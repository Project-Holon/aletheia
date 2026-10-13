/*
 * function: UNION_CHARA_GetMmdl
 * address: 0x0217AFB0
 * packet: pkt_ov019_0217AFB0
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_CHARA_MakeObjId 0x0217AED4 thumb ov019
 *   GAME_DATA_GetOccupyInfo 0x02012964 thumb
 *   FLDMMDL_SysSearchObjId 0x0216DE94 thumb ov010
 *   func_02034714 0x02034714 arm
 *   gUnionEmptyString0 0x021807E0 data a1
 */
#include "../include/Obj19389.h"

typedef unsigned char u8;
typedef unsigned short u16;
extern u16 UNION_CHARA_MakeObjId(u8 *,u8 *);
struct BigObj;
extern unsigned int GAME_DATA_GetOccupyInfo(const struct BigObj *p);
extern void *FLDMMDL_SysSearchObjId(void *,unsigned int);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char gUnionEmptyString0[];
void *UNION_CHARA_GetMmdl(void **a,u8 *b,u8 *c) { u16 key; void *p; key = UNION_CHARA_MakeObjId(b,c); p = FLDMMDL_SysSearchObjId((void *)GAME_DATA_GetOccupyInfo(((struct Obj19389 *)((u8 *)*a))->f8),key); if(p == 0) func_02034714(gUnionEmptyString0,0,gUnionEmptyString0); return p; }
