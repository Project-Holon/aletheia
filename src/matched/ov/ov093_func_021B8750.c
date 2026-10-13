/*
 * function: BTL_MAIN_RegisterZukanSeen
 * address: 0x021B8750
 * packet: pkt_ov093_021B8750
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_POKEPARAM_GetMon 0x021D5844 thumb ov093
 *   func_0200CFA0 0x0200CFA0 thumb
 */
#include "../include/Obj01889.h"
#include "../include/Obj20962.h"
extern unsigned int BTL_MAIN_GetCompetitor(void *);
extern void *BTL_POKEPARAM_GetMon(void *);
struct Blk37;
extern void func_0200CFA0(struct Blk37 *p, void *m);
void BTL_MAIN_RegisterZukanSeen(char *p,unsigned char k,void *m) { if(BTL_MAIN_GetCompetitor(p)<=1 && k!=0) func_0200CFA0(((struct Obj20962 *)(*(char * *)&((struct Obj01889 *)p)->f0))->f68,BTL_POKEPARAM_GetMon(m)); }
