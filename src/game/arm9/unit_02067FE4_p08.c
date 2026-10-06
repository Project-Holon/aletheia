/*
 * file:     unit_02067FE4_p08.c
 * unit:     yes
 * function: func_02068FF0, func_02069078
 * address:  0x02068FF0
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02068E78  0x02068E78  arm
 *   g_020A18F4     0x020A18F4  data
 *   g_020A18E8     0x020A18E8  data
 *   func_02069128    0x02069128  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 w    : 8;
    u32 h    : 8;
    u32 rest : 16;
} Param;

extern void func_02068E78(void *pCC, void *charBase, int areaWidth, int areaHeight,
                          int colorMode, const void *vtable, Param param);
extern void func_02069128(u16 *pScrBase, int w, int h, int scnWidth, int charNo, int cplt);
void func_02068FF0(void *pCC, void *charBase, int areaWidth, int areaHeight, int colorMode);
void func_02069078(void *scnBase, int areaWidth, int areaHeight, int areaLeft, int areaTop, int scnWidth, int charNo, int cplt);
extern const u8 g_020A18F4[4][4][2];
extern const u8 g_020A18E8[];


static inline u32 MATH_CountLeadingZeros(u32 x)
{
    asm { clz x, x }
    return x;
}


inline static int MATH_ILog2(u32 x)
{
    return (int)(31 - MATH_CountLeadingZeros(x));
}


inline static int SizeToShift(int size)
{
    return (size >= 8) ? 3 : MATH_ILog2((u32)size);
}


/*
 * NitroSystem g2d_CharCanvas.c, the OBJ-1D canvas initialiser: derive the
 * log2 of each area dimension saturated at 3 (MATH_ILog2 over the SDK's
 * inline-asm MATH_CountLeadingZeros, which is how the image's predicated
 * clz/rsb #0x1f pairs arise), look the OBJ shift pair up in g_020A18F4
 * [shiftH][shiftW], and hand everything to the common initialiser
 * func_02068E78 with the vtable-like object g_020A18E8.
 *
 * Two readings closed it.  (1) The word the image reads uninitialised from
 * [sp, #0xc], edits in bytes 0 and 1 and stores to both [sp, #0xc] and
 * [sp, #8] is a 4-byte BITFIELD STRUCT local passed BY VALUE as the seventh
 * argument, not an eighth argument: its home is [sp, #0xc] and the by-value
 * copy is the argument slot.  (2) The pair is read through a pointer local
 * `const u8 *p = g_020A18F4[shiftH][shiftW];`; subscripting the table twice
 * leaves shiftW/shiftH in swapped registers (10 bytes).  1.1p1 compiles 132 bytes;
 * the pin is ../2.0/sp2.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02068FF0.c \
 *       --func func_02068FF0 --addr 0x02068FF0 --arm --cc ../2.0/sp2
 */
void func_02068FF0(void *pCC, void *charBase, int areaWidth, int areaHeight, int colorMode)
{
    Param param;
    const int shiftW = SizeToShift(areaWidth);
    const int shiftH = SizeToShift(areaHeight);
    const u8 *p = g_020A18F4[shiftH][shiftW];

    param.w = p[0];
    param.h = p[1];
    func_02068E78(pCC, charBase, areaWidth, areaHeight, colorMode, g_020A18E8, param);
}


/*
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
