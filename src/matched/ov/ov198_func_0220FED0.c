/*
 * function: B_PLIST_MAIN_HandleItemSelect
 * address: 0x0220FED0
 * packet: pkt_ov198_0220FED0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Width: original narrows state to u8 before 0220B760; extern preserves caller truncation despite owner u32 state.
 * symbols:
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   B_PLIST_MAIN_PlaySe 0x02211970 thumb ov198
 *   B_PLIST_ANM_StartPaletteAnim 0x0220B760 thumb ov198
 *   B_PLIST_MAIN_CheckMoveUsable  0x02210F1C  thumb
 */
#include "../include/Obj08361.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sound;
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *);
extern void B_PLIST_MAIN_PlaySe(u8 **,u32);
extern void B_PLIST_ANM_StartPaletteAnim(u8 *p, unsigned int state);
extern u32 B_PLIST_MAIN_CheckMoveUsable(u8 *p);
extern u32 PALANM_GetFadeRequestBits(const char *);
int B_PLIST_MAIN_HandleItemSelect(u8 *p)
{
    u32 sel;
    u8 value;
    if(PALANM_GetFadeRequestBits(*(const char * *)&((struct Obj08361 *)p)->f1D8)!=0)return 25;
    sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj08361 *)p)->f2184);
    switch(sel){
    case 0: case 1: case 2: case 3: case 4:
        value=sel;
        (*(u8 **)p)[0x4B]=value;
        p[0x2191]=value;
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)(sel+22));
        ((struct Obj08361 *)p)->f217C=17;
        return 29;
    case 5:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        (*(u8 **)p)[0x4B]=4;
        B_PLIST_ANM_StartPaletteAnim(p,(u8)6);
        return 31;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        (*(u8 **)p)[0x4B]=4;
        B_PLIST_ANM_StartPaletteAnim(p,(u8)6);
        return 31;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 25;
}
