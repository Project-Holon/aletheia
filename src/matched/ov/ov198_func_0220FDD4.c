/*
 * function: B_PLIST_MAIN_HandleSlotSelectFade
 * address: 0x0220FDD4
 * packet: pkt_ov198_0220FDD4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   B_PLIST_MAIN_PlaySe 0x02211970 thumb ov198
 *   B_PLIST_ANM_StartPaletteAnim 0x0220B760 thumb ov198
 *   B_PLIST_MAIN_CheckCancel 0x02211958 thumb ov198
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_MAIN_CheckMoveUsable  0x02210F1C  thumb
 */
#include "../include/Obj14565.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sound;
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *);
extern void B_PLIST_MAIN_PlaySe(u8 **,u32);
extern void B_PLIST_ANM_StartPaletteAnim(u8 *,u32);
extern u32 B_PLIST_MAIN_CheckMoveUsable(u8 *p);
extern u32 PALANM_GetFadeRequestBits(const char *);
extern u32 B_PLIST_MAIN_CheckCancel(u8 **);
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
int B_PLIST_MAIN_HandleSlotSelectFade(u8 *p)
{
    u32 sel;
    int row;
    if(PALANM_GetFadeRequestBits(*(const char * *)&((struct Obj14565 *)p)->f1D8)!=0)return 30;
    if(B_PLIST_MAIN_CheckCancel((u8 **)p)==1)return 31;
    sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj14565 *)p)->f2184);
    switch(sel){
    case 0: case 1: case 2: case 3:
        if((*(u8 **)p)[0x4B]!=sel){
            row=(u32)p+B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20])*0x4C;
            if(*(u16 *)(row+sel*8+0x30)!=0){
                B_PLIST_MAIN_PlaySe((u8 **)p,1357);
                (*(u8 **)p)[0x4B]=sel;
                return 15;
            }
        }
        break;
    case 4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        return 31;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        return 31;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 30;
}
