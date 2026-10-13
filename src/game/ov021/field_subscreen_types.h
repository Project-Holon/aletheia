#ifndef FIELD_SUBSCREEN_TYPES_H
#define FIELD_SUBSCREEN_TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/*
 * Work of the field sub-screen (the lower screen panel: C-Gear and its
 * replacements): heapId at 0x0C, fieldMap at 0x14, cgear at 0x20.
 * Allocated with 0x2C bytes by FIELD_SUBSCREEN_Create.
 */
typedef struct FieldSubscreen {
    u32 mode;              /* running mode: row of the mode table */
    u32 nextMode;          /* mode that FIELD_SUBSCREEN_Main switches to */
    u32 state;             /* FIELD_SUBSCREEN_STATE_* */
    u16 heapId;
    u16 padHeap;
    u32 panelResult;       /* result posted by the panel (close, select ...) */
    void *fieldMap;
    void (*callback)(int); /* handed to the panel by mode 8 (callback mode) */
    u32 callbackArg;
    void *cgear;           /* handle of the loaded panel */
    u32 pad24[2];
} FieldSubscreen;

#endif
