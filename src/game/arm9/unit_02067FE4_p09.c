/*
 * function: func_02069128
 * address:  0x02069128
 * packet:   pkt_02069078
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The linear half of NitroSystem's NNS_G2dMapScrToCharText (g2d_CharCanvas):
 * fill an areaWidth x areaHeight block of a text-BG screen whose rows are
 * scnWidth entries apart with consecutive character numbers, palette
 * `cplt` in the top four bits of every entry.  func_02069078 calls it for
 * screens no wider than 32 entries.
 *
 * Three spellings decide it, all measured:
 *   - the palette field is a `const u16 cpltMask = (u16)(cplt << 12)`: the
 *     compiler keeps it as `cplt << 28` and ORs it in with `lsr #16`;
 *   - the store is `*pScr++ = (u16)(charNo++ | cpltMask)` with the
 *     post-increment INSIDE the store expression (a separate `charNo++`
 *     statement is 8 bytes out, the old `top = hi << 28` reading 15);
 *   - `x` and `y` declared together at function scope, x first.
 * The same C is EXACT under dsi/1.1p1 and ../2.0/sp2; no pin.
 */
typedef unsigned short u16;
typedef unsigned int   u32;

/*
 * The linear half of NitroSystem's NNS_G2dMapScrToCharText (g2d_CharCanvas):
 * fill an areaWidth x areaHeight block of a text-BG screen whose rows are
 * scnWidth entries apart with consecutive character numbers, palette
 * `cplt` in the top four bits of every entry.  func_02069078 calls it for
 * screens no wider than 32 entries.
 *
 * Three spellings decide it, all measured:
 *   - the palette field is a `const u16 cpltMask = (u16)(cplt << 12)`: the
 *     compiler keeps it as `cplt << 28` and ORs it in with `lsr #16`;
 *   - the store is `*pScr++ = (u16)(charNo++ | cpltMask)` with the
 *     post-increment INSIDE the store expression (a separate `charNo++`
 *     statement is 8 bytes out, the old `top = hi << 28` reading 15);
 *   - `x` and `y` declared together at function scope, x first.
 * The same C is EXACT under dsi/1.1p1 and ../2.0/sp2; no pin.
 */
void func_02069128(u16 *pScrBase, int w, int h, int scnWidth, int charNo, int cplt)
{
    int x, y;
    const u16 cpltMask = (u16)(cplt << 12);

    for (y = 0; y < h; y++) {
        u16 *pScr = pScrBase;
        for (x = 0; x < w; x++) {
            *pScr++ = (u16)(charNo++ | cpltMask);
        }
        pScrBase += scnWidth;
    }
}
