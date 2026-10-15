#ifndef MYSTERY_GRAPHIC_SHARED_TYPES_H
#define MYSTERY_GRAPHIC_SHARED_TYPES_H

struct Cfg;

struct Obj;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

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
    void *updateTask;             /* 0x14 func_020056A0 task driving the module */
    unsigned short heapId;        /* 0x18 heap the object was allocated from */
} MysteryGraphicWork;

#endif
