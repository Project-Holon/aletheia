/*
 * function: C_GEAR_POWER_ONOFF_InitBgs
 * address:  0x021F000C
 * packet:   pkt_ov035_021F000C
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_InitBgs 0x021F000C thumb
 *   func_02040588 0x02040588 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 *   func_020490F4 0x020490F4 arm
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   d_021F05B0    0x021F05B0 data a4
 *   sBgPaletteFileIds    0x021F05BC data ov035 a4
 *   d_021F05C8    0x021F05C8 data ov035 a4
 *   d_021F05E8    0x021F05E8 data ov035 a4
 *   d_021F0608    0x021F0608 data ov035 a4
 */
#include "../include/Obj13078.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BgTemplate;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_020409B4(u32 layer);
extern void *func_020490F4(unsigned int id, unsigned int heap);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *h, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_02049740(void *h, u32 id, u32 layer, u32 ofs, u32 size, u32 heap);
extern void ARC_UTIL_UploadBgPaletteAddFromHandle(void *h, u32 id, u32 layer, u32 ofs, u32 chrOfs, u32 a5, u32 a6,
    u32 heap);
extern void ARC_TOOL_DeleteHandle(void *h);

extern const u32 d_021F05B0[];
extern const u32 sBgPaletteFileIds[];
extern const u8 d_021F05C8[];
extern const u8 d_021F05E8[];
extern const u8 d_021F0608[];

void C_GEAR_POWER_ONOFF_InitBgs(char *p, u32 heap)
{
    int i;
    void *h;
    u32 r;

    for (i = 4; i <= 7; i++)
        func_02040588((u8)i, 0);
    func_0203FCA0(6, (const struct BgTemplate *)d_021F0608, 0);
    func_020414EC(6);
    func_020409B4(6);
    func_02040588((u8)6, 1);
    func_0203FCA0(5, (const struct BgTemplate *)d_021F05C8, 0);
    func_020414EC(5);
    func_020409B4(5);
    func_02040588((u8)5, 1);
    func_0203FCA0(4, (const struct BgTemplate *)d_021F05E8, 0);
    func_020414EC(4);
    func_020409B4(4);
    func_02040588((u8)4, 1);
    h = func_020490F4(0x1E, heap);
    i = func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(((struct Obj13078 *)p)->f4)));
    func_02049B68(h, sBgPaletteFileIds[i], 4, 0, 1, heap);
    r = func_02049740(h, d_021F05B0[i], 6, 0, 0, heap);
    ((struct Obj13078 *)p)->f10 = r;
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 3, 6, 0, (u16)r, 0, 0, heap);
    ARC_TOOL_DeleteHandle(h);
}
