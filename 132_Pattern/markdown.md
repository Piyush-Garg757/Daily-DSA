## DSA Question: 132 Pattern Detection

## Problem
Given an array of `n` integers `nums`, a **132 pattern** is a subsequence of three integers `nums[i]`, `nums[j]`, and `nums[k]` such that `i < j < k` and `nums[i] < nums[k] < nums[j]`.

Return `true` if there is a 132 pattern in `nums`, otherwise, return `false`.

## Examples:

**Input:** `nums = [1, 2, 3, 4]`
**Output:** `false`
**Explanation:** There is no subsequence that satisfies the 132 pattern.

**Input:** `nums = [3, 1, 4, 2]`
**Output:** `true`
**Explanation:** The subsequence `[1, 4, 2]` is a 132 pattern, where `i=1, j=2, k=3` and `nums[1] < nums[3] < nums[2]` (i.e., `1 < 2 < 4`).

**Input:** `nums = [-1, 3, 2, 0]`
**Output:** `true`
**Explanation:** There are three 132 patterns: `[-1, 3, 2]`, `[-1, 3, 0]`, and `[-1, 2, 0]`.

## Approach
A highly efficient approach uses a **monotonic stack** and a single pass from right to left. We need to find `nums[i] < nums[k] < nums[j]`.

1.  Iterate through the `nums` array from right to left. The current number will be our candidate for `nums[i]`.
2.  Maintain a second number, `s3` (representing `nums[k]`), which will store the largest possible value for the third element of the pattern. Initialize it to negative infinity.
3.  Use a stack to store potential candidates for `nums[j]` (the largest element). The stack will be maintained in decreasing order.
4.  For each number `num` from the right:
    * If `num < s3`, we have found our `nums[i] < nums[k]`. Since `s3` was derived from a `nums[j]` that appeared to its right (and thus at a greater index), we have successfully found `nums[i] < nums[k] < nums[j]`. Return `true`.
    * Otherwise, check the stack. While the stack is not empty and `num` is greater than the element at the top of the stack, it means we have found a better candidate for `nums[j]` (`num`). The element at the top of the stack can now become our best candidate for `s3`. So, we update `s3 = stack.pop()` and repeat.
    * Push the current `num` onto the stack. It is now a candidate for `nums[j]`.
5.  If the loop completes, no 132 pattern was found. Return `false`.

## Complexities
> **Time Complexity**
**O(n)** — We iterate through the input array once. Each element is pushed and popped from the stack at most one time.

> **Space Complexity**
**O(n)** — In the worst-case scenario (a strictly decreasing array), the stack could hold all `n` elements.