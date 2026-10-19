/*
 * function: POKETRADE_PROC_StepShowTradeSummary
 * address: 0x021D9AD8
 * packet: pkt_ov119_021D9AD8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepOpenMainMenu 0x021D9B34 thumb ov119
 */
#include "../include/Obj05327.h"
typedef unsigned int u32;
struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void *POKETRADE_PROC_GetSideMon(void *,int);
struct WordSet;
extern void WORDSET_SetSlotMonNickname(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepOpenMainMenu(char *p);
void POKETRADE_PROC_StepShowTradeSummary(char *p) { int i; MSGDATA_ReadString((struct MsgBank *)(((struct Obj05327 *)p)->f720),17,(void *)(((struct Obj05327 *)p)->f73C));for(i=0;i<2;i++) WORDSET_SetSlotMonNickname(((struct Obj05327 *)p)->f724,i,POKETRADE_PROC_GetSideMon(p,i));WORDSET_CopyTaggedText((struct WordSet *)(*(int *)&((struct Obj05327 *)p)->f724),(void *)(((struct Obj05327 *)p)->f738),(void *)(((struct Obj05327 *)p)->f73C));POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepOpenMainMenu); }
