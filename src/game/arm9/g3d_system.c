/*
 * file:     g3d_system.c
 * unit:     yes
 * function: G3D_SYSTEM_Init, G3D_SYSTEM_Exit, G3D_SYSTEM_GetProjection, G3D_SYSTEM_SetProjection, G3D_SYSTEM_SetLight, G3D_SYSTEM_GetLookAt, G3D_SYSTEM_SetLookAt, G3D_SYSTEM_SetSwapBuffersMode, G3D_SYSTEM_GetTexManagerMode, G3D_SYSTEM_GetPlttManagerMode, G3D_SYSTEM_SetGlbFlushMode, G3D_SYSTEM_FlushGlbDefault, G3D_SYSTEM_GetResourceSize, G3D_SYSTEM_InitResourceByKind, G3D_SYSTEM_InitResourceByFile, G3D_SYSTEM_CreateResourceArc, G3D_SYSTEM_CreateResourceArcHandle, G3D_SYSTEM_CreateResourcePath, G3D_SYSTEM_DeleteResource, G3D_SYSTEM_GetResourceFile, G3D_SYSTEM_CheckResourceType, G3D_SYSTEM_CutTexture, G3D_SYSTEM_TransVramTexture, G3D_SYSTEM_TransVramTextureAndCut, G3D_SYSTEM_FreeVramTexture, G3D_SYSTEM_AllocVramTexture, G3D_SYSTEM_TransAllocatedTexture, G3D_SYSTEM_GetResourceTex, G3D_SYSTEM_AllocTexVramKeys, G3D_SYSTEM_AllocPlttVramKey, G3D_SYSTEM_IsTextureInVram, G3D_SYSTEM_GetTexVramKey, G3D_SYSTEM_GetPlttVramKey, G3D_SYSTEM_GetTexDataAddr, G3D_SYSTEM_GetPlttDataAddr, G3D_SYSTEM_CreateRender, G3D_SYSTEM_DeleteRender, G3D_SYSTEM_GetRenderMdlRes, G3D_SYSTEM_GetRenderTexRes, G3D_SYSTEM_GetRenderObj, G3D_SYSTEM_CreateAnime, G3D_SYSTEM_DeleteAnime, G3D_SYSTEM_GetAnimeObj, G3D_SYSTEM_CreateObject, G3D_SYSTEM_DeleteObject, G3D_SYSTEM_GetObjectRender, G3D_SYSTEM_GetObjectAnime, G3D_SYSTEM_GetObjectAnimeCount, G3D_SYSTEM_EnableObjectAnime, G3D_SYSTEM_DisableObjectAnime, G3D_SYSTEM_ResetObjectAnimeFrame, G3D_SYSTEM_GetObjectAnimeFrame, G3D_SYSTEM_SetObjectAnimeFrame, G3D_SYSTEM_GetObjectAnimeFrameMax, G3D_SYSTEM_IncObjectAnimeFrame, G3D_SYSTEM_LoopObjectAnimeFrame, G3D_SYSTEM_DrawStart, G3D_SYSTEM_DrawEnd, G3D_SYSTEM_SwapBuffersMain, G3D_SYSTEM_ApplyLookAt, G3D_SYSTEM_DrawObject, G3D_SYSTEM_DrawObjectCulling, G3D_SYSTEM_CheckObjectCulling, G3D_SYSTEM_BoxTest, G3D_SYSTEM_DrawRenderObj, G3D_SYSTEM_ResetDrawCounts
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
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   GFL_HEAP_Free      0x020307B0  arm
 *   GFL_HEAP_InitAllocatorChecked      0x020307C8  arm
 *   GFL_HEAP_CheckAllocator      0x020307E0  arm
 *   GFL_HEAP_AllocSystemChecked      0x02030BBC  arm
 *   GFL_HEAP_FreeSystemChecked      0x02030BC8  arm
 *   ARC_TOOL_LoadMember      0x02048F60  arm
 *   ARC_TOOL_LoadMemberFromPath      0x02048F9C  arm
 *   ARC_TOOL_LoadHandleMember      0x02049250  arm
 *   NNS_GfdInitVramManager      0x020613D8  arm
 *   NNSi_GfdSizeToGranuleTex      0x0206210C  arm
 *   NNSi_GfdInitTexVramManager      0x02062114  arm
 *   NNSi_GfdSizeToGranulePltt      0x0206246C  arm
 *   NNSi_GfdInitPlttVramManager      0x02062474  arm
 *   NNS_G3dAnmObjInit      0x02069C74  arm
 *   NNS_G3dRenderObjInit      0x02069D14  arm
 *   NNS_G3dRenderObjAddAnmObj      0x02069E88  arm
 *   NNS_G3dRenderObjRemoveAnmObj      0x02069F7C  arm
 *   NNS_G3dTexGetRequiredSize      0x02069FD0  arm
 *   NNS_G3dTex4x4GetRequiredSize      0x02069FE4  arm
 *   NNS_G3dTexSetTexKey      0x02069FF8  arm
 *   NNS_G3dTexLoad      0x0206A00C  arm
 *   NNS_G3dTexReleaseTexKey      0x0206A0C4  arm
 *   NNS_G3dPlttGetRequiredSize      0x0206A110  arm
 *   NNS_G3dPlttSetPlttKey      0x0206A124  arm
 *   NNS_G3dPlttLoad      0x0206A12C  arm
 *   NNS_G3dPlttReleasePlttKey      0x0206A17C  arm
 *   NNS_G3dBindMdlTex      0x0206A2CC  arm
 *   NNS_G3dBindMdlPltt      0x0206A4AC  arm
 *   NNS_G3dGlbInit      0x0206A700  arm
 *   NNS_G3dGlbFlush      0x0206A854  arm
 *   NNS_G3dGlbFlushP      0x0206A884  arm
 *   NNS_G3dGlbFlushWVP      0x0206A8FC  arm
 *   NNS_G3dGlbBaseTrans      0x0206A9DC  arm
 *   NNS_G3dGlbBaseScale      0x0206AA0C  arm
 *   NNS_G3dGlbLightVector      0x0206AA3C  arm
 *   NNS_G3dGlbLightColor      0x0206AA78  arm
 *   NNS_G3dDraw      0x0206B6A4  arm
 *   NNS_G3dGeIsBufferExist      0x0206DB24  arm
 *   NNS_G3dGeSetBuffer      0x0206DB40  arm
 *   NNS_G3dGeReleaseBuffer      0x0206DB60  arm
 *   NNS_G3dGeFlushBuffer      0x0206DB80  arm
 *   NNS_G3dGeBufferOP_N      0x0206DDA4  arm
 *   NNS_G3dInit      0x0206DF14  arm
 *   NNS_G3dAllocRenderObj      0x0206E348  arm
 *   NNS_G3dFreeRenderObj      0x0206E358  arm
 *   NNS_G3dAllocAnmObj      0x0206E364  arm
 *   NNS_G3dFreeAnmObj      0x0206E388  arm
 *   NNS_G3dGetMdlSet      0x0206E954  arm
 *   NNS_G3dGetTex      0x0206E964  arm
 *   NNS_G3dGetAnmByIdx      0x0206E9A4  arm
 *   MTX_FrustumW      0x0207C1D0  arm
 *   MTX_PerspectiveW      0x0207C408  arm
 *   MTX_OrthoW      0x0207C554  arm
 *   G3X_Reset      0x0207DA8C  arm
 *   G3X_GetBoxTestResult      0x0207DEA4  arm
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

extern void *GFL_HEAP_Alloc(u16 heapId, u32 size, int clear, const char *file, int line);
extern void  GFL_HEAP_Free(void *memory);
extern void  GFL_HEAP_InitAllocatorChecked(NNSFndAllocator *allocator, u16 heapId, u32 align);
extern void  GFL_HEAP_CheckAllocator(void *memory, u32 newSize);
extern void *GFL_HEAP_AllocSystemChecked(u32 size);
extern int   GFL_HEAP_FreeSystemChecked(u32 buffer);
extern void *ARC_TOOL_LoadMember(u32 arcId, u32 dataId, u16 heapId);
extern void *ARC_TOOL_LoadMemberFromPath(const char *path, u32 dataId, u16 heapId);
extern void *ARC_TOOL_LoadHandleMember(struct ArcHandle *arc, u32 dataId, u16 heapId);
extern void  NNS_GfdInitVramManager(u32 size, u32 useAsDefault);
extern int   NNSi_GfdSizeToGranuleTex(int numBlocks);
extern void  NNSi_GfdInitTexVramManager(u32 size, u32 size4x4, u32 work, u32 workSize, u32 useAsDefault);
extern int   NNSi_GfdSizeToGranulePltt(int numBlocks);
extern void  NNSi_GfdInitPlttVramManager(u32 size, u32 work, u32 workSize, u32 useAsDefault);
extern void  NNS_G3dAnmObjInit(NNSG3dAnmObj *anmObj, void *anm, NNSG3dResMdl *resMdl, NNSG3dResTex *tex);
extern void  NNS_G3dRenderObjInit(NNSG3dRenderObj *rndObj, void *resMdl);
extern void  NNS_G3dRenderObjAddAnmObj(NNSG3dRenderObj *rndObj, NNSG3dAnmObj *anmObj);
extern void  NNS_G3dRenderObjRemoveAnmObj(NNSG3dRenderObj *rndObj, NNSG3dAnmObj *anmObj);
extern u32   NNS_G3dTexGetRequiredSize(NNSG3dResTex *tex);
extern u32   NNS_G3dTex4x4GetRequiredSize(NNSG3dResTex *tex);
extern void  NNS_G3dTexSetTexKey(NNSG3dResTex *tex, u32 texKey, u32 tex4x4Key);
extern void  NNS_G3dTexLoad(NNSG3dResTex *tex, BOOL exec);
extern void  NNS_G3dTexReleaseTexKey(NNSG3dResTex *tex, u32 *texKey, u32 *tex4x4Key);
extern u32   NNS_G3dPlttGetRequiredSize(NNSG3dResTex *tex);
extern void  NNS_G3dPlttSetPlttKey(NNSG3dResTex *tex, u32 plttKey);
extern void  NNS_G3dPlttLoad(NNSG3dResTex *tex, BOOL exec);
extern u32   NNS_G3dPlttReleasePlttKey(NNSG3dResTex *tex);
extern void  NNS_G3dBindMdlTex(void *resMdl, NNSG3dResTex *tex);
extern void  NNS_G3dBindMdlPltt(void *resMdl, NNSG3dResTex *tex);
extern void  NNS_G3dGlbInit(void);
extern void  NNS_G3dGlbFlush(void);
extern void  NNS_G3dGlbFlushP(void);
extern void  NNS_G3dGlbFlushWVP(void);
extern void  NNS_G3dGlbBaseTrans(VecFx32 *trans);
extern void  NNS_G3dGlbBaseScale(VecFx32 *scale);
extern void  NNS_G3dGlbLightVector(int lightIdx, s16 x, s16 y, s16 z);
extern void  NNS_G3dGlbLightColor(int lightIdx, u32 color);
extern void  NNS_G3dDraw(NNSG3dRenderObj *rndObj);
extern u32   NNS_G3dGeIsBufferExist(void);
extern void  NNS_G3dGeSetBuffer(void *buffer);
extern void *NNS_G3dGeReleaseBuffer(void);
extern void  NNS_G3dGeFlushBuffer(void);
extern void  NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 numParams);
extern void  NNS_G3dInit(void);
extern NNSG3dRenderObj *NNS_G3dAllocRenderObj(NNSFndAllocator *allocator);
extern void  NNS_G3dFreeRenderObj(NNSFndAllocator *allocator, NNSG3dRenderObj *rndObj);
extern NNSG3dAnmObj *NNS_G3dAllocAnmObj(NNSFndAllocator *allocator, void *anm, NNSG3dResMdl *resMdl);
extern void  NNS_G3dFreeAnmObj(NNSFndAllocator *allocator, NNSG3dAnmObj *anmObj);
extern NNSG3dResMdlSet *NNS_G3dGetMdlSet(void *file);
extern NNSG3dResTex *NNS_G3dGetTex(void *file);
extern void *NNS_G3dGetAnmByIdx(void *file, u32 anmIdx);
extern void  MTX_FrustumW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
extern void  MTX_PerspectiveW(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
extern void  MTX_OrthoW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
extern void  G3X_Reset(void);
extern int   G3X_GetBoxTestResult(s32 *result);
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

void G3D_SYSTEM_Init(u32 texManMode, u32 texManSize, u32 plttManMode, u32 plttManSize, u16 geBufSize, s16 heapId, void (*setUpFunc)(void));
void G3D_SYSTEM_Exit(void);
void G3D_SYSTEM_GetProjection(G3dProjection *proj);
void G3D_SYSTEM_SetProjection(const G3dProjection *proj);
void G3D_SYSTEM_SetLight(u32 lightIdx, const G3dLight *light);
void G3D_SYSTEM_GetLookAt(G3dLookAt *lookAt);
void G3D_SYSTEM_SetLookAt(const G3dLookAt *lookAt);
void G3D_SYSTEM_SetSwapBuffersMode(u32 sortMode, u32 bufferMode);
u32 G3D_SYSTEM_GetTexManagerMode(void);
u32 G3D_SYSTEM_GetPlttManagerMode(void);
void G3D_SYSTEM_SetGlbFlushMode(u32 mode);
void G3D_SYSTEM_FlushGlbDefault(void);
u32 G3D_SYSTEM_GetResourceSize(void);
void G3D_SYSTEM_InitResourceByKind(G3dResource *res, u32 kind, void *file);
void G3D_SYSTEM_InitResourceByFile(G3dResource *res, NNSG3dResFileHeader *file);
G3dResource *G3D_SYSTEM_CreateResourceArc(u32 arcId, u32 dataId);
G3dResource *G3D_SYSTEM_CreateResourceArcHandle(struct ArcHandle *arc, u32 dataId);
G3dResource *G3D_SYSTEM_CreateResourcePath(const char *path, u32 dataId);
void G3D_SYSTEM_DeleteResource(G3dResource *res);
void *G3D_SYSTEM_GetResourceFile(G3dResource *res);
u32 G3D_SYSTEM_CheckResourceType(G3dResource *res, u32 kind);
void G3D_SYSTEM_CutTexture(G3dResource *res);
BOOL G3D_SYSTEM_TransVramTexture(G3dResource *res);
BOOL G3D_SYSTEM_TransVramTextureAndCut(G3dResource *res);
BOOL G3D_SYSTEM_FreeVramTexture(G3dResource *res);
BOOL G3D_SYSTEM_AllocVramTexture(G3dResource *res);
BOOL G3D_SYSTEM_TransAllocatedTexture(G3dResource *res);
NNSG3dResTex *G3D_SYSTEM_GetResourceTex(G3dResource *res);
BOOL G3D_SYSTEM_AllocTexVramKeys(NNSG3dResTex *tex, u32 *texKey, u32 *tex4x4Key);
BOOL G3D_SYSTEM_AllocPlttVramKey(NNSG3dResTex *tex, u32 *plttKey);
BOOL G3D_SYSTEM_IsTextureInVram(G3dResource *res);
u32 G3D_SYSTEM_GetTexVramKey(G3dResource *res);
u32 G3D_SYSTEM_GetPlttVramKey(G3dResource *res);
void *G3D_SYSTEM_GetTexDataAddr(G3dResource *res);
void *G3D_SYSTEM_GetPlttDataAddr(G3dResource *res);
G3dRender *G3D_SYSTEM_CreateRender(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
void G3D_SYSTEM_DeleteRender(G3dRender *render);
G3dResource *G3D_SYSTEM_GetRenderMdlRes(G3dRender *render);
G3dResource *G3D_SYSTEM_GetRenderTexRes(G3dRender *render);
NNSG3dRenderObj *G3D_SYSTEM_GetRenderObj(G3dRender *render);
G3dAnime *G3D_SYSTEM_CreateAnime(G3dRender *render, const G3dResource *anmRes, u32 anmIdx);
void G3D_SYSTEM_DeleteAnime(G3dAnime *anime);
NNSG3dAnmObj *G3D_SYSTEM_GetAnimeObj(G3dAnime *anime);
G3dObject *G3D_SYSTEM_CreateObject(G3dRender *render, G3dAnime **anmTbl, int anmCount);
void G3D_SYSTEM_DeleteObject(G3dObject *obj);
G3dRender *G3D_SYSTEM_GetObjectRender(G3dObject *obj);
G3dAnime *G3D_SYSTEM_GetObjectAnime(G3dObject *obj, int anmIdx);
u16 G3D_SYSTEM_GetObjectAnimeCount(G3dObject *obj);
BOOL G3D_SYSTEM_EnableObjectAnime(G3dObject *obj, u32 anmIdx);
BOOL G3D_SYSTEM_DisableObjectAnime(G3dObject *obj, u32 anmIdx);
BOOL G3D_SYSTEM_ResetObjectAnimeFrame(G3dObject *obj, u16 anmIdx);
BOOL G3D_SYSTEM_GetObjectAnimeFrame(G3dObject *obj, u32 anmIdx, fx32 *frame);
BOOL G3D_SYSTEM_SetObjectAnimeFrame(G3dObject *obj, u16 anmIdx, const fx32 *frame);
BOOL G3D_SYSTEM_GetObjectAnimeFrameMax(G3dObject *obj, int anmIdx, fx32 *frameMax);
BOOL G3D_SYSTEM_IncObjectAnimeFrame(G3dObject *obj, int anmIdx, fx32 step);
BOOL G3D_SYSTEM_LoopObjectAnimeFrame(G3dObject *obj, int anmIdx, fx32 step);
void G3D_SYSTEM_DrawStart(void);
void G3D_SYSTEM_DrawEnd(void);
void G3D_SYSTEM_SwapBuffersMain(void);
void G3D_SYSTEM_ApplyLookAt(void);
void G3D_SYSTEM_DrawObject(G3dObject *obj, G3dObjectStatus *status);
BOOL G3D_SYSTEM_DrawObjectCulling(G3dObject *obj, G3dObjectStatus *status);
BOOL G3D_SYSTEM_CheckObjectCulling(G3dObject *obj);
BOOL G3D_SYSTEM_BoxTest(const GXBoxTestParam *box);
void G3D_SYSTEM_DrawRenderObj(NNSG3dRenderObj *rndObj);
void G3D_SYSTEM_ResetDrawCounts(void);

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
void G3D_SYSTEM_Init(u32 texManMode, u32 texManSize, u32 plttManMode, u32 plttManSize,
                   u16 geBufSize, s16 heapId, void (*setUpFunc)(void))
{
    G3dProjection proj;
    G3dLookAt lookAt;
    G3dLight light;
    u32 workSize;

    _G3dSystem.work = GFL_HEAP_Alloc((u16)heapId, 0xa0, 0, G3D_SYSTEM_FileName, 0x5c);
    _G3dSystem.work->heapId = heapId;
    _G3dSystem.work->texManagerMode = texManMode;
    _G3dSystem.work->plttManagerMode = plttManMode;

    NNS_G3dInit();
    G3X_InitMtxStack();
    NNS_G3dGlbInit();

    if (geBufSize != 0)
        NNS_G3dGeSetBuffer(GFL_HEAP_AllocSystemChecked(geBufSize > 0x1800 ? 0x1800 : geBufSize));

    reg_G3_SWAP_BUFFERS = 2;
    GFL_HEAP_InitAllocatorChecked(&_G3dSystem.work->allocator, _G3dSystem.work->heapId, 4);

    if (texManMode == 0) {
        workSize = NNSi_GfdSizeToGranuleTex(texManSize << 7);
        _G3dSystem.work->texManagerWork = GFL_HEAP_Alloc(_G3dSystem.work->heapId, workSize, 0, G3D_SYSTEM_FileName, 0x7e);
        NNSi_GfdInitTexVramManager(texManSize << 17, 0, (u32)_G3dSystem.work->texManagerWork, workSize, 1);
    } else {
        NNS_GfdInitVramManager((u16)texManSize, 1);
        _G3dSystem.work->texManagerWork = 0;
    }

    if (plttManMode == 0) {
        workSize = NNSi_GfdSizeToGranulePltt(plttManSize << 9);
        _G3dSystem.work->plttManagerWork = GFL_HEAP_Alloc(_G3dSystem.work->heapId, workSize, 0, G3D_SYSTEM_FileName, 0x8d);
        NNSi_GfdInitPlttVramManager(plttManSize << 14, (u32)_G3dSystem.work->plttManagerWork, workSize, 1);
    } else {
        NNS_GfdInitVramManager((u16)(plttManSize << 14), 1);
        _G3dSystem.work->texManagerWork = 0;
    }

    /* sine and cosine of 20 degrees (FX_SinIdx/FX_CosIdx of 0xE38) */
    proj = _DefaultProjection;
    proj.fovySinOrTop = FX_SinCosTable_[(0xE38 >> 4) * 2];
    proj.fovyCosOrBottom = FX_SinCosTable_[(0xE38 >> 4) * 2 + 1];
    G3D_SYSTEM_SetProjection(&proj);

    light = _DefaultLight;
    G3D_SYSTEM_SetLight(0, &light);
    G3D_SYSTEM_SetLight(1, &light);
    G3D_SYSTEM_SetLight(2, &light);
    G3D_SYSTEM_SetLight(3, &light);

    lookAt = _DefaultLookAt;
    G3D_SYSTEM_SetLookAt(&lookAt);
    G3D_SYSTEM_SetSwapBuffersMode(0, 1);
    G3D_SYSTEM_SetGlbFlushMode(0);

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
void G3D_SYSTEM_Exit(void)
{
    if (_G3dSystem.work->plttManagerWork != 0)
        GFL_HEAP_Free(_G3dSystem.work->plttManagerWork);
    if (_G3dSystem.work->texManagerWork != 0)
        GFL_HEAP_Free(_G3dSystem.work->texManagerWork);

    if (NNS_G3dGeIsBufferExist() == 1) {
        GFL_HEAP_FreeSystemChecked((u32)NNS_G3dGeReleaseBuffer());
    }

    GFL_HEAP_Free(_G3dSystem.work);
    _G3dSystem.work = 0;
}

void G3D_SYSTEM_GetProjection(G3dProjection *proj)
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
    MTX_PerspectiveW(fovySin, fovyCos, aspect, n, f, scaleW, &NNS_G3dGlb.projMtx);
    NNS_G3dGlb.flag &= ~(0x10 | 0x40);
}

static inline void NNS_G3dGlbFrustumW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW)
{
    MTX_FrustumW(t, b, l, r, n, f, scaleW, &NNS_G3dGlb.projMtx);
    NNS_G3dGlb.flag &= ~(0x10 | 0x40);
}

static inline void NNS_G3dGlbOrthoW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW)
{
    MTX_OrthoW(t, b, l, r, n, f, scaleW, &NNS_G3dGlb.projMtx);
    NNS_G3dGlb.flag &= ~(0x10 | 0x40);
}

/*
 * Store the projection and load it into the NitroSystem global state:
 * perspective, frustum or orthographic by type; a zero scaleW means
 * FX32_ONE.
 */
void G3D_SYSTEM_SetProjection(const G3dProjection *proj)
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
void G3D_SYSTEM_SetLight(u32 lightIdx, const G3dLight *light)
{
    G3dSystemWork *slot = (G3dSystemWork *)((u8 *)_G3dSystem.work + lightIdx * 8);

    slot->lights[0].vecX = light->vecX;
    slot->lights[0].vecY = light->vecY;
    slot->lights[0].vecZ = light->vecZ;
    slot->lights[0].color = light->color;

    NNS_G3dGlbLightVector(lightIdx, _G3dSystem.work->lights[lightIdx].vecX,
                  _G3dSystem.work->lights[lightIdx].vecY,
                  _G3dSystem.work->lights[lightIdx].vecZ);
    NNS_G3dGlbLightColor(lightIdx, _G3dSystem.work->lights[lightIdx].color);
}

void G3D_SYSTEM_GetLookAt(G3dLookAt *lookAt)
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
void G3D_SYSTEM_SetLookAt(const G3dLookAt *lookAt)
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

void G3D_SYSTEM_SetSwapBuffersMode(u32 sortMode, u32 bufferMode)
{
    _G3dSystem.work->swapSortMode = sortMode;
    _G3dSystem.work->swapBufferMode = bufferMode;
}

u32 G3D_SYSTEM_GetTexManagerMode(void)
{
    return _G3dSystem.work->texManagerMode;
}

u32 G3D_SYSTEM_GetPlttManagerMode(void)
{
    return _G3dSystem.work->plttManagerMode;
}

/*
 * Select the function that flushes the NitroSystem global state before a
 * draw: modes 1 and 2 have their own, mode 0 and every other value use
 * G3D_SYSTEM_FlushGlbDefault.
 */
void G3D_SYSTEM_SetGlbFlushMode(u32 mode)
{
    switch (mode) {
    case 0:
    default:
        _G3dSystem.work->glbFlushFunc = G3D_SYSTEM_FlushGlbDefault;
        break;
    case 1:
        _G3dSystem.work->glbFlushFunc = NNS_G3dGlbFlushP;
        break;
    case 2:
        _G3dSystem.work->glbFlushFunc = NNS_G3dGlbFlushWVP;
        break;
    }
}

void G3D_SYSTEM_FlushGlbDefault(void)
{
    NNS_G3dGlbFlush();
}

u32 G3D_SYSTEM_GetResourceSize(void)
{
    return sizeof(G3dResource);
}

/* Fill a resource header for a file of a known kind. */
void G3D_SYSTEM_InitResourceByKind(G3dResource *res, u32 kind, void *file)
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
void G3D_SYSTEM_InitResourceByFile(G3dResource *res, NNSG3dResFileHeader *file)
{
    switch (file->signature) {
    case SIGNATURE_BMD0:
        if (NNS_G3dGetTex(file) == 0) {
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
G3dResource *G3D_SYSTEM_CreateResourceArc(u32 arcId, u32 dataId)
{
    G3dResource *res = GFL_HEAP_Alloc(_G3dSystem.work->heapId, 8, 0, G3D_SYSTEM_FileName, 0x2b4);

    G3D_SYSTEM_InitResourceByFile(res, ARC_TOOL_LoadMember(arcId, dataId, _G3dSystem.work->heapId));
    return res;
}

/* Load a resource file through an open archive handle. */
G3dResource *G3D_SYSTEM_CreateResourceArcHandle(struct ArcHandle *arc, u32 dataId)
{
    G3dResource *res = GFL_HEAP_Alloc(_G3dSystem.work->heapId, 8, 0, G3D_SYSTEM_FileName, 0x2c8);

    G3D_SYSTEM_InitResourceByFile(res, ARC_TOOL_LoadHandleMember(arc, dataId, _G3dSystem.work->heapId));
    return res;
}

/* Load a resource file from an archive given by path. */
G3dResource *G3D_SYSTEM_CreateResourcePath(const char *path, u32 dataId)
{
    G3dResource *res = GFL_HEAP_Alloc(_G3dSystem.work->heapId, 8, 0, G3D_SYSTEM_FileName, 0x2dc);

    G3D_SYSTEM_InitResourceByFile(res, ARC_TOOL_LoadMemberFromPath(path, dataId, _G3dSystem.work->heapId));
    return res;
}

void G3D_SYSTEM_DeleteResource(G3dResource *res)
{
    if (res == 0) {
        return;
    }
    if (res->magic != G3D_RESOURCE_MAGIC) {
        return;
    }
    res->magic = G3D_RESOURCE_MAGIC - 1;
    if (res->file != 0) {
        GFL_HEAP_Free(res->file);
        res->file = 0;
    }
    GFL_HEAP_Free(res);
}

void *G3D_SYSTEM_GetResourceFile(G3dResource *res)
{
    return res->file;
}

/*
 * Whether the resource holds data of the given kind: a model (MDLTEX or
 * MDL), a texture (MDLTEX or TEX) or an animation. The model test is written
 * as a range on type - 1 (`+ 0xFFFF` after the halfword narrowing).
 */
u32 G3D_SYSTEM_CheckResourceType(G3dResource *res, u32 kind)
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
void G3D_SYSTEM_CutTexture(G3dResource *res)
{
    void         *file = res->file;
    NNSG3dResTex *tex = NNS_G3dGetTex(file);

    GFL_HEAP_CheckAllocator(file, (u32)((u8 *)tex + tex->texInfo.ofsTex - (u8 *)file));
}

/*
 * Allocate texture and palette VRAM for the resource's texture block, set the
 * keys and load the texels and palettes. The first guard exits through the
 * shared epilogue (a plain `return 0` there is if-converted).
 */
BOOL G3D_SYSTEM_TransVramTexture(G3dResource *res)
{
    u32 texKey;
    u32 tex4x4Key;
    u32 plttKey;
    NNSG3dResFileHeader *file;
    NNSG3dResTex *tex;

    file = res->file;
    tex = NNS_G3dGetTex(file);
    if (tex == 0)
        goto fail;
    if (G3D_SYSTEM_AllocTexVramKeys(tex, &texKey, &tex4x4Key) == 0)
        return 0;
    if (G3D_SYSTEM_AllocPlttVramKey(tex, &plttKey) == 0)
        return 0;
    NNS_G3dTexSetTexKey(tex, texKey, tex4x4Key);
    NNS_G3dPlttSetPlttKey(tex, plttKey);
    DC_FlushRange(file, file->fileSize);
    NNS_G3dTexLoad(tex, 1);
    NNS_G3dPlttLoad(tex, 1);
    return 1;
fail:
    return 0;
}

/* Load the texture into VRAM, then cut the texels off the file. */
BOOL G3D_SYSTEM_TransVramTextureAndCut(G3dResource *res)
{
    if (G3D_SYSTEM_TransVramTexture(res) == 0) {
        return 0;
    }
    G3D_SYSTEM_CutTexture(res);
    return 1;
}

/*
 * Release the texture's VRAM keys and free the VRAM. The two "loaded" flags
 * are ints set to 1 in the body (the boolean form gives a movne/moveq pair
 * each), and the palette free takes the release call's result directly so
 * the function pointer goes to r1.
 */
BOOL G3D_SYSTEM_FreeVramTexture(G3dResource *res)
{
    NNSG3dResTex *tex;
    int texLoaded;
    int tex4x4Loaded;
    u32 texKey;
    u32 tex4x4Key;

    tex = NNS_G3dGetTex(res->file);
    texLoaded = 0;
    tex4x4Loaded = 0;
    if (tex->texInfo.flag & 1)
        texLoaded = 1;
    if (tex->tex4x4Info.flag & 1)
        tex4x4Loaded = 1;
    NNS_G3dTexReleaseTexKey(tex, &texKey, &tex4x4Key);
    if (texLoaded)
        NNS_GfdDefaultFuncFreeTexVram(texKey);
    if (tex4x4Loaded)
        NNS_GfdDefaultFuncFreeTexVram(tex4x4Key);
    if ((tex->plttInfo.flag & 1) != 0 && tex->plttInfo.sizePltt != 0)
        NNS_GfdDefaultFuncFreePlttVram(NNS_G3dPlttReleasePlttKey(tex));
    return 1;
}

/* Allocate texture and palette VRAM and set the keys, without loading. */
BOOL G3D_SYSTEM_AllocVramTexture(G3dResource *res)
{
    NNSG3dResTex *tex;
    u32 texKey;
    u32 tex4x4Key;
    u32 plttKey;

    tex = NNS_G3dGetTex(res->file);
    if (tex == 0)
        goto fail;
    if (G3D_SYSTEM_AllocTexVramKeys(tex, &texKey, &tex4x4Key) == 0)
        return 0;
    if (G3D_SYSTEM_AllocPlttVramKey(tex, &plttKey) == 0)
        return 0;
    NNS_G3dTexSetTexKey(tex, texKey, tex4x4Key);
    NNS_G3dPlttSetPlttKey(tex, plttKey);
    return 1;
fail:
    return 0;
}

/* Load the texels and palettes into VRAM keys allocated before. */
BOOL G3D_SYSTEM_TransAllocatedTexture(G3dResource *res)
{
    NNSG3dResFileHeader *file = res->file;
    NNSG3dResTex        *tex = NNS_G3dGetTex(file);

    if (tex == 0) {
        return 0;
    }
    DC_FlushRange(file, file->fileSize);
    NNS_G3dTexLoad(tex, 1);
    NNS_G3dPlttLoad(tex, 1);
    return 1;
}

NNSG3dResTex *G3D_SYSTEM_GetResourceTex(G3dResource *res)
{
    return NNS_G3dGetTex(res->file);
}

/*
 * Allocate VRAM for the plain and the 4x4-compressed texels. The 4x4 call
 * passes texSize, not tex4x4Size; the image does the same.
 */
BOOL G3D_SYSTEM_AllocTexVramKeys(NNSG3dResTex *tex, u32 *texKey, u32 *tex4x4Key)
{
    u32 texSize = NNS_G3dTexGetRequiredSize(tex);
    u32 tex4x4Size = NNS_G3dTex4x4GetRequiredSize(tex);

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
BOOL G3D_SYSTEM_AllocPlttVramKey(NNSG3dResTex *tex, u32 *plttKey)
{
    u32 key;

    key = NNS_G3dPlttGetRequiredSize(tex);
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
BOOL G3D_SYSTEM_IsTextureInVram(G3dResource *res)
{
    NNSG3dResTex *tex = NNS_G3dGetTex(res->file);

    if ((tex->texInfo.flag & 1) || (tex->tex4x4Info.flag & 1) || (tex->plttInfo.flag & 1))
        return 1;
    return 0;
}

u32 G3D_SYSTEM_GetTexVramKey(G3dResource *res)
{
    NNSG3dResTex *tex = NNS_G3dGetTex(res->file);

    if (tex->texInfo.flag & 1)
        return tex->texInfo.vramKey;
    if (tex->tex4x4Info.flag & 1)
        return tex->tex4x4Info.vramKey;
    return 0;
}

u32 G3D_SYSTEM_GetPlttVramKey(G3dResource *res)
{
    NNSG3dResTex *tex = NNS_G3dGetTex(res->file);

    if (tex->plttInfo.flag & 1)
        return tex->plttInfo.vramKey;
    return 0;
}

void *G3D_SYSTEM_GetTexDataAddr(G3dResource *res)
{
    NNSG3dResTex *tex = G3D_SYSTEM_GetResourceTex(res);

    return (u8 *)tex + tex->texInfo.ofsTex;
}

void *G3D_SYSTEM_GetPlttDataAddr(G3dResource *res)
{
    NNSG3dResTex *tex = G3D_SYSTEM_GetResourceTex(res);

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
G3dRender *G3D_SYSTEM_CreateRender(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes)
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
    mdlSet = NNS_G3dGetMdlSet(mdlRes->file);
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

    if (texRes != 0) tex = NNS_G3dGetTex(texRes->file);

    render = GFL_HEAP_Alloc(_G3dSystem.work->heapId, 0x10, 0, G3D_SYSTEM_FileName, 0x608);
    render->magic = G3D_RENDER_MAGIC;
    render->mdlRes = mdlRes;
    render->texRes = texRes;
    render->rndObj = NNS_G3dAllocRenderObj(&_G3dSystem.work->allocator);
    if (tex != 0) {
        NNS_G3dBindMdlTex(resMdl, tex);
        NNS_G3dBindMdlPltt(resMdl, tex);
    }
    NNS_G3dRenderObjInit(render->rndObj, resMdl);
    return render;
}

void G3D_SYSTEM_DeleteRender(G3dRender *render)
{
    if (render == 0)
        return;
    if (render->magic != G3D_RENDER_MAGIC)
        return;

    NNS_G3dFreeRenderObj(&_G3dSystem.work->allocator, render->rndObj);
    render->magic = G3D_RENDER_MAGIC - 1;
    GFL_HEAP_Free(render);
}

G3dResource *G3D_SYSTEM_GetRenderMdlRes(G3dRender *render)
{
    return render->mdlRes;
}

G3dResource *G3D_SYSTEM_GetRenderTexRes(G3dRender *render)
{
    return render->texRes;
}

NNSG3dRenderObj *G3D_SYSTEM_GetRenderObj(G3dRender *render)
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
G3dAnime *G3D_SYSTEM_CreateAnime(G3dRender *render, const G3dResource *anmRes, u32 anmIdx)
{
    G3dAnime *anime;
    void *anm;
    NNSG3dResMdl *resMdl;
    NNSG3dResTex *tex = 0;

    anime = GFL_HEAP_Alloc(_G3dSystem.work->heapId, 0xC, 0, G3D_SYSTEM_FileName, 0x6D2);
    anime->magic = G3D_ANIME_MAGIC;
    anime->anmRes = anmRes;
    anm = NNS_G3dGetAnmByIdx(anmRes->file, anmIdx);
    resMdl = render->rndObj->resMdl;
    if (G3D_SYSTEM_GetRenderTexRes(render) != 0)
        tex = NNS_G3dGetTex(render->texRes->file);
    anime->anmObj = NNS_G3dAllocAnmObj(&_G3dSystem.work->allocator, anm, resMdl);
    NNS_G3dAnmObjInit(anime->anmObj, anm, resMdl, tex);
    return anime;
}

void G3D_SYSTEM_DeleteAnime(G3dAnime *anime)
{
    if (anime == 0)
        return;
    if (anime->magic != G3D_ANIME_MAGIC)
        return;

    NNS_G3dFreeAnmObj(&_G3dSystem.work->allocator, anime->anmObj);
    anime->magic = G3D_ANIME_MAGIC - 1;
    GFL_HEAP_Free(anime);
}

NNSG3dAnmObj *G3D_SYSTEM_GetAnimeObj(G3dAnime *anime)
{
    return anime->anmObj;
}

/* Build an object from a render object and a copy of an animation table (lines 1883, 1893). */
G3dObject *G3D_SYSTEM_CreateObject(G3dRender *render, G3dAnime **anmTbl, int anmCount)
{
    G3dObject *obj;
    int i;

    obj = GFL_HEAP_Alloc(_G3dSystem.work->heapId, 0x10, 0, G3D_SYSTEM_FileName, 0x75b);
    obj->magic = G3D_OBJECT_MAGIC;
    obj->render = render;
    obj->anmCount = (u16)anmCount;
    if (anmCount == 0) {
        obj->anmTbl = 0;
    } else {
        obj->anmTbl = GFL_HEAP_Alloc(_G3dSystem.work->heapId, anmCount * 4, 1, G3D_SYSTEM_FileName, 0x765);
        if (anmTbl != 0 && anmCount > 0) {
            for (i = 0; i < anmCount; i++)
                obj->anmTbl[i] = anmTbl[i];
        }
    }
    return obj;
}

void G3D_SYSTEM_DeleteObject(G3dObject *obj)
{
    if (obj == 0)
        return;
    if (obj->magic != G3D_OBJECT_MAGIC)
        return;

    if (obj->anmTbl != 0) {
        GFL_HEAP_Free(obj->anmTbl);
        obj->anmTbl = 0;
    }

    obj->magic = G3D_OBJECT_MAGIC - 1;
    GFL_HEAP_Free(obj);
}

G3dRender *G3D_SYSTEM_GetObjectRender(G3dObject *obj)
{
    return obj->render;
}

G3dAnime *G3D_SYSTEM_GetObjectAnime(G3dObject *obj, int anmIdx)
{
    return obj->anmTbl[anmIdx];
}

u16 G3D_SYSTEM_GetObjectAnimeCount(G3dObject *obj)
{
    return obj->anmCount;
}

/* Attach animation anmIdx to the object's render object; FALSE for an empty slot. */
BOOL G3D_SYSTEM_EnableObjectAnime(G3dObject *obj, u32 anmIdx)
{
    G3dAnime *anime = obj->anmTbl[anmIdx];

    if (anime == 0) {
        return 0;
    }

    NNS_G3dRenderObjAddAnmObj(obj->render->rndObj, anime->anmObj);
    return 1;
}

/* Detach animation anmIdx from the object's render object; FALSE for an empty slot. */
BOOL G3D_SYSTEM_DisableObjectAnime(G3dObject *obj, u32 anmIdx)
{
    G3dAnime *anime = obj->anmTbl[anmIdx];

    if (anime == 0)
        return 0;

    NNS_G3dRenderObjRemoveAnmObj(obj->render->rndObj, anime->anmObj);
    return 1;
}

BOOL G3D_SYSTEM_ResetObjectAnimeFrame(G3dObject *obj, u16 anmIdx)
{
    G3dAnime *anime = obj->anmTbl[anmIdx];

    if (anime == 0) {
        return 0;
    }
    anime->anmObj->frame = 0;
    return 1;
}

BOOL G3D_SYSTEM_GetObjectAnimeFrame(G3dObject *obj, u32 anmIdx, fx32 *frame)
{
    G3dAnime *anime = obj->anmTbl[anmIdx];

    if (anime == 0) {
        return 0;
    }
    *frame = anime->anmObj->frame;
    return 1;
}

/* Set the frame of animation anmIdx, clamped to its frame count. */
BOOL G3D_SYSTEM_SetObjectAnimeFrame(G3dObject *obj, u16 anmIdx, const fx32 *frame)
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

BOOL G3D_SYSTEM_GetObjectAnimeFrameMax(G3dObject *obj, int anmIdx, fx32 *frameMax)
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
BOOL G3D_SYSTEM_IncObjectAnimeFrame(G3dObject *obj, int anmIdx, fx32 step)
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
BOOL G3D_SYSTEM_LoopObjectAnimeFrame(G3dObject *obj, int anmIdx, fx32 step)
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
void G3D_SYSTEM_DrawStart(void)
{
    G3X_Reset();
}

/* End a frame of 3D drawing: flush the command buffer and request the buffer swap. */
void G3D_SYSTEM_DrawEnd(void)
{
    NNS_G3dGeFlushBuffer();
    _G3dSystem.work->swapRequest = 1;
}

/* Called once per frame from the main loop: swap the 3D buffers when requested. */
void G3D_SYSTEM_SwapBuffersMain(void)
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
void G3D_SYSTEM_ApplyLookAt(void)
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
void G3D_SYSTEM_DrawObject(G3dObject *obj, G3dObjectStatus *status)
{
    NNSG3dRenderObj *rndObj;

    rndObj = G3D_SYSTEM_GetRenderObj(G3D_SYSTEM_GetObjectRender(obj));
    NNS_G3dGlbBaseTrans(&status->trans);
    NNS_G3dGlbSetBaseRot(&status->rotate);
    NNS_G3dGlbBaseScale(&status->scale);
    _G3dSystem.work->glbFlushFunc();
    G3D_SYSTEM_DrawRenderObj(rndObj);
}

/*
 * Draw an object only when its bounding box is in view; returns whether it
 * was drawn.
 */
BOOL G3D_SYSTEM_DrawObjectCulling(G3dObject *obj, G3dObjectStatus *status)
{
    NNSG3dRenderObj *rndObj;
    BOOL visible;

    rndObj = G3D_SYSTEM_GetRenderObj(G3D_SYSTEM_GetObjectRender(obj));
    NNS_G3dGlbBaseTrans(&status->trans);
    NNS_G3dGlbSetBaseRot(&status->rotate);
    NNS_G3dGlbBaseScale(&status->scale);
    _G3dSystem.work->glbFlushFunc();
    visible = G3D_SYSTEM_CheckObjectCulling(obj);
    if (visible == 1)
        G3D_SYSTEM_DrawRenderObj(rndObj);
    return visible;
}

/* Box-test the object's model bounding box, scaled by its box scale. */
BOOL G3D_SYSTEM_CheckObjectCulling(G3dObject *obj)
{
    GXBoxTestParam box;
    fx32 scale[3];
    int popCount;
    NNSG3dResMdlInfo *info;
    NNSG3dResMdl *resMdl;
    BOOL visible;

    visible = 1;
    resMdl = G3D_SYSTEM_GetRenderObj(G3D_SYSTEM_GetObjectRender(obj))->resMdl;
    info = (resMdl != 0 ? &resMdl->info : 0);

    box.x = info->boxX;
    box.y = info->boxY;
    box.z = info->boxZ;
    box.width = info->boxW;
    box.height = info->boxH;
    box.depth = info->boxD;
    NNS_G3dGeBufferOP_N(G3OP_PUSH_MTX, 0, 0);

    scale[0] = info->boxPosScale;
    scale[1] = scale[0];
    scale[2] = scale[0];
    NNS_G3dGeBufferOP_N(G3OP_SCALE, scale, 3);

    if (G3D_SYSTEM_BoxTest(&box) == 0) {
        visible = 0;
    }

    popCount = 1;
    NNS_G3dGeBufferOP_N(G3OP_POP_MTX, &popCount, 1);
    return visible;
}

/* Run a box test; TRUE when the box is in view. */
BOOL G3D_SYSTEM_BoxTest(const GXBoxTestParam *box)
{
    s32 result;
    int polygonAttr;
    int primitive;

    result = 1;
    polygonAttr = 0x30C1;
    NNS_G3dGeBufferOP_N(G3OP_POLYGON_ATTR, &polygonAttr, 1);
    primitive = 0;
    NNS_G3dGeBufferOP_N(G3OP_BEGIN_VTXS, &primitive, 1);
    NNS_G3dGeBufferOP_N(G3OP_END_VTXS, 0, 0);
    NNS_G3dGeBufferOP_N(G3OP_BOX_TEST, box, 3);
    NNS_G3dGeFlushBuffer();
    while (G3X_GetBoxTestResult(&result) != 0) {
        ;
    }
    return result;
}

/* Draw a render object: count its polygons and vertices, run the draw callback, draw. */
void G3D_SYSTEM_DrawRenderObj(NNSG3dRenderObj *rndObj)
{
    _G3dSystem.polygonCount += rndObj->resMdl->info.numPolygon;
    _G3dSystem.vertexCount += rndObj->resMdl->info.numVertex;
    if (_G3dSystem.work->drawCallback != 0)
        _G3dSystem.work->drawCallback(rndObj, _G3dSystem.work->drawCallbackArg);
    NNS_G3dDraw(rndObj);
}

void G3D_SYSTEM_ResetDrawCounts(void)
{
    _G3dSystem.polygonCount = 0;
    _G3dSystem.vertexCount = 0;
}
