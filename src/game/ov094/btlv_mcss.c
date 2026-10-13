/*
 * file:     btlv_mcss.c
 * unit:     yes
 * function: func_021FEAC0, func_021FEB78, func_021FEBAC, func_021FEE9C, func_021FEEA8, func_021FF088, func_021FF0F8, func_021FF134, func_021FF144, func_021FF16C, func_021FF1B0, func_021FF1F4, func_021FF228, func_021FF260, func_021FF2D8, func_021FF304, func_021FF348, func_021FF374, func_021FF3F4, func_021FF3FC, func_021FF468, func_021FF470, func_021FF498, func_021FF4C0, func_021FF5B0, func_021FF630, func_021FF6B0, func_021FF730, func_021FF7B0, func_021FF870, func_021FF924, func_021FFA18, func_021FFB04, func_021FFBBC, func_021FFCB0, func_021FFD6C, func_021FFD9C, func_021FFDB4, func_021FFDF8, func_021FFE24, func_021FFE48, func_021FFF0C, func_021FFF38, func_021FFF68, func_021FFFAC, func_021FFFD8, func_02200108, func_02200140, func_022001DC, func_02200218, func_02200344, func_022003C4, func_022003EC, func_0220041C, func_02200468, func_02200494, func_022004BC, func_0220055C, func_022005C4, func_02200608, func_02200654, func_022006A0, func_022006B4, func_0220074C, func_02200904, func_02200990, func_022009C8, func_02200A50, func_02200A84, func_02200B10, func_02200B48, func_02200BD4, func_02200C0C, func_02200C98, func_02200CD0, func_02200D30, func_02200D68, func_02200DE4, func_02200E1C, func_02201098, func_022010D0, func_022011FC, func_02201234, func_022012CC, func_02201304, func_02201408, func_02201700, func_02201718, func_02201810, func_02201894, func_022018A8, func_02201934, func_022019F4, func_02201A20
 * address:  0x021FEAC0
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
 *   func_020307B0  0x020307B0  arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   func_02030EAC 0x02030EAC arm
 *   func_02030DA8  0x02030DA8  arm
 *   TCBL_IsDeletePending   0x02030EE8  arm
 *   func_0203F0A8 0x0203F0A8 arm
 *   FX_Div_Alt  0x0207C768  arm
 *   func_02030734  0x02030734  arm
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 *   MCSS_Init  0x02014B08  thumb
 *   MCSS_SetSysParam  0x020163B0  thumb
 *   MCSS_SetSysFlag  0x020163B4  thumb
 *   d_0220AE7C     0x0220AE7C  data   ov094
 *   MCSS_Exit  0x02014BA8  thumb
 *   MCSS_RestartAnime 0x02016374 thumb
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw  0x02014D2C  thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_02017EAC 0x02017EAC thumb
 *   func_02019C90 0x02019C90 thumb
 *   func_0202D034 0x0202D034 thumb
 *   MCSS_Add 0x020159C8 thumb
 *   MCSS_SetShadowAlpha 0x02015FD4 thumb
 *   MCSS_SetShadowOffset 0x02015D94 thumb
 *   MCSS_SetShadowRotateZ 0x02015D88 thumb
 *   MCSS_SetAnimCallback 0x02015F2C thumb
 *   MCSS_Del  0x02015BA4  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_SetOrthoMode   0x02015BF0  thumb
 *   MCSS_ResetOrthoMode   0x02015C00  thumb
 *   MCSS_SetOrthoBillboardFlag  0x02015C0C  thumb
 *   MCSS_ResetOrthoBillboardFlag  0x02015C1C  thumb
 *   MCSS_SetMepachiFlag  0x02015DB0  thumb
 *   MCSS_ResetMepachiFlag  0x02015DC0  thumb
 *   MCSS_FlipMepachiFlag  0x02015DD4  thumb
 *   MCSS_GetAnmStopFlag  0x02015DF8  thumb
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetAnmStopFlagAlways  0x02015E28  thumb
 *   MCSS_ResetAnmStopFlagAlways  0x02015E70  thumb
 *   MCSS_ResetAnmStopFlag  0x02015E4C  thumb
 *   MCSS_GetVanishFlag  0x02015E94  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_FlipVanishFlag  0x02015EC4  thumb
 *   d_0220A050  0x0220A050  data  ov094
 *   d_0220A080  0x0220A080  data  ov094
 *   d_0220A158  0x0220A158  data  ov094
 *   d_0220A1A0  0x0220A1A0  data  ov094
 *   MCSS_SetShadowVanishFlag  0x02015FF0  thumb
 *   MCSS_SetAnimeSpeed  0x020160C4  thumb
 *   MCSS_GetPosition 0x02015C30 thumb
 *   MCSS_GetShadowScale  0x02015CC4  thumb
 *   MCSS_GetScale  0x02015C94  thumb
 *   MCSS_GetRotate  0x02015CF8  thumb
 *   BTLV_GAUGE_HideSlot  0x022089BC  thumb  ov094
 *   MCSS_GetAlpha 0x02015FAC thumb
 *   MCSS_GetMosaic 0x02016068 thumb
 *   MCSS_CheckPaletteFade  0x0201600C  thumb
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   MCSS_CreatePaletteTransTask  0x020160D4  thumb
 *   MCSS_CreatePaletteCopyTask  0x0201624C  thumb
 *   MCSS_GetStopCellFlags  0x02015F24  thumb
 *   MCSS_TOOL_SetSpindaSpotHook 0x020172AC thumb
 *   MCSS_ReloadResource 0x02014CF8 thumb
 *   POKEGRA_GetArcID 0x0202D060 thumb
 *   MCSS_SetMosaic  0x02016078  thumb
 *   BTL_MAIN_GetVoiceOfSlot  0x021B994C  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   PM_VOICE_AddVolume  0x02006A8C  thumb
 *   PM_VOICE_AddFrequency  0x02006AEC  thumb
 *   d_02209FC0  0x02209FC0  data  ov094
 *   d_02209FE0  0x02209FE0  data  ov094
 *   d_02209FF0  0x02209FF0  data  ov094
 *   d_0220A068  0x0220A068  data  ov094
 *   MCSS_TOOL_MakeAddWorkFromPP  0x02017100  thumb
 *   MCSS_GetAnimSeqNumEx  0x020160CC  thumb
 *   MCSS_SetAnimeIndex   0x02016028  thumb
 *   MCSS_GetOfsPosition  0x02015C60  thumb
 *   MCSS_SetOfsPosition  0x02015C78  thumb
 *   MCSS_SetWorkFlag  0x02016394  thumb
 *   MCSS_TOOL_MakeAddWorkFromTrainer  0x02017214  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   MCSS_SetOfsScale  0x02015D30  thumb
 *   MCSS_SetShadowScale  0x02015CDC  thumb
 *   MCSS_GetDrawScale  0x02015D4C  thumb
 *   MCSS_SetDrawScale  0x02015D64  thumb
 *   MCSS_SetRotate  0x02015D14  thumb
 *   MCSS_SetAlpha  0x02015FBC  thumb
 *   MCSS_GetAnimCtrl 0x02015EE8 thumb
 *   MCSS_SetCellCallback 0x02015F40 thumb
 *   d_0220AE78 0x0220AE78 data a4
 *   d_0220A0C8     0x0220A0C8  data
 *   d_0220A0B0     0x0220A0B0  data
 *   d_0220A0E0     0x0220A0E0  data
 *   MCSS_GetStopCellNum 0x02015EF4 thumb
 *   MCSS_GetAnimSeqNum 0x02015EEC thumb
 *   MCSS_GetStopCellIndex  0x02015EFC  thumb
 *   d_0220A110  0x0220A110  data  ov094
 *   d_02209FC8  0x02209FC8  data  ov094
 *   d_02209FD0  0x02209FD0  data  ov094
 *   d_0220A008  0x0220A008  data  ov094
 *   d_0220A020  0x0220A020  data  ov094
 *   d_0220A038  0x0220A038  data  ov094
 *   d_0220A1E8  0x0220A1E8  data  ov094
 *   d_0220A1EA  0x0220A1EA  data  ov094
 *   d_0220A1EC  0x0220A1EC  data  ov094
 *   d_0220A1EE  0x0220A1EE  data  ov094
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021F89BC 0x021F89BC thumb ov094
 *   func_021F918C 0x021F918C thumb ov094
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_021F6AA8 0x021F6AA8 thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021F821C 0x021F821C thumb ov094
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_021F86A4 0x021F86A4 thumb ov094
 *   func_021F86B4 0x021F86B4 thumb ov094
 *   func_021F86C4 0x021F86C4 thumb ov094
 *   func_021F8710 0x021F8710 thumb ov094
 *   func_021F8754 0x021F8754 thumb ov094
 *   func_021F935C 0x021F935C thumb ov094
 *   func_021F9824 0x021F9824 thumb ov094
 */
#include "../../matched/include/Obj13604.h"
#include "../../matched/include/Obj12218.h"
#include "../../matched/include/Obj12219.h"
#include "../../matched/include/Obj12220.h"
#include "../../matched/include/Obj06309.h"
#include "../../matched/include/Obj12223.h"
#include "../../matched/include/Obj12224.h"
#include "../../matched/include/Obj01047.h"
#include "../../matched/include/Obj12226.h"
#include "../../matched/include/Obj12228.h"
#include "../../matched/include/Obj06316.h"
#include "../../matched/include/Obj00264.h"
#include "../../matched/include/Obj06318.h"
#include "../../matched/include/Obj02439.h"
#include "../../matched/include/Obj06319.h"
#include "../../matched/include/Obj05243.h"
#include "../../matched/include/Obj21725.h"
#include "../../matched/include/Obj21726.h"
#include "../../matched/include/Obj21727.h"
#include "../../matched/include/Obj21729.h"
#include "../../matched/include/Obj13608.h"
#include "../../matched/include/Obj12236.h"
#include "btlv_effvm_types.h"
#include "btlv_stage_shared_types.h"
#include "btlv_camera_shared_types.h"
#include "btlv_effect_shared_types.h"
#include "btlv_effvm_shared_types.h"
#include "btlv_mcss_shared_types.h"

#define FIX(x) ((int)(((x) > 0.0f) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))

struct McssSys;

struct Obj_vE254;

struct Sub150;

struct McssFade;

struct Sub02014CF8Ctx;

struct Sub02014CF8Rec;

struct Stats;

typedef struct {
    unsigned int f0 : 10;
    unsigned int f10 : 1;
} Flags_vE254;

typedef struct {
    Flags_vE254 fl;
    char pad04[0x268];
    int tbl[6];
} Obj_vE254;

typedef struct { int x, y, z; } Vec_021FE254;

typedef struct { Vec_021FE254 orient, pos; } Vectors;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b34 : 2;
    unsigned int b5 : 1;
} Flags_021FEEA8;

typedef struct { u32 x, y, z; } Vec_021FF088;

typedef struct {
    int x, y, z;
} Vec3_vF7B0;

typedef struct {
    Work_021FF870 *w;                /* 0x00 */
    int i;                  /* 0x04 */
    char pad08[0x0c];
    int kind;               /* 0x14 */
    char pad18[0x2c];
    int f44;                /* 0x44 */
    int f48;                /* 0x48 */
    int f4c;                /* 0x4c */
    int f50;                /* 0x50 */
} Obj_021FF870;

typedef struct {
    int w[9];
} Rec_vFE24;

typedef struct {
    void *h;                /* 0x00 */
    Rec_vFE24 rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry_vFE24;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE24 e[14];            /* 0x008 */
} Work_vFE24;

typedef struct { u32 v[9]; } Rec_021FFFD8;

typedef struct {
    int w[9];
} Rec_02200108;

typedef struct {
    void *h;                /* 0x00 */
    Rec_02200108 rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry_02200108;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200108 e[14];            /* 0x008 */
} Work_02200108;

typedef struct {
    Work_02200344 *w;                /* 0x00 */
    u32 a : 31;             /* 0x04 */
    u32 flag : 1;
    int f8;                 /* 0x08 */
    int fc;                 /* 0x0c */
} Obj_vFE48;

typedef struct {
    int x, y, z;
} Vec_vFE48;

typedef enum { SLOT_FE48_0, SLOT_FE48_MAX = 8 } Slot_021FFE48;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_022006B4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_022006B4 e[14];            /* 0x008 */
    char pad[0x534 - 0x008 - 14 * 0x5c];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
} Work_022006B4;

typedef struct {
    fx32 x, y, z;
} VecFx32_vFE48;

typedef struct {
    void *owner;        /* 0x000 */
    char pad[0x540 - 4];
    u16 heap;           /* 0x540 */
} Work_0220074C;

typedef struct {
    Work_0220074C *w;            /* 0x00 */
    int i;              /* 0x04 */
    VecFx32_vFE48 cur;        /* 0x08 */
    int kind;           /* 0x14 */
    VecFx32_vFE48 start;      /* 0x18 */
    VecFx32_vFE48 end;        /* 0x24 */
    VecFx32_vFE48 step;       /* 0x30 */
    int frames;         /* 0x3c */
    int left;           /* 0x40 */
    int count;          /* 0x44 */
    int f48;            /* 0x48 */
    int f4c;            /* 0x4c */
    int f50;            /* 0x50 */
} Mover_0220074C;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_0220074C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_0220074C e[14];            /* 0x008 */
    char pad[0x542 - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x542 */
} Work_02200904;

typedef struct {
    char body[0x3c];
} Mover_02200904;

typedef struct {
    Work_02200904 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_02200904 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_021FFE48;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_vFE48;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x514 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x514 */
    char pad518[0x542 - 0x518];
    u8 tag[1];              /* 0x542 */
} Work_02200990;

typedef struct {
    char body[0x3c];
} Mover_vFE48;

typedef struct {
    Work_02200990 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200990;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x550 - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x550 */
} Work_vFE48;

typedef struct {
    Work_vFE48 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_vFE48;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x518 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x518 */
    char pad51c[0x550 - 0x51c];
    u8 tag[1];              /* 0x550 */
} Work_02200A50;

typedef struct {
    Work_02200A50 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200A50;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x55e - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x55e */
} Work_02200A84;

typedef struct {
    Work_02200A84 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200A84;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x520 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x520 */
    char pad524[0x55e - 0x524];
    u8 tag[1];              /* 0x55e */
} Work_02200B10;

typedef struct {
    Work_02200B10 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200B10;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x56c - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x56c */
} Work_02200B48;

typedef struct {
    Work_02200B48 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200B48;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x524 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x524 */
    char pad528[0x56c - 0x528];
    u8 tag[1];              /* 0x56c */
} Work_02200BD4;

typedef struct {
    Work_02200BD4 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200BD4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x57a - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x57a */
} Work_02200C0C;

typedef struct {
    Work_02200C0C *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200C0C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x51c - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x51c */
    char pad520[0x57a - 0x520];
    u8 tag[1];              /* 0x57a */
} Work_02200C98;

typedef struct {
    Work_02200C98 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200C98;

typedef struct {
    char pad000[0x588];
    u8 tag[1];              /* 0x588 */
} Work_02200CD0;

typedef struct {
    Work_02200CD0 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x3c];
    int wait;               /* 0x44 */
    int reload;             /* 0x48 */
    int count;              /* 0x4c */
    int tag;                /* 0x50 */
} Ctx_02200CD0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_v0D30;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_v0D30 e[14];            /* 0x008 */
    char pad[0x528 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x528 */
    char pad52c[0x588 - 0x52c];
    u8 tag[1];              /* 0x588 */
} Work_v0D30;

typedef struct {
    char body[0x3c];
} Mover_v0D30;

typedef struct {
    Work_v0D30 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_v0D30 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_v0D30;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_v0DE4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_v0DE4 e[14];            /* 0x008 */
    char pad[0x52c - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x52c */
    char pad530[0x596 - 0x530];
    u8 tag[1];              /* 0x596 */
} Work_v0DE4;

typedef struct {
    char body[0x3c];
} Mover_v0DE4;

typedef struct {
    Work_v0DE4 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_v0DE4 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_v0DE4;

typedef struct Vec_021FFE48 { int x, y, z; } Vec_021FFE48;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_v1098;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_v1098 e[14];            /* 0x008 */
    char pad[0x514 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x514 */
    char pad518[0x542 - 0x518];
    u8 tag[1];              /* 0x542 */
} Work_v1098;

typedef struct {
    char body[0x24];
} Mover_v1098;

typedef struct {
    Work_v1098 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_v1098 mv;               /* 0x14 */
    int tag;                /* 0x38 */
} Ctx_v1098;

typedef struct Vec_02201098 { int x, y, z; } Vec_02201098;

typedef struct {
    char body[0x14];
} Mover_022011FC;

typedef struct {
    Work_v1098 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_022011FC mv;               /* 0x14 */
    int tag;                /* 0x28 */
} Ctx_022011FC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_v1098 e[14];            /* 0x008 */
    char pad[0x530 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x530 */
    char pad534[0x5a4 - 0x534];
    u8 tag[1];              /* 0x5a4 */
} Work_022012CC;

typedef struct {
    char body[0x3c];
} Mover_022012CC;

typedef struct {
    Work_022012CC *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_022012CC mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_022012CC;

typedef struct {
    int x, y, z;
} Vec_022011FC;

typedef struct {
    int v[2][3];
} Tab6;

typedef struct {
    int v[2][2][3];
} Tab12;

typedef struct {
    char pad00[0x30];
    int busy;           /* 0x30 */
    char pad34[0x1c];
    int target;         /* 0x50 */
    char pad54[0x08];
} Slot_02201098;

typedef struct {
    char *p;            /* 0x00 */
    u32 state : 31;     /* 0x04 */
    u32 sound : 1;
    int idx;            /* 0x08 */
    int dir;            /* 0x0c */
    int ang[3];         /* 0x10 */
    int cnt;            /* 0x1c */
    int step;           /* 0x20 */
} Work_02201408;

typedef struct Flags_02201098 { unsigned low:3; unsigned count:2; unsigned high:27; } Flags_02201098;

typedef struct GlobalFlags { unsigned low:2; unsigned disabled:1; unsigned high:29; } GlobalFlags;

typedef struct {
    int pad[2];
    void *h;
    char pad2[0x5C - 12];
} Row;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags_02201894;

typedef struct {
    char pad[0x510];
    Flags_02201894 flags;
} Unit_v1098;

typedef signed short s16_02201894;

typedef struct {
    u16 key : 14;
    u16 flag : 1;
    u16 hi : 1;
} Ent_02201894;

extern void *sub_02030734(u32, u32, int, const char *, u16);

extern u32 func_020307B0(void *p);

extern void func_02030EAC(struct Node *n);

extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 n);

extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);

extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);

extern u32 func_0203F0A8(void);

extern u32 FX_Div_Alt(u32 a, u32 b);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void GFL_USE_StopSeSlot(int i);

extern void GFL_USE_PlaySeInSlot(void *arg, int i);

extern void *MCSS_Init(u32 id, void *heap);

extern void MCSS_SetSysParam(char *p, int v);

extern void MCSS_SetSysFlag(void *o, int v);

extern void MCSS_Exit(u8 *a0);

extern void MCSS_RestartAnime(void *h);

extern void MCSS_Main(char *self);

void MCSS_Draw(struct McssSys *sys);

extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);

extern u32 func_02017EAC(void *p);

extern u32 func_02019C90(u16, u16, u32);

extern int func_0202D034(u32, u32);

extern struct Rec_vE254 *MCSS_Add(struct Obj_vE254 *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);

extern void MCSS_SetShadowAlpha(char *p, int v);

extern void MCSS_SetShadowOffset(char *p, int *src);

extern void MCSS_SetShadowRotateZ(char *p, u16 value);

extern void MCSS_SetAnimCallback(void *, u32, void *, u32);

extern void MCSS_Del(void *obj, void *h);

extern void MCSS_SetPosition(void *p, u32 *src);

extern void MCSS_SetOrthoMode(void *obj);

extern void MCSS_ResetOrthoMode(void *obj);

extern void MCSS_SetOrthoBillboardFlag(void *h);

extern void MCSS_ResetOrthoBillboardFlag(void *h);

extern void MCSS_SetMepachiFlag(void *p);

extern void MCSS_ResetMepachiFlag(void *p);

extern void MCSS_FlipMepachiFlag(void *p);

extern int MCSS_GetAnmStopFlag(void *h);

extern void MCSS_SetAnmStopFlag(void *p);

extern void MCSS_SetAnmStopFlagAlways(void *p);

extern void MCSS_ResetAnmStopFlagAlways(void *p);

extern void MCSS_ResetAnmStopFlag(void *p);

extern int MCSS_GetVanishFlag(void *h);

extern void MCSS_SetVanishFlag(void *h);

extern void MCSS_ResetVanishFlag(void *h);

extern void MCSS_FlipVanishFlag(void *h);

extern void MCSS_SetShadowVanishFlag(char *p, int v);

extern void MCSS_SetAnimeSpeed(char *p, int v);

extern void MCSS_GetPosition(void *p, u32 *out);

extern void MCSS_GetShadowScale(void *p, u32 *out);

extern void MCSS_GetScale(void *p, u32 *out);

extern void MCSS_GetRotate(void *p, u32 *out);

extern void BTLV_GAUGE_HideSlot(char *p, int i);

extern u8 MCSS_GetAlpha(void *p);

extern u8 MCSS_GetMosaic(void *p);

extern int MCSS_CheckPaletteFade(void *h);

extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);

extern void MCSS_CreatePaletteTransTask(void *obj, void *h, int a, int b);

extern void MCSS_CreatePaletteCopyTask(u8 *a0, u8 *a1);

extern int MCSS_GetStopCellFlags(void *h);

extern void MCSS_TOOL_SetSpindaSpotHook(int a0, int a1);

extern void MCSS_ReloadResource(void *a, struct Sub02014CF8Ctx *b, const struct Sub02014CF8Rec *c);

extern int POKEGRA_GetArcID(void);

extern void MCSS_SetMosaic(void *obj, void *h, int v);

extern void MCSS_ReloadResource(void *a, struct Sub02014CF8Ctx *b, const struct Sub02014CF8Rec *c);

extern int BTL_MAIN_GetVoiceOfSlot(void *p, int key, u32 *out);

extern u32 PM_VOICE_Play(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

extern void PM_VOICE_AddVolume(u32 idx, int delta);

extern void PM_VOICE_AddFrequency(u32 idx, u32 delta);

extern void MCSS_TOOL_MakeAddWorkFromPP(void *p, struct Stats *out, u32 lvl);

extern int MCSS_GetAnimSeqNumEx(void *h);

extern void MCSS_SetAnimeIndex(void *h, u32 n);

extern void MCSS_GetOfsPosition(void *p, u32 *out);

extern void MCSS_SetOfsPosition(void *p, u32 *src);

extern void MCSS_SetWorkFlag(void *h, int flag);

extern void MCSS_TOOL_MakeAddWorkFromTrainer(void *p, struct Stats *out, void *q);

extern void MCSS_SetScale(void *p, u32 *src);

extern void MCSS_SetOfsScale(void *p, u32 *src);

extern void MCSS_SetShadowScale(void *p, u32 *src);

extern void MCSS_GetDrawScale(void *p, u32 *out);

extern void MCSS_SetDrawScale(void *p, u32 *src);

extern void MCSS_SetRotate(void *p, u32 *src);

extern void MCSS_SetAlpha(char *p, int v);

extern void *MCSS_GetAnimCtrl(void *);

extern void MCSS_SetCellCallback(char *p, unsigned flags, void *callback);

extern void MCSS_SetAnimeIndex(void *, u32);

extern u8 MCSS_GetStopCellNum(char *p);

extern u16 MCSS_GetAnimSeqNum(char *p);

extern u8 MCSS_GetStopCellIndex(char *p, u8 i);

void func_021F6AA8(Obj_021F6AA8 *p, int i, int j, int a, int b);

int func_021F7EB4(void);

int func_021F821C(int a, int *b, int *c);

int func_021F8694(void);

int func_021F86A4(void);

int func_021F86B4(void);

int func_021F86C4(void);

int func_021F8710(void);

int func_021F8754(void);

void func_021F896C(void *h, void (*cb)(void *), int arg);

void func_021F89BC(void *h);

void func_021F918C(const VecFx32_021F8F30 *a, const VecFx32_021F8F30 *b, VecFx32_021F8F30 *out, fx32 div);

int func_021F9260(Mover_v8204 *m, VecFx32_021F8F30 *out);

int func_021F935C(int x);

int func_021F9824(void *a);

Work_021FEAC0 *func_021FEAC0(int mode, int a1, u16 a2);

void func_021FEB78(Work_021FEB78 *w);

void func_021FEBAC(Work_021FEBAC *w);

void func_021FEE9C(int *p);

void func_021FEEA8(char *w, void *src, int key);

void func_021FF088(Work_vE254 *w, void *src, int key);

void func_021FF0F8(Work_021FF0F8 *w, int key);

void func_021FF134(char *p, int a, int b);

void func_021FF144(Work_021FF144 *w, int key, fx32 x, fx32 y, fx32 z);

void func_021FF16C(Work_021FF16C *w);

void func_021FF1B0(Work_021FF1B0 *w);

void func_021FF1F4(Work_vE254 *w, int key);

void func_021FF228(Work_021FF228 *w, int key);

void func_021FF260(Work_021FF228 *w, int key, int mode);

int func_021FF2D8(Work_021FF228 *w, int key);

void func_021FF304(Work_021FF228 *w, int key, int mode);

int func_021FF348(Work_021FF348 *w, int key);

void func_021FF374(Work_vF228 *w, int key, int kind);

void func_021FF3F4(void *obj, void *out, int idx);

void func_021FF3FC(const Vec3_vF228 *def, Vec3_vF228 *out, int idx, int kind);

int func_021FF468(void *u, int i, int mode);

void func_021FF470(char *p, int key, u8 v);

void func_021FF498(char *p, int key, void *v);

void func_021FF4C0(char *w, int key, int kind, Vec_021F6560 *q, int a, int b, int c);

void func_021FF5B0(Work_021FF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c);

void func_021FF630(Work_021FF630 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c);

void func_021FF6B0(Work_vF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c);

void func_021FF730(Work_vF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c);

void func_021FF7B0(Work_021FF7B0 *w, int a, int b);

void func_021FF870(Work_021FF870 *w, int key, int kind, int a, int b);

void func_021FF924(char *w, int key, int kind, int value, int a, int b, int c);

void func_021FFA18(Work_021FFA18 *w, Obj_021FFA18 *s);

void func_021FFB04(Work_vF7B0 *w, Obj_vF7B0 *s);

void func_021FFBBC(char *w, int key, int kind, int value, int a, int b, int c);

int func_021FFCB0(Work_021FFCB0 *w, int key);

int func_021FFD6C(Work_021FFD6C *w);

int func_021FFD9C(char *p, int key);

void func_021FFDB4(Work_vFCB0 *w, int key, u8 cur, u8 target, u8 step, u32 e);

void func_021FFDF8(Work_vFCB0 *w, int key, int a, int b);

void func_021FFE24(Work_vFE24 *w, int key);

void func_021FFE48(Work_021FFE48 *w, int key, void *p);

int func_021FFF0C(char *p, int key);

int func_021FFF38(char *p, int key);

int func_021FFF68(Work_021FFF68 *w, int key);

int func_021FFFAC(Work_021FFFAC *w, int key);

void func_021FFFD8(char *w, int key, int flag, int clear);

void func_02200108(Work_02200108 *w, int key, int v);

void func_02200140(Work_02200140 *w, int key1, int key2);

void func_022001DC(Work_022001DC *w, int key, Rec_022001DC *r);

int func_02200218(Work_02200218 *w, int key, int pitch, int pan, int a4, int a5, int a6);

void func_02200344(Work_02200344 *w, int a, int b, int flag);

int func_022003C4(char *p, int key);

void func_022003EC(Work_022003EC *w, void *p, int *a, int flags);

int func_0220041C(Work_0220041C *w, int key, int n);

void func_02200468(Work_02200468 *w, int key);

int func_02200494(char *p, int key);

void func_022004BC(Work_022004BC *w, int key);

void func_0220055C(Work_0220055C *w, int key, int mode);

int func_022005C4(Work_022005C4 *w, int key);

void func_02200608(Work_02200608 *w);

void func_02200654(Work_02200654 *w);

void func_022006A0(void *p, void *out, int flags);

void func_022006B4(Work_022006B4 *w, int i);

void func_0220074C(Work_0220074C *w, int i, int kind, VecFx32_vFE48 *p, VecFx32_vFE48 *q, int n, int f48, int f4c, void *fn, void (*cb)(void *), int flip, u8 f50);

void func_02200904(void *h, Ctx_021FFE48 *c);

void func_02200990(void *h);

void func_022009C8(void *h, Ctx_vFE48 *c);

void func_02200A50(void *h);

void func_02200A84(void *h, Ctx_02200A84 *c);

void func_02200B10(void *h);

void func_02200B48(void *h, Ctx_02200B48 *c);

void func_02200BD4(void *h);

void func_02200C0C(void *h, Ctx_02200C0C *c);

void func_02200C98(void *h);

void func_02200CD0(void *h, void *arg);

void func_02200D30(void *h);

void func_02200D68(void *o, char *q);

void func_02200DE4(void *h);

void func_02200E1C(void *task, void *arg);

void func_02201098(void *h);

void func_022010D0(void *task, void *arg);

void func_022011FC(void *h);

void func_02201234(void *o, char *q);

void func_022012CC(void *h);

void func_02201304(void *task, void *arg);

void func_02201408(void *task, void *arg);

void func_02201700(void *h);

void func_02201718(int i);

int func_02201810(u32 flags, int a, int *out, int key);

void func_02201894(int i);

void func_022018A8(Unit_v1098 *u, Vec3_vF228 *out, int i);

int func_02201934(Unit_v1098 *u, int i, int mode);

int func_022019F4(char *p, int key);

int func_02201A20(int a, int b, int *o1, u16 *o2, int *o3);

extern const s16_021F6560 FX_SinCosTable_[];

extern char d_0220AE7C[];

extern const Vec3_vF228 d_0220A050[];

extern const Vec3_vF228 d_0220A080[];

extern const Vec3_vF228 d_0220A158[];

extern const Vec3_vF228 d_0220A1A0[];

extern u32 d_02209FC0[];

extern u32 d_02209FE0[];

extern u32 d_02209FF0[];

extern u32 d_0220A068[];

extern const u8 d_0220AE78[];

extern const Tab6 d_0220A0C8;

extern const Tab6 d_0220A0B0;

extern const Tab12 d_0220A0E0;

extern const Vec3_vF228 d_0220A110[];

extern const int d_02209FC8[];

extern const int d_02209FD0[];

extern const int d_0220A008[];

extern const int d_0220A020[];

extern const int d_0220A038[];

extern const char d_0220A1E8[];

extern const char d_0220A1EA[];

extern const char d_0220A1EC[];

extern const char d_0220A1EE[];

#define FX(x) ((int)(((x) > 0) ? ((float)((x) << 12) + .5f) : ((float)((x) << 12) - .5f)))

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * Lever: `u16 a2` (the strh of the heap id makes the parameter 16-bit; it
 * is spilled at entry and reloaded, as the image does).
 *
 * witness outside the range): MCSS_SetSysParam (0x020163B0) and MCSS_SetSysFlag
 * (0x020163B4).  Both are the integrator's; verified C (one --thumb, no --region,
 * EXACT each):
 *     void MCSS_SetSysParam(char *p, int v) { *(int *)(p + 0x48) = v; }
 *     typedef struct { char pad[0x2c]; unsigned int b0 : 1; unsigned int b1 : 1; } Obj_vE254;
 *     void MCSS_SetSysFlag(Obj_vE254 *p, int v) { p->b1 = v; }
 * Re-run this file once layout/matched/arm9 shards for both exist.
 */
Work_021FEAC0 *func_021FEAC0(int mode, int a1, u16 a2)
{
    Work_021FEAC0 *w;
    int v = 0xe;
    int i;

    w = func_02030734(a2, 0x5b4, 1, d_0220AE7C, 0x184);
    w->obj = MCSS_Init(v, (void *)a2);
    w->cb = (int *)a1;
    w->heap = a2;
    v += 0xf2;
    MCSS_SetSysParam(w->obj, v);
    MCSS_SetSysFlag(w->obj, 1);
    w->active = 1;
    w->scaleEven = 0x1000;
    w->scaleOdd = 0x1000;
    w->flags.b0 = (mode == 2);
    w->flags.b1 = (mode == 3);
    for (i = 0; i < 14; i++)
        w->e[i].k48 = 0xff;
    return w;
}

void func_021FEB78(Work_021FEB78 *w)
{
    Key_021FD04C i;

    for (i = 0; i < 14; i++) {
        if (func_021FFD9C((char *)w, i))
            func_021FF0F8((Work_021FF0F8 *)w, i);
    }
    MCSS_Exit(w->obj);
    func_020307B0(w);
}

/*
 * lever: enum loop counter keeps both entry guards; a separate local k for the
 *   first loop index puts idx at sp+8 and flag at sp+4 (one shared idx swapped them).
 */
void func_021FEBAC(Work_021FEBAC *w)
{
    Key_021FD04C i;
    int k;
    int idx;
    int flag;
    int a;
    int b;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)w, i)) {
            k = func_022019F4((char *)w, i);
            if (w->e[k].f11) {
                w->e[k].f11 = 0;
                MCSS_RestartAnime(w->e[k].h);
            }
        }
    }
    MCSS_Main(w->obj);
    if (w->f510 == 0) {
        for (i = 0; i < 8; i++) {
            if (func_021FFD9C((char *)w, i)
                && (u32)(((u64)func_0203F0A8() * 100) >> 32) == 0
                && (func_021F935C(i) & w->m528) == 0
                && func_021FF2D8((Work_021FF228 *)w, i) == 0)
                func_021FF870((Work_021FF870 *)w, i, 2, 4, 1);
            if (func_021FFD9C((char *)w, i) == 0)
                continue;
            idx = func_022019F4((char *)w, i);
            flag = 0;
            if (func_021F7EB4() && w->e[idx].f8) {
                w->e[idx].f8 = 0;
                w->e[idx].f7 = 1;
            }
            if (func_021F7EB4() && w->e[idx].f7)
                continue;
            w->e[idx].f7 = 0;
            if (func_021FFF38((char *)w, i) & 4)
                continue;
            if (func_021F821C(i, &a, &b) == 0)
                continue;
            if (w->e[idx].f1 == 1) {
                if (w->e[idx].f54 == 0)
                    w->e[idx].f54 = 1;
                if (w->e[idx].f58++ > 0x18) {
                    flag = 1;
                    w->e[idx].f58 = 0;
                    w->e[idx].f50 += w->e[idx].f54;
                    if (w->e[idx].f50 == 0 || w->e[idx].f50 == 12)
                        w->e[idx].f54 *= -1;
                }
            }
            switch (b) {
            case 3:
                func_021FFE24((Work_vFE24 *)w, i);
                func_021FF260((Work_021FF228 *)w, i, 3);
                func_021FF304((Work_021FF228 *)((char *)w), i, 3);
                func_021FF498((char *)w, i, (void *)0x555);
                w->e[idx].f1 = 1;
                break;
            case 1:
                if (flag == 1)
                    func_021FFDF8((Work_vFCB0 *)w, i, (u8)w->e[idx].f50, 0x1ef);
                func_021FF260((Work_021FF228 *)w, i, 4);
                func_021FF304((Work_021FF228 *)((char *)w), i, 3);
                w->e[idx].f1 = 1;
                break;
            case 2:
                if (flag == 1)
                    func_021FFDF8((Work_vFCB0 *)w, i, 8, 0x7def);
                func_021FF260((Work_021FF228 *)w, i, 4);
                func_021FF304((Work_021FF228 *)((char *)w), i, 2);
                w->e[idx].f1 = 1;
                break;
            case 5:
                if (flag == 1)
                    func_021FFDF8((Work_vFCB0 *)w, i, (u8)w->e[idx].f50, 0xf);
                func_021FF260((Work_021FF228 *)w, i, 4);
                func_021FF304((Work_021FF228 *)((char *)w), i, 3);
                w->e[idx].f1 = 1;
                break;
            case 4:
            case 7:
                if (flag == 1)
                    func_021FFDF8((Work_vFCB0 *)w, i, (u8)w->e[idx].f50, 0x3c0f);
                func_021FF260((Work_021FF228 *)w, i, 4);
                func_021FF304((Work_021FF228 *)((char *)w), i, 3);
                w->e[idx].f1 = 1;
                break;
            case 8:
            default:
                if (w->e[idx].f1 == 1) {
                    func_021FFE24((Work_vFE24 *)w, i);
                    func_021FF260((Work_021FF228 *)w, i, 4);
                    func_021FF304((Work_021FF228 *)((char *)w), i, 3);
                    func_021FF498((char *)w, i, (void *)0x1000);
                    w->e[idx].f1 = 0;
                    w->e[idx].f54 = 0;
                    w->e[idx].f50 = 0;
                    w->e[idx].f58 = 0;
                }
                break;
            }
            if (b == 8) {
                if ((u32)(a - 2) <= 1)
                    func_021FF498((char *)w, i, (void *)0x555);
                else
                    func_021FF498((char *)w, i, (void *)0x1000);
            }
        }
    }
}

void func_021FEE9C(int *p)
{
    MCSS_Draw((struct McssSys *)p[1]);
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 * levers: grouped vectors fix stack order; integer address arithmetic on the
 * second buffer argument prevents CSE; b34 is one two-bit assignment.
 * Verified scratch C, EXACT (blocker_02015D94_r1.log):
 * void MCSS_SetShadowOffset(char *p, int *src) {
 *     *(int *)(p + 0x17c) = src[0];
 *     *(int *)(p + 0x180) = src[1];
 *     *(int *)(p + 0x184) = src[2];
 * }
 * Verified scratch C, EXACT (blocker_02015D88_r1.log):
 * typedef unsigned short u16;
 * void MCSS_SetShadowRotateZ(char *p, u16 value) { *(u16 *)(p + 0x17a) = value; }
 */
void func_021FEEA8(char *w, void *src, int key)
{
    int i;
    int off;
    int visible;
    u16 angle;
    Vectors vectors;
    u32 a, b;
    for (i = 0; i < 14; i++) {
        if (*(void **)(w + i * 0x5c + 8) == 0)
            break;
    }
    if (key < 14 && i < 14) {
        off = i * 0x5c;
        *(int *)(w + 0x48 + off) = 0;
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b0 = 0;
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b1 = 0;
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b5 = 0;
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b2 = ((struct Obj13604 *)w)->f534;
        *(int *)(w + 0x50 + off) = key;
        *(u32 *)(w + 0x3c + off) = POKE_TOOL_GetPartyValue(src, 0, 0);
        *(u32 *)(w + 0x44 + off) = POKE_TOOL_GetPartyValue(src, 0x98, 0);
        if (func_02017EAC(src) == 1)
            *(int *)(w + 0x48 + off) |= 2;
        func_022003EC((Work_022003EC *)w, src, (int *)(w + 0xc + off), key);
        func_022018A8((Unit_v1098 *)w, (Vec3_vF228 *)((Vec_021FE254 *)(&vectors.pos)), key);
        *(void **)(w + 8 + off) = MCSS_Add(((struct Obj13604 *)w)->f4, vectors.pos.x, vectors.pos.y, vectors.pos.z, (void *)((u32)w + 0xc + off));
        func_0220055C((Work_0220055C *)w, key, 1);
        *(u32 *)(w + 0x34 + off) = POKE_TOOL_GetPartyValue(src, 5, 0);
        *(u32 *)(w + 0x38 + off) = POKE_TOOL_GetPartyValue(src, 0x6f, 0);
        *(u16 *)(w + 0x40 + off) = func_02019C90(*(u32 *)(w + 0x34 + off), *(u32 *)(w + 0x38 + off), 0x26);
        a = POKE_TOOL_GetPartyValue(src, 0xa0, 0);
        b = POKE_TOOL_GetPartyValue(src, 0xa1, 0);
        *(u16 *)(w + 0x42 + off) = func_0202D034(a, b);
        if (func_02201A20(*(int *)(w + 0x34 + off), key, (int *)(&vectors.orient), &angle, &visible) == 0) {
            vectors.orient.x = -0x400;
            vectors.orient.y = 0;
            vectors.orient.z = -0x600;
            angle = 0xf800;
            visible = 1;
        }
        if (visible == 0)
            MCSS_SetShadowAlpha(*(void **)(w + 8 + off), 0);
        else {
            MCSS_SetShadowOffset(*(void **)(w + 8 + off), (int *)(&vectors.orient));
            MCSS_SetShadowRotateZ(*(void **)(w + 8 + off), angle);
        }
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b34 = 3;
        func_022006B4((Work_022006B4 *)w, key);
        MCSS_SetAnimCallback(*(void **)(w + 8 + off), i, (void *)func_02201718, 1);
    }
}

void func_021FF088(Work_vE254 *w, void *src, int key)
{
    int i;
    char buf[0x24];
    Vec_021FF088 v;

    for (i = 0; i < 14; i++) {
        if (w->e[i].h == 0)
            break;
    }
    if (key < 14 && i < 14) {
        w->e[i].flip = 1;
        w->e[i].k48 = key;
        func_022006A0(src, buf, key);
        func_022018A8((Unit_v1098 *)w, (Vec3_vF228 *)((Vec_021FE254 *)&v), key);
        w->e[i].h = MCSS_Add(w->obj, v.x, v.y, v.z, (const struct Sub150 *)buf);
        func_022006B4((Work_022006B4 *)w, key);
    }
}

void func_021FF0F8(Work_021FF0F8 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    MCSS_Del(w->obj, w->e[idx].h);
    w->e[idx].h = 0;
    if (w->e[idx].task != 0) {
        func_020307B0((void *)TCBL_IsDeletePending(w->e[idx].task));
        func_02030EAC(w->e[idx].task);
        w->e[idx].task = 0;
    }
}

void func_021FF134(char *p, int a, int b)
{
    ((struct Obj12218 *)p)->f538 = a;
    ((struct Obj12218 *)p)->f53C = b;
}

void func_021FF144(Work_021FF144 *w, int key, fx32 x, fx32 y, fx32 z)
{
    int idx = func_022019F4((char *)w, key);
    VecFx32 v;

    v.x = x;
    v.y = y;
    v.z = z;
    MCSS_SetPosition(w->e[idx].h, (u32 *)(&v));
}

void func_021FF16C(Work_021FF16C *w)
{
    int i;
    int idx;

    MCSS_SetOrthoMode(w->obj);
    w->active = 1;
    for (i = 0; i < 14; i++) {
        idx = func_022019F4((char *)w, i);
        if (idx != -1) {
            w->e[idx].flip = 1;
            func_022006B4((Work_022006B4 *)w, i);
        }
    }
}

void func_021FF1B0(Work_021FF1B0 *w)
{
    int i;
    int idx;

    MCSS_ResetOrthoMode(w->obj);
    w->active = 0;
    for (i = 0; i < 14; i++) {
        idx = func_022019F4((char *)w, i);
        if (idx != -1) {
            w->e[idx].flip = 0;
            func_022006B4((Work_022006B4 *)((Work_021FF16C *)w), i);
        }
    }
}

void func_021FF1F4(Work_vE254 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    w->e[idx].flip = 1;
    MCSS_SetOrthoBillboardFlag(w->e[idx].h);
    func_022006B4((Work_022006B4 *)((Work_021FF16C *)w), key);
}

void func_021FF228(Work_021FF228 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    w->e[idx].flip = 0;
    MCSS_ResetOrthoBillboardFlag(w->e[idx].h);
    func_022006B4((Work_022006B4 *)w, key);
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 *   MCSS_SetMepachiFlag, MCSS_ResetMepachiFlag, MCSS_FlipMepachiFlag.  All the integrator's; verified C
 *   (one --thumb, no --region, EXACT each; +0x140 is a register-like word):
 *     struct R { unsigned int : 8; unsigned int f : 1; };
 *     void MCSS_SetMepachiFlag(void *p) { *(unsigned int *)((char *)p + 0x140) |= 0x100u; }
 *     void MCSS_ResetMepachiFlag(void *p) { *(unsigned int *)((char *)p + 0x140) &= ~0x100u; }
 *     void MCSS_FlipMepachiFlag(void *p) { ((struct R *)((char *)p + 0x140))->f ^= 1; }
 *   Re-run this file once layout/matched/arm9 shards for all three exist.
 */
void func_021FF260(Work_021FF228 *w, int key, int mode)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    if (mode == 4) {
        MCSS_ResetMepachiFlag(w->e[idx].h);
        w->e[idx].f0 = 0;
    }
    if (w->e[idx].f0)
        return;
    if (mode == 2) {
        MCSS_FlipMepachiFlag(w->e[idx].h);
    } else if (mode == 1) {
        MCSS_SetMepachiFlag(w->e[idx].h);
    } else if (mode == 3) {
        MCSS_SetMepachiFlag(w->e[idx].h);
        w->e[idx].f0 = 1;
    } else {
        MCSS_ResetMepachiFlag(w->e[idx].h);
    }
}

int func_021FF2D8(Work_021FF228 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    return MCSS_GetAnmStopFlag(w->e[idx].h);
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 *   MCSS_SetAnmStopFlagAlways (0x02015E28) and MCSS_ResetAnmStopFlagAlways (0x02015E70).  Both are the integrator's;
 *   verified C (one --thumb, no --region, EXACT each):
 *     struct R { unsigned int : 9; unsigned int f : 2; };
 *     void MCSS_SetAnmStopFlagAlways(void *p) { ((struct R *)((char *)p + 0x140))->f |= 2; }
 *     void MCSS_ResetAnmStopFlagAlways(void *p) { ((struct R *)((char *)p + 0x140))->f &= ~2u; }
 *   Re-run this file once layout/matched/arm9 shards for both exist.
 */
void func_021FF304(Work_021FF228 *w, int key, int mode)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    if (mode == 1)
        MCSS_SetAnmStopFlag(w->e[idx].h);
    else if (mode == 2)
        MCSS_SetAnmStopFlagAlways(w->e[idx].h);
    else if (mode == 3)
        MCSS_ResetAnmStopFlagAlways(w->e[idx].h);
    else
        MCSS_ResetAnmStopFlag(w->e[idx].h);
}

int func_021FF348(Work_021FF348 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    return MCSS_GetVanishFlag(w->e[idx].h);
}

void func_021FF374(Work_vF228 *w, int key, int kind)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    switch (kind) {
    case 2:
        MCSS_FlipVanishFlag(w->e[idx].h);
        break;
    case 1:
        MCSS_SetVanishFlag(w->e[idx].h);
        break;
    case 0:
        MCSS_ResetVanishFlag(w->e[idx].h);
        break;
    case 3:
        if (MCSS_GetVanishFlag(w->e[idx].h))
            w->e[idx].f5 = 1;
        MCSS_SetVanishFlag(w->e[idx].h);
        break;
    case 4:
        if (w->e[idx].f5)
            w->e[idx].f5 = 0;
        else
            MCSS_ResetVanishFlag(w->e[idx].h);
        break;
    }
}

void func_021FF3F4(void *obj, void *out, int idx)
{
    func_022018A8((Unit_v1098 *)obj, (Vec3_vF228 *)((Vec_021FE254 *)out), idx);
}

/*
 * Unlabelled: no func_ label in the listing (leaf, saves no lr); reached
 * by bl from func_021FD1CC.
 */
void func_021FF3FC(const Vec3_vF228 *def, Vec3_vF228 *out, int idx, int kind)
{
    switch (idx) {
    case 0:
    case 1:
        def = &d_0220A050[idx];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (kind == 3)
            def = &d_0220A1A0[idx - 2];
        else if (kind == 2)
            def = &d_0220A158[idx - 2];
        else
            def = &d_0220A080[idx - 2];
        break;
    case 6:
    case 7:
        if (kind == 3)
            def = &d_0220A1A0[idx - 2];
        else
            def = &d_0220A158[idx - 2];
        break;
    }
    out->x = def->x;
    out->y = def->y;
    out->z = def->z;
}

int func_021FF468(void *u, int i, int mode)
{
    return func_02201934((Unit_v1098 *)u, i, mode);
}

/*
 * Byte-identical to the original; parked because the +0014 call to 0x02015FF0
 * (an unlabelled ARM9 leaf, no traced label) has no witness outside the
 * compared range.  The +0006 call to 0x022019F4 is an ov094 Thumb function.
 */
void func_021FF470(char *p, int key, u8 v)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return;
    e = p + i * 0x5c;
    if (((struct Obj12219 *)e)->f8 == 0)
        return;
    MCSS_SetShadowVanishFlag((char *)(((struct Obj12219 *)e)->f8), v);
}

/*
 * Byte-identical to the original; parked because the call to 0x020160C4
 * (an unlabelled ARM9 leaf, no traced label) has no witness outside the
 * compared range.  The call to 0x022019F4 is an ov094 Thumb function.
 */
void func_021FF498(char *p, int key, void *v)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return;
    e = p + i * 0x5c;
    if (((struct Obj12220 *)e)->f8 == 0)
        return;
    MCSS_SetAnimeSpeed((char *)(((struct Obj12220 *)e)->f8), (int)v);
}

void func_021FF4C0(char *w, int key, int kind, Vec_021F6560 *q, int a, int b, int c)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Vec_021F6560 start;
    if (idx == -1)
        return;
    e = w + 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    MCSS_GetPosition(*(void **)(e + off), (u32 *)&start);
    if (kind == 1) {
        if (key & 1)
            q->x = start.x - q->x;
        else
            q->x += start.x;
        q->y += start.y;
        q->z += start.z;
    }
    if (kind == 5) {
        func_022018A8((Unit_v1098 *)w, (Vec3_vF228 *)((Vec_021FE254 *)q), key);
        kind = 1;
    }
    if (kind == 6) {
        func_022018A8((Unit_v1098 *)w, (Vec3_vF228 *)((Vec_021FE254 *)q), key);
        kind = 0;
    }
    if (kind == 0) {
        MCSS_SetPosition(*(void **)(e + off), (u32 *)q);
        return;
    }
    (*(u8 *)(w + 0x542 + key))++;
    func_0220074C((Work_0220074C *)w, key, kind, (VecFx32_vFE48 *)&start, (VecFx32_vFE48 *)q, a, b, c, (void *)func_02200904, (void (*)(void *))func_02200990, 1, *(u8 *)(w + 0x542 + key));
    ((struct Obj06309 *)w)->f514 |= func_021F935C(key);
}

void func_021FF5B0(Work_021FF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c)
{
    int idx = func_022019F4((char *)w, i);
    VecFx32_vF5B0 cur;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_GetShadowScale(w->e[idx].h, (u32 *)(&cur));
    w->cnt[0][i]++;
    func_0220074C((Work_0220074C *)((Work_021FF5B0 *)w), i, kind, (VecFx32_vFE48 *)((Vec_021F6560 *)&cur), (VecFx32_vFE48 *)((Vec_021F6560 *)q), n, f48, f4c, (void *)func_022009C8, (void (*)(void *))((void ( *)(void *))func_02200A50), 0, w->cnt[0][i]);
    w->mask[0] |= func_021F935C(i);
}

void func_021FF630(Work_021FF630 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c)
{
    int idx = func_022019F4((char *)w, i);
    VecFx32_vF5B0 cur;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_GetScale(w->e[idx].h, (u32 *)(&cur));
    w->cnt[i]++;
    func_0220074C((Work_0220074C *)((Work_021FF5B0 *)w), i, kind, (VecFx32_vFE48 *)((Vec_021F6560 *)&cur), (VecFx32_vFE48 *)((Vec_021F6560 *)q), n, f48, f4c, (void *)func_02200A84, (void (*)(void *))((void ( *)(void *))func_02200B10), 0, w->cnt[i]);
    w->mask |= func_021F935C(i);
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * Byte-correct; MATCH blocked on one unlabelled ARM9 Thumb leaf (the integrator's; no
 * witness outside the range): MCSS_GetShadowScale (copies three words from +0x128).
 * Verified C (match.py one, no --region, --thumb, EXACT):
 *   typedef unsigned int u32;
 *   void MCSS_GetShadowScale(void *p, u32 *out)
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x128);
 *       out[1] = *(u32 *)((char *)p + 0x12C);
 *       out[2] = *(u32 *)((char *)p + 0x130);
 *   }
 * Twin of matched func_021FF630.
 */
void func_021FF6B0(Work_vF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c)
{
    int idx = func_022019F4((char *)w, i);
    VecFx32_vF5B0 cur;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_GetShadowScale(w->e[idx].h, (u32 *)(&cur));
    w->cnt[2][i]++;
    func_0220074C((Work_0220074C *)((Work_021FF5B0 *)w), i, kind, (VecFx32_vFE48 *)((Vec_021F6560 *)&cur), (VecFx32_vFE48 *)((Vec_021F6560 *)q), n, f48, f4c, (void *)func_02200B48, (void (*)(void *))((void ( *)(void *))func_02200BD4), 0, w->cnt[2][i]);
    w->mask[3] |= func_021F935C(i);
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * Byte-correct; MATCH blocked on one unlabelled ARM9 Thumb leaf (the integrator's; no
 * witness outside the range): MCSS_GetRotate (copies three words from +0xF8).
 * Verified C (match.py one, no --region, --thumb, EXACT):
 *   typedef unsigned int u32;
 *   void MCSS_GetRotate(void *p, u32 *out)
 *   {
 *       out[0] = *(u32 *)((char *)p + 0xF8);
 *       out[1] = *(u32 *)((char *)p + 0xFC);
 *       out[2] = *(u32 *)((char *)p + 0x100);
 *   }
 * Twin of matched func_021FF630.
 */
void func_021FF730(Work_vF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c)
{
    int idx = func_022019F4((char *)w, i);
    VecFx32_vF5B0 cur;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_GetRotate(w->e[idx].h, (u32 *)(&cur));
    w->cnt[3][i]++;
    func_0220074C((Work_0220074C *)((Work_021FF5B0 *)w), i, kind, (VecFx32_vFE48 *)((Vec_021F6560 *)&cur), (VecFx32_vFE48 *)((Vec_021F6560 *)q), n, f48, f4c, (void *)func_02200C0C, (void (*)(void *))((void ( *)(void *))func_02200C98), 1, w->cnt[3][i]);
    w->mask[1] |= func_021F935C(i);
}

void func_021FF7B0(Work_021FF7B0 *w, int a, int b)
{
    int keys[2];
    int idx[2];
    Vec3_vF7B0 v;
    int i;

    keys[0] = a;
    keys[1] = b;
    for (i = 0; i < 2; i++) {
        idx[i] = func_022019F4((char *)w, keys[i]);
        if (func_021FFD9C((char *)w, keys[i])) {
            func_022018A8((Unit_v1098 *)w, (Vec3_vF228 *)((Vec_021FE254 *)&v), keys[i ^ 1]);
            func_021FF4C0((char *)w, keys[i], 0, (Vec_021F6560 *)&v, 0, 0, 0);
            BTLV_GAUGE_HideSlot((char *)func_021F86B4(), keys[i]);
            if (w->e[idx[i]].f6) {
                w->e[idx[i]].f6 = 0;
                func_021FF374((Work_vF228 *)w, keys[i], 0);
            }
        }
    }
    for (i = 0; i < 2; i++) {
        if (idx[i] != -1)
            w->e[idx[i]].key = keys[i ^ 1];
    }
}

void func_021FF870(Work_021FF870 *w, int key, int kind, int a, int b)
{
    Obj_021FF870 *o;

    switch (kind) {
    case 3:
        func_021FF260((Work_021FF228 *)w, key, 1);
        return;
    case 4:
        func_021FF260((Work_021FF228 *)w, key, 0);
        return;
    case 2:
        o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x54, 0, d_0220AE7C, 0x5e5);
        o->w = w;
        o->i = key;
        o->kind = kind;
        o->f44 = 0;
        o->f48 = a;
        o->f4c = b * 2;
        w->cnt[0][key]++;
        o->f50 = w->cnt[0][key];
        func_021F896C((void *)func_02030DA8((void *)w->owner, func_02200CD0, o, 0), func_02200D30, 2);
        w->mask[2] |= func_021F935C(key);
        return;
    }
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 * Verified scratch C, EXACT (blocker_02015FAC_r1.log):
 * typedef unsigned char u8;
 * typedef struct { char pad[0x140]; unsigned int value : 8; } Data;
 * u8 MCSS_GetAlpha(Data *p) { return p->value; }
 */
void func_021FF924(char *w, int key, int kind, int value, int a, int b, int c)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Vec_021F6560 start, end;
    if (idx == -1)
        return;
    e = w + 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    start.x = FX(MCSS_GetAlpha(*(void **)(e + off)));
    start.y = 0;
    start.z = 0;
    end.x = FX(value);
    end.y = 0;
    end.z = 0;
    (*(u8 *)(w + 0x596 + key))++;
    func_0220074C((Work_0220074C *)w, key, kind, (VecFx32_vFE48 *)&start, (VecFx32_vFE48 *)&end, a, b, c, (void *)func_02200D68, (void (*)(void *))func_02200DE4, 0, *(u8 *)(w + 0x596 + key));
    ((struct Obj06309 *)w)->f52C |= func_021F935C(key);
}

/*
 * lever: the 4/5 kind test is an unsigned range check; individual equality tests cost two bytes.
 */
void func_021FFA18(Work_021FFA18 *w, Obj_021FFA18 *s)
{
    Obj_021FFA18 *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x3c, 0, d_0220AE7C, 0x627);
    o->w = w;
    o->key = s->key;
    o->kind = s->kind;
    o->direction = s->direction;
    o->f10 = s->f10;
    o->f14 = s->f14;
    o->f18 = s->f18;
    o->f1c = s->f1c;
    o->f20 = s->f20;
    o->f24 = s->f24;
    o->f30 = 0;
    o->f34 = 0;
    if (o->key & 1) {
        if ((o->kind != 0 && o->kind != 1 && (unsigned)(o->kind - 4) > 1)
            || (s->direction != 2 && s->direction != 3))
            o->direction ^= 1;
    }
    o->f28 = (o->kind & 1) ? 0x10000 : 0;
    o->f2c = 0x10000 / s->f18;
    w->cnt[o->key]++;
    o->f38 = w->cnt[o->key];
    func_021F896C((void *)func_02030DA8(w->owner, func_02200E1C, o, 0), func_02201098, 2);
    w->mask |= func_021F935C(o->key);
}

void func_021FFB04(Work_vF7B0 *w, Obj_vF7B0 *s)
{
    Obj_vF7B0 *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x2c, 0, d_0220AE7C, 0x660);
    int idx = func_022019F4((char *)w, s->key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    *o = *s;
    o->w = w;
    MCSS_GetPosition(w->e[idx].h, (u32 *)o->v);
    w->cnt[0][o->key]++;
    o->f28 = w->cnt[0][o->key];
    func_021F896C((void *)func_02030DA8(w->owner, func_022010D0, o, 0), func_022011FC, 2);
    w->mask[0] |= func_021F935C(o->key);
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 * Verified scratch C, EXACT (blocker_02016068_r1.log):
 * typedef unsigned char u8;
 * typedef struct { char pad[0x140]; unsigned int padbits : 24; unsigned int value : 4; } Data;
 * u8 MCSS_GetMosaic(Data *p) { return p->value; }
 */
void func_021FFBBC(char *w, int key, int kind, int value, int a, int b, int c)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Vec_021F6560 start, end;
    if (idx == -1)
        return;
    e = w + 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    start.x = FX(MCSS_GetMosaic(*(void **)(e + off)));
    start.y = 0;
    start.z = 0;
    end.x = FX(value);
    end.y = 0;
    end.z = 0;
    (*(u8 *)(w + 0x5a4 + key))++;
    func_0220074C((Work_0220074C *)w, key, kind, (VecFx32_vFE48 *)&start, (VecFx32_vFE48 *)&end, a, b, c, (void *)func_02201234, (void (*)(void *))func_022012CC, 0, *(u8 *)(w + 0x5a4 + key));
    ((struct Obj06309 *)w)->f530 |= func_021F935C(key);
}

int func_021FFCB0(Work_021FFCB0 *w, int key)
{
    int r = 0;

    if (func_021FFD9C((char *)w, key))
        r = MCSS_CheckPaletteFade(w->e[func_022019F4((char *)w, key)].h);
    if (func_021F935C(key) & w->m514
        || func_021F935C(key) & w->m518
        || func_021F935C(key) & w->m524
        || func_021F935C(key) & w->m520
        || func_021F935C(key) & w->m51c
        || func_021F935C(key) & w->m528
        || func_021F935C(key) & w->m52c
        || func_021F935C(key) & w->m530
        || w->f510
        || r)
        return 1;
    return 0;
}

int func_021FFD6C(Work_021FFD6C *w)
{
    Key_021FD04C i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)w, i) && func_021FFCB0((Work_021FFCB0 *)w, i))
            return 1;
    }
    return 0;
}

int func_021FFD9C(char *p, int key)
{
    if (func_022019F4(p, key) != -1)
        return 1;
    return 0;
}

void func_021FFDB4(Work_vFCB0 *w, int key, u8 cur, u8 target, u8 step, u32 e)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_SetPaletteFade(w->e[idx].h, cur, target, (s8)step, e);
    w->e[idx].flags |= 0x100;
}

void func_021FFDF8(Work_vFCB0 *w, int key, int a, int b)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_CreatePaletteTransTask(w->obj, w->e[idx].h, a, b);
}

void func_021FFE24(Work_vFE24 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_CreatePaletteCopyTask(w->obj, w->e[idx].h);
}

#define FX_INT_TO_FX32(x) ((fx32)(((x) > 0) ? ((float)((x) << 12) + .5f)                                             : ((float)((x) << 12) - .5f)))

#define MUL(a, b) ((int)(((s64)(a) * (b) + 0x800) >> 12))

void func_021FFE48(Work_021FFE48 *w, int key, void *p)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    w->e[idx].a = POKE_TOOL_GetPartyValue(p, 5, 0);
    w->e[idx].b = POKE_TOOL_GetPartyValue(p, 0x6f, 0);
    w->e[idx].d = func_02019C90(w->e[idx].a, w->e[idx].b, 0x26);
    w->e[idx].c = POKE_TOOL_GetPartyValue(p, 0, 0);
    w->e[idx].f = POKE_TOOL_GetPartyValue(p, 0x98, 0);
    if (func_02017EAC(p) == 1)
        w->e[idx].flags0 |= 2;
    w->e[idx].e = func_0202D034(POKE_TOOL_GetPartyValue(p, 0xa0, 0), POKE_TOOL_GetPartyValue(p, 0xa1, 0));
    w->e[idx].flags |= 0x200;
}

int func_021FFF0C(char *p, int key)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12223 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12223 *)e)->f40;
}

int func_021FFF38(char *p, int key)
{
    int i;
    char *e;

    if (key == 0xff)
        return 0;
    i = func_022019F4(p, key);
    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12224 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12224 *)e)->f48;
}

int func_021FFF68(Work_021FFF68 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    if (func_02019C90(w->e[idx].a, w->e[idx].b, 0x10))
        return 1;
    return 0;
}

int func_021FFFAC(Work_021FFFAC *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    return MCSS_GetStopCellFlags(w->e[idx].h);
}

void func_021FFFD8(char *w, int key, int flag, int clear)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Rec_021FFFD8 r;
    int odd;

    if (idx == -1)
        return;
    e = w;
    e += 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    if (flag == 0) {
        MCSS_TOOL_SetSpindaSpotHook((int)(((struct Obj01047 *)w)->f4), *(u32 *)(w + off + 0x3c));
        MCSS_ReloadResource(((struct Obj01047 *)w)->f4, *(void **)(w + 8 + off), (const struct Sub02014CF8Rec *)(w + 0xc + off));
        MCSS_SetAnimCallback(*(void **)(w + 8 + off), idx, (void *)func_02201718, 1);
        if (clear)
            *(u32 *)(w + 0x48 + off) &= ~1u;
        *(u32 *)(w + 0x48 + off) &= ~4u;
    } else {
        r.v[0] = POKEGRA_GetArcID();
        odd = key & 1;
        r.v[1] = odd ? 0x37a0 : 0x37a6;
        r.v[2] = 0x37ac;
        r.v[3] = odd ? 0x37a1 : 0x37a7;
        r.v[4] = odd ? 0x37a2 : 0x37a8;
        r.v[5] = odd ? 0x37a3 : 0x37a9;
        r.v[6] = odd ? 0x37a4 : 0x37aa;
        r.v[7] = odd ? 0x37a5 : 0x37ab;
        r.v[8] = 0;
        MCSS_ReloadResource(((struct Obj01047 *)w)->f4, *(void **)(e + off), (const struct Sub02014CF8Rec *)(&r));
        func_021FFE24((Work_vFE24 *)w, key);
        if (clear)
            *(u32 *)(w + 0x48 + off) |= 1;
        *(u32 *)(w + 0x48 + off) |= 4;
    }
}

void func_02200108(Work_02200108 *w, int key, int v)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_TOOL_SetSpindaSpotHook((int)w->obj, w->e[idx].k34);
    MCSS_SetMosaic(w->obj, w->e[idx].h, v);
}

void func_02200140(Work_02200140 *w, int key1, int key2)
{
    int i1 = func_022019F4((char *)w, key1);
    int i2 = func_022019F4((char *)w, key2);

    w->e[i2].f04 = w->e[i1].f04;
    w->e[i2].f0c = w->e[i1].f0c;
    if (key1 & 1) {
        w->e[i2].f08 = w->e[i1].f08 + 9;
        w->e[i2].f10 = w->e[i1].f10 + 9;
        w->e[i2].f14 = w->e[i1].f14 + 9;
        w->e[i2].f18 = w->e[i1].f18 + 9;
        w->e[i2].f1c = w->e[i1].f1c + 9;
        w->e[i2].f20 = w->e[i1].f20 + 9;
    } else {
        w->e[i2].f08 = w->e[i1].f08 - 9;
        w->e[i2].f10 = w->e[i1].f10 - 9;
        w->e[i2].f14 = w->e[i1].f14 - 9;
        w->e[i2].f18 = w->e[i1].f18 - 9;
        w->e[i2].f1c = w->e[i1].f1c - 9;
        w->e[i2].f20 = w->e[i1].f20 - 9;
    }
    w->e[i2].q = w->e[i1].q;
    MCSS_ReloadResource(w->obj, w->e[i2].h, (const struct Sub02014CF8Rec *)(&w->e[i2].f04));
}

void func_022001DC(Work_022001DC *w, int key, Rec_022001DC *r)
{
    int idx = func_022019F4((char *)w, key);

    w->e[idx].rec = *r;
    MCSS_TOOL_SetSpindaSpotHook((int)w->obj, w->e[idx].k34);
    MCSS_ReloadResource(w->obj, w->e[idx].h, (const struct Sub02014CF8Rec *)(&w->e[idx].rec));
}

int func_02200218(Work_02200218 *w, int key, int pitch, int pan, int a4, int a5, int a6)
{
    int idx = func_022019F4((char *)w, key);
    u32 id;
    u32 buf;
    u32 *out;
    int flag;
    void *p;
    u32 r;

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    switch (key) {
    case 0:
    case 1:
        id = d_02209FC0[key];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (w->flags.b1)
            id = d_02209FF0[key - 2];
        else if (w->flags.b0)
            id = d_0220A068[key - 2];
        else
            id = d_02209FE0[key - 2];
        break;
    case 6:
    case 7:
        if (w->flags.b1)
            id = d_02209FF0[key - 2];
        else
            id = d_0220A068[key - 2];
        break;
    }
    p = (void *)func_021F8754();
    out = &buf;
    flag = 0;
    if (p != 0) {
        if (BTL_MAIN_GetVoiceOfSlot(p, key, out) == 0)
            out = 0;
    } else {
        out = 0;
    }
    if (a4 != 0 || a5 != 0)
        flag = 1;
    if (pitch == (int)0x80000000) {
        if (w->e[idx].k3a == 1)
            pitch = -0xa00;
        else
            pitch = 0;
    }
    r = PM_VOICE_Play(w->e[idx].k2c, w->e[idx].k30, (u8)id, flag, a4, a5, a6, (u32)out);
    PM_VOICE_AddVolume(r, (signed char)pan);
    PM_VOICE_AddFrequency(r, pitch);
    return r;
}

void func_02200344(Work_02200344 *w, int a, int b, int flag)
{
    Obj_vFE48 *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x24, 0, d_0220AE7C, 0x8f2);

    o->w = w;
    o->a = 0;
    o->flag = flag;
    o->f8 = a;
    o->fc = b;
    w->flags |= 4;
    func_021F896C(func_02030DA8(w->owner, func_02201408, o, 0), func_02201700, 2);
}

int func_022003C4(char *p, int key)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12226 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12226 *)e)->f44;
}

void func_022003EC(Work_022003EC *w, void *p, int *a, int flags)
{
    int v = 1;

    if (flags & 1)
        v = 0;
    MCSS_TOOL_MakeAddWorkFromPP(p, (struct Stats *)a, v);
    MCSS_TOOL_SetSpindaSpotHook((int)w->obj, POKE_TOOL_GetPartyValue(p, 0, 0));
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * MATCH: bytes identical (one prints MATCH*); blocked on 0x020160CC, an
 * unfiled unlabelled ARM9 Thumb leaf (the integrator's) with no witness outside this
 * range. Verified C for it (EXACT, `one --thumb`, no --region, cc 1.1p1,
 * -O4,p; packet pkt_020160CC, 64 B extent):
 *
 *   typedef unsigned short u16;
 *   typedef struct { char pad[0x28]; u16 *p28; } S;
 *   u16 MCSS_GetAnimSeqNumEx(S *s) { return *s->p28; }
 *
 * The extern here takes `int` as return type (u16 not needed at the caller).
 */
int func_0220041C(Work_0220041C *w, int key, int n)
{
    int r = 0;
    int i = func_022019F4((char *)w, key);

    if (i == -1)
        return 0;
    if (w->e[i].h == 0)
        return 0;
    if (n < MCSS_GetAnimSeqNumEx(w->e[i].h)) {
        MCSS_SetAnimeIndex(w->e[i].h, n);
        r = 1;
        w->e[i].f44 = r;
    }
    return r;
}

void func_02200468(Work_02200468 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_SetAnimCallback(w->e[idx].h, idx, (void *)func_02201894, 1);
}

int func_02200494(char *p, int key)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12228 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12228 *)e)->f4C;
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * MATCH: bytes identical; blocked on 0x02015C60, an unfiled unlabelled ARM9
 * Thumb leaf (the integrator's) with no witness outside this range. Verified C for it
 * (EXACT, `one --thumb`, no --region, cc 1.1p1, -O4,p; packet pkt_02015C60,
 * 64 B extent, out-direction twin of MCSS_SetOfsPosition):
 *
 *   typedef unsigned int u32;
 *   void MCSS_GetOfsPosition(void *p, u32 *out)
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x11C);
 *       out[1] = *(u32 *)((char *)p + 0x120);
 *       out[2] = *(u32 *)((char *)p + 0x124);
 *   }
 */
void func_022004BC(Work_022004BC *w, int key)
{
    Vec_vFE48 want;
    Vec_vFE48 cur;
    Vec_vFE48 off;
    int i = func_022019F4((char *)w, key);

    if (i == -1)
        return;
    if (w->e[i].h == 0)
        return;
    func_022018A8((Unit_v1098 *)w, (Vec3_vF228 *)&want, key);
    MCSS_GetPosition(w->e[i].h, (u32 *)(&cur));
    MCSS_GetOfsPosition(w->e[i].h, (u32 *)(&off));
    w->e[i].flags &= ~0x40;
    if (want.x == cur.x && want.y == cur.y && want.z == cur.z
        && off.x == 0 && off.y == 0 && off.z == 0)
        return;
    w->e[i].flags |= 0x40;
    off.x = 0;
    off.y = 0;
    off.z = 0;
    MCSS_SetPosition(w->e[i].h, (u32 *)(&want));
    MCSS_SetOfsPosition(w->e[i].h, (u32 *)(&off));
    MCSS_SetVanishFlag(w->e[i].h);
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 *   0220055C..022005C2). Every concrete byte matches (MATCH*, the extent's 2 extra bytes
 *   are the pad); only the final bl relocation stays wildcarded.
 *   Verified C (match.py one, --thumb, no --region, dsi/1.1p1 -O4,p), EXACT, 28 bytes:
 *
 *     typedef struct { char pad[0x140]; unsigned int lo : 30; unsigned int f : 1;
 *                      unsigned int hi : 1; } S;
 *     void MCSS_SetWorkFlag(S *s, int f)        // 0x02016394
 *     {
 *         s->f = f;
 *     }
 *
 * lever: each arm of the result switch writes `f = 1` out in its own inner switch
 *   (`switch (key) { case 3: case 4: f = 1; break; }`), so the case-1 copy is
 *   cross-jumped into a `b` after threading and the key == 3 beq keeps pointing at it
 *   (a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.md); a
 *   shared `set:` label lets the beq be threaded straight to `f = 1` (2 bytes out), and
 *   `key == 3 || key == 4` folds to a range test.
 */
void func_0220055C(Work_0220055C *w, int key, int mode)
{
    int f = 0;
    int i;

    i = func_022019F4((char *)w, key);
    if (i == -1)
        return;
    if (w->e[i].h == 0)
        return;
    if (mode == 1) {
        switch (func_021F8710()) {
        case 0:
        case 3:
            break;
        case 1:
            switch (key) {
            case 3:
            case 4:
                f = 1;
                break;
            }
            break;
        case 2:
            switch (key) {
            case 2:
            case 5:
            case 6:
                f = 1;
                break;
            }
            break;
        }
    }
    MCSS_SetWorkFlag(w->e[i].h, f);
}

int func_022005C4(Work_022005C4 *w, int key)
{
    int i = func_022019F4((char *)w, key);
    int r;

    if (i == -1)
        return 0;
    if (w->e[i].h == 0)
        return 0;
    if (w->e[i].f9)
        r = 1;
    else
        r = 0;
    w->e[i].f9 = 0;
    return r;
}

void func_02200608(Work_02200608 *w)
{
    Slot_021FFE48 i;
    int j;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)w, i)) {
            j = func_022019F4((char *)w, i);
            w->e[j].f10 = func_021FF348((Work_021FF348 *)w, i);
        }
    }
}

void func_02200654(Work_02200654 *w)
{
    Slot_021FFE48 i;
    int j;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)w, i)) {
            j = func_022019F4((char *)w, i);
            func_021FF374((Work_vF228 *)w, i, w->e[j].f10);
            w->e[j].f5 = 0;
        }
    }
}

/*
 * Tail-call stub: forwards (p, out) and passes !(flags & 1) as the third
 * argument of MCSS_TOOL_MakeAddWorkFromTrainer.
 */
void func_022006A0(void *p, void *out, int flags)
{
    MCSS_TOOL_MakeAddWorkFromTrainer(p, out, (void *)((flags & 1) == 0));
}

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * MATCH: bytes identical; blocked on 0x02015D30, an unlabelled ARM9 Thumb
 * leaf (stores a VecFx32_vFE48 at +0x104, beside the matched MCSS_SetScale) with no
 * witness. Filing that ARM9 leaf closes this.
 */
void func_022006B4(Work_022006B4 *w, int i)
{
    int idx = func_022019F4((char *)w, i);
    fx32 v;
    VecFx32_vFE48 s;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    v = func_02201934((Unit_v1098 *)w, i, w->e[idx].flip);
    if (i & 1)
        v = FX_Mul(v, w->scaleOdd);
    else
        v = FX_Mul(v, w->scaleEven);
    s.x = v;
    s.y = v;
    s.z = 0x1000;
    MCSS_SetScale(w->e[idx].h, (u32 *)(&s));
    v = func_02201934((Unit_v1098 *)w, i, 0);
    s.x = v;
    s.y = v;
    s.z = 0x1000;
    MCSS_SetOfsScale(w->e[idx].h, (u32 *)(&s));
}

void func_0220074C(Work_0220074C *w, int i, int kind, VecFx32_vFE48 *p, VecFx32_vFE48 *q, int n,
                   int f48, int f4c, void *fn, void (*cb)(void *), int flip, u8 f50)
{
    Mover_0220074C *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x54, 0, d_0220AE7C, 0xa4e);

    o->w = w;
    o->i = i;
    o->kind = kind;
    o->frames = n;
    o->left = n;
    o->count = 0;
    o->f48 = f48;
    o->f4c = f4c * 2;
    o->start.x = p->x;
    o->start.y = p->y;
    o->start.z = p->z;
    o->end.x = q->x;
    o->end.y = q->y;
    o->end.z = q->z;
    o->cur.x = p->x;
    o->cur.y = p->y;
    o->cur.z = p->z;
    o->f50 = f50;
    switch (kind) {
    case 0:
        break;
    case 1:
    case 4:
        func_021F918C((const VecFx32_021F8F30 *)(&o->start), (const VecFx32_021F8F30 *)q, (VecFx32_021F8F30 *)(&o->step), FX_INT_TO_FX32(n));
        break;
    case 3:
        o->f4c *= 2;
    case 2:
        o->step.x = FX_Div_Alt(q->x, FX_INT_TO_FX32(n));
        o->step.y = FX_Div_Alt(q->y, FX_INT_TO_FX32(n));
        o->step.z = FX_Div_Alt(q->z, FX_INT_TO_FX32(n));
        if ((i & 1) && flip) {
            o->step.x *= -1;
            o->step.z *= -1;
        }
        break;
    }
    func_021F896C(func_02030DA8(w->owner, fn, o, 0), cb, 2);
}

/*
 * Task callback, twin of func_02200A84 on the +0xE0 vector.
 */
void func_02200904(void *h, Ctx_021FFE48 *c)
{
    Work_02200904 *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32_vFE48 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    MCSS_GetPosition(w->e[i].h, (u32 *)(&v));
    r = func_021F9260((Mover_v8204 *)(&c->mv), (VecFx32_021F8F30 *)&v);
    MCSS_SetPosition(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}

void func_02200990(void *h)
{
    Ctx_02200990 *c = (Ctx_02200990 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}

void func_022009C8(void *h, Ctx_vFE48 *c)
{
    Work_vFE48 *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32_vFE48 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    MCSS_GetShadowScale(w->e[i].h, (u32 *)(&v));
    r = func_021F9260((Mover_v8204 *)((Mover_02200904 *)(&c->mv)), (VecFx32_021F8F30 *)&v);
    MCSS_SetShadowScale(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}

void func_02200A50(void *h)
{
    Ctx_02200A50 *c = (Ctx_02200A50 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}

/*
 * Task callback passed by func_021FF630.
 */
void func_02200A84(void *h, Ctx_02200A84 *c)
{
    Work_02200A84 *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32_vFE48 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    MCSS_GetScale(w->e[i].h, (u32 *)(&v));
    r = func_021F9260((Mover_v8204 *)((Mover_02200904 *)(&c->mv)), (VecFx32_021F8F30 *)&v);
    MCSS_SetScale(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}

/*
 * Task destructor passed by func_021FF630.
 */
void func_02200B10(void *h)
{
    Ctx_02200B10 *c = (Ctx_02200B10 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * MATCH: bytes identical; blocked on two unfiled ARM9 Thumb leaves (the integrator's),
 * no witness outside this range. Verified C, each EXACT with `one --thumb`
 * and no --region (cc 1.1p1, -O4,p), packets pkt_02015D4C / pkt_02015D64:
 *
 *   typedef unsigned int u32;
 *   void MCSS_GetDrawScale(void *p, u32 *out)   // 0x02015D4C, 64 B extent
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x110);
 *       out[1] = *(u32 *)((char *)p + 0x114);
 *       out[2] = *(u32 *)((char *)p + 0x118);
 *   }
 *   void MCSS_SetDrawScale(void *p, u32 *src)  // 0x02015D64, inverse
 *   {
 *       *(u32 *)((char *)p + 0x110) = src[0];
 *       *(u32 *)((char *)p + 0x114) = src[1];
 *       *(u32 *)((char *)p + 0x118) = src[2];
 *   }
 *
 * Task callback, twin of func_02200A84.
 */
void func_02200B48(void *h, Ctx_02200B48 *c)
{
    Work_02200B48 *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32_vFE48 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    MCSS_GetDrawScale(w->e[i].h, (u32 *)(&v));
    r = func_021F9260((Mover_v8204 *)((Mover_02200904 *)(&c->mv)), (VecFx32_021F8F30 *)&v);
    MCSS_SetDrawScale(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}

void func_02200BD4(void *h)
{
    Ctx_02200BD4 *c = (Ctx_02200BD4 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}

void func_02200C0C(void *h, Ctx_02200C0C *c)
{
    Work_02200C0C *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32_vFE48 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    MCSS_GetRotate(w->e[i].h, (u32 *)(&v));
    r = func_021F9260((Mover_v8204 *)((Mover_02200904 *)(&c->mv)), (VecFx32_021F8F30 *)&v);
    MCSS_SetRotate(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}

void func_02200C98(void *h)
{
    Ctx_02200C98 *c = (Ctx_02200C98 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}

/*
 * Task callback.
 */
void func_02200CD0(void *h, void *arg)
{
    Ctx_02200CD0 *c = arg;

    Work_02200CD0 *w = c->w;

    if (func_021FFD9C((char *)w, c->key) == 0 || c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    if (c->wait == 0) {
        c->wait = c->reload;
        func_021FF260((Work_021FF228 *)c->w, c->key, 2);
        if (--c->count == 0) {
            func_021FF260((Work_021FF228 *)c->w, c->key, 0);
            func_021F89BC(h);
        }
    } else {
        c->wait--;
    }
}

void func_02200D30(void *h)
{
    Ctx_v0D30 *c = (Ctx_v0D30 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}

void func_02200D68(void *o, char *q)
{
    char *p = *(char * *)&((struct Obj06316 *)q)->f0;
    int i = func_022019F4(p, ((struct Obj06316 *)q)->f4);
    char *e;
    int off;
    int r;

    if (i == -1) {
        func_021F89BC(o);
        return;
    }
    e = p + 8;
    off = i * 0x5C;
    if (*(int *)(e + off) == 0) {
        func_021F89BC(o);
        return;
    }
    if (((struct Obj06316 *)q)->f50 != *(u8 *)(p + ((struct Obj06316 *)q)->f4 + 0x596)) {
        func_021F89BC(o);
        return;
    }
    r = func_021F9260((Mover_v8204 *)((Mover_02200904 *)(q + 0x14)), (VecFx32_021F8F30 *)((VecFx32_vFE48 *)((int *)(q + 8))));
    MCSS_SetAlpha(*(char **)(e + off), (u8)(((struct Obj06316 *)q)->f8 >> 12));
    if (r == 1)
        func_021F89BC(o);
}

void func_02200DE4(void *h)
{
    Ctx_v0DE4 *c = (Ctx_v0DE4 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}

void func_02200E1C(void *task, void *arg)
{
    char *q = arg;

    char *p = *(char * *)&((struct Obj00264 *)q)->f0;
    Vec_021FFE48 v = {0, 0, 0};
    int i = func_022019F4(p, ((struct Obj00264 *)q)->f4);
    char *e;
    int off;
    int x, y;
    int j;
    if (i == -1) {
        func_021F89BC(task);
        return;
    }
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) {
        func_021F89BC(task);
        return;
    }
    if (((struct Obj00264 *)q)->f38 != *(u8 *)(p + ((struct Obj00264 *)q)->f4 + 0x542)) {
        func_021F89BC(task);
        return;
    }
    if (((struct Obj00264 *)q)->f34 == 0) {
        if (((struct Obj00264 *)q)->f30 == ((struct Obj00264 *)q)->f1C) {
        ((struct Obj00264 *)q)->f30 = 0;
        if (((struct Obj00264 *)q)->f8 & 1)
            ((struct Obj00264 *)q)->f28 -= ((struct Obj00264 *)q)->f2C;
        else
            ((struct Obj00264 *)q)->f28 += ((struct Obj00264 *)q)->f2C;
        if (((struct Obj00264 *)q)->f28 & 0xffff0000) {
            ((struct Obj00264 *)q)->f28 = (u16)((struct Obj00264 *)q)->f28;
            ((struct Obj00264 *)q)->f20 -= 1;
            ((struct Obj00264 *)q)->f34 = ((struct Obj00264 *)q)->f24;
        }
        if (((struct Obj00264 *)q)->f20 != 0) {
            switch (((struct Obj00264 *)q)->fC) {
            case 0:
                j = ((u16)(((struct Obj00264 *)q)->f28 + 0x4000) >> 4) * 2;
                x = FX_SinCosTable_[j];
                x = -MUL(x, ((struct Obj00264 *)q)->f10);
                y = FX_SinCosTable_[j + 1];
                y = -MUL(y, ((struct Obj00264 *)q)->f14);
                x += ((struct Obj00264 *)q)->f10;
                break;
            case 1:
                j = ((u16)(((struct Obj00264 *)q)->f28 + 0x4000) >> 4) * 2;
                x = FX_SinCosTable_[j];
                x = MUL(x, ((struct Obj00264 *)q)->f10) - ((struct Obj00264 *)q)->f10;
                y = FX_SinCosTable_[j + 1];
                y = MUL(y, ((struct Obj00264 *)q)->f14);
                break;
            case 2:
                j = (((struct Obj00264 *)q)->f28 >> 4) * 2;
                x = FX_SinCosTable_[j];
                x = -MUL(x, ((struct Obj00264 *)q)->f10);
                y = FX_SinCosTable_[j + 1];
                y = -MUL(y, ((struct Obj00264 *)q)->f14);
                y += ((struct Obj00264 *)q)->f14;
                break;
            case 3:
                j = (((struct Obj00264 *)q)->f28 >> 4) * 2;
                x = FX_SinCosTable_[j];
                x = MUL(x, ((struct Obj00264 *)q)->f10);
                y = FX_SinCosTable_[j + 1];
                y = MUL(y, ((struct Obj00264 *)q)->f14) - ((struct Obj00264 *)q)->f14;
                break;
            }
            switch ((((struct Obj00264 *)q)->f8 & 7) >> 1) {
            default:
            case 0:
                v.z = x;
                v.y = y;
                break;
            case 1:
                v.x = x;
                v.z = y;
                break;
            case 2:
                v.x = x;
                v.y = y;
                break;
            }
        }
        MCSS_SetOfsPosition(*(void **)(e + off), (u32 *)&v);
        } else {
            ((struct Obj00264 *)q)->f30 += 1;
        }
    } else {
        ((struct Obj00264 *)q)->f34 -= 1;
    }
    if (((struct Obj00264 *)q)->f20 == 0)
        func_021F89BC(task);
}

#undef MUL

#undef MUL

#undef MUL

#define MUL(a, b) ((int)(((long long)(a) * (b) + 0x800) >> 12))

/*
 * 2026-10-02 EXACT: the call argument is spelled as a raw offset load
 * (*(int *)((char *)c + 4)) while the tag index uses c->key, as in sibling
 * func_022011FC. With one spelling CSE hoists key ahead of the index and it
 * loads first (the +0x50 twins' order); with two spellings key is
 * copy-propagated and c->w loads first, as the image does.
 */
void func_02201098(void *h)
{
    Ctx_v1098 *c = (Ctx_v1098 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(((struct Obj06318 *)c)->f4) ^ 0xFFFFFFFF;
}

/*
 * lever: Separate x/y/z clears preserve the original store order.
 */
void func_022010D0(void *task, void *arg)
{
    char *q = arg;

    char *p = *(char * *)&((struct Obj02439 *)q)->f0;
    Vec_02201098 v = {0, 0, 0};
    int i = func_022019F4(p, ((struct Obj02439 *)q)->f4);
    char *e;
    int off;
    int n, f;
    if (i == -1) {
        func_021F89BC(task);
        return;
    }
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) {
        func_021F89BC(task);
        return;
    }
    if (((struct Obj02439 *)q)->f28 != *(u8 *)(p + ((struct Obj02439 *)q)->f4 + 0x542)) {
        func_021F89BC(task);
        return;
    }
    ((struct Obj02439 *)q)->f18 += ((struct Obj02439 *)q)->f1C;
    n = FX_SinCosTable_[((((struct Obj02439 *)q)->f18 & 0x0ffff000) >> 16) * 2];
    f = FIX((float)n / 4096.0f);
    f = (int)(((s64)f * ((struct Obj02439 *)q)->f20 + 0x800) >> 12);
    if (((struct Obj02439 *)q)->f14 != 0) v.y = f;
    else v.x = f;
    MCSS_SetOfsPosition(*(void **)(e + off), (u32 *)&v);
    ((struct Obj02439 *)q)->f24 -= 1;
    if (((struct Obj02439 *)q)->f24 == 0) {
        v.x = 0;
        v.y = 0;
        v.z = 0;
        MCSS_SetOfsPosition(*(void **)(e + off), (u32 *)&v);
        func_021F89BC(task);
    }
}

/*
 * 2026-10-02 EXACT: the call argument is spelled as a raw offset load
 * (*(int *)((char *)c + 4)) while the tag index uses c->key. With the same
 * field name on both uses, CSE makes key a temp ahead of the index
 * expression and it loads first (the twins' order); with distinct
 * spellings key is copy-propagated instead and c->w loads first.
 */
void func_022011FC(void *h)
{
    Ctx_022011FC *c = (Ctx_022011FC *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(((struct Obj06319 *)c)->f4) ^ 0xFFFFFFFF;
}

void func_02201234(void *o, char *q)
{
    char *p = *(char * *)&((struct Obj05243 *)q)->f0;
    int i = func_022019F4(p, ((struct Obj05243 *)q)->f4);
    char *e;
    int off;
    int r;

    if (i == -1) {
        func_021F89BC(o);
        return;
    }
    e = p + 8;
    off = i * 0x5C;
    if (*(int *)(e + off) == 0) {
        func_021F89BC(o);
        return;
    }
    if (((struct Obj05243 *)q)->f50 != *(u8 *)(p + ((struct Obj05243 *)q)->f4 + 0x5A4)) {
        func_021F89BC(o);
        return;
    }
    r = func_021F9260((Mover_v8204 *)((Mover_02200904 *)(q + 0x14)), (VecFx32_021F8F30 *)((VecFx32_vFE48 *)((int *)(q + 8))));
    func_02200108((Work_02200108 *)p, ((struct Obj05243 *)q)->f4, ((struct Obj05243 *)q)->f8 >> 12);
    if (r == 1) {
        MCSS_SetAnimCallback(*(void **)(e + off), i, (void *)func_02201718, 1);
        func_021F89BC(o);
    }
}

void func_022012CC(void *h)
{
    Ctx_022012CC *c = (Ctx_022012CC *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}

/*
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 sole-ref/code 02015F40 belongs to the integrator.
 * Verified C: one, Thumb dsi/1.1p1 -O4,p EXACT 16 bytes;
 * proof: scratchpad/overlay-goal-20260930-w29/B6/f40-proof.log
 * symbols for blocker: NNSi_G2dMCEnumAnimBank 0x02064D70 arm
 *   extern void NNSi_G2dMCEnumAnimBank(void *, void *, unsigned);
 *   void MCSS_SetCellCallback(char *p, unsigned flags, void *callback)
 *   { NNSi_G2dMCEnumAnimBank(p + 0x68, callback, flags); }
 * lever: Offset local precedes the entry pointer, and is initialized first.
 * split: Caller-only tu --suggest-split MATCH, zero viable pieces; both
 * 02015F40 witnesses are inside this callback. No overlay leaves filed.
 */
void func_02201304(void *task, void *arg)
{
    int *q = arg;

    char *p = (char *)func_021F8694();
    int i = q[1];
    int off;
    char *e;
    if (i == -1) {
        func_020307B0(q);
        func_02030EAC(task);
        return;
    }
    off = i * 0x5c;
    e = p + 8;
    if (*(void **)(e + off) == 0) {
        func_020307B0(q);
        func_02030EAC(task);
        return;
    }
    switch (q[0]) {
    case 0:
        ((struct Obj21726 *)((char *)MCSS_GetAnimCtrl(*(void **)(e + off))))->fC = 0;
        MCSS_SetCellCallback(*(void **)(e + off), i | 0x80000000, func_02201810);
        q[0]++;
        q[2] = d_0220AE78[(u32)(((u64)func_0203F0A8() * 3) >> 32)];
        return;
    case 1:
        q[2]--;
        if (q[2] != 0 && ((struct Obj21725 *)p)->f51C == 0 && func_021F9824((void *)func_021F86C4()) != 0) break;
        MCSS_SetAnimeIndex(*(void **)(e + off), 0);
        ((struct Obj21727 *)((char *)MCSS_GetAnimCtrl(*(void **)(e + off))))->fC = 1;
        MCSS_SetCellCallback(*(void **)(e + off), i, func_02201810);
        q[0]++;
        return;
    case 2:
        MCSS_SetAnimCallback(*(void **)(e + off), i, (void *)func_02201718, 1);
        func_020307B0(q);
        func_02030EAC(task);
        *(int *)(p + off + 0x30) = 0;
        break;
    }
}

/*
 * lever: the slot test written as char-pointer arithmetic (p + k * 0x5c + 0x30)
 * swaps the row and base registers in the case-0 loop; indexing a 0x5c-byte
 * Slot_02201098 struct array evaluates the row first, as the original does.
 */
void func_02201408(void *task, void *arg)
{
    Work_02201408 *w = arg;

    Tab6 keys = d_0220A0C8;
    Tab6 angs = d_0220A0B0;
    Tab12 tgt = d_0220A0E0;
    Vec_022011FC v;
    Vec_022011FC pos;
    int idx[3];
    int i;
    int step;

    switch (w->state) {
    case 0:
        for (i = 0; i < 3; i++) {
            if (((Slot_02201098 *)w->p)[keys.v[w->idx][i]].busy != 0)
                break;
        }
        if (i != 3)
            return;
        for (i = 0; i < 3; i++)
            w->ang[i] = angs.v[w->idx][i];
        step = (w->dir == 0) ? 0x1000 : -0x1000;
        func_021F6AA8((Obj_021F6AA8 *)(func_021F86A4()), w->idx, 0, step, 0x3c);
        w->step = (w->dir == 0) ? 0x16c : -0x16c;
        w->cnt = 0x3c;
        if (w->sound)
            GFL_USE_PlaySeInSlot((void *)0x6ca, 2);
        w->state++;
        return;
    case 1:
        for (i = 0; i < 3; i++) {
            if (func_021FFD9C(w->p, keys.v[w->idx][i])) {
                v.x = MUL(FX_SinCosTable_[((u16)w->ang[i] >> 4) * 2], 0x5000);
                v.y = 0x666;
                v.z = (w->idx == 0) ? 0xc000 : -0xd000;
                v.z += MUL(FX_SinCosTable_[((u16)w->ang[i] >> 4) * 2 + 1], 0x5000);
                func_021FF4C0(w->p, keys.v[w->idx][i], 0, (Vec_021F6560 *)&v, 0, 0, 0);
            }
            w->ang[i] += w->step;
        }
        if (--w->cnt != 0)
            return;
        for (i = 0; i < 3; i++) {
            if (func_021FFD9C(w->p, keys.v[w->idx][i])) {
                func_022018A8((Unit_v1098 *)w->p, (Vec3_vF228 *)&pos, tgt.v[w->dir][w->idx][i]);
                func_021FF4C0(w->p, keys.v[w->idx][i], 0, (Vec_021F6560 *)&pos, 0, 0, 0);
            }
        }
        w->state++;
        return;
    case 2:
        if (*(int *)(w->p + 0x514) != 0)
            return;
        for (i = 0; i < 3; i++) {
            idx[i] = func_022019F4(w->p, keys.v[w->idx][i]);
            BTLV_GAUGE_HideSlot((char *)func_021F86B4(), keys.v[w->idx][i]);
        }
        for (i = 0; i < 3; i++) {
            if (idx[i] != -1)
                ((Slot_02201098 *)w->p)[idx[i]].target = tgt.v[w->dir][w->idx][i];
        }
        if (w->sound) {
            GFL_USE_StopSeSlot(2);
            GFL_USE_PlaySeInSlot((void *)0x57a, 1);
        }
        func_021F89BC(task);
        return;
    }
}

void func_02201700(void *h)
{
    char *p = *((char **)TCBL_IsDeletePending(h));
    ((struct Obj21729 *)p)->f510 &= ~4;
}

/*
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 sole-ref/code 02015EF4 and 02015EEC are integrator-owned.
 * Verified C for 02015EF4 reused from ov094_func_02201810.c:
 *   typedef unsigned char u8;
 *   u8 MCSS_GetStopCellNum(char *p) { return **(u8 **)(p + 0x30); }
 * Verified C for 02015EEC: one, Thumb dsi/1.1p1 -O4,p EXACT 6 bytes;
 * proof: scratchpad/overlay-goal-20260930-w29/B6/eec-proof.log
 *   typedef unsigned short u16;
 *   u16 MCSS_GetAnimSeqNum(char *p) { return **(u16 **)(p + 0x28); }
 * lever: Bind the random draw before the variable 64-bit product.
 * split: Caller-only tu --suggest-split MATCH, zero viable pieces;
 * 02015EEC has only this caller. No overlay leaves filed.
 */
void func_02201718(int i)
{
    char *p = (char *)func_021F8694();
    char *e;
    int off;
    unsigned n;
    u32 draw;
    int *q;
    if (i == -1) return;
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) return;
    if (func_021F9824((void *)func_021F86C4()) == 0) return;
    if (((GlobalFlags *)(p + 0x510))->disabled) return;
    if (MCSS_GetStopCellNum(*(void **)(e + off)) == 0xff) {
        *(u32 *)(p + 0x54 + off) |= 0x800;
        return;
    }
    n = ((Flags_02201098 *)(p + 0x54 + off))->count;
    ((Flags_02201098 *)(p + 0x54 + off))->count = n - 1;
    draw = func_0203F0A8();
    if ((u32)(((u64)draw * n) >> 32) != 0) return;
    ((Flags_02201098 *)(p + 0x54 + off))->count = 3;
    q = func_02030734((u16)((((struct Obj13608 *)p)->f540 & 0x7fff) | 0x8000), 12, 1, d_0220AE7C, 0xd5e);
    q[1] = i;
    if (MCSS_GetAnimSeqNum(*(void **)(e + off)) > 1) MCSS_SetAnimeIndex(*(void **)(e + off), 1);
    *(void **)(p + off + 0x30) = func_02030DA8(((struct Obj13608 *)p)->f0, func_02201304, q, 0);
}

/*
 * blocker (cleared 2026-10-01, arm9 leaf filed): two unlabelled arm9 Thumb leaves (the integrator's; no witness outside this range).
 *   Every concrete byte matches; only the two bl relocation sites stay wildcarded.
 *   Verified C (match.py one --arm9 no --region, --thumb, dsi/1.1p1 -O4,p), both EXACT:
 *
 *     typedef unsigned char u8;
 *     u8 MCSS_GetStopCellNum(char *p)              // 0x02015EF4, 6 bytes
 *     {
 *         return **(u8 **)(p + 0x30);
 *     }
 *     u8 MCSS_GetStopCellIndex(char *p, int i)       // 0x02015EFC, 8 bytes
 *     {
 *         return (*(u8 **)(p + 0x30) + i)[2];  // `[i + 2]` is 5 bytes out
 *     }
 *
 * lever: the first test reads the row through the indexed base (`base[idx].h`), the loop
 *   through `e = &base[idx]` inside the loop body; a shared `base + off` char cast is CSE'd
 *   into one register and comes out 8 bytes short. `idx == -1` (u16 against int -1) is not
 *   folded: it keeps the movs/mvns pair. The two `v = 1` arms cross-jump only when the
 *   found test is `if (found == 0) v = 0; else v = 1;`.
 */
int func_02201810(u32 flags, int a, int *out, int key)
{
    Row *base = (Row *)func_021F8694();
    u16 idx = flags;
    int found;
    int n;
    int i;
    int v;

    if (idx == -1)
        return 0;
    if (base[idx].h == 0)
        return 0;
    if (flags & 0x80000000) {
        found = 0;
        n = MCSS_GetStopCellNum(base[idx].h);
        for (i = 0; i < n; i++) {
            Row *e = &base[idx];

            if (key == MCSS_GetStopCellIndex(e->h, i))
                found = 1;
        }
        if (found == 0)
            v = 0;
        else
            v = 1;
    } else {
        v = 1;
    }
    out[3] = v;
    return 1;
}

void func_02201894(int i)
{
    *(int *)((char *)func_021F8694() + i * 0x5c + 0x4c) = 0;
}

void func_022018A8(Unit_v1098 *u, Vec3_vF228 *out, int i)
{
    const Vec3_vF228 *t = (const Vec3_vF228 *)u;

    switch (i) {
    case 0:
    case 1:
        t = &d_0220A050[i];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (u->flags.b1)
            t = &d_0220A1A0[i - 2];
        else if (u->flags.b0)
            t = &d_0220A158[i - 2];
        else
            t = &d_0220A080[i - 2];
        break;
    case 6:
    case 7:
        if (u->flags.b1)
            t = &d_0220A1A0[i - 2];
        else
            t = &d_0220A158[i - 2];
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        t = &d_0220A110[i - 8];
        break;
    }
    out->x = t->x;
    out->y = t->y;
    out->z = t->z;
}

int func_02201934(Unit_v1098 *u, int i, int mode)
{
    if (mode == 0) {
        switch (i) {
        case 0:
        case 1:
            return d_02209FC8[i];
        case 2:
        case 3:
        case 4:
        case 5:
            if (u->flags.b1)
                return d_0220A008[i - 2];
            if (u->flags.b0)
                return d_0220A038[i - 2];
            return d_02209FD0[i - 2];
        case 6:
        case 7:
            if (u->flags.b1)
                return d_0220A008[i - 2];
            return d_0220A038[i - 2];
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            return d_0220A020[i - 8];
        }
    } else {
        if (i < 8) {
            if (i & 1)
                return 0x10000;
            return 0x20000;
        }
        return 0x10000;
    }
}

int func_022019F4(char *p, int key)
{
    int i;

    for (i = 0; i < 14; i++) {
        char *e = p + i * 0x5c;

        if (((struct Obj12236 *)e)->f8 != 0 && key == ((struct Obj12236 *)e)->f50)
            return i;
    }
    return -1;
}

/*
 * lever: `(b & 1) == e->flag` written inline in the condition; a hoisted local `f = b & 1` costs a different register order.
 */
int func_02201A20(int a, int b, int *o1, u16 *o2, int *o3)
{
    int found = 0;
    unsigned i;

    for (i = 0; i < 0x30; i++) {
        const Ent_02201894 *e = (const Ent_02201894 *)(d_0220A1E8 + i * 8);
        unsigned o = i * 8;

        if (a == e->key && (b & 1) == e->flag) {
            o1[0] = *(const s16_02201894 *)(d_0220A1EA + o);
            o1[1] = 0;
            o1[2] = *(const s16_02201894 *)(d_0220A1EC + o);
            *o2 = *(const u16 *)(d_0220A1EE + o);
            *o3 = e->hi;
            found = 1;
            break;
        }
    }
    return found;
}
