#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int square[3][3] = {0};

int isMagic(int square[3][3]){
    int sum;
    //check rows
    for(int i=0 ; i<3; i++){
        sum = 0;
        for(int j=0; j<3; j++){
            sum += square[i][j];
        }
        if(sum != 15)  return 0;
    }
    //check columns
    for(int i=0 ; i<3; i++){
        sum = 0;
        for(int j=0; j<3; j++){
            sum += square[j][i];
        }
        if(sum != 15)  return 0;
    }
    //check diagonaly
    if((square[0][0]+square[1][1]+square[2][2])!=15) return 0;
    if((square[0][2]+square[1][1]+square[2][0])!=15) return 0;
    //all equal 15
    return 1;
}

void printGrid(int square[3][3]){
    for(int i=0; i<3; i++){
        printf("[ ");
        for(int j=0; j<3; j++){
            printf("%d ", square[i][j]);
        }
        printf("]\n");
    }
}

void mixUpNumbers(int num[9]){
    for(int i = 0; i<9;i++){
        int randomNum=(rand() % 9)+1;
        int temp = num[i];
        num[i] = num[randomNum];
        num[randomNum]=temp;
    }
}

void generateSquare(){
    int num[9]= {1, 2, 3, 4, 5, 6, 7, 8, 9};
    mixUpNumbers(num);
    int count = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            square[i][j] = num[count];
            count ++;
        }
    }
}

int main(){
    int found = 0;
    int count = 0;
    srand(time(NULL));
    //Uncomment to test if the square is magic
    // int loShu [3][3] = {
    //     {4, 9, 2},
    //     {3, 5, 7},
    //     {8, 1, 6}
    //     };
    // if(isMagic(loShu)==1)
    //     printf("Magic square found!\n");
    // else
    //     printf("Magic square NOT found.\n");
    // printGrid(loShu);

    //uncomment to generate a random square
    // generateSquare();
    // if(isMagic(square)==1)
    //     printf("Magic square found!\n");
    // else
    //     printf("Magic square NOT found.\n");
    // printGrid(square);

    //randomly generate until magic square is found
    //comment from while to printGrid if you'd like to test other functions
    while(found != 1){
        generateSquare();
        count++;
        //printf("Attempts: %d\n", count);
        if(isMagic(square)==1) 
            found = 1;
    }
    printf("Attempts: %d\n", count);
    printf("Magic square found!\n");
    printGrid(square);
}