/*
 * file:     beacon_view_p17.c
 * unit:     yes
 * function: func_021F254C, func_021F2588, func_021F25D4, func_021F2608, func_021F2624, func_021F2664, func_021F2674, func_021F26D8, func_021F26F0, func_021F2714, func_021F27B4, func_021F27CC, func_021F27D4, func_021F28DC, func_021F2908, func_021F2A04
 * address:  0x021F254C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0201235C 0x0201235C thumb
 *   func_021F05E8 0x021F05E8 thumb ov032
 *   func_021F0668 0x021F0668 thumb ov032
 *   func_020310C4 0x020310C4 arm
 *   func_0202822C 0x0202822C thumb
 *   func_02028178 0x02028178 thumb
 *   func_02028230 0x02028230 thumb
 *   func_020282A4 0x020282A4 thumb
 *   func_02021D50 0x02021D50 thumb
 *   func_021F00C8 0x021F00C8 thumb ov032
 *   func_021F0078 0x021F0078 thumb ov032
 *   func_021EFF7C 0x021EFF7C thumb ov032
 *   func_021F0114 0x021F0114 thumb ov032
 *   func_021F0140 0x021F0140 thumb ov032
 *   func_021F02C4 0x021F02C4 thumb ov032
 *   func_021F067C 0x021F067C thumb ov032
 *   func_021F0050 0x021F0050 thumb ov032
 *   func_021F029C 0x021F029C thumb ov032
 *   func_021F028C 0x021F028C thumb ov032
 *   func_021F03EC 0x021F03EC thumb ov032
 *   func_021F0438 0x021F0438 thumb ov032
 *   func_02012A54  0x02012A54  thumb
 *   func_020275A8  0x020275A8  thumb
 *   func_02165B04  0x02165B04  thumb  ov010
 *   func_020275AC  0x020275AC  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF10  0x0200BF10  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   func_02008730  0x02008730  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02165B2C  0x02165B2C  thumb  ov010
 *   func_02165B10  0x02165B10  thumb  ov010
 *   func_02010F7C  0x02010F7C  thumb
 *   func_021F0684  0x021F0684  thumb  ov032
 *   func_02165940 0x02165940 thumb ov010
 *   func_02010F8C 0x02010F8C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0203101C  0x0203101C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_0201C4C8  0x0201C4C8  thumb
 *   func_0201C4DC  0x0201C4DC  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_0201DD68  0x0201DD68  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02031140 0x02031140 arm
 */
#include "../../matched/include/Obj07639.h"
#include "../../matched/include/Obj09800.h"
#include "../../matched/include/Obj13067.h"
#include "../../matched/include/Obj00188.h"
#include "../../matched/include/Obj00007.h"
#include "../../matched/include/Obj05123.h"
#include "../../matched/include/Obj00812.h"

struct Desc;
struct Obj;
struct S0201235C;
struct Tcbl;
struct S02021D50;
struct Big;
struct BigObj;
struct Blk34;
struct Ctx;
struct Rec1B0;
struct Sub0200852CObj;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PalAnmSlot;
struct PrintSys;
struct Node;
struct Rec;
struct S02031140;
typedef struct { void *f00; void *f04; unsigned f08; void *f0c; void *f10; } Desc;

typedef struct { int state; void *f04; unsigned f08; void *owner; unsigned f10; unsigned f14; unsigned f18; } Work;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern void func_021F05E8(u8 *, int, u32);
extern int func_021F0668(char *p, int i);
extern void func_020310C4(struct Tcbl *);
extern void func_0202822C(char *p, int v);
extern void func_02028178(u8 *p);
extern u32 func_02028230(u8 *p);
extern void func_020282A4(struct Obj *obj);
extern void func_02021D50(struct S02021D50 *);
extern int func_021F00C8(char *);
extern int func_021F0078(char *);
extern int func_021EFF7C(u8 *p);
extern int func_021F0114(u8 *p);
extern int func_021F0140(u8 *p);
extern int func_021F02C4(u8 *);
extern void func_021F067C(char *p);
extern int func_021F0050(unsigned char *p);
extern void func_021F029C(char *, int);
extern void func_021F028C(unsigned char *p);
extern int func_021F03EC(u8 *);
extern int func_021F0438(u8 *p);
extern u32 func_02012A54(const struct BigObj *p);
extern u32 func_020275A8(u32 a);
extern u8 func_02165B04(u8 *q);
extern u8 func_020275AC(u8 *p);
extern signed char func_02012FFC(void);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern u8 func_0200BF10(struct Rec1B0 *p);
extern u32 func_02012138(const struct Ctx *p);
extern u32 func_0201283C(const struct BigObj *p);
extern void *func_0201292C(const struct BigObj *p);
extern void *func_0200C0E8(void *sys);
extern u32 func_0200C1DC(struct Blk34 *p);
extern struct Sub0200852CObj *func_02008730(void *sys);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 *func_02165B2C(u32 heap);
extern u8 *func_02165B10(u32 heap);
extern void *func_02010F7C(u32 heap);
extern void func_021F0684(u8 *p, u8 *a, u8 *b);
extern void func_02165940(unsigned char *p);
extern void func_02010F8C(void *);
extern u32 func_020307B0(void *p);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_020056A0(void *fn, void *ctx, u32 a);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern u32 func_0201C440(void *p);
extern void func_0201C4C8(struct PrintSys *p, u32 v);
extern void func_0201C4DC(struct PrintSys *p, u32 lo, u32 hi);
extern u32 func_02188C54(u8 *p);
extern u32 func_021904AC(u8 *p);
extern void func_0201DD68(void);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_02030EAC(struct Node *n);
extern void func_02031140(struct S02031140 *p);
Desc *func_021F254C(char *p, unsigned a, unsigned b, unsigned c);
int func_021F2588(int a0, int a1, int *st);
int func_021F25D4(u8 *p, int *st);
int func_021F2608(char *p, int *unused);
int func_021F2624(int a0, int *st);
void func_021F2664(int a, char *p);
int func_021F2674(char *p);
int func_021F26D8(u8 *p);
int func_021F26F0(u8 *p);
int func_021F2714(char *p);
int func_021F27B4(u8 *p);
int func_021F27CC(char *p);
void func_021F27D4(u8 *p);
void func_021F28DC(char *p);
void func_021F2908(char *p);
void func_021F2A04(char *p);

Desc *func_021F254C(char *p, unsigned a, unsigned b, unsigned c)
{
    Desc *d;
    Work *w;
    d = (Desc *)func_020122C0(((struct Obj07639 *)p)->f0, 0, func_021F2588, 0x1c);
    w = func_020124E8((struct Obj *)d);
    w->owner = p;
    w->f04 = ((struct Obj07639 *)p)->f0;
    w->f08 = ((struct Obj07639 *)p)->f8;
    w->f10 = a;
    w->f14 = b;
    w->f18 = c;
    ((struct Obj07639 *)p)->f72 = 1;
    return d;
}


int func_021F2588(int a0, int a1, int *st)
{
    int r;
    char *o;

    r = 0;
    o = (char *)st[3];
    switch (st[5]) {
    case 0:
        r = func_021F25D4((u8 *)o, st);
        break;
    case 1:
        r = func_021F2608(o, st);
        break;
    case 2:
        r = func_021F2624((int)o, st);
        break;
    }
    if (r) {
        ((struct Obj09800 *)o)->f72 = 0;
        func_0201235C((struct S0201235C *)a0, (u32 *)st[4]);
    }
    return 0;
}

int func_021F25D4(u8 *p, int *st)
{
    switch (st[0]) {
    case 0:
        func_021F05E8(p, st[6], 1);
        st[0]++;
        return 0;
    case 1:
        if (func_021F0668((char *)p, st[6]) != 0)
            return 0;
        break;
    }
    return 1;
}

int func_021F2608(char *p, int *unused)
{
    func_020310C4(*(struct Tcbl * *)&((struct Obj09800 *)p)->fA0);
    if (((struct Obj09800 *)p)->fA8 == 0)
        return 1;
    return 0;
}


int func_021F2624(int a0, int *st)
{
    int h = st[6];

    switch (st[0]) {
    case 0:
        func_0202822C((char *)h, 1);
        st[0]++;
        break;
    case 1:
        func_02028178((u8 *)h);
        if (func_02028230((u8 *)h)) {
            func_020282A4((struct Obj *)h);
            return 1;
        }
        break;
    }
    return 0;
}

void func_021F2664(int a, char *p)
{
    if (*(struct S02021D50 * *)&((struct Obj13067 *)p)->fAC)
        func_02021D50(*(struct S02021D50 * *)&((struct Obj13067 *)p)->fAC);
}


int func_021F2674(char *p)
{
    int r;

    if (func_021F00C8(p)) {
        ((struct Obj00188 *)p)->f74 = 90;
        return 2;
    }
    if (func_021F0078(p)) {
        return 0;
    }
    r = func_021EFF7C((u8 *)p);
    if (r == 0) {
        if (((struct Obj00188 *)p)->f74 != 0) {
            ((struct Obj00188 *)p)->f74 = ((struct Obj00188 *)p)->f74 - 1;
            return 0;
        }
        if (func_021F0114((u8 *)p) == 1) {
            ((struct Obj00188 *)p)->f74 = 90;
            return 2;
        }
        if (func_021F0140((u8 *)p) == 0) {
            return 0;
        }
        ((struct Obj00188 *)p)->f74 = 90;
        return 1;
    }
    return r;
}

int func_021F26D8(u8 *p)
{
    if (func_021F02C4(p) == 0)
        return 1;
    ((struct Obj00007 *)p)->f6C = 0;
    return 2;
}

int func_021F26F0(u8 *p)
{
    if (((struct Obj00007 *)p)->fA8 != 0)
        return 2;
    func_021F05E8(p, 4, 0);
    func_021F067C((char *)p);
    return 0;
}


/*
 * note:     func_021F05E8 takes three arguments (its own matched file); the
 *           cleared zero is shared with its third argument, which is what
 *           puts the zero in r2 for the three stores.
 */
int func_021F2714(char *p)
{
    int r;

    if (((struct Obj00007 *)p)->f82 == 0) {
        r = func_021F0050((unsigned char *)p);
        if (r != ((struct Obj00007 *)p)->f84 || r == -1) {
            ((struct Obj00007 *)p)->f82 = 1;
        }
        ((struct Obj00007 *)p)->f88 = ((struct Obj00007 *)p)->f88 + 1;
    }
    if (((struct Obj00007 *)p)->f82 != 0) {
        if (((struct Obj00007 *)p)->fA8 > 0) {
            return 3;
        }
        ((struct Obj00007 *)p)->f82 = 0;
        ((struct Obj00007 *)p)->f88 = 0;
        ((struct Obj00007 *)p)->f81 = 0;
        if (((struct Obj00007 *)p)->f83 == 0) {
            func_021F05E8((u8 *)p, 4, 0);
        }
        func_021F067C(p);
        func_021F029C(p, 0);
        return ((struct Obj00007 *)p)->f83;
    }
    if (((struct Obj00007 *)p)->fA8 == 0) {
        func_021F028C((unsigned char *)p);
    }
    return 3;
}

/*
 * note: extent follower 0x021F27CC is already filed separately.
 */
int func_021F27B4(u8 *p)
{
    if (func_021F03EC(p) == 0)
        return 4;
    ((struct Obj00007 *)p)->f6C = 0;
    return 0;
}


int func_021F27CC(char *p)
{
    return func_021F0438((u8 *)p);
}


/*
 *           wildcarded because their targets are unlabelled arm9 leaves with no
 *           caller outside this range (Ilias's, inside arm9). Each was verified
 *           EXACT with `one --thumb` and no --region:
 *             0x020275A8  u32 func_020275A8(u32 a) { return a; }
 *             0x020275AC  u8 func_020275AC(u8 *p) { return p[0xb0e]; }
 *             0x02010F7C  u32 func_02010F7C(u32 heap)
 *                         { return func_02048F60(0x26, 0, heap); }
 *                         (func_02048F60 0x02048F60 arm, a tail call)
 *           Once those three are matched in arm9, this file is EXACT as it stands.
 *           The min of p[0x7b] and 4 must be an if/else of two stores: the
 *           ternary inverts the branch (blo for bhs; b).
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/func_020275A8,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 */
void func_021F27D4(u8 *p)
{
    u32 sv;
    u32 s2;

    *(u32 *)(p + 0x34) = func_02012A54((const struct BigObj *)(*(u32 *)(p + 4)));
    *(u32 *)(p + 0x3c) = func_020275A8(*(u32 *)(p + 0x34));
    p[0x7b] = func_02165B04((u8 *)(*(u32 *)(p + 0x3c)));
    p[0x7c] = func_020275AC((u8 *)(*(u32 *)(p + 0x34)));
    if (p[0x7b] < 4)
        p[0x7d] = p[0x7b];
    else
        p[0x7d] = 4;
    p[0x7f] = 0x30;
    p[0x78] = func_02012FFC();
    sv = (u32)func_02012EBC((struct Big *)(*(u32 *)(p + 4)));
    *(u32 *)(p + 0x28) = func_0200BF10((struct Rec1B0 *)func_0200BE48((void *)sv));
    *(u32 *)(p + 0x1c) = func_02012138((const struct Ctx *)(*(u32 *)p));
    *(u32 *)(p + 0x20) = func_0201283C((const struct BigObj *)(*(u32 *)(p + 4)));
    *(u32 *)(p + 0x18) = (u32)func_0201292C((const struct BigObj *)(*(u32 *)(p + 4)));
    *(u32 *)(p + 0x14) = (u32)func_0200C0E8((void *)sv);
    *(u32 *)(p + 0x2d4) = func_0200C1DC((struct Blk34 *)(*(u32 *)(p + 0x14)));
    s2 = (u32)func_02008730((void *)sv);
    *(u32 *)(p + 0x2c) = (u16)func_02008530((const struct Sub0200852CObj *)s2);
    p[0x30] = func_02008550((const struct Sub0200852CObj *)s2);
    p[0x31] = func_02008554((const struct Sub0200852CObj *)s2);
    p[0x32] = 0x15;
    *(u32 *)(p + 0x38) = (u32)func_02165B2C(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x40) = (u32)func_02165B10(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x44) = (u32)func_02165B10(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x4c) = (u32)func_02165B10(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x24) = (u32)func_02010F7C(*(u16 *)(p + 0x98));
    func_021F0684(p, p + 0x58, p + 0x59);
}

/*
 * note: two alignment padding bytes at 0x021F2906 follow the body.
 */
void func_021F28DC(char *p)
{
    func_02165940(((struct Obj05123 *)p)->f38);
    func_02010F8C(((struct Obj05123 *)p)->f24);
    func_020307B0(((struct Obj05123 *)p)->f4C);
    func_020307B0(((struct Obj05123 *)p)->f44);
    func_020307B0(((struct Obj05123 *)p)->f40);
    func_020307B0(((struct Obj05123 *)p)->f38);
}


void func_021F2908(char *p)
{
    ((struct Obj00007 *)p)->fA0 = func_0203101C(((struct Obj00007 *)p)->f98, ((struct Obj00007 *)p)->f98, 0x10, 0x80);
    ((struct Obj00007 *)p)->fA4 = func_020056A0((void *)func_021F2664, p, 0);
    ((struct Obj00007 *)p)->fAC = (u32)func_02021518(((struct Obj00007 *)p)->f98);
    func_0202155C((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), 1, 0x1c0, ((struct Obj00007 *)p)->f98);
    func_0202155C((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), 3, 0x200, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->fB4 = func_0201C440((void *)(((struct Obj00007 *)p)->f98));
    func_0201C4C8((struct PrintSys *)(((struct Obj00007 *)p)->fB4), 1);
    func_0201C4DC((struct PrintSys *)(((struct Obj00007 *)p)->fB4), 0x1f4, 0);
    ((struct Obj00007 *)p)->fB0 = func_021904AC((u8 *)func_02188C54((u8 *)(*(u32 *)&((struct Obj00007 *)p)->f8)));
    func_0201DD68();
    ((struct Obj00007 *)p)->f110 = func_0201EC64(((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f114 = func_02045B38(1, 2, 8, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f118 = func_020457B0(0xd9, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f11C = func_020457B0(0xd9, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f120 = func_020457B0(0xd9, ((struct Obj00007 *)p)->f98);
}


void func_021F2A04(char *p)
{
    func_02045808((struct U16Vec *)(((struct Obj00812 *)p)->f120));
    func_02045808((struct U16Vec *)(((struct Obj00812 *)p)->f11C));
    func_02045808((struct U16Vec *)(((struct Obj00812 *)p)->f118));
    func_02045C04((struct Rec *)(((struct Obj00812 *)p)->f114));
    func_0201ED04((struct WordSet *)(((struct Obj00812 *)p)->f110));
    func_0201C6EC((struct PrintSys *)(((struct Obj00812 *)p)->fB4));
    func_0201C4C0((struct PrintSys *)(((struct Obj00812 *)p)->fB4));
    func_0201DD68();
    func_020215A0((struct PalAnmSlot *)(((struct Obj00812 *)p)->fAC), 3);
    func_020215A0((struct PalAnmSlot *)(((struct Obj00812 *)p)->fAC), 1);
    func_02021540((void *)(((struct Obj00812 *)p)->fAC));
    ((struct Obj00812 *)p)->fAC = 0;
    func_02030EAC((struct Node *)(((struct Obj00812 *)p)->fA4));
    func_02031140((struct S02031140 *)(*(int *)&((struct Obj00812 *)p)->fA0));
}
