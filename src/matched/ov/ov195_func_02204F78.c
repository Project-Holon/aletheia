/*
 * function: func_02204F78
 * address:  0x02204F78
 * packet:   pkt_02204F78
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005E30 0x02005E30 thumb
 */

typedef unsigned int   u32;
extern void func_02005E30(u32 a);

void func_02204F78(int a, char *b)
{
    if (*(int *)(b + 0x30) == 4) {
        func_02005E30(0x3c);
        *(int *)(b + 0x30) = 6;
    }
}
