#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct oyuncu  
{  
  char isim[25];
  char soyIsim[25];
  int hataliPas;
  int oynananMacSayisi;  
  int isabetliPas;
};

bool oyuncununKaydiVarMi(struct oyuncu gelenOyuncu, char gelenOyuncuAdi[20]) {
  if (strcmp(gelenOyuncu.isim, gelenOyuncuAdi) == 0)
  {
    return true; 
  }
  return false;
}

void oyuncuEkle(struct oyuncu oyuncular[20], struct oyuncu eklenecekOyuncu, int kacinciOyuncu) {
  /*
    DEBUG CODES
    
    printf("gelen isim => %s \n", eklenecekOyuncu.isim);
    printf("gelen soyisim => %s \n", eklenecekOyuncu.soyIsim);
    printf("gelen hatali pas => %d \n", eklenecekOyuncu.hataliPas);
    printf("gelen isabetli pas => %d \n", eklenecekOyuncu.isabetliPas);
    printf("bu oyuncu kacinci oyuncu? => %d\n", kacinciOyuncu);

    printf("yeni eklenen isim => %s \n", eklenecekOyuncu.isim);
    printf("yeni eklenen soyisim => %s \n", eklenecekOyuncu.soyIsim);
    printf("yeni eklenen hatali pas => %d \n", eklenecekOyuncu.hataliPas);
    printf("yeni eklenen isabetli pas => %d \n", eklenecekOyuncu.isabetliPas);
  */
  
  strcpy(oyuncular[kacinciOyuncu].isim, eklenecekOyuncu.isim);

  strcpy(oyuncular[kacinciOyuncu].soyIsim, eklenecekOyuncu.soyIsim);

  oyuncular[kacinciOyuncu].isabetliPas = eklenecekOyuncu.isabetliPas;

  oyuncular[kacinciOyuncu].hataliPas = eklenecekOyuncu.hataliPas;
}

int main()
{
  struct oyuncu oyuncular[20];
  struct oyuncu temp;

  char satir[100], *karakter;
  char neyeGore[] = " ", *ptr;
  FILE *paslar = fopen("paslar.txt", "r");

  bool kaydiVarMi = false;
  int kacinciOyuncu = 0;
  int ozellikSayaci = 0;
 
  do {
    karakter = fgets(satir, 100, paslar);
    ptr = strtok(satir, neyeGore);

    if (strcmp(ptr, "----") == 0) {
      printf("şu an ---- yakalandı! => %s", ptr);
      continue;
    }

    kaydiVarMi = oyuncununKaydiVarMi(oyuncular[kacinciOyuncu], ptr);

    while(ptr != NULL)
	  {
      if (!kaydiVarMi) {
        if (ozellikSayaci == 0) {
          strcpy(temp.isim , ptr);
        }else if (ozellikSayaci == 1){
          strcpy(temp.soyIsim , ptr);
        }else if (ozellikSayaci == 2){
          temp.hataliPas = atoi(ptr);
        }else{
          temp.isabetliPas = atoi(ptr);
        }
      }
		  ptr = strtok(NULL, neyeGore);
      ozellikSayaci++;
	  }

    if (!kaydiVarMi) oyuncuEkle(oyuncular, temp, kacinciOyuncu);

    ozellikSayaci = 0;
    kacinciOyuncu++;
  } while (karakter != NULL);

	return 0;
}