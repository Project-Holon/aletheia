/*
 * function: func_021F6EF8
 * address: 0x021F6EF8
 * packet: pkt_ov215_021F6EF8
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02046BE0 0x02046BE0 arm
 *   func_02047CFC 0x02047CFC arm
 */
typedef unsigned short u16;
struct Util;
extern void func_02046BE0(unsigned,unsigned);
extern struct Util *func_02047CFC(u16,u16,u16);
void func_021F6EF8(char *p){unsigned z=0;func_02046BE0(1,z);*(struct Util **)(p+72)=func_02047CFC(4,1,*(u16 *)p);*(u16 *)(p+80)=z;}
