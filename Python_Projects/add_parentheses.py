#splving problem 241 from leetcode: https://leetcode.com/problems/different-ways-to-add-parentheses/description/
#the approach I used is Recursion and Divide & Conquer this code also use Memoization.

import operator

operators = {
    "+": operator.add,
    "-": operator.sub,
    "*": operator.mul,
    }

def add_parentheses(expr, memory = None):
    if memory is None:
        memory = {}
    
    if expr in memory:
        return memory[expr]

    results = []

    for i, char in enumerate(expr):
        if char in '+-*':
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


if __name__ == "__main__":
    #get the expration
    expr = input("Type your expression (like 2*3-4*5): ").strip()

    result = add_parentheses(expr)
    print("Results With Different Ways to Add Parentheses:", result)


'''
241. Different Ways to Add Parentheses
Medium

Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. 
You may return the answer in any order.

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2

Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
'''
