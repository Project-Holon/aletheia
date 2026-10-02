/*
 * function: func_021F0924
 * address:  0x021F0924
 * packet:   pkt_ov033_021F0924
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the four `strh #0` after func_02024A20 are `Local s = {0};`
 *           opening an inner block there; declared at the top they land
 *           before the first call.
 *
 * symbols:
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02024A20 0x02024A20 thumb
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_020410D0 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B954 0x0204B954 arm
 *   func_0204B878 0x0204B878 arm
 *   func_02049238 0x02049238 arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

struct Scr {
    u8 pad00[0xC];
    u16 data[0x300];
};

typedef struct {
    u16 heap;
    u16 heap2;
    u8 pad4[0x4];
    u32 f8;
    u32 fC;
    u8 pad10[0x4];
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
} Obj;

extern u32 func_02188C80(u32);
extern u32 func_020120F4(u32);
extern void func_02024A20(u32, u32, u32, u32);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(void *o, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_02049740(void *, u32, u32, u32, u32, u32);
extern u32 func_02049EF4(void *o, u32 a, u32 b, struct Scr **out, u32 e);
extern void func_020410D0(u8 a, u32 b, u32 c, u32 d, u32 e, void *f, u32 g,
                          u32 h, u32 i, u32 j);
extern void func_02041B6C(u8 a);
extern void func_020307B0(u32 h);
extern u32 func_0204AC18(void *arc, u32 id, u32 a, u32 b, u32 c, u32 d, u32 heap);
extern u32 func_0204A6C8(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern u32 func_0204AF28(void *arc, u32 a, u32 b, u32 heap);
extern u32 func_0204B294(u32, u32, u32, u32, Local *, u32, u32);
extern void func_0204B92C(u32, int);
extern void func_0204B954(u32, u32);
extern void func_0204B878(u32, u16);
extern void func_02049238(void *);

void func_021F0924(Obj *p)
{
    struct Scr *ptr;
    u32 heap2;

    heap2 = p->heap2;
    func_02024A20(4, 3, func_020120F4(func_02188C80(p->f8)), p->heap);
    {
        Local s = {0};
        u32 h;
        void *arc;
        u16 *d;
        u16 i;
        u16 base;

        arc = func_020490F4(func_020275E4(), heap2);
        func_02049B68(arc, func_02027624(), 4, 0x40, 0x20, heap2);
        p->f14 = func_02049740(arc, func_02027628(), 4, 0, 0, heap2);
        h = func_02049EF4(arc, func_0202762C(), 0, &ptr, heap2);
        base = p->f14;
        d = ptr->data;
        for (i = 0; i < 0x300; i++) {
            d[i] &= 0xFFF;
            d[i] = (base + d[i]) | 0x2000;
        }
        func_020410D0(4, 0, 0x15, 0x20, 3, ptr->data, 0, 0x15, 0x20, 0x18);
        func_02041B6C(4);
        func_020307B0(h);
        p->f18 = func_0204AC18(arc, func_02027614(), 1, 0x20, 0, 3, p->heap);
        p->f1C = func_0204A6C8(arc, func_02027618(), 0, 1, p->heap);
        p->f20 = func_0204AF28(arc, func_0202761C(0), func_02027620(0), p->heap);
        s.a = 0xE8;
        s.b = 0xA8;
        p->f24 = func_0204B294(p->fC, p->f1C, p->f18, p->f20, &s, 1, p->heap);
        func_0204B92C(p->f24, 1);
        func_0204B954(p->f24, 0x2000);
        func_0204B878(p->f24, 0);
        func_02049238(arc);
        p->f28 = 0;
    }
}
