/*
 * file:     worldtrade_box.c
 * unit:     yes
 * function: func_021F4580, func_021F46A8, func_021F47C0, func_021F4864, func_021F4894, func_021F489C, func_021F49A4, func_021F49A8, func_021F49F8, func_021F4BCC, func_021F4BE0, func_021F4BF8, func_021F4CE4, func_021F4D14, func_021F4D50, func_021F4E30, func_021F4E64, func_021F4E98, func_021F4EA0, func_021F4EB4, func_021F4EC0, func_021F4EC8, func_021F4ED4, func_021F4EDC, func_021F4EFC, func_021F4F84, func_021F4F90, func_021F4FA4, func_021F4FC4, func_021F4FF4, func_021F5008, func_021F5034, func_021F5060, func_021F5074, func_021F50EC, func_021F513C, func_021F5154, func_021F51F0, func_021F5204, func_021F5250, func_021F5358, func_021F5374, func_021F5420, func_021F577C, func_021F57EC, func_021F5940, func_021F5980, func_021F59E8, func_021F5A18, func_021F5A7C, func_021F5B8C, func_021F5CA4, func_021F5CD4, func_021F5CFC, func_021F5E44, func_021F5F60, func_021F5F9C, func_021F5FC0, func_021F601C, func_021F6178, func_021F61D4, func_021F632C, func_021F6384, func_021F63A8, func_021F63EC, func_021F6418, func_021F643C, func_021F6474, func_021F651C, func_021F6548, func_021F656C, func_021F65C8, func_021F65E8, func_021F6604, func_021F663C, func_021F66C8, func_021F66F0, func_021F6748, func_021F6754, func_021F67A8, func_021F68A4, func_021F6B34, func_021F6B40, func_021F6B80, func_021F6BA4, func_021F6BC4, func_021F6BFC, func_021F6C28, func_021F6C48, func_021F6C80, func_021F6CDC, func_021F6D14, func_021F6DB4, func_021F6DE8, func_021F6E08, func_021F6E58, func_021F6FD4, func_021F7268, func_021F72C4, func_021F7338, func_021F7374, func_021F73DC, func_021F74E4, func_021F74F8, func_021F7538, func_021F75C0, func_021F76BC, func_021F76D8, func_021F777C, func_021F7840, func_021F7878, func_021F7964, func_021F798C, func_021F79EC, func_021F7A18, func_021F7A4C, func_021F7A70, func_021F7A8C, func_021F7B50, func_021F7B9C, func_021F7BC8, func_021F7CB4, func_021F7CDC, func_021F7D00, func_021F7D80, func_021F7DA8, func_021F7DD0, func_021F7E74, func_021F7E9C, func_021F7EC0, func_021F7F14, func_021F7F64, func_021F7F80, func_021F7F9C, func_021F7FD4, func_021F8010, func_021F8078, func_021F8098, func_021F8104, func_021F8154, func_021F8178, func_021F81C8, func_021F8290, func_021F8358, func_021F8498, func_021F84BC, func_021F84EC, func_021F8554, func_021F8668, func_021F86A8, func_021F875C, func_021F87E0, func_021F882C, func_021F886C
 * address:  0x021F4580
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02202608  0x02202608  thumb
 *   func_022026D8  0x022026D8  thumb
 *   g_02203F80  0x02203F80  data
 *   str_02203AF8  0x02203AF8  data  a1
 *   ov114_id  0x00000072  data
 *   ov067_id  0x00000043  data
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_0205D074 0x0205D074 arm
 *   GFL_NET_WM_ICON_EasySetLevel 0x020370F4 arm
 *   func_021C7C1C 0x021C7C1C arm ov114
 *   PROCSYS_Main 0x02031330 arm
 *   func_02030D28 0x02030D28 arm
 *   func_02202770 0x02202770 thumb ov135
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_021FF6A4 0x021FF6A4 thumb ov135
 *   func_021FFB20 0x021FFB20 thumb ov135
 *   CLACT_DrawSystem 0x0204A600 arm
 *   d_02203A80 0x02203A80 data a4
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0203133C 0x0203133C arm
 *   func_02202744 0x02202744 thumb ov135
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   str_02203B08  0x02203B08  data  a1
 *   func_020490F4  0x020490F4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02049F34  0x02049F34  arm
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOBJPltt 0x0207E51C  arm
 *   func_02008550  0x02008550  thumb
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   d_02202BE0     0x02202BE0  data
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   data_02202BC8 0x02202BC8 data a4
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   data_02202C2C 0x02202C2C data a4
 *   func_0204B404  0x0204B404  arm
 *   DWC_GetLinkLevel  0x0205CCD8  arm
 *   sub_02012FFC  0x02012FFC  thumb  arm9
 *   g_02202BFC  0x02202BFC  data  ov135
 *   func_021FFCD4  0x021FFCD4  thumb
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   func_020056BC  0x020056BC  thumb
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   tbl_02202BB8  0x02202BB8  data
 *   func_02030EAC  0x02030EAC  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_0200F7C0   0x0200F7C0  thumb
 *   func_021FFFE8 0x021FFFE8 thumb ov135
 *   func_021FFD44 0x021FFD44 thumb ov135
 *   func_0207D55C 0x0207D55C arm
 *   func_021F9254 0x021F9254 thumb ov135
 *   g_02203B0C  0x02203B0C  data  ov135
 *   func_021FFD74 0x021FFD74 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   BG_SYS_GetSubVisiblePlanes  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040B94  0x02040B94  arm
 *   g_02202C94  0x02202C94  data  ov135
 *   g_02202CE4  0x02202CE4  data  ov135
 *   g_02202D04  0x02202D04  data  ov135
 *   g_02202CA4  0x02202CA4  data  ov135
 *   g_02202CC4  0x02202CC4  data  ov135
 *   sub_020403F4  0x020403F4  arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02200AB4 0x02200AB4 thumb ov135
 *   func_02200B34 0x02200B34 thumb ov135
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   func_020355C4  0x020355C4  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_StopActorAnim  0x0204B974  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   tbl_02202D24   0x02202D24  data  a2
 *   tbl_02202C50   0x02202C50  data  a2
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_02200BAC  0x02200BAC  thumb
 *   func_02202940 0x02202940 thumb ov135
 *   func_020452E8 0x020452E8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02030734 0x02030734 arm
 *   str_02203B54 0x02203B54 data a1
 *   func_022025E4  0x022025E4  thumb
 *   tbl_02202E24  0x02202E24  data  a1
 *   tbl_02202DA4  0x02202DA4  data  a1
 *   d_02203B68 0x02203B68 data a4
 *   func_02202840  0x02202840  thumb  ov135
 *   MSGDATA_AllocString   0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_WIN_MakeScreen   0x02045374  arm
 *   unit_02045730  0x02045730  arm
 *   sub_020409B4   0x020409B4  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   STRBUF_Delete   0x02045808  arm
 *   func_02202858  0x02202858  thumb  ov135
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb
 *   func_02082B0C  0x02082B0C  arm
 *   func_0201BB5C  0x0201BB5C  thumb
 *   GX_LoadOBJ     0x0207E780  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_02007A18  0x02007A18  thumb
 *   func_0200785C  0x0200785C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   tbl_02202C58  0x02202C58  data  a4
 *   func_020120F4  0x020120F4  thumb
 *   func_0200ADB4  0x0200ADB4  thumb
 *   func_0200AD9C  0x0200AD9C  thumb
 *   func_02019CE0  0x02019CE0  thumb
 *   PROCSYS_Push  0x02031348  arm
 *   str_02203B6C   0x02203B6C  data  a1
 *   d_021E75B4     0x021E75B4  data  ov119
 *   d_021E75CC     0x021E75CC  data  ov119
 *   d_021E75FC     0x021E75FC  data  ov119
 *   ov119_id       0x00000077  data
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02012984  0x02012984  thumb
 *   SHINKA_CHECK_CheckEvolution  0x0201B2B0  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   d_02208C40     0x02208C40  data  ov195
 *   ov195_id       0x000000C3  data
 *   MYSTATUS_Create  0x0200846C  thumb
 *   MYSTATUS_Init  0x020084A0  thumb
 *   func_020084D4  0x020084D4  thumb
 *   func_02008560  0x02008560  thumb
 *   func_02008568  0x02008568  thumb
 *   func_0200854C  0x0200854C  thumb
 *   func_02008558  0x02008558  thumb
 *   func_02008574  0x02008574  thumb
 *   func_0220262C  0x0220262C  thumb
 *   func_02007664  0x02007664  thumb
 *   func_020076D0  0x020076D0  thumb
 *   func_0200752C  0x0200752C  thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_021F9890 0x021F9890 thumb ov135
 *   g_02203BBC  0x02203BBC  data  ov135
 *   func_021F99D0 0x021F99D0 thumb ov135
 *   func_02041300  0x02041300  arm
 *   g_02202F64  0x02202F64  data  ov135
 *   g_02202F84  0x02202F84  data  ov135
 *   g_02202F44  0x02202F44  data  ov135
 *   g_02202FA4  0x02202FA4  data  ov135
 *   func_02049624 0x02049624 arm
 *   func_0204989C 0x0204989C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   tbl_02202EC0 0x02202EC0 data a2
 *   func_02082AC0 0x02082AC0 arm
 *   func_021F8990 0x021F8990 thumb ov135
 *   g_02203C00 0x02203C00 data a4
 *   func_021F9968  0x021F9968  thumb  ov135
 *   func_021F8950 0x021F8950 thumb ov135
 *   func_02202644 0x02202644 thumb ov135
 *   func_021F99F0 0x021F99F0 thumb ov135
 *   func_021F89A8 0x021F89A8 thumb ov135
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_022028C8  0x022028C8  thumb
 *   tbl_02202EB0   0x02202EB0  data
 *   func_02202670  0x02202670  thumb
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 *   tbl_0220307C   0x0220307C  data
 *   func_022026A0  0x022026A0  thumb
 *   tbl_02203B84 0x02203B84 data a2
 *   d_02202ED8 0x02202ED8 data a4
 *   tbl_0220301C 0x0220301C data a4
 *   tbl_02202FC4 0x02202FC4 data a4
 *   str_02203C18 0x02203C18 data a1
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb  arm9
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb  arm9
 *   GAME_DATA_SaveCancel  0x02012E08  thumb  arm9
 *   POKE_TOOL_ChangeBoxForm  0x020179B8  thumb  arm9
 *   POKE_TOOL_CalcBoxLevel  0x02018438  thumb  arm9
 *   PROCSYS_Create  0x02031324  arm  arm9
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm  arm9
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm  arm9
 *   BG_SYS_ClearSubPlanes  0x02043588  arm  arm9
 *   POKE_TOOL_ChangeForm  0x02017988  thumb  arm9
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_Delete  0x0201F868  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   BMP_MENULIST_Create  0x0201FF30  thumb  arm9
 *   BMP_MENULIST_Delete  0x0202020C  thumb  arm9
 *   TIME_ICON_Create  0x0202EE30  thumb  arm9
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm  arm9
 *   PROCSYS_AllocProcWork  0x0203159C  arm  arm9
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm  arm9
 *   BMP_WIN_Init  0x02045088  arm  arm9
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *   CLACT_RestartActorAnim  0x0204B9A0  arm  arm9
 */
#include "worldtrade_types.h"
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj12197.h"
#include "../../matched/include/Obj09227.h"
#include "../../matched/include/Obj23379.h"
#include "../../matched/include/Obj23380.h"
#include "../../matched/include/Obj23381.h"
#include "../../matched/include/Obj23382.h"
#include "../../matched/include/Obj23383.h"
#include "../../matched/include/Obj23384.h"
#include "../../matched/include/Obj23385.h"
#include "../../matched/include/Obj23386.h"
#include "../../matched/include/Obj23387.h"
#include "../../matched/include/Obj23388.h"
#include "../../matched/include/Obj23389.h"
#include "../../matched/include/Obj12201.h"

#define ASSERT(x) if (!(x)) func_02034714(str_02203B08, 0, str_02203B08)
struct Ctx;
struct MsgBank;
struct WordSet;
struct Obj0203159C;
struct Rec;
struct S020314B8;
struct S020315D4;
struct DispVram;
struct Cfg;
struct Sub0200852CObj;
struct Bank;
struct R;
struct U16Vec;
struct TaskMenu;
struct TaskMenuTmpl;
struct TaskMenuState;
struct Obj;
struct Vec2;
struct Descriptor;
struct Node;
struct Actor;
struct CharBuf;
struct Slot;
struct ArcFile;
struct NitroFileHeader;
struct Sav;
struct Sub020079BCEntry;
struct RecDC;
struct BigObj;
struct Ctx_021F6FD4;
struct Party;
struct PartyMon;
struct Sub02007454Entry;
struct Personal;
struct Sub02009470Obj;
struct Blk37;
struct Src;
typedef struct {
    u8 pad0[0x20];
    u32 x20;
} Args_021F4580;

typedef struct { int (*init)(u8 *, int); int (*update)(u8 *, int); int (*finish)(u8 *, int); } Handler;

typedef volatile u32 vu32_021F4580;

typedef volatile u16 vu16;

typedef struct {
    u8 pad0[0xC];
    u16 *data;
} PlttData;

typedef void (*Fn)(void);

typedef struct { union { void *text; u32 a; }; u32 b, c; } BoxItem;

typedef struct { BoxItem item[2]; } BoxItems2;

typedef struct { u32 heap; u8 count,pad[3]; BoxItem *items; u32 mode; u8 a,b,c,d; } BoxMenu_021F4580;

typedef struct { BoxItem item[3]; } BoxItems3;

typedef volatile u16 vu16_021F5074;

struct DispConfig_021F4580 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

typedef volatile unsigned short vu16_021F50EC;

typedef volatile unsigned int vu32_021F4D50;

struct BgTemplate_021F4580 {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef struct {
    u16 x;
    u16 y;
} Pos_021F4580;

typedef struct {
    u8 pad0[0x14];
    void *pixels;
} CharData_p02;

typedef struct {
    u16 species;
    u8 form;
    u8 gender;
} MonTag;

typedef struct {
    u16 species;
    u8 form;
    u8 b3;
    u8 b4;
} WantTag;

typedef struct {
    u8 pad0[0xEC];
    MonTag have;
    WantTag want;
} Deposit;

typedef struct {
    s16 a;
    s16 b;
} Rec_p03;

typedef struct {
    u32 f0;
    int f4;
    u8 pad8[0x20C - 8];
} Entry_021F6DB4;

typedef struct {
    u8 pad0[0x10];
    u32 f10;
    u32 f14;
} Info_021F72C4;

typedef struct {
    u8 pad0[0xF6];
    u8 fF6;
    u8 padF7[0x108 - 0xF7];
    u32 f108;
    u32 f10C;
    u8 name[0x120 - 0x110];
    u8 f120;
    u8 f121;
    u8 f122;
    u8 pad123;
    u8 f124;
    u8 f125;
} Entry_021F72C4;

typedef struct { void *a,*b,*obj,*d,*e,*f,*g,*h,*i; u32 j,k,l; } Init;

typedef struct { u16 x,y,z; u8 a,b; } Pos_021F7374;

typedef struct {
    u32 id;
    union {
        struct { s16 x; s16 y; };
        struct { s16 key; s16 val; };
    };
} TableRow;

typedef struct { u32 w[4]; u16 count, rows; u32 rest[8]; } BoxMenu_021F7374;

extern int func_02034AC4(s32 handle);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02202608(u32 heap);
extern void *PROCSYS_Create(int a0);
extern u32 func_02030CB0(u32 n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_022026D8(void *ctx, u32 arg);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern int GFL_NET_GetRunState(void);
extern int func_0205D074(void);
extern u32 GFL_NET_WM_ICON_EasySetLevel(u32);
extern void func_021C7C1C(void);
extern u32 PROCSYS_Main(void *);
extern void func_02030D28(struct Ctx *c);
extern void func_02202770(void *);
extern u32 WIPE_SYS_EndCheck(void);
extern void func_021FF6A4(u8 *);
extern void func_021FFB20(u8 *, int, int);
extern void CLACT_DrawSystem(void *);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern void func_02030DA4(void *);
extern u32 func_020307B0(void *p);
extern void func_0203133C(struct S020314B8 *p);
extern void func_02202744(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(s32 handle);
extern void func_020419E4(void);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_020490F4(u32 id, u32 heap);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void DC_FlushRange(void *p, u32 size);
extern void GX_LoadOBJPltt(const void *src, u32 offset, u32 size);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void func_020434DC(u32 a, u32 b);
extern void BG_SYS_SetSubPlaneVisible(u32 a, u32 b);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void APP_TASKMENU_UpdateMenu(void *);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int DWC_GetLinkLevel(void);
extern signed char sub_02012FFC(void);
extern void func_021FFCD4(u8 *p);
extern void CLACT_ReleasePalette(u32 v);
extern void CLACT_ReleaseCharacter(u32 v);
extern void CLACT_ReleaseCellAnim(u32 v);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern u32 func_020056BC(void);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void TIME_ICON_Delete(u8 *p);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 v);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_02043534(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 a);
extern void func_0203F8F4(u16 heapId);
extern void BMP_WIN_Init(u16 heapId);
extern void func_0203FC28(struct DispConfig_021F4580 *cfg);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_02030EAC(struct Node *n);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void *func_020120F4(const struct Ctx *p);
extern void GAME_DATA_SaveCancel(char *p);
extern void func_0200F7C0(u32 c);
extern void func_021FFFE8(u8 *, u32, u32);
extern void func_021FFD44(char *p);
extern int func_0207D55C(volatile u16 *reg);
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
extern void func_021F9254(u8 *);
extern void func_021FFD74(char *p);
extern void func_022000E4(char *p);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern u32 BG_SYS_GetSubVisiblePlanes(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate_021F4580 *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_02041570(int channel, u16 val);
extern void sub_020403F4(u32 i);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02200AB4(u8 *);
extern void func_02200B34(u8 *);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *, u32);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u8 func_020355C4(void);
extern void CLACT_SetActorBgPriority(u32, int);
extern void CLACT_StopActorAnim(struct Actor *a);
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern int func_021F91A0(void *win, void *str, u32 c, u32 d, u32 e, u16 f, void *g);
extern void func_02200BAC(u8 *p, u32 k);
extern void func_02202940(struct Obj *p);
extern u32 func_020452E8(struct Descriptor *d);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void func_020061E4(u32 se);
extern void func_022025E4(u32 a, u32 b, u32 c);
extern int TOUCHPANEL_HitTrg(const void *key);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern void *BMP_MENUWORK_Create(u32 a, u32 b);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int POKE_TOOL_ChangeBoxForm(int a0, int a1);
extern u32 func_0201AA18(void *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern u32 func_02202840(u8 *p);
extern int TOUCHPANEL_GetTrg(void);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 unit_02045730(u32 a);
extern void sub_020409B4(u32 index);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern void func_02082B0C(const void *src, void *dst, u32 n);
extern u32 func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern u32 POKE_TOOL_CalcBoxLevel(void *p);
extern void GX_LoadOBJ(const void *src, u32 offset, u32 size);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32 func_0202136C(u16 v);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void func_0200785C(void *save, u32 box, void *dest);
extern void *POKE_TOOL_GetBoxParam(void *a);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern int func_020078C4(void *save, u32 box);
extern u32 func_02017E1C(void *a, u32 b, u32 c);
extern u8 func_020076A4(void *save);
extern u8 func_020076B4(void *save);
extern void *func_0200ADB4(void *sys);
extern void func_0200AD9C(void *sys, void *mon);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern void PROCSYS_Push(void *h, u32 id, void *a, void *b);
extern u8 func_02012984(const struct BigObj *p);
extern u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern struct Party *func_0201A920(u32 heap);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void *MYSTATUS_Create(int a0);
extern void MYSTATUS_Init(struct Sub0200852CObj *p);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_02008560(struct Sub0200852CObj *obj, u8 value);
extern void func_02008568(struct Sub0200852CObj *obj, u8 value);
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
extern void func_02008558(struct Sub0200852CObj *obj, u8 value);
extern void func_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);
extern void func_0220262C(u32 a, u32 b);
extern void func_02007664(void *save, u32 box, u32 slot);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);
extern void *func_021F9890(Init *,u32,u32);
extern void func_021F99D0(u8 *p);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_02082AC0(u32 value, void *dst, u32 size);
extern void func_021F8990(u8 *p);
extern void func_021F9968(u8 *p, int mode);
extern int func_021F8950(void *p, u16 *old);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern void func_02202644(u32 a, int kind);
extern int func_021F99F0(void *);
extern void *func_0201ADE4(u32,int,u32);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern void func_021F89A8(u8 *p, int i, u16 a, u16 b);
extern u32 func_022028C8(void *win, u32 z, void *str, u32 x, u32 y, u32 z2, u16 color, void *g);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_02202670(u32 a, u32 b, u32 c, u32 d);
extern int ARC_UTIL_LoadMemberWithSize(int a0, int a1, int a2, int a3, u32 *out);
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);
extern u32 func_020173EC(void);
extern void func_022026A0(u8 *p, u32 k);
extern const void *func_020084F4(const void *p);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_02009628(const struct Sub02009470Obj *obj);
extern u8 func_02009584(const struct Sub02009470Obj *obj);
extern u8 func_0200960C(const struct Sub02009470Obj *obj);
extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);
int func_021F4580(void *proc, int *seq, Args_021F4580 *args);
int func_021F46A8(void *unused0, int *state, void *unused2, Work *p);
int func_021F47C0(void *ctx, int unused1, int unused2, Work *p);
void func_021F4864(void *unused, Work *p);
void func_021F4894(const struct DispVram *a0);
void func_021F489C(Work *p, Args *args);
void func_021F49A4(Work *a0);
void func_021F49A8(void);
void func_021F49F8(Work *p, u32 mode);
void func_021F4BCC(Work *p);
void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);
void func_021F4BF8(WorldtradeBoxObj1 *p,int b,int unused,int a,int c,u8 flag);
void func_021F4CE4(Work *p);
int func_021F4D14(Work *p);
void func_021F4D50(WorldtradeBoxObj1 *p, u16 a, int count, int b);
u32 func_021F4E30(Work *p);
void func_021F4E64(Work *p);
void func_021F4E98(Work *p, u32 a, u32 b);
void func_021F4EA0(u32 a, u16 b, u16 c);
int func_021F4EB4(void);
void func_021F4EC0(Work *p, u32 a, u32 b);
void func_021F4EC8(Work *p);
int func_021F4ED4(void);
void func_021F4EDC(Work *p);
void func_021F4EFC(Work *p);
void func_021F4F84(Work *p);
void func_021F4F90(Work *p);
void func_021F4FA4(Work *p);
void func_021F4FC4(Work *p);
void func_021F4FF4(u32 a, u32 b, u32 c);
void func_021F5008(u32 x);
void func_021F5034(u32 x);
void func_021F5060(void);
void func_021F5074(Work *p);
void func_021F50EC(Work *p);
void func_021F513C(WorldtradeBoxObj1 *p);
int func_021F5154(Work *p);
void func_021F51F0(u8 *p);
int func_021F5204(WorldtradeBoxObj1 *p);
void func_021F5250(void);
void func_021F5358(void);
void func_021F5374(Work *p);
void func_021F5420(Work *p);
void func_021F577C(Work *p);
void func_021F57EC(Work *p);
void func_021F5940(Work *p);
void func_021F5980(Work *p);
void func_021F59E8(Work *p);
int func_021F5A18(Work *p);
void func_021F5A7C(Work *p);
void func_021F5B8C(Work *p);
int func_021F5CA4(Work *p);
void func_021F5CD4(Work *p, u32 k);
int func_021F5CFC(Work *p);
void func_021F5E44(Work *p);
void func_021F5F60(u32 cursor, int i);
int func_021F5F9C(int a, int b, int c);
int func_021F5FC0(WorldtradeBoxObj1 *p);
int func_021F601C(Work *p);
int func_021F6178(WorldtradeBoxObj1 *p);
int func_021F61D4(Work *p);
int func_021F632C(WorldtradeBoxObj4 *p);
int func_021F6384(Work *p);
int func_021F63A8(Work *p);
int func_021F63EC(Work *p);
int func_021F6418(Work *p);
int func_021F643C(Work *p);
int func_021F6474(Work *p);
int func_021F651C(Work *p);
int func_021F6548(Work *p);
int func_021F656C(Work *p);
int func_021F65C8(WorldtradeBoxObj1 *p);
int func_021F65E8(Work *p);
int func_021F6604(Work *p);
void func_021F663C(Work *p, u32 b, u32 c, u32 d, u32 e, u32 sel);
u32 func_021F66C8(u32 a, u32 b, u32 c, u32 d);
void func_021F66F0(u32 species, u32 form, u32 gender, u32 isEgg, u32 slot, u32 f8, u32 arc, IconRec *rec);
void func_021F6748(u32 a, u8 *q);
void func_021F6754(Work *p);
void func_021F67A8(void *mon, u32 icon, u32 item_spr, u16 *species, u32 slot, void *arc, Info *info, IconRec *rec);
void func_021F68A4(Work *p, int box);
int func_021F6B34(int v);
void *func_021F6B40(void *party, void *save, int box, int slot);
u32 func_021F6B80(u8 *p, u32 b, u32 c);
int func_021F6BA4(void *party, void *save, int box, int slot);
u32 func_021F6BC4(void *sav);
int func_021F6BFC(u32 handle);
int func_021F6C28(u32 handle);
int func_021F6C48(void *party, void *save, int box, int slot);
int func_021F6C80(WorldtradeBoxObj9 *pa, WorldtradeBoxObj7 *pb);
int func_021F6CDC(void *mon, WorldtradeBoxObj7 *want);
void func_021F6D14(Deposit *dst, Work *p);
void func_021F6DB4(Rec_p03 *recs, u32 unused, WorldtradeBoxObj7 *key, Entry_021F6DB4 *ent);
int func_021F6DE8(u32 handle);
void func_021F6E08(Work *p);
int func_021F6E58(Work *p);
int func_021F6FD4(Work *p);
int func_021F7268(Work *p);
Info_021F72C4 *func_021F72C4(Entry_021F72C4 *e);
Entry *func_021F7338(Work *p, int kind);
void func_021F7374(Work *p);
int func_021F73DC(Work *p);
void func_021F74E4(u8 *p);
int func_021F74F8(WorldtradeBoxObj1 *p);
void func_021F7538(Work *p, u32 b, u32 c, u32 d, u32 e);
void func_021F75C0(void);
void func_021F76BC(void);
void func_021F76D8(Work *p);
void func_021F777C(Work *p);
void func_021F7840(Work *p);
void func_021F7878(Work *p);
void func_021F7964(Work *p);
void func_021F798C(Work *p);
void func_021F79EC(Work *p);
int func_021F7A18(Work *p);
int func_021F7A4C(Work *p);
int func_021F7A70(Work *p);
int func_021F7A8C(Work *p);
int func_021F7B50(Work *p);
int func_021F7B9C(WorldtradeBoxObj8 *p, int event);
int func_021F7BC8(Work *p);
int func_021F7CB4(Work *p);
int func_021F7CDC(Work *p);
int func_021F7D00(Work *p);
int func_021F7D80(Work *p);
int func_021F7DA8(Work *p);
int func_021F7DD0(Work *p);
int func_021F7E74(Work *p);
int func_021F7E9C(Work *p);
int func_021F7EC0(Work *p);
int func_021F7F14(Work *p);
int func_021F7F64(Work *p);
u16 func_021F7F80(int mode);
void func_021F7F9C(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g);
void func_021F7FD4(void *win, void *bank, u32 index, u32 y, u16 color, void *g);
void func_021F8010(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *g);
u16 func_021F8078(int mode, u16 color);
void func_021F8098(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g);
void func_021F8104(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g);
void func_021F8154(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g);
void func_021F8178(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g);
void func_021F81C8(void *bank, void *names, int unused, WorldtradeBoxObj2 *win, u32 index, int mode, int place, void *g);
void func_021F8290(void *bank, void *names, int unused, WorldtradeBoxObj2 *win, u32 index, int mode, int place, void *g);
void func_021F8358(void *bank, void *ws, void **win, void *mon, MonTag *out, void *g);
u16 *func_021F8498(u32 heap, u32 unused, u32 *count);
void func_021F84BC(u32 i, int *start, int *end);
u8 *func_021F84EC(u32 id);
void func_021F8554(WorldtradeBoxObj5 *dst, Work *p);
void func_021F8668(WorldtradeBoxObj5 *dst, Work *p);
int func_021F86A8(void **menu, void *msg, void *endmsg, u16 *list, u32 unused4, u32 unused5, u32 kind, void *bag);
void *func_021F875C(Work *p, void **menu, void *win, void *endmsg, void *msg, WorldtradeBoxObj6 *cfg, void *bag);
int func_021F87E0(void **menu, void *msg, int kind);
void func_021F882C(u8 *dst, int i, int kind);
int func_021F886C(int key, int val, int which);
extern u8 ov114_id[];
extern u8 ov067_id[];
extern Work *g_02203F80;
extern const char str_02203AF8[];
extern const Handler d_02203A80[];
extern const char str_02203B08[];
extern u8 d_02202BE0[];
extern const BoxItems2 data_02202BC8;
extern const BoxItems3 data_02202C2C;
extern u8 g_02202BFC[];
extern const struct DispConfig_021F4580 tbl_02202BB8;
extern void (*g_02203B0C[])(u8 *);
extern struct DispConfig_021F4580 g_02202C94;
extern struct BgTemplate_021F4580 g_02202CE4;
extern struct BgTemplate_021F4580 g_02202D04;
extern struct BgTemplate_021F4580 g_02202CA4;
extern struct BgTemplate_021F4580 g_02202CC4;
extern const Pos_021F4580 tbl_02202D24[];
extern const Pos_021F4580 tbl_02202C50[];
extern const char str_02203B54[];
extern const u8 tbl_02202E24[];
extern const u8 tbl_02202DA4[][4];
extern const char d_02203B68[];
extern const u32 tbl_02202C58[];
extern char str_02203B6C[];
extern u8 d_021E75B4[];
extern u8 d_021E75CC[];
extern u8 d_021E75FC[];
extern u8 ov119_id[];
extern u8 d_02208C40[];
extern u8 ov195_id[];
extern void (*g_02203BBC[])(u8 *);
extern struct BgTemplate_021F4580 g_02202F64;
extern struct BgTemplate_021F4580 g_02202F84;
extern struct BgTemplate_021F4580 g_02202F44;
extern struct BgTemplate_021F4580 g_02202FA4;
extern const u16 tbl_02202EC0[][2];
extern const char g_02203C00[];
extern const u32 tbl_02202EB0[];
extern const int tbl_0220307C[];
extern const u16 tbl_02203B84[];
extern const BoxMenu_021F7374 d_02202ED8;
extern const TableRow tbl_0220301C[12];
extern const TableRow tbl_02202FC4[11];
extern const char str_02203C18[];





int func_021F4580(void *proc, int *seq, Args_021F4580 *args)
{
    Work *p;

    func_02034AC4((u32)ov114_id);
    func_02034AC4((u32)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 0x48, 0x30100);
    p = PROCSYS_AllocProcWork(proc, sizeof(Work), 0x48);
    func_02082BCC(p, 0, sizeof(Work));
    g_02203F80 = p;
    p->fEA8 = func_02202608(0x48);
    p->f12F0 = PROCSYS_Create(0x48);
    p->recMem = func_02030734(0x48, func_02030CB0(8), 0, str_02203AF8, 0xA1);
    p->rec_p = func_02030CBC(8, p->recMem);
    func_022026D8(p->tail, args->x20);
    p->words = func_0201EC74(0xB, 0x40, 0x48);
    p->msg[0] = func_02045B38(0, 2, 0xD0, 0x48);
    p->msg[2] = func_02045B38(0, 2, 0xD1, 0x48);
    p->msg[3] = func_02045B38(0, 2, 0xE8, 0x48);
    p->msg[1] = func_02045B38(0, 2, 0x46, 0x48);
    p->msg[4] = func_02045B38(0, 2, 0xE7, 0x48);
    func_021F489C((Work *)p, (Args *)args);
    BG_SYS_ClearGraphicsMemory(0);
    func_021F5074(p);
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_CancelChangeAndStopBgm();
    return 1;
}





int func_021F46A8(void *unused0, int *state, void *unused2, Work *p)
{
    if (GFL_NET_GetRunState() != 0) {
        func_0205D074();
        GFL_NET_WM_ICON_EasySetLevel(func_021F4EB4());
    }
    func_021C7C1C();
    p->busy_u = PROCSYS_Main(p->f12F0);
    func_02030D28(p->rec_p);
    func_02202770((u8 *)p + 0xfa0);
    switch (*state) {
    case 0:
        *state = d_02203A80[p->x10].init((u8 *)p, *state);
        func_021F49A8();
        break;
    case 1:
        if (WIPE_SYS_EndCheck() != 0) *state = 2;
        break;
    case 2:
        *state = d_02203A80[p->x10].update((u8 *)p, *state);
        break;
    case 3:
        if (WIPE_SYS_EndCheck() != 0) {
            *state = d_02203A80[p->x10].finish((u8 *)p, *state);
            if (p->fB8 != 0) {
                func_021FF6A4((u8 *)p);
                func_021FFB20((u8 *)p, (*(int *)&p->d0), 0);
                p->fB8 = 0;
            }
        }
        break;
    case 4:
        *state = 5;
        break;
    case 5:
        return 1;
    }
    func_021F4F84(p);
    if (*(u32 *)&p->res != 0) CLACT_DrawSystem(p->res);
    if (p->f12E8 > 0) p->f12E8 -= 1;
    return 0;
}





int func_021F47C0(void *ctx, int unused1, int unused2, Work *p)
{
    GFL_USE_CancelChangeAndStopBgm();
    func_021F50EC(p);
    func_021F49A4(p);
    MSGDATA_Delete(p->names);
    MSGDATA_Delete(p->msg[3]);
    MSGDATA_Delete(p->msg[2]);
    MSGDATA_Delete(p->bank);
    MSGDATA_Delete(p->msg_p);
    func_0201ED04(p->words);
    func_02030DA4(p->rec_p);
    func_020307B0(p->recMem);
    func_0203133C(p->f12F0);
    func_020307B0(p->fEA8);
    func_02202744((u8 *)p + 0xfa0);
    func_020315D4(ctx);
    func_020306F0(0x48);
    func_02034A5C((unsigned int)ov067_id);
    func_02034A5C((unsigned int)ov114_id);
    return 1;
}





void func_021F4864(void *unused, Work *p)
{
    func_020419E4();
    CLACT_VBlankSystem();
    if (p->once != 0) {
        p->once(p);
        p->once = 0;
    }
    if (p->every != 0) {
        p->every(p);
    }
}





void func_021F4894(const struct DispVram *a0)
{
    BG_SYS_SetVramBanks(a0);
}





void func_021F489C(Work *p, Args *args)
{
    ASSERT(args->a3C);
    ASSERT(args->a0);
    ASSERT(args->a4);
    ASSERT(args->a8);
    ASSERT(args->aC);
    ASSERT(args->a14);
    ASSERT(args->a18);
    ASSERT(args->a1C);
    ASSERT(args->a20);
    ASSERT(args->a24);
    p->args = args;
    p->x10 = 0;
    func_021F4EC0(p, 0, 0x13);
    p->sel = 0;
    p->sel_h = 0;
    p->xB58 = 3;
    p->xB59 = 0;
    p->xB5A = 0;
    p->xB5C = 0;
    p->active = 0;
    p->box = 0xFF;
    p->species = 0;
    p->xEB2 = 0;
    p->fE1A = 0;
    p->xDF8 = 0;
    p->fF84 = 0;
}





/*
 * Empty stub: a bare `bx lr`, the overlay's no-op placeholder body.
 */
void func_021F49A4(Work *a0)
{
}





static inline void SetWnd0InsidePlane(int wnd, int effect)
{
    u32 tmp = (*(vu16 *)0x04000048 & ~0x3F) | wnd;

    if (effect) {
        tmp |= 0x20;
    }
    *(vu16 *)0x04000048 = (u16)tmp;
}





static inline void SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp = (*(vu16 *)0x0400004A & ~0x3F) | wnd;

    if (effect) {
        tmp |= 0x20;
    }
    *(vu16 *)0x0400004A = (u16)tmp;
}





void func_021F49A8(void)
{
    *(vu32_021F4580 *)0x04001000 &= ~0xE000;
    *(vu32_021F4580 *)0x04000000 = (*(vu32_021F4580 *)0x04000000 & ~0xE000) | 0x2000;
    SetWnd0InsidePlane(0x1F, 0);
    SetWndOutsidePlane(0x1F, 1);
    *(vu16 *)0x04000040 = 0xF0FF;
    *(vu16 *)0x04000044 = 0x10;
}





/*
 * Load the screen's OBJ resources: the archive-0x60 cell, character,
 * palette and animation sets into the resource block at +0xBC0, the
 * OBJ palette from archive 7 at 0xA0 and a half-brightness copy of it
 * at 0x100, and from archive 0x1F the version-dependent set (files
 * 0x11/6/0xF/0x10 when func_02008550 reports 1, else 0xE/4/0xC/0xD).
 */
void func_021F49F8(Work *p, u32 mode)
{
    void *arc;
    void *buf;
    PlttData *pd;
    int i;
    u16 *d;
    u32 anm;
    u32 cell;
    u32 pal;
    u32 chr;

    arc = func_020490F4(0x60, 0x48);
    CLACT_InitSystem((const struct Cfg *)d_02202BE0, mode, 0x48);
    p->res_res.f0 = (u32)CLACT_CreateUnit(0x60, 0, 0x48);
    p->res_res.f4 = CLACT_RegisterCharacter(arc, 0x11, 1, 0, 0x48);
    p->res_res.f8 = CLACT_RegisterPalette(arc, 8, 0, 0, 0x48);
    p->res_res.fC = CLACT_RegisterCellAnim(arc, 0x12, 0x13, 0x48);
    p->res_res.f28 = CLACT_RegisterCharacter(arc, 0x27, 1, 0, 0x48);
    p->res_res.f30 = CLACT_RegisterCellAnim(arc, 0x28, 0x29, 0x48);
    p->res_res.f10 = CLACT_RegisterCharacter(arc, 0x24, 1, 1, 0x48);
    p->res_res.f14 = CLACT_RegisterPalette(arc, 7, 1, 0, 0x48);
    p->res_res.f18 = CLACT_RegisterCellAnim(arc, 0x25, 0x26, 0x48);
    ARC_TOOL_DeleteHandle(arc);

    buf = func_02049F34(7, 0, (u32)(&pd), 0x48);
    DC_FlushRange(pd->data, 0x60);
    GX_LoadOBJPltt(pd->data, 0xA0, 0x60);
    d = pd->data;
    for (i = 0; i < 0x30; i++) {
        u16 c = d[i];
        d[i] = ((((c >> 10) & 0x1f) / 2) << 10) | ((((c >> 5) & 0x1f) / 2) << 5) | ((c & 0x1f) / 2);
    }
    DC_FlushRange(pd->data, 0x60);
    GX_LoadOBJPltt(pd->data, 0x100, 0x60);
    func_020307B0(buf);

    if ((u8)(u32)func_02008550(p->ctx->f1C) == 1) {
        chr = 0x11;
        anm = 0x10;
        cell = 0xF;
        pal = 6;
    } else {
        chr = 0xE;
        anm = 0xD;
        cell = 0xC;
        pal = 4;
    }
    arc = func_020490F4(0x1f, 0x48);
    p->res_res.f1C = CLACT_RegisterCharacter(arc, chr, 0, 1, 0x48);
    p->res_res.f20 = CLACT_RegisterPaletteEx(arc, pal, 1, 0, 0, 1, 0x48);
    p->res_res.f24 = CLACT_RegisterCellAnim(arc, cell, anm, 0x48);
    ARC_TOOL_DeleteHandle(arc);
}





/*
 * Release the 0x10 channel on both hardware blocks.
 */
void func_021F4BCC(Work *p)
{
    func_020434DC(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}





/*
 * Forward four register arguments plus a zero and the u8 stack argument.
 */
void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_021F4BF8((WorldtradeBoxObj1 *)a, b, c, d, 0, e);
}





void func_021F4BF8(WorldtradeBoxObj1 *p,int b,int unused,int a,int c,u8 flag)
{
    BoxItems2 items;
    BoxMenu_021F4580 menu;
    int on;
    if (*(u32 *)&p->fE04) func_02034714(str_02203B08,0,str_02203B08);
    if (*(u32 *)&p->fE08) func_02034714(str_02203B08,0,str_02203B08);
    p->fE04=APP_TASKMENU_RES_Create((u8)c,(u8)a,p->fFA0,p->fFAC,0x48);
    items=data_02202BC8;
    on=0;
    func_02082BCC(&menu,0,20);
    items.item[0].text=func_02045EC0(p->fB6C,63);
    items.item[1].text=func_02045EC0(p->fB6C,64);
    menu.heap=0x48;
    menu.count=2;
    menu.items=items.item;
    menu.mode=1;
    menu.a=0x20;
    menu.b=b;
    menu.c=8;
    menu.d=3;
    p->fE08=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&menu),p->fE04);
    STRBUF_Delete(items.item[0].text);
    STRBUF_Delete(items.item[1].text);
    if (flag) {
        if(c<=3) on=1;
        func_021F5008(on);
    }
}





void func_021F4CE4(Work *p) { if(p->fE08) { APP_TASKMENU_CloseMenu(p->fE08); p->fE08=0; } if(p->fE04) { APP_TASKMENU_RES_Delete(p->fE04); p->fE04=0; } }





int func_021F4D14(Work *p) { int result; result=0; if(p->fE08) { APP_TASKMENU_UpdateMenu(p->fE08); if(APP_TASKMENU_IsFinish(p->fE08)) { result=APP_TASKMENU_GetCursorPos(p->fE08); if(result==0) result=1; else if(result==1) result=2; func_021F5060(); } } return result; }





void func_021F4D50(WorldtradeBoxObj1 *p, u16 a, int count, int b)
{
    BoxItems3 items;
    BoxMenu_021F4580 menu;
    int i;
    if (*(u32 *)&p->fE04) func_02034714(str_02203B08,0,str_02203B08);
    if (*(u32 *)&p->fE08) func_02034714(str_02203B08,0,str_02203B08);
    p->fE04=APP_TASKMENU_RES_Create(a,10,p->fFA0,p->fFAC,0x48);
    items=data_02202C2C;
    func_02082BCC(&menu,0,20);
    if ((u32)count>3) func_02034714(str_02203B08,0,str_02203B08);
    for(i=0;i<count;i++) items.item[i].a=*(u32 *)(*(u32 *)&p->fDE8+i*8);
    menu.heap=0x48;
    menu.count=count;
    menu.items=items.item;
    menu.mode=1;
    menu.a=0x20;
    menu.b=b;
    menu.c=13;
    menu.d=3;
    p->fE08=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&menu),p->fE04);
    func_021F5008(1);
}





u32 func_021F4E30(Work *p)
{
    u32 r = (u32)-1;

    if (p->fE08 != 0) {
        APP_TASKMENU_UpdateMenu(p->fE08);
        if (APP_TASKMENU_IsFinish(p->fE08) != 0) {
            r = APP_TASKMENU_GetCursorPos(p->fE08) + 1;
            func_021F5060();
        }
    }
    return r;
}





void func_021F4E64(Work *p)
{
    if (p->fE08 != 0) {
        APP_TASKMENU_CloseMenu(p->fE08);
        p->fE08 = 0;
    }
    if (p->fE04 != 0) {
        APP_TASKMENU_RES_Delete(p->fE04);
        p->fE04 = 0;
    }
    func_021F5060();
}





void func_021F4E98(Work *p, u32 a, u32 b)
{
    p->state = a;
    ((struct Obj00018 *)p)->f2C = b;
}





/*
 * Send a one-entry u16 table {b, c}
/*
 * Send a one-entry u16 table {b, c} to func_0204B404.
 */
void func_021F4EA0(u32 a, u16 b, u16 c)
{
    u16 t[2];

    t[0] = b;
    t[1] = c;
    func_0204B404((struct Obj *)a, (const struct Vec2 *)t, 1);
}





int func_021F4EB4(void)
{
    return 3 - DWC_GetLinkLevel();
}





/*
 * Store two words into the object at +0x14 and +0x20.
 */
void func_021F4EC0(Work *p, u32 a, u32 b)
{
    p->x14 = a;
    *(u32 *)&p->kind = b;
}





/*
 * Save the current value at +0x10 into +0x1c and move +0x14 down into +0x10.
 */
void func_021F4EC8(Work *p)
{
    p->f1C_u = p->x10;
    p->x10 = p->x14;
}





int func_021F4ED4(void)
{
    return sub_02012FFC();
}





/*
 * Wire the shared table into the two initialisers and release the channel.
 */
void func_021F4EDC(Work *p)
{
    func_021F4894((const struct DispVram *)g_02202BFC);
    func_021F49F8((Work *)p, (u32)g_02202BFC);
    func_021F4BCC(p);
}





void func_021F4EFC(Work *p)
{
    func_021FFCD4((u8 *)p);
    CLACT_ReleasePalette(p->res_res.f20);
    CLACT_ReleaseCharacter(p->res_res.f1C);
    CLACT_ReleaseCellAnim(p->res_res.f24);
    CLACT_ReleasePalette(p->res_res.f14);
    CLACT_ReleaseCharacter(p->res_res.f10);
    CLACT_ReleaseCellAnim(p->res_res.f18);
    CLACT_ReleasePalette(p->sub.f8);
    CLACT_ReleaseCharacter(p->sub.f4);
    CLACT_ReleaseCellAnim(p->sub.fC);
    CLACT_ReleaseCharacter(p->sub.f28);
    CLACT_ReleaseCellAnim(p->sub.f30);
    CLACT_DeleteUnit((struct Bank *)(p->sub.f0));
    p->sub.f0 = 0;
    CLACT_ExitSystem();
}





/*
 * Decrement the u16 counter at +0x36 when it is non-zero.
 */
void func_021F4F84(Work *p)
{
    u16 v = p->f36;

    if (v != 0) {
        p->f36 = v - 1;
    }
}





/*
 * Set the u16 flag at +0xeb2 and clear the one at +0xeb0.
 */
void func_021F4F90(Work *p)
{
    p->xEB2 = 1;
    p->species = 0;
}





/*
 * blocker resolved: 0x020056BC was matched in arm9 (src/matched/
 * func_020056BC.c, shard pkt_020056BC); the call now attests as `matched`.
 * All 32 bytes are right.
 *
 * Start a frame with the 0x48-byte object held at +0xd40 and keep the result at +0xdf8.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021F4FA4.c --func func_021F4FA4  *       --addr 0x021F4FA4 --region ov135 --thumb --cc dsi/1.1p1 --diff
 */
void func_021F4FA4(Work *p)
{
    p->xDF8 = (u32)TIME_ICON_Create((void *)func_020056BC(), (void *)(p->frame),
                                        0xf, 0x10, 0x48);
}





void func_021F4FC4(Work *p)
{
    if (p->xDF8 != 0) {
        TIME_ICON_Delete((u8 *)(p->xDF8));
        p->xDF8 = 0;
        BMP_WIN_MakeScreen((struct Cfg *)(p->frame));
        func_020409B4(func_02045730((struct Descriptor *)(p->frame)));
    }
}





void func_021F4FF4(u32 a, u32 b, u32 c)
{
    u16 t[2];

    t[0] = b;
    t[1] = c;
    func_0204B404((struct Obj *)a, (const struct Vec2 *)t, 0);
}





/*
 * Pick the 0x04000050 or 0x04001050 hardware register from the flag and write the 0x1e/-7 pair.
 */
void func_021F5008(u32 x)
{
    if (x != 0) {
        func_0207D658(0x04000050, 0x1e, -7);
    } else {
        func_0207D658(0x04001050, 0x1e, -7);
    }
}





/*
 * Pick the 0x04000050 or 0x04001050 hardware register from the flag and write the 0x1b/-7 pair.
 */
void func_021F5034(u32 x)
{
    if (x != 0) {
        func_0207D658(0x04000050, 0x1b, -7);
    } else {
        func_0207D658(0x04001050, 0x1b, -7);
    }
}





/*
 * Clear the two display control registers.
 */
void func_021F5060(void)
{
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
}





void func_021F5074(Work *p)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_02043534(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_021F4EDC(p);
    func_0203F8F4(0x48);
    BMP_WIN_Init(0x48);
    {
        struct DispConfig_021F4580 c = tbl_02202BB8;

        func_0203FC28(&c);
    }
    func_021F49A8();
    *(vu16_021F5074 *)0x04000050 = 0;
    *(vu16_021F5074 *)0x04001050 = 0;
    if (p->vblank_p == 0) {
        p->vblank_p = func_020056A0(func_021F4864, p, 0);
    }
}





void func_021F50EC(Work *p)
{
    if (p->vblank_p != 0) {
        func_02030EAC(p->vblank_p);
        p->vblank_p = 0;
    }
    *(vu16_021F50EC *)0x04000050 = 0;
    *(vu16_021F50EC *)0x04001050 = 0;
    func_021F4EFC(p);
    BMP_WIN_Exit();
    func_0203F9B4();
    *(vu32_021F4D50 *)0x04000000 &= 0xFFFF1FFF;
    *(vu32_021F4D50 *)0x04001000 &= 0xFFFF1FFF;
}





void func_021F513C(WorldtradeBoxObj1 *p)
{
    GAME_DATA_SaveCancel(func_020120F4((const struct Ctx *)(*(u32 *)(p->f0 + 0x40))));
    func_0200F7C0(0x29);
}





/*
 * volatile: hardware halfword 04000304 read at 021F5162 before masked write.
 */
int func_021F5154(Work *p)
{
    func_021F5980(p);
    *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);
    func_021F5250();
    func_021FFFE8((u8 *)p, 0, 0);
    func_021F5374(p);
    func_021F57EC((Work *)p);
    func_021F5420((Work *)p);
    func_021FFD44((char *)p);
    if (func_0207D55C((u16 *)0x0400106c) == 0) {
        WIPE_SYS_Start((void *)3, 1, 1, 0, 6, 1, 0x48);
    } else {
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x48);
    }
    func_021F68A4((Work *)p, p->box);
    func_021F9254((u8 *)p);
    p->state = 0;
    p->f12E4 = 0;
    return 1;
}





/*
 * State-table dispatch through the table at 0x02203B0C.
 */
void func_021F51F0(u8 *p)
{
    g_02203B0C[*(u32 *)(p + 0x28)](p);
}





int func_021F5204(WorldtradeBoxObj1 *p)
{
    if (func_0207D55C((u16 *)0x0400106c)) {
        func_021FFD74((char *)p);
    }
    func_021F577C((Work *)(void *)p);
    func_021F59E8((Work *)p);
    func_021F5940((Work *)(void *)p);
    func_021F5358();
    func_022000E4((char *)p);
    func_0204B3DC((struct Obj *)*(u32 *)&p->fD38, 0);
    func_021F4EC8((Work *)(void *)p);
    return 0;
}





/*
 * Five-layer bring-up: the saved display config, then layers 0, 2 and 3
 * through 020414EC and layers 0 and 3 cleared through 02040B94.
 */
void func_021F5250(void)
{
    struct DispConfig_021F4580 c = g_02202C94;
    u32 v = BG_SYS_GetSubVisiblePlanes();

    func_0203FC28(&c);
    BG_SYS_SetSubVisiblePlanes(v);
    {
        struct BgTemplate_021F4580 t = g_02202CE4;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate_021F4580 t = g_02202D04;
        func_0203FCA0(1, &t, 0);
    }
    func_02040588(1, 1);
    {
        struct BgTemplate_021F4580 t = g_02202CA4;
        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    {
        struct BgTemplate_021F4580 t = g_02202CC4;
        func_0203FCA0(3, &t, 0);
    }
    func_020414EC(3);
    func_02040588(3, 1);
    func_02040B94(0, 0x20, 0, 0x48);
    func_02040B94(3, 0x20, 0, 0x48);
}





/*
 * Poke the channel-selection helper with 2, 1, 0, 3 in turn.
 */
void func_021F5358(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
    sub_020403F4(3);
}





void func_021F5374(Work *p)
{
    void *h;
    h = func_020490F4(0x60, 0x48);
    func_02049B68(h, 1, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0xa, 1, 0, 0xa00, 1, 0x48);
    func_020498F4(h, 0x15, 1, 0, 0x600, 1, 0x48);
    func_020498F4(h, 0x1f, 2, 0, 0x600, 1, 0x48);
    ARC_TOOL_DeleteHandle(h);
    func_02200AB4((u8 *)p);
    func_02200B34((u8 *)p);
}





void func_021F5420(Work *p)
{
    Local s;
    int i;

    func_02082BCC(&s, 0, 8);
    s.a = tbl_02202D24[p->slot].x;
    s.b = tbl_02202D24[p->slot].y;
    p->sub.f34 = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
    func_0204B92C((struct Obj *)p->sub.f34, 1);
    CLACT_SetActorAnimSeq((struct Obj *)p->sub.f34, 4);
    if (func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->sub.f34, 0);
    } else {
        func_0204B3DC((struct Obj *)p->sub.f34, 1);
    }
    if (p->slot == 0x1f || p->slot <= 5) {
        CLACT_SetActorBgPriority(p->sub.f34, 0);
    } else {
        CLACT_SetActorBgPriority(p->sub.f34, 1);
    }

    for (i = 0; i < 30; i++) {
        s.a = tbl_02202D24[i].x;
        s.b = tbl_02202D24[i].y;
        s.d = 30 - i % 6;
        p->sub.arrA[i] = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        CLACT_SetActorAnimSeq((struct Obj *)p->sub.arrA[i], i + 6);
        CLACT_SetActorBgPriority(p->sub.arrA[i], 1);
    }

    for (i = 0; i < 30; i++) {
        s.a = tbl_02202D24[i].x;
        s.b = tbl_02202D24[i].y + 6;
        s.d = 10;
        p->sub.arrB[i] = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        CLACT_SetActorAnimSeq((struct Obj *)p->sub.arrB[i], 0x28);
        CLACT_SetActorBgPriority(p->sub.arrB[i], 1);
    }

    for (i = 0; i < 6; i++) {
        s.a = tbl_02202D24[i].x + 8;
        s.b = tbl_02202D24[i].y + 6;
        s.d = 10;
        p->arrC[i] = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        CLACT_SetActorAnimSeq((struct Obj *)p->arrC[i], 0x2a);
        CLACT_SetActorBgPriority(p->arrC[i], 1);
    }

    for (i = 0; i < 2; i++) {
        s.a = tbl_02202C50[i].x;
        s.b = tbl_02202C50[i].y;
        p->arrows[i] = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        CLACT_SetActorAnimSeq((struct Obj *)p->arrows[i], i + 0x26);
        CLACT_SetActorBgPriority(p->arrows[i], 1);
    }

    s.a = 0xef;
    s.b = 0x88;
    s.d = 100;
    s.e = 1;
    p->sub.f3C = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f28, p->sub.f8, p->sub.f30, &s, 0, 0x48);
    CLACT_SetActorAnimSeq((struct Obj *)p->sub.f3C, 0xc);
    func_0204B92C((struct Obj *)p->sub.f3C, 1);
    CLACT_StopActorAnim((struct Actor *)p->sub.f3C);
    func_0204B3DC((struct Obj *)p->sub.f3C, 0);
    func_0204B3DC((struct Obj *)p->fD38, 1);
    func_021F4EA0(p->fD38, 0x37, 0xa8);
}





void func_021F577C(Work *p)
{
    int i;
    WorldtradeBoxObj10 *q;
    CLACT_DeleteActor((struct Obj *)(p->cursor_u));
    for (i = 0; i < 2; i++) {
        CLACT_DeleteActor((struct Obj *)(*(u32 *)((u8 *)p + 0xd2c + i * 4)));
    }
    CLACT_DeleteActor((struct Obj *)(p->cursor));
    for (i = 0; i < 30; i++) {
        q = (WorldtradeBoxObj10 *) ((u8 *)p + i * 4);
        CLACT_DeleteActor((struct Obj *)(q->fC00));
        CLACT_DeleteActor((struct Obj *)(q->fC78));
    }
    for (i = 0; i < 6; i++) {
        CLACT_DeleteActor((struct Obj *)(*(u32 *)((u8 *)p + 0xcf0 + i * 4)));
    }
}





void func_021F57EC(Work *p)
{
    void *w;

    p->fD4C = (void *)BMP_WIN_Create(3, 4, 0, 0xD, 3, 0xD, 1);
    BMP_Clear(func_02045770(p->fD4C), 0);
    w = p->fD4C;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_020409B4(func_02045730(w));

    p->d40 = (void *)BMP_WIN_Create(0, 2, 0x15, 0x1B, 2, 0xD, 1);
    BMP_Clear(func_02045770(p->d40), 0);
    w = p->d40;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_020409B4(func_02045730(w));

    p->dd0 = (void *)BMP_WIN_Create(0, 2, 0x13, 0x1B, 4, 0xD, 1);
    BMP_Clear(func_02045770(p->dd0), 0);
    w = p->d40;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_020409B4(func_02045730(w));

    p->win3 = (void *)BMP_WIN_Create(1, 0x18, 0x10, 6, 2, 0, 1);
    BMP_Clear(func_02045770(p->win3), 4);
    w = p->win3;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_020409B4(func_02045730(w));

    func_021F91A0(p->win3, p->strs, 0, 1, 1, 0x3DC4, p->fFA0);
    if (p->kind == 5) {
        func_02200BAC((u8 *)p, 3);
    } else {
        func_02200BAC((u8 *)p, 1);
    }
}





void func_021F5940(Work *p)
{
    func_02202940((struct Obj *)((u8 *)p + 0xfa0));
    func_020452E8(p->fDE0);
    func_020452E8(p->dd0);
    func_020452E8(p->win3);
    func_020452E8(p->d40);
    func_020452E8(p->fD4C);
}





void func_021F5980(Work *p)
{
    func_021F6E08((Work *)p);
    p->fB80 = STRBUF_Create(0x12, 0x48);
    p->str = STRBUF_Create(0xb4, 0x48);
    p->strs = func_02045EC0(p->bank, 0x73);
    if (p->slot == 0x1e) {
        p->slot = 0;
    }
    (*(void **)&p->info_p) = func_02030734(0x48, 0x78, 0, str_02203B54, 0x344);
}





void func_021F59E8(Work *p) { func_020307B0((void *)p->info_p); STRBUF_Delete(p->fB80); STRBUF_Delete(p->str); STRBUF_Delete(p->strs); }





/*
 * precondition: entry mode at offset 0x20 must be 5 or 6; original
 *   leaves r4 unchanged for other modes at 021F5A32..021F5A38.
 */
int func_021F5A18(Work *p)
{
    int index;
    if (WIPE_SYS_EndCheck()) {
        if (p->kind == 5) {
            index = 0x15;
        } else if (p->kind == 6) {
            index = 0x11;
        }
        func_021F663C(p, index, 1, 0, 0xf0f, 0);
        func_021F4E98(p, 3, 1);
        if (func_020355C4() == 1) {
            func_0204B3DC((struct Obj *)p->cursor, 0);
        } else {
            func_0204B3DC((struct Obj *)p->cursor, 1);
        }
    }
    return 2;
}





void func_021F5A7C(Work *p)
{
    if (p->slot == 0x1E) {
        func_0204B3DC((struct Obj *)p->cursor_u, 1);
        CLACT_RestartActorAnim((struct Actor *)p->cursor_u);
        p->state = 0x11;
        func_020061E4(0x551);
        return;
    }
    if (p->slot == 0x1F) {
        return;
    }
    switch (func_021F6C48(p->ctx->party, p->ctx->save, p->box, p->slot)) {
    case 1:
        func_020061E4(0x54C);
        if (func_021F6BA4(p->ctx->party, p->ctx->save, p->box, p->slot) != 0) {
            func_022025E4((u32)p->words, 0, (u32)func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot));
            func_021F663C(p, 0x16, 1, 0, 0xF0F, 0);
            func_021F4E98(p, 3, 7);
        } else {
            func_021F663C(p, 0x1A, 1, 0, 0xF0F, 1);
            func_021F4E98(p, 4, 1);
        }
        break;
    case 2:
        func_020061E4(0x54C);
        func_021F663C(p, 0x21, 1, 0, 0xF0F, 1);
        func_021F4E98(p, 4, 1);
        break;
    }
}





void func_021F5B8C(Work *p)
{
    void *mon;

    if (p->slot == 0x1E) {
        func_0204B3DC((struct Obj *)p->cursor_u, 1);
        CLACT_RestartActorAnim((struct Actor *)p->cursor_u);
        p->state = 0x11;
        return;
    }
    if (p->slot == 0x1F) {
        return;
    }
    switch (func_021F6C48(p->ctx->party, p->ctx->save, p->box, p->slot)) {
    case 1:
        mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (func_021F6CDC(mon, (WorldtradeBoxObj7 *)(p->arr_entry1[p->cur].key)) != 0) {
            if (func_021F6BA4(p->ctx->party, p->ctx->save, p->box, p->slot) != 0) {
                func_022025E4((u32)p->words, 0, (u32)mon);
                func_021F663C(p, 0x12, 1, 0, 0xF0F, 0);
                func_021F4E98(p, 3, 9);
                func_020061E4(0x54C);
            } else {
                func_021F663C(p, 0x1A, 1, 0, 0xF0F, 1);
                func_021F4E98(p, 4, 1);
            }
        } else {
            func_020061E4(0x551);
        }
        break;
    case 0:
    case 2:
        func_020061E4(0x551);
        break;
    }
}





int func_021F5CA4(Work *p)
{
    int r = TOUCHPANEL_HitTrg(tbl_02202E24);

    if (r != -1) {
        func_0204B3DC((struct Obj *)p->cursor, 0);
        func_020355D8(1);
    }
    return r;
}





/*
 * Two-way mode dispatch on the second argument, each arm latching state 2.
 */
void func_021F5CD4(Work *p, u32 k)
{
    if (k == 5) {
        func_021F4EC0(p, 1, 0);
        p->state = 2;
    } else if (k == 6) {
        func_021F4EC0(p, 3, 0x11);
        p->state = 2;
    }
}





int func_021F5CFC(Work *p)
{
    int r = func_021F5CA4((Work *)p);

    if (r != -1) {
        switch (r) {
        case 0x1F:
            func_0204B92C((struct Obj *)p->arrows[0], 1);
            CLACT_SetActorAnimSeq((struct Obj *)p->arrows[0], 0x26);
            p->box = func_021F5F9C(p->box, p->boxes, 1);
            func_021F68A4(p, p->box);
            func_020061E4(0x548);
            break;
        case 0x20:
            func_0204B92C((struct Obj *)p->arrows[1], 1);
            CLACT_SetActorAnimSeq((struct Obj *)p->arrows[1], 0x27);
            p->box = func_021F5F9C(p->box, p->boxes, -1);
            func_021F68A4(p, p->box);
            func_020061E4(0x548);
            break;
        case 0x1E:
            func_0204B3DC((struct Obj *)p->cursor_u, 1);
            CLACT_RestartActorAnim((struct Actor *)p->cursor_u);
            p->state = 0x11;
            p->slot = r;
            func_020061E4(0x551);
            func_021F5F60(p->cursor, p->slot);
            break;
        default:
            p->slot = r;
            func_021F5F60(p->cursor, p->slot);
            if (p->kind == 5) {
                func_021F5A7C((Work *)p);
            } else if (p->kind == 6) {
                func_021F5B8C((Work *)p);
            }
            break;
        }
    } else {
        func_021F5E44((Work *)((Work *)p));
        if (p->kind == 5) {
            if (func_020362DC() & 2) {
                func_0204B3DC((struct Obj *)p->cursor_u, 1);
                CLACT_RestartActorAnim((struct Actor *)p->cursor_u);
                p->state = 0x11;
                func_020061E4(0x551);
            } else if (func_020362DC() & 1) {
                func_021F5A7C((Work *)p);
            }
        } else if (p->kind == 6) {
            if (func_020362DC() & 2) {
                func_0204B3DC((struct Obj *)p->cursor_u, 1);
                CLACT_RestartActorAnim((struct Actor *)p->cursor_u);
                p->state = 0x11;
                func_020061E4(0x551);
            } else if (func_020362DC() & 1) {
                func_021F5B8C((Work *)p);
            }
        }
    }
    return 2;
}





void func_021F5E44(Work *p)
{
    int moved = 0;
    int dir = 0;
    u8 k;

    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_020355D8(moved);
        func_020061E4(0x548);
        return;
    }
    if (func_020362DC() & 0x40) {
        dir = 1;
    } else if (func_020362DC() & 0x80) {
        dir = 2;
    } else if (func_020362DC() & 0x20) {
        dir = 3;
    } else if (func_020362DC() & 0x10) {
        dir = 4;
    }
    if (dir != 0) {
        dir = tbl_02202DA4[p->slot][dir - 1];
        if (dir != p->slot) {
            if (dir == 0x63 || dir == 0x65) {
                k = dir == 0x65 ? 0 : 1;
                func_0204B92C((struct Obj *)p->arrows[k], 1);
                CLACT_SetActorAnimSeq((struct Obj *)p->arrows[k], k + 0x26);
                p->box = func_021F5F9C(p->box, p->boxes, dir - 0x64);
                func_021F68A4((Work *)p, p->box);
                func_020061E4(0x548);
            } else {
                moved = 1;
                p->slot = dir;
            }
        }
    }
    if (moved) {
        func_020061E4(0x548);
    }
    func_021F5F60(p->cursor, p->slot);
}





void func_021F5F60(u32 cursor, int i)
{
    func_021F4FF4(cursor, tbl_02202D24[i].x, tbl_02202D24[i].y);
    if (i == 0x1F || (i >= 0 && i <= 5)) {
        CLACT_SetActorBgPriority(cursor, 0);
    } else {
        CLACT_SetActorBgPriority(cursor, 1);
    }
}





/*
 * Byte-index arithmetic with 0xff as the out-of-range marker.
 */
int func_021F5F9C(int a, int b, int c)
{
    if (a == 0xff) {
        if (c > 0) {
            return 0;
        }
        if (c < 0) {
            return b - 1;
        }
        return a;
    }
    a += c;
    if (a < 0) {
        return 0xff;
    }
    if (a == b) {
        return 0xff;
    }
    return a;
}





/*
 * Create the resource, register the three 68/69/6a entries and latch state 0x8.
 */
int func_021F5FC0(WorldtradeBoxObj1 *p)
{
    *(u32 *)&p->fDE8 = (u32)BMP_MENUWORK_Create(3, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&p->fDE8), *(u32 *)&p->fB6C, 0x68, 1, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&p->fDE8), *(u32 *)&p->fB6C, 0x69, 2, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&p->fDE8), *(u32 *)&p->fB6C, 0x6a, 3, 0x48);
    func_021F4D50(p, 0, 3, 0x14);
    p->f28 = 0x8;
    return 2;
}





int func_021F601C(Work *p)
{
    void *mon;

    switch (func_021F4E30(p)) {
    case 1:
        func_021F4E64(p);
        BMP_MENUWORK_Delete(p->de8);
        func_0201F7A8(p->d40, 0);
        p->state = 2;
        func_021F4EC0(p, 8, 5);
        break;
    case 2:
        func_021F4E64(p);
        BMP_MENUWORK_Delete(p->de8);
        mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (func_021F6BC4(mon) != 0) {
            func_021F663C(p, 0x2B, 1, 0, 0xF0F, 1);
            func_021F4E98(p, 4, 1);
        } else if (func_021F6BFC((u32)mon) != 0) {
            if (func_021F6BFC((u32)mon) == 1) {
                func_021F663C(p, 0xBF, 1, 0, 0xF0F, 1);
            } else {
                func_021F663C(p, 0xC0, 1, 0, 0xF0F, 1);
            }
            func_021F4E98(p, 4, 1);
        } else if (func_021F6C28((u32)mon) != 0) {
            func_021F663C(p, 0xC1, 1, 0, 0xF0F, 1);
            func_021F4E98(p, 4, 1);
        } else {
            if (func_021F6B34(p->box) != 0) {
                func_0201AB28(p->ctx->party, p->slot);
            }
            p->mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
            p->state = 2;
            func_021F4EC0(p, 6, 0);
        }
        break;
    case 3:
    case (u32)-2:
        func_021F4E64(p);
        BMP_MENUWORK_Delete(p->de8);
        func_0201F7A8(p->d40, 0);
        p->state = 0;
        break;
    }
    return 2;
}





/*
 * Create the resource, register the three 5d/5e/5f entries and latch state 0xa.
 */
int func_021F6178(WorldtradeBoxObj1 *p)
{
    *(u32 *)&p->fDE8 = (u32)BMP_MENUWORK_Create(3, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&p->fDE8), *(u32 *)&p->fB6C, 0x5d, 1, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&p->fDE8), *(u32 *)&p->fB6C, 0x5e, 2, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&p->fDE8), *(u32 *)&p->fB6C, 0x5f, 3, 0x48);
    func_021F4D50(p, 0, 3, 0x14);
    p->f28 = 0xa;
    return 2;
}





int func_021F61D4(Work *p)
{
    void *mon;

    switch (func_021F4E30(p)) {
    case 1:
        func_021F4E64(p);
        BMP_MENUWORK_Delete(p->de8);
        p->state = 2;
        func_021F4EC0(p, 8, 6);
        break;
    case 2:
        func_021F4E64(p);
        BMP_MENUWORK_Delete(p->de8);
        func_0201F7A8(p->d40, 0);
        mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (func_021F6BC4(mon) != 0) {
            func_021F663C(p, 0x2B, 1, 0, 0xF0F, 1);
            func_021F4E98(p, 4, 1);
        } else if (func_021F6BFC((u32)mon) != 0) {
            if (func_021F6BFC((u32)mon) == 1) {
                func_021F663C(p, 0xBF, 1, 0, 0xF0F, 1);
            } else {
                func_021F663C(p, 0xC0, 1, 0, 0xF0F, 1);
            }
            func_021F4E98(p, 4, 1);
        } else if (func_021F6C28((u32)mon) != 0) {
            func_021F663C(p, 0xC1, 1, 0, 0xF0F, 1);
            func_021F4E98(p, 4, 1);
        } else {
            if (func_021F6B34(p->box) != 0) {
                func_0201AB28(p->ctx->party, p->slot);
            }
            if (func_02017E88(mon, 5, 0) == 0x1EC) {
                POKE_TOOL_ChangeBoxForm((int)mon, 0);
            }
            func_021F6474((Work *)((Work *)p));
        }
        break;
    case 3:
    case (u32)-2:
        func_021F4E64(p);
        BMP_MENUWORK_Delete(p->de8);
        func_0201F7A8(p->d40, 0);
        p->state = 0;
        break;
    }
    return 2;
}





int func_021F632C(WorldtradeBoxObj4 *p)
{
    if (p->f14 == 0 || p->f14 == 8 || p->f14 == 3) {
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
        p->fEB4 = 1;
    } else {
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    p->f28 = 0;
    return 3;
}





/*
 * State setter: build with the fixed 0x14/0x1ad/0x8/0x1 argument pair and latch state 0x6.
 */
int func_021F6384(Work *p)
{
    func_021F4BE0((u32)p, 0x14, 0x1ad, 0x8, 0x1);
    p->state = 0x6;
    return 2;
}





int func_021F63A8(Work *p)
{
    unsigned result = func_021F4D14(p);
    func_02034714(d_02203B68, 0, d_02203B68);
    if (result == 1) {
        func_021F4CE4(p);
        p->state = 2;
        func_021F4EC0(p, 0, 0);
    } else if (result == 2) {
        func_021F4CE4(p);
        p->state = 0;
    }
    return 2;
}





/*
 * Build through func_021F663C and publish the 3/0xc pair.
 */
int func_021F63EC(Work *p)
{
    func_021F663C(p, 0x19, 1, 0, 0xf0f, 1);
    func_021F4E98(p, 3, 0xc);
    return 2;
}





/*
 * State setter: build with the fixed 0x12/0x1ad/0x8/0x1 argument pair and latch state 0xd.
 */
int func_021F6418(Work *p)
{
    func_021F4BE0((u32)p, 0x12, 0x1ad, 0x8, 0x1);
    p->state = 0xd;
    return 2;
}





/*
 * Two-way mode dispatch: mode 1 clears and runs the sub-step, mode 2 clears, releases the +0xdd0 word and latches state 1.
 */
int func_021F643C(Work *p)
{
    u32 k = func_021F4D14(p);

    if (k == 1) {
        func_021F4CE4(p);
        func_021F6474((Work *)((Work *)p));
    } else if (k == 2) {
        func_021F4CE4(p);
        func_0201F7A8((void *)(*(u32 *)&p->dd0), 0);
        p->state = 1;
    }
    return 2;
}





int func_021F6474(Work *p)
{
    if (func_021F6DE8((u32)p->list[p->cur]) != 0 && p->box != 0xFF
        && func_0201AA18(p->ctx->party) == 6) {
        func_021F663C(p, 0x29, 1, 0, 0xF0F, 1);
        func_021F4E98(p, 4, 1);
        return 0;
    }
    p->mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
    p->state = 2;
    p->eb4 = 1;
    func_021F4EC0(p, 7, 9);
    func_021F6D14((Deposit *)p->ent, p);
    p->d0 = 0;
    return 1;
}





int func_021F651C(Work *p)
{
    func_021F663C(p, 0x19, 1, 0, 0xf0f, 1);
    func_021F4E98(p, 3, 0xf);
    return 2;
}





/*
 * State setter: build with the fixed 0x12/0x1ad/0x8/0x1 argument pair and latch state 0x10.
 */
int func_021F6548(Work *p)
{
    func_021F4BE0((u32)p, 0x12, 0x1ad, 0x8, 0x1);
    p->state = 0x10;
    return 2;
}





int func_021F656C(Work *p)
{
    unsigned result = func_021F4D14(p);
    if (result == 1) {
        func_021F4CE4(p);
        p->mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        p->state_un = 2;
        func_021F4EC0(p, 6, 0);
    } else if (result == 2) {
        func_021F4CE4(p);
        func_0201F7A8(p->dd0, 0);
        p->state_un = 1;
    }
    return 2;
}





/*
 * While the +0xbfc buffer is free, feed the mode word at +0x20 to the dispatch.
 */
int func_021F65C8(WorldtradeBoxObj1 *p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(p->fBFC)) == 0) {
        func_021F5CD4((Work *)(void *)p, p->f20);
    }
    return 2;
}





/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int func_021F65E8(Work *p)
{
    if (func_02202840((u8 *)p + 0xfa0) == 0) {
        p->state = ((struct Obj12197 *)p)->f2C;
    }
    return 2;
}





/*
 * When the build query answers 0 and either probe is set, release the +0xdd0 word and roll the state.
 */
int func_021F6604(Work *p)
{
    if (func_02202840((u8 *)p + 0xfa0) == 0) {
        if (func_020362DC() != 0 || TOUCHPANEL_GetTrg() != 0) {
            func_0201F7A8((void *)((*(unsigned int *)&p->dd0)), 0);
            p->state = ((struct Obj09227 *)p)->f2C;
        }
    }
    return 2;
}





/*
 * Window teardown: the handle is the 0xd40 or 0xdd0 window selected by the
 * sixth argument, and that one handle is used by every call in the body.
 */
void func_021F663C(Work *p, u32 b, u32 c, u32 d, u32 e, u32 sel)
{
    u32 v = (u32)MSGDATA_AllocString((struct MsgBank *)(*(u32 *)&p->bank), b);
    u32 h;

    func_0201F250((struct WordSet *)(*(u32 *)&p->words), (void *)((*(unsigned int *)&p->str)), (void *)v);
    h = *(u32 *)((u8 *)p + (sel == 0 ? 0xd40 : 0xdd0));
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)h)), 0xf);
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    sub_020409B4(unit_02045730(h));
    func_0201F73C((void *)h, 0, 1, 0xe);
    func_02202858((void *)h, 0, (void *)((*(unsigned int *)&p->str)), 0, 0, (u8 *)p + 0xfa0);
    STRBUF_Delete((struct U16Vec *)v);
}





u32 func_021F66C8(u32 a, u32 b, u32 c, u32 d)
{
    u32 blk = (u32)ARC_TOOL_LoadHandleMember((struct ArcFile *)a, b, (u16)d);

    if (blk != 0 && func_02062A4C((struct NitroFileHeader *)blk, (void **)c) == 0) {
        func_020307B0((void *)blk);
        return 0;
    }
    return blk;
}





/*
 * Load the icon graphics of a Pokemon (species, form, gender/half, egg)
 * from the archive handle and copy its 0x200 bytes into the sprite
 * record: +0 gets the VRAM offset of slot `slot`, +4 the icon palette
 * (func_0201BB5C + 5), +8 `pal`, the pixels go to +0xC.
 */
void func_021F66F0(u32 species, u32 form, u32 gender, u32 isEgg, u32 slot, u32 f8, u32 arc, IconRec *rec)
{
    CharData_p02 *cd;
    void *buf = (void *)func_021F66C8(arc, POKE_TOOL_CalcGraphicIndex(species, form, gender, isEgg), (u32)(&cd), 0x48);

    func_02082B0C(cd->pixels, rec->pixels, 0x200);
    rec->vram = (slot * 16 + 0x1c) * 32;
    rec->spr = f8;
    rec->pal = func_0201BB5C(species, form, gender, isEgg) + 5;
    func_020307B0(buf);
}





/*
 * Store the query byte at +3 of the second argument.
 */
void func_021F6748(u32 a, u8 *q)
{
    q[3] = POKE_TOOL_CalcBoxLevel((void *)a);
}





/*
 * Deferred icon upload (installed at +0xEBC by func_021F68A4): for each
 * of the 30 icon records at +0xEB8 that has a sprite (+8), flush and
 * load its 0x200 pixel bytes to its OBJ VRAM offset and set the sprite's
 * palette; then free the record block.
 */
void func_021F6754(Work *p)
{
    int i;
    IconRec *e;

    e = p->icons;
    for (i = 0; i < 30; i++, e++) {
        if (e->spr != 0) {
            DC_FlushRange(e->pixels, 0x200);
            GX_LoadOBJ(e->pixels, e->vram, 0x200);
            func_0204B6F4((struct Obj *)e->spr, (u8)e->pal, 1);
        }
    }
    func_020307B0(p->icons);
}





/*
 * Read one Pokemon's display parameters (presence 0xA9, species 5, form
 * 0x6F, egg 0x4C, held item 6, parameter 0x6E + 1) into the info record,
 * clearing its +3 byte for an egg. A present Pokemon gets its icon loaded
 * (func_021F66F0) and shown; the item sprite is shown with animation 0x29
 * or 0x28 by func_0202136C, or hidden when there is no item. An empty
 * slot hides both sprites and clears the icon record's +8 word.
 */
void func_021F67A8(void *mon, u32 icon, u32 item_spr, u16 *species, u32 slot, void *arc, Info *info, IconRec *rec)
{
    u32 present;
    u32 item;
    u32 egg;
    u32 form;

    func_02017DBC(mon);
    present = func_02017E88(mon, 0xa9, 0);
    *species = func_02017E88(mon, 5, 0);
    form = func_02017E88(mon, 0x6f, 0);
    egg = func_02017E88(mon, 0x4c, 0);
    item = func_02017E88(mon, 6, 0);
    info->species = *species;
    info->f2 = func_02017E88(mon, 0x6e, 0) + 1;
    if (egg != 0) {
        info->f3 = 0;
    }
    func_02017DE4(mon, 1);
    if (present != 0) {
        func_021F66F0(*species, form, info->f2 - 1, egg, slot, icon, (u32)arc, (IconRec *)rec);
        func_0204B3DC((struct Obj *)icon, 1);
        if (item != 0) {
            func_0204B3DC((struct Obj *)item_spr, 1);
            if (func_0202136C(item) != 0) {
                CLACT_SetActorAnimSeq((struct Obj *)item_spr, 0x29);
            } else {
                CLACT_SetActorAnimSeq((struct Obj *)item_spr, 0x28);
            }
        } else {
            func_0204B3DC((struct Obj *)item_spr, 0);
        }
    } else {
        func_0204B3DC((struct Obj *)icon, 0);
        func_0204B3DC((struct Obj *)item_spr, 0);
        rec->spr = 0;
    }
}




/*
 * Build the 30 Pokemon icon slots of the screen from box `box` of the
 * storage (+0xC of the context) or, for box 0xFF, from the party (+8),
 * blanking the slots past the party size. Icon records (0x3D68 bytes,
 * +0xEB8) are uploaded later by func_021F6754, installed at +0xEBC.
 * Any other box reports through func_02034714 (raw 0x02203B68). Kind 6
 * then runs func_021F6DB4 against the current entry's key.
 */
void func_021F68A4(Work *p, int box)
{
    void *storage = p->ctx->save;
    u16 species[30];
    void *arc;
    IconRec *icons;
    u16 i;

    icons = func_02030734(0x8001, 0x3D68, 0, str_02203B54, 0x892);
    p->icons = icons;
    arc = func_020490F4(7, 0x48);
    if (box >= 0 && box < p->nbox) {
        for (i = 0; i < 30; i++) {
            func_021F6748((u32)func_02007A18(storage, box, i), (u8 *)(&p->info_p[i]));
        }
        for (i = 0; i < 30; i++) {
            p->info_p[i].species = 0;
            func_021F67A8(func_02007A18(storage, box, i), p->icon[i], p->item[i], &species[i], i, arc, (Info *)(&p->info_p[i]), &icons[i]);
            if (i < 6) {
                func_0204B3DC((struct Obj *)p->arrC[i], 0);
            }
        }
        func_0200785C(storage, box, p->fB80);
    } else if (box == 0xff) {
        int n = func_0201AA18(p->ctx->party);

        for (i = 0; i < n; i++) {
            void *mon = POKE_TOOL_GetBoxParam(func_0201AB28(p->ctx->party, i));

            func_021F6748((u32)mon, (u8 *)(&p->info_p[i]));
            func_021F67A8(mon, p->icon[i], p->item[i], &species[i], i, arc, (Info *)(&p->info_p[i]), &icons[i]);
            func_0204B3DC((struct Obj *)p->arrC[i], 0);
        }
        for (; i < 30; i++) {
            p->info_p[i].species = 0;
            func_0204B3DC((struct Obj *)p->icon[i], 0);
            func_0204B3DC((struct Obj *)p->item[i], 0);
            icons[i].spr = 0;
            if (i < 6) {
                func_0204B3DC((struct Obj *)p->arrC[i], 0);
            }
        }
        func_02045CAC(p->bank, 0x62, p->fB80);
    } else {
        func_02034714((void *)0x02203B68, 0, (void *)0x02203B68);
    }
    ARC_TOOL_DeleteHandle(arc);
    BMP_Clear(func_02045770(p->fD4C), 0);
    func_021F91A0(p->fD4C, p->fB80, 0, 5, 1, 0x440, p->fFA0);
    if (p->kind == 6) {
        func_021F6DB4((Rec_p03 *)p->info_p, (u32)p->icon, (WorldtradeBoxObj7 *)(p->arr[p->cur].key), (Entry_021F6DB4 *)icons);
    }
    p->vblank_fn = func_021F6754;
}




/*
 * True only for the 0xff sentinel.
 */
int func_021F6B34(int v)
{
    if (v == 0xff) {
        return 1;
    }
    return 0;
}




void *func_021F6B40(void *party, void *save, int box, int slot)
{
    if (func_021F6B34(box) != 0) {
        if (slot > (int)func_0201AA18(party) - 1) {
            return 0;
        }
        return POKE_TOOL_GetBoxParam(func_0201AB28(party, slot));
    }
    return func_02007A18(save, box, slot);
}




u32 func_021F6B80(u8 *p, u32 b, u32 c)
{
    if (func_021F6B34(c) != 0) {
        return func_0201AA18(p);
    }
    return func_020078C4((void *)b, c);
}




int func_021F6BA4(void *party, void *save, int box, int slot)
{
    if (func_021F6B34(box) != 0 && (int)func_0201AA18(party) < 2) {
        return 0;
    }
    return 1;
}




u32 func_021F6BC4(void *sav)
{
    u32 f = func_02017DBC(sav);
    u32 i;
    u32 r;

    for (i = 0; i < 15; i++) {
        r = func_02017E88(sav, tbl_02202C58[i], 0);
        if (r == 1) {
            break;
        }
    }
    func_02017DE4(sav, f);
    return r;
}




/*
 * Restart the channel: stamp, force ports 5 and 0x6f to zero, hand the stamp over.
 */
int func_021F6BFC(u32 handle)
{
    u32 stamp = func_02017DBC((struct Sav *)handle);

    func_02017E88((void *)handle, 5, 0);
    func_02017E88((void *)handle, 0x6f, 0);
    func_02017DE4((struct Sav *)handle, stamp);
    return 0;
}




/*
 * Restart the channel: take a stamp, force port 6 to zero and hand the handle over.
 */
int func_021F6C28(u32 handle)
{
    u32 stamp = func_02017DBC((struct Sav *)handle);

    func_02017E88((void *)handle, 6, 0);
    func_02017DE4((struct Sav *)handle, stamp);
    return 0;
}




int func_021F6C48(void *party, void *save, int box, int slot)
{
    void *mon = func_021F6B40(party, save, box, slot);

    if (mon == 0) {
        return 0;
    }
    if (func_02017E88(mon, 0xA9, 0) == 0) {
        return 0;
    }
    if (func_02017E88(mon, 0xAA, 0) != 0) {
        return 2;
    }
    return 1;
}




int func_021F6C80(WorldtradeBoxObj9 *pa, WorldtradeBoxObj7 *pb)
{
    signed char a3;
    signed char b3;
    signed char b4;
    signed char b2;

    if (pa->f0 != pb->f0)
        return 0;
    b2 = pb->f2;
    if (b2 != 3 && b2 != pa->f2)
        return 0;
    a3 = pa->f3;
    if (a3 == 0)
        return 0;
    b3 = pb->f3;
    if (b3 != 0 && b3 > a3)
        return 0;
    b4 = pb->f4;
    if (b4 != 0 && b4 < a3)
        return 0;
    return 1;
}




int func_021F6CDC(void *mon, WorldtradeBoxObj7 *want)
{
    MonTag t;

    t.species = func_02017E88(mon, 5, 0);
    t.form = func_02017E88(mon, 0x6E, 0) + 1;
    t.gender = POKE_TOOL_CalcBoxLevel(mon);
    return func_021F6C80((WorldtradeBoxObj9 *)(&t), want);
}




void func_021F6D14(Deposit *dst, Work *p)
{
    MonTag m;
    WantTag w;
    void *e;

    m.species = func_02017E88(p->mon, 5, 0);
    m.form = func_02017E88(p->mon, 0x6E, 0) + 1;
    m.gender = POKE_TOOL_CalcBoxLevel(p->mon);
    dst->have = m;
    func_021F8554((WorldtradeBoxObj5 *)dst, p);
    e = POKE_TOOL_GetBoxParam(p->list[p->cur]);
    w.species = func_02017E88(e, 5, 0);
    w.form = func_02017E88(e, 0x6E, 0) + 1;
    w.b3 = 0;
    w.b4 = 0;
    dst->want = w;
}




void func_021F6DB4(Rec_p03 *recs, u32 unused, WorldtradeBoxObj7 *key, Entry_021F6DB4 *ent)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (recs[i].a != 0 && func_021F6C80((WorldtradeBoxObj9 *)(&recs[i]), key) == 0) {
            ent[i].f4 += 3;
        }
    }
}




/*
 * Read port 6 and report whether the follow-up check accepted it.
 */
int func_021F6DE8(u32 handle)
{
    int ok = 0;
    u16 v = (u16)func_02017E1C((void *)handle, 6, 0);

    if (func_0202136C(v) != 0) {
        ok = 1;
    }
    return ok;
}




void func_021F6E08(Work *p)
{
    unsigned i;
    p->count = func_020076A4(p->ctx->save);
    if (p->count < 24) {
        for (i = 0; i < p->count; i++) {
            if (func_020078C4(p->ctx->save, i) == 0) break;
        }
        if (i == p->count) p->count = func_020076B4(p->ctx->save);
    }
}




int func_021F6E58(Work *p)
{
    Req *d;
    void *tmpl;

    func_021F50EC(p);
    p->req = func_02030734(0x48, 0x44, 0, str_02203B6C, 0x5E);
    func_02082BCC(p->req, 0, 0x44);
    d = p->req;
    p->fEA4 = func_02202608(0x48);
    d->f30 = func_020120F4(p->ctx->f40);
    d->f3C = p->ctx->f1C_u;
    switch (p->kind) {
    case 7:
        d->f38 = d->f34 = func_0200ADB4(p->ctx->sys);
        d->f40 = p->info = (void *)func_021F72C4((Entry_021F72C4 *)p->ent);
        tmpl = d_021E75FC;
        break;
    case 8:
        if (p->f207 != 0) {
            d->f38 = p->ent;
        } else {
            d->f38 = func_0200ADB4(p->ctx->sys);
        }
        d->f34 = d->f38;
        d->f40 = p->info = (void *)func_021F72C4((Entry_021F72C4 *)p->ent);
        tmpl = d_021E75B4;
        break;
    case 10:
        if (p->f207 != 0) {
            d->f38 = p->ent;
        } else {
            d->f38 = func_0200ADB4(p->ctx->sys);
        }
        func_0200AD9C(p->ctx->sys, p->fEA4);
        d->f34 = p->fEA4;
        d->f40 = p->info = (void *)func_021F72C4((Entry_021F72C4 *)p->ent);
        tmpl = d_021E75CC;
        break;
    case 9:
        func_02019CE0(p->fEA8, p->fEA4);
        d->f34 = p->fEA8;
        d->f38 = &p->arr[p->cur];
        d->f40 = p->info = (void *)func_021F72C4((Entry_021F72C4 *)(&p->arr[p->cur]));
        tmpl = d_021E75CC;
        break;
    default:
        func_02034714((void *)0x02203B80, 0, (void *)0x02203B80);
        break;
    }
    PROCSYS_Push(p->f12F0, (u32)ov119_id, tmpl, p->req);
    p->fB8 = 1;
    p->f12E4 = 0;
    return 1;
}




/*
 * Two-state step. State 0, once the +0x12F4 busy word clears: for kind 9
 * (or kinds 8/10 when the stored entry differs from the one rebuilt from
 * the save data by func_02202608/func_0200AD9C) build a 0x14-byte request
 * (SHINKA_CHECK_CheckEvolution result, list holding the entry, out byte) at +0x10DC,
 * load overlay 67 and start the overlay-195 task (d_02208C40, hinted to
 * ov195 because this function names ov195_id), then go to state 1; any
 * failure calls func_021F4EC0(p, 1, 0) and returns 3. State 1 copies the
 * result back into the entry, frees the request, refreshes the record
 * (func_021F7374), clears the DISPCNT window bits, unloads overlay 67 and
 * calls func_021F4EC0(p, 7, 0xC). Returns 2 while waiting, else 3.
 */
int func_021F6FD4(Work *p)
{
    int ret = 2;

    switch (p->state_i) {
    case 0:
        if (p->busy_u != 0) {
            break;
        }
        if (p->kind == 9) {
            void *e = (void *)func_021F7338((Work *)p, p->kind);
            u32 out;
            u32 r;

            func_02017E1C(e, 6, 0);
            r = SHINKA_CHECK_CheckEvolution(0, e, 1, (u32)p->fEA4, func_02012984(func_020120F4((const struct Ctx *)p->ctx->f40)), &out, 0x48);
            if (r != 0) {
                Req *w;

                if (p->req != 0) {
                    func_020307B0(p->req);
                    p->req = 0;
                }
                p->req = func_02030734(0x48, 0x14, 0, str_02203B6C, 0xEB);
                func_02082BCC(p->req, 0, 0x14);
                w = p->req;
                w->f0 = func_020120F4((const struct Ctx *)p->ctx->f40);
                w->list = func_0201A920(0x48);
                func_0201A98C(w->list, (const struct PartyMon *)e);
                w->f8 = r;
                w->fA = 0;
                w->fB = out;
                w->fC = 1;
                w->f10 = 0;
                func_02034A5C((u32)ov067_id);
                PROCSYS_Push(p->f12F0, (u32)ov195_id, d_02208C40, p->req);
                p->state_i = 1;
            } else {
                func_021F4EC0(p, 1, 0);
                ret = 3;
            }
        } else if (p->kind == 8 || p->kind == 10) {
            void *e = (void *)func_021F7338((Work *)p, p->kind);
            void *mon = func_02202608(0x48);
            u32 out;
            u32 r;

            func_0200AD9C(p->ctx->sys, mon);
            if (func_02017E1C(e, 5, 0) != func_02017E1C(mon, 5, 0)
                || func_02017E1C(e, 0, 0) != func_02017E1C(mon, 0, 0)) {
                func_02017E1C(e, 6, 0);
                r = 0;
                if (p->f12F8 != 0) {
                    p->f12F8 = 0;
                    r = SHINKA_CHECK_CheckEvolution(0, e, 1, (u32)mon, func_02012984(func_020120F4((const struct Ctx *)p->ctx->f40)), &out, 0x48);
                }
                if (r != 0) {
                    Req *w;

                    if (p->req != 0) {
                        func_020307B0(p->req);
                        p->req = 0;
                    }
                    p->req = func_02030734(0x48, 0x14, 0, str_02203B6C, 0x130);
                    func_02082BCC(p->req, 0, 0x14);
                    w = p->req;
                    w->f0 = func_020120F4((const struct Ctx *)p->ctx->f40);
                    w->list = func_0201A920(0x48);
                    func_0201A98C(w->list, (const struct PartyMon *)e);
                    w->f8 = r;
                    w->fA = 0;
                    w->fB = out;
                    w->fC = 1;
                    w->f10 = 0;
                    func_02034A5C((u32)ov067_id);
                    PROCSYS_Push(p->f12F0, (u32)ov195_id, d_02208C40, p->req);
                    p->state_i = 1;
                } else {
                    func_021F4EC0(p, 1, 0);
                    ret = 3;
                }
            } else {
                func_021F4EC0(p, 1, 0);
                ret = 3;
            }
            func_020307B0(mon);
        } else {
            func_021F4EC0(p, 1, 0);
            ret = 3;
        }
        break;
    case 1:
        if (p->busy_u != 0) {
            break;
        }
        if (p->req != 0) {
            Req *w = p->req;
            void *e = (void *)func_021F7338((Work *)p, p->kind);

            func_02019CE0(func_0201AB28(w->list, 0), e);
            func_020307B0(w->list);
            func_020307B0(p->req);
            p->req = 0;
        }
        func_021F7374((Work *)p);
        *(volatile u32 *)0x04000000 &= ~0xE000;
        func_02034AC4((u32)ov067_id);
        func_021F4EC0(p, 7, 0xC);
        ret = 3;
        break;
    }
    return ret;
}




/*
 * volatile: 0x021F72AC writes hardware halfword 0x04000050.
 */
int func_021F7268(Work *p)
{
    if (p->info) {
        func_020307B0(p->info);
        p->info = 0;
    }
    func_020307B0(p->fEA4);
    if ((void *)p->req) {
        func_020307B0((void *)p->req);
        (*(void **)&p->req) = 0;
    }
    p->f12F8 = 0;
    func_021F5074((Work *)p);
    func_021F4EC8(p);
    *(volatile unsigned short *)0x04000050 = 0;
    return 0;
}




Info_021F72C4 *func_021F72C4(Entry_021F72C4 *e)
{
    Info_021F72C4 *info;

    info = MYSTATUS_Create(0x48);
    MYSTATUS_Init((struct Sub0200852CObj *)info);
    func_020084D4((u32)info, e->name);
    func_02008560((struct Sub0200852CObj *)info, e->f124);
    func_02008568((struct Sub0200852CObj *)info, e->f125);
    func_0200854C((struct Sub0200852CObj *)info, e->fF6);
    func_02008558((struct Sub0200852CObj *)info, e->f122);
    func_02008574((struct Sub0200852CObj *)info, e->f120, e->f121);
    info->f10 = e->f10C;
    info->f14 = e->f108;
    return info;
}




/*
 * Return the slot record for a kind: kind 9 is the current 0x128-byte
 * entry of the +0x20C array (index at +0xD4), kinds 10 and 8 share the
 * record at +0xE4. Any other kind reports through func_02034714 (raw
 * address 0x02203B80, a plain constant as in func_02202B20) and yields 0.
 */
Entry *func_021F7338(Work *p, int kind)
{
    if (kind == 9) {
        return &p->arr_entry1[p->cur];
    } else if (kind == 10) {
        return &p->single;
    } else if (kind == 8) {
        return &p->single;
    }
    func_02034714((void *)0x02203B80, 0, (void *)0x02203B80);
    return 0;
}





/*
 * Fill the slot record for the current kind (+0x20). A +0xDC source of
 * 0xFF copies party member +0xE0 into it (func_0220262C); otherwise the
 * box/slot pair (+0xDC, +0xE0) is looked up in the storage at +0xC of
 * the context and the found entry is written into the record.
 */
void func_021F7374(Work *p)
{
    u32 e = (u32)func_021F7338(p, p->kind);

    if (p->box_u == 0xff) {
        func_0220262C(e, (u32)func_0201AB28(p->ctx->party, p->pos));
    } else {
        u32 a;
        u32 b;

        a = 0;
        b = 0;
        func_02007664((void *)p->ctx->box, p->box_u, p->pos);
        func_020076D0((void *)p->ctx->box, (int *)(&a), (int *)(&b));
        func_0200752C((void **)p->ctx->box, a, (const struct Sub02007454Entry *)((u32)POKE_TOOL_GetBoxParam((void *)e)));
    }
}





int func_021F73DC(Work *p)
{
    Init init;
    func_021F798C(p);
    func_021F75C0();
    func_021FFFE8((u8 *)p,0,0);
    func_021F76D8(p);
    func_021F777C((Work *)p);
    func_021F7878(p);
    WIPE_SYS_Start((void *)3,1,1,0,6,1,0x48);
    func_021F9254((u8 *)p);
    func_021F81C8(p->bank,p->names,(int)(p->words),(WorldtradeBoxObj2 *)((u8 *)p+0xD90),0,3,-1,(u8 *)p+0xFA0);
    func_021F8358(p->bank,p->words,(void **)((u8 *)p+0xD9C),p->mon,(MonTag *)((u8 *)p+0xB4C),(u8 *)p+0xFA0);
    init.a=(u8 *)p+0xD50;
    init.b=(u8 *)p+0xDD4;
    init.obj=p->mark;
    init.d=p->btn[0];
    init.e=p->btn[1];
    init.f=0;
    init.g=p->bank;
    init.h=p->names;
    init.i=p->msg_p;
    init.j=((struct Obj23379 *)(*(u8 * *)(void **)&p->ctx))->f10;
    init.k=((struct Obj23380 *)(*(u8 * *)(void **)&p->st))->f14;
    init.l=((struct Obj23381 *)(*(u8 * *)(void **)&p->ctx))->f20;
    p->menu=func_021F9890(&init,2,0);
    p->state=0;
    p->f12E4=0;
    return 1;
}





/*
 * State-table dispatch through the table at 0x02203BBC.
 */
void func_021F74E4(u8 *p)
{
    g_02203BBC[*(u32 *)(p + 0x28)](p);
}





int func_021F74F8(WorldtradeBoxObj1 *p)
{
    func_021F7964((Work *)(void *)p);
    func_021F99D0(p->fDE4);
    func_021F79EC((Work *)p);
    func_021F7840((Work *)p);
    func_021F76BC();
    func_022000E4((char *)p);
    func_0204B3DC((struct Obj *)*(unsigned *)&p->fD38, 0);
    func_021F4EC8((Work *)(void *)p);
    return 0;
}





/*
 * Handle walk: 02045EC0 over the 0xb6c field, the 0xb68/0xb88 pair through
 * 0201F250, then the p+0xd40 window through the 02045334/02045374/
 * 02045730/020409B4 group and a 02202858 redraw with the p+0xfa0 block.
 */
void func_021F7538(Work *p, u32 b, u32 c, u32 d, u32 e)
{
    u32 v = (u32)MSGDATA_AllocString((struct MsgBank *)(*(u32 *)&p->bank), b);
    u32 h;

    func_0201F250((struct WordSet *)(*(u32 *)&p->words), (void *)((*(unsigned int *)&p->str)), (void *)v);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->frame)), 0xf);
    h = p->frame;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    sub_020409B4(unit_02045730(h));
    func_0201F73C((void *)(p->frame), 0, 1, 0xe);
    func_02202858((void *)(p->frame), 0, (void *)((*(unsigned int *)&p->str)), 0, 0, (u8 *)p + 0xfa0);
    STRBUF_Delete((struct U16Vec *)v);
}





/*
 * Four-layer bring-up with no display restore: layer 2 is seeded by the
 * 02041300 tile dump and its 020409B4 redraw before the enable.
 */
void func_021F75C0(void)
{
    {
        struct BgTemplate_021F4580 t = g_02202F64;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate_021F4580 t = g_02202F84;
        func_0203FCA0(1, &t, 0);
    }
    func_02040588(1, 1);
    {
        struct BgTemplate_021F4580 t = g_02202F44;
        func_0203FCA0(2, &t, 0);
    }
    func_02041300(2, 0, 0, 0, 0x20, 0x18, 0);
    func_020409B4(2);
    func_02040588(2, 1);
    {
        struct BgTemplate_021F4580 t = g_02202FA4;
        func_0203FCA0(3, &t, 0);
    }
    func_020414EC(3);
    func_02040588(3, 1);
    func_02040B94(0, 0x20, 0, 0x48);
    func_02040B94(3, 0x20, 0, 0x48);
}





/*
 * Poke the channel-selection helper with 2, 1, 0, 3 in turn.
 */
void func_021F76BC(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
    sub_020403F4(3);
}





void func_021F76D8(Work *p)
{
    void *h = func_020490F4(0x60, 0x48);
    func_02049B40(0x60, 0, 0, 0, 0x40, 0x48);
    func_02049B40(0x17, 5, 0, 0x1A0, 0x20, 0x48);
    func_0201F5BC(0, 1, 14, 0, 0x48);
    func_0201F5BC(0, 31, 11, 0, 0x48);
    func_02049624((void *)0x60, (void *)9, (void *)1, 0, 0, 1, 0x48);
    func_0204989C(0x60, 20, 1, 0, 0x600, 1, 0x48);
    func_02049658(h, 12, 2, 0, 0, 1, 0x48);
    func_02200B34((u8 *)p);
    ARC_TOOL_DeleteHandle(h);
}





void func_021F777C(Work *p)
{
    void *w;
    int i;
    p->d40 = (void *)BMP_WIN_Create(0, (u8)2, (u8)21, (u8)27, 2, 13, (u16)1);
    BMP_Clear(func_02045770(p->d40), 0);
    w = p->d40;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_020409B4(func_02045730(w));
    for (i = 0; i < 6; i++) {
        p->wins[i] = (void *)BMP_WIN_Create(3, (u8)tbl_02202EC0[i][0], (u8)tbl_02202EC0[i][1], (u8)12, 2, 13, (u16)1);
        BMP_Clear(func_02045770(p->wins[i]), 0);
        w = p->wins[i];
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        func_020409B4(func_02045730(w));
    }
    func_02200BAC((u8 *)p, 3);
}





void func_021F7840(Work *p) { int i; func_02202940((struct Obj *)((char *)p+0xfa0)); func_020452E8(p->fDE0); for(i=0;i<6;i++) func_020452E8(*(void **)((u32)(char *)p+(u32)i*4+0xd90)); func_020452E8(p->d40); }





/*
 * CLACT_CreateActor returns the object consumed by the subsequent calls and stores.
 * Matched ov135 neighbours prove its pointer request in the fifth slot.
 */
void func_021F7878(Work *p)
{
    Pos_021F7374 pos;
    func_02082BCC(&pos,0,8);
    pos.x=0xA0;
    pos.y=0x20;
    p->mark=CLACT_CreateActor(p->res,(unsigned int)p->set2,(unsigned int)p->set[1],(unsigned int)p->set3,&pos,0,0x48);
    CLACT_SetActorAnimSeq(p->mark,12);
    func_0204B92C(p->mark,1);
    CLACT_StopActorAnim(p->mark);
    func_0204B3DC(p->mark,0);
    pos.x=0xE4;
    pos.y=0x75;
    p->btn[0]=CLACT_CreateActor(p->res,(unsigned int)p->set[0],(unsigned int)p->set[1],(unsigned int)p->set[2],&pos,0,0x48);
    CLACT_SetActorAnimSeq(p->btn[0],0x26);
    func_0204B3DC(p->btn[0],0);
    pos.x=0x8C;
    p->btn[1]=CLACT_CreateActor(p->res,(unsigned int)p->set[0],(unsigned int)p->set[1],(unsigned int)p->set[2],&pos,0,0x48);
    CLACT_SetActorAnimSeq(p->btn[1],0x27);
    func_0204B3DC(p->btn[1],0);
}





/*
 * Release the +0xbf8, +0xd2c and +0xd30 handles.
 */
void func_021F7964(Work *p)
{
    CLACT_DeleteActor((struct Obj *)(p->sub.f38));
    CLACT_DeleteActor((struct Obj *)((*(unsigned int *)&p->btn[0])));
    CLACT_DeleteActor((struct Obj *)((*(unsigned int *)&p->btn[1])));
}





void func_021F798C(Work *p)
{
    p->str = STRBUF_Create(0xB4, 0x48);
    (*(void **)&p->st) = func_02030734(0x48, 0x30, 0, g_02203C00, 0x2B4);
    func_02082AC0(0, (void *)p->st, 0x30);
    *(u16 * *)&((struct Obj23382 *)(*(u8 * *)(void **)&p->st))->f18 = func_021F8498(0x48, 0, (u32 *)(*(u8 * *)(void **)&p->st + 0x1C));
    *(u8 * *)&((struct Obj23383 *)(*(u8 * *)(void **)&p->st))->f14 = func_021F84EC(0x48);
    func_021F8990((u8 *)p + 0xEEC);
}





void func_021F79EC(Work *p) { func_020307B0(((struct Obj23384 *)(*(char * *)(void **)&p->st))->f14); func_020307B0(((struct Obj23385 *)(*(char * *)(void **)&p->st))->f18); func_020307B0((void *)p->st); STRBUF_Delete(p->str); }





int func_021F7A18(Work *p) { if(WIPE_SYS_EndCheck()){func_021F7538(p,9,1,0,0xf0f);func_021F4E98(p,16,1);}return 2; }





/*
 * Test bit 1 of the callee result; the odd branch re-latches state 2 before state 3.
 */
int func_021F7A4C(Work *p)
{
    u32 v = func_020362DC();

    if (v & 2) {
        func_021F4EC0(p, 5, 5);
        p->state = 2;
    }
    p->state = 3;
    return 2;
}





/*
 * Hand the buffer at +0xde4 to the writer and stamp state 6.
 */
int func_021F7A70(Work *p)
{
    func_021F9968((u8 *)((*(unsigned int *)&p->menu)), 0);
    p->state = 6;
    return 2;
}





int func_021F7A8C(Work *p)
{
    switch ((unsigned)func_021F8950(p->fDF4, (u16 *)((u8 *)p + 0xBC))) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        BMP_MENULIST_Delete(p->fDF4, (u16 *)(*(u8 * *)(void **)&p->st + 6), (u16 *)(*(u8 * *)(void **)&p->st + 4));
        BMP_MENUWORK_Delete(p->de8);
        p->state = 5;
        func_020061E4(0x54C);
        break;
    case (unsigned)-2:
        BMP_MENULIST_Delete(p->fDF4, (u16 *)(*(u8 * *)(void **)&p->st + 6), (u16 *)(*(u8 * *)(void **)&p->st + 4));
        BMP_MENUWORK_Delete(p->de8);
        func_02202644((u32)(p->side_p2[0]), 0);
        func_0201F7A8(p->d40, 0);
        func_020452E8(p->side_p2[0]);
        func_020452E8(p->win3);
        func_021F4EC0(p, 5, 5);
        p->state = 2;
        func_020061E4(0x54C);
        break;
    case 0:
        break;
    }
    return 2;
}





int func_021F7B50(Work *p)
{
    p->fDF4 = func_021F875C((Work *)p, (void **)((u8 *)p + 0xDE8), p->win3, p->bank, p->names, (WorldtradeBoxObj6 *)((void *)p->st), ((struct Obj23386 *)(*(u8 * *)(void **)&p->ctx))->f10);
    p->fBC = 0xFFFF;
    p->state = 6;
    return 2;
}





/*
 * Map the event code to its state byte: 0, 0xfe and 0xff are accepted.
 */
int func_021F7B9C(WorldtradeBoxObj8 *p, int event)
{
    switch (event) {
    case 0:
        p->f2 = 1;
        return 1;
    case 0xfe:
        p->f2 = 2;
        return 1;
    case 0xff:
        p->f2 = 3;
        return 1;
    }
    return 0;
}





/*
 * lever: signed halfword selection store keeps the unsigned argument truncation after it.
 */
int func_021F7BC8(Work *p)
{
    int result=func_021F99F0(p->menu);
    u32 h,v;
    int mode;
    WorldtradeBoxObj3 *target;
    switch(result) {
    case (u32)-2:
        func_0201F7A8(p->d40,0);
        func_021F4EC0(p,5,5);
        p->state=2;
        target=(WorldtradeBoxObj3 *) (*(u8 * *)(void **)&p->st);
        func_021F89A8((u8 *)p+0xEEC,target->f6+target->f4,target->fA,target->f8);
        break;
    case (u32)-1:
        break;
    default:
        p->fB50=result;
        h=(u32)func_0201ADE4((u16)result,0,0x48);
        v=func_0201AE1C((const struct Personal *)h,20);
        func_0201AE14((void *)h);
        ((struct Obj23387 *)(*(u8 * *)(void **)&p->st))->f20=v;
        if(func_021F7B9C((WorldtradeBoxObj8 *)((u8 *)p+0xB50),((struct Obj23388 *)(*(u8 * *)(void **)&p->st))->f20)) {
            p->state=10;
            mode=p->fB52;
        } else {
            p->state=7;
            mode=3;
        }
        func_021F81C8(p->bank,p->names,(int)(p->words),(WorldtradeBoxObj2 *)((u8 *)p+0xD90),p->fB50,mode,-1,(u8 *)p+0xFA0);
        target=(WorldtradeBoxObj3 *) (*(u8 * *)(void **)&p->st);
        func_021F89A8((u8 *)p+0xEEC,target->f6+target->f4,target->fA,target->f8);
        break;
    }
    return 2;
}





/*
 * Build through func_021F7538 and publish the 0x10/0x8 pair.
 */
int func_021F7CB4(Work *p)
{
    func_021F7538(p, 0xa, 1, 0, 0xf0f);
    func_021F4E98(p, 0x10, 0x8);
    return 2;
}





/*
 * Publish the 0xffff sentinel at +0xbc and the u32 at +0xde4, then latch state 9.
 */
int func_021F7CDC(Work *p)
{
    p->fBC = 0xffff;
    func_021F9968((u8 *)((*(unsigned int *)&p->menu)), 1);
    p->state = 9;
    return 2;
}





int func_021F7D00(Work *p)
{
    unsigned result = func_021F99F0(p->menu);
    switch (result) {
    case (unsigned)-2:
        func_0201F7A8(p->d40, 0);
        p->state = 0;
        break;
    case 0: case 1: case 2:
        p->fB52 = result + 1;
        p->state = 10;
        func_021F81C8(p->bank, p->names, (int)(p->words), (WorldtradeBoxObj2 *)((u8 *)p + 0xD90), p->fB50, p->fB52, -1, (u8 *)p + 0xFA0);
        break;
    }
    return 2;
}





int func_021F7D80(Work *p)
{
    func_021F7538(p, 0xb, 1, 0, 0xf0f);
    func_021F4E98(p, 0x10, 0xb);
    return 2;
}





/*
 * Publish the u32 at +0xde4, the 0xffff sentinel at +0xbc and latch state 0xc.
 */
int func_021F7DA8(Work *p)
{
    func_021F9968((u8 *)((*(unsigned int *)&p->menu)), 2);
    p->fBC = 0xffff;
    p->state = 0xc;
    return 2;
}





int func_021F7DD0(Work *p)
{
    unsigned result = func_021F99F0(p->menu);
    switch (result) {
    case 12: case (unsigned)-2:
        func_0201F7A8(p->d40, 0);
        if (func_021F7B9C((WorldtradeBoxObj8 *)((u8 *)p + 0xB50), ((struct Obj23389 *)(*(u8 * *)(void **)&p->st))->f20)) {
            p->state = 0;
        } else {
            p->state = 7;
        }
        break;
    case (unsigned)-1:
        break;
    default:
        func_021F882C((u8 *)p + 0xB50, result, 0);
        p->state = 13;
        result = func_021F886C(p->fB53, p->fB54_c, 0);
        func_021F81C8(p->bank, p->names, (int)(p->words), (WorldtradeBoxObj2 *)((u8 *)p + 0xD90), p->fB50, p->fB52, result, (u8 *)p + 0xFA0);
        break;
    }
    return 2;
}





int func_021F7E74(Work *p)
{
    func_021F7538(p, 0x17, 1, 0, 0xf0f);
    func_021F4E98(p, 0x10, 0xe);
    return 2;
}





/*
 * State setter: build with the fixed 0x14/0x126/0x3/0x0 argument pair and latch state 0xf.
 */
int func_021F7E9C(Work *p)
{
    func_021F4BE0((u32)p, 0x14, 0x126, 0x3, 0x0);
    p->state = 0xf;
    return 2;
}





int func_021F7EC0(Work *p)
{
    int result;
    result = func_021F4D14(p);
    if (result == 1) {
        func_021F4CE4(p);
        func_021F4EC0(p, 7, 7);
        p->state = 2;
        p->eb4 = 1;
        func_021F8668((WorldtradeBoxObj5 *)((u8 *)p + 0xE4), p);
    } else if (result == 2) {
        func_021F4CE4(p);
        func_021F4EC0(p, 5, 5);
        p->state = 2;
    }
    return 2;
}





int func_021F7F14(Work *p)
{
    if (p->x14 == 0) {
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
        p->eb4 = 1;
    } else {
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    p->state = 0;
    return 3;
}





/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int func_021F7F64(Work *p)
{
    if (func_02202840((u8 *)p + 0xfa0) == 0) {
        p->state = ((struct Obj12201 *)p)->f2C;
    }
    return 2;
}





/*
 * Mode table: 0 -> 0x14c0, 1 -> 0xc80, anything else 0.
 */
u16 func_021F7F80(int mode)
{
    switch (mode) {
    case 0:
        return 0x53 << 6;
    case 1:
        return 0x32 << 6;
    default:
        return 0;
    }
}





void func_021F7F9C(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g)
{
    void *str;

    if (index != 0) {
        str = func_02045EC0(bank, index);
        func_021F91A0(win, str, 0, x, y, color, g);
        STRBUF_Delete(str);
    }
}





void func_021F7FD4(void *win, void *bank, u32 index, u32 y, u16 color, void *g)
{
    void *str;

    if (index != 0) {
        str = func_02045EC0(bank, index);
        func_022028C8(win, 0, str, 0, y, 0, color, g);
        STRBUF_Delete(str);
    }
}





void func_021F8010(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *g)
{
    void *str;

    if (index != 0) {
        str = func_02045EC0(bank, index);
        func_021F91A0(win, str, 0, x, y, color, g);
        STRBUF_Delete(str);
    } else {
        str = func_02045EC0(bank2, 0xBB);
        func_021F91A0(win, str, 0, x, y, color, g);
        STRBUF_Delete(str);
    }
}





u16 func_021F8078(int mode, u16 color)
{
    if (mode == 1) {
        return func_021F7F80(0);
    }
    if (mode == 2) {
        color = func_021F7F80(1);
    }
    return color;
}





void func_021F8098(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g)
{
    void *str;

    if (force != 0 || mode != 3) {
        str = func_02045EC0(bank, tbl_02202EB0[mode]);
        if (y > 3) {
            func_021F91A0(win, str, y, x, 0, func_021F8078(mode, color), g);
        } else {
            func_021F91A0(win, str, 0, x, y, func_021F8078(mode, color), g);
        }
        STRBUF_Delete(str);
    }
}





void func_021F8104(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g)
{
    void *str;

    if (force != 0 || mode != 3) {
        str = func_02045EC0(bank, tbl_02202EB0[mode]);
        func_022028C8(win, 0, str, x, y, 0, func_021F8078(mode, color), g);
        STRBUF_Delete(str);
    }
}





void func_021F8154(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g)
{
    func_021F8178(win, bank, idx, e, 0, y, color, alt, (u32)g);
}





void func_021F8178(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g)
{
    const TableRow *tab;
    void *str;

    if (idx != -1) {
        tab = tbl_0220301C;
        if (alt != 0) {
            tab = tbl_02202FC4;
        }
        str = func_02045EC0(bank, tab[idx].id);
        func_021F91A0(win, str, x, y, e, color, (void *)g);
        STRBUF_Delete(str);
    }
}





void func_021F81C8(void *bank, void *names, int unused, WorldtradeBoxObj2 *win, u32 index, int mode, int place, void *g)
{
    int i;
    void *str;
    int show = 1;
    str = func_02045EC0(bank, 0x6b);
    func_021F91A0(win->f0, str, 1, 0, 0, 0x440, g);
    for (i = 1; i < 3; i++)
        BMP_Clear(func_02045770(*(void **)((u8 *)win + i * 4)), 0);
    func_021F7F9C(win->f4, names, index, 0, 0, 0x440, g);
    if (index == 29 && mode == 2)
        show = 0;
    else if (index == 32 && mode == 1)
        show = 0;
    if (show) {
        if (mode == 1 || mode == 2)
            func_021F8098(win->f4, bank, mode, 0, 0, 70, 0x440, g);
    }
    func_021F8154(win->f8, bank, place, 2, 0, 0x440, 0, g);
    STRBUF_Delete(str);
}




void func_021F8290(void *bank, void *names, int unused, WorldtradeBoxObj2 *win, u32 index, int mode, int place, void *g)
{
    int i;
    void *str;
    int show = 1;
    str = func_02045EC0(bank, 0x6b);
    func_021F91A0(win->f0, str, 0, 0, 0, 0x440, g);
    for (i = 1; i < 3; i++)
        BMP_Clear(func_02045770(*(void **)((u8 *)win + i * 4)), 0);
    func_021F7F9C(win->f4, names, index, 0, 0, 0x440, g);
    if (index == 29 && mode == 2)
        show = 0;
    else if (index == 32 && mode == 1)
        show = 0;
    if (show) {
        if (mode == 1 || mode == 2)
            func_021F8098(win->f4, bank, mode, 0, 0, 70, 0x440, g);
    }
    func_021F8154(win->f8, bank, place, 0, 0, 0x440, 0, g);
    STRBUF_Delete(str);
}





void func_021F8358(void *bank, void *ws, void **win, void *mon, MonTag *out, void *g)
{
    int i;
    int form;
    void *title;
    void *place;
    void *name;
    void *tmp;
    u32 has;
    u32 gender;

    name = STRBUF_Create(0xB, 0x48);
    tmp = STRBUF_Create(0xB, 0x48);
    func_02017E88(mon, 0x73, (u32)name);
    form = func_02017E88(mon, 0x6E, 0) + 1;
    gender = POKE_TOOL_CalcBoxLevel(mon);
    has = func_02017E88(mon, 0xAD, 0);
    title = func_02045EC0(bank, 0x6E);
    func_0201EFA4(ws, 3, gender, 3, 0, 1);
    place = (void *)func_02202670((u32)ws, (u32)bank, 0x72, 0x48);
    if (form != 3) {
        func_02045CAC(bank, tbl_02202EB0[form], tmp);
    }
    for (i = 0; i < 3; i++) {
        BMP_Clear(func_02045770(win[i]), 0);
    }
    func_021F91A0(win[0], title, 1, 0, 0, 0x3C40, g);
    func_021F91A0(win[1], name, 0, 0, 0, 0x3C40, g);
    func_021F91A0(win[2], place, 0, 0, 2, 0x3C40, g);
    if (form != 3 && has != 0) {
        func_021F91A0(win[1], tmp, 0x46, 0, 0, func_021F7F80(form - 1), g);
    }
    out->species = func_02017E88(mon, 5, 0);
    out->form = form;
    out->gender = gender;
    STRBUF_Delete(place);
    STRBUF_Delete(tmp);
    STRBUF_Delete(name);
    STRBUF_Delete(title);
}





u16 *func_021F8498(u32 heap, u32 unused, u32 *count)
{
    u32 size;
    u16 *list;

    list = (u16 *)ARC_UTIL_LoadMemberWithSize(0x62, 5, 0, (u16)heap, &size);
    *count = size / 2;
    return list;
}





void func_021F84BC(u32 i, int *start, int *end)
{
    if (i >= 0x1B) {
        func_02034714((void *)0x02203C18, 0, (void *)0x02203C18);
    }
    *start = tbl_0220307C[i];
    *end = tbl_0220307C[i + 1];
}





u8 *func_021F84EC(u32 id)
{
    u32 size;
    u32 i;
    u8 *buf;
    u16 *tbl;
    u32 n;

    buf = func_02030734(0x48, 0x28A, 0, (const char *)g_02203C00, 0x796);
    func_02082AC0(0, buf, 0x28A);
    tbl = (u16 *)ARC_UTIL_LoadMemberWithSize(0x62, 4, 0, (u16)id, &size);
    n = size / 2;
    for (i = 0; i < n; i++) {
        if (tbl[i] < 0x28A) {
            buf[tbl[i]] = 1;
        }
    }
    func_020307B0(tbl);
    return buf;
}





void func_021F8554(WorldtradeBoxObj5 *dst, Work *p)
{
    u32 species;

    if (func_021F6B34(p->box) != 0) {
        species = func_02017E88(p->mon, 5, 0);
        if (species == 0x1EC || species == 0x286) {
            POKE_TOOL_ChangeForm(p->mon, 0);
        }
        func_02082B0C(p->mon, dst, func_020173EC());
    } else {
        species = func_02017E88(p->mon, 5, 0);
        if (species == 0x1EC || species == 0x286) {
            POKE_TOOL_ChangeBoxForm((int)p->mon, 0);
        }
        func_022026A0(p->mon, (u32)dst);
    }
    func_0201F41C(func_020084F4(p->ctx->f1C), (u16 *)((u8 *)dst + 0x110), 8);
    *(u32 *)((u8 *)dst + 0x10C) = func_02008530(p->ctx->f1C);
    ((u8 *)dst)[0x120] = func_0200856C(p->ctx->f1C);
    ((u8 *)dst)[0x121] = func_02008570(p->ctx->f1C);
    ((u8 *)dst)[0x122] = func_02008554(p->ctx->f1C);
    ((u8 *)dst)[0xF6] = func_02008550(p->ctx->f1C);
    ((u8 *)dst)[0x124] = 0x15;
    ((u8 *)dst)[0x125] = 2;
    ((u8 *)dst)[0x126] = func_02009628(p->ctx->status);
    ((u8 *)dst)[0x127] = func_02009584(p->ctx->status);
    ((u8 *)dst)[0xF7] = func_0200960C(p->ctx->status);
}





void func_021F8668(WorldtradeBoxObj5 *dst, Work *p)
{
    func_021F8554(dst, (Work *)p);
    dst->fEC = p->fB4C;
    dst->fEE = p->fB4E;
    dst->fF0 = (*(unsigned short *)&p->fB50);
    dst->fF2 = p->fB52_h;
    dst->fF4 = p->fB54;
}





int func_021F86A8(void **menu, void *msg, void *endmsg, u16 *list, u32 unused4, u32 unused5, u32 kind, void *bag)
{
    int i;
    int size;
    int count;
    int start;
    count = 0;
    start = tbl_02203B84[kind];
    size = tbl_02203B84[kind + 1] - start;
    for (i = 0; i < size; i++) {
        if (func_0200D064(bag, list[start + i]) != 0) count++;
    }
    *menu = BMP_MENUWORK_Create(count + 1, 0x48);
    for (i = 0; i < size; i++) {
        if (func_0200D064(bag, list[start + i]) != 0) {
            BMP_MENUWORK_AddMsgItem(*menu, (u32)msg, list[start + i], list[start + i], 0x48);
        }
    }
    BMP_MENUWORK_AddMsgItem(*menu, (u32)endmsg, 0x85, -2, 0x48);
    return count + 1;
}





/*
 * lever: u16 arrays at 0xEF0 and 0xF04 preserve base/index load scheduling; raw offset casts differ by 8 bytes.
 */
void *func_021F875C(Work *p, void **menu, void *win, void *endmsg, void *msg, WorldtradeBoxObj6 *cfg, void *bag)
{
    int kind;
    int count;
    BoxMenu_021F7374 src;
    BMP_Clear(func_02045770(win), 15);
    kind = cfg->f6 + cfg->f4;
    count = func_021F86A8(menu, msg, endmsg, *(u16 * *)&cfg->f18, cfg->f14, cfg->f1C, kind, bag);
    src = d_02202ED8;
    src.count = count;
    src.w[0] = (u32)*menu;
    src.w[3] = (u32)win;
    func_0201F73C(win, 0, 31, 11);
    return BMP_MENULIST_Create((struct Src *)(&src), p->a[kind], p->b[kind], 0x48);
}




int func_021F87E0(void **menu, void *msg, int kind)
{
    const TableRow *table;
    int i;
    int count;
    if (kind == 0) { table = tbl_0220301C; count = 12; }
    else { table = tbl_02202FC4; count = 11; }
    *menu = BMP_MENUWORK_Create(count, 0x48);
    for (i = 0; i < count; i++) {
        BMP_MENUWORK_AddMsgItem(*menu, (u32)msg, table[i].id, i, 0x48);
    }
    return count;
}



void func_021F882C(u8 *dst, int i, int kind)
{
    const TableRow *table;
    if (kind == 0) {
        table = tbl_0220301C;
        if (i >= 12) func_02034714(str_02203C18, 0, str_02203C18);
    } else {
        table = tbl_02202FC4;
        if (i >= 11) func_02034714(str_02203C18, 0, str_02203C18);
    }
    dst[3] = table[i].x;
    dst[4] = table[i].y;
}




/*
 * Index of a key/value pair in one of two s16 tables.
 */
int func_021F886C(int key, int val, int which)
{
    int i;
    int n;
    const TableRow *tab;

    if (which == 0) {
        tab = tbl_0220301C;
        n = 0xc;
    } else {
        tab = tbl_02202FC4;
        n = 0xb;
    }
    for (i = 0; i < n; i++) {
        if (tab[i].key == key && tab[i].val == val) {
            return i;
        }
    }
    return 0;
}
