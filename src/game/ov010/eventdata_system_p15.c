/*
 * file:     eventdata_system_p15.c
 * unit:     yes
 * function: func_02162A74, func_02162AA4, func_02162B68
 * address:  0x02162A74
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
 *   func_02162C54  0x02162C54  thumb  ov010
 */
#include "../../matched/include/Obj18964.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 e,f,g; } Payload;

typedef struct { u16 a,b,c,d; Payload data; } Rec;

typedef struct { u8 pad[18]; u16 n; u8 pad14[8]; Rec *r; } Ctx;

typedef short s16;

struct Sub {
    s16 f0;
    s16 f2;
    s16 f4;
    u16 f6;
    u16 f8;
};

struct Box {
    u16 pad0[4];
    struct Sub s;
};

extern int func_02162C54(u8 *p);
void func_02162A74(const Ctx *c, u32 i, u32 a, u32 b, u16 d);
u16 func_02162AA4(int v, int m, int flag, int dir, u16 n);
u16 func_02162B68(struct Box *b, int *pos);

static inline void set(Rec *r, u32 a, u32 b, u16 d)
{
    Payload *p = &r->data;
    ((struct Obj18964 *)r)->f8 = a;
    p->f = d;
    p->g = b << 4;
}

/*
 * extent: 46 code bytes followed by two zero alignment bytes.
 * lever: inline setter takes the whole Rec and all three payload inputs;
 * its own Payload pointer preserves the parent base and explicit +8 copy.
 * domain: unsigned index comparison and modular word address arithmetic.
 */
void func_02162A74(const Ctx *c, u32 i, u32 a, u32 b, u16 d)
{
    Rec *r;
    if (c->n >= i && c->r != 0) {
        r = (Rec *)((u32)c->r + i * 20u);
        if (r->d == 0) {
            set(r, a, b, d);
        }
    }
}


/*
 * note 2026-10-05: the old draft (DIFF45) wrote the tail as a do/while(0) with a goto.
 * The branch-to-branch stubs are the tail `a = hw + (a - h)` written out in each arm
 * (cross-jumped later). `long w = n` keeps the final `a >= n` reload from the stack slot;
 * `hw` is unsigned (lsrs). EXACT* = 2 byte trailing pad (194 of 196 listing extent).
 */
u16 func_02162AA4(int v, int m, int flag, int dir, u16 n)
{
    int b, a, c;
    unsigned h, hw;
    int d;
    long w;
    if (v == 0)
        return 0;
    b = (v & 0xf0) >> 4;
    a = v & 0xf;
    c = (v & 0xf00) >> 8;
    if ((c == 0 && m == 3) || (c == 1 && m == 2) || (c == 3 && m == 0) || (c == 2 && m == 1))
        a = (b - 1) - a;
    if (flag != 0) {
        switch (dir) {
        case 0:
            if ((unsigned)(c - 2) <= 1)
                a = (b - 1) - a;
            break;
        case 1:
            if ((unsigned)c <= 1)
                a = (b - 1) - a;
            break;
        case 2:
            a = (b - 1) - a;
            break;
        }
    }
    w = n;
    h = (unsigned)b / 2;
    d = w - b;
    hw = (unsigned)w / 2;
    if (d != 0) {
        if (d % 2 != 0) {
            if (w % 2 != 0) {
                if (a < h) {
                    h = h - 1;
                    a = hw + (a - h);
                } else {
                    a = hw + (a - h);
                }
            } else {
                if (a <= h) {
                    a = (hw - 1) + (a - h);
                    goto clamp;
                } else {
                    a = hw + (a - h);
                }
            }
        } else {
            a = hw + (a - h);
        }
    }
clamp:
    if (a < 0)
        a = 0;
    else if (a >= n)
        a = w - 1;
    return a;
}


u16 func_02162B68(struct Box *b, int *pos)
{
    struct Sub *s;
    int m = func_02162C54((u8 *)b);
    s = &b->s;
    if (s->f6 > 1)
        return (s->f6 << 4) | (((pos[0] >> 12) - s->f0) / 16) | (m << 8);
    if (s->f8 > 1)
        return (s->f8 << 4) | (((pos[2] >> 12) - s->f4) / 16) | (m << 8);
    return (m << 8) | 0x10;
}
