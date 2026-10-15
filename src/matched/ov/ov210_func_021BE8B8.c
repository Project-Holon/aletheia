/*
 * function: ZKNSEARCH_MAIN_PrintEntryCount
 * address: 0x021BE8B8
 * packet: pkt_ov210_021BE8B8
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: raw 0x1B4 accesses retain the offset in r6; a named enum swaps
 *        the offset with the implicit zero in r4.
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
void ZKNSEARCH_MAIN_PrintEntryCount(u8 *p)
{
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00222 *)p)->f1B4), 0);
    ZKNSEARCH_MAIN_PrintWindowText(p, 13, (*(u8 **)(*(u8 * *)&((struct Obj00222 *)p)->f0 + 8))[1] + 25, 48, 0, 0x3c40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(p + 0x1b4);
}
