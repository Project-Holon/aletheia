/*
 * function: RESEARCH_TOP_LoadTopAssets
 * address: 0x021B9A24
 * packet: pkt_ov217_021B9A24
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * declaration: original 021B9A34/38 truncates heap to u16 before ARC_TOOL_CreateHandle despite its legacy u32 declaration.
 * declaration: ARC_TOOL_DeleteHandle's legacy void asm body reads entry r0 into r4 and forwards it twice; retain the visible archive argument.
 * symbols:
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   NNS_G2dGetUnpackedPaletteData 0x02062A98 arm
 *   BG_SYS_LoadPltt 0x02040E78 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   NNS_G2dGetUnpackedCharacterDataEx 0x02062A4C arm
 *   BG_SYS_LoadTileData 0x02040B1C arm
 *   NNS_G2dGetUnpackedScreenData 0x02062B30 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj14724.h"
#include "../include/Obj25805.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct ArcFile;
struct NitroFileHeader;
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *, u32, u32);
extern int NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *, void **);
extern void BG_SYS_LoadPltt(u32, void *, u32, u32);
extern u32 GFL_HEAP_Free(void *p);
extern int NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *, void **);
extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);
extern int NNS_G2dGetUnpackedScreenData(void *, void **);
extern void BG_SYS_DrawTile(u32, u32, u32, u32, u8, u8);
extern void BG_SYS_PushTile(u32);
extern void ARC_TOOL_DeleteHandle(struct ArcFile *);
void RESEARCH_TOP_LoadTopAssets(u32 heap)
{
    void *palette;
    void *character;
    void *screen;
    struct ArcFile *arc;
    void *buffer;
    arc = ARC_TOOL_CreateHandle(192, (u16)((heap & 0x7fff) | 0x8000));
    buffer = ARC_TOOL_LoadHandleMember(arc, 0, heap);
    NNS_G2dGetUnpackedPaletteData(buffer, &palette);
    BG_SYS_LoadPltt(1, ((struct Obj25805 *)palette)->fC, 512, 0);
    GFL_HEAP_Free(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 1, heap);
    NNS_G2dGetUnpackedCharacterDataEx(buffer, &character);
    BG_SYS_LoadTileData(1, ((struct Obj14724 *)character)->f14, ((struct Obj14724 *)character)->f10, 0);
    GFL_HEAP_Free(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 2, heap);
    NNS_G2dGetUnpackedScreenData(buffer, &screen);
    BG_SYS_DrawTile(1, (u32)((char *)screen + 12), 0, 0, 32, 24);
    BG_SYS_PushTile(1);
    GFL_HEAP_Free(buffer);
    ARC_TOOL_DeleteHandle(arc);
}
