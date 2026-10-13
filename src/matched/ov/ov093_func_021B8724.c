/*
 * function: BTL_MAIN_CheckZukanSeen
 * address: 0x021B8724
 * packet: pkt_ov093_021B8724
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 */
#include "../include/Obj20958.h"
#include "../include/Obj20959.h"
typedef unsigned short u16;
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int ZUKAN_SAVE_IsCaught(void *,unsigned int);
int BTL_MAIN_CheckZukanSeen(char *p,void *m) { unsigned int s=BTL_POKEPARAM_GetSpecies(m); return ZUKAN_SAVE_IsCaught(((struct Obj20959 *)(*(char * *)&((struct Obj20958 *)p)->f0))->f68,s); }
