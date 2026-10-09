/*
 * file:     unit_021B23E0_p05.c
 * unit:     yes
 * function: func_021B2894
 * address:  0x021B2894
 * packet:   pkt_ov013_021B2894
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B60D8  0x021B60D8  data  ov013  a4
 *   d_021B3BC8  0x021B3BC8  data  ov013  a1
 *   d_021B3AFC  0x021B3AFC  data  ov013  a1
 *   func_021B25B0  0x021B25B0  arm  ov013
 */

typedef unsigned char u8;
typedef signed char s8;

typedef struct Ctx {
    int f0;
    int f4;
    int f8;
    int fC;
} Ctx;

typedef struct Msg {
    int f0;
    u8 b4;
    u8 b5;
    u8 b6;
} Msg;

typedef struct St {
    char pad[0x10];
    int state;
} St;

extern St d_021B60D8;
extern s8 d_021B3BC8[][11];
extern s8 d_021B3AFC[][11];
extern int func_021B25B0(int a, int b);

int func_021B2894(Ctx *c, Msg *m)
{
    int i;
    int r;

    i = m->b6;
    if (m->b4 == 0)
        i += 5;
    if ((unsigned int)i >= 0xb)
        i = -1;
    if (i < 0)
        return -1;
    if (d_021B60D8.state == 1)
        r = d_021B3BC8[c->fC][i];
    else
        r = d_021B3AFC[c->fC][i];
    switch (r) {
    case -1:
        return r;
    case -2:
        func_021B25B0((int)c, 1);
        c->fC = 0;
        c->f0 = 0;
        return r;
    case -3:
        func_021B25B0((int)c, 3);
        c->fC = 0;
        c->f0 = 0;
        return r;
    default:
        return r;
    }
}
