/*
 * function: func_021B6D70
 * address:  0x021B6D70
 * packet:   pkt_ov067_021B6D70
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020458F8  0x020458F8  arm
 *   func_02045A90  0x02045A90  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020458F8(u32 h);
extern u16 *func_02045A90(u32 h);

int func_021B6D70(u32 a, u32 b, u32 n)
{
    u16 *pa;
    u16 *pb;
    u32 i;

    if (func_020458F8(a) < n) {
        return 0;
    }
    if (func_020458F8(b) < n) {
        return 0;
    }
    pa = func_02045A90(a);
    pb = func_02045A90(b);
    for (i = 0; i < n; i++) {
        if (*pa++ != *pb++) {
            return 0;
        }
    }
    return 1;
}
