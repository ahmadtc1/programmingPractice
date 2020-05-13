def largestProductofThreeNums(nums):
	nums.sort()
	lastIndex = len(nums) - 1
	if ((nums[0] * nums[1]) >= (nums[lastIndex] * nums[lastIndex - 1])):
		return nums[0] * nums[1] * nums[lastIndex]

	else:
		return nums[lastIndex] * nums[lastIndex - 1] * nums[lastIndex - 2]



list = [-4, -4, 2, 8]
print(largestProductofThreeNums(list))


