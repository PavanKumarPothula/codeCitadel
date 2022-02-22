#include <stdio.h>
#define MASK_LSB(x, i) ((x << (i)) >> (i))
#define MASK_MSB(x, i) ((x >> (i)) << (i))

void printInBinary(unsigned int x)
{
    for (int i = (sizeof(x) * 8) - 1; i >= 0; i--)
        printf("%u", (x >> i) & 1);
    printf("\n");
}

unsigned int reverseNBits(unsigned int x, unsigned int N)
{
    /*
     & STEPS
     * 0. intiate count to N.
     * 1. Mask and save lsb for later.
     * 2. Mask msb and assign it to result.
     * 3. Shift MSB to rightmost.
     * 4, Copy the last bit of msb to last bit of result.
     * 5. Right shift MSB and left shift result by one.
     * 6. Decrement count by one.
     * 7. Repeat 4 if MSB isn't zero.
     * 8. Left shift the result by remaining count.
     * 9. Copy LSB to result and return result
     */
    unsigned int msb = MASK_MSB(x, (32 - N));
    unsigned int lsb = MASK_LSB(x, N);

    printf("msb:");
    printInBinary(msb);
    printf("lsb:");
    printInBinary(lsb);
    unsigned int result = msb;
    unsigned int count = N;

    msb >>= (32 - N);

    while (msb)
    {
        result |= (msb & 1);
        msb >>= 1;
        result <<= 1;
        count--;
        printInBinary(result);
    }
    result <<= count;
    result |= lsb;
    return result;
}
int main()
{
    unsigned int given = 0x0001 << 16, result, N = 20;
    result = reverseNBits(given, N);
    printf("Given : %u : ", given);
    printInBinary(given);
    printf("N:%u\n", N);
    printf("Result: %u : ", result);
    printInBinary(result);
    return 0;
}