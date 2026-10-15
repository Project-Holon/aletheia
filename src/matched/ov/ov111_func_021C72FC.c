/*
 * function: VIEWER_TEXT_LoadBgResources
 * address:  0x021C72FC
 * packet:   pkt_ov111_021C72FC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever:    enum-typed zero in the eighth call preserves copied argument registers and the preceding late heap store.
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
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BMP_MENUWORK_LoadPltt  0x0201F57C  thumb
 *   BMP_MENUWORK_LoadChar  0x0201F554  thumb
 *   ARC_UTIL_LoadPaletteBlockFromHandle  0x02049F78  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[2];
    u16 f122;
    u8 pad124[4];
    int f128;
    int f12C;
    int f130;
    u8 pad134[4];
    int f138;
    int f13C;
    int f140;
    int f144;
    int f148;
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *arc, u32 id, u32 frame, u32 a, u32 b, u32 c, u16 heap);
extern void func_02049B68(void *arc, u32 id, u32 a, u32 b, u32 c, u16 heap);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_PushTile(u32 index);
extern void BMP_MENUWORK_LoadPltt(u32 a, u32 b, u32 c, u32 d);
extern void BMP_MENUWORK_LoadChar(u32 a, u32 b, u32 c, u32 d);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);

void VIEWER_TEXT_LoadBgResources(Work *p)
{
    typedef enum { Zero } ZeroArg;
    ZeroArg z = Zero;
    void *arc = p->f0;
    void *arc2;
    int i;

    func_02049658(arc, 0x19, 6, 0, 0, 0, 0x27);
    func_020498F4(arc, 0x22, 6, 0, 0, 0, 0x27);
    func_02049B68(arc, 1, 4, 0, 0, 0x27);
    func_02049658(arc, 0x1A, 5, 0, 0, 0, 0x27);
    func_020498F4(arc, 0x23, 5, 0, 0, 0, 0x27);
    func_02049658(arc, 0x19, 3, 0, 0, 0, 0x27);
    func_020498F4(arc, 0x22, 3, 0, 0, 0, 0x27);
    func_02049B68(arc, z, z, z, z, 0x27);
    func_02049658(arc, 0x19, 1, 0, 0, 0, 0x27);
    func_020498F4(arc, 0x21, 1, 0, 0, 0, 0x27);
    arc2 = func_020490F4(APP_ICON_GetArchiveId(), 0x27);
    func_02049658(arc2, APP_ICON_GetStatusFrameFileId(), 2, 0, 0, 0, 0x27);
    func_020498F4(arc2, APP_ICON_GetStatusDataFileId(), 2, 0, 0, 0, 0x27);
    ARC_UTIL_UploadPaletteFromHandle(arc2, APP_ICON_GetStatusAnimFileId(), 0, 0, 0x1C0, 0x20, 0x27);
    BG_SYS_FillTileMap(2, 0, 0x15, 0x20, 3, 0xE);
    BG_SYS_PushTile(2);
    ARC_TOOL_DeleteHandle(arc2);
    func_02049B40(0x17, 5, 0, 0x1E0, 0x20, 0x27);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x27);
    BMP_MENUWORK_LoadPltt(4, 0xE, 0, 0x27);
    BMP_MENUWORK_LoadChar(4, 1, 0, 0x27);
    for (i = 0; i < 3; i++) {
        p->f14C[i] = ARC_UTIL_LoadPaletteBlockFromHandle(arc, 4 - i, (u32)(&p->f158[i]), 0x27);
    }
    for (i = 0; i < 3; i++) {
        p->f164[i] = ARC_UTIL_LoadPaletteBlockFromHandle(arc, 0x17 - i, (u32)(&p->f170[i]), 0x27);
    }
}
