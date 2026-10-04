/*
 * function: func_021DE0AC
 * address: 0x021DE0AC
 * packet: pkt_ov121_021DE0AC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE024 0x021DE024 thumb ov121
 *   func_020056A0 0x020056A0 thumb
 */
#include "../include/Obj08098.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DE024(void *,char *);
extern void *func_020056A0(u32,u32,u32);
void func_021DE0AC(u8 *p,u32 b) { ((struct Obj08098 *)p)->f130=b; if(*(u32 *)&((struct Obj08098 *)p)->f128==0) ((struct Obj08098 *)p)->f128=func_020056A0((u32)func_021DE024,(u32)p,0); else ((struct Obj08098 *)p)->f12C=0; }
