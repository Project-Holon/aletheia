/*
 * file:     mcss.c
 * unit:     yes
 * function: func_02014910, func_0201493C, func_02014A10, func_02014A20, func_02014A80, func_02014B08, func_02014BA8, func_02014C08, func_02014CB8, func_02014CD4, func_02014CEC, func_02014CF0, func_02014CF8, func_02014D2C, func_020155A0, func_020159C8, func_02015BA4, func_02015BF0, func_02015C00, func_02015C0C, func_02015C1C, func_02015C30, func_02015C48, func_02015C60, func_02015C78, func_02015C94, func_02015CAC, func_02015CC4, func_02015CDC, func_02015CF8, func_02015D14, func_02015D30, func_02015D4C, func_02015D64, func_02015D80, func_02015D88, func_02015D94, func_02015DB0, func_02015DC0, func_02015DD4, func_02015DF8, func_02015E04, func_02015E28, func_02015E4C, func_02015E70, func_02015E94, func_02015EA0, func_02015EB0, func_02015EC4, func_02015EE8, func_02015EEC, func_02015EF4, func_02015EFC, func_02015F04, func_02015F0C, func_02015F14, func_02015F1C, func_02015F24, func_02015F2C, func_02015F40, func_02015F50, func_02015FAC, func_02015FBC, func_02015FD4, func_02015FF0, func_0201600C, func_02016020, func_02016024, func_02016028, func_02016068, sub_02016078, func_020160C0, func_020160C4, func_020160CC, func_020160D4, func_0201624C, func_02016374, func_02016380, func_02016394, func_020163B0, func_020163B4, func_020163C4, func_02016630, func_02016880, func_0201691C, func_02016984, func_020169D4, func_020169E8, func_02016BA0, func_02016C0C, func_02016C38, func_02016C60, func_02016FC8, func_02017100, func_02017114, func_02017168, func_02017214, func_02017270, func_020172AC, func_020172BC, func_020172D8, func_020173B4, sub_020173C8
 * address:  0x02014910
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02013F2C  0x02013F2C  thumb
 *   func_02013B38  0x02013B38  thumb
 *   func_0201407C  0x0201407C  thumb
 *   func_020140DC  0x020140DC  thumb
 *   func_020140B4  0x020140B4  thumb
 *   sub_020307B0   0x020307B0  arm
 *   sub_0209E054_Map  0x0209E054  data
 *   func_020490A8       0x020490A8  arm
 *   func_02048F60       0x02048F60  arm
 *   VEC_Fx16Normalize   0x0207CDB8  arm
 *   func_02011400  0x02011400  thumb
 *   func_02030734     0x02030734  arm
 *   func_020637D4     0x020637D4  arm
 *   func_02049F34     0x02049F34  arm
 *   func_020056A0     0x020056A0  thumb
 *   sFileMcss  0x020A72CC  data
 *   func_02014CD4   0x02014CD4  thumb
 *   func_02030EE8   0x02030EE8  arm
 *   func_020307B0   0x020307B0  arm
 *   func_02030EAC   0x02030EAC  arm
 *   func_02015BA4   0x02015BA4  thumb
 *   func_02016374  0x02016374  thumb
 *   func_020490F4         0x020490F4  arm
 *   ENV_SetResourceSet_2  0x02049238  arm
 *   func_02016BA0  0x02016BA0  thumb
 *   func_0206DB80    0x0206DB80  arm
 *   MTX_Inverse43    0x0207B67C  arm
 *   MI_Copy36B       0x02082B60  arm
 *   MTX_Copy33To44_  0x0207ADE8  arm
 *   MTX_Copy43To44_  0x0207B5C0  arm
 *   MTX_Concat44     0x0207BE14  arm
 *   G3i_LookAt_      0x0207D7C4  arm
 *   G3_RotX          0x0207D810  arm
 *   G3_RotZ          0x0207D888  arm
 *   G3_MultMtx44     0x0207D8FC  arm
 *   sub_0207C768     0x0207C768  arm
 *   g_02148B98       0x02148B98  data
 *   g_02148B54       0x02148B54  data
 *   g_02148D8C       0x02148D8C  data
 *   g_02148D98       0x02148D98  data
 *   g_02148DA4       0x02148DA4  data
 *   FX_SinCosTable_  0x020A1B38  data
 *   d_0209E090       0x0209E090  data
 *   d_0209E09C       0x0209E09C  data
 *   G3i_FrustumW_    0x0207D760  arm
 *   func_02016C0C  0x02016C0C  thumb
 *   func_02063000  0x02063000  arm
 *   func_02064D70  0x02064D70  arm
 *   func_020627D8  0x020627D8  arm
 *   func_0206469C  0x0206469C  arm
 *   func_02021F64  0x02021F64  thumb
 *   func_02030DA8  0x02030DA8  arm
 *   func_02082A60  0x02082A60  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_02064CBC  0x02064CBC  arm
 *   func_02063A54  0x02063A54  arm
 *   func_02063E54  0x02063E54  arm
 *   sub_02030EAC   0x02030EAC  arm
 *   _s32_to_double  0x0209B750  arm
 *   func_0209AB80   0x0209AB80  arm
 *   _d2s            0x0209C508  arm
 *   func_0202D060  0x0202D060  thumb
 *   func_0202D09C  0x0202D09C  thumb
 *   func_0202D0D4  0x0202D0D4  thumb
 *   func_0202D110  0x0202D110  thumb
 *   func_0202D144  0x0202D144  thumb
 *   func_0202D178  0x0202D178  thumb
 *   func_0202D1AC  0x0202D1AC  thumb
 *   func_0202D1E0  0x0202D1E0  thumb
 *   func_0202D5CC  0x0202D5CC  thumb
 *   func_0202D5F8  0x0202D5F8  thumb
 *   func_0202D61C  0x0202D61C  thumb
 *   func_0202D640  0x0202D640  thumb
 *   func_0202D664  0x0202D664  thumb
 *   func_0202D688  0x0202D688  thumb
 *   func_0202D6AC  0x0202D6AC  thumb
 *   func_0202D6D0  0x0202D6D0  thumb
 *   sSpindaSpotCoords  0x020A72D4  data
 */

#define REG_MTX_MODE     (*(vu32 *)0x04000440)
#define REG_MTX_PUSH     (*(vu32 *)0x04000444)
#define REG_MTX_POP      (*(vu32 *)0x04000448)
#define REG_MTX_STORE    (*(vu32 *)0x0400044C)
#define REG_MTX_IDENTITY (*(vu32 *)0x04000454)
#define REG_MTX_SCALE    (*(vu32 *)0x0400046C)
#define REG_MTX_TRANS    (*(vu32 *)0x04000470)
#define REG_TEXIMAGE_PARAM (*(vu32 *)0x040004A8)
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))
#define REG_MTX_RESTORE  (*(vu32 *)0x04000450)
#define REG_TEXCOORD     (*(vu32 *)0x04000488)
#define REG_VTX_16       (*(vu32 *)0x0400048C)
#define REG_POLYGON_ATTR (*(vu32 *)0x040004A4)
#define REG_TEXPLTT_BASE (*(vu32 *)0x040004AC)
#define REG_BEGIN_VTXS   (*(vu32 *)0x04000500)
#define REG_END_VTXS     (*(vu32 *)0x04000504)
typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned char  u8;

typedef signed short s16;

typedef signed char   s8;

typedef signed long long s64;

typedef s32 fx32;

typedef s64 fx64;

typedef volatile u32 vu32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct { fx32 m[4][3]; } MtxFx43;

typedef struct { fx32 m[3][3]; } MtxFx33;

typedef struct { fx32 m[4][4]; } MtxFx44;

typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_PLTT4 = 2 } GXTexFmt;

typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1 } GXTexGen;

typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;

typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;

typedef enum { GX_TEXREPEAT_NONE = 0, GX_TEXREPEAT_ST = 3 } GXTexRepeat;

typedef enum { GX_TEXFLIP_NONE = 0, GX_TEXFLIP_ST = 3 } GXTexFlip;

typedef enum { GX_TEXPLTTCOLOR0_USE = 0, GX_TEXPLTTCOLOR0_TRNS = 1 } GXTexPlttColor0;

struct McssSys;
struct McssWork;
struct McssTransTask;
struct AnimBank;

/*
 * What to load for one sprite: the archive and the member ids of its
 * resources.  Built by the MCSS_TOOL_MakeAddWork functions, stored in the
 * work at +0x150 so the resources can be reloaded.  heapMode 1 puts the
 * resources into the 0x8000 heap bank.
 */
typedef struct McssAddWork {
    u32 arcId;                          /* 0x00 */
    u32 textureMember;                  /* 0x04 */
    u32 paletteMember;                  /* 0x08 */
    u32 cellMember;                     /* 0x0C */
    u32 cellAnimMember;                 /* 0x10 */
    u32 multiCellMember;                /* 0x14 */
    u32 multiCellAnimMember;            /* 0x18 */
    u32 cellHeaderMember;               /* 0x1C */
    u32 heapMode;                       /* 0x20 */
} McssAddWork;

/* Called after a sprite's resources are loaded; returns 1 to unhook itself. */
typedef u32 (*McssLoadHook)(const McssAddWork *addWork, struct McssTransTask *task, u32 hookWork);

/* One pose of a sprite part: the kind of the animation decides which fields the data holds. */
typedef struct McssPose {
    u16  index;                         /* cell frame or cell index */
    u16  rot;
    fx32 sx;
    fx32 sy;
    s16  ofsX;
    s16  ofsY;
} McssPose;

/* Pose data of kind 2: index and offset only. */
typedef struct McssPoseOfs {
    u16 index;
    u16 pad;
    s16 ofsX;
    s16 ofsY;
} McssPoseOfs;

typedef struct McssPoseFrame {
    void *content;
    u16   duration;
    u16   pad;
} McssPoseFrame;

typedef struct McssPoseSeq {
    u16 numFrames;
    u16 loopStart;
    u32 kind;                           /* 0: index, 1: full pose, 2: index and offset */
} McssPoseSeq;

/* Animation playback state, 0x34 bytes (McssWork +0x34 and the start of each node). */
typedef struct McssAnimCtrl {
    McssPoseFrame *cur;
    u8             state[0x1C - 0x04];
    McssPoseSeq   *seq;
    u8             tail[0x34 - 0x20];
} McssAnimCtrl;

/* One part of a multi cell sprite; the cell animation owns an array of them. */
typedef struct McssCellNode {
    McssAnimCtrl ctrl;
    u8           tail[0x5C - 0x34];
} McssCellNode;

typedef struct McssAnimCell {
    s16 cellId;
    s16 ofsX;
    s16 ofsY;
    u16 nodeInfo;                       /* high byte: index into the node array */
} McssAnimCell;

typedef struct McssCellFrame {
    u16           count;
    u16           pad;
    McssAnimCell *cells;
} McssCellFrame;

typedef struct McssCellAnim {
    u32            numFrames;
    McssCellFrame *frames;
} McssCellAnim;

/* The state of the cell animation at McssWork +0x68, 0x30 bytes. */
typedef struct McssCellCtrl {
    u8             head[0x0C];
    McssCellNode  *nodes;               /* 0x0C */
    McssCellAnim  *anim;                /* 0x10 */
    u8             tail[0x30 - 0x14];
} McssCellCtrl;

/* One textured rectangle: position, size and texture origin, all in fx32. */
typedef struct McssQuad {
    fx32 x, y, w, h, s, t;
} McssQuad;

/* One cell record: the body quad and the eye (mepachi) quad. */
typedef struct McssCellRec {
    McssQuad body;
    McssQuad eye;
} McssCellRec;

/* The header the cell data starts with (McssWork +0x2C). */
typedef struct McssCellHeader {
    u32 cellCount;
    u16 sizeX;
    u16 sizeY;
    s16 ofsX;
    s16 ofsY;
    McssCellRec cells[1];
} McssCellHeader;

/* Texture image proxy: VRAM addresses (3D, main, sub; -1 is unset) and the texture parameters. */
typedef struct McssTexImage {
    u32 vramAddr[3];                    /* 0x00 */
    u32 sizeS;                          /* 0x0C */
    u32 sizeT;                          /* 0x10 */
    u32 fmt;                            /* 0x14 */
    u32 byteSize;                       /* 0x18 */
    u32 pltt0;                          /* 0x1C */
} McssTexImage;

/* Palette image proxy, 0x14 bytes: format, size and the three VRAM addresses. */
typedef struct McssPlttProxy {
    s32 fmt;                            /* 0x00 */
    u32 byteSize;                       /* 0x04 */
    u32 vramAddr[3];                    /* 0x08 */
} McssPlttProxy;

/* A loaded palette. */
typedef struct McssPlttData {
    u32   fmt;                          /* 0x00 */
    u32   extended;                     /* 0x04 */
    u32   byteSize;                     /* 0x08 */
    void *data;                         /* 0x0C */
} McssPlttData;

/* A loaded texture; only the raw pixel pointer is read here. */
typedef struct McssTexData {
    u8  header[0x14];
    u8 *rawData;                        /* 0x14 */
} McssTexData;

/*
 * Work block of a texture or palette transfer task, 0x2C bytes.  Without a
 * task system the task only runs while the scanline is in 0xC0..0xC8.
 */
typedef struct McssTransTask {
    McssTexData   *texData;             /* 0x00 */
    McssPlttData  *plttData;            /* 0x04 */
    McssTexImage  *texImageOut;         /* 0x08 */
    McssPlttProxy *plttProxyOut;        /* 0x0C */
    void          *texBuf;              /* 0x10 */
    void          *plttBuf;             /* 0x14 */
    u32            texDest;             /* 0x18 */
    u32            plttDest;            /* 0x1C */
    struct McssSys *sys;                /* 0x20 */
    struct McssWork *work;              /* 0x24 */
    u32            hasTaskSys;          /* 0x28 */
} McssTransTask;

/*
 * The MCSS system: one per scene, owns the work slots and the shared
 * shadow palette.  Size 0x4C (MCSS_Init allocates it).
 */
typedef struct McssSys {
    void *arcHandle;                    /* 0x00 */
    u32 arcId;                          /* 0x04 */
    void *taskSys;                      /* 0x08 */
    void *shadowPlttTask;               /* 0x0C */
    s32 maxCount;                       /* 0x10 */
    struct McssWork **works;            /* 0x14 */
    McssPlttProxy shadowPltt;           /* 0x18 */
    union {                             /* 0x2C */
        u32 raw;
        struct {
            u32 orthoMode : 1;
            u32 nearDepthRange : 1;     /* far plane 512 and depth step 0x100 */
        } bits;
    } flags;
    u32 texTransAdrs;                   /* 0x30 */
    u32 plttTransAdrs;                  /* 0x34 */
    McssLoadHook loadHook;              /* 0x38 */
    u32 loadHookWork;                   /* 0x3C */
    u32 heapId;                         /* 0x40 */
    fx32 globalScale;                   /* 0x44 */
    s32 depthStep;                      /* 0x48 */
} McssSys;

/* The flag word at McssWork +0x140. */
typedef union McssFlags {
    u32 raw;
    struct {
        u32 alpha : 8;                  /* 0x1F = opaque */
        u32 mepachiFlag : 1;
        u32 anmStopFlag : 2;            /* bit 0 stop, bit 1 stop always */
        u32 vanishFlag : 1;
        u32 paletteFadeFlag : 1;
        u32 loaded : 1;
        u32 shadowAlpha : 9;
        u32 shadowVanishFlag : 1;
        u32 mosaic : 4;
        u32 plttCurrentValid : 1;       /* plttCurrent holds the last blended palette */
        u32 orthoBillboardFlag : 1;
        u32 mepachiDrawLast : 1;
        u32 shadowForceDraw : 1;
    } bits;
} McssFlags;

typedef union McssRequestFlags {
    u32 raw;
    struct {
        u32 stopAtStart : 1;
    } bits;
} McssRequestFlags;

/* One MCSS object (a multi-cell sprite).  Size 0x188. */
typedef struct McssWork {
    void *textureTask;                  /* 0x000 */
    void *fadeTask;                     /* 0x004 */
    void *paletteTask;                  /* 0x008 */
    void *cellFile;                     /* 0x00C */
    void *cellBank;                     /* 0x010 */
    void *multiCellFile;                /* 0x014 */
    void *multiCellBank;                /* 0x018 */
    void *cellAnimFile;                 /* 0x01C */
    void *cellAnimBank;                 /* 0x020 */
    void *multiCellAnimFile;            /* 0x024 */
    struct AnimBank *multiCellAnimBank; /* 0x028 */
    McssCellHeader *cellHeader;         /* 0x02C */
    u8 *stopCellTable;                  /* 0x030 */
    McssAnimCtrl animCtrl;              /* 0x034 */
    McssCellCtrl cellCtrl;              /* 0x068 */
    void *animWork;                     /* 0x098 */
    McssTexImage texImage;              /* 0x09C */
    u32 texImageExtra;                  /* 0x0BC */
    McssPlttProxy plttProxy;            /* 0x0C0 */
    void *plttOriginal;                 /* 0x0D4 */
    void *plttCurrent;                  /* 0x0D8 */
    u32 plttByteSize;                   /* 0x0DC */
    VecFx32 position;                   /* 0x0E0 */
    VecFx32 scale;                      /* 0x0EC */
    VecFx32 rotate;                     /* 0x0F8 */
    VecFx32 ofsScale;                   /* 0x104 */
    VecFx32 drawScale;                  /* 0x110 */
    VecFx32 ofsPosition;                /* 0x11C */
    VecFx32 shadowScale;                /* 0x128 */
    s8 fadeStart;                       /* 0x134 */
    s8 fadeEnd;                         /* 0x135 */
    s8 fadeWait;                        /* 0x136 */
    s8 fadeWaitSet;                     /* 0x137 */
    s32 fadeStep;                       /* 0x138 */
    u32 fadeColor;                      /* 0x13C */
    McssFlags flags;                    /* 0x140 */
    McssRequestFlags requestFlags;      /* 0x144 bit 0: stop the anime at its start */
    u32 index;                          /* 0x148 */
    u32 heapId;                         /* 0x14C */
    McssAddWork addWork;                /* 0x150 */
    fx32 animeSpeed;                    /* 0x174 */
    u16 shadowRotX;                     /* 0x178 */
    u16 shadowRotZ;                     /* 0x17A */
    VecFx32 shadowOffset;               /* 0x17C */
} McssWork;

/* One 0x34-byte record of the time-of-day light table. */
struct LightTableEntry {
    u16 hourKey;                        /* 0x00 */
    s16 minute;                         /* 0x02 */
    u8  pad0[4];
    u16 colorA[4];                      /* 0x08 */
    s16 dir[4][3];                      /* 0x10 */
    u16 colorB[4];                      /* 0x28 */
    u8  pad1[4];
};

extern void *func_020122C0(void *owner, void *parent, void *callback, u32 workSize);
extern void *func_020124E8(void *task);
extern u32 func_02014878(u32 task, u32 *mode, u32 *taskWork);
extern u32 func_02013F2C(u32 id);
extern u32 func_02013B38(u32 id);
extern void *func_0201407C(u16 heap, u32 zoneLightId, u32 season);
extern u8 func_020140DC(void *p);
extern u32 func_020140B4(void *a);
extern u32 sub_020307B0(void *p);
extern u32   func_020490A8(u32 archive, u32 member);
extern void *func_02048F60(u32 archive, u32 member, u32 heap);
extern void  VEC_Fx16Normalize(void *dest, const void *src);
extern u8 func_02011400(int season, int key);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020637D4(u32 *proxy);
extern void *func_02049F34(u32 arcId, u32 member, McssPlttData **out, u32 heap);
extern void *func_020056A0(void *fn, void *work, u32 priority);
extern void func_02014CD4(McssSys *sys);
extern void *func_02030EE8(void *task);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(void *task);
extern void func_02015BA4(McssSys *sys, McssWork *work);
extern void func_020649D4(McssAnimCtrl *ctrl, fx32 speed);
extern void func_02016374(McssWork *work);
extern void *func_020490F4(u32 id, u32 heap);
extern void  ENV_SetResourceSet_2(void *arcHandle);
extern void func_02016BA0(McssWork *work);
extern void func_0206DB80(void);
extern int  MTX_Inverse43(const MtxFx43 *src, MtxFx43 *dst);
extern void MI_Copy36B(const void *src, void *dst);
extern void MTX_Copy33To44_(const MtxFx33 *src, MtxFx44 *dst);
extern void MTX_Copy43To44_(const MtxFx43 *src, MtxFx44 *dst);
extern void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
extern void G3i_LookAt_(const VecFx32 *camPos, const VecFx32 *camUp,
                        const VecFx32 *target, int draw, MtxFx43 *mtx);
extern void G3_RotX(fx32 s, fx32 c);
extern void G3_RotZ(fx32 s, fx32 c);
extern void G3_MultMtx44(const MtxFx44 *m);
extern u32 sub_0207C768(u32 value, u32 divisor);
extern void G3i_FrustumW_(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f,
                          fx32 scaleW, int draw, void *mtx);
extern void func_02016C0C(void *taskHandle);
extern void func_02063000(int p0, int p1, int p2, int p3);
extern void func_02064D70(void *, void *, unsigned);
extern void *func_020627D8(struct AnimBank *bank, u32 idx);
extern void func_0206469C(McssAnimCtrl *ctrl, void *seq);
extern void *func_02030DA8(void *taskSys, void *callback, void *work, int priority);
extern void  func_02021F64(void *src, void *dst, u16 count, int fadeLevel, u16 fadeColor);
extern void  func_02082A60(const void *src, void *dst, u32 size);
extern void MIi_CpuCopy16(const void *src, void *dest, u32 size);
extern void func_02064CBC(McssAnimCtrl *ctrl);
extern void *func_02049FBC(u32 arcId, u32 member, u32 flag, void *out, u32 heap);
extern void *func_0204A03C(u32 arcId, u32 member, u32 flag, void *out, u32 heap);
extern void *func_0204A0BC(u32 arcId, u32 member, u32 flag, void *out, u32 heap);
extern void *func_0204A13C(u32 arcId, u32 member, u32 flag, void *out, u32 heap);
extern void *func_02049DB4(u32 arcId, u32 member, u32 flag, McssTransTask *out, u16 heap);
extern void func_02063790(u32 *vramAddr);
extern void *func_02049FFC(void *arcHandle, u32 member, u32 flag, void *out, u16 heap);
extern void *func_0204A07C(void *arcHandle, u32 member, u32 flag, void *out, u16 heap);
extern void *func_0204A0FC(void *arcHandle, u32 member, u32 flag, void *out, u16 heap);
extern void *func_0204A17C(void *arcHandle, u32 member, u32 flag, void *out, u16 heap);
extern void *func_02049250(void *arcHandle, u32 member, u32 heap);
extern void *func_02049DF4(void *arcHandle, u32 member, u32 flag, McssTransTask *out, u16 heap);
extern void *func_02049F78(void *arcHandle, u32 member, McssPlttData **out, u32 heap);
extern void func_02063A54(McssTexData *tex, u32 dst, int mode, McssTexImage *out);
extern void func_02063E54(McssPlttData *pltt, u32 dst, int mode, McssPlttProxy *out);
extern int func_020648B4(void *multiCellBank, int kind);
extern void func_02064754(McssAnimCtrl *ctrl, void *animWork, void *cellAnimBank, void *cellBank, void *multiCellBank, int kind);
extern double _s32_to_double(s32 v);
extern double func_0209AB80(double base, double exponent);
extern s32 _d2s(double d);
extern int func_0202D060(void);
extern s32 func_0202D09C(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);
extern s32 func_0202D0D4(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);
extern s32 func_0202D110(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);
extern s32 func_0202D144(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);
extern s32 func_0202D178(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);
extern s32 func_0202D1AC(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);
extern s32 func_0202D1E0(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);
extern u32 func_0202D5CC(u32 a);
extern u32 func_0202D5F8(u32 id, u32 flags);
extern u32 func_0202D61C(u32 id, u32 flags);
extern u32 func_0202D640(u32 id, u32 flags);
extern u32 func_0202D664(u32 id, u32 flags);
extern u32 func_0202D688(u32 id, u32 flags);
extern u32 func_0202D6AC(u32 id, u32 flags);
extern u32 func_0202D6D0(u32 id, u32 flags);
void *func_02014910(void *anime, int slot, int config, int target);
void func_0201493C(u32 zoneId, u32 hour, u32 minute, u32 lightTableId, u32 season, u16 *outColors, u16 heapId);
u16 func_02014A10(u32 index);
void *func_02014A20(u32 archive, u32 member, u32 *countOut, u32 heap);
void func_02014A80(u8 *table, u32 count, s32 time, u32 season, u16 *out);
McssSys *func_02014B08(u32 maxCount, u32 heapId);
void func_02014BA8(McssSys *sys);
void func_02014C08(McssSys *sys);
void sub_02014CB8(McssSys *sys, u32 arcId);
void sub_02014CD4(McssSys *sys);
void func_02014CEC(McssSys *sys, void *taskSys);
void sub_02014CF0(McssSys *sys, McssLoadHook hook, u32 hookWork);
void sub_02014CF8(McssSys *sys, McssWork *work, const McssAddWork *addWork);
void func_02014D2C(McssSys *sys);
void func_020155A0(McssSys *sys, McssWork *work, fx32 x, fx32 y, fx32 width, fx32 height, fx32 s, fx32 t, McssPose *pose, u16 *frameIndex, McssPlttProxy *shadowPltt, int cellId, int ortho, u32 *depth, u8 flip);
McssWork *func_020159C8(McssSys *sys, fx32 x, fx32 y, fx32 z, const McssAddWork *addWork);
void sub_02015BA4(McssSys *sys, McssWork *work);
void sub_02015BF0(McssSys *sys);
void sub_02015C00(McssSys *sys);
void sub_02015C0C(McssWork *work);
void sub_02015C1C(McssWork *work);
void func_02015C30(McssWork *work, u32 *out);
void func_02015C48(McssWork *work, u32 *src);
void func_02015C60(McssWork *work, u32 *out);
void func_02015C78(McssWork *work, u32 *src);
void func_02015C94(McssWork *work, u32 *out);
void func_02015CAC(McssWork *work, u32 *src);
void func_02015CC4(McssWork *work, u32 *out);
void func_02015CDC(McssWork *work, u32 *src);
void func_02015CF8(McssWork *work, u32 *out);
void func_02015D14(McssWork *work, u32 *src);
void func_02015D30(McssWork *work, u32 *src);
void func_02015D4C(McssWork *work, u32 *out);
void func_02015D64(McssWork *work, u32 *src);
void func_02015D80(McssWork *work, u16 rotX);
void func_02015D88(McssWork *work, u16 rotZ);
void func_02015D94(McssWork *work, int *src);
void func_02015DB0(McssWork *work);
void func_02015DC0(McssWork *work);
void func_02015DD4(McssWork *work);
int func_02015DF8(McssWork *work);
void func_02015E04(McssWork *work);
void func_02015E28(McssWork *work);
void func_02015E4C(McssWork *work);
void func_02015E70(McssWork *work);
int func_02015E94(McssWork *work);
void func_02015EA0(McssWork *work);
void func_02015EB0(McssWork *work);
void func_02015EC4(McssWork *work);
void *func_02015EE8(McssWork *work);
u16 func_02015EEC(McssWork *work);
u8 func_02015EF4(McssWork *work);
u8 func_02015EFC(McssWork *work, u8 i);
u16 func_02015F04(McssWork *work);
u16 func_02015F0C(McssWork *work);
s16 func_02015F14(McssWork *work);
s16 func_02015F1C(McssWork *work);
u8 func_02015F24(McssWork *work);
void sub_02015F2C(McssWork *work, u32 callback, u32 callbackWork);
void func_02015F40(McssWork *work, unsigned flags, void *callback);
void func_02015F50(McssWork *work, u32 start, u32 end, s32 wait, u32 color);
u8 func_02015FAC(McssWork *work);
void func_02015FBC(McssWork *work, int alpha);
void func_02015FD4(McssWork *work, int alpha);
void func_02015FF0(McssWork *work, int flag);
int func_0201600C(McssWork *work);
void func_02016020(McssSys *sys, u32 adrs);
void func_02016024(McssSys *sys, unsigned int adrs);
void sub_02016028(McssWork *work, u32 animeIndex);
u8 func_02016068(McssWork *work);
void sub_02016078(McssSys *sys, McssWork *work, int mosaic);
void func_020160C0(McssSys *sys, unsigned int scale);
void func_020160C4(McssWork *work, int speed);
u16 func_020160CC(McssWork *work);
void func_020160D4(McssSys *sys, McssWork *work, u16 fadeLevel, int fadeColor);
void func_0201624C(McssSys *sys, McssWork *work);
void sub_02016374(McssWork *work);
void sub_02016380(McssWork *work);
void func_02016394(McssWork *work, int flag);
void func_020163B0(McssSys *sys, int depthStep);
void func_020163B4(McssSys *sys, int flag);
void func_020163C4(McssSys *sys, u32 index, const McssAddWork *addWork);
void func_02016630(McssSys *sys, u32 index, const McssAddWork *addWork);
void func_02016880(void *taskHandle, McssTransTask *task);
void func_0201691C(void *taskHandle, McssTransTask *task);
void func_02016984(McssWork *work, int kind);
void sub_020169D4(void);
void func_020169E8(McssSys *sys, McssWork *work);
void sub_02016BA0(McssWork *work);
void sub_02016C0C(void *taskHandle);
void func_02016C38(void *taskHandle);
void func_02016C60(McssWork *work, McssTransTask *task);
void func_02016FC8(const VecFx32 *v, const MtxFx44 *mtx, VecFx32 *dst, s32 *w);
void func_02017100(void *pp, McssAddWork *out, u32 direction);
void func_02017114(void *pokemon, McssAddWork *out, u32 direction);
void func_02017168(u32 species, u32 form, u32 gender, u32 isShiny, u32 isEgg, McssAddWork *out, u32 direction);
void func_02017214(void *trainerClass, McssAddWork *out, void *trainerGender);
McssWork *func_02017270(McssSys *sys, void *pp, u32 direction, fx32 x, fx32 y, fx32 z);
void func_020172AC(McssSys *sys, u32 personality);
u32 func_020172BC(const McssAddWork *addWork, McssTransTask *task, u32 personality);
void func_020172D8(u8 *pixels, u32 personality);
int func_020173B4(McssWork *work);
void sub_020173C8(McssWork *work);
u32 func_02017E1C(void *p, u32 id, u32 v);
u32 func_02017E88(void *p, u32 id, u32 v);
u32 func_02017EB4(void *p);
void *func_020185F4(void *p);
extern u32 sub_0209E054_Map[];
extern const char sFileMcss[];
extern MtxFx43 g_02148B98;
extern MtxFx44 g_02148B54;
extern VecFx32 g_02148D8C;
extern VecFx32 g_02148D98;
extern VecFx32 g_02148DA4;
extern s16 FX_SinCosTable_[];
extern const VecFx32 d_0209E090;
extern const VecFx32 d_0209E09C;
extern const u8 *sSpindaSpotCoords[4];
/*
 *           Closed at the bottom, not unfiled: no branch anywhere in the image
 *           reaches 0x02014878, so only a `matched` entry could attest it, and
 *           func_02014878 is itself capped at MATCH by two own-pool words
 *           (0x0000005B at 0x02014900, 0x00000083 at 0x02014908 - each occurs
 *           exactly once in arm9, inside its own compared range).  See
 *           docs/notes/pkt_02014808.c.txt.
 */
void *func_02014910(void *anime, int slot, int config, int target)
{
    void *task = func_020122C0(anime, 0, (void *)((int)func_02014878), 0x10);
    u32 *taskWork = func_020124E8(task);

    taskWork[0] = (u32)anime;
    taskWork[1] = slot;
    taskWork[2] = config;
    taskWork[3] = target;
    return task;
}


/*
 * The three-way fallback load of the 0x34-byte time-of-day table (member
 * 0x3e for an explicit id, 0x52 for the id func_02013F2C maps, else 0x3d
 * built through func_0201407C), then func_02014A80 over it and a free.
 *
 * Closed in wave 13 by the declaration, not the body: the seventh
 * parameter is a u16 heap id (the ov094 caller at 0x021F7702 loads it
 * with ldrh), written `(heap & 0x7fff) | 0x8000` at each of the four
 * uses.  The earlier note (docs/notes/pkt_0201493C.c.txt) read it as the
 * low half of a word through `*(u16 *)((char *)&b0 + 8)` and had to spell
 * the first tag as 0x10000000; with the real parameter type both of its
 * "back-end tie-breaks" (the pooled 0x0FFFFFFF + 1 tag and the late b0
 * reload) disappear.
 */
void func_0201493C(u32 zoneId, u32 hour, u32 minute, u32 lightTableId,
                   u32 season, u16 *outColors, u16 heapId)
{
    u32 count;
    void *table = 0;
    s32 hourSeconds;
    s32 minuteSeconds;

    minuteSeconds = minute * 0x3c;
    hourSeconds = hour * 0xe10;

    if (lightTableId != 0) {
        table = func_02014A20(0x3e, func_02014A10(lightTableId), &count, (u16)((heapId & 0x7fff) | 0x8000));
    }
    if (table == 0) {
        u32 mapped = func_02013F2C((u16)zoneId);
        if (mapped != 0xfffffff)
            table = func_02014A20(0x52, mapped, &count, (u16)((heapId & 0x7fff) | 0x8000));
    }
    if (table == 0) {
        void *zoneLight = func_0201407C((heapId & 0x7fff) | 0x8000, func_02013B38((u16)zoneId), season);
        table = func_02014A20(0x3d, func_020140DC(zoneLight), &count, (u16)((heapId & 0x7fff) | 0x8000));
        func_020140B4((void *)zoneLight);
    }
    func_02014A80(table, count, minuteSeconds + hourSeconds, season, outColors);
    sub_020307B0(table);
}


u16 func_02014A10(u32 i)
{
    return sub_0209E054_Map[i];
}


/*
 * Load a record table out of an archive sub-file: the sub-file's byte size
 * divided by 0x34 is the record count (unsigned divide, `_u32_div_f`), the
 * count is handed back through a3's slot and the block itself is loaded by
 * func_02048F60.  Each 0x34-byte record carries four 6-byte vectors at +0x10
 * (a VecFx16 triple plus a spare halfword) and each is normalized in place
 * before the count is returned.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014A20.c \
 *       --func func_02014A20 --addr 0x02014A20 --cc 1.1p1 --thumb
 */
void *func_02014A20(u32 archive, u32 member, u32 *countOut, u32 heap)
{
    u32 recordCount;
    u32 recordIdx;
    u8 *dir;
    u8 *table;
    int dirIdx;

    recordCount = func_020490A8(archive, member) / 0x34;
    *countOut = recordCount;
    table = func_02048F60(archive, member, heap);
    for (recordIdx = 0; recordIdx < recordCount; recordIdx++) {
        dir = table + recordIdx * 0x34 + 0x10;
        for (dirIdx = 0; dirIdx < 4; dirIdx++) {
            VEC_Fx16Normalize(dir + dirIdx * 6, dir + dirIdx * 6);
        }
    }
    return table;
}


/*
 * Scans the 0x34-byte-stride table at a0 for the element whose 3600*hour +
 * 60*minute value first climbs past a2 while the best so far is still at or
 * below it, then returns that element's eight halfword fields through the
 * caller's buffer (the four at +8 and the four at +0x28).
 *
 * Shape notes:
 *  - the index runs from 0 and the loop is entered only when a1 != 0, so the
 *    counter's first comparison sits at the bottom (`cmp r4, a1 / blo`) and
 *    the guard at the top is a bare `adds r0, r1, #0 / beq`);
 *  - the element's +2 field is signed (`ldrsh` with a register offset,
 *    docs/idioms/ldrsh-register-offset-is-signedness.md), which is why both
 *    comparisons on the running value are `bgt`;
 *  - `i % a1` is one call to the unsigned divmod helper with the remainder
 *    read out of r1, so the source must stay a modulo expression and not a
 *    hand-rolled subtraction loop;
 *  - the two products are two statements (`v = 0xE10 * ...; v += ...;`).
 *    Written as one expression mwcc evaluates the s16 arm first and the
 *    15-byte window at +0x2C comes out in the other order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014A80.c \
 *       --func func_02014A80 --addr 0x02014A80 --cc 1.1p1 --thumb
 */
void func_02014A80(u8 *table, u32 count, s32 time, u32 season, u16 *out)
{
    u32 i;
    s32 prevTime;
    s32 entryTime;
    u32 chosen;
    struct LightTableEntry *e;

    prevTime = 0;
    i = 0;
    if (count != 0) {
        do {
            e = (struct LightTableEntry *)(table + i * 0x34);
            entryTime = 0xE10 * (s32)func_02011400(season, e->hourKey);
            entryTime += e->minute * 0x3C;
            if (prevTime <= time && entryTime > time) {
                break;
            }
            prevTime = entryTime;
            i++;
        } while (i < count);
    }

    chosen = i % count;
    e = (struct LightTableEntry *)(table + chosen * 0x34);
    out[0] = e->colorA[0];
    out[1] = e->colorA[1];
    out[2] = e->colorA[2];
    out[3] = e->colorA[3];
    out[4] = e->colorB[0];
    out[5] = e->colorB[1];
    out[6] = e->colorB[2];
    out[7] = e->colorB[3];
}


McssSys *func_02014B08(u32 maxCount, u32 heapId)
{
    McssSys *sys;
    McssTransTask *task;
    u32 subHeapId;

    sys = func_02030734(heapId, 0x4c, 1, sFileMcss, 0x78);
    sys->maxCount = maxCount;
    sys->heapId = heapId;
    sys->globalScale = 0x1000;
    sys->works = func_02030734(heapId, maxCount * 4, 1, sFileMcss, 0x7f);
    sys->texTransAdrs = 9 << 14;
    sys->plttTransAdrs = 0x1000;
    func_020637D4((u32 *)&sys->shadowPltt);
    subHeapId = (heapId & 0x7fff) | 0x8000;
    task = func_02030734((u32)((void *)(u16)subHeapId), 0x2c, 1, sFileMcss, 0x8e);
    task->sys = sys;
    task->plttProxyOut = &sys->shadowPltt;
    task->plttDest = 0x1100;
    task->plttBuf = func_02049F34(0xb, 0x58, &task->plttData, (u16)subHeapId);
    sys->shadowPlttTask = func_020056A0((void *)func_02016880, task, 0);
    return sys;
}


/*
 * Tear-down of a "list of arrays" record: close the open sub-object at +0xC
 * (three frees through the handle returned by func_02030EE8, then the handle
 * itself), then walk the +0x14 array of +0x10 entries and release each live
 * one through func_02015BA4, finally the array and the record itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014BA8.c \
 *       --func func_02014BA8 --addr 0x02014BA8 --cc 1.1p1 --thumb
 */
void func_02014BA8(McssSys *sys)
{
    int i;

    func_02014CD4(sys);
    if (sys->shadowPlttTask != 0) {
        McssTransTask *task = func_02030EE8(sys->shadowPlttTask);

        func_020307B0(task->plttData->data);
        func_020307B0(task->plttData);
        func_020307B0(task);
        func_02030EAC(sys->shadowPlttTask);
        sys->shadowPlttTask = 0;
    }
    for (i = 0; i < sys->maxCount; i++) {
        McssWork **works = sys->works;
        McssWork *work = works[i];

        if (work != 0) {
            func_02015BA4(sys, work);
        }
    }
    func_020307B0(sys->works);
    func_020307B0(sys);
}


/*
 * Closed in the second pass (2026-09-22) from the 7-byte near miss in
 * docs/notes/pkt_02014C08.c.txt.  That note, and the two full permuter
 * runs made on it today (tools/permuter.py --mode hill, 171 single
 * mutations; --mode anneal, 2000 compiles) could not move the residue by
 * a single byte, which is the tell the brief names: a residue nothing in
 * the body reaches lives in the DECLARATIONS.
 *
 * THE LEVER IS func_02016374's ARITY.  The original leaves the slot
 * pointer live in r0 through the third bit test:
 *
 *     02014C7C  ldr r0, [r5, #0x14]     ; the slot array
 *     02014C7E  ldr r1, [sp, #4]        ; the offset constant 0x144
 *     02014C80  ldr r0, [r0, r4]        ; the slot -- STAYS in r0
 *     02014C82  ldr r1, [r0, r1]        ; the flag word into r1
 *     ...
 *     02014C8C  bl  #0x2016374          ; called with r0 already set
 *
 * Declared `void func_02016374(void)` the compiler has no reason to keep
 * the slot in r0, puts the flag word there instead and the six
 * instructions at +0x0076..+0x0080 come out with r0 and r1 swapped, the
 * whole 7-byte residue.  Declared `func_02016374(char *w)` and CALLED
 * with the slot, the allocation the image shows is the only legal one and
 * every byte closes.  This confirms the prototype
 * docs/families/mcss.h already carried (`void func_02016374(struct
 * McssWork *work)`), which the note had not applied at the call site.
 *
 * The 0x020169E8 site resolves through sole-ref/code (and, since
 * src/matched/func_020169E8.c was filed in the same pass, through
 * `matched` as well).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02014C08.c \
 *       --func func_02014C08 --addr 0x02014C08 --cc 1.1p1 --thumb
 */
void func_02014C08(McssSys *sys)
{
    int i;

    for (i = 0; i < sys->maxCount; i++) {
        if (sys->works[i] == 0)
            continue;
        if (sys->works[i]->flags.bits.anmStopFlag == 0)
            func_020649D4(&sys->works[i]->animCtrl, sys->works[i]->animeSpeed);
        if (sys->works[i]->flags.bits.paletteFadeFlag != 0)
            func_020169E8(sys, sys->works[i]);
        if (sys->works[i]->requestFlags.bits.stopAtStart == 1) {
            func_02016374(sys->works[i]);
            func_020649D4(&sys->works[i]->animCtrl, 0);
            sys->works[i]->requestFlags.raw &= ~1u;
        }
    }
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: an acquire/release pair on the same object. sub_02014CB8 only
 * acts the first time (its own field at +0 is the guard); it records the
 * argument at +4 and installs whatever func_020490F4 returns at +0.
 * sub_02014CD4 is the release: if +0 is set it tears it down and clears
 * both fields.
 *
 * ENV_SetResourceSet_2 is not the same call site as
 * src/matched/unit_02014444.c's ENV_SetResourceSet: `layout/symbols_sdk.txt`
 * recovers three separate addresses for that SDK name (0x020307B0,
 * 0x02049238, 0x0204B084), one per statically linked object that pulled the
 * small library routine in, and this file only ever reaches the second one.
 * The two extern declarations therefore differ (three registers forwarded
 * there, one used here), which is a property of each call site, not a
 * disagreement about the routine.
 *
 * The one detail that pinned the source: the field at +0x40 is read with a
 * plain `ldr` (word reach, +124) and truncated to u16 afterwards rather than
 * loaded with `ldrh` (reach +62) directly, which only happens when the field
 * itself is declared u32 and truncated at the call, matching
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md's family of reach-driven
 * tells. Declaring it u16 outright produces an extra `adds` to reach the
 * offset and is 4 bytes wrong.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014CB8.c \
 *       --addr 0x02014CB8 --thumb
 */
void sub_02014CB8(McssSys *sys, u32 arcId)
{
    if (sys->arcHandle == 0) {
        sys->arcId = arcId;
        sys->arcHandle = func_020490F4(arcId, (u16)sys->heapId);
    }
}


void sub_02014CD4(McssSys *sys)
{
    if (sys->arcHandle != 0) {
        ENV_SetResourceSet_2(sys->arcHandle);
        sys->arcId = 0;
        sys->arcHandle = 0;
    }
}


void func_02014CEC(McssSys *sys, void *taskSys)
{
    sys->taskSys = taskSys;
}


/*
 * Two consecutive word stores through the object pointer - a plain field
 * pair setter with no prologue, so no label, attested by the pool word
 * 0x02014CF1.  The stores are in source order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02014CF0.c \
 *       --func sub_02014CF0 --addr 0x02014CF0 --cc 1.1p1 --thumb
 */
void sub_02014CF0(McssSys *sys, McssLoadHook hook, u32 hookWork)
{
    sys->loadHook = hook;
    sys->loadHookWork = hookWork;
}


/*
 * Prepares b (a validation call, func_02016BA0), copies a 0x24-byte record
 * from c into b's field at +0x150 (the inlined ldm/stm loop plus one trailing
 * word is docs/idioms/aggregate-assignment-is-ldm-stm.md), then forwards a,
 * a pointer field of b at +0x148, and the original record pointer c to
 * func_020163C4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02014CF8.c \
 *       --func sub_02014CF8 --addr 0x02014CF8 --thumb --cc 1.1p1
 */
void sub_02014CF8(McssSys *sys, McssWork *work, const McssAddWork *addWork)
{
    func_02016BA0(work);
    work->addWork = *addWork;
    func_020163C4(sys, work->index, addWork);
}


static inline fx32 FX_MUL(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}


static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_TRANS = (u32)x;
    REG_MTX_TRANS = (u32)y;
    REG_MTX_TRANS = (u32)z;
}


static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_SCALE = (u32)x;
    REG_MTX_SCALE = (u32)y;
    REG_MTX_SCALE = (u32)z;
}


static inline void G3_LookAt(const VecFx32 *camPos, const VecFx32 *camUp,
                             const VecFx32 *target, MtxFx43 *mtx)
{
    G3i_LookAt_(camPos, camUp, target, 1, mtx);
}


static inline void G3_TexImageParam(GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    REG_TEXIMAGE_PARAM = (u32)((addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}


static inline void G3_StoreMtx(int num) { REG_MTX_STORE = (u32)num; }


/* func_02014D2C is one function over 0x02014D2C..0x020155A0.  The labels
 * func_02014D90 (0x02014D90) and func_02015590 (0x02015590) are not
 * function starts: they are the targets of two long-branch bl pairs inside
 * it (the shared epilogue and the outer loop head). */
/*
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_02014D2C.c \
 *       --addr 0x02014D2C --thumb
 *
 * The mcss.c frame walker, ONE function over 0x02014D2C..0x020155A0
 * (2164 bytes).  0x02014D90 and 0x02015590 are not function starts: they
 * are the targets of two bl instructions the compiler emits as long
 * branches (0x02014D74 to the shared epilogue, 0x0201558C back to the
 * outer loop head), both beyond Thumb b reach.  They are not listed on the
 * function line (alternate labels of func_02014D2C, no start of their own).
 *
 * The lever that closed it (wave 15, from 43 bytes out): the texture
 * parameter write is the SDK inline G3_TexImageParam with the SDK's ENUM
 * parameter types (GXTexFmt, GXTexGen, GXTexSizeS/T, GXTexRepeat,
 * GXTexFlip, GXTexPlttColor0).  With int parameters the inline is 2168
 * bytes (540 out); with a hand-written or-chain 43 out (the STORE constant
 * 0x1e CSE'd with 0x1e << 15).  Enum parameters are materialised as
 * temporaries before the body, which is what keeps 0x1e rematerialised.
 * See docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 * History: docs/notes/pkt_02014D2C_boundary.c.txt.
 */
void func_02014D2C(McssSys *sys)
{
    McssPose pose;
    McssPose part;
    VecFx32 pos;
    MtxFx44 billboardMtx;
    MtxFx43 invView;
    MtxFx33 invViewRot;
    u32 depth;
    s32 projW;
    McssWork *work;
    McssAnimCtrl *animCtrl;
    int cellIdx;
    int sinIdx;
    u16 angle;
    fx32 transX, transY;
    fx32 scaleX, scaleY;
    McssTexImage *texImage;
    int workIdx;
    McssCellNode **nodes;
    u8 flip;
    fx32 cosRot;
    fx32 sinRot;
    int billboard;

    func_0206DB80();
    REG_MTX_PUSH = 0;
    REG_MTX_MODE = 0;
    REG_MTX_STORE = 0;
    REG_MTX_MODE = 3;
    REG_MTX_IDENTITY = 0;
    REG_MTX_MODE = 2;
    MTX_Inverse43(&g_02148B98, &invView);
    MI_Copy36B(&invView, &invViewRot);
    MTX_Copy33To44_(&invViewRot, &billboardMtx);

    workIdx = 0;
    if (sys->maxCount > 0) {
    do {
        if (sys->works[workIdx] == 0 || sys->works[workIdx]->flags.bits.vanishFlag != 0 || sys->works[workIdx]->flags.bits.loaded != 1) {
            continue;
        }
        billboard = 0;
        depth = 0;
        if (sys->flags.bits.orthoMode) {
            billboard = sys->works[workIdx]->flags.bits.orthoBillboardFlag;
        }
        work = sys->works[workIdx];
        texImage = &work->texImage;
        if (billboard == 0) {
            G3_LookAt(&g_02148D8C, &g_02148D98, &g_02148DA4, 0);
        } else {
            VecFx32 camPos = { 0, 0, 0 };
            VecFx32 camUp = d_0209E090;
            VecFx32 camTgt = d_0209E09C;
            G3_LookAt(&camPos, &camUp, &camTgt, 0);
        }
        animCtrl = &work->animCtrl;
        nodes = &work->cellCtrl.nodes;
        switch ((u16)animCtrl->seq->kind) {
        case 0:
            pose.index = *(u16 *)animCtrl->cur->content;
            pose.rot = 0;
            pose.sx = 0x1000;
            pose.sy = 0x1000;
            pose.ofsX = 0;
            pose.ofsY = 0;
            break;
        case 1:
            pose = *(McssPose *)animCtrl->cur->content;
            break;
        case 2: {
            McssPoseOfs *poseOfs = (McssPoseOfs *)animCtrl->cur->content;
            pose.index = poseOfs->index;
            pose.rot = 0;
            pose.sx = 0x1000;
            pose.sy = 0x1000;
            pose.ofsX = poseOfs->ofsX;
            pose.ofsY = poseOfs->ofsY;
            break;
        }
        }
        pos.x = work->position.x + work->ofsPosition.x;
        pos.y = work->position.y + work->ofsPosition.y;
        pos.z = work->position.z + work->ofsPosition.z;
        if (billboard == 0) {
            transX = FX_MUL(pose.ofsX << 8, sys->globalScale);
            transY = FX_MUL(-pose.ofsY << 8, sys->globalScale);
        } else {
            MtxFx44 viewMtx;
            scaleX = FX_MUL(work->scale.x, work->shadowScale.x);
            scaleY = FX_MUL(work->scale.y, work->shadowScale.y);
            MTX_Copy43To44_(&g_02148B98, &viewMtx);
            MTX_Concat44(&viewMtx, &g_02148B54, &viewMtx);
            func_02016FC8(&pos, &viewMtx, &pos, &projW);
            pos.x = FX_MUL(sub_0207C768(pos.x, projW), 0x80000);
            pos.y = FX_MUL(sub_0207C768(pos.y, projW), 0x60000);
            pos.z = -pos.z;
            transX = FX_F32_TO_FX32(pose.ofsX);
            transY = FX_F32_TO_FX32(-pose.ofsY);
            transX = FX_MUL(transX, scaleX / 16);
            transY = FX_MUL(transY, scaleY / 16);
        }
        G3_Translate(pos.x, pos.y, pos.z);
        if (billboard == 0) {
            G3_MultMtx44(&billboardMtx);
        }
        angle = pose.rot + (work->rotate.z >> 12);
        G3_Translate(transX, transY, 0);
        flip = 0;
        sinIdx = angle >> 4;
        cosRot = FX_SinCosTable_[sinIdx * 2 + 1];
        sinRot = -FX_SinCosTable_[sinIdx * 2];
        G3_RotZ(sinRot, cosRot);
        G3_Scale(FX_MUL(FX_MUL(pose.sx, work->scale.x), work->shadowScale.x),
                 FX_MUL(FX_MUL(pose.sy, work->scale.y), work->shadowScale.y), 0x1000);
        if (work->scale.x < 0) {
            flip++;
        }
        G3_StoreMtx(29);
        G3_LookAt(&g_02148D8C, &g_02148D98, &g_02148DA4, 0);
        G3_Translate(work->position.x + work->ofsPosition.x + work->shadowOffset.x, work->position.y + work->shadowOffset.y,
                     work->position.z + work->ofsPosition.z + work->shadowOffset.z);
        sinIdx = work->shadowRotX >> 4;
        G3_RotX(FX_SinCosTable_[sinIdx * 2], FX_SinCosTable_[sinIdx * 2 + 1]);
        G3_Translate(FX_MUL(FX_MUL(pose.ofsX << 8, sys->globalScale), work->ofsScale.x),
                     FX_MUL(FX_MUL(-pose.ofsY << 8, sys->globalScale), work->ofsScale.y), 0);
        sinIdx = work->shadowRotZ >> 4;
        G3_RotZ(-FX_SinCosTable_[sinIdx * 2], FX_SinCosTable_[sinIdx * 2 + 1]);
        G3_RotZ(sinRot, cosRot);
        G3_Scale(FX_MUL(FX_MUL(FX_MUL(pose.sx, work->ofsScale.x), work->drawScale.x), work->shadowScale.x),
                 FX_MUL(FX_MUL(FX_MUL(pose.sy, work->ofsScale.y), work->drawScale.y), work->shadowScale.y),
                 0x1000);
        G3_StoreMtx(30);
        sub_020169D4();
        G3_TexImageParam(texImage->fmt, GX_TEXGEN_TEXCOORD, texImage->sizeS, texImage->sizeT, GX_TEXREPEAT_ST, GX_TEXFLIP_ST, texImage->pltt0, texImage->vramAddr[0]);
        for (cellIdx = 0; cellIdx < work->cellCtrl.anim->frames[pose.index].count; cellIdx++) {
            McssCellNode *node;
            McssCellRec *rec;
            int cellId;
            if (work->flags.bits.alpha != 0x1f || work->flags.bits.mepachiDrawLast) {
                cellId = work->cellCtrl.anim->frames[pose.index].count - 1 - cellIdx;
            } else {
                cellId = cellIdx;
            }
            node = &(*nodes)[(work->cellCtrl.anim->frames[pose.index].cells[cellId].nodeInfo & 0xff00) >> 8];
            switch ((u16)node->ctrl.seq->kind) {
            case 0:
                part.index = *(u16 *)node->ctrl.cur->content;
                part.rot = 0;
                part.sx = 0x1000;
                part.sy = 0x1000;
                part.ofsX = 0;
                part.ofsY = 0;
                break;
            case 1:
                part = *(McssPose *)node->ctrl.cur->content;
                break;
            case 2: {
                McssPoseOfs *poseOfs = (McssPoseOfs *)node->ctrl.cur->content;
                part.index = poseOfs->index;
                part.rot = 0;
                part.sx = 0x1000;
                part.sy = 0x1000;
                part.ofsX = poseOfs->ofsX;
                part.ofsY = poseOfs->ofsY;
                break;
            }
            }
            rec = &work->cellHeader->cells[part.index];
            if (rec->eye.w != 0 && work->flags.bits.mepachiDrawLast == 0) {
                if (work->flags.bits.mepachiFlag) {
                    func_020155A0(sys, work, rec->eye.x, rec->eye.y, rec->eye.w, rec->eye.h, rec->eye.s, rec->eye.t + rec->eye.h, &part, &pose.index, &sys->shadowPltt, cellId, billboard, &depth, flip);
                } else {
                    func_020155A0(sys, work, rec->eye.x, rec->eye.y, rec->eye.w, rec->eye.h, rec->eye.s, rec->eye.t, &part, &pose.index, &sys->shadowPltt, cellId, billboard, &depth, flip);
                }
            }
            func_020155A0(sys, work, rec->body.x, rec->body.y, rec->body.w, rec->body.h, rec->body.s, rec->body.t, &part, &pose.index, &sys->shadowPltt, cellId, billboard, &depth, flip);
            if (rec->eye.w != 0 && work->flags.bits.mepachiDrawLast == 1) {
                if (work->flags.bits.mepachiFlag) {
                    func_020155A0(sys, work, rec->eye.x, rec->eye.y, rec->eye.w, rec->eye.h, rec->eye.s, rec->eye.t + rec->eye.h, &part, &pose.index, &sys->shadowPltt, cellId, billboard, &depth, flip);
                } else {
                    func_020155A0(sys, work, rec->eye.x, rec->eye.y, rec->eye.w, rec->eye.h, rec->eye.s, rec->eye.t, &part, &pose.index, &sys->shadowPltt, cellId, billboard, &depth, flip);
                }
            }
        }
    } while (++workIdx < sys->maxCount);
    }
    REG_MTX_POP = 1;
}


/* fx32 texture coordinate to the 12.4 halfword TEXCOORD wants */
#define ST(x) ((u32)(u16)(s16)((x) >> 8))


/*
 * mcss.c's per-cell quad drawer (wave 11, third lane on the family).  Its
 * three callers are the 0x02014D2C..0x020155A0 frame walker (0x020154D0,
 * 0x02015506, 0x02015562), which pass a cell record's six words as
 * x, y, width, height, s, t and a stack record as `pose`.  The body is a
 * straight run of G3 register writes: optional projection, texture palette
 * base, polygon attributes, translate / rotate / scale, one textured quad,
 * then (when the slot is not hidden and alpha is non-zero) the same quad
 * again with polygon id 1, and finally a depth step on *z.
 *
 * FOUR THINGS THE BYTES SETTLED, in the order they were found:
 *  1. FX_SinCosTable_ is declared WITHOUT const.  The second G3_RotZ
 *     re-reads pose->rot and both table entries after the call; const lets
 *     mwcc keep sin/cos across the call in two extra frame slots (0x58
 *     frame against the original's 0x50).  The index is recomputed too.
 *  2. G3_Translate / G3_Scale are the SDK inline functions, not three
 *     plain stores: the original loads pose->sx AND pose->sy (and *z)
 *     before the first register store, which only argument evaluation
 *     produces (58 -> 31 bytes).
 *  3. The second G3_TexPlttBase is written as the SDK's inline expression
 *     `addr >> (4 - (fmt == GX_TEXFMT_PLTT4))`; its 0/1 is a compiler
 *     temporary homed at sp+0x20, the LOWEST slot, which is how the slot
 *     order told a temporary from a declared local.  The alpha value goes
 *     through a block-local `a`, and polyId is declared last: slot order
 *     here follows creation order, not declaration order alone.
 *  4. The depth pointer is `u32 *`, not `fx32 *`.  With a signed pointee
 *     the two +-0x100 tails pick the other register for the 0x140 field
 *     offset the original re-uses to build 0x100 (`subs r0, #0x40`); 22
 *     bytes over four tails that 547 hill and 2000 anneal permuter compiles
 *     could not move, closed by the declaration alone (wave-10 lesson).
 */
void func_020155A0(McssSys *sys, McssWork *work, fx32 x, fx32 y,
                   fx32 width, fx32 height, fx32 s, fx32 t,
                   McssPose *pose, u16 *frameIndex, McssPlttProxy *shadowPltt, int cellId,
                   int ortho, u32 *depth, u8 flip)
{
    u32 alpha;
    fx32 transX, transY;
    u32 texCoord0, texCoord1, texCoord2, texCoord3;
    u32 sLeft, tTop, sRight, tBottom;
    int sinIdx;
    int polyId;

    {
        u32 shadowAlpha = work->flags.bits.shadowAlpha;
        if (shadowAlpha == 0x20) {
            shadowAlpha = work->flags.bits.alpha >> 1;
        }
        alpha = (u8)shadowAlpha;
    }
    if (work->flags.bits.alpha == 0x1f || work->flags.bits.shadowForceDraw) {
        polyId = 0;
    } else {
        polyId = cellId;
        if (polyId > 0x3f) {
            polyId = 0x3f;
        }
    }

    if (ortho != 0) {
        G3i_FrustumW_(6 << 16, -6 << 16, -8 << 16, 8 << 16, 0x1000,
                      (sys->flags.bits.nearDepthRange ? 0x200 : 0x400) << 12, 0x1000, 1, 0);
        REG_MTX_MODE = 2;
    }
    REG_MTX_RESTORE = 0x1d;

    REG_TEXPLTT_BASE = work->plttProxy.vramAddr[0] >> (4 - (work->plttProxy.fmt == 2));
    REG_POLYGON_ATTR = (work->flags.bits.alpha << 16) | (0xc0 | (polyId << 24));

    transX = (work->cellCtrl.anim->frames[*frameIndex].cells[cellId].ofsX + pose->ofsX) << 8;
    transY = -(work->cellCtrl.anim->frames[*frameIndex].cells[cellId].ofsY + pose->ofsY) << 8;
    G3_Translate(transX, transY, *depth);
    sinIdx = pose->rot >> 4;
    G3_RotZ(-FX_SinCosTable_[sinIdx * 2], FX_SinCosTable_[sinIdx * 2 + 1]);

    if (flip == 0) {
        G3_Scale(pose->sx, pose->sy, 0x1000);
        G3_Translate(x, y, 0);
        G3_Scale(width, height, 0x1000);
    } else if (flip & 1) {
        G3_Scale(-pose->sx, pose->sy, 0x1000);
        G3_Translate(-x, y, 0);
        G3_Scale(width, height, 0x1000);
        G3_Translate(-0x100, 0, 0);
        s = 0x200000 - s - width;
    }

    REG_BEGIN_VTXS = 1;
    tTop = ST(t) << 16;
    sLeft = ST(s);
    texCoord0 = sLeft | tTop;
    REG_TEXCOORD = texCoord0;
    REG_VTX_16 = 0;
    REG_VTX_16 = 0;
    tBottom = ST(t + height) << 16;
    texCoord1 = sLeft | tBottom;
    REG_TEXCOORD = texCoord1;
    REG_VTX_16 = 0xFF000000;
    REG_VTX_16 = 0;
    sRight = ST(s + width);
    texCoord2 = tBottom | sRight;
    REG_TEXCOORD = texCoord2;
    REG_VTX_16 = 0xFF000100;
    REG_VTX_16 = 0;
    texCoord3 = sRight | tTop;
    REG_TEXCOORD = texCoord3;
    REG_VTX_16 = 0x100;
    REG_VTX_16 = 0;
    REG_END_VTXS = 0;

    REG_MTX_MODE = 0;
    REG_MTX_RESTORE = 0;
    REG_MTX_MODE = 2;
    REG_MTX_RESTORE = 0x1e;

    if (!work->flags.bits.shadowVanishFlag && alpha != 0) {
        REG_TEXPLTT_BASE = shadowPltt->vramAddr[0] >> (4 - (shadowPltt->fmt == 2));
        REG_POLYGON_ATTR = (alpha << 16) | 0x010000C0;
        G3_Translate(transX, transY, 0);
        sinIdx = pose->rot >> 4;
        G3_RotZ(-FX_SinCosTable_[sinIdx * 2], FX_SinCosTable_[sinIdx * 2 + 1]);
        G3_Scale(pose->sx, pose->sy, 0x1000);
        G3_Translate(x, y, 0);
        G3_Scale(width, height, 0x1000);
        REG_BEGIN_VTXS = 1;
        REG_TEXCOORD = texCoord0;
        REG_VTX_16 = 0;
        REG_VTX_16 = 0;
        REG_TEXCOORD = texCoord1;
        REG_VTX_16 = 0xFF000000;
        REG_VTX_16 = 0;
        REG_TEXCOORD = texCoord2;
        REG_VTX_16 = 0xFF000100;
        REG_VTX_16 = 0;
        REG_TEXCOORD = texCoord3;
        REG_VTX_16 = 0x100;
        REG_VTX_16 = 0;
        REG_END_VTXS = 0;
    }

    if (ortho == 0) {
        if (sys->depthStep == 0) {
            *depth -= ((work->flags.bits.alpha != 0x1f) | work->flags.bits.mepachiDrawLast) ? -0x100 : 0x100;
        } else {
            *depth -= ((work->flags.bits.alpha != 0x1f) | work->flags.bits.mepachiDrawLast) ? -sys->depthStep : sys->depthStep;
        }
    } else if (sys->flags.bits.nearDepthRange) {
        *depth -= ((work->flags.bits.alpha != 0x1f) | work->flags.bits.mepachiDrawLast) ? -0x100 : 0x100;
    } else {
        *depth -= ((work->flags.bits.alpha != 0x1f) | work->flags.bits.mepachiDrawLast) ? -0x400 : 0x400;
    }
}


/*
 * 476 bytes, one function, 29 field stores and no branches but the loop.
 *
 * "Take the first free slot of the module's array, allocate a 0x188 byte
 * record into it, fill it in and hand it back."  The loop walks
 * sys->works[0 .. sys->maxCount) looking for a NULL entry, and on the first one
 * it allocates, initialises and breaks; the return is sys->works[i] either way,
 * so a full array returns the one-past-the-end element, which is the game's
 * behaviour and not a transcription error.
 *
 * ---------------------------------------------------------------------------
 * THE FILE NAME, AND WHAT IT SETTLES
 * ---------------------------------------------------------------------------
 * The allocator call passes 0x020A72CC and 906, which are __FILE__ and
 * __LINE__.  The bytes at 0x020A72CC spell **mcss.c**, so this function and
 * its neighbours in pkt_02014D90 are that original source file, at line 906.
 * The string is attested the ordinary way, seven literal-pool witnesses
 * elsewhere in the image, so it needed no widening of the `string` class; see
 * docs/idioms/file-string-is-an-abs32-into-the-string-area.md for why it is
 * declared as an extern array rather than written `__FILE__`.  The strings on
 * either side of it in the packed area are "field_status.c" and a run of four
 * pointer words, which is the shape
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md warns about for
 * the *next* file name in that area rather than for this one.
 *
 * ---------------------------------------------------------------------------
 * WHAT COST THE TIME
 * ---------------------------------------------------------------------------
 * **The loop bound is the field, not a local.**  `n = sys->maxCount;` before the
 * loop and `i < n` inside it compiles to the same 476 bytes with `n` in r1
 * instead of r2, which spills the second parameter one instruction later and
 * leaves nine bytes wrong in the prologue and one at the loop's `cmp`.
 * Written `for (i = 0; i < sys->maxCount; i++)` the compiler hoists the load
 * itself, into r2, and the whole function is EXACT.  Nothing in the body reads
 * the field, and the only call inside the loop is on the path that breaks out
 * of it, so the hoist is legal and the original took it.
 *
 * **sizeof is in the source, and it is what pays for the field offsets.**
 * The allocation size arrives as `movs r7, #0x62` / `lsls r7, r7, #2`, which is
 * 0x188, and r7 then stays live for the whole body: every field past the Thumb
 * immediate reach is addressed as `adds r0, r7, #0` / `subs r0, #k` with k the
 * distance back from the end of the record, and the halfword 0xC400 stored at
 * +0x178 is `lsls r2, r7, #7` off the same register.  That only happens if the
 * size the source passes to the allocator is literally `sizeof(McssWork)`
 * and the struct is exactly 0x188 bytes, which makes the declaration
 * self-checking: a struct one word too long or too short changes the constant
 * and every offset derived from it.  The same front end goes on to reuse the
 * constant 0x1F (a bitfield value, parked in `ip`) as the base for the offsets
 * 0x110, 0x114 and 0x118, which is the extreme end of the same behaviour.
 *
 * **Every store reloads the array and the element.**  `sys->works[i]->field = v`
 * appears 29 times and the original reloads `sys->works` and then
 * `sys->works[i]` before each one, because the store it just made could alias
 * either.  Writing the element pointer into a local once, which is what a
 * person would do, removes 28 pairs of loads and is a different function.  The
 * counterpart is docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md:
 * there the qualifier removes the reloads, here its absence is the match.
 *
 * **The 36 byte record at +0x150 is one struct assignment.**  It compiles to a
 * counted `ldm`/`stm` loop of four iterations plus a trailing word, which is
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; declaring it as a
 * byte array instead gives a `ldrb`/`strb` loop of 36 iterations, so the
 * source's type has at least four byte alignment and `u32 w[9]` is what
 * reproduces it.
 *
 * The word at +0x140 is a bitfield container: the three writes are the low
 * eight bits set to 0x1F, the nine bits at 14 set to 0x20 and bit 11 cleared,
 * and then bit 29 set after the struct copy.  Written as masks and shifts over
 * a plain `u32` the compiler materialises each mask from a literal pool; as
 * bitfields it emits the original's `bics`/`orrs` against the small constants
 * and only the two nine-bit masks reach the pool.
 *
 * Nothing here is version specific: every constant is a structure offset, a
 * fixed-point 1.0 (0x1000), a bitfield value or the source line number.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_020159C8.c  *       --func func_020159C8 --addr 0x020159C8 --cc 1.1p1
 */
McssWork *func_020159C8(McssSys *sys, fx32 x, fx32 y, fx32 z, const McssAddWork *addWork)
{
    s32 i;

    for (i = 0; i < sys->maxCount; i++) {
        if (sys->works[i] == 0) {
            sys->works[i] = func_02030734((u16)sys->heapId, sizeof(McssWork), 1,
                                          sFileMcss,
                                          906);
            sys->works[i]->index = i;
            sys->works[i]->heapId = sys->heapId;
            sys->works[i]->position.x = x;
            sys->works[i]->position.y = y;
            sys->works[i]->position.z = z;
            sys->works[i]->scale.x = 0x1000;
            sys->works[i]->scale.y = 0x1000;
            sys->works[i]->scale.z = 0x1000;
            sys->works[i]->ofsPosition.x = 0;
            sys->works[i]->ofsPosition.y = 0;
            sys->works[i]->ofsPosition.z = 0;
            sys->works[i]->shadowScale.x = 0x1000;
            sys->works[i]->shadowScale.y = 0x1000;
            sys->works[i]->shadowScale.z = 0x1000;
            sys->works[i]->flags.bits.alpha = 0x1F;
            sys->works[i]->flags.bits.shadowAlpha = 0x20;
            sys->works[i]->flags.bits.vanishFlag = 0;
            sys->works[i]->shadowRotX = 0xC400;
            sys->works[i]->shadowRotZ = 0;
            sys->works[i]->shadowOffset.x = 0;
            sys->works[i]->shadowOffset.y = 0;
            sys->works[i]->shadowOffset.z = 0xFFFFF000;
            sys->works[i]->drawScale.x = 0x1000;
            sys->works[i]->drawScale.y = 0x1000;
            sys->works[i]->drawScale.z = 0x1000;
            sys->works[i]->addWork = *addWork;
            sys->works[i]->animeSpeed = 0x1000;
            sys->works[i]->flags.bits.orthoBillboardFlag = 1;
            func_020163C4(sys, i, addWork);
            break;
        }
    }
    return sys->works[i];
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02015C1C
 *
 * alias: sub_02015BA4 tears down an object: it calls func_02016BA0(obj), then
 * for each of the three word fields at +0, +4 and +8 that is non-zero it
 * passes that field's *value* (not the object) to a cleanup call
 * (func_02016C0C for +0, func_02016C38 for +4 and +8) and zeroes the field;
 * it then clears a slot this object owns in an array reached through
 * sys->+0x14, indexed by the object's own field at +0x148, and finally
 * hands the object to func_020307B0 through an interworking blx.
 *
 * The four followers are unlabelled leaf accessors on the same class of
 * object, found in the .word run disasm.py left undecoded immediately
 * after sub_02015BA4 (its prologue has no register-saving push that a
 * two-word bit-flag accessor shares); see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md. Two work a
 * flag at +0x2c: sub_02015BF0 clears then re-sets bit 0 (a clear/set pair
 * rather than a plain |=, which is what tells apart the extra bics), and
 * sub_02015C00 only clears it. The other two work a flag at +0x140, too far
 * from the object base for an immediate str, which is why the compiler
 * computes the offset into a register instead of folding it into the
 * instruction: sub_02015C0C sets bit 0x1D (0x20000000) and sub_02015C1C
 * clears it via the pool word 0xDFFFFFFF immediately after it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02015BA4.c \
 *       --addr 0x02015BA4 --thumb
 */
void sub_02015BA4(McssSys *sys, McssWork *work)
{
    u32 index;
    McssWork **works;
    func_02016BA0(work);
    if (work->textureTask != 0) {
        func_02016C0C(work->textureTask);
        work->textureTask = 0;
    }
    if (work->fadeTask != 0) {
        func_02016C38(work->fadeTask);
        work->fadeTask = 0;
    }
    if (work->paletteTask != 0) {
        func_02016C38(work->paletteTask);
        work->paletteTask = 0;
    }
    index = work->index;
    works = sys->works;
    works[index] = 0;
    func_020307B0(work);
}


void sub_02015BF0(McssSys *sys)
{
    sys->flags.raw &= ~1;
    sys->flags.raw |= 1;
}


void sub_02015C00(McssSys *sys)
{
    sys->flags.raw &= ~1;
}


void sub_02015C0C(McssWork *work)
{
    work->flags.raw |= 0x20000000;
}


void sub_02015C1C(McssWork *work)
{
    work->flags.raw &= ~0x20000000;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module (saves nothing, so disasm.py emits
 * it as a run of .word). Copies three words out of the structure at +0xE0.
 * The inverse of func_02015C48; in the ov118 event state machine
 * (0x021D7130) it is the out-direction marshaller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C30(McssWork *work, u32 *out)
{
    out[0] = work->position.x;
    out[1] = work->position.y;
    out[2] = work->position.z;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into the
 * structure at +0xE0. The inverse of func_02015C30; in the ov118 event state
 * machine (0x021D7130) and func_021D6E04 it is the in-direction marshaller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C48(McssWork *work, u32 *src)
{
    work->position.x = src[0];
    work->position.y = src[1];
    work->position.z = src[2];
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x11C. Twin of func_02015C78.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C60(McssWork *work, u32 *out)
{
    out[0] = work->ofsPosition.x;
    out[1] = work->ofsPosition.y;
    out[2] = work->ofsPosition.z;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Copies three words
 * into the structure at +0x11C; same shape as func_02015C48 further
 * back.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C78(McssWork *work, u32 *src)
{
    work->ofsPosition.x = src[0];
    work->ofsPosition.y = src[1];
    work->ofsPosition.z = src[2];
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of the
 * structure at +0xEC. The inverse of func_02015CAC; same shape as
 * func_02015C30 one word-group further along.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C94(McssWork *work, u32 *out)
{
    out[0] = work->scale.x;
    out[1] = work->scale.y;
    out[2] = work->scale.z;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into the
 * structure at +0xEC. The inverse of func_02015C94.
 *
 * Addresses are Black-image addresses.
 */
void func_02015CAC(McssWork *work, u32 *src)
{
    work->scale.x = src[0];
    work->scale.y = src[1];
    work->scale.z = src[2];
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x128.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015CC4(McssWork *work, u32 *out)
{
    out[0] = work->shadowScale.x;
    out[1] = work->shadowScale.y;
    out[2] = work->shadowScale.z;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x128. Inverse of func_02015CC4.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015CDC(McssWork *work, u32 *src)
{
    work->shadowScale.x = src[0];
    work->shadowScale.y = src[1];
    work->shadowScale.z = src[2];
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0xF8.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015CF8(McssWork *work, u32 *out)
{
    out[0] = work->rotate.x;
    out[1] = work->rotate.y;
    out[2] = work->rotate.z;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0xF8. Inverse of func_02015CF8.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D14(McssWork *work, u32 *src)
{
    work->rotate.x = src[0];
    work->rotate.y = src[1];
    work->rotate.z = src[2];
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x104.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D30(McssWork *work, u32 *src)
{
    work->ofsScale.x = src[0];
    work->ofsScale.y = src[1];
    work->ofsScale.z = src[2];
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x110.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D4C(McssWork *work, u32 *out)
{
    out[0] = work->drawScale.x;
    out[1] = work->drawScale.y;
    out[2] = work->drawScale.z;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x110. Inverse of func_02015D4C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D64(McssWork *work, u32 *src)
{
    work->drawScale.x = src[0];
    work->drawScale.y = src[1];
    work->drawScale.z = src[2];
}


/*
 * note: halfword setter at +0x178; called from ov131 func_021D785C (bl at
 *   +0x78 and +0xB6) with the pooled full-width value 0xD555.
 */
void func_02015D80(McssWork *work, u16 rotX)
{
    work->shadowRotX = rotX;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Stores a halfword at +0x17A.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D88(McssWork *work, u16 rotZ)
{
    work->shadowRotZ = rotZ;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x17C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D94(McssWork *work, int *src)
{
    work->shadowOffset.x = src[0];
    work->shadowOffset.y = src[1];
    work->shadowOffset.z = src[2];
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015DB0(McssWork *work)
{
    work->flags.raw |= 0x100u;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Clears bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015DC0(McssWork *work)
{
    work->flags.raw &= ~0x100u;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Toggles bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015DD4(McssWork *work)
{
    work->flags.bits.mepachiFlag ^= 1;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads the two-bit field at bits 9..10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
int func_02015DF8(McssWork *work)
{
    return work->flags.bits.anmStopFlag;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Compound-OR of the 2-bit
 * bitfield at bits 9..10 of the register at +0x140 with 1. The access is
 * non-volatile in the original: mwcc reads the word once and reinserts the
 * field without a reload (a `volatile` spelling forces a second `ldr` and
 * diverges). Pairs with func_02015E4C, which clears bit 9.
 *
 * Addresses are Black-image addresses.
 */
void func_02015E04(McssWork *work)
{
    work->flags.bits.anmStopFlag |= 1;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015E28(McssWork *work)
{
    work->flags.bits.anmStopFlag |= 2;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Compound-AND of the 2-bit
 * bitfield at bits 9..10 of the register at +0x140 with ~1 (clears bit 9).
 * Same non-volatile codegen lever as func_02015E04.
 *
 * Addresses are Black-image addresses.
 */
void func_02015E4C(McssWork *work)
{
    work->flags.bits.anmStopFlag &= ~1u;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Clears bit 10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015E70(McssWork *work)
{
    work->flags.bits.anmStopFlag &= ~2u;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads bit 11 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
int func_02015E94(McssWork *work)
{
    return work->flags.bits.vanishFlag;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 11 (0x800) of the
 * 32-bit register at +0x140. Pairs with func_02015EB0, which clears it.
 *
 * Addresses are Black-image addresses.
 */
void func_02015EA0(McssWork *work)
{
    /* stand-in: volatile keeps the word read-modify-write of the original */
    *(volatile u32 *)&work->flags.raw |= 0x800u;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module (saves nothing, so disasm.py emits
 * it as a run of .word; the live bytes decode as Thumb). Clears bit 11
 * (0x800) of the 32-bit field at +0x140. This is one of the pair
 * func_02015EA0/func_02015EB0 that set and clear the same bit; it is called
 * from the ov118 event state machine at 0x021D7130 and from
 * func_021D6E04, and is an image-wide-only reference target (no func_ label),
 * so matching it supplies the `matched` witness those callers lack.
 *
 * Addresses are Black-image addresses.
 */
void func_02015EB0(McssWork *work)
{
    /* stand-in: volatile keeps the word read-modify-write of the original */
    *(volatile u32 *)&work->flags.raw &= 0xFFFFF7FFu;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Toggles bit 11 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015EC4(McssWork *work)
{
    work->flags.bits.vanishFlag = work->flags.bits.vanishFlag ^ 1;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Returns the address
 * of the embedded renderer sub-object at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void *func_02015EE8(McssWork *work)
{
    return &work->animCtrl;
}


u16 func_02015EEC(McssWork *work)
{
    return *(u16 *)work->multiCellAnimBank;
}


u8 func_02015EF4(McssWork *work)
{
    return work->stopCellTable[0];
}


u8 func_02015EFC(McssWork *work, u8 i)
{
    return (work->stopCellTable + i)[2];
}


/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the u16 at
 * +4 of the table the word at +0x2C points to (`ldrh` proves unsigned).
 * Witness for the call from ov119 func_021E33FC at 0x021E3520.
 */
u16 func_02015F04(McssWork *work)
{
    return work->cellHeader->sizeX;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the u16 at
 * +6 of the table the word at +0x2C points to (`ldrh` proves unsigned).
 *
 * Addresses are Black-image addresses.
 */
u16 func_02015F0C(McssWork *work)
{
    return work->cellHeader->sizeY;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the s16 at
 * +8 of the table the word at +0x2C points to (`ldrsh` with a register
 * offset proves signed).
 *
 * Addresses are Black-image addresses.
 */
s16 func_02015F14(McssWork *work)
{
    return work->cellHeader->ofsX;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the s16 at
 * +0xA of the table the word at +0x2C points to; sibling of
 * func_02015F14.
 *
 * Addresses are Black-image addresses.
 */
s16 func_02015F1C(McssWork *work)
{
    return work->cellHeader->ofsY;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads byte 1 of the record behind the pointer at +0x30.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02015F24(McssWork *work)
{
    return work->stopCellTable[1];
}


/*
 * A pure forwarder: tail-calls func_02063000 on a member 0x34 bytes into
 * the object, with a fixed 1 as the second argument.
 *
 * EXACT* because the 18 compiled bytes fall far short of the disasm.py
 * extent (252 bytes): the packet's next several functions carry no
 * register-saving prologue and disasm.py's extent runs to the following
 * labelled function; they are not matched here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02015F2C.c \
 *       --func sub_02015F2C --addr 0x02015F2C --cc 1.1p1
 */
void sub_02015F2C(McssWork *work, u32 callback, u32 callbackWork)
{
    func_02063000((int)&work->animCtrl, 1, callback, callbackWork);
}


void func_02015F40(McssWork *work, unsigned flags, void *callback)
{
    func_02064D70(&work->cellCtrl, callback, flags);
}


/*
 * Unlabelled Thumb function in the ARM9 module (mcss.c). Starts the
 * +0x134 fade: sets bit 12 of the +0x140 flag word, stores the current
 * and target bytes (+0x134, +0x135), the fifth argument at +0x13C, clears
 * +0x136, splits the signed step into +0x137 and the s32 step at +0x138
 * (1 - step when negative), and negates the step when the current value
 * is above the target (`cmp r1, r2 / bls`, so both are unsigned bytes).
 *
 * The step is stored as a field in each arm and the negation re-reads the
 * field (the original reloads +0x138 with a fresh `0x4e << 2` base).
 * Written through raw char offsets with the step in a local, mwcc forwards
 * the stored value into the `muls` and colours the 0x140 base into r5;
 * the struct spelling below is byte-exact. `* 0xFFFFFFFF` rather than
 * `-x` is what emits the `mvns`/`muls` pair.
 *
 * Addresses are Black-image addresses.
 */
void func_02015F50(McssWork *work, u32 start, u32 end, s32 wait, u32 color)
{
    work->flags.raw |= 0x1000;
    work->fadeStart = start;
    work->fadeEnd = end;
    work->fadeColor = color;
    work->fadeWait = 0;
    if (wait < 0) {
        work->fadeWaitSet = 0;
        work->fadeStep = -(wait - 1);
    } else {
        work->fadeWaitSet = wait;
        work->fadeStep = 1;
    }
    if (start > end) {
        work->fadeStep *= 0xFFFFFFFF;
    }
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads the low byte of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02015FAC(McssWork *work)
{
    return work->flags.bits.alpha;
}


/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness (ov117 func_021D49F4): the low byte of the word at +0x140.
 * Addresses are Black-image addresses.
 */
void func_02015FBC(McssWork *work, int alpha)
{
    work->flags.raw = (work->flags.raw & ~0xFF) | (unsigned char)alpha;
}


/*
 * Unlabelled leaf accessor, the follower of func_02015FBC: a 9-bit field at
 * bit 14 of the word at +0x140. Labelled so that func_02015FBC's extent ends
 * at its own bx lr. Addresses are Black-image addresses.
 */
void func_02015FD4(McssWork *work, int alpha)
{
    work->flags.raw = (work->flags.raw & 0xFF803FFF) | ((alpha & 0x1FF) << 14);
}


/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void func_02015FF0(McssWork *work, int flag)
{
    work->flags.raw = (work->flags.raw & 0xFF7FFFFF) | ((flag & 1) << 23);
}


/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Tests bit 12 of the
 * flag word at +0x140 (the bit func_02015F50 sets). A one-bit bitfield
 * keeps the original's lsls/lsrs pair; a mask would fold to `ands`.
 *
 * Addresses are Black-image addresses.
 */
int func_0201600C(McssWork *work)
{
    if (work->flags.bits.paletteFadeFlag) {
        return 1;
    }
    return 0;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Stores its second
 * argument into the word at +0x30. Seeded from overlay call sites.
 *
 * Addresses are Black-image addresses.
 */
void func_02016020(McssSys *sys, u32 adrs)
{
    sys->texTransAdrs = adrs;
}


void func_02016024(McssSys *sys, unsigned int adrs)
{
    sys->plttTransAdrs = adrs;
}


/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 *
 * Reconfigures the object: derives a value from func_020627D8 on field
 * +0x28 and a caller-supplied flag truncated to 16 bits (the explicit
 * lsls/lsrs #0x10 pair in the original is exactly that narrowing cast in
 * the callee, not something the caller is trusted to have done), releases
 * the handle at +0x98 through func_020307B0 if one is set, calls
 * func_02016984(a, 1), passes the derived value into func_0206469C on the
 * member at +0x34, then clears bit 0 of the word at +0x144.
 *
 * Every concrete byte matches; func_02016984 (0x02016984, later in this
 * same packet, not yet matched) is called from exactly this one site in
 * the whole ROM, so that relocation stays unresolved under the honesty
 * rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02016028.c \
 *       --func sub_02016028 --addr 0x02016028 --cc 1.1p1
 *
 * The `matched` class does not reach it: func_02016984 is not matched, so
 * no EXACT entry covers that address. Closes to EXACT the day it is
 * matched, or gets a second caller elsewhere in the image.
 */
void sub_02016028(McssWork *work, u32 animeIndex)
{
    void *seq = func_020627D8(work->multiCellAnimBank, (u16)animeIndex);

    if (work->animWork != 0) {
        func_020307B0(work->animWork);
    }

    func_02016984(work, 1);
    func_0206469C(&work->animCtrl, seq);
    work->requestFlags.raw &= ~1u;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads bits 24..27 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02016068(McssWork *work)
{
    return work->flags.bits.mosaic;
}


/*
 * Updates a packed 4-bit mode field at b+0x140 (bits 24-27 of that word;
 * see docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md) if
 * the caller's requested mode (clamped to 15) differs from the current
 * one, then reinitialises through func_02016BA0 and forwards a nested
 * word and struct pointer into func_020163C4. The bitfield pointer is
 * recomputed fresh for the store rather than kept in a local across the
 * clamp branch: the original re-issues the same "5 << 6" multiply instead
 * of reusing the register from the read, the same shape as
 * docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md.
 *
 * EXACT* because the 72 compiled bytes fall short of the disasm.py extent
 * (92 bytes): the extent runs into the next function's own literal pool,
 * not a byte difference.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02016078.c \
 *       --func sub_02016078 --addr 0x02016078 --cc 1.1p1
 */
void sub_02016078(McssSys *sys, McssWork *work, int mosaic)
{
    if (work->flags.bits.mosaic != (u32)mosaic) {
        if (mosaic > 15) {
            mosaic = 15;
        }
        work->flags.bits.mosaic = mosaic;
        func_02016BA0(work);
        func_020163C4(sys, work->index, &work->addWork);
    }
}


void func_020160C0(McssSys *sys, unsigned int scale)
{
    sys->globalScale = scale;
}


void func_020160C4(McssWork *work, int speed)
{
    work->animeSpeed = speed;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads the halfword behind the pointer at +0x28.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u16 func_020160CC(McssWork *work)
{
    return *(u16 *)work->multiCellAnimBank;
}


/*
 * mcss.c: builds the per-scene fade/transition context.  Three debug
 * allocations out of the heap named by the u16 at +0x14c (masked to
 * 0x7fff and forced into the 0x8000 bank), then a palette blend and a
 * copy, and finally either a task registration (func_0201691C as the
 * callback, through the owner-aware path or the plain one) or, if the
 * caller has already set the "skip" bit at +0x140, an immediate teardown
 * of everything just allocated.  Either way the done bit 0x10000000 is
 * latched into the same word at +0x140.
 *
 * The three heap ids are recomputed rather than cached: each is a fresh
 * `ldr`+lsls/lsrs of the int field at +0x14c, so the field is an `int`
 * truncated at the call, not a u16 member (see func_02016984 in this
 * same file).  The two __LINE__ pool words 0x761 and 0x769 are the
 * consecutive-line idiom: 0x76e is derived from 0x769 with `adds #5`.
 *
 * Closed in the second pass (2026-09-22) from the 12-byte prologue-spill
 * near miss in docs/notes/func_020160D4.c.txt.  The lever is the THIRD
 * PARAMETER'S TYPE: `u16 a2`, not `int a2`.
 *
 * That note's own list had tried `u16` on a3 (which made it worse, 168
 * bytes) and `u32` on a2, but never `u16` on a2.  tools/permuter.py
 * found it as `type:p(a2:int->u16)` on the 306th compile of a
 * `--mode hill --budget 800 --types` run, taking 12 concrete bytes to 0
 * in one mutation.  A 16-bit parameter arrives already narrowed, so the
 * front end spills it BEFORE it touches the literal pool -- which is
 * exactly the `str r2,[sp,#4]` / `ldr r0,[pc,#0x158]` / `str r3,[sp,#8]`
 * order the note recorded and could not reach.  The note's "untried
 * lever" guess (make a2 reach a call earlier) was not needed.
 *
 * This is also a data point for the family: the value at +0x13C that
 * func_020169E8 hands to func_02021F64 as `(u16)` is 16-bit AT THE
 * PARAMETER here, not only at the call.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020160D4.c \
 *       --func func_020160D4 --addr 0x020160D4 --cc 1.1p1 --thumb
 */
void func_020160D4(McssSys *sys, McssWork *work, u16 fadeLevel, int fadeColor)
{
    McssTransTask *task;

    task = func_02030734(
            (u16)(((u16)work->heapId & 0x7fff) | 0x8000),
            0x2c, 1, sFileMcss, 0x761);

    task->sys = sys;
    task->hasTaskSys = (sys->taskSys != 0);
    task->work = work;
    task->plttProxyOut = &work->plttProxy;
    task->plttDest = sys->plttTransAdrs + (work->index << 5);

    task->plttData = func_02030734(
            (u16)(((u16)work->heapId & 0x7fff) | 0x8000),
            0x10, 0, sFileMcss, 0x769);

    task->plttData->fmt = work->plttProxy.fmt;
    task->plttData->extended = 0;
    task->plttData->byteSize = work->plttByteSize;
    task->plttData->data = func_02030734(
            (u16)(((u16)work->heapId & 0x7fff) | 0x8000),
            work->plttByteSize, 0, sFileMcss, 0x76e);

    func_02021F64(work->plttOriginal,
                  task->plttData->data,
                  (u16)((s32)work->plttByteSize / 2),
                  fadeLevel, (u16)fadeColor);
    func_02082A60(task->plttData->data,
                  work->plttCurrent, work->plttByteSize);

    if (work->paletteTask != 0) {
        func_02016C38(work->paletteTask);
        work->paletteTask = 0;
    }

    if (work->flags.bits.paletteFadeFlag == 0) {
        if (sys->taskSys != 0) {
            work->paletteTask = func_02030DA8(sys->taskSys,
                                             func_0201691C, task, 0);
        } else {
            work->paletteTask = func_020056A0(func_0201691C, task, 0);
        }
    } else {
        func_020307B0(task->plttData->data);
        func_020307B0(task->plttData);
        func_020307B0(task);
    }

    work->flags.raw |= 0x10000000;
}


void func_0201624C(McssSys *sys, McssWork *work)
{
    McssTransTask *task;
    u32 hasTaskSys;
    void *handle;

    hasTaskSys = 1;
    task = func_02030734((u16)(((u16)work->heapId & 0x7FFF) | 0x8000), 0x2C, 1, sFileMcss, 1942);
    task->sys = sys;
    if (sys->taskSys == 0) {
        hasTaskSys = 0;
    }
    task->hasTaskSys = hasTaskSys;
    task->work = work;
    task->plttProxyOut = &work->plttProxy;
    task->plttDest = sys->plttTransAdrs + (work->index << 5);

    hasTaskSys = 0;
    task->plttData = func_02030734((u16)(((u16)work->heapId & 0x7FFF) | 0x8000), 0x10, 0, sFileMcss, 1950);
    task->plttData->fmt = work->plttProxy.fmt;
    task->plttData->extended = hasTaskSys;
    task->plttData->byteSize = work->plttByteSize;

    task->plttData->data = func_02030734((u16)(((u16)work->heapId & 0x7FFF) | 0x8000), work->plttByteSize, 0, sFileMcss, 1950 + 5);
    MIi_CpuCopy16(work->plttOriginal, task->plttData->data, work->plttByteSize);

    if (work->paletteTask != 0) {
        func_02016C38(work->paletteTask);
        work->paletteTask = (void *)hasTaskSys;
    }

    if (sys->taskSys != 0) {
        handle = func_02030DA8(sys->taskSys, func_0201691C, task, 0);
    } else {
        handle = func_020056A0(func_0201691C, task, 0);
    }
    work->paletteTask = handle;

    work->flags.raw &= 0xEFFFFFFF;
}


/*
 * A single matched function.
 *
 * alias: an argument-adjusting tail call: it shifts the object pointer to
 * a member 0x34 bytes in and hands off to func_02064CBC. See
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_02016374.c \
 *       --func sub_02016374 --addr 0x02016374 --cc 1.1p1 --thumb
 */
void sub_02016374(McssWork *work)
{
    func_02064CBC(&work->animCtrl);
}


/*
 * Set bit 0 of the word at +0x144: read, clear, set, write back.  The two
 * `movs r1, #1` are the two separate constants of the `& ~1` / `| 1` pair
 * (Thumb has no ORR immediate, so both go through r1).  Entry attested by
 * the pool word 0x02016381 in sub_020173C8's own pool.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02016380.c \
 *       --func sub_02016380 --addr 0x02016380 --cc 1.1p1 --thumb
 */
void sub_02016380(McssWork *work)
{
    u32 flags = work->requestFlags.raw;
    flags = flags & ~1u;
    flags = flags | 1u;
    work->requestFlags.raw = flags;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 30 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02016394(McssWork *work, int flag)
{
    work->flags.bits.mepachiDrawLast = flag;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Stores a word at +0x48.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_020163B0(McssSys *sys, int depthStep)
{
    sys->depthStep = depthStep;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 1 of the flag word at +0x2C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_020163B4(McssSys *sys, int flag)
{
    sys->flags.bits.nearDepthRange = flag;
}


/*
 * The mcss.c bind-slot routine (line 0x840).  Closed in wave 15 from 16
 * bytes out by one declaration: the descriptor parameter is
 * const McssAddWork *.  Without const, the four constructor call sites
 * load a2 for the first argument before the second; with it the image's
 * order (second-argument base first, then the first, then the out
 * pointer copy) comes out.  History: docs/notes/func_020163C4.c.txt.
 */
void func_020163C4(McssSys *sys, u32 index, const McssAddWork *addWork)
{
    McssWork *work = sys->works[index];
    McssTransTask *task;
    u32 heap;
    u32 flag;
    McssCellHeader *cellHeader;

    {
        u32 t;
        if (addWork->heapMode == 1) {
            t = (u16)(((u16)work->heapId & 0x7FFF) | 0x8000);
        } else {
            t = work->heapId;
        }
        heap = (u16)t;
    }

    if (sys->arcHandle != 0 && sys->arcId == addWork->arcId) {
        func_02016630(sys, index, addWork);
        return;
    }

    work->flags.raw &= 0xFFFFDFFF;
    func_02063790((u32 *)&work->texImage);
    func_020637D4((u32 *)&work->plttProxy);

    work->cellFile = func_02049FBC(addWork->arcId, addWork->cellMember, 0, &work->cellBank, heap);
    work->cellAnimFile = func_0204A03C(addWork->arcId, addWork->cellAnimMember, 1, &work->cellAnimBank, heap);
    flag = 1;
    work->multiCellFile = func_0204A0BC(addWork->arcId, addWork->multiCellMember, 0, &work->multiCellBank, heap);
    work->multiCellAnimFile = func_0204A13C(addWork->arcId, addWork->multiCellAnimMember, 0, &work->multiCellAnimBank, heap);
    sub_02016028(work, 0);

    cellHeader = func_02048F60(addWork->arcId, addWork->cellHeaderMember, heap);
    work->cellHeader = cellHeader;
    work->stopCellTable = (u8 *)cellHeader + ((0x30 * cellHeader->cellCount + 0xC) & ~3u);

    task = func_02030734((u16)(((u16)work->heapId & (0xFFFFDFFFu >> 0x11)) | (flag << 0xF)),
                         0x2C, 1, sFileMcss, 0x840);
    task->sys = sys;
    if (sys->taskSys == 0) {
        flag = 0;
    }
    task->hasTaskSys = flag;
    task->texImageOut = &work->texImage;
    task->plttProxyOut = &work->plttProxy;
    task->texDest = sys->texTransAdrs + (index << 0xE);
    task->plttDest = sys->plttTransAdrs + (index << 5);
    task->work = work;

    task->texBuf = func_02049DB4(addWork->arcId, addWork->textureMember, 1, task,
                                 (u16)(((u16)work->heapId & 0x7FFF) | 0x8000));
    task->plttBuf = func_02049F34(addWork->arcId, addWork->paletteMember, &task->plttData,
                                  (u16)(((u16)work->heapId & 0x7FFF) | 0x8000));

    work->plttOriginal = func_02030734(heap,
                                       task->plttData->byteSize, 0,
                                       sFileMcss, 0x858);
    work->plttCurrent = func_02030734(heap,
                                      task->plttData->byteSize, 0,
                                      sFileMcss, 0x858 + 1);
    work->plttByteSize = task->plttData->byteSize;
    MIi_CpuCopy16(task->plttData->data, work->plttOriginal,
                  task->plttData->byteSize);

    if (sys->loadHook != 0) {
        if (sys->loadHook(addWork, task, sys->loadHookWork) == 1) {
            sys->loadHook = 0;
            sys->loadHookWork = 0;
        }
    }
    if (work->flags.bits.mosaic != 0) {
        func_02016C60(work, task);
    }
    if (sys->taskSys != 0) {
        work->textureTask = func_02030DA8(sys->taskSys, func_02016880, task, 0);
    } else {
        work->textureTask = func_020056A0(func_02016880, task, 0);
    }
}


/*
 * The mcss.c rebind routine (line 0x8AB), twin of func_020163C4.  Closed
 * in wave 15 from 21 bytes out by the same declaration: the descriptor
 * parameter is const McssAddWork *, which fixes the argument load order
 * at every constructor call site.  History:
 * docs/notes/func_02016630.c.txt.
 */
void func_02016630(McssSys *sys, u32 index, const McssAddWork *addWork)
{
    McssWork *work = sys->works[index];
    void *arcHandle;
    McssTransTask *task;
    u32 flag;
    McssCellHeader *cellHeader;

    arcHandle = sys->arcHandle;
    work->flags.raw &= 0xFFFFDFFF;
    func_02063790((u32 *)&work->texImage);
    func_020637D4((u32 *)&work->plttProxy);

    work->cellFile = func_02049FFC(arcHandle, addWork->cellMember, 0,
                                   &work->cellBank,
                                   (u16)work->heapId);
    work->cellAnimFile = func_0204A07C(arcHandle, addWork->cellAnimMember, 1, &work->cellAnimBank,
                                       (u16)work->heapId);
    flag = 1;
    work->multiCellFile = func_0204A0FC(arcHandle, addWork->multiCellMember, 0, &work->multiCellBank,
                                        (u16)work->heapId);
    work->multiCellAnimFile = func_0204A17C(arcHandle, addWork->multiCellAnimMember, 0, &work->multiCellAnimBank,
                                            (u16)work->heapId);
    sub_02016028(work, 0);

    cellHeader = func_02049250(arcHandle, addWork->cellHeaderMember, (u16)work->heapId);
    work->cellHeader = cellHeader;
    work->stopCellTable = (u8 *)cellHeader + ((0x30 * cellHeader->cellCount + 0xC) & ~3u);

    task = func_02030734((u16)(((u16)work->heapId & (0xFFFFDFFFu >> 0x11)) | (flag << 0xF)),
                         0x2C, 1, sFileMcss, 0x8AB);
    task->sys = sys;
    if (sys->taskSys == 0) {
        flag = 0;
    }
    task->hasTaskSys = flag;
    task->texImageOut = &work->texImage;
    task->plttProxyOut = &work->plttProxy;
    task->texDest = sys->texTransAdrs + (index << 0xE);
    task->plttDest = sys->plttTransAdrs + (index << 5);
    task->work = work;

    task->texBuf = func_02049DF4(arcHandle, addWork->textureMember, 1, task,
                                 (u16)(((u16)work->heapId & 0x7FFF) | 0x8000));
    task->plttBuf = func_02049F78(arcHandle, addWork->paletteMember, &task->plttData,
                                  (u16)(((u16)work->heapId & 0x7FFF) | 0x8000));

    work->plttOriginal = func_02030734((u16)work->heapId,
                                       task->plttData->byteSize, 0,
                                       sFileMcss, 0x8C3);
    work->plttCurrent = func_02030734((u16)work->heapId,
                                      task->plttData->byteSize, 0,
                                      sFileMcss, 0x8C3 + 1);
    work->plttByteSize = task->plttData->byteSize;
    MIi_CpuCopy16(task->plttData->data, work->plttOriginal,
                  task->plttData->byteSize);

    if (sys->loadHook != 0) {
        if (sys->loadHook(addWork, task, sys->loadHookWork) == 1) {
            sys->loadHook = 0;
            sys->loadHookWork = 0;
        }
    }
    if (work->flags.bits.mosaic != 0) {
        func_02016C60(work, task);
    }
    if (sys->taskSys != 0) {
        work->textureTask = func_02030DA8(sys->taskSys, func_02016880, task, 0);
    } else {
        work->textureTask = func_020056A0(func_02016880, task, 0);
    }
}


void func_02016880(void *taskHandle, McssTransTask *task)
{
    if (task->hasTaskSys == 0) {
        u32 scanline = *(volatile u16 *)0x04000006;

        if (scanline < 0xc0 || scanline > 0xc8)
            return;
    }
    if (task->texBuf != 0) {
        func_02063A54(task->texData, task->texDest, 0, task->texImageOut);
        sub_020307B0(task->texBuf);
        if (task->work->flags.bits.mosaic == 0) {
            task->texBuf = 0;
            return;
        }
    }
    if (task->work != 0)
        task->work->flags.raw |= 0x2000;
    if (task->plttBuf != 0) {
        func_02063E54(task->plttData, task->plttDest, 0, task->plttProxyOut);
        sub_020307B0(task->plttBuf);
    }
    if (task->work != 0)
        task->work->textureTask = 0;
    if (task->sys != 0 && task->sys->shadowPlttTask != 0)
        task->sys->shadowPlttTask = 0;
    sub_020307B0(task);
    sub_02030EAC(taskHandle);
}


void func_0201691C(void *taskHandle, McssTransTask *task)
{
    if (task->hasTaskSys == 0) {
        u32 scanline = *(volatile u16 *)0x04000006;

        if (scanline < 0xc0 || scanline > 0xc8)
            return;
    }
    func_020637D4((u32 *)task->plttProxyOut);
    func_02063E54(task->plttData, task->plttDest, 0, task->plttProxyOut);
    if (task->work != 0) {
        if (task->work->fadeTask == taskHandle)
            task->work->fadeTask = 0;
        if (task->work->paletteTask == taskHandle)
            task->work->paletteTask = 0;
    }
    sub_020307B0(task->plttData->data);
    sub_020307B0(task->plttData);
    sub_020307B0(task);
    sub_02030EAC(taskHandle);
}


/*
 * A two-call registrar.  The first call is five arguments wide: the value
 * loaded from +0x14c is an `int` truncated to `u16` at the call (the listing
 * shows `ldr` + the lsls/lsrs 0x10 pair, not a `ldrh` - declaring the field
 * itself `u16` is what produces a `ldrh` and loses four bytes), and 0x970 is
 * the fifth argument on the stack.  The result is stored back into +0x98,
 * which the second call reads as its own second argument, so the field is a
 * genuine `int`.
 *
 * The pool word at 0x020169D0 is 0x020A72CC; that same word sits in eight
 * other functions' pools in this image (0x02014B9C, 0x02015B94, 0x02016240,
 * 0x02016360, 0x02016624, 0x02016870, 0x02016B84, ...), all outside the
 * compared range, which is what attests the site through the `literal` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02016984.c \
 *       --func func_02016984 --addr 0x02016984 --cc 1.1p1 --thumb
 */
void func_02016984(McssWork *work, int kind)
{
    work->animWork = func_02030734((unsigned short)work->heapId,
                                   func_020648B4(work->multiCellBank, kind),
                                   0, sFileMcss, 0x970);
    func_02064754(&work->animCtrl, work->animWork, work->cellAnimBank,
                  work->cellBank, work->multiCellBank, kind);
}


/*
 * A single matched function.
 *
 * alias: a direct write of a fixed 32-bit value to a hardware register pair
 * at 0x040004C0: the low word gets the full constant, the high word (at
 * +4) gets its upper halfword. This is a raw I/O register store, not an
 * SDK call, which is why it is game code sitting on hardware address space.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_020169D4.c \
 *       --func sub_020169D4 --addr 0x020169D4 --cc 1.1p1 --thumb
 */
void sub_020169D4(void)
{
    u32 v = 0x4210FFFF;
    *(volatile u32 *)0x040004C0 = v;
    *(volatile u32 *)0x040004C4 = v >> 16;
}


/*
 * Closed in the second pass (2026-09-22) from the 4-byte near miss in
 * docs/notes/func_020169E8.c.txt.  The residue was NOT the pool-word
 * shape that note predicted; it was two misreadings of the image:
 *
 *   1. the flag mask is 0xFFFFEFFF (bit 12), not 0xEFFFFFFF (bit 28).
 *      The pool word at 0x02016B94 is `ff ef ff ff`.  Fixing it alone
 *      took the diff from 4 concrete bytes to 2.
 *   2. the second clamp reads +0x135 / +0x134, not +0x137 / +0x136.
 *      The `ldr r0,[pc,#0x3c]` at 0x02016B58 resolves to 0x02016B98,
 *      the SECOND pool word (0x135), while the `ldr r0,[pc,#0x30]` at
 *      0x02016B6A resolves to 0x02016B9C, the THIRD (0x137).  Reading
 *      both as 0x137 is what made the 0x135 pool word disappear and the
 *      function come out 436 bytes instead of 440.  The missing pool
 *      word was a symptom, not the cause.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020169E8.c \
 *       --func func_020169E8 --addr 0x020169E8 --cc 1.1p1 --thumb
 */
void func_020169E8(McssSys *sys, McssWork *work)
{
    McssTransTask *task;
    u32 flag;
    void *handle;
    s32 step;
    s8 cur;
    s8 target;

    if (work->fadeWait != 0) {
        goto dec;
    }

    flag = 1;
    task = func_02030734((u16)(((u16)work->heapId & 0x7FFF) | 0x8000), 0x2C, 1, sFileMcss, 0x9A1);
    task->sys = sys;
    if (sys->taskSys == 0) {
        flag = 0;
    }
    task->hasTaskSys = flag;
    task->work = work;
    task->plttProxyOut = &work->plttProxy;
    task->plttDest = sys->plttTransAdrs + (work->index << 5);

    flag = 0;
    task->plttData = func_02030734((u16)(((u16)work->heapId & 0x7FFF) | 0x8000), 0x10, 0, sFileMcss, 0x9A9);
    task->plttData->fmt = work->plttProxy.fmt;
    task->plttData->extended = flag;
    task->plttData->byteSize = work->plttByteSize;
    task->plttData->data = func_02030734((u16)(((u16)work->heapId & 0x7FFF) | 0x8000), work->plttByteSize, 0, sFileMcss, 0x9A9 + 5);

    if (work->flags.bits.plttCurrentValid) {
        func_02021F64(work->plttCurrent, task->plttData->data, ((s32)work->plttByteSize / 2), *(u8 *)&work->fadeStart, (u16)work->fadeColor);
    } else {
        func_02021F64(work->plttOriginal, task->plttData->data, ((s32)work->plttByteSize / 2), *(u8 *)&work->fadeStart, (u16)work->fadeColor);
    }

    if (work->fadeTask != 0) {
        func_02016C38(work->fadeTask);
        work->fadeTask = 0;
    }

    if (sys->taskSys != 0) {
        handle = func_02030DA8(sys->taskSys, func_0201691C, task, 0);
    } else {
        handle = func_020056A0(func_0201691C, task, 0);
    }
    work->fadeTask = handle;

    cur = work->fadeStart;
    target = work->fadeEnd;
    if (cur == target) {
        work->flags.raw &= 0xFFFFEFFF;
    } else {
        step = work->fadeStep;
        work->fadeStart = (s8)(cur + (s8)step);
        if (step < 0 || work->fadeStart < target) {
            if (step < 0) {
                target = work->fadeEnd;
                if (work->fadeStart > target) {
                    goto done;
                }
            } else {
                goto done;
            }
        }
        work->fadeStart = target;
    }
done:
    work->fadeWait = work->fadeWaitSet;
    return;
dec:
    work->fadeWait = work->fadeWait - 1;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: a teardown chain on the same object class as unit_02015BA4.c.
 * sub_02016BA0 releases eight pointer fields of the object through
 * func_020307B0 (a generic release call reached by blx, so it is ARM),
 * zeroes three of them (+0x98, +0xd4, +0xd8, all past the immediate str
 * reach so the compiler adds the offset into a register first), then
 * zeroes the other four (+0xc, +0x1c, +0x14, +0x24, +0x2c) and, if the
 * object's own field at +0 is non-zero, recurses into sub_02016C0C with
 * that field's value before zeroing it too. sub_02016C0C turns an id into
 * an object through func_02030EE8, releases one or two of the object's own
 * pointer fields the same way, releases the object itself, and finally
 * releases the id through func_02030EAC.
 *
 * The immediate follower, sub_02016C38 (38 bytes, same shape over a third
 * field, one level of extra indirection), is a documented near miss: this
 * front end assigns it only two callee-saved registers (padding a filler
 * into r3) where the original spends three (r4, r5, r6), so the second
 * fetch of the inner pointer is a register move here and a reload from
 * memory in every source shape tried. Left out rather than forced.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02016BA0.c \
 *       --addr 0x02016BA0 --thumb
 */
void sub_02016BA0(McssWork *work)
{
    func_020307B0(work->cellFile);
    func_020307B0(work->cellAnimFile);
    func_020307B0(work->multiCellFile);
    func_020307B0(work->multiCellAnimFile);
    func_020307B0(work->animWork);
    func_020307B0(work->cellHeader);
    func_020307B0(work->plttOriginal);
    func_020307B0(work->plttCurrent);

    work->animWork = 0;
    work->plttOriginal = 0;
    work->plttCurrent = 0;

    {
        void *task = work->textureTask;
        work->cellFile = 0;
        work->cellAnimFile = 0;
        work->multiCellFile = 0;
        work->multiCellAnimFile = 0;
        work->cellHeader = 0;
        if (task != 0) {
            func_02016C0C(task);
            work->textureTask = 0;
        }
    }
}


void sub_02016C0C(void *taskHandle)
{
    McssTransTask *task = func_02030EE8(taskHandle);

    if (task->texBuf != 0) {
        func_020307B0(task->texBuf);
    }
    if (task->plttBuf != 0) {
        func_020307B0(task->plttBuf);
    }
    func_020307B0(task);
    func_02030EAC(taskHandle);
}


void func_02016C38(void *taskHandle)
{
    McssTransTask *task = func_02030EE8(taskHandle);
    func_020307B0(task->plttData->data);
    func_020307B0(task->plttData);
    func_020307B0(task);
    func_02030EAC(taskHandle);
}


/*
 * mcss.c, the two-pass nibble fill over the 0x30-byte cell records of work->cellHeader.
 * EXACT* (870 bytes; the 872-byte listing extent carries 2 pad bytes).
 * Closed in wave 21 (lane B2) from 16 bytes out.  The lever is eyeW: it is
 * read raw into the guard (`eyeW = rec->eye.w; if (eyeW != 0)`) and shifted
 * later (`eyeW >>= 12;`), and the pass-2 header follows pass 1's order,
 * eyeS, eyeT, eyeW, eyeH, then `eyeBlockRow = 0; blockY = 0;`.  The raw eyeW web spans the
 * eyeS/eyeT reads and is coloured before the record pointer, which puts
 * the pointer in r1 and both zeros in r0, as the image has them.
 * History: docs/notes/pkt_02016C60.c.txt.
 */
void func_02016C60(McssWork *work, McssTransTask *task)
{
  s32 rowBytes;
  u8 *pixels;
  s32 cellIdx;
  s32 bodyS;
  s32 bodyT;
  s32 bodyW;
  s32 bodyH;
  s32 blockSize;
  s32 fillLow;
  s32 colorIdx;
  s32 blockX;
  s32 blockY;
  s32 blockRow;
  s32 blockCol;
  s32 eyeS;
  s32 eyeT;
  s32 eyeW;
  s32 eyeH;
  s32 eyeBlockRow;
  s32 eyeBlockCol;
  s32 blockW;
  s32 blockH;
  s32 row;
  s32 col;
  s32 byteOfs;
  s32 texX;
  s32 texel;
  s32 fillY;
  s32 eyeFillY;
  s32 searchY;
  s32 fillYBase;
  s32 eyeFillYBase;
  s32 eyeSearchY;
  s32 fillXBase;
  if (work->texImage.fmt != 3)
  {
    return;
  }
  rowBytes = _d2s(func_0209AB80(2.0, _s32_to_double(work->texImage.sizeS + 2)));
  pixels = task->texData->rawData;
  cellIdx = 0;
  while (((u32) cellIdx) < work->cellHeader->cellCount)
  {
    bodyS = work->cellHeader->cells[cellIdx].body.s >> 12;
    bodyT = work->cellHeader->cells[cellIdx].body.t >> 12;
    bodyW = work->cellHeader->cells[cellIdx].body.w >> 12;
    bodyH = work->cellHeader->cells[cellIdx].body.h >> 12;
    blockSize = ((s32) work->flags.bits.mosaic) + 1;
    blockRow = 0;
    blockY = 0;
    if (bodyH > 0)
    {
      do
      {
        for (blockCol = 0, blockX = 0; blockX < bodyW; blockCol++, blockX += blockSize)
        {
          {
            s32 fillHigh;
            if ((blockX + blockSize) > bodyW)
            {
              blockW = bodyW - (blockSize * blockCol);
            }
            else
            {
              blockW = blockSize;
            }
            if ((blockY + blockSize) > bodyH)
            {
              blockH = bodyH - (blockSize * blockRow);
            }
            else
            {
              blockH = blockSize;
            }
            colorIdx = 0;
            for (row = 0; row < blockH; row++)
            {
              for (col = 0; col < blockW; col++)
              {
                texX = (bodyS + blockX) + col;
                searchY = (bodyT + blockY) + row;
                byteOfs = (texX / 2) + (searchY * rowBytes);
                if (col & 1)
                {
                  texel = (pixels[byteOfs] & 0xf0) >> 4;
                }
                else
                {
                  texel = pixels[byteOfs] & 0x0f;
                }
                if (texel != 0)
                {
                  colorIdx = texel;
                  break;
                }
              }

              if (colorIdx != 0)
              {
                break;
              }
            }

            fillLow = (u8) colorIdx;
            fillHigh = fillLow << 4;
            for (row = 0; row < blockH; row++)
            {
              for (col = 0; col < blockW; col++)
              {
                fillXBase = bodyS + blockX;
                texX = fillXBase + col;
                fillYBase = bodyT + blockY;
                fillY = fillYBase + row;
                byteOfs = (texX / 2) + (fillY * rowBytes);
                if (byteOfs < (1 << 14))
                {
                  if (texX & 1)
                  {
                    pixels[byteOfs] = (pixels[byteOfs] & 0x0f) | fillHigh;
                  }
                  else
                  {
                    pixels[byteOfs] = (pixels[byteOfs] & 0xf0) | fillLow;
                  }
                }
              }

            }

          }
        }

        blockRow++;
        blockY += blockSize;
      }
      while (blockY < bodyH);
    }
    eyeW = work->cellHeader->cells[cellIdx].eye.w;
    if (eyeW != 0)
    {
      eyeS = work->cellHeader->cells[cellIdx].eye.s >> 12;
      eyeT = work->cellHeader->cells[cellIdx].eye.t >> 12;
      eyeW >>= 12;
      eyeH = (work->cellHeader->cells[cellIdx].eye.h >> 12) << 1;
      eyeBlockRow = 0;
      blockY = 0;
      if (eyeH > 0)
      {
        do
        {
          for (eyeBlockCol = 0, blockX = 0; blockX < eyeW; eyeBlockCol++, blockX += blockSize)
          {
            {
              s32 eyeFillHigh;
              if ((blockX + blockSize) > eyeW)
              {
                blockW = eyeW - (blockSize * eyeBlockCol);
              }
              else
              {
                blockW = blockSize;
              }
              if ((blockY + blockSize) > eyeH)
              {
                blockH = eyeH - (blockSize * eyeBlockRow);
              }
              else
              {
                blockH = blockSize;
              }
              colorIdx = 0;
              for (row = 0; row < blockH; row++)
              {
                for (col = 0; col < blockW; col++)
                {
                  texX = (eyeS + blockX) + col;
                  eyeSearchY = (eyeT + blockY) + row;
                  byteOfs = (texX / 2) + (eyeSearchY * rowBytes);
                  if (col & 1)
                  {
                    texel = (pixels[byteOfs] & 0xf0) >> 4;
                  }
                  else
                  {
                    texel = pixels[byteOfs] & 0x0f;
                  }
                  if (texel != 0)
                  {
                    colorIdx = texel;
                    break;
                  }
                }

                if (colorIdx != 0)
                {
                  break;
                }
              }

              fillLow = (u8) colorIdx;
              eyeFillHigh = fillLow << 4;
              for (row = 0; row < blockH; row++)
              {
                for (col = 0; col < blockW; col++)
                {
                  texX = eyeS + blockX;
                  texX = texX + col;
                  eyeFillYBase = eyeT + blockY;
                  eyeFillY = eyeFillYBase + row;
                  byteOfs = (texX / 2) + (eyeFillY * rowBytes);
                  if (byteOfs < (1 << 14))
                  {
                    if (texX & 1)
                    {
                      pixels[byteOfs] = (pixels[byteOfs] & 0x0f) | eyeFillHigh;
                    }
                    else
                    {
                      pixels[byteOfs] = (pixels[byteOfs] & 0xf0) | fillLow;
                    }
                  }
                }

              }

            }
          }

          eyeBlockRow++;
          blockY += blockSize;
        }
        while (blockY < eyeH);
      }
    }
    cellIdx++;
  }

}


/*
 * 310 bytes, one function, and two bytes of linker fill after it before the
 * next function at 0x02017100; the range this entry owns is 0x02016FC8 plus
 * 310, which is why it is written as a unit rather than as a single function
 * entry (`match.py one` measures the extent to the next label, sees 312 and
 * reports EXACT* over two bytes the compiler never emitted).
 *
 * The 4x4 fixed-point transform of a three-component vector: the ordinary
 * Nitro row-vector convention, out = v * M with the translation row added
 * afterwards, computed in 64 bit and shifted back down by the 12 fractional
 * bits at the end of each component.  The fourth component does not go into
 * the destination vector; it is written through a separate `s32 *`, which is
 * what makes this the projection form rather than MTX_MultVec: the caller
 * gets x, y, z and w separately and divides by w itself.
 *
 *   dst->x = (s32)((vx * m[0][0] + vy * m[1][0] + vz * m[2][0]) >> 12)
 *            + m[3][0];        and the same for columns 1, 2 and 3
 *
 * Every product is a call to the compiler's 64 bit multiply helper at
 * 0x0209C054, twelve of them, and the `asrs rN, rM, #0x1f` in front of each
 * operand is the sign extension an `s32` costs on the way to `long long`; see
 * docs/idioms/consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md
 * for the same family of helpers seen from the division side.  The name the
 * relocation carries is `_ll_mul`, not `_ull_mul`: both spellings name the
 * same routine at 0x0209C054 (`umull` plus two `mla` is correct for either
 * signedness), and which one mwccarm emits follows the signedness of the
 * operands, so `src/matched/unit_020056A0.c` pins the same address under the
 * other name.  The helper's contract is r0:r1 and r2:r3 in, r0:r1 out.
 *
 * The 64 bit shift is not a call.  `lsls r0, rHi, #0x14` / `lsrs r1, rLo, #0xc`
 * / `orrs r1, r0` is the low word of a `>> 12` on a 64 bit value with the high
 * word dead, which is what the cast back to `s32` makes of it; the shift of
 * the low half is `lsrs` and not `asrs` whatever the sign of the value,
 * because it is a bit-field splice and not an arithmetic shift.
 *
 * ---------------------------------------------------------------------------
 * WHAT COST THE TIME
 * ---------------------------------------------------------------------------
 * **The shifted product needs a named local, or the translation row is loaded
 * ten bytes too early.**  Written as one expression,
 *
 *     dst->x = (s32)((...) >> 12) + mtx->m[3][0];
 *
 * the compiler loads `mtx->m[3][0]` before the last two adds of the 64 bit
 * accumulation, which then needs two register copies to get the helper's
 * result out of r0:r1; the function grows twelve bytes and 248 concrete bytes
 * differ, all of them scheduling.  Splitting the statement,
 *
 *     r = (s32)((...) >> 12);
 *     dst->x = r + mtx->m[3][0];
 *
 * is EXACT.  Holding the 64 bit sum in an `s64` local instead and casting at
 * the store is byte-identical, so the image does not say which of the two the
 * source wrote, only that it was not one expression.
 *
 * **The three vector components are read into locals, and the sign extension
 * is what they are read for.**  `v` is `const` and `dst` is not, so a store
 * through `dst` may alias `v`; written as `v->x` inside all twelve products
 * the compiler reloads and re-extends each component for every output and
 * comes out four bytes short with the whole body rescheduled.  Three `s32`
 * locals assigned at the top make the six words of sign-extended vector one
 * CSE that lives on the stack at sp+4 through sp+0x18 for the whole function,
 * which is the original's frame.  The same three values held as `s64` locals
 * are twelve bytes longer, so the source's locals are 32 bit and the cast is
 * at the multiply.
 *
 * Nothing here is version specific: every constant is a matrix offset or the
 * fixed-point shift.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02016FC8.c  *       --addr 0x02016FC8 --thumb
 */
void func_02016FC8(const VecFx32 *v, const MtxFx44 *mtx,
                   VecFx32 *dst, s32 *w)
{
    s32 vx;
    s32 vy;
    s32 vz;
    s32 r;

    vx = v->x;
    vy = v->y;
    vz = v->z;

    r = (s32)(((s64)vx * mtx->m[0][0] + (s64)vy * mtx->m[1][0]
                    + (s64)vz * mtx->m[2][0]) >> 12);
    dst->x = r + mtx->m[3][0];
    r = (s32)(((s64)vx * mtx->m[0][1] + (s64)vy * mtx->m[1][1]
                    + (s64)vz * mtx->m[2][1]) >> 12);
    dst->y = r + mtx->m[3][1];
    r = (s32)(((s64)vx * mtx->m[0][2] + (s64)vy * mtx->m[1][2]
                    + (s64)vz * mtx->m[2][2]) >> 12);
    dst->z = r + mtx->m[3][2];
    r = (s32)(((s64)vx * mtx->m[0][3] + (s64)vy * mtx->m[1][3]
                    + (s64)vz * mtx->m[2][3]) >> 12);
    *w = r + mtx->m[3][3];
}


/*
 * The first of two parallel fillers of the same nine word record.
 * func_02017168 builds it from the five values func_02017114 reads out of the
 * save block and writes 0 into the last word; its twin at 0x02017214 builds
 * the same record from a pair of pointers and writes 1, so that word is the
 * tag saying which of the two produced it.  The twin is parked in
 * src/pending/unit_02017214.c: it is the only caller of six of its eight
 * callees.
 *
 * func_02017100 passes its first argument through func_020185F4 rather than
 * holding it in a callee-saved register, which is only possible because that
 * function returns its argument: it is the two byte `bx lr` at 0x020185F4 that
 * src/matched/unit_020185F0.c matches as an empty hook.  Written as a void
 * call followed by func_02017114(p, ...) the first argument would have to be
 * saved across it and the function grows a register.
 */
void func_02017100(void *pp, McssAddWork *out, u32 direction)
{
    func_02017114(func_020185F4(pp), out, direction);
}


void func_02017114(void *pokemon, McssAddWork *out, u32 direction)
{
    u32 species = func_02017E88(pokemon, 5, 0);
    u32 form = func_02017E88(pokemon, 0x6F, 0);
    u32 gender = func_02017E88(pokemon, 0x6E, 0);
    u32 isShiny = func_02017EB4(pokemon);
    u32 isEgg = func_02017E88(pokemon, 0x4C, 0);

    func_02017168(species, form, gender, isShiny, isEgg, out, direction);
}


void func_02017168(u32 species, u32 form, u32 gender, u32 isShiny, u32 isEgg, McssAddWork *out,
                   u32 direction)
{
    out->arcId = func_0202D060();
    out->textureMember = func_0202D09C(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->paletteMember = func_0202D0D4(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->cellMember = func_0202D110(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->cellAnimMember = func_0202D144(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->multiCellMember = func_0202D178(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->multiCellAnimMember = func_0202D1AC(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->cellHeaderMember = func_0202D1E0(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->heapMode = 0;
}


/*
 * Promoted from src/pending/ during a shard verify sweep: all six of its
 * previously witness-less callees (func_0202D5F8, func_0202D640,
 * func_0202D664, func_0202D688, func_0202D6AC, func_0202D6D0) are now
 * EXACT matched entries elsewhere in the tree, so the `matched` class
 * resolves every site that was stuck wildcarded and this closes to
 * EXACT with no change to the C.
 *
 * This is the twin of func_02017168 in src/matched/unit_02017100.c: the
 * same nine word record, built from a pair of pointers instead of from
 * five save block fields, with 1 in the last word where the other
 * writes 0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02017214.c \
 *       --addr 0x02017214 --thumb
 */
void func_02017214(void *trainerClass, McssAddWork *out, void *trainerGender)
{
    out->arcId = func_0202D5CC((u32)trainerGender);
    out->textureMember = func_0202D5F8((u32)trainerClass, (u32)trainerGender);
    out->paletteMember = func_0202D61C((u32)trainerClass, (u32)trainerGender);
    out->cellMember = func_0202D640((u32)trainerClass, (u32)trainerGender);
    out->cellAnimMember = func_0202D664((u32)trainerClass, (u32)trainerGender);
    out->multiCellMember = func_0202D688((u32)trainerClass, (u32)trainerGender);
    out->multiCellAnimMember = func_0202D6AC((u32)trainerClass, (u32)trainerGender);
    out->cellHeaderMember = func_0202D6D0((u32)trainerClass, (u32)trainerGender);
    out->heapMode = 1;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017270.c \
 *       --func func_02017270 --addr 0x02017270 --cc 1.1p1 --thumb
 */
McssWork *func_02017270(McssSys *sys, void *pp, u32 direction, fx32 x, fx32 y, fx32 z)
{
    McssAddWork addWork;

    func_020172AC(sys, func_02017E1C(pp, 0, 0));
    func_02017100(pp, &addWork, direction);
    return func_020159C8(sys, x, y, z, &addWork);
}


/*
 * A four-instruction tail call: the second argument is replaced by a function
 * pointer (the pool word 0x020172BD, the Thumb bit set), the first and third
 * pass through, and the target is loaded from the pool and branched to with
 * `bx r3`.  The callee is the label-less Thumb leaf src/matched/sub_02014CF0.c.
 *
 * The `symbols:` line is load-bearing.  Without it the name `func_02014CF0`
 * carries the address but the naming convention can only guess the ISA, and
 * an address no `func_` label was traced at is guessed ARM -- so the site
 * was reported as "02014CF0 (arm, from name) has no witness" and the file sat
 * at MATCH, because sub_02014CF0 is a Thumb manifest entry and the `matched`
 * class refuses an ISA that does not agree with it.  Declaring the ISA
 * explicitly (origin "header") resolves the word to 0x02014CF1, which is what
 * the image holds.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020172AC.c \
 *       --func func_020172AC --addr 0x020172AC --cc 1.1p1 --thumb
 */
void func_020172AC(McssSys *sys, u32 personality)
{
    sub_02014CF0(sys, func_020172BC, personality);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020172BC.c \
 *       --func func_020172BC --addr 0x020172BC --cc 1.1p1 --thumb
 */
u32 func_020172BC(const McssAddWork *addWork, McssTransTask *task, u32 personality)
{
    if (addWork->cellHeaderMember == 0x1994) {
        func_020172D8(task->texData->rawData, personality);
    }
    return 1;
}


/*
 * mcss.c.  Walks four (x, y) offset lists and bumps the matching nibble of
 * two bytes per point.  Lever (wave 16): the read-modify-write of a0[p] is a
 * compound assignment `a0[p] += 0x50` / `a0[p] += 5`; the spelled-out
 * `a0[p] = (u8)(val + 0x50)` left a three-register rotation (a0/k/b0, 47
 * bytes out) that no declaration order, scope, type or permuter run moved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020172D8.c \
 *       --func func_020172D8 --addr 0x020172D8 --cc 1.1p1 --thumb
 */
void func_020172D8(u8 *pixels, u32 personality)
{
    const u8 *spotTable;
    s32 spotSet;
    s32 spotIdx;
    s32 spotOfs[2];

    for (spotSet = 0; spotSet < 4; spotSet++) {
        spotTable = sSpindaSpotCoords[spotSet];
        spotIdx = 0;
        if (spotTable[0] != 0xff) {
            spotOfs[1] = (personality & 0xf) - 8;
            spotOfs[0] = ((personality & 0xf0) >> 4) - 8;
            do {
                u8 spotX = (u8)(spotOfs[1] + spotTable[spotIdx * 2]);
                u32 spotY = (u8)(spotOfs[0] + spotTable[spotIdx * 2 + 1]);
                u32 pixelIdx[2];
                s32 half;
                pixelIdx[0] = ((u32)spotX >> 1) + (spotY << 7);
                pixelIdx[1] = ((u32)spotX >> 1) + ((spotY + 0x28) << 7);
                for (half = 0; half < 2; half++) {
                    if ((spotX & 1) != 0) {
                        u32 pixelOfs = pixelIdx[half];
                        u8 pixel = pixels[pixelOfs];
                        s32 nibble = pixel & 0xf0;
                        if (nibble >= 0x10 && nibble <= 0x30) {
                            pixels[pixelOfs] += 0x50;
                        }
                    } else {
                        u32 pixelOfs = pixelIdx[half];
                        u8 pixel = pixels[pixelOfs];
                        s32 nibble = 0xf & pixel;
                        if (nibble >= 1 && nibble <= 3) {
                            pixels[pixelOfs] += 5;
                        }
                    }
                }
                spotIdx = (u8)(spotIdx + 1);
            } while (spotTable[spotIdx * 2] != 0xff);
        }
        personality = personality >> 8;
    }
}


int func_020173B4(McssWork *work){ int ret = func_02015F2C((int)work, (int)(work + 0), (int)0x20173C9, (int)1); return ret; }


/*
 * A four-byte tail call: the pool word 0x02016381 (Thumb) is loaded and
 * `bx r3` jumps with the incoming r0 untouched, i.e. sub_02016380 itself.
 * Its witness is the EXACT entry for 0x02016380 in this same shard - the
 * `matched` class - which is what makes the pool word resolve.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020173C8.c \
 *       --func sub_020173C8 --addr 0x020173C8 --cc 1.1p1 --thumb
 */
void sub_020173C8(McssWork *work)
{
    sub_02016380(work);
}
