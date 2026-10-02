/*
 * function: func_021F43E4
 * address: 0x021F43E4
 * packet: pkt_ov048_021F43E4
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F3C2C 0x021F3C2C thumb ov048
 *   func_021F440C 0x021F440C thumb ov048
 *   func_021F4454 0x021F4454 thumb ov048
 */
typedef unsigned char u8;
extern u8 *func_021F3C2C(u8 *p);
extern void func_021F440C(int *p,int *q,int i);
extern void func_021F4454(int *p);
void func_021F43E4(int *p) { int *q; q=(int *)func_021F3C2C((u8 *)p); switch(q[4]) {case 0:func_021F440C(p,q,3);break;case 2:func_021F4454(p);break;} }
