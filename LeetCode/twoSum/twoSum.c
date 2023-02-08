int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int i,j;
    int *tab=malloc(2*sizeof(int));
    tab[0]=1;
    tab[1]=1;
    for (i=0;i < numsSize;i++)
    {
        for(j=i+1;j< numsSize;j++)
        {
            if(nums[i] + nums[j] == target)
            {
                *returnSize=2;
                tab[0]=i;
                tab[1]=j;
                return tab;
            }       
        }
    }   
    *returnSize=0;
    return tab;
}
