#include <stdio.h>
#include <string.h>
#include <ctype.h>

void imprimirDerivacion(char *entrada); 

int main() {
    char entrada[100];

    printf("Ingrese la cantidad (ej. 7.1e4): ");
    scanf("%s", entrada);

    printf("Derivacion para %s:\n", entrada);
    imprimirDerivacion(entrada);

    return 0;
}

void imprimirDerivacion(char *entrada) {

    char *pos=strchr(entrada, 'e');
    if (pos==NULL) {
        pos=strchr(entrada, 'E');
    }
    if (pos==NULL) {
        printf("Entrada invalida"); 
        return;
    }

    // Es . EN
    int indice=pos-entrada;
    char part1[100], part2[100];
    strncpy(part1, entrada, indice);
    part1[indice] = '\0';
    strcpy(part2, pos + 1);

    printf("-> Es.ENExEs\n");

    if (part1[0] == '-' || part1[0] == '+') {
        printf("-> SEN.ENExEs\n");
        printf("-> %cEN.ENExEs\n", part1[0]);
        memmove(part1, part1 + 1, strlen(part1));
    } else {
        printf("-> EN.ENExEs\n");
    }

    printf("-> DR.ENExEs\n");
    printf("-> %cR.ENExEs\n", part1[0]);
    int i=1;
    while (isdigit(part1[i])) {
        printf("-> %cR.ENExEs\n", part1[i]);
        i++;
    }
    if (part1[i] == '.') {
        printf("-> %s.DRExEs\n", part1);
        i++;
        while (isdigit(part1[i])) {
            printf("-> %s.%cRExEs\n", part1, part1[i]);
            i++;
        }
    }
    printf("-> %sExEs\n", part1);

    printf("-> %seEs\n", part1);

    if (part2[0] == '-' || part2[0] == '+') {
        printf("-> %seSEN\n", part1);
        printf("-> %se%cEN\n", part1, part2[0]);
        memmove(part2, part2 + 1, strlen(part2));
    } else {
        printf("-> %seEN\n", part1);
    }

    printf("-> %seDR\n", part1);
    printf("-> %se%cR\n", part1, part2[0]);
    i = 1;
    while (isdigit(part2[i])) {
        printf("-> %se%cR\n", part1, part2[i]);
        i++;
    }
    printf("-> %se%s\n", part1, part2);
}




