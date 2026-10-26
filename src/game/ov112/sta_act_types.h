#ifndef OV112_STA_ACT_TYPES_H
#define OV112_STA_ACT_TYPES_H

#include "../types.h"

struct MusPokeDrawSlot;
struct StaActBillboardImage;
struct StaActPokeElem;

typedef struct { int x,y,z; } StaActObjVec;

/* The 64-byte G3D model part shared by the light unit and the sprite elem. */
typedef struct StaActLightModel {
    u16 heap;            /* 0x00 */
    u16 pad_02;          /* 0x02 */
    u32 param;           /* 0x04 AllocElem parameter */
    u16 frame;           /* 0x08 SetModelFrame */
    u8 pad_0A[0x12];     /* 0x0A */
    struct G3dResource *resourceArc;     /* 0x1C single resource arc, 0 until created */
    struct G3dResource *arcs[3];         /* 0x20 three more resource arcs */
    struct G3dRender *render;          /* 0x2C G3D render */
    struct G3dAnime *animes[3];       /* 0x30 G3D anime records */
    void *object;        /* 0x3C G3D object */
} StaActLightModel;

/* One character slot of the light unit (32 bytes). value is the actor id
   (0 when the slot is free), color/alpha the RGB555 tint SetElemA writes,
   x/y/z the position in 20.12 fixed point and actor the CLACT handle. */
typedef struct LightActor {
    u32 value;            /* 0x00 actor id, 0 when free */
    u16 color;            /* 0x04 RGB555 tint */
    u8 alpha;             /* 0x06 tint alpha */
    u8 pad_07;            /* 0x07 */
    int x;                /* 0x08 position, 20.12 fixed point */
    int y;                /* 0x0C */
    int z;                /* 0x10 */
    int paramA;           /* 0x14 set by SetElemB, never read in decompiled code */
    int paramB;           /* 0x18 set by SetElemB, never read in decompiled code */
    void *actor;          /* 0x1C CLACT actor handle */
} LightActor;

typedef struct StaActLightObject { u16 heap,pad; void *a; LightActor entries[4]; u32 flag; u8 pad_8C[0x18]; void *actor; void *bank; u32 palette,character,cellAnim; } StaActLightObject;

/* One billboard element: position, image id and the billboard slot index. */
typedef struct StaActObjEntry {
    u32 active;          /* 0x00 */
    u32 dirty;           /* 0x04 */
    int x;               /* 0x08 */
    int y;               /* 0x0C */
    int z;               /* 0x10 */
    int id;              /* 0x14 */
    int index;           /* 0x18 billboard slot index */
} StaActObjEntry;

/* The billboard element manager the STA_ACT_OBJ_* functions operate on
   (148 bytes): heap id, element count, billboard board and 5 element slots. */
typedef struct StaActObjObject {
    u16 heap;            /* 0x00 */
    u16 count;           /* 0x02 */
    void *board;         /* 0x04 BILLBOARD board */
    StaActObjEntry entries[5]; /* 0x08 */
} StaActObjObject;


/* Animation state at StaActPokeElem + 0xF0 (16 bytes). Some animators count with an
   unsigned short and some with a signed short, so the counter is unioned. */
typedef struct { u16 count; u16 pad; int index; char *a; int b; } ElemTail;

typedef struct { short count; short pad; int index; char *a; int b; } ElemTailSigned;

/* One sprite element of a StaActBillboardImage (264 bytes). The same record is the
   3D actor the actor system hands out through STA_ACTING_GetActor. */
typedef struct StaActPokeElem {
    int value;            /* 0x00 */
    int dirty;              /* 0x04 */
    int flag;             /* 0x08 */
    int elemValue;              /* 0x0C */
    int keepUpright;              /* 0x10 */
    int noFlip;              /* 0x14 */
    int x;                /* 0x18 */
    int y;                /* 0x1C */
    int z;                /* 0x20 */
    int scaleX;           /* 0x24 */
    int scaleY;           /* 0x28 */
    int scaleZ;           /* 0x2C */
    int offsetX;              /* 0x30 */
    int offsetY;              /* 0x34 */
    int offsetZ;              /* 0x38 */
    int pivotShiftX;              /* 0x3C */
    int pivotShiftY;              /* 0x40 */
    u8 pad_44[4];         /* 0x44 */
    u16 angle;            /* 0x48 */
    u16 pad_4A;           /* 0x4A */
    int renderAnimActive;              /* 0x4C */
    u16 animTimer;              /* 0x50 */
    u16 pad_52;           /* 0x52 */
    int flipX;              /* 0x54 */
    struct MusPokeDrawSlot *renderElem; /* 0x58 */
    u32 billboardIdx;     /* 0x5C */
    struct Tagged *slotArc[9];       /* 0x60 */
    void *slotImage[9];   /* 0x84 */
    void *slotRecord[9];  /* 0xA8 */
    int slotActive[9];    /* 0xCC */
    union {
        ElemTail anim;        /* unsigned counter */
        ElemTailSigned animSigned; /* signed counter */
    } tail;               /* 0xF0 */
    u32 pad_100;          /* 0x100 */
    union {
        int active;                        /* 0x104 nonzero while an animation runs */
        void (*animFunc)(struct StaActBillboardImage *, struct StaActPokeElem *);  /* 0x104 current animator */
    } handler;            /* 0x104 */
} StaActPokeElem;

typedef struct StaActBillboardImage {
    u16 heap;             /* 0x00 */
    u16 pad_02;
    void *b;              /* 0x04 acting system */
    void *board;          /* 0x08 */
    void *renderObj;      /* 0x0C */
    void *actorPool;      /* 0x10 */
    StaActPokeElem elems[4];        /* 0x14 */
    u16 frame;            /* 0x434 */
    u16 pad_436;
    u32 image;            /* 0x438 */
    u8 count;             /* 0x43C */
    u8 pad_43D[3];
} StaActBillboardImage;


#endif
