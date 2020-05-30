# Leetcode-
LeetCode题解
文件名为题号和函数名

本人使用python和C++
# 42. 最大连续子数组的和
sum[i..j] = sum[j] - sum[i]

以j为最后元素的最大连续子数组和为：max{sum[...j]} = sum[j] - min{sum[0]...sum[j-1]


