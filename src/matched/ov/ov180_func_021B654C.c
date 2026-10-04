/*
 * function: func_021B654C
 * address: 0x021B654C
 * packet: pkt_ov180_021B654C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017D30 0x02017D30 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017D70 0x02017D70 thumb
 */
#include "../include/Obj08297.h"
typedef unsigned int   u32;
struct Sav;
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017D70(struct Sav *p, u32 f);
void func_021B654C(char *p) {
 void *mon; unsigned saved;
 mon=*(void **)(p+(unsigned char)p[0x915D]*4+0x9140);
 saved=func_02017D30(mon);
 ((struct Obj08297 *)p)->f9158=func_02017E1C(mon,5,0);
 ((struct Obj08297 *)p)->f915A=func_02017E1C(mon,174,0);
 p[0x915C]=func_02017E1C(mon,111,0);
 func_02017D70(mon,saved);
}
