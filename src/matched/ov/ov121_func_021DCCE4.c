/*
 * function: MYSTERY_ALBUM_SaveHandler
 * address: 0x021DCCE4
 * packet: pkt_ov121_021DCCE4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: separate case-1 guard tests preserve the branch to the shared state store; a short-circuit guard gives DIFF404.
 * symbols:
 *   MYSTERY_UTIL_CreateMenuWindow 0x021D9CA4 thumb ov121
 *   MYSTERY_UTIL_DrawMenuWindow 0x021D9FFC thumb ov121
 *   MYSTERY_UTIL_SetMenuMessage 0x021D9F08 thumb ov121
 *   MYSTERY_UTIL_GetMenuState 0x021D9FF8 thumb ov121
 *   MYSTERY_UTIL_DeleteMenuWindow 0x021D9E04 thumb ov121
 *   MYSTERY_UTIL_UpdateMenuWindow 0x021D9E50 thumb ov121
 *   MYSTERY_UTIL_CreateMenu 0x021DA038 thumb ov121
 *   MYSTERY_UTIL_DeleteMenu 0x021DA148 thumb ov121
 *   MYSTERY_UTIL_UpdateMenu 0x021DA178 thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   MYSTERY_UTIL_MarkTaskDone 0x021DA8B8 thumb ov121
 *   MYSTERY_ALBUM_SelectHandler 0x021DC08C thumb ov121
 *   MYSTERY_ALBUM_IsIntroIdle 0x021DE014 thumb ov121
 *   MYSTERY_DATA_HasCardSpace 0x0200A0C8 thumb
 *   MYSTERY_DATA_SaveStart 0x0200A2B8 thumb
 *   MYSTERY_DATA_SaveMain 0x0200A2D8 thumb
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj00253.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 v[7];u16 a,b,c,d;} Desc;
extern void *MYSTERY_UTIL_CreateMenuWindow(int a, unsigned char b, void *c, void *d, u16 heap);
typedef unsigned char  u8;
extern void MYSTERY_UTIL_DrawMenuWindow(u8 *p, int a, int b);
extern void MYSTERY_UTIL_SetMenuMessage(u8 *a, int b, int c, int d);
extern unsigned MYSTERY_UTIL_GetMenuState(u8 *p);
extern void MYSTERY_UTIL_DeleteMenuWindow(u8 *p);
extern void MYSTERY_UTIL_UpdateMenuWindow(u8 *p);
extern void *MYSTERY_UTIL_CreateMenu(const u8 *p, u16 heap);
extern void MYSTERY_UTIL_DeleteMenu(u8 *p);
extern int MYSTERY_UTIL_UpdateMenu(char *p);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *p, u32 a);
extern void MYSTERY_UTIL_MarkTaskDone(u32 *p);
extern void MYSTERY_ALBUM_SelectHandler(void *task, u32 *state, char *p);
extern int MYSTERY_ALBUM_IsIntroIdle(char *p);
extern u32 MYSTERY_DATA_HasCardSpace(u8 *p);
extern void MYSTERY_DATA_SaveStart(void *a0, int a1);
extern int MYSTERY_DATA_SaveMain(void *a0, int a1);
extern void MI_CpuFill8(void *,int,int);
void MYSTERY_ALBUM_SaveHandler(void *arg,u32 *state,char *p)
{
    Desc d;
    int result;
    int ready;
    switch (*state) {
    case 0:
        *state=1;
        break;
    case 1:
        if (!((struct Obj00253 *)p)->f0) *state=5;
        else if (MYSTERY_DATA_HasCardSpace(((struct Obj00253 *)p)->fC)) *state=5;
        else *state=2;
        break;
    case 2:
        if (!((struct Obj00253 *)p)->fABC) {
            ((struct Obj00253 *)p)->fABC=MYSTERY_UTIL_CreateMenuWindow(0,15,((struct Obj00253 *)p)->f14,((struct Obj00253 *)p)->f10,29);
            MYSTERY_UTIL_DrawMenuWindow(((struct Obj00253 *)p)->fABC,1,13);
        }
        MYSTERY_UTIL_SetMenuMessage(((struct Obj00253 *)p)->fABC,((struct Obj00253 *)p)->f1C,93,1);
        *state=3;
        break;
    case 3:
        if (MYSTERY_UTIL_GetMenuState(((struct Obj00253 *)p)->fABC)) {
            MI_CpuFill8(&d,0,36);
            d.v[0]=*(u32 *)&((struct Obj00253 *)p)->f1C;
            d.v[1]=*(u32 *)&((struct Obj00253 *)p)->f10;
            d.v[2]=*(u32 *)&((struct Obj00253 *)p)->f14;
            d.v[3]=124;
            d.v[4]=125;
            d.v[6]=2;
            d.a=0; d.b=15; d.c=13; d.d=1;
            ((struct Obj00253 *)p)->fAC0=MYSTERY_UTIL_CreateMenu((const u8 *)(&d),((struct Obj00253 *)p)->f24);
            *state=4;
        }
        break;
    case 4:
        result=MYSTERY_UTIL_UpdateMenu(((struct Obj00253 *)p)->fAC0);
        ((struct Obj00253 *)p)->fBAC=0x7fff;
        if (result!=-1) {
            MYSTERY_UTIL_DeleteMenu(((struct Obj00253 *)p)->fAC0);
            ((struct Obj00253 *)p)->fAC0=0;
            if (!result) *state=5;
            else {
                if (((struct Obj00253 *)p)->fABC) {
                    MYSTERY_UTIL_DeleteMenuWindow(((struct Obj00253 *)p)->fABC);
                    ((struct Obj00253 *)p)->fABC=0;
                }
                MYSTERY_UTIL_SetTaskHandler(arg,(u32)MYSTERY_ALBUM_SelectHandler);
            }
        }
        break;
    case 5:
        if (((struct Obj00253 *)p)->fAD4) *state=6;
        else *state=10;
        break;
    case 6:
        if (!((struct Obj00253 *)p)->fABC) {
            ((struct Obj00253 *)p)->fABC=MYSTERY_UTIL_CreateMenuWindow(0,15,((struct Obj00253 *)p)->f14,((struct Obj00253 *)p)->f10,29);
            MYSTERY_UTIL_DrawMenuWindow(((struct Obj00253 *)p)->fABC,1,13);
        }
        MYSTERY_UTIL_SetMenuMessage(((struct Obj00253 *)p)->fABC,((struct Obj00253 *)p)->f1C,115,2);
        *state=7;
        break;
    case 7:
        if (MYSTERY_UTIL_GetMenuState(((struct Obj00253 *)p)->fABC)) *state=8;
        break;
    case 8:
        ready=1;
        if (((struct Obj00253 *)p)->fAAC && !MYSTERY_ALBUM_IsIntroIdle(((struct Obj00253 *)p)->fAAC)) ready=0;
        if (ready) {
            MYSTERY_DATA_SaveStart(((struct Obj00253 *)p)->fC,(int)(((struct Obj00253 *)p)->f20));
            *state=9;
        }
        break;
    case 9:
        if (MYSTERY_DATA_SaveMain(((struct Obj00253 *)p)->fC,(int)(((struct Obj00253 *)p)->f20))==2) *state=10;
        break;
    case 10:
        if (((struct Obj00253 *)p)->fABC) {
            MYSTERY_UTIL_DeleteMenuWindow(((struct Obj00253 *)p)->fABC);
            ((struct Obj00253 *)p)->fABC=0;
        }
        MYSTERY_UTIL_MarkTaskDone(arg);
        break;
    }
    if (((struct Obj00253 *)p)->fABC) MYSTERY_UTIL_UpdateMenuWindow(((struct Obj00253 *)p)->fABC);
}
