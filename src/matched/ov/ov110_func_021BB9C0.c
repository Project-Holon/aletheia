/*
 * function: PMSIV_CATEGORY_ShowWordList
 * address: 0x021BB9C0
 * packet: pkt_ov110_021BB9C0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype-evidence: BF7FC's legacy source says void; this caller uses r0
 * at 0x021BB9CC/0x021BB9CE, so its observed unsigned result is retained.
 * symbols:
 *   PMS_INPUT_GetInitialCount 0x021BF7FC thumb ov110
 *   PMSIV_CATEGORY_DrawWordList 0x021BBA10 thumb ov110
 *   PMSIV_CATEGORY_StartListScrollOut 0x021BB9E8 thumb ov110
 */
#include "../include/Obj02460.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 PMS_INPUT_GetInitialCount(u8 *p);
extern void PMSIV_CATEGORY_DrawWordList(u8 *,unsigned);
extern void PMSIV_CATEGORY_StartListScrollOut(u8 *,u32);
void PMSIV_CATEGORY_ShowWordList(u8 *p,int flag) { u32 n=PMS_INPUT_GetInitialCount(*(u8 * *)&((struct Obj02460 *)p)->f4); if(n>22)n=22; if(flag)PMSIV_CATEGORY_DrawWordList(p,n);else PMSIV_CATEGORY_StartListScrollOut(p,n); }
