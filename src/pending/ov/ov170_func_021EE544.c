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
