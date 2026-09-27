/*
 * function: GXx_SetMasterBrightness_
 * address:  0x0207D534
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Original (40 bytes, no relocation):
 *   cmp    r1, #0
 *   moveq  r1, #0
 *   strheq r1, [r0]
 *   bxeq   lr
 *   orrgt  r1, r1, #0x4000
 *   strhgt r1, [r0]
 *   rsble  r1, r1, #0
 *   orrle  r1, r1, #0x8000
 *   strhle r1, [r0]
 *   bx     lr
 */

typedef unsigned short u16;
typedef int s32;

void GXx_SetMasterBrightness_(volatile u16 *reg, s32 val)
{
    if (val == 0) {
        *reg = 0;
        return;
    }
    if (val > 0)
        *reg = (u16)(val | 0x4000);
    else
        *reg = (u16)(-val | 0x8000);
}
