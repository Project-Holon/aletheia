/*
 * function: func_02162928
 * address: 0x02162928
 * packet: pkt_ov010_02162928
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021627C8 0x021627C8 thumb ov010
 */
typedef unsigned short u16;
extern u16 *func_021627C8(void *, void *, int, int);
u16 func_02162928(void *p, void *q, int key, int mode) { u16 *r=func_021627C8(p,q,key,mode); if(r) return *r; return 0xffff; }
