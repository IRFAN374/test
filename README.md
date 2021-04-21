# test

**Time Complexity Analysis**

*the isSafe method takes O(n) time
*for each invocation of loop in soldier_pos, it runs for O(n) time
*the isSafe condition is present in the loop and also calls soldier_pos which is recursive
*adding this up, the recurrence relation is:

T(n) = O(n^2) + n * T(n-1)

solving the above recurrence by iteration or recursion tree,
the time complexity of the above problem is = O(N!)
