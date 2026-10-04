/*
 * function: func_021D9548
 * address: 0x021D9548
 * packet: pkt_ov119_021D9548
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 *   func_0202F738 0x0202F738 thumb
 */
#include "../include/Obj04475.h"
typedef unsigned int   u32;
extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_0202F738(int,int);
int func_021D9548(char *p,int a,int b) { int v=(int)func_021D8DD0((void *)(((struct Obj04475 *)p)->f828),a,b,p); int r; if(((struct Obj04475 *)p)->f118C) return 0; if(a!=((struct Obj04475 *)p)->f630) return 0; r=0; if(func_02017E88((void *)v,76,0)) return r; if(func_0202F738(v,r)==0) r=1; return r; }
