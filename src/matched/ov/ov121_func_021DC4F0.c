/*
 * function: MYSTERY_ALBUM_ConfirmHandler
 * address: 0x021DC4F0
 * packet: pkt_ov121_021DC4F0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_UTIL_CreateMenuWindow 0x021D9CA4 thumb ov121
 *   MYSTERY_UTIL_CreateMenuWindow2 0x021D9D4C thumb ov121
 *   MYSTERY_UTIL_DrawMenuWindow 0x021D9FFC thumb ov121
 *   MYSTERY_UTIL_SetMenuMessage 0x021D9F08 thumb ov121
 *   MYSTERY_UTIL_CreateMenu 0x021DA038 thumb ov121
 *   MYSTERY_UTIL_UpdateMenu 0x021DA178 thumb ov121
 *   MYSTERY_UTIL_DeleteMenu 0x021DA148 thumb ov121
 *   MYSTERY_UTIL_DeleteMenuWindow 0x021D9E04 thumb ov121
 *   MYSTERY_UTIL_UpdateMenuWindow 0x021D9E50 thumb ov121
 *   MYSTERY_UTIL_GetMenuState 0x021D9FF8 thumb ov121
 *   MYSTERY_ALBUM_GetEntryEggFlag 0x021DC030 thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   MYSTERY_ALBUM_SelectHandler 0x021DC08C thumb ov121
 *   MYSTERY_ALBUM_InfoHandler 0x021DC734 thumb ov121
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   data_021DF86E 0x021DF86E data a1
 */
#include "../include/Obj00169.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 v[7]; u16 a,b,c,d; } Desc;
typedef struct { short x,y; } Vec;
typedef struct { u8 x,y,pad[6]; } Coord;
extern const Coord data_021DF86E[];
struct Obj;
struct Vec2;
extern void *MYSTERY_UTIL_CreateMenuWindow(int a, u8 b, void *c, void *d, u16 heap);
extern void *MYSTERY_UTIL_CreateMenuWindow2(int a, u8 b, void *c, void *d, u16 heap);
struct Obj;
extern void MYSTERY_UTIL_DrawMenuWindow(u8 *p, int a, int b);
extern void MYSTERY_UTIL_SetMenuMessage(u8 *a, int b, int c, int d);
extern void *MYSTERY_UTIL_CreateMenu(const u8 *p, u16 heap);
extern int MYSTERY_UTIL_UpdateMenu(char *p);
extern void MYSTERY_UTIL_DeleteMenu(u8 *p);
extern void MYSTERY_UTIL_DeleteMenuWindow(u8 *);
extern void MYSTERY_UTIL_UpdateMenuWindow(u8 *);
extern unsigned MYSTERY_UTIL_GetMenuState(u8 *p);
extern int MYSTERY_ALBUM_GetEntryEggFlag(u32 p);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *p, u32 a);
extern void MYSTERY_ALBUM_SelectHandler(void *task, u32 *state, char *p);
extern void MYSTERY_ALBUM_InfoHandler(void *task, u32 *state, char *p);
extern void MI_CpuFill8(void *,int,u32);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void MYSTERY_ALBUM_ConfirmHandler(void *task,u32 *state,u8 *p)
{
    Desc d;
    Vec v;
    int result;
    switch (*state) {
    case 0:
        if (!((struct Obj00169 *)p)->fABC) {
            ((struct Obj00169 *)p)->fABC=MYSTERY_UTIL_CreateMenuWindow(0,15,((struct Obj00169 *)p)->f14,((struct Obj00169 *)p)->f10,29);
            MYSTERY_UTIL_DrawMenuWindow(((struct Obj00169 *)p)->fABC,1,13);
        }
        MYSTERY_UTIL_SetMenuMessage(((struct Obj00169 *)p)->fABC,((struct Obj00169 *)p)->f1C,116,0);
        *state=1;
        break;
    case 1:
        MI_CpuFill8(&d,0,36);
        d.v[0]=*(u32 *)&((struct Obj00169 *)p)->f1C; d.v[1]=*(u32 *)&((struct Obj00169 *)p)->f10; d.v[2]=*(u32 *)&((struct Obj00169 *)p)->f14;
        d.v[3]=117;d.v[4]=118;d.v[5]=119;d.v[6]=3;
        d.a=0;d.b=15;d.c=13;d.d=1;
        ((struct Obj00169 *)p)->fAC0=MYSTERY_UTIL_CreateMenu((const u8 *)(&d),((struct Obj00169 *)p)->f24);
        *state=2;
        break;
    case 2:
        result=MYSTERY_UTIL_UpdateMenu(((struct Obj00169 *)p)->fAC0);
        ((struct Obj00169 *)p)->fBAC=0x7fff;
        if (result==-1) break;
        if (result==0) {
            ((struct Obj00169 *)p)->fAE0=1;
            v.x=data_021DF86E[*(u32 *)(p+0xacc)].x*8-24;
            v.y=data_021DF86E[*(u32 *)(p+0xacc)].y*8-8;
            CLACT_AddActorSurfacePos(((struct Obj00169 *)p)->fAF0,(const struct Vec2 *)(&v),0);
            CLACT_SetActorDrawEnable(((struct Obj00169 *)p)->fAF0,1);
            ((struct Obj00169 *)p)->fADE=((struct Obj00169 *)p)->fACC+((struct Obj00169 *)p)->fAC8*4;
            if (((struct Obj00169 *)p)->fAC0) {MYSTERY_UTIL_DeleteMenu(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;}
            if (*(u8 * *)&((struct Obj00169 *)p)->fABC) {MYSTERY_UTIL_DeleteMenuWindow(*(u8 * *)&((struct Obj00169 *)p)->fABC);((struct Obj00169 *)p)->fABC=0;}
            if (!((struct Obj00169 *)p)->fABC) {
                ((struct Obj00169 *)p)->fABC=MYSTERY_UTIL_CreateMenuWindow2(0,15,((struct Obj00169 *)p)->f14,((struct Obj00169 *)p)->f10,29);
                MYSTERY_UTIL_DrawMenuWindow(((struct Obj00169 *)p)->fABC,1,13);
            }
            MYSTERY_UTIL_SetMenuMessage(((struct Obj00169 *)p)->fABC,((struct Obj00169 *)p)->f1C,122,0);
            *state=6;
        } else if (result==1) {
            if (MYSTERY_ALBUM_GetEntryEggFlag((u32)((void *)((u32)p+40+220*(((struct Obj00169 *)p)->fACC+((struct Obj00169 *)p)->fAC8*4))))) *state=7;
            else *state=3;
        } else if (result==2) *state=5;
        break;
    case 3:
        if (((struct Obj00169 *)p)->fAC0) {MYSTERY_UTIL_DeleteMenu(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;}
        MYSTERY_UTIL_SetMenuMessage(((struct Obj00169 *)p)->fABC,((struct Obj00169 *)p)->f1C,120,1);
        *state=4;
        break;
    case 4:
        if (MYSTERY_UTIL_GetMenuState(((struct Obj00169 *)p)->fABC)) *state=5;
        break;
    case 5:
        if (*(u8 * *)&((struct Obj00169 *)p)->fABC) {MYSTERY_UTIL_DeleteMenuWindow(*(u8 * *)&((struct Obj00169 *)p)->fABC);((struct Obj00169 *)p)->fABC=0;}
        if (((struct Obj00169 *)p)->fAC0) {MYSTERY_UTIL_DeleteMenu(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;}
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SelectHandler);
        break;
    case 6:
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SelectHandler);
        break;
    case 7:
        MYSTERY_UTIL_DeleteMenu(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_InfoHandler);
        break;
    }
    if (*(u8 * *)&((struct Obj00169 *)p)->fABC) MYSTERY_UTIL_UpdateMenuWindow(*(u8 * *)&((struct Obj00169 *)p)->fABC);
}
