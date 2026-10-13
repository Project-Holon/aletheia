/*
 * function: FIELD_GIMMICK_GATE_LoadState
 * address: 0x021F37FC
 * packet: pkt_ov048_021F37FC
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELD_GIMMICK_GATE_GetSave 0x021F37A4 thumb ov048
 */
#include "../include/Obj00377.h"
#include "../include/Obj09834.h"
typedef unsigned short u16;
extern char *FIELD_GIMMICK_GATE_GetSave(int a);
void FIELD_GIMMICK_GATE_LoadState(int *p) { char *q; q=FIELD_GIMMICK_GATE_GetSave(p[1]); p[4]=((struct Obj09834 *)q)->f0; p[6]=((struct Obj09834 *)q)->f4; ((struct Obj00377 *)p)->f64=((struct Obj09834 *)q)->f8; }
