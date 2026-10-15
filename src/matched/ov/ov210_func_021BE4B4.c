/*
 * function: ZKNSEARCH_MAIN_InitWindowTexts
 * address:  0x021BE4B4
 * packet:   pkt_021BE4B4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_PrintWindowText  0x021BE44C  thumb ov210
 */
#include "../include/Obj00222.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;
extern void ZKNSEARCH_MAIN_PrintWindowText(u8 *p, int slot, u32 message, int x, int y, u16 color, u32 mode);

void ZKNSEARCH_MAIN_InitWindowTexts(u8 *p)
{
    if (*(u8 *)(*(u32 *)(*(u32 *)&((struct Obj00222 *)p)->f0 + 8)) == 0)
        ZKNSEARCH_MAIN_PrintWindowText(p, 0, 0x12, 0, 4, 0x3C40, 0);
    else
        ZKNSEARCH_MAIN_PrintWindowText(p, 0, 0x11, 0, 4, 0x3C40, 0);
    ZKNSEARCH_MAIN_PrintWindowText(p, 2, 0xC, 0x28, 4, 0x3C40, 2);
    ZKNSEARCH_MAIN_PrintWindowText(p, 3, 0xD, 0x28, 4, 0x3C40, 2);
    ZKNSEARCH_MAIN_PrintWindowText(p, 4, 0xE, 0x28, 4, 0x3C40, 2);
    ZKNSEARCH_MAIN_PrintWindowText(p, 5, 0xF, 0x28, 4, 0x3C40, 2);
    ZKNSEARCH_MAIN_PrintWindowText(p, 6, 0x10, 0x28, 4, 0x3C40, 2);
    ZKNSEARCH_MAIN_PrintWindowText(p, 0xB, 0x14, 0x28, 4, 0x3C40, 2);
}
