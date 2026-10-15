/*
 * function: B_PLIST_MAIN_HandlePartySelect
 * address: 0x022100BC
 * packet: pkt_ov198_022100BC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: bounded permuter expanded row use, cast the row/column sum to u32,
 *   and captured the byte selection in tmp before calling B_PLIST_MAIN_GetOrderIndex.
 * symbols:
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_MAIN_PlaySe 0x02211970 thumb ov198
 *   B_PLIST_ANM_StartPaletteAnim 0x0220B760 thumb ov198
 * Caller truncates the selection+18 argument to u8 before B_PLIST_ANM_StartPaletteAnim.
 */
#include "../include/Obj10851.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sound;
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *);
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern void B_PLIST_MAIN_PlaySe(u8 **,u32);
extern void B_PLIST_ANM_StartPaletteAnim(u8 *p, unsigned int state);
int B_PLIST_MAIN_HandlePartySelect(u8 *p)
{
    u32 selection=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj10851 *)p)->f2184);
    u8 tmp;
    switch(selection) {
    case 0: case 1: case 2: case 3: {
        unsigned idx;
        u8 *row;
        tmp=(*(u8 **)p)[0x20];
        idx=B_PLIST_MAIN_GetOrderIndex(p,tmp);
        row=(u8 *)((u32)p+idx*0x4c);
        if(*(u16 *)((u32)((u32)((u8 *)((u32)p+idx*0x4c))+selection*8)+0x30)==0) break;
        (*(u8 **)p)[0x4b]=selection;
        (*(u8 **)p)[0x48]=idx;
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)(selection+18));
        return 31;
    }
    case 4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        ((struct Obj10851 *)p)->f217C=11;
        return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        ((struct Obj10851 *)p)->f217C=11;
        return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5:
    case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 28;
}
