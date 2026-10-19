/*
 * function: BSUBWAY_RECORD_LIST_Init
 * address:  0x021B95A0
 * packet:   pkt_ov069_021B95A0
 * region:   ov069
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * BSUBWAY_RECORD_LIST_SetupBgLayers is declared without a prototype: its matched source takes no
 * argument but the caller loads r4 into r0 before the call.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 *   BSUBWAY_RECORD_LIST_InitWork  0x021B96D4  thumb  ov069
 *   BSUBWAY_RECORD_LIST_SetupVramBanks  0x021B97D4  thumb  ov069
 *   BSUBWAY_RECORD_LIST_SetupBgLayers  0x021B97F4  thumb  ov069
 *   BSUBWAY_RECORD_LIST_LoadGraphics  0x021B98AC  thumb  ov069
 *   BSUBWAY_RECORD_LIST_SetupActors  0x021B9A50  thumb  ov069
 *   BSUBWAY_RECORD_LIST_CreateActors  0x021B9B44  thumb  ov069
 *   BSUBWAY_RECORD_LIST_CreateWindows  0x021B9C44  thumb  ov069
 *   BSUBWAY_RECORD_LIST_InitText  0x021B9D08  thumb  ov069
 *   BSUBWAY_RECORD_LIST_InitCursor  0x021B9F24  thumb  ov069
 *   BSUBWAY_RECORD_LIST_UpdateArrowVisibility  0x021BA384  thumb  ov069
 *   BSUBWAY_RECORD_LIST_ShowPage  0x021BA438  thumb  ov069
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 */
#include "../include/Obj00432.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_HEAP_CreateChildHeap(unsigned int a, unsigned int heap, unsigned int size);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void  MIi_CpuClearFast(u32 val, void *dst, u32 size);
extern void  WIPE_SetBrightnessFadeOut(u32 a, u32 color);
struct Obj;
struct WorkObj;
extern void BSUBWAY_RECORD_LIST_InitWork(u8 *p, u32 a);
extern void  BSUBWAY_RECORD_LIST_SetupVramBanks(void);
extern void  BSUBWAY_RECORD_LIST_SetupBgLayers();
extern void BSUBWAY_RECORD_LIST_LoadGraphics(u8 *p);
extern void BSUBWAY_RECORD_LIST_SetupActors(u8 *p);
extern void BSUBWAY_RECORD_LIST_CreateActors(struct WorkObj *o);
extern void BSUBWAY_RECORD_LIST_CreateWindows(struct Obj *o);
extern void BSUBWAY_RECORD_LIST_InitText(u8 *p);
extern void BSUBWAY_RECORD_LIST_InitCursor(char *p);
extern void  BSUBWAY_RECORD_LIST_UpdateArrowVisibility(char *o, int i, int n);
extern void BSUBWAY_RECORD_LIST_ShowPage(char *p, int i);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void  GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);

int BSUBWAY_RECORD_LIST_Init(void *a, u32 b, u32 c)
{
    u8 *p;

    GFL_HEAP_CreateChildHeap(1, 0x80, 0x20000);
    p = PROCSYS_AllocProcWork(a, 0x168, 0x80);
    MIi_CpuClearFast(0, p, 0x168);
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    BSUBWAY_RECORD_LIST_InitWork(p, c);
    BSUBWAY_RECORD_LIST_SetupVramBanks();
    BSUBWAY_RECORD_LIST_SetupBgLayers(p);
    BSUBWAY_RECORD_LIST_LoadGraphics(p);
    BSUBWAY_RECORD_LIST_SetupActors(p);
    BSUBWAY_RECORD_LIST_CreateActors((struct WorkObj *)p);
    BSUBWAY_RECORD_LIST_CreateWindows((struct Obj *)p);
    BSUBWAY_RECORD_LIST_InitText(p);
    BSUBWAY_RECORD_LIST_InitCursor((char *)p);
    BSUBWAY_RECORD_LIST_UpdateArrowVisibility((char *)p, ((struct Obj00432 *)p)->f160, ((struct Obj00432 *)p)->f162);
    BSUBWAY_RECORD_LIST_ShowPage((char *)p, ((struct Obj00432 *)p)->f160);
    WIPE_SYS_Start(0, 1, 1, 0, 0x10, 1, 0x80);
    GFL_NET_RefreshWmIconAtTopRight(1, 0x80);
    return 1;
}
