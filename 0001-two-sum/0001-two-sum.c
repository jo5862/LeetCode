/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
     int*map = (int*)malloc(numsSize*2*sizeof(int));
     *returnSize = 2; //항상 두 인덱스를 반환하므로 크기는 2

    for (int i=0;i<numsSize*2;i++){
        map[i]=-1;
    }

    for(int j =0 ; j<numsSize; j++){
        int complement = target - nums[j];

        for(int k=0;k<j;k++){
            if(nums[k]==complement){
                int*result = (int*)malloc(2*sizeof(int));
                result[0] = k;  //보수의 인덱스
                result[1]=j;    //현재 인덱스
                return result;
            }
        }
    }
    return NULL;
}