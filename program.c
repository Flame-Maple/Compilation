//
//  main.c
//  词法分析
//
//  Created by Flaming on 2020/10/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char str[10000], factor[100];
    int i, j, k = 0, flag;
    FILE *fp;
    fp = fopen(argv[1], "r");
    while ((fgets(str, 10000, fp)) != NULL) {
        flag = 0;
        k = 0;
        for (i = 0; i < strlen(str); i++) {
            if (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n') {
                factor[k] = '\0';
                if (strlen(factor) != 0) {
                    if (flag == 1) {
                        for (j = 0; factor[j] == '0'; j++)
                            ;
                        if(strlen(factor) != 0)
                            printf("Int(%s)\n", &factor[j]);
                        flag = k = 0;
                    }
                    else if (flag == 2) {
                        if (strcmp(factor, "BEGIN") == 0)
                            printf("Begin\n");
                        else if (strcmp(factor, "END") == 0)
                            printf("End\n");
                        else if (strcmp(factor, "FOR") == 0)
                            printf("For\n");
                        else if (strcmp(factor, "IF") == 0)
                            printf("If\n");
                        else if (strcmp(factor, "THEN") == 0)
                            printf("Then\n");
                        else if(strcmp(factor, "ELSE") == 0)
                            printf("Else\n");
                        else
                            printf("Ident(%s)\n", factor);
                        flag = k = 0;
                    }
                }
            }
            else if (str[i] == ':' || str[i] == '+' || str[i] == '*' || str[i] == ',' || str[i] == '(' || str[i] == ')') {
                factor[k] = '\0';
                if (strlen(factor) != 0) {
                    if (flag == 1) {
                        for (j = 0; factor[j] == '0'; j++)
                            ;
                        if(strlen(factor) != 0)
                            printf("Int(%s)\n", &factor[j]);
                        flag = k = 0;
                    }
                    else if (flag == 2) {
                        if (strcmp(factor, "BEGIN") == 0)
                            printf("Begin\n");
                        else if (strcmp(factor, "END") == 0)
                            printf("End\n");
                        else if (strcmp(factor, "FOR") == 0)
                            printf("For\n");
                        else if (strcmp(factor, "IF") == 0)
                            printf("If\n");
                        else if (strcmp(factor, "THEN") == 0)
                            printf("Then\n");
                        else if(strcmp(factor, "ELSE") == 0)
                            printf("Else\n");
                        else {
                            if(strlen(factor) != 0)
                            printf("Ident(%s)\n", factor);
                        }
                        flag = k = 0;
                    }
                }
                if (str[i] == ':') {
                    if (str[i + 1] == '=') {
                        printf("Assign\n");
                        i++;
                    }
                    else
                        printf("Colon\n");
                }
                else if (str[i] == '+')
                    printf("Plus\n");
                else if (str[i] == '*')
                    printf("Star\n");
                else if (str[i] == ',')
                    printf("Comma\n");
                else if (str[i] == '(')
                    printf("LParenthesis\n");
                else if (str[i] == ')')
                    printf("RParenthesis\n");
            }
            else if (str[i] >= '0' && str[i] <= '9') {
                if (flag == 0)
                    flag = 1;
                factor[k++] = str[i];
            }
            else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
                if (flag == 1) {
                    factor[k] = '\0';
                    for (j = 0; j < strlen(factor) && factor[j] == 0; j++)
                        ;
                    if(strlen(factor) != 0) {
                        if(strlen(factor) != 0)
                            printf("Int(%s)\n", &factor[j]);
                    }
                    flag = k = 0;
                }
                flag = 2;
                factor[k++] = str[i];
            }
            else {
                printf("Unknown\n");
                return 0;
            }
        }
    }
    
    
    
    return 0;
}
