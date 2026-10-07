/*
 * file:     vs_multi_list_p04.c
 * unit:     yes
 * function: func_021F6F3C, func_021F6F50, func_021F6F80, func_021F6F88, func_021F7108, func_021F714C, func_021F72BC, func_021F72DC, func_021F7308, func_021F734C
 * address:  0x021F6F3C
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A48C 0x0204A48C arm
 *   d_021F764C 0x021F764C data a4
 *   d_021F761C 0x021F761C data a4
 *   func_020490F4 0x020490F4 arm
 *   func_020185F4 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0201BABC 0x0201BABC thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCEC 0x0201BCEC thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0202775C 0x0202775C thumb
 *   func_02027758 0x02027758 thumb
 *   func_02027760 0x02027760 thumb
 *   func_02027764 0x02027764 thumb
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   d_021F76C8 0x021F76C8 data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0202C9B4 0x0202C9B4 thumb
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CEBC 0x0202CEBC thumb
 *   func_0202CAC4 0x0202CAC4 thumb
 *   func_0202CE50 0x0202CE50 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0204162C 0x0204162C arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020414EC 0x020414EC arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   d_021F78C0 0x021F78C0 data a4
 */
#include "../../matched/include/Obj00410.h"
#include "../../matched/include/Obj21993.h"
#include "../../matched/include/Obj21994.h"
#include "../../matched/include/Obj21995.h"
#include "../../matched/include/Obj21996.h"

struct Bank;
struct Obj;
struct Actor;
struct Vec2;
struct WinMgr;
struct Cfg { unsigned w[7]; };

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32_021F6F80;

struct T { u32 a, b, i, j, k; };

struct P_021F714C {
    u8 *parent;
    u8 pad04[0x4c];
    struct Bank *bank;
    union { struct Obj *all[24]; struct { struct Obj *a[6], *b[6], *c[6], *d[6]; } set; } actors;
    u32 tabA[9], tabB[4], tabC[4];
    void *mons[6];
};

struct PtS { short x, y; };

typedef signed int s32_021F734C;

struct Pair { void *data; u32 other; };

struct P_021F734C {
    u8 *parent; u32 pad04; struct WinMgr *window; u8 pad0c[20];
    struct Pair images[6]; u8 pad50[0xa8]; void *mons[6];
};

extern void func_0204A48C(const struct Cfg *, unsigned, unsigned);
extern void func_0204A5AC(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_020185F4(void *);
extern u32 func_0201BA68(void *);
extern u32 func_0201BABC(u32, u32, u32, u32);
extern int func_0204A6C8(void *, u32, u32, u32, u16);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *, u32, u32, u32, u16);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern int func_0204AF28(void *, u32, u32, u32);
extern void func_02049238(void *);
extern u32 func_020275E4(void);
extern int func_0204ABF0(void *, u32, u32, u32, u16);
extern int func_0202775C(int);
extern int func_02027758(void);
extern int func_02027760(int);
extern int func_02027764(int);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern struct Bank *func_0204B100(int, u8, u32);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *, u32);
extern void func_0204B92C(struct Obj *, u32);
extern int func_0201BBE8(void *);
extern void func_0204B6F4(struct Obj *, u32, u32);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_0202136C(u16);
extern void func_0204B8C4(struct Obj *, u32);
extern void func_0204B878(struct Obj *, u16);
extern void func_0204B3B4(struct Obj *);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern void func_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src);
extern void func_0202CE50(struct WinMgr *mgr, u32 idx, s32_021F734C x, s32_021F734C y, u8 w, u8 h, u8 pal);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern u32 func_0204162C(int);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern void func_020414EC(u32);
extern void MIi_CpuCopy16(const void *, void *, u32);
void func_021F6F3C(char *p);
void func_021F6F50(void);
void func_021F6F80(void);
void func_021F6F88(int p);
void func_021F7108(char *p);
void func_021F714C(struct P_021F714C *p);
void func_021F72BC(char *p);
void func_021F72DC(unsigned p, unsigned i, int dx);
void func_021F7308(int a, unsigned b, int c);
void func_021F734C(struct P_021F734C *p);
extern const struct Cfg d_021F764C;
extern const unsigned d_021F761C[];
extern const struct T d_021F76C8[];
extern const char d_021F78C0[];

void func_021F6F3C(char *p)
{
    func_021F72BC(p);
    func_021F7108(p);
    func_021F6F80();
}

void func_021F6F50(void)
{
    struct Cfg c = d_021F764C;
    func_0204A48C(&c, (unsigned)d_021F761C, 0x71);
}

void func_021F6F80(void) { func_0204A5AC(); }

static inline u32 IconBase(int obj)
{
    return (u32)&((struct Obj00410 *)obj)->fB4;
}

/*
 * lever: integer object base; the icon array address comes from a static
 * inline accessor of field fB4 (the inlined parameter and the result share
 * one spill slot: str p; adds #0xb4; str); merged icon is u16.
 * note 2026-10-05: replaced the stand-in `icons = p; icons = p + 0xb4;`
 * with the accessor IconBase(p). EXACT in --lang c99 and --lang c. An
 * accessor returning u32 * with icons[i] stores gives DIFF; one that copies
 * into a local and adds (r = obj; r += 0xb4) gives DIFF.
 */
void func_021F6F88(int p)
{
    u32 a, b;
    void *h;
    void *h2;
    u16 i, icon;
    u32 icons;
    h = func_020490F4(7, 0x8071);
    icons = IconBase(p);
    for (i = 0; i < 6; i++) {
        if (*(void **)(p + i * 4 + 0xf8) != 0)
            icon = func_0201BA68(func_020185F4(*(void **)(p + i * 4 + 0xf8)));
        else
            icon = func_0201BABC(0, 0, 0, 0);
        *(int *)(icons + i * 4) = func_0204A6C8(h, icon, 0, 0, 0x71);
    }
    *(int *)&((struct Obj00410 *)p)->fD8 = func_0204ACEC(h, func_0201BC3C(), 0, 0, 0x71);
    a = func_0201BC78();
    b = func_0201BCEC();
    *(int *)&((struct Obj00410 *)p)->fE8 = func_0204AF28(h, a, b, 0x71);
    func_02049238(h);
    h2 = func_020490F4(func_020275E4(), 0x8071);
    ((struct Obj00410 *)p)->fD0 = func_0204A6C8(h2, 0xc, 0, 0, 0x71);
    ((struct Obj00410 *)p)->fE0 = func_0204ABF0(h2, 0xb, 0, 0x60, 0x71);
    ((struct Obj00410 *)p)->fF0 = func_0204AF28(h2, 0xf, 0x12, 0x71);
    ((struct Obj00410 *)p)->fCC = func_0204A6C8(h2, 0x41, 0, 0, 0x71);
    ((struct Obj00410 *)p)->fDC = func_0204ABF0(h2, 0x42, 0, 0x80, 0x71);
    ((struct Obj00410 *)p)->fEC = func_0204AF28(h2, 0x45, 0x48, 0x71);
    ((struct Obj00410 *)p)->fD4 = func_0204A6C8(h2, func_0202775C(2), 0, 0, 0x71);
    ((struct Obj00410 *)p)->fE4 = func_0204ABF0(h2, func_02027758(), 0, 0xa0, 0x71);
    a = func_02027760(2);
    b = func_02027764(2);
    ((struct Obj00410 *)p)->fF4 = func_0204AF28(h2, a, b, 0x71);
    func_02049238(h2);
}


void func_021F7108(char *p)
{
    unsigned i;

    for (i = 0; i < 9; i++)
        func_0204A8D4(*(int *)(p + i * 4 + 0xb4));
    for (i = 0; i < 4; i++)
        func_0204ADA4(*(int *)(p + i * 4 + 0xd8));
    for (i = 0; i < 4; i++)
        func_0204AFD8(*(int *)(p + i * 4 + 0xe8));
}

/*
 * prototype: 0204B294 result stored at 021F719C despite owner void; 020185F4 preserves and returns live r0; 0204B8C4 visible r1=0 retained.
 */
void func_021F714C(struct P_021F714C *p)
{
    u32 i;
    u16 species;
    p->bank = func_0204B100(24, 0, 0x71);
    for (i = 0; i < 24; i++) {
        p->actors.all[i] = func_0204B294(p->bank,
            p->tabA[d_021F76C8[i].i],
            p->tabB[d_021F76C8[i].j],
            p->tabC[d_021F76C8[i].k], &d_021F76C8[i], 0, 0x71);
    }
    for (i = 0; i < 6; i++) {
        if (p->mons[i] == 0) {
            func_0204B3DC(p->actors.set.a[i], 0);
            func_0204B3DC(p->actors.set.b[i], 0);
            func_0204B3DC(p->actors.set.d[i], 0);
        } else {
            func_0204B92C(p->actors.set.a[i], 1);
            func_0204B6F4(p->actors.set.a[i], func_0201BBE8(func_020185F4(p->mons[i])), 1);
            species = func_02017E1C(p->mons[i], 6, 0);
            if (species == 0) func_0204B3DC(p->actors.set.b[i], 0);
            else if (func_0202136C(species) == 1) {
                func_0204B8C4(p->actors.set.b[i], 0);
                func_0204B878(p->actors.set.b[i], 1);
            } else {
                func_0204B8C4(p->actors.set.b[i], 0);
                func_0204B878(p->actors.set.b[i], 0);
            }
        }
        func_0204B3DC(p->actors.set.c[i], 0);
    }
    if (((struct Obj21993 *)(p->parent))->f8 == 0) {
        for (i = 0; i < 3; i++) {
            func_021F72DC((unsigned int)p, i + 3, 128);
            func_021F72DC((unsigned int)p, i + 9, 128);
            func_021F72DC((unsigned int)p, i + 15, 128);
            func_021F72DC((unsigned int)p, i + 21, 128);
        }
    } else {
        for (i = 0; i < 3; i++) {
            func_021F72DC((unsigned int)p, i, -128);
            func_021F72DC((unsigned int)p, i + 6, -128);
            func_021F72DC((unsigned int)p, i + 12, -128);
            func_021F72DC((unsigned int)p, i + 18, -128);
        }
    }
}

void func_021F72BC(char *p)
{
    unsigned i;
    for (i = 0; i < 24; i++)
        func_0204B3B4(*(struct Obj **)(p + i * 4 + 0x54));
    func_0204B1CC(*(struct Bank * *)&((struct Obj21994 *)p)->f50);
}

void func_021F72DC(unsigned p, unsigned i, int dx)
{
    struct PtS pt;
    unsigned base = p + 0x54;
    func_0204B454(*(struct Actor **)(base + i * 4), &pt, 0);
    pt.x = pt.x + dx;
    func_0204B404((struct Obj *)(*(struct Actor **)(base + i * 4)), (const struct Vec2 *)(&pt), 0);
}


void func_021F7308(int a, unsigned b, int c)
{
    unsigned i;

    for (i = b; i < b + 3; i++) {
        func_021F72DC(a, i, c);
        func_021F72DC(a, i + 6, c);
        func_021F72DC(a, i + 12, c);
        func_021F72DC(a, i + 18, c);
    }
}

void func_021F734C(struct P_021F734C *p)
{
    u16 i;
    u8 *palette, *buf;
    p->window = func_0202C9B4(2, 12, 0x71);
    for (i = 0; i < 6; i++) {
        func_0202CA3C(p->window, i, 1, 16, 6);
        func_0202CA3C(p->window, i + 6, 0, 16, 6);
        func_0202CEBC(p->window, i + 6, p->images[i].data);
    }
    palette = (u8 *)func_0204162C(1);
    buf = func_02030734(0x8071, 0xc0, 0, d_021F78C0, 0x606);
    for (i = 0; i < 6; i++) MIi_CpuCopy16(palette + i * 64, buf + i * 32, 32);
    for (i = 0; i < 6; i++) if (p->mons[i]) func_0202CAC4(p->window, i, buf);
    for (i = 0; i < 6; i++) MIi_CpuCopy16(palette + (i + 18) * 64, buf + i * 32, 32);
    for (i = 0; i < 6; i++) if (!p->mons[i]) func_0202CAC4(p->window, i, buf);
    func_020307B0(buf);
    func_020414EC(1);
    if (((struct Obj21995 *)(p->parent))->f8 == 0) {
        for (i = 3; i < 6; i++) if (p->mons[i]) func_0202CE50(p->window, i, 0, 0, 16, 6, 5);
    } else {
        for (i = 0; i < 3; i++) if (p->mons[i]) func_0202CE50(p->window, i, 0, 0, 16, 6, 5);
    }
    if (((struct Obj21996 *)(p->parent))->f8 == 0) {
        func_0202CB4C(p->window, 0, 0, 0);
        func_0202CB4C(p->window, 1, 0, 6);
        func_0202CB4C(p->window, 2, 0, 12);
        func_0202CB4C(p->window, 6, 0, 0);
        func_0202CB4C(p->window, 7, 0, 6);
        func_0202CB4C(p->window, 8, 0, 12);
        func_0202CB4C(p->window, 3, 32, 1);
        func_0202CB4C(p->window, 4, 32, 7);
        func_0202CB4C(p->window, 5, 32, 13);
        func_0202CB4C(p->window, 9, 32, 1);
        func_0202CB4C(p->window, 10, 32, 7);
        func_0202CB4C(p->window, 11, 32, 13);
    } else {
        func_0202CB4C(p->window, 0, -16, 0);
        func_0202CB4C(p->window, 1, -16, 6);
        func_0202CB4C(p->window, 2, -16, 12);
        func_0202CB4C(p->window, 6, -16, 0);
        func_0202CB4C(p->window, 7, -16, 6);
        func_0202CB4C(p->window, 8, -16, 12);
        func_0202CB4C(p->window, 3, 16, 1);
        func_0202CB4C(p->window, 4, 16, 7);
        func_0202CB4C(p->window, 5, 16, 13);
        func_0202CB4C(p->window, 9, 16, 1);
        func_0202CB4C(p->window, 10, 16, 7);
        func_0202CB4C(p->window, 11, 16, 13);
    }
}
