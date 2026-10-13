/*
 * function: func_02158CD0
 * address:  0x02158CD0
 * packet:   pkt_ov010_02158CD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Looks up value v in a table of 46 range records (lo, hi, a, b, c).
 * Writes a, b, c to the three outputs and returns v - lo. Past the table
 * it falls back to two lookups by k, or to fixed outputs when v is 0.
 * 2026-10-05 (wave P15): the table is const and the three outputs are
 * stored directly from the record. The old DIFF 14 B draft copied b and c
 * into u16 locals; that form is not needed.
 * symbols:
 *   func_02034714  0x02034714  arm
 *   ZONEDATA_GetScriptArcId  0x02013B5C  thumb
 *   ZONEDATA_GetMsgArcId  0x02013B68  thumb
 *   d_021701A8     0x021701A8  data  a4
 *   d_02172898     0x02172898  data  ov010  a1
 */
typedef unsigned short u16;

struct E { u16 lo, hi, a, b, c; };

typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 ZONEDATA_GetScriptArcId(u32 id);
extern u16 ZONEDATA_GetMsgArcId(u16);
extern const struct E d_021701A8[];
extern char d_02172898[];

u16 func_02158CD0(unsigned k, unsigned v, u16 *o1, u16 *o2, u16 *o3)
{
    unsigned i;
    const struct E *t = d_021701A8;
    const struct E *e;
    for (i = 0; i < 46; i++) {
        if (v < t[i].lo)
            continue;
        if (v > t[i].hi)
            func_02034714(d_02172898, (int)0, d_02172898);
        e = &t[i];
        *o1 = e->a;
        *o2 = e->b;
        *o3 = e->c;
        return v - t[i].lo;
    }
    if (v >= 1) {
        u16 x = (u16)ZONEDATA_GetScriptArcId((u16)k);
        u16 y = ZONEDATA_GetMsgArcId(k);
        *o1 = x;
        *o2 = 3;
        *o3 = y;
        return v - 1;
    }
    *o1 = 0x356;
    *o2 = 3;
    *o3 = 0x9E;
    return 0;
}
