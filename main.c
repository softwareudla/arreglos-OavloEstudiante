#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int MAX_ESTUDIANTES = 5;
    int MAX_MATERIAS = 3;
    int MAX_NOMBRE = 50;
    int numEstudiantes;
    char entrada[100];
    char estudiantes[MAX_ESTUDIANTES][MAX_NOMBRE];
    char materias[MAX_MATERIAS][MAX_NOMBRE];
    float notas[MAX_ESTUDIANTES][MAX_MATERIAS];

    int repetir;
    do {
        do {
            printf("\tIngrese el numero de estudiantes (1-5): ");
            fgets(entrada, sizeof(entrada), stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            int valido = 1;
            for (int i = 0; entrada[i] != '\0'; i++) {
                if (entrada[i] < '0' || entrada[i] > '9') {
                    valido = 0;
                    break;
                }
            }
            if (!valido) {
                printf("\tError, solo se permiten numeros.\n");
                continue;
            }
            numEstudiantes = 0;
            for (int i = 0; entrada[i] != '\0'; i++) {
                numEstudiantes = numEstudiantes * 10 + (entrada[i] - '0');
            }
            if (numEstudiantes < 1 || numEstudiantes > MAX_ESTUDIANTES) {
                printf("\tError, el numero debe estar entre 1 y 5.\n");
            }
        } while (numEstudiantes < 1 || numEstudiantes > MAX_ESTUDIANTES);

        for (int i = 0; i < numEstudiantes; i++) {
            while (1) {
                printf("\tIngrese el nombre del estudiante %d: ", i + 1);
                fgets(estudiantes[i], MAX_NOMBRE, stdin);
                estudiantes[i][strcspn(estudiantes[i], "\n")] = '\0';

                if (strlen(estudiantes[i]) == 0) {
                    printf("\tError, el nombre no puede estar vacio.\n");
                    continue;
                }

                int valido = 1;
                for (int j = 0; estudiantes[i][j] != '\0'; j++) {
                    if (!(estudiantes[i][j] >= 'A' && estudiantes[i][j] <= 'Z' || 
                        estudiantes[i][j] >= 'a' && estudiantes[i][j] <= 'z' || 
                        estudiantes[i][j] == ' ')) {
                        valido = 0;
                        break;
                    }
                }
                if (!valido) {
                    printf("\tError, solo se permiten letras y espacios.\n");
                    continue;
                }

                int repetido = 0;
                for (int j = 0; j < i; j++) {
                    if (strcmp(estudiantes[i], estudiantes[j]) == 0) {
                        repetido = 1;
                        break;
                    }
                }
                if (repetido) {
                    printf("\tError, el nombre ya ha sido ingresado.\n");
                    continue;
                }
                break;
            }
        }

        for (int i = 0; i < MAX_MATERIAS; i++) {
            while (1) {
                printf("\tIngrese el nombre de la materia %d: ", i + 1);
                fgets(materias[i], MAX_NOMBRE, stdin);
                materias[i][strcspn(materias[i], "\n")] = '\0';

                if (strlen(materias[i]) == 0) {
                    printf("\tError, el nombre no puede estar vacio.\n");
                    continue;
                }

                int valido = 1;
                for (int j = 0; materias[i][j] != '\0'; j++) {
                    if (!(materias[i][j] >= 'A' && materias[i][j] <= 'Z' || 
                        materias[i][j] >= 'a' && materias[i][j] <= 'z' || 
                        materias[i][j] == ' ')) {
                        valido = 0;
                        break;
                    }
                }
                if (!valido) {
                    printf("\tError, solo se permiten letras y espacios.\n");
                    continue;
                }

                int repetido = 0;
                for (int j = 0; j < i; j++) {
                    if (strcmp(materias[i], materias[j]) == 0) {
                        repetido = 1;
                        break;
                    }
                }
                if (repetido) {
                    printf("\tError, el nombre ya ha sido ingresado.\n");
                    continue;
                }
                break;
            }
        }

        for (int i = 0; i < numEstudiantes; i++) {
            for (int j = 0; j < MAX_MATERIAS; j++) {
                while (1) {
                    printf("\tIngrese la nota de %s en %s (0-10): ", estudiantes[i], materias[j]);
                    fgets(entrada, sizeof(entrada), stdin);
                    entrada[strcspn(entrada, "\n")] = '\0';

                    int valido = 1;
                    for (int k = 0; entrada[k] != '\0'; k++) {
                        if (entrada[k] < '0' || entrada[k] > '9') {
                            if (entrada[k] != '.') {
                                valido = 0;
                                break;
                            }
                        }
                    }

                    if (!valido || strlen(entrada) == 0) {
                        printf("\tError, ingrese un numero valido entre 0 y 10.\n");
                        continue;
                    }

                    float numNota = 0.0f;
                    int puntoDecimal = 0;
                    for (int k = 0; entrada[k] != '\0'; k++) {
                        if (entrada[k] == '.') {
                            puntoDecimal = 1;
                        } else {
                            if (puntoDecimal) {
                                numNota = numNota + (entrada[k] - '0') / (10.0f);
                                puntoDecimal *= 10;
                            } else {
                                numNota = numNota * 10 + (entrada[k] - '0');
                            }
                        }
                    }

                    if (numNota < 0 || numNota > 10) {
                        printf("\tError, la nota debe estar entre 0 y 10.\n");
                    } else {
                        notas[i][j] = numNota;
                        break;
                    }
                }
            }
        }

        printf("\n\t===== Promedios por estudiante =====\n");
        printf("\t%-25s\tPromedio\tNota mas alta\tNota mas baja\n", "Nombre");
        for (int i = 0; i < numEstudiantes; i++) {
            float suma = 0;
            float maxNota = notas[i][0], minNota = notas[i][0];
            for (int j = 0; j < MAX_MATERIAS; j++) {
                suma += notas[i][j];
                if (notas[i][j] > maxNota) maxNota = notas[i][j];
                if (notas[i][j] < minNota) minNota = notas[i][j];
            }
            printf("\t%-25s\t%.2f\t\t%.2f\t\t%.2f\n", estudiantes[i], suma / MAX_MATERIAS, maxNota, minNota);
        }

        printf("\n\t===== Promedios por materia =====\n");
        printf("\t%-25s\tPromedio\tNota mas alta\tNota mas baja\n", "Materia");
        for (int j = 0; j < MAX_MATERIAS; j++) {
            float suma = 0;
            float maxNota = notas[0][j], minNota = notas[0][j];
            for (int i = 0; i < numEstudiantes; i++) {
                suma += notas[i][j];
                if (notas[i][j] > maxNota) maxNota = notas[i][j];
                if (notas[i][j] < minNota) minNota = notas[i][j];
            }
            printf("\t%-25s\t%.2f\t\t%.2f\t\t%.2f\n", materias[j], suma / numEstudiantes, maxNota, minNota);
        }

        printf("\n\t===== Aprobados y Reprobados por materia =====\n");
        printf("\t%-25s\tAprobados\tReprobados\n", "Materia");
        for (int j = 0; j < MAX_MATERIAS; j++) {
            int aprob = 0, reprob = 0;
            printf("\t%-25s\t", materias[j]);
            for (int i = 0; i < numEstudiantes; i++) {
                if (notas[i][j] >= 6)
                    aprob++;
                else
                    reprob++;
            }
            printf("%d\t\t%d\n", aprob, reprob);
        }

        printf("\n\t===== Nombres de Aprobados y Reprobados por materia =====\n");
        for (int j = 0; j < MAX_MATERIAS; j++) {
            printf("\tMateria: %s\n", materias[j]);
            printf("\tAprobados: ");
            for (int i = 0; i < numEstudiantes; i++) {
                if (notas[i][j] >= 6) printf("%s, ", estudiantes[i]);
            }
            printf("\n\tReprobados: ");
            for (int i = 0; i < numEstudiantes; i++) {
                if (notas[i][j] < 6) printf("%s, ", estudiantes[i]);
            }
            printf("\n");
        }

        printf("\n\tDesea ingresar nuevos datos? (1 = Si, 0 = No): ");
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        repetir = entrada[0] == '1' ? 1 : 0;

    } while (repetir);

    printf ("\tQue tenga un lindo dia lleno de emocion\n");

    return 0;
}
