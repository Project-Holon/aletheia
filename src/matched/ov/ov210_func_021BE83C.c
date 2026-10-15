/*
 * function: ZKNSEARCH_MAIN_InitListTexts
 * address: 0x021BE83C
 * packet: pkt_ov210_021BE83C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   ZKNSEARCH_MAIN_PrintWindowText 0x021BE44C thumb ov210
 *   ZKNSEARCH_MAIN_MakeWindowScreen 0x021BE49C thumb ov210
 *   ZKNSEARCH_MAIN_PrintEntryCount 0x021BE8B8 thumb ov210
 */
#include "../include/Obj00222.h"
typedef unsigned char u8;
struct Descriptor;
struct CharBuf;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void ZKNSEARCH_MAIN_PrintWindowText(u8 *, int, unsigned, int, int, unsigned short, unsigned);
extern void ZKNSEARCH_MAIN_MakeWindowScreen(u8 *);
extern void ZKNSEARCH_MAIN_PrintEntryCount(u8 *);
void ZKNSEARCH_MAIN_InitListTexts(u8 *p)
{
    ZKNSEARCH_MAIN_MakeWindowScreen(p + 0x14c);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00222 *)p)->f154), 0);
    ZKNSEARCH_MAIN_PrintWindowText(p, 1, 4, 0, 4, 0x440, 0);
    ZKNSEARCH_MAIN_MakeWindowScreen(p + 0x154);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00222 *)p)->f1AC), 0);
    ZKNSEARCH_MAIN_PrintWindowText(p, 12, 12, 40, 0, 0x3c40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(p + 0x1ac);
    ZKNSEARCH_MAIN_PrintEntryCount(p);
}
