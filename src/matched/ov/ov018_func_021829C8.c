/*
 * function: func_021829C8,func_021829E8
 * address: 0x021829C8
 * packet: pkt_ov018_021829C8
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   d_02183A44 0x02183A44 data a2
 *   d_02183A2C 0x02183A2C data a2
 *   func_021828B8 0x021828B8 thumb ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x48]; unsigned int n : 4; unsigned int other : 28; } Src;
extern u16 d_02183A44[][5];
extern u16 d_02183A2C[];
extern void func_021828B8(void *, void *, u16 *);
void func_021829C8(void *a, Src *b) { int n; n = b->n; if (n >= 6) n = 0; func_021828B8(a,b,d_02183A44[n]); }
void func_021829E8(void *a, void *b) { func_021828B8(a,b,d_02183A2C); }
