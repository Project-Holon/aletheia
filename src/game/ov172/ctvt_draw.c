/*
 * file:     ctvt_draw.c
 * unit:     yes
 * function: func_021BA174, func_021BA194, func_021BA1B4, func_021BA1D8, func_021BA1E4, func_021BA1E8, func_021BA234, func_021BA244, func_021BA248, func_021BA24C, func_021BA254, func_021BA270, func_021BA280, func_021BA2B8, func_021BA2C4, func_021BA8C4, func_021BA9EC, func_021BAE58, func_021BAEE0, func_021BB288, func_021BB4D0, func_021BB54C, func_021BB65C, func_021BB8F4, func_021BB938, func_021BB9E4, func_021BBA6C, func_021BBA88, func_021BBA94, func_021BBE5C, func_021BBF2C, func_021BC5E8, func_021BC7FC, func_021BCB88, func_021BCC40, func_021BCE2C, func_021BCEF8, func_021BD038, func_021BD0A4, func_021BD0C4, func_021BD134, func_021BD1AC, func_021BD3B8, func_021BD43C, func_021BD5AC, func_021BD5D8, func_021BD7D0, func_021BD820, func_021BD844, func_021BDB5C, func_021BDBC4, func_021BDC70, func_021BDCB8, func_021BDD6C, func_021BDEF0, func_021BDFDC, func_021BDFE4, func_021BDFEC, func_021BDFFC, func_021BE004, func_021BE00C, func_021BE010, func_021BE018, func_021BE024, func_021BE02C, func_021BE030, func_021BE034, func_021BE03C, func_021BE044, func_021BE04C, func_021BE054, func_021BE058, func_021BE05C, func_021BE078, func_021BE07C, func_021BE08C, func_021BE0A0, func_021BE0A4, func_021BE0A8, func_021BE0AC, func_021BE0B0, func_021BE0B4, func_021BE0B8, func_021BE0C8, func_021BE0CC, func_021BE0D0, func_021BE0D4, func_021BE0D8, func_021BE0EC, func_021BE0F0, func_021BE0F8, func_021BE0FC, func_021BE100, func_021BE11C, func_021BE1A4, func_021BE1E4, func_021BE210, func_021BE2E0, func_021BE2F0, func_021BE318, func_021BE34C, func_021BE364, func_021BE410, func_021BE43C
 * address:  0x021BA174
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_021B6A00  0x021B6A00  thumb  ov172
 *   func_02082A7C  0x02082A7C  arm
 *   func_021B6A18  0x021B6A18  thumb  ov172
 *   NNS_SndWaveOutAllocChannel  0x02072A44  arm
 *   func_02034714  0x02034714  arm
 *   func_02072A88  0x02072A88  arm
 *   func_02072AA0  0x02072AA0  arm
 *   func_02072BDC 0x02072BDC arm
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   func_021B7590  0x021B7590  thumb  ov172
 *   func_021B7578  0x021B7578  thumb  ov172
 *   func_021B7B80  0x021B7B80  thumb  ov172
 *   func_021B7B3C  0x021B7B3C  thumb  ov172
 *   func_021B8084  0x021B8084  thumb  ov172
 *   func_021B8740  0x021B8740  thumb  ov172
 *   func_021B8B34  0x021B8B34  thumb  ov172
 *   func_021B8B48  0x021B8B48  thumb  ov172
 *   func_021B77B4  0x021B77B4  thumb  ov172
 *   FX_SinCosTable_     0x020A1B38  data a2
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   d_021C6FF8     0x021C6FF8  data
 *   d_021C7014     0x021C7014  data
 *   d_021C6FBC     0x021C6FBC  data
 *   d_021C7030     0x021C7030  data
 *   d_021C6FDC     0x021C6FDC  data
 *   d_021C6FC8     0x021C6FC8  data
 *   d_021C7034     0x021C7034  data
 *   d_021C7038     0x021C7038  data
 *   d_021C703C     0x021C703C  data
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   func_021B8BB8  0x021B8BB8  thumb  ov172
 *   func_021B6E88  0x021B6E88  thumb  ov172
 *   func_021B8BFC  0x021B8BFC  thumb  ov172
 *   func_0207E008  0x0207E008  arm
 *   func_0207E100  0x0207E100  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   func_02041EE4 0x02041EE4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   d_021C6FB2     0x021C6FB2  data
 *   d_021C6FB4     0x021C6FB4  data
 *   d_021C6FB6     0x021C6FB6  data
 *   d_021C6FB8     0x021C6FB8  data
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_02045EC0  0x02045EC0  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   func_021B80E4  0x021B80E4  thumb  ov172
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   g_021C7234    0x021C7234  data  ov172
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_020409B4  0x020409B4  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   d_021C7234     0x021C7234  data
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   func_020414EC  0x020414EC  arm
 *   func_021B7B64  0x021B7B64  thumb  ov172
 *   func_021B80DC  0x021B80DC  thumb  ov172
 *   func_021B80EC  0x021B80EC  thumb  ov172
 *   func_021B8B7C  0x021B8B7C  thumb  ov172
 *   func_021B8C14  0x021B8C14  thumb  ov172
 *   func_021B8C20  0x021B8C20  thumb  ov172
 *   _u32_div_f     0x0209C2B0  arm
 *   APP_TASKMENU_WIN_IsTouch  0x0202824C  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 *   d_021C7040     0x021C7040  data
 *   func_021B8108  0x021B8108  thumb  ov172
 *   GFL_NET_GetScanResult  0x0203CF10  arm
 *   GFL_NET_GetScanResultMac  0x0203CF3C  arm
 *   NET_WHPIPE_GetEntryBeaconKind  0x02177B80  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02087C6C  0x02087C6C  arm
 *   func_021B85D0  0x021B85D0  thumb  ov172
 *   ZONEDATA_IsZone117  0x02013D5C  thumb
 *   ZONEDATA_IsZoneGroup118To120  0x02013D9C  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   COMM_PLAYER_SUPPORT_GetRecordFieldPtr  0x0202E930  thumb
 *   STRBUF_SetStringN  0x02045994  arm
 *   COMM_PLAYER_SUPPORT_GetRecordField  0x0202E938  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02009D50  0x02009D50  thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_021B6EE0 0x021B6EE0 thumb ov172
 *   func_021B7BA8 0x021B7BA8 thumb ov172
 *   func_021B8C3C 0x021B8C3C thumb ov172
 *   func_021B6BE0 0x021B6BE0 thumb ov172
 *   func_020056A0 0x020056A0 thumb
 *   func_0202EB14 0x0202EB14 thumb
 *   func_02012A30 0x02012A30 thumb
 *   func_02028A70 0x02028A70 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_021B6C34 0x021B6C34 thumb ov172
 *   func_021B8CB0 0x021B8CB0 thumb ov172
 *   func_021B7DCC 0x021B7DCC thumb ov172
 *   func_021B70A8 0x021B70A8 thumb ov172
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   func_021B7E34  0x021B7E34  thumb  ov172
 *   func_021B9044  0x021B9044  thumb  ov172
 *   func_021B80CC  0x021B80CC  thumb
 *   _fflt          0x0209BDBC  arm
 *   _fdiv          0x0209CE10  arm
 *   _ffixu         0x0209C4C8  arm
 *   func_021B6C48  0x021B6C48  thumb  ov172
 *   func_021B712C  0x021B712C  thumb  ov172
 *   func_02061CA4  0x02061CA4  arm
 *   FX_SinCosTable_     0x020A1B38  data
 *   func_021B71B8  0x021B71B8  thumb  ov172
 *   func_021B6C4C  0x021B6C4C  thumb  ov172
 *   func_021B9574  0x021B9574  thumb  ov172
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 *   WIPE_ResetWndMask  0x02022224  thumb
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_02040588  0x02040588  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   d_021C7050     0x021C7050  data  a4
 *   d_021C7060     0x021C7060  data  a4
 *   d_021C7080     0x021C7080  data  a4
 *   d_021C70A0     0x021C70A0  data  a4
 *   d_021C70C0     0x021C70C0  data  a4
 *   d_021C70E0     0x021C70E0  data  a4
 *   d_021C7100     0x021C7100  data  a4
 *   d_021C7120     0x021C7120  data  a4
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   func_020403F4  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02012944 0x02012944 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082A90 0x02082A90 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201F5BC 0x0201F5BC thumb
 *   TCBL_Create 0x0203101C arm
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   func_021B8FB8 0x021B8FB8 thumb ov172
 *   func_021B8CC8 0x021B8CC8 thumb ov172
 *   func_021B8BA4 0x021B8BA4 thumb ov172
 *   func_021B8B8C 0x021B8B8C thumb ov172
 *   func_021B7B30 0x021B7B30 thumb ov172
 *   func_021B8B94 0x021B8B94 thumb ov172
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   func_021B8B68 0x021B8B68 thumb ov172
 *   func_02008510 0x02008510 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_021B9F98  0x021B9F98  thumb
 *   func_021B8720 0x021B8720 thumb ov172
 *   sub_0202EB0C  0x0202EB0C  thumb
 *   unit_0202EB14  0x0202EB14  thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   d_021C7048 0x021C7048 data ov172
 *   d_021C704C 0x021C704C data ov172
 *   func_0200ED48 0x0200ED48 thumb
 *   TIME_ICON_CreateNode  0x0202EE8C  thumb
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   GAME_DATA_Create 0x020124F4 thumb
 *   KEY_GetCont 0x0203630C arm
 *   d_021C724C 0x021C724C data a4
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb  arm9
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb  arm9
 *   NNS_GfdRegisterNewVramTransferTask  0x02061CA4  arm  arm9
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb  arm9
 *   TCBL_Main  0x020310C4  arm  arm9
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 */
#include "../../matched/include/Obj05447.h"
#include "../../matched/include/Obj24096.h"
#include "../../matched/include/Obj04555.h"
#include "../../matched/include/Obj24097.h"
#include "../../matched/include/Obj24098.h"
#include "../../matched/include/Obj24099.h"
#include "../../matched/include/Obj14306.h"
#include "../../matched/include/Obj24100.h"
#include "../../matched/include/Obj06562.h"
#include "../../matched/include/Obj00276.h"
#include "../../matched/include/Obj01265.h"
#include "../../matched/include/Obj00140.h"
#include "../../matched/include/Obj00024.h"
#include "../../matched/include/Obj01757.h"
#include "../../matched/include/Obj24101.h"
#include "../../matched/include/Obj02880.h"
#include "../../matched/include/Obj14307.h"
#include "../../matched/include/Obj00836.h"
#include "../../matched/include/Obj02881.h"
#include "../../matched/include/Obj03316.h"
#include "../../matched/include/Obj08261.h"
#include "../../matched/include/Obj00330.h"
#include "../../matched/include/Obj01950.h"
#include "../../matched/include/Obj01951.h"
#include "../../matched/include/Obj01166.h"
#include "../../matched/include/Obj02882.h"
#include "../../matched/include/Obj24102.h"
#include "../../matched/include/Obj01560.h"
#include "../../matched/include/Obj24103.h"
#include "../../matched/include/Obj00543.h"
#include "../../matched/include/Obj01266.h"
#include "../../matched/include/Obj03855.h"
#include "../../matched/include/Obj10666.h"
#include "../../matched/include/Obj24105.h"
#include "../../matched/include/Obj14310.h"
#include "../../matched/include/Obj01758.h"
#include "../../matched/include/Obj02215.h"
#include "../../matched/include/Obj02216.h"
#include "../../matched/include/Obj24107.h"
#include "../../matched/include/Obj24108.h"
#include "../../matched/include/Obj24109.h"
#include "../../matched/include/Obj24110.h"
#include "../../matched/include/Obj24111.h"
#include "../../matched/include/Obj24113.h"
#include "../../matched/include/Obj24114.h"
#include "../../matched/include/Obj24115.h"
#include "../../matched/include/Obj24116.h"
#include "../../matched/include/Obj24117.h"
#include "../../matched/include/Obj24118.h"
#include "../../matched/include/Obj24119.h"
#include "../../matched/include/Obj24120.h"
#include "../../matched/include/Obj24121.h"
#include "../../matched/include/Obj24122.h"
#include "../../matched/include/Obj24123.h"
#include "../../matched/include/Obj24125.h"
#include "../../matched/include/Obj24126.h"
#include "../../matched/include/Obj24127.h"
#include "../../matched/include/Obj24128.h"
#include "../../matched/include/Obj24129.h"
#include "../../matched/include/Obj24130.h"
#include "../../matched/include/Obj24131.h"
#include "../../matched/include/Obj14311.h"
#include "../../matched/include/Obj24132.h"
#include "../../matched/include/Obj24133.h"
#include "../../matched/include/Obj24134.h"
#include "../../matched/include/Obj24135.h"
#include "../../matched/include/Obj24136.h"
#include "../../matched/include/Obj24137.h"
#include "../../matched/include/Obj24138.h"
#include "../../matched/include/Obj24139.h"
#include "../../matched/include/Obj24140.h"
#include "../../matched/include/Obj08262.h"
#include "../../matched/include/Obj10667.h"
#include "../../matched/include/Obj24141.h"
#include "../../matched/include/Obj05448.h"
#include "../../matched/include/Obj03856.h"
#include "../../matched/include/Obj24143.h"
#include "../../matched/include/Obj24145.h"
#include "../../matched/include/Obj24146.h"
#include "../../matched/include/Obj24147.h"

#define MK(c, p, a1, a2, a3, sp) CLACT_CreateActor((void *)func_021BE024(c), func_021BE018(c, a1), func_021BE018(c, a2), func_021BE018(c, a3), &d, sp, v)
#define OBJ (*(struct Obj **)(p + 0x400))
#define F(o) (*(u32_021BD43C *)(ctx + (o)))
#define WININ (*(volatile u16 *)0x04000048)
#define WINOUT (*(volatile u16 *)0x0400004a)
#define BG (*(void **)(p + 0x17c))
#define HEAP (*(u16 *)p)
struct MsgBank;
struct U16Vec;
struct CharBuf;
struct Obj;
struct Descriptor;
struct Cfg;
struct PrintSys;
struct Actor;
struct Vec2;
struct Sub0200852CObj;
struct WordSet;
struct Strbuf;
struct BigObj;
struct Sub020097BCObj;
struct R;
struct SoundSys;
struct Node;
struct TaskMenuState;
struct Tcbl;
struct S;
struct Q;
struct Bank;
struct DispConfig;
struct BgTemplate;
struct DispVram;
struct GfFont;
struct Rec;
struct S02031140;
struct StrObj;
struct TaskMenu;
struct TaskMenuTmpl;
struct Big;
struct L0200ED54;
struct Obj0203159C;
struct S020315D4;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32_021BA1B4;

typedef signed int     s32;

typedef unsigned int   u32_021BA1D8;

typedef unsigned int   u32_021BA1E4;

typedef unsigned int u32_021BA234;

typedef struct Slot02072BDC Slot02072BDC;

typedef unsigned int   u32_021BA244;

typedef unsigned int   u32_021BA248;

typedef unsigned int   u32_021BA24C;

typedef unsigned int   u32_021BA254;

typedef unsigned int   u32_021BA270;

typedef unsigned int   u32_021BA280;

typedef unsigned int   u32_021BA2B8;

typedef unsigned int   u32_021BA2C4;

typedef signed short   s16;

struct Desc {
    s16 x;
    s16 y;
    s16 z;
    u8  a;
    u8  b;
};

typedef unsigned int   u32_021BA8C4;

typedef unsigned int   u32_021BA9EC;

typedef unsigned int u32_021BAE58;

typedef unsigned long u32_021BAEE0;

struct SpritePos {
    s16 x;
    s16 y;
};

typedef unsigned long u32_021BB288;

typedef unsigned int u32_021BB4D0;

struct PtS { s16 x, y; };

typedef unsigned long u32_021BB54C;

typedef unsigned long u32_021BB65C;

typedef unsigned int   u32_021BB8F4;

typedef unsigned int u32_021BB938;

typedef unsigned int u32_021BB9E4;

typedef unsigned int   u32_021BBA6C;

typedef unsigned int   u32_021BBA88;

typedef unsigned int   u32_021BBA94;

typedef unsigned int   u32_021BBE5C;

typedef unsigned int   u32_021BBF2C;

typedef unsigned long u32_021BC5E8;

typedef unsigned long u32_021BC7FC;

struct Info {
    u8 pad0[2];
    u8 b2_0 : 1;
    u8 b2_1 : 5;
    u8 b2_6 : 2;
    u8 pad3[8];
    u8 bB_0 : 7;
    u8 bB_7 : 1;
    u32_021BC7FC w4dummy;
};

struct Rec {
    u8 pad0[4];
    u32_021BC7FC f4;
    u8 pad8[3];
    u8 bB_0 : 7;
    u8 bB_7 : 1;
    u32_021BC7FC fC_0 : 17;
    u32_021BC7FC fC_17 : 10;
    u32_021BC7FC fC_27 : 5;
    u8 pad10[0x10];
    u8 f20;
    u8 f21_0 : 1;
    u8 f21_1 : 1;
    u8 f21_2 : 6;
};

struct Bits2 {
    u8 b0 : 1;
    u8 b1 : 5;
    u8 b6 : 2;
};

struct Slot {
    u32_021BC7FC active;
    u32_021BC7FC unseen;
    u32_021BC7FC f8;
    u8 padC[8];
    u8 *buf;
    u8 kind;
    u8 mac[6];
    u8 pad1f;
    u8 row;
    u8 pad21[3];
};

struct List {
    u8 pad[0x1e4];
    struct Slot slots[15];
};

typedef unsigned long u32_021BCB88;

typedef unsigned long u32_021BCC40;

struct FlagsA {
    u8 pad[0x21];
    u8 on : 1;
    u8 rest : 7;
};

struct FlagsB {
    u8 pad[2];
    u8 low : 6;
    u8 b6 : 1;
    u8 b7 : 1;
};

typedef unsigned long u32_021BCE2C;

typedef unsigned long u32_021BCEF8;

struct Prompt {
    u32_021BCEF8 str;
    u16 color;
    u16 pad;
    u32_021BCEF8 flags;
};

typedef unsigned long u32_021BD038;

typedef unsigned long u32_021BD0A4;

typedef unsigned int u32_021BD0C4;

typedef unsigned long u32_021BD134;

typedef unsigned int u32_021BD1AC;

typedef struct { u16 heap; u8 kind, pad; u16 count, a, b, c, d; } Params;

typedef unsigned int u32_021BD3B8;

typedef unsigned int   u32_021BD43C;

typedef unsigned int u32_021BD5AC;

typedef unsigned int u32;

typedef struct { u32 w[7]; } Cfg7;

struct PltData { u32 fmt; u32 ext; u32 size; u8 *raw; };

struct CellCfg { u16 a; u16 b; u16 c; u8 d; u8 e; };

typedef unsigned int   u32_021BE0A8;

typedef unsigned int   u32_021BE0AC;

typedef unsigned int   u32_021BE0B0;

typedef unsigned int   u32_021BE0B4;

typedef unsigned int   u32_021BE0B8;

typedef unsigned int   u32_021BE0C8;

typedef unsigned int u32_021BE0CC;

typedef unsigned long u32_021BE0D0;

typedef unsigned long u32_021BE0D4;

typedef unsigned int   u32_021BE0D8;

typedef unsigned int   u32_021BE0EC;

typedef unsigned int   u32_021BE0F0;

typedef unsigned int   u32_021BE0F8;

typedef unsigned int   u32_021BE0FC;

typedef unsigned int   u32_021BE100;

typedef unsigned int u32_021BE11C;

typedef struct { u32_021BE11C heap; u8 count; u8 pad[3]; void *items; u32_021BE11C zero; u8 a,b,c,d; } Descriptor;

typedef struct { u32_021BE11C handle; u16 value; u16 pad; u32_021BE11C zero; } Item;

typedef unsigned int   u32_021BE1A4;

typedef unsigned int u32_021BE1E4;

typedef unsigned int u32_021BE210;

struct Q { u8 b[4]; };

struct Pt { u16 x; u16 y; struct Q yv; struct Q xv; };

typedef unsigned int   u32_021BE2E0;

typedef unsigned int u32_021BE2F0;

typedef unsigned int   u32_021BE318;

typedef unsigned int   u32_021BE34C;

typedef unsigned int u32_021BE364;

typedef unsigned int u32_021BE410;

typedef unsigned int u32_021BE43C;

extern void MI_CpuFill8(void *p, int v, int n);
extern int func_021B6A00(void *a0, unsigned a1, void *a2);
extern void func_02082A7C(int v, void *p, unsigned n);
extern int func_021B6A18(int a, int b, int c);
extern int  NNS_SndWaveOutAllocChannel(int size);
extern void func_02034714(const char *expr, u32_021BA1B4 line, const char *file);
extern void func_02072A88(u32_021BA1D8 *p);
extern int func_02072AA0(void *s, int fmt, void *data, int loop,
                         int start, int end, int rate, int vol, int freq, int e);
extern void func_02072BDC(Slot02072BDC *s);
extern u32_021BA254 func_0209C2B0(u32_021BA254 a, u32_021BA254 b);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32_021BA2B8 func_020307B0(void *p);
extern void func_020498F4(void *a, u32_021BA2C4 b, u32_021BA2C4 c, u32_021BA2C4 d, u32_021BA2C4 e, u32_021BA2C4 f, u16 g);
extern void func_020409B4(u32_021BA2C4 a);
extern void func_02040588(u32 which, unsigned char enable);
extern u32_021BA2C4  func_020275E4(void);
extern u32_021BA2C4  func_0202762C(void);
extern void *func_020490F4(u32_021BA2C4 id, u32_021BA2C4 heap);
extern void func_020414EC(u32_021BA2C4 a);
extern u32_021BA2C4 func_02049990(void *a0, u32_021BA2C4 a1, u32_021BA2C4 a2, u32_021BA2C4 a3, u32_021BA2C4 a4, u32_021BA2C4 a5, u32_021BA2C4 a6, u16 a7);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02040618(u32_021BA2C4 a, u32_021BA2C4 b, u32_021BA2C4 c);
extern void ARC_TOOL_DeleteHandle(void *a);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32_021BA2C4 v);
extern void CLACT_SetActorDrawEnable(struct Obj *o, unsigned int k);
extern u32_021BA2C4 BMP_WIN_Create(u32_021BA2C4 layer, u32_021BA2C4 a, u32_021BA2C4 b, u32_021BA2C4 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *w);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32_021BCC40 index);
extern void PRINTSYS_PrintQueColor(void *owner, void *b, short x, u32 y, void *text, u32 font, u32 flags);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void GFL_NET_RestartWithDefaultTimeout(u32_021BA2C4 a, u32_021BA2C4 b);
extern void func_0201F7A8(void *desc, u32_021BA8C4 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern u32_021BA8C4 BMP_WIN_Delete(struct Descriptor *d);
extern void CLACT_DeleteActor(struct Obj *p);
extern int func_021B7590(int x, char *p);
extern void func_021B7578(int x, char *p);
extern void func_021B7B80(int x, char *p);
extern void func_021B7B3C(int x, int y, int z);
extern void func_021B8084(void *a, char *q);
extern u32_021BA9EC func_021B8740(int a, int b, u8 c, u32_021BA9EC d);
extern void func_021B8B34(void *c, u32_021BA9EC v, u32_021BA9EC k);
extern int  func_021B8B48(void *c, u32_021BA9EC v, u32_021BA9EC k);
extern u32_021BA9EC func_021B77B4(int unused, void *p);
extern void WIPE_SYS_Start(void *p1, u32_021BA9EC p2, u32_021BA9EC p3, u32_021BA9EC p4, u32_021BA9EC p5, u32_021BA9EC p6, u32_021BA9EC p7);
extern u32_021BA9EC  WIPE_SYS_EndCheck(void);
extern int TOUCHPANEL_GetTrg(void);
extern u32_021BA9EC  KEY_GetTrg(void);
extern u32_021BA9EC PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32_021BA9EC a);
extern void GFL_USE_PlaySeDefaultVolume(u32_021BA9EC id);
extern s32 func_02061CA4(void *p, u32_021BA9EC a, u32_021BA9EC b, s32 size);
extern u32_021BAE58 CLACT_IsActorAnimActive(struct Actor *);
extern u16 CLACT_GetActorAnimSeq(struct Obj *);
extern void CLACT_SetActorAnimSeq(struct Obj *, u16);
extern int TOUCHPANEL_HitTrg(const void *p);
extern u32_021BAEE0 CLACT_GetActorDrawEnable(struct Obj *p);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32_021BAEE0 which);
extern u32_021BB288 TOUCHPANEL_GetPointTrg(u32_021BB288 *outA, u32_021BB288 *outB);
extern int TOUCHPANEL_GetCont(void);
extern int func_021B8BB8(int a, unsigned char *p, int *out);
extern void func_021B6E88(char *p, void *q);
extern void func_021B8BFC(int unused, u8 *p);
extern void *func_0207E008(void);
extern u32_021BB288 func_0207E100(void);
extern u32_021BB288 TOUCHPANEL_GetPointCont(u32_021BB288 *outA, u32_021BB288 *outB);
extern void func_02041EE4(u32_021BB4D0, u32_021BB4D0, u32_021BB4D0);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32_021BB54C value);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern u32_021BB8F4 func_021B80E4(int unused, char *p);
extern u32_021BBA94 func_02049658(void *a, u32_021BBA94 b, u32_021BBA94 c, u32_021BBA94 d, u32_021BBA94 e, u32_021BBA94 f, u16 g);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void func_021B7B64(int x, char *p);
extern void func_021B80DC(int unused, char *p, u32_021BBF2C v);
extern void func_021B80EC(int unused, char *p, const u8 *src);
extern u8 *func_021B8B7C(void *c, u8 *x);
extern void func_021B8C14(void *c, u8 *x);
extern u32_021BBF2C func_021B8C20(void *c, u8 *x);
extern u32_021BBF2C APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern void GFL_USE_StopAllSe(void);
extern void GFL_USE_PlaySeInSlot(void *arg, int i);
extern u32_021BC5E8 APP_TASKMENU_WIN_IsTouch(void **p);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern int func_021B8108(void *unused, void *p);
extern u32_021BC7FC GFL_NET_GetScanResult(u32_021BC7FC a);
extern void *GFL_NET_GetScanResultMac(u32_021BC7FC a);
extern u8 NET_WHPIPE_GetEntryBeaconKind(int i);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32_021BC7FC func_02008530(const struct Sub0200852CObj *obj);
extern void func_02087C6C(void *p);
extern int func_021B85D0(unsigned char *p, unsigned char *q);
extern u32_021BC7FC ZONEDATA_IsZone117(u32_021BC7FC id);
extern u32_021BC7FC ZONEDATA_IsZoneGroup118To120(u32_021BC7FC id);
extern void func_02082D44(const void *src, void *dst, u32_021BC7FC n);
extern struct WordSet *func_0201EC64(u32_021BCC40 heap);
extern struct U16Vec *STRBUF_Create(u32_021BCC40 capacity, u32_021BCC40 heapId);
extern u16 *COMM_PLAYER_SUPPORT_GetRecordFieldPtr(void *p);
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, unsigned int len);
extern u16 COMM_PLAYER_SUPPORT_GetRecordField(void *p);
extern void func_0201EFA4(struct WordSet *p, u32_021BCC40 i, u32_021BCC40 a, u32_021BCC40 b, u32_021BCC40 c, u32_021BCC40 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32_021BCC40 func_0201ED04(struct WordSet *p);
extern u32_021BCEF8 APP_TASKMENU_WIN_Create(u32_021BCEF8 a0, u32_021BCEF8 a1, u32_021BCEF8 a2, u32_021BCEF8 a3, u8 a4, u16 a5);
extern u32_021BD0A4 func_0201283C(const struct BigObj *p);
extern int func_02009D50(struct Sub020097BCObj *obj, const void *unused, u32_021BD0A4 id, u32_021BD0A4 kind, u32_021BD0A4 *out);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32_021BD1AC a2, u32_021BD1AC a3, u16 heap);
extern char *func_021B6EE0(void *a, u16 b);
extern char *func_021B7BA8(void *p, u16 heap);
extern char *func_021B8C3C(char *unused, u16 heap);
extern u32_021BD1AC func_021B6BE0(Params *);
extern u32_021BD1AC func_020056A0(void (*)(int, char *), char *, int);
extern int func_0202EB14(void);
extern u32_021BD1AC func_02012A30(const struct BigObj *p);
extern void func_02028A70(struct SoundSys *sys);
extern void GFL_USE_CancelChangeAndPlayBgm(u32_021BD1AC, u32_021BD1AC);
extern void func_02030EAC(struct Node *n);
extern void func_021B6C34(char *);
extern void func_021B8CB0(void *, char *);
extern void func_021B7DCC(void *p, char *q);
extern void func_021B70A8(int unused, char *q);
extern u32_021BD3B8 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void func_021B7E34(void *p, char *q);
extern u32_021BD43C func_021B9044(void *p, struct S *s);
extern u32_021BD43C func_021B80CC(int unused, char *p);
extern void func_021B6C48(u32_021BD43C a);
extern void func_021B712C(int unused, char *q);
extern void CLACT_DrawSystem(void);
extern u32_021BD43C PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void TCBL_Main(struct Tcbl *p);
extern u32_021BD43C  func_02005728(u32_021BD43C v);
extern void sub_02040618(u32_021BD43C layer, u32_021BD43C a, u32_021BD43C b);
extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32_021BD43C a, u32_021BD43C b, s32 size);
extern void func_021B71B8(void *p, struct Q *q);
extern void CLACT_VBlankSystem(void);
extern void func_021B6C4C(char *p);
extern void func_021B9574(int unused, char *p);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 b);
extern u32 WIPE_ResetWndMask(void *win);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203F8F4(u16 heap);
extern void BMP_WIN_Init(u16 heap);
extern void func_0203FC28(struct DispConfig *cfg);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32 a, u32 b);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(u32 p);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u32 which);
extern u8 *func_02012944(void *p);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *PRINTSYS_QUE_CreateEx(u16 n, u32 heap);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201DD68(void);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void TIME_ICON_Delete(u8 *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_021B8FB8(void *,char *);
extern void func_021B8CC8(void *,char *);
extern u32 func_021B8BA4(int unused, char *base, int i);
extern u32 func_021B8B8C(int unused, char *base, int i);
extern u32 func_021B7B30(int unused, char *base, int i);
extern char *func_021B8B94(int unused, char *base, int i);
extern u8 func_021B8B68(int unused, char *p);
extern void *func_02008510(void *a, int tag);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern int func_021B9F98(int unused, int *p);
extern void func_021B8720(void *a0, u32 *a1, u32 a2);
extern u32_021BE100 sub_0202EB0C(void);
extern int unit_0202EB14(void);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200ED48(void *p);
extern void func_0200ED54(struct L0200ED54 *l, u32_021BE2F0 val);
extern u8 *TIME_ICON_CreateNode(u32_021BE318 a, void *b, u8 c, u8 d, u16 e);
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32_021BE364 size, u32_021BE364 heap);
extern void *GAME_DATA_Create(u16 heap);
extern unsigned int KEY_GetCont(void);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int h);
extern u32_021BE43C func_0200FB24(void);
extern void GFL_NET_ERR_RequestScreen(void);
int func_021BA174(int unused, void *a, void *buf, unsigned n);
int func_021BA194(int unused, int a, void *buf, unsigned n);
void func_021BA1B4(char *p, u32_021BA1B4 a1);
void func_021BA1D8(void *p);
void func_021BA1E4(void *a0);
int func_021BA1E8(int *self, char *buf, unsigned n, int vol, int freq);
void func_021BA234(void *p);
u32_021BA244 func_021BA244(void *p);
int func_021BA248(void *p);
int func_021BA24C(void *p);
int func_021BA254(void *p);
int func_021BA270(void *p);
char *func_021BA280(void *a, u16 b);
void func_021BA2B8(int unused, int v);
void func_021BA2C4(void *a0, u8 *p);
void func_021BA8C4(u16 *a0, char *p);
int func_021BA9EC(void *a0, char *p);
void func_021BAE58(void *p, u8 *q);
void func_021BAEE0(void *ctx, u8 *p);
void func_021BB288(void *ctx, u8 *p);
void func_021BB4D0(void *unused, u8 *q);
void func_021BB54C(void *ctx, u8 *p);
void func_021BB65C(void *ctx, u8 *p, int k);
int func_021BB8F4(void *a0, int *out);
void func_021BB938(void *p, u8 *q, int id);
void func_021BB9E4(void *a0, char *a1);
void *func_021BBA6C(int unused, void *p);
void func_021BBA88(int unused, int v);
void func_021BBA94(void *a0, u8 *p);
void func_021BBE5C(void *a0, char *a1);
int func_021BBF2C(void *a0, char *p);
void func_021BC5E8(void *ctx, u8 *list);
void func_021BC7FC(void *ctx, u8 *list);
void func_021BCB88(void *ctx, char *list);
void func_021BCC40(void *ctx, char *list, char *row, int idx);
void func_021BCE2C(void *ctx, char *list, char *cur, u8 idx);
void func_021BCEF8(void *ctx, u8 *st);
void func_021BD038(void *ctx, char *st);
int func_021BD0A4(void *ctx, u32_021BD0A4 unused, u32_021BD0A4 a, u32_021BD0A4 b, u32_021BD0A4 c);
void func_021BD0C4(void *a0, char *a1, int a2);
void func_021BD134(void *ctx, char *st, u32_021BD134 msgId);
void func_021BD1AC(char *self);
void func_021BD3B8(u8 *p);
int func_021BD43C(char *ctx);
void func_021BD5AC(int unused, char *ctx);
void func_021BD5D8(u8 *p);
void func_021BD7D0(void *a0);
void func_021BD820(const struct BgTemplate *tmpl, u32 bgId, u32 type);
void func_021BD844(u8 *p);
void func_021BDB5C(u8 *p);
void func_021BDBC4(u8 *p);
void func_021BDC70(u32 *a0);
void func_021BDCB8(u8 *p);
void func_021BDD6C(u8 *p);
void func_021BDEF0(u8 *p, char *a, u32 b);
u32 func_021BDFDC(void *p);
u32 func_021BDFE4(void *p);
int func_021BDFEC(void *p);
u32 func_021BDFFC(void *p);
u32 func_021BE004(void *p);
u16 func_021BE00C(u16 *p);
u32 func_021BE010(void *p);
u32 func_021BE018(void *p, int i);
u32 func_021BE024(void *p);
u32 func_021BE02C(void *p);
void func_021BE030(void *p, u32 v);
u32_021BCC40 func_021BE034(void *p);
u32_021BCC40 func_021BE03C(void *p);
u32_021BCC40 func_021BE044(void *p);
u32 func_021BE04C(void *p);
u8 func_021BE054(void *p);
void func_021BE058(void *p, u32 v);
int func_021BE05C(void *p);
u32 func_021BE078(void *p);
void func_021BE07C(u32 *p, u32 v);
void func_021BE08C(void *p);
void func_021BE0A0(void *p, u32 v);
u32 func_021BE0A4(void *p);
void func_021BE0A8(void *p, u32_021BE0A8 v);
u32_021BE0AC func_021BE0AC(void *p);
void func_021BE0B0(void *p, u32_021BE0B0 v);
u32_021BE0B4 func_021BE0B4(void *p);
void func_021BE0B8(void *p);
u32_021BE0C8 func_021BE0C8(void *p);
void func_021BE0CC(void *p, u32_021BE0CC v);
u32_021BE0D0 func_021BE0D0(void *p);
void func_021BE0D4(void *p, u32_021BE0D4 v);
int func_021BE0D8(void *p);
u32_021BE0EC func_021BE0EC(void *p);
void func_021BE0F0(u8 *c);
u32_021BE0F8 func_021BE0F8(void *p);
void func_021BE0FC(void *p, u32_021BE0FC v);
int func_021BE100(void);
u32_021BE11C func_021BE11C(u8 *p);
void func_021BE1A4(char *p);
void func_021BE1E4(u8 *p);
void func_021BE210(char *a, u8 idx);
void func_021BE2E0(void *p);
void func_021BE2F0(u32_021BE2F0 *p, void *q);
void func_021BE318(char *a0, void *a1);
void func_021BE34C(void *p);
int func_021BE364(struct Obj0203159C *obj,int unused,u8 *arg);
int func_021BE410(void *a, void *b, int c, u32_021BE410 *p);
int func_021BE43C(void *a, void *b, void *c, u32_021BE43C *p);
extern s16 FX_SinCosTable_[];
extern const u8 d_021C6FF8[];
extern const u8 d_021C7014[];
extern const u32_021BAEE0 d_021C6FBC[];
extern const struct SpritePos d_021C7030;
extern const u8 d_021C6FDC[];
extern const u32_021BAEE0 d_021C6FC8[];
extern const struct SpritePos d_021C7034;
extern const struct SpritePos d_021C7038;
extern const struct SpritePos d_021C703C;
extern const u8 d_021C6FB2[];
extern const u8 d_021C6FB4[];
extern const u8 d_021C6FB6[];
extern const u8 d_021C6FB8[];
extern u32_021BBA6C g_021C7234[];
extern u8 d_021C7234[];
extern const u8 d_021C7040[];
extern s16 FX_SinCosTable_[];
extern const Cfg7 gClActorInitParam;
extern u8 d_021C7050[];
extern u8 d_021C7060[];
extern u8 d_021C7080[];
extern u8 d_021C70A0[];
extern u8 d_021C70C0[];
extern u8 d_021C70E0[];
extern u8 d_021C7100[];
extern u8 d_021C7120[];
extern const struct Q d_021C7048;
extern const struct Q d_021C704C;
extern u8 d_021C724C[];




/*
 * Zero-fills a byte buffer, then runs func_021B6A00 over it.
 *
 * Addresses are Black-image addresses.
 */
int func_021BA174(int unused, void *a, void *buf, unsigned n)
{
    MI_CpuFill8(buf, 0, n);
    return func_021B6A00(a, n, buf);
}




int func_021BA194(int unused, int a, void *buf, unsigned n)
{
    func_02082A7C(0, buf, n << 2);
    return func_021B6A18(a, (int)n, (int)buf);
}




void func_021BA1B4(char *p, u32_021BA1B4 a1)
{
    u32_021BA1B4 v = NNS_SndWaveOutAllocChannel(7);

    ((struct Obj05447 *)p)->f20 = v;
    if (v == 0) {
        func_02034714((void *)0x021C7224, 0, (void *)0x021C7224);
    }
    ((struct Obj05447 *)p)->fC = 0;
}




void func_021BA1D8(void *p)
{
    func_02072A88((u32_021BA1D8 *)((struct Obj24096 *)p)->f20);
}




void func_021BA1E4(void *a0)
{
}




/*
 * Starts a sample on the channel at +0x20 when n > 0x20; records the handle and span.
 *
 * Addresses are Black-image addresses.
 */
int func_021BA1E8(int *self, char *buf, unsigned n, int vol, int freq)
{
    if (n > 0x20) {
        int r = func_02072AA0((void *)self[8], 1, buf + 0x800, 0, 0, (int)(n >> 1), 0x1FF4, vol, freq, 0x40);
        self[3] = r;
        self[5] = 0;
        self[6] = (int)n;
        self[7] = freq;
        return r;
    }
    return 0;
}



void func_021BA234(void *p)
{
    ((struct Obj04555 *)p)->fC = 0;
    func_02072BDC(*(Slot02072BDC * *)&((struct Obj04555 *)p)->f20);
}




u32_021BA244 func_021BA244(void *p)
{
    return ((struct Obj24097 *)p)->fC;
}




int func_021BA248(void *p)
{
    return ((struct Obj24098 *)p)->f18;
}




int func_021BA24C(void *p)
{
    return (u16)((struct Obj24099 *)p)->f14;
}




int func_021BA254(void *p)
{
    return (u16)func_0209C2B0(((struct Obj14306 *)p)->f18 << 15,
                              ((struct Obj14306 *)p)->f1C * 0x10e);
}




/*
 * Test the byte at +0x10 against 0xb4, unsigned.
 *
 * Addresses are Black-image addresses.
 */
int func_021BA270(void *p)
{
    if (((struct Obj24100 *)p)->f10 >= 0xb4) {
        return 1;
    }
    return 0;
}




/*
 * Allocates the 0x98-byte record and seeds its counters.
 *
 * Addresses are Black-image addresses.
 */
char *func_021BA280(void *a, u16 b)
{
    char *v = func_02030734(b, 0x98, 1, (void *)0x021C7228, 0xcf);

    v[0x36] = 0;
    v[0x37] = 3;
    ((struct Obj06562 *)v)->f28 = 0;
    ((struct Obj06562 *)v)->f24 = 0;
    ((struct Obj06562 *)v)->f34 = 0x8000;
    return v;
}




void func_021BA2B8(int unused, int v)
{
    func_020307B0((void *)v);
}




/*
 * Scene constructor: loads the bank, builds fifteen sprite/button objects
 * from one descriptor, opens the text window and clears the state words.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA2C4(void *a0, u8 *p)
{
    struct Desc d;
    u16 v;
    u8 i;
    void *bank;
    void *s;
    u32_021BA2C4 t1;
    u32_021BA2C4 t3;

    v = func_021BE00C(a0);
    func_020498F4((void *)func_021BE010(a0), 0x10, 7, 0, 0, 0, v);
    func_020409B4(7);
    func_02040588(5, 0);
    {
        u32_021BA2C4 t = *(volatile u16 *)0x04000304;
        *(volatile u16 *)0x04000304 = t & 0xFFFF7FFF;
    }
    bank = func_020490F4(func_020275E4(), v);
    func_020414EC(0);
    func_02049990(bank, func_0202762C(), 0, 0x60, 0, 0x600, 0, v);
    func_020413B0(0, 0, 0x15, 0x20, 3, 0);
    func_020409B4(0);
    func_02040618(0, 3, 0);
    ARC_TOOL_DeleteHandle(bank);
    d.x = 0x10;
    d.y = 0xcc;
    d.z = 1;
    d.a = 8;
    d.b = 0;
    ((struct Obj00276 *)p)->f58 = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0x38;
    d.z = 0x3;
    ((struct Obj00276 *)p)->f5C = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0x60;
    d.z = 0x5;
    ((struct Obj00276 *)p)->f60 = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0x88;
    d.z = 0x7;
    ((struct Obj00276 *)p)->f64 = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0xc8;
    if (func_021BE0B4(a0) == 1) {
        d.z = 0xc;
    } else {
        d.z = 0xa;
    }
    ((struct Obj00276 *)p)->f68 = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0xe0;
    d.y = 0xc0;
    d.z = 0x1;
    ((struct Obj00276 *)p)->f6C = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 7), func_021BE018(a0, 3), func_021BE018(a0, 10), &d, 0, v);
    CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00276 *)p)->f6C, 1);
    for (i = 0; i < 6; i++) {
        CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BA2C4 *)(p + i * 4 + 0x58), 1);
    }
    d.x = 0x38;
    d.y = 0x48;
    d.z = 0xe;
    ((struct Obj00276 *)p)->f70 = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.y = 0x5c;
    d.z = 0xf;
    ((struct Obj00276 *)p)->f74 = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.y = 0x70;
    d.z = 0x10;
    ((struct Obj00276 *)p)->f78 = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.y = 0x84;
    d.z = 0x11;
    ((struct Obj00276 *)p)->f7C = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.x = 0x2c;
    d.y = 0x8c;
    d.z = 0x1;
    ((struct Obj00276 *)p)->f80 = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 6), func_021BE018(a0, 2), func_021BE018(a0, 10), &d, 1, v);
    for (i = 0; i < 5; i++) {
        CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BA2C4 *)(p + i * 4 + 0x70), 0);
    }
    d.x = 0x10;
    d.y = 0xa0;
    d.z = 0xf;
    ((struct Obj00276 *)p)->f84 = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00276 *)p)->f84, 0);
    d.x = 0x88;
    d.y = 0xa0;
    d.z = 0x10;
    ((struct Obj00276 *)p)->f88 = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00276 *)p)->f88, 0);
    d.a = 0;
    ((struct Obj00276 *)p)->f8C = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00276 *)p)->f8C, 0);
    d.z = 0x19;
    d.a = 2;
    ((struct Obj00276 *)p)->f90 = (u32_021BA2C4)CLACT_CreateActor((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00276 *)p)->f90, 0);
    func_021BB54C(a0, p);
    ((struct Obj00276 *)p)->f48 = 0;
    ((struct Obj00276 *)p)->f50 = 0;
    t1 = func_021BE034(a0);
    s = (void *)func_021BE03C(a0);
    t3 = func_021BE044(a0);
    *(u32_021BA2C4 *)&((struct Obj00276 *)p)->f4C = (u32_021BA2C4)BMP_WIN_Create(4, 3, 1, 0x1c, 2, 0xa, 1);
    BMP_Clear((struct CharBuf *)((u32_021BA2C4)BMP_WIN_GetBmp(((struct Obj00276 *)p)->f4C)), 0);
    s = func_02045EC0(s, 0xb);
    PRINTSYS_PrintQueColor((void *)t3, BMP_WIN_GetBmp(((struct Obj00276 *)p)->f4C), 1, 0, s, t1, 0x440);
    STRBUF_Delete(s);
    ((struct Obj00276 *)p)->f40 = 1;
    ((struct Obj00276 *)p)->f0 = 0;
    p[4] = 0x18;
    p[5] = 0x18;
    ((struct Obj00276 *)p)->f96 = 0;
    ((struct Obj00276 *)p)->fC = 0;
    ((struct Obj00276 *)p)->f8 = 0;
    ((struct Obj00276 *)p)->f10 = 0;
    ((struct Obj00276 *)p)->f14 = 0;
    ((struct Obj00276 *)p)->f38 = 0;
    ((struct Obj00276 *)p)->f44 = 0;
    ((struct Obj00276 *)p)->f18 = 0;
    ((struct Obj00276 *)p)->f1C = 0;
    ((struct Obj00276 *)p)->f20 = 0;
    *(volatile u16 *)0x0500021A = ((struct Obj00276 *)p)->f34 & 0x7fff;
    func_021BB65C(a0, p, 0);
    GFL_NET_RestartWithDefaultTimeout(1, v);
    func_021BE2E0(a0);
}




void func_021BA8C4(u16 *a0, char *p)
{
    u32_021BA8C4 r;
    u8 i;
    u16 v;

    v = func_021BE00C(a0);
    if (((struct Obj01265 *)p)->f28 == 1) {
        ((struct Obj01265 *)p)->f28 = (((struct Obj01265 *)p)->f24 == 0) ? 0 : 3;
    }
    r = 0;
    GFL_NET_RestartWithDefaultTimeout(0, v);
    func_0201F7A8((void *)(((struct Obj01265 *)p)->f48), 0);
    r = ((struct Obj01265 *)p)->f48;
    BMP_WIN_ClearScreen((struct Descriptor *)r);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)r));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj01265 *)p)->f48));
    r = ((struct Obj01265 *)p)->f4C;
    BMP_WIN_ClearScreen((struct Descriptor *)r);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)r));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj01265 *)p)->f4C));
    r = ((struct Obj01265 *)p)->f50;
    if (r != 0) {
        BMP_WIN_ClearScreen((struct Descriptor *)r);
        func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)r));
        BMP_WIN_Delete((struct Descriptor *)(((struct Obj01265 *)p)->f50));
        ((struct Obj01265 *)p)->f50 = 0;
    }
    for (i = 0; i < 5; i++) {
        CLACT_DeleteActor((struct Obj *)(*(u32_021BA8C4 *)(p + i * 4 + 0x70)));
    }
    for (i = 0; i < 6; i++) {
        CLACT_DeleteActor((struct Obj *)(*(u32_021BA8C4 *)(p + i * 4 + 0x58)));
    }
    CLACT_DeleteActor((struct Obj *)(((struct Obj01265 *)p)->f90));
    CLACT_DeleteActor((struct Obj *)(((struct Obj01265 *)p)->f8C));
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01265 *)p)->f88, 0);
    CLACT_DeleteActor((struct Obj *)(((struct Obj01265 *)p)->f88));
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01265 *)p)->f84, 0);
    CLACT_DeleteActor((struct Obj *)(((struct Obj01265 *)p)->f84));
    func_020414EC(0);
    func_020409B4(0);
    func_02040618(0, 3, 0);
    func_020414EC(6);
    func_020409B4(6);
    func_02040588(5, 1);
    *(volatile u16 *)0x04000304 |= 0x8000;
    func_021BE1A4((char *)a0);
}




/*
 * 2026-10-02 (lane C1-04): byte-correct; one relocation wildcarded.
 * is `ldr r0, [r0, #0x10]; bx lr`, 021BE030 is the paired setter
 * `str r1, [r0, #0x10]; bx lr`; both missing from the layout, a figure
 * move). The only other file for that address is ov203's unrelated function.
 * The +0x96 wrap-around reload is a volatile read in the else arm.
 *
 * Scene state machine, one switch on the state word at +0, then the
 * per-frame tail (window release checks, key handling, colour fade).
 *
 * Addresses are Black-image addresses.
 */
int func_021BA9EC(void *a0, char *p)
{
    u32_021BA9EC v;
    u32_021BA9EC flag;
    u32_021BA9EC z;
    u8 i;
    u32_021BA9EC t;
    u32_021BA9EC s;
    u32_021BA9EC k;

    v = func_021BE00C(a0);
    z = 0;
    ((struct Obj00140 *)p)->f8 = z;
    switch (((struct Obj00140 *)p)->f0) {
    case 0:
        if (func_021BE02C(a0) == 1) {
            WIPE_SYS_Start((void *)z, 1, 1, z, 6, 1, v);
        } else {
            WIPE_SYS_Start((void *)4, 1, 1, z, 6, 1, v);
        }
        ((struct Obj00140 *)p)->f0 = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            ((struct Obj00140 *)p)->f18 = 1;
            ((struct Obj00140 *)p)->f0 = 4;
        }
        break;
    case 2:
        t = func_021BDFDC(a0);
        if (((struct Obj00140 *)p)->f20 != 0) {
            if (func_021B7590((int)a0, (char *)t) != 1) {
                break;
            }
        }
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, v);
        ((struct Obj00140 *)p)->f0 = 3;
        ((struct Obj00140 *)p)->f18 = 0;
        break;
    case 3:
        if (WIPE_SYS_EndCheck() == 1) {
            if (((struct Obj00140 *)p)->f1C == 0) {
                return 1;
            }
            return 4;
        }
        break;
    case 4:
        if (func_021BB8F4(a0, (int *)p) == 0) {
            func_021BAE58(a0, (u8 *)p);
        }
        break;
    case 5:
        if (func_021BB8F4(a0, (int *)p) == 0) {
            func_021BAEE0(a0, (u8 *)p);
        }
        break;
    case 6:
        func_021B8084(a0, (char *)func_021BDFE4(a0));
        func_021BB938(a0, (u8 *)p, 0x24);
        flag = 1;
        func_021BE0B0(a0, 1);
        ((struct Obj00140 *)p)->f0 = 7;
        func_021B7B80((int)a0, (char *)func_021BDFDC(a0));
        ((struct Obj00140 *)p)->f20 = flag;
        break;
    case 7:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0) {
            ((struct Obj00140 *)p)->f1C = flag = 1;
            ((struct Obj00140 *)p)->f0 = 2;
            func_021BE0B0(a0, 1);
            func_021B7578((int)a0, (char *)func_021BDFDC(a0));
            ((struct Obj00140 *)p)->f20 = flag;
        }
        break;
    case 8:
        if (func_021B8740((int)a0, func_021BDFE4(a0), 10, z) == 1) {
            ((struct Obj00140 *)p)->f0 = 9;
        }
        break;
    case 9:
        func_021B8084(a0, (char *)func_021BDFE4(a0));
        func_021BB938(a0, (u8 *)p, 0x25);
        flag = 1;
        func_021BE0B0(a0, 1);
        ((struct Obj00140 *)p)->f0 = 10;
        ((struct Obj00140 *)p)->f54 = z;
        func_021B7B80((int)a0, (char *)func_021BDFDC(a0));
        ((struct Obj00140 *)p)->f20 = flag;
        break;
    case 10:
        ((struct Obj00140 *)p)->f54 = ((struct Obj00140 *)p)->f54 + 1;
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0
            || ((struct Obj00140 *)p)->f54 >= 300) {
            ((struct Obj00140 *)p)->f0 = 11;
        }
        break;
    case 11:
        func_021B8B34(a0, func_021BDFE4(a0), 0x2f);
        ((struct Obj00140 *)p)->f0 = 12;
        break;
    case 12:
        if (func_021B8B48(a0, func_021BDFE4(a0), 0x2f) == 1) {
            ((struct Obj00140 *)p)->f1C = flag = 1;
            ((struct Obj00140 *)p)->f0 = 2;
            func_021BE0B0(a0, 1);
            func_021B7578((int)a0, (char *)func_021BDFDC(a0));
            ((struct Obj00140 *)p)->f20 = flag;
        }
        break;
    case 13:
        func_021B8084(a0, (char *)func_021BDFE4(a0));
        func_021BB938(a0, (u8 *)p, 0x26);
        flag = 1;
        func_021BE0B0(a0, 1);
        ((struct Obj00140 *)p)->f0 = 14;
        func_021B7B80((int)a0, (char *)func_021BDFDC(a0));
        ((struct Obj00140 *)p)->f20 = flag;
        break;
    case 14:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0) {
            ((struct Obj00140 *)p)->f1C = flag = 1;
            ((struct Obj00140 *)p)->f0 = 2;
            func_021BE0B0(a0, 1);
            func_021B7578((int)a0, (char *)func_021BDFDC(a0));
            ((struct Obj00140 *)p)->f20 = flag;
        }
        break;
    }
    func_021BB4D0(a0, (u8 *)p);
    if (((struct Obj00140 *)p)->f18 == 1) {
        func_021BB288(a0, (u8 *)p);
    }
    if (((struct Obj00140 *)p)->f38 == 1) {
        t = func_021BE044(a0);
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)t, (void *)((u32_021BA9EC)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00140 *)p)->f48))) == 0) {
            func_0201F73C((void *)(((struct Obj00140 *)p)->f48), 2, 0x140, 9);
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00140 *)p)->f48);
            BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj00140 *)p)->f48));
            func_02041B6C(4);
            i = 0;
            ((struct Obj00140 *)p)->f38 = 0;
            if (((struct Obj00140 *)p)->f3C == 1) {
                k = 1;
                for (i = 0; i < 5; i++) {
                    CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BA9EC *)(p + i * 4 + 0x70), k);
                }
            } else {
                k = i;
                for (i = 0; i < 5; i++) {
                    CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BA9EC *)(p + i * 4 + 0x70), k);
                }
            }
        }
    }
    if (((struct Obj00140 *)p)->f40 == 1) {
        t = func_021BE044(a0);
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)t, (void *)((u32_021BA9EC)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00140 *)p)->f4C))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00140 *)p)->f4C);
            BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj00140 *)p)->f4C));
            func_020409B4(4);
            ((struct Obj00140 *)p)->f40 = 0;
        }
    }
    if (((struct Obj00140 *)p)->f44 == 1 && ((struct Obj00140 *)p)->f50 != 0) {
        t = func_021BE044(a0);
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)t, (void *)((u32_021BA9EC)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00140 *)p)->f50))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00140 *)p)->f50);
            BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj00140 *)p)->f50));
            func_020409B4(0);
            ((struct Obj00140 *)p)->f44 = 0;
        }
    }
    if (*(s32 *)&((struct Obj00140 *)p)->f0 <= 5 && func_021BE0B4(a0) == 0) {
        v = func_021BDFDC(a0);
        if (KEY_GetTrg() & 0x40) {
            func_021B7B3C((int)a0, v, 0);
        }
        if (KEY_GetTrg() & 0x10) {
            func_021B7B3C((int)a0, v, 5);
        }
        if (KEY_GetTrg() & 0x80) {
            func_021B7B3C((int)a0, v, 1);
        }
        if (KEY_GetTrg() & 0x20) {
            func_021B7B3C((int)a0, v, 3);
        }
    }
    if (func_021BE0A4(a0) == 0 && (KEY_GetTrg() & 0x200)) {
        if (func_021B77B4((int)a0, (void *)func_021BDFDC(a0)) == 0) {
            func_021BE08C(a0);
            GFL_USE_PlaySeDefaultVolume(0x66C);
        }
    }
    t = *(volatile u16 *)&((struct Obj00140 *)p)->f96;
    ((struct Obj00140 *)p)->f96 = ((s32)(t + 0x400) >= 0x10000) ? t - 0xFC00 : *(volatile u16 *)&((struct Obj00140 *)p)->f96 + 0x400;
    s = FX_SinCosTable_[(((struct Obj00140 *)p)->f96 >> 4) * 2 + 1];
    s = (s16)((s32)(s + 0x1000) / 2);
    s = (u8)(((s32)s * -9 >> 12) + 0x1c);
    ((struct Obj00140 *)p)->f94 = s | (s << 5) | (s << 10);
    func_02061CA4((void *)0xe, 0xde, (u32_021BA9EC)(p + 0x94), 2);
    return 3;
}



void func_021BAE58(void *p, u8 *q)
{
    if ((KEY_GetTrg() & 1024) && ((struct Obj00024 *)q)->f38 == 0) {
        if (CLACT_IsActorAnimActive(*(struct Actor * *)&((struct Obj00024 *)q)->f6C) == 0 ||
            CLACT_GetActorAnimSeq(*(struct Obj * *)&((struct Obj00024 *)q)->f6C) == 1) {
            *(u32_021BAE58 *)&((struct Obj00024 *)q)->f0 = 5;
            q[4] = 0;
            func_021BB65C(p, q, 1);
            CLACT_SetActorAnimSeq(*(struct Obj * *)&((struct Obj00024 *)q)->f6C, 1);
            GFL_USE_PlaySeDefaultVolume(1644);
        }
    } else if (KEY_GetTrg() & 2) {
        *(u32_021BAE58 *)&((struct Obj00024 *)q)->f0 = 2;
        GFL_USE_PlaySeDefaultVolume(1361);
    }
    if (KEY_GetTrg() & 12) {
        func_021BE0B8(p);
        func_021BB54C(p, q);
        GFL_USE_PlaySeDefaultVolume(1647);
    }
}




void func_021BAEE0(void *ctx, u8 *p)
{
    struct SpritePos pa;
    struct SpritePos pb;
    struct SpritePos pc;
    struct SpritePos pd;
    int k;
    int j;

    k = TOUCHPANEL_HitTrg(d_021C6FF8);
    if (k == 0 && CLACT_GetActorDrawEnable(((struct Obj00024 *)p)->f8C) == 0) {
        ((struct Obj00024 *)p)->f28 = 0;
        ((struct Obj00024 *)p)->f24 = 0;
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        ((struct Obj00024 *)p)->f10 = 1;
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f84, 1);
        CLACT_SetActorAutoAnim(((struct Obj00024 *)p)->f84, 1);
        GFL_USE_PlaySeDefaultVolume(0x66c);
    }
    if (k == 1) {
        ((struct Obj00024 *)p)->f28 = 1;
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        GFL_USE_PlaySeDefaultVolume(0x66c);
    }
    if (k == 2) {
        ((struct Obj00024 *)p)->f28 = 2;
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        GFL_USE_PlaySeDefaultVolume(0x66c);
    }
    if (k == 3 && CLACT_GetActorDrawEnable(((struct Obj00024 *)p)->f8C) == 0) {
        ((struct Obj00024 *)p)->f28 = 3;
        ((struct Obj00024 *)p)->f24 = 1;
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        ((struct Obj00024 *)p)->f14 = 1;
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f88, 1);
        CLACT_SetActorAutoAnim(((struct Obj00024 *)p)->f88, 1);
        GFL_USE_PlaySeDefaultVolume(0x66c);
    }
    if (k == 4) {
        func_021BE0B8(ctx);
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        GFL_USE_PlaySeDefaultVolume(0x66f);
    }
    if (((struct Obj00024 *)p)->f10 == 1) {
        j = TOUCHPANEL_HitTrg(d_021C7014);
        if (j != -1) {
            p[0x36] = d_021C6FBC[j];
            ((struct Obj00024 *)p)->f8 = 1;
            pa = d_021C7030;
            CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f8C, 1);
            CLACT_RestartActorAnim(((struct Obj00024 *)p)->f8C);
            CLACT_SetActorAutoAnim(((struct Obj00024 *)p)->f8C, 1);
            CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f8C, (u16)(j + 0x11));
            CLACT_AddActorSurfacePos(((struct Obj00024 *)p)->f8C, (const struct Vec2 *)(&pa), 0);
            CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f90, 0);
            GFL_USE_PlaySeDefaultVolume(0x66c);
        }
    }
    if (((struct Obj00024 *)p)->f14 == 1) {
        j = TOUCHPANEL_HitTrg(d_021C6FDC);
        if (j != -1) {
            p[0x37] = d_021C6FC8[j];
            ((struct Obj00024 *)p)->f8 = 1;
            GFL_USE_PlaySeDefaultVolume(0x66c);
            pb = d_021C7034;
            CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f8C, 1);
            CLACT_RestartActorAnim(((struct Obj00024 *)p)->f8C);
            CLACT_SetActorAutoAnim(((struct Obj00024 *)p)->f8C, 1);
            CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f8C, (u16)(j + 0x14));
            CLACT_AddActorSurfacePos(((struct Obj00024 *)p)->f8C, (const struct Vec2 *)(&pb), 0);
            CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f90, 0);
        }
    }
    if ((KEY_GetTrg() & 0x400) || (KEY_GetTrg() & 2) || k == 5) {
        if (*(int *)&((struct Obj00024 *)p)->f38 == 0) {
            ((struct Obj00024 *)p)->f0 = 4;
            p[4] = 0x18;
            ((struct Obj00024 *)p)->f8 = 1;
            func_021BB65C(ctx, p, 0);
            func_021BB9E4(ctx, (char *)p);
            GFL_USE_PlaySeDefaultVolume(0x551);
            CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f6C, 9);
        }
    }
    if (KEY_GetTrg() & 0xc) {
        func_021BE0B8(ctx);
        func_021BB54C(ctx, p);
        GFL_USE_PlaySeDefaultVolume(0x66f);
    }
    if (CLACT_GetActorDrawEnable(((struct Obj00024 *)p)->f8C) == 1 && CLACT_IsActorAnimActive(((struct Obj00024 *)p)->f8C) == 0) {
        func_021BB9E4(ctx, (char *)p);
    }
    if (((struct Obj00024 *)p)->f10 == 1 && CLACT_IsActorAnimActive(((struct Obj00024 *)p)->f84) == 0 && CLACT_GetActorDrawEnable(((struct Obj00024 *)p)->f90) == 0) {
        pc = d_021C7038;
        switch (p[0x36]) {
        case 1:
            pc.x = pc.x + 0x10;
            break;
        case 0:
            pc.x = pc.x + 0x20;
            break;
        case 2:
            break;
        }
        CLACT_AddActorSurfacePos(((struct Obj00024 *)p)->f90, (const struct Vec2 *)(&pc), 0);
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f90, 1);
    }
    if (((struct Obj00024 *)p)->f14 == 1 && CLACT_IsActorAnimActive(((struct Obj00024 *)p)->f88) == 0 && CLACT_GetActorDrawEnable(((struct Obj00024 *)p)->f90) == 0) {
        pd = d_021C703C;
        switch (p[0x37]) {
        case 3:
            pd.x = pd.x - 0x20;
            break;
        case 4:
            pd.x = pd.x - 0x10;
            break;
        case 6:
            pd.x = pd.x + 0x10;
            break;
        case 7:
            pd.x = pd.x + 0x20;
            break;
        }
        CLACT_AddActorSurfacePos(((struct Obj00024 *)p)->f90, (const struct Vec2 *)(&pd), 0);
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f90, 1);
    }
}




void func_021BB288(void *ctx, u8 *p)
{
    u32_021BB288 x;
    u32_021BB288 y;
    int out1;
    u32_021BB288 x2;
    u32_021BB288 y2;
    int out2;
    u32_021BB288 s2;
    u32_021BB288 s1;
    u32_021BB288 base;
    u16 *pb;
    u32_021BB288 off;
    u32_021BB288 a2;
    u32_021BB288 v1;
    u32_021BB288 v2;
    u8 mode;
    u32_021BB288 base2;
    u8 *e;
    u32_021BB288 cur;

    TOUCHPANEL_GetPointTrg(&x, &y);
    if (func_021BE0C8(ctx) == 1) {
        return;
    }
    if (TOUCHPANEL_GetCont() == 0) {
        ((struct Obj00024 *)p)->fC = 0;
    }
    if (TOUCHPANEL_GetTrg() == 1 && ((struct Obj00024 *)p)->f8 == 0 && ((struct Obj00024 *)p)->f0 == 5 && y >= 0xa8) {
        if (((struct Obj00024 *)p)->f28 == 1) {
            ((struct Obj00024 *)p)->f28 = (((struct Obj00024 *)p)->f24 == 0) ? 0 : 3;
            func_021BB54C(ctx, p);
        }
        func_021BB9E4(ctx, (char *)p);
        return;
    }
    if ((u32_021BB288)(((struct Obj00024 *)p)->f0 - 4) <= 1 && TOUCHPANEL_GetTrg() == 1 && ((struct Obj00024 *)p)->f8 == 0 && ((struct Obj00024 *)p)->f28 == 3) {
        mode = func_021BE054(ctx);
        cur = func_021BDFE4(ctx);
        s1 = func_021BDFFC(ctx);
        e = (u8 *)func_021B8BB8((int)ctx, (unsigned char *)cur, &out1);
        if (out1 == 0) {
            e[0] = x;
            e[1] = y;
            e[2] = x;
            e[3] = y;
            e[6] = p[0x37];
            ((struct Obj01757 *)e)->f4 = ((struct Obj00024 *)p)->f34;
            if (mode == 1) {
                func_021B6E88((char *)s1, e);
            } else {
                func_021B8BFC((int)ctx, (u8 *)cur);
            }
        }
    }
    if (TOUCHPANEL_GetTrg() == 1 && ((struct Obj00024 *)p)->f8 == 0) {
        if (((struct Obj00024 *)p)->f28 == 1) {
            pb = (u16 *)func_0207E008();
            off = y << 9;
            base = (x << 1) + (u32_021BB288)pb;
            func_0207E100();
            if (func_021BE078(ctx) == 1) {
                a2 = ((y >> 1) << 9) + ((x & ~1) + func_0207E100());
            } else {
                a2 = (y << 9) + ((x << 1) + func_0207E100());
            }
            v1 = *(u16 *)(off + base);
            if (v1 & 0x8000) {
                ((struct Obj00024 *)p)->f34 = v1;
            } else {
                v2 = ((struct Obj24101 *)a2)->f0;
                if (v2 & 0x8000) {
                    ((struct Obj00024 *)p)->f34 = v2;
                } else {
                    ((struct Obj00024 *)p)->f34 = 0x8000;
                }
            }
            *(volatile u16 *)0x0500021A = ((struct Obj00024 *)p)->f34 & 0x7fff;
            ((struct Obj00024 *)p)->f28 = (((struct Obj00024 *)p)->f24 == 0) ? 0 : 3;
            func_021BB54C(ctx, p);
            GFL_USE_PlaySeDefaultVolume(0x66d);
        } else {
            ((struct Obj00024 *)p)->fC = 1;
            ((struct Obj00024 *)p)->f2C = 0xffff;
            ((struct Obj00024 *)p)->f30 = 0xffff;
            func_021BB9E4(ctx, (char *)p);
        }
    }
    if ((((struct Obj00024 *)p)->f28 == 0 || ((struct Obj00024 *)p)->f28 == 2) && ((struct Obj00024 *)p)->fC == 1) {
        TOUCHPANEL_GetPointCont(&x2, &y2);
        if (((struct Obj00024 *)p)->fC == 1) {
            if (((struct Obj00024 *)p)->f2C != 0xffff && ((struct Obj00024 *)p)->f30 != 0xffff) {
                mode = func_021BE054(ctx);
                cur = func_021BDFE4(ctx);
                s2 = func_021BDFFC(ctx);
                e = (u8 *)func_021B8BB8((int)ctx, (unsigned char *)cur, &out2);
                if (out2 == 0) {
                    e[0] = ((struct Obj00024 *)p)->f2C;
                    e[1] = ((struct Obj00024 *)p)->f30;
                    e[2] = x2;
                    e[3] = y2;
                    e[6] = p[0x36];
                    if (((struct Obj00024 *)p)->f28 == 2) {
                        ((struct Obj01757 *)e)->f4 = 0;
                        e[6] = 2;
                    } else {
                        ((struct Obj01757 *)e)->f4 = ((struct Obj00024 *)p)->f34;
                    }
                    if (mode == 1) {
                        func_021B6E88((char *)s2, e);
                    } else {
                        func_021B8BFC((int)ctx, (u8 *)cur);
                    }
                } else {
                    ((struct Obj00024 *)p)->fC = 0;
                }
            }
            ((struct Obj00024 *)p)->f2C = x2;
            ((struct Obj00024 *)p)->f30 = y2;
        }
    }
}



void func_021BB4D0(void *unused, u8 *q)
{
    s16 pos[2];
    u8 i;
    int changed = 0;
    if (CLACT_IsActorAnimActive(*(struct Actor * *)&((struct Obj02880 *)q)->f6C) == 0 ||
        CLACT_GetActorAnimSeq(*(struct Obj * *)&((struct Obj02880 *)q)->f6C) == 1) {
        if ((u8)q[4] < (u8)q[5]) { q[5] -= 24; changed = 1; }
        else if ((u8)q[4] > (u8)q[5]) { q[5] += 24; changed = 1; }
    }
    if (changed == 1) {
        func_02041EE4(0, 3, 24 - (u8)q[5]);
        for (i = 0; i < 6; i++) {
            u8 *element = q + i * 4;
            CLACT_GetActorSurfacePos(*(struct Actor * *)&((struct Obj14307 *)element)->f58, (struct PtS *)pos, 0);
            pos[1] = q[5] + 180;
            if (i == 5) pos[1] -= 12;
            CLACT_AddActorSurfacePos((struct Obj *)(*(struct Actor * *)&((struct Obj14307 *)element)->f58), (const struct Vec2 *)pos, 0);
        }
    }
}




void func_021BB54C(void *ctx, u8 *p)
{
    int r;

    CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f58, d_021C6FB2[((struct Obj00024 *)p)->f28 == 0]);
    CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f5C, d_021C6FB4[((struct Obj00024 *)p)->f28 == 1]);
    CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f60, d_021C6FB6[((struct Obj00024 *)p)->f28 == 2]);
    CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f64, d_021C6FB8[((struct Obj00024 *)p)->f28 == 3]);
    r = func_021BE0B4(ctx);
    if (r == 1) {
        CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f68, 12);
    } else {
        CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f68, 10);
    }
    if (((struct Obj00024 *)p)->f28 != 0 && ((struct Obj00024 *)p)->f10 == 1) {
        ((struct Obj00024 *)p)->f10 = 0;
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f84, 0);
        CLACT_RestartActorAnim(((struct Obj00024 *)p)->f84);
        CLACT_SetActorAnimFrame(((struct Obj00024 *)p)->f84, 0);
        CLACT_SetActorAutoAnim(((struct Obj00024 *)p)->f84, 0);
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f90, 0);
    }
    if (((struct Obj00024 *)p)->f28 != 3 && ((struct Obj00024 *)p)->f14 == 1) {
        ((struct Obj00024 *)p)->f14 = 0;
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f88, 0);
        CLACT_RestartActorAnim(((struct Obj00024 *)p)->f88);
        CLACT_SetActorAnimFrame(((struct Obj00024 *)p)->f88, 0);
        CLACT_SetActorAutoAnim(((struct Obj00024 *)p)->f88, 0);
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f90, 0);
    }
}




void func_021BB65C(void *ctx, u8 *p, int k)
{
    void *last;
    void *w8;
    void *w7;
    void *w6;
    void *w5;
    void *w4;
    void *w3;
    void *w2;
    void *w1;
    void *w0;
    void *old;
    void *h3c;
    void *h44;
    u32_021BB65C h34;

    h34 = func_021BE034(ctx);
    h3c = (void *)func_021BE03C(ctx);
    h44 = (void *)func_021BE044(ctx);
    old = ((struct Obj00836 *)p)->f48;
    if (old != 0) {
        PRINTSYS_QUE_Clear(h44);
        func_0201F7A8(((struct Obj00836 *)p)->f48, 2);
        BMP_WIN_ClearScreen(((struct Obj00836 *)p)->f48);
    }
    ((struct Obj00836 *)p)->f3C = k;
    if (k == 1) {
        ((struct Obj00836 *)p)->f48 = (void *)BMP_WIN_Create(4, 2, 8, 0x1c, 0xd, 0xa, 1);
        BMP_Clear(BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0xf);
        BMP_WIN_TransferChars(((struct Obj00836 *)p)->f48);
        w0 = func_02045EC0(h3c, 6);
        PRINTSYS_PrintQueColor(h44, BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x40, 0x4, w0, h34, 0x440);
        STRBUF_Delete(w0);
        w1 = func_02045EC0(h3c, 7);
        PRINTSYS_PrintQueColor(h44, BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x40, 0x18, w1, h34, 0x440);
        STRBUF_Delete(w1);
        w2 = func_02045EC0(h3c, 8);
        PRINTSYS_PrintQueColor(h44, BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x40, 0x2c, w2, h34, 0x440);
        STRBUF_Delete(w2);
        w3 = func_02045EC0(h3c, 10);
        PRINTSYS_PrintQueColor(h44, BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x40, 0x40, w3, h34, 0x440);
        STRBUF_Delete(w3);
        last = func_02045EC0(h3c, 9);
        PRINTSYS_PrintQueColor(h44, BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x40, 0x54, last, h34, 0x440);
        STRBUF_Delete(last);
    } else {
        ((struct Obj00836 *)p)->f48 = (void *)BMP_WIN_Create(4, 2, 0x10, 0x1c, 6, 0xa, 1);
        BMP_Clear(BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0xf);
        BMP_WIN_TransferChars(((struct Obj00836 *)p)->f48);
        w4 = func_02045EC0(h3c, 0);
        PRINTSYS_PrintQueColor(h44, BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x8, 0x0, w4, h34, 0x440);
        STRBUF_Delete(w4);
        w5 = func_02045EC0(h3c, 1);
        PRINTSYS_PrintQueColor(h44, BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x8, 0x10, w5, h34, 0x440);
        STRBUF_Delete(w5);
        w6 = func_02045EC0(h3c, 2);
        PRINTSYS_PrintQueColor(h44, BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x8, 0x20, w6, h34, 0x440);
        STRBUF_Delete(w6);
        w7 = func_02045EC0(h3c, 3);
        PRINTSYS_PrintQueColor(h44, BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x50, 0x0, w7, h34, 0x440);
        STRBUF_Delete(w7);
        w8 = func_02045EC0(h3c, 4);
        PRINTSYS_PrintQueColor(h44, BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x50, 0x10, w8, h34, 0x440);
        STRBUF_Delete(w8);
        last = func_02045EC0(h3c, 5);
        PRINTSYS_PrintQueColor(h44, BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x50, 0x20, last, h34, 0x440);
        STRBUF_Delete(last);
    }
    ((struct Obj00836 *)p)->f38 = 1;
    if (old != 0) {
        BMP_WIN_Delete(old);
    }
}




/*
 * Maps the +4 state to an output code through the two ARM9 probes, 9/6/0xd.
 *
 * Addresses are Black-image addresses.
 */
int func_021BB8F4(void *a0, int *out)
{
    if (func_021BE0D0(a0) == 1) {
        int v = func_021B80E4((int)a0, (char *)func_021BDFE4(a0));

        *out = (v == 5) ? 9 : 6;
        return 1;
    }
    if (func_021BE054(a0) <= 1) {
        *out = 0xd;
        return 1;
    }
    return 0;
}



void func_021BB938(void *p, u8 *q, int id)
{
    u32_021BB938 font = func_021BE034(p);
    u32_021BB938 msgs = func_021BE03C(p);
    u32_021BB938 sys = func_021BE044(p);
    u32_021BB938 text;
    if (*(u32_021BB938 *)&((struct Obj02881 *)q)->f50 != 0) BMP_WIN_Delete(((struct Obj02881 *)q)->f50);
    *(u32_021BB938 *)&((struct Obj02881 *)q)->f50 = BMP_WIN_Create(0, 1, q[4] == 0 ? 4 : 1, 30, 4, 10, 1);
    PRINTSYS_QUE_Clear((struct PrintSys *)sys);
    BMP_Clear((struct CharBuf *)((u32_021BB938)BMP_WIN_GetBmp((struct Descriptor *)*(u32_021BB938 *)&((struct Obj02881 *)q)->f50)), 15);
    text = (u32_021BB938)func_02045EC0((struct MsgBank *)msgs, id);
    PRINTSYS_PrintQueColor((void *)sys, BMP_WIN_GetBmp((struct Descriptor *)*(u32_021BB938 *)&((struct Obj02881 *)q)->f50), 0, 0, (void *)text, font, 1088);
    STRBUF_Delete((struct U16Vec *)text);
    BMP_WIN_TransferChars((struct Descriptor *)*(u32_021BB938 *)&((struct Obj02881 *)q)->f50);
    BMP_WIN_MakeScreen((struct Cfg *)(*(u32_021BB938 *)&((struct Obj02881 *)q)->f50));
    func_0201F73C((void *)(*(u32_021BB938 *)&((struct Obj02881 *)q)->f50), 1, 512, 9);
    ((struct Obj02881 *)q)->f44 = 1;
}




/*
 * Clears +0x10/+0x14 then runs the 0x84/0x88/0x8c/0x90 handles through the five
 * resource teardown entry points.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB9E4(void *a0, char *a1)
{
    *(u32_021BB9E4 *)&((struct Obj00024 *)a1)->f10 = 0;
    *(u32_021BB9E4 *)&((struct Obj00024 *)a1)->f14 = 0;
    CLACT_RestartActorAnim(((struct Obj00024 *)a1)->f84);
    CLACT_RestartActorAnim(((struct Obj00024 *)a1)->f88);
    CLACT_RestartActorAnim(((struct Obj00024 *)a1)->f8C);
    CLACT_SetActorAnimFrame(((struct Obj00024 *)a1)->f84, 0);
    CLACT_SetActorAnimFrame(((struct Obj00024 *)a1)->f88, 0);
    CLACT_SetActorAutoAnim(((struct Obj00024 *)a1)->f84, 0);
    CLACT_SetActorAutoAnim(((struct Obj00024 *)a1)->f88, 0);
    CLACT_SetActorDrawEnable(((struct Obj00024 *)a1)->f84, 0);
    CLACT_SetActorDrawEnable(((struct Obj00024 *)a1)->f88, 0);
    CLACT_SetActorDrawEnable(((struct Obj00024 *)a1)->f8C, 0);
    CLACT_SetActorDrawEnable(((struct Obj00024 *)a1)->f90, 0);
}




#define W(o) (*(u32_021BBF2C *)(p + (o)))




#define B(o) (*(u8 *)(p + (o)))




#define H(o) (*(u16 *)(p + (o)))






void *func_021BBA6C(int unused, void *p)
{
    return func_02030734((u32_021BBA6C)p, 0x408, 1, (const char *)g_021C7234, 0xd8);
}






/*
 * Tail call to func_020307B0, second argument forwarded.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBA88(int unused, int v)
{
    func_020307B0((void *)v);
}






/*
 * Scene setup: fifteen rows of three sprite objects (stride 0x1c), the objects at +0x400 and
 * +0x404, fifteen 0x24-byte entries with text buffers, fifteen windows, then state clears.
 * note 2026-10-05 (wD7 lane03): EXACT. Closing levers: the d.z choice as an if/else (the ternary
 * gave the inverted branch layout and changed the whole colouring), the missing `d.a = 0x10` in
 * the third object of each row (logic error in the draft), row computed after the descriptor
 * stores, and separate pointer locals for loop 2 and loop 3 (spill slots 0x10 and 0xc).
 */
void func_021BBA94(void *a0, u8 *p)
{
    struct Desc d;
    u16 v;
    u32_021BBA94 o;
    u8 i;
    u8 j;
    u8 k;
    u8 z;
    u8 *row;
    u8 *ent;
    u8 *slot;
    u32_021BBA94 owner;
    int o1, o2, o3, o4, o5, o6, o7;

    v = func_021BE00C(a0);
    owner = func_021BE010(a0);
    o = func_021BE004(a0);
    if (*(u32_021BBA94 *)(o + 4) != 2 && *(u32_021BBA94 *)(o + 4) != 3 && func_021BE0EC(a0) == 0) {
        func_02049658((void *)owner, 0xb, 4, 0, 0xa << 10, 0, v);
        func_020498F4((void *)owner, 0x12, 4, 0, 0, 0, v);
        func_020409B4(4);
    }
    d.b = 3;
    for (i = 0; i < 15; i++) {
        d.x = 0x80;
        d.y = i * 32 + 0x10;
        d.z = 8;
        d.a = 0x20;
        row = p + i * 0x1c;
        *(u32_021BBA94 *)(row + 0x48) = (u32_021BBA94)MK(a0, p, 5, 1, 9, 1);
        CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BBA94 *)(row + 0x48), 0);
        CLACT_SetActorAutoAnim((struct Obj *)*(u32_021BBA94 *)(row + 0x48), 1);
        d.x = 0x12;
        d.z = 9;
        d.a = 0x10;
        *(u32_021BBA94 *)(row + 0x4c) = (u32_021BBA94)MK(a0, p, 5, 1, 9, 1);
        CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BBA94 *)(row + 0x4c), 0);
        d.x = 0xc8;
        d.z = 0x12;
        d.a = 0x10;
        *(u32_021BBA94 *)(row + 0x50) = (u32_021BBA94)MK(a0, p, 5, 1, 9, 1);
        CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BBA94 *)(row + 0x50), 0);
    }
    d.x = 0xe0;
    d.y = 0xa8;
    if (func_021BE0EC(a0) == 0)
        d.z = 1;
    else
        d.z = 0xf;
    j = 0;
    d.a = j;
    d.b = j;
    *(u32_021BBA94 *)(p + 0x400) = (u32_021BBA94)MK(a0, p, 6, 2, 10, 1);
    CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BBA94 *)(p + 0x400), 1);
    CLACT_SetActorAutoAnim((struct Obj *)*(u32_021BBA94 *)(p + 0x400), 1);
    d.x = 0xf8;
    d.y = 0x18;
    d.z = 0xc;
    *(u32_021BBA94 *)(p + 0x404) = (u32_021BBA94)MK(a0, p, 5, 1, 9, 1);
    CLACT_SetActorDrawEnable((struct Obj *)*(u32_021BBA94 *)(p + 0x404), 0);
    o1 = 0x14A;
    o1 += 0x9a;
    o2 = 0x14A;
    o2 += 0x9e;
    o3 = 0x14A;
    o3 += 0xa2;
    o4 = 0x14A;
    o4 += 0xaa;
    o5 = 0x14A;
    o5 += 0xba;
    o6 = 0x14A;
    o6 += 0xae;
    o7 = 0x14A;
    o7 += 0xb9;
    for (j = 0; j < 15; j++) {
        ent = p + j * 0x24;
        *(u32_021BBA94 *)(ent + o1) = 0;
        *(u32_021BBA94 *)(ent + o2) = 0;
        *(u32_021BBA94 *)(ent + o3) = 0;
        *(u32_021BBA94 *)(ent + o4) = 0;
        *(u8 *)(ent + o5) = 0xff;
        *(u32_021BBA94 *)(ent + o6) = (u32_021BBA94)func_02030734(v, 0x64, 1, (const char *)d_021C7234, 0xff + 0x4b);
        *(u8 *)(ent + o7) = 0;
    }
    for (k = 0; k < 15; k++) {
        slot = p + k * 0x1c;
        *(u32_021BBA94 *)(slot + 0x40) = 0;
        *(u32_021BBA94 *)(slot + 0x44) = 0;
        *(u8 *)(slot + 0x58) = 0xff;
        *(u32_021BBA94 *)(slot + 0x54) = BMP_WIN_Create(6, 3, (u8)(k * 4 + 1), 0x19, 2, 0xa, 1);
    }
    *(u32_021BBA94 *)(p + 0x2c) = BMP_WIN_Create(4, 1, 0x15, 0x15, 2, 0xa, 1);
    *(u32_021BBA94 *)(p + 0x30) = BMP_WIN_Create(4, 2, 9, 0x1c, 2, 0xa, 1);
    z = 0;
    *(u32_021BBA94 *)(p + 0x38) = z;
    *(u16 *)(p + 0x36) = z;
    for (z = 0; z < 3; z++) {
        p[z] = 0xff;
    }
    p[3] = 0xff;
    *(u16 *)(p + 4) = 0;
    *(u16 *)(p + 6) = 0;
    p[0x14] = 0;
    p[0x15] = 0xff;
    *(u32_021BBA94 *)(p + 0x18) = 0xff;
    *(u32_021BBA94 *)(p + 0xc) = 0;
    *(u32_021BBA94 *)(p + 0x10) = 0;
    *(u32_021BBA94 *)(p + 0x20) = 0;
    *(u32_021BBA94 *)(p + 0x24) = 0;
    *(u32_021BBA94 *)(p + 0x28) = 0;
    *(u32_021BBA94 *)(p + 0x1c) = 0;
    *(u32_021BBA94 *)(p + 8) = 0;
    *(u16 *)(p + 0x34) = 0;
    func_02041EE4(6, 3, 0);
    if ((u32_021BBA94)(*(u32_021BBA94 *)(o + 4) - 2) <= 1 && func_021BE0EC(a0) == 0) {
        CLACT_SetActorAnimSeq((struct Obj *)*(u32_021BBA94 *)(p + 0x400), 0xf);
        func_021BD134(a0, (char *)p, 0x18);
        *(u32_021BBA94 *)(p + 0x38) = 1;
        *(u32_021BBA94 *)(p + 0x18) = 3;
    }
}






void func_021BBE5C(void *a0, char *a1)
{
    u32_021BBE5C p;
    u8 i, j;

    if (((struct Obj03316 *)a1)->f1C != 0) {
        APP_TASKMENU_WIN_Delete((u8 *)(*(u32_021BBE5C *)&((struct Obj03316 *)a1)->f1C));
        *(u32_021BBE5C *)&((struct Obj03316 *)a1)->f1C = 0;
    }

    p = ((struct Obj03316 *)a1)->f2C;
    BMP_WIN_ClearScreen((struct Descriptor *)p);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)p));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj03316 *)a1)->f2C));

    p = ((struct Obj03316 *)a1)->f30;
    BMP_WIN_ClearScreen((struct Descriptor *)p);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)p));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj03316 *)a1)->f30));

    CLACT_DeleteActor((struct Obj *)(((struct Obj03316 *)a1)->f404));
    CLACT_DeleteActor((struct Obj *)(((struct Obj03316 *)a1)->f400));

    for (i = 0; i < 0xf; i++) {
        char *q = a1 + i * 0x1c;

        BMP_WIN_Delete((struct Descriptor *)(((struct Obj08261 *)q)->f54));
        CLACT_DeleteActor((struct Obj *)(((struct Obj08261 *)q)->f50));
        CLACT_DeleteActor((struct Obj *)(((struct Obj08261 *)q)->f4C));
        CLACT_DeleteActor((struct Obj *)(((struct Obj08261 *)q)->f48));
    }

    for (j = 0; j < 0xf; j++)
        func_020307B0((void *)(*(u32_021BBE5C *)(a1 + j * 0x24 + 0x1f8)));

    func_020414EC(6);
    func_020409B4(6);
    func_02041EE4(6, 3, 0);
    func_020414EC(4);
    func_020409B4(4);
    func_02041EE4(4, 3, 0);
}






/*
 * 2026-10-04 (D3-06): byte-identical (1724 bytes); 4 of 106 relocations wait on
 *   unlabelled ov172 Thumb leaves filed EXACT this wave as src/matched/ov/
 *   ov172_func_021B8B7C.c, ov172_func_021B8C14.c, ov172_func_021B8C20.c,
 *   ov172_func_021BE0F0.c. After the integrator manifest gives them shard
 *   witnesses, this file should verify EXACT and move to src/matched/ov.
 *   Keys: cnt is block-local in the fC==1 block (sets its stack slot);
 *   case 6 jumps into case 10 by tail merge (code written twice).
 */
int func_021BBF2C(void *a0, char *p)
{
    u32_021BBF2C t;
    u16 v;
    u32_021BBF2C *st;
    u32_021BBF2C t2;
    u8 i, j;
    char *r;
    char *q;
    u8 *ip;
    u32_021BBF2C w;
    struct Descriptor *d;

    v = func_021BE00C(a0);
    st = (u32_021BBF2C *)func_021BE004(a0);
    switch (W(8)) {
    case 0:
        if (func_021BE02C(a0) == 1)
            WIPE_SYS_Start((void *)0, 1, 1, 0, 6, 1, v);
        else
            WIPE_SYS_Start((void *)4, 1, 1, 0, 6, 1, v);
        W(8) = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            u32_021BBF2C *s = (u32_021BBF2C *)func_021BE004(a0);
            if (func_021BE0EC(a0) == 1)
                W(8) = 11;
            else if (s[1] == 2 || s[1] == 3)
                W(8) = 8;
            else
                W(8) = 5;
        }
        break;
    case 2:
        WIPE_SYS_Start((void *)4, 0, 0, 0, 6, 1, v);
        func_021BE030(a0, 0);
        W(8) = 4;
        break;
    case 3:
        if (func_021B7590((int)a0, (char *)func_021BDFDC(a0)) == 1) {
            WIPE_SYS_Start((void *)0, 0, 0, 0, 6, 1, v);
            func_021BE030(a0, 0);
            W(8) = 4;
        }
        break;
    case 4:
        if (WIPE_SYS_EndCheck() == 1) {
            if (W(0x18) == 0 || W(0x18) == 5)
                return 4;
            return 1;
        }
        break;
    case 5:
        func_021BC5E8(a0, (u8 *)p);
        func_021BD038(a0, p);
        break;
    case 6:
        if (W(0x18) == 0 || W(0x18) == 5) {
            if (CLACT_IsActorAnimActive((struct Actor *)OBJ) == 0) {
                func_021B7578((int)a0, (char *)func_021BDFDC(a0));
                W(0x18) = 0;
                W(8) = 3;
            }
            break;
        }
        if (APP_TASKMENU_WIN_IsFinish((void *)W(0x1c)) != 1)
            break;
        if (W(0x18) == 2) {
            t = func_021BDFE4(a0);
            func_021B80DC((int)a0, (char *)t, 4);
            func_021B80EC((int)a0, (char *)t, (const u8 *)(p + 0x1fd + B(3) * 0x24));
            func_021BD134(a0, p, 0x18);
            W(0x38) = 1;
            W(8) = 7;
            H(0x34) = 0;
            H(0x36) = 0;
            APP_TASKMENU_WIN_Delete((void *)W(0x1c));
            W(0x1c) = 0;
        } else {
            t2 = func_021BDFE4(a0);
            W(8) = 9;
            func_021BD134(a0, p, 0x14);
            W(0x38) = 1;
            H(0x36) = 0;
            func_021B80DC((int)a0, (char *)t2, 3);
            APP_TASKMENU_WIN_Delete((void *)W(0x1c));
            W(0x1c) = 0;
            ip = func_021B8B7C(a0, (u8 *)t2);
            for (i = 0; i < 3; i++) {
                if (B(i) == 0xff) {
                    for (j = 0; j < 6; j++)
                        ip[i * 6 + j + 0x22] = 0xff;
                } else {
                    for (j = 0; j < 6; j++)
                        ip[i * 6 + j + 0x22] = *(u8 *)(p + B(i) * 0x24 + j + 0x1fd);
                }
            }
            ip[0x21] |= 2;
            func_021B8C14(a0, (u8 *)t2);
        }
        CLACT_SetActorAnimSeq(OBJ, 0xf);
        break;
    case 7:
    case 8:
    case 9:
        func_021BDFE4(a0);
        if (func_021BE054(a0) >= 2) {
            if (W(0x28) == 0) {
                t = func_021BDFDC(a0);
                GFL_USE_StopAllSe();
                GFL_USE_PlaySeDefaultVolume(0x73e);
                func_021B7B64((int)a0, (char *)t);
            }
            W(8) = 2;
        }
        if (W(8) == 9) {
            H(0x36)++;
            if (H(0x36) >= 0x78) {
                H(0x36) = 0;
                GFL_USE_PlaySeInSlot((void *)0x73d, 2);
            }
        }
        if (W(8) == 9) {
            if (func_021B8C20(a0, (u8 *)func_021BDFE4(a0)) == 1) {
                func_021B80DC((int)a0, (char *)func_021BDFE4(a0), 2);
                func_021BD134(a0, p, 0x27);
                W(8) = 10;
            }
        } else if (W(8) == 7 || W(8) == 8) {
            H(0x34)++;
            if (H(0x34) >= 0x4b0) {
                func_021B80DC((int)a0, (char *)func_021BDFE4(a0), 2);
                func_021BD134(a0, p, 0x28);
                W(8) = 10;
            }
        }
        break;
    case 10:
        if (TOUCHPANEL_GetTrg() == 1) {
            if (((u32_021BBF2C *)func_021BE004(a0))[1] == 2) {
                func_021B7578((int)a0, (char *)func_021BDFDC(a0));
                W(0x18) = 0;
                W(8) = 3;
            } else {
                for (i = 0; i < 3; i++)
                    B(i) = 0xff;
                W(8) = 5;
                B(3) = 0xff;
                func_0201F7A8((void *)W(0x30), 1);
                d = (struct Descriptor *)W(0x30);
                BMP_WIN_ClearScreen(d);
                func_020409B4(BMP_WIN_GetBgLayer(d));
                func_021BE34C(a0);
                CLACT_SetActorAnimSeq(OBJ, 1);
                W(0x18) = 4;
            }
        }
        break;
    case 11:
        BMP_WIN_Delete((struct Descriptor *)W(0x2c));
        W(0x2c) = BMP_WIN_Create(4, 2, 5, 0x1c, 0xe, 0xa, 1);
        func_021BD0C4(a0, p, 0x29);
        W(8) = 12;
        break;
    case 12:
        if (func_021BE054(a0) >= 2 && W(0x28) == 0) {
            GFL_USE_StopAllSe();
            W(0x28) = 1;
            GFL_USE_PlaySeDefaultVolume(0x73e);
        }
        if (TOUCHPANEL_GetTrg() == 1 || func_021BE0D0(a0) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            func_0201F7A8((void *)W(0x2c), 1);
            d = (struct Descriptor *)W(0x2c);
            BMP_WIN_ClearScreen(d);
            func_020409B4(BMP_WIN_GetBgLayer(d));
            BMP_WIN_Delete((struct Descriptor *)W(0x2c));
            W(0x2c) = BMP_WIN_Create(4, 1, 0x15, 0x15, 2, 0xa, 1);
            func_021BE0F0(a0);
            if (st[1] == 2 || st[1] == 3) {
                CLACT_SetActorAnimSeq(OBJ, 0xf);
                if (func_021BE054(a0) < 2)
                    func_021BD134(a0, p, 0x18);
                W(0x38) = 1;
                W(0x18) = 3;
                W(8) = 8;
            } else {
                W(8) = 5;
                W(0x18) = 4;
                CLACT_SetActorAnimSeq(OBJ, 1);
                v = func_021BE00C(a0);
                w = func_021BE010(a0);
                func_02049658((void *)w, 0xb, 4, 0, 0x2800, 0, v);
                func_020498F4((void *)w, 0x12, 4, 0, 0, 0, v);
                func_020409B4(4);
            }
        }
        break;
    }
    if (st[1] != 3 && func_021BE0EC(a0) == 0) {
        func_021BC7FC(a0, (u8 *)p);
        for (i = 0; i < 15; i++) {
            r = p + i * 0x1c;
            if (*(u32_021BBF2C *)(r + 0x44) == 1) {
                struct PrintSys *ps = (struct PrintSys *)func_021BE044(a0);
                if (PRINTSYS_QUE_IsExistTarget(ps, BMP_WIN_GetBmp(*(struct Descriptor **)(r + 0x54))) == 0) {
                    d = *(struct Descriptor **)(r + 0x54);
                    BMP_WIN_TransferChars(d);
                    BMP_WIN_MakeScreen((struct Cfg *)d);
                    func_02041B6C(BMP_WIN_GetBgLayer(d));
                    *(u32_021BBF2C *)(r + 0x44) = 0;
                }
            }
        }
        if (W(0xc) == 1) {
            u8 cnt = 0;
            for (i = 0; i < 15; i++)
                func_021BCE2C(a0, p, p + 0x40 + i * 0x1c, i);
            func_02041EE4(6, 3, H(4));
            for (i = 0; i < 3; i++) {
                if (B(i) != 0xff)
                    cnt++;
            }
            for (j = 0; j < 15; j++) {
                r = p + j * 0x24;
                if (*(u32_021BBF2C *)(r + 0x1e4) == 1) {
                    q = p + 0x40 + *(u8 *)(r + 0x204) * 0x1c;
                    if (*(u32_021BBF2C *)(r + 0x1ec) == 1 && *(u8 *)(r + 0x203) < 4 && (B(3) == 0xff || B(3) == j))
                        CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0xc), 0xa);
                    else if (cnt == 3 || B(3) != 0xff || *(u8 *)(r + 0x203) == 4)
                        CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0xc), 0xb);
                    else
                        CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0xc), 9);
                    if (*(u32_021BBF2C *)(r + 0x1f4) == 1) {
                        *(u32_021BBF2C *)(r + 0x1f4) = 0;
                        CLACT_SetActorAnimSeq(*(struct Obj **)(q + 8), 0x22);
                    }
                }
            }
            W(0xc) = 0;
        }
    }
    if (W(0x20) == 1) {
        struct PrintSys *ps = (struct PrintSys *)func_021BE044(a0);
        if (PRINTSYS_QUE_IsExistTarget(ps, BMP_WIN_GetBmp((struct Descriptor *)W(0x2c))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)W(0x2c));
            BMP_WIN_MakeScreen((struct Cfg *)W(0x2c));
            func_020409B4(4);
            W(0x20) = 0;
        }
    }
    if (W(0x24) == 1) {
        struct PrintSys *ps = (struct PrintSys *)func_021BE044(a0);
        if (PRINTSYS_QUE_IsExistTarget(ps, BMP_WIN_GetBmp((struct Descriptor *)W(0x30))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)W(0x30));
            BMP_WIN_MakeScreen((struct Cfg *)W(0x30));
            func_020409B4(4);
            W(0x24) = 0;
            if (W(0x38) == 1) {
                W(0x38) = 0;
                func_021BE318(a0, (void *)W(0x30));
            }
        }
    }
    if (W(0x1c) != 0)
        APP_TASKMENU_WIN_Update((void *)W(0x1c));
    return 2;
}






void func_021BC5E8(void *ctx, u8 *list)
{
    u32_021BC5E8 tx;
    u32_021BC5E8 ty;
    u32_021BC5E8 dx;
    u32_021BC5E8 dy;
    struct SpritePos pos;
    int trg;
    int cont;
    s16 row;
    u8 id;
    u8 *e;
    int done;
    u8 i;
    int s;
    u32_021BC5E8 range;

    trg = TOUCHPANEL_GetPointTrg(&tx, &ty);
    cont = TOUCHPANEL_GetPointCont(&dx, &dy);
    func_021BDFE4(ctx);
    if (trg == 1) {
        if (tx > 8 && tx < 0xe0) {
            row = (ty + ((struct Obj00330 *)list)->f4) >> 5;
            if (row >= 0 && row < 15) {
                id = *(list + row * 0x1c + 0x58);
                e = list + 0x1e4 + id * 0x24;
                done = 0;
                if (((struct Obj01950 *)e)->f0 == 1 && e[0x1f] < 4) {
                    if (e[0x18] == 0x20) {
                        if (((struct Obj01950 *)e)->f8 == 0) {
                            list[3] = id;
                            done = 1;
                            ((struct Obj01950 *)e)->f8 = 1;
                            ((struct Obj01950 *)e)->f10 = 1;
                            ((struct Obj00330 *)list)->fC = 1;
                            GFL_USE_PlaySeDefaultVolume(0x73b);
                        } else {
                            list[3] = 0xff;
                            ((struct Obj01950 *)e)->f8 = 0;
                            done = 1;
                            ((struct Obj01950 *)e)->f10 = 1;
                            ((struct Obj00330 *)list)->fC = 1;
                            GFL_USE_PlaySeDefaultVolume(0x73c);
                        }
                    } else if (list[3] == 0xff) {
                        if (((struct Obj01950 *)e)->f8 == 0) {
                            for (i = 0; i < 3; i++) {
                                if (list[i] == 0xff) {
                                    list[i] = id;
                                    break;
                                }
                            }
                            if (i < 3) {
                                done = 1;
                                ((struct Obj01950 *)e)->f8 = 1;
                                ((struct Obj01950 *)e)->f10 = 1;
                                ((struct Obj00330 *)list)->fC = 1;
                                GFL_USE_PlaySeDefaultVolume(0x73b);
                            }
                        } else {
                            for (i = 0; i < 3; i++) {
                                if (id == list[i]) {
                                    list[i] = 0xff;
                                    break;
                                }
                            }
                            ((struct Obj01950 *)e)->f8 = 0;
                            done = 1;
                            ((struct Obj01950 *)e)->f10 = 1;
                            ((struct Obj00330 *)list)->fC = 1;
                            GFL_USE_PlaySeDefaultVolume(0x73c);
                        }
                    }
                }
                if (done == 1)
                    func_021BCEF8(ctx, list);
            }
        } else if (tx >= 0xec && tx <= 0x104 && ty >= ((struct Obj00330 *)list)->f6 + 0xc
                   && ty <= ((struct Obj00330 *)list)->f6 + 0x24 && list[0x14] > 5) {
            ((struct Obj00330 *)list)->f10 = 1;
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00330 *)list)->f404), 0xd);
            GFL_USE_PlaySeDefaultVolume(0x66c);
        }
    }
    if (cont == 1 && ((struct Obj00330 *)list)->f10 == 1 && list[0x14] > 5) {
        if (dx >= 0xec && dx <= 0x104 && dy >= 0xc && dy <= 0x9c) {
            range = (list[0x14] - 5) * 32;
            s = dy - 0x18;
            if (s < 0)
                s = 0;
            else if (s > 0x78)
                s = 0x78;
            ((struct Obj00330 *)list)->f6 = s;
            pos.x = 0xf8;
            pos.y = ((struct Obj00330 *)list)->f6 + 0x18;
            CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj00330 *)list)->f404), (const struct Vec2 *)(&pos), 1);
            ((struct Obj00330 *)list)->f4 = ((struct Obj00330 *)list)->f6 * range / 0x78;
            ((struct Obj00330 *)list)->fC = 1;
        }
    } else {
        ((struct Obj00330 *)list)->f10 = 0;
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00330 *)list)->f404), 0xc);
    }
    if (((struct Obj00330 *)list)->f1C != 0 && APP_TASKMENU_WIN_IsTouch((void **)(((struct Obj00330 *)list)->f1C)) == 1) {
        APP_TASKMENU_WIN_SetDecide((char *)(((struct Obj00330 *)list)->f1C), 1);
        ((struct Obj00330 *)list)->f8 = 6;
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if (((struct Obj00330 *)list)->f18 == 1)
            GFL_USE_PlaySeInSlot((void *)0x73d, 2);
    }
    if (!TOUCHPANEL_HitTrg(d_021C7040) || (KEY_GetTrg() & 2)) {
        ((struct Obj00330 *)list)->f8 = 6;
        ((struct Obj00330 *)list)->f18 = 5;
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00330 *)list)->f400), 9);
        GFL_USE_PlaySeDefaultVolume(0x551);
    }
}






/*
 * Peer list refresh: marks every active slot as unseen, scans the 16 wireless
 * peers, matches each peer MAC against the 15 slots (kind 0x20 or 3), adds new
 * peers to a free slot and to the first free row, then drops slots that were
 * not seen, compacts the rows, and refreshes the list.
 *
 * pass 2 2026-10-06 P2L03: EXACT. kind is a u8 local (NET_WHPIPE_GetEntryBeaconKind returns u8) and
 * found = 1 is a plain literal after the unseen store. With a u32 kind the found
 * spill store was scheduled above the unseen store (10 bytes) and the found = match
 * stand-in was needed (2 bytes); the narrow kind closes it.
 */
void func_021BC7FC(void *ctx, u8 *list)
{
    int changed;
    int refresh;
    int found;
    int diff;
    struct Rec *p;
    u8 kind;
    u32_021BC7FC a;
    u32_021BC7FC c;
    int match;
    u8 slot;
    int j;
    int i;
    u8 k;
    u8 m;
    u8 r;
    u8 *e;
    u8 *row;
    u8 *mac;
    u32_021BC7FC mode;
    int ok;
    u32_021BC7FC b;
    u8 buf[8];
    u8 q;

    changed = 0;
    refresh = 0;
    if (!func_021B8108(ctx, (void *)func_021BDFE4(ctx)))
        return;
    for (i = 0; i < 15; i++) {
        e = list + i * 0x24;
        if (*(u32_021BC7FC *)(e + 0x1e4) == 1)
            *(u32_021BC7FC *)(e + 0x1e8) = 1;
    }
    mode = *(u32_021BC7FC *)(list + 8);
    if (mode != 7 && mode != 9 && mode != 10 && (int)mode >= 5) {
        for (j = 0; j < 16; j++) {
            found = 0;
            diff = 0;
            p = (struct Rec *)GFL_NET_GetScanResult(j);
            if (p == 0)
                continue;
            slot = 0xff;
            mac = GFL_NET_GetScanResultMac(j);
            kind = NET_WHPIPE_GetEntryBeaconKind(j);
            if (kind == 3 && ((struct Bits2 *)((u8 *)p + 2))->b1 != 2)
                continue;
            ok = 0;
            if (kind == 0x20) {
                a = (u32_021BC7FC)func_020084F4(p);
                b = func_02008550((const struct Sub0200852CObj *)p);
                c = func_02008530((const struct Sub0200852CObj *)p);
                func_02087C6C(buf);
                if (p->f21_1 == 0 || func_021B85D0((u8 *)p, buf) == 1)
                    ok = func_021BD0A4(ctx, (u32_021BC7FC)list, a, c, b);
            } else if (ZONEDATA_IsZone117((u16)p->fC_17) == 0 && ZONEDATA_IsZoneGroup118To120((u16)p->fC_17) == 0) {
                ok = func_021BD0A4(ctx, (u32_021BC7FC)list, (u32_021BC7FC)((u8 *)p + 0x1a), p->f4, p->bB_7);
            }
            if (ok == 0)
                continue;
            for (k = 0; k < 15; k++) {
                e = list + k * 0x24;
                if (*(u32_021BC7FC *)(e + 0x1e4) == 1) {
                    match = 1;
                    for (m = 0; m < 6; m++) {
                        if (mac[m] != e[m + 0x1fd]) {
                            match = 0;
                            break;
                        }
                    }
                    if (match == 1) {
                        ((struct List *)list)->slots[k].unseen = 0;
                        found = 1;
                        if (kind != ((struct List *)list)->slots[k].kind) {
                            found = 0;
                            diff = 1;
                            slot = k;
                            for (m = 0; m < 3; m++) {
                                if (k == list[m]) {
                                    list[m] = 0xff;
                                    refresh = 1;
                                }
                            }
                            if (list[3] == k) {
                                list[3] = 0xff;
                                refresh = 1;
                            }
                        }
                        if (kind == 0x20 && (*(u8 **)(e + 0x1f8))[0x20] != p->f20) {
                            found = 0;
                            diff = 1;
                            slot = k;
                        }
                        break;
                    }
                } else if (slot == 0xff) {
                    slot = k;
                }
            }
            if (found != 0 || slot == 0xff)
                continue;
            e = list + slot * 0x24;
            *(u32_021BC7FC *)(e + 0x1e4) = 1;
            *(u32_021BC7FC *)(e + 0x1e8) = 0;
            *(u32_021BC7FC *)(e + 0x1ec) = 0;
            for (m = 0; m < 6; m++)
                e[m + 0x1fd] = mac[m];
            if (kind == 0x20) {
                ((struct List *)list)->slots[slot].kind = 0x20;
                func_02082D44(p, ((struct List *)list)->slots[slot].buf, 0x34);
            } else {
                ((struct List *)list)->slots[slot].kind = 3;
                func_02082D44(p, ((struct List *)list)->slots[slot].buf, 0x64);
            }
            if (diff == 0) {
                for (r = 0; r < 15; r++) {
                    row = list + r * 0x1c;
                    if (row[0x58] == 0xff) {
                        row[0x58] = slot;
                        e[0x204] = r;
                        *(u32_021BC7FC *)(row + 0x40) = 1;
                        break;
                    }
                }
            } else {
                *(u32_021BC7FC *)(list + e[0x204] * 0x1c + 0x40) = 1;
            }
            changed = 1;
        }
    }
    for (i = 0; i < 15; i++) {
        e = list + i * 0x24;
        if (*(u32_021BC7FC *)(e + 0x1e4) == 1 && *(u32_021BC7FC *)(e + 0x1e8) == 1) {
            q = e[0x204];
            for (; q < 14; q++) {
                row = list + q * 0x1c;
                if (row[0x74] == 0xff)
                    break;
                row[0x58] = row[0x74];
                list[row[0x58] * 0x24 + 0x204] = q;
                *(u32_021BC7FC *)(row + 0x40) = 1;
            }
            row = list + q * 0x1c;
            row[0x58] = 0xff;
            *(u32_021BC7FC *)(row + 0x40) = 1;
            e[0x204] = 0xff;
            *(u32_021BC7FC *)(e + 0x1e4) = 0;
            for (m = 0; m < 3; m++) {
                if (i == list[m]) {
                    list[m] = 0xff;
                    refresh = 1;
                }
            }
            if (list[3] == i) {
                list[3] = 0xff;
                refresh = 1;
            }
            i--;
            changed = 1;
        }
    }
    if (changed == 1) {
        func_021BCB88(ctx, (char *)list);
        refresh = 1;
        *(u32_021BC7FC *)(list + 0xc) = 1;
    }
    if (refresh == 1 && *(u32_021BC7FC *)(list + 8) == 5)
        func_021BCEF8(ctx, list);
}






void func_021BCB88(void *ctx, char *list)
{
    struct SpritePos pos;
    u8 n = 0;
    u8 i;
    u32_021BCB88 range;

    for (i = 0; i < 15; i++)
        func_021BCC40(ctx, list, list + 0x40 + i * 0x1c, i);
    for (i = 0; i < 15; i++) {
        if (*(u8 *)(list + i * 0x1c + 0x58) != 0xff)
            n++;
    }
    if (((struct Obj01951 *)list)->f14 == n)
        return;
    if (n > 5) {
        range = (n - 5) * 32;
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01951 *)list)->f404, 1);
        if (((struct Obj01951 *)list)->f4 > range)
            ((struct Obj01951 *)list)->f4 = range;
        ((struct Obj01951 *)list)->f6 = ((struct Obj01951 *)list)->f4 * 0x78 / range;
        if (((struct Obj01951 *)list)->f10 == 0) {
            pos.x = 0xf8;
            pos.y = ((struct Obj01951 *)list)->f6 + 0x18;
            CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj01951 *)list)->f404), (const struct Vec2 *)(&pos), 1);
        }
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01951 *)list)->f404, 0);
        ((struct Obj01951 *)list)->f4 = 0;
        ((struct Obj01951 *)list)->fC = 1;
    }
    ((struct Obj01951 *)list)->f14 = n;
}






static inline u8 func_021BCC40_show(u32_021BCC40 win)
{
    BMP_WIN_ClearScreen((struct Descriptor *)win);
    return BMP_WIN_GetBgLayer((struct Descriptor *)win);
}






void func_021BCC40(void *ctx, char *list, char *row, int idx)
{
    u32_021BCC40 buf2;
    u32_021BCC40 fmt2;
    u32_021BCC40 msgs;
    u32_021BCC40 sys;
    u32_021BCC40 str;
    u32_021BCC40 buf;
    u8 *p;
    u32_021BCC40 heap;
    u32_021BCC40 fmt;
    u32 font;
    char *e;
    u32_021BCC40 ws;

    if (((struct Obj02882 *)row)->f0 != 1)
        return;
    if (((struct Obj02882 *)row)->f18 != 0xff) {
        heap = func_021BE00C(ctx);
        font = func_021BE034(ctx);
        msgs = func_021BE03C(ctx);
        sys = func_021BE044(ctx);
        e = list + 0x1e4 + ((struct Obj02882 *)row)->f18 * 0x24;
        ws = (u32_021BCC40)func_0201EC64(heap);
        BMP_Clear((struct CharBuf *)((u32_021BCC40)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02882 *)row)->f14)), 0);
        str = (u32_021BCC40)STRBUF_Create(0x20, heap);
        if (((struct Obj01166 *)e)->f18 == 0x20)
            STRBUF_SetStringN((struct Strbuf *)str, COMM_PLAYER_SUPPORT_GetRecordFieldPtr(((struct Obj01166 *)e)->f14), 8);
        else
            STRBUF_SetStringN((struct Strbuf *)str, (const u16 *)(*(char * *)&((struct Obj01166 *)e)->f14 + 0x1a), 8);
        PRINTSYS_PrintQueColor((void *)sys, BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02882 *)row)->f14), 6, 0, (void *)str, font, 0x3c40);
        STRBUF_Delete((struct U16Vec *)str);
        fmt = (u32_021BCC40)func_02045EC0((struct MsgBank *)msgs, 0xe);
        buf = (u32_021BCC40)STRBUF_Create(0x20, heap);
        if (((struct Obj01166 *)e)->f18 == 0x20)
            func_0201EFA4((struct WordSet *)ws, 0, COMM_PLAYER_SUPPORT_GetRecordField(((struct Obj01166 *)e)->f14), 5, 2, 1);
        else
            func_0201EFA4((struct WordSet *)ws, 0, ((struct Obj24102 *)(*(char * *)&((struct Obj01166 *)e)->f14))->f18, 5, 2, 1);
        func_0201F250((struct WordSet *)ws, (void *)buf, (void *)fmt);
        STRBUF_Delete((struct U16Vec *)fmt);
        PRINTSYS_PrintQueColor((void *)sys, BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02882 *)row)->f14), 0x50, 0, (void *)buf, font, 0x3c40);
        STRBUF_Delete((struct U16Vec *)buf);
        if (((struct Obj01166 *)e)->f18 == 0x20) {
            p = *(u8 * *)&((struct Obj01166 *)e)->f14;
            ((struct Obj01166 *)e)->f1F = p[0x20];
            fmt2 = (u32_021BCC40)func_02045EC0((struct MsgBank *)msgs, 0x10);
            buf2 = (u32_021BCC40)STRBUF_Create(0x20, heap);
            p += 0x20;
            func_0201EFA4((struct WordSet *)ws, 0, *p, 1, 0, 1);
            func_0201F250((struct WordSet *)ws, (void *)buf2, (void *)fmt2);
            STRBUF_Delete((struct U16Vec *)fmt2);
            PRINTSYS_PrintQueColor((void *)sys, BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02882 *)row)->f14), 0x90, 0, (void *)buf2, font, 0x3c40);
            STRBUF_Delete((struct U16Vec *)buf2);
        } else {
            ((struct Obj01166 *)e)->f1F = 0;
        }
        if (((struct Obj01166 *)e)->f18 == 0x20) {
            if ((*(struct FlagsA * *)&((struct Obj01166 *)e)->f14)->on == 1)
                ((struct Obj01166 *)e)->fC = 1;
            else
                ((struct Obj01166 *)e)->fC = 0;
        } else if ((*(struct FlagsB * *)&((struct Obj01166 *)e)->f14)->b7 == 1 && (*(struct FlagsB * *)&((struct Obj01166 *)e)->f14)->b6 == 0) {
            ((struct Obj01166 *)e)->fC = 1;
        } else {
            ((struct Obj01166 *)e)->fC = 0;
        }
        func_0201ED04((struct WordSet *)ws);
        ((struct Obj02882 *)row)->f4 = 1;
    } else {
        func_02041B6C(func_021BCC40_show(((struct Obj02882 *)row)->f14));
    }
    ((struct Obj02882 *)row)->f0 = 0;
}






/*
 * Places the three cursor sprites (+0x8, +0xc, +0x10) on list row idx relative to the scroll offset at +4: hidden when no row is selected (+0x18 == 0xff) or the row is off screen; the third sprite shows only when the selected entry's flag at +0x1f0 is set, animated from the row's cell at +0x50.
 */
void func_021BCE2C(void *ctx, char *list, char *cur, u8 idx)
{
    struct SpritePos pos;
    s16 y;

    if (((struct Obj01560 *)cur)->f18 == 0xff) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f8, 0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->fC, 0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f10, 0);
        return;
    }
    y = idx * 32 - ((struct Obj24103 *)list)->f4;
    if (y >= -32 && y <= 0xa0) {
        pos.x = 0x80;
        pos.y = y + 0x10;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj01560 *)cur)->f8), (const struct Vec2 *)(&pos), 1);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f8, 1);
        pos.x = 0x12;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj01560 *)cur)->fC), (const struct Vec2 *)(&pos), 1);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->fC, 1);
        pos.x = 0xc8;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj01560 *)cur)->f10), (const struct Vec2 *)(&pos), 1);
        if (*(u32_021BCE2C *)(list + ((struct Obj01560 *)cur)->f18 * 0x24 + 0x1f0) == 1) {
            CLACT_SetActorAnimSeq((struct Obj *)(*(u32_021BCE2C *)(list + idx * 0x1c + 0x50)), 0x12);
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f10, 1);
        } else {
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f10, 0);
        }
        return;
    }
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f8, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->fC, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01560 *)cur)->f10, 0);
}






static inline u8 func_021BCEF8_show(u32_021BCEF8 win)
{
    BMP_WIN_ClearScreen((struct Descriptor *)win);
    return BMP_WIN_GetBgLayer((struct Descriptor *)win);
}






/*
 * Keeps the button prompt (+0x1c, kind at +0x18) in step with the selection: a fourth selected slot shows prompt 0x13 (kind 2), any selected slot shows prompt 0x12 (kind 1), none removes the prompt (kind 0) and reprints message 0x11 when the mode byte at +0x14 is set.
 */
void func_021BCEF8(void *ctx, u8 *st)
{
    u8 n = 0;
    u8 i;
    u16 heap = func_021BE00C(ctx);
    u32_021BCEF8 msgs = func_021BE03C(ctx);
    u32_021BCEF8 sys = func_021BE04C(ctx);

    for (i = 0; i < 3; i++) {
        if (st[i] != 0xff)
            n++;
    }
    if (st[3] != 0xff) {
        if (((struct Obj00543 *)st)->f18 != 2) {
            struct Prompt p = {0};

            func_02041B6C(func_021BCEF8_show(((struct Obj00543 *)st)->f2C));
            func_0201F7A8((void *)(((struct Obj00543 *)st)->f2C), 1);
            if (((struct Obj00543 *)st)->f1C != 0) {
                APP_TASKMENU_WIN_Delete((u8 *)(((struct Obj00543 *)st)->f1C));
                ((struct Obj00543 *)st)->f1C = 0;
            }
            p.str = (u32_021BCEF8)func_02045EC0((struct MsgBank *)msgs, 0x13);
            p.color = 0x39e3;
            p.flags = 0;
            ((struct Obj00543 *)st)->f1C = APP_TASKMENU_WIN_Create(sys, (u32_021BCEF8)(&p), 0, 0x15, 0x15, heap);
            STRBUF_Delete((struct U16Vec *)p.str);
            ((struct Obj00543 *)st)->f18 = 2;
        }
    } else if (n != 0) {
        if (((struct Obj00543 *)st)->f18 != 1) {
            struct Prompt p = {0};

            func_02041B6C(func_021BCEF8_show(((struct Obj00543 *)st)->f2C));
            func_0201F7A8((void *)(((struct Obj00543 *)st)->f2C), 1);
            if (((struct Obj00543 *)st)->f1C != 0) {
                APP_TASKMENU_WIN_Delete((u8 *)(((struct Obj00543 *)st)->f1C));
                ((struct Obj00543 *)st)->f1C = 0;
            }
            p.str = (u32_021BCEF8)func_02045EC0((struct MsgBank *)msgs, 0x12);
            p.color = 0x39e3;
            p.flags = 0;
            ((struct Obj00543 *)st)->f1C = APP_TASKMENU_WIN_Create(sys, (u32_021BCEF8)(&p), 0, 0x15, 0x15, heap);
            STRBUF_Delete((struct U16Vec *)p.str);
            ((struct Obj00543 *)st)->f18 = 1;
        }
    } else if (((struct Obj00543 *)st)->f18 != 0) {
        if (((struct Obj00543 *)st)->f1C != 0) {
            APP_TASKMENU_WIN_Delete((u8 *)(((struct Obj00543 *)st)->f1C));
            ((struct Obj00543 *)st)->f1C = 0;
        }
        if (st[0x14] != 0)
            func_021BD0C4(ctx, (char *)st, 0x11);
        ((struct Obj00543 *)st)->f18 = 0;
    }
}






static inline u8 func_021BD038_show(u32_021BD038 win)
{
    BMP_WIN_ClearScreen((struct Descriptor *)win);
    return BMP_WIN_GetBgLayer((struct Descriptor *)win);
}






void func_021BD038(void *ctx, char *st)
{
    if (((struct Obj01266 *)st)->f14 == ((struct Obj01266 *)st)->f15)
        return;
    if (((struct Obj01266 *)st)->f14 == 0) {
        func_021BD134(ctx, st, 0x1c);
        ((struct Obj01266 *)st)->f38 = 1;
        func_02041B6C(func_021BD038_show(((struct Obj01266 *)st)->f2C));
        func_0201F7A8((void *)(((struct Obj01266 *)st)->f2C), 1);
    } else if (((struct Obj01266 *)st)->f15 == 0 && ((struct Obj01266 *)st)->f14 != 0) {
        func_021BD0C4(ctx, st, 0x11);
        func_021BE34C(ctx);
        func_0201F7A8((void *)(((struct Obj01266 *)st)->f30), 1);
        func_020409B4(func_021BD038_show(((struct Obj01266 *)st)->f30));
    }
    ((struct Obj01266 *)st)->f15 = ((struct Obj01266 *)st)->f14;
}






int func_021BD0A4(void *ctx, u32_021BD0A4 unused, u32_021BD0A4 a, u32_021BD0A4 b, u32_021BD0A4 c)
{
    return func_02009D50((struct Sub020097BCObj *)func_0201283C((const struct BigObj *)(*((u32_021BD0A4 *)func_021BE004(ctx)))), (const void *)a, b, c, 0);
}




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(u32_021BD1AC *)(self + (o)))




#undef B



#undef B


#undef B

#undef B
#define B(o) (*(u8 *)(self + (o)))






void func_021BD0C4(void *a0, char *a1, int a2)
{
    u32_021BD0C4 x = func_021BE034(a0);
    u32_021BD0C4 y = func_021BE03C(a0);
    u32_021BD0C4 z = func_021BE044(a0);
    u32_021BD0C4 w;

    BMP_Clear((struct CharBuf *)((u32_021BD0C4)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00543 *)a1)->f2C)), 0xf);
    w = (u32_021BD0C4)func_02045EC0((struct MsgBank *)y, a2);
    PRINTSYS_PrintQueColor((void *)z, BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00543 *)a1)->f2C), 0, 0, (void *)w, x, 0x440);
    STRBUF_Delete((struct U16Vec *)w);
    func_0201F73C((void *)(((struct Obj00543 *)a1)->f2C), 2, 0x140, 9);
    ((struct Obj00543 *)a1)->f20 = 1;
}






void func_021BD134(void *ctx, char *st, u32_021BD134 msgId)
{
    u32_021BD134 font = func_021BE034(ctx);
    u32_021BD134 msgs = func_021BE03C(ctx);
    u32_021BD134 sys = func_021BE044(ctx);
    u32_021BD134 str;

    BMP_Clear((struct CharBuf *)((u32_021BD134)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01266 *)st)->f30)), 0xf);
    str = (u32_021BD134)func_02045EC0((struct MsgBank *)msgs, msgId);
    PRINTSYS_PrintQueColor((void *)sys, BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01266 *)st)->f30), 0, 0, (void *)str, font, 0x440);
    STRBUF_Delete((struct U16Vec *)str);
    func_0201F73C((void *)(((struct Obj01266 *)st)->f30), 2, 0x140, 9);
    ((struct Obj01266 *)st)->f24 = 1;
    ((struct Obj01266 *)st)->f38 = 0;
    func_021BE34C(ctx);
}




#undef H



#undef H


#undef H

#undef H

#define H(o) (*(u16 *)(self + (o)))





/*
 * note 2026-10-05 wD5 lane12: the loop argument and the two byte stores are the literal 0 (the
 *   original copies r5=0 into r6 before the loop label; it is not the last index).
 */
void func_021BD1AC(char *self)
{
    int z = 0;
    int one = 1;
    u8 i;
    u32_021BD1AC h2;
    Params st;
    B(0x18) = one;
    B(0x19) = z;
    W(0x1c) = z;
    func_021BD5D8((u8 *)self);
    func_021BD844((u8 *)self);
    func_021BDBC4((u8 *)self);
    W(0x1d4) = (u32_021BD1AC)APP_TASKMENU_RES_Create(4, 7, W(0x1c8), W(0x1d0), H(0));
    W(0x1e0) = (u32_021BD1AC)func_021B6EE0(self, H(0));
    W(0x1e4) = (u32_021BD1AC)func_021B7BA8(self, H(0));
    W(0x1e8) = (u32_021BD1AC)func_021B8C3C(self, H(0));
    W(0x1ec) = (u32_021BD1AC)func_021BA280(self, H(0));
    W(0x1f0) = (u32_021BD1AC)func_021BBA6C((int)self, (void *)H(0));
    st.heap = H(0);
    st.kind = 2;
    st.count = 0x64;
    st.a = z;
    st.b = 0x100;
    st.c = z;
    st.d = 0xc0;
    W(0x1f4) = func_021B6BE0(&st);
    W(4) = func_020056A0(func_021BD5AC, self, 8);
    W(8) = z;
    H(0x38) = z;
    H(0x3a) = z;
    W(0x10) = one;
    W(0x20) = z;
    W(0x24) = z;
    W(0x28) = z;
    W(0x2c) = z;
    W(0x30) = z;
    W(0x34) = z;
    if (func_0202EB14() == 1) W(0x30) = one;
    GFL_NET_RestartWithDefaultTimeout(0, H(0));
    switch (*(u32_021BD1AC *)(W(0x1f8) + 4)) {
    case 0:
        func_021B80DC((int)self, (char *)W(0x1e4), 3);
        W(0xc) = 1;
        break;
    case 1:
        func_021B80DC((int)self, (char *)W(0x1e4), 2);
        W(0xc) = 2;
        break;
    case 2:
        func_021B80DC((int)self, (char *)W(0x1e4), 4);
        func_021B80EC((int)self, (char *)W(0x1e4), (const u8 *)(W(0x1f8) + 8));
        W(0xc) = 2;
        func_02028A70((struct SoundSys *)func_02012A30((const struct BigObj *)(*(u32_021BD1AC *)W(0x1f8))));
        break;
    case 3:
        func_021B80DC((int)self, (char *)W(0x1e4), 5);
        W(0xc) = 2;
        break;
    }
    W(0x1b8) = BMP_WIN_Create(0, 2, 10, 12, 2, 10, 1);
    W(0x1bc) = BMP_WIN_Create(0, 0x12, 10, 12, 2, 10, 1);
    W(0x1c0) = BMP_WIN_Create(0, 2, 0x16, 12, 2, 10, 1);
    W(0x1c4) = BMP_WIN_Create(0, 0x12, 0x16, 12, 2, 10, 1);
    for (i = 0; i < 4; i++) {
        BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)(*(u32_021BD1AC *)(self + i * 4 + 0x1b8))), 0);
    }
    B(0x1b4) = 0;
    B(0x1b5) = 0;
    GFL_USE_CancelChangeAndPlayBgm(0x3e9, 0xffff);
}





void func_021BD3B8(u8 *p)
{
    u8 i;
    for (i=0; i<4; i++) BMP_WIN_Delete((struct Descriptor *)(*(u32_021BD3B8 *)(p + i*4 + 0x1b8)));
    func_02030EAC((struct Node *)(((struct Obj03855 *)p)->f4));
    func_021B6C34(*(char * *)&((struct Obj03855 *)p)->f1F4);
    func_021BBA88((int)p, ((struct Obj03855 *)p)->f1F0);
    func_021BA2B8((int)p, ((struct Obj03855 *)p)->f1EC);
    func_021B8CB0(p, *(char * *)&((struct Obj03855 *)p)->f1E8);
    func_021B7DCC(p, (char *)(((struct Obj03855 *)p)->f1E4));
    func_021B70A8((int)p, (char *)(((struct Obj03855 *)p)->f1E0));
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(((struct Obj03855 *)p)->f1D4));
    func_021BDC70((u32_021BD3B8 *)p);
    func_021BDB5C(p);
    func_021BD7D0(p);
}





#undef H




#undef H



#undef H


#undef H

#undef H
#define H(o) (*(u16 *)(ctx + (o)))






int func_021BD43C(char *ctx)
{
    u32_021BD43C idx;
    s32 v;
    u8 pal;

    func_021B7E34(ctx, (char *)F(0x1e4));
    switch (F(8)) {
    case 1:
        F(0xc) = func_021B9044(ctx, (struct S *)F(0x1e8));
        break;
    case 2:
        F(0xc) = func_021BBF2C(ctx, (char *)F(0x1f0));
        break;
    case 3:
        F(0xc) = func_021BA9EC(ctx, (char *)F(0x1ec));
        break;
    case 4:
        if (func_021B80CC((int)ctx, (char *)F(0x1e4)) == 1 && func_021B7590((int)ctx, (char *)F(0x1e0)) == 1) {
            return 1;
        }
        return 0;
    case 5:
        if (func_021B80CC((int)ctx, (char *)F(0x1e4)) == 1 && func_021B7590((int)ctx, (char *)F(0x1e0)) == 1
            && WIPE_SYS_EndCheck() == 1) {
            return 1;
        }
        break;
    }
    if (F(0x14) == 1 && WIPE_SYS_EndCheck() == 1) {
        F(0xc) = 5;
    }
    if (F(8) != F(0xc)) {
        func_021BDCB8((u8 *)ctx);
    }
    func_021B712C((int)ctx, (char *)F(0x1e0));
    func_021B6C48(F(0x1f4));
    CLACT_DrawSystem();
    PRINTSYS_QUE_Main((struct PrintSys *)F(0x1d0));
    func_021BDD6C((u8 *)ctx);
    H(0x38) += 0x200;
    idx = H(0x38) >> 4;
    v = (FX_SinCosTable_[idx * 2] + 0x1000) / 2 * 10;
    pal = (u8)(u32_021BD43C)((float)v / 4096.0f);
    if (pal >= 10) {
        pal = 9;
    }
    if (pal != H(0x3a)) {
        H(0x3a) = pal;
        NNS_GfdRegisterNewVramTransferTask((void *)0x1f, 0x40, (u32_021BD43C)(ctx + 0x3c + pal * 32), 0x20);
    }
    TCBL_Main((struct Tcbl *)F(0x1d8));
    sub_02040618(1, 0, func_02005728(0x100));
    sub_02040618(1, 3, func_02005728(0x100));
    return 0;
}






void func_021BD5AC(int unused, char *ctx)
{
    func_021B71B8(ctx, (struct Q *)(((struct Obj10666 *)ctx)->f1E0));
    CLACT_VBlankSystem();
    func_021B6C4C((char *)(((struct Obj10666 *)ctx)->f1F4));
    func_021B9574((int)ctx, (char *)(((struct Obj10666 *)ctx)->f1E8));
}



static inline void inside0(int wnd, int effect)
{
    u32 tmp;
    tmp = (WININ & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    WININ = (u16)tmp;
}



static inline void inside1(int wnd, int effect)
{
    u32 tmp;
    tmp = (WININ & ~0x3f00) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    WININ = (u16)tmp;
}



static inline void outside(int wnd, int effect)
{
    u32 tmp;
    tmp = (WINOUT & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    WINOUT = (u16)tmp;
}




void func_021BD5D8(u8 *p)
{
    u32 size;
    u32 mode;
    struct Bank *bank;
    Cfg7 cfg;

    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FF;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FF;
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000304 |= 0x8000;
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C7120);
    func_0203F8F4(*(u16 *)p);
    BMP_WIN_Init(*(u16 *)p);
    func_0203FC28((struct DispConfig *)d_021C7050);
    func_021BD820((const struct BgTemplate *)d_021C70A0, 0, 0);
    func_021BD820((const struct BgTemplate *)d_021C7100, 1, 0);
    func_021BD820((const struct BgTemplate *)d_021C70C0, 4, 0);
    func_021BD820((const struct BgTemplate *)d_021C70E0, 5, 0);
    func_021BD820((const struct BgTemplate *)d_021C7080, 6, 0);
    func_021BD820((const struct BgTemplate *)d_021C7060, 7, 0);
    *(volatile u16 *)0x0400000C = (*(volatile u16 *)0x0400000C & 0x43) | 0x4484;
    *(volatile u16 *)0x0400000E = (*(volatile u16 *)0x0400000E & 0x43) | 0x4A84;
    size = 0x18000;
    MI_CpuFill8(func_0207E008(), 0, size);
    MI_CpuFill8((void *)func_0207E100(), 0, size);
    *(volatile u16 *)0x0400000C = (*(volatile u16 *)0x0400000C & ~3) | 1;
    *(volatile u16 *)0x0400000E = (*(volatile u16 *)0x0400000E & ~3) | 2;
    func_02040588(2, 1);
    mode = 3;
    func_02040588(mode, 1);
    cfg = gClActorInitParam;
    CLACT_InitSystem((const struct Cfg *)(&cfg), (u32)d_021C7120, *(u16 *)p);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    bank = CLACT_CreateUnit(0x40, 0, *(u16 *)p);
    *(struct Bank **)(p + 0x1AC) = bank;
    CLACT_SetUnitDefaultRenderer(bank);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFFF1FFF) | (mode << 13);
    inside0(0x1f, 1);
    inside1(0x1f, 1);
    outside(0x13, 1);
    *(volatile u16 *)0x04000040 = 0xff;
    *(volatile u16 *)0x04000044 = 0xc0;
    *(volatile u16 *)0x04000042 = 0x20 << 10;
    *(volatile u16 *)0x04000046 = 0xc0;
}

#undef W

#define W(o) (*(u32 *)(p + (o)))








/*
 * Masks the display control word down to 0xffff1fff, hands the +0x1ac handle to
 * the two release probes and then drops priorities 7,6,5,4,1,0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD7D0(void *a0)
{
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    CLACT_ExitSystem(CLACT_DeleteUnit((struct Bank *)(((struct Obj24105 *)a0)->f1AC)));
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(1);
    func_020403F4(0);
    BMP_WIN_Exit();
    func_0203F9B4();
}








void func_021BD820(const struct BgTemplate *tmpl, u32 bgId, u32 type)
{
    func_0203FCA0(bgId, tmpl, type);
    func_02040588(bgId, 1);
    func_020414AC(bgId);
    func_020409B4(bgId);
}






void func_021BD844(u8 *p)
{
    struct Sub0200852CObj *t;
    void *dev;
    u32 o;
    u32 i0;
    u32 i1;
    u32 i2;
    int z;
    struct CellCfg cfg;
    struct PltData *pal;
    t = (struct Sub0200852CObj *)func_02012944(*(void **)W(0x1f8));
    BG = func_020490F4(0xac, HEAP);
    if (func_02008550(t) == 0) {
        func_02049B68(BG, 7, 4, 0, 0xc0, HEAP);
    } else {
        func_02049B68(BG, 6, 4, 0, 0xc0, HEAP);
    }
    z = 0;
    func_02049658(BG, 0xb, 7, 0, z, z, HEAP);
    func_020498F4(BG, 0xe, 7, 0, z, z, HEAP);
    func_020409B4(7);
    func_02049B68(BG, 0, 0, 0x20, 0x20, HEAP);
    func_02049658(BG, 8, 1, 0, z, z, HEAP);
    func_020498F4(BG, 0xd, 1, 0, z, z, HEAP);
    func_020409B4(1);
    W(0x180) = CLACT_RegisterPaletteCompressed(BG, 3, 0, 0, HEAP);
    W(0x190) = CLACT_RegisterCharacter(BG, 0x18, 0, 0, HEAP);
    W(0x1a0) = CLACT_RegisterCellAnim(BG, 0x14, 0x16, HEAP);
    W(0x184) = CLACT_RegisterPaletteCompressed(BG, 3, 1, 0, HEAP);
    W(0x194) = CLACT_RegisterCharacter(BG, 0x17, 0, 1, HEAP);
    W(0x1a4) = CLACT_RegisterCellAnim(BG, 0x13, 0x15, HEAP);
    dev = func_020490F4(func_020275E4(), HEAP);
    func_02049B68(dev, func_02027624(), 0, 0, 0x20, HEAP);
    func_02049658(dev, func_02027628(), 0, 0, z, z, HEAP);
    func_02049B68(dev, func_02027624(), 4, 0xc0, 0x20, HEAP);
    func_02049658(dev, func_02027628(), 5, z, z, z, HEAP);
    func_020498F4(dev, func_0202762C(), 5, z, z, z, HEAP);
    func_020413B0(5, z, 0x15, 0x20, 3, 6);
    func_020409B4(5);
    W(0x18c) = CLACT_RegisterPaletteEx(dev, func_02027614(), z, 0xe0, z, 3, HEAP);
    W(0x19c) = CLACT_RegisterCharacter(dev, func_02027618(), z, z, HEAP);
    W(0x188) = CLACT_RegisterPaletteEx(dev, func_02027614(), 1, 0xe0, z, 3, HEAP);
    W(0x198) = CLACT_RegisterCharacter(dev, func_02027618(), z, 1, HEAP);
    W(0x1a8) = CLACT_RegisterCellAnim(dev, func_0202761C(2), func_02027620(2), HEAP);
    ARC_TOOL_DeleteHandle(dev);
    cfg.a = z;
    cfg.b = z;
    cfg.c = z;
    cfg.d = z;
    cfg.e = z;
    o = func_021BE024(p);
    i0 = func_021BE018(p, 4);
    i1 = func_021BE018(p, z);
    i2 = func_021BE018(p, 8);
    W(0x1b0) = (u32)CLACT_CreateActor((void *)o, i0, i1, i2, &cfg, z, HEAP);
    CLACT_SetActorDrawEnable((void *)W(0x1b0), z);
    CLACT_SetActorAutoAnim((void *)W(0x1b0), 1);
    if (func_02008550(t) == 0) {
        dev = func_02049F78(BG, 7, (u32)(&pal), HEAP);
    } else {
        dev = func_02049F78(BG, 6, (u32)(&pal), HEAP);
    }
    func_02082A90(pal->raw + 0xc0, p + 0x3c, 0x140);
    func_020307B0(dev);
}





void func_021BDB5C(u8 *p)
{
    u8 i;
    CLACT_DeleteActor((struct Obj *)(((struct Obj14310 *)p)->f1B0));
    for (i = 0; i < 4; i++) CLACT_ReleasePalette(*(u32 *)(p + i * 4 + 0x180));
    for (i = 4; i < 8; i++) CLACT_ReleaseCharacter(*(u32 *)(p + i * 4 + 0x180));
    for (i = 8; i < 11; i++) CLACT_ReleaseCellAnim(*(u32 *)(p + i * 4 + 0x180));
    ARC_TOOL_DeleteHandle((void *)(((struct Obj14310 *)p)->f17C));
}





/*
 * Extent remainder: zero alignment halfword at 021BDC6E.
 */
void func_021BDBC4(u8 *p)
{
    ((struct Obj01758 *)p)->f1C8=(u32)GF_FONT_Create(23,0,0,0,((struct Obj01758 *)p)->f0);
    ((struct Obj01758 *)p)->f1CC=(u32)func_02045B38(0,2,27,((struct Obj01758 *)p)->f0);
    ((struct Obj01758 *)p)->f1D0=(u32)PRINTSYS_QUE_CreateEx(0x800,((struct Obj01758 *)p)->f0);
    func_02049B40(23,5,0,0x140,32,((struct Obj01758 *)p)->f0);
    func_02049B40(23,5,4,0x140,32,((struct Obj01758 *)p)->f0);
    func_0201DD68();
    func_0201F5BC(4,0x140,9,0,((struct Obj01758 *)p)->f0);
    func_0201F5BC(0,0x200,9,0,((struct Obj01758 *)p)->f0);
    ((struct Obj01758 *)p)->f1D8=(u32)TCBL_Create(((struct Obj01758 *)p)->f0,((struct Obj01758 *)p)->f0,1,0);
    ((struct Obj01758 *)p)->f1DC=0;
}






void func_021BDC70(u32 *a0)
{
    u32 i;
    u32 v;

    i = 0x77;
    v = a0[i];
    if (v != 0) {
        TIME_ICON_Delete((u8 *)v);
        a0[i] = 0;
    }
    i = 0x76;
    TCBL_Destroy((struct S02031140 *)a0[i]);
    PRINTSYS_QUE_Clear((struct PrintSys *)a0[i - 2]);
    PRINTSYS_QUE_Delete((struct PrintSys *)a0[i - 2]);
    MSGDATA_Delete((struct Rec *)a0[i - 3]);
    GF_FONT_Delete((void *)a0[i - 4]);
}




void func_021BDCB8(u8 *p)
{
    switch (*(u32 *)(p+8)) {
    case 1: func_021B8FB8(p,*(char **)(p+0x1e8)); break;
    case 2: func_021BBE5C(p,*(char **)(p+0x1f0)); break;
    case 3: func_021BA8C4((u16 *)p,*(char **)(p+0x1ec)); break;
    }
    *(u32 *)(p+8)=*(u32 *)(p+12);
    switch (*(u32 *)(p+8)) {
    case 0: break;
    case 1: func_021B8CC8(p,*(char **)(p+0x1e8)); break;
    case 2: func_021BBA94(p,(u8 *)(*(char **)(p+0x1f0))); break;
    case 3: func_021BA2C4(p,(u8 *)(*(char **)(p+0x1ec))); break;
    case 5:
        WIPE_SetBrightnessFadeOut(0,0);
        WIPE_SetBrightnessFadeOut(1,0);
    case 4:
        func_021B8084(p,*(char **)(p+0x1e4));
        func_021B7578((int)p,*(char **)(p+0x1e0));
        func_021B7B80((int)p,*(char **)(p+0x1e0));
        break;
    }
}




void func_021BDD6C(u8 *p)
{
    u8 i;
    u32 found;
    u32 r;
    u32 m;
    u32 b;
    u32 w;
    found = 0;
    if (((struct Obj02215 *)p)->f8 == 3) {
        return;
    }
    r = func_021BE05C(p);
    for (i = found; i < 4; i++) {
        if (func_021B8BA4((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i) != 1) continue;
        if (func_021B8B8C((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i) != 1) continue;
        if (func_021B7B30((int)p, *(char * *)&((struct Obj02215 *)p)->f1E0, i) != 0) continue;
        m = 1 << i;
        if (m & p[0x1b4]) continue;
        {
            char *k = func_021B8B94((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i);
            if (r == 1) {
                if (i == 0) b = 2; else b = 3;
            } else {
                b = i;
            }
            func_021BDEF0(p, k, *(u32 *)(p + b * 4 + 0x1b8));
        }
        p[0x1b4] += (u8)m;
        p[0x1b5] += (u8)(1 << b);
    }
    for (i = 0; i < 4; i++) {
        m = 1 << i;
        if (!(p[0x1b5] & m)) continue;
        if (PRINTSYS_QUE_IsExistTarget(((struct Obj02215 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p + i * 4 + 0x1b8))) != 0) continue;
        w = *(u32 *)(p + i * 4 + 0x1b8);
        BMP_WIN_TransferChars((struct Descriptor *)w);
        BMP_WIN_MakeScreen((struct Cfg *)w);
        func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)w));
        p[0x1b5] -= (u8)m;
        found = 1;
    }
    if (found == 1) {
        u8 v = func_021B8B68((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4);
        if (v != 0xff) {
            func_021BE210((char *)p, v);
        }
    }
}




void func_021BDEF0(u8 *p, char *a, u32 b)
{
    void *s;
    int x;
    s = func_02008510(a, ((struct Obj02216 *)p)->f0);
    x = (0x60 - (u8)func_0201D304(s, ((struct Obj02216 *)p)->f1C8, 0)) / 2;
    PRINTSYS_PrintQueColor((void *)((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x + 1, 1, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    PRINTSYS_PrintQueColor((void *)((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x - 1, 1, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    PRINTSYS_PrintQueColor((void *)((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x, 2, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    PRINTSYS_PrintQueColor((void *)((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x, 0, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    PRINTSYS_PrintQueColor((void *)((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x, 1, s, ((struct Obj02216 *)p)->f1C8, 0x3c00);
    STRBUF_Delete(s);
}





u32 func_021BDFDC(void *p)
{
    return ((struct Obj24107 *)p)->f1E0;
}





/*
 * Field getter, u32 at +0x1e4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BDFE4(void *p)
{
    return ((struct Obj24108 *)p)->f1E4;
}





/*
 * Tail call to func_021B9F98, second argument the field at +0x1e8.
 *
 * Addresses are Black-image addresses.
 *
 * evidence: func_021B9F98 is ov172's own code ("ldr r0, [r1, #0x10]; bx lr"
 * after the pop at 0x021B9F94), inside ov172's window, so only ov172 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov172's own listing.
 */
int func_021BDFEC(void *p)
{
    return func_021B9F98((int)p, (int *)(((struct Obj24109 *)p)->f1E8));
}





/*
 * Field getter, u32 at +0x1f4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BDFFC(void *p)
{
    return ((struct Obj24110 *)p)->f1F4;
}





/*
 * Field getter, u32 at +0x1f8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE004(void *p)
{
    return ((struct Obj24111 *)p)->f1F8;
}





/*
 * Field getter, u16 at +0.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021BE00C(u16 *p)
{
    return *p;
}





u32 func_021BE010(void *p)
{
    return ((struct Obj24113 *)p)->f17C;
}





/*
 * Field getter, u32 at +0x180 of element i (stride 4).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE018(void *p, int i)
{
    return *(u32 *)((char *)p + i * 4 + 0x180);
}





/*
 * Field getter, u32 at +0x1ac.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE024(void *p)
{
    return ((struct Obj24114 *)p)->f1AC;
}




u32 func_021BE02C(void *p)
{
    return ((struct Obj24115 *)p)->f10;
}




void func_021BE030(void *p, u32 v)
{
    ((struct Obj24116 *)p)->f10 = v;
}





/*
 * Field getter, u32 at +0x1c8.
 *
 * Addresses are Black-image addresses.
 */
u32_021BCC40 func_021BE034(void *p)
{
    return ((struct Obj24117 *)p)->f1C8;
}





u32_021BCC40 func_021BE03C(void *p)
{
    return ((struct Obj24118 *)p)->f1CC;
}





/*
 * Field getter, u32 at +0x1d0.
 *
 * Addresses are Black-image addresses.
 */
u32_021BCC40 func_021BE044(void *p)
{
    return ((struct Obj24119 *)p)->f1D0;
}





/*
 * Field getter, u32 at +0x1d4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE04C(void *p)
{
    return ((struct Obj24120 *)p)->f1D4;
}





/*
 * Field getter, u8 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021BE054(void *p)
{
    return ((struct Obj24121 *)p)->f18;
}





/*
 * Set the u8 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE058(void *p, u32 v)
{
    ((struct Obj24122 *)p)->f18 = v;
}





/*
 * 1 for states 1 and 2, else 2.
 *
 * Addresses are Black-image addresses.
 */
int func_021BE05C(void *p)
{
    u8 v = func_021BE054(p);
    if (v == 1) {
        return 1;
    }
    if (v == 2) {
        return 1;
    }
    return 2;
}





u32 func_021BE078(void *p)
{
    return ((struct Obj24123 *)p)->f1C;
}




void func_021BE07C(u32 *p, u32 v)
{
    func_021B8720(p, (u32 *)p[0x79], v);
}





/*
 * Tail call passing the inverted flag at +0x1c as the second argument.
 *
 * Addresses are Black-image addresses.
 *
 * evidence: func_021BE07C is ov172's own code (a tail call to func_021B8720
 * right after func_021BE078's bx lr), inside ov172's window, so only ov172
 * can be resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov172's own listing.
 */
void func_021BE08C(void *p)
{
    u32 v = ((struct Obj24125 *)p)->f1C;
    if (v == 0) {
        v = 1;
    } else {
        v = 0;
    }
    func_021BE07C(p, v);
}




void func_021BE0A0(void *p, u32 v)
{
    ((struct Obj24126 *)p)->f1C = v;
}





/*
 * Field getter, u8 at +0x19.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE0A4(void *p)
{
    return ((struct Obj24127 *)p)->f19;
}




/*
 * Set the u8 at +0x19.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE0A8(void *p, u32_021BE0A8 v)
{
    ((struct Obj24128 *)p)->f19 = v;
}




/*
 * Field getter, u32 at +0x20.
 *
 * Addresses are Black-image addresses.
 */
u32_021BE0AC func_021BE0AC(void *p)
{
    return ((struct Obj24129 *)p)->f20;
}




/*
 * Set the u32 at +0x20.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE0B0(void *p, u32_021BE0B0 v)
{
    ((struct Obj24130 *)p)->f20 = v;
}




/*
 * Field getter, u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
u32_021BE0B4 func_021BE0B4(void *p)
{
    return ((struct Obj24131 *)p)->f24;
}




/*
 * Invert the flag at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE0B8(void *p)
{
    u32_021BE0B8 v = ((struct Obj14311 *)p)->f24;
    if (v == 0) {
        v = 1;
    } else {
        v = 0;
    }
    ((struct Obj14311 *)p)->f24 = v;
}




/*
 * Field getter, u32 at +0x28.
 *
 * Addresses are Black-image addresses.
 */
u32_021BE0C8 func_021BE0C8(void *p)
{
    return ((struct Obj24132 *)p)->f28;
}



void func_021BE0CC(void *p, u32_021BE0CC v)
{
    ((struct Obj24133 *)p)->f28 = v;
}




u32_021BE0D0 func_021BE0D0(void *p)
{
    return ((struct Obj24134 *)p)->f2C;
}




void func_021BE0D4(void *p, u32_021BE0D4 v)
{
    ((struct Obj24135 *)p)->f2C = v;
}




/*
 * Test word 1 of the object behind +0x1f8 against 3.
 *
 * Addresses are Black-image addresses.
 */
int func_021BE0D8(void *p)
{
    void *q = ((struct Obj24136 *)p)->f1F8;
    if (((struct Obj24137 *)q)->f4 == 3) {
        return 1;
    }
    return 0;
}




u32_021BE0EC func_021BE0EC(void *p)
{
    return ((struct Obj24138 *)p)->f30;
}




void func_021BE0F0(u8 *c)
{
    *(u32_021BE0F0 *)(c + 0x30) = 0;
}




/*
 * Field getter, u32 at +0x34.
 *
 * Addresses are Black-image addresses.
 */
u32_021BE0F8 func_021BE0F8(void *p)
{
    return ((struct Obj24139 *)p)->f34;
}




/*
 * Set the u32 at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE0FC(void *p, u32_021BE0FC v)
{
    ((struct Obj24140 *)p)->f34 = v;
}




int func_021BE100(void)
{
    if (sub_0202EB0C() == 1 && unit_0202EB14() == 0) {
        return 1;
    }
    return 0;
}



u32_021BE11C func_021BE11C(u8 *p)
{
    Descriptor x={0};
    Item items[2]={0};
    u32_021BE11C result;
    items[0].handle=(u32_021BE11C)func_02045EC0((struct MsgBank *)(((struct Obj08262 *)p)->f1CC),34);
    items[1].handle=(u32_021BE11C)func_02045EC0((struct MsgBank *)(((struct Obj08262 *)p)->f1CC),35);
    items[0].value=14819;
    items[1].value=14819;
    items[0].zero=0;
    items[1].zero=0;
    x.heap=((struct Obj08262 *)p)->f0;
    x.count=2;
    x.items=items;
    x.a=24;
    x.b=6;
    x.c=8;
    x.d=3;
    x.zero=0;
    result=(u32_021BE11C)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&x),(void *)(((struct Obj08262 *)p)->f1D4));
    STRBUF_Delete((struct U16Vec *)items[0].handle);
    STRBUF_Delete((struct U16Vec *)items[1].handle);
    return result;
}




/*
 * Releases the four +0x1b8 slots and clears the two +0x1b4 bytes.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE1A4(char *p)
{
    u8 i;

    p[0x1b4] = 0;
    p[0x1b5] = 0;
    for (i = 0; i < 4; i++) {
        BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)*(u32_021BE1A4 *)(p + i * 4 + 0x1b8))), 0);
        if (((struct Obj10667 *)p)->f8 != 3) {
            BMP_WIN_ClearScreen((struct Descriptor *)(*(u32_021BE1A4 *)(p + i * 4 + 0x1b8)));
        }
    }
}



void func_021BE1E4(u8 *p)
{
    u8 i;
    for (i = 0; i < 4; i++) {
        BMP_Clear((struct CharBuf *)((u32_021BE1E4)BMP_WIN_GetBmp((struct Descriptor *)*(u32_021BE1E4 *)(p + i * 4 + 0x1b8))), 0);
        BMP_WIN_TransferChars((struct Descriptor *)*(u32_021BE1E4 *)(p + i * 4 + 0x1b8));
    }
}



/*
 * Places a slot marker: k = idx (2 or 3 for slots 0/1 in mode 1), checks the slot with
 * func_021B8BA4 and func_021B8B8C, then sets the sprite position from the xv/yv byte tables.
 * idx is a u8 slot index (the sibling func_021BDD6C walks the same slots with a u8 i). The u8
 * parameter is what keeps the third-call idx reload after the byte copies (wD9r lane48).
 */
void func_021BE210(char *a, u8 idx)
{
    struct Pt rc;
    void *h;
    u32_021BE210 v;
    int mode;
    u32_021BE210 k;
    mode = func_021BE05C(a);
    k = idx;
    if (*(int *)(a + 8) == 3) return;
    if (mode == 1) k = (k == 0) ? 2 : 3;
    if (func_021B8BA4((int)a, *(char **)(a + 0x1E4), idx) != 1) return;
    if (func_021B8B8C((int)a, *(char **)(a + 0x1E4), idx) != 1) return;
    rc.xv = d_021C704C;
    rc.yv = d_021C7048;
    h = func_02008510(func_021B8B94((int)a, *(char **)(a + 0x1E4), idx), *(u16 *)a);
    v = (u8)func_0201D304(h, *(u32_021BE210 *)(a + 0x1C8), 0);
    STRBUF_Delete(h);
    { u32_021BE210 xk = rc.xv.b[k]; rc.x = xk + (v >> 1); }
    rc.y = rc.yv.b[k];
    CLACT_AddActorSurfacePos(*(void **)(a + 0x1B0), (const struct Vec2 *)(&rc), 0);
    CLACT_SetActorDrawEnable(*(void **)(a + 0x1B0), 1);
    CLACT_RestartActorAnim(*(void **)(a + 0x1B0));
}




void func_021BE2E0(void *p)
{
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj24141 *)p)->f1B0, 0);
}



void func_021BE2F0(u32_021BE2F0 *p, void *q)
{
    void *l = func_0200ED48((void *)GAME_DATA_GetSaveControl((struct Big *)(*(u32_021BE2F0 *)p[0x7e])));
    func_0200ED54(l, func_02008530(q));
}




/*
 * Rebuilds the +0x1dc record from the +0x1d8 source, retiring the old one first.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE318(char *a0, void *a1)
{
    if (((struct Obj05448 *)a0)->f1DC != 0)
        func_021BE34C(a0);

    ((struct Obj05448 *)a0)->f1DC =
        (u32_021BE318)TIME_ICON_CreateNode(((struct Obj05448 *)a0)->f1D8, (void *)a1, 0xf, 0x10, ((struct Obj05448 *)a0)->f0);
}




void func_021BE34C(void *p)
{
    u32_021BE34C v = ((struct Obj05448 *)p)->f1DC;
    if (v != 0) {
        TIME_ICON_Delete((u8 *)v);
        ((struct Obj05448 *)p)->f1DC = 0;
    }
}



int func_021BE364(struct Obj0203159C *obj,int unused,u8 *arg)
{
    u8 *p;
    if (arg && ((struct Obj24143 *)arg)->f4==3) GFL_HEAP_CreateChildHeap(1,109,0xd0000);
    else GFL_HEAP_CreateChildHeap(1,109,0xe8000);
    p=PROCSYS_AllocProcWork(obj,0x1fc,109);
    ((struct Obj03856 *)p)->f0=109;
    if (arg==0) {
        *(u8 * *)&((struct Obj03856 *)p)->f1F8=func_02030734(1,16,1,(const char *)d_021C724C,1357);
        **(u32_021BE364 * *)&((struct Obj03856 *)p)->f1F8=(u32_021BE364)GAME_DATA_Create(1);
        ((struct Obj24145 *)(*(u8 * *)&((struct Obj03856 *)p)->f1F8))->f4=0;
        if (KEY_GetCont() & 0x100) ((struct Obj24146 *)(*(u8 * *)&((struct Obj03856 *)p)->f1F8))->f4=1;
        if (KEY_GetCont() & 0x400) ((struct Obj24147 *)(*(u8 * *)&((struct Obj03856 *)p)->f1F8))->f4=2;
    } else *(u8 * *)&((struct Obj03856 *)p)->f1F8=arg;
    ((struct Obj03856 *)p)->f14=0;
    func_021BD1AC((char *)p);
    return 1;
}



int func_021BE410(void *a, void *b, int c, u32_021BE410 *p)
{
    func_021BD3B8((u8 *)p);
    if (c == 0) {
        func_020307B0((void *)p[0x7e]);
    }
    func_020315D4(a);
    func_020306F0(0x6d);
    return 1;
}



int func_021BE43C(void *a, void *b, void *c, u32_021BE43C *p)
{
    if (func_0200FB24() != 0 && p[5] == 0) {
        GFL_NET_ERR_RequestScreen();
        p[5] = 1;
    }
    if (func_021BD43C((char *)p) == 1) {
        return 1;
    }
    return 0;
}
