/*
 * function: MYSTERY_TaskAlbumView
 * address: 0x021D7B4C
 * packet: pkt_ov121_021D7B4C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0207D63C 0x0207D63C arm
 *   MYSTERY_UTIL_SetTaskArg 0x021DA8C0 thumb ov121
 *   MYSTERY_UTIL_GetTaskArg 0x021DA8C4 thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   MYSTERY_SetScrollParam 0x021D9288 thumb ov121
 *   MYSTERY_DeleteCardMenu 0x021D8380 thumb ov121
 *   MYSTERY_UTIL_DeleteMenuWindow 0x021D9E04 thumb ov121
 *   MYSTERY_GRAPHIC_GetClactUnit 0x021D9744 thumb ov121
 *   MYSTERY_ALBUM_Create 0x021DAC18 thumb ov121
 *   MYSTERY_ALBUM_Update 0x021DAEF0 thumb ov121
 *   MYSTERY_ALBUM_GetWindowState 0x021DB008 thumb ov121
 *   MYSTERY_ALBUM_DeleteWork 0x021DAE1C thumb ov121
 *   MYSTERY_SetupBg 0x021D694C thumb ov121
 *   MYSTERY_TransferPalette 0x021D6C60 thumb ov121
 *   MYSTERY_UTIL_CreateMenuWindow 0x021D9CA4 thumb ov121
 *   MYSTERY_UTIL_DrawMenuWindow 0x021D9FFC thumb ov121
 *   MYSTERY_CreateCardMenu 0x021D81B0 thumb ov121
 *   MYSTERY_ALBUM_UpdateWindows 0x021DAFCC thumb ov121
 *   MYSTERY_TaskMenu 0x021D6E3C thumb ov121
 */
#include "../include/Obj00989.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 w[9]; } Desc;
typedef signed int     s32;
struct Obj;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern void MI_CpuFill8(void *,int,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void MYSTERY_UTIL_SetTaskArg(u32 *p, u32 a);
extern void MYSTERY_UTIL_GetTaskArg(u32 *p);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *p, u32 a);
typedef unsigned short u16;
extern void MYSTERY_SetScrollParam(unsigned *p, unsigned v);
extern void MYSTERY_DeleteCardMenu(char *p);
extern void MYSTERY_UTIL_DeleteMenuWindow(u8 *p);
extern unsigned MYSTERY_GRAPHIC_GetClactUnit(char *p);
extern void *MYSTERY_ALBUM_Create(Desc *,int);
extern void MYSTERY_ALBUM_Update(struct Obj *obj);
extern int MYSTERY_ALBUM_GetWindowState(char *p);
extern void MYSTERY_ALBUM_DeleteWork(struct Obj *obj);
extern void MYSTERY_SetupBg(u16 *p, int mode);
extern void MYSTERY_TransferPalette(u8 *p, int heap);
extern void *MYSTERY_UTIL_CreateMenuWindow(int a, u8 b, void *c, void *d, u16 heap);
extern void MYSTERY_UTIL_DrawMenuWindow(u8 *p, int a, int b);
extern void MYSTERY_CreateCardMenu(u8 *p, u32 which, int heap);
extern void MYSTERY_ALBUM_UpdateWindows(char *p);
extern void MYSTERY_TaskMenu(void *task, u32 *state, u8 *p);
void MYSTERY_TaskAlbumView(void *task,u32 *state,u8 *p)
{
    Desc d;
    switch(*state) {
    case 0:
        FADE_Start(3,0,16,-1);
        MYSTERY_UTIL_SetTaskArg(task,1);
        *state=8;
        break;
    case 1:
        MYSTERY_SetScrollParam((unsigned int *)(p+312),0);
        MYSTERY_DeleteCardMenu((char *)p);
        MYSTERY_UTIL_DeleteMenuWindow(((struct Obj00989 *)p)->f284);
        ((struct Obj00989 *)p)->f284=0;
        MI_CpuFill8(&d,0,36);
        d.w[0]=0;
        d.w[2]=(u32)MYSTERY_GRAPHIC_GetClactUnit(((struct Obj00989 *)p)->f394);
        d.w[3]=((struct Obj00989 *)p)->f3BC;
        d.w[4]=*(u32 *)&((struct Obj00989 *)p)->f398;
        d.w[5]=*(u32 *)&((struct Obj00989 *)p)->f39C;
        d.w[6]=((struct Obj00989 *)p)->f3A8;
        d.w[7]=((struct Obj00989 *)p)->f3A4;
        d.w[8]=((struct Obj00989 *)p)->f3B8;
        ((struct Obj00989 *)p)->f8=MYSTERY_ALBUM_Create(&d,29);
        *state=2;
        break;
    case 2:
        FADE_Start(3,16,0,-1);
        MYSTERY_UTIL_SetTaskArg(task,3);
        *state=8;
        break;
    case 3:
        MYSTERY_ALBUM_Update(((struct Obj00989 *)p)->f8);
        if(MYSTERY_ALBUM_GetWindowState(((struct Obj00989 *)p)->f8)) *state=4;
        break;
    case 4:
        FADE_Start(3,0,16,0);
        MYSTERY_UTIL_SetTaskArg(task,5);
        *state=8;
        break;
    case 5:
        MYSTERY_SetScrollParam((unsigned int *)(p+312),1);
        MYSTERY_ALBUM_DeleteWork(((struct Obj00989 *)p)->f8);
        ((struct Obj00989 *)p)->f8=0;
        MYSTERY_SetupBg((u16 *)(p+912),0);
        MYSTERY_TransferPalette(p+660,29);
        ((struct Obj00989 *)p)->f284=MYSTERY_UTIL_CreateMenuWindow(1,15,((struct Obj00989 *)p)->f39C,((struct Obj00989 *)p)->f398,29);
        MYSTERY_UTIL_DrawMenuWindow(((struct Obj00989 *)p)->f284,10,14);
        MYSTERY_CreateCardMenu(p,0,29);
        func_0207D63C((void *)0x04000050,4,24,15,3);
        *state=6;
        break;
    case 6:
        FADE_Start(3,16,0,0);
        MYSTERY_UTIL_SetTaskArg(task,7);
        *state=8;
        break;
    case 7:
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenu);
        break;
    case 8:
        if(!FADE_IsActive()) MYSTERY_UTIL_GetTaskArg(task);
        break;
    }
    if(((struct Obj00989 *)p)->f8) MYSTERY_ALBUM_UpdateWindows(((struct Obj00989 *)p)->f8);
}
