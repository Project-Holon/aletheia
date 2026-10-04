/*
 * function: func_02191134
 * address:  0x02191134
 * packet:   pkt_ov021_02191134
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045334  0x02045334  arm  arm9
 *   func_02045770  0x02045770  arm  arm9
 *   func_021928C0  0x021928C0  thumb  ov021
 *   func_0219320C  0x0219320C  thumb  ov021
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

extern u8 func_0219320C(u8 *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern void func_021928C0(u32 *sub, u32 a, u32 b);
extern void func_02045334(struct Descriptor *a);

void func_02191134(P *p)
{
    if (func_0219320C((u8 *)p->f14 + 0x160) == 0) {
        func_021928C0((u32 *)((u8 *)p + 0x18), (u32)func_02045770((struct Descriptor *)p->f00), 0xF);
        func_02045334((struct Descriptor *)p->f00);
    }
}
