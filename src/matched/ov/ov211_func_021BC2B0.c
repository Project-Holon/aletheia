/*
 * function: ZUKAN_SEARCH_SCREEN_SetupVram
 * address:  0x021BC2B0
 * packet:   pkt_021BC2B0
 * region:   ov211
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   d_021BC990    0x021BC990 data ov211
 */

typedef struct
{
    int v[12];
} S021BC2B0;

typedef unsigned int   u32;
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern S021BC2B0 d_021BC990;

void ZUKAN_SEARCH_SCREEN_SetupVram(void)
{
    S021BC2B0 buf = d_021BC990;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)(&buf));
}
