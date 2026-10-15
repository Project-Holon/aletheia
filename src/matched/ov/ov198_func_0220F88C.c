/*
 * function: B_PLIST_MAIN_HandleModeSelect
 * address: 0x0220F88C
 * packet: pkt_ov198_0220F88C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_CheckCancel 0x02211958 thumb ov198
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   B_PLIST_MAIN_PlaySe 0x02211970 thumb ov198
 *   B_PLIST_ANM_StartPaletteAnim 0x0220B760 thumb ov198
 *   B_PLIST_MAIN_PrintStatusMessage 0x02210E20 thumb ov198
 *   B_PLIST_MAIN_IsRowFlagged 0x02210ED4 thumb ov198
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_MAIN_CanSwap 0x02211844 thumb ov198
 *   B_PLIST_MAIN_CommitSwap 0x022118F4 thumb ov198
 */
#include "../include/Obj03907.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Sound;
extern u32 B_PLIST_MAIN_CheckCancel(u8 **);
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *);
extern void B_PLIST_MAIN_PlaySe(u8 **,u32);
extern void B_PLIST_ANM_StartPaletteAnim(u8 *,u32);
extern int B_PLIST_MAIN_PrintStatusMessage(u8 *);
extern u8 B_PLIST_MAIN_IsRowFlagged(u8 *);
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern int B_PLIST_MAIN_CanSwap(u8 *);
extern void B_PLIST_MAIN_CommitSwap(u8 *);
int B_PLIST_MAIN_HandleModeSelect(u8 *p)
{
    u32 sel;
    u8 *q;
    if(B_PLIST_MAIN_CheckCancel((u8 **)p)==1) return 31;
    sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj03907 *)p)->f2184);
    switch(sel) {
    case 0:
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,7);
        if(B_PLIST_MAIN_PrintStatusMessage(p)==1) {
            q=*(u8 * *)&((struct Obj03907 *)p)->f0;
            if(q[31]!=2) {
                (q+q[33])[72]=B_PLIST_MAIN_GetOrderIndex(p,q[32]);
                return 31;
            }
            if(B_PLIST_MAIN_CanSwap(p)==0) {B_PLIST_MAIN_CommitSwap(p);return 31;}
            ((struct Obj03907 *)p)->f217C=19;return 29;
        }
        ((struct Obj03907 *)p)->f217C=21;return 29;
    case 1:
        if(B_PLIST_MAIN_IsRowFlagged(p)==1) break;
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,8);
        ((struct Obj03907 *)p)->f217C=13;return 29;
    case 2:
        if(B_PLIST_MAIN_IsRowFlagged(p)==1) break;
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,10);
        ((struct Obj03907 *)p)->f217C=14;return 29;
    case 3:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        ((struct Obj03907 *)p)->f217C=11;return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        ((struct Obj03907 *)p)->f217C=11;return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 4;
}
