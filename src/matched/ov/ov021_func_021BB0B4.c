/*
 * function: func_021BB0B4
 * address:  0x021BB0B4
 * packet:   pkt_ov021_021BB0B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A298  0x0204A298  arm
 *   func_02030734  0x02030734  arm
 *   d_021DE2C4     0x021DE2C4  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 *func_0204A298(int, u32, int, u16, u32 *);
extern u32 *func_02030734(u16, u32, int, void *, int);
extern int d_021DE2C4;

void func_021BB0B4(u32 *a, u32 b, u32 c)
{
    u32 i = 0;
    u32 off;

    a[0] = (u32)func_0204A298(0x4f, b, 0, c, &a[1]);
    a[2] = *(u32 *)a[0];
    a[3] = (u32)func_02030734(c, a[2] * 4, 1, &d_021DE2C4, 0x86);
    off = 4;
    for (i = 0; i < a[2]; i++) {
        u16 *q;

        ((u32 *)a[3])[i] = a[0] + off;
        q = (u16 *)((u32 *)a[3])[i];
        off += q[0] * q[1] * 4 + 4;
    }
}
