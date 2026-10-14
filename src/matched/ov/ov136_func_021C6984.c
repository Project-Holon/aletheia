/*
 * function: MB_SEQ_StateInit
 * address:  0x021C6984
 * packet:   pkt_ov136_021C6984
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0       0x020056A0  thumb
 *   GFL_HEAP_CreateChildHeap   0x0203064C  arm
 *   func_02030734        0x02030734  arm
 *   func_02030EAC   0x02030EAC  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes             0x020435F4  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   MIi_CpuClearFast    0x02082AC0  arm
 *   MB_SEQ_VBlankTask 0x021C54FC thumb
 *   MB_SEQ_SetVramBanks 0x021C5508 thumb
 *   MB_SEQ_InitBgs 0x021C5518 thumb
 *   MB_SEQ_LoadFrameCharData 0x021C574C thumb
 *   MB_SEQ_LoadMiscGraphics 0x021C5828 thumb
 *   MB_SEQ_CreateFrames 0x021C587C thumb
 *   MB_SEQ_CreateMessageResources 0x021C5924 thumb
 *   MB_SEQ_CreateMenuEntries 0x021C59B8 thumb
 *   MB_SEQ_CollectMails 0x021C5B40 thumb
 *   MB_SEQ_DrawPage 0x021C5C00 thumb
 *   MB_SEQ_CreatePmsDraw 0x021C5DD8 thumb
 *   MB_SEQ_CreateWindows 0x021C5E58 thumb
 *   MB_SEQ_DrawTitle 0x021C6170 thumb
 *   MB_SEQ_CreateActors 0x021C64A8 thumb
 *   MB_SEQ_CreateTouchSelect  0x021C7658  thumb
 *   d_021C7F04 0x021C7F04 data a1
 */
#include "../include/Obj03836.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021C7F04[];
struct Node;
extern void func_02030EAC(struct Node *n);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern void BG_SYS_SetLcdSwap(u32);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MIi_CpuClearFast(u32, void *, u32);
extern void MB_SEQ_CollectMails(u8 *);
extern void MB_SEQ_SetVramBanks(void);
extern void MB_SEQ_InitBgs(u8 *);
extern void MB_SEQ_LoadFrameCharData(u8 *);
extern void MB_SEQ_LoadMiscGraphics(void *a0);
extern void MB_SEQ_CreateWindows(u8 *);
extern void MB_SEQ_CreateFrames(u8 *);
extern void MB_SEQ_CreateActors(u8 *);
extern void MB_SEQ_CreatePmsDraw(u8 *);
extern void MB_SEQ_CreateTouchSelect(u8 *);
extern void MB_SEQ_CreateMessageResources(u8 *);
extern void MB_SEQ_DrawTitle(u8 *);
extern void MB_SEQ_DrawPage(u8 *);
extern void MB_SEQ_CreateMenuEntries(u8 *);
extern void MB_SEQ_VBlankTask(void);
extern void *func_020056A0(void (*)(void *), void *, u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
int MB_SEQ_StateInit(u8 *p)
{
    if (((struct Obj03836 *)p)->f2C != 0) {
        func_02030EAC(((struct Obj03836 *)p)->f2C);
        *(u32 *)&((struct Obj03836 *)p)->f2C = 0;
    }
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetLcdSwap(0);
    GFL_HEAP_CreateChildHeap(1, 0x66, 0x60000);
    ((struct Obj03836 *)p)->f8 = func_02030734(0x66, 0x370, 0, d_021C7F04, 0x10C);
    MIi_CpuClearFast(0, ((struct Obj03836 *)p)->f8, 0x370);
    MB_SEQ_CollectMails(p);
    MB_SEQ_SetVramBanks();
    MB_SEQ_InitBgs(p);
    MB_SEQ_LoadFrameCharData(p);
    MB_SEQ_LoadMiscGraphics(p);
    MB_SEQ_CreateWindows(p);
    MB_SEQ_CreateFrames(p);
    MB_SEQ_CreateActors(p);
    MB_SEQ_CreatePmsDraw(p);
    MB_SEQ_CreateTouchSelect(p);
    MB_SEQ_CreateMessageResources(*(u8 * *)&((struct Obj03836 *)p)->f8);
    MB_SEQ_DrawTitle(p);
    MB_SEQ_DrawPage(p);
    MB_SEQ_CreateMenuEntries(p);
    ((struct Obj03836 *)p)->f2C = func_020056A0((void (*)(void *))MB_SEQ_VBlankTask, p, 1);
    GFL_NET_RestartWithDefaultTimeout(0, 0x66);
    return ((struct Obj03836 *)p)->f28;
}
