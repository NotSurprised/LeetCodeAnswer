int* twoSum(int* nums, int numsSize, int target) {
    int *ans;
    ans = (int*)malloc(2*sizeof(int));
    bool stop = false;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                ans[0] = i;  
                ans[1] = j; 
                stop = true;
                break;
            }
        }
        if (stop == true)
            break;
    }  
    return ans; 
    free(ans);
}