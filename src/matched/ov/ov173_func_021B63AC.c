/*
 * function: POKE_SUMMARY_MAIN_InitScreen
 * address:  0x021B63AC
 * packet:   pkt_021B63AC
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   func_020490F4  0x020490F4  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   func_020056A0  0x020056A0  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   POKE_SUMMARY_MAIN_SetVramBanks  0x021B64C0  thumb  ov173
 *   POKE_SUMMARY_MAIN_InitDisplay  0x021B64D0  thumb  ov173
 *   POKE_SUMMARY_MAIN_CreateMsgWindows  0x021B66BC  thumb  ov173
 *   POKE_SUMMARY_ACTOR_CreateActors  0x021B7A00  thumb  ov173
 *   POKE_SUMMARY_MAIN_CreateText  0x021B6850  thumb  ov173
 *   POKE_SUMMARY_MAIN_CreateBmpWindows  0x021B67A4  thumb  ov173
 *   POKE_SUMMARY_MAIN_BuildMoveList  0x021B7128  thumb  ov173
 *   POKE_SUMMARY_MAIN_RefreshMoveList  0x021B6BCC  thumb  ov173
 *   POKE_SUMMARY_MAIN_DrawMovesPage  0x021B6CC0  thumb  ov173
 *   POKE_SUMMARY_ACTOR_CreateSound  0x021B7C44  thumb  ov173
 *   POKE_SUMMARY_ACTOR_SetIdleAnim  0x021B8040  thumb  ov173
 *   POKE_SUMMARY_MAIN_CreateTaskMenu  0x021B6278  thumb  ov173
 *   POKE_SUMMARY_MAIN_VBlankCallback  0x021B6498  thumb  ov173
 */
#include "../include/Obj00180.h"
typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;

extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern u32 func_020056A0(void (*cb)(void), void *p, int n);
extern void ARC_TOOL_DeleteHandle(u32 a);
extern void POKE_SUMMARY_MAIN_SetVramBanks(void);
extern void POKE_SUMMARY_MAIN_InitDisplay(void);
extern void POKE_SUMMARY_MAIN_CreateMsgWindows(u8 *p, u8 *q);
extern void POKE_SUMMARY_ACTOR_CreateActors(char *p, void *arg);
extern void POKE_SUMMARY_MAIN_CreateText(char *p);
extern void POKE_SUMMARY_MAIN_CreateBmpWindows(u8 *p);
extern void POKE_SUMMARY_MAIN_BuildMoveList(char *p);
extern void POKE_SUMMARY_MAIN_RefreshMoveList(char *p);
extern void POKE_SUMMARY_MAIN_DrawMovesPage(char *p);
extern void POKE_SUMMARY_ACTOR_CreateSound(u8 *p);
extern void POKE_SUMMARY_ACTOR_SetIdleAnim(u8 *p);
extern void POKE_SUMMARY_MAIN_CreateTaskMenu(u8 *p);
extern void POKE_SUMMARY_MAIN_VBlankCallback(void *unused, char *p);

void POKE_SUMMARY_MAIN_InitScreen(u8 *p)
{
    u8 *q;

    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= 0xffffe0ff;
    *(volatile u32 *)0x04001000 &= 0xffffe0ff;
    q = func_020490F4(0x7c, 0x4f);
    POKE_SUMMARY_MAIN_SetVramBanks();
    POKE_SUMMARY_MAIN_InitDisplay();
    POKE_SUMMARY_MAIN_CreateMsgWindows(p, q);
    POKE_SUMMARY_ACTOR_CreateActors((char *)p, q);
    POKE_SUMMARY_MAIN_CreateText((char *)p);
    POKE_SUMMARY_MAIN_CreateBmpWindows(p);
    POKE_SUMMARY_MAIN_BuildMoveList((char *)p);
    POKE_SUMMARY_MAIN_RefreshMoveList((char *)p);
    POKE_SUMMARY_MAIN_DrawMovesPage((char *)p);
    POKE_SUMMARY_ACTOR_CreateSound(p);
    POKE_SUMMARY_ACTOR_SetIdleAnim(p);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x4f);
    BG_SYS_SetLcdSwap(1);
    ((struct Obj00180 *)p)->f68 = (u32)func_020056A0((void (*)(void))POKE_SUMMARY_MAIN_VBlankCallback, p, 0x10);
    ARC_TOOL_DeleteHandle((u32)q);
    POKE_SUMMARY_MAIN_CreateTaskMenu(p);
}



