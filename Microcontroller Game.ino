int basla=0;
int sayi1,sayi2,sayi3,sayi4;
int fark=0;
void setup() {
  Serial.begin(9600); //SERİ HABERLEŞME 
  randomSeed(analogRead(A0)); //RASTGELE  SAYI ÜRETME  
  pinMode(2,INPUT);//BUTON
  
  pinMode(3,OUTPUT);//LED
  pinMode(4,OUTPUT);//LED
  pinMode(5,OUTPUT);//LED
  pinMode(6,OUTPUT);//LED

  pinMode(7,INPUT);//DIP SWİTCH
  pinMode(8,INPUT);//DIP SWİTCH
  pinMode(9,INPUT);//DIP SWİTCH
  pinMode(10,INPUT);//DIP SWİTCH
  
  pinMode(11,OUTPUT); //YEŞİL LED
  pinMode(12,OUTPUT); // KIRMIZI LED
}
void loop() {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  
  basla=digitalRead(2);
  if(basla)   //BUTUNA BASILINCA BAŞLA
    {
      sayi1=random(1,16); //Rastgele sayı üret
      sayi2=random(1,16); //Rastgele sayı üret
      sayi3=random(1,16); //Rastgele sayı üret
      sayi4=random(1,16); //Rastgele sayı üret
      
      int sayilarSirala[4];
      sayilarSirala[0]=sayi1;
      sayilarSirala[1]=sayi2;
      sayilarSirala[2]=sayi3;
      sayilarSirala[3]=sayi4;  
      //EN BÜYÜK İLE EN KÜÇÜK BULMA
      int enBuyuk=sayilarSirala[0];
      int enKucuk=sayilarSirala[0];
      for(int sayac1=0;sayac1<=3;sayac1++){
        if(sayilarSirala[sayac1]>=enBuyuk){
          enBuyuk=sayilarSirala[sayac1];
        }
        if(sayilarSirala[sayac1]<=enKucuk){
          enKucuk=sayilarSirala[sayac1];
        }
      }    
      fark=enBuyuk-enKucuk; //EN BÜYÜK SAYI İLE EN KÜÇÜK SAYI ARASINDAKİ FARK
      Serial.print("Fark:");Serial.println(fark);
      Serial.print(sayi1); Serial.print(" "); cevir(sayi1); Serial.println();
      Serial.print(sayi2); Serial.print(" "); cevir(sayi2); Serial.println();
      Serial.print(sayi3); Serial.print(" "); cevir(sayi3); Serial.println();
      Serial.print(sayi4); Serial.print(" "); cevir(sayi4); Serial.println();
      Serial.println("-------------");
      sorgu(fark);
    }
}
//SWİTCH GİRİLEN DEĞERLER İLE LEDDEKİ GİRİLEN DEĞERLERİN FARKI SORGU EDİLİYOR.
void sorgu(int fark2)
  {
  delay(1000);//DIP SWİTCDE GİRİLEN TOPLAM DEĞER İÇİN BEKLEME SÜRESİ
  int k[4],i;
  i=0;
  int dipSayi;
  //DİP SWİTCH DEĞER GİRME
   dipSayi=(digitalRead(7)*8)+(digitalRead(8)*4)+(digitalRead(9)*2)+(digitalRead(10)*1);
    k[4]=0;  k[3]=0;  k[2]=0;  k[1]=0;
    while(fark2>=1)
    {
      i++;
      k[i]=fark2%2;
      fark2=fark2/2;
    }
   delay(1000); //DEĞER GİRMEK İÇİN BEKLENEN SÜRE
   Serial.print("Dip Switch:"); Serial.print(dipSayi); //DİP SWİTCH'DEN GİRİLEN DEĞER
  
  //DİP SWİTCH İLE SAYININ EN BÜYÜK İLE EN KÜÇÜK SAYI ARASINDAKİ FARKIN DEĞERİNE GÖRE LED YANAR.
  if(dipSayi==fark) 
  {   
    digitalWrite(11,HIGH); delay(1000); Serial.println("-Dogru"); //Doğru değer ise Yeşil LED yanacak
  }
  else {
    digitalWrite(12,HIGH); delay(1000); Serial.println("-Yanlis");// Yanlış değerse Kırmızı LED yanacak
  }  
  }
  //TABAN ÇEVİRME 10-->2
void cevir(int sayi)   
{
  int k[10],i;
  i=0;
  k[4]=0;  k[3]=0;  k[2]=0;  k[1]=0;
    while(sayi>=1)
    {
      i++;
      k[i]=sayi%2;
      sayi=sayi/2;
    }

    Serial.print(k[4]); 
    Serial.print(k[3]);
    Serial.print(k[2]);
    Serial.print(k[1]);
    //LEDLERİ DEĞERLERİNE GÖRE YANMASI SAĞLANIR.
    if(k[4]==1){digitalWrite(3,HIGH);} 
    if(k[3]==1){digitalWrite(4,HIGH);}
    if(k[2]==1){digitalWrite(5,HIGH);}
    if(k[1]==1){digitalWrite(6,HIGH);}
    delay(5000);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    delay(1000);
}
