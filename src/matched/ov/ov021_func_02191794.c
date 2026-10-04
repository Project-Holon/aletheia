/*
 * function: func_02191794
 * address:  0x02191794
 * packet:   pkt_ov021_02191794
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

extern u8 func_0219320C(u8 *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern void func_021928C0(R *sub, u32 a, u32 b);
extern void func_02045334(u32 a);

void func_02191794(R *r)
{
    if (func_0219320C((u8 *)r->f0c + 0x160) == 0) {
        func_021928C0(r, (u32)func_02045770((struct Descriptor *)r->f18), 0xF);
        func_02045334(r->f18);
    }
}
