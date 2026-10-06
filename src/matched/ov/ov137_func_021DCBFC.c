/*
 * function: func_021DCBFC
 * address: 0x021DCBFC
 * packet: pkt_ov137_021DCBFC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_021DE08C 0x021DE08C thumb ov137
 */
#include "../include/Obj10614.h"
#include "../include/Obj23673.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
extern u16 func_02039338(void);
extern void func_021DE08C(char *p, int state, int player);
void func_021DCBFC(int a,int b,int c,u8 *p) {if(func_02039338()!=0) {((struct Obj10614 *)p)->f20=0;((struct Obj10614 *)p)->f24=1;func_021DE08C(*(char * *)&((struct Obj23673 *)(*(u8 * *)&((struct Obj10614 *)p)->f0))->f20,27,(u8)a);}}
