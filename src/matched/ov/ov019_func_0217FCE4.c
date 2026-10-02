/*
 * function: func_0217FCE4
 * address: 0x0217FCE4
 * packet: pkt_ov019_0217FCE4
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217FCA4 0x0217FCA4 thumb ov019
 */

typedef unsigned int u32;
struct E { u32 a,b,c,d; unsigned short h; };
extern void func_0217FCA4(struct E *e);
void func_0217FCE4(struct E *p) { int i; for(i=0;i<10;i++) { struct E *e=&p[i]; if(e->d != 0) func_0217FCA4(e); } }
