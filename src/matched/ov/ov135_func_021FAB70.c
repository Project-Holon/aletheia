/*
 * function: func_021FAB70
 * address: 0x021FAB70
 * packet: pkt_ov135_021FAB70
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
 *   func_021F87E0 0x021F87E0 thumb ov135
 *   func_021FB2F0 0x021FB2F0 thumb ov135
 *   func_021F9EEC 0x021F9EEC thumb ov135
 *   func_021FBF04 0x021FBF04 thumb ov135
 *   func_021FBEB8 0x021FBEB8 thumb ov135
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   func_0204B878 0x0204B878 arm
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 *   BGWINFRM_StartMove 0x0202CD64 thumb
 *   tbl_02203220 0x02203220 data a1
 */
#include "../include/Obj00474.h"
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void BGWINFRM_SetFrameDataArc(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 BGWINFRM_GetFrameBuffer(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(void *, u32);
extern int func_021F87E0(void **, void *, int);
extern void func_021FB2F0(void *, int, int);
struct Obj;
extern u32 func_021F9EEC(u8 *p, u32 n);
extern void func_021FBF04(void *, void *, void *, int, u32);
extern void func_021FBEB8(void *, void *, void *, u32, void *);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021F4FF4(u32, u32, u32);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
typedef struct { u8 x; u8 y; } CurPos;
extern const CurPos tbl_02203220[];
void func_021FAB70(u8 *p)
{
    BGWINFRM_SetFrameDataArc(((struct Obj00474 *)p)->f18, 0, 96, 29, 1);
    BGWINFRM_GetFrameBuffer(((struct Obj00474 *)p)->f18, 0);
    func_021F9260(p, 2);
    if (((struct Obj00474 *)p)->f5C == 1)
        ((struct Obj00474 *)p)->f58 = func_021F87E0((void **)(p + 48), ((struct Obj00474 *)p)->f20, 1);
    else if (((struct Obj00474 *)p)->f5C == 0)
        ((struct Obj00474 *)p)->f58 = func_021F87E0((void **)(p + 48), ((struct Obj00474 *)p)->f20, 0);
    func_021FB2F0(p, 0, ((struct Obj00474 *)p)->f58);
    ((struct Obj00474 *)p)->f56 = 0;
    func_021FBF04(((struct Obj00474 *)p)->f18, ((struct Obj00474 *)p)->f34, (*(void ***)p)[4], ((struct Obj00474 *)p)->f56, func_021F9EEC((u8 *)(((struct Obj00474 *)p)->f58), 4));
    func_021FBEB8(((struct Obj00474 *)p)->f18, ((struct Obj00474 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    BGWINFRM_PutFrame(((struct Obj00474 *)p)->f18, 0, 32, 0);
    func_0204B878((struct Obj *)(((struct Obj00474 *)p)->f8), 6);
    ((struct Obj00474 *)p)->f7A = 0;
    *(int *)&((struct Obj00474 *)p)->f44 = 0;
    func_021F4FF4(((struct Obj00474 *)p)->f8, tbl_02203220[*(int *)(p + 68)].x, tbl_02203220[*(int *)(p + 68)].y);
    BGWINFRM_ShowFrame(((struct Obj00474 *)p)->f18, 0);
    BGWINFRM_StartMove(((struct Obj00474 *)p)->f18, 0, -4, 0, 4);
    *(int *)&((struct Obj00474 *)p)->f48 = 34;
}
