/*
 * function: func_02190FA0
 * address:  0x02190FA0
 * packet:   pkt_ov021_02190FA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm  arm9
 *   func_020457B0  0x020457B0  arm  arm9
 *   func_021927C0  0x021927C0  thumb  ov021
 *   func_02192B20  0x02192B20  thumb  ov021
 *   func_02192F74  0x02192F74  thumb  ov021
 *   func_02193044  0x02193044  thumb  ov021
 *   func_02193144  0x02193144  thumb  ov021
 *   d_021DDA50     0x021DDA50  data   ov021  a1
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

typedef struct Obj2 {
    u32 id;
    u32 f04;
    u32 f08;
    u32 b;
    u32 f10;
    Fx *owner;
    u32 sub[2];
} Obj2;

extern char d_021DDA50[];

extern void func_02192F74(Fx *a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_021927C0(u32 *sub, Fx *a);
extern void func_02193144(u32 heap);
extern void func_02193044(u32 v);
extern u32 func_02192B20(u8 a, u8 b, u8 c, u8 d, u32 e);

Obj2 *func_02190FA0(Fx *a, u32 b, u32 c)
{
    Obj2 *r;

    a->f06 = 0xe;
    func_02192F74(a);
    r = func_02030734(a->f00, 0x20, 1, d_021DDA50, 0x9F4);
    r->owner = a;
    r->b = b;
    r->id = func_02192B20(1, c, 0x1E, 4, a->f00);
    r->f10 = (u32)func_020457B0(0xA0, a->f00);
    func_021927C0(r->sub, a);
    func_02193144(a->f00);
    func_02193044(1);
    return r;
}
