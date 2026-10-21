#ifndef GAME_OV228_SAVE_OUTSIDE_H
#define GAME_OV228_SAVE_OUTSIDE_H

#include "../types.h"

/* the ov228 flash save work object (0x380 bytes) */
struct SaveOutsideWork {
    u32 magic;             /* 0x000 0xA10F49AE */
    u32 counter;           /* 0x004 save generation, newer wins */
    u16 crc;               /* 0x008 CRC over 0x00C..0x374 */
    u8 payload[0x368];     /* 0x00C */
    u32 state;             /* 0x374 0 ok, 1..3 the load outcome */
    u8 loaded;             /* 0x378 1 once a copy was loaded */
    u8 phase;              /* 0x379 async write step */
    u8 copyIndex;          /* 0x37A which flash copy is being written */
    u8 pad37B;             /* 0x37B padding, never read */
    u16 token;             /* 0x37C BACKUP_SYSTEM_WriteFlashAsync token */
    u16 pad37E;            /* 0x37E padding, never read */
};
typedef struct SaveOutsideWork SaveOutsideWork;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of save_outside.c, prototypes copied from their definitions. */

#include "../types.h"

void *SAVE_OUTSIDE_Load(u32 heap);
void SAVE_OUTSIDE_Free(void *p);
void SAVE_OUTSIDE_Prepare(SaveOutsideWork *work);
int SAVE_OUTSIDE_WriteAsync(SaveOutsideWork *work);
u8 SAVE_OUTSIDE_IsLoaded(SaveOutsideWork *work);
int SAVE_OUTSIDE_IsCorrupt(SaveOutsideWork *work);
void *SAVE_OUTSIDE_GetPayload(SaveOutsideWork *work);
void SAVE_OUTSIDE_CopyPayload(SaveOutsideWork *work, void *ctrl);
void SAVE_OUTSIDE_ClearFlash(u32 heap);
/* END mkheaders: generated region */

#endif
