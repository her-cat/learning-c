#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * destCity(char *** paths, int pathsSize, int* pathsColSize){
    char * startCities[pathsSize];

    for (int i = 0; i < pathsSize; i++)  {
        startCities[i] = paths[i][0];
    }
    
    for (int i = 0; i < pathsSize; i++) {
        int inStartCities = 0;
        for (int j = 0; j < pathsSize; j++) {
            if (strcmp(paths[i][1], startCities[j]) == 0) {
                inStartCities = 1;
                break;
            }
        }

        if (inStartCities == 0) return paths[i][1];
    }

    return paths[0][1];
}

void main()
{
    // [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
    char *** paths = malloc(sizeof(paths));

    char * temp1[] = {"London","New York"};
    char * temp2[] = {"New York","Lima"};
    char * temp3[] = {"Lima","Sao Paulo"};

    paths[0] = temp1;
    paths[1] = temp2;
    paths[2] = temp3;
    

    int size = 2;

    printf("%s \r\n", destCity(paths, 3, &size));
}
