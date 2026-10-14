/*
 * function: WORLDTRADE_INPUT_DrawThreeOptionScreen
 * address: 0x021FAAD4
 * packet: pkt_ov135_021FAAD4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BGWINFRM_SetFrameDataArc 0x0202CAE4 thumb
 *   BGWINFRM_GetFrameBuffer 0x0202CF84 thumb
 *   func_021F9260 0x021F9260 thumb ov135
 *   func_02045EC0 0x02045EC0 arm
 *   WORLDTRADE_INPUT_PutBmpWinString 0x021FAC50 thumb ov135
 *   STRBUF_Delete 0x02045808 arm
 *   WORLDTRADE_INPUT_PrintFrameStringAlt 0x021FBEB8 thumb ov135
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 *   BGWINFRM_StartMove 0x0202CD64 thumb
 */
#include "../include/Obj03296.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void BGWINFRM_SetFrameDataArc(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 BGWINFRM_GetFrameBuffer(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(void *, u32);
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORLDTRADE_INPUT_PutBmpWinString(void *, void *, void *, u32, u16, void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void WORLDTRADE_INPUT_PrintFrameStringAlt(void *, void *, void *, u32, void *);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
void WORLDTRADE_INPUT_DrawThreeOptionScreen(u8 *p)
{
    int i;
    void *str;
    BGWINFRM_SetFrameDataArc(((struct Obj03296 *)p)->f18, 0, 96, 25, 1);
    BGWINFRM_GetFrameBuffer(((struct Obj03296 *)p)->f18, 0);
    func_021F9260(p, 1);
    for (i = 0; i < 3; i++) {
        str = func_02045EC0(((struct Obj03296 *)p)->f20, i + 130);
        WORLDTRADE_INPUT_PutBmpWinString(((struct Obj03296 *)p)->f18, (*(void ***)p)[i], str, 2, 0x3dc2, p + 124);
        STRBUF_Delete(str);
    }
    WORLDTRADE_INPUT_PrintFrameStringAlt(((struct Obj03296 *)p)->f18, ((struct Obj03296 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    BGWINFRM_PutFrame(((struct Obj03296 *)p)->f18, 0, 32, 0);
    BGWINFRM_ShowFrame(((struct Obj03296 *)p)->f18, 0);
    BGWINFRM_StartMove(((struct Obj03296 *)p)->f18, 0, -4, 0, 4);
}
