/*
 * function: func_0220F9F8
 * address: 0x0220F9F8
 * packet: pkt_ov198_0220F9F8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   func_02211958 0x02211958 thumb ov198
 *   func_02211970 0x02211970 thumb ov198
 *   B_PLIST_ANM_StartPaletteAnim 0x0220B760 thumb ov198
 *   func_02210B30 0x02210B30 thumb ov198
 */
#include "../include/Obj03908.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sound;
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *);
extern void func_02211970(u8 **,u32);
extern void B_PLIST_ANM_StartPaletteAnim(u8 *,u32);
extern u32 func_02210F1C(u8 *p);
extern u32 func_02211958(u8 **);
extern u8 func_02210B30(u8 *,int,int);
int func_0220F9F8(u8 *p)
{
    u32 sel;
    u8 next;
    if(func_02211958((u8 **)p)==1)return 31;
    sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj03908 *)p)->f2184);
    switch(sel){
    case 0:
        next=func_02210B30(p,(*(u8 **)p)[0x20],-1);
        if(next!=255){
            (*(u8 **)p)[0x20]=next;
            func_02211970((u8 **)p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,12);
            ((struct Obj03908 *)p)->f217C=20;
            return 29;
        }
        break;
    case 1:
        next=func_02210B30(p,(*(u8 **)p)[0x20],1);
        if(next!=255){
            (*(u8 **)p)[0x20]=next;
            func_02211970((u8 **)p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,13);
            ((struct Obj03908 *)p)->f217C=20;
            return 29;
        }
        break;
    case 2:
        func_02211970((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,11);
        ((struct Obj03908 *)p)->f217C=14;
        return 29;
    case 3:
        func_02211970((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p[0x2190]=1;
        ((struct Obj03908 *)p)->f217C=12;
        return 29;
    case (u32)-2:
        func_02211970((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p[0x2190]=1;
        ((struct Obj03908 *)p)->f217C=12;
        return 29;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 5;
}
