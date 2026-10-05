/*
 * function: func_021EE544
 * address:  0x021EE544
 * packet:   pkt_ov170_021EE544
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-04: residue is 4 instructions in the argument-load order only: original
 *   emits `ldrb r1,[r3,#1]; adds r2,r4,r2; ldrb r3,[r3]; str r1,[sp]; ldrb r1,[r2]; ldrb r2,[r2,#1]`,
 *   compiled emits str, ldrb r1, ldrb r2, ldrb r3 (g[0] loaded last). Tried: local pointer g,
 *   struct g, g[0]/g[1] into locals before/after the call, u8 callee prototype, struct vs byte
 *   table, t+i*12 forms, e=&t[i] before/after the branch. Branch/pool order already matches.
 *
 * 2026-10-04 (wD2 lane 02): still 6 bytes. Also tried: g as an E-typed table (g->a/g->b), x/y locals read from e
 * before the call, tx/ty locals read before the call, callee parameters declared u32, const g, a G{x,y} struct.
 * All give the same order (ty, e->a, e->b, tx). The original loads tx before e->a and e->b.
 *
 * 2026-10-05 (wD4 lane 15): also tried direct d_021F0188[0], [1] with no g local (52 B, pool word loaded per branch), t0/t1 locals
 * assigned before the if (60 B, spill), t0/t1 locals assigned after the if in both orders (56 B, same 6-byte residue).
 * Original loads g[0] into r3 before `str r1,[sp]`; ours always puts that load last.
 *
 * 2026-10-05 (wD5 lane20): same 6-byte residue (g[0] load order). The original materialises g[1] in r1 and g[0] in r3 before the stack store while e->a/e->b load after; no new source form tried beyond the earlier notes.
 * symbols:
 *   func_021EEFA4  0x021EEFA4  thumb
 *   d_021F0188  0x021F0188  data
 *   d_021F0DCC  0x021F0DCC  data
 *   d_021F0370  0x021F0370  data
 */

typedef struct { unsigned char a, b, pad[10]; } E;
extern unsigned char d_021F0188[];
extern E d_021F0DCC[];
extern E d_021F0370[];
extern void func_021EEFA4(char *p, unsigned char x, unsigned char y, unsigned char tx, unsigned char ty);
void func_021EE544(char *p, unsigned int i)
{
    E *e; unsigned char *g = d_021F0188;
    if (i < 0x1e) { e = &d_021F0DCC[i]; } else { e = &d_021F0370[i - 0x1e]; }
    func_021EEFA4(*(char **)(p + 0x2c), e->a, e->b, g[0], g[1]);
}
