/*
 * function: func_021BDDF4
 * address: 0x021BDDF4
 * packet: pkt_ov099_021BDDF4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BCB70 0x021BCB70 thumb ov099
 *   func_021BCBBC 0x021BCBBC thumb ov099
 */
#include "../include/Obj07954.h"
typedef unsigned int   u32;
struct BigObj;
extern int func_021BCB70(void *rules, const struct BigObj *obj, u32 *mask);
extern int func_021BCBBC(int,int,int *);
int func_021BDDF4(char *p) {
 int out;
 if (func_021BCB70((void *)(((struct Obj07954 *)p)->f1348),(const struct BigObj *)(((struct Obj07954 *)p)->fC4),(u32 *)(&out)) && func_021BCBBC(((struct Obj07954 *)p)->f1348,((struct Obj07954 *)p)->fCC,&out)) return 0;
 return 1;
}
