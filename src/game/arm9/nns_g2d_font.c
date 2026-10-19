/*
 * file:     nns_g2d_font.c
 * unit:     yes
 * function: NNSi_G2dFontGetGlyphIndexFromCMap, NNS_G2dFontInitUTF16, NNS_G2dFontGetGlyphIndex, NNS_G2dFontGetCharWidthsFromIndex, NNS_G2dFontGetStringWidth, NNS_G2dFontGetTextHeight, NNS_G2dFontGetTextRect, NNSi_G2dCalcRectMask, NNSi_G2dGetOamShapeCode, NNSi_G2dCharCanvasFill, NNSi_G2dBlitCharData, NNSi_G2dCharCanvasDrawText, NNSi_G2dCharCanvasDrawTextForVRAM, NNSi_G2dSurfaceFill, NNSi_G2dSurfaceFillTiled, NNSi_G2dSurfaceFillRect, NNSi_G2dSurfaceFillRectSwizzled, NNSi_G2dInitPen, NNSi_G2dCharCanvasDrawChar, NNSi_G2dInitPenSimple, NNS_G2dCharCanvasInitForVRAM, NNS_G2dMapScrToCharText, NNSi_G2dFillScrCharArea, NNSi_G2dCalcCharAreaSize, NNSi_G2dMakeCharObjArea, NNSi_G2dDrawTextLine, NNSi_G2dDrawTextRotated, NNSi_G2dCalcTextBox, NNSi_G2dAlignTextVertical, NNS_G2dFontLoad, NNSi_G2dFontFixupSections, NNSi_G2dBitReaderRead, NNSi_G2dReadCharUTF16, GetTaggedPayloadSize
 * address:  0x02067EB0
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * NitroSystem g2d's MSB-first bit reader: return the next nBits bits of the
 * stream as a right-aligned value.  The reader holds the source cursor, the
 * number of bits still unread in the current byte and that byte itself.
 * When the request is wider than what is left, the leftover bits are taken,
 * the next byte is loaded (the static inline below) and the rest comes from
 * a recursive call; otherwise the byte is shifted down and the count drops.
 * Closed 2026-09-24 (wave 21, lane G) from DIFF 6
 * (docs/notes/NNSi_G2dBitReaderRead.c.txt).  PINNED ../2.0/sp2 on the schedule tell
 * already recorded for the NitroSystem g2d block (NNSi_G2dFixupOffsets /
 * NNSi_G2dCellAnimationEdgeHandler in docs/FRONTEND-PINS.md): the image sets the recursive
 * call's argument before the constant, `mov r1, r6` at 0x02069BD8 then
 * `mov r2, #8` at 0x02069BDC.  dsi/1.1p1 -O4,p emits the pair the other way
 * round on this exact source (96 bytes, 6 concrete out), as on every
 * spelling measured in waves 16 to 20; under ../2.0/sp2 (and sp1) it is 96
 * bytes, 0 out, and ../1.2/sp2 is 108 bytes.
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G2dBitReaderRead.c \
 *       --func NNSi_G2dBitReaderRead --addr 0x02069BA0 --arm --cc ../2.0/sp2
 *
 * symbols:
 *   g_020A18F4     0x020A18F4  data
 *   g_020A1914     0x020A1914  data
 *   MIi_CpuClearFast    0x02082AC0  arm
 *   g_020A18E8     0x020A18E8  data
 *   NNS_G2dFindBinaryBlock  0x02062B64  arm
 *   OS_Terminate  0x02088234  arm
 */
struct BitReader;
struct Pen;
struct NNSG2dFont;
struct Ctx;
struct NitroFileHeader;
#include "../types.h"

struct FontCMapEntry {
    u16 charCode;
    u16 glyphIndex;
};

struct FontCMap {
    u16 firstCode;          /* 0x0 */
    u16 reserved02;
    u16 type;               /* 0x4 */
    u16 reserved06;
    u8 reserved08[4];
    union {
        u16 offset;         /* 0xc */
        u16 glyphIndices[1]; /* 0xc */
        u16 count;          /* 0xc */
    };
    struct FontCMapEntry entries[]; /* 0xe */
};

struct FontCMapRange {
    u16  firstCode;    /* 0x00 */
    u16  lastCode;    /* 0x02 */
    u8   reserved04[4];
    struct FontCMapRange *next;   /* 0x08 */
};

/* NitroSystem g2d font resource (NNSG2dFontInformation, the FINF block) and
 * the runtime font handle.  Offsets pinned by this file's own loads. */
typedef struct NNSG2dCharWidths {
    s8 left;            /* +0 */
    u8 glyphWidth;      /* +1 */
    s8 charWidth;       /* +2  ldrsb */
} NNSG2dCharWidths;

typedef struct NNSG2dFontWidth {
    u16 indexBegin;                     /* +0 */
    u16 indexEnd;                       /* +2 */
    struct NNSG2dFontWidth *pNext;      /* +4 */
    NNSG2dCharWidths widthTable[1];     /* +8, 3-byte entries */
} NNSG2dFontWidth;

typedef struct NNSG2dFontGlyph {
    u8 cellWidth;
    u8 cellHeight;
    u16 cellSize;
    s8 baselinePos;
    u8 maxCharWidth;
    u8 bpp;
    u8 flags;
} NNSG2dFontGlyph;

typedef struct NNSG2dFontInformation {
    u8  fontType;                   /* +0x00 */
    s8  linefeed;                   /* +0x01  ldrsb */
    u16 alterCharIndex;             /* +0x02 */
    NNSG2dCharWidths defaultWidth;  /* +0x04 */
    u8  encoding;                   /* +0x07 */
    NNSG2dFontGlyph *pGlyph;        /* +0x08 */
    NNSG2dFontWidth *pWidth;        /* +0x0C */
    void *pMap;                     /* +0x10 */
} NNSG2dFontInformation;

typedef struct NNSG2dFont {
    NNSG2dFontInformation *pRes;                /* +0 */
    u16 (*cbCharSpliter)(const void **ppChar);  /* +4, called through blx */
} NNSG2dFont;

typedef struct NNSG2dTextRect { int width; int height; } NNSG2dTextRect;

typedef struct LC_INFO {
    const u8 *dst;
    const u8 *src;
    int ofs_x;
    int ofs_y;
    int width;
    int height;
    int dsrc;
    int srcBpp;
    int dstBpp;
    u32 cl;
} LC_INFO;

typedef struct NNSiG2dBitReader {
    const u8 *src;
    s8 availableBits;
    u8 bits;
    u8 reserved[2];
} NNSiG2dBitReader;

typedef union OBJ1DParam {
    u32 packed;
    struct {
        unsigned baseWidthShift :8;
        unsigned baseHeightShift :8;
    };
} OBJ1DParam;

typedef struct NNSG2dGlyph {
    const NNSG2dCharWidths *pWidths;
    const u8 *image;
} NNSG2dGlyph;

typedef struct NNSG2dCharCanvas {
    u8 *charBase;
    int areaWidth;
    int areaHeight;
    u8 dstBpp;
    u8 reserved[3];
    u32 param;
    const void *vtable;
} NNSG2dCharCanvas;

struct Surface {
    char *base;   /* +0x00 */
    int   w;      /* +0x04 */
    int   h;      /* +0x08 */
    u8    bpp;    /* +0x0C  4 or 8 */
    int   stride; /* +0x10 */
};

struct SurfaceTiled {
    char *base;        /* +0x00 */
    int   w;           /* +0x04 */
    int   h;           /* +0x08 */
    u8    bpp;         /* +0x0C */
    int   strideTiles; /* +0x10 characters per row, in tiles */
};

struct SurfaceSwzBase { u32 x : 8; u32 y : 8; u32 rest : 16; };

struct SurfaceSwizzled {
    char *base;                /* +0x00 */
    int   w;                   /* +0x04 */
    int   h;                   /* +0x08 */
    u8    bpp;                 /* +0x0C */
    struct SurfaceSwzBase swz; /* +0x10 base tile coordinate */
};

struct Pen {
    void *charBase;     /* +0x00 */
    int  areaWidth;     /* +0x04 */
    int  areaHeight;    /* +0x08 */
    u8   dstBpp;        /* +0x0C */
    u8   reserved0d[3];
    int  param;         /* +0x10 */
    const void *vtable; /* +0x14 */
};

struct Ctx { u8 reserved[0x14]; void **vt; };

typedef union {
    u32 raw;
    struct {
        u32 w    : 8;
        u32 h    : 8;
        u32 rest : 16;
    };
} Param;

#include "../sdk_gx.h"

typedef struct {
    signed char dx;
    signed char dy;
} Step;

typedef u16 (*NextFn)(const void **cursor);

typedef struct {
    u8 b00;
    signed char b01;
} Hdr;

typedef struct {
    struct Ctx *pCanvas;
    NNSG2dFont *pFont;
    s32 hSpace;
    s32 vSpace;
} Ctx;

typedef NNSG2dTextRect Ext;

typedef struct {
    u32 signature;   /* +0x00 'NFTR' */
    u16 byteOrder;   /* +0x04 0xFEFF */
    u16 version;     /* +0x06 */
    u32 fileSize;    /* +0x08 */
    u16 headerSize;  /* +0x0C byte offset of the first block header */
    u16 numBlocks;   /* +0x0E block count */
} Res;

typedef struct {
    u32 signature;   /* +0x00 block FourCC */
    u32 size;        /* +0x04 block byte size, the stride to the next block */
    u32 reserved08;  /* +0x08 block content start, never relocated here */
    u32 pNextWidth;  /* +0x0C CWDH: next width block */
    u32 pGlyph;      /* +0x10 FINF: glyph block; the CMAP next pointer shares the slot */
    u32 pWidth;      /* +0x14 FINF: width block */
    u32 pMap;        /* +0x18 FINF: map block */
} Section;

struct BitReader {
    const u8 *src;
    s8        avail;
    u8        bits;
    u8        reserved06[2];
};

typedef struct CharCursor {
    u8 *pCur;
    signed char reserved04;
    unsigned char reserved05;
} CharCursor;

typedef struct TaggedNode {
    u8 reserved00[0x17];
    u8 entryCount;
    u8 entryCountM;
} TaggedNode;

extern void MIi_CpuClearFast(u32 data, void *dst, int size);
struct NNSG2dBinaryFileHeader;
extern void *NNS_G2dFindBinaryBlock(struct NNSG2dBinaryFileHeader *pHeader, u32 signature);
extern void OS_Terminate(void);
u16 NNSi_G2dFontGetGlyphIndexFromCMap(struct FontCMap *tbl, u16 charCode);
void NNS_G2dFontInitUTF16(NNSG2dFont *pFont, void *pResource);
u16 NNS_G2dFontGetGlyphIndex(const NNSG2dFont *pFont, u16 charCode);
const NNSG2dCharWidths *NNS_G2dFontGetCharWidthsFromIndex(const NNSG2dFont *pFont, u32 idx);
int NNS_G2dFontGetStringWidth(const NNSG2dFont *pFont, int hSpace, const void *txt, const void **pPos);
int NNS_G2dFontGetTextHeight(const NNSG2dFont *pFont, int vSpace, const void *txt);
NNSG2dTextRect NNS_G2dFontGetTextRect(const NNSG2dFont *pFont, int hSpace, int vSpace, const void *txt);
int NNSi_G2dCalcRectMask(int x, int y, int w, int h, int sw0, int sh0);
u32 NNSi_G2dGetOamShapeCode(const u8 *p);
void NNSi_G2dCharCanvasFill(u32 *dst, int x, int y, int w, int h, u32 val, int bpp);
void NNSi_G2dBlitCharData(LC_INFO *i);
void NNSi_G2dCharCanvasDrawText(const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph);
void NNSi_G2dCharCanvasDrawTextForVRAM(const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph);
void NNSi_G2dSurfaceFill(struct Surface *s, u32 arg);
void NNSi_G2dSurfaceFillTiled(struct Surface *s, u32 arg);
void NNSi_G2dSurfaceFillRect(struct SurfaceTiled *s, u32 arg, int x, int y, int w, int h);
void NNSi_G2dSurfaceFillRectSwizzled(struct SurfaceSwizzled *s, u32 arg, int x, int y, int w, int h);
void NNSi_G2dInitPen(struct Pen *p, void *charBase, int areaWidth, int areaHeight, int dstBpp, const void *vtable, int param);
s8 NNSi_G2dCharCanvasDrawChar(struct Ctx *ctx, NNSG2dFont *font, int x, int y, int cl, u16 code);
void NNSi_G2dInitPenSimple(int pen, int charBase, int areaWidth, int areaHeight, int dstBpp);
void NNS_G2dCharCanvasInitForVRAM(void *pCC, void *charBase, int areaWidth, int areaHeight, int colorMode);
void NNS_G2dMapScrToCharText(void *scnBase, int areaWidth, int areaHeight, int areaLeft, int areaTop, int scnWidth, int charNo, int cplt);
void NNSi_G2dFillScrCharArea(u16 *pScrBase, int w, int h, int scnWidth, int charNo, int cplt);
u32 NNSi_G2dCalcCharAreaSize(u32 areaWidth, u32 areaHeight);
int NNSi_G2dMakeCharObjArea(GXOamAttr *oam, int areaWidth, int areaHeight, int x, int y, int color, int charName, int vramShift);
void NNSi_G2dDrawTextLine(Ctx *ctx, s32 x, s32 y, s32 w2, const void *s, const void **last, Step st);
void NNSi_G2dDrawTextRotated(Ctx *ctx, s32 x, s32 y, s32 w, s32 w2, u32 flags, const void *s, Step st);
void NNSi_G2dCalcTextBox(Ctx *ctx, s32 x, s32 y, s32 w, u32 flags, u32 s, Step st);
void NNSi_G2dAlignTextVertical(Ctx *ctx, s32 x, s32 y, s32 w, u32 h, u32 w2, u32 flags, u32 s, Step st);
u32 NNS_G2dFontLoad(Res *res, void **out);
void NNSi_G2dFontFixupSections(Res *base);
u32 NNSi_G2dBitReaderRead(struct BitReader *reader, int nBits);
u16 NNSi_G2dReadCharUTF16(CharCursor *cursor);
u32 GetTaggedPayloadSize(const u8 *tag, const TaggedNode *node);
extern const u8 g_020A18F4[4][4][2];
extern u32 g_020A1914[][4];
extern const u8 g_020A18E8[];

u16 NNSi_G2dFontGetGlyphIndexFromCMap(struct FontCMap *tbl, u16 charCode)
{
    u16 ret = 0xFFFF;
    u16 type = tbl->type;

    switch (type) {
    case 0:
        {
            u32 diff = charCode - tbl->firstCode;
            ret = (u16)(tbl->offset + diff);
        }
        break;
    case 1:
        ret = *(u16 *)((u8 *)tbl + 0xc + (charCode - tbl->firstCode) * 2);
        break;
    case 2:
        {
            struct FontCMapEntry *low = (struct FontCMapEntry *)((u8 *)tbl + 0xe);
            struct FontCMapEntry *high = low + (tbl->count - 1);

            while (low <= high) {
                struct FontCMapEntry *mid = low + (high - low) / 2;

                if (mid->charCode < charCode) {
                    low = mid + 1;
                } else if (charCode < mid->charCode) {
                    high = mid - 1;
                } else {
                    ret = mid->glyphIndex;
                    break;
                }
            }
        }
        break;
    }

    return ret;
}

/*
 * Blocking class: label.  Every concrete byte is right; both relocation sites are
 * unresolved and both for the same reason: the `bl NNS_G2dFontLoad` at 0x02067F88 is
 * the only branch to 0x020698F8 in the image, and the pool word that stores
 * 0x02069C00 as a value (+0x20) is the only reference to that address anywhere, so
 * neither `label` nor `literal` has a witness outside this file's 32 bytes.
 */
void NNS_G2dFontInitUTF16(NNSG2dFont *pFont, void *pResource)
{
    NNS_G2dFontLoad((Res *)pResource, (void **)pFont);
    pFont->cbCharSpliter = (u16 (*)(const void **))NNSi_G2dReadCharUTF16;
}

/*
 * Range lookup over a singly linked list of key records: walk the chain hung
 * off (*a0)->pRes->pMap and hand the first record whose [lo, hi] halfword pair
 * contains `key` to NNSi_G2dFontGetGlyphIndexFromCMap, which returns the mapped word.  No record
 * holds the key: return the pooled 0xFFFF sentinel.  The record's link is at
 * +0x04 (used by the twin at 0x02067FE4) while the chain head here is the
 * +0x10 field of the object the caller's pointer points at.
 *
 * The half-open test is ONE conjunction (`key >= lo && key <= hi`): the
 * original's `ldrhls`/`cmpls` pair is the second comparison issued
 * conditionally on the first, which is a `&&`, not two nested guards.
 */
u16 NNS_G2dFontGetGlyphIndex(const NNSG2dFont *pFont, u16 charCode)
{
    struct FontCMapRange *range = (struct FontCMapRange *)pFont->pRes->pMap;

    while (range != 0) {
        if (range->firstCode <= charCode && charCode <= range->lastCode) {
            return NNSi_G2dFontGetGlyphIndexFromCMap((struct FontCMap *)range, charCode);
        }
        range = range->next;
    }

    return 0xffff;
}

/*
 * NNS_G2dFontGetCharWidthsFromIndex (NitroSystem g2d_Font.c): walk the
 * font's width-block chain (FINF +0x0C) and return the 3-byte width entry of
 * the block whose [indexBegin, indexEnd] holds idx, else &FINF->defaultWidth.
 *
 * COMPILER PIN ../2.0/sp2, "kept branches" (docs/FRONTEND-PINS.md): the image
 * keeps `bhi 0x0206801C` at 0x02068004 over the unpredicated four-instruction
 * return (sub/add/add/add + bx lr at 0x02068008..0x02068018); dsi/1.1p1
 * predicates it (subls/addls/addls/addls/bxls) and is 72 bytes against 76.
 * The same C is 76 bytes, 0 mismatches under the pin.
 */
const NNSG2dCharWidths *NNS_G2dFontGetCharWidthsFromIndex(const NNSG2dFont *pFont, u32 idx)
{
    const NNSG2dFontWidth *pWidth = pFont->pRes->pWidth;

    while (pWidth != 0) {
        if (pWidth->indexBegin <= idx && idx <= pWidth->indexEnd)
            return &pWidth->widthTable[idx - pWidth->indexBegin];
        pWidth = pWidth->pNext;
    }
    return &pFont->pRes->defaultWidth;
}

static inline int GetCharWidth(const NNSG2dFont *pFont, u16 c)
{
    u16 index = NNS_G2dFontGetGlyphIndex(pFont, c);
    if (index == 0xFFFF)
        index = pFont->pRes->alterCharIndex;
    return NNS_G2dFontGetCharWidthsFromIndex(pFont, index)->charWidth;
}

/*
 * NNS_G2dFontGetStringWidth (NitroSystem g2d_Font.c): width of one line of
 * text, stopping at NUL or '\n'; the spliter callback advances a cursor held
 * in a stack slot.  *pPos gets the cursor after a newline, NULL at end of
 * string, and one trailing hSpace is removed.  NNS_G2dFontGetGlyphIndex is
 * NNS_G2dFontGetGlyphIndex (0xFFFF = not found -> alterCharIndex),
 * NNS_G2dFontGetCharWidthsFromIndex NNS_G2dFontGetCharWidthsFromIndex.
 *
 * The cursor is a LOCAL COPY of the string argument (`str = txt`): taking
 * the address of the parameter itself spills all four argument registers
 * (`push {r0, r1, r2, r3}`), which the image does not have.
 *
 * COMPILER PIN ../2.0/sp2, "kept constants" (docs/FRONTEND-PINS.md): the
 * image rematerialises the cursor address, `add r0, sp, #0` at 0x02068044
 * and again `add sl, sp, #0` at 0x02068064; dsi/1.1p1 CSEs it into r4
 * (`add r4, sp, #0` / `mov r0, r4`), which permutes every callee-saved
 * register, 47 concrete bytes out at 172.  0 mismatches under the pin.
 */
int NNS_G2dFontGetStringWidth(const NNSG2dFont *pFont, int hSpace, const void *txt, const void **pPos)
{
    const void *str = txt;
    int width = 0;
    u16 (*getNextChar)(const void **);
    u16 c;

    getNextChar = pFont->cbCharSpliter;

    while ((c = getNextChar(&str)) != 0) {
        if (c == '\n')
            break;
        width += GetCharWidth(pFont, c) + hSpace;
    }
    if (pPos != 0)
        *pPos = (c == '\n') ? str : 0;
    if (width > 0)
        width -= hSpace;
    return width;
}

/*
 * NNS_G2dFontGetTextHeight (NitroSystem g2d_Font.c): count lines (1 plus one
 * per '\n') and return lines * (vSpace + linefeed) - vSpace.  FINF +0x01
 * linefeed is s8 (`ldrsb`).
 *
 * The two dead zero stores at [sp]/[sp+4] through `add r4, sp, #0` are an
 * unused `NNSG2dTextRect rect = {0, 0}`, the same aggregate initialiser
 * NNS_G2dFontGetTextRect uses live.  `vSpace + linefeed` in that operand order
 * (`add r0, r4, r0`); the other order is 2 bytes out.
 *
 * COMPILER PIN ../2.0/sp2, "kept constants" (docs/FRONTEND-PINS.md): the
 * image rematerialises the cursor address, `add r0, sp, #8` at 0x02068100
 * and `add r5, sp, #8` at 0x02068118; dsi/1.1p1 hoists one `add r5, sp, #8`
 * and schedules the prologue differently, 49 concrete bytes out at 116.
 * 0 mismatches under the pin.  Supersedes src/pending/NNS_G2dFontGetTextHeight.c
 * (DIFF 5, a different reading).
 */
int NNS_G2dFontGetTextHeight(const NNSG2dFont *pFont, int vSpace, const void *txt)
{
    const void *pos = txt;
    NNSG2dTextRect rect = { 0, 0 };
    int lines = 1;
    u16 (*getNextChar)(const void **);
    u16 c;

    getNextChar = pFont->cbCharSpliter;
    while ((c = getNextChar(&pos)) != 0) {
        if (c == '\n')
            lines++;
    }
    return lines * (vSpace + pFont->pRes->linefeed) - vSpace;
}

/*
 * NNS_G2dFontGetTextRect (NitroSystem g2d_Font.c), struct return through the
 * hidden r0 pointer: widest line via NNS_G2dFontGetStringWidth (threading its pPos back
 * in as the next line), height = (lines - 1) * (vSpace + linefeed) - vSpace
 * with the counter starting at ONE (`mov r4, #1` / `sub r2, r4, #1`); a
 * counter from zero is 140 bytes against 148.
 *
 * COMPILER PIN ../2.0/sp2 (docs/FRONTEND-PINS.md): the same C under
 * dsi/1.1p1 is 148 bytes with exactly 8 out, the two stores at the tail
 * swapped: the image writes the height into the local first, `str r1,
 * [sp, #4]` at 0x020681D4, then `stm r8, {r0, r1}` at 0x020681D8; 1.1p1
 * issues the stm first.  0 mismatches under the pin.
 */
NNSG2dTextRect NNS_G2dFontGetTextRect(const NNSG2dFont *pFont, int hSpace, int vSpace, const void *txt)
{
    NNSG2dTextRect rect = { 0, 0 };
    int numLine = 1;

    while (txt != 0) {
        const int width = NNS_G2dFontGetStringWidth(pFont, hSpace, txt, &txt);
        if (width > rect.width)
            rect.width = width;
        numLine++;
    }
    rect.height = (numLine - 1) * (vSpace + pFont->pRes->linefeed) - vSpace;
    return rect;
}

/*
 * NitroSystem g2d_CharCanvas.c GetCharIndex1D(cx, cy, areaWidth,
 * areaHeight, objWidth, objHeight): the character index of (x, y) inside
 * an OBJ-1D canvas tiled greedily with the largest OBJ that fits.  The last
 * two arguments are the current OBJ width/height shifts, rewritten each
 * round from GetMaxObjectSize's table g_020A18F4[log_h][log_w] (u8 pairs
 * widthShift, heightShift), with each log saturated at 3 and taken with an
 * in-place clz (MATH_ILog2 over MATH_CountLeadingZeros' `asm { clz x, x }`).
 *
 * Closed in wave 19 after 18 -> 10 in wave 11: the w log is computed IN
 * PLACE in the dying h-shift local `sh`, not in a fresh local.  With a named
 * log_w the two logs take each other's registers (18 out, in every
 * declaration order and with int, u32 or long logs); reusing sh puts log_w
 * in r6 with sh and log_h in r7, where the row pointer coalesces with the
 * next objWidth, as the image does.  1.1p1 is 240 bytes on this shape.
 */
int NNSi_G2dCalcRectMask(int x, int y, int w, int h, int sw0, int sh0)
{
  int base = 0;
  int sh;
  int sw;
  int wMask;
  int alignedX;
  sw = sw0;
  sh = sh0;
  for (;;)
  {
    u32 ww;
    u32 hh;
    wMask = 0xFFFFFFFFu << sw;
    ww = ((u32) w) & wMask;
    hh = ((u32) h) & (0xFFFFFFFFu << sh);
    if (hh <= ((u32) y))
    {
      base += w * hh;
      if (ww <= ((u32) x))
      {
        h -= hh;
        base += ww * h;
        x -= ww;
        y -= hh;
        w -= ww;
      }
      else
      {
        w = ww;
        y -= hh;
        h -= hh;
      }
    }
    else
    {
      const u32 hinv = ~(0xFFFFFFFFu << sh);
      if (ww <= ((u32) x))
      {
        base += ww * hh;
        h = hh;
        x -= ww;
        w -= ww;
      }
      else
      {
        const u32 winv = ~(0xFFFFFFFFu << sw);
        base += ww * (y & (0xFFFFFFFFu << sh));
        alignedX = x & (0xFFFFFFFFu << sw);
        base += alignedX << sh;
        base += (y & hinv) << sw;
        return base + (x & winv);
      }
    }
    {
      int lh;
      const u8 *p;
      if (w >= 8) sh = 3; else { sh = w; asm { clz sh, sh } sh = 31 - sh; }
      if (h >= 8) lh = 3; else { lh = h; asm { clz lh, lh } lh = 31 - lh; }
      p = g_020A18F4[lh][sh];
      sw = (sw0 = p[0]);
      sh = (sh0 = p[1]);
    }
  }
}

/*
 *           in the image is this function's own literal at 0x020682F4, so the
 *           `literal`/`data_table` classes both refuse; written as an integer
 *           constant the pool word needs no witness but the front end then
 *           synthesises the address with two `add`s and loses the whole body.
 *
 * A 2-D table of four-word rows indexed by the byte at +1 then the byte at +0,
 * which is what makes the first index a `lsl #4` on the base and the second a
 * `lsl #2` inside the load's addressing mode.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NNSi_G2dGetOamShapeCode.c \
 *       --func NNSi_G2dGetOamShapeCode --addr 0x020682DC --cc 1.1p1 --arm
 */
u32 NNSi_G2dGetOamShapeCode(const u8 *p)
{
    return g_020A1914[p[1]][p[0]];
}

/*
 * Fill a sub-rectangle of ONE 8x8 tile with a pixel word.  dst is the tile,
 * (x, y) the sub-rectangle's offset inside it, (w, h) its extent, val the
 * expanded pixel word (NNSi_G2dSurfaceFill's expansion) and bpp 4 or 8.  A whole
 * tile goes to MIi_CpuClearFast (MIi_CpuClearFast) in one call; otherwise each
 * of the h rows is masked in place, one word per row at 4bpp and two at
 * 8bpp, where the 64-bit row mask is built longhand from two 32-bit halves
 * with the >= 32 shift cases spelled out.  Called seven-argument from
 * NNSi_G2dSurfaceFillRect and NNSi_G2dSurfaceFillRectSwizzled.
 *
 * COMPILER PIN ../2.0/sp2, "kept branches" (docs/FRONTEND-PINS.md): the image
 * keeps `blo` over both four-instruction >= 32 blocks (0x020683A4,
 * 0x020683C8); 1.1p1 predicates them and is 304 bytes against 312.
 *
 * Levers, after the note docs/notes/pkt_020682F8.c.txt had the push one
 * register too wide under the pin (63 bytes out):
 *   - u and the 64 - (u + w*8) remainder are UNSIGNED (`blo`, not `blt`);
 *   - in the 8bpp arm the remainder is NOT held in a local across the arm:
 *     it is named once for the first test (`r`) and written out again at
 *     each later use.  Holding it live is what cost the third callee-saved
 *     register (found by tools/permuter.py, expand(v));
 *   - the 4bpp mask is built in two statements (m = ~0 >> u; m <<= ...);
 *   - declaration order `set` before `end` (4bpp) and `slo, shi, p, end`
 *     (8bpp) picks the image's registers for the fill values and the bound.
 */
void NNSi_G2dCharCanvasFill(u32 *dst, int x, int y, int w, int h, u32 val, int bpp)
{
    if (w == 8 && h == 8) {
        MIi_CpuClearFast(val, dst, bpp << 3);
        return;
    }
    if (bpp == 4) {
        int u = x << 2;
        int v = 0x20 - (u + (w << 2));
        u32 m = 0xFFFFFFFF >> u;
        u32 *p;
        u32 set;
        u32 *end;

        m = m << (v + (x << 2));
        p = dst + y;
        end = p + h;
        set = val & (m >> v);
        m = ~(m >> v);
        while (p < end) {
            *p = set | (*p & m);
            p++;
        }
    } else {
        u32 u = x << 3;
        u32 lo = 0xFFFFFFFF >> u;
        u32 hi;
        u32 slo;
        u32 shi;
        u32 *p;
        u32 *end;
        u32 e;
        u32 r;

        r = 0x40 - (u + (w << 3));
        if (r < 0x20) {
            lo = lo << u;
        } else {
            e = r - 0x20;
            lo = (lo << (u + e)) >> e;
        }
        hi = 0xFFFFFFFF << (0x40 - (u + (w << 3)));
        if (u < 0x20) {
            hi = hi >> (0x40 - (u + (w << 3)));
        } else {
            e = u - 0x20;
            hi = (hi >> (e + (0x40 - (u + (w << 3))))) << e;
        }
        p = dst + y * 2;
        end = p + h * 2;
        slo = val & lo;
        shi = val & hi;
        lo = ~lo;
        hi = ~hi;
        while (p < end) {
            p[0] = slo | (p[0] & lo);
            p[1] = shi | (p[1] & hi);
            p += 2;
        }
    }
}

static inline int MATH_IMax(int a, int b)
{
    return (a >= b) ? a : b;
}

static inline int MATH_IMin(int a, int b)
{
    return (a <= b) ? a : b;
}

static inline void NNSi_G2dBitReaderInit(NNSiG2dBitReader *reader, const void *src)
{
    reader->availableBits = 0;
    reader->src = (const u8 *)src;
    reader->bits = 0;
}

/*
 * NitroSystem g2d_CharCanvas.c LetterChar(LC_INFO *): blit one glyph's
 * bit-packed pixels into one 8x8 character, clipped to the character, at 4
 * or 8 bits per destination pixel, adding the colour base cl to every
 * non-zero source value.  Each row opens an NNSiG2dBitReader at
 * src + offset / 8 and discards offset % 8 bits first
 * (NNSi_G2dBitReaderRead = NNSi_G2dBitReaderRead).  The LC_INFO block is the
 * ten-word "Blit" struct of docs/families/cluster_020682DC.h.
 *
 * Closed in wave 13 on the first compile of the library body with the
 * TwlSDK MATH_IMax / MATH_IMin inlines and NNSi_G2dBitReaderInit; the
 * wave-11 transcription sat at 119 out.  ../2.0/sp2 and sp2p2 identical;
 * 1.1p1 is 564 bytes.
 */
void NNSi_G2dBlitCharData(LC_INFO *i)
{
    const u8 *pSrc;
    u32 x_st;
    u32 x_ed;
    u32 y_st;
    u32 y_ed;
    u32 offset;

    {
        u32 bit_y_begin;

        x_st = (unsigned int)MATH_IMax(i->ofs_x, 0);
        y_st = (unsigned int)MATH_IMax(i->ofs_y, 0);
        x_ed = (unsigned int)MATH_IMin(8, i->ofs_x + i->width);
        y_ed = (unsigned int)MATH_IMin(8, i->ofs_y + i->height);

        bit_y_begin = (unsigned int)-MATH_IMin(i->ofs_y, 0);
        offset = -MATH_IMin(i->ofs_x, 0) * i->srcBpp + bit_y_begin * i->dsrc;

        pSrc = i->src;
    }

    {
        u32 x;
        const int dsrc = i->dsrc;
        const int srcBpp = i->srcBpp;
        const int dstBpp = i->dstBpp;

        x_st *= dstBpp;
        x_ed *= dstBpp;

        if ( dstBpp == 4 ) {
            u32 *pDst = (u32 *)i->dst + y_st;
            u32 *pDstEnd = (u32 *)i->dst + y_ed;
            u32 cl = i->cl;

            for ( ; pDst < pDstEnd; pDst++) {
                NNSiG2dBitReader reader;
                u32 out_line = *pDst;

                NNSi_G2dBitReaderInit(&reader, pSrc + offset / 8);
                (void)NNSi_G2dBitReaderRead((struct BitReader *)(&reader), (int)offset % 8);

                for (x = x_st; x < x_ed; x += 4) {
                    u32 bits = NNSi_G2dBitReaderRead((struct BitReader *)(&reader), srcBpp);

                    if ( bits != 0 ) {
                        out_line = (out_line & ~(0xF << x)) | ((cl + bits) << x);
                    }
                }

                *pDst = out_line;

                offset += dsrc;
            }
        } else {
            u32 *pDst = (u32 *)((u64 *)i->dst + y_st);
            u32 * const pDstEnd = (u32 *)((u64 *)i->dst + y_ed);
            u32 cl = i->cl;

            for ( ; pDst < pDstEnd; pDst += 2) {
                NNSiG2dBitReader reader;
                u32 out_line_0 = *pDst;
                u32 out_line_1 = *(pDst + 1);

                NNSi_G2dBitReaderInit(&reader, pSrc + offset / 8);
                (void)NNSi_G2dBitReaderRead((struct BitReader *)(&reader), (int)offset % 8);

                for (x = x_st; x < x_ed; x += 8) {
                    u32 bits = NNSi_G2dBitReaderRead((struct BitReader *)(&reader), srcBpp);

                    if ( bits != 0 ) {
                        if ( x < 32 ) {
                            out_line_0 = (out_line_0 & ~((u32)0xFF << x)) | ((u32)(cl + bits) << x);
                        } else {
                            const u32 x_32 = x - 32;
                            out_line_1 = (out_line_1 & ~((u32)0xFF << x_32)) | ((u32)(cl + bits) << x_32);
                        }
                    }
                }

                *pDst = out_line_0;
                *(pDst + 1) = out_line_1;

                offset += dsrc;
            }
        }
    }
}

static inline int GetCharacterSize(const NNSG2dCharCanvas *pCC)
{
    return 8 * 8 * pCC->dstBpp / 8;
}

static inline u8 NNS_G2dFontGetCellHeight(const NNSG2dFont *pFont)
{
    return pFont->pRes->pGlyph->cellHeight;
}

static inline u8 NNS_G2dFontGetCellWidth(const NNSG2dFont *pFont)
{
    return pFont->pRes->pGlyph->cellWidth;
}

static inline u8 NNS_G2dFontGetBpp(const NNSG2dFont *pFont)
{
    return pFont->pRes->pGlyph->bpp;
}

/*
 * NitroSystem g2d_CharCanvas.c DrawGlyphLine(pCC, pFont, x, y, cl, pGlyph):
 * the BG / OBJ-2D-rect glyph draw.  Clip the glyph to the canvas in whole
 * 8x8 characters, then walk the covered characters row by row on the
 * canvas's linear character grid (pCC->param = characters per row),
 * handing each to LetterChar (NNSi_G2dBlitCharData) with an LC_INFO on the stack.
 * pCC is NNSG2dCharCanvas { charBase, areaWidth, areaHeight, u8 dstBpp,
 * param, vtable } (the "Surface" of docs/families/cluster_020682DC.h);
 * cell width / height / bpp come from pFont->pRes->pGlyph (FGLP).
 *
 * Closed in wave 13 on the first compile of the library body with its
 * inlines (GetCharacterSize, NNS_G2dFontGetCellHeight / CellWidth / Bpp);
 * the wave-11 transcription sat at 238 out on a spill choice.  ../2.0/sp2
 * and sp2p2 identical; 1.1p1 is 404 bytes.
 */
void NNSi_G2dCharCanvasDrawText(const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph)
{
    int ofs_x_base;
    int ofs_x;
    int ofs_y;
    int ofs_x_end;
    int ofs_y_end;
    unsigned int nextLineOffset;
    u8 * pChar;
    u8 glyphWidth;
    u8 charHeight;
    int charSize;

    charSize = GetCharacterSize(pCC);

    {
        int chara_x_num;
        int chara_y_num;
        const unsigned int areaWidth = (unsigned int)pCC->areaWidth;
        const unsigned int areaHeight = (unsigned int)pCC->areaHeight;
        u8 * const charBase = pCC->charBase;
        const NNSG2dCharWidths * const pWidth = pGlyph->pWidths;

        unsigned int chara_x_begin;
        unsigned int chara_x_last;
        unsigned int chara_y_begin;
        unsigned int chara_y_last;

        glyphWidth = pWidth->glyphWidth;
        charHeight = NNS_G2dFontGetCellHeight(pFont);

        if ( glyphWidth <= 0 ) {
            return;
        }

        if ((x + glyphWidth < 0) || (y + charHeight) < 0 ) {
            return;
        }

        chara_x_begin = (x <= 0) ? 0: ((u32)x / 8);
        chara_y_begin = (y <= 0) ? 0: ((u32)y / 8);

        chara_x_last = (u32)(x + glyphWidth + (8 - 1)) / 8;
        if ( chara_x_last >= areaWidth ) {
            chara_x_last = areaWidth;
        }
        chara_y_last = (u32)(y + charHeight + (8 - 1)) / 8;
        if ( chara_y_last >= areaHeight ) {
            chara_y_last = areaHeight;
        }

        chara_x_num = (int)(chara_x_last - chara_x_begin);
        chara_y_num = (int)(chara_y_last - chara_y_begin);

        if ((chara_x_num < 0) || (chara_y_num < 0)) {
            return;
        }

        pChar = charBase + (pCC->param * chara_y_begin + chara_x_begin) * charSize;

        nextLineOffset = (pCC->param - chara_x_num) * charSize;

        ofs_x_base = (x < 0) ? x: x & 0x7;
        ofs_y = (y < 0) ? y: y & 0x7;
        ofs_x_end = ofs_x_base - 8 * chara_x_num;
        ofs_y_end = ofs_y - 8 * chara_y_num;
    }

    {
        LC_INFO i;

        i.src = pGlyph->image;
        i.width = glyphWidth;
        i.height = charHeight;
        i.cl = (u32)(cl - 1);
        i.srcBpp = NNS_G2dFontGetBpp(pFont);
        i.dstBpp = pCC->dstBpp;
        i.dsrc = NNS_G2dFontGetCellWidth(pFont) * i.srcBpp;

        for ( ; ofs_y > ofs_y_end; ofs_y -= 8) {
            i.ofs_y = ofs_y;
            for (ofs_x = ofs_x_base; ofs_x > ofs_x_end; ofs_x -= 8) {
                i.dst = pChar;
                i.ofs_x = ofs_x;
                NNSi_G2dBlitCharData(&i);
                pChar += charSize;
            }
            pChar += nextLineOffset;
        }
    }
}

/*
 * NitroSystem g2d_CharCanvas.c DrawGlyph1D(pCC, pFont, x, y, cl, pGlyph):
 * the OBJ-1D glyph draw.  Same clip as DrawGlyphLine (NNSi_G2dCharCanvasDrawText), but
 * each covered character's slot comes from GetCharIndex1D (NNSi_G2dCalcRectMask)
 * with the two OBJ size shifts packed in the low bytes of pCC->param (the
 * OBJ1DParam union { packed; baseWidthShift:8; baseHeightShift:8 }), and
 * each character is drawn by LetterChar (NNSi_G2dBlitCharData).
 *
 * Closed in wave 13 on the first compile of the library body; the wave-11
 * transcription sat at 168 out.  ../2.0/sp2 and sp2p2 identical; 1.1p1 is
 * 520 bytes.
 */
void NNSi_G2dCharCanvasDrawTextForVRAM(const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph)
{
    int ofs_x_base;
    int ofs_x;
    int ofs_y;
    int ofs_x_end;
    int ofs_y_end;
    int cx, cx_base;
    int cy;
    u8 glyphWidth;
    u8 charHeight;
    int charSize;
    u16 * mapTable;

    charSize = GetCharacterSize(pCC);
    mapTable = (u16 *)(pCC->param);

    {
        int chara_x_num;
        int chara_y_num;
        const unsigned int areaWidth = (unsigned int)pCC->areaWidth;
        const unsigned int areaHeight = (unsigned int)pCC->areaHeight;
        const NNSG2dCharWidths * const pWidth = pGlyph->pWidths;

        u32 chara_x_begin;
        u32 chara_x_last;
        u32 chara_y_begin;
        u32 chara_y_last;

        glyphWidth = pWidth->glyphWidth;
        charHeight = NNS_G2dFontGetCellHeight(pFont);

        if ( glyphWidth <= 0 ) {
            return;
        }

        if ((x + glyphWidth < 0) || (y + charHeight) < 0 ) {
            return;
        }

        chara_x_begin = (x <= 0) ? 0: ((u32)x / 8);
        chara_y_begin = (y <= 0) ? 0: ((u32)y / 8);

        chara_x_last = (u32)(x + glyphWidth + (8 - 1)) / 8;
        if ( chara_x_last >= areaWidth ) {
            chara_x_last = areaWidth;
        }
        chara_y_last = (u32)(y + charHeight + (8 - 1)) / 8;
        if ( chara_y_last >= areaHeight ) {
            chara_y_last = areaHeight;
        }

        chara_x_num = (int)(chara_x_last - chara_x_begin);
        chara_y_num = (int)(chara_y_last - chara_y_begin);

        if ((chara_x_num < 0) || (chara_y_num < 0)) {
            return;
        }

        cx_base = (int)chara_x_begin;
        cy = (int)chara_y_begin;

        ofs_x_base = (x < 0) ? x: x & 0x7;
        ofs_y = (y < 0) ? y: y & 0x7;
        ofs_x_end = ofs_x_base - 8 * chara_x_num;
        ofs_y_end = ofs_y - 8 * chara_y_num;
    }

    {
        LC_INFO i;
        u8 * const pCharBase = pCC->charBase;
        OBJ1DParam p;

        i.src = pGlyph->image;
        i.width = glyphWidth;
        i.height = charHeight;
        i.cl = (u32)(cl - 1);
        i.srcBpp = NNS_G2dFontGetBpp(pFont);
        i.dstBpp = pCC->dstBpp;
        i.dsrc = NNS_G2dFontGetCellWidth(pFont) * i.srcBpp;

        p.packed = pCC->param;

        {
            const u32 areaWidth = (u32)pCC->areaWidth;
            const u32 areaHeight = (u32)pCC->areaHeight;
            const u32 baseWidthShift = p.baseWidthShift;
            const u32 baseHeightShift = p.baseHeightShift;

            for ( ; ofs_y > ofs_y_end; ofs_y -= 8) {
                i.ofs_y = ofs_y;
                cx = cx_base;
                for (ofs_x = ofs_x_base; ofs_x > ofs_x_end; ofs_x -= 8) {
                    const unsigned int iChar = NNSi_G2dCalcRectMask((u32)cx, (u32)cy, areaWidth, areaHeight, baseWidthShift, baseHeightShift);

                    i.ofs_x = ofs_x;
                    i.dst = pCharBase + iChar * charSize;

                    NNSi_G2dBlitCharData(&i);
                    cx++;
                }
                cy++;
            }
        }
    }
}

/*
 * Clear a linear surface to one pixel value: expand the value to a full word
 * (4bpp doubles the nibble, then the byte; 8bpp doubles the byte; both then
 * double the halfword) and hand w * h * bytes-per-pixel-row-unit to
 * MIi_CpuClearFast (MIi_CpuClearFast(data, dest, size) in the SDK map).
 *
 * THE LEVER that closed this row after five DIFF passes
 * (docs/notes/pkt_02068808.c.txt): the final `| (t << 16)` step is written
 * INSIDE BOTH ARMS, not after the if/else.  Written once after the join, the
 * two arms' shared `| (x << 8)` step is tail-merged (68 bytes) or the arms
 * write the parameter in place and the orrne is sunk (76 bytes).  With the
 * <<16 duplicated, the compiler tail-merges exactly that one step back out
 * and the arms stay predicated into a temporary (orreq/orreq/orrne r0) with
 * the result landing in the parameter's own register (orr r1, r0, r0, lsl
 * #16), which is the image.  The `n = w * h` partial product must be its own
 * statement.
 */
void NNSi_G2dSurfaceFill(struct Surface *s, u32 arg)
{
    int bpp = s->bpp;
    u32 t;
    int n;

    if (bpp == 4) {
        t = arg | (arg << 4);
        t = t | (t << 8);
        arg = t | (t << 16);
    } else {
        t = arg | (arg << 8);
        arg = t | (t << 16);
    }
    n = s->w * s->h;
    MIi_CpuClearFast(arg, s->base, n * ((bpp << 6) / 8));
}

/*
 * Row-by-row twin of NNSi_G2dSurfaceFill: the same pixel expansion, then one
 * MIi_CpuClearFast (MIi_CpuClearFast) per row of w * tile-size bytes, stepping
 * the destination by stride * tile-size.  The row count is re-read from +0x08
 * each iteration (the call may alias it) and compared signed.
 *
 * Two levers: the `| (t << 16)` step is written in BOTH arms (see
 * NNSi_G2dSurfaceFill), and `dst = s->base` is assigned AFTER the two products,
 * immediately before the loop.  Initialising dst in its declaration gives the
 * same bytes with dst in r5 instead of sb (24 bytes out); the late assignment
 * is what makes it the last value the allocator colours.
 */
void NNSi_G2dSurfaceFillTiled(struct Surface *s, u32 arg)
{
    int i, n, adv, tsz;
    int bpp = s->bpp;
    char *dst;
    u32 t;

    if (bpp == 4) {
        t = arg | (arg << 4);
        t = t | (t << 8);
        arg = t | (t << 16);
    } else {
        t = arg | (arg << 8);
        arg = t | (t << 16);
    }
    tsz = (bpp << 6) / 8;
    adv = tsz * s->stride;
    n = tsz * s->w;
    dst = s->base;
    for (i = 0; i < s->h; i++) {
        MIi_CpuClearFast(arg, dst, n);
        dst += adv;
    }
}

/*
 * Fill a rectangle of a LINEAR tile grid with one pixel value
 * (docs/families/cluster_020682DC.h): expand the pixel to a word, round the
 * rectangle out to whole 8x8 tiles and hand every covered tile to
 * NNSi_G2dCharCanvasFill with its own sub-rectangle, walking the grid with
 * `p += tilesz` per tile and `row += stride * tilesz` per tile row.
 *
 * Levers (docs/notes/pkt_02068808.c.txt has the earlier passes):
 *   - ../2.0/sp2 pin (1.1p1 is 408 bytes on this source);
 *   - the NNSi_G2dSurfaceFillRectSwizzled loop shape: yo as `(cy < y) ? y - cy : 0`, p = row
 *     after it, th through a clamped temporary, loop locals declared
 *     `cx, th, xe, p, yo` at function scope (image r4..r8);
 *   - wave 10: the tile size reads the field again,
 *     `tilesz = (s->bpp << 6) / 8;` (CSE'd into the one `ldrb`).  From the
 *     bpp local, bpp is the spilled value and the tile size takes fp; from
 *     the field, the image's choice (bpp in fp, tile size at [sp,#0x14]);
 *   - wave 10: the two rounded bounds come BEFORE the row pointer:
 *     `xe, ye, row, rowadv` (found by permuting the four statements; the
 *     permuter's reorder(+2) from the old order reached 412/72, and only
 *     xe-ye-first orders are exact).
 */
void NNSi_G2dSurfaceFillRect(struct SurfaceTiled *s, u32 arg, int x, int y, int w, int h)
{
    int cy;
    int x1;
    int y1;
    int ye;
    char *row;
    int x0;
    int tilesz;
    int rowadv;
    u8 bpp;
    int cx;
    int th;
    int xe;
    char *p;
    int yo;

    bpp = s->bpp;
    x1 = x + w;
    y1 = y + h;
    if (bpp == 4) { u32 t = arg | (arg << 4); t = t | (t << 8); arg = t | (t << 16); }
    else { u32 t = arg | (arg << 8); arg = t | (t << 16); }
    cy = y & ~7;
    tilesz = (s->bpp << 6) / 8;
    x0 = x & ~7;
    xe = (x1 + 7) & ~7;
    ye = (y1 + 7) & ~7;
    row = s->base + tilesz * ((cy / 8) * s->strideTiles + (x0 / 8));
    rowadv = s->strideTiles * tilesz;
    if (cy >= ye)
        return;
    do {
        int t;
        yo = (cy < y) ? y - cy : 0;
        p = row;
        t = y1 - cy;
        if (t > 8)
            t = 8;
        th = t - yo;
        for (cx = x0; cx < xe; cx += 8) {
            int xo = (cx < x) ? x - cx : 0;
            int tw = x1 - cx;
            if (tw > 8)
                tw = 8;
            tw -= xo;
            NNSi_G2dCharCanvasFill((u32 *)p, xo, yo, tw, th, arg, bpp);
            p = p + tilesz;
        }
        row = row + rowadv;
        cy = cy + 8;
    } while (cy < ye);
}

/*
 * Fill a rectangle of a SWIZZLED tile grid with one pixel value
 * (docs/families/cluster_020682DC.h): expand the pixel to a word, round the
 * rectangle out to whole 8x8 tiles, ask NNSi_G2dCalcRectMask for each tile's index
 * (tx, ty, w, h and the two swizzle bytes of the +0x10 word) and hand every
 * covered tile to NNSi_G2dCharCanvasFill with its own sub-rectangle.
 *
 * Levers, in the order they were found (docs/notes/pkt_02068808.c.txt):
 *   - ../2.0/sp2 pin (1.1p1 is 492 bytes);
 *   - yo as `(cy < y) ? y - cy : 0`, tx = tx0 after it, th through a
 *     clamped temporary; loop registers declared `cx, th, tx, xe, ty`;
 *   - THE LAST 8 BYTES (wave 10): the tile size is computed from a fresh
 *     read of the field, `tilesz = (s->bpp << 6) / 8;`, not from the bpp
 *     local.  The two loads CSE to the one `ldrb`, but the tile size then
 *     becomes its own value in the IR and the image's `stm sp, {r5, fp}` is
 *     scheduled before `sub r3, r2, r1` (tw - xo).  The same lever closes
 *     NNSi_G2dSurfaceFillRect, where it decides whether bpp or the tile size is the
 *     spilled value.  (Declaring NNSi_G2dCharCanvasFill's bpp parameter u8 in this
 *     caller also closes C84 alone, but the callee's own definition,
 *     src/matched/NNSi_G2dCharCanvasFill.c, is EXACT only with `int bpp`, so the
 *     re-read is the reading kept.)  The permuter (hill 800 + anneal 2000,
 *     --types) never moved this residue.
 */
void NNSi_G2dSurfaceFillRectSwizzled(struct SurfaceSwizzled *s, u32 arg, int x, int y, int w, int h)
{
    struct SurfaceSwzBase swzBase;
    int cy;
    int x1;
    int y1;
    int ye;
    char *base;
    int tx0;
    int x0;
    int sy;
    int sx;
    int sh;
    int sw;
    int tilesz;
    u8 bpp;
    int cx;
    int th;
    int tx;
    int xe;
    int ty;

    bpp = s->bpp;
    x1 = x + w;
    y1 = y + h;
    if (bpp == 4) { u32 t = arg | (arg << 4); t = t | (t << 8); arg = t | (t << 16); }
    else { u32 t = arg | (arg << 8); arg = t | (t << 16); }
    x0 = x & ~7;
    cy = y & ~7;
    ye = (y1 + 7) & ~7;
    tilesz = (s->bpp << 6) / 8;
    tx0 = x0 / 8;
    swzBase = s->swz;
    ty = cy / 8;
    xe = (x1 + 7) & ~7;
    sw = s->w;
    sh = s->h;
    base = s->base;
    sx = swzBase.x;
    sy = swzBase.y;
    if (cy >= ye)
        return;
    do {
        int yo, t;
        yo = (cy < y) ? y - cy : 0;
        tx = tx0;
        t = y1 - cy;
        if (t > 8)
            t = 8;
        th = t - yo;
        for (cx = x0; cx < xe; cx += 8) {
            int off = NNSi_G2dCalcRectMask(tx, ty, sw, sh, sx, sy);
            int xo = (cx < x) ? x - cx : 0;
            int tw = x1 - cx;
            if (tw > 8)
                tw = 8;
            tw -= xo;
            NNSi_G2dCharCanvasFill((u32 *)(base + tilesz * off), xo, yo, tw, th, arg, bpp);
            tx = tx + 1;
        }
        ty = ty + 1;
        cy = cy + 8;
    } while (cy < ye);
}

/*
 * The text-context initialiser: seven arguments straight into six fields of a
 * 0x18-byte pen/draw context, with no computation at all.  A leaf, and the
 * image proves it -- it never pushes and returns with a bare `bx lr`.
 *
 * TWO THINGS THE BYTES FORCED:
 *
 *   1. THE STORE ORDER IS THE SOURCE ORDER, and it is deliberately not the
 *      field order: +0x04, +0x08, +0x0c, +0x00, +0x14, +0x10.  Writing the
 *      fields in ascending order instead lets the front end fuse the first two
 *      into `stm r0, {r1, r2}` (which is what 1.1p1 does even with the source
 *      order, see the pin below), and the function changes shape.  This
 *      compiler never reorders independent stores to the same object, so the
 *      image's order IS the original statement order -- the same reading rule
 *      as docs/idioms/the-fall-through-arm-is-the-source-order.md applied to
 *      straight-line code.
 *
 *   2. +0x0c IS A BYTE.  `strb r2, [r0, #0xc]` with the value arriving as a
 *      full stack word, so the parameter is an `int` and the field is `u8`;
 *      the narrowing is at the store, not at the call.
 *
 * THE ARITY AND THE ARGUMENT ORDER are not guessed: the caller
 * src/matched/NNSi_G2dInitPenSimple.c (already EXACT) spells the call as
 *
 *     NNSi_G2dInitPen((char *)a, b, c, d, e, 0x020A18DC, c);
 *
 * which fixes seven arguments, three in registers and four on the stack at
 * [sp+0], [sp+4], [sp+8], and shows the last argument repeating the third.
 * The other caller, NNS_G2dCharCanvasInitForVRAM at 0x02069064, agrees.
 *
 * THE `../2.0/sp2` PIN.  dsi/1.1p1 cannot produce a leaf here at all: it
 * spends `r4` and `lr` on the three stack arguments and therefore opens
 * `push {r4, lr}` and returns through `pop {r4, pc}`, which also shifts every
 * stack-argument displacement by 8 and lets it fuse `str r1, [r0]` with
 * `str r2, [r0, #4]` into one `stm`.  Nine of the ten instructions differ.
 * ../2.0/sp2 and ../1.2/sp2 both reproduce the image byte for byte with the
 * same C.  ../2.0/sp2 is recorded because the adjacent matched member of this
 * cluster, src/matched/NNSi_G2dCharCanvasDrawChar.c, is independently pinned to it (on the
 * "kept constants" re-read tell) and because the other function filed into
 * this cluster in the same pass, src/matched/NNS_G2dCharCanvasInitForVRAM.c, is 2.0 and NOT
 * 1.2.  Since two front ends agree on this row it is not usable as evidence
 * for either pin on its own, and it is deliberately not offered as one in
 * docs/FRONTEND-PINS.md -- but the symptom is worth naming: A LEAF THAT GROWS
 * A PROLOGUE is a front-end question, not a spelling one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dInitPen.c \
 *       --func NNSi_G2dInitPen --addr 0x02068E78 --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 40 = original 40, 0 relocation sites
 */
void NNSi_G2dInitPen(struct Pen *p, void *charBase, int areaWidth, int areaHeight, int dstBpp, const void *vtable, int param)
{
    p->areaWidth = areaWidth;
    p->areaHeight = areaHeight;
    p->dstBpp = (u8)dstBpp;
    p->charBase = charBase;
    p->vtable = vtable;
    p->param = param;
}

/*
 * Per-file compiler pin, the re-read/forward form of the "kept constants"
 * family (docs/FRONTEND-PINS.md, the NNSi_G3dAnmObjInitNsBva row). The image RE-READS
 * the font's header chain a second time before the switch dispatch,
 * `ldr r1, [r7]` at 0x02068F00 (`00 10 97 e5`) then `ldr r3, [r1, #8]` at
 * 0x02068F04 (`08 30 91 e5`), although the same chain was already loaded at
 * 0x02068EE8/0x02068EEC for the stride computation two instructions earlier.
 * dsi/1.1p1 -O4,p forwards the register it still has live and collapses the
 * pair to a single `ldr r3, [r3, #8]`, giving 284 bytes against the original's
 * 292 with everything from the dispatch onward shifted by four. A volatile
 * qualifier on the outer load, struct-typed field chains, binding the header
 * to a local before or after out[1], and a fresh `(*font)->hdr` chain spelled
 * out in every switch arm all CSE identically at 284. Under the pin the same C
 * is 292 bytes, 0 mismatches.
 *
 * Draw one glyph: look the character up in the font's range table, fall back
 * to the font's default glyph when the lookup returns its 0xFFFF "not found"
 * sentinel (the pool word at 0x02068FC0), then adjust the pen position by the
 * glyph's own bearings according to the header's layout kind before handing
 * both the glyph record and the metrics record to the context's draw hook.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dCharCanvasDrawChar.c \
 *       --func NNSi_G2dCharCanvasDrawChar --addr 0x02068EA0 --cc ../2.0/sp2 --arm
 */
s8 NNSi_G2dCharCanvasDrawChar(struct Ctx *ctx, NNSG2dFont *font, int x, int y, int cl, u16 code)
{
    s8 *out[2];
    u32 idx;
    s8 *g;
    u8 k;

    idx = NNS_G2dFontGetGlyphIndex(font, code);
    if (idx == 0xffff)
        idx = font->pRes->alterCharIndex;
    out[0] = (s8 *)NNS_G2dFontGetCharWidthsFromIndex(font, idx);
    out[1] = (s8 *)((char *)font->pRes->pGlyph + 8 + idx * font->pRes->pGlyph->cellSize);
    g = out[0];
    k = font->pRes->pGlyph->flags;

    switch (k) {
    case 0:
    case 7:
        x += g[0];
        break;
    case 1:
    case 2:
        x -= font->pRes->pGlyph->cellWidth;
        y += g[0];
        break;
    case 3:
    case 4:
        x -= g[0] + (u8)g[1];
        y -= font->pRes->pGlyph->cellHeight;
        break;
    case 5:
    case 6:
        y -= g[0] + font->pRes->pGlyph->cellHeight;
        break;
    }
    ((void (*)(struct Ctx *, void *, int, int, int, s8 **))ctx->vt[0])(ctx, font, x, y, cl, out);
    return out[0][2];
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dInitPenSimple.c \
 *       --func NNSi_G2dInitPenSimple --addr 0x02068FC4 --cc 1.1p1 --arm
 */
void NNSi_G2dInitPenSimple(int pen, int charBase, int areaWidth, int areaHeight, int dstBpp)
{
    NNSi_G2dInitPen((struct Pen *)pen, (void *)charBase, areaWidth, areaHeight, dstBpp, (const void *)0x020A18DC, areaWidth);
}

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
 * NNSi_G2dInitPen with the vtable-like object g_020A18E8.
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
 *   python3 tools/match.py one --src src/matched/NNS_G2dCharCanvasInitForVRAM.c \
 *       --func NNS_G2dCharCanvasInitForVRAM --addr 0x02068FF0 --arm --cc ../2.0/sp2
 */
void NNS_G2dCharCanvasInitForVRAM(void *pCC, void *charBase, int areaWidth, int areaHeight, int colorMode)
{
    Param param;
    const int shiftW = SizeToShift(areaWidth);
    const int shiftH = SizeToShift(areaHeight);
    const u8 *p = g_020A18F4[shiftH][shiftW];

    param.w = p[0];
    param.h = p[1];
    NNSi_G2dInitPen((struct Pen *)pCC, charBase, areaWidth, areaHeight, colorMode, g_020A18E8, param.raw);
}

/*
 * NitroSystem NNS_G2dMapScrToCharText (g2d_CharCanvas): map a rectangle of
 * a text-BG screen to consecutive character numbers.  A screen no wider
 * than 32 entries is linear and goes to NNSi_G2dFillScrCharArea; a 64-wide screen is
 * two 32x32 blocks side by side, so row y >= 32 skips the right-hand block
 * (y + 32) and column x >= 32 lands in it (x + 32 * 31).
 *
 * Levers: `scnWidth * areaTop + areaLeft` in that order and parenthesised
 * (the image's `mla r4, r5, lr, r3`; the unparenthesised sum is two adds,
 * and the other product order is 2 bytes out); `const u16 cpltMask` and the
 * post-increment inside the store, as in NNSi_G2dFillScrCharArea.
 *
 * COMPILER PIN ../2.0/sp2 (docs/FRONTEND-PINS.md): both 32-block selects are
 * true conditional-move pairs in the image, `cmp lr, #0x20` / `movlt r2, lr`
 * / `addge r2, lr, #0x20` at 0x020690D0..0x020690D8 and `cmp r7, #0x20` /
 * `movlt r2, r7` / `addge r2, r7, #0x3e0` at 0x020690EC..0x020690F4; dsi/1.1p1
 * emits an unconditional `mov r2, lr` before the `cmp` (and `mov r2, r7`),
 * 16 concrete bytes out at 176.  0 mismatches under the pin.
 */
void NNS_G2dMapScrToCharText(void *scnBase, int areaWidth, int areaHeight, int areaLeft, int areaTop,
                   int scnWidth, int charNo, int cplt)
{
    if (scnWidth <= 32) {
        NNSi_G2dFillScrCharArea((u16 *)scnBase + (scnWidth * areaTop + areaLeft), areaWidth, areaHeight,
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

/*
 * The linear half of NitroSystem's NNS_G2dMapScrToCharText (g2d_CharCanvas):
 * fill an areaWidth x areaHeight block of a text-BG screen whose rows are
 * scnWidth entries apart with consecutive character numbers, palette
 * `cplt` in the top four bits of every entry.  NNS_G2dMapScrToCharText calls it for
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
void NNSi_G2dFillScrCharArea(u16 *pScrBase, int w, int h, int scnWidth, int charNo, int cplt)
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

/*
 * Number of OBJs NitroSystem's 1D OBJ arrangement (NNSi_G2dMakeCharObjArea) spends on
 * an areaWidth x areaHeight character area: 8x8-char OBJs over the aligned
 * part, then per 8-char strip one OBJ for a 4-char remainder and two for
 * each of the 2- and 1-char remainders (a 1x8 or 2x8 OBJ does not exist),
 * and the remainder corner.  Exported; nothing in the image calls it.
 *
 * Levers, from the permuter (docs/notes/permuter.md): the bit pair is
 * `((v & 2) >> 1) + (v & 1)` (bit 1 first), the declarations run
 * X8, Y8, X2, num, X4, Y4, Y2, and the corner product is bound to its own
 * local before the return.
 *
 * COMPILER PIN ../2.0/sp2, "kept constants" (docs/FRONTEND-PINS.md): the
 * image seeds the product chain with a materialised zero, `mov r2, #0` at
 * 0x02069190 then `mla lr, r3, r5, r2` at 0x02069194; dsi/1.1p1 folds the
 * same C to a bare `mul lr, r3, r5` (every spelling of the zero the earlier
 * notes list does the same), 25 concrete bytes out.  0 under the pin.
 */
u32 NNSi_G2dCalcCharAreaSize(u32 areaWidth, u32 areaHeight)
{
    u32 numX8 = areaWidth >> 3;
    u32 numY8 = areaHeight >> 3;
    u32 numX2 = ((areaWidth & 2) >> 1) + (areaWidth & 1);
    u32 num = 0;
    u32 numX4 = (areaWidth & 4) >> 2;
    u32 numY4 = (areaHeight & 4) >> 2;
    u32 numY2 = ((areaHeight & 2) >> 1) + (areaHeight & 1);
    u32 corner;

    num += numX8 * numY8;
    num += numY8 * (numX2 * 2 + numX4);
    num += numX8 * (numY2 * 2 + numY4);
    corner = (numX2 + numX4) * (numY2 + numY4);
    return num + corner;
}

inline static void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
  oam->attr01 = ((oam->attr01 & (~(0x000000FFu | 0x01FF0000u))) | (y & 0x000000FFu)) | ((x & (0x01FF0000u >> 16)) << 16);
}

inline static void G2_SetOBJShape(GXOamAttr *oam, u32 shape)
{
  oam->attr01 = (oam->attr01 & (~(0x0000C000u | 0xC0000000u))) | shape;
}

inline static void G2_SetOBJCharName(GXOamAttr *oam, int name)
{
  oam->attr2 = (u16) ((oam->attr2 & (~0x03FF)) | name);
}

inline static void G2_SetOBJColorMode(GXOamAttr *oam, int color)
{
  oam->attr01 = (oam->attr01 & (~0x2000u)) | (color << 13);
}

/*
 * NitroSystem g2d_CharCanvas.c, NNS_G2dArrangeOBJ1D(oam, areaWidth,
 * areaHeight, x, y, color, charName, vramShift): pick the OBJ shape for the
 * area from g_020A18F4[log2 h][log2 w] (NNSi_G2dGetOamShapeCode turns the pair into
 * the attr01 shape/size bits), lay the aligned block out with the SDK OAM
 * inlines, then recurse on the right strip, the bottom strip and the
 * corner; returns the number of OBJs written.  The log2 is the SDK's
 * inline-asm MATH_CountLeadingZeros behind a `>= 8 ? 3 :` ternary.
 *
 * Levers (wave 11): the three post-lookup locals are DECLARED
 * charPerOBJ, numX, numY (uninitialised) and assigned numX, numY,
 * charPerOBJ afterwards -- declaration order, not assignment order, is
 * what gives numX sb and charPerOBJ r8 (initialised consts in assignment
 * order swap the pair, 5 bytes out; assigning charPerOBJ first fixes the
 * registers but moves the schedule).  The right-strip x is bound to a
 * named local before the recursive call.
 *
 * COMPILER PIN ../2.0/sp2: dsi/1.1p1 is 768 bytes with a wider push.
 */
int NNSi_G2dMakeCharObjArea(GXOamAttr *oam, int areaWidth, int areaHeight, int x, int y, int color, int charName, int vramShift)
{
  const int shiftI = (areaWidth >= 8) ? (3) : (MATH_ILog2((u32) areaWidth));
  const int shiftJ = (areaHeight >= 8) ? (3) : (MATH_ILog2((u32) areaHeight));
  const u8 *pair = g_020A18F4[shiftJ][shiftI];
  const int objShiftW = pair[0];
  const int objShiftH = pair[1];
  const u32 alignedW = ((u32) areaWidth) & (0xFFFFFFFFu << objShiftW);
  const u32 alignedH = ((u32) areaHeight) & (0xFFFFFFFFu << objShiftH);
  const int charUnit = (color == 0) ? (1) : (2);
  int numOBJ = 0;
  const u32 shape = NNSi_G2dGetOamShapeCode(pair);
  int charPerOBJ;
  int numX;
  int numY;
  int ix;
  int iy;
  numX = areaWidth >> objShiftW;
  numY = areaHeight >> objShiftH;
  charPerOBJ = (charUnit << objShiftW) << objShiftH;
  for (iy = 0; iy < numY; iy++)
  {
    const int py = y + ((iy << objShiftH) << 3);
    for (ix = 0; ix < numX; ix++)
    {
      const int px = x + ((ix << objShiftW) << 3);
      G2_SetOBJPosition(oam, px, py);
      G2_SetOBJShape(oam, shape);
      G2_SetOBJCharName(oam, charName);
      G2_SetOBJColorMode(oam, color);
      charName += charPerOBJ >> vramShift;
      oam++;
    }

  }

  numOBJ += numX * numY;
  if (alignedW < ((u32) areaWidth))
  {
    const int restW = areaWidth - alignedW;
    const int tmp = x + (alignedW << 3);
    const int n = NNSi_G2dMakeCharObjArea(oam, restW, alignedH, tmp, y, color, charName, vramShift);
    oam += n;
    charName += ((u32) (alignedH * (charUnit * restW))) >> vramShift;
    numOBJ += n;
  }
  if (alignedH < ((u32) areaHeight))
  {
    const int restH = areaHeight - alignedH;
    const int n = NNSi_G2dMakeCharObjArea(oam, alignedW, restH, x, y + (alignedH << 3), color, charName, vramShift);
    oam += n;
    charName += ((u32) (restH * (charUnit * alignedW))) >> vramShift;
    numOBJ += n;
  }
  if ((alignedW < ((u32) areaWidth)) && (alignedH < ((u32) areaHeight)))
  {
    numOBJ += NNSi_G2dMakeCharObjArea(oam, areaWidth - alignedW, areaHeight - alignedH, x + (alignedW << 3), y + (alignedH << 3), color, charName, vramShift);
  }
  return numOBJ;
}

/*
 * The innermost draw step of the text renderer, the function
 * src/matched/NNSi_G2dDrawTextRotated.c calls once per line as
 * `NNSi_G2dDrawTextLine(ctx, px, py, w2, cur, &cur, st)`.  It walks one LINE of the
 * string: a character iterator is fetched out of the font object
 * (`ctx->pFont`, callback at +4, taking a `const void **` cursor and returning
 * the character code), each character is drawn with NNSi_G2dCharCanvasDrawChar, and the
 * pen is stepped along the step vector by the glyph's advance plus the
 * inter-character gap `ctx->hSpace`.  The walk stops at NUL or at '\n' (0xa),
 * and the `last` out-parameter receives the cursor position when the stop was
 * a newline and 0 when it was the end of the string -- the identical tail
 * NNS_G2dFontGetStringWidth (the measure-one-line sibling at 0x02068030) carries at
 * 0x020680AC..0x020680C0, which is what fixes the polarity here.
 *
 * TWO C LEVERS, both needed, both found by measurement:
 *
 * 1. DECLARATION ORDER `gap` BEFORE `fnt`
 *    (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *    The image opens `ldr r4, [fp, #8]` / `ldr r5, [fp, #4]` -- the two
 *    context fields loaded as SEPARATE instructions in DESCENDING offset
 *    order, which is the one order mwccarm's ldm coalescer cannot merge.
 *    Declared the other way round the same two loads fold to a single
 *    `ldmib fp, {r4, r5}`, the whole body shifts one slot earlier and 94 of
 *    180 bytes differ.  Re-ordering the two ASSIGNMENTS does not help (every
 *    permutation was measured: 94, 95 and 97 bytes out); it is the
 *    declaration order that picks r4 for the gap and r5 for the font, and
 *    having picked them the scheduler emits the loads in that order.
 *
 * 2. THE LOOP MUST BE AN EXPLICIT `goto`, NOT A `while`
 *    (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md).
 *    The image's back edge is `bne #0x206951c` at 0x02069554: it tests only
 *    `c != 0` and jumps back to the `cmp r0, #0xa` at 0x0206951C, so the
 *    newline test is the LOOP TOP and the NUL test is the BOTTOM.  Written as
 *    `while (c != 0xa) { ...; c = next(&cur); if (c == 0) break; }` the
 *    compiler fuses the bottom pair into `cmp r0, #0 / cmpne r0, #0xa`, which
 *    is one instruction and four bytes too many (184 bytes, 59 out) and moves
 *    the `ldrsb r7, [sp, #0x40]` load of st.dx from between the two compares
 *    to after them.  The explicit two-label form below keeps them apart.
 *
 * The compiler pin is the cluster's, `../2.0/sp2`, shared with its packet
 * mates NNSi_G2dDrawTextRotated, NNSi_G2dCalcTextBox and NNSi_G2dFontFixupSections; see the "kept
 * branches" tell in docs/FRONTEND-PINS.md.  Under dsi/1.1p1 this same source
 * loses the 0x10 frame and the ten-register push.
 *
 * The two trailing `signed char`s are ONE 2-byte struct passed by value, the
 * same Step the whole cluster forwards (see NNSi_G2dAlignTextVertical's header).
 */
void NNSi_G2dDrawTextLine(Ctx *ctx, s32 x, s32 y, s32 w2,
                   const void *s, const void **last, Step st)
{
    const void *cur;
    s32 gap;
    NNSG2dFont *fnt;
    NextFn next;
    u16 c;
    s32 adv;
    s32 dx;
    s32 dy;

    gap = ctx->hSpace;
    fnt = ctx->pFont;
    cur = s;
    next = ((NextFn *)fnt)[1];
    dy = st.dy;
    /* stand-in: goto loop; while/for forms change the block layout (800 bytes) */
    c = next(&cur);
    if (c == 0) goto done;
    dx = st.dx;
loop:
    if (c == 0xa) goto done;
    adv = gap + NNSi_G2dCharCanvasDrawChar(ctx->pCanvas, fnt, x, y, w2, c);
    x = x + adv * dx;
    y = y + adv * dy;
    c = next(&cur);
    if (c != 0) goto loop;
done:
    if (last != 0) {
        *last = (c == 0xa) ? cur : 0;
    }
}

/*
 * The line loop of the text renderer, sitting between NNSi_G2dAlignTextVertical /
 * NNSi_G2dCalcTextBox (which pre-align the pen) and NNSi_G2dDrawTextLine (which draws one
 * line). Per line it optionally re-aligns the pen horizontally within the
 * measured line box -- bit 11 of the flags word right-aligns by the full
 * measured width, bit 10 centres by half -- then draws the line and steps the
 * pen down by one line height along the step normal.
 *
 * Per-file compiler pin, the "kept branches" tell in its CROSS-JUMP form
 * (docs/FRONTEND-PINS.md). The image writes the pen-delta tail out in BOTH
 * arms of the alignment dispatch: `mla r4, r0, sb, r4` / `mla r5, r0, r8, r5`
 * at 0x02069658/0x0206965C closed by `b 0x0206969C` (`0d 00 00 ea`) at
 * 0x02069660 for the bit-11 arm, and the byte-identical `mla r4, r0, sb, r4`
 * / `mla r5, r0, r8, r5` at 0x02069694/0x02069698 for the bit-10 arm.
 * dsi/1.1p1 -O4,p cross-jumps the two, branching the bit-11 arm straight
 * into the bit-10 arm's pair and dropping both instructions plus the join
 * branch: 352 bytes against the original's 360, 130 concrete bytes out with
 * everything before 0x020695F4 already identical. Under the pin the same C
 * is 360 bytes, 0 mismatches.
 *
 * One C lever needed under the pin: `px`/`py` must be declared BEFORE
 * `sx`/`sy`, which is what puts the per-line pen in r4/r5 and the running
 * line offset in r6/r7. Declared the other way round the same 360 bytes come
 * out with those four registers swapped, 21 concrete bytes out.
 */
void NNSi_G2dDrawTextRotated(Ctx *ctx, s32 x, s32 y, s32 w,
                   s32 w2, u32 flags, const void *s, Step st)
{
    const void *cur;
    s32 lead;
    s32 dx;
    s32 dy;
    s32 bit11;
    s32 bit10;
    s32 half;
    s32 px;
    s32 py;
    s32 sx;
    s32 sy;
    s32 n;

    lead = ctx->vSpace + ctx->pFont->pRes->linefeed;
    dx = lead * -st.dy;
    dy = lead * st.dx;

    cur = s;
    if (cur == 0) return;

    sx = 0;
    bit11 = flags & 0x800;
    half = (w + 1) / 2;
    bit10 = flags & 0x400;
    sy = 0;

    do {
        px = x + sx;
        py = y + sy;
        if (bit11 != 0) {
            n = w - NNS_G2dFontGetStringWidth(ctx->pFont, ctx->hSpace, cur, 0);
            px = px + n * st.dx;
            py = py + n * st.dy;
        } else if (bit10 != 0) {
            n = half - (NNS_G2dFontGetStringWidth(ctx->pFont, ctx->hSpace, cur, 0) + 1) / 2;
            px = px + n * st.dx;
            py = py + n * st.dy;
        }
        NNSi_G2dDrawTextLine(ctx, px, py, w2, cur, &cur, st);
        sx = sx + dx;
        sy = sy + dy;
    } while (cur != 0);
}

/*
 * The block-alignment pre-pass, the two-dimensional counterpart of
 * NNSi_G2dAlignTextVertical's single-line one. It measures the whole multi-line extent
 * with NNS_G2dFontGetTextRect into a two-word local, copies that pair into a second
 * local (the one the caller-visible {w,h} box keeps), and then backs the pen
 * off along the step vector according to two pairs of flag bits:
 *   0x10 centre vertically, 0x20 bottom-align (measured width, +0x18)
 *   0x02 centre horizontally, 0x04 right-align (box height, +0x24)
 * Everything is then forwarded verbatim to NNSi_G2dDrawTextRotated, the same Step
 * struct by value that NNSi_G2dAlignTextVertical forwards.
 *
 * Per-file compiler pin, the "kept branches" tell (docs/FRONTEND-PINS.md).
 * The image keeps `tst r4, #0x20` at 0x02069768 (`20 00 14 e3`) and
 * `beq 0x02069784` at 0x0206976C (`04 00 00 0a`) over the FIVE-instruction
 * bottom-align arm at 0x02069770..0x02069780 (two `ldrsb` of the step pair,
 * `rsb r2, r2, #0`, and the two `mla`). dsi/1.1p1 -O4,p predicates the whole
 * arm to `ldrsbne/rsbne/ldrsbne/mlane/mlane`, and having done so schedules
 * the head one slot differently (`ldr r3, [r8, #0xc]` split out of the
 * `ldmib r8, {r1, r2, r3}`): the same 292 bytes, 93 concrete bytes out, with
 * everything from 0x02069784 onward already byte-identical. Under the pin
 * the same C is 292 bytes, 0 mismatches.
 *
 * The three {w,h} pairs at sp+0x10, sp+0x18 and sp+0x20 are three distinct
 * stack objects: the out buffer NNS_G2dFontGetTextRect fills and two copies of it,
 * only one of which is read again. Both copies must be `volatile` or 1.1p1
 * and 2.0 alike dead-store-eliminate them and the frame comes out 0x18.
 */
void NNSi_G2dCalcTextBox(Ctx *ctx, s32 x, s32 y, s32 w,
                   u32 flags, u32 s, Step st)
{
    volatile Ext box2;
    Ext e;
    volatile Ext box;
    s32 d;

    e = NNS_G2dFontGetTextRect(ctx->pFont, ctx->hSpace, ctx->vSpace, (const void *)s);
    box.width = e.width;
    box.height = e.height;
    box2.width = e.width;
    box2.height = e.height;

    if (flags & 0x10) {
        d = -(e.width + 1) / 2;
        x = x + d * st.dx;
        y = y + d * st.dy;
    } else if (flags & 0x20) {
        d = -e.width;
        x = x + d * st.dx;
        y = y + d * st.dy;
    }

    if (flags & 2) {
        d = -(box2.height + 1) / 2;
        x = x + d * -st.dy;
        y = y + d * st.dx;
    } else if (flags & 4) {
        d = -box2.height;
        x = x + d * -st.dy;
        y = y + d * st.dx;
    }

    NNSi_G2dDrawTextRotated(ctx, x, y, box2.width, w, flags, (const void *)s, st);
}

/*
 * The two trailing `signed char` parameters are ONE 2-byte struct passed by
 * value, not two separate char arguments. Spelled as two arguments the ABI
 * gives each its own word slot and the image's `ldrsb r2, [sp, #0x39]` /
 * `strb ip, [sp, #0xd]` become +0x3C and +0x10; the struct form packs them
 * adjacently and is what makes the file byte-correct. The same pair is
 * forwarded verbatim to NNSi_G2dDrawTextRotated, which therefore takes it the same
 * way.
 *
 * VERDICT: MATCH. Byte-correct -- 224 bytes, ZERO concrete mismatches, the
 * full extent -- and capped only for lack of an outside witness.
 *
 * BLOCKING EVIDENCE CLASS: none available for the two calls to 0x020680DC
 * at +0x0030 and +0x0068. `label` refuses it: 0x020680DC has exactly two
 * branch witnesses anywhere in the image (arm9 and every overlay), at
 * 0x02069848 and 0x02069880, and BOTH are the two `bl`s in this function,
 * so every witness is inside the compared range. There is no `matched`
 * manifest entry for 0x020680DC either (it is in another packet), and it
 * is ordinary compiled C, so neither `runtime` nor `veneer` applies.
 * `--suggest-split` was run and reports "the whole range as one file is
 * NOT viable / best partition: 0 piece(s), 1 function(s) left out": both
 * sites are calls from a single function section, so there is no cut that
 * leaves either one a witness outside a smaller range.
 *
 * The third site, the tail call to 0x0206958C at +0x00D4, IS resolved
 * (`label x3, e.g. 0206980C`). Unblocking this file therefore needs one
 * thing only: an EXACT manifest entry covering 0x020680DC, which would
 * give both sites the `matched` class. That address is outside
 * pkt_020694D8 and cannot be filed from here.
 *
 * The horizontal/vertical alignment pre-pass for the text renderer.
 * Depending on two bits of the flags word (the third stack argument) it
 * measures the string with NNS_G2dFontGetTextHeight and shifts the pen:
 *   bit 8  (0x100): right/bottom align -- back the pen off by the full
 *                   measured extent, `(limit - measured)`;
 *   bit 7  (0x080): centre align -- back it off by half, with the
 *                   +1/asr-1 rounding pair on BOTH operands, which is what
 *                   produces the four `add rN, rM, rM, lsr #31` / `asr #1`
 *                   instructions at 0x02069888..0x020698A4.
 * The pen delta is applied as `pen += extent * (-dy)` and
 * `pen += extent * dx` through the two `mla`s, then everything is
 * forwarded verbatim to NNSi_G2dDrawTextRotated.
 */
void NNSi_G2dAlignTextVertical(Ctx *ctx, s32 x, s32 y, s32 w,
                   u32 h, u32 w2, u32 flags, u32 s, Step st)
{
    s32 n;
    s32 d;

    if (flags & 0x100) {
        n = NNS_G2dFontGetTextHeight(ctx->pFont, ctx->vSpace, (const void *)s);
        d = (s32)h - n;
        x = x + d * -st.dy;
        y = y + d * st.dx;
    } else if (flags & 0x80) {
        n = NNS_G2dFontGetTextHeight(ctx->pFont, ctx->vSpace, (const void *)s);
        d = ((s32)h + 1) / 2 - (n + 1) / 2;
        x = x + d * -st.dy;
        y = y + d * st.dx;
    }
    NNSi_G2dDrawTextRotated(ctx, x, y, w, w2, flags, (const void *)s, st);
}

static inline BOOL IsNftr(const Res *r)
{
    if (r != 0 && r->signature == 0x4e465452u)
        return 1;
    return 0;
}

static inline BOOL VerAtLeast(const Res *r, u16 v)
{
    if (r != 0 && r->version >= v)
        return 1;
    return 0;
}

static inline BOOL IsValid(const Res *r, u16 v)
{
    return r != 0 ? (IsNftr(r) && VerAtLeast(r, v)) : 0;
}

/*
 * NFTR font-resource open (docs/families/cluster_020694D8.h): validate the
 * resource against version 0x0102, then 0x0101, else assert 0x0100 and mark
 * it legacy; relocate the section table, find 'FINF', hand back payload + 8,
 * and for a legacy resource clear byte 7 of the FINF's +8 pointee.
 *
 * Closed wave 12.  The six doubly-normalised guards are three INLINE helper
 * levels, and the leaf helpers are written as `if (cond) return 1; return 0;`
 * -- the only spelling that materialises the `&&` value (moveq #1 / beq /
 * mov #0) instead of merging it into the caller's branch.  The caller's `&&`
 * then normalises it (movne #1 / moveq #0) and tests it; the outer
 * `r != 0 ? ... : 0` is the leading null test whose false value is the r4
 * zero.  `return r && cond;` in the leaves merges into control flow (256
 * bytes); `if (r == 0) return 0; return cond;` gives movhs/movlo (122 out).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNS_G2dFontLoad.c \
 *       --func NNS_G2dFontLoad --addr 0x020698F8 --arm --cc ../2.0/sp2
 *   EXACT, 460 bytes, 3 of 3 relocation sites resolved.
 *   ../2.0/sp2p2: EXACT as well; dsi/1.1p1: 452 bytes, DIFF.
 */
u32 NNS_G2dFontLoad(Res *res, void **out)
{
    BOOL legacy = 0;
    u8 *finf;

    if (!IsValid(res, 0x102) && !IsValid(res, 0x101)) {
        if (!IsValid(res, 0x100))
            OS_Terminate();
        legacy = 1;
    }
    NNSi_G2dFontFixupSections(res);
    finf = NNS_G2dFindBinaryBlock((struct NNSG2dBinaryFileHeader *)res, 0x46494e46u);
    if (finf == 0) {
        *out = 0;
        return 0;
    }
    *out = finf + 8;
    if (legacy)
        (*(u8 **)((u8 *)*out + 8))[7] = 0;
    return 1;
}

/*
 * Relocate the section table of an NFTR-style font resource loaded at `base`:
 * the u16 at +0x0C is the byte offset of the first section header and the u16
 * at +0x0E the section count; each header carries its own FourCC at +0 and its
 * own size at +4, which is the stride to the next one.
 *
 * Per-signature fixups, all "add `base` to a stored file offset":
 *   'FINF'  +0x10 unconditionally, then +0x14 and +0x18 if non-zero
 *   'CWDH'  +0x0C if non-zero
 *   'CMAP'  +0x10 if non-zero
 *   'CGLP'  nothing -- an EMPTY arm whose target is the default exit.
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md). The
 * original keeps the dead `cmp r5, lr` at 0x02069B00 (e155000e), the left
 * leaf of the four-way search tree, immediately before the unconditional
 * `b 0x02069B74` to the default exit. dsi/1.1p1 -O4,p folds that compare
 * away because the CGLP arm and the default share a target, giving 216
 * bytes against the original's 220, with every other byte identical and
 * shifted by exactly those four. Empty-arm, `default:`-fallthrough,
 * `continue` and `goto` spellings all fold the same way under 1.1p1.
 * ../2.0/sp2 keeps the compare: 220 bytes, 0 mismatches.
 */
void NNSi_G2dFontFixupSections(Res *base)
{
    Section *s;
    s32 i;
    s32 n;
    u32 v;

    s = (Section *)((u8 *)base + base->headerSize);
    i = 0;
    n = base->numBlocks;
    if (n <= 0) return;
    do {
        switch (s->signature) {
        case 0x46494e46:
            s->pGlyph = s->pGlyph + (u32)base;
            v = s->pWidth;
            if (v != 0) s->pWidth = v + (u32)base;
            v = s->pMap;
            if (v != 0) s->pMap = v + (u32)base;
            break;
        case 0x43574448:
            v = s->pNextWidth;
            if (v != 0) s->pNextWidth = v + (u32)base;
            break;
        case 0x434d4150:
            v = s->pGlyph;
            if (v != 0) s->pGlyph = v + (u32)base;
            break;
        case 0x43474c50:
            break;
        }
        i++;
        s = (Section *)((u8 *)s + s->size);
    } while (i < (s32)base->numBlocks);
}

static inline void BitReaderNextByte(struct BitReader *reader)
{
    reader->bits = *(reader->src)++;
    reader->avail = 8;
}

u32 NNSi_G2dBitReaderRead(struct BitReader *reader, int nBits)
{
    u32 val = reader->bits;
    int avail = reader->avail;

    if (avail < nBits) {
        int lack = nBits - avail;
        val <<= lack;
        BitReaderNextByte(reader);
        val |= NNSi_G2dBitReaderRead(reader, lack);
    } else {
        val >>= (avail - nBits);
        reader->avail = (s8)(avail - nBits);
    }

    val &= 0xFF >> (8 - nBits);
    return val;
}

/*
 * The halfword post-increment reader over the bit reader's byte cursor
 * (+0x00), the unlabelled leaf after NNSi_G2dBitReaderRead (seeded start).  The
 * cursor must be read into a typed u16 pointer and post-incremented; the
 * u8-pointer spelling `p = b->cur; b->cur = p + 2; return *(u16 *)p;`
 * schedules the store before the load (7 bytes).
 */
u16 NNSi_G2dReadCharUTF16(CharCursor *cursor)
{
    u16 *p = (u16 *)cursor->pCur;
    u16 v = *p++;
    cursor->pCur = (u8 *)p;
    return v;
}

/*
 * Size of the payload described by (tag, node): dispatches on the tag byte
 * *tag (same 0x4D/0x4A/0x56 tag alphabet as NNS_G3dRenderObjAddAnmObj in the
 * neighbouring list module) and returns the node's element count scaled by
 * two, plus the 0x1C header, rounded down to a word. 0x4D counts from the
 * byte at +0x18, 0x4A and 0x56 share the byte at +0x17.
 */
u32 GetTaggedPayloadSize(const u8 *tag, const TaggedNode *node)
{
    if (tag == 0 || node == 0) return 0;
    switch (*tag) {
    case 0x4d:
        return ((node->entryCountM * 2) + 0x1c) & ~3;
    case 0x4a:
    case 0x56:
        return ((node->entryCount * 2) + 0x1c) & ~3;
    }
    return 0;
}
