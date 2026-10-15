/*
 * function: B_PLIST_MAIN_HandleMoveSelect
 * address: 0x0220FB44
 * packet: pkt_ov198_0220FB44
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Width: original narrows state to u8 before 0220B760; extern preserves caller truncation despite owner u32 state.
 * symbols:
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   B_PLIST_MAIN_PlaySe 0x02211970 thumb ov198
 *   B_PLIST_ANM_StartPaletteAnim 0x0220B760 thumb ov198
 *   B_PLIST_MAIN_CheckCancel 0x02211958 thumb ov198
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_MAIN_NextSelectable 0x02210B30 thumb ov198
 *   B_PLIST_MAIN_CheckMoveUsable  0x02210F1C  thumb
 */
#include "../include/Obj03349.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sound;
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *);
extern void B_PLIST_MAIN_PlaySe(u8 **,u32);
extern void B_PLIST_ANM_StartPaletteAnim(u8 *p, unsigned int state);
extern u32 B_PLIST_MAIN_CheckMoveUsable(u8 *p);
extern u32 B_PLIST_MAIN_CheckCancel(u8 **);
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern u8 B_PLIST_MAIN_NextSelectable(u8 *,int,int);
int B_PLIST_MAIN_HandleMoveSelect(u8 *p)
{
    u32 sel;
    int row;
    u8 next;
    if(B_PLIST_MAIN_CheckCancel((u8 **)p)==1)return 31;
    sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj03349 *)p)->f2184);
    switch(sel){
    case 0: case 1: case 2: case 3:
        row=(u32)p+B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20])*0x4C;
        if(*(u16 *)(row+sel*8+0x30)!=0){
            B_PLIST_MAIN_PlaySe((u8 **)p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,(u8)(sel+14));
            (*(u8 **)p)[0x4B]=sel;
            ((struct Obj03349 *)p)->f217C=15;
            return 29;
        }
        break;
    case 4:
        next=B_PLIST_MAIN_NextSelectable(p,(*(u8 **)p)[0x20],-1);
        if(next!=255){
            (*(u8 **)p)[0x20]=next;
            B_PLIST_MAIN_PlaySe((u8 **)p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,(u8)12);
            ((struct Obj03349 *)p)->f217C=20;
            return 29;
        }
        break;
    case 5:
        next=B_PLIST_MAIN_NextSelectable(p,(*(u8 **)p)[0x20],1);
        if(next!=255){
            (*(u8 **)p)[0x20]=next;
            B_PLIST_MAIN_PlaySe((u8 **)p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,(u8)13);
            ((struct Obj03349 *)p)->f217C=20;
            return 29;
        }
        break;
    case 6:
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)9);
        ((struct Obj03349 *)p)->f217C=13;
        return 29;
    case 7:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)6);
        p[0x2190]=2;
        ((struct Obj03349 *)p)->f217C=12;
        return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)6);
        p[0x2190]=2;
        ((struct Obj03349 *)p)->f217C=12;
        return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 6;
}
