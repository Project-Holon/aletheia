/*
 * function: BSUBWAY_RECORD_LIST_LoadGraphics
 * address:  0x021B98AC
 * packet:   pkt_ov069_021B98AC
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   APP_ICON_GetStatusAnimFileId  0x02027624  thumb
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb
 *   APP_ICON_GetStatusDataFileId  0x0202762C  thumb
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_02049B40  0x02049B40  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   BGWINFRM_Create  0x0202C9B4  thumb
 *   BGWINFRM_AddFrame  0x0202CA3C  thumb
 *   BGWINFRM_SetFrameDataArcHandle  0x0202CB18  thumb
 *   BGWINFRM_PutFrame  0x0202CB4C  thumb
 *   sRecordListFramePositions     0x021BA66C  data  a4
 */
#include "../include/Obj06170.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;

typedef struct {
    int x;
    int y;
} Pos;

struct WinMgr;
extern const Pos sRecordListFramePositions[];

extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);
extern struct WinMgr *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BGWINFRM_SetFrameDataArcHandle(struct WinMgr *mgr, u32 idx, void *arc, u32 member, u32 alloc);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);

void BSUBWAY_RECORD_LIST_LoadGraphics(u8 *p)
{
    void *arc = ((struct Obj06170 *)p)->f0;
    void *arc2;
    int i;

    func_02049658(arc, 5, 5, 0, 0, 1, 0x80);
    func_020498F4(arc, 4, 5, 0, 0, 1, 0x80);
    func_02049B68(arc, 6, 4, 0, 0, 0x80);
    func_02049658(arc, 1, 2, 0, 0, 1, 0x80);
    func_020498F4(arc, 0, 2, 0, 0, 1, 0x80);
    func_02049B68(arc, 2, 0, 0, 0, 0x80);
    func_02049658(arc, 1, 1, 0, 0, 1, 0x80);
    func_020498F4(arc, 0, 1, 0, 0, 1, 0x80);
    arc2 = func_020490F4(APP_ICON_GetArchiveId(), 0x80);
    func_02049658(arc2, APP_ICON_GetStatusFrameFileId(), 1, 0, 0, 0, 0x80);
    func_020498F4(arc2, APP_ICON_GetStatusDataFileId(), 1, 0, 0, 0, 0x80);
    ARC_UTIL_UploadPaletteFromHandle(arc2, APP_ICON_GetStatusAnimFileId(), 0, 0, 0x1C0, 0x20, 0x80);
    BG_SYS_FillTileMap(1, 0, 0x15, 0x20, 3, 0xE);
    func_020409B4(1);
    ARC_TOOL_DeleteHandle(arc2);
    func_02049B40(0x17, 5, 0, 0x1E0, 0x20, 0x80);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x80);
    ((struct Obj06170 *)p)->f4 = BGWINFRM_Create(2, 10, 0x80);
    for (i = 0; i < 10; i++) {
        BGWINFRM_AddFrame(((struct Obj06170 *)p)->f4, i, 1, 0xE, 4);
        BGWINFRM_SetFrameDataArcHandle(((struct Obj06170 *)p)->f4, i, arc, 3, 1);
        BGWINFRM_PutFrame(((struct Obj06170 *)p)->f4, i, sRecordListFramePositions[i].x, sRecordListFramePositions[i].y);
    }
}
