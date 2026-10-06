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

struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern u8 func_02045730(struct Descriptor *p);
struct Bmp;
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_020409B4(u32 a);

void func_0219063C(Slot *s, int x, int y, int w, int h)
{
    func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)s->f14)), (s16)x, (s16)y, (u16)w, (u16)h, 0xFF);
    func_020409B4(func_02045730((struct Descriptor *)s->f14));
}
