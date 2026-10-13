/*
 * function: EL_SCOREBOARD_AnimateLampPalette
 * address: 0x021876B0
 * packet: pkt_ov020_021876B0
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02061CA4 0x02061CA4 arm
 *   EL_SCOREBOARD_LampPaletteColors 0x02187ECC data ov020 a4
 */
typedef unsigned short u16;
typedef struct { int index; char *base; } Pair;
extern int EL_SCOREBOARD_LampPaletteColors[];
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
void EL_SCOREBOARD_AnimateLampPalette(Pair *p, int tick)
{
    func_02061CA4((void *)1, (u32)(p->base + (u16)p->index * 8), EL_SCOREBOARD_LampPaletteColors[(tick & 31) / 8], 8);
}
