#ifndef OV170_BOX2_PARAM_TYPES_H
#define OV170_BOX2_PARAM_TYPES_H

#include "../types.h"

/* Parameters the parent hands to the box application (0x2C bytes). The field event, the script command and the
   game sync event build this block; the box application reads it and writes the result words. */
typedef struct BoxParam {
    void *gameData;                 /* 0x00 */
    void *boxSave;                  /* 0x04: box manager of the save */
    void *party;                    /* 0x08: replaced by a heap copy of the battle box party when mode is 4 */
    void *myItem;                   /* 0x0C */
    u8 *myStatus;                   /* 0x10 */
    int linkMode;                   /* 0x14: 1 when the battle box is locked (set for mode 4) */
    void *config;                   /* 0x18 */
    u32 natDex;                     /* 0x1C: national dex is on; the sync picker clears it */
    u8 *pickerBuffer;               /* 0x20: block the sync picker fills */
    int mode;                       /* 0x24: 3 and 5 are the pick modes, 4 the battle box */
    u16 result;                     /* 0x28: written by the box application, 1 means success */
    u8 pickedBox;                   /* 0x2A */
    u8 pickedSlot;                  /* 0x2B */
} BoxParam;

#endif
