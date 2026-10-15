/*
 * file:     b_bag_main.c
 * unit:     yes
 * function: B_BAG_MAIN_InitWindows, B_BAG_MAIN_CreateWindows, B_BAG_MAIN_DeleteWindows, B_BAG_MAIN_ExitWindows, B_BAG_MAIN_DrawPage, B_BAG_MAIN_PrintLabel, B_BAG_MAIN_DrawLabels, func_0220B31C, func_0220B3EC, func_0220B4B8, func_0220B520, func_0220B584, func_0220B6C4, func_0220B774, func_0220B78C, func_0220B814, func_0220B880, func_0220B904, func_0220B928, func_0220B980, func_0220B990, func_0220B9A4, func_0220B9D8, func_0220BA2C, func_0220BB1C, func_0220BB78, func_0220BB98, func_0220BBD8, func_0220BBE4, func_0220BD14, func_0220BD24, func_0220BF20, func_0220BF40, func_0220C034, func_0220C06C, func_0220C0B4, func_0220C180, func_0220C220, func_0220C27C, func_0220C304, func_0220C3B4, func_0220C40C, func_0220C448, func_0220C4D4, func_0220C4EC, func_0220C538, func_0220C574, func_0220C618, func_0220C68C, func_0220C6C0, func_0220C6D0, func_0220C6E8, func_0220C6F8, func_0220C714, func_0220C724, func_0220C834, func_0220C914, func_0220C980, func_0220CAAC, func_0220CBB4, func_0220CBE8, func_0220CC18, func_0220CD50, func_0220CFA4, func_0220CFF0, func_0220D024, func_0220D11C, func_0220D214, func_0220D234, func_0220D254, func_0220D274, func_0220D29C, func_0220D2AC, func_0220D328, func_0220D358, func_0220D370, func_0220D39C, func_0220D3B0, func_0220D464, func_0220D5C0, func_0220D6B8, func_0220D6DC, func_0220D798, func_0220D7D0, func_0220D7F0, func_0220D848, func_0220D884, func_0220D89C, func_0220D8B0, func_0220D8C4, func_0220D914, func_0220D924, func_0220D974, func_0220D98C, func_0220D9A8, B_BAG_MAIN_HandleSelection
 * address:  0x0220B120
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   d_0220DA68 0x0220DA68 data a4
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   d_0220DA0D 0x0220DA0D data a1
 *   func_0201F250 0x0201F250 thumb
 *   WORDSET_Callback_EF40 0x0201EF40 thumb
 *   d_0220DA38 0x0220DA38 data a4
 *   func_0201EFA4 0x0201EFA4 thumb
 *   d_0220DA3C 0x0220DA3C data a4
 *   func_02041300 0x02041300 arm
 *   d_0220DA28 0x0220DA28 data a1
 *   d_0220DA19 0x0220DA19 data a1
 *   STRBUF_Create 0x020457B0 arm
 *   func_02020FB4 0x02020FB4 thumb
 *   d_0220DA08 0x0220DA08 data a1
 *   func_0201F73C 0x0201F73C thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   B_APP_TOOL_Update 0x0220B0B0 thumb
 *   B_APP_TOOL_ShowWindows  0x0220B094  thumb  ov196
 *   MYITEM_SAVEDATA_HasItem 0x02007F68 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   func_020081DC 0x020081DC thumb
 *   func_020307B0 0x020307B0 arm
 *   d_0220DB3C 0x0220DB3C data a4
 *   d_0220DB3F 0x0220DB3F data a4
 *   func_0202F114 0x0202F114 thumb
 *   func_0202F138 0x0202F138 thumb
 *   sub_0202F144 0x0202F144 thumb
 *   BGWINFRM_Create 0x0202C9B4 thumb
 *   func_020490F4 0x020490F4 arm
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_SetClipArea 0x0202CFEC thumb
 *   BGWINFRM_SetFrameDataArcHandle 0x0202CB18 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   d_0220DB44 0x0220DB44 data a4
 *   BGWINFRM_Delete 0x0202CA0C thumb
 *   BGWINFRM_ChangePalette 0x0202CE50 thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 *   BGWINFRM_HideFrame 0x0202CC70 thumb
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_02020F08 0x02020F08 thumb
 *   FILE_UTIL_Get 0x02020E60 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   func_02020F0C 0x02020F0C thumb
 *   func_02020F10 0x02020F10 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   PALANM_LoadHandlePaletteToSlot 0x020216B4 thumb
 *   func_02049B40 0x02049B40 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   PALANM_CopyToSlot 0x020215BC thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   d_0220DBBC 0x0220DBBC data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   d_0220DB7C 0x0220DB7C data a4
 *   d_0220DB88 0x0220DB88 data a4
 *   d_0220DB80 0x0220DB80 data a4
 *   B_APP_TOOL_CreateActors 0x0220AF6C thumb ov196
 *   B_APP_TOOL_SetActorsVisible 0x0220AFDC thumb ov196
 *   B_APP_TOOL_DeleteActors 0x0220AFC4 thumb ov196
 *   BTLV_FINGER_CURSOR_Create 0x02209A7C thumb
 *   BTLV_FINGER_CURSOR_Delete 0x02209B30 thumb
 *   BTLV_FINGER_CURSOR_Start  0x02209B60  thumb  ov094
 *   BTLV_FINGER_CURSOR_DeleteActor 0x02209C18 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   d_0220E0E0 0x0220E0E0 data a1
 *   func_02030734 0x02030734 arm
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   func_0200829C 0x0200829C thumb
 *   func_020082B0 0x020082B0 thumb
 *   func_020082B4 0x020082B4 thumb
 *   TCBL_Main 0x020310C4 arm
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   d_0220DF40 0x0220DF40 data a4
 *   d_04001050 0x04001050 data a2
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   TCBL_Create 0x0203101C arm
 *   B_APP_TOOL_Create 0x0220AF40 thumb ov196
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   FILE_UTIL_Get_0FE4 0x02020FE4 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetCont 0x0203630C arm
 *   KEY_GetTrg 0x020362DC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   WIPE_SYS_ExeEnd 0x020221B8 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   B_APP_TOOL_Delete 0x0220AF64 thumb ov196
 *   func_02030EAC 0x02030EAC arm
 *   BTLV_FINGER_CURSOR_IsActive 0x02209C2C thumb
 *   func_0203FC6C 0x0203FC6C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   d_0220DEB0 0x0220DEB0 data a4
 *   d_0220DEE0 0x0220DEE0 data a4
 *   d_0220DF20 0x0220DF20 data a4
 *   d_0220DF00 0x0220DF00 data a4
 *   d_0220DEC0 0x0220DEC0 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   func_02041570 0x02041570 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CURSOR_MOVE_Create 0x02025CD0 thumb
 *   CURSOR_MOVE_EnableInput 0x02025D1C thumb
 *   CURSOR_MOVE_SetMode 0x02025D24 thumb
 *   d_0220DF90 0x0220DF90 data a4
 *   d_0220DF9C 0x0220DF9C data a4
 *   CURSOR_MOVE_Delete  0x02025D14  thumb
 *   CURSOR_MOVE_GetEntry  0x0202616C  thumb
 *   B_APP_TOOL_LayoutActors  0x0220B000  thumb  ov196
 *   CURSOR_MOVE_SetCurrent  0x020260E4  thumb
 */
#include "../../matched/include/Obj14542.h"
#include "../../matched/include/Obj24989.h"
#include "../../matched/include/Obj08353.h"
#include "../../matched/include/Obj24990.h"
#include "../../matched/include/Obj24991.h"
#include "../../matched/include/Obj03905.h"
#include "../../matched/include/Obj24992.h"
#include "../../matched/include/Obj00845.h"
#include "../../matched/include/Obj24993.h"
#include "../../matched/include/Obj24994.h"
#include "../../matched/include/Obj00314.h"
#include "../../matched/include/Obj24999.h"
#include "../../matched/include/Obj25000.h"
#include "../../matched/include/Obj25001.h"
#include "../../matched/include/Obj25002.h"
#include "../../matched/include/Obj25003.h"
#include "../../matched/include/Obj25004.h"
#include "../../matched/include/Obj04597.h"
#include "../../matched/include/Obj25005.h"
#include "../../matched/include/Obj25007.h"
#include "../../matched/include/Obj25008.h"
#include "../../matched/include/Obj14543.h"
#include "../../matched/include/Obj25009.h"
#include "../../matched/include/Obj25010.h"
#include "../../matched/include/Obj06648.h"
#include "../../matched/include/Obj14544.h"
#include "../../matched/include/Obj05520.h"
#include "../../matched/include/Obj25011.h"
#include "../../matched/include/Obj08354.h"
#include "../../matched/include/Obj01176.h"
#include "../../matched/include/Obj25012.h"
#include "../../matched/include/Obj25013.h"
#include "../../matched/include/Obj25014.h"
#include "../../matched/include/Obj08355.h"
#include "../../matched/include/Obj01005.h"
#include "../../matched/include/Obj00315.h"
#include "../../matched/include/Obj25015.h"
#include "../../matched/include/Obj25016.h"
#include "../../matched/include/Obj25017.h"
#include "../../matched/include/Obj25018.h"
#include "../../matched/include/Obj25019.h"
#include "../../matched/include/Obj01075.h"
#include "../../matched/include/Obj14545.h"
#include "../../matched/include/Obj25020.h"
#include "../../matched/include/Obj25021.h"
#include "../../matched/include/Obj10833.h"
#include "../../matched/include/Obj25022.h"
#include "../../matched/include/Obj25023.h"
#include "../../matched/include/Obj25024.h"
#include "../../matched/include/Obj25025.h"
#include "../../matched/include/Obj25026.h"
#include "../../matched/include/Obj25027.h"
#include "../../matched/include/Obj25028.h"
#include "../../matched/include/Obj25029.h"
#include "../../matched/include/Obj25030.h"
#include "../../matched/include/Obj25031.h"
#include "../../matched/include/Obj25032.h"
#include "../../matched/include/Obj25033.h"
#include "../../matched/include/Obj25034.h"
#include "../../matched/include/Obj25035.h"
#include "../../matched/include/Obj25036.h"
#include "../../matched/include/Obj25037.h"
#include "../../matched/include/Obj25038.h"
#include "../../matched/include/Obj25039.h"
#include "../../matched/include/Obj25040.h"
#include "../../matched/include/Obj25041.h"
#include "../../matched/include/Obj25042.h"
#include "../../matched/include/Obj25043.h"
#include "../../matched/include/Obj25044.h"
#include "../../matched/include/Obj25045.h"
#include "../../matched/include/Obj25046.h"
#include "../../matched/include/Obj25047.h"
#include "../../matched/include/Obj00846.h"
#include "../../matched/include/Obj25048.h"
#include "../../matched/include/Obj25049.h"
#include "../../matched/include/Obj25050.h"
#include "../../matched/include/Obj00736.h"
#include "../../matched/include/Obj25051.h"
#include "../../matched/include/Obj25052.h"
#include "../../matched/include/Obj25053.h"
#include "../../matched/include/Obj25054.h"
#include "../../matched/include/Obj25055.h"
#include "../../matched/include/Obj25057.h"
#include "../../matched/include/Obj25058.h"
#include "../../matched/include/Obj01076.h"
#include "../../matched/include/Obj25059.h"
#include "../../matched/include/Obj25060.h"
#include "../../matched/include/Obj25061.h"
#include "../../matched/include/Obj25062.h"
#include "../../matched/include/Obj25064.h"
#include "../../matched/include/Obj14547.h"
#include "../../matched/include/Obj25065.h"
#include "../../matched/include/Obj10835.h"
#include "../../matched/include/Obj25066.h"
#include "../../matched/include/Obj25067.h"
#include "../../matched/include/Obj25068.h"
#include "../../matched/include/Obj02244.h"
#include "../../matched/include/Obj25069.h"
#include "../../matched/include/Obj25070.h"
#include "../../matched/include/Obj25071.h"
#include "../../matched/include/Obj25072.h"
#include "../../matched/include/Obj00389.h"
#include "../../matched/include/Obj25073.h"
#include "../../matched/include/Obj25074.h"
#include "../../matched/include/Obj25075.h"
#include "../../matched/include/Obj25076.h"
#include "../../matched/include/Obj25077.h"
#include "../../matched/include/Obj25078.h"
#include "../../matched/include/Obj25079.h"
#include "../../matched/include/Obj25080.h"
#include "../../matched/include/Obj10837.h"
#include "../../matched/include/Obj02245.h"
#include "../../matched/include/Obj25081.h"
#include "../../matched/include/Obj25082.h"
#include "../../matched/include/Obj25083.h"
#include "../../matched/include/Obj25084.h"
#include "../../matched/include/Obj25085.h"
#include "../../matched/include/Obj25086.h"
#include "../../matched/include/Obj14548.h"
#include "../../matched/include/Obj14549.h"
#include "../../matched/include/Obj14550.h"
#include "../../matched/include/Obj10838.h"
#include "../../matched/include/Obj25087.h"
#include "../../matched/include/Obj03346.h"
#include "../../matched/include/Obj25088.h"
#include "../../matched/include/Obj14551.h"
#include "../../matched/include/Obj25089.h"
#include "../../matched/include/Obj25090.h"
#include "../../matched/include/Obj25091.h"
#include "../../matched/include/Obj25092.h"
#include "../../matched/include/Obj25093.h"
#include "../../matched/include/Obj25095.h"
#include "../../matched/include/Obj25097.h"
#include "../../matched/include/Obj00688.h"
#include "../../matched/include/Obj25098.h"
#include "../../matched/include/Obj25099.h"
#include "../../matched/include/Obj25100.h"
#include "../../matched/include/Obj14552.h"
#include "../../matched/include/Obj25101.h"
#include "../../matched/include/Obj25102.h"
#include "../../matched/include/Obj02914.h"
#include "../../matched/include/Obj25103.h"
#include "../../matched/include/Obj25104.h"
#include "../../matched/include/Obj25105.h"
#include "../../matched/include/Obj25106.h"
#include "../../matched/include/Obj25107.h"
#include "../../matched/include/Obj25108.h"
#include "../../matched/include/Obj25109.h"
#include "../../matched/include/Obj03906.h"
#include "../../matched/include/Obj25110.h"
#include "../../matched/include/Obj25111.h"
#include "../../matched/include/Obj25112.h"
#include "../../matched/include/Obj25113.h"
#include "../../matched/include/Obj08356.h"
#include "../../matched/include/Obj25114.h"
#include "../../matched/include/Obj25115.h"
#include "../../matched/include/Obj25116.h"
#include "../../matched/include/Obj25118.h"
#include "../../matched/include/Obj25120.h"
#include "../../matched/include/Obj03347.h"
#include "../../matched/include/Obj25121.h"
#include "../../matched/include/Obj25122.h"
#include "../../matched/include/Obj06649.h"

#define MGR(p) (*(struct WinMgr **)((p) + 0x520))
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct CharBuf;
struct WordSet;
struct Cfg;
struct Item;
struct WinMgr;
struct Obj;
struct PalAnmSlot;
struct Sub0204A9D0;
struct Bank;
struct Vec2;
struct MyItemSave;
struct Tcbl;
struct Node;
struct PrintSys;
struct Sound;
struct Rec;
struct Rec3;
struct S02031140;
struct Struct_02025CD0;
struct Struct_02025D1C;
struct Struct_02025D24;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_0220B120;

typedef unsigned int u32_0220B120;

typedef short s16_0220B150;

typedef unsigned int u32_0220B150;

typedef unsigned int   u32_0220B188;

typedef unsigned int   u32_0220B1A0;

typedef short s16_0220B1D4;

typedef unsigned int   u32_0220B1D4;

typedef signed short s16_0220B248;

typedef unsigned long u32_0220B248;

typedef signed short s16_0220B31C;

typedef unsigned long u32_0220B31C;

typedef signed short s16_0220B3EC;

typedef unsigned long u32_0220B3EC;

typedef unsigned int   u32_0220B4B8;

typedef signed short s16_0220B584;

typedef unsigned long u32_0220B584;

typedef unsigned int u32_0220B78C;

typedef unsigned int   u32_0220B814;

typedef struct {unsigned short entry[36][2];} Row;

typedef unsigned int u32_0220B880;

typedef unsigned int u32_0220B928;

typedef unsigned int   u32_0220B990;

typedef signed short   s16_0220B990;

typedef signed char    s8;

typedef short s16_0220B9A4;

typedef unsigned int u32_0220B9A4;

typedef short s16_0220BA2C;

typedef unsigned int u32_0220BA2C;

typedef short s16_0220BBD8;

typedef unsigned int u32_0220BBD8;

typedef unsigned long u32_0220BBE4;

typedef struct {u16 member;u8 w,h;} WinCfg;

typedef signed int     s32;

typedef unsigned int   u32;

struct S { char pad0[0x520]; struct WinMgr *mgr; char pad1[0x533-0x524]; u8 idx; char pad2[5]; u8 fl[1]; };

typedef short s16;

typedef struct {u16 a,b,c;unsigned char d,e;} Config;

struct Pair_0220C574 { short x, y; };

typedef signed short   s16_0220C6F8;

struct Pair_0220C6E8 { short x,y; };

typedef signed short   s16_0220C834;

typedef short s16_0220D370;

typedef struct PalAnmObj PalAnmObj;

struct BgVramReq {u32 a,b,c,d;};

struct BgTemplate {u32 a,b,size,c;u8 d,e,f,g;u32 h;u8 i,j,k,l;u32 m;};

typedef signed short s16_0220D884;

typedef signed short   s16_0220D914;

typedef signed short s16_0220D924;

typedef signed short   s16_0220D98C;

extern u32_0220B120 BMP_WIN_Create(u32_0220B120,u32_0220B120,u32_0220B120,u32_0220B120,u8,u8,u8);
extern u32_0220B188 BMP_WIN_Delete(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32_0220B1D4 index);
extern u32_0220B1D4 func_0201D304(struct StrObj *s, u32_0220B1D4 a, u32_0220B1D4 b);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201EFA4(struct WordSet *p, u32_0220B248 i, u32_0220B248 a, u32_0220B248 b, u32_0220B248 c, u32_0220B248 d);
extern void WORDSET_Callback_EF40(struct WordSet *p, u32_0220B248 i, u32_0220B248 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
extern struct U16Vec *STRBUF_Create(u32_0220B814 capacity, u32_0220B814 heapId);
extern void func_02020FB4(void *,unsigned,unsigned);
extern void func_0201F73C(void *, int, int, int);
extern void GF_FONT_SetTextColor(u32_0220B928 r, u32_0220B928 g, u32_0220B928 b);
extern signed char MSG_SPEED_GetWait(void);
extern void *PRINTSYS_PrintStream(void *a0, u32_0220B928 a1, u32_0220B928 a2, void *a3, u32_0220B928 a4, u32_0220B928 a5, void *a6, u32_0220B928 a7, u16 a8, u32_0220B928 a9);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32_0220B928 bit);
extern int B_APP_TOOL_Update(void *, int, int);
extern u32_0220B990 B_APP_TOOL_ShowWindows(u8 *, u32_0220B990);
extern u32_0220B9A4 MYITEM_SAVEDATA_HasItem(u8 *,u16,u16,u16);
extern void *ARC_TOOL_LoadMember(u32_0220BA2C archive_id, u32_0220BA2C member, u32_0220BA2C heap);
extern struct Item *func_020081DC(u8 *base, u32_0220BA2C id, u32_0220BA2C index);
extern u32_0220BA2C func_020307B0(void *p);
extern unsigned func_0202F114(const unsigned char *,unsigned);
extern unsigned short func_0202F138(unsigned);
extern u32_0220BBD8 sub_0202F144(u32_0220BBD8);
extern struct WinMgr *BGWINFRM_Create(u32_0220BBE4,u32_0220BBE4,u32_0220BBE4);
extern void *func_020490F4(u32_0220BBE4 id, u32_0220BBE4 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32_0220BBE4 idx, u32_0220BBE4 bg, u32_0220BBE4 w, u32_0220BBE4 h);
extern void BGWINFRM_SetClipArea(struct Obj *o, u32_0220BBE4 i, u8 a, u8 b, s8 c, s8 d);
extern void BGWINFRM_SetFrameDataArcHandle(struct WinMgr *mgr,u32_0220BBE4,void *,u32_0220BBE4,u32_0220BBE4);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr,u32_0220BBE4,s8,s8);
extern void BGWINFRM_Delete(struct WinMgr *mgr);
extern void BGWINFRM_ChangePalette(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern unsigned func_02020F08(void);
extern unsigned FILE_UTIL_Get(unsigned,unsigned);
extern int CLACT_RegisterCharacter(void *,unsigned,unsigned,unsigned,u16);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_02020F0C(void);
extern int func_02020F10(void);
extern int CLACT_RegisterCellAnim(void *,unsigned,unsigned,unsigned);
extern void *ARC_UTIL_LoadScreenDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern struct Bank *CLACT_CreateUnit(int,u8,u32);
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
extern void CLACT_ReleaseCellAnim(unsigned);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void B_APP_TOOL_CreateActors(char *,int,int,int,int);
extern void B_APP_TOOL_SetActorsVisible(char *,void *);
extern void B_APP_TOOL_DeleteActors(u8 *p);
extern int BTLV_FINGER_CURSOR_Create(int, int, int);
extern void BTLV_FINGER_CURSOR_Delete(int);
extern void BTLV_FINGER_CURSOR_Start(u32, u32, u32, u32, u32, u32);
extern void BTLV_FINGER_CURSOR_DeleteActor(int);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *BTLV_EFFECT_GetOwner(void);
extern int BTLV_EFFECT_GetPalanm(void);
extern void *func_02030DA8(void *, u32, void *, u32);
extern void func_0200829C(const struct MyItemSave *p, int i, s16_0220C834 *a, s16_0220C834 *b);
extern u16 func_020082B0(const struct MyItemSave *p);
extern u16 func_020082B4(const struct MyItemSave *p);
extern void TCBL_Main(struct Tcbl *);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u8 *B_APP_TOOL_Create(u16 v);
extern void GFL_NET_RestartWithDefaultTimeout(unsigned,unsigned);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern int PALANM_RequestFade(void *,u16,u16,short,u8,u8,u16,void *);
extern unsigned PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void WIPE_SYS_Start(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern unsigned WIPE_SYS_EndCheck(void);
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *obj);
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern unsigned FILE_UTIL_Get_0FE4(void *, unsigned, unsigned);
extern void func_0201F7A8(void *desc, u32 kind);
extern unsigned PRINTSYS_PrintStreamGetState(void *);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *, int);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
extern int TOUCHPANEL_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void WIPE_SYS_ExeEnd(void);
extern void TCBL_Destroy(struct S02031140 *);
extern void B_APP_TOOL_Delete(void *);
extern void func_02030EAC(struct Node *);
extern int BTLV_FINGER_CURSOR_IsActive(void *);
extern void func_0203FC6C(const struct BgVramReq *,u32);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);
extern void BG_SYS_ClearSlot(u32);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020403F4(u32 i);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *, u32, u32, u32, u32, u32, u16);
extern struct MsgBank *func_02045B38(unsigned,unsigned,unsigned,unsigned);
extern struct WordSet *GF_FONT_Create_EC64(unsigned);
extern unsigned PRINTSYS_QUE_Create(void *);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern void BG_SYS_ResetSlot(unsigned int, unsigned int, unsigned int);
extern void func_02041570(int channel, u16 val);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern struct Struct_02025CD0 *CURSOR_MOVE_Create(u32, u32, u32, u32, u8, u16);
extern void CURSOR_MOVE_EnableInput(struct Struct_02025D1C *);
extern void CURSOR_MOVE_SetMode(struct Struct_02025D24 *);
extern u32 CURSOR_MOVE_Delete(void *a0);
extern void *CURSOR_MOVE_GetEntry(void **obj, u32 idx);
extern void B_APP_TOOL_LayoutActors(int *p, u8 *q);
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
void B_BAG_MAIN_InitWindows(char *p);
void B_BAG_MAIN_CreateWindows(char *p,u8 unused);
void B_BAG_MAIN_DeleteWindows(char *a);
void B_BAG_MAIN_ExitWindows(char *a);
void B_BAG_MAIN_DrawPage(char *a, int which);
void B_BAG_MAIN_PrintLabel(char *p,int i,int id,int y,u16 colour);
void B_BAG_MAIN_DrawLabels(char *p);
void func_0220B31C(char *p,u32_0220B31C i,int id,int w,int unused,int unused2);
void func_0220B3EC(char *p, u32_0220B3EC i, int id, int w, int unused, int y, int unused2);
void func_0220B4B8(char *p,u16 i);
void func_0220B520(char *p);
void func_0220B584(char *p);
void func_0220B6C4(char *p);
void func_0220B774(char *a);
void func_0220B78C(u8 *p, u32_0220B78C idx);
void func_0220B814(char *p,int n);
void func_0220B880(char *p);
void func_0220B904(char *p);
void func_0220B928(char *p);
int func_0220B980(char *a);
u32_0220B990 func_0220B990(u8 *p);
int func_0220B9A4(char *p);
void func_0220B9D8(u8 *p);
void func_0220BA2C(u8 *p);
void func_0220BB1C(char *p);
void func_0220BB78(char *p);
u16 func_0220BB98(const char *p, unsigned n);
int func_0220BBD8(u32_0220BBD8 key);
void func_0220BBE4(char *p);
void func_0220BD14(char *a);
void func_0220BD24(char *p, int mode);
void func_0220BF20(char *p, int v);
void func_0220BF40(char *p);
void func_0220C034(char *p);
void func_0220C06C(char *p);
void func_0220C0B4(char *p);
void func_0220C180(char *p,u16 item,unsigned slot,unsigned offset);
void func_0220C220(char *p,unsigned item,unsigned slot);
void func_0220C27C(char *p);
void func_0220C304(char *p);
struct Obj *func_0220C3B4(char *p,const int *indices);
void func_0220C40C(char *p);
void func_0220C448(char *p);
void func_0220C4D4(int a, int b);
void func_0220C4EC(char *p, int mode);
void func_0220C538(char *p);
void func_0220C574(char *p);
void func_0220C618(char *p);
void func_0220C68C(char *p);
void func_0220C6C0(char *a);
void func_0220C6D0(char *a);
void func_0220C6E8(char *a);
void func_0220C6F8(u8 *p, u32 a, u32 b);
void func_0220C714(char *a);
void func_0220C724(char *p,u16 slot,u8 a,u8 b,const struct Pair_0220C6E8 *src);
void func_0220C834(u8 *arg);
void func_0220C914(void *task, char *p);
int func_0220C980(char *p);
int func_0220CAAC(char *p);
int func_0220CBB4(char *p);
int func_0220CBE8(char *p);
int func_0220CC18(char *p);
int func_0220CD50(char *p);
int func_0220CFA4(char *p);
int func_0220CFF0(char *p);
int func_0220D024(char *p);
int func_0220D11C(char *p);
int func_0220D214(char *p);
int func_0220D234(char *p);
int func_0220D254(char *p);
int func_0220D274(char *p);
int func_0220D29C(char *a);
int func_0220D2AC(char *p);
int func_0220D328(char *p);
int func_0220D358(char *p);
int func_0220D370(char *p);
int func_0220D39C(char *a);
int func_0220D3B0(struct Node *task, char *p);
int func_0220D464(char *p);
void func_0220D5C0(char *p);
void func_0220D6B8(void);
void func_0220D6DC(char *p);
void func_0220D798(char *p);
void func_0220D7D0(char *p);
void func_0220D7F0(void *unused, int mode);
void func_0220D848(char *p,int mode);
int func_0220D884(char **p);
void func_0220D89C(char **a, int b);
void func_0220D8B0(char **a, int b);
void func_0220D8C4(u8 *p, u32 index, u32 value);
u32 func_0220D914(u8 *p);
void func_0220D924(u8 *p, int state, int value);
void func_0220D974(char *a, int b);
void func_0220D98C(u8 *p, u32 idx);
void func_0220D9A8(u8 *p,u32 i);
void func_0220D9BC(char *p);
void func_0220D9C8(char *p);
void func_0220D9D4(u8 *p,u32 i);
void B_BAG_MAIN_HandleSelection(char *p, int b);
extern const u8 d_0220DA68[];
extern const char d_0220DA0D[];
extern const char d_0220DA38[];
extern const char d_0220DA3C[];
extern const char d_0220DA28[];
extern const char d_0220DA19[];
extern const u8 d_0220DA08[];
extern const u8 d_0220DB3C[];
extern const u8 d_0220DB3F[];
extern const WinCfg d_0220DB44[14];
extern const int d_0220DBBC[];
extern const int d_0220DB7C[];
extern const struct Pair_0220C574 d_0220DB88[];
extern const struct Pair_0220C574 d_0220DB80[];
extern const char d_0220E0E0[];
extern u16 d_04001050[];
extern const struct BgVramReq d_0220DEB0;
extern const struct BgTemplate d_0220DEE0,d_0220DF20,d_0220DF00,d_0220DEC0;
extern const u32 d_0220DF90[];
extern const u32 d_0220DF9C[];


void B_BAG_MAIN_InitWindows(char *p) { ((struct Obj14542 *)p)->f24=BMP_WIN_Create(4,1,19,30,4,12,1); B_BAG_MAIN_CreateWindows(p,((struct Obj14542 *)p)->f532); }


/*
 * Declaring the table pointer before the counter restores r4/r5 allocation.
 */
void B_BAG_MAIN_CreateWindows(char *p,u8 unused) { const u8 *q; u32_0220B150 i; q=d_0220DA68; for(i=0;i<35;i++,q+=6) *(u32_0220B150 *)(p+i*8+0x28)=BMP_WIN_Create(q[0],q[1],q[2],q[3],q[4],q[5],1); }



void B_BAG_MAIN_DeleteWindows(char *a)
{
    unsigned int i;

    for (i = 0; i < 0x23; i++)
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(a + i * 8 + 0x28)));
}



void B_BAG_MAIN_ExitWindows(char *a)
{
    B_BAG_MAIN_DeleteWindows(a);
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj24989 *)a)->f24));
}



void B_BAG_MAIN_DrawPage(char *a, int which)
{
    switch (which)
    {
    case 0:
        B_BAG_MAIN_DrawLabels(a);
        break;
    case 1:
        func_0220B774(a);
        break;
    case 2:
        func_0220B880(a);
        break;
    }
}


void B_BAG_MAIN_PrintLabel(char *p,int i,int id,int y,u16 colour)
{
    int handle=*(int *)(p+0x28+i*8);
    int text=(int)func_02045EC0((struct MsgBank *)(((struct Obj08353 *)p)->fC),id);
    int width=func_0201D304((struct StrObj *)text,((struct Obj24990 *)(*(char * *)&((struct Obj08353 *)p)->f0))->f4,0);
    int x=(BMP_WIN_GetWidth((struct Descriptor *)handle)*8-width)>>1;
    int font=((struct Obj08353 *)p)->f18;
    int surface=(int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)(p+0x28+i*8));
    PRINTSYS_PrintQueColor((void *)font,(int)surface,(s16_0220B1D4)x,(s16_0220B1D4)y,(int)text,(int)(((struct Obj24991 *)(*(char * *)&((struct Obj08353 *)p)->f0))->f4),colour);
    (p+i*8)[0x2c]=1;
    STRBUF_Delete((struct U16Vec *)text);
}


/*
 * matching: unsigned loop bound i<=4 preserves the original cmp4/bls; i<5 differs in two bytes.
 */
void B_BAG_MAIN_DrawLabels(char *p)
{
    unsigned i;
    void *text;
    void *font;
    void *surface;
    for(i=0;i<=4;i++)BMP_Clear(BMP_WIN_GetBmp(*(void **)(p+i*8+0x28)),0);
    B_BAG_MAIN_PrintLabel(p,0,0,0,0x3C40);
    B_BAG_MAIN_PrintLabel(p,0,1,16,0x3C40);
    B_BAG_MAIN_PrintLabel(p,1,2,0,0x3C40);
    B_BAG_MAIN_PrintLabel(p,1,3,16,0x3C40);
    B_BAG_MAIN_PrintLabel(p,2,7,0,0x3C40);
    B_BAG_MAIN_PrintLabel(p,3,6,0,0x3C40);
    if(((struct Obj03905 *)p)->f540!=0){
        text=func_02045EC0(((struct Obj03905 *)p)->fC,8);
        font=((struct Obj03905 *)p)->f18;
        surface=BMP_WIN_GetBmp(((struct Obj03905 *)p)->f48);
        PRINTSYS_PrintQueColor(font,(u32_0220B248)surface,0,0,(u32_0220B248)text,((struct Obj24992 *)(*(char * *)&((struct Obj03905 *)p)->f0))->f4,0x3C40);
        p[0x4C]=1;
        STRBUF_Delete(text);
    }else{
        BMP_WIN_TransferChars(((struct Obj03905 *)p)->f48);
    }
    *(const char * *)&((struct Obj03905 *)p)->f59C=d_0220DA0D;
}




/*
 * Width: printer x truncates to signed halfword in original; extern keeps s16 despite owner u32.
 */
void func_0220B31C(char *p,u32_0220B31C i,int id,int w,int unused,int unused2)
{
    char *windows=p+0x28;
    void *handle=*(void **)(windows+w*8);
    void *text;
    void *font;
    void *surface;
    u32_0220B31C width;
    int page;
    BMP_Clear(BMP_WIN_GetBmp(handle),0);
    page=(u32_0220B31C)p+((u8 *)p)[0x533]*0x90;
    if(*(u16 *)(page+i*4+0x150)!=0){
        text=func_02045EC0(((struct Obj00845 *)p)->fC,*(u32_0220B31C *)(d_0220DA38+id*8));
        page=(u32_0220B31C)p+((u8 *)p)[0x533]*0x90;
        WORDSET_Callback_EF40(((struct Obj00845 *)p)->f10,0,*(u16 *)(page+i*4+0x150));
        func_0201F250(((struct Obj00845 *)p)->f10,((struct Obj00845 *)p)->f14,text);
        width=func_0201D304(((struct Obj00845 *)p)->f14,((struct Obj24993 *)(*(char * *)&((struct Obj00845 *)p)->f0))->f4,0);
        width=BMP_WIN_GetWidth(handle)*8-width;
        font=((struct Obj00845 *)p)->f18;
        surface=BMP_WIN_GetBmp(*(void **)(windows+w*8));
        PRINTSYS_PrintQueColor(font,(u32_0220B31C)surface,(s16_0220B31C)(width/2),(s16_0220B31C)7,(u32_0220B31C)(((struct Obj00845 *)p)->f14),((struct Obj24994 *)(*(char * *)&((struct Obj00845 *)p)->f0))->f4,0x3C40);
        (p+w*8)[0x2C]=1;
        STRBUF_Delete(text);
    }else{
        BMP_WIN_TransferChars(handle);
    }
}




/*
 * Width: original narrows y to signed halfword before printer; corresponding extern keeps s16 despite owner u32.
 */
void func_0220B3EC(char *p, u32_0220B3EC i, int id, int w, int unused, int y, int unused2)
{
  char *windows = p + 0x28;
  void *handle = *((void **) (windows + (w * 8)));
  void *text;
  void *font;
  void *surface;
  int page;
  char *tmp;
  u16 pad;
  u32_0220B3EC *tmp1;
  char *tmp2;
  BMP_Clear(BMP_WIN_GetBmp(handle), 0);
  page = ((u32_0220B3EC) p) + (((u8 *) p)[0x533] * 0x90);
  if (((*((u16 *) ((page + (i * 4)) + 0x152))) != 0) && ((*((int *) ((*((char **) p)) + 8))) != 1))
  {
    text = func_02045EC0(*((void **) (p + 0xC)), *((u32_0220B3EC *) (d_0220DA3C + (id * 8))));
    page = ((u32_0220B3EC) p) + (((u8 *) p)[0x533] * 0x90);
    func_0201EFA4(*((void **) (p + 0x10)), 0, *((u16 *) (((u32_0220B3EC) (page + (i * 4))) + 0x152)), 3, 0, 1);
    tmp2 = p + 0x14;
    func_0201F250(*((void **) (p + 0x10)), *((void **) tmp2), text);
    font = *((void **) (p + 0x18));
    surface = BMP_WIN_GetBmp(*((void **) (windows + (w * 8))));
    tmp = p + 0x14;
    tmp1 = (u32_0220B3EC *) ((*((char **) p)) + 4);
    PRINTSYS_PrintQueColor(font, (u32_0220B3EC)surface, (s16_0220B3EC)0, (s16_0220B3EC)y, (u32_0220B3EC)(*((void **) tmp)), *tmp1, 0x3C40);
    (p + (w * 8))[0x2C] = 1;
    STRBUF_Delete(text);
  }
  else
  {
    BMP_WIN_TransferChars(handle);
  }
}




/*
 * lever: assign the doubled index after the flag branch; the flag is unsigned byte evidence.
 */
void func_0220B4B8(char *p,u16 i)
{
    int base=*(short *)(*(char * *)&((struct Obj00845 *)p)->f0+((u8 *)p)[0x533]*2+0x38)*6;
    int row=5;
    int twice;
    if(((u8 *)p)[0x141]!=0)row=0x11;
    twice=i*2;
    func_0220B31C(p,i+base,i,row+twice,0,0);
    func_0220B3EC(p,i+base,i,row+1+twice,0,4,0);
}




void func_0220B520(char *p)
{
    u16 i;
    func_02041300(5,0,0,0,0x20,0x13,0x11);
    for(i=0;i<6;i++)func_0220B4B8(p,i);
    if(((u8 *)p)[0x141]==0)
        *(const char * *)&((struct Obj00314 *)p)->f59C=d_0220DA28;
    else
        *(const char * *)&((struct Obj00314 *)p)->f59C=d_0220DA19;
    ((u8 *)p)[0x141]^=1;
}




/*
 * matching: parenthesised byte-pointer plus page keeps the page load before the far-field add; a flat offset sum differs in two bytes.
 * Width: original narrows x to signed 16 bits before each 0201C724 call; s16 extern preserves those caller truncations despite owner u32 x.
 */
void func_0220B584(char *p)
{
    void *handle=((struct Obj00314 *)p)->f118;
    void *surface=BMP_WIN_GetBmp(handle);
    void *text;
    u32_0220B584 width;
    u32_0220B584 x;
    void *font;
    void *lastSurface;
    BMP_Clear(surface,0);
    text=func_02045EC0(((struct Obj00314 *)p)->fC,28);
    width=func_0201D304(text,((struct Obj24999 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0);
    x=(BMP_WIN_GetWidth(handle)*8-width)/2;
    PRINTSYS_PrintQueColor(((struct Obj00314 *)p)->f18,(u32_0220B584)surface,(s16_0220B584)x,(s16_0220B584)4,(u32_0220B584)text,((struct Obj25000 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0x3C40);
    STRBUF_Delete(text);
    text=func_02045EC0(((struct Obj00314 *)p)->fC,29);
    func_0201EFA4(((struct Obj00314 *)p)->f10,0,((u8 *)p+((u8 *)p)[0x533])[0x539]+1,2,0,1);
    func_0201F250(((struct Obj00314 *)p)->f10,((struct Obj00314 *)p)->f14,text);
    PRINTSYS_PrintQueColor(((struct Obj00314 *)p)->f18,(u32_0220B584)surface,(s16_0220B584)(x+width),(s16_0220B584)4,(u32_0220B584)(((struct Obj00314 *)p)->f14),((struct Obj25001 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0x3C40);
    STRBUF_Delete(text);
    text=func_02045EC0(((struct Obj00314 *)p)->fC,30);
    func_0201EFA4(((struct Obj00314 *)p)->f10,0,*(s16_0220B584 *)(*(char * *)&((struct Obj00314 *)p)->f0+((u8 *)p)[0x533]*2+0x38)+1,2,0,1);
    func_0201F250(((struct Obj00314 *)p)->f10,((struct Obj00314 *)p)->f14,text);
    width=func_0201D304(((struct Obj00314 *)p)->f14,((struct Obj25002 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0);
    font=((struct Obj00314 *)p)->f18;
    lastSurface=BMP_WIN_GetBmp(((struct Obj00314 *)p)->f118);
    PRINTSYS_PrintQueColor(font,(u32_0220B584)lastSurface,(s16_0220B584)(x-width),(s16_0220B584)4,(u32_0220B584)(((struct Obj00314 *)p)->f14),((struct Obj25003 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0x3C40);
    ((u8 *)p)[0x11C]=1;
    STRBUF_Delete(text);
}




void func_0220B6C4(char *p)
{
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00314 *)p)->f110)),0);
    if(((struct Obj25004 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f8!=1) {
        switch(((unsigned char *)p)[0x533]) {
        case 0:B_BAG_MAIN_PrintLabel(p,29,22,4,0x3c40);B_BAG_MAIN_PrintLabel(p,29,23,20,0x3c40);break;
        case 1:B_BAG_MAIN_PrintLabel(p,29,24,4,0x3c40);B_BAG_MAIN_PrintLabel(p,29,25,20,0x3c40);break;
        case 2:B_BAG_MAIN_PrintLabel(p,29,26,12,0x3c40);break;
        case 3:B_BAG_MAIN_PrintLabel(p,29,27,12,0x3c40);break;
        }
    } else BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00314 *)p)->f110);
}





void func_0220B774(char *a)
{
    func_0220B520(a);
    func_0220B6C4(a);
    func_0220B584(a);
}





void func_0220B78C(u8 *p, u32_0220B78C idx)
{
    void *win = *(void **)(p + 0x120);
    void *msg = func_02045EC0(*(void **)(p + 0xc), 9);
    u8 sel = *(u8 *)(p + 0x533);
    u8 *row = p + sel * 0x90;
    void *w;
    WORDSET_Callback_EF40(*(void **)(p + 0x10), 0, *(u16 *)(row + 0x150 + idx * 4));
    func_0201F250(*(void **)(p + 0x10), *(void **)(p + 0x14), msg);
    BMP_Clear(BMP_WIN_GetBmp(win), 0);
    w = *(void **)(p + 0x18);
    PRINTSYS_PrintQueColor(w, (u32_0220B78C)BMP_WIN_GetBmp(*(void **)(p + 0x120)), 0, 0,
                  *(u32_0220B78C *)(p + 0x14), *(u32_0220B78C *)(*(u8 **)p + 4), 0x3C40);
    *(u8 *)(p + 0x124) = 1;
    STRBUF_Delete(msg);
}




/*
 * matching: named row index in Row[36][2] restores base-add-before-column-shift; raw byte row differs in seven bytes.
 */
void func_0220B814(char *p,int n)
{
    void *owner;
    int index;
    Row *row;
    void *buf=STRBUF_Create(130,((struct Obj25005 *)(*(char * *)&((struct Obj04597 *)p)->f0))->fC);
    index=((struct Obj04597 *)p)->f533;
    row=(Row *)(p+0x150);
    func_02020FB4(buf,row[index].entry[n][0],((struct Obj25007 *)(*(char * *)&((struct Obj04597 *)p)->f0))->fC);
    owner=((struct Obj04597 *)p)->f18;
    PRINTSYS_PrintQueColor(owner,(unsigned)BMP_WIN_GetBmp(((struct Obj04597 *)p)->f130),4,0,(unsigned)buf,((struct Obj25008 *)(*(char * *)&((struct Obj04597 *)p)->f0))->f4,0x3c40);
    ((struct Obj04597 *)p)->f134=1;
    STRBUF_Delete(buf);
}




/*
 * lever: the scaled index is its own int local added after each field
 *   offset (`*(short *)(*(char **)p + 0x30 + off)`), which puts the ldrb and
 *   lsls ahead of the `ldr r0,[r4]` base load (0220B8A4..0220B8AA). A row
 *   pointer `q = *(char **)p + idx*2` (either operand order, or as a short
 *   element address) loads the base first: 9 bytes.
 * prototype: func_0220B78C has no matched definition; (char *, unsigned) and
 *   void taken from its listing (r1 scaled by 4 as an index, no r0 use after).
 */
void func_0220B880(char *p)
{
    unsigned i;
    int x, y;
    int off;
    for (i = 31; i <= 34; i++)
        BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0x28 + i * 8)), 0);
    off = *(u8 *)(p + 0x533) * 2;
    x = *(short *)(*(char **)p + 0x30 + off);
    y = *(short *)(*(char **)p + 0x38 + off) * 6;
    func_0220B78C((u8 *)p, x + y);
    func_0220B3EC(p, x + y, 0, 32, 0, 0, 0);
    func_0220B814(p, x + y);
    B_BAG_MAIN_PrintLabel(p, 34, 31, 0, 0x3c40);
    *(const u8 **)(p + 0x59c) = d_0220DA08;
}





void func_0220B904(char *p)
{
    func_0201F73C(((struct Obj14543 *)p)->f24, 2, 1, 0xb);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj14543 *)p)->f24), 0xf);
    func_0220B928(p);
}




/*
 * lever: MSG_SPEED_GetWait() called inside the argument list (as the ov010
 *   0x02169EBC twin does) with its real signed char return; a font local
 *   computed before the call let mwcc CSE the two *p reads (DIFF 42).
 * prototypes: from the matched arm9 definitions, except PRINTSYS_PrintStream,
 *   whose definition is declared void although it forwards PRINTSYS_PrintStreamCallBack's
 *   r0; the return type is the ov010 twin's void *.
 */
void func_0220B928(char *p)
{
    void *d;
    GF_FONT_SetTextColor(1, 2, 0);
    *(void **)(p + 0x1c) = PRINTSYS_PrintStream(*(void **)(p + 0x24), 0, 0, *(void **)(p + 0x14),
        *(u32_0220B928 *)(*(char **)p + 4), MSG_SPEED_GetWait(), *(void **)(p + 4), 10,
        *(u16 *)(*(char **)p + 0xc), 15);
    d = *(void **)(p + 0x24);
    BMP_WIN_TransferChars(d);
    BMP_WIN_MakeScreen(d);
    func_02041B6C(BMP_WIN_GetBgLayer(d));
}





int func_0220B980(char *a)
{
    return B_APP_TOOL_Update(a + 0x28, ((struct Obj25009 *)a)->f18, 0x23);
}





/*
 * Addresses are Black-image addresses.
 */
u32_0220B990 func_0220B990(u8 *p)
{
    return B_APP_TOOL_ShowWindows(p + 0x28, ((struct Obj25010 *)p)->f59C);
}




/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
int func_0220B9A4(char *p) { char *q; if(((struct Obj06648 *)p)->f540==0) return 0; q=*(char * *)&((struct Obj06648 *)p)->f0; if(MYITEM_SAVEDATA_HasItem(*(u8 * *)&((struct Obj14544 *)q)->f0,((struct Obj06648 *)p)->f540,1,((struct Obj14544 *)q)->fC)==0) { ((struct Obj06648 *)p)->f540=0; ((struct Obj06648 *)p)->f542=0; return 0; } return 1; }




void func_0220B9D8(u8 *p)
{
    unsigned int i = 0;
    u8 sel = *(u8 *)(p + 0x533);
    u8 *row = p + sel * 0x90;
    u16 cur = *(u16 *)(p + 0x533 + 0xd);
    for (; i < 36; i++) {
        if (cur == *(u16 *)(row + 0x150 + i * 4)) {
            *(u16 *)(*(u8 **)p + sel * 2 + 0x30) = i % 6;
            *(u16 *)(*(u8 **)p + *(u8 *)(p + 0x533) * 2 + 0x38) = i / 6;
            return;
        }
    }
}





/*
 * 2026-10-05 (wD9r lane05): EXACT. The record address is an integer local reused for the row offset:
 *   `u32 e = c * 0x90; e = q[0x535] * 4 + (u32)(p + e);`. The mul stays first (e is defined in its own
 *   statement and used once more), and idx*4 is the first operand of the final add, so e shares idx*4's
 *   register (r0) and row takes r4 as in the original.
 */
void func_0220BA2C(u8 *p)
{
    u8 *tbl;
    u16 *r;
    u32_0220BA2C i, j, k;

    tbl = ARC_TOOL_LoadMember(0xE8, 0, *(u16 *)(*(u8 **)p + 0xC));
    i = 0;
    do {
        j = 0;
        for (;;) {
            r = (u16 *)func_020081DC(**(void ***)p, d_0220DB3C[i], (u16)j);
            if (r == 0)
                break;
            if (r[0] != 0 && r[1] != 0) {
                u32_0220BA2C m = tbl[r[0]];
                for (k = 0; k < 4; k++) {
                    if (m & (1 << k)) {
                        int c = d_0220DB3F[k];
                        u8 *q = p + c;
                        u32_0220BA2C e = c * 0x90;
                        e = q[0x535] * 4 + (u32_0220BA2C)(p + e);
                        *(u16 *)(e + 0x150) = r[0];
                        *(u16 *)(e + 0x152) = r[1];
                        q[0x535]++;
                    }
                }
            }
            j++;
        }
        i++;
    } while (i < 3);
    func_020307B0(tbl);
    for (i = 0; i < 4; i++) {
        u8 v = p[i + 0x535];
        u8 *s;
        if (v == 0)
            p[i + 0x539] = 0;
        else
            p[i + 0x539] = (v - 1) / 6;
        s = *(u8 **)p + i * 2;
        if (p[i + 0x539] < *(s16_0220BA2C *)(s + 0x38))
            *(s16_0220BA2C *)(s + 0x38) = p[i + 0x539];
    }
}




void func_0220BB1C(char *p)
{
    unsigned i;
    for(i=0;i<46;i++) {
        if(func_0202F114(*(const unsigned char * *)&((struct Obj25011 *)(*(char * *)&((struct Obj05520 *)p)->f0))->f10,i)==1) {
            *(unsigned short *)(p+0x150+((struct Obj05520 *)p)->f535*4)=func_0202F138(i);
            *(unsigned short *)(p+0x152+((struct Obj05520 *)p)->f535*4)=1;
            (((struct Obj05520 *)p)->f535)++;
        }
    }
    ((struct Obj05520 *)p)->f539=(((struct Obj05520 *)p)->f535-1)/6;
}





void func_0220BB78(char *p)
{
    ((struct Obj08354 *)p)->f270 = 4;
    ((struct Obj08354 *)p)->f272 = 0x1e;
    ((struct Obj08354 *)p)->f537 = 1;
    ((struct Obj08354 *)p)->f53B = 0;
}




/*
 * lever: one statement n = (n + k * 6) << 2, then p += index * 0x90 and a
 *   const u16 pointer s = p + n read as s[0xa8] / s[0xa9]; the byte-offset
 *   spelling (n += ..; n *= 4; slot + 0x150) sank the shift after the
 *   0x90 multiply (13 bytes), and a typed row struct folded 0x150 (60 bytes).
 */
u16 func_0220BB98(const char *p, unsigned n)
{
    unsigned index = *(u8 *)(p + 0x533);
    const u16 *s;
    n = (n + *(short *)(*(char **)p + 0x38 + index * 2) * 6) << 2;
    p += index * 0x90;
    s = (const u16 *)(p + n);
    if (s[0xa8] != 0 && s[0xa9] != 0) return s[0xa8];
    return 0;
}




/*
 * Forward entry r0 as the key. The explicit result truncation requires a wide extern return.
 */
int func_0220BBD8(u32_0220BBD8 key) { return (u16)sub_0202F144(key); }




void func_0220BBE4(char *p)
{
    void *arc;
    unsigned i;
    ((struct Obj01176 *)p)->f520=BGWINFRM_Create(2,14,((struct Obj25012 *)(*(char * *)&((struct Obj01176 *)p)->f0))->fC);
    arc=func_020490F4(99,(u16)((((struct Obj25013 *)(*(char * *)&((struct Obj01176 *)p)->f0))->fC&0x7FFF)|0x8000));
    for(i=0;i<14;i++){
        BGWINFRM_AddFrame(((struct Obj01176 *)p)->f520,i,6,d_0220DB44[i].w,d_0220DB44[i].h);
        BGWINFRM_SetClipArea(((struct Obj01176 *)p)->f520,i,0,64,0,64);
        BGWINFRM_SetFrameDataArcHandle(((struct Obj01176 *)p)->f520,i,arc,d_0220DB44[i].member,1);
    }
    ARC_TOOL_DeleteHandle(arc);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,0,0,1);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,1,0,10);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,2,16,1);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,3,16,10);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,4,32,1);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,5,48,1);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,6,32,7);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,7,48,7);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,8,32,13);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,9,48,13);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,11,32,19);
    BGWINFRM_PutFrame(((struct Obj01176 *)p)->f520,12,37,19);
}







void func_0220BD14(char *a)
{
    BGWINFRM_Delete(*(struct WinMgr * *)&((struct Obj25014 *)a)->f520);
}






/*
 * note 2026-10-05 (wave D4 lane 02): the two window calls 11/12 are written in each if/else
 *   arm with literal arguments. Tail merging sinks the common call parts into the join and keeps
 *   r4 = 0x533 live, so 0x520 comes out as 0x533 - 0x13.
 */
void func_0220BD24(char *p, int mode)
{
    u32 i;
    for (i = 0; i < 14; i++) BGWINFRM_HideFrame(MGR(p), i);
    switch (mode) {
    case 0:
        BGWINFRM_PutFrame(MGR(p), 10, 27, 19);
        BGWINFRM_PutFrame(MGR(p), 13, 1, 19);
        if (*(u16 *)(p + 0x540) == 0)
            BGWINFRM_ChangePalette(MGR(p), 13, 0, 0, 25, 5, 3);
        else
            BGWINFRM_ChangePalette(MGR(p), 13, 0, 0, 25, 5, 1);
        BGWINFRM_ShowFrame(MGR(p), 0);
        BGWINFRM_ShowFrame(MGR(p), 1);
        BGWINFRM_ShowFrame(MGR(p), 2);
        BGWINFRM_ShowFrame(MGR(p), 3);
        BGWINFRM_ShowFrame(MGR(p), 10);
        BGWINFRM_ShowFrame(MGR(p), 13);
        break;
    case 1: {
        struct WinMgr **pm;
        BGWINFRM_PutFrame(MGR(p), 10, 59, 19);
        pm = (struct WinMgr **)(p + 0x520);
        for (i = 0; i < 6; i++) {
            if (func_0220BB98(p, i) == 0)
                BGWINFRM_ChangePalette(MGR(p), i + 4, 0, 0, d_0220DB44[i + 4].w, d_0220DB44[i + 4].h, 6);
            else
                BGWINFRM_ChangePalette(*pm, i + 4, 0, 0, d_0220DB44[i + 4].w, d_0220DB44[i + 4].h, 4);
        }
        {
            struct S *q = (struct S *)p;
            if (q->fl[q->idx] == 0) {
                BGWINFRM_ChangePalette(q->mgr, 11, 0, 0, 5, 5, 3);
                BGWINFRM_ChangePalette(q->mgr, 12, 0, 0, 5, 5, 3);
            } else {
                BGWINFRM_ChangePalette(q->mgr, 11, 0, 0, 5, 5, 1);
                BGWINFRM_ChangePalette(q->mgr, 12, 0, 0, 5, 5, 1);
            }
        }
        BGWINFRM_ShowFrame(MGR(p), 4);
        BGWINFRM_ShowFrame(MGR(p), 5);
        BGWINFRM_ShowFrame(MGR(p), 6);
        BGWINFRM_ShowFrame(MGR(p), 7);
        BGWINFRM_ShowFrame(MGR(p), 8);
        BGWINFRM_ShowFrame(MGR(p), 9);
        BGWINFRM_ShowFrame(MGR(p), 11);
        BGWINFRM_ShowFrame(MGR(p), 12);
        BGWINFRM_ShowFrame(MGR(p), 10);
        break;
    }
    case 2:
        BGWINFRM_ChangePalette(MGR(p), 13, 0, 0, 25, 5, 1);
        BGWINFRM_PutFrame(MGR(p), 10, 27, 51);
        BGWINFRM_PutFrame(MGR(p), 13, 1, 51);
        BGWINFRM_ShowFrame(MGR(p), 10);
        BGWINFRM_ShowFrame(MGR(p), 13);
        break;
    }
}







void func_0220BF20(char *p, int v)
{
    ((struct Obj08355 *)p)->f524 = 0;
    ((struct Obj08355 *)p)->f525 = 0;
    ((struct Obj08355 *)p)->f526 = v;
    ((struct Obj08355 *)p)->f527 = 1;
}






/*
 * matching: naming unsigned index before the u8 palette settles r0/r2;
 *   unnamed repeated index loads differ in18 bytes. Callee uses u8 palette.
 */
void func_0220BF40(char *p)
{
    if(((struct Obj01005 *)p)->f527) {
        switch(((struct Obj01005 *)p)->f524) {
        case 0: {
            unsigned index=((struct Obj01005 *)p)->f526;
            u8 color;
            color=2;
            if(index<10) color=5;
            BGWINFRM_ChangePalette(((struct Obj01005 *)p)->f520,index,0,0,d_0220DB44[index].w,d_0220DB44[index].h,color);
            BGWINFRM_ShowFrame(((struct Obj01005 *)p)->f520,((struct Obj01005 *)p)->f526);
            (((struct Obj01005 *)p)->f524)++;
            break;
        }
        case 1: {
            unsigned index;
            u8 color;
            if(((struct Obj01005 *)p)->f525==4) {
                index=((struct Obj01005 *)p)->f526;
                color=1;
                if(index<10) color=4;
                BGWINFRM_ChangePalette(((struct Obj01005 *)p)->f520,index,0,0,d_0220DB44[index].w,d_0220DB44[index].h,color);
                BGWINFRM_ShowFrame(((struct Obj01005 *)p)->f520,((struct Obj01005 *)p)->f526);
                ((struct Obj01005 *)p)->f525=0;
                (((struct Obj01005 *)p)->f524)++;
            } else (((struct Obj01005 *)p)->f525)++;
            break;
        }
        case 2:
            if(((struct Obj01005 *)p)->f525==1) {
                ((struct Obj01005 *)p)->f525=0;
                ((struct Obj01005 *)p)->f524=0;
                ((struct Obj01005 *)p)->f527=0;
            } else (((struct Obj01005 *)p)->f525)++;
            break;
        }
    }
}






void func_0220C034(char *p) { func_0220C06C(p); func_0220C0B4(p); func_0220C27C(p); func_0220C304(p); func_0220C40C(p); func_0220C68C(p); func_0220C6D0(p); BG_SYS_SetSubPlaneVisible(16,1); }






void func_0220C06C(char *p)
{
    unsigned i;
    for(i=0;i<9;i++) *(int *)(p+0x544+i*4)=-1;
    for(i=0;i<9;i++) *(int *)(p+0x568+i*4)=-1;
    for(i=0;i<3;i++) *(int *)(p+0x58c+i*4)=-1;
}






/*
 * matching: arc declared before first/second fixes the three spill homes.
 *   0204ABF0 argument4 is u16: caller explicitly truncates i*32.
 *   0202F138 result widened to reproduce caller's explicit u16 narrowing;
 *   its own sub_0202F138 returns u16, which removed the observed shifts.
 */
void func_0220C0B4(char *p)
{
    u16 item,i;
    void *arc;
    unsigned first,second;
    int a;
    if(((struct Obj25015 *)(*(char * *)&((struct Obj00315 *)p)->f0))->f8==1) {item=(unsigned)func_0202F138(0);first=3;second=4;}
    else {first=1;item=1;second=2;}
    arc=func_020490F4(func_02020F08(),(u16)((((struct Obj25016 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    for(i=0;i<7;i++) {
        *(int *)(p+i*4+0x544)=CLACT_RegisterCharacter(arc,FILE_UTIL_Get(item,first),0,1,((struct Obj25017 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
        *(int *)(p+i*4+0x568)=CLACT_RegisterPalette(arc,FILE_UTIL_Get(item,second),1,(u16)(i*32),((struct Obj25018 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    }
    a=func_02020F0C();
    ((struct Obj00315 *)p)->f58C=CLACT_RegisterCellAnim(arc,a,func_02020F10(),((struct Obj25019 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ARC_TOOL_DeleteHandle(arc);
}






/*
 * matching: u16 item restores entry spill order without extra truncation; unsigned item differs in eight bytes.
 */
void func_0220C180(char *p,u16 item,unsigned slot,unsigned offset)
{
    char *q=*(char * *)&((struct Obj01075 *)p)->f0;
    unsigned first, second;
    void *arc;
    void *data,*buffer;
    if(((struct Obj14545 *)q)->f8==1) {first=3;second=4;} else {first=1;second=2;}
    arc=func_020490F4(func_02020F08(),(u16)((((struct Obj14545 *)q)->fC&0x7fff)|0x8000));
    buffer=ARC_UTIL_LoadScreenDataFromHandle(arc,FILE_UTIL_Get(item,first),0,(u32)(&data),((struct Obj25020 *)(*(char * *)&((struct Obj01075 *)p)->f0))->fC);
    CLACT_TransferCharacter(*(int *)(p+slot*4+0x544),data);
    func_020307B0(buffer);
    PALANM_LoadHandlePaletteToSlot(((struct Obj01075 *)p)->f8,(void *)((unsigned)arc),FILE_UTIL_Get(item,second),((struct Obj25021 *)(*(char * *)&((struct Obj01075 *)p)->f0))->fC,3,32,offset*16);
    ARC_TOOL_DeleteHandle(arc);
}






void func_0220C220(char *p,unsigned item,unsigned slot)
{
    char *q=*(char * *)&((struct Obj01075 *)p)->f0;
    unsigned archive;
    if(((struct Obj10833 *)q)->f8==1) {
        archive=func_02020F08();
        func_02049B40(archive,FILE_UTIL_Get(item,4),5,slot*32,32,((struct Obj10833 *)q)->fC);
    } else {
        archive=func_02020F08();
        func_02049B40(archive,FILE_UTIL_Get(item,2),5,slot*32,32,((struct Obj10833 *)q)->fC);
    }
}






void func_0220C27C(char *p)
{
    void *arc = func_020490F4(99,(u16)((((struct Obj25022 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    ((struct Obj00315 *)p)->f560=CLACT_RegisterCharacter(arc,13,1,1,((struct Obj25023 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f584=CLACT_RegisterPalette(arc,14,1,224,((struct Obj25024 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f590=CLACT_RegisterCellAnim(arc,15,16,((struct Obj25025 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    PALANM_LoadHandlePaletteToSlot(((struct Obj00315 *)p)->f8,(void *)((unsigned)arc),14,((struct Obj25026 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC,3,32,112);
    ARC_TOOL_DeleteHandle(arc);
}






void func_0220C304(char *p)
{
    void *arc = func_020490F4(11,(u16)((((struct Obj25027 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    char *data;
    void *buf;
    ((struct Obj00315 *)p)->f564=CLACT_RegisterCharacter(arc,119,0,1,((struct Obj25028 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f588=CLACT_RegisterPaletteEx(arc,116,1,256,4,1,((struct Obj25029 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f594=CLACT_RegisterCellAnim(arc,120,121,((struct Obj25030 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    buf=ARC_UTIL_LoadPaletteBlockFromHandle(arc,116,(u32)(&data),(u16)((((struct Obj25031 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    PALANM_CopyToSlot(((struct Obj00315 *)p)->f8,*(char * *)&((struct Obj25032 *)data)->fC+128,3,128,32);
    func_020307B0(buf);
    ARC_TOOL_DeleteHandle(arc);
}






/*
 * matching: const indices restores the load/store scheduling; mutable indices differ in 29 bytes.
 */
struct Obj *func_0220C3B4(char *p,const int *indices)
{
    Config c;
    c.a=0;c.b=0;c.c=0;c.d=1;c.e=1;
    return CLACT_CreateActor((void *)*(unsigned *)&((struct Obj00315 *)p)->f420,*(unsigned *)(p+indices[0]*4+0x544),*(unsigned *)(p+indices[1]*4+0x568),*(unsigned *)(p+indices[2]*4+0x58c),&c,1,((struct Obj25033 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
}






/*
 * Raw byte stride i*12 emits muls rather than the flat word-index shift/add.
 * The caller stores live r0 from C3B4; its owner declaration is void.
 */
void func_0220C40C(char *p) { u32 i; *(struct Bank * *)&((struct Obj00315 *)p)->f420=CLACT_CreateUnit(67,0,((struct Obj25034 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC); for(i=0;i<63;i++) *(u32 *)(p+i*4+0x424)=(u32)func_0220C3B4(p,(const int *)((u32)d_0220DBBC+i*12)); }






void func_0220C448(char *p)
{
    unsigned i;
    func_0220C6E8(p);
    for (i = 0; i < 63; i++) CLACT_DeleteActor(*(struct Obj **)(p + i * 4 + 0x424));
    func_0220C6C0(p);
    for (i = 0; i < 9; i++) if (*(int *)(p + i * 4 + 0x544) != -1) CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0x544));
    for (i = 0; i < 9; i++) if (*(int *)(p + i * 4 + 0x568) != -1) CLACT_ReleasePalette(*(int *)(p + i * 4 + 0x568));
    for (i = 0; i < 3; i++) if (*(int *)(p + i * 4 + 0x58c) != -1) CLACT_ReleaseCellAnim(*(int *)(p + i * 4 + 0x58c));
    CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj25035 *)p)->f420);
}







void func_0220C4D4(int a, int b)
{
    CLACT_SetActorDrawEnable((struct Obj *)a, 1);
    CLACT_AddActorSurfacePos((struct Obj *)a, (const struct Vec2 *)b, 1);
}






void func_0220C4EC(char *p, int mode)
{
    unsigned int i;
    for (i = 0; i < 63; i++) CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x424), 0);
    func_0220C714(p);
    switch (mode) {
    case 0: func_0220C538(p); break;
    case 1: func_0220C574(p); break;
    case 2: func_0220C618(p); break;
    }
}




void func_0220C538(char *p) { if(((struct Obj01075 *)p)->f540!=0) { func_0220C180(p,((struct Obj01075 *)p)->f540,6,6); func_0220C4D4(((struct Obj01075 *)p)->f43C,(int)d_0220DB7C); } if(((struct Obj25036 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8==2) func_0220C6F8((u8 *)p,192,24); }





void func_0220C574(char *p)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        u16 item = func_0220BB98(p, i);
        if (item) {
            func_0220C180(p, item, i, i);
            func_0220C220(p, item, i);
            func_0220C4D4(*(int *)(p + i * 4 + 0x424), (int)&d_0220DB88[i]);
            if (((struct Obj25037 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8 == 1)
                func_0220C724(p, i * 8 + 7, func_0220BBD8(item), 0, (const struct Pair_0220C6E8 *)(&d_0220DB88[i + 6]));
        }
    }
    if (((struct Obj25038 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8 == 1)
        func_0220C724(p, 55, ((struct Obj25039 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f14, ((struct Obj25040 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f15, (const struct Pair_0220C6E8 *)(&d_0220DB88[i + 6]));
    if (((struct Obj25041 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8 == 2) func_0220C6F8((u8 *)p, 64, 16);
}





/*
 * caller-width: BB98 takes full signed short promotion; no u16 truncation in this caller.
 */
void func_0220C618(char *p)
{
    u16 item = func_0220BB98(p, *(short *)(*(char * *)&((struct Obj01075 *)p)->f0 + ((struct Obj01075 *)p)->f533 * 2 + 0x30));
    func_0220C180(p, item, 6, 6);
    func_0220C4D4(((struct Obj01075 *)p)->f43C, (int)&d_0220DB80[0]);
    if (((struct Obj25042 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8 == 1)
        func_0220C724(p, 7, func_0220BBD8(item), 0, (const struct Pair_0220C6E8 *)(&d_0220DB80[1]));
    if (((struct Obj25043 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8 == 2) func_0220C6F8((u8 *)p, 0x68, 0x98);
}





void func_0220C68C(char *p){B_APP_TOOL_CreateActors(*(char * *)&((struct Obj00315 *)p)->f148,*(int *)&((struct Obj00315 *)p)->f420,((struct Obj00315 *)p)->f564,((struct Obj00315 *)p)->f588,((struct Obj00315 *)p)->f594);B_APP_TOOL_SetActorsVisible(*(char * *)&((struct Obj00315 *)p)->f148,0);}






void func_0220C6C0(char *a)
{
    B_APP_TOOL_DeleteActors((u8 *)(((struct Obj25044 *)a)->f148));
}






void func_0220C6D0(char *a)
{
    ((struct Obj00315 *)a)->f14C = BTLV_FINGER_CURSOR_Create(*(int *)&((struct Obj00315 *)a)->f8, 9,
                                         *(unsigned short *)(*(int *)&((struct Obj00315 *)a)->f0 + 0xc));
}





void func_0220C6E8(char *a)
{
    BTLV_FINGER_CURSOR_Delete(((struct Obj25045 *)a)->f14C);
}





void func_0220C6F8(u8 *p, u32 a, u32 b)
{
    BTLV_FINGER_CURSOR_Start(((struct Obj25046 *)p)->f14C, a, b, 2, 6, 0x14);
}





void func_0220C714(char *a)
{
    BTLV_FINGER_CURSOR_DeleteActor(((struct Obj25047 *)a)->f14C);
}




/*
 * matching: pair aggregate copy emits two unsigned halfword transfers;
 *   explicit objects base keeps the first indexed address split correctly.
 */
void func_0220C724(char *p,u16 slot,u8 a,u8 b,const struct Pair_0220C6E8 *src)
{
    struct Pair_0220C6E8 v;
    u16 i;
    s8 left,right;
    void **objects=(void **)(p+0x424);
    func_0220C4D4((int)objects[slot],(int)src);
    CLACT_SetActorAnimSeq(objects[slot],a);
    slot++;
    left=a;
    right=b;
    v=*src;
    v.x+=12;
    for(i=0;i<7;i++) {
        if(left<=0) {
            if(right<=0) CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),15);
            else if(right==1) {CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),19);right--;}
            else {CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),20);right-=2;}
        } else if(left==1) {
            if(right==0) CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),16);
            else if(right>0) {CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),18);right--;}
            left--;
        } else {CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),17);left-=2;}
        func_0220C4D4(*(int *)(p+slot*4+0x424),(int)&v);
        v.x+=8;
        slot++;
    }
}





/*
 * lever: Size constant held in a local (offsets derived from it), the 0x533 store repeated in each arm instead of one shared tail, and no row-pointer local in the first loop (*(u8 **)p re-read per argument).
 */
void func_0220C834(u8 *arg)
{
    u8 *p;
    u8 *q;
    int z;
    u32 i;
    int v;
    int sz = 0x5A4;
    p = func_02030734(*(u16 *)(arg + 0xc), sz, 1, d_0220E0E0, 0xB1);
    q = func_02030DA8(BTLV_EFFECT_GetOwner(), (u32)func_0220C914, p, 0x64);
    *(u8 **)p = arg;
    *(void **)(p + 8) = (void *)BTLV_EFFECT_GetPalanm();
    z = 0;
    *(int *)(p + sz - 4) = z;
    if (*(int *)(*(u8 **)p + 8) == 1) {
        p[sz - 0x72] = 1;
        p[sz - 0x74] = 1;
        p[sz - 0x71] = z;
    } else if (*(int *)(*(u8 **)p + 8) == 3) {
        p[sz - 0x72] = 1;
        p[sz - 0x74] = z;
        z = 2;
        p[sz - 0x71] = z;
    } else {
        p[sz - 0x72] = z;
        p[sz - 0x74] = z;
        p[sz - 0x71] = z;
    }
    if (*(int *)(*(u8 **)p + 8) != 1) {
        for (i = 0; i < 4; i++) {
            func_0200829C((const struct MyItemSave *)(*(u32 *)(*(u8 **)p + 0x1c)), (u16)i, (s16_0220C834 *)(*(u8 **)p + 0x30 + i * 2), (s16_0220C834 *)(*(u8 **)p + 0x38 + i * 2));
        }
        *(u16 *)(p + 0x540) = func_020082B0((const struct MyItemSave *)(*(u32 *)(*(u8 **)p + 0x1c)));
        p[0x542] = func_020082B4((const struct MyItemSave *)(*(u32 *)(*(u8 **)p + 0x1c)));
        func_0220B9A4((char *)p);
    } else {
        for (i = 0; i < 4; i++) {
            *(u16 *)(*(u8 **)p + i * 2 + 0x30) = 0;
            *(u16 *)(*(u8 **)p + i * 2 + 0x38) = 0;
        }
    }
}




extern int (*const d_0220DF40[])(char *);




void func_0220C914(void *task, char *p)
{
    if (((struct Obj25048 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f24 == 1) {
        ((struct Obj25049 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f16 = 0;
        ((struct Obj25050 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f18 = 0;
        ((struct Obj00846 *)p)->f530 = 20;
    }
    if (((struct Obj00846 *)p)->f530 != 20) ((struct Obj00846 *)p)->f530 = d_0220DF40[*(u8 *)(p + 0x530)](p);
    if (((struct Obj00846 *)p)->f530 == 20 && func_0220D3B0(task, p) == 1) return;
    TCBL_Main(*(struct Tcbl * *)&((struct Obj00846 *)p)->f4);
    func_0220BF40(p);
    BGWINFRM_UpdateMoves(*(struct WinMgr * *)&((struct Obj00846 *)p)->f520);
    func_0220B980(p);
}




/*
 * lever: word-address arithmetic reuses the MMIO pool base, as in matched ov197 0220CAAC.
 */
int func_0220C980(char *p)
{
    d_04001050[0]=0;
    GXx_SetMasterBrightness_((u16 *)((unsigned)d_04001050+0x1c),-16);
    ((struct Obj00736 *)p)->f4=TCBL_Create(((struct Obj25051 *)(*(char * *)&((struct Obj00736 *)p)->f0))->fC,((struct Obj25052 *)(*(char * *)&((struct Obj00736 *)p)->f0))->fC,1,4);
    ((struct Obj00736 *)p)->f148=B_APP_TOOL_Create(((struct Obj25053 *)(*(char * *)&((struct Obj00736 *)p)->f0))->fC);
    func_0220D5C0(p);
    func_0220D6DC(p);
    func_0220D798(p);
    if(((struct Obj25054 *)(*(char * *)&((struct Obj00736 *)p)->f0))->f8==2) func_0220BB78(p);
    else func_0220BA2C((u8 *)p);
    B_BAG_MAIN_InitWindows(p);
    B_BAG_MAIN_DrawPage(p,((struct Obj00736 *)p)->f532);
    func_0220B990((u8 *)p);
    func_0220BBE4(p);
    func_0220BD24(p,((struct Obj00736 *)p)->f532);
    func_0220C034(p);
    func_0220C4EC(p,((struct Obj00736 *)p)->f532);
    if(**(u8 * *)&((struct Obj25055 *)(*(char * *)&((struct Obj00736 *)p)->f0))->f2C==1) ((struct Obj00736 *)p)->f598=(void *)1;
    else ((struct Obj00736 *)p)->f598=0;
    B_APP_TOOL_SetActorsVisible(*(char * *)&((struct Obj00736 *)p)->f148,((struct Obj00736 *)p)->f598);
    if(((struct Obj00736 *)p)->f532==0) func_0220D8C4((u8 *)p,((struct Obj00736 *)p)->f532,((struct Obj00736 *)p)->f542);
    else func_0220D8C4((u8 *)p,((struct Obj00736 *)p)->f532,0);
    GFL_NET_RestartWithDefaultTimeout(0,((struct Obj25057 *)(*(char * *)&((struct Obj00736 *)p)->f0))->fC);
    PALANM_CopyHwPaletteToSlot(((struct Obj00736 *)p)->f8,3,224,32);
    PALANM_RequestFade(((struct Obj00736 *)p)->f8,10,65535,0,16,0,0,BTLV_EFFECT_GetOwner());
    if(((struct Obj25058 *)(*(char * *)&((struct Obj00736 *)p)->f0))->f8==3) func_0220D7F0(p,((struct Obj00736 *)p)->f532);
    ((struct Obj00736 *)p)->f5A0=1;
    return 2;
}




/*
 * lever: word-address arithmetic reuses MMIO pool base for +0x1c; typed pointer addition pools a second word.
 */
int func_0220CAAC(char *p)
{
    d_04001050[0] = 0;
    GXx_SetMasterBrightness_((u16 *)((unsigned)d_04001050 + 0x1c), -16);
    ((struct Obj01076 *)p)->f4 = TCBL_Create(((struct Obj25059 *)(*(char * *)&((struct Obj01076 *)p)->f0))->fC, ((struct Obj25060 *)(*(char * *)&((struct Obj01076 *)p)->f0))->fC, 1, 4);
    ((struct Obj01076 *)p)->f148 = B_APP_TOOL_Create(((struct Obj25061 *)(*(char * *)&((struct Obj01076 *)p)->f0))->fC);
    func_0220D5C0(p);
    func_0220D6DC(p);
    func_0220D798(p);
    func_0220BB1C(p);
    func_0220D7F0(p, ((struct Obj01076 *)p)->f532);
    B_BAG_MAIN_InitWindows(p);
    B_BAG_MAIN_DrawPage(p, ((struct Obj01076 *)p)->f532);
    func_0220B990((u8 *)p);
    func_0220BBE4(p);
    func_0220BD24(p, ((struct Obj01076 *)p)->f532);
    func_0220C034(p);
    func_0220C4EC(p, ((struct Obj01076 *)p)->f532);
    if (**(u8 * *)&((struct Obj25062 *)(*(char * *)&((struct Obj01076 *)p)->f0))->f2C == 1) ((struct Obj01076 *)p)->f598 = (void *)1;
    else ((struct Obj01076 *)p)->f598 = 0;
    B_APP_TOOL_SetActorsVisible(*(char * *)&((struct Obj01076 *)p)->f148, ((struct Obj01076 *)p)->f598);
    func_0220D8C4((u8 *)p, ((struct Obj01076 *)p)->f532, 0);
    GFL_NET_RestartWithDefaultTimeout(0, ((struct Obj25064 *)(*(char * *)&((struct Obj01076 *)p)->f0))->fC);
    PALANM_CopyHwPaletteToSlot(((struct Obj01076 *)p)->f8, 3, 0xe0, 0x20);
    PALANM_RequestFade(((struct Obj01076 *)p)->f8, 0xa, 0xffff, 0, 0x10, 0, 0, BTLV_EFFECT_GetOwner());
    ((struct Obj01076 *)p)->f5A0 = 1;
    return 2;
}




int func_0220CBB4(char *p){if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj14547 *)p)->f18)==1){WIPE_SYS_Start((void *)4,1,1,0,6,1,((struct Obj25065 *)(*(char * *)&((struct Obj14547 *)p)->f0))->fC);return 3;}return 2;}




int func_0220CBE8(char *p){if(WIPE_SYS_EndCheck()==1){if(((struct Obj25066 *)(*(char * *)&((struct Obj10835 *)p)->f0))->f8==2)return 17;if(((struct Obj25067 *)(*(char * *)&((struct Obj10835 *)p)->f0))->f8==1)return 5;if(((struct Obj25068 *)(*(char * *)&((struct Obj10835 *)p)->f0))->f8==3)return 5;return 4;}return 3;}




int func_0220CC18(char *p)
{
    unsigned sel;
    if (PALANM_GetFadeRequestBits(((struct Obj02244 *)p)->f8) != 0) goto done;
    if (func_0220D884((char **)p) == 1) return 0x12;
    sel = CURSOR_MOVE_PollRepeatInput(((struct Obj02244 *)p)->f144);
    switch (sel) {
    case 0: case 1: case 2: case 3:
        func_0220D89C((char **)p, 0x54d);
        ((struct Obj02244 *)p)->f533 = (u8)sel;
        ((struct Obj02244 *)p)->f531 = 8;
        func_0220BF20(p, (u8)sel);
        return 0x10;
    case 4:
        if (((struct Obj02244 *)p)->f540 != 0) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj02244 *)p)->f533 = ((struct Obj02244 *)p)->f542;
            ((struct Obj02244 *)p)->f531 = 9;
            func_0220B9D8((u8 *)p);
            func_0220BF20(p, 0xd);
            return 0x10;
        }
        break;
    case 5:
        func_0220D89C((char **)p, 0x552);
        ((struct Obj25069 *)(*(char * *)&((struct Obj02244 *)p)->f0))->f16 = 0;
        ((struct Obj25070 *)(*(char * *)&((struct Obj02244 *)p)->f0))->f2A = 4;
        func_0220BF20(p, 0xa);
        return 0x12;
    case (unsigned)-2:
        func_0220D89C((char **)p, 0x552);
        ((struct Obj25071 *)(*(char * *)&((struct Obj02244 *)p)->f0))->f16 = 0;
        ((struct Obj25072 *)(*(char * *)&((struct Obj02244 *)p)->f0))->f2A = 4;
        func_0220BF20(p, 0xa);
        return 0x12;
    case (unsigned)-4: case (unsigned)-3:
        func_0220D89C((char **)p, 0x548);
        break;
    case (unsigned)-8: case (unsigned)-7: case (unsigned)-6:
    case (unsigned)-5: case (unsigned)-1:
        break;
    }
done:
    return 4;
}




int func_0220CD50(char *p)
{
    unsigned sel;
    if (PALANM_GetFadeRequestBits(((struct Obj00389 *)p)->f8) != 0) goto done;
    if (func_0220D884((char **)p) == 1) return 0x12;
    sel = CURSOR_MOVE_PollRepeatInput(((struct Obj00389 *)p)->f144);
    switch (sel) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        if (func_0220BB98(p, sel) != 0) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct Obj00389 *)p)->f0 + ((struct Obj00389 *)p)->f533 * 2 + 0x30) = (u8)sel;
            ((struct Obj00389 *)p)->f531 = 9;
            func_0220BF20(p, (u8)(sel + 4));
            return 0x10;
        }
        break;
    case 6:
        func_0220D89C((char **)p, 0x552);
        func_0220BF20(p, 0xa);
        if (((struct Obj25073 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f8 == 1 || ((struct Obj25074 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f8 == 3) {
            ((struct Obj25075 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f16 = 0;
            ((struct Obj25076 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f2A = 4;
            return 0x12;
        }
        ((struct Obj00389 *)p)->f531 = 7;
        return 0x10;
    case (unsigned)-2:
        func_0220D89C((char **)p, 0x552);
        func_0220BF20(p, 0xa);
        if (((struct Obj25077 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f8 == 1 || ((struct Obj25078 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f8 == 3) {
            ((struct Obj25079 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f16 = 0;
            ((struct Obj25080 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f2A = 4;
            return 0x12;
        }
        ((struct Obj00389 *)p)->f531 = 7;
        return 0x10;
    case 7:
        if (*(u8 *)(p + ((struct Obj00389 *)p)->f533 + 0x539) != 0) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct Obj00389 *)p)->f0 + ((struct Obj00389 *)p)->f533 * 2 + 0x30) = 0;
            ((struct Obj00389 *)p)->f531 = 0xb;
            *(signed char *)&((struct Obj00389 *)p)->f534 = -1;
            func_0220BF20(p, 0xb);
            return 0x10;
        }
        break;
    case 8:
        if (*(u8 *)(p + ((struct Obj00389 *)p)->f533 + 0x539) != 0) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct Obj00389 *)p)->f0 + ((struct Obj00389 *)p)->f533 * 2 + 0x30) = 0;
            ((struct Obj00389 *)p)->f531 = 0xb;
            ((struct Obj00389 *)p)->f534 = 1;
            func_0220BF20(p, 0xc);
            return 0x10;
        }
        break;
    case (unsigned)-4: case (unsigned)-3:
        func_0220D89C((char **)p, 0x548);
        break;
    case (unsigned)-6:
        CURSOR_MOVE_GetCurrent(((struct Obj00389 *)p)->f144);
        if (*(u8 *)(p + ((struct Obj00389 *)p)->f533 + 0x539) != 0) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj00389 *)p)->f531 = 0xb;
            *(signed char *)&((struct Obj00389 *)p)->f534 = -1;
            func_0220BF20(p, 0xb);
            return 0x10;
        }
        break;
    case (unsigned)-5:
        CURSOR_MOVE_GetCurrent(((struct Obj00389 *)p)->f144);
        if (*(u8 *)(p + ((struct Obj00389 *)p)->f533 + 0x539) != 0) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj00389 *)p)->f531 = 0xb;
            ((struct Obj00389 *)p)->f534 = 1;
            func_0220BF20(p, 0xc);
            return 0x10;
        }
        break;
    case (unsigned)-8: case (unsigned)-7: case (unsigned)-1:
        break;
    }
done:
    return 5;
}




/*
 * lever: narrow value load then compound add before reading maximum fixes r0/r6 swap.
 */
int func_0220CFA4(char *p)
{
    unsigned index = ((struct Obj00314 *)p)->f533;
    short *values = (short *)(*(char * *)&((struct Obj00314 *)p)->f0 + 0x38);
    s8 value = (s8)values[index];
    u8 maximum;
    value += ((struct Obj00314 *)p)->f534;
    maximum = *(u8 *)(p + index + 0x539);
    if (value > maximum) value = 0;
    else if (value < 0) {
        values[index] = maximum;
        goto done;
    }
    values[index] = value;
done:
    func_0220B520(p);
    func_0220B584(p);
    return 12;
}




int func_0220CFF0(char *p){if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj10837 *)p)->f18)==1){func_0220B990((unsigned char *)p);func_0220C4EC(p,((struct Obj10837 *)p)->f532);func_0220BD24(p,((struct Obj10837 *)p)->f532);return 5;}return 12;}




int func_0220D024(char *p)
{
    if (func_0220D884((char **)p) == 1) return 0x12;
    switch ((unsigned)CURSOR_MOVE_PollRepeatInput(((struct Obj02245 *)p)->f144)) {
    case 0:
        func_0220D89C((char **)p, 0x54d);
        ((struct Obj25081 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f16 = func_0220BB98(p, *(short *)(*(char * *)&((struct Obj02245 *)p)->f0 + ((struct Obj02245 *)p)->f533 * 2 + 0x30));
        ((struct Obj25082 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f2A = ((struct Obj02245 *)p)->f533;
        if (((struct Obj25083 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f8 == 1)
            ((struct Obj25085 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f18 = func_0220BBD8(((struct Obj25084 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f16);
        else
            ((struct Obj25086 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f18 = 0;
        func_0220BF20(p, 0xd);
        return func_0220D11C(p);
    case 1:
        func_0220D89C((char **)p, 0x552);
        ((struct Obj02245 *)p)->f531 = 8;
        func_0220BF20(p, 0xa);
        return 0x10;
    case (unsigned)-2:
        func_0220D89C((char **)p, 0x552);
        ((struct Obj02245 *)p)->f531 = 8;
        func_0220BF20(p, 0xa);
        return 0x10;
    case (unsigned)-4:
    case (unsigned)-3:
        func_0220D89C((char **)p, 0x548);
        break;
    case (unsigned)-8:
    case (unsigned)-7:
    case (unsigned)-6:
    case (unsigned)-5:
    case (unsigned)-1:
        break;
    }
    return 6;
}




/*
 * Owner unit_02045C44.c omits MSGDATA_ReadString in function:. Verified EXACT344 C
 * below copied from ov173_func_021B71C4.c, prior ov070 fixed-flag --arm one.
 * abi: BBD8 returns a zero-extended u16; int extern preserves the original signed bge against the u8 field, unlike older unsigned caller externs.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void MSGDATA_ReadString(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 */
int func_0220D11C(char *p)
{
    char *q = *(char **)p;
    if (*(int *)(q + 8) == 1 && *(u8 *)(q + 0x14) < func_0220BBD8(*(u16 *)(q + 0x16))) {
        MSGDATA_ReadString(*(void **)(p + 0xc), 0x31, *(void **)(p + 0x14));
        func_0220B904(p);
        *(u8 *)(p + 0x531) = 0xd;
        return 0xe;
    }
    if (*(u8 *)(p + 0x533) == 2) {
        if (*(u8 *)(q + 0x28) == 1) {
            MSGDATA_ReadString(*(void **)(p + 0xc), 0x2d, *(void **)(p + 0x14));
            func_0220B904(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
        if (*(u8 *)(q + 0x28) == 2) {
            MSGDATA_ReadString(*(void **)(p + 0xc), 0x2c, *(void **)(p + 0x14));
            func_0220B904(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
        if (*(u8 *)(q + 0x28) == 3) {
            MSGDATA_ReadString(*(void **)(p + 0xc), 0x33, *(void **)(p + 0x14));
            func_0220B904(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
        if (*(u8 *)(q + 0x28) == 4) {
            MSGDATA_ReadString(*(void **)(p + 0xc), 0x2f, *(void **)(p + 0x14));
            func_0220B904(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
    }
    if (*(u8 *)(q + 0x29) == 0 && FILE_UTIL_Get_0FE4((void *)(unsigned)*(u16 *)(q + 0x16), 7, *(u16 *)(q + 0xc)) == 3) {
        MSGDATA_ReadString(*(void **)(p + 0xc), 0x32, *(void **)(p + 0x14));
        func_0220B904(p);
        *(u8 *)(p + 0x531) = 0xd;
        return 0xe;
    }
    return 0x12;
}




int func_0220D214(char *p){B_BAG_MAIN_DrawPage(p,0);((struct Obj14548 *)p)->f532=0;((struct Obj14548 *)p)->f531=4;return 10;}




int func_0220D234(char *p){B_BAG_MAIN_DrawPage(p,1);((struct Obj14549 *)p)->f532=1;((struct Obj14549 *)p)->f531=5;return 10;}




int func_0220D254(char *p){B_BAG_MAIN_DrawPage(p,2);((struct Obj14550 *)p)->f532=2;((struct Obj14550 *)p)->f531=6;return 10;}




int func_0220D274(char *p){if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj10838 *)p)->f18)==1){func_0220D848(p,((struct Obj10838 *)p)->f532);return ((struct Obj10838 *)p)->f531;}return 10;}





int func_0220D29C(char *a)
{
    func_0201F7A8((void *)(((struct Obj25087 *)a)->f24), 0);
    return 6;
}




int func_0220D2AC(char *p)
{
    switch (PRINTSYS_PrintStreamGetState(*(struct Rec * *)&((struct Obj03346 *)p)->f1C)) {
    case 0:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetCont() & 3)) PRINTSYS_PrintStreamShortWait(*(struct Rec * *)&((struct Obj03346 *)p)->f1C, 0);
        ((struct Obj03346 *)p)->f20 = 0;
        break;
    case 1:
        if (!((struct Obj03346 *)p)->f20 && (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3))) {
            func_0220D8B0((char **)p, 0x547);
            PRINTSYS_PrintStreamReleasePause(*(struct Rec * *)&((struct Obj03346 *)p)->f1C);
            ((struct Obj03346 *)p)->f20 = 1;
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj03346 *)p)->f1C);
        *(int *)&((struct Obj03346 *)p)->f1C = 0;
        ((struct Obj03346 *)p)->f20 = 0;
        return 15;
    }
    return 14;
}




/*
 * trailing: larger follower filed as ov197_func_0220D358.c (parent cleared).
 */
int func_0220D328(char *p)
{
    if (func_0220D884((char **)p) == 1) return 18;
    if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg() == 1)
        return ((struct Obj25088 *)p)->f531;
    return 15;
}




/*
 * lever: explicit else preserves the nonzero arm after the field-return arm.
 * leaf: parent-cleared 24-byte follower in D328 extent.
 */
int func_0220D358(char *p)
{
    if (((struct Obj14551 *)p)->f527 == 0) {
        return ((struct Obj14551 *)p)->f531;
    } else {
        return 16;
    }
}




int func_0220D370(char *p){PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj25089 *)p)->f8,10,65535,0,0,16,0,BTLV_EFFECT_GetOwner());return 19;}





int func_0220D39C(char *a)
{
    if (PALANM_GetFadeRequestBits((const char *)(((struct Obj25090 *)a)->f8)) == 0)
        return 0x14;
    return 0x13;
}




/*
 * lever: explicit if/else field stores preserve one-first branch and shared store.
 */
int func_0220D3B0(struct Node *task, char *p)
{
    if (((struct Obj00846 *)p)->f5A0 == 1) {
        if (PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj00846 *)p)->f18) == 0) {
            if (((struct Obj25091 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f24 == 1) PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj00846 *)p)->f18);
            else return 0;
        }
        if (WIPE_SYS_EndCheck() == 0) {
            if (((struct Obj25092 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f24 == 1) WIPE_SYS_ExeEnd();
            else return 0;
        }
        if (*(struct Rec3 * *)&((struct Obj00846 *)p)->f1C) PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj00846 *)p)->f1C);
        func_0220BD14(p);
        func_0220C448(p);
        B_BAG_MAIN_ExitWindows(p);
        func_0220D7D0(p);
        func_0220D6B8();
        TCBL_Destroy(*(struct S02031140 * *)&((struct Obj00846 *)p)->f4);
        func_0220D914((u8 *)p);
        B_APP_TOOL_Delete(((struct Obj00846 *)p)->f148);
        if (((struct Obj00846 *)p)->f598 == 1) {
            **(u8 * *)&((struct Obj25093 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f2C = 1;
        } else {
            **(u8 * *)&((struct Obj25095 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f2C = 0;
        }
    }
    ((struct Obj25097 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f19 = 1;
    func_02030EAC(task);
    func_020307B0(p);
    return 1;
}




int func_0220D464(char *p)
{
    switch (((struct Obj00688 *)p)->f53D) {
    case 0:
        if (BTLV_FINGER_CURSOR_IsActive(((struct Obj00688 *)p)->f14C) == 1) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj00688 *)p)->f533 = 2;
            ((struct Obj00688 *)p)->f531 = 0x11;
            func_0220BF20(p, 2);
            ++((struct Obj00688 *)p)->f53D;
            return 0x10;
        }
        break;
    case 1:
        if (BTLV_FINGER_CURSOR_IsActive(((struct Obj00688 *)p)->f14C) == 0) {
            func_0220D234(p);
            ++((struct Obj00688 *)p)->f53D;
            ((struct Obj00688 *)p)->f531 = 0x11;
            return 0xa;
        }
        break;
    case 2:
        if (BTLV_FINGER_CURSOR_IsActive(((struct Obj00688 *)p)->f14C) == 1) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct Obj00688 *)p)->f0 + ((struct Obj00688 *)p)->f533 * 2 + 0x30) = 0;
            ((struct Obj00688 *)p)->f531 = 0x11;
            func_0220BF20(p, 4);
            ++((struct Obj00688 *)p)->f53D;
            return 0x10;
        }
        break;
    case 3:
        if (BTLV_FINGER_CURSOR_IsActive(((struct Obj00688 *)p)->f14C) == 0) {
            func_0220D254(p);
            ++((struct Obj00688 *)p)->f53D;
            ((struct Obj00688 *)p)->f531 = 0x11;
            return 0xa;
        }
        break;
    case 4:
        if (BTLV_FINGER_CURSOR_IsActive(((struct Obj00688 *)p)->f14C) == 1) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj25098 *)(*(char * *)&((struct Obj00688 *)p)->f0))->f16 = func_0220BB98(p, *(short *)(*(char * *)&((struct Obj00688 *)p)->f0 + ((struct Obj00688 *)p)->f533 * 2 + 0x30));
            ((struct Obj25099 *)(*(char * *)&((struct Obj00688 *)p)->f0))->f2A = ((struct Obj00688 *)p)->f533;
            ((struct Obj25100 *)(*(char * *)&((struct Obj00688 *)p)->f0))->f18 = 0;
            func_0220BF20(p, 0xd);
            ++((struct Obj00688 *)p)->f53D;
        }
        break;
    case 5:
        if (BTLV_FINGER_CURSOR_IsActive(((struct Obj00688 *)p)->f14C) == 0) return func_0220D11C(p);
        break;
    }
    return 0x11;
}




void func_0220D5C0(char *p)
{
 struct BgVramReq req=d_0220DEB0;
 struct BgTemplate b7,b6,b5,b4;
 func_0203FC6C(&req,1);
 b7=d_0220DEE0;BG_SYS_InitBgLayer(7,&b7,0);
 b6=d_0220DF20;BG_SYS_InitBgLayer(6,&b6,0);
 b5=d_0220DF00;BG_SYS_InitBgLayer(5,&b5,0);BG_SYS_ClearSlot(5);
 b4=d_0220DEC0;BG_SYS_InitBgLayer(4,&b4,0);BG_SYS_ClearSlot(4);
 BG_SYS_InitRun(5,32,0,((struct Obj25101 *)(*(char * *)&((struct Obj14552 *)p)->f0))->fC);
 BG_SYS_InitRun(4,32,0,((struct Obj25102 *)(*(char * *)&((struct Obj14552 *)p)->f0))->fC);
 func_02041B6C(5);func_02041B6C(4);BG_SYS_SetSubPlaneVisible(15,1);
}





void func_0220D6B8(void)
{
    BG_SYS_SetSubPlaneVisible(0x1f, 0);
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
}




void func_0220D6DC(char *p)
{
    void *handle = func_020490F4(99,(u16)((((struct Obj25103 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC & 0x7fff) | 0x8000));
    func_02049658(handle, 0, 6, 0, 0, 1, ((struct Obj25104 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC);
    func_020498F4(handle, 3, 6, 0, 0, 1, ((struct Obj25105 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC);
    func_020498F4(handle, 2, 7, 0, 0, 1, ((struct Obj25106 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC);
    PALANM_LoadHandlePaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj02914 *)p)->f8, (void *)((u32)handle), 1, ((struct Obj25107 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC, 1, 224, 0);
    ARC_TOOL_DeleteHandle(handle);
    func_0201F5BC(4, 1, 11, 0, ((struct Obj25108 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj02914 *)p)->f8, 1, 176, 32);
    PALANM_LoadArcPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj02914 *)p)->f8, 23, 5, ((struct Obj25109 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC, 1, 32, 192);
}




void func_0220D798(char *p){*(struct MsgBank * *)&((struct Obj03906 *)p)->fC=func_02045B38(0,2,17,((struct Obj25110 *)(*(char * *)&((struct Obj03906 *)p)->f0))->fC);*(struct WordSet * *)&((struct Obj03906 *)p)->f10=GF_FONT_Create_EC64(((struct Obj25111 *)(*(char * *)&((struct Obj03906 *)p)->f0))->fC);((struct Obj03906 *)p)->f18=PRINTSYS_QUE_Create((void *)((struct Obj25112 *)(*(char * *)&((struct Obj03906 *)p)->f0))->fC);*(struct U16Vec * *)&((struct Obj03906 *)p)->f14=STRBUF_Create(512,((struct Obj25113 *)(*(char * *)&((struct Obj03906 *)p)->f0))->fC);}




/*
 * Tail: two zero alignment bytes at 0x0220D7EE.
 */
void func_0220D7D0(char *p){MSGDATA_Delete(((struct Obj08356 *)p)->fC);WORDSET_DeleteStrbufED04(*(struct WordSet * *)&((struct Obj08356 *)p)->f10);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj08356 *)p)->f18);STRBUF_Delete(((struct Obj08356 *)p)->f14);}




/*
 * trailing: 2 zero alignment bytes at 0x0220D846.
 */
void func_0220D7F0(void *unused, int mode)
{
    switch (mode) {
    case 0:
        BG_SYS_ResetSlot(6, 0, 0);
        BG_SYS_ResetSlot(6, 3, 0);
        break;
    case 1:
        BG_SYS_ResetSlot(6, 0, 256);
        BG_SYS_ResetSlot(6, 3, 0);
        break;
    case 2:
        BG_SYS_ResetSlot(6, 0, 0);
        BG_SYS_ResetSlot(6, 3, 256);
        break;
    }
}




void func_0220D848(char *p,int mode){func_0220D7F0(p,mode);func_02041570(4,0);func_02041570(5,0);func_0220B990((unsigned char *)p);func_0220BD24(p,mode);func_0220D924((unsigned char *)p,mode,0);func_0220C4EC(p,mode);}





int func_0220D884(char **p)
{
    if (((struct Obj25114 *)(*p))->f20 == 1) {
        ((struct Obj25115 *)(*p))->f16 = 0;
        ((struct Obj25116 *)(*p))->f18 = 0;
        return 1;
    }
    return 0;
}





void func_0220D89C(char **a, int b)
{
    if (((struct Obj25118 *)(*a))->f40 == 1)
        GFL_USE_PlaySeDefaultVolume(b);
}





void func_0220D8B0(char **a, int b)
{
    if (((struct Obj25120 *)(*a))->f40 == 1)
        GFL_USE_PlaySeDefaultVolume(b);
}




void func_0220D8C4(u8 *p, u32 index, u32 value)
{
    *(struct Struct_02025CD0 * *)&((struct Obj03347 *)p)->f144 = CURSOR_MOVE_Create(d_0220DF9C[index], d_0220DF90[index], (u32)p, ((struct Obj03347 *)p)->f598, (u8)value, ((struct Obj25121 *)(*(u8 * *)&((struct Obj03347 *)p)->f0))->fC);
    CURSOR_MOVE_EnableInput(*(struct Struct_02025D1C * *)&((struct Obj03347 *)p)->f144);
    CURSOR_MOVE_SetMode(*(struct Struct_02025D24 * *)&((struct Obj03347 *)p)->f144);
    func_0220D98C(p, value);
}





/*
 *   traced func_ label), so neither label nor sole-ref/code can attest it;
 *   byte-correct otherwise.  Not resolvable from this packet.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0220D914(u8 *p)
{
    return CURSOR_MOVE_Delete((void *)(((struct Obj25122 *)p)->f144));
}




/*
 * lever: an outer switch preserves the unconditional default-arm branch.
 */
void func_0220D924(u8 *p, int state, int value)
{
    switch (*(int *)&((struct Obj03347 *)p)->f598) {
    case 0: value = 0; break;
    default:
        switch (state) {
        case 0: value = p[0x533]; break;
        case 1: value = *(s16_0220D924 *)(*(char * *)&((struct Obj03347 *)p)->f0 + p[0x533] * 2 + 0x30); break;
        case 2: value = 0; break;
        }
        break;
    }
    func_0220D914(p);
    func_0220D8C4(p, state, value);
}





void func_0220D974(char *a, int b)
{
    ((struct Obj06649 *)a)->f598 = b;
    B_APP_TOOL_SetActorsVisible((char *)(*(int *)&((struct Obj06649 *)a)->f148), (void *)b);
}





void func_0220D98C(u8 *p, u32 idx)
{
    void *t = CURSOR_MOVE_GetEntry(*(void ** *)&((struct Obj06649 *)p)->f144, idx);

    B_APP_TOOL_LayoutActors((int *)(((struct Obj06649 *)p)->f148), (u8 *)((u32)t));
}




void func_0220D9A8(u8 *p,u32 i){func_0220D98C(p,i);func_0220D974((char *)p,1);}




void func_0220D9BC(char *p){func_0220D974(p,0);}




void func_0220D9C8(char *p){func_0220D974(p,0);}




void func_0220D9D4(u8 *p,u32 i){func_0220D98C(p,i);}


void B_BAG_MAIN_HandleSelection(char *p, int b)
{
    if ((unsigned int)(b - 7) <= 1) {
        CURSOR_MOVE_SetCurrent((struct Sound *)(*(int *)&((struct Obj06649 *)p)->f144), 0);
        b = 0;
    }
    func_0220D98C((u8 *)p, b);
    func_0220D974(p, 1);
}
