/*
 * function: ZKNSEARCH_MAIN_PrintEntryCount3
 * address:  0x021BEA54
 * packet:   pkt_ov210_021BEA54
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   ZKNSEARCH_MAIN_LookupSavedEntryId  0x021BCF00  thumb ov210
 *   ZKNSEARCH_MAIN_PrintWindowText  0x021BE44C  thumb ov210
 *   ZKNSEARCH_MAIN_MakeWindowScreen  0x021BE49C  thumb ov210
 */
#include "../include/Obj00222.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern unsigned short ZKNSEARCH_MAIN_LookupSavedEntryId(int a0, int a1);
typedef unsigned short u16;
extern void ZKNSEARCH_MAIN_PrintWindowText(u8 *p, int slot, u32 message, int x, int y, u16 color, u32 mode);
extern void ZKNSEARCH_MAIN_MakeWindowScreen(u8 *p);

void ZKNSEARCH_MAIN_PrintEntryCount3(u8 *p)
{
    u8 c;

    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj00222 *)p)->f1B4)), 0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00222 *)p)->f1BC)), 0);
    c = ((u8 *)*(u32 *)(*(u32 *)&((struct Obj00222 *)p)->f0 + 8))[3];
    if (c != 0xFF)
        ZKNSEARCH_MAIN_PrintWindowText(p, 0xD, ZKNSEARCH_MAIN_LookupSavedEntryId((int)p, c), 0x30, 0, 0x3C40, 2);
    else
        ZKNSEARCH_MAIN_PrintWindowText(p, 0xD, 0x30, 0x30, 0, 0x3C40, 2);
    c = ((u8 *)*(u32 *)(*(u32 *)&((struct Obj00222 *)p)->f0 + 8))[4];
    if (c != 0xFF)
        ZKNSEARCH_MAIN_PrintWindowText(p, 0xE, ZKNSEARCH_MAIN_LookupSavedEntryId((int)p, c), 0x30, 0, 0x3C40, 2);
    else
        ZKNSEARCH_MAIN_PrintWindowText(p, 0xE, 0x30, 0x30, 0, 0x3C40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(p + 0x1B4);
    ZKNSEARCH_MAIN_MakeWindowScreen(p + 0x1BC);
}
