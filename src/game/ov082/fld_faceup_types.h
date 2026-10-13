#ifndef OV082_FLD_FACEUP_TYPES_H
#define OV082_FLD_FACEUP_TYPES_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef signed int     s32;

/* One step of a blink or lip animation: which image of the strip to show. */
typedef struct FaceupAnimFrame {
    u16 imageIndex;                     /* image number in the tile strip */
    u16 holdFrames;                     /* not read; the hold time comes from FaceupAnim.delayReload */
} FaceupAnimFrame;

/*
 * Tile animation of one face part. The step function fills tiles[] with the
 * map entries of the next image; the vblank upload copies them to BG 3.
 */
typedef struct FaceupAnim {
    int idle;                           /* 0x00 set when a cycle has finished */
    int uploadPending;                  /* 0x04 tiles[] holds a frame not yet copied to the map */
    u8 delay;                           /* 0x08 frames left before the next image */
    u8 delayReload;                     /* 0x09 delay after each image */
    u16 frame;                          /* 0x0A position in the frame list */
    u16 tiles[2][6];                    /* 0x0C map entries: upper row, lower row */
} FaceupAnim;

/* REG_BG3CNT as the bit fields the SDK macro G2_SetBG3ControlText writes. */
typedef union Bg3Control {
    u16 raw;
    struct {
        u16 priority : 2;
        u16 charBase : 4;
        u16 mosaic : 1;
        u16 colorMode : 1;
        u16 screenBase : 5;
        u16 areaOverflow : 1;
        u16 screenSize : 2;
    } bits;
} Bg3Control;

/* Work of the face-up scene (0x78 bytes), stored in the field map's face-up slot. */
typedef struct FaceupWork {
    u8 savedBgPriority[4];              /* 0x00 priorities of BG 0..3 before the scene */
    u32 savedVisiblePlanes;             /* 0x04 */
    Bg3Control savedBg3Control;         /* 0x08 */
    u8 pad0A[2];
    int faceType;                       /* 0x0C selects the portrait (0..2) */
    void *scrcmdWork;                   /* 0x10 script work that owns the message window */
    void *updateTask;                   /* 0x14 per-frame animation task */
    void *vblankTask;                   /* 0x18 vblank task that uploads the tiles */
    int lipSyncStopped;                 /* 0x1C set once the message has been printed */
    u8 pad20[4];
    u16 fadeFrame;                      /* 0x24 frame counter of the alpha fade-in */
    u16 blinkTimer;                     /* 0x26 frames until the next blink */
    FaceupAnim blink;                   /* 0x28 eyes, map offset 0x10D */
    FaceupAnim mouth;                   /* 0x4C mouth, map offset 0x16E */
    int fadeBothScreens;                /* 0x70 close with a fast fade of both screens */
    int waitingForText;                 /* 0x74 set until the message starts printing */
} FaceupWork;

#endif
