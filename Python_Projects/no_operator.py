#this is the code is for shaparak problem _ no operator(quera question)!
#I used operator moudule to improve my code and learn more here is the link to keep up:
#https://realpython.com/python-operator-module/#faqs

import operator
import time
import tracemalloc

def max_in_shaparak(expr):
    #Parse the input
    numbers =  list(map(int , expr.split("?")))

    results = []
    
    #Generate all possible combinations:
    # Define possible operator pairs
    op_pairs = [
        (operator.add, operator.add),
        (operator.add, operator.mul),
        (operator.mul, operator.add),
        (operator.mul, operator.mul)
    ]

    # Try both (a op1 b) op2 c and a op1 (b op2 c)
    for op1, op2 in op_pairs:
        results.append(op2(op1(numbers[0], numbers[1]), numbers[2]))  # (a op1 b) op2 c
        results.append(op1(numbers[0], op2(numbers[1], numbers[2])))  # a op1 (b op2 c)

    #Track the max
    return max(results)

# Performance measurement (optional)
if __name__ == "__main__":
    #get the expration
    expr = input("Type your expression (like 14?100?1): ").strip()

    #to track time and memory
    tracemalloc.start()
    start = time.time()

    result = max_in_shaparak(expr)
    print("Max value that was calculated:", result)

    end = time.time()
    current, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()

    print(f"\nExecution time: {end - start:.6f} seconds")
    print(f"Peak memory usage: {peak / 1024 / 1024:.4f} MB")
