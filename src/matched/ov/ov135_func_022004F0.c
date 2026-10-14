/*
 * function: WORLDTRADE_TITLE_StateStartCursorAnim
 * address: 0x022004F0
 * packet: pkt_ov135_022004F0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_TITLE_PrintMessage 0x022009A4 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   WORLDTRADE_ClearSelectedSpecies 0x021F4F90 thumb ov135
 */
#include "../include/Obj02863.h"
struct Obj;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void WORLDTRADE_TITLE_PrintMessage(u8 *p, u32 n, int a2, int a3, int a4);extern void WORLDTRADE_SetNextState(void *,unsigned,unsigned);extern void CLACT_SetActorAutoAnim(struct Obj *,unsigned);extern void WORLDTRADE_ClearSelectedSpecies(void *);
int WORLDTRADE_TITLE_StateStartCursorAnim(unsigned char *p) {WORLDTRADE_TITLE_PrintMessage(p,4,1,0,0xf0f);WORLDTRADE_SetNextState(p,10,6);CLACT_SetActorAutoAnim(*(struct Obj * *)&((struct Obj02863 *)p)->fBF4,1);WORLDTRADE_ClearSelectedSpecies(p);return 2;}
