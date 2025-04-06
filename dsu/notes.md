**Disjoint Set Union**

A DSU will have an operation to combine any two sets, and it will be able to tell in which set a specific element is.

*Operations*
- make_set(v) - Creates a new set consisting of new element v
- union_sets(a,b) - merges the two specified sets (the set in which the element a is located, and the set in which the element b is located)
- find_set(v) - returns the 'header' of the set that contains element v. 

Average time complexity of operation is o(1). 
Added implementation for the above operations using a parent array, adding path compression, Union using size & rank 

*Applications*

Connected components in graph 



