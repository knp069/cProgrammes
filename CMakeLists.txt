cmake_minimum_required(VERSION 3.8)
project(cProgrammes)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        backtracking/nQueen.cpp
        backtracking/sudokuchecker.cpp
        "Binary Search Tree/adding-node-in -a-binary-search-tree.c"
        "Binary Search Tree/deleting-a-node-in-a-binary-search-tree.c"
        "binary Tree/countLeaf.c"
        "binary Tree/deleteBinaryTree.c"
        "binary Tree/diameter.c"
        "binary Tree/elementAtDistanceK.c"
        "binary Tree/heightBalance.c"
        "binary Tree/identicalTree.c"
        "binary Tree/largest-path-sum-between-leaves.c"
        "binary Tree/LeafAtSameLevel.c"
        "binary Tree/levelOrderTraversal.c"
        "binary Tree/mirrorTree.c"
        "binary Tree/morric.c"
        "binary Tree/remove-Node-With-Less-Sum.c"
        "binary Tree/rootLeafpath.c"
        "binary Tree/spiralLevelOrderTraversal.c"
        "binary Tree/treeWidth.c"
        "General Algo/counting-number-of-inversions.c"
        "General Algo/factorial.c"
        "General Algo/fibbonaci.c"
        "General Algo/primeNumber.c"
        graphs/bfs.c
        graphs/dfs.c
        "Linked List/adding-node-to-end-of-a-linked-list.c"
        "Linked List/adding-node-to-start-of-a-linked-list.c"
        "Linked List/queue.c"
        "Linked List/removing-node-from-end-of-linked-list.c"
        "Linked List/removing-node-from-start-of-a-linked-list.c"
        "Linked List/reversal-of-linked-list.c"
        "Linked List/stack-using-queue.c"
        "Linked List/stack.c"
        "Linked List/string-comparison-represented-as-linked-list.c"
        sorting/bubblesort.c
        sorting/countsort.cpp
        sorting/insertionSort.c
        Strings/palincrome.c
        Strings/reverse-string.c
        Strings/string-comparision.c
        Strings/string-concatenation.c
        Strings/string-copy.c
        Strings/string-Length.c
        Strings/substring-comparision.c sorting/mergeSort.c)

add_executable(cProgrammes ${SOURCE_FILES})