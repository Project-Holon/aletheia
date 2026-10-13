/*
 * file:     unit_021C3CC0.c
 * unit:     yes
 * function: func_021C3CC0, func_021C3EF8, func_021C3F18, func_021C3F54, func_021C40DC, func_021C41C4, func_021C42C0, func_021C436C, func_021C43C4, func_021C43E8, func_021C4524, func_021C4530, func_021C453C, func_021C46F0, func_021C4754, func_021C479C, func_021C47EC, func_021C4858, func_021C49D8, func_021C4AB0, func_021C4B74, func_021C4B9C, func_021C4D48, func_021C4E0C, func_021C4F80, func_021C5008, func_021C5054, func_021C513C, func_021C51B4, func_021C51E4, func_021C523C, func_021C5264, func_021C5280, func_021C5484, func_021C555C, func_021C55A4, func_021C567C, func_021C56E8, func_021C5718, func_021C581C, func_021C5874, func_021C58E0, func_021C5938, func_021C5958, func_021C59B0, func_021C59DC, func_021C5ACC, func_021C5AEC, func_021C5B34, func_021C5B80, func_021C5BCC, func_021C5CF4, func_021C5DB8, func_021C5F50, func_021C5F64
 * address:  0x021C3CC0
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
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   func_0202223C  0x0202223C  thumb
 *   WIPE_ResetWndMask  0x02022224  thumb
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020355C4  0x020355C4  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_020433E0  0x020433E0  arm
 *   PMS_DRAW_Create  0x0202DB0C  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_021C6D9C  0x021C6D9C  thumb  ov111
 *   func_021C6804  0x021C6804  thumb  ov111
 *   func_021C6E8C  0x021C6E8C  thumb  ov111
 *   func_021C6000  0x021C6000  thumb  ov111
 *   func_021C6D98  0x021C6D98  thumb  ov111
 *   d_021C8564     0x021C8564  data  a4
 *   func_020061E4  0x020061E4  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204A600  0x0204A600  arm
 *   PMS_DRAW_Main  0x0202DBC4  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020310C4  0x020310C4  arm
 *   GAME_DATA_GetSaveBlock21  0x02012F5C  thumb
 *   func_020089CC  0x020089CC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008558  0x02008558  thumb
 *   func_02008A14  0x02008A14  thumb
 *   func_02008A1C  0x02008A1C  thumb
 *   PMS_DRAW_Delete  0x0202DC08  thumb
 *   func_021C6F4C  0x021C6F4C  thumb  ov111
 *   func_020307B0  0x020307B0  arm
 *   func_021C60A0  0x021C60A0  thumb  ov111
 *   func_02030EAC  0x02030EAC  arm
 *   func_02031140  0x02031140  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_02049F34  0x02049F34  arm
 *   d_021C8E20     0x021C8E20  data  a4
 *   d_021C86E8     0x021C86E8  data  a4
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02040588  0x02040588  arm
 *   d_021C85C8     0x021C85C8  data  a4
 *   d_021C85E8     0x021C85E8  data  a4
 *   d_021C8608     0x021C8608  data  a4
 *   d_021C8628     0x021C8628  data  a4
 *   d_021C8648     0x021C8648  data  a4
 *   d_021C8668     0x021C8668  data  a4
 *   func_02049DB4  0x02049DB4  arm
 *   ARC_UTIL_LoadPaletteDataFromArchive  0x02049EB4  arm
 *   func_02049624  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02027628  0x02027628  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02040618  0x02040618  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   d_021C85D8     0x021C85D8  data  a4
 *   func_020414EC  0x020414EC  arm
 *   func_021C60CC  0x021C60CC  thumb  ov111
 *   func_021C6874  0x021C6874  thumb  ov111
 *   func_021C636C  0x021C636C  thumb  ov111
 *   func_021C631C  0x021C631C  thumb  ov111
 *   func_021C6FA0  0x021C6FA0  thumb  ov111
 *   GAME_DATA_CheckSaveFlag  0x02012BF8  thumb
 *   PMS_DRAW_SetDecoVisible  0x0202DCD4  thumb
 *   PMS_DRAW_SetVisible  0x0202DCB0  thumb
 *   _ll_mul          0x0209C054  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *   func_0207D658  0x0207D658  arm
 *   FX_Inv  0x0207C778  arm
 *   func_0207D59C  0x0207D59C  arm
 *   func_02035C38  0x02035C38  arm
 *   func_0203630C  0x0203630C  arm
 *   func_020362DC  0x020362DC  arm
 *   GAME_DATA_SetSaveFlag  0x02012BE0  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   d_021C8544     0x021C8544  data  a1
 *   func_02035C08  0x02035C08  arm
 *   func_02035C60  0x02035C60  arm
 *   func_02035D20  0x02035D20  arm
 *   d_021C8554     0x021C8554  data  a1
 *   d_021C8594     0x021C8594  data  a1
 *   sub_02008A00  0x02008A00  thumb
 *   func_021C61EC  0x021C61EC  thumb
 *   func_021C628C  0x021C628C  thumb
 *   func_020419E4  0x020419E4  arm
 *   func_0204A648  0x0204A648  arm
 *   func_02087AE4  0x02087AE4  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_020410D0  0x020410D0  arm
 *   func_02041300  0x02041300  arm
 *   func_0204162C  0x0204162C  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0207E468  0x0207E468  arm
 *   d_021C8534     0x021C8534  data  a1
 *   d_021C854C     0x021C854C  data  a1
 *   TOUCHPANEL_HitPoint  0x02035D40  arm
 *   d_021C852C     0x021C852C  data  a1
 *   d_021C853C     0x021C853C  data  a1
 *   d_021C86A8     0x021C86A8  data  a1
 */
#define REG_DB_DISPCNT  (*(volatile u32 *)0x04001000)
#define REG_DB_WIN0H    (*(volatile u16 *)0x04001040)
#define REG_DB_WIN0V    (*(volatile u16 *)0x04001044)
#define REG_DB_WININ    (*(volatile u16 *)0x04001048)
#define REG_DB_WINOUT   (*(volatile u16 *)0x0400104A)
#define REG_DB_BLDCNT   (*(volatile u16 *)0x04001050)
struct PmsDraw;
struct Obj0203159C;
struct Tcbl;
struct DispVram;
struct Actor;
struct PrintSys;
struct Node;
struct Obj;
struct S020315D4;
struct Sub0200852CObj;
struct Sub020089A8Obj;
struct S02031140;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec;
struct Obj0202DC98;
struct Obj0202DCC4;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 pad5[3];
    u16 h8;
    u8 padA[0x33 - 0xA];
    u8 b33;
} Info_021C3CC0;

typedef struct {
    Info_021C3CC0 *info;
    u8 pad4[0xC - 4];
    u32 fC;
    u8 pad10[4];
    u32 f14;
} Args_v3CC0;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *f4;
} Anim_021C3CC0;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *bg[8];
    Args_v3CC0 *args;
    Info_021C3CC0 *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x304C - 0x3038];
    u32 f304C;
    u32 f3050;
    u32 f3054;
    u32 f3058;
    u8 pad305C[0x3060 - 0x305C];
    u32 f3060;
    u8 pad3064[0x3070 - 0x3064];
    Anim_021C3CC0 anim;
    u8 pad3078[0x31C4 - 0x3078];
    u32 f31C4;
    u8 pad31C8[0x31F4 - 0x31C8];
    void *f31F4;
    void *f31F8;
    void *f31FC;
    u8 pad3200[0x320C - 0x3200];
    void *f320C;
    u8 pad3210[0x32B0 - 0x3210];
    void *f32B0;
    u8 flags[16];
    u8 b32C4;
    u8 pad32C5[3];
    u8 b32C8;
    u8 pad32C9;
    u8 f32CA_0 : 1;
    u8 f32CA_1 : 1;
    u8 pad32CB;
    void *f32CC;
    u8 pad32D0[4];
    u8 b32D4;
    u8 b32D5;
    u8 pad32D6[0x3310 - 0x32D6];
} Work_021C3CC0;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 pad5;
    u8 b6;
} Info_021C3EF8;

typedef struct {
    u8 pad0[0x32F6];
    u8 b32F6;
    u8 pad32F7[2];
    u8 cooldown;
} Work_021C3F18;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
} Cfg;

typedef struct {
    Cfg *cfg;
    void *f4;
    u8 pad8[4];
    u32 fC;
    u32 f10;
} Args_021C3F54;

typedef struct {
    u8 x;
    u8 y;
    u8 size;
    u8 active;
} TouchPos;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args_021C3F54 *args;
    void *info;
    u8 pix[0x305C - 0x2C];
    u16 f305C;
    u16 f305E;
    u8 pad3060[0x3108 - 0x3060];
    void *f3108;
    void *f310C;
    void *f3110;
    u8 pad3114[0x31F8 - 0x3114];
    void *f31F8;
    u8 pad31FC[0x32B0 - 0x31FC];
    void *f32B0;
    u8 pad32B4[0x32CC - 0x32B4];
    void *f32CC;
    u8 pad32D0[0x32D6 - 0x32D0];
    u8 b32D6;
    u8 pad32D7[0x32EE - 0x32D7];
    TouchPos cur;
    TouchPos prev;
} Work_021C3F54;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 pad5;
    u8 b6;
    u8 pad7[0x48 - 7];
    u32 f48;
    u8 pad4C[0x74 - 0x4C];
    u8 bitmap[0x600];
} Info_v3CC0;

typedef struct {
    void *f0;
    void *f4;
    u32 f8;
} Args_021C40DC;

typedef struct {
    u16 heap;
} Anim_021C3F54;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args_021C40DC *args;
    Info_v3CC0 *info;
    u8 pix[0x302C - 0x2C];
    void *f302C;
    u8 pad3030[0x3060 - 0x3030];
    u32 f3060;
    u8 pad3064[0x3070 - 0x3064];
    Anim_021C3F54 anim;
    u8 pad3072[0x31D8 - 0x3072];
    void *f31D8;
    u8 pad31DC[0x31E8 - 0x31DC];
    void *f31E8;
    u8 pad31EC[0x31F4 - 0x31EC];
    void *f31F4;
    u32 f31F8;
    u8 pad31FC[0x32B0 - 0x31FC];
    void *f32B0;
} Work_021C40DC;

typedef struct {
    u16 heap;
    u8 pad2[0x31FC - 2];
    void *f31FC;
    void *f3200;
    void *f3204;
    void *f3208;
    void *f320C;
    void *f3210;
    void *f3214;
    void *f3218[3];
    void *f3224[2];
    void *f322C[26];
    void *f3294[5];
} Work_021C41C4;

typedef struct {
    u8 kind;
    u8 pad1[2];
    u8 b3;
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
    u8 f4_7 : 1;
    u8 pad5;
    u8 b6;
    u8 pad7[0x74 - 7];
    u8 bitmap[1];
} Info_021C43E8;

typedef struct {
    u16 heap;
    u8 pad2[0x28 - 2];
    Info_021C43E8 *info;
    u8 pix[0x302C - 0x2C];
    void *f302C;
    void *f3030;
    u8 pad3034[0x31D8 - 0x3034];
    void *f31D8;
    void *f31DC;
} Work_v3CC0;

typedef struct {
    u8 pad0[0x3060];
    int mode;
} Work_021C56E8;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
} Info_021C5AEC;

typedef struct {
    u8 pad0[0x28];
    Info_021C5AEC *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x32C7 - 0x3038];
    u8 blink;
    u8 phase;
} Work_021C5AEC;

typedef struct {
    u16 heap;
    u8 pad2[0x31FC - 2];
    void *f31FC;
    void *f3200;
    void *f3204;
    void *f3208;
    void *f320C;
    void *f3210;
    void *f3214;
    void *f3218[3];
    void *f3224[2];
    void *f322C[26];
    void *f3294[5];
} Work_021C42C0;

typedef struct {
    u8 kind;
} Info_021C42C0;

typedef struct {
    u16 heap;
    u8 pad2[0x28 - 2];
    Info_021C42C0 *info;
    u8 pad2C[0x31E8 - 0x2C];
    void *f31E8;
    void *f31EC;
} Work_021C436C;

typedef struct {
    u16 heap;
} Work_021C43C4;

struct DispConfig {
    u32 w[4];
};

struct BgTemplate {
    u32 w[8];
};

struct BgTemplatePair {
    struct BgTemplate t[2];
};

typedef struct {
    u8 pad0[0x10];
    u32 size;
    void *data;
} CharData_v3CC0;

typedef struct {
    u16 w;
    u16 h;
} ScrnData_v3CC0;

typedef struct {
    u8 pad0[0x3030];
    CharData_v3CC0 *chr;
    u8 pad3034[0x31DC - 0x3034];
    ScrnData_v3CC0 *scrn;
} Work_021C58E0_021C3CC0;

typedef struct {
    u8 pad0[4];
    u8 lo : 4;
    u8 alt : 1;
} Info_021C4754;

typedef struct {
    u16 heap;
    u8 pad2[0x28 - 2];
    Info_021C4754 *info;
} Work_021C4754;

typedef struct {
    u32 file[2][2];
} FileTable;

typedef struct {
    u8 kind;
} Info_021C479C;

typedef struct {
    u16 heap;
    u8 pad2[0x28 - 2];
    Info_021C479C *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
} Work_021C479C;

typedef short s16;

typedef struct Info_v4754 Info_v4754;

typedef struct {
    u8 pad0[4];
    void *bg[7];
    u8 pad20[8];
    Info_v4754 *info;
    u8 pix[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x32B0 - 0x3038];
    void *f32B0;
    u8 pad32B4[0x32C8 - 0x32B4];
    u8 phase;
    u8 pad32C9[0x32E2 - 0x32C9];
    s16 scroll;
} Work_v4754;

typedef struct {
    u8 pad0[0x10];
    u32 size;
    void *data;
} CharData_v4754;

typedef struct {
    u16 w;
    u16 h;
} ScrnData_v4754;

typedef struct {
    u8 pad0[0x3030];
    CharData_v4754 *chr;
    u8 pad3034[0x31DC - 0x3034];
    ScrnData_v4754 *scrn;
} Work_021C58E0_021C4754;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
    u8 f4_7 : 1;
} Info_v4858;

typedef struct {
    u8 pad0[4];
    void *f4;
    u32 f8;
} Sub24_v4858;

typedef struct {
    u8 pad0[0x98];
} Anim_v4858;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Sub24_v4858 *f24;
    Info_v4858 *info;
    u8 pad2C[0x305E - 0x2C];
    u16 h305E;
    u8 pad3060[0x3070 - 0x3060];
    Anim_v4858 anim;
    u8 pad3108[0x32F6 - 0x3108];
    u8 b32F6;
} Work_021C4858;

typedef int fx32;

typedef long long fx64;

typedef struct {
    u8 pad0[4];
    void *bg[8];
    u8 pad24[8];
    u8 pix[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x303C - 0x3038];
    fx32 scaleX;
    fx32 scaleY;
    u8 pad3044[4];
    int angle;
    u8 pad304C[0x32B0 - 0x304C];
    void *f32B0;
    u8 pad32B4[0x32C6 - 0x32B4];
    u8 state;
    u8 blink;
    u8 phase;
    u8 pad32C9;
    u8 f0 : 1;
    u8 f1 : 1;
    u8 dirty : 1;
} Work_021C4B9C;

typedef int s32;

struct Mtx {
    fx32 _00;
    fx32 _01;
    fx32 _10;
    fx32 _11;
};

typedef struct {
    u8 pad0[0x303C];
    fx32 scaleX;
    fx32 scaleY;
    u8 pad3044[0x304C - 0x3044];
    u32 cx;
    u32 cy;
    u32 x;
    u32 y;
    u8 pad305C[0x32CA - 0x305C];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 dirty : 1;
} Work_021C4F80;

typedef struct {
    u8 pad0[0x3060];
    int mode;
} Work_021C5008;

typedef struct {
    u8 pad0[4];
    void *f4;
} Args_v4858;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args_v4858 *args;
    Info_v4858 *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x305E - 0x3038];
    u16 h305E;
    u8 pad3060[0x3070 - 0x3060];
    Anim_v4858 anim;
} Work_v4858;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
    u8 f4_7 : 1;
} Info_021C51B4;

typedef struct {
    u8 pad0[0x98];
} Anim_021C51B4;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Sub24_v4858 *f24;
    Info_021C51B4 *info;
    u8 pad2C[0x305E - 0x2C];
    u16 h305E;
    u8 pad3060[0x3070 - 0x3060];
    Anim_021C51B4 anim;
    u8 pad3108[0x32F6 - 0x3108];
    u8 b32F6;
} Work_021C51B4_021C3CC0;

typedef struct {
    u8 pad0[0x10];
    u32 size;
    void *data;
} CharData_v4858;

typedef struct {
    u16 w;
    u16 h;
} ScrnData_v4858;

typedef struct {
    u8 pad0[4];
    void *f4;
    u32 f8;
} Sub24_v51B4;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Sub24_v51B4 *f24;
    Info_021C51B4 *info;
    u8 pad2C[0x305E - 0x2C];
    u16 h305E;
    u8 pad3060[0x3070 - 0x3060];
    Anim_021C51B4 anim;
    u8 pad3108[0x32F6 - 0x3108];
    u8 b32F6;
} Work_021C51B4_021C51B4;

typedef struct {
    u8 pad0[0x98];
    void *obj[8];
} Anim_021C51E4;

typedef struct {
    u8 pad0[0x3070];
    Anim_021C51E4 anim;
} Work_021C51E4;

typedef struct {
    u8 pad0[0x32C7];
    u8 blink;
    u8 phase;
} Work_021C523C;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
} Info_021C5264;

typedef struct {
    u8 pad0[0x28];
    Info_021C5264 *info;
} Work_021C5264;

typedef struct {
    u8 kind;
    u8 pad1[3];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
    u8 f4_7 : 1;
} Info_v51B4;

typedef struct {
    Info_v51B4 *info;
    void *f4;
} Args_v51B4;

typedef struct {
    u8 pad0[0x98];
} Anim_v51B4;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args_v51B4 *args;
    Info_v51B4 *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x305E - 0x3038];
    u16 h305E;
    u8 pad3060[0x3070 - 0x3060];
    Anim_v51B4 anim;
    u8 pad3108[0x32C6 - 0x3108];
    u8 b32C6;
    u8 pad32C7[0x32D8 - 0x32C7];
    u32 f32D8;
    u32 f32DC;
    u8 pad32E0[0x32F6 - 0x32E0];
    u8 b32F6;
} Work_v51B4;

typedef struct {
    u8 kind;
    u8 pad1[3];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
    u8 f4_7 : 1;
} Info_v5484;

typedef struct {
    Info_v5484 *info;
    void *f4;
} Args_v5484;

typedef struct {
    u8 pad0[0x98];
} Anim_v5484;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args_v5484 *args;
    Info_v5484 *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x305C - 0x3038];
    u16 h305C;
    u16 h305E;
    u8 pad3060[0x3070 - 0x3060];
    Anim_v5484 anim;
    u8 pad3108[0x32C6 - 0x3108];
    u8 b32C6;
    u8 pad32C7[0x32D8 - 0x32C7];
    u32 f32D8;
    u32 f32DC;
    u8 pad32E0[0x32F6 - 0x32E0];
    u8 b32F6;
} Work_021C5484;

typedef struct {
    u8 pad0[0x3034];
    u32 f3034;
    u8 pad3038[0x32E2 - 0x3038];
    s16 scroll;
    u8 pad32E4[0x32F7 - 0x32E4];
    u8 b32F7;
    u8 b32F8;
    u8 pad32F9[0x330E - 0x32F9];
    u8 b330E;
} Work_021C555C;

typedef struct {
    u8 pad0[0x32E2];
    s16 scroll;
    s16 prevScroll;
    s16 grabY;
    s16 grabScroll;
    u8 pad32EA[0x32F7 - 0x32EA];
    u8 b32F7;
    u8 pad32F8[0x330D - 0x32F8];
    u8 rows;
    u8 b330E;
} Work_v5484;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
    u8 f4_7 : 1;
} Info_021C567C;

typedef struct {
    u8 pad0[0x28];
    Info_021C567C *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x305E - 0x3038];
    u16 h305E;
} Work_021C567C;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
} Cfg_021C567C;

typedef struct {
    Cfg_021C567C *cfg;
    void *f4;
    u8 pad8[4];
    u32 fC;
    u32 f10;
} Args_021C567C;

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x48 - 7];
    u32 f48;
} Info_021C56E8;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args_021C567C *args;
    Info_021C56E8 *info;
    u8 pad2C[0x32C6 - 0x2C];
    u8 b32C6;
} Work_021C5718;

typedef struct {
    u8 pad0[0x32CA];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 dirty : 1;
    u8 pad32CB[0x32D6 - 0x32CB];
    u8 shake;
} Work_021C581C;

typedef struct {
    u8 pad0[0x10];
    u32 size;
    void *data;
} CharData_021C567C;

typedef struct {
    u16 w;
    u16 h;
} ScrnData_021C567C;

typedef struct {
    u8 pad0[0x3030];
    CharData_021C567C *chr;
    u8 pad3034[0x31DC - 0x3034];
    ScrnData_021C567C *scrn;
} Work_021C58E0_021C567C;

typedef struct {
    u8 pad0[0xC];
    u16 *data;
} PlttData;

typedef struct {
    u8 pad0[0x31EC];
    PlttData *pltt;
    int frame;
} Work_021C5B34;

typedef struct {
    u8 pad0[0x3034];
    u32 f3034;
    u8 pad3038[0x305E - 0x3038];
    u16 h305E;
    u8 pad3060[0x330F - 0x3060];
    u8 b330F;
} Work_021C5B80;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
} Info_021C5BCC;

typedef struct {
    u8 x;
    u8 y;
    u8 size;
    u8 active;
} TouchPos_021C567C;

typedef struct {
    u8 pad0[0x28];
    Info_021C5BCC *info;
    u8 pad2C[0x305C - 0x2C];
    u16 h305C;
    u8 pad305E[0x32EA - 0x305E];
    TouchPos_021C567C raw;
    TouchPos_021C567C cur;
    u8 pad32F2[0x32F6 - 0x32F2];
    u8 size;
    u8 pad32F7[0x330F - 0x32F7];
    u8 b330F;
} Work_021C5BCC;

extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0202223C(u32 a, u32 b);
extern u32 WIPE_ResetWndMask(void *win);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern u8 func_020355C4(void);
extern signed char func_02012FFC(void);
extern int func_0203D1B4(void);
extern void func_0203F8F4(u16 heap);
extern void func_020433E0(const struct DispVram *c);
extern struct PmsDraw *PMS_DRAW_Create(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void *func_020056A0(void (*cb)(void *, Work_021C581C *), void *ctx, int pri);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021C6D9C(Anim_021C3CC0 *a, const void *cfg);
extern void func_021C6804(Work_021C3CC0 *p, Info_021C3CC0 *info);
extern void func_021C6E8C(Anim_021C3CC0 *a);
extern void func_021C6000(Work_021C3CC0 *p);
extern void func_021C6D98(Work_021C3CC0 *p, void *bg, u32 a, void *b);
extern void func_020061E4(u32 a);
extern u32 func_020221A4(void);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204A600(void);
extern void PMS_DRAW_Main(u8 *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);
extern void *GAME_DATA_GetSaveBlock21(void **h);
extern void *func_020089CC(void *p);
extern void func_02082D44(const void *src, void *dst, u32 size);
extern u8 *func_02012944(void *p);
extern void func_02008558(struct Sub0200852CObj *obj, u8 value);
extern void func_02008A14(void *p, u32 v);
extern void func_02008A1C(struct Sub020089A8Obj *obj, u8 value);
extern void PMS_DRAW_Delete(struct Obj *p);
extern void func_021C6F4C(Anim_021C3F54 *a);
extern u32 func_020307B0(void *p);
extern void func_021C60A0(Work_021C40DC *p);
extern void func_02030EAC(struct Node *n);
extern void func_02031140(struct S02031140 *p);
extern void func_020355D8(u32 v);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u32 bgId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *ARC_UTIL_LoadPaletteDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern u32 func_020275E4(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 layer);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02040618(u32 bgId, u32 which, u32 value);
extern void func_020403F4(u32 bgId);
extern void func_0203F9B4(void);
extern void func_020414EC(u32 i);
extern void func_021C60CC(Work_v4754 *p, void **bg, Info_v4754 *info);
extern void func_021C6874(Work_v4754 *p, int scroll, int flush, int idx);
extern void func_021C636C(Work_v4754 *p, void **bg, Info_v4754 *info);
extern void func_021C631C(Work_v4754 *p, void **bg);
extern void func_021C6FA0(Anim_v4858 *a, int idx, u8 x, u8 y);
extern int GAME_DATA_CheckSaveFlag(int a0, int a1);
extern void PMS_DRAW_SetDecoVisible(struct Obj0202DCC4 *p, u32 i, u32 val);
extern void PMS_DRAW_SetVisible(struct Obj0202DC98 *o, int i, u32 a1);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern fx32 FX_Inv(fx32 v);
extern void func_0207D59C(void *reg, struct Mtx *m, u32 a, u32 b, u32 x, u32 y);
extern int func_02035C38(void);
extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
extern void GAME_DATA_SetSaveFlag(void *p, u32 a, u32 b);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int TOUCHPANEL_HitCont(const void *p);
extern int func_02035C08(const void *rect);
extern int func_02035C60(void);
extern u32 func_02035D20(u32 *x, u32 *y);
extern struct Sub020089A8Obj *sub_02008A00(struct Sub020089A8Obj *obj);
extern void func_021C61EC(Work_021C5718 *p, int v, int a);
extern void func_021C628C(Work_021C5718 *p, int v, int a);
extern void func_020419E4(void);
extern void func_0204A648(void);
extern void func_02087AE4(void);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern u32 func_0204162C(int channel);
extern void func_02041B6C(u32 bit);
extern void func_0207E468(const void *src, u32 offset, u32 size);
extern u32 TOUCHPANEL_HitPoint(struct Ctx *ctx, u32 a, u32 b);
int func_021C3CC0(void *man, int *state, Args_v3CC0 *args);
void func_021C3EF8(Info_021C3EF8 *info);
void func_021C3F18(Work_021C3F18 *p, int speed);
int func_021C3F54(void *proc, int *seq, int c, Work_021C3F54 *p);
int func_021C40DC(void *man, int *state, Args_021C40DC *args, Work_021C40DC *p);
void func_021C41C4(Work_021C41C4 *p);
void func_021C42C0(Work_021C42C0 *p);
void func_021C436C(Work_021C436C *p, int k, int alt);
void func_021C43C4(Work_021C43C4 *p, int k);
void func_021C43E8(void);
int func_021C4524(int x);
int func_021C4530(int x);
void func_021C453C(Work_v3CC0 *p);
void func_021C46F0(void);
void func_021C4754(Work_021C4754 *p, int kind);
void func_021C479C(Work_021C479C *p);
void func_021C47EC(Work_v4754 *p);
void func_021C4858(Work_021C4858 *p, int flag);
void func_021C49D8(Work_021C4858 *p, int flag);
void func_021C4AB0(Work_021C4858 *p, int flag);
void func_021C4B74(Work_021C4858 *p, int flag);
int func_021C4B9C(Work_021C4B9C *p);
void func_021C4D48(int side);
int func_021C4E0C(char *p);
void func_021C4F80(Work_021C4F80 *p);
int func_021C5008(Work_021C5008 *p);
int func_021C5054(Work_v4858 *p);
void func_021C513C(Work_v4858 *p);
void func_021C51B4(Work_021C51B4_021C51B4 *p, int flag, int v);
void func_021C51E4(Work_021C51E4 *p, int flag);
void func_021C523C(Work_021C523C *p, int flag);
int func_021C5264(Work_021C5264 *p, int hit);
int func_021C5280(Work_v51B4 *p, int hit);
int func_021C5484(Work_021C5484 *p, int hit);
void func_021C555C(Work_021C555C *p);
void func_021C55A4(Work_v5484 *p);
int func_021C567C(Work_021C567C *p);
int func_021C56E8(Work_021C56E8 *p);
void func_021C5718(Work_021C5718 *p, int sel, int *seq);
void func_021C581C(void *task, Work_021C581C *p);
void func_021C5874(void);
void func_021C58E0(Work_021C58E0_021C567C *p);
void func_021C5938(void *p);
void func_021C5958(const u8 *src, u8 *dst);
void func_021C59B0(const u8 *src, u8 *dst);
void func_021C59DC(u32 bg, int mode);
void func_021C5ACC(u32 bg, const void *src, int mode);
void func_021C5AEC(Work_021C5AEC *p);
void func_021C5B34(Work_021C5B34 *p);
void func_021C5B80(Work_021C5B80 *p);
void func_021C5BCC(Work_021C5BCC *p, int side);
void func_021C5CF4(u8 *dst, const u8 *src, int x, int y, int w, int h, int mode, int sel);
int func_021C5DB8(u8 *pix, const u8 *brush, int x1, int y1, int *px, int *py, int a, int b, int clip, int side);
void func_021C5F50(TouchPos_021C567C *src, TouchPos_021C567C *dst);
int func_021C5F64(u8 *pix, TouchPos_021C567C *cur, TouchPos_021C567C *prev, int flush, const void *src, u8 clip, u8 side);
extern const u8 d_021C8564[];
extern const u32 d_021C8E20[][2];
extern const u32 d_021C86E8[][2];
extern const struct DispConfig d_021C85C8;
extern const struct BgTemplate d_021C85E8;
extern const struct BgTemplate d_021C8608;
extern const struct BgTemplate d_021C8628;
extern const struct BgTemplate d_021C8648;
extern const struct BgTemplatePair d_021C8668;
extern const FileTable d_021C85D8;
extern s16 FX_SinCosTable_[];
extern const u8 d_021C8544[];
extern const u8 d_021C8554[];
extern const u8 d_021C8594[];
extern const u8 d_021C8534[];
extern const u8 d_021C854C[];
extern const u8 d_021C852C[];
extern const u8 d_021C853C[];
extern const u8 d_021C86A8[2][2][16];









int func_021C3CC0(void *man, int *state, Args_v3CC0 *args)
{
    Work_021C3CC0 *p;
    int i;
    u16 mask;

    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= ~0x1F00;
    *(volatile u32 *)0x04001000 &= ~0x1F00;
    func_0202223C(0, 0);
    func_0202223C(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    func_0203064C(1, 0x27, 0x50000);
    p = func_0203159C(man, sizeof(Work_021C3CC0), 0x27);
    func_02082BCC(p, 0, sizeof(Work_021C3CC0));
    p->heap = 0x27;
    p->anim.heap = 0x27;
    p->args = args;
    p->info = args->info;
    p->f3060 = func_020355C4();
    p->b32D5 = func_02012FFC();
    p->b32D4 = 0;
    if (p->info->b33) {
        p->f32CA_0 = 1;
    } else {
        p->f32CA_0 = 0;
    }
    mask = 1;
    for (i = 0; i < 16; i++) {
        if (p->info->h8 & mask) {
            p->flags[i] = 1;
        } else {
            p->flags[i] = 0;
        }
        mask <<= 1;
    }
    if (func_0203D1B4() > 0) {
        p->f32CA_1 = 1;
    }
    func_0203F8F4(p->heap);
    func_021C41C4((Work_021C41C4 *)p);
    func_020433E0((const struct DispVram *)d_021C8564);
    func_021C43E8();
    func_021C453C((Work_v3CC0 *)p);
    func_021C6D9C((Anim_021C3CC0 *)(&p->anim), d_021C8564);
    func_021C6804(p, p->args->info);
    func_021C6E8C((Anim_021C3CC0 *)(&p->anim));
    func_021C6000(p);
    p->f32B0 = PMS_DRAW_Create((u32)p->anim.f4, 1, (u32)p->f32CC, (u32)p->f31FC, 8, 1, 0x27);
    func_021C6D98(p, p->bg[4], 1, p->f320C);
    if (p->args->f14 == 2) {
        p->args->f14 = 0;
        p->f3034 = 1;
    } else {
        p->f3034 = 0;
    }
    p->args->fC = 0;
    p->b32C4 = 0;
    p->f31C4 = 0;
    if (p->info->f4_4) {
        p->b32C8 = 0;
    } else {
        p->b32C8 = 2;
    }
    p->f304C = 0x80;
    p->f3050 = 0x60;
    p->f3054 = 0;
    p->f3058 = 0;
    func_021C5874();
    func_021C47EC((Work_v4754 *)p);
    p->f31F4 = func_020056A0(func_021C581C, p, 1);
    p->f31F8 = func_0203101C(p->heap, p->heap, 3, 0);
    func_0203D34C(1, p->heap);
    func_0202208C((void *)1, 3, 3, 0, 6, 1, p->heap);
    return 1;
}









/*
 * Addresses are Black-image addresses.
 */
void func_021C3EF8(Info_021C3EF8 *info)
{
    info->b6++;
    if (info->b6 > (info->f4_1 + 1) * 8 - 1) {
        info->b6 = info->f4_1 * 8;
    }
}









void func_021C3F18(Work_021C3F18 *p, int speed)
{
    if (p->cooldown != 0) {
        p->cooldown--;
        return;
    }
    if (speed > 5) {
        p->cooldown = 5;
        if (p->b32F6 == 0) {
            func_020061E4(0x65C);
        } else {
            func_020061E4(0x7CF);
        }
    }
}









int func_021C3F54(void *proc, int *seq, int c, Work_021C3F54 *p)
{
    switch (*seq) {
    case 0:
        if (func_020221A4()) {
            *seq = 1;
        }
        break;
    case 1:
        func_021C5718((Work_021C5718 *)p, func_021C56E8((Work_021C56E8 *)p), (int *)seq);
        func_021C5AEC((Work_021C5AEC *)p);
        if (p->args->cfg->f4_6) {
            func_021C3F18((Work_021C3F18 *)p, func_021C5F64((u8 *)p->pix, (TouchPos_021C567C *)(&p->cur), (TouchPos_021C567C *)(&p->prev), 1, p->pix, p->f305E, p->f305C));
        }
        break;
    case 2:
        if (func_0204B98C(p->f3108) == 0) {
            func_0202208C((void *)2, 4, 4, 0, 6, 1, p->heap);
            *seq = 4;
        }
        break;
    case 3:
        if (func_0204B98C(p->f310C) == 0) {
            func_0202208C((void *)2, 4, 4, 0, 6, 1, p->heap);
            *seq = 4;
        }
        break;
    case 4:
        if (func_020221A4()) {
            return 1;
        }
        break;
    case 5:
        if (func_021C4B9C((Work_021C4B9C *)p)) {
            *seq = 1;
        }
        break;
    case 9:
        if (func_021C4E0C((char *)p)) {
            *seq = 1;
        }
        break;
    case 6:
        func_0202208C((void *)2, 4, 4, 0, 6, 1, p->heap);
        p->args->fC = 1;
        *seq = 4;
        break;
    case 7:
        if (func_0204B98C(p->f3110) == 0) {
            func_0202208C((void *)2, 4, 4, 0, 6, 1, p->heap);
            p->args->fC = 2;
            *seq = 4;
        }
        break;
    case 8:
        break;
    }
    p->b32D6++;
    if (p->b32D6 >= 0x100) {
        p->b32D6 = 0;
    }
    func_0204A600();
    PMS_DRAW_Main(p->f32B0);
    func_0201C4E4(p->f32CC);
    if (p->f31F8) {
        func_020310C4(p->f31F8);
    }
    return 0;
}









/*
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * Addresses are Black-image addresses.
 */
int func_021C40DC(void *man, int *state, Args_021C40DC *args, Work_021C40DC *p)
{
    void *a;
    void *b;

    if (!p->info->f4_5) {
        func_021C59B0(p->pix, p->info->bitmap);
        func_02082D44(p->info->bitmap, func_020089CC(GAME_DATA_GetSaveBlock21(p->args->f4)), 0x600);
    }
    if (args->f8 != 0) {
        a = func_02012944(p->args->f4);
        b = GAME_DATA_GetSaveBlock21(p->args->f4);
        func_02008558(a, p->info->b6);
        func_02008A14(b, p->info->f48);
        func_02008A1C(b, p->info->f4_4);
    }
    PMS_DRAW_Delete(p->f32B0);
    func_021C5874();
    func_021C42C0((Work_021C42C0 *)p);
    func_021C6F4C((Anim_021C3F54 *)(&p->anim));
    func_020307B0(p->f302C);
    func_020307B0(p->f31D8);
    func_020307B0(p->f31E8);
    func_021C60A0(p);
    func_021C46F0();
    func_02030EAC(p->f31F4);
    func_02031140((struct S02031140 *)p->f31F8);
    func_020355D8(p->f3060);
    func_020315D4(man);
    func_020306F0(0x27);
    return 1;
}









void func_021C41C4(Work_021C41C4 *p)
{
    int i;

    p->f31FC = func_0201D7EC(0x17, 0, 0, 0, p->heap);
    p->f3200 = func_02045B38(0, 2, 0xBB, p->heap);
    p->f3208 = func_020457B0(4, p->heap);
    p->f3210 = func_020457B0(0x20, p->heap);
    p->f3214 = func_020457B0(0x21, p->heap);
    p->f320C = func_020457B0(5, p->heap);
    func_02045CAC(p->f3200, 0x17, p->f320C);
    for (i = 0; i < 3; i++) {
        p->f3218[i] = func_02045EC0(p->f3200, i + 0x1A);
    }
    for (i = 0; i < 2; i++) {
        p->f3224[i] = func_02045EC0(p->f3200, i + 0x1D);
    }
    for (i = 0; i < 26; i++) {
        p->f322C[i] = func_02045EC0(p->f3200, i);
    }
    for (i = 0; i < 5; i++) {
        p->f3294[i] = func_02045EC0(p->f3200, i + 0x38);
    }
    p->f3204 = func_0201EC64(p->heap);
}









void func_021C42C0(Work_021C42C0 *p)
{
    int i;

    func_0201ED04(p->f3204);
    for (i = 0; i < 5; i++) {
        func_02045808(p->f3294[i]);
    }
    for (i = 0; i < 26; i++) {
        func_02045808(p->f322C[i]);
    }
    func_02045808(p->f3224[1]);
    func_02045808(p->f3224[0]);
    func_02045808(p->f3218[2]);
    func_02045808(p->f3218[1]);
    func_02045808(p->f3218[0]);
    func_02045808(p->f320C);
    func_02045808(p->f3214);
    func_02045808(p->f3210);
    func_02045808(p->f3208);
    func_02045C04(p->f3200);
    func_0201D83C(p->f31FC);
}









void func_021C436C(Work_021C436C *p, int k, int alt)
{
    int j = 1;
    u32 file;

    if (p->info->kind == 0x14) {
        j = 0;
    } else if (p->info->kind != 0x15) {
        k = 6;
    }
    file = d_021C8E20[k][j];
    func_02049B40(0x28, file, 4, 0, 0x200, p->heap);
    p->f31E8 = func_02049F34(0x28, file, (u32)(&p->f31EC), p->heap);
}









void func_021C43C4(Work_021C43C4 *p, int k)
{
    func_02049B40(0x29, d_021C86E8[k][1], 4, 0x80, 0x20, p->heap);
}









void func_021C43E8(void)
{
    *(volatile u16 *)0x04000304 |= 0x8000;
    {
        struct DispConfig disp = d_021C85C8;
        func_0203FC28(&disp);
    }
    {
        struct BgTemplate t = d_021C85E8;
        func_0203FCA0(7, &t, 2);
        func_020414AC(7);
        func_02040588(7, 1);
    }
    {
        struct BgTemplatePair t = d_021C8668;
        func_0203FCA0(4, &t.t[0], 0);
        func_020414AC(4);
        func_02040588(4, 1);
        func_0203FCA0(5, &t.t[1], 0);
        func_020414AC(5);
        func_02040588(5, 1);
    }
    {
        struct BgTemplate t = d_021C8608;
        func_0203FCA0(6, &t, 2);
        func_020414AC(6);
        func_02040588(6, 1);
    }
    {
        struct BgTemplate t = d_021C8628;
        func_0203FCA0(2, &t, 0);
        func_020414AC(2);
        func_02040588(2, 0);
    }
    {
        struct BgTemplate t = d_021C8648;
        func_0203FCA0(3, &t, 0);
        func_020414AC(3);
        func_02040588(3, 1);
    }
}








/*
 * Two ternaries selecting between two constants.
 */
int func_021C4524(int x)
{
    return x == 0x14 ? 0x20 : 0x1C;
}









int func_021C4530(int x)
{
    return x == 0x14 ? 0x2A : 0x29;
}









void func_021C453C(Work_v3CC0 *p)
{
    func_021C436C((Work_021C436C *)p, p->info->b3, p->info->f4_2);
    if (p->info->f4_7 == 0) {
        p->f302C = func_02049DB4(0x28, 0x1F, 0, (u32)(&p->f3030), p->heap);
        if (p->info->f4_1 == 0) {
            p->f31D8 = ARC_UTIL_LoadPaletteDataFromArchive(0x28, 0x2B, 0, (u32)(&p->f31DC), p->heap);
        } else {
            p->f31D8 = ARC_UTIL_LoadPaletteDataFromArchive(0x28, 0x2C, 0, (u32)(&p->f31DC), p->heap);
        }
    } else {
        p->f302C = func_02049DB4(0x29, d_021C86E8[p->info->b6][0], 0, (u32)(&p->f3030), p->heap);
        p->f31D8 = ARC_UTIL_LoadPaletteDataFromArchive(0x29, 0x20, 0, (u32)(&p->f31DC), p->heap);
        func_021C43C4((Work_021C43C4 *)p, p->info->b6);
    }
    func_021C58E0((Work_021C58E0_021C567C *)p);
    func_02049624((void *)0x28, (void *)func_021C4524(p->info->kind), (void *)6, 0, 0, 0, p->heap);
    func_0204989C(0x28, func_021C4530(p->info->kind), 6, 0, 0, 0, p->heap);
    func_02049624((void *)0x28, (void *)0x1E, (void *)5, 0, 0, 0, p->heap);
    func_0204989C(0x28, 0x28, 5, 0, 0, 0, p->heap);
    func_02049624((void *)0x28, (void *)0x1E, (void *)3, 0, 0, 0, p->heap);
    func_0204989C(0x28, 0x28, 3, 0, 0, 0, p->heap);
    func_02049B40(0x28, 0xF, 0, 0, 0x20, p->heap);
    func_021C5958(p->info->bitmap, p->pix);
    func_02049624((void *)func_020275E4(), (void *)func_02027628(), (void *)4, 0, 0, 0, p->heap);
    func_0204989C(func_020275E4(), func_0202762C(), 4, 0, 0, 0, p->heap);
    func_020413B0(4, 0, 0x15, 0x20, 3, 0xC);
    func_020409B4(4);
}









void func_021C46F0(void)
{
    func_020434DC(0x1F, 0);
    func_02043598(0x1F, 0);
    func_02040618(5, 0, 0);
    func_02040618(5, 3, 0);
    func_02040618(3, 0, 0);
    func_02040618(3, 3, 0);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(2);
    func_020403F4(3);
    func_0203F9B4();
}








void func_021C4754(Work_021C4754 *p, int kind)
{
    FileTable t = d_021C85D8;
    int j = 1;

    if (kind == 0x14) {
        j = 0;
    }
    func_0204989C(0x28, t.file[p->info->alt][j], 6, 0, 0, 0, p->heap);
}








void func_021C479C(Work_021C479C *p)
{
    if (p->f3034 == 0) {
        func_0204989C(0x28, func_021C4530(p->info->kind), 6, 0, 0, 0, p->heap);
        func_020414EC(7);
    } else {
        func_021C4754((Work_021C4754 *)p, p->info->kind);
        func_021C5938(p);
        func_020414EC(7);
    }
}







void func_021C47EC(Work_v4754 *p)
{
    func_021C479C((Work_021C479C *)p);
    func_021C60CC(p, p->bg, p->info);
    PMS_DRAW_Main(p->f32B0);
    if (p->f3034 == 0) {
        func_021C6874(p, p->scroll, 0, 0);
        func_021C58E0((Work_021C58E0_021C567C *)p);
    } else {
        func_021C636C(p, p->bg, p->info);
        func_021C5ACC(7, p->pix, p->phase);
    }
    func_021C4B74((Work_021C4858 *)p, p->f3034);
    func_021C631C(p, p->bg);
}










void func_021C4858(Work_021C4858 *p, int flag)
{
    if (flag == 0) {
        func_021C6FA0(&p->anim, 0, 1, 1);
        func_021C6FA0(&p->anim, 4, 0x12, 0);
        func_021C6FA0(&p->anim, 5, 6, 0);
        func_021C6FA0(&p->anim, 2, 0x10, 1);
        func_021C6FA0(&p->anim, 7, GAME_DATA_CheckSaveFlag((int)p->f24->f4, 0x15) + 6, 1);
    } else if (p->h305E == 0) {
        func_021C6FA0(&p->anim, 0, 1, 1);
        func_021C6FA0(&p->anim, 1, 0, 1);
        func_021C6FA0(&p->anim, 6, 0x16, 1);
        func_021C6FA0(&p->anim, 4, 0x12, p->info->f4_4 ^ 1);
        func_021C6FA0(&p->anim, 5, 8 - p->b32F6 * 2, p->info->f4_4 ^ 1);
        func_021C51B4((Work_021C51B4_021C51B4 *)p, p->info->f4_4, 1);
        func_021C6FA0(&p->anim, 7, GAME_DATA_CheckSaveFlag((int)p->f24->f4, 0x16) + 6, 1);
    } else {
        func_021C6FA0(&p->anim, 0, 0xF, 1);
        func_021C6FA0(&p->anim, 1, 0xE, 1);
        func_021C6FA0(&p->anim, 4, 0x14, 1);
        func_021C6FA0(&p->anim, 5, 8 - p->b32F6 * 2, 1);
        func_021C6FA0(&p->anim, 6, 0x16, 0);
        func_021C6FA0(&p->anim, 2, 10, 0);
    }
}










void func_021C49D8(Work_021C4858 *p, int flag)
{
    if (flag == 0) {
        func_021C6FA0(&p->anim, 0, 1, 1);
        func_021C6FA0(&p->anim, 4, 0x12, 0);
        func_021C6FA0(&p->anim, 5, 6, 0);
        func_021C6FA0(&p->anim, 2, 0x10, 1);
        func_021C6FA0(&p->anim, 7, GAME_DATA_CheckSaveFlag((int)p->f24->f4, 0x15) + 6, 1);
    } else {
        func_021C6FA0(&p->anim, 0, 1, 1);
        func_021C6FA0(&p->anim, 1, 0, 1);
        func_021C6FA0(&p->anim, 4, 0x12, 0);
        func_021C6FA0(&p->anim, 6, 0x16, 1);
        func_021C6FA0(&p->anim, 5, 8 - p->b32F6 * 2, 0);
        func_021C51B4((Work_021C51B4_021C51B4 *)p, p->info->f4_4, 0);
        func_021C6FA0(&p->anim, 7, GAME_DATA_CheckSaveFlag((int)p->f24->f4, 0x16) + 6, 1);
    }
}










void func_021C4AB0(Work_021C4858 *p, int flag)
{
    if (flag == 0) {
        func_021C6FA0(&p->anim, 0, 1, 1);
        func_021C6FA0(&p->anim, 1, 0xE, 0);
        func_021C6FA0(&p->anim, 2, 0x10, 0);
        func_021C6FA0(&p->anim, 5, 6, 0);
        func_021C6FA0(&p->anim, 7, 6, 0);
        func_021C6FA0(&p->anim, 4, 0, 0);
    } else {
        func_021C6FA0(&p->anim, 0, 1, 1);
        func_021C6FA0(&p->anim, 1, 0, 0);
        func_021C6FA0(&p->anim, 4, 0x12, 0);
        func_021C6FA0(&p->anim, 6, 0x16, 1);
        func_021C6FA0(&p->anim, 5, 8 - p->b32F6 * 2, 0);
        func_021C51B4((Work_021C51B4_021C51B4 *)p, p->info->f4_4, 0);
        func_021C6FA0(&p->anim, 7, 6, 0);
    }
}










void func_021C4B74(Work_021C4858 *p, int flag)
{
    if (p->info->f4_7 == 1) {
        func_021C4AB0((Work_021C4858 *)p, flag);
    } else if (p->f24->f8 == 0) {
        func_021C49D8((Work_021C4858 *)p, flag);
    } else {
        func_021C4858((Work_021C4858 *)p, flag);
    }
}









static inline fx32 FX_Mul(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}









int func_021C4B9C(Work_021C4B9C *p)
{
    int done = 0;

    switch (p->state) {
    case 0:
        p->angle = 0;
        p->scaleX = 0x103D;
        p->scaleY = 0x103D;
        func_020061E4(0x65A);
        if (p->f3034 == 0) {
            PMS_DRAW_SetDecoVisible(p->f32B0, 0, 0);
        }
        p->state++;
        break;
    case 1:
        p->scaleX = FX_Mul(FX_SinCosTable_[(p->angle >> 4) * 2 + 1], 0x103D);
        if (p->scaleX <= 0x80) {
            p->scaleX = 0x80;
            p->state++;
        }
        p->angle += 0x400;
        if (p->angle >= 0x4000) {
            p->angle = 0x4000;
        }
        break;
    case 2:
        p->f3034 ^= 1;
        func_021C479C((Work_021C479C *)p);
        func_021C4B74((Work_021C4858 *)p, p->f3034);
        p->state++;
        break;
    case 3:
        if (p->f3034 == 0) {
            func_021C58E0((Work_021C58E0_021C567C *)p);
        } else {
            func_021C5ACC(7, p->pix, p->phase);
        }
        p->state++;
        break;
    case 4:
        func_021C631C((Work_v4754 *)p, p->bg);
        p->state++;
        break;
    case 5:
        p->angle -= 0x400;
        if (p->angle <= 0) {
            p->angle = 0;
        }
        p->scaleX = FX_Mul(FX_SinCosTable_[(p->angle >> 4) * 2 + 1], 0x103D);
        if (p->scaleX <= 0x80) {
            p->scaleX = 0x80;
        }
        if (p->angle == 0) {
            p->scaleX = 0x1000;
            p->scaleY = 0x1000;
            done = 1;
            if (p->f3034 == 0) {
                PMS_DRAW_SetVisible(p->f32B0, 0, 1);
                PMS_DRAW_SetDecoVisible(p->f32B0, 0, 1);
            }
        }
        break;
    }
    p->dirty = 1;
    return done;
}









static inline void SetWnd0InsidePlane(int wnd, int effect)
{
    u32 tmp = (REG_DB_WININ & ~0x3F) | wnd;
    if (effect) {
        tmp |= 0x20;
    }
    REG_DB_WININ = (u16)tmp;
}









static inline void SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp = (REG_DB_WINOUT & ~0x3F) | wnd;
    if (effect) {
        tmp |= 0x20;
    }
    REG_DB_WINOUT = (u16)tmp;
}









void func_021C4D48(int side)
{
    if (side < 0) {
        REG_DB_BLDCNT = 0;
        REG_DB_DISPCNT &= ~0xE000;
    } else if (side == 0) {
        func_0207D658(0x04001050, 0xC, -8);
        REG_DB_WIN0H = 0xE000;
        REG_DB_WIN0V = 0xA8;
        SetWnd0InsidePlane(0x1C, 1);
        SetWndOutsidePlane(0x1F, 0);
        REG_DB_DISPCNT = (REG_DB_DISPCNT & ~0xE000) | 0x2000;
    } else if (side == 1) {
        func_0207D658(0x04001050, 0xC, -8);
        REG_DB_WIN0H = 0x20;
        REG_DB_WIN0V = 0xA8;
        SetWnd0InsidePlane(0x1C, 1);
        SetWndOutsidePlane(0x1F, 0);
        REG_DB_DISPCNT = (REG_DB_DISPCNT & ~0xE000) | 0x2000;
    }
}








/*
 * note 2026-10-05 (wave D4 lane 02): case 0 writes both stores (0x304C and 0x3050) in each
 * if/else arm. The compiler sinks the common stores into the join block and keeps the 0x305C
 * constant live, so 0x304C/0x3050 come out as 0x305C-0x10 / 0x305C-0xC.
 */
int func_021C4E0C(char *p)
{
    switch (*(u8 *)(p + 0x32C6)) {
    case 0:
        if (*(u16 *)(p + 0x305C) == 0) {
            *(u32 *)(p + 0x304C) = 0x20;
            *(u32 *)(p + 0x3050) = 0x98;
        } else {
            *(u32 *)(p + 0x304C) = 0xE0;
            *(u32 *)(p + 0x3050) = 0x98;
        }
        *(u32 *)(p + 0x303C) = 0x103D;
        *(u32 *)(p + 0x3040) = 0x103D;
        *(u8 *)(p + 0x32C6) = 1;
        break;
    case 1:
        *(int *)(p + 0x303C) += 0x100;
        *(int *)(p + 0x3040) += 0x100;
        if (*(int *)(p + 0x303C) >= 0x2000) {
            *(int *)(p + 0x303C) = 0x2000;
            *(int *)(p + 0x3040) = 0x2000;
            *(u8 *)(p + 0x32C6) = 2;
        }
        break;
    case 2:
        *(u16 *)(p + 0x305E) = 1;
        func_021C4B74((Work_021C4858 *)p, *(int *)(p + 0x3034));
        func_021C4D48(*(u16 *)(p + 0x305C));
        return 1;
    case 3:
        *(u8 *)(p + 0x32C6) = 4;
        break;
    case 4:
        *(int *)(p + 0x303C) -= 0x100;
        *(int *)(p + 0x3040) -= 0x100;
        if (*(int *)(p + 0x303C) <= 0x1000) {
            *(int *)(p + 0x303C) = 0x1000;
            *(int *)(p + 0x3040) = 0x1000;
            *(u8 *)(p + 0x32C6) = 5;
        }
        break;
    case 5:
        *(int *)(p + 0x304C) = 0x80;
        *(int *)(p + 0x3050) = 0x60;
        *(u16 *)(p + 0x305E) = 0;
        func_021C4B74((Work_021C4858 *)p, *(int *)(p + 0x3034));
        func_021C4D48(-1);
        return 1;
    case 6:
        *(u8 *)(p + 0x32C6) = 7;
        break;
    case 7:
        *(int *)(p + 0x304C) -= 8;
        if (*(int *)(p + 0x304C) < 0x20) {
            *(int *)(p + 0x304C) = 0x20;
            *(u8 *)(p + 0x32C6) = 8;
        }
        break;
    case 8:
        *(u16 *)(p + 0x305C) ^= 1;
        func_021C4D48(*(u16 *)(p + 0x305C));
        return 1;
    case 9:
        *(u8 *)(p + 0x32C6) = 10;
        break;
    case 10:
        *(int *)(p + 0x304C) += 8;
        if (*(int *)(p + 0x304C) > 0xE0) {
            *(int *)(p + 0x304C) = 0xE0;
            *(u8 *)(p + 0x32C6) = 11;
        }
        break;
    case 11:
        *(u16 *)(p + 0x305C) ^= 1;
        func_021C4D48(*(u16 *)(p + 0x305C));
        return 1;
    }
    *(u8 *)(p + 0x32CA) |= 4;
    return 0;
}








void func_021C4F80(Work_021C4F80 *p)
{
    struct Mtx m;

    m._00 = FX_Inv(p->scaleX);
    m._01 = 0;
    m._10 = 0;
    m._11 = FX_Inv(p->scaleY);
    func_0207D59C((void *)0x04001020, &m, p->cx, p->cy, p->x, p->y);
    func_0207D59C((void *)0x04001030, &m, p->cx, p->cy, p->x, p->y);
    p->dirty = 0;
}








int func_021C5008(Work_021C5008 *p)
{
    if (p->mode == 1) {
        if (func_02035C38()) {
            return 0;
        }
        if (func_0203630C()) {
            p->mode = 0;
            return 1;
        }
    } else {
        if (func_0203630C()) {
            return 0;
        }
        if (func_02035C38()) {
            p->mode = 1;
            return 0;
        }
    }
    return 0;
}







int func_021C5054(Work_v4858 *p)
{
    u32 key = func_020362DC();

    if (key & 2) {
        if (p->h305E == 0) {
            func_021C6FA0(&p->anim, 0, 9, 1);
            func_020061E4(0x551);
            func_020355D8((u32)0);
            return 4;
        }
    } else if (key & 0x400) {
        if (p->h305E == 0 && !p->info->f4_7) {
            func_021C6FA0(&p->anim, 1, 8, 1);
            func_020061E4(0x556);
            return 5;
        }
    } else if (key & 0x30) {
        if (p->h305E == 0) {
            func_021C6FA0(&p->anim, 6, 0x17, 1);
            return 3;
        }
    } else if (key & 0x800) {
        if (!p->info->f4_7) {
            func_021C513C(p);
        }
    } else if (key & 1) {
        if (!p->info->f4_7 && p->f3034 == 0) {
            func_020061E4(0x54C);
            func_021C6FA0(&p->anim, 2, 0x11, 1);
            return 10;
        }
    }
    return 0;
}







void func_021C513C(Work_v4858 *p)
{
    int v;

    func_020061E4(0x646);
    if (p->f3034 == 0) {
        v = GAME_DATA_CheckSaveFlag((int)p->args->f4, 0x15) ^ 1;
        func_021C6FA0(&p->anim, 7, v + 6, 1);
        GAME_DATA_SetSaveFlag(p->args->f4, 0x15, v);
    } else {
        v = GAME_DATA_CheckSaveFlag((int)p->args->f4, 0x16) ^ 1;
        func_021C6FA0(&p->anim, 7, v + 6, 1);
        GAME_DATA_SetSaveFlag(p->args->f4, 0x16, v);
    }
}







void func_021C51B4(Work_021C51B4_021C51B4 *p, int flag, int v)
{
    if (flag == 0) {
        func_021C6FA0((Anim_v4858 *)((Anim_v51B4 *)((Anim_021C51B4 *)(&p->anim))), 2, 10, v);
    } else {
        func_021C6FA0((Anim_v4858 *)((Anim_v51B4 *)((Anim_021C51B4 *)(&p->anim))), 2, 12, v);
    }
}








void func_021C51E4(Work_021C51E4 *p, int flag)
{
    if (flag == 0) {
        func_021C6FA0((Anim_v4858 *)((Anim_v51B4 *)((Anim_021C51B4 *)(&p->anim))), 2, 0xB, 1);
        func_0204B3DC(p->anim.obj[4], 0);
        func_0204B3DC(p->anim.obj[5], 0);
    } else {
        func_021C6FA0((Anim_v4858 *)((Anim_v51B4 *)((Anim_021C51B4 *)(&p->anim))), 2, 0xD, 1);
        func_0204B3DC(p->anim.obj[4], 1);
        func_0204B3DC(p->anim.obj[5], 1);
    }
}








void func_021C523C(Work_021C523C *p, int flag)
{
    if (flag) {
        p->phase = 0;
        p->blink = 0;
    } else {
        p->phase = 2;
    }
    func_021C59DC(7, p->phase);
}






int func_021C5264(Work_021C5264 *p, int hit)
{
    if (p->info->f4_5 && hit >= 3 && hit <= 9) {
        return 1;
    }
    return 0;
}





int func_021C5280(Work_v51B4 *p, int hit)
{
    if (func_021C5264((Work_021C5264 *)p, hit) == 1) {
        return 0;
    }
    switch (hit) {
    case 0:
        func_021C6FA0((Anim_v4858 *)((Anim_v51B4 *)((Anim_021C51B4 *)(&p->anim))), 0, 9, 1);
        func_020061E4(0x551);
        func_020355D8((u32)1);
        return 4;
    case 1:
        func_021C6FA0((Anim_v4858 *)((Anim_v51B4 *)((Anim_021C51B4 *)(&p->anim))), 1, 8, 1);
        func_020061E4(0x556);
        return 5;
    case 2:
        TOUCHPANEL_GetPointCont(&p->f32D8, &p->f32DC);
        func_021C6FA0((Anim_v4858 *)((Anim_v51B4 *)((Anim_021C51B4 *)(&p->anim))), 6, 0x17, 1);
        return 3;
    case 3:
        if (p->f3034 != 0) {
            if (p->args->info->f4_6) {
                func_021C51E4((Work_021C51E4 *)p, p->info->f4_4);
                p->info->f4_4 ^= 1;
                func_021C4754((Work_021C4754 *)p, p->info->kind);
                func_021C523C((Work_021C523C *)p, p->info->f4_4);
                func_020061E4(0x548);
            }
        } else {
            func_020061E4(0x54C);
            func_021C6FA0((Anim_v4858 *)((Anim_v51B4 *)((Anim_021C51B4 *)(&p->anim))), 2, 0x11, 1);
            return 10;
        }
        break;
    case 4:
        if (p->f3034 != 0 && !p->info->f4_4 && p->args->info->f4_6) {
            if (p->h305E == 0) {
                func_021C6FA0((Anim_v4858 *)((Anim_v51B4 *)((Anim_021C51B4 *)(&p->anim))), 4, 0x13, 1);
                func_020061E4(0x648);
                p->b32C6 = 0;
            } else {
                func_021C6FA0((Anim_v4858 *)((Anim_v51B4 *)((Anim_021C51B4 *)(&p->anim))), 4, 0x15, 1);
                func_020061E4(0x649);
                p->b32C6 = 3;
            }
            return 8;
        }
        break;
    case 5:
        if (p->f3034 != 0 && p->args->info->f4_6 && !p->info->f4_4) {
            func_020061E4(0x548);
            func_021C6FA0((Anim_v4858 *)((Anim_v51B4 *)((Anim_021C51B4 *)(&p->anim))), 5, 9 - p->b32F6 * 2, 1);
            p->b32F6 ^= 1;
        }
        break;
    case 6:
        func_021C513C((Work_v4858 *)p);
        break;
    case 7:
        if (p->f3034 == 0) {
            return 6;
        }
        break;
    case 8:
        if (p->f3034 == 0) {
            return 7;
        }
        break;
    case 9:
        if (p->f3034 == 0) {
            return 9;
        }
        break;
    }
    return 0;
}





int func_021C5484(Work_021C5484 *p, int hit)
{
    switch (hit) {
    case 4:
        if (p->f3034 != 0) {
            func_021C6FA0((Anim_v4858 *)(&p->anim), 4, 0x15, 1);
            func_020061E4(0x649);
            p->b32C6 = 3;
            return 8;
        }
        break;
    case 5:
        if (p->f3034 != 0) {
            func_020061E4(0x548);
            func_021C6FA0((Anim_v4858 *)(&p->anim), 5, 9 - p->b32F6 * 2, 1);
            p->b32F6 ^= 1;
        }
        break;
    case 6:
        func_021C513C((Work_v4858 *)p);
        break;
    case 10:
        if (p->h305C == 0) {
            func_020061E4(0x548);
            p->b32C6 = 9;
            return 8;
        }
        break;
    case 11:
        if (p->h305C == 1) {
            func_020061E4(0x548);
            p->b32C6 = 6;
            return 8;
        }
        break;
    }
    return 0;
}





void func_021C555C(Work_021C555C *p)
{
    if (p->f3034 != 0 && TOUCHPANEL_HitCont(d_021C8544) && p->b32F7 == 1) {
        func_021C6874((Work_v4754 *)p, p->scroll, 1, 0);
        p->b32F7 = 0;
        p->b32F8 = 0;
        p->b330E = 0;
    }
}




void func_021C55A4(Work_v5484 *p)
{
    u32 x, y;
    int lim;

    if (!func_02035C08(d_021C8544)) {
        p->b330E = 1;
    }
    if (p->b330E != 0 && !TOUCHPANEL_HitCont(d_021C8544)) {
        if (func_02035C60()) {
            func_02035D20(&x, &y);
            p->grabY = y;
            p->grabScroll = p->scroll;
        }
        if (func_02035C38()) {
            TOUCHPANEL_GetPointCont(&x, &y);
            p->scroll = p->grabScroll - (p->grabY - y);
        }
        lim = -(p->rows - 4) << 4;
        if (p->scroll < lim) {
            p->scroll = lim;
        } else if (p->scroll > 0) {
            p->scroll = 0;
        }
        if (p->prevScroll != p->scroll) {
            p->b32F7 = 1;
            func_021C6874((Work_v4754 *)p, p->scroll, 1, 1);
            func_020061E4(0x645);
        }
        p->prevScroll = p->scroll;
    }
}




int func_021C567C(Work_021C567C *p)
{
    int hit;
    int r;

    if (p->info->f4_7 == 0) {
        hit = func_02035C08(d_021C8594);
    } else {
        hit = func_02035C08(d_021C8554);
    }
    if (p->h305E == 0) {
        r = func_021C5280((Work_v51B4 *)p, hit);
    } else {
        r = func_021C5484((Work_021C5484 *)p, hit);
    }
    if (r != 0) {
        return r;
    }
    if (p->f3034 != 0) {
        if (p->h305E == 0) {
            func_021C55A4((Work_v5484 *)p);
            func_021C5BCC((Work_021C5BCC *)p, 0);
        } else {
            func_021C5BCC((Work_021C5BCC *)p, 1);
        }
    }
    return 0;
}





int func_021C56E8(Work_021C56E8 *p)
{
    func_021C5008((Work_021C5008 *)p);
    func_021C555C((Work_021C555C *)p);
    func_021C5B80((Work_021C5B80 *)p);
    if (p->mode == 1) {
        return func_021C567C((Work_021C567C *)p);
    }
    return func_021C5054((Work_v4858 *)p);
}





void func_021C5718(Work_021C5718 *p, int sel, int *seq)
{
    switch (sel) {
    case 3:
        p->b32C6 = 0;
        *seq = 5;
        break;
    case 8:
        if (p->args->cfg->f4_6) {
            *seq = 9;
        }
        break;
    case 9:
        if (p->args->cfg->f4_6) {
            func_020061E4(0x548);
            p->b32C6 = 0;
            *seq = 6;
        }
        break;
    case 4:
        *seq = 2;
        p->args->fC = 0;
        p->args->f10 = 0;
        break;
    case 5:
        *seq = 3;
        p->args->fC = 0;
        p->args->f10 = 1;
        break;
    case 6:
        if (p->args->cfg->f4_6) {
            sub_02008A00(GAME_DATA_GetSaveBlock21(p->args->f4));
            func_020061E4(0x548);
            func_021C3EF8((Info_021C3EF8 *)p->info);
            func_021C61EC(p, p->info->b6, 1);
        }
        break;
    case 7:
        if (p->args->cfg->f4_6) {
            func_020061E4(0x548);
            p->info->f48++;
            if (p->info->f48 > 0x18) {
                p->info->f48 = 0;
            }
            func_021C628C(p, p->info->f48, 1);
        }
        break;
    case 10:
        p->b32C6 = 0;
        *seq = 7;
        break;
    }
}





void func_021C581C(void *task, Work_021C581C *p)
{
    int ofs;

    func_021C5B34((Work_021C5B34 *)p);
    ofs = -(p->shake / 2);
    func_02040618(5, 0, ofs);
    func_02040618(5, 3, ofs);
    func_02040618(3, 0, ofs);
    func_02040618(3, 3, ofs);
    if (p->dirty) {
        func_021C4F80((Work_021C4F80 *)p);
    }
    func_020419E4();
    func_0204A648();
}





void func_021C5874(void)
{
    struct Mtx m;
    fx32 a, d;

    a = FX_Inv(0x1000);
    d = FX_Inv(0x1000);
    m._00 = a;
    m._01 = 0;
    m._10 = 0;
    m._11 = d;
    func_02087AE4();
    func_0207D59C((void *)0x04001020, &m, 0x80, 0x60, 0, 0);
    func_0207D59C((void *)0x04001030, &m, 0x80, 0x60, 0, 0);
    func_02087AE4();
    func_0207D59C((void *)0x04000030, &m, 0x80, 0, 0, 0);
}




void func_021C58E0(Work_021C58E0_021C567C *p)
{
    ScrnData_021C567C *s;

    func_02040B1C(7, p->chr->data, p->chr->size, 0);
    s = p->scrn;
    func_020410D0(7, 0x15, 2, 10, 11, (u32)s + 0xC, 0x15, 2, s->w >> 3, s->h >> 3);
    func_020409B4(7);
}




void func_021C5938(void *p)
{
    func_02041300(7, 0, 0x14, 6, 6, 9, 0x10);
}




void func_021C5958(const u8 *src, u8 *dst)
{
    int i;

    for (i = 0; i < 0x3000; i++) {
        if ((src[i / 64 * 8 + (u8)(i / 8 % 8)] >> (u8)(i % 8)) & 1) {
            dst[i] = 7;
        }
    }
}




void func_021C59B0(const u8 *src, u8 *dst)
{
    int i, j;
    int v;

    for (i = 0; i < 0x600; i++) {
        v = 0;
        for (j = 0; j < 8; j++) {
            v |= (src[i * 8 + j] & 1) << j;
        }
        dst[i] = v;
    }
}




void func_021C59DC(u32 bg, int mode)
{
    u16 *map = (u16 *)func_0204162C((u8)bg);
    u8 x, y;
    u16 n;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 24; x++) {
            map[(y + 11) * 32 + 4 + x] = 0;
        }
    }
    n = 0;
    switch (mode) {
    case 2:
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 24; x++) {
                n++;
                map[(y + 11) * 32 + 4 + x] = n;
            }
        }
        break;
    case 0:
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 12; x++) {
                n++;
                map[(y + 11) * 32 + 10 + x] = n;
            }
            n += 12;
        }
        break;
    case 1:
        n += 12;
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 12; x++) {
                n++;
                map[(y + 11) * 32 + 10 + x] = n;
            }
            n += 12;
        }
        break;
    }
    func_02041B6C((u8)bg);
}




void func_021C5ACC(u32 bg, const void *src, int mode)
{
    func_02040B1C((u8)bg, src, 0x3000, 1);
    func_021C59DC(bg, mode);
}




void func_021C5AEC(Work_021C5AEC *p)
{
    if (p->f3034 != 0 && p->info->f4_4) {
        p->blink++;
        if (p->blink > 20) {
            p->phase ^= 1;
            func_021C59DC(7, p->phase);
            p->blink = 0;
        }
    }
}




void func_021C5B34(Work_021C5B34 *p)
{
    u16 *pal = p->pltt->data;

    p->frame++;
    if (p->frame > 8) {
        p->frame = 0;
    }
    if (p->frame == 0) {
        func_0207E468(pal + 3, 6, 4);
    } else if (p->frame == 4) {
        func_0207E468(pal + 5, 6, 4);
    }
}




void func_021C5B80(Work_021C5B80 *p)
{
    if ((p->f3034 != 0 && p->h305E == 0 && TOUCHPANEL_HitCont(d_021C8534))
        || (p->h305E == 1 && TOUCHPANEL_HitCont(d_021C854C))) {
        p->b330F = 0;
    }
}




void func_021C5BCC(Work_021C5BCC *p, int side)
{
    u32 x, y;

    if (p->info->f4_5 || p->info->f4_4 == 1) {
        return;
    }
    if (TOUCHPANEL_GetPointCont(&x, &y)) {
        if (side == 0) {
            if (!func_02035C08(d_021C852C)) {
                p->b330F = 1;
            }
            if (p->b330F != 0 && !TOUCHPANEL_HitPoint((struct Ctx *)d_021C852C, x, y)) {
                p->raw.x = x;
                p->raw.y = y;
                p->raw.size = p->size;
                p->raw.active = 1;
                if (x < 0x80) {
                    p->h305C = 0;
                } else {
                    p->h305C = 1;
                }
            } else {
                p->raw.active = 0;
            }
        } else {
            if (!func_02035C08(d_021C853C)) {
                p->b330F = 1;
            }
            if (p->b330F != 0 && !TOUCHPANEL_HitPoint((struct Ctx *)d_021C853C, x, y)) {
                p->raw.x = ((x - 0x20) + p->h305C * 0xC0) / 2 + 0x20;
                p->raw.y = (y - 0x18) / 2 + 0x58;
                p->raw.size = p->size;
                p->raw.active = 1;
            } else {
                p->raw.active = 0;
            }
        }
    } else {
        p->raw.active = 0;
    }
    p->cur.x = p->raw.x;
    p->cur.y = p->raw.y;
    p->cur.size = p->raw.size;
    p->cur.active = p->raw.active;
}



/*
 * 4x4 tile blit into an 8x8-tile layout, 24 tiles per row.
 * The `b skip` stubs are `n++; continue;` repeated in each rejection arm
 * (tail merging leaves a lone branch per arm). xx and yy declared at the top,
 * before j, k, n, give the image colours (xx r2, k r3, n r4).
 */
void func_021C5CF4(u8 *dst, const u8 *src, int x, int y, int w, int h, int mode, int sel)
{
    int xx, yy;
    int j, k, n = 0;
    for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
            xx = x + k;
            yy = y + j;
            if (xx < 0 || yy < 0) {
                n++;
                continue;
            }
            if (xx >= w || yy >= h) {
                n++;
                continue;
            }
            if (mode == 1 && ((sel == 0 && xx >= 0x60) || (sel == 1 && xx <= 0x5f))) {
                n++;
                continue;
            }
            {
                int idx = xx % 8 + ((yy % 8) * 8 + ((yy / 8) * 24 + xx / 8) * 64);
                int c = src[n];
                if (c == 1) dst[idx] = 7;
                else if (c == 2) dst[idx] = 0;
            }
            n++;
        }
    }
}




int func_021C5DB8(u8 *pix, const u8 *brush, int x1, int y1, int *px, int *py, int a, int b, int clip, int side)
{
    int n = 0;
    int x = *px;
    int y = *py;
    int ex = x1;
    int dx, dy;
    int ey = y1;
    int e, s;

    if (a == 0 && b == 0) {
        *px = x1;
        *py = y1;
        return n;
    }
    dx = x1 - x;
    if (dx < 0) {
        dx = -dx;
    }
    dy = y1 - y;
    if (dy < 0) {
        dy = -dy;
    }
    if (dx > dy) {
        if (x > x1) {
            s = (y > y1) ? 1 : -1;
            ex = x;
            x = x1;
            y = y1;
        } else {
            s = (y < y1) ? 1 : -1;
        }
        func_021C5CF4(pix, brush, x, y, 0xC0, 0x40, clip, side);
        x++;
        e = dx >> 1;
        n++;
        for (; x <= ex; x++) {
            e -= dy;
            if (e < 0) {
                e += dx;
                y += s;
            }
            func_021C5CF4(pix, brush, x, y, 0xC0, 0x40, clip, side);
            n++;
        }
    } else {
        if (y > y1) {
            s = (x > x1) ? 1 : -1;
            ey = y;
            y = y1;
            x = x1;
        } else {
            s = (x < x1) ? 1 : -1;
        }
        func_021C5CF4(pix, brush, x, y, 0xC0, 0x40, clip, side);
        y++;
        e = dy >> 1;
        n++;
        for (; y <= ey; y++) {
            e -= dx;
            if (e < 0) {
                e += dy;
                x += s;
            }
            func_021C5CF4(pix, brush, x, y, 0xC0, 0x40, clip, side);
            n++;
        }
    }
    *px = x1;
    *py = y1;
    return n;
}




void func_021C5F50(TouchPos_021C567C *src, TouchPos_021C567C *dst)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->size = src->size;
    dst->active = src->active;
}




int func_021C5F64(u8 *pix, TouchPos_021C567C *cur, TouchPos_021C567C *prev, int flush, const void *src, u8 clip, u8 side)
{
    int drew = 0;
    int n = 0;
    int ofs;
    int px, py;

    if (clip == 0) {
        ofs = 4;
    } else {
        ofs = 2;
    }
    if (cur->active) {
        if (prev->active) {
            px = prev->x - 0x20 - ofs;
            py = prev->y - 0x5A;
        }
        n = func_021C5DB8(pix, d_021C86A8[clip][cur->size], cur->x - 0x20 - ofs, cur->y - 0x5A, &px, &py, 0, prev->active, clip, side);
        drew = 1;
    }
    if (drew && flush) {
        func_02040B1C(7, src, 0x3000, 1);
    }
    func_021C5F50(cur, prev);
    cur->active = 0;
    return n;
}
