/*
 * function: B_PLIST_DRAW_DrawMode2
 * address: 0x0220DCA8
 * packet: pkt_ov198_0220DCA8
 * region: ov198
 * status: EXACT
 * symbols:
 *   d_02211B50 0x02211B50 data a1
 *   B_PLIST_DRAW_ClearWindowBitmaps 0x0220BDA0 thumb ov198
 *   B_PLIST_DRAW_PrintRowName 0x0220BEB8 thumb ov198
 *   B_PLIST_DRAW_PrintDualValue 0x0220CDF0 thumb ov198
 *   B_PLIST_DRAW_FillTypeBar 0x0220C2F8 thumb ov198
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   B_PLIST_DRAW_PrintStatsFields 0x0220C714 thumb ov198
 *   B_PLIST_DRAW_PrintStatRow0 0x0220C8F0 thumb ov198
 *   B_PLIST_DRAW_PrintStatRow1 0x0220C9F0 thumb ov198
 *   B_PLIST_DRAW_PrintStatRow2 0x0220CAF0 thumb ov198
 *   B_PLIST_DRAW_PrintStatRow3 0x0220CBF0 thumb ov198
 *   B_PLIST_DRAW_PrintStatRow4 0x0220CCF0 thumb ov198
 *   B_PLIST_DRAW_PrintRowValue 0x0220C398 thumb ov198
 *   B_PLIST_DRAW_PrintItemOrName 0x0220C42C thumb ov198
 *   B_PLIST_DRAW_PrintBankEntry 0x0220CFC4 thumb ov198
 *   B_PLIST_DRAW_PrintCenteredText 0x0220C694 thumb ov198
 */
#include "../include/Obj00507.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 d_02211B50[];
extern void B_PLIST_DRAW_ClearWindowBitmaps(u8 *p);
extern void B_PLIST_DRAW_PrintRowName(u8 *p, int slot, u16 a2, u8 a3, u8 extra);
extern void B_PLIST_DRAW_PrintDualValue(u8 *p, int index);
extern void B_PLIST_DRAW_PrintStatsFields(u8 *p, int index);
extern void B_PLIST_DRAW_PrintStatRow0(char *,int);
extern void B_PLIST_DRAW_FillTypeBar(u8 *p, int slot, int index, u16 value, u8 extra);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void B_PLIST_DRAW_PrintStatRow1(char *,int),B_PLIST_DRAW_PrintStatRow2(char *,int),B_PLIST_DRAW_PrintStatRow3(char *,int),B_PLIST_DRAW_PrintStatRow4(char *,int);
extern void B_PLIST_DRAW_PrintRowValue(u8 *p, int slot, int index);
extern void B_PLIST_DRAW_PrintItemOrName(char *,int,int);
extern void B_PLIST_DRAW_PrintBankEntry(char *,int);
extern void B_PLIST_DRAW_PrintCenteredText(char *,int,int);
void B_PLIST_DRAW_DrawMode2(char *p) {
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B50;
    B_PLIST_DRAW_ClearWindowBitmaps((u8 *)p);
    B_PLIST_DRAW_PrintRowName((u8 *)p,0,(*(u8 **)p)[32],0,0);
    B_PLIST_DRAW_PrintDualValue((u8 *)p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_FillTypeBar((u8 *)p,10,(*(u8 **)p)[32],0,0);
    BMP_WIN_TransferChars(((struct Obj00507 *)p)->f1FC0);
    B_PLIST_DRAW_PrintStatsFields((u8 *)p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintStatRow0(p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintStatRow1(p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintStatRow2(p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintStatRow3(p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintStatRow4(p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintRowValue((u8 *)p,1,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintItemOrName(p,3,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintBankEntry(p,(*(u8 **)p)[32]);
    B_PLIST_DRAW_PrintCenteredText(p,21,25);
}
