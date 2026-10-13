/*
 * function: MCSS_TOOL_DrawSpindaSpots
 * address:  0x020172D8
 * packet:   pkt_020172D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   sMcssTable  0x020A72D4  data
 *
 * mcss.c.  Walks four (x, y) offset lists and bumps the matching nibble of
 * two bytes per point.  Lever (wave 16): the read-modify-write of a0[p] is a
 * compound assignment `a0[p] += 0x50` / `a0[p] += 5`; the spelled-out
 * `a0[p] = (u8)(val + 0x50)` left a three-register rotation (a0/k/b0, 47
 * bytes out) that no declaration order, scope, type or permuter run moved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_TOOL_DrawSpindaSpots.c \
 *       --func MCSS_TOOL_DrawSpindaSpots --addr 0x020172D8 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern const u8 *sMcssTable[4];

void MCSS_TOOL_DrawSpindaSpots(u8 *a0, u32 a1)
{
    const u8 *cur;
    s32 i;
    s32 n;
    s32 d[2];

    for (i = 0; i < 4; i++) {
        cur = sMcssTable[i];
        n = 0;
        if (cur[0] != 0xff) {
            d[1] = (a1 & 0xf) - 8;
            d[0] = ((a1 & 0xf0) >> 4) - 8;
            do {
                u8 b0 = (u8)(d[1] + cur[n * 2]);
                u32 b1 = (u8)(d[0] + cur[n * 2 + 1]);
                u32 idx[2];
                s32 k;
                idx[0] = ((u32)b0 >> 1) + (b1 << 7);
                idx[1] = ((u32)b0 >> 1) + ((b1 + 0x28) << 7);
                for (k = 0; k < 2; k++) {
                    if ((b0 & 1) != 0) {
                        u32 p = idx[k];
                        u8 val = a0[p];
                        s32 v = val & 0xf0;
                        if (v >= 0x10 && v <= 0x30) {
                            a0[p] += 0x50;
                        }
                    } else {
                        u32 p = idx[k];
                        u8 val = a0[p];
                        s32 v = 0xf & val;
                        if (v >= 1 && v <= 3) {
                            a0[p] += 5;
                        }
                    }
                }
                n = (u8)(n + 1);
            } while (cur[n * 2] != 0xff);
        }
        a1 = a1 >> 8;
    }
}
