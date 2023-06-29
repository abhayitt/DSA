#include <stdio.h>
#include <string.h>

#define CITY_SIZE 20
#define SUBURBS 2
#define TOWNS 2
#define CORPORATIONS 2

typedef struct {
    char city[CITY_SIZE];
    char suburbs[SUBURBS][CITY_SIZE];
    char towns[SUBURBS][TOWNS][CITY_SIZE];
    char corporations[SUBURBS][TOWNS][CORPORATIONS][CITY_SIZE];
} CityData;


void commonDetail(CityData cityData, const char* corporation1, const char* corporation2) {
    char city_common[20] = "";
    char suburb_common[20] = "";
    char town_common[20] = "";

    strcpy(city_common, cityData.city);
    
    for (int i = 0; i < SUBURBS; i++) {
        for (int j = 0; j < TOWNS; j++) {
            for (int k = 0; k < CORPORATIONS - 1; k++) {
                if ((strcmp(cityData.corporations[i][j][k], corporation1) == 0 && strcmp(cityData.corporations[i][j][k + 1], corporation2) == 0) ||
                    (strcmp(cityData.corporations[i][j][k], corporation2) == 0 && strcmp(cityData.corporations[i][j][k + 1], corporation1) == 0)) {
                    strcpy(suburb_common, cityData.suburbs[i]);
                    strcpy(town_common, cityData.towns[i][j]);
                    break;
                }
            }
        }
    }
    
    
    

    if (strlen(town_common) > 0) {
        printf("%s, ", town_common);
    }
    if (strlen(suburb_common) > 0) {
        printf("%s, ", suburb_common);
    }
    printf("%s\n", city_common);
}


int main() {
    CityData cityData;

    printf("Enter the city: ");
    scanf("%[^\n]%*c", cityData.city);

    for (int i = 0; i < SUBURBS; i++) {
        printf("Enter the suburb %d: ", i + 1);
        scanf("%[^\n]%*c", cityData.suburbs[i]);

        for (int j = 0; j < TOWNS; j++) {
            printf("Enter the town %d in %s: ", j + 1, cityData.suburbs[i]);
            scanf("%[^\n]%*c", cityData.towns[i][j]);

            for (int k = 0; k < CORPORATIONS; k++) {
                printf("Enter the corporation %d in %s: ", k + 1, cityData.towns[i][j]);
                scanf("%[^\n]%*c", cityData.corporations[i][j][k]);
            }
        }
    }

    printf("\n");
    //Input corporations value
    char corperation1[10];
    char corperation2[10];

    printf("Enter the code for corporation 1: ");
    scanf("%s", corperation1);

    printf("Enter the code for corporation 2: ");
    scanf("%s", corperation2);

    commonDetail(cityData, corperation1, corperation2);

    return 0;
}


