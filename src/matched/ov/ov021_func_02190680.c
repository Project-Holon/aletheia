/*
 * function: func_02190680
 * address:  0x02190680
 * packet:   pkt_ov021_02190680
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm  arm9
 *   func_021904EC  0x021904EC  thumb  ov021
 *   func_02192F74  0x02192F74  thumb  ov021
 *   func_02193044  0x02193044  thumb  ov021
 *   func_021930C0  0x021930C0  thumb  ov021
 *   func_02193144  0x02193144  thumb  ov021
 *   func_02193170  0x02193170  thumb  ov021
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

typedef struct Obj {
    u32 id;
    u32 slot;
    Fx *owner;
} Obj;

extern char d_021DDA50[];

extern void func_02192F74(Fx *a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_021930C0(int a, int unused, int b, int c, u16 d, u16 e, u16 f);
struct Slot;
extern struct Slot *func_021904EC(u32 *p, u32 a, u32 b);
extern void func_02193144(u32 heap);
extern void func_02193044(u32 v);
extern void func_02193170(u32 heap);

Obj *func_02190680(Fx *a, u32 b, u16 c, u16 d, u16 e, u16 f, u16 g)
{
    u8 k;
    Obj *r;

    k = a->f02;
    func_02192F74(a);
    if (g == 0xe) {
        k = a->f04;
    }
    r = func_02030734(a->f00, 0xC, 1, d_021DDA50, 0x483);
    r->owner = a;
    r->id = func_021930C0(k, a->f00, c, d, e, f, g);
    r->slot = (u32)func_021904EC((u32 *)a, b, r->id);
    if (g == 0xe) {
        func_02193144(a->f00);
        func_02193044(1);
    } else {
        func_02193170(a->f00);
    }
    return r;
}
