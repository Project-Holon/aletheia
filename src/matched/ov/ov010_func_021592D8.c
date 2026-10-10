/*
 * function: func_021592D8
 * address: 0x021592D8
 * packet: pkt_ov010_021592D8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov010/script_work_p04.c and filed here.
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
typedef struct { u8 pad00[0x14]; u8 *pc; u8 pad18[4]; u32 *vars; } Ctx_021592D8;

static inline u8 rd8_021592D8(Ctx_021592D8 *c)
{
    u8 v = *c->pc;
    c->pc++;
    return v;
}

int func_021592D8(Ctx_021592D8 *c)
{
    u8 a = rd8_021592D8(c);
    u8 b = rd8_021592D8(c);
    c->vars[a] = b;
    return 0;
}
