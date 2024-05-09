/* ARDUINO DUE CAPACITIVE PIANO WITH LED MATRIX DISPLAY
* Modified with a "newtone" library to be compatible with Arduino DUE
* By: Ashna Samson
*
* This piano works by capacitive sensing. The piano has 1 octave and uses the major C scale
*
*/
// Ashna Samson
// Student Number: 216196446
// EECS 2032 - Embedded Systems Project
// Import pitches.h
#include "pitches.h"
// Import the CapacitiveSensor Library
#include <CapacitiveSensor.h>
// Identify pin 45 as the buzzer
#define buzzer 45
#include "NewToneLib.h" // the alternative library compatible with the DUE board
MyTone t(false);
// Set the send and recieve pins
CapacitiveSensor note_c_23_27 = CapacitiveSensor(23,27); // Note C
CapacitiveSensor note_d_23_29 = CapacitiveSensor(23,29); // Note D
CapacitiveSensor note_e_23_31 = CapacitiveSensor(23,31); // Note E
CapacitiveSensor note_f_23_33 = CapacitiveSensor(23,33); // Note F
CapacitiveSensor note_g_23_35 = CapacitiveSensor(23,35); // Note G
CapacitiveSensor note_a_23_37 = CapacitiveSensor(23,37); // Note A
CapacitiveSensor note_b_23_39 = CapacitiveSensor(23,39); // Note B
CapacitiveSensor note_c_23_41 = CapacitiveSensor(23,41); // Note C
//-------------------------------------------------------------------------------------------
// FOR THE 4X4 LED MATRIX LETTER DISPLAY
// LED matrix anodes
int row[] = {24, 26, 28, 30};
// LED matrix cathodes
int col[] = {32, 34, 36, 38};
// set the tempo
int oneFourtyBPM = 396.5;
// set the base bit patterns for each row
byte data[] = {
0, 0, 0, 0
};
// define the size of the matrix (4x4)
int columns = 4;
int rows = 4;
// For 140BPM:
float sixtyFourthNote = 5.543;
float thirtySecondNote = 11.086;
float sixteenthNote = 26.254;
float eigthNote = 47.57;
float quarterNote = 99.425;
float halfNote = 198.861;
float wholeNote = 397.712;
int startTime = 0;
int endTime = 0;
//-------------------------------------------------------------------------------------------

void setup()
{
note_c_23_27.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1
the Arduino board (for the piano keys/buzzer)
Serial.begin(9600);
pinMode(buzzer, OUTPUT); //pin declared as OUTPUT
// Start the serial communication between the laptop and the Arduino board (for the LED matrix)
Serial.begin(9600);
for (int i = 0; i < 4; i++) {
pinMode(row[i], OUTPUT);
pinMode(col[i], OUTPUT);
}
}
void loop()
{
// Set a timer
long start = millis();
// Set the sensitivity of the sensors
long sensor1 = note_c_23_27.capacitiveSensor(30);
long sensor2 = note_d_23_29.capacitiveSensor(30);
long sensor3 = note_e_23_31.capacitiveSensor(30);
long sensor4 = note_f_23_33.capacitiveSensor(30);
long sensor5 = note_g_23_35.capacitiveSensor(30);
long sensor6 = note_a_23_37.capacitiveSensor(30);
long sensor7 = note_b_23_39.capacitiveSensor(30);
long sensor8 = note_c_23_41.capacitiveSensor(30);
Serial.print(millis() - start); // check on performance in milliseconds
Serial.print("\t"); // tab character for debug window spacing
Serial.print(sensor1); // print each sensor output from keys 1-8 (in the C scale)
Serial.print("\t"); // Leave some space before printing the next output
Serial.print(sensor2);
Serial.print("\t");
Serial.print(sensor3);
Serial.print("\t");
Serial.print(sensor4);
Serial.print("\t");
Serial.print(sensor5);
Serial.print("\t");
Serial.print(sensor6);
Serial.print("\t");
Serial.print(sensor7);
Serial.print("\t");
Serial.println(sensor8);
// When one's finger touches the sensor, the buzzer will produce a tone according to its frequency
// and display the letter formation of each key on the LED matrix display
if (sensor1 > 800) {
t.tone(buzzer,NOTE_C4,600);
display_C(wholeNote);
}
if (sensor2 > 800) {
t.tone(buzzer,NOTE_D4,600);
display_D(wholeNote);
}
if (sensor3 > 800) {
t.tone(buzzer,NOTE_E4,600);
display_E(wholeNote);
}
if (sensor4 > 800) {
t.tone(buzzer,NOTE_F4,600);
display_F(wholeNote);
}
if (sensor5 > 800) {
t.tone(buzzer,NOTE_G4,600);
display_G(wholeNote);
}
if (sensor6 > 800) {
t.tone(buzzer,NOTE_A4,600);
display_A(wholeNote);
}
if (sensor7 > 800) {
t.tone(buzzer,NOTE_B4,600);
display_B(wholeNote);
}
if (sensor8 > 800) {
t.tone(buzzer,NOTE_C5,600);
display_C2(wholeNote);
}
// When the sensor isn't being touched, the buzzer will not produce any tones
/* if (sensor1<=800 & sensor2<=800 & sensor3<=800 & sensor4<=800 & sensor5<=800 & sensor6<=800 & sensor7<=800 & sensor8<=800)
notone(buzzer);*/
delay(10); // arbitrary delay to limit data to serial port
}

//---------------------------------------------------------------------------------------------------------
void allOff() {
for (int i = 0; i < 4; i++)
{
digitalWrite(row[i], LOW);
digitalWrite(col[i], HIGH);
}
}
void allOn() {
for (int i = 0; i < 4; i++)
{
digitalWrite(row[i], HIGH);
digitalWrite(col[i], LOW);
}
}
void showPattern(float tempo) {
for (int i = 0; i < tempo; i++) {
for (int thisRow = 0; thisRow < rows; thisRow++)
{
allOff();
digitalWrite(row[thisRow], HIGH);
for (int thisCol = 0; thisCol < columns; thisCol++)
{
if (bitRead(data[thisRow], columns - thisCol - 1) == 1)
{
digitalWrite(col[thisCol], LOW);
}
else
{
digitalWrite(col[thisCol], HIGH);
}
}
delay(1);
}
}
}

//********LED MATRIX DISPLAY LETTER PATTERNS*********
// defines letter formation in binary format
void allOn(float tempo) {
data[0] = B1111;
data[1] = B1111;
data[2] = B1111;
data[3] = B1111;
showPattern(tempo);
}
void pattern_C(float tempo) {
data[0] = B1111;
data[1] = B1000;
data[2] = B1000;
data[3] = B1111;
showPattern(tempo);
}
void pattern_D(float tempo) {
data[0] = B1110;
data[1] = B1001;
data[2] = B1001;
data[3] = B1110;
showPattern(tempo);
}
void pattern_E(float tempo) {
data[0] = B1111;
data[1] = B1110;
data[2] = B1000;
data[3] = B1111;
showPattern(tempo);
}
void pattern_F(float tempo) {
data[0] = B1111;
data[1] = B1110;
data[2] = B1000;
data[3] = B1000;
showPattern(tempo);
}
void pattern_G(float tempo) {
data[0] = B1111;
data[1] = B1000;
data[2] = B1011;
data[3] = B1111;
showPattern(tempo);
}
void pattern_A(float tempo) {
data[0] = B0110;
data[1] = B1001;
data[2] = B1111;
data[3] = B1001;
showPattern(tempo);
}
void pattern_B(float tempo) {
data[0] = B1110;
data[1] = B1110;
data[2] = B1001;
data[3] = B1111;
showPattern(tempo);
}
void pattern_C2(float tempo) {
data[0] = B1111;
data[1] = B1000;
data[2] = B1000;
data[3] = B1111;
showPattern(tempo);
}
//*********LED MATRIX DISPLAY ANIMATIONS********
// The animations keep in tempo to display the letters in the c scale
void display_C(float tempo) {
pattern_C(tempo);
delay(1000);
}
void display_D(float tempo) {
pattern_D(tempo);
delay(1000);
}
void display_E(float tempo) {
pattern_E(tempo);
delay(1000);
}
void display_F(float tempo) {
pattern_F(tempo);
delay(1000);
}
void display_G(float tempo) {
pattern_G(tempo);
delay(1000);
}
void display_A(float tempo) {
pattern_A(tempo);
delay(1000);
}
void display_B(float tempo) {
pattern_B(tempo);
delay(1000);
}
void display_C2(float tempo) {
pattern_C2(tempo);
delay(1000);
}
void flash() {
allOn(eigthNote);
allOff();
delay(halfNote + 16);
}
