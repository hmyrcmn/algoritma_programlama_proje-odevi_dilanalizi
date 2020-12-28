#include <stdio.h>
#include <stdlib.h>

float calculated_frequencies; // global degisken frekans degerleri dizisi olarak kullandım

void filter_metin(char metin1[],char izinliler[])
{
    int j;
    for (int i=0;metin1[i]!='\0';i++)
    {
        for (j=0;j<53;j++)
        {
            if(metin1[i]==izinliler[j])
                break;
        }
        if(j==53)
            metin1[i]=32;
    }


puts(metin1); // yabanci karakterlerden arinan girilen metin düzenlenmis olarak ekrana yazdirılıyor
}
void detect_lang(float x,float y) // dil analizinin tamamlanma kismi elde ettigimiz sonuçlara göre metnin hangi dile daha yakin oldugunu yazdiran fonk
{
     printf("dil analizi sonlanmak uzere lutfen bekleyiniz !\n\n\n");
     printf("SONUC :");
    if (x>y) // x degeri toplam degiskenini temsil ediyor ingilizce dilinin frekans degerlerinden ne kadar farkli oldugunu belirtiyor.
        printf("\nbenzerlin en fazla oldugu dil ingilizce dilidir! \n");
    else if (x<y)
    printf("\nbenzerliin en fazla oldugu dil almanca dilidir! \n");
    else
        printf("\n tam karar olusturulamadı lutfen daha fazla metin giriniz!!\n");

}


void calculate_frequencies_bi(char metin1[])
{
    float frekans_degerleri[21];
    frekans_degerleri[21]='\0';
    char name[10][3]= {
            "th",
            "he",
            "in",
            "er",
            "an",
            "en",
            "ch",
            "de",
            "ei",
            "te"
    };
    int sayac = 0;
    int dizi[11];
    dizi[11]='\0';
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 50; ++j) {
            if ((name[i][0] == metin1[j]) && (name[i][1] == metin1[j+1])){
                sayac++;
            }
        }
        dizi[i] = sayac;
        sayac = 0;

    }
    for (int i = 0; i < 10; ++i)
    {
        printf("\n%s kelimesi %d defa geciyor\n",name[i],dizi[i]);


    }
    for (int i=0;i<10;i++)
       {
           printf("%d --> ",dizi[i]);
           frekans_degerleri[i]=dizi[i];
           printf("%.2f \n",frekans_degerleri[i]); // metinde kaç kez geçtiklerinin float olarak döndürülmesi için yazıldı

       }

   calculate_frequencies_tri(metin1,frekans_degerleri); // trigramlari hesaplayan fonku çagrýyorum

}
void calculate_frequencies_tri(char metin1[],float frekans_degerleri[])

{
    char name2[10][4]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};
    int sayac2=0;
    int dizi2[11];
    dizi2[11]='\0';

    for (int i=0;i<10;i++)
    {
        for (int j = 0; j < 50; ++j) {
            if ((name2[i][0] == metin1[j] )&& (name2[i][1] == metin1[j+1])&&(name2[i][2]==metin1[j+2]))
            {
                sayac2++;
            }
        }
        dizi2[i] = sayac2;
        sayac2 = 0;

    }
    for (int i = 0; i < 10; ++i) {
        printf("\n%s kelimesi %d defa geciyor\n",name2[i],dizi2[i]);


    }
    for (int i=0;i<10;i++)
      {
          //tekrar eden frekans degerlerinin float olarak ifadeleri yapılacaktır
          printf("%d -->",dizi2[i]);
          frekans_degerleri[11+i]=dizi2[i];
          printf("%.2f \n",frekans_degerleri[11+i]);


      }

      calculate_distances(frekans_degerleri); // frekans degerleri adli dizi burada tamamlandigi için hesaplama fonk burada çagirdim
}


void calculate_distances(float frekans_degerleri[])
{
    float aralik[21];
    aralik[21]='\0';

    printf("ingilizce dili hesaplamalari:\n");
    const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };
    for (int i=0;i<20;i++)
    {


            aralik[i]=(frekans_degerleri[i]*frequency_eng[i]);
            printf("%.2f \n",aralik[i]);  //ing dilini ile arasindaki farki yazdiran kod:


    }
    printf("girilen metnin ingilizce dili fark frekans degerleri toplaniyor \n lutfen bekleyınız\n");
    float toplam=0;
    for(int i=0;i<20;i++)              // buradaki döngü ile girilen metinin almanca dilinin frekan
                                    //degerlerinden ne kadar farklý oldugununa dair bir toplama iþlemi gerçekleþiyor.
    {

        toplam+=aralik[i];              // aralik dizisindeki elemanlar tek tek toplam degiskenine atiliyor .

    }
    printf("ingilizce dilinine ait toplam fark  frekans degerleri:\n ");
    printf("%f\n",toplam);

    printf("almaca dili hespalamalarina geciliyor \n");
    float aralik2[21];
    aralik2[21]='\0';
    const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };
    for (int i=0;i<20;i++)
    {


            aralik2[i]=(frekans_degerleri[i]*frequency_germ[i]); // almanca dilinin frekans degerlerile o frekansın kac kez gectıgıini belirten ifadenin çarpımı oldugunu yazdiran kod:

            printf("%.2f \n",aralik2[i]);



    }
    printf("girilen metnin almanca dili farki frekans degerleri toplaniyor \n lutfen bekleyiniz\n");
    float toplam2=0;                // buradaki döngü ile girilen metinin almanca dilinin frekan
                                    //degerlerinden ne kadar farkli oldugununa dair bir toplama iþlemi gerçekleþiyor.
    for(int i=0;i<20;i++)
    {
        toplam2+=aralik2[i];

    }
    printf("almanca dilinin toplam fark  frekans degeri \n ");
     printf("%f\n",toplam2);


     detect_lang(toplam,toplam2); // bu kod projenin son fonk cagiriyor elde ettigim 2 degisken degerlerine göre dil sonucu belirtilecek
    // toplam degişkeni ing frekan degerleri ile birlikte metindeki sayılarını çarpıp elde edilen deger
    // toplam2 degiskeni ise almanca frekans degerleri ile birlikte metinde kaç kez geçtiğini ifade eden sayı
}


int main()
{
    printf("Hello world!\n");
    char metin1[51];
    printf("metin 1 i gir:\n ");
    gets(metin1);

    char izinliler[53];

    for (int i=0;i<26;i++)
    {
        izinliler[i]=65+i;
    }
    for(int i =0;i<26;i++)
    {
        izinliler[26+i]=97+i;
    }
    filter_metin(metin1,izinliler);//metin1 i düzenleyen fonk u çagiriyorr:

    calculate_frequencies_bi(metin1);


    // calculate_frequencies_tri(metin1,frekans_degerleri); bu fonk burada tanimladigimmda fonk a gönderdigim 2. parametre tanimsiz oluyor

    //calculated_frequencies=frekans_degerleri;bu bir kod degil taslak kodda belirtilen degiþkenin yerine kendi projemin tanimladigim degiskeni okunurlugu arttirmak için belitmek istedim


    // detect_lang(toplam,toplam2);



    return 0;
}
