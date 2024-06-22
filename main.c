/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary spac

example
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
 */

#include <stdio.h>
#include <stdlib.h>

void get_small(int* small, int nums[], int size){
    *small = nums[0];
    for(int i = 1; i < size; i++){
	if(nums[i] < *small){
	    *small = nums[i];
	}
    }
}

void get_missing(int nums[], int size, int* missing){
    for(int i = 0; i < size; i++){
	for(int j = 0; j < size; j++){
	    if(nums[j] == *missing){
		*missing = *missing + 1;
	    }
	}
    }
}

int main(){
    int nums[] = {1, 2, 0};
    int size = sizeof(nums)/sizeof(nums[0]);
    int small;
    int missing;
    
    get_small(&small, nums, size);
    missing = small;

    get_missing(nums, size, &missing);
    printf("missing number: %d", missing);

    return 0;
}
