/*
 * function: func_021DEAF4
 * address: 0x021DEAF4
 * packet: pkt_ov093_021DEAF4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: int n = (unsigned char)func_021DCFF8(a,2) schedules the
 * narrowing in r0 then r1. An inline call cast costs an extra copy (62 B).
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021DCFD0 0x021DCFD0 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern int func_021DCFF8(int,int);
extern int func_021DCFD0(int *,unsigned int);
extern int func_021D76BC(int,unsigned int);
void func_021DEAF4(int a,int *b,int c,int *p) { int n; if(c==func_021D775C(4)) { n=(unsigned char)func_021DCFF8(a,2); if(func_021DCFD0(b,n)) *p=func_021D76BC(58,3); else *p=0; } }
