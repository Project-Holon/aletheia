/*
 * function: func_0220D39C
 * address:  0x0220D39C
 * packet:   pkt_0220D39C
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02021ED8 0x02021ED8 thumb
 */

typedef unsigned int   u32;
extern u32 func_02021ED8(const char *ptr);

int func_0220D39C(char *a)
{
    if (func_02021ED8((const char *)(*(int *)(a + 8))) == 0)
        return 0x14;
    return 0x13;
}