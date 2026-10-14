/*
 * function: GURU2_MAIN_StateShowRound
 * address: 0x021DF004
 * packet: pkt_ov137_021DF004
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_StartBlendFade 0x021E1584 thumb ov137
 *   GURU2_MAIN_CreateCenterActorTask 0x021E129C thumb ov137
 */
#include "../include/Obj02209.h"
extern void GURU2_MAIN_StartBlendFade(char *,int);
extern void GURU2_MAIN_CreateCenterActorTask(char *);
int GURU2_MAIN_StateShowRound(char *p) { GURU2_MAIN_StartBlendFade(p,1); GURU2_MAIN_CreateCenterActorTask(p); ((struct Obj02209 *)p)->f0=25; return 0; }
