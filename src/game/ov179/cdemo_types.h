#ifndef ALETHEIA_CDEMO_TYPES_H
#define ALETHEIA_CDEMO_TYPES_H

/*
 * ov179 work object (size 0x605C, allocated by CDEMO_MAIN_Create) and the
 * records it points at. Built from the offset views the overlay used before.
 */

/* Command-script record pointed at by CdemoState.script (f0). */
struct CdemoScript {
    unsigned short index; /* 00: current entry in the scene tables */
    unsigned char  state; /* 02: nonzero while the script is active */
    unsigned char  flag;  /* 03: set when the script must stop */
};

/* One 0x2004-byte palette block inside CdemoState.palettes. */
struct CdemoPaletteBlock {
    unsigned char  data[0x2000]; /* 0000: raw palette/tile bytes */
    unsigned int   count;        /* 2000: byte count of data */
};

/* Loaded palette entry handed back by ARC_UTIL_LoadPaletteBlockFromHandle. */
struct CdemoPaletteEntry {
    unsigned char  pad0[8];
    int            size; /* +08: byte count */
    int            data; /* +0C: source address */
};

struct CdemoState {
    struct CdemoScript *script;            /* 0000: current script record */
    void               *arcHandle;         /* 0004: graphics archive handle */
    struct CdemoPaletteBlock palettes[3];  /* 0008: three 0x2004 blocks */
    void               *task;              /* 6014: task started by GFL_USE_AddMainTask */
    int                 scriptStart;       /* 6018: script table base */
    int                 scriptCursor;      /* 601C: current command pointer */
    int                 count;             /* 6020: command counter */
    int                 blendA0;           /* 6024 */
    int                 blendA1;           /* 6028 */
    int                 blendB0;           /* 602C */
    int                 blendB1;           /* 6030 */
    int                 blend2Param0;         /* 6034 */
    int                 blend2Param1;         /* 6038 */
    unsigned short      step;              /* 603C: frame step counter */
    unsigned char       flip;              /* 603E: double-buffer flip */
    unsigned char       state;             /* 603F: scene state */
    unsigned long long  tick;              /* 6040: last OS tick (us) */
    unsigned long long  accum;             /* 6048: accumulated us */
    int                 result;            /* 6050: command result / state */
    int                 fade;              /* 6054: fade/wipe parameter */
    int                 finish;            /* 6058: teardown flag */
};

#endif
