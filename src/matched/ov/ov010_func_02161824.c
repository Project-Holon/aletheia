/*
 * function: func_02161824
 * address: 0x02161824
 * packet: pkt_ov010_02161824
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02161724 0x02161724 thumb ov010
 */

typedef unsigned int u32;
extern int func_02161724(void *,u32 *,void *);
extern void *func_020122C0(void *,int,void *,int);
extern u32 *func_020124E8(void *);
extern void *func_020120F4(void *);
void *func_02161824(void *a, void *b) { void *t; u32 *p; t=func_020122C0(a,0,func_02161724,0x10); p=func_020124E8(t); p[0]=(u32)a; p[1]=(u32)b; p[2]=(u32)func_020120F4(a); return t; }
