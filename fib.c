int fib(int temp)
{
    if (temp <= 1)
        return temp;
    return fib(temp - 1) + fib(temp - 2);
}
