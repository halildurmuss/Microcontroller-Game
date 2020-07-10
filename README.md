# MicrocontrollerGame
## Bu projede Atmega328p mikrodenetleyici ile aşağıda detayları verilen oyun gerçekleştirilmiştir.

Fritzing programı yardımıyla devre tasarımı gerçekleştirildi.

![Circuit Diagram - Kopya](https://user-images.githubusercontent.com/66306220/87210177-53770b80-c31d-11ea-9cbe-235e44671f31.png)


Ardunio programını (sketch) yazılmıştır.

## Oyunun Detayları

1. Oyun 2 numaralı dijital pine geçici anahtara (pushbutton) basılması durumunda başlar.
2. Oyun başlayınca mikrodenetleyici tarafından 4 adet rastgele tam sayı (1 dahil, 15 dahil aralığında ) üretilecektir.

   Ardunio programlarında rastgele sayı üretimi için kullanılabilecek 2 fonksiyon vardır. Bunlardan birincisinin adı **randomSeed**, ikincisinin adı ise **random** dır. **randomSeed** fonksiyonu kendisine parametre olarak aldığı çekirdek değer sayesinde **random** fonksiyonunun her çağrılışında farklı bir rastgele sayı üretiminimümkün kılmaktadır.
   
   Genellikle **randomSeed** setup, **random** ise loop içerisinde yer alır.
   
   **randomSeed(analogRead(A0));** deyimi **randomSeed** fonksiyonunun tipik bir kullanım şeklidir.
   
   **random(x,y)** ise x(dahil) ile y(hariç) aralığında rastgele bir tam sayı üretimi için kullanılır.

3. Mikrodenetleyici daha sonra üretilen bir tam sayıların her birinin 4 bitlik ikili karşılığını bulacak ve bu sayılar 3-6 aralığındaki dijital pinlere bağlı led’lerle temsil edilecektir.(Bu sayıların MSB bitleri 3 numaralı pin ve LSB bitleri de 6 numaralı pin ile kontrol ediliyor.) Örneğin rastgele tam sayılardan biri 10 (On)(1010) iken 3 ve 5 numaralı dijital pinlere bağlı led’ler yanıyorken 4 ve 6 numaralı dijital pinlere bağlı led’ler sönüyor olacaktır. Her bir tam sayıyı temsil eden led kombinasyonu 5 saniye süresince aktif olmalıdır. Sonrasında tüm led’ler 1 saniye süresince söndürülüyor ve aynı işlem 4 sayının her biri için tekrar ediliyor.

4. Kullanıcı da bu esnada led’lerle temsil edilen sayıların önce tam sayı karşılıklarını tespit etmeye çalışmalı ve sonrasında da bu 4 sayının maksimum ile minumumunun farkını zihninden hesaplaması gerekiyor.

5. Kullanıcı daha sonra 7-10 aralığındaki dijital pinlere bağlı bir kalıcı anahatar grubunun 4 pozisyonunu kullanarak zihninden hesapladığı farkın ikili karşılığını ilgili kalıcı anahtar üzerinden mikrodenetleyiciye iletiyor. Örneğin 4 rastgele tam sayının maksimumu 14 ve minimumu da 8 iken maksimum ile minumum farkı 6 (0110)’dır. Dolayısıyla 8 ve 9 numaralı pinlere bağlı anahtar ON; 7 ve 10 numaralı pinlere bağlı anahtarlar OFF durumunda olur. (Oyun başlatılmadan önce tüm kullanıcı anahtarların OFF durumunda olduğuna dikkat edilmelidir.)

6. Kalıcı anahtarlar üzerinden veri girişine imkan tanıyabilmek için sayıların gösterimi tamamlandıktan sonra 3-6 aralığındaki ledlerin tamamı 5 saniye süresince ve 1’er saniye aralıklarla yanmalıdır ve sönmelidir. Kullanıcı da bu esnada veri girişini yapmalıdır. Mikrodenetleyici bu süre sonrasında kendi hesapladığı maksimum ile minumum arasındaki farkın kullanıcının girdiği değere eşit olup olmadığını kontrol eder.

7. Kullanıcının girdiği fark doğru ise 11 numaralı dijital pine bağlı led, doğru değilse 12 numaralı dijital pine bağlı kırmızı led bir saniye süresince yanmalıdır ve sonrasında sönmelidir.

8. Kullanıcı 2 numaralı dijital pine bağlı geçici anahtara bastığında oyun yeni rastgele tam sayılarla tekrar başlıyor. Oyun başlamadan önce tüm led’ler sönük olmalılar.

9. Programda 2 alt (yardımcı) fonksiyon kullanılmıştır. Setup öncesi prototipler ve loop sonrası da tanımlar yer alıyor.
