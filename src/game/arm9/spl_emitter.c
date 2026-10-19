/*
 * file:     spl_emitter.c
 * unit:     yes
 * function: SPL_EMITTER_FreeResourceList, SPL_EMITTER_FreeResource, SPL_EMITTER_AllocResourceEx, SPL_EMITTER_AllocResource, SPL_EMITTER_FreeNodeHeap, SPL_EMITTER_FreeTexNode, SPL_EMITTER_AllocPlttVramDefault, SPL_EMITTER_AllocTexVramDefault, SPL_EMITTER_AllocPlttVramList, SPL_EMITTER_AllocTexVramList, SPL_EMITTER_FreeNodeToHeap, SPL_EMITTER_AllocNodeFromHeap, SPL_EMITTER_AllocPlttVram, SPL_EMITTER_AllocTexVram, SPL_EMITTER_UpdateSubC, SPL_EMITTER_UpdateSubX, SPL_EMITTER_UpdateSubB, SPL_EMITTER_UpdateParticles, SPL_EMITTER_SetupResource, SPL_EMITTER_Noop, SPL_EMITTER_SetTextureParam, SPL_EMITTER_UpdateFrameMainEx, SPL_EMITTER_UpdateFrameMain, SPL_EMITTER_UpdateFrameA68Ex, SPL_EMITTER_UpdateFrameA68, SPL_EMITTER_UpdateParticleMotionEx, SPL_EMITTER_UpdateParticleMotion, SPL_EMITTER_UpdateFrameEx, SPL_EMITTER_UpdateFrame, SPL_EMITTER_SetRotMtx, SPL_EMITTER_CalcRotMtx, SPLUtil_DrawXZPlane, SPLUtil_DrawXYPlane, SPLEmitter_EmitChildren, SPLEmitter_EmitParticles, SPLUtil_TiltCoordinates, SPLEmitter_ComputeOrthogonalAxes, SPLAnim_ChildAlpha, SPLAnim_ChildScale, SPLAnim_Texture, SPLAnim_Alpha, SPLAnim_Color, SPLAnim_Scale, SPL_EMITTER_LerpVec, SPL_EMITTER_InterpTarget, SPL_EMITTER_BuildFrame, SPL_EMITTER_AddScaledVec, SPL_EMITTER_UpdateNode, SPL_EMITTER_AddVec, SPLList_Erase, SPLList_PopFront, SPLList_PushFront
 * address:  0x020524C8
 * region:   arm9
 * compiler: dsi/../1.2/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Own object (particle library code after button_man.c): EXACT only with the
 * NITRO ../1.2/sp2 and ../1.2/base builds; DIFF with 1.1p1 and dsi/1.2 (the
 * builds of button_man.c), ../2.0/sp2, ../1.2/sp3 and -proc arm7tdmi.
 * Stand-ins left: fn = (Fn)SPL_EMITTER_UpdateParticleMotion and (Fn)SPL_EMITTER_UpdateParticleMotionEx (handlers stored
 * in a rig row table); SPL_EMITTER_FreeResourceList, SPL_EMITTER_FreeResource, SPL_EMITTER_AllocResourceEx,
 * SPL_EMITTER_AllocResource, SPL_EMITTER_FreeNodeHeap and SPL_EMITTER_FreeTexNode still use char * offsets and
 * the VramHeapHead/VramFreeList views of the rig object.
 *
 * symbols:
 *   GX_BeginLoadTexPltt  0x0207FA0C  arm
 *   GX_LoadTexPltt       0x0207FA40  arm
 *   GX_EndLoadTexPltt    0x0207FADC  arm
 *   GX_BeginLoadTex  0x0207F7A0  arm
 *   GX_LoadTex       0x0207F7FC  arm
 *   GX_EndLoadTex    0x0207F9B4  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   NNS_GfdDefaultFuncAllocPlttVram  0x020A8148  data
 *   NNS_GfdDefaultFuncAllocTexVram  0x020A8140  data
 *   MTX_MultVec33          0x0207B51C  arm
 *   MTX_MultVec43          0x0207BC08  arm
 *   VEC_CrossProduct       0x0207CAE8  arm
 *   VEC_Normalize          0x0207CCA4  arm
 *   VEC_DotProduct         0x0207CA68  arm
 *   G3_MultMtx43           0x0207D918  arm
 *   MI_Copy36B             0x02082B60  arm
 *   FX_SinCosTable_        0x020A1B38  data
 *   _s32_div_f             0x0209C0A4  arm
 *   func_02053E1C_Verts  0x020A1B38  data
 *   func_02053E1C_Hooks  0x020A7FE4  data
 *   func_02053E1C_Hooks2 0x020A7FDC  data
 *   MTX_Identity43_        0x0207B598  arm
 *   MTX_Scale43_        0x0207B5F4  thumb
 *   MTX_Concat43        0x0207B9F0  arm
 *   VEC_DotProduct        0x0207CA68  arm
 *   VEC_CrossProduct        0x0207CAE8  arm
 *   G3_LoadMtx43        0x0207D8E0  arm
 *   G3_MultMtx43        0x0207D918  arm
 *   func_0205429C_Verts  0x020A1B38  data
 *   func_0205429C_Hooks  0x020A7FE4  data
 *   func_0205429C_Hooks2 0x020A7FDC  data
 *   func_02054718_Verts  0x020A1B38  data
 *   func_02054718_Hooks  0x020A7FE4  data
 *   func_02054718_Hooks2 0x020A7FDC  data
 *   func_02054A68_Verts  0x020A1B38  data
 *   func_02054A68_Hooks  0x020A7FE4  data
 *   func_02054A68_Hooks2 0x020A7FDC  data
 *   func_02055B80_Verts  0x020A1B38  data
 *   func_02055FD4_Verts  0x020A1B38  data
 *   g_02146A8C     0x02146A8C  data
 *   SPLRandom_VecFx32                0x02058478  arm
 *   SPLRandom_VecFx32_XY             0x0205841C  arm
 *   VEC_Fx16CrossProduct             0x0207CB68  arm
 *   _u32_div_f                       0x0209C2B0  arm
 *   VEC_Fx16Normalize   0x0207CDB8  arm
 *   VEC_Fx16DotProduct  0x0207CAA4  arm
 *   g_020A7FEC     0x020A7FEC  data
 *   MTX_RotX33_  0x0207AF00  thumb
 *   MTX_RotY33_  0x0207AF1C  thumb
 *   MTX_RotZ33_  0x0207AF38  thumb
 *   MTX_MultVec33  0x0207B51C  arm
 */
#include "gf_standard_shared_types.h"

#define NULL ((void *)0)
#define FX32_SHIFT 12
#define FX32_ONE ((fx32)0x00001000L)
#define FX32_HALF ((fx32)0x00000800L)
#define FX32_DEC_MASK 0x00000fff
#define FX16_ONE ((fx16)0x1000)
#define FX32_CAST(x) ((fx32)(x))
#define FX32_CONST(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))
#define FX_MUL(v1, v2) FX32_CAST(((fx64)(v1) * (v2) + 0x800LL) >> FX32_SHIFT)
#define SPL_TEX_ANIM_MAX_FRAMES 8
#define gSPLRandomState g_02146A8C
#define RandRange(v) (((v) * (s32)((g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173) >> 23) - ((v) << 8)) >> 8)
#define reg_G3_BEGIN_VTXS (*(volatile u32 *)0x04000500)
#define reg_G3_END_VTXS   (*(volatile u32 *)0x04000504)
#define reg_G3_TEXCOORD   (*(volatile u32 *)0x04000488)
#define reg_G3_VTX_10     (*(volatile u32 *)0x04000490)
#define GX_FX16ToVtx10(x) ((u32)((x) >> 6) & 0x3ff)
#define GX_VECVTX10(x, y, z) ((u32)((GX_FX16ToVtx10(x) << 0) | (GX_FX16ToVtx10(y) << 10) | (GX_FX16ToVtx10(z) << 20)))
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
#define GX_RGB_R_(rgb) (rgb & GX_RGB_R_MASK)
#define GX_RGB_G_(rgb) (rgb & GX_RGB_G_MASK)
#define GX_RGB_B_(rgb) (rgb & GX_RGB_B_MASK)
#define GX_LIGHTMASK_NONE 0
#define GX_PACK_POLYGONATTR_PARAM(light, polyMode, cullMode, polygonID, alpha, misc) \
    ((u32)(((light) << 0) | ((polyMode) << 4) | ((cullMode) << 6) | (misc) | ((polygonID) << 24) | ((alpha) << 16)))
#define SPLRandom_ScaledRangeFX32(num, range) (((num) * (255 - (((range) * (fx32)SPLRandom_U32(8)) >> 8))) >> 8)
#define SPLRandom_DoubleScaledRangeFX32(num, range) ((num) * (255 + (range) - (((range) * (fx32)SPLRandom_U32(8)) >> 7)) >> 8)
#define SPLRandom_RangeFX32(num) (((num) * (s32)SPLRandom_U32(9) - ((num) << 8)) >> 8)
#define SPLRandom_BetweenFX32(min, max) ((fx32)(((max) - (min)) * SPLRandom_U32(12) + ((min) * FX32_ONE)))
#define reg_G3_MTX_MODE        (*(volatile u32 *)0x04000440)
#define reg_G3_MTX_SCALE       (*(volatile u32 *)0x0400046C)
#define reg_G3_TEXIMAGE_PARAM  (*(volatile u32 *)0x040004A8)
#define reg_G3_TEXPLTT_BASE    (*(volatile u32 *)0x040004AC)
#define GX_PACK_TEXIMAGE_PARAM(texFmt, texGen, s, t, repeat, flip, pltt0, addr) \
    ((u32)((addr) >> 3) | ((texFmt) << 26) | ((texGen) << 30) | ((s) << 20) | ((t) << 23) | ((repeat) << 16) | ((flip) << 18) | ((pltt0) << 29))
#define GX_PACK_TEXPLTTBASE_PARAM(addr, texfmt) ((u32)((addr) >> (4 - ((texfmt) == GX_TEXFMT_PLTT4))))
#define FALSE 0
#define ANIM_FUNC_NO_LOOP 0
#define ANIM_FUNC_LOOP    1
struct SPLParticle;
struct SPLEmitter;
struct ColorNode;
struct RenderNode;
struct SPLManager;
struct SPLTexture;
struct ScaledVecSource;
struct InterpState;
struct RandomVecSource;
struct VramHeapNode;
struct Cfg;
struct RigObject;
struct Vec3;
typedef struct SPLNode { struct SPLNode *next; struct SPLNode *prev; } SPLNode;

typedef struct SPLList { SPLNode *first; int count; SPLNode *last; } SPLList;

typedef signed short s16;

typedef unsigned short u16;

typedef unsigned int u32;

struct RandomVecRange {
    s16 x;
    s16 y;
    s16 z;
    u16 interval;
};

struct RandomVecSource {
    char reserved0[0x26];
    u16 frame;
};

struct ScaledVecSource {
    int x;
    int y;
    int z;
    s16 scale;
};

struct RigOffsetPair {
    int reserved0[2];
    int originX;
    int originY;
    int originZ;
    int offsetX;
    int offsetY;
    int offsetZ;
};

typedef unsigned char u8;

struct AxisAngleKey {
    u16 angle;
    u16 axis;
};

struct InterpTargetParam {
    int target;
    s16 speed;
    u16 mode : 2;
    u16 rest : 14;
};

struct InterpState {
    char _00[0x74];
    int target;
};

struct InterpTrack {
    char reserved0[0xc];
    int step;
    char reserved1[8];
    int value;
    char reserved2[8];
    u16 hold;
    u16 state;
    char reserved3[0x14];
    int position;
};

typedef signed int s32;

typedef s32 fx32;

typedef signed long long s64;

typedef s64 fx64;

struct LerpSource {
    fx32 x;
    fx32 y;
    fx32 z;
    short w;
};

struct LerpDest {
    fx32 reserved0;
    fx32 reserved1;
    fx32 x;
    fx32 y;
    fx32 z;
};

typedef u16 GXRgb;

typedef struct VecFx32 { fx32 x, y, z; } VecFx32;

typedef unsigned long long u64;

typedef signed char s8;

typedef s16 fx16;

typedef int BOOL;

typedef struct { fx16 x, y, z; } VecFx16;

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
    s16 minRotation;
    s16 maxRotation;
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
        u32 textureTileCountS : 2; // Number of times to tile the texture in the RenderNode direction
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
    s16 angularVelocity;
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

struct ParticleVisibility { u16 b0 : 5; u16 b5 : 5; u16 b10 : 6; };

struct ParticleView {
    u8 reserved0[0x08];
    struct VecFx32 pos;     /* +0x08 */
    struct VecFx32 vel;     /* +0x14 */
    u16 rotation;
    s16 angularVelocity;
    u16 lifeTime;
    u16 age;
    u16 loopTimeFactor;
    u16 lifeTimeFactor;
    u8 texture;
    u8 lifeRateOffset;
    struct ParticleVisibility w;           /* +0x2e */
    fx32 baseScale;
    u16 animScale;
    u16 color;
    struct VecFx32 emitterPos;
};

struct ParticleDescFlags { u16 b0 : 3; u16 sel : 2; u16 b5 : 1; u16 col : 1; u16 rest : 9; };

struct ParticleDesc {
    struct ParticleDescFlags f;        /* +0x00 */
    s16 velocity;
    u8 reserved0[2];
    u16 lifeTime;
    u8 scale;
    u8 scaleAdd;
    u16 color;
    u8 count;
    u8 reserved1[2];
    u8 texture;
};

struct EmitterParticle {
    u8 reserved0[0x08];
    struct VecFx32 pos;     /* +0x08 */
    struct VecFx32 vel;     /* +0x14 */
    u16 rotation;
    s16 angularVelocity;
    u16 lifeTime;
    u8 reserved1[0x08];
    struct ParticleVisibility w;           /* +0x2e */
    fx32 baseScale;
    s16 animScale;
    u16 color;
    struct VecFx32 emitterPos;
};

struct ParticleDescOwner { u8 reserved0[0x14]; struct ParticleDesc *desc; };

struct EmitOwner { u8 reserved0[0x14]; SPLList list; struct ParticleDescOwner *x; };

struct MtxFx43 { s32 m[12]; };

struct SubHwFlags {
    u16 a : 7;
    u16 kind : 2;
    u16 sel2 : 2;
    u16 sel1 : 1;
    u16 b : 4;
};

struct SubSelFlags {
    u32 lo : 6;
    u32 sel : 1;
    u32 hi : 25;
};

struct SubZeroFlags {
    u32 lo : 16;
    u32 b16 : 1;
    u32 sel2 : 2;
    u32 sel1 : 1;
    u32 reserved0 : 1;
    u32 b21 : 1;
    u32 b22 : 1;
    u32 flag : 1;
    u32 reserved1 : 8;
};

struct Sub28Flags {
    u32 lo : 8;
    u32 k : 16;
    u32 mid : 4;
    u32 sel : 3;
    u32 hi : 1;
};

struct SubDescBits {
    u32 lo : 4;
    u32 kind : 2;
    u32 mid : 5;
    u32 sel : 1;
    u32 hi : 20;
};

union SubFlags {
    struct SubZeroFlags z;
    struct SubDescBits d;
};

struct RigDescriptorHw {
    struct SubHwFlags hw;
    u8 reserved0[0x0d];
    u8 texture;
    struct SubSelFlags selFlags;
};

struct RigDescriptor {
    union SubFlags flags;
    u32 transX;
    u32 transY;
    u32 transZ;
    u8 reserved0[0x20];
    s16 scale;
    u8 reserved1[0x15];
    u8 texture;
    struct Sub28Flags flags28;
    u8 reserved2[0x04];
    s16 texS;
    s16 texT;
};

struct RigSubList {
    struct RigDescriptor *desc;
    u8 reserved0[0x10];
    struct RigDescriptorHw *hw;
};

struct RigRenderList {
    u8 reserved0[0x08];
    struct RenderNode *nodeList;
    u8 reserved1[0x08];
    struct RenderNode *nodeList2;
    u8 reserved2[0x08];
    struct RigSubList *subList;
    u8 reserved3[0x4e];
    u16 color;
    u8 reserved4[0x04];
    s16 texS;
    s16 texT;
    s16 texS2;
    s16 texT2;
};

struct RigObject {
    u8 reserved0[0x2c];
    struct SPLTexture *textures;
    u8 reserved1[0x02];
    u16 texCount;
    u8 reserved2[0x08];
    u32 polygonAttr;
    struct RigRenderList *renderList;
    struct MtxFx43 *mtx;
};

struct RenderNode {
    struct RenderNode *next;
    u8 reserved0[0x04];
    struct VecFx32 p1;
    struct VecFx32 p2;
    u16 rotation;
    u8 reserved1[0x0a];
    u8 texture;
    u8 reserved2;
    struct ParticleVisibility w;
    s32 baseScale;
    s16 animScale;
    u16 color;
    u32 emitterPosX;
    u32 emitterPosY;
    u32 emitterPosZ;
};

struct RigTransformFrame {
    struct VecFx32 t;
    struct MtxFx43 m;
};

typedef struct { fx32 m[4][3]; } MtxFx43;

typedef struct { fx32 m[3][3]; } MtxFx33;

typedef u32 GXPolygonAttrMisc;

typedef enum { GX_POLYGONMODE_MODULATE = 0 } GXPolygonMode;

typedef enum { GX_CULL_ALL = 0, GX_CULL_FRONT = 1, GX_CULL_BACK = 2, GX_CULL_NONE = 3 } GXCull;

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

struct RigTransformFrameA68 {
    struct MtxFx43 m1;
    struct MtxFx43 m2;
    struct MtxFx43 m3;
};

struct MtxFx33 { s32 m[9]; };

struct RigTransformFrameMain {
    struct MtxFx43 m1;
    struct MtxFx43 m2;
    struct MtxFx43 m3;
    struct VecFx32 dir;
    struct VecFx32 right;
    struct VecFx32 up;
    struct VecFx32 upRef;
    struct MtxFx43 m4;
};

typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_A3I5 = 1, GX_TEXFMT_PLTT4 = 2, GX_TEXFMT_PLTT16 = 3, GX_TEXFMT_PLTT256 = 4, GX_TEXFMT_COMP4x4 = 5, GX_TEXFMT_A5I3 = 6, GX_TEXFMT_DIRECT = 7 } GXTexFmt;

typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1, GX_TEXGEN_NORMAL = 2, GX_TEXGEN_VERTEX = 3 } GXTexGen;

typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;

typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;

typedef enum { GX_TEXREPEAT_NONE = 0 } GXTexRepeat;

typedef enum { GX_TEXFLIP_NONE = 0 } GXTexFlip;

typedef enum { GX_TEXPLTTCOLOR0_USE = 0 } GXTexPlttColor0;

typedef enum { GX_MTXMODE_PROJECTION = 0, GX_MTXMODE_POSITION = 1, GX_MTXMODE_POSITION_VECTOR = 2, GX_MTXMODE_TEXTURE = 3 } GXMtxMode;

struct VramResourceHeader
{
  u32 flags;
  s32 emitterBasePosX;
  s32 emitterBasePosY;
  s32 emitterBasePosZ;
  s32 emissionCount;
  s32 radius;
  s32 length;
  u16 axisX;
  u16 axisY;
  u16 axisZ;
  u16 color;
  s32 initVelPosAmplifier;
  s32 initVelAxisAmplifier;
  s32 baseScale;
  s32 aspectAndDelay;
  s32 rotationRange;
  u16 initAngle;
  u16 reserved0;
  u16 emitterLifeTime;
  u16 particleLifeTime;
  s32 randomAttenuation;
  u8 miscByte0;
  u8 miscByte1;
  u8 miscByte2;
  u8 miscByte3;
  u32 polygonFlags;
  u32 userData;
};

struct VramSub14
{
  s32 reserved0;
  s32 reserved1;
  s32 reserved2;
  s32 reserved3;
  u32 mode;
};

struct Cfg
{
  struct VramResourceHeader *resource;
  s32 reserved0;
  s32 reserved1;
  s32 reserved2;
  s32 reserved3;
  struct VramSub14 *sub14;
};

struct Vec3
{
  s32 x;
  s32 y;
  s32 z;
};

struct ResourceSetup
{
  s32 next;
  s32 prev;
  s32 particlesFirst;
  s32 particlesCount;
  s32 particlesLast;
  s32 childParticlesFirst;
  s32 childParticlesCount;
  s32 childParticlesLast;
  struct Cfg *resource;
  s32 state;
  s32 posX;
  s32 posY;
  s32 posZ;
  s32 velX;
  s32 velY;
  s32 velZ;
  s32 initVelX;
  s32 initVelY;
  s32 initVelZ;
  u16 age;
  u16 emissionCountFractional;
  u16 axisX;
  u16 axisY;
  u16 axisZ;
  u16 initAngle;
  s32 emissionCount;
  s32 radius;
  s32 length;
  s32 initVelPosAmplifier;
  s32 initVelAxisAmplifier;
  s32 baseScale;
  u16 particleLifeTime;
  u16 color;
  u32 collisionPlaneHeight;
  s16 textureS;
  s16 textureT;
  s16 childTextureS;
  s16 childTextureT;
  u32 misc;
  s32 reserved0;
  s32 reserved1;
  s32 reserved2;
  s32 updateCallback;
  s32 userDataPtr;
  s32 userData;
};

typedef struct FieldFunc {
    void (*func)(SPLParticle *, SPLResource *, int);
    BOOL loop;
} AnimFunc;

typedef void (*Fn)(struct RigObject *, struct RenderNode *);

typedef void (*Fn1)(SPLTexture *);

typedef void *(*AllocFn)(u32 size);

struct VramNodeHeap {
    AllocFn alloc;       /* 0x00 */
    u32 reserved0;
    u32 reserved1;
    u32 reserved2;
    u32 nodeListFirst;
    u32 nodeListCount;
    u32 nodeListLast;
    u32 rowListFirst;
    u32 rowListCount;
    u32 rowListLast;
    u32 reserved3;
    u32 reserved4;
    u16 reserved5;
    u16 reserved6;
    u16 nodeCount;
    u16 rowCount;
    u32 b0  : 6;
    u32 b6  : 6;
    u32 b12 : 6;
    u32 b18 : 6;
    u32 b24 : 1;
    u32 b25 : 7;
    u32 reserved7;
    u32 reserved8;
    u32 reserved9;
    u16 reserved10;
    u16 reserved11;
};

struct VramNodeBlob9C { u8 b[0x9c]; };

struct VramRowBlob44 { u8 b[0x44]; };

struct VramNodeFlags {
    u32 lo   : 8;
    u32 sub0   : 1;
    u32 sub1   : 1;
    u32 sub2  : 1;
    u32 sub3  : 1;
    u32 b12  : 4;
    u32 sub4  : 1;
    u32 b17  : 7;
    u32 anim0  : 1;
    u32 anim1  : 1;
    u32 anim2  : 1;
    u32 anim3  : 1;
    u32 anim4  : 1;
    u32 anim5  : 1;
    u32 b30  : 2;
};

struct VramAnim {
    void (*fn)(void);
    void *data;
};

struct VramHeapRecord {
    struct VramNodeFlags *data;  /* 0x00 */
    void *sub0;
    void *sub1;
    void *sub2;
    void *sub3;
    void *sub4;
    struct VramAnim *anims;  /* 0x18 */
    u16 nanims;          /* 0x1c */
    u16 reserved0;
};

struct VramResource {
    u32 id;
    u32 kind : 4;
    u32 w    : 4;
    u32 h    : 4;
    u32 hi   : 20;
    u32 textureSize;
    u32 paletteOffset;
    u32 paletteSize;
    u32 unused0;
    u32 unused1;
    u32 size;            /* 0x1c */
};

struct VramResourceRow {
    struct VramResource *res;
    u32 tex_vram;
    u32 pltt_vram;
    u32 param;
    u16 w;
    u16 h;
};

struct VramHeapHeader {
    u32 flags;
    u32 size;
    u16 nrec;
    u16 nrow;
};

struct VramTexHeap {
    AllocFn alloc;       /* 0x00 */
    u32 reserved0[9];
    struct VramHeapRecord *records;     /* 0x28 */
    struct VramResourceRow *rows;     /* 0x2c */
    u16 recordCount;
    u16 rowCount;
};

typedef u32 (*AllocTex)(u32, u32);

struct VramAllocClass {
    u32 c00_lo : 14;
    u32 retire : 1;
    u32 c00_hi : 17;
    u32 reserved0[11];
    u16 reserved1;
    u16 lifeTime;             /* 0x32 */
    u32 reserved2[2];
    u16 lifeCap;             /* 0x3c */
    u16 reserved3;
};

struct VramFreeNode {
    struct VramFreeNode * next;
    struct VramFreeNode * prev;
    u32 reserved0;
    u32 pending0;
    u32 reserved4[2];
    u32 pending1;
    u32 reserved1;
    struct VramAllocClass ** allocClass;
    u32 kill : 1;
    u32 reserved2 : 1;
    u32 suppressed : 1;
    u32 hidden : 1;
    u32 expired : 1;
    u32 reserved3 : 27;
    u16 reserved5[18];
    u16 age;
    u16 reserved6;
    u32 reserved7[12];
    unsigned int phaseFlags;
};

struct VramFreeList {
    u32 flags;
    struct VramFreeNode *list;   /* 0x04 */
    u32 reserved0;
    u32 reserved1;
    u32 freeList;
    u32 reserved2[13];
    u16 parity;             /* 0x48 */
};

struct VramHeapNode {
    struct VramHeapNode *next;   /* 0x00 */
    struct VramHeapNode *prev;   /* 0x04 */
    u32 reserved2[7];
    u32 kill : 1;
    u32 reserved0 : 1;
    u32 suppressed : 1;
    u32 hidden : 1;
    u32 reserved1 : 28;
};

struct VramHeapHead {
    u32 flags;
    struct VramHeapNode *list;   /* 0x04 */
    u32 reserved0;
    struct VramHeapNode *rlist;  /* 0x0c */
    u32 reserved4[10];
    u32 reserved2 : 24;
    u32 reverse : 1;
    u32 reserved3 : 7;
    u32 reserved1;
    struct VramHeapNode *cur;    /* 0x40 */
    u32 userData;
};

struct AllocScratch {
    u32 a;
    u32 b;
    u32 c;
};

extern void MTX_RotX33_(u8 *buf, int a, int b);
extern void MTX_RotY33_(u8 *buf, int a, int b);
extern void MTX_RotZ33_(u8 *buf, int a, int b);
extern void MTX_MultVec33(const VecFx32 *a, const MtxFx33 *b, VecFx32 *c);
extern void VEC_Fx16Normalize(VecFx16 *v, VecFx16 *w);
extern fx32 VEC_Fx16DotProduct(const VecFx16 *a, const VecFx16 *b);
extern void VEC_Fx16CrossProduct(const VecFx16 *a, const VecFx16 *b, VecFx16 *axb);
extern fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);
extern void VEC_Normalize(const VecFx32 *pSrc, VecFx32 *pDst);
extern void SPLRandom_VecFx32(VecFx32 *vec);
extern void SPLRandom_VecFx32_XY(VecFx32 *vec);
extern void G3_MultMtx43(const MtxFx43 *m);
extern void MI_Copy36B(const void *pSrc, void *pDst);
extern void MTX_MultVec43(const VecFx32 *vec, const MtxFx43 *m, VecFx32 *dst);
extern void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern u32 MTX_Scale43_(void *, s32, s32, s32);
extern void MTX_Concat43(const void *, const void *, void *);
extern void G3_LoadMtx43(const void *);
extern void MTX_Identity43_(void *);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void GX_BeginLoadTex(void);
extern void GX_LoadTex(void *dst, u32 a, u32 b);
extern void GX_EndLoadTex(void);
extern void GX_BeginLoadTexPltt(void);
extern void GX_LoadTexPltt(void *dst, u32 a, u32 b);
extern void GX_EndLoadTexPltt(void);
void SPLList_PushFront(SPLList *list, SPLNode *node);
SPLNode *SPLList_PopFront(SPLList *list);
SPLNode *SPLList_Erase(SPLList *list, SPLNode *node);
void SPL_EMITTER_AddVec(struct RandomVecRange *o, void *s, int *dst);
void SPL_EMITTER_UpdateNode(struct RandomVecRange *o, struct RandomVecSource *s, int *dst);
void SPL_EMITTER_AddScaledVec(struct ScaledVecSource *a, struct RigOffsetPair *b, volatile int *c);
void SPL_EMITTER_BuildFrame(struct AxisAngleKey *o, u8 *dst);
void SPL_EMITTER_InterpTarget(struct InterpTargetParam *a, struct InterpTrack *s, int unused, struct InterpState *c);
void SPL_EMITTER_LerpVec(struct LerpSource *a, struct LerpDest *b);
void SPLAnim_Scale(SPLParticle *ptcl, SPLResource *res, int lifeRate);
void SPLAnim_Color(SPLParticle *ptcl, SPLResource *res, int lifeRate);
void SPLAnim_Alpha(SPLParticle *ptcl, SPLResource *res, int lifeRate);
void SPLAnim_Texture(SPLParticle *ptcl, SPLResource *res, int lifeRate);
void SPLAnim_ChildScale(SPLParticle *ptcl, SPLResource *res, int lifeRate);
void SPLAnim_ChildAlpha(SPLParticle *ptcl, SPLResource *res, int lifeRate);
void SPLEmitter_ComputeOrthogonalAxes(SPLEmitter *emtr);
void SPLUtil_TiltCoordinates(VecFx32 *out, const VecFx32 *src, const SPLEmitter *emtr);
void SPLEmitter_EmitParticles(SPLEmitter *emtr, SPLParticleList *list);
void SPLEmitter_EmitChildren(SPLParticle *ptcl, SPLEmitter *emtr, SPLParticleList *list);
void SPLUtil_DrawXYPlane(s32 s, s32 t, s32 x, s32 y);
void SPLUtil_DrawXZPlane(s32 s, s32 t, s32 x, s32 z);
void SPL_EMITTER_CalcRotMtx(s32 sn, s32 cs, struct MtxFx43 *m);
void SPL_EMITTER_SetRotMtx(s32 sn, s32 cs, struct MtxFx43 *m);
void SPL_EMITTER_UpdateFrame(struct RigObject *obj, struct RenderNode *s);
void SPL_EMITTER_UpdateFrameEx(struct RigObject *obj, struct RenderNode *s);
void SPL_EMITTER_UpdateParticleMotion(SPLManager *mgr, SPLParticle *ptcl);
void SPL_EMITTER_UpdateParticleMotionEx(SPLManager *mgr, SPLParticle *ptcl);
void SPL_EMITTER_UpdateFrameA68(struct RigObject *obj, struct RenderNode *s);
void SPL_EMITTER_UpdateFrameA68Ex(struct RigObject *obj, struct RenderNode *s);
void SPL_EMITTER_UpdateFrameMain(struct RigObject *obj, struct RenderNode *s);
void SPL_EMITTER_UpdateFrameMainEx(struct RigObject *obj, struct RenderNode *s);
void SPL_EMITTER_SetTextureParam(SPLTexture *tex);
void SPL_EMITTER_Noop(SPLTexture *tex);
void SPL_EMITTER_SetupResource(volatile struct ResourceSetup *o, struct Cfg *cfg, const struct Vec3 *pos);
void SPL_EMITTER_UpdateParticles(SPLManager *mgr, SPLEmitter *emtr);
void SPL_EMITTER_UpdateSubB(struct RigObject *o);
void SPL_EMITTER_UpdateSubX(struct RigObject *o);
void SPL_EMITTER_UpdateSubC(struct RigObject *o);
int SPL_EMITTER_AllocTexVram(u32 szByte, u32 is4x4comp);
int SPL_EMITTER_AllocPlttVram(u32 szByte, u32 is4pltt);
struct VramNodeHeap *SPL_EMITTER_AllocNodeFromHeap(AllocFn alloc, u16 n1, u16 n2, u16 limitA, u16 limitB, u16 maxResIndex);
void SPL_EMITTER_FreeNodeToHeap(struct VramTexHeap *h, struct VramHeapHeader *d);
int SPL_EMITTER_AllocTexVramList(struct RigObject *o, AllocTex alloc);
int SPL_EMITTER_AllocPlttVramList(struct RigObject *o, AllocTex alloc);
void SPL_EMITTER_AllocTexVramDefault(u32 rigObject);
void SPL_EMITTER_AllocPlttVramDefault(u32 rigObject);
void SPL_EMITTER_FreeTexNode(struct VramFreeList *h);
void SPL_EMITTER_FreeNodeHeap(struct VramHeapHead *h, u32 a);
int SPL_EMITTER_AllocResource(char *p, int b, int c);
int SPL_EMITTER_AllocResourceEx(char *p, int b, void (*fn)(void *));
void SPL_EMITTER_FreeResource(char *p, char *q);
void SPL_EMITTER_FreeResourceList(void *p);
extern const VecFx16 g_020A7FEC;
extern const fx16 FX_SinCosTable_[];
extern u32 g_02146A8C;
extern const s16 func_02055FD4_Verts[];
extern const s16 func_02055B80_Verts[];
extern const s16 func_02054A68_Verts[];
extern const s16 func_02054718_Verts[];
extern const s16 func_0205429C_Verts[];
extern const s16 func_02053E1C_Verts[];



void SPLList_PushFront(SPLList *list, SPLNode *node)
{
    SPLNode *head;

    head = list->first;
    if (head == 0) {
        list->first = node;
        list->last = node;
        node->next = 0;
        node->prev = node->next;
    } else {
        node->next = head;
        node->prev = 0;
        list->first->prev = node;
        list->first = node;
    }
    list->count++;
}




SPLNode *SPLList_PopFront(SPLList *list)
{
    SPLNode *ret;
    SPLNode *head;

    ret = 0;
    head = list->first;
    if (head != 0) {
        ret = head;
        list->first = head->next;
        if (list->first != 0) {
            head->next->prev = 0;
        } else {
            list->first = 0;
            list->last = 0;
        }
        list->count--;
    }
    return ret;
}





SPLNode *SPLList_Erase(SPLList *list, SPLNode *node)
{
    SPLNode *next;

    next = node->next;
    if (next == 0) {
        if (list->first == node) {
            list->first = 0;
            list->last = 0;
        } else {
            node->prev->next = 0;
            list->last = list->last->prev;
        }
    } else {
        if (list->first == node) {
            list->first = next;
            list->first->prev = 0;
        } else {
            next->prev = node->prev;
            node->prev->next = node->next;
        }
    }
    list->count--;
    return node;
}






/*
 * Handler row 0 of the 3D-rig table searched by BUTTON_MAN_FindRowData: adds the three
 * s16 components of o to dst[0..2].  Same compiler as its sibling
 * SPL_EMITTER_UpdateNode (1.1p1 merges the first two loads into an ldm).  The middle
 * argument is unused but kept for the handler signature SPL_EMITTER_UpdateNode has.
 */
void SPL_EMITTER_AddVec(struct RandomVecRange *o, void *s, int *dst)
{
    dst[0] = dst[0] + o->x;
    dst[1] = dst[1] + o->y;
    dst[2] = dst[2] + o->z;
}







u32 g_02146A8C;







/*
 * note:     EXACT* because the follower at 0x020582C0 is an unlabelled leaf run
 *           (its own literal pool); every byte of the 188-byte function plus the
 *           pool at 0x020582C0 compares identical.
 */
void SPL_EMITTER_UpdateNode(struct RandomVecRange *o, struct RandomVecSource *s, int *dst)
{
    int r;

    if (s->frame % o->interval != 0) {
        return;
    }

    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    r = g_02146A8C >> 23;
    dst[0] = dst[0] + ((o->x * r - (o->x << 8)) >> 8);

    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    r = g_02146A8C >> 23;
    dst[1] = dst[1] + ((o->y * r - (o->y << 8)) >> 8);

    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    r = g_02146A8C >> 23;
    dst[2] = dst[2] + ((o->z * r - (o->z << 8)) >> 8);
}








void SPL_EMITTER_AddScaledVec(struct ScaledVecSource *a, struct RigOffsetPair *b, volatile int *c)
{
    c[0] = c[0] + (a->scale * (a->x - b->originX - b->offsetX) >> 12);
    c[1] = c[1] + (a->scale * (a->y - b->originY - b->offsetY) >> 12);
    c[2] = c[2] + (a->scale * (a->z - b->originZ - b->offsetZ) >> 12);
}









/*
 * wave r8 lane rigD: first compile, EXACT under ../1.2/sp2 -proc arm946e.
 * The r6 note called this row "untouched" and predicted five label-class
 * relocation sites; all five resolve (four branch, one literal), and the
 * shared table is one symbol for all three cases.
 *
 * The two spellings that matter:
 *  - the three cases are identical apart from the callee, so each arm
 *    re-reads `idx = o->angle >> 4;` (hoisting it above the switch costs the
 *    asr slot).
 *  - the subscripts are `idx * 2` and `idx * 2 + 1`, not `idx`/`idx + 1`:
 *    both address the same halfwords, but the image forms the byte offsets
 *    from `lsl r2, r1, #1` + `add r1, r2, #1` + two `lsl #1`s, which is the
 *    `idx * 2` spelling (the `idx`/`idx + 1` spelling is 12 bytes short).
 */
void SPL_EMITTER_BuildFrame(struct AxisAngleKey *o, u8 *dst)
{
    u8 buf[0x28];
    int idx;

    switch (o->axis) {
    case 0:
        idx = o->angle >> 4;
        MTX_RotX33_(buf, FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);
        break;
    case 1:
        idx = o->angle >> 4;
        MTX_RotY33_(buf, FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);
        break;
    case 2:
        idx = o->angle >> 4;
        MTX_RotZ33_(buf, FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);
        break;
    }

    MTX_MultVec33((const VecFx32 *)(dst + 8), (const MtxFx33 *)buf, (VecFx32 *)(dst + 8));
}










/*
 * wave r8 lane rigD: the wave r6 DIFF at this address is closed.  The two
 * levers the r6 note asked for are both real and both necessary:
 *
 *  - the mode dispatch is a `switch` on a 2-bit bitfield member, not an
 *    if/else-if chain: `sw` puts BOTH case tests before the default `bx lr`
 *    and the two bodies after it, which is the 284-byte layout (the
 *    if/else-if spelling hoists case 0's body to the first test and comes
 *    out 260 bytes).
 *  - the mode-1 clamp is the 64-bit `(s64)x * y + 0x800 >> 12` form, not the
 *    32-bit one: 32-bit gives `mul/add/asr` (4 instructions, 260 bytes),
 *    the `long long` form gives the image's `smull/adc/lsr/orr` quartet with
 *    the pooled `mov r0, #0x800` in the middle.
 *
 * The arm shape the r6 note arrived at is also exact as written: the inner
 * `return` sits INSIDE the inner `if` (predicated `bxgt lr` in mode 0, a
 * `ble <tail>` out-of-line clamp in mode 1), and the redundant
 * `if (v < target) return;` after it is what makes the shared tail block
 * exist at all.
 */
void SPL_EMITTER_InterpTarget(struct InterpTargetParam *a, struct InterpTrack *s, int unused, struct InterpState *c)
{
    int target;
    int v;

    target = a->target;
    if (c->target != 0x80000000) target = c->target;

    switch (a->mode) {
    case 0:
        v = s->position;
        if (v < target) {
            if (v + s->step > target) {
                s->step = target - v;
                s->state = s->hold;
                return;
            }
        }
        if (v < target) return;
        if (v + s->step < target) {
            s->step = target - v;
            s->state = s->hold;
        }
        return;
    case 1:
        v = s->position;
        if (v < target) {
            if (v + s->step > target) {
                s->step = target - v;
                s->value = -(int)(((long long)s->value * a->speed + 0x800) >> 12);
                return;
            }
        }
        if (v < target) return;
        if (v + s->step < target) {
            s->step = target - v;
            s->value = -(int)(((long long)s->value * a->speed + 0x800) >> 12);
        }
        return;
    }
}










static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((s64)a * b + 0x800) >> 12);
}










void SPL_EMITTER_LerpVec(struct LerpSource *a, struct LerpDest *b)
{
    b->x = b->x + FX_Mul(a->w, a->x - b->x);
    b->y = b->y + FX_Mul(a->w, a->y - b->y);
    b->z = b->z + FX_Mul(a->w, a->z - b->z);
}



#define GX_RGB(r, g, b) (((r) << 0) | ((g) << 5) | ((b) << 10))







void SPLAnim_Scale(SPLParticle *ptcl, SPLResource *res, int lifeRate)
{
    SPLScaleAnim *anim;
    int b0;
    int b1;

    anim = res->scaleAnim;
    b0 = anim->curve.in;
    b1 = anim->curve.out;
    if (lifeRate < b0) {
        ptcl->animScale = anim->start + lifeRate * (anim->mid - anim->start) / b0;
        return;
    }
    if (lifeRate < b1) {
        ptcl->animScale = anim->mid;
        return;
    }
    ptcl->animScale = anim->end + (lifeRate - 0xFF) * (anim->end - anim->mid) / (0xFF - b1);
}








static inline void ColLerp(SPLParticle *out, s32 from, s32 to, u32 on, s32 num, s32 den)
{
    s32 tr = to & 0x1f;
    s32 fr = from & 0x1f;
    s32 tg = (to >> 5) & 0x1f;
    s32 fg = (from >> 5) & 0x1f;
    s32 fb = (from >> 10) & 0x1f;
    s32 tb = (to >> 10) & 0x1f;
    if (!on) {
        out->color = GX_RGB(tr, tg, tb);
        return;
    }
    out->color = GX_RGB(fr + num * (tr - fr) / den, fg + num * (tg - fg) / den, fb + num * (tb - fb) / den);
}







/* Segment 2 copy: the key colour is the FIRST parameter (`to`) and the
 * node colour the second (`from`); channels declared from/to per channel. */
static inline void ColLerp2(SPLParticle *out, s32 to, s32 from, u32 on, s32 num, s32 den)
{
    s32 fr = from & 0x1f;
    s32 tr = to & 0x1f;
    s32 fg = (from >> 5) & 0x1f;
    s32 tg = (to >> 5) & 0x1f;
    s32 fb = (from >> 10) & 0x1f;
    s32 tb = (to >> 10) & 0x1f;
    if (!on) {
        out->color = GX_RGB(tr, tg, tb);
        return;
    }
    out->color = GX_RGB(fr + num * (tr - fr) / den, fg + num * (tg - fg) / den, fb + num * (tb - fb) / den);
}







/*
 * A keyframed RGB555 colour ramp over three key times t0 < t1 < t2: below t0
 * the key's first colour, between t0 and t1 a per-channel lerp from the
 * key's first colour to the node's colour, between t1 and t2 a lerp from the
 * node's colour to the key's second colour, and past t2 the second colour.
 * The key's bit-2 flag switches the lerp off (the target colour is stored
 * recomposed).  The three _s32_div_f calls per segment come out in b, r, g
 * order from the GX_RGB expression tree.
 *
 * Closes docs/notes/pkt_02057C9C.c.txt (16 out at the end of wave 8).  The
 * two segments are two inline helpers with different parameter and channel
 * declaration orders; segment 1 is the note's ColLerp unchanged.  What closed
 * segment 2 (wave 9, third lane): its helper takes the KEY colour FIRST
 * (`to`, then `from`), called ColLerp2(out, k->c1, n->col, ...), and declares
 * its channels in plain per-channel from/to order fr, tr, fg, tg, fb, tb.  In
 * both segments the key colour is therefore the first colour parameter.
 * Found by a joint search of the (to, from) signature over the 720 channel
 * orders; (to, from) with the note's order was 22 out.
 */
void SPLAnim_Color(SPLParticle *ptcl, SPLResource *res, int lifeRate)
{
    SPLColorAnim *k = res->colorAnim;
    s32 t0 = k->curve.in;
    SPLResourceHeader *n = res->header;
    s32 t1 = k->curve.peak;
    s32 t2 = k->curve.out;
    if (lifeRate < t0) {
        ptcl->color = k->start;
        return;
    }
    if (lifeRate < t1) {
        ColLerp(ptcl, k->start, n->color, k->flags.interpolate, lifeRate - t0, t1 - t0);
        return;
    }
    if (lifeRate < t2) {
        ColLerp2(ptcl, k->end, n->color, k->flags.interpolate, lifeRate - t1, t2 - t1);
        return;
    }
    ptcl->color = k->end;
}









u32 g_02146A8C;









/*
 * wave r10 lane closeC: EXACT, 220 bytes, 3 of 3 relocation sites resolved.
 * Two spellings closed the r8/r9 13-byte residue, and the first one is the
 * whole register tie-break:
 *
 *  - the third arm's base is `p->hi`, NOT `p->mid`.  The image's base shift is
 *    `lsl r6, r0, #0x11` at 0x02057C20 (rec << 17, i.e. the hi channel), where
 *    a `p->mid +` base emits `lsl r6, ..., #0x16` (rec << 22).  The two forms
 *    are the same value - hi + (t-0xff)*(hi-mid)/(0xff-b) equals
 *    mid + (t-b)*(hi-mid)/(0xff-b) - but only the hi-referenced form gives the
 *    image's instruction for instruction allocation, including the r3 handover
 *    at 0x02057C24 (`b` dies at the rsb on the line before, r3 is reused for hi).
 *
 *  - the tail's halfword is `w = (u16)((v * (0xff - q)) >> 8);`, a RIGHT shift.
 *    The image's `lsl r0, r1, #8` / `lsr r0, r0, #0x10` at 0x02057C70 is the
 *    u16 cast of a right shift of 8, not of a left shift: see
 *    docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 *    (32 - 16 = 16 = the cast width; 8 - 16 = -8 = the source shift).  The r8
 *    note's `<< 8` spelling compiles to `lsl #0x18`, one byte out.
 *
 * The r9 lever (moving the `b` definition inside the else or into the guard) and
 * the r8 lever set (24 declaration orders, five member types, the a/b assignment
 * order, nested-if, `b > t`, in-place member reads, three return types) are all
 * superseded by the base fix above; none of them is needed.
 */
void SPLAnim_Alpha(SPLParticle *ptcl, SPLResource *res, int lifeRate)
{
    SPLAlphaAnim *p;
    int a;
    int b;
    int v;
    int r;
    int q;
    u16 rangeValue;
    u16 w;

    p = res->alphaAnim;
    a = p->curve.in;
    b = p->curve.out;
    if (lifeRate < a) {
        v = p->alpha.start + lifeRate * (p->alpha.mid - p->alpha.start) / a;
    } else if (lifeRate < b) {
        v = p->alpha.mid;
    } else {
        v = p->alpha.end + (lifeRate - 0xff) * (p->alpha.end - p->alpha.mid) / (0xff - b);
    }
    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    r = g_02146A8C >> 24;
    rangeValue = p->flags.randomRange;
    q = rangeValue * r;
    q = q >> 8;
    w = (u16)((v * (0xff - q)) >> 8);
    *(u16 *)&ptcl->visibility = (*(u16 *)&ptcl->visibility & ~0x3e0) | ((w & 0x1f) << 5);
}










/*
 * wave r8 lane rigD: the wave r6 residue (80 bytes, register plan) is closed.
 *
 * The frame is a symptom, not a target: `push {r4,r5,lr}` + `sub sp, sp, #4`
 * is what mwcc emits for ANY function that needs r4 and r5 (12 bytes of
 * saves, realigned to 16).  So the job is to make the pointer land in r5,
 * and the lever is the wave r6 note's "r5-resident pointer": the loop must
 * carry TWO step values.  `end += p->step` in the loop update (the field,
 * re-read) together with a `step` local used by the test gives the fourth
 * live value the frame needs; with only one spelling of step the compiler
 * merges them and emits 80 bytes with `push {r4, lr}`.
 *
 * Two more spellings, each worth real bytes:
 *  - `i = 0;` is a statement before the guard and `end = 0;` sits after it,
 *    so the scheduler keeps `mov r4, #0` above the test and `mov lr, r4`
 *    in the loop preheader (both in the for-header comes out 100 bytes but
 *    28 bytes wrong).
 *  - the loop's continuation test reads `p->n` (the field) while the guard
 *    tests the local `n`: that is what assigns n to r3 and step to ip.
 *    Testing `n` in both places is 6 bytes out (n and step swap registers);
 *    everything else in the function is already right at that point.
 *
 * `-proc arm946e` measured, not assumed: at `arm7tdmi` (this range's
 * proc_hints entry) the same source is 41 bytes out at the same 100-byte
 * size; wave r6's measurement of the family's small rows holds for this row.
 */
void SPLAnim_Texture(SPLParticle *ptcl, SPLResource *res, int lifeRate)
{
    SPLTexAnim *p;
    int i;
    int end;
    int n;
    int step;

    p = res->texAnim;
    i = 0;
    n = p->param.frameCount;
    if (n <= 0) {
        return;
    }
    step = p->param.step;
    end = 0;
    do {
        if (lifeRate < end + step) {
            ptcl->texture = p->textures[i];
            return;
        }
        i++;
        end += p->param.step;
    } while (i < p->param.frameCount);
}











void SPLAnim_ChildScale(SPLParticle *ptcl, SPLResource *res, int lifeRate)
{
    short cur;

    cur = res->childResource->endScale;
    ptcl->animScale = cur + (cur - 0x1000) * (lifeRate - 0xFF) / 255;
}












void SPLAnim_ChildAlpha(SPLParticle *ptcl, SPLResource *res, int lifeRate)
{
    u16 v;

    v = (0xff - lifeRate) * 0x1f / 255;
    *(u16 *)&ptcl->visibility = (*(u16 *)&ptcl->visibility & ~0x3e0) | ((v & 0x1f) << 5);
}













/*
 *           +0x284, and that address's only pooled word image-wide is the word
 *           at 0x02057AB4, inside this function's own range
 *           (0x02057830..0x02057AB8).  `match.py one` prints verbatim:
 *           "+0284 ABS32 g_020A7FEC -> unresolved: 020A7FEC (data, from
 *           header) has no witness outside 02057830..02057AB8".  Confirmed by
 *           a raw word scan of the arm9 region: exactly one occurrence of the
 *           little-endian word ec 7f 0a 02, at 0x02057AB4.  The four PC24
 *           branch sites all resolve `label`.  A single-function row, so
 *           --suggest-split has nothing to cut: the site's only witness is
 *           inside the range that needs it.
 * First transcription (wave r11 lane B), MATCH on the second variant: 648 of
 * 648 bytes, every concrete byte identical, only the own-pool site wildcarded.
 * Whole body from the structure map in docs/notes/pkt_02057830.c.txt,
 * re-confirmed by a fresh `match.py show --addr 0x02057830` this run.
 *
 * Shape: a rig basis build.  `a` is the pooled axis (0, 0x1000, 0) at
 * 0x020A7FEC, `v` comes from a two-bit mode field of the object graph
 * `m->modeRef->mode->mode` (one of the three unit axes, or VEC_Fx16Normalize of
 * m+0x50 in the default arm), then the two basis rows are the cross product
 * of v with a and of v with the first row, computed inline with the FX_Mul
 * rounding quartet (the same shape as the sibling SPLUtil_TiltCoordinates), and the
 * two rows are normalised in place with the same two-identical-arguments
 * call the sibling records as load-bearing.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPLEmitter_ComputeOrthogonalAxes.c \
 *       --func SPLEmitter_ComputeOrthogonalAxes --addr 0x02057830 --arm --cc ../1.2/sp2
 */
void SPLEmitter_ComputeOrthogonalAxes(SPLEmitter *emtr)
{
    VecFx16 a;
    VecFx16 v;
    fx32 d;

    a = g_020A7FEC;

    switch (emtr->resource->header->flags.circleAxis) {
    case 2:
        v.x = 0x1000;
        v.y = 0;
        v.z = 0;
        break;
    case 1:
        v.x = 0;
        v.y = 0x1000;
        v.z = 0;
        break;
    case 0:
        v.x = 0;
        v.y = 0;
        v.z = 0x1000;
        break;
    default:
        VEC_Fx16Normalize(&emtr->axis, &v);
        break;
    }

    d = VEC_Fx16DotProduct(&a, &v);
    if (d == 0x1000 || d == -0x1000) {
        a.x = 0x1000;
        a.y = 0;
        a.z = 0;
    }

    emtr->crossAxis1.x = FX_Mul(v.y, a.z) - FX_Mul(v.z, a.y);
    emtr->crossAxis1.y = FX_Mul(v.z, a.x) - FX_Mul(v.x, a.z);
    emtr->crossAxis1.z = FX_Mul(v.x, a.y) - FX_Mul(v.y, a.x);
    emtr->crossAxis2.x = FX_Mul(v.y, emtr->crossAxis1.z) - FX_Mul(v.z, emtr->crossAxis1.y);
    emtr->crossAxis2.y = FX_Mul(v.z, emtr->crossAxis1.x) - FX_Mul(v.x, emtr->crossAxis1.z);
    emtr->crossAxis2.z = FX_Mul(v.x, emtr->crossAxis1.y) - FX_Mul(v.y, emtr->crossAxis1.x);

    VEC_Fx16Normalize(&emtr->crossAxis1, &emtr->crossAxis1);
    VEC_Fx16Normalize(&emtr->crossAxis2, &emtr->crossAxis2);
}













/*
 * out = M * src for a rig matrix M whose two 3x2 s16 rows live at m+0x84 and
 * m+0x8a; the third row is their cross product, normalised in place:
 *
 *     VEC_CrossProduct((VEC16 *)(m+0x84), (VEC16 *)(m+0x8a), &v);
 *     VEC_Fx16Normalize(&v, &v);        <-- TWO arguments, both the same
 *     out[0..2] = FX_Mul(src->x, m->r0[k]) + FX_Mul(src->y, m->r1[k])
 *               + FX_Mul(src->z, v[k]);
 *
 * 0x0207CB68 is the 104-byte cross product (six smulbb / sub / +0x800 / asr
 * #12 quartets), 0x0207CDB8 the 300-byte Fx16 normaliser (reads r0, writes a
 * global through a pooled pointer).  The normaliser's own body never reads
 * r1, but the CALLER must still materialise it: `add r0, sp, #0` followed by
 * `mov r1, r0` is in the image at 0x020576D4+0x24/+0x28, so the call in the
 * original source passes the vector twice.  Omitting the second argument
 * costs exactly those 4 bytes (348 vs 352) and shifts every later
 * instruction, so it reads as a whole-body register-plan diff; it is the
 * one thing to get right on this row.
 *
 * The `mov ip, #0x800` register-form rounding constant feeding `adds` is the
 * 1.2 constant-materialisation tell (docs/FRONTEND-PINS.md), and the pin is
 * the family pin for 0x0205429C..0x020584E0.  -proc arm946e is MEASURED for
 * this row, not quoted from layout/proc_hints.txt (which calls the packet
 * arm7tdmi): at arm7tdmi the frame is not this one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPLUtil_TiltCoordinates.c \
 *       --func SPLUtil_TiltCoordinates --addr 0x020576D0 --arm --cc ../1.2/sp2
 */
void SPLUtil_TiltCoordinates(VecFx32 *out, const VecFx32 *src, const SPLEmitter *emtr)
{
    VecFx16 v;

    VEC_Fx16CrossProduct(&emtr->crossAxis1, &emtr->crossAxis2, &v);
    VEC_Fx16Normalize(&v, &v);

    out->x = FX_Mul(src->x, emtr->crossAxis1.x) + FX_Mul(src->y, emtr->crossAxis2.x) + FX_Mul(src->z, v.x);
    out->y = FX_Mul(src->x, emtr->crossAxis1.y) + FX_Mul(src->y, emtr->crossAxis2.y) + FX_Mul(src->z, v.y);
    out->z = FX_Mul(src->x, emtr->crossAxis1.z) + FX_Mul(src->y, emtr->crossAxis2.z) + FX_Mul(src->z, v.z);
}







static inline fx16 FX_SinIdx(int idx) { return FX_SinCosTable_[((idx >> 4) << 1)]; }







static inline fx16 FX_CosIdx(int idx) { return FX_SinCosTable_[((idx >> 4) << 1) + 1]; }










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








static inline s32 SPLRandom_S32(u32 bits)
{
    return (s32)(SPLRandom_Next() >> (sizeof(u32) * 8 - bits));
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
#define SPLRandom_RangeFX32(num) (((num) * (s32)SPLRandom_U32(9) - ((num) << 8)) >> 8)








/**
 * @brief Generates a random fx32 number in the range [min, max)
 * @param min The minimum number to generate, integer
 * @param max The maximum number to generate, integer
 */
#define SPLRandom_BetweenFX32(min, max) ((fx32)(((max) - (min)) * SPLRandom_U32(12) + ((min) * FX32_ONE)))







static inline void SPLParticleList_PushFront(SPLParticleList *list, SPLParticle *ptcl)
{
    SPLList_PushFront((SPLList *)list, (SPLNode *)ptcl);
}







static inline SPLParticle *SPLParticleList_PopFront(SPLParticleList *list)
{
    return (SPLParticle *)SPLList_PopFront((SPLList *)list);
}







/*
 * SPLEmitter_EmitParticles of the NitroSystem particle library (SPL) this
 * cluster is (docs/families/cluster_02052F58.h): pop totalEmissions
 * particles off the free list, place each by the emitter's emission shape
 * (a ten-way switch: point, sphere surface, circle border, uniform circle
 * border, sphere, circle, cylinder surface, cylinder, hemisphere surface,
 * hemisphere), then set velocity, scale, colour, alpha, rotation, life and
 * texture from the resource header with the SPL LCG at 0x02146A8C.
 *
 * Wave 9, third lane: the body and every declaration are the public
 * pret/pokeplatinum decompilation of the same library (lib/spl/src/
 * spl_emit.c SPLEmitter_EmitParticles, lib/spl/include/spl_*.h), adapted
 * only by pinning its callees to Black addresses; it compiled EXACT at the
 * cluster pin on the first compile, all 3372 bytes (the listing extent to
 * SPLUtil_TiltCoordinates, pool included; the worklist's 1544-byte figure was wrong).
 * The struct layouts (SPLEmitter, SPLParticle, SPLResourceHeader,
 * SPLResource) therefore hold for Black unchanged, which settles most of
 * this cluster's field names.  `int i = 0;` before the loop is the
 * upstream's own spelling (commented there as required for matching).  The two statics upstream,
 * SPLEmitter_ComputeOrthogonalAxes and SPLUtil_TiltCoordinates, are the
 * separate functions SPLEmitter_ComputeOrthogonalAxes and SPLUtil_TiltCoordinates here.
 */
void SPLEmitter_EmitParticles(SPLEmitter *emtr, SPLParticleList *list)
{
    SPLResource *res = emtr->resource;
    SPLResourceHeader *header = res->header;

    int i = 0; // Required for matching
    int emitCountDec = emtr->emissionCount + FX32_CAST(emtr->emissionCountFractional);
    int totalEmissions = emitCountDec >> FX32_SHIFT;
    int emission = 0;
    emtr->emissionCountFractional = emitCountDec & FX32_DEC_MASK;

    enum SPLEmissionType emitType = header->flags.emissionType;
    if (emitType == SPL_EMISSION_TYPE_CIRCLE_BORDER
        || emitType == SPL_EMISSION_TYPE_CIRCLE_BORDER_UNIFORM
        || emitType == SPL_EMISSION_TYPE_CIRCLE
        || emitType == SPL_EMISSION_TYPE_CYLINDER_SURFACE
        || emitType == SPL_EMISSION_TYPE_CYLINDER
        || emitType == SPL_EMISSION_TYPE_HEMISPHERE_SURFACE
        || emitType == SPL_EMISSION_TYPE_HEMISPHERE) {
        SPLEmitter_ComputeOrthogonalAxes(emtr);
    }

    for (i = 0; i < totalEmissions; i++) {
        SPLParticle *ptcl = SPLParticleList_PopFront(list);
        if (ptcl == NULL) {
            return;
        }

        SPLParticleList_PushFront(&emtr->particles, ptcl);

        switch (header->flags.emissionType) {
        case SPL_EMISSION_TYPE_POINT:
            ptcl->position.x = ptcl->position.y = ptcl->position.z = 0;
            break;

        case SPL_EMISSION_TYPE_SPHERE_SURFACE:
            SPLRandom_VecFx32(&ptcl->position);
            ptcl->position.x = FX_MUL(ptcl->position.x, emtr->radius);
            ptcl->position.y = FX_MUL(ptcl->position.y, emtr->radius);
            ptcl->position.z = FX_MUL(ptcl->position.z, emtr->radius);
            break;

        case SPL_EMISSION_TYPE_CIRCLE_BORDER: {
            VecFx32 pos;
            SPLRandom_VecFx32_XY(&pos);
            pos.x = FX_MUL(pos.x, emtr->radius);
            pos.y = FX_MUL(pos.y, emtr->radius);
            pos.z = 0;
            SPLUtil_TiltCoordinates(&ptcl->position, &pos, emtr);
        } break;

        case SPL_EMISSION_TYPE_CIRCLE_BORDER_UNIFORM: {
            VecFx32 pos;
            int idx = (emission * FX32_CONST(16)) / totalEmissions;
            emission += 1;

            fx32 sin = FX_SinIdx(idx);
            fx32 cos = FX_CosIdx(idx);
            pos.x = FX_MUL(sin, emtr->radius);
            pos.y = FX_MUL(cos, emtr->radius);
            pos.z = 0;
            SPLUtil_TiltCoordinates(&ptcl->position, &pos, emtr);
        } break;

        case SPL_EMISSION_TYPE_SPHERE:
            SPLRandom_VecFx32(&ptcl->position);
            ptcl->position.x = FX_MUL(FX_MUL(ptcl->position.x, emtr->radius), SPLRandom_RangeFX32(FX32_ONE));
            ptcl->position.y = FX_MUL(FX_MUL(ptcl->position.y, emtr->radius), SPLRandom_RangeFX32(FX32_ONE));
            ptcl->position.z = FX_MUL(FX_MUL(ptcl->position.z, emtr->radius), SPLRandom_RangeFX32(FX32_ONE));
            break;

        case SPL_EMISSION_TYPE_CIRCLE: {
            VecFx32 pos;
            SPLRandom_VecFx32_XY(&pos);
            pos.x = FX_MUL(FX_MUL(pos.x, emtr->radius), SPLRandom_RangeFX32(FX32_ONE));
            pos.y = FX_MUL(FX_MUL(pos.y, emtr->radius), SPLRandom_RangeFX32(FX32_ONE));
            SPLUtil_TiltCoordinates(&ptcl->position, &pos, emtr);
        } break;

        case SPL_EMISSION_TYPE_HEMISPHERE_SURFACE: {
            VecFx32 pos;
            VecFx16 emitterUp;
            SPLRandom_VecFx32(&ptcl->position);
            VEC_Fx16CrossProduct(&emtr->crossAxis1, &emtr->crossAxis2, &emitterUp);
            pos.x = emitterUp.x;
            pos.y = emitterUp.y;
            pos.z = emitterUp.z;
            if (VEC_DotProduct(&pos, &ptcl->position) <= 0) {
                ptcl->position.x = -ptcl->position.x;
                ptcl->position.y = -ptcl->position.y;
                ptcl->position.z = -ptcl->position.z;
            }

            ptcl->position.x = FX_MUL(ptcl->position.x, emtr->radius);
            ptcl->position.y = FX_MUL(ptcl->position.y, emtr->radius);
            ptcl->position.z = FX_MUL(ptcl->position.z, emtr->radius);
        } break;

        case SPL_EMISSION_TYPE_HEMISPHERE: {
            VecFx32 pos;
            VecFx16 tmpUnitVec;
            SPLRandom_VecFx32(&ptcl->position);
            VEC_Fx16CrossProduct(&emtr->crossAxis1, &emtr->crossAxis2, &tmpUnitVec);
            pos.x = tmpUnitVec.x;
            pos.y = tmpUnitVec.y;
            pos.z = tmpUnitVec.z;
            if (VEC_DotProduct(&pos, &ptcl->position) < 0) {
                ptcl->position.x = -ptcl->position.x;
                ptcl->position.y = -ptcl->position.y;
                ptcl->position.z = -ptcl->position.z;
            }

            ptcl->position.x = FX_MUL(FX_MUL(ptcl->position.x, emtr->radius), (SPLRandom_RangeFX32(FX32_ONE) >> 1) + FX32_HALF);
            ptcl->position.y = FX_MUL(FX_MUL(ptcl->position.y, emtr->radius), (SPLRandom_RangeFX32(FX32_ONE) >> 1) + FX32_HALF);
            ptcl->position.z = FX_MUL(FX_MUL(ptcl->position.z, emtr->radius), (SPLRandom_RangeFX32(FX32_ONE) >> 1) + FX32_HALF);
        } break;

        case SPL_EMISSION_TYPE_CYLINDER_SURFACE: {
            VecFx32 pos;
            SPLRandom_VecFx32_XY(&ptcl->velocity);
            pos.x = FX_MUL(ptcl->velocity.x, emtr->radius);
            pos.y = FX_MUL(ptcl->velocity.y, emtr->radius);
            pos.z = SPLRandom_RangeFX32(emtr->length);
            SPLUtil_TiltCoordinates(&ptcl->position, &pos, emtr);
        } break;

        case SPL_EMISSION_TYPE_CYLINDER: {
            VecFx32 pos;
            SPLRandom_VecFx32_XY(&ptcl->velocity);
            pos.x = FX_MUL(FX_MUL(ptcl->velocity.x, emtr->radius), SPLRandom_RangeFX32(FX32_ONE));
            pos.y = FX_MUL(FX_MUL(ptcl->velocity.y, emtr->radius), SPLRandom_RangeFX32(FX32_ONE));
            pos.z = SPLRandom_RangeFX32(emtr->length);
            SPLUtil_TiltCoordinates(&ptcl->position, &pos, emtr);
        } break;
        }

        fx32 magPos = SPLRandom_DoubleScaledRangeFX32(emtr->initVelPositionAmplifier, header->randomAttenuation.initVel);
        fx32 magAxis = SPLRandom_DoubleScaledRangeFX32(emtr->initVelAxisAmplifier, header->randomAttenuation.initVel);

        VecFx32 posNorm;
        if (header->flags.emissionType == SPL_EMISSION_TYPE_CYLINDER_SURFACE) {
            VecFx32 tmp;
            tmp.x = FX_MUL(ptcl->velocity.x, emtr->crossAxis1.x) + FX_MUL(ptcl->velocity.y, emtr->crossAxis2.x);
            tmp.y = FX_MUL(ptcl->velocity.x, emtr->crossAxis1.y) + FX_MUL(ptcl->velocity.y, emtr->crossAxis2.y);
            tmp.z = FX_MUL(ptcl->velocity.x, emtr->crossAxis1.z) + FX_MUL(ptcl->velocity.y, emtr->crossAxis2.z);

            VEC_Normalize(&tmp, &posNorm);
        } else if (ptcl->position.x == 0 && ptcl->position.y == 0 && ptcl->position.z == 0) {
            SPLRandom_VecFx32(&posNorm);
        } else {
            VEC_Normalize(&ptcl->position, &posNorm);
        }

        ptcl->velocity.x = FX_MUL(posNorm.x, magPos) + FX_MUL(emtr->axis.x, magAxis) + emtr->particleInitVelocity.x;
        ptcl->velocity.y = FX_MUL(posNorm.y, magPos) + FX_MUL(emtr->axis.y, magAxis) + emtr->particleInitVelocity.y;
        ptcl->velocity.z = FX_MUL(posNorm.z, magPos) + FX_MUL(emtr->axis.z, magAxis) + emtr->particleInitVelocity.z;

        ptcl->emitterPos = emtr->position;

        ptcl->baseScale = SPLRandom_DoubleScaledRangeFX32(emtr->baseScale, header->randomAttenuation.baseScale);
        ptcl->animScale = FX32_ONE;

        if (header->flags.hasColorAnim && res->colorAnim->flags.randomStartColor) {
            u16 clr[3];
            u32 index = SPLRandom_S32(12);
            clr[0] = res->colorAnim->start;
            clr[1] = header->color;
            clr[2] = res->colorAnim->end;
            ptcl->color = clr[index % 3];
        } else {
            ptcl->color = header->color;
        }

        ptcl->visibility.baseAlpha = emtr->misc.baseAlpha;
        ptcl->visibility.animAlpha = 31;

        if (header->flags.randomInitAngle) {
            ptcl->rotation = SPLRandom_S32(32);
        } else {
            ptcl->rotation = emtr->initAngle;
        }

        if (header->flags.hasRotation) {
            ptcl->angularVelocity = (u32)SPLRandom_BetweenFX32(header->minRotation, header->maxRotation) >> FX32_SHIFT;
        } else {
            ptcl->angularVelocity = 0;
        }

        ptcl->lifeTime = SPLRandom_ScaledRangeFX32(emtr->particleLifeTime, header->randomAttenuation.lifeTime) + 1; // Life is always at least 1 frame
        ptcl->age = 0;

        if (header->flags.hasTexAnim && res->texAnim->param.randomizeInit) {
            ptcl->texture = res->texAnim->textures[SPLRandom_U32(12) % res->texAnim->param.frameCount];
        } else if (header->flags.hasTexAnim && !res->texAnim->param.randomizeInit) {
            ptcl->texture = res->texAnim->textures[0];
        } else {
            ptcl->texture = header->misc.textureIndex;
        }

        ptcl->loopTimeFactor = 0xFFFF / res->header->misc.loopFrames;
        ptcl->lifeTimeFactor = 0xFFFF / ptcl->lifeTime;

        ptcl->lifeRateOffset = 0;

        if (header->flags.randomizeLoopedAnim) {
            ptcl->lifeRateOffset = (u8)SPLRandom_S32(8);
        }
    }
}








/*
 * Particle spawn for the rig emitter (the SPL-style particle system this
 * cluster renders; docs/families/cluster_02052F58.h).  For each of
 * desc->count particles: pop one from the free list (SPLList_PopFront), push it
 * on the owner's live list at +0x14 (SPLList_PushFront), copy the emitter
 * position, set velocity = FX_Mul(emitter velocity, FX_Mul(scale << 12, 0x10))
 * plus a random term in [-velocity, velocity) per axis from the LCG at 0x02146A8C
 * (0x5EEDF715 / 0x1B0CB173, the same generator SPL_EMITTER_UpdateNode uses), and
 * fill scale, colour, the 5-bit tile fields, the rotation pair (3-way
 * switch on desc bits 3..4), life and the two 0xFFFF reciprocal rates.
 *
 * LOAD-BEARING SHAPES (wave 8, each measured):
 *   1. The random term is a MACRO whose rng update is an assignment
 *      expression used as a value, `(g = g * A + C) >> 23`.  The same body
 *      as a static inline function (or a separate Rand() inline) is 792
 *      bytes against 800 and 534 out: the inline's statement boundary moves
 *      the whole velocity block.  The macro puts it at 52 out.
 *   2. `(s32)((u32)e->lifeTime >> 1)`: lsr, not asr, but _s32_div_f, not
 *      _u32_div_f.  An unsigned dividend picks the unsigned helper.
 *   3. `s = (e->baseScale * e->animScale) >> 12` bound to a local, operands in that
 *      order (40 out without it).
 *   4. `struct ParticleView *p;` declared FIRST, before `d`.  With p declared in the
 *      loop body (or after d) the two pointers swap r6/r7 and the last 40
 *      bytes stay out; tools/permuter.py --mode hill (222 singles) could not
 *      move it -- a declaration residue, as docs/notes/permuter.md predicts.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPLEmitter_EmitChildren.c \
 *       --func SPLEmitter_EmitChildren --addr 0x02056684 --arm --cc ../1.2/sp2
 */
void SPLEmitter_EmitChildren(SPLParticle *ptcl, SPLEmitter *emtr, SPLParticleList *list)
{
    struct ParticleView *p;
    struct EmitterParticle *e = (struct EmitterParticle *)ptcl;
    struct EmitOwner *o = (struct EmitOwner *)emtr;
    SPLList *pool = (SPLList *)list;
    struct ParticleDesc *d = o->x->desc;
    fx32 scale = FX_Mul(d->scale << 12, 0x10);
    s32 i;
    for (i = 0; i < d->count; i++) {
        p = (struct ParticleView *)SPLList_PopFront(pool);
        if (p == 0)
            return;
        SPLList_PushFront(&o->list, (SPLNode *)p);
        p->pos = e->pos;
        p->vel.x = FX_Mul(e->vel.x, scale) + RandRange(d->velocity);
        p->vel.y = FX_Mul(e->vel.y, scale) + RandRange(d->velocity);
        p->vel.z = FX_Mul(e->vel.z, scale) + RandRange(d->velocity);
        p->emitterPos = e->emitterPos;
        {
            s32 s = (e->baseScale * e->animScale) >> 12;
            p->baseScale = s * (d->scaleAdd + 1) >> 6;
        }
        p->animScale = 0x1000;
        if (d->f.col)
            p->color = d->color;
        else
            p->color = e->color;
        p->w.b0 = (u16)((e->w.b0 * (e->w.b5 + 1)) >> 5);
        p->w.b5 = 0x1f;
        switch (d->f.sel) {
        case 0:
            p->rotation = 0;
            p->angularVelocity = 0;
            break;
        case 1:
            p->rotation = e->rotation;
            p->angularVelocity = 0;
            break;
        case 2:
            p->rotation = e->rotation;
            p->angularVelocity = e->angularVelocity;
            break;
        }
        p->lifeTime = d->lifeTime;
        p->age = 0;
        p->texture = d->texture;
        p->loopTimeFactor = 0xffff / (s32)((u32)e->lifeTime >> 1);
        p->lifeTimeFactor = 0xffff / e->lifeTime;
        p->lifeRateOffset = 0;
    }
}







static inline void G3_Begin(u32 p) { reg_G3_BEGIN_VTXS = p; }







static inline void G3_End(void) { reg_G3_END_VTXS = 0; }







static inline void G3_TexCoord(fx32 s, fx32 t)
{
    reg_G3_TEXCOORD = (u32)(u16)(s >> 8) | ((u32)(u16)(t >> 8) << 16);
}







static inline void G3_Vtx10(fx16 x, fx16 y, fx16 z)
{
    reg_G3_VTX_10 = GX_VECVTX10(x, y, z);
}








/*
 * One of the two textured-quad emitters in the table at 0x020A7FDC
 * (Rig_Hooks2 = { SPLUtil_DrawXYPlane, SPLUtil_DrawXZPlane }, docs/families/
 * cluster_02052F58.h).  Emits one GX_BEGIN_QUADS quad of side 0x2000 centred
 * on the two passed coordinates, texcoords (0,0) (s,0) (s,t) (0,t).
 * Plane: the second coordinate goes to the VTX_10 y field (bits 10..19).
 *
 * THE SHAPE THAT CLOSED IT (wave 8): the NitroSDK immediate-mode inlines,
 * written as static inline functions with their own parameter types --
 * G3_Begin / G3_TexCoord(fx32 s, fx32 t) / G3_Vtx10(fx16 x, fx16 y, fx16 z)
 * / G3_End -- and a VOID return.  The earlier notes (docs/notes/
 * pkt_02056460.c.txt, residues 2..10) wrote the packing inline with named
 * u16 texcoord locals and needed a u32 return to stay size-exact; that body
 * was stuck at 40/50 concrete bytes of pure register naming.  Passing each
 * coordinate through an fx16 PARAMETER (the SDK's own narrowing, then
 * (x >> 6) & 0x3ff) and each texcoord pair through G3_TexCoord's
 * (u16)(s >> 8) | (u16)(t >> 8) << 16 gives the allocator the image's value
 * order directly, and void is then size-exact too.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPLUtil_DrawXYPlane.c \
 *       --func SPLUtil_DrawXYPlane --addr 0x020565C8 --arm --cc ../1.2/sp2
 */
void SPLUtil_DrawXYPlane(s32 s, s32 t, s32 x, s32 y)
{
    G3_Begin(1);
    G3_TexCoord(0, 0);
    G3_Vtx10((fx16)(x - 0x1000), (fx16)(y + 0x1000), 0);
    G3_TexCoord(s, 0);
    G3_Vtx10((fx16)(x + 0x1000), (fx16)(y + 0x1000), 0);
    G3_TexCoord(s, t);
    G3_Vtx10((fx16)(x + 0x1000), (fx16)(y - 0x1000), 0);
    G3_TexCoord(0, t);
    G3_Vtx10((fx16)(x - 0x1000), (fx16)(y - 0x1000), 0);
    G3_End();
}









/*
 * One of the two textured-quad emitters in the table at 0x020A7FDC
 * (Rig_Hooks2 = { SPLUtil_DrawXYPlane, SPLUtil_DrawXZPlane }, docs/families/
 * cluster_02052F58.h).  Emits one GX_BEGIN_QUADS quad of side 0x2000 centred
 * on the two passed coordinates, texcoords (0,0) (s,0) (s,t) (0,t).
 * Plane: the second coordinate goes to the VTX_10 z field (bits 20..29).
 *
 * THE SHAPE THAT CLOSED IT (wave 8): the NitroSDK immediate-mode inlines,
 * written as static inline functions with their own parameter types --
 * G3_Begin / G3_TexCoord(fx32 s, fx32 t) / G3_Vtx10(fx16 x, fx16 y, fx16 z)
 * / G3_End -- and a VOID return.  The earlier notes (docs/notes/
 * pkt_02056460.c.txt, residues 2..10) wrote the packing inline with named
 * u16 texcoord locals and needed a u32 return to stay size-exact; that body
 * was stuck at 40/50 concrete bytes of pure register naming.  Passing each
 * coordinate through an fx16 PARAMETER (the SDK's own narrowing, then
 * (x >> 6) & 0x3ff) and each texcoord pair through G3_TexCoord's
 * (u16)(s >> 8) | (u16)(t >> 8) << 16 gives the allocator the image's value
 * order directly, and void is then size-exact too.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPLUtil_DrawXZPlane.c \
 *       --func SPLUtil_DrawXZPlane --addr 0x0205650C --arm --cc ../1.2/sp2
 */
void SPLUtil_DrawXZPlane(s32 s, s32 t, s32 x, s32 z)
{
    G3_Begin(1);
    G3_TexCoord(0, 0);
    G3_Vtx10((fx16)(x - 0x1000), 0, (fx16)(z + 0x1000));
    G3_TexCoord(s, 0);
    G3_Vtx10((fx16)(x + 0x1000), 0, (fx16)(z + 0x1000));
    G3_TexCoord(s, t);
    G3_Vtx10((fx16)(x + 0x1000), 0, (fx16)(z - 0x1000));
    G3_TexCoord(0, t);
    G3_Vtx10((fx16)(x - 0x1000), 0, (fx16)(z - 0x1000));
    G3_End();
}









/*
 * Row 1 of the two-entry billboard basis table at 0x020A7FE4
 * (func_02054718_Hooks / func_0205429C_Hooks): { 0x02056420, 0x02056460 }.
 * Both rows take (sin, cos, MtxFx43 *) from a sin/cos pair read out of the
 * Verts table at 0x020A1B38 and fill a 4x3 rig matrix.
 *
 * Row 0 (0x02056420, an unlabelled leaf) is the plain rotation about +Y.
 * This row is the rotation about the diagonal axis (1,1,1)/sqrt(3): the two
 * pool constants are 0x555 = 4096/3 (k*k for k = 1/sqrt(3)) and 0x93D = 2365
 * = 4096/sqrt(3) (k itself), so with d = (1-cos)*k*k and e = sin*k the
 * matrix is the standard axis-angle form, diagonal d+cos and the two
 * off-diagonals d-e and d+e, with the translation row left zero.
 *
 * Returns void, NOT u32: the sibling table rows are declared
 * `u32 (*const [])(s32, s32, void *)` in src/matched/SPL_EMITTER_UpdateFrameA68Ex.c, but a
 * `return 0` here costs the extra `mov r0, r4` and makes the function 176
 * bytes against 172.  The table is a mixed-prototype table.
 *
 * TWO SPELLINGS ARE LOAD-BEARING, both found by tools/permuter.py
 * (--mode anneal --budget 2000, EXACT at compile 1499 from an 8-byte residue):
 *   1. `d + cos` is written out at all THREE diagonal sites, never bound to
 *      one local.  A shared `s32 a = d + cs;` puts the value in lr where the
 *      image has it in r1 (the parameter's own register), 8 bytes out.
 *   2. `cs2 = cs;` splits the live range of the cos parameter before the
 *      second group of stores, and `p = d; p = p + e;` gives the first
 *      `d + e` its own definition point.  Without the split the same 8 bytes
 *      stay wrong.  Both are pure allocator levers; the arithmetic is
 *      unchanged.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_CalcRotMtx.c \
 *       --func SPL_EMITTER_CalcRotMtx --addr 0x02056460 --arm --cc ../1.2/sp2
 */
void SPL_EMITTER_CalcRotMtx(s32 sn, s32 cs, struct MtxFx43 *m)
{
    s32 d = FX_Mul(0x1000 - cs, 0x555);
    s32 e = FX_Mul(sn, 0x93D);
    s32 p;
    s32 cs2;

    p = d;
    p = p + e;

    m->m[0] = d + cs;
    m->m[3] = p;
    m->m[6] = d - e;
    m->m[9] = 0;

    cs2 = cs;
    m->m[1] = d - e;
    m->m[4] = d + cs2;
    m->m[7] = d + e;
    m->m[10] = 0;

    m->m[2] = d + e;
    m->m[5] = d - e;
    m->m[8] = d + cs2;
    m->m[11] = 0;
}






/*
 * Row 0 of the billboard basis table: the plain rotation about +Y, an unlabelled
 * leaf in front of SPL_EMITTER_CalcRotMtx.  It is written after SPL_EMITTER_CalcRotMtx because
 * this compiler places it first in the object only in that source order.
 */
void SPL_EMITTER_SetRotMtx(s32 sn, s32 cs, struct MtxFx43 *m)
{
    m->m[0] = cs;
    m->m[3] = 0;
    m->m[6] = sn;
    m->m[9] = 0;
    m->m[1] = 0;
    m->m[4] = 0x1000;
    m->m[7] = 0;
    m->m[10] = 0;
    m->m[2] = -sn;
    m->m[5] = 0;
    m->m[8] = cs;
    m->m[11] = 0;
}





void SPL_EMITTER_UpdateFrame(struct RigObject *obj, struct RenderNode *s)
{
    struct RigTransformFrame f;
    struct RigDescriptor *p;
    struct MtxFx43 *mtx;
    s32 n;
    s32 baseScale;
    s32 x;
    s32 y;
    s64 baseScale64;
    u32 v;
    s32 i;
    s32 sn;
    s32 cs;
    s32 sc;
    s32 k34;
    u8 sel;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    p = obj->renderList->subList->desc;
    sc = p->scale;
    sel = p->flags28.sel;
    c2 = obj->renderList->color;
    k34 = s->animScale;
    c1 = s->color;
    mtx = obj->mtx;
    v = ((u32)s->w.b10 << 24) | (obj->polygonAttr | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    baseScale = s->baseScale;
    baseScale64 = (s64)(s32)baseScale;
    n = (s32)((baseScale64 * sc + 0x800) >> 12);
    x = n;
    y = baseScale;
    if (sel == 0) {
        x = (s32)(((s64)n * k34 + 0x800) >> 12);
        y = (s32)(((baseScale64 * k34) + 0x800) >> 12);
    } else if (sel == 1) {
        x = (s32)(((s64)n * k34 + 0x800) >> 12);
    } else {
        y = (s32)(((baseScale64 * k34) + 0x800) >> 12);
    }

    p = obj->renderList->subList->desc;
    if (p->flags.z.flag == 0) {
        f.t.x = s->p1.x + s->emitterPosX;
        f.t.y = s->p1.y + s->emitterPosY;
        f.t.z = s->p1.z + s->emitterPosZ;
        MTX_MultVec43((const VecFx32 *)&f.t, (const MtxFx43 *)mtx, (VecFx32 *)&f.t);
        i = (s32)s->rotation >> 4;
        sn = func_02055FD4_Verts[2 * i];
        cs = func_02055FD4_Verts[2 * i + 1];
        f.m.m[0] = FX_Mul(cs, x);
        f.m.m[1] = FX_Mul(sn, x);
        f.m.m[2] = 0;
        f.m.m[3] = FX_Mul(-sn, y);
        f.m.m[4] = FX_Mul(cs, y);
        f.m.m[5] = 0;
        f.m.m[6] = 0;
        f.m.m[7] = 0;
        f.m.m[8] = 0x1000;
        f.m.m[9] = f.t.x;
        f.m.m[10] = f.t.y;
        f.m.m[11] = f.t.z;
        *(volatile u32 *)0x04000454 = 0;
        G3_MultMtx43((const MtxFx43 *)(&f.m));
    } else {
        f.t.x = s->p1.x + s->emitterPosX - p->transX;
        f.t.y = s->p1.y + s->emitterPosY - obj->renderList->subList->desc->transY;
        f.t.z = s->p1.z + s->emitterPosZ - obj->renderList->subList->desc->transZ;
        MTX_MultVec43((const VecFx32 *)&f.t, (const MtxFx43 *)mtx, (VecFx32 *)&f.t);
        i = (s32)s->rotation >> 4;
        sn = func_02055FD4_Verts[2 * i];
        cs = func_02055FD4_Verts[2 * i + 1];
        f.m.m[0] = FX_Mul(cs, x);
        f.m.m[1] = FX_Mul(sn, x);
        f.m.m[2] = 0;
        f.m.m[3] = FX_Mul(-sn, y);
        f.m.m[4] = FX_Mul(cs, y);
        f.m.m[5] = 0;
        f.m.m[6] = 0;
        f.m.m[7] = 0;
        f.m.m[8] = 0x1000;
        f.m.m[9] = f.t.x;
        f.m.m[10] = f.t.y;
        f.m.m[11] = f.t.z;
        *(volatile u32 *)0x04000454 = 0;
        p = obj->renderList->subList->desc;
        qc = p->transZ;  q8 = p->transY;  q4 = p->transX;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        G3_MultMtx43((const MtxFx43 *)(&f.m));
    }

    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    p = obj->renderList->subList->desc;
    SPLUtil_DrawXYPlane(obj->renderList->texS, obj->renderList->texT, p->texS, p->texT);
}



#undef GX_RGB


#undef GX_RGB

#undef GX_RGB
#define GX_RGB(r, g, b) ((GXRgb)(((r) << GX_RGB_R_SHIFT) | ((g) << GX_RGB_G_SHIFT) | ((b) << GX_RGB_B_SHIFT)))






/*
 * Handler row of the rig dispatch (SPL_EMITTER_UpdateSubX / SPL_EMITTER_UpdateSubB pool rows;
 * docs/families/cluster_02052F58.h): a Z-rotation billboard.  Same top as
 * SPL_EMITTER_UpdateFrameMain (POLYGON_ATTR, the three-way scale switch), then instead of
 * the basis hooks it transforms the particle position by the current matrix
 * (MTX_MultVec43), reads sin/cos from the Verts table at
 * s->rotation >> 4, fills a 4x3 matrix ROW-major { cs*x, sn*x, 0 ; -sn*y, cs*y, 0 ;
 * 0, 0, 1 ; t }, loads it (identity + [translate FIFO] + G3_MultMtx43), mixes
 * the colour and calls the quad emitter SPLUtil_DrawXYPlane DIRECTLY.
 *
 * LOAD-BEARING SHAPES (wave 8):
 *   1. RigDescriptor->scale is read into a local BEFORE the 0x040004A4 store, and
 *      obj->mtx likewise (the image loads both there).
 *   2. `a64 = (s64)(s32)a;` comes BEFORE the scale product, and the product
 *      is written `(s32)((a64 * sc + 0x800) >> 12)` on it.  The FX_Mul(a, sc)
 *      inline is 9 bytes out (the lo/hi halves swap registers), and the
 *      permuter's hill pass (399 singles) could not move it.
 *   3. -proc arm946e, NOT the arm7tdmi recorded in docs/notes/
 *      pkt_02055498.c.txt (that note's 740-out body was measured there).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_UpdateFrameEx.c \
 *       --func SPL_EMITTER_UpdateFrameEx --addr 0x02055B80 --arm --cc ../1.2/sp2
 */
void SPL_EMITTER_UpdateFrameEx(struct RigObject *obj, struct RenderNode *s)
{
    struct RigTransformFrame f;
    struct RigDescriptor *p;
    struct MtxFx43 *mtx;
    s32 n;
    s32 baseScale;
    s32 x;
    s32 y;
    s64 baseScale64;
    u32 v;
    s32 i;
    s32 sn;
    s32 cs;
    s32 sc;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    sc = obj->renderList->subList->desc->scale;
    mtx = obj->mtx;
    v = ((u32)s->w.b10 << 24) | (obj->polygonAttr | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    baseScale = s->baseScale;
    baseScale64 = (s64)(s32)baseScale;
    n = (s32)((baseScale64 * sc + 0x800) >> 12);
    x = n;
    y = baseScale;
    p = obj->renderList->subList->desc;
    switch (p->flags28.sel) {
    case 0:
        x = (s32)(((s64)n * s->animScale + 0x800) >> 12);
        y = (s32)(((baseScale64 * s->animScale) + 0x800) >> 12);
        break;
    case 1:
        x = (s32)(((s64)n * s->animScale + 0x800) >> 12);
        break;
    case 2:
        y = (s32)(((baseScale64 * s->animScale) + 0x800) >> 12);
        break;
    default:
        break;
    }

    if (p->flags.z.flag == 0) {
        f.t.x = s->p1.x + s->emitterPosX;
        f.t.y = s->p1.y + s->emitterPosY;
        f.t.z = s->p1.z + s->emitterPosZ;
        MTX_MultVec43((const VecFx32 *)&f.t, (const MtxFx43 *)mtx, (VecFx32 *)&f.t);
        i = (s32)s->rotation >> 4;
        sn = func_02055B80_Verts[2 * i];
        cs = func_02055B80_Verts[2 * i + 1];
        f.m.m[0] = FX_Mul(cs, x);
        f.m.m[1] = FX_Mul(sn, x);
        f.m.m[2] = 0;
        f.m.m[3] = FX_Mul(-sn, y);
        f.m.m[4] = FX_Mul(cs, y);
        f.m.m[5] = 0;
        f.m.m[6] = 0;
        f.m.m[7] = 0;
        f.m.m[8] = 0x1000;
        f.m.m[9] = f.t.x;
        f.m.m[10] = f.t.y;
        f.m.m[11] = f.t.z;
        *(volatile u32 *)0x04000454 = 0;
        G3_MultMtx43((const MtxFx43 *)(&f.m));
    } else {
        f.t.x = s->p1.x + s->emitterPosX - p->transX;
        f.t.y = s->p1.y + s->emitterPosY - obj->renderList->subList->desc->transY;
        f.t.z = s->p1.z + s->emitterPosZ - obj->renderList->subList->desc->transZ;
        MTX_MultVec43((const VecFx32 *)&f.t, (const MtxFx43 *)mtx, (VecFx32 *)&f.t);
        i = (s32)s->rotation >> 4;
        sn = func_02055B80_Verts[2 * i];
        cs = func_02055B80_Verts[2 * i + 1];
        f.m.m[0] = FX_Mul(cs, x);
        f.m.m[1] = FX_Mul(sn, x);
        f.m.m[2] = 0;
        f.m.m[3] = FX_Mul(-sn, y);
        f.m.m[4] = FX_Mul(cs, y);
        f.m.m[5] = 0;
        f.m.m[6] = 0;
        f.m.m[7] = 0;
        f.m.m[8] = 0x1000;
        f.m.m[9] = f.t.x;
        f.m.m[10] = f.t.y;
        f.m.m[11] = f.t.z;
        *(volatile u32 *)0x04000454 = 0;
        p = obj->renderList->subList->desc;
        qc = p->transZ;  q8 = p->transY;  q4 = p->transX;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        G3_MultMtx43((const MtxFx43 *)(&f.m));
    }

    c1 = s->color;
    c2 = obj->renderList->color;
    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    SPLUtil_DrawXYPlane(obj->renderList->texS2, obj->renderList->texT2, 0, 0);
}






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
#define SPLRandom_RangeFX32(num) (((num) * (s32)SPLRandom_U32(9) - ((num) << 8)) >> 8)







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






/*
 * SPLDraw_DirectionalBillboard: the parent-particle twin of SPL_EMITTER_UpdateParticleMotionEx,
 * ending in SPLUtil_DrawXYPlane with the emitter texture tiling and the
 * resource header polygonX/polygonY offsets.
 *
 * Wave 9, third lane: this body and every declaration it uses are the public
 * pret/pokeplatinum decompilation of the same NitroSystem particle library
 * (SPL; docs/families/cluster_02052F58.h), lib/spl/src/spl_draw.c SPLDraw_DirectionalBillboard, with the
 * lib/spl/include/spl_*.h structs, and the SDK G3/MTX/VEC inlines written out
 * from sdk/TwlSDK/include; only the callees are pinned to Black addresses.
 * It compiled EXACT at the cluster pin unchanged, closing docs/notes/pkt_02055498.c.txt (286 out after two lanes).
 */
void SPL_EMITTER_UpdateParticleMotion(SPLManager *mgr, SPLParticle *ptcl)
{
    VecFx32 vel_dir;
    VecFx32 trs;
    fx32 sclX, sclY;
    VecFx32 dir, look;
    MtxFx33 mat;
    MtxFx43 load;

    const MtxFx43 *cmr = mgr->renderState.viewMatrix;
    fx32 aspect = mgr->renderState.emitter->resource->header->aspectRatio;

    if (SPLDraw_Setup(ptcl, mgr)) {
        return;
    }

    sclY = ptcl->baseScale;
    sclX = FX_MUL(sclY, aspect);

    switch (mgr->renderState.emitter->resource->header->misc.scaleAnimDir) {
    case SPL_SCALE_ANIM_DIR_XY:
        sclX = FX_MUL(sclX, ptcl->animScale);
        sclY = FX_MUL(sclY, ptcl->animScale);
        break;

    case SPL_SCALE_ANIM_DIR_X:
        sclX = FX_MUL(sclX, ptcl->animScale);
        break;

    case SPL_SCALE_ANIM_DIR_Y:
        sclY = FX_MUL(sclY, ptcl->animScale);
        break;
    }

    if (!mgr->renderState.emitter->resource->header->flags.useViewSpace) {
        trs.x = ptcl->position.x + ptcl->emitterPos.x;
        trs.y = ptcl->position.y + ptcl->emitterPos.y;
        trs.z = ptcl->position.z + ptcl->emitterPos.z;

        dir = ptcl->velocity;

        look.x = cmr->m[0][2];
        look.y = cmr->m[1][2];
        look.z = cmr->m[2][2];

        VEC_CrossProduct(&dir, &look, &dir);
        if (dir.x == 0 && dir.y == 0 && dir.z == 0) {
            return;
        }

        VEC_Normalize(&dir, &dir);
        MTX_Copy43To33(cmr, &mat);
        MTX_MultVec33(&dir, &mat, &dir);
        MTX_MultVec43(&trs, cmr, &trs);

        vel_dir = ptcl->velocity;
        VEC_Normalize(&vel_dir, &vel_dir);

        fx32 dot = FX_MUL(vel_dir.x, -cmr->m[0][2]) + FX_MUL(vel_dir.y, -cmr->m[1][2]) + FX_MUL(vel_dir.z, -cmr->m[2][2]);
        if (dot < 0) {
            dot = -dot;
        }

        dot = FX_MUL(sclY, FX_MUL(FX32_ONE - dot, (fx32)mgr->renderState.emitter->resource->header->misc.dbbScale) + FX32_ONE);
        load.m[0][0] = FX_MUL(dir.x, sclX);
        load.m[1][0] = FX_MUL(-dir.y, dot);
        load.m[2][0] = 0;
        load.m[3][0] = trs.x;
        load.m[0][1] = FX_MUL(dir.y, sclX);
        load.m[1][1] = FX_MUL(dir.x, dot);
        load.m[2][1] = 0;
        load.m[3][1] = trs.y;
        load.m[0][2] = 0;
        load.m[1][2] = 0;
        load.m[2][2] = FX32_ONE;
        load.m[3][2] = trs.z;

        G3_Identity();
        G3_MultMtx43(&load);
    } else {
        trs.x = ptcl->position.x + ptcl->emitterPos.x - mgr->renderState.emitter->resource->header->emitterBasePos.x;
        trs.y = ptcl->position.y + ptcl->emitterPos.y - mgr->renderState.emitter->resource->header->emitterBasePos.y;
        trs.z = ptcl->position.z + ptcl->emitterPos.z - mgr->renderState.emitter->resource->header->emitterBasePos.z;

        dir = ptcl->velocity;

        look.x = cmr->m[0][2];
        look.y = cmr->m[1][2];
        look.z = cmr->m[2][2];

        VEC_CrossProduct(&dir, &look, &dir);
        if (dir.x == 0 && dir.y == 0 && dir.z == 0) {
            return;
        }

        VEC_Normalize(&dir, &dir);
        MTX_Copy43To33(cmr, &mat);
        MTX_MultVec33(&dir, &mat, &dir);
        MTX_MultVec43(&trs, cmr, &trs);

        vel_dir = ptcl->velocity;
        VEC_Normalize(&vel_dir, &vel_dir);

        fx32 dot = FX_MUL(vel_dir.x, -cmr->m[0][2]) + FX_MUL(vel_dir.y, -cmr->m[1][2]) + FX_MUL(vel_dir.z, -cmr->m[2][2]);
        if (dot < 0) {
            dot = -dot;
        }

        dot = FX_MUL(sclY, FX_MUL(FX32_ONE - dot, (fx32)mgr->renderState.emitter->resource->header->misc.dbbScale) + FX32_ONE);
        load.m[0][0] = FX_MUL(dir.x, sclX);
        load.m[1][0] = FX_MUL(-dir.y, dot);
        load.m[2][0] = 0;
        load.m[3][0] = trs.x;
        load.m[0][1] = FX_MUL(dir.y, sclX);
        load.m[1][1] = FX_MUL(dir.x, dot);
        load.m[2][1] = 0;
        load.m[3][1] = trs.y;
        load.m[0][2] = 0;
        load.m[1][2] = 0;
        load.m[2][2] = FX32_ONE;
        load.m[3][2] = trs.z;

        G3_Identity();
        G3_Translate(
            mgr->renderState.emitter->resource->header->emitterBasePos.x,
            mgr->renderState.emitter->resource->header->emitterBasePos.y,
            mgr->renderState.emitter->resource->header->emitterBasePos.z);
        G3_MultMtx43(&load);
    }

    G3_Color(GX_RGB(
        GX_RGB_R_(ptcl->color) * GX_RGB_R_(mgr->renderState.emitter->color) >> 5,
        GX_RGB_G_(ptcl->color) * GX_RGB_G_(mgr->renderState.emitter->color) >> 15,
        GX_RGB_B_(ptcl->color) * GX_RGB_B_(mgr->renderState.emitter->color) >> 25));

    SPLEmitter *emtr = mgr->renderState.emitter;
    SPLUtil_DrawXYPlane(
        emtr->textureS,
        emtr->textureT,
        emtr->resource->header->polygonX,
        emtr->resource->header->polygonY);
}







/*
 * SPLDraw_Child_DirectionalBillboard: draws one child particle as a
 * billboard stretched along its velocity (the "directional billboard" draw
 * type), through SPLDraw_Setup (POLYGON_ATTR), a hand-built 4x3 load matrix
 * and SPLUtil_DrawXYPlane (SPLUtil_DrawXYPlane) with the child texture tiling.
 *
 * Wave 9, third lane: this body and every declaration it uses are the public
 * pret/pokeplatinum decompilation of the same NitroSystem particle library
 * (SPL; docs/families/cluster_02052F58.h), lib/spl/src/spl_draw.c SPLDraw_Child_DirectionalBillboard, with the
 * lib/spl/include/spl_*.h structs, and the SDK G3/MTX/VEC inlines written out
 * from sdk/TwlSDK/include; only the callees are pinned to Black addresses.
 * It compiled EXACT at the cluster pin unchanged, closing docs/notes/SPL_EMITTER_UpdateParticleMotionEx.c.txt (286 out after two lanes).
 */
void SPL_EMITTER_UpdateParticleMotionEx(SPLManager *mgr, SPLParticle *ptcl)
{
    VecFx32 vel_dir;
    VecFx32 trs;
    fx32 sclX, sclY;
    VecFx32 dir, look;
    MtxFx33 mat;
    MtxFx43 load;

    const MtxFx43 *cmr = mgr->renderState.viewMatrix;
    fx32 aspect = mgr->renderState.emitter->resource->header->aspectRatio;

    if (SPLDraw_Setup(ptcl, mgr)) {
        return;
    }

    sclY = ptcl->baseScale;
    sclX = FX_MUL(sclY, aspect);

    switch (mgr->renderState.emitter->resource->header->misc.scaleAnimDir) {
    case SPL_SCALE_ANIM_DIR_XY:
        sclX = FX_MUL(sclX, ptcl->animScale);
        sclY = FX_MUL(sclY, ptcl->animScale);
        break;

    case SPL_SCALE_ANIM_DIR_X:
        sclX = FX_MUL(sclX, ptcl->animScale);
        break;

    case SPL_SCALE_ANIM_DIR_Y:
        sclY = FX_MUL(sclY, ptcl->animScale);
        break;
    }

    if (!mgr->renderState.emitter->resource->header->flags.useViewSpace) {
        trs.x = ptcl->position.x + ptcl->emitterPos.x;
        trs.y = ptcl->position.y + ptcl->emitterPos.y;
        trs.z = ptcl->position.z + ptcl->emitterPos.z;

        dir = ptcl->velocity;

        look.x = cmr->m[0][2];
        look.y = cmr->m[1][2];
        look.z = cmr->m[2][2];

        VEC_CrossProduct(&dir, &look, &dir);
        if (dir.x == 0 && dir.y == 0 && dir.z == 0) {
            return;
        }

        VEC_Normalize(&dir, &dir);
        MTX_Copy43To33(cmr, &mat);
        MTX_MultVec33(&dir, &mat, &dir);
        MTX_MultVec43(&trs, cmr, &trs);

        vel_dir = ptcl->velocity;
        VEC_Normalize(&vel_dir, &vel_dir);

        fx32 dot = FX_MUL(vel_dir.x, -cmr->m[0][2]) + FX_MUL(vel_dir.y, -cmr->m[1][2]) + FX_MUL(vel_dir.z, -cmr->m[2][2]);
        if (dot < 0) {
            dot = -dot;
        }

        dot = FX_MUL(sclY, FX_MUL(FX32_ONE - dot, (fx32)mgr->renderState.emitter->resource->header->misc.dbbScale) + FX32_ONE);
        load.m[0][0] = FX_MUL(dir.x, sclX);
        load.m[1][0] = FX_MUL(-dir.y, dot);
        load.m[2][0] = 0;
        load.m[3][0] = trs.x;
        load.m[0][1] = FX_MUL(dir.y, sclX);
        load.m[1][1] = FX_MUL(dir.x, dot);
        load.m[2][1] = 0;
        load.m[3][1] = trs.y;
        load.m[0][2] = 0;
        load.m[1][2] = 0;
        load.m[2][2] = FX32_ONE;
        load.m[3][2] = trs.z;

        G3_Identity();
        G3_MultMtx43(&load);
    } else {
        trs.x = ptcl->position.x + ptcl->emitterPos.x - mgr->renderState.emitter->resource->header->emitterBasePos.x;
        trs.y = ptcl->position.y + ptcl->emitterPos.y - mgr->renderState.emitter->resource->header->emitterBasePos.y;
        trs.z = ptcl->position.z + ptcl->emitterPos.z - mgr->renderState.emitter->resource->header->emitterBasePos.z;

        dir = ptcl->velocity;

        look.x = cmr->m[0][2];
        look.y = cmr->m[1][2];
        look.z = cmr->m[2][2];

        VEC_CrossProduct(&dir, &look, &dir);
        if (dir.x == 0 && dir.y == 0 && dir.z == 0) {
            return;
        }

        VEC_Normalize(&dir, &dir);
        MTX_Copy43To33(cmr, &mat);
        MTX_MultVec33(&dir, &mat, &dir);
        MTX_MultVec43(&trs, cmr, &trs);

        vel_dir = ptcl->velocity;
        VEC_Normalize(&vel_dir, &vel_dir);

        fx32 dot = FX_MUL(vel_dir.x, -cmr->m[0][2]) + FX_MUL(vel_dir.y, -cmr->m[1][2]) + FX_MUL(vel_dir.z, -cmr->m[2][2]);
        if (dot < 0) {
            dot = -dot;
        }

        dot = FX_MUL(sclY, FX_MUL(FX32_ONE - dot, (fx32)mgr->renderState.emitter->resource->header->misc.dbbScale) + FX32_ONE);
        load.m[0][0] = FX_MUL(dir.x, sclX);
        load.m[1][0] = FX_MUL(-dir.y, dot);
        load.m[2][0] = 0;
        load.m[3][0] = trs.x;
        load.m[0][1] = FX_MUL(dir.y, sclX);
        load.m[1][1] = FX_MUL(dir.x, dot);
        load.m[2][1] = 0;
        load.m[3][1] = trs.y;
        load.m[0][2] = 0;
        load.m[1][2] = 0;
        load.m[2][2] = FX32_ONE;
        load.m[3][2] = trs.z;

        G3_Identity();
        G3_Translate(
            mgr->renderState.emitter->resource->header->emitterBasePos.x,
            mgr->renderState.emitter->resource->header->emitterBasePos.y,
            mgr->renderState.emitter->resource->header->emitterBasePos.z);
        G3_MultMtx43(&load);
    }

    G3_Color(GX_RGB(
        GX_RGB_R_(ptcl->color) * GX_RGB_R_(mgr->renderState.emitter->color) >> 5,
        GX_RGB_G_(ptcl->color) * GX_RGB_G_(mgr->renderState.emitter->color) >> 15,
        GX_RGB_B_(ptcl->color) * GX_RGB_B_(mgr->renderState.emitter->color) >> 25));

    SPLUtil_DrawXYPlane(mgr->renderState.emitter->childTextureS, mgr->renderState.emitter->childTextureT, 0, 0);
}







extern u32 (*const func_02054A68_Hooks[])(s32, s32, void *);







extern u32 (*const func_02054A68_Hooks2[])(s32, s32, s32, s32);








/*
 * Member of the 1.2-pinned 3D rig family (docs/FRONTEND-PINS.md): a register
 * `blx rN` (0x02054B10, 0x02054D8C) beside an ARMv4T-style return
 * (0x02054AC0, 0x02054D94).
 *
 * -proc is arm946e, from the bytes: layout/proc_hints.txt infers arm7tdmi
 * for pkt_0205429C from its pop-lr epilogues, but arm7tdmi cannot emit the
 * register `blx rN` these bytes contain.  EXACT at 848/848 under
 * `compiler: ../1.2/sp2`, `flags: -O4,p -proc arm946e`.
 *
 * Twin of SPL_EMITTER_UpdateFrameA68Ex: the prologue, the frames and the arm bodies are
 * byte-identical; it differs in the hook selector (bits 17..18 of
 * RigDescriptor.flags rather than the u16 at RigSubList+0x14), in the MTX_Concat43 argument
 * order, and in a four-argument final hook.
 *
 * The same four source shapes that close SPL_EMITTER_UpdateFrameA68Ex close this row; see
 * its header for the measurements (the 0x040004A4 `|` chain order, the
 * `(s64)a * res->aspectAndDelay` operand order, `x` before `y` in case 0, and the three
 * 0x04000470 stores through locals loaded in reverse field order).
 *
 * Addresses are Black-image addresses.
 */
void SPL_EMITTER_UpdateFrameA68(struct RigObject *obj, struct RenderNode *s)
{
    struct RigTransformFrameA68 f;
    struct RigDescriptor *p;
    s32 n;
    s32 i;
    s32 baseScale;
    s32 x;
    s32 y;
    s64 baseScale64;
    u32 v;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    v = ((u32)s->w.b10 << 24) | (obj->polygonAttr | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    i = (s32)s->rotation >> 4;
    func_02054A68_Hooks[obj->renderList->subList->desc->flags.z.sel2]
        (func_02054A68_Verts[2 * i], func_02054A68_Verts[2 * i + 1], &f.m2);

    baseScale = s->baseScale;
    n = (s32)(((s64)baseScale * obj->renderList->subList->desc->scale + 0x800) >> 12);
    x = n;
    y = baseScale;
    baseScale64 = (s64)(s32)baseScale;
    switch (obj->renderList->subList->desc->flags28.sel) {
    case 0:
        x = (s32)(((s64)n * s->animScale + 0x800) >> 12);
        y = (s32)(((baseScale64 * s->animScale) + 0x800) >> 12);
        break;
    case 1:
        x = (s32)(((s64)n * s->animScale + 0x800) >> 12);
        break;
    case 2:
        y = (s32)(((baseScale64 * s->animScale) + 0x800) >> 12);
        break;
    default:
        break;
    }

    MTX_Scale43_(&f.m3, x, y, y);
    MTX_Concat43(&f.m3, &f.m2, &f.m1);

    if (obj->renderList->subList->desc->flags.z.flag == 0) {
        f.m1.m[9] = s->p1.x + s->emitterPosX;
        f.m1.m[10] = s->p1.y + s->emitterPosY;
        f.m1.m[11] = s->p1.z + s->emitterPosZ;
        G3_LoadMtx43(obj->mtx);
        G3_MultMtx43((const MtxFx43 *)(&f.m1));
    } else {
        f.m1.m[9] = s->p1.x + s->emitterPosX - obj->renderList->subList->desc->transX;
        f.m1.m[10] = s->p1.y + s->emitterPosY - obj->renderList->subList->desc->transY;
        f.m1.m[11] = s->p1.z + s->emitterPosZ - obj->renderList->subList->desc->transZ;
        *(volatile u32 *)0x04000454 = 0;
        p = obj->renderList->subList->desc;
        qc = p->transZ;  q8 = p->transY;  q4 = p->transX;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        G3_MultMtx43((const MtxFx43 *)(obj->mtx));
        G3_MultMtx43((const MtxFx43 *)(&f.m1));
    }

    c1 = s->color;
    c2 = obj->renderList->color;
    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    p = obj->renderList->subList->desc;
    func_02054A68_Hooks2[p->flags.z.sel1]
        (obj->renderList->texS, obj->renderList->texT, p->texS, p->texT);
}





extern u32 (*const func_02054718_Hooks[])(s32, s32, void *);





extern u32 (*const func_02054718_Hooks2[])(s32, s32, s32, s32);






void SPL_EMITTER_UpdateFrameA68Ex(struct RigObject *obj, struct RenderNode *s)
{
    struct RigTransformFrameA68 f;
    struct RigDescriptor *p;
    s32 n;
    s32 e;
    s32 i;
    s32 baseScale;
    s32 x;
    s32 y;
    s64 baseScale64;
    u32 v;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    v = ((u32)s->w.b10 << 24) | (obj->polygonAttr | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    i = (s32)s->rotation >> 4;
    func_02054718_Hooks[obj->renderList->subList->hw->hw.sel2]
        (func_02054718_Verts[2 * i], func_02054718_Verts[2 * i + 1], &f.m2);

    baseScale = s->baseScale;
    n = (s32)(((s64)baseScale * obj->renderList->subList->desc->scale + 0x800) >> 12);
    x = n;
    y = baseScale;
    baseScale64 = (s64)(s32)baseScale;
    switch (obj->renderList->subList->desc->flags28.sel) {
    case 0:
        x = (s32)(((s64)n * s->animScale + 0x800) >> 12);
        y = (s32)(((baseScale64 * s->animScale) + 0x800) >> 12);
        break;
    case 1:
        x = (s32)(((s64)n * s->animScale + 0x800) >> 12);
        break;
    case 2:
        y = (s32)(((baseScale64 * s->animScale) + 0x800) >> 12);
        break;
    default:
        break;
    }

    MTX_Scale43_(&f.m3, x, y, y);
    MTX_Concat43(&f.m2, &f.m3, &f.m1);

    if (obj->renderList->subList->desc->flags.z.flag == 0) {
        f.m1.m[9] = s->p1.x + s->emitterPosX;
        f.m1.m[10] = s->p1.y + s->emitterPosY;
        f.m1.m[11] = s->p1.z + s->emitterPosZ;
        G3_LoadMtx43(obj->mtx);
        G3_MultMtx43((const MtxFx43 *)(&f.m1));
    } else {
        f.m1.m[9] = s->p1.x + s->emitterPosX - obj->renderList->subList->desc->transX;
        f.m1.m[10] = s->p1.y + s->emitterPosY - obj->renderList->subList->desc->transY;
        f.m1.m[11] = s->p1.z + s->emitterPosZ - obj->renderList->subList->desc->transZ;
        *(volatile u32 *)0x04000454 = 0;
        p = obj->renderList->subList->desc;
        qc = p->transZ;  q8 = p->transY;  q4 = p->transX;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        G3_MultMtx43((const MtxFx43 *)(obj->mtx));
        G3_MultMtx43((const MtxFx43 *)(&f.m1));
    }

    c1 = s->color;
    c2 = obj->renderList->color;
    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    e = 0;
    func_02054718_Hooks2[obj->renderList->subList->hw->hw.sel1]
        (obj->renderList->texS2, obj->renderList->texT2, e, e);
}






extern u32 (*const func_0205429C_Hooks[])(s32, s32, void *);






extern u32 (*const func_0205429C_Hooks2[])(s32, s32, s32, s32);







void SPL_EMITTER_UpdateFrameMain(struct RigObject *obj, struct RenderNode *s)
{
    struct RigTransformFrameMain f;
    struct RigDescriptor *p;
    s32 n;
    s32 i;
    s32 baseScale;
    s32 x;
    s32 y;
    s64 baseScale64;
    u32 v;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    v = ((u32)s->w.b10 << 24) | (obj->polygonAttr | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    i = (s32)s->rotation >> 4;
    func_0205429C_Hooks[obj->renderList->subList->desc->flags.z.sel2]
        (func_0205429C_Verts[2 * i], func_0205429C_Verts[2 * i + 1], &f.m2);

    MTX_Identity43_(&f.m4);
    if (obj->renderList->subList->desc->flags28.hi == 0) {
        VEC_Normalize((const VecFx32 *)&s->p2, (VecFx32 *)&f.dir);
    } else {
        VEC_Normalize((const VecFx32 *)&s->p1, (VecFx32 *)&f.dir);
        f.dir.x = -f.dir.x;
        f.dir.y = -f.dir.y;
        f.dir.z = -f.dir.z;
    }

    f.upRef.x = 0;
    f.upRef.y = 0x1000;
    f.upRef.z = 0;
    i = VEC_DotProduct(&f.dir, &f.upRef);
    if (i > 0xCCD || i < -0xCCD) {
        f.upRef.x = 0x1000;
        f.upRef.y = 0;
        f.upRef.z = 0;
    }

    VEC_CrossProduct(&f.dir, &f.upRef, &f.right);
    VEC_CrossProduct(&f.dir, &f.right, &f.up);

    f.m4.m[0] = f.right.x;
    f.m4.m[1] = f.right.y;
    f.m4.m[2] = f.right.z;
    f.m4.m[3] = f.dir.x;
    f.m4.m[4] = f.dir.y;
    f.m4.m[5] = f.dir.z;
    f.m4.m[6] = f.up.x;
    f.m4.m[7] = f.up.y;
    f.m4.m[8] = f.up.z;

    MTX_Concat43(&f.m2, &f.m4, &f.m2);

    baseScale = s->baseScale;
    n = (s32)(((s64)baseScale * obj->renderList->subList->desc->scale + 0x800) >> 12);
    x = n;
    y = baseScale;
    baseScale64 = (s64)(s32)baseScale;
    switch (obj->renderList->subList->desc->flags28.sel) {
    case 0:
        x = (s32)(((s64)n * s->animScale + 0x800) >> 12);
        y = (s32)(((baseScale64 * s->animScale) + 0x800) >> 12);
        break;
    case 1:
        x = (s32)(((s64)n * s->animScale + 0x800) >> 12);
        break;
    case 2:
        y = (s32)(((baseScale64 * s->animScale) + 0x800) >> 12);
        break;
    default:
        break;
    }

    MTX_Scale43_(&f.m3, x, y, y);
    MTX_Concat43(&f.m3, &f.m2, &f.m1);

    if (obj->renderList->subList->desc->flags.z.flag == 0) {
        f.m1.m[9] = s->p1.x + s->emitterPosX;
        f.m1.m[10] = s->p1.y + s->emitterPosY;
        f.m1.m[11] = s->p1.z + s->emitterPosZ;
        G3_LoadMtx43(obj->mtx);
        G3_MultMtx43((const MtxFx43 *)(&f.m1));
    } else {
        f.m1.m[9] = s->p1.x + s->emitterPosX - obj->renderList->subList->desc->transX;
        f.m1.m[10] = s->p1.y + s->emitterPosY - obj->renderList->subList->desc->transY;
        f.m1.m[11] = s->p1.z + s->emitterPosZ - obj->renderList->subList->desc->transZ;
        *(volatile u32 *)0x04000454 = 0;
        p = obj->renderList->subList->desc;
        qc = p->transZ;  q8 = p->transY;  q4 = p->transX;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        G3_MultMtx43((const MtxFx43 *)(obj->mtx));
        G3_MultMtx43((const MtxFx43 *)(&f.m1));
    }

    c1 = s->color;
    c2 = obj->renderList->color;
    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    p = obj->renderList->subList->desc;
    func_0205429C_Hooks2[p->flags.z.sel1]
        (obj->renderList->texS, obj->renderList->texT, p->texS, p->texT);
}








extern u32 (*const func_02053E1C_Hooks[])(s32, s32, void *);








extern u32 (*const func_02053E1C_Hooks2[])(s32, s32, s32, s32);









/*
 * Handler row 0 of the rig render-list dispatch (SPL_EMITTER_UpdateSubX /
 * SPL_EMITTER_UpdateSubB pool rows; docs/families/cluster_02052F58.h).  Same skeleton
 * as SPL_EMITTER_UpdateFrameMain, transcribed from it with five differences read off the
 * listing:
 *   - the basis hook is selected by RigDescriptorHw->hw bits 9..10 (SubHwFlags.sel2, as in
 *     SPL_EMITTER_UpdateFrameA68Ex), not RigDescriptor->flags bits 17..18;
 *   - the direction/negated-position choice is RigDescriptorHw->selFlags bit 6 (SubSelFlags.sel),
 *     not RigDescriptor->flags28 bit 31;
 *   - the scale concat is MTX_Concat43(m2, m3, m1) -- operands the other way
 *     round from SPL_EMITTER_UpdateFrameMain's (m3, m2, m1); the only 2 bytes the straight
 *     transcription had wrong;
 *   - the quad-emitter hook is RigDescriptorHw->hw bit 11 (SubHwFlags.sel1);
 *   - its arguments are RigRenderList +0x7c/+0x7e and two literal zeros.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_UpdateFrameMainEx.c \
 *       --func SPL_EMITTER_UpdateFrameMainEx --addr 0x02053E1C --arm --cc ../1.2/sp2
 */
void SPL_EMITTER_UpdateFrameMainEx(struct RigObject *obj, struct RenderNode *s)
{
    struct RigTransformFrameMain f;
    struct RigDescriptor *p;
    s32 n;
    s32 i;
    s32 baseScale;
    s32 x;
    s32 y;
    s64 baseScale64;
    u32 v;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    v = ((u32)s->w.b10 << 24) | (obj->polygonAttr | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    i = (s32)s->rotation >> 4;
    func_02053E1C_Hooks[obj->renderList->subList->hw->hw.sel2]
        (func_02053E1C_Verts[2 * i], func_02053E1C_Verts[2 * i + 1], &f.m2);

    MTX_Identity43_(&f.m4);
    if (obj->renderList->subList->hw->selFlags.sel == 0) {
        VEC_Normalize((const VecFx32 *)&s->p2, (VecFx32 *)&f.dir);
    } else {
        VEC_Normalize((const VecFx32 *)&s->p1, (VecFx32 *)&f.dir);
        f.dir.x = -f.dir.x;
        f.dir.y = -f.dir.y;
        f.dir.z = -f.dir.z;
    }

    f.upRef.x = 0;
    f.upRef.y = 0x1000;
    f.upRef.z = 0;
    i = VEC_DotProduct(&f.dir, &f.upRef);
    if (i > 0xCCD || i < -0xCCD) {
        f.upRef.x = 0x1000;
        f.upRef.y = 0;
        f.upRef.z = 0;
    }

    VEC_CrossProduct(&f.dir, &f.upRef, &f.right);
    VEC_CrossProduct(&f.dir, &f.right, &f.up);

    f.m4.m[0] = f.right.x;
    f.m4.m[1] = f.right.y;
    f.m4.m[2] = f.right.z;
    f.m4.m[3] = f.dir.x;
    f.m4.m[4] = f.dir.y;
    f.m4.m[5] = f.dir.z;
    f.m4.m[6] = f.up.x;
    f.m4.m[7] = f.up.y;
    f.m4.m[8] = f.up.z;

    MTX_Concat43(&f.m2, &f.m4, &f.m2);

    baseScale = s->baseScale;
    n = (s32)(((s64)baseScale * obj->renderList->subList->desc->scale + 0x800) >> 12);
    x = n;
    y = baseScale;
    baseScale64 = (s64)(s32)baseScale;
    switch (obj->renderList->subList->desc->flags28.sel) {
    case 0:
        x = (s32)(((s64)n * s->animScale + 0x800) >> 12);
        y = (s32)(((baseScale64 * s->animScale) + 0x800) >> 12);
        break;
    case 1:
        x = (s32)(((s64)n * s->animScale + 0x800) >> 12);
        break;
    case 2:
        y = (s32)(((baseScale64 * s->animScale) + 0x800) >> 12);
        break;
    default:
        break;
    }

    MTX_Scale43_(&f.m3, x, y, y);
    MTX_Concat43(&f.m2, &f.m3, &f.m1);

    if (obj->renderList->subList->desc->flags.z.flag == 0) {
        f.m1.m[9] = s->p1.x + s->emitterPosX;
        f.m1.m[10] = s->p1.y + s->emitterPosY;
        f.m1.m[11] = s->p1.z + s->emitterPosZ;
        G3_LoadMtx43(obj->mtx);
        G3_MultMtx43((const MtxFx43 *)(&f.m1));
    } else {
        f.m1.m[9] = s->p1.x + s->emitterPosX - obj->renderList->subList->desc->transX;
        f.m1.m[10] = s->p1.y + s->emitterPosY - obj->renderList->subList->desc->transY;
        f.m1.m[11] = s->p1.z + s->emitterPosZ - obj->renderList->subList->desc->transZ;
        *(volatile u32 *)0x04000454 = 0;
        p = obj->renderList->subList->desc;
        qc = p->transZ;  q8 = p->transY;  q4 = p->transX;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        G3_MultMtx43((const MtxFx43 *)(obj->mtx));
        G3_MultMtx43((const MtxFx43 *)(&f.m1));
    }

    c1 = s->color;
    c2 = obj->renderList->color;
    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    func_02053E1C_Hooks2[obj->renderList->subList->hw->hw.sel1]
        (obj->renderList->texS2, obj->renderList->texT2, 0, 0);
}








static inline void G3_TexImageParam(GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS sSize, GXTexSizeT tSize, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    reg_G3_TEXIMAGE_PARAM = GX_PACK_TEXIMAGE_PARAM(texFmt, texGen, sSize, tSize, repeat, flip, pltt0, addr);
}








static inline void G3_TexPlttBase(u32 addr, GXTexFmt texfmt)
{
    reg_G3_TEXPLTT_BASE = GX_PACK_TEXPLTTBASE_PARAM(addr, texfmt);
}








static inline void G3_MtxMode(GXMtxMode mode) { reg_G3_MTX_MODE = (u32)mode; }








static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    reg_G3_MTX_SCALE = (u32)x;
    reg_G3_MTX_SCALE = (u32)y;
    reg_G3_MTX_SCALE = (u32)z;
}








/*
 * SPLUtil_SetTexture of the NitroSystem-style particle library (SPL) this
 * cluster is: the texture-row setup both draw dispatchers call.  The body is
 * the SDK's own G3 inline sequence, G3_TexImageParam / G3_TexPlttBase /
 * G3_MtxMode / G3_Identity / G3_Scale / G3_MtxMode, over a copy of the
 * row's SPLTextureParam union (the copy is the dead `str r7, [sp]`).
 *
 * Closes docs/notes/SPL_EMITTER_SetTextureParam.c.txt (41 out after two lanes, the whole
 * residue register naming).  What closed it, wave 9 third lane: the
 * function's structure and names were taken from the public pret/pokeplatinum
 * decompilation of the same library (lib/spl/src/spl_emitter.c,
 * SPLUtil_SetTexture), with the SDK inlines written with their real
 * parameter lists.  Measured load-bearing: the G3_TexImageParam inline with
 * its enum-typed parameters and GX_PACK_TEXIMAGE_PARAM (writing the macro
 * straight into the register store: 50 out) and the G3_Scale inline with its
 * three fx32 parameters (direct stores through sx/sy locals: 57 out).  Not
 * load-bearing: G3_TexPlttBase as an inline, `* FX32_ONE` versus `<< 12`,
 * and the union versus a plain bitfield struct.
 */
void SPL_EMITTER_SetTextureParam(SPLTexture *tex)
{
    SPLTextureParam param = tex->param;
    G3_TexImageParam(param.format, GX_TEXGEN_TEXCOORD, param.s, param.t, param.repeat, param.flip, param.palColor0, tex->texAddr);
    G3_TexPlttBase(tex->palAddr, param.format);
    G3_MtxMode(GX_MTXMODE_TEXTURE);
    G3_Identity();
    G3_Scale(tex->width * FX32_ONE, tex->height * FX32_ONE, 0);
    G3_MtxMode(GX_MTXMODE_POSITION);
}














void SPL_EMITTER_Noop(SPLTexture *tex)
{
}









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
 * 66 out at arm946e and 712 / 73 at arm7tdmi.  Under THIS RANGE'RenderNode FAMILY PIN,
 * `../1.2/sp2 -proc arm946e`, the note's own source is 716/716 with 17
 * concrete bytes out, and both horns of the supposed conflict vanish at once:
 * 1.2 emits the ARMv4T `pop {r4, r5, r6, lr}; bx lr` return AND the four
 * `smulbb` from `(s16)(x * -1)`.  Same tell as the rest of the
 * 0x0205429C..0x020584E0 3D-rig unit (docs/FRONTEND-PINS.md).
 *
 * THREE SPELLINGS ARE LOAD-BEARING on top of the note's source, the last two
 * found by tools/permuter.py (--mode anneal --focus pos,posX,posY,posZ,cfg,
 * EXACT at compile 321 from a 13-byte residue):
 *   1. `volatile struct VramResourceHeader *r` for the cached descriptor pointer around the
 *      +0x50/+0x52/+0x54 halfword copies.  Without volatile the two `ldrh`
 *      for axisX/axisY swap registers (the note's residue, 4 instructions).
 *   2. `const struct Vec3 *pos`, NOT `const volatile`.  With volatile the
 *      three position adds and the descriptor chain that feeds them are 10
 *      instructions of register naming out.
 *   3. `pos->x + o->resource->resource->emitterBasePosX`, position FIRST.  Field-first is the
 *      note's order and costs the same 10 instructions in the other
 *      direction (cmp/commutative operand order names the temporary).
 * The rest of the source, the every-time re-read of `o->resource->resource` for each
 * copied field, the `volatile struct RigObject *o`, and `(s16)(x * -1)` for the
 * sign flips, is the note's and is unchanged.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_SetupResource.c \
 *       --func SPL_EMITTER_SetupResource --addr 0x02053A60 --arm --cc ../1.2/sp2
 */
void SPL_EMITTER_SetupResource(volatile struct ResourceSetup *o, struct Cfg *cfg, const struct Vec3 *pos)
{
  volatile struct VramResourceHeader *r;
  struct Cfg *c;
  o->resource = cfg;
  o->state = 0;
  o->posX = pos->x + o->resource->resource->emitterBasePosX;
  o->posY = pos->y + o->resource->resource->emitterBasePosY;
  o->posZ = pos->z + o->resource->resource->emitterBasePosZ;
  o->initVelX = 0;
  o->initVelY = 0;
  o->initVelZ = 0;
  o->velZ = 0;
  o->velY = o->velZ;
  o->velX = o->velY;
  o->age = 0;
  o->emissionCountFractional = 0;
  r = o->resource->resource;
  {
    u16 h0 = r->axisX;
    u16 h1 = r->axisY;
    o->axisX = h0;
    o->axisY = h1;
  }
  o->axisZ = r->axisZ;
  o->initAngle = o->resource->resource->initAngle;
  o->emissionCount = o->resource->resource->emissionCount;
  o->radius = o->resource->resource->radius;
  o->length = o->resource->resource->length;
  o->initVelPosAmplifier = o->resource->resource->initVelPosAmplifier;
  o->initVelAxisAmplifier = o->resource->resource->initVelAxisAmplifier;
  o->baseScale = o->resource->resource->baseScale;
  o->particleLifeTime = o->resource->resource->particleLifeTime;
  o->color = 0x7fff;
  *((u8 *) (&o->misc)) = o->resource->resource->miscByte0;
  *(((u8 *) (&o->misc)) + 1) = o->resource->resource->miscByte1;
  o->misc = o->misc & (~0x70000u);
  o->misc = o->misc & 0x0007ffffu;
  o->collisionPlaneHeight = 0x80000000u;
  o->textureS = (s16) (0x1000 << ((o->resource->resource->polygonFlags << 6) >> 30));
  o->textureT = (s16) (0x1000 << ((o->resource->resource->polygonFlags << 4) >> 30));
  if ((o->resource->resource->userData << 31) >> 31)
    o->textureS = (s16) (o->textureS * (-1));
  if ((o->resource->resource->userData << 30) >> 31)
    o->textureT = (s16) (o->textureT * (-1));
  c = o->resource;
  if ((c->resource->flags << 15) >> 31)
  {
    {
      s32 t = c->sub14->mode;
      s32 u = t << 30;
      o->childTextureS = (s16) (0x1000 << (((u32) u) >> 30));
    }
    o->childTextureT = (s16) (0x1000 << ((o->resource->sub14->mode << 28) >> 30));
    if ((o->resource->sub14->mode << 27) >> 31)
      o->childTextureS = (s16) (o->childTextureS * (-1));
    if ((o->resource->sub14->mode << 26) >> 31)
      o->childTextureT = (s16) (o->childTextureT * (-1));
  }
  o->prev = 0;
  o->next = o->prev;
  o->childParticlesFirst = 0;
  o->particlesFirst = o->childParticlesFirst;
  o->childParticlesCount = 0;
  o->particlesCount = o->childParticlesCount;
  o->updateCallback = 0;
  o->userDataPtr = 0;
  o->userData = 0;
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
#define SPLRandom_RangeFX32(num) (((num) * (s32)SPLRandom_U32(9) - ((num) << 8)) >> 8)











/**
 * @brief Generates a random fx32 number in the range [min, max)
 * @param min The minimum number to generate, integer
 * @param max The maximum number to generate, integer
 */
#define SPLRandom_BetweenFX32(min, max) ((fx32)(((max) - (min)) * SPLRandom_U32(12) + ((min) * FX32_ONE)))










static inline SPLParticle *SPLParticleList_Erase(SPLParticleList *list, SPLParticle *ptcl)
{
    return (SPLParticle *)SPLList_Erase((SPLList *)list, (SPLNode *)ptcl);
}










/*
 * SPLEmitter_Update: the per-frame emitter step.  Emits new particles on the
 * emission interval (SPLEmitter_EmitParticles), collects the enabled animation
 * functions (SPLAnim_Scale scale, SPLAnim_Color colour, SPLAnim_Alpha
 * alpha, SPLAnim_Texture texture; children SPLAnim_ChildScale / SPLAnim_ChildAlpha),
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
void SPL_EMITTER_UpdateParticles(SPLManager *mgr, SPLEmitter *emtr)
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
 * The sibling of SPL_EMITTER_UpdateSubX in the same file: the same per-frame dispatch
 * over a render list, but on the block's OTHER list (+0x08 rather than +0x14)
 * and with a disjoint handler set.  Unconditionally calls SPL_EMITTER_SetTextureParam on the
 * 0x14-byte row the descriptor's byte at +0x47 selects, picks the per-node
 * handler from bits 4..5 of the descriptor's first word (the `lsl #26` /
 * `lsr #30` pair), and picks a SECOND per-node function from bit 11 of the
 * same word (`lsl #20` / `lsrs #31`, materialised as the `ldrne`/`ldreq`
 * pair at 0x020531B8/0x020531BC), then walks the list calling both.
 * Cases 3 and 4 share SPL_EMITTER_UpdateFrameMain, exactly as cases 3/4 do in the sibling.
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
 * ABS32 pool words at +0x00D4/D8/E8 naming SPL_EMITTER_UpdateFrame, SPL_EMITTER_UpdateParticleMotion and
 * SPL_EMITTER_Noop, and this function's own pool at 0x02053200 is the only place
 * in the image those three words appear.  SPL_EMITTER_UpdateFrameA68 and SPL_EMITTER_UpdateFrameMain
 * already resolve `matched x1`; filing any one of the remaining three
 * promotes this file toward EXACT with no change to the C.  SPL_EMITTER_UpdateParticleMotion and
 * SPL_EMITTER_UpdateFrame are unfiled 3D-rig rows (docs/FRONTEND-PINS.md); SPL_EMITTER_Noop
 * is an unlabelled leaf four bytes below SPL_EMITTER_SetTextureParam.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/SPL_EMITTER_UpdateSubB.c \
 *       --func SPL_EMITTER_UpdateSubB --addr 0x0205312C --cc ../1.2/sp2 --arm
 */
void SPL_EMITTER_UpdateSubB(struct RigObject *o)
{
    struct RigRenderList *b = o->renderList;
    struct RigDescriptor *d = b->subList->desc;
    Fn fn = 0;
    Fn1 g;
    struct RenderNode *n;

    SPL_EMITTER_SetTextureParam(o->textures + d->texture);

    switch (d->flags.d.kind) {
    case 0:
        fn = SPL_EMITTER_UpdateFrame;
        break;
    case 1:
        fn = (Fn)SPL_EMITTER_UpdateParticleMotion; /* stand-in: the row is an SPLManager * SPLParticle handler */
        break;
    case 2:
        fn = SPL_EMITTER_UpdateFrameA68;
        break;
    case 3:
        fn = SPL_EMITTER_UpdateFrameMain;
        break;
    case 4:
        fn = SPL_EMITTER_UpdateFrameMain;
        break;
    }

    if (d->flags.d.sel)
        g = SPL_EMITTER_SetTextureParam;
    else
        g = SPL_EMITTER_Noop;

    n = b->nodeList;
    if (n == 0)
        return;

    do {
        g(o->textures + n->texture);
        fn(o, n);
        n = n->next;
    } while (n != 0);
}






/*
 * Per-frame dispatch for one render list.  Reads the object's block at +0x40,
 * bails when bit 16 of the first word of the sub-block's *desc chain is clear,
 * calls SPL_EMITTER_SetTextureParam on the 0x14-byte row the descriptor's byte at +0x0f
 * selects, then picks a per-node handler from a 2-bit field of the
 * descriptor's halfword (bits 8..9, spelled as the shift pair `lsl #23` /
 * `lsr #30`), and walks the singly linked list at block+0x14 calling it.
 *
 * Cases 3 and 4 share SPL_EMITTER_UpdateFrameMainEx, and the `cmp r0, #4` says the switch has
 * exactly five arms, none of them empty; a sixth arm makes the table one entry
 * longer and shifts every branch.
 *
 * COMPILER PIN: ../1.2/sp2, on two tells at once, both documented in
 * docs/FRONTEND-PINS.md and both already carried by this region's
 * pkt_020526A8 family (SPL_EMITTER_AllocResourceEx.c, SPL_EMITTER_AllocResource.c, SPL_EMITTER_AllocPlttVramDefault.c):
 *   - the interworking conflict, `blx r4` at 0x02053100 (`34 ff 2f e1`)
 *     beside the ARMv4T-style return `pop {r4, r5, r6, r7, lr}` / `bx lr` at
 *     0x02053114/0x02053118 (`f0 40 bd e8` / `1e ff 2f e1`); under
 *     -proc arm946e no dsi front end emits that pair, it emits `pop {..., pc}`;
 *   - the frame-padding tell, `sub sp, sp, #4` at 0x02053048 (`04 d0 4d e2`)
 *     where 1.1p1 pads the five-register frame with a dead `push {r3}` and
 *     gives `push {r3, r4, r5, r6, r7, lr}` at +0000.
 * Under 1.1p1 -O4,p the same C is 208 bytes against the original's 232, 161
 * concrete bytes out (all three epilogues one instruction short); under
 * ../2.0/sp2 it is 204 bytes and 161 out.  Under the pin it is 232 bytes with
 * ZERO concrete mismatches.
 *
 * Three of the five relocation sites are ABS32 pool words at +0x00D8/DC/E4
 * naming SPL_EMITTER_UpdateFrameEx, SPL_EMITTER_UpdateParticleMotionEx and SPL_EMITTER_UpdateFrameMainEx.  Each is an unfiled
 * 3D-rig row (see docs/FRONTEND-PINS.md, "The 3D rig unit"), so neither the
 * `matched` class nor `literal` has a witness: this function's own pool at
 * 0x0205311C is the only place in the image those words appear, and the
 * sibling at 0x0205312C carries a DISJOINT handler set (0x02055FD4,
 * 0x02055498, 0x02054A68, 0x0205429C), so it cannot attest them either.
 * Filing any one of the three (SPL_EMITTER_UpdateFrameEx is the highest-value) promotes
 * this file toward EXACT with no change to the C.  SPL_EMITTER_UpdateFrameA68Ex already
 * resolves `matched x1`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/SPL_EMITTER_UpdateSubX.c \
 *       --func SPL_EMITTER_UpdateSubX --addr 0x02053044 --cc ../1.2/sp2 --arm
 */
void SPL_EMITTER_UpdateSubX(struct RigObject *o)
{
    struct RigRenderList *b = o->renderList;
    struct RigSubList *s = b->subList;
    Fn fn = 0;
    struct RenderNode *n;

    if (!s->desc->flags.z.b16)
        return;

    SPL_EMITTER_SetTextureParam(o->textures + s->hw->texture);

    switch (s->hw->hw.kind) {
    case 0:
        fn = SPL_EMITTER_UpdateFrameEx;
        break;
    case 1:
        fn = (Fn)SPL_EMITTER_UpdateParticleMotionEx; /* stand-in: the row is an SPLManager * SPLParticle handler */
        break;
    case 2:
        fn = SPL_EMITTER_UpdateFrameA68Ex;
        break;
    case 3:
        fn = SPL_EMITTER_UpdateFrameMainEx;
        break;
    case 4:
        fn = SPL_EMITTER_UpdateFrameMainEx;
        break;
    }

    n = b->nodeList2;
    if (n == 0)
        return;

    do {
        fn(o, n);
        n = n->next;
    } while (n != 0);
}






/*
 * Blocking class: label.  Both callees, 0x02053044 and 0x0205312C, are
 * reached only from the two call sites inside this function, so neither has a
 * witness outside the compared range and all four PC24 fields stay
 * wildcarded (0x02052FC8 is the last function of the packet before them).
 * Every concrete byte matches under the packet's 1.2 pin; both callees are
 * still-open rows of pkt_020526A8, and filing either one EXACT would move
 * this to EXACT through the `matched` class.
 *
 * The two branches are bit 21 and bit 22 of *v, and they must be written as a
 * 21/1/1/9 bitfield struct: the spelled-out `(*v << 10) >> 31` form loads the
 * word into the wrong scratch register (r2 where the image uses r1, and the
 * in-place `lsl r1, r1, #9` of the second test becomes a move), a six-byte
 * residue that the bitfield declaration removes.  See
 * docs/notes/pkt_020526A8.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/SPL_EMITTER_UpdateSubC.c \
 *       --func SPL_EMITTER_UpdateSubC --addr 0x02052FC8 --arm --cc ../1.2/sp2
 */
void SPL_EMITTER_UpdateSubC(struct RigObject *o)
{
    struct RigDescriptor *v = o->renderList->subList->desc;

    if (v->flags.z.b21) {
        SPL_EMITTER_UpdateSubX(o);
        if (v->flags.z.b22)
            return;
        SPL_EMITTER_UpdateSubB(o);
        return;
    }
    if (v->flags.z.b22 == 0)
        SPL_EMITTER_UpdateSubB(o);
    SPL_EMITTER_UpdateSubX(o);
}







extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(u32 a, u32 b, u32 c);







extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(u32 a, u32 b, u32 c);







/*
 * Twin of src/matched/SPL_EMITTER_AllocPlttVram.c: same twelve instructions and the same
 * two pool words by position, differing only in the global function pointer
 * it calls (0x020A8140 against 0x020A8148).  Carries the same per-file pin
 * for the same measured tells (register `blx r3` beside an ARMv4T
 * `ldm sp!, {lr}; bx lr` return, and `sub sp, sp, #4` where 1.1p1 pads with a
 * dead `push {r3}`).
 *
 * Evidence recorded in docs/notes/pkt_020526A8.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_AllocTexVram.c \
 *       --func SPL_EMITTER_AllocTexVram --addr 0x02052F90 --arm --cc ../1.2/sp2
 */
int SPL_EMITTER_AllocTexVram(u32 szByte, u32 is4x4comp)
{
    return (NNS_GfdDefaultFuncAllocTexVram(szByte, is4x4comp, 0) & 0xffff) << 3;
}







/*
 * Calls the routine held in the global function pointer at 0x020A8148 with
 * (a0, a1, 0) and returns (result & 0xffff) << 3.  The 8-byte frame is
 * push {lr} plus the AAPCS alignment word.
 *
 * Built by the 1.2 front end, on two measured tells at once: the image has a
 * register `blx r3` beside an ARMv4T return `ldm sp!, {lr}; bx lr`, a pair no
 * dsi build emits, and the frame is `sub sp, sp, #4` where 1.1p1 pads with a
 * dead `push {r3}`.  Under 1.1p1 the 16-bit mask also folds into a shift pair
 * (`lsl r0,r0,#0x10; lsr r0,r0,#0xd`) where the image ANDs with a pooled
 * 0xffff; ../1.2/sp2 reproduces all of it.  Measured, same packet as
 * src/matched/SPL_EMITTER_AllocResourceEx.c (pinned for the frame tell).
 *
 * Evidence recorded in docs/notes/pkt_020526A8.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_AllocPlttVram.c \
 *       --func SPL_EMITTER_AllocPlttVram --addr 0x02052F58 --arm --cc ../1.2/sp2
 */
int SPL_EMITTER_AllocPlttVram(u32 szByte, u32 is4pltt)
{
    return (NNS_GfdDefaultFuncAllocPlttVram(szByte, is4pltt, 0) & 0xffff) << 3;
}







/*
 * The rig constructor: allocate and zero the 0x4c-byte VramNodeHeap through the
 * caller's allocator, record the two pool sizes (+0x34, +0x36), pack the
 * 6-bit fields of the +0x38 word (b0 = a4, b6 = a5, b12 = b0, b18 = a3,
 * b24 and b25..31 cleared, one read-modify-write per field under 1.2), clear
 * the three list headers and the counters, then allocate n1 nodes of 0x9c
 * bytes pushed onto the recycle list at +0x10 and n2 records of 0x44 bytes
 * pushed onto the list at +0x1c.  Returns the VramNodeHeap.  Caller 0x02050D88 passes
 * every scalar argument truncated to u16.
 *
 * Closed by indexing: `&p[i]` over a 0x9c-byte element type rather than a
 * hand-advanced `char *` (8 bytes out, a p/i register swap, otherwise).
 */
/*
 * The rig constructor: allocate and zero the 0x4c-byte Head through the
 * caller's allocator, record the two pool sizes (+0x34, +0x36), pack the
 * 6-bit fields of the +0x38 word (b0 = a4, b6 = a5, b12 = b0, b18 = a3,
 * b24 and b25..31 cleared, one read-modify-write per field under 1.2), clear
 * the three list headers and the counters, then allocate n1 nodes of 0x9c
 * bytes pushed onto the recycle list at +0x10 and n2 records of 0x44 bytes
 * pushed onto the list at +0x1c.  Returns the Head.  Caller 0x02050D88 passes
 * every scalar argument truncated to u16.
 *
 * Closed by indexing: `&p[i]` over a 0x9c-byte element type rather than a
 * hand-advanced `char *` (8 bytes out, a p/i register swap, otherwise).
 */
struct VramNodeHeap *SPL_EMITTER_AllocNodeFromHeap(AllocFn alloc, u16 n1, u16 n2, u16 limitA, u16 limitB, u16 maxResIndex)
{
    struct VramNodeHeap *h;
    struct VramNodeBlob9C *p;
    struct VramRowBlob44 *q;
    int i;

    h = alloc(sizeof(struct VramNodeHeap));
    MI_CpuFill8(h, 0, sizeof(struct VramNodeHeap));
    h->nodeCount = n1;
    h->rowCount = n2;
    h->b0 = limitB;
    h->b6 = maxResIndex;
    h->b12 = h->b0;
    h->b18 = limitA;
    h->b24 = 0;
    h->b25 = 0;
    h->alloc = alloc;
    h->reserved1 = 0;
    h->nodeListCount = 0;
    h->rowListCount = 0;
    h->reserved0 = 0;
    h->nodeListFirst = 0;
    h->rowListFirst = 0;
    h->reserved7 = 0;
    h->reserved10 = 0;

    p = alloc(n1 * sizeof(struct VramNodeBlob9C));
    MI_CpuFill8(p, 0, n1 * sizeof(struct VramNodeBlob9C));
    for (i = 0; i < n1; i++)
        SPLList_PushFront((SPLList *)(&h->nodeListFirst), (SPLNode *)(&p[i]));

    q = alloc(n2 * sizeof(struct VramRowBlob44));
    MI_CpuFill8(q, 0, n2 * sizeof(struct VramRowBlob44));
    for (i = 0; i < n2; i++)
        SPLList_PushFront((SPLList *)(&h->rowListFirst), (SPLNode *)(&q[i]));

    h->reserved3 = 0;
    h->reserved4 = 0;
    h->reserved5 = h->reserved6 = 0;
    return h;
}







/*
 * The rig's resource binder: walk a packed blob `d` from byte 0x20 on.
 * First h->recordCount = d->nrec records of 0x20 bytes (h->records): each takes a
 * 0x58-byte block whose first word is a flag set; flags 8..11 and 16 each
 * bind an optional sub-block (0xc/0xc/8/0xc/0x14 bytes) to rec->sub0..sub4,
 * and flags 24..29 each add one {callback, data} entry to a table allocated
 * at rec->anims (count at rec->nanims) with data sizes 8/8/0x10/4/8/0x10 and the
 * six callbacks 0x020582CC..0x02057EF8.  Then h->rowCount = d->nrow material
 * rows of 0x14 bytes (h->rows): row->res points at the next resource, the two
 * 4-bit size codes at res+4 bits 4..7 and 8..11 give 1 << (code + 3), and
 * the resource's own size word at +0x1c advances the cursor.
 *
 * Levers: the optional fills are if/else statements (a `?:` gives separate
 * zero stack slots per arm and reorders), the callback entry stores data,
 * then fn, then advances `off` (any other order if-converts the blocks and
 * loses 40 bytes), `rec = &h->records[i]` is bound before the data store, and
 * the entry count is summed straight from the six bitfields, the later
 * tests reading the same fields (separate u32 locals give a r4/r5/r6
 * register cycle, 22 bytes out).
 */
void SPL_EMITTER_FreeNodeToHeap(struct VramTexHeap *h, struct VramHeapHeader *d)
{
    u32 off;
    int i;

    off = 0x20;
    h->recordCount = d->nrec;
    h->rowCount = d->nrow;
    h->records = h->alloc(h->recordCount * sizeof(struct VramHeapRecord));
    MI_CpuFill8(h->records, 0, h->recordCount * sizeof(struct VramHeapRecord));

    for (i = 0; i < h->recordCount; i++) {
        struct VramHeapRecord *rec;
        struct VramNodeFlags fl;

        rec = &h->records[i];
        rec->data = (struct VramNodeFlags *)((char *)d + off);
        fl = *rec->data;
        off += 0x58;

        if (fl.sub0) { rec->sub0 = (char *)d + off; off += 0xc; } else { rec->sub0 = 0; }
        if (fl.sub1) { rec->sub1 = (char *)d + off; off += 0xc; } else { rec->sub1 = 0; }
        if (fl.sub2) { rec->sub2 = (char *)d + off; off += 8; } else { rec->sub2 = 0; }
        if (fl.sub3) { rec->sub3 = (char *)d + off; off += 0xc; } else { rec->sub3 = 0; }
        if (fl.sub4) { rec->sub4 = (char *)d + off; off += 0x14; } else { rec->sub4 = 0; }

        rec->nanims = fl.anim0 + fl.anim1 + fl.anim2 + fl.anim3 + fl.anim4 + fl.anim5;
        if (rec->nanims != 0) {
            struct VramAnim *p;
            rec->anims = h->alloc(rec->nanims * sizeof(struct VramAnim));
            p = rec->anims;
            if (fl.anim0) { p->data = (char *)d + off; p->fn = (void (*)(void))SPL_EMITTER_AddVec; off += 8; p++; }
            if (fl.anim1) { p->data = (char *)d + off; p->fn = (void (*)(void))SPL_EMITTER_UpdateNode; off += 8; p++; }
            if (fl.anim2) { p->data = (char *)d + off; p->fn = (void (*)(void))SPL_EMITTER_AddScaledVec; off += 0x10; p++; }
            if (fl.anim3) { p->data = (char *)d + off; p->fn = (void (*)(void))SPL_EMITTER_BuildFrame; off += 4; p++; }
            if (fl.anim4) { p->data = (char *)d + off; p->fn = (void (*)(void))SPL_EMITTER_InterpTarget; off += 8; p++; }
            if (fl.anim5) { p->data = (char *)d + off; p->fn = (void (*)(void))SPL_EMITTER_LerpVec; off += 0x10; }
        } else {
            rec->anims = 0;
        }
    }

    h->rows = h->alloc(h->rowCount * sizeof(struct VramResourceRow));
    MI_CpuFill8(h->rows, 0, h->rowCount * sizeof(struct VramResourceRow));

    for (i = 0; i < h->rowCount; i++) {
        struct VramResourceRow *row = &h->rows[i];
        struct VramResource *res = (struct VramResource *)((char *)d + off);
        row->res = res;
        row->w = 1 << (res->w + 3);
        row->h = 1 << (res->h + 3);
        row->param = ((u32 *)res)[1];
        off += res->size;
    }
}







/*
 * The texture-upload pass of the rig's material rows: GX_BeginLoadTex, then
 * for every row of o->textures (o->texCount rows of 0x14 bytes) either share another
 * row's texture handle (resource flag bit 17 set; the row index is the 8-bit
 * field at bits 18..25) or allocate through the caller's callback and upload
 * with GX_LoadTex, then GX_EndLoadTex.  Always returns 1.  Twin of
 * SPL_EMITTER_AllocPlttVramList (palettes).
 *
 * What closed it (wave 9): the natural spelling.  The byte-offset induction
 * variable and the two stack slots holding 1 and 0 are the compiler's own
 * strength reduction of o->textures[i] and of "kind == 5 ? 1 : 0"; writing them
 * as locals (the wave-7 note) left a register swap no permutation moved.
 * The flags word is three declared bitfields (kind:4, shared at bit 17,
 * idx:8 at bits 18..25), and the row pointer is taken before the resource.
 */
int SPL_EMITTER_AllocTexVramList(struct RigObject *o, AllocTex alloc)
{
    int i;

    GX_BeginLoadTex();

    for (i = 0; i < o->texCount; i++) {
        struct SPLTexture *tex = &o->textures[i];
        const struct SPLTextureResource *res = tex->resource;

        if (res->param.useSharedTexture) {
            tex->texAddr = o->textures[res->param.sharedTexID].texAddr;
        } else {
            u32 v = alloc(res->textureSize, res->param.format == 5 ? 1 : 0);
            GX_LoadTex((char *)tex->resource + 0x20, v, res->textureSize);
            tex->texAddr = v;
        }
    }

    GX_EndLoadTex();
    return 1;
}






/*
 * The texture-palette upload pass: GX_BeginLoadTexPltt, then for every row
 * of o->textures with a non-zero resource size, allocate through the caller's
 * callback (first argument is the SIZE word, second is kind == 2) and upload
 * with GX_LoadTexPltt; the handle (0 when skipped) goes to row+0x08.  Then
 * GX_EndLoadTexPltt; always returns 1.  Twin of SPL_EMITTER_AllocTexVramList (textures).
 *
 * What closed it (wave 9): array indexing o->textures[i] and "kind == 2 ? 1 : 0"
 * instead of hand-written offset/one/zero locals (the wave-7 note's 8-byte
 * register swap was the compiler's strength reduction disagreeing with the
 * hand-reduced loop).
 */
int SPL_EMITTER_AllocPlttVramList(struct RigObject *o, AllocTex alloc)
{
    int i;

    GX_BeginLoadTexPltt();

    for (i = 0; i < o->texCount; i++) {
        struct SPLTexture *tex = &o->textures[i];
        const struct SPLTextureResource *res = tex->resource;
        u32 v = 0;

        if (res->paletteSize != 0) {
            v = alloc(res->paletteSize, res->param.format == 2 ? 1 : 0);
            GX_LoadTexPltt((char *)tex->resource + res->paletteOffset, v, res->paletteSize);
        }
        tex->palAddr = v;
    }

    GX_EndLoadTexPltt();
    return 1;
}






/*
 * Twin of src/matched/SPL_EMITTER_AllocPlttVramDefault.c, same twelve bytes by position: forward
 * r0 to 0x02052984 with the address of SPL_EMITTER_AllocTexVram as the second argument.
 * Same 1.2 pin and same tail-call schedule tell.
 *
 * The callback site resolves through the `matched` class once
 * src/matched/SPL_EMITTER_AllocTexVram.c is in the manifest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_AllocTexVramDefault.c \
 *       --func SPL_EMITTER_AllocTexVramDefault --addr 0x020528BC --arm --cc ../1.2/sp2
 */
void SPL_EMITTER_AllocTexVramDefault(u32 rigObject)
{
    SPL_EMITTER_AllocTexVramList((struct RigObject *)rigObject, (AllocTex)((void *)SPL_EMITTER_AllocTexVram));
}






/*
 * A twelve-byte tailcall thunk: forward r0 to 0x020528D0 and pass the
 * address of SPL_EMITTER_AllocPlttVram as the second argument.  mwcc emits a tail call as
 * a pool word plus `bx ip`, and for two pool words the 1.2 front end issues
 * the callee load into ip first, then the argument load; 1.1p1 issues them in
 * the other order (the documented tail-call schedule gap,
 * docs/idioms/a-tail-calls-pool-word-is-scheduled-before-the-last-argument-write.md),
 * so this row needs the packet's 1.2 pin as well.
 *
 * The callback site resolves through the `matched` class once
 * src/matched/SPL_EMITTER_AllocPlttVram.c is in the manifest: this row is filed after
 * that entry, and it is the second half of the pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_AllocPlttVramDefault.c \
 *       --func SPL_EMITTER_AllocPlttVramDefault --addr 0x020528A8 --arm --cc ../1.2/sp2
 */
void SPL_EMITTER_AllocPlttVramDefault(u32 rigObject)
{
    SPL_EMITTER_AllocPlttVramList((struct RigObject *)rigObject, (AllocTex)((void *)SPL_EMITTER_AllocPlttVram));
}







/*
 * The rig's per-frame node walk: for every node on h->list, age it, maybe
 * dispatch it, and maybe retire it onto the recycle list.  This is the callee
 * src/pending/PARTICLE_UpdateSystem.c was capped on.
 *
 * Per node, with c = *n->allocClass (the node's class record, doubly indirected):
 *   - if n's "expired" bit (+0x24 bit 4) is clear and the node's age n->age
 *     has reached the class lifetime c->lifeTime, set the bit and zero the age;
 *   - if n's "suppressed" bit (+0x24 bit 2) is clear, read the 3-bit phase
 *     index at +0x80 bits 16..18 and call SPL_EMITTER_UpdateParticles(h, n) when the phase
 *     is zero or matches the rig's own frame parity h->parity;
 *   - retire the node when either the class asks for it (c bit 14 set, a
 *     non-zero c->lifeCap cap, the expired bit set and the age past the cap) or
 *     the node's own "kill" bit (+0x24 bit 0) is set -- and then only if the
 *     node has no pending work (n->pending0 == 0 && n->pending1 == 0).  Retiring is
 *     SPLList_PushFront(&h->freeList, (SPLNode *)(SPLList_Erase(&h->list, n))).
 * After the walk h->parity is incremented and wrapped back to zero above 1, so
 * it is a two-frame parity counter.
 *
 * Two declarations carry the whole match, and both were the residue:
 *
 *  1. The retire call's two addresses must be written INLINE at the call site
 *     (&h->list, &h->freeList), not bound to two pointer locals hoisted before the
 *     loop.  The original DOES hoist them into sl and sb -- but hoisting them
 *     in the C gives those two values the low colours and pushes the head and
 *     node pointers up to sl/sb instead, a clean two-cycle register swap in
 *     33 bytes that no permuter mutation moves (266 single mutations tried,
 *     none improved).  Written inline, the compiler performs the hoist itself
 *     and colours in the original's order.
 *  2. The class record's lifetime field is at 0x32 and its cap at 0x3c; one
 *     halfword of padding wrong in the VramAllocClass layout was the last byte out.
 *
 * Every bit test is the lsl/lsr shift pair, so all six selectors are real
 * bitfields rather than masks
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md); the 3-bit
 * phase index is read as a plain (word << 13) >> 29 because it is not a
 * field of the bitfield struct the +0x24 word is.
 *
 * Built by the 1.2 front end, the packet-wide pin for this cluster.  An
 * earlier lane worked this function under dsi/1.1p1 and stopped at 288/312
 * bytes (docs/notes/pkt_020526A8.c.txt); the front end was the first half of
 * the answer, the two declarations above the second.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_FreeTexNode.c \
 *       --func SPL_EMITTER_FreeTexNode --addr 0x02052770 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
void SPL_EMITTER_FreeTexNode(struct VramFreeList *h)
{
    struct VramFreeNode *n = h->list;

    if (n != 0) {
        u16 z = 0;
        struct VramFreeNode *next;

        do {
            struct VramAllocClass *c = *n->allocClass;
            u32 idx;

            next = n->next;

            if (n->expired == 0) {
                if (n->age >= c->lifeTime) {
                    n->expired = 1;
                    n->age = z;
                }
            }
            if (n->suppressed == 0) {
                idx = (((struct VramFreeNode *)n)->phaseFlags << 13) >> 29;
                if (idx == 0 || h->parity == idx - 1)
                    SPL_EMITTER_UpdateParticles((struct SPLManager *)h, (struct SPLEmitter *)n);
            }
            if ((c->retire != 0 && c->lifeCap != 0 && n->expired != 0
                 && n->age > c->lifeCap) || n->kill != 0) {
                if (n->pending0 == 0 && n->pending1 == 0) {
                    SPLNode *r = SPLList_Erase((SPLList *)(&h->list), (SPLNode *)n);
                    SPLList_PushFront((SPLList *)(&h->freeList), r);
                }
            }
            n = next;
        } while (next != 0);
    }
    h->parity = h->parity + 1;
    if (h->parity > 1)
        h->parity = 0;
}








/*
 * Per-frame sweep of one display rig.  It first pokes the 3D display control
 * halfword at 0x04000060 (DISP3DCNT): clear bits 12-13, set bit 3.  That is a
 * cast constant, not a relocation
 * (docs/idioms/volatile-reread-needs-two-locals.md gives the shape; the two
 * accesses here are one read-modify-write and stay one expression).
 *
 * The argument is stored to h->userData, then bit 24 of the word at h+0x38 chooses
 * which of the rig's two lists to walk: clear walks h->list forward through
 * node->next, set walks h->rlist backward through node->prev.  Both arms are
 * written out in full rather than factored behind a shared body, which is what
 * gives the function its two identical epilogues and two `bl` sites
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * Every bit test is the lsl/lsr shift pair, so the selectors are genuine
 * bitfields, not masks: h+0x38 bit 24 is (x << 7) >> 31 and node+0x24 bit 3
 * is (x << 28) >> 31
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *
 * Built by the 1.2 front end, the packet-wide pin for this cluster.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_FreeNodeHeap.c \
 *       --func SPL_EMITTER_FreeNodeHeap --addr 0x020526A8 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
void SPL_EMITTER_FreeNodeHeap(struct VramHeapHead *h, u32 a)
{
    struct VramHeapNode *n;

    *(volatile u16 *)0x04000060 =
        (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 8);

    h->userData = a;
    if (h->reverse == 0) {
        n = h->list;
        while (n != 0) {
            h->cur = n;
            if (n->hidden == 0)
                SPL_EMITTER_UpdateSubC((struct RigObject *)h);
            n = n->next;
        }
    } else {
        n = h->rlist;
        while (n != 0) {
            h->cur = n;
            if (n->hidden == 0)
                SPL_EMITTER_UpdateSubC((struct RigObject *)h);
            n = n->prev;
        }
    }
}









/*
 * Promote-first callee of src/pending/PARTICLE_StartEffect.c (parks lane 2).
 * Pops one node off the list at p+0x10, runs the loader for the node and
 * (p->records + (arg1 << 5), arg2), then hands the node to SPLList_PushFront; the
 * node is discarded when bit 14 of the word at *(node->allocClass) is set.
 *
 * Built by the 1.2 front end, not dsi/1.1p1: the epilogue is the ARMv4T
 * style `pop {r4-r7, lr}; bx lr` *and* the frame pads with `sub sp, sp, #4`
 * instead of spending a dead `push {r3}` on the alignment word, which is
 * the small-frame signature in
 * docs/idioms/an-armv4t-style-return-and-a-register-blx-name-a-1-2-front-end-not-a-proc-value.md.
 * On dsi/1.1p1 this same C is 4 bytes short (112) at every -proc value.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_AllocResource.c \
 *       --func SPL_EMITTER_AllocResource --addr 0x02052634 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
int SPL_EMITTER_AllocResource(char *p, int b, int c)
{
    void *r = 0;

    if (((SPLManager *)p)->inactiveEmitters.first != 0) {
        r = SPLList_PopFront((SPLList *)(p + 0x10));
        SPL_EMITTER_SetupResource(r, (void *)((u32)((SPLManager *)p)->resources + (b << 5)), (const struct Vec3 *)c);
        SPLList_PushFront((SPLList *)(p + 4), (SPLNode *)r);
        if ((*(u32 *)(*(u32 *)(*(u32 *)&((SPLEmitter *)r)->resource)) << 0x11 >> 0x1f) != 0)
            r = 0;
    }
    return (int)r;
}










/*
 * Promote-first callee of src/pending/PARTICLE_StartEffectWithCallback.c (parks lane 2).
 * Same shape as its neighbour SPL_EMITTER_AllocResource with two extra steps: the
 * loader takes the address of a twelve-byte zeroed scratch block as its
 * third argument, and a non-null third parameter is called back with the
 * popped node before SPLList_PushFront runs.
 *
 * Built by the 1.2 front end (ARMv4T-style `pop {... lr}; bx lr` epilogue
 * and a `sub sp, sp, #4` alignment word), see
 * docs/idioms/an-armv4t-style-return-and-a-register-blx-name-a-1-2-front-end-not-a-proc-value.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_AllocResourceEx.c \
 *       --func SPL_EMITTER_AllocResourceEx --addr 0x020525A0 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
int SPL_EMITTER_AllocResourceEx(char *p, int b, void (*fn)(void *))
{
    void *r = 0;

    if (((SPLManager *)p)->inactiveEmitters.first != 0) {
        struct AllocScratch scratch = { 0, 0, 0 };

        r = SPLList_PopFront((SPLList *)(p + 0x10));
        SPL_EMITTER_SetupResource(r, (void *)((u32)((SPLManager *)p)->resources + (b << 5)), (const struct Vec3 *)(&scratch));
        if (fn != 0)
            fn(r);
        SPLList_PushFront((SPLList *)(p + 4), (SPLNode *)r);
        if ((*(u32 *)(*(u32 *)(*(u32 *)&((SPLEmitter *)r)->resource)) << 0x11 >> 0x1f) != 0)
            r = 0;
    }
    return (int)r;
}










/*
 * Tear down one node q owned by container p.  Two identical drain loops move
 * every child off q's two sublists (q+8 and q+0x14) onto the container's own
 * recycle list at p+0x1c with SPLList_PushFront; SPLList_PopFront is the pop, and it
 * is re-called at the bottom of each loop rather than at the top, which is why
 * the original re-materialises `add r5,r7,#0x1c` and `add r4,r6,#k` INSIDE the
 * loop body rather than hoisting them (the two locals are declared in the
 * body, one live range per iteration).  Then q is unlinked from p+4 and pushed
 * onto p+0x10.
 *
 * Called from SPL_EMITTER_FreeResourceList next door, which drains p+4 through this routine.
 *
 * Built by the 1.2 front end (`sub sp,sp,#4` alignment word and a
 * `pop {...,lr}; bx lr` epilogue), the packet-wide pin for this cluster.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_FreeResource.c \
 *       --func SPL_EMITTER_FreeResource --addr 0x0205250C --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
void SPL_EMITTER_FreeResource(char *p, char *q)
{
    void *n;

    n = SPLList_PopFront((SPLList *)(q + 8));
    while (n != 0) {
        char *head = p + 0x1c;
        char *list = q + 8;
        SPLList_PushFront((SPLList *)head, (SPLNode *)n);
        n = SPLList_PopFront((SPLList *)list);
    }

    n = SPLList_PopFront((SPLList *)(q + 0x14));
    while (n != 0) {
        char *head = p + 0x1c;
        char *list = q + 0x14;
        SPLList_PushFront((SPLList *)head, (SPLNode *)n);
        n = SPLList_PopFront((SPLList *)list);
    }

    SPLList_Erase((SPLList *)(p + 4), (SPLNode *)q);
    SPLList_PushFront((SPLList *)(p + 0x10), (SPLNode *)q);
}










/*
 * Drain the singly-linked list hanging off p+4: for each node, cache its
 * `next` pointer (the first word) BEFORE handing the node to SPL_EMITTER_FreeResource,
 * which tears the node down.  The cached-next shape is what produces the
 * `ldr r4,[r1]` above the call and the `mov r1,r4; cmp r4,#0` pair below it.
 *
 * Built by the 1.2 front end like the rest of this cluster: the frame pads
 * with `sub sp, sp, #4` and the epilogue is `pop {r4,r5,lr}; bx lr`
 * (docs/idioms/an-armv4t-style-return-and-a-register-blx-name-a-1-2-front-end-not-a-proc-value.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_FreeResourceList.c \
 *       --func SPL_EMITTER_FreeResourceList --addr 0x020524C8 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
void SPL_EMITTER_FreeResourceList(void *p)
{
    void *n = ((SPLManager *)p)->activeEmitters.first;

    while (n != 0) {
        void *next = ((SPLEmitter *)n)->next;
        SPL_EMITTER_FreeResource(p, n);
        n = next;
    }
}
