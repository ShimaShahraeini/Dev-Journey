'''
https://quera.org/problemset/251440?tab=description -> what if the input numbers where more?
extending my current solution to handle inputs like: a?b?c?d?e?...
I should replace ? with either + or *, insert parentheses in all valid ways, and then find the maximum value from all combinations.
I had problem with this, so i split this problem and first code 2 leetcode problem relate to this one to figure out the code.
check out 'add_parentheses.py' and 'add_operators.py'.

this code still use brute force, For n numbers:
    Operator combinations = 2^(n-1)
    Parenthesis combinations = Catalan(n-1)
    Total complexity = O(2^(n-1) * Catalan(n-1)) → super-exponential

check out Dynamic Programming (DP) solution for this in 'no_operator_unlimited_dp.py'!
'''
import operator

operators = {
    "+": operator.add,
    "-": operator.sub,
    "*": operator.mul,
    }

def main():
    #get the expration
    expr = input("Type your expression (like 14?100?1): ").strip()

    result = max_in_shaparak(expr)
    print("Max value that was calculated:", result)

def max_in_shaparak(expr):
    results = []

    #Parse the input
    numbers =  list(map(int , expr.split("?")))

    #List all operator combos
    op_combination = []
    first = numbers[0]
    add_operators(numbers, 1, str(first), op_combination)
    
    #For each combo: List all parenthesis placements and Evaluate manually
    for exp in op_combination:
        results.extend(add_parentheses(exp))

    #Track the max
    return max(results)

def add_operators(numbers, index, valid_expr, result):
    """
    Recursive function to try all combinations of +, * between numbers
    and track valid expressions and return them.
    """
    if index == len(numbers):    
        result.append(valid_expr)
        return result

    current_num = numbers[index]

    # Handle '+'
    add_operators(numbers, index + 1, valid_expr + '+' + str(current_num), result)

    # Handle '*'
    add_operators(numbers, index + 1, valid_expr + '*' + str(current_num), result)


def add_parentheses(expr, memory = None):
    if memory is None:
        memory = {}
    
    if expr in memory:
        return memory[expr]

    results = []

    for i, char in enumerate(expr):
        if char in '+*':
            left = add_parentheses(expr[:i], memory)
            right = add_parentheses(expr[i+1:], memory)

            for l in left:
                for r in right:
                    results.append(apply_operator(l, r, char))
    
    # If no operator was found, this is a number (base case) / 
    #If you looped over the whole expression and never hit an operator, and result still empty you're at base
    if not results:
        results.append(int(expr))

    memory[expr] = results

    return results

def apply_operator(num1, num2, op_string):
    return operators[op_string](num1, num2)

# Performance measurement (optional)
if __name__ == "__main__":
    main()
