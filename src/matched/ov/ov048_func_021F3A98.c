/*
 * function: FIELD_GIMMICK_GATE_IsSaveBlockListOn
 * address: 0x021F3A98
 * packet: pkt_ov048_021F3A98
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 */
#include "../include/Obj20531.h"
typedef unsigned int u32;
typedef signed int     s32;
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
int FIELD_GIMMICK_GATE_IsSaveBlockListOn(void *p) {return ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork((const struct BigObj *)(((struct Obj20531 *)p)->f8)),0x960)==1;}
