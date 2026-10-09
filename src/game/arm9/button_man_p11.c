/*
 * file:     button_man_p11.c
 * unit:     yes
 * function: func_02056460, func_0205650C, func_020565C8, func_02056684, func_020569A4, func_020576D0, func_02057830, func_02057AB8, func_02057B10, func_02057B5C, func_02057BC0, func_02057C9C, func_02057E68
 * address:  0x02056460
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
 *   func_02058380  0x02058380  arm
 *   func_020583CC  0x020583CC  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   g_02146A8C     0x02146A8C  data
 *   SPLList_PopFront                 0x02058380  arm
 *   SPLList_PushFront                0x020583CC  arm
 *   SPLRandom_VecFx32                0x02058478  arm
 *   SPLRandom_VecFx32_XY             0x0205841C  arm
 *   SPLUtil_TiltCoordinates          0x020576D0  arm
 *   SPLEmitter_ComputeOrthogonalAxes 0x02057830  arm
 *   VEC_Fx16CrossProduct             0x0207CB68  arm
 *   VEC_DotProduct                   0x0207CA68  arm
 *   VEC_Normalize                    0x0207CCA4  arm
 *   _u32_div_f                       0x0209C2B0  arm
 *   FX_SinCosTable_                  0x020A1B38  data
 *   func_0207CB68   0x0207CB68  arm
 *   func_0207CDB8   0x0207CDB8  arm
 *   func_0207CAA4  0x0207CAA4  arm
 *   g_020A7FEC     0x020A7FEC  data
 */
#define GX_RGB(r, g, b) (((r) << 0) | ((g) << 5) | ((b) << 10))
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
struct SPLParticle;
struct SPLEmitter;
struct List;
struct Node;
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

struct Obj {
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

struct Node { u8 pad_00[0x22]; GXRgb col; };

struct Ctx { struct Node *node; u8 pad_04[4]; struct Key *key; };

struct Out { u8 pad_00[0x36]; GXRgb col; };

typedef short s16_020576D0;

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

struct Vec16 { s16_020576D0 x, y, z; };

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
    s16_020576D0          r0[3];
    s16_020576D0          r1[3];
};

typedef struct { fx32 x, y, z; } VecFx32;

struct Mtx3 {
    u8  pad[0x84];
    s16_020576D0 r0[3];
    s16_020576D0 r1[3];
};

typedef unsigned long long u64;

typedef signed char s8;

typedef signed short s16_02056460;

typedef s16_02056460 fx16;

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
    s16_02056460 minRotation;
    s16_02056460 maxRotation;
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
    s16_02056460 angularVelocity;
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

struct VecFx32 { fx32 x, y, z; };

struct PBf { u16 b0 : 5; u16 b5 : 5; u16 b10 : 6; };

struct Ptcl {
    u8 pad00[0x08];
    struct VecFx32 pos;     /* +0x08 */
    struct VecFx32 vel;     /* +0x14 */
    u16 f20;
    s16_02056460 f22;
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

struct Desc {
    struct DescBf f;        /* +0x00 */
    s16_02056460 f02;
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
    s16_02056460 f22;
    u16 f24;
    u8 pad26[0x08];
    struct PBf w;           /* +0x2e */
    fx32 f30;
    s16_02056460 f34;
    u16 f36;
    struct VecFx32 f38;
};

struct SubX { u8 pad00[0x14]; struct Desc *desc; };

struct Owner { u8 pad00[0x14]; u8 list[0x0c]; struct SubX *x; };

struct MtxFx43 { s32 m[12]; };

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
extern struct Node *func_02058380(struct List *list);
extern void func_020583CC(volatile struct List *list, volatile struct Node *node);
void func_02057E68(struct Obj *o, struct Src_02057E68 *s, int t);
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
extern const struct Vec16 g_020A7FEC;
extern const fx16 FX_SinCosTable_[];
extern u32 g_02146A8C;



void func_02057E68(struct Obj *o, struct Src_02057E68 *s, int t)
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
    struct Node *n = ctx->node;
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
    struct Desc *d = o->x->desc;
    fx32 scale = FX_Mul(d->f08 << 12, 0x10);
    s32 i;
    for (i = 0; i < d->f0c; i++) {
        p = (struct Ptcl *)func_02058380(pool);
        if (p == 0)
            return;
        func_020583CC((volatile struct List *)o->list, (volatile struct Node *)p);
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
