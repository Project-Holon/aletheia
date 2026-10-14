/*
 * function: GURU2_MAIN_StateWaitUnionAppReset
 * address: 0x021DF778
 * packet: pkt_ov137_021DF778
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_GetUnionApp 0x021DEB10 thumb ov137
 *   UNION_APP_IsResetDone 0x0218417C thumb ov022
 *   TIME_ICON_Delete 0x0202F038 thumb
 */
#include "../include/Obj10624.h"
typedef unsigned char u8;typedef unsigned int u32;
extern void *GURU2_MAIN_GetUnionApp(char *p);extern u32 UNION_APP_IsResetDone(u8 *);extern void TIME_ICON_Delete(void *);
int GURU2_MAIN_StateWaitUnionAppReset(char *p){if(UNION_APP_IsResetDone(GURU2_MAIN_GetUnionApp(p))){TIME_ICON_Delete(((struct Obj10624 *)p)->fDA8);((struct Obj10624 *)p)->fDA8=0;((struct Obj10624 *)p)->f0=50;return 1;}return 0;}
