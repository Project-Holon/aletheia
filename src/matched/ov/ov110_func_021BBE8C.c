/*
 * function: PMSIV_EDIT_UpdateFramePosition
 * address: 0x021BBE8C
 * packet: pkt_ov110_021BBE8C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 */
#include "../include/Obj04447.h"
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
struct WinMgr;
extern void BG_SYS_SetTileEntry(unsigned, int, int, int, u8, u8, u8);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);
void PMSIV_EDIT_UpdateFramePosition(void *unused, u8 *p)
{
    ((struct Obj04447 *)p)->f1A8 = 0;
    ((struct Obj04447 *)p)->f1AC = 0;
    if (((struct Obj04447 *)p)->f1B8) {
        BG_SYS_SetTileEntry(0, 0, 0, 0, 32, 6, 17);
        BGWINFRM_PutFrame(((struct Obj04447 *)p)->f1B4, 0, 0, (s8)(-((struct Obj04447 *)p)->f198 / 8));
        BGWINFRM_ShowFrame(((struct Obj04447 *)p)->f1B4, 0);
        ((struct Obj04447 *)p)->f1B8 = 0;
    }
}
