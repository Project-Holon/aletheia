/*
 * file:     viewer_text.c
 * unit:     yes
 * function: VIEWER_TEXT_Init, VIEWER_TEXT_Exit, VIEWER_TEXT_Draw, VIEWER_TEXT_DrawTable, VIEWER_TEXT_DrawList, VIEWER_TEXT_FlushWindow, VIEWER_TEXT_DrawWindow, VIEWER_TEXT_PrintColorAt, VIEWER_TEXT_DrawRow, VIEWER_TEXT_SetScroll, VIEWER_TEXT_SetScrollParam, VIEWER_TEXT_DrawPage, VIEWER_TEXT_PrintNumber, VIEWER_TEXT_PrintDigits, VIEWER_TEXT_PrintString, VIEWER_TEXT_PrintStringClipped, VIEWER_TEXT_PrintStringPad, VIEWER_TEXT_PrintWrapped, VIEWER_TEXT_Print, VIEWER_TEXT_PrintRow, VIEWER_TEXT_NoOp, VIEWER_TEXT_InitActors, VIEWER_TEXT_CreateActor, VIEWER_TEXT_DeleteActors, VIEWER_TEXT_SetActorAnim, VIEWER_TEXT_Create, VIEWER_TEXT_Main, VIEWER_TEXT_Delete, VIEWER_TEXT_VBlank, VIEWER_TEXT_LoadResources, VIEWER_TEXT_FreeResources, VIEWER_TEXT_InitVram, VIEWER_TEXT_InitBg, VIEWER_TEXT_ExitBg, VIEWER_TEXT_LoadBgResources, VIEWER_TEXT_FreeBgResources, VIEWER_TEXT_InitClact
 * address:  0x021C6000
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_02041B6C  0x02041B6C  arm
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   d_021C8773  0x021C8773  data
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   STRBUF_SetString  0x02045924  arm
 *   PMS_DRAW_SetNullColorPalette  0x0202DE5C  thumb
 *   PMS_DRAW_Print  0x0202DC48  thumb
 *   PMS_DRAW_SetVisible  0x0202DCB0  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_02045B38  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GAME_DATA_GetSaveBlock21  0x02012F5C  thumb
 *   func_020089F4  0x020089F4  thumb
 *   CURSOR_MOVE_GetTableKind  0x02025C9C  thumb
 *   d_021C876C     0x021C876C  data  a1
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   d_021C8768     0x021C8768  data  a2
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   WORDSET_FormatNumber  0x0201F35C  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_020490F4  0x020490F4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   APP_ICON_GetMoveKindPaletteFileId  0x02027614  thumb
 *   APP_ICON_GetMoveKindAnimFileId  0x02027618  thumb
 *   APP_ICON_GetStatusCellFileId  0x0202761C  thumb
 *   APP_ICON_GetStatusPaletteFileId  0x02027620  thumb
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   gClActorInitParam     0x020A1448  data
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   d_021C87A4     0x021C87A4  data  a4
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   VIEWER_ACTOR_CreateObjects  0x021C75E4  thumb
 *   VIEWER_ACTOR_Init3D  0x021C76A4  thumb
 *   VIEWER_ACTOR_CreateModel  0x021C7744  thumb
 *   VIEWER_ACTOR_InitBgWindow  0x021C78C4  thumb
 *   VIEWER_ACTOR_CreateFont  0x021C7934  thumb
 *   VIEWER_ACTOR_SetSelection  0x021C81A4  thumb
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   VIEWER_ACTOR_DispatchState  0x021C79A0  thumb
 *   VIEWER_ACTOR_DrawModel  0x021C7830  thumb
 *   VIEWER_ACTOR_PrintQueMain  0x021C7970  thumb
 *   CLACT_DrawSystem  0x0204A600  arm
 *   VIEWER_ACTOR_DeleteFont  0x021C795C  thumb
 *   VIEWER_ACTOR_DeleteBgWindow  0x021C78F8  thumb
 *   VIEWER_ACTOR_DeleteModel  0x021C7808  thumb
 *   VIEWER_ACTOR_Exit3D  0x021C7730  thumb
 *   VIEWER_ACTOR_DeleteObjects  0x021C7658  thumb
 *   VIEWER_ACTOR_SetRtcDate  0x021C81C0  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_0203084C  0x0203084C  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   BG_SYS_FillScrollArea  0x02040618  arm
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   BG_SYS_Update  0x020419E4  arm
 *   STRBUF_GetChars  0x02045A90  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_Create  0x0201EC74  thumb
 *   func_020056A0  0x020056A0  thumb
 *   VIEWER_ACTOR_SetPageCount  0x021C80B4  thumb
 *   VIEWER_ACTOR_GetRtcDate  0x021C8208  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   d_021C88FC  0x021C88FC  data
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 *   d_021C895C  0x021C895C  data
 *   d_021C89E0  0x021C89E0  data
 *   d_021C885C  0x021C885C  data
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   APP_ICON_GetStatusAnimFileId  0x02027624  thumb
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb
 *   APP_ICON_GetStatusDataFileId  0x0202762C  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BMP_MENUWORK_LoadPltt  0x0201F57C  thumb
 *   BMP_MENUWORK_LoadChar  0x0201F554  thumb
 *   func_02049F78  0x02049F78  arm
 *   func_020307B0  0x020307B0  arm
 */
struct CharBuf;
struct Descriptor;
struct PrintSys;
struct PmsDraw;
struct Strbuf;
struct Cfg;
struct MsgBank;
struct Rec;
struct Sub020089A8Obj;
struct U16Vec;
struct StrObj;
struct WordSet;
struct PlayTime;
struct Bank;
struct Obj;
struct Actor;
struct Proc;
struct Proc;
struct Node;
struct DispVram;
struct DispConfig;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *win[8];
    u8 pad24[0x32CC - 0x24];
    void *f32CC;
    u8 pad32D0[4];
    u8 f32D4;
} Work_021C6000;

typedef unsigned int   u32;

typedef struct {
    u8 pad0[4];
    void *bg[8];
    u8 pad24[0x32CC - 0x24];
    void *f32CC;
} Work_021C60A0;

typedef short s16;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 pad5;
    u8 b6;
    u8 pad7[0xA - 7];
    u16 name[1];
    u8 padC[0x20 - 0xC];
    u32 f20;
    u32 f24;
    u8 pad28[0x48 - 0x28];
    u32 f48;
    u8 pad4C[0x6C - 0x4C];
    u8 f6C[1];
} Info_021C6000;

typedef struct {
    u8 pad0[0x28];
    Info_021C6000 *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x31FC - 0x3038];
    void *f31FC;
    u8 pad3200[0x3210 - 0x3200];
    void *f3210;
    void *f3214;
    u8 pad3218[0x322C - 0x3218];
    void *f322C[26];
    u8 pad3294[0x32B0 - 0x3294];
    void *f32B0;
} Work_021C60CC;

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
} Work_021C6C38;

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
    u8 pad3200[4];
    void *f3204;
    u8 pad3208[0x3294 - 0x3208];
    void *f3294[4];
    void *f32A4;
} Work_021C6B5C;

typedef struct {
    u8 pad0[4];
    void *f4;
} Sub24;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *bg[7];
    u8 pad20[4];
    Sub24 *f24;
    u8 pad28[0x31FC - 0x28];
    void *f31FC;
    void *f3200;
    u8 pad3204[0x3234 - 0x3204];
    void *f3234;
} Work_021C61EC;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *bg[7];
    u8 pad20[4];
    Sub24 *f24;
    u8 pad28[0x31FC - 0x28];
    void *f31FC;
    void *f3200;
    u8 pad3204[0x3234 - 0x3204];
    void *f3234;
} Work_021C628C;

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
    u8 pad3200[4];
    void *f3204;
    u8 pad3208[0x3294 - 0x3208];
    void *f3294[4];
    void *f32A4;
} Work_021C6954;

typedef struct {
    u8 pad0[0x3034];
    u32 f3034;
} Work_021C631C;

typedef struct {
    u8 pad0[0x32E2];
    s16 scroll;
} Work_021C636C;

typedef struct {
    u8 pad0[0x28];
    u16 h28;
    u8 pad2A[0x33 - 0x2A];
    u8 b33;
    u8 pad34[0x38 - 0x34];
    u32 f38;
    u32 f3C;
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4C;
    u32 f50;
    u32 f54;
    u32 f58;
    u16 h5C;
    u16 h5E;
    u16 h60;
    u16 h62;
    u16 h64;
} Info_021C61EC;

typedef struct {
    u8 pad0[0x28];
    Info_021C61EC *info;
    u8 pad2C[0x31FC - 0x2C];
    void *f31FC;
    u8 pad3200[0x3208 - 0x3200];
    void *f3208;
    u8 pad320C[0x3214 - 0x320C];
    void *f3214;
    u8 pad3218[0x3240 - 0x3218];
    void *win[17];
    u8 pad3284[0x328C - 0x3284];
    void *f328C;
} Work_021C63B8;

typedef struct {
    u8 pad0[0x32FA];
    u8 list[0x13];
    u8 count;
} Work_021C67E8;

typedef struct {
    u8 pad0[0x68];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
} Info_021C67E8;

typedef struct {
    u8 pad0[0x1C];
    void *bg;
    u8 pad20[0x32FA - 0x20];
    u8 list[0x13];
} Work_021C6874;

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
} Work_021C68F0;

typedef struct {
    u8 pad0[0x2C];
    u16 h2C;
    u8 pad2E;
    u8 b2F;
    u8 b30;
    u8 b31;
    u8 b32;
    u8 b33;
    u8 b34;
    u8 b35;
} Info_021C69D4;

typedef struct {
    u8 pad0[0x28];
    Info_021C69D4 *info;
    u8 pad2C[0x31FC - 0x2C];
    void *f31FC;
    u8 pad3200[4];
    void *f3204;
    u8 pad3208[0x329C - 0x3208];
    void *f329C;
    void *f32A0;
} Work_021C69D4;

typedef struct {
    u8 pad0[0x2C];
    u16 h2C;
    u8 pad2E[4];
    u8 b32;
    u8 b33;
    u8 b34;
    u8 b35;
} Info_021C6A84;

typedef struct {
    u16 heap;
    u8 pad2[0x28 - 2];
    Info_021C6A84 *info;
    u8 pad2C[0x31FC - 0x2C];
    void *f31FC;
    u8 pad3200[4];
    void *f3204;
    u8 pad3208[0x32A0 - 0x3208];
    void *f32A0;
} Work_021C6A84;

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
    u8 pad3200[0x320C - 0x3200];
    void *f320C;
} Work_021C6C7C;

typedef struct {
    u8 pad0[0x1C];
    void *f1C;
    u8 pad20[0x2A - 0x20];
    u16 h2A;
    u8 pad2C[2];
    u8 b2E;
} Info_021C6C38;

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
} Work_021C6BD4;

typedef signed char s8;


typedef struct {
    u16 heap;
    u8 pad2[2];
    u32 f4;
    u8 pad8[0xB8 - 8];
    u32 fB8;
    u32 fBC;
    u32 fC0;
    u32 fC4;
    u32 fC8;
    u32 fCC;
} Anim_021C6D9C;

typedef struct {
    u16 x;
    u16 y;
    u8 chr;
    u8 cell;
    u8 anm;
    u8 pri;
    u32 z;
} ObjTemplate;

typedef struct {
    ObjTemplate t[8];
} ObjTemplateTable;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pad6;
    u8 pri;
} ObjPos;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} ResSet;

typedef struct {
    u16 heap;
    u8 pad2[2];
    u32 f4;
    u8 pad8[0x98 - 8];
    void *obj[8];
    ResSet res[2];
} Anim_021C6E8C;

typedef struct {
    u16 heap;
    u8 pad2[2];
    u32 f4;
    u8 pad8[0xB8 - 8];
    ResSet res[2];
} Anim_021C6F4C;

typedef struct {
    u8 pad0[0x98];
    void *anim[1];
} Work_021C6FA0;

typedef long long s64;

typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x13C - 0x120];
    int f13C;
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C6FC4;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x58 - 0x18];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF8 - 0xDC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    void *f108;
    int state;
    u8 pad110[4];
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    u8 pad144[0x14C - 0x144];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
} Work_021C705C;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent_021C7098;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent_021C7098 *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C7098;

typedef struct {
    u8 pad0[4];
    void *f4;
} Parent_021C70EC;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    u8 pad48[0x58 - 0x48];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF4 - 0xDC];
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent_021C70EC *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C70EC;

typedef struct {
    u8 pad0[4];
    void *f4;
} Parent_021C7130;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    u8 pad48[0x58 - 0x48];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF4 - 0xDC];
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent_021C7130 *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent_021C7228;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent_021C7228 *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[2];
    u16 f122;
    u8 pad124[4];
    int f128;
    int f12C;
    int f130;
    u8 pad134[4];
    int f138;
    int f13C;
    int f140;
    int f144;
    int f148;
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C72FC;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent_021C7228 *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x13C - 0x120];
    int f13C;
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C7504;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x58 - 0x18];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF8 - 0xDC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    void *f108;
    int state;
    u8 pad110[4];
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    u8 pad144[0x14C - 0x144];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
} Work_021C74D0;

typedef enum { GX_DISP_SELECT_SUB_MAIN = 0, GX_DISP_SELECT_MAIN_SUB = 1 } GXDispSelect;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent_021C7228 *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x13C - 0x120];
    int f13C;
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C7228;

typedef struct { u32 w[4]; } BankCfg;

typedef struct { u32 w[8]; } BgTemplate;

typedef struct { BgTemplate t[6]; } BgTemplates;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[4][3];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work_021C72C8;

typedef signed int     s32;

extern void BMP_WIN_Init(u16 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02041B6C(u32 bit);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *p, u8 v);
extern void PMS_DRAW_Print(u32 a, u32 b, u32 c, u32 d);
extern void PMS_DRAW_SetVisible(struct PmsDraw *o, int i, u32 a1);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void *GAME_DATA_GetSaveBlock21(void **h);
extern u8 func_020089F4(const struct Sub020089A8Obj *obj);
extern u32 CURSOR_MOVE_GetTableKind(u32 x);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void WORDSET_FormatNumber(void *ctx, int n, u32 kind, u32 mode, u32 flag);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32 a);
extern u32 APP_ICON_GetStatusPaletteFileId(u32 a);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_ReleasePalette(u32 r);
extern void CLACT_ReleaseCharacter(u32 r);
extern void CLACT_ReleaseCellAnim(u32 r);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 heap, u32 size);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MIi_CpuClearFast(int v, void *p, int size);
extern void VIEWER_ACTOR_CreateObjects(Work_021C6FC4 *p);
extern void VIEWER_ACTOR_Init3D(Work_021C6FC4 *p);
extern void VIEWER_ACTOR_CreateModel(Work_021C6FC4 *p);
extern void VIEWER_ACTOR_InitBgWindow(Work_021C6FC4 *p);
extern void VIEWER_ACTOR_CreateFont(Work_021C6FC4 *p);
extern void VIEWER_ACTOR_SetSelection(Work_021C6FC4 *p, u16 v);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int VIEWER_ACTOR_DispatchState(Work_021C705C *p);
extern void VIEWER_ACTOR_DrawModel(Work_021C705C *p);
extern void VIEWER_ACTOR_PrintQueMain(Work_021C705C *p);
extern void CLACT_DrawSystem(void);
extern void VIEWER_ACTOR_DeleteFont(Work_021C7098 *p);
extern void VIEWER_ACTOR_DeleteBgWindow(Work_021C7098 *p);
extern void VIEWER_ACTOR_DeleteModel(Work_021C7098 *p);
extern void VIEWER_ACTOR_Exit3D(Work_021C7098 *p);
extern void VIEWER_ACTOR_DeleteObjects(Work_021C7098 *p);
extern void VIEWER_ACTOR_SetRtcDate(Work_021C7098 *p);
extern void func_020315D4(struct Proc *p);
extern void *func_0203084C(u32 heapId);
extern void GFL_HEAP_DeleteChecked(u32 heap);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_Update(void);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern void *func_020056A0(void (*cb)(void *, Work_021C70EC *), Work_021C70EC *p, int pri);
extern void VIEWER_ACTOR_SetPageCount(Work *p);
extern void VIEWER_ACTOR_GetRtcDate(Work *p);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void func_02030EAC(struct Node *n);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_Create(u16 heapId);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u8 frame, const BgTemplate *t, int mode);
extern void BG_SYS_ClearSlot(u32 i);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(volatile void *reg, int plane1, int plane2, int ev1, int ev2);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BG_SYS_Delete(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *arc, u32 id, u32 frame, u32 a, u32 b, u32 c, u16 heap);
extern void func_02049B68(void *arc, u32 id, u32 a, u32 b, u32 c, u16 heap);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_PushTile(u32 index);
extern void BMP_MENUWORK_LoadPltt(u32 a, u32 b, u32 c, u32 d);
extern void BMP_MENUWORK_LoadChar(u32 a, u32 b, u32 c, u32 d);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
void VIEWER_TEXT_Init(Work_021C6000 *p);
void VIEWER_TEXT_Exit(Work_021C60A0 *p);
void VIEWER_TEXT_Draw(Work_021C60CC *p, void **bg, const Info_021C6000 *info);
void VIEWER_TEXT_DrawTable(Work_021C61EC *p, int k, int flush);
void VIEWER_TEXT_DrawList(Work_021C628C *p, int k, int flush);
void VIEWER_TEXT_FlushWindow(Work_021C631C *p, void **bg);
void VIEWER_TEXT_DrawWindow(Work_021C636C *p, void *bg, void *info);
void VIEWER_TEXT_PrintColorAt(void *a, Work_021C61EC *p, int x, int y, void *s, int idx);
void VIEWER_TEXT_DrawRow(Work_021C63B8 *p, void *a, u32 sel, int y, int idx);
void VIEWER_TEXT_SetScroll(Work_021C67E8 *p, int v);
void VIEWER_TEXT_SetScrollParam(void *p, Info_021C67E8 *info);
void VIEWER_TEXT_DrawPage(Work_021C6874 *p, int scroll, int flush, int idx);
void VIEWER_TEXT_PrintNumber(Work_021C68F0 *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int idx);
void VIEWER_TEXT_PrintDigits(Work_021C6954 *p, void *a, int x, int dx, int y, void *s, u32 n, u8 digits, u32 mode, int k, int idx);
void VIEWER_TEXT_PrintString(Work_021C69D4 *p, void *a, int x, int dx, int y, void *s, u32 mode, int idx);
void VIEWER_TEXT_PrintStringClipped(Work_021C6A84 *p, void *win, int x, int ofs, int y, void *str, u32 mode, int col);
void VIEWER_TEXT_PrintStringPad(Work_021C6B5C *p, void *a, int x, int dx, int y, void *s, u32 n, u32 mode, int idx);
void VIEWER_TEXT_PrintWrapped(Work_021C6BD4 *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int w0, int h0, int idx);
void VIEWER_TEXT_Print(Work_021C6C38 *p, void *a, int x, int dx, int y, void *s);
void VIEWER_TEXT_PrintRow(Work_021C6C7C *p, void *a, int y, const Info_021C6C38 *info, void *s, int idx);
void VIEWER_TEXT_NoOp(void);
void VIEWER_TEXT_InitActors(Anim_021C6D9C *a, u32 x);
void VIEWER_TEXT_CreateActor(Anim_021C6E8C *a);
void VIEWER_TEXT_DeleteActors(Anim_021C6F4C *a);
void VIEWER_TEXT_SetActorAnim(Work_021C6FA0 *p, int idx, u8 a, u8 b);
int VIEWER_TEXT_Create(void *proc, int *seq, void *parent);
int VIEWER_TEXT_Main(void *a, void *b, int c, Work_021C705C *p);
int VIEWER_TEXT_Delete(void *proc, void *seq, int c, Work_021C7098 *p);
void VIEWER_TEXT_VBlank(void *unused, Work_021C70EC *p);
void VIEWER_TEXT_LoadResources(Work *p, Parent_021C7130 *parent);
void VIEWER_TEXT_FreeResources(Work *p);
void VIEWER_TEXT_InitVram(void);
void VIEWER_TEXT_InitBg(Work_021C7228 *p);
void VIEWER_TEXT_ExitBg(Work_021C72C8 *p);
void VIEWER_TEXT_LoadBgResources(Work_021C72FC *p);
void VIEWER_TEXT_FreeBgResources(Work_021C74D0 *p);
void VIEWER_TEXT_InitClact(Work_021C7504 *p);
extern const u8 d_021C8773[8][6];
extern const u8 d_021C876C[];
extern const u16 d_021C8768[];
extern const u8 gClActorInitParam[];
extern const ObjTemplateTable d_021C87A4;
extern const unsigned char d_021C88FC[];
extern const BankCfg d_021C895C;
extern const BgTemplates d_021C89E0;
extern const u32 d_021C885C[];





/*
 * Addresses are Black-image addresses.
 */
void VIEWER_TEXT_Init(Work_021C6000 *p)
{
    const u8 (*tbl)[6] = d_021C8773;
    u8 i;

    BMP_WIN_Init(p->heap);
    for (i = 0; i < 8; i++) {
        p->win[i] = (void *)BMP_WIN_Create(tbl[i][0], tbl[i][1], tbl[i][2], tbl[i][3], tbl[i][4], tbl[i][5], 1);
        BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 0);
    }
    BG_SYS_Init(7, 0, 1, 0);
    BMP_MENUWORK_LoadCharAndPltt(4, 0x31, 0xD, p->f32D4, p->heap);
    func_02049B40(0x17, 5, 4, 0x1C0, 0x20, p->heap);
    func_02041B6C(7);
    func_02041B6C(4);
    p->f32CC = (void *)PRINTSYS_QUE_Create((void *)p->heap);
}





void VIEWER_TEXT_Exit(Work_021C60A0 *p)
{
    u16 i;

    PRINTSYS_QUE_Delete(p->f32CC);
    for (i = 0; i < 8; i++) {
        BMP_WIN_Delete(p->bg[i]);
    }
    BMP_WIN_Exit();
}




/*
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * Addresses are Black-image addresses.
 */
void VIEWER_TEXT_Draw(Work_021C60CC *p, void **bg, const Info_021C6000 *info)
{
    u8 i;
    void *s;

    for (i = 0; i < 5; i++) {
        BMP_Clear(BMP_WIN_GetBmp(bg[i]), 0);
        if (i != 3 || (i == 3 && info->f4_2)) {
            PRINTSYS_Print(BMP_WIN_GetBmp(bg[i]), 0, 0, p->f322C[i], p->f31FC);
        }
    }
    s = p->f3214;
    STRBUF_SetString(p->f3210, info->name);
    VIEWER_TEXT_Print((Work_021C6C38 *)p, bg[0], 0x88, 8, 0, p->f3210);
    if (info->f4_2) {
        VIEWER_TEXT_PrintStringPad((Work_021C6B5C *)p, bg[3], 0x88, 8, 0, s, info->f24, 1, 0);
    }
    VIEWER_TEXT_DrawTable((Work_021C61EC *)p, info->b6, 0);
    VIEWER_TEXT_DrawList((Work_021C628C *)p, info->f48, 0);
    VIEWER_TEXT_PrintDigits((Work_021C6954 *)p, bg[4], 0xD8, 8, 0, s, info->f20, 7, 1, 1, 0);
    PMS_DRAW_SetNullColorPalette(p->f32B0, 0);
    PMS_DRAW_Print((u32)p->f32B0, (u32)bg[5], (u32)p->info->f6C, 0);
    if (p->f3034 != 0) {
        PMS_DRAW_SetVisible(p->f32B0, 0, 0);
    }
}









void VIEWER_TEXT_DrawTable(Work_021C61EC *p, int k, int flush)
{
    void *bank;
    void *str;
    u32 w;

    bank = func_02045B38(0, 2, 0xBF, p->heap);
    if (func_020089F4(GAME_DATA_GetSaveBlock21(p->f24->f4))) {
        str = func_02045EC0(bank, CURSOR_MOVE_GetTableKind(k));
    } else {
        str = func_02045EC0(bank, 0);
    }
    w = func_0201D304(str, (u32)p->f31FC, 0);
    BMP_Clear(BMP_WIN_GetBmp(p->bg[1]), 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(p->bg[1]), 0x80 - w, 0, str, p->f31FC);
    STRBUF_Delete(str);
    MSGDATA_Delete(bank);
    if (flush) {
        BMP_WIN_MakeScreen(p->bg[1]);
        BMP_WIN_TransferChars(p->bg[1]);
        func_02041B6C(7);
    }
}










void VIEWER_TEXT_DrawList(Work_021C628C *p, int k, int flush)
{
    void *str;
    u32 w;

    str = func_02045EC0(p->f3200, k + 0x1F);
    w = func_0201D304(str, (u32)p->f31FC, 0);
    BMP_Clear(BMP_WIN_GetBmp(p->bg[2]), 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(p->bg[2]), 0, 0, p->f3234, p->f31FC);
    PRINTSYS_Print(BMP_WIN_GetBmp(p->bg[2]), 0x80 - w, 0, str, p->f31FC);
    STRBUF_Delete(str);
    if (flush) {
        BMP_WIN_MakeScreen(p->bg[2]);
        BMP_WIN_TransferChars(p->bg[2]);
        func_02041B6C(7);
    }
}










void VIEWER_TEXT_FlushWindow(Work_021C631C *p, void **bg)
{
    int i;

    if (p->f3034 != 0) {
        BMP_WIN_MakeScreen(bg[6]);
        BMP_WIN_TransferChars(bg[6]);
    } else {
        for (i = 0; i <= 5; i++) {
            if (d_021C876C[i] != 0) {
                BMP_WIN_MakeScreen(bg[i]);
                BMP_WIN_TransferChars(bg[i]);
            }
        }
    }
    func_02041B6C(7);
    func_02041B6C(4);
}








void VIEWER_TEXT_DrawWindow(Work_021C636C *p, void *bg, void *info)
{
    VIEWER_TEXT_DrawPage((Work_021C6874 *)p, p->scroll, 0, 0);
}







void VIEWER_TEXT_PrintColorAt(void *a, Work_021C61EC *p, int x, int y, void *s, int idx)
{
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x, y, s, p->f31FC, d_021C8768[idx]);
}






void VIEWER_TEXT_DrawRow(Work_021C63B8 *p, void *a, u32 sel, int y, int idx)
{
    void *s = p->f3214;
    Info_021C61EC *info = p->info;
    u32 w;

    switch (sel) {
    case 0:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[0], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0x60, 0, y, s, info->h28, 5, 2, idx);
        break;
    case 1:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[1], idx);
        VIEWER_TEXT_PrintRow((Work_021C6C7C *)p, a, y, (Info_021C6C38 *)((const Info_021C61EC *)p->info), p->f3208, idx);
        break;
    case 2:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[2], idx);
        break;
    case 3:
        VIEWER_TEXT_PrintString((Work_021C69D4 *)p, a, 0xD8, 0, y, s, 0, idx);
        break;
    case 4:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[3], idx);
        break;
    case 5:
        if (info->b33 != 0) {
            VIEWER_TEXT_PrintStringClipped((Work_021C6A84 *)p, a, 0xD8, 0, y, s, 0, idx);
        } else {
            w = func_0201D304(p->f328C, (u32)p->f31FC, 0);
            VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0xD8 - w, y, p->f328C, idx);
        }
        break;
    case 6:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[4], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f38, 9, 1, idx);
        break;
    case 7:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[5], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f3C, 9, 1, idx);
        break;
    case 8:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[6], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f40, 9, 1, idx);
        break;
    case 9:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[7], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f44, 9, 1, idx);
        break;
    case 10:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[8], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f4C, 9, 1, idx);
        break;
    case 11:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[9], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f50, 9, 1, idx);
        break;
    case 12:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[10], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f54, 9, 1, idx);
        break;
    case 13:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[11], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f58, 5, 1, idx);
        break;
    case 14:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[12], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->h5C, 4, 1, idx);
        break;
    case 15:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[13], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->h5E, 2, 1, idx);
        break;
    case 16:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[14], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->h60, 4, 1, idx);
        break;
    case 17:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[15], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->h62, 3, 1, idx);
        break;
    case 18:
        VIEWER_TEXT_PrintColorAt(a, (Work_021C61EC *)p, 0, y, p->win[16], idx);
        VIEWER_TEXT_PrintNumber((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->h64, 4, 1, idx);
        break;
    }
}






void VIEWER_TEXT_SetScroll(Work_021C67E8 *p, int v)
{
    p->list[p->count] = v;
    p->count++;
}






void VIEWER_TEXT_SetScrollParam(void *p, Info_021C67E8 *info)
{
    int i;

    for (i = 0; i < 13; i++) {
        VIEWER_TEXT_SetScroll(p, i);
    }
    if (info->b0) {
        VIEWER_TEXT_SetScroll(p, 14);
        VIEWER_TEXT_SetScroll(p, 13);
    }
    if (info->b1) {
        VIEWER_TEXT_SetScroll(p, 15);
    }
    if (info->b2) {
        VIEWER_TEXT_SetScroll(p, 16);
    }
    if (info->b3) {
        VIEWER_TEXT_SetScroll(p, 17);
    }
    if (info->b4) {
        VIEWER_TEXT_SetScroll(p, 18);
    }
}






void VIEWER_TEXT_DrawPage(Work_021C6874 *p, int scroll, int flush, int idx)
{
    void *bg = p->bg;
    int i;
    int top = -(scroll / 16);

    BMP_Clear(BMP_WIN_GetBmp(bg), 0);
    for (i = 0; i < 5; i++) {
        VIEWER_TEXT_DrawRow((Work_021C63B8 *)p, bg, p->list[i + top], scroll % 16 + i * 16, idx);
    }
    if (flush) {
        BMP_WIN_TransferChars(bg);
        BMP_WIN_MakeScreen(bg);
        func_02041B6C(BMP_WIN_GetBgLayer(bg));
    }
}






void VIEWER_TEXT_PrintNumber(Work_021C68F0 *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int idx)
{
    u32 w;

    WORDSET_FormatNumber(s, n, kind, mode, 1);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}





void VIEWER_TEXT_PrintDigits(Work_021C6954 *p, void *a, int x, int dx, int y, void *s, u32 n, u8 digits, u32 mode, int k, int idx)
{
    u32 w;

    WORDSET_SetSlotNumber(p->f3204, 0, n, digits, mode, 1);
    WORDSET_CopyTaggedText(p->f3204, (void *)((u32)s), p->f3294[k]);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}





void VIEWER_TEXT_PrintString(Work_021C69D4 *p, void *a, int x, int dx, int y, void *s, u32 mode, int idx)
{
    u32 w;

    WORDSET_SetSlotNumber(p->f3204, 0, p->info->b2F + 2000, 4, mode, 1);
    WORDSET_SetSlotNumber(p->f3204, 1, p->info->b30, 2, mode, 1);
    WORDSET_SetSlotNumber(p->f3204, 2, p->info->b31, 2, mode, 1);
    WORDSET_CopyTaggedText(p->f3204, (void *)((u32)s), p->f329C);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}






void VIEWER_TEXT_PrintStringClipped(Work_021C6A84 *p, void *win, int x, int ofs, int y, void *str, u32 mode, int col)
{
    int w;

    WORDSET_SetSlotNumber(p->f3204, 0, p->info->b32 + 2000, 4, mode, 1);
    WORDSET_SetSlotNumber(p->f3204, 1, p->info->b33, 2, mode, 1);
    WORDSET_SetSlotNumber(p->f3204, 2, p->info->b34, 2, mode, 1);
    WORDSET_SetSlotNumber(p->f3204, 3, p->info->h2C, 2, 2, 1);
    WORDSET_SetSlotNumber(p->f3204, 4, p->info->b35, 2, 2, 1);
    WORDSET_CopyTaggedText(p->f3204, str, p->f32A0);
    w = func_0201D304(str, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(win), x - (w + ofs), y, str, p->f31FC, d_021C8768[col]);
}






void VIEWER_TEXT_PrintStringPad(Work_021C6B5C *p, void *a, int x, int dx, int y, void *s, u32 n, u32 mode, int idx)
{
    u32 w;

    WORDSET_SetSlotNumber(p->f3204, 0, n, 3, mode, 1);
    WORDSET_CopyTaggedText(p->f3204, (void *)((u32)s), p->f32A4);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}






void VIEWER_TEXT_PrintWrapped(Work_021C6BD4 *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int w0, int h0, int idx)
{
    u32 w;

    WORDSET_FormatNumber(s, n, kind, mode, 1);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}






void VIEWER_TEXT_Print(Work_021C6C38 *p, void *a, int x, int dx, int y, void *s)
{
    u32 w;

    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC);
}






void VIEWER_TEXT_PrintRow(Work_021C6C7C *p, void *a, int y, const Info_021C6C38 *info, void *s, int idx)
{
    int v;

    if (info->f1C == 0) {
        VIEWER_TEXT_PrintWrapped((Work_021C6BD4 *)p, a, 0xD8, 0, y, s, info->b2E, 2, 2, 0xD0, 0x10, idx);
        VIEWER_TEXT_PrintWrapped((Work_021C6BD4 *)p, a, 0xD8, 0x13, y, s, info->h2A, 3, 1, 0xAD, 0x1B, idx);
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), 0xC6, y, p->f320C, p->f31FC, d_021C8768[idx]);
    } else {
        v = func_0200864C(info->f1C);
        if (v > 999) {
            v = 999;
        }
        VIEWER_TEXT_PrintWrapped((Work_021C6BD4 *)p, a, 0xD8, 0, y, s, func_02008650(info->f1C), 2, 2, 0xD0, 0x10, idx);
        VIEWER_TEXT_PrintWrapped((Work_021C6BD4 *)p, a, 0xD8, 0x13, y, s, v, 3, 1, 0xAD, 0x1B, idx);
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), 0xC6, y, p->f320C, p->f31FC, d_021C8768[idx]);
    }
}






void VIEWER_TEXT_NoOp(void) { }






void VIEWER_TEXT_InitActors(Anim_021C6D9C *a, u32 x)
{
    void *h;

    h = func_020490F4(0x28, a->heap);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam, x, a->heap);
    a->f4 = (u32)CLACT_CreateUnit(0x23, 0, a->heap);
    a->fB8 = CLACT_RegisterPaletteEx(h, 0xC, 1, 0, 0, 5, a->heap);
    a->fBC = CLACT_RegisterCharacter(h, 0x1D, 0, 1, a->heap);
    a->fC0 = CLACT_RegisterCellAnim(h, 0x2E, 0x30, a->heap);
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(APP_ICON_GetArchiveId(), a->heap);
    a->fC4 = CLACT_RegisterPalette(h, APP_ICON_GetMoveKindPaletteFileId(), 1, 0xA0, a->heap);
    a->fC8 = CLACT_RegisterCharacter(h, APP_ICON_GetMoveKindAnimFileId(), 0, 1, a->heap);
    a->fCC = CLACT_RegisterCellAnim(h, APP_ICON_GetStatusCellFileId(0), APP_ICON_GetStatusPaletteFileId(0), a->heap);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}






void VIEWER_TEXT_CreateActor(Anim_021C6E8C *a)
{
    ObjTemplateTable tbl = d_021C87A4;
    ObjPos pos;
    int i;

    for (i = 0; i < 8; i++) {
        pos.x = tbl.t[i].x;
        pos.y = tbl.t[i].y;
        pos.z = tbl.t[i].z;
        pos.pri = tbl.t[i].pri;
        a->obj[i] = CLACT_CreateActor((void *)a->f4, a->res[tbl.t[i].cell].a, a->res[tbl.t[i].chr].b, a->res[tbl.t[i].anm].c, &pos, 1, a->heap);
        CLACT_SetActorDrawEnable(a->obj[i], 1);
        CLACT_SetActorAutoAnimSpeed(a->obj[i], 0x1000);
        CLACT_SetActorAutoAnim(a->obj[i], 1);
        if (i == 3) {
            CLACT_SetActorDrawEnable(a->obj[i], 0);
        }
    }
    CLACT_SetActorDrawEnable(a->obj[5], 0);
}






void VIEWER_TEXT_DeleteActors(Anim_021C6F4C *a)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        CLACT_ReleasePalette(a->res[i].a);
        CLACT_ReleaseCharacter(a->res[i].b);
        CLACT_ReleaseCellAnim(a->res[i].c);
    }
    CLACT_DeleteUnit((struct Bank *)a->f4);
    CLACT_ExitSystem();
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x300010) | 0x10;
}






void VIEWER_TEXT_SetActorAnim(Work_021C6FA0 *p, int idx, u8 a, u8 b)
{
    CLACT_SetActorAnimSeq(p->anim[idx], a);
    CLACT_RestartActorAnim(p->anim[idx]);
    CLACT_SetActorDrawEnable(p->anim[idx], b);
}






int VIEWER_TEXT_Create(void *proc, int *seq, void *parent)
{
    Work_021C6FC4 *p;

    GFL_HEAP_CreateChildHeap(1, 0x27, 0x20000);
    p = PROCSYS_AllocProcWork(proc, 0x1C8, 0x27);
    MIi_CpuClearFast(0, p, 0x1C8);
    VIEWER_TEXT_LoadResources((Work *)p, (Parent_021C7130 *)parent);
    VIEWER_TEXT_InitVram();
    VIEWER_TEXT_InitBg((Work_021C7228 *)p);
    VIEWER_TEXT_LoadBgResources((Work_021C72FC *)p);
    VIEWER_TEXT_InitClact((Work_021C7504 *)p);
    VIEWER_ACTOR_CreateObjects(p);
    VIEWER_ACTOR_Init3D(p);
    VIEWER_ACTOR_CreateModel(p);
    VIEWER_ACTOR_InitBgWindow(p);
    VIEWER_ACTOR_CreateFont(p);
    VIEWER_ACTOR_SetSelection(p, p->f114);
    GFL_NET_RestartWithDefaultTimeout(1, 0x27);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x27);
    return 1;
}






int VIEWER_TEXT_Main(void *a, void *b, int c, Work_021C705C *p)
{
    if (VIEWER_ACTOR_DispatchState(p) == 0) {
        return 1;
    }
    VIEWER_ACTOR_DrawModel(p);
    VIEWER_ACTOR_PrintQueMain(p);
    CLACT_DrawSystem();
    if (++p->f11C >= 0x100) {
        p->f11C = 0;
    }
    return 0;
}





int VIEWER_TEXT_Delete(void *proc, void *seq, int c, Work_021C7098 *p)
{
    VIEWER_ACTOR_DeleteFont(p);
    VIEWER_ACTOR_DeleteBgWindow(p);
    VIEWER_ACTOR_DeleteModel(p);
    VIEWER_ACTOR_Exit3D(p);
    VIEWER_ACTOR_DeleteObjects(p);
    VIEWER_TEXT_FreeBgResources((Work_021C74D0 *)p);
    VIEWER_TEXT_ExitBg((Work_021C72C8 *)p);
    VIEWER_TEXT_FreeResources((Work *)p);
    VIEWER_ACTOR_SetRtcDate(p);
    func_020315D4(proc);
    func_0203084C(0x27);
    GFL_HEAP_DeleteChecked(0x27);
    return 1;
}





void VIEWER_TEXT_VBlank(void *unused, Work_021C70EC *p)
{
    int v = -(p->f11C / 2);

    BG_SYS_FillScrollArea(6, 0, v);
    BG_SYS_FillScrollArea(6, 3, v);
    BG_SYS_FillScrollArea(3, 0, v);
    BG_SYS_FillScrollArea(3, 3, v);
    CLACT_VBlankSystem();
    BG_SYS_Update();
}





void VIEWER_TEXT_LoadResources(Work *p, Parent_021C7130 *parent)
{
    int i;

    p->f108 = parent;
    p->f110 = 0;
    p->f0 = func_020490F4(0x28, 0x27);
    p->f20 = func_02045B38(0, 2, 0xBB, 0x27);
    for (i = 0; i < 7; i++) {
        p->f2C[i] = func_02045EC0(p->f20, i);
        STRBUF_GetChars(p->f2C[i]);
    }
    p->f28 = STRBUF_Create(0x68, 0x27);
    p->f24 = WORDSET_Create(8, 0x40, 0x27);
    p->fF4 = func_020056A0(VIEWER_TEXT_VBlank, (Work_021C70EC *)p, 0);
    p->f118 = 8;
    p->f144 = -1;
    VIEWER_ACTOR_SetPageCount(p);
    p->f184 = GAME_DATA_GetSaveBlock21(p->f108->f4);
    VIEWER_ACTOR_GetRtcDate(p);
}





void VIEWER_TEXT_FreeResources(Work *p)
{
    int i;

    for (i = 0; i < 7; i++) {
        STRBUF_Delete(p->f2C[i]);
    }
    STRBUF_Delete(p->f28);
    WORDSET_DeleteStrbufED04(p->f24);
    MSGDATA_Delete(p->f20);
    func_02030EAC(p->fF4);
    ARC_TOOL_DeleteHandle(p->f0);
}





static inline void GX_SetDispSelect(GXDispSelect sel)
{
    *(volatile u16 *)0x04000304 = (u16)((*(volatile u16 *)0x04000304 & ~0x8000) | (sel << 15));
}





void VIEWER_TEXT_InitVram(void)
{
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C88FC);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
}





void VIEWER_TEXT_InitBg(Work_021C7228 *p)
{
    BankCfg bank;
    BgTemplates tmpl;
    u32 i;

    BG_SYS_Create(0x27);
    bank = d_021C895C;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&bank));
    tmpl = d_021C89E0;
    for (i = 0; i < 6; i++) {
        u32 v = d_021C885C[i];
        BG_SYS_InitBgLayer(v, &tmpl.t[i], 0);
        BG_SYS_ClearSlot((u8)v);
        BG_SYS_InitRun(v, 0x20, 0, 0x27);
        func_02040588(v, 1);
    }
    func_02040588(7, 0);
    *(volatile u16 *)0x04000050 = 0;
    func_0207D63C((volatile void *)0x04001050, 2, 4, 7, 0x10);
}





void VIEWER_TEXT_ExitBg(Work_021C72C8 *p)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        BG_SYS_FreeLayerBuf((u8)d_021C885C[i]);
    }
    BG_SYS_Delete();
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
}





/*
 * lever:    enum-typed zero in the eighth call preserves copied argument registers and the preceding late heap store.
 *
 * Addresses are Black-image addresses.
 */
void VIEWER_TEXT_LoadBgResources(Work_021C72FC *p)
{
    typedef enum { Zero } ZeroArg;
    ZeroArg z = Zero;
    void *arc = p->f0;
    void *arc2;
    int i;

    func_02049658(arc, 0x19, 6, 0, 0, 0, 0x27);
    func_020498F4(arc, 0x22, 6, 0, 0, 0, 0x27);
    func_02049B68(arc, 1, 4, 0, 0, 0x27);
    func_02049658(arc, 0x1A, 5, 0, 0, 0, 0x27);
    func_020498F4(arc, 0x23, 5, 0, 0, 0, 0x27);
    func_02049658(arc, 0x19, 3, 0, 0, 0, 0x27);
    func_020498F4(arc, 0x22, 3, 0, 0, 0, 0x27);
    func_02049B68(arc, z, z, z, z, 0x27);
    func_02049658(arc, 0x19, 1, 0, 0, 0, 0x27);
    func_020498F4(arc, 0x21, 1, 0, 0, 0, 0x27);
    arc2 = func_020490F4(APP_ICON_GetArchiveId(), 0x27);
    func_02049658(arc2, APP_ICON_GetStatusFrameFileId(), 2, 0, 0, 0, 0x27);
    func_020498F4(arc2, APP_ICON_GetStatusDataFileId(), 2, 0, 0, 0, 0x27);
    ARC_UTIL_UploadPaletteFromHandle(arc2, APP_ICON_GetStatusAnimFileId(), 0, 0, 0x1C0, 0x20, 0x27);
    BG_SYS_FillTileMap(2, 0, 0x15, 0x20, 3, 0xE);
    BG_SYS_PushTile(2);
    ARC_TOOL_DeleteHandle(arc2);
    func_02049B40(0x17, 5, 0, 0x1E0, 0x20, 0x27);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x27);
    BMP_MENUWORK_LoadPltt(4, 0xE, 0, 0x27);
    BMP_MENUWORK_LoadChar(4, 1, 0, 0x27);
    for (i = 0; i < 3; i++) {
        p->f14C[i] = func_02049F78(arc, 4 - i, (u32)(&p->f158[i]), 0x27);
    }
    for (i = 0; i < 3; i++) {
        p->f164[i] = func_02049F78(arc, 0x17 - i, (u32)(&p->f170[i]), 0x27);
    }
}





void VIEWER_TEXT_FreeBgResources(Work_021C74D0 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        func_020307B0(p->f164[i]);
    }
    for (i = 0; i < 3; i++) {
        func_020307B0(p->f14C[i]);
    }
}





void VIEWER_TEXT_InitClact(Work_021C7504 *p)
{
    void *arc = func_020490F4(APP_ICON_GetArchiveId(), 0x27);

    CLACT_InitSystem((const struct Cfg *)gClActorInitParam, (u32)d_021C88FC, 0x27);
    p->f48 = CLACT_CreateUnit(0x24, 1, 0x27);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    p->fE0 = (void *)(s32)CLACT_RegisterCharacter(p->f0, 0x1B, 0, 0, 0x27);
    p->fDC = (void *)(s32)CLACT_RegisterPalette(p->f0, 2, 0, 0, 0x27);
    p->fE4 = (void *)(s32)CLACT_RegisterCellAnim(p->f0, 0x2D, 0x2F, 0x27);
    p->fEC = (void *)(s32)CLACT_RegisterCharacter(arc, APP_ICON_GetMoveKindAnimFileId(), 0, 0, 0x27);
    p->fE8 = (void *)(s32)CLACT_RegisterPaletteEx(arc, APP_ICON_GetMoveKindPaletteFileId(), 0, 0x160, 0, 3, 0x27);
    p->fF0 = (void *)(s32)CLACT_RegisterCellAnim(arc, APP_ICON_GetStatusCellFileId(0), APP_ICON_GetStatusPaletteFileId(0), 0x27);
    ARC_TOOL_DeleteHandle(arc);
}
