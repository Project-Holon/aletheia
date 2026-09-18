/*
 * unit:     no
 * function: func_0209D784
 * address:  0x0209D784
 * packet:   pkt_0209D784
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int  u32;
typedef unsigned char u8;

extern int func_0209D77C(void);

u32 func_0209D784(u32 a, char *dest, u32 *count)
{
    u32 i;
    u32 n = *count;
    for (i = 0; i < n; i++)
    {
        int c = func_0209D77C();
        dest[i] = (char)c;
        if ((u8)c == '\r' || (u8)c == '\n')
        {
            *count = i + 1;
            break;
        }
    }
    return 0;
}