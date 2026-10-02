/*
 * function: func_021CF3B0
 * address:  0x021CF3B0
 * packet:   pkt_ov021_021CF3B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203996C  0x0203996C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0203996C(u32 a);
extern void *func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);

void func_021CF3B0(int mode)
{
    if (mode == 1) {
        func_0203D3A8(func_0203996C(0xff), 0x2706, 0, 0);
    } else {
        func_0203D3A8(func_020399A8(), 0x2706, 0, 0);
    }
}
