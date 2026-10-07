/*
 * function: func_02206BC8
 * address: 0x02206BC8
 * packet: pkt_ov094_02206BC8
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_0204AEF4 0x0204AEF4 arm
 *   func_020216D4 0x020216D4 thumb
 *   func_020275E4 0x020275E4 thumb
 *   func_020276B8 0x020276B8 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_020276BC 0x020276BC thumb
 *   func_020276C0 0x020276C0 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_020276B4 0x020276B4 thumb
 *   func_02022004 0x02022004 thumb
 *   func_02049238 0x02049238 arm
 *   func_02049E74 0x02049E74 arm
 *   func_02005C44 0x02005C44 thumb
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   func_021F8710 0x021F8710 thumb ov094
 *   func_02207430 0x02207430 thumb ov094
 *   func_022079C0 0x022079C0 thumb ov094
 *   func_02208BFC 0x02208BFC thumb ov094
 *   d_0220AEC0 0x0220AEC0 data a1
 *   d_0220AABC 0x0220AABC data a2
 */
#include "../../../matched/include/Obj21804.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct { s16 x, y; } Pt;

typedef struct {
    char pad00[0x40];
    int kind;
    char pad44[0x3c];
} Slot;

typedef struct {
    void *f00;
    void *h04;
    int f08;
    void *f0c;
    void *f10;
    int f14;
    int f18[6];
    int f30, f34, f38, f3c;
    Slot slot[8];
    int f440;
    int f444;
    u16 heap;
} Obj;

typedef struct {
    Obj *obj;
    int pad[3];
} Task;

extern const char d_0220AEC0[];
extern const Pt d_0220AABC;

typedef signed int     s32;
typedef unsigned char  u8;
struct Bank;
struct PalAnmSlot;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u32 heap);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_021F86E0(void);
extern int func_0204AEF4(u32 idx, u32 alternate);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern u32 func_020275E4(void);
extern u32 func_020276B8(void);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 func_020276BC(u32 i);
extern u32 func_020276C0(u32 i);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_020276B4(void);
extern void func_02022004(unsigned, unsigned, u16, unsigned, unsigned);
extern void func_02049238(void *);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u16 func_02005C44(void);
extern void *func_021F86D4(void);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 a3);
extern int func_021F8710(void);
extern void func_02207430(Obj *, int, int);
extern void func_022079C0(Obj *, int, Pt *);
extern void func_02208BFC(void *, void *);

Obj *func_02206BC8(int a, u16 heap)
{
    char *hdr;
    Pt pos;
    Pt base;
    Obj *s;
    int i;
    void *arc;
    Task *t;
    int lo, hi, kind;

    s = func_02030734(heap, sizeof(Obj), 1, d_0220AEC0, 0x14b);
    s->heap = heap;
    s->h04 = func_020490F4(0xb, (u16)s->heap);
    s->f00 = func_0204B100(0x28, 0, s->heap);
    for (i = 0; i < 6; i++) {
        s->f18[i] = func_0204ABF0(s->h04, 0xa2, 0, (u16)(i * 0x20), s->heap);
        func_020216D4((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(func_0204AEF4(s->f18[i], 0) >> 1), 0x20);
    }
    arc = func_020490F4(func_020275E4(), (u16)((s->heap & 0x7fff) | 0x8000));
    s->f30 = func_0204A6C8(arc, func_020276B8(), 0, 0, s->heap);
    s->f34 = func_0204AF28(arc, func_020276BC(1), func_020276C0(1), s->heap);
    s->f38 = func_0204ABF0(arc, func_020276B4(), 0, 0x100, s->heap);
    s->f3c = func_0204ABF0(arc, func_020276B4(), 0, 0x120, s->heap);
    func_020216D4((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(func_0204AEF4(s->f38, 0) >> 1), 0x20);
    func_020216D4((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(func_0204AEF4(s->f3c, 0) >> 1), 0x20);
    func_02022004((unsigned)func_021F86E0(), 2, 0x200, 8, 0);
    func_02049238(arc);
    s->f10 = func_02049E74((void *)s->h04, 0xa4, 0, (u32)(&hdr), s->heap);
    s->f14 = ((struct Obj21804 *)hdr)->f14;
    s->f08 = a;
    s->f444 = func_02005C44();
    t = func_02030734(heap, sizeof(Task), 1, d_0220AEC0, 0x185);
    t->obj = s;
    s->f0c = func_02030DA8(func_021F86D4(), func_02208BFC, t, 0);
    switch (func_021F8710()) {
    case 0:
        lo = 0;
        hi = 1;
        kind = 0;
        break;
    case 1:
        lo = 2;
        hi = 5;
        kind = 1;
        break;
    case 2:
    default:
        lo = 2;
        hi = 7;
        kind = 2;
        break;
    case 3:
        lo = 2;
        hi = 7;
        kind = 3;
        break;
    }
    for (i = lo; i <= hi; i++) {
        base = d_0220AABC;
        pos = base;
        if (i & 1)
            pos.x *= -1;
        func_02207430(s, kind, i);
        s->slot[i].kind = kind;
        func_022079C0(s, i, &pos);
    }
    return s;
}
