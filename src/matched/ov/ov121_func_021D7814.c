/*
 * function: MYSTERY_TaskAlbum
 * address: 0x021D7814
 * packet: pkt_ov121_021D7814
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x021D79BC writes the display blend register 0x04000050.
 * symbols:
 *   MYSTERY_GRAPHIC_StartRender 0x021D9750 thumb ov121
 *   func_02040588 0x02040588 arm
 *   MYSTERY_GRAPHIC_GetClactUnit 0x021D9744 thumb ov121
 *   MYSTERY_CreateReceivedMon 0x021D84D4 thumb ov121
 *   MYSTERY_InitCardView 0x021D8C1C thumb ov121
 *   MYSTERY_UTIL_SetMenuMessage 0x021D9F08 thumb ov121
 *   MYSTERY_UTIL_GetMenuState 0x021D9FF8 thumb ov121
 *   MYSTERY_StepCardView 0x021D8D00 thumb ov121
 *   MYSTERY_IsCardViewDone 0x021D8D18 thumb ov121
 *   MYSTERY_DATA_SaveStart 0x0200A2B8 thumb
 *   MYSTERY_DATA_SaveMain 0x0200A2D8 thumb
 *   MYSTERY_DeleteCardView 0x021D8CA8 thumb ov121
 *   MYSTERY_UTIL_DeleteMenuWindow 0x021D9E04 thumb ov121
 *   MYSTERY_DeleteCardMenu 0x021D8380 thumb ov121
 *   MYSTERY_GRAPHIC_StopRender 0x021D9790 thumb ov121
 *   MI_CpuFill8 0x02082BCC arm
 *   MYSTERY_ALBUM_CreateSlotWork 0x021DCFC8 thumb ov121
 *   MYSTERY_ALBUM_CreateAlbumView 0x021DD24C thumb ov121
 *   MYSTERY_ALBUM_RequestSetup 0x021DE0AC thumb ov121
 *   MYSTERY_ALBUM_StepIntro 0x021DD9CC thumb ov121
 *   MYSTERY_ALBUM_StartIntro 0x021DDF5C thumb ov121
 *   MYSTERY_ALBUM_IsIntroIdle 0x021DE014 thumb ov121
 *   KEY_GetTrg 0x020362DC arm
 *   MYSTERY_CreateOamSprite 0x021D93F4 thumb ov121
 *   MYSTERY_PollOamSprite 0x021D94B8 thumb ov121
 *   MYSTERY_DeleteOamSprite 0x021D9488 thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   MYSTERY_TaskExitAlbum 0x021D6DF4 thumb ov121
 */
#include "../include/Obj00297.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[12]; } Desc;
extern void MYSTERY_GRAPHIC_StartRender(u8 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern unsigned MYSTERY_GRAPHIC_GetClactUnit(char *p);
extern void MYSTERY_CreateReceivedMon(u8 *out, void *owner, const u8 *desc, void *save, void *list, void *a5, void *a6, u16 heap);
extern void MYSTERY_InitCardView(u8 *p, int mode);
extern void MYSTERY_UTIL_SetMenuMessage(u8 *a, int b, int c, int d);
extern unsigned MYSTERY_UTIL_GetMenuState(u8 *p);
extern void MYSTERY_StepCardView(char *p);
extern int MYSTERY_IsCardViewDone(char *p);
extern void MYSTERY_DATA_SaveStart(void *a0, int a1);
extern int MYSTERY_DATA_SaveMain(void *a0, int a1);
extern void MYSTERY_DeleteCardView(u8 *p);
extern void MYSTERY_UTIL_DeleteMenuWindow(u8 *p);
extern void MYSTERY_DeleteCardMenu(char *p);
extern void MYSTERY_GRAPHIC_StopRender(char *p);
extern void MI_CpuFill8(void *,int,int);
extern void *MYSTERY_ALBUM_CreateSlotWork(Desc *,u16);
extern void *MYSTERY_ALBUM_CreateAlbumView(void *,void *,void *,u16);
extern void MYSTERY_ALBUM_RequestSetup(u8 *p, u32 b);
extern void MYSTERY_ALBUM_StepIntro(char *p);
extern void MYSTERY_ALBUM_StartIntro(u8 *p);
extern int MYSTERY_ALBUM_IsIntroIdle(char *p);
extern u32 KEY_GetTrg(void);
extern void MYSTERY_CreateOamSprite(u8 *p, const void *q, int n, int k, int x, int y, int z, u16 heap);
extern int MYSTERY_PollOamSprite(char *p);
extern void MYSTERY_DeleteOamSprite(void **p);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *p, u32 a);
extern void MYSTERY_TaskExitAlbum(void *a, int *state);
void MYSTERY_TaskAlbum(void *task,u32 *state,u8 *p)
{
    Desc d;
    switch (*state) {
    case 0:
        MYSTERY_GRAPHIC_StartRender(((struct Obj00297 *)p)->f394);
        func_02040588(1,1);
        func_02040588(3,1);
        MYSTERY_CreateReceivedMon(p+12,(void *)MYSTERY_GRAPHIC_GetClactUnit(((struct Obj00297 *)p)->f394),p+972,(void *)(*(int *)&((struct Obj00297 *)p)->f3B8),p+660,p+912,p+312,29);
        MYSTERY_InitCardView(p+12,0);
        MYSTERY_UTIL_SetMenuMessage(((struct Obj00297 *)p)->f284,((struct Obj00297 *)p)->f3A4,113,2);
        *state=1;
        break;
    case 1:
        func_02040588(0,1);
        *state=2;
        break;
    case 2:
        if (MYSTERY_UTIL_GetMenuState(((struct Obj00297 *)p)->f284)) *state=3;
        break;
    case 3:
        MYSTERY_StepCardView((char *)(p+12));
        if (MYSTERY_IsCardViewDone((char *)(p+12))) *state=4;
        break;
    case 4:
        MYSTERY_DATA_SaveStart(((struct Obj00297 *)p)->f3BC,(int)(((struct Obj00297 *)p)->f3B8));
        *state=5;
        break;
    case 5:
        if (MYSTERY_DATA_SaveMain(((struct Obj00297 *)p)->f3BC,(int)(((struct Obj00297 *)p)->f3B8))==2) *state=6;
        break;
    case 6:
        MYSTERY_InitCardView(p+12,1);
        *state=7;
        break;
    case 7:
        MYSTERY_StepCardView((char *)(p+12));
        if (MYSTERY_IsCardViewDone((char *)(p+12))) *state=8;
        break;
    case 8:
        MYSTERY_UTIL_SetMenuMessage(((struct Obj00297 *)p)->f284,((struct Obj00297 *)p)->f3A4,114,1);
        *state=9;
        break;
    case 9:
        if (MYSTERY_UTIL_GetMenuState(((struct Obj00297 *)p)->f284)) *state=10;
        break;
    case 10:
        MYSTERY_DeleteCardView(p+12);
        MYSTERY_UTIL_DeleteMenuWindow(((struct Obj00297 *)p)->f284);
        ((struct Obj00297 *)p)->f284=0;
        MYSTERY_DeleteCardMenu((char *)p);
        *(volatile u16 *)0x04000050=0;
        MYSTERY_GRAPHIC_StopRender(((struct Obj00297 *)p)->f394);
        func_02040588(1,1);
        func_02040588(3,1);
        *state=11;
        break;
    case 11:
        func_02040588(0,1);
        *state=12;
        break;
    case 12:
        func_02040588(1,0);
        MI_CpuFill8(&d,0,48);
        d.w[0]=2;
        d.w[1]=0;
        d.w[2]=8;
        d.w[3]=15;
        d.w[5]=13;
        d.w[4]=10;
        d.w[6]=(u32)MYSTERY_GRAPHIC_GetClactUnit(((struct Obj00297 *)p)->f394);
        d.w[7]=*(u32 *)&((struct Obj00297 *)p)->f3BC;
        d.w[8]=*(u32 *)&((struct Obj00297 *)p)->f3A4;
        d.w[9]=((struct Obj00297 *)p)->f398;
        d.w[10]=((struct Obj00297 *)p)->f39C;
        d.w[11]=((struct Obj00297 *)p)->f3A8;
        ((struct Obj00297 *)p)->f4=MYSTERY_ALBUM_CreateSlotWork(&d,29);
        ((struct Obj00297 *)p)->f0=MYSTERY_ALBUM_CreateAlbumView(p+972,((struct Obj00297 *)p)->f4,((struct Obj00297 *)p)->f3B8,29);
        MYSTERY_ALBUM_RequestSetup(((struct Obj00297 *)p)->f0,0);
        *state=13;
        break;
    case 13:
        MYSTERY_ALBUM_StepIntro(((struct Obj00297 *)p)->f0);
        MYSTERY_ALBUM_StartIntro(((struct Obj00297 *)p)->f0);
        *state=14;
        break;
    case 14:
        MYSTERY_ALBUM_StepIntro(((struct Obj00297 *)p)->f0);
        if (MYSTERY_ALBUM_IsIntroIdle(((struct Obj00297 *)p)->f0)) {
            ((struct Obj00297 *)p)->f3C4=0;
            *state=15;
        }
        break;
    case 15:
        if (KEY_GetTrg()&1) *state=18;
        if ((((struct Obj00297 *)p)->f3C4)++>240) {
            ((struct Obj00297 *)p)->f3C4=0;
            *state=16;
        }
        break;
    case 16:
        MYSTERY_CreateOamSprite(p+612,p+660,(int)MYSTERY_GRAPHIC_GetClactUnit(((struct Obj00297 *)p)->f394),*(int *)&((struct Obj00297 *)p)->f39C,((struct Obj00297 *)p)->f3A4,155,*(int *)&((struct Obj00297 *)p)->f398,29);
        MYSTERY_PollOamSprite((char *)(p+612));
        *state=17;
        break;
    case 17:
        MYSTERY_PollOamSprite((char *)(p+612));
        if (KEY_GetTrg()&1) {
            MYSTERY_DeleteOamSprite((void **)(p+612));
            *state=18;
        }
        break;
    case 18:
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskExitAlbum);
        break;
    }
}
