/*
 * function: func_02190F7C
 * address:  0x02190F7C
 * packet:   pkt_ov021_02190F7C
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

typedef struct P {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    Fx *f14;
} P;

struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(u32 a, u32 b);
extern void func_020409B4(u32 a);

void func_02190F7C(P *p)
{
    func_02043B5C((u32)func_02045770((struct Descriptor *)p->f00), 0xFF);
    func_020409B4((u8)p->f14->f02);
}
