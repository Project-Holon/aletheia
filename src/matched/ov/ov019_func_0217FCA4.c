/*
 * function: func_0217FCA4
 * address: 0x0217FCA4
 * packet: pkt_ov019_0217FCA4
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02047738 0x02047738 arm
 *   func_02047504 0x02047504 arm
 *   func_02082BCC 0x02082BCC arm
 */

typedef unsigned int u32;
struct Rec; struct Tagged;
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern void func_02082BCC(void *p, u32 v, u32 n);
void func_0217FCA4(u32 *p) { func_02047738((struct Rec *)p[3]); func_02047504((struct Rec *)p[1]); func_02082BCC(p,0,0x14); }
