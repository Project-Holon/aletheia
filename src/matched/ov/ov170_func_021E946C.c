/*
 * function: func_021E946C
 * address: 0x021E946C
 * packet: pkt_ov170_021E946C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021E2334 0x021E2334 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23945.h"
#include "../include/Obj23946.h"
typedef unsigned char  u8;
extern u8 func_020355C4(void); extern void func_020260F4(void *,int); extern void func_021ED55C(char **,int); extern int func_021E2334(unsigned char *);
void func_021E946C(unsigned char *p){if(func_020355C4()==1)func_020260F4(((struct Obj23945 *)(*(unsigned char * *)&((struct Obj00000 *)p)->f2C))->f70,0);else {func_020260F4(((struct Obj23946 *)(*(unsigned char * *)&((struct Obj00000 *)p)->f2C))->f70,1);func_021ED55C((char **)p,0);}func_021E2334(p);}
