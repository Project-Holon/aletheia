/*
 * function: FIELD_GIMMICK_BRIDGE_Exit
 * address: 0x021F370C
 * packet: pkt_ov047_021F370C
 * region: ov047
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FLDMMDL_SetDrawOffsetOutside 0x0216D8E0 thumb ov010
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb  arm9
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb  arm9
 */
#include "../include/Obj20524.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern int *FIELDMAP_GetCommonWork(char *,int);
extern void FLDMMDL_SetDrawOffsetOutside(u8 *,void *);
extern void FIELDMAP_FreeCommonWork(u8 *,int);
void FIELD_GIMMICK_BRIDGE_Exit(u32 a) { u8 *p; GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a))),31); p=(u8 *)FIELDMAP_GetCommonWork((char *)a,1); FLDMMDL_SetDrawOffsetOutside(*(u8 * *)&((struct Obj20524 *)p)->f4,p+8); FIELDMAP_FreeCommonWork((u8 *)a,1); }
