/*
 * function: PMS_INPUT_GetListWord
 * address: 0x021BF758
 * packet: pkt_ov110_021BF758
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two trailing zero alignment bytes.
 * symbols:
 *   PMS_INPUT_DATA_GetCategoryWordString 0x021B99A4 thumb ov110
 *   PMSI_SEARCH_GetResultString 0x021BB1CC thumb ov110
 */
#include "../include/Obj08009.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PMS_INPUT_DATA_GetCategoryWordString(u32,u32,u32,int);
extern int PMSI_SEARCH_GetResultString(u8 *p, u8 i, int c);
void PMS_INPUT_GetListWord(u8 *p,u32 a,int b) {
    if(p[0x69]==0) PMS_INPUT_DATA_GetCategoryWordString(((struct Obj08009 *)p)->f18,((struct Obj08009 *)p)->f4C,a,b);
    else PMSI_SEARCH_GetResultString(*(u8 * *)&((struct Obj08009 *)p)->f1C,a,b);
}
