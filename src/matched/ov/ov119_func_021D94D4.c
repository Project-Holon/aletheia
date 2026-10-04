/*
 * function: func_021D94D4
 * address: 0x021D94D4
 * packet: pkt_ov119_021D94D4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_021D8F20 0x021D8F20 thumb ov119
 *   func_02017E1C 0x02017E1C thumb
 *   func_0201AC80 0x0201AC80 thumb
 */
#include "../include/Obj22724.h"
extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *,int);
extern int func_021D8F20(void *,int);
typedef unsigned int   u32;
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_0201AC80(void *p);
int func_021D94D4(char *p) { int w; void *v; int z; if(func_021D8AA8(p)==0) {v=func_021D8FA4(p,0);w=func_021D8F20(p,0);} else {v=func_021D8FA4(p,1);w=func_021D8F20(p,1);} z=0;if(func_02017E1C(v,160,0)==0)return z;if(func_02017E1C(v,76,0))return z;if(func_0201AC80((void *)(((struct Obj22724 *)p)->f838))==1 && w!=0)return 1;return 0; }
