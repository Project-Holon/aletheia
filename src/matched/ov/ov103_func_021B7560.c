/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_ProcInit
 * address: 0x021B7560
 * packet: pkt_ov103_021B7560
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: write argument byte 17 through the stored p+0xb0c pointer; the direct argument store loses the scratch copy and shifts the remaining code by two bytes.
 * prototype: 3064C preserves explicitly loaded third input; 3159C leaves allocator return live at 020315C0-C8. 7948 tail-forwards to 7C64's full-word getter. 1F73C's third input is explicitly narrowed at 021B75EC-F0.
 * volatile: DISPCNT read/write 021B76D2-DE; WININ re-read 021B76E4/EE, WINOUT 021B76FC; window-position hardware writes 021B770C-1C.
 * symbols:
 * GFL_HEAP_CreateChildHeap 0x0203064C arm
 * PROCSYS_AllocProcWork 0x0203159C arm
 * MI_CpuFill8 0x02082BCC arm
 * IRC_COMPATIBLE_TOUCH_TEST_InitExchange 0x021B8AF4 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_InitScene 0x021B787C thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_InitText 0x021B7F7C thumb ov103
 * ICA_ANIME_GetField24 0x02012138 thumb
 * IRC_COMPATIBLE_TOUCH_TEST_InitTitleWindow 0x021B800C thumb ov103
 * BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 * IRC_COMPATIBLE_TOUCH_TEST_InitWindow 0x021B8074 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_PrintMessageCentered 0x021B81A4 thumb ov103
 * BG_SYS_ChangeScale 0x02041F6C arm
 * BG_SYS_ChangeCenter 0x02041FB0 arm
 * IRC_COMPATIBLE_TOUCH_TEST_ClearStroke 0x021B91A8 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_InitTrail 0x021B9110 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_GetSpriteUnit 0x021B7948 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_TextGetFont 0x021B7FFC thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue 0x021B8000 thumb ov103
 * IRC_APPBAR_Create 0x021B70DC thumb ov101
 * COMPATIBLE_IRC_SYS_SetOwnValue 0x021B63CC thumb ov101
 * IRC_COMPATIBLE_TOUCH_TEST_SetHandler 0x021B8338 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch 0x021B8364 thumb ov103
 */
#include "../include/Obj03740.h"
#include "../include/Obj22170.h"
#include "../include/Obj22173.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
struct Ctx;
extern void IRC_COMPATIBLE_TOUCH_TEST_InitExchange(u8 *p, void *q);
extern void IRC_COMPATIBLE_TOUCH_TEST_InitScene(u8 *,int);
extern void IRC_COMPATIBLE_TOUCH_TEST_InitText(u32 *p, int skip, u32 heap);
extern u32 ICA_ANIME_GetField24(const struct Ctx *p);
struct Rec;
extern void IRC_COMPATIBLE_TOUCH_TEST_InitTitleWindow(struct Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void IRC_COMPATIBLE_TOUCH_TEST_InitWindow(u8 *,int,int,u8,u8,u8,u8,u16,u8,u16);
extern void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageCentered(u8 *,void *,int);
extern void BG_SYS_ChangeScale(u32 which, u32 op, u32 value);
extern void BG_SYS_ChangeCenter(u32,u32,u16);
extern void IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(void *);
extern void IRC_COMPATIBLE_TOUCH_TEST_InitTrail(u8 *,void *,int,int,int,u8);
extern u32 IRC_COMPATIBLE_TOUCH_TEST_GetSpriteUnit(u8 *);
extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(void *),IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(void *);
extern void *IRC_APPBAR_Create(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void COMPATIBLE_IRC_SYS_SetOwnValue(int *,int);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetHandler(u32 p, u32 a);
extern void IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch(u8 *,u16 *);
#define REG32(a) (*(volatile u32 *)(a))
#define REG16(a) (*(volatile u16 *)(a))
int IRC_COMPATIBLE_TOUCH_TEST_ProcInit(void *owner,int unused,void *arg)
{
    u8 *p;
    u32 handle;
    int first,second;
    GFL_HEAP_CreateChildHeap(1,55,0x25000);
    p=PROCSYS_AllocProcWork(owner,0xb10,55);
    MI_CpuFill8(p,0,0xb10);
    ((struct Obj03740 *)p)->fB0C=arg;
    (*(u8 **)(p+0xb0c))[17]=0;
    IRC_COMPATIBLE_TOUCH_TEST_InitExchange(p+0x75c,((struct Obj22170 *)(*(u8 * *)&((struct Obj03740 *)p)->fB0C))->f4);
    IRC_COMPATIBLE_TOUCH_TEST_InitScene(p,55);
    IRC_COMPATIBLE_TOUCH_TEST_InitText((u32 *)(p+0x174),0,55);
    if(**(void ** *)&((struct Obj03740 *)p)->fB0C) ICA_ANIME_GetField24(**(void ** *)&((struct Obj03740 *)p)->fB0C);
    IRC_COMPATIBLE_TOUCH_TEST_InitTitleWindow((struct Rec *)(p+0x184),5,1,18,30,5,8,55);
    BMP_MENUWORK_DrawWindow(((struct Obj03740 *)p)->f184,0,(u16)(((struct Obj03740 *)p)->f0),6);
    IRC_COMPATIBLE_TOUCH_TEST_InitWindow(p+0x748,7,6,3,20,5,8,1,1,55);
    IRC_COMPATIBLE_TOUCH_TEST_PrintMessageCentered(p+0x748,p+0x174,16);
    BG_SYS_ChangeScale(7,3,0x1000);
    BG_SYS_ChangeScale(7,6,0x1000);
    BG_SYS_ChangeCenter(7,9,128);
    BG_SYS_ChangeCenter(7,12,40);
    IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(p+0xa4c);
    IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(p+0xaac);
    IRC_COMPATIBLE_TOUCH_TEST_InitTrail(p+0x198,p,0,1,0,1);
    handle=IRC_COMPATIBLE_TOUCH_TEST_GetSpriteUnit(p);
    first=IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(p+0x174);
    second=IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(p+0x174);
    ((struct Obj03740 *)p)->fA38=IRC_APPBAR_Create(2,handle,1,13,13,2,first,second,55);
    COMPATIBLE_IRC_SYS_SetOwnValue(*(int * *)&((struct Obj22173 *)(*(u8 * *)&((struct Obj03740 *)p)->fB0C))->f4,2);
    IRC_COMPATIBLE_TOUCH_TEST_SetHandler((u32)p,(u32)IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch);
    REG32(0x04000000)=(REG32(0x04000000)&~0xe000)|0x6000;
    REG16(0x04000048)=(REG16(0x04000048)&~0x3f)|0x1e;
    REG16(0x04000048)=(REG16(0x04000048)&~0x3f00)|0x1e00;
    REG16(0x0400004a)=(REG16(0x0400004a)&~0x3f)|0x1f;
    REG16(0x04000040)=0xff2c;
    REG16(0x04000044)=0xa8c0;
    REG16(0x04000042)=0xff;
    REG16(0x04000046)=0xa8c0;
    return 1;
}
