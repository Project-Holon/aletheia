/*
 * function: PMS_INPUT_OpenWordList
 * address: 0x021BD868
 * packet: pkt_ov110_021BD868
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_INPUT_InitWordList 0x021BED84 thumb ov110
 *   PMS_INPUT_HandleWordList 0x021BEDEC thumb ov110
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 */
#include "../include/Obj13788.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PMS_INPUT_InitWordList(u8 *,void *);
extern int PMS_INPUT_HandleWordList(u8 *,u32 *);
extern void PMS_INPUT_VIEW_StartTask(u8 *,int);
void PMS_INPUT_OpenWordList(u8 *p)
{
    GFL_USE_PlaySeDefaultVolume(1356);
    PMS_INPUT_InitWordList(p+0x54,p);
    ((struct Obj13788 *)p)->f28=(u32)PMS_INPUT_HandleWordList;
    PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj13788 *)p)->f14,12);
}
