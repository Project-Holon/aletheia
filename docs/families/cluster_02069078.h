/*
 * docs/families/cluster_02069078.h -- shared declarations for the
 * pseudo-family pkt_02069078 (0x02069078..0x020694D8 in the ARM9 image).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; match.py never sees
 * it.  Declarations are from EXACT files in src/matched (named beside them)
 * or marked NOT BYTE-ATTESTED.  Black-image addresses.
 *
 * WHAT IT IS.  NitroSystem g2d_CharCanvas.c, the BG-screen / OBJ arrangement
 * helpers that follow the canvas initialisers of cluster_02068E78.h:
 *
 *   func_02069078  NNS_G2dMapScrToCharText             EXACT (2.0 pin)
 *   func_02069128  its linear (<= 32-wide) helper      EXACT (1.1p1 = 2.0)
 *   func_02069184  OBJ count for an area (exported)    EXACT (2.0 pin)
 *   func_020691E0  NNS_G2dArrangeOBJ1D, recursive      EXACT (2.0 pin)
 *
 * STATUS (wave 11, 2026-09-23): 4 of 4 EXACT (wave 10 closed three).  Notes:
 * docs/notes/pkt_02068FF0.c.txt (2026-09-23 appendix; it corrects the
 * "triangular fill", "accumulator seed unreachable" and "clz unreachable"
 * readings above it).
 *
 * FRONT END.  ../2.0/sp2 wherever 1.1p1 differs (rows in
 * docs/FRONTEND-PINS.md): true `movlt`/`addge` select pairs (078), a
 * materialised zero `mla` addend (184), and 1E0 is size-exact only under 2.0.
 */

#ifndef CLUSTER_02069078_H
#define CLUSTER_02069078_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* THE SCREEN-ENTRY LEVER (078, 128).  The palette goes in as
 *     const u16 cpltMask = (u16)(cplt << 12);
 * (the compiler holds `cplt << 28` and ORs `lsr #16`), and the store is
 *     *p++ = (u16)(charNo++ | cpltMask);
 * with the post-increment INSIDE the expression.  Earlier `hi << 28` /
 * separate-increment readings sat at 15..41 bytes out on both functions. */
extern void func_02069128(u16 *pScrBase, int w, int h, int scnWidth,
                          int charNo, int cplt);                   /* EXACT */
extern void func_02069078(void *scnBase, int areaWidth, int areaHeight,
                          int areaLeft, int areaTop, int scnWidth,
                          int charNo, int cplt);                   /* EXACT */

/* Pure arithmetic, u32 (lsr).  Levers in its header. */
extern u32 func_02069184(u32 areaWidth, u32 areaHeight);           /* EXACT */

/* NNS_G2dArrangeOBJ1D.  EXACT (src/matched/func_020691E0.c, 2.0 pin).
 * GXOamAttr is { u32 attr01; u16 attr2; u16 attr3; } and the body uses the
 * SDK G2_SetOBJPosition / Shape / CharName / ColorMode inlines verbatim.
 * The log2 is `(v >= 8) ? 3 : MATH_ILog2((u32)v)` with the SDK's
 * inline-asm MATH_CountLeadingZeros -- the `>= 8 ? 3` arm first.
 * THE LAST 5 BYTES were DECLARATION ORDER (wave 11): declare
 * `int charPerOBJ; int numX; int numY;` uninitialised, THEN assign numX,
 * numY, charPerOBJ.  Const-initialised in assignment order the pair
 * numX/charPerOBJ swaps sb/r8; assigning charPerOBJ first fixes the
 * registers but moves the schedule.  The permuter (hill 800 + anneal 2000)
 * never tries an uninitialised declaration ahead of its assignment. */
typedef struct GXOamAttr { u32 attr01; u16 attr2; u16 attr3; } GXOamAttr;
extern int func_020691E0(GXOamAttr *oam, int areaWidth, int areaHeight,
                         int x, int y, int color, int charName, int vramShift);

/* Shared objects and callees. */
extern const u8 g_020A18F4[4][4][2];      /* [log2 h][log2 w] = {shiftW, shiftH};
                                             also func_020681E4, func_02068FF0 */
extern u32 func_020682DC(const u8 *pair); /* EXACT 1.1p1: pair -> attr01
                                             shape/size bits via 0x020A1914 */

#endif /* CLUSTER_02069078_H */
