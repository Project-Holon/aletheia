/*
 * function: func_02204EB0
 * address:  0x02204EB0
 * packet:   pkt_02204EB0
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005DF8 0x02005DF8 thumb
 */

extern int func_02005E9C(int);
extern void func_02005DE4(int);
extern void func_02005DF8(int);

void func_02204EB0(char *a, char *b)
{
    if (*(int *)(b + 0x30) == 0 && *(int *)(a + 0xc) != 0) {
        func_02005E9C(*(int *)(a + 0xc));
        func_02005DE4(0);
        func_02005DF8(0x3c);
    }
}
