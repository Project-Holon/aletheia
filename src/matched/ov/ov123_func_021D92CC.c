/*
 * function: func_021D92CC
 * address: 0x021D92CC
 * packet: pkt_ov123_021D92CC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   TCBL_Create 0x0203101C arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   d_021DABA8 0x021DABA8 data ov123 a1
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   GF_FONT_ResetTextColor  0x0201DD60  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 */
#include "../include/Obj00500.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021DABA8[];
extern void *func_02030734(u32,u32,int,const char *,u16);
struct GfFont;
struct R;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern void BMP_WIN_Init(u16);
extern void GF_FONT_ResetTextColor(void);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_0201F5DC(void *,u32,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
u8 *func_021D92CC(u32 heap,u32 bank)
{
    u8 *p;
    p=func_02030734(heap,0xb4,1,d_021DABA8,0x9b);
    ((struct Obj00500 *)p)->fB0=heap;
    BMP_WIN_Init(((struct Obj00500 *)p)->fB0);
    GF_FONT_ResetTextColor();
    ((struct Obj00500 *)p)->f88=TCBL_Create(((struct Obj00500 *)p)->fB0,((struct Obj00500 *)p)->fB0,2,0);
    ((struct Obj00500 *)p)->f8C=func_0201C440((void *)(u32)((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f2C=STRBUF_Create(400,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f30=STRBUF_Create(400,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f28=GF_FONT_Create(23,0,0,0,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f20=func_02045B38(0,2,(u16)bank,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f24=func_0201EC64(((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->fAC=APP_TASKMENU_RES_Create(5,9,*(u32 *)&((struct Obj00500 *)p)->f28,((struct Obj00500 *)p)->f8C,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f0=func_0201F5DC((void *)1,12,0,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f8=func_0201F5DC((void *)5,12,0,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f4=func_0201F5DC((void *)6,12,0,((struct Obj00500 *)p)->fB0);
    func_02049B40(23,5,4,352,32,((struct Obj00500 *)p)->fB0);
    func_02049B40(23,5,0,352,32,((struct Obj00500 *)p)->fB0);
    return p;
}
