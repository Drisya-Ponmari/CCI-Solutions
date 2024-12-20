
# Max Heap 

Complete binary tree where each node is greate than(or equal) it's children.(Max heap property)

## Time complexities 
o(1) to get the max element 
o(log n) to extract max element 
o(nlogn) heap sort 

## Height 
Number of edges to reach the longest leaf. 
If n is the number of nodes and h is the height 
$${2^h <= n <= 2^(h+1) -1>>}$$

## Implementation 
Max heap can be implemented with array. 
parent = i 
left child = 2i
right child  =2i + 1
if child in j, parent = low_floor(j/2)

