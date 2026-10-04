/*
 * function: func_021B8724
 * address: 0x021B8724
 * packet: pkt_ov093_021B8724
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_0200CED4 0x0200CED4 thumb
 */
#include "../include/Obj20958.h"
#include "../include/Obj20959.h"
typedef unsigned short u16;
struct QF;
extern u16 func_021D5444(struct QF *p);
extern int func_0200CED4(void *,unsigned int);
int func_021B8724(char *p,void *m) { unsigned int s=func_021D5444(m); return func_0200CED4(((struct Obj20959 *)(*(char * *)&((struct Obj20958 *)p)->f0))->f68,s); }
