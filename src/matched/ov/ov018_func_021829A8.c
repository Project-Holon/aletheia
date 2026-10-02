/*
 * function: func_021829A8
 * address: 0x021829A8
 * packet: pkt_ov018_021829A8
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02183A80 0x02183A80 data a2
 *   func_021828B8 0x021828B8 thumb ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x48]; unsigned int n : 4; unsigned int other : 28; } Src;
extern u16 d_02183A80[][5];
extern void func_021828B8(void *, void *, u16 *);
void func_021829A8(void *a, Src *b) { int n; n = b->n; if (n >= 6) n = 0; func_021828B8(a,b,d_02183A80[n]); }
