
/*Detta program �r en r�knare som kan anv�ndas f�r ell�ra med enbart v�xelsp�nningar och v�xelstr�mmar. R�knaren
tar upp r�kning med sp�nningar i volt(U), resistanser upp till 20 000/ohm(R).
Str�m upp till 440 Ampere(I), effekter P i watt(W). 3 faser upp till 400V mellan faserna.
�ven tar denna upp Skenbar effekt vid 3-fas och enfas, aktiv effekt vid 3-fas och enfas d�r cosinus fi/cosinus() anv�nds
som effektfaktorn som �r mindre �n 1 och inte mindre �n 0.
Frekvenser i (Hz):  och totala motst�ndet i parallellkopplade kretsar med max 3 motst�nd.

50 Hertz(Hz) Finns det i v�ra uttag i sverige Vid 50 Hz byter �sp�nningen polaritet och str�mmen riktning 100 g�nger per
sekund. Sp�nningen i svenska eluttag pendlar upp och ner fr�n -325 V till +325 V. Att vi talar om 230 V beror p� att det
�r sp�nningens(v�xelstr�m ~) effektivv�rde eller roten ur. Sp�nningen V(U)=Toppv�rdet/sqrt(2)=325V/sqrt(2).

OHMS LAG: Sp�nning i volt(U)=Resistans i ohm(R)*Str�m i ampere(I)
RESISTANSTOTAL PARALLELLA RESISTANSER: Rtot=1/R1R2R3
EFFEKTLAGEN ENKEL f�r likstr�m: Effekt i watt(P)=U*I
SKENBAR EFFEKT ENFAS ~: Skenbar(S/VA)=U*I
AKTIV EFFEKT/MEDELEFFEKT ENFAS ~:P=U*I*cos()
SKENBAR EFFEKT 3-FAS ~: Skenbar S/VA=U*I*sqrt(3)
AKTIV EFFEKT 3-FAS ~: P=U*I*sqrt(3)*cos()

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_RES   20000
#define MAX_AMP     440
#define MAX_VOLT    400


double ohms_lag(double r, double i){
    return i * r;
}

double res_tot(double r1, double r2, double r3){
    return 1/((1/r1) + (1/r2) + (1/r3));
}

double eff_enk(double u, double i){
    return u * i;
}
double sken_eff(double u, double i){
    return u*i;
}

double aktiv_eff(double u, double i, double cos){
    return u*i*cos;
}

double sken_3fas(double u, double i){
    return u*i*sqrt(3);
}
double aktiv_3fas(double u, double i, double cos){
    return u * i * sqrt(3) * cos;
}

double input_check(int max_value){
  double input_value;
  scanf("%lf", &input_value);
  if(input_value > max_value || input_value <0 && input_value>0){
      printf("F�r h�gt v�rde, f�rs�k igen: \n");
  }
    return input_value;
}

int menu(){
  int val;
  printf("\nV�lj vilka storheter du vill ber�kna:\n"
         "V�lj 1 f�r: OHMS LAG\n"
         "V�lj 2 f�r: Rtot\n"
         "V�lj 3 f�r: EFFEKTLAGEN ENKEL\n"
         "V�lj 4 f�r: SKENBAR EFFEKT ENFAS\n"
         "V�lj 5 f�r: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n"
         "V�lj 6 f�r: SKENBAR EFFEKT 3-FAS\n"
         "V�lj 7 f�r: AKTIV EFFEKT 3-FAS\n"
         "V�lj 0 f�r: F�R ATT AVSLUTA\n");
  scanf("%d", &val);
  return val;
}

int main()
{
    system("chcp 1252");
    system("cls");
    bool exit = false;
    double value_1, value_2, value_3;
    int val;

    while (exit == false){
        val = menu();
        if(val == 1){
            printf("Ohms lag sp�nningen(volt/V) bet�ckning U lika med Resistansen(Ohm) bet�ckning R \n"
                   "g�nger Str�mmen(Ampere) med bet�ckningen I. Kort U=R*I. \n\n"
                   "Skriv resistans R < 20 000ohm: \n ");
            value_1 = input_check(MAX_RES);
            if(value_1>MAX_RES) continue;

            printf("Skriv str�m I < 440 Ampere: \n");
            value_2 = input_check(MAX_AMP);
            if(value_2>MAX_AMP) continue;
            printf("%f V\n", ohms_lag(value_1, value_2));
        }

        else if(val == 2){
            printf("Resistans sammankopplade i parallella kretsar �r lika med 1 delat Resistans R total �r lika med\n"
                   "Resistans 1/R1 + 1/R2 + 1/R3 d� vi h�gst anv�nder tre resistanser.\n\n"
                   "Skriv resistans R1 < 20 000ohm: \n ");
            value_1 = input_check(MAX_RES);
            if(value_1>MAX_RES) continue;
            printf("Skriv resistans R2 < 20 000ohm: \n ");
            value_2 = input_check(MAX_RES);
            if(value_2>MAX_RES) continue;
            printf("Skriv resistans R3 < 20 000ohm: \n ");
            value_3 = input_check(MAX_RES);
            if(value_3>MAX_RES) continue;

            printf("%f Ohm\n", res_tot(value_1, value_2, value_3));
        }

        else if(val == 3){
            printf("Effektlagen enkel f�r likstr�m �r effekten P i Watt (W) lika med sp�nningen U i volt(V)\n"
                   "g�nger str�mmen I i Ampere(A): \n\n"
                   "Skriv sp�nnngen U i volt(V): \n ");
            value_1 = input_check(MAX_VOLT);
            if(value_1>MAX_VOLT) continue;
            printf("Skriv str�m Ampere I < 440A: \n");
            value_2 = input_check(MAX_AMP);
            if(value_2>MAX_AMP) continue;
            printf("%f W\n", eff_enk(value_1, value_2));
        }
        else if(val == 4){
            printf("Skenbar effekt enfas r�knas med storheten VA(VoltAmpere) som �r lika med sp�nningen U i volt(V)\n"
                   "g�nger str�mmen I i ampere(A)\n\n"
                   "Skriv Sp�nningen U i volt: \n ");
            value_1 = input_check(MAX_VOLT);
            if(value_1>MAX_VOLT) continue;
            printf("Skriv str�m I < 440A: \n");
            value_2 = input_check(MAX_AMP);
            if(value_2>MAX_AMP) continue;
            printf("%f VA\n", sken_eff(value_1, value_2));
        }

        else if(val == 5){
            printf("Aktiv medelefdekt enfas �r lika med effekt P i watt(W) lika med sp�nningen U i volt(V) g�nger str�mmen I \n"
                   "i Ampere g�nger cosinus fi/efkektfaktor < 1:\n\n"
                   "Skriv sp�nning U i volt: \n ");
            scanf("%lf", &value_1);
            printf("Skriv str�m I: \n");
            value_2 = input_check(MAX_AMP);
            if(value_2>MAX_AMP) continue;
            printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
            scanf("%lf", &value_3);
            if (value_3 < 0 && value_3 > 1){
                printf("Fel v�rde, f�rs�k igen\n");
                continue;
            }
            printf("%f W\n", aktiv_eff(value_1, value_2, value_3));
        }
        else if(val == 6){
            printf("3-fas skenbar effekt �r v�xelsp�nning �r skenbar effekt S i voltampere(VA) lika med sp�nningen U i volt(V) \n"
                   "g�nger str�mmen I i ampere(A) g�nger roten ur 3 SQRT(3).\n\n"
                   "Skriv sp�nning U i volt(V) < 400V: \n ");
            value_1 = input_check(MAX_VOLT);
            if(value_1>MAX_VOLT) continue;
            printf("Skriv str�m I i ampere < 440: \n");
            value_2 = input_check(MAX_AMP);
            if(value_2>MAX_AMP) continue;
            printf("%f VA\n", sken_3fas(value_1, value_2));
        }
        else if(val == 7){
            printf("3-fas aktiv effekt �r effekten P i Watt(W) lika med sp�nningen U i volt(V) g�nger str�mmen I i ampere(A)\n"
                   "g�nger cos < 1 && cos > 0 g�nger roten ur 3 SQRT(3).\n\n"
                   "Skriv Sp�nningen U i volt(V): \n ");
            value_1 = input_check(MAX_VOLT);
            if(value_1>MAX_VOLT) continue;
            printf("Skriv str�m I i ampere(A): \n");
            value_2 = input_check(MAX_AMP);
            if(value_2>MAX_AMP) continue;
            printf("Skriv in effektfaktorn cos > 0 && cos < 1: \n");
            scanf("%lf", &value_3);
            if (value_3 < 0 && value_3 > 1){
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }
            printf("%f W\n", aktiv_3fas(value_1 ,value_2, value_3));
        }
        else if (val == 0){
            exit = true;
        }
        else{
            printf("Fel alternativ f�rs�k igen!: \n");
        }
    }
    return 0;
}
