/*
 * file:     guru2_main.c
 * unit:     yes
 * function: func_021DD1E0, func_021DD2E0, func_021DD380, func_021DD3B0, func_021DD3D8, func_021DD4A8, func_021DD570, func_021DD5AC, func_021DD638, func_021DD700, func_021DD760, func_021DD79C, func_021DD7E4, func_021DD80C, func_021DD924, func_021DD928, func_021DD93C, func_021DD94C, func_021DD970, func_021DD99C, func_021DD9D4, func_021DDAEC, func_021DDB04, func_021DDB90, func_021DDBB0, func_021DDBE8, func_021DDC7C, func_021DDCB4, func_021DDCEC, func_021DDD0C, func_021DDD48, func_021DDD80, func_021DDE24, func_021DDE74, func_021DDE94, func_021DDEDC, func_021DDF38, func_021DDF64, func_021DDF84, func_021DDFC0, func_021DDFFC, func_021DE060, func_021DE08C, func_021DE17C, func_021DE220, func_021DE248, func_021DE350, func_021DE354, func_021DE37C, func_021DE388, func_021DE4B4, func_021DE55C, func_021DE5C0, func_021DE5D0, func_021DE6C0, func_021DE6DC, func_021DE6EC, func_021DE738, func_021DE7F4, func_021DE7FC, func_021DE960, func_021DEA0C, func_021DEA68, func_021DEA70, func_021DEA84, func_021DEAC8, func_021DEAE0, func_021DEB10, func_021DEB1C, func_021DEB40, func_021DEB74, func_021DEC08, func_021DEC38, func_021DEC64, func_021DEC84, func_021DECB0, func_021DECCC, func_021DECF4, func_021DED3C, func_021DED88, func_021DEDAC, func_021DEE4C, func_021DEED8, func_021DEF14, func_021DEF3C, func_021DEF6C, func_021DEFB4, func_021DEFD0, func_021DEFE8, func_021DF004, func_021DF01C, func_021DF050, func_021DF060, func_021DF1C4, func_021DF204, func_021DF22C, func_021DF2A0, func_021DF2B8, func_021DF2E0, func_021DF370, func_021DF3E8, func_021DF434, func_021DF488, func_021DF4AC, func_021DF548, func_021DF56C, func_021DF5B0, func_021DF5EC, func_021DF648, func_021DF6A4, func_021DF6B8, func_021DF6D4, func_021DF6FC, func_021DF778, func_021DF7A4, func_021DF7CC, func_021DF7E8, func_021DF800, func_021DF83C, func_021DF864, func_021DF984, func_021DF998, func_021DFA14, func_021DFA68, func_021DFAD8, func_021DFB60, func_021DFC74, func_021DFE40, func_021DFE6C, func_021DFEA0, func_021DFEB8, func_021DFEC4, func_021DFEFC, func_021DFF20, func_021DFF44, func_021DFF70, func_021DFFC8, func_021DFFF8, func_021E00D4, func_021E0130, func_021E01B0, func_021E026C, func_021E0304, func_021E0338, func_021E03A0, func_021E03D8, func_021E0450, func_021E0478, func_021E04B4, func_021E04C4, func_021E04E0, func_021E0554, func_021E0570, func_021E05D4, func_021E0634, func_021E0640, func_021E0678, func_021E0698, func_021E06E0, func_021E073C, func_021E078C, func_021E07A4, func_021E0848, func_021E0980, func_021E09C0, func_021E0A44, func_021E0B14, func_021E0B38, func_021E0BA4, func_021E0BC0, func_021E0C08, func_021E0C70, func_021E0CA4, func_021E0CCC, func_021E0D0C, func_021E0D50, func_021E0DC0, func_021E0DE8, func_021E0E1C, func_021E0E2C, func_021E0E50, func_021E0EAC, func_021E0EFC, func_021E0F20, func_021E0F54, func_021E0F64, func_021E0FAC, func_021E1028, func_021E104C, func_021E1080, func_021E1090, func_021E10D8, func_021E11B4, func_021E11E4, func_021E11F4, func_021E1204, func_021E1210, func_021E121C, func_021E129C, func_021E1320, func_021E13BC, func_021E13F0, func_021E1400, func_021E140C, func_021E141C, func_021E1468, func_021E1488, func_021E14BC, func_021E14CC, func_021E14E4, func_021E1540, func_021E1584, func_021E15DC, func_021E1604, func_021E161C, func_021E1634, func_021E168C, func_021E1694, func_021E16AC, func_021E16C0, func_021E16C4, func_021E16D8, func_021E170C, func_021E172C, func_021E1758, func_021E1768, func_021E1784, func_021E17EC, func_021E180C, func_021E1814, func_021E1830, func_021E18CC, func_021E1910, func_021E1954, func_021E1974, func_021E1988, func_021E19A4
 * address:  0x021DD1E0
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   d_021E1B70 0x021E1B70 data a4
 *   d_021E1BE0 0x021E1BE0 data a4
 *   d_021E1B80 0x021E1B80 data a4
 *   d_021E1BA0 0x021E1BA0 data a4
 *   d_021E1BC0 0x021E1BC0 data a4
 *   d_021E1C00 0x021E1C00 data a4
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02049F78 0x02049F78 arm
 *   func_020307B0 0x020307B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   func_020452E8 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   UNION_APP_Close 0x02184114 thumb ov022
 *   UNION_APP_Open 0x02184134 thumb ov022
 *   func_020061E4 0x020061E4 thumb
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   d_021E1AE8 0x021E1AE8 data a2
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   func_0201F02C 0x0201F02C thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 *   func_02039CB4 0x02039CB4 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   PRINTSYS_PrintStreamStop 0x0201CE0C thumb
 *   func_02008534 0x02008534 thumb
 *   func_02008500 0x02008500 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   UNION_APP_GetJoinedBits 0x021841A0 thumb ov022
 *   func_02008530 0x02008530 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0203630C 0x0203630C arm
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_020362DC 0x020362DC arm
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02008550 0x02008550 thumb
 *   func_02008554 0x02008554 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049F34 0x02049F34 arm
 *   d_021E1AF8 0x021E1AF8 data a1
 *   func_0207E51C 0x0207E51C arm
 *   func_02049E34 0x02049E34 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02012934 0x02012934 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_020056A0 0x020056A0 thumb
 *   G3D_UTIL_Create 0x02047CFC arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   d_021E1FA0 0x021E1FA0 data a2
 *   d_021E22B8 0x021E22B8 data a1
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_020351A0 0x020351A0 arm
 *   d_021E217C 0x021E217C data a4
 *   func_02030D28 0x02030D28 arm
 *   func_02039C68 0x02039C68 arm
 *   GFL_NET_SendDataMask 0x0203D4D0 arm
 *   d_021E1FDC 0x021E1FDC data a2
 *   func_0200ED48 0x0200ED48 thumb
 *   func_021E19C0 0x021E19C0 thumb ov137
 *   func_020056EC 0x020056EC thumb
 *   func_0201292C 0x0201292C thumb
 *   func_02007E50 0x02007E50 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E1F34 0x021E1F34 data a4
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0203516C 0x0203516C arm
 *   func_0201088C 0x0201088C thumb
 *   TIME_ICON_Create 0x0202EE30 thumb
 *   func_02010904 0x02010904 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBB0 0x0200FBB0 thumb
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   func_02010934 0x02010934 thumb
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   UNION_APP_RequestReset 0x02184174 thumb ov022
 *   UNION_APP_IsResetDone 0x0218417C thumb ov022
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   func_020419E4 0x020419E4 arm
 *   func_02048B6C 0x02048B6C arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   NNS_G3dGlbLightVector 0x0206AA3C arm
 *   NNS_G3dGlbLightColor 0x0206AA78 arm
 *   NNS_G3dGlbMaterialColorDiffAmb 0x0206AA8C arm
 *   NNS_G3dGlbMaterialColorSpecEmi 0x0206AAB0 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   TIME_ICON_Update 0x0202F0B0 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   d_021E1EA4 0x021E1EA4 data a4
 *   func_02040588 0x02040588 arm
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   d_021E1D90 0x021E1D90 data a2
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   d_021E2020 0x021E2020 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021E1D00 0x021E1D00 data a4
 *   d_021E1D0C 0x021E1D0C data a4
 *   func_0203F8F4 0x0203F8F4 arm
 *   d_021E202C 0x021E202C data a4
 *   d_021E204C 0x021E204C data a4
 *   d_021E206C 0x021E206C data a4
 *   d_021E208C 0x021E208C data a4
 *   d_021E20AC 0x021E20AC data a4
 *   d_021E20CC 0x021E20CC data a4
 *   func_02062A98 0x02062A98 arm
 *   PALANM_CopyToSlot 0x020215BC thumb
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   func_02062A00 0x02062A00 arm
 *   func_02040B1C 0x02040B1C arm
 *   func_02062B30 0x02062B30 arm
 *   func_02040AE0 0x02040AE0 arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_0201EF40 0x0201EF40 thumb
 *   d_021E1E30 0x021E1E30 data a4
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021E1CB0 0x021E1CB0 data a4
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   d_021E20EC 0x021E20EC data a4
 *   d_021E1DE8 0x021E1DE8 data a4
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   func_02048A18 0x02048A18 arm
 *   BUTTON_MAN_MakeRotMtxXYZ 0x020520FC arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   d_021E1D80 0x021E1D80 data a4
 *   d_021E1E60 0x021E1E60 data a4
 *   d_021E1E70 0x021E1E70 data a4
 *   d_021E212C 0x021E212C data a4
 *   func_0207ADC4 0x0207ADC4 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   func_0203F63C 0x0203F63C arm
 *   func_0203F5FC 0x0203F5FC arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   func_02030DA8 0x02030DA8 arm
 *   d_021E1CB8 0x021E1CB8 data a4
 *   d_021E203C 0x021E203C data a4
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   d_021E2278 0x021E2278 data a4
 *   d_021E2018 0x021E2018 data a4
 *   ARC_TOOL_GetHandleMemberSize 0x020493D4 arm
 *   ARC_TOOL_ReadHandleMember 0x0204932C arm
 *   func_021DCE00 0x021DCE00 thumb ov137
 *   func_0201AB28 0x0201AB28 thumb
 *   func_0202F190 0x0202F190 thumb
 *   func_02019CE0 0x02019CE0 thumb
 *   d_021E1F04 0x021E1F04 data a4
 *   func_0201AA18 0x0201AA18 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_02005F38 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   d_021E1B40 0x021E1B40 data a4
 *   d_021E1B20 0x021E1B20 data a4
 *   d_021E1B30 0x021E1B30 data a4
 *   d_021E1B38 0x021E1B38 data a4
 *   d_021E1B08 0x021E1B08 data a2
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 */
#include "ov137_types.h"
struct Guru2MainCtx3;
struct Guru2MainCtx4;

struct Guru2MainCtx3 {
    int f0;
    int f4;
    unsigned char pad_8[28];
    unsigned short f24;
    unsigned short f26;
    unsigned short f28;
    unsigned char pad_2A[14];
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
    unsigned char pad_50[20];
    void *f64;
};

struct Guru2MainCtx4 {
    unsigned short f0;
    unsigned short f2;
};

#define DISP3D (*(volatile u16 *)0x04000060)
struct MsgBank;
struct U16Vec;
struct Bank;
struct Cfg;
struct Sub0200852CObj;
struct FrameObj;
struct CharBuf;
struct Descriptor;
struct StrObj;
struct BmpMenu;
struct WordSet;
struct Entry;
struct Link;
struct Rec3;
struct Rec;
struct Sub0204A9D0;
struct Obj0203159C;
struct BigObj;
struct Ctx;
struct PrintSys;
struct S020315D4;
struct Node;
struct Big;
struct L0200ED54;
struct Sub02008C20Obj;
struct Sub0201088CObj;
struct S02021D50;
struct Light;
struct DispVram;
struct NitroFileHeader;
struct PalAnmSlot;
struct Util;
struct Setup;
struct GfFont;
struct Arg;
struct Mtx33;
struct Actor;
struct Obj;
struct ArcFile;
struct RecDC;
typedef unsigned int u32;

struct DispConfig { u32 w[4]; };

struct BgTemplate { u32 w[8]; };

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed short s16_021DD1E0;

typedef signed char s8;

typedef signed int s32;

typedef struct {u8 frame,x,y,pal;u16 chr;} WinDat;

typedef struct { void *current; void *previous; } Entry;

typedef struct { char pad[0x38]; void *font; void *formatter; void *bank; void *names[5]; char pad58[0xe0]; Entry entries[5]; } Context;

typedef unsigned long long u64;

typedef union { struct { u32 a,b; } words; u64 wide; } WordPair;

typedef struct { char pad[0x4824]; WordPair current,previous; } FrameRecord;

typedef struct { u8 pad[0x4804]; volatile int previous; } FrameObj;

typedef struct { u8 pad[0x90]; void *slots[5]; void *other[5]; } SlotObj;

typedef struct {int a,b;u16 values[5];u16 flag;} Msg;

typedef struct {u8 pad[28]; int angle;} Selected;

typedef struct { int state; u8 pad[36]; Selected *selected; int index, count; } SelectObj;

typedef struct { u8 pad[0x60]; u16 angles[5]; } AngleObj;

struct RangeU32 { u32 low, high; };

typedef enum { GX_SHADING_TOON = 0, GX_SHADING_HIGHLIGHT = 1 } GXShading;

typedef short s16_021DEFD0;

typedef struct { u32 x, y, z; } Vec3;



typedef struct { u32 layer; u8 a,b,c,d; u16 e,pad; } Desc;

typedef struct { int x,y,z; } Vec;

typedef struct { int a[4]; } Descriptor;

typedef struct { int m[9]; } Mtx;

typedef struct { Vec pos,scale; Mtx rot; } Transform;

typedef enum { COUNT_ZERO=0, COUNT_NEGATIVE=-1 } Count;

typedef struct { int active; char rest[0xb0]; } RecordA;

typedef struct { int active; char rest[0x78]; } RecordB;

typedef struct { int active; char rest[0x64]; } RecordC;

typedef struct {
    char pad[0x140];
    RecordA a[5];
    RecordB b[5];
    RecordC c[5];
} PlayerBlock;

typedef enum {INDEX_ZERO=0} Index;

typedef signed short   s16;

typedef struct {u8 pad[0x2c]; int index,count;} Obj;

typedef struct { int active; char rest[0xb0]; } PlayerRecord;

typedef struct { char pad[0x140]; PlayerRecord records[1]; } RecordBlock;

typedef struct { int active, state, x, y, key; } EntryA;

typedef struct { int active, state, x, y, z, key; } EntryB;

typedef struct {unsigned state;int active,other,timer,speed;} PlayerState;

typedef struct { int v[4]; } Table;

typedef struct { u16 state, flag; int count; } ModeState;

typedef struct
{
  int active;
  int a;
  int b;
  int key;
  char rest[0xa4];
} KeyRecord;

typedef struct
{
  char pad[0x140];
  KeyRecord records[1];
} Block;

typedef struct { int a, b; } IntPair;

typedef struct { int a, b, c, d, e; } FiveRecord;

struct RangeU16 { u16 lo, hi; };

struct Entry { unsigned count; struct RangeU16 *ranges; };

extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020414EC(u32);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_020403F4(u32);
extern void func_0203F9B4(void);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32,u32,u32,u32,u32,u32,u16);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u8 *func_02012944(void *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020490F4(u32 id, u32 heap);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern struct FrameObj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct FrameObj *,unsigned int);
extern void CLACT_SetActorAnimSeq(struct FrameObj *p, u16 value);
extern void func_020434DC(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void func_0204B3DC(struct FrameObj *,unsigned int);
extern void BMP_WIN_Init(u16);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintColor(void *, s16_021DD1E0, s16_021DD1E0, void *, void *, u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void BMP_MENU_DeleteYesNo(u8 *o);
extern u32 func_020452E8(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void GFL_NET_SetAutoExit(unsigned char a0);
extern void *func_021DCF50(u8 *p);
extern int UNION_APP_GetMemberCount(unsigned char *p);
extern int UNION_APP_Close(unsigned char *p);
extern void UNION_APP_Open(u8 *p);
extern void func_020061E4(u32 a);
extern struct BmpMenu *BMP_MENU_CreateYesNo(const WinDat *,u16,u8,u8,u16);
extern u32 BMP_MENU_ProcessYesNo(u8 *p);
extern void func_02082BCC(void *,int,unsigned);
extern int func_021DCBC4(void *,int,void *,int);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetUserInfo(char *p, int a, int b, int c);
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void PRINTSYS_PrintStreamStop(void *);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_02008500(void *,void *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u8 UNION_APP_GetJoinedBits(u8 *);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0201F73C(void *, int, int, int);
extern void func_0201CE48(struct Rec3 *p);
extern void *PRINTSYS_PrintStream(void *, int, int, void *, void *, int, void *, int, u16, u16);
extern u32 func_0201CE30(void *p);
extern unsigned int func_0203630C(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern u32 func_020362DC(void);
extern void func_0201CE38(void *);
extern void func_0201F7A8(void *desc, u32 kind);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_0207E51C(void *, int, int);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern void GFL_HEAP_CreateChildHeap(u32 src, u32 dst, u32 size);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_02012934(const struct BigObj *p);
extern void *func_020056A0(void (*)(int,void *),void *,u32);
extern void *G3D_UTIL_Create(u16,u16,u16);
extern u32 func_02030CB0(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(struct PrintSys *);
extern void TIME_ICON_Delete(u8 *);
extern void func_02030DA4(void *);
extern void G3D_UTIL_Delete(struct Rec *p);
extern void G3D_SYSTEM_Exit(void);
extern void func_02030EAC(struct Node *n);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
extern int func_020351A0(u32);
extern void func_02030D28(struct Ctx *c);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 func_0200FB24(void);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_02039C68(struct Link *p, u32 lo, u32 hi);
extern u32 GFL_NET_SendDataMask(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200ED48(void *);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern void func_021E19C0(char *,int);
extern u32 func_020056EC(u32);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02007E50(u8 *, u16, u16, u16);
extern u32 func_02008DF0(struct Sub02008C20Obj *,int);
extern void func_0203516C(u32);
extern void *func_0201088C(unsigned, unsigned);
extern u32 func_02010904(struct Sub0201088CObj *p);
extern u32 func_0200FBB0(void);
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);
extern void WIPE_SetBrightnessFadeOut(unsigned, unsigned);
extern void func_02010934(struct Sub0201088CObj *p);
extern void GFL_NET_COMMAND_DeleteCommandTable(unsigned);
extern void UNION_APP_RequestReset(u8 *p);
extern u32 UNION_APP_IsResetDone(u8 *);
extern void PALANM_TransferPalettes(struct S02021D50 *);
extern void CLACT_VBlankSystem(void);
extern void func_020419E4(void);
extern void func_02048B6C(struct Light *l, const u32 *in);
extern void func_02048AD0(struct Light *l);
extern void func_02047964(void),G3D_SYSTEM_ApplyLookAt(void),G3D_SYSTEM_DrawEnd(void),CLACT_DrawSystem(void);
extern void NNS_G3dGlbLightVector(int,int,int,int),NNS_G3dGlbLightColor(int,u32),NNS_G3dGlbMaterialColorDiffAmb(u32,u32,u32),NNS_G3dGlbMaterialColorSpecEmi(u32,u32,u32);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void TIME_ICON_Update(u8 *p);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void func_0207D63C(unsigned, int, int, int, int);
extern void func_0207DCF8(const u16 *);
extern void G3X_SetClearColor(u16, int, int, int, int);
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16_021DEFD0 heap, void (*setup)(void));
extern void G3D_SYSTEM_SetSwapBuffersMode(u32, u32);
extern void *G3D_CAMERA_Create(u32, u32, u32, u32, u32, u32, u32, u32, Vec3 *, Vec3 *, Vec3 *, u16);
extern void func_0203F8F4(u16);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern void PALANM_BlendChannelMask(u32,u32,u16,u32,u32);
extern s32 func_02062A00(struct NitroFileHeader *file, void **out);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern int func_02062B30(void *,void **);
extern void func_02040AE0(u32,const void *,u32);
extern void *PALANM_Create(u32);
extern void PALANM_SetAutoTransfer(struct PalAnmSlot *,int);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *,u32,u32,u32);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,u32);
extern void PALANM_Delete(struct PalAnmSlot *);
extern int CLACT_RegisterPalette(void *,u32,u32,u32,u16);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02041B6C(u32 bit);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern int TOUCHPANEL_HitTrg(const void *);
extern int G3D_UTIL_AddUnit(void *,const void *);
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);
extern u32 func_02048A18(u8 *a0, int i);
extern void BUTTON_MAN_MakeRotMtxXYZ(int,int,int,struct Mtx33 *);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);
extern void func_0207ADC4(Mtx *);
extern s16 func_0203F63C(u32 x);
extern int func_0203F5FC(u32 x);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern struct Node * func_02030DA8(void *,void (*)(void *,void *),void *,int);
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
extern u32 CLACT_IsActorAnimActive(struct Actor *);
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *, u32);
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *, u32, void *);
extern int func_021DCE00(char *p, int i);
extern void *func_0201AB28(void *, unsigned);
extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern u32 func_0201AA18(void *p);
extern unsigned func_02017E1C(void *, unsigned, unsigned);
extern void GFL_USE_SetBgmPlayerParam(void *);
extern int GFL_USE_PushBgm(void);
extern int func_02005F38(void);
extern int GFL_USE_PopBgm(void);
void func_021DD1E0(void);
void func_021DD2E0(u8 *p,void *q);
void func_021DD380(u8 *p);
void func_021DD3B0(u32 a0);
void func_021DD3D8(void *p,void *arc);
void func_021DD4A8(const u8 *p);
void func_021DD570(u8 *p);
void func_021DD5AC(u8 *p);
void func_021DD638(struct Guru2MainCtx *p);
void func_021DD700(void *p, void *text, void *font);
void func_021DD760(u8 *p);
int func_021DD79C(char *p, int state);
int func_021DD7E4(char *p,int a);
void func_021DD80C(char *p);
void func_021DD924(char *p);
int func_021DD928(char *p,int state);
void func_021DD93C(char *p, int v);
int func_021DD94C(char *p,int state);
int func_021DD970(char *p,int state);
int func_021DD99C(char *p,int state);
int func_021DD9D4(char *p,int state);
int func_021DDAEC(char *p,int state);
int func_021DDB04(char *p, int state);
int func_021DDB90(char *p,int state);
int func_021DDBB0(char *p,int state);
int func_021DDBE8(char *p, int state);
int func_021DDC7C(struct Guru2MainCtx *p,int state);
int func_021DDCB4(struct Guru2MainCtx *p,int state);
int func_021DDCEC(char *p,int state);
int func_021DDD0C(char *p,int state);
int func_021DDD48(char *p,int state);
int func_021DDD80(char *p, int state);
int func_021DDE24(char *p, int state);
int func_021DDE74(char *p,int state);
int func_021DDE94(char *p, int state);
int func_021DDEDC(char *p, int state);
int func_021DDF38(char *p,int state);
int func_021DDF64(char *p,int state);
int func_021DDF84(char *p, int state);
int func_021DDFC0(char *p,int state);
int func_021DDFFC(char *p, int state);
int func_021DE060(char *p);
void func_021DE08C(char *p,int state,int player);
void func_021DE17C(struct Guru2MainCtx *p, int command, int player);
int func_021DE220(void *p);
int func_021DE248(void *window,int unused,u16 color,Context *p);
void func_021DE350(char *a0);
int func_021DE354(void *p);
unsigned func_021DE37C(void *p);
int func_021DE388(char *p);
void func_021DE4B4(char *p, int message, int unused);
int func_021DE55C(char *p);
void func_021DE5C0(u8 *p);
void func_021DE5D0(u8 *p);
void func_021DE6C0(char *p, void *a1);
void func_021DE6DC(u8 *p);
void func_021DE6EC(u8 *p, u8 *q, int i, int j, int unused);
int func_021DE738(FrameObj *obj);
u32 func_021DE7F4(void);
int func_021DE7FC(void *obj,int unused,u8 *q);
int func_021DE960(struct S020315D4 *a, int b, int c, u8 *p);
int func_021DEA0C(int a, int b, int c, u8 *p);
void func_021DEA68(char *p);
int func_021DEA70(u8 *p);
int func_021DEA84(struct Guru2MainCtx *p);
int func_021DEAC8(struct Guru2MainCtx *p);
int func_021DEAE0(struct Guru2MainCtx *p);
void *func_021DEB10(char *p);
int func_021DEB1C(char *p);
int func_021DEB40(char *p);
int func_021DEB74(struct Guru2MainCtx *p);
int func_021DEC08(struct Guru2MainCtx *p);
int func_021DEC38(struct Guru2MainCtx *p);
int func_021DEC64(char *p);
int func_021DEC84(struct Guru2MainCtx *p);
int func_021DECB0(struct Guru2MainCtx3 *p);
int func_021DECCC(struct Guru2MainCtx *p);
int func_021DECF4(u8 *p);
int func_021DED3C(u8 *p);
int func_021DED88(struct Guru2MainCtx *p);
int func_021DEDAC(SlotObj *obj);
int func_021DEE4C(char *p);
int func_021DEED8(char *p);
int func_021DEF14(struct Guru2MainCtx *p);
int func_021DEF3C(struct Guru2MainCtx *p);
void func_021DEF6C(SlotObj *obj);
int func_021DEFB4(char *p);
int func_021DEFD0(int *p);
int func_021DEFE8(int *p);
int func_021DF004(char *p);
int func_021DF01C(u8 *p);
int func_021DF050(struct Guru2MainCtx3 *p);
int func_021DF060(char *p);
int func_021DF1C4(u8 *p);
int func_021DF204(char *p);
int func_021DF22C(SelectObj *obj);
int func_021DF2A0(int *p);
int func_021DF2B8(int *p);
int func_021DF2E0(AngleObj *obj);
int func_021DF370(u8 *p);
int func_021DF3E8(u8 *p);
int func_021DF434(u8 *p);
int func_021DF488(struct Guru2MainCtx *p);
int func_021DF4AC(u8 *p);
int func_021DF548(struct Guru2MainCtx *p);
int func_021DF56C(u8 *p);
int func_021DF598(struct Guru2MainCtx *p);
int func_021DF5B0(u8 *p);
int func_021DF5EC(u8 *p);
int func_021DF648(u8 *p);
int func_021DF6A4(u8 *p);
int func_021DF6B8(struct Guru2MainCtx *p);
int func_021DF6D4(u8 *p);
int func_021DF6FC(u8 *p);
int func_021DF778(char *p);
int func_021DF7A4(int *p);
int func_021DF7CC(int *p);
int func_021DF7E4(void);
void func_021DF7E8(void *arg,struct Guru2MainCtx *p);
void func_021DF800(char *p);
void func_021DF83C(char *p);
void func_021DF864(u8 *p);
void func_021DF984(char *p);
void func_021DF998(char *a0);
void func_021DFA14(char *a0);
void func_021DFA68(void);
void func_021DFAD8(u8 *p);
void func_021DFB60(char *a0);
void func_021DFC74(char *p);
void func_021DFE40(char *p);
void func_021DFE6C(u8 *p,int file);
void func_021DFEA0(u8 *p);
void func_021DFEAC(u8 *p);
void func_021DFEB8(u8 *p);
void func_021DFEC4(char *p);
void func_021DFEFC(char *p);
void func_021DFF20(struct Guru2MainCtx2 *p,int a);
void func_021DFF44(u8 *p);
void func_021DFF70(u8 *p);
void func_021DFFC8(u8 *p);
void func_021DFFF8(u8 *p);
void func_021E00D4(u8 *p);
void func_021E0130(u8 *p,int message);
void func_021E01B0(u8 *p,int message,void *value);
void func_021E026C(u8 *p,int message,unsigned value);
void func_021E0304(u8 *p);
void func_021E0338(u8 *p,int count);
void func_021E03A0(u8 *p);
void func_021E03D8(u8 *p,void *text,int index,int color);
void func_021E0450(u8 *p,void *text,int index,int a);
void func_021E0478(u8 *p,u32 i);
void func_021E04B4(u8 *p);
int func_021E04C4(char *a0);
void func_021E04E0(u8 *p);
void func_021E0554(u8 *p);
void func_021E0570(u8 *p);
void func_021E05D4(u8 *p);
void func_021E0634(u8 *p,int a);
void func_021E0640(u8 *p);
void func_021E0678(char *p);
void func_021E0698(u8 *p);
void func_021E06E0(char *p);
void func_021E073C(char *p);
void func_021E078C(char *p,char *q);
void func_021E07A4(char *p);
void func_021E0848(u8 *p);
void func_021E0980(char *p,int amount);
void func_021E09C0(char *p,int *q,int amount,int extra);
void *func_021E0A44(Obj *p);
void func_021E0B14(char *p,char *q);
void func_021E0B38(char *p,char *q,int amount);
void func_021E0BA4(char *p, char *q);
void func_021E0BC0(char *p,char *q,int i);
void func_021E0C08(char *p,int a,int b,int c,int d,int e,int *q);
void func_021E0C70(struct Node *task,char *p);
int func_021E0CA4(struct Guru2MainCtx *p);
int func_021E0CCC(int *p);
int func_021E0D0C(int *p);
void func_021E0D50(char *p,int *q);
void func_021E0DC0(void *unused,char *p);
void func_021E0DE8(char *p);
void func_021E0E1C(u8 *p);
void func_021E0E2C(char *p,int value);
void func_021E0E50(char *p);
int func_021E0E8C(char *p);
void func_021E0EAC(int *p);
void func_021E0EFC(void *unused,char *p);
void func_021E0F20(char *p);
void func_021E0F54(u8 *p);
void func_021E0F64(char *p, int key);
void func_021E0FAC(int *p);
void func_021E1028(void *unused,char *p);
void func_021E104C(char *p);
void func_021E1080(u8 *p);
void func_021E1090(char *p, int key);
void func_021E10D8(u8 *p,PlayerState *s);
void func_021E11A0(void *unused,u8 *p);
void func_021E11B4(char *p);
void func_021E11E4(u8 *p);
void func_021E11F4(char *p);
int func_021E1204(char *p);
int func_021E1210(char *p);
void func_021E121C(void *task, int *p);
void func_021E129C(char *p);
void func_021E1320(void *task, ModeState *p);
void func_021E13A8(void *unused, char *p);
void func_021E13BC(char *p);
void func_021E13F0(u8 *p);
u16 func_021E1400(char *p);
void func_021E140C(char *p);
void func_021E141C(void *unused, int *p);
void func_021E1468(void *unused, char *p);
void func_021E1488(char *p);
void func_021E14BC(u8 *p);
void func_021E14CC(char *p, char *q);
void func_021E14E4(const char *p);
void func_021E1540(void *task, int *p);
void func_021E1584(char *p, int flag);
void func_021E15DC(int *p, int v);
void func_021E1604(char *p, int v);
int func_021E161C(char *p);
void *func_021E1634(char *p, u32 member, int flag);
void func_021E168C(int *p,int a);
void func_021E1694(char *p, const FiveRecord *q);
char *func_021E16AC(char *p, int n);
char *func_021E16C0(char *p);
int func_021E16C4(char *p, int mask);
int func_021E16D8(const char *p);
int func_021E170C(char *p);
void func_021E172C(char *p,unsigned short *q);
void func_021E1758(char *p, int a1);
int func_021E1768(char *p, int i);
void func_021E1784(char *p, int i);
int func_021E17EC(char *p);
void func_021E180C(int *p,int a,int b);
void func_021E1814(unsigned char *p,u16 *q);
int func_021E1830(char *p, int angle, int index);
int func_021E18CC(void *p);
int func_021E1910(char *p);
int func_021E1954(struct Guru2MainCtx *p);
int func_021E1974(struct Guru2MainCtx *p);
void func_021E1988(unsigned int n);
int func_021E19A4(void);
extern const struct DispConfig d_021E1B70;
extern const struct BgTemplate d_021E1BE0,d_021E1B80,d_021E1BA0,d_021E1BC0,d_021E1C00;
extern const struct Cfg gClActorInitParam;
extern const u32 d_021E1B40[],d_021E1B20[],d_021E1B30[],d_021E1B38[];
extern const u16 d_021E1B08[];
extern const WinDat d_021E1AE8;
extern const u8 d_021E1AF8[];
extern const u16 d_021E1FA0[][5];
extern const char d_021E22B8[];
extern const u16 d_021E1FDC[][5];
extern struct RangeU32 d_021E1F34[];
extern const struct DispVram d_021E1EA4;
extern const u16 d_021E1D90[];
extern const Vec3 d_021E2020;
extern const s16_021DEFD0 d_020A1EB8[];
extern Vec3 d_021E1D00, d_021E1D0C;
extern const struct DispConfig d_021E202C;
extern const struct BgTemplate d_021E204C,d_021E206C,d_021E208C,d_021E20AC,d_021E20CC;
extern const Desc *const d_021E1E30[];
extern const u8 d_021E1CB0[];
extern const Descriptor d_021E20EC[];
extern const int d_021E1DE8[];
extern const struct Setup d_021E1D80;
extern const char d_021E1E60[],d_021E1E70[],d_021E212C[];
extern const Table d_021E203C;
extern const int d_021E2278[];
extern const IntPair d_021E2018;
extern struct Entry d_021E1F04[];
















/*
 * func_0203FC28 0x0203FC28 arm
 * func_0203FCA0 0x0203FCA0 arm
 * func_020414EC 0x020414EC arm
 * func_02040B94 0x02040B94 arm
 * d_021E1B70 0x021E1B70 data a4
 * d_021E1BE0 0x021E1BE0 data a4
 * d_021E1B80 0x021E1B80 data a4
 * d_021E1BA0 0x021E1BA0 data a4
 * d_021E1BC0 0x021E1BC0 data a4
 * d_021E1C00 0x021E1C00 data a4
 */
void func_021DD1E0(void)
{
    struct DispConfig d;
    struct BgTemplate a,b,c,e,f;
    d=d_021E1B70;
    func_0203FC28((struct DispConfig *)&d);
    a=d_021E1BE0;
    func_0203FCA0(4, (const struct BgTemplate *)&a, 0); func_020414EC(4);
    b=d_021E1B80;
    func_0203FCA0(5, (const struct BgTemplate *)&b, 0); func_020414EC(5);
    c=d_021E1BA0;
    func_0203FCA0(6, (const struct BgTemplate *)&c, 0); func_02040B94(4,32,0,114);
    e=d_021E1BC0;
    func_0203FCA0(0, (const struct BgTemplate *)&e, 0); func_020414EC(0);
    f=d_021E1C00;
    func_0203FCA0(1, (const struct BgTemplate *)&f, 0); func_02040B94(0,32,0,114);
}
















/*
 * STRBUF_Create 0x020457B0 arm
 * func_02045CAC 0x02045CAC arm
 * func_02049F78 0x02049F78 arm
 * func_021DE6C0 0x021DE6C0 thumb ov137
 */
void func_021DD2E0(u8 *p,void *q)
{
    int i;
    u32 v;
    for(i=0;i<5;i++) {
        *(u32 *)(p+i*4+68)=(u32)STRBUF_Create(8,114);
        *(u32 *)(p+i*8+312)=0; *(u32 *)(p+i*8+316)=0;
        *(u32 *)(p+i*4+352)=0;
    }
    *(unsigned int *)&((struct Guru2MainCtx *)p)->f5C=(u32)STRBUF_Create(180,114);
    v=(u32)STRBUF_Create(40,114); *(unsigned int *)&((struct Guru2MainCtx *)p)->f60=v;
    *(unsigned int *)&((struct Guru2MainCtx *)p)->f118=0;
    func_02045CAC((struct MsgBank *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->f40),17,(void *)v);
    func_021DE6C0((char *)p,q);
    *(unsigned int *)&((struct Guru2MainCtx *)p)->f18=0; *(unsigned int *)&((struct Guru2MainCtx *)p)->f20=0; *(unsigned int *)&((struct Guru2MainCtx *)p)->f1C=0;
    *(unsigned int *)&((struct Guru2MainCtx *)p)->f24=(u32)func_02049F78(q,2,(u32)(p+40),114);
    ((struct Guru2MainCtx *)p)->f4804=0; *(unsigned int *)&((struct Guru2MainCtx *)p)->fE8=0;
    ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f2C=2;
}















void func_021DD380(u8 *p) {int i;func_021DE6DC(p);func_020307B0(((struct Guru2MainCtx *)p)->f24);for(i=0;i<5;i++)STRBUF_Delete(*(void **)((u32)p+i*4+68));STRBUF_Delete(((struct Guru2MainCtx *)p)->f60);STRBUF_Delete(((struct Guru2MainCtx *)p)->f5C);}















void func_021DD3B0(u32 a0) {func_020403F4(6);func_020403F4(5);func_020403F4(4);func_020403F4(1);func_020403F4(0);func_0203F9B4();}















/*
 * single-function C below is EXACT (52 bytes) at fixed flags, blocker49624.log.
 * typedef unsigned short u16; typedef unsigned int u32;
 * extern u32 ARC_UTIL_LoadMember(void *,void *,u32,u16);
 * extern u32 func_0204968C(u32,void *,void *,u32,u32);
 * u32 func_02049624(void *a,void *b,void *c,void *d,u32 e,u32 f,u16 g) {
 *     u32 r=ARC_UTIL_LoadMember(a,b,f,g); return func_0204968C(r,c,d,e,f);
 * }
 * Blocker symbols: ARC_UTIL_LoadMember 0x0204A1BC arm; func_0204968C 0x0204968C arm.
 * func_02049B68 0x02049B68 arm
 * func_02049658 0x02049658 arm
 * func_020498F4 0x020498F4 arm
 * func_02049B40 0x02049B40 arm
 * func_02049624 0x02049624 arm
 * func_0204989C 0x0204989C arm
 * func_02040588 0x02040588 arm
 * func_0201F5BC 0x0201F5BC thumb
 */
void func_021DD3D8(void *p,void *arc)
{
    func_02049B68(arc,1,0,0,512,114);
    func_02049658(arc,7,1,0,8192,0,114);
    func_020498F4(arc,13,1,0,1536,0,114);
    func_02049B40(23,5,0,416,32,114);
    func_02049B40(30,13,4,0,352,114);
    func_02049624((void *)30,(void *)14,(void *)6,0,0,0,114);
    func_0204989C(30,3,6,0,0,0,114);
    func_0201F5BC(0,1,10,0,114);
    func_0201F5BC(0,31,11,0,114);
    func_02040588(0,1);
    func_02040588(1,1);
    func_02040588(6,1);
}















/*
 * note: 2026-10-05 wave P13 B4: the older draft was DIFF 2/200 (v in r4 instead
 *   of r5). `i = 0;` assigned before `table = ...` (so the counter web starts
 *   while v is live) and `for (; i < 5; ...)` gives EXACT in c99 and c. v is a
 *   plain u8 (the enum local is not needed). Callees: 02008550 returns u8-range
 *   index, 0204B100 returns a pointer, others as in matched callers.
 * func_02012944 0x02012944 thumb
 * func_02008550 0x02008550 thumb
 * func_020490F4 0x020490F4 arm
 * CLACT_InitSystem 0x0204A48C arm
 * CLACT_CreateUnit 0x0204B100 arm
 * CLACT_RegisterCharacter 0x0204A6C8 arm
 * CLACT_RegisterPaletteEx 0x0204AC18 arm
 * CLACT_RegisterCellAnim 0x0204AF28 arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 * gClActorInitParam 0x020A1448 data a4
 * d_021E1B40 0x021E1B40 data a4
 * d_021E1B20 0x021E1B20 data a4
 * d_021E1B30 0x021E1B30 data a4
 * d_021E1B38 0x021E1B38 data a4
 */
void func_021DD4A8(const u8 *p)
{
    u8 v;
    long i;
    u32 a,b;
    const u32 *table;
    void *arc;
    v=func_02008550((const struct Sub0200852CObj *)func_02012944(*(void **)(*(u8 **)(*(u8 **)(p+12)+20)+4)));
    arc=func_020490F4(31,114);
    CLACT_InitSystem(&gClActorInitParam,(u32)d_021E1B40,114);
    *(void **)(p+104)=CLACT_CreateUnit(30,1,114);
    i=0;
    table=d_021E1B20+v;
    a=table[0]; b=table[2];
    for(;i<5;i++) {
        *(int *)(p+i*4+128)=CLACT_RegisterCharacter(arc,a,0,0,114);
        *(int *)(p+i*4+108)=CLACT_RegisterPaletteEx(arc,b,0,(u16)(i*32),0,1,114);
    }
    *(int *)(p+148)=CLACT_RegisterCellAnim(arc,d_021E1B30[v],d_021E1B38[v],114);
    ARC_TOOL_DeleteHandle(arc);
    *(void **)(p+52)=func_020490F4(32,114);
}















void func_021DD570(u8 *p) {int i;u8 *q;ARC_TOOL_DeleteHandle(*(void * *)&((struct Guru2MainCtx *)p)->f34);for(i=0;i<5;i++) {q=(u8 *)((u32)p+i*4);CLACT_ReleaseCharacter(((struct Guru2MainCtx *)q)->f6C);CLACT_ReleasePalette(((struct Guru2MainCtx *)q)->f80);}CLACT_ReleaseCellAnim(((struct Guru2MainCtx *)p)->f94);CLACT_DeleteUnit(((struct Guru2MainCtx *)p)->f68);CLACT_ExitSystem();}














/*
 * CLACT_CreateActor 0x0204B294 arm
 * func_0204B92C 0x0204B92C arm
 * CLACT_SetActorAnimSeq 0x0204B878 arm
 * func_0204B3DC 0x0204B3DC arm
 * func_020434DC 0x020434DC arm
 * BG_SYS_SetSubPlaneVisible 0x02043598 arm
 * d_021E1B08 0x021E1B08 data a2
 */
void func_021DD5AC(u8 *p)
{
    struct { u16 a,b,c; u8 d,e; } s;
    long i;
    s.e=1; s.d=0; s.c=0;
    for(i=0;i<5;i++) {
        s.a=d_021E1B08[i*2+2]; s.b=d_021E1B08[i*2+3];
        *(u32 *)(p+i*4+156)=(u32)(struct Obj *)CLACT_CreateActor((void *)*(unsigned int *)&((struct Guru2MainCtx *)p)->f68,*(u32 *)(p+i*4+128),*(u32 *)(p+i*4+108),((struct Guru2MainCtx *)p)->f94,&s,0,114);
        func_0204B92C((struct FrameObj *)*(u32 *)(p+i*4+156),1);
        CLACT_SetActorAnimSeq((struct FrameObj *)(*(u32 *)(p+i*4+156)),0);
        func_0204B3DC((struct FrameObj *)*(u32 *)(p+i*4+156),0);
    }
    func_020434DC(16,1); BG_SYS_SetSubPlaneVisible(16,0);
}














/*
 * extent: Two-byte alignment padding at 0x021DD6FE.
 */
void func_021DD638(struct Guru2MainCtx *p) {
    BMP_WIN_Init(0x72);
    *(u32 *)&p->fD8=BMP_WIN_Create(5,26,20,6,2,13,1);
    BMP_Clear(func_02045770(p->fD8),0);
    *(u32 *)&p->fD4=BMP_WIN_Create(0,2,19,27,4,13,1);
    BMP_Clear(func_02045770(p->fD4),15);
    *(u32 *)&p->fDC=BMP_WIN_Create(0,3,1,26,2,15,1);
    func_021DD700(p->fDC,p->f60,p->f38);
    *(u32 *)&p->fD0=BMP_WIN_Create(0,2,6,16,11,15,1);
    BMP_Clear(func_02045770(p->fD0),0);
    func_021DE248(p->fD0, 0, 0x480, (Context *)p);
    p->fF8=p->fDC;
    p->fFC=0;
}














void func_021DD700(void *p, void *text, void *font) {
    int width;
    width = func_0201D304(text, (u32)font, 0);
    BMP_Clear(func_02045770(p), 0);
    PRINTSYS_PrintColor(func_02045770(p), (208-width)/2, 1, text, font, 0x480);
    BMP_WIN_TransferChars(p);
    BMP_WIN_MakeScreen(p);
    func_020409B4((u32)func_02045730(p));
}














void func_021DD760(u8 *p) {if(((struct Guru2MainCtx *)p)->fE8!=0)BMP_MENU_DeleteYesNo(((struct Guru2MainCtx *)p)->fE8);func_020452E8(((struct Guru2MainCtx *)p)->fD0);func_020452E8(((struct Guru2MainCtx *)p)->fDC);func_020452E8(((struct Guru2MainCtx *)p)->fD8);func_020452E8(((struct Guru2MainCtx *)p)->fD4);BMP_WIN_Exit();}














int func_021DD79C(char *p, int state) {
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        int zero = 0;
        GFL_NET_SetAutoExit(0);
        if ((unsigned)UNION_APP_GetMemberCount(func_021DCF50((u8 *)p)) >= 2)
            func_021DE4B4(p, 2, zero);
    } else {
        GFL_NET_SetAutoExit(1);
        func_021DE4B4(p, 8, 0);
    }
    func_021DD93C(p, 3);
    return state;
}














/*
 * Lever: nested explicit empty then/else-call plus outer else-call preserves the b-to-next at +0x1c; goto spelling DIFF12/38B.
 * abi: 021DD802 visibly reloads p into r0 for 021DE350; retain that argument despite its empty matched body.
 */
int func_021DD7E4(char *p,int a) {func_021DD80C(p);if(GFL_NET_SYSTEM_GetCurrentAid()==0) {if(func_021DE220(p)==1) {} else func_021DE350(p);}else func_021DE350(p);return a;}














void func_021DD80C(char *p) {
    char *q;
    if (func_021DE7F4()&1) {
        if (GFL_NET_SYSTEM_GetCurrentAid()==0) {
            q=*(char * *)&((struct Guru2MainCtx *)p)->f10;
            if (((struct Guru2MainCtx *)q)->f2C==func_021DE354(p) && *(unsigned int *)&((struct Guru2MainCtx *)q)->f30==0) {
                if (UNION_APP_Close(func_021DCF50((u8 *)p))) {
                    func_020061E4(0x54c);
                    func_021DE4B4(p,3,0);
                    func_021DD93C(p,22);
                }
            } else func_020061E4(0x548);
        }
    } else if (func_021DE7F4()&2) {
        if (GFL_NET_SYSTEM_GetCurrentAid()!=0) {
            if (*(unsigned int *)&((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f28==0) {
                func_021DE4B4(p,4,0);
                func_021DD93C(p,4);
            } else func_020061E4(0x548);
        } else {
            q=*(char * *)&((struct Guru2MainCtx *)p)->f10;
            if (((struct Guru2MainCtx *)q)->f2C==UNION_APP_GetMemberCount(func_021DCF50((u8 *)p)) && *(unsigned int *)&((struct Guru2MainCtx *)q)->f30==0) {
                if (UNION_APP_Close(func_021DCF50((u8 *)p))) {
                    func_021DE4B4(p,4,0);
                    func_021DD93C(p,4);
                    func_020061E4(0x551);
                }
            } else func_020061E4(0x548);
        }
    } else {
        if (*(unsigned int *)&((struct Guru2MainCtx *)p)->f4808==0 && GFL_NET_SYSTEM_GetCurrentAid()==0 &&
            ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f2C==UNION_APP_GetMemberCount(func_021DCF50((u8 *)p)))
            UNION_APP_Open(func_021DCF50((u8 *)p));
    }
}













void func_021DD924(char *p) {}













/*
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 */
int func_021DD928(char *p,int state) {((struct Guru2MainCtx *)p)->f118=2;func_021DD924(p);return state;}














void func_021DD93C(char *p, int v)
{
    ((struct Guru2MainCtx *)p)->f118 = 0x1A;
    ((struct Guru2MainCtx *)p)->f11C = v;
}













int func_021DD94C(char *p,int state) {if(func_021DE55C(p)) ((struct Guru2MainCtx *)p)->f118=((struct Guru2MainCtx *)p)->f11C;func_021DD924(p);return state;}













/*
 * extent: two zero alignment bytes follow the compiled function.
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 */
int func_021DD970(char *p,int state) {if(GFL_NET_SYSTEM_GetCurrentAid()==0)UNION_APP_Open(func_021DCF50((u8 *)p));((struct Guru2MainCtx *)p)->f118=3;func_021DD924(p);return state;}













int func_021DD99C(char *p,int state) {*(struct BmpMenu * *)&((struct Guru2MainCtx *)p)->fE8=BMP_MENU_CreateYesNo(&d_021E1AE8,31,11,0,114);((struct Guru2MainCtx *)p)->f118=5;func_021DD924(p);return state;}













int func_021DD9D4(char *p,int state) {
    unsigned count;
    unsigned result;
    u8 msg[4];
    if (GFL_NET_SYSTEM_GetCurrentAid()!=0) {
        if (*(unsigned int *)&((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f28!=0) {
            if (func_021DE7F4()&0xc3) func_020061E4(0x548);
            func_021DD924(p);
            return state;
        }
    } else {
        if (((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f30!=0) {
            if (func_021DE7F4()&0xc3) func_020061E4(0x548);
            func_021DD924(p);
            return state;
        }
    }
    count=func_021DE354(p);
    if (count!=UNION_APP_GetMemberCount(func_021DCF50((u8 *)p))) {
        func_021DD924(p);
        return state;
    }
    result=BMP_MENU_ProcessYesNo(((struct Guru2MainCtx *)p)->fE8);
    if (result!=-1) {
        if (result==-2) {
            if (GFL_NET_SYSTEM_GetCurrentAid()==0) UNION_APP_Open(func_021DCF50((u8 *)p));
            ((struct Guru2MainCtx *)p)->f118=0;
        } else {
            if (GFL_NET_SYSTEM_GetCurrentAid()==0) {
                func_021DD93C(p,11);
                func_021DE4B4(p,14,0);
            } else {
                func_02082BCC(msg,0,4);
                msg[2]=0;
                msg[0]=GFL_NET_SYSTEM_GetCurrentAid();
                if (func_021DCBC4(((struct Guru2MainCtx *)p)->f10,0x2801,msg,4)) {
                    ((struct Guru2MainCtx *)p)->f4810=1;
                    *(unsigned short *)&((struct Guru2MainCtx *)p)->f4820=0;
                    ((struct Guru2MainCtx *)p)->f118=6;
                } else ((struct Guru2MainCtx *)p)->f118=0;
            }
        }
        ((struct Guru2MainCtx *)p)->fE8=0;
    }
    func_021DD924(p);
    return state;
}













int func_021DDAEC(char *p,int state) {*(unsigned short *)&((struct Guru2MainCtx *)p)->f4820=0;func_021DD924(p);return state;}













int func_021DDB04(char *p, int state) {
    unsigned char buf[4];
    if (((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f38 != UNION_APP_GetMemberCount(func_021DCF50((u8 *)p)) ||
        ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f38 != func_021DE354(p)) {
        ((struct Guru2MainCtx *)p)->f4820 = 0;
        ((struct Guru2MainCtx *)p)->f118 = 8;
        func_021DD924(p);
        return state;
    }
    ++*(volatile s16_021DD1E0 *)&((struct Guru2MainCtx *)p)->f4820;
    if (*(volatile s16_021DD1E0 *)&((struct Guru2MainCtx *)p)->f4820 > 30) {
        int zero = 0;
        func_02082BCC(buf, 0, 4);
        buf[2] = 1;
        buf[0] = GFL_NET_SYSTEM_GetCurrentAid();
        func_021DCBC4(((struct Guru2MainCtx *)p)->f10, 0x2801, buf, 4);
        ((struct Guru2MainCtx *)p)->f4820 = zero;
        ((struct Guru2MainCtx *)p)->f118 = 9;
    }
    func_021DD924(p);
    return state;
}













int func_021DDB90(char *p,int state) {((struct Guru2MainCtx *)p)->f4810=0;func_021DD93C(p,0);func_021DD924(p);return state;}













int func_021DDBB0(char *p,int state) {*(struct BmpMenu * *)&((struct Guru2MainCtx *)p)->fE8=BMP_MENU_CreateYesNo(&d_021E1AE8,31,11,0,114);((struct Guru2MainCtx *)p)->f118=23;func_021DD924(p);return state;}













int func_021DDBE8(char *p, int state) {
    char *q = *(char * *)&((struct Guru2MainCtx *)p)->f10;
    unsigned result;
    if (((struct Guru2MainCtx *)q)->f2C != func_021DE354(p) || *(unsigned int *)&((struct Guru2MainCtx *)q)->f30 != 0) {
        if (func_021DE7F4() & 0xc3) func_020061E4(0x548);
        func_021DD924(p);
        return state;
    }
    result = BMP_MENU_ProcessYesNo(((struct Guru2MainCtx *)p)->fE8);
    if (result != -1) {
        if (result == -2) {
            UNION_APP_Open(func_021DCF50((u8 *)p));
            ((struct Guru2MainCtx *)p)->f118 = 0;
        } else {
            if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
                ((struct Guru2MainCtx *)p)->f118 = 0x18;
                ((struct Guru2MainCtx *)p)->f4812 = func_021DE354(p);
            }
        }
        ((struct Guru2MainCtx *)p)->fE8 = 0;
    }
    func_021DD924(p);
    return state;
}













/*
 * prototype: original cmp r0,#1 at 021DDC96 uses func_021DCBC4's return;
 * retain int return despite the pending void tail-forwarder. Original 021DDCA2
 * supplies r0=1 to GFL_NET_SetLoginOption despite its filed no-argument prototype.
 */
int func_021DDC7C(struct Guru2MainCtx *p,int state) {if(p->f4813==0) {if(func_021DCBC4(p->f10,0x2804,0,0)==1) {p->f118=27;GFL_NET_SetLoginOption(1);}}return state;}













/*
 * extent: two zero alignment bytes follow the compiled function.
 */
int func_021DDCB4(struct Guru2MainCtx *p,int state) {if(GFL_NET_SYSTEM_GetCurrentAid()==0)UNION_APP_GetMemberCount(func_021DCF50((u8 *)p));if(((struct Guru2MainCtx2 *)p->f10)->f20==UNION_APP_GetMemberCount(func_021DCF50((u8 *)p))) p->f118=27;return state;}













int func_021DDCEC(char *p,int state) {func_021DE4B4(p,5,0);func_021DD93C(p,10);func_021DD924(p);return state;}












int func_021DDD0C(char *p,int state) {if(++((struct Guru2MainCtx *)p)->f124>60) {WIPE_SYS_Start(0,0,0,0,16,1,114);state=3;}func_021DD924(p);return state;}












int func_021DDD48(char *p,int state) {*(struct BmpMenu * *)&((struct Guru2MainCtx *)p)->fE8=BMP_MENU_CreateYesNo(&d_021E1AE8,31,11,0,114);((struct Guru2MainCtx *)p)->f118=12;func_021DD924(p);return state;}












int func_021DDD80(char *p, int state) {
    char *q = *(char * *)&((struct Guru2MainCtx *)p)->f10;
    unsigned result;
    if (((struct Guru2MainCtx *)q)->f2C != func_021DE354(p) || *(unsigned int *)&((struct Guru2MainCtx *)q)->f30 != 0) {
        if (func_021DE7F4() & 0xc3) func_020061E4(0x54c);
        func_021DD924(p);
        return state;
    }
    result = BMP_MENU_ProcessYesNo(((struct Guru2MainCtx *)p)->fE8);
    if (result != -1) {
        if (result == -2) {
            ((struct Guru2MainCtx *)p)->f118 = 0;
            UNION_APP_Open(func_021DCF50((u8 *)p));
        } else {
            ((struct Guru2MainCtx *)p)->f118 = 0xd;
            func_021DCBC4(((struct Guru2MainCtx *)p)->f10, 0x2802, 0, 0);
            func_0201F02C(((struct Guru2MainCtx *)p)->f3C, 0, UNION_APP_GetMemberEntry(func_021DCF50((u8 *)p), 0));
        }
        ((struct Guru2MainCtx *)p)->fE8 = 0;
    }
    func_021DD924(p);
    return state;
}












int func_021DDE24(char *p, int state) {
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        func_021DE4B4(p, 5, 0);
    } else {
        func_0201F02C(((struct Guru2MainCtx *)p)->f3C, 0, UNION_APP_GetMemberEntry(func_021DCF50((u8 *)p), 0));
        func_021DE4B4(p, 0x10, 0);
    }
    func_021DD93C(p, 0xe);
    ((struct Guru2MainCtx *)p)->f124 = 0;
    func_021DD924(p);
    return state;
}












int func_021DDE74(char *p,int state) {if(++((struct Guru2MainCtx *)p)->f124>45) ((struct Guru2MainCtx *)p)->f118=15;func_021DD924(p);return state;}












int func_021DDE94(char *p, int state) {
    GFL_NET_HANDLE_GetCurrentHandle();
    ((struct Guru2MainCtx *)p)->f4814 = ((struct Guru2MainCtx *)p)->f480C ^ func_021DE37C(p);
    GFL_NET_HANDLE_SetUserInfo((char *)GFL_NET_HANDLE_GetCurrentHandle(), 0xcf, 0x28, (u16)(((struct Guru2MainCtx *)p)->f4814));
    ((struct Guru2MainCtx *)p)->f118 = 0x10;
    func_021DD924(p);
    return state;
}












int func_021DDEDC(char *p, int state) {
    if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xcf, 0x28) != 0 ||
        ((struct Guru2MainCtx *)p)->f4814 != (func_021DE37C(p) ^ ((struct Guru2MainCtx *)p)->f480C)) {
        GFL_NET_SetAutoExit(0);
        WIPE_SYS_Start(0,0,0,0,0x10,1,0x72);
        state = 3;
    }
    func_021DD924(p);
    return state;
}












int func_021DDF38(char *p,int state) {if(func_021DE55C(p)) {func_021DE4B4(p,7,0);((struct Guru2MainCtx *)p)->f118=18;}func_021DD924(p);return state;}












int func_021DDF64(char *p,int state) {if(func_021DE55C(p)) ((struct Guru2MainCtx *)p)->f118=10;func_021DD924(p);return state;}












int func_021DDF84(char *p, int state) {
    func_021DE4B4(p, 15, 1);
    *(int *)(p + 0x118) = 20;
    GFL_NET_SYSTEM_GetCurrentAid();
    *(int *)(p + 0x481C) = UNION_APP_GetMemberCount(func_021DCF50((u8 *)p));
    *(int *)(p + 0x4818) = 300;
    func_021DD924(p);
    return state;
}












int func_021DDFC0(char *p,int state) {if(((struct Guru2MainCtx *)p)->f481C){if(((struct Guru2MainCtx *)p)->f481C!=(u32)UNION_APP_GetMemberCount(func_021DCF50((u8 *)p))) ((struct Guru2MainCtx *)p)->f481C=0;}((struct Guru2MainCtx *)p)->f118=21;((struct Guru2MainCtx *)p)->f124=0;func_021DD924(p);return state;}












int func_021DDFFC(char *p, int state) {
    if (((struct Guru2MainCtx *)p)->f481C != 0) {
        if (((struct Guru2MainCtx *)p)->f481C != UNION_APP_GetMemberCount(func_021DCF50((u8 *)p)))
            ((struct Guru2MainCtx *)p)->f481C = 0;
    }
    if (--((struct Guru2MainCtx *)p)->f4818 < 0)
        ((struct Guru2MainCtx *)p)->f481C = 0;
    if (++((struct Guru2MainCtx *)p)->f124 > 60 && ((struct Guru2MainCtx *)p)->f481C == 0) {
        ((struct Guru2MainCtx *)p)->f118 = 0;
        GFL_NET_SYSTEM_GetCurrentAid();
    }
    func_021DD924(p);
    return state;
}












int func_021DE060(char *p) {WIPE_SYS_Start(0,0,0,0,16,1,114);*(int *)&((struct Guru2MainCtx *)p)->f8=1;func_021DD924(p);return 3;}












void func_021DE08C(char *p,int state,int player) {
    switch(state) {
    case 2:
        func_021DE5C0((u8 *)p);
        break;
    case 13:
        if (((struct Guru2MainCtx *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Guru2MainCtx *)p)->fE8);
            ((struct Guru2MainCtx *)p)->fE8=0;
        }
        break;
    case 25:
        func_021DE4B4(p,12,0);
        if (((struct Guru2MainCtx *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Guru2MainCtx *)p)->fE8);
            ((struct Guru2MainCtx *)p)->fE8=0;
        }
        break;
    case 19:
        if (((struct Guru2MainCtx *)p)->f4810==1) return;
        func_0201F02C(((struct Guru2MainCtx *)p)->f3C,0,UNION_APP_GetMemberEntry(func_021DCF50((u8 *)p),player));
        if (player==GFL_NET_SYSTEM_GetCurrentAid()) return;
        if (((struct Guru2MainCtx *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Guru2MainCtx *)p)->fE8);
            ((struct Guru2MainCtx *)p)->fE8=0;
        }
        if (GFL_NET_SYSTEM_GetCurrentAid()==0)
            ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f30&=player^0xffff;
        break;
    case 27:
        if (!func_021DE55C(p)) PRINTSYS_PrintStreamStop(((struct Guru2MainCtx *)p)->fF0);
        if (((struct Guru2MainCtx *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Guru2MainCtx *)p)->fE8);
            ((struct Guru2MainCtx *)p)->fE8=0;
        }
        break;
    case 7:
    case 8:
        break;
    default:
        return;
    }
    ((struct Guru2MainCtx *)p)->f118=state;
}












void func_021DE17C(struct Guru2MainCtx *p, int command, int player) {
    void *target;
    if (p->f118 == 3) {
        switch (command) {
        case 1:
            target = UNION_APP_GetMemberEntry(func_021DCF50((u8 *)p), player);
            if (target != 0)
                func_0201F02C(p->f3C, 0, target);
            p->f118 = command;
            ((struct Guru2MainCtx2 *)p->f10)->f2C = UNION_APP_GetMemberCount(func_021DCF50((u8 *)p));
            ((struct Guru2MainCtx2 *)p->f10)->f30 = 0;
            return;
        case 19:
            func_0201F02C(p->f3C, 0, UNION_APP_GetMemberEntry(func_021DCF50((u8 *)p), player));
            if (player != GFL_NET_SYSTEM_GetCurrentAid()) {
                if (GFL_NET_SYSTEM_GetCurrentAid() == 0)
                    ((struct Guru2MainCtx2 *)p->f10)->f30 &= player ^ 0xffff;
                p->f118 = command;
            }
            break;
        }
    } else {
        if (command == 1) {
            ((struct Guru2MainCtx2 *)p->f10)->f30 = 0;
            ((struct Guru2MainCtx2 *)p->f10)->f2C = UNION_APP_GetMemberCount(func_021DCF50((u8 *)p));
        }
    }
}












int func_021DE220(void *p) {int i,n;n=0;for(i=0;i<5;i++) if(UNION_APP_GetMemberEntry(func_021DCF50(p),(u8)i)) n++;return n;}












/*
 * extent: Two-byte alignment padding at 0x021DE34E.
 * lever: Struct members avoid cached element addresses; block scopes and expanding the first y argument settle the two spill slots.
 */
int func_021DE248(void *window,int unused,u16 color,Context *p) {
    int player;
    void *format;
    u16 value;
    void *text;
    int i;
    u16 ink;
    player=GFL_NET_SYSTEM_GetCurrentAid();
    if (!func_021DE388((char *)p)) return 0;
    BMP_Clear(func_02045770(window),0);
    for(i=0;i<5;i++) {
      do {
        if (p->entries[i].current) {
            int y;
            value=func_02008534(p->entries[i].current);
            text=STRBUF_Create(16,0x72);
            func_02008500(p->entries[i].current,p->names[i]);
            func_0201EFA4(p->formatter,0,value,5,2,1);
            format=func_02045EC0(p->bank,1);
            func_0201F250(p->formatter,text,format);
            if (player==i) ink=0x860; else ink=color;
            y=18*i+1;
            PRINTSYS_PrintColor(func_02045770(window),5,18*i+1,p->names[i],p->font,ink);
            PRINTSYS_PrintColor(func_02045770(window),70,y,text,p->font,ink);
            STRBUF_Delete(text);
            do { STRBUF_Delete(format); } while (0);
        }
      } while (0);
    }
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_020409B4(func_02045730(window));
    return 1;
}












void func_021DE350(char *a0) {}












int func_021DE354(void *p) {int i,n;n=0;for(i=0;i<5;i++) if(UNION_APP_GetMemberEntry(func_021DCF50(p),(u8)i)) n++;return n;}












unsigned func_021DE37C(void *p) {return UNION_APP_GetJoinedBits(func_021DCF50(p));}












int func_021DE388(char *p) {
    int changed;
    int i;
    u32 *slot;
    FrameRecord *record;
    changed=0;
    for(i=0;i<5;i++) {
        slot=(u32 *)(p+i*8);
        slot[0x13c/4]=slot[0x138/4];
        slot[0x138/4]=(u32)UNION_APP_GetMemberEntry(func_021DCF50((u8 *)p),(u8)i);
        record=(FrameRecord *)(p+i*16);
        record->previous=record->current;
        if (slot[0x138/4]) {
            record->current.words.a=func_02008530((void *)slot[0x138/4]);
            record->current.words.b=1;
        } else {
            record->current.wide=0;
        }
    }
    for(i=0;i<5;i++) {
        slot=(u32 *)(p+i*8);
        if (slot[0x13c/4]!=slot[0x138/4]) {
            changed=1;
            if (slot[0x138/4]==0) *(u32 *)(p+i*4+0x160)=3;
            else *(u32 *)(p+i*4+0x160)=1;
        } else {
            record=(FrameRecord *)(p+i*16);
            if (record->current.wide!=record->previous.wide) {
                changed=1;
                if (record->current.words.b==0) *(u32 *)(p+i*4+0x160)=3;
                else *(u32 *)(p+i*4+0x160)=1;
            }
        }
    }
    return changed;
}












void func_021DE4B4(char *p, int message, int unused) {
    void *text;
    void *window;
    text = STRBUF_Create(0xb4, 0x72);
    func_02045CAC(*(void * *)&((struct Guru2MainCtx *)p)->f40, message, text);
    func_0201F250(((struct Guru2MainCtx *)p)->f3C, ((struct Guru2MainCtx *)p)->f5C, text);
    STRBUF_Delete(text);
    BMP_Clear(func_02045770(((struct Guru2MainCtx *)p)->fD4), 0xf);
    func_0201F73C(((struct Guru2MainCtx *)p)->fD4, 0, 1, 0xa);
    if (((struct Guru2MainCtx *)p)->fF0 != 0)
        func_0201CE48(((struct Guru2MainCtx *)p)->fF0);
    ((struct Guru2MainCtx *)p)->fF0 = PRINTSYS_PrintStream(((struct Guru2MainCtx *)p)->fD4, 0, 0, ((struct Guru2MainCtx *)p)->f5C, ((struct Guru2MainCtx *)p)->f38, 0, ((struct Guru2MainCtx *)p)->fF4, 0, 0x72, 0xf);
    window = ((struct Guru2MainCtx *)p)->fD4;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_020409B4(func_02045730(window));
}












int func_021DE55C(char *p) {
    int state;
    if (((struct Guru2MainCtx *)p)->fF0 == 0) return 1;
    state = func_0201CE30(((struct Guru2MainCtx *)p)->fF0);
    if (state == 0) {
        if (func_0203630C() & 1)
            func_0201CE5C(((struct Guru2MainCtx *)p)->fF0, 0);
    } else if (state == 1) {
        if (func_020362DC() & 1)
            func_0201CE38(((struct Guru2MainCtx *)p)->fF0);
    } else if (state == 2) {
        func_0201CE48(((struct Guru2MainCtx *)p)->fF0);
        ((struct Guru2MainCtx *)p)->fF0 = 0;
        return 1;
    }
    return 0;
}













/*
 * Addresses are Black-image addresses.
 */
void func_021DE5C0(u8 *p)
{
    func_0201F7A8(((struct Guru2MainCtx *)p)->fD4, 0);
}












void func_021DE5D0(u8 *p)
{
    int i;
    int flag = 0;
    u8 a, b;
    for (i = 0; i < 5; i++) {
        switch(*(u32 *)(p+i*4+0x160)) {
        case 0: break;
        case 1:
            a=func_02008550(*(void **)(p+i*8+0x138));
            b=func_02008554(*(void **)(p+i*8+0x138));
            if (i==GFL_NET_SYSTEM_GetCurrentAid()) {
                CLACT_SetActorAnimSeq((struct FrameObj *)(*(void **)(p+i*4+0x9c)), 4);
            } else {
                func_021DE6EC((u8 *)p,*(u8 **)(p+0x114),i,b,a);
                CLACT_SetActorAnimSeq((struct FrameObj *)(*(void **)(p+i*4+0x9c)), 4);
            }
            func_0204B3DC((struct FrameObj *)(*(void **)(p+i*4+0x9c)), 1);
            *(u32 *)(p+i*4+0x160)=2;
            flag=1;
            break;
        case 2: break;
        case 3:
            if(i==GFL_NET_SYSTEM_GetCurrentAid()) {
                func_02008550(*(void **)(p+i*8+0x138));
                CLACT_SetActorAnimSeq((struct FrameObj *)(*(void **)(p+i*4+0x9c)), 5);
            } else {
                CLACT_SetActorAnimSeq((struct FrameObj *)(*(void **)(p+i*4+0x9c)), 5);
            }
            *(u32 *)(p+i*4+0x160)=0;
            break;
        }
    }
    if(flag) func_020061E4(0x676);
}












void func_021DE6C0(char *p, void *a1) { ((struct Guru2MainCtx *)p)->f110=func_02049F34(32,0,(u32)(p+276),114); }













void func_021DE6DC(u8 *p)
{
    func_020307B0(((struct Guru2MainCtx *)p)->f110);
}












void func_021DE6EC(u8 *p, u8 *q, int i, int j, int unused)
{
    void *r;
    int n;
    func_0207E51C(*(u8 * *)&((struct Guru2MainCtx *)q)->fC + d_021E1AF8[j] * 32, i * 32, 32);
    r = func_02049E34(32, j + 1, 0, (u32)(&n), 114);
    CLACT_TransferCharacter((int)(*(void **)(p + (i + 5) * 4 + 0x6c)), (struct Sub0204A9D0 *)n);
    func_020307B0(r);
}












/*
 * volatile: previous state at +0x4804 is read at 0x021DE764 and 0x021DE7CA.
 */
int func_021DE738(FrameObj *obj)
{
    u8 *p = (u8 *)obj;
    int state;
    state = func_021DE354(p);
    if (state > *(int *)&((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f2C) {
        if (UNION_APP_Close(func_021DCF50(p))) ((struct Guru2MainCtx *)p)->f4808 = 1;
    } else ((struct Guru2MainCtx *)p)->f4808 = 0;
    if (state == obj->previous) return 1;
    switch (state) {
    case 0: break;
    case 1:
        if ((unsigned)UNION_APP_GetMemberCount(func_021DCF50(p)) > 1 || UNION_APP_GetJoinedBits(func_021DCF50(p)) > 1) return 1;
        *(int *)&((struct Guru2MainCtx *)p)->f118 = 17;
        if (((struct Guru2MainCtx *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Guru2MainCtx *)p)->fE8);
            ((struct Guru2MainCtx *)p)->fE8 = 0;
        }
        return 2;
    case 2: case 3: case 4:
        if (state < obj->previous)
            *(int *)&((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f2C = (unsigned)UNION_APP_GetMemberCount(func_021DCF50(p));
        break;
    case 5: break;
    }
    obj->previous = func_021DE354(p);
    return 1;
}










u32 func_021DE7F4(void) { return func_020362DC(); }









int func_021DE7FC(void *obj,int unused,u8 *q)
{
    u8 *p,*s;
    void *r;
    int i,n,player;
    GFL_NET_SetAutoExit(1);
    GFL_HEAP_CreateChildHeap(1,114,0x80000);
    p=PROCSYS_AllocProcWork(obj,0xdac,114);
    i=0;
    func_02082BCC(p,0,0xdac);
    *(u8 * *)&((struct Guru2MainCtx *)q)->f1C=p;
    *(u8 * *)&((struct Guru2MainCtx *)p)->fD8=q;
    ((struct Guru2MainCtx *)p)->fDC=*(void * *)&((struct Guru2MainCtx *)q)->f18;
    ((struct Guru2MainCtx *)p)->f24=func_02012934(((struct Guru2MainCtx2_f14 *)((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fD8)->f14)->f4);
    ((struct Guru2MainCtx *)p)->fD58=func_020490F4(183,114);
    func_021DF800((char *)p);
    ((struct Guru2MainCtx *)p)->fD9C=func_020056A0((void (*)(int,  void *))func_021DF7E8,p,1);
    ((struct Guru2MainCtx *)p)->fAF4=G3D_UTIL_Create(20,11,114);
    func_021E0640(p);func_021E06E0((char *)p);func_021E04E0(p);
    n=0;
    player=GFL_NET_SYSTEM_GetCurrentAid();
    s=p+0xe0;
    q=*(u8 * *)&((struct Guru2MainCtx *)p)->fD8;
    for(;i<5;i++) {
        if(*(unsigned int *)&((struct Guru2MainCtx *)q)->fC&(1<<i)) {if(i==player) break;n++;}
    }
    ((struct Guru2MainCtx3 *)s)->f40=d_021E1FA0[*(int *)&((struct Guru2MainCtx *)q)->f8][n]<<12;
    r=func_02030734(0x8072,func_02030CB0(32),0,d_021E22B8,0x4ec);
    ((struct Guru2MainCtx *)p)->fD94=r;
    ((struct Guru2MainCtx *)p)->fD98=func_02030CBC(32,r);
    func_021E0DE8((char *)p);func_021E0F20((char *)p);func_021E104C((char *)p);func_021E11B4((char *)p);func_021E13BC((char *)p);func_021E1488((char *)p);
    WIPE_SYS_Start(0,1,1,0,8,1,114);
    GFL_NET_SetLoginOption(1);
    return 1;
}








int func_021DE960(struct S020315D4 *a, int b, int c, u8 *p)
{
    func_0201C6EC(*(struct PrintSys **)(p + 0xD38));
    func_0201C4C0(*(struct PrintSys **)(p + 0xD38));
    if (*(u8 **)(p + 0xDA8) != 0) TIME_ICON_Delete(*(u8 **)(p + 0xDA8));
    func_021E0E1C(p);
    func_021E0F54(p);
    func_021E1080(p);
    func_021E11E4(p);
    func_021E13F0(p);
    func_021E14BC(p);
    func_02030DA4(*(void **)(p + 0xD98));
    func_020307B0(*(void **)(p + 0xD94));
    func_021E0678((char *)p);
    func_021E0554(p);
    func_021E073C((char *)p);
    G3D_UTIL_Delete(*(void **)(p + 0xAF4));
    G3D_SYSTEM_Exit();
    func_021DF83C((char *)p);
    func_02030EAC(*(void **)(p + 0xD9C));
    ARC_TOOL_DeleteHandle(*(void **)(p + 0xD58));
    func_020315D4(a);
    func_020306F0(0x72);
    func_020351A0(8);
    return 1;
}








extern int (*const d_021E217C[])(void *);








int func_021DEA0C(int a, int b, int c, u8 *p)
{
    int result;
    do { result = d_021E217C[*(int *)p](p); } while (result == 1);
    if (result == 2) return 1;
    func_021E0570(p);
    func_021E07A4((char *)p);
    func_021DF864(p);
    func_021DEA68((char *)p);
    func_02030D28(((struct Guru2MainCtx *)p)->fD98);
    if (WIPE_SYS_EndCheck() && func_0200FB24()) return 1;
    return 0;
}








void func_021DEA68(char *p) { *(unsigned int *)&((struct Guru2MainCtx *)p)->f34=0;*(unsigned int *)&((struct Guru2MainCtx *)p)->f3C=0; }









int func_021DEA70(u8 *p)
{
    func_021E0130(p, 0);
    *(unsigned int *)&((struct Guru2MainCtx *)p)->f0 = 1;
    return 0;
}








int func_021DEA84(struct Guru2MainCtx *p)
{
    if (WIPE_SYS_EndCheck()) {
        p->f0 = GFL_NET_SYSTEM_GetCurrentAid() == 0 ? 2 : 8;
        p->fDA8 = TIME_ICON_Create(p->fD98, p->fCF0, 15, 16, 114);
        return 1;
    }
    return 0;
}








int func_021DEAC8(struct Guru2MainCtx *p)
{
    if (func_021E16D8((const char *)p)) {
        *(unsigned int *)&p->f0 = 3;
        return 1;
    }
    return 0;
}







int func_021DEAE0(struct Guru2MainCtx *p) {u16 v=1;if(func_021DCBC4(p->fDC,0x2805,&v,2)==1){p->f0=4;return 1;}return 0;}








/*
 * extent: two trailing bytes of zero alignment padding.
 */
void *func_021DEB10(char *p) {return **(void ** *)&((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fD8)->f14;}







int func_021DEB1C(char *p) {unsigned v;v=func_021E170C(p)+1;if(v!=UNION_APP_GetMemberCount(func_021DEB10(p)))return 0;((struct Guru2MainCtx *)p)->f0=5;return 1;}







int func_021DEB40(char *p) {((struct Guru2MainCtx *)p)->f30=func_021E170C(p)+1;if(func_021DCBC4(((struct Guru2MainCtx *)p)->fDC,0x280A,p+48,4)==1){((struct Guru2MainCtx *)p)->f14=0;((struct Guru2MainCtx *)p)->f0=6;}return 0;}







int func_021DEB74(struct Guru2MainCtx *p)
{
    u16 buf[2];
    int i, count;
    u16 mask;
    if (p->f14 == 0) {
        buf[1] = 0; buf[0] = 0;
        if (func_021DCBC4(p->fDC, 10249, buf, 4) == 1) (p->f14)++;
        return 0;
    }
    i = 1;
    mask = ((struct Guru2MainCtx2 *)p->fDC)->f42;
    for (count = 1; i < 5; i++) {
        if (mask & (1 << i)) {
            if (count >= p->f14) {
                buf[1] = i; buf[0] = p->f14;
                if (func_021DCBC4(p->fDC, 10249, buf, 4) == 1) (p->f14)++;
                break;
            }
            count++;
        }
    }
    if (p->f14 >= p->f30) p->f0 = 7;
    return 0;
}







int func_021DEC08(struct Guru2MainCtx *p) {u16 v=8;if(func_021DCBC4(p->fDC,0x2805,&v,2)==1)p->f0=10;return 0;}






int func_021DEC38(struct Guru2MainCtx *p) {if(func_021DCBC4(p->fDC,0x2806,0,0)==1){p->f0=9;*(int *)&p->f10=0;return 0;}return 0;}






int func_021DEC64(char *p) {if(func_021E16C4(p,8)==1){((struct Guru2MainCtx *)p)->f30=func_021E170C(p)+1;((struct Guru2MainCtx *)p)->f0=10;}return 0;}






int func_021DEC84(struct Guru2MainCtx *p) {void *v;v=GFL_NET_HANDLE_GetCurrentHandle();TIME_ICON_Delete(p->fDA8);p->fDA8=0;func_02039C68(v,202,40);p->f0=11;return 0;}






int func_021DECB0(struct Guru2MainCtx3 *p) {if(func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),202,40))p->f0=12;return 0;}






int func_021DECCC(struct Guru2MainCtx *p) {if(func_021DCBC4(p->fDC,0x280B,*(char * *)&p->fD8+4,4))p->f0=13;return 0;}






int func_021DECF4(u8 *p)
{
    void *q;
    q = GFL_NET_HANDLE_GetCurrentHandle();
    if ((int)GFL_NET_SendDataMask((u32)q, (u8)((int)UNION_APP_GetJoinedBits(func_021DEB10((char *)p))), (int)10255, (int)1428, (u32)(((struct Guru2MainCtx *)p)->f24), (int)1, (int)1, (int)1))
        ((struct Guru2MainCtx *)p)->f0 = 14;
    return 0;
}






int func_021DED3C(u8 *p)
{
    if (((struct Guru2MainCtx *)p)->f30 == func_021E17EC((char *)p)) {
        if (func_021E1910((char *)p) == 1) {
            func_021DCBC4(((struct Guru2MainCtx *)p)->fDC, 10253, 0, 0);
            ((struct Guru2MainCtx *)p)->f0 = 45;
        } else {
            func_021DCBC4(((struct Guru2MainCtx *)p)->fDC, 10254, 0, 0);
            ((struct Guru2MainCtx *)p)->f0 = 15;
        }
    }
    return 0;
}





int func_021DED88(struct Guru2MainCtx *p) {if(func_021E1974(p)==1)p->f0=45;else if(p->f30==func_021E1954(p))p->f0=16;return 0;}





int func_021DEDAC(SlotObj *obj)
{
    u8 *p = (u8 *)obj;
    u8 *q;
    int i, count;
    q = (u8 *)func_021E16AC((char *)p, 24);
    *(int *)&((struct Guru2MainCtx *)q)->f10 = *(int *)&((struct Guru2MainCtx *)p)->f2C;
    count = ((struct Guru2MainCtx *)p)->f30;
    ((struct Guru2MainCtx *)q)->f14 = count;
    *(int *)&((struct Guru2MainCtx *)q)->f4 = d_021E1FA0[count][*(int *)&((struct Guru2MainCtx *)p)->f2C];
    for (i = 0; i < 5; i++) {
        if (func_021E1768((char *)p, i)) {
            obj->slots[i] = UNION_APP_GetMemberEntry(func_021DEB10((char *)p), (u8)i);
            func_02008500(obj->slots[i], obj->other[i]);
        }
    }
    func_021DEF6C((SlotObj *)p);
    ((struct Guru2MainCtx *)p)->f120 = *(int *)&((struct Guru2MainCtx *)q)->f4 << 12;
    ((struct Guru2MainCtx *)p)->f0 = 17;
    GFL_USE_CancelChangeAndPlayBgm(1157, 65535);
    ((struct Guru2MainCtx2_f14 *)((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fD8)->f14)->f14 = 1;
    func_021E0304(p);
    return 1;
}





/*
 * extent: unlabelled follower at 021DEED8, filed separately.
 * lever: raw unsigned byte-table address and a named row byte offset restore r6.
 */
int func_021DEE4C(char *p)
{
    int *r;
    int value, a, row;
    if (--((struct Guru2MainCtx *)p)->fC>0) return 0;
    ((struct Guru2MainCtx *)p)->fC=15;
    r=(int *)func_021E16C0(p);
    row=r[5]*10;
    value=*(const u16 *)((unsigned)d_021E1FDC+row+r[4]*2);
    a=*(u16 *)(p+0x7e + r[4]*4);
    *(u16 *)(p+0x60+r[4]*2)=value;
    func_021E0C08(p,a,r[4],r[0],value,r[1],(int *)(p+0x2e0+r[4]*0xb4));
    r[4]++;
    r[4]%=r[5];
    if (++r[0]==r[5]) {
        ((struct Guru2MainCtx *)p)->fC=0;
        ((struct Guru2MainCtx *)p)->f0=18;
    }
    return 0;
}





int func_021DEED8(char *p)
{
    char *q=p+0x1a0;
    int i,n,count;
    count=((struct Guru2MainCtx *)p)->f30;
    i=0;
    n=0;
    do {
        if (*(int *)(q+i*0xb4+0x148)==1) n++;
        i++;
    } while(i<count);
    if (n==count) {((struct Guru2MainCtx *)p)->f0=19;return 1;}
    return 0;
}




int func_021DEF14(struct Guru2MainCtx *p) {if(++p->fC>30){p->fC=0;if(GFL_NET_SYSTEM_GetCurrentAid()==0)p->f0=20;else p->f0=21;}return 0;}




int func_021DEF3C(struct Guru2MainCtx *p) { u16 buf; buf=4; if(func_021DCBC4(p->fDC,0x2805,&buf,2)==1) p->f0=22; return 0; }




void func_021DEF6C(SlotObj *obj)
{
    u8 *p = (u8 *)obj;
    void *q;
    int i;
    q = func_0200ED48(GAME_DATA_GetSaveControl(((struct Guru2MainCtx2_f14 *)((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fD8)->f14)->f4));
    for (i = 0; i < 5; i++) {
        if (obj->slots[i] && i != GFL_NET_SYSTEM_GetCurrentAid())
            func_0200ED54(q, func_02008530(obj->slots[i]));
    }
}




/*
 * trailing: Two zero alignment bytes.
 */
int func_021DEFB4(char *p) { if(func_021E16C4(p,4)==1) { ((struct Guru2MainCtx *)p)->f0=22; return 1; } return 0; }







int func_021DEFD0(int *p) { func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),203,40); *p=23; return 0; }







int func_021DEFE8(int *p) { if(func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),203,40)) *p=24; return 0; }







int func_021DF004(char *p) { func_021E1584(p,1); func_021E129C(p); ((struct Guru2MainCtx *)p)->f0=25; return 0; }







int func_021DF01C(u8 *p) { int i; ((struct Guru2MainCtx *)p)->fC+=1; if(((struct Guru2MainCtx *)p)->fC<95) return 0; for(i=0;i<((struct Guru2MainCtx *)p)->f30;i++) func_021E0478(p,i); ((struct Guru2MainCtx *)p)->fC=0; ((struct Guru2MainCtx *)p)->f0=26; return 0; }








int func_021DF050(struct Guru2MainCtx3 *p)
{
    GFL_NET_SYSTEM_GetCurrentAid();
    *(unsigned int *)&p->f0 = 0x1b;
    return 0;
}







int func_021DF060(char *p)
{
    char *s;
    Msg msg;
    int state,i,rate;
    state=func_021E161C(p);
    if(state==1 && func_021E1210(p)==0 && ((struct Guru2MainCtx2 *)p)->f5C==0) ((struct Guru2MainCtx2 *)p)->f20=1;
    if(((struct Guru2MainCtx2 *)p)->f6A==1) {*(int *)&((struct Guru2MainCtx2 *)p)->f0=28;return 1;}
    if(state==0) {
        if(((struct Guru2MainCtx2 *)p)->f34 && func_021E1210(p)==0) func_021E11F4(p);
        if(func_021E1400(p)==0 && func_021E04C4(p)==1) {
            if(func_021E1210(p)==0) *(int *)&((struct Guru2MainCtx2 *)p)->f38=1;
            func_021E140C(p);
        }
        if(*(int *)&((struct Guru2MainCtx2 *)p)->f38) {
            if(func_021DCBC4(((struct Guru2MainCtx2_fD8 *)((struct Guru2MainCtx2 *)p)->fD8)->f18,0x2807,p+0x38,1)==1) *(int *)&((struct Guru2MainCtx2 *)p)->f38=0;
        }
    }
    s=p+0xe0;
    if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
        if(((struct Guru2MainCtx2 *)p)->f8<300) {
            ((struct Guru2MainCtx *)s)->f48+=95;
            if(((struct Guru2MainCtx *)s)->f48>=0x7000) ((struct Guru2MainCtx *)s)->f48=0x7000;
        } else {
            ((struct Guru2MainCtx *)s)->f48-=95;
            if(((struct Guru2MainCtx *)s)->f48<0x4000) ((struct Guru2MainCtx *)s)->f48=0x4000;
        }
    }
    if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
        msg.a=((struct Guru2MainCtx2 *)p)->f11C;
        msg.flag=((struct Guru2MainCtx2 *)p)->f20;
        msg.b=((struct Guru2MainCtx2 *)p)->f33C;
        for(i=0;i<*(int *)&((struct Guru2MainCtx2 *)p)->f30;i++) msg.values[i]=*(int *)(p+i*0xb4+0x2fc)/4096;
        func_021DCBC4(((struct Guru2MainCtx2 *)p)->fDC,0x2808,&msg,20);
    }
    if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
        rate=((struct Guru2MainCtx2 *)p)->f128;
        if(func_021E1204(p)==1) func_021E0634((u8 *)(p+0xe0),rate*2);
        else func_021E1604(p,rate);
    }
    return 0;
}







int func_021DF1C4(u8 *p)
{
    func_021E1584((char *)p, 0);
    *(u8 * *)&((struct Guru2MainCtx *)p)->f28 = func_021E0A44((Obj *)p);
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        if (((struct Guru2MainCtx_f28 *)((struct Guru2MainCtx *)p)->f28)->fC == GFL_NET_SYSTEM_GetCurrentAid())
            ((struct Guru2MainCtx *)p)->f0 = 29;
        else
            ((struct Guru2MainCtx *)p)->f0 = 30;
    } else {
        ((struct Guru2MainCtx *)p)->f0 = 31;
    }
    func_020061E4(1833);
    return 1;
}







int func_021DF204(char *p) { func_021E19C0(p,0x4000); *(u8 * *)&((struct Guru2MainCtx2 *)p)->f28=func_021E0A44((Obj *)p); if(((struct Guru2MainCtx2_f28 *)((struct Guru2MainCtx2 *)p)->f28)->fC!=GFL_NET_SYSTEM_GetCurrentAid()) *(int *)&((struct Guru2MainCtx2 *)p)->f0=30; return 0; }







#pragma opt_propagation off







/*
 * note 2026-10-05 (wave P17 L7, final push G6L7): DIFF 26/116, obj/step/target colour
 * rotation and index load order; about 60 forms tried (see git history of the pending copy).
 *
 * pass 2 2026-10-06 P2L39: EXACT in --lang c99 and --lang c. Under #pragma opt_propagation
 * off, all locals declared at the top (target before step), with step assigned before
 * target: this gives obj r6, step r5, target r4. A named table pointer local assigned first
 * keeps the table load live across the multiply (table r4), which lets count be a named
 * local without a copy before muls. The reads in the order index, selected, count, angle
 * give the low colours (angle r1, count r2, index r3).
 */
int func_021DF22C(SelectObj *obj)
{
    Selected *sel;
    int current, index, count;
    int target, step;
    int angle, delta;
    const u16 (*table)[5];
    table = d_021E1FDC;
    index = obj->index;
    sel = obj->selected;
    count = obj->count;
    current = sel->angle;
    step = 0x4000;
    target = table[count][index] << 12;
    angle = current;
    delta = target - current;
    if (delta < 0) delta = target + 0x168000 - current;
    if (delta <= 0x10000) step >>= 1;
    if (delta < step) step = delta;
    func_021E19C0((char *)obj, step);
    func_021E15DC(&angle, step);
    if (angle / 4096 == target / 4096) obj->state = 31;
    return 0;
}







#pragma opt_propagation reset







int func_021DF2A0(int *p) { func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),204,40); *p=32; return 0; }







int func_021DF2B8(int *p) { if(func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),204,40)) { if(GFL_NET_SYSTEM_GetCurrentAid()==0) *p=33; else *p=34; } return 0; }







int func_021DF2E0(AngleObj *obj)
{
    u8 *p = (u8 *)obj;
    struct { u16 angle, mask, entries[6]; } buf;
    int i;
    u8 *q;
    buf.angle = *(int *)&((struct Guru2MainCtx *)p)->f58 / 4096;
    ((struct Guru2MainCtx *)p)->f1C = 0;
    for (i = 0; i < ((struct Guru2MainCtx *)p)->f30; i++) {
        q = p + 0x2e0 + i * 180;
        {
        int angle;
        angle = obj->angles[i];
        buf.entries[*(int *)&((struct Guru2MainCtx *)q)->f10] = angle;
        if (func_021E1830((char *)p, angle << 12, ((struct Guru2MainCtx *)p)->f30) == 1)
            ((struct Guru2MainCtx *)p)->f1C |= 1 << ((struct Guru2MainCtx *)q)->fC;
        }
    }
    buf.mask = ((struct Guru2MainCtx *)p)->f1C;
    if (func_021DCBC4(((struct Guru2MainCtx *)p)->fDC, 10252, &buf, 16) == 1) ((struct Guru2MainCtx *)p)->f0 = 35;
    return 0;
}







int func_021DF370(u8 *p)
{
    int i;
    u8 *entry;
    u16 *values;
    if (((struct Guru2MainCtx *)p)->f40 == 1) {
        values = (u16 *)(p + 108);
        ((struct Guru2MainCtx *)p)->f11C = values[0] << 12;
        *(int *)&((struct Guru2MainCtx *)p)->f58 = values[0] << 12;
        for (i = 0; i < ((struct Guru2MainCtx *)p)->f30; i++) {
            entry = p + 736 + i * 180;
            ((struct Guru2MainCtx *)entry)->f1C = values[*(int *)&((struct Guru2MainCtx *)entry)->f10 + 2] << 12;
            *(u16 *)(p + 96 + i * 2) = values[*(int *)&((struct Guru2MainCtx *)entry)->f10 + 2];
        }
        ((struct Guru2MainCtx *)p)->f1C = values[1];
        func_021E0570(p);
        func_021E07A4((char *)p);
        *(u8 * *)&((struct Guru2MainCtx *)p)->f28 = func_021E0A44((Obj *)p);
        ((struct Guru2MainCtx *)p)->f0 = 35;
    }
    return 0;
}







int func_021DF3E8(u8 *p)
{
    int index, i, count, selected;
    index = (*(int * *)&((struct Guru2MainCtx *)p)->f28)[4];
    *(int *)&((struct Guru2MainCtx *)p)->f5C = 0;
    for (i = 0; i < ((struct Guru2MainCtx *)p)->f30; i++) {
        selected = *(int *)(p + 748 + index * 180);
        func_021E0450(p, (void *)(*(int *)(p + 164 + selected * 4)), i, selected);
        count = ((struct Guru2MainCtx *)p)->f30;
        index = (index + 1) % count;
    }
    ((struct Guru2MainCtx *)p)->fC = 0;
    ((struct Guru2MainCtx *)p)->f0 = 36;
    return 0;
}







int func_021DF434(u8 *p)
{
    int i;
    ((struct Guru2MainCtx *)p)->fC += 1;
    if (((struct Guru2MainCtx *)p)->fC < 120) return 0;
    ((struct Guru2MainCtx *)p)->fC = 0;
    for (i = 0; i < ((struct Guru2MainCtx *)p)->f30; i++) func_021E0478(p, i);
    func_021E01B0(p, 2, (void *)(*(int *)(p + 144 + 4 * (*(int * *)&((struct Guru2MainCtx *)p)->f28)[3])));
    func_021E1988(1302);
    ((struct Guru2MainCtx *)p)->f0 = 37;
    return 0;
}







int func_021DF488(struct Guru2MainCtx *p) { if(p->fC<120) p->fC+=1; else if(!func_021E19A4()) { p->fC=0; p->f0=38; } return 0; }







/*
 * lever: Mutable range table is reloaded after RNG; updating low in place preserves r4/r5 colouring.
 */
int func_021DF4AC(u8 *p)
{
    u32 low, high, value;
    int count;
    func_021E14E4((const char *)p);
    if ((*(unsigned int *)&((struct Guru2MainCtx *)p)->f1C & (1 << (*(int * *)&((struct Guru2MainCtx *)p)->f28)[3])) == 0) {
        ((struct Guru2MainCtx *)p)->f0 = 42;
        return 0;
    }
    count = ((struct Guru2MainCtx *)p)->f30;
    low = d_021E1F34[count].low;
    high = d_021E1F34[count].high;
    low += func_020056EC(65535) % (high - low + 1);
    if (low < d_021E1F34[count].low) low = d_021E1F34[count].low;
    else if (low > high) low = high;
    func_021E026C(p, 3, low);
    value = func_02007E50(func_0201292C((((struct Guru2MainCtx2_f14 *)((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fD8)->f14)->f4)), low, 1, 114);
    func_021E1988(1302);
    if (value == 1) ((struct Guru2MainCtx *)p)->f0 = 39;
    else ((struct Guru2MainCtx *)p)->f0 = 40;
    return 0;
}







int func_021DF548(struct Guru2MainCtx *p) { if(p->fC<180) p->fC+=1; if(!func_021E19A4()) { p->fC=0; p->f0=42; } return 0; }







int func_021DF56C(u8 *p)
{
    if (((struct Guru2MainCtx *)p)->fC < 180) {
        ((struct Guru2MainCtx *)p)->fC += 1;
    } else if (func_021E19A4() == 0) {
        ((struct Guru2MainCtx *)p)->fC = 0;
        ((struct Guru2MainCtx *)p)->f0 = 41;
        func_021E0130(p, 4);
    }
    return 0;
}







int func_021DF598(struct Guru2MainCtx *p)
{
    if (p->fC < 180) {
        p->fC += 1;
    } else {
        p->fC = 0;
        p->f0 = 42;
    }
    return 0;
}







int func_021DF5B0(u8 *p) { struct Link *link; link=(struct Link *)GFL_NET_HANDLE_GetCurrentHandle(); func_02008DF0(*(struct Sub02008C20Obj * *)&((struct Guru2MainCtx2_f14 *)((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fD8)->f14)->f10,90); func_021E0130(p,11); func_02039C68(link,205,40); ((struct Guru2MainCtx *)p)->f0=43; func_0203516C(8); return 0; }







int func_021DF5EC(u8 *p)
{
    if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 205, 40)) {
        func_021E1784((char *)p, (*(int * *)&((struct Guru2MainCtx *)p)->f28)[3]);
        ((struct Guru2MainCtx *)p)->fDA0 = func_0201088C(114, (*(unsigned **)(*(u8 * *)&((struct Guru2MainCtx *)p)->fD8 + 20))[1]);
        ((struct Guru2MainCtx *)p)->fDA8 = TIME_ICON_Create(((struct Guru2MainCtx *)p)->fD98, ((struct Guru2MainCtx *)p)->fCF0, 15, 16, 114);
        ((struct Guru2MainCtx *)p)->f0 = 44;
    }
    return 0;
}







/*
 *   extern void func_020307B0(void *);
 *   void func_02010934(void *p) { func_020307B0(p); }
 * tail: 021DF6A2..021DF6A4 is two zero alignment bytes.
 */
int func_021DF648(u8 *p)
{
    int ready;
    ready = func_02010904(*(void **)(p + 3488));
    if (func_0200FB24()) {
        func_0200FBB0();
        GFL_NET_ERR_ShowScreen(1);
        WIPE_SetBrightnessFadeOut(0, 0);
        WIPE_SetBrightnessFadeOut(1, 0);
        return 0;
    }
    if (ready) {
        TIME_ICON_Delete(*(void **)(p + 3496));
        *(void **)(p + 3496) = 0;
        func_02010934(*(void **)(p + 3488));
        *(int *)p = 47;
    }
    return 0;
}







int func_021DF6A4(u8 *p){func_021E0130(p,12);((struct Guru2MainCtx *)p)->f0=46;return 0;}







/*
 * follower: unlabelled timer inside handed 021DF6A4 extent, followed by 2-byte zero padding.
 */
int func_021DF6B8(struct Guru2MainCtx *p){if(++p->fC>=180){p->fC=0;p->f0=47;return 1;}return 0;}







int func_021DF6D4(u8 *p){void *ctx=GFL_NET_HANDLE_GetCurrentHandle();if(!((struct Guru2MainCtx *)p)->f18)func_02039C68(ctx,206,40);func_021E0130(p,10);((struct Guru2MainCtx *)p)->f0=48;return 0;}







int func_021DF6FC(u8 *p)
{
    void *ctx;
    ctx = GFL_NET_HANDLE_GetCurrentHandle();
    if (((struct Guru2MainCtx *)p)->f18 == 0) {
        if (func_02039CB4(ctx, 206, 40)) {
            ((struct Guru2MainCtx *)p)->fDA8 = TIME_ICON_Create(((struct Guru2MainCtx *)p)->fD98, ((struct Guru2MainCtx *)p)->fCF0, 15, 16, 114);
            GFL_NET_SetLoginOption(0);
            GFL_NET_COMMAND_DeleteCommandTable(10240);
            UNION_APP_RequestReset(func_021DEB10((char *)p));
            ((struct Guru2MainCtx *)p)->f0 = 49;
        }
    } else {
        ((struct Guru2MainCtx *)p)->fC += 1;
        if (((struct Guru2MainCtx *)p)->fC >= 180) {
            ((struct Guru2MainCtx *)p)->fC = 0;
            if ((*(int * *)&((struct Guru2MainCtx *)p)->fDC)[15] == 0) GFL_NET_SetAutoExit(0);
            ((struct Guru2MainCtx *)p)->f0 = 49;
        }
    }
    return 0;
}







int func_021DF778(char *p){if(UNION_APP_IsResetDone(func_021DEB10(p))){TIME_ICON_Delete(((struct Guru2MainCtx *)p)->fDA8);((struct Guru2MainCtx *)p)->fDA8=0;((struct Guru2MainCtx *)p)->f0=50;return 1;}return 0;}







int func_021DF7A4(int *p){WIPE_SYS_Start((void *)2,0,0,0,8,1,114);*p=51;return 0;}







int func_021DF7CC(int *p){if(WIPE_SYS_EndCheck()){*p=52;return 1;}return 0;}







int func_021DF7E4(void){return 2;}







void func_021DF7E8(void *arg,struct Guru2MainCtx *p){PALANM_TransferPalettes(*(struct S02021D50 * *)&p->fD78);CLACT_VBlankSystem();func_020419E4();}







void func_021DF800(char *p){func_021DF984(p);func_021DFAD8((u8 *)p);func_021DFB60(p);func_021DFEC4(p);func_021DFF44((u8 *)p);func_021DFC74(p);func_021DFFF8((u8 *)p);func_021DFF70((u8 *)p);func_021DF998(p);}







void func_021DF83C(char *p){func_021DFA14(p);func_021DFFC8((u8 *)p);func_021E00D4((u8 *)p);func_021DFE40(p);func_021DFEFC(p);func_021E04B4((u8 *)p);}







/*
 * omits func_02048B6C from function: and its shard. tu --suggest-split leaves caller OUT.
 * typedef unsigned int u32;
 * void func_02048B6C(char *p,const u32 *in) {*(u32 *)(p+0x18)=*in;}
 */
void func_021DF864(u8 *p)
{
    u32 flags=0x1000000;
    void *r;
    int i;
    func_02048B6C(*(void **)(p+0xd54),&flags);
    func_02047964();
    func_02048AD0(*(void **)(p+0xd54));
    G3D_SYSTEM_ApplyLookAt();
    NNS_G3dGlbLightVector(0,0,-4096,0);
    NNS_G3dGlbLightColor(0,0x7fff);
    NNS_G3dGlbMaterialColorDiffAmb(0x7fff,0x7fff,0);
    NNS_G3dGlbMaterialColorSpecEmi(0x7fff,0x7fff,0);
    func_021E0698(p);func_021E05D4(p);func_021E0848(p);
    G3D_SYSTEM_DrawEnd();CLACT_DrawSystem();
    PRINTSYS_QUE_Main(*(void **)(p+0xd38));
    r=*(void **)(p+0xd38);
    if(*(u8 *)(p+0xd0c)) {
        if(!func_0201C6C4(r,func_02045770(*(void **)(p+0xd08)))) {
            BMP_WIN_TransferChars(*(void **)(p+0xd08));
            *(u8 *)(p+0xd0c)=0;
        }
    }
    for(i=0;i<5;i++) {
        r=*(void **)(p+0xd38);
        if(*(u8 *)(p+i*8+0xd14)) {
            if(!func_0201C6C4(r,func_02045770(*(void **)(p+i*8+0xd10)))) {
                BMP_WIN_TransferChars(*(void **)(p+i*8+0xd10));
                *(u8 *)(p+i*8+0xd14)=0;
            }
        }
    }
    if(*(void **)(p+0xda8)) TIME_ICON_Update(*(void **)(p+0xda8));
}







void func_021DF984(char *p){BG_SYS_SetVramBanks(&d_021E1EA4);BMP_WIN_Init(114);}







static inline void G2_SetBG0Priority(int priority)
{
    *(volatile u16 *)0x04000008 = (u16)((*(volatile u16 *)0x04000008 & ~3) | priority);
}







/*
 * volatile: BG0CNT 0x04000008 read at 021DF9F2, written 021DF9FC.
 */
void func_021DF998(char *a0)
{
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 1);
    func_02040588(7, 1);
    func_020434DC(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    G2_SetBG0Priority(1);
    func_0207D63C(0x04000050, 4, 40, 11, 10);
}







void func_021DFA14(char *a0)
{
    func_02040588(0, 0);
    func_02040588(1, 0);
    func_02040588(2, 0);
    func_02040588(3, 0);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_020434DC(16, 0);
    BG_SYS_SetSubPlaneVisible(16, 0);
}







static inline void G3X_SetShading(GXShading shading)
{
    DISP3D = (u16)((DISP3D & ~(2 | 0x1000 | 0x2000)) | (shading << 1));
}







static inline void G3X_AntiAlias(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 16);
    else DISP3D &= (u16)~0x3010;
}







static inline void G3X_AlphaTest(int enable, int ref)
{
    if (enable) {
        DISP3D = (u16)((DISP3D & ~0x3000) | 4);
        *(volatile u16 *)0x04000340 = (u16)ref;
    } else DISP3D &= (u16)~0x3004;
}







static inline void G3X_AlphaBlend(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 8);
    else DISP3D &= (u16)~0x3008;
}







static inline void G3X_EdgeMarking(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 32);
    else DISP3D &= (u16)~0x3020;
}







/*
 * volatile: DISP3DCNT 0x04000060 re-read at 021DFA70,76,82,8A,96; GXSTAT written 021DFABA.
 */
void func_021DFA68(void)
{
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(1);
    G3X_AlphaTest(0, 0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(1);
    func_0207DCF8(d_021E1D90);
    G3X_SetClearColor(0x7fff, 0, 0x7fff, 63, 0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
}







void func_021DFAD8(u8 *p)
{
    u8 *section;
    Vec3 position;
    section = p + 3392;
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, 114, func_021DFA68);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
    position = d_021E2020;
    *(void * *)&((struct Guru2MainCtx *)section)->f14 = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 4096, 0x400000, 0, &d_021E1D00, &position, &d_021E1D0C, 114);
    func_02048AD0(*(void * *)&((struct Guru2MainCtx *)section)->f14);
}







/*
 * volatile: 021DFB6E reads and 021DFB76 writes hardware register 04000304
 */
void func_021DFB60(char *a0)
{
    func_0203F8F4(114);
    *(volatile u16 *)0x04000304 |= 0x8000;
    {struct DispConfig t=d_021E202C; func_0203FC28((struct DispConfig *)&t);}
    {struct BgTemplate t=d_021E204C; func_0203FCA0(1, (const struct BgTemplate *)&t, 0); func_020414EC(1); func_02040B94(1,32,0,114);}
    {struct BgTemplate t=d_021E206C; func_0203FCA0(2, (const struct BgTemplate *)&t, 0); func_020414EC(2);}
    {struct BgTemplate t=d_021E208C; func_0203FCA0(3, (const struct BgTemplate *)&t, 0); func_020414EC(3);}
    {struct BgTemplate t=d_021E20AC; func_0203FCA0(6, (const struct BgTemplate *)&t, 0); func_020414EC(6);}
    {struct BgTemplate t=d_021E20CC; func_0203FCA0(7, (const struct BgTemplate *)&t, 0); func_020414EC(7);}
}







void func_021DFC74(char *p)
{
    void *buf;
    u8 *data;
    buf=func_021E1634(p,17,0);
    func_02062A98(buf,(void **)(p+0xd64));
    PALANM_CopyToSlot(((struct Guru2MainCtx *)p)->fD78,((struct Guru2MainCtx_fD64 *)((struct Guru2MainCtx *)p)->fD64)->fC,0,0,64);
    func_020307B0(buf);
    buf=func_021E1634(p,20,0);
    func_02062A98(buf,(void **)(p+0xd64));
    PALANM_CopyToSlot(((struct Guru2MainCtx *)p)->fD78,((struct Guru2MainCtx_fD64 *)((struct Guru2MainCtx *)p)->fD64)->fC,1,0,64);
    func_020307B0(buf);
    PALANM_BlendChannelMask(*(u32 *)&((struct Guru2MainCtx *)p)->fD78,1,65535,8,0);
    buf=func_021E1634(p,16,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD60;
    func_02040B1C(3,*(void * *)&((struct Guru2MainCtx *)data)->f14,*(unsigned int *)&((struct Guru2MainCtx *)data)->f10,0);
    func_020307B0(buf);
    buf=func_021E1634(p,22,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD60;
    func_02040B1C(6,*(void * *)&((struct Guru2MainCtx *)data)->f14,*(unsigned int *)&((struct Guru2MainCtx *)data)->f10,0);
    func_020307B0(buf);
    buf=func_021E1634(p,21,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD60;
    func_02040B1C(7,*(void * *)&((struct Guru2MainCtx *)data)->f14,*(unsigned int *)&((struct Guru2MainCtx *)data)->f10,0);
    func_020307B0(buf);
    buf=func_021E1634(p,19,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD5C;
    func_02040AE0(2,data+12,*(unsigned int *)&((struct Guru2MainCtx *)data)->f8);
    func_020409B4(2);
    func_020307B0(buf);
    buf=func_021E1634(p,18,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD5C;
    func_02040AE0(3,data+12,*(unsigned int *)&((struct Guru2MainCtx *)data)->f8);
    func_020409B4(3);
    func_020307B0(buf);
    buf=func_021E1634(p,24,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD5C;
    func_02040AE0(6,data+12,*(unsigned int *)&((struct Guru2MainCtx *)data)->f8);
    func_020409B4(6);
    func_020307B0(buf);
    buf=func_021E1634(p,23,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD5C;
    func_02040AE0(7,data+12,*(unsigned int *)&((struct Guru2MainCtx *)data)->f8);
    func_020409B4(7);
    func_020307B0(buf);
}







void func_021DFE40(char *p){BMP_WIN_Exit();func_020403F4(1);func_020403F4(2);func_020403F4(3);func_020403F4(6);func_020403F4(7);func_0203F9B4();}







/*
 * followers: 021DFEA0,021DFEAC,021DFEB8 are pooled tail-call stubs; parent cleared ownership.
 */
void func_021DFE6C(u8 *p,int file)
{
    void *buf;
    u8 *screen;
    buf=func_021E1634((char *)p,file,0);
    func_02062B30(buf,(void **)(p+3420));
    screen=*(u8 * *)&((struct Guru2MainCtx *)p)->fD5C;
    func_02040AE0(6,screen+12,((struct Guru2MainCtx2 *)screen)->f8);
    func_020409B4(6);
    func_020307B0(buf);
}







void func_021DFEA0(u8 *p) { func_021DFE6C(p,26); }







void func_021DFEAC(u8 *p) { func_021DFE6C(p,24); }







void func_021DFEB8(u8 *p) { func_021DFE6C(p,25); }







void func_021DFEC4(char *p){*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78=PALANM_Create(114);PALANM_SetAutoTransfer(*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78,1);PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78,0,512,114);PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78,1,512,114);}







void func_021DFEFC(char *p){PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78,0);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78,1);PALANM_Delete(*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78);}







void func_021DFF20(struct Guru2MainCtx2 *p,int a){PALANM_BlendChannelMask(p->fD78,1,65535,(u8)a,0);}







/*
 * blocking: ABS32 data gClActorInitParam at +0x20 has no witness outside 021DFF44..021DFF70; ROM pool at021DFF64 is020A1448. Alignment-only data a4 hint already used; one recheck and tu --suggest-split remain MATCH with zero witnesses. Both ARM9 callees resolve matched.
 */
void func_021DFF44(u8 *p){CLACT_InitSystem(&gClActorInitParam,0x021E1EA4,114);*(struct Bank **)(p+0xd68)=CLACT_CreateUnit(30,1,114);}







void func_021DFF70(u8 *p)
{
    void *arc;
    arc = func_020490F4(184,114);
    *(int *)&((struct Guru2MainCtx *)p)->fD6C = CLACT_RegisterCharacter(arc,6,0,0,114);
    *(int *)&((struct Guru2MainCtx *)p)->fD70 = CLACT_RegisterPalette(arc,0,0,0,114);
    *(int *)&((struct Guru2MainCtx *)p)->fD74 = CLACT_RegisterCellAnim(arc,10,14,114);
    ARC_TOOL_DeleteHandle(arc);
    GFL_NET_RestartWithDefaultTimeout(1,114);
}







void func_021DFFC8(u8 *p){CLACT_ReleaseCharacter(((struct Guru2MainCtx *)p)->fD6C);CLACT_ReleasePalette(((struct Guru2MainCtx *)p)->fD70);CLACT_ReleaseCellAnim(((struct Guru2MainCtx *)p)->fD74);CLACT_DeleteUnit(*(struct Bank * *)&((struct Guru2MainCtx *)p)->fD68);CLACT_ExitSystem();}







void func_021DFFF8(u8 *p)
{
    int i;
    u8 *s=p+0xce0;
    func_0201F5BC(1,1,15,0,114);
    PALANM_LoadArcPaletteToSlot(((struct Guru2MainCtx *)p)->fD78,5,3,114,0,32,224);
    PALANM_LoadArcPaletteToSlot(((struct Guru2MainCtx *)p)->fD78,23,5,114,0,32,240);
    ((struct Guru2MainCtx *)s)->f4=GF_FONT_Create(23,0,0,0,114);
    ((struct Guru2MainCtx *)s)->f8=func_02045B38(0,2,41,114);
    *(void * *)&((struct Guru2MainCtx *)s)->fC=func_0201EC64(114);
    *(unsigned int *)&((struct Guru2MainCtx *)s)->f10=BMP_WIN_Create(1,2,19,26,4,15,1);
    ((struct Guru2MainCtx *)s)->f5C=STRBUF_Create(256,114);
    for(i=0;i<5;i++) {*(void **)(p+0xa4+i*4)=STRBUF_Create(8,114);}
    *(unsigned int *)&((struct Guru2MainCtx *)s)->f28=*(unsigned int *)&((struct Guru2MainCtx *)s)->f10;
    *(unsigned char *)&((struct Guru2MainCtx *)s)->f2C=0;
    *(unsigned int *)&((struct Guru2MainCtx *)s)->f58=func_0201C440((void *)114);
    func_021E0338(p,((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fD8)->f8);
}







/*
 * extent: Two zero alignment bytes at 021E012E follow the 90-byte function.
 */
void func_021E00D4(u8 *p)
{
    u8 *s;
    void *obj;
    int i;
    s=p+3296;
    obj=((struct Guru2MainCtx *)s)->f10;
    BMP_WIN_ClearScreen(obj);
    func_020409B4(func_02045730(obj));
    func_020452E8(((struct Guru2MainCtx *)s)->f10);
    func_021E03A0(p);
    MSGDATA_Delete(((struct Guru2MainCtx *)s)->f8);
    func_0201ED04(*(void * *)&((struct Guru2MainCtx *)s)->fC);
    GF_FONT_Delete(((struct Guru2MainCtx *)s)->f4);
    STRBUF_Delete(((struct Guru2MainCtx *)s)->f5C);
    for(i=0;i<5;i++) STRBUF_Delete(*(void **)(p+164+i*4));
    BMP_WIN_Exit();
}







void func_021E0130(u8 *p,int message)
{
    u8 *s;
    void *window,*owner,*data;
    s=p+3296;
    window=((struct Guru2MainCtx *)s)->f10;
    BMP_Clear(func_02045770(window),15);
    func_0201F73C(window,2,1,14);
    BMP_Clear(func_02045770(window),15);
    func_02045CAC(((struct Guru2MainCtx *)s)->f8,message,((struct Guru2MainCtx *)s)->f5C);
    owner=((struct Guru2MainCtx *)s)->f58;
    data=func_02045770(((struct Guru2MainCtx *)s)->f28);
    PRINTSYS_PrintQueColor(owner,(u32)data,0,0,(u32)(((struct Guru2MainCtx *)s)->f5C),(u32)(((struct Guru2MainCtx *)s)->f4),1088);
    *(unsigned char *)&((struct Guru2MainCtx *)s)->f2C=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(func_02045730(window));
}







void func_021E01B0(u8 *p,int message,void *value)
{
    u8 *s;
    void *window,*text,*owner,*data;
    s=p+3296;
    window=((struct Guru2MainCtx *)s)->f10;
    func_0201F02C(*(void * *)&((struct Guru2MainCtx *)s)->fC,1,UNION_APP_GetMemberEntry(func_021DEB10((char *)p),(u8)GFL_NET_SYSTEM_GetCurrentAid()));
    func_0201F02C(*(void * *)&((struct Guru2MainCtx *)s)->fC,2,value);
    text=STRBUF_Create(256,114);
    func_02045CAC(((struct Guru2MainCtx *)s)->f8,message,text);
    func_0201F250(*(void * *)&((struct Guru2MainCtx *)s)->fC,((struct Guru2MainCtx *)s)->f5C,text);
    STRBUF_Delete(text);
    func_0201F73C(window,2,1,14);
    BMP_Clear(func_02045770(window),15);
    owner=((struct Guru2MainCtx *)s)->f58;
    data=func_02045770(((struct Guru2MainCtx *)s)->f28);
    PRINTSYS_PrintQueColor(owner,(u32)data,0,0,(u32)(((struct Guru2MainCtx *)s)->f5C),(u32)(((struct Guru2MainCtx *)s)->f4),1088);
    *(unsigned char *)&((struct Guru2MainCtx *)s)->f2C=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(func_02045730(window));
}







/*
 * extent: Two zero alignment bytes at 021E0302.
 */
void func_021E026C(u8 *p,int message,unsigned value)
{
    u8 *s;
    void *window,*text,*owner,*data;
    s=p+3296;
    window=((struct Guru2MainCtx *)s)->f10;
    func_0201EF40(*(void * *)&((struct Guru2MainCtx *)s)->fC,0,value);
    text=STRBUF_Create(256,114);
    func_02045CAC(((struct Guru2MainCtx *)s)->f8,message,text);
    func_0201F250(*(void * *)&((struct Guru2MainCtx *)s)->fC,((struct Guru2MainCtx *)s)->f5C,text);
    STRBUF_Delete(text);
    func_0201F73C(window,2,1,14);
    BMP_Clear(func_02045770(window),15);
    owner=((struct Guru2MainCtx *)s)->f58;
    data=func_02045770(((struct Guru2MainCtx *)s)->f28);
    PRINTSYS_PrintQueColor(owner,(u32)data,0,0,(u32)(((struct Guru2MainCtx *)s)->f5C),(u32)(((struct Guru2MainCtx *)s)->f4),1088);
    *(unsigned char *)&((struct Guru2MainCtx *)s)->f2C=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(func_02045730(window));
}







void func_021E0304(u8 *p){struct Descriptor *w=*(struct Descriptor * *)&((struct Guru2MainCtx *)p)->fCF0;func_0201F7A8(w,0);BMP_Clear(func_02045770(w),0);BMP_WIN_TransferChars(w);BMP_WIN_MakeScreen((struct Cfg *)w);func_02041B6C(func_02045730(w));}







/*
 * lever: Store the call result directly into its slot, then reuse that slot; declare counter before section base.
 */
void func_021E0338(u8 *p,int count)
{
    int i;
    u8 *s;
    const Desc *table;
    u32 obj;
    u32 *slot;
    const Desc *entry;
    s=p+3296;
    i=0;
    table=d_021E1E30[count];
    ((struct Guru2MainCtx3 *)s)->f0=count;
    for(;i<count;i++) {
        entry=&table[i];
        slot=(u32 *)(s+i*4);
        slot[5]=BMP_WIN_Create((u8)entry->layer,entry->a,entry->b,entry->c,entry->d,entry->e,1);
        obj=slot[5];
        *(u32 *)(s+48+i*8)=obj;
        *(u8 *)(s+52+i*8)=0;
    }
}







void func_021E03A0(u8 *p){int i;u8 *s=p+0xce0;for(i=0;i<((struct Guru2MainCtx3 *)s)->f0;i++){u8 *q=s+(u32)i*4;struct Descriptor *w=*(struct Descriptor * *)&((struct Guru2MainCtx *)q)->f14;BMP_WIN_ClearScreen(w);func_020409B4(func_02045730(w));func_020452E8(*(struct Descriptor * *)&((struct Guru2MainCtx *)q)->f14);}}







void func_021E03D8(u8 *p,void *text,int index,int color)
{
    u8 *s;
    void *window,*owner,*data;
    s=p+3296;
    window=*(void **)(s+20+index*4);
    func_0201F73C(window,2,1,14);
    BMP_Clear(func_02045770(window),15);
    owner=((struct Guru2MainCtx *)s)->f58;
    data=func_02045770(*(void **)(s+48+index*8));
    PRINTSYS_PrintQueColor(owner,(u32)data,4,1,(u32)text,(u32)(((struct Guru2MainCtx *)s)->f4),color);
    *(u8 *)(s+52+index*8)=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(func_02045730(window));
}







void func_021E0450(u8 *p,void *text,int index,int a){int c=0x440;if(a==GFL_NET_SYSTEM_GetCurrentAid())c=0xc80;func_021E03D8(p,text,index,c);}







void func_021E0478(u8 *p,u32 i){struct Descriptor *w=*(struct Descriptor **)(p+i*4+0xcf4);func_0201F7A8(w,0);BMP_Clear(func_02045770(w),0);BMP_WIN_TransferChars(w);BMP_WIN_MakeScreen((struct Cfg *)w);func_02041B6C(func_02045730(w));}






void func_021E04B4(u8 *p){G3D_CAMERA_Delete(((struct Guru2MainCtx *)p)->fD54);}






int func_021E04C4(char *a0){if(TOUCHPANEL_HitTrg(d_021E1CB0)!=-1)return 1;return 0;}






/*
 * lever: Enum zero preserves its early definition; halfword stores use literal zero to avoid truncation.
 */
void func_021E04E0(u8 *p)
{
    int index;
    enum { ZERO } zero;
    u8 *s;
    index=((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fD8)->f8;
    s=p+224;
    ((struct Guru2MainCtx *)s)->fBC=G3D_UTIL_AddUnit(((struct Guru2MainCtx *)p)->fAF4,&d_021E20EC[index-2]);
    zero=0;
    ((struct Guru2MainCtx *)s)->f44=d_021E1DE8[index];
    ((struct Guru2MainCtx *)s)->f18=4096;
    ((struct Guru2MainCtx *)s)->f1C=4096;
    *(int *)&((struct Guru2MainCtx *)s)->f20=4096;
    ((struct Guru2MainCtx *)s)->f4C=0;
    *(unsigned short *)&((struct Guru2MainCtx *)s)->f4E=0;
    ((struct Guru2MainCtx *)s)->f50=0;
    *(int *)&((struct Guru2MainCtx *)s)->f3C=zero;
    ((struct Guru2MainCtx *)p)->fE0=zero;
    *(int *)&((struct Guru2MainCtx *)s)->f4=-147456;
    *(int *)&((struct Guru2MainCtx *)s)->f8=zero;
    *(Vec *)(s+12)=*(Vec *)s;
}






void func_021E0554(u8 *p){G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)p)->f19C));}






void func_021E0570(u8 *p)
{
    u8 *s;
    int angle;
    s=p+224;
    angle=*(int *)&((struct Guru2MainCtx *)p)->f58;
    func_021E15DC(&angle,((struct Guru2MainCtx *)s)->f40);
    func_021E15DC(&angle,((struct Guru2MainCtx *)s)->f44);
    ((struct Guru2MainCtx *)s)->f4E=(360-angle/4096)%360;
    ((struct Guru2MainCtx *)s)->fC=((struct Guru2MainCtx *)p)->fE0+((struct Guru2MainCtx *)s)->f30+*(int *)&((struct Guru2MainCtx *)s)->f24;
    *(int *)&((struct Guru2MainCtx *)s)->f10=*(int *)&((struct Guru2MainCtx *)s)->f4+((struct Guru2MainCtx *)s)->f34+*(int *)&((struct Guru2MainCtx *)s)->f28;
    ((struct Guru2MainCtx *)s)->f14=*(int *)&((struct Guru2MainCtx *)s)->f8+*(int *)&((struct Guru2MainCtx *)s)->f38+*(int *)&((struct Guru2MainCtx *)s)->f2C;
}






static inline void VecSet(Vec *v,int x,int y,int z)
{
    v->x=x; v->y=y; v->z=z;
}






void func_021E05D4(u8 *p)
{
    Transform t;
    u8 *s;
    void *object;
    s=p+224;
    object=(void *)func_02048A18(((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)s)->fBC));
    VecSet(&t.pos,((struct Guru2MainCtx *)s)->fC,*(int *)&((struct Guru2MainCtx *)s)->f10,((struct Guru2MainCtx *)s)->f14);
    VecSet(&t.scale,((struct Guru2MainCtx *)s)->f18,((struct Guru2MainCtx *)s)->f1C,*(int *)&((struct Guru2MainCtx *)s)->f20);
    BUTTON_MAN_MakeRotMtxXYZ(((struct Guru2MainCtx *)s)->f4C,(u16)(((struct Guru2MainCtx *)s)->f4E*182),((struct Guru2MainCtx *)s)->f50,(struct Mtx33 *)&t.rot);
    G3D_SYSTEM_DrawObject(object,(struct Arg *)(&t));
}






void func_021E0634(u8 *p,int a){func_021E15DC((int *)(p+0x3c),a);}





void func_021E0640(u8 *p){((struct Guru2MainCtx *)p)->fDA4=G3D_UTIL_AddUnit(*(struct Util * *)&((struct Guru2MainCtx *)p)->fAF4,&d_021E1D80);G3X_SetClearColor(0,0,32767,0,0);}





/*
 * note: original narrows the second call argument with lsls/lsrs #16 at 021E0682/021E0686, so this caller's extern uses u16.
 */
void func_021E0678(char *p) { G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)p)->fDA4)); }




/*
 * lever: Position setter before scale setter keeps zero in r0 and scale in r1.
 */
void func_021E0698(u8 *p)
{
    Transform t;
    void *object;
    object = (void *)func_02048A18(((struct Guru2MainCtx *)p)->fAF4,(u16)(*(int *)&((struct Guru2MainCtx *)p)->fDA4));
    VecSet(&t.pos,0,0,0);
    VecSet(&t.scale,4096,4096,4096);
    BUTTON_MAN_MakeRotMtxXYZ(0,0,0,(struct Mtx33 *)&t.rot);
    G3D_SYSTEM_DrawObject(object,(struct Arg *)(&t));
}




void func_021E06E0(char *p)
{
    int i;
    char *q=p+0x1a0;
    ((struct Guru2MainCtx *)q)->f938=G3D_UTIL_AddUnit(((struct Guru2MainCtx *)p)->fAF4,d_021E1E60);
    ((struct Guru2MainCtx *)q)->f93C=G3D_UTIL_AddUnit(((struct Guru2MainCtx *)p)->fAF4,d_021E1E70);
    for (i=0;i<5;i++) *(int *)(q+0x940+i*4)=G3D_UTIL_AddUnit(((struct Guru2MainCtx *)p)->fAF4,d_021E212C+i*16);
}










void func_021E073C(char *p)
{
    int i;
    char *q = p+0x1a0;
    for (i=0;i<5;i++) G3D_UTIL_RemoveUnit(((struct Guru2MainCtx *)p)->fAF4,(u16)(*(int *)(q+0x940+i*4)));
    G3D_UTIL_RemoveUnit(((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)q)->f938));
    G3D_UTIL_RemoveUnit(((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)q)->f93C));
}










void func_021E078C(char *p,char *q) { *(int *)&((struct Guru2MainCtx *)q)->f4=1; func_021E0B14(p,q); func_021E0BA4(p,q); }










void func_021E07A4(char *p)
{
    Count count;
    int i=0;
    PlayerBlock *base;
    count=((struct Guru2MainCtx *)p)->f30;
    base=(PlayerBlock *)(p+0x1a0);
    for (;i<count;i++) {
        if (base->a[i].active)
            func_021E09C0((char *)&base->a[i],(int *)(p+0x110),*(u16 *)(p+0x60+i*2)<<12,*(int *)&((struct Guru2MainCtx *)p)->f5C);
        if (base->b[i].active)
            func_021E0B38(p,(char *)&base->b[i],*(int *)&((struct Guru2MainCtx *)p)->f5C);
        if (base->c[i].active)
            func_021E0BC0(p,(char *)&base->c[i],i);
    }
}










void func_021E0848(u8 *p)
{
    int i=0;
    int count=((struct Guru2MainCtx *)p)->f30;
    u8 *base=p+0x1a0;
    u8 *first=base+0x140,*second=base+0x4c4,*third=base+0x730;
    for(;i<count;i=i+1) {
        if(((struct Guru2MainCtx3 *)first)->f4) {
            Transform t;
            void *object=(void *)func_02048A18(((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)base)->f938));
            VecSet(&t.pos,((struct Guru2MainCtx3 *)first)->f44,((struct Guru2MainCtx3 *)first)->f48,((struct Guru2MainCtx3 *)first)->f4C);
            VecSet(&t.scale,((struct Guru2MainCtx3 *)first)->f38,((struct Guru2MainCtx3 *)first)->f3C,((struct Guru2MainCtx3 *)first)->f40);
            BUTTON_MAN_MakeRotMtxXYZ(((struct Guru2MainCtx3 *)first)->f24,((struct Guru2MainCtx3 *)first)->f26,((struct Guru2MainCtx3 *)first)->f28,(struct Mtx33 *)&t.rot);
            G3D_SYSTEM_DrawObject(object,(struct Arg *)(&t));
        }
        if(*(int *)&((struct Guru2MainCtx2 *)second)->f0) {
            Transform t;
            void *object=(void *)func_02048A18(((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)base)->f93C));
            VecSet(&t.pos,((struct Guru2MainCtx2 *)second)->f18,((struct Guru2MainCtx2 *)second)->f1C,((struct Guru2MainCtx2 *)second)->f20);
            VecSet(&t.scale,((struct Guru2MainCtx2 *)second)->fC,((struct Guru2MainCtx2 *)second)->f10,*(int *)&((struct Guru2MainCtx2 *)second)->f14);
            BUTTON_MAN_MakeRotMtxXYZ(((struct Guru2MainCtx2 *)second)->f4,((struct Guru2MainCtx2 *)second)->f6,*(unsigned short *)&((struct Guru2MainCtx2 *)second)->f8,(struct Mtx33 *)&t.rot);
            G3D_SYSTEM_DrawObject(object,(struct Arg *)(&t));
        }
        if(((struct Guru2MainCtx *)third)->f0) {
            Transform t;
            void *object=(void *)func_02048A18(((struct Guru2MainCtx *)p)->fAF4,(u16)(*(int *)((unsigned)(base+i*4)+0x940)));
            VecSet(&t.pos,*(int *)&((struct Guru2MainCtx *)third)->f4,*(int *)&((struct Guru2MainCtx *)third)->f8,((struct Guru2MainCtx *)third)->fC);
            VecSet(&t.scale,4096,4096,4096);
            func_0207ADC4(&t.rot);
            G3D_SYSTEM_DrawObject(object,(struct Arg *)(&t));
        }
        first+=0xb4;second+=0x7c;third+=0x68;
    }
}










void func_021E0980(char *p,int amount)
{
    int count = *(int *)&((struct Guru2MainCtx2 *)p)->f30;
    int i = 0;
    char *base = p+0x1a0;
    for (;i<count;i++) {
        if (*(int *)(base+0x140+i*0xb4))
            func_021E15DC((int *)(base+0x15c+i*0xb4),amount);
    }
}










/*
 * extent: two-byte alignment padding at 0x021E0A42.
 * Verified ARM scratch C: S12/blocker_0203F63C-r1.log EXACT (72 bytes),
 * S13/blocker_0203F5FC-r1.log EXACT (64 bytes). Both use this symbol:
 *   d_020A1B38 0x020A1B38 data a2
 * typedef unsigned short u16;
 * extern const short d_020A1B38[];
 * int func_0203F63C(u16 angle) {
 *     if (angle >= 360) return 0;
 *     return d_020A1B38[((angle * 65535 / 360) >> 4) * 2 + 1];
 * }
 * int func_0203F5FC(u16 angle) {
 *     if (angle >= 360) return 0;
 *     return d_020A1B38[((angle * 65535 / 360) >> 4) * 2];
 * }
 */
void func_021E09C0(char *p,int *q,int amount,int extra)
{
    u16 angle;
    func_021E15DC(&amount,*(int *)(p+0x20));
    angle=amount/4096;
    *(int *)(p+0x44)=*(int *)(p+0x50)+q[0]+22*func_0203F63C(angle);
    *(int *)(p+0x48)=extra+(*(int *)(p+0x54)-0x6000+q[1]);
    *(int *)(p+0x4c)=*(int *)(p+0x58)+q[2]+22*func_0203F5FC(angle);
    *(short *)(p+0x24)=*(int *)(p+0x2c)/4096;
    *(short *)(p+0x26)=*(int *)(p+0x30)/4096;
    *(short *)(p+0x28)=*(int *)(p+0x34)/4096;
}










/*
 * lever: (pass 2 2026-10-06 P2L40) i zeroed before the angle statement, the row offset
 *   count*10 in a named local as in the twin func_021DEE4C, and a separate local for the
 *   insertion-sort value in the third loop.
 * history: wave P12 lane A8 33 of 208 bytes off; final push G7L3 26 (initialised declarations
 *   count, table, base); pass 2 P2L40: early i 13, separate sort-value local 6, named row 0.
 */
void *func_021E0A44(Obj *p)
{
    int distance[5],indices[5];
    int angle,i,j,key,value,delta,dist,row;
    long count=p->count;
    const u8 *base=(const u8 *)p+0x1a0;
    i=0;
    row=count*10;
    angle=*(const u16 *)((unsigned)d_021E1FDC+row+p->index*2)<<12;
    do {indices[i]=i;distance[i]=65535;i++;} while(i<count);
    for(i=0;i<count;i++) {
        value=*(int *)(base+i*0xb4+0x15c);
        delta=angle-value;
        if(delta<0)delta=angle+0x168000-value;
        distance[i]=delta/4096;
    }
    for(i=1;i<count;i++) {
        key=indices[i];dist=distance[key];
        j=i-1;
        while(j>=0 && distance[indices[j]]>dist) {indices[j+1]=indices[j];j--;}
        indices[j+1]=key;
    }
    return (void *)(base+0x140+indices[0]*0xb4);
}










void func_021E0B14(char *p,char *q) { char *r; int offset; r=p+0x664; offset=*(int *)&((struct Guru2MainCtx *)q)->f10*0x7c; *(int *)(r+offset)=1; *(char **)(r+offset+0x78)=q; func_021E0B38(p,r+offset,0); }










void func_021E0B38(char *p,char *q,int amount)
{
    int n;
    *(short *)&((struct Guru2MainCtx2 *)q)->f4=0;
    *(short *)&((struct Guru2MainCtx2 *)q)->f6=0;
    *(short *)&((struct Guru2MainCtx2 *)q)->f8=0;
    *(Vec *)(q+0x18)=*(Vec *)(*(char * *)&((struct Guru2MainCtx2 *)q)->f78+0x44);
    ((struct Guru2MainCtx2 *)q)->f18-=((struct Guru2MainCtx2_f78 *)((struct Guru2MainCtx2 *)q)->f78)->f50;
    ((struct Guru2MainCtx2 *)q)->f1C-=((struct Guru2MainCtx2_f78 *)((struct Guru2MainCtx2 *)q)->f78)->f54+amount;
    ((struct Guru2MainCtx2 *)q)->f20-=((struct Guru2MainCtx2_f78 *)((struct Guru2MainCtx2 *)q)->f78)->f58;
    ((struct Guru2MainCtx2 *)q)->f1C+=0x2000;
    n=((struct Guru2MainCtx2_f78 *)((struct Guru2MainCtx2 *)q)->f78)->f54+amount;
    if (n<0) n=-n;
    n/=128;
    if (n>0x800) n=0x800;
    ((struct Guru2MainCtx2 *)q)->fC=0x1000-n;
    ((struct Guru2MainCtx2 *)q)->f10=0x1000-n;
    *(int *)&((struct Guru2MainCtx2 *)q)->f14=0x1000-n;
}











void func_021E0BA4(char *p, char *q)
{
    char *r = p + 0x8D0 + *(int *)&((struct Guru2MainCtx *)q)->f10 * 0x68;

    ((struct Guru2MainCtx3 *)r)->f0 = 1;
    *(char * *)&((struct Guru2MainCtx3 *)r)->f64 = q;
}










void func_021E0BC0(char *p,char *q,int i)
{
    void *r = (void *)func_02048A18(((struct Guru2MainCtx *)p)->fAF4,(u16)(*(int *)(p+0xae0+i*4)));
    *(Vec *)(q+4) = *(Vec *)(*(char * *)&((struct Guru2MainCtx2 *)q)->f64+0x44);
    ((struct Guru2MainCtx2 *)q)->f8 += 0x14000;
    G3D_SYSTEM_LoopObjectAnimeFrame(r,0,0x1000);
}









void func_021E0C08(char *p,int a,int b,int c,int d,int e,int *q)
{
    int *r;
    q[3]=a;
    q[4]=b;
    q[5]=c;
    q[6]=b;
    q[7]=d<<12;
    q[8]=e<<12;
    q[0]=1;
    q[2]=0;
    r=func_02030734(0x8072,24,0,d_021E22B8,0x130e);
    func_02082BCC(r,0,24);
    r[5]=(int)p;
    r[4]=(int)q;
    func_02030DA8(((struct Guru2MainCtx *)p)->fD98,(void (*)(void *, void *))func_021E0C70,r,0);
}









extern int (*const d_021E1CB8[])(char *);









void func_021E0C70(struct Node *task,char *p) { int result; do { result=d_021E1CB8[*(int *)p](p); } while(result==1); if(result==2) { ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f8=1; func_020307B0(p); func_02030EAC(task); } }









int func_021E0CA4(struct Guru2MainCtx *p) { char *q; q=*(char * *)&p->f10; *(int *)&((struct Guru2MainCtx *)q)->f38=4096; *(int *)&((struct Guru2MainCtx *)q)->f3C=4096; ((struct Guru2MainCtx *)q)->f40=4096; ((struct Guru2MainCtx *)q)->f54=0xc0000; func_021E078C(*(char * *)&p->f14,q); p->fC=0x8000; p->f0=1; return 0; }









int func_021E0CCC(int *p)
{
    int *q = (int *)p[4];
    q[21] -= p[3];
    if (p[2] == 0 && q[21] <= 0x68000) {
        p[2] = 1;
        func_020061E4(0x725);
    }
    if (q[21] <= 0x20000) {
        q[21] = 0x20000;
        p[0] = 2;
    }
    return 0;
}








/*
 * extent: two-byte alignment padding at 0x021E0D4E.
 */
int func_021E0D0C(int *p)
{
    int *q = (int *)p[4];
    char *r;
    if (p[3] > 0x1000) {
        p[3] -= 0x1000;
        if (p[3] < 0x1000) p[3] = 0x1000;
    }
    q[21] -= p[3];
    if (q[21] <= 0) {
        q[21] = 0;
        r = (char *)p[5];
        func_021E0450((u8 *)r, (void *)(*(int *)(r + 0xa4 + q[3]*4)), q[5], q[3]);
        return 2;
    }
    return 0;
}








void func_021E0D50(char *p,int *q)
{
    int *r=(int *)q[7];
    switch(q[1]) {
    case 0:
        func_021E0F64(p,(int)r);
        q[4]=0x4000;
        q[5]=-1092;
        q[1]++;
    case 1:
        r[23]+=q[4];
        q[4]+=q[5];
        q[2]++;
        if(q[2]>=15) {
            q[2]=0;
            q[4]=0;
            if(q[3]==0) { q[3]=1; return; }
            r[23]=0;
            func_021E1090(p,(int)r);
            func_02082BCC(q,0,32);
        }
        break;
    }
}








void func_021E0DC0(void *unused,char *p) { int i; int *q; q=(int *)(p+0xaf8); for(i=0;i<5;i++,q+=8) if(*q!=0) func_021E0D50(p,q); }








void func_021E0DE8(char *p) { func_02082BCC(p+2808,0,160); *(struct Node * *)&((struct Guru2MainCtx *)p)->fD7C=func_02030DA8(*(struct Ctx * *)&((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))((u32)func_021E0DC0), (void *)((u32)p), 256); }








void func_021E0E1C(u8 *p)
{
    func_02030EAC(((struct Guru2MainCtx *)p)->fD7C);
}







void func_021E0E2C(char *p,int value) { int i; int *q; q=(int *)(p+0xaf8); for(i=0;i<5;i++,q+=8) { if(*q==0) { *q=1; q[7]=value; return; } } }







void func_021E0E50(char *p)
{
    RecordBlock *base=(RecordBlock *)(p+0x1a0);
    int count=((struct Guru2MainCtx *)p)->f30;
    int i;
    i=0;
    do {
        if (base->records[i].active) func_021E0E2C(p,(int)((char *)&base->records[i]));
        i++;
    } while (i<count);
}







/*
 * extent: unlabelled bool scan follower at 0x021E0E8C, through pool at 0x021E0EA8.
 */
int func_021E0E8C(char *p)
{
    int i;
    char *q=p+0xaf8;
    for (i=0;i<5;i++,q+=0x20) if (((struct Guru2MainCtx3 *)q)->f0) return 1;
    return 0;
}







void func_021E0EAC(int *p)
{
    int *q = (int *)p[4];
    switch (p[1]) {
    case 0:
        p[3] = 0x18000;
        q[12] = 0;
        p[1]++;
    case 1:
        func_021E15DC(q + 12, p[3]);
        if (q[12] < 0x4000) {
            p[3] = (unsigned)p[3] >> 1;
            if (p[3] < 0x4000) {
                q[12] = 0;
                func_02082BCC(p, 0, 20);
            }
        }
        break;
    }
}







void func_021E0EFC(void *unused,char *p) { int i; int *q; q=(int *)(p+0xb98); for(i=0;i<5;i++,q+=5) if(*q!=0) func_021E0EAC(q); }







void func_021E0F20(char *p) { func_02082BCC(p+2968,0,100); *(struct Node * *)&((struct Guru2MainCtx *)p)->fD80=func_02030DA8(*(struct Ctx * *)&((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))((u32)func_021E0EFC), (void *)((u32)p), 257); }








void func_021E0F54(u8 *p)
{
    func_02030EAC(((struct Guru2MainCtx *)p)->fD80);
}







void func_021E0F64(char *p, int key)
{
    int i;
    EntryA *entry;
    EntryA *base = (EntryA *)(p + 0xb98);
    entry = base;
    for (i = 0; i < 5; i++, entry++) {
        if (entry->active == 1 && entry->key == key) {
            entry->state = 0;
            return;
        }
    }
    for (i = 0; i < 5; i++, base++) {
        if (base->active == 0) {
            base->active = 1;
            base->key = key;
            return;
        }
    }
}







/*
 *   typedef unsigned short u16;
 *   extern const short d_020A1B38[];
 *   int func_0203F5FC(u16 angle) {
 *       if (angle >= 360) return 0;
 *       return d_020A1B38[((angle * 65535 / 360) >> 4) * 2];
 *   }
 */
void func_021E0FAC(int *p)
{
    int *q = (int *)p[5];
    int old;
    int amount;
    switch (p[1]) {
    case 0:
        q[13] = 0;
        p[4] = 0;
        p[2] = 0x1e000;
        p[3] = 0x14000;
        p[1]++;
    case 1:
        amount = func_0203F5FC((u16)(p[4] / 4096)) * (p[2] / 4096);
        q[13] = 0;
        func_021E15DC(q + 13, amount);
        old = p[4];
        func_021E15DC(p + 4, p[3]);
        if (p[4] < old) {
            p[2] = (unsigned)p[2] >> 1;
            if (p[2] == 0) {
                q[13] = 0;
                func_02082BCC(p, 0, 24);
            }
        }
        break;
    }
}







void func_021E1028(void *unused,char *p) { int i; int *q; q=(int *)(p+0xbfc); for(i=0;i<5;i++,q+=6) if(*q!=0) func_021E0FAC(q); }







void func_021E104C(char *p) { func_02082BCC(p+3068,0,120); *(struct Node * *)&((struct Guru2MainCtx *)p)->fD84=func_02030DA8(*(struct Ctx * *)&((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))((u32)func_021E1028), (void *)((u32)p), 258); }








void func_021E1080(u8 *p)
{
    func_02030EAC(((struct Guru2MainCtx *)p)->fD84);
}







void func_021E1090(char *p, int key)
{
    int i;
    EntryB *entry;
    EntryB *base = (EntryB *)(p + 0xbfc);
    entry = base;
    for (i = 0; i < 5; i++, entry++) {
        if (entry->active == 1 && entry->key == key) {
            entry->state = 0;
            return;
        }
    }
    for (i = 0; i < 5; i++, base++) {
        if (base->active == 0) {
            base->active = 1;
            base->key = key;
            return;
        }
    }
}







void func_021E10D8(u8 *p,PlayerState *s)
{
    u8 *b=p+0xe0;
    switch(s->state) {
    case 1:
        s->speed=0x4000;s->timer=0;s->state++;
    case 2:
        ((struct Guru2MainCtx *)b)->f34-=4096;
        if(((struct Guru2MainCtx *)b)->f34<=-32768)s->state++;
        break;
    case 3:
        ((struct Guru2MainCtx *)b)->f34+=8192;
        if(((struct Guru2MainCtx *)b)->f34>=0) {
            ((struct Guru2MainCtx *)b)->f34=0;
            func_021E0E50((char *)p);
            s->active=1;s->state++;
            func_020061E4(0x55e);
        }
        break;
    case 4:
        *(int *)&((struct Guru2MainCtx *)b)->f28=s->speed;
        s->speed=-s->speed;
        s->timer++;
        if(!(s->timer&3)) {
            if(s->speed<=4096) {*(int *)&((struct Guru2MainCtx *)b)->f28=0;s->state++;}
            else s->speed>>=1;
        }
        break;
    case 5:
        if(!func_021E0E8C((char *)p)) {
            s->other=0;s->active=0;s->state=0;
            func_020061E4(0x76d);
        }
        break;
    case 0:break;
    }
}







void func_021E11A0(void *unused,u8 *p)
{
    func_021E10D8(p,(PlayerState *)(p+0xc74));
}






void func_021E11B4(char *p)
{
    func_02082BCC(p + 0xc74, 0, 20);
    ((struct Guru2MainCtx *)p)->fD88 = (void *)func_02030DA8(((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))func_021E11A0, p, 255);
}







void func_021E11E4(u8 *p)
{
    func_02030EAC(((struct Guru2MainCtx *)p)->fD88);
}







void func_021E11F4(char *p)
{
    char *q = p + 0xC74;

    *(int *)&((struct Guru2MainCtx *)q)->f8 = 1;
    ((struct Guru2MainCtx *)q)->f0 = 1;
}






int func_021E1204(char *p)
{
    return ((struct Guru2MainCtx2 *)p)->fC78;
}






int func_021E1210(char *p)
{
    return ((struct Guru2MainCtx2 *)p)->fC7C;
}





void func_021E121C(void *task, int *p)
{
    switch (p[0]) {
    case 0:
        if (p[3] < 4) {
            Table sounds = d_021E203C;
            p[1]--;
            if (p[1] <= 0) {
                p[1] = 30;
                func_020061E4(sounds.v[p[3]]);
                p[3]++;
            }
        }
        CLACT_AddActorAnimFrame((struct Obj *)p[5], 0x1800);
        if (CLACT_IsActorAnimActive((struct Actor *)p[5]) == 0) p[0]++;
        break;
    case 1:
        CLACT_DeleteActor((struct Obj *)p[5]);
        func_020307B0(p);
        func_02030EAC(task);
        break;
    }
}





void func_021E129C(char *p)
{
    struct { u16 x, y, z; u8 a, b; } pos;
    int *q = func_02030734(0x8072, 24, 0, d_021E22B8, 5638);
    func_02082BCC(q, 0, 24);
    pos.x = 128;
    pos.y = 100;
    pos.z = 0;
    pos.b = 0;
    pos.a = 0;
    q[5] = (int)(struct Obj *)CLACT_CreateActor((void *)*(unsigned int *)&((struct Guru2MainCtx *)p)->fD68, ((struct Guru2MainCtx *)p)->fD6C, ((struct Guru2MainCtx *)p)->fD70, ((struct Guru2MainCtx *)p)->fD74, &pos, 0, 114);
    CLACT_AddActorAnimFrame((struct Obj *)q[5], 4096);
    q[4] = (int)p;
    func_02030DA8(((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))func_021E121C, q, 0);
}




void func_021E1320(void *task, ModeState *p)
{
    switch (p->state) {
    case 0: break;
    case 1:
        func_021DFEA0(task);
        func_020061E4(1832);
        p->count = 0;
        p->state++;
    case 2:
        p->count++;
        if (p->count >= 2) {
            p->count = 0;
            p->state++;
            func_021DFEB8(task);
        }
        break;
    case 3:
        p->count++;
        if (p->count >= 4) {
            func_021DFEA0(task);
            p->count = 0;
            p->state++;
        }
        break;
    case 4:
        p->count++;
        if (p->count >= 2) {
            func_021DFEAC(task);
            p->flag = 0;
            p->state = 0;
        }
        break;
    }
}




/*
 * follower: 021E13A8 tail-forwards r1 and r1+0xC88 to this callback.
 */
void func_021E13A8(void *unused, char *p)
{
    func_021E1320(p, (ModeState *)(p + 0xc88));
}




void func_021E13BC(char *p)
{
    unsigned n = 8;
    func_02082BCC(p + 0xc88, 0, n);
    n += 251;
    ((struct Guru2MainCtx *)p)->fD8C = (void *)func_02030DA8(((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))func_021E13A8, p, n);
}





void func_021E13F0(u8 *p)
{
    func_02030EAC(((struct Guru2MainCtx *)p)->fD8C);
}





u16 func_021E1400(char *p)
{
    return ((struct Guru2MainCtx2 *)p)->fC8A;
}





void func_021E140C(char *p)
{
    char *q = p + 0xC88;

    ((struct Guru2MainCtx4 *)q)->f2 = 1;
    ((struct Guru2MainCtx4 *)q)->f0 = 1;
}




void func_021E141C(void *unused, int *p)
{
    switch (p[0]) {
    case 0: break;
    case 1:
        *(int *)(p[3] + 0x54) = d_021E2278[p[1]] << 12;
        p[1]++;
        if (p[1] >= 16) {
            p[1] = 0;
            p[0]++;
        }
        break;
    case 2:
        p[2]++;
        if (p[2] >= 15) {
            p[2] = 0;
            p[0] = 1;
        }
        break;
    }
}




void func_021E1468(void *unused, char *p)
{
    int i;
    int *q = (int *)(p + 0xc90);
    for (i = 0; i < 5; i++, q += 4) func_021E141C(p, q);
}




void func_021E1488(char *p)
{
    unsigned n = 80;
    func_02082BCC(p + 0xc90, 0, n);
    n += 180;
    ((struct Guru2MainCtx *)p)->fD90 = (void *)func_02030DA8(((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))func_021E1468, p, n);
}




void func_021E14BC(u8 *p)
{
    func_02030EAC(((struct Guru2MainCtx *)p)->fD90);
}




void func_021E14CC(char *p, char *q)
{
    char *r = p + 0xC90 + ((struct Guru2MainCtx2 *)q)->fC * 0x10;

    ((struct Guru2MainCtx *)r)->f0 = 1;
    *(char * *)&((struct Guru2MainCtx *)r)->fC = q;
}



void func_021E14E4(const char *p)
{
  int mask = *((int *) (p + 28));
  const Block *base;
  int i;
  int count;
  i = 0;
  base = (const Block *) (p + 0x1a0);
  count = *((int *) (p + 48));
  for (; i < count; i++)
  {
    if ((base->records[i].active != 0) && (mask & (1 << base->records[i].key)))
      func_021E14CC((char *) p, (char *) (&base->records[i]));
  }
}



void func_021E1540(void *task, int *p)
{
    int done = 0;
    if (p[1] == 1) {
        p[2]--;
        if (p[2] <= 0) {
            p[2] = 0;
            done = 1;
        }
    } else {
        p[2]++;
        if (p[2] >= 8) {
            p[2] = 8;
            done = 1;
        }
    }
    func_021DFF20((void *)p[0], p[2]);
    if (done == 1) {
        func_020307B0(p);
        func_02030EAC(task);
    }
}



void func_021E1584(char *p, int flag)
{
    IntPair values = d_021E2018;
    int *q = func_02030734(0x8072, 12, 0, d_021E22B8, 5992);
    q[0] = (int)p;
    q[1] = flag;
    q[2] = ((int *)&values)[flag];
    func_02030DA8(((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))func_021E1540, q, 0);
}




void func_021E15DC(int *p, int v)
{
    *p += v;
    while (*p < 0) *p += 0x168000;
    *p %= 0x168000;
}



void func_021E1604(char *p, int v)
{
    func_021E0634((u8 *)(p + 0xe0), v);
    func_021E0980(p, v);
}




int func_021E161C(char *p)
{
    int n = ((struct Guru2MainCtx2 *)p)->f8 + 1;

    ((struct Guru2MainCtx2 *)p)->f8 = n;
    if (n < 0x258)
        return 0;
    ((struct Guru2MainCtx2 *)p)->f8 = 0x258;
    return 1;
}



/*
 * extent: following 021E168C is already matched separately.
 */
void *func_021E1634(char *p, u32 member, int flag)
{
    u32 size = ARC_TOOL_GetHandleMemberSize(*(struct ArcFile * *)&((struct Guru2MainCtx *)p)->fD58, member);
    void *result;
    if (flag == 1)
        result = func_02030734(114, size, 0, d_021E22B8, 6090);
    else
        result = func_02030734(0x8072, size, 0, d_021E22B8, 6092);
    ARC_TOOL_ReadHandleMember(*(struct ArcFile * *)&((struct Guru2MainCtx *)p)->fD58, member, result);
    return result;
}



void func_021E168C(int *p,int a) { if(a!=0) p[13]=a; }



void func_021E1694(char *p, const FiveRecord *q)
{
    ((struct Guru2MainCtx2 *)p)->f3C = 1;
    *(FiveRecord *)(p + 0x58) = *q;
}



char *func_021E16AC(char *p, int n)
{
    func_02082BCC(p + 0xb8, 0, 32);
    return p + 0xb8;
}




char *func_021E16C0(char *p)
{
    return p + 0xb8;
}




int func_021E16C4(char *p, int mask)
{
    return (((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fDC)->f40 & mask) != 0;
}



/*
 * Lever: initialise count before bound, then carry bound through a plain copy bound_ after x is loaded.
 * Direct bound use left a four-byte zero/subtraction scheduling swap; bounded permuter found the copy spelling.
 * trailing: Two zero alignment bytes.
 */
int func_021E16D8(const char *p)
{
  unsigned int count;
  int bound;
  unsigned int x;
  int bound_;
  count = 0;
  bound = (*((int *) ((*((char **) (p + 0xd8))) + 8))) - 1;
  x = *((unsigned short *) ((*((char **) (p + 0xdc))) + 0x42));
  bound_ = bound;
  while (x)
  {
    count += x & 1;
    x >>= 1;
  }

  return ((int) count) >= bound_;
}




/*
 * extent: 30-byte body followed by two bytes of zero alignment padding.
 * lever: Initialize count before loading x; declare count before x.
 * Existing result-before-input and declaration-order idioms cover this.
 */
int func_021E170C(char *p) { int count; unsigned int x; count=0;x=((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fDC)->f42;while(x) { count+=x&1; x>>=1; }return count; }



/*
 * extent: 42-byte body followed by two bytes of zero alignment padding.
 * volatile: The raw halfword at q+0 is re-read at 021E1732/021E1734.
 */
void func_021E172C(char *p,unsigned short *q) { unsigned int index;unsigned short value; index=*(volatile unsigned short *)&((struct Guru2MainCtx4 *)q)->f0;value=*(volatile unsigned short *)&((struct Guru2MainCtx4 *)q)->f0;*(unsigned short *)(p+index*4+0x7c)=value;*(unsigned short *)(p+index*4+0x7e)=q[1];if(q[1]==GFL_NET_SYSTEM_GetCurrentAid())((struct Guru2MainCtx *)p)->f2C=q[0]; }



void func_021E1758(char *p, int a1) { ((struct Guru2MainCtx *)p)->f30=UNION_APP_GetMemberCount(func_021DEB10(p)); }




/*
 * The `&` operand order names the temporary: `field & (1 << i)` (field into
 * r2, mask into r0) reproduces the original; `(1 << i) & field` rotates them.
 */
int func_021E1768(char *p, int i)
{
    if (i != 0 && (((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fDC)->f42 & (1 << i)) == 0)
        return 0;
    return 1;
}



void func_021E1784(char *p, int i)
{
    void *party;
    void *other;
    int slot;
    void *a;
    void *b;
    void *q;
    party = ((struct Guru2MainCtx *)p)->f24;
    other = (void *)func_021DCE00(*(char * *)&((struct Guru2MainCtx *)p)->fDC, i);
    slot = *(int *)(p + 0x44 + i * 4);
    a = func_0201AB28(party, (*(int * *)&((struct Guru2MainCtx *)p)->fD8)[1]);
    b = func_0201AB28(other, slot);
    q = func_021DEB10(p);
    func_0202F190(b, (int)6, (u32)UNION_APP_GetMemberEntry(q, (u8)GFL_NET_SYSTEM_GetCurrentAid()), (int)30002, (int)114);
    func_02019CE0(b, a);
}



int func_021E17EC(char *p)
{
    int count = 0;
    unsigned bits = ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fDC)->f46;
    while (bits) {
        count += bits & 1;
        bits >>= 1;
    }
    return count;
}



void func_021E180C(int *p,int a,int b) { (p+a)[17]=b; }



void func_021E1814(unsigned char *p,u16 *q)
{
    u16 *d=(u16 *)(p+108);
    unsigned n=8;
    do { *d++=*q++; } while(--n);
    ((struct Guru2MainCtx3 *)p)->f40=1;
}



int func_021E1830(char *p, int angle, int index)
{
    int tmp;
    unsigned a;
    unsigned count;
    unsigned b;
    struct RangeU16 *r;
    struct Entry *e;
    func_021E15DC(&angle, -((struct Guru2MainCtx *)p)->f11C);
    func_021E15DC(&angle, -((struct Guru2MainCtx *)p)->f124);
    tmp = angle;
    func_021E15DC(&tmp, -0x4000);
    a = tmp / 0x1000;
    tmp = angle;
    func_021E15DC(&tmp, 0x5000);
    b = tmp / 0x1000;
    e = &d_021E1F04[index];
    count = e->count;
    r = e->ranges;
    while (count) {
        if ((a >= r->lo && a <= r->hi) || (b >= r->lo && b <= r->hi))
            return 1;
        r++;
        count--;
    }
    return 0;
}



int func_021E18CC(void *p)
{
    int n;
    int i;
    void *m;
    n = func_0201AA18(p);
    for (i = 0; i < n; i++) {
        m = func_0201AB28(p, i);
        if (func_02017E1C(m, 0x4c, 0) != 0 && func_02017E1C(m, 3, 0) != 0)
            return 1;
    }
    return 0;
}



int func_021E1910(char *p)
{
    int i;
    if (func_021E18CC(((struct Guru2MainCtx *)p)->f24) == 1)
        return 1;
    for (i = 0; i < 5; i++) {
        if (func_021E1768(p, i) != 0 && func_021E18CC((void *)func_021DCE00(*(char * *)&((struct Guru2MainCtx *)p)->fDC, i)) == 1)
            return 1;
    }
    return 0;
}




int func_021E1954(struct Guru2MainCtx *p) { int count; unsigned int x; count=0;x=((struct Guru2MainCtx2 *)p->fDC)->f4A;while(x) { count+=x&1; x>>=1; }return count; }




int func_021E1974(struct Guru2MainCtx *p)
{
    return ((struct Guru2MainCtx2 *)p->fDC)->f48 != 0;
}



void func_021E1988(unsigned int n) { GFL_USE_SetBgmPlayerParam((void *)1);GFL_USE_PushBgm();GFL_USE_CancelChangeAndPlayBgm(n,65535); }



/*
 * prototype: Legacy 02005E9C source lists four inputs, but its complete
 * body starts with 02005FBC(void) and reads no entry inputs; omitted them.
 */
int func_021E19A4(void) { if(func_02005F38()==0) { GFL_USE_PopBgm();GFL_USE_SetBgmPlayerParam(0);return 0; }return 1; }
