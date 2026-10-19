#ifndef ALETHEIA_OV121_MYSTERY_NET_TYPES_H
#define ALETHEIA_OV121_MYSTERY_NET_TYPES_H

/* Mystery Gift network work object (mystery_net.c, 0x17A8 bytes). */

/* One ND (Nintendo Download) file record inside the download context. */
typedef struct MysteryNetNdFileRecord {
    unsigned char data[0x93];     /* 0x00 file metadata */
    signed char hexFlags[0x1D];   /* 0x93 hex text parsed by MYSTERY_NET_ParseHexValue */
} MysteryNetNdFileRecord;

/* Nintendo Download (DWC_Nd*) context embedded at 0x60 of the work object. */
typedef struct MysteryNetNdContext {
    MysteryNetNdFileRecord records[10];  /* 0x000 10 candidate file records */
    unsigned int recordFlags[10];        /* 0x6E0 1 per record, set from hexFlags bit 21 */
    int state;                           /* 0x708 current ND state (MYSTERY_NET_SetNdState) */
    int done;                            /* 0x70C set when the caller requests the download */
    int error;                           /* 0x710 set on an ND error */
    int validCount;                      /* 0x714 number of flagged records */
    int progressRatio;                   /* 0x718 last reported progress percent */
    int progressDone;                    /* 0x71C bytes downloaded so far */
    int progressTotal;                   /* 0x720 total bytes to download */
    int selectedIndex;                   /* 0x724 record chosen for download */
    void *destBuffer;                    /* 0x728 destination of the downloaded file */
    int timer;                           /* 0x72C watchdog counter (7200 ticks) */
    int busy;                            /* 0x730 1 while an ND download is running */
} MysteryNetNdContext;                   /* 0x734 */

/*
 * Root work object of the Mystery Gift network module. Allocated by
 * MYSTERY_NET_Create (0x17A8 bytes) and driven through the handler pointer at
 * 0x00: the handler is called as handler(object, &state, handlerArg).
 */
typedef struct MysteryNetWork {
    void (*handler)(char *, char *, unsigned int); /* 0x00 active state handler */
    int paused;                          /* 0x04 when set the handler is not dispatched */
    int state;                           /* 0x08 per-handler state machine */
    unsigned int handlerArg;             /* 0x0C third argument passed to the handler */
    void *wihHandle;                     /* 0x10 WIH_DWC handle */
    unsigned char buffer[0x20];          /* 0x14 scratch buffer (MYSTERY_NET_GetBuffer) */
    unsigned char unknown34[0x20];       /* 0x34 */
    void *result;                        /* 0x54 last polled result */
    unsigned short heapId;               /* 0x58 heap the object was allocated from */
    unsigned char unknown5A[2];          /* 0x5A */
    int flag5C;                          /* 0x5C exit request flag */
    MysteryNetNdContext nd;              /* 0x60 */
    void *param;                         /* 0x794 argument passed to MYSTERY_NET_Create */
    void *beacon;                        /* 0x798 DELIVERY_BEACON handle */
    void *irc;                           /* 0x79C DELIVERY_IRC handle */
    unsigned char unknown7A0[4];         /* 0x7A0 */
    unsigned char recvBuffer[0x1000];    /* 0x7A4 downloaded payload */
    int recvState;                       /* 0x17A4 1 when recvBuffer holds a result */
} MysteryNetWork;                        /* 0x17A8 */

struct Cfg;

struct Obj;

#include "../types.h"

/* CLACT sprite renderer pair owned by the graphic module. */
typedef struct MysteryGraphicClact {
    void *unit;        /* 0x00 CLACT_CreateUnit bank */
    void *renderer;    /* 0x04 CLACT_CreateRenderer handle */
} MysteryGraphicClact;

/* G3D camera pair owned by the graphic module. */
typedef struct MysteryGraphicCamera {
    void *handle;         /* 0x00 G3D_CAMERA_Create handle */
    unsigned int enabled; /* 0x04 set to 1 once the camera is created */
} MysteryGraphicCamera;

/*
 * Root work object of the Mystery Gift 3D graphic module (mystery_graphic.c,
 * 0x1C bytes, allocated by MYSTERY_GRAPHIC_Create). It owns the BG/BMP
 * subsystem, the CLACT renderer pair and the G3D camera pair, plus the update
 * task handle and the heap the object lives in.
 */
typedef struct MysteryGraphicWork {
    unsigned int displayState;    /* 0x00 cleared while BG/BMP is created/destroyed */
    MysteryGraphicClact clact;    /* 0x04 */
    MysteryGraphicCamera camera;  /* 0x0C */
    void *updateTask;             /* 0x14 GFL_USE_AddMainTask task driving the module */
    unsigned short heapId;        /* 0x18 heap the object was allocated from */
} MysteryGraphicWork;

#endif
