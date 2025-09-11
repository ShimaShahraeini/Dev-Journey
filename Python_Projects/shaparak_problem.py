#https://quera.org/problemset/251440?tab=description
# this is the code I came up with for shaparak problem - no operator(quera question) on my first try! I think there is room for improvment, 
#1) first combination 1 and 2 are somehow like each other maybe there is cleaner way to code this. go to file no_operator.py
#2) what if we want to enter an expression with more than 3 numbers? go to file no_operator_unlimited.py

#I used Brute-force search to solve this problem cuase it was small enough, also known as exhaustive search,
#is a problem-solving technique that involves systematically trying all possible solutions to find the correct one.

def max_in_shaparak(expr):
    #Parse the input
    numbers =  list(map(int , expr.split("?")))

    results = []
    
    #Generate all possible combinations
    for o in ['++', '**', '+*', '*+']:
        combination1(numbers,o, results)
        combination2(numbers,o, results)

    #Track the max
    return max(results)

def combination1(num, operator, results):
    #(a op1 b) op2 c
    match operator:
        case '++':
            results.append((num[0]+num[1])+num[2])
        case "**":
            results.append((num[0]*num[1])*num[2])
        case "+*":
            results.append((num[0]+num[1])*num[2])
        case "*+":
            results.append((num[0]*num[1])+num[2])

def combination2(num, operator, results):
    #a op1 (b op2 c)
    match operator:
        case '++':
            results.append(num[0]+(num[1]+num[2]))
        case "**":
            results.append(num[0]*(num[1]*num[2]))
        case "+*":
            results.append(num[0]+(num[1]*num[2]))
        case "*+":
            results.append(num[0]*(num[1]+num[2]))


if __name__ == "__main__":
    expr = input().strip()
    print(max_in_shaparak(expr))