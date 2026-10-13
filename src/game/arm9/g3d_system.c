/*
 * file:     g3d_system.c
 * unit:     yes
 * function: func_02046440, func_02046788, func_020467EC, func_02046858, func_02046A94, func_02046AFC, func_02046B40, func_02046BE0, func_02046BFC, func_02046C10, func_02046C24, func_02046C88, func_02046C94, sub_02046C9C, func_02046CE0, func_02046DB8, func_02046E24, func_02046E90, func_02046EFC, func_02046F48, func_02046F50, func_02046FCC, func_02046FF8, func_020470A8, func_020470D0, func_02047180, func_02047204, func_02047250, func_02047260, func_020472F8, func_02047348, func_02047388, func_020473B8, func_020473D8, func_020473EC, func_02047400, func_02047504, func_0204754C, func_02047554, func_0204755C, func_02047564, func_0204762C, func_02047674, func_0204767C, func_02047738, func_02047788, func_02047790, func_0204779C, func_020477A4, func_020477D4, func_02047804, func_02047828, func_0204784C, func_02047888, func_020478B8, func_02047910, func_02047964, func_02047970, func_02047990, func_020479D8, func_02047A60, func_02047AC8, func_02047B4C, func_02047C04, func_02047C8C, func_02047CE4
 * address:  0x02046440
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from g3d_system.c at 0x02047CFC (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   _G3dSystem                       0x02146A5C  data
 *   G3D_SYSTEM_FileName              0x020A7EA8  data
 *   _DefaultLight                    0x020A1300  data
 *   _DefaultProjection               0x020A1308  data
 *   _DefaultLookAt                   0x020A1328  data
 *   FX_SinCosTable_                  0x020A1B38  data
 *   NNS_G3dGlb                       0x02148B4C  data
 *   NNS_GfdDefaultFuncAllocTexVram   0x020A8140  data
 *   NNS_GfdDefaultFuncFreeTexVram    0x020A8144  data
 *   NNS_GfdDefaultFuncAllocPlttVram  0x020A8148  data
 *   NNS_GfdDefaultFuncFreePlttVram   0x020A814C  data
 *   func_02030734      0x02030734  arm
 *   func_020307B0      0x020307B0  arm
 *   func_020307C8      0x020307C8  arm
 *   func_020307E0      0x020307E0  arm
 *   func_02030BBC      0x02030BBC  arm
 *   func_02030BC8      0x02030BC8  arm
 *   func_02048F60      0x02048F60  arm
 *   func_02048F9C      0x02048F9C  arm
 *   func_02049250      0x02049250  arm
 *   func_020613D8      0x020613D8  arm
 *   func_0206210C      0x0206210C  arm
 *   func_02062114      0x02062114  arm
 *   func_0206246C      0x0206246C  arm
 *   func_02062474      0x02062474  arm
 *   func_02069C74      0x02069C74  arm
 *   func_02069D14      0x02069D14  arm
 *   func_02069E88      0x02069E88  arm
 *   func_02069F7C      0x02069F7C  arm
 *   func_02069FD0      0x02069FD0  arm
 *   func_02069FE4      0x02069FE4  arm
 *   func_02069FF8      0x02069FF8  arm
 *   func_0206A00C      0x0206A00C  arm
 *   func_0206A0C4      0x0206A0C4  arm
 *   func_0206A110      0x0206A110  arm
 *   func_0206A124      0x0206A124  arm
 *   func_0206A12C      0x0206A12C  arm
 *   func_0206A17C      0x0206A17C  arm
 *   func_0206A2CC      0x0206A2CC  arm
 *   func_0206A4AC      0x0206A4AC  arm
 *   func_0206A700      0x0206A700  arm
 *   func_0206A854      0x0206A854  arm
 *   func_0206A884      0x0206A884  arm
 *   func_0206A8FC      0x0206A8FC  arm
 *   func_0206A9DC      0x0206A9DC  arm
 *   func_0206AA0C      0x0206AA0C  arm
 *   func_0206AA3C      0x0206AA3C  arm
 *   func_0206AA78      0x0206AA78  arm
 *   func_0206B6A4      0x0206B6A4  arm
 *   func_0206DB24      0x0206DB24  arm
 *   func_0206DB40      0x0206DB40  arm
 *   func_0206DB60      0x0206DB60  arm
 *   func_0206DB80      0x0206DB80  arm
 *   func_0206DDA4      0x0206DDA4  arm
 *   func_0206DF14      0x0206DF14  arm
 *   func_0206E348      0x0206E348  arm
 *   func_0206E358      0x0206E358  arm
 *   func_0206E364      0x0206E364  arm
 *   func_0206E388      0x0206E388  arm
 *   func_0206E954      0x0206E954  arm
 *   func_0206E964      0x0206E964  arm
 *   func_0206E9A4      0x0206E9A4  arm
 *   func_0207C1D0      0x0207C1D0  arm
 *   func_0207C408      0x0207C408  arm
 *   func_0207C554      0x0207C554  arm
 *   func_0207DA8C      0x0207DA8C  arm
 *   func_0207DEA4      0x0207DEA4  arm
 *   G3X_InitMtxStack   0x0207DB1C  arm
 *   G3X_SetFog         0x0207DC44  arm
 *   G3X_SetClearColor  0x0207DD24  arm
 *   MTX_LookAt         0x0207BCA0  arm
 *   MI_Copy36B         0x02082B60  arm
 *   DC_FlushRange      0x020862F0  arm
 */
/*
 * The 3D system: brings up the geometry engine and the texture and palette
 * VRAM managers, keeps the projection, lights and camera, loads NitroSystem
 * resource files (models, textures, animations), builds render objects,
 * animations and objects on top of them, and draws objects.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;
typedef int            BOOL;
typedef s32            fx32;
typedef s16            fx16;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 m[3][3]; } MtxFx33;
typedef struct { fx32 m[4][3]; } MtxFx43;
typedef struct { fx32 m[4][4]; } MtxFx44;

#define reg_G3X_DISP3DCNT   (*(volatile u16 *)0x04000060)
#define reg_G3_SWAP_BUFFERS (*(volatile u32 *)0x04000540)
#define reg_G3_VIEWPORT     (*(volatile u32 *)0x04000580)

/* geometry command codes (G3OP_*) */
#define G3OP_PUSH_MTX     0x11
#define G3OP_POP_MTX      0x12
#define G3OP_SCALE        0x1B
#define G3OP_POLYGON_ATTR 0x29
#define G3OP_BEGIN_VTXS   0x40
#define G3OP_END_VTXS     0x41
#define G3OP_BOX_TEST     0x70

/* resource file signatures */
#define SIGNATURE_BMD0 0x30444D42
#define SIGNATURE_BTX0 0x30585442
#define SIGNATURE_BVA0 0x30415642
#define SIGNATURE_BMA0 0x30414D42
#define SIGNATURE_BCA0 0x30414342
#define SIGNATURE_BTA0 0x30415442
#define SIGNATURE_BTP0 0x30505442

struct ArcHandle;

/* NitroSystem types, only the parts this file reads */
typedef struct {
    const void *funcs;
    void       *heap;
    u32         heapParam1;
    u32         heapParam2;
} NNSFndAllocator;

typedef struct {
    u32 signature;
    u16 byteOrder;
    u16 version;
    u32 fileSize;
    u16 headerSize;
    u16 dataBlocks;
} NNSG3dResFileHeader;

typedef struct {
    u32 kind;
    u32 size;
} NNSG3dResDataBlockHeader;

typedef struct {
    u8  revision;
    u8  numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
} NNSG3dResDict;

typedef struct {
    NNSG3dResDataBlockHeader header;
    NNSG3dResDict            dict;
} NNSG3dResMdlSet;

typedef struct {
    u8   sbcType;
    u8   scalingRule;
    u8   texMtxMode;
    u8   numNode;
    u8   numMat;
    u8   numShp;
    u8   firstUnusedMtxStackID;
    u8   dummy_;
    fx32 posScale;
    fx32 invPosScale;
    u16  numVertex;     /* 0x10 */
    u16  numPolygon;
    u16  numTriangle;
    u16  numQuad;
    fx16 boxX;          /* 0x18 */
    fx16 boxY;
    fx16 boxZ;
    fx16 boxW;
    fx16 boxH;
    fx16 boxD;
    fx32 boxPosScale;   /* 0x24 */
    fx32 boxInvPosScale;
} NNSG3dResMdlInfo;

typedef struct {
    u32              size;
    u32              ofsSbc;
    u32              ofsMat;
    u32              ofsShp;
    u32              ofsEvpMtx;
    NNSG3dResMdlInfo info;  /* 0x14 */
} NNSG3dResMdl;

typedef struct {
    u32 vramKey;
    u16 sizeTex;
    u16 ofsDict;
    u16 flag;       /* bit 0: loaded */
    u16 dummy_;
    u32 ofsTex;
} NNSG3dResTexInfo;

typedef struct {
    u32 vramKey;
    u16 sizeTex;
    u16 ofsDict;
    u16 flag;       /* bit 0: loaded, bit 15: 4-color palettes */
    u16 dummy_;
    u32 ofsTex;
    u32 ofsTexPlttIdx;
} NNSG3dResTex4x4Info;

typedef struct {
    u32 vramKey;
    u16 sizePltt;
    u16 flag;       /* bit 0: loaded */
    u16 ofsDict;
    u16 dummy_;
    u32 ofsPlttData;
} NNSG3dResPlttInfo;

typedef struct {
    NNSG3dResDataBlockHeader header;
    NNSG3dResTexInfo         texInfo;       /* 0x08 */
    NNSG3dResTex4x4Info      tex4x4Info;    /* 0x18 */
    NNSG3dResPlttInfo        plttInfo;      /* 0x2C */
} NNSG3dResTex;

typedef struct {
    u32 anmHeader;
    u16 numFrame;
} NNSG3dResAnmCommon;

typedef struct NNSG3dAnmObj {
    fx32                      frame;
    fx32                      ratio;
    const NNSG3dResAnmCommon *resAnm;
} NNSG3dAnmObj;

typedef struct NNSG3dRenderObj {
    u32           flag;
    NNSG3dResMdl *resMdl;
} NNSG3dRenderObj;

typedef struct {
    fx16 x;
    fx16 y;
    fx16 z;
    fx16 width;
    fx16 height;
    fx16 depth;
} GXBoxTestParam;

typedef struct {
    u32     cmd0;
    u32     mtxmode_proj;
    MtxFx44 projMtx;
    u32     mtxmode_posvec;
    MtxFx43 cameraMtx;
    u32     cmd1;
    u32     lightVec[4];
    u32     cmd2;
    u32     prmMatColor0;
    u32     prmMatColor1;
    u32     prmPolygonAttr;
    u32     prmViewPort;
    u32     cmd3;
    u32     lightColor[4];
    u32     cmd4;
    MtxFx33 prmBaseRot;
    VecFx32 prmBaseTrans;
    VecFx32 prmBaseScale;
    u32     prmTexImageParam;
    u32     flag;
    MtxFx43 invCameraMtx;
    MtxFx43 srtCameraMtx;
    MtxFx43 invSrtCameraMtx;
    MtxFx43 invBaseMtx;
    MtxFx44 invProjMtx;
    MtxFx44 invCameraProjMtx;
    VecFx32 camPos;
    VecFx32 camUp;
    VecFx32 camTarget;
} NNSG3dGlb;

#include "g3d_system_types.h"

extern void *func_02030734(u16 heapId, u32 size, int clear, const char *file, int line);
extern void  func_020307B0(void *memory);
extern void  func_020307C8(NNSFndAllocator *allocator, u16 heapId, u32 align);
extern void  func_020307E0(void *memory, u32 newSize);
extern void *func_02030BBC(u32 size);
extern int   func_02030BC8(u32 buffer);
extern void *func_02048F60(u32 arcId, u32 dataId, u16 heapId);
extern void *func_02048F9C(const char *path, u32 dataId, u16 heapId);
extern void *func_02049250(struct ArcHandle *arc, u32 dataId, u16 heapId);
extern void  func_020613D8(u32 size, u32 useAsDefault);
extern int   func_0206210C(int numBlocks);
extern void  func_02062114(u32 size, u32 size4x4, u32 work, u32 workSize, u32 useAsDefault);
extern int   func_0206246C(int numBlocks);
extern void  func_02062474(u32 size, u32 work, u32 workSize, u32 useAsDefault);
extern void  func_02069C74(NNSG3dAnmObj *anmObj, void *anm, NNSG3dResMdl *resMdl, NNSG3dResTex *tex);
extern void  func_02069D14(NNSG3dRenderObj *rndObj, void *resMdl);
extern void  func_02069E88(NNSG3dRenderObj *rndObj, NNSG3dAnmObj *anmObj);
extern void  func_02069F7C(NNSG3dRenderObj *rndObj, NNSG3dAnmObj *anmObj);
extern u32   func_02069FD0(NNSG3dResTex *tex);
extern u32   func_02069FE4(NNSG3dResTex *tex);
extern void  func_02069FF8(NNSG3dResTex *tex, u32 texKey, u32 tex4x4Key);
extern void  func_0206A00C(NNSG3dResTex *tex, BOOL exec);
extern void  func_0206A0C4(NNSG3dResTex *tex, u32 *texKey, u32 *tex4x4Key);
extern u32   func_0206A110(NNSG3dResTex *tex);
extern void  func_0206A124(NNSG3dResTex *tex, u32 plttKey);
extern void  func_0206A12C(NNSG3dResTex *tex, BOOL exec);
extern u32   func_0206A17C(NNSG3dResTex *tex);
extern void  func_0206A2CC(void *resMdl, NNSG3dResTex *tex);
extern void  func_0206A4AC(void *resMdl, NNSG3dResTex *tex);
extern void  func_0206A700(void);
extern void  func_0206A854(void);
extern void  func_0206A884(void);
extern void  func_0206A8FC(void);
extern void  func_0206A9DC(VecFx32 *trans);
extern void  func_0206AA0C(VecFx32 *scale);
extern void  func_0206AA3C(int lightIdx, s16 x, s16 y, s16 z);
extern void  func_0206AA78(int lightIdx, u32 color);
extern void  func_0206B6A4(NNSG3dRenderObj *rndObj);
extern u32   func_0206DB24(void);
extern void  func_0206DB40(void *buffer);
extern void *func_0206DB60(void);
extern void  func_0206DB80(void);
extern void  func_0206DDA4(u32 cmd, const void *params, u32 numParams);
extern void  func_0206DF14(void);
extern NNSG3dRenderObj *func_0206E348(NNSFndAllocator *allocator);
extern void  func_0206E358(NNSFndAllocator *allocator, NNSG3dRenderObj *rndObj);
extern NNSG3dAnmObj *func_0206E364(NNSFndAllocator *allocator, void *anm, NNSG3dResMdl *resMdl);
extern void  func_0206E388(NNSFndAllocator *allocator, NNSG3dAnmObj *anmObj);
extern NNSG3dResMdlSet *func_0206E954(void *file);
extern NNSG3dResTex *func_0206E964(void *file);
extern void *func_0206E9A4(void *file, u32 anmIdx);
extern void  func_0207C1D0(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
extern void  func_0207C408(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
extern void  func_0207C554(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
extern void  func_0207DA8C(void);
extern int   func_0207DEA4(s32 *result);
extern void  G3X_InitMtxStack(void);
extern void  G3X_SetFog(BOOL enable, int mode, int slope, int offset);
extern void  G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, BOOL fog);
extern void  MTX_LookAt(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, MtxFx43 *mtx);
extern void  MI_Copy36B(const void *src, void *dst);
extern void  DC_FlushRange(void *addr, u32 size);

extern G3dSystem _G3dSystem;
extern char G3D_SYSTEM_FileName[];
extern const G3dLight _DefaultLight;
extern const G3dProjection _DefaultProjection;
extern const G3dLookAt _DefaultLookAt;
extern const s16 FX_SinCosTable_[];
extern NNSG3dGlb NNS_G3dGlb;
extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(u32 size, BOOL is4x4comp, u32 opt);
extern int (*NNS_GfdDefaultFuncFreeTexVram)(u32 key);
extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(u32 size, BOOL is4pltt, u32 opt);
extern int (*NNS_GfdDefaultFuncFreePlttVram)(u32 key);

void func_02046440(u32 texManMode, u32 texManSize, u32 plttManMode, u32 plttManSize, u16 geBufSize, s16 heapId, void (*setUpFunc)(void));
void func_02046788(void);
void func_020467EC(G3dProjection *proj);
void func_02046858(const G3dProjection *proj);
void func_02046A94(u32 lightIdx, const G3dLight *light);
void func_02046AFC(G3dLookAt *lookAt);
void func_02046B40(const G3dLookAt *lookAt);
void func_02046BE0(u32 sortMode, u32 bufferMode);
u32 func_02046BFC(void);
u32 func_02046C10(void);
void func_02046C24(u32 mode);
void func_02046C88(void);
u32 func_02046C94(void);
void sub_02046C9C(G3dResource *res, u32 kind, void *file);
void func_02046CE0(G3dResource *res, NNSG3dResFileHeader *file);
G3dResource *func_02046DB8(u32 arcId, u32 dataId);
G3dResource *func_02046E24(struct ArcHandle *arc, u32 dataId);
G3dResource *func_02046E90(const char *path, u32 dataId);
void func_02046EFC(G3dResource *res);
void *func_02046F48(G3dResource *res);
u32 func_02046F50(G3dResource *res, u32 kind);
void func_02046FCC(G3dResource *res);
BOOL func_02046FF8(G3dResource *res);
BOOL func_020470A8(G3dResource *res);
BOOL func_020470D0(G3dResource *res);
BOOL func_02047180(G3dResource *res);
BOOL func_02047204(G3dResource *res);
NNSG3dResTex *func_02047250(G3dResource *res);
BOOL func_02047260(NNSG3dResTex *tex, u32 *texKey, u32 *tex4x4Key);
BOOL func_020472F8(NNSG3dResTex *tex, u32 *plttKey);
BOOL func_02047348(G3dResource *res);
u32 func_02047388(G3dResource *res);
u32 func_020473B8(G3dResource *res);
void *func_020473D8(G3dResource *res);
void *func_020473EC(G3dResource *res);
G3dRender *func_02047400(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
void func_02047504(G3dRender *render);
G3dResource *func_0204754C(G3dRender *render);
G3dResource *func_02047554(G3dRender *render);
NNSG3dRenderObj *func_0204755C(G3dRender *render);
G3dAnime *func_02047564(G3dRender *render, const G3dResource *anmRes, u32 anmIdx);
void func_0204762C(G3dAnime *anime);
NNSG3dAnmObj *func_02047674(G3dAnime *anime);
G3dObject *func_0204767C(G3dRender *render, G3dAnime **anmTbl, int anmCount);
void func_02047738(G3dObject *obj);
G3dRender *func_02047788(G3dObject *obj);
G3dAnime *func_02047790(G3dObject *obj, int anmIdx);
u16 func_0204779C(G3dObject *obj);
BOOL func_020477A4(G3dObject *obj, u32 anmIdx);
BOOL func_020477D4(G3dObject *obj, u32 anmIdx);
BOOL func_02047804(G3dObject *obj, u16 anmIdx);
BOOL func_02047828(G3dObject *obj, u32 anmIdx, fx32 *frame);
BOOL func_0204784C(G3dObject *obj, u16 anmIdx, const fx32 *frame);
BOOL func_02047888(G3dObject *obj, int anmIdx, fx32 *frameMax);
BOOL func_020478B8(G3dObject *obj, int anmIdx, fx32 step);
BOOL func_02047910(G3dObject *obj, int anmIdx, fx32 step);
void func_02047964(void);
void func_02047970(void);
void func_02047990(void);
void func_020479D8(void);
void func_02047A60(G3dObject *obj, G3dObjectStatus *status);
BOOL func_02047AC8(G3dObject *obj, G3dObjectStatus *status);
BOOL func_02047B4C(G3dObject *obj);
BOOL func_02047C04(const GXBoxTestParam *box);
void func_02047C8C(NNSG3dRenderObj *rndObj);
void func_02047CE4(void);

/*
 * Bring the 3D system up: allocate the work (line 92), set up the geometry
 * engine, the geometry command buffer (at most 0x1800 bytes), the texture and
 * palette VRAM managers (linked-list managers with their own work for mode 0,
 * frame managers otherwise), the default projection, lights and camera, then
 * either call the caller's setup or apply the default display settings.
 *
 * The palette frame-manager branch clears texManagerWork, not
 * plttManagerWork; the image does the same.
 *
 * heapId is s16: as u16 the compiler reloads it from its stack home instead
 * of holding it in r8 across the first allocation.
 */
void func_02046440(u32 texManMode, u32 texManSize, u32 plttManMode, u32 plttManSize,
                   u16 geBufSize, s16 heapId, void (*setUpFunc)(void))
{
    G3dProjection proj;
    G3dLookAt lookAt;
    G3dLight light;
    u32 workSize;

    _G3dSystem.work = func_02030734((u16)heapId, 0xa0, 0, G3D_SYSTEM_FileName, 0x5c);
    _G3dSystem.work->heapId = heapId;
    _G3dSystem.work->texManagerMode = texManMode;
    _G3dSystem.work->plttManagerMode = plttManMode;

    func_0206DF14();
    G3X_InitMtxStack();
    func_0206A700();

    if (geBufSize != 0)
        func_0206DB40(func_02030BBC(geBufSize > 0x1800 ? 0x1800 : geBufSize));

    reg_G3_SWAP_BUFFERS = 2;
    func_020307C8(&_G3dSystem.work->allocator, _G3dSystem.work->heapId, 4);

    if (texManMode == 0) {
        workSize = func_0206210C(texManSize << 7);
        _G3dSystem.work->texManagerWork = func_02030734(_G3dSystem.work->heapId, workSize, 0, G3D_SYSTEM_FileName, 0x7e);
        func_02062114(texManSize << 17, 0, (u32)_G3dSystem.work->texManagerWork, workSize, 1);
    } else {
        func_020613D8((u16)texManSize, 1);
        _G3dSystem.work->texManagerWork = 0;
    }

    if (plttManMode == 0) {
        workSize = func_0206246C(plttManSize << 9);
        _G3dSystem.work->plttManagerWork = func_02030734(_G3dSystem.work->heapId, workSize, 0, G3D_SYSTEM_FileName, 0x8d);
        func_02062474(plttManSize << 14, (u32)_G3dSystem.work->plttManagerWork, workSize, 1);
    } else {
        func_020613D8((u16)(plttManSize << 14), 1);
        _G3dSystem.work->texManagerWork = 0;
    }

    /* sine and cosine of 20 degrees (FX_SinIdx/FX_CosIdx of 0xE38) */
    proj = _DefaultProjection;
    proj.fovySinOrTop = FX_SinCosTable_[(0xE38 >> 4) * 2];
    proj.fovyCosOrBottom = FX_SinCosTable_[(0xE38 >> 4) * 2 + 1];
    func_02046858(&proj);

    light = _DefaultLight;
    func_02046A94(0, &light);
    func_02046A94(1, &light);
    func_02046A94(2, &light);
    func_02046A94(3, &light);

    lookAt = _DefaultLookAt;
    func_02046B40(&lookAt);
    func_02046BE0(0, 1);
    func_02046C24(0);

    if (setUpFunc != 0) {
        setUpFunc();
    } else {
        reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~(0x0002 | 0x3000)) | (0 << 1));
        reg_G3X_DISP3DCNT &= ~(0x0010 | 0x3000);
        reg_G3X_DISP3DCNT &= ~(0x0004 | 0x3000);
        reg_G3X_DISP3DCNT &= ~(0x0008 | 0x3000);
        reg_G3X_DISP3DCNT &= ~(0x0020 | 0x3000);
        G3X_SetFog(0, 0, 0, 0);
        G3X_SetClearColor(0, 0, 0x7fff, 63, 0);
        reg_G3_VIEWPORT = 0xBFFF0000;
    }

    _G3dSystem.work->drawCallback = 0;
    _G3dSystem.work->drawCallbackArg = 0;
}

/*
 * Shut the 3D system down: free the manager works, release the geometry
 * command buffer when one is set, free the work.
 */
void func_02046788(void)
{
    if (_G3dSystem.work->plttManagerWork != 0)
        func_020307B0(_G3dSystem.work->plttManagerWork);
    if (_G3dSystem.work->texManagerWork != 0)
        func_020307B0(_G3dSystem.work->texManagerWork);

    if (func_0206DB24() == 1) {
        func_02030BC8((u32)func_0206DB60());
    }

    func_020307B0(_G3dSystem.work);
    _G3dSystem.work = 0;
}

void func_020467EC(G3dProjection *proj)
{
    proj->type = _G3dSystem.work->projection.type;
    proj->fovySinOrTop = _G3dSystem.work->projection.fovySinOrTop;
    proj->fovyCosOrBottom = _G3dSystem.work->projection.fovyCosOrBottom;
    proj->aspectOrLeft = _G3dSystem.work->projection.aspectOrLeft;
    proj->right = _G3dSystem.work->projection.right;
    proj->nearClip = _G3dSystem.work->projection.nearClip;
    proj->farClip = _G3dSystem.work->projection.farClip;
    proj->scaleW = _G3dSystem.work->projection.scaleW;
}

/* NitroSystem inlines (glbstate_inline.h): set the projection matrix and clear INVPROJ and INVCAMERAPROJ. */
static inline void NNS_G3dGlbPerspectiveW(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW)
{
    func_0207C408(fovySin, fovyCos, aspect, n, f, scaleW, &NNS_G3dGlb.projMtx);
    NNS_G3dGlb.flag &= ~(0x10 | 0x40);
}

static inline void NNS_G3dGlbFrustumW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW)
{
    func_0207C1D0(t, b, l, r, n, f, scaleW, &NNS_G3dGlb.projMtx);
    NNS_G3dGlb.flag &= ~(0x10 | 0x40);
}

static inline void NNS_G3dGlbOrthoW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW)
{
    func_0207C554(t, b, l, r, n, f, scaleW, &NNS_G3dGlb.projMtx);
    NNS_G3dGlb.flag &= ~(0x10 | 0x40);
}

/*
 * Store the projection and load it into the NitroSystem global state:
 * perspective, frustum or orthographic by type; a zero scaleW means
 * FX32_ONE.
 */
void func_02046858(const G3dProjection *proj)
{
    _G3dSystem.work->projection.type = proj->type;
    _G3dSystem.work->projection.fovySinOrTop = proj->fovySinOrTop;
    _G3dSystem.work->projection.fovyCosOrBottom = proj->fovyCosOrBottom;
    _G3dSystem.work->projection.aspectOrLeft = proj->aspectOrLeft;
    _G3dSystem.work->projection.right = proj->right;
    _G3dSystem.work->projection.nearClip = proj->nearClip;
    _G3dSystem.work->projection.farClip = proj->farClip;
    _G3dSystem.work->projection.scaleW = proj->scaleW;

    switch (_G3dSystem.work->projection.type) {
    case 0:
        if (_G3dSystem.work->projection.scaleW == 0) {
            NNS_G3dGlbPerspectiveW(_G3dSystem.work->projection.fovySinOrTop, _G3dSystem.work->projection.fovyCosOrBottom,
                _G3dSystem.work->projection.aspectOrLeft, _G3dSystem.work->projection.nearClip,
                _G3dSystem.work->projection.farClip, 0x1000);
        } else {
            NNS_G3dGlbPerspectiveW(_G3dSystem.work->projection.fovySinOrTop, _G3dSystem.work->projection.fovyCosOrBottom,
                _G3dSystem.work->projection.aspectOrLeft, _G3dSystem.work->projection.nearClip,
                _G3dSystem.work->projection.farClip, _G3dSystem.work->projection.scaleW);
        }
        break;
    case 1:
        if (_G3dSystem.work->projection.scaleW == 0) {
            NNS_G3dGlbFrustumW(_G3dSystem.work->projection.fovySinOrTop, _G3dSystem.work->projection.fovyCosOrBottom,
                _G3dSystem.work->projection.aspectOrLeft, _G3dSystem.work->projection.right,
                _G3dSystem.work->projection.nearClip, _G3dSystem.work->projection.farClip, 0x1000);
        } else {
            NNS_G3dGlbFrustumW(_G3dSystem.work->projection.fovySinOrTop, _G3dSystem.work->projection.fovyCosOrBottom,
                _G3dSystem.work->projection.aspectOrLeft, _G3dSystem.work->projection.right,
                _G3dSystem.work->projection.nearClip, _G3dSystem.work->projection.farClip,
                _G3dSystem.work->projection.scaleW);
        }
        break;
    case 2:
        if (_G3dSystem.work->projection.scaleW == 0) {
            NNS_G3dGlbOrthoW(_G3dSystem.work->projection.fovySinOrTop, _G3dSystem.work->projection.fovyCosOrBottom,
                _G3dSystem.work->projection.aspectOrLeft, _G3dSystem.work->projection.right,
                _G3dSystem.work->projection.nearClip, _G3dSystem.work->projection.farClip, 0x1000);
        } else {
            NNS_G3dGlbOrthoW(_G3dSystem.work->projection.fovySinOrTop, _G3dSystem.work->projection.fovyCosOrBottom,
                _G3dSystem.work->projection.aspectOrLeft, _G3dSystem.work->projection.right,
                _G3dSystem.work->projection.nearClip, _G3dSystem.work->projection.farClip,
                _G3dSystem.work->projection.scaleW);
        }
        break;
    }
}

/*
 * Store light lightIdx and load its vector and color into the NitroSystem
 * global state. The store goes through the work base plus lightIdx * 8 and
 * lights[0]; the loads index lights[] directly.
 */
void func_02046A94(u32 lightIdx, const G3dLight *light)
{
    G3dSystemWork *slot = (G3dSystemWork *)((u8 *)_G3dSystem.work + lightIdx * 8);

    slot->lights[0].vecX = light->vecX;
    slot->lights[0].vecY = light->vecY;
    slot->lights[0].vecZ = light->vecZ;
    slot->lights[0].color = light->color;

    func_0206AA3C(lightIdx, _G3dSystem.work->lights[lightIdx].vecX,
                  _G3dSystem.work->lights[lightIdx].vecY,
                  _G3dSystem.work->lights[lightIdx].vecZ);
    func_0206AA78(lightIdx, _G3dSystem.work->lights[lightIdx].color);
}

void func_02046AFC(G3dLookAt *lookAt)
{
    G3dSystemWork *work = _G3dSystem.work;

    lookAt->camPos = work->lookAt.camPos;
    lookAt->camUp = work->lookAt.camUp;
    lookAt->target = work->lookAt.target;
}

/*
 * Store the camera and load it into the global state. The second half is
 * NNS_G3dGlbLookAt written out: calling the inline (below) here allocates
 * the registers differently.
 */
void func_02046B40(const G3dLookAt *lookAt)
{
    G3dSystemWork *work = _G3dSystem.work;

    work->lookAt.camPos = lookAt->camPos;
    work->lookAt.camUp = lookAt->camUp;
    work->lookAt.target = lookAt->target;
    NNS_G3dGlb.camPos = work->lookAt.camPos;
    NNS_G3dGlb.camUp = work->lookAt.camUp;
    NNS_G3dGlb.camTarget = work->lookAt.target;
    MTX_LookAt(&work->lookAt.camPos, &work->lookAt.camUp, &work->lookAt.target, &NNS_G3dGlb.cameraMtx);
    NNS_G3dGlb.flag &= ~0xE8u;
}

void func_02046BE0(u32 sortMode, u32 bufferMode)
{
    _G3dSystem.work->swapSortMode = sortMode;
    _G3dSystem.work->swapBufferMode = bufferMode;
}

u32 func_02046BFC(void)
{
    return _G3dSystem.work->texManagerMode;
}

u32 func_02046C10(void)
{
    return _G3dSystem.work->plttManagerMode;
}

/*
 * Select the function that flushes the NitroSystem global state before a
 * draw: modes 1 and 2 have their own, mode 0 and every other value use
 * func_02046C88.
 */
void func_02046C24(u32 mode)
{
    switch (mode) {
    case 0:
    default:
        _G3dSystem.work->glbFlushFunc = func_02046C88;
        break;
    case 1:
        _G3dSystem.work->glbFlushFunc = func_0206A884;
        break;
    case 2:
        _G3dSystem.work->glbFlushFunc = func_0206A8FC;
        break;
    }
}

void func_02046C88(void)
{
    func_0206A854();
}

u32 func_02046C94(void)
{
    return sizeof(G3dResource);
}

/* Fill a resource header for a file of a known kind. */
void sub_02046C9C(G3dResource *res, u32 kind, void *file)
{
    switch (kind) {
    case G3D_RES_KIND_MDL:
        res->type = G3D_RES_TYPE_MDL;
        break;
    case G3D_RES_KIND_TEX:
        res->type = G3D_RES_TYPE_TEX;
        break;
    case G3D_RES_KIND_ANM:
        res->type = G3D_RES_TYPE_ANM;
        break;
    }

    res->file = file;
    res->magic = G3D_RESOURCE_MAGIC;
}

/*
 * Fill a resource header from the file signature. The case bodies are in
 * source order (BMD0, BTX0, then the animations), not in value order.
 */
void func_02046CE0(G3dResource *res, NNSG3dResFileHeader *file)
{
    switch (file->signature) {
    case SIGNATURE_BMD0:
        if (func_0206E964(file) == 0) {
            res->type = G3D_RES_TYPE_MDL;
        } else {
            res->type = G3D_RES_TYPE_MDLTEX;
        }
        break;
    case SIGNATURE_BTX0:
        res->type = G3D_RES_TYPE_TEX;
        break;
    case SIGNATURE_BVA0:
    case SIGNATURE_BMA0:
    case SIGNATURE_BCA0:
    case SIGNATURE_BTA0:
    case SIGNATURE_BTP0:
        res->type = G3D_RES_TYPE_ANM;
        break;
    default:
        res->type = G3D_RES_TYPE_NONE;
        break;
    }
    res->file = file;
    res->magic = G3D_RESOURCE_MAGIC;
}

/* Load a resource file from an archive. */
G3dResource *func_02046DB8(u32 arcId, u32 dataId)
{
    G3dResource *res = func_02030734(_G3dSystem.work->heapId, 8, 0, G3D_SYSTEM_FileName, 0x2b4);

    func_02046CE0(res, func_02048F60(arcId, dataId, _G3dSystem.work->heapId));
    return res;
}

/* Load a resource file through an open archive handle. */
G3dResource *func_02046E24(struct ArcHandle *arc, u32 dataId)
{
    G3dResource *res = func_02030734(_G3dSystem.work->heapId, 8, 0, G3D_SYSTEM_FileName, 0x2c8);

    func_02046CE0(res, func_02049250(arc, dataId, _G3dSystem.work->heapId));
    return res;
}

/* Load a resource file from an archive given by path. */
G3dResource *func_02046E90(const char *path, u32 dataId)
{
    G3dResource *res = func_02030734(_G3dSystem.work->heapId, 8, 0, G3D_SYSTEM_FileName, 0x2dc);

    func_02046CE0(res, func_02048F9C(path, dataId, _G3dSystem.work->heapId));
    return res;
}

void func_02046EFC(G3dResource *res)
{
    if (res == 0) {
        return;
    }
    if (res->magic != G3D_RESOURCE_MAGIC) {
        return;
    }
    res->magic = G3D_RESOURCE_MAGIC - 1;
    if (res->file != 0) {
        func_020307B0(res->file);
        res->file = 0;
    }
    func_020307B0(res);
}

void *func_02046F48(G3dResource *res)
{
    return res->file;
}

/*
 * Whether the resource holds data of the given kind: a model (MDLTEX or
 * MDL), a texture (MDLTEX or TEX) or an animation. The model test is written
 * as a range on type - 1 (`+ 0xFFFF` after the halfword narrowing).
 */
u32 func_02046F50(G3dResource *res, u32 kind)
{
    u16 type = res->type;

    switch (kind) {
    case G3D_RES_KIND_NONE:
        return type == G3D_RES_TYPE_NONE;
    case G3D_RES_KIND_MDL:
        return (u16)(type + 0xFFFF) <= 1;
    case G3D_RES_KIND_TEX:
        return type == G3D_RES_TYPE_MDLTEX || type == G3D_RES_TYPE_TEX;
    case G3D_RES_KIND_ANM:
        return type == G3D_RES_TYPE_ANM;
    }
    return 0;
}

/* Cut the texel data off the end of the file once it is in VRAM. */
void func_02046FCC(G3dResource *res)
{
    void         *file = res->file;
    NNSG3dResTex *tex = func_0206E964(file);

    func_020307E0(file, (u32)((u8 *)tex + tex->texInfo.ofsTex - (u8 *)file));
}

/*
 * Allocate texture and palette VRAM for the resource's texture block, set the
 * keys and load the texels and palettes. The first guard exits through the
 * shared epilogue (a plain `return 0` there is if-converted).
 */
BOOL func_02046FF8(G3dResource *res)
{
    u32 texKey;
    u32 tex4x4Key;
    u32 plttKey;
    NNSG3dResFileHeader *file;
    NNSG3dResTex *tex;

    file = res->file;
    tex = func_0206E964(file);
    if (tex == 0)
        goto fail;
    if (func_02047260(tex, &texKey, &tex4x4Key) == 0)
        return 0;
    if (func_020472F8(tex, &plttKey) == 0)
        return 0;
    func_02069FF8(tex, texKey, tex4x4Key);
    func_0206A124(tex, plttKey);
    DC_FlushRange(file, file->fileSize);
    func_0206A00C(tex, 1);
    func_0206A12C(tex, 1);
    return 1;
fail:
    return 0;
}

/* Load the texture into VRAM, then cut the texels off the file. */
BOOL func_020470A8(G3dResource *res)
{
    if (func_02046FF8(res) == 0) {
        return 0;
    }
    func_02046FCC(res);
    return 1;
}

/*
 * Release the texture's VRAM keys and free the VRAM. The two "loaded" flags
 * are ints set to 1 in the body (the boolean form gives a movne/moveq pair
 * each), and the palette free takes the release call's result directly so
 * the function pointer goes to r1.
 */
BOOL func_020470D0(G3dResource *res)
{
    NNSG3dResTex *tex;
    int texLoaded;
    int tex4x4Loaded;
    u32 texKey;
    u32 tex4x4Key;

    tex = func_0206E964(res->file);
    texLoaded = 0;
    tex4x4Loaded = 0;
    if (tex->texInfo.flag & 1)
        texLoaded = 1;
    if (tex->tex4x4Info.flag & 1)
        tex4x4Loaded = 1;
    func_0206A0C4(tex, &texKey, &tex4x4Key);
    if (texLoaded)
        NNS_GfdDefaultFuncFreeTexVram(texKey);
    if (tex4x4Loaded)
        NNS_GfdDefaultFuncFreeTexVram(tex4x4Key);
    if ((tex->plttInfo.flag & 1) != 0 && tex->plttInfo.sizePltt != 0)
        NNS_GfdDefaultFuncFreePlttVram(func_0206A17C(tex));
    return 1;
}

/* Allocate texture and palette VRAM and set the keys, without loading. */
BOOL func_02047180(G3dResource *res)
{
    NNSG3dResTex *tex;
    u32 texKey;
    u32 tex4x4Key;
    u32 plttKey;

    tex = func_0206E964(res->file);
    if (tex == 0)
        goto fail;
    if (func_02047260(tex, &texKey, &tex4x4Key) == 0)
        return 0;
    if (func_020472F8(tex, &plttKey) == 0)
        return 0;
    func_02069FF8(tex, texKey, tex4x4Key);
    func_0206A124(tex, plttKey);
    return 1;
fail:
    return 0;
}

/* Load the texels and palettes into VRAM keys allocated before. */
BOOL func_02047204(G3dResource *res)
{
    NNSG3dResFileHeader *file = res->file;
    NNSG3dResTex        *tex = func_0206E964(file);

    if (tex == 0) {
        return 0;
    }
    DC_FlushRange(file, file->fileSize);
    func_0206A00C(tex, 1);
    func_0206A12C(tex, 1);
    return 1;
}

NNSG3dResTex *func_02047250(G3dResource *res)
{
    return func_0206E964(res->file);
}

/*
 * Allocate VRAM for the plain and the 4x4-compressed texels. The 4x4 call
 * passes texSize, not tex4x4Size; the image does the same.
 */
BOOL func_02047260(NNSG3dResTex *tex, u32 *texKey, u32 *tex4x4Key)
{
    u32 texSize = func_02069FD0(tex);
    u32 tex4x4Size = func_02069FE4(tex);

    if (texSize != 0) {
        *texKey = NNS_GfdDefaultFuncAllocTexVram(texSize, 0, 0);
        if (*texKey == 0)
            return 0;
    }
    if (tex4x4Size != 0) {
        *tex4x4Key = NNS_GfdDefaultFuncAllocTexVram(texSize, 1, 0);
        if (*tex4x4Key == 0)
            return 0;
    }
    return 1;
}

/*
 * Allocate palette VRAM; a texture without palettes needs none and succeeds.
 * The result is stored before it is tested.
 */
BOOL func_020472F8(NNSG3dResTex *tex, u32 *plttKey)
{
    u32 key;

    key = func_0206A110(tex);
    if (key == 0)
        goto done;

    key = NNS_GfdDefaultFuncAllocPlttVram(key, tex->tex4x4Info.flag & 0x8000, 0);
    *plttKey = key;
    if (key == 0)
        return 0;
done:
    return 1;
}

/* Whether any part of the resource's texture block is in VRAM. */
BOOL func_02047348(G3dResource *res)
{
    NNSG3dResTex *tex = func_0206E964(res->file);

    if ((tex->texInfo.flag & 1) || (tex->tex4x4Info.flag & 1) || (tex->plttInfo.flag & 1))
        return 1;
    return 0;
}

u32 func_02047388(G3dResource *res)
{
    NNSG3dResTex *tex = func_0206E964(res->file);

    if (tex->texInfo.flag & 1)
        return tex->texInfo.vramKey;
    if (tex->tex4x4Info.flag & 1)
        return tex->tex4x4Info.vramKey;
    return 0;
}

u32 func_020473B8(G3dResource *res)
{
    NNSG3dResTex *tex = func_0206E964(res->file);

    if (tex->plttInfo.flag & 1)
        return tex->plttInfo.vramKey;
    return 0;
}

void *func_020473D8(G3dResource *res)
{
    NNSG3dResTex *tex = func_02047250(res);

    return (u8 *)tex + tex->texInfo.ofsTex;
}

void *func_020473EC(G3dResource *res)
{
    NNSG3dResTex *tex = func_02047250(res);

    return (u8 *)tex + tex->plttInfo.ofsPlttData;
}

/*
 * Build a render object for model mdlIdx of a model resource, binding the
 * textures and palettes of texRes when one is given (line 1544).
 *
 * The gotos give the "no entry" and "no model" results their own blocks with
 * two predecessors each, as the image has them; the structured form lets the
 * compiler predicate the entry lookup (12 bytes off).
 */
G3dRender *func_02047400(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes)
{
    NNSG3dResTex *tex;
    NNSG3dResMdlSet *mdlSet;
    NNSG3dResDict *dict;
    void *resMdl;
    G3dRender *render;
    u8 *entry;
    u32 ofsEntry;
    u32 sizeUnit;

    tex = 0;
    mdlSet = func_0206E954(mdlRes->file);
    if (mdlSet == 0) goto noModel;
    dict = &mdlSet->dict;
    if (dict == 0) goto noEntry;
    if (mdlIdx >= mdlSet->dict.numEntry) goto noEntry;
    ofsEntry = mdlSet->dict.ofsEntry;
    sizeUnit = *(u16 *)((u8 *)dict + ofsEntry);
    entry = (u8 *)(sizeUnit * mdlIdx + (s32)((u8 *)dict + ofsEntry + 4));
    goto join;
noEntry:
    entry = 0;
join:
    if (entry != 0) { resMdl = (u8 *)mdlSet + *(u32 *)entry; goto have; }
noModel:
    resMdl = 0;
have:
    ;

    if (texRes != 0) tex = func_0206E964(texRes->file);

    render = func_02030734(_G3dSystem.work->heapId, 0x10, 0, G3D_SYSTEM_FileName, 0x608);
    render->magic = G3D_RENDER_MAGIC;
    render->mdlRes = mdlRes;
    render->texRes = texRes;
    render->rndObj = func_0206E348(&_G3dSystem.work->allocator);
    if (tex != 0) {
        func_0206A2CC(resMdl, tex);
        func_0206A4AC(resMdl, tex);
    }
    func_02069D14(render->rndObj, resMdl);
    return render;
}

void func_02047504(G3dRender *render)
{
    if (render == 0)
        return;
    if (render->magic != G3D_RENDER_MAGIC)
        return;

    func_0206E358(&_G3dSystem.work->allocator, render->rndObj);
    render->magic = G3D_RENDER_MAGIC - 1;
    func_020307B0(render);
}

G3dResource *func_0204754C(G3dRender *render)
{
    return render->mdlRes;
}

G3dResource *func_02047554(G3dRender *render)
{
    return render->texRes;
}

NNSG3dRenderObj *func_0204755C(G3dRender *render)
{
    return render->rndObj;
}

/*
 * Build animation anmIdx of an animation resource against the render
 * object's model, with its textures when it has some (line 1746).
 *
 * anmRes is const: it lets the anmRes->file load move above the magic
 * store, and the scheduler then issues the magic's pool load first as the
 * image does.
 */
G3dAnime *func_02047564(G3dRender *render, const G3dResource *anmRes, u32 anmIdx)
{
    G3dAnime *anime;
    void *anm;
    NNSG3dResMdl *resMdl;
    NNSG3dResTex *tex = 0;

    anime = func_02030734(_G3dSystem.work->heapId, 0xC, 0, G3D_SYSTEM_FileName, 0x6D2);
    anime->magic = G3D_ANIME_MAGIC;
    anime->anmRes = anmRes;
    anm = func_0206E9A4(anmRes->file, anmIdx);
    resMdl = render->rndObj->resMdl;
    if (func_02047554(render) != 0)
        tex = func_0206E964(render->texRes->file);
    anime->anmObj = func_0206E364(&_G3dSystem.work->allocator, anm, resMdl);
    func_02069C74(anime->anmObj, anm, resMdl, tex);
    return anime;
}

void func_0204762C(G3dAnime *anime)
{
    if (anime == 0)
        return;
    if (anime->magic != G3D_ANIME_MAGIC)
        return;

    func_0206E388(&_G3dSystem.work->allocator, anime->anmObj);
    anime->magic = G3D_ANIME_MAGIC - 1;
    func_020307B0(anime);
}

NNSG3dAnmObj *func_02047674(G3dAnime *anime)
{
    return anime->anmObj;
}

/* Build an object from a render object and a copy of an animation table (lines 1883, 1893). */
G3dObject *func_0204767C(G3dRender *render, G3dAnime **anmTbl, int anmCount)
{
    G3dObject *obj;
    int i;

    obj = func_02030734(_G3dSystem.work->heapId, 0x10, 0, G3D_SYSTEM_FileName, 0x75b);
    obj->magic = G3D_OBJECT_MAGIC;
    obj->render = render;
    obj->anmCount = (u16)anmCount;
    if (anmCount == 0) {
        obj->anmTbl = 0;
    } else {
        obj->anmTbl = func_02030734(_G3dSystem.work->heapId, anmCount * 4, 1, G3D_SYSTEM_FileName, 0x765);
        if (anmTbl != 0 && anmCount > 0) {
            for (i = 0; i < anmCount; i++)
                obj->anmTbl[i] = anmTbl[i];
        }
    }
    return obj;
}

void func_02047738(G3dObject *obj)
{
    if (obj == 0)
        return;
    if (obj->magic != G3D_OBJECT_MAGIC)
        return;

    if (obj->anmTbl != 0) {
        func_020307B0(obj->anmTbl);
        obj->anmTbl = 0;
    }

    obj->magic = G3D_OBJECT_MAGIC - 1;
    func_020307B0(obj);
}

G3dRender *func_02047788(G3dObject *obj)
{
    return obj->render;
}

G3dAnime *func_02047790(G3dObject *obj, int anmIdx)
{
    return obj->anmTbl[anmIdx];
}

u16 func_0204779C(G3dObject *obj)
{
    return obj->anmCount;
}

/* Attach animation anmIdx to the object's render object; FALSE for an empty slot. */
BOOL func_020477A4(G3dObject *obj, u32 anmIdx)
{
    G3dAnime *anime = obj->anmTbl[anmIdx];

    if (anime == 0) {
        return 0;
    }

    func_02069E88(obj->render->rndObj, anime->anmObj);
    return 1;
}

/* Detach animation anmIdx from the object's render object; FALSE for an empty slot. */
BOOL func_020477D4(G3dObject *obj, u32 anmIdx)
{
    G3dAnime *anime = obj->anmTbl[anmIdx];

    if (anime == 0)
        return 0;

    func_02069F7C(obj->render->rndObj, anime->anmObj);
    return 1;
}

BOOL func_02047804(G3dObject *obj, u16 anmIdx)
{
    G3dAnime *anime = obj->anmTbl[anmIdx];

    if (anime == 0) {
        return 0;
    }
    anime->anmObj->frame = 0;
    return 1;
}

BOOL func_02047828(G3dObject *obj, u32 anmIdx, fx32 *frame)
{
    G3dAnime *anime = obj->anmTbl[anmIdx];

    if (anime == 0) {
        return 0;
    }
    *frame = anime->anmObj->frame;
    return 1;
}

/* Set the frame of animation anmIdx, clamped to its frame count. */
BOOL func_0204784C(G3dObject *obj, u16 anmIdx, const fx32 *frame)
{
    G3dAnime *anime = obj->anmTbl[anmIdx];
    NNSG3dAnmObj *anmObj;

    if (anime == 0) {
        return 0;
    }
    anmObj = anime->anmObj;
    if (*frame >= (fx32)(anmObj->resAnm->numFrame << 12)) {
        anmObj->frame = anmObj->resAnm->numFrame << 12;
    } else {
        anmObj->frame = *frame;
    }
    return 1;
}

BOOL func_02047888(G3dObject *obj, int anmIdx, fx32 *frameMax)
{
    G3dAnime *anime = obj->anmTbl[anmIdx];
    if (anime == 0) {
        return 0;
    }
    *frameMax = anime->anmObj->resAnm->numFrame << 12;
    return 1;
}

/*
 * Advance animation anmIdx by step without looping: at the end it stays on
 * the last frame, below zero it stays on frame 0. FALSE when it stopped.
 */
BOOL func_020478B8(G3dObject *obj, int anmIdx, fx32 step)
{
    G3dAnime **anmTbl = obj->anmTbl;
    G3dAnime *anime = anmTbl[anmIdx];
    NNSG3dAnmObj *anmObj;
    fx32 frame;
    u32 frameEnd;

    if (anime == 0) {
        return 0;
    }

    anmObj = anime->anmObj;
    frame = anmObj->frame + step;
    anmObj->frame = frame;

    frameEnd = (u32)anmObj->resAnm->numFrame << 12;
    if (frame >= (fx32)frameEnd) {
        anmObj->frame = frameEnd - 0x1000;
        return 0;
    }
    if (frame < 0) {
        anmObj->frame = 0;
        return 0;
    }
    return 1;
}

/*
 * Advance animation anmIdx by step and wrap: past the end it goes to frame
 * 0, below zero to the end. FALSE when it wrapped.
 */
BOOL func_02047910(G3dObject *obj, int anmIdx, fx32 step)
{
    G3dAnime **anmTbl = obj->anmTbl;
    G3dAnime *anime = anmTbl[anmIdx];
    NNSG3dAnmObj *anmObj;
    fx32 frame;
    u32 frameEnd;

    if (anime == 0) {
        return 0;
    }

    anmObj = anime->anmObj;
    frame = anmObj->frame + step;
    anmObj->frame = frame;

    frameEnd = (u32)anmObj->resAnm->numFrame << 12;
    if (frame >= (fx32)frameEnd) {
        anmObj->frame = 0;
        return 0;
    }
    if (frame < 0) {
        anmObj->frame = frameEnd;
        return 0;
    }
    return 1;
}

/* Start a frame of 3D drawing. */
void func_02047964(void)
{
    func_0207DA8C();
}

/* End a frame of 3D drawing: flush the command buffer and request the buffer swap. */
void func_02047970(void)
{
    func_0206DB80();
    _G3dSystem.work->swapRequest = 1;
}

/* Called once per frame from the main loop: swap the 3D buffers when requested. */
void func_02047990(void)
{
    G3dSystemWork *work = _G3dSystem.work;

    if (work == 0)
        return;
    if (work->swapRequest != 1)
        return;
    reg_G3_SWAP_BUFFERS = (work->swapBufferMode << 1) | work->swapSortMode;
    _G3dSystem.work->swapRequest = 0;
}

/* NitroSystem inline (glbstate_inline.h): set the camera and clear the derived-matrix flags. */
static inline void NNS_G3dGlbLookAt(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target)
{
    NNS_G3dGlb.camPos = *camPos;
    NNS_G3dGlb.camUp = *camUp;
    NNS_G3dGlb.camTarget = *target;
    MTX_LookAt(camPos, camUp, target, &NNS_G3dGlb.cameraMtx);
    NNS_G3dGlb.flag &= ~(0x08 | 0x80 | 0x20 | 0x40);
}

/* Load the stored camera into the global state and flush it. */
void func_020479D8(void)
{
    NNS_G3dGlbLookAt(&_G3dSystem.work->lookAt.camPos, &_G3dSystem.work->lookAt.camUp, &_G3dSystem.work->lookAt.target);
    _G3dSystem.work->glbFlushFunc();
}

/* NitroSystem inline (glbstate_inline.h): set the base rotation and clear the derived-matrix flags. */
static inline void NNS_G3dGlbSetBaseRot(const MtxFx33 *rot)
{
    MI_Copy36B(rot, &NNS_G3dGlb.prmBaseRot);
    NNS_G3dGlb.flag &= ~(0x04 | 0x20 | 0x80);
}

/* Draw an object at the given position, scale and rotation. */
void func_02047A60(G3dObject *obj, G3dObjectStatus *status)
{
    NNSG3dRenderObj *rndObj;

    rndObj = func_0204755C(func_02047788(obj));
    func_0206A9DC(&status->trans);
    NNS_G3dGlbSetBaseRot(&status->rotate);
    func_0206AA0C(&status->scale);
    _G3dSystem.work->glbFlushFunc();
    func_02047C8C(rndObj);
}

/*
 * Draw an object only when its bounding box is in view; returns whether it
 * was drawn.
 */
BOOL func_02047AC8(G3dObject *obj, G3dObjectStatus *status)
{
    NNSG3dRenderObj *rndObj;
    BOOL visible;

    rndObj = func_0204755C(func_02047788(obj));
    func_0206A9DC(&status->trans);
    NNS_G3dGlbSetBaseRot(&status->rotate);
    func_0206AA0C(&status->scale);
    _G3dSystem.work->glbFlushFunc();
    visible = func_02047B4C(obj);
    if (visible == 1)
        func_02047C8C(rndObj);
    return visible;
}

/* Box-test the object's model bounding box, scaled by its box scale. */
BOOL func_02047B4C(G3dObject *obj)
{
    GXBoxTestParam box;
    fx32 scale[3];
    int popCount;
    NNSG3dResMdlInfo *info;
    NNSG3dResMdl *resMdl;
    BOOL visible;

    visible = 1;
    resMdl = func_0204755C(func_02047788(obj))->resMdl;
    info = (resMdl != 0 ? &resMdl->info : 0);

    box.x = info->boxX;
    box.y = info->boxY;
    box.z = info->boxZ;
    box.width = info->boxW;
    box.height = info->boxH;
    box.depth = info->boxD;
    func_0206DDA4(G3OP_PUSH_MTX, 0, 0);

    scale[0] = info->boxPosScale;
    scale[1] = scale[0];
    scale[2] = scale[0];
    func_0206DDA4(G3OP_SCALE, scale, 3);

    if (func_02047C04(&box) == 0) {
        visible = 0;
    }

    popCount = 1;
    func_0206DDA4(G3OP_POP_MTX, &popCount, 1);
    return visible;
}

/* Run a box test; TRUE when the box is in view. */
BOOL func_02047C04(const GXBoxTestParam *box)
{
    s32 result;
    int polygonAttr;
    int primitive;

    result = 1;
    polygonAttr = 0x30C1;
    func_0206DDA4(G3OP_POLYGON_ATTR, &polygonAttr, 1);
    primitive = 0;
    func_0206DDA4(G3OP_BEGIN_VTXS, &primitive, 1);
    func_0206DDA4(G3OP_END_VTXS, 0, 0);
    func_0206DDA4(G3OP_BOX_TEST, box, 3);
    func_0206DB80();
    while (func_0207DEA4(&result) != 0) {
        ;
    }
    return result;
}

/* Draw a render object: count its polygons and vertices, run the draw callback, draw. */
void func_02047C8C(NNSG3dRenderObj *rndObj)
{
    _G3dSystem.polygonCount += rndObj->resMdl->info.numPolygon;
    _G3dSystem.vertexCount += rndObj->resMdl->info.numVertex;
    if (_G3dSystem.work->drawCallback != 0)
        _G3dSystem.work->drawCallback(rndObj, _G3dSystem.work->drawCallbackArg);
    func_0206B6A4(rndObj);
}

void func_02047CE4(void)
{
    _G3dSystem.polygonCount = 0;
    _G3dSystem.vertexCount = 0;
}
