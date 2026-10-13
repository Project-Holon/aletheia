#ifndef OV037_GIMMICK_INIT_HELPERS_TYPES_H
#define OV037_GIMMICK_INIT_HELPERS_TYPES_H

/*
 * Views of GimmickWork.work (the 32-word block of the field gimmick save) for
 * the gimmicks that the script commands of this overlay set up.  The block is
 * shared: only one gimmick is active at a time, so each gimmick overlay lays
 * its own view over it (the id argument of the accessor is not used).
 */

/* Gimmick 39 (overlay 39). */
typedef struct Gimmick39Work {
    unsigned char reserved0[0x14];
    unsigned short firstFlag;       /* 0x14 */
    unsigned short secondFlag;      /* 0x16 */
} Gimmick39Work;

/* Gimmick 40 (overlay 40): one flag, mirrored into a byte. */
typedef struct Gimmick40Work {
    int enabled;                    /* 0x00 */
    unsigned char enabledByte;      /* 0x04 */
} Gimmick40Work;

/* Gimmick 42 (overlay 42): three flags set from a bit mask. */
typedef struct Gimmick42Work {
    unsigned char flag[3];
} Gimmick42Work;

/* Gimmick 38 (overlay 38): eight switches, ten plates, seven doors. */
typedef struct Gimmick38Work {
    int switchFound[8];             /* 0x00 */
    int platePressed[10];           /* 0x20 */
    int doorOpen[7];                /* 0x48 */
} Gimmick38Work;

/* Gimmick 46 (overlay 46): three rows of three words. */
typedef struct Gimmick46Work {
    int panel[3][3];                /* 0x00 */
} Gimmick46Work;

#endif
