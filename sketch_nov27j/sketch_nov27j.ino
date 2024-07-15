#include <IRremote.h>
#include <IRremoteInt.h>
#define error 0xFFFFFFFF // define nos sirve para avisarle al compilador que cada vez que nuestro arduino obtenga o lea por parametros //
// la funcion  FFFFFFFF lo transforme a una especie de variable error //
#define boton1 0xFF30CF
#define boton2 0xFF18E7
#define boton3 0xFF7A85
#define boton4 0xFF10EF
#define boton5 0xFF38C7   // Representacion a traves de los codigos el numero de cada uno de los botones
#define boton6 0xFF5AA5
#define boton7 0xFF42BD
#define boton8 0xFF4AB5
#define boton9 0xFF52AD
#define boton0 0xFF6897

int control=12; // aca en este pin conectamos el sensor infrarojo //
int ledv=3;
int leda=4;
int ledr=5;

IRrecv receptor(control); // inicializamos, le decimos al arduino que vamos a usar un modulo receptor de infrarojo //
decode_results codigoLeido; // guardar el ultimo codigo que se ingreso //
decode_results codigoLeidoNuevo; // actual codigo ingresado // Asi podemos comparar entre ellos //

void setup() {
  // put your setup code here, to run once:
    Serial.begin (9600);
    receptor.enableIRIn(); // Habilitamos el receptor para que empiece a leer//

    pinMode (ledv , OUTPUT); // Ahora declaramos las salidas //
    pinMode (leda , OUTPUT);
    pinMode (ledr , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Leer lo que nos manda el control mediante el sensor y luego a la lectura la guardamos en una variable y con eso ir activando o //
  // desactiivando lo que queramos //

    if (receptor.decode(&codigoLeidoNuevo)){ //Funcion en donde aca le decimos en donde guardar el dato que esta leyendo nuestro sensor infra //
    //Con esta funcion guardamos la lectura en la v. codigoLeidoNuevo //

        receptor.resume(); // esta funcion le dice al arduino que se prepare para el siguiente codigo que apretemos que vaya a leer //
    }

    if (codigoLeidoNuevo.value != codigoLeido.value && codigoLeidoNuevo.value != error){
          Serial.println (codigoLeidoNuevo.value, HEX); // aca se mostraran los codigos o valores que valen cada uno de los botones del control //
          // se pone value pq nos interesa el valor, y luego HEX transformara ese valor en valor hexagesimal que es lo que lee el control //
          // Basicamente con esto, estamos logrando que a traves del serial nos muestre cada vez que se presiona una tecla/boton distinta //
         codigoLeido=codigoLeidoNuevo;
         switch (codigoLeido.value){ // esta funcion nos sirve para comparar el valor que tenga un boton con
         // todos los valores que tengamos de los otros botones
            case boton1; // case es como "caso comparativo" que se puede o no cumplir de acuerdo a las condiciones
                digitalWrite (ledv , HIGH);
            break;  // termina la funcion switch // termina funcion comparativa //
            case boton2;
                digitalWrite(leda, HIGH);
            break;
            case boton3;
                digitalWrite(ledr, HIGH);
            break;
            case boton4;
                digitalWrite(ledv, LOW;
            break;
            case boton5;
                digitalWrite(leda, LOW);
            break;
            case boton6;
                digitalWrite(ledr, LOW);
            break;
            case boton7;
                for(int i=0;i<4;i++){
                    digitalWrite(ledv, HIGH);
                    delay(50);
                    digitalWrite(leda, HIGH);
                    delay(50);
                    digitalWrite(ledr, HIGH);
                    delay(50);
                    digitalWrite(ledv, LOW);
                    digitalWrite(leda, LOW);
                    digitalWrite(ledr, LOW);
                    delay(50);
                }
              break;
              case boton8;
                  for(int i=0;i<4;i++){
                    digitalWrite(ledr, HIGH);
                    delay(50);
                    digitalWrite(leda, HIGH);
                    delay(50);
                    digitalWrite(ledv, HIGH);
                    delay(50);
                    digitalWrite(ledv, LOW);
                    digitalWrite(leda, LOW);
                    digitalWrite(ledr, LOW);
                    delay(50);
                  }
              break;
              case boton9;
                  for(int i=0;i<4;i++){
                    digitalWrite(ledv, HIGH);
                    delay(50);
                    digitalWrite(leda, HIGH);
                    delay(50);
                    digitalWrite(ledr, HIGH);
                    delay(50);
                    digitalWrite(ledv, LOW);
                    digitalWrite(leda, LOW);
                    digitalWrite(ledr, LOW);
                    delay(100);
                    digitalWrite(ledr, HIGH);
                    delay(50);
                    digitalWrite(leda, HIGH);
                    delay(50);
                    digitalWrite(ledv, HIGH);
                    delay(50);
                    digitalWrite(ledv, LOW);
                    digitalWrite(leda, LOW);
                    digitalWrite(ledr, LOW);
                    delay(50);
                  }
              break;
              case boton0;
                  for(int i=0;i<4;i++){
                    digitalWrite(ledv, HIGH);                   
                    digitalWrite(leda, HIGH);                   
                    digitalWrite(ledr, HIGH);
                    delay(50);
                    digitalWrite(ledv, LOW);
                    digitalWrite(leda, LOW);
                    digitalWrite(ledr, LOW);
                    delay(50);       
                  }    
          }
        }

}
