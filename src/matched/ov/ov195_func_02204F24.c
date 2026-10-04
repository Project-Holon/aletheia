/*
 * function: func_02204F24
 * address:  0x02204F24
 * packet:   pkt_02204F24
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 */

extern void func_02005DE4(void *p);
extern void func_02005E64(void);

void func_02204F24(int a, char *b)
{
    if (*(int *)(b + 0x30) == 4) {
        func_02005DE4((void *)1);
        func_02005E64();
        *(int *)(b + 0x30) = 5;
    }
}