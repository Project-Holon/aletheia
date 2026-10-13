/*
 * function: func_021D7724
 * address: 0x021D7724
 * packet: pkt_ov120_021D7724
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: 0201EC74 heap widened because caller passes the entire ldrh value without byte truncation.
 * symbols:
 *   s_021D8BEC 0x021D8BEC data a1
 *   func_02030734 0x02030734 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   TCBL_Create 0x0203101C arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   GF_FONT_ResetTextColor  0x0201DD60  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 */
#include "../include/Obj00496.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern const char s_021D8BEC[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void BMP_WIN_Init(u16);
extern void GF_FONT_ResetTextColor(void);
struct GfFont;
struct R;
struct Tcbl;
struct U16Vec;
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct WordSet;
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_0201F5DC(void *,u32,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
char *func_021D7724(u32 heap,u32 n)
{
    char *p=func_02030734(heap,0xd0,1,s_021D8BEC,0xa9);
    ((struct Obj00496 *)p)->fC8=heap;
    BMP_WIN_Init(((struct Obj00496 *)p)->fC8);
    GF_FONT_ResetTextColor();
    ((struct Obj00496 *)p)->fA0=TCBL_Create(((struct Obj00496 *)p)->fC8,((struct Obj00496 *)p)->fC8,1,0);
    ((struct Obj00496 *)p)->fA4=(void *)PRINTSYS_QUE_Create((void *)(u32)((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->f1C=STRBUF_Create(240,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->f18=STRBUF_Create(240,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->f20=STRBUF_Create(240,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->f14=GF_FONT_Create(23,0,0,0,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->fC=func_02045B38(0,2,(u16)n,(u16)(((struct Obj00496 *)p)->fC8));
    ((struct Obj00496 *)p)->f10=func_0201EC74(6,64,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->fC0=APP_TASKMENU_RES_Create(5,9,*(u32 *)&((struct Obj00496 *)p)->f14,*(u32 *)&((struct Obj00496 *)p)->fA4,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->f4=func_0201F5DC((void *)1,12,0,((struct Obj00496 *)p)->fC8);
    ((struct Obj00496 *)p)->f0=func_0201F5DC((void *)6,12,0,((struct Obj00496 *)p)->fC8);
    func_02049B40(23,5,4,0x160,32,((struct Obj00496 *)p)->fC8);
    func_02049B40(23,5,0,0x160,32,((struct Obj00496 *)p)->fC8);
    return p;
}
