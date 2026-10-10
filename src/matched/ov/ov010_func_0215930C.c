/*
 * function: func_0215930C
 * address: 0x0215930C
 * packet: pkt_ov010_0215930C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov010/unit_021592F0.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 pad00[0x14]; u8 *pc; u8 pad18[4]; u32 *vars; } Ctx_0215930C;

static inline u8 rd8_0215930C(Ctx_0215930C *c)
{
    u8 v = *c->pc;
    c->pc++;
    return v;
}

int func_0215930C(Ctx_0215930C *c)
{
    u8 a = rd8_0215930C(c);
    u8 b = rd8_0215930C(c);
    c->vars[a] = c->vars[b];
    return 0;
}
