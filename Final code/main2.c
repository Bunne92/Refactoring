
/*Detta program är en räknare som kan användas för ellära med enbart växelspänningar och växelströmmar. Räknaren
tar upp räkning med spänningar i volt(U), resistanser upp till 20 000/ohm(R).
Ström upp till 440 Ampere(I), effekter P i watt(W). 3 faser upp till 400V mellan faserna.
Även tar denna upp Skenbar effekt vid 3-fas och enfas, aktiv effekt vid 3-fas och enfas där cosinus fi/cosinus() används
som effektfaktorn som är mindre än 1 och inte mindre än 0.
Frekvenser i (Hz):  och totala motståndet i parallellkopplade kretsar med max 3 motstånd.

50 Hertz(Hz) Finns det i våra uttag i sverige Vid 50 Hz byter ­spänningen polaritet och strömmen riktning 100 gånger per
sekund. Spänningen i svenska eluttag pendlar upp och ner från -325 V till +325 V. Att vi talar om 230 V beror på att det
är spänningens(växelström ~) effektivvärde eller roten ur. Spänningen V(U)=Toppvärdet/sqrt(2)=325V/sqrt(2).

OHMS LAG: Spänning i volt(U)=Resistans i ohm(R)*Ström i ampere(I)
RESISTANSTOTAL PARALLELLA RESISTANSER: Rtot=1/R1R2R3
EFFEKTLAGEN ENKEL för likström: Effekt i watt(P)=U*I
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
    double rtot= (1/r1) + (1/r2) + (1/r3);
    return 1/rtot;
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
  if(input_value > max_value)
  {
      printf("För högt värde, försök igen: \n");
  }
    return input_value;
}


int main()
{
    system("chcp 1252");
    system("cls");
    bool exit = false;
    double value_1, value_2, value_3;

    while (exit == false)
    {
        printf("\n");
        int val;

        printf("Välj vilka storheter du vill beräkna:\n"
               "Välj 1 för: OHMS LAG\n"
               "Välj 2 för: Rtot\n"
               "Välj 3 för: EFFEKTLAGEN ENKEL\n"
               "Välj 4 för: SKENBAR EFFEKT ENFAS\n"
               "Välj 5 för: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n"
               "Välj 6 för: SKENBAR EFFEKT 3-FAS\n"
               "Välj 7 för: AKTIV EFFEKT 3-FAS\n"
               "Välj 0 för: FÖR ATT AVSLUTA\n");

        scanf("%d", &val);

        if(val == 1)
        {
            printf("Ohms lag spänningen(volt/V) betäckning U lika med Resistansen(Ohm) betäckning R \n"
                   "gånger Strömmen(Ampere) med betäckningen I. Kort U=R*I. \n\n"
                   "Skriv resistans R < 20 000ohm: \n ");
            value_1 = input_check(MAX_RES);
            if(value_1>MAX_RES) continue;

            printf("Skriv ström I < 440 Ampere: \n");
            value_2 = input_check(MAX_AMP);
            if(value_2>MAX_AMP) continue;
            printf("%f V\n", ohms_lag(value_1, value_2));
        }

        else if(val == 2)
        {
            printf("Resistans sammankopplade i parallella kretsar är lika med 1 delat Resistans R total är lika med\n"
                   "Resistans 1/R1 + 1/R2 + 1/R3 då vi högst använder tre resistanser.\n\n"
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

        else if(val == 3)
        {
            printf("Effektlagen enkel för likström är effekten P i Watt (W) lika med spänningen U i volt(V)\n"
                   "gånger strömmen I i Ampere(A): \n\n"
                   "Skriv spännngen U i volt(V): \n ");
            scanf("%lf", &value_1);
            printf("Skriv ström Ampere I < 440A: \n");
            value_2 = input_check(MAX_AMP);
            if(value_2>MAX_AMP) continue;
            printf("%f W\n", eff_enk(value_1, value_2));
        }
        else if(val == 4)
        {
            printf("Skenbar effekt enfas räknas med storheten VA(VoltAmpere) som är lika med spänningen U i volt(V)\n"
                   "gånger strömmen I i ampere(A)\n\n"
                   "Skriv Spänningen U i volt: \n ");
            scanf("%lf", &value_1);
            printf("Skriv ström I < 440A: \n");
            value_2 = input_check(MAX_AMP);
            if(value_2>MAX_AMP) continue;
            printf("%f VA\n", sken_eff(value_1, value_2));
        }

        else if(val == 5)
        {
            printf("Aktiv medelefdekt enfas är lika med effekt P i watt(W) lika med spänningen U i volt(V) gånger strömmen I \n"
                   "i Ampere gånger cosinus fi/efkektfaktor < 1:\n\n"
                   "Skriv spänning U i volt: \n ");
            scanf("%lf", &value_1);
            printf("Skriv ström I: \n");
            value_2 = input_check(MAX_AMP);
            if(value_2>MAX_AMP) continue;
            printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
            scanf("%lf", &value_3);
            if (value_3 < 0 && value_3 > 1)
            {
                printf("Fel värde, försök igen\n");
                continue;
            }
            printf("%f W\n", aktiv_eff(value_1, value_2, value_3));
        }
        else if(val == 6)
        {
            printf("3-fas skenbar effekt är växelspänning är skenbar effekt S i voltampere(VA) lika med spänningen U i volt(V) \n"
                   "gånger strömmen I i ampere(A) gånger roten ur 3 SQRT(3).\n\n"
                   "Skriv spänning U i volt(V) < 400V: \n ");
            value_1 = input_check(MAX_VOLT);
            if(value_1>MAX_VOLT) continue;
            printf("Skriv ström I i ampere < 440: \n");
            value_2 = input_check(MAX_AMP);
            if(value_2>MAX_AMP) continue;
            printf("%f VA\n", sken_3fas(value_1, value_2));
        }
        else if(val == 7)
        {

            printf("3-fas aktiv effekt är effekten P i Watt(W) lika med spänningen U i volt(V) gånger strömmen I i ampere(A)\n"
                   "gånger cos < 1 && cos > 0 gånger roten ur 3 SQRT(3).\n\n"
                   "Skriv Spänningen U i volt(V): \n ");
            value_1 = input_check(MAX_VOLT);
            if(value_1>MAX_VOLT) continue;
            printf("Skriv ström I i ampere(A): \n");
            value_2 = input_check(MAX_AMP);
            if(value_2>MAX_AMP) continue;
            printf("Skriv in effektfaktorn cos > 0 && cos < 1: \n");
            scanf("%lf", &value_3);
            if (value_3 < 0 && value_3 > 1)
            {
                printf("För högt värde, försök igen: \n");
                continue;
            }

            printf("%f W\n", aktiv_3fas(value_1 ,value_2, value_3));
        }
        else if (val == 0)
        {
            exit = true;
        }
        else
        {
            printf("Fel alternativ försök igen!: \n");
        }
    }
    return 0;
}
