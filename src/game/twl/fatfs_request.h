#ifndef GAME_TWL_FATFS_REQUEST_H
#define GAME_TWL_FATFS_REQUEST_H

#include "../types.h"

/* One command buffer.  qnext (0x0C) links it into the list that
 * FATFSi_WaitForRequest waits on; next (0x808) links the busy list. */
typedef struct FATFSCommandBuffer {
    u32 arg;
    u32 state;
    u32 mode;
    struct FATFSCommandBuffer *qnext;
    u8 buf[0x7F0];
    u32 key;
    u32 pad804;
    u32 pad808;
    struct FATFSCommandBuffer *next;
} FATFSCommandBuffer;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fatfs_request.c, prototypes copied from their definitions. */

#include "../types.h"

void FATFSi_SendToPXI(FATFSCommandBuffer *command);
u32 FATFSi_GetThreadHandle(void);
FATFSCommandBuffer *FATFSi_AllocateCommandBuffer(u32 arg);
FATFSCommandBuffer *FATFSi_AllocateEmergencyCommandBuffer(u32 arg);
void FATFSi_FreeCommandBuffer(FATFSCommandBuffer *command);
void FATFSi_PostRequest(FATFSCommandBuffer *request);
void FATFSi_WaitForRequest(FATFSCommandBuffer *request);
/* END mkheaders: generated region */

#endif
