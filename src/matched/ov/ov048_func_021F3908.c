/*
 * function: FIELD_GIMMICK_GATE_InitMiscSaveValue
 * address: 0x021F3908
 * packet: pkt_ov048_021F3908
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControlWork 0x02012EC0 thumb
 *   BEACON_GetFromSave 0x0200C0E8 thumb
 *   BEACON_GetGatePoints 0x0200C3B0 thumb
 */
#include "../include/Obj00377.h"
typedef unsigned short u16;
struct Big;
struct Blk34;
extern void *GAME_DATA_GetSaveControlWork(struct Big *p);
extern void *BEACON_GetFromSave(void *p);
extern u16 BEACON_GetGatePoints(struct Blk34 *p);
void FIELD_GIMMICK_GATE_InitMiscSaveValue(int *p) { if(p[4]==0) { ((struct Obj00377 *)p)->f64=BEACON_GetGatePoints(BEACON_GetFromSave(GAME_DATA_GetSaveControlWork((void *)p[2]))); p[4]=1; } }
