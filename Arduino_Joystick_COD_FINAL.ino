#include <Joystick.h>
#include <USBAPI.h>

#include <HID.h>

// Declarare variabile: (Fiecare buton este asignat pin-ului digital corespunzator)

int b1 = 1;
int b2 = 2;
int b3 = 3;
int b4 = 4;

// Variabila ce initializeaza butoanele cu valoarea "0", pentru a le comuta la apasare pe "1"
int stare_initiala_buton = 0;

// Declarare variabile pentru LED-uri: (Fiecare LED este asignat pin-ului digital corespunzator);   LED-urile vor fi LOW in stare initiala("0") si HIGH atunci cand sunt apasate("1")
const int l1Pin = 6;
const int l2Pin = 7;
const int l3Pin = 8;
const int l4Pin = 9;

// Declarare variabile pentru cele 2 axe ale Gamepad-ului: (Axele necesita o valoare byte intre (-127,127))
// Se initializeaza variabilele cu 0 ( La inceperea executiei codului, pozitia va fi (x,y)=(0,0)
unsigned int axaX = 0;
unsigned int axaY = 0;

// Variabila pentru Update-ul in timp real al starii Axelor
const bool initAutoSendState = true;


void setup()
{
  Joystick.begin();       //Initializare biblioteca Joystick.h folosita
  pinMode(b1, INPUT); //Declarare pini digitali
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
  pinMode(l1Pin, OUTPUT);
  pinMode(l2Pin, OUTPUT);
  pinMode(l3Pin, OUTPUT);
  pinMode(l4Pin, OUTPUT);

  //Pinii analogici pentru citirea Axelor X si Y ai Gamepad-ului nu se declara intrucat ei sunt implicit pini de input pentru Arduino Leonardo.

}

void loop()
{
  // stare_initiala_buton este initializat cu 0 si reprezinta un flag pentru aprinderea butonului
  // setButton() seteaza starea (0/1) curenta a butonului specificat
  // Citirea pinilor digitali (butoanelor):

  stare_initiala_buton = digitalRead(b1);   // Se citeste valoarea "1" sau "0" de la butonul 1
  Joystick.setButton(1, !stare_initiala_buton);
  if ( stare_initiala_buton == HIGH) {            // Daca butonul 1 este apasat, se aprinde LED-ul 1(rosu)
    digitalWrite(l1Pin, HIGH);

  } else {
    digitalWrite(l1Pin, LOW);
  }


  stare_initiala_buton = digitalRead(b2);   // Se citeste valoarea "1" sau "0" de la butonul 2
  Joystick.setButton(2, !stare_initiala_buton);   // Sets the state (0 or 1) of the specified button (0 - 31)
  if ( stare_initiala_buton == HIGH) {            // Daca butonul 2 este apasat, se aprinde LED-ul 2(galben)
    digitalWrite(l2Pin, HIGH);

  } else {
    digitalWrite(l2Pin, LOW);
  }


  stare_initiala_buton = digitalRead(b3);   // Se citeste valoarea "1" sau "0" de la butonul 3
  Joystick.setButton(3, !stare_initiala_buton);
  if ( stare_initiala_buton == HIGH) {            //  Daca butonul 3 este apasat, se aprinde LED-ul 3(rosu)
    digitalWrite(l3Pin, HIGH);

  } else {
    digitalWrite(l3Pin, LOW);
  }


  stare_initiala_buton = digitalRead(b4);   // Se citeste valoarea "1" sau "0" de la butonul 4
  Joystick.setButton(4, !stare_initiala_buton);
  if ( stare_initiala_buton == HIGH) {            // Daca butonul 4 este apasat, se aprinde LED-ul 4(galben)
    digitalWrite(l4Pin, HIGH);

  } else {
    digitalWrite(l4Pin, LOW);
  }

  // Citirea pinilor analogici, cei ai axelor X,Y si asigneaza acestora valorile citite in corespondenta cu biblioteca Joystick

  // Se citeste input-ului analogic conectat la pinul "A0", pentru axa X
  axaX = analogRead(A0) / 4;

  // OBS!!! Se imparte la 4 pentru a se putea mapa valorile citite, intrucat Arduino citeste pozitiile Gamepad-ului in range-ul 0:1023 bits, iar PC-ul are range de procesare intre 0:255 bytes (1024/4 = 256 bits)

  axaX = map(axaX, 0, 255, 127, -127);

  // setXAxis() updateaza in timp real valoarea stocata in xAxis in conformitate cu biblioteca Joystick.h prin initAutoSendState=true
  Joystick.setXAxis(axaX);

  // Se citeste input-ului analogic conectat la pinul "A1", pentru axa Y
  axaY = analogRead(A1) / 4;

  // OBS!!! Se imparte la 4 pentru a se putea mapa valorile citite, intrucat Arduino citeste pozitiile Gamepad-ului in range-ul 0:1023 bits, iar PC-ul are range de procesare intre 0:255 bytes (1024/4 = 256 bits)

  axaY = map(axaY,0,255,-127,127);

  // setYAxis() updateaza in timp real valoarea stocata in xAxis in conformitate cu biblioteca Joystick.h prin initAutoSendState=true
  Joystick.setYAxis(axaY);


}
