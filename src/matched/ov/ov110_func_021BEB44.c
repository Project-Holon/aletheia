/*
 * function: PMS_INPUT_CategoryHasWords
 * address: 0x021BEB44
 * packet: pkt_ov110_021BEB44
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMS_INPUT_DATA_GetCategoryWordCount 0x021B999C thumb ov110
 */
#include "../include/Obj13792.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned PMS_INPUT_DATA_GetCategoryWordCount(u8 *,int);
int PMS_INPUT_CategoryHasWords(u8 *p) { if(PMS_INPUT_DATA_GetCategoryWordCount(*(u8 * *)&((struct Obj13792 *)p)->f18,((struct Obj13792 *)p)->f4C)!=0) return 1; return 0; }
