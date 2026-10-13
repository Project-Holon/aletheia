/*
 * function: FIELD_SAVEANIME_LoadResource
 * address:  0x021D11F4
 * packet:   pkt_ov021_021D11F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   BMP_CreateFromArchive  0x0204384C  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   d_021DB97C     0x021DB97C  data    ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(unsigned int id, unsigned int heap);
struct Bmp;
struct Ctx;
struct Sub0200852CObj;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern struct Bmp *BMP_CreateFromArchive(u32 arc, u32 member, u32 heap2, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandle(void *h, u32 id, u32 type, u32 ofs, u32 src, u32 size, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *h);
extern const u32 d_021DB97C[];

void FIELD_SAVEANIME_LoadResource(u32 *p, u32 b)
{
    void *h = func_020490F4(200, b);
    u32 idx;

    idx = func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)p[0]))));
    p[4] = (u32)BMP_CreateFromArchive(200, 0, 0, b);
    ARC_UTIL_UploadPaletteFromHandle(h, 1, 0, d_021DB97C[idx] << 5, 0x120, 0x20, b);
    ARC_TOOL_DeleteHandle(h);
}
