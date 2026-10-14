/*
 * function: WORLDTRADE_INPUT_DrawFrame
 * address: 0x021FA9C8
 * packet: pkt_ov135_021FA9C8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BGWINFRM_SetFrameDataArc 0x0202CAE4 thumb
 *   BGWINFRM_GetFrameBuffer 0x0202CF84 thumb
 *   func_021F9260 0x021F9260 thumb ov135
 *   WORLDTRADE_INPUT_PrintFrameStringAlt 0x021FBEB8 thumb ov135
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02045EC0 0x02045EC0 arm
 *   WORLDTRADE_INPUT_CategoryHasSpecies 0x021FBFB0 thumb ov135
 *   WORLDTRADE_INPUT_CategoryHasListEntries 0x021FC014 thumb ov135
 *   WORLDTRADE_INPUT_PutBmpWinString 0x021FAC50 thumb ov135
 *   STRBUF_Delete 0x02045808 arm
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 */
#include "../include/Obj01744.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void BGWINFRM_SetFrameDataArc(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 BGWINFRM_GetFrameBuffer(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(void *, u32);
extern void WORLDTRADE_INPUT_PrintFrameStringAlt(void *, void *, void *, u32, void *);
extern void MI_CpuFill8(void *, u32, u32);
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int WORLDTRADE_INPUT_CategoryHasSpecies(void *, int);
extern int WORLDTRADE_INPUT_CategoryHasListEntries(void *, int);
extern void WORLDTRADE_INPUT_PutBmpWinString(void *, void *, void *, u32, u16, void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);
void WORLDTRADE_INPUT_DrawFrame(u8 *p, int mode, int pos)
{
    int i;
    void *str;
    u16 color;
    u8 *g;
    BGWINFRM_SetFrameDataArc(((struct Obj01744 *)p)->f18, 0, 96, mode == 6 ? 27 : 28, 1);
    BGWINFRM_GetFrameBuffer(((struct Obj01744 *)p)->f18, 0);
    func_021F9260(p, mode);
    WORLDTRADE_INPUT_PrintFrameStringAlt(((struct Obj01744 *)p)->f18, ((struct Obj01744 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    MI_CpuFill8(p + 96, 1, 26);
    g = p;
    g += 124;
    for (i = 0; i < 9; i++) {
        str = func_02045EC0(((struct Obj01744 *)p)->f20, i + 116);
        if (mode == 4) {
            if (WORLDTRADE_INPUT_CategoryHasSpecies(p, i) == 1) {
                color = 0x3dc2;
                p[i + 96] = 1;
            } else {
                color = 0x2122;
                p[i + 96] = 0;
            }
        } else {
            if (WORLDTRADE_INPUT_CategoryHasListEntries(p, i) == 1) {
                color = 0x3dc2;
                p[i + 96] = 1;
            } else {
                color = 0x2122;
                p[i + 96] = 0;
            }
        }
        WORLDTRADE_INPUT_PutBmpWinString(((struct Obj01744 *)p)->f18, (*(void ***)p)[i], str, 2, color, g);
        STRBUF_Delete(str);
    }
    if (mode == 6) {
        str = func_02045EC0(((struct Obj01744 *)p)->f20, 188);
        WORLDTRADE_INPUT_PutBmpWinString(((struct Obj01744 *)p)->f18, (*(void ***)p)[15], str, 2, 0x3dc2, p + 124);
        STRBUF_Delete(str);
    }
    BGWINFRM_PutFrame(((struct Obj01744 *)p)->f18, 0, pos, 0);
    BGWINFRM_ShowFrame(((struct Obj01744 *)p)->f18, 0);
}
