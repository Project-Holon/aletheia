/*
 * file:     unit_021C6000.c
 * unit:     yes
 * function: func_021C6000, func_021C60A0, func_021C60CC, func_021C61EC, func_021C628C, func_021C631C, func_021C636C, func_021C6380, func_021C63B8, func_021C67E8, func_021C6804, func_021C6874, func_021C68F0, func_021C6954, func_021C69D4, func_021C6A84, func_021C6B5C, func_021C6BD4, func_021C6C38, func_021C6C7C, func_021C6D98, func_021C6D9C, func_021C6E8C, func_021C6F4C, func_021C6FA0, func_021C6FC4, func_021C705C, func_021C7098, func_021C70EC, func_021C7130, func_021C71CC, func_021C7208, func_021C7228, func_021C72C8, func_021C72FC, func_021C74D0, func_021C7504
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
 *   func_02040C14  0x02040C14  arm
 *   func_0201F5BC  0x0201F5BC  thumb
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
 *   func_02025C9C  0x02025C9C  thumb
 *   d_021C876C     0x021C876C  data  a1
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   d_021C8768     0x021C8768  data  a2
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_0201F35C  0x0201F35C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_020490F4  0x020490F4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
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
 *   func_02082AC0  0x02082AC0  arm
 *   func_021C75E4  0x021C75E4  thumb
 *   func_021C76A4  0x021C76A4  thumb
 *   func_021C7744  0x021C7744  thumb
 *   func_021C78C4  0x021C78C4  thumb
 *   func_021C7934  0x021C7934  thumb
 *   func_021C81A4  0x021C81A4  thumb
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   func_021C79A0  0x021C79A0  thumb
 *   func_021C7830  0x021C7830  thumb
 *   func_021C7970  0x021C7970  thumb
 *   CLACT_DrawSystem  0x0204A600  arm
 *   func_021C795C  0x021C795C  thumb
 *   func_021C78F8  0x021C78F8  thumb
 *   func_021C7808  0x021C7808  thumb
 *   func_021C7730  0x021C7730  thumb
 *   func_021C7658  0x021C7658  thumb
 *   func_021C81C0  0x021C81C0  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_0203084C  0x0203084C  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02040618  0x02040618  arm
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   func_020419E4  0x020419E4  arm
 *   STRBUF_GetChars  0x02045A90  arm
 *   STRBUF_Create  0x020457B0  arm
 *   func_0201EC74  0x0201EC74  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_021C80B4  0x021C80B4  thumb
 *   func_021C8208  0x021C8208  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   d_021C88FC  0x021C88FC  data
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 *   d_021C895C  0x021C895C  data
 *   d_021C89E0  0x021C89E0  data
 *   d_021C885C  0x021C885C  data
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02027624  0x02027624  thumb
 *   func_02027628  0x02027628  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0201F57C  0x0201F57C  thumb
 *   func_0201F554  0x0201F554  thumb
 *   func_02049F78  0x02049F78  arm
 *   func_020307B0  0x020307B0  arm
 */
struct CharBuf;
struct Descriptor;
struct PrintSys;
struct Obj0202DC98;
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
struct Obj0203159C;
struct S020315D4;
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

typedef int s32_021C6D98;

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

typedef signed int     s32_021C6D9C;

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
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
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
extern void PMS_DRAW_SetVisible(struct Obj0202DC98 *o, int i, u32 a1);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void *GAME_DATA_GetSaveBlock21(void **h);
extern u8 func_020089F4(const struct Sub020089A8Obj *obj);
extern u32 func_02025C9C(u32 x);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_0201F35C(void *ctx, int n, u32 kind, u32 mode, u32 flag);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern s32_021C6D9C CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32_021C6D9C CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021C6D9C CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);
extern u32 func_020275E4(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern s32_021C6D9C CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
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
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082AC0(int v, void *p, int size);
extern void func_021C75E4(Work_021C6FC4 *p);
extern void func_021C76A4(Work_021C6FC4 *p);
extern void func_021C7744(Work_021C6FC4 *p);
extern void func_021C78C4(Work_021C6FC4 *p);
extern void func_021C7934(Work_021C6FC4 *p);
extern void func_021C81A4(Work_021C6FC4 *p, u16 v);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int func_021C79A0(Work_021C705C *p);
extern void func_021C7830(Work_021C705C *p);
extern void func_021C7970(Work_021C705C *p);
extern void CLACT_DrawSystem(void);
extern void func_021C795C(Work_021C7098 *p);
extern void func_021C78F8(Work_021C7098 *p);
extern void func_021C7808(Work_021C7098 *p);
extern void func_021C7730(Work_021C7098 *p);
extern void func_021C7658(Work_021C7098 *p);
extern void func_021C81C0(Work_021C7098 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void *func_0203084C(u32 heapId);
extern void func_020306F0(u32 heap);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void CLACT_VBlankSystem(void);
extern void func_020419E4(void);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern void *func_020056A0(void (*cb)(void *, Work_021C70EC *), Work_021C70EC *p, int pri);
extern void func_021C80B4(Work *p);
extern void func_021C8208(Work *p);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02030EAC(struct Node *n);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u8 frame, const BgTemplate *t, int mode);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(volatile void *reg, int plane1, int plane2, int ev1, int ev2);
extern void func_020403F4(u32 i);
extern void func_0203F9B4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *arc, u32 id, u32 frame, u32 a, u32 b, u32 c, u16 heap);
extern void func_02049B68(void *arc, u32 id, u32 a, u32 b, u32 c, u16 heap);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);
extern void func_0201F57C(u32 a, u32 b, u32 c, u32 d);
extern void func_0201F554(u32 a, u32 b, u32 c, u32 d);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
void func_021C6000(Work_021C6000 *p);
void func_021C60A0(Work_021C60A0 *p);
void func_021C60CC(Work_021C60CC *p, void **bg, const Info_021C6000 *info);
void func_021C61EC(Work_021C61EC *p, int k, int flush);
void func_021C628C(Work_021C628C *p, int k, int flush);
void func_021C631C(Work_021C631C *p, void **bg);
void func_021C636C(Work_021C636C *p, void *bg, void *info);
void func_021C6380(void *a, Work_021C61EC *p, int x, int y, void *s, int idx);
void func_021C63B8(Work_021C63B8 *p, void *a, u32 sel, int y, int idx);
void func_021C67E8(Work_021C67E8 *p, int v);
void func_021C6804(void *p, Info_021C67E8 *info);
void func_021C6874(Work_021C6874 *p, int scroll, int flush, int idx);
void func_021C68F0(Work_021C68F0 *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int idx);
void func_021C6954(Work_021C6954 *p, void *a, int x, int dx, int y, void *s, u32 n, u8 digits, u32 mode, int k, int idx);
void func_021C69D4(Work_021C69D4 *p, void *a, int x, int dx, int y, void *s, u32 mode, int idx);
void func_021C6A84(Work_021C6A84 *p, void *win, int x, int ofs, int y, void *str, u32 mode, int col);
void func_021C6B5C(Work_021C6B5C *p, void *a, int x, int dx, int y, void *s, u32 n, u32 mode, int idx);
void func_021C6BD4(Work_021C6BD4 *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int w0, int h0, int idx);
void func_021C6C38(Work_021C6C38 *p, void *a, int x, int dx, int y, void *s);
void func_021C6C7C(Work_021C6C7C *p, void *a, int y, const Info_021C6C38 *info, void *s, int idx);
void func_021C6D98(void);
void func_021C6D9C(Anim_021C6D9C *a, u32 x);
void func_021C6E8C(Anim_021C6E8C *a);
void func_021C6F4C(Anim_021C6F4C *a);
void func_021C6FA0(Work_021C6FA0 *p, int idx, u8 a, u8 b);
int func_021C6FC4(void *proc, int *seq, void *parent);
int func_021C705C(void *a, void *b, int c, Work_021C705C *p);
int func_021C7098(void *proc, void *seq, int c, Work_021C7098 *p);
void func_021C70EC(void *unused, Work_021C70EC *p);
void func_021C7130(Work *p, Parent_021C7130 *parent);
void func_021C71CC(Work *p);
void func_021C7208(void);
void func_021C7228(Work_021C7228 *p);
void func_021C72C8(Work_021C72C8 *p);
void func_021C72FC(Work_021C72FC *p);
void func_021C74D0(Work_021C74D0 *p);
void func_021C7504(Work_021C7504 *p);
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
void func_021C6000(Work_021C6000 *p)
{
    const u8 (*tbl)[6] = d_021C8773;
    u8 i;

    BMP_WIN_Init(p->heap);
    for (i = 0; i < 8; i++) {
        p->win[i] = (void *)BMP_WIN_Create(tbl[i][0], tbl[i][1], tbl[i][2], tbl[i][3], tbl[i][4], tbl[i][5], 1);
        BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 0);
    }
    func_02040C14(7, 0, 1, 0);
    func_0201F5BC(4, 0x31, 0xD, p->f32D4, p->heap);
    func_02049B40(0x17, 5, 4, 0x1C0, 0x20, p->heap);
    func_02041B6C(7);
    func_02041B6C(4);
    p->f32CC = (void *)PRINTSYS_QUE_Create((void *)p->heap);
}





void func_021C60A0(Work_021C60A0 *p)
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
void func_021C60CC(Work_021C60CC *p, void **bg, const Info_021C6000 *info)
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
    func_021C6C38((Work_021C6C38 *)p, bg[0], 0x88, 8, 0, p->f3210);
    if (info->f4_2) {
        func_021C6B5C((Work_021C6B5C *)p, bg[3], 0x88, 8, 0, s, info->f24, 1, 0);
    }
    func_021C61EC((Work_021C61EC *)p, info->b6, 0);
    func_021C628C((Work_021C628C *)p, info->f48, 0);
    func_021C6954((Work_021C6954 *)p, bg[4], 0xD8, 8, 0, s, info->f20, 7, 1, 1, 0);
    PMS_DRAW_SetNullColorPalette(p->f32B0, 0);
    PMS_DRAW_Print((u32)p->f32B0, (u32)bg[5], (u32)p->info->f6C, 0);
    if (p->f3034 != 0) {
        PMS_DRAW_SetVisible(p->f32B0, 0, 0);
    }
}









void func_021C61EC(Work_021C61EC *p, int k, int flush)
{
    void *bank;
    void *str;
    u32 w;

    bank = func_02045B38(0, 2, 0xBF, p->heap);
    if (func_020089F4(GAME_DATA_GetSaveBlock21(p->f24->f4))) {
        str = func_02045EC0(bank, func_02025C9C(k));
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










void func_021C628C(Work_021C628C *p, int k, int flush)
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










void func_021C631C(Work_021C631C *p, void **bg)
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








void func_021C636C(Work_021C636C *p, void *bg, void *info)
{
    func_021C6874((Work_021C6874 *)p, p->scroll, 0, 0);
}







void func_021C6380(void *a, Work_021C61EC *p, int x, int y, void *s, int idx)
{
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x, y, s, p->f31FC, d_021C8768[idx]);
}






void func_021C63B8(Work_021C63B8 *p, void *a, u32 sel, int y, int idx)
{
    void *s = p->f3214;
    Info_021C61EC *info = p->info;
    u32 w;

    switch (sel) {
    case 0:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[0], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0x60, 0, y, s, info->h28, 5, 2, idx);
        break;
    case 1:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[1], idx);
        func_021C6C7C((Work_021C6C7C *)p, a, y, (Info_021C6C38 *)((const Info_021C61EC *)p->info), p->f3208, idx);
        break;
    case 2:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[2], idx);
        break;
    case 3:
        func_021C69D4((Work_021C69D4 *)p, a, 0xD8, 0, y, s, 0, idx);
        break;
    case 4:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[3], idx);
        break;
    case 5:
        if (info->b33 != 0) {
            func_021C6A84((Work_021C6A84 *)p, a, 0xD8, 0, y, s, 0, idx);
        } else {
            w = func_0201D304(p->f328C, (u32)p->f31FC, 0);
            func_021C6380(a, (Work_021C61EC *)p, 0xD8 - w, y, p->f328C, idx);
        }
        break;
    case 6:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[4], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f38, 9, 1, idx);
        break;
    case 7:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[5], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f3C, 9, 1, idx);
        break;
    case 8:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[6], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f40, 9, 1, idx);
        break;
    case 9:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[7], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f44, 9, 1, idx);
        break;
    case 10:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[8], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f4C, 9, 1, idx);
        break;
    case 11:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[9], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f50, 9, 1, idx);
        break;
    case 12:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[10], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f54, 9, 1, idx);
        break;
    case 13:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[11], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->f58, 5, 1, idx);
        break;
    case 14:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[12], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->h5C, 4, 1, idx);
        break;
    case 15:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[13], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->h5E, 2, 1, idx);
        break;
    case 16:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[14], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->h60, 4, 1, idx);
        break;
    case 17:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[15], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->h62, 3, 1, idx);
        break;
    case 18:
        func_021C6380(a, (Work_021C61EC *)p, 0, y, p->win[16], idx);
        func_021C68F0((Work_021C68F0 *)p, a, 0xD8, 8, y, s, info->h64, 4, 1, idx);
        break;
    }
}






void func_021C67E8(Work_021C67E8 *p, int v)
{
    p->list[p->count] = v;
    p->count++;
}






void func_021C6804(void *p, Info_021C67E8 *info)
{
    int i;

    for (i = 0; i < 13; i++) {
        func_021C67E8(p, i);
    }
    if (info->b0) {
        func_021C67E8(p, 14);
        func_021C67E8(p, 13);
    }
    if (info->b1) {
        func_021C67E8(p, 15);
    }
    if (info->b2) {
        func_021C67E8(p, 16);
    }
    if (info->b3) {
        func_021C67E8(p, 17);
    }
    if (info->b4) {
        func_021C67E8(p, 18);
    }
}






void func_021C6874(Work_021C6874 *p, int scroll, int flush, int idx)
{
    void *bg = p->bg;
    int i;
    int top = -(scroll / 16);

    BMP_Clear(BMP_WIN_GetBmp(bg), 0);
    for (i = 0; i < 5; i++) {
        func_021C63B8((Work_021C63B8 *)p, bg, p->list[i + top], scroll % 16 + i * 16, idx);
    }
    if (flush) {
        BMP_WIN_TransferChars(bg);
        BMP_WIN_MakeScreen(bg);
        func_02041B6C(BMP_WIN_GetBgLayer(bg));
    }
}






void func_021C68F0(Work_021C68F0 *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int idx)
{
    u32 w;

    func_0201F35C(s, n, kind, mode, 1);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}





void func_021C6954(Work_021C6954 *p, void *a, int x, int dx, int y, void *s, u32 n, u8 digits, u32 mode, int k, int idx)
{
    u32 w;

    func_0201EFA4(p->f3204, 0, n, digits, mode, 1);
    func_0201F250(p->f3204, (void *)((u32)s), p->f3294[k]);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}





void func_021C69D4(Work_021C69D4 *p, void *a, int x, int dx, int y, void *s, u32 mode, int idx)
{
    u32 w;

    func_0201EFA4(p->f3204, 0, p->info->b2F + 2000, 4, mode, 1);
    func_0201EFA4(p->f3204, 1, p->info->b30, 2, mode, 1);
    func_0201EFA4(p->f3204, 2, p->info->b31, 2, mode, 1);
    func_0201F250(p->f3204, (void *)((u32)s), p->f329C);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}






void func_021C6A84(Work_021C6A84 *p, void *win, int x, int ofs, int y, void *str, u32 mode, int col)
{
    int w;

    func_0201EFA4(p->f3204, 0, p->info->b32 + 2000, 4, mode, 1);
    func_0201EFA4(p->f3204, 1, p->info->b33, 2, mode, 1);
    func_0201EFA4(p->f3204, 2, p->info->b34, 2, mode, 1);
    func_0201EFA4(p->f3204, 3, p->info->h2C, 2, 2, 1);
    func_0201EFA4(p->f3204, 4, p->info->b35, 2, 2, 1);
    func_0201F250(p->f3204, str, p->f32A0);
    w = func_0201D304(str, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(win), x - (w + ofs), y, str, p->f31FC, d_021C8768[col]);
}






void func_021C6B5C(Work_021C6B5C *p, void *a, int x, int dx, int y, void *s, u32 n, u32 mode, int idx)
{
    u32 w;

    func_0201EFA4(p->f3204, 0, n, 3, mode, 1);
    func_0201F250(p->f3204, (void *)((u32)s), p->f32A4);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}






void func_021C6BD4(Work_021C6BD4 *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int w0, int h0, int idx)
{
    u32 w;

    func_0201F35C(s, n, kind, mode, 1);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}






void func_021C6C38(Work_021C6C38 *p, void *a, int x, int dx, int y, void *s)
{
    u32 w;

    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC);
}






void func_021C6C7C(Work_021C6C7C *p, void *a, int y, const Info_021C6C38 *info, void *s, int idx)
{
    int v;

    if (info->f1C == 0) {
        func_021C6BD4((Work_021C6BD4 *)p, a, 0xD8, 0, y, s, info->b2E, 2, 2, 0xD0, 0x10, idx);
        func_021C6BD4((Work_021C6BD4 *)p, a, 0xD8, 0x13, y, s, info->h2A, 3, 1, 0xAD, 0x1B, idx);
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), 0xC6, y, p->f320C, p->f31FC, d_021C8768[idx]);
    } else {
        v = func_0200864C(info->f1C);
        if (v > 999) {
            v = 999;
        }
        func_021C6BD4((Work_021C6BD4 *)p, a, 0xD8, 0, y, s, func_02008650(info->f1C), 2, 2, 0xD0, 0x10, idx);
        func_021C6BD4((Work_021C6BD4 *)p, a, 0xD8, 0x13, y, s, v, 3, 1, 0xAD, 0x1B, idx);
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), 0xC6, y, p->f320C, p->f31FC, d_021C8768[idx]);
    }
}






void func_021C6D98(void) { }






void func_021C6D9C(Anim_021C6D9C *a, u32 x)
{
    void *h;

    h = func_020490F4(0x28, a->heap);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam, x, a->heap);
    a->f4 = (u32)CLACT_CreateUnit(0x23, 0, a->heap);
    a->fB8 = CLACT_RegisterPaletteEx(h, 0xC, 1, 0, 0, 5, a->heap);
    a->fBC = CLACT_RegisterCharacter(h, 0x1D, 0, 1, a->heap);
    a->fC0 = CLACT_RegisterCellAnim(h, 0x2E, 0x30, a->heap);
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(func_020275E4(), a->heap);
    a->fC4 = CLACT_RegisterPalette(h, func_02027614(), 1, 0xA0, a->heap);
    a->fC8 = CLACT_RegisterCharacter(h, func_02027618(), 0, 1, a->heap);
    a->fCC = CLACT_RegisterCellAnim(h, func_0202761C(0), func_02027620(0), a->heap);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}






void func_021C6E8C(Anim_021C6E8C *a)
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






void func_021C6F4C(Anim_021C6F4C *a)
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






void func_021C6FA0(Work_021C6FA0 *p, int idx, u8 a, u8 b)
{
    CLACT_SetActorAnimSeq(p->anim[idx], a);
    CLACT_RestartActorAnim(p->anim[idx]);
    CLACT_SetActorDrawEnable(p->anim[idx], b);
}






int func_021C6FC4(void *proc, int *seq, void *parent)
{
    Work_021C6FC4 *p;

    GFL_HEAP_CreateChildHeap(1, 0x27, 0x20000);
    p = PROCSYS_AllocProcWork(proc, 0x1C8, 0x27);
    func_02082AC0(0, p, 0x1C8);
    func_021C7130((Work *)p, (Parent_021C7130 *)parent);
    func_021C7208();
    func_021C7228((Work_021C7228 *)p);
    func_021C72FC((Work_021C72FC *)p);
    func_021C7504((Work_021C7504 *)p);
    func_021C75E4(p);
    func_021C76A4(p);
    func_021C7744(p);
    func_021C78C4(p);
    func_021C7934(p);
    func_021C81A4(p, p->f114);
    GFL_NET_RestartWithDefaultTimeout(1, 0x27);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x27);
    return 1;
}






int func_021C705C(void *a, void *b, int c, Work_021C705C *p)
{
    if (func_021C79A0(p) == 0) {
        return 1;
    }
    func_021C7830(p);
    func_021C7970(p);
    CLACT_DrawSystem();
    if (++p->f11C >= 0x100) {
        p->f11C = 0;
    }
    return 0;
}





int func_021C7098(void *proc, void *seq, int c, Work_021C7098 *p)
{
    func_021C795C(p);
    func_021C78F8(p);
    func_021C7808(p);
    func_021C7730(p);
    func_021C7658(p);
    func_021C74D0((Work_021C74D0 *)p);
    func_021C72C8((Work_021C72C8 *)p);
    func_021C71CC((Work *)p);
    func_021C81C0(p);
    func_020315D4(proc);
    func_0203084C(0x27);
    func_020306F0(0x27);
    return 1;
}





void func_021C70EC(void *unused, Work_021C70EC *p)
{
    int v = -(p->f11C / 2);

    func_02040618(6, 0, v);
    func_02040618(6, 3, v);
    func_02040618(3, 0, v);
    func_02040618(3, 3, v);
    CLACT_VBlankSystem();
    func_020419E4();
}





void func_021C7130(Work *p, Parent_021C7130 *parent)
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
    p->f24 = func_0201EC74(8, 0x40, 0x27);
    p->fF4 = func_020056A0(func_021C70EC, (Work_021C70EC *)p, 0);
    p->f118 = 8;
    p->f144 = -1;
    func_021C80B4(p);
    p->f184 = GAME_DATA_GetSaveBlock21(p->f108->f4);
    func_021C8208(p);
}





void func_021C71CC(Work *p)
{
    int i;

    for (i = 0; i < 7; i++) {
        STRBUF_Delete(p->f2C[i]);
    }
    STRBUF_Delete(p->f28);
    func_0201ED04(p->f24);
    MSGDATA_Delete(p->f20);
    func_02030EAC(p->fF4);
    ARC_TOOL_DeleteHandle(p->f0);
}





static inline void GX_SetDispSelect(GXDispSelect sel)
{
    *(volatile u16 *)0x04000304 = (u16)((*(volatile u16 *)0x04000304 & ~0x8000) | (sel << 15));
}





void func_021C7208(void)
{
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C88FC);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
}





void func_021C7228(Work_021C7228 *p)
{
    BankCfg bank;
    BgTemplates tmpl;
    u32 i;

    func_0203F8F4(0x27);
    bank = d_021C895C;
    func_0203FC28((struct DispConfig *)(&bank));
    tmpl = d_021C89E0;
    for (i = 0; i < 6; i++) {
        u32 v = d_021C885C[i];
        func_0203FCA0(v, &tmpl.t[i], 0);
        func_020414EC((u8)v);
        func_02040B94(v, 0x20, 0, 0x27);
        func_02040588(v, 1);
    }
    func_02040588(7, 0);
    *(volatile u16 *)0x04000050 = 0;
    func_0207D63C((volatile void *)0x04001050, 2, 4, 7, 0x10);
}





void func_021C72C8(Work_021C72C8 *p)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        func_020403F4((u8)d_021C885C[i]);
    }
    func_0203F9B4();
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
}





/*
 * lever:    enum-typed zero in the eighth call preserves copied argument registers and the preceding late heap store.
 *
 * Addresses are Black-image addresses.
 */
void func_021C72FC(Work_021C72FC *p)
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
    arc2 = func_020490F4(func_020275E4(), 0x27);
    func_02049658(arc2, func_02027628(), 2, 0, 0, 0, 0x27);
    func_020498F4(arc2, func_0202762C(), 2, 0, 0, 0, 0x27);
    ARC_UTIL_UploadPaletteFromHandle(arc2, func_02027624(), 0, 0, 0x1C0, 0x20, 0x27);
    func_020413B0(2, 0, 0x15, 0x20, 3, 0xE);
    func_020409B4(2);
    ARC_TOOL_DeleteHandle(arc2);
    func_02049B40(0x17, 5, 0, 0x1E0, 0x20, 0x27);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x27);
    func_0201F57C(4, 0xE, 0, 0x27);
    func_0201F554(4, 1, 0, 0x27);
    for (i = 0; i < 3; i++) {
        p->f14C[i] = func_02049F78(arc, 4 - i, (u32)(&p->f158[i]), 0x27);
    }
    for (i = 0; i < 3; i++) {
        p->f164[i] = func_02049F78(arc, 0x17 - i, (u32)(&p->f170[i]), 0x27);
    }
}





void func_021C74D0(Work_021C74D0 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        func_020307B0(p->f164[i]);
    }
    for (i = 0; i < 3; i++) {
        func_020307B0(p->f14C[i]);
    }
}





void func_021C7504(Work_021C7504 *p)
{
    void *arc = func_020490F4(func_020275E4(), 0x27);

    CLACT_InitSystem((const struct Cfg *)gClActorInitParam, (u32)d_021C88FC, 0x27);
    p->f48 = CLACT_CreateUnit(0x24, 1, 0x27);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    p->fE0 = (void *)(s32)CLACT_RegisterCharacter(p->f0, 0x1B, 0, 0, 0x27);
    p->fDC = (void *)(s32)CLACT_RegisterPalette(p->f0, 2, 0, 0, 0x27);
    p->fE4 = (void *)(s32)CLACT_RegisterCellAnim(p->f0, 0x2D, 0x2F, 0x27);
    p->fEC = (void *)(s32)CLACT_RegisterCharacter(arc, func_02027618(), 0, 0, 0x27);
    p->fE8 = (void *)(s32)CLACT_RegisterPaletteEx(arc, func_02027614(), 0, 0x160, 0, 3, 0x27);
    p->fF0 = (void *)(s32)CLACT_RegisterCellAnim(arc, func_0202761C(0), func_02027620(0), 0x27);
    ARC_TOOL_DeleteHandle(arc);
}
