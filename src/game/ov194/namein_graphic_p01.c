/*
 * file:     namein_graphic_p01.c
 * unit:     yes
 * function: func_021F1440, func_021F168C, func_021F1744, func_021F1780, func_021F1878, func_021F1888, func_021F1968, func_021F1998, func_021F19A0, func_021F1A10, func_021F1A1C, func_021F1BFC
 * address:  0x021F1440
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200C104  0x0200C104  thumb
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_021F4AE4  0x021F4AE4  thumb  ov194
 *   func_021F4BEC  0x021F4BEC  thumb  ov194
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   func_021F4408  0x021F4408  thumb  ov194
 *   func_021F3FBC  0x021F3FBC  thumb  ov194
 *   func_021F4D3C  0x021F4D3C  thumb  ov194
 *   STRBUF_Clone  0x02045874  arm
 *   STRBUF_GetLength  0x020458F8  arm
 *   STRBUF_GetChars  0x02045A90  arm
 *   func_021F5004  0x021F5004  thumb  ov194
 *   STRBUF_Clear  0x0204581C  arm
 *   func_021F45EC  0x021F45EC  thumb  ov194
 *   func_021F463C  0x021F463C  thumb  ov194
 *   func_021F1E28  0x021F1E28  thumb  ov194
 *   func_021F3008  0x021F3008  thumb  ov194
 *   func_021F3CD0  0x021F3CD0  thumb  ov194
 *   func_021F3EB0  0x021F3EB0  thumb  ov194
 *   func_021F5304  0x021F5304  thumb  ov194
 *   func_021F3DE0  0x021F3DE0  thumb  ov194
 *   func_021F3E18  0x021F3E18  thumb  ov194
 *   func_021F3D70  0x021F3D70  thumb  ov194
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   SAVE_CONTROL_INTR_Resume  0x021BD374  thumb  ov088
 *   func_021F5354 0x021F5354 thumb ov194
 *   func_021F3ED0 0x021F3ED0 thumb ov194
 *   func_021F3D54 0x021F3D54 thumb ov194
 *   func_021F31B8 0x021F31B8 thumb ov194
 *   func_021F4D78 0x021F4D78 thumb ov194
 *   func_021F1F7C 0x021F1F7C thumb ov194
 *   func_021F4608 0x021F4608 thumb ov194
 *   func_021F42A0 0x021F42A0 thumb ov194
 *   func_021F4B84 0x021F4B84 thumb ov194
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_021F4614 0x021F4614 thumb ov194
 *   func_021F4BD8 0x021F4BD8 thumb ov194
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021F436C 0x021F436C thumb ov194
 *   func_021F4628 0x021F4628 thumb ov194
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02040C14 0x02040C14 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02040DA8 0x02040DA8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02049F34 0x02049F34 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020355C4 0x020355C4 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021F1D58 0x021F1D58 thumb ov194
 *   func_02040804 0x02040804 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   d_021F5780 0x021F5780 data a4 ov194
 */
#include "../../matched/include/Obj02908.h"
#include "../../matched/include/Obj14494.h"
#include "../../matched/include/Obj01772.h"
#include "../../matched/include/Obj10805.h"
#include "../../matched/include/Obj24898.h"
#include "../../matched/include/Obj24899.h"
#include "../../matched/include/Obj01427.h"

struct U16Vec;
struct Blk34;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Obj0203159C;
struct PrintSys;
struct Rec;
struct S020315D4;
struct Obj;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Rect_021F1440 {int left,top,right,bottom;} Rect_021F1440;

typedef signed short s16;

typedef struct Rect_021F1BFC {int left,top,right,bottom;} Rect_021F1BFC;

struct Vec2 { s16 x, y; };

extern u8 func_0200C104(struct Blk34 *p, u32 i);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,unsigned,unsigned);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void *PRINTSYS_QUE_CreateEx(u16 n, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern unsigned char *func_021F4AE4(unsigned swap, unsigned short heap);
extern unsigned func_021F4BEC(unsigned char *p);
extern void *BMP_OAM_CreateSys(u32 a0, void *a1);
extern int func_021F4408(int x, int y);
extern void func_021F3FBC(u8 *o, u32 mode, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3, u32 s4, u16 heap);
extern u32 *func_021F4D3C(u32 heap);
extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u32 func_021F5004(u16 *s, u32 x);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void func_021F45EC(u8 *a, u32 b, u32 c);
extern void func_021F463C(unsigned char *p, int *unused, unsigned char *q);
extern void func_021F1E28(u8 *p, u32 a, u32 b, u32 c, u32 d, u8 *e, u32 f);
extern void func_021F3008(u8 *p, int mode, void *font, void *window, void *data, void *palette, u32 heap);
extern void func_021F3CD0(u8 *p, int a, int b, int c, int d, u16 e);
extern void func_021F3EB0(char *p, int v);
extern u32 func_021F5304(u16 heap);
extern void func_021F3DE0(char *, int, u32, u32, u16);
extern void func_021F3E18(char *, int, void *);
extern void func_021F3D70(char *, int);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern void SAVE_CONTROL_INTR_Resume(unsigned char *p);
extern void func_021F5354(u8 *);
extern void func_021F3ED0(u8 *);
extern void func_021F3D54(u8 *);
extern void func_021F31B8(u8 *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021F4D78(u8 *);
extern void func_021F1F7C(u8 *);
extern void func_021F4608(void *p);
extern void func_021F42A0(u8 *);
extern void BMP_OAM_DeleteSys(void *);
extern void func_021F4B84(unsigned char *p);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32);
extern void func_021F4614(u8 *);
extern void func_021F4BD8(u8 *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_021F436C(u8 *);
extern unsigned func_021F4628(unsigned char *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *,unsigned,unsigned,unsigned,unsigned,u16);
extern unsigned int func_02049658(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);
extern void func_020498F4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_02040C14(unsigned,unsigned,unsigned,unsigned);
extern void func_0201F5BC(unsigned,unsigned,unsigned,unsigned,u16);
extern int func_02040DA8(int, int, int);
extern int CLACT_RegisterPalette(void *,unsigned,unsigned,unsigned,u16);
extern int CLACT_RegisterCellAnim(void *,unsigned,unsigned,unsigned);
extern int CLACT_RegisterCharacter(void *,unsigned,unsigned,unsigned,u16);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void CLACT_SetActorAutoAnim(struct Obj *,unsigned);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u8 func_020355C4(void);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern int func_021F1D58(u16 *out, u16 *phase, u32 step, u32 row, u8 idx, u16 a, u16 b);
extern u32 func_02040804(u32 layer);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
u32 func_021F1440(struct Obj0203159C *a, u32 b, u8 *args);
int func_021F168C(void *a,u32 b,u32 c,u8 *d);
int func_021F1744(int a,int b,int c,u8 *p);
void func_021F1780(int unused,u16 heap);
int func_021F1878(void *a0);
void func_021F1888(char *p,unsigned owner,u16 heap);
void func_021F1968(u8 *p);
void *func_021F1998(u8 *p,u32 i);
void func_021F19A0(u8 *a,void *b,void *c,u32 d);
void func_021F1A10(void *p);
void func_021F1A1C(char *p,int mode,const Rect_021F1440 *rect,int flag,int selected);
void func_021F1BFC(char *p, int sel, const void *rect);
extern u32 d_021F5780[];





u32 func_021F1440(struct Obj0203159C *a, u32 b, u8 *args)
{
    u8 *w;
    int mode;
    u32 s;
    u16 h;

    mode = 0;
    if (*(u32 *)(args + 0x28) != 0) {
        mode = func_0200C104((struct Blk34 *)(*(u32 *)(args + 0x28)), *(u32 *)args);
        if (mode >= 5) {
            mode = 0;
        }
    }
    GFL_HEAP_CreateChildHeap(1, 0x1e, 0x70000);
    w = PROCSYS_AllocProcWork(a, 0x2d4, 0x1e);
    MI_CpuFill8(w, 0, 0x2d4);
    *(u8 **)(w + 0x2c4) = args;
    *(u32 *)(w + 0x2b0) = (u32)GF_FONT_Create(0x17, 0, 1, 0, 0x1e);
    *(u32 *)(w + 0x2b4) = (u32)PRINTSYS_QUE_CreateEx(0x1000, 0x1e);
    *(u32 *)(w + 0x2b8) = (u32)func_02045B38(1, 2, 0x51, 0x1e);
    *(u32 *)(w + 0x2bc) = (u32)func_0201EC64(0x1e);
    *(u32 *)w = (u32)func_021F4AE4(0, 0x1e);
    *(u32 *)(w + 0x2c0) = (u32)BMP_OAM_CreateSys(0x1e, (void *)func_021F4BEC((unsigned char *)(*(u32 *)w)));
    func_021F1780((int)(w + 0x64), 0x1e);
    s = func_021F4BEC((unsigned char *)(*(u32 *)w));
    func_021F1888((char *)(w + 4), s, 0x1e);
    h = *(u16 *)(args + 4);
    func_021F3FBC(w + 0x264, func_021F4408(*(u32 *)args, h), h, *(u16 *)(args + 6), s,
                  *(u32 *)(w + 0x2b0), *(u32 *)(w + 0x2b4), (void *)(*(u32 *)(w + 0x2b8)), *(u32 *)(w + 0x2c0), 0x1e);
    *(u32 *)(w + 0x22c) = (u32)func_021F4D3C(0x1e);
    *(u32 *)(w + 0x2d0) = (u32)STRBUF_Clone(*(struct U16Vec **)(args + 0x20), 0x1e);
    if (STRBUF_GetLength(*(struct U16Vec **)(w + 0x2d0)) != 0) {
        if (STRBUF_GetLength(*(struct U16Vec **)(w + 0x2d0)) > *(u32 *)(args + 0x18)
            || func_021F5004(STRBUF_GetChars(*(struct U16Vec **)(w + 0x2d0)), 0x1e) == 0) {
            STRBUF_Clear(*(struct U16Vec **)(w + 0x2d0));
        }
    }
    func_021F45EC(w + 0x2a0, (u32)w, (u32)func_021F463C);
    func_021F1E28(w + 0x68, *(u32 *)(w + 0x2d0), (u8)*(u32 *)(args + 0x18), *(u32 *)(w + 0x2b0),
                  *(u32 *)(w + 0x2b4), (u8 *)((u32)(w + 4)), 0x1e);
    func_021F3008(w + 0xfc, mode, *(void **)(w + 0x2b0), *(void **)(w + 0x2b4), *(void **)(w + 0x22c), w + 4, 0x1e);
    func_021F3CD0(w + 0x230, *(u32 *)(w + 0x2b0), *(u32 *)(w + 0x2b8), *(u32 *)(w + 0x2b4), *(u32 *)(w + 0x2bc), 0x1e);
    func_021F3EB0((char *)(w + 0x254), 0x1e);
    *(u32 *)(w + 0x2cc) = func_021F5304(0x1e);
    if (*(u32 *)args == 1) {
        if (*(u32 *)(args + 8) == 0) {
            func_021F3DE0((char *)(w + 0x230), *(u32 *)args, *(u16 *)(args + 4), *(u16 *)(args + 6), 0x1e);
        } else {
            func_021F3E18((char *)(w + 0x230), *(u32 *)args, *(void **)(args + 8));
        }
    } else {
        func_021F3D70((char *)(w + 0x230), *(u32 *)args);
    }
    if (GFL_NET_GetRunState()) {
        GFL_NET_RestartWithDefaultTimeout(1, 0x1e);
    }
    if (*(u32 *)(*(u8 **)(w + 0x2c4) + 0x24) != 0) {
        SAVE_CONTROL_INTR_Resume((unsigned char *)(*(u32 *)(*(u8 **)(w + 0x2c4) + 0x24)));
    }
    return 1;
}




int func_021F168C(void *a,u32 b,u32 c,u8 *d)
{
    func_021F5354(*(u8 * *)&((struct Obj02908 *)d)->f2CC);
    func_021F3ED0(d+596);
    func_021F3D54(d+560);
    func_021F31B8(d+252);
    STRBUF_Delete(((struct Obj02908 *)d)->f2D0);
    func_021F4D78(*(u8 * *)&((struct Obj02908 *)d)->f22C);
    func_021F1F7C(d+104);
    func_021F4608(d+672);
    func_021F42A0(d+612);
    func_021F1968(d+4);
    func_021F1878(d+100);
    BMP_OAM_DeleteSys(((struct Obj02908 *)d)->f2C0);
    func_021F4B84(((struct Obj02908 *)d)->f0);
    func_0201ED04(((struct Obj02908 *)d)->f2BC);
    MSGDATA_Delete(((struct Obj02908 *)d)->f2B8);
    PRINTSYS_QUE_Clear(((struct Obj02908 *)d)->f2B4);
    PRINTSYS_QUE_Delete(((struct Obj02908 *)d)->f2B4);
    GF_FONT_Delete(((struct Obj02908 *)d)->f2B0);
    func_020315D4(a);
    func_020306F0(30);
    return 1;
}




int func_021F1744(int a,int b,int c,u8 *p) { func_021F4614(p+0x2a0);func_021F4BD8(*(u8 * *)&((struct Obj14494 *)p)->f0);PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj14494 *)p)->f2B4));func_021F436C(p+0x264);if(func_021F4628(p+0x2a0))return 1;return 0; }




/*
 * extent: Two trailing zero alignment bytes at 021F1876; existing func_021F1878 begins immediately afterward.
 */
void func_021F1780(int unused,u16 heap)
{
    void *p;
    p=func_020490F4(118,heap);
    func_02049B68(p,2,4,0,0,heap);
    func_02049658(p,1,5,0,0,0,heap);
    func_020498F4(p,3,5,0,0,0,heap);
    func_02049B68(p,2,0,0,0,heap);
    ARC_UTIL_UploadPaletteFromHandle(p,2,0,64,96,32,heap);
    ARC_UTIL_UploadPaletteFromHandle(p,2,0,64,128,32,heap);
    func_02049658(p,1,0,0,0,0,heap);
    func_020498F4(p,0,0,0,0,0,heap);
    func_020498F4(p,4,2,0,0,0,heap);
    ARC_TOOL_DeleteHandle(p);
    p=func_020490F4(23,heap);
    func_02049B68(p,6,4,480,32,heap);
    ARC_TOOL_DeleteHandle(p);
    func_02040C14(4,0,1,0);
    func_0201F5BC(4,1,14,0,heap);
}





int func_021F1878(void *a0)
{
    return func_02040DA8(4, 1, 0);
}




void func_021F1888(char *p,unsigned owner,u16 heap)
{
    short pos[4];
    void *handle;
    int i;
    int zero;
    handle=func_020490F4(118,heap);
    *(int *)&((struct Obj01772 *)p)->f0=CLACT_RegisterPalette(handle,9,0,0,heap);
    *(int *)&((struct Obj01772 *)p)->f8=CLACT_RegisterCellAnim(handle,7,6,heap);
    *(int *)&((struct Obj01772 *)p)->f4=CLACT_RegisterCharacter(handle,8,0,0,heap);
    ARC_TOOL_DeleteHandle(handle);
    MI_CpuFill8(pos,0,8);
    pos[2]=0;
    zero=0;
    for(i=0;i<16;i++)
        *(void **)(p+i*4+12)=CLACT_CreateActor((void *)owner,((struct Obj01772 *)p)->f4,((struct Obj01772 *)p)->f0,((struct Obj01772 *)p)->f8,pos,zero,heap);
    pos[2]=1;
    ((struct Obj01772 *)p)->f50=CLACT_CreateActor((void *)owner,((struct Obj01772 *)p)->f4,((struct Obj01772 *)p)->f0,((struct Obj01772 *)p)->f8,pos,zero,heap);
    CLACT_SetActorDrawEnable(((struct Obj01772 *)p)->f50,zero);
    for(i=18;i<20;i++) {
        pos[0]=-32;
        pos[1]=-32;
        pos[2]=i-15;
        *(void **)(p+i*4+12)=CLACT_CreateActor((void *)owner,((struct Obj01772 *)p)->f4,((struct Obj01772 *)p)->f0,((struct Obj01772 *)p)->f8,pos,0,heap);
        CLACT_SetActorAutoAnim(*(void **)(p+i*4+12),1);
        CLACT_SetActorDrawEnable(*(void **)(p+i*4+12),0);
    }
}




void func_021F1968(u8 *p) { int i; for(i=0;i<21;i++) { void *q=*(void **)((u32)p+(u32)i*4+12); if(q)CLACT_DeleteActor(q); } CLACT_ReleasePalette(((struct Obj10805 *)p)->f0);CLACT_ReleaseCharacter((u32)(((struct Obj10805 *)p)->f4));CLACT_ReleaseCellAnim(((struct Obj10805 *)p)->f8); }




void *func_021F1998(u8 *p,u32 i) { return *(void **)((u32)p+i*4+12); }




void func_021F19A0(u8 *a,void *b,void *c,u32 d)
{
    int i;
    void *x;
    void *p;
    u8 *q;
    int j;
    MI_CpuFill8(a,0,180);
    ((struct Obj24898 *)a)->fA0=b;
    for(i=0;i<2;i++) *(u32 *)(a+164+i*4)=(u32)func_021F1998(c,i+18);
    p=func_02049F34(118,2,(u32)(&x),d);
    q=*(u8 * *)&((struct Obj24899 *)x)->fC;
    for(i=0;i<16;i++) *(u16 *)(a+i*2)=*(u16 *)(q+32+i*2);
    for(j=0;j<16;j++) *(u16 *)(a+32+j*2)=*(u16 *)(q+64+j*2);
    func_020307B0(p);
}




void func_021F1A10(void *p) { MI_CpuFill8(p,0,180); }


/*
 * extent: 478 instruction bytes; 021F1BFA is two-byte zero alignment before021F1BFC.
 * lever: const Rect source schedules the loads ahead of argument stores; signed y destinations avoid an extra unsigned truncation pair (484/224 to482/157 toEXACT*478).
 */
void func_021F1A1C(char *p,int mode,const Rect_021F1440 *rect,int flag,int selected)
{
    int x;
    short y;
    ((struct Obj01427 *)p)->f98=0;
    ((struct Obj01427 *)p)->f94=mode;
    ((struct Obj01427 *)p)->f9C=flag;
    ((struct Obj01427 *)p)->fA0=selected;
    func_020413B0(2,0,0,32,24,1);
    func_020413B0(1,0,0,32,24,1);
    if(flag!=0 && selected==3) {
        func_020413B0(1,3,16,4,3,4);
        func_020413B0(1,23,16,4,3,4);
    }
    x=(selected+1)*3;
    func_020413B0(1,x,20,3,3,4);
    func_020413B0(2,x,20,3,3,4);
    if(rect && mode!=0) {
        *(Rect_021F1440 *)(p+0x84)=*rect;
        if(mode==2) {
            func_020413B0(2,rect->left,rect->top,rect->right-rect->left,rect->bottom-rect->top,mode+1);
            func_020413B0(1,rect->left,rect->top,rect->right-rect->left,rect->bottom-rect->top,mode+1);
        }
        if(func_020355C4()==0) {
            ((struct Obj01427 *)p)->fAC=rect->left*8+7;
            y=rect->top*8+(rect->bottom-rect->top)*4-3;
            ((struct Obj01427 *)p)->fAE=y;
            ((struct Obj01427 *)p)->fB0=rect->right*8-7;
            ((struct Obj01427 *)p)->fB2=y;
            CLACT_RestartActorAnim(((struct Obj01427 *)p)->fA4);
            CLACT_RestartActorAnim(((struct Obj01427 *)p)->fA8);
            CLACT_SetActorDrawEnable(((struct Obj01427 *)p)->fA4,1);
            CLACT_SetActorDrawEnable(((struct Obj01427 *)p)->fA8,1);
        }
    }
    if(mode==0 || func_020355C4()==1) {
        CLACT_SetActorDrawEnable(((struct Obj01427 *)p)->fA4,0);
        CLACT_SetActorDrawEnable(((struct Obj01427 *)p)->fA8,0);
    }
    func_020409B4(2);
    func_020409B4(1);
    if(mode!=0) {
        MI_CpuFill8(p+0x60,0,32);
        ((struct Obj01427 *)p)->f80=0;
        ((struct Obj01427 *)p)->f98=1;
    }
}

/*
 * note 2026-10-05 (wD7 lane05): the third parameter is dead after the switch; the source reuses it
 *   for the address of the Vec2 scratch (`rect = &v;`), which keeps that address in r7 across both
 *   CLACT_AddActorSurfacePos calls (idiom a-dead-stack-parameter-reassigned-to-a-locals-address-keeps-a-callee-saved-register).
 *   Parameter declared `const void *` so no casts are needed.
 */
void func_021F1BFC(char *p, int sel, const void *rect)
{
    struct Vec2 v;
    u32 d, c;
    int i;
    if (*(u32 *)(p + 0x98) != 0) {
        u16 *a, *b;
        switch (*(u32 *)(p + 0x94)) {
        case 0:
            break;
        case 1:
            d = 2;
            c = (u16)d_021F5780[0];
            break;
        case 2:
            d = 3;
            c = 0x1999;
            if ((*(u16 *)(p + 0x80))++ > 10) {
                if (func_020355C4() == 0)
                    func_021F1A1C(p, 1, (const Rect_021F1440 *)rect, *(int *)(p + 0x9C), sel);
                else
                    func_021F1A1C(p, 0, (const Rect_021F1440 *)rect, *(int *)(p + 0x9C), sel);
            }
            break;
        }
        a = (u16 *)p;
        a += 0x20;
        b = (u16 *)p;
        b += 0x30;
        for (i = 0; i < 16; i++)
            func_021F1D58(a + i, b + i, c, d, i, ((u16 *)p)[i], ((u16 *)p)[i + 0x10]);
    }
    rect = &v;
    v.x = *(u16 *)(p + 0xAC);
    v.y = *(u16 *)(p + 0xAE);
    v.y = v.y - (s16)(func_02040804(2) << 3);
    CLACT_AddActorSurfacePos(*(struct Obj **)(p + 0xA4), rect, 0);
    v.x = *(u16 *)(p + 0xB0);
    v.y = *(u16 *)(p + 0xB2);
    v.y = v.y - (s16)(func_02040804(2) << 3);
    CLACT_AddActorSurfacePos(*(struct Obj **)(p + 0xA8), rect, 0);
    if (*(int *)(p + 0xA0) != sel) {
        if (func_020355C4() == 0)
            func_021F1A1C(p, 1, (const Rect_021F1440 *)((const Rect_021F1BFC *)(p + 0x84)), *(int *)(p + 0x9C), sel);
        else
            func_021F1A1C(p, 0, (const Rect_021F1440 *)((const Rect_021F1BFC *)(p + 0x84)), *(int *)(p + 0x9C), sel);
    }
}
