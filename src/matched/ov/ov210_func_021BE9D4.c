/*
 * function: ZKNSEARCH_MAIN_InitListTexts3
 * address:  0x021BE9D4
 * packet:   pkt_021BE9D4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   ZKNSEARCH_MAIN_PrintWindowText  0x021BE44C  thumb ov210
 *   ZKNSEARCH_MAIN_MakeWindowScreen  0x021BE49C  thumb ov210
 *   ZKNSEARCH_MAIN_PrintEntryCount3  0x021BEA54  thumb ov210
 */
#include "../include/Obj00222.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
typedef unsigned short u16;
extern void ZKNSEARCH_MAIN_PrintWindowText(u8 *p, int slot, u32 message, int x, int y, u16 color, u32 mode);
extern void ZKNSEARCH_MAIN_MakeWindowScreen(u8 *p);
extern void ZKNSEARCH_MAIN_PrintEntryCount3(u8 *p);

void ZKNSEARCH_MAIN_InitListTexts3(u8 *p)
{
    ZKNSEARCH_MAIN_MakeWindowScreen(p + 0x14C);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj00222 *)p)->f154)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(p, 1, 6, 0, 4, 0x440, 0);
    ZKNSEARCH_MAIN_MakeWindowScreen(p + 0x154);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj00222 *)p)->f1AC)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(p, 0xC, 0xE, 0x28, 0, 0x3C40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(p + 0x1AC);
    ZKNSEARCH_MAIN_PrintEntryCount3(p);
}
