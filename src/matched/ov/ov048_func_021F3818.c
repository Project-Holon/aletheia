/*
 * function: FIELD_GIMMICK_GATE_StoreMiscSaveValue
 * address: 0x021F3818
 * packet: pkt_ov048_021F3818
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BEACON_GetBlock 0x0200C0F0 thumb
 *   BEACON_SetGatePoints 0x0200C3B8 thumb
 */
#include "../include/Obj00377.h"
typedef unsigned short u16;
struct Big;
struct Blk34;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BEACON_GetBlock(void *p);
extern void BEACON_SetGatePoints(struct Blk34 *p, u16 v);
void FIELD_GIMMICK_GATE_StoreMiscSaveValue(int *p) { BEACON_SetGatePoints(BEACON_GetBlock(GAME_DATA_GetSaveControl(((struct Obj00377 *)p)->f8)), ((struct Obj00377 *)p)->f64); }
