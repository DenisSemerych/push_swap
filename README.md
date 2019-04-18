# push_swap
42 algorithmic project
Purpose of this project is to create two different programs: checker and push_swap.
Checker needs to take int values as arguments and than waits for list of instruction from standart input. 
Push_swap needs to take int values as arguments and than generates list of instruction to standart output.


usage: console_name% $ARG=4 2 3 15 12 51 8 ./push_swap $ARG | ./checker $ARG.

Speed - fast.
Sorting - excelent on 500, 100 - not so good, but on average fewer than 700 instructions.
Used algo: Quick Sort modification. 


About algo:
My aproach to this problem I used quicksort as was mentioned above.
There is two main functions that sorts arrays - first one is sorting stack_a by dividing it to point, where only 3 elements or less left in stack. Than it sorts stack_a by calling special sorting function in assending order.
Second one sorts stack_b in descending order by (if it need to) divading stack and send some elements in stack_a. When it is less than 30 elements (number is not optimal - better to use 10-8 elements) and if it all elements, than left in stack algo uses kind of insertion sort, and if it is 3 elements or less - using special function to sort three elements.
This function is made in recursion:
1) quick_sort_a is working till 3 or less elements in stack and sorts 3 elements in the right order
2) quick_sort_b start working with last group of elements that was send to stack_b from quicksort_a
3) quick_sort_a is working with sorting elements (if they needs to be sorted)
4) steps 2 and 3 repeating.
Than program peforming some optimization to list of instructions.

Choosing Pivot: 
In case of working in program and to sort in smaller set of instruction - works fine, but if purpose to sort stacks - that is bad.
I choose pivot by translating stack(aka linked list) of instructions to array and sort it by insertion sort (array version) and picking up middle element of the array.

Validation in checker:
My aproach in using array of function pointers and validating instructions after writting them in linked list to avoid unnecessary array sorting.
