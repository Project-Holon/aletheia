/*
 * file:     btlv_effvm.c
 * unit:     yes
 * function: func_021F93F4, func_021F9478, func_021F94D8, func_021F94F8, func_021F97E4, func_021F9814, func_021F9824, func_021F9844, func_021F9858, func_021F9948, func_021F9A7C, func_021F9AA4, func_021F9AB8, func_021F9EFC, func_021F9FC0, func_021FA048, func_021FA09C, func_021FA108, func_021FA12C, func_021FA288, func_021FA358, func_021FA458, func_021FA5D0, func_021FA758, func_021FA794, func_021FA884, func_021FA988, func_021FAB0C, func_021FAC94, func_021FACA0, func_021FACAC, func_021FAD2C, func_021FADC0, func_021FAE48, func_021FAECC, func_021FAF44, func_021FAFBC, func_021FB034, func_021FB09C, func_021FB0E8, func_021FB168, func_021FB1C4, func_021FB214, func_021FB298, func_021FB2D0, func_021FB328, func_021FB390, func_021FB3C8, func_021FB3DC, func_021FB49C, func_021FB500, func_021FB524, func_021FB550, func_021FB574, func_021FB5D4, func_021FB624, func_021FB648, func_021FB6F4, func_021FB790, func_021FB7F8, func_021FB864, func_021FB894, func_021FB8F4, func_021FB91C, func_021FBA64, func_021FBAD8, func_021FBAF8, func_021FBC78, func_021FBCEC, func_021FBD10, func_021FBD34, func_021FBD44, func_021FBD88, func_021FBDD4, func_021FBE28, func_021FBE60, func_021FBE74, func_021FBE90, func_021FBF48, func_021FBFA0, func_021FBFC0, func_021FC134, func_021FC148, func_021FC20C, func_021FC2DC, func_021FC334, func_021FC354, func_021FC374, func_021FC3D8, func_021FC434, func_021FC448, func_021FC744, func_021FC9D0, func_021FC9E4, func_021FC9F4, func_021FCA04, func_021FCD14, func_021FCF2C, func_021FD04C, func_021FD070, func_021FD088, func_021FD15C, func_021FD19C, func_021FD1A8, func_021FD1C0, func_021FD1CC, func_021FD8CC, func_021FD9F0, func_021FDA28, func_021FDB08, func_021FDB20, func_021FDB40, func_021FDBB0, func_021FDD60, func_021FDFA0, func_021FE1B8, func_021FE254, func_021FE38C, func_021FE410, func_021FE4D0, func_021FE4F8, func_021FE520, func_021FE54C, func_021FE580, func_021FE594, func_021FE690, func_021FE6A4, func_021FE750, func_021FE768, func_021FE79C, func_021FE8AC, func_021FE8D8, func_021FE930, func_021FE9BC, func_021FE9F0, func_021FEAA0
 * address:  0x021F93F4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btlv_effvm.c, btlv_b_gauge.c, btlv_bg.c, btlv_finger_cursor.c by tools/splitfile.py.
 *
 * symbols:
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   func_020307B0  0x020307B0  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207C768  0x0207C768  arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   func_020056A0  0x020056A0  thumb
 *   func_02030DA8  0x02030DA8  arm
 *   func_02040588  0x02040588  arm
 *   TCBL_GetTaskUserData   0x02030EE8  arm
 *   d_0220AE68     0x0220AE68  data   ov094  a1
 *   d_02209DCC     0x02209DCC  data   ov094  a4
 *   func_02030734  0x02030734  arm
 *   VM_Create  0x0201121C  thumb
 *   VM_Init  0x0201126C  thumb
 *   VM_Control  0x02011298  thumb
 *   func_02011324  0x02011324  thumb
 *   VM_Delete 0x02011264 thumb
 *   VM_Start  0x0201127C  thumb
 *   MIi_CpuClear16  0x02082A48  arm
 *   PM_VOICE_StopSlot 0x02006BB4 thumb
 *   VM_GetU32  0x0201134C  thumb
 *   d_0220ACA0  0x0220ACA0  data  a4
 *   d_0220ACE8  0x0220ACE8  data  a4
 *   d_0220AD00  0x0220AD00  data  a4
 *   d_0220AD78  0x0220AD78  data  a4
 *   d_0220ADA8  0x0220ADA8  data  a4
 *   d_0220ADD8  0x0220ADD8  data  a4
 *   d_0220AE20  0x0220AE20  data  a4
 *   func_0207C9D0  0x0207C9D0  arm
 *   VM_SetWait 0x020113D0 thumb
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   PARTICLE_CreateSystem 0x02050C30 arm
 *   PARTICLE_SetupSystemNoHandlers 0x02051380 arm
 *   PARTICLE_StartEffectWithCallback 0x020515CC arm
 *   PARTICLE_InitCamera 0x02051648 arm
 *   BUTTON_MAN_GetBlock 0x02051788 arm
 *   d_02209E1C 0x02209E1C data a4
 *   d_02209D90 0x02209D90 data a4
 *   d_02209D78 0x02209D78 data a4
 *   d_02209E04 0x02209E04 data a4
 *   d_02209DC0 0x02209DC0 data ov094 a4
 *   d_02209D84 0x02209D84 data ov094 a4
 *   d_02209DA8 0x02209DA8 data ov094 a4
 *   d_02209D9C 0x02209D9C data ov094 a4
 *   func_0204047C  0x0204047C  arm
 *   func_02049624  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   PALANM_LoadArcPaletteToSlotAt  0x020215EC  thumb
 *   func_020407E8  0x020407E8  arm
 *   func_02040804  0x02040804  arm
 *   BTLV_BG_SetScroll  0x02209784  thumb  ov094
 *   BTLV_BG_StartScroll  0x022097CC  thumb  ov094
 *   func_0207D63C  0x0207D63C  arm
 *   func_0206DF3C  0x0206DF3C  arm
 *   BTLV_GAUGE_PlaceSlot  0x022079C0  thumb  ov094
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 *   VM_Jump  0x020113B0  thumb
 *   PALANM_GetPairedCodeForFirst  0x0202142C  thumb
 *   VM_Call 0x020113B4 thumb
 *   VM_Return  0x020113C4  thumb
 *   func_02011290 0x02011290 thumb
 *   BTLV_SCU_ReloadGraphics 0x021EB2A8 thumb ov093
 *   func_02040618 0x02040618 arm
 *   BTLV_BG_IsScrolling 0x0220985C thumb ov094
 *   PARTICLE_GetEffectCount 0x02051614 arm
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   GFL_USE_IsSeSlotBusy 0x02006224 thumb
 *   PM_VOICE_IsActive 0x02006BD0 thumb
 *   d_02209E58 0x02209E58 data a4
 *   d_02209E28 0x02209E28 data ov094 a4
 *   d_0220AD18 0x0220AD18 data ov094 a4
 *   d_0220AD38 0x0220AD38 data ov094 a4
 *   d_0220AD58     0x0220AD58  data   ov094
 *   func_02051774 0x02051774 arm
 *   BUTTON_MAN_SetUserData 0x02051A2C arm
 *   BUTTON_MAN_SetCallback 0x02051A24 arm
 *   func_0207CF3C 0x0207CF3C arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   func_0207CA68 0x0207CA68 arm
 *   FX_AcosIdx 0x0207D184 arm
 *   func_0207CAE8 0x0207CAE8 arm
 *   MTX_RotAxis43 0x0207B65C arm
 *   MTX_MultVec43 0x0207BC08 arm
 *   BUTTON_MAN_SetRow2 0x020519C4 arm
 *   BUTTON_MAN_SetRow5 0x02051A04 arm
 *   BUTTON_MAN_GetRot 0x020517B4 arm
 *   BUTTON_MAN_SetRow3Half 0x020519E4 arm
 *   BUTTON_MAN_SetRot 0x02051880 arm
 *   BUTTON_MAN_GetScaleX 0x020517D0 arm
 *   BUTTON_MAN_GetAlpha 0x02051830 arm
 *   BUTTON_MAN_GetAngle 0x02051820 arm
 *   BUTTON_MAN_GetScaleY 0x020517E0 arm
 *   BUTTON_MAN_SetScaleX 0x020517D8 arm
 *   BUTTON_MAN_SetScaleY 0x020517E8 arm
 *   BUTTON_MAN_SetAlpha 0x020518A4 arm
 *   BUTTON_MAN_SetAngle 0x0205189C arm
 *   BUTTON_MAN_GetPos 0x02051790 arm
 *   BUTTON_MAN_SetPos 0x020517A4 arm
 *   BUTTON_MAN_GetOffsetX 0x020517F0 arm
 *   BUTTON_MAN_SetOffsetX 0x02051800 arm
 *   BUTTON_MAN_GetOffsetY 0x02051808 arm
 *   BUTTON_MAN_SetOffsetY 0x02051818 arm
 *   BUTTON_MAN_SetEmitterPos 0x02051838 arm
 *   BUTTON_MAN_GetUserData  0x02051A34  arm
 *   PARTICLE_GetWorkBase  0x02051640  arm
 *   PARTICLE_DeleteSystem  0x02050DB8  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 *   GFL_USE_GetSeHandle  0x02006138  thumb
 *   GFL_USE_SetSeSlotParams  0x02006268  thumb
 *   NNS_SndHandleSetVolume  0x02072F34  arm
 *   NNS_SndHandleSetTrackModDepth  0x02073058  arm
 *   NNS_SndHandleSetTrackModSpeed  0x02073078  arm
 *   _s32_div_f 0x0209C0A4 arm
 *   d_02209E10 0x02209E10 data
 *   d_02209DB4 0x02209DB4 data
 *   MTX_Copy43To44_  0x0207B5C0  arm
 *   MTX_Concat44     0x0207BE14  arm
 *   FX_Div           0x0207C768  arm
 *   g_renderStateDrawParams       0x02148B98  data
 *   SCREENTEX_ProjectionMatrix       0x02148B54  data
 *   func_0200F698  0x0200F698  thumb
 *   PARTICLE_ApplyLoadHandlers  0x02051394  arm
 *   d_02209DD8  0x02209DD8  data  ov094
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021F89BC 0x021F89BC thumb ov094
 *   func_021F6EDC 0x021F6EDC thumb ov094
 *   func_021F6F20 0x021F6F20 thumb ov094
 *   func_021F6F48 0x021F6F48 thumb ov094
 *   func_021F7000 0x021F7000 thumb ov094
 *   func_021F70F0 0x021F70F0 thumb ov094
 *   func_021F7108 0x021F7108 thumb ov094
 *   func_021F7208 0x021F7208 thumb ov094
 *   func_021F722C 0x021F722C thumb ov094
 *   func_021F7F04 0x021F7F04 thumb ov094
 *   func_021F7F1C 0x021F7F1C thumb ov094
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021F8010 0x021F8010 thumb ov094
 *   func_021F8198 0x021F8198 thumb ov094
 *   func_021F81B4 0x021F81B4 thumb ov094
 *   func_021F8298 0x021F8298 thumb ov094
 *   func_021F8324 0x021F8324 thumb ov094
 *   func_021F839C 0x021F839C thumb ov094
 *   func_021F84D0 0x021F84D0 thumb ov094
 *   func_021F8684 0x021F8684 thumb ov094
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_021F86B4 0x021F86B4 thumb ov094
 *   func_021F86F0 0x021F86F0 thumb ov094
 *   func_021F8700 0x021F8700 thumb ov094
 *   func_021F8710 0x021F8710 thumb ov094
 *   func_021F8730 0x021F8730 thumb ov094
 *   func_021F8740 0x021F8740 thumb ov094
 *   func_021F8764 0x021F8764 thumb ov094
 *   func_021F88E0 0x021F88E0 thumb ov094
 *   func_021F8934 0x021F8934 thumb ov094
 *   func_021F8A10 0x021F8A10 thumb ov094
 *   func_021F9154 0x021F9154 thumb ov094
 *   func_021F9220 0x021F9220 thumb ov094
 *   func_021F935C 0x021F935C thumb ov094
 *   func_021FF134 0x021FF134 thumb ov094
 *   func_021FF16C 0x021FF16C thumb ov094
 *   func_021FF1B0 0x021FF1B0 thumb ov094
 *   func_021FF1F4 0x021FF1F4 thumb ov094
 *   func_021FF228 0x021FF228 thumb ov094
 *   func_021FF304 0x021FF304 thumb ov094
 *   func_021FF348 0x021FF348 thumb ov094
 *   func_021FF374 0x021FF374 thumb ov094
 *   func_021FF3F4 0x021FF3F4 thumb ov094
 *   func_021FF3FC 0x021FF3FC thumb ov094
 *   func_021FF468 0x021FF468 thumb ov094
 *   func_021FF470 0x021FF470 thumb ov094
 *   func_021FF4C0 0x021FF4C0 thumb ov094
 *   func_021FF5B0 0x021FF5B0 thumb ov094
 *   func_021FF630 0x021FF630 thumb ov094
 *   func_021FF6B0 0x021FF6B0 thumb ov094
 *   func_021FF730 0x021FF730 thumb ov094
 *   func_021FF870 0x021FF870 thumb ov094
 *   func_021FF924 0x021FF924 thumb ov094
 *   func_021FFA18 0x021FFA18 thumb ov094
 *   func_021FFB04 0x021FFB04 thumb ov094
 *   func_021FFBBC 0x021FFBBC thumb ov094
 *   func_021FFCB0 0x021FFCB0 thumb ov094
 *   func_021FFD9C 0x021FFD9C thumb ov094
 *   func_021FFDB4 0x021FFDB4 thumb ov094
 *   func_021FFF0C 0x021FFF0C thumb ov094
 *   func_021FFF38 0x021FFF38 thumb ov094
 *   func_021FFF68 0x021FFF68 thumb ov094
 *   func_021FFFAC 0x021FFFAC thumb ov094
 *   func_021FFFD8 0x021FFFD8 thumb ov094
 *   func_02200140 0x02200140 thumb ov094
 *   func_02200218 0x02200218 thumb ov094
 *   func_022003C4 0x022003C4 thumb ov094
 *   func_0220041C 0x0220041C thumb ov094
 *   func_02200468 0x02200468 thumb ov094
 *   func_02200494 0x02200494 thumb ov094
 *   func_022004BC 0x022004BC thumb ov094
 *   func_02200654 0x02200654 thumb ov094
 *   func_02201AF8 0x02201AF8 thumb ov094
 *   func_02201B20 0x02201B20 thumb ov094
 *   func_02201CA4 0x02201CA4 thumb ov094
 *   func_02201CD0 0x02201CD0 thumb ov094
 *   func_02201D5C 0x02201D5C thumb ov094
 *   func_02201DA0 0x02201DA0 thumb ov094
 *   func_02201DB4 0x02201DB4 thumb ov094
 */
#include "../../matched/include/Obj21678.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj21683.h"
#include "../../matched/include/Obj13598.h"
#include "../../matched/include/Obj18571.h"
#include "btlv_effvm_types.h"
#include "btlv_camera_shared_types.h"
#include "btlv_effect_shared_types.h"
#include "btlv_effvm_shared_types.h"

#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))

#define REG16(a) (*(volatile u16 *)(a))

#define REG32(a) (*(volatile unsigned int *)(a))

struct ScriptVm;

struct ScriptVmParams;

struct Cursor;

struct Dst648;

struct Src648;

struct Cur;

struct Ring;

struct Obj_vD04C;

struct S12;

struct Vec3;

typedef struct {
    char pad0[8];
    void *a;            /* 8 */
    char pad1[0x40];
    int v4c[16];        /* 0x4C */
    char padx[0x40];
    int vcc[4];         /* 0xCC */
    char pad2[0x238 - 0xDC];
    u16 h238;           /* 0x238 */
    char pad3[2];
    int f23c;           /* 0x23C */
    char pad4[4];
    int f244;           /* 0x244 */
    char pad5[0x26C - 0x248];
    int e26c[6];        /* 0x26C */
} T_021F93F4;

typedef struct {
    BtlvEffVmWork *work;
    u32 a;
    int b;
    int c;
    int d;
    int e;
    u32 f;
    int g;
    int h;
} Job_021F9858;

typedef struct {
    BtlvEffVmWork *work;
    u32 a;
    int mode;
    int c;
    int x;
    int dest;
    int fx;
    int delta;
    int e;
    int f;
    int remaining;
    int zero;
    int g;
    int duration;
} Job_021F9948;

typedef struct {
    int x, y, z;
} VecFx32_v9814;

typedef struct { BtlvEffVmWork *state; void *emitter; void *resource; } Callback;

typedef struct { u32 v[8]; } Desc_021F6560;

typedef struct {
    int f0;
    int item;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    char pad[0x14];
} Req_021FAD2C;

typedef struct {
    int f0;
    int item;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
} Req_021FADC0;

typedef short s16_021FA758;

typedef struct {
    int x;
    int y;
    int z;
} Pt_021FC148;

typedef enum { KEY_ZERO, KEY_ONE, KEY_TWO, KEY_THREE, KEY_MAX = 7 } Key_021F6560;

typedef struct { int v[4][3]; } Targets;

typedef struct { s16_021F6560 x, y, z; } Vec16;

typedef struct { int m[12]; } Mtx;

typedef struct { u16 on; Vec16 dir; } Dir;

typedef struct {
    int vm;         /* 0x00 */
    int k1;         /* 0x04 */
    int k2;         /* 0x08 */
    Vec_021F6560 ofs;        /* 0x0c */
    int f18;        /* 0x18 */
    int f1c;        /* 0x1c */
    int kind;       /* 0x20 */
    int f24;        /* 0x24 */
    Vec_021F6560 pa;         /* 0x28 */
    Vec_021F6560 pb;         /* 0x34 */
    int mode;       /* 0x40 */
    int f44;        /* 0x44 */
    int f48;        /* 0x48 */
    int f4c;        /* 0x4c */
    int f50;        /* 0x50 */
    int f54;        /* 0x54 */
    int flip;       /* 0x58 */
} Rec_021FD04C;

typedef struct {
    int m[9];       /* 0x00 */
    Vec_021F6560 pos;        /* 0x24 */
    int f30;        /* 0x30 */
    int f34;        /* 0x34 */
    int f38;        /* 0x38 */
    int f3c;        /* 0x3c */
    int f40;        /* 0x40 */
    int f44;        /* 0x44 */
    int f48;        /* 0x48 */
    int f4c;        /* 0x4c */
    int f50;        /* 0x50 */
    int f54;        /* 0x54 */
    int f58;        /* 0x58 */
    int f5c;        /* 0x5c */
} Obj_vD04C;

typedef struct { int x, y, z; } VecFx32_021FD04C;

typedef struct {
    char pad00[0x0c];
    int k0c;                /* 0x0c */
    char pad10[0x2c];
    int k3c;                /* 0x3c */
} State_021FD04C;

typedef struct { int v[23]; } Rec_021FDD60;

typedef long long fx64;

typedef struct { fx32 x, y, z; } VecFx32_021FE1B8;

typedef struct { fx32 m[4][3]; } MtxFx43;

typedef struct { fx32 m[4][4]; } MtxFx44;

typedef struct {
    BtlvEffVmWork *obj;
    int a1, a2, a3;
    int a4, a5, a6;
    int cnt;
} Req;

typedef struct {
    unsigned int *reg;      /* 0x00 */
    char pad04[0x20];
    int k24;                /* 0x24 */
} Ctx_021FE254;

typedef struct {
    int pad0;
    int side;
    int mask;
} Arg_vE254;

typedef struct {
    unsigned int *reg;      /* 0x00 */
    void *obj;              /* 0x04 */
} Ctx_021FE9BC;

typedef enum { SLOT_0, SLOT_MAX = 8 } Slot_021FD04C;

extern void *ARC_TOOL_LoadMember(u32, u32, u32);

extern u32 func_020307B0(void *p);

extern u32 func_0207C768(u32 a, u32 b);

extern void *func_020056A0(void (*)(void *, void *), void *, int);

extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 n);

extern void func_02040588(unsigned char which, unsigned char enable);

extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);

extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct ScriptVm *VM_Create(u32 heapId, const struct ScriptVmParams *params);

extern void VM_Init(struct ScriptVm *vm, void *user);

extern int VM_Control(struct ScriptVm *vm);

extern void *func_02011324(void *vm);

extern void VM_Delete(void *);

extern void VM_Start(struct ScriptVm *vm, u8 *pc);

extern void MIi_CpuClear16(u16 data, void *destp, u32 size);

extern void PM_VOICE_StopSlot(u32 i);

extern u32 VM_GetU32(struct Cursor *p);

extern void func_0207C9D0(int *a, int *b, int *c);

extern void VM_SetWait(char *p, int val);

extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);

extern void *PARTICLE_CreateSystem(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap);

extern void PARTICLE_SetupSystemNoHandlers(void *, void *);

extern int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);

extern void PARTICLE_InitCamera(struct Dst648 *this, struct Src648 *src, u16 a2, int *a3, int *a4, int *a5, u16 a6);

extern int BUTTON_MAN_GetBlock(char *p);

extern void func_0204047C(int idx, unsigned short val);

extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);

extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);

extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);

extern u32 func_020407E8(u32 layer);

extern u32 func_02040804(u32 layer);

extern void BTLV_BG_SetScroll(int a, int b, int c);

extern void BTLV_BG_StartScroll(int a, int b, int c, int d, int e, int f, int g, int h);

extern void func_0207D63C(int reg, int a, int b, int c, int d);

extern void func_0206DF3C(int *p, int *q, int *r);

extern void BTLV_GAUGE_PlaceSlot(char *p, int i, Pt_021FB8F4 *pt);

extern void GFL_USE_StopAllSe(void);

extern void GFL_USE_StopSeSlot(int i);

extern float _fflt(int);

extern float _fadd(float, float);

extern float _fsub(float, float);

extern int _ffix(float);

extern void VM_Jump(struct Cur *c, u32 v);

extern unsigned short PALANM_GetPairedCodeForFirst(int a0);

extern void VM_Call(struct Ring *r, unsigned int v);

extern u32 VM_Return(struct Ring *r);

extern struct ScriptVm *func_02011290(struct ScriptVm *vm);

extern void BTLV_SCU_ReloadGraphics(const u8 *a);

extern void func_02040618(u32 layer, u32 a, u32 b);

extern int BTLV_BG_IsScrolling(void *);

extern int PARTICLE_GetEffectCount(int **p);

extern int GFL_USE_IsAnySeBusy(void);

extern int GFL_USE_IsSeSlotBusy(unsigned);

extern u32 PM_VOICE_IsActive(u32 i);

extern u32 func_02051774(void);

extern void BUTTON_MAN_SetUserData(void *p, int v);

extern void BUTTON_MAN_SetCallback(void *p, int v);

extern int func_0207CF3C(const Vec_021F6560 *a, const Vec_021F6560 *b);

extern void VEC_Normalize(const Vec_021F6560 *a, Vec_021F6560 *b);

extern int func_0207CA68(const Vec_021F6560 *a, const Vec_021F6560 *b);

extern u16 FX_AcosIdx(int a);

extern void func_0207CAE8(const Vec_021F6560 *a, const Vec_021F6560 *b, Vec_021F6560 *c);

extern void MTX_RotAxis43(void *m, const Vec_021F6560 *axis, int s, int c);

extern void MTX_MultVec43(const Vec_021F6560 *a, const void *m, Vec_021F6560 *out);

extern void BUTTON_MAN_SetRow2(void *p, struct S12 *q);

extern void BUTTON_MAN_SetRow5(void *p, struct S12 *q);

extern void BUTTON_MAN_GetRot(void *p, Vec16 *v);

extern void BUTTON_MAN_SetRow3Half(void *p, u16 *q);

extern void BUTTON_MAN_SetRot(struct Obj_vD04C *o, const struct Vec3 *v);

extern int BUTTON_MAN_GetScaleX(char *p);

extern unsigned short BUTTON_MAN_GetAlpha(char *p);

extern short BUTTON_MAN_GetAngle(char *p);

extern int BUTTON_MAN_GetScaleY(char *p);

extern void BUTTON_MAN_SetScaleX(char *p, int v);

extern void BUTTON_MAN_SetScaleY(char *p, int v);

extern void BUTTON_MAN_SetAlpha(struct Obj_vD04C *o, u16 v);

extern void BUTTON_MAN_SetAngle(struct Obj_vD04C *o, u32 v);

extern void BUTTON_MAN_GetPos(void *p, Vec_021F6560 *v);

extern void BUTTON_MAN_SetPos(void *p, const Vec_021F6560 *v);

extern short BUTTON_MAN_GetOffsetX(char *p);

extern void BUTTON_MAN_SetOffsetX(char *p, int v);

extern short BUTTON_MAN_GetOffsetY(char *p);

extern void BUTTON_MAN_SetOffsetY(char *p, int v);

extern void BUTTON_MAN_SetEmitterPos(void *p, const Vec_021F6560 *v);

extern int BUTTON_MAN_GetUserData(void *p);

extern void *PARTICLE_GetWorkBase(char *p);

extern void PARTICLE_DeleteSystem(u8 *p);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern int GFL_USE_GetSeSlot(u32 a);

extern void GFL_USE_PlaySeInSlot(void *arg, int i);

extern u32 *GFL_USE_GetSeHandle(int i);

extern void GFL_USE_SetSeSlotParams(int i, u32 a, u32 b, u32 c);

extern void NNS_SndHandleSetVolume(char *p, unsigned int v);

extern void NNS_SndHandleSetTrackModDepth(struct Obj_vD04C *o, u32 v, u32 w);

extern void NNS_SndHandleSetTrackModSpeed(struct Obj_vD04C *o, u32 v, u32 w);

extern int _s32_div_f(int, int);

void MTX_Copy43To44_(const MtxFx43 *src, MtxFx44 *dst);

void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);

fx32 FX_Div(fx32 numer, fx32 denom);

extern void func_0200F698(void *a, void *b);

extern void PARTICLE_ApplyLoadHandlers(u32 *p);

void func_021F6EDC(int *p, int *a, int *b);

void func_021F6F20(Obj_021F6F20 *p, int a, int b);

void func_021F6F48(Cam_021F6F48 *c, VecFx32_v6560 *a, VecFx32_v6560 *b, int n, int s, int t);

void func_021F7000(Cam_021F7000 *c, int mode, fx32 v, int unused, int n, int g, int h);

void func_021F70F0(void **p, void *b, int c);

void func_021F7108(int *p, int a, int b, int *out, int *base);

void func_021F7208(VecFx32_v6560 *a, VecFx32_v6560 *b);

int func_021F722C(char *p);

void func_021F7F04(int a);

int func_021F7F1C(int i);

void func_021F7F58(int a, u32 b, u32 c, u32 d, u32 e);

void func_021F8010(int a);

void func_021F8198(int a, int b);

void func_021F81B4(u32 a, u32 b);

void func_021F8298(u32 a, u8 b, u8 c, u8 d, u16 e);

int func_021F8324(u32 a);

void func_021F839C(u32 a, u32 b);

int func_021F84D0(int a);

int func_021F8684(void);

int func_021F8694(void);

int func_021F86B4(void);

int func_021F86E0(void);

int func_021F86F0(void);

int func_021F8700(void);

int func_021F8710(void);

int func_021F8730(void);

unsigned short func_021F8740(int a);

int func_021F8764(void);

int func_021F88E0(void);

void func_021F8934(int a);

void func_021F896C(void *h, void (*cb)(void *), int arg);

void func_021F89BC(void *h);

void func_021F8A10(int a);

void func_021F9154(int a, int b, int *out, int c);

void func_021F9220(int *p, int *d, int *lim, int *flag);

int func_021F935C(int x);

void *func_021F93F4(void *a, u32 b);

int func_021F9478(void *vm);

void func_021F94D8(void *a);

void func_021F94F8(void *vm, u32 a1, u32 a2, u16 id, BtlvEffVmParams *q);

void func_021F97E4(void *a);

void func_021F9814(void *a);

int func_021F9824(void *a);

void func_021F9844(S9844 *p);

void func_021F9858(void *vm, u32 a, int b, u32 c, int e, u32 f, int g, int h, int d);

void func_021F9948(void *vm, u32 a, int mode, int c, int x, int dest, int e, int f, int g, int duration);

void func_021F9A7C(void *a);

void func_021F9AA4(void *a);

int func_021F9AB8(void *r, BtlvEffVmWork *c);

int func_021F9EFC(void *r, BtlvEffVmWork *c);

int func_021F9FC0(void *r, BtlvEffVmWork *c);

int func_021FA048(void *r, BtlvEffVmWork *c);

int func_021FA09C(void *a, BtlvEffVmWork *s);

int func_021FA108(int a, BtlvEffVmWork *b);

int func_021FA12C(void *a, BtlvEffVmWork *s);

int func_021FA288(void *a, BtlvEffVmWork *s);

int func_021FA358(void *a, BtlvEffVmWork *s);

int func_021FA458(void *a, BtlvEffVmWork *s);

int func_021FA5D0(void *a, BtlvEffVmWork *s);

int func_021FA758(void *a, BtlvEffVmWork *s);

int func_021FA794(void *a, BtlvEffVmWork *s);

int func_021FA884(void *a, BtlvEffVmWork *s);

int func_021FA988(void *a, BtlvEffVmWork *s);

int func_021FAB0C(void *a, BtlvEffVmWork *s);

void func_021FAC94(void *a, void *b);

void func_021FACA0(void *a, void *b);

int func_021FACAC(void *a, BtlvEffVmWork *s);

int func_021FAD2C(void *a, BtlvEffVmWork *s);

int func_021FADC0(void *a, BtlvEffVmWork *s);

int func_021FAE48(void *a, BtlvEffVmWork *s);

int func_021FAECC(void *a, BtlvEffVmWork *s);

int func_021FAF44(void *a, BtlvEffVmWork *s);

int func_021FAFBC(void *a, BtlvEffVmWork *s);

int func_021FB034(void *a, BtlvEffVmWork *s);

int func_021FB09C(void *a, BtlvEffVmWork *s);

int func_021FB0E8(void *a, BtlvEffVmWork *s);

int func_021FB168(void *a, BtlvEffVmWork *s);

int func_021FB1C4(struct Cursor *a, BtlvEffVmWork *b);

int func_021FB214(struct Cursor *a, BtlvEffVmWork *b);

int func_021FB298(void *a, BtlvEffVmWork *s);

int func_021FB2D0(struct Cursor *a, BtlvEffVmWork *b);

int func_021FB328(struct Cursor *a, BtlvEffVmWork *b);

int func_021FB390(void *a, BtlvEffVmWork *s);

int func_021FB3C8(void *a, BtlvEffVmWork *s);

int func_021FB3DC(struct Cursor *a, BtlvEffVmWork *b);

int func_021FB49C(struct Cursor *a, BtlvEffVmWork *b);

int func_021FB500(void *a, BtlvEffVmWork *s);

int func_021FB524(void *a, BtlvEffVmWork *s);

int func_021FB550(void *a, BtlvEffVmWork *s);

int func_021FB574(struct Cursor *a, BtlvEffVmWork *b);

int func_021FB5D4(struct Cursor *a, BtlvEffVmWork *b);

int func_021FB624(void *a, BtlvEffVmWork *s);

int func_021FB648(struct Cursor *a, BtlvEffVmWork *b);

int func_021FB6F4(struct Cursor *a, BtlvEffVmWork *b);

int func_021FB790(struct Cursor *a, BtlvEffVmWork *b);

int func_021FB7F8(struct Cursor *a, BtlvEffVmWork *b);

int func_021FB864(void *a, BtlvEffVmWork *s);

int func_021FB894(struct Cursor *a, BtlvEffVmWork *s);

int func_021FB8F4(void *a, BtlvEffVmWork *s);

int func_021FB91C(void *r, BtlvEffVmWork *s);

int func_021FBA64(struct Cursor *a, BtlvEffVmWork *s);

int func_021FBAD8(void *a, BtlvEffVmWork *s);

int func_021FBAF8(void *a, BtlvEffVmWork *s);

int func_021FBC78(struct Cursor *a, BtlvEffVmWork *s);

int func_021FBCEC(void *a, BtlvEffVmWork *s);

int func_021FBD10(void *a, BtlvEffVmWork *s);

void func_021FBD34(void *a, BtlvEffVmWork *s);

int func_021FBD44(struct Cursor *a, BtlvEffVmWork *s);

int func_021FBD88(struct Cursor *a, BtlvEffVmWork *s);

void func_021FBDD4(int a, int b, int c, int op, int e);

int func_021FBE28(struct Cursor *a, BtlvEffVmWork *s);

int func_021FBE60(void *a, BtlvEffVmWork *s);

int func_021FBE74(void *a, BtlvEffVmWork *s);

int func_021FBE90(struct Cursor *a, BtlvEffVmWork *s);

int func_021FBF48(struct Cursor *a, BtlvEffVmWork *s);

int func_021FBFA0(int a, BtlvEffVmWork *b);

int func_021FBFC0(void *a, BtlvEffVmWork *s);

int func_021FC134(void *a, BtlvEffVmWork *s);

int func_021FC148(struct Cursor *a, BtlvEffVmWork *s);

int func_021FC20C(struct Ring *a, BtlvEffVmWork *s);

int func_021FC2DC(int a, BtlvEffVmWork *s);

int func_021FC334(struct Cursor *a, BtlvEffVmWork *s);

int func_021FC354(void *a, BtlvEffVmWork *s);

int func_021FC374(void *a, BtlvEffVmWork *s);

int func_021FC3D8(struct Cursor *a, BtlvEffVmWork *s);

int func_021FC434(void *a, BtlvEffVmWork *s);

int func_021FC448(void *a, BtlvEffVmWork *s);

int func_021FC744(int a, BtlvEffVmWork *s);

int func_021FC9D0(void *a, BtlvEffVmWork *s);

int func_021FC9E4(void *a, BtlvEffVmWork *s);

int func_021FC9F4(void *a, BtlvEffVmWork *s);

int func_021FCA04(BtlvEffVmWork *s, int cmd, int *out);

int func_021FCD14(BtlvEffVmWork *s, int unused, int *out);

int func_021FCF2C(int a, int idx);

int func_021FD04C(BtlvEffVmWork *s, int i);

int func_021FD070(int a, int b);

int func_021FD088(int a, int *out);

int func_021FD15C(BtlvEffVmWork *p, int key, int *out);

void func_021FD19C(BtlvEffVmWork *p, int i, char *q);

int func_021FD1A8(BtlvEffVmWork *p, int v);

int func_021FD1C0(BtlvEffVmWork *p, int i);

void func_021FD1CC(void *p);

void func_021FD8CC(void *p, int active);

void func_021FD9F0(void *p);

void func_021FDA28(void *p, int active);

void func_021FDB08(void *p);

void func_021FDB20(BtlvEffVmWork *s);

void func_021FDB40(u32 a0, int m, int a2, int a3, unsigned int e, unsigned int f, unsigned int g);

int func_021FDBB0(BtlvEffVmWork *s, unsigned int key);

void func_021FDD60(BtlvEffVmWork *s, Rec_021FDD60 *r, int slot, int arg);

int func_021FDFA0(void *a, BtlvEffVmWork *s, int mode);

void func_021FE1B8(VecFx32_021FE1B8 *v, const VecFx32_021FE1B8 *ofs);

void func_021FE254(const VecFx32 *v, const MtxFx44 *m, fx32 *out, fx32 *w);

unsigned int func_021FE38C(BtlvEffVmWork *p, unsigned int k);

void func_021FE410(BtlvEffVmWork *o, int a, int b, int n);

int func_021FE4D0(BtlvEffVmWork *p);

void func_021FE4F8(void *unused);

void func_021FE520(void *unused);

void func_021FE54C(void *h, void *arg);

void func_021FE580(void *h);

void func_021FE594(void *h, void *arg);

void func_021FE690(void *h);

void func_021FE6A4(void *h, void *arg);

void func_021FE750(void *h);

void func_021FE768(void *h, void *arg);

void func_021FE79C(void *h, void *arg);

void func_021FE8AC(void *h);

void func_021FE8D8(void *h, void *arg);

void func_021FE930(void *h, void *arg);

void func_021FE9BC(void *h, void *arg);

void func_021FE9F0(fx32 a, fx32 b, int n, int f48, int f4c);

int func_021FEAA0(int v);

void func_021FF134(char *p, int a, int b);

void func_021FF16C(Work_021FF16C *w);

void func_021FF1B0(Work_021FF1B0 *w);

void func_021FF1F4(Work_vE254 *w, int key);

void func_021FF228(Work_021FF228 *w, int key);

void func_021FF304(Work_021FF228 *w, int key, int mode);

int func_021FF348(Work_021FF348 *w, int key);

void func_021FF374(Work_vF228 *w, int key, int kind);

void func_021FF3F4(void *obj, void *out, int idx);

void func_021FF3FC(const Vec3_vF228 *def, Vec3_vF228 *out, int idx, int kind);

int func_021FF468(void *u, int i, int mode);

void func_021FF470(char *p, int key, u8 v);

void func_021FF4C0(char *w, int key, int kind, Vec_021F6560 *q, int a, int b, int c);

void func_021FF5B0(Work_021FF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c);

void func_021FF630(Work_021FF630 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c);

void func_021FF6B0(Work_vF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c);

void func_021FF730(Work_vF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c);

void func_021FF870(Work_021FF870 *w, int key, int kind, int a, int b);

void func_021FF924(char *w, int key, int kind, int value, int a, int b, int c);

void func_021FFA18(Work_021FFA18 *w, Obj_021FFA18 *s);

void func_021FFB04(Work_vF7B0 *w, Obj_vF7B0 *s);

void func_021FFBBC(char *w, int key, int kind, int value, int a, int b, int c);

int func_021FFCB0(Work_021FFCB0 *w, int key);

int func_021FFD9C(char *p, int key);

void func_021FFDB4(Work_vFCB0 *w, int key, u8 cur, u8 target, u8 step, u32 e);

int func_021FFF0C(char *p, int key);

int func_021FFF38(char *p, int key);

int func_021FFF68(Work_021FFF68 *w, int key);

int func_021FFFAC(Work_021FFFAC *w, int key);

void func_021FFFD8(char *w, int key, int flag, int clear);

void func_02200140(Work_02200140 *w, int key1, int key2);

int func_02200218(Work_02200218 *w, int key, int pitch, int pan, int a4, int a5, int a6);

int func_022003C4(char *p, int key);

int func_0220041C(Work_0220041C *w, int key, int n);

void func_02200468(Work_02200468 *w, int key);

int func_02200494(char *p, int key);

void func_022004BC(Work_022004BC *w, int key);

void func_02200654(Work_02200654 *w);

int func_02201AF8(int a, int b, int c, short d, short e, int f, int g);

int func_02201B20(char *p, u32 archiveId, int a, u32 b, int c, int d, s16_02201B20 x, s16_02201B20 y, u32 e, u32 f);

void func_02201CA4(Res_02201B20 *r, int i);

void func_02201CD0(char *o, int idx, int c, s16_02201B20 *p, int s1, int s2, int s3);

void func_02201D5C(char *o, int idx, int c, void *d, int s1, int s2, int s3);

u32 func_02201DA0(char *p, int i, int v);

void func_02201DB4(char *base, int idx, u8 b, u8 c, s8 step, u16 d);

extern const s16_021F6560 FX_SinCosTable_[];

extern const char d_0220AE68[];

extern char d_02209DCC[];

extern const VecFx32_v9814 d_0220ACA0[2];

extern const VecFx32_v9814 d_0220ACE8[];

extern const VecFx32_v9814 d_0220AD00[];

extern const VecFx32_v9814 d_0220AD78[];

extern const VecFx32_v9814 d_0220ADA8[];

extern const VecFx32_v9814 d_0220ADD8[];

extern const VecFx32_v9814 d_0220AE20[];

extern const Vec_021F6560 d_02209E1C, d_02209D90;

extern const Vec_021F6560 d_02209D78, d_02209E04;

extern const Vec_021F6560 d_02209DC0, d_02209D84;

extern const Vec_021F6560 d_02209DA8, d_02209D9C;

extern const Targets d_02209E58;

extern const Targets d_02209E28;

extern const int d_0220AD18[], d_0220AD38[];

extern const int d_0220AD58[];

extern const Vec_021F6560 d_02209E10, d_02209DB4;

extern MtxFx43 g_renderStateDrawParams;

extern MtxFx44 SCREENTEX_ProjectionMatrix;

extern int d_02209DD8[];

#define FX(x) ((int)(((x) > 0) ? (0.5f + (float)((x) << 12)) : ((float)((x) << 12) - 0.5f)))

void *func_021F93F4(void *a, u32 b)
{
    T_021F93F4 *t;
    void *vm;
    int i;

    t = func_02030734(b, 0x2AC, 1, d_0220AE68, 0x27D);
    t->h238 = b;
    t->a = a;
    t->f23c = 1;
    t->f244 = 1;
    for (i = 0; i < 16; i++)
        t->v4c[i] = -1;
    for (i = 0; i < 4; i++)
        t->vcc[i] = -1;
    for (i = 0; i < 6; i++)
        t->e26c[i] = -1;
    vm = VM_Create(b, (const struct ScriptVmParams *)d_02209DCC);
    VM_Init(vm, t);
    return vm;
}

int func_021F9478(void *vm)
{
    int r;
BtlvEffVmWork *t;

    r = VM_Control(vm);
    t = func_02011324(vm);
    if (t->flags.bit.blockedOnTask)
        return 0;
    if (r == 0 && t->scriptBuf != 0) {
        func_021F8198(1, 2);
        if (t->flags.bit.fallbackScript == 0)
            func_021FE410(t, 0x6B000, 0x7F000, 0x14);
        func_020307B0(t->scriptBuf);
        t->scriptBuf = 0;
    }
    return r;
}

/*
 * Tears down the owner's work: func_021F97E4, free, then VM_Delete.
 */
void func_021F94D8(void *a)
{
BtlvEffVmWork *s = func_02011324(a);
    func_021F97E4(a);
    func_020307B0(s);
    VM_Delete(a);
}

void func_021F94F8(void *vm, u32 a1, u32 a2, u16 id, BtlvEffVmParams *q)
{
BtlvEffVmWork *t;
    int off;
    int flag;
    u8 *p;

    t = func_02011324(vm);
    t->scriptBuf = 0;
    func_021F8A10(1);
    if (q != 0)
        t->params = *q;
    else
        MIi_CpuClear16(0, &t->params, 0x10);
    t->attackerPos = a1;
    t->defenderPos = a2;
    t->layoutMode = 1;
    t->effectId = id;
    if (t->effectId >= 0x231 && (u16)(t->effectId + 0xFD9F) <= 1
        && t->lastEffectId == t->effectId && t->lastSlot == a1)
        return;
    t->lastEffectId = t->effectId;
    t->lastSlot = a1;
    if (func_021FEAA0(t->effectId) == 0)
        func_021F8934(0);
    if (t->effectId < 0x231) {
        t->scriptBuf = ARC_TOOL_LoadMember(0x42, id, (u16)((t->heapId & 0x7fff) | 0x8000));
        if (t->effectId != 0x90 && t->effectId != 0x77 && t->effectId != 0x10b)
            func_021F8198(0, 2);
        func_02040588(1, 0);
        func_02040588(2, 0);
        func_02040588(3, 0);
        t->flags.bit.fallbackScript = 0;
        func_021FE410(t, 0x7F000, 0x6B000, 0x14);
    } else {
        t->scriptBuf = ARC_TOOL_LoadMember(0x43, id - 0x231, (u16)((t->heapId & 0x7fff) | 0x8000));
        t->flags.bit.fallbackScript = 1;
        if (id >= 0x256 && (*(volatile u16 *)0x04000052 & 0x1f) == 0)
            func_02040588(1, 0);
    }
    off = 4;
    if (q != 0) {
        if (*(u8 *)t->scriptBuf <= ((u8 *)q)[1])
            ((u8 *)q)[1] = 0;
        off += ((u8 *)q)[1] * 0x38;
    }
    flag = 0;
    if (func_021FFD9C((char *)func_021F8694(), t->attackerPos)) {
        if (((t->effectId == 0xf8 || t->effectId == 0x161) && ((u8 *)q)[1] == 1)
            || t->effectId == 0x90 || t->effectId == 0x77 || t->effectId == 0x10b) {
        } else {
            flag = func_021FFF38((char *)func_021F8694(), t->attackerPos) & 1;
        }
    }
    if (t->effectId == 0x27e)
        t->flags.bit.keepBackground = 1;
    if (t->effectId == 0x291)
        t->flags.bit.keepBackground = 0;
    if (t->effectId == 0x27e && flag) {
        t->pendingScriptBuf = t->scriptBuf;
        t->pendingScriptOffset = off;
        t->scriptBuf = ARC_TOOL_LoadMember(0x43, 0x33, (u16)((t->heapId & 0x7fff) | 0x8000));
        t->flags.bit.fallbackScript = 1;
        t->flags.bit.fallbackPending = 1;
        off = 4;
    } else if (!t->flags.bit.fallbackScript && t->effectId != 0x90 && !t->flags.bit.fallbackPending && flag) {
        t->pendingScriptBuf = t->scriptBuf;
        t->pendingScriptOffset = off;
        t->scriptBuf = ARC_TOOL_LoadMember(0x43, 0x33, (u16)((t->heapId & 0x7fff) | 0x8000));
        t->flags.bit.fallbackScript = 1;
        off = 4;
    }
    p = t->scriptBuf;
    t->scriptVar = 0;
    t->flags.bit.stopSeOnEnd = 0;
    t->typeSource = 8;
    VM_Start(vm, (u8 *)t->scriptBuf + *(int *)(p + off));
}

/*
 * Releases the owner's script buffer (scriptBuf) after func_021FC448.
 */
void func_021F97E4(void *a)
{
BtlvEffVmWork *s = func_02011324(a);

    if (s->scriptBuf != 0) {
        func_021FC448(a, func_02011324(a));
        func_020307B0(s->scriptBuf);
        s->scriptBuf = 0;
    }
}

/*
 * Clears the blockedOnTask flag of the owner's work.
 */
void func_021F9814(void *a)
{
    ((BtlvEffVmWork *)func_02011324(a))->flags.bit.blockedOnTask = 0;
}

/*
 * Returns the fallbackScript flag of the owner's work when scriptBuf is set, else -1.
 */
int func_021F9824(void *a)
{
BtlvEffVmWork *s = (void *)func_02011324(a);
    int r = -1;

    if (s->scriptBuf != 0)
        r = s->flags.bit.fallbackScript;
    return r;
}

void func_021F9844(S9844 *p)
{
    p->b0 = 0;
    p->b1 = 0;
    p->b2 = 0;
    p->b3 = 0;
    p->w1 = 0;
    p->w2 = 0;
    p->h1 = 0;
}

void func_021F9858(void *vm, u32 a, int b, u32 c, int e, u32 f, int g, int h, int d)
{
BtlvEffVmWork *w;
    Job_021F9858 *j;
    w = (void *)func_02011324(vm);
    if (func_021F88E0() == 1)
        return;
    w->flags.bit.stopSeOnEnd = 1;
    if (c == 2)
        c = 0;
    else if (c <= 1) {
        if (c & 1)
            c = 127;
        else
            c = -128;
    } else {
        if (func_021FCF2C((int)vm, c) & 1)
            c = 127;
        else
            c = -128;
    }
    if (g > 255)
        g = 255;
    if (h > 255)
        h = 255;
    if (d == 0) {
        func_021FDB40(a, b, c, e, f, g, h);
        return;
    }
    j = func_02030734((u16)((w->heapId & 0x7fff) | 0x8000), 0x24, 0, d_0220AE68, 0x431);
    j->work = w;
    j->a = a;
    j->b = b;
    j->c = c;
    j->d = d;
    j->e = e;
    j->f = f;
    j->g = g;
    j->h = h;
    w->flags.bit.seVolumeRamp = 1;
    func_021F896C(func_02030DA8(w->owner, func_021FE54C, j, 0), func_021FE580, 1);
}

void func_021F9948(void *vm, u32 a, int mode, int c, int x, int dest, int e, int f, int g, int duration)
{
BtlvEffVmWork *w;
    Job_021F9948 *j;
    float ff;
    int fd;
    w = (void *)func_02011324(vm);
    j = func_02030734((u16)((w->heapId & 0x7fff) | 0x8000), 0x38, 0, d_0220AE68, 0x455);
    j->work = w;
    j->a = a;
    j->mode = mode;
    j->c = c;
    j->x = x;
    j->dest = dest;
    j->e = e;
    j->f = f;
    j->remaining = f;
    j->zero = 0;
    j->g = g;
    j->duration = duration * 2;
    if (mode == 1 && j->duration == 0)
        j->duration = 2;
    j->fx = FX(j->x);
    if (j->f > 0)
        ff = 0.5f + (float)(j->f << 12);
    else
        ff = (float)(j->f << 12) - 0.5f;
    fd = FX(j->dest - j->x);
    j->delta = func_0207C768(fd, (int)ff);
    func_021F896C(func_02030DA8(w->owner, func_021FE594, j, 0), func_021FE690, 1);
    w->flags.bit.sePanRamp = 1;
}

/*
 * Stops every live sound slot of the owner's work (seVoiceIds, -1 = free).
 */
void func_021F9A7C(void *a)
{
BtlvEffVmWork *s = (void *)func_02011324(a);
    int i;

    for (i = 0; i < 6; i++) {
        if (s->seVoiceIds[i] != -1)
            PM_VOICE_StopSlot(s->seVoiceIds[i]);
    }
}

/*
 * Clears lastEffectId and lastSlot of the owner's work.
 */
void func_021F9AA4(void *a)
{
BtlvEffVmWork *s = (void *)func_02011324(a);
    s->lastEffectId = 0;
    s->lastSlot = 0;
}

/*
 * note: d_0220ACA0 holds six vectors but is declared with a short bound. Cases 14, 18 and
 *   19 index past it; MWCC then treats those loads as possibly aliasing A/B and keeps each
 *   load after the preceding store (any bound 1..4 matches; in-bounds models such as [6],
 *   [2][3] or a pair struct hoist the last load above the B.y store).
 */
int func_021F9AB8(void *r, BtlvEffVmWork *c)
{
    VecFx32_v9814 A;
    VecFx32_v9814 B;
    int type;
    int mode;
    int n;
    int s;
    int t;
    int k;
    int v;

    type = VM_GetU32(r);
    mode = VM_GetU32(r);
    n = VM_GetU32(r);
    s = VM_GetU32(r);
    t = VM_GetU32(r);
    if (c->flags.bit.cameraLocked) {
        return c->result;
    }
    if (mode == 13 && c->camVecSaved == 0) {
        mode = 8;
    }
    if (mode != 8 && mode != 15 && mode != 16 && mode != 14 && mode != 17) {
        func_021FDB20(c);
    } else {
        c->flags.bit.cameraOverride = 1;
    }
    switch (mode) {
    case 15:
    case 16:
        k = func_021F8710();
        if (mode == 15) {
            v = c->attackerPos;
        } else {
            v = c->defenderPos;
        }
        switch (k) {
        case 0:
            return c->result;
        case 1:
        case 2:
            switch (v) {
            case 2:
                mode = 2;
                break;
            case 3:
                mode = 8;
                if (k != 1) {
                    mode = 18;
                }
                break;
            case 4:
                mode = 4;
                if (k != 1) {
                    mode = 8;
                }
                break;
            case 5:
                mode = 8;
                break;
            case 6:
                mode = 8;
                if (k != 1) {
                    mode = 6;
                }
                break;
            case 7:
            default:
                return c->result;
            }
            break;
        case 3:
            if (v == 4 || v == 6) {
                mode = 19;
            }
            break;
        }
        break;
    case 14:
        k = func_021F8710();
        if (k == 0 || k == 3) {
            return c->result;
        }
        break;
    case 20:
        k = func_021F8710();
        if (k == 0 || k == 3) {
            func_021FF16C((Work_021FF16C *)((void *)func_021F8694()));
            return c->result;
        }
        mode = 14;
        break;
    case 21:
        k = func_021F8710();
        if (k == 0 || k == 3) {
            mode = c->attackerPos;
        } else if (c->attackerPos & 1) {
            mode = 1;
        } else {
            mode = 14;
        }
        break;
    case 17:
        mode = 8;
        break;
    case 9:
    case 10:
        k = func_021F8710();
        mode = c->attackerPos;
        if (k == 3 && (mode == 4 || mode == 6)) {
            mode = 19;
        }
        break;
    case 11:
    case 12:
        switch (c->params.kind) {
        case 0:
        case 1:
        case 2:
        case 3:
            mode = c->defenderPos;
            if (mode == 0xff) {
                mode = (c->attackerPos & 1) ^ 1;
            }
            break;
        case 5:
        case 7:
        case 9:
        case 13:
            mode = c->defenderPos;
            if (mode != 0xff) {
                break;
            }
        case 11:
            mode = (c->attackerPos & 1) ^ 1;
            break;
        case 6:
        case 12:
            mode = c->attackerPos & 1;
            break;
        case 4:
        case 8:
        case 10:
            k = func_021F8710();
            if (k == 0 || k == 3) {
                mode = (c->attackerPos & 1) ^ 1;
            } else {
                mode = 14;
            }
            break;
        }
        break;
    }
    switch (mode) {
    case 0:
    case 1:
        A.x = d_0220ACE8[mode].x;
        A.y = d_0220ACE8[mode].y;
        A.z = d_0220ACE8[mode].z;
        B.x = d_0220AD00[mode].x;
        B.y = d_0220AD00[mode].y;
        B.z = d_0220AD00[mode].z;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        k = func_021F8710();
        if (k == 3) {
            A.x = d_0220ACE8[mode - 2].x;
            A.y = d_0220ACE8[mode - 2].y;
            A.z = d_0220ACE8[mode - 2].z;
            B.x = d_0220AD00[mode - 2].x;
            B.y = d_0220AD00[mode - 2].y;
            B.z = d_0220AD00[mode - 2].z;
        } else if (k == 1) {
            A.x = d_0220AD78[mode - 2].x;
            A.y = d_0220AD78[mode - 2].y;
            A.z = d_0220AD78[mode - 2].z;
            B.x = d_0220ADA8[mode - 2].x;
            B.y = d_0220ADA8[mode - 2].y;
            B.z = d_0220ADA8[mode - 2].z;
        } else {
            A.x = d_0220ADD8[mode - 2].x;
            A.y = d_0220ADD8[mode - 2].y;
            A.z = d_0220ADD8[mode - 2].z;
            B.x = d_0220AE20[mode - 2].x;
            B.y = d_0220AE20[mode - 2].y;
            B.z = d_0220AE20[mode - 2].z;
        }
        break;
    case 6:
    case 7:
        A.x = d_0220ADD8[mode - 2].x;
        A.y = d_0220ADD8[mode - 2].y;
        A.z = d_0220ADD8[mode - 2].z;
        B.x = d_0220AE20[mode - 2].x;
        B.y = d_0220AE20[mode - 2].y;
        B.z = d_0220AE20[mode - 2].z;
        break;
    case 13:
        A.x = c->camEye.x;
        A.y = c->camEye.y;
        A.z = c->camEye.z;
        B.x = c->camTarget.x;
        B.y = c->camTarget.y;
        B.z = c->camTarget.z;
        break;
    case 14:
        A.x = d_0220ACA0[0].x;
        A.y = d_0220ACA0[0].y;
        A.z = d_0220ACA0[0].z;
        B.x = d_0220ACA0[2].x;
        B.y = d_0220ACA0[2].y;
        B.z = d_0220ACA0[2].z;
        if (c->flags.bit.cameraOverride) {
            func_021FE9F0(0xa66, 0xb9a, n, s, 0);
            c->flags.bit.cameraOffset = 1;
        }
        break;
    case 19:
        A.x = d_0220ACA0[3].x;
        A.y = d_0220ACA0[3].y;
        A.z = d_0220ACA0[3].z;
        B.x = d_0220ACA0[1].x;
        B.y = d_0220ACA0[1].y;
        B.z = d_0220ACA0[1].z;
        if (c->flags.bit.cameraOverride) {
            func_021FE9F0(0xa66, 0xb9a, n, s, 0);
            c->flags.bit.cameraOffset = 1;
        }
        break;
    case 18:
        A.x = d_0220ACA0[5].x;
        A.y = d_0220ACA0[5].y;
        A.z = d_0220ACA0[5].z;
        B.x = d_0220ACA0[4].x;
        B.y = d_0220ACA0[4].y;
        B.z = d_0220ACA0[4].z;
        break;
    default:
        func_021F7208((VecFx32_v6560 *)&A, (VecFx32_v6560 *)&B);
        if (c->flags.bit.cameraOffset) {
            func_021FE9F0(0x1000, 0x1000, n, s, 0);
            c->flags.bit.cameraOffset = 0;
        }
        break;
    }
    switch (type) {
    case 0:
        func_021F6EDC((int *)func_021F8684(), (int *)(&A), (int *)(&B));
        break;
    case 1:
        func_021F6F48((Cam_021F6F48 *)(func_021F8684()), (VecFx32_v6560 *)&A, (VecFx32_v6560 *)&B, n, s, t);
        break;
    }
    return c->result;
}

int func_021F9EFC(void *r, BtlvEffVmWork *c)
{
    int A[3];
    int B[3];
    int C[3];
    int D[3];
    int n;
    int s;
    int t;
    int type;

    type = VM_GetU32(r);
    A[0] = VM_GetU32(r);
    A[1] = VM_GetU32(r);
    A[2] = VM_GetU32(r);
    B[0] = VM_GetU32(r);
    B[1] = VM_GetU32(r);
    B[2] = VM_GetU32(r);
    n = VM_GetU32(r);
    s = VM_GetU32(r);
    t = VM_GetU32(r);
    func_021FDB20(c);
    switch (type) {
    case 0:
        func_021F6EDC((int *)func_021F8684(), A, B);
        break;
    case 1:
        func_021F6F48((Cam_021F6F48 *)(func_021F8684()), (VecFx32_v6560 *)((VecFx32_v9814 *)A), (VecFx32_v6560 *)((VecFx32_v9814 *)B), n, s, t);
        break;
    case 2:
        func_021F70F0((void **)func_021F8684(), C, (int)D);
        func_0207C9D0(C, A, A);
        func_0207C9D0(D, B, B);
        func_021F6F48((Cam_021F6F48 *)(func_021F8684()), (VecFx32_v6560 *)((VecFx32_v9814 *)A), (VecFx32_v6560 *)((VecFx32_v9814 *)B), n, s, t);
        break;
    }
    return c->result;
}

int func_021F9FC0(void *r, BtlvEffVmWork *c)
{
    int E[3];
    int F[3];
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int type;

    type = VM_GetU32(r);
    v1 = VM_GetU32(r);
    v2 = VM_GetU32(r);
    v3 = VM_GetU32(r);
    v4 = VM_GetU32(r);
    v5 = VM_GetU32(r);
    func_021FDB20(c);
    switch (type) {
    case 0:
        func_021F6F20((Obj_021F6F20 *)(func_021F8684()), v1, v2);
        break;
    case 1:
        func_021F7108((int *)func_021F8684(), v1, v2, E, F);
        func_021F6F48((Cam_021F6F48 *)(func_021F8684()), (VecFx32_v6560 *)((VecFx32_v9814 *)E), (VecFx32_v6560 *)((VecFx32_v9814 *)F), v3, v4, v5);
        break;
    }
    return c->result;
}

int func_021FA048(void *r, BtlvEffVmWork *c)
{
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;

    v0 = VM_GetU32(r);
    v1 = VM_GetU32(r);
    v2 = VM_GetU32(r);
    v3 = VM_GetU32(r);
    v4 = VM_GetU32(r);
    v5 = VM_GetU32(r);
    func_021F7000((Cam_021F7000 *)(func_021F8684()), v0, v1, v2, v3, v4, v5);
    return c->result;
}

int func_021FA09C(void *a, BtlvEffVmWork *s)
{
    int buf[8];
    int x;
    int n;
    int i;

    x = VM_GetU32(a);
    if (VM_GetU32(a) == 0) {
        s->layoutMode = x;
        func_021FDB20(s);
    } else {
        n = func_021FCA04(s, 14, buf);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (x == 1)
                    func_021FF228((Work_021FF228 *)((void *)func_021F8694()), buf[i]);
                else
                    func_021FF1F4((Work_vE254 *)((void *)func_021F8694()), buf[i]);
            }
        }
    }
    return s->result;
}

int func_021FA108(int a, BtlvEffVmWork *b)
{
    b->camVecSaved = 1;
    func_021F70F0((void **)func_021F8684(), &b->camEye, (int)&b->camTarget);
    return b->result;
}

/*
 * witness: arm9 PARTICLE_SetupSystemNoHandlers filed as src/matched/arm9/PARTICLE_SetupSystemNoHandlers.c.
 * witness: func_021FC9F4 filed as src/matched/ov/ov094_func_021FC9F4.c.
 */
int func_021FA12C(void *a, BtlvEffVmWork *s)
{
    int slot;
    int key;
    void *buffer;
    void *resource;
    Callback *cb;
    int line;

    key = func_021FE38C(s, VM_GetU32(a));
    if (func_021FD15C(s, key, &slot) == 1) {
        line = 0x715;
        buffer = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x4800, 0, d_0220AE68, line);
        resource = (void *)PARTICLE_LoadArchiveMember(6, key, (u16)((s->heapId & 0x7fff) | 0x8000));
        if (buffer != 0 && resource != 0) {
            s->emitters[slot] = PARTICLE_CreateSystem((u32)buffer, 0x4800, 0, 5, 6, 0x36, (u16)((s->heapId & 0x7fff) | 0x8000));
            if (s->emitters[slot] != 0) {
                PARTICLE_SetupSystemNoHandlers(s->emitters[slot], resource);
                line += 10;
                cb = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 12, 0, d_0220AE68, line);
                cb->state = s;
                cb->emitter = s->emitters[slot];
                cb->resource = resource;
                s->flags.bit.particleSysActive = 1;
                func_021F896C(func_020056A0(func_021FE9BC, cb, 0), 0, 1);
                VM_SetWait(a, (int)func_021FC9F4);
                func_021FD19C(s, slot, resource);
            }
        }
        if (s->emitters[slot] == 0) {
            if (buffer != 0)
                func_020307B0(buffer);
            if (resource != 0)
                func_020307B0(resource);
            s->voiceIds[slot] = -1;
        }
    }
    return 1;
}

int func_021FA288(void *a, BtlvEffVmWork *s)
{
    int *p;
    int slot;
    int arg;

    p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x74a);
    slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    arg = VM_GetU32(a);
    p[0] = (int)a;
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[6] = VM_GetU32(a);
    VM_GetU32(a);
    p[17] = VM_GetU32(a);
    p[18] = VM_GetU32(a);
    p[19] = VM_GetU32(a);
    p[20] = VM_GetU32(a);
    if (p[2] == 8)
        p[2] = p[1];
    if (slot != 16)
        func_021FDD60(s, (Rec_021FDD60 *)p, slot, arg);
    func_020307B0(p);
    return s->result;
}

int func_021FA358(void *a, BtlvEffVmWork *s)
{
    int *p;
    int slot;
    int arg;
    int result;

    p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x77d);
    slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    arg = VM_GetU32(a);
    p[0] = (int)a;
    p[1] = 8;
    p[2] = 8;
    p[10] = VM_GetU32(a);
    p[11] = VM_GetU32(a);
    p[12] = VM_GetU32(a);
    p[13] = VM_GetU32(a);
    p[14] = VM_GetU32(a);
    p[15] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[6] = VM_GetU32(a);
    VM_GetU32(a);
    p[17] = VM_GetU32(a);
    p[18] = VM_GetU32(a);
    p[19] = VM_GetU32(a);
    p[20] = VM_GetU32(a);
    if (slot != 16) {
        result = PARTICLE_StartEffectWithCallback((int *)s->emitters[slot], arg, (int)func_021FD1CC, (int)p);
        if (result == -1)
            func_020307B0(p);
    } else {
        func_020307B0(p);
    }
    return s->result;
}

/*
 * witness: arm9 BUTTON_MAN_GetBlock filed as src/matched/arm9/BUTTON_MAN_GetBlock.c.
 */
int func_021FA458(void *a, BtlvEffVmWork *s)
{
    Desc_021F6560 desc;
    int *p;
    int slot;
    int arg;

    p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x7b6);
    slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    arg = VM_GetU32(a);
    p[0] = (int)a;
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = VM_GetU32(a);
    p[4] = VM_GetU32(a);
    p[5] = VM_GetU32(a);
    p[17] = VM_GetU32(a);
    p[18] = VM_GetU32(a);
    p[19] = VM_GetU32(a);
    p[20] = VM_GetU32(a);
    p[16] = 1;
    if (p[1] == 13) {
        p[1] = 9;
        p[16] = 2;
    }
    if (p[2] == 8)
        p[2] = p[1];
    if (slot != 16) {
        Vec_021F6560 zero = {0, 0, 0};
        Vec_021F6560 v1;
        Vec_021F6560 v2;
        v1 = d_02209E1C;
        v2 = d_02209D90;
        desc.v[0] = 2;
        desc.v[1] = 0x3000;
        desc.v[2] = 0xffffd000;
        desc.v[3] = 0xffffc000;
        desc.v[4] = 0x4000;
        desc.v[5] = 0x1000;
        desc.v[6] = 0x200000;
        desc.v[7] = 0x1000;
        if (BUTTON_MAN_GetBlock(s->emitters[slot]) == 0)
            PARTICLE_InitCamera(s->emitters[slot], (struct Src648 *)(&desc), 0x2000, (int *)(&zero), (int *)(&v1), (int *)(&v2), (u16)((s->heapId & 0x7fff) | 0x8000));
        func_021FDD60(s, (Rec_021FDD60 *)p, slot, arg);
    }
    func_020307B0(p);
    return s->result;
}

int func_021FA5D0(void *a, BtlvEffVmWork *s)
{
    Desc_021F6560 desc;
    int *p;
    int slot;
    int count;
    int arg;
    int i;

    p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x7ff);
    slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    count = func_021FD1C0(s, slot);
    p[0] = (int)a;
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[6] = VM_GetU32(a);
    arg = VM_GetU32(a);
    p[17] = VM_GetU32(a);
    p[18] = VM_GetU32(a);
    p[19] = VM_GetU32(a);
    p[20] = VM_GetU32(a);
    if (slot != 16) {
        if (arg != 0) {
            Vec_021F6560 zero = {0, 0, 0};
            Vec_021F6560 v1;
            Vec_021F6560 v2;
            v1 = d_02209D78;
            v2 = d_02209E04;
            desc.v[0] = 2;
            desc.v[1] = 0x3000;
            desc.v[2] = 0xffffd000;
            desc.v[3] = 0xffffc000;
            desc.v[4] = 0x4000;
            desc.v[5] = 0x1000;
            desc.v[6] = 0x200000;
            desc.v[7] = 0x1000;
            if (BUTTON_MAN_GetBlock(s->emitters[slot]) == 0)
                PARTICLE_InitCamera(s->emitters[slot], (struct Src648 *)(&desc), 0x2000, (int *)(&zero), (int *)(&v1), (int *)(&v2), (u16)((s->heapId & 0x7fff) | 0x8000));
            p[16] = 2;
        }
        if (p[2] == 8)
            p[2] = p[1];
        for (i = 0; i < count; i++)
            func_021FDD60(s, (Rec_021FDD60 *)p, slot, i);
    }
    func_020307B0(p);
    return s->result;
}

int func_021FA758(void *a, BtlvEffVmWork *s)
{
    int slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));

    if (slot != 16) {
        void **e = s->emitters + slot;
        func_021FDB08(*e);
        *e = 0;
        s->voiceIds[slot] = -1;
    }
    return s->result;
}

int func_021FA794(void *a, BtlvEffVmWork *s)
{
    int *p;
    int slot;
    int arg;

    p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x868);
    slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    arg = VM_GetU32(a);
    p[0] = (int)a;
    p[8] = VM_GetU32(a);
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[9] = VM_GetU32(a);
    p[7] = VM_GetU32(a);
    p[17] = 0x1000;
    p[18] = VM_GetU32(a);
    p[19] = 0x1000;
    p[20] = VM_GetU32(a);
    p[21] = VM_GetU32(a);
    if (p[21] == 0)
        p[21] = 1;
    if (slot != 16) {
        if (PARTICLE_StartEffectWithCallback((int *)s->emitters[slot], arg, (int)func_021FD1CC, (int)p) == -1)
            func_020307B0(p);
    } else {
        func_020307B0(p);
    }
    return s->result;
}

int func_021FA884(void *a, BtlvEffVmWork *s)
{
    int *p;
    int idx;
    int x;
    p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x8a2);
    idx = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    x = VM_GetU32(a);
    p[0] = (int)a;
    p[8] = VM_GetU32(a);
    p[1] = 8;
    p[10] = VM_GetU32(a);
    p[11] = VM_GetU32(a);
    p[12] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[9] = VM_GetU32(a);
    p[7] = VM_GetU32(a);
    p[17] = 0x1000;
    p[18] = VM_GetU32(a);
    p[19] = 0x1000;
    p[20] = VM_GetU32(a);
    p[21] = VM_GetU32(a);
    if (p[21] == 0) p[21] = 1;
    if (idx != 16) {
        if (PARTICLE_StartEffectWithCallback((int *)s->emitters[idx], x, (int)func_021FD1CC, (int)p) == -1) {
            func_020307B0(p);
        }
    } else {
        func_020307B0(p);
    }
    return s->result;
}

int func_021FA988(void *a, BtlvEffVmWork *s)
{
    Desc_021F6560 desc;
    int *p;
    int idx;
    int x;
    p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x8e0);
    idx = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    x = VM_GetU32(a);
    p[0] = (int)a;
    p[8] = VM_GetU32(a);
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[9] = VM_GetU32(a);
    p[7] = VM_GetU32(a);
    p[17] = 0xc00;
    p[18] = VM_GetU32(a);
    p[19] = 0xc00;
    p[20] = VM_GetU32(a);
    p[21] = VM_GetU32(a);
    p[16] = 3;
    if (p[21] == 0) p[21] = 1;
    if (idx != 16) {
        Vec_021F6560 zero = {0, 0, 0};
        Vec_021F6560 v1;
        Vec_021F6560 v2;
        v1 = d_02209DC0;
        v2 = d_02209D84;
        desc.v[0] = 2;
        desc.v[1] = 0x3000;
        desc.v[2] = 0xffffd000;
        desc.v[3] = 0xffffc000;
        desc.v[4] = 0x4000;
        desc.v[5] = 0x1000;
        desc.v[6] = 0x200000;
        desc.v[7] = 0x1000;
        if (BUTTON_MAN_GetBlock(s->emitters[idx]) == 0)
            PARTICLE_InitCamera((struct Dst648 *)(s->emitters[idx]), (struct Src648 *)&desc, 0x2000, (int *)&zero, (int *)&v1, (int *)&v2, (s->heapId & 0x7fff) | 0x8000);
        if (PARTICLE_StartEffectWithCallback((int *)s->emitters[idx], x, (int)func_021FD1CC, (int)p) == -1) {
            func_020307B0(p);
        }
    } else {
        func_020307B0(p);
    }
    return s->result;
}

/*
 * witness: arm9 BUTTON_MAN_GetBlock filed as src/matched/arm9/BUTTON_MAN_GetBlock.c.
 * trailing: 021FAC94 and 021FACA0 are tail-call stubs; not filed while ARM9 blocks.
 */
int func_021FAB0C(void *a, BtlvEffVmWork *s)
{
    Desc_021F6560 desc;
    int *p;
    int idx;
    int x;
    p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x92d);
    idx = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    x = VM_GetU32(a);
    p[0] = (int)a;
    p[8] = VM_GetU32(a);
    p[1] = 8;
    p[10] = VM_GetU32(a);
    p[11] = VM_GetU32(a);
    p[12] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[9] = VM_GetU32(a);
    p[7] = VM_GetU32(a);
    p[17] = 0x1000;
    p[18] = VM_GetU32(a);
    p[20] = VM_GetU32(a);
    p[19] = VM_GetU32(a);
    p[16] = 3;
    if (idx != 16) {
        Vec_021F6560 zero = {0, 0, 0};
        Vec_021F6560 v1;
        Vec_021F6560 v2;
        v1 = d_02209DA8;
        v2 = d_02209D9C;
        desc.v[0] = 2;
        desc.v[1] = 0x3000;
        desc.v[2] = 0xffffd000;
        desc.v[3] = 0xffffc000;
        desc.v[4] = 0x4000;
        desc.v[5] = 0x1000;
        desc.v[6] = 0x200000;
        desc.v[7] = 0x1000;
        if (BUTTON_MAN_GetBlock(s->emitters[idx]) == 0)
            PARTICLE_InitCamera((struct Dst648 *)(s->emitters[idx]), (struct Src648 *)&desc, 0x2000, (int *)&zero, (int *)&v1, (int *)&v2, (s->heapId & 0x7fff) | 0x8000);
        if (PARTICLE_StartEffectWithCallback((int *)s->emitters[idx], x, (int)func_021FD1CC, (int)p) == -1) {
            func_020307B0(p);
        }
    } else {
        func_020307B0(p);
    }
    return s->result;
}

/*
 * Tail call to func_021FDFA0 with mode 0.
 */
void func_021FAC94(void *a, void *b)
{
    func_021FDFA0(a, b, 0);
}

/*
 * Tail call to func_021FDFA0 with mode 1.
 */
void func_021FACA0(void *a, void *b)
{
    func_021FDFA0(a, b, 1);
}

int func_021FACAC(void *a, BtlvEffVmWork *s)
{
    int buf[8];
    int t[3];
    int n;
    int x;
    int r;
    int u;
    int v;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), buf);
    x = VM_GetU32(a);
    t[0] = VM_GetU32(a);
    t[1] = VM_GetU32(a);
    i = 0;
    t[2] = 0;
    r = VM_GetU32(a);
    u = VM_GetU32(a);
    v = VM_GetU32(a);
    if (n != 0) {
        for (; i < n; i++)
            func_021FF4C0((char *)((void *)func_021F8694()), buf[i], x, (Vec_021F6560 *)t, r, u, v);
    }
    return s->result;
}

int func_021FAD2C(void *a, BtlvEffVmWork *s)
{
    Req_021FAD2C q;
    int buf[8];
    int n;
    int i;

    n = func_021FCA04(s, (int)VM_GetU32(a), buf);
    q.f8 = (int)VM_GetU32(a);
    q.fc = (int)VM_GetU32(a);
    q.f10 = (int)VM_GetU32(a);
    q.f14 = (int)VM_GetU32(a);
    q.f18 = (int)VM_GetU32(a) >> 12;
    q.f1c = (int)VM_GetU32(a) >> 12;
    q.f20 = (int)VM_GetU32(a) >> 12;
    q.f24 = (int)VM_GetU32(a);
    if (n != 0 && q.f20 != 0) {
        for (i = 0; i < n; i++) {
            q.item = buf[i];
            func_021FFA18((Work_021FFA18 *)((void *)func_021F8694()), (Obj_021FFA18 *)&q);
        }
    }
    return s->result;
}

int func_021FADC0(void *a, BtlvEffVmWork *s)
{
    Req_021FADC0 q;
    int buf[8];
    int n;
    int p;
    int r;
    int t;
    int u;
    int v;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), buf);
    p = VM_GetU32(a);
    r = VM_GetU32(a);
    t = VM_GetU32(a);
    u = VM_GetU32(a);
    v = VM_GetU32(a);
    q.f18 = r;
    q.f24 = v;
    q.f14 = p;
    q.f20 = u;
    q.f1c = func_0207C768(t - r, v << 12);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            q.item = buf[i];
            func_021FFB04((Work_vF7B0 *)((void *)func_021F8694()), (Obj_vF7B0 *)&q);
        }
    }
    return s->result;
}

int func_021FAE48(void *a, BtlvEffVmWork *s)
{
    int t[3];
    int buf[8];
    int n;
    int x;
    int r;
    int u;
    int v;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), buf);
    x = VM_GetU32(a);
    t[0] = VM_GetU32(a);
    t[1] = VM_GetU32(a);
    t[2] = 0x1000;
    r = VM_GetU32(a);
    u = VM_GetU32(a);
    v = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF5B0((Work_021FF5B0 *)((void *)func_021F8694()), buf[i], x, (VecFx32_vF5B0 *)t, r, u, v);
    }
    return s->result;
}

int func_021FAECC(void *a, BtlvEffVmWork *s)
{
    int buf[8];
    int t[3];
    int n;
    int x;
    int r;
    int u;
    int v;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), buf);
    x = VM_GetU32(a);
    i = 0;
    t[0] = 0;
    t[1] = 0;
    t[2] = VM_GetU32(a);
    r = VM_GetU32(a);
    u = VM_GetU32(a);
    v = VM_GetU32(a);
    if (n != 0) {
        for (; i < n; i++)
            func_021FF730((Work_vF5B0 *)((void *)func_021F8694()), buf[i], x, (VecFx32_vF5B0 *)t, r, u, v);
    }
    return s->result;
}

int func_021FAF44(void *a, BtlvEffVmWork *s)
{
    int buf[8];
    int n;
    int p;
    int q;
    int r;
    int t;
    int u;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), buf);
    p = VM_GetU32(a);
    q = VM_GetU32(a);
    r = VM_GetU32(a);
    t = VM_GetU32(a);
    u = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF924((char *)func_021F8694(), buf[i], p, q, r, t, u);
    }
    return s->result;
}

int func_021FAFBC(void *a, BtlvEffVmWork *s)
{
    int buf[8];
    int n;
    int p;
    int q;
    int r;
    int t;
    int u;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), buf);
    p = VM_GetU32(a);
    q = VM_GetU32(a);
    r = VM_GetU32(a);
    t = VM_GetU32(a);
    u = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FFBBC((char *)func_021F8694(), buf[i], p, q, r, t, u);
    }
    return s->result;
}

int func_021FB034(void *a, BtlvEffVmWork *s)
{
    int buf[8];
    int n;
    int x;
    int y;
    int z;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), buf);
    x = VM_GetU32(a);
    y = VM_GetU32(a);
    z = VM_GetU32(a);
    if (n != 0) {
        if (z == 0)
            z = 1;
        for (i = 0; i < n; i++)
            func_021FF870((Work_021FF870 *)((void *)func_021F8694()), buf[i], x, y, z);
    }
    return s->result;
}

int func_021FB09C(void *a, BtlvEffVmWork *s)
{
    int buf[8];
    int n;
    int v;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), buf);
    v = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF304((Work_021FF228 *)((void *)func_021F8694()), buf[i], v);
    }
    return s->result;
}

int func_021FB0E8(void *a, BtlvEffVmWork *s)
{
    int buf[8];
    int n;
    int p;
    int q;
    int r;
    int t;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), buf);
    p = VM_GetU32(a);
    q = VM_GetU32(a);
    r = VM_GetU32(a);
    t = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FFDB4((Work_vFCB0 *)((void *)func_021F8694()), buf[i], p, q, r, t);
    }
    return s->result;
}

int func_021FB168(void *a, BtlvEffVmWork *s)
{
    int buf[8];
    int n;
    int v;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), buf);
    v = VM_GetU32(a);
    if (v == 5) {
        func_02200654((Work_02200654 *)((void *)func_021F8694()));
    } else if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF374((Work_vF228 *)((void *)func_021F8694()), buf[i], v);
    }
    return s->result;
}

int func_021FB1C4(struct Cursor *a, BtlvEffVmWork *b)
{
    int buf[8];
    int n;
    int i;
    int v;

    n = func_021FCA04(b, VM_GetU32(a), buf);
    v = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF470((char *)((void *)func_021F8694()), buf[i], v);
    }
    return b->result;
}

int func_021FB214(struct Cursor *a, BtlvEffVmWork *b)
{
    int arr[3];
    int buf[8];
    int n;
    int i;
    int t1, t4, t5, t6;

    n = func_021FCA04(b, VM_GetU32(a), buf);
    t1 = VM_GetU32(a);
    arr[0] = VM_GetU32(a);
    arr[1] = VM_GetU32(a);
    arr[2] = 0x1000;
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    t6 = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF6B0((Work_vF5B0 *)((void *)func_021F8694()), buf[i], t1, (VecFx32_vF5B0 *)arr, t4, t5, t6);
    }
    return b->result;
}

/*
 * Script command: runs func_021F7F04 on each id listed by func_021FCA04.
 */
int func_021FB298(void *a, BtlvEffVmWork *s)
{
    int ids[8];
    int n;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), ids);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021F7F04(ids[i]);
    }
    return s->result;
}

int func_021FB2D0(struct Cursor *a, BtlvEffVmWork *b)
{
    int t0, t1, t2, t3, t4;

    t0 = VM_GetU32(a);
    t1 = func_021FCF2C((int)a, VM_GetU32(a));
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    if (t0 == -1)
        t0 = b->scriptVar;
    func_021F7F58(t0, t1, t2, t3, t4);
    return b->result;
}

int func_021FB328(struct Cursor *a, BtlvEffVmWork *b)
{
    int arr[3];
    int t1;
    int t0;
    int t5, t6, t7;

    t0 = func_021F84D0(VM_GetU32(a));
    t1 = VM_GetU32(a);
    arr[0] = VM_GetU32(a);
    arr[1] = VM_GetU32(a);
    arr[2] = VM_GetU32(a);
    t5 = VM_GetU32(a);
    t6 = VM_GetU32(a);
    t7 = VM_GetU32(a);
    func_021FF4C0((char *)((void *)func_021F8694()), t0, t1, (Vec_021F6560 *)arr, t5, t6, t7);
    return b->result;
}

/*
 * Script command: when func_0220041C(x, y) reports 1, calls func_02200468(x).
 */
int func_021FB390(void *a, BtlvEffVmWork *s)
{
    int x = VM_GetU32(a);
    int y = VM_GetU32(a);

    if (func_0220041C((Work_0220041C *)((void *)func_021F8694()), x, y) == 1)
        func_02200468((Work_02200468 *)((void *)func_021F8694()), x);
    return s->result;
}

/*
 * Script command: passes one argument to func_021F8010.
 */
int func_021FB3C8(void *a, BtlvEffVmWork *s)
{
    func_021F8010(VM_GetU32(a));
    return s->result;
}

int func_021FB3DC(struct Cursor *a, BtlvEffVmWork *b)
{
    int t;

    t = VM_GetU32(a);
    func_0204047C(3, 1);
    func_02049624((void *)0x5f, (void *)(t + 1), (void *)3, 0, 0, 0, (b->heapId & 0x7fff) | 0x8000);
    func_0204989C(0x5f, t, 3, 0, 0, 0, (b->heapId & 0x7fff) | 0x8000);
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)func_021F86E0(), (int)0x5f, (int)(t + 2), (u16)((b->heapId & 0x7fff) | 0x8000), (int)0, (int)0, (int)0x80, (int)0);
    b->bg3ScrollX = func_020407E8(3);
    b->bg3ScrollY = func_02040804(3);
    BTLV_BG_SetScroll(func_021F8700(), 0, 0);
    b->flags.bit.gfxReloadPending = 1;
    return b->result;
}

int func_021FB49C(struct Cursor *a, BtlvEffVmWork *b)
{
    int t0, t1, t2, t3, t4, t5, v;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    v = func_021FCF2C((int)a, 14);
    BTLV_BG_StartScroll(func_021F8700(), v, t0, t1, t2, t3, t4, t5);
    return b->result;
}

/*
 * Script command: no-op that skips 4 arguments.
 */
int func_021FB500(void *a, BtlvEffVmWork *s)
{
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    return s->result;
}

/*
 * Script command: no-op that skips 5 arguments.
 */
int func_021FB524(void *a, BtlvEffVmWork *s)
{
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    return s->result;
}

/*
 * Script command: func_0204047C(3, arg) and sets the gfxReloadPending flag.
 */
int func_021FB550(void *a, BtlvEffVmWork *s)
{
    func_0204047C(3, (unsigned char)VM_GetU32(a));
    s->flags.bit.gfxReloadPending = 1;
    return s->result;
}

int func_021FB574(struct Cursor *a, BtlvEffVmWork *b)
{
    int t2;

    VM_GetU32(a);
    VM_GetU32(a);
    t2 = VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    if (t2 == 0x1f)
        func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
    else
        func_0207D63C(0x04000050, 10, 0x35, 0x1f, t2);
    b->flags.bit.blendActive = 1;
    return b->result;
}

int func_021FB5D4(struct Cursor *a, BtlvEffVmWork *b)
{
    int t0, t1, t2, t3, t4;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    func_021F8298(t0, t1, t2, t3, t4);
    return b->result;
}

/*
 * Script command: passes two arguments to func_021F839C.
 */
int func_021FB624(void *a, BtlvEffVmWork *s)
{
    int x = VM_GetU32(a);
    func_021F839C(x, VM_GetU32(a));
    return s->result;
}

int func_021FB648(struct Cursor *a, BtlvEffVmWork *b)
{
    int *p;

    p = func_02030734((u16)((b->heapId & 0x7fff) | 0x8000), 0x28, 1, d_0220AE68, 0xd88);
    p[0] = (int)b;
    p[2] = VM_GetU32(a);
    p[3] = VM_GetU32(a);
    p[4] = VM_GetU32(a);
    p[5] = VM_GetU32(a);
    p[6] = VM_GetU32(a);
    p[8] = VM_GetU32(a);
    p[9] = VM_GetU32(a);
    func_02040588(1, 0);
    func_02040588(2, 0);
    func_021F896C((void *)func_02030DA8((void *)b->owner, func_021FE79C, p, 0), func_021FE8AC, 1);
    b->flags.bit.bgFadeActive = 1;
    return b->result;
}

/*
 * (pt is 3 words: the third is unused padding that sets the 0x30 frame)
 */
int func_021FB6F4(struct Cursor *a, BtlvEffVmWork *b)
{
    int pt[3];
    int o1, o2;
    int t0, t1, t2, t3, t4, t5, t6;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = func_021FCF2C((int)a, VM_GetU32(a));
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    t6 = VM_GetU32(a);
    func_021FF3F4((void *)func_021F8694(), pt, t2);
    pt[0] += t3;
    pt[1] += t4;
    func_0206DF3C(pt, &o1, &o2);
    b->resources[t0] =
        func_02201AF8(func_021F86F0(), 0x5f, t1, o1, o2, t5, t6);
    return b->result;
}

int func_021FB790(struct Cursor *a, BtlvEffVmWork *b)
{
    s16_021FA758 arr[2];
    int t0, t1, t3, t4, t5;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    arr[0] = VM_GetU32(a);
    arr[1] = VM_GetU32(a);
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    func_02201CD0((char *)func_021F86F0(), b->resources[t0], t1, (s16_02201B20 *)((s16_021FA758 *)arr), t3, t4, t5);
    return b->result;
}

int func_021FB7F8(struct Cursor *a, BtlvEffVmWork *b)
{
    int arr[3];
    int t0, t1, t3, t4, t5;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    arr[0] = VM_GetU32(a);
    arr[1] = VM_GetU32(a);
    arr[2] = 0x1000;
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    func_02201D5C((char *)func_021F86F0(), b->resources[t0], t1, arr, t3, t4, t5);
    return b->result;
}

/*
 * Script command: passes slot arg of the table at 0xcc and a value to func_02201DA0.
 */
int func_021FB864(void *a, BtlvEffVmWork *s)
{
    int i = VM_GetU32(a);
    int x = VM_GetU32(a);

    func_02201DA0((char *)func_021F86F0(), s->resources[i], x);
    return s->result;
}

int func_021FB894(struct Cursor *a, BtlvEffVmWork *s)
{
    int v0 = VM_GetU32(a);
    int v1 = VM_GetU32(a);
    int v2 = VM_GetU32(a);
    int v3 = VM_GetU32(a);
    int v4 = VM_GetU32(a);

    func_02201DB4((char *)func_021F86F0(), s->resources[v0], v1, v2, v3, v4);
    return s->result;
}

/*
 * Script command: releases slot arg of the table at 0xcc and marks it free.
 */
int func_021FB8F4(void *a, BtlvEffVmWork *s)
{
    int *tab = s->resources;
    int i = VM_GetU32(a);

    func_02201CA4((Res_02201B20 *)((struct Res *)func_021F86F0()), tab[i]);
    tab[i] = -1;
    return s->result;
}

/*
 * The last loop reads the list through `((int *)ids)[i]`. The cast stops
 * the element address folding into sp-relative form, so the compiler hoists
 * `add r6, sp, #0x10` to function entry (ahead of the s spill) and reloads
 * the element after each call, while the case 4 call still takes a fresh
 * `add r2, sp, #0x10`. A `p = ids` pointer local instead CSEs that argument
 * into r6 and leaves 6 bytes out. `pt.x *= -1` and `Pt_021FB8F4 pt = {0, 0};` in the
 * loop block are required for the rest.
 */
int func_021FB91C(void *r, BtlvEffVmWork *s)
{
    int ids2[8];
    int ids[8];
    u32 a;
    u32 b;
    int n;
    int i;

    a = VM_GetU32(r);
    b = VM_GetU32(r);
    if (a <= 1) {
        switch (b) {
        case 3:
            func_021F81B4(a, s->attackerPos);
            break;
        case 4:
            n = func_021FCA04(s, 0x10, ids2);
            if (n != 0) {
                for (i = 0; i < n; i++)
                    func_021F81B4(a, ids2[n]);
            }
            break;
        default:
            func_021F8198(a, b);
            break;
        }
    } else {
        n = 0;
        switch (b) {
        case 0:
            for (i = 0; i < 8; i += 2) {
                if (func_021F7F1C(i)) {
                    ids[n] = i;
                    n++;
                }
            }
            break;
        case 1:
            for (i = 1; i < 8; i += 2) {
                if (func_021F7F1C(i)) {
                    ids[n] = i;
                    n++;
                }
            }
            break;
        case 2:
            for (i = 0; i < 8; i++) {
                if (func_021F7F1C(i)) {
                    ids[n] = i;
                    n++;
                }
            }
            break;
        case 3:
            n = 1;
            ids[0] = s->attackerPos;
            break;
        case 4:
            n = func_021FCA04(s, 0x10, ids);
            break;
        }
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Pt_021FB8F4 pt = {0, 0};

                pt.x = (a == 2) ? 0x80 : -0x10;
                if (((int *)ids)[i] & 1)
                    pt.x *= -1;
                BTLV_GAUGE_PlaceSlot((char *)func_021F86B4(), ((int *)ids)[i], (Pt_021FB8F4 *)&pt);
            }
        }
    }
    return s->result;
}

int func_021FBA64(struct Cursor *a, BtlvEffVmWork *s)
{
    int v0 = VM_GetU32(a);
    int v1 = VM_GetU32(a);
    int v2 = VM_GetU32(a);
    int v3 = VM_GetU32(a);
    int v4 = VM_GetU32(a);
    int v5 = VM_GetU32(a);
    int v6 = VM_GetU32(a);
    int v7 = VM_GetU32(a);

    VM_GetU32(a);
    func_021F9858((void *)a, v0, v1, v2, v4, v5, v6, v7, v3);
    return s->result;
}

/*
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Script command: mode 5 calls GFL_USE_StopAllSe, any other mode is passed to
 * GFL_USE_StopSeSlot.
 */
int func_021FBAD8(void *a, BtlvEffVmWork *s)
{
    int r = VM_GetU32(a);

    if (r == 5)
        GFL_USE_StopAllSe();
    else
        GFL_USE_StopSeSlot(r);
    return s->result;
}

int func_021FBAF8(void *a, BtlvEffVmWork *s)
{
    int *p;
    int x;
    int y;
    int diff;
    float f;
    float g;
    p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x38, 0, d_0220AE68, 0xf17);
    p[0] = (int)s;
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 2;
    x = func_021FCF2C((int)a, VM_GetU32(a));
    y = func_021FCF2C((int)a, VM_GetU32(a));
    p[4] = (x & 1) ? 127 : -128;
    p[5] = (y & 1) ? 127 : -128;
    p[8] = VM_GetU32(a);
    p[9] = VM_GetU32(a);
    p[10] = p[9];
    p[11] = 0;
    p[12] = VM_GetU32(a);
    p[13] = VM_GetU32(a) * 2;
    if (p[2] == 1 && p[13] == 0) p[13] = 2;
    if (p[4] > 0) p[6] = _ffix(_fadd(0.5f, _fflt(p[4] << 12)));
    else p[6] = _ffix(_fsub(_fflt(p[4] << 12), 0.5f));
    if (p[9] > 0) f = _fadd(0.5f, _fflt(p[9] << 12));
    else f = _fsub(_fflt(p[9] << 12), 0.5f);
    diff = p[5] - p[4];
    if (diff > 0) g = _fadd(0.5f, _fflt(diff << 12));
    else g = _fsub(_fflt(diff << 12), 0.5f);
    x = _ffix(g);
    y = _ffix(f);
    p[7] = func_0207C768(x, y);
    func_021F896C(func_02030DA8(s->owner, func_021FE594, p, 0), func_021FE690, 1);
    s->flags.bit.sePanRamp = 1;
    return s->result;
}

int func_021FBC78(struct Cursor *a, BtlvEffVmWork *s)
{
    int v0 = VM_GetU32(a);
    int v1 = VM_GetU32(a);
    int v2 = VM_GetU32(a);
    int v3 = VM_GetU32(a);
    int v4 = VM_GetU32(a);
    int v5 = VM_GetU32(a);
    int v6 = VM_GetU32(a);
    int v7 = VM_GetU32(a);
    int v8 = VM_GetU32(a);

    func_021F9948((void *)a, v0, v1, v2, v3, v4, v5, v6, v7, v8);
    return s->result;
}

/*
 * Script command: stores one argument in waitMode, waits on func_021FC744, and suspends.
 */
int func_021FBCEC(void *a, BtlvEffVmWork *s)
{
    s->waitMode = VM_GetU32(a);
    VM_SetWait(a, (int)func_021FC744);
    s->result = 1;
    return 1;
}

/*
 * Script command: stores one argument in waitFrames, waits on func_021FC9D0, and suspends.
 */
int func_021FBD10(void *a, BtlvEffVmWork *s)
{
    s->waitFrames = VM_GetU32(a);
    VM_SetWait(a, (int)func_021FC9D0);
    s->result = 1;
    return 1;
}

/*
 * Script command: stores one argument in result.
 */
void func_021FBD34(void *a, BtlvEffVmWork *s)
{
    s->result = VM_GetU32(a);
}

int func_021FBD44(struct Cursor *a, BtlvEffVmWork *s)
{
    int x = func_021FDBB0(s, VM_GetU32(a));
    int op = VM_GetU32(a);
    int y = VM_GetU32(a);
    int z = VM_GetU32(a);

    func_021FBDD4((int)a, x, y, op, z);
    return s->result;
}

int func_021FBD88(struct Cursor *a, BtlvEffVmWork *s)
{
    int x = func_021FDBB0(s, VM_GetU32(a));
    int op = VM_GetU32(a);
    int y = func_021FDBB0(s, VM_GetU32(a));
    int z = VM_GetU32(a);

    func_021FBDD4((int)a, x, y, op, z);
    return s->result;
}

void func_021FBDD4(int a, int b, int c, int op, int e)
{
    int t = 0;

    switch (op) {
    case 0:
        if (b == c)
            t = 1;
        break;
    case 1:
        if (b != c)
            t = 1;
        break;
    case 2:
        if (b < c)
            t = 1;
        break;
    case 3:
        if (b > c)
            t = 1;
        break;
    case 4:
        if (b <= c)
            t = 1;
        break;
    case 5:
        if (b >= c)
            t = 1;
        break;
    }
    if (t == 1)
        VM_Jump((struct Cur *)a, ((struct Obj21678 *)a)->f14 + e);
}

/*
 * Script command: relative jump when func_021F7F1C(x) equals y.
 */
int func_021FBE28(struct Cursor *a, BtlvEffVmWork *s)
{
    int x = VM_GetU32(a);
    int y = VM_GetU32(a);
    int off = VM_GetU32(a);

    if (y == func_021F7F1C(x))
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + off);
    return s->result;
}

/*
 * Script command: stores one argument in scriptVar.
 */
int func_021FBE60(void *a, BtlvEffVmWork *s)
{
    s->scriptVar = VM_GetU32(a);
    return s->result;
}

/*
 * Script command: stores func_021FDBB0(s, arg) in scriptVar.
 */
/*
 * Script command: stores func_021FDBB0(s, arg) in scriptVar.
 */
int func_021FBE74(void *a, BtlvEffVmWork *s)
{
    s->scriptVar = func_021FDBB0(s, VM_GetU32(a));
    return s->result;
}

int func_021FBE90(struct Cursor *a, BtlvEffVmWork *s)
{
    int sel = VM_GetU32(a);
    int v = VM_GetU32(a);

    switch (sel) {
    case 9:
        s->params.kind = v;
        break;
    case 10:
        s->params.variant = v;
        break;
    case 11:
        s->params.option = v;
        break;
    case 12:
        s->params.side = v;
        break;
    case 13:
        s->params.argA = v;
        break;
    case 14:
        s->params.argB = v;
        break;
    case 15:
        s->params.typeCode = v;
        break;
    case 0x35:
        s->flags.bit.cameraOffset = v;
        break;
    case 0x36:
        s->camVecSaved = v;
        break;
    case 0x37:
        s->scratchVar = v;
        break;
    case 0x38:
        s->flags.bit.cameraLocked = v;
        break;
    }
    return s->result;
}

int func_021FBF48(struct Cursor *a, BtlvEffVmWork *s)
{
    int buf[8];
    int x = VM_GetU32(a);
    int n = func_021FCA04(s, VM_GetU32(a), buf);
    int y = VM_GetU32(a);
    int i;

    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FFFD8((char *)func_021F8694(), buf[i], x, y);
    }
    return s->result;
}

int func_021FBFA0(int a, BtlvEffVmWork *b)
{
    func_02200140((Work_02200140 *)(func_021F8694()), b->defenderPos, b->attackerPos);
    return b->result;
}

int func_021FBFC0(void *a, BtlvEffVmWork *s)
{
    int buf[8];
    int n;
    int x;
    int y;
    int z;
    int q;
    int r;
    int duration;
    int i;
    int slot;
    int *p;
    n = func_021FCA04(s, VM_GetU32(a), buf);
    x = VM_GetU32(a);
    y = VM_GetU32(a);
    z = VM_GetU32(a);
    q = VM_GetU32(a);
    r = VM_GetU32(a);
    duration = VM_GetU32(a);
    if (n != 0) {
        if (duration == 0) {
            for (i = 0; i < n; i++) {
                slot = func_021FE4D0(s);
                s->seVoiceIds[slot] = func_02200218((Work_02200218 *)((char *)func_021F8694()), buf[i], x, y, z, q, r);
            }
            func_021FE410(s, 0x7f000, 0x6b000, 10);
            if (!s->flags.bit.fadeRestart) {
                p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 4, 0, d_0220AE68, 0x10f9);
                p[0] = (int)s;
                func_021F896C(func_02030DA8(s->owner, func_021FE8D8, (int *)p, 0), 0, 0);
            }
        } else {
            for (i = 0; i < n; i++) {
                p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x20, 0, d_0220AE68, 0x1104);
                p[0] = (int)s;
                p[1] = buf[i];
                p[2] = x;
                p[3] = y;
                p[4] = z;
                p[5] = q;
                p[6] = r;
                p[7] = duration;
                s->flags.bit.particleTaskActive = 1;
                func_021F896C(func_02030DA8(s->owner, func_021FE6A4, (int *)p, 0), func_021FE750, 1);
            }
        }
    }
    return s->result;
}

/*
 * Script command: stores one argument in typeSource.
 */
int func_021FC134(void *a, BtlvEffVmWork *s)
{
    s->typeSource = VM_GetU32(a);
    return s->result;
}

int func_021FC148(struct Cursor *a, BtlvEffVmWork *s)
{
    int idx = VM_GetU32(a);
    int q = func_021FCF2C((int)a, VM_GetU32(a));
    int dx = VM_GetU32(a);
    int dy = VM_GetU32(a);
    int p5 = VM_GetU32(a);
    int p6 = VM_GetU32(a);
    Pt_021FC148 pt;
    int o1;
    int o2;
    int m;

    func_021FF3F4((void *)func_021F8694(), &pt, q);
    pt.x += dx;
    pt.y += dy;
    func_0206DF3C((int *)((Pt_021FC148 *)&pt), &o1, &o2);
    m = PALANM_GetPairedCodeForFirst(s->params.typeCode);
    m = (m == 0 || m > 0x19) ? 4 : m;
    m = (m == 0x19) ? 0x11 : m;
    m *= 2;
    s->resources[idx] = (int)func_02201B20((char *)func_021F86F0(), 0x5f, m + 0x81, m + 0x82, 0x81, 0x82, o1, o2, p5, p6);
    return s->result;
}

int func_021FC20C(struct Ring *a, BtlvEffVmWork *s)
{
    int n = VM_GetU32((struct Cursor *)a);
    int v = VM_GetU32((struct Cursor *)a);
    int w = VM_GetU32((struct Cursor *)a);
    int *p;

    s->savedAttackerPos[s->callDepth] = s->attackerPos;
    s->savedDefenderPos[s->callDepth] = s->defenderPos;
    s->savedScriptBuf[s->callDepth] = (int)s->scriptBuf;
    s->savedScriptVar[s->callDepth] = s->scriptVar;
    if (v != 14) s->attackerPos = v;
    if (w != 16) s->defenderPos = w;
    s->scriptVar = 0;
    p = ARC_TOOL_LoadMember(0x43, n - 0x231, (u16)((s->heapId & 0x7fff) | 0x8000));
    s->scriptBuf = p;
    VM_Call(a, (unsigned int)((char *)p + p[1]));
    s->callDepth++;
    return s->result;
}

int func_021FC2DC(int a, BtlvEffVmWork *s)
{
    int n;

    s->callDepth--;
    func_020307B0(s->scriptBuf);
    n = s->callDepth;
    s->attackerPos = s->savedAttackerPos[n];
    s->defenderPos = s->savedDefenderPos[n];
    s->scriptBuf = (void *)s->savedScriptBuf[n];
    s->scriptVar = s->savedScriptVar[n];
    VM_Return((struct Ring *)a);
    return s->result;
}

/*
 * Script command: jumps the reader by a relative offset.
 */
int func_021FC334(struct Cursor *a, BtlvEffVmWork *s)
{
    int off = VM_GetU32(a);
    VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + off);
    return s->result;
}

/*
 * Script command: sets the blockedOnTask flag, waits on func_021FC9E4, and suspends.
 */
int func_021FC354(void *a, BtlvEffVmWork *s)
{
    s->flags.bit.blockedOnTask = 1;
    VM_SetWait(a, (int)func_021FC9E4);
    s->result = 1;
    return 1;
}

/*
 * Script command: loads script id (archive 0x42 below 0x231, else 0x43) into scriptBuf and jumps into it.
 */
int func_021FC374(void *a, BtlvEffVmWork *s)
{
    int id = VM_GetU32(a);
    char *p;

    func_020307B0(s->scriptBuf);
    if (id < 0x231)
        *(char * *)&s->scriptBuf = ARC_TOOL_LoadMember((int)0x42, (int)id, (u16)((s->heapId & 0x7fff) | 0x8000));
    else
        *(char * *)&s->scriptBuf = ARC_TOOL_LoadMember((int)0x43, (int)(id - 0x231), (u16)((s->heapId & 0x7fff) | 0x8000));
    p = *(char * *)&s->scriptBuf;
    s->scriptVar = 0;
    VM_Jump(a, (u32)(p + ((struct Obj21683 *)p)->f4));
    return s->result;
}

int func_021FC3D8(struct Cursor *a, BtlvEffVmWork *s)
{
    int v = VM_GetU32(a);
    int *p;

    p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0xc, 0, d_0220AE68, 0x1250);
    p[0] = (int)s;
    p[1] = v;
    p[2] = 0;
    func_021F896C(func_02030DA8((void *)s->owner, func_021FE930, (void *)(int *)p, 0), 0, 1);
    return s->result;
}

/*
 * Script command: passes one argument to func_021F8934.
 */
int func_021FC434(void *a, BtlvEffVmWork *s)
{
    func_021F8934(VM_GetU32(a));
    return s->result;
}

/*
 * Script reset: frees slot objects and buffers, restores display state, then resumes the
 * pending script at 0x1ec or reloads script 0x34 when the follow-up conditions hold.
 */
int func_021FC448(void *a, BtlvEffVmWork *s)
{
    int i;
    int v;
    u16 id;
    u16 id2;
    int b;
    int off;
    char *p;
    void *q;

    for (i = 0; i < 16; i++) {
        if (s->emitters[i] != 0) {
            func_021FDB08(s->emitters[i]);
            s->emitters[i] = 0;
        }
        s->voiceIds[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        if (s->resources[i] != -1) {
            func_02201CA4((Res_02201B20 *)((struct Res *)func_021F86F0()), s->resources[i]);
            s->resources[i] = -1;
        }
    }
    for (i = 0; i < s->allocBufferCount; i++)
        func_020307B0(s->allocBuffers[i]);
    s->allocBufferCount = 0;
    func_021F8A10(1);
    func_021FE4F8(s);
    func_021FE520(s);
    if (s->flags.bit.keepBackground == 0)
        func_021F8934(1);
    func_02011290(a);
    s->result = 1;
    if (s->flags.bit.gfxReloadPending) {
        q = (void *)func_021F8764();
        if (q != 0)
            BTLV_SCU_ReloadGraphics(q);
        func_0204047C(3, 0);
        s->flags.bit.gfxReloadPending = 0;
        func_02040618(3, 0, s->bg3ScrollX);
        func_02040618(3, 3, s->bg3ScrollY);
    }
    if (s->flags.bit.blendActive) {
        func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
        s->flags.bit.blendActive = 0;
    }
    if (s->flags.bit.stopSeOnEnd)
        GFL_USE_StopAllSe();
    v = 0;
    if (func_021FFD9C((char *)func_021F8694(), s->attackerPos) != 0) {
        id = s->effectId;
        if (((id == 0xf8 || id == 0x161) && s->params.variant == 1) || id == 0x90 || id == 0x77 || id == 0x10b) {
        } else {
            v = func_021FFF38((char *)func_021F8694(), s->attackerPos) & 1;
        }
    }
    if (s->pendingScriptBuf != 0) {
        func_020307B0(s->scriptBuf);
        p = s->pendingScriptBuf;
        s->scriptBuf = p;
        s->pendingScriptBuf = 0;
        s->flags.bit.fallbackScript = 0;
        off = s->pendingScriptOffset;
        func_02040588(1, 0);
        func_02040588(2, 0);
        func_02040588(3, 0);
        s->scriptVar = 0;
        VM_Start(a, (u8 *)((char *)s->scriptBuf + *(int *)(p + off)));
        return 1;
    }
    b = s->flags.bit.fallbackPending;
    if (b == 1 && s->effectId == 0x291) {
        func_020307B0(s->scriptBuf);
        s->effectId = 0x34;
        p = ARC_TOOL_LoadMember(0x43, s->effectId, (u16)((s->heapId & 0x7fff) | 0x8000));
        s->scriptBuf = p;
        s->flags.bit.fallbackScript = 1;
        s->scriptVar = 0;
        s->flags.bit.fallbackPending = 0;
        VM_Start(a, (u8 *)(p + ((struct Obj13598 *)p)->f4));
        return 1;
    }
    id2 = s->effectId;
    if ((id2 == 0x286 || s->flags.bit.fallbackScript == 0) && id2 != 0x90 && id2 != 0xe2 && b == 0 && v != 0) {
        if (id2 == 0x1f6)
            func_021FF374((Work_vF228 *)((void *)func_021F8694()), s->attackerPos, 0);
        func_020307B0(s->scriptBuf);
        s->effectId = 0x34;
        p = ARC_TOOL_LoadMember(0x43, s->effectId, (u16)((s->heapId & 0x7fff) | 0x8000));
        s->scriptBuf = p;
        s->flags.bit.fallbackScript = 1;
        s->scriptVar = 0;
        s->flags.bit.fallbackPending = 0;
        VM_Start(a, (u8 *)(p + ((struct Obj13598 *)p)->f4));
        return 1;
    }
    if (id2 != 0x27e) {
        func_02040588(1, 1);
        func_02040588(2, 1);
        func_02040588(3, 1);
    }
    return 1;
}

/*
 * witness: arm9 PARTICLE_GetEffectCount filed as src/matched/arm9/PARTICLE_GetEffectCount.c.
 * followers: 021FC9D0 countdown <=0; 021FC9E4 !flags bit7;
 *   021FC9F4 !flags bit16 (filed as their own packets).
 * lever: enum loop counters retain entry guards; flag bitfields retain
 *   shift-pair tests (raw unsigned mask expressions added 16 bytes).
 */
int func_021FC744(int a, BtlvEffVmWork *s)
{
    int i;
    Slot_021F6560 j;

    if (s->waitMode <= 1) {
        if (func_021F722C((char *)func_021F8684()) == 1) return 0;
        if (s->flags.bit.cameraOverride) {
            s->flags.bit.cameraOverride = 0;
            s->layoutMode = 1;
            func_021FF16C((Work_021FF16C *)((void *)func_021F8694()));
        }
    }
    if (s->waitMode == 0 || s->waitMode == 3) {
        for (j = 0; j < 14; j++) {
            if (func_021FFCB0((Work_021FFCB0 *)((void *)func_021F8694()), j) == 1) return 0;
        }
    }
    if (s->waitMode == 4) {
        for (j = 8; j < 14; j++) {
            if (func_021FFD9C((char *)func_021F8694(), j)) {
                if (func_02200494((char *)func_021F8694(), j) == 1) return 0;
            }
        }
    }
    if (s->waitMode == 0 || s->waitMode == 5) {
        if (BTLV_BG_IsScrolling((void *)func_021F8700()) == 1) return 0;
    }
    if (s->waitMode == 0 || s->waitMode == 2) {
        for (i = 0; i < 16; i++) {
            if (s->emitters[i] != 0) {
                if (PARTICLE_GetEffectCount(s->emitters[i]) != 0) return 0;
            }
        }
    }
    if (s->waitMode == 0 || s->waitMode == 6 || s->waitMode == 8) {
        if (func_021F8324(0) != 0) return 0;
    }
    if (s->waitMode == 0 || s->waitMode == 7 || s->waitMode == 8) {
        if (func_021F8324(1) != 0) return 0;
    }
    if (s->waitMode == 0 || s->waitMode == 9) {
        if (func_021F8324(3) != 0) return 0;
    }
    if (s->waitMode == 10) {
        if (GFL_USE_IsAnySeBusy() != 0 || s->flags.bit.seVolumeRamp || s->flags.bit.sePanRamp) return 0;
    }
    if (s->waitMode == 11) {
        if (GFL_USE_IsSeSlotBusy(1) != 0 || s->flags.bit.seVolumeRamp || s->flags.bit.sePanRamp) return 0;
    }
    if (s->waitMode == 12) {
        if (GFL_USE_IsSeSlotBusy(2) != 0 || s->flags.bit.seVolumeRamp || s->flags.bit.sePanRamp) return 0;
    }
    if (s->waitMode == 13) {
        if (GFL_USE_IsSeSlotBusy(4) != 0 || s->flags.bit.seVolumeRamp || s->flags.bit.sePanRamp) return 0;
    }
    if (s->waitMode == 14) {
        if (GFL_USE_IsSeSlotBusy(3) != 0 || s->flags.bit.seVolumeRamp || s->flags.bit.sePanRamp) return 0;
    }
    if (s->waitMode == 15) {
        if (GFL_USE_IsSeSlotBusy(0) != 0 || s->flags.bit.seVolumeRamp || s->flags.bit.sePanRamp) return 0;
    }
    if (s->waitMode == 16) {
        if (s->flags.bit.particleTaskActive) return 0;
        for (i = 0; i < 6; i++) {
            if (s->seVoiceIds[i] != -1) {
                if (PM_VOICE_IsActive(s->seVoiceIds[i]) != 0) return 0;
                s->seVoiceIds[i] = -1;
            }
        }
    }
    if (s->waitMode == 0 || s->waitMode == 17) {
        if (s->flags.bit.bgFadeActive) return 0;
    }
    return 1;
}

/*
 * Wait callback: decrements waitFrames, done when it reaches zero.
 */
int func_021FC9D0(void *a, BtlvEffVmWork *s)
{
    return --s->waitFrames <= 0;
}

/*
 * Wait callback: done once the blockedOnTask flag is clear.
 */
int func_021FC9E4(void *a, BtlvEffVmWork *s)
{
    if (s->flags.bit.blockedOnTask)
        return 0;
    return 1;
}

/*
 * Wait callback: done once the particleSysActive flag is clear.
 */
int func_021FC9F4(void *a, BtlvEffVmWork *s)
{
    if (s->flags.bit.particleSysActive)
        return 0;
    return 1;
}

int func_021FCA04(BtlvEffVmWork *s, int cmd, int *out)
{
    Key_021F6560 k;
    int n = 1;
    int mode;
    Targets t;
    int group;
    int *p;
    int i;
    int hi;

    switch (cmd) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6:
    case 7: case 8: case 9: case 10: case 11: case 12: case 13:
        out[0] = cmd;
        break;
    case 14:
        out[0] = s->attackerPos;
        if (out[0] == 0xff) {
            if (func_021F7F1C(0) == 1) {
                out[0] = 0;
            } else if (func_021F7F1C(2) == 1) {
                out[0] = 2;
            } else if (func_021F7F1C(4) == 1) {
                out[0] = 4;
            } else if (func_021F7F1C(4) == 1) {
                out[0] = 6;
            }
        }
        break;
    case 15:
        if (s->attackerPos > 1) {
            out[0] = s->attackerPos ^ 2;
        } else {
            out[0] = 0xff;
        }
        break;
    case 16:
        out[0] = s->defenderPos;
        if (out[0] == 0xff) {
            mode = func_021F8710();
            n = 0;
            if (mode == 0 || mode == 3) {
                if (s->params.kind == 8 || s->params.kind == 10) {
                    out[0] = s->attackerPos;
                    n = 1;
                    if (func_021F7F1C(s->attackerPos ^ 1)) {
                        out[1] = s->attackerPos ^ 1;
                        n++;
                    }
                } else {
                    k = KEY_ONE;
                    n = 0;
                    if (func_021F7F1C(s->attackerPos ^ k)) {
                        out[0] = s->attackerPos ^ k;
                        n++;
                    }
                }
            } else {
                switch (s->params.kind) {
                case 0: case 1: case 2: case 3:
                    break;
                case 4:
                    if (mode == 2 && s->attackerPos != 4 && s->attackerPos != 5) {
                        t = d_02209E58;
                        group = s->attackerPos > 3 ? 2 : 0;
                        i = 0;
                        p = t.v[(s->attackerPos & 1) + group];
                        for (; i < 3; i++) {
                            if (func_021F7F1C(p[i])) {
                                out[n] = p[i];
                                n++;
                            }
                        }
                    } else {
                        for (k = KEY_TWO; k <= KEY_MAX; k++) {
                            if (s->attackerPos != k && func_021F7F1C(k)) {
                                out[n] = k;
                                n++;
                            }
                        }
                    }
                    break;
                case 5: case 7: case 9: case 13:
                    k = (s->attackerPos & 1) ? KEY_TWO : KEY_THREE;
                    hi = (mode == 2) ? 7 : 5;
                    if (mode == 2) {
                        if (s->attackerPos <= 3)
                            k += 2;
                        if (s->attackerPos >= 6)
                            hi -= 2;
                    }
                    for (; k <= hi; k += 2) {
                        if (func_021F7F1C(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                case 11:
                    k = (s->attackerPos & 1) ? KEY_TWO : KEY_THREE;
                    for (; k <= KEY_MAX; k += 2) {
                        if (func_021F7F1C(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                case 6: case 12:
                    k = (s->attackerPos & 1) ? KEY_THREE : KEY_TWO;
                    for (; k <= KEY_MAX; k += 2) {
                        if (func_021F7F1C(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                case 8: case 10:
                    for (k = KEY_TWO; k <= KEY_MAX; k++) {
                        if (func_021F7F1C(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                }
            }
        }
        break;
    case 17:
        if (s->defenderPos > 1) {
            out[0] = s->defenderPos ^ 2;
        } else {
            out[0] = 0xff;
        }
        break;
    case 18:
        n = 0;
        for (k = KEY_ZERO; k <= KEY_MAX; k++) {
            if (func_021F7F1C(k)) {
                out[n] = k;
                n++;
            }
        }
        break;
    case 19: case 20:
        k = (cmd == 19) ? KEY_ZERO : (Key_021F6560)n;
        n = 0;
        for (; k <= KEY_MAX; k += 2) {
            if (func_021F7F1C(k)) {
                out[n] = k;
                n++;
            }
        }
        break;
    }
    if (out[0] != 0xff && out[0] < 8) {
        if (func_021F7F1C(out[0]) == 1) {
            out[0] = func_021FD04C(s, out[0]);
        } else {
            out[0] = 0xff;
            n = 0;
        }
    }
    return n;
}

/*
 * lever: enum key retains loop entry guards and constant one; shared outer
 *   exit, separate output store/increment, and branch-local n=0 reproduce
 *   the original scheduling (r1 266 bytes DIFF; r2 532 bytes; r3 EXACT).
 */
int func_021FCD14(BtlvEffVmWork *s, int unused, int *out)
{
    Key_021F6560 k = KEY_ONE;
    int n = 1;
    int mode;
    Targets t;
    int group;
    int *p;
    int i;

    out[0] = s->defenderPos;
    if (out[0] == 0xff) {
    mode = func_021F8710();
    n = 0;
    if (mode == 0 || mode == 3) {
        if (s->params.kind == 8 || s->params.kind == 10) {
            out[0] = s->attackerPos;
            n = 1;
            if (func_021F7F1C(s->attackerPos ^ 1)) {
                out[1] = s->attackerPos ^ 1;
                n++;
            }
        } else {
            n = 0;
            if (func_021F7F1C(s->attackerPos ^ 1)) {
                out[0] = s->attackerPos ^ 1;
                n++;
            }
        }
    } else {
        switch (s->params.kind) {
        case 0: case 1: case 2: case 3:
            break;
        case 4:
            if (mode == 2 && s->attackerPos != 4 && s->attackerPos != 5) {
                t = d_02209E28;
                group = s->attackerPos > 3 ? 2 : 0;
                i = 0;
                p = t.v[(s->attackerPos & 1) + group];
                for (; i < 3; i++) {
                    if (func_021F7F1C(p[i]) && !func_021FF348((Work_021FF348 *)((void *)func_021F8694()), p[i])) {
                        out[n] = p[i];
                        n++;
                    }
                }
            } else {
                for (k = KEY_TWO; k <= KEY_MAX; k++) {
                    if (s->attackerPos != k && func_021F7F1C(k) && !func_021FF348((Work_021FF348 *)((void *)func_021F8694()), k)) {
                        out[n] = k;
                        n++;
                    }
                }
            }
            break;
        case 5: case 7: case 9: case 13:
            if (mode == 1) {
                out[0] = (s->attackerPos & k) ? 0 : k;
                n = 1;
            } else {
                if (s->attackerPos != 4 && s->attackerPos != 5) {
                    out[0] = d_0220AD18[s->attackerPos];
                    n = k;
                } else {
                    out[0] = s->attackerPos ^ 1;
                    n = 1;
                }
            }
            break;
        case 11:
            if (mode == 1) {
                out[0] = (s->attackerPos & k) ? 0 : k;
                n = 1;
            } else {
                if (s->attackerPos != 4 && s->attackerPos != 5) {
                    out[0] = d_0220AD38[s->attackerPos];
                    n = k;
                } else {
                    out[0] = s->attackerPos ^ 1;
                    n = 1;
                }
            }
            break;
        case 6: case 12:
            k = (s->attackerPos & k) ? KEY_THREE : KEY_TWO;
            for (; k <= KEY_MAX; k += 2) {
                if (func_021F7F1C(k) && !func_021FF348((Work_021FF348 *)((void *)func_021F8694()), k)) {
                    out[n] = k;
                    n++;
                }
            }
            break;
        case 8: case 10:
            for (k = KEY_TWO; k <= KEY_MAX; k++) {
                if (func_021F7F1C(k) && !func_021FF348((Work_021FF348 *)((void *)func_021F8694()), k)) {
                    out[n] = k;
                    n++;
                }
            }
            break;
        }
    }
    }
    return n;
}

int func_021FCF2C(int a, int idx)
{
BtlvEffVmWork *s = func_02011324((struct ScriptVm *)a);
    int v;

    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        v = idx;
        break;
    case 14:
        v = s->attackerPos;
        if (v == 0xff) {
            if (func_021F7F1C(2) == 1)
                return 2;
            if (func_021F7F1C(4) == 1)
                return 4;
            if (func_021F7F1C(6) == 1)
                return 6;
            return 0;
        }
        break;
    case 15:
        if (s->attackerPos > 1)
            v = s->attackerPos ^ 2;
        else
            v = 0xff;
        break;
    case 16:
        v = s->defenderPos;
        if (v == 0xff) {
            if (s->attackerPos & 1) {
                if (func_021F7F1C(2) == 1)
                    return 2;
                if (func_021F7F1C(4) == 1)
                    return 4;
                if (func_021F7F1C(6) == 1)
                    return 6;
                return 0;
            } else {
                if (func_021F7F1C(3) == 1)
                    return 3;
                if (func_021F7F1C(5) == 1)
                    return 5;
                if (func_021F7F1C(7) == 1)
                    return 7;
                return 1;
            }
        }
        break;
    case 17:
        if (s->defenderPos > 1)
            v = s->defenderPos ^ 2;
        else
            v = 0xff;
        break;
    }
    return func_021FD070(a, v);
}

#define MUL(a, b) ((int)(((s64)(a) * (b) + 0x800) >> 12))

int func_021FD04C(BtlvEffVmWork *s, int i)
{
    if (func_021F7F1C(i) == 1) {
        if (s->flags.bit.flipSides)
            i ^= 1;
    } else {
        i = 0xff;
    }
    return i;
}

int func_021FD070(int a, int b)
{
    int r = b;

    if (((BtlvEffVmWork *)func_02011324((void *)a))->flags.bit.flipSides)
        r ^= 1;
    return r;
}

int func_021FD088(int a, int *out)
{
BtlvEffVmWork *s = (void *)func_02011324((void *)a);
    int mode = func_021F8710();
    int v;

    *out = s->defenderPos;
    if (*out != 0xff)
        return mode;
    if (mode == 0 || mode == 3 || s->flags.bit.fallbackScript == 1) {
        *out = s->attackerPos ^ 1;
        return mode;
    }
    switch (s->params.kind) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 8:
    case 10:
        if (mode == 1) {
            mode = 0;
            *out = !(s->attackerPos & 1);
        } else {
            v = s->attackerPos;
            if (v != 4 && v != 5) {
                mode = 1;
                *out = d_0220AD58[v];
            } else {
                *out = v ^ 1;
            }
        }
        break;
    case 7:
    case 9:
    case 13:
        *out = s->attackerPos ^ 1;
        break;
    case 11:
        mode = 0;
        *out = !(s->attackerPos & 1);
        break;
    case 6:
    case 12:
        mode = 0;
        *out = (s->attackerPos & 1) != 0;
        break;
    }
    return mode;
}

int func_021FD15C(BtlvEffVmWork *p, int key, int *out)
{
    int i;
    int r = 1;

    for (i = 0; i < 16; i++) {
        if (key == p->voiceIds[i]) {
            r = 0;
            break;
        }
    }
    if (i == 16) {
        for (i = 0; i < 16; i++) {
            if (p->voiceIds[i] == -1) {
                p->voiceIds[i] = key;
                break;
            }
        }
    }
    *out = i;
    return r;
}

void func_021FD19C(BtlvEffVmWork *p, int i, char *q)
{
    p->soundHandles[i] = ((struct Obj18571 *)q)->f8;
}

int func_021FD1A8(BtlvEffVmWork *p, int v)
{
    int i;

    for (i = 0; i < 16; i++) {
        if (p->voiceIds[i] == v)
            break;
    }
    return i;
}

int func_021FD1C0(BtlvEffVmWork *p, int i)
{
    return p->soundHandles[i];
}

/*
 * 2026-10-02: the kind == 4 swap closed. It is a per-axis swap through
 * temps from a (tx = a.x; a.x = b.x; ...), then the sums read the new a:
 * b.x = tx + a.x. Grouped temps, temps from b and `b.x = b.x + tx` all
 * leave the spill on old b.y or the add operands reversed.
 */
void func_021FD1CC(void *p)
{
    Vec_021F6560 a;
    Vec_021F6560 b;
    Vec_021F6560 c;
    Vec_021F6560 axis;
    Vec_021F6560 d;
    Vec_021F6560 e;
    Mtx m;
    Vec_021F6560 v1;
    Vec_021F6560 v2;
    Vec_021F6560 axis2;
    Vec_021F6560 sc;
    Dir dir;
    Rec_021FD04C *r;
    int flip;
BtlvEffVmWork *s;
    Obj_vD04C *o;
    u16 ang;
    int t0, t1, t2, t3;
    int n;
    int tx, ty, tz;

    r = (Rec_021FD04C *)func_02051774();
    flip = r->flip;
    switch (r->k1) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        r->k1 = func_021FD070(r->vm, r->k1);
        break;
    case 9:
    case 11:
        r->k1 = func_021FCF2C(r->vm, r->k1 + 5);
        break;
    case 8:
        a.x = r->pa.x;
        a.y = r->pa.y;
        a.z = r->pa.z;
        break;
    case 14: case 15: case 16: case 17:
        func_021FF3FC((const Vec3_vF228 *)((const Vec_021F6560 *)func_021F8694()), (Vec3_vF228 *)&a, r->k1 - 12, 1);
        r->k1 = -1;
        break;
    case 18: case 19: case 20: case 21:
        func_021FF3FC((const Vec3_vF228 *)((const Vec_021F6560 *)func_021F8694()), (Vec3_vF228 *)&a, r->k1 - 16, 1);
        switch (r->k1) {
        case 18: a.z += 0x1a00; break;
        case 19: a.z += 0x2600; break;
        case 20: a.z += 0x600; break;
        case 21: a.z += 0x3900; break;
        }
        r->k1 = -1;
        break;
    }
    if (r->k1 != -1 && r->k1 != 8)
        func_021FF3F4((void *)func_021F8694(), &a, r->k1);
    switch (r->k2) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        r->k2 = func_021FD070(r->vm, r->k2);
        break;
    case 9:
        r->k2 = func_021FCF2C(r->vm, r->k2 + 5);
        break;
    case 10:
        flip = 1;
        r->k2 = func_021FCF2C(r->vm, r->k2 + 4);
        break;
    case 12:
        flip = 1;
    case 11:
        n = func_021FD088(r->vm, &r->k2);
        func_021FF3FC((const Vec3_vF228 *)((const Vec_021F6560 *)func_021F8694()), (Vec3_vF228 *)&b, r->k2, n);
        r->k2 = -1;
        break;
    case 8:
        b.x = r->pb.x;
        b.y = r->pb.y;
        b.z = r->pb.z;
        break;
    case 14: case 15: case 16: case 17:
        func_021FF3FC((const Vec3_vF228 *)((const Vec_021F6560 *)func_021F8694()), (Vec3_vF228 *)&b, r->k2 - 12, 1);
        r->k2 = -1;
        break;
    case 18: case 19: case 20: case 21:
        func_021FF3FC((const Vec3_vF228 *)((const Vec_021F6560 *)func_021F8694()), (Vec3_vF228 *)&b, r->k2 - 16, 1);
        switch (r->k1) {
        case 18: b.z += 0x1a00; break;
        case 19: b.z += 0x2600; break;
        case 20: b.z += 0x600; break;
        case 21: b.z += 0x3900; break;
        }
        r->k2 = -1;
        break;
    }
    if (r->k2 != -1 && r->k2 != 8)
        func_021FF3F4((void *)func_021F8694(), &b, r->k2);
    func_021F8710();
    a.z += 0x500;
    b.z += 0x500;
    if ((u32)(r->mode - 1) <= 1) {
        func_021FE1B8((VecFx32_021FE1B8 *)&a, (const VecFx32_021FE1B8 *)(&r->ofs));
        func_021FE1B8((VecFx32_021FE1B8 *)&b, (const VecFx32_021FE1B8 *)(&r->ofs));
    } else if (r->mode == 3) {
        c.x = a.x;
        c.y = a.y;
        c.z = a.z;
        a.y += r->ofs.y;
        func_021FE1B8((VecFx32_021FE1B8 *)&c, (const VecFx32_021FE1B8 *)(&r->ofs));
    } else {
        a.y += r->ofs.y;
    }
    b.y += r->ofs.y;
    if (r->kind != 0) {
        s = (void *)func_02011324((void *)r->vm);
        (Obj_vD04C *)s->allocBuffers[s->allocBufferCount] = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x60, 0, d_0220AE68, 0x194a);
        o = (Obj_vD04C *)s->allocBuffers[s->allocBufferCount];
        BUTTON_MAN_SetUserData(p, (int)o);
        BUTTON_MAN_SetCallback(p, (int)func_021FD8CC);
        s->allocBufferCount += 1;
        o->f38 = 0;
        o->f50 = 0;
        o->f54 = 0;
        o->f58 = 0;
        o->f4c = r->kind;
        o->f48 = r->f24 >> 12;
        o->f5c = r->mode;
        if (r->kind == 3) {
            o->f40 = func_0207C768(0x6000000, r->f24);
        } else if ((u32)(r->kind - 5) <= 1) {
            o->f40 = func_0207C768(0x8000000, r->f24);
            o->f44 = func_0207C768(0x10000000, r->f24);
            o->f44 = MUL(o->f44, r->f54);
        } else {
            o->f40 = func_0207C768(0x8000000, r->f24);
        }
        if (o->f40 == 0)
            o->f40 = 1;
        o->f30 = func_0207CF3C((const Vec_021F6560 *)&a, (const Vec_021F6560 *)&b) / 2;
        if (r->kind == 1 || r->kind == 4)
            o->f34 = 0;
        else
            o->f34 = r->f1c;
        if (r->kind == 4) {
            tx = a.x;
            a.x = b.x;
            ty = a.y;
            a.y = b.y;
            tz = a.z;
            a.z = b.z;
            b.x = tx + a.x;
            b.y = ty + a.y;
            b.z = tz + a.z;
        }
        d.x = b.x - a.x;
        d.y = b.y - a.y;
        d.z = b.z - a.z;
        VEC_Normalize((const Vec_021F6560 *)&d, (Vec_021F6560 *)&d);
        e.x = 0x1000;
        e.y = 0;
        e.z = 0;
        ang = FX_AcosIdx(func_0207CA68((const Vec_021F6560 *)&e, (const Vec_021F6560 *)&d));
        func_0207CAE8((const Vec_021F6560 *)&e, (const Vec_021F6560 *)&d, (Vec_021F6560 *)&axis);
        VEC_Normalize((const Vec_021F6560 *)&axis, (Vec_021F6560 *)&axis);
        MTX_RotAxis43(o, (const Vec_021F6560 *)&axis, FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
        o->pos.x = a.x;
        o->pos.y = a.y;
        o->pos.z = a.z;
    }
    if (r->k1 != 8 && r->k2 != 8 && r->k1 != r->k2) {
        dir.on = 2;
        b.x -= a.x;
        b.y -= a.y;
        b.z -= a.z;
        BUTTON_MAN_SetRow2(p, (struct S12 *)(&b));
        BUTTON_MAN_SetRow5(p, (struct S12 *)(&b));
        v2.x = b.x;
        v2.y = 0;
        v2.z = b.z;
        BUTTON_MAN_GetRot(p, &dir.dir);
        v1.x = dir.dir.x;
        v1.y = 0;
        v1.z = dir.dir.z;
        VEC_Normalize((const Vec_021F6560 *)&v1, (Vec_021F6560 *)&v1);
        VEC_Normalize((const Vec_021F6560 *)&v2, (Vec_021F6560 *)&v2);
        ang = FX_AcosIdx(func_0207CA68((const Vec_021F6560 *)&v1, (const Vec_021F6560 *)&v2));
        func_0207CAE8((const Vec_021F6560 *)&v1, (const Vec_021F6560 *)&v2, (Vec_021F6560 *)&axis2);
        VEC_Normalize((const Vec_021F6560 *)&axis2, (Vec_021F6560 *)&axis2);
        MTX_RotAxis43(&m, (const Vec_021F6560 *)&axis2, FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
        v1.x = dir.dir.x;
        v1.y = dir.dir.y;
        v1.z = dir.dir.z;
        MTX_MultVec43((const Vec_021F6560 *)&v1, &m, (Vec_021F6560 *)&v1);
        VEC_Normalize((const Vec_021F6560 *)&v1, (Vec_021F6560 *)&v1);
        if (flip == 1) {
            v1.x *= -1;
            v1.z *= -1;
        }
        dir.dir.x = v1.x;
        dir.dir.y = v1.y;
        dir.dir.z = v1.z;
        if (ang < 0x2000 || (ang > 0x6000 && ang < 0xa000) || ang > 0xe000)
            dir.on = 0;
        BUTTON_MAN_SetRow3Half(p, (u16 *)(&dir));
        BUTTON_MAN_SetRot(p, (const struct Vec3 *)(&dir.dir));
    }
    if ((r->mode != 0 && (r->k1 & 1)) || r->mode == 0 || (u32)(r->mode - 2) <= 1) {
        t0 = BUTTON_MAN_GetScaleX(p);
        t1 = BUTTON_MAN_GetAlpha(p) << 12;
        t2 = BUTTON_MAN_GetAngle(p);
        t3 = BUTTON_MAN_GetScaleY(p);
        if (r->f44 != 0) {
            BUTTON_MAN_SetScaleX(p, MUL(t0, r->f44));
            BUTTON_MAN_SetScaleY(p, MUL(t3, r->f44));
        }
        if (r->f48 != 0)
            BUTTON_MAN_SetAlpha(p, (u16)(MUL(t1, r->f48) >> 12));
        if (r->f4c != 0)
            BUTTON_MAN_SetAngle(p, (s16_021F6560)MUL(t2, r->f4c));
        if (r->f50 != 0) {
            BUTTON_MAN_GetPos(p, (Vec_021F6560 *)&sc);
            sc.x = MUL(sc.x, r->f50);
            sc.y = MUL(sc.y, r->f50);
            sc.z = MUL(sc.z, r->f50);
            BUTTON_MAN_SetPos(p, (const Vec_021F6560 *)&sc);
            t0 = BUTTON_MAN_GetOffsetX(p);
            BUTTON_MAN_SetOffsetX(p, (s16_021F6560)MUL(t0, r->f50));
            t0 = BUTTON_MAN_GetOffsetY(p);
            BUTTON_MAN_SetOffsetY(p, (s16_021F6560)MUL(t0, r->f50));
        }
    }
    if (r->mode == 3)
        BUTTON_MAN_SetEmitterPos(p, (const Vec_021F6560 *)&c);
    else
        BUTTON_MAN_SetEmitterPos(p, (const Vec_021F6560 *)&a);
    func_020307B0(r);
}

#undef MUL

#undef MUL

#undef MUL

#undef MUL

#undef MUL

#undef MUL

#undef MUL

#undef MUL

#undef MUL

#undef MUL

#undef MUL

#undef MUL

#undef MUL

#define MUL(a,b) ((int)(((long long)(a) * (b) + 0x800) >> 12))

/*
 * The 5 and default arms are separate `else if` / `else` blocks with the
 * whole MUL repeated; the compiler cross-jumps their common tail, and the
 * 0 high word of the rounding addend stays CSE'd in r4 across all three
 * arms (a ternary index colours it differently).
 * Caller func_021FD1CC (same lane) shows s is a 0x60 object: 3x3 matrix,
 * pos at 0x24, counters from 0x30.
 */
void func_021FD8CC(void *p, int active)
{
    VecFx32_021FD04C v;
    u16 a;
    u16 b;
    int *s;

    s = (int *)BUTTON_MAN_GetUserData(p);
    if (s[18] == 0 || active == 0)
        return;
    if (s[19] == 3) {
        if (s[20] != 0) {
            s[20]--;
            return;
        }
        s[22] += 0xc;
        s[21] += s[22];
        s[20] = s[21] >> 12;
    }
    s[18]--;
    s[14] += s[16];
    s[15] += s[17];
    a = (s[14] >> 12) + 0xc000;
    b = (s[15] >> 12) + 0xc000;
    v.x = FX_SinCosTable_[(a >> 4) * 2];
    v.x = MUL(v.x, s[12]);
    v.x += s[12];
    if (s[19] == 6) {
        v.z = FX_SinCosTable_[(b >> 4) * 2 + 1];
        v.z = MUL(v.z, s[13]);
        v.y = 0;
    } else if (s[19] == 5) {
        v.y = FX_SinCosTable_[(b >> 4) * 2 + 1];
        v.y = MUL(v.y, s[13]);
        v.z = 0;
    } else {
        v.y = FX_SinCosTable_[(a >> 4) * 2 + 1];
        v.y = MUL(v.y, s[13]);
        v.z = 0;
    }
    MTX_MultVec43((const Vec_021F6560 *)&v, s, (Vec_021F6560 *)&v);
    if (s[23] != 0)
        func_021FE1B8((VecFx32_021FE1B8 *)((Vec_021F6560 *)&v), (const VecFx32_021FE1B8 *)((const Vec_021F6560 *)0));
    BUTTON_MAN_SetEmitterPos(p, (const Vec_021F6560 *)&v);
}

void func_021FD9F0(void *p)
{
    State_021FD04C *s = (State_021FD04C *)func_02051774();

    if (s->k3c != 0 && s->k0c < 0)
        BUTTON_MAN_SetAngle(p, 0x800);
    BUTTON_MAN_SetUserData(p, (int)s);
    BUTTON_MAN_SetCallback(p, (int)func_021FDA28);
}

void func_021FDA28(void *p, int active)
{
    int *s;
    VecFx32_021FD04C v;
    s = (int *)BUTTON_MAN_GetUserData(p);
    if (active == 0)
        return;
    if (s[13] == 0) {
        if (s[10] == 0) {
            s[10] = s[11];
            if (s[0] & 1)
                s[6] -= s[7];
            else
                s[6] += s[7];
            s[6] = (u16)s[6];
            v.x = FX_SinCosTable_[(s[6] >> 4) * 2];
            v.x = MUL(v.x, s[4]);
            v.x += s[1];
            v.y = s[2];
            v.z = FX_SinCosTable_[(s[6] >> 4) * 2 + 1];
            v.z = MUL(v.z, s[5]);
            v.z += s[3];
            if (s[15] != 0)
                func_021FE1B8((VecFx32_021FE1B8 *)((Vec_021F6560 *)&v), (const VecFx32_021FE1B8 *)((const Vec_021F6560 *)0));
            BUTTON_MAN_SetEmitterPos(p, (const Vec_021F6560 *)&v);
            if (s[8] != 0) {
                s[8]--;
            } else {
                s[8] = s[9];
                s[13] = s[14];
            }
        } else {
            s[10]--;
        }
    } else {
        s[13]--;
    }
}

void func_021FDB08(void *p)
{
    void *q = PARTICLE_GetWorkBase(p);

    PARTICLE_DeleteSystem(p);
    func_020307B0(q);
}

void func_021FDB20(BtlvEffVmWork *s)
{
    if (s->layoutMode == 1)
        func_021FF1B0((Work_021FF1B0 *)((void *)func_021F8694()));
    else
        func_021FF16C((Work_021FF16C *)((void *)func_021F8694()));
}

void func_021FDB40(u32 a0, int m, int a2, int a3, unsigned int e, unsigned int f, unsigned int g)
{
    if (m == 5) {
        GFL_USE_PlaySeDefaultVolume(a0);
        m = GFL_USE_GetSeSlot(a0);
    } else {
        GFL_USE_PlaySeInSlot((void *)a0, m);
    }
    NNS_SndHandleSetVolume((char *)GFL_USE_GetSeHandle(m), e);
    GFL_USE_SetSeSlotParams(m, -1, -1, a2);
    GFL_USE_SetSeSlotParams(m, -1, a3, -1);
    if (f) {
        NNS_SndHandleSetTrackModDepth((struct Obj_vD04C *)GFL_USE_GetSeHandle(m), 0xffff, f);
        NNS_SndHandleSetTrackModSpeed((struct Obj_vD04C *)GFL_USE_GetSeHandle(m), 0xffff, g);
    }
}

/*
 * leaves: parent-cleared ov094 getters 0x021F8730 and 0x021F8740 filed separately.
 * domain: selector values 0..57; out-of-range result is unspecified.
 */
int func_021FDBB0(BtlvEffVmWork *s, unsigned int key)
{
    switch (key) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        return func_021FFF0C((char *)func_021F8694(), key);
    case 8: return func_021FFF0C((char *)func_021F8694(), s->attackerPos);
    case 9: return s->params.kind;
    case 10: return s->params.variant;
    case 11: return s->params.option;
    case 12: return s->params.side;
    case 13: return s->params.argA;
    case 14: return s->params.argB;
    case 15: return s->params.typeCode;
    case 16: return s->scriptVar;
    case 17: return s->attackerPos;
    case 18: return func_021FF348((Work_021FF348 *)((void *)func_021F8694()), s->attackerPos);
    case 19: return s->attackerPos & 1;
    case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27:
        if (func_021FFF38((char *)func_021F8694(), key - 20) & 2)
            return 1;
        return 0;
    case 28:
        if (func_021FFF38((char *)func_021F8694(), s->attackerPos) & 2)
            return 1;
        return 0;
    case 29: case 30: case 31: case 32: case 33: case 34: case 35: case 36:
        return func_021FFF68((Work_021FFF68 *)((void *)func_021F8694()), key - 29);
    case 37: return func_021FFF68((Work_021FFF68 *)((void *)func_021F8694()), s->attackerPos);
    case 38: return func_021F8730();
    case 39: return func_021F8710();
    case 40: case 41: case 42: case 43: return func_021F8740(key - 40);
    case 44: case 45: case 46: case 47: case 48: case 49: case 50: case 51:
        return func_021FFFAC((Work_021FFFAC *)((void *)func_021F8694()), key - 44);
    case 52: return func_021FFFAC((Work_021FFFAC *)((void *)func_021F8694()), s->attackerPos);
    case 53: return s->flags.bit.cameraOffset;
    case 54: return s->camVecSaved;
    case 55: return s->scratchVar;
    case 56: return s->flags.bit.cameraLocked;
    case 57: return s->defenderPos;
    }
}

/*
 * lever: declare count before n to place them at sp+0x18 and sp+0x14;
 *   reversed declarations produced five differing spill/reload bytes.
 */
void func_021FDD60(BtlvEffVmWork *s, Rec_021FDD60 *r, int slot, int arg)
{
    int targets[8];
    int keys[8];
    int count;
    int n;
    int i;
    Rec_021FDD60 *p;

    if (r->v[2] == r->v[1] && (u32)(r->v[2] - 11) <= 1) {
        if (r->v[2] == 12)
            r->v[22] = 1;
        count = func_021FCD14(s, 16, targets);
        if (count != 0) {
            for (i = 0; i < count; i++) {
                p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c0e);
                *p = *r;
                p->v[1] = targets[i];
                p->v[2] = targets[i];
                if (PARTICLE_StartEffectWithCallback(s->emitters[slot], arg, (int)func_021FD1CC, (int)p) == -1)
                    func_020307B0(p);
            }
        }
    } else if (r->v[2] == r->v[1] && s->params.kind == 12 && !s->flags.bit.fallbackScript && s->effectId != 0x16e && (u32)(r->v[2] - 9) <= 1) {
        if (r->v[2] == 10)
            r->v[22] = 1;
        switch (func_021F8710()) {
        default:
        case 0: case 3:
            keys[0] = s->attackerPos;
            n = 1;
            break;
        case 1:
            keys[0] = (s->attackerPos & 1) ? 1 : 0;
            n = 1;
            break;
        case 2:
            keys[0] = (s->attackerPos & 1) ? 19 : 18;
            keys[1] = (s->attackerPos & 1) ? 21 : 20;
            n = 2;
            break;
        }
        if (n != 0) {
            for (i = 0; i < n; i++) {
                p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c45);
                *p = *r;
                p->v[1] = keys[i];
                p->v[2] = keys[i];
                if (PARTICLE_StartEffectWithCallback(s->emitters[slot], arg, (int)func_021FD1CC, (int)p) == -1)
                    func_020307B0(p);
            }
        }
    } else {
        p = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c56);
        *p = *r;
        if (PARTICLE_StartEffectWithCallback(s->emitters[slot], arg, (int)func_021FD1CC, (int)p) == -1)
            func_020307B0(p);
    }
}

int func_021FDFA0(void *a, BtlvEffVmWork *s, int mode)
{
    int *p;
    int idx;
    int x;
    int y;
    int flags;

    idx = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    x = VM_GetU32(a);
    flags = 0;
    (int *)s->allocBuffers[s->allocBufferCount] = func_02030734((u16)((s->heapId & 0x7fff) | 0x8000), 0x40, 0, d_0220AE68, 0x1c79);
    p = (int *)s->allocBuffers[s->allocBufferCount];
    s->allocBufferCount += 1;
    p[0] = VM_GetU32(a);
    p[4] = VM_GetU32(a);
    p[5] = VM_GetU32(a);
    y = VM_GetU32(a);
    p[6] = 0;
    p[9] = p[8] = VM_GetU32(a);
    p[10] = 0;
    p[11] = VM_GetU32(a);
    p[12] = VM_GetU32(a);
    p[13] = 0;
    p[14] = VM_GetU32(a);
    p[7] = _s32_div_f(0x10000, p[8]);
    p[15] = mode;
    if (idx == 16)
        goto end;
    if (mode == 1) {
        if (BUTTON_MAN_GetBlock(s->emitters[idx]) == 0) {
            Desc_021F6560 desc;
            Vec_021F6560 zero = {0, 0, 0};
            Vec_021F6560 v1;
            Vec_021F6560 v2;
            v1 = d_02209E10;
            v2 = d_02209DB4;
            desc.v[0] = 2;
            desc.v[1] = 0x3000;
            desc.v[2] = 0xffffd000;
            desc.v[3] = 0xffffc000;
            desc.v[4] = 0x4000;
            desc.v[5] = 0x1000;
            desc.v[6] = 0x200000;
            desc.v[7] = 0x1000;
            PARTICLE_InitCamera((struct Dst648 *)(s->emitters[idx]), (struct Src648 *)&desc, 0x2000, (int *)&zero, (int *)&v1, (int *)&v2, (s->heapId & 0x7fff) | 0x8000);
        }
    }
    switch (p[0]) {
    case 0:
    case 1:
        flags = func_021FCF2C((int)a, 14);
        func_021FF3F4((void *)func_021F8694(), &p[1], flags);
        break;
    case 2:
    case 3:
        flags = func_021FCF2C((int)a, 16);
        func_021FF3F4((void *)func_021F8694(), &p[1], flags);
        break;
    case 4:
    case 5:
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        break;
    }
    if (flags & 1)
        p[6] = 0x8000;
    p[2] += y;
    if (PARTICLE_StartEffectWithCallback((int *)s->emitters[idx], x, (int)func_021FD9F0, (int)p) == -1)
        func_020307B0(p);
end:
    return s->result;
}

void func_021FE1B8(VecFx32_021FE1B8 *v, const VecFx32_021FE1B8 *ofs)
{
    fx32 w;
    MtxFx44 m;

    MTX_Copy43To44_(&g_renderStateDrawParams, &m);
    MTX_Concat44(&m, &SCREENTEX_ProjectionMatrix, &m);
    if (ofs != 0) {
        v->x += ofs->x;
        v->y += ofs->y;
        v->z += ofs->z;
    }
    func_021FE254((const VecFx32 *)((const VecFx32_021FE1B8 *)v), &m, (fx32 *)((VecFx32_021FE1B8 *)v), &w);
    v->x = FX_MUL(FX_Div(v->x, w), 0x4000);
    v->y = FX_MUL(FX_Div(v->y, w), 0x3000);
    v->z = -v->z;
}

void func_021FE254(const VecFx32 *v, const MtxFx44 *m, fx32 *out, fx32 *w)
{
    fx64 y = v->y;
    fx64 x = v->x;
    fx64 z = v->z;
    fx64 t;

    t = z * m->m[2][0] + (x * m->m[0][0] + y * m->m[1][0]);
    out[0] = (fx32)(t >> 12) + m->m[3][0];
    t = z * m->m[2][1] + (x * m->m[0][1] + y * m->m[1][1]);
    out[1] = (fx32)(t >> 12) + m->m[3][1];
    t = z * m->m[2][2] + (x * m->m[0][2] + y * m->m[1][2]);
    out[2] = (fx32)(t >> 12) + m->m[3][2];
    t = z * m->m[2][3] + (x * m->m[0][3] + y * m->m[1][3]);
    *w = (fx32)(t >> 12) + m->m[3][3];
}

/*
 * Levers: v and k unsigned (bhi/bhs/blo compares); the middle arm is
 * `mode != 8` and the mode==8 arm last, which puts its block after the
 * cross-jumped func_022003C4 call.
 */
unsigned int func_021FE38C(BtlvEffVmWork *p, unsigned int k)
{
    int mode = p->typeSource;
    unsigned int v;

    if (mode == 9)
        v = func_022003C4((char *)func_021F8694(), p->attackerPos);
    else if (mode != 8)
        v = func_022003C4((char *)func_021F8694(), mode);
    else
        v = PALANM_GetPairedCodeForFirst(p->params.typeCode);
    if (v == 0 || v > 0x19)
        v = 4;
    v--;
    switch (k) {
    case 3:
        k += v;
        break;
    case 0x1d:
        if (v + 1 == 0x19)
            v = 0x10;
        else if (v + 1 >= 0x10)
            v = 3;
        k += v;
        break;
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
        k += v << 2;
        break;
    }
    return k;
}

/*
 * Sets/clears the fading and fadeRestart flags of *o, allocates a 0x10-byte record
 * (heap from heapId), converts n to fx32 (n<<12, +-0.5 rounding)
 * and registers func_021FE768 as a task callback through func_02030DA8.
 */
void func_021FE410(BtlvEffVmWork *o, int a, int b, int n)
{
    Rec_vE254 *r;
    int fx;

    if (a > b) {
        if (o->flags.bit.fading) {
            o->flags.bit.fadeRestart = 1;
            return;
        }
        o->flags.bit.fading = 1;
    } else {
        o->flags.bit.fading = 0;
    }
    r = func_02030734((u16)(((u16)o->heapId & 0x7fff) | 0x8000), 0x10, 0, d_0220AE68, 0x1d78);
    r->a = a;
    r->b = b;
    r->fl = &o->flags;
    if (n > 0)
        fx = _ffix(_fadd(0.5f, _fflt(n << 12)));
    else
        fx = _ffix(_fsub(_fflt(n << 12), 0.5f));
    func_021F9154(r->a, r->b, r->v, fx);
    func_021F896C((void *)func_02030DA8((void *)o->owner, func_021FE768, r, 0), 0, 1);
}

int func_021FE4D0(BtlvEffVmWork *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (p->seVoiceIds[i] == -1)
            break;
    }
    if (i == 6)
        i = 0;
    return i;
}

void func_021FE4F8(void *unused)
{
    Key_021FD04C i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)func_021F8694(), i) == 1)
            func_022004BC((Work_022004BC *)((void *)func_021F8694()), i);
    }
}

void func_021FE520(void *unused)
{
    Key_021FD04C i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)func_021F8694(), i) == 1)
            func_021FF470((char *)func_021F8694(), i, 0);
    }
}

void func_021FE54C(void *h, void *arg)
{
    int *s = arg;

    if (--s[4] == 0) {
        func_021FDB40(s[1], s[2], s[3], s[5], s[6], s[7], s[8]);
        func_021F89BC(h);
    }
}

void func_021FE580(void *h)
{
    unsigned int *p = *((unsigned int **)TCBL_GetTaskUserData(h));

    *p &= ~4u;
}

/*
 * trailing: two zero alignment bytes at 0x021FE68E.
 */
void func_021FE594(void *h, void *arg)
{
    int *s = arg;

    int done;
    int v;
    done = 0;
    if (s[8] != 0) {
        s[8]--;
        return;
    }
    if (s[11] == 0) {
        s[11] = s[12];
        s[6] += s[7];
        v = s[6] >> 12;
        if (s[13] & 1) {
            if (s[7] < 0) {
                if (v < s[4])
                    v = s[4];
            } else {
                if (v > s[4])
                    v = s[4];
            }
        } else {
            if (s[7] < 0) {
                if (v < s[5])
                    v = s[5];
            } else {
                if (v > s[5])
                    v = s[5];
            }
        }
        if (v > 0)
            s[6] = _ffix(_fadd(0.5f, _fflt(v << 12)));
        else
            s[6] = _ffix(_fsub(_fflt(v << 12), 0.5f));
        switch (s[3]) {
        case 0: GFL_USE_SetSeSlotParams(s[1], -1, v, -1); break;
        case 1: NNS_SndHandleSetVolume((char *)GFL_USE_GetSeHandle(s[1]), v); break;
        case 2: GFL_USE_SetSeSlotParams(s[1], -1, -1, v); break;
        }
        if (s[9] == 0) {
            s[9] = s[10];
            switch (s[2]) {
            case 0: done = 1; break;
            case 1:
                s[13]--;
                if (s[13] != 0)
                    s[7] *= -1;
                else
                    done = 1;
                break;
            }
        } else {
            s[9]--;
        }
    } else {
        s[11]--;
    }
    if (done == 1)
        func_021F89BC(h);
}

void func_021FE690(void *h)
{
    unsigned int *p = *((unsigned int **)TCBL_GetTaskUserData(h));

    *p &= ~8u;
}

void func_021FE6A4(void *h, void *arg)
{
    Req *r = arg;

    int slot;
    BtlvEffVmWork **cell;

    r->cnt--;
    if (r->cnt != 0)
        return;
    slot = func_021FE4D0(r->obj);
    r->obj->seVoiceIds[slot] =
        func_02200218((Work_02200218 *)((char *)func_021F8694()), r->a1, r->a2, r->a3, r->a4, r->a5, r->a6);
    func_021FE410(r->obj, 0x7f000, 0x6b000, 10);
    if (!r->obj->flags.bit.fadeRestart) {
        cell = func_02030734((u16)(((u16)r->obj->heapId & 0x7fff) | 0x8000), 4, 0, d_0220AE68, 0x1e6d);
        *cell = r->obj;
        func_021F896C((void *)func_02030DA8((void *)r->obj->owner, func_021FE8D8, cell, 0), 0, 0);
    }
    func_021F89BC(h);
}

void func_021FE750(void *h)
{
    unsigned int *p = *((unsigned int **)TCBL_GetTaskUserData(h));

    *p &= ~0x800u;
}

void func_021FE768(void *h, void *arg)
{
    int *s = arg;

    int flag = 1;

    func_021F9220(&s[1], &s[3], &s[2], &flag);
    func_0200F698((void *)0xffff, (void *)(s[1] >> 12));
    if (flag)
        func_021F89BC(h);
}

static inline void window0(int x1, int y1, int x2, int y2)
{
    REG16(0x04000040) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000044) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

static inline void window1(int x1, int y1, int x2, int y2)
{
    REG16(0x04000042) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000046) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

/*
 * volatile: WININ re-read at 0x021FE7BE; WINOUT and display register accesses.
 */
void func_021FE79C(void *h, void *arg)
{
    int *s = arg;

    switch (s[1]) {
    case 0:
        REG16(0x04000048) = (u16)((REG16(0x04000048) & ~0x3f) | (u8)s[5]);
        REG16(0x04000048) = (u16)((REG16(0x04000048) & ~0x3f00) | (u16)(s[5] << 8));
        REG16(0x0400004a) = (u16)((REG16(0x0400004a) & ~0x3f) | ((s[5] & 0xff00) >> 8));
        REG32(0x04000000) = (REG32(0x04000000) & ~0xe000) | 0x6000;
        REG16(0x04000042) = 0;
        REG16(0x04000046) = 0;
        s[1]++;
    case 1:
        if (s[7] == 0) {
            s[7] = s[8];
            switch (s[2]) {
            case 0: s[4] -= 0x100; s[4]++; break;
            case 1: s[4] += 0x100; s[4]--; break;
            case 2: s[3] -= 0x100; s[3]++; break;
            case 3: s[3] += 0x100; s[3]--; break;
            }
            window0(s[3] >> 8, s[4] >> 8, s[3], s[4]);
            if ((u8)s[3] == 0xff) {
                window1(1, s[4] >> 8, 0, s[4]);
            } else {
                window1(0, 0, 0, 0);
            }
            s[6]--;
            if (s[6] == 0)
                func_021F89BC(h);
        } else {
            s[7]--;
        }
        break;
    }
}

void func_021FE8AC(void *h)
{
    Ctx_021FE254 *c = (Ctx_021FE254 *)TCBL_GetTaskUserData(h);

    if (c->k24 == 0)
        *(volatile unsigned int *)0x04000000 &= ~0xE000u;
    *c->reg &= ~0x100u;
}

void func_021FE8D8(void *h, void *arg)
{
    BtlvEffVmWork **pp = arg;

    int i;

    for (i = 0; i < 6; i++) {
        if ((*pp)->seVoiceIds[i] != -1) {
            if (PM_VOICE_IsActive((*pp)->seVoiceIds[i]) != 0)
                return;
            (*pp)->seVoiceIds[i] = -1;
        }
    }
    func_021FE410(*pp, 0x6b000, 0x7f000, 10);
    (*pp)->flags.bit.fadeRestart = 0;
    func_021F89BC(h);
}

/*
 * Lever: the `mask |= 1 << i` tail is written out in both arms (then-arm
 * innermost, and the else arm); the compiler cross-jumps them and leaves the
 * `b` to the next instruction.  A single shared tail (goto/continue) gives no
 * `b` and hoists r7/r4 in the other order.
 */
void func_021FE930(void *h, void *arg)
{
    Arg_vE254 *a = arg;

    int i = 1;
    int want;

    if (a->side == 0)
        i = 0;
    if (a->side != 0)
        want = 0xaa;
    else
        want = 0x55;
    while (i <= 7) {
        if (func_021F7F1C(i)) {
            if (func_021FFCB0((Work_021FFCB0 *)((char *)func_021F8694()), i) == 0) {
                if ((func_021F935C(i) & a->mask) == 0) {
                    func_021FF304((Work_021FF228 *)((char *)func_021F8694()), i, 0);
                    func_021FF470((char *)func_021F8694(), i, 0);
                    a->mask |= func_021F935C(i);
                }
            }
        } else {
            a->mask |= func_021F935C(i);
        }
        i += 2;
    }
    if (want == a->mask)
        func_021F89BC(h);
}

void func_021FE9BC(void *h, void *arg)
{
    Ctx_021FE9BC *c = arg;

    u16 line = *(volatile u16 *)0x04000006;

    if (line >= 0xc0 && line <= 0xc8) {
        PARTICLE_ApplyLoadHandlers(c->obj);
        *c->reg &= ~0x10000u;
        func_021F89BC(h);
    }
}

/*
 * Lever: the loop counter is an enum (keeps the `cmp r4,#8; bge` entry guard
 * and the unfolded (1<<12)>>1 rounding constants after it), see
 * docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 */
void func_021FE9F0(fx32 a, fx32 b, int n, int f48, int f4c)
{
    Slot_021FD04C i;
    VecFx32 v;
    fx32 s;
    fx32 t;

    func_021FF134((char *)func_021F8694(), a, b);
    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)func_021F8694(), i)) {
            s = func_021FF468((void *)func_021F8694(), i, 1);
            if (i & 1)
                t = (fx32)(((fx64)s * b + ((fx64)(1 << 12) >> 1)) >> 12);
            else
                t = (fx32)(((fx64)s * a + ((fx64)(1 << 12) >> 1)) >> 12);
            v.x = t;
            v.y = t;
            v.z = 1 << 12;
            func_021FF630((Work_021FF630 *)((char *)func_021F8694()), i, 1, (VecFx32_vF5B0 *)&v, n, f48, f4c);
        }
    }
}

int func_021FEAA0(int v)
{
    unsigned int i;

    for (i = 0; i < 11; i++) {
        if (v == d_02209DD8[i])
            return 1;
    }
    return 0;
}
