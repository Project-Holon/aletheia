/*
 * function: func_021BAB9C
 * address:  0x021BAB9C
 * packet:   pkt_ov093_021BAB9C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB724  0x021BB724  thumb  ov093
 *   func_021BB798  0x021BB798  thumb  ov093
 */

extern void func_021BB724(int, int, int, int);
extern int func_021BB798(unsigned char *p);

int func_021BAB9C(int a)
{
    char *p = (char *)a;
    if (*(unsigned char *)(p + 0xed) != 2) {
        int (*fp)(int, int) = *(int (**)(int, int))p;
        if (fp(a, a + 4) != 0) {
            func_021BB724(a, 9, *(int *)(p + 0xb0), 8);
            *(unsigned char *)(p + 0xed) = 2;
        }
    } else {
        if (func_021BB798((unsigned char *)p) != 0)
            return 1;
    }
    return 0;
}
