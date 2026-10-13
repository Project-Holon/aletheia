/*
 * file:     musical_mcss.c
 * unit:     yes
 * function: func_021F40D0, func_021F40F4, func_021F4280, func_021F4284, func_021F4300, func_021F4350, func_021F44E8, func_021F44F8, func_021F4684, func_021F46A8, func_021F4748, func_021F4794, func_021F4804, func_021F485C, func_021F48C0, func_021F4948, func_021F4990, func_021F4AA8, func_021F4AC8, func_021F4AF0, func_021F4AFC, func_021F4B10, func_021F4B24, func_021F4B30, func_021F4B3C, func_021F4B4C, func_021F4B54, func_021F4B88, func_021F4C1C, func_021F4C94, func_021F4D40, func_021F4D74, func_021F4DE0, func_021F4E2C, func_021F4E6C, func_021F4E8C, func_021F4EA4, func_021F4EB4, func_021F4EC4, func_021F4ED4, func_021F4EE0, func_021F4EE8, func_021F4EFC, func_021F4F04, func_021F4F10, func_021F4F14, func_021F4F40, func_021F4F54, func_021F4F60, func_021F4F70, func_021F4F74, func_021F4FF4, func_021F5064, func_021F50D0, func_021F50E0, func_021F50F4, func_021F5140, func_021F514C, func_021F5158, func_021F5164, func_021F51B0, func_021F51E8, func_021F51F4, func_021F5204, func_021F5330, func_021F5350, func_021F535C, func_021F5368, func_021F5374, func_021F5388, func_021F539C, func_021F53B4, func_021F53CC, func_021F53D8, func_021F5414, func_021F5424, func_021F5438, func_021F5444, func_021F5450, func_021F545C, func_021F5464, func_021F546C, func_021F5518, func_021F55F8, func_021F5644, func_021F5678, func_021F56BC, func_021F5EDC, func_021F611C, func_021F61D8, func_021F621C, func_021F622C, func_021F6230, func_021F6234, func_021F624C, func_021F6264, func_021F626C, func_021F6280, func_021F6290, func_021F62A0, func_021F62B0, func_021F62D0, func_021F62DC, func_021F62EC, func_021F62FC, func_021F63B8, func_021F6540, func_021F659C, func_021F65EC, func_021F660C, func_021F6744, func_021F675C, func_021F67E0, func_021F685C, func_021F6888, func_021F68BC
 * address:  0x021F40D0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F8264 0x021F8264 data a4
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02049B40 0x02049B40 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_SetString 0x02045924 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02030734 0x02030734 arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021F8394 0x021F8394 data a1
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020307B0 0x020307B0 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   func_0200A640 0x0200A640 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_0200FB24 0x0200FB24 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   TCBL_Main 0x020310C4 arm
 *   func_02041EE4 0x02041EE4 arm
 *   d_021F8290 0x021F8290 data a1
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020413B0 0x020413B0 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   d_021F8298 0x021F8298 data a4
 *   d_021F82B8 0x021F82B8 data a4
 *   d_021F82D8 0x021F82D8 data a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   TCBL_Create 0x0203101C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   d_021F83A4 0x021F83A4 data a1
 *   NNS_GfdResetVramTransferTaskQueue 0x02061C30 arm
 *   BILLBOARD_SetElemPos 0x0204F638 arm
 *   BILLBOARD_SetElemScale 0x0204F684 arm
 *   BILLBOARD_SetElemRotZ 0x0204F7C4 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   ARC_TOOL_GetArchiveFileCount 0x02049030 arm
 *   func_0204EDD0 0x0204EDD0 arm
 *   G3D_SYSTEM_CreateResourceArc 0x02046DB8 arm
 *   BILLBOARD_AddImage 0x0204EF58 arm
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 *   d_021F8300 0x021F8300 data a4
 *   BILLBOARD_FreeElem 0x0204F5A8 arm
 *   BILLBOARD_ReleaseImageVramIfUsed 0x0204F1A0 arm
 *   BILLBOARD_SetElemId 0x0204F604 arm
 *   func_0204F2CC 0x0204F2CC arm
 *   func_0204F32C 0x0204F32C arm
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 *   d_021F83B4 0x021F83B4 data a1
 *   sub_02030734 0x02030734 arm
 *   d_021F83C4 0x021F83C4 data a1
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   func_02019D30 0x02019D30 thumb
 *   func_02019D58 0x02019D58 thumb
 *   POKEGRA_GetCbrArcIndex 0x0202D09C thumb
 *   POKEGRA_GetPalArcIndex 0x0202D0D4 thumb
 *   POKEGRA_GetCelArcIndex 0x0202D110 thumb
 *   POKEGRA_GetAnmArcIndex 0x0202D144 thumb
 *   POKEGRA_GetMCelArcIndex 0x0202D178 thumb
 *   POKEGRA_GetMAnmArcIndex 0x0202D1AC thumb
 *   POKEGRA_GetNcecArcIndex 0x0202D1E0 thumb
 *   d_021F83D4 0x021F83D4 data a1
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   NNS_G2dTickMCAnimation 0x020649D4 arm
 *   func_0207D7C4 0x0207D7C4 arm
 *   func_0207B67C 0x0207B67C arm
 *   func_02082B60 0x02082B60 arm
 *   func_0207ADE8 0x0207ADE8 arm
 *   func_0207B5C0 0x0207B5C0 arm
 *   func_0207BE14 0x0207BE14 arm
 *   func_0207C768 0x0207C768 arm
 *   func_0207D8FC 0x0207D8FC arm
 *   func_0207D888 0x0207D888 arm
 *   func_0207AF38 0x0207AF38 thumb
 *   func_0207B51C 0x0207B51C arm
 *   func_0207CA00 0x0207CA00 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   d_02148D8C 0x02148D8C data
 *   d_02148D98 0x02148D98 data
 *   d_02148DA4 0x02148DA4 data
 *   d_021F8310 0x021F8310 data ov112
 *   d_021F831C 0x021F831C data ov112
 *   d_021F8304 0x021F8304 data ov112
 *   d_02148B98 0x02148B98 data
 *   d_02148B54 0x02148B54 data
 *   func_0207D760 0x0207D760 arm
 *   func_020627D8 0x020627D8 arm
 *   NNS_G2dSetAnimSequenceToMCAnimation 0x0206469C arm
 *   func_02063790 0x02063790 arm
 *   func_020637D4 0x020637D4 arm
 *   ARC_UTIL_LoadCellBankFromArchive 0x02049FBC arm
 *   ARC_UTIL_LoadMultiCellBankFromArchive 0x0204A03C arm
 *   ARC_UTIL_LoadAnimBankFromArchive 0x0204A0BC arm
 *   ARC_UTIL_LoadMultiAnimBankFromArchive 0x0204A13C arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   func_02049DB4 0x02049DB4 arm
 *   func_02049F34 0x02049F34 arm
 *   MCSS_TOOL_DrawSpindaSpots 0x020172D8 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02063A54 0x02063A54 arm
 *   func_02063E54 0x02063E54 arm
 *   NNS_G2dGetMCWorkAreaSize 0x020648B4 arm
 *   NNS_G2dInitMCAnimation 0x02064754 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017EAC 0x02017EAC thumb
 *   d_021F83E4 0x021F83E4 data a4
 *   MUSICAL_DIST_SAVE_Create 0x0200C52C thumb
 *   MUSICAL_DIST_SAVE_GetPayload 0x0200C6D8 thumb
 *   MUSICAL_DIST_SAVE_GetPayloadSize 0x0200C6DC thumb
 *   MUSICAL_DIST_SAVE_Delete 0x0200C5A4 thumb
 *   ARC_TOOL_CreateHandleFromMemory 0x0204913C arm
 *   ARC_UTIL_LoadHandleMemberWithSize 0x0204A39C arm
 *   ARC_TOOL_GetHandleMemberSize 0x020493D4 arm
 *   ARC_TOOL_ReadHandleMember 0x0204932C arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb  arm9
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   TIME_ICON_Delete  0x0202F038  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb  arm9
 */
#include "../../matched/include/Obj00669.h"
#include "../../matched/include/Obj04456.h"
#include "../../matched/include/Obj00226.h"
#include "../../matched/include/Obj00721.h"
#include "../../matched/include/Obj01147.h"
#include "../../matched/include/Obj01924.h"
#include "../../matched/include/Obj01395.h"
#include "../../matched/include/Obj02167.h"
#include "../../matched/include/Obj06406.h"
#include "../../matched/include/Obj22515.h"
#include "../../matched/include/Obj22518.h"
#include "../../matched/include/Obj22519.h"
#include "../../matched/include/Obj22520.h"
#include "../../matched/include/Obj22521.h"
#include "../../matched/include/Obj22522.h"
#include "../../matched/include/Obj06407.h"
#include "../../matched/include/Obj05310.h"
#include "../../matched/include/Obj13826.h"
#include "../../matched/include/Obj02168.h"
#include "../../matched/include/Obj10298.h"
#include "../../matched/include/Obj05311.h"
#include "../../matched/include/Obj05312.h"
#include "../../matched/include/Obj13827.h"
#include "../../matched/include/Obj22523.h"
#include "../../matched/include/Obj01396.h"
#include "../../matched/include/Obj10300.h"
#include "../../matched/include/Obj22528.h"
#include "../../matched/include/Obj22530.h"
#include "../../matched/include/Obj13828.h"
#include "../../matched/include/Obj22532.h"
#include "../../matched/include/Obj22533.h"
#include "../../matched/include/Obj10301.h"
#include "../../matched/include/Obj10302.h"
#include "../../matched/include/Obj22534.h"
#include "../../matched/include/Obj22535.h"
#include "../../matched/include/Obj08022.h"
#include "../../matched/include/Obj22536.h"
#include "../../matched/include/Obj22537.h"
#include "../../matched/include/Obj22538.h"
#include "../../matched/include/Obj10304.h"
#include "../../matched/include/Obj22540.h"
#include "../../matched/include/Obj01717.h"
#include "../../matched/include/Obj13831.h"
#include "../../matched/include/Obj22542.h"
#include "../../matched/include/Obj04459.h"
#include "../../matched/include/Obj05315.h"
#include "../../matched/include/Obj13832.h"
#include "../../matched/include/Obj10305.h"
#include "../../matched/include/Obj10306.h"
#include "../../matched/include/Obj04460.h"
#include "../../matched/include/Obj13833.h"
#include "../../matched/include/Obj22543.h"
#include "../../matched/include/Obj22544.h"
#include "../../matched/include/Obj10307.h"
#include "../../matched/include/Obj10309.h"
#include "../../matched/include/Obj22545.h"
#include "../../matched/include/Obj22546.h"
#include "../../matched/include/Obj00722.h"
#include "../../matched/include/Obj22547.h"
#include "../../matched/include/Obj22548.h"
#include "../../matched/include/Obj22549.h"
#include "../../matched/include/Obj13834.h"
#include "../../matched/include/Obj22550.h"
#include "../../matched/include/Obj22551.h"
#include "../../matched/include/Obj22552.h"
#include "../../matched/include/Obj03759.h"
#include "../../matched/include/Obj03247.h"
#include "../../matched/include/Obj03760.h"

#define REG(a) (*(volatile u32 *)(a))
#define SLOT (*(char ***)(a+4))[i]
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
struct Strbuf;
struct R;
struct Bank;
struct Obj;
struct TaskMenuState;
struct Actor;
struct PrintSys;
struct Rec3;
struct TaskMenu;
struct Tcbl;
struct BgTemplate;
struct S02031140;
struct TaskMenuTmpl;
struct Manager0204F684;
struct Tagged;
struct Desc;
struct Board;
struct Vec3;
struct Obj0204F1A0;
struct S;
struct AnimBank;
struct AnimSequence;
struct Obj0206469C;
struct Node;
struct Out;
struct Res;
struct ArcFile;
struct Blk2C;
struct MusicalDist;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 words[4]; } Quad;

typedef signed short s16_021F40F4;

typedef struct { u32 pad:9; u32 a:7; u32 b:5; u32 c:6; u32 tail:5; } Input_021F40D0;

typedef short s16_021F4280;

typedef signed char s8;

typedef int s32_021F40D0;

typedef struct { u16 v; u16 pad; } H16;

typedef struct { u8 b[8]; } Box;

typedef struct { u16 x,y,z; u8 a,b; } Desc;

typedef signed int     s32_021F44F8;

typedef struct Item { void *data; u16 value; u16 pad; int zero; } Item;

typedef struct Menu { u32 heap; u8 count; u8 pad[3]; Item *items; int zero; u8 a,b,c,d; } Menu;

typedef struct Record_021F48C0 { u16 active:1; u16 enabled:1; u16 rest:14; u8 data[34]; } Record_021F48C0;

typedef struct Object_021F48C0 { u16 heap; u16 pad; u32 owner; Record_021F48C0 *records; void *resource; u16 count; u16 slots[16]; } Object_021F48C0;

typedef struct Record_021F4948 { u16 active:1; u16 rest:15; u8 data[34]; } Record_021F4948;

typedef short s16;

typedef union {
    u16 value;
    struct { u16 active:1, dirty:1, rotate:1, rest:13; } bits;
} Flags_021F40D0;

typedef struct { Flags_021F40D0 flags; u16 angle; u32 id,index,type; int x,y,z; s16 a,b; u8 *data; } Entry_021F40D0;

typedef struct { u32 pad; u8 *board; Entry_021F40D0 *entries; u8 *table; u16 count; } Object_021F4990;

typedef struct { int x,y; } Offset_021F40D0;

typedef struct { u8 x,y; s16 b,a; } Scale;

struct Trip { u32 a,b,c; };

typedef int s32;

typedef struct { u16 used:1; u16 rest:15; } Bits_021F40D0;

typedef struct { u16 flags,zero; u32 id,index,type; int x,y,z; s16 a,b; u8 *data; } Entry_021F4B10;

typedef struct { u32 pad; void *board; Entry_021F4B10 *entries; u8 *table; } Object_021F40D0;

typedef struct { u8 x,y; } Pair;

typedef short s16_021F4C94;

typedef signed int     s32_021F4C94;

typedef struct { u16 flags, zero; u32 id, index, type; int x,y,z; s16_021F4C94 a,b; void *data; } Entry_021F4C94;

typedef struct { u32 pad; void *board; Entry_021F4C94 *entries; } Object_021F4C94;

typedef short s16_021F4D40;

typedef struct { u16 low:4; u16 bit4:1; u16 rest:11; } Bits_021F4D40;

typedef struct { u16 low:3; u16 bit3:1; u16 bit4:1; u16 rest:11; } Bits_021F4D74;

typedef struct { u16 low:3; u16 bit3:1; u16 rest:12; } Bits_021F4DE0;

typedef signed int     s32_021F4DE0;

typedef signed short s16_021F4E2C;

typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags_021F4E2C;

typedef short s16_021F4E6C;

typedef short s16_021F4E8C;

typedef struct { u16 flags,zero; u32 id,index,type; int x,y,z; s16_021F4E8C a,b; u8 *data; } Entry_021F4E8C;

typedef short s16_021F4EA4;

typedef short s16_021F4EB4;

typedef short s16_021F4EC4;

typedef short s16_021F4ED4;

typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags_021F4EE8;

typedef struct { u16 lo : 2; u16 flag : 1; u16 hi : 13; } Flags_021F4EFC;

typedef struct { int x, y; } Offset_021F4C94;

typedef short s16_021F4F10;

typedef int s32_021F4F10;

typedef short s16_021F4F54;

typedef int s32_021F4F54;

typedef struct { int f0, f4, active; } Fields;

typedef struct { u32 value; u8 pad[52]; } Track;

typedef struct {
    u32 active, enabled;
    u8 *object;
    char *primary, *secondary;
    Track tracks[9];
    u32 f524, f528, f532, f536, f540, f544, f548, f552;
} Slot;

typedef struct { u32 heap; char *main; Slot slots[8]; } Scene;

typedef struct { u32 stats[9]; int scale[3]; } Buffers;

typedef short s16_021F53D8;

typedef short s16_021F5450;

typedef short s16_021F545C;

typedef struct { int x,y,z; } Vec_021F56BC;

typedef struct { Vec_021F56BC a,b,c,d; u16 e,f; } Input_021F53CC;

typedef struct { int pad[5]; u32 tracks[126]; /* 9 tracks of 0x38 bytes */ Vec_021F56BC t[2]; int flag[2]; } Big;

typedef struct { u32 low:1; u32 paused:1; u32 rest:30; } Flags_021F53CC;

typedef signed short   s16_021F56BC;

typedef long long      s64;

typedef struct {
    u16 id;
    u16 rot;
    int sx;
    int sy;
    s16_021F56BC dx;
    s16_021F56BC dz;
} Pose;

typedef struct {
    u32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C;
    u8 parts[8];
} Ent;

typedef struct {
    u32 f0;
    u32 f4;
    int x;
    int z;
    u32 f10;
} Part;

typedef struct {
    u16 f0;
    s16_021F56BC x;
    s16_021F56BC z;
    u16 h;
} TabEnt;

typedef struct {
    u16 count;
    u16 pad;
    TabEnt *ents;
} Tab;

typedef struct {
    int w;
    int z;
    Input_021F53CC in;
} CB;

typedef struct { int m[12]; } Mtx43;

typedef struct { int m[16]; } Mtx44;

typedef struct { int m[9]; } Mtx33;

typedef struct { u32 b0 : 1; u32 rest : 31; } Bits_021F53CC;

typedef struct { u32 b0 : 1; u32 b1 : 1; u32 b2 : 1; u32 rest : 29; } Bits3;

typedef struct { u16 id; u16 pad; s16_021F56BC dx; s16_021F56BC dz; } PoseSrc;

typedef struct { u32 addr; u32 f04; u32 f08; u32 s; u32 t; u32 fmt; u32 f18; u32 pltt0; } TexInfo;

typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_PLTT4 = 2 } GXTexFmt;

typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1 } GXTexGen;

typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;

typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;

typedef enum { GX_TEXREPEAT_NONE = 0, GX_TEXREPEAT_ST = 3 } GXTexRepeat;

typedef enum { GX_TEXFLIP_NONE = 0, GX_TEXFLIP_ST = 3 } GXTexFlip;

typedef enum { GX_TEXPLTTCOLOR0_USE = 0, GX_TEXPLTTCOLOR0_TRNS = 1 } GXTexPlttColor0;

struct E2 { s16 p0; s16 f2; s16 f4; s16 p6; };

struct E1 { int p0; struct E2 *arr; };

struct H { int p0; struct E1 *tbl; };

struct S {
    int pad0;
    int f4;
    int f8;
    s16 fC;
    s16 fE;
};

typedef struct { u32 a:1,b:1,c:1,rest:29; } Flags;

typedef struct { int x,y,z; } Vec;

typedef struct { char pad[200]; Vec a,b,c; u32 b0:1,b1:1,b2:1,rest:29; char pad2[12]; u16 h,pad3; Vec d,e; } Object;

typedef unsigned long long u64;

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintColor(void *,s16_021F40F4,s16_021F40F4,void *,void *,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_020409B4(u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void func_020403F4(u32 i);
extern u32 func_020307B0(void *p);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern u32 WIPE_SYS_EndCheck(void);
extern void APP_TASKMENU_UpdateMenu(void *);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void *func_0200A640(void *);
extern void MI_CpuCopy8(const void *,void *,u32);
extern void func_021FCDEC(int,int);
extern int func_021FCE00(char *p, int id);
extern u32 func_0200FB24(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern u32 PRINTSYS_PrintStreamGetState(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern u8 *TIME_ICON_CreateNode(u32,void *,u8,u8,u16);
extern void TCBL_Main(struct Tcbl *p);
extern void func_02041EE4(u32,u32,u32);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern s32_021F44F8 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_02027614(void);
extern s32_021F44F8 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern s32_021F44F8 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_0201DD68(u32);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void TIME_ICON_Delete(u8 *);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *p);
extern signed char func_02012FFC(void);
extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void func_0201F73C(void *,int,int,int);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void NNS_GfdResetVramTransferTaskQueue(void);
extern void BILLBOARD_SetElemPos(u8 *,int,struct Trip *);
extern void BILLBOARD_SetElemScale(struct Manager0204F684 *,int,const s16 *,const s16 *);
extern void BILLBOARD_SetElemRotZ(u8 *,int,u16 *);
extern u32 ARC_TOOL_GetArchiveFileCount(u32 a);
extern void func_0204EDD0(int,u16 *,u16 *);
extern void *G3D_SYSTEM_CreateResourceArc(u32,u32);
extern void func_02046EFC(struct Tagged *p);
extern u32 BILLBOARD_AddImage(struct Desc *desc, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern s32_021F4C94 BILLBOARD_AddElem(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void BILLBOARD_SetElemVisible(void *,u32,u32 *);
extern void BILLBOARD_FreeElem(void *,u32);
extern void BILLBOARD_ReleaseImageVramIfUsed(struct Obj0204F1A0 *a0, u32 a1);
extern void BILLBOARD_SetElemId(void *,u32,u16 *);
extern void func_0204F2CC(int p0, int p1, int p2);
extern void func_0204F32C(int p0, int p1, int p2);
extern s32_021F4DE0 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32_021F4DE0 size);
extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern void *sub_02030734(u32, u32, int, const char *, u16);
extern void *POKE_TOOL_GetBoxParam(void *p);
extern u32 func_02019D30(u32, u32);
extern int func_02019D58(u16 a, int b);
extern int POKEGRA_GetCbrArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetPalArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetCelArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetAnmArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetMCelArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetMAnmArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetNcecArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern void NNS_G2dTickMCAnimation(char *, int);
extern void func_0207D7C4(const Vec_021F56BC *a, const Vec_021F56BC *b, const Vec_021F56BC *c, int d, void *e);
extern void func_0207B67C(const Mtx43 *a, Mtx43 *m);
extern void func_02082B60(Mtx43 *a, Mtx33 *b);
extern void func_0207ADE8(Mtx33 *a, Mtx44 *b);
extern void func_0207B5C0(const Mtx43 *src, Mtx44 *dst);
extern void func_0207BE14(const Mtx44 *a, const Mtx44 *b, Mtx44 *ab);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_0207D8FC(Mtx44 *m);
extern void func_0207D888(int s, int c);
extern void func_0207AF38(Mtx33 *m, int s, int c);
extern void func_0207B51C(void *v, Mtx33 *m, void *out);
extern void func_0207CA00(void *a, void *b, void *c);
extern void func_0207D760(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern struct AnimSequence *func_020627D8(struct AnimBank *bank, u32 idx);
extern void NNS_G2dSetAnimSequenceToMCAnimation(void *,void *);
extern void func_02063790(u32 *);
extern void func_020637D4(u32 *);
extern void *ARC_UTIL_LoadCellBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *ARC_UTIL_LoadMultiCellBankFromArchive(u32,u32,u32,u32,u16);
extern void *ARC_UTIL_LoadAnimBankFromArchive(u32,u32,u32,u32,u16);
extern void *ARC_UTIL_LoadMultiAnimBankFromArchive(u32,u32,u32,u32,u16);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void MCSS_TOOL_DrawSpindaSpots(u8 *,u32);
extern void *func_020056A0(u32,u32,u32);
extern void func_02030EAC(struct Node *n);
extern void func_02063A54(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063E54(void *,void *,int,void *);
extern int NNS_G2dGetMCWorkAreaSize(u32,u32);
extern void NNS_G2dInitMCAnimation(char *,char *,void *,int,void *,int);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_02017EAC(void *);
extern struct MusicalDist *MUSICAL_DIST_SAVE_Create(void *sys, u32 heap);
extern u32 MUSICAL_DIST_SAVE_GetPayload(struct Blk2C *p);
extern u32 MUSICAL_DIST_SAVE_GetPayloadSize(struct Blk2C *p);
extern void *ARC_TOOL_CreateHandleFromMemory(void *a0, u32 a1, u32 heap);
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);
extern void MUSICAL_DIST_SAVE_Delete(struct MusicalDist *p);
u32 func_021F40D0(void *p,u32 i,u16 c);
void func_021F40F4(u8 *p);
void func_021F4280(u8 *a0);
void *func_021F4284(u32 a, u32 b, u32 c, u32 d, H16 heap);
void func_021F4300(u8 *p);
void func_021F4350(u8 *p);
int func_021F44E8(u32 *p);
void func_021F44F8(u8 *p);
void func_021F4684(const void *a,u32 b,u32 c);
void func_021F46A8(u8 *p);
void func_021F4748(u8 *p);
void func_021F4794(u8 *p,u32 index);
void func_021F4804(u8 *p,u32 index);
void func_021F485C(u8 *p);
Object_021F48C0 *func_021F48C0(u32 owner,int count,u16 heap);
void func_021F4948(u8 *p);
void func_021F4990(Object_021F4990 *p);
void func_021F4AA4(void *a0);
u16 func_021F4AA8(int i);
void func_021F4AC8(u8 *p,u8 *a,u8 *b);
int func_021F4AF0(u8 *p, int index);
int func_021F4AFC(u8 *p,int index,int mode);
int func_021F4B10(u8 *p,int index,int mode);
int func_021F4B24(u8 *p);
int func_021F4B30(u8 *p);
void *func_021F4B3C(int type);
void func_021F4B4C(struct Tagged *a0);
u16 func_021F4B54(u32 p);
Entry_021F4B10 *func_021F4B88(Object_021F40D0 *p,int type,u32 id,int *v);
Entry_021F4B10 *func_021F4C1C(Object_021F40D0 *p, int type, u32 id, int *v);
Entry_021F4C94 *func_021F4C94(Object_021F4C94 *p, u16 index, int *v, s16_021F4C94 a, s16_021F4C94 b);
void func_021F4D40(u8 *p,u8 *e);
void func_021F4D74(u8 *p, u8 *e, int type, u16 id);
void func_021F4DE0(char *p, char *e, void *a2);
void func_021F4E2C(void *unused, u8 *s, u8 *d);
void func_021F4E6C(u8 *p,u8 *e,u32 value);
void func_021F4E8C(u32 unused,Entry_021F4E8C *p,const int *q);
void func_021F4EA4(u32 unused,u32 p,u32 q);
void func_021F4EB4(u32 unused,u32 p,s16_021F4EB4 a,s16_021F4EB4 b);
void func_021F4EC4(u32 unused,u32 p,s16_021F4EC4 *a,s16_021F4EC4 *b);
void func_021F4ED4(u32 unused,u32 p,u16 v);
void func_021F4EE0(int unused, u16 *p, u16 *out);
void func_021F4EE8(int unused,Flags_021F4EE8 *s,int flag);
int func_021F4EFC(int unused, Flags_021F4EFC *p);
void func_021F4F04(u8 *p, Offset_021F4C94 *out);
u32 func_021F4F10(u8 *p);
u32 *func_021F4F14(int heap);
void func_021F4F40(void **p);
u8 *func_021F4F54(u8 *p, int i);
void func_021F4F60(u8 *p, Offset_021F4C94 *out);
int func_021F4F70(int *p);
int func_021F4F74(u16 *p, int mode);
int func_021F4FF4(u16 *p, int mode);
int func_021F5064(u8 *p, int mode);
int func_021F50D0(const unsigned char *p);
int func_021F50E0(const unsigned char *p);
int func_021F50F4(unsigned index);
unsigned char func_021F5140(void *p, int i);
unsigned char func_021F514C(void *p, int i);
unsigned char func_021F5158(void *p, int i);
void *func_021F5164(u32 heap);
void func_021F51B0(int a);
void func_021F51E8(u8 *p);
void func_021F51F4(void **p);
u8 *func_021F5204(Scene *p,const u8 *b,int c);
void func_021F5330(int a, int b);
void func_021F5350(int *p, int *q);
void func_021F535C(int *p, int *q);
void func_021F5368(int *p, unsigned short v);
void func_021F5374(int *p,int b);
int func_021F5388(u8 **p);
void func_021F539C(void **p);
void func_021F53B4(int a);
void func_021F53CC(int a, u32 n);
void func_021F53D8(int a);
void func_021F5414(int a,int b);
void func_021F5424(int a0, int a1);
void func_021F5438(void **p,int b);
void func_021F5444(u8 *p, int a);
u8 *func_021F5450(u8 *p, int i);
u8 *func_021F545C(u8 *p);
char *func_021F5464(char *p);
void func_021F546C(unsigned mode, Input_021F53CC *in, Big *p);
void func_021F5518(u8 *p, u32 *out, u32 k);
void *func_021F55F8(int count, u32 heap);
void func_021F5644(char *p);
void func_021F5678(char *p);
void func_021F56BC(int *p, void (*arg)(unsigned, Input_021F53CC *, Big *));
void func_021F5EDC(char *p, int a1, int a2, int a3, int a4, int a5, int a6, struct S *s, u16 *pa, int a9, int flag, int *pz, u8 mode);
char *func_021F611C(char *a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g);
void func_021F61D8(char *a, char *p);
void func_021F621C(void *p);
void func_021F622C(char *p,int b);
void func_021F6230(u8 *p, int a);
void func_021F6234(char *p, int *q);
void func_021F624C(char *p, int *q);
void func_021F6264(char *p, unsigned short v);
void func_021F626C(u8 *p);
void func_021F6280(u8 *p);
void func_021F6290(u8 *p);
void func_021F62A0(char *p);
void func_021F62B0(char *p,u32 n);
u32 func_021F62D0(u8 *p);
void func_021F62DC(char *p);
void func_021F62EC(char *p);
void func_021F62FC(Object *a,Object *b);
void func_021F63B8(u8 *a,int index,u32 *res,u32 mode);
void func_021F6540(void *a, void **p);
void func_021F659C(char *p, int kind);
void func_021F65EC(void);
void func_021F660C(const int *p, const int *m, u32 *out, u32 *w);
int func_021F6744(void *p);
char *func_021F675C(void *a,u16 heap);
char *func_021F67E0(u16 a,u8 b,u8 c,u8 d,u32 e,u16 heap);
void *func_021F685C(u32 heap);
void func_021F6888(char *p);
void func_021F68BC(u8 *p, u32 unused, void *sys, u8 kind, u16 heap);
extern const Quad d_021F8264;
extern char d_021F8394[];
extern const Box d_021F8290;
extern const u32 d_021F8298[];
extern const u32 d_021F82B8[];
extern const u32 d_021F82D8[];
extern char d_021F83A4[];
extern s16 FX_SinCosTable_[];
extern u32 d_021F8300;
extern char d_021F83B4[];
extern const char d_021F83C4[];
extern const char d_021F83D4[];
extern u32 d_02FFFC3C;
extern const Vec_021F56BC d_02148D8C;
extern const Vec_021F56BC d_02148D98;
extern const Vec_021F56BC d_02148DA4;
extern const Vec_021F56BC d_021F8310;
extern const Vec_021F56BC d_021F831C;
extern const Vec_021F56BC d_021F8304;
extern const Mtx43 d_02148B98;
extern const Mtx44 d_02148B54;
extern const char d_021F83E4[];








u32 func_021F40D0(void *p,u32 i,u16 c) { Quad q=d_021F8264; return q.words[i]; }








void func_021F40F4(u8 *p)
{
    void *buf;
    void *t;
    void *f;
    void *b;
    ((struct Obj00669 *)p)->f54=(void *)BMP_WIN_Create(1,24,22,8,2,10,1);
    ((struct Obj00669 *)p)->f58=(void *)BMP_WIN_Create(1,1,1,30,2,10,1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00669 *)p)->f54),0);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00669 *)p)->f58),0);
    ((struct Obj00669 *)p)->f5C=GF_FONT_Create(23,3,0,0,((struct Obj00669 *)p)->f0);
    ((struct Obj00669 *)p)->f60=GF_FONT_Create(23,0,0,0,((struct Obj00669 *)p)->f0);
    func_02049B40(23,5,0,320,32,((struct Obj00669 *)p)->f0);
    buf=STRBUF_Create(128,((struct Obj00669 *)p)->f0);
    t=func_0201EC64(((struct Obj00669 *)p)->f0);
    f=func_02045B38(0,2,78,((struct Obj00669 *)p)->f0);
    b=func_02045EC0(f,0);
    func_0201EFA4(t,0,(*(Input_021F40D0 * *)&((struct Obj00669 *)p)->f4)->a,2,2,1);
    func_0201EFA4(t,1,(*(Input_021F40D0 * *)&((struct Obj00669 *)p)->f4)->b,2,2,1);
    func_0201EFA4(t,2,(*(Input_021F40D0 * *)&((struct Obj00669 *)p)->f4)->c,2,2,1);
    func_0201F250(t,buf,b);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct Obj00669 *)p)->f54),0,0,buf,((struct Obj00669 *)p)->f5C,3424);
    STRBUF_Delete(buf);
    STRBUF_Delete(b);
    func_0201ED04(t);
    MSGDATA_Delete(f);
    buf=STRBUF_Create(37,((struct Obj00669 *)p)->f0);
    STRBUF_SetString(buf,(const u16 *)(*(u8 * *)&((struct Obj00669 *)p)->f4+356));
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct Obj00669 *)p)->f58),0,0,buf,((struct Obj00669 *)p)->f60,15424);
    STRBUF_Delete(buf);
    BMP_WIN_TransferChars(((struct Obj00669 *)p)->f54);
    BMP_WIN_MakeScreen(((struct Obj00669 *)p)->f54);
    BMP_WIN_TransferChars(((struct Obj00669 *)p)->f58);
    BMP_WIN_MakeScreen(((struct Obj00669 *)p)->f58);
    func_020409B4(1);
}









void func_021F4280(u8 *a0) { }








void *func_021F4284(u32 a, u32 b, u32 c, u32 d, H16 heap)
{
    u8 *p = func_02030734(*(u16 *)&heap, 0x5c, 1, d_021F8394, 0x8d);
    *(u16 *)p = *(u16 *)&heap;
    *(u32 *)(p + 0xc) = c;
    *(u32 *)(p + 0x10) = a;
    *(u32 *)(p + 0x14) = b;
    *(u32 *)(p + 0x44) = d;
    *(u32 *)(p + 0x2c) = 0;
    *(u8 *)(p + 8) = 0;
    if (c == 1) *(u32 *)(p + 4) = 0; else *(u32 *)(p + 4) = 1;
    func_021F44F8(p);
    func_021F46A8(p);
    *(u32 *)(p + 0x40) = (u32)APP_TASKMENU_RES_Create(4, 12, *(u32 *)(p + 0x20), *(u32 *)(p + 0x38), *(u16 *)p);
    GFL_NET_RestartWithDefaultTimeout(0, *(u16 *)&heap);
    BG_SYS_SetSubPlaneVisible(16, 1);
    return p;
}








/*
 * extent: trailing two-byte padding at 0x021F434E.
 */
void func_021F4300(u8 *p)
{
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(((struct Obj04456 *)p)->f40));
    if (((struct Obj04456 *)p)->fC==0) {
        CLACT_ReleasePalette(((struct Obj04456 *)p)->f4C);
        CLACT_ReleaseCharacter(((struct Obj04456 *)p)->f50);
        CLACT_ReleaseCellAnim(((struct Obj04456 *)p)->f54);
        CLACT_DeleteActor((struct Obj *)(((struct Obj04456 *)p)->f58));
    }
    CLACT_DeleteUnit((struct Bank *)(((struct Obj04456 *)p)->f48));
    func_021F4748(p);
    func_020403F4(4);
    func_020403F4(6);
    func_020403F4(7);
    func_020307B0(p);
}








/*
 * volatile: byte +8 is re-read after the increment at 0x021F44BA.
 * ABI: 0200A640 leaves its incoming pointer in r0; the caller copies that return.
 */
void func_021F4350(u8 *p)
{
    u8 v;
    switch (((struct Obj00226 *)p)->f4) {
    case 0:
        ((struct Obj00226 *)p)->f4=1;
        GFL_USE_PlaySeDefaultVolume(1583);
    case 1:
        if(WIPE_SYS_EndCheck()==1) {
            if(((struct Obj00226 *)p)->fC==1) {
                func_021F4794(p,3);
                ((struct Obj00226 *)p)->f4=2;
            } else ((struct Obj00226 *)p)->f4=5;
        }
        break;
    case 2:
        if(!((struct Obj00226 *)p)->f24) {
            func_021F485C(p);
            ((struct Obj00226 *)p)->f4=3;
        }
        break;
    case 3:
        APP_TASKMENU_UpdateMenu(((struct Obj00226 *)p)->f3C);
        if(APP_TASKMENU_IsFinish(((struct Obj00226 *)p)->f3C)==1) {
            v=APP_TASKMENU_GetCursorPos(*(u8 * *)&((struct Obj00226 *)p)->f3C);
            APP_TASKMENU_CloseMenu(((struct Obj00226 *)p)->f3C);
            if(v==0) MI_CpuCopy8(((struct Obj00226 *)p)->f10,func_0200A640(((struct Obj00226 *)p)->f14),432);
            if(*(int *)&((struct Obj00226 *)p)->f44) {
                ((struct Obj00226 *)p)->f4=4;
                func_021FCDEC(*(int *)&((struct Obj00226 *)p)->f44,71);
                func_021F4804(p,6);
            } else ((struct Obj00226 *)p)->f4=7;
        } else if(func_0200FB24()!=0) {
            APP_TASKMENU_CloseMenu(((struct Obj00226 *)p)->f3C);
            ((struct Obj00226 *)p)->f4=7;
        }
        break;
    case 4:
        if(func_021FCE00(((struct Obj00226 *)p)->f44,71)==1) ((struct Obj00226 *)p)->f4=7;
        else if(func_0200FB24()!=0) ((struct Obj00226 *)p)->f4=7;
        break;
    case 5:
        if((KEY_GetTrg()&2)||!TOUCHPANEL_HitTrg(&d_021F8290)) {
            GFL_USE_PlaySeDefaultVolume(1361);
            ((struct Obj00226 *)p)->f4=6;
            CLACT_SetActorAnimSeq(((struct Obj00226 *)p)->f58,9);
            CLACT_SetActorAutoAnim(((struct Obj00226 *)p)->f58,1);
        }
        break;
    case 6:
        if(!CLACT_IsActorAnimActive(((struct Obj00226 *)p)->f58)) ((struct Obj00226 *)p)->f4=7;
        break;
    case 7: break;
    }
    if(((struct Obj00226 *)p)->f24&&PRINTSYS_PrintStreamGetState(((struct Obj00226 *)p)->f24)==2) {
        PRINTSYS_PrintStreamDelete(((struct Obj00226 *)p)->f24);
        ((struct Obj00226 *)p)->f24=0;
    }
    PRINTSYS_QUE_Main(((struct Obj00226 *)p)->f38);
    if(((struct Obj00226 *)p)->f30==1&&PRINTSYS_QUE_IsFinished(((struct Obj00226 *)p)->f38)==1) {
        ((struct Obj00226 *)p)->f30=0;
        *(u8 * *)&((struct Obj00226 *)p)->f34=TIME_ICON_CreateNode(*(u32 *)&((struct Obj00226 *)p)->f18,((struct Obj00226 *)p)->f1C,15,16,((struct Obj00226 *)p)->f0);
        BMP_WIN_TransferChars(((struct Obj00226 *)p)->f1C);
    }
    TCBL_Main(((struct Obj00226 *)p)->f18);
    (*(volatile u8 *)&((struct Obj00226 *)p)->f8)++;
    if(*(volatile u8 *)&((struct Obj00226 *)p)->f8>1) {
        *(volatile u8 *)&((struct Obj00226 *)p)->f8=0;
        func_02041EE4(7,1,1);
        func_02041EE4(7,5,1);
    }
}









int func_021F44E8(u32 *p) { if(p[1]==7) return 1; return 0; }








/*
 * ABI: 0204B294 returns an Obj pointer, which the original stores at +88.
 */
void func_021F44F8(u8 *p)
{
    Desc d;
    void *t;
    u32 v;
    u32 w;
    func_021F4684(d_021F8298,4,0);
    func_021F4684(d_021F82B8,6,0);
    func_021F4684(d_021F82D8,7,0);
    ((struct Obj00721 *)p)->f48=CLACT_CreateUnit(8,0,((struct Obj00721 *)p)->f0);
    CLACT_SetUnitDefaultRenderer(((struct Obj00721 *)p)->f48);
    BG_SYS_SetSubPlaneVisible(16,1);
    t=func_020490F4((unsigned int)46,((struct Obj00721 *)p)->f0);
    func_02049B68((void *)((u32)t),4,4,0,0,((struct Obj00721 *)p)->f0);
    func_02049658((void *)((u32)t),7,7,0,0,0,((struct Obj00721 *)p)->f0);
    func_020498F4((void *)((u32)t),12,7,0,0,0,((struct Obj00721 *)p)->f0);
    ARC_TOOL_DeleteHandle(t);
    if (((struct Obj00721 *)p)->fC==0) {
        t=func_020490F4((unsigned int)func_020275E4(),((struct Obj00721 *)p)->f0);
        func_02049B68((void *)((u32)t),func_02027624(),4,288,32,((struct Obj00721 *)p)->f0);
        func_02049658((void *)((u32)t),func_02027628(),6,0,0,0,((struct Obj00721 *)p)->f0);
        func_020498F4((void *)((u32)t),func_0202762C(),6,0,0,0,((struct Obj00721 *)p)->f0);
        func_020413B0(6,0,21,32,3,9);
        func_020409B4(6);
        ((struct Obj00721 *)p)->f4C=CLACT_RegisterPaletteEx((void *)((u32)t),func_02027614(),1,0,0,3,((struct Obj00721 *)p)->f0);
        ((struct Obj00721 *)p)->f50=CLACT_RegisterCharacter((void *)((u32)t),func_02027618(),0,1,((struct Obj00721 *)p)->f0);
        v=func_0202761C(0);
        w=func_02027620(0);
        ((struct Obj00721 *)p)->f54=CLACT_RegisterCellAnim((void *)((u32)t),v,w,((struct Obj00721 *)p)->f0);
        ARC_TOOL_DeleteHandle(t);
        d.x=232;
        d.y=168;
        d.z=1;
        d.b=0;
        d.a=0;
        ((struct Obj00721 *)p)->f58=CLACT_CreateActor((void *)*(u32 *)&((struct Obj00721 *)p)->f48,((struct Obj00721 *)p)->f50,((struct Obj00721 *)p)->f4C,((struct Obj00721 *)p)->f54,&d,1,((struct Obj00721 *)p)->f0);
    }
}








void func_021F4684(const void *a,u32 b,u32 c) { func_0203FCA0(b,a,c); func_02040588(b,1); func_020414AC(b); func_020409B4(b); }








void func_021F46A8(u8 *p)
{
    int zero;
    ((struct Obj01147 *)p)->f1C=BMP_WIN_Create(4,1,1,30,4,10,1);
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01147 *)p)->f1C);
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj01147 *)p)->f1C));
    func_020409B4(4);
    zero=0;
    ((struct Obj01147 *)p)->f20=(u32)GF_FONT_Create(23,0,0,0,((struct Obj01147 *)p)->f0);
    ((struct Obj01147 *)p)->f28=(u32)func_02045B38(0,2,78,((struct Obj01147 *)p)->f0);
    func_0201F5BC(4,1,11,0,((struct Obj01147 *)p)->f0);
    func_0201DD68(func_02049B40(23,5,4,320,32,((struct Obj01147 *)p)->f0));
    ((struct Obj01147 *)p)->f18=(u32)TCBL_Create(((struct Obj01147 *)p)->f0,((struct Obj01147 *)p)->f0,3,256);
    ((struct Obj01147 *)p)->f24=zero;
    ((struct Obj01147 *)p)->f2C=zero;
    ((struct Obj01147 *)p)->f30=zero;
    ((struct Obj01147 *)p)->f34=zero;
    ((struct Obj01147 *)p)->f38=PRINTSYS_QUE_Create((void *)(((struct Obj01147 *)p)->f0));
}








void func_021F4748(u8 *p)
{
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj01924 *)p)->f38));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj01924 *)p)->f38));
    if (*(u8 * *)&((struct Obj01924 *)p)->f34) {
        TIME_ICON_Delete(*(u8 * *)&((struct Obj01924 *)p)->f34);
        *(u32 *)&((struct Obj01924 *)p)->f34=0;
    }
    if (((struct Obj01924 *)p)->f24) PRINTSYS_PrintStreamDelete(((struct Obj01924 *)p)->f24);
    if (((struct Obj01924 *)p)->f2C) STRBUF_Delete(((struct Obj01924 *)p)->f2C);
    MSGDATA_Delete(((struct Obj01924 *)p)->f28);
    BMP_WIN_Delete(((struct Obj01924 *)p)->f1C);
    GF_FONT_Delete(((struct Obj01924 *)p)->f20);
    TCBL_Destroy(((struct Obj01924 *)p)->f18);
}








void func_021F4794(u8 *p,u32 index)
{
    u32 t;
    if (((struct Obj01395 *)p)->f24) {
        PRINTSYS_PrintStreamDelete(((struct Obj01395 *)p)->f24);
        *(u32 *)&((struct Obj01395 *)p)->f24=0;
    }
    if (((struct Obj01395 *)p)->f2C) {
        STRBUF_Delete(((struct Obj01395 *)p)->f2C);
        *(u32 *)&((struct Obj01395 *)p)->f2C=0;
    }
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj01395 *)p)->f1C)),15);
    ((struct Obj01395 *)p)->f2C=func_02045EC0((struct MsgBank *)(((struct Obj01395 *)p)->f28),index);
    t=func_02012FFC();
    *(u32 *)&((struct Obj01395 *)p)->f24=PRINTSYS_PrintStream(*(u32 *)&((struct Obj01395 *)p)->f1C,0,0,*(u32 *)&((struct Obj01395 *)p)->f2C,((struct Obj01395 *)p)->f20,t,((struct Obj01395 *)p)->f18,2,((struct Obj01395 *)p)->f0,0);
    func_0201F73C(((struct Obj01395 *)p)->f1C,1,1,11);
}








void func_021F4804(u8 *p,u32 index)
{
    u32 win;
    if (((struct Obj02167 *)p)->f2C) {
        STRBUF_Delete(((struct Obj02167 *)p)->f2C);
        *(u32 *)&((struct Obj02167 *)p)->f2C=0;
    }
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj02167 *)p)->f1C)),15);
    ((struct Obj02167 *)p)->f2C=func_02045EC0((struct MsgBank *)(((struct Obj02167 *)p)->f28),index);
    win=(u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj02167 *)p)->f1C);
    PRINTSYS_PrintQue((struct PrintSys *)(((struct Obj02167 *)p)->f38),win,0,0,((struct Obj02167 *)p)->f2C,((struct Obj02167 *)p)->f20);
    ((struct Obj02167 *)p)->f30=1;
    func_0201F73C(((struct Obj02167 *)p)->f1C,1,1,11);
}








void func_021F485C(u8 *p)
{
    Item items[2];
    Menu menu;
    items[0].data=func_02045EC0((struct MsgBank *)(((struct Obj06406 *)p)->f28),4);
    items[1].data=func_02045EC0((struct MsgBank *)(((struct Obj06406 *)p)->f28),5);
    items[0].value=0x39e0;
    items[1].value=0x39e0;
    items[0].zero=0;
    items[1].zero=0;
    menu.heap=((struct Obj06406 *)p)->f0;
    menu.count=2;
    menu.items=items;
    menu.zero=0;
    menu.a=24;
    menu.b=6;
    menu.c=8;
    menu.d=3;
    ((struct Obj06406 *)p)->f3C=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&menu),(void *)(((struct Obj06406 *)p)->f40));
    STRBUF_Delete(items[0].data);
    STRBUF_Delete(items[1].data);
}







Object_021F48C0 *func_021F48C0(u32 owner,int count,u16 heap)
{
    int i=0;
    Object_021F48C0 *p;
    int j;
    p=func_02030734(heap,0x34,0,d_021F83A4,0x55);
    p->records=func_02030734(heap,count*0x24,0,d_021F83A4,0x57);
    p->heap=heap;
    p->count=count;
    p->owner=owner;
    for(;i<p->count;i++) {
        p->records[i].active=0;
        p->records[i].enabled=0;
    }
    p->resource=func_021F4F14(heap);
    for(j=0;j<16;j++) p->slots[j]=0x5a56;
    return p;
}







void func_021F4948(u8 *p)
{
    int i;
    NNS_GfdResetVramTransferTaskQueue();
    func_021F4F40(*(void **)(p+0xc));
    for(i=0;i<*(u16 *)(p+0x10);i++) {
        if ((*(Record_021F4948 **)(p+8))[i].active==1)
            func_021F4D40(p,(u8 *)(&(*(Record_021F4948 **)(p+8))[i]));
    }
    func_020307B0(*(void **)(p+8));
    func_020307B0(p);
}







/*
 * extent: 276-byte lead plus 4AA4 two-byte return stub; 4AA6 is zero alignment padding.
 * function_starts: 0x021F4AA4
 * lever: bitfield dirty clear retains the hoisted mask; named offset.x keeps trig load order.
 */
void func_021F4990(Object_021F4990 *p)
{
    int i;
    Entry_021F40D0 *e;
    Offset_021F40D0 offset;
    Scale scale;
    struct Trip v;
    int x,y,s,c,ox;
    for(i=0;i<p->count;i++) {
        e=&p->entries[i];
        if(e->flags.bits.active==1 && e->flags.bits.dirty==1) {
            if(e->flags.bits.rotate==1) {
                func_021F4F60((u8 *)e->data, (Offset_021F4C94 *)&offset);
                if(e->a<0) offset.x *= -1;
                ox=offset.x;
                s=FX_SinCosTable_[(e->angle>>4)*2];
                c=FX_SinCosTable_[(e->angle>>4)*2+1];
                x=ox*c-offset.y*s;
                y=ox*s+offset.y*c;
            } else { x=0; y=0; }
            v.a=(e->x-x)/16;
            v.b=(0xC0000-(e->y-y))/16;
            v.c=e->z;
            BILLBOARD_SetElemPos(p->board,e->index,&v);
            func_021F4AC8((u8 *)e,&scale.y,&scale.x);
            scale.a=e->a*scale.y;
            scale.b=e->b*scale.x;
            BILLBOARD_SetElemScale((struct Manager0204F684 *)p->board,e->index,&scale.a,&scale.b);
            BILLBOARD_SetElemRotZ(p->board,e->index,&e->angle);
            p->entries[i].flags.bits.dirty=0;
        }
    }
}







void func_021F4AA4(void *a0)
{
}







u16 func_021F4AA8(int i)
{
    u32 n = (u16)ARC_TOOL_GetArchiveFileCount(45) - 2;
    if (i >= (int)n) return 100;
    return (u16)i;
}







void func_021F4AC8(u8 *p,u8 *a,u8 *b) { u16 x,y; func_0204EDD0(func_021F4F70(*(int * *)&((struct Obj22515 *)p)->f20),&x,&y); *a=(u32)x>>5; *b=(u32)y>>5; }







int func_021F4AF0(u8 *p, int index)
{
    return func_021F4F74(*(u16 * *)&((struct Obj22518 *)p)->f20, index);
}







int func_021F4AFC(u8 *p,int index,int mode) { return func_021F4FF4((u16 *)func_021F4F54(*(u8 * *)&((struct Obj22519 *)p)->fC,index),mode); }






int func_021F4B10(u8 *p,int index,int mode) { return func_021F5064(func_021F4F54(*(u8 * *)&((struct Obj22520 *)p)->fC,index),mode); }






int func_021F4B24(u8 *p) { return func_021F50D0((const unsigned char *)(((struct Obj22521 *)p)->f20)); }






int func_021F4B30(u8 *p) { return func_021F50E0((const unsigned char *)(((struct Obj22522 *)p)->f20)); }






void *func_021F4B3C(int type) { return G3D_SYSTEM_CreateResourceArc(45,func_021F4AA8(type)); }






void func_021F4B4C(struct Tagged *a0) { func_02046EFC(a0); }






u16 func_021F4B54(u32 p) { u16 n; int i; n=((struct Obj06407 *)p)->f10; for (i=0;i<n;i++) { if (((Bits_021F40D0 *)(((struct Obj06407 *)p)->f8+i*36))->used==0) break; } if (i==n) return 0; return i; }






Entry_021F4B10 *func_021F4B88(Object_021F40D0 *p,int type,u32 id,int *v)
{
    int index;
    int data;
    Pair pair;
    index=func_021F4B54((u32)p);
    p->entries[index].type=func_021F4AA8(type);
    p->entries[index].data=func_021F4F54(p->table,type);
    data=func_021F4F70((int *)p->entries[index].data);
    func_021F4AC8((u8 *)(&p->entries[index]),&pair.y,&pair.x);
    p->entries[index].id=BILLBOARD_AddImage(p->board,id,0,data,pair.y<<5,pair.x<<5);
    p->entries[index].flags |= 16;
    func_021F4C94((Object_021F4C94 *)p, index, (int *)v, pair.y, pair.x);
    return &p->entries[index];
}






Entry_021F4B10 *func_021F4C1C(Object_021F40D0 *p, int type, u32 id, int *v)
{
    int index;
    Pair pair;
    index=func_021F4B54((u32)p);
    p->entries[index].type=func_021F4AA8(type);
    p->entries[index].data=func_021F4F54(p->table,type);
    func_021F4F70((int *)p->entries[index].data);
    func_021F4AC8((u8 *)(&p->entries[index]),&pair.y,&pair.x);
    p->entries[index].id=id;
    p->entries[index].flags=p->entries[index].flags & ~16;
    func_021F4C94((Object_021F4C94 *)p, index, (int *)v, pair.y, pair.x);
    return &p->entries[index];
}





Entry_021F4C94 *func_021F4C94(Object_021F4C94 *p, u16 index, int *v, s16_021F4C94 a, s16_021F4C94 b)
{
    p->entries[index].index = BILLBOARD_AddElem(p->board,p->entries[index].id,4096,4096,(struct Vec3 *)v,31,0,0);
    BILLBOARD_SetElemVisible(p->board,p->entries[index].index,&d_021F8300);
    p->entries[index].flags = (p->entries[index].flags & ~1) | 1;
    p->entries[index].flags |= 2;
    p->entries[index].flags |= 4;
    p->entries[index].flags = p->entries[index].flags & ~8;
    p->entries[index].x = v[0];
    p->entries[index].y = v[1];
    p->entries[index].z = v[2];
    p->entries[index].a = a;
    p->entries[index].b = b;
    p->entries[index].zero = 0;
    return &p->entries[index];
}





void func_021F4D40(u8 *p,u8 *e) { BILLBOARD_FreeElem(((struct Obj13826 *)p)->f4,((struct Obj05310 *)e)->f8); if (((Bits_021F4D40 *)e)->bit4==1) BILLBOARD_ReleaseImageVramIfUsed(((struct Obj13826 *)p)->f4,((struct Obj05310 *)e)->f4); ((struct Obj05310 *)e)->f0=((struct Obj05310 *)e)->f0 & ~1; ((struct Obj05310 *)e)->f0=((struct Obj05310 *)e)->f0 & ~2; }





void func_021F4D74(u8 *p, u8 *e, int type, u16 id)
{
    ((struct Obj02168 *)e)->fC = func_021F4AA8(type);
    *(u8 * *)&((struct Obj02168 *)e)->f20 = func_021F4F54(*(u8 * *)&((struct Obj10298 *)p)->fC,type);
    ((struct Obj02168 *)e)->f0 = ((struct Obj02168 *)e)->f0 & ~8;
    BILLBOARD_SetElemId(((struct Obj10298 *)p)->f4,((struct Obj02168 *)e)->f8,&id);
    if (((Bits_021F4D74 *)e)->bit4 == 1) BILLBOARD_ReleaseImageVramIfUsed(((struct Obj10298 *)p)->f4,((struct Obj02168 *)e)->f4);
    ((struct Obj02168 *)e)->f0 = ((struct Obj02168 *)e)->f0 & ~16;
    ((struct Obj02168 *)e)->f4 = id;
    ((struct Obj02168 *)e)->f0 = (((struct Obj02168 *)e)->f0 & ~1) | 1;
    ((struct Obj02168 *)e)->f0 |= 2;
}





/*
 * Note: when the address 0x0204F32C is registered this should resolve to EXACT. Scratch blocker.log EXACT.
 *   typedef unsigned int u32;
 *   void func_0204F32C(char *p,u32 i,u32 *out) {
 *       *out = *(u32 *)(*(char **)(p+4)+i*40+36);
 *   }
 * follower: 0x021F4E2C vector/flags leaf left unfiled while ARM9 blocks.
 */
/*
 *   once 0x0204F32C is registered (manifest/label) this should resolve to EXACT*. Scratch blocker.log EXACT.
 *   typedef unsigned int u32;
 *   void func_0204F32C(char *p,u32 i,u32 *out) {
 *       *out = *(u32 *)(*(char **)(p+4)+i*40+36);
 *   }
 * follower: 0x021F4E2C vector/flags leaf left unfiled while ARM9 blocks.
 */
void func_021F4DE0(char *p, char *e, void *a2)
{
    u32 first, second;
    if (!((Bits_021F4DE0 *)e)->bit3) {
        func_0204F2CC((int)(*(void **)(p+4)),*(u32 *)(e+4),(int)(&first));
        func_0204F32C((int)(*(void **)(p+4)),*(u32 *)(e+4),(int)(&second));
        NNS_GfdRegisterNewVramTransferTask((void *)1,first,(u32)(p+18),((second & 0xffff0000) >> 16) * 8);
        *(u16 *)e |= 8;
    }
}





/*
 * lever: Three-shift single-bit extraction is a halfword bitfield copy.
 */
void func_021F4E2C(void *unused, u8 *s, u8 *d)
{
    ((struct Obj05312 *)d)->f10 = ((struct Obj05311 *)s)->f10 + 8192;
    ((struct Obj05312 *)d)->f14 = ((struct Obj05311 *)s)->f14 + 8192;
    ((struct Obj05312 *)d)->f18 = ((struct Obj05311 *)s)->f18 - 2048;
    ((struct Obj05312 *)d)->f1C = ((struct Obj05311 *)s)->f1C;
    ((struct Obj05312 *)d)->f1E = ((struct Obj05311 *)s)->f1E;
    ((struct Obj05312 *)d)->f2 = ((struct Obj05311 *)s)->f2;
    ((Flags_021F4E2C *)d)->flag = ((Flags_021F4E2C *)s)->flag;
}





void func_021F4E6C(u8 *p,u8 *e,u32 value) { BILLBOARD_SetElemVisible(((struct Obj22523 *)p)->f4,((struct Obj13827 *)e)->f8,&value); ((struct Obj13827 *)e)->f0 |=2; }





void func_021F4E8C(u32 unused,Entry_021F4E8C *p,const int *q) { p->x=q[0]; p->y=q[1]; p->z=q[2]; p->flags |=2; }





void func_021F4EA4(u32 unused,u32 p,u32 q) { ((struct Obj10300 *)q)->f0=((struct Obj01396 *)p)->f10; ((struct Obj10300 *)q)->f4=((struct Obj01396 *)p)->f14; ((struct Obj10300 *)q)->f8=((struct Obj01396 *)p)->f18; }





void func_021F4EB4(u32 unused,u32 p,s16_021F4EB4 a,s16_021F4EB4 b) { u16 flags; ((struct Obj01396 *)p)->f1C=a; flags=((struct Obj01396 *)p)->f0; ((struct Obj01396 *)p)->f1E=b; ((struct Obj01396 *)p)->f0=flags|2; }





void func_021F4EC4(u32 unused,u32 p,s16_021F4EC4 *a,s16_021F4EC4 *b) { *a=((struct Obj01396 *)p)->f1C; *b=((struct Obj01396 *)p)->f1E; }





void func_021F4ED4(u32 unused,u32 p,u16 v) { ((struct Obj01396 *)p)->f2=v; ((struct Obj01396 *)p)->f0 |=2; }





/*
 * extent: six-byte body, two zero alignment bytes before separately filed 021F4EE8.
 */
void func_021F4EE0(int unused, u16 *p, u16 *out)
{
    *out = p[1];
}





/*
 * lever: wide int argument into u16 bitfield preserves the redundant
 * halfword narrowing pair; a u16 argument produced 16 bytes, DIFF10.
 * leaf: sole overlay blocker of handed ov133 021B8140; explicit unused r0
 * retained from the caller. Twenty-byte body; following getter omitted.
 */
void func_021F4EE8(int unused,Flags_021F4EE8 *s,int flag)
{
    s->flag=flag;
}





int func_021F4EFC(int unused, Flags_021F4EFC *p)
{
    return p->flag;
}





void func_021F4F04(u8 *p, Offset_021F4C94 *out)
{
    func_021F4F60(*(u8 * *)&((struct Obj01396 *)p)->f20, out);
}






u32 func_021F4F10(u8 *p) { return ((struct Obj22528 *)p)->fC; }





u32 *func_021F4F14(int heap)
{
    u32 *p = func_02030734(heap, 8, 0, d_021F83B4, 0x47);
    int r = ARC_UTIL_LoadMember(45, 0x65, 0, heap);
    p[0] = r;
    p[1] = r;
    return p;
}





void func_021F4F40(void **p) { func_020307B0(*p); func_020307B0(p); }






u8 *func_021F4F54(u8 *p, int i) { return *(u8 * *)&((struct Obj22530 *)p)->f4 + i * 0xc; }





void func_021F4F60(u8 *p, Offset_021F4C94 *out)
{
    out->x = ((struct Obj13828 *)p)->f4;
    out->y = ((struct Obj13828 *)p)->f5;
}





/*
 * follower: func_021F4F74 filed separately.
 */
int func_021F4F70(int *p) { return *p; }





int func_021F4F74(u16 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[3] & 1) return 1; break;
    case 2: if (p[3] & 2) return 1; break;
    case 3: if (p[3] & 4) return 1; break;
    case 4: if (p[3] & 8) return 1; break;
    case 5: if (p[3] & 16) return 1; break;
    case 6: if (p[3] & 32) return 1; break;
    case 7: case 8: if (p[3] & 64) return 1; break;
    case 9: return 0;
    }
    return 0;
}





int func_021F4FF4(u16 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[3] & 1) return 1; break;
    case 2: if (p[3] & 2) return 1; break;
    case 3: if (p[3] & 12) return 1; break;
    case 4: if (p[3] & 16) return 1; break;
    case 5: if (p[3] & 32) return 1; break;
    case 6: case 7: if (p[3] & 64) return 1; break;
    case 8: return 0;
    }
    return 0;
}





int func_021F5064(u8 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[8] == 0) return 1; break;
    case 2: if (p[8] == 1) return 1; break;
    case 3: if ((u8)(p[8] + 254) <= 1) return 1; break;
    case 4: if (p[8] == 4) return 1; break;
    case 5: if (p[8] == 5) return 1; break;
    case 6: case 7: if (p[8] == 6) return 1; break;
    case 8: return 0;
    }
    return 0;
}






int func_021F50D0(const unsigned char *p)
{
    if (*(const unsigned short *)&((struct Obj22532 *)p)->f6 & 0x80)
        return 1;
    return 0;
}






int func_021F50E0(const unsigned char *p)
{
    if (*(const unsigned short *)&((struct Obj22533 *)p)->f6 & 0x200)
        return 1;
    return 0;
}





/*
 * leaf: Sole unresolved ov112 mapper for concrete-correct ov133 func_021B8444; root reserved ownership.
 */
int func_021F50F4(unsigned index)
{
    switch (index) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3:
    case 4: return 3;
    case 5: return 4;
    case 6: return 5;
    case 7: return 6;
    case 8: return 7;
    case 9: return 8;
    default: return 9;
    }
}






unsigned char func_021F5140(void *p, int i)
{
    return *(unsigned char *)(func_021F4F54(p, i) + 9);
}






unsigned char func_021F514C(void *p, int i)
{
    return *(unsigned char *)(func_021F4F54(p, i) + 10);
}





unsigned char func_021F5158(void *p, int i)
{
    return *(func_021F4F54(p, i) + 8);
}




void *func_021F5164(u32 heap)
{
    int i;
    char *p;
    p = sub_02030734(heap, 4456, 0, d_021F83C4, 76);
    ((struct Obj10301 *)p)->f0 = heap;
    ((struct Obj10301 *)p)->f4 = func_021F55F8(8, heap);
    for (i = 0; i < 8; i++) *(u32 *)(p + i * 556 + 8) = 0;
    func_021F621C(((struct Obj10301 *)p)->f4);
    return p;
}




void func_021F51B0(int a) { int i; for(i=0;i<8;i++) { if(((Fields *)(a+i*556))->active==1)func_021F5330(a,a+8+i*556); } func_021F5644(((struct Obj10302 *)a)->f4); func_020307B0((void *)a); }




void func_021F51E8(u8 *p) { func_021F5678((char *)(((struct Obj22534 *)p)->f4)); }




/*
 * 2026-10-05 (wave D5 lane 02): ov112 0x021F546C is a different function from the ov194 one (a 172-byte slot
 * writer: mode >= 7 copies an input record into slot mode-7, modes 4 and 5 write four words). Parked as
 * src/pending/ov/ov112_func_021F546C.c, DIFF. Still blocks this MATCH.
 * 2026-10-05 (wD4 lane16): re-checked, bytes identical; MATCH only because func_021F546C (ov112) has no EXACT witness (ov194 has a pending file at the same address, 9 overlays overlap). Needs the callback matched in ov112.
 * 2026-10-05 (wave D6 lane 01): bytes still identical; still blocked by ov112 021F546C (DIFF 170/172).
 * 2026-10-05 (wave D7 lane 01): still MATCH, blocked by ov112 021F546C, now DIFF 172/172 with 27 bytes
 *   (two register-order residues, see that file).
 * 2026-10-05 (wave D8 lane 01): bytes still identical, still blocked by ov112 021F546C. Finding for
 *   that draft (not in this lane, so not edited): dropping const from the input pointer
 *   (`Input_021F40D0 *in`) fixes its residue (b), the modes 4/5 y-before-x load order; with the y local kept
 *   it is 172/172 with 5 bytes left, only the slot multiply colours (original idx r4 and product
 *   r1, ours idx r1 and product r4). No change to that from: no idx local, mode -= 7, unsigned idx,
 *   idx declared at function scope, an else-if chain, a void * parameter cast to Big *, an inline
 *   SetSlot(p, idx, in), enabled stored last; a byte-offset form loses the copy shape.
 * 2026-10-05 (D9 lane 02): still blocked by ov112 021F546C. Tried one more reading there: `Slot *s = &p->slots[mode - 7]` instead of the idx local (worse, 128 bytes differ).
 * 2026-10-05 (D9r lane 45): bytes still identical; still blocked by ov112 021F546C, now DIFF 172/172 with
 *   5 bytes (only the slot multiply colours), see that file.
 * 2026-10-05 (D9r lane 74): bytes still identical; still blocked by ov112 021F546C (DIFF, 5 bytes, slot
 *   multiply colours; new tries listed in that file).
 * 2026-10-05 (D9r lane 94): bytes still identical; still blocked by ov112 021F546C (DIFF, 5 bytes, slot multiply
 *   colours; three more tries listed in that file).
 * 2026-10-05 (D9r lane 121): bytes still identical (re-checked); still blocked by ov112 021F546C (DIFF, 5 bytes,
 *   same slot multiply colours; new tries listed in that file).
 * 2026-10-05 (D9r lane 144): bytes still identical (re-checked); still blocked by ov112 021F546C (DIFF, 5 bytes;
 *   new tries listed in that file).
 * 2026-10-05 (D9r lane 155): bytes still identical (re-checked); still blocked by ov112 021F546C (DIFF, 5 bytes;
 *   new finding and tries listed in that file).
 * 2026-10-05 (D9r lane 171): bytes still identical (re-checked, MATCH, the func_021F546C ABS32 word has no
 *   witness); still blocked by ov112 021F546C (DIFF, 5 bytes; tries listed in that file).
 * 2026-10-05 (D9r lane 195): ov112 021F546C is now EXACT (src/matched/ov/ov112_func_021F546C.c, compound product form).
 *   This MATCH should resolve once the integrator regenerates the witness index (the tool still reads the old
 *   manifest: "no witness outside"). Re-run match.py one after the regenerate and file as EXACT.
 */
void func_021F51F4(void **p) { func_021F56BC(p[1],func_021F546C); }




u8 *func_021F5204(Scene *p,const u8 *b,int c)
{
    int i;
    int j;
    u8 *slot;
    Buffers buffers;
    char *second;
    for(i=0;i<8;i++) if(p->slots[i].active==0) break;
    slot=(u8 *)&p->slots[i];
    ((struct Obj22535 *)slot)->f0=1;
    func_021F5518((u8 *)b,buffers.stats,0);
    p->slots[i].primary=func_021F611C(p->main,0,0,0,(u32)buffers.stats,(u32)slot,0);
    if(c==1) {
        func_021F5518((u8 *)b,buffers.stats,1);
        p->slots[(u32)i].secondary=func_021F611C(p->main,0,0,0,(u32)buffers.stats,(u32)slot,0);
        func_021F62DC(p->slots[(u32)i].secondary);
    } else p->slots[i].secondary=0;
    p->slots[i].enabled=1;
    p->slots[i].object=(u8 *)p->slots[i].primary;
    buffers.scale[0]=65536;
    buffers.scale[1]=65536;
    buffers.scale[2]=4096;
    for(j=0;j<9;j++) p->slots[i].tracks[j].value=0;
    p->slots[i].f548=0;
    p->slots[i].f552=0;
    p->slots[i].f524=0;
    p->slots[i].f528=0;
    p->slots[i].f532=0;
    p->slots[i].f536=0;
    p->slots[i].f540=0;
    p->slots[i].f544=0;
    func_021F535C((int *)&p->slots[i],buffers.scale);
    func_021F6290(p->slots[i].object);
    return (u8 *)&p->slots[i];
}





void func_021F5330(int a, int b) {
    if (((struct Obj08022 *)b)->f10 != 0) {
        func_021F61D8((char *)(*(int *)&((struct Obj10302 *)a)->f4), (char *)(((struct Obj08022 *)b)->f10));
    }
    func_021F61D8((char *)(*(int *)&((struct Obj10302 *)a)->f4), (char *)(((struct Obj08022 *)b)->fC));
    ((struct Obj08022 *)b)->f0 = 0;
}





void func_021F5350(int *p, int *q)
{
    func_021F6234(*(char * *)&((struct Obj22536 *)p)->f8, q);
}





void func_021F535C(int *p, int *q)
{
    func_021F624C(*(char * *)&((struct Obj22537 *)p)->f8, q);
}





void func_021F5368(int *p, unsigned short v)
{
    func_021F6264(*(char * *)&((struct Obj22538 *)p)->f8, v);
}




void func_021F5374(int *p,int b) { if(b==1)func_021F62EC((char *)p[2]); else func_021F62DC((char *)p[2]); }




int func_021F5388(u8 **p) { return func_021F62D0(p[2]) != 1; }




void func_021F539C(void **p) {func_021F62A0(p[3]); if(p[4])func_021F62A0(p[4]); }





void func_021F53B4(int a) {
    func_021F6290((u8 *)(((struct Obj10304 *)a)->fC));
    if (((struct Obj10304 *)a)->f10 != 0) {
        func_021F6290((u8 *)(((struct Obj10304 *)a)->f10));
    }
}



void func_021F53CC(int a, u32 n)
{
    func_021F62B0(*(char * *)&((struct Obj22540 *)a)->f8, n);
}




void func_021F53D8(int a) {
    if (((struct Obj01717 *)a)->f4 == 1) {
        func_021F62FC((Object *)((struct Obj01717 *)a)->fC, (Object *)((struct Obj01717 *)a)->f10);
        ((struct Obj01717 *)a)->f8 = ((struct Obj01717 *)a)->f10;
        ((struct Obj01717 *)a)->f4 = 0;
        func_021F62DC((char *)(((struct Obj01717 *)a)->fC));
    } else {
        func_021F62FC((Object *)((struct Obj01717 *)a)->f10, (Object *)((struct Obj01717 *)a)->fC);
        ((struct Obj01717 *)a)->f8 = ((struct Obj01717 *)a)->fC;
        ((struct Obj01717 *)a)->f4 = 1;
        func_021F62DC((char *)(((struct Obj01717 *)a)->f10));
    }
}



void func_021F5414(int a,int b) { if(b!=((struct Obj01717 *)a)->f4)func_021F53D8(a); }




/*
 * Recursive MATCH unblocker: unresolved callee named by the parked
 * ov112_func_021F80B0.  The +8 word is loaded once and shared by both arms
 * (the two identical loads CSE, which schedules the load before the branch).
 *
 * Addresses are Black-image addresses.
 */
void func_021F5424(int a0, int a1)
{
    if (a1 == 1)
        func_021F626C((u8 *)(((struct Obj13831 *)a0)->f8));
    else
        func_021F6280((u8 *)(((struct Obj13831 *)a0)->f8));
}



void func_021F5438(void **p,int b) {func_021F622C(p[1],b); }



void func_021F5444(u8 *p, int a)
{
    func_021F6230(*(u8 * *)&((struct Obj22542 *)p)->f4, a);
}




u8 *func_021F5450(u8 *p, int i) { return p + 0x14 + i * 0x38; }




u8 *func_021F545C(u8 *p) { return p + 0x20c; }



/*
 * follower: aggregate-copy function 021F546C parked as DIFF note.
 */
char *func_021F5464(char *p) { return p+536; }



void func_021F546C(unsigned mode, Input_021F53CC *in, Big *p)
{
    if (mode >= 7) {
        u32 off = mode - 7;
        u32 base = (u32)p;
        off *= 0x38;
        *(int *)(base + off + 0x14) = 1;
        base += off;
        *(Vec_021F56BC *)(base + 0x18) = in->a;
        *(Vec_021F56BC *)(base + 0x24) = in->b;
        *(u16 *)(base + 0x48) = in->e;
        *(u16 *)(base + 0x4a) = in->f;
        *(Vec_021F56BC *)(base + 0x30) = in->c;
        *(Vec_021F56BC *)(base + 0x3c) = in->d;
        return;
    }
    if (mode == 4) {
        int y = in->b.y;
        p->t[0].x = in->b.x;
        p->t[0].y = y;
        p->t[0].z = 0;
        p->flag[0] = 1;
        return;
    }
    if (mode == 5) {
        int y = in->b.y;
        p->t[1].x = in->b.x;
        p->t[1].y = y;
        p->t[1].z = 0;
        p->flag[1] = 1;
    }
}



void func_021F5518(u8 *p, u32 *out, u32 k)
{
    u32 a, c, d, flag;
    int b;
    u32 n;
    POKE_TOOL_GetBoxParam(((struct Obj04459 *)p)->f4);
    a = ((struct Obj04459 *)p)->f8;
    n = func_02019D30(a, p[11]);
    c = p[10];
    d = p[12];
    flag = 0;
    b = func_02019D58(((struct Obj04459 *)p)->f8, (u8)n);
    if (k == 1) flag = 1;
    out[0] = 52;
    out[1] = POKEGRA_GetCbrArcIndex(out[0],a,b,c,d,flag,0);
    out[2] = POKEGRA_GetPalArcIndex(out[0],a,b,c,d,flag,0);
    out[3] = POKEGRA_GetCelArcIndex(out[0],a,b,c,d,flag,0);
    out[4] = POKEGRA_GetAnmArcIndex(out[0],a,b,c,d,flag,0);
    out[5] = POKEGRA_GetMCelArcIndex(out[0],a,b,c,d,flag,0);
    out[6] = POKEGRA_GetMAnmArcIndex(out[0],a,b,c,d,flag,0);
    out[7] = POKEGRA_GetNcecArcIndex(out[0],a,b,c,d,flag,0);
    out[8] = ((struct Obj04459 *)p)->f10;
}



void *func_021F55F8(int count, u32 heap)
{
    char *p;
    p = sub_02030734(heap, 28, 1, d_021F83D4, 132);
    ((struct Obj05315 *)p)->f0 = count;
    ((struct Obj05315 *)p)->f14 = heap;
    ((struct Obj05315 *)p)->f4 = sub_02030734(heap, count * 4, 1, d_021F83D4, 137);
    ((struct Obj05315 *)p)->f18 = d_02FFFC3C;
    ((struct Obj05315 *)p)->fC = 3 << 16;
    ((struct Obj05315 *)p)->f10 = 1 << 12;
    return p;
}



void func_021F5644(char *p) { int i; char *q; for(i=0;i<((struct Obj13832 *)p)->f0;i++) { q=(*(char ***)(p+4))[i]; if(q)func_021F61D8(p,q); } func_020307B0(((struct Obj13832 *)p)->f4); func_020307B0(p); }



void func_021F5678(char *p)
{
    int i;
    u32 now;
    int delta;
    char *child;
    i = 0;
    now = d_02FFFC3C;
    delta = now - ((struct Obj10305 *)p)->f18;
    for (; i < ((struct Obj10305 *)p)->f0; i++) {
        child = (*(char ***)(p + 4))[i];
        if (child && !((Flags_021F53CC *)(child + 236))->paused)
            NNS_G2dTickMCAnimation(child + 40, delta << 12);
    }
    ((struct Obj10305 *)p)->f18 = now;
}



static inline int FxMul(s64 a, s64 b)
{
    return (int)((a * b + 0x800) >> 12);
}



static inline int RoundF(int v)
{
    return (int)(v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f);
}



static inline void LoadPose(Pose *r, char *src, int one)
{
    switch ((u16)*(u32 *)(*(char **)(src + 0x1c) + 4)) {
    case 0: {
        const PoseSrc *s = **(PoseSrc ***)src;
        r->id = s->id;
        r->rot = 0;
        r->sx = one;
        r->sy = one;
        r->dx = 0;
        r->dz = 0;
        break;
    }
    case 1:
        *r = ***(Pose ***)src;
        break;
    case 2: {
        const PoseSrc *s = **(PoseSrc ***)src;
        r->id = s->id;
        r->rot = 0;
        r->sx = one;
        r->sy = one;
        r->dx = s->dx;
        r->dz = s->dz;
        break;
    }
    }
}



static inline void G3_TexImageParam(GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    REG(0x040004A8) = (u32)((addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}



static inline void VEC_Set(Vec_021F56BC *a, int x, int y, int z)
{
    a->x = x;
    a->y = y;
    a->z = z;
}



static inline void G3_Translate(int x, int y, int z)
{
    REG(0x04000470) = (u32)x;
    REG(0x04000470) = (u32)y;
    REG(0x04000470) = (u32)z;
}



static inline void G3_Scale(int x, int y, int z)
{
    REG(0x0400046C) = (u32)x;
    REG(0x0400046C) = (u32)y;
    REG(0x0400046C) = (u32)z;
}



/*
 * note (2026-10-04, wave D3 lane 03): first complete structural draft, not tuned.
 *   Listing extent 021F56BC..021F5EDC (2080 bytes), frame 0x254, mid pool at 021F5A24
 *   (0x04000444, 02148D8C/98/A4, 021F8310/1C/04, 02148B98, 0xFFFFF000, 0xFFFA0000,
 *   02148B54, 0x04000470, 020A1B38 sin/cos table, 0x0400046C) and tail pool 021F5ED0.
 *   Shape: G3 setup (push, mode 0, store 0, mode 3, identity, mode 2); camera pick by
 *   p->f8 bit 0; outer loop i < p[0] over p[1][i] objects, skip null or (fEC >> 2) & 1;
 *   per object a 16-byte pose rec at sp+0x244 filled by kind 0/1/2 of
 *   obj+0x28 -> [0x1c] -> f4; translation/rotation/scale writes; func_021F65EC;
 *   polygon attr word built from bitfields at obj+0x90; inner loop j over parts of
 *   p->f6C->f4[rec.id]; second pose rec at sp+0x234; two func_021F5EDC calls;
 *   innermost k < 8 over bytes ent[0x30+k] != 0xFF with s64 fixed point math and
 *   an indirect call through p->fF8.
 *   Known hard parts: the compiler derives small constants from register-held I/O
 *   addresses (lsrs r1, r0, #0x13 = 0x80 from 0x04000470; lsrs #0xe = 0x1000 from
 *   0x0400046C; r0 >> 0x12 = 0x100), the float rounding idiom
 *   (v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f) then _ffix, and the
 *   many spilled loop-invariant offsets at sp+0x80..0xAC (0x80 constants and
 *   field offsets r5-8, r5-4 with r5 = 0x10C).
 *   The innermost k-loop math is an approximation of the listing (021F5BD4..021F5E8C),
 *   re-derive it from the listing before tuning.
 *   Verdict of this draft: DIFF, compiled 1680 bytes vs 2080, 1623 bytes differ, 52 of 55
 *   relocations resolved. Prologue already differs (push r3 extra, frame 0x198 vs 0x254):
 *   the original keeps more stack locals (spilled invariants at sp+0x80..0xAC, s64 halves
 *   at sp+0x68..0x74, sub-pose rec at sp+0x234, 0x5C-byte source records).
 *   Siblings: func_021F5EDC (callee, 13 args, see 021F5B6A..021F5BCC for the stack layout).
 *
 * note (2026-10-05, wave D4 lane 06): p->f8 bit 0 is now read through a one-bit bitfield
 *   (Bits_021F53CC.b0): the camera pick now gives the original lsls #0x1f; lsrs #0x1f test (1623 -> 1611
 *   bytes differ, compiled 1684 vs 2080).  Still open: the frame (0x254 vs 0x198, push without
 *   r3), the zero local stored at [sp] at entry, the spilled invariants, and the innermost k-loop
 *   which still needs re-deriving from the listing (021F5BD4..021F5E8C).
 *
 * note (2026-10-05, wave D5 lane 06): body rewritten from a fresh reading of the listing
 *   (the code after the mid pool needs `show --addr 0x021F5A5C --size 0x480 --thumb`, the
 *   default show desyncs at 021F5A44).  Fixes: r4 is obj for the whole loop, so the j/k loops
 *   read obj+0x6C/0x68/0x20/0x24/0xF8, func_021F5EDC takes obj (not p) and &cb.z (sp+0xB8,
 *   zeroed per object), and the indirect call goes through the second parameter `arg`
 *   (`arg((u8)pt->f4, &cb.in.a, obj->fF8)`); a 0x3C-byte callback record at sp+0xB4 (w out
 *   word, z, pos with y negated, x2/y2 scaled by obj->fD4/16 and fD8/16, z, obj+0xD4 vec,
 *   obj+0x100 vec, obj->fFC, ang + (pt->f10 << 11)); on pt->f4 == 5 the result goes to
 *   obj+0x100/0x104/0x108.  k loop: two rotations (part by pose.rot + sub.rot scaled by the
 *   pose*sub scale, then the table entry (x, z at +2/+4) plus pose.dx/dz by pose.rot scaled by
 *   pose.sx/sy), operand order (s64)vec * scale.  Else-branch: a local 4x4 matrix filled with
 *   constants at sp+0x114, func_0207B5C0(&d_02148B98, &m4), func_0207BE14(&m4, &d_02148B54,
 *   &m4), second func_021F660C uses that matrix.  Sub-pose kind 0 leaves dz unset.  obj skip
 *   test reads p[1][i] twice and bit 2 of obj->fEC as a bitfield; obj+0x90 and obj+0x68 are
 *   loop-level pointer locals (sp+0x5C, sp+0x50).  Result: compiled 1996 vs 2080 (was 1684),
 *   frame 0x248 vs 0x254, prologue and the obj test now line up modulo slot numbers.
 *   Open: the zero stored at [sp] at entry (push without r3 in the original), the i slot
 *   (0x5C vs 0x58), mid-pool placement (original after the attr word at 021F5A20), LoadPose
 *   register shape (original keeps src = obj+0x28 in r0), the eight spilled 0x800 rounding
 *   words at sp+0x80..0x94/0x9C/0xA0 and the 0x100/0x10C offsets at sp+0x98/0xA4..0xAC.
 * note (2026-10-05, wave D6 lane 01): three fixes from a fresh reading of the head and the pose loader.
 *   (1) func_0207D7C4 takes a fifth argument (NULL, as in the matched callers): the zero stored at [sp]
 *   at entry is that stack argument, written once before the camera-pick branch. The prologue now
 *   matches to 021F56F8 apart from the frame size. (2) LoadPose is a switch on the u16 kind with a
 *   compare chain (beq 0, cmp 1, cmp 2, b out), and the id is a u16 read (ldrh) through a
 *   {u16 id; u16 pad; s16 dx; s16 dz} source record. (3) obj+0x90, obj+0x68 and obj+0x28 come from
 *   static inline accessors (ObjAttr, ObjSrcs, ObjAnim): the parameter copy gives the original
 *   `adds r0,r4,#0; str [sp,#K]; adds r0,#0x90; str [sp,#K]` double store for srcs and keeps src =
 *   obj+0x28 in r0 for the kind load (`ldr r3,[r0,#0x1c]`). Compiled 2008 vs 2080 (was 1996).
 *   Open: frame 0x24C vs 0x254 (8 bytes of locals missing, every sp offset is 8 low), attr (obj+0x90)
 *   stays in r5 where the original spills it to sp+0x5C, the zero/kind registers in the obj head
 *   (original zero r2, kind r3; ours zero r3, kind r1), and everything after 021F57BC not re-checked.
 * note (2026-10-05, wave D7 lane 01): read only, no new build. The original spills attr (obj+0x90) to
 *   sp+0x5C and reloads it three times for the attr word (021F59EE, 021F59F0, 021F5A00); r5 is a
 *   short-lived temp there (0x10C offset at 021F59A6). So the original has more long-lived values than
 *   ours; the 8 missing frame bytes are likely two more spilled locals. Also: the callback arg is
 *   ov112 func_021F546C (mode = (u8)pt->f4, in = &cb.in.a, p = obj->fF8), see that draft for the
 *   0x38-byte slot layout of obj->fF8.
 * note (2026-10-05, wave D8 lane 01): three local shape fixes from the listing at 021F58C4..021F591E.
 *   (1) The pos and (ox, oy, 0) MTX_TRANS writes are a G3_Translate(x, y, z) static inline: the
 *   original loads all three values before the three stores (ldr r3,[sp,#0x230]; ldr r2; ldr r1;
 *   str; str; str); 0x0400046C writes are G3_Scale(sx, sy, 0x1000). (2) The flag increment is
 *   `flag++` on the u8 local: the original reloads the spilled zero and does adds/lsls/lsrs, where
 *   `flag = (u8)(flag + 1)` folds to movs #1. (3) The rotation ternary has no inner (u16) cast:
 *   `u16 a = (flag & 1) ? 0x10000 - pose.rot : pose.rot;` truncates once after the join, as in the
 *   original. Compiled 2012 vs 2080 (byte count is not comparable, every later offset shifts).
 *   Still open: frame 0x24C vs 0x254. The original spill area is 8 bytes larger (struct locals start
 *   at sp+0xB4 in the original, sp+0xAC in ours), so the original spills two more values; attr
 *   (obj+0x90) is one of them (sp+0x5C, ours keeps it in r5). G3_Translate(pos) still takes r2/r1/r0
 *   for z/y/x and r3 for the register base, the original r3/r2/r1 and r0. The rounding constant
 *   0x800 is derived from the halfword offset 2 held in r6 (`movs r6,#2; ldrsh r1,[r2,r6]` then
 *   `lsls r2,r6,#0xa`), ours does the same from r7. The k-loop past 021F5A5C was not re-checked.
 * note (2026-10-05, wave D9 lane 04): six fixes from a fresh reading of the j/k loops (compiled 2064 vs
 *   2080; on a register-blind instruction diff 94 lines differ, was 210).  (1) obj->f6C has one more
 *   level: the record table is at obj->f6C->f4 (as in matched func_021F5EDC, struct H/E1/E2), both in
 *   the j-loop test and for the entry reads.  (2) The sub-pose uses the same LoadPose switch: kind 0
 *   also zeroes dz, by cross-jumping into the kind 2 tail (listing 021F5AE6 b 021F5B1A).  The entry
 *   te and the part pt are not locals: j*8 and b*0x14 are spilled CSE values and every read is
 *   written inline.  (3) The 0x1D write goes to 0x0400044C (MTX_STORE), not 0x04000450.  (4) Every
 *   fixed-point product is a FxMul(s64 a, s64 b) static inline: it puts the vector in r0:r1 and the
 *   scale in r2:r3 and spills fx/fz with s/c in r5/r6, as in the original.  psx/psy are s64 locals
 *   assigned before the first product (the original sign-extends both before the first _ll_mul).
 *   (5) obj->fEC bit 0 is a one-bit bitfield.  (6) Declaration order `fx, fz, c, s, X, c2, Z, s2`
 *   gives the original registers in both rotations; the attr word is written right-nested
 *   a7 | (0xF0000 | (a4 | (a3 | (a5 | a0 | 0x40000000)))) to get the original OR order.
 *   Still open: frame 0x250 + push r3 vs 0x254. The original spills attr (obj+0x90) to sp+0x5C and
 *   keeps &pos in r7 across the two func_021F660C calls; ours keeps attr in r5 and rematerialises
 *   &pos.  Tried without effect: attr declaration position, block scope, a struct type, a PolyAttr
 *   inline, a Persp inline and a `Vec *pp` local for the 660C calls.  A separate `int w` local (not
 *   cb.w) gives the 0x254 frame but puts w at sp+0xB0, not 0xB4, so it is not the answer.  The k-loop
 *   head schedules the fx/fz loads before `ang` (original: ang first); `ent->parts[k]` inline instead
 *   of `b` is worse.  `j = 0` sits after the first scale product in the original; only an unnatural
 *   split of the sy/sx block reproduces it.
 * note (2026-10-05, wave D9r lane 22): 94 -> 0 instruction lines differ; 5 bytes left (two spill slots).
 *   (1) The 0x040004A8 word is the SDK inline G3_TexImageParam with enum parameter types, as in the
 *   matched sibling arm9 MCSS_Draw (same renderer: same matrix calls, Pose switch, TexInfo record
 *   at obj+0x90 with addr/s/t/fmt/pltt0 at 0/0xC/0x10/0x14/0x1C).  With it, attr spills to sp+0x5C and
 *   &pos stays in r7 across the func_021F660C calls; the frame is 0x254 and the push has no r3.
 *   (2) attr, srcs and a new ctrl (obj+0x28) are plain assignments in the order attr, ctrl, srcs (the
 *   accessor inlines are gone; they made no difference once attr spills).  (3) Declaration order
 *   ent, attr, i, j, srcs, k gives the original slots.  (4) for (j = 0; ...) without the early
 *   j = 0 statement: the 0 is shared with the first FxMul high word, as in the original.  (5) ang is an int
 *   (u16 cast at the assignment).  (6) X = te.x; X += pose.dx; (same for Z) gives the te.x-first load
 *   order.  (7) c2 (the cos of pr) is written inline at both uses: the original spills it as a CSE
 *   temp (lowest slot, reload with no copy).  (8) The obj+0x100 write is VEC_Set(v, x2, y2, 0), which
 *   loads y2 before x2.
 *   Residue: the CSE temps j*8 and c2 have swapped slots (original j*8 sp+0x34, c2 sp+0x30; ours the
 *   reverse).  A diagnostic without the j-loop use of ents[j] gives the original order, so the j*8
 *   temp is created later than c2 in ours.  Tried without effect: s2 inline too, c/s inline (worse),
 *   an idx local, operand order of the c2 products, k-loop locals at function scope, a te local in
 *   the k loop, src passed straight to LoadPose, named c2 in any scope (goes to the named slots).
 * note (2026-10-05, wave D9r lane 53): residue unchanged at 5 bytes (j*8 CSE temp at sp+0x30, cos(pr) temp
 *   at sp+0x34; original reverse).  One clean-up: the `one` local (0x1000 for the sub-pose LoadPose) is
 *   gone; LoadPose(&sub, src, 0x1000) gives the same bytes (the 0x1000 reload from sp+0x64 is the
 *   compiler's own hoisted constant).  Tried without effect on the slot pair (each a real compile): a TabEnt
 *   pointer or a u16 h local for the head read; `int id = j` alias at head or in the k loop; the j loop and the
 *   k loop as if/do-while; pose.rot inline (no pr local; same bytes); s2 load moved above the X/Z reads; X/Z
 *   reads as (ents + j)->x, as a Cell() inline, or as byte offsets (j * 8 + 2) in both head and k loop
 *   (byte offsets in the k loop only stop the j*8 CSE and LICM-hoist a second copy); cos(pr) spelled four
 *   other ways (1 + idx, (T + idx)[1], &T[idx][1], idx << 1) and through a Cos() inline; RotX/RotZ inlines and
 *   an FX_MUL-style macro for the second rotation (worse); a `const s16 *sc` pointer for s2/cos (worse);
 *   k-loop declaration order.  The pair stays swapped in every variant, so its order is probably fixed by the
 *   colouring tie-break, not by source position of the two expressions.
 * note (2026-10-05, wave D9r lane 90): residue unchanged at 5 bytes (same slot pair).  Compared with the
 *   matched twin arm9 MCSS_Draw line by line and tested new forms, each a real compile.  Same 5 bytes:
 *   outer i loop as the twin's `i = 0; if (n > 0) do { } while (++i < n);`; a typed MAnim/Frame chain
 *   (`((Obj *)obj)->anim->frames[pose.id]`) instead of the raw obj+0x6C casts; the node as a 0x5C-byte
 *   struct array (`&(*nodes)[idx]`, as the twin); a frame-cells pointer local at the head; a named int
 *   node index at the head; SDK FX_SinIdx/FX_CosIdx inlines (int idx, fx16 return) for every table
 *   read; the break test as `if (ent->parts[k] == 0xFF) break; b = ent->parts[k];`; the rotated vector
 *   in vx/vz locals before the two FxMul calls.  Worse: the head index through a NodeIdx() inline
 *   (loses the loop-condition entry pointer, 1056 B); the k loop as a static inline (not inlined,
 *   1832 B); `k < 8 && parts[k] != 0xFF` in the for condition (744 B); X/Z as one expression each
 *   (64 B).  Diagnostics (not candidates): a third use of the cos(pr) temp, X/Z reads moved to the top
 *   of the k loop, and no Z read all keep ours order (j*8 below cos(pr), b*0x14 lowest), so the order
 *   does not follow use count or program position of the k-loop reads.
 * note (2026-10-05, wave D9r lane 107): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp sp+0x34;
 *   original reverse).  New tries, each a real compile: FxMul with int (fx32) parameters as in the twin's
 *   FX_MUL, with s64 or int psx/psy (89 B, worse); cos(pr) as an int-typed value ((int) cast at both uses,
 *   or an int-returning CosI() inline; same 5 B); 5EDC prototype and Ent fields as int, as in the matched
 *   func_021F5EDC, and 660C with its matched const int / u32 parameters (same 5 B); `int b` for the part
 *   byte (same 5 B); s16 (fx16) locals for s2, for c/s, or for all three (508 to 728 B, worse); named c2 in
 *   three placements (430+ B, adds a copy); mixed spellings for the X/Z reads (index for one, byte offset
 *   for the other: 870 B; `(ents + j)->x` for X only: same 5 B).  Diagnostics: `int pr` swaps the pr and
 *   flag slots (0x38/0x3C), so local width moves slot order; an extra k-loop use of ents[j] does not move
 *   j*8 off sp+0x30.  The slot order of the two CSE temps does not follow use count or type.
 * note (2026-10-05, wave D9r lane 124): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  Tested the inline-return-temp idiom (ov125 021D6B40) on every helper in
 *   the j/k loops, each a real compile: LoadPose hand-expanded for sub, and for both pose and sub (output
 *   identical to the draft, byte for byte); RoundF hand-expanded as a plain ternary and with a block-local
 *   `int v` (identical); the two second-rotation FxMul calls hand-expanded with a block-local s64 operand
 *   (identical) or as one expression (2084 B, worse); a Cell() inline returning &ents[j] at all three
 *   uses, head included (1056 B).  So the inlines are transparent here; no inline temp sets this pair.
 *   Also tried: the head .h read as a byte offset (j*8+6: 1040 B) or as (ents + j) cast to char * (same
 *   5 B); an index local for s2/cos(pr) as u32, int (same 5 B) or u16 (483 B).  Diagnostics: `u32 j`
 *   and a branch between the two cos(pr) uses keep ours order.
 * note (2026-10-05, wave D9r lane 135): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  New head-of-j-loop forms, each a real compile, all give the same 5 B
 *   (the front end normalises them to one tree): a `Tab *tab` assigned in the loop condition
 *   (`j < (tab = &T[pose.id])->count`) and read at the head as tab->ents[j].h, also through a TabEnt
 *   pointer local taken from tab (te = tab->ents; te[j].h, or te = &tab->ents[j]); entries as a u16/s16
 *   halfword array at all three uses (`((u16 *)ents)[j * 4 + 3]`, x/z at j * 4 + 1 / + 2); getters that
 *   take the already-computed ents (or &T[pose.id]) plus j: EntH(e, j), EntAt(e, j)->h, EntIdx(e, j),
 *   TabEntAt(t, j)->h (head only: same 5 B; also at the X/Z reads: 6 B, add operand swap); src at
 *   function scope.  Worse: a struct copy `TabEnt e = ents[j]` at the head (1100 B); h as an 8-bit
 *   bitfield pair (u16, s16 or u32 fields: 998 to 1056 B, lsls/lsrs instead of and/asr); the u16 head
 *   read only (X/Z left as fields: 1040 B); tab also used at the X/Z reads (1136 B, tab held in a register).
 *   Off the head, also same 5 B: a non-const `s16` table (as in the twin), the table named
 *   FX_SinCosTable_, s2 and the second rotation in a nested block.  Diagnostics: without cos(pr) as a CSE
 *   (second use replaced) j*8 stays at sp+0x30, so it is the cos(pr) temp that lands above j*8; without
 *   the head use j*8 becomes a LICM temp at sp+0x3C (above the narrow pr/flag locals) and cos(pr) drops
 *   to sp+0x30.  No head spelling reached changes the temp order.
 * note (2026-10-05, wave D9r lane 152): residue unchanged at 5 bytes; the file body is unchanged.
 *   New tries, each a real compile.  The slot order of the late group (flag, pr, j*8, cos(pr), b*0x14)
 *   moves with the declared TYPE of j, not with any spelling of the expressions:
 *   - `long j` (or s32/unsigned long): j*8 goes to sp+0x38, above pr (pr 0x34, cos 0x30 correct, b*0x14
 *     0x2c correct): 6 B.  `unsigned int j` keeps ours order (7 B).  The type of i, of the k-loop
 *     locals (long/fx32), of b (int), of u32 (unsigned long), and fx32 struct fields do not move it.
 *   - `long j` plus `int pr` (or long pr): j*8 0x34 and cos 0x30 are correct, but pr and flag swap
 *     (pr 0x3C, flag 0x38): 9 B.  So the original needs u16 pr with j*8 between pr and cos; no type
 *     pair of (j, pr) gives that.
 *   - reusing the first-rotation `c` (or `s` and `c`) for the second rotation: j*8 goes to 0x34, but
 *     the second web of c gets the lowest slot (0x2C, below b*0x14) and the rz product gains a copy
 *     (431 B).  A named s16 c2 also adds the copy and stays at 0x34.
 *   - pose.rot spelled in place of pr in ang, s2, or one/both cos reads: j*8 goes to 0x34, but pr
 *     takes a late slot (0x30) and cos moves to 0x38 (5 to 10 B; split spellings also break the
 *     shared T+idx address).
 *   - same 5 B: cos and sin as a {sin, cos} struct table (cast or extern), five mixed spellings of one
 *     cos read (1 + idx, (T + idx)[1], *(&T[i] + 1), (idx << 1) + 1, (&T[i])[1]), FX_SinIdx/FX_CosIdx
 *     with int or long idx (with long j), pr declared with an initialiser in a block, pr at function
 *     scope reused for the G3 rotation angles (with long j: still 6 B), b assigned after its
 *     declaration, an unreferenced label between the products, byte-offset j * sizeof(TabEnt) reads.
 *   Worse: RotA/RotB inlines taking cos as a parameter (432 B, rz product copy); a `const s16 *sc`
 *   pointer (432 B); a 5EDC prototype with a long j parameter (j itself moves to the late group).
 *   Reading of the pattern: the late slots look like spill temporaries in the order the allocator
 *   spills them (round by round, then by definition order).  cos(pr) is in the first round in every
 *   variant; the original needs it in a later round than pr.  No natural source change found that
 *   does this without moving another slot.
 * note (2026-10-05, wave D9r lane 198): residue unchanged at 5 bytes; the file body is unchanged.  Lane 152's
 *   suggestion (long j or s32 plus a way to push pr back above j*8 with pr still u16) tested as a table; every row a
 *   real compile.  Slots low to high (b*0x14 is 0x2C in every row):
 *   original                     cos 30, j*8 34, pr 38, flag 3C
 *   base (int j)                 j*8 30, cos 34, pr 38, flag 3C: 5 B
 *   long j / unsigned long j     cos 30, pr 34, j*8 38, flag 3C: 6 B (8 B for unsigned long: extra loop-test byte)
 *   unsigned int / size_t j      as base, 7 B (loop-test byte differs)
 *   named `int jo = j * 8;` (head, X and Z read through ((TabEnt *)((char *)ents + jo))), int or u32, any
 *   declaration order of {jo, pr, flag} at function scope (6 orders), jo at function or j-body scope:
 *                                cos 30, pr 34, jo 38, flag 3C: 7 B (the X/Z add operand order also changes)
 *   named jo plus a redundant second `jo = j * 8;` BEFORE the last use (idiom a-redundant-second-assignment...;
 *   after the loadpose, before the 5EDC calls, before the k loop, first or after the break test in the k body):
 *                                jo 30, cos 34, pr 38, flag 3C: 6 B.  A second assignment after the last use
 *                                (after cb.in.a or at the end of the k body) is dead and gives the single-assign row.
 *   jo declared long or as a char * / void *: long moves it to a high named slot (22 B); a pointer is the base row.
 *   jo split into jh (head) and jk (k loop): as the double-assign row.
 *   So j*8 only ever lands at one of two places: below cos (temp) or above pr (named, or long-typed); the original
 *   needs the slot between them.  Declaration order and scope of jo, pr and flag never moved any slot.
 *   pr changes with long j: `int`, `long`, `u32` or `unsigned long` pr give j*8 34 and cos 30 (correct) but pr 3C and
 *   flag 38 (5 B differ); flag as u16, s16 (same 5 B), int, u32, long with `flag = (flag + 1) & 0xFF` (1429 to 1462 B);
 *   pr s16 or u8 (740 B); pr at function scope as int (14 to 43 B, pr 0x48).  pr read earlier (at the top of the j
 *   body, 1034 B; before the k loop, 309 B; first statement of the k body or declared with an initialiser before
 *   the break test, 19 B: the load schedule changes), later (just before the s2 read: 1780 B).  pr declared at j
 *   body scope: same as base (5 B) or, with long j, 6 B.
 *   The angle through u16 helpers SinA(u16)/CosA(u16): with pr passed or with pose.rot passed directly, no pr local
 *   used at the reads: same slots as base (5 B) or as long j (6 B).  j as an enum type: 1091 B; signed char j: 91 B.
 *   Diagnostic only: a third pr use does not give a comparable build (frame changes).
 *   Reading: the slot order is a ranking, not a source position: with j*8 a CSE temp it ranks below cos(pr), with
 *   j*8 named (or long) it ranks above pr, and the original has it between.  No natural form found for the middle rank.
 * note (2026-10-05, wave D9r lane S8): residue unchanged at 5 bytes; the file body is unchanged (the earlier
 *   lane left only notes, body identical to HEAD).  Slot facts measured with a Thumb decode of the compiled
 *   bytes (7 real compiles, none repeating a lane 152 or 198 row):
 *   - the compound byte-offset idiom of the sibling 021F546C (`u32 jo = j; jo *= 8;`, head, X and Z read
 *     through (TabEnt *)((char *)ents + jo)): b 2C, cos 30, pr 34, jo 38, flag 3C (7 B).  j*8 is not a named
 *     byte offset: any named local lands above pr, the original has j*8 below pr.
 *   - named locals order by first assignment in the code, not by declaration: with `u16 pr;` declared in the
 *     j body BEFORE jo, pr still lands below jo (pr 34, jo 38).  So declaration order cannot place jo.
 *   - the spilled CSE temps (b*0x14, cos, j*8) always sit below every named local.  The original j*8 (0x34)
 *     is in the temp band, above cos, which is the only pair left swapped.
 *   - statement order tests (second rotation before the first; fz read after the Z read) change the frame
 *     and schedule (836 and 842 B), so they cannot show the pair order.
 *   mwcc source (inspiredrobot/mwcc): Coloring_SelectColors flags a web Spilled in select-stack order and
 *   SpillCode_00531800 (slot assignment, not reconstructed there) runs per retry round; Coloring_SimplifyGraph
 *   picks potential spills by min spill_cost / degree.  Our listing and the original are instruction identical,
 *   so cost and degree of j*8 and cos are equal in both builds; only the web numbering or tie order differs.
 *   Lane 22's diagnostic (no head use of ents[j] gives the original order) fits a numbering reading: the head
 *   use makes j*8 a temp that is created before cos in ours.  No source form that creates cos(pr) before j*8
 *   without moving code was found (cos has no occurrence before the k body in the original listing).
 * note (2026-10-05, final push G2L5, rounds 2 and 3): 16 more real compiles, all DIFF, none better than 5 B.  `u16 j`, `s16 j`
 *   (94/93 B); rx and rz as one expression each with both products (836 B); `long j` with `int pr` at function scope
 *   (18 B), with pr assigned at object level (1794 B), with `u16`/`s16`/`unsigned short` flag (11 B), plus opt_lifetimes
 *   or scheduling off (9 B); head chain through a named `int id = pose.id` (723 B); second rotation rz before rx (652 B);
 *   `Z * cos` operand order (5 B, same).  Also off: opt_unroll_loops, opt_vectorize_loops, opt_findoffsets (5 B).  mwcc
 *   SpillCode.c: spill cost is use count times block weight; earlier lanes' extra-use diagnostics did not move the pair, so
 *   slot order is not cost-driven.  Twin arm9 MCSS_Draw re-read: no k-body pr rotation, nothing to borrow.
 * note (pass 2 2026-10-06 P2L09): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Slots low to high of the triple j*8 / cos(pr) / pr (flag 0x3C in all rows unless said):
 *   - `#pragma opt_strength_reduction off`: cos 30, pr 34, j*8 38 (6 B), the same as `long j`.  So strength
 *     reduction is what ranks j*8 below cos.  Under SR off: pose.rot for pr everywhere, pr at j-body or function
 *     scope (3 positions), u16 pr with an int/u32 `pi = pr >> 4` index, `(pr = pose.rot) + sub.rot`: SR-off row
 *     (6 to 7 B); int or u32 pr: cos 30, j*8 34 (correct), flag 38, pr 3C (9 to 10 B); pose.rot in ang only:
 *     pr 30, cos 34, j*8 38 (8 B).  SR off plus opt_loop_invariants off: 1501 B; plus opt_lifetimes off: SR-off row.
 *   - SR on, pose.rot spelled in ang only (pr kept for s2 and both cos reads): pr 30, j*8 34 (correct), cos 38,
 *     5 B.  In that form, same 5 B and same slots: ang before `pr = pose.rot`, pr declared at function scope,
 *     j-body scope or first in the k body, pr assigned right before s2, SinA/CosA(u16) inlines on pr.  Back to
 *     the base order (5 B): int pr, an int `pi = pr >> 4` or `pi = pose.rot >> 4` index, SinA/CosA(pose.rot).
 *     u32 pr 6 B; plus long j 8 B.  pose.rot in rz cos only 653 B, rx cos only 505 B, both cos or s2 only 10 B.
 *   - j*8 written as `(char *)ents + (j << 3)` at all three uses: base slots, 6 B (add operand byte); at the head
 *     only or the k loop only: 1040 B (CSE lost).  opt_loop_invariants plus opt_lifetimes off: 5 B (base).
 *   Four orders of the triple are reachable (j8<cos<pr, cos<pr<j8, pr<j8<cos, cos<j8 with pr above flag); the
 *   original cos<j8<pr<flag was not produced.
 * note (pass 3 2026-10-06 P3L04): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   New regime: the second-rotation cos stored in the first-rotation `c` with `rz += FxMul(X * s2 + Z * c, psy)`
 *   (operand order Z * c removes lane 152's extra copy): 7 B, j*8 0x34 and pr 0x38 now correct, but the c web
 *   takes 0x2C and b*0x14 moves to 0x30 (original b*0x14 0x2C, cos 0x30).  In that regime, same 7 B: s also
 *   reused for s2, s or fx reused for cos, int/u32 b, the assignment inside the rx argument, opt_loop_invariants
 *   off.  Worse: `c * X` (18 B), plus pose.rot in ang (13 B), plus SR off (13 B), plus opt_lifetimes off (546 B),
 *   c at function scope (684 B), c and s2 moved above the X/Z reads (851 B), CosA/SinA(u16) inlines (14 B).
 *   Same 5 B base slots: s reused for s2 only; an int idx index local for s2 only; RotX/RotZ inlines reading the
 *   table; a named TabEnt *e for the k-loop reads; rx/rz as a local struct; c assigned from one read with the other
 *   read inline (either order); opt_strength_reduction_strict on.  Worse: idx local in some cos reads only
 *   (508 B / 9 B), a const s16 *sc pair pointer for one cos read (502/508 B), named c2 with Z * c2 at three
 *   declaration places (14/23/64 B), separate x1/z1/x2/z2 running locals (898 B); SR off plus an `int id = j`
 *   alias at the head or in the k loop gives the SR-off row (6 B).  Reading: a reused variable's second web ranks
 *   below every optimizer temp, a first named web ranks in the named band, so cos in the original is a temp made
 *   after the SR-created j*8 web and before b*0x14; no source form found that delays the cos CSE that way.
 * note (pass 4 2026-10-06 P4L03): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Same 5 B: RotA/RotB inlines with cos as a parameter and `Z * c`; a `const s16 *sc` pair pointer with
 *   `Z * sc[1]` (with or without s2); `s16 sc[2]` with `Z * sc[1]`; rx/rz as `int r[2]` (const or non-const
 *   table); `register` on pr or j.  Long-j row (6 B, flag 3C, j*8 38, pr 34, cos 30): u16 pr reused at
 *   function scope for either G3 angle; s2 read above the X/Z reads (77 B, same slots); the head .h read as
 *   a byte offset `j * 8 + 6` or `(j << 3) + 6` (merged under long j); `u16 pr = 0;` initialisers.  Long j
 *   plus int pr with `pr >>= 4`: 9 B (pr 3C, flag 38); with u16 pr: 10 B (pr 3C, lsrs).  Long j plus int pr
 *   reused for the obj+0xFC G3 angle: 18 B (pr 0x48).  `int sc[2]` for s2/cos: 14 B (the array-to-register
 *   web takes 0x3C above flag).  Worse: `pr / 16` (15 B all reads, 656 B rz only), a {s, c} struct copied
 *   from the table (576 B), one cos read as a char* byte offset (495/504 B: the table load is never merged
 *   after CSE0), opt_propagation off (1898 B), opt_common_subs off (1438 B).  Reading (research in the lane
 *   folder): the global table load is merged only by the first CSE, so cos is always numbered before the SR
 *   j*8 web; without SR on j, j*8 is numbered at the j-loop head, before the k-top pr.  The original order
 *   (flag, pr, j*8, cos) needs one of the two moved, and no source form found does that.
 * note (pass 5 2026-10-06 P5L02): residue unchanged at 5 bytes; the body is unchanged.  41 real compiles.
 *   New forms, none better: `int b` reused as the Part byte offset (`b *= sizeof(Part)`) with the cos stored in the
 *   first-rotation c (or s, fx): instructions identical, 7 B, j*8 and pr right but b*0x14 30 above the c web 2C (both
 *   are second webs and rank by def position, so b*0x14 at the k top always ranks above the cos); declaration order
 *   of b and c in that form: same or 593/684 B.  A local struct {int s, c} for s2/cos: 14 B (promoted, cos 3C above
 *   flag).  Function-scope `s16 sn, cs` shared with the object-level G3 rotation, cs reused for the k-loop cos: 5 B
 *   base slots (narrow reuse is transparent); as int: 23 B (decl slot 0x48); a j-body `int n` node index reused for
 *   the cos: 23 B; the function-scope int ox reused: 821 B.  Same 5 B: a `u16 pr2 = pr` (or int) copy for the rz
 *   cos read (value numbering sees through it), a k-loop `const s16 *tab` for all table reads, pose.rot spelled
 *   everywhere, a named s16 c2, the break as a goto, pr first assigned at the object-level G3 angle.  Named jo
 *   (head or k loop): 7 B or 1040 B.  Strength reduction off or long j in the reuse forms: 13 B (J P B C order).
 *   Reading (research in scratchpad wD9r/p5_P5L02): every measured order fits one birth-phase ranking (decl webs and
 *   promoted aggregates, then code-order webs flag/pr/cos with the head j*8 first when not strength reduced, then
 *   strength-reduced j*8, then load-deletion temps, then b*0x14, then second webs of reused ints).  The original
 *   needs j*8 between pr and cos, which no tested source form produces.
 * note (pass 6 2026-10-06 P6L10): residue unchanged at 5 bytes; the body is unchanged.  4 real compiles plus about 25
 *   traced compiler runs (tools in scratchpad wD9r/p6_P6L10).  FX_SinIdx/FX_CosIdx inlines (`T[((idx >> 4) << 1)]`, + 1):
 *   5 B, the parameter is propagated before the first CSE and cos stays a first-run temp.  The b*0x14 split at the first
 *   CSE is caused by any branch between the uses, but only for the b chain (index under a memory-loaded base); the
 *   const-table pr/cos chain crosses the same branches at the first CSE.  Single-use locals for the rz read (pointer,
 *   cos value, second pose.rot read) are propagated back before the first CSE or leave the load read twice.  `long j`
 *   plus `int pr`: 9 B with j*8, cos and b*0x14 correct and only pr/flag swapped; the trace shows that the flag slot
 *   is the CAST(flag) temp and a named int pr outranks every temp, so the original pr must be a temp created between
 *   the flag temp and the k-preheader j*8 temp, where no pr occurrence exists.  `#pragma opt_loop_invariants off`
 *   with s2 above the X/Z reads: 77 B (the head j*8 stops being a CSE candidate).
 * note (pass 6 2026-10-06 P6L02, round 2): residue unchanged at 5 bytes; the body is unchanged.  Traced why j*8 and
 *   b*0x14 are second-run CSE temps: their uses differ at the first CSE (k-loop j*8 rewritten into CAST/MUL temps by the
 *   loop transforms; b uses split by the arg() call) and become equal after copy propagation.  Tried for cos(pr), each
 *   traced: an index local for the rz read only (propagated back before the first CSE, 5 B); an index local for s2 and
 *   rz (508 B, the loads stay different); a cos local (441 B); a const s16 *sc for s2 and rz (508 B).  Both cos reads
 *   are in one block with no call between, so the first CSE always merges them; a store, a call or a struct copy put between the
 *   two rotations (diagnostics) does not split them either.  A CSE run names each temp at the first reuse of the
 *   expression (pr at the s2 read, cos at the rz read), so j*8 between them needs a j*8 reuse inside the rx statement.
 * note (pass 6 2026-10-06 P6L02): residue unchanged at 5 bytes; the body is unchanged.  New method: mwccarm traced
 *   under a debugger (tools in scratchpad wD9r/p6_P6L02).  Measured: spill slots follow the creation order of the
 *   compiler temps ("@N" names, lower N = higher slot).  The temps are made by IRO_CommonSubs, which runs twice here;
 *   each run names its temps in IR program order.  Ours: the (int)pr temp and cos(pr) are made by the first run, j*8
 *   only by the second run (at the j-loop head), b*0x14 later in the second run.  With long j the first run names
 *   j*8 at the head (above pr).  The original order needs cos(pr) to become common only in the second run (its two
 *   reads must differ at the first CSE and become equal through the copy/expression propagation that runs between
 *   the two CSE runs), or j*8 named in the first run between the s2 read and the rz cos read.  No such form found:
 *   a pr2 copy is removed before the first run (5 B), a second pr = pose.rot reloads pose (653 B).  The same 5 B with
 *   dsi 1.1 to 1.6sp2; the hidden opt_* pragmas tested have no effect.
 * note (pass 6 2026-10-06 P6L12): EXACT (c99 and c).  The residue was the declaration-order ranking of named
 *   spill webs, not CSE timing.  Measured with the temp tracer: named locals take spill slots in declaration order,
 *   above all compiler temps.  Three changes together give the original slots (flag 3C, pr 38, j*8 34, cos 30):
 *   (1) `long j` (NitroSDK s32): j*8 becomes a first-run CSE temp at the k preheader, above cos;
 *   (2) the func_021F5EDC prototype takes the flag as `u8` (the matched callee is EXACT with `u8 mode` as well),
 *   so the u8 flag is passed without a widening cast and keeps its own named web (no CAST(flag) temp);
 *   (3) C89-style function-scope declarations: the k-loop ints (ang, fx, ... rz) before `u8 flag`, then `int pr`.
 *   With int pr and the u8 flag named, declaration order places ang/fx/X, flag, pr in the original order.
 */
/*
 * note (2026-10-04, wave D3 lane 03): first complete structural draft, not tuned.
 *   Listing extent 021F56BC..021F5EDC (2080 bytes), frame 0x254, mid pool at 021F5A24
 *   (0x04000444, 02148D8C/98/A4, 021F8310/1C/04, 02148B98, 0xFFFFF000, 0xFFFA0000,
 *   02148B54, 0x04000470, 020A1B38 sin/cos table, 0x0400046C) and tail pool 021F5ED0.
 *   Shape: G3 setup (push, mode 0, store 0, mode 3, identity, mode 2); camera pick by
 *   p->f8 bit 0; outer loop i < p[0] over p[1][i] objects, skip null or (fEC >> 2) & 1;
 *   per object a 16-byte pose rec at sp+0x244 filled by kind 0/1/2 of
 *   obj+0x28 -> [0x1c] -> f4; translation/rotation/scale writes; func_021F65EC;
 *   polygon attr word built from bitfields at obj+0x90; inner loop j over parts of
 *   p->f6C->f4[rec.id]; second pose rec at sp+0x234; two func_021F5EDC calls;
 *   innermost k < 8 over bytes ent[0x30+k] != 0xFF with s64 fixed point math and
 *   an indirect call through p->fF8.
 *   Known hard parts: the compiler derives small constants from register-held I/O
 *   addresses (lsrs r1, r0, #0x13 = 0x80 from 0x04000470; lsrs #0xe = 0x1000 from
 *   0x0400046C; r0 >> 0x12 = 0x100), the float rounding idiom
 *   (v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f) then _ffix, and the
 *   many spilled loop-invariant offsets at sp+0x80..0xAC (0x80 constants and
 *   field offsets r5-8, r5-4 with r5 = 0x10C).
 *   The innermost k-loop math is an approximation of the listing (021F5BD4..021F5E8C),
 *   re-derive it from the listing before tuning.
 *   Verdict of this draft: DIFF, compiled 1680 bytes vs 2080, 1623 bytes differ, 52 of 55
 *   relocations resolved. Prologue already differs (push r3 extra, frame 0x198 vs 0x254):
 *   the original keeps more stack locals (spilled invariants at sp+0x80..0xAC, s64 halves
 *   at sp+0x68..0x74, sub-pose rec at sp+0x234, 0x5C-byte source records).
 *   Siblings: func_021F5EDC (callee, 13 args, see 021F5B6A..021F5BCC for the stack layout).
 *
 * note (2026-10-05, wave D4 lane 06): p->f8 bit 0 is now read through a one-bit bitfield
 *   (Bits.b0): the camera pick now gives the original lsls #0x1f; lsrs #0x1f test (1623 -> 1611
 *   bytes differ, compiled 1684 vs 2080).  Still open: the frame (0x254 vs 0x198, push without
 *   r3), the zero local stored at [sp] at entry, the spilled invariants, and the innermost k-loop
 *   which still needs re-deriving from the listing (021F5BD4..021F5E8C).
 *
 * note (2026-10-05, wave D5 lane 06): body rewritten from a fresh reading of the listing
 *   (the code after the mid pool needs `show --addr 0x021F5A5C --size 0x480 --thumb`, the
 *   default show desyncs at 021F5A44).  Fixes: r4 is obj for the whole loop, so the j/k loops
 *   read obj+0x6C/0x68/0x20/0x24/0xF8, func_021F5EDC takes obj (not p) and &cb.z (sp+0xB8,
 *   zeroed per object), and the indirect call goes through the second parameter `arg`
 *   (`arg((u8)pt->f4, &cb.pos, obj->fF8)`); a 0x3C-byte callback record at sp+0xB4 (w out
 *   word, z, pos with y negated, x2/y2 scaled by obj->fD4/16 and fD8/16, z, obj+0xD4 vec,
 *   obj+0x100 vec, obj->fFC, ang + (pt->f10 << 11)); on pt->f4 == 5 the result goes to
 *   obj+0x100/0x104/0x108.  k loop: two rotations (part by pose.rot + sub.rot scaled by the
 *   pose*sub scale, then the table entry (x, z at +2/+4) plus pose.dx/dz by pose.rot scaled by
 *   pose.sx/sy), operand order (s64)vec * scale.  Else-branch: a local 4x4 matrix filled with
 *   constants at sp+0x114, func_0207B5C0(&d_02148B98, &m4), func_0207BE14(&m4, &d_02148B54,
 *   &m4), second func_021F660C uses that matrix.  Sub-pose kind 0 leaves dz unset.  obj skip
 *   test reads p[1][i] twice and bit 2 of obj->fEC as a bitfield; obj+0x90 and obj+0x68 are
 *   loop-level pointer locals (sp+0x5C, sp+0x50).  Result: compiled 1996 vs 2080 (was 1684),
 *   frame 0x248 vs 0x254, prologue and the obj test now line up modulo slot numbers.
 *   Open: the zero stored at [sp] at entry (push without r3 in the original), the i slot
 *   (0x5C vs 0x58), mid-pool placement (original after the attr word at 021F5A20), LoadPose
 *   register shape (original keeps src = obj+0x28 in r0), the eight spilled 0x800 rounding
 *   words at sp+0x80..0x94/0x9C/0xA0 and the 0x100/0x10C offsets at sp+0x98/0xA4..0xAC.
 * note (2026-10-05, wave D6 lane 01): three fixes from a fresh reading of the head and the pose loader.
 *   (1) func_0207D7C4 takes a fifth argument (NULL, as in the matched callers): the zero stored at [sp]
 *   at entry is that stack argument, written once before the camera-pick branch. The prologue now
 *   matches to 021F56F8 apart from the frame size. (2) LoadPose is a switch on the u16 kind with a
 *   compare chain (beq 0, cmp 1, cmp 2, b out), and the id is a u16 read (ldrh) through a
 *   {u16 id; u16 pad; s16 dx; s16 dz} source record. (3) obj+0x90, obj+0x68 and obj+0x28 come from
 *   static inline accessors (ObjAttr, ObjSrcs, ObjAnim): the parameter copy gives the original
 *   `adds r0,r4,#0; str [sp,#K]; adds r0,#0x90; str [sp,#K]` double store for srcs and keeps src =
 *   obj+0x28 in r0 for the kind load (`ldr r3,[r0,#0x1c]`). Compiled 2008 vs 2080 (was 1996).
 *   Open: frame 0x24C vs 0x254 (8 bytes of locals missing, every sp offset is 8 low), attr (obj+0x90)
 *   stays in r5 where the original spills it to sp+0x5C, the zero/kind registers in the obj head
 *   (original zero r2, kind r3; ours zero r3, kind r1), and everything after 021F57BC not re-checked.
 * note (2026-10-05, wave D7 lane 01): read only, no new build. The original spills attr (obj+0x90) to
 *   sp+0x5C and reloads it three times for the attr word (021F59EE, 021F59F0, 021F5A00); r5 is a
 *   short-lived temp there (0x10C offset at 021F59A6). So the original has more long-lived values than
 *   ours; the 8 missing frame bytes are likely two more spilled locals. Also: the callback arg is
 *   ov112 func_021F546C (mode = (u8)pt->f4, in = &cb.pos, p = obj->fF8), see that draft for the
 *   0x38-byte slot layout of obj->fF8.
 * note (2026-10-05, wave D8 lane 01): three local shape fixes from the listing at 021F58C4..021F591E.
 *   (1) The pos and (ox, oy, 0) MTX_TRANS writes are a G3_Translate(x, y, z) static inline: the
 *   original loads all three values before the three stores (ldr r3,[sp,#0x230]; ldr r2; ldr r1;
 *   str; str; str); 0x0400046C writes are G3_Scale(sx, sy, 0x1000). (2) The flag increment is
 *   `flag++` on the u8 local: the original reloads the spilled zero and does adds/lsls/lsrs, where
 *   `flag = (u8)(flag + 1)` folds to movs #1. (3) The rotation ternary has no inner (u16) cast:
 *   `u16 a = (flag & 1) ? 0x10000 - pose.rot : pose.rot;` truncates once after the join, as in the
 *   original. Compiled 2012 vs 2080 (byte count is not comparable, every later offset shifts).
 *   Still open: frame 0x24C vs 0x254. The original spill area is 8 bytes larger (struct locals start
 *   at sp+0xB4 in the original, sp+0xAC in ours), so the original spills two more values; attr
 *   (obj+0x90) is one of them (sp+0x5C, ours keeps it in r5). G3_Translate(pos) still takes r2/r1/r0
 *   for z/y/x and r3 for the register base, the original r3/r2/r1 and r0. The rounding constant
 *   0x800 is derived from the halfword offset 2 held in r6 (`movs r6,#2; ldrsh r1,[r2,r6]` then
 *   `lsls r2,r6,#0xa`), ours does the same from r7. The k-loop past 021F5A5C was not re-checked.
 * note (2026-10-05, wave D9 lane 04): six fixes from a fresh reading of the j/k loops (compiled 2064 vs
 *   2080; on a register-blind instruction diff 94 lines differ, was 210).  (1) obj->f6C has one more
 *   level: the record table is at obj->f6C->f4 (as in matched func_021F5EDC, struct H/E1/E2), both in
 *   the j-loop test and for the entry reads.  (2) The sub-pose uses the same LoadPose switch: kind 0
 *   also zeroes dz, by cross-jumping into the kind 2 tail (listing 021F5AE6 b 021F5B1A).  The entry
 *   te and the part pt are not locals: j*8 and b*0x14 are spilled CSE values and every read is
 *   written inline.  (3) The 0x1D write goes to 0x0400044C (MTX_STORE), not 0x04000450.  (4) Every
 *   fixed-point product is a FxMul(s64 a, s64 b) static inline: it puts the vector in r0:r1 and the
 *   scale in r2:r3 and spills fx/fz with s/c in r5/r6, as in the original.  psx/psy are s64 locals
 *   assigned before the first product (the original sign-extends both before the first _ll_mul).
 *   (5) obj->fEC bit 0 is a one-bit bitfield.  (6) Declaration order `fx, fz, c, s, X, c2, Z, s2`
 *   gives the original registers in both rotations; the attr word is written right-nested
 *   a7 | (0xF0000 | (a4 | (a3 | (a5 | a0 | 0x40000000)))) to get the original OR order.
 *   Still open: frame 0x250 + push r3 vs 0x254. The original spills attr (obj+0x90) to sp+0x5C and
 *   keeps &pos in r7 across the two func_021F660C calls; ours keeps attr in r5 and rematerialises
 *   &pos.  Tried without effect: attr declaration position, block scope, a struct type, a PolyAttr
 *   inline, a Persp inline and a `Vec *pp` local for the 660C calls.  A separate `int w` local (not
 *   cb.w) gives the 0x254 frame but puts w at sp+0xB0, not 0xB4, so it is not the answer.  The k-loop
 *   head schedules the fx/fz loads before `ang` (original: ang first); `ent->parts[k]` inline instead
 *   of `b` is worse.  `j = 0` sits after the first scale product in the original; only an unnatural
 *   split of the sy/sx block reproduces it.
 * note (2026-10-05, wave D9r lane 22): 94 -> 0 instruction lines differ; 5 bytes left (two spill slots).
 *   (1) The 0x040004A8 word is the SDK inline G3_TexImageParam with enum parameter types, as in the
 *   matched sibling arm9 MCSS_Draw (same renderer: same matrix calls, Pose switch, TexInfo record
 *   at obj+0x90 with addr/s/t/fmt/pltt0 at 0/0xC/0x10/0x14/0x1C).  With it, attr spills to sp+0x5C and
 *   &pos stays in r7 across the func_021F660C calls; the frame is 0x254 and the push has no r3.
 *   (2) attr, srcs and a new ctrl (obj+0x28) are plain assignments in the order attr, ctrl, srcs (the
 *   accessor inlines are gone; they made no difference once attr spills).  (3) Declaration order
 *   ent, attr, i, j, srcs, k gives the original slots.  (4) for (j = 0; ...) without the early
 *   j = 0 statement: the 0 is shared with the first FxMul high word, as in the original.  (5) ang is an int
 *   (u16 cast at the assignment).  (6) X = te.x; X += pose.dx; (same for Z) gives the te.x-first load
 *   order.  (7) c2 (the cos of pr) is written inline at both uses: the original spills it as a CSE
 *   temp (lowest slot, reload with no copy).  (8) The obj+0x100 write is VEC_Set(v, x2, y2, 0), which
 *   loads y2 before x2.
 *   Residue: the CSE temps j*8 and c2 have swapped slots (original j*8 sp+0x34, c2 sp+0x30; ours the
 *   reverse).  A diagnostic without the j-loop use of ents[j] gives the original order, so the j*8
 *   temp is created later than c2 in ours.  Tried without effect: s2 inline too, c/s inline (worse),
 *   an idx local, operand order of the c2 products, k-loop locals at function scope, a te local in
 *   the k loop, src passed straight to LoadPose, named c2 in any scope (goes to the named slots).
 * note (2026-10-05, wave D9r lane 53): residue unchanged at 5 bytes (j*8 CSE temp at sp+0x30, cos(pr) temp
 *   at sp+0x34; original reverse).  One clean-up: the `one` local (0x1000 for the sub-pose LoadPose) is
 *   gone; LoadPose(&sub, src, 0x1000) gives the same bytes (the 0x1000 reload from sp+0x64 is the
 *   compiler's own hoisted constant).  Tried without effect on the slot pair (each a real compile): a TabEnt
 *   pointer or a u16 h local for the head read; `int id = j` alias at head or in the k loop; the j loop and the
 *   k loop as if/do-while; pose.rot inline (no pr local; same bytes); s2 load moved above the X/Z reads; X/Z
 *   reads as (ents + j)->x, as a Cell() inline, or as byte offsets (j * 8 + 2) in both head and k loop
 *   (byte offsets in the k loop only stop the j*8 CSE and LICM-hoist a second copy); cos(pr) spelled four
 *   other ways (1 + idx, (T + idx)[1], &T[idx][1], idx << 1) and through a Cos() inline; RotX/RotZ inlines and
 *   an FX_MUL-style macro for the second rotation (worse); a `const s16 *sc` pointer for s2/cos (worse);
 *   k-loop declaration order.  The pair stays swapped in every variant, so its order is probably fixed by the
 *   colouring tie-break, not by source position of the two expressions.
 * note (2026-10-05, wave D9r lane 90): residue unchanged at 5 bytes (same slot pair).  Compared with the
 *   matched twin arm9 MCSS_Draw line by line and tested new forms, each a real compile.  Same 5 bytes:
 *   outer i loop as the twin's `i = 0; if (n > 0) do { } while (++i < n);`; a typed MAnim/Frame chain
 *   (`((Obj *)obj)->anim->frames[pose.id]`) instead of the raw obj+0x6C casts; the node as a 0x5C-byte
 *   struct array (`&(*nodes)[idx]`, as the twin); a frame-cells pointer local at the head; a named int
 *   node index at the head; SDK FX_SinIdx/FX_CosIdx inlines (int idx, fx16 return) for every table
 *   read; the break test as `if (ent->parts[k] == 0xFF) break; b = ent->parts[k];`; the rotated vector
 *   in vx/vz locals before the two FxMul calls.  Worse: the head index through a NodeIdx() inline
 *   (loses the loop-condition entry pointer, 1056 B); the k loop as a static inline (not inlined,
 *   1832 B); `k < 8 && parts[k] != 0xFF` in the for condition (744 B); X/Z as one expression each
 *   (64 B).  Diagnostics (not candidates): a third use of the cos(pr) temp, X/Z reads moved to the top
 *   of the k loop, and no Z read all keep ours order (j*8 below cos(pr), b*0x14 lowest), so the order
 *   does not follow use count or program position of the k-loop reads.
 * note (2026-10-05, wave D9r lane 107): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp sp+0x34;
 *   original reverse).  New tries, each a real compile: FxMul with int (fx32) parameters as in the twin's
 *   FX_MUL, with s64 or int psx/psy (89 B, worse); cos(pr) as an int-typed value ((int) cast at both uses,
 *   or an int-returning CosI() inline; same 5 B); 5EDC prototype and Ent fields as int, as in the matched
 *   func_021F5EDC, and 660C with its matched const int / u32 parameters (same 5 B); `int b` for the part
 *   byte (same 5 B); s16 (fx16) locals for s2, for c/s, or for all three (508 to 728 B, worse); named c2 in
 *   three placements (430+ B, adds a copy); mixed spellings for the X/Z reads (index for one, byte offset
 *   for the other: 870 B; `(ents + j)->x` for X only: same 5 B).  Diagnostics: `int pr` swaps the pr and
 *   flag slots (0x38/0x3C), so local width moves slot order; an extra k-loop use of ents[j] does not move
 *   j*8 off sp+0x30.  The slot order of the two CSE temps does not follow use count or type.
 * note (2026-10-05, wave D9r lane 124): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  Tested the inline-return-temp idiom (ov125 021D6B40) on every helper in
 *   the j/k loops, each a real compile: LoadPose hand-expanded for sub, and for both pose and sub (output
 *   identical to the draft, byte for byte); RoundF hand-expanded as a plain ternary and with a block-local
 *   `int v` (identical); the two second-rotation FxMul calls hand-expanded with a block-local s64 operand
 *   (identical) or as one expression (2084 B, worse); a Cell() inline returning &ents[j] at all three
 *   uses, head included (1056 B).  So the inlines are transparent here; no inline temp sets this pair.
 *   Also tried: the head .h read as a byte offset (j*8+6: 1040 B) or as (ents + j) cast to char * (same
 *   5 B); an index local for s2/cos(pr) as u32, int (same 5 B) or u16 (483 B).  Diagnostics: `u32 j`
 *   and a branch between the two cos(pr) uses keep ours order.
 * note (2026-10-05, wave D9r lane 135): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  New head-of-j-loop forms, each a real compile, all give the same 5 B
 *   (the front end normalises them to one tree): a `Tab *tab` assigned in the loop condition
 *   (`j < (tab = &T[pose.id])->count`) and read at the head as tab->ents[j].h, also through a TabEnt
 *   pointer local taken from tab (te = tab->ents; te[j].h, or te = &tab->ents[j]); entries as a u16/s16
 *   halfword array at all three uses (`((u16 *)ents)[j * 4 + 3]`, x/z at j * 4 + 1 / + 2); getters that
 *   take the already-computed ents (or &T[pose.id]) plus j: EntH(e, j), EntAt(e, j)->h, EntIdx(e, j),
 *   TabEntAt(t, j)->h (head only: same 5 B; also at the X/Z reads: 6 B, add operand swap); src at
 *   function scope.  Worse: a struct copy `TabEnt e = ents[j]` at the head (1100 B); h as an 8-bit
 *   bitfield pair (u16, s16 or u32 fields: 998 to 1056 B, lsls/lsrs instead of and/asr); the u16 head
 *   read only (X/Z left as fields: 1040 B); tab also used at the X/Z reads (1136 B, tab held in a register).
 *   Off the head, also same 5 B: a non-const `s16` table (as in the twin), the table named
 *   FX_SinCosTable_, s2 and the second rotation in a nested block.  Diagnostics: without cos(pr) as a CSE
 *   (second use replaced) j*8 stays at sp+0x30, so it is the cos(pr) temp that lands above j*8; without
 *   the head use j*8 becomes a LICM temp at sp+0x3C (above the narrow pr/flag locals) and cos(pr) drops
 *   to sp+0x30.  No head spelling reached changes the temp order.
 * note (2026-10-05, wave D9r lane 152): residue unchanged at 5 bytes; the file body is unchanged.
 *   New tries, each a real compile.  The slot order of the late group (flag, pr, j*8, cos(pr), b*0x14)
 *   moves with the declared TYPE of j, not with any spelling of the expressions:
 *   - `long j` (or s32/unsigned long): j*8 goes to sp+0x38, above pr (pr 0x34, cos 0x30 correct, b*0x14
 *     0x2c correct): 6 B.  `unsigned int j` keeps ours order (7 B).  The type of i, of the k-loop
 *     locals (long/fx32), of b (int), of u32 (unsigned long), and fx32 struct fields do not move it.
 *   - `long j` plus `int pr` (or long pr): j*8 0x34 and cos 0x30 are correct, but pr and flag swap
 *     (pr 0x3C, flag 0x38): 9 B.  So the original needs u16 pr with j*8 between pr and cos; no type
 *     pair of (j, pr) gives that.
 *   - reusing the first-rotation `c` (or `s` and `c`) for the second rotation: j*8 goes to 0x34, but
 *     the second web of c gets the lowest slot (0x2C, below b*0x14) and the rz product gains a copy
 *     (431 B).  A named s16 c2 also adds the copy and stays at 0x34.
 *   - pose.rot spelled in place of pr in ang, s2, or one/both cos reads: j*8 goes to 0x34, but pr
 *     takes a late slot (0x30) and cos moves to 0x38 (5 to 10 B; split spellings also break the
 *     shared T+idx address).
 *   - same 5 B: cos and sin as a {sin, cos} struct table (cast or extern), five mixed spellings of one
 *     cos read (1 + idx, (T + idx)[1], *(&T[i] + 1), (idx << 1) + 1, (&T[i])[1]), FX_SinIdx/FX_CosIdx
 *     with int or long idx (with long j), pr declared with an initialiser in a block, pr at function
 *     scope reused for the G3 rotation angles (with long j: still 6 B), b assigned after its
 *     declaration, an unreferenced label between the products, byte-offset j * sizeof(TabEnt) reads.
 *   Worse: RotA/RotB inlines taking cos as a parameter (432 B, rz product copy); a `const s16 *sc`
 *   pointer (432 B); a 5EDC prototype with a long j parameter (j itself moves to the late group).
 *   Reading of the pattern: the late slots look like spill temporaries in the order the allocator
 *   spills them (round by round, then by definition order).  cos(pr) is in the first round in every
 *   variant; the original needs it in a later round than pr.  No natural source change found that
 *   does this without moving another slot.
 * note (2026-10-05, wave D9r lane 198): residue unchanged at 5 bytes; the file body is unchanged.  Lane 152's
 *   suggestion (long j or s32 plus a way to push pr back above j*8 with pr still u16) tested as a table; every row a
 *   real compile.  Slots low to high (b*0x14 is 0x2C in every row):
 *   original                     cos 30, j*8 34, pr 38, flag 3C
 *   base (int j)                 j*8 30, cos 34, pr 38, flag 3C: 5 B
 *   long j / unsigned long j     cos 30, pr 34, j*8 38, flag 3C: 6 B (8 B for unsigned long: extra loop-test byte)
 *   unsigned int / size_t j      as base, 7 B (loop-test byte differs)
 *   named `int jo = j * 8;` (head, X and Z read through ((TabEnt *)((char *)ents + jo))), int or u32, any
 *   declaration order of {jo, pr, flag} at function scope (6 orders), jo at function or j-body scope:
 *                                cos 30, pr 34, jo 38, flag 3C: 7 B (the X/Z add operand order also changes)
 *   named jo plus a redundant second `jo = j * 8;` BEFORE the last use (idiom a-redundant-second-assignment...;
 *   after the loadpose, before the 5EDC calls, before the k loop, first or after the break test in the k body):
 *                                jo 30, cos 34, pr 38, flag 3C: 6 B.  A second assignment after the last use
 *                                (after cb.pos or at the end of the k body) is dead and gives the single-assign row.
 *   jo declared long or as a char * / void *: long moves it to a high named slot (22 B); a pointer is the base row.
 *   jo split into jh (head) and jk (k loop): as the double-assign row.
 *   So j*8 only ever lands at one of two places: below cos (temp) or above pr (named, or long-typed); the original
 *   needs the slot between them.  Declaration order and scope of jo, pr and flag never moved any slot.
 *   pr changes with long j: `int`, `long`, `u32` or `unsigned long` pr give j*8 34 and cos 30 (correct) but pr 3C and
 *   flag 38 (5 B differ); flag as u16, s16 (same 5 B), int, u32, long with `flag = (flag + 1) & 0xFF` (1429 to 1462 B);
 *   pr s16 or u8 (740 B); pr at function scope as int (14 to 43 B, pr 0x48).  pr read earlier (at the top of the j
 *   body, 1034 B; before the k loop, 309 B; first statement of the k body or declared with an initialiser before
 *   the break test, 19 B: the load schedule changes), later (just before the s2 read: 1780 B).  pr declared at j
 *   body scope: same as base (5 B) or, with long j, 6 B.
 *   The angle through u16 helpers SinA(u16)/CosA(u16): with pr passed or with pose.rot passed directly, no pr local
 *   used at the reads: same slots as base (5 B) or as long j (6 B).  j as an enum type: 1091 B; signed char j: 91 B.
 *   Diagnostic only: a third pr use does not give a comparable build (frame changes).
 *   Reading: the slot order is a ranking, not a source position: with j*8 a CSE temp it ranks below cos(pr), with
 *   j*8 named (or long) it ranks above pr, and the original has it between.  No natural form found for the middle rank.
 * note (2026-10-05, wave D9r lane S8): residue unchanged at 5 bytes; the file body is unchanged (the earlier
 *   lane left only notes, body identical to HEAD).  Slot facts measured with a Thumb decode of the compiled
 *   bytes (7 real compiles, none repeating a lane 152 or 198 row):
 *   - the compound byte-offset idiom of the sibling 021F546C (`u32 jo = j; jo *= 8;`, head, X and Z read
 *     through (TabEnt *)((char *)ents + jo)): b 2C, cos 30, pr 34, jo 38, flag 3C (7 B).  j*8 is not a named
 *     byte offset: any named local lands above pr, the original has j*8 below pr.
 *   - named locals order by first assignment in the code, not by declaration: with `u16 pr;` declared in the
 *     j body BEFORE jo, pr still lands below jo (pr 34, jo 38).  So declaration order cannot place jo.
 *   - the spilled CSE temps (b*0x14, cos, j*8) always sit below every named local.  The original j*8 (0x34)
 *     is in the temp band, above cos, which is the only pair left swapped.
 *   - statement order tests (second rotation before the first; fz read after the Z read) change the frame
 *     and schedule (836 and 842 B), so they cannot show the pair order.
 *   mwcc source (inspiredrobot/mwcc): Coloring_SelectColors flags a web Spilled in select-stack order and
 *   SpillCode_00531800 (slot assignment, not reconstructed there) runs per retry round; Coloring_SimplifyGraph
 *   picks potential spills by min spill_cost / degree.  Our listing and the original are instruction identical,
 *   so cost and degree of j*8 and cos are equal in both builds; only the web numbering or tie order differs.
 *   Lane 22's diagnostic (no head use of ents[j] gives the original order) fits a numbering reading: the head
 *   use makes j*8 a temp that is created before cos in ours.  No source form that creates cos(pr) before j*8
 *   without moving code was found (cos has no occurrence before the k body in the original listing).
 * note (2026-10-05, final push G2L5, rounds 2 and 3): 16 more real compiles, all DIFF, none better than 5 B.  `u16 j`, `s16 j`
 *   (94/93 B); rx and rz as one expression each with both products (836 B); `long j` with `int pr` at function scope
 *   (18 B), with pr assigned at object level (1794 B), with `u16`/`s16`/`unsigned short` flag (11 B), plus opt_lifetimes
 *   or scheduling off (9 B); head chain through a named `int id = pose.id` (723 B); second rotation rz before rx (652 B);
 *   `Z * cos` operand order (5 B, same).  Also off: opt_unroll_loops, opt_vectorize_loops, opt_findoffsets (5 B).  mwcc
 *   SpillCode.c: spill cost is use count times block weight; earlier lanes' extra-use diagnostics did not move the pair, so
 *   slot order is not cost-driven.  Twin arm9 MCSS_Draw re-read: no k-body pr rotation, nothing to borrow.
 * note (pass 2 2026-10-06 P2L09): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Slots low to high of the triple j*8 / cos(pr) / pr (flag 0x3C in all rows unless said):
 *   - `#pragma opt_strength_reduction off`: cos 30, pr 34, j*8 38 (6 B), the same as `long j`.  So strength
 *     reduction is what ranks j*8 below cos.  Under SR off: pose.rot for pr everywhere, pr at j-body or function
 *     scope (3 positions), u16 pr with an int/u32 `pi = pr >> 4` index, `(pr = pose.rot) + sub.rot`: SR-off row
 *     (6 to 7 B); int or u32 pr: cos 30, j*8 34 (correct), flag 38, pr 3C (9 to 10 B); pose.rot in ang only:
 *     pr 30, cos 34, j*8 38 (8 B).  SR off plus opt_loop_invariants off: 1501 B; plus opt_lifetimes off: SR-off row.
 *   - SR on, pose.rot spelled in ang only (pr kept for s2 and both cos reads): pr 30, j*8 34 (correct), cos 38,
 *     5 B.  In that form, same 5 B and same slots: ang before `pr = pose.rot`, pr declared at function scope,
 *     j-body scope or first in the k body, pr assigned right before s2, SinA/CosA(u16) inlines on pr.  Back to
 *     the base order (5 B): int pr, an int `pi = pr >> 4` or `pi = pose.rot >> 4` index, SinA/CosA(pose.rot).
 *     u32 pr 6 B; plus long j 8 B.  pose.rot in rz cos only 653 B, rx cos only 505 B, both cos or s2 only 10 B.
 *   - j*8 written as `(char *)ents + (j << 3)` at all three uses: base slots, 6 B (add operand byte); at the head
 *     only or the k loop only: 1040 B (CSE lost).  opt_loop_invariants plus opt_lifetimes off: 5 B (base).
 *   Four orders of the triple are reachable (j8<cos<pr, cos<pr<j8, pr<j8<cos, cos<j8 with pr above flag); the
 *   original cos<j8<pr<flag was not produced.
 * note (pass 3 2026-10-06 P3L04): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   New regime: the second-rotation cos stored in the first-rotation `c` with `rz += FxMul(X * s2 + Z * c, psy)`
 *   (operand order Z * c removes lane 152's extra copy): 7 B, j*8 0x34 and pr 0x38 now correct, but the c web
 *   takes 0x2C and b*0x14 moves to 0x30 (original b*0x14 0x2C, cos 0x30).  In that regime, same 7 B: s also
 *   reused for s2, s or fx reused for cos, int/u32 b, the assignment inside the rx argument, opt_loop_invariants
 *   off.  Worse: `c * X` (18 B), plus pose.rot in ang (13 B), plus SR off (13 B), plus opt_lifetimes off (546 B),
 *   c at function scope (684 B), c and s2 moved above the X/Z reads (851 B), CosA/SinA(u16) inlines (14 B).
 *   Same 5 B base slots: s reused for s2 only; an int idx index local for s2 only; RotX/RotZ inlines reading the
 *   table; a named TabEnt *e for the k-loop reads; rx/rz as a local struct; c assigned from one read with the other
 *   read inline (either order); opt_strength_reduction_strict on.  Worse: idx local in some cos reads only
 *   (508 B / 9 B), a const s16 *sc pair pointer for one cos read (502/508 B), named c2 with Z * c2 at three
 *   declaration places (14/23/64 B), separate x1/z1/x2/z2 running locals (898 B); SR off plus an `int id = j`
 *   alias at the head or in the k loop gives the SR-off row (6 B).  Reading: a reused variable's second web ranks
 *   below every optimizer temp, a first named web ranks in the named band, so cos in the original is a temp made
 *   after the SR-created j*8 web and before b*0x14; no source form found that delays the cos CSE that way.
 * note (pass 4 2026-10-06 P4L03): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Same 5 B: RotA/RotB inlines with cos as a parameter and `Z * c`; a `const s16 *sc` pair pointer with
 *   `Z * sc[1]` (with or without s2); `s16 sc[2]` with `Z * sc[1]`; rx/rz as `int r[2]` (const or non-const
 *   table); `register` on pr or j.  Long-j row (6 B, flag 3C, j*8 38, pr 34, cos 30): u16 pr reused at
 *   function scope for either G3 angle; s2 read above the X/Z reads (77 B, same slots); the head .h read as
 *   a byte offset `j * 8 + 6` or `(j << 3) + 6` (merged under long j); `u16 pr = 0;` initialisers.  Long j
 *   plus int pr with `pr >>= 4`: 9 B (pr 3C, flag 38); with u16 pr: 10 B (pr 3C, lsrs).  Long j plus int pr
 *   reused for the obj+0xFC G3 angle: 18 B (pr 0x48).  `int sc[2]` for s2/cos: 14 B (the array-to-register
 *   web takes 0x3C above flag).  Worse: `pr / 16` (15 B all reads, 656 B rz only), a {s, c} struct copied
 *   from the table (576 B), one cos read as a char* byte offset (495/504 B: the table load is never merged
 *   after CSE0), opt_propagation off (1898 B), opt_common_subs off (1438 B).  Reading (research in the lane
 *   folder): the global table load is merged only by the first CSE, so cos is always numbered before the SR
 *   j*8 web; without SR on j, j*8 is numbered at the j-loop head, before the k-top pr.  The original order
 *   (flag, pr, j*8, cos) needs one of the two moved, and no source form found does that.
 * note (pass 5 2026-10-06 P5L02): residue unchanged at 5 bytes; the body is unchanged.  41 real compiles.
 *   New forms, none better: `int b` reused as the Part byte offset (`b *= sizeof(Part)`) with the cos stored in the
 *   first-rotation c (or s, fx): instructions identical, 7 B, j*8 and pr right but b*0x14 30 above the c web 2C (both
 *   are second webs and rank by def position, so b*0x14 at the k top always ranks above the cos); declaration order
 *   of b and c in that form: same or 593/684 B.  A local struct {int s, c} for s2/cos: 14 B (promoted, cos 3C above
 *   flag).  Function-scope `s16 sn, cs` shared with the object-level G3 rotation, cs reused for the k-loop cos: 5 B
 *   base slots (narrow reuse is transparent); as int: 23 B (decl slot 0x48); a j-body `int n` node index reused for
 *   the cos: 23 B; the function-scope int ox reused: 821 B.  Same 5 B: a `u16 pr2 = pr` (or int) copy for the rz
 *   cos read (value numbering sees through it), a k-loop `const s16 *tab` for all table reads, pose.rot spelled
 *   everywhere, a named s16 c2, the break as a goto, pr first assigned at the object-level G3 angle.  Named jo
 *   (head or k loop): 7 B or 1040 B.  Strength reduction off or long j in the reuse forms: 13 B (J P B C order).
 *   Reading (research in scratchpad wD9r/p5_P5L02): every measured order fits one birth-phase ranking (decl webs and
 *   promoted aggregates, then code-order webs flag/pr/cos with the head j*8 first when not strength reduced, then
 *   strength-reduced j*8, then load-deletion temps, then b*0x14, then second webs of reused ints).  The original
 *   needs j*8 between pr and cos, which no tested source form produces.
 * note (pass 6 2026-10-06 P6L10): residue unchanged at 5 bytes; the body is unchanged.  4 real compiles plus about 25
 *   traced compiler runs (tools in scratchpad wD9r/p6_P6L10).  FX_SinIdx/FX_CosIdx inlines (`T[((idx >> 4) << 1)]`, + 1):
 *   5 B, the parameter is propagated before the first CSE and cos stays a first-run temp.  The b*0x14 split at the first
 *   CSE is caused by any branch between the uses, but only for the b chain (index under a memory-loaded base); the
 *   const-table pr/cos chain crosses the same branches at the first CSE.  Single-use locals for the rz read (pointer,
 *   cos value, second pose.rot read) are propagated back before the first CSE or leave the load read twice.  `long j`
 *   plus `int pr`: 9 B with j*8, cos and b*0x14 correct and only pr/flag swapped; the trace shows that the flag slot
 *   is the CAST(flag) temp and a named int pr outranks every temp, so the original pr must be a temp created between
 *   the flag temp and the k-preheader j*8 temp, where no pr occurrence exists.  `#pragma opt_loop_invariants off`
 *   with s2 above the X/Z reads: 77 B (the head j*8 stops being a CSE candidate).
 * note (pass 6 2026-10-06 P6L02, round 2): residue unchanged at 5 bytes; the body is unchanged.  Traced why j*8 and
 *   b*0x14 are second-run CSE temps: their uses differ at the first CSE (k-loop j*8 rewritten into CAST/MUL temps by the
 *   loop transforms; b uses split by the arg() call) and become equal after copy propagation.  Tried for cos(pr), each
 *   traced: an index local for the rz read only (propagated back before the first CSE, 5 B); an index local for s2 and
 *   rz (508 B, the loads stay different); a cos local (441 B); a const s16 *sc for s2 and rz (508 B).  Both cos reads
 *   are in one block with no call between, so the first CSE always merges them; a store, a call or a struct copy put between the
 *   two rotations (diagnostics) does not split them either.  A CSE run names each temp at the first reuse of the
 *   expression (pr at the s2 read, cos at the rz read), so j*8 between them needs a j*8 reuse inside the rx statement.
 * note (pass 6 2026-10-06 P6L02): residue unchanged at 5 bytes; the body is unchanged.  New method: mwccarm traced
 *   under a debugger (tools in scratchpad wD9r/p6_P6L02).  Measured: spill slots follow the creation order of the
 *   compiler temps ("@N" names, lower N = higher slot).  The temps are made by IRO_CommonSubs, which runs twice here;
 *   each run names its temps in IR program order.  Ours: the (int)pr temp and cos(pr) are made by the first run, j*8
 *   only by the second run (at the j-loop head), b*0x14 later in the second run.  With long j the first run names
 *   j*8 at the head (above pr).  The original order needs cos(pr) to become common only in the second run (its two
 *   reads must differ at the first CSE and become equal through the copy/expression propagation that runs between
 *   the two CSE runs), or j*8 named in the first run between the s2 read and the rz cos read.  No such form found:
 *   a pr2 copy is removed before the first run (5 B), a second pr = pose.rot reloads pose (653 B).  The same 5 B with
 *   dsi 1.1 to 1.6sp2; the hidden opt_* pragmas tested have no effect.
 * note (pass 6 2026-10-06 P6L12): EXACT (c99 and c).  The residue was the declaration-order ranking of named
 *   spill webs, not CSE timing.  Measured with the temp tracer: named locals take spill slots in declaration order,
 *   above all compiler temps.  Three changes together give the original slots (flag 3C, pr 38, j*8 34, cos 30):
 *   (1) `long j` (NitroSDK s32): j*8 becomes a first-run CSE temp at the k preheader, above cos;
 *   (2) the func_021F5EDC prototype takes the flag as `u8` (the matched callee is EXACT with `u8 mode` as well),
 *   so the u8 flag is passed without a widening cast and keeps its own named web (no CAST(flag) temp);
 *   (3) C89-style function-scope declarations: the k-loop ints (ang, fx, ... rz) before `u8 flag`, then `int pr`.
 *   With int pr and the u8 flag named, declaration order places ang/fx/X, flag, pr in the original order.
 */
void func_021F56BC(int *p, void (*arg)(unsigned, Input_021F53CC *, Big *))
{
    Pose pose;
    Pose sub;
    Vec_021F56BC pos;
    Mtx44 m3;
    Mtx43 m1;
    Mtx33 m2;
    Mtx44 m4;
    Mtx44 proj;
    Mtx33 m5;
    CB cb;
    Ent *ent;
    TexInfo *attr;
    int i;
    long j;
    char **srcs;
    u8 k;
    char *obj;
    char *ctrl;
    int ox, oy;
    int ang, fx, fz, c, s, X, Z, s2, rx, rz;
    u8 flag;
    int pr;

    REG(0x04000444) = 0;
    REG(0x04000440) = 0;
    REG(0x0400044C) = 0;
    REG(0x04000440) = 3;
    REG(0x04000454) = 0;
    REG(0x04000440) = 2;
    if ((((Bits_021F53CC *)&p[2])->b0) == 0)
        func_0207D7C4(&d_02148D8C, &d_02148D98, &d_02148DA4, 1, 0);
    else
        func_0207D7C4(&d_021F8310, &d_021F831C, &d_021F8304, 1, 0);
    func_0207B67C(&d_02148B98, &m1);
    func_02082B60(&m1, &m2);
    func_0207ADE8(&m2, &m3);

    for (i = 0; i < p[0]; i++) {
        if (((char **)p[1])[i] == 0 || ((Bits3 *)(((char **)p[1])[i] + 0xEC))->b2)
            continue;
        REG(0x04000444) = 0;
        obj = ((char **)p[1])[i];
        attr = (TexInfo *)(obj + 0x90);
        ctrl = obj + 0x28;
        srcs = (char **)(obj + 0x68);
        cb.z = 0;
        LoadPose(&pose, ctrl, 0x1000);
        pos.x = *(int *)(obj + 0xC8);
        pos.y = *(int *)(obj + 0xCC);
        pos.z = *(int *)(obj + 0xD0);
        if ((((Bits_021F53CC *)&p[2])->b0) == 0) {
            ox = pose.dx << 8;
            oy = -pose.dz << 8;
        } else {
            proj.m[0] = 0x80000;
            proj.m[1] = 0;
            proj.m[2] = 0;
            proj.m[3] = 0x80000;
            proj.m[4] = 0;
            proj.m[5] = 0x60000;
            proj.m[6] = 0;
            proj.m[7] = (int)0xFFFA0000;
            proj.m[8] = 0;
            proj.m[9] = 0;
            proj.m[10] = (int)0xFFFFF000;
            proj.m[11] = 0x1000;
            proj.m[12] = 0;
            proj.m[13] = 0;
            proj.m[14] = 0;
            proj.m[15] = (int)0xFFFFF000;
            func_0207B5C0(&d_02148B98, &m4);
            func_0207BE14(&m4, &d_02148B54, &m4);
            func_021F660C((const int *)(&pos), (const int *)(&m4), (u32 *)(&pos), (u32 *)(&cb.w));
            pos.x = func_0207C768(pos.x, cb.w);
            pos.y = func_0207C768(pos.y, cb.w);
            func_021F660C((const int *)(&pos), (const int *)(&proj), (u32 *)(&pos), (u32 *)(&cb.w));
            ox = RoundF(pose.dx);
            oy = RoundF(-pose.dz);
        }
        pos.z = *(int *)(obj + 0xD0);
        flag = 0;
        if (*(int *)(obj + 0xD4) < 0)
            flag++;
        G3_Translate(pos.x, pos.y, pos.z);
        if ((((Bits_021F53CC *)&p[2])->b0) == 0)
            func_0207D8FC(&m3);
        G3_Translate(ox, oy, 0);
        {
            u16 a = (flag & 1) ? 0x10000 - pose.rot : pose.rot;
            func_0207D888(-FX_SinCosTable_[(a >> 4) * 2], FX_SinCosTable_[(a >> 4) * 2 + 1]);
        }

        {
            int sy = FxMul(pose.sy, *(int *)(obj + 0xD8));
            int sx = FxMul(pose.sx, *(int *)(obj + 0xD4));
            G3_Scale(sx, sy, 0x1000);
        }
        {
            u16 a = *(u16 *)(obj + 0xFC);
            func_0207AF38(&m5, -FX_SinCosTable_[(a >> 4) * 2], FX_SinCosTable_[(a >> 4) * 2 + 1]);
            func_0207B51C(obj + 0x100, &m5, obj + 0x10C);
            func_0207CA00(obj + 0x100, obj + 0x10C, obj + 0x10C);
            *(int *)(obj + 0x10C) = func_0207C768(*(int *)(obj + 0x10C), *(int *)(obj + 0xD4));
            *(int *)(obj + 0x110) = func_0207C768(*(int *)(obj + 0x110), *(int *)(obj + 0xD8));
        }
        REG(0x0400044C) = 0x1D;
        func_021F65EC();
        {
            G3_TexImageParam(attr->fmt, GX_TEXGEN_TEXCOORD, attr->s, attr->t, GX_TEXREPEAT_ST, GX_TEXFLIP_ST, attr->pltt0, attr->addr);
        }
        for (j = 0; j < (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].count; j++) {
            char *src;
            src = *srcs + (((*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].h & 0xFF00) >> 8) * 0x5C;
            LoadPose(&sub, src, 0x1000);
            ent = (Ent *)(*(char **)(obj + 0x20) + 4 + sub.id * 0x38);
            if (ent->f20 != 0) {
                if (((Bits_021F53CC *)(obj + 0xEC))->b0)
                    func_021F5EDC(obj, ent->f18, ent->f1C, ent->f20, ent->f24, ent->f28,
                                  ent->f2C + ent->f24, (struct S *)(&sub), (u16 *)(&pose), j, ((Bits_021F53CC *)&p[2])->b0, &cb.z, flag);
                else
                    func_021F5EDC(obj, ent->f18, ent->f1C, ent->f20, ent->f24, ent->f28,
                                  ent->f2C, (struct S *)(&sub), (u16 *)(&pose), j, ((Bits_021F53CC *)&p[2])->b0, &cb.z, flag);
            }
            func_021F5EDC(obj, ent->f0, ent->f4, ent->f8, ent->fC, ent->f10, ent->f14,
                          (struct S *)(&sub), (u16 *)(&pose), j, ((Bits_021F53CC *)&p[2])->b0, &cb.z, flag);
            for (k = 0; k < 8; k++) {
                u8 b = ent->parts[k];

                s64 psx, psy;
                if (b == 0xFF)
                    break;
                pr = pose.rot;
                ang = (u16)(pr + sub.rot);
                fx = (*(Part **)(obj + 0x24))[b].x;
                fz = (*(Part **)(obj + 0x24))[b].z;
                s = FX_SinCosTable_[(ang >> 4) * 2];
                c = FX_SinCosTable_[(ang >> 4) * 2 + 1];
                psx = pose.sx;
                psy = pose.sy;
                rx = FxMul(fx * c - fz * s, FxMul(psx, sub.sx));
                rz = FxMul(fx * s + fz * c, FxMul(psy, sub.sy));
                X = (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].x;
                X += pose.dx;
                Z = (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].z;
                Z += pose.dz;
                s2 = FX_SinCosTable_[(pr >> 4) * 2];
                rx += FxMul(X * FX_SinCosTable_[(pr >> 4) * 2 + 1] - Z * s2, psx);
                rz += FxMul(X * s2 + FX_SinCosTable_[(pr >> 4) * 2 + 1] * Z, psy);
                rx += RoundF(sub.dx);
                rz += RoundF(sub.dz);
                cb.in.a = pos;
                cb.in.a.y = -cb.in.a.y;
                cb.in.b.x = FxMul(rx, *(int *)(obj + 0xD4) / 16);
                cb.in.b.y = FxMul(rz, *(int *)(obj + 0xD8) / 16);
                cb.in.b.z = cb.z;
                cb.in.d = *(Vec_021F56BC *)(obj + 0x100);
                cb.in.e = *(u16 *)(obj + 0xFC);
                cb.in.c = *(Vec_021F56BC *)(obj + 0xD4);
                cb.in.f = (u16)(ang + ((*(Part **)(obj + 0x24))[b].f10 << 11));
                arg((u8)(*(Part **)(obj + 0x24))[b].f4, &cb.in, *(Big **)(obj + 0xF8));
                if ((*(Part **)(obj + 0x24))[b].f4 == 5) {
                    VEC_Set((Vec_021F56BC *)(obj + 0x100), cb.in.b.x, cb.in.b.y, 0);
                }
            }
        }
        REG(0x04000448) = 1;
    }
    REG(0x04000448) = 1;
}



static inline void G3_TexPlttBase(u32 addr, int fmt)
{
    u32 param = (u32)(addr >> (4 - (fmt == 2)));
    *(volatile u32 *)0x040004AC = param;
}



static inline u32 pk(int v)
{
    return (u16)((v << 8) >> 16);
}



static inline void G3_TexCoord(u32 s, u32 t)
{
    *(volatile u32 *)0x04000488 = s | (t << 16);
}



static inline void G3_Vtx(u32 xy, u32 z)
{
    *(volatile u32 *)0x0400048C = xy;
    *(volatile u32 *)0x0400048C = z;
}



/*
 * 2026-10-05 wD5 lane16: EXACT. The record access is written in full at each use
 *   (`(*(struct H **)(p + 0x6C))->tbl[*pa].arr[a9].f2` and `.f4`), not through e1/e2 pointer locals.
 *   The CSE of the two full expressions colours pa in r2, so its load can move above the 0x4AC store.
 */
void func_021F5EDC(char *p, int a1, int a2, int a3, int a4, int a5, int a6, struct S *s, u16 *pa, int a9, int flag, int *pz, u8 mode)
{
    u16 ang;
    int x;
    int y;
    u32 s0;
    u32 s1;
    u32 t0;
    u32 t1;

    if (flag != 0) {
        func_0207D760(0x60000, 0xFFFA1000, 0xFFF81000, 0x80000, 0x1000, 0x3E8000, 0x1000, 1, 0);
        *(volatile u32 *)0x04000440 = 2;
    }
    *(volatile u32 *)0x04000450 = 0x1D;
    G3_TexPlttBase(*(u32 *)(p + 0xBC), *(int *)(p + 0xB4));
    *(volatile u32 *)0x040004A4 = 0x001F00C0;
    x = (s->fC + (*(struct H **)(p + 0x6C))->tbl[*pa].arr[a9].f2) << 8;
    y = -((*(struct H **)(p + 0x6C))->tbl[*pa].arr[a9].f4 + s->fE) << 8;
    if (mode == 0) {
        ang = *(u16 *)(p + 0xFC);
    } else if ((mode & 1) != 0) {
        ang = (u16)(0x10000 - *(u16 *)(p + 0xFC));
    }
    func_0207D888(-FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
    G3_Translate(x, y, *pz);
    func_0207D888(-FX_SinCosTable_[(*(u16 *)((char *)s + 2) >> 4) * 2], FX_SinCosTable_[(*(u16 *)((char *)s + 2) >> 4) * 2 + 1]);
    if (mode == 0) {
        G3_Scale(s->f4, s->f8, 0x1000);
        G3_Translate(a1, a2, 0);
        G3_Scale(a3, a4, 0x1000);
    } else if ((mode & 1) != 0) {
        G3_Scale(-s->f4, s->f8, 0x1000);
        G3_Translate(-a1, a2, 0);
        G3_Scale(a3, a4, 0x1000);
        G3_Translate(-0x100, 0, 0);
        a5 = 0x200000 - a5 - a3;
    }
    *(volatile u32 *)0x04000500 = 1;
    t0 = pk(a6) << 16;
    s0 = pk(a5);
    *(volatile u32 *)0x04000488 = s0 | t0;
    G3_Vtx(0, 0);
    s1 = pk(a5 + a3);
    *(volatile u32 *)0x04000488 = s1 | t0;
    G3_Vtx(0x100, 0);
    t1 = pk(a6 + a4) << 16;
    *(volatile u32 *)0x04000488 = s1 | t1;
    G3_Vtx(0xFF000100, 0);
    *(volatile u32 *)0x04000488 = s0 | t1;
    G3_Vtx(0xFF000000, 0);
    *(volatile u32 *)0x04000504 = 0;
    *(volatile u32 *)0x04000440 = 0;
    *(volatile u32 *)0x04000450 = 0;
    *(volatile u32 *)0x04000440 = 2;
    if (flag == 0) {
        *pz = *pz - 0x100;
    } else {
        *pz = *pz - 0x400;
    }
}


char *func_021F611C(char *a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g)
{
    int i;
    for(i=0;i<((struct Obj10306 *)a)->f0;i++) {
        if(SLOT==0) {
            SLOT=func_02030734((u16)((struct Obj10306 *)a)->f14,292,1,d_021F83D4,763);
            *(u32 *)(SLOT+240)=i;
            *(u32 *)(SLOT+244)=((struct Obj10306 *)a)->f14;
            *(u32 *)(SLOT+200)=b;
            *(u32 *)(SLOT+204)=c;
            *(u32 *)(SLOT+208)=d;
            *(u16 *)(SLOT+252)=0;
            *(u32 *)(SLOT+212)=4096;
            *(u32 *)(SLOT+216)=4096;
            *(u32 *)(SLOT+220)=4096;
            *(u32 *)(SLOT+248)=f;
            func_021F63B8((u8 *)a,i,(u32 *)e,g);
            break;
        }
    }
    return SLOT;
}


void func_021F61D8(char *a, char *p)
{
    func_020307B0(((struct Obj04460 *)p)->f0);
    func_020307B0(((struct Obj04460 *)p)->f10);
    func_020307B0(((struct Obj04460 *)p)->f8);
    func_020307B0(((struct Obj04460 *)p)->f18);
    func_020307B0(((struct Obj04460 *)p)->f8C);
    func_020307B0(((struct Obj04460 *)p)->f20);
    (*(u32 **)(a+4))[((struct Obj04460 *)p)->fF0] = 0;
    func_020307B0(p);
}



void func_021F621C(void *p)
{
    unsigned int v = ((struct Obj13833 *)p)->f8;
    ((struct Obj13833 *)p)->f8 = (v & ~1u) | 1u;
}


/*
 * note: blocker leaf of func_021F5438; following 021F6230 is already matched.
 */
void func_021F622C(char *p,int b) { ((struct Obj22543 *)p)->fC=b; }


void func_021F6230(u8 *p, int a)
{
    ((struct Obj22544 *)p)->f10 = a;
}



void func_021F6234(char *p, int *q)
{
    ((struct Obj10307 *)p)->fC8 = q[0];
    ((struct Obj10307 *)p)->fCC = q[1];
    ((struct Obj10307 *)p)->fD0 = q[2];
}



void func_021F624C(char *p, int *q)
{
    ((struct Obj10309 *)p)->fD4 = q[0];
    ((struct Obj10309 *)p)->fD8 = q[1];
    ((struct Obj10309 *)p)->fDC = q[2];
}



void func_021F6264(char *p, unsigned short v)
{
    ((struct Obj22545 *)p)->fFC = v;
}


void func_021F626C(u8 *p) { ((Flags *)(p+236))->a=1; }


void func_021F6280(u8 *p) { ((Flags *)(p+236))->a=0; }


void func_021F6290(u8 *p) { ((Flags *)(p+236))->b=1; }


void func_021F62A0(char *p) {((struct Obj22546 *)p)->fEC&=~2u;}


void func_021F62B0(char *p,u32 n) {void *a; a=func_020627D8(((struct Obj00722 *)p)->f1C,n);func_021F659C(p,1);NNS_G2dSetAnimSequenceToMCAnimation(p+40,a);}



u32 func_021F62D0(u8 *p) { return (((struct Obj22547 *)p)->fEC << 29) >> 31; }


void func_021F62DC(char *p) {((struct Obj22548 *)p)->fEC|=4u;}


void func_021F62EC(char *p) {((struct Obj22549 *)p)->fEC&=~4u;}


void func_021F62FC(Object *a,Object *b)
{
    b->a=a->a; b->b=a->b; b->c=a->c;
    b->b0=a->b0; b->b1=a->b1; b->b2=a->b2;
    b->h=a->h; b->d=a->d; b->e=a->e;
}


/*
 * lever: an unqualified resource pointer keeps constant r2 setup before resource loads.
 * prototype: 6469C receives the sequence in r1 despite its one-argument matched definition.
 * prototype: 48F60/49F34/30734 heap inputs are narrowed immediately before each original call.
 */
void func_021F63B8(u8 *a,int index,u32 *res,u32 mode)
{
    u8 *q=(*(u8 ***)(a+4))[index];
    void **job;
    struct AnimSequence *sequence;
    u8 *table;
    ((struct Obj00722 *)q)->fEC |= 4;
    func_02063790((u32 *)(q+144));
    func_020637D4((u32 *)(q+180));
    ((struct Obj00722 *)q)->f0=ARC_UTIL_LoadCellBankFromArchive(res[0],res[3],0,(u32)(q+4),((struct Obj00722 *)q)->fF4);
    ((struct Obj00722 *)q)->f10=ARC_UTIL_LoadMultiCellBankFromArchive(res[0],res[4],1,(u32)(q+20),((struct Obj00722 *)q)->fF4);
    ((struct Obj00722 *)q)->f8=ARC_UTIL_LoadAnimBankFromArchive(res[0],res[5],0,(u32)(q+12),((struct Obj00722 *)q)->fF4);
    ((struct Obj00722 *)q)->f18=ARC_UTIL_LoadMultiAnimBankFromArchive(res[0],res[6],0,(u32)(q+28),((struct Obj00722 *)q)->fF4);
    sequence=func_020627D8(*(struct AnimBank * *)&((struct Obj00722 *)q)->f1C,0);
    func_021F659C((char *)q,1);
    NNS_G2dSetAnimSequenceToMCAnimation((struct Obj0206469C *)(q+40),sequence);
    table=ARC_TOOL_LoadMember(res[0],res[7],(u16)(((struct Obj00722 *)q)->fF4));
    *(u8 * *)&((struct Obj00722 *)q)->f20=table;
    *(u8 * *)&((struct Obj00722 *)q)->f24=table+4+56* ((struct Obj22550 *)table)->f0;
    job=func_02030734((u16)((struct Obj00722 *)q)->fF4,36,1,d_021F83D4,1104);
    job[2]=q+144;
    job[3]=q+180;
    job[6]=*(u8 * *)&((struct Obj13834 *)a)->fC+index*16384;
    job[7]=*(u8 * *)&((struct Obj13834 *)a)->f10+index*32;
    job[8]=q;
    job[4]=func_02049DB4(res[0],res[1],1,(u32)job,((struct Obj00722 *)q)->fF4);
    job[5]=func_02049F34(res[0],res[2],(u32)(job+1),(u16)(((struct Obj00722 *)q)->fF4));
    if(res[7]==6548) MCSS_TOOL_DrawSpindaSpots(*(u8 * *)&((struct Obj22551 *)((u8 *)job[0]))->f14,res[8]);
    if(mode==1) func_020056A0((u32)func_021F6540,(u32)job,0);
    else func_021F6540(0,job);
}


/*
 * extent: Two zero padding bytes follow the compiled body.
 */
void func_021F6540(void *a, void **p)
{
    if(p[8]) ((struct Obj22552 *)((char *)p[8]))->fEC &= ~4u;
    if(p[4]) { func_02063A54(p[0],(u32)p[6],0,p[2]); func_020307B0(p[4]); }
    if(p[1]) { func_02063E54(p[1],p[7],0,p[3]); func_020307B0(p[5]); }
    func_020307B0(p);
    if(a) func_02030EAC(a);
}


void func_021F659C(char *p, int kind)
{
    ((struct Obj00722 *)p)->f8C=func_02030734((u16)((struct Obj00722 *)p)->fF4,NNS_G2dGetMCWorkAreaSize(*(u32 *)&((struct Obj00722 *)p)->fC,kind),0,d_021F83D4,1216);
    NNS_G2dInitMCAnimation(p+40,*(char * *)&((struct Obj00722 *)p)->f8C,((struct Obj00722 *)p)->f14,((struct Obj00722 *)p)->f4,((struct Obj00722 *)p)->fC,kind);
}


/*
 * volatile: Hardware register stores at listing 021F65F0,021F65F4,021F65FA.
 */
void func_021F65EC(void) {*(volatile u32 *)0x040004c0=0x4210ffff;*(volatile u32 *)0x040004c4=0x4210;*(volatile u32 *)0x040004a4=0x001f00c0;}


/*
 * extent: 310-byte code; 021F6742 is two zero alignment bytes.
 * lever: a named unsigned 64-bit sum pins carry accumulation before translation.
 * semantics: signed 32-bit products fit s64; u64 additions wrap like ADDS/ADCS.
 */
void func_021F660C(const int *p, const int *m, u32 *out, u32 *w)
{
    s64 y = p[1];
    s64 x = p[0];
    s64 z = p[2];
    u64 sum;
    sum = (u64)(x * m[0]) + (u64)(y * m[4]) + (u64)(z * m[8]);
    out[0] = (u32)(sum >> 12) + (u32)m[12];
    sum = (u64)(x * m[1]) + (u64)(y * m[5]) + (u64)(z * m[9]);
    out[1] = (u32)(sum >> 12) + (u32)m[13];
    sum = (u64)(x * m[2]) + (u64)(y * m[6]) + (u64)(z * m[10]);
    out[2] = (u32)(sum >> 12) + (u32)m[14];
    sum = (u64)(x * m[3]) + (u64)(y * m[7]) + (u64)(z * m[11]);
    *w = (u32)(sum >> 12) + (u32)m[15];
}


/*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
int func_021F6744(void *p) {int r; r=0;if(func_02017E1C(p,170,0)!=1)r=1;return r;}


char *func_021F675C(void *a,u16 heap)
{
    char *p;
    int i;
    p=func_02030734(heap,124,1,d_021F83E4,141);
    ((struct Obj03759 *)p)->f0=4;
    ((struct Obj03759 *)p)->f4=a;
    ((struct Obj03759 *)p)->f4A=0;
    for(i=0;i<9;i++) { *(u16 *)(p+20+6*i)=255; *(u16 *)(p+22+6*i)=0; *(u32 *)(p+84+4*i)=0; }
    ((struct Obj03759 *)p)->f8=func_02017E1C(a,5,0);
    p[10]=func_02017E1C(a,110,0);
    p[11]=func_02017E1C(a,111,0);
    p[12]=func_02017EAC(a);
    ((struct Obj03759 *)p)->f10=func_02017E1C(a,0,0);
    return p;
}


char *func_021F67E0(u16 a,u8 b,u8 c,u8 d,u32 e,u16 heap)
{
    int i;
    char *p;
    int j;
    p=func_02030734(heap,124,1,d_021F83E4,165);
    ((struct Obj03247 *)p)->f0=4; ((struct Obj03247 *)p)->f4=0; ((struct Obj03247 *)p)->f4A=0;
    for(i=0;i<9;i++) { *(u16 *)(p+20+6*i)=255; *(u16 *)(p+22+6*i)=0; *(u32 *)(p+84+4*i)=0; }
    for(j=0;j<4;j++) *(u16 *)(p+76+2*j)=0;
    ((struct Obj03247 *)p)->f78=0;
    ((struct Obj03247 *)p)->f8=a; p[10]=b; p[11]=c; p[12]=d; ((struct Obj03247 *)p)->f10=e;
    return p;
}


void *func_021F685C(u32 heap) {u32 *p;int z;z=0;p=func_02030734(heap,48,0,d_021F83E4,194);p[1]=z;p[2]=z;p[3]=z;p[4]=z;p[5]=z;p[6]=z;p[7]=z;return p;}


void func_021F6888(char *p) {if(((struct Obj03760 *)p)->f4)func_020307B0(((struct Obj03760 *)p)->f4);if(((struct Obj03760 *)p)->f8)func_020307B0(((struct Obj03760 *)p)->f8);if(((struct Obj03760 *)p)->fC)func_020307B0(((struct Obj03760 *)p)->fC);if(((struct Obj03760 *)p)->f10)func_020307B0(((struct Obj03760 *)p)->f10);func_020307B0(p);}


void func_021F68BC(u8 *p, u32 unused, void *sys, u8 kind, u16 heap)
{
    void *x;
    void *arc;
    u32 c, d, e;
    u8 *q;
    *p = kind;
    if (kind >= 4) {
        x = MUSICAL_DIST_SAVE_Create(sys, heap);
        arc = ARC_TOOL_CreateHandleFromMemory((void *)MUSICAL_DIST_SAVE_GetPayload(x), MUSICAL_DIST_SAVE_GetPayloadSize(x), (u16)((heap & 0x7fff) | 0x8000));
    } else {
        arc = func_020490F4(kind + 0x6f, (u16)((heap & 0x7fff) | 0x8000));
    }
    *(void **)(p + 4) = ARC_UTIL_LoadHandleMemberWithSize(arc, 0, 0, heap, (u32 *)(p + 0x20));
    *(void **)(p + 8) = ARC_UTIL_LoadHandleMemberWithSize(arc, 1, 0, heap, (u32 *)(p + 0x24));
    *(void **)(p + 0xc) = ARC_UTIL_LoadHandleMemberWithSize(arc, 2, 0, heap, (u32 *)(p + 0x28));
    c = ARC_TOOL_GetHandleMemberSize(arc, 4);
    d = ARC_TOOL_GetHandleMemberSize(arc, 3);
    e = ARC_TOOL_GetHandleMemberSize(arc, 5);
    *(u32 *)(p + 0x2c) = c + 0xc + d + e;
    q = func_02030734(heap, *(u32 *)(p + 0x2c), 1, d_021F83E4, 0x104);
    *(u8 **)(p + 0x10) = q;
    *(u8 **)(p + 0x14) = q + 0xc;
    *(u8 **)(p + 0x18) = q + 0xc + c;
    *(u32 *)(p + 0x1c) = d + *(u32 *)(p + 0x18);
    *(u32 *)q = c;
    *(u32 *)(q + 4) = d;
    *(u32 *)(q + 8) = e;
    ARC_TOOL_ReadHandleMember(arc, 4, *(void **)(p + 0x14));
    ARC_TOOL_ReadHandleMember(arc, 3, *(void **)(p + 0x18));
    ARC_TOOL_ReadHandleMember(arc, 5, *(void **)(p + 0x1c));
    ARC_TOOL_DeleteHandle(arc);
    if (kind >= 4) MUSICAL_DIST_SAVE_Delete(x);
}
