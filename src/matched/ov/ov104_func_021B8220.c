/*
 * function: IRC_RHYTHM_StateCountdown
 * address: 0x021B8220
 * packet: pkt_ov104_021B8220
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_RHYTHM_StartCountdown 0x021B816C thumb ov104
 *   IRC_RHYTHM_IsCountdownFinished 0x021B8178 thumb ov104
 *   IRC_RHYTHM_SetState 0x021B817C thumb ov104
 *   IRC_RHYTHM_Finish 0x021B818C thumb ov104
 *   IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 *   COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 *   IRC_RHYTHM_StateAbort 0x021B8528 thumb ov104
 *   IRC_RHYTHM_UpdateCountdown 0x021B8104 thumb ov104
 *   IRC_RHYTHM_StartRecord 0x021B85E4 thumb ov104
 *   IRC_RHYTHM_StartPulse 0x021B8F00 thumb ov104
 *   IRC_RHYTHM_StateTapping 0x021B829C thumb ov104
 */
#include "../include/Obj13745.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void IRC_RHYTHM_StartCountdown(u8 *);
extern u32 IRC_RHYTHM_IsCountdownFinished(u8 *);
extern void IRC_RHYTHM_SetState(char *p, u32 v);
extern void IRC_RHYTHM_Finish(u8 *);
extern int IRC_APPBAR_GetResult(int *p);
extern int COMPATIBLE_IRC_SYS_GetValueDifference(int *p);
extern void IRC_RHYTHM_StateAbort(u8 *,u16 *);
#define CTX(p) (*(u8 **)((p)+0x8b0))
extern void IRC_RHYTHM_UpdateCountdown(u32 *);
extern void IRC_RHYTHM_StartRecord(u8 *p);
extern void IRC_RHYTHM_StartPulse(void *);
extern void IRC_RHYTHM_StateTapping(u8 *,u16 *);
void IRC_RHYTHM_StateCountdown(u8 *p,u16 *state) { IRC_RHYTHM_UpdateCountdown((u32 *)(p+0x7b0)); if(IRC_RHYTHM_IsCountdownFinished(p+0x7b0)) { ((struct Obj13745 *)p)->f8A8=1; IRC_RHYTHM_StartRecord(p+0x814); IRC_RHYTHM_StartPulse(p+0x7cc); IRC_RHYTHM_SetState((char *)p,(u32)IRC_RHYTHM_StateTapping); } if(IRC_APPBAR_GetResult(((struct Obj13745 *)p)->f7AC)==1) { *(u32 *)(CTX(p)+0xc)=1; IRC_RHYTHM_Finish(p); } if(COMPATIBLE_IRC_SYS_GetValueDifference(*(void **)(CTX(p)+4))!=0) IRC_RHYTHM_SetState((char *)p,(u32)IRC_RHYTHM_StateAbort); }
