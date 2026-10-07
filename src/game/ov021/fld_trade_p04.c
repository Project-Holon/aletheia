/*
 * file:     fld_trade_p04.c
 * unit:     yes
 * function: func_021CC810, func_021CC8B0, func_021CC8DC, func_021CC9A4, func_021CCA00, func_021CCB98
 * address:  0x021CC810
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
 *   func_021CCFC0  0x021CCFC0  thumb  ov021
 *   func_021CCFE4  0x021CCFE4  thumb  ov021
 *   func_021CCFF8  0x021CCFF8  thumb  ov021
 *   func_021CCEFC  0x021CCEFC  thumb  ov021
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_021CCF54  0x021CCF54  thumb  ov021
 *   func_021CCF48  0x021CCF48  thumb  ov021
 *   func_021CD1AC  0x021CD1AC  thumb  ov021
 *   func_021CCFD8  0x021CCFD8  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021DB404     0x021DB404  data  a2
 *   func_0204B3B4  0x0204B3B4  arm
 */
#include "../../matched/include/Obj06097.h"
#include "../../matched/include/Obj09731.h"

struct Obj_021CCA00;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Obj_021CC810 {
    u8 pad0[0xa4];
    u32 fA4;
    u8 padA8[0xbc - 0xa8];
    u32 fBC;
    u8 fC0;
    u8 fC1;
} Obj_021CC810;

typedef struct Obj_021CC8B0 {
    u8 pad0[0x10];
    u32 f10;
    u32 f14;
    u8 pad18[0xbc - 0x18];
    u32 fBC;
} Obj_021CC8B0;

typedef struct {
    u32 f0;
    void *f4;
    void *f8;
    u16 heap;
    u16 padE[(0x7C - 0xE) / 2];
    u16 f7C;
    u16 f7E;
    u16 f80[6];
    u16 f8C[6];
} Obj_021CC8DC;

typedef signed int     s32;

typedef struct {
    u16 x;
    u16 y;
    u16 f4;
    u16 f6;
} Pos;

typedef struct {
    u32 f0;
    void *f4;
    void *f8;
    u16 heap;
    u16 padE;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C[6];
    u32 f34[6];
    u32 pad4C[(0x7C - 0x4C) / 4];
    u16 f7C;
    u16 f7E;
    u16 f80[6];
    u16 f8C[6];
} Obj_021CCA00;

extern void func_021CCFC0(Obj_021CC810 *p);
extern int func_021CCFE4(u32 a, u32 b);
extern int func_021CCFF8(u8 *p);
extern void func_021CCEFC(u8 *p);
extern int func_0219049C(u8 *p);
extern u32 func_021CCF54(u8 *p);
extern void func_021CCF48(u8 *p);
extern void func_021CD1AC(Obj_021CC810 *p);
extern void func_021CCFD8(u8 *p);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *h, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_020185F0(void *p);
extern u32 func_0201BA68(void *mon);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *h);
extern void func_0204A8D4(u32 v);
extern void func_0204AFD8(u32 v);
extern void func_0204ADA4(u32 v);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u32 func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern struct Obj_021CCA00 *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B6F4(struct Obj_021CCA00 *o, u32 v, u32 flag);
extern void func_0204B3DC(struct Obj_021CCA00 *p, unsigned int v);
extern void func_0204B3B4(struct Obj *p);
int func_021CC810(Obj_021CC810 *p);
u32 func_021CC8B0(Obj_021CC8B0 *p, u32 *out);
void func_021CC8DC(Obj_021CC8DC *p);
void func_021CC9A4(u8 *p);
void func_021CCA00(Obj_021CCA00 *p);
void func_021CCB98(u8 *p);
extern Pos d_021DB404;


/*
 * Task state machine on the byte at +0xc0. The inner switch on an unsigned
 * result (cases 2, -2, -1) is what gives the compare order 2, -2, -1 and
 * the dead second -1 test.
 */
int func_021CC810(Obj_021CC810 *p)
{
    u32 r;

    switch (p->fC0) {
    case 0:
        func_021CCFC0(p);
        func_021CCFE4((u32)p, 3);
        p->fC0 = p->fC0 + 1;
        break;
    case 1:
        if (func_021CCFF8((u8 *)p) == 1) {
            func_021CCEFC((u8 *)p);
            p->fC0 = p->fC0 + 1;
        }
        break;
    case 2:
        if (func_0219049C((u8 *)p->fA4) == 1) {
            r = func_021CCF54((u8 *)p);
            if (r == -1)
                break;
            func_021CCF48((u8 *)p);
            func_021CD1AC(p);
            func_021CCFD8((u8 *)p);
            switch (r) {
            case 2:
            case -2:
                p->fBC = 2;
                p->fC0 = p->fC0 + 1;
                break;
            case -1:
                break;
            default:
                p->fBC = r;
                p->fC0 = p->fC0 + 1;
                break;
            }
        }
        break;
    default:
        p->fC1 = 1;
        return 1;
    }
    return 0;
}


u32 func_021CC8B0(Obj_021CC8B0 *p, u32 *out)
{
    u32 m;

    *out = 0;
    m = p->fBC;
    if (m == 0 && p->f10 == 1)
        *out = 1;
    else if (m == 1 && p->f14 == 1)
        *out = 1;
    return p->fBC;
}


void func_021CC8DC(Obj_021CC8DC *p)
{
    void *arc;
    int i;
    int n;

    arc = func_020490F4(7, p->heap);
    p->f7C = func_0204ACEC(arc, func_0201BC3C(), 0, 0x60, p->heap);
    p->f7E = func_0204AF28(arc, func_0201BC40(), func_0201BCB4(), p->heap);
    n = func_0201AA18(p->f4);
    for (i = 0; i < n; i++) {
        p->f80[i] = func_0204A6C8(arc, func_0201BA68((void *)func_020185F0(func_0201AB28(p->f4, i))), 0, 0, p->heap);
    }
    if (p->f8 != 0) {
        n = func_0201AA18(p->f8);
        for (i = 0; i < n; i++) {
            p->f8C[i] = func_0204A6C8(arc, func_0201BA68((void *)func_020185F0(func_0201AB28(p->f8, i))), 0, 0, p->heap);
        }
    }
    func_02049238(arc);
}


void func_021CC9A4(u8 *p)
{
    int i;
    int n;

    if (((struct Obj06097 *)p)->f8) {
        n = func_0201AA18(((struct Obj06097 *)p)->f8);
        for (i = 0; i < n; i++)
            func_0204A8D4(*(u16 *)(p + i * 2 + 0x8c));
    }
    n = func_0201AA18(((struct Obj06097 *)p)->f4);
    for (i = 0; i < n; i++)
        func_0204A8D4(*(u16 *)(p + i * 2 + 0x80));
    func_0204AFD8(((struct Obj06097 *)p)->f7E);
    func_0204ADA4(((struct Obj06097 *)p)->f7C);
}


void func_021CCA00(Obj_021CCA00 *p)
{
    Pos pos = d_021DB404;
    int n1;
    int n2;
    int i;
    void *mon;
    u32 s;
    u32 f;
    u32 e;
    u32 r;

    n1 = func_0201AA18(p->f4);
    for (i = 0; i < n1; i++) {
        pos.x = i * 0x28 + 0x18;
        p->f1C[i] = (u32)func_0204B294((void *)p->f18, p->f80[i], p->f7C, p->f7E, &pos, 0, p->heap);
        mon = func_0201AB28(p->f4, i);
        s = func_02017E1C(mon, 5, 0);
        f = func_02017E1C(mon, 0x6f, 0);
        e = (func_02017E1C(mon, 0xab, 0) == 0x28a) ? 1 : 0;
        r = func_0201BB5C(s, f, func_02017E1C(mon, 0x6e, 0), e);
        func_0204B6F4((struct Obj_021CCA00 *)p->f1C[i], (u8)r, 1);
        func_0204B3DC((struct Obj_021CCA00 *)p->f1C[i], 0);
    }
    if (p->f8 != 0) {
        n2 = func_0201AA18(p->f8);
        for (i = 0; i < n2; i++) {
            pos.x = i * 0x28 + 0x18;
            p->f34[i] = (u32)func_0204B294((void *)p->f18, p->f8C[i], p->f7C, p->f7E, &pos, 0, p->heap);
            mon = func_0201AB28(p->f8, i);
            s = func_02017E1C(mon, 5, 0);
            f = func_02017E1C(mon, 0x6f, 0);
            e = (func_02017E1C(mon, 0xab, 0) == 0x28a) ? 1 : 0;
            r = func_0201BB5C(s, f, func_02017E1C(mon, 0x6e, 0), e);
            func_0204B6F4((struct Obj_021CCA00 *)p->f34[i], (u8)r, 1);
            func_0204B3DC((struct Obj_021CCA00 *)p->f34[i], 0);
        }
    }
}


void func_021CCB98(u8 *p)
{
    int i;
    int n;

    n = func_0201AA18(((struct Obj09731 *)p)->f4);
    for (i = 0; i < n; i++)
        func_0204B3B4(*(void **)(p + i * 4 + 0x1c));
    if (((struct Obj09731 *)p)->f8) {
        n = func_0201AA18(((struct Obj09731 *)p)->f8);
        for (i = 0; i < n; i++)
            func_0204B3B4(*(void **)(p + i * 4 + 0x34));
    }
}
