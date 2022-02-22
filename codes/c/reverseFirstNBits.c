#include <stdio.h>
#define MASK_LSB(x, i) ((x << (i)) >> (i))
#define MASK_MSB(x, i) ((x >> (i)) << (i))

void printInBinary(unsigned int x)
{
    for (int i = 0; i < (sizeof(x) * 8); i++)
    {
        printf("%u", )
    }
}

unsigned int reverseNBits(unsigned int x, unsigned int N)
{
    /*
     * 0. intiate count to N.
     * 1. Mask and save lsb for later.
     * 2. Mask msb and assign it to result.
     * 3. Shift MSB to rightmost.
     * 4, Copy the last bit of msb to last bit of result.
     * 5. Right shift MSB and left shift result by one.
     * 6. Decrement count by one.
     * 7. Repeat 4 if MSB isn't zero.
     * 8. Left shift the result by remaining count.
     * 9. Copy LSB to result and return result.
     */
    unsigned int lsb = MASK_LSB(x, 32 - N);
    unsigned int msb = MASK_MSB(x, N);

    unsigned int result = msb;
    unsigned int count = N;

    msb >>= 32 - N;

    while (msb)
    {
        result |= (msb & 1);
        msb >>= 1;
        result <<= 1;
        count--;
    }
    result <<= count;
    result |= lsb;
    return result;
}
int main()
{
    unsigned int given, result, N;
    scanf("%u", &given);
    scanf("%u", &N);
    result = reverseNBits(given, N);
    printf("Given:%x, N:%x\n", given, N);
    printf("result:%x\n", result);
    return 0;
}