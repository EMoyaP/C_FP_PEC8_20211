/*
* File: coworkingcenter.c
* Author: EUGENIO MOYA
* Course: 20211
* Description: PEC8_20211
*/

#include <stdio.h>
#include <stdbool.h>

#define CATEGORY1 1					/* Category 1 id */
#define CATEGORY2 2                 /* Category 2 id */
#define CATEGORY3 3                 /* Category 3 id */

#define MAX_CENTERS 100
#define MAX_NAME 15+1
#define MAX_CITY 15+1

#define MAX_LINE 514

#define FACILITIES_POINTS 5.0  /* Point for facilities */
#define OPTIMAL_WORKSPACES 3   /* Optimal amount of workspaces */

#define ZERO 0
#define ONE 1
#define FIRST 0
#define HUNDRED 100


typedef enum {STARTUPS=1, FREELANCERS, RURAL, SPECIALIZED, GENERALIST} tCoworkingType;

typedef struct {
    char name[MAX_NAME];
	char city[MAX_CITY];
    int category;
    tCoworkingType centerType;
	int numSpaces;
    float price; 
    float distanceFromCityCenter;
    bool hasMeetingRooms;
    bool hasAuditorium;
	float percentOccupation;
} tCoworkingCenter;

typedef struct { 
	tCoworkingCenter centers[MAX_CENTERS];
	int numCenters;
}tCoworkingCentersTable;

//headers
void writeCenter(tCoworkingCenter center);
void copyCenter (tCoworkingCenter centerSrc, tCoworkingCenter *centerDst);
float pointsCenter (tCoworkingCenter center, float price, float distance);

void getCenterObject(const char *str, tCoworkingCenter *center);
void centersTableAddElement(tCoworkingCentersTable *centersTable, tCoworkingCenter center);
void centersTableLoadDataFromFile(tCoworkingCentersTable *centersTable, const char* filename, bool *isRead);

/* new function */
/* Exercise 2.1 */
void centersTableInitialize (tCoworkingCentersTable *centersTable);

/* Exercise 2.2 */
void centersTableSelect (tCoworkingCentersTable centersTable, char *optimalCity, float optimalDistance, float optimalPrice, float minumumPoints, tCoworkingCentersTable *centersTableSelection);

/* Exercise 2.3 */
float centersAverageOccupation(tCoworkingCentersTable centersTable, char *optimalCity);