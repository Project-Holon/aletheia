/*
 * g3d_system_types.h: the objects of the 3D system (g3d_system.c).
 *
 * The includer defines u8, u16, u32, fx32, VecFx32, MtxFx33, NNSFndAllocator
 * and the NitroSystem resource types named below before it includes this
 * header.
 *
 * Every object starts with a magic halfword. The delete functions check it
 * and write magic - 1 before they free the object.
 */
#ifndef G3D_SYSTEM_TYPES_H
#define G3D_SYSTEM_TYPES_H

#define G3D_RESOURCE_MAGIC 0x48BF
#define G3D_RENDER_MAGIC   0x7A14
#define G3D_ANIME_MAGIC    0x59D1
#define G3D_OBJECT_MAGIC   0x2185

/* G3dResource.type, set from the file signature */
#define G3D_RES_TYPE_NONE   0   /* unknown signature */
#define G3D_RES_TYPE_MDLTEX 1   /* BMD0 that holds a texture block */
#define G3D_RES_TYPE_MDL    2   /* BMD0 without textures */
#define G3D_RES_TYPE_TEX    3   /* BTX0 */
#define G3D_RES_TYPE_ANM    4   /* BCA0, BVA0, BMA0, BTP0, BTA0 */

/* kinds for func_02046C9C and G3D_SYSTEM_CheckResourceType */
#define G3D_RES_KIND_NONE 0
#define G3D_RES_KIND_MDL  1
#define G3D_RES_KIND_TEX  2
#define G3D_RES_KIND_ANM  3

/* A loaded NitroSystem resource file (8 bytes). */
typedef struct G3dResource {
    u16   magic;    /* G3D_RESOURCE_MAGIC */
    u16   type;     /* G3D_RES_TYPE_* */
    void *file;     /* NNSG3dResFileHeader *, owned */
} G3dResource;

/* A render object: one model of a model resource, bound to a texture resource (0x10 bytes). */
typedef struct G3dRender {
    u16              magic;     /* G3D_RENDER_MAGIC */
    NNSG3dRenderObj *rndObj;
    G3dResource     *mdlRes;
    G3dResource     *texRes;
} G3dRender;

/* One animation of an animation resource, allocated against a model (0xC bytes). */
typedef struct G3dAnime {
    u16                magic;   /* G3D_ANIME_MAGIC */
    NNSG3dAnmObj      *anmObj;
    const G3dResource *anmRes;
} G3dAnime;

/* A render object with its table of animations (0x10 bytes). */
typedef struct G3dObject {
    u16         magic;      /* G3D_OBJECT_MAGIC */
    G3dRender  *render;
    G3dAnime  **anmTbl;     /* anmCount entries, owned */
    u16         anmCount;
} G3dObject;

/* Position, scale and rotation an object is drawn with. */
typedef struct G3dObjectStatus {
    VecFx32 trans;
    VecFx32 scale;
    MtxFx33 rotate;
} G3dObjectStatus;

/*
 * Projection setup. type 0 is a perspective (the first two parameters are the
 * sine and cosine of half the field of view, the third the aspect ratio, the
 * fourth unused); types 1 and 2 are a frustum and an orthographic projection
 * (top, bottom, left, right).
 */
typedef struct G3dProjection {
    u32  type;
    fx32 fovySinOrTop;
    fx32 fovyCosOrBottom;
    fx32 aspectOrLeft;
    fx32 right;
    fx32 nearClip;
    fx32 farClip;
    fx32 scaleW;        /* 0 means FX32_ONE */
} G3dProjection;

/* One light: direction (fx16 bit patterns) and RGB555 color. */
typedef struct G3dLight {
    u16 vecX;
    u16 vecY;
    u16 vecZ;
    u16 color;
} G3dLight;

/* Camera: position, up vector and target. */
typedef struct G3dLookAt {
    VecFx32 camPos;
    VecFx32 camUp;
    VecFx32 target;
} G3dLookAt;

/* The 3D system work (0xA0 bytes, allocated by G3D_SYSTEM_Init). */
typedef struct G3dSystemWork {
    NNSFndAllocator allocator;          /* 0x00: heap allocator for render and animation objects */
    void           *plttManagerWork;    /* 0x10 */
    void           *texManagerWork;     /* 0x14 */
    u16             heapId;             /* 0x18 */
    u8              pad_1a[2];
    G3dProjection   projection;         /* 0x1C */
    G3dLight        lights[4];          /* 0x3C */
    G3dLookAt       lookAt;             /* 0x5C */
    u32             swapSortMode;       /* 0x80 */
    u32             swapBufferMode;     /* 0x84 */
    void          (*glbFlushFunc)(void);/* 0x88 */
    u32             texManagerMode;     /* 0x8C: 0 linked-list manager, else frame manager */
    u32             plttManagerMode;    /* 0x90 */
    u32             swapRequest;        /* 0x94: 1 when the frame's buffer swap is due */
    void          (*drawCallback)(NNSG3dRenderObj *rndObj, u32 arg); /* 0x98 */
    u32             drawCallbackArg;    /* 0x9C */
} G3dSystemWork;

/* The 3D system state (at 0x02146A5C). */
typedef struct G3dSystem {
    G3dSystemWork *work;
    u32            polygonCount;    /* polygons drawn since the last reset */
    u32            vertexCount;     /* vertices drawn since the last reset */
} G3dSystem;

#endif /* G3D_SYSTEM_TYPES_H */
