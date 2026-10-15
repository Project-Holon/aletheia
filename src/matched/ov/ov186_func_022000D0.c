/*
 * function: BR_POKESEARCH_DestroySpeciesList
 * address: 0x022000D0
 * packet: pkt_ov186_022000D0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_DeleteListMenu 0x021FCC80 thumb ov186
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 */
#include "../include/Obj06639.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BR_UTIL_DeleteListMenu(char *);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void BR_RES_ApplyBgSet(int,unsigned);
void BR_POKESEARCH_DestroySpeciesList(u8 *p) { BR_UTIL_DeleteListMenu(*(char * *)&((struct Obj06639 *)p)->f68); *(u32 *)&((struct Obj06639 *)p)->f68=0; BMP_MENUWORK_Delete(((struct Obj06639 *)p)->f64); *(u32 *)&((struct Obj06639 *)p)->f64=0; BR_RES_ApplyBgSet(((struct Obj06639 *)p)->f28,21); }
