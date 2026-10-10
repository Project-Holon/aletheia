/*
 * file:     net_err.c
 * unit:     yes
 * function: func_0200F2D4, func_0200F300, func_0200F34C, func_0200F38C, func_0200F43C, func_0200F4E4, func_0200F520, func_0200F594, func_0200F5EC, func_0200F698, func_0200F6B8, func_0200F6D8, func_0200F734, func_0200F7B8, func_0200F7C0, func_0200F7DC, func_0200F7F4, func_0200F800, func_0200F824, func_0200F83C, func_0200FA84, func_0200FA94, func_0200FAAC, func_0200FB24, func_0200FB38, func_0200FB4C, func_0200FB6C, func_0200FBA0, func_0200FBB0, func_0200FC0C, sub_0200FD38, sub_0200FEBC, CTRDGi_IsTaskAvailable_02010054, sub_02010068
 * address:  0x0200F2D4
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
 *   func_0203D5D4  0x0203D5D4  arm
 *   func_02059A5C  0x02059A5C  arm
 *   func_020598EC  0x020598EC  arm
 *   func_0203D5EC   0x0203D5EC  arm
 *   func_0203D610   0x0203D610  arm
 *   func_0203D634   0x0203D634  arm
 *   func_020596D8   0x020596D8  arm
 *   func_02009860           0x02009860  thumb
 *   sub_020099C8            0x020099C8  thumb
 *   func_02009A34           0x02009A34  thumb
 *   DWC_CheckFriendKey      0x02059354  arm
 *   DWC_CreateFriendKeyToken 0x02059980 arm
 *   DWC_GetGsProfileId      0x020598EC  arm
 *   DWC_IsValidFriendData   0x020596D8  arm
 *   func_02082D44  0x02082D44  arm
 *   sub_02008510   0x02008510  thumb
 *   sub_02008530   0x02008530  thumb
 *   sub_0200853C   0x0200853C  thumb
 *   sub_02008550   0x02008550  thumb
 *   sub_02008554   0x02008554  thumb
 *   sub_02009918   0x02009918  thumb
 *   sub_02009A00   0x02009A00  thumb
 *   func_02045808  0x02045808  arm
 *   sub_0201283C   0x0201283C  thumb
 *   sub_02009A1C           0x02009A1C  thumb
 *   func_0203D29C  0x0203D29C  arm
 *   func_02156B70  0x02156B70  thumb  ov009
 *   func_02005F24  0x02005F24  thumb
 *   sub_0200F6B8_Obj  0x0214617C  data
 *   MI_CpuFill8       0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203D880  0x0203D880  arm
 *   func_020393D0  0x020393D0  arm
 *   func_0203C990  0x0203C990  arm
 *   func_0203D864  0x0203D864  arm
 *   func_0200FAAC  0x0200FAAC  thumb
 *   func_0203D798  0x0203D798  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_02156460  0x02156460  thumb  ov009
 *   sub_0200F7B8       0x0200F7B8  thumb
 *   sub_0200F7C0_Obj   0x0214617C  data
 *   sub_0200F7C0_Flags 0x021461BC  data
 *   func_0207D534 0x0207D534  arm
 *   func_02010054        0x02010054  thumb
 *   func_02006210        0x02006210  thumb
 *   GX_VBlankIntr        0x0207D3E4  arm
 *   func_02037174        0x02037174  arm
 *   func_02037200        0x02037200  arm
 *   func_0201034C        0x0201034C  thumb
 *   func_02037190        0x02037190  arm
 *   GXS_SetGraphicsMode  0x0207D518  arm
 *   g_0214617C           0x0214617C  data
 *   func_0200FD38  0x0200FD38  thumb
 *   func_020351A0  0x020351A0  arm
 *   func_020053EC  0x020053EC  thumb
 *   func_0203CDBC  0x0203CDBC  arm
 *   sub_02010054   0x02010054  thumb
 *   g0214617C      0x0214617C  data
 *   g_021461BC     0x021461BC  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_020306F0  0x020306F0  arm
 *   sub_0200FBA0_Obj  0x0214617C  data
 *   func_0203CF04  0x0203CF04  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203D0D0  0x0203D0D0  arm
 *   func_02178E4C  0x02178E4C  thumb
 *   func_0203CFA0  0x0203CFA0  arm
 *   func_0208459C  0x0208459C  arm
 *   GX_HBlankIntr  0x0207D3AC  arm
 *   func_020101D4  0x020101D4  thumb
 *   GXx_GetMasterBrightness_  0x0207D55C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   func_020808F4             0x020808F4  arm
 *   func_020809A0             0x020809A0  arm
 *   GX_SetBankForBG           0x0207FDCC  arm
 *   GX_SetGraphicsMode        0x0207D4B0  arm
 *   G2_GetBG1CharPtr          0x0207E24C  arm
 *   G2_GetBG1ScrPtr           0x0207DFB4  arm
 *   MIi_CpuCopy16             0x02082A60  arm
 *   func_02043668             0x02043668  arm
 *   func_020435F4             0x020435F4  arm
 *   func_0203D828             0x0203D828  arm
 *   GX_SetBankForSubBG        0x020806B0  arm
 *   OS_WaitIrq                0x0208459C  arm
 *   g0209DEA0      0x0209DEA0  data
 *   func_0207E24C  0x0207E24C  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_020862F0  0x020862F0  arm
 *   func_02082A60  0x02082A60  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0207DFB4  0x0207DFB4  arm
 *   func_02062AD4  0x02062AD4  arm
 *   func_02062A98  0x02062A98  arm
 */
#include "../../matched/include/Obj11713.h"
#include "../../matched/include/Obj03039.h"
#include "../../matched/include/Obj05696.h"
#include "../../matched/include/Obj01327.h"

#define reg_GX_DISPCNT      (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT  (*(volatile u32 *)0x04001000)
#define reg_G2_WINOUT       (*(volatile u16 *)0x0400004A)
#define reg_G2S_DB_WINOUT   (*(volatile u16 *)0x0400104A)
#define reg_PAD_KEYINPUT    (*(volatile u16 *)0x04000130)
#define HW_BUTTON_XY_BUF    (*(volatile u16 *)0x02FFFFA8)
#define reg_GX_MASTER_BRIGHT   (*(volatile u16 *)0x0400006C)
#define reg_GXS_DB_MASTER_BRIGHT (*(volatile u16 *)0x0400106C)
#define reg_G2_BG1CNT          (*(volatile u16 *)0x0400000A)
#define reg_G2_BG1OFS          (*(volatile u32 *)0x04000014)
#define reg_G2_BLDCNT          (*(volatile u16 *)0x04000050)
#define reg_G2S_DB_BLDCNT      (*(volatile u16 *)0x04001050)
struct DWCstAccUserData;
struct Sub020097BCObj;
struct Sub020097BCFriend;
struct Sub0200852CObj;
struct U16Vec;
struct BigObj;
struct NitroFileHeader;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned long long u64;

typedef struct { u32 w[3]; } DWCFriendData;

typedef signed short   s16;

struct Sub0200F6B8Obj {
    unsigned char pad[0x60];
};

typedef unsigned short u16;

struct Sub0200F7C0Obj {
    u8 pad[0x64];
};

struct Sub0200F7C0Flags {
    u8 pad[0x1b];
};

typedef int            BOOL;

typedef union {
    u32 raw;
    struct {
        u32 bgMode:3;
        u32 bg0_2d3d:1;
        u32 objMapChar:1;
        u32 objMapBmp:2;
        u32 blankScr:1;
        u32 visiblePlane:5;
        u32 visibleWnd:3;
        u32 dispMode:4;
        u32 extObjMapChar:2;
        u32 extObjMapBmp:1;
        u32 hBlankObjProc:1;
        u32 bgCharOffset:3;
        u32 bgScrOffset:3;
        u32 bgExtPltt:1;
        u32 objExtPltt:1;
    };
} GXDispCnt;

typedef union {
    u16 raw;
    struct {
        u16 priority:2;
        u16 charBase:4;
        u16 mosaic:1;
        u16 colorMode:1;
        u16 screenBase:5;
        u16 bgExtPltt:1;
        u16 screenSize:2;
    };
} GXBg01Control;

typedef struct {
    u32 w[4];
} NetErrBlk;

typedef struct {
    void          *bg1Char;     /* +0x00 */
    void          *bg1Scr;      /* +0x04 */
    void          *pltt;        /* +0x08 */
    GXDispCnt      dispCnt;     /* +0x0C */
    GXBg01Control  bg1Cnt;      /* +0x10 */
    u16            pad12;
    int            bright;      /* +0x14 */
    int            subBright;   /* +0x18 */
    BOOL           hBlank;      /* +0x1C */
    BOOL           vBlank;      /* +0x20 */
    u32            bankBG;      /* +0x24 */
    u32            bankSubBG;   /* +0x28 */
    u32            state;       /* +0x2C */
    u32            f30;         /* +0x30 */
    u16            bldCnt;      /* +0x34 */
    u16            subBldCnt;   /* +0x36 */
    u32            f38;         /* +0x38 */
    int            subWnd;      /* +0x3C */
    u16            pltt0;       /* +0x40 */
    u16            pad42;
    u32            count;       /* +0x44 */
    NetErrBlk      blk48;       /* +0x48 */
    u8             f58;         /* +0x58 */
    u8             f59;         /* +0x59 */
    u8             pad5A[2];
    u32            f5C;         /* +0x5C */
    u32            f60;         /* +0x60 */
} NetErrWork;

typedef struct {
    u8 planeMask:5;
    u8 effect:1;
    u8 _reserve:2;
} GXWndPlane;

struct Blk16_0200FAAC {
    u32 w[4];
};

struct Sub0200FB6CObj {
    void *unk00;
    void *unk04;
    void *unk08;
};

struct Sub0200FBA0Obj {
    unsigned char pad[0x60];
};

typedef enum { GX_BG_SCRSIZE_TEXT_256x256 = 0 } GXBGScrSizeText;

typedef enum { GX_BG_COLORMODE_16 = 0 } GXBGColorMode;

typedef enum { GX_BG_SCRBASE_0x0000 = 0 } GXBGScrBase;

typedef enum { GX_BG_CHARBASE_0x00000 = 0 } GXBGCharBase;

typedef enum { GX_BG_EXTPLTT_01 = 0 } GXBGExtPltt;

struct ent {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
};

struct res0 {
    u8  pad[0x10];
    u32 len;
    void *ptr;
};

struct res1 {
    u32 pad0;
    u32 pad4;
    u32 len;
    u8  buf[4];
};

struct res2 {
    u8  pad[0xc];
    void *ptr;
};

typedef signed int     s32;

extern int func_0203D5D4(void);
extern int func_02059A5C(void *b, void *c);
extern int func_020598EC(struct DWCstAccUserData *userdata, void *frienddata);
extern u32 func_0203D5EC(void);
extern u32 func_0203D610(void);
extern u32 func_0203D634(void);
extern int   func_020596D8(void *p);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern struct Sub020097BCFriend *sub_020099C8(struct Sub020097BCObj *obj, int i);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern int  DWC_CheckFriendKey(void *p, u64 key);
extern void DWC_CreateFriendKeyToken(DWCFriendData *tok, u64 key);
extern int  DWC_GetGsProfileId(void *p, const DWCFriendData *rec);
extern int  DWC_IsValidFriendData(const DWCFriendData *rec);
extern void  func_02082D44(void *dst, const void *src, u32 n);
extern void *sub_02008510(void *a, int b);
extern u32 sub_02008530(const struct Sub0200852CObj *obj);
extern u32 sub_0200853C(const struct Sub0200852CObj *obj);
extern u8 sub_02008550(const struct Sub0200852CObj *obj);
extern u8 sub_02008554(const struct Sub0200852CObj *obj);
extern void sub_02009918(struct Sub020097BCObj *obj, u32 i, u32 field, u32 value);
extern void sub_02009A00(struct Sub020097BCObj *obj, int i, void *dest);
extern void func_02045808(struct U16Vec *vec);
extern u32 sub_0201283C(const struct BigObj *p);
extern int sub_02009A1C(struct Sub020097BCObj *obj, u32 i);
extern u32  func_0203D29C(void);
extern s16 func_02156B70(void);
extern void func_02005F24(u32 a0, u32 a1);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern u32 func_02030734(u16 kind, u32 mask, u32 zero, const void *name, u8 tag);
extern int func_0203CD98(void);
extern u32  func_0203D880(void);
extern int func_020393D0(void);
extern u32  func_0203C990(void);
extern void func_0203D864(void);
extern void func_0200FAAC(void);
extern void *func_0203D798(void);
extern u32 func_0203CA98(void);
extern int func_02156460(int err, int kind);
extern u32 sub_0200F7B8(u32 a0);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern u32 func_0203CF5C();
extern void func_0208459C(int clear, u32 irqFlags);
extern u32  func_02010054(void);
extern void func_02006210(void);
extern BOOL GX_VBlankIntr(BOOL on);
extern void func_02037174(void);
extern u32 func_02037200(void);
extern int func_0201034C(void);
extern void func_02037190(void);
extern void GXS_SetGraphicsMode(u32 bgMode);
extern void func_0200FD38(u32 a, u32 b);
extern int func_020351A0(u32 v);
extern void func_020053EC(void);
extern int   sub_02010054(void);
extern int   func_0203CDBC(void);
extern u32 func_020307B0(void *p);
extern void func_020306F0(u32 id);
extern void func_0203CF04(void);
extern int func_0203CEAC(int a0);
extern void func_0203D0D0(void);
extern u32  func_02178E4C(void);
extern void func_0203CFA0(void);
extern u32  GX_HBlankIntr(BOOL on);
extern void func_020101D4(u32 a, u32 b);
extern int  GXx_GetMasterBrightness_(volatile u16 *reg);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int v);
extern int func_020808F4(void);
extern int func_020809A0(void);
extern void GX_SetBankForBG(u32 bank);
extern void GX_SetGraphicsMode(u32 dispMode, u32 bgMode, u32 bg0_2d3d);
extern void *G2_GetBG1CharPtr(void);
extern void *G2_GetBG1ScrPtr(void);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern u32  func_02043668(void);
extern void func_020435F4(u32 a);
extern void func_0203D828(u32 *a, u32 *b);
extern void GX_SetBankForSubBG(u32 bank);
extern u32  OS_WaitIrq(BOOL clear, u32 mask);
extern void *func_0207E24C(void);
extern void *func_0207DFB4(void);
extern void func_02082A7C(u32 val, void *dst, u32 n);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void func_020862F0(void *p, u32 n);
extern void func_02082A60(void *dst, const void *src, u32 n);
extern int func_02062B30(void *file, void **out);
extern s32 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
int func_0200F2D4(void);
int sub_0200F300(void);
int sub_0200F34C(void *a, void *b, void *c);
int func_0200F38C(void *a, int *out);
int func_0200F43C(void *obj, u64 key, int *out);
int func_0200F4E4(void *o);
void sub_0200F520(void *obj, void *src, int i, int sel, int flag);
void sub_0200F594(void *a0, void *a1, void *a2, int a3, void *a4, int mode);
int func_0200F5EC(void *a0, void *a1, void *a2, void *a3);
void sub_0200F698(void *a, void *b);
void sub_0200F6B8(void);
void sub_0200F6D8(u32 kind);
void sub_0200F734(void);
u32 func_0200F7B8(u32 a0);
void sub_0200F7C0(u32 value);
void sub_0200F7DC(void);
void sub_0200F7E8(u32 value);
void sub_0200F7F4(void);
void sub_0200F800(void);
void sub_0200F824(void);
void func_0200F83C(void);
void sub_0200FA84(void);
void sub_0200FA94(void);
void sub_0200FAAC(void);
u32 sub_0200FB24(void);
void func_0200FB38(void);
void func_0200FB4C(unsigned int x);
void sub_0200FB6C(void);
void sub_0200FBA0(void);
u32 sub_0200FBB0(void);
u32 func_0200FC0C(u32 a0);
void sub_0200FD38(u32 a0, u32 a1);
void sub_0200FEBC(BOOL keepDark);
asm void CTRDGi_IsTaskAvailable_02010054(void);
void sub_02010068(u32 a0);
extern struct Sub0200F7C0Flags sub_0200F7C0_Flags;
extern NetErrWork g_0214617C;
extern unsigned char g_021461BC[];
extern struct ent g0209DEA0[];





int func_0200F2D4(void){ int t0, t1, t2; t0 = func_0203D5D4(); if ((unsigned int)(t0) == (unsigned int)(2)) { if ((unsigned int)(*(unsigned char *)((char *)(0x2146178))) == (unsigned int)(0)) { t1 = func_0203CF5C((int)*(unsigned char *)((char *)(0x2146178))); *(unsigned char *)((char *)(0x2146178)) = (unsigned char)t1; return t1; } else { *(unsigned char *)((char *)(0x2146178)) = (unsigned char)0; return 0; } } else { t2 = func_0203CF5C((int)t0); return t2; } }






/*
 * A membership test on func_0203D5D4()'s result: true for a scattered set
 * of values (12-16, 28, 31, 37, 38, 48), false otherwise. The compiler
 * lowers the contiguous 12-16 run as a dense jump table (see
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md), all five
 * entries landing on the same "return 1", and the rest as compare chains.
 * func_0203D5D4 has to be declared returning a signed int: an unsigned
 * return type turns every one of the range tests into an unsigned
 * compare (bhi/bhs instead of bgt/bge), which is the only thing that
 * differed on the first attempt.
 *
 * EXACT* because the 74 compiled bytes fall two short of the disasm.py
 * extent: a "movs r0, r0" alignment filler before the next label, the
 * ordinary inter-function padding, not a byte difference.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F300.c \
 *       --func sub_0200F300 --addr 0x0200F300 --cc 1.1p1
 */
int sub_0200F300(void)
{
    switch (func_0203D5D4()) {
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 28:
    case 31:
    case 37:
    case 38:
    case 48:
        return 1;
    default:
        return 0;
    }
}






/*
 * A three-way friend-key comparator: bails out (0) if func_02059A5C(a, c)
 * flags the pair invalid. Otherwise compares b against a with
 * func_020598EC; if that says "no difference" (<= 0) the function reports
 * "not newer" (2). Otherwise it re-derives the b-against-a comparison
 * (the call is issued twice) and compares it against a fresh b-against-c
 * comparison, reporting "newer" (1) only when they agree and "not newer"
 * (2) otherwise.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F34C.c \
 *       --func sub_0200F34C --addr 0x0200F34C --cc 1.1p1
 */
int sub_0200F34C(void *a, void *b, void *c)
{
    if (func_02059A5C(a, c) != 0) {
        return 0;
    }

    if (func_020598EC(b, a) > 0) {
        int lhs = func_020598EC(b, a);
        int rhs = func_020598EC(b, c);
        if (lhs == rhs) {
            return 1;
        }
    }
    return 2;
}






/*
 * Search for a free friend slot: the out-parameter starts at -1 and the
 * function reports 3 when the object is not known at all (func_020596D8),
 * 0 for the first record whose tester (func_02059A5C) accepts it with that
 * slot index, 1 when the key (func_020598EC) of the object matches the
 * record's, and 2 when the scan finishes.  A slot that no key names and that
 * the tester still rejects is kept as a fallback in *out.
 *
 * This is the callee src/pending/sub_0200F4E4.c is capped on: its only
 * branch anywhere in the image is that one call site, so this entry is the
 * witness that turns it EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200F38C.c \
 *       --func func_0200F38C --addr 0x0200F38C --cc 1.1p1 --thumb
 */
int func_0200F38C(void *a, int *out)
{
    int   i;
    void *key = (void *)func_0203D5EC();
    u8   *tbl = (u8 *)func_0203D610();
    int   n = func_0203D634();

    *out = -1;
    if (func_020596D8(a) == 0)
        return 3;
    for (i = 0; i < n; i++) {
        int off = i * 12;

        if (func_02059A5C(a, tbl + off) != 0) {
            *out = i;
            return 0;
        }
        if (func_020598EC(key, a) > 0
            && func_020598EC(key, a) == func_020598EC(key, tbl + off)) {
            *out = i;
            return 1;
        }
        if (*out < 0 && func_020596D8(tbl + off) == 0)
            *out = i;
    }
    return 2;
}






/*
 * The friend-list lookup: build a DWC friend-key token from the 64-bit
 * friend key, and compare its GS profile id against every entry of the
 * DWCFriendData (0xC-byte) array; report the matching slot through *out.
 * Returns 3 if the key is bad or the token has no profile id, 0 on a hit,
 * 2 if the list was walked without one; *out is left holding the first slot
 * whose record fails DWC_IsValidFriendData when there is no hit, -1 when
 * there is not even one of those.
 *
 * Closed in wave 12 by two declaration facts the earlier passes missed:
 *  - the key is ONE u64 (DWC_CheckFriendKey / DWC_CreateFriendKeyToken take
 *    a u64 friendKey), not two ints: that is why r1:r2 are homed together
 *    at sp+0/sp+4;
 *  - the array is typed as 12-byte records and indexed as arr[i], so the
 *    i*12 offset is computed once at the loop top into a callee-saved
 *    register ahead of both uses (a u8 pointer plus i * 0xC is recomputed
 *    and spilled per use, which is what pushed p into r7 and cost 2 bytes).
 * Both profile lookups stay inside the loop, as in the image.
 *
 * EXACT* only because the listing extent includes the two-byte
 * "movs r0, r0" alignment filler after the function.
 */
int func_0200F43C(void *obj, u64 key, int *out)
{
    void *p;
    DWCFriendData *arr;
    int n;
    int i;
    DWCFriendData tok;

    p = func_02009860(obj);
    i = 0;
    arr = (DWCFriendData *)sub_020099C8(obj, 0);
    n = func_02009A34(obj);

    if (DWC_CheckFriendKey(p, key) == 0)
        return 3;

    DWC_CreateFriendKeyToken(&tok, key);
    if (DWC_GetGsProfileId(p, &tok) <= 0)
        return 3;

    *out = i - 1;
    for (; i < n; i++) {
        if (DWC_GetGsProfileId(p, &tok) == DWC_GetGsProfileId(p, &arr[i])) {
            *out = i;
            return 0;
        }
        if (*out < 0 && DWC_IsValidFriendData(&arr[i]) == 0)
            *out = i;
    }
    return 2;
}






/*
 * note:     promoted from src/pending 2026-09-19 with NO C change: the only unresolved site was the
 *           call at +0x0012 to func_0200F38C, which became a `matched` witness when
 *           src/matched/func_0200F38C.c was filed (layout/matched/arm9/pkt_0200F38C.json).
 *           match.py one: EXACT, compiled 60 bytes, 3 of 3 relocations resolved.
 */
int func_0200F4E4(void *o)
{
    u32 out;
    int r = 0;
    void *base = (void *)func_0203D610();
    int v = func_0200F38C(o, (int *)(&out));

    if (v == 0) {
        /* nothing */
    } else if (v == 1) {
        func_02082D44(o, (unsigned char *)base + out * 0xc, 0xc);
    } else if (v == 2) {
        r = 1;
    }
    return r;
}






void sub_0200F520(void *obj, void *src, int i, int sel, int flag)
{
    if (flag != 0) {
        void *data = sub_02008510(src, sel);
        sub_02009A00(obj, i, data);
        func_02045808(data);
    }
    sub_02009918(obj, i, 9, sub_02008550(src));
    sub_02009918(obj, i, 0, sub_02008530(src));
    sub_02009918(obj, i, 1, sub_0200853C(src));
    sub_02009918(obj, i, 8, sub_02008554(src));
}






/*
 * blocking: unresolved: 0200F520 (thumb, from header) has no witness outside 0200F594..0200F
 */
void sub_0200F594(void *a0, void *a1, void *a2, int a3, void *a4, int mode)
{
    void *obj = (void *)sub_0201283C(a0);
    void *src = sub_020099C8(obj, a3);

    if (mode != 2) {
        func_02082D44(a2, src, 0xc);
    }
    if (mode == 0) {
        sub_0200F520(obj, a1, a3, (int)a4, 1);
    } else if (mode == 1) {
        sub_0200F520(obj, a1, a3, (int)a4, 0);
    }
    sub_02009918(obj, a3, 8, sub_02008554(a1));
}






/*
 * Insert one friend record into a 32-entry list and mirror it into the three
 * case slots.  sub_0200F594's last argument picks the slot: 0 for the
 * "not valid yet" arm, 2 when sub_0200F34C reports equality and 1 when it
 * reports "newer".  The first arm is the only one that returns 1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200F5EC.c \
 *       --func func_0200F5EC --addr 0x0200F5EC --cc 1.1p1 --thumb
 */
int func_0200F5EC(void *a0, void *a1, void *a2, void *a3)
{
    void *obj = (void *)sub_0201283C(a0);
    int i;

    if (DWC_IsValidFriendData(a2) == 0) {
        return 0;
    }

    for (i = 0; i < 0x20; i++) {
        void *src = sub_020099C8(obj, i);
        int mode;

        if (sub_02009A1C(obj, i) == 0) {
            sub_0200F594(a0, a1, a2, i, a3, 0);
            return 1;
        }
        mode = sub_0200F34C(a2, func_02009860(obj), src);
        if (mode == 0) {
            sub_0200F594(a0, a1, a2, i, a3, 2);
            return 0;
        }
        if (mode == 1) {
            sub_0200F594(a0, a1, a2, i, a3, 1);
            return 0;
        }
    }
    return 0;
}






/*
 * note:     wave 16: promoted.  0x02156B70 is the unlabelled ov009 leaf matched
 *           in src/matched/func_02156B70.c (ov009/pkt_02156B70); it attests as
 *           `matched, overlay` under the ov009 hint.
 *
 * Forwards its two arguments to func_02005F24 unless both func_0203D29C()
 * and func_02156B70() report nonzero; func_0203D29C is always called,
 * func_02156B70 only when the first call reports zero (a genuine
 * short-circuit, not an independent second check).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F698.c \
 *       --func sub_0200F698 --addr 0x0200F698 --cc 1.1p1
 */
void sub_0200F698(void *a, void *b)
{
    if (func_0203D29C() == 0 || func_02156B70() == 0) {
        func_02005F24((u32)a, (u32)b);
    }
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F6B8.c \
 *       --func sub_0200F6B8 --addr 0x0200F6B8 --cc 1.1p1
 */
void sub_0200F6B8(void)
{
    func_0203064C(1, 8, 0x4920);
    MI_CpuFill8(&g_0214617C, 0, 0x64);
}






/*
 * Zero-fills the module-wide object at 0x0214617C (see sub_0200F6B8.c and
 * sub_0200FBA0.c for the other users of the same global), then calls
 * func_02030734 three times with the same truncated kind value and the same
 * name pointer at 0x020A7234, each time with a different flag mask and a
 * different tag byte passed on the stack, storing each result into the
 * first three words of the object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F6D8.c \
 *       --func sub_0200F6D8 --addr 0x0200F6D8 --cc 1.1p1
 */
void sub_0200F6D8(u32 kind)
{
    u32 *obj = (u32 *)0x0214617C;
    const void *name = (const void *)0x020A7234;

    MI_CpuFill8(obj, 0, 0x64);

    obj[0] = func_02030734((u16)kind, 1u << 14, 0, name, 0xbb);
    obj[1] = func_02030734((u16)kind, (1u << 14) >> 3, 0, name, 0xbc);
    obj[2] = func_02030734((u16)kind, 0x20, 0, name, 0xbd);
}






/*
 *           func_02156460.  It is now a traced Thumb label in ov009 (ov010
 *           overlaps with non-code there, hence the ov009 hint below), but
 *           the call at 0x0200F7A8 is the only branch image-wide that
 *           reaches it, so the overlay `label` class refuses (no outside
 *           branch) and sole-ref/code does not cover overlay addresses.
 *           Needs a tool-side sole-ref/code rule for overlay labels, or a
 *           matched ov009 entry covering 0x02156460.  func_0203D864 now
 *           resolves.
 *
 * A gated status update: bails out early if the module-wide object at
 * 0x0214617C already has its +0x2c flag set, or if func_0203CD98 does not
 * report state 1, or if none of three link-state probes says yes. Once
 * past the gate it re-derives a status byte from func_0203D798's returned
 * object at offset +0x65 (only 1, 2 or 6 continue), then compares a field
 * of the object func_0203CA98 returns against two small windows and stores
 * a fixed error code into the global's +0x60 for either, falling through
 * to a real computation (func_02156460 on the object's first two words)
 * otherwise.
 *
 * Every concrete byte matches; func_0203D864 and func_02156460 are each
 * called from exactly this one site in the whole ROM, so both stay
 * unresolved relocations under the honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F734.c \
 *       --func sub_0200F734 --addr 0x0200F734 --cc 1.1p1
 *
 * The `matched` class does not reach it: neither func_0203D864 nor
 * func_02156460 is matched, so no EXACT entry covers either address.  Both live
 * outside the matched region so far.
 */
void sub_0200F734(void)
{
    u32 *g = (u32 *)0x0214617C;

    if (g[0x2c / 4] != 0) {
        return;
    }
    if (func_0203CD98() != 1) {
        return;
    }
    if (func_0203D880() == 0 && func_020393D0() == 0 && func_0203C990() == 0) {
        return;
    }

    func_0203D864();
    func_0200FAAC();

    {
        u8 *p = func_0203D798();
        u8 v = p[0x65];
        if (v != 1 && v != 2 && v != 6) {
            return;
        }
    }

    {
        u32 *obj = (u32 *)func_0203CA98();
        u32 field = obj[0xc / 4];

        if (field - 0x3f0 <= 1) {
            g[0x60 / 4] = 0x28;
            return;
        }
        if (field - 0x3f2 <= 4) {
            g[0x60 / 4] = 0xe;
            return;
        }

        g[0x60 / 4] = func_02156460(obj[0], obj[1]);
    }
}






u32 func_0200F7B8(u32 a0)
{
    return func_0200FC0C(a0);
}






/*
 * A whole translation unit, matched as one byte range.
 *
 * Four functions with no register-saving prologue, printed by disasm.py as
 * a run of .word between two labelled neighbours (sub_0200F7B8 before,
 * func_0200F800 after); see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md. Recovered by
 * hand-decoding the .word run and confirmed against the section map of
 * `match.py tu`.
 *
 * sub_0200F7C0 and sub_0200F7DC both tail-call sub_0200F7B8 (itself a
 * four-byte tail call to func_0200FC0C, matched separately); neither
 * clears r0 first, so the argument each passes reaches func_0200FC0C
 * unchanged. sub_0200F7E8 is a plain setter on the module-wide object at
 * 0x0214617C, and sub_0200F7F4 tail-calls it with a fixed zero.
 *
 * sub_0200F7B8's only two callers in the whole ROM are sub_0200F7C0 and
 * sub_0200F7DC, both inside this same range; a third call site elsewhere
 * in the image gives match.py's label class a witness outside the range,
 * so the relocation resolves.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200F7C0.c \
 *       --addr 0x0200F7C0 --thumb
 */
void sub_0200F7C0(u32 value)
{
    g_0214617C.f60 = value;
    *(u8 *)((u8 *)&sub_0200F7C0_Flags + 0x1a) = 1;
    *(u8 *)((u8 *)&sub_0200F7C0_Flags + 0x19) = 1;
    sub_0200F7B8(1);
}






void sub_0200F7DC(void)
{
    sub_0200F7B8(1);
}






void sub_0200F7E8(u32 value)
{
    g_0214617C.count = value;
}






void sub_0200F7F4(void)
{
    sub_0200F7E8(0);
}






/*
 * Two writes of a fixed global struct's fields straight to hardware I/O
 * registers at 0x0400006C and 0x0400106C (main-engine and sub-engine
 * capture control, per the DS memory map); the global at 0x0214617C is
 * read at +0x14 and +0x18 for the values written to each. The addresses
 * are literal pool words, not symbol references, so nothing needed
 * relocation resolution here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F800.c \
 *       --func sub_0200F800 --addr 0x0200F800 --cc 1.1p1
 */
void sub_0200F800(void)
{
    u32 *g = (u32 *)0x0214617C;
    func_0207D534((volatile u16 *)0x0400006C, ((struct Obj11713 *)g)->f14);
    func_0207D534((volatile u16 *)0x0400106C, ((struct Obj11713 *)g)->f18);
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F824.c \
 *       --func sub_0200F824 --addr 0x0200F824 --cc 1.1p1
 */
void sub_0200F824(void)
{
    if (func_0203CD98() == 1) {
        func_0203CF5C();
        func_0208459C(1, 1);
    }
}






static inline GXDispCnt GXS_GetDispCnt(void)
{
    return *(volatile GXDispCnt *)&reg_GXS_DB_DISPCNT;
}






static inline GXWndPlane G2_GetWndOutsidePlane(void)
{
    return *(volatile GXWndPlane *)&reg_G2_WINOUT;
}






static inline GXWndPlane G2_GetWndOBJInsidePlane(void)
{
    return *(volatile GXWndPlane *)((u8 *)&reg_G2_WINOUT + 1);
}






static inline GXWndPlane G2S_GetWndOutsidePlane(void)
{
    return *(volatile GXWndPlane *)&reg_G2S_DB_WINOUT;
}






static inline GXWndPlane G2S_GetWndOBJInsidePlane(void)
{
    return *(volatile GXWndPlane *)((u8 *)&reg_G2S_DB_WINOUT + 1);
}






static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (reg_G2_WINOUT & ~0x3F) | wnd;
    if (effect) {
        tmp |= 0x20;
    }
    reg_G2_WINOUT = (u16)tmp;
}






static inline void G2_SetWndOBJInsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (reg_G2_WINOUT & ~0x3F00) | (wnd << 8);
    if (effect) {
        tmp |= 0x2000;
    }
    reg_G2_WINOUT = (u16)tmp;
}






static inline void G2S_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (reg_G2S_DB_WINOUT & ~0x3F) | wnd;
    if (effect) {
        tmp |= 0x20;
    }
    reg_G2S_DB_WINOUT = (u16)tmp;
}






static inline void G2S_SetWndOBJInsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (reg_G2S_DB_WINOUT & ~0x3F00) | (wnd << 8);
    if (effect) {
        tmp |= 0x2000;
    }
    reg_G2S_DB_WINOUT = (u16)tmp;
}






static inline void GX_SetVisiblePlane(int plane)
{
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1F00) | (plane << 8);
}






static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}






static inline void GXS_SetVisiblePlane(int plane)
{
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1F00) | (plane << 8);
}






static inline void GXS_SetVisibleWnd(int window)
{
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0xE000 | (window << 13);
}






static inline BOOL PAD_DetachedCover(void)
{
    return (BOOL)((HW_BUTTON_XY_BUF & 0x8000) >> 15);
}






static inline u16 PAD_Read(void)
{
    return (u16)(((reg_PAD_KEYINPUT | HW_BUTTON_XY_BUF) ^ 0x2FFF) & 0x2FFF);
}






static inline u16 KeyFilter(u16 k)
{
    return (u16)(k & ~((k & 0x40) << 1) & ~((k & 0x20) >> 1));
}






/*
 * net_err.c's fatal-error screen: snapshots the sub-engine DISPCNT and the
 * WINOUT outside / OBJ-window planes of both engines, blanks and redraws
 * through sub_0200FD38, narrows the chosen engine's windowing to BG1+OBJ,
 * waits for A/B to be released and pressed (PAD_DetachedCover / PAD_Read
 * inlines, polling func_0201034C and sub_0200F824 per frame), restores via
 * sub_0200FEBC and puts the snapshotted window state back on whichever
 * engine func_02037200 now names.  Written directly from NitroSDK's
 * gx.h / g2.h inline shapes (GXDispCnt, GXWndPlane, G2[S]_SetWnd*Plane,
 * GX[S]_SetVisible*); exact on the first compile.
 */
void func_0200F83C(void)
{
    GXDispCnt dispCnt = GXS_GetDispCnt();
    GXWndPlane outMain = G2_GetWndOutsidePlane();
    GXWndPlane outSub = G2S_GetWndOutsidePlane();
    GXWndPlane objMain = G2_GetWndOBJInsidePlane();
    GXWndPlane objSub = G2S_GetWndOBJInsidePlane();

    if (func_02010054() == 0) {
        return;
    }
    func_02006210();
    sub_0200FD38(0, 0);
    GX_VBlankIntr(1);
    func_02037174();
    if (func_02037200() == 1) {
        G2_SetWndOutsidePlane(2, 0);
        G2_SetWndOBJInsidePlane(0x10, 0);
        GX_SetVisibleWnd(4);
        GX_SetVisiblePlane(0x12);
    } else {
        G2S_SetWndOutsidePlane(2, 0);
        G2S_SetWndOBJInsidePlane(0x10, 0);
        GXS_SetVisibleWnd(4);
        GXS_SetVisiblePlane(0x12);
    }
    while (PAD_DetachedCover() == 1 || (KeyFilter(PAD_Read()) & 3) != 0) {
        func_0201034C();
        sub_0200F824();
    }
    while (PAD_DetachedCover() == 1 || (KeyFilter(PAD_Read()) & 3) == 0) {
        func_0201034C();
        sub_0200F824();
    }
    sub_0200FEBC(g_0214617C.count == 1);
    func_02037190();
    if (func_02037200() == 2) {
        GXS_SetGraphicsMode(dispCnt.bgMode);
        GXS_SetVisiblePlane(dispCnt.visiblePlane);
        GXS_SetVisibleWnd(dispCnt.visibleWnd);
        G2S_SetWndOutsidePlane(outSub.planeMask, outSub.effect);
        G2S_SetWndOBJInsidePlane(objSub.planeMask, objSub.effect);
    } else {
        G2_SetWndOutsidePlane(outMain.planeMask, outMain.effect);
        G2_SetWndOBJInsidePlane(objMain.planeMask, objMain.effect);
    }
}






/*
 * Guard: if func_02010054() reports nonzero, calls the abort path
 * sub_0200FA94.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200FA84.c \
 *       --func sub_0200FA84 --addr 0x0200FA84 --cc 1.1p1
 */
void sub_0200FA84(void)
{
    if (func_02010054() != 0) {
        sub_0200FA94();
    }
}






/*
 * An abort path: reports a fixed status, tears down with func_020351A0(2),
 * then spins forever calling func_020053EC(). The infinite loop is why
 * nothing after this in the same block is ever reached.
 *
 * EXACT* because the 22 compiled bytes fall two short of the disasm.py
 * extent: a "movs r0, r0" alignment filler before the next label, the
 * ordinary inter-function padding, not a byte difference.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200FA94.c \
 *       --func sub_0200FA94 --addr 0x0200FA94 --cc 1.1p1
 */
void sub_0200FA94(void)
{
    func_0200FD38(1, 0);
    func_020351A0(2);
    for (;;) {
        func_020053EC();
    }
}





/*
 * Wave 13: the parked MATCH named its global as 0x0202617C, a transcription
 * slip; the pool word at 0x0200FB20 reads 0x0214617C, the net_err.c module
 * object every sibling uses (literal x42), and the site resolves with it.
 */
void sub_0200FAAC(void)
{
    NetErrWork *g = &g_0214617C;
    u8 t;

    if (sub_02010054() == 0) {
        return;
    }
    if (g->state != 0) {
        return;
    }
    g->state = 1;
    if (func_0203CDBC() != 0) {
        return;
    }
    g->f59 = ((u8 *)func_0203D798())[0x65];
    g->blk48 = *(NetErrBlk *)func_0203CA98();
    g->f58 = (u8)func_0203C990();
    t = g->f59;
    if (t == 1 || t == 2 || t == 6) {
        if ((u32)(g->blk48.w[1] - 1) <= 1) {
            g->f5C = 2;
        } else {
            g->f5C = 1;
        }
        return;
    }
    g->f5C = 2;
}





/*
 * A getter on the module-wide object at 0x0214617C (the same object
 * unit_0200F7C0.c names sub_0200F7C0_Obj): returns field +0x5c when field
 * +0x2c is set, 0 otherwise.
 *
 * EXACT* because the 20 compiled bytes fall 52 short of the disasm.py
 * extent: an unlabelled follower, sub_0200FB38, hides in the run of
 * literal-pool .word data right after this function (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * sub_0200FB38 itself (a conditional store: bump the object's +0x2c field
 * from 1 to 2) is a documented near miss: every write attempt reproduces
 * all twenty bytes but with r0 and r1 swapped throughout, a pure
 * register-numbering difference no source restructuring here changed, in
 * the same class as the codegen near misses in docs/MATCHING.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200FB24.c \
 *       --func sub_0200FB24 --addr 0x0200FB24 --cc 1.1p1
 */
u32 sub_0200FB24(void)
{
    u32 *obj = (u32 *)0x0214617C;

    if (obj[0x2c / 4] != 0) {
        return obj[0x5c / 4];
    }
    return 0;
}





/*
 * Unlabelled Thumb leaf accessor: if the u32 at +0x2c of the object at
 * g_0214617C is 1, set it to 2.
 */
void func_0200FB38(void)
{
    if (g_0214617C.state == 1) {
        g_0214617C.state = 2;
    }
}





/*
 * Unlabelled Thumb leaf: if the u32 at +0x2c of the object at g_0214617C is
 * not 2, store the argument at +0x60, set two flag bytes of the object at
 * g_021461BC, and set +0x2c to 2.
 */
void func_0200FB4C(unsigned int x)
{
    if (g_0214617C.state != 2) {
        g_0214617C.f60 = x;
        g_021461BC[0x1a] = 1;
        g_021461BC[0x19] = 1;
        g_0214617C.state = 2;
    }
}





/*
 * Teardown for the module object at 0x0214617C (same object as
 * sub_0200FB24.c and sub_0200FB38): frees its three owned pointers, frees
 * pool id 8, marks offset 0x19 of a second object at 0x021461BC (which is
 * numerically 0x0214617C + 0x40, but the original loads it through its
 * own fresh literal-pool word rather than as an offset off r4, so the two
 * are declared as separate objects here to keep the same register/pool
 * shape) and forwards flag 1 to func_0200F7B8.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0200FB6C.c \
 *       --func sub_0200FB6C --addr 0x0200FB6C --cc 1.1p1 --thumb
 */
void sub_0200FB6C(void)
{
    struct Sub0200FB6CObj *obj = (struct Sub0200FB6CObj *)0x0214617C;

    func_020307B0(obj->unk00);
    func_020307B0(obj->unk04);
    func_020307B0(obj->unk08);
    func_020306F0(8);

    g_021461BC[0x19] = 0x60;

    func_0200F7B8(1);
}





/*
 * Zeroes two word fields of the module-wide object at 0x0214617C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200FBA0.c \
 *       --func sub_0200FBA0 --addr 0x0200FBA0 --cc 1.1p1
 */
void sub_0200FBA0(void)
{
    g_0214617C.state = 0;
    g_0214617C.f5C = 0;
}





/*
 * A polling loop, gated on func_0203CD98(): returns 1 immediately if it is
 * zero. Otherwise fetches the same status object sub_0200F734 reads
 * (func_0203D798, offset +0x65), resets three link-state counters, then
 * polls func_0203CDBC() once per iteration, quitting the moment it stops
 * returning zero. Each iteration checks the status byte first: 0 or 5
 * means "ready to ask", and if func_02178E4C() then answers 0xa the
 * function returns 0 straight out of the loop.
 *
 * Every concrete byte matches; func_0203CFA0 is called from exactly this
 * one site in the whole ROM, so that relocation stays unresolved under
 * the honesty rule. The other nine calls all resolve.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0200FBB0.c \
 *       --func sub_0200FBB0 --addr 0x0200FBB0 --cc 1.1p1
 *
 * The `matched` class does not reach it: func_0203CFA0 is not matched, so
 * no EXACT entry covers that address. Closes to EXACT the day either
 * func_0203CFA0 gets a second caller elsewhere in the image, or is itself
 * matched.
 */
u32 sub_0200FBB0(void)
{
    u8 *obj;
    u32 flag;

    if (func_0203CD98() != 0) {
        obj = func_0203D798();
        func_0203CF04();
        func_0203CEAC(0);
        func_0203D0D0();
        flag = 1;

        for (;;) {
            if (obj != 0) {
                u8 v = obj[0x65];
                if (v == 0 || v == 5) {
                    if (func_02178E4C() == 0xa) {
                        return 0;
                    }
                }
            }
            func_0203CFA0();
            func_0201034C();
            func_0208459C(flag, flag);
            if (func_0203CDBC() == 0) {
                continue;
            }
            break;
        }
    }

    return 1;
}





/*
 * The net_err.c error screen's blocking entry: bail unless the module is
 * live (func_02010054), abort on a1 == 1, and only when the module object's
 * +0x2c state is 2 run the screen -- re-init graphics (sub_0200FD38) for a
 * link-mode error (+0x59 in 1, 2, 6), poll the link (sub_0200FBB0), draw
 * (func_020101D4 or sub_0200FD38), then wait for A/B to be released and
 * pressed again (the two PAD loops are NitroSDK's PAD_DetachedCover and
 * PAD_Read inlines plus a filter that drops the opposing D-pad bit), then
 * tear down.  Two lessons: the 0x2c test is a WRAPPING if, not an early
 * return (the shared 'return 0' sits after the body); and the object is a
 * named local 'u8 *g', which makes mwccarm rematerialise the pool word per
 * access and reach +0x59 with 'adds' -- the extern spelled directly folds
 * to a second pool word g+0x40 instead.
 */
u32 func_0200FC0C(u32 a0)
{
    NetErrWork *g = &g_0214617C;
    u32 mode;

    if (func_02010054() == 0) {
        return 0;
    }
    if (a0 == 1) {
        sub_0200FA94();
    }
    if (g->state == 2) {
        mode = 0;
        {
            u8 t = g->f59;
            if (t == 1 || t == 2 || t == 6) {
                mode = 1;
            }
        }
        if (mode == 1) {
            sub_0200FD38(a0, 1);
        }
        if (sub_0200FBB0() == 0) {
            sub_0200FA94();
        }
        if (mode == 1) {
            g->hBlank = GX_HBlankIntr(0);
            g->vBlank = GX_VBlankIntr(0);
            func_020101D4(a0, 0);
        } else {
            sub_0200FD38(a0, 0);
        }
        while (PAD_DetachedCover() == 1 || (KeyFilter(PAD_Read()) & 3) != 0) {
            func_0201034C();
        }
        while (PAD_DetachedCover() == 1 || (KeyFilter(PAD_Read()) & 3) == 0) {
            func_0201034C();
        }
        sub_0200FEBC(0);
        sub_0200FBA0();
        g->f30 = 0;
    return 1;
    }
    return 0;
}




static inline int GXS_GetVisibleWnd(void)
{
    return (int)((reg_GXS_DB_DISPCNT & 0xE000) >> 13);
}




static inline GXBg01Control G2_GetBG1Control(void)
{
    return *(volatile GXBg01Control *)&reg_G2_BG1CNT;
}


static inline void G2_SetBG1Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                    GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    reg_G2_BG1CNT = (u16)((reg_G2_BG1CNT & 0x43) | (screenSize << 14) |
                          (colorMode << 7) | (screenBase << 8) |
                          (charBase << 2) | (bgExtPltt << 13));
}




static inline void G2_BG1Mosaic(BOOL enable)
{
    if (enable) {
        reg_G2_BG1CNT |= 0x40;
    } else {
        reg_G2_BG1CNT &= ~0x40;
    }
}




/*
 * net_err.c's graphics save-and-blank: saves both master brightness levels,
 * the H/V-blank interrupt enables, two VRAM bank states, DISPCNT, the sub
 * window mask and BG1CNT into the module object at 0x0214617C, reprograms
 * BG1 as a 16-colour text layer, backs up BG1's character, screen and the
 * first palette block (unless +0x59 is 0x60), then draws the error screen
 * (sub_02010068 and func_020101D4).  The SDK inlines are NitroSDK's gx.h /
 * g2.h shapes (GX_SetVisiblePlane, G2_SetBG1Control with the saved control
 * word's bgExtPltt bit, G2_BG1Mosaic).  The lever that closed it (the
 * earlier note was 20 bytes short): the two backup copies read their buffer
 * pointer and call the pointer getter into NAMED LOCALS, dst first, which
 * loads the buffer before the call and raises the pressure that spills a0
 * to [sp] exactly as the image does.
 */
void sub_0200FD38(u32 a0, u32 a1)
{
    NetErrWork *g = &g_0214617C;

    if (func_02010054() == 0) {
        return;
    }
    g->bright = GXx_GetMasterBrightness_(&reg_GX_MASTER_BRIGHT);
    g->subBright = GXx_GetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT);
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, -16);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, -16);
    if (a1 == 0) {
        g->hBlank = GX_HBlankIntr(0);
        g->vBlank = GX_VBlankIntr(0);
    }
    g->bankBG = func_020808F4();
    g->bankSubBG = func_020809A0();
    GX_SetBankForBG(4);
    g->dispCnt.raw = reg_GX_DISPCNT;
    GX_SetGraphicsMode(1, 0, 0);
    GX_SetVisiblePlane(2);
    GX_SetVisibleWnd(0);
    g->subWnd = GXS_GetVisibleWnd();
    GXS_SetVisibleWnd(0);
    g->bg1Cnt = G2_GetBG1Control();
    G2_SetBG1Control(0, 0, 0, 1, g->bg1Cnt.bgExtPltt);
    G2_BG1Mosaic(0);
    reg_G2_BG1OFS = 0;
    if (g->f59 != 0x60) {
        void *dst;
        void *src;
        dst = g->bg1Char;
        src = G2_GetBG1CharPtr();
        MIi_CpuCopy16(src, dst, 0x4000);
        dst = g->bg1Scr;
        src = G2_GetBG1ScrPtr();
        MIi_CpuCopy16(src, dst, 0x800);
        MIi_CpuCopy16((void *)0x05000000, g->pltt, 0x20);
    }
    g->bldCnt = reg_G2_BLDCNT;
    g->bldCnt = reg_G2S_DB_BLDCNT; /* sic: stored over bldCnt again, as in the image */
    reg_G2_BLDCNT = 0;
    reg_G2S_DB_BLDCNT = 0;
    g->f38 = func_02043668();
    func_020435F4(0);
    g->pltt0 = *(volatile u16 *)0x05000400;
    *(volatile u16 *)0x05000400 = 0x7eea;
    if (g_0214617C.f59 == 0x60) {
        sub_02010068(1);
    } else {
        sub_02010068(0);
        func_020101D4(a0, a1);
    }
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, 0);
}




static inline void G2_SetBG1Offset(int hOffset, int vOffset)
{
    reg_G2_BG1OFS = (u32)(((hOffset << 0) & 0x1FF) | ((vOffset << 16) & 0x1FF0000));
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200FEBC.c  *       --func sub_0200FEBC --addr 0x0200FEBC --cc 1.1p1 --thumb
 *
 * net_err.c: restore the 2D state sub_0200FD38 saved (docs/families/
 * net_err.h).  Wave 14 closed the 43-byte bitfield-unpack schedule of
 * docs/notes/sub_0200FEBC.c.txt: G2_SetBG1Control's parameters are the
 * SDK's ENUM types (GXBGScrSizeText, GXBGColorMode, GXBGScrBase,
 * GXBGCharBase, GXBGExtPltt), not int.  With enum parameters mwcc
 * materialises each bitfield argument into a temporary, right to left,
 * before the inline body reads reg_G2_BG1CNT; with int parameters it
 * substitutes the extractions into the expression after the read.
 */
void sub_0200FEBC(BOOL keepDark)
{
    NetErrWork *w = &g_0214617C;
    u32 x;
    u32 y;

    if (func_02010054() == 0) {
        return;
    }
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, -16);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, -16);
    *(volatile u16 *)0x05000400 = w->pltt0;
    func_020435F4(w->f38);
    reg_G2_BLDCNT = w->bldCnt;
    reg_G2S_DB_BLDCNT = w->subBldCnt;
    MIi_CpuCopy16(w->bg1Char, G2_GetBG1CharPtr(), 0x4000);
    MIi_CpuCopy16(w->bg1Scr, G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuCopy16(w->pltt, (void *)0x05000000, 0x20);
    G2_SetBG1Control(w->bg1Cnt.screenSize, w->bg1Cnt.colorMode, w->bg1Cnt.screenBase,
                     w->bg1Cnt.charBase, w->bg1Cnt.bgExtPltt);
    G2_BG1Mosaic(w->bg1Cnt.mosaic);
    func_0203D828(&x, &y);
    G2_SetBG1Offset(x, y);
    GX_SetGraphicsMode(w->dispCnt.dispMode, w->dispCnt.bgMode, w->dispCnt.bg0_2d3d);
    GX_SetVisiblePlane(w->dispCnt.visiblePlane);
    GX_SetVisibleWnd(w->dispCnt.visibleWnd);
    GXS_SetVisibleWnd(w->subWnd);
    func_020809A0();
    func_020808F4();
    GX_SetBankForBG(w->bankBG);
    GX_SetBankForSubBG(w->bankSubBG);
    GX_HBlankIntr(w->hBlank);
    GX_VBlankIntr(w->vBlank);
    OS_WaitIrq(1, 1);
    if (keepDark == 0) {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, w->bright);
        GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, w->subBright);
    }
}



asm void CTRDGi_IsTaskAvailable_02010054(void)
{
    ldr r0, =0x0214617C
    ldr r0, [r0]
    cmp r0, #0
    beq _zero
    mov r0, #1
    bx lr
_zero:
    mov r0, #0
    bx lr
}



/*
 * blocked: literal.  Every concrete byte matches; the only four unresolved
 * sites are the four ABS32 pool words for g0209DEA0 (base+0/+2/+4/+6, the
 * four u16 fields of an 8-byte-stride table indexed by a0).  The word
 * 0x0209DEA0 appears in exactly one literal pool image-wide, at 0x02010148,
 * which is inside this function's own extent, so no witness exists outside
 * the compared range and no cut can free it.  Needs a second referrer of
 * the table, or a matched neighbour that pools the same address.
 *   func_0207E24C  0x0207E24C  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_020862F0  0x020862F0  arm
 *   func_02082A60  0x02082A60  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0207DFB4  0x0207DFB4  arm
 *   func_02062AD4  0x02062AD4  arm
 *   func_02062A98  0x02062A98  arm
 */
void sub_02010068(u32 a0)
{
    void *h;
    struct res0 *r0p;
    struct res1 *r1p;
    struct res2 *r2p;
    u32 sp0;
    u16 id;

    func_02082A7C(0, func_0207E24C(), 0x4000);

    id = g0209DEA0[a0].f0;
    h = (void *)func_0204A1BC(id, g0209DEA0[a0].f2, 0, 1);
    if (func_02062A4C(h, (void **)(&r0p)) != 0) {
        u32 n;
        void *src;
        func_020862F0(r0p->ptr, r0p->len);
        n = r0p->len;
        src = func_0207E24C();
        func_02082A60(r0p->ptr, src, n);
    }
    func_020307B0(h);

    h = (void *)func_0204A1BC(id, g0209DEA0[a0].f4, 0, 1);
    if (func_02062B30(h, (void **)(&r1p)) != 0) {
        u32 n;
        void *src;
        func_020862F0(r1p->buf, r1p->len);
        n = r1p->len;
        src = func_0207DFB4();
        func_02082A60(r1p->buf, src, n);
    }
    func_020307B0(h);

    h = (void *)func_0204A1BC(id, g0209DEA0[a0].f6, 0, 1);
    func_02062AD4(h, (void **)(&sp0));
    if (func_02062A98(h, (void **)(&r2p)) != 0) {
        func_020862F0(r2p->ptr, 0x20);
        func_02082A60(r2p->ptr, (void *)0x05000000, 0x20);
    }
    func_020307B0(h);
}
