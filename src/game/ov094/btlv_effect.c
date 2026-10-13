/*
 * file:     btlv_effect.c
 * unit:     yes
 * function: func_021F73F0, func_021F745C, func_021F7544, func_021F7808, func_021F78E4, func_021F7998, func_021F7A28, func_021F7AAC, func_021F7B2C, func_021F7BEC, func_021F7C0C, func_021F7C2C, func_021F7CE4, func_021F7CFC, func_021F7D44, func_021F7D80, func_021F7E38, func_021F7E74, func_021F7E84, func_021F7E94, func_021F7EA4, func_021F7EB4, func_021F7EE8, func_021F7F04, func_021F7F1C, func_021F7F58, func_021F8010, func_021F803C, func_021F8090, func_021F80E4, func_021F80FC, func_021F8118, func_021F8134, func_021F8150, func_021F8168, func_021F8180, func_021F8198, func_021F81B4, func_021F81D0, func_021F81EC, func_021F8204, func_021F821C, func_021F823C, func_021F8260, func_021F827C, func_021F8298, func_021F8324, func_021F839C, func_021F8414, func_021F84B4, func_021F84D0, func_021F84E8, func_021F8504, func_021F8524, func_021F853C, func_021F8554, func_021F8628, func_021F8678, func_021F8684, func_021F8694, func_021F86A4, func_021F86B4, func_021F86C4, func_021F86D4, func_021F86E0, func_021F86F0, func_021F8700, func_021F8710, func_021F8720, func_021F8730, func_021F8740, func_021F8754, func_021F8764, func_021F8774, func_021F878C, func_021F87D4, func_021F87EC, func_021F882C, func_021F883C, func_021F8884, func_021F88A8, func_021F88BC, func_021F88E0, func_021F88F4, func_021F8914, func_021F8934, func_021F896C, func_021F899C, func_021F89BC, func_021F8A10, func_021F8A40, func_021F8A78, func_021F8AC0, func_021F8AE8, func_021F8AFC, func_021F8B10, func_021F8B28, func_021F8B40, func_021F8B6C, func_021F8B90, func_021F8BAC, func_021F8C78, func_021F8CB0, func_021F8EF8, func_021F8F30, func_021F8FB0, func_021F8FE8, func_021F9028, func_021F903C, func_021F9154, func_021F918C, func_021F9220, func_021F9260, func_021F935C, func_021F9364
 * address:  0x021F73F0
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
 *   sub_02030734 0x02030734 arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   G3D_SYSTEM_GetResourceFile 0x02046F48 arm
 *   NNS_G3dGetTex 0x0206E964 arm
 *   sub_020307B0 0x020307B0 arm
 *   func_020307B0  0x020307B0  arm
 *   func_0207C768  0x0207C768  arm
 *   d_0220AC90     0x0220AC90  data   ov094  a1
 *   BTL_MAIN_IsMultiMode 0x021B86C8 thumb ov093
 *   BTL_MAIN_IsOwnClientSecondTeam 0x021B8FE4 thumb ov093
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTL_MAIN_GetOwnPartnerClient 0x021B9000 thumb ov093
 *   BTL_MAIN_GetTrainerType 0x021BA020 thumb ov093
 *   BTL_MAIN_GetOwnOpponentClient 0x021B904C thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_GetFieldSituation 0x021B8714 thumb ov093
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   d_0220AF20     0x0220AF20  data   a4
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   BTL_MAIN_CheckSetupStatusFlag  0x021BA1A8  thumb  ov093
 *   func_0201493C  0x0201493C  thumb
 *   G3D_SYSTEM_SetLight  0x02046A94  arm
 *   BTLV_TIMER_Create  0x02209224  thumb  ov094
 *   BTLV_BG_Create  0x0220975C  thumb  ov094
 *   PARTICLE_InitManager  0x02050B80  arm
 *   func_020056A0  0x020056A0  thumb
 *   PM_VOICE_AllocBuffers  0x02006674  thumb
 *   PM_VOICE_FreeBuffers 0x020066E8 thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   BTLV_TIMER_Delete 0x022092E8 thumb ov094
 *   BTLV_BG_Delete 0x0220977C thumb ov094
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_02030D28  0x02030D28  arm
 *   func_02047964  0x02047964  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   PARTICLE_Main  0x02050BE8  arm
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 *   func_02030DA8  0x02030DA8  arm
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   d_02209D0C     0x02209D0C  data   ov094  a1
 *   BTLV_GAUGE_StartHpChangeAnimated  0x02207B4C  thumb  ov094
 *   BTLV_GAUGE_StartHpChangeInstant  0x02207B68  thumb  ov094
 *   BTLV_GAUGE_StartExpGain 0x02207B84 thumb ov094
 *   BTLV_GAUGE_RefreshForLevelUp 0x02207BAC thumb ov094
 *   BTLV_GAUGE_RequestStop 0x022089AC thumb ov094
 *   BTLV_GAUGE_IsAnimating 0x02207C94 thumb ov094
 *   BTLV_GAUGE_SetSideVisible 0x02207CC4 thumb ov094
 *   BTLV_GAUGE_SetSlotVisible  0x02207D04  thumb  ov094
 *   BTLV_GAUGE_SetStatusIcon  0x02208814  thumb  ov094
 *   BTLV_GAUGE_SelectSlot 0x02208870 thumb ov094
 *   BTLV_GAUGE_IsSlotOccupied 0x02207D60 thumb ov094
 *   BTLV_GAUGE_GetSlotHealthInfo 0x02208958 thumb ov094
 *   BTLV_B_GAUGE_CreatePartyBallBar  0x02208DAC  thumb  ov094
 *   BTLV_B_GAUGE_DeletePartyBallBar 0x02209068 thumb ov094
 *   BTLV_B_GAUGE_IsPartyBallBarActive 0x022090A4 thumb ov094
 *   PALANM_RequestFade  0x0202173C  thumb
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   func_02040588  0x02040588  arm
 *   BTLV_TIMER_Start 0x02209318 thumb ov094
 *   BTLV_TIMER_SetVisible  0x022094BC  thumb  ov094
 *   BTLV_TIMER_IsExpired  0x02209500  thumb ov094
 *   g_0220AF20  0x0220AF20  data
 *   BTLV_GAUGE_IsLowHpBgmPlaying 0x022088F4 thumb ov094
 *   BTLV_GAUGE_SetLowHpBgmPlaying  0x02208900  thumb  ov094
 *   BTLV_GAUGE_SetLowHpBgmSuppressed  0x0220893C  thumb  ov094
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   BTLV_GAUGE_SetSavedBgmNo  0x02208918  thumb  ov094
 *   BTLV_GAUGE_SetBgmReplaced  0x02208924  thumb  ov094
 *   BTL_MAIN_IsRecordEnabledInComm 0x021BA1EC thumb ov093
 *   BTL_MAIN_IsRecordAllowed 0x021BA20C thumb ov093
 *   sub_02030EAC   0x02030EAC  arm
 *   TCBL_IsDeletePending   0x02030EE8  arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   d_0220AC70 0x0220AC70 data a4
 *   d_0220AC78 0x0220AC78 data a4
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_0203F0A8 0x0203F0A8 arm
 *   FX_Div_Alt  0x0207C768  arm
 *   PALANM_BlendColors  0x02021F64  thumb
 *   func_02061CA4  0x02061CA4  arm
 *   func_021F882C 0x021F882C thumb ov094
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021F89BC 0x021F89BC thumb ov094
 *   func_021F918C 0x021F918C thumb ov094
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_021F6560 0x021F6560 thumb ov094
 *   func_021F6898 0x021F6898 thumb ov094
 *   func_021F6934 0x021F6934 thumb ov094
 *   func_021F69B0 0x021F69B0 thumb ov094
 *   func_021F69E8 0x021F69E8 thumb ov094
 *   func_021F6A18 0x021F6A18 thumb ov094
 *   func_021F6A28 0x021F6A28 thumb ov094
 *   func_021F6AD0 0x021F6AD0 thumb ov094
 *   func_021F6B04 0x021F6B04 thumb ov094
 *   func_021F6CF0 0x021F6CF0 thumb ov094
 *   func_021F6D5C 0x021F6D5C thumb ov094
 *   func_021F6DD4 0x021F6DD4 thumb ov094
 *   func_021F6DEC 0x021F6DEC thumb ov094
 *   func_021F6E1C 0x021F6E1C thumb ov094
 *   func_021F6E2C 0x021F6E2C thumb ov094
 *   func_021F6E3C 0x021F6E3C thumb ov094
 *   func_021F6EC0 0x021F6EC0 thumb ov094
 *   func_021F6ED4 0x021F6ED4 thumb ov094
 *   func_021F6EDC 0x021F6EDC thumb ov094
 *   func_021F6F48 0x021F6F48 thumb ov094
 *   func_021F93F4 0x021F93F4 thumb ov094
 *   func_021F9478 0x021F9478 thumb ov094
 *   func_021F94D8 0x021F94D8 thumb ov094
 *   func_021F94F8 0x021F94F8 thumb ov094
 *   func_021F97E4 0x021F97E4 thumb ov094
 *   func_021F9814 0x021F9814 thumb ov094
 *   func_021F9844 0x021F9844 thumb ov094
 *   func_021F9858 0x021F9858 thumb ov094
 *   func_021F9948 0x021F9948 thumb ov094
 *   func_021F9A7C 0x021F9A7C thumb ov094
 *   func_021F9AA4 0x021F9AA4 thumb ov094
 *   func_021FEAC0 0x021FEAC0 thumb ov094
 *   func_021FEB78 0x021FEB78 thumb ov094
 *   func_021FEBAC 0x021FEBAC thumb ov094
 *   func_021FEE9C 0x021FEE9C thumb ov094
 *   func_021FEEA8 0x021FEEA8 thumb ov094
 *   func_021FF088 0x021FF088 thumb ov094
 *   func_021FF0F8 0x021FF0F8 thumb ov094
 *   func_021FF144 0x021FF144 thumb ov094
 *   func_021FF16C 0x021FF16C thumb ov094
 *   func_021FF348 0x021FF348 thumb ov094
 *   func_021FF374 0x021FF374 thumb ov094
 *   func_021FF3F4 0x021FF3F4 thumb ov094
 *   func_021FF7B0 0x021FF7B0 thumb ov094
 *   func_021FF924 0x021FF924 thumb ov094
 *   func_021FFBBC 0x021FFBBC thumb ov094
 *   func_021FFCB0 0x021FFCB0 thumb ov094
 *   func_021FFD6C 0x021FFD6C thumb ov094
 *   func_021FFD9C 0x021FFD9C thumb ov094
 *   func_021FFDB4 0x021FFDB4 thumb ov094
 *   func_021FFE48 0x021FFE48 thumb ov094
 *   func_021FFF38 0x021FFF38 thumb ov094
 *   func_022001DC 0x022001DC thumb ov094
 *   func_02200344 0x02200344 thumb ov094
 *   func_022003EC 0x022003EC thumb ov094
 *   func_0220055C 0x0220055C thumb ov094
 *   func_02200608 0x02200608 thumb ov094
 *   func_02201A8C 0x02201A8C thumb ov094
 *   func_02201AC4 0x02201AC4 thumb ov094
 *   func_02201AF0 0x02201AF0 thumb ov094
 *   func_02206BC8 0x02206BC8 thumb ov094
 *   func_02206E28 0x02206E28 thumb ov094
 *   func_02206EB4 0x02206EB4 thumb ov094
 *   func_022070C0 0x022070C0 thumb ov094
 *   func_02207288 0x02207288 thumb ov094
 *   func_02207960 0x02207960 thumb ov094
 */
#include "btlv_effvm_types.h"
#include "btlv_stage_shared_types.h"
#include "btlv_field_shared_types.h"
#include "btlv_camera_shared_types.h"
#include "btlv_effect_shared_types.h"

#define REG_04000604 (*(volatile u16 *)0x04000604)

struct Obj02021EE4;

struct S02021D50;

typedef struct {
    int w[4];
} Q_v6560;

typedef struct {
    int f0;
    int f4;
    Q_v6560 q;            /* 0x08 */
    u16 h[4];       /* 0x18 */
    int f20;
    int f24;
    int f28;
} Obj_v6560;

typedef struct {
    int f0;          /* 0x00 */
    int f4;          /* 0x04 */
    int f8;          /* 0x08 */
    int fc;          /* 0x0c */
    u8 f10;          /* 0x10 */
    u8 f11;          /* 0x11 */
    u16 f12;         /* 0x12 */
    u8 f14;          /* 0x14 */
    u8 f15;          /* 0x15 */
    char pad16[0x28 - 0x16];
    void *battle;    /* 0x28 */
} Param;

typedef struct {
    void *owner;     /* 0x000 */
    void *buf;       /* 0x004 */
    char pad08[0x188 - 8];
    void *h188;      /* 0x188 */
    int h18c;        /* 0x18c */
    void *h190;      /* 0x190 */
    void *h194;      /* 0x194 */
    void *h198;      /* 0x198 */
    void *h19c;      /* 0x19c */
    void *h1a0;      /* 0x1a0 */
    void *h1a4;      /* 0x1a4 */
    char pad1a8[8];
    void *h1b0;      /* 0x1b0 */
    void *h1b4;      /* 0x1b4 */
    void *h1b8;      /* 0x1b8 */
    Param param;     /* 0x1bc */
    int f1e8;        /* 0x1e8 */
    char pad1ec[4];
    u16 heap;        /* 0x1f0 */
    char pad1f2[6];
    int slots[8];    /* 0x1f8 */
    char pad218[0x244 - 0x218];
    int f244;        /* 0x244 */
    int f248;        /* 0x248 */
} Work_v6560;

typedef struct {
    u8 f0;
    u8 f1;
    u8 a2[0x13 - 2];
    u8 a13[0x24 - 0x13];
} Entry_021F7208;

typedef struct {
    s16_021F6560 x;
    s16_021F6560 y;
    s16_021F6560 z;
    u16 w;
} Rect;

typedef struct BtlvEff {
    void *owner;                /* 0x000 */
    void *buf;                  /* 0x004 */
    void *handle[32];           /* 0x008 */
    void (*cb[32])(void *);     /* 0x088 */
    int arg[32];                /* 0x108 */
    void *h188;                 /* 0x188 */
    void *h18c;
    void *h190;                 /* 0x190 */
    void *h194;
    void *h198;
    void *h19c;
    void *h1a0;
    void *h1a4;
    void *h1a8[2];              /* 0x1a8 */
    void *h1b0;                 /* 0x1b0 */
    void *h1b4;
    void *h1b8;
    int mode;                   /* 0x1bc */
    int f1c0;
    char pad1c4[0x10];
    unsigned short f1d4[4];                /* 0x1d4 */
    int f1dc;
    int f1e0;
    void *param_battle;         /* 0x1e4 */
    int f1e8;                   /* 0x1e8 */
    unsigned int m0 : 8;                 /* 0x1ec */
    unsigned int m1 : 8;
    unsigned int m2 : 2;
    unsigned int v : 8;
    unsigned int b26 : 1;
    unsigned short heap;                   /* 0x1f0 */
    char pad1f2[2];
    int f1f4;                   /* 0x1f4 */
    int slots[8];               /* 0x1f8 */
    unsigned int tbl[8];                 /* 0x218 */
    int f238;                   /* 0x238 */
    int f23c;
    int f240;
    int f244;
    int f248;
} BtlvEff;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
} Job_021F7998;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
} Job_021F7A28;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
} Job_021F7AAC;

typedef struct {
    u8 b0, b1, b2;
} Small;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    Small *s;           /* 0x10 */
} Job_021F7B2C;

typedef struct {
    u16 h0;
    int f4;
    int f8;
    u8 c;               /* 0x0c */
    u8 d;               /* 0x0d */
    int f10;
} Req_021F7208;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} Job_021F7208;

typedef struct {
    int w[3];
    unsigned short v;
} Req_021F7D44;

typedef struct {
    int f0;
    int f4;
    int buf[9];         /* 0x08 */
} Job_021F7D80;

typedef struct {
    int state;              /* 0 */
    u8 b;                   /* 4 */
    int c;                  /* 8 */
    int d;                  /* 0xC */
} St;

typedef struct { int x, y, z; } VecFx32_021F8204;

typedef struct {
    int pad0;
    int a;              /* 4 */
    u32 b;              /* 8 */
    u32 c;              /* 0xC */
    void *d;            /* 0x10 */
} Arg_v8204;

typedef struct {
    char pad[0x2C];
    u32 w2c;            /* 0x2C */
    u16 h30;            /* 0x30 */
    char pad2[6];
    u32 o38;            /* 0x38 */
} Q_v8204;

extern void *sub_02030734(u32, u32, int, const char *, u16);

extern void *ARC_TOOL_LoadMember(u32, u32, u32);

extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);

extern unsigned char *NNS_G3dGetTex(unsigned char *p);

extern u32 sub_020307B0(void *p);

extern u32 func_020307B0(void *p);

extern u32 func_0207C768(u32 a, u32 b);

extern int BTL_MAIN_IsMultiMode(unsigned char **p);

extern u8 BTL_MAIN_IsOwnClientSecondTeam(u8 *p);

extern u8 BTL_MAIN_GetOwnClientId(u8 *);

extern u8 BTL_MAIN_GetOwnPartnerClient(u8 *p);

extern u16 BTL_MAIN_GetTrainerType(char *, int);

extern u8 BTL_MAIN_GetOwnOpponentClient(u8 *p, int k);

extern u32 BTL_MAIN_GetRule(void **p);

extern void *BTL_MAIN_GetCompetitor(void ***);

extern char *BTL_MAIN_GetFieldSituation(char **);

extern unsigned func_02030CB0(unsigned);

extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);

extern void *PALANM_Create(u32 heap);

extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);

extern int BTL_MAIN_CheckSetupStatusFlag(char **p, int m);

extern void func_0201493C(u32 id, u32 a1, u32 a2, u32 a3, u32 b0, u16 *b1, u16 heap);

extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);

extern void *BTLV_TIMER_Create(u16 heap);

extern void *BTLV_BG_Create(void *a, u16 heap);

extern void PARTICLE_InitManager(u32);

extern void *func_020056A0(void (*)(void *, void *), void *, int);

extern void PM_VOICE_AllocBuffers(int n, u32 heap);

extern void PM_VOICE_FreeBuffers(void);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);

extern u32 PALANM_Delete(void *a0);

extern void BTLV_TIMER_Delete(void *);

extern void BTLV_BG_Delete(void *);

extern void PARTICLE_ExitManager(void);

extern void func_02030EAC(struct Node *n);

extern void func_02030DA4(void *);

extern void * func_02030D28(struct Ctx *c);

extern void func_02047964(void);

extern void G3D_SYSTEM_ApplyLookAt(void);

extern void PARTICLE_Main(void);

extern void G3D_SYSTEM_DrawEnd(void);

extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 n);

extern int WAZA_TOOL_GetDamageType(int);

extern void BTLV_GAUGE_StartHpChangeAnimated(char *p, int i, int n);

extern void BTLV_GAUGE_StartHpChangeInstant(char *p, int i, int n);

extern void BTLV_GAUGE_StartExpGain(void *, int, u32);

extern void BTLV_GAUGE_RefreshForLevelUp(void *, void *, int);

extern void BTLV_GAUGE_RequestStop(void *);

extern int BTLV_GAUGE_IsAnimating(u8 *p);

extern void BTLV_GAUGE_SetSideVisible(struct O *obj, int a, int c);

extern void BTLV_GAUGE_SetSlotVisible(struct O *obj, int a, int idx);

extern void BTLV_GAUGE_SetStatusIcon(struct O *obj, int k, int idx);

void BTLV_GAUGE_SelectSlot(void *w, int sel);

extern int BTLV_GAUGE_IsSlotOccupied(u8 *, int);

extern int BTLV_GAUGE_GetSlotHealthInfo(void *, int, int *, int *);

extern u32 BTLV_B_GAUGE_CreatePartyBallBar(u32 *p, u32 v);

extern void BTLV_B_GAUGE_DeletePartyBallBar(void *);

extern int BTLV_B_GAUGE_IsPartyBallBarActive(int *);

extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16_021F6560 step, u8 b, u8 c, u16 d, void *ctx);

extern u32 PALANM_GetFadeRequestBits(const char *ptr);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void BTLV_TIMER_Start(void *, int, int);

extern void BTLV_TIMER_SetVisible(u8 *p, int i, int a, int b);

extern int BTLV_TIMER_IsExpired(struct W *w, int i);

extern int BTLV_GAUGE_IsLowHpBgmPlaying(void *);

extern void BTLV_GAUGE_SetLowHpBgmPlaying(u32 obj, u32 v);

extern void BTLV_GAUGE_SetLowHpBgmSuppressed(u32 obj, u32 v);

extern int GFL_USE_PopBgm(void);

extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u16 b);

extern void BTLV_GAUGE_SetSavedBgmNo(char *p, int v);

extern void BTLV_GAUGE_SetBgmReplaced(void *o, u32 v);

extern int BTL_MAIN_IsRecordEnabledInComm(char **p);

extern int BTL_MAIN_IsRecordAllowed(char **p);

extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);

extern void sub_02030EAC(struct Node *n);

extern void CLACT_VBlankSystem(void);

extern void PALANM_TransferPalettes(struct S02021D50 *p);

extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);

extern u32 KEY_GetTrg(void);

extern int TOUCHPANEL_GetTrg(void);

extern u32 func_0203F0A8(void);

extern u32 FX_Div_Alt(u32 a, u32 b);

extern void PALANM_BlendColors(u16 *src, u16 *dst, u32 count, int weight, u16 color);

extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);

Obj_021F6560 *func_021F6560(int mode, int group, int variant, u16 heap);

void func_021F6898(Obj_021F6898 *o);

void func_021F6934(Obj_021F6934 *o);

void func_021F69B0(Obj_021F69B0 *p);

void func_021F69E8(S69E8 *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d);

int func_021F6A18(char *p);

void func_021F6A28(Obj_021F6A28 *o, u32 mode, u32 on);

int func_021F6AD0(Obj_021F6AD0 *p);

Obj_021F6B04 *func_021F6B04(int unused, int group, u8 variant, u16 heap);

void func_021F6CF0(Obj_021F6CF0 *o);

void func_021F6D5C(Obj_021F6D5C *o);

void func_021F6DD4(Obj_021F6DD4 *p);

void func_021F6DEC(S6DEC *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d);

int func_021F6E1C(char *p);

void func_021F6E2C(Obj_021F6E2C *o, u32 v);

Obj_021F6E3C *func_021F6E3C(int a, u16 b);

void func_021F6EC0(void **p);

void func_021F6ED4(int *p);

void func_021F6EDC(int *p, int *a, int *b);

void func_021F6F48(Cam_021F6F48 *c, VecFx32_v6560 *a, VecFx32_v6560 *b, int n, int s, int t);

Obj_v6560 *func_021F73F0(int a, int b, Q_v6560 *q, int c, u16 *h, int e, int f, u16 heap);

void *func_021F745C(u8 *p, int a, u16 heap);

void func_021F7544(Param *p, int arg, u16 heap);

void func_021F7808(void);

void func_021F78E4(void);

void func_021F7998(u32 a);

void func_021F7A28(int a, u32 b);

void func_021F7AAC(int a, int b, u32 c);

void func_021F7B2C(const Req_021F7208 *r);

void func_021F7BEC(void);

void func_021F7C0C(void);

void func_021F7C2C(int a, int b);

void func_021F7CE4(int a);

void func_021F7CFC(u32 a, u16 b, u8 c, int d, int e);

void func_021F7D44(int a, unsigned short b);

void func_021F7D80(void *a, int b);

void func_021F7E38(void *a, int b);

void func_021F7E74(u32 a);

void func_021F7E84(u32 a);

void func_021F7E94(int a);

void func_021F7EA4(u32 a);

int func_021F7EB4(void);

void func_021F7EE8(void *m, int key);

void func_021F7F04(int a);

int func_021F7F1C(int i);

void func_021F7F58(int a, u32 b, u32 c, u32 d, u32 e);

void func_021F8010(int a);

void func_021F803C(u32 a, void *m, u32 c);

void func_021F8090(u32 a, u32 b, u32 c);

void func_021F80E4(u32 a);

void func_021F80FC(u32 a, u32 b);

void func_021F8118(u32 a, u32 b);

void func_021F8134(int index, u32 amount);

void func_021F8150(int index, void *obj);

void func_021F8168(void);

int func_021F8180(void);

void func_021F8198(int a, int b);

void func_021F81B4(u32 a, u32 b);

void func_021F81D0(u32 a, u32 b);

void func_021F81EC(int sel);

int func_021F8204(int index);

int func_021F821C(int a, int *b, int *c);

void func_021F823C(u32 *p);

void func_021F8260(u32 i);

int func_021F827C(u32 i);

void func_021F8298(u32 a, u8 b, u8 c, u8 d, u16 e);

int func_021F8324(u32 a);

void func_021F839C(u32 a, u32 b);

void func_021F8414(int a, int b, int c);

void func_021F84B4(u32 a, u32 b);

int func_021F84D0(int a);

void func_021F84E8(int a, int b);

void func_021F8504(u32 a, u32 b, u32 c);

int func_021F8524(int i);

int func_021F853C(int a);

void func_021F8554(u32 flags, int kind, int n, int s, int t);

void func_021F8628(u32 a, int *out, int *p);

void *func_021F8678(void);

int func_021F8684(void);

int func_021F8694(void);

int func_021F86A4(void);

int func_021F86B4(void);

int func_021F86C4(void);

void *func_021F86D4(void);

int func_021F86E0(void);

int func_021F86F0(void);

int func_021F8700(void);

int func_021F8710(void);

int func_021F8720(void);

int func_021F8730(void);

unsigned short func_021F8740(int a);

int func_021F8754(void);

int func_021F8764(void);

void func_021F8774(void);

void func_021F878C(u32 a);

void func_021F87D4(u32 v);

void func_021F87EC(u32 v);

int func_021F882C(void);

void func_021F883C(u32 a);

void func_021F8884(int a);

int func_021F88A8(void);

void func_021F88BC(int a);

int func_021F88E0(void);

int func_021F88F4(void);

int func_021F8914(void);

void func_021F8934(int a);

void func_021F896C(void *h, void (*cb)(void *), int arg);

int func_021F899C(void *h);

void func_021F89BC(void *h);

void func_021F8A10(int a);

void func_021F8A40(int a);

void func_021F8A78(void);

void func_021F8AC0(int a);

void func_021F8AE8(int i, u32 v);

int func_021F8AFC(int i);

void func_021F8B10(void);

void func_021F8B28(void);

int func_021F8B40(void);

void func_021F8B6C(void);

void func_021F8B90(void *h, void *arg);

void func_021F8BAC(void *h, void *arg);

void func_021F8C78(void *h);

void func_021F8CB0(void *h, void *arg);

void func_021F8EF8(void *h);

void func_021F8F30(void *h, void *p);

void func_021F8FB0(void *h);

void func_021F8FE8(void *h, void *arg);

void func_021F9028(void *h);

void func_021F903C(void);

void func_021F9154(int a, int b, int *out, int c);

void func_021F918C(const VecFx32_021F8F30 *a, const VecFx32_021F8F30 *b, VecFx32_021F8F30 *out, fx32 div);

void func_021F9220(int *p, int *d, int *lim, int *flag);

int func_021F9260(Mover_v8204 *m, VecFx32_021F8F30 *out);

int func_021F935C(int x);

void func_021F9364(P *p);

void *func_021F93F4(void *a, u32 b);

int func_021F9478(void *vm);

void func_021F94D8(void *a);

void func_021F94F8(void *vm, u32 a1, u32 a2, u16 id, BtlvEffVmParams *q);

void func_021F97E4(void *a);

void func_021F9814(void *a);

void func_021F9844(S9844 *p);

void func_021F9858(void *vm, u32 a, int b, u32 c, int e, u32 f, int g, int h, int d);

void func_021F9948(void *vm, u32 a, int mode, int c, int x, int dest, int e, int f, int g, int duration);

void func_021F9A7C(void *a);

void func_021F9AA4(void *a);

Work_021FEAC0 *func_021FEAC0(int mode, int a1, u16 a2);

void func_021FEB78(Work_021FEB78 *w);

void func_021FEBAC(Work_021FEBAC *w);

void func_021FEE9C(int *p);

void func_021FEEA8(char *w, void *src, int key);

void func_021FF088(Work_vE254 *w, void *src, int key);

void func_021FF0F8(Work_021FF0F8 *w, int key);

void func_021FF144(Work_021FF144 *w, int key, fx32 x, fx32 y, fx32 z);

void func_021FF16C(Work_021FF16C *w);

int func_021FF348(Work_021FF348 *w, int key);

void func_021FF374(Work_vF228 *w, int key, int kind);

void func_021FF3F4(void *obj, void *out, int idx);

void func_021FF7B0(Work_021FF7B0 *w, int a, int b);

void func_021FF924(char *w, int key, int kind, int value, int a, int b, int c);

void func_021FFBBC(char *w, int key, int kind, int value, int a, int b, int c);

int func_021FFCB0(Work_021FFCB0 *w, int key);

int func_021FFD6C(Work_021FFD6C *w);

int func_021FFD9C(char *p, int key);

void func_021FFDB4(Work_vFCB0 *w, int key, u8 cur, u8 target, u8 step, u32 e);

void func_021FFE48(Work_021FFE48 *w, int key, void *p);

int func_021FFF38(char *p, int key);

void func_022001DC(Work_022001DC *w, int key, Rec_022001DC *r);

void func_02200344(Work_02200344 *w, int a, int b, int flag);

void func_022003EC(Work_022003EC *w, void *p, int *a, int flags);

void func_0220055C(Work_0220055C *w, int key, int mode);

void func_02200608(Work_02200608 *w);

Res_02201894 *func_02201A8C(void *owner, u16 heap);

void func_02201AC4(Res_02201AC4 *r);

void func_02201AF0(void *a0);

Obj_02206BC8 *func_02206BC8(int a, u16 heap);

void func_02206E28(char *p);

void func_02206EB4(W_02206BC8 *p);

void func_022070C0(W_022070C0 *p, void *a, void *q, int mode, int i);

void func_02207288(W_02207288 *p, void *a, void *q, int mode, int i);

void func_02207960(char *p, int i);

extern const char d_0220AC90[];

extern BtlvEff *d_0220AF20;

extern u8 d_02209D0C[];

extern BtlvEff *g_0220AF20;

extern u32 d_0220AC70[];

extern u32 d_0220AC78[];

Obj_v6560 *func_021F73F0(int a, int b, Q_v6560 *q, int c, u16 *h, int e, int f, u16 heap)
{
    Obj_v6560 *o;
    int i = 0;

    o = sub_02030734((u16)((heap & 0x7fff) | 0x8000), 0x2c, 0, d_0220AC90, 0xca);
    o->f0 = a;
    o->f4 = b;
    o->q = *q;
    o->f20 = c;
    o->f24 = f;
    o->f28 = e;
    for (; i < 4; i++)
        o->h[i] = h[i];
    return o;
}

void *func_021F745C(u8 *p, int a, u16 heap)
{
    u16 h[4];
    unsigned int i;
    int side, idx, other;
    int mode, type;
    Q_v6560 *q;
    for (i = 0; i < 4; i++) h[i] = 0;
    if (BTL_MAIN_IsMultiMode((unsigned char **)p) == 1) {
        side = BTL_MAIN_IsOwnClientSecondTeam(p);
        idx = BTL_MAIN_GetOwnClientId(p);
        other = BTL_MAIN_GetOwnPartnerClient(p);
        h[side * 2] = BTL_MAIN_GetTrainerType((char *)p, idx);
        if (other != 4) h[(side ^ 1) * 2] = BTL_MAIN_GetTrainerType((char *)p, other);
        h[1] = BTL_MAIN_GetTrainerType((char *)p, BTL_MAIN_GetOwnOpponentClient(p, 0));
        h[3] = BTL_MAIN_GetTrainerType((char *)p, BTL_MAIN_GetOwnOpponentClient(p, 1));
    } else {
        h[0] = BTL_MAIN_GetTrainerType((char *)p, BTL_MAIN_GetOwnClientId(p));
        h[1] = BTL_MAIN_GetTrainerType((char *)p, BTL_MAIN_GetOwnOpponentClient(p, 0));
        h[2] = 0;
        h[3] = 0;
    }
    mode = BTL_MAIN_GetRule((void **)p);
    type = (int)BTL_MAIN_GetCompetitor((void ***)p);
    q = (Q_v6560 *)BTL_MAIN_GetFieldSituation((char **)p);
    return func_021F73F0(mode, type, q, BTL_MAIN_IsMultiMode((unsigned char **)p), h, (int)p, a, heap);
}

/*
 * note:     the two func_021F6B04 calls and the two f244 stores are written per arm;
 *           the compiler tail-merges them, which is what keeps the 0x194-based
 *           offsets and the reload of &d_0220AF20 seen in the listing.
 */
void func_021F7544(Param *p, int arg, u16 heap)
{
    Work_v6560 *w;
    Entry_021F7208 *tbl;
    u8 v;
    int i;
    Rect r;
    u16 out[10];

    w = sub_02030734(heap, sizeof(Work_v6560), 1, d_0220AC90, 0x116);
    d_0220AF20 = (BtlvEff *)(w);
    w->param = *p;
    w->heap = heap;
    d_0220AF20->buf = sub_02030734(heap, func_02030CB0(0x20), 1, d_0220AC90, 0x11c);
    d_0220AF20->owner = func_02030CBC(0x20, d_0220AF20->buf);
    d_0220AF20->h188 = func_021F93F4(d_0220AF20->owner, heap);
    d_0220AF20->h18c = (void *)PALANM_Create(heap);
    PALANM_SetAutoTransfer((struct Obj02021EE4 *)d_0220AF20->h18c, 1);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)d_0220AF20->h18c, 0, 0x200, heap);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)d_0220AF20->h18c, 1, 0x1e0, heap);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)d_0220AF20->h18c, 2, 0x200, heap);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)d_0220AF20->h18c, 3, 0x1e0, heap);
    v = 0;
    d_0220AF20->h190 = (void *)func_021FEAC0(p->f0, (int)d_0220AF20->owner, heap);
    tbl = ARC_TOOL_LoadMember(0x98, 0, (u16)((d_0220AF20->heap & 0x7fff) | 0x8000));
    if (tbl[p->f8].f1 != 0) {
        v = p->f11;
    }
    d_0220AF20->h194 = (void *)func_021F6560(p->f0, tbl[p->f8].a13[p->fc], v, heap);
    if (d_0220AF20->param_battle != 0) {
        d_0220AF20->h198 = (void *)func_021F6B04(BTL_MAIN_CheckSetupStatusFlag(d_0220AF20->param_battle, 0x400), tbl[p->f8].a2[p->fc], v, heap);
    } else {
        d_0220AF20->h198 = (void *)func_021F6B04(0, tbl[p->f8].a2[p->fc], v, heap);
    }
    if (tbl[p->f8].f0 != 0) {
        func_0201493C(p->f12, p->f14, p->f15, p->f10, p->f11, out, d_0220AF20->heap);
        r.w = out[0];
        r.x = 0;
        r.y = -0x1000;
        r.z = 0;
        G3D_SYSTEM_SetLight(0, (const u16 *)(&r));
    }
    func_020307B0(tbl);
    d_0220AF20->h19c = (void *)func_021F6E3C((int)d_0220AF20->owner, heap);
    d_0220AF20->h1a0 = (struct Res *)func_02201A8C(d_0220AF20->owner, heap);
    d_0220AF20->h1a4 = (void *)func_02206BC8(arg, heap);
    d_0220AF20->h1b0 = BTLV_TIMER_Create(heap);
    d_0220AF20->h1b4 = BTLV_BG_Create(d_0220AF20->owner, heap);
    func_021FF16C((Work_021FF16C *)d_0220AF20->h190);
    PARTICLE_InitManager(heap);
    for (i = 0; i < 8; i++) {
        d_0220AF20->slots[i] = -1;
    }
    if (d_0220AF20->param_battle != 0) {
        if (BTL_MAIN_CheckSetupStatusFlag(d_0220AF20->param_battle, 0x800)) {
            d_0220AF20->f244 = 300;
        } else {
            d_0220AF20->f244 = 900;
        }
    }
    d_0220AF20->h1b8 = func_020056A0(func_021F8B90, 0, 1);
    PM_VOICE_AllocBuffers(2, d_0220AF20->heap);
}

void func_021F7808(void)
{
    if (d_0220AF20 != 0) {
        PM_VOICE_FreeBuffers();
        func_021F8B6C();
        PALANM_FreeSlotBuffers(d_0220AF20->h18c, 0);
        PALANM_FreeSlotBuffers(d_0220AF20->h18c, 1);
        PALANM_FreeSlotBuffers(d_0220AF20->h18c, 2);
        PALANM_FreeSlotBuffers(d_0220AF20->h18c, 3);
        PALANM_Delete(d_0220AF20->h18c);
        func_021FEB78((Work_021FEB78 *)d_0220AF20->h190);
        func_021F6898((Obj_021F6898 *)d_0220AF20->h194);
        func_021F6CF0((Obj_021F6CF0 *)d_0220AF20->h198);
        func_021F6EC0(d_0220AF20->h19c);
        func_02201AC4((Res_02201AC4 *)d_0220AF20->h1a0);
        func_02206E28(d_0220AF20->h1a4);
        BTLV_TIMER_Delete(d_0220AF20->h1b0);
        BTLV_BG_Delete(d_0220AF20->h1b4);
        PARTICLE_ExitManager();
        func_021F94D8(d_0220AF20->h188);
        func_02030EAC(d_0220AF20->h1b8);
        func_02030DA4(d_0220AF20->owner);
        func_020307B0(d_0220AF20->buf);
        func_020307B0(d_0220AF20);
        d_0220AF20 = 0;
    }
}

/*
 * volatile: 0x021F7980 0x021F7986 (0x04000604 read twice, results unused)
 */
void func_021F78E4(void)
{
    if (d_0220AF20 != 0) {
        d_0220AF20->f1e8 = func_021F9478(d_0220AF20->h188);
        func_021F903C();
        func_02030D28(d_0220AF20->owner);
        func_021FEBAC((Work_021FEBAC *)d_0220AF20->h190);
        func_021F6934((Obj_021F6934 *)d_0220AF20->h194);
        func_021F6D5C((Obj_021F6D5C *)d_0220AF20->h198);
        func_021F6ED4(d_0220AF20->h19c);
        func_02206EB4((W_02206BC8 *)d_0220AF20->h1a4);
        func_02201AF0(d_0220AF20->h1a0);
        func_02047964();
        G3D_SYSTEM_ApplyLookAt();
        func_021F69B0((Obj_021F69B0 *)d_0220AF20->h194);
        func_021F6DD4((Obj_021F6DD4 *)d_0220AF20->h198);
        func_021FEE9C(d_0220AF20->h190);
        REG_04000604;
        PARTICLE_Main();
        REG_04000604;
        G3D_SYSTEM_DrawEnd();
    }
}

void func_021F7998(u32 a)
{
    Job_021F7998 *o;

    if (func_021F7EB4() == 0) {
        func_021F94F8(d_0220AF20->h188, 0xff, 0xff, a, (BtlvEffVmParams *)0);
        d_0220AF20->f1e8 = 1;
        return;
    }
    o = sub_02030734((u16)((d_0220AF20->heap & 0x7fff) | 0x8000), 0x14, 1, d_0220AC90, 0x210);
    o->f4 = 0xff;
    o->f8 = 0xff;
    o->fc = a;
    func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8FE8, o, 0), func_021F9028, 0);
}

void func_021F7A28(int a, u32 b)
{
    Job_021F7A28 *o;

    if (func_021F7EB4() == 0) {
        func_021F94F8(d_0220AF20->h188, a, 0xff, b, (BtlvEffVmParams *)0);
        d_0220AF20->f1e8 = 1;
        return;
    }
    o = sub_02030734(d_0220AF20->heap, 0x14, 1, d_0220AC90, 0x22c);
    o->f4 = a;
    o->f8 = 0xff;
    o->fc = b;
    func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8FE8, o, 0), func_021F9028, 0);
}

void func_021F7AAC(int a, int b, u32 c)
{
    Job_021F7AAC *o;

    if (func_021F7EB4() == 0) {
        func_021F94F8(d_0220AF20->h188, a, b, c, (BtlvEffVmParams *)0);
        d_0220AF20->f1e8 = 1;
        return;
    }
    o = sub_02030734(d_0220AF20->heap, 0x14, 1, d_0220AC90, 0x249);
    o->f4 = a;
    o->f8 = b;
    o->fc = c;
    func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8FE8, o, 0), func_021F9028, 0);
}

void func_021F7B2C(const Req_021F7208 *r)
{
    Job_021F7B2C *o;
    Arg_v6560 l;

    if (func_021F7EB4() == 0) {
        func_021F9844((S9844 *)&l);
        l.b0 = r->f10;
        l.b1 = r->c;
        l.b2 = r->d;
        func_021F94F8(d_0220AF20->h188, r->f4, r->f8, r->h0, (BtlvEffVmParams *)&l);
        d_0220AF20->f1e8 = 1;
        return;
    }
    o = sub_02030734(d_0220AF20->heap, 0x14, 1, d_0220AC90, 0x26b);
    o->s = sub_02030734(d_0220AF20->heap, 0x10, 1, d_0220AC90, 0x26c);
    o->f4 = r->f4;
    o->f8 = r->f8;
    o->fc = r->h0;
    o->s->b0 = r->f10;
    o->s->b1 = r->c;
    o->s->b2 = r->d;
    func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8FE8, o, 0), func_021F9028, 0);
}

/*
 * Calls func_021F97E4 on the handle at 0x188 of the global work block, then sets the word at 0x1e8 to 0.
 */
void func_021F7BEC(void)
{
    func_021F97E4(d_0220AF20->h188);
    d_0220AF20->f1e8 = 0;
}

/*
 * Calls func_021F9814 on the handle at 0x188 of the global work block, then sets the word at 0x1e8 to 1.
 */
void func_021F7C0C(void)
{
    func_021F9814(d_0220AF20->h188);
    d_0220AF20->f1e8 = 1;
}

/*
 * witness: arm9 WAZA_TOOL_GetDamageType filed as src/matched/arm9/WAZA_TOOL_GetDamageType.c.
 */
void func_021F7C2C(int a, int b)
{
    Job_021F7208 *o;

    o = sub_02030734((u16)((d_0220AF20->heap & 0x7fff) | 0x8000), 0x18, 0, d_0220AC90, 0x29b);
    o->f4 = 0;
    o->f0 = a;
    o->f8 = 3;
    o->fc = 0;
    o->f14 = func_021FF348((Work_021FF348 *)d_0220AF20->h190, a);
    if (WAZA_TOOL_GetDamageType(b) == 1)
        o->f10 = 0x842;
    else
        o->f10 = 0x6318;
    d_0220AF20->m0 |= func_021F935C(a);
    func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8BAC, o, 0), func_021F8C78, 0);
}

/*
 * Runs func_021F7A28 with code 0x23b, then func_021F8AE8 with 0.
 */
void func_021F7CE4(int a)
{
    func_021F7A28(a, 0x23b);
    func_021F8AE8(a, 0);
}

void func_021F7CFC(u32 a, u16 b, u8 c, int d, int e)
{
    Arg_v6560 l;

    func_021F9844((S9844 *)&l);
    l.b3 = c;
    l.f8 = e;
    l.f4 = d;
    l.fc = b;
    func_021F94F8(d_0220AF20->h188, 0, a, 0x23a, (BtlvEffVmParams *)&l);
    d_0220AF20->f1e8 = 1;
}

/*
 * Queues request 0x23d with value b on the handle at 0x188, then sets the word at 0x1e8 to 1.
 */
void func_021F7D44(int a, unsigned short b)
{
    Req_021F7D44 req;

    func_021F9844((S9844 *)((Arg_v6560 *)&req));
    req.v = b;
    func_021F94F8(d_0220AF20->h188, 0, a, 0x23d, (BtlvEffVmParams *)&req);
    d_0220AF20->f1e8 = 1;
}

void func_021F7D80(void *a, int b)
{
    Job_021F7D80 *o;

    o = sub_02030734((u16)((d_0220AF20->heap & 0x7fff) | 0x8000), 0x2c, 0, d_0220AC90, 0x2f9);
    o->f4 = 0;
    o->f0 = b;
    func_021FFE48((Work_021FFE48 *)d_0220AF20->h190, b, a);
    func_022003EC((Work_022003EC *)d_0220AF20->h190, a, o->buf, b);
    d_0220AF20->m1 |= func_021F935C(b);
    func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8CB0, o, 0), func_021F8EF8, 0);
}

void func_021F7E38(void *a, int b)
{
    int buf[9];

    func_021FFE48((Work_021FFE48 *)d_0220AF20->h190, b, a);
    func_022003EC((Work_022003EC *)d_0220AF20->h190, a, buf, b);
    func_022001DC((Work_022001DC *)d_0220AF20->h190, b, (Rec_022001DC *)buf);
}

void func_021F7E74(u32 a)
{
    func_021F7A28(a, 0x285);
}

/*
 * Unlabelled tail-call stub, filed as a witness for the caller ov093 BTLV_CORE_SetMonShown (wave B3 lane 17).
 */
void func_021F7E84(u32 a)
{
    func_021F7A28(a, 0x286);
}

/*
 * Thumb tail call through r3 with a constant second argument. Labelled in wave D8.
 */
void func_021F7E94(int a)
{
    func_021F7A28(a, 0x26E);
}

/*
 * Unlabelled tail-call stub, filed for the caller ov093 func_021D284C (lane S16).
 */
void func_021F7EA4(u32 a)
{
    func_021F7A28(a, 0x26F);
}

int func_021F7EB4(void)
{
    BtlvEff *p = d_0220AF20;
    u32 t = p->f1e8 | p->m0 | p->m1 | p->m2;

    if (t != 0)
        return 1;
    return 0;
}

/*
 * Unlabelled leaf, filed as the blocker of ov093 callers (lane S15).
 */
void func_021F7EE8(void *m, int key)
{
    func_021FEEA8((char *)d_0220AF20->h190, m, key);
}

/*
 * Tail call to func_021FF0F8 with the handle at 0x190 of the global work block.
 */
void func_021F7F04(int a)
{
    func_021FF0F8((Work_021FF0F8 *)d_0220AF20->h190, a);
}

int func_021F7F1C(int i)
{
    if (i < 8)
        return func_021FFD9C((char *)d_0220AF20->h190, i);
    if (d_0220AF20->slots[i - 8] != -1)
        return 1;
    return 0;
}

void func_021F7F58(int a, u32 b, u32 c, u32 d, u32 e)
{
    if (!(b & 1)) {
        switch (a) {
        case 0:
        case 1:
            if (func_021F88F4())
                a += 4;
            break;
        case 0x3D:
            a = 2;
            break;
        case 0x25:
            a = 3;
            break;
        default:
            if (d_02209D0C[a] == 0)
                a = 0;
            else
                a = 1;
            break;
        }
    } else {
        switch (a) {
        case 0:
        case 1:
            if (func_021F88F4())
                a += 0x67;
            break;
        }
    }
    func_021FF088((Work_vE254 *)((u32)d_0220AF20->h190), (void *)a, b);
    if (c != 0 || d != 0 || e != 0)
        func_021FF144((Work_021FF144 *)((u32)d_0220AF20->h190), b, c, d, e);
    d_0220AF20->slots[b - 8] = b;
}

void func_021F8010(int a)
{
    func_021FF0F8((Work_021FF0F8 *)d_0220AF20->h190, a);
    d_0220AF20->slots[a - 8] = -1;
}

void func_021F803C(u32 a, void *m, u32 c)
{
    switch ((u32)d_0220AF20->mode) {
    case 2:
        func_022070C0((W_022070C0 *)((struct W *)d_0220AF20->h1a4), (void *)a, m, 2, c);
        break;
    case 3:
        func_022070C0((W_022070C0 *)((struct W *)d_0220AF20->h1a4), (void *)a, m, 3, c);
        break;
    default:
        func_022070C0((W_022070C0 *)((struct W *)d_0220AF20->h1a4), (void *)a, m, 0, c);
        break;
    }
}

/*
 * extent: Already matched followers begin at 0x021F80E4.
 */
void func_021F8090(u32 a, u32 b, u32 c)
{
    switch ((u32)d_0220AF20->mode) {
    case 2:
        func_02207288((W_02207288 *)((struct W *)d_0220AF20->h1a4), (void *)a, (void *)b, 2, c);
        break;
    case 3:
        func_02207288((W_02207288 *)((struct W *)d_0220AF20->h1a4), (void *)a, (void *)b, 3, c);
        break;
    default:
        func_02207288((W_02207288 *)((struct W *)d_0220AF20->h1a4), (void *)a, (void *)b, 0, c);
        break;
    }
}

/*
 * Unlabelled leaf, filed as the blocker of ov093 callers (lane S17).
 */
void func_021F80E4(u32 a)
{
    func_02207960((char *)d_0220AF20->h1a4, a);
}

void func_021F80FC(u32 a, u32 b)
{
    BTLV_GAUGE_StartHpChangeAnimated((char *)d_0220AF20->h1a4, a, b);
}

void func_021F8118(u32 a, u32 b)
{
    BTLV_GAUGE_StartHpChangeInstant((char *)d_0220AF20->h1a4, a, b);
}

void func_021F8134(int index, u32 amount)
{
    BTLV_GAUGE_StartExpGain(d_0220AF20->h1a4, index, amount);
}

void func_021F8150(int index, void *obj)
{
    BTLV_GAUGE_RefreshForLevelUp(d_0220AF20->h1a4, obj, index);
}

/*
 * Tail call to BTLV_GAUGE_RequestStop with the handle at 0x1a4 of the global work block.
 */
void func_021F8168(void)
{
    BTLV_GAUGE_RequestStop(d_0220AF20->h1a4);
}

/*
 * Tail call to BTLV_GAUGE_IsAnimating with the handle at 0x1a4 of the global work block.
 */
int func_021F8180(void)
{
    return BTLV_GAUGE_IsAnimating(d_0220AF20->h1a4);
}

/*
 * Tail call to BTLV_GAUGE_SetSideVisible with the handle at 0x1a4 of the global work block.
 */
void func_021F8198(int a, int b)
{
    BTLV_GAUGE_SetSideVisible(d_0220AF20->h1a4, a, b);
}

void func_021F81B4(u32 a, u32 b)
{
    BTLV_GAUGE_SetSlotVisible((struct O *)d_0220AF20->h1a4, a, b);
}

/*
 * Unlabelled leaf, filed as the blocker of ov093 func_021D2234 (lane S15).
 */
void func_021F81D0(u32 a, u32 b)
{
    BTLV_GAUGE_SetStatusIcon((struct O *)d_0220AF20->h1a4, a, b);
}

void func_021F81EC(int sel)
{
    BTLV_GAUGE_SelectSlot((void *)d_0220AF20->h1a4, sel);
}

int func_021F8204(int index)
{
    return BTLV_GAUGE_IsSlotOccupied((u8 *)d_0220AF20->h1a4, index);
}

/*
 * Forwards three arguments to BTLV_GAUGE_GetSlotHealthInfo with the handle at 0x1a4 of the global work block.
 */
int func_021F821C(int a, int *b, int *c)
{
    return BTLV_GAUGE_GetSlotHealthInfo(d_0220AF20->h1a4, a, b, c);
}

void func_021F823C(u32 *p)
{
    u32 r = BTLV_B_GAUGE_CreatePartyBallBar(p, d_0220AF20->heap);

    d_0220AF20->h1a8[p[0]] = (void *)r;
}

/*
 * Leaf blocking ov093 BTLV_SCU_ProcEntrySingleTrainer.
 */
void func_021F8260(u32 i)
{
    BTLV_B_GAUGE_DeletePartyBallBar(d_0220AF20->h1a8[i]);
}

int func_021F827C(u32 i)
{
    return BTLV_B_GAUGE_IsPartyBallBarActive((int *)d_0220AF20->h1a8[i]);
}

void func_021F8298(u32 a, u8 b, u8 c, u8 d, u16 e)
{
    if (a == 0 || a == 2 || a == 4)
        func_021F69E8((S69E8 *)((u32)d_0220AF20->h194), b, c, d, e);
    if (a == 1 || a == 2 || a == 4)
        func_021F6DEC((S6DEC *)((u32)d_0220AF20->h198), b, c, d, e);
    if (a - 3 <= 1)
        PALANM_RequestFade(d_0220AF20->h18c, 1, 0xFF00, (s8)d, b, c, e, *(void **)d_0220AF20);
}

int func_021F8324(u32 a)
{
    int x = 0;
    int y = 0;
    int z = 0;

    if (a == 0 || a == 2 || a == 4)
        x = func_021F6A18((char *)d_0220AF20->h194);
    if (a == 1 || a == 2 || a == 4)
        y = func_021F6E1C((char *)d_0220AF20->h198);
    if (a - 3 <= 1) {
        z = PALANM_GetFadeRequestBits((const char *)d_0220AF20->h18c) != 0;
    }
    if (x == 1 || y == 1 || z == 1)
        return 1;
    return 0;
}

void func_021F839C(u32 a, u32 b)
{
    switch (a) {
    case 0:
        func_021F6A28((Obj_021F6A28 *)((u32)d_0220AF20->h194), 2, b);
        break;
    case 1:
        func_021F6E2C((Obj_021F6E2C *)((u32)d_0220AF20->h198), b);
        break;
    case 2:
        func_02040588(3, (u8)(b ^ 1));
        break;
    case 3:
        func_021F6A28((Obj_021F6A28 *)((u32)d_0220AF20->h194), 0, b);
        break;
    case 4:
        func_021F6A28((Obj_021F6A28 *)((u32)d_0220AF20->h194), 1, b);
        break;
    }
}

void func_021F8414(int a, int b, int c)
{
    St *s = sub_02030734((u16)((d_0220AF20->heap & 0x7FFF) | 0x8000), 0x10, 0, d_0220AC90, 0x538);

    if (a != 1) {
        s->state = 0;
        s->b = (a == 3) ? 0 : 1;
        s->c = b;
        s->d = c;
        d_0220AF20->m2 |= func_021F935C(b);
        func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8F30, s, 0), func_021F8FB0, 0);
    }
}

void func_021F84B4(u32 a, u32 b)
{
    func_021FF7B0((Work_021FF7B0 *)((u32)d_0220AF20->h190), a, b);
}

/*
 * Returns slot a-8 of the table at 0x1f8 of the global work block.
 */
int func_021F84D0(int a)
{
    return d_0220AF20->slots[a - 8];
}

/*
 * Tail call to BTLV_TIMER_Start with the handle at 0x1b0 of the global work block.
 */
void func_021F84E8(int a, int b)
{
    BTLV_TIMER_Start(d_0220AF20->h1b0, a, b);
}

void func_021F8504(u32 a, u32 b, u32 c)
{
    BTLV_TIMER_SetVisible((u8 *)d_0220AF20->h1b0, a, b, c);
}

/*
 * Thumb tail call through r3: the work record at +0x1B0 of d_0220AF20 and the argument. Labelled in wave D8.
 */
int func_021F8524(int i)
{
    return BTLV_TIMER_IsExpired((struct W *)d_0220AF20->h1b0, i);
}

/*
 * Tail call to func_021FF348 with the handle at 0x190 of the global work block.
 * Unlabelled; filed as a witness for the caller ov093 BTLV_CORE_SetMonShown (wave B3 lane 17).
 */
int func_021F853C(int a)
{
    return func_021FF348((Work_021FF348 *)d_0220AF20->h190, a);
}

void func_021F8554(u32 flags, int kind, int n, int s, int t)
{
    VecFx32_021F8204 a;
    VecFx32_021F8204 b;

    if (flags & 1) {
        func_021F8628(flags, (int *)(&a), (int *)(&b));
        switch (kind) {
        case 0:
            func_021F6EDC(d_0220AF20->h19c, (int *)(&a), (int *)(&b));
            break;
        case 1:
            func_021F6F48((Cam_021F6F48 *)d_0220AF20->h19c, (VecFx32_v6560 *)&a, (VecFx32_v6560 *)&b, n, s, t);
            break;
        }
        return;
    }
    switch (d_0220AF20->mode) {
    case 0:
        func_021F7998(0x23F);
        break;
    case 1:
        if (flags == 2) {
            func_021F7998(0x240);
        } else {
            func_021F7998(0x241);
        }
        break;
    case 2:
        if (flags == 2) {
            func_021F7998(0x242);
        } else if (flags == 4) {
            func_021F7998(0x23F);
        } else {
            func_021F7998(0x243);
        }
        break;
    case 3:
        func_021F7998(0x245);
        break;
    }
}

void func_021F8628(u32 a, int *out, int *p)
{
    func_021FF3F4((void *)d_0220AF20->h190, p, a);
    out[0] = p[0] + 0x4B33;
    out[1] = p[1] + 0x2299;
    out[2] = p[2] + 0x99CD;
    p[1] = p[1] + 0x2000;
}

void *func_021F8678(void)
{
    return g_0220AF20;
}

int func_021F8684(void)
{
    return (int)d_0220AF20->h19c;
}

int func_021F8694(void)
{
    return (int)d_0220AF20->h190;
}

int func_021F86A4(void)
{
    return (int)d_0220AF20->h194;
}

/*
 * Returns the word at 0x1a4 of the global work block.
 */
int func_021F86B4(void)
{
    return (int)d_0220AF20->h1a4;
}

/*
 * Returns the word at 0x188 of the global work block.
 */
int func_021F86C4(void)
{
    return (int)d_0220AF20->h188;
}

void *func_021F86D4(void)
{
    return *(void **)g_0220AF20;
}

/*
 * Returns the word at 0x18c of the global work block.
 */
int func_021F86E0(void)
{
    return (int)d_0220AF20->h18c;
}

/*
 * Returns the word at 0x1a0 of the global work block.
 */
int func_021F86F0(void)
{
    return (int)d_0220AF20->h1a0;
}

/*
 * Returns the word at 0x1b4 of the global work block.
 */
int func_021F8700(void)
{
    return (int)d_0220AF20->h1b4;
}

int func_021F8710(void)
{
    return d_0220AF20->mode;
}

/*
 * Returns the word at 0x1c0 of the global work block.
 */
int func_021F8720(void)
{
    return d_0220AF20->f1c0;
}

/*
 * Returns the word at 0x1dc of the global work block.
 */
int func_021F8730(void)
{
    return d_0220AF20->f1dc;
}

/*
 * Returns halfword a of the table at 0x1d4 of the global work block.
 */
unsigned short func_021F8740(int a)
{
    return d_0220AF20->f1d4[a];
}

/*
 * Returns the word at 0x1e4 of the global work block.
 */
int func_021F8754(void)
{
    return (int)d_0220AF20->param_battle;
}

/*
 * Returns the word at 0x1e0 of the global work block.
 */
int func_021F8764(void)
{
    return d_0220AF20->f1e0;
}

/*
 * Tail call to BTLV_GAUGE_IsLowHpBgmPlaying with the handle at 0x1a4 of the global work block.
 */
void func_021F8774(void)
{
    BTLV_GAUGE_IsLowHpBgmPlaying(d_0220AF20->h1a4);
}

void func_021F878C(u32 a)
{
    if (BTLV_GAUGE_IsLowHpBgmPlaying((void *)d_0220AF20->h1a4)) {
        BTLV_GAUGE_SetLowHpBgmPlaying((u32)d_0220AF20->h1a4, 0);
        GFL_USE_PopBgm();
    }
    BTLV_GAUGE_SetLowHpBgmSuppressed((u32)d_0220AF20->h1a4, 1);
    GFL_USE_CancelChangeAndPlayBgm(a, 0xFFFF);
}

/*
 * Witness leaf for ov093 BTLV_SCU_HideMonPair: tail call (obj, v) to BTLV_GAUGE_SetLowHpBgmSuppressed.
 */
void func_021F87D4(u32 v)
{
    BTLV_GAUGE_SetLowHpBgmSuppressed((u32)d_0220AF20->h1a4, v);
}

void func_021F87EC(u32 v)
{
    d_0220AF20->f1f4 = 1;
    BTLV_GAUGE_SetSavedBgmNo(d_0220AF20->h1a4, v);
    if (BTLV_GAUGE_IsLowHpBgmPlaying(d_0220AF20->h1a4) == 0)
        BTLV_GAUGE_SetBgmReplaced(d_0220AF20->h1a4, 1);
}

int func_021F882C(void)
{
    return d_0220AF20->f1f4;
}

void func_021F883C(u32 a)
{
    if (BTLV_GAUGE_IsLowHpBgmPlaying(d_0220AF20->h1a4) == 1)
        GFL_USE_PopBgm();
    BTLV_GAUGE_SetLowHpBgmSuppressed((u32)d_0220AF20->h1a4, 1);
    BTLV_GAUGE_SetLowHpBgmPlaying((u32)d_0220AF20->h1a4, 0);
    GFL_USE_CancelChangeAndPlayBgm(a, 0x0000FFFF);
}

/*
 * Stores the low 8 bits of the argument in bits 18..25 of the word at 0x1ec of the global work block.
 */
void func_021F8884(int a)
{
    d_0220AF20->v = a;
}

/*
 * Returns bits 18..25 of the word at 0x1ec of the global work block.
 */
int func_021F88A8(void)
{
    return d_0220AF20->v;
}

/*
 * Sets flag bit 26 of the word at 0x1ec of the global work block.
 */
void func_021F88BC(int a)
{
    d_0220AF20->b26 = a;
}

int func_021F88E0(void)
{
    return d_0220AF20->b26;
}

/*
 * Returns BTL_MAIN_IsRecordEnabledInComm of the handle at 0x1e4 of the global work block, or 0 when it is null.
 */
int func_021F88F4(void)
{
    int r = 0;
    void *h = d_0220AF20->param_battle;
    if (h != 0)
        r = BTL_MAIN_IsRecordEnabledInComm(h);
    return r;
}

/*
 * Returns BTL_MAIN_IsRecordAllowed of the handle at 0x1e4 of the global work block, or 0 when it is null.
 */
int func_021F8914(void)
{
    int r = 0;
    void *h = d_0220AF20->param_battle;
    if (h != 0)
        r = BTL_MAIN_IsRecordAllowed(h);
    return r;
}

/*
 * Runs func_0220055C with a (enum counter keeps the entry guard) on each of the first 8 active slots of the handle at 0x190.
 */
void func_021F8934(int a)
{
    Slot_021F6560 i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C(d_0220AF20->h190, i) != 0)
            func_0220055C((Work_0220055C *)d_0220AF20->h190, i, a);
    }
}

void func_021F896C(void *h, void (*cb)(void *), int arg)
{
    int i = func_021F8B40();

    d_0220AF20->handle[i] = h;
    d_0220AF20->cb[i] = cb;
    d_0220AF20->arg[i] = arg;
}

int func_021F899C(void *h)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (d_0220AF20->handle[i] == h)
            break;
    }
    return i;
}

void func_021F89BC(void *h)
{
    int i = func_021F899C(h);
    void *w;

    if (h == 0)
        return;
    w = (void *)TCBL_IsDeletePending(h);
    if (d_0220AF20->cb[i] != 0)
        d_0220AF20->cb[i](h);
    if (w != 0)
        sub_020307B0(w);
    sub_02030EAC(h);
    d_0220AF20->handle[i] = 0;
    d_0220AF20->cb[i] = 0;
}

/*
 * Runs func_021F89BC on each live object owned by a.
 */
void func_021F8A10(int a)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (d_0220AF20->handle[i] != 0 && a == d_0220AF20->arg[i])
            func_021F89BC(d_0220AF20->handle[i]);
    }
}

void func_021F8A40(int a)
{
    d_0220AF20->f238 = a;
    if (d_0220AF20->f238 != 2) {
        d_0220AF20->f23c = 0;
        d_0220AF20->f240 = 0;
    }
    if (a == 3)
        func_02200608((Work_02200608 *)d_0220AF20->h190);
}

void func_021F8A78(void)
{
    func_021F7BEC();
    if (d_0220AF20->f238 == 3 && BTL_MAIN_CheckSetupStatusFlag(d_0220AF20->param_battle, 0x400))
        func_021F7998(0x251);
    else
        func_021F7998(0x236);
    d_0220AF20->f238 = 0;
}

/*
 * Calls func_021F7BEC, then stores the argument at 0x238 and clears 0x23c and 0x240 of the global work block.
 */
void func_021F8AC0(int a)
{
    func_021F7BEC();
    d_0220AF20->f238 = a;
    d_0220AF20->f23c = 0;
    d_0220AF20->f240 = 0;
}

void func_021F8AE8(int i, u32 v)
{
    d_0220AF20->tbl[i] = v;
}

int func_021F8AFC(int i)
{
    return d_0220AF20->tbl[i];
}

void func_021F8B10(void)
{
    func_021F9A7C(d_0220AF20->h188);
}

void func_021F8B28(void)
{
    func_021F9AA4(d_0220AF20->h188);
}

int func_021F8B40(void)
{
    BtlvEff *w;
    int i;

    i = 0;
    w = d_0220AF20;
    for (; i < 32; i++) {
        if (w->handle[i] == 0)
            break;
    }
    if (i == 32) {
        func_021F89BC(w->handle[0]);
        i = 0;
    }
    return i;
}

/*
 * Runs func_021F89BC on each of the 32 live objects at 8 of the global work block.
 */
void func_021F8B6C(void)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (d_0220AF20->handle[i] != 0)
            func_021F89BC(d_0220AF20->handle[i]);
    }
}

/*
 * Calls CLACT_VBlankSystem, then PALANM_TransferPalettes on the handle at 0x18c of the global work block.
 */
void func_021F8B90(void *h, void *arg)
{
    CLACT_VBlankSystem();
    PALANM_TransferPalettes(d_0220AF20->h18c);
}

void func_021F8BAC(void *h, void *arg)
{
    int *p = arg;

    if (p[3] != 0) {
        p[3]--;
        return;
    }
    switch (p[1]) {
    case 0:
        if (p[5] == 0)
            func_021FFDB4((Work_vFCB0 *)d_0220AF20->h190, p[0], 16, 16, 0, p[4]);
        p[3] = 3;
        p[1] = 1;
        break;
    case 1:
        if (p[5] == 0)
            func_021FF374((Work_vF228 *)d_0220AF20->h190, p[0], 1);
        p[3] = 3;
        p[1] = 2;
        break;
    case 2:
        p[1] = 0;
        if (p[5] == 0) {
            func_021FF374((Work_vF228 *)d_0220AF20->h190, p[0], 0);
            func_021FFDB4((Work_vFCB0 *)d_0220AF20->h190, p[0], 0, 0, 0, 0x7fff);
        }
        p[3] = 3;
        if (--p[2] == 0)
            func_021F89BC(h);
        break;
    }
}

/*
 * Clears the current task's mask bits from the low byte at 0x1ec of the global work block.
 */
void func_021F8C78(void *h)
{
    int m = func_021F935C(*((int *)TCBL_IsDeletePending(h)));
    d_0220AF20->m0 &= m ^ 0xffffffff;
}

void func_021F8CB0(void *h, void *arg)
{
    int *p = arg;

    switch (p[1]) {
    case 0:
        func_021F94F8(d_0220AF20->h188, p[0], 0xff, 0x253, 0);
        d_0220AF20->f1e8 = 1;
        p[1]++;
        break;
    case 1:
        if (d_0220AF20->f1e8 == 0) {
            if (func_021FFF38(d_0220AF20->h190, p[0]) & 1) {
                func_021F94F8(d_0220AF20->h188, p[0], 0xff, 0x264, 0);
                d_0220AF20->f1e8 = 1;
            }
            p[1]++;
        }
        break;
    case 2:
        if (d_0220AF20->f1e8 == 0) {
            func_021FF924(d_0220AF20->h190, p[0], 0, 16, 0, 0, 0);
            func_021FFBBC(d_0220AF20->h190, p[0], 1, 8, 8, 1, 0);
            func_021F9858(d_0220AF20->h188, 0x5aa, 1, 14, -500, 127, 0, 0, 0);
            func_021F9948(d_0220AF20->h188, 1, 0, 1, 127, 0, 30, 10, 0, 0);
            p[1]++;
        }
        break;
    case 3:
        if (func_021FFCB0((Work_021FFCB0 *)d_0220AF20->h190, p[0]) == 0) {
            func_022001DC((Work_022001DC *)d_0220AF20->h190, p[0], (Rec_022001DC *)(&p[2]));
            p[1]++;
        }
        break;
    case 4:
        func_021FFBBC(d_0220AF20->h190, p[0], 1, 0, 8, 1, 0);
        p[1]++;
        break;
    case 5:
        if (func_021FFCB0((Work_021FFCB0 *)d_0220AF20->h190, p[0]) == 0) {
            func_021F9858(d_0220AF20->h188, 0x560, 1, 14, 0, 0, 0, 0, 0);
            func_021FF924(d_0220AF20->h190, p[0], 0, 31, 0, 0, 0);
            if (func_021FFF38(d_0220AF20->h190, p[0]) & 1) {
                func_021F94F8(d_0220AF20->h188, p[0], 0xff, 0x265, 0);
                d_0220AF20->f1e8 = 1;
            }
            p[1]++;
        }
        break;
    case 6:
        if (d_0220AF20->f1e8 == 0) {
            func_021F94F8(d_0220AF20->h188, p[0], 0xff, 0x254, 0);
            d_0220AF20->f1e8 = 1;
            p[1]++;
        }
        break;
    case 7:
        if (d_0220AF20->f1e8 == 0)
            func_021F89BC(h);
        break;
    }
}

/*
 * Clears the current task's mask bits from bits 8..15 of the word at 0x1ec of the global work block.
 */
void func_021F8EF8(void *h)
{
    int m = func_021F935C(((int *)TCBL_IsDeletePending(h))[0]);
    d_0220AF20->m1 &= m ^ 0xffffffff;
}

void func_021F8F30(void *h, void *p)
{
    St *s = p;
    int st;
    u32 m;

    st = s->state;
    switch (st) {
    case 0:
        m = d_0220AF20->m0 | d_0220AF20->f1e8 | d_0220AF20->m1;
        if (m)
            return;
        s->state = st + 1;
    case 1:
        func_02200344((Work_02200344 *)d_0220AF20->h190, s->c, s->b, s->d);
        s->state = s->state + 1;
        return;
    case 2:
        if (func_021F6AD0((Obj_021F6AD0 *)d_0220AF20->h194))
            return;
        if (func_021FFD6C((Work_021FFD6C *)d_0220AF20->h190))
            return;
        func_021F89BC(h);
        return;
    }
}

void func_021F8FB0(void *h)
{
    int m = func_021F935C(((int *)TCBL_IsDeletePending(h))[2]);
    d_0220AF20->m2 &= m ^ 0xffffffff;
}

void func_021F8FE8(void *h, void *arg)
{
    Arg_v8204 *p = arg;

    if (func_021F7EB4() == 0) {
        func_021F94F8(d_0220AF20->h188, p->a, p->b, p->c, p->d);
        d_0220AF20->f1e8 = 1;
        func_021F89BC(h);
    }
}

/*
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Frees the buffer at 0x10 of the current task's work, if any.
 */
void func_021F9028(void *h)
{
    void *p = *(void **)(TCBL_IsDeletePending(h) + 0x10);
    if (p != 0)
        func_020307B0(p);
}

/*
 * lever: Assign table lookups to a shared local before the call; duplicated
 * calls cross-jump the indexed load and shorten the function by four bytes.
 */
void func_021F903C(void)
{
    int a, b;
    u32 n, value;
    a = KEY_GetTrg();
    b = TOUCHPANEL_GetTrg();
    if (d_0220AF20->f238 == 0)
        return;
    if (d_0220AF20->f238 != 2 && d_0220AF20->f238 != 3 && (a != 0 || b != 0)) {
        func_021F7BEC();
        func_021F7998(0x252);
        d_0220AF20->f23c = 0;
        d_0220AF20->f240 = 0;
    }
    switch (d_0220AF20->f23c) {
    case 0:
        if (d_0220AF20->f240 < d_0220AF20->f244) {
            d_0220AF20->f240++;
            return;
        }
        d_0220AF20->f23c = 1;
    case 1:
        if (func_021F7EB4() == 0) {
            if (d_0220AF20->f238 == 3 && BTL_MAIN_CheckSetupStatusFlag(d_0220AF20->param_battle, 0x400)) {
                do {
                    n = (u32)(((u64)func_0203F0A8() * 2) >> 32);
                } while (d_0220AF20->f248 == n);
                d_0220AF20->f248 = n;
                value = d_0220AC70[d_0220AF20->f248];
            } else {
                do {
                    n = (u32)(((u64)func_0203F0A8() * 6) >> 32);
                } while (d_0220AF20->f248 == n);
                d_0220AF20->f248 = n;
                value = d_0220AC78[d_0220AF20->f248];
            }
            func_021F7998(value);
            d_0220AF20->f1e8 = 1;
        }
        break;
    }
}

/*
 * Signed step from a to b in units of c (default 0x1000), at least one unit.
 */
void func_021F9154(int a, int b, int *out, int c)
{
    *out = 0;
    if (b - a == 0)
        return;
    if (c == 0)
        c = 0x1000;
    *out = func_0207C768(b - a, c);
    if (*out == 0) {
        if (b > a)
            *out = 1;
        else
            *out = -1;
    }
}

void func_021F918C(const VecFx32_021F8F30 *a, const VecFx32_021F8F30 *b, VecFx32_021F8F30 *out, fx32 div)
{
    out->x = 0;
    out->y = 0;
    out->z = 0;
    if (div == 0)
        div = 0x1000;
    if (b->x - a->x != 0) {
        out->x = FX_Div_Alt(b->x - a->x, div);
        if (out->x == 0)
            out->x = (b->x > a->x) ? 1 : -1;
    }
    if (b->y - a->y != 0) {
        out->y = FX_Div_Alt(b->y - a->y, div);
        if (out->y == 0)
            out->y = (b->y > a->y) ? 1 : -1;
    }
    if (b->z - a->z != 0) {
        out->z = FX_Div_Alt(b->z - a->z, div);
        if (out->z == 0)
        {
            if (b->z > a->z)
                out->z = 1;
            else
                out->z = -1;
        }
    }
}

/*
 * EXACT*: inferred extent runs two bytes long; the follower is an unlabelled
 * padding pair.
 */
void func_021F9220(int *p, int *d, int *lim, int *flag)
{
    int n = *p + *d;
    *p = n;
    if (*d < 0) {
        if (n <= *lim) {
            *p = *lim;
        } else {
            if (flag)
                *flag = 0;
        }
    } else {
        if (n >= *lim) {
            *p = *lim;
        } else {
            if (flag)
                *flag = 0;
        }
    }
}

int func_021F9260(Mover_v8204 *m, VecFx32_021F8F30 *out)
{
    int ret = 1;

    switch (m->mode) {
    case 0:
        out->x = m->start.x;
        out->y = m->start.y;
        out->z = m->start.z;
        break;
    case 1:
    case 4:
        if (m->wait == 0) {
            m->wait = m->waitReset;
            func_021F9220(&out->x, &m->step.x, &m->start.x, &ret);
            func_021F9220(&out->y, &m->step.y, &m->start.y, &ret);
            func_021F9220(&out->z, &m->step.z, &m->start.z, &ret);
        } else {
            m->wait--;
            ret = 0;
        }
        break;
    case 2:
    case 3:
        if (m->wait == 0) {
            m->wait = m->waitReset;
            out->x += m->step.x;
            out->y += m->step.y;
            out->z += m->step.z;
            if (--m->count == 0) {
                m->repeat--;
                m->count = m->countReset;
                if (m->mode == 2 || (m->mode == 3 && (m->repeat & 1))) {
                    m->step.x *= -1;
                    m->step.y *= -1;
                    m->step.z *= -1;
                }
            }
        } else {
            m->wait--;
        }
        if (m->repeat != 0) {
            ret = 0;
        } else {
            out->x = m->end.x;
            out->y = m->end.y;
            out->z = m->end.z;
        }
        break;
    }
    return ret;
}

int func_021F935C(int x)
{
    return 1 << x;
}

void func_021F9364(P *p)
{
    int i;
    Q_v8204 *q;
    u32 sz;
    u32 off;

    if (p->en != 0) {
        if (p->cnt == 0) {
            p->cnt = p->rl;
            for (i = 0; i < p->n; i++) {
                q = (Q_v8204 *)NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile((struct Tagged *)p->a0[i]));
                sz = q->h30 << 3;
                off = (u16)q->w2c << 3;
                PALANM_BlendColors((u16 *)((char *)q + q->o38), p->a4[i], (u16)(sz >> 1), p->cur, p->col);
                func_02061CA4((void *)1, off, (u32)p->a4[i], sz);
            }
            if (p->cur == p->tgt) {
                p->en = 0;
            } else if (p->cur > p->tgt) {
                p->cur = p->cur - 1;
            } else {
                p->cur = p->cur + 1;
            }
        } else {
            p->cnt = p->cnt - 1;
        }
    }
}
