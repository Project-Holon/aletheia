/*
 * function: IRCBATTLEMATCH_PrintWaitingMessage
 * address: 0x021BA668
 * packet: pkt_ov100_021BA668
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRCBATTLEMATCH_PrintMainMessage 0x021BA3A4 thumb ov100
 *   IRCBATTLEMATCH_PrintPlayerMessage 0x021BA454 thumb ov100
 *   IRCBATTLEMATCH_PrintRetryMessage 0x021BA530 thumb ov100
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   func_02009A34 0x02009A34 thumb
 *   gIrcBattleMatchMsgPartnerLeft 0x021BB694 data a4
 *   gIrcBattleMatchMsgWaitingMode7Full 0x021BB690 data a4
 *   gIrcBattleMatchMsgWaitingMode7 0x021BB670 data a4
 *   gIrcBattleMatchMsgWaitingMode6 0x021BB680 data a4
 *   gIrcBattleMatchMsgWaitingMode5 0x021BB684 data a4
 *   gIrcBattleMatchMsgWaitingMode9 0x021BB67C data a4
 *   gIrcBattleMatchMsgWaitingMode10 0x021BB66C data a4
 *   gIrcBattleMatchMsgWaitingMode11 0x021BB6A0 data a4
 *   gIrcBattleMatchMsgWaitingDefault 0x021BB698 data a4
 */
#include "../include/Obj00060.h"
struct Word { int x; };
extern const struct Word gIrcBattleMatchMsgPartnerLeft,gIrcBattleMatchMsgWaitingMode7Full,gIrcBattleMatchMsgWaitingMode7,gIrcBattleMatchMsgWaitingMode6,gIrcBattleMatchMsgWaitingMode5,gIrcBattleMatchMsgWaitingMode9,gIrcBattleMatchMsgWaitingMode10,gIrcBattleMatchMsgWaitingMode11,gIrcBattleMatchMsgWaitingDefault;
extern void IRCBATTLEMATCH_PrintMainMessage(struct Word *,int),IRCBATTLEMATCH_PrintPlayerMessage(int,int),IRCBATTLEMATCH_PrintRetryMessage(int,int);
typedef unsigned int   u32;
struct BigObj;
struct Sub020097BCObj;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
void IRCBATTLEMATCH_PrintWaitingMessage(int a) {
 if(((struct Obj00060 *)a)->fCA0==1) {struct Word t=gIrcBattleMatchMsgPartnerLeft;IRCBATTLEMATCH_PrintMainMessage(&t,a);return;}
 if(((struct Obj00060 *)a)->f24C==7) {
  if(func_02009A34((struct Sub020097BCObj *)GAME_DATA_GetWifiList((const struct BigObj *)(**(int * *)&((struct Obj00060 *)a)->f244)))==32) {struct Word t=gIrcBattleMatchMsgWaitingMode7Full;IRCBATTLEMATCH_PrintMainMessage(&t,a);return;}
  else {struct Word t=gIrcBattleMatchMsgWaitingMode7;IRCBATTLEMATCH_PrintMainMessage(&t,a);IRCBATTLEMATCH_PrintPlayerMessage(0x22,a);return;}
 }
 if(((struct Obj00060 *)a)->f24C==6) {struct Word t=gIrcBattleMatchMsgWaitingMode6;IRCBATTLEMATCH_PrintMainMessage(&t,a);return;}
 if(((struct Obj00060 *)a)->f24C==5) {struct Word t=gIrcBattleMatchMsgWaitingMode5;IRCBATTLEMATCH_PrintMainMessage(&t,a);return;}
 if(((struct Obj00060 *)a)->f24C==9) {struct Word t=gIrcBattleMatchMsgWaitingMode9;IRCBATTLEMATCH_PrintMainMessage(&t,a);IRCBATTLEMATCH_PrintRetryMessage(0x27,a);return;}
 if(((struct Obj00060 *)a)->f24C==10) {struct Word t=gIrcBattleMatchMsgWaitingMode10;IRCBATTLEMATCH_PrintMainMessage(&t,a);return;}
 if(((struct Obj00060 *)a)->f24C==11) {struct Word t=gIrcBattleMatchMsgWaitingMode11;IRCBATTLEMATCH_PrintMainMessage(&t,a);return;}
 else {struct Word t=gIrcBattleMatchMsgWaitingDefault;IRCBATTLEMATCH_PrintMainMessage(&t,a);return;}
}
