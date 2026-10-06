/*
 * function: func_021914CC
 * address:  0x021914CC
 * packet:   pkt_ov021_021914CC
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
 *   func_02194990  0x02194990  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct S {
    u8  f00;
    u8  f01;
    u8  pad02[6];
    u32 f08;
    u32 sub[2];
    u8 *f14;
} S;

extern u8 func_0219320C(u8 *p);
extern u32 func_02194990(u32 a, u32 b);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
struct Cur;
extern void func_021928C0(struct Cur *c, u32 win, u32 col);
extern void func_02045334(struct Descriptor *a);

void func_021914CC(S *s)
{
    u32 x;

    if (func_0219320C(s->f14 + 0x160) == 0) {
        x = func_02194990(s->f08, s->f01);
        func_021928C0((struct Cur *)s->sub, (u32)func_02045770((struct Descriptor *)x), 0xF);
        func_02045334((struct Descriptor *)x);
    }
}
