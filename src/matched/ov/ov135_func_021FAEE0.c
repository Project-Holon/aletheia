/*
 * function: func_021FAEE0
 * address: 0x021FAEE0
 * packet: pkt_ov135_021FAEE0
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
 *   func_021FBEB8 0x021FBEB8 thumb ov135
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_021FBFB0 0x021FBFB0 thumb ov135
 *   func_021FAC50 0x021FAC50 thumb ov135
 *   STRBUF_Delete 0x02045808 arm
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_020355C4 0x020355C4 arm
 *   tbl_022032C6 0x022032C6 data a1
 */
#include "../include/Obj01160.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 x; u8 y; } CurPos;
typedef signed char s8;
struct WinMgr;
extern const CurPos tbl_022032C6[];
extern void BGWINFRM_SetFrameDataArc(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 BGWINFRM_GetFrameBuffer(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(void *, u32);
extern void func_021FBEB8(void *, void *, void *, u32, void *);
extern void MI_CpuFill8(void *, u32, u32);
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_021FBFB0(void *, int);
extern void func_021FAC50(void *, void *, void *, u32, u16, void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_021F4FF4(u32, u32, u32);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern u8 func_020355C4(void);
int func_021FAEE0(u8 *p)
{
    int i;
    void *str;
    u16 color;
    u8 *g;
    BGWINFRM_SetFrameDataArc(((struct Obj01160 *)p)->f18, 0, 96, 28, 1);
    BGWINFRM_GetFrameBuffer(((struct Obj01160 *)p)->f18, 0);
    func_021F9260(p, 4);
    func_021FBEB8(((struct Obj01160 *)p)->f18, ((struct Obj01160 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    MI_CpuFill8(p + 96, 1, 26);
    g = p + 124;
    for (i = 0; i < 9; i++) {
        str = func_02045EC0(((struct Obj01160 *)p)->f20, i + 116);
        if (func_021FBFB0(p, i) == 1) {
            color = 0x3dc2;
            p[i + 96] = 1;
        } else {
            color = 0x2122;
            p[i + 96] = 0;
        }
        func_021FAC50(((struct Obj01160 *)p)->f18, (*(void ***)p)[i], str, 2, color, g);
        STRBUF_Delete(str);
    }
    BGWINFRM_PutFrame(((struct Obj01160 *)p)->f18, 0, 16, 0);
    BGWINFRM_ShowFrame(((struct Obj01160 *)p)->f18, 0);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj01160 *)p)->f8), 18);
    func_021F4FF4(((struct Obj01160 *)p)->f8, (tbl_022032C6[*(s16 *)(p + 56)].x + 16) * 8, tbl_022032C6[*(s16 *)(p + 56)].y * 8);
    ((struct Obj01160 *)p)->f44 = ((struct Obj01160 *)p)->f38;
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01160 *)p)->f8, 1);
    ((struct Obj01160 *)p)->f48 = 7;
    if (func_020355C4() == 1)
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01160 *)p)->f8, 0);
    else
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01160 *)p)->f8, 1);
    return -1;
}
