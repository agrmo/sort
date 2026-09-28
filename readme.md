# sort

Sort algorithms.

## quicksort-cpp

Serial recursive quicksort in C++. 

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

It is also important to handle recursion into a sublist of identical values.

```
Call [-1, -1, -1, -1, -1, 4, 5, 0]
Pivot 7 value 0
Left size 5, right size 3
Pour left [-1, -1, -1, -1, -1]
Pour right [4, 5, 0]
Call [-1, -1, -1, -1, -1]
Call [4, 5, 0]
Pivot 1 value 5
Left size 2, right size 1
Pour left [4, 0]
Pour right [5]
Call [4, 0]
Size two, return [0, 4]
Call [5]
Combine left [0, 4]
Combine right [5]
Combined [0, 4, 5]
Combine left [-1, -1, -1, -1, -1]
Combine right [0, 4, 5]
Combined [-1, -1, -1, -1, -1, 0, 4, 5]
```

## quicksort-py

Serial recursive quicksort in Python.

## heapsort

A proper implementation of heapsort using a min-heap. Runs in `2*n*log(n) = O(nlogn)` time, `nlogn` for the upheaping, `nlogn` for the downheaping. e.g.

```
[9, 5, 1, -1, 51, 521, 19, 2, 6, 111]
```

returns

```
[-1, 1, 2, 5, 6, 9, 19, 51, 111, 521]
```
