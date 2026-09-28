/*
 * function: func_021DC268
 * address:  0x021DC268
 * packet:   pkt_021DC268
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *
 * Sends through the eight-argument link routine with arguments (link, flag, 0x2404, 4, data, 1, 1, 1); flag is 1 unless 0x0203D1A4 reports the link busy.
 */

typedef unsigned char u8;
typedef unsigned long u32;

extern u32 func_020399A8(void);
extern u32 func_0203D1A4(u32 link);
extern u32 func_0203D3F8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

void func_021DC268(char *obj, u32 data)
{
    u32 busy = func_0203D1A4(func_020399A8());
    int flag = 1;

    if (busy != 0)
        flag = 0;
    func_0203D3F8(func_020399A8(), (u8)flag, 0x2404, 4, data, 1, 1, 1);
}
