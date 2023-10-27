#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int square[3][3] = {0};

int randomNumGenerator(){
    int num = (rand() % 9) + 1;
    return num;
}

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

int numberNotFound(int randomNum, int *number){
    for(int i=0; i<9; i++){
        if(randomNum == number[i]) return 0;
    }
    return 1;
}

void generateSquare(){
    int numbers[9]={0};
    int count = 0;
    srand(time(0));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int randomNum = randomNumGenerator();
            while(numberNotFound(randomNum, numbers) != 1){
                randomNum = randomNumGenerator();
            }
            numbers[count]=randomNum;
            square[i][j] = randomNum;
            count ++;
        }
    }
}

int main(){
    int found = 0;
    int count = 0;
    
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
        count++;
        printf("Attempts: %d\n", count);
        generateSquare();
        if(isMagic(square)==1) 
            found = 1;
    }
    printf("Magic square found!\n");
    printGrid(square);
}