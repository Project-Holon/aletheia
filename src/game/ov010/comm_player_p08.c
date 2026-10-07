/*
 * file:     comm_player_p08.c
 * unit:     yes
 * function: func_02167CF4, func_02167D00, func_02167D44, func_02167DB8, func_02167DEC, func_02167E28
 * address:  0x02167CF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02039338  0x02039338  arm
 *   func_02082D44 0x02082D44 arm
 */
#include "../../matched/include/Obj09320.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Obj {
    u8 pad00[0x724];
    u8 b724;
    u8 b725;
    u8 pad726[2];
    u16 h728;
} Obj;

typedef struct {
    u8 pad0[0xb];
    u8 f0b;
    u16 lo : 5;
    u16 hi : 3;
    u16 rest : 8;
    u8 pad1[0xa];
    u16 f18;
    u16 f1a;
    u16 f1c;
    u8 pad2[4];
    u16 f22;
    u16 f24;
    u8 pad3[0x724 - 0x26];
    u8 f724;
    u8 pad4[3];
    u16 f728;
} D;

typedef struct {
    u8 pad[0xc];
    u16 low : 3;
    u16 flag : 1;
    u16 high : 12;
} Flags;

extern u32 func_0200FB24(void);
extern u16 func_02039338(void);
extern void func_02082D44(void *, void *, unsigned int);
void func_02167CF4(u8 *w, u8 v);
int func_02167D00(Obj *o, u16 *out);
void func_02167D44(int a, int b, const u16 *c, D *d);
void func_02167DB8(u16 a, int b, void *c, u8 *p);
void func_02167DEC(u16 a, int b, u16 *c, u8 *p);
void func_02167E28(u16 a, int b, void *c, u8 *p);


/*
 * Byte setter at +0x725. bl from ov021 func_021CA5C4 at 0x021CB596.
 */
void func_02167CF4(u8 *w, u8 v)
{
    w[0x725] = v;
}


int func_02167D00(Obj *o, u16 *out)
{
    int want;

    if (func_0200FB24() != 0)
        return 1;
    want = 1;
    if (o->b725 != 1)
        want = 2;
    if (o->b724 == want) {
        o->b724 = 0;
        if (out != 0)
            *out = o->h728;
        return 1;
    }
    return 0;
}


/*
 * lever: Const source halfwords restores c[0]/c[1] load scheduling.
 */
void func_02167D44(int a, int b, const u16 *c, D *d)
{
    u16 n = 0;
    u16 w;
    u16 v;
    d->f724++;
    if (a != func_02039338()) {
        w = c[0];
        v = c[1];
        d->f0b = w;
        d->f1a = v;
        d->f1c = c[2];
        d->f18 = c[3];
        d->hi = d->f0b + 5;
        if (d->f22 == v || d->f22 == d->f1c)
            n += 1;
        if (d->f24 == v || d->f24 == d->f1c)
            n += 2;
        d->f728 = n;
    }
}

void func_02167DB8(u16 a, int b, void *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338() && func_02039338() != 0)
        func_02082D44(c, p + 0x32, 0x1c);
}

void func_02167DEC(u16 a, int b, u16 *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338()) {
        ((struct Obj09320 *)p)->f728 = 0;
        if (((Flags *)p)->flag != 0 || *c != 0)
            ((struct Obj09320 *)p)->f728 = 1;
    }
}

void func_02167E28(u16 a, int b, void *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338())
        func_02082D44(c, p + 0x72c, 0x20);
}
