# it is for finding fibonacci numbers in O (lg(n)) time complexity

p = [[0, 1], [1, 1]]


def matrix_multiplication(A, B):
    # A and B are 2 * 2 matrices
    c = [[0, 0], [0, 0]]
    c[0][0] = A[0][0]*B[0][0]+A[0][1]*B[1][0]
    c[0][1] = A[0][0]*B[0][1]+A[0][1]*B[1][1]
    c[1][0] = A[1][0]*B[0][0]+A[1][1]*B[1][0]
    c[1][1] = A[1][0]*B[0][1]+A[1][1]*B[1][1]
    return c


def power(p, n):
    ans = [[1, 0], [0, 1]]  # identity matrix
    while n > 0:
        if n % 2 == 1:
            ans = matrix_multiplication(ans, p)
        p = matrix_multiplication(p, p)
        n >>= 1
    return(ans)


def calculate_fib_n(fib0, fib1, n):  # zero-based fibonacci numbers
    # n+1 th fibanacci number in one-based
    fib = [fib0, fib1]
    q = power(p, n)
    return (fib[0]*q[0][0]+fib[1]*q[1][0])


if __name__ == '__main__':
    print(calculate_fib_n(0, 1, 100000))
