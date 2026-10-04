/*
 * function: func_021B8B38
 * address: 0x021B8B38
 * packet: pkt_ov103_021B8B38
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021B64B8 0x021B64B8 thumb ov101
 */
#include "../include/Obj04429.h"
typedef unsigned char u8;
typedef struct {int words[54];} Block;
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
struct Link;
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_021B64B8(u32 p, u32 a, u32 b, u32 c, u8 d, u32 e, u32 f, u32 g);
int func_021B8B38(u8 *p,const Block *q) {
 switch(((struct Obj04429 *)p)->f4) {
 case 0: *(Block *)(p+0x1b8)=*q;((struct Obj04429 *)p)->f4=1;break;
 case 1:
  if(func_021B64B8(((struct Obj04429 *)p)->f0,0xe00,0xd8,(u32)(p+0x1b8),(u8)(func_0203D1A4((struct Link *)((int)func_020399A8()))==0),0,0,1))((struct Obj04429 *)p)->f4=2;
  break;
 case 2:
  if(((struct Obj04429 *)p)->f290) {((struct Obj04429 *)p)->f290=0;((struct Obj04429 *)p)->f4=0;return 1;}
  break;
 }
 return 0;
}
