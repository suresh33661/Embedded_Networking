#include <Arduino.h>

void toBinaryString(char character) {
    for (int i = 7; i >= 0; i--) {
        Serial.print((character >> i) & 1);  
    }
}

void processString(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        char currentChar = str[i];
        
        if (isAlpha(currentChar)) {
            
            Serial.print("Character '");
            Serial.print(currentChar);
            Serial.print("' -> Binary: ");
            toBinaryString(currentChar);
            Serial.println();
        } else if (isspace(currentChar)) {
            
            Serial.println("Space detected.");
        } else {
            Serial.print("Non-alphabetic character '");
            Serial.print(currentChar);
            Serial.println("' ignored.");
        }
    }
}

void setup() {
    
    Serial.begin(115200);
    while (!Serial);  
    Serial.println("Enter a string of words (A-Z or a-z):");
}

void loop() {
    
    if (Serial.available() > 0) {
        
        String inputString = Serial.readStringUntil('\n');  
        
       
        processString(inputString.c_str());
        
        
        
    }
}
