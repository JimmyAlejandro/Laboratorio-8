#include <Arduino.h>

// Definir las imágenes ASCII como matrices de caracteres
const char imagen1[] =
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@*.@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@**@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@/*@@@@@@@%#(@@@@@@@@@@@@@\n"
"@@@@@@@#@@./&/%*,,&.(@@@(@@@@@@@\n"
"@@@@@@@&@@@@/#%/&%(..%(*,@@@@@@@\n"
"@@@%%%#&*@%&@&&&&&&#(@@@@@@@@@@@\n"
"@%@%%%%%&&%&&&%#(**#@/(@@@@@@@@\n"
"@@@@@#%@@%&%%%%#&&&&%@@&(/(@@@@@\n"
"@@@@@@@@@@%%%&%%#/,##@&&#%(@@@\n"
"@@@@@@@@@@@@%&%%&#((@@@(&&(@@@@@\n"
"@@@@@@@@@@@@@&@%%%%@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";

const char imagen2[] =
"                                 \n"
"    @@                     @@    \n"
"   @@@@                   @&@*   \n"
"   @%%@  %@@@@@&&&@@@@@(  @%%@   \n"
"  ,@%%@&&%%%%%%&&&%%%%%%%@@%%@   \n"
"  @&%%%%%%@@@@@@@@@@@@@%%%%%%@@  \n"
"  @%%%%%@@@@@@@@@@@@@@@@@%%%%%@  \n"
"  @%%%&@@@@@@@@@@@@@@@@@@@%%%%@  \n"
".@%%%@  /@@@@@@@@@@@@@*  @%%%@  \n"
"  @&%%@@@@@@@@@@@@@@@@@@@@@%%&@  \n"
"   @@%@@.......,%........@@%@@   \n"
"     /@@................,@@.     \n"
"     @@@//@//%@@@@@#//@//@@&     \n"
"  .@&@//@%/@@@@@@@@@@@/@@//@%@   \n"
"  @&%%%@(////*..#..#////@@%%%%@  \n"
"   @@@@@&@&&&&&*&&&&&&&@@@@@   \n"
"  @@%%@@%%%%%%%%%%%%%%%%%@@%%@&  \n"
"  @%%%@/////////@////////#@&%%@  \n"
"  @@  @@%%%%%%%%@%%%%%%%%@@  @@  \n"
"        @@@@@@@& @@@@@@@@       \n";

const char imagen3[] =
"@@@@................,,,,,,,,(@@@\n"
"@@@@.%./..,,,,...,,...%,,,,,(@@@\n"
"@@@@,(,..,,,,,,,,,(..,.*,,,,(@@@\n"
"@@@@,,,,..,......#.,/,,,,,,,(@@@\n"
"@@@@,,,,............,,,//%%%(@@@\n"
"@@@@*,.& .....(.&,...%%%%%(@@@\n"
"@@@@###*..............&&%@@@\n"
"@@@@///%..........((((((((%@@@\n"
"@@@@(((,...**...##/////(%@@@\n"
"@@@@((/,,...,,,*...,,///////#@@@\n"
"@@@@//,,,,..,.,..,*,,(((((((%@@@\n"
"@@@@((*,,,,,,,,,,*//////#@@@\n"
"@@@@///%*/////**#(/////(%@@@\n";

// Definir una matriz para almacenar la imagen personalizada de 32x32
char imagenPersonalizada[32][32];

void setup() {
  Serial.begin(9600);
  Serial.println("Elija una imagen:");
  Serial.println("1. Imagen 1");
  Serial.println("2. Imagen 2");
  Serial.println("3. Imagen 3");
  Serial.println("4. Crear imagen Personalizada");
}

void loop() {
  if (Serial.available() > 0) {
    char opcion = Serial.read();
    switch (opcion) {
      case '1':
        mostrarImagen(imagen1);
        break;
      case '2':
        mostrarImagen(imagen2);
        break;
      case '3':
        mostrarImagen(imagen3);
        break;
      case '4':
        crearImagenPersonalizada();
        mostrarImagen(imagenPersonalizada);
        break;
    }
  }
}

void mostrarImagen(const char* imagen) {
  Serial.println("Imagen:");
  Serial.println(imagen);
}

void mostrarImagen(char imagen[32][32]) {
  Serial.println("Imagen Personalizada:");
  for (int i = 0; i < 32; i++) {
    Serial.println(imagen[i]);
  }
}

void crearImagenPersonalizada() {
  Serial.println("Ingrese su imagen personalizada (32x32 caracteres):");

  // Leer la imagen personalizada desde la terminal
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 32; j++) {
      while (!Serial.available()) {
        // Esperar a que el usuario ingrese un carácter
      }
      imagenPersonalizada[i][j] = Serial.read();
    }
  }
}
