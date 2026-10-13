/*
 * unit: yes
 * function: HAND_ITEM_Choice_ReleaseMoveLock, HAND_ITEM_GetFocusSashHandlers
 * address: 0x021DEA1C
 * packet: pkt_ov093_021DEA1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes store-return follower 0x021DEA4C.
 * symbols:
 *   gFocusSashHandlers 0x021F16BC data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 */
#include "../include/Obj07820.h"
extern int BTL_EVENT_GetVar(int);
extern int gFocusSashHandlers;
extern void BTL_EVENT_MultiplyVar(int,int);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *,void *);
void HAND_ITEM_Choice_ReleaseMoveLock(int a,void *b,int c) { unsigned char *p; if(c==BTL_EVENT_GetVar(2)) { p=BTL_SERVER_FLOW_AllocCmdRecord(b,11,c); ((struct Obj07820 *)p)->f4=27; p[8]=c; p[20]=1; p[21]=1; BTL_SERVER_FLOW_CommitCmdRecord(b,p); } }
int *HAND_ITEM_GetFocusSashHandlers(int *p) { *p=2; return &gFocusSashHandlers; }
