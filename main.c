#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int MAX_ESTUDIANTES = 5;
    int MAX_MATERIAS = 3;
    int MAX_NOMBRE = 50;
    int numEstudiantes = 0;
    int numMaterias = 0;
    char entrada[100];
    char estudiantes[MAX_ESTUDIANTES][MAX_NOMBRE];
    char materias[MAX_MATERIAS][MAX_NOMBRE];
    float notas[MAX_ESTUDIANTES][MAX_MATERIAS];
    int repetir;
    do {
        do {
            printf("\tIngrese el numero de estudiantes (1-%d): ", MAX_ESTUDIANTES);
            fgets(entrada, sizeof(entrada), stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            if (strlen(entrada) == 0) {
                 printf("\tError, la entrada no puede estar vacia.\n");
                 numEstudiantes = 0;
                 continue;
            }
            int valido = 1;
            for (int i = 0; entrada[i] != '\0'; i++) {
                if (entrada[i] < '0' || entrada[i] > '9') {
                    valido = 0;
                    break;
                }
            }
            if (!valido) {
                printf("\tError, solo se permiten numeros.\n");
                numEstudiantes = 0;
                continue;
            }
            numEstudiantes = 0;
            for (int i = 0; entrada[i] != '\0'; i++) {
                if (numEstudiantes > (2147483647 / 10) - (entrada[i] - '0')) {
                      printf("\tError, numero demasiado grande.\n");
                      numEstudiantes = 0;
                      valido = 0;
                      break;
                 }
                numEstudiantes = numEstudiantes * 10 + (entrada[i] - '0');
            }
            if (!valido) continue;
            if (numEstudiantes < 1 || numEstudiantes > MAX_ESTUDIANTES) {
                printf("\tError, el numero debe estar entre 1 y %d.\n", MAX_ESTUDIANTES);
            }
        } while (numEstudiantes < 1 || numEstudiantes > MAX_ESTUDIANTES);
        do {
            printf("\tIngrese el numero de materias (1-%d): ", MAX_MATERIAS);
            fgets(entrada, sizeof(entrada), stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            if (strlen(entrada) == 0) {
                 printf("\tError, la entrada no puede estar vacia.\n");
                 numMaterias = 0;
                 continue;
            }
            int valido = 1;
            for (int i = 0; entrada[i] != '\0'; i++) {
                if (entrada[i] < '0' || entrada[i] > '9') {
                    valido = 0;
                    break;
                }
            }
            if (!valido) {
                printf("\tError, solo se permiten numeros.\n");
                numMaterias = 0;
                continue;
            }
            numMaterias = 0;
            for (int i = 0; entrada[i] != '\0'; i++) {
                if (numMaterias > (2147483647 / 10) - (entrada[i] - '0')) {
                      printf("\tError, numero demasiado grande.\n");
                      numMaterias = 0;
                      valido = 0;
                      break;
                 }
                numMaterias = numMaterias * 10 + (entrada[i] - '0');
            }
            if (!valido) continue;
            if (numMaterias < 1 || numMaterias > MAX_MATERIAS) {
                printf("\tError, el numero de materias debe estar entre 1 y %d.\n", MAX_MATERIAS);
            }
        } while (numMaterias < 1 || numMaterias > MAX_MATERIAS);
        printf("\n\tIngreso de Nombres de Estudiantes\n");
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
        printf("\n\tIngreso de Nombres de Materias\n");
        for (int i = 0; i < numMaterias; i++) {
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
        printf("\n\tIngreso de Notas\n");
        for (int i = 0; i < numEstudiantes; i++) {
             printf("\tNotas para %s:\n", estudiantes[i]);
            for (int j = 0; j < numMaterias; j++) {
                while (1) {
                    printf("\tIngrese la nota de %s (0-10): ", materias[j]);
                    fgets(entrada, sizeof(entrada), stdin);
                    entrada[strcspn(entrada, "\n")] = '\0';
                    if (strlen(entrada) == 0) {
                        printf("\tError, ingrese un numero valido entre 0 y 10.\n");
                        continue;
                    }
                    int valido = 1;
                    int puntos = 0;
                    for (int k = 0; entrada[k] != '\0'; k++) {
                        if (entrada[k] < '0' || entrada[k] > '9') {
                            if (entrada[k] == '.' && puntos == 0) {
                                puntos++;
                            } else {
                                valido = 0;
                                break;
                            }
                        }
                    }
                    if (strlen(entrada) == 1 && entrada[0] == '.') {
                        valido = 0;
                    }
                    if (!valido) {
                        printf("\tError, formato invalido. Ingrese un numero valido entre 0 y 10 (ej: 7, 9.5).\n");
                        continue;
                    }
                    float numNota = 0.0f;
                    int puntoDecimal = 0;
                    float divisor = 10.0f;
                    for (int k = 0; entrada[k] != '\0'; k++) {
                        if (entrada[k] == '.') {
                            puntoDecimal = 1;
                        } else {
                            if (puntoDecimal) {
                                numNota += (float)(entrada[k] - '0') / divisor;
                                divisor *= 10.0f;
                            } else {
                                numNota = numNota * 10 + (float)(entrada[k] - '0');
                            }
                        }
                    }
                    if (numNota < 0.0f || numNota > 10.0f) {
                        printf("\tError, la nota debe estar entre 0.0 y 10.0.\n");
                    } else {
                        notas[i][j] = numNota;
                        break;
                    }
                }
            }
        }
        int salirMenu = 0;
        do {
            printf("\n\tMenu de Reportes\n");
            printf("\t1.- Notas por estudiante\n");
            printf("\t2.- Promedios por materia\n");
            printf("\t3.- Aprobados/reprobados por materia\n");
            printf("\t4.- Ver TODOS los reportes generales\n");
            printf("\t5.- Salir\n");
            printf("\tSeleccione una opcion (1-5): ");
            fgets(entrada, sizeof(entrada), stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            if (strlen(entrada) != 1 || entrada[0] < '1' || entrada[0] > '5') {
                printf("\tError, opcion invalida. Ingrese un numero entre 1 y 5.\n");
                continue;
            }
            int opcion = entrada[0] - '0';
            switch (opcion) {
                case 1:
                    while (1) {
                        printf("\n\tSeleccione el estudiante\n");
                        for (int i = 0; i < numEstudiantes; i++) {
                            printf("\t%d.- %s\n", i + 1, estudiantes[i]);
                        }
                        printf("\t%d.- Todos los estudiantes\n", numEstudiantes + 1);
                        printf("\tIngrese el numero del estudiante (1-%d): ", numEstudiantes + 1);
                        fgets(entrada, sizeof(entrada), stdin);
                        entrada[strcspn(entrada, "\n")] = '\0';
                        if (strlen(entrada) == 0) {
                             printf("\tError, la entrada no puede estar vacia.\n");
                             continue;
                        }
                        int valido = 1;
                        for(int k=0; entrada[k] != '\0'; k++) {
                            if (entrada[k] < '0' || entrada[k] > '9') {
                                valido = 0; break;
                            }
                        }
                        if (!valido) {
                            printf("\tError, solo se permiten numeros.\n");
                            continue;
                        }
                        int seleccionEstudiante = 0;
                        for (int k = 0; entrada[k] != '\0'; k++) {
                             if (seleccionEstudiante > (2147483647 / 10) - (entrada[k] - '0')) {
                                  printf("\tError, numero demasiado grande.\n");
                                  seleccionEstudiante = 0;
                                  valido = 0;
                                  break;
                             }
                            seleccionEstudiante = seleccionEstudiante * 10 + (entrada[k] - '0');
                        }
                        if (!valido) continue;
                        if (seleccionEstudiante < 1 || seleccionEstudiante > (numEstudiantes + 1)) {
                            printf("\tError, opcion invalida. Debe ser entre 1 y %d.\n", numEstudiantes + 1);
                            continue;
                        }
                        if (seleccionEstudiante == numEstudiantes + 1) {
                            printf("\n\tNotas de Todos los Estudiantes\n");
                            for (int idx_loop = 0; idx_loop < numEstudiantes; idx_loop++) {
                                printf("\n\tEstudiante: %s\n", estudiantes[idx_loop]);
                                printf("\t%-25s\tNota\tEstado\n", "Materia");
                                int aprobadas = 0, reprobadas = 0;
                                float sumaNotas = 0.0f;
                                float maxNota = -1.0f, minNota = 11.0f;
                                if (numMaterias > 0) {
                                     maxNota = notas[idx_loop][0];
                                     minNota = notas[idx_loop][0];
                                    for (int j = 0; j < numMaterias; j++) {
                                        sumaNotas += notas[idx_loop][j];
                                        const char *estado = (notas[idx_loop][j] >= 6.0f) ? "Aprobado" : "Reprobado";
                                        printf("\t%-25s\t%.2f\t%s\n", materias[j], notas[idx_loop][j], estado);
                                        if (notas[idx_loop][j] >= 6.0f) aprobadas++;
                                        else reprobadas++;
                                        if (notas[idx_loop][j] > maxNota) maxNota = notas[idx_loop][j];
                                        if (notas[idx_loop][j] < minNota) minNota = notas[idx_loop][j];
                                    }
                                    printf("\tPromedio: %.2f | Aprobadas: %d | Reprobadas: %d\n", sumaNotas / numMaterias, aprobadas, reprobadas);
                                    printf("\tNota Maxima: %.2f | Nota Minima: %.2f\n", maxNota, minNota);
                                } else {
                                     printf("\tNo hay materias registradas.\n");
                                }
                            }
                        } else {
                            int idx = seleccionEstudiante - 1;
                            printf("\n\tNotas de %s:\n", estudiantes[idx]);
                            printf("\t%-25s\tNota\tEstado\n", "Materia");
                            int aprobadas = 0, reprobadas = 0;
                            float sumaNotas = 0.0f;
                            float maxNota = -1.0f, minNota = 11.0f;
                             if (numMaterias > 0) {
                                 maxNota = notas[idx][0];
                                 minNota = notas[idx][0];
                                for (int j = 0; j < numMaterias; j++) {
                                    sumaNotas += notas[idx][j];
                                    const char *estado = (notas[idx][j] >= 6.0f) ? "Aprobado" : "Reprobado";
                                    printf("\t%-25s\t%.2f\t%s\n", materias[j], notas[idx][j], estado);
                                    if (notas[idx][j] >= 6.0f) aprobadas++;
                                    else reprobadas++;
                                    if (notas[idx][j] > maxNota) maxNota = notas[idx][j];
                                    if (notas[idx][j] < minNota) minNota = notas[idx][j];
                                }
                                printf("\tPromedio: %.2f | Aprobadas: %d | Reprobadas: %d\n", sumaNotas / numMaterias, aprobadas, reprobadas);
                                printf("\tNota Maxima: %.2f | Nota Minima: %.2f\n", maxNota, minNota);
                            } else {
                                printf("\tNo hay materias registradas.\n");
                            }
                        }
                        break;
                    }
                    break;
                case 2:
                    printf("\n\t===== Promedios por materia =====\n");
                    printf("\t%-25s\tPromedio\tNota mas alta\tNota mas baja\n", "Materia");
                    for (int j = 0; j < numMaterias; j++) {
                        float suma = 0;
                        float maxNota = (numEstudiantes > 0) ? notas[0][j] : 0.0f;
                        float minNota = (numEstudiantes > 0) ? notas[0][j] : 0.0f;
                         if (numEstudiantes > 0) {
                            for (int i = 0; i < numEstudiantes; i++) {
                                suma += notas[i][j];
                                if (notas[i][j] > maxNota) maxNota = notas[i][j];
                                if (notas[i][j] < minNota) minNota = notas[i][j];
                            }
                            printf("\t%-25s\t%.2f\t\t%.2f\t\t%.2f\n", materias[j], suma / numEstudiantes, maxNota, minNota);
                         } else {
                            printf("\t%-25s\t N/A\t\t N/A\t\t N/A\n", materias[j]);
                         }
                    }
                    break;
                case 3:
                    printf("\n\t===== Aprobados y Reprobados por materia =====\n");
                    printf("\t%-25s\tAprobados\tReprobados\n", "Materia");
                    for (int j = 0; j < numMaterias; j++) {
                        int aprob = 0, reprob = 0;
                         if (numEstudiantes > 0) {
                            for (int i = 0; i < numEstudiantes; i++) {
                                if (notas[i][j] >= 6.0f) aprob++;
                                else reprob++;
                            }
                            printf("\t%-25s\t%d\t\t%d\n", materias[j], aprob, reprob);
                         } else {
                             printf("\t%-25s\t0\t\t0\n", materias[j]);
                         }
                    }
                    printf("\n\t===== Nombres de Aprobados y Reprobados por materia =====\n");
                    for (int j = 0; j < numMaterias; j++) {
                        printf("\t--- Materia: %s ---\n", materias[j]);
                        printf("\t Aprobados: ");
                        int countAprob = 0;
                        for (int i = 0; i < numEstudiantes; i++) {
                            if (notas[i][j] >= 6.0f) {
                                if (countAprob > 0) printf(", ");
                                printf("%s", estudiantes[i]);
                                countAprob++;
                            }
                        }
                        if (countAprob == 0) printf("(Ninguno)");
                        printf("\n");
                        printf("\t Reprobados: ");
                         int countReprob = 0;
                        for (int i = 0; i < numEstudiantes; i++) {
                            if (notas[i][j] < 6.0f) {
                                if (countReprob > 0) printf(", ");
                                printf("%s", estudiantes[i]);
                                countReprob++;
                            }
                        }
                         if (countReprob == 0) printf("(Ninguno)");
                        printf("\n");
                    }
                    break;
                case 4:
                    printf("\n\tReportes:\n");
                    printf("\n\t===== Promedios por estudiante =====\n");
                    printf("\t%-25s\tPromedio\tNota mas alta\tNota mas baja\n", "Nombre Estudiante");
                    if (numEstudiantes > 0 && numMaterias > 0) {
                        for (int i = 0; i < numEstudiantes; i++) {
                            float suma = 0;
                            float maxNota = notas[i][0];
                            float minNota = notas[i][0];
                            for (int j = 0; j < numMaterias; j++) {
                                suma += notas[i][j];
                                if (notas[i][j] > maxNota) maxNota = notas[i][j];
                                if (notas[i][j] < minNota) minNota = notas[i][j];
                            }
                            printf("\t%-25s\t%.2f\t\t%.2f\t\t%.2f\n", estudiantes[i], suma / numMaterias, maxNota, minNota);
                        }
                    } else {
                         printf("\t (No hay suficientes datos para calcular promedios por estudiante)\n");
                    }
                    printf("\n\t===== Promedios por materia =====\n");
                    printf("\t%-25s\tPromedio\tNota mas alta\tNota mas baja\n", "Materia");
                    for (int j = 0; j < numMaterias; j++) {
                        float suma = 0;
                        float maxNota = (numEstudiantes > 0) ? notas[0][j] : 0.0f;
                        float minNota = (numEstudiantes > 0) ? notas[0][j] : 0.0f;
                         if (numEstudiantes > 0) {
                            for (int i = 0; i < numEstudiantes; i++) {
                                suma += notas[i][j];
                                if (notas[i][j] > maxNota) maxNota = notas[i][j];
                                if (notas[i][j] < minNota) minNota = notas[i][j];
                            }
                            printf("\t%-25s\t%.2f\t\t%.2f\t\t%.2f\n", materias[j], suma / numEstudiantes, maxNota, minNota);
                         } else {
                              printf("\t%-25s\t N/A\t\t N/A\t\t N/A\n", materias[j]);
                         }
                    }
                    printf("\n\t===== Aprobados y Reprobados por materia =====\n");
                    printf("\t%-25s\tAprobados\tReprobados\n", "Materia");
                    for (int j = 0; j < numMaterias; j++) {
                        int aprob = 0, reprob = 0;
                        if (numEstudiantes > 0) {
                           for (int i = 0; i < numEstudiantes; i++) {
                               if (notas[i][j] >= 6.0f) aprob++;
                               else reprob++;
                           }
                           printf("\t%-25s\t%d\t\t%d\n", materias[j], aprob, reprob);
                        } else {
                             printf("\t%-25s\t0\t\t0\n", materias[j]);
                        }
                    }
                    printf("\n\t===== Nombres de Aprobados y Reprobados por materia =====\n");
                    for (int j = 0; j < numMaterias; j++) {
                        printf("\t--- Materia: %s ---\n", materias[j]);
                        printf("\t Aprobados: ");
                        int countAprob = 0;
                        for (int i = 0; i < numEstudiantes; i++) {
                            if (notas[i][j] >= 6.0f) {
                                if (countAprob > 0) printf(", ");
                                printf("%s", estudiantes[i]);
                                countAprob++;
                            }
                        }
                         if (countAprob == 0) printf("(Ninguno)");
                        printf("\n");
                        printf("\t Reprobados: ");
                        int countReprob = 0;
                        for (int i = 0; i < numEstudiantes; i++) {
                            if (notas[i][j] < 6.0f) {
                                if (countReprob > 0) printf(", ");
                                printf("%s", estudiantes[i]);
                                countReprob++;
                            }
                        }
                         if (countReprob == 0) printf("(Ninguno)");
                        printf("\n");
                    }
                    break;
                case 5:
                    printf("\tSaliendo.\n");
                    salirMenu = 1;
                    break;
                default:
                     printf("\tError: Opcion desconocida.\n");
                     break;
            }
        } while (!salirMenu);
        int respuestaRepetirValida = 0;
        do {
            printf("\n\tDesea ingresar un nuevo conjunto de datos? (1 = Si, 0 = No): ");
            fgets(entrada, sizeof(entrada), stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            if (strlen(entrada) == 1 && (entrada[0] == '1' || entrada[0] == '0')) {
                repetir = entrada[0] - '0';
                respuestaRepetirValida = 1;
            } else {
                printf("\tError: Por favor ingrese solo 1 para Si o 0 para No.\n");
            }
        } while (!respuestaRepetirValida);
    } while (repetir == 1);
    printf ("\n\tQue tenga un lindo dia lleno de emocion\n");
    return 0;
}