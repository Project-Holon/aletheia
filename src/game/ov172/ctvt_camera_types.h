#ifndef CTVT_CAMERA_TYPES_H
#define CTVT_CAMERA_TYPES_H

#include "../types.h"

struct Camera;

/* One participant window of the video chat screen: it slides from the current
 * rectangle to the target rectangle (in pixels of the 256 wide frame plane). */
typedef struct CtvtCamViewWindow {
    s32 moving;
    s32 animate;
    s32 seOnArrive;
    u16 curX;
    u16 curY;
    u16 curW;
    u16 curH;
    u16 tgtX;
    u16 tgtY;
    u16 tgtW;
    u16 tgtH;
} CtvtCamViewWindow;

/* Frame view of the video chat: composes the camera frames of up to four
 * participants into one plane and copies it to VRAM. Size 0xB4. */
typedef struct CtvtCamView {
    u16 heapId;
    u8 pad2[2];             /* alignment before the pointer */
    void *screenBuf;        /* 256x192 RGB plane copied to VRAM */
    void *noSignalFull;     /* placeholder picture, full size (ARC member 0x19) */
    void *noSignalHalf;     /* placeholder picture, half size (ARC member 0x1A) */
    u8 dirtyMask;           /* one bit per window with new pixels */
    u8 pad11[3];            /* alignment before the next word */
    s32 layoutDirty;
    s32 revealPending;
    s32 clearPending;
    u32 halfRes;
    s32 shutterReq0;
    s32 shutterReq1;
    u8 settleCount;
    u8 revealY;             /* bottom edge of the window mask, 0xC0 = fully shown */
    u8 pad2E[2];            /* alignment before the next word */
    s32 revealing;
    CtvtCamViewWindow window[4];
    struct Camera *camera;
    void *spareBufA;
    void *spareBufB;
    void *cropBuf;          /* centre crop of the last camera frame */
} CtvtCamView;

#endif
