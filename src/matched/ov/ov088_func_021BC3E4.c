/*
 * function: func_021BC3E4
 * address:  0x021BC3E4
 * packet:   pkt_ov088_021BC3E4
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020312CC  0x020312CC  arm
 *   func_02008450  0x02008450  thumb
 *   d_021BD830     0x021BD830  data  a4
 */

typedef unsigned int u32;
extern void func_020312CC(u32 a0, u32 a1, u32 a2);
extern void func_02008450(int, int);
extern char d_021BD830[];

int func_021BC3E4(int a, int *st, int k, int *p)
{
    switch (*st) {
    case 0:
        if (k == 0) {
            func_020312CC(-1, (u32)d_021BD830, (u32)p);
        } else if (k == 1) {
            func_02008450(p[1], 0);
        } else if (k == 2) {
            func_02008450(p[1], 1);
        }
        *st = *st + 1;
        break;
    case 1:
        return 1;
    }
    return 1;
}
