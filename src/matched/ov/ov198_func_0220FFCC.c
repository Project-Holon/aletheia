/*
 * function: B_PLIST_MAIN_HandleConfirmCancel
 * address: 0x0220FFCC
 * packet: pkt_ov198_0220FFCC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   B_PLIST_MAIN_PlaySe 0x02211970 thumb ov198
 *   B_PLIST_ANM_StartPaletteAnim 0x0220B760 thumb ov198
 *   B_PLIST_MAIN_CheckMoveUsable 0x02210F1C thumb ov198
 */
#include "../include/Obj04602.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sound;
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *);
extern void B_PLIST_MAIN_PlaySe(u8 **,u32);
extern void B_PLIST_ANM_StartPaletteAnim(u8 *,u32);
extern u32 B_PLIST_MAIN_CheckMoveUsable(u8 *p);
int B_PLIST_MAIN_HandleConfirmCancel(u8 *p)
{
    u32 sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj04602 *)p)->f2184);
    switch(sel){
    case 0:
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,27);
        if(B_PLIST_MAIN_CheckMoveUsable(p)==0)((struct Obj04602 *)p)->f217C=31;
        else ((struct Obj04602 *)p)->f217C=27;
        return 29;
    case 1:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p[0x2192]=0;
        ((struct Obj04602 *)p)->f217C=16;
        return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p[0x2192]=0;
        ((struct Obj04602 *)p)->f217C=16;
        return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 26;
}
