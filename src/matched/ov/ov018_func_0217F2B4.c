/*
 * function: func_0217F2B4
 * address:  0x0217F2B4
 * packet:   pkt_ov018_0217F2B4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_0201EC74  0x0201EC74  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_021904B0  0x021904B0  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    u8 f28;
} Ov018Obj;

typedef unsigned int   u32;
struct Ctx;
struct U16Vec;
struct WordSet;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188C54(u8 *p);
typedef unsigned short u16;
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_021904B0(u32 a, u32 b);

void func_0217F2B4(Ov018Obj *p, void *a)
{
    void *r;

    r = (void *)func_02188C54(func_0201210C(a));
    if (p->f00 == 0) {
        p->f00 = func_0201EC74(6, 0x20, 4);
        p->f04 = func_020457B0(0x1F0, 4);
        p->f08 = func_020457B0(0x1D0, 4);
        p->f0C = (void *)func_021904B0((u32)r, 0x44);
        p->f10 = (void *)func_021904B0((u32)r, 0x42);
        p->f14 = (void *)func_021904B0((u32)r, 0x43);
        p->f24 = r;
        p->f28 = 0;
    }
}
