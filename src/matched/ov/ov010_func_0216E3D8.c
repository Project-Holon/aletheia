/*
 * function: func_0216E3D8
 * address: 0x0216E3D8
 * packet: pkt_ov010_0216E3D8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020143CC 0x020143CC thumb
 */

typedef unsigned short u16;
extern unsigned int func_020143CC(unsigned int, unsigned int);
unsigned int func_0216E3D8(unsigned int a, unsigned int id) { if (id>=162 && id<=177) { if(a==0) id=10; else id=*(u16 *)func_020143CC(a,(u16)(id+0x3f7e)); } return id; }
