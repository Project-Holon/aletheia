#ifndef WF2DMAP_OBJ_TYPES_H
#define WF2DMAP_OBJ_TYPES_H

/*
 * Shared types of the 2D map object layer of ov127: wf2dmap_map.c,
 * wf2dmap_obj.c (currently merged into wf2dmap_map.c), wf2dmap_objcmd.c
 * and wf2dmap_objdraw.c.
 */

/* One 2D map object (0x18 bytes); slots are read and written through the
 * get/set slot helpers in wf2dmap_obj.c. */
typedef struct Wf2dmapObj {
    unsigned int active;            /* 0x00: 1 when the slot is in use */
    short posX;                     /* 0x04 (slot 0) */
    short posY;                     /* 0x06 (slot 1) */
    short destX;                    /* 0x08 (slot 2) */
    short destY;                    /* 0x0A (slot 3) */
    unsigned short id;              /* 0x0C (slot 4) */
    unsigned short kind;            /* 0x0E (slot 7) */
    unsigned short step;            /* 0x10 (slot 8) */
    unsigned short stepCount;       /* 0x12 (slot 9) */
    unsigned char variant;          /* 0x14 (slot 6) */
    unsigned char command;          /* 0x15 (slot 5) */
    unsigned short updateCounter;   /* 0x16 (slot 10) */
} Wf2dmapObj;

/* Signed 16-bit point. */
typedef struct Wf2dmapPos {
    short x;
    short y;
} Wf2dmapPos;

/* Unsigned 16-bit pair passed by value to the position setters. */
typedef struct Wf2dmapPairU16 {
    unsigned short x;
    unsigned short y;
} Wf2dmapPairU16;

#endif
