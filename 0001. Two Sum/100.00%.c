int compare_int( const void* a, const void* b )
{
    if( *(int*)a == *(int*)b ) return 0;
    return *(int*)a < *(int*)b ? -1 : 1;
}

int* twoSum(int* nums, int numsSize, int target) {
        
    int* newArray = malloc(sizeof(int) * numsSize);
    
    for (int i = 0; i < numsSize; i++)
        newArray[i] = nums[i];
    
    qsort(nums, numsSize, sizeof(int), compare_int);
    
    int startIndex = 0;
    int endIndex = numsSize - 1;
    int* result;
    
    while (startIndex < numsSize)
    {
        if (nums[startIndex] + nums[endIndex] != target)
        {
            if (target > nums[startIndex] + nums[endIndex])
                startIndex++;
            else
                endIndex--;
        }
        else
        {
            result = malloc(sizeof(int) * 2);
            result[0] = nums[startIndex];
            result[1] = nums[endIndex];
            break;
        }
    }
    int Index1;
    int Index2;
    for (int i = 0; i < numsSize; i++)
    {
        if (newArray[i] == result[0])
        {
            Index1 = i;
            break;
        }
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (newArray[i] == result[1])
            Index2 = i;
    }
    int* aresult = malloc(sizeof(int) * 2);
    aresult[0] = Index1;
    aresult[1] = Index2;
    return aresult;
}