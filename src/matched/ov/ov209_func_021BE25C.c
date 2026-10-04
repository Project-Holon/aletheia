/*
 * function: func_021BE25C
 * address:  0x021BE25C
 * packet:   pkt_021BE25C
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD8F4 0x021BD8F4 thumb
 */

typedef unsigned int   u32;
extern u32 func_021BD8F4(char *p, u32 idx);

int func_021BE25C(int p, int t)
{
    unsigned int i;

    if (t == 1) {
        for (i = 0xa; i < 0x1a; i++) {
            if (func_021BD8F4((char *)p, i) == 0) {
                return i;
            }
        }
    } else {
        for (i = 0x1a; i < 0x2a; i++) {
            if (func_021BD8F4((char *)p, i) == 0) {
                return i;
            }
        }
    }
    return 0;
}
