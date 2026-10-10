/*
 * file:     button_man_p03.c
 * unit:     yes
 * function: func_0205312C, func_02053218, func_02053A60, func_02053D2C, func_02053D30, func_02053E1C, func_0205429C, func_02054718, func_02054A68, func_02054DB8, func_02055498, func_02055B80, func_02055FD4, func_02056420, func_02056460, func_0205650C, func_020565C8, func_02056684, func_020569A4, func_020576D0, func_02057830, func_02057AB8, func_02057B10, func_02057B5C, func_02057BC0, func_02057C9C, func_02057E68
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
 *   func_02053E1C_Verts  0x020A1B38  data
 *   func_02053E1C_Hooks  0x020A7FE4  data
 *   func_02053E1C_Hooks2 0x020A7FDC  data
 *   func_0207B598        0x0207B598  arm
 *   func_0207B5F4        0x0207B5F4  thumb
 *   func_0207B9F0        0x0207B9F0  arm
 *   func_0207CA68        0x0207CA68  arm
 *   func_0207CAE8        0x0207CAE8  arm
 *   func_0207CCA4        0x0207CCA4  arm
 *   func_0207D8E0        0x0207D8E0  arm
 *   func_0207D918        0x0207D918  arm
 *   func_0205429C_Verts  0x020A1B38  data
 *   func_0205429C_Hooks  0x020A7FE4  data
 *   func_0205429C_Hooks2 0x020A7FDC  data
 *   func_02054718_Verts  0x020A1B38  data
 *   func_02054718_Hooks  0x020A7FE4  data
 *   func_02054718_Hooks2 0x020A7FDC  data
 *   func_02054A68_Verts  0x020A1B38  data
 *   func_02054A68_Hooks  0x020A7FE4  data
 *   func_02054A68_Hooks2 0x020A7FDC  data
 *   func_0207BC08        0x0207BC08  arm
 *   func_02055B80_Verts  0x020A1B38  data
 *   func_02055FD4_Verts  0x020A1B38  data
 *   func_02058380  0x02058380  arm
 *   func_020583CC  0x020583CC  arm
 *   g_02146A8C     0x02146A8C  data
 *   SPLList_PopFront                 0x02058380  arm
 *   SPLRandom_VecFx32                0x02058478  arm
 *   SPLRandom_VecFx32_XY             0x0205841C  arm
 *   SPLUtil_TiltCoordinates          0x020576D0  arm
 *   SPLEmitter_ComputeOrthogonalAxes 0x02057830  arm
 *   VEC_Fx16CrossProduct             0x0207CB68  arm
 *   _u32_div_f                       0x0209C2B0  arm
 *   func_0207CB68   0x0207CB68  arm
 *   func_0207CDB8   0x0207CDB8  arm
 *   func_0207CAA4  0x0207CAA4  arm
 *   g_020A7FEC     0x020A7FEC  data
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
struct List;
struct Node_02055FD4;
struct S;
struct SPLManager;
struct SPLTexture;
struct Curve {
    short _00;
    short _02;
    short _04;
    unsigned char _06;
    unsigned char _07;
};

struct Src_02057E68 {
    int _00;
    struct Curve *_04;
};

struct Obj_02056420 {
    char _00[0x34];
    short _34;
};

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef u16 GXRgb;

struct KeyF { u16 b0 : 2; u16 on : 1; u16 rest : 13; };

struct Key {
    GXRgb c0;
    GXRgb c1;
    u8 t0;
    u8 t1;
    u8 t2;
    u8 pad7;
    struct KeyF f;
};

struct Node_02055FD4 { u8 pad_00[0x22]; GXRgb col; };

struct Ctx { struct Node_02055FD4 *node; u8 pad_04[4]; struct Key *key; };

struct Out { u8 pad_00[0x36]; GXRgb col; };

typedef signed short s16;

struct Rec {
    u16 lo : 5;
    u16 mid : 5;
    u16 hi : 5;
    u16 _unused : 1;
    u8 f02;
    u8 _03;
    u8 a;
    u8 b;
};

struct S_02057BC0 {
    char _00[0xc];
    struct Rec *f0c;
};

struct O_02057BC0 {
    char _00[0x2e];
    u16 f2e;
};

struct P {
    u8 vals[8];
    u8 n;
    u8 step;
};

struct O_020576D0 {
    char _00[0x2c];
    u8 f2c;
};

struct S_020576D0 {
    char _00[0x10];
    struct P *f10;
};

struct Angle {
    int _00;
    short _04;
};

struct Src_020576D0 {
    char _00[0x14];
    struct Angle *_14;
};

struct Obj_02057B10 {
    char _00[0x34];
    short _34;
};

struct Obj_020576D0 {
    u8 _00[0x2e];
    u16 _2e;
};

typedef s32 fx32;

typedef signed long long s64;

typedef s64 fx64;

struct Vec16 { s16 x, y, z; };

struct Mode {
    u32 _unused : 6;
    u32 mode    : 2;
    u32 _rest   : 24;
};

struct Mid { struct Mode *f00; };

struct Rig {
    u8           pad_00[0x20];
    struct Mid  *f20;
    u8           pad_24[0x2c];
    struct Vec16 f50;
    u8           pad_56[0x2e];
    s16          r0[3];
    s16          r1[3];
};

typedef struct { fx32 x, y, z; } VecFx32;

struct Mtx3 {
    u8  pad[0x84];
    s16 r0[3];
    s16 r1[3];
};

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

typedef struct SPLNode { struct SPLNode *next; struct SPLNode *prev; } SPLNode;

typedef struct SPLList { SPLNode *first; int count; SPLNode *last; } SPLList;

struct VecFx32 { s32 x, y, z; };

struct PBf { u16 b0 : 5; u16 b5 : 5; u16 b10 : 6; };

struct Ptcl {
    u8 pad00[0x08];
    struct VecFx32 pos;     /* +0x08 */
    struct VecFx32 vel;     /* +0x14 */
    u16 f20;
    s16 f22;
    u16 f24;
    u16 f26;
    u16 f28;
    u16 f2a;
    u8 f2c;
    u8 f2d;
    struct PBf w;           /* +0x2e */
    fx32 f30;
    u16 f34;
    u16 f36;
    struct VecFx32 f38;
};

struct DescBf { u16 b0 : 3; u16 sel : 2; u16 b5 : 1; u16 col : 1; u16 rest : 9; };

struct Desc_02055FD4 {
    struct DescBf f;        /* +0x00 */
    s16 f02;
    u8 pad04[2];
    u16 f06;
    u8 f08;
    u8 f09;
    u16 f0a;
    u8 f0c;
    u8 pad0d[2];
    u8 f0f;
};

struct Emt {
    u8 pad00[0x08];
    struct VecFx32 pos;     /* +0x08 */
    struct VecFx32 vel;     /* +0x14 */
    u16 f20;
    s16 f22;
    u16 f24;
    u8 pad26[0x08];
    struct PBf w;           /* +0x2e */
    fx32 f30;
    s16 f34;
    u16 f36;
    struct VecFx32 f38;
};

struct SubX_02056420 { u8 pad00[0x14]; struct Desc_02055FD4 *desc; };

struct Owner { u8 pad00[0x14]; u8 list[0x0c]; struct SubX_02056420 *x; };

struct MtxFx43 { s32 m[12]; };

struct Bf16 {
    u16 b0 : 5;
    u16 b5 : 5;
    u16 b10 : 6;
};

struct BfHw {
    u16 a : 9;
    u16 sel2 : 2;
    u16 sel1 : 1;
    u16 b : 4;
};

struct BfSel {
    u32 lo : 6;
    u32 sel : 1;
    u32 hi : 25;
};

struct BfZero {
    u32 f0 : 17;
    u32 sel2 : 2;
    u32 sel1 : 1;
    u32 f20 : 3;
    u32 flag : 1;
    u32 f24 : 8;
};

struct Bf28 {
    u32 lo : 8;
    u32 k : 16;
    u32 mid : 4;
    u32 sel : 3;
    u32 hi : 1;
};

struct SubD {
    struct BfHw hw;
    u8 pad02[0x0e];
    struct BfSel f10;
};

struct SubC {
    struct BfZero f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u8 pad10[0x20];
    s16 f30;
    u8 pad32[0x16];
    struct Bf28 f48;
    u8 pad4c[0x04];
    s16 f50;
    s16 f52;
};

struct SubX {
    struct SubC *f00;
    u8 pad04[0x10];
    struct SubD *f14;
};

struct SubB {
    u8 pad00[0x20];
    struct SubX *f20;
    u8 pad24[0x4e];
    u16 f72;
    u8 pad74[0x04];
    s16 f78;
    s16 f7a;
    s16 f7c;
    s16 f7e;
};

struct Obj {
    u8 pad00[0x3c];
    u32 f3c;
    struct SubB *f40;
    struct MtxFx43 *f44;
};

struct S {
    u8 pad00[0x08];
    struct VecFx32 p1;
    struct VecFx32 p2;
    u16 f20;
    u8 pad22[0x0c];
    struct Bf16 w;
    s32 f30;
    s16 f34;
    u16 f36;
    u32 f38;
    u32 f3c;
    u32 f40;
};

struct Frame_02055FD4 {
    struct VecFx32 t;
    struct MtxFx43 m;
};

struct Frame_02055B80 {
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

struct Frame_02054A68 {
    struct MtxFx43 m1;
    struct MtxFx43 m2;
    struct MtxFx43 m3;
};

struct MtxFx33 { s32 m[9]; };

struct Frame_02054718 {
    struct MtxFx43 m1;
    struct MtxFx43 m2;
    struct MtxFx43 m3;
};

struct Frame {
    struct MtxFx43 m1;
    struct MtxFx43 m2;
    struct MtxFx43 m3;
    struct VecFx32 v0;
    struct VecFx32 v1;
    struct VecFx32 v2;
    struct VecFx32 v3;
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

struct Res0
{
  u32 f00;
  s32 f04;
  s32 f08;
  s32 f0c;
  s32 f10;
  s32 f14;
  s32 f18;
  u16 f1c;
  u16 f1e;
  u16 f20;
  u16 f22;
  s32 f24;
  s32 f28;
  s32 f2c;
  s32 f30;
  s32 f34;
  u16 f38;
  u16 f3a;
  u16 f3c;
  u16 f3e;
  s32 f40;
  u8 f44;
  u8 f45;
  u8 f46;
  u8 f47;
  u32 f48;
  u32 f4c;
};

struct Sub14
{
  s32 f00;
  s32 f04;
  s32 f08;
  s32 f0c;
  u32 f10;
};

struct Cfg
{
  struct Res0 *f00;
  s32 f04;
  s32 f08;
  s32 f0c;
  s32 f10;
  struct Sub14 *f14;
};

struct Vec3
{
  s32 x;
  s32 y;
  s32 z;
};

struct Obj_02053A60
{
  s32 f00;
  s32 f04;
  s32 f08;
  s32 f0c;
  s32 f10;
  s32 f14;
  s32 f18;
  s32 f1c;
  struct Cfg *f20;
  s32 f24;
  s32 f28;
  s32 f2c;
  s32 f30;
  s32 f34;
  s32 f38;
  s32 f3c;
  s32 f40;
  s32 f44;
  s32 f48;
  u16 f4c;
  u16 f4e;
  u16 f50;
  u16 f52;
  u16 f54;
  u16 f56;
  s32 f58;
  s32 f5c;
  s32 f60;
  s32 f64;
  s32 f68;
  s32 f6c;
  u16 f70;
  u16 f72;
  u32 f74;
  s16 f78;
  s16 f7a;
  s16 f7c;
  s16 f7e;
  u32 f80;
  s32 f84;
  s32 f88;
  s32 f8c;
  s32 f90;
  s32 f94;
  s32 f98;
};

typedef struct FieldFunc {
    void (*func)(SPLParticle *, SPLResource *, int);
    BOOL loop;
} AnimFunc;

struct Node_0205312C {
    struct Node_0205312C *next;
    u32 pad[10];
    u8 f2c;
};

struct Desc_0205312C {
    u32 flags;
    u8 pad[0x43];
    u8 f47;
};

struct Sub {
    struct Desc_0205312C *f00;
};

struct Blk {
    u32 pad0[2];
    struct Node_0205312C *f08;
    u32 pad1[5];
    struct Sub *f20;
};

struct Obj_0205312C {
    u32 pad0[11];
    void *f2c;
    u32 pad1[4];
    struct Blk *f40;
};

typedef void (*Fn)(struct Obj_0205312C *, struct Node_0205312C *);

typedef void (*Fn1)(void *);

extern int _s32_div_f(int num, int den);
extern void func_0207CDB8(struct Vec16 *v, struct Vec16 *w);
extern fx32 func_0207CAA4(const struct Vec16 *a, const struct Vec16 *b);
extern void func_0207CB68(const struct Vec16 *a, const struct Vec16 *b, struct Vec16 *out);
extern void VEC_Fx16CrossProduct(const VecFx16 *a, const VecFx16 *b, VecFx16 *axb);
extern fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);
extern void VEC_Normalize(const VecFx32 *pSrc, VecFx32 *pDst);
extern SPLNode *SPLList_PopFront(SPLList *list);
extern void SPLList_PushFront(SPLList *list, SPLNode *node);
extern void SPLRandom_VecFx32(VecFx32 *vec);
extern void SPLRandom_VecFx32_XY(VecFx32 *vec);
extern void SPLEmitter_ComputeOrthogonalAxes(SPLEmitter *emtr);
extern void SPLUtil_TiltCoordinates(VecFx32 *ptclPos, VecFx32 *pos, SPLEmitter *emtr);
extern struct Node_02055FD4 *func_02058380(struct List *list);
extern void func_020583CC(volatile struct List *list, volatile struct Node_02055FD4 *node);
extern void func_0207BC08(const void *v, const void *m, void *out);
extern void func_0207D918(const void *);
extern void G3_MultMtx43(const MtxFx43 *m);
extern void MI_Copy36B(const void *pSrc, void *pDst);
extern void MTX_MultVec43(const VecFx32 *vec, const MtxFx43 *m, VecFx32 *dst);
extern void MTX_MultVec33(const VecFx32 *vec, const MtxFx33 *m, VecFx32 *dst);
extern void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern void SPLUtil_DrawXYPlane(fx16 s, fx16 t, fx16 offsetX, fx16 offsetY);
extern void SPLUtil_DrawXZPlane(fx16 s, fx16 t, fx16 offsetX, fx16 offsetZ);
extern u32 func_0207B5F4(void *, s32, s32, s32);
extern void func_0207B9F0(const void *, const void *, void *);
extern void func_0207D8E0(const void *);
extern void func_0207B598(void *);
extern s32 func_0207CA68(const void *, const void *);
extern void func_0207CAE8(const void *, const void *, void *);
extern void func_0207CCA4(const void *, void *);
extern SPLNode *SPLList_Erase(SPLList *list, SPLNode *node);
extern void SPLAnim_Scale(SPLParticle *ptcl, SPLResource *res, int lifeRate);
extern void SPLAnim_Color(SPLParticle *ptcl, SPLResource *res, int lifeRate);
extern void SPLAnim_Alpha(SPLParticle *ptcl, SPLResource *res, int lifeRate);
extern void SPLAnim_Texture(SPLParticle *ptcl, SPLResource *res, int lifeRate);
extern void SPLAnim_ChildScale(SPLParticle *ptcl, SPLResource *res, int lifeRate);
extern void SPLAnim_ChildAlpha(SPLParticle *ptcl, SPLResource *res, int lifeRate);
extern void SPLEmitter_EmitParticles(SPLEmitter *emtr, SPLParticleList *list);
extern void SPLEmitter_EmitChildren(SPLParticle *ptcl, SPLEmitter *emtr, SPLParticleList *list);
void func_02057E68(struct Obj_02056420 *o, struct Src_02057E68 *s, int t);
void func_02057C9C(struct Out *out, struct Ctx *ctx, s32 t);
void func_02057BC0(struct O_02057BC0 *o, struct S_02057BC0 *s, int t);
void func_02057B5C(struct O_020576D0 *o, struct S_020576D0 *s, int t);
void func_02057B10(struct Obj_02057B10 *o, struct Src_020576D0 *s, int t);
void func_02057AB8(struct Obj_020576D0 *o, int unused, int t);
void func_02057830(struct Rig *m);
void func_020576D0(fx32 *out, const VecFx32 *src, const struct Mtx3 *m);
void func_020569A4(SPLEmitter *emtr, SPLParticleList *list);
void func_02056684(struct Emt *e, struct Owner *o, void *pool);
void func_020565C8(s32 s, s32 t, s32 x, s32 y);
void func_0205650C(s32 s, s32 t, s32 x, s32 z);
void func_02056460(s32 sn, s32 cs, struct MtxFx43 *m);
void func_02056420(s32 sn, s32 cs, struct MtxFx43 *m);
void func_02055FD4(struct Obj *obj, struct S *s);
void func_02055B80(struct Obj *obj, struct S *s);
void func_02055498(SPLManager *mgr, SPLParticle *ptcl);
void func_02054DB8(SPLManager *mgr, SPLParticle *ptcl);
void func_02054A68(struct Obj *obj, struct S *s);
void func_02054718(struct Obj *obj, struct S *s);
void func_0205429C(struct Obj *obj, struct S *s);
void func_02053E1C(struct Obj *obj, struct S *s);
void func_02053D30(SPLTexture *tex);
void func_02053D2C(void);
void func_02053A60(volatile struct Obj_02053A60 *o, struct Cfg *cfg, const struct Vec3 *pos);
void func_02053218(SPLManager *mgr, SPLEmitter *emtr);
void func_0205312C(struct Obj_0205312C *o);
extern const struct Vec16 g_020A7FEC;
extern const fx16 FX_SinCosTable_[];
extern u32 g_02146A8C;
extern const s16 func_02055FD4_Verts[];
extern const s16 func_02055B80_Verts[];
extern const s16 func_02054A68_Verts[];
extern const s16 func_02054718_Verts[];
extern const s16 func_0205429C_Verts[];
extern const s16 func_02053E1C_Verts[];

#define GX_RGB(r, g, b) (((r) << 0) | ((g) << 5) | ((b) << 10))





void func_02057E68(struct Obj_02056420 *o, struct Src_02057E68 *s, int t)
{
    struct Curve *cv;
    int b0;
    int b1;

    cv = s->_04;
    b0 = cv->_06;
    b1 = cv->_07;
    if (t < b0) {
        o->_34 = cv->_00 + t * (cv->_02 - cv->_00) / b0;
        return;
    }
    if (t < b1) {
        o->_34 = cv->_02;
        return;
    }
    o->_34 = cv->_04 + (t - 0xFF) * (cv->_04 - cv->_02) / (0xFF - b1);
}






static inline void ColLerp(struct Out *out, s32 from, s32 to, u32 on, s32 num, s32 den)
{
    s32 tr = to & 0x1f;
    s32 fr = from & 0x1f;
    s32 tg = (to >> 5) & 0x1f;
    s32 fg = (from >> 5) & 0x1f;
    s32 fb = (from >> 10) & 0x1f;
    s32 tb = (to >> 10) & 0x1f;
    if (!on) {
        out->col = GX_RGB(tr, tg, tb);
        return;
    }
    out->col = GX_RGB(fr + num * (tr - fr) / den, fg + num * (tg - fg) / den, fb + num * (tb - fb) / den);
}





/* Segment 2 copy: the key colour is the FIRST parameter (`to`) and the
 * node colour the second (`from`); channels declared from/to per channel. */
static inline void ColLerp2(struct Out *out, s32 to, s32 from, u32 on, s32 num, s32 den)
{
    s32 fr = from & 0x1f;
    s32 tr = to & 0x1f;
    s32 fg = (from >> 5) & 0x1f;
    s32 tg = (to >> 5) & 0x1f;
    s32 fb = (from >> 10) & 0x1f;
    s32 tb = (to >> 10) & 0x1f;
    if (!on) {
        out->col = GX_RGB(tr, tg, tb);
        return;
    }
    out->col = GX_RGB(fr + num * (tr - fr) / den, fg + num * (tg - fg) / den, fb + num * (tb - fb) / den);
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
void func_02057C9C(struct Out *out, struct Ctx *ctx, s32 t)
{
    struct Key *k = ctx->key;
    s32 t0 = k->t0;
    struct Node_02055FD4 *n = ctx->node;
    s32 t1 = k->t1;
    s32 t2 = k->t2;
    if (t < t0) {
        out->col = k->c0;
        return;
    }
    if (t < t1) {
        ColLerp(out, k->c0, n->col, k->f.on, t - t0, t1 - t0);
        return;
    }
    if (t < t2) {
        ColLerp2(out, k->c1, n->col, k->f.on, t - t1, t2 - t1);
        return;
    }
    out->col = k->c1;
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
void func_02057BC0(struct O_02057BC0 *o, struct S_02057BC0 *s, int t)
{
    struct Rec *p;
    int a;
    int b;
    int v;
    int r;
    int q;
    u16 f02;
    u16 w;

    p = s->f0c;
    a = p->a;
    b = p->b;

    if (t < a) {
        v = p->lo + t * (p->mid - p->lo) / a;
    } else if (t < b) {
        v = p->mid;
    } else {
        v = p->hi + (t - 0xff) * (p->hi - p->mid) / (0xff - b);
    }

    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    r = g_02146A8C >> 24;
    f02 = p->f02;
    q = f02 * r;
    q = q >> 8;
    w = (u16)((v * (0xff - q)) >> 8);
    o->f2e = (o->f2e & ~0x3e0) | ((w & 0x1f) << 5);
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
void func_02057B5C(struct O_020576D0 *o, struct S_020576D0 *s, int t)
{
    struct P *p;
    int i;
    int end;
    int n;
    int step;

    p = s->f10;
    i = 0;
    n = p->n;
    if (n <= 0) {
        return;
    }
    step = p->step;
    end = 0;
    do {
        if (t < end + step) {
            o->f2c = p->vals[i];
            return;
        }
        i++;
        end += p->step;
    } while (i < p->n);
}









void func_02057B10(struct Obj_02057B10 *o, struct Src_020576D0 *s, int t)
{
    short cur;

    cur = s->_14->_04;
    o->_34 = cur + (cur - 0x1000) * (t - 0xFF) / 255;
}










void func_02057AB8(struct Obj_020576D0 *o, int unused, int t)
{
    u16 v;

    v = (0xff - t) * 0x1f / 255;
    o->_2e = (o->_2e & ~0x3e0) | ((v & 0x1f) << 5);
}











static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((s64)a * b + 0x800) >> 12);
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
 * `m->f20->f00->mode` (one of the three unit axes, or VEC_Fx16Normalize of
 * m+0x50 in the default arm), then the two basis rows are the cross product
 * of v with a and of v with the first row, computed inline with the FX_Mul
 * rounding quartet (the same shape as the sibling func_020576D0), and the
 * two rows are normalised in place with the same two-identical-arguments
 * call the sibling records as load-bearing.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02057830.c \
 *       --func func_02057830 --addr 0x02057830 --arm --cc ../1.2/sp2
 */
void func_02057830(struct Rig *m)
{
    struct Vec16 a;
    struct Vec16 v;
    fx32 d;

    a = g_020A7FEC;

    switch (m->f20->f00->mode) {
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
        func_0207CDB8(&m->f50, &v);
        break;
    }

    d = func_0207CAA4(&a, &v);
    if (d == 0x1000 || d == -0x1000) {
        a.x = 0x1000;
        a.y = 0;
        a.z = 0;
    }

    m->r0[0] = FX_Mul(v.y, a.z) - FX_Mul(v.z, a.y);
    m->r0[1] = FX_Mul(v.z, a.x) - FX_Mul(v.x, a.z);
    m->r0[2] = FX_Mul(v.x, a.y) - FX_Mul(v.y, a.x);
    m->r1[0] = FX_Mul(v.y, m->r0[2]) - FX_Mul(v.z, m->r0[1]);
    m->r1[1] = FX_Mul(v.z, m->r0[0]) - FX_Mul(v.x, m->r0[2]);
    m->r1[2] = FX_Mul(v.x, m->r0[1]) - FX_Mul(v.y, m->r0[0]);

    func_0207CDB8((struct Vec16 *)(m->pad_00 + 0x84), (struct Vec16 *)(m->pad_00 + 0x84));
    func_0207CDB8((struct Vec16 *)(m->pad_00 + 0x8a), (struct Vec16 *)(m->pad_00 + 0x8a));
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
 *   python tools/match.py one --src src/matched/func_020576D0.c \
 *       --func func_020576D0 --addr 0x020576D0 --arm --cc ../1.2/sp2
 */
void func_020576D0(fx32 *out, const VecFx32 *src, const struct Mtx3 *m)
{
    struct Vec16 v;

    func_0207CB68((const struct Vec16 *)(m->pad + 0x84),
                  (const struct Vec16 *)(m->pad + 0x8a), &v);
    func_0207CDB8(&v, &v);

    out[0] = FX_Mul(src->x, m->r0[0]) + FX_Mul(src->y, m->r1[0]) + FX_Mul(src->z, v.x);
    out[1] = FX_Mul(src->x, m->r0[1]) + FX_Mul(src->y, m->r1[1]) + FX_Mul(src->z, v.y);
    out[2] = FX_Mul(src->x, m->r0[2]) + FX_Mul(src->y, m->r1[2]) + FX_Mul(src->z, v.z);
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
 * func_020576D0, pool included; the worklist's 1544-byte figure was wrong).
 * The struct layouts (SPLEmitter, SPLParticle, SPLResourceHeader,
 * SPLResource) therefore hold for Black unchanged, which settles most of
 * this cluster's field names.  `int i = 0;` before the loop is the
 * upstream's own spelling (commented there as required for matching).  The two statics upstream,
 * SPLEmitter_ComputeOrthogonalAxes and SPLUtil_TiltCoordinates, are the
 * separate functions func_02057830 and func_020576D0 here.
 */
void func_020569A4(SPLEmitter *emtr, SPLParticleList *list)
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
 * desc->f0c particles: pop one from the free list (func_02058380), push it
 * on the owner's live list at +0x14 (func_020583CC), copy the emitter
 * position, set velocity = FX_Mul(emitter velocity, FX_Mul(f08 << 12, 0x10))
 * plus a random term in [-f02, f02) per axis from the LCG at 0x02146A8C
 * (0x5EEDF715 / 0x1B0CB173, the same generator func_02058204 uses), and
 * fill scale, colour, the 5-bit tile fields, the rotation pair (3-way
 * switch on desc bits 3..4), life and the two 0xFFFF reciprocal rates.
 *
 * LOAD-BEARING SHAPES (wave 8, each measured):
 *   1. The random term is a MACRO whose rng update is an assignment
 *      expression used as a value, `(g = g * A + C) >> 23`.  The same body
 *      as a static inline function (or a separate Rand() inline) is 792
 *      bytes against 800 and 534 out: the inline's statement boundary moves
 *      the whole velocity block.  The macro puts it at 52 out.
 *   2. `(s32)((u32)e->f24 >> 1)`: lsr, not asr, but _s32_div_f, not
 *      _u32_div_f.  An unsigned dividend picks the unsigned helper.
 *   3. `s = (e->f30 * e->f34) >> 12` bound to a local, operands in that
 *      order (40 out without it).
 *   4. `struct Ptcl *p;` declared FIRST, before `d`.  With p declared in the
 *      loop body (or after d) the two pointers swap r6/r7 and the last 40
 *      bytes stay out; tools/permuter.py --mode hill (222 singles) could not
 *      move it -- a declaration residue, as docs/notes/permuter.md predicts.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02056684.c \
 *       --func func_02056684 --addr 0x02056684 --arm --cc ../1.2/sp2
 */
void func_02056684(struct Emt *e, struct Owner *o, void *pool)
{
    struct Ptcl *p;
    struct Desc_02055FD4 *d = o->x->desc;
    fx32 scale = FX_Mul(d->f08 << 12, 0x10);
    s32 i;
    for (i = 0; i < d->f0c; i++) {
        p = (struct Ptcl *)func_02058380(pool);
        if (p == 0)
            return;
        func_020583CC((volatile struct List *)o->list, (volatile struct Node_02055FD4 *)p);
        p->pos = e->pos;
        p->vel.x = FX_Mul(e->vel.x, scale) + RandRange(d->f02);
        p->vel.y = FX_Mul(e->vel.y, scale) + RandRange(d->f02);
        p->vel.z = FX_Mul(e->vel.z, scale) + RandRange(d->f02);
        p->f38 = e->f38;
        {
            s32 s = (e->f30 * e->f34) >> 12;
            p->f30 = s * (d->f09 + 1) >> 6;
        }
        p->f34 = 0x1000;
        if (d->f.col)
            p->f36 = d->f0a;
        else
            p->f36 = e->f36;
        p->w.b0 = (u16)((e->w.b0 * (e->w.b5 + 1)) >> 5);
        p->w.b5 = 0x1f;
        switch (d->f.sel) {
        case 0:
            p->f20 = 0;
            p->f22 = 0;
            break;
        case 1:
            p->f20 = e->f20;
            p->f22 = 0;
            break;
        case 2:
            p->f20 = e->f20;
            p->f22 = e->f22;
            break;
        }
        p->f24 = d->f06;
        p->f26 = 0;
        p->f2c = d->f0f;
        p->f28 = 0xffff / (s32)((u32)e->f24 >> 1);
        p->f2a = 0xffff / e->f24;
        p->f2d = 0;
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
 * (Rig_Hooks2 = { func_020565C8, func_0205650C }, docs/families/
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
 *   python tools/match.py one --src src/matched/func_020565C8.c \
 *       --func func_020565C8 --addr 0x020565C8 --arm --cc ../1.2/sp2
 */
void func_020565C8(s32 s, s32 t, s32 x, s32 y)
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
 * (Rig_Hooks2 = { func_020565C8, func_0205650C }, docs/families/
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
 *   python tools/match.py one --src src/matched/func_0205650C.c \
 *       --func func_0205650C --addr 0x0205650C --arm --cc ../1.2/sp2
 */
void func_0205650C(s32 s, s32 t, s32 x, s32 z)
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
 * `u32 (*const [])(s32, s32, void *)` in src/matched/func_02054718.c, but a
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
 *   python tools/match.py one --src src/matched/func_02056460.c \
 *       --func func_02056460 --addr 0x02056460 --arm --cc ../1.2/sp2
 */
void func_02056460(s32 sn, s32 cs, struct MtxFx43 *m)
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
 * leaf in front of func_02056460.  It is written after func_02056460 because
 * this compiler places it first in the object only in that source order.
 */
void func_02056420(s32 sn, s32 cs, struct MtxFx43 *m)
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



void func_02055FD4(struct Obj *obj, struct S *s)
{
    struct Frame_02055FD4 f;
    struct SubC *p;
    struct MtxFx43 *mtx;
    s32 n;
    s32 a;
    s32 x;
    s32 y;
    s64 a64;
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
    p = obj->f40->f20->f00;
    sc = p->f30;
    sel = p->f48.sel;
    c2 = obj->f40->f72;
    k34 = s->f34;
    c1 = s->f36;
    mtx = obj->f44;
    v = ((u32)s->w.b10 << 24) | (obj->f3c | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    a = s->f30;
    a64 = (s64)(s32)a;
    n = (s32)((a64 * sc + 0x800) >> 12);
    x = n;
    y = a;
    if (sel == 0) {
        x = (s32)(((s64)n * k34 + 0x800) >> 12);
        y = (s32)(((a64 * k34) + 0x800) >> 12);
    } else if (sel == 1) {
        x = (s32)(((s64)n * k34 + 0x800) >> 12);
    } else {
        y = (s32)(((a64 * k34) + 0x800) >> 12);
    }

    p = obj->f40->f20->f00;
    if (p->f00.flag == 0) {
        f.t.x = s->p1.x + s->f38;
        f.t.y = s->p1.y + s->f3c;
        f.t.z = s->p1.z + s->f40;
        func_0207BC08(&f.t, mtx, &f.t);
        i = (s32)s->f20 >> 4;
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
        func_0207D918(&f.m);
    } else {
        f.t.x = s->p1.x + s->f38 - p->f04;
        f.t.y = s->p1.y + s->f3c - obj->f40->f20->f00->f08;
        f.t.z = s->p1.z + s->f40 - obj->f40->f20->f00->f0c;
        func_0207BC08(&f.t, mtx, &f.t);
        i = (s32)s->f20 >> 4;
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
        p = obj->f40->f20->f00;
        qc = p->f0c;  q8 = p->f08;  q4 = p->f04;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        func_0207D918(&f.m);
    }

    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    p = obj->f40->f20->f00;
    func_020565C8(obj->f40->f78, obj->f40->f7a, p->f50, p->f52);
}

#undef GX_RGB
#define GX_RGB(r, g, b) ((GXRgb)(((r) << GX_RGB_R_SHIFT) | ((g) << GX_RGB_G_SHIFT) | ((b) << GX_RGB_B_SHIFT)))




/*
 * Handler row of the rig dispatch (func_02053044 / func_0205312C pool rows;
 * docs/families/cluster_02052F58.h): a Z-rotation billboard.  Same top as
 * func_0205429C (POLYGON_ATTR, the three-way scale switch), then instead of
 * the basis hooks it transforms the particle position by the current matrix
 * (MTX_MultVec43, func_0207BC08), reads sin/cos from the Verts table at
 * s->f20 >> 4, fills a 4x3 matrix ROW-major { cs*x, sn*x, 0 ; -sn*y, cs*y, 0 ;
 * 0, 0, 1 ; t }, loads it (identity + [translate FIFO] + func_0207D918), mixes
 * the colour and calls the quad emitter func_020565C8 DIRECTLY.
 *
 * LOAD-BEARING SHAPES (wave 8):
 *   1. SubC->f30 is read into a local BEFORE the 0x040004A4 store, and
 *      obj->f44 likewise (the image loads both there).
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
 *   python tools/match.py one --src src/matched/func_02055B80.c \
 *       --func func_02055B80 --addr 0x02055B80 --arm --cc ../1.2/sp2
 */
void func_02055B80(struct Obj *obj, struct S *s)
{
    struct Frame_02055B80 f;
    struct SubC *p;
    struct MtxFx43 *mtx;
    s32 n;
    s32 a;
    s32 x;
    s32 y;
    s64 a64;
    u32 v;
    s32 i;
    s32 sn;
    s32 cs;
    s32 sc;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    sc = obj->f40->f20->f00->f30;
    mtx = obj->f44;
    v = ((u32)s->w.b10 << 24) | (obj->f3c | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    a = s->f30;
    a64 = (s64)(s32)a;
    n = (s32)((a64 * sc + 0x800) >> 12);
    x = n;
    y = a;
    p = obj->f40->f20->f00;
    switch (p->f48.sel) {
    case 0:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    case 1:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        break;
    case 2:
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    default:
        break;
    }

    if (p->f00.flag == 0) {
        f.t.x = s->p1.x + s->f38;
        f.t.y = s->p1.y + s->f3c;
        f.t.z = s->p1.z + s->f40;
        func_0207BC08(&f.t, mtx, &f.t);
        i = (s32)s->f20 >> 4;
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
        func_0207D918(&f.m);
    } else {
        f.t.x = s->p1.x + s->f38 - p->f04;
        f.t.y = s->p1.y + s->f3c - obj->f40->f20->f00->f08;
        f.t.z = s->p1.z + s->f40 - obj->f40->f20->f00->f0c;
        func_0207BC08(&f.t, mtx, &f.t);
        i = (s32)s->f20 >> 4;
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
        p = obj->f40->f20->f00;
        qc = p->f0c;  q8 = p->f08;  q4 = p->f04;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        func_0207D918(&f.m);
    }

    c1 = s->f36;
    c2 = obj->f40->f72;
    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    func_020565C8(obj->f40->f7c, obj->f40->f7e, 0, 0);
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
 * SPLDraw_DirectionalBillboard: the parent-particle twin of func_02054DB8,
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
void func_02055498(SPLManager *mgr, SPLParticle *ptcl)
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
 * and SPLUtil_DrawXYPlane (func_020565C8) with the child texture tiling.
 *
 * Wave 9, third lane: this body and every declaration it uses are the public
 * pret/pokeplatinum decompilation of the same NitroSystem particle library
 * (SPL; docs/families/cluster_02052F58.h), lib/spl/src/spl_draw.c SPLDraw_Child_DirectionalBillboard, with the
 * lib/spl/include/spl_*.h structs, and the SDK G3/MTX/VEC inlines written out
 * from sdk/TwlSDK/include; only the callees are pinned to Black addresses.
 * It compiled EXACT at the cluster pin unchanged, closing docs/notes/func_02054DB8.c.txt (286 out after two lanes).
 */
void func_02054DB8(SPLManager *mgr, SPLParticle *ptcl)
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
 * Twin of func_02054718: the prologue, the frames and the arm bodies are
 * byte-identical; it differs in the hook selector (bits 17..18 of
 * SubC.f00 rather than the u16 at SubX+0x14), in the MTX_Concat43 argument
 * order, and in a four-argument final hook.
 *
 * The same four source shapes that close func_02054718 close this row; see
 * its header for the measurements (the 0x040004A4 `|` chain order, the
 * `(s64)a * res->f30` operand order, `x` before `y` in case 0, and the three
 * 0x04000470 stores through locals loaded in reverse field order).
 *
 * Addresses are Black-image addresses.
 */
void func_02054A68(struct Obj *obj, struct S *s)
{
    struct Frame_02054A68 f;
    struct SubC *p;
    s32 n;
    s32 i;
    s32 a;
    s32 x;
    s32 y;
    s64 a64;
    u32 v;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    v = ((u32)s->w.b10 << 24) | (obj->f3c | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    i = (s32)s->f20 >> 4;
    func_02054A68_Hooks[obj->f40->f20->f00->f00.sel2]
        (func_02054A68_Verts[2 * i], func_02054A68_Verts[2 * i + 1], &f.m2);

    a = s->f30;
    n = (s32)(((s64)a * obj->f40->f20->f00->f30 + 0x800) >> 12);
    x = n;
    y = a;
    a64 = (s64)(s32)a;
    switch (obj->f40->f20->f00->f48.sel) {
    case 0:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    case 1:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        break;
    case 2:
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    default:
        break;
    }

    func_0207B5F4(&f.m3, x, y, y);
    func_0207B9F0(&f.m3, &f.m2, &f.m1);

    if (obj->f40->f20->f00->f00.flag == 0) {
        f.m1.m[9] = s->p1.x + s->f38;
        f.m1.m[10] = s->p1.y + s->f3c;
        f.m1.m[11] = s->p1.z + s->f40;
        func_0207D8E0(obj->f44);
        func_0207D918(&f.m1);
    } else {
        f.m1.m[9] = s->p1.x + s->f38 - obj->f40->f20->f00->f04;
        f.m1.m[10] = s->p1.y + s->f3c - obj->f40->f20->f00->f08;
        f.m1.m[11] = s->p1.z + s->f40 - obj->f40->f20->f00->f0c;
        *(volatile u32 *)0x04000454 = 0;
        p = obj->f40->f20->f00;
        qc = p->f0c;  q8 = p->f08;  q4 = p->f04;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        func_0207D918(obj->f44);
        func_0207D918(&f.m1);
    }

    c1 = s->f36;
    c2 = obj->f40->f72;
    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    p = obj->f40->f20->f00;
    func_02054A68_Hooks2[p->f00.sel1]
        (obj->f40->f78, obj->f40->f7a, p->f50, p->f52);
}



extern u32 (*const func_02054718_Hooks[])(s32, s32, void *);



extern u32 (*const func_02054718_Hooks2[])(s32, s32, s32, s32);




void func_02054718(struct Obj *obj, struct S *s)
{
    struct Frame_02054718 f;
    struct SubC *p;
    s32 n;
    s32 e;
    s32 i;
    s32 a;
    s32 x;
    s32 y;
    s64 a64;
    u32 v;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    v = ((u32)s->w.b10 << 24) | (obj->f3c | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    i = (s32)s->f20 >> 4;
    func_02054718_Hooks[obj->f40->f20->f14->hw.sel2]
        (func_02054718_Verts[2 * i], func_02054718_Verts[2 * i + 1], &f.m2);

    a = s->f30;
    n = (s32)(((s64)a * obj->f40->f20->f00->f30 + 0x800) >> 12);
    x = n;
    y = a;
    a64 = (s64)(s32)a;
    switch (obj->f40->f20->f00->f48.sel) {
    case 0:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    case 1:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        break;
    case 2:
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    default:
        break;
    }

    func_0207B5F4(&f.m3, x, y, y);
    func_0207B9F0(&f.m2, &f.m3, &f.m1);

    if (obj->f40->f20->f00->f00.flag == 0) {
        f.m1.m[9] = s->p1.x + s->f38;
        f.m1.m[10] = s->p1.y + s->f3c;
        f.m1.m[11] = s->p1.z + s->f40;
        func_0207D8E0(obj->f44);
        func_0207D918(&f.m1);
    } else {
        f.m1.m[9] = s->p1.x + s->f38 - obj->f40->f20->f00->f04;
        f.m1.m[10] = s->p1.y + s->f3c - obj->f40->f20->f00->f08;
        f.m1.m[11] = s->p1.z + s->f40 - obj->f40->f20->f00->f0c;
        *(volatile u32 *)0x04000454 = 0;
        p = obj->f40->f20->f00;
        qc = p->f0c;  q8 = p->f08;  q4 = p->f04;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        func_0207D918(obj->f44);
        func_0207D918(&f.m1);
    }

    c1 = s->f36;
    c2 = obj->f40->f72;
    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    e = 0;
    func_02054718_Hooks2[obj->f40->f20->f14->hw.sel1]
        (obj->f40->f7c, obj->f40->f7e, e, e);
}




extern u32 (*const func_0205429C_Hooks[])(s32, s32, void *);




extern u32 (*const func_0205429C_Hooks2[])(s32, s32, s32, s32);





void func_0205429C(struct Obj *obj, struct S *s)
{
    struct Frame f;
    struct SubC *p;
    s32 n;
    s32 i;
    s32 a;
    s32 x;
    s32 y;
    s64 a64;
    u32 v;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    v = ((u32)s->w.b10 << 24) | (obj->f3c | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    i = (s32)s->f20 >> 4;
    func_0205429C_Hooks[obj->f40->f20->f00->f00.sel2]
        (func_0205429C_Verts[2 * i], func_0205429C_Verts[2 * i + 1], &f.m2);

    func_0207B598(&f.m4);
    if (obj->f40->f20->f00->f48.hi == 0) {
        func_0207CCA4(&s->p2, &f.v0);
    } else {
        func_0207CCA4(&s->p1, &f.v0);
        f.v0.x = -f.v0.x;
        f.v0.y = -f.v0.y;
        f.v0.z = -f.v0.z;
    }

    f.v3.x = 0;
    f.v3.y = 0x1000;
    f.v3.z = 0;
    i = func_0207CA68(&f.v0, &f.v3);
    if (i > 0xCCD || i < -0xCCD) {
        f.v3.x = 0x1000;
        f.v3.y = 0;
        f.v3.z = 0;
    }

    func_0207CAE8(&f.v0, &f.v3, &f.v1);
    func_0207CAE8(&f.v0, &f.v1, &f.v2);

    f.m4.m[0] = f.v1.x;
    f.m4.m[1] = f.v1.y;
    f.m4.m[2] = f.v1.z;
    f.m4.m[3] = f.v0.x;
    f.m4.m[4] = f.v0.y;
    f.m4.m[5] = f.v0.z;
    f.m4.m[6] = f.v2.x;
    f.m4.m[7] = f.v2.y;
    f.m4.m[8] = f.v2.z;

    func_0207B9F0(&f.m2, &f.m4, &f.m2);

    a = s->f30;
    n = (s32)(((s64)a * obj->f40->f20->f00->f30 + 0x800) >> 12);
    x = n;
    y = a;
    a64 = (s64)(s32)a;
    switch (obj->f40->f20->f00->f48.sel) {
    case 0:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    case 1:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        break;
    case 2:
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    default:
        break;
    }

    func_0207B5F4(&f.m3, x, y, y);
    func_0207B9F0(&f.m3, &f.m2, &f.m1);

    if (obj->f40->f20->f00->f00.flag == 0) {
        f.m1.m[9] = s->p1.x + s->f38;
        f.m1.m[10] = s->p1.y + s->f3c;
        f.m1.m[11] = s->p1.z + s->f40;
        func_0207D8E0(obj->f44);
        func_0207D918(&f.m1);
    } else {
        f.m1.m[9] = s->p1.x + s->f38 - obj->f40->f20->f00->f04;
        f.m1.m[10] = s->p1.y + s->f3c - obj->f40->f20->f00->f08;
        f.m1.m[11] = s->p1.z + s->f40 - obj->f40->f20->f00->f0c;
        *(volatile u32 *)0x04000454 = 0;
        p = obj->f40->f20->f00;
        qc = p->f0c;  q8 = p->f08;  q4 = p->f04;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        func_0207D918(obj->f44);
        func_0207D918(&f.m1);
    }

    c1 = s->f36;
    c2 = obj->f40->f72;
    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    p = obj->f40->f20->f00;
    func_0205429C_Hooks2[p->f00.sel1]
        (obj->f40->f78, obj->f40->f7a, p->f50, p->f52);
}






extern u32 (*const func_02053E1C_Hooks[])(s32, s32, void *);






extern u32 (*const func_02053E1C_Hooks2[])(s32, s32, s32, s32);







/*
 * Handler row 0 of the rig render-list dispatch (func_02053044 /
 * func_0205312C pool rows; docs/families/cluster_02052F58.h).  Same skeleton
 * as func_0205429C, transcribed from it with five differences read off the
 * listing:
 *   - the basis hook is selected by SubD->hw bits 9..10 (BfHw.sel2, as in
 *     func_02054718), not SubC->f00 bits 17..18;
 *   - the direction/negated-position choice is SubD->f10 bit 6 (BfSel.sel),
 *     not SubC->f48 bit 31;
 *   - the scale concat is MTX_Concat43(m2, m3, m1) -- operands the other way
 *     round from func_0205429C's (m3, m2, m1); the only 2 bytes the straight
 *     transcription had wrong;
 *   - the quad-emitter hook is SubD->hw bit 11 (BfHw.sel1);
 *   - its arguments are SubB +0x7c/+0x7e and two literal zeros.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02053E1C.c \
 *       --func func_02053E1C --addr 0x02053E1C --arm --cc ../1.2/sp2
 */
void func_02053E1C(struct Obj *obj, struct S *s)
{
    struct Frame f;
    struct SubC *p;
    s32 n;
    s32 i;
    s32 a;
    s32 x;
    s32 y;
    s64 a64;
    u32 v;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    v = ((u32)s->w.b10 << 24) | (obj->f3c | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    i = (s32)s->f20 >> 4;
    func_02053E1C_Hooks[obj->f40->f20->f14->hw.sel2]
        (func_02053E1C_Verts[2 * i], func_02053E1C_Verts[2 * i + 1], &f.m2);

    func_0207B598(&f.m4);
    if (obj->f40->f20->f14->f10.sel == 0) {
        func_0207CCA4(&s->p2, &f.v0);
    } else {
        func_0207CCA4(&s->p1, &f.v0);
        f.v0.x = -f.v0.x;
        f.v0.y = -f.v0.y;
        f.v0.z = -f.v0.z;
    }

    f.v3.x = 0;
    f.v3.y = 0x1000;
    f.v3.z = 0;
    i = func_0207CA68(&f.v0, &f.v3);
    if (i > 0xCCD || i < -0xCCD) {
        f.v3.x = 0x1000;
        f.v3.y = 0;
        f.v3.z = 0;
    }

    func_0207CAE8(&f.v0, &f.v3, &f.v1);
    func_0207CAE8(&f.v0, &f.v1, &f.v2);

    f.m4.m[0] = f.v1.x;
    f.m4.m[1] = f.v1.y;
    f.m4.m[2] = f.v1.z;
    f.m4.m[3] = f.v0.x;
    f.m4.m[4] = f.v0.y;
    f.m4.m[5] = f.v0.z;
    f.m4.m[6] = f.v2.x;
    f.m4.m[7] = f.v2.y;
    f.m4.m[8] = f.v2.z;

    func_0207B9F0(&f.m2, &f.m4, &f.m2);

    a = s->f30;
    n = (s32)(((s64)a * obj->f40->f20->f00->f30 + 0x800) >> 12);
    x = n;
    y = a;
    a64 = (s64)(s32)a;
    switch (obj->f40->f20->f00->f48.sel) {
    case 0:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    case 1:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        break;
    case 2:
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    default:
        break;
    }

    func_0207B5F4(&f.m3, x, y, y);
    func_0207B9F0(&f.m2, &f.m3, &f.m1);

    if (obj->f40->f20->f00->f00.flag == 0) {
        f.m1.m[9] = s->p1.x + s->f38;
        f.m1.m[10] = s->p1.y + s->f3c;
        f.m1.m[11] = s->p1.z + s->f40;
        func_0207D8E0(obj->f44);
        func_0207D918(&f.m1);
    } else {
        f.m1.m[9] = s->p1.x + s->f38 - obj->f40->f20->f00->f04;
        f.m1.m[10] = s->p1.y + s->f3c - obj->f40->f20->f00->f08;
        f.m1.m[11] = s->p1.z + s->f40 - obj->f40->f20->f00->f0c;
        *(volatile u32 *)0x04000454 = 0;
        p = obj->f40->f20->f00;
        qc = p->f0c;  q8 = p->f08;  q4 = p->f04;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        func_0207D918(obj->f44);
        func_0207D918(&f.m1);
    }

    c1 = s->f36;
    c2 = obj->f40->f72;
    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    func_02053E1C_Hooks2[obj->f40->f20->f14->hw.sel1]
        (obj->f40->f7c, obj->f40->f7e, 0, 0);
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
 * Closes docs/notes/func_02053D30.c.txt (41 out after two lanes, the whole
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
void func_02053D30(SPLTexture *tex)
{
    SPLTextureParam param = tex->param;
    G3_TexImageParam(param.format, GX_TEXGEN_TEXCOORD, param.s, param.t, param.repeat, param.flip, param.palColor0, tex->texAddr);
    G3_TexPlttBase(tex->palAddr, param.format);
    G3_MtxMode(GX_MTXMODE_TEXTURE);
    G3_Identity();
    G3_Scale(tex->width * FX32_ONE, tex->height * FX32_ONE, 0);
    G3_MtxMode(GX_MTXMODE_POSITION);
}












void func_02053D2C(void)
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
  o->f78 = (s16) (0x1000 << ((o->f20->f00->f48 << 6) >> 30));
  o->f7a = (s16) (0x1000 << ((o->f20->f00->f48 << 4) >> 30));
  if ((o->f20->f00->f4c << 31) >> 31)
    o->f78 = (s16) (o->f78 * (-1));
  if ((o->f20->f00->f4c << 30) >> 31)
    o->f7a = (s16) (o->f7a * (-1));
  c = o->f20;
  if ((c->f00->f00 << 15) >> 31)
  {
    {
      s32 t = c->f14->f10;
      s32 u = t << 30;
      o->f7c = (s16) (0x1000 << (((u32) u) >> 30));
    }
    o->f7e = (s16) (0x1000 << ((o->f20->f14->f10 << 28) >> 30));
    if ((o->f20->f14->f10 << 27) >> 31)
      o->f7c = (s16) (o->f7c * (-1));
    if ((o->f20->f14->f10 << 26) >> 31)
      o->f7e = (s16) (o->f7e * (-1));
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
    struct Desc_0205312C *d = b->f20->f00;
    Fn fn = 0;
    Fn1 g;
    struct Node_0205312C *n;

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
