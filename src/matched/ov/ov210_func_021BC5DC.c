/*
 * function: ZKNSEARCH_MAIN_LoadCommonGraphics
 * address: 0x021BC5DC
 * packet: pkt_ov210_021BC5DC
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wD9r lane54): closed. func_02049658 returns a value (as in the matched
 *   ov123 021D9D3C and ov110 021BB328); declared void, it let mwcc pool the 4s and zeros into r7/r5
 *   copies and took r7 from 0x807B. With the u32 return and an uninitialised u32 i set by the for statement it is EXACT.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetStatusFrameFileId 0x02027628 thumb
 *   APP_ICON_GetStatusAnimFileId 0x02027624 thumb
 *   APP_ICON_GetStatusDataFileId 0x0202762C thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_GetBuf 0x0204162C arm
 *   func_02049B40 0x02049B40 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *h);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 layer);
extern u32 BG_SYS_GetBuf(int channel);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void ZKNSEARCH_MAIN_LoadCommonGraphics(void)
{
    void *h;
    u32 base;
    u32 i;
    u8 *scr;

    h = func_020490F4(0x9F, 0x807B);
    func_02049B68(h, 0x49, 0, 0, 0xC0, 0x7B);
    func_02049B68(h, 0x4A, 4, 0, 0xA0, 0x7B);
    func_02049740(h, 0x51, 0, 0, 0, 0x7B);
    func_02049658(h, 0x51, 1, 0, 0, 0, 0x7B);
    func_02049658(h, 0x51, 3, 0, 0, 0, 0x7B);
    func_02049658(h, 0x4F, 2, 0, 0, 0, 0x7B);
    func_02049658(h, 0x51, 5, 0, 0, 0, 0x7B);
    func_02049658(h, 0x50, 6, 0, 0, 0, 0x7B);
    func_02049658(h, 0x50, 4, 0, 0, 0, 0x7B);
    func_020498F4(h, 0x5F, 2, 0, 0, 0, 0x7B);
    func_020498F4(h, 0x5E, 4, 0, 0, 0, 0x7B);
    func_020498F4(h, 0x60, 6, 0, 0, 0, 0x7B);
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(APP_ICON_GetArchiveId(), 0x807B);
    base = func_02049740(h, APP_ICON_GetStatusFrameFileId(), 0, 0, 0, 0x7B);
    func_02049B68(h, APP_ICON_GetStatusAnimFileId(), 0, 0x1C0, 0x20, 0x7B);
    func_020498F4(h, APP_ICON_GetStatusDataFileId(), 0, 0, 0, 0, 0x7B);
    BG_SYS_FillTileMap(0, 0, 0x15, 0x20, 3, 0xE);
    func_02041B6C(0);
    ARC_TOOL_DeleteHandle(h);
    scr = (u8 *)BG_SYS_GetBuf(0);
    for (i = 0; i < 0x60; i++) {
        ((u16 *)scr)[i + 0x2A0] += (u16)base;
    }
    func_02041B6C(0);
    func_02049B40(0x17, 5, 0, 0x1E0, 0x20, 0x7B);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x7B);
}
