/*
 * function: func_021DC1A0
 * address:  0x021DC1A0
 * packet:   pkt_021DC1A0
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
 *   func_0201A918  0x0201A918  thumb
 *
 * Sends through the eight-argument link routine with arguments (link, flag, 0x2401, size + 0xd4, data, 1, 1, 1); size is 0x0201A918's constant.
 */

typedef unsigned char u8;
typedef unsigned long u32;

struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_0203D3F8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int func_0201A918(void);

void func_021DC1A0(char *obj, u32 data)
{
    u32 busy = func_0203D1A4((struct Link *)((u32)func_020399A8()));
    int flag = 1;

    if (busy != 0)
        flag = 0;
    func_0203D3F8((u32)func_020399A8(), (u8)flag, 0x2401, func_0201A918() + 0xd4, data, 1, 1, 1);
}
