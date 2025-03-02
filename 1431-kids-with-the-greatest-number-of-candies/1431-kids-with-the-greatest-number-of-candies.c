/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    
    int maxcandies = candies[0];
    for(int i=1;i<candiesSize;i++){
        if(candies[i]>maxcandies){
            maxcandies=candies[i];
        }
    }
    bool* result =  (bool*)malloc(candiesSize* sizeof (bool));

    for(int j=0;j<candiesSize;j++)
    {
        if(candies[j]+extraCandies>=maxcandies)
        {
            result[j]=true;
        }
        else{
            result[j]=false;
        }
    }

    *returnSize = candiesSize;
    return result;
}