/*
 * file:     bsubway_scr_p19.c
 * unit:     yes
 * function: func_021C9B78, func_021C9BCC, func_021C9C54, func_021C9CAC, func_021C9D30, func_021C9D70, func_021C9DB0, func_021C9E8C, func_021C9F44, func_021C9FD0, func_021C9FFC, func_021CA048, func_021CA05C, func_021CA150, func_021CA164, func_021CA1E4, func_021CA210, func_021CA234, func_021CA238
 * address:  0x021C9B78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200D914  0x0200D914  thumb
 *   func_0200DB44  0x0200DB44  thumb
 *   func_0200DAC4  0x0200DAC4  thumb
 *   func_021CA250  0x021CA250  thumb
 *   func_0200D868  0x0200D868  thumb
 *   func_021CA270  0x021CA270  thumb
 *   func_0200D884  0x0200D884  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200DA14  0x0200DA14  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200DB1C  0x0200DB1C  thumb
 *   func_0200DB08  0x0200DB08  thumb
 *   func_0200DAEC  0x0200DAEC  thumb
 *   func_021CA2DC  0x021CA2DC  thumb
 *   func_0200DC08  0x0200DC08  thumb
 *   func_0200DB80  0x0200DB80  thumb
 *   func_0200DA80  0x0200DA80  thumb
 *   d_021DACDC     0x021DACDC  data  a1
 *   func_021CA2CC  0x021CA2CC  thumb
 *   func_021CBD90  0x021CBD90  thumb
 *   func_021CA2A4  0x021CA2A4  thumb
 *   func_0200DA54  0x0200DA54  thumb
 *   func_0200DB60  0x0200DB60  thumb
 *   func_0200DEA8  0x0200DEA8  thumb
 *   func_021CBED8  0x021CBED8  thumb
 *   func_02168AEC  0x02168AEC  thumb  ov010
 *   func_0200DBA0  0x0200DBA0  thumb
 *   func_0200DBF0  0x0200DBF0  thumb
 *   func_0200DC0C  0x0200DC0C  thumb
 *   func_0200DBFC  0x0200DBFC  thumb
 *   data_021DACD0  0x021DACD0  data
 *   func_020307B0  0x020307B0  arm
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_02012934  0x02012934  thumb
 */
#include "../../matched/include/Obj03617.h"
#include "../../matched/include/Obj02732.h"
#include "../../matched/include/Obj00116.h"
#include "../../matched/include/Obj02733.h"
#include "../../matched/include/Obj04291.h"
#include "../../matched/include/Obj05094.h"
#include "../../matched/include/Obj20232.h"
#include "../../matched/include/Obj07233.h"
#include "../../matched/include/Obj01671.h"
#include "../../matched/include/Obj07584.h"
#include "../../matched/include/Obj18345.h"
#include "../../matched/include/Obj18346.h"

struct Blk1AC;
struct Blk3C;
struct Ctx;
struct Big;
struct Sub020071CCCtrl;
struct BigObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8  pad0[0xc];
    u16 lo  : 5;
    u16 sel : 3;
    u16 hi  : 8;
} Sel;

typedef struct {
    u8  pad0[0x22];
    u16 a22[4];
    u16 a2a[4];
} Stats;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct { u16 b0 : 1; u16 b1 : 2; } Bits;

typedef struct {
    u8  pad0[0xc];
    u16 done : 1;
    u16 rest : 15;
} Latch;

typedef struct {
    u16 tag : 11;
    u16 hi  : 5;
    u16 val;
    u8  pad4[0x38];
} Slot;

extern void func_0200D914(struct Blk3C *p, u32 id, const void *src);
extern u32 func_0200DB44(struct Blk1AC *p, u32 i);
extern u16 func_0200DAC4(struct Blk1AC *p, u32 i);
extern int func_021CA250(u32 a);
extern void func_0200D868(struct Blk3C *p, u32 v);
extern int func_021CA270(u16 kind);
extern u32 func_0200D884(struct Blk3C *p, u32 id, void *out);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *m, u32 id, u32 v);
extern void func_0200DA14(struct Blk3C *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void func_0200DB1C(struct Blk1AC *p, u32 i);
extern void func_0200DB08(struct Blk1AC *p, u32 i, u16 v);
extern void func_0200DAEC(struct Blk1AC *p, u32 i, u16 v);
extern void func_021CA2DC(u8 *p, u32 h, int flag, u16 v);
extern u8 func_0200DC08(struct Blk1AC *p);
extern u16 func_0200DB80(struct Blk1AC *p, u32 i);
extern void func_0200DA80(struct Blk1AC *p, s32 v);
extern u16 func_021CA2CC(u16 v);
extern u16 func_021CBD90(void *ctx, u32 round, u32 stage, u32 line, u8 alt);
extern int func_021CA2A4(const u16 *arr, u16 val, u16 n);
extern u16 func_0200DA54(struct Blk3C *p);
extern void func_0200DB60(struct Blk1AC *p, u32 i);
extern void func_0200DEA8(u32 h, u8 *list, u8 n, u16 id);
extern u8 func_021CBED8(u32 unused, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u16 func_02168AEC(u16 a0);
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern void func_0200DBF0(struct Blk1AC *p);
extern u8 func_0200DC0C(struct Blk1AC *p, u32 kind);
extern void func_0200DBFC(struct Blk1AC *p);
extern u32 func_020307B0(void *p);
extern void *func_0200BAC8(void *p);
extern void *func_0200BAF4(int a0, int a1);
extern void *func_02012934(const struct BigObj *p);
void func_021C9B78(u8 *p);
void func_021C9BCC(u8 *p);
void func_021C9C54(u8 *p, u32 x);
void func_021C9CAC(u8 *p);
u32 func_021C9D30(const struct Ctx *a0);
void func_021C9D70(u32 unused, u8 *p);
u32 func_021C9DB0(u8 *p);
void func_021C9E8C(u8 *p);
u32 func_021C9F44(u8 *p, u32 x);
int func_021C9FD0(u8 *p);
void func_021C9FFC(u8 *p, u32 x);
int func_021CA048(u32 a, u32 b);
void func_021CA05C(u8 *p);
u32 func_021CA150(u8 *p, int i);
int func_021CA164(void *a, int unused, int mode);
void func_021CA1E4(u8 *p);
void *func_021CA210(u8 *p);
u16 func_021CA234(u8 *p);
void func_021CA238(u8 *p, u16 v);
extern const u8 d_021DACDC[7][10];
extern const u8 data_021DACD0[];


/*
 * Remaps kind 2/7 to 3/8, pushes it to the +0x70 object and refreshes the +0xe counter from +0x74.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9B78(u8 *p)
{
    u8 v;

    if (p[9] == 2)
        v = 3;
    else if (p[9] == 7)
        v = 8;
    p[9] = v;
    func_0200D914((struct Blk3C *)(((struct Obj03617 *)p)->f70), 0, &v);
    if (func_0200DB44((struct Blk1AC *)(((struct Obj03617 *)p)->f74), p[9]) == 1)
        func_021CA238(p, func_0200DAC4((struct Blk1AC *)(((struct Obj03617 *)p)->f74), p[9]));
    else
        func_021CA250((u32)p);
}


/*
 * Pushes the kind, the +0x1e and +0x32 blocks and, for kind 2/7, the selected +0x628 entry to the +0x70 object.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9BCC(u8 *p)
{
    u8 v = p[9];

    func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 0, &v);
    func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 5, p + 0x1e);
    func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 8, p + 0x32);
    func_0200D868((struct Blk3C *)(((struct Obj02732 *)p)->f70), 1);
    if (p[9] == 2 || p[9] == 7) {
        v = ((Sel *)p)->sel;
        func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 9, &v);
        func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 6, p + 0x628 + ((Sel *)p)->sel * 0x14);
        func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 7, p + 0x664 + ((Sel *)p)->sel);
    }
}


/*
 * Classifies the kind into the +8 count and reads two stats per slot into +0x22 and +0x2a.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9C54(u8 *p, u32 x)
{
    void *h;
    int i;
    u32 m;

    p[8] = func_021CA270(p[9]);
    func_0200D884((struct Blk3C *)(((struct Obj00116 *)p)->f70), 5, p + 0x1e);
    h = func_021CA210(p);
    for (i = 0; i < p[8]; i++) {
        m = (u32)func_0201AB28(h, p[0x1e + i]);
        ((Stats *)p)->a22[i] = func_02017E1C((void *)m, 5, 0);
        ((Stats *)p)->a2a[i] = func_02017E1C((void *)m, 6, 0);
    }
}


/*
 * Like 0x021C9BCC with a reset of the +0x70 object and without the +0x32 block.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9CAC(u8 *p)
{
    u8 v = p[9];

    func_0200D914((struct Blk3C *)(((struct Obj02733 *)p)->f70), 0, &v);
    func_0200DA14((struct Blk3C *)(((struct Obj02733 *)p)->f70));
    func_0200D914((struct Blk3C *)(((struct Obj02733 *)p)->f70), 5, p + 0x1e);
    func_0200D868((struct Blk3C *)(((struct Obj02733 *)p)->f70), 1);
    if (p[9] == 2 || p[9] == 7) {
        v = ((Sel *)p)->sel;
        func_0200D914((struct Blk3C *)(((struct Obj02733 *)p)->f70), 9, &v);
        func_0200D914((struct Blk3C *)(((struct Obj02733 *)p)->f70), 6, p + 0x628 + ((Sel *)p)->sel * 0x14);
        func_0200D914((struct Blk3C *)(((struct Obj02733 *)p)->f70), 7, p + 0x664 + ((Sel *)p)->sel);
    }
}


/*
 * Reads flag 0 of resource 0x39, resets it and forwards the flag to resource 0x3a.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C9D30(const struct Ctx *a0)
{
    u32 a = (u32)func_02012EBC((struct Big *)func_020120F4(a0));
    u32 b = (u32)func_020071CC((struct Sub020071CCCtrl *)a, 0x39);
    u32 c = (u32)func_020071CC((struct Sub020071CCCtrl *)a, 0x3a);
    u8 r = func_0200D884((struct Blk3C *)b, 0, 0);

    func_0200DA14((struct Blk3C *)b);
    func_0200DB1C((struct Blk1AC *)c, r);
    return r;
}


/*
 * Commits the +0xe counter for the current kind and redraws.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9D70(u32 unused, u8 *p)
{
    u16 v = ((struct Obj00116 *)p)->fE;
    u8 kind = p[9];
    u32 h = ((struct Obj00116 *)p)->f74;

    func_0200DB08((struct Blk1AC *)h, kind, v);
    func_0200DAEC((struct Blk1AC *)h, kind, v);
    func_021CA2DC(p, (u32)func_02012EBC((struct Big *)(*(u32 *)&((struct Obj00116 *)p)->f6C)), 1, v);
    func_0200DB1C((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind);
    func_0200DA14((struct Blk3C *)(((struct Obj00116 *)p)->f70));
}


/*
 * Picks a step amount from a 7x10 byte table by mode byte +9 and a clamped
 * counter, adds it to the record at +0x74 and returns it.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C9DB0(u8 *p)
{
    int r;
    int row;
    int idx;
    u16 n;

    if (p[9] == 4) {
        r = 0;
        if ((u16)func_0200D884(((struct Obj04291 *)p)->f70, 0xB, 0) == 1) {
            idx = (s8)func_0200DC08(((struct Obj04291 *)p)->f74);
            if (idx < 0)
                idx = 0;
            else if (idx >= 10)
                idx = 9;
            r = d_021DACDC[6][idx];
        } else {
            r = 5;
        }
    } else {
        r = 0;
        n = func_0200DB80(((struct Obj04291 *)p)->f74, p[9]);
        switch (p[9]) {
        case 0:
            row = 0;
            break;
        case 5:
            row = 1;
            r = 1;
            break;
        case 1:
            row = 2;
            break;
        case 6:
            row = 3;
            r = 1;
            break;
        case 2:
            row = 4;
            break;
        case 3:
            row = 4;
            break;
        case 7:
            row = 5;
            r = 1;
            break;
        case 8:
            row = 5;
            r = 1;
            break;
        case 4:
            row = 6;
            break;
        default:
            row = 0;
            break;
        }
        n = n - 1;
        if ((s16)n < 0)
            idx = 0;
        else if (n >= 10)
            idx = 9;
        else
            idx = n;
        if (((Bits *)(p + 0xC))->b1) {
            if (r == 1)
                r = 30;
            else
                r = 10;
        } else {
            r = d_021DACDC[row][idx];
        }
    }
    if (r == 0)
        r = 1;
    func_0200DA80(((struct Obj04291 *)p)->f74, r);
    return r;
}


/*
 * Fills the +0x32 halfword list with distinct draws: 14 for kinds 2, 3, 7, 8, else 7.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9E8C(u8 *p)
{
    u8 kind = p[9];
    u16 lim = func_021CA2CC(func_021CA234(p));
    int i;
    u16 v;

    if (kind == 2 || kind == 3 || kind == 7 || kind == 8) {
        if (lim < ((struct Obj05094 *)p)->f18)
            lim = ((struct Obj05094 *)p)->f18;
        for (i = 0; i < 14; i++) {
            do {
                v = func_021CBD90(p, lim, (u8)(i / 2), kind, (u8)(i & 1));
            } while (func_021CA2A4((u16 *)(p + 0x32), v, i));
            ((u16 *)(p + 0x32))[i] = v;
        }
    } else {
        for (i = 0; i < 7; i++) {
            do {
                v = func_021CBD90(p, lim, (u8)i, p[9], 0);
            } while (func_021CA2A4((u16 *)(p + 0x32), v, i));
            ((u16 *)(p + 0x32))[i] = v;
        }
    }
}


/*
 * Unless blocked, clamps each slot's +0x7c id to 1..6, copies it into +0x1e and reloads the slot's two stats.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C9F44(u8 *p, u32 x)
{
    void *h;
    u16 i;
    u8 *q;
    u32 m;

    if (((struct Obj00116 *)p)->f84 != 0 || ((struct Obj00116 *)p)->f82 == 7 || ((struct Obj00116 *)p)->f82 == 8)
        return 0;
    h = func_021CA210(p);
    for (i = 0; i < p[8]; i++) {
        q = p + i;
        if (q[0x7c] - 1 >= 6)
            q[0x7c] = 1;
        q[0x1e] = q[0x7c] - 1;
        m = (u32)func_0201AB28(h, q[0x1e]);
        ((Stats *)p)->a22[i] = func_02017E1C((void *)m, 5, 0);
        ((Stats *)p)->a2a[i] = func_02017E1C((void *)m, 6, 0);
    }
    return 1;
}


/*
 * Latches bit 0 of +0xc once the +0x70 object's count reaches 7.
 *
 * Addresses are Black-image addresses.
 */
int func_021C9FD0(u8 *p)
{
    if (((Latch *)p)->done == 0) {
        if (func_0200DA54((struct Blk3C *)(((struct Obj20232 *)p)->f70)) < 7)
            return 0;
        ((Latch *)p)->done = 1;
    }
    return 1;
}


/*
 * Commits the +0xe counter and the current kind's level and redraws.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9FFC(u8 *p, u32 x)
{
    u8 kind = p[9];
    u16 v = func_021CA234(p);

    func_0200DB08((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind, v);
    func_0200DAEC((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind, func_0200DAC4((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind));
    func_0200DB60((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind);
    func_021CA2DC(p, (u32)func_02012EBC((struct Big *)(*(u32 *)&((struct Obj00116 *)p)->f6C)), 1, v);
    func_0200DA14((struct Blk3C *)(((struct Obj00116 *)p)->f70));
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021CA048(u32 a, u32 b)
{
((struct Obj07233 *)((u8 *)(a)))->fC = (((struct Obj07233 *)((u8 *)(a)))->fC & ~1);
((struct Obj07233 *)((u8 *)(a)))->fC = (((struct Obj07233 *)((u8 *)(a)))->fC & ~6);
return a;
}


/*
 * Draws the current page of the +0x32 list through 0x021CBED8; kinds 2, 3, 7, 8 draw two pages with the slot tags.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA05C(u8 *p)
{
    u32 n = func_0200DA54((struct Blk3C *)(((struct Obj01671 *)p)->f70));
    int i;
    u32 j;
    u16 tags[2];
    u16 vals[2];

    switch (p[9]) {
    case 4:
        func_0200DEA8(((struct Obj01671 *)p)->f78, p + 0x88, n, ((struct Obj01671 *)p)->f4);
        return;
    case 2:
    case 3:
    case 7:
    case 8:
        i = 0;
        j = n * 2;
        func_021CBED8((u32)p, (u32)(p + 0x88), ((u16 *)(p + 0x32))[j], p[8], 0, 0, 0, ((struct Obj01671 *)p)->f4);
        for (; i < p[8]; i++) {
            tags[i] = ((Slot *)(p + 0xb8))[i].tag;
            vals[i] = ((Slot *)(p + 0xb8))[i].val;
        }
        func_021CBED8((u32)p, (u32)(p + 0x1a8), ((u16 *)(p + 0x32))[j + 1], p[8], (u32)tags, (u32)vals, 0, ((struct Obj01671 *)p)->f4);
        return;
    }
    func_021CBED8((u32)p, (u32)(p + 0x88), ((u16 *)(p + 0x32))[n], p[8], 0, 0, 0, ((struct Obj01671 *)p)->f4);
}


/*
 * Tail-calls into ov010 with the halfword at +0x8c of the 0x120-byte entry i.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CA150(u8 *p, int i)
{
    return func_02168AEC(*(u16 *)(p + i * 0x120 + 0x8c));
}


/*
 * Steps an arm9 object by mode (0, 3, 4) and reports whether it advanced.
 *
 * Addresses are Black-image addresses.
 */
int func_021CA164(void *a, int unused, int mode)
{
    u8 state = (int)func_0200DC08(a);
    u32 v;

    switch (mode) {
    case 0:
        return state;
    case 3:
        func_0200DBA0(a, 0, 2);
        if (state == 10)
            return 0;
        func_0200DBF0(a);
        return 1;
    case 4:
        v = func_0200DC0C(a, 3);
        if (state == 1)
            return 0;
        if (v >= data_021DACD0[state - 1]) {
            func_0200DBFC(a);
            func_0200DC0C(a, 2);
            func_0200DBA0(a, 0, 2);
            return 1;
        }
        return 0;
    }
    return 0;
}


/*
 * Releases the handle at +0x7c8 and allocates a fresh one from the object at +0x6c.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA1E4(u8 *p)
{
    if (((struct Obj07584 *)p)->f7C8 != 0)
        func_020307B0(((struct Obj07584 *)p)->f7C8);
    ((struct Obj07584 *)p)->f7C8 = func_0200BAF4((int)func_0200BAC8(func_02012EBC((struct Big *)(((struct Obj07584 *)p)->f6C))), 4);
}


/*
 * Returns the object at +0x6c's handle unless the query on +0x70 is set, then the cached +0x7c8.
 *
 * Addresses are Black-image addresses.
 */
void *func_021CA210(u8 *p)
{
    if (func_0200D884((struct Blk3C *)(((struct Obj00116 *)p)->f70), 10, 0) == 0)
        return func_02012934(((struct Obj00116 *)p)->f6C);
    return ((struct Obj00116 *)p)->f7C8;
}


/*
 * Loads the 16-bit halfword at +0xe of the object.
 */
u16 func_021CA234(u8 *p)
{
    return ((struct Obj18345 *)p)->fE;
}


/*
 * Field setter at +0xe.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA238(u8 *p, u16 v)
{
    ((struct Obj18346 *)p)->fE = v;
}
