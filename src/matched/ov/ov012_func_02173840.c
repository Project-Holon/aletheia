/*
 * function: UNION_MAIN_IsFieldReady
 * address: 0x02173840
 * packet: pkt_ov012_02173840
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_IsFieldMapExist 0x02012114 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_IsReady 0x02188BE8 thumb ov021
 */
#include "../include/Obj09361.h"
#include "../include/Obj19235.h"
#include "../include/Obj19236.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Ctx;
extern u32 GAMESYSTEM_IsFieldMapExist(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_IsReady(void *a);
int UNION_MAIN_IsFieldReady(u8 *p) { if(p[0x282a]==1 && GAMESYSTEM_IsFieldMapExist(*(const struct Ctx * *)&((struct Obj19235 *)(*(u8 * *)&((struct Obj09361 *)p)->f0))->fC)==1 && FIELDMAP_IsReady(GAMESYSTEM_GetFieldMap(*(const struct Ctx * *)&((struct Obj19236 *)(*(u8 * *)&((struct Obj09361 *)p)->f0))->fC))==1) return 1; return 0; }
