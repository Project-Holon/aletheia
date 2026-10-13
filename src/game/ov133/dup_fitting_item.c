/*
 * file:     dup_fitting_item.c
 * unit:     yes
 * function: func_021B6100, func_021B6294, func_021B63BC, func_021B6884, func_021B69AC, func_021B6BA4, func_021B6E4C, func_021B6E74, func_021B6F00, func_021B7368, func_021B7458, func_021B7498, func_021B75E0, func_021B765C, func_021B7A18, func_021B7A70, func_021B7CFC, func_021B7F00, func_021B7F54, func_021B8140, func_021B8254, func_021B82E8, func_021B8444, func_021B8680, func_021B8930, func_021B8A30, func_021B8AC8, func_021B8B78, func_021B8BB4, func_021B8C6C, func_021B8FA8, func_021B8FF4, func_021B9028, func_021B9118, func_021B918C, func_021B940C, func_021B94C0, func_021B952C, func_021B95AC, func_021B96D8, func_021B9784, func_021B9818, func_021B987C, func_021B98A0, func_021B9990, func_021B9A88, func_021B9AC0, func_021B9B48, func_021B9BD0, func_021B9C08, func_021B9C90, func_021B9CBC, func_021B9D54, func_021B9DE8, func_021B9F24, func_021B9F5C, func_021BA098, func_021BA0C8, func_021BA0CC, func_021BA0F8, func_021BA100, func_021BA124, func_021BA148, func_021BA184, func_021BA188, func_021BA18C, func_021BA19C, func_021BA1D8, func_021BA1EC, func_021BA208, func_021BA20C, func_021BA210, func_021BA214, func_021BA218, func_021BA21C, func_021BA228, func_021BA22C, func_021BA238, func_021BA23C, func_021BA240, func_021BA244, func_021BA248, func_021BA24C, func_021BA250, func_021BA254, func_021BA258, func_021BA25C
 * address:  0x021B6100
 * region:   ov133
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_0200A828 0x0200A828 thumb
 *   func_0200A834 0x0200A834 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   d_021BA600 0x021BA600 data a4
 *   func_020355D8 0x020355D8 arm
 *   func_0200A6F8 0x0200A6F8 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_021F5330 0x021F5330 thumb ov112
 *   func_021F51B0 0x021F51B0 thumb ov112
 *   func_02030EAC 0x02030EAC arm
 *   func_0204ED24 0x0204ED24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020307B0 0x020307B0 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021FD6A4 0x021FD6A4 thumb ov132
 *   func_021F51E8 0x021F51E8 thumb ov112
 *   func_021F51F4 0x021F51F4 thumb ov112
 *   func_021F4990 0x021F4990 thumb ov112
 *   CLACT_DrawSystem 0x0204A600 arm
 *   func_02047964 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   BILLBOARD_Draw 0x0204F7DC arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204152C 0x0204152C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_0204047C 0x0204047C arm
 *   func_0204989C 0x0204989C arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_021F4F10 0x021F4F10 thumb ov112
 *   func_021F4F54 0x021F4F54 thumb ov112
 *   func_021F4F70 0x021F4F70 thumb ov112
 *   func_021F4D74 0x021F4D74 thumb ov112
 *   func_021F4AA4 0x021F4AA4 thumb ov112
 *   func_0204F32C 0x0204F32C arm
 *   BILLBOARD_GetImageTexKey 0x0204F2E4 arm
 *   BILLBOARD_SetImageTexAddr 0x0204F2FC arm
 *   func_0204EDD0 0x0204EDD0 arm
 *   BILLBOARD_AddImageFromVramKeys 0x0204F044 arm
 *   BILLBOARD_ReleaseImageVramIfUsed 0x0204F1A0 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0204044C 0x0204044C arm
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_0204EBD4 0x0204EBD4 arm
 *   d_021BA518 0x021BA518 data a4
 *   d_021BA3F4 0x021BA3F4 data a4
 *   d_021BA40C 0x021BA40C data a4
 *   d_021BA400 0x021BA400 data a4
 *   d_021BA418 0x021BA418 data a4
 *   d_021BA428 0x021BA428 data a4
 *   d_021BA438 0x021BA438 data a4
 *   d_021BA458 0x021BA458 data a4
 *   d_021BA478 0x021BA478 data a4
 *   d_021BA4F8 0x021BA4F8 data a4
 *   d_021BA498 0x021BA498 data a4
 *   d_021BA4B8 0x021BA4B8 data a4
 *   d_021BA4D8 0x021BA4D8 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   d_021BA5C4 0x021BA5C4 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_021F5164 0x021F5164 thumb ov112
 *   func_021F5438 0x021F5438 thumb ov112
 *   func_021F5444 0x021F5444 thumb ov112
 *   func_021F5204 0x021F5204 thumb ov112
 *   func_021F545C 0x021F545C thumb ov112
 *   func_021F5350 0x021F5350 thumb ov112
 *   func_0200A644 0x0200A644 thumb
 *   func_0200A680 0x0200A680 thumb
 *   func_0200A628 0x0200A628 thumb
 *   func_021F48C0 0x021F48C0 thumb ov112
 *   func_021F4B3C 0x021F4B3C thumb ov112
 *   func_021F4B4C 0x021F4B4C thumb ov112
 *   func_021F4EE8 0x021F4EE8 thumb ov112
 *   func_021F4C1C 0x021F4C1C thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4DE0 0x021F4DE0 thumb ov112
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_GetTexVramKey 0x02047388 arm
 *   G3D_SYSTEM_GetPlttVramKey 0x020473B8 arm
 *   G3D_SYSTEM_GetPlttDataAddr 0x020473EC arm
 *   G3D_SYSTEM_GetResourceFile 0x02046F48 arm
 *   G3D_SYSTEM_GetResourceTex 0x02047250 arm
 *   NNS_G3dPlttSetPlttKey 0x0206A124 arm
 *   NNS_G3dPlttLoad 0x0206A12C arm
 *   func_020862F0 0x020862F0 arm
 *   BILLBOARD_AddImageFromArchive 0x0204EFC8 arm
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 *   d_020A8148    0x020A8148 data
 *   d_021BA3E0    0x021BA3E0 data ov133 a4
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021F4D40 0x021F4D40 thumb ov112
 *   func_021F4948 0x021F4948 thumb ov112
 *   BILLBOARD_FreeElem 0x0204F5A8 arm
 *   BILLBOARD_DeleteImage 0x0204F150 arm
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   BILLBOARD_SetElemPos 0x0204F638 arm
 *   BILLBOARD_SetElemScale 0x0204F684 arm
 *   _fdiv 0x0209CE10 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   d_021BA3E4 0x021BA3E4 data
 *   d_021BA3E8 0x021BA3E8 data
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   _fmul 0x0209C77C arm
 *   func_0203F768 0x0203F768 arm
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F4B24 0x021F4B24 thumb ov112
 *   func_021F4EC4 0x021F4EC4 thumb ov112
 *   d_021BA5A0 0x021BA5A0 data a4
 *   _ffltu 0x0209BE04 arm
 *   d_021BA5B8 0x021BA5B8 data a4
 *   func_021F4EA4 0x021F4EA4 thumb ov112
 *   d_021BA588 0x021BA588 data a4
 *   d_021BA568 0x021BA568 data a4
 *   func_021F50F4 0x021F50F4 thumb ov112
 *   d_021BA570 0x021BA570 data a4
 *   func_021F4F04 0x021F4F04 thumb ov112
 *   d_021BA57C 0x021BA57C data a4
 *   d_021BA5AC 0x021BA5AC data a4
 *   func_021F4AF0 0x021F4AF0 thumb ov112
 *   func_021F4E2C 0x021F4E2C thumb ov112
 *   func_021F4B10 0x021F4B10 thumb ov112
 *   func_021F4AFC 0x021F4AFC thumb ov112
 *   _ffixu 0x0209C4C8 arm
 *   _fgr 0x0209BBB0 arm
 *   _ll_mul 0x0209C054 arm
 *   FX_Sqrt 0x0207C7B4 arm
 *   FX_Atan2Idx 0x0207CFB8 arm
 *   func_02040618 0x02040618 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   FX_SinCosTable__Alt 0x020A1B38 data
 *   d_021BA594 0x021BA594 data ov133 a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021BA324 0x021BA324 thumb ov133
 *   func_0207CFB8 0x0207CFB8 arm
 *   func_0200A604 0x0200A604 thumb
 *   func_020413B0 0x020413B0 arm
 *   a1 0x021BA558 data a4
 *   b1 0x021BA560 data a4
 *   a2 0x021BA550 data a4
 *   b2 0x021BA548 data a4
 *   table 0x020A1B38 data a2
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_0201F5BC 0x0201F5BC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   func_021F5158 0x021F5158 thumb ov112
 *   func_0201EE0C 0x0201EE0C thumb
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   func_020416D4 0x020416D4 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   d_021BA610 0x021BA610 data a4
 *   func_021F4EFC 0x021F4EFC thumb ov112
 *   func_021F4EE0 0x021F4EE0 thumb ov112
 */
#include "../../matched/include/Obj01941.h"
#include "../../matched/include/Obj23308.h"
#include "../../matched/include/Obj02852.h"
#include "../../matched/include/Obj00777.h"
#include "../../matched/include/Obj00004.h"
#include "../../matched/include/Obj06496.h"
#include "../../matched/include/Obj00220.h"
#include "../../matched/include/Obj23311.h"
#include "../../matched/include/Obj04522.h"
#include "../../matched/include/Obj00004.h"
#include "../../matched/include/Obj06497.h"
#include "../../matched/include/Obj23312.h"
#include "../../matched/include/Obj14149.h"
#include "../../matched/include/Obj06498.h"
#include "../../matched/include/Obj23314.h"
#include "../../matched/include/Obj06499.h"
#include "../../matched/include/Obj03825.h"
#include "../../matched/include/Obj10571.h"
#include "../../matched/include/Obj05409.h"
#include "../../matched/include/Obj23317.h"
#include "../../matched/include/Obj23318.h"
#include "../../matched/include/Obj23319.h"
#include "../../matched/include/Obj23320.h"
#include "../../matched/include/Obj23321.h"
#include "../../matched/include/Obj23322.h"
#include "../../matched/include/Obj23323.h"
#include "../../matched/include/Obj06500.h"
#include "../../matched/include/Obj03826.h"
#include "../../matched/include/Obj00228.h"
#include "../../matched/include/Obj02197.h"
#include "../../matched/include/Obj06501.h"
#include "../../matched/include/Obj23324.h"
#include "../../matched/include/Obj23325.h"
#include "../../matched/include/Obj14153.h"
#include "../../matched/include/Obj01062.h"
#include "../../matched/include/Obj14154.h"
#include "../../matched/include/Obj06502.h"
#include "../../matched/include/Obj10572.h"
#include "../../matched/include/Obj06503.h"
#include "../../matched/include/Obj04523.h"
#include "../../matched/include/Obj05410.h"
#include "../../matched/include/Obj23326.h"
#include "../../matched/include/Obj03827.h"
#include "../../matched/include/Obj14155.h"
#include "../../matched/include/Obj06504.h"
#include "../../matched/include/Obj06505.h"
#include "../../matched/include/Obj23327.h"
#include "../../matched/include/Obj23328.h"
#include "../../matched/include/Obj14156.h"
#include "../../matched/include/Obj14157.h"
#include "../../matched/include/Obj23329.h"
#include "../../matched/include/Obj14158.h"
#include "../../matched/include/Obj14159.h"
#include "../../matched/include/Obj23330.h"
#include "../../matched/include/Obj23331.h"
#include "../../matched/include/Obj23332.h"
#include "../../matched/include/Obj23333.h"
#include "../../matched/include/Obj23334.h"
#include "../../matched/include/Obj23335.h"
#include "../../matched/include/Obj23336.h"
#include "../../matched/include/Obj23337.h"
#include "../../matched/include/Obj23338.h"
#include "../../matched/include/Obj23339.h"
#include "../../matched/include/Obj23340.h"
#include "../../matched/include/Obj23341.h"
#include "../../matched/include/Obj23342.h"
#include "../../matched/include/Obj04524.h"

#define B(k) (*(u8 *)((u8 *)p+(k)))
#define P(k) (*(u8 **)((u8 *)p+(k)))
#define FXI(d) ((fx32)(((d) > 0) ? ((d) * 4096 + .5f) : ((d) * 4096 - .5f)))
#define FXF(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))
struct Big;
struct Obj;
struct Descriptor;
struct Bank;
struct Node;
struct Board;
struct Camera;
struct Cfg;
struct Lights;
struct O;
struct PrintSys;
struct Obj0204F1A0;
struct DispConfig;
struct DispVram;
struct Light;
struct BgTemplate;
struct Desc;
struct Layer;
struct Object;
struct Tagged;
struct Vec3;
struct Manager0204F684;
struct Trip;
struct Vec2;
struct WordSet;
struct GfFont;
struct MsgBank;
struct CharBuf;
struct U16Vec;
struct Actor;
struct Entry;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 prefix[0x18c1]; u8 counter; u16 timer,pad18c4; u8 brightness,pad; u32 mode,busy,flag; u16 sentinel; u8 pad18d6[0x16]; u32 window; } Context;

typedef signed short s16_021B6100;

typedef struct { u32 x, y, z; } VecU;

typedef struct { u32 words[2]; u8 a,b,c,d; u32 field; u16 dims[6]; } Config;

typedef enum { DISP_SUB_MAIN=0, DISP_MAIN_SUB=1 } DispSelect;

typedef short s16_021B6BA4;

typedef struct {s16_021B6BA4 x,y,index;u8 a,b;} Params_021B6100;

typedef signed int     s32;

typedef short s16_021B6F00;

typedef struct { int x, y, z; } Vec;

typedef signed short s16_021B7368;

typedef struct { u32 x,y; } PairU_021B6100;

typedef signed short s16_021B7458;

typedef signed short   s16_021B75E0;

typedef short s16_021B765C;

typedef struct {int x,y;} Pair_021B6100;

typedef struct {s16_021B6BA4 y,x;u16 limit;} Scale_021B6100;

typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags;

typedef struct { u32 x, y; } PairU_021B8140;

typedef struct { short y,x; } Scale_021B8140;

typedef struct { int x, y; } Pair_021B8140;

typedef enum { I_ZERO = 0, I_LIMIT = 9 } Index;

struct O {
    u8 pad0[0x1820];
    void *f1820;
    void *f1824;
    void *f1828;
    u8 pad1[0x1884 - 0x182c];
    void *f1884;
};

typedef int fx32;

typedef struct { short s; short c; } SC;

typedef struct { short x; short y; } Pt;

typedef struct { u8 bytes[12]; } Rects;

typedef short s16_021B9028;

typedef struct {s16_021B9028 x,y;} Pos;

typedef short s16_021B98A0;

typedef struct {int x,y;} Pair_021B98A0;

typedef struct {s16_021B98A0 x,y;} Pos_021B98A0;

typedef short s16_021B9990;

typedef short s16_021B9DE8;

typedef struct {s16_021B9DE8 x,y,index;u8 a,b;} Params_021B98A0;

typedef unsigned long long u64;

typedef short s16_021B9F5C;

typedef struct { s16_021B9F5C x, y; } Pos_021B9F5C;

typedef struct {short x,y;} Pos_021BA098;

typedef signed char s8;

typedef signed short s16_021BA18C;

typedef struct {u32 a,b;} Pair_021BA21C;

typedef struct {u32 a,b;} Pair_021BA22C;

typedef short s16_021BA25C;

typedef struct { int x, y; } Offset;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_020056A0(void *,void *,int);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_0200A828(struct Big *p);
extern void func_0200A834(struct Big *p, u8 value);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void func_020355D8(u8);
extern void func_0200A6F8(struct Big *);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void func_021F5330(int,int);
extern void func_021F51B0(int a);
extern void func_02030EAC(struct Node *);
extern void func_0204ED24(void *);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
extern void func_020403F4(u32);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern u32 func_020307B0(void *p);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern u32 WIPE_SYS_EndCheck(void);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_FadeOutBgm(u32);
extern void func_021FCDEC(int,int);
extern int func_021FCE00(char *p, int id);
extern int func_021FD6A4(char *p);
extern void func_021F51E8(u8 *);
extern void func_021F51F4(void **p);
extern void func_021F4990(void *);
extern void CLACT_DrawSystem(void),func_02047964(void),G3D_SYSTEM_ApplyLookAt(void),G3D_SYSTEM_DrawEnd(void);
extern void BILLBOARD_Draw(struct Board *b, struct Camera *cam, struct Lights *lights);
extern void func_02041EE4(u32,u32,u32);
extern void func_0204152C(int,u16);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void func_0204047C(int,u16),func_0204989C(u32,u32,u32,u32,u32,u32,u16),func_02041B6C(u32);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern u32 func_0200FB24(void);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern u32 func_021F4F10(u8 *);
extern u8 *func_021F4F54(u8 *, int);
extern int func_021F4F70(int *);
extern void func_021F4D74(u8 *, u8 *, int, u16);
extern void func_021F4AA4(void *);
extern void func_0204F32C(int p0, int p1, int p2);
extern void BILLBOARD_GetImageTexKey(u8 *, int, u32 *);
extern void BILLBOARD_SetImageTexAddr(u8 *p, int i, u32 value);
extern void func_0204EDD0(int, u16 *, u16 *);
extern int BILLBOARD_AddImageFromVramKeys(struct Board *b, int w, int h, int a3, u32 a4, u8 a5, u8 a6);
extern void BILLBOARD_ReleaseImageVramIfUsed(struct Obj0204F1A0 *a0, u32 a1);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32,u32);
extern u32 WIPE_ResetWndMask(void *);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u32,void (*)(void));
extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32);
extern u32 *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,VecU *,VecU *,VecU *,u16);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void func_0207DCF8(void *);
extern void func_0203F8F4(u16),BMP_WIN_Init(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0204044C(u32);
extern void func_02040588(unsigned int, unsigned int);
extern void func_0207D63C(void *,int,int,int,int);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32,u32),BG_SYS_SetSubPlaneVisible(u32,u32);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void *func_0204EBD4(u8 *,void *);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_020409B4(u32);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned int);
extern void *func_021F5164(u32 heap);
extern void func_021F5438(void **p, int b);
extern void func_021F5444(u8 *, int);
extern u8 *func_021F5204(u8 *, void *, int);
extern u8 *func_021F545C(u8 *p);
extern void func_021F5350(int *p, int *q);
extern u32 func_0200A644(struct Big *p, u8 index);
extern u32 func_0200A680(struct Big *p, u8 index);
extern u8 *func_0200A628(struct Big *p);
extern struct Object *func_021F48C0(u32 owner, int count, u16 heap);
extern void *func_021F4B3C(int type);
extern void func_021F4B4C(struct Tagged *a0);
extern void func_021F4EE8(int, Flags *, int);
extern u8 *func_021F4C1C(u8 *, int, u32, Vec *);
extern void func_021F4E6C(u8 *, u8 *, u32);
extern void func_021F4EB4(u32 unused, u32 p, s16_021B6F00 a, s16_021B6F00 b);
extern void func_021F4DE0(char *p, char *e, void *a2);
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern u32 G3D_SYSTEM_GetTexVramKey(struct Layer *layer);
extern u32 G3D_SYSTEM_GetPlttVramKey(struct Layer *layer);
extern int G3D_SYSTEM_GetPlttDataAddr(int a0);
extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);
extern void *G3D_SYSTEM_GetResourceTex(void *);
extern void NNS_G3dPlttSetPlttKey(int *p, int v);
extern void NNS_G3dPlttLoad(void *, u32);
extern void func_020862F0(void *, u32);
extern u32 BILLBOARD_AddImageFromArchive(struct Desc *desc, u32 a1, u32 a2, u32 a3, u32 a4, u8 a5, u8 a6);
extern s32 BILLBOARD_AddElem(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void BILLBOARD_SetElemVisible(void *, u32, u32 *);
extern u32 func_02005728(u32 range);
extern void BILLBOARD_FreeElem(void *,unsigned int),BILLBOARD_DeleteImage(u8 *,int);
extern void func_021F4D40(u8 *p, u8 *e);
extern void func_021F4948(u8 *);
extern void func_021F4E8C(int, int, Vec *);
extern void func_021F4ED4(u32 unused, u32 p, u16 v);
extern void BILLBOARD_SetElemPos(u8 *a0, int i, struct Trip *src);
extern void BILLBOARD_SetElemScale(struct Manager0204F684 *mgr, int idx, const s16_021B765C *p12, const s16_021B765C *p14);
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int func_0203F768(int,int,int,int,int,int,int);
extern u8 *func_021F5450(u8 *,int);
extern int func_021F4B24(u8 *);
extern void func_021F4EC4(u32 unused, u32 p, s16_021B6BA4 *a, s16_021B6BA4 *b);
extern void func_021F4EA4(u32 unused, u32 p, u32 q);
extern int func_021F50F4(unsigned int);
extern void func_021F4F04(u8 *,Pair_021B8140 *);
extern int func_021F4AF0(u8 *p, int index);
extern void func_021F4E2C(void *unused, u8 *s, u8 *d);
extern int func_021F4B10(u8 *p, int index, int mode);
extern int func_021F4AFC(u8 *p, int index, int mode);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int FX_Sqrt(int);
extern int FX_Atan2Idx(int, int);
extern int TOUCHPANEL_HitTrg(const void *);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern u32 func_0201ED04(struct WordSet *p);
extern unsigned int func_021BA324(u8 *, int, int);
extern u16 func_0207CFB8(long,long);
extern void func_0200A604(struct Big *p);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern int _s32_div_f(int,int);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void MSGDATA_Delete(void *);
extern void GF_FONT_Delete(void *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u8 func_021F5158(void *, int);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern u8 func_020416D4(u32);
extern void CLACT_SetActorBgPriority(void *, u32);
extern u32 func_0203F0A8(void);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_RestartActorAnim(struct Actor*);
extern int func_021F4EFC(int, Flags *);
extern void func_021F4EE0(int, u16 *, u16 *);
u8 *func_021B6100(u8 *parent, int heap);
void func_021B6294(char *p);
int func_021B63BC(Context *p);
void func_021B6884(void *unused, u8 *p);
void func_021B69AC(u8 *p);
void func_021B6BA4(u8 *p);
void func_021B6E4C(const void *t,unsigned int id);
void func_021B6E74(u8 *p);
void func_021B6F00(u8 *p);
void func_021B7368(u8 *p,u16 id);
void func_021B7458(void *unused, int *p);
void func_021B7498(u8 *p);
void func_021B75E0(u8 *p);
void *func_021B765C(u8 *p, u16 base, s16_021B765C speed, u16 rx, u16 ry);
void func_021B7A18(u8 *p);
void func_021B7A70(u8 *p);
void func_021B7CFC(u8 *p, int unused_x, int unused_y);
int func_021B7F00(u8 *p, void *q, u32 a);
void func_021B7F54(u8 *p,int sound);
void func_021B8140(u8 *p);
void func_021B8254(u8 *p);
void func_021B82E8(u8 *p, int unused);
void func_021B8444(u8 *p);
void func_021B8680(u8 *p);
int func_021B8930(u8 *p);
void func_021B8A30(u8 *p);
void func_021B8AC8(u8 *p);
int func_021B8B78(unsigned char *p,unsigned int id);
int func_021B8BB4(u8 *p, void *manager, const int *pos, u16 *limit);
void func_021B8C6C(struct O *p);
void func_021B8FA8(u8 *p);
int func_021B8FF4(int x,int y,int radius,float scale);
void func_021B9028(u8 *p, int kind, u16 start);
u16 func_021B9118(u8 *p, u8 *q, int v);
void func_021B918C(u8 *p);
int func_021B940C(u8 *p);
void func_021B94C0(u8 *p);
void func_021B952C(u8 *p);
void func_021B95AC(u8 *p);
void func_021B96D8(char *p);
void func_021B9784(u8 *p);
void func_021B9818(u8 *p);
void func_021B987C(unsigned char *p);
void func_021B98A0(u8 *p);
void func_021B9990(u8 *p,u16 a,int delta,u16 duration);
void func_021B9A88(unsigned char *p,unsigned int limit);
void func_021B9AC0(u8 *p, int *a, int *b, u16 duration);
void func_021B9B48(u8 *p);
void func_021B9BD0(unsigned char *p);
void func_021B9C08(u8 *p, unsigned int index, void *object);
void func_021B9C90(unsigned char *p);
void func_021B9CBC(u8 *p, u8 *entry);
void func_021B9D54(u8 *p, int state);
void func_021B9DE8(u8 *p);
void func_021B9F24(unsigned char *p);
void func_021B9F5C(u8 *p);
void func_021BA098(u8*p);
void func_021BA0C8(u8 *p, u8 n);
u8 *func_021BA0CC(u16 heap, int n);
void func_021BA0F8(void *p);
void func_021BA100(u8*p,u8*q);
void func_021BA124(u8*p,u8*q);
void func_021BA148(u8*p,u8*q);
void *func_021BA184(char *p);
unsigned short func_021BA188(char *p);
int func_021BA18C(char *p);
u8 *func_021BA19C(u16 heap, struct Object*q, u8*r, int*v);
void func_021BA1D8(u8*p,u8*q);
void func_021BA1EC(u8*p,u8*q,u8*r);
u32 func_021BA208(u8 *p);
u32 func_021BA20C(u8 *p);
void func_021BA210(u8 *p, u32 value);
u32 func_021BA214(u8 *p);
u32 func_021BA218(u8 *p);
void func_021BA21C(u8 *p, const u8 *src);
u8 * func_021BA228(u8 *p);
void func_021BA22C(u8 *p, const u8 *src);
u8 * func_021BA238(u8 *p);
void func_021BA23C(u8 *p, u32 value);
u32 func_021BA240(u8 *p);
void func_021BA244(u8 *p, u32 value);
int func_021BA248(char *p);
void func_021BA24C(char *p, u32 v);
u16 func_021BA250(char *p);
void func_021BA254(char *p, int v);
u32 func_021BA258(char *p);
int func_021BA25C(u8 *p, int x, int y);
extern const char d_021BA600[];
extern u8 d_021BA518[],d_021BA418[],d_021BA428[],d_021BA438[],d_021BA458[],d_021BA478[],d_021BA4F8[],d_021BA498[],d_021BA4B8[],d_021BA4D8[];
extern VecU d_021BA3F4,d_021BA40C,d_021BA400;
extern Config gClActorInitParam,d_021BA5C4;
extern u32 d_021BA3E0[];
extern const s16_021B765C FX_SinCosTable_[];
extern u8 d_021BA3E4[], d_021BA3E8[];
extern const Vec d_021BA5A0;
extern const Vec d_021BA5B8;
extern const Vec d_021BA588;
extern const Pair_021B8140 d_021BA568;
extern const Vec d_021BA570;
extern const Vec d_021BA57C,d_021BA5AC;
extern const SC FX_SinCosTable__Alt[];
extern const Rects d_021BA594;
extern const Pair_021B98A0 a1,b1,a2,b2;
extern const s16_021B9990 table[];
extern const char d_021BA610[];





#define W(k) (*(u32 *)((u8 *)p+(k)))




#define H(k) (*(u16 *)((u8 *)p+(k)))





u8 *func_021B6100(u8 *parent, int heap)
{
    u8 *p = func_02030734(heap, 0x18f0, 1, d_021BA600, 0x1de);
    u32 t, m;
    *(u16 *)p = heap;
    *(u8 **)(p + 4) = parent;
    *(u32 *)(p + 0xc) = 7;
    *(u32 *)(p + 0x10) = 0;
    *(u32 *)(p + 0x14) = 0;
    *(u32 *)(p + 0x18) = 0;
    *(u32 *)(p + 0x30) = 0;
    *(u32 *)(p + 0x38) = 0;
    *(u32 *)(p + 0x3c) = 0;
    *(u32 *)(p + 0x40) = 0;
    *(u32 *)(p + 0x98) = 0;
    *(u32 *)(p + 0xa4) = 8;
    *(u16 *)(p + 0x182c) = 0;
    *(u16 *)(p + 0x1838) = 0;
    *(u16 *)(p + 0x183a) = 0;
    *(u32 *)(p + 0x183c) = 0;
    *(u8 *)(p + 0x18c6) = 0;
    *(u32 *)(p + 0x18c8) = 0;
    *(u32 *)(p + 0x18d0) = 0;
    *(u32 *)(p + 0x18cc) = 0;
    *(u16 *)(p + 0x18d4) = 0xff;
    *(u8 *)(p + 0x18c1) = 0;
    *(u32 *)(p + 0x1834) = 0;
    *(u32 *)(p + 0x18ec) = 0;
    *(u16 *)(p + 0x182e) = 0;
    *(u32 *)(p + 0x34) = 10;
    func_021B69AC(p);
    func_021B6BA4(p);
    func_021B6E74(p);
    func_021B6F00(p);
    func_021B9DE8(p);
    func_021B9B48(p);
    *(void **)(p + 8) = func_020056A0((void *)func_021B6884, p, 8);
    WIPE_SYS_Start((void *)2, 1, 1, 0x7fff, 18, 1, *(u16 *)p);
    t = *(u32 *)(p + 0x1834) + 0x18000;
    *(u16 *)(p + 0x18c2) = 10;
    m = *(u16 *)(p + 0xa8) * 0x1249;
    {
        u16 x;
        if (t >= m)
            x = (t - m) / 0x1249;
        else
            x = t / 0x1249;
        func_021B9028(p, 8, x);
    }
    *(u32 *)(p + 0xa4) = 8;
    *(u32 *)(p + 0x98) = 1;
    *(u32 *)(p + 0x9c) = 0;
    *(u32 *)(p + 0xa0) = *(u16 *)(p + 0x182c) % 0x1249 + 0x10000;
    if (func_0200A828((struct Big *)(*(u32 *)(*(u8 **)(p + 4) + 8))) == 0) {
        func_0200A834((struct Big *)(*(u32 *)(*(u8 **)(p + 4) + 8)), 1);
        *(u32 *)(p + 0x1840) = 1;
    } else {
        *(u32 *)(p + 0x1840) = 0;
    }
    GFL_USE_CancelChangeAndPlayBgm(0x454, 0xffff);
    GFL_NET_RestartWithDefaultTimeout(0, *(u16 *)p);
    return p;
}





void func_021B6294(char *p)
{
    u8 i;
    func_020355D8(1);
    func_0200A6F8(*(struct Big * *)&((struct Obj23308 *)(*(char * *)&((struct Obj01941 *)p)->f4))->f8);
    GFL_USE_CancelChangeAndStopBgm();
    func_021B9BD0((unsigned char *)p);
    func_021B9F24((unsigned char *)p);
    CLACT_DeleteActor(*(struct Obj * *)&((struct Obj01941 *)p)->f184C);
    CLACT_DeleteActor(*(struct Obj * *)&((struct Obj01941 *)p)->f1850);
    CLACT_DeleteActor(*(struct Obj * *)&((struct Obj01941 *)p)->f1854);
    for(i=0;i<=2;i++) CLACT_ReleasePalette(*(u32 *)(p+0x1858+i*4));
    for(i=3;i<=5;i++) CLACT_ReleaseCharacter(*(u32 *)(p+0x1858+i*4));
    for(i=6;i<=8;i++) CLACT_ReleaseCellAnim(*(u32 *)(p+0x1858+i*4));
    if(*(struct Descriptor * *)&((struct Obj01941 *)p)->f18EC) BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj01941 *)p)->f18EC);
    CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj01941 *)p)->f1848);
    CLACT_ExitSystem();
    func_021B7498((u8 *)p);
    func_021F5330(*(int *)&((struct Obj01941 *)p)->f187C,((struct Obj01941 *)p)->f1880);
    func_021F51B0(((struct Obj01941 *)p)->f187C);
    func_02030EAC(*(struct Node * *)&((struct Obj01941 *)p)->f8);
    func_0204ED24(((struct Obj01941 *)p)->f188C);
    G3D_CAMERA_Delete(((struct Obj01941 *)p)->f1888);
    G3D_SYSTEM_Exit();
    func_020403F4(0);func_020403F4(1);func_020403F4(2);func_020403F4(3);
    func_020403F4(4);func_020403F4(6);func_020403F4(5);func_020403F4(7);
    BMP_WIN_Exit();
    func_0203F9B4();
    func_020307B0(p);
}





static inline void brightness(u8 *value)
{
    func_02041EE4(6,0,128-*value);
    func_02041EE4(5,0,*value-128);
}





int func_021B63BC(Context *p)
{
    void *desc;
    switch(W(0x0c)) {
    case 7:
        GFL_USE_PlaySeDefaultVolume(1358); W(0x0c)=8;
    case 8:
        if(WIPE_SYS_EndCheck()==1) {
            if(W(0x1840)==1) func_021B9818((u8 *)p);
            else W(0x0c)=1;
        }
        if(W(0x98)==1) func_021B8A30((u8 *)p);
        break;
    case 9:
        if(WIPE_SYS_EndCheck()==1 && GFL_USE_IsBgmFading()==0) return 2;
        break;
    case 0: func_021B98A0((u8 *)p); break;
    case 1: func_021B75E0((u8 *)p); break;
    case 2:
        W(0x10)+=6;
        if((int)W(0x10)>=192) {
            func_021B9C08((u8 *)p,1,0); W(0x10)=192; W(0x0c)=3;
            H(0x1838)=0; H(0x183a)=0; H(0x18c4)=0;
        }
        func_021B918C((u8 *)p); break;
    case 6:
        W(0x10)-=6;
        if((int)W(0x10)<0) { W(0x10)=0; W(0x0c)=1; }
        func_021B918C((u8 *)p); break;
    case 3:
        if(func_021B940C((u8 *)p)==2) { W(0x0c)=10; B(0x18c0)=0; CLACT_SetActorDrawEnable((struct Obj *)P(0x18b0),1); }
        break;
    case 10:
        B(0x18c0)++; func_021B9784((u8 *)p);
        if(B(0x18c0)>60) {
            if(*(u32 *)P(4)==0) {
                WIPE_SYS_Start(0,0,0,0x7fff,18,1,H(0)); GFL_USE_FadeOutBgm(60); W(0x0c)=9; p->mode=1;
            } else {
                func_021B9C08((u8 *)p,2,0); func_021FCDEC(*(int *)P(4),69); W(0x0c)=4;
            }
        }
        break;
    case 4:
        if(func_021FCE00(*(void **)P(4),69)==1) W(0x0c)=5;
        break;
    case 5:
        if(func_021FD6A4(*(void **)P(4))==1) {
            WIPE_SYS_Start(0,0,0,0x7fff,18,1,H(0)); GFL_USE_FadeOutBgm(60); W(0x0c)=9; p->mode=1;
        }
        break;
    }
    func_021B9F5C((u8 *)p); func_021B8C6C((struct O *)p); func_021F51E8(P(0x187c));
    func_021F4990(P(0x1884)); CLACT_DrawSystem(); func_02047964(); G3D_SYSTEM_ApplyLookAt();
    func_021F51F4((void **)P(0x187c)); BILLBOARD_Draw((struct Board *)P(0x188c),(struct Camera *)P(0x1888),0); G3D_SYSTEM_DrawEnd();
    p->counter++;
    if(p->counter>1) {
        p->counter=0;
        func_02041EE4(3,1,1); func_02041EE4(3,5,1);
    }
    if(p->mode==0) {
        if(p->brightness<128) { p->brightness+=8; brightness(&p->brightness); }
        else if(p->flag==0) {
            p->flag=1; func_0204152C(7,0);
            p->window=BMP_WIN_Create(7,1,19,30,4,14,1);
            if(W(0x1840)==0) func_021B9C90((u8 *)p); else func_021B9C08((u8 *)p,6,0);
            func_0201F73C((u8 *)p->window,1,128,12);
        }
    } else {
        if(p->flag==1) {
            func_021BA0C8((u8 *)p,2); p->flag=0;
            func_0204047C(7,3); func_0204047C(4,0); func_0204047C(5,1); func_0204047C(6,2);
            func_021BA0C8((u8 *)p,4); func_0204989C(46,13,7,0,0,0,H(0)); func_02041B6C(7);
            p->busy=0; PRINTSYS_QUE_Clear((struct PrintSys *)P(0x18e8)); BMP_WIN_Delete((struct Descriptor *)p->window); p->window=0; func_021BA0C8((u8 *)p,6);
        } else if(p->brightness!=0) {
            func_021BA0C8((u8 *)p,p->brightness+96); p->brightness-=8; brightness(&p->brightness);
        }
    }
    func_021BA0C8((u8 *)p,8);
    if(p->busy==0 && W(0x0c)==1) {
        if(P(0x38)!=0 && p->sentinel!=*(u16 *)func_021BA20C(P(0x38))) {
            func_021B9CBC((u8 *)p,P(0x38)); p->sentinel=*(u16 *)func_021BA20C(P(0x38));
        } else if(p->sentinel!=255 && P(0x38)==0) { func_021B9C90((u8 *)p); p->sentinel=255; }
    }
    func_021BA0C8((u8 *)p,10);
    if(p->busy==1 && PRINTSYS_QUE_IsFinished((const struct PrintSys *)P(0x18e8))==1) {
        p->busy=0; desc=(u8 *)p->window;
        BMP_WIN_TransferChars(desc); BMP_WIN_MakeScreen(desc); func_02041B6C(BMP_WIN_GetBgLayer(desc));
        func_0204047C(4,1); func_0204047C(5,2); func_0204047C(6,3); func_0204047C(7,0);
    }
    func_021BA0C8((u8 *)p,12);
    if(P(0x18e8)!=0) PRINTSYS_QUE_Main((struct PrintSys *)P(0x18e8));
    func_021BA0C8((u8 *)p,14);
    if(H(0x18c2)!=0) H(0x18c2)--;
    if(*(u32 *)P(4)!=0 && W(0x0c)!=7 && W(0x0c)!=8 && W(0x0c)!=9) {
        func_021BA0C8((u8 *)p,32);
        if(func_0200FB24()!=0) {
            func_021BA0C8((u8 *)p,34); WIPE_SYS_Start(0,0,0,0x7fff,18,1,H(0)); GFL_USE_FadeOutBgm(60);
            func_021BA0C8((u8 *)p,36); W(0x0c)=9; func_021BA0C8((u8 *)p,38);
        } else func_021BA0C8((u8 *)p,64);
    }
    func_021BA0C8((u8 *)p,16);
    return 0;
}





void func_021B6884(void *unused, u8 *p)
{
    u32 height, width;
    u16 sizes[2];
    int changed;
    u8 *e, *q, *r;
    u8 *table;
    int flags;
    u16 index;
    e = func_021BA184(*(void **)(p + 0x181c));
    changed = 0;
    while (e) {
        func_021BA218(e);
        q = (u8 *)func_021BA20C(e);
        r = (u8 *)func_021BA214(e);
        if (*(u16 *)q != *(u16 *)r) {
            func_021BA1EC(e, *(void **)(p + 0x1884), r);
            changed = 1;
        }
        e = (u8 *)func_021BA208(e);
    }
    if (changed == 1) func_021B7A18(p);
    if (*(u8 **)(p + 0x38)) {
        q = (u8 *)func_021BA20C(*(u8 **)(p + 0x38));
        if (*(u16 *)(p + 0x50) != *(u16 *)q) {
            table = (u8 *)func_021F4F10(*(u8 **)(p + 0x1884));
            *(u16 *)(p + 0x50) = *(u16 *)q;
            func_0204F32C((int)(*(void **)(p + 0x188c)), *(int *)(p + 0x54), (int)(&height));
            BILLBOARD_GetImageTexKey(*(u8 **)(p + 0x188c), *(int *)(q + 4), &width);
            BILLBOARD_SetImageTexAddr(*(void **)(p + 0x188c), *(int *)(p + 0x54), width);
            flags = func_021F4F70((int *)func_021F4F54(table, *(u16 *)(p + 0x50)));
            func_0204EDD0(flags, &sizes[1], &sizes[0]);
            index = BILLBOARD_AddImageFromVramKeys(*(void **)(p + 0x188c), width, height, 0, flags, sizes[1], sizes[0]);
            func_021F4D74(*(u8 **)(p + 0x1884), *(u8 **)(p + 0x4c), *(u16 *)(p + 0x50), index);
            BILLBOARD_ReleaseImageVramIfUsed(*(void **)(p + 0x188c), *(u32 *)(p + 0x54));
            *(u32 *)(p + 0x54) = index;
        }
    }
    CLACT_VBlankSystem();
    func_021F4AA4(*(void **)(p + 0x1884));
}





static inline void visible_main(int plane)
{
    *(volatile u32 *)0x04000000 = (u32)((*(volatile u32 *)0x04000000 & ~0x1f00u) | (plane << 8));
}





static inline void visible_sub(int plane)
{
    *(volatile u32 *)0x04001000 = (u32)((*(volatile u32 *)0x04001000 & ~0x1f00u) | (plane << 8));
}





static inline void select_display(DispSelect sel)
{
    *(volatile u16 *)0x04000304 = (u16)((*(volatile u16 *)0x04000304 & ~0x8000u) | (sel << 15));
}





void func_021B69AC(u8 *p)
{
    Config cfg, board;
    BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
    visible_main(0);
    visible_sub(0);
    WIPE_SetBrightnessFadeOut(0,0); WIPE_SetBrightnessFadeOut(1,0);
    WIPE_ResetWndMask(0); WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    select_display(DISP_SUB_MAIN);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BA518);
    G3D_SYSTEM_Init(0,2,0,1,0,*(u16 *)p,0);
    G3D_SYSTEM_SetSwapBuffersMode(0,1);
    *(u32 **)(p+0x1888) = G3D_CAMERA_Create(2,0xc000,0,0,0x10000,0x1000,0x3e8000,0,&d_021BA3F4,&d_021BA40C,&d_021BA400,*(u16 *)p);
    G3D_CAMERA_Reset(*(void **)(p+0x1888));
    func_0207DCF8(d_021BA418);
    *(volatile u16 *)0x04000060 &= 0xcfdf;
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
    func_0203F8F4(*(u16 *)p); BMP_WIN_Init(*(u16 *)p);
    func_0203FC28((struct DispConfig *)d_021BA428); func_0204044C(1);
    func_021B6E4C(d_021BA438,1); func_021B6E4C(d_021BA458,2);
    func_021B6E4C(d_021BA478,3); func_021B6E4C(d_021BA4F8,7);
    func_021B6E4C(d_021BA498,4); func_021B6E4C(d_021BA4B8,5); func_021B6E4C(d_021BA4D8,6);
    func_02040588(0,1);
    func_0207D63C((void *)0x04001050,0,15,4,16);
    cfg = gClActorInitParam;
    cfg.a = 16; cfg.b = 112;
    CLACT_InitSystem((const struct Cfg *)(&cfg),(u32)d_021BA518,*(u16 *)p);
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
    *(void **)(p+0x1848) = CLACT_CreateUnit(24,0,*(u16 *)p);
    CLACT_SetUnitDefaultRenderer(*(void **)(p+0x1848));
    board = d_021BA5C4;
    *(void **)(p+0x188c) = func_0204EBD4((u8 *)&board,(void *)*(u16 *)p);
}




#undef H



#undef H


#undef H

#undef H

#define H (*(u16 *)p)




#undef W



#undef W


#undef W

#undef W
#define W(o) (*(u32 *)(p + (o)))








/*
 * note 2026-10-05 (wD9r lane78): EXACT. Closed by declaring func_02049658 with its real return type u32
 *   (it returns ARC_UTIL_UploadBgChar's u32 result, as the matched sibling func_02049624 does), not void. The void
 *   prototype hoisted 4 into r7 and turned later zeros into adds rN,r6,#0 copies. 0xd and -128 are literals.
 *   See docs/idioms/a-getter-declared-void-changes-constant-hoisting.md.
 */
void func_021B6BA4(u8 *p)
{
    Params_021B6100 cfg;
    void *g = func_020490F4(0x2e, H);
    func_02049B68(g, 4, 0, 0, 0, H);
    func_02049658(g, 7, 3, 0, 0, 0, H);
    func_020498F4(g, 0xc, 3, 0, 0, 0, H);
    func_020498F4(g, 0xb, 2, 0, 0, 0, H);
    func_02049B68(g, 3, 4, 0, 0, H);
    func_02049658(g, 0xa, 4, 0, 0, 0, H);
    func_02049658(g, 9, 7, 0, 0, 0, H);
    func_020498F4(g, 0x10, 4, 0, 0, 0, H);
    func_020498F4(g, 0xf, 6, 0, 0, 0, H);
    func_020498F4(g, 0xe, 5, 0, 0, 0, H);
    func_020498F4(g, 0xd, 7, 0, 0, 0, H);
    func_02041EE4(6, 0, 128);
    func_02041EE4(5, 0, -128);
    *(struct Obj **)(p + 0x1858) = (struct Obj *)CLACT_RegisterPalette(g, 2, 0, 0, H);
    *(struct Obj **)(p + 0x1864) = (struct Obj *)CLACT_RegisterCharacter(g, 8, 0, 0, H);
    *(struct Obj **)(p + 0x1870) = (struct Obj *)CLACT_RegisterCellAnim(g, 0x14, 0x18, H);
    *(struct Obj **)(p + 0x1860) = (struct Obj *)CLACT_RegisterPalette(g, 1, 1, 0, H);
    *(struct Obj **)(p + 0x186c) = (struct Obj *)CLACT_RegisterCharacter(g, 6, 0, 1, H);
    *(struct Obj **)(p + 0x1878) = (struct Obj *)CLACT_RegisterCellAnim(g, 0x13, 0x17, H);
    *(struct Obj **)(p + 0x185c) = (struct Obj *)CLACT_RegisterPalette(g, 0, 0, 0x40, H);
    *(struct Obj **)(p + 0x1868) = (struct Obj *)CLACT_RegisterCharacter(g, 5, 0, 0, H);
    *(struct Obj **)(p + 0x1874) = (struct Obj *)CLACT_RegisterCellAnim(g, 0x11, 0x15, H);
    cfg.x = 32; cfg.y = 224; cfg.index = 0; cfg.a = 0; cfg.b = 2;
    *(struct Obj **)(p + 0x184c) = CLACT_CreateActor((void *)W(0x1848), W(0x1864), W(0x1858), W(0x1870), &cfg, 0, H);
    cfg.x = 224; cfg.y = 224; cfg.index = 1;
    *(struct Obj **)(p + 0x1850) = CLACT_CreateActor((void *)W(0x1848), W(0x1864), W(0x1858), W(0x1870), &cfg, 0, H);
    cfg.x = 128; cfg.y = 96; cfg.index = 2; cfg.a = 0; cfg.b = 0;
    *(struct Obj **)(p + 0x1854) = CLACT_CreateActor((void *)W(0x1848), W(0x1864), W(0x1858), W(0x1870), &cfg, 0, H);
    CLACT_SetActorDrawEnable(*(struct Obj **)(p + 0x184c), 1);
    CLACT_SetActorDrawEnable(*(struct Obj **)(p + 0x1850), 1);
    CLACT_SetActorDrawEnable(*(struct Obj **)(p + 0x1854), 0);
    ARC_TOOL_DeleteHandle(g);
    func_020409B4(3);
    func_020409B4(2);
    func_020409B4(7);
}








void func_021B6E4C(const void *t,unsigned int id) {func_0203FCA0(id,t,0);func_02040588(id,1);func_020414AC(id);func_020409B4(id);}








void func_021B6E74(u8 *p)
{
    int v[3];
    int *q;
    *(u8 * *)&((struct Obj02852 *)p)->f187C = func_021F5164(((struct Obj02852 *)p)->f0);
    func_021F5438((void **)(*(u8 * *)&((struct Obj02852 *)p)->f187C), 0x50000);
    func_021F5444(*(u8 * *)&((struct Obj02852 *)p)->f187C, 0x3fe0);
    *(u8 * *)&((struct Obj02852 *)p)->f1880 = func_021F5204(*(u8 * *)&((struct Obj02852 *)p)->f187C, (*(void ***)(p + 4))[1], 0);
    func_021F51E8(*(u8 * *)&((struct Obj02852 *)p)->f187C);
    func_021F51F4((void **)(*(u8 * *)&((struct Obj02852 *)p)->f187C));
    q = (int *)func_021F545C(*(u8 * *)&((struct Obj02852 *)p)->f1880);
    v[0] = (0x80000 - q[0]) / 16;
    v[1] = (0xc0000 - (0x70000 - q[1])) / 16;
    v[2] = 0x28000;
    func_021F5350((int *)(*(u8 * *)&((struct Obj02852 *)p)->f1880), v);
}








extern u32 (*d_020A8148)(u32, u32, u32);









void func_021B6F00(u8 *p)
{
    int i;
    int j;
    u32 zero;
    u8 *table;
    void *h;
    int w;
    u32 flags;
    u32 vram;
    u32 hgt;
    u32 sz;
    u16 sizes[2];
    u16 dims[2];
    u16 *pal;
    u32 n;
    u8 k;
    u8 *buf;
    void *res;
    u8 *e;

    *(u16 *)(p + 0xa8) = 0;
    zero = 0;
    for (i = 0; i < 250; i++) {
        if (func_0200A644(*(void **)(*(u8 **)(p + 4) + 8), i) == 1) {
            *(u16 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xac) = i;
            *(u32 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xb8) = zero;
            if (func_0200A680(*(void **)(*(u8 **)(p + 4) + 8), i) == 1)
                *(u32 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xbc) = 1;
            else
                *(u32 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xbc) = zero;
            (*(u16 *)(p + 0xa8))++;
        }
    }
    for (j = 0; *(u16 *)(p + 0xa8) + j < 250; j++) {
        *(u16 *)(p + (*(u16 *)(p + 0xa8) + j) * 0x14 + 0xac) = 0xff;
        *(u32 *)(p + (*(u16 *)(p + 0xa8) + j) * 0x14 + 0xb8) = 0;
        *(u32 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xbc) = 1;
    }

    *(u8 **)(p + 0x1884) = (u8 *)func_021F48C0((u32)(*(void **)(p + 0x188c)), 0x98, *(u16 *)p);
    table = (u8 *)func_021F4F10(*(u8 **)(p + 0x1884));

    for (i = 0; i < *(u16 *)(p + 0xa8); i++) {
        h = func_021F4B3C(*(u16 *)(p + i * 0x14 + 0xac));
        G3D_SYSTEM_TransVramTexture(h);
        w = G3D_SYSTEM_GetTexVramKey(h);
        hgt = G3D_SYSTEM_GetPlttVramKey(h);
        sz = ((hgt & 0xFFFF0000) >> 16) << 3;
        vram = d_020A8148(sz, 0, 0);
        flags = func_021F4F70((int *)func_021F4F54(table, *(u16 *)(p + i * 0x14 + 0xac)));
        func_0204EDD0(flags, &sizes[1], &sizes[0]);
        *(u32 *)(p + i * 0x14 + 0xb0) = BILLBOARD_AddImageFromVramKeys(*(void **)(p + 0x188c), w, hgt, 0, flags, sizes[1], sizes[0]);
        pal = (u16 *)G3D_SYSTEM_GetPlttDataAddr((int)h);
        n = sz >> 1;
        for (k = 0; k < n; k++) {
            u16 c = pal[k];
            u32 b = (u32)(u8)((c & 0x7C00) >> 10) >> 3;
            u32 r = (u32)(u8)(c & 0x1F) >> 3;
            u32 g = (u32)(u8)((c & 0x3E0) >> 5) >> 3;
            pal[k] = r | (g << 5) | (b << 10);
        }
        buf = G3D_SYSTEM_GetResourceFile(h);
        res = G3D_SYSTEM_GetResourceTex(h);
        NNS_G3dPlttSetPlttKey(res, vram);
        func_020862F0(buf, *(u32 *)(buf + 8));
        NNS_G3dPlttLoad(res, 1);
        *(u32 *)(p + i * 0x14 + 0xb4) = BILLBOARD_AddImageFromVramKeys(*(void **)(p + 0x188c), w, vram, 0, flags, sizes[1], sizes[0]);
        func_021F4B4C(h);
    }

    func_021B9028(p, 8, 0);
    *(u8 **)(p + 0x181c) = func_021BA0CC(*(u16 *)p, 0xe);
    *(u8 **)(p + 0x1820) = func_021BA0CC(*(u16 *)p, 0x80);
    *(u8 **)(p + 0x1824) = func_021BA0CC(*(u16 *)p, 9);
    *(u8 **)(p + 0x1828) = func_021BA0CC(*(u16 *)p, 4);

    for (i = 0; i < 14; i++) {
        Vec v = {0, 0, 0};
        e = func_021BA19C(*(u16 *)p, *(void **)(p + 0x1884), p + 0xac + i * 0x14, (int *)(&v));
        func_021BA100(*(void **)(p + 0x181c), e);
        func_021F4EE8((int)*(u8 **)(p + 0x1884), (Flags *)func_021BA218(e), 0);
    }

    {
    Vec v2 = {0, 0, 0};
    *(u16 *)(p + 0x50) = 0;
    flags = func_021F4F70((int *)func_021F4F54(table, *(u16 *)(p + 0x50)));
    func_0204EDD0(flags, &dims[1], &dims[0]);
    h = func_021F4B3C(*(u16 *)(p + 0x50));
    G3D_SYSTEM_TransVramTexture(h);
    w = G3D_SYSTEM_GetTexVramKey(h);
    *(u32 *)(p + 0x54) = BILLBOARD_AddImageFromVramKeys(*(void **)(p + 0x188c), w, G3D_SYSTEM_GetPlttVramKey(h), 0, flags, dims[1], dims[0]);
    *(u8 **)(p + 0x4c) = func_021F4C1C(*(u8 **)(p + 0x1884), *(u16 *)(p + 0x50), *(u32 *)(p + 0x54), &v2);
    func_021F4E6C(*(u8 **)(p + 0x1884), *(u8 **)(p + 0x4c), 0);
    func_021F4EB4((u32)(*(u8 **)(p + 0x1884)), (u32)(*(u8 **)(p + 0x4c)), 0x1000, 0x1000);
    func_021F4DE0((char *)(*(u8 **)(p + 0x1884)), (char *)(*(u8 **)(p + 0x4c)), h);
    func_021F4B4C(h);
    }

    *(u32 *)(p + 0x58) = BILLBOARD_AddImageFromArchive(*(void **)(p + 0x188c), 0x2e, 0x19, 2, 0x22, 0x20, 0x20);
    for (k = 0; k < 14; k++) {
        Vec v3 = {0, 0, 0};
        n = BILLBOARD_AddElem(*(void **)(p + 0x188c), *(u32 *)(p + 0x58), 0x1000, 0x1000, (struct Vec3 *)(&v3), 0x1f, 0, 0);
        *(u32 *)(p + k * 4 + 0x5c) = n;
        BILLBOARD_SetElemVisible(*(void **)(p + 0x188c), n, d_021BA3E0);
    }

    *(u16 *)(p + 0x94) = 0;
    e = func_0200A628(*(void **)(*(u8 **)(p + 4) + 8));
    for (k = 0; k < 8; k++) {
        if (e[k * 6] != 10)
            func_021B7368(p, *(u16 *)(e + k * 6 + 2));
    }
    func_021B7A18(p);
    *(u32 *)(p + 0x1834) = *(u16 *)(p + 0xa8) * 0x1249 - 0x8000;
    func_021B765C(p, 0, 0, 0x48, 0x30);
}








void func_021B7368(u8 *p,u16 id)
{
    PairU_021B6100 pos;
    Vec scale;
    u8 *e,*q;
    u8 i;
    e=0;
    for(i=0;i<*(u16 *)(p+0xa8);i++){
        if(id==*(u16 *)(p+i*20+0xac)){e=p+0xac+i*20;break;}
    }
    if(e){
        int y;
        func_021B7458(p,(int *)(&pos));
        if((int)pos.x>0) scale.x=(int)(0.5f+(float)((int)pos.x<<12));
        else scale.x=(int)((float)((int)pos.x<<12)-0.5f);
        if((int)pos.y>0) y=(int)(0.5f+(float)((int)pos.y<<12));
        else y=(int)((float)((int)pos.y<<12)-0.5f);
        scale.y=y;
        scale.z=(10<<12)-(func_021BA188((char *)(*(u8 **)(p+0x1820)))<<10);
        q=func_021BA19C(*(u16 *)p,*(void **)(p+0x1884),e,(int *)(&scale));
        func_021BA100(*(void **)(p+0x1820),q);
        func_021BA21C(q,(const u8 *)(&pos));
        func_021F4EB4(*(int *)(p+0x1884),func_021BA218(q),0x1000,0x1000);
        *(u32 *)(e+0xc)=1;
    }
}








void func_021B7458(void *unused, int *p)
{
    do {
        p[0] = func_02005728(240) + 8;
        p[1] = func_02005728(128) + 32;
    } while (func_021B8FF4((s16_021B7458)(p[0] - 128), (s16_021B7458)(p[1] - 80), 84, 0.739130437374115f) == 1);
}








void func_021B7498(u8 *p)
{
    u8 *e,*next;
    int i;
    e=func_021BA184(((struct Obj00777 *)p)->f181C);
    while(e){next=(u8 *)func_021BA208(e);func_021BA1D8(e,((struct Obj00777 *)p)->f1884);e=next;}
    e=func_021BA184(((struct Obj00777 *)p)->f1820);
    while(e){next=(u8 *)func_021BA208(e);func_021BA1D8(e,((struct Obj00777 *)p)->f1884);e=next;}
    e=func_021BA184(((struct Obj00777 *)p)->f1824);
    while(e){next=(u8 *)func_021BA208(e);func_021BA1D8(e,((struct Obj00777 *)p)->f1884);e=next;}
    e=func_021BA184(((struct Obj00777 *)p)->f1828);
    while(e){next=(u8 *)func_021BA208(e);func_021BA1D8(e,((struct Obj00777 *)p)->f1884);e=next;}
    for(i=0;i<14;i++)BILLBOARD_FreeElem(((struct Obj00777 *)p)->f188C,*(unsigned int *)(p+i*4+0x5c));
    BILLBOARD_DeleteImage(*(u8 * *)&((struct Obj00777 *)p)->f188C,((struct Obj00777 *)p)->f58);
    func_021F4D40((u8 *)(*(int *)&((struct Obj00777 *)p)->f1884),(u8 *)(((struct Obj00777 *)p)->f4C));
    BILLBOARD_DeleteImage(*(u8 * *)&((struct Obj00777 *)p)->f188C,((struct Obj00777 *)p)->f54);
    for(i=0;i<((struct Obj00777 *)p)->fA8;i++){
        BILLBOARD_DeleteImage(*(u8 **)(p+0x188c),*(int *)(p+i*20+0xb0));
        BILLBOARD_DeleteImage(*(u8 **)(p+0x188c),*(int *)(p+i*20+0xb4));
    }
    func_021BA0F8(((struct Obj00777 *)p)->f181C);func_021BA0F8(((struct Obj00777 *)p)->f1820);
    func_021BA0F8(((struct Obj00777 *)p)->f1824);func_021BA0F8(((struct Obj00777 *)p)->f1828);
    func_021F4948(*(u8 **)(p+0x1884));
}








void func_021B75E0(u8 *p)
{
    if (((struct Obj00004 *)p)->f98 == 1) func_021B8A30(p);
    else { func_021B7A70(p); func_021B8AC8(p); }
    func_021B8FA8(p);
    ++((struct Obj00004 *)p)->f94;
    if (((struct Obj00004 *)p)->f94 >= 90) {
        ((struct Obj00004 *)p)->f94 = 0;
        func_021B765C(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
    }
    if (((struct Obj00004 *)p)->f94 == 45)
        func_021B765C(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
}








static inline int GetTimer(u8 *p) { return *(u16 *)(p + 0x94); }








/*
 * 2026-10-05 (user decision): the field re-read in the loop (for (n = F; t >= n * K; n = F)) is accepted as a real source quirk.
 * note (2026-10-04, wave D3 lane 08): DIFF, same length as the target. Body matches
 *   instruction for instruction except two spots. (1) Prologue order: the target stores
 *   r1 (base) to [sp] before the 0x181C pool load and stores r3 before idx; ours
 *   loads the pool first. (2) At +0x13C the target does "str r1,[sp,#8]; ldr r1,[sp,#8];
 *   muls" (the u16 at p+0xA8 is a spilled value reloaded for 0x1249*n); ours multiplies
 *   r1 before the store, which shifts all later code by 2 bytes. Tried for (2): n as int
 *   (slot moves to 0xC), lim local vs loop-condition multiply, if+do-while guard,
 *   n*0x1249 vs 0x1249*n, no n at all (field re-read so the compiler CSEs the load;
 *   spill slot right but still no reload). Keys that closed big residues: the local
 *   constants h = 0x8000 and sh = 0xC0000 (the target computes h>>1, h>>3, h>>4, h<<1,
 *   sh>>9 at run time, so they are variables, not literals); sx = tp[0]*rx and
 *   sy = tp[1]*ry operand order; cur = old = f() store order; offy written with "* -8";
 *   case a < h>>1 passes h>>3 directly (not sc) so it is not tail-merged.
 * 2026-10-05 (wave D4 lane 01): DIFF, residue unchanged. Tried: `lim = (n = ...) * 0x1249`; `int idx = 0`
 *   at the declaration; an offset local o = 0x181C for the first access and for p + (o + 0x18) in the first
 *   0x1834 lines (no change: the pool load still schedules first); base as int or u32 (moves the base
 *   store, never to +0004). In the original, base, rx, idx and n are all stored at their definition and
 *   reloaded before use (spill everywhere); ours keeps the value in the register and the scheduler sinks the
 *   store. A fifth live value in the original (more register pressure) is the likely cause; not found.
 * 2026-10-05 (wave D5 lane 04): DIFF, residue unchanged (prologue store order and the n store/reload at
 *   +013C). Tried: n as a block-local u16 in the do body; `lim = (n = field) * 0x1249`; the multiply in the
 *   loop condition `while (t >= (lim = n * 0x1249))` and `while (t >= n * 0x1249) t -= n * 0x1249`; a
 *   static inline wrap(t, n) helper for the second loop; `idx = 0` after the first call (worse); volatile n
 *   as a probe (not a fix: changes the frame, still no reload). The listing has real back edges, so both
 *   while loops are real. The reload means the multiply reads n's home, not the ldrh temp: find what
 *   blocks copy propagation of `n = field` in the original.
 * 2026-10-05 (wave D6 lane 09): DIFF, residue unchanged. Finding: the same str/ldr pair appears in our
 *   build for cur at +0x198 (str r0,[sp,#0x10]; ldr r1,[sp,#0x10]) because cur has two definitions
 *   (cur = old and cur = table), so copy propagation does not replace it. The n reload at +0x13C thus
 *   says that n also has a second definition (or is otherwise not copy-propagated) in the original.
 *   Tried: `u16 n = 0` initialiser (no change), `lim = n; lim *= 0x1249` (no change), the second loop
 *   with the field re-read in the condition and body plus n kept for k (no change). Next: find where a
 *   second def of n can sit without a store in the listing (sp+8 is only written at +0x13C).
 * 2026-10-05 (wave D7 lane 04): DIFF, residue unchanged (533 bytes: prologue store order and the n
 *   reload at +013C). Tried: a second def of n in the prologue (`n = field; lim = 0x1249 * n;`, no change:
 *   n is still copy-propagated in the loop). Reading: in the original the three entry stores (base [sp],
 *   rx [sp,#4], idx [sp,#0x2c]) all stay above the first p+0x181C load, as if they were memory-variable
 *   stores that may alias it; ours sinks the rx store below the load. n at [sp,#8] behaves the same way
 *   (store then reload). So base, rx, idx and n look like memory-resident variables in the original,
 *   not allocator spills; the source cause is still not found.
 * 2026-10-05 (wD9 lane08): DIFF, residue unchanged. Tried: n as u32 (same as int: slots for n and ry
 *   swap, multiply still reads the ldrh temp). Note: ry is also copied to a stack home ([sp,#0xC]) at the
 *   loop guard, so base, rx, ry, idx and n all have stack homes; the prologue stores stay above the
 *   first p+0x181C load in the original only.
 * 2026-10-05 (wave D8 lane 02): DIFF, residue unchanged (533 bytes). Tried: n as int (536; the slots
 *   for n and ry swap, 8 and 0xC, and the multiply still reads the ldrh temp, no reload). The
 *   original pattern (store at the definition, reload at every use, entry stores above the first
 *   load) is spill-everywhere for base, rx, idx and n; no source shape found yet that blocks the
 *   copy propagation of n = field into the multiply.
 * 2026-10-05 (wD9r lane02): DIFF, residue unchanged (533 bytes). Tried: n defined inside the first loop
 *   (`while (t < 0) { n = field; t += n * 0x1249; }`, 646, worse); the 0x1249 factor as a local
 *   `unit = 0x1249` for `lim = n * unit` (533, no change); n read through a static inline getter (533,
 *   no change). Reading: the prologue and the loop wrap use the same shape (ldrh, pool K, copy, muls), and
 *   the image reloads n at the multiply, so the multiply reads n after a block boundary or n is not a
 *   single-def copy there; no source form found.
 * 2026-10-05 (wD9r lane20): DIFF, residue unchanged (533 bytes). New tries, each compiled: the whole body
 *   as a static inline called from a wrapper (544, slots move, prologue order unchanged); sx, sy, old,
 *   cur, spr, t, k, n and tp declared in the do-body block (533, no change). Probe: dsi/1.1 to 1.6sp2
 *   all give 533, so the residue is source, not compiler build. Reading: the same shape as ov116
 *   021D7D0C (store at the def, reload at the use, entry stores held above the first load) means the
 *   image keeps base, rx, idx and n as memory variables, not register-allocator spills; no source
 *   form found that does this without address-taking.
 * 2026-10-05 (wD9r lane42): DIFF, 533 -> 521 bytes. The prologue store order is fixed: the callers
 *   (021B7A70, 021B7CFC, 021B8930) declare (u8 *, u16, s16_021B6BA4, int, u16) and pass 72, 48 for rx, ry, so
 *   speed is s16_021B6BA4 and rx is a narrow parameter like ry (u16; s16_021B6BA4 gives the same code). A narrow rx pins
 *   its home store above the first p+0x181C load (docs/idioms/a-narrow-parameter-pins-its-home-store-
 *   to-the-front-of-the-prologue.md). The only residue left is the n store/reload at +013C (all later
 *   bytes are the 2-byte shift). Probe: a second reaching def of n before the k compare (`if (t == 5)
 *   n = 3;`, not a fix) gives the image's str/ldr/muls exactly, so in the image n has a second
 *   definition that reaches the multiply or the k compare. A def that does not reach (prologue
 *   `n = field; lim = 0x1249 * n;`, a dead `n = 0` at the loop end) changes nothing. Also tried, all 521:
 *   `while (t >= (n = field) * 0x1249) t -= n * 0x1249;`, `while (t >= (lim = (n = field) * 0x1249))`,
 *   `while (t >= (lim = n * 0x1249))`, `while (t >= n * 0x1249) t -= n * 0x1249;`, an explicit if guard
 *   plus do-while, n read through a struct field `((Hdr *)p)->n` (also in the first loop).
 *   More (all compiled): `lim = 0x1249; lim *= n;` after `n = field` (520: str moves above the muls,
 *   still no reload, muls r1,r2,r1); `lim = 0x1249` before `n = field` (525); a `for (;;)` with break
 *   (605); n as a 6th function parameter (probe only, 56 B: parameters are not copy-propagated, the
 *   reload appears at [sp,#0x6c]); reusing the speed parameter for n (612/888). Inline helpers for the
 *   tail (wrap loop, if, k, cur pick) with n as a helper parameter: with `u8 *cur = old;` inside the
 *   helper (668) the image's `str r1,[sp,#8]; ldr r1,[sp,#8]; muls` appears, but the helper adds a
 *   `ldr [sp,#0x14]; str [sp,#0x10]` copy for cur after the t loop (the image stores cur at the call,
 *   +010A); with cur passed by pointer (`u8 **pcur`, 521) or with two returns (663) n is propagated
 *   again. Reading: the image's n is a copy that mwcc does not propagate (a parameter-like variable),
 *   and something sits between `n = field` and the multiply in the IR without code of its own.
 * 2026-10-05 (wD9r lane86): DIFF, residue unchanged (521 bytes, only the n str/ldr at +013C). New
 *   tries, each compiled, all 521 unless noted: k and the second wrap in an inline helper called before
 *   the condition (the divide is not sunk into the if); `t = Wrap(t, n)` inline helper with an int
 *   return; the whole f(e)..pick segment as an inline helper returning cur (523, old/cur stores swap);
 *   `GetCount(p, &n)` inline out-parameter; `register u16 n`; block-local `const u16 n`; `int unit =
 *   0x1249` at the top used in one, two or all three places; the wrap on a copy `f = t`; n reused for the
 *   (u16)(0x6E00 - a) and (u16)(0x78E0 - a) temps; the frame index written into n (`if (k >= n) n = k -
 *   n; else n = k;`, both orders); `lim = field * 0x1249` with `n = field` after the wrap; the n def
 *   behind a goto label; `for (n = field; t >= n * 0x1249; )`; `int speed` reused for n (888).
 *   Findings: (1) n = field written in both arms of `if (t < 0) { while (t < 0) ...; n = field; } else n
 *   = field;` gets cross-jumped into one tail and gives the reload, but the inner while keeps a redundant
 *   `cmp r0,#0; bge` (635), and the reload sits in the join block (str before the pool load, the image
 *   has the pool load first); with a do-while in the arm (630) the arm's n is CSE'd with the loop's
 *   hoisted load. (2) An intervening statement that needs a register between `n = field` and the
 *   multiply (a memory store, a spilled-local copy) also gives the reload; a store of a callee-saved
 *   value (`cur = spr`), a register copy, or a constant assignment does not. (3) A reaching second def
 *   after the wrap (`if (t == 5) n = 3;`, probe) reproduces the image's exact order (pool load, str,
 *   ldr, muls), so the image's n most likely has a second reaching def or is parameter-like; no natural
 *   codeless form found.
 * 2026-10-05 (wD9r lane116): DIFF, residue unchanged (521 bytes, only the n str/ldr at +013C). Twin
 *   search: 0x1249 appears only in ov133 021B6100 (frame pick as `m = F * 0x1249; if (t >= m) x = (t - m)
 *   / 0x1249; else ...`, no n local) and 021B6F00 (init); no matched copy of this routine. New tries
 *   (F = the u16 at p+0xA8), each compiled: n as a one-field local struct (521, scalarised); `while (t <
 *   0) { n = F; t += n * 0x1249; } n = F;` (964/635: the +0134 block is now byte-exact, str/ldr/muls in the
 *   image order, but hoisting the loop assignment adds a re-test `cmp r0,#0; bge` after the preheader);
 *   the same with `(n = F)` in the loop expression and as a for loop (635); `if (t < 0) { n = F; do ...
 *   while }` and `if (t < 0) do { n = F; ... } while` (521); `if (t < 0) { n = F; while ... }` (635,
 *   re-test); `n = F` before the first loop (631, CSE); if/else arms with a for(;;)+break or do-while
 *   loop and `n = F` in both arms (630, 632: CSE with the hoisted load); n re-read (`n = F`) inside the
 *   condition block before or after k, or only there with `lim = F * 0x1249` (521, CSE'd away); no n and
 *   F read at the k compare (521); a later def that reads n (`n += k` or `n = k - n` with a use after,
 *   562/563, no reload); `else n = 3` after the k compare (no reload). Probes (not fixes): moving the
 *   loop-top `sc = 0` (store to the address-taken sc) between `n = F` and the multiply gives the image's
 *   str/ldr/muls (115 bytes left, all from the moved strh), so any memory store there blocks the load
 *   forwarding into the multiply; a def of n inside the condition block before k (`if (t == 5) n = 3;`)
 *   also gives it, a def after the k compare does not. Open: a codeless memory kill or a codeless
 *   second def between +0138 and +0184; none of the image's stores fits.
 */
/*
 * 2026-10-05 (user decision): the field re-read in the loop (for (n = F; t >= n * K; n = F)) is accepted as a real source quirk.
 * note (2026-10-04, wave D3 lane 08): DIFF, same length as the target. Body matches
 *   instruction for instruction except two spots. (1) Prologue order: the target stores
 *   r1 (base) to [sp] before the 0x181C pool load and stores r3 before idx; ours
 *   loads the pool first. (2) At +0x13C the target does "str r1,[sp,#8]; ldr r1,[sp,#8];
 *   muls" (the u16 at p+0xA8 is a spilled value reloaded for 0x1249*n); ours multiplies
 *   r1 before the store, which shifts all later code by 2 bytes. Tried for (2): n as int
 *   (slot moves to 0xC), lim local vs loop-condition multiply, if+do-while guard,
 *   n*0x1249 vs 0x1249*n, no n at all (field re-read so the compiler CSEs the load;
 *   spill slot right but still no reload). Keys that closed big residues: the local
 *   constants h = 0x8000 and sh = 0xC0000 (the target computes h>>1, h>>3, h>>4, h<<1,
 *   sh>>9 at run time, so they are variables, not literals); sx = tp[0]*rx and
 *   sy = tp[1]*ry operand order; cur = old = f() store order; offy written with "* -8";
 *   case a < h>>1 passes h>>3 directly (not sc) so it is not tail-merged.
 * 2026-10-05 (wave D4 lane 01): DIFF, residue unchanged. Tried: `lim = (n = ...) * 0x1249`; `int idx = 0`
 *   at the declaration; an offset local o = 0x181C for the first access and for p + (o + 0x18) in the first
 *   0x1834 lines (no change: the pool load still schedules first); base as int or u32 (moves the base
 *   store, never to +0004). In the original, base, rx, idx and n are all stored at their definition and
 *   reloaded before use (spill everywhere); ours keeps the value in the register and the scheduler sinks the
 *   store. A fifth live value in the original (more register pressure) is the likely cause; not found.
 * 2026-10-05 (wave D5 lane 04): DIFF, residue unchanged (prologue store order and the n store/reload at
 *   +013C). Tried: n as a block-local u16 in the do body; `lim = (n = field) * 0x1249`; the multiply in the
 *   loop condition `while (t >= (lim = n * 0x1249))` and `while (t >= n * 0x1249) t -= n * 0x1249`; a
 *   static inline wrap(t, n) helper for the second loop; `idx = 0` after the first call (worse); volatile n
 *   as a probe (not a fix: changes the frame, still no reload). The listing has real back edges, so both
 *   while loops are real. The reload means the multiply reads n's home, not the ldrh temp: find what
 *   blocks copy propagation of `n = field` in the original.
 * 2026-10-05 (wave D6 lane 09): DIFF, residue unchanged. Finding: the same str/ldr pair appears in our
 *   build for cur at +0x198 (str r0,[sp,#0x10]; ldr r1,[sp,#0x10]) because cur has two definitions
 *   (cur = old and cur = table), so copy propagation does not replace it. The n reload at +0x13C thus
 *   says that n also has a second definition (or is otherwise not copy-propagated) in the original.
 *   Tried: `u16 n = 0` initialiser (no change), `lim = n; lim *= 0x1249` (no change), the second loop
 *   with the field re-read in the condition and body plus n kept for k (no change). Next: find where a
 *   second def of n can sit without a store in the listing (sp+8 is only written at +0x13C).
 * 2026-10-05 (wave D7 lane 04): DIFF, residue unchanged (533 bytes: prologue store order and the n
 *   reload at +013C). Tried: a second def of n in the prologue (`n = field; lim = 0x1249 * n;`, no change:
 *   n is still copy-propagated in the loop). Reading: in the original the three entry stores (base [sp],
 *   rx [sp,#4], idx [sp,#0x2c]) all stay above the first p+0x181C load, as if they were memory-variable
 *   stores that may alias it; ours sinks the rx store below the load. n at [sp,#8] behaves the same way
 *   (store then reload). So base, rx, idx and n look like memory-resident variables in the original,
 *   not allocator spills; the source cause is still not found.
 * 2026-10-05 (wD9 lane08): DIFF, residue unchanged. Tried: n as u32 (same as int: slots for n and ry
 *   swap, multiply still reads the ldrh temp). Note: ry is also copied to a stack home ([sp,#0xC]) at the
 *   loop guard, so base, rx, ry, idx and n all have stack homes; the prologue stores stay above the
 *   first p+0x181C load in the original only.
 * 2026-10-05 (wave D8 lane 02): DIFF, residue unchanged (533 bytes). Tried: n as int (536; the slots
 *   for n and ry swap, 8 and 0xC, and the multiply still reads the ldrh temp, no reload). The
 *   original pattern (store at the definition, reload at every use, entry stores above the first
 *   load) is spill-everywhere for base, rx, idx and n; no source shape found yet that blocks the
 *   copy propagation of n = field into the multiply.
 * 2026-10-05 (wD9r lane02): DIFF, residue unchanged (533 bytes). Tried: n defined inside the first loop
 *   (`while (t < 0) { n = field; t += n * 0x1249; }`, 646, worse); the 0x1249 factor as a local
 *   `unit = 0x1249` for `lim = n * unit` (533, no change); n read through a static inline getter (533,
 *   no change). Reading: the prologue and the loop wrap use the same shape (ldrh, pool K, copy, muls), and
 *   the image reloads n at the multiply, so the multiply reads n after a block boundary or n is not a
 *   single-def copy there; no source form found.
 * 2026-10-05 (wD9r lane20): DIFF, residue unchanged (533 bytes). New tries, each compiled: the whole body
 *   as a static inline called from a wrapper (544, slots move, prologue order unchanged); sx, sy, old,
 *   cur, spr, t, k, n and tp declared in the do-body block (533, no change). Probe: dsi/1.1 to 1.6sp2
 *   all give 533, so the residue is source, not compiler build. Reading: the same shape as ov116
 *   021D7D0C (store at the def, reload at the use, entry stores held above the first load) means the
 *   image keeps base, rx, idx and n as memory variables, not register-allocator spills; no source
 *   form found that does this without address-taking.
 * 2026-10-05 (wD9r lane42): DIFF, 533 -> 521 bytes. The prologue store order is fixed: the callers
 *   (021B7A70, 021B7CFC, 021B8930) declare (u8 *, u16, s16, int, u16) and pass 72, 48 for rx, ry, so
 *   speed is s16 and rx is a narrow parameter like ry (u16; s16 gives the same code). A narrow rx pins
 *   its home store above the first p+0x181C load (docs/idioms/a-narrow-parameter-pins-its-home-store-
 *   to-the-front-of-the-prologue.md). The only residue left is the n store/reload at +013C (all later
 *   bytes are the 2-byte shift). Probe: a second reaching def of n before the k compare (`if (t == 5)
 *   n = 3;`, not a fix) gives the image's str/ldr/muls exactly, so in the image n has a second
 *   definition that reaches the multiply or the k compare. A def that does not reach (prologue
 *   `n = field; lim = 0x1249 * n;`, a dead `n = 0` at the loop end) changes nothing. Also tried, all 521:
 *   `while (t >= (n = field) * 0x1249) t -= n * 0x1249;`, `while (t >= (lim = (n = field) * 0x1249))`,
 *   `while (t >= (lim = n * 0x1249))`, `while (t >= n * 0x1249) t -= n * 0x1249;`, an explicit if guard
 *   plus do-while, n read through a struct field `((Hdr *)p)->n` (also in the first loop).
 *   More (all compiled): `lim = 0x1249; lim *= n;` after `n = field` (520: str moves above the muls,
 *   still no reload, muls r1,r2,r1); `lim = 0x1249` before `n = field` (525); a `for (;;)` with break
 *   (605); n as a 6th function parameter (probe only, 56 B: parameters are not copy-propagated, the
 *   reload appears at [sp,#0x6c]); reusing the speed parameter for n (612/888). Inline helpers for the
 *   tail (wrap loop, if, k, cur pick) with n as a helper parameter: with `u8 *cur = old;` inside the
 *   helper (668) the image's `str r1,[sp,#8]; ldr r1,[sp,#8]; muls` appears, but the helper adds a
 *   `ldr [sp,#0x14]; str [sp,#0x10]` copy for cur after the t loop (the image stores cur at the call,
 *   +010A); with cur passed by pointer (`u8 **pcur`, 521) or with two returns (663) n is propagated
 *   again. Reading: the image's n is a copy that mwcc does not propagate (a parameter-like variable),
 *   and something sits between `n = field` and the multiply in the IR without code of its own.
 * 2026-10-05 (wD9r lane86): DIFF, residue unchanged (521 bytes, only the n str/ldr at +013C). New
 *   tries, each compiled, all 521 unless noted: k and the second wrap in an inline helper called before
 *   the condition (the divide is not sunk into the if); `t = Wrap(t, n)` inline helper with an int
 *   return; the whole f(e)..pick segment as an inline helper returning cur (523, old/cur stores swap);
 *   `GetCount(p, &n)` inline out-parameter; `register u16 n`; block-local `const u16 n`; `int unit =
 *   0x1249` at the top used in one, two or all three places; the wrap on a copy `f = t`; n reused for the
 *   (u16)(0x6E00 - a) and (u16)(0x78E0 - a) temps; the frame index written into n (`if (k >= n) n = k -
 *   n; else n = k;`, both orders); `lim = field * 0x1249` with `n = field` after the wrap; the n def
 *   behind a goto label; `for (n = field; t >= n * 0x1249; )`; `int speed` reused for n (888).
 *   Findings: (1) n = field written in both arms of `if (t < 0) { while (t < 0) ...; n = field; } else n
 *   = field;` gets cross-jumped into one tail and gives the reload, but the inner while keeps a redundant
 *   `cmp r0,#0; bge` (635), and the reload sits in the join block (str before the pool load, the image
 *   has the pool load first); with a do-while in the arm (630) the arm's n is CSE'd with the loop's
 *   hoisted load. (2) An intervening statement that needs a register between `n = field` and the
 *   multiply (a memory store, a spilled-local copy) also gives the reload; a store of a callee-saved
 *   value (`cur = spr`), a register copy, or a constant assignment does not. (3) A reaching second def
 *   after the wrap (`if (t == 5) n = 3;`, probe) reproduces the image's exact order (pool load, str,
 *   ldr, muls), so the image's n most likely has a second reaching def or is parameter-like; no natural
 *   codeless form found.
 * 2026-10-05 (wD9r lane116): DIFF, residue unchanged (521 bytes, only the n str/ldr at +013C). Twin
 *   search: 0x1249 appears only in ov133 021B6100 (frame pick as `m = F * 0x1249; if (t >= m) x = (t - m)
 *   / 0x1249; else ...`, no n local) and 021B6F00 (init); no matched copy of this routine. New tries
 *   (F = the u16 at p+0xA8), each compiled: n as a one-field local struct (521, scalarised); `while (t <
 *   0) { n = F; t += n * 0x1249; } n = F;` (964/635: the +0134 block is now byte-exact, str/ldr/muls in the
 *   image order, but hoisting the loop assignment adds a re-test `cmp r0,#0; bge` after the preheader);
 *   the same with `(n = F)` in the loop expression and as a for loop (635); `if (t < 0) { n = F; do ...
 *   while }` and `if (t < 0) do { n = F; ... } while` (521); `if (t < 0) { n = F; while ... }` (635,
 *   re-test); `n = F` before the first loop (631, CSE); if/else arms with a for(;;)+break or do-while
 *   loop and `n = F` in both arms (630, 632: CSE with the hoisted load); n re-read (`n = F`) inside the
 *   condition block before or after k, or only there with `lim = F * 0x1249` (521, CSE'd away); no n and
 *   F read at the k compare (521); a later def that reads n (`n += k` or `n = k - n` with a use after,
 *   562/563, no reload); `else n = 3` after the k compare (no reload). Probes (not fixes): moving the
 *   loop-top `sc = 0` (store to the address-taken sc) between `n = F` and the multiply gives the image's
 *   str/ldr/muls (115 bytes left, all from the moved strh), so any memory store there blocks the load
 *   forwarding into the multiply; a def of n inside the condition block before k (`if (t == 5) n = 3;`)
 *   also gives it, a def after the k compare does not. Open: a codeless memory kill or a codeless
 *   second def between +0138 and +0184; none of the image's stores fits.
 */
void *func_021B765C(u8 *p, u16 base, s16_021B765C speed, u16 rx, u16 ry)
{
    Vec v;
    Vec w;
    Pair_021B6100 pos;
    s16_021B765C sc;
    int idx;
    u16 rot;
    int offx;
    int offy;
    int sx;
    int sy;
    u8 *old;
    u8 *cur;
    u16 a;
    u8 *e;
    u8 *spr;
    int t;
    u16 k;
    int lim;
    u16 n;
    const s16_021B765C *tp;
    u32 h = 0x8000;
    int sh = 0xC0000;

    idx = 0;
    e = func_021BA184((char *)(*(u8 **)(p + 0x181C)));
    *(int *)(p + 0x1834) += speed;
    if (*(int *)(p + 0x1834) < 0)
        *(int *)(p + 0x1834) += *(u16 *)(p + 0xA8) * 0x1249;
    lim = 0x1249 * *(u16 *)(p + 0xA8);
    if (*(int *)(p + 0x1834) >= lim)
        *(int *)(p + 0x1834) -= lim;
    rot = *(u16 *)(p + 0x1838);
    offx = (FX_SinCosTable_[0] - FX_SinCosTable_[(rot >> 4) * 2]) << 3;
    offy = FX_SinCosTable_[1] - 0x8008 - FX_SinCosTable_[(rot >> 4) * 2 + 1] * -8;
    if (speed > 0x9C4 || speed < -0x9C4) {
        if (*(u16 *)(p + 0x18C2) == 0) {
            *(u16 *)(p + 0x18C2) = 30;
            GFL_USE_PlaySeDefaultVolume(0x624);
        }
    }
    if (e == 0)
        goto end;
    do {
        a = (u16)((base + (idx << 16) / 14) % 0x10000);
        sc = 0;
        spr = (u8 *)func_021BA218(e);
        tp = &FX_SinCosTable_[(a >> 4) * 2];
        sx = tp[0] * rx + 0x80000;
        sy = tp[1] * ry + 0x50000;
        cur = old = (u8 *)func_021BA20C(e);
        t = *(int *)(p + 0x1834) + (a + 0x8000) % 0x10000;
        while (t < 0)
            t += *(u16 *)(p + 0xA8) * 0x1249;
        for (n = *(u16 *)(p + 0xA8); t >= n * 0x1249; n = *(u16 *)(p + 0xA8))
            t -= n * 0x1249;
        if (*(int *)(p + 0x98) == 0 || *(u32 *)(p + 0x9C) > (u32)((0x18000 - a) % 0x10000)) {
            k = (u16)((t + 0x924) / 0x1249);
            if (k >= n)
                k = (u16)(k - n);
            cur = *(u8 **)(p + k * 4 + 0x1434);
            func_021BA210(e, (u32)cur);
            if (*(u16 *)old != *(u16 *)cur && e == *(u8 **)(p + 0x38))
                *(u8 **)(p + 0x38) = 0;
        }
        if (a >= h)
            a = (u16)((h << 1) - a);
        pos.x = (int)((float)sx / 4096.0f);
        pos.y = (int)((float)sy / 4096.0f);
        v.x = sx + offx;
        v.y = sy + offy;
        v.z = (h - a) + 0x14000;
        func_021F4E8C(*(int *)(p + 0x1884), (int)spr, &v);
        func_021F4ED4(*(int *)(p + 0x1884), (int)spr, rot);
        func_021BA21C(e, (const u8 *)(&pos));
        if (a < (h >> 1)) {
            sc = h >> 3;
            func_021F4EB4(*(int *)(p + 0x1884), (int)spr, h >> 3, h >> 3);
            func_021F4E6C((u8 *)(*(int *)(p + 0x1884)), (u8 *)((int)spr), 1);
            func_021BA244(e, h >> 3);
        } else if (a < 0x6E00) {
            sc = ((u16)(0x6E00 - a) << 11) / 0x2E00 + (h >> 4);
            func_021F4EB4(*(int *)(p + 0x1884), (int)spr, sc, sc);
            func_021F4E6C((u8 *)(*(int *)(p + 0x1884)), (u8 *)((int)spr), 1);
            func_021BA244(e, sc);
        } else if (a < 0x78E0) {
            sc = ((u16)(0x78E0 - a) << 11) / 0xAE0;
            func_021F4EB4(*(int *)(p + 0x1884), (int)spr, sc, sc);
            func_021F4E6C((u8 *)(*(int *)(p + 0x1884)), (u8 *)((int)spr), 1);
            func_021BA244(e, sc);
        } else {
            func_021F4E6C((u8 *)(*(int *)(p + 0x1884)), (u8 *)((int)spr), 0);
            func_021BA244(e, 0);
            sc = 0;
        }
        if (*(int *)(cur + 0x10) == 1 && GetTimer(p) < 45) {
            w.x = v.x / 16;
            w.y = (sh - (v.y + 0x8000)) / 16;
            w.z = v.z + (sh >> 9);
            BILLBOARD_SetElemPos((u8 *)(*(int *)(p + 0x188C)), *(int *)(p + idx * 4 + 0x5C), (struct Trip *)(&w));
            BILLBOARD_SetElemScale((struct Manager0204F684 *)(*(int *)(p + 0x188C)), *(int *)(p + idx * 4 + 0x5C), &sc, &sc);
            BILLBOARD_SetElemVisible((void *)(*(int *)(p + 0x188C)), *(int *)(p + idx * 4 + 0x5C), (u32 *)d_021BA3E8);
        } else {
            BILLBOARD_SetElemVisible((void *)(*(int *)(p + 0x188C)), *(int *)(p + idx * 4 + 0x5C), (u32 *)d_021BA3E4);
        }
        e = (u8 *)func_021BA208(e);
        idx++;
    } while (e != 0);
end:
    return func_021BA184((char *)(*(u8 **)(p + 0x181C)));
}








void func_021B7A18(u8 *p)
{
    u8 *e = func_021BA184(((struct Obj00004 *)p)->f181C);
    u8 *q;
    u8 *s;
    while (e) {
        q = (u8 *)func_021BA20C(e);
        s = (u8 *)func_021BA218(e);
        if (((struct Obj06496 *)q)->fC == 1)
            func_021F4D74(*(u8 **)(p + 0x1884), s, ((struct Obj06496 *)q)->f0, ((struct Obj06496 *)q)->f8);
        else
            func_021F4D74(*(u8 * *)&((struct Obj00004 *)p)->f1884, s, ((struct Obj06496 *)q)->f0, ((struct Obj06496 *)q)->f4);
        e = (u8 *)func_021BA208(e);
    }
}







void func_021B7A70(u8 *p)
{
    int moved=0,other=0,hit=0,outer,n,dx,dy;
    if(((struct Obj00004 *)p)->f183C==0){((struct Obj00004 *)p)->f14=TOUCHPANEL_GetTrg();((struct Obj00004 *)p)->f18=TOUCHPANEL_GetPointCont((u32 *)(p+0x1c),(u32 *)(p+0x20));}
    if(((struct Obj00004 *)p)->f14!=0 || ((struct Obj00004 *)p)->f18!=0){
        if(((struct Obj00004 *)p)->f20>176)((struct Obj00004 *)p)->f20=176;
        if(((struct Obj00004 *)p)->f20<16)((struct Obj00004 *)p)->f20=16;
        if(((struct Obj00004 *)p)->f3C==2 && *(u8 * *)&((struct Obj00004 *)p)->f38)func_021B7F54(p,1);
        else if(((struct Obj00004 *)p)->f14==1){
            hit=func_021B7F00(p,((struct Obj00004 *)p)->f1824,3);
            if(hit==1){func_021BA148(((struct Obj00004 *)p)->f1824,*(u8 * *)&((struct Obj00004 *)p)->f38);func_021BA100(((struct Obj00004 *)p)->f1820,*(u8 * *)&((struct Obj00004 *)p)->f38);func_021B7F54(p,0);}
            else other=func_021B8930(p);
        }
        if(hit==0 && other==0 && ((*(u8 * *)&((struct Obj00004 *)p)->f38==0 && ((struct Obj00004 *)p)->f14==1)||((struct Obj00004 *)p)->f3C==1)){
            dy=(s16_021B6BA4)(((struct Obj00004 *)p)->f20-80);dx=(s16_021B6BA4)(*(u32 *)&((struct Obj00004 *)p)->f1C-128);
            hit=func_021B8FF4(dx,dy,28,0.5384615659713745f);
            outer=func_021B8FF4(dx,dy,68,0.739130437374115f);
            if(hit==0 && outer==1){moved=1;func_021B7CFC(p,dx,dy);}
            else if((hit==0 && outer==0)||(hit==1 && outer==1)){
                if(func_021BA18C(((struct Obj00004 *)p)->f1820)==0 && ((struct Obj00004 *)p)->f3C==1 && *(u8 * *)&((struct Obj00004 *)p)->f38){
                    n=((struct Obj00004 *)p)->f182E;if(n<0)n=-n;
                    if(n<364)func_021B8140(p);
                }
            }
            if(moved==0 && ((struct Obj00004 *)p)->f14==1)func_021B7F00(p,((struct Obj00004 *)p)->f1820,2);
        }
        if(((struct Obj00004 *)p)->f14!=0 && *(u8 * *)&((struct Obj00004 *)p)->f38==0 && ((struct Obj00004 *)p)->f20>160 && *(u32 *)&((struct Obj00004 *)p)->f1C>96 && *(u32 *)&((struct Obj00004 *)p)->f1C<160){
            ((struct Obj00004 *)p)->fC=2;((struct Obj00004 *)p)->f10=0;GFL_USE_PlaySeDefaultVolume(0x622);func_021BA098(p);
        }
    }else {
        dy=(s16_021B6BA4)(((struct Obj00004 *)p)->f28-80);dx=(s16_021B6BA4)(((struct Obj00004 *)p)->f24-128);
        hit=func_021B8FF4(dx,dy,28,0.5384615659713745f);outer=func_021B8FF4(dx,dy,68,0.739130437374115f);
        if(((struct Obj00004 *)p)->f3C==2 && *(u8 * *)&((struct Obj00004 *)p)->f38){
            if(((struct Obj00004 *)p)->f34!=10)func_021B8444(p);
            else if(hit==0 && outer==1)func_021B82E8(p,0);
            else if(hit==1)func_021B8680(p);
            else func_021B8254(p);
        }
        ((struct Obj00004 *)p)->f30=0;*(int *)&((struct Obj00004 *)p)->f38=0;((struct Obj00004 *)p)->f3C=0;((struct Obj00004 *)p)->f40=0;((struct Obj00004 *)p)->f34=10;
    }
    if(((struct Obj00004 *)p)->f182E!=0 && moved==0){
        n=((struct Obj00004 *)p)->f182C+0x10000-((struct Obj00004 *)p)->f182E;if(n<0)n+=0x10000;if(n>=0x10000)n-=0x10000;
        ((struct Obj00004 *)p)->f182C=n;func_021B765C(p,((struct Obj00004 *)p)->f182C,((struct Obj00004 *)p)->f182E,72,48);
        if(((struct Obj00004 *)p)->f182E>128 || ((struct Obj00004 *)p)->f182E<-128)((struct Obj00004 *)p)->f182E*=0.75f;
        else ((struct Obj00004 *)p)->f182E=0;
    }
    ((struct Obj00004 *)p)->f24=*(u32 *)&((struct Obj00004 *)p)->f1C;((struct Obj00004 *)p)->f28=((struct Obj00004 *)p)->f20;
}







void func_021B7CFC(u8 *p, int unused_x, int unused_y)
{
    int y0,y1,angle,hit,n;
    u8 *e,*data;
    y0=(((struct Obj00220 *)p)->f28*72)/48;
    y1=(((struct Obj00220 *)p)->f20*72)/48;
    angle=func_0203F768(((struct Obj00220 *)p)->f24,y0,((struct Obj00220 *)p)->f1C,y1,128,80,72);
    ((struct Obj00220 *)p)->f1830+=(u16)(angle<0?-angle:angle);
    if(((struct Obj00220 *)p)->f14==1 || ((struct Obj00220 *)p)->f1830>=0x71c){
        e=func_021BA184(((struct Obj00220 *)p)->f181C);hit=0;
        if(((struct Obj00220 *)p)->f14==1)*(u16 *)&((struct Obj00220 *)p)->f182E=0;
        ((struct Obj00220 *)p)->f1830=0;*(u8 * *)&((struct Obj00220 *)p)->f38=0;
        while(e){
            data=(u8 *)func_021BA20C(e);
            if(func_021BA25C(e,((struct Obj00220 *)p)->f1C,*(int *)&((struct Obj00220 *)p)->f20)==1){
                hit=1;
                if(((struct Obj23311 *)data)->fC==0){*(u8 * *)&((struct Obj00220 *)p)->f38=e;((struct Obj00220 *)p)->f3C=1;e=0;}
            }
            if(*(u8 * *)&((struct Obj00220 *)p)->f38==0)e=(u8 *)func_021BA208(e);
        }
        if(((struct Obj00220 *)p)->f14==1 && hit==1 && *(u8 * *)&((struct Obj00220 *)p)->f38==0){((struct Obj00220 *)p)->f3C=1;GFL_USE_PlaySeDefaultVolume(0x557);}
    }
    if(((struct Obj00220 *)p)->f30==1){
        if((angle<0?-angle:angle)>227 && (angle<0?-angle:angle)<0x4000){
            n=((struct Obj00220 *)p)->f182C+0x10000-angle;
            if(n<0)n+=0x10000;
            if(n>=0x10000)n-=0x10000;
            ((struct Obj00220 *)p)->f182C=n;
            func_021B765C(p,((struct Obj00220 *)p)->f182C,(s16_021B6BA4)angle,72,48);
            if(angle>=0 && ((struct Obj00220 *)p)->f182E>0 && angle<((struct Obj00220 *)p)->f182E)
                ((struct Obj00220 *)p)->f182E=(((struct Obj00220 *)p)->f182E+angle)/2;
            else if(angle<=0 && ((struct Obj00220 *)p)->f182E<0 && angle>((struct Obj00220 *)p)->f182E)
                ((struct Obj00220 *)p)->f182E=(((struct Obj00220 *)p)->f182E+angle)/2;
            else ((struct Obj00220 *)p)->f182E=angle;
            n=((struct Obj00220 *)p)->f182E;
            if((n>0 && ((struct Obj00220 *)p)->f1838>0)||(n<0 && ((struct Obj00220 *)p)->f1838<0))((struct Obj00220 *)p)->f1838=0;
            else if(n>0 && ((struct Obj00220 *)p)->f1838>-0x3000){
                if(n*15>((struct Obj00220 *)p)->f1838*-10)((struct Obj00220 *)p)->f1838-=256;
            } else if(n<0 && ((struct Obj00220 *)p)->f1838<0x3000){
                if(n*-15>((struct Obj00220 *)p)->f1838*10)((struct Obj00220 *)p)->f1838+=256;
            }
        }else ((struct Obj00220 *)p)->f182E=0;
    }
    ((struct Obj00220 *)p)->f30=1;
}







int func_021B7F00(u8 *p, void *q, u32 a)
{
    u8 *e = func_021BA184(q);
    u32 *v;
    while (e) {
        if (func_021BA25C(e, ((struct Obj04522 *)p)->f1C, ((struct Obj04522 *)p)->f20) == 1) {
            v = (u32 *)func_021BA228(e);
            ((struct Obj04522 *)p)->f3C = 2;
            *(u8 * *)&((struct Obj04522 *)p)->f38 = e;
            GFL_USE_PlaySeDefaultVolume(0x623);
            ((struct Obj04522 *)p)->f40 = a;
            ((struct Obj04522 *)p)->f44 = v[0];
            ((struct Obj04522 *)p)->f48 = v[1];
            return 1;
        }
        e = (u8 *)func_021BA208(e);
    }
    return 0;
}





void func_021B7F54(u8 *p,int sound)
{
    Vec v;
    Pair_021B6100 pos,relative;
    Scale_021B6100 scale;
    int old,index;
    u8 *sprite,*q;
    u16 rotation=0;
    scale.limit=12;v=d_021BA5A0;
    old=((struct Obj00004 *)p)->f34;sprite=(u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
    relative.x=((struct Obj00004 *)p)->f1C-128;relative.y=*(int *)&((struct Obj00004 *)p)->f20-112;
    index=func_021B8BB4(p,sprite,(const int *)&relative,&scale.limit);((struct Obj00004 *)p)->f34=index;
    if(index!=10){
        q=func_021F5450(*(u8 * *)&((struct Obj00004 *)p)->f1880,index);
        pos.x=(int)((float)(((struct Obj06497 *)q)->f4+((struct Obj06497 *)q)->f10)/4096.f)+128;
        pos.y=(int)((float)(((struct Obj06497 *)q)->f8+((struct Obj06497 *)q)->f14)/4096.f)+96;
        rotation=((struct Obj06497 *)q)->f36;func_021F4EE8(*(int *)&((struct Obj00004 *)p)->f1884, (Flags *)((int)sprite), 1);
        if(func_021F4B24(sprite)==1)v.z=0x1a000;
        if(func_021B8B78(p,((struct Obj00004 *)p)->f34)==0){((struct Obj00004 *)p)->f40=3;((struct Obj00004 *)p)->f44=pos.x;((struct Obj00004 *)p)->f48=pos.y;}
        func_021BA254((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),((struct Obj00004 *)p)->f34);
        if(old!=((struct Obj00004 *)p)->f34 && sound==1)GFL_USE_PlaySeDefaultVolume(0x627);
    }else{
        ((struct Obj00004 *)p)->f34=10;pos.x=((struct Obj00004 *)p)->f1C;pos.y=*(int *)&((struct Obj00004 *)p)->f20;
        func_021F4EE8(*(int *)&((struct Obj00004 *)p)->f1884, (Flags *)((int)sprite), rotation);
    }
    if(pos.x>0)v.x=(int)(0.5f+(float)(int)((u32)pos.x<<12));else v.x=(int)((float)(int)((u32)pos.x<<12)-0.5f);
    if(pos.y>0)v.y=(int)(0.5f+(float)(int)((u32)pos.y<<12));else v.y=(int)((float)(int)((u32)pos.y<<12)-0.5f);
    func_021F4E8C(*(int *)(p+0x1884),(int)sprite,&v);
    func_021BA21C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&pos));
    q=(u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);func_021F4ED4(*(int *)(p+0x1884),(int)q,rotation);
    func_021F4EC4(*(int *)(p+0x1884),(int)sprite,&scale.x,&scale.y);
    if(scale.x<4096 || scale.y<4096){
        scale.x+=410;scale.y+=410;
        if(scale.x>4096)scale.x=4096;if(scale.y>4096)scale.y=4096;
        func_021F4EB4(*(int *)(p+0x1884),(int)sprite,scale.x,scale.y);
    }
}







void func_021B8140(u8 *p)
{
    Vec scale=d_021BA5B8;
    PairU_021B8140 pos;
    Scale_021B8140 old;
    u8 *q,*data,*s,*t;
    u32 *v;
    data=(u8 *)func_021BA20C(*(u8 * *)&((struct Obj00004 *)p)->f38);
    pos.x=*(u32 *)&((struct Obj00004 *)p)->f1C;pos.y=((struct Obj00004 *)p)->f20;
    if(pos.x!=0) scale.x=(int)(0.5f+(float)(pos.x<<12));
    else scale.x=(int)((float)(pos.x<<12)-0.5f);
    if(((struct Obj00004 *)p)->f20!=0) scale.y=(int)(0.5f+(float)(((struct Obj00004 *)p)->f20<<12));
    else scale.y=(int)((float)(((struct Obj00004 *)p)->f20<<12)-0.5f);
    q=func_021BA19C(((struct Obj00004 *)p)->f0,((struct Obj00004 *)p)->f1884,data,(int *)(&scale));
    func_021BA100(((struct Obj00004 *)p)->f1820,q);
    func_021BA21C(q,(const u8 *)(&pos));
    s=(u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);t=(u8 *)func_021BA218(q);
    func_021F4EC4(*(int *)&((struct Obj00004 *)p)->f1884,(int)s,&old.x,&old.y);
    func_021F4EB4(*(int *)&((struct Obj00004 *)p)->f1884,(int)t,old.x,old.y);
    func_021F4EE8(*(int *)&((struct Obj00004 *)p)->f1884,(Flags *)t,0);
    v=(u32 *)func_021BA228(*(u8 * *)&((struct Obj00004 *)p)->f38);
    *(u32 *)&((struct Obj00004 *)p)->f40=1;
    *(u32 *)&((struct Obj00004 *)p)->f44=v[0];*(u32 *)&((struct Obj00004 *)p)->f48=v[1];
    *(u32 *)&((struct Obj00004 *)p)->f3C=2;*(u8 * *)&((struct Obj00004 *)p)->f38=q;*(u32 *)&((struct Obj00004 *)p)->f40=1;
    ((struct Obj23312 *)data)->fC=1;
    func_021B7A18(p);GFL_USE_PlaySeDefaultVolume(0x625);
}







void func_021B8254(u8 *p)
{
    Vec v;
    u8 *e, *s;
    int z = 0xa000;
    s = (u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021BA148(((struct Obj00004 *)p)->f1820, *(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021BA124(((struct Obj00004 *)p)->f1820, *(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021F4EB4(*(int *)&((struct Obj00004 *)p)->f1884, (int)s, 4096, 4096);
    e = func_021BA184(((struct Obj00004 *)p)->f1820);
    while (e) {
        s = (u8 *)func_021BA218(e);
        func_021F4EA4(*(int *)(p + 0x1884), (int)s, (u32)(&v));
        v.z = z;
        func_021F4E8C(*(int *)(p + 0x1884), (int)s, (Vec *)&v);
        z -= 1024;
        e = (u8 *)func_021BA208(e);
    }
}






/*
 * lever: Named halfword call-result local fixes comparison load order.
 */
void func_021B82E8(u8 *p, int unused)
{
    Vec v;
    Pair_021B8140 pos;
    Pair_021B8140 fallback;
    u8 *sprite, *data, *entry, *found;
    u16 key;
    func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
    sprite = (u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
    data = (u8 *)func_021BA20C(*(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021BA148(((struct Obj00004 *)p)->f1820, *(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021BA124(((struct Obj00004 *)p)->f1828, *(u8 * *)&((struct Obj00004 *)p)->f38);
    v = d_021BA588;
    pos.x = ((struct Obj00004 *)p)->f1C;
    pos.y = *(int *)&((struct Obj00004 *)p)->f20;
    if (((struct Obj00004 *)p)->f44 > 0) v.x = (int)(0.5f + (float)(((struct Obj00004 *)p)->f44 << 12));
    else v.x = (int)((float)(((struct Obj00004 *)p)->f44 << 12) - 0.5f);
    if (((struct Obj00004 *)p)->f48 > 0) v.y = (int)(0.5f + (float)(((struct Obj00004 *)p)->f48 << 12));
    else v.y = (int)((float)(((struct Obj00004 *)p)->f48 << 12) - 0.5f);
    func_021BA22C(*(u8 * *)&((struct Obj00004 *)p)->f38, (const u8 *)(&pos));
    func_021F4E8C(*(int *)&((struct Obj00004 *)p)->f1884, (int)sprite, (Vec *)&v);
    func_021F4EB4(*(int *)&((struct Obj00004 *)p)->f1884, (int)sprite, 4096, 4096);
    func_021BA244(*(u8 * *)&((struct Obj00004 *)p)->f38, 4096);
    found = 0;
    entry = func_021BA184(((struct Obj00004 *)p)->f181C);
    while (entry && !found) {
        key = *(u16 *)func_021BA20C(entry);
        if (key == ((struct Obj14149 *)data)->f0) found = entry;
        entry = (u8 *)func_021BA208(entry);
    }
    if (found) {
        func_021BA21C(*(u8 * *)&((struct Obj00004 *)p)->f38, (const u8 *)func_021BA228(found));
        func_021BA23C(*(u8 * *)&((struct Obj00004 *)p)->f38, func_021BA248((char *)found));
    } else {
        fallback = d_021BA568;
        func_021BA21C(*(u8 * *)&((struct Obj00004 *)p)->f38, (const u8 *)(&fallback));
        func_021BA23C(*(u8 * *)&((struct Obj00004 *)p)->f38, 0);
    }
    func_021BA24C((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38), 10);
    ((struct Obj14149 *)data)->fC = 0;
    func_021B7A18(p);
    GFL_USE_PlaySeDefaultVolume(1574);
}





/*
 * ABI: func_021F4B24 declared int here: its forwarded func_021F50D0 returns 0/1; original compares the returned r0 despite legacy void declarations.
 */
void func_021B8444(u8 *p)
{
    Vec v, first, second;
    Pair_021B8140 pos, offset;
    u8 *sprite,*entry,*s;
    Pair_021B8140 *old;
    int state,depth;
    func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
    sprite=(u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
    if(func_021B8B78(p,((struct Obj00004 *)p)->f34)==1) {
        state=func_021F50F4(((struct Obj00004 *)p)->f34);
        entry=func_021BA184(((struct Obj00004 *)p)->f1824);
        while(entry) {
            if(state==func_021F50F4(func_021BA258((char *)entry))) break;
            entry=(u8 *)func_021BA208(entry);
        }
        if(entry) {
            v=d_021BA570;
            s=(u8 *)func_021BA218(entry);
            func_021F4F04(s,&offset);
            func_021B7458(p,(int *)&pos);
            pos.x+=offset.x;
            pos.y+=offset.y;
            func_021BA148(((struct Obj00004 *)p)->f1824,entry);
            func_021BA124(((struct Obj00004 *)p)->f1820,entry);
            old=(Pair_021B8140 *)func_021BA228(entry);
            if(pos.x>0) v.x=(int)(0.5f+(float)(pos.x<<12));
            else v.x=(int)((float)(pos.x<<12)-0.5f);
            if(pos.y>0) v.y=(int)(0.5f+(float)(pos.y<<12));
            else v.y=(int)((float)(pos.y<<12)-0.5f);
            func_021BA22C(entry,(const u8 *)old);
            func_021F4E8C(*(int *)&((struct Obj00004 *)p)->f1884, (int)s, (Vec *)&v);
            func_021F4ED4(*(int *)&((struct Obj00004 *)p)->f1884,(int)s,0);
            func_021BA21C(entry,(const u8 *)(&pos));
            func_021BA24C((char *)entry,10);
            depth=0;
            entry=func_021BA184(((struct Obj00004 *)p)->f1820);
            while(entry) {
                s=(u8 *)func_021BA218(entry);
                func_021F4EA4(*(int *)(p+0x1884),(int)s,(u32)(&first));
                first.z=depth;
                func_021F4E8C(*(int *)(p+0x1884), (int)s, (Vec *)&first);
                depth-=1024;
                entry=(u8 *)func_021BA208(entry);
            }
        }
    }
    func_021BA148(((struct Obj00004 *)p)->f1820,*(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021BA124(((struct Obj00004 *)p)->f1824,*(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021F4EB4(*(int *)&((struct Obj00004 *)p)->f1884,(int)sprite,4096,4096);
    func_021BA254((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),((struct Obj00004 *)p)->f34);
    entry=func_021BA184(((struct Obj00004 *)p)->f1824);
    depth=0;
    while(entry) {
        s=(u8 *)func_021BA218(entry);
        func_021F4EA4(*(int *)(p+0x1884),(int)s,(u32)(&second));
        if(func_021F4B24(s)==1) second.z=depth+(102<<10);
        else if(func_021BA258((char *)entry)==7 || func_021BA258((char *)entry)==8) second.z=depth+(222<<10);
        else second.z=depth+(202<<10);
        func_021F4E8C(*(int *)(p+0x1884), (int)s, (Vec *)&second);
        depth-=1024;
        entry=(u8 *)func_021BA208(entry);
    }
}






/*
 * lever: Unsigned word state local restores the state/sprite register pair; int and long left DIFF7.
 * ABI: func_021F4B24 declared int here: its forwarded func_021F50D0 returns 0/1; original compares the returned r0 despite legacy void declarations.
 */
void func_021B8680(u8 *p)
{
    Vec a,b,c;
    Pair_021B8140 posA,currentB,posB,posC;
    unsigned int state;
    u8 *sprite,*record;
    u16 flag;
    if(((struct Obj00004 *)p)->f40==2) {
        a=d_021BA57C;
        sprite=(u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
        posA.x=((struct Obj00004 *)p)->f1C; posA.y=*(int *)&((struct Obj00004 *)p)->f20;
        if(((struct Obj00004 *)p)->f44>0) a.x=(int)(0.5f+(float)(((struct Obj00004 *)p)->f44<<12));
        else a.x=(int)((float)(((struct Obj00004 *)p)->f44<<12)-0.5f);
        if(((struct Obj00004 *)p)->f48>0) a.y=(int)(0.5f+(float)(((struct Obj00004 *)p)->f48<<12));
        else a.y=(int)((float)(((struct Obj00004 *)p)->f48<<12)-0.5f);
        func_021BA22C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&posA));
        func_021F4E8C(*(int *)&((struct Obj00004 *)p)->f1884, (int)sprite, (Vec *)&a);
        func_021BA21C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(p+0x44));
        func_021BA24C((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),10);
        func_021B8254(p);
        return;
    } else if(((struct Obj00004 *)p)->f40==3) {
        u8 *spriteB;
        spriteB=(u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
        state=func_021BA258((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38));
        record=func_021F5450(*(u8 * *)&((struct Obj00004 *)p)->f1880,state);
        posB.x=(int)((float)(((struct Obj06498 *)record)->f4+((struct Obj06498 *)record)->f10)/4096.0f)+128;
        posB.y=(int)((float)(((struct Obj06498 *)record)->f8+((struct Obj06498 *)record)->f14)/4096.0f)+96;
        if(posB.x>0) b.x=(int)(0.5f+(float)(posB.x<<12));
        else b.x=(int)((float)(posB.x<<12)-0.5f);
        if(posB.y>0) b.y=(int)(0.5f+(float)(posB.y<<12));
        else b.y=(int)((float)(posB.y<<12)-0.5f);
        if(func_021F4B24(spriteB)==1) b.z=102<<10;
        else if(func_021BA258((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38))==7 || func_021BA258((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38))==8) b.z=222<<10;
        else b.z=202<<10;
        flag=((struct Obj06498 *)record)->f36;
        func_021F4EE8(*(int *)&((struct Obj00004 *)p)->f1884,(Flags *)spriteB,1);
        func_021F4E8C(*(int *)&((struct Obj00004 *)p)->f1884, (int)spriteB, (Vec *)&b);
        func_021F4ED4(*(int *)&((struct Obj00004 *)p)->f1884,(int)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38),flag);
        func_021BA21C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&posB));
        currentB.x=((struct Obj00004 *)p)->f1C; currentB.y=*(int *)&((struct Obj00004 *)p)->f20;
        func_021BA22C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&currentB));
        func_021BA24C((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),10);
        ((struct Obj00004 *)p)->f34=state;
        func_021B8444(p);
        ((struct Obj00004 *)p)->f34=10;
        return;
    } else if(((struct Obj00004 *)p)->f40==1) {
        func_021BA238(*(u8 * *)&((struct Obj00004 *)p)->f38);
        c=d_021BA5AC;
        sprite=(u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
        func_021BA21C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(p+0x44));
        func_021BA24C((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),10);
        posC.x=((struct Obj00004 *)p)->f1C; posC.y=*(int *)&((struct Obj00004 *)p)->f20;
        if(((struct Obj00004 *)p)->f44>0) c.x=(int)(0.5f+(float)(((struct Obj00004 *)p)->f44<<12));
        else c.x=(int)((float)(((struct Obj00004 *)p)->f44<<12)-0.5f);
        if(((struct Obj00004 *)p)->f48>0) c.y=(int)(0.5f+(float)(((struct Obj00004 *)p)->f48<<12));
        else c.y=(int)((float)(((struct Obj00004 *)p)->f48<<12)-0.5f);
        func_021BA22C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&posC));
        func_021F4E8C(*(int *)&((struct Obj00004 *)p)->f1884, (int)sprite, (Vec *)&c);
        func_021B82E8(p,1);
        return;
    }
    func_021B82E8(p,0);
}






/*
 * lever: Assign mode = 8 after the sort call; the compiler hoists its saved-register assignment between the r0 and r1 argument setups.
 * checks: 1 8BB4/9D54/765C arities verified; 2 matched/pending ov133 callers agree; 3 unsigned-long phase and long mode both DIFF4; 4 early-return/assignment-argument/volatile idioms tested; 5 fresh idiom listing and neighbours reread, stack pair already matches; permuter 300 baseline DIFF4 unchanged; next lever would be inline wrapper argument binding.
 * volatile: 0x021B89AC stores A4; 0x021B89B0 rereads that word for func_021B9D54.
 */
int func_021B8930(u8 *p)
{
    int pos[2];
    u16 limit = 16;
    u16 start;
    u32 phase;
    int mode = 0;
    int index;
    phase = ((struct Obj00004 *)p)->f1834 + 0x19249;
    if (phase >= ((struct Obj00004 *)p)->fA8 * 4681u)
        start = (phase - ((struct Obj00004 *)p)->fA8 * 4681u) / 4681u;
    else start = phase / 4681u;
    pos[0] = ((struct Obj00004 *)p)->f1C - 128;
    pos[1] = *(int *)&((struct Obj00004 *)p)->f20 - 112;
    index = func_021B8BB4(p, 0, pos, &limit);
    if (index != 10) {
    mode = func_021F50F4(index);
    if (mode == 7) mode = 6;
    if (mode == ((struct Obj00004 *)p)->fA4) {
        func_021B9028(p, 8, start);
        mode = 8;
    } else func_021B9028(p, mode, start);
    ((struct Obj00004 *)p)->fA4 = mode;
    func_021B9D54(p, *(volatile int *)&((struct Obj00004 *)p)->fA4);
    ((struct Obj00004 *)p)->f98 = 1;
    *(int *)&((struct Obj00004 *)p)->f9C = 0;
    ((struct Obj00004 *)p)->fA0 = ((struct Obj00004 *)p)->f182C % 4681 + 65536;
    if (((struct Obj00004 *)p)->fA0 >= 65536 && ((struct Obj00004 *)p)->fA0 <= 65538)
        ((struct Obj00004 *)p)->fA0 += 4681;
    func_021B765C(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
    GFL_USE_PlaySeDefaultVolume(1576);
    return 1;
    }
    return mode;
}






void func_021B8A30(u8 *p)
{
    u32 delta = ((struct Obj00004 *)p)->fA0 - ((struct Obj00004 *)p)->f9C;
    u32 step = delta / 10u;
    if (step < 256) {
        if (delta < 256) {
            step = delta;
            ((struct Obj00004 *)p)->f98 = 0;
        } else step = 256;
    }
    if (delta > 4096) {
        ((struct Obj00004 *)p)->f1838 -= 512;
        if (((struct Obj00004 *)p)->f1838 < -12288) ((struct Obj00004 *)p)->f1838 = -12288;
    } else func_021B8AC8(p);
    ((struct Obj00004 *)p)->f9C += step;
    ((struct Obj00004 *)p)->f182C -= (u16)step;
    func_021B765C(p, ((struct Obj00004 *)p)->f182C, step, 72, 48);
}






void func_021B8AC8(u8 *p)
{
    int n = ((struct Obj00004 *)p)->f182E;
    if (n < 0) n = -n;
    if (n < 48 && (((struct Obj00004 *)p)->f1838 != 0 || ((struct Obj00004 *)p)->f183A != 0)) {
        ((struct Obj00004 *)p)->f1838 += ((struct Obj00004 *)p)->f183A;
        if (((struct Obj00004 *)p)->f1838 > 0) {
            if (((struct Obj00004 *)p)->f183A > 0) ((struct Obj00004 *)p)->f183A -= 128;
            else ((struct Obj00004 *)p)->f183A -= 42;
        } else if (((struct Obj00004 *)p)->f1838 < 0) {
            if (((struct Obj00004 *)p)->f183A < 0) ((struct Obj00004 *)p)->f183A += 128;
            else ((struct Obj00004 *)p)->f183A += 42;
        }
        n = ((struct Obj00004 *)p)->f1838;
        if (n < 0) n = -n;
        if (n < 512) {
            n = ((struct Obj00004 *)p)->f183A;
            if (n < 0) n = -n;
            if (n < 512) {
                ((struct Obj00004 *)p)->f183A = 0;
                ((struct Obj00004 *)p)->f1838 = 0;
            }
        }
        func_021B765C(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
    }
}






int func_021B8B78(unsigned char *p,unsigned int id) {int key=func_021F50F4(id);unsigned char *q=func_021BA184((char *)(((struct Obj23314 *)p)->f1824));while(q){if(key==func_021F50F4(func_021BA258((char *)q)))return 1;q=(unsigned char *)func_021BA208(q);}return 0;}






static inline int coordinate(int value, Index offset)
{
    return (int)((float)value / 4096.0f) - offset;
}






/*
 * lever: Inline coordinate conversion with an enum offset keeps the zero subtract and matching spill homes.
 */
int func_021B8BB4(u8 *p, void *manager, const int *pos, u16 *limit)
{
    u16 distance;
    int best;
    int x;
    Index i;
    int enabled, y, dx, dy, n;
    u8 *q;
    distance = *limit * *limit;
    best = 10;
    for (i = I_ZERO; i < I_LIMIT; i++) {
        if (manager == 0) enabled = 1;
        else enabled = func_021F4AF0(manager, i);
        q = func_021F5450(*(u8 * *)&((struct Obj00004 *)p)->f1880, i);
        if (((struct Obj06499 *)q)->f0 == 1 && enabled == 1) {
            x = coordinate(((struct Obj06499 *)q)->f4 + ((struct Obj06499 *)q)->f10, I_ZERO);
            y = coordinate(((struct Obj06499 *)q)->f8 + ((struct Obj06499 *)q)->f14, (Index)16);
            dx = pos[0] - x;
            dy = pos[1] - y;
            n = dx * dx + dy * dy;
            if (n < distance) { distance = n; best = i; }
        }
    }
    *limit = distance;
    return best;
}






void func_021B8C6C(struct O *p)
{
    Vec v1;
    Vec v2;
    Vec v3;
    u32 cnt0;
    u8 *cur;
    int *A;
    int *B;
    int s;
    int flag;
    int n2;
    int *A2;
    int a0;
    int w;
    int a1;
    int a0b;
    int wb;
    int a1b;
    u8 *e;
    u32 data;
    u32 cnt;
    int n;
    int x;
    int d;
    s16_021B6100 sx;
    int *B2;
    u32 data2;
    e = func_021BA184((char *)p->f1828);
    if (e) {
        do {
            cur = e;
            data = (u32)func_021BA218(e);
            cnt = func_021BA250((char *)e);
            A = (int *)func_021BA238(e);
            B = (int *)func_021BA228(e);
            s = (s16_021B6100)func_021BA240(e);
            e = (u8 *)(unsigned char *)func_021BA208(e);
            n = (u16)(cnt - 1);
            if (n != 0) {
                x = s + ((0x1000 - s) * n) / 10;
                sx = x;
                func_021F4EB4((u32)p->f1884, data, sx, sx);
                func_021F4EA4((int)p->f1884, data, (u32)(&v1));
                w = 10 - (u16)n;
                a0 = A[0];
                x = B[0] - a0;
                x *= w;
                x = a0 + x / 10;
                if (x > 0) v1.x = (int)(0.5f + (float)(x << 12));
                else v1.x = (int)((float)(x << 12) - 0.5f);
                a1 = A[1];
                x = B[1] - a1;
                x *= w;
                x = a1 + x / 10;
                if (x > 0) v1.y = (int)(0.5f + (float)(x << 12));
                else v1.y = (int)((float)(x << 12) - 0.5f);
                v1.z = 0x46000;
                func_021F4E8C((int)p->f1884, data, (Vec *)&v1);
                func_021BA24C((char *)cur, n);
            } else {
                func_021BA148(p->f1828, cur);
                func_021BA1D8(cur, p->f1884);
            }
        } while (e);
    }
    flag = 0;
    e = func_021BA184((char *)p->f1820);
    if (e == 0) {
        flag = 1;
        e = func_021BA184((char *)p->f1824);
    }
    if (e) {
        do {
            cnt0 = func_021BA250((char *)e);
            if (cnt0 != 0) {
                data2 = (u32)func_021BA218(e);
                A2 = (int *)func_021BA238(e);
                B2 = (int *)func_021BA228(e);
                n2 = (u16)(cnt0 - 1);
                if (n2 != 0) {
                    func_021F4EA4((int)p->f1884, data2, (u32)(&v2));
                    wb = 10 - n2;
                    a0b = A2[0];
                    x = B2[0] - a0b;
                    x *= wb;
                    x = a0b + x / 10;
                    if (x > 0) v2.x = (int)(0.5f + (float)(x << 12));
                    else v2.x = (int)((float)(x << 12) - 0.5f);
                    a1b = A2[1];
                    x = B2[1] - a1b;
                    x *= wb;
                    x = a1b + x / 10;
                    if (x > 0) v2.y = (int)(0.5f + (float)(x << 12));
                    else v2.y = (int)((float)(x << 12) - 0.5f);
                    func_021F4E8C((int)p->f1884, data2, (Vec *)&v2);
                } else {
                    func_021F4EA4((int)p->f1884, data2, (u32)(&v3));
                    if (B2[0] > 0) v3.x = (int)(0.5f + (float)(B2[0] << 12));
                    else v3.x = (int)((float)(B2[0] << 12) - 0.5f);
                    if (B2[1] > 0) v3.y = (int)(0.5f + (float)(B2[1] << 12));
                    else v3.y = (int)((float)(B2[1] << 12) - 0.5f);
                    func_021F4E8C((int)p->f1884, data2, (Vec *)&v3);
                    func_021BA22C(e, (const u8 *)B2);
                }
                func_021BA24C((char *)e, n2);
            }
            e = (u8 *)(unsigned char *)func_021BA208(e);
            if (e == 0 && flag == 0) {
                flag = 1;
                e = func_021BA184((char *)p->f1824);
            }
        } while (e);
    }
}






void func_021B8FA8(u8 *p)
{
    if (*(u8 * *)&((struct Obj00004 *)p)->f38 == 0) {
        func_021F4E6C(((struct Obj00004 *)p)->f1884, ((struct Obj00004 *)p)->f4C, 0);
        return;
    }
    if (((struct Obj00004 *)p)->f50 == *(u16 *)func_021BA20C(*(u8 * *)&((struct Obj00004 *)p)->f38)) {
        func_021F4E6C(((struct Obj00004 *)p)->f1884, ((struct Obj00004 *)p)->f4C, 1);
        func_021F4E2C(((struct Obj00004 *)p)->f1884, (u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38), ((struct Obj00004 *)p)->f4C);
    }
}






int func_021B8FF4(int x,int y,int radius,float scale) {short k=(short)((float)x*scale);if(k*k+y*y<radius*radius)return 1;return 0;}







/*
 * lever: explicit redundant pointer/bound temporaries from the bounded permuter settled the three spill homes.
 */
void func_021B9028(u8 *p, int kind, u16 start)
{
    u8 *positionptr;
    u16 i, j, index, position, weight, next, best;
    u8 *tmp;
    u8 *tmp1;
    u8 **tmp2;
    u16 tmp3, tmp4;
    for (i = 0; i < ((struct Obj03825 *)p)->fA8; i++) {
        index = (u16)((start + i) % ((struct Obj03825 *)p)->fA8);
        *(u8 **)(p + index * 4 + 0x1434) = (p + 0xAC) + i * 20;
    }
    for (i = 0; i < ((struct Obj03825 *)p)->fA8; i++) {
        position = (u16)((start + i) % ((struct Obj03825 *)p)->fA8);
        best = position;
        tmp1 = p + position * 4;
        positionptr = tmp1;
        weight = func_021B9118(p, *(u8 * *)&((struct Obj10571 *)positionptr)->f1434, kind);
        for (j = i + 1; j < *(u16 *)(p + 0xA8); j++) {
            tmp4 = *(u16 *)(p + 0xA8);
            tmp3 = tmp4;
            index = (u16)((start + j) % tmp3);
            next = func_021B9118(p, *(u8 **)(p + index * 4 + 0x1434), kind);
            if (weight < next) { weight = next; best = index; }
        }
        if (best != position) {
            tmp = *(u8 **)(positionptr + 0x1434);
            *(u8 **)(positionptr + 0x1434) = *(u8 **)(p + best * 4 + 0x1434);
            tmp2 = (u8 **)(p + best * 4 + 0x1434);
            *tmp2 = tmp;
        }
    }
}







u16 func_021B9118(u8 *p, u8 *q, int v)
{
    int a = func_021F4B10(((struct Obj03825 *)p)->f1884, ((struct Obj05409 *)q)->f0, v);
    int b = func_021F4AFC(((struct Obj03825 *)p)->f1884, ((struct Obj05409 *)q)->f0, v);
    int n;
    if (a == 1) {
        if (((struct Obj05409 *)q)->f10 == 1) n = 6000;
        else n = 5000;
    } else if (b == 1) {
        if (((struct Obj05409 *)q)->f10 == 1) n = 4000;
        else n = 3000;
    } else {
        if (((struct Obj05409 *)q)->f10 == 1) n = 2000;
        else n = 1000;
    }
    return n + (999 - ((struct Obj05409 *)q)->f0);
}








void func_021B918C(u8 *p)
{
    u8 *e;
    Pt r;
    func_021B765C(p, *(u16 *)(p + 0x182C), 0, (u16)(*(int *)(p + 0x10) + 0x48), (u16)(48.0f + (float)*(int *)(p + 0x10) * 0.6666667f));
    e = func_021BA184((char *)(*(u8 **)(p + 0x1820)));
    while (e) {
        int *pos = (int *)func_021BA228(e);
        int id = func_021BA218(e);
        int y;
        int x;
        int d;
        int dist, ang, k;
        const SC *sc;
        int v[3];
        x = (short)(pos[0] - 0x80);
        y = (short)(pos[1] - 0x50);
        d = x * x + y * y;
        dist = FX_Sqrt(FXI(d));
        ang = FX_Atan2Idx(FXI(y), FXI(x));
        func_021F4EA4((u32)(*(u8 **)(p + 0x1884)), id, (u32)v);
        k = dist + FXI(*(int *)(p + 0x10));
        sc = &FX_SinCosTable__Alt[ang >> 4];
        v[0] = (fx32)(((long long)sc->c * k + 0x800) >> 12) + 0x80000;
        k = dist + FXF((float)*(int *)(p + 0x10) * 0.6666667f);
        v[1] = (fx32)(((long long)sc->s * k + 0x800) >> 12) + 0x50000;
        func_021F4E8C((int)*(u8 **)(p + 0x1884), id, (Vec *)v);
        e = (u8 *)func_021BA208(e);
    }
    func_02040618(2, 3, -*(int *)(p + 0x10));
    r.x = 0x20;
    {
        int t = 0xC0 - *(int *)(p + 0x10);
        if (t >= 0x40) t = 0x40;
        r.y = t + 0xA0;
    }
    CLACT_AddActorSurfacePos((struct Obj *)(*(u8 **)(p + 0x184C)), (const struct Vec2 *)(&r), 0);
    r.x = 0xE0;
    {
        int t = 0xC0 - *(int *)(p + 0x10);
        if (t >= 0x40) t = 0x40;
        r.y = t + 0xA0;
    }
    CLACT_AddActorSurfacePos((struct Obj *)(*(u8 **)(p + 0x1850)), (const struct Vec2 *)(&r), 0);
}







int func_021B940C(u8 *p)
{
    Rects rects = d_021BA594;
    void *obj;
    TOUCHPANEL_GetPointCont((unsigned int *)(p + 0x1c), (unsigned int *)(p + 0x20));
    switch (TOUCHPANEL_HitTrg(&rects)) {
    case 0:
        func_021B96D8((char *)p);
        GFL_USE_PlaySeDefaultVolume(1358);
        func_021BA098(p);
        return 2;
    case 1:
        ((struct Obj00004 *)p)->fC = 6;
        ((struct Obj00004 *)p)->f10 = 192;
        GFL_USE_PlaySeDefaultVolume(1962);
        func_021B94C0(p);
        obj = func_0201EC64(((struct Obj00004 *)p)->f0);
        func_0201EEF4(obj, 0, ((struct Obj23318 *)(*(u8 * *)&((struct Obj23317 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4))->f4);
        func_021B9C08(p, 0, obj);
        func_0201ED04(obj);
        func_021BA098(p);
        break;
    case -1:
        func_021B952C(p);
        break;
    }
    func_021B8FA8(p);
    return 0;
}







void func_021B94C0(u8 *p)
{
    u8 i;
    u8 *e, *q;
    u16 index;
    for (i = 0; i < 9; i++)
        *(u16 *)(*(u8 * *)&((struct Obj23319 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4 + 0x16 + i * 6) = 0;
    e = func_021BA184(((struct Obj00004 *)p)->f1824);
    while (e) {
        index = func_021BA258((char *)e);
        q = func_021F5450(*(u8 * *)&((struct Obj00004 *)p)->f1880, index);
        func_021F4ED4((u32)(((struct Obj00004 *)p)->f1884), func_021BA218(e), ((struct Obj23320 *)q)->f36);
        e = (u8 *)func_021BA208(e);
    }
}






void func_021B952C(u8 *p)
{
    u8 *e, *best;
    unsigned int distance, n;
    *(int *)&((struct Obj00004 *)p)->f24 = ((struct Obj00004 *)p)->f1C;
    *(int *)&((struct Obj00004 *)p)->f28 = *(int *)&((struct Obj00004 *)p)->f20;
    ((struct Obj00004 *)p)->f14 = TOUCHPANEL_GetTrg();
    ((struct Obj00004 *)p)->f18 = TOUCHPANEL_GetPointCont((unsigned int *)(p + 0x1c), (unsigned int *)(p + 0x20));
    if (((struct Obj00004 *)p)->f14 == 1) {
        best = 0;
        distance = 256;
        e = func_021BA184(((struct Obj00004 *)p)->f1824);
        while (e) {
            n = func_021BA324(e, ((struct Obj00004 *)p)->f1C, *(int *)&((struct Obj00004 *)p)->f20);
            if (distance > n) { best = e; distance = n; }
            e = (u8 *)func_021BA208(e);
        }
        if (best) *(u8 * *)&((struct Obj00004 *)p)->f38 = best;
    }
    if (((struct Obj00004 *)p)->f18 == 1 && *(u8 * *)&((struct Obj00004 *)p)->f38) func_021B95AC(p);
    if (((struct Obj00004 *)p)->f18 == 0) {
        ((struct Obj00004 *)p)->f30 = 0;
        *(u8 * *)&((struct Obj00004 *)p)->f38 = 0;
    }
}





static inline int fx(int x)
{
    if(x>0) return (int)(0.5f+(float)(int)((unsigned)x<<12));
    return (int)((float)(int)((unsigned)x<<12)-0.5f);
}





void func_021B95AC(u8 *p)
{
    u16 index,angle;
    u8 *rec;
    u32 *xy;
    int dx,dy,stride,absval,y;
    s16_021B9028 old,adjust;
    index=func_021BA258((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38));
    rec=func_021F5450(*(u8 * *)&((struct Obj00004 *)p)->f1880,index);
    func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
    xy=(u32 *)func_021BA228(*(u8 * *)&((struct Obj00004 *)p)->f38);
    y=xy[1];
    dx=fx((int)(*(u32 *)&((struct Obj00004 *)p)->f1C-xy[0]));
    dy=fx((int)(((struct Obj00004 *)p)->f20-(unsigned)y));
    angle=func_0207CFB8(dx,dy);
    if(((struct Obj00004 *)p)->f30==1) {
        stride=index*6;
        old=*(s16_021B9028 *)(*(u8 * *)&((struct Obj23322 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4+stride+0x16);
        adjust=old+(s16_021B9028)(((struct Obj00004 *)p)->f2C-angle);
        if(adjust< -2730) adjust= -2730;
        if(adjust>2730) adjust=2730;
        ((struct Obj00004 *)p)->f18C4+=(s16_021B9028)(old-adjust);
        absval=((struct Obj00004 *)p)->f18C4;
        if(absval<0) absval= -absval;
        if(absval>1820) {
            ((struct Obj00004 *)p)->f18C4=0;
            GFL_USE_PlaySeDefaultVolume(1577);
        }
        func_021F4ED4((u32)(((struct Obj00004 *)p)->f1884),func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38),((struct Obj23321 *)rec)->f36+adjust);
        *(s16_021B9028 *)(*(u8 * *)&((struct Obj23323 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4+stride+0x16)=adjust;
    }
    ((struct Obj00004 *)p)->f2C=angle;
    ((struct Obj00004 *)p)->f30=1;
}




void func_021B96D8(char *p)
{
    u8 *sv = func_0200A628(*(void **)(*(char **)(p + 4) + 8));
    void *t;
    u8 i = 0;
    func_0200A604(*(void **)(*(char **)(p + 4) + 8));
    t = func_021BA184(*(char **)(p + 0x1824));
    while (t != 0 && i < 8) {
        u32 idx = (u16)func_021BA258(t);
        u8 *rec;
        u32 off;
        (char *)func_021F5450((u8 *)(*(char **)(p + 0x1880)), idx);
        rec = sv + i * 6;
        sv[i * 6] = idx;
        *(u16 *)(rec + 2) = *((u16 *)func_021BA20C(t));
        off = idx * 6;
        *(s16_021B9028 *)(rec + 4) = *(s16_021B9028 *)(*(char **)(*(char **)(p + 4) + 4) + off + 0x16);
        *(u16 *)(*(char **)(*(char **)(p + 4) + 4) + off + 0x14) = *((u16 *)func_021BA20C(t));
        *(u8 *)(*(char **)(*(char **)(p + 4) + 4) + off + 0x18) = i;
        t = (void *)func_021BA208(t);
        i++;
    }
}




void func_021B9784(u8 *p)
{
    Pos pos;
    u8 pal;
    pos.x=32;
    pos.y=p[0x18c0]*2+160;
    if(pos.y>=224) pos.y=224;
    CLACT_AddActorSurfacePos(((struct Obj06500 *)p)->f184C,(const struct Vec2 *)(&pos),0);
    pos.x=224;
    pos.y=p[0x18c0]*2+160;
    if(pos.y>=224) pos.y=224;
    CLACT_AddActorSurfacePos(((struct Obj06500 *)p)->f1850,(const struct Vec2 *)(&pos),0);
    pal=p[0x18c0]*24/60+4;
    if(pal>=11) pal=3;
    func_020413B0(2,10,44,12,12,pal);
    func_02041B6C(2);
}




void func_021B9818(u8 *p)
{
    unsigned i;
    ((struct Obj03826 *)p)->f183C=1;
    ((struct Obj03826 *)p)->f1844=0;
    p[0x1846]=1;
    i=5;
    do {
        if(*(int *)(*(u8 **)(p+(unsigned)i*4+0x1434)+12)!=1) break;
        i=(u16)(i+1);
        if(i==((struct Obj03826 *)p)->fA8) i=0;
    } while(i!=5);
    if(i==0) p[0x1847]=((struct Obj03826 *)p)->fA8-1;
    else p[0x1847]=i-1;
    ((struct Obj03826 *)p)->fC=0;
}




void func_021B987C(unsigned char *p) {((struct Obj00228 *)p)->f183C=0;((struct Obj00228 *)p)->fC=1;CLACT_SetActorDrawEnable(((struct Obj00228 *)p)->f1854,0);func_021B9C90(p);}


void func_021B98A0(u8 *p)
{
    Pair_021B98A0 firstA,firstB,secondA,secondB;
    Pos_021B98A0 pos;
    switch(p[0x1846]) {
    case 0: break;
    case 1: func_021B9990(p,p[0x1847]*4681,p[0x1847]*4681,p[0x1847]*15); break;
    case 2: func_021B9A88(p,30); break;
    case 3: func_021B9990(p,-(u16)(p[0x1847]*4681),-(p[0x1847]*4681),p[0x1847]*15); break;
    case 4: func_021B9A88(p,30); break;
    case 5: firstA=a1; firstB=b1; func_021B9AC0(p,&firstA.x,&firstB.x,60); break;
    case 6: func_021B9A88(p,30); break;
    case 7: secondA=a2; secondB=b2; func_021B9AC0(p,&secondA.x,&secondB.x,60); break;
    case 8: func_021B9A88(p,30); break;
    case 9: func_021B987C(p); return;
    }
    pos.x=((struct Obj00228 *)p)->f1C; pos.y=((struct Obj00228 *)p)->f20;
    CLACT_AddActorSurfacePos(((struct Obj00228 *)p)->f1854,(const struct Vec2 *)(&pos),0);
    func_021B75E0(p);
}


void func_021B9990(u8 *p,u16 a,int delta,u16 duration)
{
    int step,index;
    ((struct Obj00228 *)p)->f18=0;
    ((struct Obj00228 *)p)->f14=0;
    CLACT_SetActorDrawEnable(((struct Obj00228 *)p)->f1854,1);
    step=_s32_div_f(delta,duration);
    index=((u16)((int)((unsigned)a-(unsigned)step*((struct Obj00228 *)p)->f1844+65536)%65536)>>4)*2;
    *(unsigned *)&((struct Obj00228 *)p)->f1C=(unsigned)((float)(72*table[index]+0x80000)/4096.0f);
    *(unsigned *)&((struct Obj00228 *)p)->f20=(unsigned)((float)(48*table[index+1]+0x50000)/4096.0f);
    ((struct Obj00228 *)p)->f182C-=(u16)step;
    func_021B765C(p,((struct Obj00228 *)p)->f182C,step,72,48);
    ++((struct Obj00228 *)p)->f1844;
    if(((struct Obj00228 *)p)->f1844>duration) {
        ((struct Obj00228 *)p)->f1844=0;
        ++p[0x1846];
    }
}


void func_021B9A88(unsigned char *p,unsigned int limit) {*(unsigned int *)&((struct Obj00228 *)p)->f18=0;*(unsigned int *)&((struct Obj00228 *)p)->f14=0;(((struct Obj00228 *)p)->f1844)++;CLACT_SetActorDrawEnable(((struct Obj00228 *)p)->f1854,0);if(((struct Obj00228 *)p)->f1844>limit){((struct Obj00228 *)p)->f1844=0;(((struct Obj00228 *)p)->f1846)++;}}


void func_021B9AC0(u8 *p, int *a, int *b, u16 duration)
{
    int x, y;
    int count;
    ((struct Obj00228 *)p)->f18 = 1;
    if (((struct Obj00228 *)p)->f1844 == 0) ((struct Obj00228 *)p)->f14 = 1;
    else ((struct Obj00228 *)p)->f14 = 0;
    count = ((struct Obj00228 *)p)->f1844;
    y = a[1] + (b[1] - a[1]) * count / (int)duration;
    x = a[0] + (b[0] - a[0]) * count / (int)duration;
    ((struct Obj00228 *)p)->f1C = x;
    ((struct Obj00228 *)p)->f20 = y;
    CLACT_SetActorDrawEnable(((struct Obj00228 *)p)->f1854, 1);
    (((struct Obj00228 *)p)->f1844)++;
    if (((struct Obj00228 *)p)->f1844 > duration) {
        ((struct Obj00228 *)p)->f1844 = 0;
        (((struct Obj00228 *)p)->f1846)++;
    }
}


void func_021B9B48(u8 *p)
{
    ((struct Obj02197 *)p)->f18E4 = GF_FONT_Create(23, 0, 0, 0, ((struct Obj02197 *)p)->f0);
    ((struct Obj02197 *)p)->f18D8 = func_02045B38(0, 2, 33, ((struct Obj02197 *)p)->f0);
    ((struct Obj02197 *)p)->f18DC = func_02045B38(0, 2, 79, ((struct Obj02197 *)p)->f0);
    ((struct Obj02197 *)p)->f18E0 = func_02045B38(0, 2, 75, ((struct Obj02197 *)p)->f0);
    func_02049B40(23, 5, 4, 448, 32, ((struct Obj02197 *)p)->f0);
    ((struct Obj02197 *)p)->f18E8 = (void *)PRINTSYS_QUE_Create((void *)(((struct Obj02197 *)p)->f0));
    func_0201F5BC(7, 128, 12, 0, ((struct Obj02197 *)p)->f0);
}


void func_021B9BD0(unsigned char *p) {PRINTSYS_QUE_Delete(((struct Obj06501 *)p)->f18E8);MSGDATA_Delete(((struct Obj06501 *)p)->f18DC);MSGDATA_Delete(((struct Obj06501 *)p)->f18E0);MSGDATA_Delete(((struct Obj06501 *)p)->f18D8);GF_FONT_Delete(((struct Obj06501 *)p)->f18E4);}


void func_021B9C08(u8 *p, unsigned int index, void *object)
{
    void *text = func_02045EC0(((struct Obj00004 *)p)->f18D8, index);
    void *copy;
    PRINTSYS_QUE_Clear(((struct Obj00004 *)p)->f18E8);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00004 *)p)->f18EC), 15);
    if (object) {
        copy = STRBUF_Create(128, ((struct Obj00004 *)p)->f0);
        func_0201F250(object, copy, text);
        STRBUF_Delete(text);
        text = copy;
    }
    PRINTSYS_PrintQueColor(((struct Obj00004 *)p)->f18E8, (u32)BMP_WIN_GetBmp(((struct Obj00004 *)p)->f18EC), 2, 2, (u32)text, (u32)(((struct Obj00004 *)p)->f18E4), 1088);
    STRBUF_Delete(text);
    *(int *)&((struct Obj00004 *)p)->f18CC = 1;
}


void func_021B9C90(unsigned char *p) {void *r=func_0201EC64(((struct Obj00004 *)p)->f0);func_0201EEF4(r,0,((struct Obj23325 *)(*(unsigned char * *)&((struct Obj23324 *)(*(unsigned char * *)&((struct Obj00004 *)p)->f4))->f4))->f4);func_021B9C08(p,0,r);func_0201ED04(r);}


void func_021B9CBC(u8 *p, u8 *entry)
{
    void *manager = (void *)func_021F4F10(*(u8 * *)&((struct Obj00004 *)p)->f1884);
    u8 *data = (u8 *)func_021BA20C(entry);
    int index = func_021F5158(manager, ((struct Obj14153 *)data)->f0);
    void *obj = func_0201EC64(((struct Obj00004 *)p)->f0);
    void *a = func_02045EC0(((struct Obj00004 *)p)->f18DC, ((struct Obj14153 *)data)->f0 + 3);
    void *b = func_02045EC0(((struct Obj00004 *)p)->f18E0, index + 16);
    func_0201EE0C(obj, 0, a, 0, 1, 2);
    func_0201EE0C(obj, 1, b, 0, 1, 2);
    func_021B9C08(p, 3, obj);
    STRBUF_Delete(b);
    STRBUF_Delete(a);
    func_0201ED04(obj);
}


void func_021B9D54(u8 *p, int state)
{
    int index;
    void *w;
    void *str;
    if (state == 8) {
        func_021B9C08(p, 5, 0);
        return;
    }
    index = 0;
    switch (state) {
    case 0:
    case 1: index = 0x10; break;
    case 2: index = 0x11; break;
    case 3: index = 0x17; break;
    case 4: index = 0x14; break;
    case 5: index = 0x15; break;
    case 6:
    case 7: index = 0x16; break;
    }
    w = func_0201EC64(((struct Obj00004 *)p)->f0);
    str = func_02045EC0(((struct Obj00004 *)p)->f18E0, index);
    func_0201EE0C(w, 0, str, 0, 1, 2);
    func_021B9C08(p, 4, w);
    STRBUF_Delete(str);
    func_0201ED04(w);
}


void func_021B9DE8(u8 *p)
{
    Params_021B98A0 configs[2];
    int a,b,c,d,e,f,g,h;
    u8 i;
    i=0;
    a=0x1860;
    b=0x186c;
    c=0x1878;
    d=0x1890;
    e=0x1890;
    f=0x1890;
    g=0x1890;
    h=0x18b8;
    do {
        configs[1].x=0;configs[1].y=0;configs[1].index=0;configs[1].a=0;configs[1].b=0;
        *(void **)(p+(unsigned)i*4+d)=CLACT_CreateActor((void *)((struct Obj01062 *)p)->f1848,*(u32 *)(p+a),*(u32 *)(p+b),*(u32 *)(p+c),&configs[1],1,((struct Obj01062 *)p)->f0);
        CLACT_SetActorDrawEnable(*(void **)(p+(unsigned)i*4+e),1);
        CLACT_SetActorAutoAnim(*(void **)(p+(unsigned)i*4+f),1);
        CLACT_SetActorObjMode(*(void **)(p+(unsigned)i*4+g),0);
        p[(unsigned)i+h]=0;
        ++i;
    } while(i<8);
    configs[0].x=128;configs[0].y=96;configs[0].index=0;configs[0].a=0;configs[0].b=0;
    ((struct Obj01062 *)p)->f18B0=CLACT_CreateActor((void *)((struct Obj01062 *)p)->f1848,((struct Obj01062 *)p)->f185C,((struct Obj01062 *)p)->f1868,((struct Obj01062 *)p)->f1874,&configs[0],0,((struct Obj01062 *)p)->f0);
    CLACT_SetActorDrawEnable(((struct Obj01062 *)p)->f18B0,0);
    CLACT_SetActorAutoAnim(((struct Obj01062 *)p)->f18B0,1);
    configs[0].index=2;
    ((struct Obj01062 *)p)->f18B4=CLACT_CreateActor((void *)((struct Obj01062 *)p)->f1848,((struct Obj01062 *)p)->f185C,((struct Obj01062 *)p)->f1868,((struct Obj01062 *)p)->f1874,&configs[0],0,((struct Obj01062 *)p)->f0);
    CLACT_SetActorDrawEnable(((struct Obj01062 *)p)->f18B4,0);
    CLACT_SetActorAutoAnim(((struct Obj01062 *)p)->f18B4,1);
}


void func_021B9F24(unsigned char *p) {unsigned char i;for(i=0;i<8;i++)CLACT_DeleteActor(*(void **)((unsigned int)p+(unsigned int)i*4+0x1890));CLACT_DeleteActor(((struct Obj14154 *)p)->f18B4);CLACT_DeleteActor(((struct Obj14154 *)p)->f18B0);}


/*
 * lever: Pointer addition for timer stores and unsigned address addition for the guard preserve four independent offset homes and the decrement reload. Uniform integer addition gave 292 bytes; uniform pointer addition gave 304.
 * note 2026-10-05 (wave D9r lane 131): removed the 5 dead first assignments
 * (`a = 0x1890;` before `a = 0x18b8;`; `b = 0x1890;` before `b = 0x18b8;`
 * and 3 more). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021B9F5C(u8 *p)
{
    int a, b, delay, c, d;
    Pos_021B9F5C pos;
    u8 i;
    u8 *q, *t;
    a = 0x18b8;
    b = 0x18b8;
    delay = 0x190;
    c = 0x18b8;
    d = 0x18b8;
    for (i = 0; i < 8; i++) {
        q = p + i * 4;
        CLACT_SetActorBgPriority(((struct Obj06502 *)q)->f1890, func_020416D4(4));
        CLACT_SetActorObjMode(((struct Obj06502 *)q)->f1890, 0);
        t = p + i;
        if (*(u8 *)((u32)p+(u32)i+(u32)d) == 0) {
            pos.x = ((u64)func_0203F0A8() * 56) >> 32;
            if ((u32)(((u64)func_0203F0A8() * 2) >> 32) == 1) pos.x = 256 - pos.x;
            pos.y = ((u64)func_0203F0A8() * 192) >> 32;
            CLACT_AddActorSurfacePos(((struct Obj06502 *)q)->f1890, (const struct Vec2 *)(&pos), 1);
            if (pos.y > 90) CLACT_SetActorAnimSeq(((struct Obj06502 *)q)->f1890, ((u64)func_0203F0A8() * 2) >> 32);
            else CLACT_SetActorAnimSeq(((struct Obj06502 *)q)->f1890, (((u64)func_0203F0A8() * 2) >> 32) + 2);
            t[c] = (((u64)func_0203F0A8() * 200) >> 32) + delay;
        } else {
            t[b] = t[a] - 1;
        }
    }
    if (CLACT_GetActorDrawEnable(((struct Obj10572 *)p)->f18B4) == 1 && CLACT_IsActorAnimActive(((struct Obj10572 *)p)->f18B4) == 0) {
        CLACT_SetActorDrawEnable(((struct Obj10572 *)p)->f18B4, 0);
    }
}


void func_021BA098(u8*p){Pos_021BA098 pos;pos.x=((struct Obj00004 *)p)->f1C;pos.y=*(int *)&((struct Obj00004 *)p)->f20;CLACT_RestartActorAnim(*(struct Actor* *)&((struct Obj00004 *)p)->f18B4);CLACT_SetActorDrawEnable(*(void* *)&((struct Obj00004 *)p)->f18B4,1);CLACT_AddActorSurfacePos(*(void* *)&((struct Obj00004 *)p)->f18B4,(const struct Vec2 *)(&pos),0);}


void func_021BA0C8(u8 *p, u8 n){}


u8 *func_021BA0CC(u16 heap, int n){u8 *p;p=func_02030734(heap,16,0,d_021BA610,76);((struct Obj06503 *)p)->f0=heap;((struct Obj06503 *)p)->f4=0;((struct Obj06503 *)p)->f6=n;((struct Obj06503 *)p)->f8=0;((struct Obj06503 *)p)->fC=0;return p;}


void func_021BA0F8(void *p){func_020307B0(p);}


void func_021BA100(u8*p,u8*q){if(((struct Obj04523 *)p)->f4<((struct Obj04523 *)p)->f6){if(!*(u8* *)&((struct Obj04523 *)p)->f8)*(u8* *)&((struct Obj04523 *)p)->f8=q;else *(u8* *)&((struct Obj23326 *)(*(u8* *)&((struct Obj04523 *)p)->fC))->f30=q;*(u8* *)&((struct Obj04523 *)p)->fC=q;*(u8* *)&((struct Obj05410 *)q)->f30=0;(((struct Obj04523 *)p)->f4)++;}}


void func_021BA124(u8*p,u8*q){if(((struct Obj03827 *)p)->f4<((struct Obj03827 *)p)->f6){if(!*(u8* *)&((struct Obj03827 *)p)->f8){*(u8* *)&((struct Obj03827 *)p)->f8=q;*(u8* *)&((struct Obj03827 *)p)->fC=q;*(u8* *)&((struct Obj14155 *)q)->f30=0;}else{*(u8* *)&((struct Obj14155 *)q)->f30=*(u8* *)&((struct Obj03827 *)p)->f8;*(u8* *)&((struct Obj03827 *)p)->f8=q;}(((struct Obj03827 *)p)->f4)++;}}


void func_021BA148(u8*p,u8*q){u8 *prev;u8 *cur;prev=0;cur=*(u8* *)&((struct Obj06504 *)p)->f8;while(cur!=q && cur){prev=cur;cur=*(u8* *)&((struct Obj06505 *)cur)->f30;}if(cur){if(prev)*(u8* *)&((struct Obj06505 *)prev)->f30=*(u8* *)&((struct Obj06505 *)cur)->f30;else *(u8* *)&((struct Obj06504 *)p)->f8=*(u8* *)&((struct Obj06505 *)cur)->f30;if(*(u8* *)&((struct Obj06504 *)p)->fC==q)*(u8* *)&((struct Obj06504 *)p)->fC=prev;*(u8* *)&((struct Obj06505 *)cur)->f30=0;(((struct Obj06504 *)p)->f4)--;}}


void *func_021BA184(char *p){return *(void* *)&((struct Obj23327 *)p)->f8;}


unsigned short func_021BA188(char *p){return ((struct Obj23328 *)p)->f4;}



int func_021BA18C(char *p)
{
    return ((struct Obj14156 *)p)->f4 == ((struct Obj14156 *)p)->f6;
}


u8 *func_021BA19C(u16 heap, struct Object*q, u8*r, int*v){u8*p;p=func_02030734(heap,52,0,d_021BA610,204);*(u32 *)&((struct Obj05410 *)p)->f30=0;*(u8* *)&((struct Obj05410 *)p)->f4=r;*(u8 **)&((struct Obj05410 *)p)->fC=func_021F4C1C((u8 *)q,((struct Obj14157 *)r)->f0,((struct Obj14157 *)r)->f4,(Vec *)v);((struct Obj05410 *)p)->f1C=0;((struct Obj05410 *)p)->f20=10;return p;}


void func_021BA1D8(u8*p,u8*q){func_021F4D40(q,*(u8* *)&((struct Obj23329 *)p)->fC);func_020307B0(p);}


void func_021BA1EC(u8*p,u8*q,u8*r){*(u8* *)&((struct Obj14158 *)p)->f4=r;func_021F4D74(q,*(u8* *)&((struct Obj14158 *)p)->fC,((struct Obj14159 *)r)->f0,((struct Obj14159 *)r)->f4);}


u32 func_021BA208(u8 *p)
{
    return ((struct Obj23330 *)p)->f30;
}


u32 func_021BA20C(u8 *p)
{
    return ((struct Obj23331 *)p)->f4;
}


void func_021BA210(u8 *p, u32 value)
{
    ((struct Obj23332 *)p)->f8=value;
}


u32 func_021BA214(u8 *p)
{
    return ((struct Obj23333 *)p)->f8;
}


u32 func_021BA218(u8 *p)
{
    return ((struct Obj23334 *)p)->fC;
}


void func_021BA21C(u8 *p, const u8 *src)
{
    *(Pair_021BA21C *)(p+16)=*(const Pair_021BA21C *)src;
}


u8 * func_021BA228(u8 *p)
{
    return p+16;
}


void func_021BA22C(u8 *p, const u8 *src)
{
    *(Pair_021BA22C *)(p+36)=*(const Pair_021BA22C *)src;
}


u8 * func_021BA238(u8 *p)
{
    return p+36;
}


void func_021BA23C(u8 *p, u32 value)
{
    ((struct Obj23335 *)p)->f2C=value;
}


u32 func_021BA240(u8 *p)
{
    return ((struct Obj23336 *)p)->f2C;
}


void func_021BA244(u8 *p, u32 value)
{
    ((struct Obj23337 *)p)->f18=value;
}


int func_021BA248(char *p) { return ((struct Obj23338 *)p)->f18; }


void func_021BA24C(char *p, u32 v) { ((struct Obj23339 *)p)->f1C=v; }


u16 func_021BA250(char *p) { return ((struct Obj23340 *)p)->f1C; }


void func_021BA254(char *p, int v) { ((struct Obj23341 *)p)->f20=v; }


u32 func_021BA258(char *p) { return ((struct Obj23342 *)p)->f20; }


int func_021BA25C(u8 *p, int x, int y)
{
    s16_021BA25C s;
    int pos[2];
    u16 angle;
    s16_021BA25C c;
    int dx, dy;
    s16_021BA25C rx, ry;
    func_021F4F04((u8 *)((struct Obj04524 *)p)->fC, (Pair_021B8140 *)pos);
    if (func_021F4EFC(0, ((struct Obj04524 *)p)->fC) == 1) {
        func_021F4EE0(0, ((struct Obj04524 *)p)->fC, &angle);
        s = ((const s16_021BA25C *)FX_SinCosTable__Alt)[(angle >> 4) * 2];
        c = ((const s16_021BA25C *)FX_SinCosTable__Alt)[(angle >> 4) * 2 + 1];
        dx = (int)((float)(pos[0] * c - pos[1] * s) / 4096.0f);
        dy = (int)((float)(pos[0] * s + pos[1] * c) / 4096.0f);
        rx = ((struct Obj04524 *)p)->f10 - dx - x;
        ry = ((struct Obj04524 *)p)->f14 - dy - y;
    } else {
        rx = ((struct Obj04524 *)p)->f10 - x;
        ry = ((struct Obj04524 *)p)->f14 - y;
    }
    if (rx < 16 && rx > -16 && ry < 16 && ry > -16) return 1;
    return 0;
}
