#ifndef GAME_ARM9_NNS_G2D_RES_TYPES_H
#define GAME_ARM9_NNS_G2D_RES_TYPES_H

#include "../types.h"

/* Bodies of the NITRO graphics resources after unpacking ('RAHC' character data, 'TTLP' palette data). */

typedef struct NNSG2dCharacterData {
    u16 H;                  /* +0x00 */
    u16 W;                  /* +0x02 */
    u32 pixelFmt;           /* +0x04 */
    u32 mapingType;         /* +0x08 */
    u32 characterFmt;       /* +0x0c */
    u32 szByte;             /* +0x10 */
    void *pRawData;         /* +0x14  offset, becomes a pointer */
} NNSG2dCharacterData;

typedef struct NNSG2dPaletteData {
    u32 fmt;                /* +0x00 */
    BOOL bExtendedPlt;      /* +0x04 */
    u32 szByte;             /* +0x08 */
    void *pRawData;         /* +0x0c  offset, becomes a pointer */
} NNSG2dPaletteData;

/* The 'PMCP' palette-compress-map body: only the +0x04 self-relative offset is touched by the fixup. */
typedef struct NNSG2dPaletteCompressInfo {
    u8  pad_00[0x04];
    void *pVramTransfer;    /* +0x04  offset, becomes a pointer */
} NNSG2dPaletteCompressInfo;

#endif
