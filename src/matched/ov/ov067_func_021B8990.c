/*
 * function: func_021B8990
 * address:  0x021B8990
 * packet:   pkt_ov067_021B8990
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies a 4-byte entry of the table at f2c into f7d/f7e and f74..f77, then
 * clamps f74..f77.  The two upper clamps are `if (t <= hi) f = t; else
 * f = hi;`: the in-range arm comes first, which is what gives the
 * `bgt Lset; b Lstore` pair (the `t > hi` polarity compiles `ble`).
 * f76's `u < 0` test on an unsigned folds away and only the load and store
 * survive.
 *
 * symbols:
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct S {
    u8 _0[0x2c];
    u8 *f2c;
    u8 _30[0x4e - 0x30];
    u16 f4e;
    u8 _50[0x74 - 0x50];
    u8 f74;
    u8 f75;
    u8 f76;
    u8 f77;
    u8 f78;
    u8 _79[0x7d - 0x79];
    u8 f7d;
    u8 f7e;
    u8 f7f;
    int f80;
};

extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);

void func_021B8990(struct S *s, int idx)
{
    int buf;
    u8 *e;
    int t;
    unsigned u;

    s->f7d = s->f2c[idx * 4];
    e = s->f2c + idx * 4;
    s->f7e = e[1];
    s->f74 = s->f2c[idx * 4];
    s->f75 = e[1];
    s->f76 = e[2];
    s->f77 = e[3];
    u = s->f74;
    if (u >= 0x20)
        u -= 0x20;
    else
        u = 0;
    s->f74 = u;
    t = s->f75 + 0x20;
    if (t <= 0xbf)
        s->f75 = t;
    else
        s->f75 = 0xbf;
    u = s->f76;
    if (u < 0)
        u = 0;
    s->f76 = u;
    t = s->f77;
    if (t <= 0xff)
        s->f77 = t;
    else
        s->f77 = 0xff;
    s->f78 = 0xff;
    if (TOUCHPANEL_GetPointCont((u32 *)(&buf), (u32 *)(&s->f80)) == 0)
        s->f80 = -1;
    s->f7f = 1;
    s->f4e = 2;
}
