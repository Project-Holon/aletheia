/*
 * function: IRCBATTLEMATCH_StepWaitFadeIn
 * address: 0x021BAA9C
 * packet: pkt_ov100_021BAA9C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: larger predicate follower 0x021BAAEC is filed separately.
 * symbols:
 *   FADE_IsActive 0x0204E804 arm
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   func_02009A34 0x02009A34 thumb
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepCountdownThenExit 0x021BAFA0 thumb ov100
 *   IRCBATTLEMATCH_StepStartSession 0x021BAB08 thumb ov100
 */
#include "../include/Obj10216.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Sub020097BCObj;
extern int FADE_IsActive(void);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
extern void IRCBATTLEMATCH_StepCountdownThenExit(int p);
extern void IRCBATTLEMATCH_StepStartSession(int p);
void IRCBATTLEMATCH_StepWaitFadeIn(int a) {
 if(FADE_IsActive()!=0) {
  if(((struct Obj10216 *)a)->f24C==7) {
   if(func_02009A34((struct Sub020097BCObj *)GAME_DATA_GetWifiList((const struct BigObj *)(**(int * *)&((struct Obj10216 *)a)->f244)))==32) {
    IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepCountdownThenExit);
    ((struct Obj10216 *)a)->fCAC=180;
    return;
   }
  }
  IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepStartSession);
 }
}
