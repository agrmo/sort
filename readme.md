# sort

Sort algorithms.

## quicksort

Serial quicksort in C++.

```
Call [0, -1, 2, -3, 1]
Pivot 1 value -1
Left size 1, right size 4
Pour left [-3]
Pour right [0, -1, 2, 1]
Call [-3]
Call [0, -1, 2, 1]
Pivot 3 value 1
Left size 2, right size 2
Pour left [0, -1]
Pour right [2, 1]
Call [0, -1]
Size two, return [-1, 0]
Call [2, 1]
Size two, return [1, 2]
Combine left [-1, 0]
Combine right [1, 2]
Combined [-1, 0, 1, 2]
Combine left [-3]
Combine right [-1, 0, 1, 2]
Combined [-3, -1, 0, 1, 2]
```
