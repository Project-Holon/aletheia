/*
 * function: VS_MULTI_LIST_ProcMain
 * address: 0x021F6590
 * packet: pkt_ov097_021F6590
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gVsMultiListStateTable 0x021F7608 data a4
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   VS_MULTI_LIST_UpdatePrintQueue 0x021F6B38 thumb ov097
 *   CLACT_DrawSystem 0x0204A600 arm
 */
#include "../include/Obj10194.h"
struct WinMgr;
extern int (*gVsMultiListStateTable[])(char *);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void VS_MULTI_LIST_UpdatePrintQueue(char *);
extern void CLACT_DrawSystem(void);
int VS_MULTI_LIST_ProcMain(int a,int *b,int c,char *d) { *b=gVsMultiListStateTable[*b](d); if(*b==5) return 1; BGWINFRM_UpdateMoves(*(struct WinMgr * *)&((struct Obj10194 *)d)->f8); VS_MULTI_LIST_UpdatePrintQueue(d); CLACT_DrawSystem(); return 0; }
