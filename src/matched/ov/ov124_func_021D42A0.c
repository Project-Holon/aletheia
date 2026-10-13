/*
 * function: func_021D42A0
 * address: 0x021D42A0
 * packet: pkt_ov124_021D42A0
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: existing follower 021D43F0 remains in its separately verified file.
 * symbols:
 *   func_021D48A4 0x021D48A4 thumb ov124
 *   func_021D49C8 0x021D49C8 thumb ov124
 *   func_020362DC 0x020362DC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0204A600 0x0204A600 arm
 *   func_02045334 0x02045334 arm
 *   func_02040618 0x02040618 arm
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb  arm9
 *   APP_TASKMENU_WIN_ResetDecide  0x020282A4  thumb  arm9
 *   APP_TASKMENU_WIN_ClearScreen  0x0202843C  thumb  arm9
 *   APP_TASKMENU_WIN_TransChar  0x02028454  thumb  arm9
 */
#include "../include/Obj00122.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
struct Descriptor;
struct Obj;
struct PrintSys;
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void func_021D48A4(char *);
extern u32 func_020362DC(void);
extern void func_02041B6C(u32 bit);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern void func_02028178(u8 *p);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02045334(struct Descriptor *d);
extern void func_021D49C8(char *,u32);
extern void APP_TASKMENU_WIN_ResetDecide(struct Obj *obj);
extern void APP_TASKMENU_WIN_ClearScreen(u8 *p);
extern void APP_TASKMENU_WIN_TransChar(u8 *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
int func_021D42A0(char *p)
{
    switch(((struct Obj00122 *)p)->f10) {
    case 0:
        func_0202208C((void *)4,1,1,0,6,1,((struct Obj00122 *)p)->f0);
        ((struct Obj00122 *)p)->f10=1;
        break;
    case 1:
        if(func_020221A4()==1) ((struct Obj00122 *)p)->f10=4;
        break;
    case 2:
        if(APP_TASKMENU_WIN_IsFinish(((struct Obj00122 *)p)->f40)==1) {
            func_0202208C((void *)4,0,0,0,6,1,((struct Obj00122 *)p)->f0);
            ((struct Obj00122 *)p)->f10=3;
        }
        break;
    case 3:
        if(func_020221A4()==1) return 1;
        break;
    case 4:
        if(!((struct Obj00122 *)p)->f1C) func_021D48A4(p);
        if(func_020362DC()&4) func_02041B6C(4);
        break;
    }
    func_0201C4E4(((struct Obj00122 *)p)->f30);
    func_0204A600();
    if(((struct Obj00122 *)p)->f3C) func_02028178(((struct Obj00122 *)p)->f3C);
    if(((struct Obj00122 *)p)->f38) func_02028178(((struct Obj00122 *)p)->f38);
    func_02028178(((struct Obj00122 *)p)->f40);
    if(((struct Obj00122 *)p)->f1C==1 && func_0201C6B4(((struct Obj00122 *)p)->f30)==1 &&
       (APP_TASKMENU_WIN_IsFinish(((struct Obj00122 *)p)->f3C)==1 || APP_TASKMENU_WIN_IsFinish(((struct Obj00122 *)p)->f38)==1 || ((struct Obj00122 *)p)->fC==1)) {
        func_02045334(((struct Obj00122 *)p)->f20);
        func_02045334(((struct Obj00122 *)p)->f24);
        ((struct Obj00122 *)p)->f1C=0;
        ((struct Obj00122 *)p)->fC=0;
        func_021D49C8(p,((struct Obj00122 *)p)->f18);
        if(((struct Obj00122 *)p)->f18==11) {
            APP_TASKMENU_WIN_ResetDecide(((struct Obj00122 *)p)->f3C);
            APP_TASKMENU_WIN_ClearScreen(((struct Obj00122 *)p)->f3C);
        } else {
            APP_TASKMENU_WIN_TransChar(((struct Obj00122 *)p)->f3C);
            APP_TASKMENU_WIN_ResetDecide(((struct Obj00122 *)p)->f3C);
        }
        if(((struct Obj00122 *)p)->f18==0) {
            APP_TASKMENU_WIN_ResetDecide(((struct Obj00122 *)p)->f38);
            APP_TASKMENU_WIN_ClearScreen(((struct Obj00122 *)p)->f38);
        } else {
            APP_TASKMENU_WIN_TransChar(((struct Obj00122 *)p)->f38);
            APP_TASKMENU_WIN_ResetDecide(((struct Obj00122 *)p)->f38);
        }
    }
    func_02040618(7,5,1);
    return 0;
}
