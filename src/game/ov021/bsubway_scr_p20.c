/*
 * file:     bsubway_scr_p20.c
 * unit:     yes
 * function: func_021CA23C, func_021CA250, func_021CA258, func_021CA270, func_021CA2A4, func_021CA2CC, func_021CA2DC, func_021CA338, func_021CA3B4
 * address:  0x021CA23C
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
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_021CA4C0  0x021CA4C0  thumb
 *   func_0200D914  0x0200D914  thumb
 *   func_0200DA54  0x0200DA54  thumb
 *   func_0200DC94  0x0200DC94  thumb
 *   func_021CBED8  0x021CBED8  thumb
 *   func_02017E1C  0x02017E1C  thumb
 */
#include "../../matched/include/Obj12970.h"
#include "../../matched/include/Obj18347.h"
#include "../../matched/include/Obj00116.h"
#include "../../matched/include/Obj09722.h"

struct Blk1AC;
struct Blk3C;
struct Src;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u8 pad[0xe]; u16 fE; } P;

typedef struct {
    u16 species : 11;
    u16 form    : 5;
    u16 item;
    u16 moves[4];
    u32 f0c;
    u32 f10;
    u32 f14;
    u8  f18[6];
    u8  ppups;
    u8  f1f;
    u8  f20;
    u8  f21;
    u16 name[13];
} Slot;

extern int func_0209C0A4(int a, int b);
extern void func_021CA4C0(u8 *p, u32 unused, int flag);
extern void func_0200D914(struct Blk3C *p, u32 id, const void *src);
extern u16 func_0200DA54(struct Blk3C *p);
extern void func_0200DC94(struct Blk1AC *p, const struct Src *q);
extern u8 func_021CBED8(u8 *p, u8 *list, u16 v, u8 n, u16 *a, u16 *b, u8 *e, u16 id);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
void func_021CA23C(u8 *p);
int func_021CA250(u32 a);
void func_021CA258(P *p, u32 a, u32 b);
int func_021CA270(u16 kind);
int func_021CA2A4(const u16 *arr, u16 val, u16 n);
u16 func_021CA2CC(u16 v);
void func_021CA2DC(u8 *p, u32 h, int flag, u16 v);
void func_021CA338(u8 *p, u8 alt);
void func_021CA3B4(Slot *s, u32 m);


/*
 * Saturating increment of the halfword counter at +0xe.
 * Addresses are Black-image addresses.
 */
void func_021CA23C(u8 *p)
{
    u16 v = ((struct Obj12970 *)p)->fE;
    if (v < 0xffff)
        ((struct Obj12970 *)p)->fE = v + 1;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021CA250(u32 a)
{
((struct Obj18347 *)((u8 *)(a)))->fE = 0;
return a;
}

void func_021CA258(P *p, u32 a, u32 b)
{
    u32 v = a * 7;
    v += b;
    if (v > 0xffff)
        v = 0xffff;
    p->fE = v;
}


int func_021CA270(u16 kind)
{
    switch (kind) {
    case 0:
    case 4:
    case 5:
        return 3;
    case 1:
    case 6:
        return 4;
    case 2:
    case 3:
    case 7:
    case 8:
        return 2;
    }
    return 0;
}


/*
 * Linear search of a halfword array.
 * Addresses are Black-image addresses.
 */
int func_021CA2A4(const u16 *arr, u16 val, u16 n)
{
    u16 i;
    for (i = 0; i < n; i++) {
        if (val == arr[i])
            return 1;
    }
    return 0;
}


u16 func_021CA2CC(u16 v)
{
return (u16)func_0209C0A4(v, 7);
}


void func_021CA2DC(u8 *p, u32 h, int flag, u16 v)
{
    u8 b;

    switch (p[9]) {
    case 0:
        func_021CA4C0(p, h, 0);
        break;
    case 1:
        break;
    case 4:
        func_021CA4C0(p, h, 1);
        b = p[9];
        func_0200D914((struct Blk3C *)(((struct Obj00116 *)p)->f70), 0, &b);
        b = func_0200DA54((struct Blk3C *)(((struct Obj00116 *)p)->f70)) + 1;
        func_0200D914((struct Blk3C *)(((struct Obj00116 *)p)->f70), 1, &b);
        func_0200DC94((struct Blk1AC *)(((struct Obj00116 *)p)->f74), (const struct Src *)(((struct Obj00116 *)p)->f70));
        break;
    }
}


/*
 * Draws the three +0x628 entries through 0x021CBED8 and stores each result byte at +0x664.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA338(u8 *p, u8 alt)
{
    int base = 300;
    int i;

    if (alt)
        base += 3;
    for (i = 0; i < 3; i++)
        p[0x664 + i] = func_021CBED8(p, p + 0x2c8 + i * 0x120, base + i, p[8],
                                     (u16 *)(p + 0x22), (u16 *)(p + 0x2a),
                                     p + 0x628 + i * 0x14, ((struct Obj09722 *)p)->f4);
}


/*
 * Packs one party member into a 0x3c-byte slot: species/form, item, four moves with their PP-up bits, ids, stats and nickname.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA3B4(Slot *s, u32 m)
{
    int i;

    s->species = func_02017E1C((void *)m, 5, 0);
    s->form = func_02017E1C((void *)m, 0x6f, 0);
    s->item = func_02017E1C((void *)m, 6, 0);
    for (i = 0; i < 4; i++) {
        s->moves[i] = func_02017E1C((void *)m, 0x36 + i, 0);
        s->ppups |= func_02017E1C((void *)m, 0x3e + i, 0) << (i * 2);
    }
    s->f1f = func_02017E1C((void *)m, 0xc, 0);
    s->f0c = func_02017E1C((void *)m, 7, 0);
    s->f10 = func_02017E1C((void *)m, 0, 0);
    s->f14 = func_02017E1C((void *)m, 0xac, 0);
    for (i = 0; i < 6; i++)
        s->f18[i] = func_02017E1C((void *)m, 0xd + i, 0);
    s->f20 = func_02017E1C((void *)m, 0xa, 0);
    s->f21 = func_02017E1C((void *)m, 9, 0);
    func_02017E1C((void *)m, 0x74, (u32)s->name);
}
