/*
* File: coworkingcenter.c
* Author: EUGENIO MOYA
* Course: 20211
* Description: PEC8_20211
*/

#include <stdio.h>
#include "coworkingcenter.h"

int main(int argc, char **argv)
{
	tCoworkingCentersTable centersTable;
	tCoworkingCentersTable centersTableSelection;
	char filename[MAX_NAME];	
	bool isRead = false;
    char optimalCity[MAX_CITY];
    float optimalPrice;
    float optimalDistance;
	float minumumPoints;
	int i;
	float centersAverage;

	
	/* Exercise 2.4 */
	/* centerTable initialization */
    centersTableInitialize(&centersTable);
  

	 /* load data from file */ 
    printf("LOAD DATA FROM FILE. ENTER FILE NAME >>\n");
    scanf("%s", filename);    
	centersTableLoadDataFromFile(&centersTable,filename,&isRead);
	
	if (isRead) {	
		printf("CENTER TABLE SUCCESSFULLY LOADED\n");	
    /* Data input */	
		printf("CITY NAME (A STRING)? >>\n");
		scanf("%s",optimalCity);
		printf("OPTIMAL DISTANCE [KM]? >>\n");
		scanf("%f",&optimalDistance);
		printf("OPTIMAL PRICE [EUR]? >>\n");
		scanf("%f",&optimalPrice);
		printf("NEEDED POINTS (A REAL)? >>\n");
		scanf("%f",&minumumPoints);
		
	/*Data processing */
	centersAverage = centersAverageOccupation(centersTable,optimalCity);
	centersTableSelect(centersTable,optimalCity,optimalDistance,optimalPrice,minumumPoints,&centersTableSelection);	
		
	/* Exercise 2.5 */
	printf("RESULTS\n");
		if (centersTableSelection.numCenters > ZERO){
			printf("CENTERS FOUND:%d\n",centersTableSelection.numCenters);
			printf("SELECTED CENTERS:\n");
			for (i=FIRST;i<centersTableSelection.numCenters;i++) {
				writeCenter(centersTableSelection.centers[i]);			
			}			
		}else{
			printf("NO AVAILABLE CENTERS WITH THIS CRITERION\n");
		}			
	printf("MEAN PERCENTAGE OCCUPATION FOR THE CITY OF %s IS %.2f\n",optimalCity,centersAverage);

	}
	
	return 0;	
}
