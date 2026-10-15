/*
 * function: IRC_COMPATIBLE_MENU_ProcInit
 * address: 0x021B7560
 * packet: pkt_ov102_021B7560
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: repeat the callback call in cases 0,1,2; cross-jumping preserves the case-0 branch into case 2. A grouped case or pointer join loses two bytes and pool alignment.
 * prototype: 3064C forwards all three inputs, including size 0x40000, to 0202FDC4; 3159C full body leaves allocated pointer live in r0; 879C preserves visible unused heap. 78F4 forwards to full 7C1C ldr r0,[r0];bx lr.
 * symbols:
 * GFL_HEAP_CreateChildHeap 0x0203064C arm
 * PROCSYS_AllocProcWork 0x0203159C arm
 * MI_CpuFill8 0x02082BCC arm
 * IRC_COMPATIBLE_MENU_InitText 0x021B7C20 thumb ov102
 * IRC_COMPATIBLE_MENU_InitDisplay 0x021B7860 thumb ov102
 * IRC_COMPATIBLE_MENU_InitBackgrounds 0x021B7908 thumb ov102
 * ICA_ANIME_GetField24 0x02012138 thumb
 * IRC_COMPATIBLE_MENU_InitButtons 0x021B8464 thumb ov102
 * IRC_COMPATIBLE_MENU_InitTitleWindow 0x021B7CC8 thumb ov102
 * BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 * IRC_COMPATIBLE_MENU_PrintMessage 0x021B7DFC thumb ov102
 * IRC_COMPATIBLE_MENU_InitWindow 0x021B7D38 thumb ov102
 * IRC_COMPATIBLE_MENU_PrintMessageCentered 0x021B7E60 thumb ov102
 * BG_SYS_SetScrollY 0x02041F6C arm
 * BG_SYS_SetAffine 0x02041FB0 arm
 * IRC_COMPATIBLE_MENU_InitScrollEffect 0x021B879C thumb ov102
 * ICA_ANIME_GetField1C 0x020120F4 thumb
 * GAME_DATA_GetSaveControl 0x02012EBC thumb
 * func_020070A4 0x020070A4 thumb
 * IRC_RANKING_GetFromSave 0x0200A8A0 thumb
 * IRC_COMPATIBLE_MENU_InitFloaters 0x021B8934 thumb ov102
 * IRC_COMPATIBLE_MENU_GetSpriteUnit 0x021B78F4 thumb ov102
 * IRC_COMPATIBLE_MENU_TextGetFont 0x021B7CBC thumb ov102
 * IRC_COMPATIBLE_MENU_TextGetPrintQueue 0x021B7CC0 thumb ov102
 * IRC_APPBAR_Create 0x021B70DC thumb ov101
 * IRC_COMPATIBLE_MENU_SetHandler 0x021B7F08 thumb ov102
 * IRC_COMPATIBLE_MENU_HandleOpen 0x021B8320 thumb ov102
 * IRC_COMPATIBLE_MENU_HandleChoice 0x021B81B0 thumb ov102
 * GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 * COMPATIBLE_IRC_SYS_SetOwnValue 0x021B63CC thumb ov101
 * IRC_COMPATIBLE_MENU_ButtonRows 0x021B8AD4 data a4
 */
#include "../include/Obj03229.h"
#include "../include/Obj22136.h"
#include "../include/Obj22137.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern void GFL_HEAP_CreateChildHeap(u32 src,u32 dst,u32 size);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
extern void IRC_COMPATIBLE_MENU_InitText(u32 *,u16);
extern void IRC_COMPATIBLE_MENU_InitDisplay(char *,u32);
extern void IRC_COMPATIBLE_MENU_InitBackgrounds(u32 *,u16);
struct Big;
struct Ctx;
struct Sub02007084Ctrl;
extern u32 ICA_ANIME_GetField24(const struct Ctx *p);
struct Row;
struct State;
extern void IRC_COMPATIBLE_MENU_InitButtons(struct State *p, int bg, const struct Row *rows, int count, void *object, u16 heap);
extern void IRC_COMPATIBLE_MENU_InitTitleWindow(void *,int,int,u8,u8,u8,u8,u16);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void IRC_COMPATIBLE_MENU_PrintMessage(u8 *,void *,int,int,s16);
extern void IRC_COMPATIBLE_MENU_InitWindow(u8 *,int,int,u8,u8,u8,u8,u16,u8,u16);
extern void IRC_COMPATIBLE_MENU_PrintMessageCentered(u8 *,void *,int);
extern void BG_SYS_SetScrollY(u32 which, u32 op, u32 value);
extern void BG_SYS_SetAffine(u32,u32,u16);
extern void IRC_COMPATIBLE_MENU_InitScrollEffect(void *,u32);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern void *IRC_RANKING_GetFromSave(void *);
extern void IRC_COMPATIBLE_MENU_InitFloaters(u8 *a, void *b, void *c, int d);
extern unsigned IRC_COMPATIBLE_MENU_GetSpriteUnit(unsigned *p);
extern int IRC_COMPATIBLE_MENU_TextGetFont(void *);
extern int IRC_COMPATIBLE_MENU_TextGetPrintQueue(void *);
extern void *IRC_APPBAR_Create(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void IRC_COMPATIBLE_MENU_SetHandler(unsigned p, unsigned x);
extern void IRC_COMPATIBLE_MENU_HandleOpen(u8 *,u16 *),IRC_COMPATIBLE_MENU_HandleChoice(u8 *,u16 *);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void COMPATIBLE_IRC_SYS_SetOwnValue(int *,int);
extern u32 IRC_COMPATIBLE_MENU_ButtonRows[];
int IRC_COMPATIBLE_MENU_ProcInit(void *owner,int unused,void *arg)
{
    u8 *p;
    void *save;
    u32 handle;
    int first,second;
    GFL_HEAP_CreateChildHeap(1,59,0x40000);
    p=PROCSYS_AllocProcWork(owner,0x4a4,59);
    MI_CpuFill8(p,0,0x4a4);
    ((struct Obj03229 *)p)->f48C=arg;
    IRC_COMPATIBLE_MENU_InitText((u32 *)(p+0x9c),59);
    IRC_COMPATIBLE_MENU_InitDisplay((char *)p,59);
    IRC_COMPATIBLE_MENU_InitBackgrounds((u32 *)(p+0x94),59);
    if(**(void ** *)&((struct Obj03229 *)p)->f48C) ICA_ANIME_GetField24(**(void ** *)&((struct Obj03229 *)p)->f48C);
    IRC_COMPATIBLE_MENU_InitButtons((struct State *)(p+0xc0),2,(const struct Row *)IRC_COMPATIBLE_MENU_ButtonRows,2,p+0x9c,59);
    IRC_COMPATIBLE_MENU_InitTitleWindow(p+0xac,5,1,18,30,5,8,59);
    BMP_MENUWORK_DrawWindow(((struct Obj03229 *)p)->fAC,0,(u16)(((struct Obj03229 *)p)->f94),6);
    IRC_COMPATIBLE_MENU_PrintMessage(p+0xac,p+0x9c,5,0,0);
    IRC_COMPATIBLE_MENU_InitWindow(p+0x46c,7,6,3,20,5,8,1,1,59);
    IRC_COMPATIBLE_MENU_PrintMessageCentered(p+0x46c,p+0x9c,10);
    BG_SYS_SetScrollY(7,3,0x1000);
    BG_SYS_SetScrollY(7,6,0x1000);
    BG_SYS_SetAffine(7,9,128);
    BG_SYS_SetAffine(7,12,40);
    IRC_COMPATIBLE_MENU_InitScrollEffect(p+0xfc,59);
    save=**(void ** *)&((struct Obj03229 *)p)->f48C;
    if(save) save=GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(save));
    else save=func_020070A4();
    IRC_COMPATIBLE_MENU_InitFloaters((u8 *)((int)(p+0x118)),(void *)((int)p),(void *)((int)IRC_RANKING_GetFromSave(save)),59);
    handle=IRC_COMPATIBLE_MENU_GetSpriteUnit((unsigned int *)p);
    first=IRC_COMPATIBLE_MENU_TextGetFont(p+0x9c);
    second=IRC_COMPATIBLE_MENU_TextGetPrintQueue(p+0x9c);
    ((struct Obj03229 *)p)->f468=IRC_APPBAR_Create(2,handle,0,14,0,2,first,second,59);
    switch(((struct Obj22136 *)(*(u8 * *)&((struct Obj03229 *)p)->f48C))->f8) {
    case 0: IRC_COMPATIBLE_MENU_SetHandler((unsigned int)p,(unsigned int)IRC_COMPATIBLE_MENU_HandleChoice); break;
    case 1: IRC_COMPATIBLE_MENU_SetHandler((unsigned int)p,(unsigned int)IRC_COMPATIBLE_MENU_HandleOpen); break;
    case 2: IRC_COMPATIBLE_MENU_SetHandler((unsigned int)p,(unsigned int)IRC_COMPATIBLE_MENU_HandleChoice); break;
    }
    GFL_USE_CancelChangeAndStopBgm();
    COMPATIBLE_IRC_SYS_SetOwnValue(*(int * *)&((struct Obj22137 *)(*(u8 * *)&((struct Obj03229 *)p)->f48C))->f4,0);
    return 1;
}
