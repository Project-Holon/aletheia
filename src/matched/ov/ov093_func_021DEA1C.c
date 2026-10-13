/*
 * unit: yes
 * function: BTL_HANDLER_ITEM_Choice_ReleaseMoveLock, BTL_HANDLER_ITEM_GetFocusSashHandlers
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
 *   d_021F16BC 0x021F16BC data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
#include "../include/Obj07820.h"
extern int BTL_EVENT_GetVar(int);
extern int d_021F16BC;
extern void BTL_EVENT_MultiplyVar(int,int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *,void *);
void BTL_HANDLER_ITEM_Choice_ReleaseMoveLock(int a,void *b,int c) { unsigned char *p; if(c==BTL_EVENT_GetVar(2)) { p=func_021C88A4(b,11,c); ((struct Obj07820 *)p)->f4=27; p[8]=c; p[20]=1; p[21]=1; func_021C88C8(b,p); } }
int *BTL_HANDLER_ITEM_GetFocusSashHandlers(int *p) { *p=2; return &d_021F16BC; }
