/****************************************************************

 <br>
 <br> Subject:            Calculation of Even Divisibility of Numbers
 <br> Project:            Assignment003
 <br> Author:             Justin H. Krum
 <br> Creation Date:      October 10, 2017
 <br> Last Modification:  October 12, 2017

 ****************************************************************/

/****************************************************************
 VAR NAME           TYPE        PURPOSE

 max                int         To set the max value for the loop creating dashes in setFormat
 inValue            int         To provide the dividend for calculating in modBy2, modBy3, modBy5, and modBy7
 inValues           int[][]     To hold all inputted values from the user and track if they are evenly divisible by 2,3,5, and 7
 divisibleBy2       int         To act as a counter for how many numbers are evenly divisible by 2
 divisibleBy3       int         To act as a counter for how many numbers are evenly divisible by 3
 divisibleBy5       int         To act as a counter for how many numbers are evenly divisible by 5
 divisibleBy7       int         To act as a counter for how many numbers are evenly divisible by 7

 FUNCTION NAME      ARGUMENTS               RETURN TYPE     PURPOSE
 setFormat          int                     void            To output a set number of dashes according to int
 modBy2             int                     int             To calculate if a number is evenly divisible by 2
 modBy3             int                     int             To calculate if a number is evenly divisible by 3
 modBy5             int                     int             To calculate if a number is evenly divisible by 5
 modBy7             int                     int             To calculate if a number is evenly divisible by 7
 main                                       int             To execute the main body of the program

 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>

void setFormat(int max){

    //Simply outputs however many dashes the user specifies with max

    printf("\n");
    for(int a = 0; a < max; a++){
        printf("-");
    }
}

int modBy2(int inValue){

    //Modulus of 2 will determine even or odd, odd is returning false


    //Use of int in place of a boolean --> 1=true   0=false
    if(inValue % 2 == 0) return 1;
    else if(inValue % 2 == 1) return 0;
}

int modBy3(int inValue){

    //Modulus of 3 will equal 0 if it is divisible, otherwise it will be >= 1


    //Use of int in place of a boolean --> 1=true   0=false
    if(inValue % 3 == 0) return 1;
    else if(inValue % 3 >= 1) return 0;
}

int modBy5(int inValue){

    //Modulus of 5 will equal 0 if it is divisible, otherwise is will be >= 1


    //Use of int in place of a boolean --> 1=true   0=false
    if(inValue % 5 == 0) return 1;
    else if(inValue % 5 >= 1) return 0;
}



int modBy7(int inValue){

    //Modulus of 5 will equal 0 if it is divisible, otherwise is will be >= 1


    //Use of int in place of a boolean --> 1=true   0=false
    if(inValue % 7 == 0) return 1;
    else if(inValue % 7 >= 1) return 0;
}


void main(){

    //Declaration of 2D array to hold the true and false conditions and all input values for the user
    int inValues[5][5];

    for(int a = 0; a < 5; a++){

        if(a > 0) printf("\n");

        //Input of values for the user to test
        printf("Enter in value #%d: ", (a+1));
        scanf("%d", &inValues[a][0]);
    }


    //Simply sets the format of the output for the user

    setFormat(35);
    printf("\n\nNumber\tDivisible By");
    printf("\n\t2\t3\t5\t7\n");
    setFormat(35);
    printf("\n");


    //Counters to tally the totals for how many numbers inputted are evenly divisible by 2, 3, 5, and 7 respectively
    int divisibleBy2 = 0,
        divisibleBy3 = 0,
        divisibleBy5 = 0,
        divisibleBy7 = 0;

    //Compares the values input by the user to their modularity to 2,3,5, and 7

    for(int x = 0; x < 5; x++){
        for(int y = 1; y < 5; y++){

            //Scans through the entire 2D array to check their modularity to a 2,3,5, and 7
            //by row and stores binary data based on the output

            //Checks against modulus 2
            if(y == 1){
                inValues[x][y] = modBy2(inValues[x][0]);

                //Increase counter if the case is true(1)
                if(inValues[x][y] == 1) divisibleBy2++;
            }

            //Checks against modulus 3
            else if(y == 2){
                inValues[x][y] = modBy3(inValues[x][0]);

                //Increase counter if the case is true(1)
                if(inValues[x][y] == 1) divisibleBy3++;
            }

            //Checks against modulus 5
            else if(y == 3){
                inValues[x][y] = modBy5(inValues[x][0]);

                //Increase counter if the case is true(1)
                if(inValues[x][y] == 1) divisibleBy5++;
            }

            //Checks against modulus 7
            else if(y == 4){
                inValues[x][y] = modBy7(inValues[x][0]);

                //Increase counter if the case is true(1)
                if(inValues[x][y] == 1) divisibleBy7++;
            }
        }
    }




    //Outputs the values and the divisibility status to the user
    for(int x = 0; x < 5; x++){

        //Outputs the value that the user input
        printf("\n%d", inValues[x][0]);

        //Checks boolean status of if values input by the user are divisible
        for(int y = 1; y < 5; y++){

            //value input by user is not divisible evenly
            if(inValues[x][y] == 0){
                printf("\t%s", " ");
            }

            //value input by user is divisible evenly
            else if(inValues[x][y] >= 1){
                printf("\t%s", "X");
            }
        }
        printf("\n");
    }


    setFormat(35);


    //Displays total values to the user
    printf("\n\nTotal\t%d\t%d\t%d\t%d", divisibleBy2, divisibleBy3, divisibleBy5, divisibleBy7);

}
