/*
 * function: ZUKAN_DETAIL_AREA_FindPlayerTownIndex
 * address:  0x021C0C14
 * packet:   pkt_ov208_021C0C14
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov208_func_021BC3A4  0x021BC3A4  thumb  ov208
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   SYMBOL_MAP_ResolveZoneId  0x02166C7C  thumb
 *   TOWNMAP_GRH_FindRecordIndex  0x021BBB48  thumb  ov072
 */
#include "../include/Obj25500.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int  ov208_func_021BC3A4(int key);
struct SaveBlock;
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
struct Rec44;
extern u16  GAME_DATA_GetPlayerZoneId(const struct Rec44 *a);
extern u32  SYMBOL_MAP_ResolveZoneId(int a, u32 b);
extern int TOWNMAP_GRH_FindRecordIndex(int a0, int a1);

u8 ZUKAN_DETAIL_AREA_FindPlayerTownIndex(u16 *heap, u8 *p, int key)
{
    int a;
    u32 m;
    int v;
    u8 r;

    a = ov208_func_021BC3A4(key);
    m = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAME_DATA_GetMyPlayerWork((struct SaveBlock *)a));
    r = 0xff;
    v = TOWNMAP_GRH_FindRecordIndex(((struct Obj25500 *)p)->f3C8, SYMBOL_MAP_ResolveZoneId(a, m));
    if (v != 0xffff)
        r = v;
    return r;
}
