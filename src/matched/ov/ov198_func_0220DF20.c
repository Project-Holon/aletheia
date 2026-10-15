/*
 * function: B_PLIST_DRAW_DrawMode7
 * address: 0x0220DF20
 * packet: pkt_ov198_0220DF20
 * region: ov198
 * status: EXACT
 * symbols:
 *   d_02211B2C 0x02211B2C data a1
 *   d_02211B3C 0x02211B3C data a4
 *   B_PLIST_DRAW_ClearWindowBitmaps 0x0220BDA0 thumb ov198
 *   B_PLIST_DRAW_PrintRowName 0x0220BEB8 thumb ov198
 *   B_PLIST_DRAW_PrintTextAt 0x0220C5AC thumb ov198
 *   B_PLIST_DRAW_PrintSlotLabelA 0x0220D034 thumb ov198
 *   B_PLIST_DRAW_PrintSlotLabelB 0x0220D1BC thumb ov198
 *   B_PLIST_DRAW_PrintSlotLabelD 0x0220D3B4 thumb ov198
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_DRAW_PrintNumberAt 0x0220C4DC thumb ov198
 *   B_PLIST_DRAW_PrintSlotValueA 0x0220D090 thumb ov198
 *   B_PLIST_DRAW_PrintSlotValueB 0x0220D218 thumb ov198
 *   B_PLIST_DRAW_PrintSlotLabelC 0x0220D348 thumb ov198
 *   B_PLIST_DRAW_PrintSlotLabelBySelector 0x0220D418 thumb ov198
 *   B_PLIST_DRAW_PrintCenterPair 0x0220D494 thumb ov198
 *   B_PLIST_DRAW_PrintMoveRowLabel 0x0220D628 thumb ov198
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   WAZA_TOOL_IsAlwaysHit 0x0201C1F4 thumb
 */
#include "../include/Obj00507.h"
#include "../include/Obj25185.h"
#include "../include/Obj25186.h"
#include "../include/Obj25187.h"
#include "../include/Obj25188.h"
#include "../include/Obj25189.h"
#include "../include/Obj25190.h"
#include "../include/Obj25191.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 d_02211B2C[];
extern const int d_02211B3C[];
extern void B_PLIST_DRAW_ClearWindowBitmaps(u8 *p);
extern void B_PLIST_DRAW_PrintRowName(u8 *p, int slot, u16 a2, u8 a3, u8 extra);
extern void B_PLIST_DRAW_PrintTextAt(char *,int,u16,u16);
extern void B_PLIST_DRAW_PrintSlotLabelA(char *,int),B_PLIST_DRAW_PrintSlotLabelB(char *,int),B_PLIST_DRAW_PrintSlotLabelD(char *,int);
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern void B_PLIST_DRAW_PrintNumberAt(char *,int,int,int,u16,short,unsigned);
extern void B_PLIST_DRAW_PrintSlotValueA(char *,int,int),B_PLIST_DRAW_PrintSlotValueB(char *,int,unsigned);
extern void B_PLIST_DRAW_PrintSlotLabelC(char *,int,int),B_PLIST_DRAW_PrintSlotLabelBySelector(char *,int,int);
extern void B_PLIST_DRAW_PrintCenterPair(u8 *p, int slot, int a2, int a3);
extern void B_PLIST_DRAW_PrintMoveRowLabel(char *,int);
extern unsigned WAZA_TOOL_GetParam(u16,unsigned);
typedef unsigned int   u32;
extern u32 WAZA_TOOL_IsAlwaysHit(u16 id);
void B_PLIST_DRAW_DrawMode7(char *p) {
    unsigned index,offset,type;
    char *base,*rec;
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B2C;
    B_PLIST_DRAW_ClearWindowBitmaps((u8 *)p);
    B_PLIST_DRAW_PrintRowName((u8 *)p,0,(*(u8 **)p)[32],0,0);
    B_PLIST_DRAW_PrintTextAt(p,2,0,0);
    B_PLIST_DRAW_PrintSlotLabelA(p,4);
    B_PLIST_DRAW_PrintSlotLabelB(p,5);
    B_PLIST_DRAW_PrintSlotLabelD(p,9);
    index=(*(u8 **)p)[0x4b];
    if(index<4) {
        base=p+0x30+B_PLIST_MAIN_GetOrderIndex((u8 *)p,(*(u8 **)p)[32])*76;
        offset=index*8;
        rec=base+offset;
        B_PLIST_DRAW_PrintNumberAt(p,*(u16 *)(base+offset),1,d_02211B3C[index],0,0,0x3dc0);
        B_PLIST_DRAW_PrintSlotValueA(p,6,(u8)rec[6]);
        B_PLIST_DRAW_PrintSlotValueB(p,7,(u8)rec[7]);
        B_PLIST_DRAW_PrintSlotLabelC(p,8,*(u16 *)(base+offset));
        B_PLIST_DRAW_PrintSlotLabelBySelector(p,10,(u8)rec[5]);
        B_PLIST_DRAW_PrintCenterPair((u8 *)p,3,(u8)rec[2],(u8)rec[3]);
    } else {
        type=WAZA_TOOL_GetParam(((struct Obj25185 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,5);
        B_PLIST_DRAW_PrintNumberAt(p,((struct Obj25186 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,1,0x53,0,0,0x3dc0);
        B_PLIST_DRAW_PrintSlotLabelC(p,8,((struct Obj25187 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26);
        if(WAZA_TOOL_IsAlwaysHit(((struct Obj25188 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26)==1) B_PLIST_DRAW_PrintSlotValueA(p,6,0);
        else B_PLIST_DRAW_PrintSlotValueA(p,6,WAZA_TOOL_GetParam(((struct Obj25189 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,4));
        B_PLIST_DRAW_PrintSlotValueB(p,7,WAZA_TOOL_GetParam(((struct Obj25190 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,3));
        B_PLIST_DRAW_PrintSlotLabelBySelector(p,10,WAZA_TOOL_GetParam(((struct Obj25191 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,2));
        B_PLIST_DRAW_PrintCenterPair((u8 *)p,3,type,type);
    }
    B_PLIST_DRAW_PrintMoveRowLabel(p,11);
}
