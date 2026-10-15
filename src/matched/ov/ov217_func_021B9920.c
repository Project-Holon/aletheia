/*
 * function: RESEARCH_TOP_LoadSubAssets
 * address: 0x021B9920
 * packet: pkt_ov217_021B9920
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 (wD9r lane26): closed by the real return type of NNS_G2dGetUnpackedScreenData (int, as in the matched
 *   sibling 021B9A24). Declared void, mwcc hoists the block-4 constant 5 into r6.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   NNS_G2dGetUnpackedPaletteData 0x02062A98 arm
 *   BG_SYS_LoadPltt 0x02040E78 arm
 *   func_020307B0 0x020307B0 arm
 *   NNS_G2dGetUnpackedCharacterDataEx 0x02062A4C arm
 *   BG_SYS_LoadTileData 0x02040B1C arm
 *   NNS_G2dGetUnpackedScreenData 0x02062B30 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct ArcFile;
struct NitroFileHeader;
extern void *func_020490F4(unsigned int id, u32 heap);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *, u32, u32);
extern int NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *, void **);
extern void BG_SYS_LoadPltt(u32, void *, u32, u32);
extern u32 func_020307B0(void *p);
extern int NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *, void **);
extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);
extern int NNS_G2dGetUnpackedScreenData(void *, void **);
extern void BG_SYS_DrawTile(u32, u32, u32, u32, u8, u8);
extern void BG_SYS_PushTile(u32);
extern void ARC_TOOL_DeleteHandle(struct ArcFile *);
void RESEARCH_TOP_LoadSubAssets(u32 heap)
{
    void *palette;
    void *character;
    void *screen;
    void *screen2;
    struct ArcFile *arc;
    void *buffer;
    arc = func_020490F4(192, heap);
    buffer = ARC_TOOL_LoadHandleMember(arc, 9, heap);
    NNS_G2dGetUnpackedPaletteData(buffer, &palette);
    BG_SYS_LoadPltt(4, *(void **)((char *)palette + 12), 512, 0);
    func_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 10, heap);
    NNS_G2dGetUnpackedCharacterDataEx(buffer, &character);
    BG_SYS_LoadTileData(4, *(void **)((char *)character + 0x14), *(u32 *)((char *)character + 0x10), 0);
    func_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 11, heap);
    NNS_G2dGetUnpackedScreenData(buffer, &screen);
    BG_SYS_DrawTile(4, (u32)((char *)screen + 12), 0, 0, 32, 24);
    BG_SYS_PushTile(4);
    func_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 12, heap);
    NNS_G2dGetUnpackedScreenData(buffer, &screen2);
    BG_SYS_DrawTile(5, (u32)((char *)screen2 + 12), 0, 0, 32, 24);
    BG_SYS_PushTile(5);
    func_020307B0(buffer);
    ARC_TOOL_DeleteHandle(arc);
}
