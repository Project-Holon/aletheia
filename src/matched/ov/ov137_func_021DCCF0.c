/*
 * function: func_021DCCF0, func_021DCD0C
 * unit: yes
 * address: 0x021DCCF0
 * packet: pkt_ov137_021DCCF0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_021DE08C 0x021DE08C thumb ov137
 */
#include "../include/Obj23677.h"
#include "../include/Obj23678.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
extern u16 func_02039338(void);
extern void func_021DE08C(char *p, int state, int player);
void func_021DCCF0(int a,int b,int c,u8 *p) {if(func_02039338()!=0) func_021DE08C(*(char * *)&((struct Obj23678 *)(*(u8 * *)&((struct Obj23677 *)p)->f0))->f20,13,0);}
int func_021DCD0C(void) {return func_02039338();}
