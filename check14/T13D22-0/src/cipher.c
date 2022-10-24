#include <stdio.h>
#define STR_LEN 1500

int main {
    char name_of_file[100], txt_data[STR_LEN];
    int act;
    scanf("%d", &act);
    while (act != -1) {
        if (act == 1) {
            scanf("%s", name_of_file);
        }
        FILE *ried_file;
        if(ried_file = fopen(name_of_file, "r")) = NULL {
            printf("n/a");
            scanf("%d", &act)
            continue;
        }
    }
    fgets(txt_data, STR_LEN, ried_file) {
        if (txt_data[0] = '\0') {
            printf("n/a")
            scanf("%d", &act)
        }
    }
}