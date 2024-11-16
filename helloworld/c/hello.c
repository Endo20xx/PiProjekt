// hello.c
#include <stdio.h>
#include <string.h>
#include "hello.h"  // Header-Datei für die Funktion 'say_hello'

// Funktion zum Testen der say_hello-Funktion
void test_say_hello() {
    char buffer[50];
    FILE *fp;

    // Standardausgabe umleiten
    fp = freopen("test_output.txt", "w", stdout);
    if (!fp) {
        printf("Fehler: Standardausgabe konnte nicht umgeleitet werden.\n");
        return;
    }

    // Die zu testende Funktion aufrufen
    say_hello();

    // Standardausgabe zurücksetzen
    freopen("/dev/tty", "w", stdout);

    // Ergebnis aus der Datei lesen
    fp = fopen("test_output.txt", "r");
    if (fp) {
        fgets(buffer, sizeof(buffer), fp);
        fclose(fp);
    }

    // Überprüfen, ob die Ausgabe korrekt ist
    if (strcmp(buffer, "Hallo, Welt!\n") == 0) {
        printf("Test erfolgreich: Ausgabe ist korrekt.\n");
    } else {
        printf("Test fehlgeschlagen: Erwartet 'Hallo, Welt!', erhalten '%s'\n", buffer);
    }
}

// Funktion say_hello
void say_hello() {
    printf("Hallo, Welt!\n");
}

// Main-Funktion, die den Test und die normale Ausgabe aufruft
int main() {
    // Hier wird der Test ausgeführt
    test_say_hello();

    // Die normale Ausgabe der say_hello-Funktion
    say_hello();
    
    return 0;
}

