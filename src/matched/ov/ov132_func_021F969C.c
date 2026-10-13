/*
 * function: func_021F969C
 * address:  0x021F969C
 * packet:   pkt_ov132_021F969C
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: The matched 020064B8 body reads four arguments; incoming r3 is
 * forwarded unchanged, preventing the erroneous three-argument tail call.
 *
 * symbols:
 *   GFL_USE_ReplaceWaveData  0x020064B8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23187.h"

typedef unsigned int u32;
extern int GFL_USE_ReplaceWaveData(u32, u32, u32, u32);

int func_021F969C(char *p, u32 a, u32 b, u32 d)
{
    return GFL_USE_ReplaceWaveData(a, b, ((struct Obj23187 *)p)->f1E4, d);
}
