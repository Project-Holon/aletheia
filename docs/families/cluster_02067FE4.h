/*
 * docs/families/cluster_02067FE4.h -- shared declarations for the
 * pseudo-family pkt_02067FE4 (0x02067FE4..0x020682DC in the ARM9 image).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; match.py never sees
 * it.  Every declaration is taken from an EXACT file in src/matched (named
 * beside it) or is marked NOT BYTE-ATTESTED.  Black-image addresses.
 *
 * WHAT IT IS.  NitroSystem g2d_Font.c, the font metric half, sitting just
 * above the glyph-index lookup func_02067F9C (NNS_G2dFontGetGlyphIndex,
 * EXACT 1.1p1) and just below the CharCanvas renderer of
 * docs/families/cluster_020682DC.h:
 *
 *   func_02067FE4  NNS_G2dFontGetCharWidthsFromIndex   EXACT (2.0 pin)
 *   func_02068030  NNS_G2dFontGetStringWidth           EXACT (2.0 pin)
 *   func_020680DC  NNS_G2dFontGetTextHeight            EXACT (2.0 pin)
 *   func_02068150  NNS_G2dFontGetTextRect              EXACT (2.0 pin)
 *   func_020681E4  OBJ-1D character index of a tile   DIFF 10 (2.0), note
 *                  (CharCanvas; belongs with cluster_02069078.h in spirit)
 *
 * STATUS (wave 10, 2026-09-23): 4 of 5 EXACT.  Notes:
 * docs/notes/pkt_02067FE4.c.txt (2026-09-23 appendix supersedes the DIFF
 * rows above it).
 *
 * FRONT END.  ../2.0/sp2 for every row here; rows in docs/FRONTEND-PINS.md.
 * The tells: a kept `bhi` over a four-instruction return (FE4), a stack
 * address `add rN, sp, #k` rematerialised at every call site instead of held
 * in a callee-saved register (030, 0DC), and a local store scheduled before
 * the struct-return `stm` (150).  Write NitroSystem C and pin 2.0 first.
 */

#ifndef CLUSTER_02067FE4_H
#define CLUSTER_02067FE4_H

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* The FINF block.  Every offset is pinned by a load in the files named. */
typedef struct NNSG2dCharWidths {
    s8 left;            /* +0 */
    u8 glyphWidth;      /* +1 */
    s8 charWidth;       /* +2  `ldrsb` in func_02068030 */
} NNSG2dCharWidths;

typedef struct NNSG2dFontWidth {        /* the CWDH chain, func_02067FE4 */
    u16 indexBegin;                     /* +0 */
    u16 indexEnd;                       /* +2 */
    struct NNSG2dFontWidth *pNext;      /* +4 */
    NNSG2dCharWidths widthTable[1];     /* +8, 3-byte stride (add r0,r0,r0,lsl#1) */
} NNSG2dFontWidth;

typedef struct NNSG2dFontInformation {
    u8  fontType;                   /* +0x00 */
    s8  linefeed;                   /* +0x01  `ldrsb`, 0DC and 150 */
    u16 alterCharIndex;             /* +0x02  030: fallback for index 0xFFFF */
    NNSG2dCharWidths defaultWidth;  /* +0x04  FE4's not-found return */
    u8  encoding;                   /* +0x07 */
    void *pGlyph;                   /* +0x08 */
    NNSG2dFontWidth *pWidth;        /* +0x0C  FE4 */
    void *pMap;                     /* +0x10  func_02067F9C's chain */
} NNSG2dFontInformation;

typedef struct NNSG2dFont {
    NNSG2dFontInformation *pRes;                /* +0 */
    u16 (*cbCharSpliter)(const void **ppChar);  /* +4, `blx`; 0 = end, '\n' */
} NNSG2dFont;

typedef struct NNSG2dTextRect { int width; int height; } NNSG2dTextRect;

extern u16 func_02067F9C(const NNSG2dFont *pFont, u16 c);             /* 0xFFFF = none */
extern const NNSG2dCharWidths *func_02067FE4(const NNSG2dFont *pFont, u16 idx);
extern int func_02068030(const NNSG2dFont *pFont, int hSpace, const void *str,
                         const void **pPos);
extern int func_020680DC(const NNSG2dFont *pFont, int vSpace, const void *txt);
extern NNSG2dTextRect func_02068150(const NNSG2dFont *pFont, int hSpace, int vSpace,
                                    const void *txt);

/* LEVERS THAT GENERALISE.
 *  - The spliter cursor is a LOCAL copy of the string argument; `&param`
 *    gives `push {r0-r3}` (030).  A stack argument (150's 5th) can be used
 *    directly: its home is the caller's slot.
 *  - `vSpace + linefeed`, in that operand order (0DC, 150).
 *  - 0DC carries a dead `NNSG2dTextRect rect = {0, 0}`: its two stores
 *    through `add r4, sp, #0` are in the image.
 *  - 150's line counter starts at ONE and the height uses `(n - 1)`.
 *  - Inline helpers as NitroSystem writes them (GetCharWidth = glyph index,
 *    alternate on 0xFFFF, widths->charWidth). */

/* func_020681E4 (NOT BYTE-ATTESTED, DIFF 10 after wave 11: `int sh; int sw;`
 * declared, then `sw = s.w; sh = s.h;` -- declaration order, the 020691E0
 * lever; the pair as `g_020A18F4[SizeToShift(h)][SizeToShift(w)]`; residue is
 * the image evaluating the w shift first yet adding the h row first).
 * (x, y, w, h, struct {int w;
 * int h;} shift) by value -- the shift pair is written back to the incoming
 * stack slots each round -- and the log2 via the SDK's inline-asm
 * MATH_CountLeadingZeros, which IS reachable (docs/notes/pkt_02067FE4.c.txt,
 * 2026-09-23).  Callers: func_02068AE8 / func_02068C84 (cluster_020682DC.h). */
struct ObjShift { int w; int h; };
extern int func_020681E4(int x, int y, int w, int h, struct ObjShift s);
extern const u8 g_020A18F4[4][4][2];    /* [log2 h][log2 w] = {shiftW, shiftH} */

#endif /* CLUSTER_02067FE4_H */
