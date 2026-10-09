/*
 * file:     button_man_p04.c
 * unit:     yes
 * function: func_0205312C, func_02053218, func_02053A60
 * address:  0x0205312C
 * region:   arm9
 * compiler: dsi/../1.2/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02053D2C  0x02053D2C  arm
 *   func_02053D30  0x02053D30  arm
 *   func_0205429C  0x0205429C  arm
 *   func_02054A68  0x02054A68  arm
 *   func_02055498  0x02055498  arm
 *   func_02055FD4  0x02055FD4  arm
 *   MTX_MultVec33          0x0207B51C  arm
 *   MTX_MultVec43          0x0207BC08  arm
 *   VEC_CrossProduct       0x0207CAE8  arm
 *   VEC_Normalize          0x0207CCA4  arm
 *   VEC_DotProduct         0x0207CA68  arm
 *   G3_MultMtx43           0x0207D918  arm
 *   MI_Copy36B             0x02082B60  arm
 *   SPLUtil_DrawXYPlane    0x020565C8  arm
 *   SPLUtil_DrawXZPlane    0x0205650C  arm
 *   FX_SinCosTable_        0x020A1B38  data
 *   SPLList_Erase          0x02058300  arm
 *   SPLList_PushFront      0x020583CC  arm
 *   SPLAnim_Scale          0x02057E68  arm
 *   SPLAnim_Color          0x02057C9C  arm
 *   SPLAnim_Alpha          0x02057BC0  arm
 *   SPLAnim_Texture        0x02057B5C  arm
 *   SPLAnim_ChildScale     0x02057B10  arm
 *   SPLAnim_ChildAlpha     0x02057AB8  arm
 *   SPLEmitter_EmitParticles 0x020569A4  arm
 *   SPLEmitter_EmitChildren  0x02056684  arm
 *   _s32_div_f             0x0209C0A4  arm
 */
#define NULL ((void *)0)
#define FX32_SHIFT 12
#define FX32_ONE ((fx32)0x00001000L)
#define FX32_HALF ((fx32)0x00000800L)
#define FX32_DEC_MASK 0x00000fff
#define FX16_ONE ((fx16)0x1000)
#define FX32_CAST(x) ((fx32)(x))
#define FX32_CONST(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))
#define FX_MUL(v1, v2) FX32_CAST(((fx64)(v1) * (v2) + 0x800LL) >> FX32_SHIFT)
#define FX32_SQRT1_3 ((fx32)0x93d)
#define reg_G3_MTX_IDENTITY    (*(volatile u32 *)0x04000454)
#define reg_G3_MTX_TRANS       (*(volatile u32 *)0x04000470)
#define reg_G3_COLOR           (*(volatile u32 *)0x04000480)
#define reg_G3_POLYGON_ATTR    (*(volatile u32 *)0x040004A4)
#define GX_RGB_R_SHIFT (0)
#define GX_RGB_R_MASK (0x001f)
#define GX_RGB_G_SHIFT (5)
#define GX_RGB_G_MASK (0x03e0)
#define GX_RGB_B_SHIFT (10)
#define GX_RGB_B_MASK (0x7c00)
#define GX_RGB(r, g, b) ((GXRgb)(((r) << GX_RGB_R_SHIFT) | ((g) << GX_RGB_G_SHIFT) | ((b) << GX_RGB_B_SHIFT)))
#define GX_RGB_R_(rgb) (rgb & GX_RGB_R_MASK)
#define GX_RGB_G_(rgb) (rgb & GX_RGB_G_MASK)
#define GX_RGB_B_(rgb) (rgb & GX_RGB_B_MASK)
#define GX_LIGHTMASK_NONE 0
#define GX_PACK_POLYGONATTR_PARAM(light, polyMode, cullMode, polygonID, alpha, misc) \
    ((u32)(((light) << 0) | ((polyMode) << 4) | ((cullMode) << 6) | (misc) | ((polygonID) << 24) | ((alpha) << 16)))
#define SPL_TEX_ANIM_MAX_FRAMES 8
#define gSPLRandomState g_02146A8C
#define FALSE 0
#define ANIM_FUNC_NO_LOOP 0
#define ANIM_FUNC_LOOP    1
struct SPLParticle;
struct SPLEmitter;
struct S;
struct SPLManager;
struct SPLTexture;
typedef unsigned char u8;

typedef short s16_02053A60;

typedef unsigned short u16;

typedef int s32_02053A60;

typedef unsigned int u32;

struct Res0
{
  u32 f00;
  s32_02053A60 f04;
  s32_02053A60 f08;
  s32_02053A60 f0c;
  s32_02053A60 f10;
  s32_02053A60 f14;
  s32_02053A60 f18;
  u16 f1c;
  u16 f1e;
  u16 f20;
  u16 f22;
  s32_02053A60 f24;
  s32_02053A60 f28;
  s32_02053A60 f2c;
  s32_02053A60 f30;
  s32_02053A60 f34;
  u16 f38;
  u16 f3a;
  u16 f3c;
  u16 f3e;
  s32_02053A60 f40;
  u8 f44;
  u8 f45;
  u8 f46;
  u8 f47;
  u32 f48;
  u32 f4c;
};

struct Sub14
{
  s32_02053A60 f00;
  s32_02053A60 f04;
  s32_02053A60 f08;
  s32_02053A60 f0c;
  u32 f10;
};

struct Cfg
{
  struct Res0 *f00;
  s32_02053A60 f04;
  s32_02053A60 f08;
  s32_02053A60 f0c;
  s32_02053A60 f10;
  struct Sub14 *f14;
};

struct Vec3
{
  s32_02053A60 x;
  s32_02053A60 y;
  s32_02053A60 z;
};

struct Obj_02053A60
{
  s32_02053A60 f00;
  s32_02053A60 f04;
  s32_02053A60 f08;
  s32_02053A60 f0c;
  s32_02053A60 f10;
  s32_02053A60 f14;
  s32_02053A60 f18;
  s32_02053A60 f1c;
  struct Cfg *f20;
  s32_02053A60 f24;
  s32_02053A60 f28;
  s32_02053A60 f2c;
  s32_02053A60 f30;
  s32_02053A60 f34;
  s32_02053A60 f38;
  s32_02053A60 f3c;
  s32_02053A60 f40;
  s32_02053A60 f44;
  s32_02053A60 f48;
  u16 f4c;
  u16 f4e;
  u16 f50;
  u16 f52;
  u16 f54;
  u16 f56;
  s32_02053A60 f58;
  s32_02053A60 f5c;
  s32_02053A60 f60;
  s32_02053A60 f64;
  s32_02053A60 f68;
  s32_02053A60 f6c;
  u16 f70;
  u16 f72;
  u32 f74;
  s16_02053A60 f78;
  s16_02053A60 f7a;
  s16_02053A60 f7c;
  s16_02053A60 f7e;
  u32 f80;
  s32_02053A60 f84;
  s32_02053A60 f88;
  s32_02053A60 f8c;
  s32_02053A60 f90;
  s32_02053A60 f94;
  s32_02053A60 f98;
};

typedef unsigned long long u64;

typedef signed char s8;

typedef signed short s16_0205312C;

typedef signed int s32_0205312C;

typedef signed long long s64;

typedef s32_0205312C fx32;

typedef s16_0205312C fx16;

typedef s64 fx64;

typedef u16 GXRgb;

typedef int BOOL;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct { fx16 x, y, z; } VecFx16;

typedef struct { fx32 m[4][3]; } MtxFx43;

typedef struct { fx32 m[3][3]; } MtxFx33;

typedef u32 GXPolygonAttrMisc;

typedef enum { GX_POLYGONMODE_MODULATE = 0 } GXPolygonMode;

typedef enum { GX_CULL_ALL = 0, GX_CULL_FRONT = 1, GX_CULL_BACK = 2, GX_CULL_NONE = 3 } GXCull;

typedef struct SPLBehavior {
    void (*applyFunc)(const void *, struct SPLParticle *, VecFx32 *, struct SPLEmitter *);
    const void *object;
} SPLBehavior;

enum SPLDrawType {
    SPL_DRAW_TYPE_BILLBOARD = 0,
    SPL_DRAW_TYPE_DIRECTIONAL_BILLBOARD,
    SPL_DRAW_TYPE_POLYGON,
    SPL_DRAW_TYPE_DIRECTIONAL_POLYGON,
    SPL_DRAW_TYPE_DIRECTIONAL_POLYGON_CENTER,
};

enum SPLCircleAxis {
    SPL_CIRCLE_AXIS_Z = 0,
    SPL_CIRCLE_AXIS_Y,
    SPL_CIRCLE_AXIS_X,
    SPL_CIRCLE_AXIS_EMITTER,
};

enum SPLEmissionType {
    SPL_EMISSION_TYPE_POINT = 0, // A single point
    SPL_EMISSION_TYPE_SPHERE_SURFACE, // Any point on the surface of a sphere
    SPL_EMISSION_TYPE_CIRCLE_BORDER, // Any point on a circle around an axis (specified by flags)
    SPL_EMISSION_TYPE_CIRCLE_BORDER_UNIFORM, // Uniform distribution of points on a circle around an axis (specified by flags)
    SPL_EMISSION_TYPE_SPHERE, // Any point inside a sphere
    SPL_EMISSION_TYPE_CIRCLE, // Any point inside a circle around an axis (specified by flags)
    SPL_EMISSION_TYPE_CYLINDER_SURFACE, // Any point on the surface of a cylinder
    SPL_EMISSION_TYPE_CYLINDER, // Any point inside a cylinder
    SPL_EMISSION_TYPE_HEMISPHERE_SURFACE, // Any point on the surface of a hemisphere (direction specified by flags)
    SPL_EMISSION_TYPE_HEMISPHERE, // Any point inside a hemisphere (direction specified by flags)
};

enum SPLChildRotationType {
    SPL_CHILD_ROT_NONE = 0,
    SPL_CHILD_ROT_INHERIT_ANGLE,
    SPL_CHILD_ROT_INHERIT_ANGLE_AND_VELOCITY,
};

enum SPLScaleAnimDir {
    SPL_SCALE_ANIM_DIR_XY = 0,
    SPL_SCALE_ANIM_DIR_X,
    SPL_SCALE_ANIM_DIR_Y,
};

enum SPLPolygonRotAxis {
    SPL_POLYGON_ROT_AXIS_Y = 0,
    SPL_POLYGON_ROT_AXIS_XYZ,
};

typedef struct SPLFileHeader {
    u32 magic;
    u32 version;
    u16 resCount;
    u16 texCount;
    u32 reserved0;
    u32 resSize;
    u32 texSize;
    u32 texOffset;
    u32 reserved1;
} SPLFileHeader;

typedef union SPLResourceFlags {
    u32 all;
    struct {
        u32 emissionType : 4; // Maps to SPLEmissionType
        u32 drawType : 2;
        u32 circleAxis : 2; // Maps to SPLCircleAxis
        u32 hasScaleAnim : 1;
        u32 hasColorAnim : 1;
        u32 hasAlphaAnim : 1;
        u32 hasTexAnim : 1;
        u32 hasRotation : 1;
        u32 randomInitAngle : 1;
        // Whether the emitter manages itself or not.
        // If set, the emitter will automatically terminate when it reaches the end of its life
        // and all of its particles have died
        u32 selfMaintaining : 1;
        u32 followEmitter : 1;
        u32 hasChildResource : 1;
        u32 polygonRotAxis : 2; // The axis to rotate the polygon around when using the 'polygon' draw types
        u32 polygonReferencePlane : 1;
        u32 randomizeLoopedAnim : 1;
        u32 drawChildrenFirst : 1; // If set, child particles will be rendered before parent particles
        u32 hideParent : 1; // If set, only child particles will be rendered
        u32 useViewSpace : 1; // If set, the rendering calculations will be done in view space
        u32 hasGravityBehavior : 1;
        u32 hasRandomBehavior : 1;
        u32 hasMagnetBehavior : 1;
        u32 hasSpinBehavior : 1;
        u32 hasCollisionPlaneBehavior : 1;
        u32 hasConvergenceBehavior : 1;
        u32 hasFixedPolygonID : 1;
        u32 childHasFixedPolygonID : 1;
    };
} SPLResourceFlags;

typedef union SPLChildResourceFlags {
    u16 all;
    struct {
        u16 usesBehaviors : 1;
        u16 hasScaleAnim : 1;
        u16 hasAlphaAnim : 1;
        u16 rotationType : 2;
        u16 followEmitter : 1;
        u16 useChildColor : 1;
        u16 drawType : 2;
        u16 polygonRotAxis : 2;
        u16 polygonReferencePlane : 1;
        u16 : 4;
    };
} SPLChildResourceFlags;

typedef union SPLCurveInOut {
    u16 all;
    struct {
        u16 in : 8;
        u16 out : 8;
    };
} SPLCurveInOut;

typedef union SPLCurveInPeakOut {
    u32 all;
    struct {
        u32 in : 8;
        u32 peak : 8;
        u32 out : 8;
        u32 : 8;
    };
} SPLCurveInPeakOut;

typedef struct SPLResourceHeader {
    SPLResourceFlags flags;
    VecFx32 emitterBasePos;
    fx32 emissionCount; // Number of particles to emit per emission interval
    fx32 radius; // Used for circle, sphere, and cylinder emissions
    fx32 length; // Used for cylinder emission
    VecFx16 axis;
    GXRgb color;
    fx32 initVelPosAmplifier;
    fx32 initVelAxisAmplifier;
    fx32 baseScale;
    fx16 aspectRatio;
    u16 startDelay; // Delay, in frames, before the emitter starts emitting particles
    s16_0205312C minRotation;
    s16_0205312C maxRotation;
    u16 initAngle;
    u16 reserved;
    u16 emitterLifeTime;
    u16 particleLifeTime;

    // All of these values are mapped to the range [0, 1]
    // They are used to attenuate the particle's properties at initialization,
    // acting as a sort of randomization factor which scales down the initial values
    struct {
        u32 baseScale : 8; // Damping factor for the base scale of the particles (0 = no damping)
        u32 lifeTime : 8;
        u32 initVel : 8; // Attenuation factor for the initial velocity of the particles (0 = no attenuation)
        u32 : 8;
    } randomAttenuation;

    struct {
        u32 emissionInterval : 8;
        u32 baseAlpha : 8;
        u32 airResistance : 8;
        u32 textureIndex : 8;
        u32 loopFrames : 8;
        u32 dbbScale : 16;
        u32 textureTileCountS : 2; // Number of times to tile the texture in the S direction
        u32 textureTileCountT : 2; // Number of times to tile the texture in the T direction
        u32 scaleAnimDir : 3; // Maps to SPLScaleAnimDir
        u32 dpolFaceEmitter : 1; // If set, the polygon will face the emitter
        u32 flipTextureS : 1;
        u32 flipTextureT : 1;
        u32 : 30;
    } misc;
    fx16 polygonX;
    fx16 polygonY;
    struct {
        u32 flags : 8;
        u32 : 24;
    } userData;
} SPLResourceHeader;

typedef struct SPLScaleAnim {
    fx16 start;
    fx16 mid;
    fx16 end;
    SPLCurveInOut curve;
    struct {
        u16 loop : 1;
        u16 : 15;
    } flags;
    u16 padding;
} SPLScaleAnim;

typedef struct SPLColorAnim {
    GXRgb start;
    GXRgb end;
    SPLCurveInPeakOut curve;
    struct {
        u16 randomStartColor : 1;
        u16 loop : 1;
        u16 interpolate : 1;
        u16 : 13;
    } flags;
    u16 padding;
} SPLColorAnim;

typedef struct SPLAlphaAnim {
    union {
        u16 all;
        struct {
            u16 start : 5;
            u16 mid : 5;
            u16 end : 5;
            u16 : 1;
        };
    } alpha;
    struct {
        u16 randomRange : 8;
        u16 loop : 1;
        u16 : 7;
    } flags;
    SPLCurveInOut curve;
    u16 padding;
} SPLAlphaAnim;

typedef struct SPLTexAnim {
    u8 textures[SPL_TEX_ANIM_MAX_FRAMES];
    struct {
        u32 frameCount : 8;
        u32 step : 8; // Number of frames between each texture frame
        u32 randomizeInit : 1; // Randomize the initial texture frame
        u32 loop : 1;
        u32 : 14;
    } param;
} SPLTexAnim;

typedef struct SPLChildResource {
    SPLChildResourceFlags flags;
    fx16 randomInitVelMag; // Randomization factor for the initial velocity magnitude (0 = no randomization)
    fx16 endScale; // For scaling animations
    u16 lifeTime;
    u8 velocityRatio; // Ratio of the parent particle's velocity to inherit (255 = 100%)
    u8 scaleRatio; // Ratio of the parent particle's scale to inherit (255 = 100%)
    GXRgb color;
    struct {
        u32 emissionCount : 8; // Number of particles to emit per emission interval
        u32 emissionDelay : 8; // Delay, as a fraction of the particle's lifetime, before the particle starts emitting
        u32 emissionInterval : 8;
        u32 texture : 8;
        u32 textureTileCountS : 2;
        u32 textureTileCountT : 2;
        u32 flipTextureS : 1;
        u32 flipTextureT : 1;
        u32 dpolFaceEmitter : 1; // If set, the polygon will face the emitter
        u32 : 25;
    } misc;
} SPLChildResource;

typedef struct SPLResource {
    SPLResourceHeader *header;
    SPLScaleAnim *scaleAnim;
    SPLColorAnim *colorAnim;
    SPLAlphaAnim *alphaAnim;
    SPLTexAnim *texAnim;
    SPLChildResource *childResource;
    SPLBehavior *behaviors;
    u16 behaviorCount;
    u16 reserved;
} SPLResource;

typedef struct SPLParticle {
    struct SPLParticle *next;
    struct SPLParticle *prev;
    VecFx32 position; // position of the particle, relative to the emitter
    VecFx32 velocity;
    u16 rotation;
    s16_0205312C angularVelocity;
    u16 lifeTime;
    u16 age;

    // These two values are essentially 1.0f / lifeTime (or 1.0f / loopTime), represented as an integer
    // They are used to map between age/lifeTime and a [0, 255] range
    // Mainly just to lower the amount of divisions needed in the update functions
    u16 loopTimeFactor;
    u16 lifeTimeFactor;

    u8 texture; // Index of the current texture in the resource

    // A value between 0 and 255 that is added to the life rate of the particle.
    // This is used only for looping particles, so particles spawned at the same time
    // don't have aren't all in sync (animation-wise)
    u8 lifeRateOffset;

    struct {
        u16 baseAlpha : 5;
        u16 animAlpha : 5;
        u16 currentPolygonID : 6;
    } visibility;
    fx32 baseScale;
    fx16 animScale;
    GXRgb color;
    VecFx32 emitterPos;
} SPLParticle;

typedef struct SPLParticleList {
    SPLParticle *first;
    int count;
    SPLParticle *last;
} SPLParticleList;

enum SPLUpdateCallbackType {
    SPL_CALLBACK_PRE_UPDATE = 0,
    SPL_CALLBACK_POST_UPDATE = 1,
};

typedef void (*SPLEmitterUpdateCallback)(struct SPLEmitter *emitter, enum SPLUpdateCallbackType type);

typedef struct SPLEmitterState {
    union {
        u32 all;
        struct
        {
            u32 terminate : 1;
            u32 emissionPaused : 1;
            u32 paused : 1;
            u32 renderingDisabled : 1;
            u32 started : 1;
            u32 : 27;
        };
    };
} SPLEmitterState;

typedef struct SPLEmitter {
    struct SPLEmitter *next;
    struct SPLEmitter *prev;
    SPLParticleList particles;
    SPLParticleList childParticles;
    SPLResource *resource;
    SPLEmitterState state;
    VecFx32 position;
    VecFx32 velocity;
    VecFx32 particleInitVelocity;
    u16 age;
    fx16 emissionCountFractional; // fractional part of the number of particles to emit (doesn't seem to be used)
    VecFx16 axis;
    u16 initAngle;
    fx32 emissionCount;
    fx32 radius;
    fx32 length;
    fx32 initVelPositionAmplifier; // amplifies the initial velocity of the particles based on their position
    fx32 initVelAxisAmplifier; // amplifies the initial velocity of the particles based on the emitter's axis
    fx32 baseScale; // base scale of the particles
    u16 particleLifeTime;
    GXRgb color;
    fx32 collisionPlaneHeight;
    fx16 textureS;
    fx16 textureT;
    fx16 childTextureS;
    fx16 childTextureT;
    struct {
        u32 emissionInterval : 8; // number of frames between particle emissions
        u32 baseAlpha : 8;
        u32 updateCycle : 3; // 0 = every frame, 1 = cycle A, 2 = cycle B, cycles A and B alternate
        u32 reserved : 13;
    } misc;
    VecFx16 crossAxis1;
    VecFx16 crossAxis2;
    SPLEmitterUpdateCallback updateCallback;

    // Fields that the game can use for custom data
    void *userDataPtr;
    union {
        u32 u32;
        u16 u16[2];
        u8 u8[4];
    } userData;
} SPLEmitter;

typedef struct SPLEmitterList {
    SPLEmitter *first;
    int count;
    SPLEmitter *last;
} SPLEmitterList;

typedef union SPLTextureParam {
    u32 all;
    struct {
        u32 format : 4; // Maps to GXTexFmt
        u32 s : 4; // Maps to GXTexSizeS
        u32 t : 4; // Maps to GXTexSizeT
        u32 repeat : 2; // Maps to GXTexRepeat
        u32 flip : 2; // Maps to GXTexFlip
        u32 palColor0 : 1; // Maps to GXTexPlttColor0
        u32 useSharedTexture : 1;
        u32 sharedTexID : 8;
        u32 : 6;
    };
} SPLTextureParam;

typedef struct SPLTextureResource {
    u32 id;
    SPLTextureParam param;
    u32 textureSize; // size of the texture data
    u32 paletteOffset; // offset to the palette data from the start of the header
    u32 paletteSize; // size of the palette data
    u32 unused0;
    u32 unused1;
    u32 resourceSize; // total size of the resource (header + data)
} SPLTextureResource;

typedef struct SPLTexture {
    const void *resource;
    u32 texAddr; // VRAM address of the texture
    u32 palAddr; // VRAM address of the palette
    SPLTextureParam param;
    u16 width;
    u16 height;
} SPLTexture;

typedef void *(*SPLAllocFunc)(u32);

enum SPLDrawOrder {
    SPL_DRAW_ORDER_REVERSE = 0,
    SPL_DRAW_ORDER_NORMAL = 1,
};

typedef struct SPLManager {
    SPLAllocFunc alloc;
    SPLEmitterList activeEmitters;
    SPLEmitterList inactiveEmitters;
    SPLParticleList inactiveParticles;
    SPLResource *resources;
    SPLTexture *textures;
    u16 resCount;
    u16 texCount;
    u16 maxEmitters;
    u16 maxParticles;
    struct {
        u32 min : 6;
        u32 max : 6;
        u32 current : 6;
        u32 fix : 6;
        u32 drawOrder : 1;
        u32 unused : 7;
    } polygonID;
    GXPolygonAttrMisc miscPolygonAttr;
    struct {
        SPLEmitter *emitter; // current emitter being processed
        const MtxFx43 *viewMatrix; // current view matrix
    } renderState;
    u16 currentCycle;
    u16 reserved;
} SPLManager;

typedef struct FieldFunc {
    void (*func)(SPLParticle *, SPLResource *, int);
    BOOL loop;
} AnimFunc;

typedef struct SPLNode { struct SPLNode *next; struct SPLNode *prev; } SPLNode;

typedef struct SPLList { SPLNode *first; int count; SPLNode *last; } SPLList;

struct Node {
    struct Node *next;
    u32 pad[10];
    u8 f2c;
};

struct Desc {
    u32 flags;
    u8 pad[0x43];
    u8 f47;
};

struct Sub {
    struct Desc *f00;
};

struct Blk {
    u32 pad0[2];
    struct Node *f08;
    u32 pad1[5];
    struct Sub *f20;
};

struct Obj_0205312C {
    u32 pad0[11];
    void *f2c;
    u32 pad1[4];
    struct Blk *f40;
};

typedef void (*Fn)(struct Obj_0205312C *, struct Node *);

typedef void (*Fn1)(void *);

extern void VEC_Fx16CrossProduct(const VecFx16 *a, const VecFx16 *b, VecFx16 *axb);
extern fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);
extern void VEC_Normalize(const VecFx32 *pSrc, VecFx32 *pDst);
extern void G3_MultMtx43(const MtxFx43 *m);
extern void MI_Copy36B(const void *pSrc, void *pDst);
extern void MTX_MultVec43(const VecFx32 *vec, const MtxFx43 *m, VecFx32 *dst);
extern void MTX_MultVec33(const VecFx32 *vec, const MtxFx33 *m, VecFx32 *dst);
extern void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern void SPLUtil_DrawXYPlane(fx16 s, fx16 t, fx16 offsetX, fx16 offsetY);
extern void SPLUtil_DrawXZPlane(fx16 s, fx16 t, fx16 offsetX, fx16 offsetZ);
extern SPLNode *SPLList_Erase(SPLList *list, SPLNode *node);
extern void SPLList_PushFront(SPLList *list, SPLNode *node);
extern void SPLAnim_Scale(SPLParticle *ptcl, SPLResource *res, int lifeRate);
extern void SPLAnim_Color(SPLParticle *ptcl, SPLResource *res, int lifeRate);
extern void SPLAnim_Alpha(SPLParticle *ptcl, SPLResource *res, int lifeRate);
extern void SPLAnim_Texture(SPLParticle *ptcl, SPLResource *res, int lifeRate);
extern void SPLAnim_ChildScale(SPLParticle *ptcl, SPLResource *res, int lifeRate);
extern void SPLAnim_ChildAlpha(SPLParticle *ptcl, SPLResource *res, int lifeRate);
extern void SPLEmitter_EmitParticles(SPLEmitter *emtr, SPLParticleList *list);
extern void SPLEmitter_EmitChildren(SPLParticle *ptcl, SPLEmitter *emtr, SPLParticleList *list);
extern void func_02053D2C(void);
extern void func_02053D30(struct SPLTexture *tex);
extern void func_0205429C(struct Obj_0205312C *obj, struct S *s);
extern void func_02054A68(struct Obj_0205312C *obj, struct S *s);
extern void func_02055498(struct SPLManager *mgr, struct SPLParticle *ptcl);
extern void func_02055FD4(struct Obj_0205312C *obj, struct S *s);
void func_02053A60(volatile struct Obj_02053A60 *o, struct Cfg *cfg, const struct Vec3 *pos);
void func_02053218(SPLManager *mgr, SPLEmitter *emtr);
void func_0205312C(struct Obj_0205312C *o);
extern const fx16 FX_SinCosTable_[];
extern u32 g_02146A8C;

/*
 * The particle/rig emitter-instance initialiser: copies a resource
 * descriptor's fields into a live instance block, offsetting the instance's
 * position by the descriptor's own offset, and turning two pairs of 2-bit
 * scale-exponent fields plus their sign bits into the four s16 scale values
 * at +0x78..+0x7e.
 *
 * THIS CLOSES docs/notes/pkt_02053A60.c.txt, which concluded the row was an
 * unresolvable "arm7tdmi epilogue versus v5TE smulbb" conflict.  It is not a
 * conflict: the note only ever measured 1.1p1, where the row is 708 bytes /
 * 66 out at arm946e and 712 / 73 at arm7tdmi.  Under THIS RANGE'S FAMILY PIN,
 * `../1.2/sp2 -proc arm946e`, the note's own source is 716/716 with 17
 * concrete bytes out, and both horns of the supposed conflict vanish at once:
 * 1.2 emits the ARMv4T `pop {r4, r5, r6, lr}; bx lr` return AND the four
 * `smulbb` from `(s16)(x * -1)`.  Same tell as the rest of the
 * 0x0205429C..0x020584E0 3D-rig unit (docs/FRONTEND-PINS.md).
 *
 * THREE SPELLINGS ARE LOAD-BEARING on top of the note's source, the last two
 * found by tools/permuter.py (--mode anneal --focus pos,f28,f2c,f30,cfg,
 * EXACT at compile 321 from a 13-byte residue):
 *   1. `volatile struct Res0 *r` for the cached descriptor pointer around the
 *      +0x50/+0x52/+0x54 halfword copies.  Without volatile the two `ldrh`
 *      for f1c/f1e swap registers (the note's residue, 4 instructions).
 *   2. `const struct Vec3 *pos`, NOT `const volatile`.  With volatile the
 *      three position adds and the descriptor chain that feeds them are 10
 *      instructions of register naming out.
 *   3. `pos->x + o->f20->f00->f04`, position FIRST.  Field-first is the
 *      note's order and costs the same 10 instructions in the other
 *      direction (cmp/commutative operand order names the temporary).
 * The rest of the source, the every-time re-read of `o->f20->f00` for each
 * copied field, the `volatile struct Obj *o`, and `(s16)(x * -1)` for the
 * sign flips, is the note's and is unchanged.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02053A60.c \
 *       --func func_02053A60 --addr 0x02053A60 --arm --cc ../1.2/sp2
 */
void func_02053A60(volatile struct Obj_02053A60 *o, struct Cfg *cfg, const struct Vec3 *pos)
{
  volatile struct Res0 *r;
  struct Cfg *c;
  o->f20 = cfg;
  o->f24 = 0;
  o->f28 = pos->x + o->f20->f00->f04;
  o->f2c = pos->y + o->f20->f00->f08;
  o->f30 = pos->z + o->f20->f00->f0c;
  o->f40 = 0;
  o->f44 = 0;
  o->f48 = 0;
  o->f3c = 0;
  o->f38 = o->f3c;
  o->f34 = o->f38;
  o->f4c = 0;
  o->f4e = 0;
  r = o->f20->f00;
  {
    u16 h0 = r->f1c;
    u16 h1 = r->f1e;
    o->f50 = h0;
    o->f52 = h1;
  }
  o->f54 = r->f20;
  o->f56 = o->f20->f00->f38;
  o->f58 = o->f20->f00->f10;
  o->f5c = o->f20->f00->f14;
  o->f60 = o->f20->f00->f18;
  o->f64 = o->f20->f00->f24;
  o->f68 = o->f20->f00->f28;
  o->f6c = o->f20->f00->f2c;
  o->f70 = o->f20->f00->f3e;
  o->f72 = 0x7fff;
  *((u8 *) (&o->f80)) = o->f20->f00->f44;
  *(((u8 *) (&o->f80)) + 1) = o->f20->f00->f45;
  o->f80 = o->f80 & (~0x70000u);
  o->f80 = o->f80 & 0x0007ffffu;
  o->f74 = 0x80000000u;
  o->f78 = (s16_02053A60) (0x1000 << ((o->f20->f00->f48 << 6) >> 30));
  o->f7a = (s16_02053A60) (0x1000 << ((o->f20->f00->f48 << 4) >> 30));
  if ((o->f20->f00->f4c << 31) >> 31)
    o->f78 = (s16_02053A60) (o->f78 * (-1));
  if ((o->f20->f00->f4c << 30) >> 31)
    o->f7a = (s16_02053A60) (o->f7a * (-1));
  c = o->f20;
  if ((c->f00->f00 << 15) >> 31)
  {
    {
      s32_02053A60 t = c->f14->f10;
      s32_02053A60 u = t << 30;
      o->f7c = (s16_02053A60) (0x1000 << (((u32) u) >> 30));
    }
    o->f7e = (s16_02053A60) (0x1000 << ((o->f20->f14->f10 << 28) >> 30));
    if ((o->f20->f14->f10 << 27) >> 31)
      o->f7c = (s16_02053A60) (o->f7c * (-1));
    if ((o->f20->f14->f10 << 26) >> 31)
      o->f7e = (s16_02053A60) (o->f7e * (-1));
  }
  o->f04 = 0;
  o->f00 = o->f04;
  o->f14 = 0;
  o->f08 = o->f14;
  o->f18 = 0;
  o->f0c = o->f18;
  o->f90 = 0;
  o->f94 = 0;
  o->f98 = 0;
}


static inline fx16 FX_SinIdx(int idx) { return FX_SinCosTable_[((idx >> 4) << 1)]; }


static inline fx16 FX_CosIdx(int idx) { return FX_SinCosTable_[((idx >> 4) << 1) + 1]; }


static inline void G3_PolygonAttr(int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID, int alpha, int misc)
{
    reg_G3_POLYGON_ATTR = GX_PACK_POLYGONATTR_PARAM(light, polyMode, cullMode, polygonID, alpha, misc);
}


static inline void G3_Identity(void) { reg_G3_MTX_IDENTITY = 0; }


static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    reg_G3_MTX_TRANS = (u32)x;
    reg_G3_MTX_TRANS = (u32)y;
    reg_G3_MTX_TRANS = (u32)z;
}


static inline void G3_Color(GXRgb rgb) { reg_G3_COLOR = (u32)(rgb); }


static inline void MTX_Copy43To33(const MtxFx43 *pSrc, MtxFx33 *pDst) { MI_Copy36B(pSrc, pDst); }





/**
 * @brief Generates a random number
 */
static inline u32 SPLRandom_Next()
{
    gSPLRandomState = gSPLRandomState * 0x5eedf715 + 0x1b0cb173;
    return gSPLRandomState;
}



/**
 * @brief Generates a random number in the range [0, 2^bits)
 * @param bits The number of bits to generate
 */
static inline u32 SPLRandom_U32(u32 bits)
{
    return SPLRandom_Next() >> (sizeof(u32) * 8 - bits);
}



static inline s32_0205312C SPLRandom_S32(u32 bits)
{
    return (s32_0205312C)(SPLRandom_Next() >> (sizeof(u32) * 8 - bits));
}



static inline fx32 SPLRandom_FX32(u32 bits)
{
    return (fx32)SPLRandom_Next() >> (sizeof(u32) * 8 - bits);
}



/**
 * @brief Generates a random number in the range [num * (1 - range), num)
 * @param num The number to scale, can be both an integer or a fixed-point number
 * @param range The range to scale the number by, integer in the range [0, 255], which maps to [0, 1]
 */
#define SPLRandom_ScaledRangeFX32(num, range) (((num) * (255 - (((range) * (fx32)SPLRandom_U32(8)) >> 8))) >> 8)



/**
 * @brief Generates a random number in the range [num * (1 - range), num * 2 * (1 - range))
 * @param num The number to scale, can be both an integer or a fixed-point number
 * @param range The range to scale the number by, integer in the range [0, 255], which maps to [0, 1]
 */
#define SPLRandom_DoubleScaledRangeFX32(num, range) ((num) * (255 + (range) - (((range) * (fx32)SPLRandom_U32(8)) >> 7)) >> 8)



/**
 * @brief Generates a random number in the range [-num, num)
 * @param num The number to scale, can be both an integer or a fixed-point number
 */
#define SPLRandom_RangeFX32(num) (((num) * (s32_0205312C)SPLRandom_U32(9) - ((num) << 8)) >> 8)



/**
 * @brief Generates a random fx32 number in the range [min, max)
 * @param min The minimum number to generate, integer
 * @param max The maximum number to generate, integer
 */
#define SPLRandom_BetweenFX32(min, max) ((fx32)(((max) - (min)) * SPLRandom_U32(12) + ((min) * FX32_ONE)))



static inline const void *SPLTextureResource_GetTexData(const SPLTextureResource *resource)
{
    return (const void *)(resource + 1);
}


static inline BOOL SPLDraw_Setup(const SPLParticle *ptcl, const SPLManager *mgr)
{
    fx32 alpha = (fx32)(ptcl->visibility.baseAlpha * (ptcl->visibility.animAlpha + 1)) >> 5;
    G3_PolygonAttr(GX_LIGHTMASK_NONE, GX_POLYGONMODE_MODULATE, GX_CULL_NONE, ptcl->visibility.currentPolygonID, alpha, mgr->miscPolygonAttr);
    reg_G3_POLYGON_ATTR;
    return alpha == 0;
}


static inline void SPLParticleList_PushFront(SPLParticleList *list, SPLParticle *ptcl)
{
    SPLList_PushFront((SPLList *)list, (SPLNode *)ptcl);
}


static inline SPLParticle *SPLParticleList_Erase(SPLParticleList *list, SPLParticle *ptcl)
{
    return (SPLParticle *)SPLList_Erase((SPLList *)list, (SPLNode *)ptcl);
}


/*
 * SPLEmitter_Update: the per-frame emitter step.  Emits new particles on the
 * emission interval (func_020569A4), collects the enabled animation
 * functions (func_02057E68 scale, func_02057C9C colour, func_02057BC0
 * alpha, func_02057B5C texture; children func_02057B10 / func_02057AB8),
 * then integrates every particle and child particle (behaviours, air
 * resistance, velocity, polygon ID, age), erasing the dead ones back to the
 * manager free list, with the pre/post update callback around it all.
 *
 * Wave 9, third lane: this body and every declaration it uses are the public
 * pret/pokeplatinum decompilation of the same NitroSystem particle library
 * (SPL; docs/families/cluster_02052F58.h), lib/spl/src/spl_emitter.c SPLEmitter_Update, with the
 * lib/spl/include/spl_*.h structs, and the SDK G3/MTX/VEC inlines written out
 * from sdk/TwlSDK/include; only the callees are pinned to Black addresses.
 * It compiled EXACT at the cluster pin unchanged, closing docs/notes/pkt_02053218.c.txt (last measured 1128/1152, 763 out, 1.1p1).
 */
void func_02053218(SPLManager *mgr, SPLEmitter *emtr)
{
    SPLParticle *ptcl;
    SPLParticle *next;
    SPLResource *res;
    SPLResourceHeader *header;
    SPLChildResource *child;
    SPLResourceFlags resFlags;
    AnimFunc animFuncs[4];
    AnimFunc childAnimFuncs[4];
    int i, animCount, behaviorCount;
    int airResistance;
    u8 lifeRates[2];
    VecFx32 acc;

    res = emtr->resource;
    child = res->childResource;
    animCount = 0;
    header = res->header;
    resFlags = header->flags;
    behaviorCount = res->behaviorCount;
    airResistance = header->misc.airResistance + FX32_CONST(0.09375);

    if (emtr->updateCallback) {
        emtr->updateCallback(emtr, SPL_CALLBACK_PRE_UPDATE);
    }

    if (header->emitterLifeTime == 0 || emtr->age < header->emitterLifeTime) {
        if (emtr->age % emtr->misc.emissionInterval == 0) {
            if (!emtr->state.terminate && !emtr->state.emissionPaused && emtr->state.started) {
                SPLEmitter_EmitParticles(emtr, &mgr->inactiveParticles);
            }
        }
    }

    if (resFlags.hasScaleAnim) {
        animFuncs[animCount].func = SPLAnim_Scale;
        animFuncs[animCount++].loop = res->scaleAnim->flags.loop;
    }

    if (resFlags.hasColorAnim && !res->colorAnim->flags.randomStartColor) {
        animFuncs[animCount].func = SPLAnim_Color;
        animFuncs[animCount++].loop = res->colorAnim->flags.loop;
    }

    if (resFlags.hasAlphaAnim) {
        animFuncs[animCount].func = SPLAnim_Alpha;
        animFuncs[animCount++].loop = res->alphaAnim->flags.loop;
    }

    if (resFlags.hasTexAnim && !res->texAnim->param.randomizeInit) {
        animFuncs[animCount].func = SPLAnim_Texture;
        animFuncs[animCount++].loop = res->texAnim->param.loop;
    }

    for (ptcl = emtr->particles.first; ptcl != NULL; ptcl = next) {
        next = ptcl->next;

        // For non-looping particles, "life rate" is a fraction of the particle's lifetime, represented as a u8.
        // where 0 is the start of the particle's life and 255 is the end
        // For looping particles, it's a fraction of the number of frames in the loop
        // See the SPLParticle struct for more info
        lifeRates[ANIM_FUNC_NO_LOOP] = (ptcl->lifeTimeFactor * ptcl->age) >> 8;
        lifeRates[ANIM_FUNC_LOOP] = ptcl->lifeRateOffset + ((ptcl->loopTimeFactor * ptcl->age) >> 8);

        for (i = 0; i < animCount; i++) {
            animFuncs[i].func(ptcl, res, lifeRates[animFuncs[i].loop]);
        }

        acc.x = acc.y = acc.z = 0;

        if (resFlags.followEmitter) {
            ptcl->emitterPos = emtr->position;
        }

        for (i = 0; i < behaviorCount; i++) {
            res->behaviors[i].applyFunc(res->behaviors[i].object, ptcl, &acc, emtr);
        }

        ptcl->rotation += ptcl->angularVelocity;

        ptcl->velocity.x = ptcl->velocity.x * airResistance >> 9;
        ptcl->velocity.y = ptcl->velocity.y * airResistance >> 9;
        ptcl->velocity.z = ptcl->velocity.z * airResistance >> 9;

        ptcl->velocity.x += acc.x;
        ptcl->velocity.y += acc.y;
        ptcl->velocity.z += acc.z;

        ptcl->position.x += ptcl->velocity.x + emtr->velocity.x;
        ptcl->position.y += ptcl->velocity.y + emtr->velocity.y;
        ptcl->position.z += ptcl->velocity.z + emtr->velocity.z;

        if (resFlags.hasChildResource) {
            fx32 emissionDelay = FX_MUL((fx32)ptcl->lifeTime << FX32_SHIFT, (fx32)child->misc.emissionDelay << FX32_SHIFT);

            // The >> 8 here is a division by 256 because emissionDelay is a fraction of the particle's lifetime represented as a u8
            fx32 diff = ((fx32)ptcl->age * FX32_ONE) - (emissionDelay >> 8);

            if (diff >= 0 && ((diff >> FX32_SHIFT) % child->misc.emissionInterval == 0)) {
                SPLEmitter_EmitChildren(ptcl, emtr, &mgr->inactiveParticles);
            }
        }

        if (emtr->resource->header->flags.hasFixedPolygonID) {
            ptcl->visibility.currentPolygonID = mgr->polygonID.fix;
        } else {
            ptcl->visibility.currentPolygonID = mgr->polygonID.current;
            mgr->polygonID.current += 1;

            if (mgr->polygonID.current > mgr->polygonID.max) {
                mgr->polygonID.current = mgr->polygonID.min;
            }
        }

        ptcl->age += 1;

        if (ptcl->age > ptcl->lifeTime) {
            SPLParticle *erased = SPLParticleList_Erase(&emtr->particles, ptcl);
            SPLParticleList_PushFront(&mgr->inactiveParticles, erased);
        }
    }

    if (resFlags.hasChildResource) {
        animCount = 0;
        if (child->flags.hasScaleAnim) {
            childAnimFuncs[animCount].func = SPLAnim_ChildScale;
            childAnimFuncs[animCount++].loop = FALSE;
        }

        if (child->flags.hasAlphaAnim) {
            childAnimFuncs[animCount].func = SPLAnim_ChildAlpha;
            childAnimFuncs[animCount++].loop = FALSE;
        }

        if (!child->flags.usesBehaviors) {
            behaviorCount = 0;
        }

        for (ptcl = emtr->childParticles.first; ptcl != NULL; ptcl = next) {
            next = ptcl->next;

            // "life rate" is a fraction of the particle's lifetime, represented as a u8
            // where 0 is the start of the particle's life and 255 is the end
            lifeRates[0] = (ptcl->age << 8) / ptcl->lifeTime;
            for (i = 0; i < animCount; i++) {
                childAnimFuncs[i].func(ptcl, res, lifeRates[0]);
            }

            acc.x = acc.y = acc.z = 0;

            if (child->flags.followEmitter) {
                ptcl->emitterPos = emtr->position;
            }

            for (i = 0; i < behaviorCount; i++) {
                res->behaviors[i].applyFunc(res->behaviors[i].object, ptcl, &acc, emtr);
            }

            ptcl->rotation += ptcl->angularVelocity;

            ptcl->velocity.x = ptcl->velocity.x * airResistance >> 9;
            ptcl->velocity.y = ptcl->velocity.y * airResistance >> 9;
            ptcl->velocity.z = ptcl->velocity.z * airResistance >> 9;

            ptcl->velocity.x += acc.x;
            ptcl->velocity.y += acc.y;
            ptcl->velocity.z += acc.z;

            ptcl->position.x += ptcl->velocity.x + emtr->velocity.x;
            ptcl->position.y += ptcl->velocity.y + emtr->velocity.y;
            ptcl->position.z += ptcl->velocity.z + emtr->velocity.z;

            if (emtr->resource->header->flags.childHasFixedPolygonID) {
                ptcl->visibility.currentPolygonID = mgr->polygonID.fix;
            } else {
                ptcl->visibility.currentPolygonID = mgr->polygonID.current;
                mgr->polygonID.current += 1;

                if (mgr->polygonID.current > mgr->polygonID.max) {
                    mgr->polygonID.current = mgr->polygonID.min;
                }
            }

            ptcl->age += 1;

            if (ptcl->age > ptcl->lifeTime) {
                SPLParticle *erased = SPLParticleList_Erase(&emtr->childParticles, ptcl);
                SPLParticleList_PushFront(&mgr->inactiveParticles, erased);
            }
        }
    }

    emtr->age += 1;

    if (emtr->updateCallback) {
        emtr->updateCallback(emtr, SPL_CALLBACK_POST_UPDATE);
    }
}



/*
 * The sibling of func_02053044 in the same file: the same per-frame dispatch
 * over a render list, but on the block's OTHER list (+0x08 rather than +0x14)
 * and with a disjoint handler set.  Unconditionally calls func_02053D30 on the
 * 0x14-byte row the descriptor's byte at +0x47 selects, picks the per-node
 * handler from bits 4..5 of the descriptor's first word (the `lsl #26` /
 * `lsr #30` pair), and picks a SECOND per-node function from bit 11 of the
 * same word (`lsl #20` / `lsrs #31`, materialised as the `ldrne`/`ldreq`
 * pair at 0x020531B8/0x020531BC), then walks the list calling both.
 * Cases 3 and 4 share func_0205429C, exactly as cases 3/4 do in the sibling.
 *
 * The descriptor's first word is READ TWICE, once for the switch field and
 * once for the bit-11 test (`ldr r0, [r5]` at 0x02053158 and again at
 * 0x020531A8).  A plain second read of the same field is CSE'd away and
 * costs the whole bit-11 block its shape; the load has to be spelled
 * `*(volatile u32 *)&d->flags` at both sites to survive, the same tell as
 * docs/idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md.
 *
 * COMPILER PIN: ../1.2/sp2, the interworking-conflict tell, same as the
 * sibling and same as this region's pkt_020526A8 family: `blx r5` at
 * 0x020531DC (`35 ff 2f e1`) and `blx r4` at 0x020531E8 (`34 ff 2f e1`)
 * beside the ARMv4T-style return `pop {r4, r5, r6, r7, r8, lr}` / `bx lr` at
 * 0x020531F8/0x020531FC (`f0 41 bd e8` / `1e ff 2f e1`), which no dsi front
 * end emits under -proc arm946e.
 *
 * 236 bytes, ZERO concrete mismatches.  Three of seven relocation sites are
 * ABS32 pool words at +0x00D4/D8/E8 naming func_02055FD4, func_02055498 and
 * func_02053D2C, and this function's own pool at 0x02053200 is the only place
 * in the image those three words appear.  func_02054A68 and func_0205429C
 * already resolve `matched x1`; filing any one of the remaining three
 * promotes this file toward EXACT with no change to the C.  func_02055498 and
 * func_02055FD4 are unfiled 3D-rig rows (docs/FRONTEND-PINS.md); func_02053D2C
 * is an unlabelled leaf four bytes below func_02053D30.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0205312C.c \
 *       --func func_0205312C --addr 0x0205312C --cc ../1.2/sp2 --arm
 */
void func_0205312C(struct Obj_0205312C *o)
{
    struct Blk *b = o->f40;
    struct Desc *d = b->f20->f00;
    Fn fn = 0;
    Fn1 g;
    struct Node *n;

    func_02053D30((struct SPLTexture *)((char *)o->f2c + d->f47 * 0x14));

    switch ((u32)(*(volatile u32 *)&d->flags << 26) >> 30) {
    case 0:
        fn = (Fn)func_02055FD4;
        break;
    case 1:
        fn = (Fn)func_02055498;
        break;
    case 2:
        fn = (Fn)func_02054A68;
        break;
    case 3:
        fn = (Fn)func_0205429C;
        break;
    case 4:
        fn = (Fn)func_0205429C;
        break;
    }

    if ((*(volatile u32 *)&d->flags << 20) >> 31)
        g = (Fn1)func_02053D30;
    else
        g = (Fn1)func_02053D2C;

    n = b->f08;
    if (n == 0)
        return;

    do {
        g((char *)o->f2c + n->f2c * 0x14);
        fn(o, n);
        n = n->next;
    } while (n != 0);
}
