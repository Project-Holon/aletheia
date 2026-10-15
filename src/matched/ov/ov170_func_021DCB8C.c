/*
 * function: BOX2_MAIN_LoadBgData
 * address:  0x021DCB8C
 * packet:   pkt_ov170_021DCB8C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: 2026-10-05 (wD9r lane76): closed by the real u32 return type of func_02049658 (as in the
 *   matched ov210 021BC5DC). With a void return the register zeros became copies of the zero
 *   register from the 0x3F call on (14 bytes). Zero arguments are plain literals.
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_02049740  0x02049740  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   BG_SYS_LoadPltt  0x02040E78  arm
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb
 *   APP_ICON_GetStatusAnimFileId  0x02027624  thumb
 *   APP_ICON_GetStatusDataFileId  0x0202762C  thumb
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   BMP_MENUWORK_LoadFrameGfx  0x0201F5DC  thumb
 *   func_02049B40  0x02049B40  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 f0; u32 f4; u32 f8; u8 *fC; } PlttData;
struct Ov170Ctx { char pad[0x2c]; char *f2c; };

extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern u32 func_02049740(void *, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern u32 APP_ICON_GetArchiveId(void);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
extern void BG_SYS_LoadPltt(u32 a, void *src, u32 size, u32 ofs);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32);
extern u32 BG_SYS_GetBuf(int channel);
extern void *BMP_MENUWORK_LoadFrameGfx(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);

void BOX2_MAIN_LoadBgData(struct Ov170Ctx *ctx)
{
    void *arc;
    void *arc2;
    void *pal;
    PlttData *pd;
    u8 *src;
    u32 ofs;
    u32 r6;
    u16 *a;
    u16 *b;
    u32 i;

    arc = func_020490F4(0x74, 0x4c);
    func_02049658(arc, 0xc, 1, 0, 0, 1, 0x4c);
    func_02049740(arc, 3, 2, 0, 1, 0x4c);
    func_020498F4(arc, 2, 2, 0, 0, 1, 0x4c);
    func_02049658(arc, 1, 3, 0, 0, 1, 0x4c);
    func_020498F4(arc, 0, 3, 0, 0, 1, 0x4c);
    func_02049B68(arc, 4, 0, 0, 0x80, 0x4c);
    func_02049658(arc, 0x3e, 1, 1000, 0x300, 1, 0x4c);
    func_02049B68(arc, 0x3f, 0, 0x180, 0x40, 0x4c);
    pal = ARC_UTIL_LoadPaletteBlockFromArchive(APP_ICON_GetArchiveId(), 0x1f, (u32)(&pd), 0x804c);
    src = pd->fC;
    ofs = 0x194;
    BG_SYS_LoadPltt(0, src + 0x34, 4, ofs);
    src += 0x14;
    ofs += 0x20;
    BG_SYS_LoadPltt(0, src, 4, ofs);
    func_020307B0(pal);
    func_02049658(arc, 6, 5, 0, 0, 1, 0x4c);
    func_020498F4(arc, 5, 5, 0, 0, 1, 0x4c);
    func_02049658(arc, 6, 6, 0, 0, 1, 0x4c);
    func_02049B68(arc, 7, 4, 0, 0, 0x4c);
    ARC_TOOL_DeleteHandle(arc);
    arc2 = func_020490F4(APP_ICON_GetArchiveId(), 0x4c);
    func_02049740(arc2, APP_ICON_GetStatusFrameFileId(), 0, 0, 0, 0x4c);
    func_02049B68(arc2, APP_ICON_GetStatusAnimFileId(), 0, 0xe0, 0x20, 0x4c);
    func_020498F4(arc2, APP_ICON_GetStatusDataFileId(), 0, 0, 0, 0, 0x4c);
    BG_SYS_FillTileMap(0, 0, 0x15, 0x20, 3, 7);
    func_02041B6C(0);
    r6 = func_02049740(arc2, APP_ICON_GetStatusFrameFileId(), 2, 0, 0, 0x4c);
    ARC_TOOL_DeleteHandle(arc2);
    a = (u16 *)BG_SYS_GetBuf(0);
    b = (u16 *)BG_SYS_GetBuf(2);
    for (i = 0; i < 0x60u; i++) {
        *(u16 *)((char *)b + 0x540 + i * 2) = r6 + *(u16 *)((char *)a + 0x540 + i * 2);
    }
    func_02041B6C(2);
    *(int *)(ctx->f2c + 0x178) = (int)BMP_MENUWORK_LoadFrameGfx(0, 10, 0, 0x4c);
    func_02049B40(0x17, 5, 0, 0x160, 0x20, 0x4c);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0x4c);
}
