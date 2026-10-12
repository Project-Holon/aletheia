/*
 * file:     wipe_sub.c
 * unit:     yes
 * function: func_02021728, func_02021730, func_0202173C, func_02021848, func_02021930, func_02021944, func_02021984, func_020219C4, func_02021A84, func_02021B18, func_02021B2C, func_02021B4C, func_02021B6C, func_02021BC8, func_02021C20, func_02021CA8, func_02021D50, func_02021ED8, func_02021EE4, func_02021F08, func_02021F3C, func_02021F64, func_02021FD8, func_02022004, func_02022040, func_0202208C, func_02022174, func_020221A4, func_020221B8, func_02022224, func_02022230, func_0202223C, func_02022268, func_020222A8, func_020222CC, func_020222EC, func_02022340, func_02022390, func_020223AC, func_020223C0, func_02022424, func_02022430, func_02022458, func_02022478, func_02022490, func_020224DC, func_02022518, func_02022568, func_020225B4, func_020225D4, func_020225F0, func_020225F4, func_02022608, func_0202262C, func_02022640, func_02022670, func_020226A0, func_020226E0, func_020226FC, func_0202271C, func_02022758, func_02022790, func_020227CC, func_02022804, func_02022830, func_0202285C, func_02022888, func_020228B4, func_020228E0, func_0202290C, func_0202291C, func_02022940, func_020229A4, func_02022A44, func_02022A88, func_02022AC4, func_02022AD0, func_02022CEC, func_02022D70, func_02022D78, func_02022D88, func_02022D98, func_02022DCC, func_02022E20, func_02022E88, func_02022EA0, func_02022EF4, func_02022F0C, func_02022F24, func_02022F34, func_02022F60, func_02023464, func_020234C0, func_0202350C, func_02023568, func_020235F0, func_0202363C, func_0202368C, func_02023768, func_020237B8, func_0202384C, func_020238B4, func_0202390C, func_02023964, func_02023A50, func_02023AAC, func_02023AB0, func_02023AF4, func_02023B48, func_02023B74, func_02023BFC, func_02023C3C, func_02023CFC, func_02023D18, func_02023D40, func_02023D60, func_02023D94, func_02023DA8, func_02023DC4, func_02023DDC, func_02023E0C, func_02023E9C, func_02023EF4, func_02023F60, func_02023F98, func_02023FD8, func_02024004, func_02024044, func_020240FC, func_02024104, func_02024108, func_0202411C, func_02024120, func_02024124, func_02024128, func_02024134, func_02024144, func_02024148, func_0202414C, func_02024150, func_02024158, func_02024160, func_02024168, func_0202419C, func_020241E0, func_0202421C, func_02024224, func_02024230, func_0202428C, func_020242A4, func_020242C0, func_020242D8, func_02024344, func_0202435C, func_02024368, func_0202441C, func_02024450, func_02024464, func_02024498, func_020244D4, func_020244F0, func_020244F8, func_02024508, func_02024520, func_0202452C, func_02024530, func_02024534, func_02024570, func_02024584, func_02024598, func_020245A0, func_020245AC, func_020245D4, func_0202465C, func_020246C8, func_0202473C, func_02024768, func_020247A8, func_020247F0, func_02024810, func_02024838, func_02024888, func_020248D8, func_02024910, func_02024918, func_02024934, func_02024938, func_02024988, func_02024994, func_020249A0, func_020249B0, func_02024A20, func_02024ABC, func_02024DCC, func_02024DFC, func_02025154, func_020251D8, func_020251FC, func_020252A8
 * address:  0x02021728
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EAC   0x02030EAC  arm
 *   func_020862F0   0x020862F0  arm
 *   func_0207E3D0   0x0207E3D0  arm
 *   func_0207E468   0x0207E468  arm
 *   func_0207E51C   0x0207E51C  arm
 *   func_0207E5D0   0x0207E5D0  arm
 *   func_0207F308   0x0207F308  arm
 *   func_0207F394   0x0207F394  arm
 *   func_0207F428   0x0207F428  arm
 *   func_0207F47C   0x0207F47C  arm
 *   func_0207F4C4   0x0207F4C4  arm
 *   func_0207F560   0x0207F560  arm
 *   func_0207F5B0   0x0207F5B0  arm
 *   func_0207F5C8   0x0207F5C8  arm
 *   func_0207F65C   0x0207F65C  arm
 *   func_0207F6A8   0x0207F6A8  arm
 *   func_0207F6C0   0x0207F6C0  arm
 *   func_0207F754   0x0207F754  arm
 *   g_021467A4                0x021467A4  data
 *   CARD_GetBackupSectorSize  0x0204E6E0  arm
 *   _s32_div_f                0x0209C0A4  arm
 *   func_0207D534  0x0207D534  arm
 *   g_0209F538  0x0209F538  data
 *   func_02005624  0x02005624  thumb
 *   func_02030734  0x02030734  arm
 *   func_020056A0  0x020056A0  thumb
 *   g_020A73C8     0x020A73C8  data
 *   func_020307B0  0x020307B0  arm
 *   d_0209F570     0x0209F570  data
 *   g_020A73D0     0x020A73D0  data
 *   g_wipe_slot0   0x020A73D0  data
 *   d_0209F56C     0x0209F56C  data
 *   d_0209F574     0x0209F574  data
 *   d_0209F568     0x0209F568  data
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_02082BCC  0x02082BCC  arm
 *   MI_CpuCopy8   0x02082D44  arm
 *   MI_CpuFill8   0x02082BCC  arm
 *   func_02023464_File  0x020A7450  data
 *   g_dat          0x020A7450  data
 *   _ll_mul   0x0209C054  arm
 *   FX_Sqrt   0x0207C7B4  arm
 *   reg_DISPCNT_SUB  0x04001000  data
 *   reg_BLDCNT      0x0400004A  data
 *   reg_BLDCNT_SUB  0x0400104A  data
 *   func_0207D658  0x0207D658  arm
 *   G2x_SetBlendBrightness_   0x0207D658  arm
 *   data_0214691C             0x0214691C  data
 *   data_021468FC             0x021468FC  data
 *   g_wipe_main    0x0214691C  data
 *   g_wipe_flags   0x021468FC  data
 *   g_wipe_subrec  0x021468FC  data
 *   g_021468FC    0x021468FC  data
 *   g2_021468FC   0x021468FC  data
 *   g_0214691C    0x0214691C  data
 *   d_021468FC  0x021468FC  data
 *   func_020071CC  0x020071CC  thumb
 *   func_02012FE4  0x02012FE4  thumb
 *   func_020142E8  0x020142E8  thumb
 *   file_020A745C  0x020A745C  data
 *   unit_020355C4  0x020355C4  arm
 *   func_020355D8 0x020355D8 arm
 *   tbl_020A1B38   0x020A1B38  data
 *   Table_0209F724   0x0209F724  data
 *   func_0201EC64    0x0201EC64  thumb
 *   func_0201ED04    0x0201ED04  thumb
 *   func_0201EFC8    0x0201EFC8  thumb
 *   func_0201EFFC    0x0201EFFC  thumb
 *   func_0201F250    0x0201F250  thumb
 *   func_020457B0    0x020457B0  arm
 *   func_02045808    0x02045808  arm
 *   func_02045B38    0x02045B38  arm
 *   func_02045C04    0x02045C04  arm
 *   func_02045EC0    0x02045EC0  arm
 *   g_0209F724  0x0209F724  data
 *   g_0209F71C  0x0209F71C  data
 *   data_0209F734  0x0209F734  data
 *   str_020A746C   0x020A746C  data  a1
 *   tbl_0209F7AC   0x0209F7AC  data  a2
 *   Table_0209F7AC   0x0209F7AC  data
 *   func_0204581C    0x0204581C  arm
 *   func_02045CAC    0x02045CAC  arm
 *   g_tbl0   0x0209F7AC  data
 *   g_tbl1   0x0209F792  data
 *   g_0209F792  0x0209F792  data
 *   tbl_0209F784   0x0209F784  data  a1
 *   data_0209F7C8  0x0209F7C8  data
 *   func_0203568C       0x0203568C  arm
 *   func_0201283C       0x0201283C  thumb
 *   func_02012BB0       0x02012BB0  thumb
 *   gInfoWin            0x0214693C  data
 *   infowin_File        0x020A7478  data
 *   func_0203CD98       0x0203CD98  arm
 *   func_0203D798       0x0203D798  arm
 *   func_0203D1B4       0x0203D1B4  arm
 *   func_0203D29C       0x0203D29C  arm
 *   func_0201058C       0x0201058C  thumb
 *   func_02026CA0       0x02026CA0  thumb
 *   d_0209F830          0x0209F830  data a4
 *   d_0209F834          0x0209F834  data a2
 *   d_0209F838          0x0209F838  data a4
 *   d_0209F840          0x0209F840  data a4
 *   d_0209F848          0x0209F848  data a4
 *   d_0209F852          0x0209F852  data a2
 *   d_0209F868          0x0209F868  data a4
 *   d_0209F870          0x0209F870  data a2
 *   func_020410D0       0x020410D0  arm
 *   func_020409B4       0x020409B4  arm
 *   func_02035630       0x02035630  arm
 *   OS_IsRunOnTwl       0x02085D3C  arm
 *   func_020490F4       0x020490F4  arm
 *   func_0203FA08       0x0203FA08  arm
 *   func_02049B68       0x02049B68  arm
 *   func_02049658       0x02049658  arm
 *   ENV_SetResourceSet  0x02049238  arm
 *   func_02041300       0x02041300  arm
 *   func_0203F4CC       0x0203F4CC  arm
 */
#include "../../matched/include/Obj16741.h"
#include "../../matched/include/Obj11726.h"
#include "../../matched/include/Obj15738.h"
#include "../../matched/include/Obj04050.h"
#include "../../matched/include/Obj15744.h"
#include "../../matched/include/Obj05795.h"

#define REG_VCOUNT  (*(volatile u16 *)0x04000006)
#define REG_A       ((volatile u16 *)0x04000004)
#define REG_B       ((volatile u16 *)0x04001040)
#define REG_C       ((volatile u16 *)0x04001042)
#define REG_DISPSTAT  (*(volatile u16 *)0x04000004)
#define REG_WININ     (*(volatile u16 *)0x04000048)
#define REG_WINOUT    (*(volatile u16 *)0x0400004A)
#define REG_DB_WININ  (*(volatile u16 *)0x04001048)
#define REG_DB_WINOUT (*(volatile u16 *)0x0400104A)
#define LEAF(REG, MASK, VAL, EFF)            \
    if (REG_DISPSTAT & 2) {                  \
        v = (REG & MASK) | (VAL);            \
        REG = v | EFF;                       \
    }
#define SET_OUT(eng, wnd)                                        \
    if ((eng) == 0) { LEAF(REG_WINOUT, ~0x3F, wnd, 0x20) }       \
    else { LEAF(REG_DB_WINOUT, ~0x3F, wnd, 0x20) }
#define SET_IN(eng, which, wnd)                                          \
    e = (eng);                                                           \
    if ((which) == 0) {                                                  \
        if (e == 0) { LEAF(REG_WININ, ~0x3F, wnd, 0x20) }            \
        else { LEAF(REG_DB_WININ, ~0x3F, wnd, 0x20) }                    \
    } else {                                                             \
        if (e == 0) { LEAF(REG_WININ, ~0x3F00, (wnd) << 8, 0x2000) }  \
        else { LEAF(REG_DB_WININ, ~0x3F00, (wnd) << 8, 0x2000) }          \
    }
#define REG_DISPCNT     (*(volatile u32 *)0x04000000)
#define REG_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_BLDCNT     (*(volatile u16 *)0x0400004A)
#define REG_BLDCNT_SUB (*(volatile u16 *)0x0400104A)
struct Node;
struct WinPanel;
struct Slots;
struct Obj;
struct Q;
struct Rec_020225F0;
struct AnimStep;
struct WipeScan;
struct Struct_02023CFC;
struct WipeSubElem;
struct S_02022E20;
struct Quad;
struct Ctx;
struct Par;
struct Wipe_02022E20;
struct Container_020225F0;
struct ctl;
struct Desc;
struct Args2;
struct Args4;
struct Args3;
struct WinPanel020071CCCtrl;
struct Rec8;
struct Data;
struct Obj_0202411C;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
struct BigObj;
struct RtcTime;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct WinPanel {
    u32   f00;
    u32   f04;
    s32   f08;
    u32   phase;
    u32   f10;
    void *obj;
    u32   f18;
    u32   f1C;
    u32   heap;
    u16   f24;
    u16   f26;
    u32   f28;
    u32   f2C;
};

typedef void (*Handler)(void *ctx);

struct Slots {
    void   *ctx[2];
    Handler fn[2];
    u32     arg[2];
};

struct DualWin {
    u32            mode;
    u32            top;
    u32            bottom;
    u32            f0C;
    u32            f10;
    struct WinPanel f14;
    struct WinPanel f44;
    struct Slots   f74;
    u8             f8C[0xC0];
    u16            f14C;
    u8             f14E;
    u8             f14F;
    u16            f150;
    u16            pad152;
    void          *f154;
};

typedef signed   short s16;

typedef signed   char  s8;

typedef struct {
    u16 f0;
    u16 lo     : 6;
    u16 cur    : 5;
    u16 max    : 5;
    u16 target : 15;
    u16 sign   : 1;
    u16 step   : 5;
    u16 copy   : 6;
    u16 pad    : 5;
} PalAnmSlot;

typedef struct {
    u16 *src;
    u16 *dst;
    u32 f8;
    PalAnmSlot slot;
} PalAnmChan;

typedef struct {
    PalAnmChan ch[14];
    u16 a_mode : 2;
    u16 a_big  : 14;
    u16 b_lo : 14;
    u16 b_x  : 1;
    u16 b_hi : 1;
    u8  latch;
} PalAnmObj;

struct Rgb555 {
    u16 r : 5;
    u16 g : 5;
    u16 b : 5;
    u16 pad : 1;
};

typedef u32 (*FuncPtr)(void *);

struct G_020225F0 {
    u32 f00;
    u8  pad04[0xc];
    u32 f10;
    u8  pad14[0xc];
    u32 f20;
    u32 pad24;
    u32 f28;
};

struct Q {
    u8  pad[0x10];
    u32 unk10;
};

typedef int           s32_0202290C;

struct Quad {
    u32 a, b, c, d;
};

struct Struct_02023CFC {
    void *val;
    u32 idx;
};

typedef int           s32_02022940;

typedef signed int     s32_020229A4;

typedef int s32_02022A88;

struct AnimStep {
    s32_02022A88 steps;
    s32_02022A88 limit;
    s32_02022A88 counter;
    s32_02022A88 val;
    s32_02022A88 target_val;
    s32_02022A88 step_delta;
    s32_02022A88 pad18;
    s32_02022A88 scaled_val;
    void *f20;
};

typedef signed int     s32_02022AD0;

struct ctl {
    u32 pad0;
    u32 mode;
    u32 sel;
};

struct sched {
    s16 x[0xc0];
    s16 y[0xc0];
    u8  pad[0x300];
    u32 flag;
};

struct Container_020225F0 {
    void *base;
    s32 count;
};

struct WipeSubElem {
    u8 buf1[0xC0];
    u8 buf2[0xC0];
    u32 unk;
};

struct Half {
    u8  pad[0xC0];
    u8  rows[0xC0];
    u32 wnd;
};

struct S_02022E20 {
    struct Half h[2];
    u8 mode;
    u8 eng;
};

typedef signed int     s32_0202350C;

typedef enum { Z0 } E;

typedef int          s32_02023568;

struct WipeTiles {
    s32_02023568 x;       /* 0x00 */
    s32_02023568 y;       /* 0x04 */
    s32_02023568 z;       /* 0x08 */
    s32_02023568 w;       /* 0x0c */
    struct Quad q10;
    u32 f20;     /* 0x20 */
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    s32_02023568 steps;   /* 0x38 */
    s32_02023568 period;  /* 0x3c */
    s32_02023568 tick;    /* 0x40 */
    u32 f44;
    u32 f48;     /* 0x48 */
};

struct Rec_020225F0 {
    u8  pad0[0xc];
    u32 mode;      /* +0xc */
    u32 f10;       /* +0x10 */
    void *entry;   /* +0x14 */
};

struct Entry {
    u8  pad0[0x2c];
    u32 f2c;       /* +0x2c */
    u32 f30;       /* +0x30 */
};

typedef int s32_0;

typedef struct Par {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    u8  f8;
    u8  f9;
    u8  fa;
    u8  fb;
} Par;

typedef struct Ctx {
    u32 pad0[3];
    u32 c;
    u32 h10;
    u32 h14;
    u32 h18;
    u32 h1c;
    u32 h20;
    u32 h24;
    u32 h28;
    u32 h2c;
    u32 h30;
    u32 h34;
} Ctx;

typedef signed int   s32_1;

struct Wipe_02022E20 {
    u32 f00;
    u32 f04;
    u32 f08;
    s32_1 f0c;          /* 0x0c  running offset */
    u32 f10;
    u32 f14;
    s32_1 f18;          /* 0x18  stride */
    s32_1 left;         /* 0x1c  countdown */
    s32_1 frame_limit;  /* 0x20 */
    s32_1 frame;        /* 0x24 */
    u32 f28;          /* 0x28 */
    u32 f2c;
    u32 f30;
    u32 f34;          /* 0x34 */
};

typedef signed long long s64;

struct Wipe_0202384C {
    u32 f00;
    u32 f04;
    u32 f08;
    s32 f0c;      /* 0x0c */
    s32 f10;      /* 0x10 */
    s32 f14;      /* 0x14  half-height of the mirrored band */
};

struct Buf {
    s16 pad000[0x180];
    s16 left[0xC0];   /* 0x300 */
    s16 right[0xC0];  /* 0x480 */
};

struct Desc {
    u32 f00;
    u16 f04;
    u16 f06;
};

struct WipeScan {
    u8  rows[2][0xC0];   /* 0x000 */
    u8  pad180[0x30C - 0x180];
    u32 f30C;            /* 0x30c */
    s32 f310;
    s32 step_bound;      /* 0x314  see the note above: a floor, not a ceiling */
    s32 step;            /* 0x318 */
    s32 frame_limit;     /* 0x31c */
    s32 frame;           /* 0x320 */
    s32 f324;
    s32 f328;
    u32 f32c;
    u32 f330;
};

struct Item_02023D18 {
    void *val;
    u32 field_4;
    u32 field_8;
    u32 field_C;
};

struct Big_02023D18 {
    u8 pad[0x10];
    struct Item_02023D18 items[1][1];
};

struct Item_02023D40 {
    void *val;
    u32 field_4;
    u32 field_8;
};

struct Rec_02023964 {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    u32 f8;
    u32 fC;
};

struct Args2 {
    u32 f0;
    u32 f4;
};

struct Args4 {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
};

struct Args3 {
    u32 f0;
    u32 f4;
    u32 f8;
};

typedef short          s16_0;

typedef signed short   s16_02023E9C;

struct Interp {
    u32 f00;
    u32 f04;
    u16 f08;
    u16 f0a;
    u16 f0c;
    u16 f0e;
    signed char f10;
    u8  f11;
    s16_02023E9C f12;
    s16_02023E9C f14;
    u16 f16;
    u16 f18;
    s16_02023E9C f1a;
    u32 f1c;
};

typedef int            s32_02023EF4;

struct Obj_02023EF4 {
    u8  kind;        /* +0x00 */
    u8  f01;         /* +0x01 */
    u8  f02;         /* +0x02 */
    u8  b0 : 1;      /* +0x03 */
    u8  b1 : 1;
    u8  b2 : 1;
    u8  b3 : 1;
    u8  rest : 4;
    u8  pad04[4];
    void *f08;       /* +0x08 */
    void *f0c;       /* +0x0c */
    u8  slot[8];     /* +0x10 */
    u16 f18[2];      /* +0x18 */
};

struct Src02024128 {
    unsigned char pad[0x18];
    unsigned short a;
    unsigned short b;
};

typedef struct {unsigned char pad[3];unsigned char flag:1;unsigned char rest:7;} Bits_02024150;

typedef struct {unsigned char pad[3];unsigned char rest:3;unsigned char flag:1;unsigned char last:4;} Bits_02024160;

typedef struct Pair { u16 x,y; } Pair;

typedef struct Input {
    u8 mode; u8 pad01[15]; u16 values10[4]; u16 values18[2];
} Input;

struct Obj_0202411C {
    u8  f0;
    u8  pad1[0x17];
    u16 f18;    /* 0x18 */
    u16 f1A;    /* 0x1A */
};

struct T {
    u8  pad00[1];
    u8  f01;
    u8  f02;
    u8  pad03[0xd];
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    u16 f18;
    u16 f1a;
};

typedef signed int       s32_02024230;

typedef int             s32_0202428C;

struct Struct_0202441C {
    u16 arcFileIdx;
    u16 strIdx;
};

typedef signed int     s32_02024464;

struct Container_02023EF4 {
    u8 pad[4];
    u16 arr[];
};

struct Data {
    u16 a;
    u16 b;
    u16 c[2];
};

struct Rec8 {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
};

struct Rec4 {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
};

struct Tbl {
    u16 f[12];
};

struct PmsWordSys {
    u32   heapId;
    void *msg[13];
};

struct Item {
    u8 bytes[8];
};

struct Obj02024838 {
    u8          pad[8];
    struct Item items[20];
};

struct PmsWordEntry {
    u32 f00;
    u16 word[2];
};

struct PmsWord {
    u32 flags;
    u32 f04;
    struct PmsWordEntry e[20];
};

typedef struct Group {
    const u16 *list;
    int count;
} Group;

struct InfoWin {
    u32 f00;
    u16 f04;
    u8  f06;
    u8  f07;
    u8  f08;
    u8  f09;
    u8  pad0A[2];
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u8  f1C;
    u8  f1D;
    u8  f1E;
    u8  f1F;
    u32 f20;
    void *f24;
};

struct Link {
    u8 pad00[0x65];
    u8 f65;
    u8 f66;
    u8 f67;
};

struct Cfg {
    u32 a;
    u32 b;
    u32 c;
};

struct Sel6 { u8 v[6]; };

struct Ofs6 { u16 v[6]; };

struct W {
    u16 scr[4];     /* +0x00 */
    struct Sel6 sel; /* +0x08 */
    u16 col[2];     /* +0x0E */
    struct Ofs6 ofs; /* +0x12 */
    u16 clk[10];    /* +0x1E */
};

extern void func_02030DA8(void *ctx, void (*fn)(void *, PalAnmObj *), PalAnmObj *p, s32 pri);
extern u32 func_02030EAC(struct Node *n);
extern void func_020862F0(void *a, u32 b);
extern void func_0207E3D0(void *a, u32 b, u32 c);
extern void func_0207E468(void *a, u32 b, u32 c);
extern void func_0207E51C(void *a, u32 b, u32 c);
extern void func_0207E5D0(void *a, u32 b, u32 c);
extern void func_0207F308(void);
extern void func_0207F394(void *a, u32 b, u32 c);
extern void func_0207F428(void);
extern void func_0207F47C(void);
extern void func_0207F4C4(void *a, u32 b, u32 c);
extern void func_0207F560(void);
extern void func_0207F5B0(void);
extern void func_0207F5C8(void *a, u32 b, u32 c);
extern void func_0207F65C(void);
extern void func_0207F6A8(void);
extern void func_0207F6C0(void *a, u32 b, u32 c);
extern void func_0207F754(void);
extern u32   CARD_GetBackupSectorSize(void);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020056A0(void *fn, void *arg, u32 prio);
extern u32 func_020307B0(void *p);
extern void MI_CpuFill8(void *dst, u8 data, u32 size);
extern s32_0202290C func_0209C0A4(s32_0202290C shifted, s32_0202290C c);
extern void  func_02082BCC(void *p, u32 v, u32 n);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern s32_1 FX_Sqrt(s32_1 x);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void *func_020071CC(struct WinPanel020071CCCtrl *ctrl, u32 id);
extern void *func_02012FE4(struct WinPanel020071CCCtrl *a0);
extern u32 func_020142E8(void *bitmap, s32_02023EF4 id);
extern u32 unit_020355C4(void);
extern void func_020355D8(void *);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201EFC8(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFFC(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void  *func_020457B0(u32 size, u16 heap);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern struct MsgBank *func_02045B38(int resident, int arcId, u32 fileId, u16 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D478(void *s);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0204581C(struct U16Vec *vec);
extern int func_0203568C(void);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02012BB0(const struct BigObj *p);
extern int   func_0203CD98(void);
extern void *func_0203D798(void);
extern int   func_0203D1B4(void);
extern u32 func_0203D29C(void);
extern u32 func_0201058C(void *key);
extern int   func_02026CA0(int *p);
extern int  func_0203FB44(u32 a, u32 b, u32 c);
extern int  func_02040E78(u32 a, const void *b, u16 c, u16 d);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32   func_0203FA08(u32 a, u32 b, u32 c);
extern void  func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void  func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void  ENV_SetResourceSet(void *a);
extern void  func_02041300(u32 a, u16 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_0203F4CC(struct RtcTime *time);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020409B4(u32 a0);
extern u8 func_02035630(void);
extern int  OS_IsRunOnTwl(void);
int func_02021728(char *p, int i);
int func_02021730(char *p, int i);
int func_0202173C(PalAnmObj *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
int func_02021848(PalAnmObj *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
u8 func_02021930(u32 val, int bit);
void func_02021944(PalAnmObj *p, int a1);
void func_02021984(s32 idx, PalAnmChan *c, u16 *pv);
void func_020219C4(PalAnmSlot *s, u16 f0, s32 a, u8 b, u8 c, u16 d);
void func_02021A84(void *a, PalAnmObj *p);
void func_02021B18(PalAnmObj *o);
void func_02021B2C(PalAnmObj *p);
void func_02021B4C(PalAnmObj *p);
void func_02021B6C(PalAnmObj *p, u32 idx, u32 arg);
void func_02021BC8(PalAnmObj *p, u32 idx, u32 arg);
void func_02021C20(u16 *src, u16 *dst, PalAnmSlot *c, u32 count);
void func_02021CA8(PalAnmObj *p, u32 idx, PalAnmSlot *s);
void func_02021D50(PalAnmObj *p);
u32 func_02021ED8(const PalAnmObj *ptr);
void func_02021EE4(PalAnmObj *o, int v);
void func_02021F08(PalAnmObj *o, int v);
u16 func_02021F3C(PalAnmChan *s, int idx, int which, u16 pos);
void func_02021F64(u16 *src, u16 *dst, u32 count, int weight, u16 color);
void func_02021FD8(PalAnmChan *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
void func_02022004(PalAnmChan *a0, u32 a1, u16 m, u8 a3, u16 a4);
void func_02022040(u16 *pal, int n, const u8 *table);
void func_0202208C(void *p1, u32 p2, u32 p3, u16 p4, u32 p5, u32 p6, u32 p7);
void func_02022174(void);
u32 func_020221A4(void);
void func_020221B8(void);
void func_02022224(void *win);
void func_02022230(u32 which);
void func_0202223C(u32 a, u32 color);
void func_02022268(u32 color);
void func_020222A8(u32 a);
void func_020222CC(u32 which, int brightness);
void func_020222EC(struct DualWin *p);
u32 func_02022340(struct DualWin *p, void *top, void *bottom);
void func_02022390(u32 *obj, void *arg);
u32 func_020223AC(void *p);
void func_020223C0(u32 mode, struct DualWin *p);
void func_02022430(struct WinPanel *s, u32 a, u32 b, s32 c, u32 d, u32 e, u32 f, void *g, void *h, u32 i, u16 j);
void func_02022458(struct Slots *p);
void func_02022478(void *task, struct Slots *p);
void func_02022490(struct Slots *p, void *ctx, Handler fn, u32 idx);
void func_020224DC(struct Slots *p, u32 idx);
void func_02022518(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
void func_02022568(u32 a0, u32 a1, u32 a2);
void func_020225B4(void *a0, u32 *a1);
void func_020225D4(struct Node *a0, u32 *a1);
void func_020225F0(void *ctx);
u16 func_020225F4(struct DualWin *obj, u16 value);
u16 func_02022608(struct DualWin *p);
void func_0202262C(void *obj, struct Q *q);
void func_02022640(struct WinPanel *s);
void func_02022670(struct WinPanel *s);
void func_020226A0(struct DualWin *p);
u32 func_020226E0(struct WinPanel *p);
u32 func_020226FC(struct WinPanel *p);
void func_0202271C(struct WinPanel *p);
void func_02022758(struct WinPanel *p);
void func_02022790(struct WinPanel *p);
void func_020227CC(struct WinPanel *p);
void func_02022804(struct WinPanel *p);
void func_02022830(struct WinPanel *p);
void func_0202285C(struct WinPanel *p);
void func_02022888(struct WinPanel *p);
void func_020228B4(struct WinPanel *p);
void func_020228E0(struct WinPanel *p);
s32_0202290C func_0202290C(s32_0202290C a, s32_0202290C b, s32_0202290C c);
void func_0202291C(struct Quad *dst, struct Quad *src);
void func_02022940(struct Quad *cur, struct Quad *end, struct Quad *step, const u8 *from, const u8 *to, s32_02022940 frames);
void func_020229A4(struct WinPanel *t, u32 dir);
u32 func_02022A44(struct WinPanel *t);
int func_02022A88(struct AnimStep *p);
void func_02022AC4(void *unused, u8 *o);
void func_02022AD0(struct ctl *ctl);
void func_02022CEC(u32 *a0, u32 a1, u32 a2, u32 a3);
void func_02022D70(void *a0);
void func_02022D78(u8 *p);
void *func_02022D88(struct Container_020225F0 *c, u32 idx);
void func_02022D98(void *p, struct Container_020225F0 *c);
void func_02022DCC(u32 a0, void *a1, u32 a2);
void func_02022E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);
void func_02022E88(struct Struct_02023CFC *table, u32 val, u32 idx, u32 mode);
void func_02022EA0(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4);
void *func_02022EF4(void *arg);
void func_02022F0C(u32 a0, u8 *a1, u32 a2);
void func_02022F24(u32 a0, u8 *a1, u32 a2);
void func_02022F34(void *p, struct WipeSubElem *elems);
void func_02022F60(struct S_02022E20 *p);
void func_02023464(struct WinPanel *t, u8 *cfg);
u32 func_020234C0(struct WinPanel *t);
void func_0202350C(struct WipeTiles *obj, const u8 *cfg, u32 a2, u32 a3, u32 a4, u32 a5);
u32 func_02023568(struct WipeTiles *o);
void func_020235F0(struct WinPanel *p, u32 a1);
u32 func_0202363C(struct Rec_020225F0 *r);
void func_0202368C(Ctx *ctx, const Par *par, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7, u32 s8);
u32 func_02023768(struct Wipe_02022E20 *w);
void func_020237B8(s32_1 a0, s32_1 a1, s32_1 a2, s32_1 a3, s32_1 *out0, s32_1 *out1);
void func_0202384C(struct Wipe_0202384C *w);
void func_020238B4(struct WinPanel *t, u32 a1);
u32 func_0202390C(struct WinPanel *t);
void func_02023964(struct WipeScan *w, struct Desc *d, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
u32 func_02023A50(struct WipeScan *w);
void func_02023AAC(void *obj);
void func_02023AB0(struct WipeScan *p);
void func_02023AF4(u8 *desc, u8 *out, s32 num, s32 den);
void func_02023B48(u32 val, u32 engine);
void func_02023B74(u32 a0, u32 a1, u32 a2, u32 a3);
void func_02023BFC(u32 a, u32 flag, u32 engine);
void func_02023C3C(u32 x2, u32 y2, u32 x1, u32 y1, int win, int sub);
void func_02023CFC(struct Struct_02023CFC *table, void *val, u32 idx);
void func_02023D18(void *obj, void *val, u32 f4, u32 f8, u32 fC);
void func_02023D40(void *obj, void *val, u32 f4, u32 f8);
void func_02023D60(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
u32 func_02023D94(void *obj, struct Args2 *args);
u32 func_02023DA8(void *obj, struct Args4 *args);
u32 func_02023DC4(void *obj, struct Args3 *args);
void func_02023DDC(void *a0, struct Rec_02023964 *a1);
void func_02023E0C(struct Interp *p);
void func_02023E9C(struct Interp *p, u16 steps, s16_02023E9C from, s16_02023E9C to, u32 a4, u32 a5);
void func_02023EF4(u16 steps, s16 from, s16 to, u32 plane, u32 mask);
void func_02023F60(u32 a0, u32 a1, u32 mask);
void func_02023F98(u32 mask);
void func_02023FD8(void);
int func_02024004(int a);
struct Obj_02023EF4 *func_02024044(u32 kind, u32 a1, void *src, u32 flag, void *sys, u32 hh);
void func_020240FC(void *t);
void func_02024104(u16 *p, u16 v);
void func_02024108(u16 *dst, const u16 *src);
int func_0202411C(unsigned char *p);
int func_02024120(u8 *p);
unsigned int func_02024124(unsigned short *p);
void func_02024128(struct Src02024128 *p, unsigned short *__restrict out);
void func_02024134(char *a, void *b);
u32 func_02024144(const u8 *p);
void *func_02024148(char *p);
void *func_0202414C(char *p);
int func_02024150(Bits_02024150 *p);
u32 func_02024158(const u8 *p);
int func_02024160(Bits_02024160 *p);
void func_02024168(const Input *p,u16 *a,u16 *b);
u32 func_0202419C(struct Obj_0202411C *p, u16 *q, u32 a);
void func_020241E0(struct T *p, u16 *a1, u16 *a2);
void func_0202421C(void);
void func_02024224(void *a,void *b);
void func_02024230(s16 *out, u32 count, u16 step, s32_02024230 amp);
void func_0202428C(void *obj);
void func_020242A4(void *obj, u32 id);
void func_020242C0(void *a, void *b, void *c);
void func_020242D8(void *slot, u32 idx);
void func_02024344(void *obj);
void *func_0202435C(void *slots, unsigned int heap);
void *func_02024368(u16 *slots, u32 heap, int count);
void *func_0202441C(const struct Struct_0202441C *obj, u32 heapId);
int func_02024450(const u16 *p);
int func_02024464(struct Rec4 *p, u16 a1);
u32 func_02024498(u32 a0, u32 a1, u16 a2);
u16 func_020244D4(void *obj, u32 idx);
u16 func_020244F0(void *obj, u32 idx);
u32 func_020244F8(struct Container_02023EF4 *p, u32 idx);
u32 func_02024508(u32 x);
u32 func_02024520(u32 x);
int func_0202452C(const u16 *p);
unsigned int func_02024530(const u16 *p);
int func_02024534(const struct Data *p1, const struct Data *p2);
void func_02024570(struct Rec8 *dst, const struct Rec8 *src);
u8 func_02024584(u32 i);
void func_02024598(void *p0, int p1, int p2);
void func_020245A0(u8 *p,unsigned i,u16 v);
void func_020245AC(struct Rec4 *p, u16 a1);
u32 func_020245D4(struct Rec4 *p, u32 a1);
u32 func_0202465C(struct Rec4 *p, u32 a1, u32 a2);
u32 func_020246C8(u16 *p, u32 mode, u32 flag);
u32 func_0202473C(u32 *p, u32 a);
s32_02024464 func_02024768(u32 v);
struct PmsWordSys *func_020247A8(u32 heapId);
void func_020247F0(struct PmsWordSys *p);
void func_02024810(struct PmsWordSys *p, u32 id, void *dest);
void func_02024838(u32 id, void *dest, u16 heap);
u16 func_02024888(u32 idx, u16 add);
int func_020248D8(u32 v, u32 *a1, u32 *a2);
void *func_02024910(char *p, int idx);
void func_02024918(struct Obj02024838 *p, s32_02024464 idx, const void *src);
u32 func_02024934(void);
void func_02024938(struct PmsWord *p);
void *func_02024988(struct WinPanel020071CCCtrl *ctrl);
int func_02024994(const u32 *p, u32 idx);
void func_020249A0(int *p, int bit);
int func_020249B0(u32 a, u16 b);
void func_02024A20(u8 a0, u8 a1, void *a2, u16 heap);
void func_02024ABC(void);
int func_02024DCC(void);
void func_02024DFC(void);
void func_02025154(u32 base, u32 blk, u8 x, u8 y, u8 w, u8 h);
int func_020251D8(int tile, const void *src, int count);
void func_020251FC(u32 a, u32 b, u32 c);
void func_020252A8(void);
extern struct DualWin g_021467A4;
extern FuncPtr g_0209F538[];
extern char  g_020A73C8[];
/* stand-in: three names for the two records at 0x021468FC; the literal pool holds the base three times (see func_02023F98), one name per word */
extern struct Interp g_wipe_main;
extern struct Interp g_wipe_subrec;
extern struct Interp g_wipe_flags[2];
extern const u32 d_0209F570[];
extern struct G_020225F0 g_020A73D0;
extern struct G_020225F0 g_wipe_slot0;
extern const u32 d_0209F56C[];
extern const u32 d_0209F574[];
extern const u32 d_0209F568[];
extern const char func_02023464_File[];
extern u8 file_020A745C[];
extern const s16 tbl_020A1B38[];
extern u16 Table_0209F724[];
extern u16 g_0209F724[];
extern u8 g_0209F71C[];
extern const struct Tbl data_0209F734;
extern const char str_020A746C[];
extern const u16  tbl_0209F7AC[];
extern u16 Table_0209F7AC[];
extern u16 g_tbl0[];
extern u16 g_tbl1[];
extern u16 g_0209F792[];
extern const u8 tbl_0209F784[][2];
extern const Group data_0209F7C8[13];
extern struct InfoWin *gInfoWin;
extern const char infowin_File[];
extern const u16 d_0209F834[];
extern const u32 d_0209F840[];
extern const u16 d_0209F848[];
extern const u16 d_0209F852[][2];
extern const u32 d_0209F838[];
extern const struct Ofs6 d_0209F870;
extern const struct Sel6 d_0209F868;
extern const u16 d_0209F830[];










int func_02021728(char *p, int i)
{
    return *(int *)(p + i * 0x14);
}










/*
 * Unlabelled Thumb leaf in the ARM9 module: word field of a 0x14-byte strided
 * array.
 *
 * Addresses are Black-image addresses.
 */
int func_02021730(char *p, int i)
{
    return *(int *)(p + i * 0x14 + 4);
}











/*
 * Palette-animation engine (palanm.c). For each of the fourteen channels
 * whose bit is set in `mask` and not yet
 * set in p->a_big: narrow the colour to the channel's
 * width (func_02021984, through the address of `col`, which is why all
 * four register parameters are pushed), initialise the channel's
 * animation sub-object at +0xC, mark the channel (func_02021944), run it
 * once (func_02021BC8, 0x10 for channels 0..3, 0x100 for 4..0xD) and
 * restore `col`. If any channel started, OR the mask into a_big and, when the tick
 * is not registered yet (b_x), set b_x, a_mode = 1, clear the latch and
 * register func_02021A84 with func_02030DA8 at priority -2. Returns 1 when
 * a channel started.
 *
 * Written fresh in wave 20 (lane palanm_fresh). The 33-byte residue of
 * earlier waves (the entry `str r3, [sp, #8]` sliding behind the stack
 * parameter copies) closes with the parameter types read from the callee:
 * `step` is narrow (s16 here; u16 and s8 give the same bytes), and b, c,
 * d are u8, u8, u16 both here and in the func_020219C4 prototype (its own
 * matched body). The narrow step's home store is then emitted at the
 * front of the prologue
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 * With u32 b, c, d in the prototype the same source is 236 bytes.
 * func_020219C4 is declared with six parameters: the caller passes six and
 * the callee's seventh (never read) is whatever sits at [sp, #8].
 */
int func_0202173C(PalAnmObj *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx)
{
    u16 keep = col;
    int ret = 0;
    u8 i;

    for (i = 0; i < 14; i++) {
        if (func_02021930(mask, i) == 1 && func_02021930(p->a_big, i) == 0) {
            func_02021984(i, &p->ch[i], &col);
            func_020219C4(&p->ch[i].slot, col, step, b, c, d);
            func_02021944(p, i);
            if (i >= 4) {
                func_02021BC8(p, i, 0x100);
            } else {
                func_02021BC8(p, i, 0x10);
            }
            col = keep;
            ret = 1;
        }
    }
    if (ret == 1) {
        p->a_big |= mask;
        if (p->b_x == 0) {
            p->b_x = 1;
            p->a_mode = 1;
            p->latch = 0;
            func_02030DA8(ctx, (void (*)(void *, PalAnmObj *))func_02021A84, p, -2);
        }
    }
    return ret;
}











/*
 * Palette-animation engine (palanm.c). For each of the fourteen channels
 * whose bit is set in `mask`: narrow the colour to the channel's
 * width (func_02021984, through the address of `col`, which is why all
 * four register parameters are pushed), initialise the channel's
 * animation sub-object at +0xC, mark the channel (func_02021944), run it
 * once (func_02021BC8, 0x10 for channels 0..3, 0x100 for 4..0xD) and
 * restore `col`. If any channel started, store the mask to a_big and, when the tick
 * is not registered yet (b_x), set b_x, a_mode = 1, clear the latch and
 * register func_02021A84 with func_02030DA8 at priority -2. Returns 1 when
 * a channel started.
 *
 * Written fresh in wave 20 (lane palanm_fresh). The 33-byte residue of
 * earlier waves (the entry `str r3, [sp, #8]` sliding behind the stack
 * parameter copies) closes with the parameter types read from the callee:
 * `step` is narrow (s16 here; u16 and s8 give the same bytes), and b, c,
 * d are u8, u8, u16 both here and in the func_020219C4 prototype (its own
 * matched body). The narrow step's home store is then emitted at the
 * front of the prologue
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 * With u32 b, c, d in the prototype the same source is 236 bytes.
 * func_020219C4 is declared with six parameters: the caller passes six and
 * the callee's seventh (never read) is whatever sits at [sp, #8].
 */
int func_02021848(PalAnmObj *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx)
{
    u16 keep = col;
    int ret = 0;
    u8 i;

    for (i = 0; i < 14; i++) {
        if (func_02021930(mask, i) == 1) {
            func_02021984(i, &p->ch[i], &col);
            func_020219C4(&p->ch[i].slot, col, step, b, c, d);
            func_02021944(p, i);
            if (i >= 4) {
                func_02021BC8(p, i, 0x100);
            } else {
                func_02021BC8(p, i, 0x10);
            }
            col = keep;
            ret = 1;
        }
    }
    if (ret == 1) {
        p->a_big = mask;
        if (p->b_x == 0) {
            p->b_x = 1;
            p->a_mode = 1;
            p->latch = 0;
            func_02030DA8(ctx, (void (*)(void *, PalAnmObj *))func_02021A84, p, -2);
        }
    }
    return ret;
}











u8 func_02021930(u32 val, int bit)
{
    u8 ret;

    if (val & (1 << bit)) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}











void func_02021944(PalAnmObj *p, int a1)
{
    if (func_02021930(p->b_lo, a1) == 1)
        return;
    p->b_lo |= 1 << a1;
}







/*
 * Narrows *pv to the channel's own bit width. The width is an 8-bit field of
 * the channel record's word at +8: bits[5:13) for channels 0..3 and
 * bits[9:17) for 4..0xD. The mask is not built with a shift -- the original
 * really does accumulate `1 << n` in a u16 loop, so the source has to be
 * written as the loop, not as `(1 << w) - 1`.
 *
 * Three spellings are load-bearing. The `(u8)` narrowing of the width is
 * applied AFTER the if/else, not inside each arm, so both arms share the
 * `lsrs r4, r0, #0x18` (the shared-exit idiom). `w` is u32, not u8, or the
 * narrowing costs a second shift pair. And the do-while guard must be
 * spelled `if (n < w)` against the already-zeroed counter, not `if (w != 0)`
 * or `if (0 < w)`: only that form emits the original's `bls`, the others
 * emit `beq` -- a single byte, and the last one left in this function.
 *
 * EXACT* only: 62 bytes compiled, listing extent 64; the extra halfword at
 * 0x020219C2 is alignment padding, not an unlabelled follower.
 */
void func_02021984(s32 idx, PalAnmChan *c, u16 *pv)
{
    u32 t;
    u16 m;
    u8 n;
    u32 w;

    if (idx < 4) {
        t = c->f8 << 0x13;
    } else {
        t = c->f8 >> 9 << 0x18;
    }
    w = t >> 0x18;

    m = 0;
    n = 0;
    if (n < w) {
        do {
            m = (u16)(m + (u16)(1 << n));
            n++;
        } while (n < w);
    }

    *pv = *pv & m;
}







/*
 * Seven-argument initialiser for one 8-byte animation slot (the `+0xc`
 * sub-object of the 0x14-byte per-channel record; both callers, 0x0202173E
 * and 0x0202184A, pass `p + idx*0x14 + 0xc`). Arguments 5..7 arrive on the
 * caller's stack (visible as `add r5,sp,#0x10` with a bare `push {r4-r7}`
 * and no frame). Argument 7 is never read.
 *
 * Halfword layout of the slot:
 *   +0x00  u16 f0            (= arg2, stored whole)
 *   +0x02  lo:6, mid:5, hi:5
 *   +0x04  val:15, flag:1
 *   +0x06  step:5, copy:6, pad:5
 *
 * The narrow parameter types are load-bearing, not cosmetic. Args 5 and 6
 * are read with `ldrb [r5]` / `ldrh [r5,#4]` off the stack-arg area, which
 * only happens when they are declared u8 / u16; and arg 4 must be u8 (not
 * u32 or u16), or the 5-bit bitfield store costs an extra u16-truncation
 * shift pair -- 8 bytes over 192, and the whole tail shifts with it.
 */
void func_020219C4(PalAnmSlot *s, u16 f0, s32 a, u8 b, u8 c, u16 d)
{
    u8 n;

    if (a < 0) {
        n = (u8)((a < 0 ? -a : a) + 2);
        if (n > 0x10) {
            n = 0x10;
        }
        s->step = n;
        s->lo = 0;
    } else {
        s->step = 2;
        s->lo = (u16)a;
    }

    s->f0 = f0;
    s->cur = b;
    s->max = c;
    s->target = d;
    s->copy = s->lo;

    if (b < c) {
        s->sign = 0;
    } else {
        s->sign = 1;
    }
}







/*
 * Per-frame tick on the slot header at p+0x118. Two halfword bitfields sit
 * there, each `lo:14, hi:2` (the +0x11A one is the field func_02021944
 * sets bits in), followed by a u8 latch at p+0x11C.
 *
 * If the latch is set, the tick is a teardown: clear the latch, clear both
 * lo fields and bit 14 of the +0x11A one, and call out through 0x02030EAC.
 * Otherwise, when the low two bits of the +0x118 field read 1 (the "running"
 * mode), copy that field's 14 bits over the +0x11A field, step all fourteen
 * channels (func_02021B2C for 0..3, func_02021B4C for 4..0xD), and when the
 * +0x118 field has drained to zero, clear bit 14 of +0x11A and call out.
 *
 * EXACT* only: the compiled function is 148 bytes and correct throughout;
 * the listing's 168-byte extent runs on past the literal pool at 0x02021B10
 * into an unlabelled leaf at 0x02021B18 (`movs r0,#0x46; lsls r0,#2;
 * ldrh r2,[r0,r5]; ... strb r2,[r0,r1]; bx lr` -- a no-lr-saving accessor,
 * so disasm.py never labelled it). Worth seeding into
 * layout/function_starts.txt; reported rather than edited here.
 */
void func_02021A84(void *a, PalAnmObj *p)
{
    if (p->latch == 1) {
        p->latch = 0;
        p->b_lo = 0;
        p->a_big = 0;
        p->b_x = 0;
        func_02030EAC(a);
        return;
    }

    if (p->a_mode != 1) {
        return;
    }

    p->b_lo = p->a_big;
    func_02021B2C(p);
    func_02021B4C(p);
    if (p->a_big == 0) {
        p->b_x = 0;
        func_02030EAC(a);
    }
}







/*
 * An unlabelled leaf (saves no lr, see docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  Reads the 14-bit field
 * above the low two bits of the halfword at +0x118 and, when it is
 * non-zero, sets the byte at +0x11c to 1.
 *
 * The `lsls #0x10 / lsrs #0x12` pair is the unequal-shift narrowing form
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md):
 * a u16 truncation folded with a >> 2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021B18.c \
 *       --func func_02021B18 --addr 0x02021B18 --cc 1.1p1 --thumb
 */
void func_02021B18(PalAnmObj *o)
{
    if (o->a_big)
        o->latch = 1;
}







void func_02021B2C(PalAnmObj *p)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        func_02021B6C(p, i, 0x10);
    }
}








void func_02021B4C(PalAnmObj *p)
{
    u8 i;

    for (i = 4; i < 0xE; i++) {
        func_02021B6C(p, i, 0x100);
    }
}








void func_02021B6C(PalAnmObj *p, u32 idx, u32 arg)
{

    if (func_02021930(p->a_big, idx) == 0) {
        return;
    }

    {
        PalAnmChan *s = &p->ch[idx];

        if (s->slot.copy < s->slot.lo) {
            s->slot.copy = s->slot.copy + 1;
        } else {
            s->slot.copy = 0;
            func_02021BC8(p, idx, arg);
        }
    }
}








void func_02021BC8(PalAnmObj *p, u32 idx, u32 arg)
{
    u32 i;
    PalAnmChan *s = &p->ch[idx];

    for (i = 0; i < 0x10; i++) {
        if (func_02021930(s->slot.f0, (u16)i)) {
            u32 off = (i * arg) * 2;
            func_02021C20((u16 *)((u8 *)s->src + off),
                          (u16 *)((u8 *)s->dst + off),
                          &s->slot,
                          arg);
        }
    }

    func_02021CA8(p, (u8)idx, &s->slot);
}








/*
 * palanm.c: the per-pixel RGB555 blend loop.  Each channel of src[i] moves
 * weight/16 of the way toward the matching channel of the anim sub-object's
 * 15-bit target colour; the result is written to dst[i].
 *
 * Closed in wave 13 by the shape func_0202EA40 (blink_palanm.c) proved the
 * same day: the source pixel and the target are u16 LOCALS (an `int` pixel
 * is 20 bytes out), the channel extractions are written inline in each
 * blend rather than bound to sb/sg/sr locals, and the pack is
 * `r | ((b << 10) | (g << 5))` -- the channel ORed last is the one the
 * compiler evaluates first, which is the image's red, blue, green order.
 * The earlier 69-byte reading (int px, t/w/sb/sg/sr locals) is in
 * docs/notes/func_02021C20.c.txt.
 */
void func_02021C20(u16 *src, u16 *dst, PalAnmSlot *c, u32 count)
{
    u32 i;
    u16 a;
    u16 t;
    s32 r;
    s32 g;
    s32 b;

    for (i = 0; i < count; i++) {
        a = src[i];
        t = c->target;
        r = (u8)((a & 0x1f) + ((((t & 0x1f) - (a & 0x1f)) * c->cur) >> 4));
        b = (u8)(((a >> 10) & 0x1f) + (((((t >> 10) & 0x1f) - ((a >> 10) & 0x1f)) * c->cur) >> 4));
        g = (u8)(((a >> 5) & 0x1f) + (((((t >> 5) & 0x1f) - ((a >> 5) & 0x1f)) * c->cur) >> 4));
        dst[i] = (u16)(r | ((b << 10) | (g << 5)));
    }
}







/*
 * Steps or clears one slider on the record at `s`. The halfword at s+2 is
 * three fields: lo6:6, cur:5, max:5. When cur has already reached max, the
 * function instead toggles bit `idx` of the 14-bit flag field at p[0x118]
 * bits[2:16) (pool word 0xFFFF0003 preserves the low two bits) and returns,
 * doing nothing at all if that bit was already clear. Otherwise the sign bit
 * of the halfword at s+4 picks the direction and s->step (5 bits at s+6) the
 * amount: cur moves up and is clamped down to max, or down and clamped up to
 * max, and is written back through pool word 0xFFFFF83F.
 *
 * Three things the earlier note (docs/notes/func_02021CA8.c.txt) left open,
 * all settled here:
 *   - the write target in blocks 2a/2b really is `cur` (bits[6:11)), which
 *     is what 0xFFFFF83F clears; the note's own "re-check before trusting
 *     this paragraph" was right to doubt the bits[11:16) reading.
 *   - blocks 2a and 2b each carry their own copy of the read-mask-or-store
 *     writeback. Factoring it out after the if/else costs a register and the
 *     `pop {r4,r5}` grows to `pop {r3,r4,r5,r6}`.
 *   - the value sign-extended at the top of each arm is `(s16)s->cur`, the
 *     already-extracted 5-bit field, NOT a fresh s16 read of the raw
 *     halfword at s+2. Both spell `lsls #0x10; asrs #0x10`, but reading the
 *     raw halfword keeps it live in a fifth register across the whole
 *     function and was the last 105 bytes of the diff; using the field
 *     lets the compiler re-derive it and closes the function outright.
 * The p[0x118] flag field is the same bits[2:16) register func_02021B6C
 * uses, as the note suspected.
 */
void func_02021CA8(PalAnmObj *p, u32 idx, PalAnmSlot *s)
{
    u32 bit;
    s32 v;

    if (s->cur == s->max) {
        bit = 1 << idx;
        if (p->a_big & bit) {
            p->a_big ^= bit;
        }
        return;
    }

    if (!s->sign) {
        v = (s16)((s16)s->cur + (s32)s->step);
        if (v > (s32)s->max) {
            v = (s16)s->max;
        }
        s->cur = v;
    } else {
        v = (s16)((s16)s->cur - (s32)s->step);
        if (v < (s32)s->max) {
            v = (s16)s->max;
        }
        s->cur = v;
    }
}







/*
 * The apply pass of the slot object: walks the 14 channel records and pushes
 * each one's current value out through the graphics-engine setter that the
 * channel index selects (a dense 14-entry halfword switch table at
 * 0x02021DBA). Runs only when the +0x11A field's top bit is set or the
 * +0x118 field's mode is 1.
 *
 * Two types are load-bearing. `i` must be u32 for the switch's own range
 * guard to come out `cmp #0xd; bhi` (signed makes it a `bgt`/`bhi` pair),
 * but the loop's own bound must be compared signed -- `(int)i < 14` -- or
 * the back edge is `bhs` where the original has `bge`. And the bit index
 * handed to func_02021930 is truncated, `(u16)i`, which is the
 * `lsls #0x10 / lsrs #0x10` pair at +0x3E.
 *
 * The final `if` re-reads p->b_lo out of memory rather than reusing the
 * value just stored; testing p->a_big instead loses the reload.
 *
 * EXACT* only: 392 bytes compiled and correct throughout. The listing's
 * 532-byte extent runs past the literal pool at 0x02021ED0 into a run of
 * unlabelled leaf accessors starting at 0x02021EE4 (none saves lr, so
 * disasm.py never labelled them; the first is
 * `movs r1,#0x46; lsls r1,#2; ldrh r0,[r0,r1]; lsls #0x10; lsrs #0xc;
 * bx lr`). Worth seeding into layout/function_starts.txt; reported rather
 * than edited here.
 */
void func_02021D50(PalAnmObj *p)
{
    PalAnmChan *c;
    u32 k;
    u32 i;

    if (p->b_hi == 0 && p->a_mode != 1) {
        return;
    }

    k = 0x2000;
    for (i = 0; (int)i < 14; i++) {
        if (p->b_hi == 0) {
            if (p->ch[i].dst == 0) {
                continue;
            }
            if (func_02021930(p->b_lo, (u16)i) == 0) {
                continue;
            }
        }
        c = &p->ch[i];
        func_020862F0(c->dst, c->f8);
        switch (i) {
        case 0:
            func_0207E3D0(c->dst, 0, c->f8);
            break;
        case 1:
            func_0207E468(c->dst, 0, c->f8);
            break;
        case 2:
            func_0207E51C(c->dst, 0, c->f8);
            break;
        case 3:
            func_0207E5D0(c->dst, 0, c->f8);
            break;
        case 4:
            func_0207F308();
            func_0207F394(c->dst, 0, c->f8);
            func_0207F428();
            break;
        case 5:
            func_0207F308();
            func_0207F394(c->dst, k, c->f8);
            func_0207F428();
            break;
        case 6:
            func_0207F308();
            func_0207F394(c->dst, 0x4000, c->f8);
            func_0207F428();
            break;
        case 7:
            func_0207F308();
            func_0207F394(c->dst, 0x6000, c->f8);
            func_0207F428();
            break;
        case 8:
            func_0207F5B0();
            func_0207F5C8(c->dst, 0, c->f8);
            func_0207F65C();
            break;
        case 9:
            func_0207F5B0();
            func_0207F5C8(c->dst, k, c->f8);
            func_0207F65C();
            break;
        case 10:
            func_0207F5B0();
            func_0207F5C8(c->dst, 0x4000, c->f8);
            func_0207F65C();
            break;
        case 11:
            func_0207F5B0();
            func_0207F5C8(c->dst, 0x6000, c->f8);
            func_0207F65C();
            break;
        case 12:
            func_0207F47C();
            func_0207F4C4(c->dst, 0, c->f8);
            func_0207F560();
            break;
        case 13:
            func_0207F6A8();
            func_0207F6C0(c->dst, 0, c->f8);
            func_0207F754();
            break;
        }
    }

    p->b_lo = p->a_big;
    if (p->b_lo == 0) {
        p->a_mode = 0;
    }
}








u32 func_02021ED8(const PalAnmObj *ptr)
{
    return ptr->a_big;
}








/*
 * EXACT*: the inferred extent ran to 0x02021F64 because the next function,
 * at 0x02021F08, saves no lr and so carries no label.  0x02021F08 is an
 * unlabelled follower and wants seeding into layout/function_starts.txt.
 *
 * An unlabelled leaf setter (saves no lr).  Writes the top bit of the
 * halfword at +0x11a from the low bit of the argument.  The pool words are
 * plain literals: 0x0000011A (the offset, past the Thumb ldrh immediate
 * reach of +62, see docs/idioms/thumb-immediate-reach-costs-an-adds.md) and
 * 0xFFFF7FFF (the clear mask), neither a relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021EE4.c \
 *       --func func_02021EE4 --addr 0x02021EE4 --cc 1.1p1 --thumb
 */
void func_02021EE4(PalAnmObj *o, int v)
{
    o->b_hi = (u16)v;
}







/*
 * An unlabelled leaf (push {r3, r4} for alignment only, no lr save), newly
 * seeded as the follower of func_02021EE4.  Arms the palette-animation
 * header at +0x118: sets the 2-bit mode field from the low bit of the
 * argument and then turns on all fourteen channel bits above it.
 *
 * The header halfword is the same `a_mode:2, a_big:14` pair func_02021A84
 * and func_02021D50 use.  The two pool words are plain literals, not
 * relocations: 0xFFFF0003 is the a_big clear mask and 0x0000FFFC the
 * all-ones a_big value written back, exactly the `<< 2` bitfield insert.
 *
 * EXACT*: 52 bytes compiled (44 of code plus the two pool words at
 * 0x02021F34/0x02021F38), against a 92-byte inferred extent that runs on
 * into the unlabelled `.word` run before func_02021F64.
 *
 * The `(v & 1)` is narrowed to u16 before the field store (`lsls #0x10 /
 * lsrs #0x10` at +0x10), which is what an `int` argument masked into a
 * 2-bit u16 bitfield produces; a u16 parameter loses the pair.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021F08.c \
 *       --func func_02021F08 --addr 0x02021F08 --cc 1.1p1 --thumb
 */
void func_02021F08(PalAnmObj *o, int v)
{
    o->a_mode = (u16)(v & 1);
    o->a_big = 0x3FFF;
}







/*
 * Witness leaf for ov071 func_021B6C7C (tiny unlabelled arm9 leaf).
 */
u16 func_02021F3C(PalAnmChan *s, int idx, int which, u16 pos)
{
    if (which == 1) {
        return s[idx].src[pos];
    }
    if (which == 0) {
        return s[idx].dst[pos];
    }
    return 0;
}







/*
 * A per-pixel RGB555 alpha-blend loop, same family as func_02021C20 and
 * func_02021BC8: each channel of src[i] is pulled toward the corresponding
 * channel of `color` by `weight`/16 and the three results repacked into
 * dst[i].  `color` is the fifth argument and arrives on the caller's stack
 * (the entry `add r0,sp,#0x20; ldrh r0,[r0]`).
 *
 * No relocations: the function calls nothing and reads no globals.
 *
 * EXACT*, not EXACT: the next function has no label, so the inferred extent
 * runs two bytes long (116 vs the 114 compiled, the difference being the
 * alignment halfword at 0x02021FD6).
 *
 * Two levers, both recorded in docs/notes/func_02021F64.c.txt:
 *   - the per-pixel channels must be read through a bitfield pointer into
 *     src[i] itself, ((struct Rgb555 *)&src[i])->r, not through a value-copy
 *     union: the copy spills the pixel to a stack slot the image never uses.
 *   - `weight` is a SIGNED int.  As u32 the products (t - s) * weight become
 *     unsigned and the three `>> 4` compile to `lsrs`; the image has `asrs`
 *     at +0x3E, +0x4A and +0x54.  That signedness was the whole residue.
 */
void func_02021F64(u16 *src, u16 *dst, u32 count, int weight,
                   u16 color)
{
    u16 i;
    int tr = ((struct Rgb555 *)&color)->r;
    int tg = ((struct Rgb555 *)&color)->g;
    int tb = ((struct Rgb555 *)&color)->b;

    for (i = 0; i < count; i++) {
        int sr = ((struct Rgb555 *)&src[i])->r;
        int sg = ((struct Rgb555 *)&src[i])->g;
        int sb = ((struct Rgb555 *)&src[i])->b;
        int rb = sb + ((tb - sb) * weight >> 4);
        int rr = sr + ((tr - sr) * weight >> 4);
        int rg = sg + ((tg - sg) * weight >> 4);

        dst[i] = (u16)(rr | (rg << 5) | (rb << 10));
    }
}






/*
 * Thin forwarding wrapper: picks channel `idx` out of the 0x14-byte record
 * array, advances both of its pointers by `c` halfwords, and hands them to
 * the RGB555 blend loop at 0x02021F64 (see docs/notes/func_02021F64.c.txt --
 * that function is still a documented DIFF, so this wrapper's own
 * relocation is attested by the `label` class, not by a matched entry).
 * Arguments 5 and 6 arrive on the caller's stack and must be u8 / u16, which
 * is what makes them `ldrb [r5]` and `ldrh [r5, #4]`.
 *
 * EXACT* only: 42 bytes compiled, the listing extent is 44 -- the two extra
 * bytes are the `00 00` alignment halfword at 0x02022002, not a follower.
 */
void func_02021FD8(PalAnmChan *p, u32 idx, u32 c, u32 count,
                   u8 weight, u16 color)
{
    func_02021F64(p[idx].src + c, p[idx].dst + c, count, weight, color);
}






void func_02022004(PalAnmChan *a0, u32 a1, u16 m, u8 a3, u16 a4)
{
    u32 i = 0;

    if (m == 0) {
        return;
    }
    do {
        if (m & 1) {
            func_02021FD8(a0, a1, (u16)i, 0x10, a3, a4);
        }
        m = (u16)(m >> 1);
        i += 0x10;
    } while (m != 0);
}






void func_02022040(u16 *pal, int n, const u8 *table)
{
    int i;
    int r, g, b;
    u8 v;

    for (i = 0; i < n; i++) {
        r = *pal & 0x1f;
        g = (*pal >> 5) & 0x1f;
        b = (*pal >> 10) & 0x1f;
        v = table[(r * 76 + g * 151 + b * 29) >> 8];
        *pal = (v << 10) | (v << 5) | v;
        pal++;
    }
}






/*
 * The setup entry point of the dual-screen window/text cluster whose object
 * lives at 0x021467A4, the same fixed object func_020226A0 zero-fills in five
 * sub-ranges (0x00/0x14, 0x14/0x30, 0x44/0x30, 0x74/0x18, 0x8C/0xC0) and the
 * one func_0202223C/func_02022268 read the sentinel colour out of at +0x150.
 * It divides its sixth argument by CARD_GetBackupSectorSize(), clears the
 * object, runs two configuration calls, then builds the two screens with the
 * same eleven-argument builder func_02022430: sub-object +0x14 with the
 * second argument and mode 0, sub-object +0x44 with the third argument and
 * mode 1, both sharing the buffers at +0x8C and +0x74 and the object the
 * fifth call returned.  It then publishes the two sub-objects through the
 * slots at +0x04 and +0x08, and for each of the two delegate pointers at
 * +0x0C and +0x10 that is non-null it runs func_02022640 on the matching
 * sub-object and sets the byte flag at +0x14E / +0x14F.
 *
 * Graduated in wave 20B.  It was parked at MATCH only because five of its
 * callees had no branch reference anywhere in the image except the ones in
 * this function, so the `label` class had no witness outside the compared
 * range.  All five are now EXACT manifest entries in pkt_02022174
 * (func_020223C0, func_02022458, func_020225F4, func_02022430,
 * func_02022640), and every one of those sites resolves on the `matched`
 * class.  g_021467A4 resolves on `literal`, CARD_GetBackupSectorSize,
 * _s32_div_f, func_020226A0 and func_02022390 on `label`.
 *
 * Near miss worth keeping: the division had to be written as a self-recompute,
 *   n = (s32)p6;  n = n / (s32)CARD_GetBackupSectorSize();
 * The single-expression form `(s32)p6 / (s32)CARD_GetBackupSectorSize()`
 * compiles the call first and then rematerialises p6 out of its incoming
 * stack slot into r0, two bytes shorter and a whole-function shift; the
 * original loads p6 into a callee-saved register in the prologue shuffle and
 * only then calls.  See
 * docs/idioms/a-self-recompute-pins-an-operand-before-the-other-side-calls.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202208C.c  *       --func func_0202208C --addr 0x0202208C --cc 1.1p1 --thumb
 */
void func_0202208C(void *p1, u32 p2, u32 p3, u16 p4, u32 p5, u32 p6, u32 p7)
{
    s32    n;
    struct DualWin *g;
    u16    obj;

    n = (s32)p6;
    n = n / (s32)CARD_GetBackupSectorSize();
    g = &g_021467A4;
    func_020226A0(g);
    func_020223C0((u32)p1, g);
    func_02022458(&g->f74);
    obj = func_020225F4(g, p4);
    func_02022430(&g->f14, p2, p5, n, 0, 0, 0,
                  g->f8C, &g->f74, p7, obj);
    func_02022430(&g->f44, p3, p5, n, 0, 0, 1,
                  g->f8C, &g->f74, p7, obj);
    g->f14C = 1;
    func_02022390(&g->top, &g->f14);
    func_02022390(&g->bottom, &g->f44);
    if (g->f0C != 0) {
        func_02022640(&g->f14);
        g->f14E = 1;
    }
    if (g->f10 != 0) {
        func_02022640(&g->f44);
        g->f14F = 1;
    }
}






/*
 * Per-frame poll for the dual-screen text cluster at 0x021467A4: while the
 * cluster is live (the u16 at +0x14C non-zero) it steps both sub-objects and,
 * when the stepper reports 1, runs the completion handler on the cluster.
 *
 * The +0x14C read costs its own pool word because 0x14C is far past the
 * ldrh immediate reach; it is g_021467A4 + 0x140 with a +0xC displacement,
 * one symbol and not a second object, see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * The follower at 0x020221A4 is a separate leaf function with fan-in 111 and
 * is deliberately NOT folded into a unit here; it keeps its own entry, see
 * docs/idioms/a-unit-attests-only-its-own-start-address.md.  EXACT* is the
 * inferred extent running into that follower, not a byte difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022174.c \
 *       --func func_02022174 --addr 0x02022174 --cc 1.1p1 --thumb
 */
void func_02022174(void)
{
    struct DualWin *g;

    g = &g_021467A4;
    if (g_021467A4.f14C != 0) {
        if (func_02022340(g, &g->f14, &g->f44) == 1)
            func_020222EC(g);
    }
}






/*
 * "Is the dual-screen text cluster idle?", the image's most-called predicate
 * on this object (fan-in 111, mostly from overlay script code): it reports 1
 * when the live counter at +0x14C is zero.  It is a leaf that saves no lr, so
 * disasm.py never labels it and it prints as an anonymous run between two
 * literal pools; see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * It deliberately does not share a file with func_02022174 above it: a unit
 * records only its start address, and this address has 111 call sites that
 * need a manifest entry here.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020221A4.c \
 *       --func func_020221A4 --addr 0x020221A4 --cc 1.1p1 --thumb
 */
u32 func_020221A4(void)
{
    if (g_021467A4.f14C == 0)
        return 1;
    return 0;
}






/*
 * Shutdown of the dual-screen text cluster, the counterpart of func_0202208C.
 * It drops both entries of the callback block at +0x74, forces each live screen
 * into state 2, unpublishes both sub-objects through the same func_02022390
 * slot writer the setup used, clears the live counter and the two delegate
 * flags at +0x14C/+0x14E/+0x14F, and releases the object.
 *
 * Every pool word here is g_021467A4 with a different displacement (+0x74,
 * +0x00, +0x04, +0x14, +0x08, +0x44, +0x140), one symbol and not seven
 * objects; see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020221B8.c \
 *       --func func_020221B8 --addr 0x020221B8 --cc 1.1p1 --thumb
 */
void func_020221B8(void)
{
    func_020224DC(&g_021467A4.f74, 0);
    func_020224DC(&g_021467A4.f74, 1);
    if (g_021467A4.top != 0)
        g_021467A4.f14.phase = 2;
    if (g_021467A4.bottom != 0)
        g_021467A4.f44.phase = 2;
    func_02022390(&g_021467A4.top, &g_021467A4.f14);
    func_02022390(&g_021467A4.bottom, &g_021467A4.f44);
    g_021467A4.f14C = 0;
    g_021467A4.f14E = 0;
    g_021467A4.f14F = 0;
    func_020226A0(&g_021467A4);
}






/*
 * A two-instruction forwarder (fan-in 22) that pins the first argument of
 * func_02023B48 to zero and passes the caller's window pointer through as the
 * second.  Tail calls in this compiler are always a pool word and a `bx`,
 * never a displacement branch, because every function gets its own section;
 * see docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * EXACT* is the extent walk running into the second forwarder at 0x02022230,
 * which is an unlabelled leaf with its own callers and keeps its own file.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022224.c \
 *       --func func_02022224 --addr 0x02022224 --cc 1.1p1 --thumb
 */
void func_02022224(void *win)
{
    func_02023B48(0, (u32)win);
}






/*
 * The companion forwarder to func_02022224: it passes the caller's engine
 * selector straight through to func_020222CC and supplies the unused second
 * argument as zero.  Same pool-word-and-`bx` tail call shape.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022230.c \
 *       --func func_02022230 --addr 0x02022230 --cc 1.1p1 --thumb
 */
void func_02022230(u32 which)
{
    func_020222CC(which, 0);
}






/*
 * Maps two sentinel colour values (0xFFFF, "read back the last value
 * written"; 0x7FFF, "white") to two hardware-register-friendly constants
 * and forwards to func_020222CC, which selects one of two hardware
 * addresses from its first argument and ignores the colour entirely
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-
 * leftovers.md; func_020222CC's own file spells this out).
 *
 * The sentinel readback is `g_021467A4.f150`, a halfword sixteen bytes into
 * a fixed object.  Writing it as `*(u16 *)(0x021468E4 + 0x10)` folds the
 * base and the offset into a single pool word (a plain integer constant
 * has no reason not to), which does not reproduce the original's separate
 * `ldr r1, [pc]; ldrh r1, [r1, #0x10]`.  Declaring the object as an extern
 * struct and taking a real relocation on its base keeps the offset in the
 * instruction encoding instead, matching
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-
 * the-load-reach.md.  The base address is attested by ten other literal
 * pools in the image.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202223C.c \
 *       --func func_0202223C --addr 0x0202223C --cc 1.1p1 --thumb
 */
void func_0202223C(u32 a, u32 color)
{
    if (color == 0xFFFF) {
        color = g_021467A4.f150;
    }
    if (color == 0x7FFF) {
        color = 0x10;
    } else {
        color = ~(u32)0xF;
    }
    func_020222CC(a, color);
}






/*
 * Same sentinel-mapping shape as func_0202223C.c, but read-modify-write:
 * it substitutes the sentinel readback the same way, maps the result to
 * one of the same two hardware constants, forwards it to both of
 * func_020222CC's hardware selections (0 and 1), and then stores the
 * *pre-mapping* colour back into the same halfword field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022268.c \
 *       --func func_02022268 --addr 0x02022268 --cc 1.1p1 --thumb
 */
void func_02022268(u32 color)
{
    u32 mapped;

    if (color == 0xFFFF) {
        color = g_021467A4.f150;
    }
    if (color == 0x7FFF) {
        mapped = 0x10;
    } else {
        mapped = ~(u32)0xF;
    }
    func_020222CC(0, mapped);
    func_020222CC(1, mapped);
    g_021467A4.f150 = color;
}






void func_020222A8(u32 a)
{
    u32 *p = &a;

    func_0207E3D0(p, 0, 2);
    func_0207E468(p, 0, 2);
}






/*
 * Selects one of two hardware register addresses (0x0400006C, 0x0400106C:
 * the master brightness registers of the two DS display engines) from its
 * first argument and passes it to func_0207D534 together with the second
 * argument, the brightness level, which stays in r1 untouched (an argument
 * passed through a register must be named in the C).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020222CC.c \
 *       --func func_020222CC --addr 0x020222CC --cc 1.1p1 --thumb
 */
void func_020222CC(u32 which, int brightness)
{
    if (which == 0) {
        func_0207D534((volatile u16 *)0x0400006C, brightness);
    } else {
        func_0207D534((volatile u16 *)0x0400106C, brightness);
    }
}







/*
 * Teardown for the dual-screen text cluster, run by func_02022174 once both
 * screen slots have gone null.  It clears the live flag at +0x14C, latches the
 * value func_02022608 returns into the sentinel colour slot at +0x150, and for
 * each of the two delegates at +0x0C and +0x10 runs the per-screen finaliser
 * func_02022670 on the matching sub-object.
 *
 * Two notes on the original's shape.  Both delegate arms retest the *same*
 * field, +0x3C, which is the top sub-object's task handle at 0x14 + 0x28; the
 * bottom arm does not use its own +0x6C.  That is the image's behaviour, not a
 * transcription slip, and it is reproduced literally.  Both flag writes also go
 * through the global rather than the incoming pointer, which the encoding
 * distinguishes: the pointer form would reuse r5, the global form spends a
 * pool word at 0x0202233C.
 *
 * 0x14C and 0x150 are both past the strh immediate reach, so the first is
 * materialised as 0x53 << 2 into a register offset and the second derived from
 * it with a single `adds r1, r4, #4`; see
 * docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md for the
 * same derivation on line-number arguments.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020222EC.c \
 *       --func func_020222EC --addr 0x020222EC --cc 1.1p1 --thumb
 */
void func_020222EC(struct DualWin *p)
{
    p->f14C = 0;
    p->f150 = func_02022608(p);
    if (p->f0C != 0) {
        func_02022670(&p->f14);
        if (p->f14.f28 == 0)
            g_021467A4.f14E = 0;
    }
    if (p->f10 != 0) {
        func_02022670(&p->f44);
        if (p->f14.f28 == 0)
            g_021467A4.f14F = 0;
    }
    func_020226A0(p);
}






/*
 * One poll step of the dual-screen cluster.  The mode word at +0x00 (the one
 * func_020223C0 wrote) selects which of the two screen slots gets pumped:
 * mode 0 pumps both, mode 1 prefers the top slot and falls back to the bottom
 * one, mode 2 the mirror of that.  It reports 1 only once both slots have gone
 * null, which is what func_02022174 tests before running the teardown.
 *
 * Three cases starting at zero still compile to a cmp chain, not a halfword
 * table: the table form only wins from four cases up.  The two pump calls are
 * written once per arm and cross-jumped by the compiler into the two shared
 * blocks at 0x0202235C and 0x02022376; factoring them behind a label instead
 * moves the branch targets.  See
 * docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md.
 *
 * The tail has to be written as the positive `if (both null) return 1; return
 * 0;`.  The equivalent `if (top || bottom) return 0; return 1;` inverts the
 * second branch and swaps the two constant returns, four bytes wrong.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022340.c \
 *       --func func_02022340 --addr 0x02022340 --cc 1.1p1 --thumb
 */
u32 func_02022340(struct DualWin *p, void *top, void *bottom)
{
    switch (p->mode) {
    case 0:
        func_02022390(&p->top, top);
        func_02022390(&p->bottom, bottom);
        break;
    case 1:
        if (p->top != 0)
            func_02022390(&p->top, top);
        else
            func_02022390(&p->bottom, bottom);
        break;
    case 2:
        if (p->bottom != 0)
            func_02022390(&p->bottom, bottom);
        else
            func_02022390(&p->top, top);
        break;
    }
    if (p->top == 0 && p->bottom == 0)
        return 1;
    return 0;
}






void func_02022390(u32 *obj, void *arg)
{
    if (*obj != 0) {
        if (func_020223AC(arg) == 1) {
            *obj = 0;
        }
    }
}






u32 func_020223AC(void *p)
{
    u32 idx = ((struct Obj16741 *)p)->f0;
    return g_0209F538[idx](p);
}






static void func_02022424(struct DualWin *p, u32 kind, u32 a, u32 b);







/*
 * Mode decoder for the dual-screen text cluster: a five-case dense switch on
 * the mode index that fills the five leading words of the object with one of
 * five fixed (kind, flagA, flagB) triples.  The writer at 0x02022424 is an
 * unlabelled leaf static in the same translation unit (no lr save, so
 * disasm.py never labels it); it stores the triple twice, once at +0x00/+0x04/
 * +0x08 and once more at +0x0C/+0x10, which is what makes the two later
 * readers see the same pair of values from either half.  It carries its
 * address as its name, and is listed in `function:` above, so the manifest
 * records the address it covers: coverage is counted per address named by an
 * entry, and a range covered only by a unit names nothing on its own.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020223C0.c \
 *       --addr 0x020223C0 --thumb
 */
void func_020223C0(u32 mode, struct DualWin *p)
{
    switch (mode) {
    case 0:
        func_02022424(p, 0, 1, 1);
        break;
    case 1:
        func_02022424(p, 1, 1, 1);
        break;
    case 2:
        func_02022424(p, 2, 1, 1);
        break;
    case 3:
        func_02022424(p, 1, 1, 0);
        break;
    case 4:
        func_02022424(p, 2, 0, 1);
        break;
    }
}





static void func_02022424(struct DualWin *p, u32 kind, u32 a, u32 b)
{
    p->mode = kind;
    p->top = a;
    p->bottom = b;
    p->f0C = a;
    p->f10 = b;
}






/*
 * The eleven-argument screen descriptor builder func_0202208C runs twice, once
 * per screen: a pure field-by-field copy of the argument list into the 0x26
 * byte sub-object, with no validation at all.  The four register arguments
 * land at +0x00..+0x0C and the seven stacked ones at +0x10..+0x24.
 *
 * Two shape facts the encoding pins down.  The sixth and seventh arguments are
 * stored the other way round from the argument order, +0x14 before +0x10, so
 * the struct's own field order is not the parameter order; writing them in
 * parameter order and letting the scheduler interleave is what reproduces the
 * ldr/str pairing.  The last argument is a u16, not a pointer: it is read back
 * with `add r1, sp, #0` + `ldrh r1, [r1, #0x18]` because Thumb has no
 * halfword load with an sp base, and stored with `strh`.  That is the value
 * func_020225F4 resolved, so the sentinel slot at +0x150 is a u16 end to end.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022430.c \
 *       --func func_02022430 --addr 0x02022430 --cc 1.1p1 --thumb
 */
void func_02022430(struct WinPanel *s, u32 a, u32 b, s32 c, u32 d, u32 e,
                   u32 f, void *g, void *h, u32 i, u16 j)
{
    s->f00 = a;
    s->f04 = b;
    s->f08 = c;
    s->phase = d;
    s->obj = (void *)e;
    s->f10 = f;
    s->f18 = (u32)g;
    s->f1C = (u32)h;
    s->heap = i;
    s->f24 = j;
}







/*
 * Resets the 24-byte two-entry callback block at +0x74 of the dual-screen
 * text object (the buffer func_0202208C hands to both screen builders):
 * three parallel two-element arrays, the context pointers at +0x00, the
 * handlers at +0x08 and the user words at +0x10.  Both handler slots are
 * armed with the do-nothing func_020225F0 rather than a null, so the
 * dispatcher never has to test them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022458.c \
 *       --func func_02022458 --addr 0x02022458 --cc 1.1p1 --thumb
 */
void func_02022458(struct Slots *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        p->ctx[i] = 0;
        p->fn[i] = func_020225F0;
        p->arg[i] = 0;
    }
}





void func_02022478(void *task, struct Slots *p)
{
    int i;
    for (i = 0; i < 2; i++)
        p->fn[i](p->ctx[i]);
}






/*
 * Arms one entry of the two-slot callback block at +0x74 of the dual-screen
 * text cluster: the exact inverse of func_020224DC.  It publishes the
 * context pointer at ctx[idx], the handler at fn[idx] (falling back to the
 * do-nothing func_020225F0 when the caller passes none, the same convention
 * func_02022458 uses), and marks the slot live with arg[idx] = 1.  Before
 * any of that, if BOTH user words are still zero the block was idle, so it
 * registers the dispatcher func_02022478 as a task through func_02005624 and
 * parks the handle at g_021468A4 +0x54 -- the same handle func_020224DC
 * releases once both words go back to zero.
 *
 * Data flow checked against both neighbours: func_020224DC clears arg[idx]
 * first and only then tests both words, this function tests both words first
 * and only then writes, so the handle is created exactly once per
 * idle-to-live transition and released exactly once per live-to-idle one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022490.c \
 *       --func func_02022490 --addr 0x02022490 --cc 1.1p1 --thumb --lang c99
 */
void func_02022490(struct Slots *p, void *ctx, Handler fn, u32 idx)
{
    if (p->arg[0] == 0 && p->arg[1] == 0)
        g_021467A4.f154 = func_02005624((u32)func_02022478, (u32)p, 0);

    p->ctx[idx] = ctx;
    if (fn != 0)
        p->fn[idx] = fn;
    else
        p->fn[idx] = func_020225F0;
    p->arg[idx] = 1;
}







/*
 * Drops one entry of the two-slot callback block func_02022458 arms (the
 * 0x18-byte object at +0x74 of the dual-screen cluster): three parallel
 * two-element arrays, ctx[] at +0x00, fn[] at +0x08 and arg[] at +0x10.
 * func_020221B8 calls it once per slot during shutdown.
 *
 * It clears this slot's user word FIRST, and only then checks whether both
 * user words have gone to zero; when they have and the vblank/task handle at
 * g_021468A4 +0x54 is still live, it releases that handle through
 * func_02030EAC and nulls it.  The slot's handler is then re-armed with the
 * do-nothing func_020225F0 rather than a null, the same convention
 * func_02022458 uses, and the context pointer cleared last.
 *
 * Shape notes.  The zero written to arg[idx] and the zero written back to
 * +0x54 are one value kept in r6 across the call, which is what makes them
 * one named local rather than two literal zeroes; the final ctx[idx] = 0
 * uses a fresh `movs r0, #0` after the call instead, so it must be written
 * as a plain constant.  The two `adds r0, r5, r4` recomputations of
 * &slot[idx] on either side of the guard are the compiler's own
 * rematerialisation of the scaled index, not two separate cursors; keeping
 * the address in a named local costs a callee-saved register, see
 * docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020224DC.c \
 *       --func func_020224DC --addr 0x020224DC --cc 1.1p1 --thumb
 */
void func_020224DC(struct Slots *p, u32 idx)
{
    u32 zero = 0;

    p->arg[idx] = zero;
    if (p->arg[0] == 0 && p->arg[1] == 0 && g_021467A4.f154 != 0) {
        func_02030EAC(g_021467A4.f154);
        g_021467A4.f154 = (void *)zero;
    }
    p->fn[idx] = func_020225F0;
    p->ctx[idx] = 0;
}






/*
 *           The only branch reaching 0x020225B4 image-wide is this pool word; 0x020225B4
 *           itself is src/pending/func_020225B4.c, MATCH-capped on 0x02022490, so the
 *           'matched' class has nothing to offer. Every concrete byte is identical
 *           (0 concrete diffs, 4/4 relocations correct, 3 resolved).
 */
void func_02022518(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 *p;

    p = (u32 *)func_02030734((u16)(((u16)a4 & 0x7FFF) | 0x8000), 0x10, 0,
                             g_020A73C8, 0x3E8);
    p[0] = a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    func_020056A0((void *)func_020225B4, p, 0x400);
}






void func_02022568(u32 a0, u32 a1, u32 a2)
{
    u32 *p = func_02030734((u16)(((u16)a2 & 0x7fff) | 0x8000), 8, 0, g_020A73C8, 0x401);

    p[0] = a0;
    p[1] = a1;
    func_020056A0((void *)func_020225D4, p, 8 << 7);
}






/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 */
void func_020225B4(void *a0, u32 *a1)
{
    func_02022490((struct Slots *)a1[0], (void *)a1[1], (Handler)a1[2], a1[3]);
    func_02030EAC(a0);
    func_020307B0(a1);
}




void func_020225D4(struct Node *a0, u32 *a1)
{
    func_020224DC((struct Slots *)a1[0], a1[1]);
    func_02030EAC(a0);
    func_020307B0(a1);
}







/*
 * The do-nothing default handler the two-entry callback table in
 * func_02022458 is initialised with: a single `bx lr` plus two bytes of
 * section padding.  It has no branch reference anywhere in the image, only
 * the ABS32 pool word at 0x02022474 that takes its address, so an EXACT
 * entry here is what lets func_02022458 resolve that pool word on the
 * `matched` class.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_020225F0.c \
 *       --addr 0x020225F0 --thumb
 */
void func_020225F0(void *ctx)
{
}








/*
 * Sentinel resolver for the dual-screen text cluster: 0xFFFF in the caller's
 * value means "use the object's own default", which lives in the u16 at
 * +0x150, the same sentinel colour slot func_0202223C and func_02022268 read.
 * Any other value passes through untouched.  Value and result are both u16:
 * a u16 result needs no re-truncation by the caller that feeds it on as u16.
 *
 * The 0xFFFF compare constant costs a pool word rather than a movs/lsls pair
 * because it is compared, not materialised into a store.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020225F4.c \
 *       --func func_020225F4 --addr 0x020225F4 --cc 1.1p1 --thumb
 */
u16 func_020225F4(struct DualWin *obj, u16 value)
{
    if (value == 0xFFFF)
        value = obj->f150;
    return value;
}







/*
 * A whole translation unit, matched as one byte range.
 *
 * func_02022608 picks one of two sub-objects at fixed offsets (0x14, 0x44)
 * of its argument depending on a mode field at +0xc, then returns a
 * halfword out of that sub-object when its own flag at +0x28 is 1, or
 * else falls back to a halfword 0x150 bytes into the *original* argument
 * (0x15 << 4), untouched by the sub-object selection.
 *
 * func_02022628 alone comes out EXACT* against `one`: its own extent runs
 * two bytes into the ordinary linker fill in front of func_0202262C, a
 * real, separately meaningful function.  Pairing the two in one
 * translation unit lets `tu` lay out both sections with that fill in
 * between, which reproduces cleanly.
 *
 * func_0202262C reads a field 0x10 bytes into its second argument and
 * forwards it, with a fixed 0, to func_020222CC (whose own second
 * argument it never reads: see src/matched/func_020222CC.c), then calls
 * func_02030EAC on the first argument.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02022608.c \
 *       --addr 0x02022608 --thumb
 */
u16 func_02022608(struct DualWin *p)
{
    struct WinPanel *b;

    if (p->f0C == 1) {
        b = &p->f14;
    } else {
        b = &p->f44;
    }
    if (b->f28 == 1) {
        return b->f24;
    }
    return p->f150;
}








void func_0202262C(void *obj, struct Q *q)
{
    func_020222CC(q->unk10, 0);
    func_02030EAC(obj);
}








/*
 * Arms the deferred screen task for one of the two sub-objects func_0202208C
 * built, but only for a screen that is still idle: the task handle at +0x28
 * must be null, the resolved sentinel value at +0x24 must be either the
 * pass-through 0x7FFF or zero, and the second handle at +0x2C must be null
 * too.  All three rejections share one epilogue, so the guard is written as a
 * single conjunction rather than a chain of early returns; see
 * docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022640.c \
 *       --func func_02022640 --addr 0x02022640 --cc 1.1p1 --thumb
 */
void func_02022640(struct WinPanel *s)
{
    if (s->f28 == 0 && (s->f24 == 0x7FFF || s->f24 == 0) && s->f2C == 0)
        func_020056A0((void *)func_0202262C, s, 1 << 10);
}







/*
 * Per-screen finaliser, the mirror of the arming path in func_02022640: it
 * runs only while the screen is in state 1, its resolved sentinel value at
 * +0x24 is the pass-through 0x7FFF or zero, and the second handle at +0x2C is
 * still null.  It then closes the screen's window through the pointer at
 * +0x10, first the flush at 0x0202223C and then the release thunk at
 * 0x02022224.
 *
 * The +0x10 field is re-read for the second call rather than kept in a
 * register, because the first call can alias it; a cached local would drop
 * the second `ldr`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022670.c \
 *       --func func_02022670 --addr 0x02022670 --cc 1.1p1 --thumb
 */
void func_02022670(struct WinPanel *s)
{
    if (s->f28 == 1 && (s->f24 == 0x7FFF || s->f24 == 0) && s->f2C == 0) {
        func_0202223C(s->f10, s->f24);
        func_02022224((void *)s->f10);
    }
}







/*
 * A whole translation unit, matched as one byte range.
 *
 * func_020226A0 is five back-to-back MI_CpuFill8 zero-fills over five
 * sub-ranges of one object (sizes 0x14, 0x30, 0x30, 0x18, 0xC0 at offsets
 * 0, 0x14, 0x44, 0x74, 0x8C); it is one of the "0x0209F5xx/0x0209F6xx"
 * cluster's neighbours and clears the object the setup functions in
 * src/matched/func_02022804.c and siblings configure.
 *
 * func_020226E0 checks a delegate pointer at +0xc, the same guard shape as
 * that cluster: when set, the call forwards to func_02022A44 and returns
 * its result; the fall-through has to be written on the guard's
 * complement (`== 0`) with the delegate call left unconditional after it,
 * or the two blocks come out in the wrong order.  The fall-through sets
 * the flag pair at +0x28 and +0x2c to (1, 1) and calls func_020229A4(p, 1).
 *
 * func_020226FC, immediately after this range, is the same shape again
 * with (0, 1) and mode 0 (src/matched/func_020226FC.c); it is kept in its
 * own file specifically so that its calls to func_020229A4 and
 * func_02022A44 stay outside this range and keep attesting them, and vice
 * versa (docs/MATCHING.md, "the label class" and "the pairwise case across
 * two files").  Bundling all three into one file drops both relocations to
 * MATCH, because each one's only other witness is then inside the same
 * compared range.
 *
 * func_020226A0 alone comes out EXACT* against `one`: its own extent runs
 * two bytes into the ordinary linker fill in front of func_020226E0, which
 * is a real, separately-matched function and not an unlabelled follower.
 * Pairing the two in one translation unit lets `tu` lay out both sections
 * with that fill in between, which reproduces cleanly.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020226A0.c \
 *       --addr 0x020226A0 --thumb
 */
void func_020226A0(struct DualWin *p)
{
    MI_CpuFill8(p, 0, 0x14);
    MI_CpuFill8(&p->f14, 0, 0x30);
    MI_CpuFill8(&p->f44, 0, 0x30);
    MI_CpuFill8(&p->f74, 0, 0x18);
    MI_CpuFill8(p->f8C, 0, 0xC0);
}







u32 func_020226E0(struct WinPanel *p)
{
    if (p->phase == 0) {
        p->f28 = 1;
        p->f2C = 1;
        func_020229A4(p, 1);
        return 0;
    }
    return func_02022A44(p);
}







/*
 * Same shape as func_020226E0 in src/matched/unit_020226A0.c, and kept in
 * its own file for the same reason: its calls to func_020229A4 and
 * func_02022A44 have to stay outside that unit's compared range to attest
 * its calls, and vice versa.  Sets the flag pair at +0x28 and +0x2c to
 * (0, 1) instead of (1, 1) and calls func_020229A4(p, 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020226FC.c \
 *       --func func_020226FC --addr 0x020226FC --cc 1.1p1 --thumb
 */
u32 func_020226FC(struct WinPanel *p)
{
    if (p->phase == 0) {
        p->f28 = 0;
        p->f2C = 1;
        func_020229A4(p, 0);
        return 0;
    }
    return func_02022A44(p);
}







/*
 * wipe.c (docs/families/wipe.h): the slot-0 member of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC (template: func_02022758).
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 9 out under 1.1p1 and 1 out
 * under every 2.0 build, docs/notes/pkt_0202271C.c.txt): the pool carries
 * 0x020A73D0 TWICE (0x02022750 for the store, 0x02022754 for the argument),
 * so two source-level names were in play. The slot store goes through
 * g_020A73D0 and the argument is a second extern, g_wipe_slot0, at the same
 * address. With one name 1.1p1 CSEs both uses into r5 (push {r3, r4, r5,
 * lr}); with two it reloads each from its own pool word under push {r4, lr}.
 * Same finding as src/matched/func_02023F98.c in the same module, whose
 * header explains why the bytes fix the number of names but not whether the
 * original had one object or two declarations of it. For the other three
 * slots the two uses differ by the slot offset, so one name suffices there.
 */
void func_0202271C(struct WinPanel *p)
{
    if (p->phase == 0) {
        g_020A73D0.f00 = (u32)d_0209F570;
        func_020222A8(p->f24);
        func_020238B4(p, (u32)(&g_wipe_slot0));
        p->f28 = 1;
        p->f2C = 0;
    } else {
        func_0202390C(p);
    }
}







/*
 * wipe.c (docs/families/wipe.h): one of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC.  Each installs a rodata
 * word table (0x0209F568..0x0209F574, four u32 words, NOT ARM code: the
 * old headers declared them as arm functions, which is why they had no
 * witness) into one slot of the wipe state at 0x020A73D0, then hands that
 * slot to func_020238B4.  Declared as data, the table address is attested
 * sole-ref/self.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022758.c  *       --func func_02022758 --addr 0x02022758 --thumb --cc 1.1p1
 */
void func_02022758(struct WinPanel *p)
{
    if (p->phase == 0) {
        g_020A73D0.f10 = (u32)d_0209F56C;
        func_020222A8(p->f24);
        func_020238B4(p, (u32)(&g_020A73D0.f10));
        p->f28 = 0;
        p->f2C = 0;
    } else {
        func_0202390C(p);
    }
}









/*
 * wipe.c (docs/families/wipe.h): one of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC.  Each installs a rodata
 * word table (0x0209F568..0x0209F574, four u32 words, NOT ARM code: the
 * old headers declared them as arm functions, which is why they had no
 * witness) into one slot of the wipe state at 0x020A73D0, then hands that
 * slot to func_020238B4.  Declared as data, the table address is attested
 * sole-ref/self.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022790.c  *       --func func_02022790 --addr 0x02022790 --thumb --cc 1.1p1
 */
void func_02022790(struct WinPanel *p)
{
    if (p->phase == 0) {
        g_020A73D0.f20 = (u32)d_0209F574;
        func_020222A8(p->f24);
        func_020238B4(p, (u32)(&g_020A73D0.f20));
        p->f28 = 1;
        p->f2C = 0;
    } else {
        func_0202390C(p);
    }
}







/*
 * wipe.c (docs/families/wipe.h): one of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC.  Each installs a rodata
 * word table (0x0209F568..0x0209F574, four u32 words, NOT ARM code: the
 * old headers declared them as arm functions, which is why they had no
 * witness) into one slot of the wipe state at 0x020A73D0, then hands that
 * slot to func_020238B4.  Declared as data, the table address is attested
 * sole-ref/self.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020227CC.c  *       --func func_020227CC --addr 0x020227CC --thumb --cc 1.1p1
 */
void func_020227CC(struct WinPanel *p)
{
    if (p->phase == 0) {
        g_020A73D0.f28 = (u32)d_0209F568;
        func_020222A8(p->f24);
        func_020238B4(p, (u32)(&g_020A73D0.f28));
        p->f28 = 0;
        p->f2C = 0;
    } else {
        func_0202390C(p);
    }
}







/*
 * One of a run of near-identical setup functions on one object
 * (func_02022804, func_02022830, func_0202285C, func_02022888,
 * func_020228B4, func_020228E0, each its own file so that the sibling
 * calls to the shared helpers stay outside the compared range and keep
 * attesting them; see docs/MATCHING.md, "the label class").
 *
 * Checks a delegate pointer at +0xc: when set, the whole call forwards to
 * func_020234C0 and returns.  That arm has to be written as the
 * fall-through (the guard on the complement, `== 0`, with the delegate
 * call left unconditional after it): the mirror phrasing, guarding
 * `!= 0` with the delegate inside the guarded block, lays the blocks out
 * in the opposite order and does not reproduce.  The fall-through calls
 * func_020222A8 with the object's id field at +0x24, then func_02023464
 * with the object pointer and a second, unattested pool constant
 * (0x0209F61C, written as a plain integer literal since nothing in this
 * function's own range names it as a symbol), and finally sets the pair
 * of flag words at +0x28 (to 1) and +0x2c (to 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022804.c \
 *       --func func_02022804 --addr 0x02022804 --cc 1.1p1 --thumb
 */
void func_02022804(struct WinPanel *p)
{
    if (p->phase == 0) {
        func_020222A8(p->f24);
        func_02023464(p, (u8 *)0x0209F61C);
        p->f28 = 1;
        p->f2C = 0;
        return;
    }
    func_020234C0(p);
}







/*
 * Same shape as src/matched/func_02022804.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (0, 0) instead of (1, 0), and stashes the constant 0x0209F628.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022830.c \
 *       --func func_02022830 --addr 0x02022830 --cc 1.1p1 --thumb
 */
void func_02022830(struct WinPanel *p)
{
    if (p->phase == 0) {
        func_020222A8(p->f24);
        func_02023464(p, (u8 *)0x0209F628);
        p->f28 = 0;
        p->f2C = 0;
        return;
    }
    func_020234C0(p);
}







/*
 * Same shape as src/matched/func_02022804.c, but the helper pair is
 * func_020235F0 / func_0202363C instead of func_02023464 / func_020234C0;
 * kept in its own file for the same reason (the sibling calls to the
 * shared helpers have to stay outside the compared range to attest them).
 * Sets the flag pair to (1, 0) and stashes the constant 0x0209F6B8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202285C.c \
 *       --func func_0202285C --addr 0x0202285C --cc 1.1p1 --thumb
 */
void func_0202285C(struct WinPanel *p)
{
    if (p->phase == 0) {
        func_020222A8(p->f24);
        func_020235F0(p, 0x0209F6B8);
        p->f28 = 1;
        p->f2C = 0;
        return;
    }
    func_0202363C((struct Rec_020225F0 *)p);
}







/*
 * Same shape as src/matched/func_0202285C.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (0, 0) instead of (1, 0), and stashes the constant 0x0209F6C4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022888.c \
 *       --func func_02022888 --addr 0x02022888 --cc 1.1p1 --thumb
 */
void func_02022888(struct WinPanel *p)
{
    if (p->phase == 0) {
        func_020222A8(p->f24);
        func_020235F0(p, 0x0209F6C4);
        p->f28 = 0;
        p->f2C = 0;
        return;
    }
    func_0202363C((struct Rec_020225F0 *)p);
}







/*
 * Same shape as src/matched/func_02022804.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (1, 0) and stashes the constant 0x0209F5EC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020228B4.c \
 *       --func func_020228B4 --addr 0x020228B4 --cc 1.1p1 --thumb
 */
void func_020228B4(struct WinPanel *p)
{
    if (p->phase == 0) {
        func_020222A8(p->f24);
        func_02023464(p, (u8 *)0x0209F5EC);
        p->f28 = 1;
        p->f2C = 0;
        return;
    }
    func_020234C0(p);
}







/*
 * Same shape as src/matched/func_020228B4.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (0, 0) instead of (1, 0), and stashes the constant 0x0209F640.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020228E0.c \
 *       --func func_020228E0 --addr 0x020228E0 --cc 1.1p1 --thumb
 */
void func_020228E0(struct WinPanel *p)
{
    if (p->phase == 0) {
        func_020222A8(p->f24);
        func_02023464(p, (u8 *)0x0209F640);
        p->f28 = 0;
        p->f2C = 0;
        return;
    }
    func_020234C0(p);
}







/*
 * A whole translation unit, matched as one byte range.
 *
 * func_0202290C is a 16-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): it computes
 * (b - a) << 7 and forwards it with the third argument straight to
 * func_0209C0A4.  The pool word carries no Thumb bit and the branch is a
 * plain `bx` rather than `blx`, so the callee is declared `arm`; the image
 * labels it as a real function reached from 161 other call sites.
 *
 * func_0202291C is a plain four-word running-sum accumulator.  It does not
 * fold into an ldm/stm pair the way a whole-object assignment would
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), because each field is
 * added rather than copied.
 *
 * Compiling func_0202291C on its own comes out EXACT* against `one`: its
 * own extent runs to the 2-byte linker fill in front of func_02022940,
 * which is a real function and not an unlabelled follower.  Pairing it
 * with func_0202290C in one translation unit lets `tu` lay out both
 * sections with that fill in between, which reproduces cleanly.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202290C.c \
 *       --addr 0x0202290C --thumb
 */
s32_0202290C func_0202290C(s32_0202290C a, s32_0202290C b, s32_0202290C c)
{
    return func_0209C0A4((b - a) << 7, c);
}







void func_0202291C(struct Quad *dst, struct Quad *src)
{
    dst->a += src->a;
    dst->b += src->b;
    dst->c += src->c;
    dst->d += src->d;
}







/*
 * wipe.c: seeds a four-channel fade.  cur = from << 7 (fixed point), end =
 * to, step = func_0202290C(from, to, frames) per channel; called from
 * func_0202350C with (obj, &obj->f20, &obj->f10, cfg, cfg + 4, frames).
 * func_0202290C returns its tail callee's value here (the unit that
 * matched it declares it void; the caller stores r0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022940.c  *       --func func_02022940 --addr 0x02022940 --thumb --cc 1.1p1
 */
void func_02022940(struct Quad *cur, struct Quad *end, struct Quad *step,
                   const u8 *from, const u8 *to, s32_02022940 frames)
{
    cur->a = from[0] << 7;
    cur->b = from[1] << 7;
    cur->c = from[2] << 7;
    cur->d = from[3] << 7;
    end->a = to[0];
    end->b = to[1];
    end->c = to[2];
    end->d = to[3];
    step->a = func_0202290C(from[0], to[0], frames);
    step->b = func_0202290C(from[1], to[1], frames);
    step->c = func_0202290C(from[2], to[2], frames);
    step->d = func_0202290C(from[3], to[3], frames);
}







/*
 * The constructor of the wipe task whose per-frame step is func_02022A44:
 * it allocates and zeroes the 0x24-byte sub-object, picks the pair of
 * start/end extents from the task's direction flag and the sentinel in
 * +0x24, fills the sub-object's eight words and registers the per-frame
 * callback func_02022AC4 with func_020056A0 at priority 0x80.
 *
 * The 0x7FFF in +0x24 is a "no explicit extent" sentinel: when it is
 * present the moving edge starts at 0x10 (or ends there, depending on the
 * direction flag) and the other edge starts at 0; when it is absent both
 * edges start at 0 and the moving one is biased by -0x10.  The four arms
 * are written out separately, which is what gives four `b` to the shared
 * continuation rather than a computed pair
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * Both extents reach the sub-object scaled by 128 (`lsls #7`), i.e. as
 * 24.7 fixed point, while the unscaled values stay in r7/r6 for the
 * func_0202290C call and the +0x1c store.
 *
 * The direction test is written `dir == 0` first: the image's `bne` at
 * +0x2e takes the SECOND arm, so the zero case is the fall-through and
 * therefore the source's first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  Written the
 * other way round every byte from +0x2e to +0x4a is wrong -- the four arm
 * bodies come out in the mirrored order and r6/r7 trade roles -- while
 * everything before and after stays identical, which is exactly the
 * signature that says polarity rather than shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020229A4.c \
 *       --func func_020229A4 --addr 0x020229A4 --cc 1.1p1 --thumb
 */
void func_020229A4(struct WinPanel *t, u32 dir)
{
    struct AnimStep *o;
    s32_020229A4         a;
    s32_020229A4         b;

    t->obj = (struct AnimStep *)func_02030734((u16)t->heap, 0x24, 0, (const char *)0x020A7450,
                                         0x09AC);
    func_02082BCC(t->obj, 0, 0x24);
    o = t->obj;

    b = 0;
    if (dir == 0) {
        if (t->f24 == 0x7FFF) {
            a = 0x10;
        } else {
            a = b;
            a = a - 0x10;
        }
    } else {
        if (t->f24 == 0x7FFF) {
            a = b;
            b = 0x10;
        } else {
            a = b;
            b = b - 0x10;
        }
    }

    func_020222CC(t->f10, a);

    o->steps = t->f04;
    o->limit = t->f08;
    o->counter = 0;
    o->val = a << 7;
    o->target_val = b << 7;
    o->step_delta = func_0202290C(a, b, t->f04);
    o->pad18 = t->f10;
    o->scaled_val = a;
    t->phase = t->phase + 1;
    o->f20 = func_020056A0((void *)func_02022AC4, o, 0x80);
}







/*
 * The per-frame step of a wipe task, the sibling of func_020234C0 at the
 * other end of the family: the same four-phase switch over the task's
 * +0x0c, the same sub-object slot at +0x14, and the same terminal phase 3
 * that is the only one to answer 1.  Phase 1 polls func_02022A88 and
 * advances when it answers 1; phase 2 releases the sub-object's +0x20
 * handle through func_02030EAC, frees the object itself, clears the slot
 * and advances.
 *
 * THE LEVER, and it is shared with func_02022A44, func_0202390C and
 * func_020234C0 (all three sat at exactly two bytes out until it was
 * found; func_0202363C in src/matched had it right all along and is where
 * it was read from).  Phase 2 assigns the result variable 1 as well,
 * immediately before its `break`:
 *
 *     case 2:  ... t->obj = 0; ret = 1; break;
 *     case 3:  ret = 1; break;
 *
 * The assignment is semantically dead -- the caller re-polls and phase 3
 * answers 1 on the next frame anyway -- but it is what makes phase 2's
 * `break` compile to a branch onto phase 3's own `movs r4, #1` instead of
 * onto the shared tail: the compiler cross-jumps the two identical
 * assignments and phase 2's exit lands on the surviving copy.  Written
 * without it the function is right in every other byte and the one branch
 * displacement is two too large.  Nothing else reaches it: 131 single
 * mutations and 3000 annealing compiles of tools/permuter.py left the
 * residue untouched (it is a cross-jumping decision, not an allocation
 * one), and every other switch spelling tried -- goto into phase 3, a
 * reordered case set, default before case 3, an if/else-if chain, an
 * added empty case -- is the same two bytes out or worse.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022A44.c \
 *       --func func_02022A44 --addr 0x02022A44 --cc 1.1p1 --thumb
 */
u32 func_02022A44(struct WinPanel *t)
{
    struct AnimStep *obj;
    u32         ret;

    ret = 0;
    obj = t->obj;

    switch (t->phase) {
    case 1:
        if (func_02022A88(obj) == 1) {
            t->phase = t->phase + 1;
        }
        break;
    case 2:
        func_02030EAC((struct Node *)obj->f20);
        func_020307B0(t->obj);
        t->phase = t->phase + 1;
        t->obj = 0;
        ret = 1;
        break;
    case 3:
        ret = 1;
        break;
    default:
        break;
    }

    return ret;
}








int func_02022A88(struct AnimStep *p)
{
    int ret = 0;

    p->counter++;
    if (p->counter >= p->limit) {
        p->counter = 0;
        if (p->steps - 1 > 0) {
            p->steps--;
            p->val += p->step_delta;
        } else {
            p->val = p->target_val;
            ret = 1;
        }

        p->scaled_val = p->val / 128;
    }

    return ret;
}







/*
 * Re-verified 2026-09-23: the MATCH park had turned DIFF (one byte) under
 * the new extents because its header named the callee 0x020202CC.  The
 * pool word at 0x02022ACC is 0x020222CD: the callee is 0x020222CC
 * (src/matched/func_020222CC.c, labelled with sixteen outside branches),
 * so the old "unlabelled leaf, sole reference" blocker was a digit slip.
 * With the address corrected the site resolves `label` and the file is
 * EXACT.
 *
 * An unlabelled leaf forwarder: it drops its own first argument and calls
 * func_020222CC with the two pointer fields at +0x18 and +0x1c of its
 * second.  The ordinary tail-call form, a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022AC4.c \
 *       --func func_02022AC4 --addr 0x02022AC4 --cc 1.1p1 --thumb
 */
void func_02022AC4(void *unused, u8 *o)
{
    func_020222CC((u32)(((struct Obj11726 *)o)->f18), (int)(((struct Obj11726 *)o)->f1C));
}







/*
 * The four pool words at 0x02022CDC are 0x04000006, 0x04000004,
 * 0x04001040 and 0x04001042: I/O register addresses, written as cast
 * constants, not relocations.
 *
 * The 8-byte residue docs/notes/func_02022AD0.c.txt records at +0x00CC
 * is closed by ONE statement order: block two must read ctl->sel BEFORE
 * its three array reads, exactly as blocks one and three do.  With
 * sel read last (the note's C) the 0x180 constant is hoisted one slot
 * early and the y[] address lands in r0 instead of r1; with sel first
 * the block is byte-identical to its two neighbours.
 */
void func_02022AD0(struct ctl *ctl)
{
    struct sched *p;
    s32_02022AD0 line;
    s32_02022AD0 next;
    s32_02022AD0 x;
    s32_02022AD0 y;
    u32 flag;
    u32 sel;

    line = REG_VCOUNT;
    if (line >= 0xc0) {
        return;
    }
    next = line + 1;
    if (next > 0xbf) {
        next -= 0xc0;
    }

    if (ctl->mode == 1) {
        p = func_02022D88((struct Container_020225F0 *)ctl, 0);
        sel = ctl->sel;
        y = p->y[next];
        x = p->x[next];
        flag = p->flag;
        if (flag == 0) {
            if (sel == 0) {
                if ((REG_A[0] & 2) != 0) {
                    REG_A[0x1e] = ((x << 8) & 0xff00) | (u32)(u8)y;
                    REG_A[0x20] = 0xc0;
                }
            } else {
                if ((REG_A[0] & 2) != 0) {
                    REG_B[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                    REG_B[2] = 0xc0;
                }
            }
        } else {
            if (sel == 0) {
                if ((REG_A[0] & 2) != 0) {
                    REG_A[0x1f] = ((x << 8) & 0xff00) | (u32)(u8)y;
                    REG_A[0x21] = 0xc0;
                }
            } else {
                if ((REG_A[0] & 2) != 0) {
                    REG_C[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                    REG_C[2] = 0xc0;
                }
            }
        }
        return;
    }

    p = func_02022D88((struct Container_020225F0 *)ctl, 0);
    sel = ctl->sel;
    y = p->y[next];
    x = p->x[next];
    flag = p->flag;
    if (flag == 0) {
        if (sel == 0) {
            if ((REG_A[0] & 2) != 0) {
                REG_A[0x1e] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_A[0x20] = 0xc0;
            }
        } else {
            if ((REG_A[0] & 2) != 0) {
                REG_B[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_B[2] = 0xc0;
            }
        }
    } else {
        if (sel == 0) {
            if ((REG_A[0] & 2) != 0) {
                REG_A[0x1f] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_A[0x21] = 0xc0;
            }
        } else {
            if ((REG_A[0] & 2) != 0) {
                REG_C[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_C[2] = 0xc0;
            }
        }
    }

    p = func_02022D88((struct Container_020225F0 *)ctl, 1);
    sel = ctl->sel;
    y = p->y[next];
    x = p->x[next];
    flag = p->flag;
    if (flag == 0) {
        if (sel == 0) {
            if ((REG_A[0] & 2) != 0) {
                REG_A[0x1e] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_A[0x20] = 0xc0;
            }
        } else {
            if ((REG_A[0] & 2) != 0) {
                REG_B[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_B[2] = 0xc0;
            }
        }
    } else {
        if (sel == 0) {
            if ((REG_A[0] & 2) != 0) {
                REG_A[0x1f] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_A[0x21] = 0xc0;
            }
        } else {
            if ((REG_A[0] & 2) != 0) {
                REG_C[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_C[2] = 0xc0;
            }
        }
    }
}







/*
 * Allocate the working buffer for one of the three background planes and
 * stamp its descriptor word: the two small planes share the 0x604-byte
 * buffer (tag 0xa9b, mode word 1, the plane's row limit written at +0x600)
 * while the third takes the 0xc08-byte buffer (tag 0xaa3, mode word 2) and
 * zeroes +0x600 at a 0x604 stride.  a1 outside 0..2 does nothing.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022CEC.c \
 *       --func func_02022CEC --addr 0x02022CEC --cc 1.1p1 --thumb
 */
void func_02022CEC(u32 *a0, u32 a1, u32 a2, u32 a3)
{
    int i;
    u8 *p;

    switch (a1) {
    case 0:
    case 1:
        p = func_02030734((u16)a3, 0x604, 0, (const char *)0x020A7450, 0xA9B);
        a0[1] = 1;
        a0[0] = (u32)p;
        a0[2] = a2;
        ((struct Obj15738 *)p)->f600 = a1;
        break;
    case 2:
        p = func_02030734((u16)a3, 0xC08, 0, (const char *)0x020A7450, 0xAA3);
        a0[0] = (u32)p;
        a0[1] = 2;
        a0[2] = a2;
        for (i = 0; i < 2; i++) {
            *(u32 *)(a0[0] + 0x600 + i * 0x604) = i;
        }
        break;
    }
}







/*
 * Blocked: 02022D78 (thumb, from header) has no witness outside 02022D70..02022D78. Every concrete byte reproduces.
 * closed:   blocker func_020294C0.c is now a manifest entry (matched class)
 */
void func_02022D70(void *a0)
{
    func_02022D78(a0);
}







/*
 * closed:   blocker func_02029488.c is now a manifest entry (matched class)
 *
 * Releases the object the node's first word points at and clears the slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02022D78.c \
 *       --func func_02022D78 --addr 0x02022D78 --thumb --cc 1.1p1
 */
void func_02022D78(u8 *p)
{
    func_020307B0(*(void **)p);
    *(u32 *)p = 0;
}








/*
 * Index into a flat array whose base pointer is the first field of
 * `obj`, with a fixed 0x604-byte stride.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022D88.c \
 *       --func func_02022D88 --addr 0x02022D88 --cc 1.1p1 --thumb
 */
void *func_02022D88(struct Container_020225F0 *c, u32 idx)
{
    return (u8 *)c->base + idx * 0x604;
}







void func_02022D98(void *p, struct Container_020225F0 *c)
{
    s32 i;

    for (i = 0; i < c->count; i++) {
        u8 *ptr = (u8 *)func_02022D88((struct Container_020225F0 *)c, i);
        MI_CpuCopy8(ptr + 0x300, ptr, 0x300);
    }
    func_02030EAC(p);
}







/*
 * Open one sprite/OBJ descriptor: a0 == 0 is the "close" spelling (one call
 * with mode 0 and no attribute writes), anything else opens with mode 1, sets
 * the 0x3f field, clears two zero slots through the six-argument entry and
 * finally stamps the 0x20 field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022DCC.c \
 *       --func func_02022DCC --addr 0x02022DCC --cc 1.1p1 --thumb
 */
void func_02022DCC(u32 a0, void *a1, u32 a2)
{
    if (a0 == 0) {
        func_02023CFC(a1, (void *)0, a2);
        return;
    }
    func_02023CFC(a1, (void *)1, a2);
    func_02023D18(a1, (void *)0x3f, 0, 0, a2);
    func_02023D60(a1, 0, 0, 0, 0, 0, a2);
    func_02023D40(a1, (void *)0x20, 0, a2);
}










/*
 * The family's ten-argument setup dispatcher, called from func_0202350C
 * with a wipe's configuration block already unpacked into registers and
 * stack.  The last argument selects the shape: zero takes the window
 * path (func_02023B74 / func_02023BFC / func_02023C3C) and anything else
 * takes the blend path (func_02023D18 / func_02023D40 / func_02023D60).
 *
 * The two arms are written out in full rather than factored, which is
 * what keeps them as two separate three-call sequences with their own
 * epilogues rather than one tail-merged tail
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022E20.c \
 *       --func func_02022E20 --addr 0x02022E20 --cc 1.1p1 --thumb
 */
void func_02022E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7, u32 a8, u32 a9)
{
    if (a9 == 0) {
        func_02023B74(a1, 0, a3, a4);
        func_02023BFC(a2, 0, a4);
        func_02023C3C(a5, a6, a7, a8, a3, a4);
    } else {
        func_02023D18((void *)a0, (void *)a1, 0, a3, a4);
        func_02023D40((void *)a0, (void *)a2, 0, a4);
        func_02023D60((u8 *)a0, a5, a6, a7, a8, a3, a4);
    }
}









void func_02022E88(struct Struct_02023CFC *table, u32 val, u32 idx, u32 mode)
{
    if (mode == 0) {
        func_02023B48(val, idx);
    } else {
        func_02023CFC(table, (void *)val, idx);
    }
}










/*
 * Clear 0x30c bytes of an OBJ record, stamp the two attribute words a3/a4
 * and the mode bytes a1/a2.  a2 == 1 is the "no second slot" spelling: the
 * word at +0x304 is left alone and the two bytes sit at +0x308/+0x309.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022EA0.c \
 *       --func func_02022EA0 --addr 0x02022EA0 --cc 1.1p1 --thumb
 */
void func_02022EA0(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    MI_CpuFill8(a0, 0, 0x30c);
    if (a2 == 1) {
        ((struct Obj04050 *)a0)->f180 = a3;
        ((struct Obj04050 *)a0)->f308 = a2;
        ((struct Obj04050 *)a0)->f309 = a1;
        return;
    }
    ((struct Obj04050 *)a0)->f180 = a3;
    ((struct Obj04050 *)a0)->f304 = a4;
    ((struct Obj04050 *)a0)->f308 = a2;
    ((struct Obj04050 *)a0)->f309 = a1;
}










void *func_02022EF4(void *arg)
{
    return func_020056A0(func_02022F34, arg, 0x3FF);
}










void func_02022F0C(u32 a0, u8 *a1, u32 a2)
{
    func_02022518(a0, (u32)a1, (u32)func_02022F60, a1[0x309], a2);
}










void func_02022F24(u32 a0, u8 *a1, u32 a2)
{
    func_02022568(a0, a1[0x309], a2);
}










void func_02022F34(void *p, struct WipeSubElem *elems)
{
    int i;

    for (i = 0; i < 2; i++) {
        MI_CpuCopy8(elems[i].buf2, elems[i].buf1, 0xC0);
    }
    func_02030EAC(p);
}








static inline void Apply(struct S_02022E20 *p, struct Half *h, int n)
{
    int v;
    int e;

    if (h->rows[n] == 0) {
        SET_OUT(p->eng, 0x3F)
        SET_IN(p->eng, h->wnd, 0x20)
    } else {
        SET_OUT(p->eng, 0x20)
        SET_IN(p->eng, h->wnd, 0x3F)
    }
}







/*
 * The per-scanline window programmer of the wipe family (1284 bytes with
 * both literal pools; no relocations at all, every pool word is a
 * hardware register address or a mask).  It reads VCOUNT, steps to the
 * next line (wrapping at 0xC0) and, for one or both of the two 0x184-byte
 * halves of the object, sets the outside-window plane mask (0x3F on a
 * clear row, 0x20 on a set one) and then the window-0 or window-1 inside
 * mask (chosen by the half's +0x180 word) on the MAIN engine when the
 * byte at +0x309 is 0 and on the SUB engine otherwise.
 *
 * Four facts closed it (the 2026-09-21 note was 140 bytes short):
 *  - The +0x309 arms are NOT identical: the zero arm writes the main
 *    engine's WININ/WINOUT at 0x04000048/0x0400004A, reached as
 *    0x04000004 + 0x44/0x46 off the already-loaded DISPSTAT address, and
 *    the other arm the sub engine's 0x04001048/0x0400104A.  With both
 *    arms spelled the same mwcc cross-jumps them, which was the whole
 *    deficit.
 *  - The +0x309 byte is read BEFORE the +0x180 word at every WININ
 *    leaf, so the engine is bound to a local ahead of the window test.
 *  - The second half's base is a NAMED local `h = &p->h[1]`: passed
 *    inline, mwcc folds p + 0x184 + n + 0xC0 into one offset and the
 *    +0x180 word into p + 0x304; the image materialises p + 0x184 once.
 *  - The body is wrapped in `if (n < 0xC0)`, which lets the exit branch
 *    reuse a leaf's branch island (`bge` to 0x02022FE6) instead of a
 *    blt/b pair; and the window-1 mask is `~0x3F00` (pool word
 *    0xFFFFC0FF), not 0xC0FF.
 */
void func_02022F60(struct S_02022E20 *p)
{
    int n;
    struct Half *h;

    n = REG_VCOUNT;
    if (n < 0xC0) {
        n = n + 1;
        if (n > 0xBF)
            n -= 0xC0;

        if (p->mode == 1) {
            Apply(p, &p->h[0], n);
        } else {
            Apply(p, &p->h[0], n);
            h = &p->h[1];
            Apply(p, h, n);
        }
    }
}








/*
 * Starts one countdown wipe: allocates the 0x4c-byte object on the heap
 * named by the low half of the task's +0x20 word, parks it at +0x14, hands
 * the task's saved parameters to func_0202350C, opens the display side
 * through func_02022E88 with mode 1 or 2 by the caller's cfg[8], and
 * advances the task's phase.  __FILE__ is "wipe_sub.c" at 0x020A7450,
 * __LINE__ 0xc7c.
 *
 * The notes carried an r4/r6 tie (o against cfg) that 3800 permuter
 * compiles never moved.  It was not an allocation tie: the func_02022E88
 * call is written out in BOTH arms of the cfg[8] test, with 1 and 2 as
 * literals, and mwcc cross-jumps the two calls, leaving `movs r1,#1 / b /
 * movs r1,#2` in front of one shared call.  A `mode` local assigned in
 * the if/else puts the test value in r1 and swaps r4/r6 for the whole
 * function (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 */
void func_02023464(struct WinPanel *t, u8 *cfg)
{
    struct WipeTiles *o;

    o = func_02030734((u16)t->heap, 0x4c, 0, func_02023464_File, 0xc7c);
    t->obj = o;

    func_0202350C(o, cfg, t->f04, t->f08, t->f10, t->f18);

    if (cfg[8] == 0) {
        func_02022E88((struct Struct_02023CFC *)t->f18, 1, o->f30, o->f44);
    } else {
        func_02022E88((struct Struct_02023CFC *)t->f18, 2, o->f30, o->f44);
    }

    t->phase = t->phase + 1;
}








/*
 * The per-frame step of the wipe/transition task set up at 0x02023464.
 * The task block keeps its phase at +0x0c and the sub-object it allocated
 * at +0x14.  Phase 1 polls func_02023568 and, once that answers 1, hands
 * the sub-object's +0x44 field to func_02022DCC and advances; phase 2
 * frees the sub-object (func_020307B0), clears the slot and advances;
 * phase 3 is the terminal phase and is the only one that answers 1, which
 * is how the caller learns the transition has finished.  Phase 0 and any
 * other value answer 0 and do nothing.
 *
 * THE LEVER, and it is shared with func_02022A44, func_0202390C and
 * func_020234C0 (all three sat at exactly two bytes out until it was
 * found; func_0202363C in src/matched had it right all along and is where
 * it was read from).  Phase 2 assigns the result variable 1 as well,
 * immediately before its `break`:
 *
 *     case 2:  ... t->obj = 0; ret = 1; break;
 *     case 3:  ret = 1; break;
 *
 * The assignment is semantically dead -- the caller re-polls and phase 3
 * answers 1 on the next frame anyway -- but it is what makes phase 2's
 * `break` compile to a branch onto phase 3's own `movs r4, #1` instead of
 * onto the shared tail: the compiler cross-jumps the two identical
 * assignments and phase 2's exit lands on the surviving copy.  Written
 * without it the function is right in every other byte and the one branch
 * displacement is two too large.  Nothing else reaches it: 131 single
 * mutations and 3000 annealing compiles of tools/permuter.py left the
 * residue untouched (it is a cross-jumping decision, not an allocation
 * one), and every other switch spelling tried -- goto into phase 3, a
 * reordered case set, default before case 3, an if/else-if chain, an
 * added empty case -- is the same two bytes out or worse.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020234C0.c \
 *       --func func_020234C0 --addr 0x020234C0 --cc 1.1p1 --thumb
 */
u32 func_020234C0(struct WinPanel *t)
{
    void *obj;
    u32   ret;

    ret = 0;
    obj = t->obj;

    switch (t->phase) {
    case 1:
        if (func_02023568(obj) == 1) {
            func_02022DCC(((struct WipeTiles *)obj)->f44, (void *)t->f18, t->f10);
            t->phase = t->phase + 1;
        }
        break;
    case 2:
        func_020307B0(obj);
        t->phase = t->phase + 1;
        t->obj = 0;
        ret = 1;
        break;
    case 3:
        ret = 1;
        break;
    default:
        break;
    }

    return ret;
}









/*
 * wipe_sub.  Closed 2026-09-24 (wave 21, lane E2) from the DIFF 2 recorded
 * in docs/notes/func_0202350C.c.txt.  Two matching levers carry it:
 *   - the zero is an enum-typed local (docs/idioms/an-enum-typed-zero-keeps-
 *     its-own-web-where-a-u32-zero-is-folded.md), read in image order k8, z,
 *     kb;
 *   - a5 is read through a volatile access placed after the f40 store and
 *     before the f44 store.  That puts a5's load (r0, the call's first
 *     argument) inside kb's live range, so kb can no longer take r0 and the
 *     zero does, while the f48 store stays last.  A plain copy of a5 is
 *     propagated back to the f48 store and does nothing (12 out).
 */
void func_0202350C(struct WipeTiles *obj, const u8 *cfg, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u32 k8;
    u32 kb;
    E z;
    u32 v5;
    func_02022940((struct Quad *)obj, (struct Quad *)&obj->f20, &obj->q10, cfg, cfg + 4, a2);
    k8 = cfg[8];
    z = Z0;
    kb = cfg[0x0b];
    obj->f30 = a4;
    obj->tick = z;
    v5 = *(volatile u32 *)&a5;
    obj->f44 = kb;
    obj->f34 = k8;
    obj->steps = a2;
    obj->period = a3;
    obj->f48 = v5;
    func_02022E20(v5, cfg[9], cfg[0x0a], cfg[8], a4, cfg[0], cfg[1],
                  cfg[2], cfg[3], obj->f44);
}








/*
 * One tick of the wipe object.  +0x40 is a frame counter compared against
 * the step length at +0x3c: until it reaches the step, nothing happens
 * and the answer is 0.  On a step boundary the counter resets and the
 * remaining-step count at +0x38 is decremented; while steps remain the
 * interpolator at +0x10 is advanced (func_0202291C) and the current
 * position is pushed to func_02023D60 with each of the three 1/128
 * fixed-point coordinates at +0x00, +0x04, +0x08 rounded toward zero
 * (`(v + (v >> 6 >> 25)) >> 7`, the compiler's signed /128), plus the
 * 1/128 scalar at +0x0c.  When the last step is used up the object jumps
 * straight to its final values (+0x2c, +0x20, +0x24, +0x28) and answers
 * 1, which is what func_020234C0 waits for.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023568.c \
 *       --func func_02023568 --addr 0x02023568 --cc 1.1p1 --thumb
 */
u32 func_02023568(struct WipeTiles *o)
{
    s32_02023568 n;

    n = o->tick + 1;
    o->tick = n;
    if (n >= o->period) {
        o->tick = 0;
        n = o->steps - 1;
        if (n > 0) {
            o->steps = n;
            func_0202291C((struct Quad *)o, &o->q10);
            goto step;
        }

        func_02023D60((u8 *)o->f48, o->f20, o->f24, o->f28, o->f2c, o->f34,
                      o->f30);
        return 1;

    step:
        func_02023D60((u8 *)o->f48, o->x / 128, o->y / 128, o->z / 128,
                      o->w / 128, o->f34, o->f30);
    }

    return 0;
}









/*
 * cap: the call at +0036 to func_0202368C (0x0202368C) is the only reference
 *      to that address outside its own body, and it is inside this range, so
 *      the `label` class refuses it.  All 76 bytes and the other relocation
 *      site (func_02030734) reproduce exactly.  Promotes to EXACT the moment
 *      func_0202368C has its own manifest entry.
 */
void func_020235F0(struct WinPanel *p, u32 a1)
{
    p->obj = func_02030734((u16)p->heap, 0x38, 0, (const char *)0x020A7450, 0x0D63);
    func_0202368C(p->obj, (const struct Par *)a1, p->f04, p->f08, p->f10, p->f18, p->f1C, p->heap);
    p->phase = p->phase + 1;
}








/*
 *           reproduces (verified with match.py one), the sole unresolved
 *           relocation is the THM_CALL to func_02023768 ((struct Wipe_02022E20 *)(0202363C..0202368C
 *           has no outside witness for it)). func_02023768 itself is a real
 *           DIFF near miss (see docs/notes/func_02023768.c.txt), not an
 *           EXACT/MATCH file, so it cannot supply a "matched" witness and
 *           the two cannot be folded into one tu unit yet.
 *
 * Dispatch on the +0xc mode word of a record: mode 1 closes the record's
 * +0x14 entry (via func_02023768) and, once it reports the entry now empty,
 * frees the pair at entry+0x2c/entry+0x30 through func_02022DCC (with the
 * record's own +0x10 as the third argument) and bumps +0xc, returning 0;
 * mode 2 tears the +0x14 entry down through func_02022D70/func_020307B0,
 * clears +0x14, bumps +0xc and falls into the same "return 1" tail as mode
 * 3 (mode 3 alone has no other side effect); anything else, and mode 1
 * without the entry becoming empty, returns 0.
 */
u32 func_0202363C(struct Rec_020225F0 *r)
{
    void *entry = r->entry;
    u32 result = 0;

    switch (r->mode) {
    case 1:
        if (func_02023768((struct Wipe_02022E20 *)entry) == 1) {
            struct Entry *e = (struct Entry *)entry;
            func_02022DCC(e->f2c, (void *)e->f30, r->f10);
            r->mode = r->mode + 1;
        }
        break;
    case 2:
        func_02022D70(entry);
        func_020307B0(r->entry);
        r->mode = r->mode + 1;
        r->entry = 0;
        result = 1;
        break;
    case 3:
        result = 1;
        break;
    default:
        break;
    }

    return result;
}








void func_0202368C(Ctx *ctx, const Par *par, u32 a2, u32 a3,
                   u32 s5, u32 s6, u32 s7, u32 s8)
{
    u32 t;
    s16 *base;
    u32 off;
    s32_0 w;
    s32_0 h;

    t = func_0202290C(par->f0, par->f2, a2);
    func_02022CEC((u32 *)ctx, par->f8, s5, s8);
    ctx->c = par->f0 << 7;
    ctx->h30 = s6;
    ctx->h10 = par->f4;
    ctx->h14 = par->f6;
    ctx->h18 = t;
    ctx->h1c = a2;
    ctx->h20 = a3;
    ctx->h24 = 0;
    ctx->h34 = s7;
    ctx->h28 = s8;
    ctx->h2c = par->fb;
    func_0202384C((struct Wipe_0202384C *)((struct Wipe_02022E20 *)ctx));
    off = 0x3ff;
    func_020056A0(func_02022D98, ctx, off);
    base = func_02022D88((struct Container_020225F0 *)ctx, 0);
    w = *(s16 *)((char *)base + (off - 0xff));
    off += 0x81;
    h = *(s16 *)((char *)base + off);
    func_02022E20(s6, par->f9, par->fa, par->f8,
                  s5, w, 0, h, 0xc0, ctx->h2c);
    if (par->f8 == 0) {
        func_02022E88((struct Struct_02023CFC *)s6, 1, s5, ctx->h2c);
    } else {
        func_02022E88((struct Struct_02023CFC *)s6, 2, s5, ctx->h2c);
    }
    func_02022518(ctx->h34, (u32)ctx, (u32)func_02022AD0, s5, s8);
}









/*
 * The per-frame poll of the wipe object built at 0x02023464, and the near
 * twin of func_02023A50 at the other end of the family: tick the frame
 * counter at +0x24 against the limit at +0x20, and on expiry step the
 * countdown at +0x1c.  A countdown still above zero advances the running
 * offset at +0x0c by the stride at +0x18, redraws through func_0202384C
 * and re-arms the callback func_02022D98 at priority 0x3FF; a countdown
 * that has reached zero finishes through func_02022568 and is the only
 * path that answers 1.
 *
 * The countdown is decremented into a LOCAL and only stored back on the
 * arm that keeps going: `n = w->left - 1; if (n > 0) { w->left = n; ... }`.
 * Written as a compound `w->left -= 1` followed by a test of the field the
 * store lands before the branch and the `ldr`/`subs`/`cmp` triple at
 * +0x1c..+0x22 becomes four instructions
 * (docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md).
 *
 * Like func_02023A50 this has exactly two exits sharing one `movs r0, #0;
 * pop {r4, pc}` tail, which is what the single trailing `return 0` after
 * the whole nest buys; a `return 0` in each arm duplicates the epilogue
 * (docs/idioms/initialise-the-result-before-the-input-or-every-arm-duplicates-the-return.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023768.c \
 *       --func func_02023768 --addr 0x02023768 --cc 1.1p1 --thumb
 */
u32 func_02023768(struct Wipe_02022E20 *w)
{
    s32_1 f;
    s32_1 n;

    f = w->frame + 1;
    w->frame = f;
    if (f >= w->frame_limit) {
        w->frame = 0;
        n = w->left - 1;
        if (n > 0) {
            w->left = n;
            w->f0c = w->f0c + w->f18;
            func_0202384C((struct Wipe_0202384C *)w);
            func_020056A0((void *)func_02022D98, w, 0x3FF);
        } else {
            func_02022568(w->f34, w->f08, w->f28);
            return 1;
        }
    }

    return 0;
}








/*
 * Compiled to 146 bytes; the listing's inferred 148-byte extent (to
 * 0x0202384C, the next labelled function) runs 2 bytes past what the
 * compiler actually emits here, never a byte difference: EXACT*.
 *
 * Fixed-point vertical-band test: a0/128 (signed division, the classic
 * sign-spread rounding-toward-zero idiom) is a limit compared against the
 * absolute difference of two row indices a2/a3. If the row distance
 * reaches or exceeds the limit, both outputs are zeroed and the function
 * returns immediately (void; the original never sets a return value on
 * either path). If the row distance is inside the limit, the function
 * computes
 * sqrt(round(limit'^2) - round(dist'^2)) where limit' = limit<<12 and
 * dist' = |a3-a2|<<12, each square taken in 64 bit through the compiler's
 * signed multiply helper _ll_mul (contract r0:r1 * r2:r3 -> r0:r1, see
 * docs/idioms/consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md)
 * and each rounded by +0x800 before its own >>12 splice. FX_Sqrt of the
 * difference gives a radius r (already >>12'd back to a plain s32 by the
 * asrs after the call); *out0 = a1 - r (clamped to 0) and
 * *out1 = *out0 + 2*r (clamped to 0xff).
 */
void func_020237B8(s32_1 a0, s32_1 a1, s32_1 a2, s32_1 a3, s32_1 *out0, s32_1 *out1)
{
    s32_1 limit = a0 / 128;
    s32_1 dist = a3 - a2;
    s32_1 r;

    if (dist < 0) {
        dist = -dist;
    }

    if (dist >= limit) {
        *out0 = 0;
        *out1 = 0;
        return;
    }

    {
        s64 sq_limit = (s64)(limit << 12) * (s64)(limit << 12);
        s64 sq_dist  = (s64)(dist  << 12) * (s64)(dist  << 12);
        s32_1 t0 = (s32_1)((sq_limit + 0x800) >> 12);
        s32_1 t1 = (s32_1)((sq_dist  + 0x800) >> 12);

        r = FX_Sqrt(t0 - t1) >> 12;
    }

    *out0 = a1 - r;
    if (*out0 < 0) {
        *out0 = 0;
    }
    *out1 = *out0 + r * 2;
    if (*out1 > 0xff) {
        *out1 = 0xff;
    }
}







/*
 * Rebuilds the wipe's per-scanline window table, one row for each of the
 * screen's 0xC0 lines.  func_02022D88 hands back the buffer whose two s16
 * arrays live at +0x300 (left edge) and +0x480 (right edge).  Inside the
 * band (f14, 2*f14] the pair is mirrored from row 2*f14 - y; everywhere
 * else it is computed through func_020237B8.
 *
 * Two facts closed it (the notes stood at 98 bytes against 104):
 *  - func_020237B8's THIRD argument is w->f14, the value still live in r2
 *    from the band test, not 0.  That was the "re-load" the notes chased.
 *  - The guard is an if / else-if / else chain with the call written out
 *    in BOTH outer arms; mwcc cross-jumps the two copies, leaving the
 *    `bgt` over a `b` at +0x16 and hoisting &l into r7
 *    (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * EXACT* only because the 102-byte body is followed by two bytes of
 * alignment padding before func_020238B4.
 */
void func_0202384C(struct Wipe_0202384C *w)
{
    struct Buf *b;
    s32 y;
    s32 l;
    s32 r;

    y = 0;
    b = func_02022D88((struct Container_020225F0 *)w, 0);

    do {
        if (y <= w->f14) {
            func_020237B8(w->f0c, w->f10, w->f14, y, (s32_1 *)&l, (s32_1 *)&r);
        } else if (y <= w->f14 * 2) {
            l = b->left[w->f14 * 2 - y];
            r = b->right[w->f14 * 2 - y];
        } else {
            func_020237B8(w->f0c, w->f10, w->f14, y, (s32_1 *)&l, (s32_1 *)&r);
        }
        b->left[y] = (s16)l;
        b->right[y] = (s16)r;
        y = y + 1;
    } while (y < 0xC0);
}







/*
 * The constructor of the wipe task whose per-frame step is func_0202390C:
 * it allocates the 0x334-byte sub-object from the task's own heap id,
 * zeroes it, hands the task's five parameter words to func_02023964 and
 * advances the phase.  The sibling of func_02023464 (which builds the
 * 0x4c-byte object at the other end of the family) and of func_020235F0.
 *
 * 0x334 is past every Thumb immediate, and it is needed TWICE (the
 * allocation size and the memset length), so it is materialised once into
 * a callee-saved register (movs #0xcd / lsls #2) and reused rather than
 * spelled at each site; writing it as a literal at both sites costs a pool
 * word.  That is what makes r6 live across the first call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020238B4.c \
 *       --func func_020238B4 --addr 0x020238B4 --cc 1.1p1 --thumb
 */
void func_020238B4(struct WinPanel *t, u32 a1)
{
    t->obj = func_02030734((u16)t->heap, 0x334, 0, (const char *)0x020A7450, 0x1354);
    func_02082BCC(t->obj, 0, 0x334);
    func_02023964(t->obj, (struct Desc *)a1, t->f04, t->f08, t->f10, t->f18, t->f1C,
                  t->heap);
    t->phase = t->phase + 1;
}







/*
 * The per-frame step of a wipe task, the third of the family's four
 * identical phase machines (func_02022A44, func_020234C0, this one and
 * func_020238B4): the same switch over the task's +0x0c, the same
 * sub-object slot at +0x14, the same terminal phase 3.
 *
 * The two far fields at +0x324 and +0x32c are past every Thumb immediate
 * reach, so both are addressed with a register offset built once
 * (movs #0xc9 / lsls #2 = 0x324) and then bumped by 8 for the second
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md); reading them as
 * two separate far offsets would cost a second pool word.
 *
 * THE LEVER, and it is shared with func_02022A44, func_0202390C and
 * func_020234C0 (all three sat at exactly two bytes out until it was
 * found; func_0202363C in src/matched had it right all along and is where
 * it was read from).  Phase 2 assigns the result variable 1 as well,
 * immediately before its `break`:
 *
 *     case 2:  ... t->obj = 0; ret = 1; break;
 *     case 3:  ret = 1; break;
 *
 * The assignment is semantically dead -- the caller re-polls and phase 3
 * answers 1 on the next frame anyway -- but it is what makes phase 2's
 * `break` compile to a branch onto phase 3's own `movs r4, #1` instead of
 * onto the shared tail: the compiler cross-jumps the two identical
 * assignments and phase 2's exit lands on the surviving copy.  Written
 * without it the function is right in every other byte and the one branch
 * displacement is two too large.  Nothing else reaches it: 131 single
 * mutations and 3000 annealing compiles of tools/permuter.py left the
 * residue untouched (it is a cross-jumping decision, not an allocation
 * one), and every other switch spelling tried -- goto into phase 3, a
 * reordered case set, default before case 3, an if/else-if chain, an
 * added empty case -- is the same two bytes out or worse.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202390C.c \
 *       --func func_0202390C --addr 0x0202390C --cc 1.1p1 --thumb
 */
u32 func_0202390C(struct WinPanel *t)
{
    struct WipeScan *obj;
    u32         ret;

    ret = 0;
    obj = t->obj;

    switch (t->phase) {
    case 1:
        if (func_02023A50(obj) == 1) {
            func_02022DCC(obj->f324, (void *)obj->f32c, t->f10);
            t->phase = t->phase + 1;
        }
        break;
    case 2:
        func_02023AAC(obj);
        func_020307B0(t->obj);
        t->phase = t->phase + 1;
        t->obj = 0;
        ret = 1;
        break;
    case 3:
        ret = 1;
        break;
    default:
        break;
    }

    return ret;
}







/*
 * The setup of the 0x334-byte scanline wipe object (struct WipeScan in
 * docs/families/wipe_sub.h): clears it through func_02022EA0, fills both
 * 0xC0-row tables with 1 or 0 by the descriptor's +6 halfword, stamps ten
 * words at +0x30c..+0x330 in the image's (non-ascending) order, installs
 * the scanline callback through func_02022F0C and arms the window.
 *
 * The 2026-09-20 note was two bytes long because it called
 * func_02022F0C(a0, desc, a3): the image passes (a6, w, a7) -- the
 * sp+0x40 and sp+0x44 stack arguments around the object, matching
 * func_02022F0C's own (u32, u8 *, u32) parameter list.  With that call
 * corrected the rest of the note's body compiles byte for byte.
 */
void func_02023964(struct WipeScan *w, struct Desc *d, u32 a2, u32 a3, u32 a4, u32 a5,
                   u32 a6, u32 a7)
{
    func_02022EA0((u8 *)w, a4, 1, 0, 0);

    if (d->f06 == 0) {
        MI_CpuFill8(w->rows[0], 1, 0xC0);
        MI_CpuFill8(w->rows[1], 1, 0xC0);
    } else {
        MI_CpuFill8(w->rows[0], 0, 0xC0);
        MI_CpuFill8(w->rows[1], 0, 0xC0);
    }

    w->f30C = d->f00;
    w->f310 = d->f04;
    w->f324 = d->f06;
    w->f328 = a7;
    w->step_bound = a2;
    w->step = 0;
    w->frame_limit = a3;
    w->frame = 0;
    w->f32c = a5;
    w->f330 = a6;

    func_02022F0C(a6, (u8 *)w, a7);

    if (d->f06 == 1) {
        func_02022E20(a5, 0x20, 0x3F, 0, a4, 0, 0, 0, 0, d->f06);
    } else {
        func_02022E20(a5, 0x3F, 0x20, 0, a4, 0, 0, 0, 0, d->f06);
    }

    func_02022E88((struct Struct_02023CFC *)a5, 1, a4, w->f324);
}





/*
 * The per-frame poll of the 0x334-byte wipe object built by
 * func_020238B4: it ticks the frame counter at +0x320 against the frame
 * limit at +0x31c, and on expiry advances the step index at +0x318
 * against the bound at +0x314.
 *
 * THE COMPARISON IS `<=`, NOT `>`, and it is the function's only real
 * decision.  Written `if (w->step + 1 > w->step_bound)` the function is
 * 92 bytes with every other byte right and ONE wrong: the branch at
 * +0x2a comes out `ble` where the image has `bgt`.  The image branches to
 * the redraw block when step+1 is GREATER than the +0x314 bound, so the
 * fall-through -- the source's first arm -- is the `<=` case, which is
 * the one that calls func_02023AB0/func_02022EF4 and answers 0
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  That makes
 * +0x314 a floor rather than a ceiling: the object is retired while the
 * step index is still inside it and keeps redrawing once it is past,
 * which reads backwards until you notice func_02023AB0 is what pushes
 * the NEXT step in, so "inside the bound" here means "there is another
 * step to load".
 *
 * Every field is past the Thumb immediate reach, so the whole group is
 * addressed off ONE register offset (movs #0x32 / lsls #4 = 0x320) that
 * the compiler then bumps by -4, -8, -0xc and +0x10 per access
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  Declaring the
 * fields as members of one struct is what keeps that single base; four
 * separate far offsets would each cost their own pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023A50.c \
 *       --func func_02023A50 --addr 0x02023A50 --cc 1.1p1 --thumb
 */
u32 func_02023A50(struct WipeScan *w)
{
    s32 f;

    f = w->frame + 1;
    w->frame = f;
    if (f >= w->frame_limit) {
        w->frame = 0;
        if (w->step + 1 <= w->step_bound) {
            w->step = w->step + 1;
            func_02023AB0(w);
            func_02022EF4(w);
        } else {
            func_02022F24(w->f330, (u8 *)w, w->f328);
            return 1;
        }
    }

    return 0;
}





void func_02023AAC(void *obj){ }





/*
 * cap: the only call site of func_02023AF4 (0x02023AF4) inside the image is at
 *      0x02023ADA, which is inside this function, so the `label` class refuses
 *      it (no witness outside 02023AB0..02023AF2).  Every byte reproduces:
 *      the listing extent reads 68 only because of two bytes of 00 00 padding
 *      at 0x02023AF2; the code is 66.  Promotes to EXACT the moment
 *      func_02023AF4 has its own manifest entry.
 */
void func_02023AB0(struct WipeScan *p)
{
    int i;

    for (i = 0; i < p->f310; i++) {
        func_02023AF4((u8 *)(p->f30C + i * 4), (u8 *)p,
                      p->step,
                      p->step_bound);
    }
}





/*
 * Paints the run [min(lo,hi), max(lo,hi)) of the 0xC0-byte row table at
 * out+0xC0 with a two-tone pattern: the starting value is the descriptor's
 * +2 halfword when lo <= hi and its logical inverse when the bounds are
 * swapped, and the value flips once at split = (hi - lo) * num / den + lo.
 *
 * The notes' four-register rotation (near in r2 against the image's r7,
 * 13 bytes over eleven spellings and both compilers) came from writing the
 * flip with two HAND-HOISTED constant locals `one`/`zero` and a while
 * loop.  Written plainly -- `near = near == 0` in a for loop, the else
 * arm as `flag == 0` -- mwcc hoists the two constants itself, numbers
 * `near` after the loop's address temporary, and the whole function is
 * byte-exact.  The inline-helper spelling (`if (v == 0) return 1;
 * return 0;`) and `v ? 0 : 1` compile identically.  The bounds are still
 * unsigned (`bhi`), the lo <= hi arm still comes first, and the split is
 * still `q + lo` with q a named local.
 *
 * EXACT* only because the 82-byte body is followed by a two-byte pad.
 */
void func_02023AF4(u8 *desc, u8 *out, s32 num, s32 den)
{
    u32 lo = desc[0];
    u32 hi = desc[1];
    s32 q = (s32)(hi - lo) * num / den;
    s32 split = q + lo;
    s32 i;
    s32 end;
    s32 near;

    if (lo <= hi) {
        i = lo;
        end = hi;
        near = *(u16 *)(desc + 2);
    } else {
        i = hi;
        end = lo;
        near = *(u16 *)(desc + 2) == 0;
    }

    for (; i < end; i++) {
        if (i == split)
            near = near == 0;
        out[0xc0 + i] = near;
    }
}





void func_02023B48(u32 val, u32 engine)
{
    if (engine == 0) {
        REG_DISPCNT = (REG_DISPCNT & 0xffff1fff) | (val << 13);
    } else {
        REG_DISPCNT_SUB = (REG_DISPCNT_SUB & 0xffff1fff) | (val << 13);
    }
}






/*
 * Merge bits into one of the two DS display-control halfwords.  a2 picks the
 * register bank (0x04000048 or the 0x04001048 engine-2 twin), a3 picks which
 * six-bit field: the low one (mask ~0x3f, source bit 0, extra bit 0x20) or
 * the middle one (mask ~0x3f00, source aligned to bit 8, extra bit 0x2000).
 * Both registers are read-modify-written as volatile halfwords.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023B74.c \
 *       --func func_02023B74 --addr 0x02023B74 --cc 1.1p1 --thumb
 */
void func_02023B74(u32 a0, u32 a1, u32 a2, u32 a3)
{
    if (a2 == 0) {
        if (a3 == 0) {
            u32 v = *(volatile u16 *)0x04000048;

            v = (v & ~0x3f) | a0;
            if (a1 != 0) {
                v |= 0x20;
            }
            *(volatile u16 *)0x04000048 = v;
        } else {
            u32 v = *(volatile u16 *)0x04001048;

            v = (v & ~0x3f) | a0;
            if (a1 != 0) {
                v |= 0x20;
            }
            *(volatile u16 *)0x04001048 = v;
        }
    } else {
        if (a3 == 0) {
            u32 v = *(volatile u16 *)0x04000048;

            v = (v & ~0x3f00) | (a0 << 8);
            if (a1 != 0) {
                v |= 0x2000;
            }
            *(volatile u16 *)0x04000048 = v;
        } else {
            u32 v = *(volatile u16 *)0x04001048;

            v = (v & ~0x3f00) | (a0 << 8);
            if (a1 != 0) {
                v |= 0x2000;
            }
            *(volatile u16 *)0x04001048 = v;
        }
    }
}






void func_02023BFC(u32 a, u32 flag, u32 engine)
{
    u32 val;

    if (engine == 0) {
        val = (REG_BLDCNT & ~0x3f) | a;
        if (flag != 0) {
            val |= 0x20;
        }
        REG_BLDCNT = (u16)val;
    } else {
        val = (REG_BLDCNT_SUB & ~0x3f) | a;
        if (flag != 0) {
            val |= 0x20;
        }
        REG_BLDCNT_SUB = (u16)val;
    }
}






/*
 * Window-bounds setter: picks one of the four window-bounds register
 * pairs (WIN0H/WIN0V and WIN1H/WIN1V, each in the main or the sub
 * engine) and writes the packed horizontal and vertical limits.
 *
 * The four bodies are textually identical in the original, which is why
 * the value expressions are repeated in each arm rather than hoisted:
 * a shared pair of locals computes once and costs 24 bytes less than the
 * image.  The second halfword is one register plus #4, so each arm holds
 * a pointer to the base register and indexes it [0] and [2]; spelling
 * both addresses absolutely puts two pool words per arm in the image
 * where the original has one.
 *
 * The leading argument shuffle (r4 <- r2, r2 <- r3) is the fourth
 * argument's register being recycled for the fifth.
 */
void func_02023C3C(u32 x2, u32 y2, u32 x1, u32 y1, int win, int sub)
{
    if (win == 0) {
        if (sub == 0) {
            u16 *p = (u16 *)0x04000040;
            p[0] = (x2 << 8 & 0xff00) | (x1 & 0xff);
            p[2] = (y2 << 8 & 0xff00) | (y1 & 0xff);
        } else {
            u16 *p = (u16 *)0x04001040;
            p[0] = (x2 << 8 & 0xff00) | (x1 & 0xff);
            p[2] = (y2 << 8 & 0xff00) | (y1 & 0xff);
        }
    } else {
        if (sub == 0) {
            u16 *p = (u16 *)0x04000042;
            p[0] = (x2 << 8 & 0xff00) | (x1 & 0xff);
            p[2] = (y2 << 8 & 0xff00) | (y1 & 0xff);
        } else {
            u16 *p = (u16 *)0x04001042;
            p[0] = (x2 << 8 & 0xff00) | (x1 & 0xff);
            p[2] = (y2 << 8 & 0xff00) | (y1 & 0xff);
        }
    }
}






void func_02023CFC(struct Struct_02023CFC *table, void *val, u32 idx)
{
    struct Struct_02023CFC *entry = &table[idx];

    entry->val = val;
    entry->idx = idx;
    func_020056A0(func_02023D94, entry, 1);
}





void func_02023D18(void *obj, void *val, u32 f4, u32 f8, u32 fC)
{
    struct Item_02023D18 *entry = (struct Item_02023D18 *)((u8 *)obj + 0x10 + (fC << 5) + (f8 << 4));

    entry->val = val;
    entry->field_4 = f4;
    entry->field_8 = f8;
    entry->field_C = fC;
    func_020056A0(func_02023DA8, entry, 1);
}





void func_02023D40(void *obj, void *val, u32 f4, u32 f8)
{
    struct Item_02023D40 *entry = (struct Item_02023D40 *)((u8 *)obj + 0x68 + f8 * 12);

    entry->val = val;
    entry->field_4 = f4;
    entry->field_8 = f8;
    func_020056A0(func_02023DC4, entry, 1);
}





void func_02023D60(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    struct Rec_02023964 *r = (struct Rec_02023964 *)(p + 0x80 + f * 32 + e * 16);

    r->f0 = a;
    r->f2 = b;
    r->f4 = c;
    r->f6 = (u16)d;
    r->f8 = e;
    r->fC = f;
    func_020056A0(func_02023DDC, r, 1);
}





/*
 * The two-field member of the func_02023DC4/func_02023DA8 forwarder family:
 * unpack the two words of `args` as positional arguments to
 * func_02023B48, then tail-call func_02030EAC on the first argument and
 * return its result. `ldm r1, {r0, r1}` is the two-word load; a plain
 * struct-by-value copy or two separate field reads through the pointer
 * both produce the same pair of loads once the fields are consecutive
 * words read in order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023D94.c \
 *       --func func_02023D94 --addr 0x02023D94 --cc 1.1p1 --thumb
 */
u32 func_02023D94(void *obj, struct Args2 *args)
{
    func_02023B48(args->f0, args->f4);
    return func_02030EAC(obj);
}





/*
 * The four-field member of the func_02023DC4/func_02023D94 forwarder
 * family: unpack the four words of `args` as positional arguments to
 * func_02023B74, then tail-call func_02030EAC on the first argument and
 * return its result.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023DA8.c \
 *       --func func_02023DA8 --addr 0x02023DA8 --cc 1.1p1 --thumb
 */
u32 func_02023DA8(void *obj, struct Args4 *args)
{
    func_02023B74(args->f0, args->f4, args->f8, args->fC);
    return func_02030EAC(obj);
}





/*
 * A three-field struct forwarder: unpack the three words of `args` as
 * positional arguments to func_02023BFC, then tail-call the ARM function
 * func_02030EAC on the first argument and return its result. The `blx`
 * is the interworking call the linker rewrites a Thumb `bl` into.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023DC4.c \
 *       --func func_02023DC4 --addr 0x02023DC4 --cc 1.1p1 --thumb
 */
u32 func_02023DC4(void *obj, struct Args3 *args)
{
    func_02023BFC(args->f0, args->f4, args->f8);
    return func_02030EAC(obj);
}





void func_02023DDC(void *a0, struct Rec_02023964 *a1)
{
    func_02023C3C(a1->f0, a1->f2, a1->f4, a1->f6, a1->f8, a1->fC);
    func_02030EAC(a0);
}





/*
 * wipe_sub.c: the per-frame step of the brightness/blend interpolation
 * record that func_02023E9C arms (docs/families/wipe_sub.h, struct Interp).
 * It advances the record's running position f1a towards the target f0a by
 * the per-step delta f14 scaled by the sign f10, pushes the result to the
 * hardware register of whichever engine the f04 bit mask selects, and
 * clears the active flag f1c once the target is reached.
 *
 * FOUR SPELLINGS ARE LOAD-BEARING.  The earlier note
 * (docs/notes/pkt_02023E0C.c.txt) read this function as a whole-function
 * register permutation the allocator would not move; it is not.  It is
 * four shape decisions, and with them the allocation falls out on its own.
 * The note's own draft is 140 bytes against 144 with 127 concrete bytes
 * out; each of the four below is worth a measured step:
 *
 *   1. THE TWO POINTER LOCALS ARE HOISTED to the top of the else arm,
 *      before the f18 accumulate and its test, not created inside the
 *      inner `if`.  This is the whole four-byte size gap: the image emits
 *      `adds r3, r4, #0 / adds r2, r4, #0 / adds r3, #0x1a / adds r2,
 *      #0x18` unconditionally on the else path.  127 bytes out -> 76.
 *
 *   2. THE MULTIPLY IS `step * p->f14`, not `p->f14 * step`.  The image's
 *      `muls r1, r0, r1` keeps `step` in the accumulator, and the
 *      accumulator holds the chain's SECOND operand
 *      (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-
 *      operand.md).  24 bytes out -> 19.
 *
 *   3. BOTH `if`s ARE WRITTEN WITH THE NEGATED CONDITION, so the arm the
 *      image falls through into is the source's first
 *      (docs/idioms/the-fall-through-arm-is-the-source-order.md).  The
 *      outer one is `if (target != cur + v && cur != target) { <advance> }
 *      else { <snap to target> }`, and the inner one is `if (p->f1a !=
 *      target) { <decrement the timer> } else { flag = 1; }`.  Written the
 *      other way round the image's two `beq` to one target come out as a
 *      `beq`/`bne` pair and everything after shifts by one instruction.
 *      76 -> 24 for the outer, 19 -> 8 for the inner.
 *
 *   4. `cur` IS A NAMED LOCAL read BEFORE `target`.  This is the last
 *      eight bytes.  The image loads f1a (offset 0x1a) and only then f0a
 *      (offset 0xa); with `p->f1a` left inline in the condition the
 *      compiler evaluates `target = p->f0a` first and the two `movs
 *      #imm`/`ldrsh` pairs come out in the other order.  Binding the f1a
 *      read to its own local ahead of `target` pins it
 *      (docs/idioms/cmp-operand-order-names-the-temporary.md is the same
 *      tell).  8 -> 0.
 *
 * Statement order of `flag = 0` is NOT a lever: first, second, third and
 * fourth position all compile identically (the compiler sinks the zero to
 * where the image has it, `movs r7, #0` after the two loads).  That was
 * measured, not assumed.
 *
 * Two further facts confirming the earlier note's structural reads, which
 * did survive: the two entry tests really are one `||` (here written as
 * the negated `&&`), and the f1a store is `p->f1a + (s16)v` so the
 * truncation is on the delta and not on the sum -- the image's `lsls
 * r1,r1,#0x10 / asrs r1,r1,#0x10` narrows v alone.  The engine register
 * words are the plain constants 0x04000050 and 0x04001050; the second is
 * NOT 0x04001000 + 0x50 computed at run time, as src/pending/
 * func_02023EF4.c's header already records for the sibling.
 *
 * The two arms of the engine select tail-merge onto one call site, which
 * is what the image's shared `movs r2,#0x1a / ldrsh / ldr r1,[r4] / blx`
 * at +0x74 is; writing the two calls out in full is what produces it
 * (docs/idioms/switch-arms-tail-merge.md).
 *
 * Nothing here is version specific: 0x04000050 and 0x04001050 are DS
 * hardware register addresses and every other constant is a field offset
 * or a flag bit.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02023E0C.c \
 *       --func func_02023E0C --addr 0x02023E0C --cc 1.1p1 --thumb
 */
void func_02023E0C(struct Interp *p)
{
    s8  step;
    int v;
    s16_0 target;
    int flag;
    u16 *timer;
    s16_0 *pos;
    s16_0 cur;

    step = p->f10;
    v = step * p->f14;
    cur = p->f1a;
    target = p->f0a;
    flag = 0;
    if (target != cur + v && cur != target) {
        p->f1a = p->f1a + (s16_0)v;
        pos = &p->f1a;
        timer = &p->f18;
        p->f18 = p->f18 + p->f16;
        if ((u16)p->f18 >= (u16)p->f08) {
            *pos = (s16_0)*pos + step;
            if (p->f1a != target) {
                *timer = *timer - p->f08;
            } else {
                flag = 1;
            }
        }
    } else {
        p->f1a = target;
        flag = 1;
    }
    if (p->f04 & 1) {
        func_0207D658((u32)((void *)0x04000050), p->f00, p->f1a);
    } else if (p->f04 & 2) {
        func_0207D658((u32)((void *)0x04001050), p->f00, p->f1a);
    }
    if (flag == 1)
        p->f1c = 0;
}





/*
 * Initialises the 0x20-byte interpolation record the packet's other two
 * functions drive. The two stack arguments are widened through the usual
 * lsls/lsrs #0x18 pair into the full words at +0x00 and +0x04, so they are
 * int-typed parameters narrowed with a (u8) cast, not u8 parameters.
 *
 * Field roles: f08 = step count, f0a = from, f1a = to, f12 = |to - from|,
 * f10 = the sign (+1 or -1), f14 = per-step delta, f16 = its remainder,
 * f18 = the running accumulator (cleared here), f1c = the active flag.
 *
 * Three spellings are load-bearing and were each isolated against the
 * bytes:
 *   - `p->f1C = 1;` must be the FIRST statement. The constant 1 has to
 *     land in r0 before the two stack arguments are widened; written
 *     anywhere later in the block the allocator promotes it to r6 and the
 *     whole entry block shifts register bank (19 and 14 bytes wrong for
 *     the two later positions tried).
 *   - the negation re-reads the field: the original is `ldrsh` + `subs
 *     r1,#0x13` + `muls`, four bytes more than the `rsbs` the compiler
 *     folds from a cached value. The volatile-qualified read is what
 *     defeats that fold; without it the function compiles 84 bytes, not
 *     88. The `-1` multiplier and the `-1` stored to f10 in the other arm
 *     share one register, derived from the 0x12 field offset.
 *   - `/` and `%` on the same operands are two separate _s32_div_f calls
 *     (docs/idioms/div-and-mod-are-two-calls.md); f14 takes the quotient
 *     from r0 and f16 the remainder from r1.
 */
void func_02023E9C(struct Interp *p, u16 steps, s16_02023E9C from, s16_02023E9C to,
                   u32 a4, u32 a5)
{
    p->f1c = 1;
    p->f00 = (u8)a4;
    p->f04 = (u8)a5;
    p->f12 = to - from;
    p->f08 = steps;
    p->f1a = to;
    p->f0a = from;

    if (p->f12 > 0) {
        p->f10 = -1;
    } else {
        p->f10 = 1;
        p->f12 = *(volatile s16_02023E9C *)&p->f12 * -1;
    }

    p->f14 = p->f12 / steps;
    p->f16 = p->f12 % steps;
    p->f18 = 0;
}














/*
 * Front end for func_02023E9C: given a record pointer and a two-bit engine
 * mask, it arms the record once per selected engine. Each arm first sets
 * the hardware blend-brightness register for that engine to the starting
 * value through G2x_SetBlendBrightness_ (0x0207D658), then calls
 * func_02023E9C with the shared step/from/to triple and the two stack
 * arguments (the starting value, and the engine bit itself as the tag).
 *
 * The two pool words 0x04000050 and 0x04001050 are the main and sub
 * engine's BLDCNT/BLDY block; both arms are written out in full rather
 * than factored behind a helper, which is what keeps them as two separate
 * call sequences rather than one tail-merged site.
 *
 * Note the second engine's register word is the plain constant 0x04001050
 * in the pool, not 0x04000050 + 0x1000 computed at run time.
 *
 * RESOLVED 2026-09-21 (wave3 wipe_sub). This file sat in src/pending at
 * MATCH with the note below blaming a missing `literal` witness for the two
 * ABS32 pool words. The blocker was not evidentiary: the symbols block named
 * the tables at 0x0202691C and 0x020268FC, but the ROM pool words at
 * 0x02023F54 and 0x02023F5C are 0x0214691C and 0x021468FC. Because a MATCH
 * wildcards the relocation field, the wrong address was never compared and
 * the typo read as an attestation failure. With the real addresses both
 * sites resolve as `literal` (6 and 12 witnesses image-wide, e.g. the pool
 * words at 0x02023FCC and 0x02023FD0 in the neighbouring unit) and the
 * function is EXACT. Earlier prose, kept for the record:
 *
 * [stale] capped at MATCH; blocking evidence class literal; neither word
 * appears in any literal pool at another address. -- wrong on both counts,
 * see above.
 *
 * Both engines pass the same record pointer p to func_02023E9C; the first
 * argument is the engine's own descriptor table, and the last argument is
 * the engine bit (1 or 2), which func_02023E9C stores to f04.
 *
 * G2x_SetBlendBrightness_ takes three arguments (addr, plane, brightness)
 * and both arms pass all three. The first arm emits no `mov r2` because
 * `from` is still live in r2 from entry; the second arm reloads it from r6
 * after the intervening call. An earlier spelling declared a two-argument
 * extern for the first arm, which matched the bytes but left r2 unnamed
 * (docs/idioms/an-argument-passed-through-a-register-must-be-named-in-the-c.md).
 */
void func_02023EF4(u16 steps, s16 from, s16 to, u32 plane, u32 mask)
{
    if (steps == 0) {
        return;
    }

    if (mask & 1) {
        G2x_SetBlendBrightness_(0x04000050, plane, to);
        func_02023E9C(&g_wipe_main, steps, from, to, plane, 1);
    }

    if (mask & 2) {
        G2x_SetBlendBrightness_(0x04001050, plane, to);
        func_02023E9C(&g_wipe_subrec, steps, from, to, plane, 2);
    }
}














void func_02023F60(u32 a0, u32 a1, u32 mask)
{
    if (mask & 1) {
        func_0207D658(0x04000050, a1, a0);
    }
    if (mask & 2) {
        func_0207D658(0x04001050, a1, a0);
    }
    func_02023F98(mask);
}














/*
 * The teardown counterpart of func_02023EF4: given the same two-bit engine
 * mask, it zeroes each selected engine's 0x20-byte blend record and clears
 * that engine's active flag.  Main engine's record is at 0x0214691C and its
 * flag at 0x021468FC+0x3c; the sub engine's record is at 0x021468FC+0x20
 * and its flag at 0x021468FC+0x1c.  The two arms are written out in full.
 *
 * THE POOL HAS A DUPLICATE OF 0x021468FC, AND WHICH USES SHARE A SLOT IS
 * THE WHOLE FINDING.  The three pool words are
 *
 *     0x02023FCC  .word 0x0214691C     <- arm 1's memset base
 *     0x02023FD0  .word 0x021468FC     <- BOTH flag stores
 *     0x02023FD4  .word 0x021468FC     <- arm 2's memset base
 *
 * mwccarm emits one pool word per source SYMBOL, in order of first use, so
 * the slot count and the sharing pattern read straight back as the number of
 * distinct externs and which statements name which.  The obvious spelling --
 * one `g_wipe_sub` at 0x021468FC for all three of its uses -- CSEs the two
 * 0x021468FC references into one slot, and the third slot then re-emits
 * 0x0214691C: 64 bytes, every instruction right, two bytes out at 0x02023FD4
 * and nothing any amount of statement shuffling reaches (63 single mutations
 * and a full permuter.py hill pass left it untouched, because it is a pool
 * layout decision, not an allocation one).
 *
 * What reproduces it is TWO distinct externs at 0x021468FC, split along the
 * image's own sharing: `g_wipe_flags` names the object both arms' flag stores
 * reach (+0x3c for main, +0x1c for sub, one slot between them) and
 * `g_wipe_subrec` names the one arm 2 memsets (its own slot).  Whether the
 * original really had two objects at one address or one object the compiler
 * saw through two declarations is not decidable from the bytes; what the
 * bytes do fix is that three source-level names were in play, not two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023F98.c \
 *       --func func_02023F98 --addr 0x02023F98 --cc 1.1p1 --thumb
 */
void func_02023F98(u32 mask)
{
    if (mask & 1) {
        func_02082BCC(&g_wipe_main, 0, 0x20);
        g_wipe_flags[1].f1c = 0;
    }
    if (mask & 2) {
        func_02082BCC(&g_wipe_subrec, 0, 0x20);
        g_wipe_flags[0].f1c = 0;
    }
}














/*
 *           outside 02023FD8..02024004; the only two branches to it in the
 *           image are these two
 *
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * All 44 concrete bytes (30 of code, then three literal words) reproduce
 * exactly.  The listing extent is 108 because the next labelled start in
 * asm/arm9/src/008_02021014.s is 0x02024044; the 64 bytes between are the
 * unlabelled function at 0x02024004 and its pool, so the entry also carries
 * the `*` of a listing-extent mismatch.  The worklist size is 32 code bytes.
 *
 * Two guards on a global struct: the word at +0x3C first, then the word at
 * +0x1C, each calling func_02023E0C with a global address when it is set.
 *
 * The pool is THREE words and the first and third hold the same address
 * 0x021468FC.  mwccarm emits a pool word per source symbol, so a source that
 * reached the same object through one name would have CSEd the two loads into
 * one slot and one register (which is what the obvious spelling does: it
 * compares the field in r1 and reuses r0 for the call argument, 40 bytes).
 * The original loads the base twice, from two slots, so it is written here
 * with two names for the one address, g_021468FC for the field base and
 * g2_021468FC for the second call's argument.  That is the whole difference
 * between DIFF and MATCH here; both declarations are the same claim and both
 * are attested `literal` from outside (x6 from 0x02023F5C and friends).
 *
 * It cannot reach EXACT while func_02023E0C is unfiled: 0x02023E0C is
 * labelled in the listings but every branch to it image-wide is one of these
 * two, so the `label` class has no witness outside the compared range.  It
 * closes the day 0x02023E0C gets a manifest entry (a large function outside
 * the 0-64 byte band, so not this lane's work), and that also releases
 * src/pending/func_020052EC.c, whose first site names this address.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02023FD8.c \
 *       --func func_02023FD8 --addr 0x02023FD8 --cc 1.1p1 --thumb
 */
void func_02023FD8(void)
{
    if (g_wipe_flags[1].f1c != 0) {
        func_02023E0C(&g_wipe_main);
    }
    if (g_wipe_flags[0].f1c != 0) {
        func_02023E0C(&g_wipe_subrec);
    }
}














/*
 * Unlabelled Thumb leaf (no prologue, so disasm.py prints the run as ARM
 * data). A three-way guard on the object at 0x021468FC: mode 3 needs both
 * the +0x3C and +0x1C words clear, mode 1 only +0x3C, mode 2 only +0x1C;
 * anything else returns 0. The pointer is loaded from the pool word at
 * 0x02024040.
 *
 * Addresses are Black-image addresses.
 */
int func_02024004(int a)
{
    if (a == 3) {
        if (g_wipe_flags[1].f1c == 0 && g_wipe_flags[0].f1c == 0)
            return 1;
    } else if (a == 1) {
        if (g_wipe_flags[1].f1c == 0)
            return 1;
    } else if (a == 2) {
        if (g_wipe_flags[0].f1c == 0)
            return 1;
    }
    return 0;
}












/*
 * pmsi_param.c's constructor (the __FILE__ anchor at 0x020A745C reads
 * "pmsi_param.c", line 0x56).  Allocates the 0x20-byte parameter object,
 * hangs two sub-objects off it, seeds the flag byte at +3 and then takes
 * one of two initialisation paths on `kind`.
 *
 * Four spellings are load-bearing and each was isolated against the bytes:
 *   - `hh` is a u32 parameter narrowed by an EXPLICIT (u16) cast at the
 *     allocator call.  A u16 parameter gives `ldrh` at +0x08 where the
 *     original loads a full word and narrows with lsls/lsrs #0x10.
 *   - func_020142E8 returns u32 and the result is narrowed by an explicit
 *     (u8) cast before the bitfield store.  Declaring the return u8 folds
 *     the `lsls #0x18 / lsrs #0x18` pair away and loses 4 bytes.
 *   - `flag` is likewise u32 with an explicit (u8) cast into the bitfield:
 *     the original's `lsls r2,r7,#0x18 / lsrs r2,r2,#0x18` is that cast,
 *     and the following `lsls #0x1f / lsrs #0x1c` is the 1-bit bitfield at
 *     bit 3 (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *   - 0x02082D44 is called (src, dest, size), i.e. MI_CpuCopy8's order, not
 *     memcpy's: the original loads r0 from `src` and r1 from `o + 0x10`.
 *     Spelling it memcpy(dst, src, n) swaps r0/r1 and costs two bytes.
 *
 * `o->b0 = ...` and `o->b1 = 0` must stay two separate bitfield writes
 * (bics/orrs then bics), not a folded mask.
 *
 * EXACT*: the inferred extent runs to 344 bytes because the follower at
 * 0x020240F4 is the unlabelled 8-byte thunk func_020240FC and the run of
 * unlabelled leaf accessors after it (they save no lr, so disasm.py never
 * labels them).  The compiled 184 bytes are byte-identical.  Unlabelled
 * follower to seed into layout/function_starts.txt: 0x020240F4.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02024044.c \
 *       --func func_02024044 --addr 0x02024044 --thumb --cc 1.1p1
 */
struct Obj_02023EF4 *func_02024044(u32 kind, u32 a1, void *src, u32 flag,
                          void *sys, u32 hh)
{
    struct Obj_02023EF4 *o;
    s32_02023EF4 i;

    o = (struct Obj_02023EF4 *)func_02030734((u16)hh, 0x20, 1, (const char *)file_020A745C, 0x56);
    o->kind = (u8)kind;
    o->f08 = func_020071CC(sys, 0x37);
    o->f0c = func_02024988(sys);
    o->b0 = (u8)func_020142E8((void *)func_02012FE4(sys), 0x960);
    o->b1 = 0;
    o->f01 = 1;
    o->f02 = 0;
    o->b3 = (u8)flag;
    if (kind == 2) {
        if (src == 0) {
            func_020242A4(o->slot, 0);
        } else {
            MI_CpuCopy8(src, o->slot, 8);
            o->b2 = 1;
        }
    } else {
        for (i = 0; i < 2; i++) {
            o->f18[i] = 0xFFFF;
        }
    }
    return o;
}











/*
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x020307B0, the callee's
 * address with its low bit clear, i.e. an ARM target (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020240FC.c \
 *       --func func_020240FC --addr 0x020240FC --thumb --cc 1.1p1
 */
void func_020240FC(void *t)
{
    func_020307B0(t);
}










void func_02024104(u16 *p, u16 v)
{
    p[0xC] = v;
}









void func_02024108(u16 *dst, const u16 *src)
{
    dst[8] = src[0];
    dst[9] = src[1];
    dst[10] = src[2];
    dst[11] = src[3];
}











/*
 * Unlabelled Thumb leaf accessor: byte at +1.
 */
int func_0202411C(unsigned char *p)
{
    return p[1];
}











/*
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 */
int func_02024120(u8 *p) { return p[2]; }











/*
 * Unlabelled Thumb leaf accessor: halfword at +0x18.
 */
unsigned int func_02024124(unsigned short *p)
{
    return p[12];
}












/*
 * Unlabelled Thumb leaf accessor: copy the halfwords at +0x18 and +0x1a to out. __restrict on out makes both loads precede both stores.
 */
void func_02024128(struct Src02024128 *p, unsigned short *__restrict out)
{
    out[0] = p->a;
    out[1] = p->b;
}









/*
 * Unlabelled Thumb tail-call thunk: func_02024570(b, a + 0x10), where func_02024570 copies a halfword pair.
 */
void func_02024134(char *a, void *b)
{
    func_02024570(b, (const struct Rec8 *)(a + 0x10));
}









u32 func_02024144(const u8 *p) { return p[0]; }









void *func_02024148(char *p){return *(void **)(p+8);}









void *func_0202414C(char *p){return *(void **)(p+12);}









int func_02024150(Bits_02024150 *p){return p->flag;}










/*
 * Unlabelled Thumb leaf in the ARM9 module: extracts bit 2 of the byte at
 * +3. Pairs with func_02024160, which extracts bit 3.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02024158(const u8 *p)
{
    return ((u32)*(const u8 *)&((struct Obj15744 *)p)->f3 << 29) >> 31;
}









int func_02024160(Bits_02024160 *p){return p->flag;}









void func_02024168(const Input *p,u16 *a,u16 *b) {
    Pair v;
    switch(p->mode) {
    case 0: a[0]=p->values18[0]; break;
    case 1:
        v=*(const Pair *)p->values18; *(Pair *)a=v; break;
    case 2:
        b[0]=p->values10[0]; b[1]=p->values10[1];
        v=*(const Pair *)(p->values10+2); *(Pair *)(b+2)=v; break;
    }
}










u32 func_0202419C(struct Obj_0202411C *p, u16 *q, u32 a)
{
    switch (p->f0) {
    case 0:
        if (*q == p->f18) {
            return 1;
        }
        return 0;
    case 1:
        if (q[0] == p->f18 && q[1] == p->f1A) {
            return 1;
        }
        return 0;
    case 2:
        break;
    }

    return func_02024534((const struct Data *)((u8 *)p + 0x10), (const struct Data *)a);
}









void func_020241E0(struct T *p, u16 *a1, u16 *a2)
{
    int i;

    p->f02 = (func_0202419C((struct Obj_0202411C *)p, a1, (u32)a2) == 0);
    p->f01 = 0;
    for (i = 0; i < 2; i++) {
        *(u16 *)((char *)p + i * 2 + 0x18) = a1[i];
    }
    p->f10 = a2[0];
    p->f12 = a2[1];
    p->f14 = a2[2];
    p->f16 = a2[3];
}







/*
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x020355C4, the callee's
 * address with its low bit clear, i.e. an ARM target (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202421C.c \
 *       --func func_0202421C --addr 0x0202421C --thumb --cc 1.1p1
 */
void func_0202421C(void)
{
    unit_020355C4();
}








void func_02024224(void *a,void *b) { func_020355D8(b); }









/*
 * pmsi_param.c: fill out[0..count) with amp * sin(phase), phase advancing
 * by step through 16 bits.  The table is FX_SinCosTable_ at 0x020A1B38
 * (sin/cos s16 pairs, hence the stride of two halfwords: the SDK's
 * FX_SinIdx); the old notes misread the pool word as 0x02021B38.
 *
 * The last byte of docs/notes/func_02024230.c.txt was the phase type: it is
 * a plain u16.  The wrap is then `lsrs` (u16 narrowing) and the index is
 * still `asrs` because the u16 promotes to int before the shift.  The s64
 * temporary for the widened table value is the permuter's find from wave 5.
 */
void func_02024230(s16 *out, u32 count, u16 step, s32_02024230 amp)
{
    u32 i;
    u16 phase;

    phase = 0;
    i = 0;
    while (i < count) {
        s64 v = (s64)tbl_020A1B38[(phase >> 4) * 2];
        s64 prod = v * (s64)amp;

        out[i] = (s16)((s32_02024230)((prod + 0x800) >> 12) >> 12);
        i++;
        phase = (u16)(phase + step);
    }
}









/*
 * A slot-clearing sibling of func_020242A4 (src/matched/func_020242A4.c):
 * the same three-halfword sentinel fill, but the leading id field is
 * also set to the sentinel instead of taking a caller-supplied id, so
 * there is no second parameter. The loop counter is signed, the same
 * `blt` tell as the sibling function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202428C.c \
 *       --func func_0202428C --addr 0x0202428C --cc 1.1p1 --thumb
 */
void func_0202428C(void *obj)
{
    u16 *p = (u16 *)obj;
    s32_0202428C i;

    p[0] = 0xFFFF;
    for (i = 0; i < 2; i++) {
        p[i + 2] = 0xFFFF;
    }
}









/*
 * The common slot initialiser shared by func_02024344 and the four arms of
 * func_020242D8 (src/matched/unit_020242D8.c): store the id, zero the
 * flag halfword at +2, then a two-iteration loop seeds the trailing
 * halfwords at +4 and +6 with a shared 0xFFFF sentinel. The loop counter
 * is signed (the original's `blt`, not `blo`, on a literal trip count of
 * 2); an unsigned counter compiles to `blo` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020242A4.c \
 *       --func func_020242A4 --addr 0x020242A4 --cc 1.1p1 --thumb
 */
void func_020242A4(void *obj, u32 id)
{
    u16 *p = (u16 *)obj;
    s32_02023EF4 i;

    p[0] = (u16)id;
    p[1] = 0;
    for (i = 0; i < 2; i++) {
        p[i + 2] = 0xFFFF;
    }
}









void func_020242C0(void *a, void *b, void *c)
{
    func_020242A4(a, (u32)b);
    func_02024598(a, (int)b, (int)c);
}









/*
 * A whole translation unit, matched as one byte range.
 *
 * func_020242D8 dispatches on a 0..3 index through a dense jump table
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md); an index
 * over 3 lands on the shared epilogue with neither a call nor a store,
 * which only a `default: break;` with nothing else in it produces. Each
 * arm calls the shared initialiser func_020242A4 (its own file,
 * src/matched/func_020242A4.c, EXACT) with a small id, then overwrites the
 * flag halfword and one trailing field with plain 16-bit constants; the
 * four constants are narrowed by the `strh`, not addresses. Case 3 passes
 * the same id as case 1 (2) but a different flag (0xd instead of 0), so
 * the four arms cannot be collapsed by id alone.
 *
 * func_02024344 is the same shape as one switch arm inlined outside a
 * switch: call func_020242A4 with id 0, then overwrite the flag and
 * trailing field it just set.
 *
 * The two functions are contiguous with no gap: func_020242D8's own
 * literal pool (the four constants) runs right up to func_02024344's
 * entry point.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020242D8.c \
 *       --addr 0x020242D8 --thumb
 */
void func_020242D8(void *slot, u32 idx)
{
    u16 *p = (u16 *)slot;

    switch (idx) {
    case 0:
        func_020242A4(slot, 1);
        p[1] = 0;
        p[2] = 0x5D2;
        break;
    case 1:
        func_020242A4(slot, 2);
        p[1] = 0;
        p[2] = 0x5CD;
        break;
    case 2:
        func_020242A4(slot, 3);
        p[1] = 0;
        p[2] = 0x667;
        break;
    case 3:
        func_020242A4(slot, 2);
        p[1] = 0xd;
        p[2] = 0x573;
        break;
    default:
        break;
    }
}









void func_02024344(void *obj)
{
    u16 *p = (u16 *)obj;

    func_020242A4(obj, 0);
    p[1] = 1;
    p[2] = 0x58F;
}









/*
 * func_02024368 with a count of 2: a tail call through the pool.  Seeded in
 * layout/function_starts.txt from the bl sites in ov010, ov069 and ov093
 * (w6_fix18).
 */
void *func_0202435C(void *slots, unsigned int heap)
{
    return func_02024368(slots, heap, 2);
}









/*
 * Archived graphics-slot loader: opens the bank named by the id table at
 * 0x0209F724 for the requested stream, unpacks a scratch buffer out of
 * it, and walks the caller's two-halfword slot array telling the slot
 * manager what each entry is.
 *
 * A slot word of 0xffff means "empty" and is registered with the
 * fixed-size flag; otherwise bit 11 of the word says whether the value
 * carries a 0x7ff payload (registered masked) or is a plain size
 * (registered whole).  The two branches into the size-carrying
 * registration merge on one call site, so they are written as two
 * separate calls in the source and left to the compiler.
 *
 * The 0x100 buffer request is materialised as `movs r5, #2` followed by
 * `adds r5, #0xfe`: the 2 already sits in r5 from the previous call's
 * argument, and 2 + 0xfe is four bytes either way.
 */
void *func_02024368(u16 *slots, u32 heap, int count)
{
    void *obj;
    void *buf;
    void *slot;
    void *k;
    int i;

    obj = func_0201EC64((u16)heap);
    for (i = 0; i < count; i++) {
        u16 v = slots[i + 2];

        if (v != 0xffff) {
            if ((v >> 11) & 1) {
                func_0201EFFC(obj, i, v & 0x7ff);
            } else {
                func_0201EFC8(obj, i, v);
            }
        } else {
            func_0201EFFC(obj, i, 1);
        }
    }
    slot = func_02045B38(0, 2, Table_0209F724[slots[0]], (u16)heap);
    buf = func_020457B0(0x100, (u16)heap);
    k = func_02045EC0(slot, slots[1]);
    func_0201F250(obj, buf, k);
    func_02045808(k);
    func_02045C04(slot);
    func_0201ED04(obj);
    return buf;
}







void *func_0202441C(const struct Struct_0202441C *obj, u32 heapId)
{
    void *str;
    void *bank;
    u16 hid = (u16)heapId;

    bank = func_02045B38(0, 2, Table_0209F724[obj->arcFileIdx], hid);
    str = func_02045EC0(bank, obj->strIdx);
    func_02045C04(bank);

    return str;
}





int func_02024450(const u16 *p)
{
    if (*p != 0xFFFF) {
        return 1;
    }
    return 0;
}








int func_02024464(struct Rec4 *p, u16 a1)
{
    u32 n = func_02024498(p->f00, p->f02, a1);
    u32 i;

    for (i = 0; i < n; i++) {
        if (*(u16 *)((char *)p + i * 2 + 4) == 0xffff) {
            return 0;
        }
    }
    return 1;
}







u32 func_02024498(u32 a0, u32 a1, u16 a2)
{
    struct MsgBank *arc = func_02045B38(0, 2, g_0209F724[a0], a2);
    void *str = func_02045EC0(arc, a1);
    u32 z;

    func_02045C04((struct Rec *)arc);
    z = func_0201D478(str);
    func_02045808((struct U16Vec *)str);

    return z;
}







u16 func_020244D4(void *obj, u32 idx)
{
    u16 val = ((u16 *)((char *)obj + 4))[idx];

    if (val == 0xffff) {
        return 0xffff;
    }
    return (u16)(val & (0xffff >> 5));
}






u16 func_020244F0(void *obj, u32 idx)
{
    return ((u16 *)((char *)obj + 4))[idx];
}








u32 func_020244F8(struct Container_02023EF4 *p, u32 idx)
{
    return func_02024508(p->arr[idx]);
}








/*
 * A sentinel-guarded bit test: 0xFFFF is treated as "unset" and reads as
 * bit 0, everything else reads back bit 11.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02024508.c \
 *       --func func_02024508 --addr 0x02024508 --cc 1.1p1 --thumb
 */
u32 func_02024508(u32 x)
{
    if (x == 0xFFFF) {
        return 0;
    }
    return ((s32_02024464)x >> 11) & 1;
}









/*
 * A plain bitmask, `& 0x7FF`. Immediately followed by two unlabelled
 * one-argument halfword accessors (`ldrh r0,[r0]`/`bx lr` and
 * `ldrh r0,[r0,#2]`/`bx lr`) that carry no push prologue and so are
 * invisible to disasm.py's sweep; not reproduced here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02024520.c \
 *       --func func_02024520 --addr 0x02024520 --cc 1.1p1 --thumb
 */
u32 func_02024520(u32 x)
{
    return x & 0x7FF;
}









/*
 * Unlabelled Thumb leaf in the ARM9 module: returns the first halfword.
 *
 * Addresses are Black-image addresses.
 */
int func_0202452C(const u16 *p)
{
    return *p;
}








/*
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 */
unsigned int func_02024530(const u16 *p) { return p[1]; }









int func_02024534(const struct Data *p1, const struct Data *p2)
{
    int i;

    if (p1->a != p2->a || p1->b != p2->b) {
        return 0;
    }

    for (i = 0; i < 2; i++) {
        if (p1->c[i] != p2->c[i]) {
            return 0;
        }
    }

    return 1;
}








/*
 * A plain 4-halfword struct copy.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02024570.c \
 *       --func func_02024570 --addr 0x02024570 --cc 1.1p1 --thumb
 */
void func_02024570(struct Rec8 *dst, const struct Rec8 *src)
{
    *dst = *src;
}








u8 func_02024584(u32 i)
{
    if (i < 7) {
        return g_0209F71C[i];
    }
    return 0;
}








void func_02024598(void *p0, int p1, int p2){ ((struct Obj05795 *)p0)->f0 = (unsigned short)p1; ((struct Obj05795 *)p0)->f2 = (unsigned short)p2; }







void func_020245A0(u8 *p,unsigned i,u16 v) {
    if(i<2) *(u16 *)(p+4+2*i)=v;
}








void func_020245AC(struct Rec4 *p, u16 a1)
{
    u32 n = func_02024498(p->f00, p->f02, a1);

    if (n < 2) {
        do {
            *(u16 *)((char *)p + n * 2 + 4) = 0xffff;
            n++;
        } while (n < 2);
    }
}








/*
 * pmsi_param.c's word-array validator: guards the (category, page) pair
 * against the per-category count, asks func_02024498 how many words the
 * page carries, and runs each word through the same two-arm check
 * func_020246C8 performs on a single word.
 *
 * THE LEVER that closed this (it was DIFF, 132 bytes against 136, for the
 * whole of the previous wave -- see docs/notes/func_020245D4.diff.c.txt):
 * BOTH arms of the two-arm check write the `ok = 0; goto ret;` tail out,
 * and the label `setfail` sits INSIDE THE FIRST ARM'S COPY.  That is the
 * mixed case of docs/idioms/two-arms-write-the-tail-out-and-the-third-
 * branches-back-into-one.md.  The original spends a conditional AND an
 * unconditional branch at +0x64/+0x66 (`bne <loop increment>; b <setfail>`)
 * exactly because the two arms did not cross-jump; every shape that shares
 * one copy behind a single label folds them into one inverted `beq`, loses
 * four bytes and shifts every later branch target.
 *
 * Equally load-bearing: the `!= 0` arm is written FIRST
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  With the
 * `== 0` arm first the two call sites swap and 17 bytes differ.
 *
 * `sel` must be a named local: the guard reads p->f02 once and the same
 * value is handed to func_02024498, which is what keeps r5 live across the
 * func_02024584 call.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020245D4.c \
 *       --func func_020245D4 --addr 0x020245D4 --thumb --cc 1.1p1
 */
u32 func_020245D4(struct Rec4 *p, u32 a1)
{
    u32 ok;
    u32 n;
    u32 i;
    u32 y, x;
    u32 sel;

    if (p->f00 >= 7) {
        goto fail;
    }
    sel = p->f02;
    if (sel >= func_02024584(p->f00)) {
        goto fail;
    }

    n = func_02024498(p->f00, sel, (u16)((a1 & 0x7FFF) | 0x8000));
    ok = 1;
    for (i = 0; i < n; i++) {
        struct Rec4 *q = (struct Rec4 *)((u16 *)p + i);

        if (func_02024508(q->f04) != 0) {
            s32_02024464 v = func_02024520(q->f04);

            if (v >= 1 && v < 11) {
                continue;
            }
setfail:
            ok = 0;
            goto ret;
        } else {
            if (func_020248D8(q->f04, &x, &y) != 0) {
                continue;
            }
            ok = 0;
            goto ret;
        }
    }
ret:
    return ok;
fail:
    return 0;
}








u32 func_0202465C(struct Rec4 *p, u32 a1, u32 a2)
{
    u32 ok = 1;
    u32 n;
    u32 i;

    if (p->f00 >= 7 || p->f02 >= (u32)func_02024584(p->f00)) {
        ok = 0;
        p->f00 = 0;
        p->f02 = 0;
    }

    n = func_02024498(p->f00, p->f02, (u16)((a2 & 0x7FFF) | 0x8000));
    if (n > 2) {
        n = 2;
    }
    for (i = 0; i < n; i++) {
        if (func_020246C8(&p->f04 + i, a1, 1) == 0) {
            ok = 0;
        }
    }
    return ok;
}








/*
 * pmsi_param.c's single-word validator (see docs/families/pmsi_param.h and
 * func_020245D4, which runs the same two-arm check over a word array).
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 116/116, 1 byte out at +0x3E
 * for three waves, docs/notes/func_020246C8.diff.c.txt): the flag arm writes
 * the fail tail `ok = 0; *p = 0x6A1; goto done;` out after the range test,
 * like the flag == 0 arm does. The image's `blt` lands on an unconditional
 * `b bad` instead of on `bad` itself: a branch that jump threading did not
 * follow is a branch into a cross-jumped copy of a written-out tail, because
 * cross-jumping runs after threading. Falling into the shared `bad:` label
 * lets 1.1p1 thread the hop away.
 */
u32 func_020246C8(u16 *p, u32 mode, u32 flag)
{
    u32 ok = 1;
    u32 y, x;

    if (mode != 0) {
        if (*p == 0xFFFF) {
            return ok;
        }
    } else {
        if (*p == 0xFFFF) {
            *p = 0x6A1;
            return 0;
        }
    }

    if (func_02024508(*p) != 0) {
        s32_02024464 v;

        if (flag != 0) {
            v = func_02024520(*p);
            if (v >= 1 && v < 11) {
                goto done;
            }
            ok = 0;
            *p = 0x6A1;
            goto done;
        } else {
            ok = 0;
            *p = 0x6A1;
            goto done;
        }
    } else {
        if (func_02024768(*p) == 0) {
            if (func_020248D8(*p, &x, &y) != 0) {
                goto done;
            }
        }
    }
bad:
    ok = 0;
    *p = 0x6A1;
done:
    return ok;
}









/*
 * Clamp a counter to the range 1..10, with a mode argument that changes
 * only the zero case: called with `a == 0` and a zero field, the field is
 * reset to 1 and 0 is returned; called with `a != 0` a zero field is left
 * alone and 1 is returned outright, skipping the range check entirely.
 * Every other value goes through the same range test regardless of `a`.
 *
 * The `result` local has to be initialised before either branch reads
 * `*p` (docs/idioms/initialise-the-result-before-the-input-or-every-arm-
 * duplicates-the-return.md): that ordering, not the declaration order, is
 * what keeps the constant 1 resident in one register across both early
 * returns and the range check's shared exit, instead of each arm
 * rematerialising its own `movs r0, #k; bx lr`. The two early returns
 * (the `a != 0` zero case and the `a == 0` zero case) are written as
 * direct `return` statements and stay as separate tails; only the range
 * check's in-range case and the clamp's fallthrough share one exit block,
 * reached by a `goto` from the first and by falling into it from the
 * second, exactly as the original's single `blt` past the clamp and the
 * clamp's own fallthrough both land on one `adds r0, r2, #0; bx lr`.
 *
 * This is wordset.c's normaliser: src/pending/func_0201EFFC.c calls it and
 * is promoted alongside this file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202473C.c \
 *       --func func_0202473C --addr 0x0202473C --cc 1.1p1 --thumb
 */
u32 func_0202473C(u32 *p, u32 a)
{
    u32 result = 1;
    s32_02024464 v;

    if (a != 0) {
        v = (s32_02024464)*p;
        if (v != 0) {
            goto range;
        }
        return result;
    }
    v = (s32_02024464)*p;
    if (v != 0) {
        goto range;
    }
    *p = result;
    return 0;

range:
    if (v < 1) {
        goto clamp;
    }
    if (v < 0xb) {
        goto end;
    }

clamp:
    *p = 1;
    result = 0;

end:
    return result;
}









/*
 * Blocked: data_0209F734 (a 12-halfword table) is named by exactly one pool word,
 * 0x020247A4, and that word is inside this function's own range once the
 * body compiles to its full 64 bytes; the `literal` class discards it. Every
 * concrete byte reproduces.
 */
s32_02024464 func_02024768(u32 v)
{
    struct Tbl b;
    u8 i;

    b = data_0209F734;
    for (i = 0; i < 12; i++) {
        if (v == b.f[i]) {
            return 1;
        }
    }
    return 0;
}









/*
 * pms_word.c: allocate the 0x38-byte word-message system and open its
 * thirteen message archives (ids from the u16 table at 0x0209F7AC).  The
 * heap id store sits inside the loop in the image, so it is inside the
 * loop here.  The r4/r5 swap of docs/notes/pkt_02024768.c.txt was the
 * declaration order: the counter is declared before the result pointer
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md),
 * found by tools/permuter.py and reduced to that one change.
 */
struct PmsWordSys *func_020247A8(u32 heapId)
{
    int i;
    struct PmsWordSys *p;

    p = func_02030734((u16)heapId, 0x38, 0, str_020A746C, 0x32);
    for (i = 0; i < 13; i++) {
        p->heapId = heapId;
        p->msg[i] = func_02045B38(0, 2, tbl_0209F7AC[i], heapId);
    }
    return p;
}









void func_020247F0(struct PmsWordSys *p)
{
    int i;
    for (i = 0; i < 0xd; i++)
        func_02045C04((struct Rec *)p->msg[i]);
    func_020307B0(p);
}









void func_02024810(struct PmsWordSys *p, u32 id, void *dest)
{
    u32 x, y;
    func_020248D8(id, &x, &y);
    func_02045CAC((struct MsgBank *)p->msg[x], y, dest);
}










/*
 * Loads one archived message/graphics entry into the caller's buffer.
 * The flat id is split by func_020248D8 into a bank index and an
 * entry index; the bank index selects an archive id out of the
 * halfword table at 0x0209F7AC, that archive is opened, the entry is
 * read into dest and the archive closed again.  The sentinel id
 * 0xffff means "nothing to load" and only clears dest.
 */
void func_02024838(u32 id, void *dest, u16 heap)
{
    u32 bank;
    u32 entry;

    if (id != 0xffff) {
        void *arc;

        func_020248D8(id, &bank, &entry);
        bank = Table_0209F7AC[bank];
        arc = func_02045B38(0, 2, bank, heap);
        func_02045CAC(arc, entry, dest);
        func_02045C04(arc);
    } else {
        func_0204581C(dest);
    }
}










u16 func_02024888(u32 idx, u16 add)
{
    u32 i;
    u16 sum;
    u16 k;

    for (i = 0; i < 0xD; i++) {
        if (idx == g_tbl0[i]) {
            k = 0;
            sum = 0;
            for (; k < i; k++) {
                sum = (u16)(sum + g_tbl1[k]);
            }
            return (u16)(sum + add);
        }
    }
    return 0xFFFF;
}











int func_020248D8(u32 v, u32 *a1, u32 *a2)
{
    u32 i;
    u32 sum;

    v &= 0x7ff;
    sum = 0;
    for (i = 0; i < 0xd; i++) {
        u16 n = g_0209F792[i];

        sum += n;
        if (v < sum) {
            *a1 = i;
            *a2 = v - (sum - n);
            return 1;
        }
    }
    return 0;
}









/*
 * Unlabelled Thumb leaf: address of the 8-byte entry idx of the table at p + 8.
 */
void *func_02024910(char *p, int idx)
{
    return p + 8 + idx * 8;
}










void func_02024918(struct Obj02024838 *p, s32_02024464 idx, const void *src)
{
    if (idx < 0 || idx >= 20) {
        return;
    }

    MI_CpuCopy8(src, &p->items[idx], 8);
}








/*
 * Save-table size callback: returns 0xA8, the size of the block whose
 * init is func_02024938.  Pointer word 0x02024935 at 0x0209DC00.
 */
u32 func_02024934(void)
{
    return 0xA8;
}








/*
 * pms_word.c: clear the flag words, seed all forty word slots to 0xFFFF,
 * then set the flag bit named by the first row of the 7 x 2 byte table at
 * 0x0209F784 whose kind is 2.  The table is a 2D array: `tbl[k][1]` is what
 * gives the image's second pool word 0x0209F785 (symbol + 1, indexed by
 * the same 2k), where a struct {kind, val} folds the +1 into the load
 * (docs/notes/pkt_02024938.c.txt).  k is unsigned (`blo`); the first two
 * loops count in int.
 */
void func_02024938(struct PmsWord *p)
{
    int i, j;
    u32 k;

    p->flags = 0;
    p->f04 = 0;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 2; j++)
            p->e[i].word[j] = 0xffff;
    }
    for (k = 0; k < 7; k++) {
        if (tbl_0209F784[k][0] == 2) {
            func_020249A0((int *)p, tbl_0209F784[k][1]);
            return;
        }
    }
}








void *func_02024988(struct WinPanel020071CCCtrl *ctrl)
{
    return func_020071CC(ctrl, 0x27);
}








int func_02024994(const u32 *p, u32 idx){return (*p >> idx) & 1;}








void func_020249A0(int *p, int bit)
{
    *p |= 1 << bit;
}









/*
 * Unlabelled arm9 leaf: true when a == b, or when the first of 13 halfword
 * groups that contains a also contains b. Filed as the relocation witness for
 * ov021 func_021D213C (wave A1).
 */
int func_020249B0(u32 a, u16 b)
{
    u32 i;
    int j, k;

    if (a == b) {
        return 1;
    }
    for (i = 0; i < 13; i++) {
        for (j = 0; j < data_0209F7C8[i].count; j++) {
            if (a == data_0209F7C8[i].list[j]) {
                for (k = 0; k < data_0209F7C8[i].count; k++) {
                    if (b == data_0209F7C8[i].list[k]) {
                        return 1;
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}









/*
 * note:     infowin constructor.  The heap id is u16: as u32 mwcc reuses r3
 *           for the allocator call instead of reloading the spilled home
 *           (17 bytes).  Found by tools/permuter.py --types.
 */
void func_02024A20(u8 a0, u8 a1, void *a2, u16 heap)
{
    gInfoWin = func_02030734(heap, 0x28, 0, infowin_File, 0x103);
    MI_CpuFill8(gInfoWin, 0, 0x28);
    gInfoWin->f06 = a0;
    gInfoWin->f07 = a1;
    func_020251FC(a0, a1, heap);
    gInfoWin->f24 = func_020056A0((void (*)(void *))func_02024DFC, gInfoWin, 1);
    gInfoWin->f20 = 0;
    gInfoWin->f1F = func_0203568C();
    if (a2 != 0) {
        gInfoWin->f0C = func_0201283C(a2);
        gInfoWin->f10 = func_02012BB0(a2);
    } else {
        gInfoWin->f0C = 0;
        gInfoWin->f10 = 0;
    }
    gInfoWin->f08 = 0;
    func_02024ABC();
    gInfoWin->f04 = 0x3f;
}









/*
 * note:     infowin per-frame state poll (the TCB-less update): clock tick,
 *           link/wireless state, then the dirty bits of +0x04.  Two shape
 *           facts carry the whole match: every flag update is spelled out
 *           (`f = (u16)(f | X)`, which reuses the tested load; `|=` re-reads
 *           it), and every clear mask is the u16 constant (the pool holds
 *           0x0000EFFF, not ~0x1000).
 */
void func_02024ABC(void)
{
    int flag = 0;
    u8 n = 0;
    struct Link *link = 0;
    u32 bits;
    int idx;

    if (gInfoWin == 0)
        return;

    func_020252A8();
    gInfoWin->f1E++;
    if (gInfoWin->f1E > 60) {
        u8 v = func_0203568C();
        if (gInfoWin->f1F != v) {
            gInfoWin->f1F = v;
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x20);
        }
        gInfoWin->f1E = 0;
    }

    if (func_0203CD98() == 1) {
        link = func_0203D798();
        n = func_0203D1B4();
        if (func_0203D29C() == 1)
            flag = 1;
    }

    if (n < 2 && flag == 0) {
        bits = func_0201058C((void *)gInfoWin->f0C);
        idx = 0;
        if (gInfoWin->f10 == 1 && func_02026CA0(&idx) != 0x1E) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x1000);
        } else {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xEFFF);
        }
        if (!(bits & 2)) {
            if (((gInfoWin->f04 & 0x200) ? 1 : 0) == 1) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 4);
                gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFDFF);
            }
        }
        if (bits & 0x3C) {
            if (bits & 0xC) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x800);
            } else if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 0) {
                gInfoWin->f08 = 0;
                gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
            }
        } else if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 1) {
            gInfoWin->f08 = 0;
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFBFF);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
        }
        if (bits & 0x3C0) {
            if (gInfoWin->f20 == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
                gInfoWin->f20 = 1;
            }
        } else if (gInfoWin->f20 != 0) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
            gInfoWin->f20 = 0;
        }
    } else if (link != 0) {
        if (link->f65 == 3) {
            if (((gInfoWin->f04 & 0x200) ? 1 : 0) == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 4);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x200);
            }
        } else if (((gInfoWin->f04 & 0x200) ? 1 : 0) == 1) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 4);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFDFF);
        }
        if (link->f65 == 0 || link->f65 == 4 || link->f65 == 5) {
            if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
                gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
                gInfoWin->f08 = 0;
            }
            if (link->f67 == 2) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x800);
            }
        } else if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 1) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFBFF);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
            gInfoWin->f08 = 0;
        }
        if (link->f65 == 1 || link->f65 == 2 || link->f65 == 6) {
            if (gInfoWin->f20 == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
                gInfoWin->f20 = 1;
            }
        } else if (gInfoWin->f20 != 0) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
            gInfoWin->f20 = 0;
        }
    }
}







int func_02024DCC(void)
{
    if (gInfoWin != 0) {
        func_02030EAC(gInfoWin->f24);
        func_0203FB44(gInfoWin->f06, gInfoWin->f00, 1 << 12);
        func_020307B0(gInfoWin);
        gInfoWin = 0;
        return 0;
    } else {
        return (int)gInfoWin;
    }
}








/*
 * note:     infowin redraw task (the TCB callback func_02024A20 registers):
 *           clock digits, battery/link/wireless icons, per dirty bit of
 *           +0x04.  Levers, in the order they closed it: tens use `/ 10`
 *           and ones `% 10` (the remainder comes back in r1); every access
 *           goes through the global (reloaded at each join); the two
 *           six-entry tables are struct copies (local initialised arrays);
 *           `k = (c) ? a : b` for all three tile selectors; the draw call
 *           in each arm of block 0x10; `done = 1` after the block-0 draw.
 */
void func_02024DFC(void)
{
    struct W buf;
    int done;
    int k;

    done = 0;
    if (gInfoWin == 0)
        return;

    if (gInfoWin->f04 & 1) {
        if (gInfoWin->f1D < 10) {
            buf.clk[0] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + 0xF);
            buf.clk[5] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + 0x1F);
        } else {
            buf.clk[0] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + (gInfoWin->f1D / 10 + 1));
            buf.clk[5] = buf.clk[0] + 0x10;
        }
        buf.clk[1] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + (gInfoWin->f1D % 10 + 1));
        k = (gInfoWin->f14 != 0) ? 11 : 15;
        buf.clk[2] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + k);
        buf.clk[3] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + (gInfoWin->f1C / 10 + 1));
        buf.clk[4] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + (gInfoWin->f1C % 10 + 1));
        buf.clk[6] = buf.clk[1] + 0x10;
        k = (gInfoWin->f14 != 0) ? 27 : 31;
        buf.clk[7] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + k);
        buf.clk[8] = buf.clk[3] + 0x10;
        buf.clk[9] = buf.clk[4] + 0x10;
        func_020410D0(gInfoWin->f06, 1, 0, 5, 2, (u32)buf.clk, 0, 0, 5, 2);
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 1;
    }

    if (gInfoWin->f04 & 4) {
        u8 sel = (gInfoWin->f04 & 0x200) ? 1 : 0;
        func_02025154(d_0209F834[sel], gInfoWin->f07, 9, 0, 3, 2);
        func_020251D8(6, &d_0209F840[sel], 2);
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 4;
    }

    if (gInfoWin->f04 & 8) {
        func_02025154(d_0209F848[gInfoWin->f20], gInfoWin->f07, 13, 0, 6, 2);
        func_020251D8(8, d_0209F852[gInfoWin->f20], 2);
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 8;
    }

    if (gInfoWin->f04 & 0x10) {
        func_02025154(0x20, gInfoWin->f07, 0x13, 0, 7, 2);
        if (gInfoWin->f04 & 0x800) {
            u8 t;
            u8 ph;
            if (func_02035630() == 0x1E)
                gInfoWin->f08 = gInfoWin->f08 + 2;
            else
                gInfoWin->f08 = gInfoWin->f08 + 1;
            if (gInfoWin->f08 >= 0x50)
                gInfoWin->f08 = 0;
            t = gInfoWin->f08 / 16;
            ph = gInfoWin->f08 % 16;
            if (t < 4) {
                int d;
                u8 c;
                d = ph - 8;
                if (d < 0)
                    d = -d;
                ph = 8 - d;
                c = ph * 13 / 8 + 6;
                buf.col[0] = (c << 5) | c | (c << 10);
                c = ph * 22 / 8 + 9;
                buf.col[1] = (c << 5) | c | (c << 10);
                func_020251D8(10, buf.col, 2);
            } else {
                func_020251D8(10, &d_0209F838[0], 2);
            }
        } else {
            u8 sel = (gInfoWin->f04 & 0x1400) ? 1 : 0;
            func_020251D8(10, &d_0209F838[sel], 2);
        }
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 0x10;
    }

    if (gInfoWin->f04 & 0x20) {
        u8 *sp8 = buf.sel.v;
        buf.ofs = d_0209F870;
        buf.sel = d_0209F868;
        if (OS_IsRunOnTwl()) {
            k = sp8[gInfoWin->f1F];
        } else {
            k = (gInfoWin->f1F == 5) ? 5 : 4;
        }
        buf.scr[0] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + buf.ofs.v[k]);
        buf.scr[2] = buf.scr[0] + 0x10;
        buf.scr[1] = buf.scr[0] + 0x400;
        buf.scr[3] = buf.scr[2] + 0x400;
        func_020410D0(gInfoWin->f06, 0x1C, 0, 2, 2, (u32)buf.scr, 0, 0, 2, 2);
        func_020251D8(13, d_0209F830, 1);
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 0x20;
    }

    if (done == 1)
        func_020409B4(gInfoWin->f06);
}








/*
 * note:     infowin tile-rect writer: fills a w*h u16 screen buffer with
 *           charbase + base + (pal << 12) + i + j*16 and hands it to
 *           func_020410D0.  x/y/w/h are u8 (the callee takes u8 w/h);
 *           `j * 16`, not `j << 4`, fixes the adds operand order.
 */
void func_02025154(u32 base, u32 blk, u8 x, u8 y, u8 w, u8 h)
{
    u16 buf[14];
    u8 i;
    u8 j;
    u32 p;
    struct InfoWin *q;

    i = 0;
    if (i < w) {
        p = base + (blk << 12);
        q = gInfoWin;
        do {
            for (j = 0; j < h; j++) {
                buf[j * w + i] = (u16)(q->f00 + (i + p + j * 16));
            }
            i++;
        } while (i < w);
    }
    func_020410D0(gInfoWin->f06, x, y, w, h, (u32)buf, 0, 0, w, h);
}








int func_020251D8(int tile, const void *src, int count)
{
    return func_02040E78(gInfoWin->f06, src, count * 2, (tile + (gInfoWin->f07 << 4)) * 2);
}








void func_020251FC(u32 a, u32 b, u32 c)
{
    void *env;
    u32 sel = 0;

    if (a > 3) {
        sel = 4;
    }

    env = func_020490F4(0x32, c);
    gInfoWin->f00 = func_0203FA08(a, 1 << 12, 1);
    func_02049B68(env, 0, sel, b << 5, 0x20, c);
    func_02049658(env, 1, a, gInfoWin->f00, 0, 0, c);
    ENV_SetResourceSet(env);
    func_02041300(a, (u16)(gInfoWin->f00 + 0xf), 0, 0, 0x20, 1, b);
    func_02041300(a, (u16)(gInfoWin->f00 + 0x1f), 0, 1, 0x20, 1, b);
    func_020409B4(a);
}








void func_020252A8(void)
{
    struct Cfg cfg;
    u32 v;

    func_0203F4CC((struct RtcTime *)(&cfg));
    v = cfg.c & 1;

    if (cfg.a != gInfoWin->f1D) {
        gInfoWin->f1D = cfg.a;
        if (gInfoWin->f1D >= 0xc) {
            gInfoWin->f18 = 1;
        } else {
            gInfoWin->f18 = 0;
        }
        gInfoWin->f04 |= 1;
    }

    if (cfg.b != gInfoWin->f1C) {
        gInfoWin->f1C = cfg.b;
        gInfoWin->f04 |= 1;
    }

    if (v != gInfoWin->f14) {
        gInfoWin->f14 = v;
        gInfoWin->f04 |= 1;
    }
}
