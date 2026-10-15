/*
 * function: ZKNSEARCH_MAIN_InitScrollWindow
 * address: 0x021BCA20
 * packet: pkt_ov210_021BCA20
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_GetBuf 0x0204162C arm
 *   BGWINFRM_Create 0x0202C9B4 thumb
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_SetFrameData 0x0202CAC4 thumb
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj10914.h"
typedef unsigned int u32;
typedef unsigned char u8;
struct WinMgr;
extern u32 BG_SYS_GetBuf(int);
extern struct WinMgr *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BGWINFRM_SetFrameData(struct WinMgr *mgr, u32 idx, const void *src);
extern void BG_SYS_SetTileEntry(u32, int, int, int, u8, u8, u8);
extern void func_02041B6C(u32);
void ZKNSEARCH_MAIN_InitScrollWindow(char *p)
{
    u32 base = BG_SYS_GetBuf(0);
    *(struct WinMgr * *)&((struct Obj10914 *)p)->f20 = BGWINFRM_Create(2, 1, 123);
    BGWINFRM_AddFrame(*(struct WinMgr * *)&((struct Obj10914 *)p)->f20, 0, 0, 32, 3);
    BGWINFRM_SetFrameData(*(struct WinMgr * *)&((struct Obj10914 *)p)->f20, 0, (void *)(base + 0x540));
    BG_SYS_SetTileEntry(0, 0, 0, 21, 32, 3, 0);
    func_02041B6C(0);
}
