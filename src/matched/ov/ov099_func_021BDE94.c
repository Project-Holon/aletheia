/*
 * function: WIFICLUB_InitScreen
 * address: 0x021BDE94
 * packet: pkt_ov099_021BDE94
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototypes: 49238 SDK asm reads r0 despite its void(void) declaration; caller-visible handle preserved. Empty 021BE5B4 preserves caller-loaded live r0; 021BE5B8 preserves visible r1 despite no body read.
 * volatile: RMW display registers read at 021BDEB4/021BDEC0 and written at 021BDEBC/021BDEC4.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   WIFICLUB_InitVram 0x021BE030 thumb ov099
 *   WIFICLUB_InitBackgrounds 0x021BE040 thumb ov099
 *   BMP_WIN_Init 0x02045088 arm
 *   WIFICLUB_InitPlanesAndText 0x021BE53C thumb ov099
 *   WIFICLUB_VBlankTask 0x021BE028 thumb ov099
 *   func_020056A0 0x020056A0 thumb
 *   WIFICLUB_TaskHook 0x021BE5B4 thumb ov099
 *   WIFICLUB_InitSprites 0x021BE5B8 thumb ov099
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 */
#include "../include/Obj03222.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct GfFont;
struct MsgBank;
struct Node;
struct WordSet;
extern void func_02030EAC(struct Node *n);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void BG_SYS_SetLcdSwap(u32);
extern void WIFICLUB_InitVram(void);
extern void WIFICLUB_InitBackgrounds(u16 heap);
extern void BMP_WIN_Init(u16);
extern void WIFICLUB_InitPlanesAndText(char *p, int v);
extern void WIFICLUB_VBlankTask(void);
extern void *func_020056A0(u32, u32, u32);
extern void WIFICLUB_TaskHook(void *);
extern void WIFICLUB_InitSprites(char *, void *);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
void WIFICLUB_InitScreen(char *p)
{
    void *h;
    if (((struct Obj03222 *)p)->f0 != 0) func_02030EAC(((struct Obj03222 *)p)->f0);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u32 *)0x04000000 &= 0xffffe0ff;
    *(volatile u32 *)0x04001000 &= 0xffffe0ff;
    h = func_020490F4(0x21, 0x21);
    ((struct Obj03222 *)p)->fDC = WORDSET_CreateDefault(0x21);
    ((struct Obj03222 *)p)->fE0 = func_02045B38(0, 2, 0xd1, 0x21);
    ((struct Obj03222 *)p)->fE4 = func_02045B38(0, 2, 0xe8, 0x21);
    ((struct Obj03222 *)p)->fE8 = GF_FONT_Create(0x17, 0, 0, 0, 0x21);
    ((struct Obj03222 *)p)->fEC = GF_FONT_Create(0x17, 3, 0, 0, 0x21);
    BG_SYS_SetLcdSwap(1);
    WIFICLUB_InitVram();
    WIFICLUB_InitBackgrounds(0x21);
    BMP_WIN_Init(0x21);
    WIFICLUB_InitPlanesAndText(p, (int)h);
    ((struct Obj03222 *)p)->f0 = func_020056A0((u32)WIFICLUB_VBlankTask, (u32)p, 1);
    WIFICLUB_TaskHook(((struct Obj03222 *)p)->f0);
    WIFICLUB_InitSprites(p, h);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    ARC_TOOL_DeleteHandle(h);
}
