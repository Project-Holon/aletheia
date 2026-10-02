/*
 * function: func_0215F2F0
 * address: 0x0215F2F0
 * packet: pkt_ov010_0215F2F0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0204A1BC 0x0204A1BC arm
 *   func_02159114 0x02159114 thumb ov010
 */

extern void *func_0215A5F4(void *);
extern int func_0204A1BC(int,int,int,int);
extern void func_02159114(void *,int);
int func_0215F2F0(void *a, void *b) { void *p = func_0215A5F4(b); func_02159114(p,func_0204A1BC(0xd1,0,0,0x8004)); return 0; }
