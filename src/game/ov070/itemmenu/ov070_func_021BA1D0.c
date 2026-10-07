/*
 * function: func_021BA1D0
 * address:  0x021BA1D0
 * packet:   pkt_ov070_021BA1D0
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02021288  0x02021288  thumb
 *   func_020212B0  0x020212B0  thumb
 */

typedef unsigned int   u32;
extern u32 func_02021288(u32 id);
extern int func_020212B0(int);

int func_021BA1D0(int x)
{
    if (func_02021288(x) == 1) {
        switch (func_020212B0(x)) {
        case 0xF:
        case 0x13:
        case 0x39:
        case 0x46:
        case 0x7F:
        case 0x123:
            return 1;
        }
    }
    return 0;
}
