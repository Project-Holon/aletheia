/*
 * function: func_021F22E8
 * address:  0x021F22E8
 * packet:   pkt_021F22E8
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 */

extern int func_0201C6C4(int, int);
extern int func_02045770(int);
extern void func_02045334(int);

int func_021F22E8(unsigned char *p)
{
    int c = p[0x30];
    int r4 = *(int *)(p + 0x38);

    if (c != 0) {
        if (func_0201C6C4(r4, func_02045770(*(int *)(p + 0x2c))) == 0) {
            func_02045334(*(int *)(p + 0x2c));
            p[0x30] = 0;
        }
    }
    return p[0x30] == 0;
}
