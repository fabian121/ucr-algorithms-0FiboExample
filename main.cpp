/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on January 7, 2014, 2:15 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <sys/time.h>

using namespace std;
long int fibonacci(long int number);
long int fibonacciRecursive(long int number);
/*  
 * 
 */
int main(int argc, char** argv) {
    
    long int number = 40, result = 0, resultRecur;
    double elapsedTime, elapsedTimeRecur;
    
    /****************************************/
    timeval initTime, finishTime, initTimeRecur, finishTimeRecur;
    gettimeofday(&initTime, NULL);
    result = fibonacci(number);
    gettimeofday(&finishTime, NULL);
    
    gettimeofday(&initTimeRecur, NULL);
    resultRecur = fibonacciRecursive(number);
    gettimeofday(&finishTimeRecur, NULL);
    
    elapsedTime = (finishTime.tv_sec - initTime.tv_sec) * 1000.0;
    elapsedTime += (finishTime.tv_usec - initTime.tv_usec) / 1000.0;
    
    elapsedTimeRecur = (finishTimeRecur.tv_sec - initTimeRecur.tv_sec) * 1000.0;
    elapsedTimeRecur += (finishTimeRecur.tv_usec - initTimeRecur.tv_usec) / 1000.0;
    
    printf("Fibonacci(%ld): %ld\n",number, result);
    printf("Algorithm's duration: %lf ms\n", elapsedTime);
    printf("Algorithm's duration(Recursive): %lf ms\n\n", elapsedTimeRecur);

    return 0;
}


/*calculates fibonacci number*/
long int fibonacci(long int number){
    //variables
    long int accumulator = 1, add = 0, previousNumber = 0;
    
    for(int k = 1; k <= number; k++ ){
        add = previousNumber + accumulator;
        previousNumber = accumulator;
        accumulator = add;
    }
    
    return accumulator;
}


/*fibonacci's implementation but recursively*/
long int fibonacciRecursive(long int number){
    if(number < 2){
        return number;
    }else{
        return fibonacciRecursive(number - 1) + fibonacciRecursive(number - 2);
    }
}