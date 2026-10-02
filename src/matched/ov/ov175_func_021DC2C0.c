/*
 * function: func_021DC2C0
 * address:  0x021DC2C0
 * packet:   pkt_021DC2C0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *
 * Tagged log/emit: the tick from 0x020399A8, the id 0x2405, a length of
 *     4 and the caller's pointer go to 0x0203D3A8, which is the four-argument
 *     form the listing loads straight into r2/r3.
 */

typedef unsigned short u16;
typedef unsigned long u32;

extern void *func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *p);

void func_021DC2C0(u32 ignored, void *p)
{
    func_0203D3A8(func_020399A8(), 0x2405, 4, p);
}

