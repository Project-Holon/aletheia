/*
 * function: FIELD_GIMMICK_GATE_Exit
 * address: 0x021F374C
 * packet: pkt_ov048_021F374C
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELD_GIMMICK_GATE_SaveState 0x021F37C4 thumb ov048
 *   GIMMICK_OBJ_ELBOARD_Delete 0x021F474C thumb ov048
 *   FIELD_GIMMICK_GATE_DeleteWork 0x021F38EC thumb ov048
 */
#include "../include/Obj05133.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int *FIELDMAP_GetCommonWork(char *,int);
extern void FIELD_GIMMICK_GATE_SaveState(u8 *);
extern void GIMMICK_OBJ_ELBOARD_Delete(unsigned char *p);
extern void FIELD_GIMMICK_GATE_DeleteWork(int *p);
void FIELD_GIMMICK_GATE_Exit(char *a) { u8 *p; p=(u8 *)FIELDMAP_GetCommonWork(a,0); FIELD_GIMMICK_GATE_SaveState(p); if(((struct Obj05133 *)p)->f14)GIMMICK_OBJ_ELBOARD_Delete(((struct Obj05133 *)p)->f14); FIELD_GIMMICK_GATE_DeleteWork((int *)p); }
