/*
 * function: func_021915EC
 * address:  0x021915EC
 * packet:   pkt_ov021_021915EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020409B4  0x020409B4  arm  arm9
 *   func_02043B5C  0x02043B5C  arm  arm9
 *   func_02045770  0x02045770  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

typedef struct R {
    u32 f00;
    u32 f04;
    u32 f08;
    Fx *f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    void *f20;
    u32 f24;
    u16 f28;
} R;

extern u32 func_02045770(u32 a);
extern void func_02043B5C(u32 a, u32 b);
extern void func_020409B4(u32 a);

void func_021915EC(R *r)
{
    func_02043B5C(func_02045770(r->f18), 0xFF);
    func_020409B4((u8)r->f0c->f02);
}
