var twoSum = function(nums, target) {
    var map = {};
    for(var i = 0 ; i < nums.length ; i++){
        var j = nums[i];

        if(map[target-j] >= 0){
            return [map[target-j],i]
        } else {
            map[j] = i;
        }
    }
};