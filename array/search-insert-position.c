#include "stdio.h"

// 暴力循环
int searchInsert(int* nums, int numsSize, int target) {
	for (int i = 0; i < numsSize; i++) 
		if (nums[i] >= target) return i;
	return numsSize;
}

// 二分搜索
int searchInsert1(int* nums, int numsSize, int target) {
	int low = 0, high = numsSize - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (target < nums[mid]) high = mid - 1;
		else if (target > nums[mid]) low = mid + 1;
		else return mid;
	}
	return low;
}

void main()
{
    int arr[] = { 1,3,5,6 };
	printf("%d \r\n", searchInsert(arr, sizeof(arr)/sizeof(int), 0));
}