/*
 * function: IRCBATTLEMATCH_StepApplyPartyRules
 * address: 0x021B9AD8
 * packet: pkt_ov100_021B9AD8
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   POKE_TOOL_HealParty 0x0201BA34 thumb
 *   IRCBATTLEMATCH_GetSharedBattleReadyCount 0x021B9AB4 thumb ov100
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepShowStartMessage 0x021B9A54 thumb ov100
 *   IRCBATTLEMATCH_StartExitWipe 0x021B96B8 thumb ov100
 */
#include "../include/Obj22075.h"
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void POKE_TOOL_HealParty(void *party);
extern int IRCBATTLEMATCH_GetSharedBattleReadyCount(unsigned a);
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
extern void IRCBATTLEMATCH_StepShowStartMessage(int a);
extern void IRCBATTLEMATCH_StartExitWipe(u8 *a);
void IRCBATTLEMATCH_StepApplyPartyRules(int a)
{
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7a,12)!=0) {
  switch(((struct Obj22075 *)a)->f24C) {
  case 7: IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepShowStartMessage); return;
  case 1: case 2: case 3: case 4:
   POKE_TOOL_HealParty((void *)((*(int **)(a+0x244))[2]));
   POKE_TOOL_HealParty((void *)((*(int **)(a+0x244))[3]));
   switch(IRCBATTLEMATCH_GetSharedBattleReadyCount(a)) {
    case 0: break;
    case 1: (*(int **)(a+0x244))[7]=1; break;
    case 2: if((*(int **)(a+0x244))[7]>2) (*(int **)(a+0x244))[7]=2; break;
   }
   IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StartExitWipe);
  default: case 0: case 5: case 6: IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StartExitWipe); break;
  }
 }
}
