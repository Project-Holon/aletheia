/*
 * function: func_02162940
 * address: 0x02162940
 * packet: pkt_ov010_02162940
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02162890 0x02162890 thumb ov010
 */
typedef unsigned short u16;
extern u16 *func_02162890(void *, void *, int);
u16 func_02162940(void *p, void *q, int key) { u16 *r=func_02162890(p,q,key); if(r) return *r; return 0xffff; }
