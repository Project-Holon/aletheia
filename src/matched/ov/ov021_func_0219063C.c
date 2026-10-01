/*
 * function: func_0219063C
 * address:  0x0219063C
 * packet:   pkt_ov021_0219063C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020409B4  0x020409B4  arm  arm9
 *   func_02043AF4  0x02043AF4  arm  arm9
 *   func_02045730  0x02045730  arm  arm9
 *   func_02045770  0x02045770  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

extern u32 func_02045770(u32 a);
extern u32 func_02045730(u32 a);
extern void func_02043AF4(u32 a, s16 b, s16 c, u16 d, u16 e, u32 f);
extern void func_020409B4(u32 a);

void func_0219063C(Slot *s, int x, int y, int w, int h)
{
    func_02043AF4(func_02045770(s->f14), x, y, w, h, 0xFF);
    func_020409B4(func_02045730(s->f14));
}
