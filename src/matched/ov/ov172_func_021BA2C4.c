/*
 * function: CTVT_DRAW_Init
 * address:  0x021BA2C4
 * packet:   pkt_ov172_021BA2C4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Scene constructor: loads the bank, builds fifteen sprite/button objects
 * from one descriptor, opens the text window and clears the state words.
 *
 * symbols:
 *   COMM_TVT_SYS_GetHeapId  0x021BE00C  thumb  ov172
 *   COMM_TVT_SYS_GetArc  0x021BE010  thumb  ov172
 *   COMM_TVT_SYS_GetResId  0x021BE018  thumb  ov172
 *   COMM_TVT_SYS_GetClactUnit  0x021BE024  thumb  ov172
 *   COMM_TVT_SYS_GetFont  0x021BE034  thumb  ov172
 *   COMM_TVT_SYS_GetMsgData  0x021BE03C  thumb  ov172
 *   COMM_TVT_SYS_GetPrintQue  0x021BE044  thumb  ov172
 *   COMM_TVT_SYS_GetViewSwapped  0x021BE0B4  thumb  ov172
 *   COMM_TVT_SYS_HideSlotMarker  0x021BE2E0  thumb  ov172
 *   CTVT_DRAW_UpdateToolButtons  0x021BB54C  thumb  ov172
 *   CTVT_DRAW_ShowHelp  0x021BB65C  thumb  ov172
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *   BMP_Clear  0x02043B5C  arm  arm9
 *   BMP_WIN_Create  0x020450F0  arm  arm9
 *   STRBUF_Delete  0x02045808  arm  arm9
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm  arm9
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *   BG_SYS_ClearSlot  0x020414EC  arm  arm9
 *   BG_SYS_FillTileMap  0x020413B0  arm  arm9
 *   APP_ICON_GetArchiveId  0x020275E4  thumb  arm9
 *   APP_ICON_GetStatusDataFileId  0x0202762C  thumb  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00276.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Desc {
    s16 x;
    s16 y;
    s16 z;
    u8  a;
    u8  b;
};

struct MsgBank;
struct U16Vec;
extern u16 COMM_TVT_SYS_GetHeapId(u16 *p);
extern u32  COMM_TVT_SYS_GetArc(void *c);
extern u32  COMM_TVT_SYS_GetResId(void *c, int i);
extern u32  COMM_TVT_SYS_GetClactUnit(void *c);
extern u32  COMM_TVT_SYS_GetFont(void *c);
extern u32  COMM_TVT_SYS_GetMsgData(void *c);
extern u32  COMM_TVT_SYS_GetPrintQue(void *c);
extern u32  COMM_TVT_SYS_GetViewSwapped(void *c);
extern void COMM_TVT_SYS_HideSlotMarker(void *c);
extern void CTVT_DRAW_UpdateToolButtons(void *c, u8 *p);
extern void CTVT_DRAW_ShowHelp(void *c, u8 *p, int k);
struct CharBuf;
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(u32 a);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u32  APP_ICON_GetArchiveId(void);
extern u32  APP_ICON_GetStatusDataFileId(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void BG_SYS_ClearSlot(u32 a);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02040618(u32 a, u32 b, u32 c);
extern void ARC_TOOL_DeleteHandle(void *a);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *o, unsigned int k);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *w);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

void CTVT_DRAW_Init(void *a0, u8 *p)
{
    struct Desc d;
    u16 v;
    u8 i;
    void *bank;
    void *s;
    u32 t1;
    u32 t3;

    v = COMM_TVT_SYS_GetHeapId(a0);
    func_020498F4((void *)COMM_TVT_SYS_GetArc(a0), 0x10, 7, 0, 0, 0, v);
    func_020409B4(7);
    func_02040588(5, 0);
    {
        u32 t = *(volatile u16 *)0x04000304;
        *(volatile u16 *)0x04000304 = t & 0xFFFF7FFF;
    }
    bank = func_020490F4(APP_ICON_GetArchiveId(), v);
    BG_SYS_ClearSlot(0);
    ARC_UTIL_UploadBgPaletteAddFromHandle(bank, APP_ICON_GetStatusDataFileId(), 0, 0x60, 0, 0x600, 0, v);
    BG_SYS_FillTileMap(0, 0, 0x15, 0x20, 3, 0);
    func_020409B4(0);
    func_02040618(0, 3, 0);
    ARC_TOOL_DeleteHandle(bank);
    d.x = 0x10;
    d.y = 0xcc;
    d.z = 1;
    d.a = 8;
    d.b = 0;
    ((struct Obj00276 *)p)->f58 = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 4), COMM_TVT_SYS_GetResId(a0, 0), COMM_TVT_SYS_GetResId(a0, 8), &d, 0, v);
    d.x = 0x38;
    d.z = 0x3;
    ((struct Obj00276 *)p)->f5C = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 4), COMM_TVT_SYS_GetResId(a0, 0), COMM_TVT_SYS_GetResId(a0, 8), &d, 0, v);
    d.x = 0x60;
    d.z = 0x5;
    ((struct Obj00276 *)p)->f60 = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 4), COMM_TVT_SYS_GetResId(a0, 0), COMM_TVT_SYS_GetResId(a0, 8), &d, 0, v);
    d.x = 0x88;
    d.z = 0x7;
    ((struct Obj00276 *)p)->f64 = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 4), COMM_TVT_SYS_GetResId(a0, 0), COMM_TVT_SYS_GetResId(a0, 8), &d, 0, v);
    d.x = 0xc8;
    if (COMM_TVT_SYS_GetViewSwapped(a0) == 1) {
        d.z = 0xc;
    } else {
        d.z = 0xa;
    }
    ((struct Obj00276 *)p)->f68 = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 4), COMM_TVT_SYS_GetResId(a0, 0), COMM_TVT_SYS_GetResId(a0, 8), &d, 0, v);
    d.x = 0xe0;
    d.y = 0xc0;
    d.z = 0x1;
    ((struct Obj00276 *)p)->f6C = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 7), COMM_TVT_SYS_GetResId(a0, 3), COMM_TVT_SYS_GetResId(a0, 10), &d, 0, v);
    CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00276 *)p)->f6C, 1);
    for (i = 0; i < 6; i++) {
        CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p + i * 4 + 0x58), 1);
    }
    d.x = 0x38;
    d.y = 0x48;
    d.z = 0xe;
    ((struct Obj00276 *)p)->f70 = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 5), COMM_TVT_SYS_GetResId(a0, 1), COMM_TVT_SYS_GetResId(a0, 9), &d, 1, v);
    d.y = 0x5c;
    d.z = 0xf;
    ((struct Obj00276 *)p)->f74 = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 5), COMM_TVT_SYS_GetResId(a0, 1), COMM_TVT_SYS_GetResId(a0, 9), &d, 1, v);
    d.y = 0x70;
    d.z = 0x10;
    ((struct Obj00276 *)p)->f78 = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 5), COMM_TVT_SYS_GetResId(a0, 1), COMM_TVT_SYS_GetResId(a0, 9), &d, 1, v);
    d.y = 0x84;
    d.z = 0x11;
    ((struct Obj00276 *)p)->f7C = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 5), COMM_TVT_SYS_GetResId(a0, 1), COMM_TVT_SYS_GetResId(a0, 9), &d, 1, v);
    d.x = 0x2c;
    d.y = 0x8c;
    d.z = 0x1;
    ((struct Obj00276 *)p)->f80 = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 6), COMM_TVT_SYS_GetResId(a0, 2), COMM_TVT_SYS_GetResId(a0, 10), &d, 1, v);
    for (i = 0; i < 5; i++) {
        CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p + i * 4 + 0x70), 0);
    }
    d.x = 0x10;
    d.y = 0xa0;
    d.z = 0xf;
    ((struct Obj00276 *)p)->f84 = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 4), COMM_TVT_SYS_GetResId(a0, 0), COMM_TVT_SYS_GetResId(a0, 8), &d, 0, v);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00276 *)p)->f84, 0);
    d.x = 0x88;
    d.y = 0xa0;
    d.z = 0x10;
    ((struct Obj00276 *)p)->f88 = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 4), COMM_TVT_SYS_GetResId(a0, 0), COMM_TVT_SYS_GetResId(a0, 8), &d, 0, v);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00276 *)p)->f88, 0);
    d.a = 0;
    ((struct Obj00276 *)p)->f8C = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 4), COMM_TVT_SYS_GetResId(a0, 0), COMM_TVT_SYS_GetResId(a0, 8), &d, 0, v);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00276 *)p)->f8C, 0);
    d.z = 0x19;
    d.a = 2;
    ((struct Obj00276 *)p)->f90 = (u32)CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a0), COMM_TVT_SYS_GetResId(a0, 4), COMM_TVT_SYS_GetResId(a0, 0), COMM_TVT_SYS_GetResId(a0, 8), &d, 0, v);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00276 *)p)->f90, 0);
    CTVT_DRAW_UpdateToolButtons(a0, p);
    ((struct Obj00276 *)p)->f48 = 0;
    ((struct Obj00276 *)p)->f50 = 0;
    t1 = COMM_TVT_SYS_GetFont(a0);
    s = (void *)COMM_TVT_SYS_GetMsgData(a0);
    t3 = COMM_TVT_SYS_GetPrintQue(a0);
    *(u32 *)&((struct Obj00276 *)p)->f4C = (u32)BMP_WIN_Create(4, 3, 1, 0x1c, 2, 0xa, 1);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp(((struct Obj00276 *)p)->f4C)), 0);
    s = func_02045EC0(s, 0xb);
    PRINTSYS_PrintQueColor((void *)t3, (u32)BMP_WIN_GetBmp(((struct Obj00276 *)p)->f4C), 1, 0, (u32)s, t1, 0x440);
    STRBUF_Delete(s);
    ((struct Obj00276 *)p)->f40 = 1;
    ((struct Obj00276 *)p)->f0 = 0;
    p[4] = 0x18;
    p[5] = 0x18;
    ((struct Obj00276 *)p)->f96 = 0;
    ((struct Obj00276 *)p)->fC = 0;
    ((struct Obj00276 *)p)->f8 = 0;
    ((struct Obj00276 *)p)->f10 = 0;
    ((struct Obj00276 *)p)->f14 = 0;
    ((struct Obj00276 *)p)->f38 = 0;
    ((struct Obj00276 *)p)->f44 = 0;
    ((struct Obj00276 *)p)->f18 = 0;
    ((struct Obj00276 *)p)->f1C = 0;
    ((struct Obj00276 *)p)->f20 = 0;
    *(volatile u16 *)0x0500021A = ((struct Obj00276 *)p)->f34 & 0x7fff;
    CTVT_DRAW_ShowHelp(a0, p, 0);
    GFL_NET_RestartWithDefaultTimeout(1, v);
    COMM_TVT_SYS_HideSlotMarker(a0);
}
