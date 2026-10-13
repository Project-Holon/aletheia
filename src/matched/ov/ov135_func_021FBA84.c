/*
 * function: func_021FBA84
 * address: 0x021FBA84
 * packet: pkt_ov135_021FBA84
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BGWINFRM_SetFrameDataArc 0x0202CAE4 thumb
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   func_020355C4 0x020355C4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   func_021F9260 0x021F9260 thumb ov135
 *   func_021F8908 0x021F8908 thumb ov135
 *   func_021FB364 0x021FB364 thumb ov135
 *   func_021F9EEC 0x021F9EEC thumb ov135
 *   func_021FBF04 0x021FBF04 thumb ov135
 *   func_021FBEB8 0x021FBEB8 thumb ov135
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   tbl_02203324 0x02203324 data a4
 *   tbl_02203236 0x02203236 data a1
 */
#include "../include/Obj00437.h"
#include "../include/Obj23404.h"
#include "../include/Obj23405.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {u8 x,y;} Cell;
typedef signed char s8;
struct WinMgr;
extern const int tbl_02203324[];
extern const Cell tbl_02203236[];
extern void BGWINFRM_SetFrameDataArc(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern u8 func_020355C4(void);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
extern void func_021F9260(void *,u32);
extern int func_021F8908(void **menu, void *msg, int id);
extern void func_021FB364(void *,int,int);
extern u32 func_021F9EEC(u8 *p, u32 n);
extern void func_021FBF04(void *,void *,void *,int,u32);
extern void func_021FBEB8(void *,void *,void *,u32,void *);
extern void func_021F4FF4(u32,u32,u32);
int func_021FBA84(u8 *p)
{
    u8 pages;
    BGWINFRM_SetFrameDataArc(((struct Obj00437 *)p)->f18,0,0x60,0x18,1);
    func_021F9260(p,3);
    ((struct Obj00437 *)p)->f58=func_021F8908((void **)(p+0x30),((struct Obj00437 *)p)->f28,((struct Obj00437 *)p)->f3A+tbl_02203324[((struct Obj00437 *)p)->f38]);
    func_021FB364(p,0,((struct Obj00437 *)p)->f58);
    ((struct Obj00437 *)p)->f56=0;
    pages=func_021F9EEC((u8 *)(((struct Obj00437 *)p)->f58),5);
    func_021FBF04(((struct Obj00437 *)p)->f18,((struct Obj00437 *)p)->f34,((struct Obj23404 *)(*(u8 * *)&((struct Obj00437 *)p)->f0))->f14,((struct Obj00437 *)p)->f56,pages);
    func_021FBEB8(((struct Obj00437 *)p)->f18,((struct Obj00437 *)p)->f20,((struct Obj23405 *)(*(u8 * *)&((struct Obj00437 *)p)->f0))->f38,0x4A,p+0x7C);
    BGWINFRM_PutFrame(((struct Obj00437 *)p)->f18,0,1,0);
    ((struct Obj00437 *)p)->f44=0;
    func_021F4FF4(((struct Obj00437 *)p)->f8,tbl_02203236[*(int *)(p+0x44)].x,tbl_02203236[*(int *)(p+0x44)].y);
    func_021F4FF4(((struct Obj00437 *)p)->fC,0xB0,0x88);
    func_021F4FF4(((struct Obj00437 *)p)->f10,0x58,0x88);
    if(func_020355C4()==1)
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00437 *)p)->f8,0);
    else
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00437 *)p)->f8,1);
    if(pages==1) {
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00437 *)p)->fC),0x3D);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00437 *)p)->f10),0x3E);
    } else {
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00437 *)p)->fC),0x26);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00437 *)p)->f10),0x27);
    }
    CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00437 *)p)->fC,0);
    CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00437 *)p)->f10,0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00437 *)p)->fC,1);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00437 *)p)->f10,1);
    ((struct Obj00437 *)p)->f48=27;
    return -1;
}
