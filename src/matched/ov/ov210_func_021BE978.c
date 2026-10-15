/*
 * function: ZKNSEARCH_MAIN_PrintEntryCount2
 * address: 0x021BE978
 * packet: pkt_ov210_021BE978
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021BE9D2..021BE9D4 is zero alignment padding.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   ZKNSEARCH_MAIN_PrintWindowText 0x021BE44C thumb ov210
 *   ZKNSEARCH_MAIN_MakeWindowScreen 0x021BE49C thumb ov210
 */
#include "../include/Obj00222.h"
typedef unsigned char u8;
struct Descriptor;
struct CharBuf;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void ZKNSEARCH_MAIN_PrintWindowText(u8 *, int, unsigned, int, int, unsigned short, unsigned);
extern void ZKNSEARCH_MAIN_MakeWindowScreen(u8 *);
void ZKNSEARCH_MAIN_PrintEntryCount2(u8 *p)
{
    unsigned message;
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00222 *)p)->f1B4), 0);
    message = (*(u8 **)(*(u8 * *)&((struct Obj00222 *)p)->f0 + 8))[2];
    if (message != 255) ZKNSEARCH_MAIN_PrintWindowText(p, 13, message + 51, 48, 0, 0x3c40, 2);
    else ZKNSEARCH_MAIN_PrintWindowText(p, 13, 95, 48, 0, 0x3c40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(p + 0x1b4);
}
