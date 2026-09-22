/*
 * function: func_02069078
 * address:  0x02069078
 * packet:   pkt_02069078
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02069128    0x02069128  arm
 *
 * NitroSystem NNS_G2dMapScrToCharText (g2d_CharCanvas): map a rectangle of
 * a text-BG screen to consecutive character numbers.  A screen no wider
 * than 32 entries is linear and goes to func_02069128; a 64-wide screen is
 * two 32x32 blocks side by side, so row y >= 32 skips the right-hand block
 * (y + 32) and column x >= 32 lands in it (x + 32 * 31).
 *
 * Levers: `scnWidth * areaTop + areaLeft` in that order and parenthesised
 * (the image's `mla r4, r5, lr, r3`; the unparenthesised sum is two adds,
 * and the other product order is 2 bytes out); `const u16 cpltMask` and the
 * post-increment inside the store, as in func_02069128.
 *
 * COMPILER PIN ../2.0/sp2 (docs/FRONTEND-PINS.md): both 32-block selects are
 * true conditional-move pairs in the image, `cmp lr, #0x20` / `movlt r2, lr`
 * / `addge r2, lr, #0x20` at 0x020690D0..0x020690D8 and `cmp r7, #0x20` /
 * `movlt r2, r7` / `addge r2, r7, #0x3e0` at 0x020690EC..0x020690F4; dsi/1.1p1
 * emits an unconditional `mov r2, lr` before the `cmp` (and `mov r2, r7`),
 * 16 concrete bytes out at 176.  0 mismatches under the pin.
 */
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02069128(u16 *pScrBase, int w, int h, int scnWidth, int charNo, int cplt);

void func_02069078(void *scnBase, int areaWidth, int areaHeight, int areaLeft, int areaTop,
                   int scnWidth, int charNo, int cplt)
{
    if (scnWidth <= 32) {
        func_02069128((u16 *)scnBase + (scnWidth * areaTop + areaLeft), areaWidth, areaHeight,
                      scnWidth, charNo, cplt);
    } else {
        const int areaRight = areaLeft + areaWidth;
        const int areaBottom = areaTop + areaHeight;
        const u16 cpltMask = (u16)(cplt << 12);
        int x, y;

        for (y = areaTop; y < areaBottom; y++) {
            u16 *pLine = (u16 *)scnBase + ((y < 32) ? y : y + 32) * 32;
            for (x = areaLeft; x < areaRight; x++) {
                pLine[(x < 32) ? x : x + 32 * 31] = (u16)(charNo++ | cpltMask);
            }
        }
    }
}
