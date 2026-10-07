/*
 * file:     btl_server_p42.c
 * unit:     yes
 * function: func_021C0404, func_021C0450, func_021C0520
 * address:  0x021C0404
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D7AF0  0x021D7AF0  thumb  ov093
 *   func_021C557C  0x021C557C  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021C63D0 0x021C63D0 thumb ov093
 *   func_021C4F64 0x021C4F64 thumb ov093
 *   func_021BC2B0 0x021BC2B0 thumb ov093
 *   func_021D7D18 0x021D7D18 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C5C1C 0x021C5C1C thumb ov093
 *   func_021C5480 0x021C5480 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C6564 0x021C6564 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C5604 0x021C5604 thumb ov093
 */
#include "../../matched/include/Obj00003.h"

struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

union Slot { u32 raw; struct { u32 kind:3; u32 lo:6; u32 hi:6; u32 rest:17; } s; };

struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };

extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_0201BEB8(void *bag, int item);
extern int func_021D7AF0(u32 pct);
extern void func_021C557C(u8 *p, u8 *a, int k, int flag);
extern u32 func_021C63D0(u8 *, u8 *);
extern int func_021C4F64(u8 *, u8 *);
extern int func_021BC2B0(u8 *);
extern union Slot func_021D7D18(int);
extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C5C1C(u8 *, u8 *, int, union Slot);
extern void func_021C5480(u8 *, u8 *, int);
extern u32 func_021CC8D8(void *, int);
extern void func_021C6564(u8 *, u8 *, u32, u32);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021CD64C(void *, u8, ...);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u32 func_021D78AC(u32 range);
extern void func_021C5604(u8 *p, u8 *a, int b);
int func_021C0404(u8 *p, u8 *a, void *bag);
void func_021C0450(u8 *p, u8 *q, u16 c, int k);
void func_021C0520(u8 *p, u8 *a, u16 b, u32 c);

int func_021C0404(u8 *p, u8 *a, void *bag)
{
    int k = func_021D62A8((struct Unk021D62A8 *)a);
    int f = 0;
    int r = 0;
    if (k == 3) {
        if (func_0201BEB8(bag, 10) != 0) {
            r = 1;
        } else if (func_021D7AF0(20) != 0) {
            f = 1;
        }
    }
    if (f != 0) {
        func_021C557C(p, a, k, 1);
    }
    return r;
}

/*
 * lever: Raw u32 lock return avoids an aggregate frame word; Slot remains a one-word aggregate.
 */
void func_021C0450(u8 *p, u8 *q, u16 c, int k)
{
    u32 old;
    if (k == 5) {
        func_021C63D0(p, q);
        if (func_021C4F64(p, q) && func_021BC2B0(p)) return;
    } else {
        func_021C0520(p, q, c, k);
        switch (k) {
        case 2: func_021C5480(p, q, 598); break;
        case 3: func_021C5480(p, q, 602); break;
        case 4: func_021C5480(p, q, 601); break;
        case 23: {
            union Slot s = func_021D7D18(2);
            func_021CD4B0(((struct Obj00003 *)p)->fC, 49, func_021D5440(q), 0);
            func_021C5C1C(p, q, 2, s);
            func_021C5480(p, q, 598);
            break;
        }
        }
    }
    old = func_021CC8D8(p + 0x1d74, 5728);
    func_021C6564(p, q, c, k);
    func_021CC95C((u32 *)(p + 0x1d74), old, 5730);
}

/*
 * lever: a u8 local for the random result narrows in r0 before copying to r2.
 */
void func_021C0520(u8 *p, u8 *a, u16 b, u32 c)
{
    u32 id = func_021D5440(a);
    switch (c) {
    case 2: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x135, id, 0xffff0000); break;
    case 3: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x114, id, 0xffff0000); break;
    case 4: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x123, id, 0xffff0000); break;
    case 6: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x16b, id, 0xffff0000); break;
    case 7: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x16e, id, 0xffff0000); break;
    case 8: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x150, id, 0xffff0000); break;
    case 9: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x253, id, b, 0xffff0000); break;
    case 18: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x1bd, id, 0xffff0000); break;
    case 10: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x23b, id, b, 0xffff0000); break;
    case 11: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x244, id, b, 0xffff0000); break;
    case 12: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x24d, id, b, 0xffff0000); break;
    case 13: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x37a, id, b, 0xffff0000); break;
    case 14: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x37d, id, 0xffff0000); break;
    case 15:
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x57, id);
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x1c3, id, 0xffff0000);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x58, id);
        break;
    case 20: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x43e, id, b, 0xffff0000); break;
    case 22:
        if (func_021D62C4((struct Unk021D62A8 *)a, 2) != 0) {
            func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0xc2, id, 0xffff0000);
        } else {
            u8 rand = func_021D78AC(4);
            func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, rand + 0xbc, id, 0xffff0000);
        }
        break;
    case 23: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0xc1, id, 0xffff0000); break;
    case 1:
        func_021C5604(p, a, b);
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0x52, id, 0xffff0000);
        break;
    default: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0x47, id, 0xffff0000); break;
    case 19:
    case 25:
        break;
    }
}
