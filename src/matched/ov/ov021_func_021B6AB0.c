/*
 * function: SCRCMD_POKEMON_FLD_CountWarpEntries
 * address:  0x021B6AB0
 * packet:   pkt_ov021_021B6AB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_POKEMON_FLD_GetWarpEntry  0x021B6AA4  thumb ov021
 *   SCRCMD_POKEMON_FLD_NoopWarpEntry  0x021B6AAC  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int SCRCMD_POKEMON_FLD_GetWarpEntry(u32 a, u32 b);
extern void SCRCMD_POKEMON_FLD_NoopWarpEntry(u16 *);

int SCRCMD_POKEMON_FLD_CountWarpEntries(void *a)
{
    int i;
    u16 *p;

    for (i = 0; i < 8; i++) {
        p = (u16 *)SCRCMD_POKEMON_FLD_GetWarpEntry((u32)a, i);
        SCRCMD_POKEMON_FLD_NoopWarpEntry(p);
        if (*p == 0xFFFF) {
            return i;
        }
    }
    return 0;
}
