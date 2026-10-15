/*
 * function: EL_SCOREBOARD_LoadSeasonGraphics
 * address:  0x0218794C
 * packet:   pkt_ov020_0218794C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   BG_SYS_LoadPltt  0x02040E78  arm
 *   func_020307B0  0x020307B0  arm
 *   NNS_G2dGetUnpackedCharacterDataEx  0x02062A4C  arm
 *   BG_SYS_LoadTileData  0x02040B1C  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   BG_SYS_PushTileSource  0x020409E0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */

void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
struct ArcFile;
void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
typedef signed int     s32;
struct NitroFileHeader;
s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);
void BG_SYS_LoadPltt(u32 r7, void *r6, u32 r5, u32 r4);
u32 func_020307B0(void *p);
s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);
void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);
int NNS_G2dGetUnpackedScreenData(void *file, void **out);
void BG_SYS_PushTileSource(u32 index, const void *src, u32 mode, u32 offset);
void ARC_TOOL_DeleteHandle(void *x);

void EL_SCOREBOARD_LoadSeasonGraphics(int sel, int b)
{
    int *l_c;
    int *l_8;
    int *l_4;
    void *x;
    void *v;
    int i0, i1, i2;

    switch (sel) {
    default:
    case 0:
        i0 = 0; i1 = 1; i2 = 2;
        break;
    case 1:
        i0 = 3; i1 = 4; i2 = 5;
        break;
    case 2:
        i0 = 6; i1 = 7; i2 = 8;
        break;
    case 3:
        i0 = 9; i1 = 10; i2 = 11;
        break;
    }
    x = func_020490F4(0x97, b);
    v = ARC_TOOL_LoadHandleMember(x, i0, b);
    NNS_G2dGetUnpackedPaletteData(v, (void **)(&l_c));
    BG_SYS_LoadPltt(3, (void *)l_c[3], 0x20, 0);
    func_020307B0(v);
    v = ARC_TOOL_LoadHandleMember(x, i1, b);
    NNS_G2dGetUnpackedCharacterDataEx(v, (void **)(&l_8));
    BG_SYS_LoadTileData(3, (const void *)l_8[5], l_8[4], 0);
    func_020307B0(v);
    v = ARC_TOOL_LoadHandleMember(x, i2, b);
    NNS_G2dGetUnpackedScreenData(v, (void **)(&l_4));
    BG_SYS_PushTileSource(3, l_4 + 3, l_4[2], 0);
    func_020307B0(v);
    ARC_TOOL_DeleteHandle(x);
}
