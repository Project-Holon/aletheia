/*
 * function: func_021D5C4C
 * address: 0x021D5C4C
 * packet: pkt_ov131_021D5C4C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D60A4 0x021D60A4 thumb ov131
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021D60D4 0x021D60D4 thumb ov131
 *   func_021D62F4 0x021D62F4 thumb ov131
 *   func_021D5C4C 0x021D5C4C thumb ov131
 */
#include "../include/Obj00112.h"
extern void *func_021D60A4(void *);
typedef unsigned int   u32;
extern void *func_021D6064(unsigned char *p);
extern void func_021D60D4(unsigned char *p, int a);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern int func_021D62F4(void *,void *);
void func_021D5C4C(unsigned char *p) {
 void *q=func_021D60A4(p);
 void *m=func_021D6064(p);
 int one=1;
 func_021D60D4(p,1);
 *(int *)&((struct Obj00112 *)p)->f38=func_02017E1C(q,76,0);
 ((struct Obj00112 *)p)->f3C=func_02017E1C(q,9,0);
 ((struct Obj00112 *)p)->f40=func_021D62F4(p,m);
 func_021D60D4(p,0);
 ((struct Obj00112 *)p)->f10=one;
}
