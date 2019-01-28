double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
        
	int *mixArr = (int*)malloc(sizeof(int)*(nums1Size + nums2Size));
	if (mixArr == NULL){
        return -1;
    }
    
	int i = 0;
    int j = 0;
    int k = 0;
	double ans = 0;
    
	while (i < nums1Size || j < nums2Size) {
        if (i < nums1Size && j == nums2Size){
            mixArr[k] = nums1[i];
            i++;
        } else if (i == nums1Size && j < nums2Size){
            mixArr[k] = nums2[j];
            j++;
        } else if (nums1[i] < nums2[j]){
            mixArr[k] = nums1[i];
            i++;
        } else {
            mixArr[k] = nums2[j];            
            j++;
        }
        k++;
	}
    
	if ((nums1Size + nums2Size) % 2 == 1) {
		ans = mixArr[((nums1Size + nums2Size - 1) / 2)];
	} else {
		ans = ((mixArr[((nums1Size + nums2Size) / 2) - 1] + mixArr[(nums1Size + nums2Size) / 2]) / 2.0);		
	}
    free(mixArr);
	return ans;
}