/*
 * function: B_PLIST_DRAW_DrawMoveDetailPage
 * address: 0x0220DD78
 * packet: pkt_ov198_0220DD78
 * region: ov198
 * status: EXACT
 * symbols:
 *   d_02211B20 0x02211B20 data a1
 *   d_02211B3C 0x02211B3C data a4
 *   B_PLIST_DRAW_ClearWindowBitmaps 0x0220BDA0 thumb ov198
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_DRAW_PrintRowName 0x0220BEB8 thumb ov198
 *   B_PLIST_DRAW_PrintTextAt 0x0220C5AC thumb ov198
 *   B_PLIST_DRAW_PrintNumberAt 0x0220C4DC thumb ov198
 *   B_PLIST_DRAW_PrintAccuracyLabel 0x0220D034 thumb ov198
 *   B_PLIST_DRAW_PrintAccuracyValue 0x0220D090 thumb ov198
 *   B_PLIST_DRAW_PrintPowerLabel 0x0220D1BC thumb ov198
 *   B_PLIST_DRAW_PrintPowerValue 0x0220D218 thumb ov198
 *   B_PLIST_DRAW_PrintMoveDescription 0x0220D348 thumb ov198
 *   B_PLIST_DRAW_PrintCategoryLabel 0x0220D3B4 thumb ov198
 *   B_PLIST_DRAW_PrintCategoryName 0x0220D418 thumb ov198
 *   B_PLIST_DRAW_PrintPpPair 0x0220D494 thumb ov198
 */
#include "../include/Obj00507.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 d_02211B20[];
extern const int d_02211B3C[];
extern void B_PLIST_DRAW_ClearWindowBitmaps(u8 *p);
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern void B_PLIST_DRAW_PrintRowName(u8 *p, int slot, u16 a2, u8 a3, u8 extra);
extern void B_PLIST_DRAW_PrintTextAt(char *,int,u16,u16);
extern void B_PLIST_DRAW_PrintNumberAt(char *,int,int,int,u16,short,unsigned);
extern void B_PLIST_DRAW_PrintAccuracyLabel(char *,int),B_PLIST_DRAW_PrintAccuracyValue(char *,int,int);
extern void B_PLIST_DRAW_PrintPowerLabel(char *,int),B_PLIST_DRAW_PrintPowerValue(char *,int,unsigned);
extern void B_PLIST_DRAW_PrintMoveDescription(char *,int,int),B_PLIST_DRAW_PrintCategoryLabel(char *,int);
extern void B_PLIST_DRAW_PrintCategoryName(char *,int,int);
extern void B_PLIST_DRAW_PrintPpPair(u8 *p, int slot, int a2, int a3);
void B_PLIST_DRAW_DrawMoveDetailPage(char *p) {
    u8 *owner;
    char *base,*rec;
    unsigned offset;
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B20;
    B_PLIST_DRAW_ClearWindowBitmaps((u8 *)p);
    owner=*(u8 * *)&((struct Obj00507 *)p)->f0;
    base=p+0x30+B_PLIST_MAIN_GetOrderIndex((u8 *)p,owner[32])*76;
    offset=owner[0x4b]*8;
    rec=base+offset;
    B_PLIST_DRAW_PrintRowName((u8 *)p,6,owner[32],0,0);
    B_PLIST_DRAW_PrintTextAt(p,7,0,0);
    B_PLIST_DRAW_PrintNumberAt(p,*(u16 *)(base+offset),0,d_02211B3C[(*(u8 **)p)[0x4b]],0,0,0x3dc0);
    B_PLIST_DRAW_PrintAccuracyLabel(p,8);
    B_PLIST_DRAW_PrintAccuracyValue(p,2,(u8)rec[6]);
    B_PLIST_DRAW_PrintPowerLabel(p,9);
    B_PLIST_DRAW_PrintPowerValue(p,3,(u8)rec[7]);
    B_PLIST_DRAW_PrintMoveDescription(p,4,*(u16 *)(base+offset));
    B_PLIST_DRAW_PrintCategoryLabel(p,10);
    B_PLIST_DRAW_PrintCategoryName(p,5,(u8)rec[5]);
    B_PLIST_DRAW_PrintPpPair((u8 *)p,1,(u8)rec[2],(u8)rec[3]);
}
