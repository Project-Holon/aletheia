/*
 * file:     shinka_demo_view.c
 * unit:     yes
 * function: func_022058F8, func_022059A0, func_022059FC, func_02205A10, func_02205A1C, func_02205A28, func_02205A34, func_02205A84, func_02205AAC, func_02205AC0, func_02205B24, func_02205B60, func_02205B64, func_02205B6C, func_02205BAC, func_02205BC8, func_02205BD0, func_02205BD8, func_02205BDC, func_02205C48, func_02205C58, func_02205C6C, func_02205C74, func_02205D28, func_02205D50, func_0220602C, func_02206044, func_0220604C, func_02206050, func_02206058, func_0220605C, func_02206064, func_0220606C, func_02206070, func_02206074, func_02206078, func_0220609C, func_022060BC, func_022060C8, func_02206108, func_0220623C, func_02206264, func_02206274, func_022063AC, func_022063E0, func_022065C8, func_02206604, func_02206664, func_0220672C, func_0220673C, func_02206750, func_02206768, func_022067B0, func_022067BC, func_022067FC, func_0220682C, func_0220685C, func_02206A3C, func_02206A5C, func_02206E2C, func_02207510, func_022076A0, func_02207868, func_022081A4, func_0220826C, func_0220827C, func_022082DC, func_022083CC, func_022083DC, func_022083EC, func_02208410, func_02208420, func_02208430, func_02208478, func_02208514, func_0220851C, func_02208570, func_022086BC, func_022086C8, func_02208714, func_0220871C, func_02208770, func_0220878C, func_02208804, func_02208814, func_0220882C, func_02208844, func_02208850, func_02208860, func_0220887C, func_02208994, func_022089A4, func_02208A24, func_02208A2C, func_02208A38, func_02208A48, func_02208A54, func_02208A6C, func_02208A78, func_02208AB0, func_02208B54, func_02208B6C, func_02208C10, func_02208C18, func_02208C28, func_02208C30
 * address:  0x022058F8
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02208F50 0x02208F50 data a4
 *   d_02208CEC 0x02208CEC data a4
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_ResetTextColor 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   d_02208CA0 0x02208CA0 data a4
 *   d_02208D1C 0x02208D1C data a4
 *   func_0203FC6C 0x0203FC6C arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   d_020A1EB8 0x020A1EB8 data a4
 *   d_02208C88 0x02208C88 data a4
 *   d_02208C7C 0x02208C7C data a4
 *   d_02208C94 0x02208C94 data a4
 *   func_02205854 0x02205854 thumb ov195
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_02047964 0x02047964 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   d_02208F68 0x02208F68 data
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   func_02019CE0 0x02019CE0 thumb
 *   POKE_TOOL_ChangeSpecies 0x020178D8 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   PM_VOICE_Play 0x02006984 thumb
 *   PM_VOICE_IsAnyActive 0x02006650 thumb
 *   MCSS_SetPaletteFade 0x02015F50 thumb
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb
 *   MCSS_CheckPaletteFade 0x0201600C thumb
 *   MCSS_GetAnimCtrl 0x02015EE8 thumb
 *   func_02064CBC 0x02064CBC arm
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw 0x02014D2C thumb
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *   MCSS_Exit 0x02014BA8 thumb
 *   MCSS_TOOL_AddPokeMcss 0x02017270 thumb
 *   MCSS_SetShadowVanishFlag 0x02015FF0 thumb
 *   MCSS_TOOL_SetAnimeStopCallback 0x020173B4 thumb
 *   MCSS_SetScale 0x02015CAC thumb
 *   _fgr 0x0209BBB0 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   MCSS_Del 0x02015BA4 thumb
 *   MCSS_GetSizeY 0x02015F0C thumb
 *   MCSS_GetOfsY 0x02015F1C thumb
 *   MCSS_GetOfsX 0x02015F14 thumb
 *   MCSS_SetOfsPosition 0x02015C78 thumb
 *   _ffltu 0x0209BE04 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   MCSS_GetPosition 0x02015C30 thumb
 *   MCSS_SetPosition 0x02015C48 thumb
 *   d_02208E74 0x02208E74 data
 *   d_02208E80 0x02208E80 data
 *   FX_SinCosTable_ 0x020A1B38 data
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   func_02017EAC 0x02017EAC thumb
 *   d_02208E8C 0x02208E8C data
 *   d_02148BCC 0x02148BCC data
 *   G3D_SYSTEM_GetProjection 0x020467EC arm
 *   G3D_SYSTEM_GetLookAt 0x02046AFC arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   NNS_G3dGlbBaseTrans 0x0206A9DC arm
 *   func_02082B60 0x02082B60 arm
 *   NNS_G3dGlbBaseScale 0x0206AA0C arm
 *   func_0206DB80 0x0206DB80 arm
 *   G3D_SYSTEM_SetProjection 0x02046858 arm
 *   G3D_SYSTEM_SetLookAt 0x02046B40 arm
 *   BMP_Create 0x02043678 arm
 *   POKEGRA_GetArcID 0x0202D060 thumb
 *   POKEGRA_GetCgrArcIndex 0x0202D064 thumb
 *   POKEGRA_GetPalArcIndex 0x0202D0D4 thumb
 *   ARC_UTIL_LoadScreenDataFromArchive 0x02049E34 arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   BMP_GetPixels 0x020437D4 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_02082A90 0x02082A90 arm
 *   BMP_ConvertToLinear 0x02044F64 arm
 *   func_02061CA4 0x02061CA4 arm
 *   BMP_Delete 0x020437AC arm
 *   _s32_div_f 0x0209C0A4 arm
 *   _ll_mul 0x0209C054 arm
 *   FX_Sqrt 0x0207C7B4 arm
 *   func_0207C768 0x0207C768 arm
 *   FX_SinCosTable__Alt 0x020A1B38 data
 *   func_0207B640 0x0207B640 thumb
 *   MTX_MultVec43 0x0207BC08 arm
 *   func_0207C7E8 0x0207C7E8 arm
 *   d_02208E4C 0x02208E4C data
 *   d_02208E38 0x02208E38 data
 *   d_02208F7C 0x02208F7C data
 *   d_02208ED0 0x02208ED0 data
 *   func_02208C30 0x02208C30 thumb ov195
 *   d_02208F24 0x02208F24 data
 *   d_02208F30 0x02208F30 data
 *   d_02208E9C 0x02208E9C data
 *   PARTICLE_InitManager 0x02050B80 arm
 *   PARTICLE_CreateSystem 0x02050C30 arm
 *   PARTICLE_ReleaseCamera 0x02051758 arm
 *   PARTICLE_InitCamera 0x02051648 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   BUTTON_MAN_GetResourceType 0x02051B04 arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   PARTICLE_KillAllEffects 0x02051620 arm
 *   PARTICLE_Main 0x02050BE8 arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   d_02208EC0 0x02208EC0 data
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_020489F4 0x020489F4 arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 */
#include "../../matched/include/Obj24951.h"
#include "../../matched/include/Obj24952.h"
#include "../../matched/include/Obj14529.h"
#include "../../matched/include/Obj24953.h"
#include "../../matched/include/Obj24957.h"
#include "../../matched/include/Obj02911.h"
#include "../../matched/include/Obj08349.h"
#include "../../matched/include/Obj10822.h"
#include "../../matched/include/Obj10824.h"
#include "../../matched/include/Obj08348.h"
#include "../../matched/include/Obj24968.h"
#include "../../matched/include/Obj00300.h"
#include "../../matched/include/Obj14534.h"
#include "../../matched/include/Obj10826.h"
#include "../../matched/include/Obj10827.h"
#include "../../matched/include/Obj24975.h"
#include "../../matched/include/Obj24976.h"
#include "../../matched/include/Obj24977.h"
#include "../../matched/include/Obj24978.h"
#include "../../matched/include/Obj24979.h"
#include "../../matched/include/Obj10829.h"
#include "../../matched/include/Obj05518.h"
#include "../../matched/include/Obj08350.h"
#include "../../matched/include/Obj10830.h"
#include "../../matched/include/Obj24981.h"
#include "../../matched/include/Obj14537.h"
#include "../../matched/include/Obj00687.h"
#include "../../matched/include/Obj00789.h"

#define W(n) (*(u32 *)(p+(n)))
#define P(n) (*(void **)(p+(n)))
#define B(n) (*(u8 *)(p+(n)))
#define NODE(i) (*(void **)(p+0x50+(u32)(i)*4))
#define REG_MTX_MODE     (*(vu32 *)0x04000440)
#define REG_MTX_IDENTITY (*(vu32 *)0x04000454)
#define REG_DIF_AMB      (*(vu32 *)0x040004C0)
#define REG_SPE_EMI      (*(vu32 *)0x040004C4)
#define REG_MTX_PUSH       (*(vu32 *)0x04000444)
#define REG_MTX_POP        (*(vu32 *)0x04000448)
#define REG_MTX_TRANS      (*(vu32 *)0x04000470)
#define REG_NORMAL         (*(vu32 *)0x04000484)
#define REG_TEXCOORD       (*(vu32 *)0x04000488)
#define REG_VTX_16         (*(vu32 *)0x0400048C)
#define REG_POLYGON_ATTR   (*(vu32 *)0x040004A4)
#define REG_TEXIMAGE_PARAM (*(vu32 *)0x040004A8)
#define REG_TEXPLTT_BASE   (*(vu32 *)0x040004AC)
#define REG_BEGIN_VTXS     (*(vu32 *)0x04000500)
#define REG_END_VTXS       (*(vu32 *)0x04000504)
#define G(n) (*(u32 *)(p+(n)))
#define Q(n) (*(int *)(q+(n)))
#define H(n) (*(s16_02207868 *)(p+(n)))
#define V(n) (*(Vec *)(q+(n)))
#define REG_MTX_SCALE      (*(vu32 *)0x0400046C)
struct DispVram;
struct Node;
struct BgTemplate;
struct BgVramReq;
struct DispConfig;
struct Cfg;
struct Bank;
struct RecDC;
struct McssFade;
struct Obj;
struct Owner;
struct McssSys;
struct Quad;
struct Light;
struct Fade;
struct Grid;
struct Bmp;
struct Obj020437AC;
struct Ptc;
struct Anim;
struct Dst648;
struct Src648;
struct Rec;
struct Transform;
struct Arg;
struct G3dSys;
struct AnmCtl;
struct Ctx;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

typedef struct {
    u32 id;
    u8 data[0x20];
    u32 len;
    u32 mode;
} Entry;

typedef signed short s16;

typedef signed int     s32;

typedef int fx32_02205AC0;

typedef s32 fx32_02206108;

typedef s32 fx32;

typedef s16 fx16;

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct Cell {
    u32 f00;
    fx32 s0, s1, t0, t1;
    u8 visible;
    u8 pad15;
    fx16 v[4][3];
    u8 pad2e[2];
    s32 f30;
    VecFx32 v34;
    s32 f40, f44, f48, f4c, f50, f54, f58, f5c, f60, f64;
    VecFx32 cur;
    VecFx32 org;
} Cell;

typedef struct Row {
    Cell cell[0x12];
} Row;

typedef struct CharData {
    u8 pad00[0x14];
    u8 *raw;
} CharData;

typedef struct PlttData {
    u8 pad00[0xc];
    void *raw;
} PlttData;

typedef struct Grid {
    CharData *chr;
    PlttData *pltt;
    void *chrRes;
    void *plttRes;
    void *canvas;
    u32 tex;
    u32 plttAddr;
    VecFx32 v;
    s32 state;
    u16 pal[16];
    u16 color;
    s16 fcur;
    s16 fend;
    s16 fwait;
    s16 fstep;
    s16 flevel;
    s16 fcount;
    s16 x0, y0, x1, y1;
    u8 pad62[2];
    s32 f64, f68, f6c, f70;
    Row row[0x12];
    u8 rows;
} Grid;

typedef struct Quad {
    u32 tex;
    u32 pltt;
    fx32 tx, ty, tz;
    fx32 sx, sy, sz;
    u32 polyId;
    fx32 s0, s1, t0, t1;
    u8 alpha;
    u8 pad35;
    fx16 v[4][3];
    u8 f4e;
} Quad;

typedef struct Work {
    u32 f00;
    void *camera;
    Grid *grid[2];
    Quad *quad;
} Work;

typedef struct Owner {
    u16 heap;
    u16 pad02;
    void *res0;
    u32 f08;
    u16 f0c;
    u16 pad0e;
    void *res1;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u8 pad28[0x34 - 0x28];
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    float scale;
    u8 f48;
    u8 pad49[3];
    void *sys;
    void *obj[2];
    Work *work;
    u32 f5c;
} Owner;

typedef volatile u32 vu32;

typedef struct MtxFx33 {
    fx32 m[3][3];
} MtxFx33;

typedef struct GlbState {
    u8 pad00[0x3c];
    MtxFx33 baseRot;
    u8 pad60[0x7c - 0x60];
    u32 flag;
} GlbState;

typedef signed char s8;

typedef struct SC {s16 s;s16 c;} SC;

typedef signed short s16_022076A0;

typedef short s16_02207868;

typedef long fx32_02207868;

typedef struct {fx32_02207868 x,y,z;} Vec;

typedef struct {fx32_02207868 a[12];} Matrix;

typedef signed short s16_022081A4;

typedef signed short s16_0220826C;

typedef struct Node {
    u16 f00;
    u16 pad02;
    fx32 tx, ty, tz;
    fx32 sx, sy, sz;
    u8 mtx[0x24];
    u8 pad40[4];
} Node;

typedef struct Anim_0220871C {
    u16 heap;
    u16 pad02;
    u32 f04;
    u32 f08;
    u32 f0c;
    void *ptc;
    void *res;
    u16 f18;
    u16 f1a;
    u16 count;
    u16 pad1e;
    void *nodes;
    u32 f24;
    u32 f28;
} Anim_0220871C;

typedef struct Anim_0220878C {
    u16 heap;
    u16 pad02;
    u32 f04;
    u32 state;
    u32 wait;
    void *ptc;
} Anim_0220878C;

typedef struct EmitParam {
    u32 f00;
    fx32 f04;
    fx32 f08;
    u32 f0c;
    u32 f10;
    fx32 f14;
    u32 f18;
    u32 f1c;
} EmitParam;

typedef struct Ptc {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 pad06;
    void *f08;
    u8 work[0x4800];
    void *spl;
    u8 f4810;
    u8 pad4811[3];
    u32 f4814;
    s32 f4818;
} Ptc;

typedef signed short s16_022089A4;

typedef struct Cue {
    u16 frame;
    u8 emit;
    u8 id;
} Cue;

typedef struct Emit {
    u8 work[0x4800];
    void *spl;
    u8 res;
    u8 pad[3];
} Emit;

typedef struct Ptc_022089A4 {
    u16 frame;
    u16 cue;
    u16 ncue;
    u16 pad06;
    Cue *cues;
    Emit emit[1];
    u32 active;
    s32 timer;
} Ptc_022089A4;

typedef short s16_02208A38;

typedef struct Ptc_02208A48 {
    u16 frame;
    u16 cue;
    u16 ncue;
    u16 pad06;
    void *cues;
    Emit emit[1];
    u32 active;
    s32 timer;
} Ptc_02208A48;

typedef short s16_02208A6C;

typedef short s16_02208A78;

typedef struct Node_02208A78 {u16 id,pad02;int tx,ty,tz,sx,sy,sz;u8 mtx[0x24];u32 f40;} Node_02208A78;

typedef struct Anim_02208A78 {u16 heap;u8 pad02[0x12];void *res;u16 f18,f1a,count,pad1e;Node_02208A78 *nodes;u32 f24,f28;} Anim_02208A78;

typedef struct Node_02208AB0 {
    u16 id;
    u16 pad02;
    fx32 tx, ty, tz;
    fx32 sx, sy, sz;
    u8 mtx[0x24];
    u32 f40;
} Node_02208AB0;

typedef struct Anim_02208AB0 {
    u16 heap;
    u8 pad02[0x12];
    void *res;
    u16 f18;
    u16 f1a;
    u16 count;
    u16 pad1e;
    Node_02208AB0 *nodes;
    u32 f24;
    u32 f28;
} Anim_02208AB0;

typedef struct Anim_02208C10 {
    u8 pad00[0x28];
    int state;
} Anim_02208C10;

typedef struct Anim_02208C18 {
    u8 pad00[0x28];
    int state;
} Anim_02208C18;

typedef struct Anim_02208C28 {
    u8 pad00[0x28];
    int state;
} Anim_02208C28;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void MI_CpuFill8(void *, int, int);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_ResetTextColor(void);
extern u32 func_020056A0(void *, void *, int);
extern void func_02030EAC(struct Node *n);
extern void GF_FONT_SetDefaultTextColor(void);
extern u32 func_020307B0(void *p);
extern void func_0203FC6C(const struct BgVramReq *req, u32 which);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8, u8);
extern void func_020403F4(u32 i);
extern void func_0203F8F4(void *);
extern void BMP_WIN_Init(void *);
extern void func_0203FC28(struct DispConfig *cfg);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(int);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void func_02205854(void);
extern void G3D_SYSTEM_Init(int, int, int, int, int, void *, void *);
extern u32 G3D_CAMERA_Create(int, int, int, int, int, int, int, int, void *, void *, void *, void *);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(int);
extern void func_02047964(void);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void G3D_SYSTEM_DrawEnd(void);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern void POKE_TOOL_ChangeSpecies(void *p, u32 a);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern u32 PM_VOICE_Play(u32,u32,u32,u32,u32,u32,u32,u32);
extern int PM_VOICE_IsAnyActive(void);
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void MCSS_SetAnmStopFlag(void *);
extern int MCSS_CheckPaletteFade(void *);
extern void *MCSS_GetAnimCtrl(void *);
extern void func_02064CBC(struct Obj *);
extern void MCSS_ResetVanishFlag(void *);
extern void MCSS_SetVanishFlag(void *);
extern void MCSS_ResetAnmStopFlag(void *);
extern void MCSS_Main(char *);
extern void MCSS_Draw(struct McssSys *sys);
extern void *MCSS_Init(u32 id, void *heap);
extern void MCSS_SetTextureTransAdrs(void *p, u32 v);
extern void MCSS_SetOrthoMode(void *obj);
extern void MCSS_Exit(u8 *a0);
extern void *MCSS_TOOL_AddPokeMcss(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void MCSS_SetShadowVanishFlag(char *p, int v);
extern int MCSS_TOOL_SetAnimeStopCallback(int a0);
extern void MCSS_SetScale(void *p, u32 *src);
extern void MCSS_Del(void *sys, void *obj);
extern u16 MCSS_GetSizeY(void *p);
extern s16 MCSS_GetOfsY(void *p);
extern s16 MCSS_GetOfsX(void *p);
extern void MCSS_SetOfsPosition(void *p, u32 *src);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_SetPosition(void *p, u32 *src);
extern u8 POKE_TOOL_GetGender(void *p);
extern u32 func_02017EAC(void *p);
extern void G3D_SYSTEM_GetProjection(int p0);
extern void G3D_SYSTEM_GetLookAt(u8 *dst);
extern void func_0207ADC4(MtxFx33 *m);
extern void NNS_G3dGlbBaseTrans(const VecFx32 *trans);
extern void func_02082B60(const MtxFx33 *src, MtxFx33 *dst);
extern void NNS_G3dGlbBaseScale(const VecFx32 *scale);
extern void func_0206DB80(void);
extern void G3D_SYSTEM_SetProjection(const u32 *src);
extern void G3D_SYSTEM_SetLookAt(u8 *a0);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern int POKEGRA_GetArcID(void);
extern s32 POKEGRA_GetCgrArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 POKEGRA_GetPalArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void *ARC_UTIL_LoadScreenDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern struct Bmp *BMP_ConvertToLinear(struct Bmp *src, u32 keep, u16 heap);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void BMP_Delete(struct Obj020437AC *p);
extern int FX_Sqrt(int);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_0207B640(Matrix *,fx32_02207868,fx32_02207868);
extern void MTX_MultVec43(const Vec *,const Matrix *,Vec *);
extern fx32_02207868 func_0207C7E8(fx32_02207868);
extern int func_02208C30(Anim_02208C28 *p);
extern void PARTICLE_InitManager(u32 heap);
extern void *PARTICLE_CreateSystem(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap);
extern int PARTICLE_ReleaseCamera(int a0);
extern void PARTICLE_InitCamera(struct Dst648 *this, struct Src648 *src, u16 a2, int *a3, int *a4, int *a5, u32 a6);
extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);
extern u16 BUTTON_MAN_GetResourceType(void *res);
extern void PARTICLE_SetupSystem(void *spl, u32 res, u32 a2, u32 a3);
extern void PARTICLE_ExitManager(void);
extern int PARTICLE_StartEffect(void *p, int b, int c);
extern void PARTICLE_KillAllEffects(void *spl);
extern void PARTICLE_Main(void);
extern int G3D_UTIL_Create(int, int, int);
extern void G3D_UTIL_Delete(struct Rec *);
extern u32 func_02048A18(u8 *a0, int i);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);
extern u16 G3D_UTIL_AddUnit(void *res, void *name);
extern u32 func_020489F4(u8 *a0, int i);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern int G3D_SYSTEM_IncObjectAnimeFrame(void *a, int idx, int amount);
char *func_022058F8(u32 a, u32 b);
void func_022059A0(char *p);
void func_022059FC(char *a);
void func_02205A10(char *a);
void func_02205A1C(char *a);
int func_02205A28(char *a);
void func_02205A34(void);
void func_02205A84(int a0);
void func_02205AAC(int a, char *b);
void func_02205AC0(void *a, void *b);
void func_02205B24(void *p);
void func_02205B60(void *a0);
void func_02205B64(void *a0);
void func_02205B6C(unsigned char *p, int a, u32 b);
void func_02205BAC(char *a);
void func_02205BC8(void *a0);
void func_02205BD0(void *a0);
int func_02205BD8(int *p);
void func_02205BDC(u32 *a, void *b);
void func_02205C48(int *p);
void func_02205C58(char *a);
void func_02205C6C(void *p);
Owner *func_02205C74(u16 heap, u32 f08, void *res0, u16 f0c);
void func_02205D28(char *p);
void func_02205D50(char *p);
void func_0220602C(Owner *o);
void func_02206044(int *p);
int func_0220604C(int *p);
void func_02206050(int *p);
int func_02206058(int *p);
void func_0220605C(int *p);
void func_02206064(int *p);
int func_0220606C(int *p);
int func_02206070(int *p);
int func_02206074(int *p);
int func_02206078(int *p);
void func_0220609C(char *a);
void func_022060BC(char *p);
fx32_02205AC0 func_022060C8(void *p);
void func_02206108(Owner *o);
void func_0220623C(Owner *o);
u8 func_02206264(u8 i);
void func_02206274(Owner *o);
void func_022063AC(char *a, u32 v);
void func_022063E0(Owner *o);
void func_022065C8(char *p);
void func_02206604(Owner *o);
void func_02206664(Owner *o);
void func_0220672C(Owner *o);
int func_0220673C(int *p);
void func_02206750(int *p);
void func_02206768(char *a, u32 x, u32 y, u32 z);
void func_022067B0(char *a, int b, int c, int d, int e);
void func_022067BC(Owner *o);
int func_022067FC(char *a);
int func_0220682C(char *a);
Grid *func_0220685C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 tex, u32 pltt, u16 heap);
void func_02206A3C(char *p, int a1);
void func_02206A5C(Grid *p, u16 heap);
void func_02206E2C(Grid *p, u16 heap);
void func_02207510(Grid *w, u16 heap);
void func_022076A0(Owner *o);
void func_02207868(char *p,u16 heap);
void func_022081A4(Grid *p, int unused, u16 color, s16_022081A4 cur, s16_022081A4 end, s16_022081A4 wait, s16_022081A4 step);
int func_0220826C(Grid *p, int x);
void func_0220827C(Grid *p, int x);
void func_022082DC(Grid *p, int x);
int func_022083CC(char *p, u16 a1);
int func_022083DC(char *p, u16 heap);
void func_022083EC(Grid *p, int x);
int func_02208410(char *p, u16 heap);
int func_02208420(char *p, u16 heap);
void func_02208430(Grid *p, int x);
Quad *func_02208478(u32 tex, u32 pltt, u16 heap);
void func_02208514(void *p,int n);
void func_0220851C(Quad *p, u16 heap);
void func_02208570(Quad *p, u16 heap);
void func_022086BC(char *a, int b, int c, int d, int e);
Node *func_022086C8(u16 heap, u16 n);
void func_02208714(void *p);
Anim_0220871C *func_0220871C(u16 heap, u32 x);
void func_02208770(char *a);
void func_0220878C(Anim_0220878C *p);
void func_02208804(char *a);
void func_02208814(char *a);
void func_0220882C(int *p);
void func_02208844(int *p);
int func_02208850(int *p);
int func_02208860(int *p);
Ptc *func_0220887C(u16 heap, u16 a, void *b);
void func_02208994(char *a);
void func_022089A4(Ptc_022089A4 *p);
void func_02208A24(int a0);
void func_02208A2C(char *p);
void func_02208A38(char *p,u32 v);
void func_02208A48(Ptc_02208A48 *p, s32 timer);
void func_02208A54(char *a);
void func_02208A6C(char *p);
void func_02208A78(Anim_02208A78 *p);
void func_02208AB0(Anim_02208AB0 *p);
void func_02208B54(char *a);
void func_02208B6C(char *p);
void func_02208C10(Anim_02208C10 *p);
int func_02208C18(Anim_02208C18 *p);
void func_02208C28(Anim_02208C28 *p);
extern u32 d_02208F50[];
extern u32 d_02208CEC[];
extern u8 d_02208CA0[];
extern Entry d_02208D1C[];
extern const s16 d_020A1EB8[];
extern u32 d_02208C88[];
extern u32 d_02208C7C[];
extern u32 d_02208C94[];
extern char d_02208F68[];
extern const VecFx32 d_02208E74;
extern const VecFx32 d_02208E80;
extern const s16 FX_SinCosTable_[];
extern const VecFx32 d_02208E8C;
extern GlbState d_02148BCC;
extern const SC FX_SinCosTable__Alt[];
extern const s16 d_02208E4C[];
extern const u8 d_02208E38[];
extern char d_02208F7C[];
extern char d_02208ED0[];
extern const VecFx32 d_02208F24;
extern const VecFx32 d_02208F30;
extern const u32 d_02208E9C[2];
extern char d_02208EC0[];







char *func_022058F8(u32 a, u32 b)
{
    char *p = func_02030734(b, 0x10, 0, (const char *)d_02208F50, 0x1df);

    MI_CpuFill8(p, 0, 0x10);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    *(volatile u32 *)0x04001000 &= 0xffff1fff;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_02208CEC);
    BG_SYS_SetLcdSwap(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_ResetTextColor();
    func_02205AC0(p, (void *)b);
    func_02205B6C((unsigned char *)(p + 4), (int)d_02208CEC, b);
    func_02205BDC((u32 *)(p + 8), (void *)b);
    ((struct Obj24951 *)p)->fC = func_020056A0(func_02205AAC, p, 0);
    return p;
}






/*
 * volatile: hardware 04000050/04001050 writes and 04000000/04001000 read/write at 022059C2-022059DC.
 */
void func_022059A0(char *p)
{
    func_02030EAC(((struct Obj24952 *)p)->fC);
    func_02205C48((int *)(p + 8));
    func_02205BAC(p + 4);
    func_02205B24(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p, 0, 0x10);
    func_020307B0(p);
}







void func_022059FC(char *a)
{
    func_02205BC8(a + 4);
    func_02205B60(a);
}







void func_02205A10(char *a)
{
    func_02205C58(a + 8);
}







void func_02205A1C(char *a)
{
    func_02205C6C(a + 8);
}







int func_02205A28(char *a)
{
    return func_02205BD8((int *)(a + 4));
}






/*
 * The `(int)i` cast on the id read (permuter, seed 6401) keeps the id load
 * and the element address separate values, so `adds r6, r7, r0` is emitted
 * inside the guarded block instead of hoisted above the `cmp`.
 */
void func_02205A34(void)
{
    u32 i;

    func_0203FC6C((const struct BgVramReq *)d_02208CA0, (int)1);
    for (i = 0; i < 6; i++) {
        u32 v = d_02208D1C[(int)i].id;
        if (v >= 4) {
            Entry *e = &d_02208D1C[i];
            func_0203FCA0((u8)v, (const struct BgTemplate *)e->data, (u8)e->len);
            func_020414AC(v);
            func_02040588(v, e->mode);
        }
    }
}






void func_02205A84(int a0)
{
    unsigned int i;
    for (i = 0; i < 6; i++)
    {
        unsigned int v = d_02208D1C[i].id;
        if (v >= 4)
        {
            func_020403F4(v & 0xff);
        }
    }
}






void func_02205AAC(int a, char *b)
{
    func_02205B64(b);
    func_02205BD0(b + 4);
}




#define FX_F32_TO_FX32(x) \
    ((fx32_02206108)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))









/*
 * Twin of func_02205A34: the `(int)i` cast on the id read keeps the element
 * address from being hoisted above the guard.
 */
void func_02205AC0(void *a, void *b)
{
    u32 i;

    MI_CpuFill8(a, 0, 4);
    func_0203F8F4(b);
    BMP_WIN_Init(b);
    func_0203FC28((struct DispConfig *)d_02208CA0);
    for (i = 0; i < 6; i++) {
        u32 v = d_02208D1C[(int)i].id;
        if (v <= 3) {
            Entry *e = &d_02208D1C[i];
            func_0203FCA0((u8)v, (const struct BgTemplate *)e->data, (u8)e->len);
            func_020414AC(v);
            func_02040588(v, e->mode);
        }
    }
}








void func_02205B24(void *p) {u32 i;for(i=0;i<6;i++){u32 id=d_02208D1C[i].id;if(id<=3)func_020403F4((u8)id);}BMP_WIN_Exit();func_0203F9B4();MI_CpuFill8(p,0,4);}









/*
 * extent: two trailing bytes of zero alignment padding.
 */
void func_02205B60(void *a0) {}








void func_02205B64(void *a0){func_020419E4();}









void func_02205B6C(unsigned char *p, int a, u32 b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x02208CB0, a, b);
    ((struct Obj14529 *)p)->f0 = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(((struct Obj14529 *)p)->f0);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}









void func_02205BAC(char *a)
{
    CLACT_ExitSystem(CLACT_DeleteUnit((struct Bank *)(((struct Obj24953 *)a)->f0)));
    MI_CpuFill8(a, 0, 4);
}








void func_02205BC8(void *a0){CLACT_DrawSystem();}








void func_02205BD0(void *a0){CLACT_VBlankSystem();}








int func_02205BD8(int *p)
{
    return *p;
}









void func_02205BDC(u32 *a, void *b)
{
    G3D_SYSTEM_Init(0, 2, 0, 1, 0, b, func_02205854);
    *a = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0,
                       d_02208C88, d_02208C7C, d_02208C94, b);
}









void func_02205C48(int *p)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}









void func_02205C58(char *a)
{
    func_02047964();
    G3D_CAMERA_Reset((struct Light *)((struct Obj24957 *)a)->f0);
    G3D_SYSTEM_ApplyLookAt();
}









void func_02205C6C(void *p)
{
    G3D_SYSTEM_DrawEnd();
}









Owner *func_02205C74(u16 heap, u32 f08, void *res0, u16 f0c)
{
    Owner *o = func_02030734(heap, 0x60, 1, d_02208F68, 0x201);

    o->heap = heap;
    o->f08 = f08;
    o->res0 = res0;
    o->f0c = f0c;
    o->res1 = 0;
    if (f08 == 0) {
        o->res1 = func_02030734(o->heap, POKE_TOOL_GetPartyParamSize(), 1, d_02208F68, 0x213);
        func_02019CE0(o->res0, o->res1);
        POKE_TOOL_ChangeSpecies(o->res1, o->f0c);
    }
    if (o->f08 == 0)
        o->f14 = 0;
    else
        o->f14 = 0x16;
    o->f18 = 0;
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f34 = 0;
    o->f38 = 0;
    o->f3c = 0;
    o->f40 = 0;
    o->scale = 16.0f;
    if (o->f08 == 0)
        o->f48 = 0;
    else
        o->f48 = 1;
    func_0220609C((char *)o);
    func_02206108((Owner *)o);
    func_022063E0((Owner *)o);
    o->f5c = 1;
    return o;
}








void func_02205D28(char *p){func_022065C8(p);func_0220623C((Owner *)((Owner *)p));func_022060BC(p);if(((struct Obj02911 *)p)->f10)func_020307B0(((struct Obj02911 *)p)->f10);func_020307B0(p);}








void func_02205D50(char *p)
{
    switch(W(0x14)) {
    case 0:
        if(W(0x1c)) {
            u32 a,b;
            W(0x14)=1;
            a=POKE_TOOL_GetPartyValue(P(4),5,0);
            b=POKE_TOOL_GetPartyValue(P(4),0x6f,0);
            PM_VOICE_Play(a,b,0x40,0,0,0,0,0);
        }
        break;
    case 1:
        if(!PM_VOICE_IsAnyActive()){W(0x14)=2;W(0x20)=1;}
        break;
    case 2:if(W(0x24))W(0x14)=3;break;
    case 3:
        W(0x14)=4;
        MCSS_SetPaletteFade((struct McssFade *)NODE(B(0x48)),0,16,0,0x7fff);
        MCSS_SetPaletteFade((struct McssFade *)NODE(func_02206264(B(0x48))),16,16,0,0x7fff);
        MCSS_SetAnmStopFlag(NODE(B(0x48)));
        break;
    case 4:if(!MCSS_CheckPaletteFade(NODE(B(0x48))))W(0x14)=5;break;
    case 5:
        if(W(0x18)>=8){W(0x14)=6;W(0x18)=0;}
        else W(0x18)++;
        break;
    case 6:
        W(0x14)=8;
        func_022063AC(p,0x100000);
        func_02206768(p,0,0xfffff800,0);
        W(0x5c)=0;
        func_02064CBC((struct Obj *)MCSS_GetAnimCtrl(NODE(B(0x48))));
        break;
    case 7:
        if(W(0x18)>=1){W(0x14)=8;W(0x18)=0;}
        else W(0x18)++;
        break;
    case 8:W(0x14)=9;func_022067BC((Owner *)((struct Owner *)p));break;
    case 9:
        if(func_022067FC(p)){W(0x14)=10;W(0x38)=1;func_0220672C((Owner *)((struct Owner *)p));}
        break;
    case 10:if(func_0220682C(p))W(0x14)=11;break;
    case 11:
        if(W(0x18)>=30){W(0x14)=13;W(0x18)=0;W(0x3c)=1;W(0x28)=1;}
        else W(0x18)++;
        break;
    case 12:if(func_0220682C(p)){W(0x14)=13;W(0x3c)=1;W(0x28)=1;}break;
    case 13:if(W(0x2c))W(0x14)=14;break;
    case 14:
        W(0x14)=15;
        if(W(0x40))W(0x18)=0;
        else {
            B(0x48)=func_02206264(B(0x48));
            MCSS_ResetVanishFlag(NODE(B(0x48)));
            MCSS_SetVanishFlag(NODE(func_02206264(B(0x48))));
            W(0x18)=30;
        }
        func_022063AC(p,0);
        func_02206768(p,0x100000,0xfffff800,0);
        W(0x5c)=1;
        break;
    case 15:if(W(0x30))W(0x14)=16;break;
    case 16:
        W(0x14)=17;
        MCSS_SetPaletteFade((struct McssFade *)NODE(B(0x48)),16,0,1,0x7fff);
        break;
    case 17:
        if(!MCSS_CheckPaletteFade(NODE(B(0x48)))){W(0x14)=18;MCSS_ResetAnmStopFlag(NODE(B(0x48)));}
        break;
    case 18:
        if(!W(0x18)){W(0x14)=19;W(0x18)=0;}
        else W(0x18)--;
        break;
    case 19:
        {
            void *obj;
            u32 a,b;
            W(0x14)=20;
            if(W(0x40))obj=P(4);else obj=P(0x10);
            a=POKE_TOOL_GetPartyValue(obj,5,0);
            b=POKE_TOOL_GetPartyValue(obj,0x6f,0);
            PM_VOICE_Play(a,b,0x40,0,0,0,0,0);
        }
        break;
    case 20:if(!PM_VOICE_IsAnyActive()){W(0x14)=21;W(0x18)=0;W(0x34)=1;}break;
    case 21:case 22:break;
    }
    if(W(0x5c))MCSS_Main(P(0x4c));
    func_02206604((Owner *)((struct Owner *)p));
}









void func_0220602C(Owner *o)
{
    if (o->f5c != 0)
        MCSS_Draw(o->sys);
    else
        func_02206664(o);
}







/*
 * Setter for the +0x1c flag word of the ov195 scene object driven by
 * func_022040E0.  Unlabelled in the listing (a leaf that saves no lr, so it
 * prints inside a .word run); region-qualified because ov094 overlaps.
 */
void func_02206044(int *p)
{
    p[7] = 1;
}







/*
 * Getter for the +0x20 word of the ov195 scene object (unlabelled leaf).
 */
int func_0220604C(int *p)
{
    return p[8];
}







/*
 * Setter for the +0x24 flag word of the ov195 scene object (unlabelled leaf).
 */
void func_02206050(int *p)
{
    p[9] = 1;
}







/*
 * Getter for the +0x28 word of the ov195 scene object (unlabelled leaf).
 */
int func_02206058(int *p)
{
    return p[10];
}







/*
 * Setter for the +0x2c flag word of the ov195 scene object (unlabelled leaf).
 */
void func_0220605C(int *p)
{
    p[11] = 1;
}







/*
 * Setter for the +0x30 flag word of the ov195 scene object (unlabelled leaf).
 */
void func_02206064(int *p)
{
    p[12] = 1;
}







/*
 * Getter for the +0x34 word of the ov195 scene object (unlabelled leaf).
 */
int func_0220606C(int *p)
{
    return p[13];
}







/*
 * Getter for the +0x38 word of the ov195 scene object (unlabelled leaf).
 */
int func_02206070(int *p)
{
    return p[14];
}







/*
 * Getter for the +0x3c word of the ov195 scene object (unlabelled leaf).
 */
int func_02206074(int *p)
{
    return p[15];
}







/*
 * Leaf of the func_022040E0 dependency tree: on a positive func_0220673C
 * probe it sets the +0x40 word and the +0x14 state word of the scene object
 * and notifies func_02206750; returns 1, else 0.
 */
int func_02206078(int *p)
{
    int func_0220673C(int *);
    void func_02206750(int *);

    if (func_0220673C(p) != 0) {
        p[0x10] = 1;
        p[5] = 0xc;
        func_02206750(p);
        return 1;
    }
    return 0;
}








/*
 * 0x02016020 (arm9 Thumb leaf `str r1,[r0,#0x30]; bx lr`) resolves as label
 * since its function_starts seed (2026-09-27). EXACT*: the listing extent
 * includes the 2 bytes of alignment padding at 0x022060BA.
 */
void func_0220609C(char *a)
{
    ((struct Obj08349 *)a)->f4C = (u32)MCSS_Init(2, (void *)(((struct Obj08349 *)a)->f0));
    MCSS_SetTextureTransAdrs((void *)(((struct Obj08349 *)a)->f4C), 0x30000);
    MCSS_SetOrthoMode((void *)(((struct Obj08349 *)a)->f4C));
}







void func_022060BC(char *p){MCSS_Exit(((struct Obj02911 *)p)->f4C);}








fx32_02205AC0 func_022060C8(void *p)
{
    int v = POKE_TOOL_GetPartyValue(p, 5, 0);
    fx32_02205AC0 r = -0x12000;

    switch (v) {
    case 0x260:
        r = -0x1b000;
        break;
    case 0x261:
        r = -0x27000;
        break;
    case 0x40:
        r = -0x11e66;
        break;
    }
    return r;
}







/*
 * mwccarm calls the add helper (0x0209C95C) _fadd and the subtract helper
 * (0x0209CB8C) _fsub, as layout/runtime_arm9.txt now does (swapped there
 * until 2026-09-28).
 */
void func_02206108(Owner *o)
{
    u8 i;
    VecFx32 scale;

    for (i = 0; i < 2; i++)
        o->obj[i] = 0;
    scale.x = FX_F32_TO_FX32(o->scale);
    scale.y = FX_F32_TO_FX32(o->scale);
    scale.z = 0x1000;
    if (o->f08 == 0) {
        for (i = 0; i < 2; i++) {
            if (i == 0)
                o->obj[i] = MCSS_TOOL_AddPokeMcss(o->sys, o->res0, 0, 0, func_022060C8(o->res0), 0);
            else
                o->obj[i] = MCSS_TOOL_AddPokeMcss(o->sys, o->res1, 0, 0, func_022060C8(o->res1), 0);
            MCSS_SetShadowVanishFlag(o->obj[i], 1);
            MCSS_TOOL_SetAnimeStopCallback((int)o->obj[i]);
            MCSS_SetScale(o->obj[i], (u32 *)(&scale));
            if (i != 0) {
                MCSS_SetVanishFlag(o->obj[i]);
                MCSS_SetAnmStopFlag(o->obj[i]);
            }
        }
    } else {
        o->obj[1] = MCSS_TOOL_AddPokeMcss(o->sys, o->res0, 0, 0, func_022060C8(o->res0), 0);
        MCSS_SetShadowVanishFlag(o->obj[1], 1);
        MCSS_TOOL_SetAnimeStopCallback((int)o->obj[1]);
        MCSS_SetScale(o->obj[1], (u32 *)(&scale));
    }
    func_02206274((Owner *)o);
}







void func_0220623C(Owner *o)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (o->obj[i] != 0) {
            MCSS_SetVanishFlag(o->obj[i]);
            MCSS_Del(o->sys, o->obj[i]);
        }
    }
}







/*
 * Unlabelled Thumb leaf (saves no lr), seeded by address: flips a 0/1
 * slot index.
 */
u8 func_02206264(u8 i)
{
    u8 r;

    if (i == 0)
        r = 1;
    else
        r = 0;
    return r;
}




#undef FX_F32_TO_FX32



#undef FX_F32_TO_FX32


#undef FX_F32_TO_FX32

#undef FX_F32_TO_FX32

#define FX_F32_TO_FX32(x) \
    ((fx32)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))






void func_02206274(Owner *o)
{
    u8 i;
    float w, h, d;
    float x, y;
    VecFx32 pos;

    for (i = 0; i < 2; i++) {
        if (o->obj[i] != 0) {
            w = MCSS_GetSizeY(o->obj[i]);
            h = MCSS_GetOfsY(o->obj[i]);
            d = MCSS_GetOfsX(o->obj[i]);
            w = w * (o->scale / 16.0f);
            if (w > 96.0f)
                w = 96.0f;
            h = h * (o->scale / 16.0f);
            d = d * (o->scale / 16.0f);
            x = ((96.0f - w) / 2.0f + h) * 0.33f;
            y = (0.0f - d) * 0.33f;
            pos.x = FX_F32_TO_FX32(y);
            pos.y = FX_F32_TO_FX32(x);
            pos.z = 0;
            MCSS_SetOfsPosition(o->obj[i], (u32 *)(&pos));
        }
    }
}






void func_022063AC(char *a, u32 v)
{
    u32 buf[3];
    u8 i;

    for (i = 0; i < 2; i++) {
        char *p = a + i * 4;
        if (((struct Obj10822 *)p)->f50 != 0) {
            MCSS_GetPosition((void *)(((struct Obj10822 *)p)->f50), buf);
            buf[0] = v;
            MCSS_SetPosition((void *)(((struct Obj10822 *)p)->f50), buf);
        }
    }
}






static inline fx32 FX_SinIdx(int idx)
{
    return FX_SinCosTable_[idx * 2];
}






static inline fx32 FX_CosIdx(int idx)
{
    return FX_SinCosTable_[idx * 2 + 1];
}






void func_022063E0(Owner *o)
{
    Work *w = func_02030734(o->heap, sizeof(Work), 1, d_02208F68, 0x54c);
    Grid *g;
    u32 a, b, c;
    u8 j, k;

    w->grid[0] = 0;
    w->grid[1] = 0;
    w->quad = 0;
    if (o->f08 == 0)
        w->f00 = 0;
    else
        w->f00 = 3;

    a = POKE_TOOL_GetPartyValue(o->res0, 5, 0);
    b = POKE_TOOL_GetPartyValue(o->res0, 0x6f, 0);
    c = POKE_TOOL_GetGender(o->res0);
    g = w->grid[0] = func_0220685C(a, b, c, func_02017EAC(o->res0), 0, 0, 0x26000, 0x960, o->heap);
    if (o->f08 == 0) {
        func_02206A5C(g, o->heap);
        g->state = 3;
        func_022081A4((Grid *)((struct Fade *)g), o->heap, 0x7fff, 31, 31, 0, 31);
    } else {
        func_02206E2C(g, o->heap);
    }

    if (o->f08 == 0) {
        a = POKE_TOOL_GetPartyValue(o->res1, 5, 0);
        b = POKE_TOOL_GetPartyValue(o->res1, 0x6f, 0);
        c = POKE_TOOL_GetGender(o->res1);
        g = w->grid[1] = func_0220685C(a, b, c, func_02017EAC(o->res1), 0, 0, 0x28000, 0x980, o->heap);
        func_02206A5C(g, o->heap);
        g->state = 3;
        func_022081A4((Grid *)((struct Fade *)g), o->heap, 0x7fff, 31, 31, 0, 31);
        for (j = 0; j < 0x12; j++) {
            for (k = 0; k < 0x12; k++)
                g->row[j].cell[k].visible = 0;
        }
    }

    if (o->f08 == 0)
        w->quad = (struct Quad *)func_02208478(0x26000, 0x960, o->heap);
    o->work = w;
    func_02206768((char *)o, 0x100000, -0x800, 0);
    {
        VecFx32 v1 = d_02208E74;
        VecFx32 v2 = d_02208E80;
        VecFx32 v3 = {0, 0, 0};

        w->camera = (void *)G3D_CAMERA_Create(0, FX_SinIdx(0xe3), FX_CosIdx(0xe3), 0x1555, 0, 0x1000, 0x400000, 0, &v1, &v2, &v3, (void *)o->heap);
    }
}


#undef FX_F32_TO_FX32

#undef FX_F32_TO_FX32
#define FX_F32_TO_FX32(x) \
    ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))






void func_022065C8(char *p){char *q;u8 i;q=*(char * *)&((struct Obj02911 *)p)->f58;G3D_CAMERA_Delete((void *)(((struct Obj10824 *)q)->f4));if(((struct Obj10824 *)q)->f10)func_02208514(((struct Obj10824 *)q)->f10,((struct Obj02911 *)p)->f0);for(i=0;i<2;i++){if(*(char **)(q+i*4+8))func_02206A3C(*(char **)(q+i*4+8),((struct Obj02911 *)p)->f0);}func_020307B0(q);}







void func_02206604(Owner *o)
{
    Work *w = o->work;
    u16 heap = o->heap;
    u8 i;
    Grid *g;

    switch (w->f00) {
    case 0:
        break;
    case 1:
        func_022076A0(o);
        break;
    case 2:
    case 3:
        break;
    }
    for (i = 0; i < 2; i++) {
        g = w->grid[i];
        if (g != 0) {
            if (o->f40 != 0 && func_02208410((char *)g, heap))
                g->state = 4;
            func_02208430((Grid *)((struct Fade *)g), heap);
        }
    }
}







void func_02206664(Owner *o)
{
    u8 save0[0x20];
    u8 save1[0x24];
    Work *w = o->work;
    u8 i;

    G3D_SYSTEM_GetProjection((int)save0);
    G3D_SYSTEM_GetLookAt(save1);
    {
        VecFx32 scale = d_02208E8C;
        MtxFx33 rot;
        VecFx32 trans = {0, 0, 0};

        func_0207ADC4(&rot);
        NNS_G3dGlbBaseTrans(&trans);
        func_02082B60(&rot, &d_02148BCC.baseRot);
        d_02148BCC.flag &= ~0xa4;
        NNS_G3dGlbBaseScale(&scale);
    }
    G3D_CAMERA_Reset((struct Light *)w->camera);
    G3D_SYSTEM_ApplyLookAt();
    func_0206DB80();
    REG_MTX_MODE = 3;
    REG_MTX_IDENTITY = 0;
    REG_MTX_MODE = 2;
    REG_DIF_AMB = 0x7fff7fff;
    REG_SPE_EMI = 0x7fff7fff;
    for (i = 0; i < 2; i++) {
        if (w->grid[i] != 0)
            func_02207510((Grid *)(w->grid[i]), o->heap);
    }
    if (w->quad != 0)
        func_02208570((Quad *)w->quad, o->heap);
    G3D_SYSTEM_SetProjection((const u32 *)save0);
    G3D_SYSTEM_SetLookAt(save1);
    G3D_SYSTEM_ApplyLookAt();
    func_0206DB80();
}







/*
 * Unlabelled Thumb leaf (saves no lr), seeded by address.
 */
void func_0220672C(Owner *o)
{
    Work *w = o->work;

    if (w->f00 == 0)
        w->f00 = 1;
}







int func_0220673C(int *p)
{
    int v = **(int * *)&((struct Obj08348 *)p)->f58;

    return v != 0 && v != 4;
}







void func_02206750(int *p)
{
    char *q = *(char * *)&((struct Obj08348 *)p)->f58;
    int *r = *(int * *)&((struct Obj24968 *)q)->f8;
    int v = r[0x28 / 4];

    if (v == 1) return;
    if (v == 2) return;
    if (v == 3) return;
    r[0x28 / 4] = 1;
}







void func_02206768(char *a, u32 x, u32 y, u32 z)
{
    char *t = *(char * *)&((struct Obj00300 *)a)->f58;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(void **)(t + i * 4 + 8) != 0)
            func_022067B0(*(void **)(t + i * 4 + 8), ((struct Obj00300 *)a)->f0, x, y, z);
    }
    if (((struct Obj14534 *)t)->f10 != 0)
        func_022086BC(((struct Obj14534 *)t)->f10, ((struct Obj00300 *)a)->f0, x, y, z);
}







void func_022067B0(char *a, int b, int c, int d, int e)
{
    ((struct Obj10826 *)a)->f1C = c;
    *(int *)(a + 0x1c + 4) = d;
    *(int *)(a + 0x1c + 8) = e;
}







void func_022067BC(Owner *o)
{
    int heap = o->heap;
    Work *w = o->work;
    u8 i;
    Grid *g;

    for (i = 0; i < 2; i++) {
        g = w->grid[i];
        if (g != 0) {
            g->state = 5;
            func_022081A4((Grid *)((struct Fade *)g), heap, 0x7fff, 31, 0, 0, -1);
        }
    }
}







int func_022067FC(char *a)
{
    u16 id = ((struct Obj00300 *)a)->f0;
    char *t = *(char * *)&((struct Obj00300 *)a)->f58;
    int r = 1;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(char **)(t + i * 4 + 8) != 0 && func_022083CC(*(char **)(t + i * 4 + 8), id) == 0)
            r = 0;
    }
    return r;
}







int func_0220682C(char *a)
{
    u16 id = ((struct Obj00300 *)a)->f0;
    char *t = *(char * *)&((struct Obj00300 *)a)->f58;
    int r = 1;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(char **)(t + i * 4 + 8) != 0 && func_02208420(*(char **)(t + i * 4 + 8), id) == 0)
            r = 0;
    }
    return r;
}







Grid *func_0220685C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 tex, u32 pltt, u16 heap)
{
    Grid *g = func_02030734(heap, sizeof(Grid), 1, d_02208F68, 0x720);
    u32 chrFile;
    u32 plttFile;
    u8 *src;
    u8 *buf;
    int i, j;
    int k;

    g->canvas = BMP_Create(16, 16, 32, heap);
    g->tex = tex;
    g->plttAddr = pltt;
    chrFile = POKEGRA_GetCgrArcIndex(POKEGRA_GetArcID(), a0, a1, a2, a3, a4, a5);
    plttFile = POKEGRA_GetPalArcIndex(POKEGRA_GetArcID(), a0, a1, a2, a3, a4, a5);
    g->chr = 0;
    g->pltt = 0;
    g->chrRes = ARC_UTIL_LoadScreenDataFromArchive(POKEGRA_GetArcID(), chrFile, 1, (u32)(&g->chr), heap);
    g->plttRes = ARC_UTIL_LoadPaletteBlockFromArchive(POKEGRA_GetArcID(), plttFile, (u32)(&g->pltt), heap);
    src = g->chr->raw;
    buf = BMP_GetPixels(g->canvas);
    func_02082A7C(0, buf, 0x2000);
    k = 0;
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 0; j < 8; j++) {
        for (i = 8; i < 12; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 0; i < 8; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 8; i < 12; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    BMP_ConvertToLinear(g->canvas, 0, heap);
    func_02061CA4(0, tex, (u32)BMP_GetPixels(g->canvas), 0x2000);
    func_02061CA4((void *)1, pltt, (u32)g->pltt->raw, 0x20);
    return g;
}







void func_02206A3C(char *p, int a1)
{
    BMP_Delete(((struct Obj10827 *)p)->f10);
    func_020307B0(((struct Obj10827 *)p)->f8);
    func_020307B0(((struct Obj10827 *)p)->fC);
    func_020307B0(p);
}





static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((long long)a * b + 0x800) >> 12);
}





/*
 * 2026-10-05 (wave P2 lane Q1b, pengy share): EXACT* (974 B compiled, the
 * listing extent is 976 B with the trailing pad). Written bottom-up from the
 * matched twin func_02206E2C (same Grid/Ent, 18 x 18 entries of 0x80 bytes).
 * What closed the dx/dy/dz block: fx64 (long long) locals lx, ly, lz assigned
 * in the loop body (lz, then lx, then ly) and multiplied directly; LICM hoists
 * their sign words above the first _ll_mul and spills them, which gives the
 * extra frame word and the r6/r7 colours. Declaration order l2, dx.., row sets
 * the slots ([sp,#0x10] row, [sp,#0x18] l2). The pool word 0.13580248f
 * (0x3E0B0FCE) replaces the earlier 0.13636364f guess. Tried before: static
 * inline FX_Mul with long long parameters (966 B, no change).
 */
void func_02206A5C(Grid *p, u16 heap)
{
    u8 i;
    u8 q;
    u8 j;
    u8 d;
    u8 v;
    int m;
    float s, t;
    int l2;
    Cell *e;
    int dx, dy, dz, l1;
    Cell *row;
    long long lx, ly, lz;

    func_02206E2C((Grid *)p, heap);
    p->state = 0;
    for (i = 0; i < 16; i++)
        p->pal[i] = 0x7FFF;
    p->color = 0x7FFF;
    q = 0;
    p->flevel = q;
    p->fwait = q;
    p->fstep = q;
    p->fcount = q;
    p->x0 = 0x11;
    p->y0 = 8;
    p->x1 = q;
    p->y1 = p->y0 + 1;
    p->f64 = q;
    p->f68 = q;
    p->f6c = q;
    p->f70 = q;
    p->rows = q;
    for (; q < 18; q++) {
        j = 0;
        d = q / 3;
        row = p->row[q].cell;
        m = q % 3;
        for (; j < 18; j++) {
            e = &row[j];
            e->f30 = 0;
            e->v34 = e->cur;
            if (m == 0) {
                if (j < 9)
                    v = 6 * j;
                else
                    v = 6 * (j - 9) + 1;
            } else if (m == 1) {
                if (j < 9)
                    v = 6 * j + 2;
                else
                    v = 6 * (j - 9) + 3;
            } else {
                if (j < 9)
                    v = 6 * j + 4;
                else
                    v = 6 * (j - 9) + 5;
            }
            e->f4c = ((int)v << 16) / 54;
            e->f54 = FX_F32_TO_FX32(22.0f - 7.3333335f * (float)d - 0.13580248f * (float)v);
            t = (float)e->f54 / 4096.0f;
            s = 10.0f + 2.0f * (2.0f * (t * (10.0f * t) / 44.0f / 44.0f));
            e->f50 = FX_F32_TO_FX32(s);
            e->f58 = FX_Mul(e->f50, FX_SinCosTable__Alt[e->f4c >> 4].c);
            e->f60 = FX_Mul(e->f50, FX_SinCosTable__Alt[e->f4c >> 4].s);
            e->f5c = e->f54;
            dx = e->f58 - e->cur.x;
            dy = e->f5c - e->cur.y;
            dz = e->f60 - e->cur.z;
            lz = dz;
            lx = dx;
            ly = dy;
            l1 = FX_Sqrt((fx32)((lx * lx + 0x800) >> 12) + (fx32)((lz * lz + 0x800) >> 12));
            l2 = FX_Sqrt((fx32)((ly * ly + 0x800) >> 12));
            if (l1 > 0x1000) {
                e->f40 = func_0207C768(dx, l1);
                e->f48 = func_0207C768(dz, l1);
            } else {
                e->f40 = dx;
                e->f48 = dz;
            }
            if (l2 > 0x1000)
                e->f44 = func_0207C768(dy, l2);
            else
                e->f44 = dy;
            e->f64 = 0;
        }
    }
}





/*
 * Builds a 18 x 18 grid of 0x80-byte entries: each gets two rounded fx32
 * corner sets, a position (cur) and its copy (org). The 0.0f offsets and the
 * 16/3 step are locals (z, k): the compiler propagates them only after folding,
 * so `z * (A / k)` stays a _fmul and `(float)r * k` keeps k as the second operand.
 */
void func_02206E2C(Grid *p, u16 heap)
{
    int i;
    float a0, b, c, d;
    int q, r;
    float A, z, k;
    Cell *e;

    p->v.x = 0;
    p->v.y = 0;
    p->v.z = 0;
    p->rows = 18;
    z = 0.0f;
    k = 5.3333335f;
    A = 2.0220568f;
    a0 = -18.198511f + A / 2.0f;
    b = 18.198511f - A / 2.0f;
    c = z * (A / k);
    d = z * (A / k);
    for (i = 0; i < 324; i++) {
        r = i % 18;
        q = i / 18;
        e = &p->row[q].cell[r];
        e->f00 = 60;
        e->visible = 31;
        e->v[0][0] = FX_F32_TO_FX32((0.0f - A) / 2.0f - c);
        e->v[0][1] = FX_F32_TO_FX32(A / 2.0f + d);
        e->v[0][2] = 0;
        e->v[1][0] = FX_F32_TO_FX32((0.0f - A) / 2.0f - c);
        e->v[1][1] = FX_F32_TO_FX32((0.0f - A) / 2.0f - d);
        e->v[1][2] = 0;
        e->v[2][0] = FX_F32_TO_FX32(A / 2.0f + c);
        e->v[2][1] = FX_F32_TO_FX32((0.0f - A) / 2.0f - d);
        e->v[2][2] = 0;
        e->v[3][0] = FX_F32_TO_FX32(A / 2.0f + c);
        e->v[3][1] = FX_F32_TO_FX32(A / 2.0f + d);
        e->v[3][2] = 0;
        e->cur = p->v;
        e->cur.x += FX_F32_TO_FX32(a0 + A * (float)r);
        e->cur.y += FX_F32_TO_FX32(b - A * (float)q);
        e->s0 = FX_F32_TO_FX32(16.0f + (float)r * k - z);
        e->t0 = FX_F32_TO_FX32(16.0f + (float)q * k - z);
        e->s1 = e->s0 + FX_F32_TO_FX32(k + 2.0f * z);
        e->t1 = e->t0 + FX_F32_TO_FX32(k + 2.0f * z);
        e->org = e->cur;
    }
}





static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_TRANS = (u32)x;
    REG_MTX_TRANS = (u32)y;
    REG_MTX_TRANS = (u32)z;
}





static inline void G3_TexCoord(fx32 s, fx32 t)
{
    REG_TEXCOORD = (u32)(u16)(s16)(s >> 8) | ((u32)(u16)(s16)(t >> 8) << 16);
}





static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}





/*
 * Grid of textured quads, rows of 0x12 cells of 0x80 bytes, one push /
 * translate / quad / pop per visible cell.
 */
void func_02207510(Grid *w, u16 heap)
{
    int j;
    int i;
    Cell *c;

    REG_TEXIMAGE_PARAM = (w->tex >> 3) | 0x6E430000;
    REG_TEXPLTT_BASE = w->plttAddr >> 4;
    j = 0;
    REG_MTX_PUSH = j;
    G3_Translate(w->v.x, w->v.y, w->v.z);
    REG_POLYGON_ATTR = 0x001F0080;
    for (; j < w->rows; j++) {
        for (i = 0; i < 0x12; i++) {
            c = &w->row[j].cell[i];
            if (c->visible != 0) {
                REG_MTX_PUSH = 0;
                G3_Translate(c->cur.x, c->cur.y, c->cur.z);
                REG_BEGIN_VTXS = 1;
                REG_NORMAL = 0x20000000;
                G3_TexCoord(c->s0, c->t0);
                G3_Vtx(c->v[0][0], c->v[0][1], c->v[0][2]);
                G3_TexCoord(c->s0, c->t1);
                G3_Vtx(c->v[1][0], c->v[1][1], c->v[1][2]);
                G3_TexCoord(c->s1, c->t1);
                G3_Vtx(c->v[2][0], c->v[2][1], c->v[2][2]);
                G3_TexCoord(c->s1, c->t0);
                G3_Vtx(c->v[3][0], c->v[3][1], c->v[3][2]);
                REG_END_VTXS = 0;
                REG_MTX_POP = 1;
            }
        }
    }
    REG_MTX_POP = 1;
}

#undef FX_F32_TO_FX32
#define FX_F32_TO_FX32(x)     ((fx32)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))





void func_022076A0(Owner *o)
{
    Work *w = o->work;
    u16 heap = o->heap;
    Grid *s;
    Grid *d;
    u8 j;
    u8 i;
    s16_022076A0 x;
    s16_022076A0 y;
    int flag;

    if (w->f00 != 1)
        return;

    func_02207868((char *)w->grid[0], heap);
    s = w->grid[0];
    d = w->grid[1];
    d->f68 = s->f68;
    for (j = 0; j < 0x12; j++) {
        for (i = 0; i < 0x12; i++)
            d->row[j].cell[i].cur = s->row[j].cell[i].cur;
    }

    for (y = d->y0; y >= s->y0; y--) {
        if (y == d->y0)
            x = d->x0;
        else
            x = 17;
        for (; x >= 0; x--) {
            if (y == s->y0) {
                if (x <= s->x0)
                    break;
                flag = 1;
            } else {
                flag = 1;
            }
            if (flag)
                d->row[y].cell[x].visible = 31;
        }
    }
    d->x0 = s->x0;
    d->y0 = s->y0;

    for (y = d->y1; y <= s->y1; y++) {
        if (y == d->y1)
            x = d->x1;
        else
            x = 0;
        for (; x < 0x12; x++) {
            if (y == s->y1) {
                if (x >= s->x1)
                    break;
                flag = 1;
            } else {
                flag = 1;
            }
            if (flag)
                d->row[y].cell[x].visible = 31;
        }
    }
    d->x1 = s->x1;
    d->y1 = s->y1;
    d->rows = s->rows;

    s = w->grid[0];
    d = w->grid[1];
    d->state = s->state;
    if (func_022083DC((char *)s, heap)) {
        func_022083EC(s, heap);
        func_022083EC(d, heap);
    }
    func_02208420((char *)s, heap);
    if (w->quad != 0) {
        w->quad->f4e = w->grid[0]->rows;
        func_0220851C((Quad *)w->quad, heap);
    }
}




static inline int mul(int a,int b){return (int)(((long long)a*b+2048)>>12);}




static inline int sub(int a,int b){return (int)((u32)a-(u32)b);}




static inline int add(int a,int b){return (int)((u32)a+(u32)b);}




/*
 * checks: 1 own matrix/vec/invsqrt bodies and matched callers confirm signatures; original explicitly forwards heap in r1 to 08410; 2 06274/063E0/06604/0685C no complete motion twin; 3 Boolean first/second, Boolean done and _Bool smallH/smallV each DIFF597; after stop s16 first/second DIFF599; writable p retained; 4 case2 cursor cache DIFF600 and case3 shared done-zero DIFF597, scheduling cap used, branch/stack idioms read; 5 refreshed unfiltered idioms and matched neighbours, declared-stack-struct idiom read.
 * recoup 2026-10-05 (P17L3): extent is 2340 B (not 114 B); compiled 2364 (24 B over). First divergence at +0x94 in case 1: original stores one movs r1 to the flag slots [sp+0x84],[sp+0x80] with done in r5 and loop counters i,j in the LOWEST slots [sp+0x20],[sp+0x18] (q at 0x58); ours puts i,j just under the flags (0x78,0x74) and done in r4. Tried (4 compiles): flags declared before the s16 counters (597->596), counters declared last (594), counters as case-block locals (594, same), first=second=1 chain (597, worse). Slot order does not follow declaration order here; not closed. Best form kept (594 differ).
 * recoup 2026-10-05 P30R8 (18 compiles, best 562 differ, was 594): instruction-aligned diff shows the code shape is the original's except 4 things. (1) Spill slots: original keeps the s16 counters in the LOWEST slots (j 0x18, j 0x1c, i 0x20, i 0x24, i 0x28, below all compiler temps); ours puts named locals above temps, so ~540 of the differing bytes are slot numbers. Declaring `s16 i,i,i,j,j,j` reproduces the original relative order of the counters (not their absolute position). Block-local `char *q` per loop (594->567) and separate `first3,second3,done3` for case 3 (567->562; flags3 now at 0x78/0x74 like the original) are kept. (2) Original shares one `movs r,#1` for the two flag stores (str [0x84]; str [0x80]); ours emits two movs. Tried first=second=1, second=first=1, first=1;second=first, `int first=1,second=1`, u8 flags: all keep two movs. (3) smallV=0 in the original is `movs r2,#0; str r2,[sp,#0x7c]` before the pool load, a zero separate from smallH; ours shares r0. Tried smallH=smallV=0 and u8 smallV: no change. (4) add order at +04F8 (adds r4,r3,r4 / lsls r3,r2,#7 swapped). Per-function pragmas on the final form (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments off: 1451 to 2225 differ; scheduling, peephole off: no change). Counters first-declared put them at the top (570); counters and flags as case-block locals 571.
 * final push 2026-10-05 G10L2 (30 compiles, 562 -> 23 bytes off): (1) ONE shared s16 i,j for all four loops (drops the counters to the original low slots, clears the case 2 q/j register swap); (2) case 3 locals (vx..inv, dx..inv) declared in their branch blocks; (3) `done=1;first=1;second=1;` with done FIRST makes first/second share one movs (literal CSE), also for case 3; (4) `smallH=0;smallV=0;` order gives the separate smallV zero; (5) case 2 first clear as `c=p+i*0x900;c+=j*0x80;c[0x88]=0` matches the original schedule. Remaining 23 B: case 3 second clear (j shift scheduled before the add; original sequential), dy1 spill slot 0x68 vs 0x60 with the case 3 vert slots shifted by one, and the five hoisted 2048 constants of case 3 branch 1 stored in order m4,m5,m1,m2,m3 (original m1..m5; slots equal). Tried without effect: plain/pointer/struct-view/(j<<7)/inline cell forms for the clear, dy declared last/block-local/as vy/unsigned, case 1 locals block-scoped, q at function scope (worse), split horiz sum (worse).
 * pass 2 2026-10-06 P2L35 (29 compiles, 23 -> EXACT in --lang c99 and --lang c): (1) both case 2 grid clears as
 *   `*(u8 *)(p+i*0x900+0x88+j*0x80)=0;` (constant before the j term: the deeper left sum is built first, so the j shift
 *   is born after the base add; replaces the c-pointer form); (2) the case 3 vertical squares written out as
 *   `(int)(((long long)vy*vy+2048)>>12)` like the sibling ov195 02206A5C (FX_Mul inline temps took the low slots; case 1
 *   vert must stay FX_Mul); (3) all case 3 locals at function scope, with four distinct `horiz1,horiz2,vert1,vert2`
 *   declared after first3,second3,done3 (slot order horiz1,horiz2,vert1,vert2); (4) branch 1 writes the step into new
 *   locals nx,ny,nz with an else arm for each clamp (`else{nx=vx;nz=vz;}`, `else ny=vy;`): the else blocks change the
 *   loop block list, so LICM hoists the 2048 constants in text order (K1..K5).
 * extent: handed2340 ends at 0220818C before pop02208190; pools through022081A0; next genuine022081A4. Full extent2364 proved by explicit show.
 */
void func_02207868(char *p,u16 heap)
{
    int first,second,done;
    int angle,dx,dy,dz,horiz,vert,inv,vx,vy,vz,smallH,smallV;
    Vec goal;
    Matrix m1;
    Vec source1;
    Matrix m2;
    Vec source2;
    Matrix m3;
    Vec source3;
    Matrix m4;
    Vec source4;
    int first3,second3,done3;
    int horiz1,horiz2,vert1,vert2;
    int nx,ny,nz;
    s16_02207868 i,j;
    G(0x68)+=G(0x6c);
    if((int)G(0x68)>=65536)G(0x68)-=65536;
    for(i=0;i<18;i++)for(j=0;j<18;j++){
        char *q=p+0x74+i*0x900+j*0x80;
        V(0x74)=V(0x68);
    }
    switch(G(0x64)){
    case 0:
        G(0x64)=1;G(0x70)=0;G(0x6c)=0x600;return;
    case 1:
        done=1;first=1;second=1;
        for(i=0;i<18;i++)for(j=0;j<18;j++){
            char *q=p+0x74+i*0x900+j*0x80;
            angle=add(Q(0x4c),G(0x68));if(angle>=65536)angle-=65536;
            func_0207B640(&m1,FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
            source1.x=Q(0x50);source1.y=0;source1.z=0;
            MTX_MultVec43(&source1,&m1,&goal);goal.y=Q(0x54);
            if(Q(0x64)==0){
                if(first||second){Q(0x30)=0;Q(0x64)=1;if(first)first=0;else second=0;}
                done=0;
            }else if(Q(0x64)==1){
                if(Q(0x30)==0){
                    Q(0x68)=add(Q(0x68),Q(0x40));Q(0x6c)=add(Q(0x6c),Q(0x44));Q(0x70)=add(Q(0x70),Q(0x48));
                    Q(0x30)++;*(u8 *)(p+0xa274)=(u8)(i+1);
                }else{
                    dy=sub(Q(0x5c),Q(0x6c));dz=sub(Q(0x60),Q(0x70));dx=sub(Q(0x58),Q(0x68));
                    horiz=mul(dx,dx)+mul(dz,dz);vert=mul(dy,dy);
                    if(horiz<0x11ac&&vert<0x11ac){
                        Q(0x68)=Q(0x58);Q(0x70)=Q(0x60);Q(0x6c)=Q(0x5c);
                        Q(0x68)=goal.x;Q(0x70)=goal.z;Q(0x6c)=goal.y;Q(0x30)=0;Q(0x64)=2;
                    }else{
                        smallH=0;smallV=0;if(horiz<0x11ac)smallH=1;else if(vert<0x11ac)smallV=1;
                        if(smallH){Q(0x68)=Q(0x58);Q(0x70)=Q(0x60);}
                        else{
                            inv=func_0207C7E8(horiz);
                            Q(0x68)=add(add(Q(0x68),mul(sub(Q(0x68),Q(0x74)),409)),mul(mul(dx,inv),3584));
                            Q(0x70)=add(add(Q(0x70),mul(sub(Q(0x70),Q(0x7c)),409)),mul(mul(dz,inv),3584));
                        }
                        if(smallV)Q(0x6c)=Q(0x5c);
                        else{vy=dy>=0?4096:-4096;Q(0x6c)=add(add(Q(0x6c),mul(sub(Q(0x6c),Q(0x78)),409)),mul(vy,3584));}
                        Q(0x30)++;
                    }
                }
                done=0;
            }else if(Q(0x64)==2){Q(0x68)=goal.x;Q(0x70)=goal.z;Q(0x6c)=goal.y;}
        }
        if(done){G(0x64)=2;if(G(0x28)!=1&&G(0x28)!=2)G(0x28)=1;}return;
    case 2:
        if(G(0x70)<100)G(0x6c)+=32;
        if(G(0x70)>=200&&G(0x70)<240)G(0x6c)-=32;
        for(i=0;i<18;i++)for(j=0;j<18;j++){
            char *q=p+0x74+i*0x900+j*0x80;
            angle=add(Q(0x4c),G(0x68));if(angle>=65536)angle-=65536;
            func_0207B640(&m2,FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
            source2.x=Q(0x50);source2.y=0;source2.z=0;
            MTX_MultVec43(&source2,&m2,&V(0x68));Q(0x6c)=Q(0x54);
        }
        if(func_02208410(p,heap)&&G(0x70)>=30){
            j=H(0x5a);i=H(0x5c);
            if(i>=0&&j>=0){
                *(u8 *)(p+i*0x900+0x88+j*0x80)=0;
                if(j-1<0){H(0x5a)=18;H(0x5c)--;}else H(0x5a)--;
            }
            j=H(0x5e);i=H(0x60);
            if(i<18&&j<18){
                *(u8 *)(p+i*0x900+0x88+j*0x80)=0;
                if(j+1>=18){H(0x5e)=0;H(0x60)++;}else H(0x5e)++;
            }
        }
        if(H(0x5c)<0&&H(0x60)>=18&&G(0x70)>=240){G(0x64)=3;G(0x70)=0;return;}
        G(0x70)++;return;
    case 3:
        done3=1;first3=1;second3=1;
        for(i=17;i>=0;i--)for(j=17;j>=0;j--){
            char *q=p+0x74+i*0x900+j*0x80;
            angle=add(Q(0x4c),G(0x68));if(angle>=65536)angle-=65536;
            if(Q(0x64)==2){
                if(first3||second3){Q(0x30)=0;Q(0x64)=3;if(first3)first3=0;else second3=0;}
                else{
                    func_0207B640(&m3,FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
                    source3.x=Q(0x50);source3.y=0;source3.z=0;
                    MTX_MultVec43(&source3,&m3,&V(0x68));Q(0x6c)=Q(0x54);
                }
                done3=0;
            }else if(Q(0x64)==3){
                if(Q(0x30)==0){
                    func_0207B640(&m4,FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
                    source4.x=Q(0x50);source4.y=0;source4.z=0;
                    MTX_MultVec43(&source4,&m4,&V(0x68));Q(0x6c)=Q(0x54);
                    vx=sub(Q(0x68),Q(0x74));vy=sub(Q(0x6c),Q(0x78));vz=sub(Q(0x70),Q(0x7c));
                    horiz1=mul(vx,vx)+mul(vz,vz);vert1=(int)(((long long)vy*vy+2048)>>12);
                    if(horiz1>4096){inv=func_0207C7E8(horiz1);nx=mul(vx,inv);nz=mul(vz,inv);}
                    else{nx=vx;nz=vz;}
                    if(vert1>4096)ny=vy>=0?4096:-4096;
                    else ny=vy;
                    Q(0x68)=add(Q(0x68),nx);Q(0x6c)=add(Q(0x6c),ny);Q(0x70)=add(Q(0x70),nz);Q(0x30)++;
                }else{
                    dx=sub(Q(0x34),Q(0x68));dy=sub(Q(0x38),Q(0x6c));dz=sub(Q(0x3c),Q(0x70));
                    horiz2=mul(dx,dx)+mul(dz,dz);vert2=(int)(((long long)dy*dy+2048)>>12);
                    if(horiz2<0x11ac&&vert2<0x11ac){Q(0x68)=Q(0x34);Q(0x70)=Q(0x3c);Q(0x6c)=Q(0x38);Q(0x30)=0;Q(0x64)=4;}
                    else{
                        if(horiz2>4096){inv=func_0207C7E8(horiz2);dx=mul(dx,inv);dz=mul(dz,inv);}
                        if(vert2>4096)dy=dy>=0?4096:-4096;
                        Q(0x68)=add(Q(0x68),dx);Q(0x6c)=add(Q(0x6c),dy);Q(0x70)=add(Q(0x70),dz);
                    }
                }
                done3=0;
            }
        }
        if(done3){G(0x64)=4;G(0x28)=4;}return;
    case 4: return;
    }
}





void func_022081A4(Grid *p, int unused, u16 color, s16_022081A4 cur, s16_022081A4 end, s16_022081A4 wait, s16_022081A4 step)
{
    s16_022081A4 v;

    p->color = color;
    p->fcur = cur;
    p->fend = end;
    p->fwait = wait;
    p->fstep = step;

    v = p->fcur;
    if (v > 31)
        v = 31;
    else if (v < 0)
        v = 0;
    p->fcur = v;

    v = p->fend;
    if (v > 31)
        v = 31;
    else if (v < 0)
        v = 0;
    p->fend = v;

    v = p->fstep;
    if (v > 31)
        v = 31;
    else if (v < -31)
        v = -31;
    p->fstep = v;

    if (p->fcur < p->fend) {
        if (p->fstep < 0)
            p->fstep = p->fstep * 0xFFFFFFFF;
    } else if (p->fcur > p->fend) {
        if (p->fstep > 0)
            p->fstep = p->fstep * 0xFFFFFFFF;
    } else {
        p->fstep = 0;
    }

    p->flevel = p->fcur;
    p->fcount = p->fwait;
    func_022082DC(p, unused);
}





int func_0220826C(Grid *p, int x)
{
    if (p->fstep == 0)
        return 1;
    return 0;
}




void func_0220827C(Grid *p, int x)
{
    s16 step = p->fstep;
    s16 v;

    if (step == 0)
        return;
    if (p->fcount > 0) {
        p->fcount = p->fcount - 1;
        return;
    }
    p->flevel = p->flevel + step;
    v = p->flevel;
    if (v > 31)
        v = 31;
    else if (v < 0)
        v = 0;
    p->flevel = v;
    if (p->flevel == p->fend)
        p->fstep = 0;
    else
        p->fcount = p->fwait;
    func_022082DC(p, x);
}








void func_022082DC(Grid *p, int x)
{
    u16 *src = *(u16 * *)&((struct Obj24975 *)(p->pltt))->fC;
    u8 i;
    s16 tr, tg, tb;
    s16 r, g, b;
    s16 level;

    tr = (s16)(p->color & 0x1f);
    tg = (s16)((p->color & 0x3e0) >> 5);
    tb = (s16)((p->color & 0x7c00) >> 10);

    for (i = 1; i < 16; i++) {
        r = (s16)(src[i] & 0x1f);
        g = (s16)((src[i] & 0x3e0) >> 5);
        b = (s16)((src[i] & 0x7c00) >> 10);
        level = p->flevel;
        if (level == 31) {
            r = tr;
            g = tg;
            b = tb;
        } else {
            r = (s16)(r + ((tr - r) * level >> 5));
            g = (s16)(g + ((tg - g) * level >> 5));
            b = (s16)(b + ((tb - b) * level >> 5));
            r = r > 31 ? 31 : (r < 0 ? 0 : r);
            g = g > 31 ? 31 : (g < 0 ? 0 : g);
            b = b > 31 ? 31 : (b < 0 ? 0 : b);
        }
        p->pal[i] = r | (g << 5) | (b << 10);
    }
    func_02061CA4((void *)1, p->plttAddr, (u32)p->pal, 0x20);
}








int func_022083CC(char *p, u16 a1)
{
    return ((struct Obj24976 *)p)->f28 == 0;
}








int func_022083DC(char *p, u16 heap)
{
    return ((struct Obj24977 *)p)->f28 == 1;
}








void func_022083EC(Grid *p, int x)
{
    p->state = 2;
    func_022081A4(p, x, 0x7fff, 0, 31, 0, 1);
}








int func_02208410(char *p, u16 heap)
{
    return ((struct Obj24978 *)p)->f28 == 3;
}







int func_02208420(char *p, u16 heap)
{
    return ((struct Obj24979 *)p)->f28 == 4;
}







void func_02208430(Grid *p, int x)
{
    switch (p->state) {
    case 0:
    case 1:
        break;
    case 2:
        if (func_0220826C((Grid *)p, x))
            p->state = 3;
        break;
    case 3:
    case 4:
        break;
    case 5:
        if (func_0220826C((Grid *)p, x))
            p->state = 0;
        break;
    }
    func_0220827C((Grid *)p, x);
}







Quad *func_02208478(u32 tex, u32 pltt, u16 heap)
{
    Quad *p = func_02030734(heap, sizeof(Quad), 1, d_02208F68, 0xd31);

    p->tex = tex;
    p->pltt = pltt;
    p->tz = 0;
    p->ty = 0;
    p->tx = 0;
    p->sx = 0x2465a;
    p->sy = 0x2465a;
    p->sz = 0x1000;
    p->polyId = 0x3b;
    p->s0 = 0x10000;
    p->t0 = 0x10000;
    p->s1 = 0x70000;
    p->t1 = 0x70000;
    p->alpha = 0x1f;
    p->v[0][0] = -0x800;
    p->v[0][1] = 0x800;
    p->v[0][2] = 0;
    p->v[1][0] = -0x800;
    p->v[1][1] = -0x800;
    p->v[1][2] = 0;
    p->v[2][0] = 0x800;
    p->v[2][1] = -0x800;
    p->v[2][2] = 0;
    p->v[3][0] = 0x800;
    p->v[3][1] = 0x800;
    p->v[3][2] = 0;
    p->f4e = 0;
    return p;
}






void func_02208514(void *p,int n){func_020307B0(p);}







/*
 * The rounding is the SDK FX_F32_TO_FX32 shape applied to an integer
 * (x * 4096 is an int multiply, converted for the +-0.5f). mwccarm calls
 * the add helper (0x0209C95C) as _fadd and the subtract helper
 * (0x0209CB8C) as _fsub, as layout/runtime_arm9.txt now does (swapped
 * there until 2026-09-28).
 */
void func_0220851C(Quad *p, u16 heap)
{
    u8 i = p->f4e;
    u8 b;

    p->v[3][1] = d_02208E4C[i];
    p->v[0][1] = p->v[3][1];
    b = d_02208E38[i];
    p->t0 = FX_F32_TO_FX32(b);
}







static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_SCALE = (u32)x;
    REG_MTX_SCALE = (u32)y;
    REG_MTX_SCALE = (u32)z;
}







/*
 * One textured quad in immediate geometry: texture image and palette base,
 * push, polygon attributes, translate, scale, four vertices, pop.
 *
 * 2026-10-05 (D8): residue is only the z of the last vertex (v[3][2], offset
 * 0x46, beyond the ldrh immediate range). Original: movs r5,#0x46; ldrsh r6,[r4,r5]
 * then lsls/lsrs #16 before the store (sign load, explicit u16 truncation, not
 * folded). Ours folds to adds/adds/ldrh and stores r6 directly (6 bytes
 * shorter in that block, so the early skip branch differs only by length).
 * Everything before it is byte-identical. Tried: fx16 local, s32 local for z,
 * raw *(s16 *)((u8 *)p + 0x46). None changes the load form. The first three
 * z values (offsets 0x3a, 0x40) fold to ldrh in the original, so the last one
 * likely has a second signed use or a different source type; not found.
 *
 * 2026-10-05 (D9-14): closed, EXACT. The z of the third vertex (offset 0x46; the
 * D8 note said v[3][2], it is v[2][2]) is read into an int local after the third
 * texcoord and passed to G3_Vtx. The int local keeps the sign-extending load
 * (ldrsh) and the explicit u16 truncation after the x/y store. An fx16 local in the
 * same place folds to ldrh (81 bytes); the local read before G3_TexCoord gives the
 * ldrsh but schedules it into the texcoord block (29 bytes).
 */
void func_02208570(Quad *p, u16 heap)
{
    int z;

    if (p->f4e < 0x12) {
        REG_TEXIMAGE_PARAM = (p->tex >> 3) | 0x6E430000;
        REG_TEXPLTT_BASE = p->pltt >> 4;
        REG_MTX_PUSH = 0;
        REG_POLYGON_ATTR = ((p->alpha != 0 ? 2 : 0) << 6) | (p->polyId << 24) | (p->alpha << 16);
        G3_Translate(p->tx, p->ty, p->tz);
        G3_Scale(p->sx, p->sy, p->sz);
        REG_BEGIN_VTXS = 1;
        REG_NORMAL = 0x20000000;
        G3_TexCoord(p->s0, p->t0);
        G3_Vtx(p->v[0][0], p->v[0][1], p->v[0][2]);
        G3_TexCoord(p->s0, p->t1);
        G3_Vtx(p->v[1][0], p->v[1][1], p->v[1][2]);
        G3_TexCoord(p->s1, p->t1);
        z = p->v[2][2];
        G3_Vtx(p->v[2][0], p->v[2][1], z);
        G3_TexCoord(p->s1, p->t0);
        G3_Vtx(p->v[3][0], p->v[3][1], p->v[3][2]);
        REG_END_VTXS = 0;
        REG_MTX_POP = 1;
    }
}







void func_022086BC(char *a, int b, int c, int d, int e)
{
    ((struct Obj10829 *)a)->f8 = c;
    *(int *)(a + 8 + 4) = d;
    *(int *)(a + 8 + 8) = e;
}






Node *func_022086C8(u16 heap, u16 n)
{
    Node *p = func_02030734(heap, n * sizeof(Node), 1, d_02208F7C, 0xe8);
    u16 i;

    for (i = 0; i < n; i++) {
        p[i].tx = 0;
        p[i].ty = 0;
        p[i].tz = 0;
        p[i].sx = 0x1000;
        p[i].sy = 0x1000;
        p[i].sz = 0x1000;
        func_0207ADC4((MtxFx33 *)p[i].mtx);
    }
    return p;
}





void func_02208714(void *p){func_020307B0(p);}






Anim_0220871C *func_0220871C(u16 heap, u32 x)
{
    Anim_0220871C *p = func_02030734(heap, sizeof(Anim_0220871C), 1, d_02208F7C, 0x150);

    p->heap = heap;
    p->f04 = x;
    if (x == 0)
        p->f08 = 0;
    else
        p->f08 = 7;
    p->f0c = 0;
    p->ptc = func_0220887C(p->heap, 9, d_02208ED0);
    func_02208A54((char *)p);
    func_02208AB0((Anim_02208AB0 *)p);
    return p;
}






void func_02208770(char *a)
{
    func_02208B54(a);
    func_02208A6C(a);
    func_02208994((char *)(((struct Obj05518 *)a)->f10));
    func_020307B0(a);
}






void func_0220878C(Anim_0220878C *p)
{
    switch (p->state) {
    case 0:
    case 1:
        break;
    case 2:
        func_02208C10((Anim_02208C10 *)p);
        p->state = 3;
        break;
    case 3:
        if (func_02208C18((Anim_02208C18 *)p)) {
            p->state = 4;
            p->wait = 3;
            func_02208A48((Ptc_02208A48 *)p->ptc, 0);
        }
        break;
    case 4:
        if (p->wait == 0) {
            func_02208C28((Anim_02208C28 *)p);
            p->state = 5;
        } else {
            p->wait = p->wait - 1;
        }
        break;
    case 5:
        if (func_02208C30((Anim_02208C28 *)p))
            p->state = 6;
        break;
    case 6:
    case 7:
        break;
    }
    func_02208B6C((char *)p);
    func_022089A4((Ptc_022089A4 *)p->ptc);
}






void func_02208804(char *a)
{
    func_02208A78((Anim_02208A78 *)((struct Anim *)a));
    func_02208A24(((struct Obj08350 *)a)->f10);
}






void func_02208814(char *a)
{
    func_02208A38((char *)(((struct Obj10830 *)a)->f10), 0x1e);
    if (((struct Obj10830 *)a)->f8 == 1)
        ((struct Obj10830 *)a)->f8 = 2;
}





/*
 * Move the ov195 scene object to state 1 with a 0x26c timer.  Labelled leaf.
 */
void func_0220882C(int *p)
{
    void func_02208A2C(char *p);

    func_02208A2C((char *)p[4]);
    p[2] = 1;
    p[3] = 0x26c;
}





/*
 * Flag bump on the ov195 scene object (+8 == 1 -> 2); unlabelled leaf.
 */
void func_02208844(int *p)
{
    if (p[2] == 1)
        p[2] = 2;
}





/*
 * True when the ov195 scene object's +8 state is 4; unlabelled leaf.
 */
int func_02208850(int *p)
{
    if (p[2] == 4)
        return 1;
    return 0;
}





/*
 * Camera-state predicate on the ov195 scene object's +8/+0xc words:
 * state 4 with +0xc <= 1, or state 5.  Unlabelled leaf.
 */
int func_02208860(int *p)
{
    if (p[2] == 4 && (unsigned)p[3] <= 1)
        return 1;
    if (p[2] == 5)
        return 1;
    return 0;
}






/*
 * promoted: from src/pending on 2026-09-27, no C change. Its blocker, the
 *   call at +0xD8 to the unlabelled ARM leaf 0x02051B04, closed when that
 *   leaf was seeded in layout/function_starts.txt and matched
 *   (src/matched/BUTTON_MAN_GetResourceType.c); all 13 relocations resolve.
 */
Ptc *func_0220887C(u16 heap, u16 a, void *b)
{
    VecFx32 v1 = d_02208F24;
    VecFx32 v2 = d_02208F30;
    VecFx32 v3 = {0, 0, 0};
    EmitParam prm;
    Ptc *p;
    u32 res;

    prm.f00 = 0;
    prm.f04 = FX_SinCosTable_[0xe3 * 2];
    prm.f08 = FX_SinCosTable_[0xe3 * 2 + 1];
    prm.f0c = 0x1555;
    prm.f10 = 0;
    prm.f14 = 0x1000;
    prm.f18 = 0x400000;
    prm.f1c = 0;

    p = func_02030734(heap, sizeof(Ptc), 1, d_02208F7C, 0x2e5);
    p->f00 = 0;
    p->f02 = 0;
    p->f04 = a;
    p->f08 = b;
    p->f4814 = 0;
    p->f4818 = -1;
    PARTICLE_InitManager(heap);
    p->spl = PARTICLE_CreateSystem((u32)p->work, sizeof(p->work), 1, 5, 6, 0x3b, heap);
    PARTICLE_ReleaseCamera((int)p->spl);
    PARTICLE_InitCamera(p->spl, (struct Src648 *)(&prm), 0x2000, (int *)(&v1), (int *)(&v2), (int *)(&v3), heap);
    res = PARTICLE_LoadArchiveMember(d_02208E9C[0], d_02208E9C[1], heap);
    p->f4810 = BUTTON_MAN_GetResourceType((void *)res);
    PARTICLE_SetupSystem(p->spl, res, 1, 0);
    return p;
}






void func_02208994(char *a)
{
    PARTICLE_ExitManager();
    func_020307B0(a);
}





void func_022089A4(Ptc_022089A4 *p)
{
    if (p->active != 0) {
        VecFx32 v = {0, 0, 0};
        Cue *c;

        for (; p->cue < p->ncue; p->cue++) {
            if (p->frame != p->cues[(int)p->cue].frame)
                break;
            c = &p->cues[p->cue];
            PARTICLE_StartEffect(p->emit[c->emit].spl, c->id, (int)(&v));
        }
        p->frame++;
    }
    if (p->timer >= 0) {
        if (p->timer == 0)
            PARTICLE_KillAllEffects(p->emit[0].spl);
        p->timer--;
    }
}




void func_02208A24(int a0){PARTICLE_Main();}





void func_02208A2C(char *p){((struct Obj24981 *)p)->f4814=1;}




void func_02208A38(char *p,u32 v) { ((struct Obj14537 *)p)->f4814=0; ((struct Obj14537 *)p)->f4818=v; }





void func_02208A48(Ptc_02208A48 *p, s32 timer)
{
    p->timer = timer;
}





void func_02208A54(char *a)
{
    *(int *)&((struct Obj00687 *)a)->f14 = G3D_UTIL_Create(4, 1, ((struct Obj00687 *)a)->f0);
    ((struct Obj00687 *)a)->f1C = 0;
}




void func_02208A6C(char *p) { G3D_UTIL_Delete(*(struct Rec * *)&((struct Obj05518 *)p)->f14); }




void func_02208A78(Anim_02208A78 *p) { u16 i; Node_02208A78 *n; for(i=0;i<p->count;i++) { n=p->nodes+i; if(n->f40) G3D_SYSTEM_DrawObject((void *)func_02048A18(p->res,n->id),(struct Arg *)((struct Transform *)&n->tx)); } }





/*
 * promoted: from src/pending on 2026-09-27, no C change. Its blocker, the
 *   two calls to the unlabelled ARM leaf 0x0204784C (sites +0x8E, +0x98),
 *   closed when that leaf was seeded in layout/function_starts.txt and
 *   matched (src/matched/G3D_SYSTEM_SetObjectAnimeFrame.c); all 11 relocations resolve.
 */
void func_02208AB0(Anim_02208AB0 *p)
{
    u32 x;
    void *q;
    u16 i;
    Node_02208AB0 *n;
    u16 id;

    p->f18 = G3D_UTIL_AddUnit(p->res, d_02208EC0);
    p->count = 1;
    p->nodes = (Node_02208AB0 *)func_022086C8(p->heap, p->count);
    id = func_020489F4(p->res, p->f18);
    n = p->nodes;
    p->f1a = 0;
    n->id = id;
    n->tx = 0;
    n->ty = 0;
    n->tz = 0;
    n->f40 = 1;
    for (i = 0; i < p->count; i++)
        G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)func_02048A18(p->res, p->nodes[i].id), 0);
    p->f24 = 0;
    q = (void *)func_02048A18(p->res, p->nodes[p->f1a].id);
    x = 0;
    p->f28 = 0;
    G3D_SYSTEM_EnableObjectAnime(q, 1);
    G3D_SYSTEM_EnableObjectAnime(q, 2);
    G3D_SYSTEM_SetObjectAnimeFrame(q, 1, (s32 *)(&x));
    G3D_SYSTEM_SetObjectAnimeFrame(q, 2, (s32 *)(&x));
}





void func_02208B54(char *a)
{
    G3D_UTIL_RemoveUnit((struct Ctx *)(*(int *)&((struct Obj05518 *)a)->f14), ((struct Obj05518 *)a)->f18);
    func_02208714((void *)(((struct Obj05518 *)a)->f20));
    ((struct Obj05518 *)a)->f1C = 0;
}





/*
 * blocker resolved: 0x02047910 and 0x020478B8 were matched in arm9
 *           (src/matched/G3D_SYSTEM_LoopObjectAnimeFrame.c, src/matched/G3D_SYSTEM_IncObjectAnimeFrame.c;
 *           shards pkt_02047910 and pkt_020478B8), so their call sites now
 *           attest as `matched`.  0x02048A18 already resolved via matched;
 *           all 164 bytes are correct.
 */
void func_02208B6C(char *p)
{
    unsigned short i;
    int j = 0;
    int v2;

    for (i = 0; i < ((struct Obj00789 *)p)->f1C; i++) {
        unsigned short v = *(unsigned short *)(((struct Obj00789 *)p)->f20 + i * 0x44);
        int x = func_02048A18((u8 *)(((struct Obj00789 *)p)->f14), v);

        G3D_SYSTEM_LoopObjectAnimeFrame((void *)x, j, 0x1000);
    }
    ((struct Obj00789 *)p)->f24 = ((struct Obj00789 *)p)->f24 + 1;
    v2 = func_02048A18((u8 *)(((struct Obj00789 *)p)->f14),
                       *(unsigned short *)(((struct Obj00789 *)p)->f20 +
                                           ((struct Obj00789 *)p)->f1A * 0x44));
    if (((struct Obj00789 *)p)->f28 == 1) {
        int a = G3D_SYSTEM_IncObjectAnimeFrame((void *)v2, 1, 0x5000);
        int b = G3D_SYSTEM_IncObjectAnimeFrame((void *)v2, 2, 0x5000);

        if (a == 0 && b == 0)
            ((struct Obj00789 *)p)->f28 = 2;
    } else if (((struct Obj00789 *)p)->f28 == 3) {
        int a = G3D_SYSTEM_IncObjectAnimeFrame((void *)v2, 1, -0x2000);
        int b = G3D_SYSTEM_IncObjectAnimeFrame((void *)v2, 2, -0x2000);

        if (a == 0 && b == 0)
            ((struct Obj00789 *)p)->f28 = 0;
    }
}





void func_02208C10(Anim_02208C10 *p)
{
    p->state = 1;
}





int func_02208C18(Anim_02208C18 *p)
{
    if (p->state == 2)
        return 1;
    return 0;
}





void func_02208C28(Anim_02208C28 *p)
{
    p->state = 3;
}

int func_02208C30(Anim_02208C28 *p)
{
    if (p->state == 0)
        return 1;
    return 0;
}
