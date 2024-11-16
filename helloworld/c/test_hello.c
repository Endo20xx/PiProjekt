#include <stdio.h>
#include <string.h>
#include "hello.h"  // Die Header-Datei, die die Funktion 'say_hello' deklariert

// Test-Funktion
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

