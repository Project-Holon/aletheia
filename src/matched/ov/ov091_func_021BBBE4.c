/*
 * function: func_021BBBE4
 * address: 0x021BBBE4
 * packet: pkt_ov091_021BBBE4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 */
#include "../include/Obj13257.h"
typedef unsigned int   u32;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
typedef unsigned char  u8;
extern u8 func_02027A04(const u8 *p);
unsigned int func_021BBBE4(int a,unsigned char *b) {if(func_020279E8(((struct Obj13257 *)b)->f74)==0)return 23;return *(unsigned short *)((unsigned int)b+func_02027A04((const u8 *)(*(int *)&((struct Obj13257 *)b)->f74))*2+2);}
