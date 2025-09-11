#splving problem 282 from leetcode: https://leetcode.com/problems/expression-add-operators/description/
#the approach I used is Recursion and back tracking, splited this problem into 2 part, splitting numbers and add operators.

def main():

    expr = input("Enter a numeric string (e.g., 123): ").strip()
    while not expr.isdigit():
        expr = input("Invalid input. Please enter digits only (e.g., 123): ").strip()

    try:
        target = int(input("Enter a target number (e.g., 6): ").strip())
    except ValueError:
        print("Invalid target. Must be an integer.")
        return

    # Split numeric string into all valid ways of numbers
    sliced_numbers = splitting_numbers(0, expr)

    
    final_result = []

    for num_list in sliced_numbers:
        # Skip empty lists
        if not num_list:
            continue

        result = []
        first = num_list[0]
        # Start recursion with first number as base
        add_operators(num_list, target, 1, str(first), first, first, result)

        # Collect valid expressions for all number splits
        final_result.extend(result)

    print(f"\nInput: num = \"{expr}\", target = {target}")
    print("Output:", final_result)


def add_operators(numbers, target, index, valid_expr, value, last_operand, result):
    """
    Recursive function to try all combinations of +, -, * between numbers
    and track valid expressions that evaluate to the target.
    """
    if index == len(numbers):
        if value == target:
            result.append(valid_expr)
        return result

    current_num = numbers[index]

    # Handle '+'
    add_operators(
        numbers, target, index + 1,
        valid_expr + '+' + str(current_num),
        value + current_num,
        current_num,
        result
    )

    # Handle '-'
    add_operators(
        numbers, target, index + 1,
        valid_expr + '-' + str(current_num),
        value - current_num,
        -current_num,  # Track as negative for future '*'
        result
    )

    # Handle '*'
    new_val = value - last_operand + (last_operand * current_num)
    add_operators(
        numbers, target, index + 1,
        valid_expr + '*' + str(current_num),
        new_val,
        last_operand * current_num,
        result
    )


def splitting_numbers(index, numbers, path = None, result = None):
    """
    Recursively split the input string into all possible sequences of numbers
    (e.g., '123' => [[1,2,3], [1,23], [12,3], [123]])
    Avoids leading zeros like "05"
    """
    if path is None:
        path = []
    if result is None:
        result = []

    if index == len(numbers):
        result.append(path)
        return result #base case

    for j in range(index + 1, len(numbers) + 1):
        substring = numbers[index:j]

        # Skip numbers with leading zeros (except '0' itself)
        if len(substring)>1 and substring[0] == '0':
            break

        number = int(substring)
        splitting_numbers(j, numbers, path + [number], result)
    
    return result

if __name__ == "__main__":
    main()

'''
282. Expression Add Operators
Hard

Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.

Note that a number can contain multiple digits.

 

Example 1:

Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

Example 2:

Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.

Example 3:

Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.

 

Constraints:

    1 <= num.length <= 10
    num consists of only digits.
    -231 <= target <= 231 - 1

'''