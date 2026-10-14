/*
 * function: RESEARCH_COMMON_Init
 * address: 0x021C0A5C
 * packet: pkt_ov217_021C0A5C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   RESEARCH_COMMON_InitClact 0x021C0AD8 thumb ov217
 *   RESEARCH_COMMON_RegisterResources 0x021C0B0C thumb ov217
 *   RESEARCH_COMMON_CreateClactUnit 0x021C0B94 thumb ov217
 *   RESEARCH_COMMON_CreateActor 0x021C0BBC thumb ov217
 *   RESEARCH_COMMON_CreatePalAnm 0x021C0C40 thumb ov217
 *   RESEARCH_COMMON_AllocSlotBuffers 0x021C0C5C thumb ov217
 *   RESEARCH_COMMON_InitTouchRects 0x021C0D88 thumb ov217
 *   RESEARCH_COMMON_CreatePaletteAnime 0x021C0CF8 thumb ov217
 *   RESEARCH_COMMON_BindPaletteAnime 0x021C0D14 thumb ov217
 */
#include "../include/Obj00791.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *);
extern void RESEARCH_COMMON_InitClact(u32);
extern void RESEARCH_COMMON_RegisterResources(u8 *);
extern void RESEARCH_COMMON_CreateClactUnit(u32);
extern void RESEARCH_COMMON_CreateActor(u8 *);
extern void RESEARCH_COMMON_CreatePalAnm(u32);
extern void RESEARCH_COMMON_AllocSlotBuffers(u8 *);
extern void RESEARCH_COMMON_InitTouchRects(u8 *);
extern void RESEARCH_COMMON_CreatePaletteAnime(u32);
extern u32 RESEARCH_COMMON_BindPaletteAnime(u8 *);
void RESEARCH_COMMON_Init(u8 *p, const struct Ctx *ctx, u32 heap)
{
    ((struct Obj00791 *)p)->f0 = heap;
    *(const struct Ctx * *)&((struct Obj00791 *)p)->f4 = ctx;
    ((struct Obj00791 *)p)->f8 = GAMESYSTEM_GetGameData(ctx);
    RESEARCH_COMMON_InitClact((u32)p);
    RESEARCH_COMMON_RegisterResources(p);
    RESEARCH_COMMON_CreateClactUnit((u32)p);
    RESEARCH_COMMON_CreateActor(p);
    RESEARCH_COMMON_CreatePalAnm((u32)p);
    RESEARCH_COMMON_AllocSlotBuffers(p);
    RESEARCH_COMMON_InitTouchRects(p);
    RESEARCH_COMMON_CreatePaletteAnime((u32)p);
    RESEARCH_COMMON_BindPaletteAnime(p);
}
