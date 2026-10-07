/*
 * file:     mystery_data.c
 * unit:     yes
 * function: sub_02009A34, sub_02009A54, sub_02009A74, sub_02009AE4, sub_02009B3C, sub_02009B80, sub_02009BB8, sub_02009C24, sub_02009CA8, func_02009CB0, func_02009CC0, sub_02009CE4, sub_02009D08, sub_02009D1C, sub_02009D50, sub_02009D9C, sub_02009DA4, sub_02009DB8, sub_02009DE8, sub_02009E40, sub_02009E54, sub_02009E74, sub_02009E8C, sub_02009EA8, sub_02009EB0, func_02009EC8, func_02009ED4, func_02009EDC, func_02009F0C, func_02009F1C, func_02009F50, func_02009F7C, func_02009FD4, func_0200A000, func_0200A034, func_0200A094, func_0200A0C8, func_0200A0E4, func_0200A104, func_0200A13C, func_0200A170, func_0200A1A8, func_0200A1E4, func_0200A21C, func_0200A254, func_0200A2B8, func_0200A2D8, func_0200A300, func_0200A338, func_0200A348, func_0200A350, sub_0200A358, func_0200A3D0, func_0200A3FC, func_0200A400, func_0200A418, func_0200A41C, func_0200A43C, func_0200A480, func_0200A49C, func_0200A4B8, func_0200A50C, func_0200A53C, func_0200A544, func_0200A5F8, func_0200A604, func_0200A628, func_0200A630, func_0200A640, func_0200A644, func_0200A680, func_0200A6BC, func_0200A6F8, func_0200A714, func_0200A73C, func_0200A750, func_0200A75C, func_0200A768, func_0200A780, func_0200A788, func_0200A7A0, func_0200A7AC, func_0200A7B8, func_0200A7C0, func_0200A7C8, func_0200A7D4, func_0200A7E0, func_0200A7EC, func_0200A7F8, func_0200A800, func_0200A81C, func_0200A828, func_0200A834, func_0200A840, func_0200A848, func_0200A864, func_0200A870, func_0200A884, func_0200A890, func_0200A898, func_0200A8A0, func_0200A8AC, func_0200A8C8, func_0200A8D0, func_0200A8E4, func_0200A8F8, func_0200A908, func_0200A930, sub_0200A940, sub_0200A9A4, sub_0200A9D4, func_0200AA00, sub_0200AA68, sub_0200AB04, sub_0200AB24, func_0200AB2C, func_0200AB50, func_0200ABE0, sub_0200AC14, func_0200ACD0, sub_0200AD00, func_0200AD6C, func_0200AD78, func_0200AD7C, func_0200AD8C, func_0200AD94, func_0200ADB4, func_0200ADB8, func_0200ADD0, func_0200ADD8, func_0200ADE0, func_0200ADE8, func_0200ADF0, func_0200AE08, func_0200AE14, func_0200AE18, func_0200AE3C, func_0200AE54, func_0200AEE8, func_0200AFD4, func_0200B040, func_0200B074, func_0200B078, func_0200B110, func_0200B1A8, func_0200B1C4, func_0200B1D4, func_0200B1E0, func_0200B1F8, func_0200B204, func_0200B214, func_0200B254
 * address:  0x02009A34
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
 *   DWC_IsValidFriendData 0x020596D8  arm
 *   func_02045994         0x02045994  arm
 *   func_02045A38         0x02045A38  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0203F4E4  0x0203F4E4  arm
 *   DWC_CreateExchangeToken 0x020599BC  arm
 *   func_020598EC    0x020598EC  arm
 *   sub_020071CC           0x020071CC  thumb
 *   DWC_CheckValidConsole  0x02059760  arm
 *   DWC_CheckHasProfile    0x020597C8  arm
 *   DWC_GetGsProfileId     0x020598EC  arm
 *   MI_CpuMove   0x02083194  arm
 *   func_020071CC  0x020071CC  thumb
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_021DFDC0    0x021DFDC0  thumb
 *   func_021DFE00    0x021DFE00  thumb
 *   g_020A71A4      0x020A71A4  data
 *   sub_020071EC   0x020071EC  thumb
 *   sub_0200A480   0x0200A480  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021DFC20  0x021DFC20  thumb  ov228
 *   func_021DFE90  0x021DFE90  thumb  ov228
 *   func_021DFEAC  0x021DFEAC  thumb  ov228
 *   ov_id_E4       0x000000E4  data
 *   ov_abs_e4      0x000000E4  data
 *   func_021DFDB8  0x021DFDB8  thumb  ov228
 *   func_02034A5C  0x02034A5C  arm
 *   func_02161D98    0x02161D98  thumb  ov010
 *   func_02161EEC    0x02161EEC  thumb  ov010
 *   func_02161F00    0x02161F00  thumb  ov010
 *   sub_0200A8AC   0x0200A8AC  thumb
 *   sub_0200A8D0   0x0200A8D0  thumb
 *   sub_0200AA00   0x0200AA00  thumb
 *   sub_020056EC   0x020056EC  thumb
 *   tbl_020A1B38   0x020A1B38  data
 *   _u32_div_f     0x0209C2B0  arm
 *   sub_0200ACD0  0x0200ACD0  thumb
 *   sub_0200AB50  0x0200AB50  thumb
 *   sub_0200ABE0  0x0200ABE0  thumb
 *   memcpy  0x02082D44  arm
 *   sub_0201F41C   0x0201F41C  thumb
 *   func_02082AC0  0x02082AC0  arm
 *   func_020173EC 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0200ADF0_File  0x020A71B4  data
 */
#include "../../matched/include/Obj11227.h"
#include "../../matched/include/Obj15577.h"
#include "../../matched/include/Obj15578.h"
#include "../../matched/include/Obj15579.h"
#include "../../matched/include/Obj15580.h"
#include "../../matched/include/Obj15581.h"
#include "../../matched/include/Obj15585.h"
#include "../../matched/include/Obj15586.h"
#include "../../matched/include/Obj15587.h"
#include "../../matched/include/Obj04037.h"
#include "../../matched/include/Obj11228.h"
#include "../../matched/include/Obj11229.h"
#include "../../matched/include/Obj11230.h"
#include "../../matched/include/Obj15588.h"
#include "../../matched/include/Obj11231.h"
#include "../../matched/include/Obj17006.h"

struct Strbuf;
struct U16Vec;
struct RtcDate;
struct Sub020097BCObj;
struct DWCstAccUserData;
struct Sub0200852CObj;
struct Sub020071CCCtrl;
struct Obj;
struct Sub020071E4Ctrl;
struct Date;
struct Rec;
struct MsgBank;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Sub020097BCFriend {
    u8 unk00[0xC];
};

struct Sub020097BCEnt {
    u8  unk00[0x1C];
    u32 unk1C;
    u32 unk20;
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u16 unk2A;
    u8  unk2C;
    u8  unk2D;
    u8  unk2E;
    u8  unk2F_0 : 2;
    u8  unk2F_2 : 6;
};

struct Sub020097BCObj {
    u8 unk000[0x40];
    struct Sub020097BCFriend unk040[0x20];
    struct Sub020097BCEnt    unk1C0[32];
    u8 unk7C0[4];
};

typedef signed int     s32;

struct Sub0203F4E4Date {
    s32 year;
    s32 month;
    s32 day;
    s32 week;
};

struct Sub02009D9CObj_0 {
    u8 unk000[0xD54];
};

struct Sub0200852CObj {
    u8 unk00[0x1B];
    u8 unk1B;
    u8 unk1C;
    u8 unk1D[3];
};

struct Sub02009D9CObj_1 {
    struct Sub0200852CObj unk000[100];
    u8  unkC80[0xD0];
    u32 unkD50;
};

typedef struct { int w[0x33]; } Slot;

struct Obj {
    void *unk00;
    u32   unk04;
    void *unk08;
};

struct Hdr {
    u16 unk00;
    u16 unk02;
};

struct BigSub6 { u8 unk0; u8 unk1[5]; };

struct BigSub4 { u8 unk0; u8 unk1[3]; };

struct Big {
    u8 unk000[0x1B0];
    struct BigSub6 unk1B0[8];
    struct BigSub4 unk1E0[10];
    u8  unk208[0x4A];
    u16 unk252;
    u16 unk254;
    u16 unk256;
    u8  unk258[0x20];
    u8  unk278[0x20];
    u8  unk298[4];
    u8  unk29C;
    u8  unk29D;
    u8  unk29E;
    u8  unk29F;
    u8  unk2A0[4];
};

struct Bits {
    u32 unk00_0  : 16;
    u32 unk00_16 : 5;
    u32 unk00_21 : 11;
};

struct Rec2DC {
    u8 unk000[0x1E8];
    u8 unk1E8[0x14];
    u8 unk1FC[0xE0];
};

struct Rec2Head {
    u8 unk000[0x1E8];
};

struct Rec2 {
    u8 unk000[0x1E8];
    u8 unk1E8[0x14];
    u8 unk1FC[0x14];
};

struct Entry_0 {
    u8  unk00[0x10];
    u32 f10_0  : 7;
    u32 f10_7  : 10;
    u32 f10_17 : 1;
    u32 f10_18 : 13;
    u32 f10_31 : 1;
    u32 unk14;
    u16 unk18;
    u8  unk1A;
    u8  f1B_0 : 6;
    u8  f1B_6 : 1;
    u8  f1B_7 : 1;
};

struct Rec {
    struct Entry_0 entries[30];
    u32 f348_0 : 8;
    u32 f348_8 : 24;
};

typedef struct { u8 pad[24]; u16 n; u8 a; u8 b : 6, c : 1, d : 1; } Entry_0;

typedef struct { u32 v : 8; u32 rest : 24; } B;

struct T0200A9A4 {
    u8  pad00[0x10];
    u32 f10;
    u32 f14;
    u8  pad18[3];
    u8  f1b;
};

typedef signed short   s16;

struct Date {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
};

typedef struct Entry_1 {
    u16 w0[8];
    u32 b0 : 7;
    u32 b1 : 10;
    u32 b2 : 1;
    u32 b3 : 4;
    u32 b4 : 4;
    u32 b5 : 5;
    u32 b6 : 1;
    u32 f14;
    u16 f18;
    u8  f1a;
    u8  c0 : 6;
    u8  c1 : 1;
    u8  c2 : 1;
} Entry_1;

typedef struct {
    u32 b0 : 8;
    u32 b8 : 24;
} Flags;

typedef struct {
    Entry_1 entries[30];
    u32   f348;
} Rec;

struct Bits0200AB04 {
    u8    lo : 7;
    u8    flag : 1;
};

struct Rec0200AB04 {
    u8 pad00[0x1b];
    struct Bits0200AB04 bits;
};

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 key  : 7;
    u32 off  : 10;
    u32 pad  : 14;
    u32 flag : 1;
    u32 f14;
    u32 f18;
} Ent;

typedef struct Rec0200AD8C {
    unsigned char pad[0xEC];
    u16 fEC;
} Rec0200AD8C;

typedef struct Rec0200AD94 {
    unsigned char pad[0xEC];
    u16 fEC;
} Rec0200AD94;

typedef signed char    s8;

struct Reg {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u8  unk04;
    u8  unk05;
    u16 unk06;
    u8  unk08;
    u8  unk09;
    u8  unk0A[0x52];
    u8  unk5C[0x4C];
    u16 unkA8;
    u8  unkAA;
    u8  unkAB;
    u8  unkAC[7];
    u8  unkB3;
    u8  unkB4;
    u8  unkB5;
    u8  unkB6;
    u8  unkB7;
    u8  unkB8;
    u8  unkB9;
    u8  unkBA;
    u8  unkBB;
};

struct RegB {
    u8  unk00[0xEE];
    u16 unkEE;
    u32 unkF0;
    u32 unkF4;
};

struct RegAC {
    u8 unk0[7];
    u8 unk7;
};

struct Reg2 {
    struct Reg reg;
    s32 unkBC;
    u8  unkC0[0x92];
    s16 unk152;
    s8  unk154;
    s8  unk155;
    s8  unk156;
    s8  unk157;
    s8  unk158;
    s8  unk159;
    s8  unk15A;
    s8  unk15B;
    u8  unk15C;
    u8  unk15D;
    u16 unk15E;
};

struct Rec160 {
    u32 unk000[0x58];
};

struct Rec1E {
    u16 unk00[6];
    u8  unk0C[6];
    u8  unk12;
    u8  unk13;
    u8  unk14[10];
};

struct RecBig {
    u8 unk000[0x2C0];
    struct Rec1E unk2C0[1];
};

extern int  DWC_IsValidFriendData(const void *friendData);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void func_0203F4E4(struct RtcDate *date);
extern void DWC_CreateExchangeToken(void *account, void *out);
extern int func_020598EC(struct DWCstAccUserData *userdata, void *frienddata);
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern int  DWC_CheckValidConsole(void *account);
extern int  DWC_CheckHasProfile(void *account);
extern void DWC_GetGsProfileId(void *account, void *out);
extern u32 sub_02008530(const struct Sub0200852CObj *obj);
extern u8  sub_02008550(const struct Sub0200852CObj *obj);
extern const void *sub_020084F4(const void *p);
extern void MI_CpuMove(const void *src, void *dest, u32 size);
extern int sub_02008468(void);
extern u8  sub_02008554(const struct Sub0200852CObj *obj);
extern void sub_02008558(struct Sub0200852CObj *obj, u8 value);
extern u8  sub_0200855C(const struct Sub0200852CObj *obj);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void func_02082BCC(void *p, int c, u32 n);
extern void func_02082D44(void *dst, void *src, int n);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void  func_021DFDC0(void *p);
extern int func_02012DAC(int a0);
extern int  func_021DFE00(void *p);
extern int func_02012DD0(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_0200A358(unsigned char *p, void *ctrl, int mode, int heap);
extern u32 func_020307B0(void *p);
extern u8    sub_020071EC(const struct Sub020071E4Ctrl *ctrl);
extern void  sub_0200A480(struct Obj *p);
extern int func_02034AC4(int id);
extern void *func_021DFC20(u32 heap);
extern u8 func_021DFE90(u8 *p);
extern void *func_021DFEAC(u8 *p);
extern void func_021DFDB8(void *v);
extern void func_02034A5C(int p);
extern u32 func_0203F2FC(const u8 *p, u32 len);
extern void func_0203F328(u16 *p, u32 size, u32 seed);
extern void func_0203F37C(void *base, u32 size, u32 seed);
extern void func_02161D98(char *p);
extern void func_02161EEC(u16 *p);
extern void func_02161F00(void *p);
extern s32 sub_0200A8AC(struct Rec *r);
extern u8 sub_0200A8D0(struct Rec *r, u32 index);
extern u8 sub_0200AA00(u32 a0, u32 a1, struct Date *src);
extern u32 sub_020056EC(u32 range);
extern s32  func_0203F540(struct RtcDate *d);
extern char *sub_0200ACD0(char *base, int count, int target);
extern u8     sub_0200AB50(Entry_1 *list, s32 n, Entry_1 *dst);
extern s32    sub_0200ABE0(u8 *base, s32 n, u8 *other);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void sub_0201F41C(const u16 *src, u16 *dst, u32 n);
extern void func_02082AC0(u32 val, void *dst, u32 size);
extern u32 func_020173EC(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045C04(struct Rec *rec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct Sub020097BCObj *sub_02009860(struct Sub020097BCObj *obj);
u32 sub_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
struct Sub020097BCEnt *sub_020099D4(struct Sub020097BCObj *obj, int i);
int sub_02009A1C(struct Sub020097BCObj *obj, u32 i);
u32 sub_02009A34(struct Sub020097BCObj *obj);
u32 sub_02009A54(struct Sub020097BCObj *obj);
void sub_02009A74(struct Sub020097BCObj *obj, u32 i);
void sub_02009AE4(struct Sub020097BCObj *obj, u32 dest, u32 src);
void sub_02009B3C(struct Sub020097BCObj *obj);
void sub_02009B80(struct Sub020097BCObj *obj, int i);
void sub_02009BB8(struct Sub020097BCObj *obj, int i, int a, int b, int c);
void sub_02009C24(struct Sub020097BCObj *obj, int src, int dest);
void sub_02009CA8(void *account, void *out);
int func_02009CB0(int a0, int a1);
int func_02009CC0(void *a0);
u32 sub_02009CE4(struct Sub020097BCObj *obj);
struct Sub020097BCObj *sub_02009D08(void *sys);
int sub_02009D1C(struct Sub020097BCObj *obj, struct Sub0200852CObj *p, u32 *out);
int sub_02009D50(struct Sub020097BCObj *obj, const void *unused, u32 id, u32 kind, u32 *out);
u32 sub_02009D9C(void);
void sub_02009DA4(struct Sub02009D9CObj_0 *obj);
int sub_02009DB8(struct Sub02009D9CObj_1 *obj, u32 id);
void sub_02009DE8(struct Sub02009D9CObj_1 *obj, struct Sub0200852CObj *p);
u32 sub_02009E40(struct Sub02009D9CObj_1 *obj, u32 i);
struct Sub0200852CObj *sub_02009E54(struct Sub02009D9CObj_1 *obj, u32 i);
u32 sub_02009E74(struct Sub02009D9CObj_1 *obj, u32 id);
int sub_02009E8C(struct Sub02009D9CObj_1 *obj);
u32 sub_02009EA8(const struct Sub02009D9CObj_1 *obj);
void sub_02009EB0(struct Sub02009D9CObj_1 *obj);
void *func_02009EC8(void *sys);
u32 func_02009ED4(void);
void func_02009EDC(void *a0);
u32 func_02009F0C(u32 a);
int func_02009F1C(void *a0);
int func_02009F50(char *p, unsigned int idx);
void func_02009F7C(void *p, unsigned int idx);
void *func_02009FD4(char *p, unsigned int idx);
int func_0200A000(char *p, int idx, void *buf);
int func_0200A034(void *p, void *arg);
void func_0200A094(void *p, unsigned int idx);
u32 func_0200A0C8(u8 *p);
u32 func_0200A0E4(u8 *p, u32 a);
int func_0200A104(char *p, unsigned int idx);
void func_0200A13C(u8 *p, u32 i);
int func_0200A170(char *p);
int func_0200A1A8(char *p, unsigned int bit);
void func_0200A1E4(void *p, unsigned int idx);
int func_0200A21C(u8 *obj);
void func_0200A254(void *p, unsigned int a, unsigned int b);
void func_0200A2B8(void *a0, int a1);
int func_0200A2D8(void *a0, int a1);
void *func_0200A300(void *a0, void *a1, void *a2);
void func_0200A338(void *a0);
u32 func_0200A348(struct Obj *obj);
int func_0200A350(struct Obj *a0);
void sub_0200A358(u8 *p, void *ctrl, int a2, int a3);
void func_0200A3D0(void *obj);
u32 func_0200A3FC(struct Obj *obj);
u32 func_0200A400(struct Obj *obj);
void *func_0200A418(struct Obj *obj);
void *func_0200A41C(struct Obj *obj);
void *func_0200A43C(struct Obj *obj, u32 index);
void func_0200A480(struct Obj *obj);
void func_0200A49C(struct Obj *obj);
void func_0200A4B8(void *base, u32 kind);
void func_0200A50C(void *base, u32 kind);
u32 func_0200A53C(void);
void func_0200A544(struct Big *p);
void *func_0200A5F8(void *sys);
void func_0200A604(struct Big *p);
u8 *func_0200A628(struct Big *p);
u32 func_0200A630(struct Bits *p);
void func_0200A640(void);
u32 func_0200A644(struct Big *p, u8 index);
u32 func_0200A680(struct Big *p, u8 index);
void func_0200A6BC(struct Big *p, u32 index);
void func_0200A6F8(struct Big *p);
u32 func_0200A714(struct Big *p);
u32 func_0200A73C(struct Big *p);
struct BigSub4 *func_0200A750(struct Big *p, u32 index);
u16 func_0200A75C(struct Big *p);
void func_0200A768(struct Big *p);
u16 func_0200A780(struct Big *p);
void func_0200A788(struct Big *p);
u8 func_0200A7A0(struct Big *p, u32 index);
void func_0200A7AC(struct Big *p, u32 index, u8 value);
u8 func_0200A7B8(struct Big *p);
void func_0200A7C0(struct Big *p, u8 value);
u8 func_0200A7C8(struct Big *p);
void func_0200A7D4(struct Big *p, u8 value);
u8 func_0200A7E0(struct Big *p);
void func_0200A7EC(struct Big *p, u8 value);
u8 *func_0200A7F8(struct Big *p);
void func_0200A800(struct Big *p, s32 delta);
u16 func_0200A81C(struct Big *p);
u32 func_0200A828(struct Big *p);
void func_0200A834(struct Big *p, u8 value);
u32 func_0200A840(void);
void func_0200A848(void **a0);
void *func_0200A864(void *sys);
void func_0200A870(struct Rec2Head *dest, const struct Rec2Head *src);
void func_0200A884(const struct Rec2Head *src, struct Rec2Head *dest);
u8 *func_0200A890(struct Rec2 *p);
u8 *func_0200A898(struct Rec2 *p);
void *func_0200A8A0(void *sys);
s32 func_0200A8AC(struct Rec *r);
struct Entry_0 *func_0200A8C8(struct Rec *r, u32 index);
u8 func_0200A8D0(struct Rec *r, u32 index);
u16 func_0200A8E4(struct Rec *r, u32 index);
u32 func_0200A8F8(struct Rec *r, u32 index);
void func_0200A908(const Entry_0 *p, u32 i, u16 *n, u8 *a, u8 *b, u8 *c);
u8 func_0200A930(char *p);
int sub_0200A940(void *a0, int a1, int a2, void *a3);
int sub_0200A9A4(struct T0200A9A4 *o, u32 v);
int sub_0200A9D4(struct T0200A9A4 *o, u32 v);
u8 func_0200AA00(u32 a0, u32 a1, struct Date *src);
u8 sub_0200AA68(Rec *r, const void *src, u16 a2, u8 a3, u8 s0, u8 s1, u32 s2, u16 s3, u8 s4, u8 s5, u8 s6);
void sub_0200AB04(struct Rec0200AB04 *o);
int sub_0200AB24(void);
void func_0200AB2C(void *a0);
u8 func_0200AB50(Ent *list, s32 n, Ent *dst);
int func_0200ABE0(u8 *a0, int n, u8 *b);
void sub_0200AC14(Entry_1 *self, const void *src, u32 a2, u32 a3, u8 p0, u8 p1, u8 p2, u32 p3, u16 p4, u8 p5, u8 p6, u8 p7);
char *func_0200ACD0(char *base, int count, int target);
void sub_0200AD00(Entry_1 *base, int n, Entry_1 *ref);
void *func_0200AD6C(void *sys);
int func_0200AD78(void);
void func_0200AD7C(void *rec);
u16 func_0200AD8C(const Rec0200AD8C *p);
void func_0200AD94(Rec0200AD94 *p, u16 v);
void OS_KillThread(void *thread, void *arg1);
void func_0200ADB4(void);
void func_0200ADB8(void *dest, const void *src, u32 a2);
void func_0200ADD0(struct RegB *p, u32 value);
void func_0200ADD8(struct RegB *p, u32 value);
u16 func_0200ADE0(struct RegB *p);
u32 func_0200ADE8(void);
struct Reg *func_0200ADF0(u32 heap);
void func_0200AE08(const struct Reg *src, struct Reg *dest);
void func_0200AE14(void);
void func_0200AE18(struct Reg *p, void *dest);
void *func_0200AE3C(struct Reg *p, u32 heap);
u32 func_0200AE54(struct Reg *p, u32 id);
void func_0200AEE8(struct Reg *p, u32 id, s32 value);
u32 func_0200AFD4(struct Reg *p, u32 id, s32 n);
void func_0200B040(struct Reg *p, struct RegAC *out);
u8 *func_0200B074(struct Reg2 *p);
s32 func_0200B078(struct Reg2 *p, u32 id);
void func_0200B110(struct Reg2 *p, u32 id, s32 value);
u32 func_0200B1A8(struct Reg2 *p);
u16 func_0200B1C4(struct Reg2 *p);
struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index);
void func_0200B1E0(struct Rec160 *arr, u32 index, const struct Rec160 *src);
void func_0200B1F8(struct Rec1E *p);
struct Rec1E *func_0200B204(struct RecBig *p, u32 index);
s32 func_0200B214(struct Rec1E *p, u32 id, u8 n);
void func_0200B254(struct Rec1E *p, int id, u8 n, s32 value);
extern char g_020A71A4[];
extern u8    ov_id_E4[];
extern u8   ov_abs_e4[];
extern s16  tbl_020A1B38[];
extern const char func_0200ADF0_File[];


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           sub_02009B3C, sub_02009B80, sub_02009BB8
 *
 * alias: wifilist.c's list maintenance.  The two parallel arrays of
 * src/matched/unit_02009860.c hold 32 slots each, an 0x0C-byte DWC friend
 * record at +0x40 and an 0x30-byte entry at +0x1C0, and every function here
 * moves both together.
 *
 * sub_02009B3C is the compaction pass and is the one worth reading.  It scans
 * the 32 slots keeping `j` at the first hole it has seen, and when it finds a
 * used slot after a hole it moves it down with sub_02009AE4 and then sets
 * `i = -1` so the `i++` restarts the scan from zero.  The compiler cross-jumps
 * the two assignments to `j`: the restart arm's `j = -1` and the hole arm's
 * `j = i` become one `adds r5, r4, #0` reached from both, which is only
 * correct because `i` has just been set to -1 on the first path.  Reading that
 * shared instruction as a single statement is what makes the restart visible.
 *
 * -1 costs three materialisations here, one in a register and two in stack
 * slots, because the function is out of callee-saved registers: the same
 * constant is the loop's sentinel, the value assigned to `i`, and the value
 * compared against in the other arm.
 *
 * The tail of sub_02009A74 is where the shape of the source is visible.  It
 * clears slot 31 of both arrays, and the original reaches it as base plus
 * offset in two separate adds: `obj + 0x1C0` and then `+ 0x5D0`, with the
 * friend array's `+ 0x174` derived from that same 0x5D0 by a `lsrs #2`.
 * Written as `&obj->unk1C0[31]` the compiler folds the two constants into one
 * 0x790 and the tail is 34 bytes different; only a local pointer, assigned
 * from the array *after* the loop and indexed with the literal 31, keeps them
 * apart.  Assigning the same pointers before the loop is wrong too: they then
 * stay live in callee-saved registers and the reload of `obj` from its stack
 * slot disappears.
 *
 * sub_02009B80 stamps the entry with the date.  func_0203F4E4 fills a 0x10-byte
 * record on the stack whose first three words are year, month and day, and the
 * year is stored as `year + 2000`, which is the `movs r0, #0x7D; lsls r0, #4`
 * in front of the `strh`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009A34.c \
 *       --addr 0x02009A34 --thumb
 */
u32 sub_02009A34(struct Sub020097BCObj *obj)
{
    int i;
    u32 count = 0;

    for (i = 0; i < 0x20; i++) {
        if (sub_02009A1C(obj, i) != 0) {
            count++;
        }
    }
    return count;
}


u32 sub_02009A54(struct Sub020097BCObj *obj)
{
    int i;
    u32 last = 0;

    for (i = 0; i < 0x20; i++) {
        if (sub_02009A1C(obj, i) != 0) {
            last = i + 1;
        }
    }
    return last;
}


void sub_02009A74(struct Sub020097BCObj *obj, u32 i)
{
    struct Sub020097BCEnt *ents;
    struct Sub020097BCFriend *friends;

    if (i >= 0x20) {
        return;
    }
    for (; (int)i < 0x1F; i++) {
        MI_CpuCopy8(&obj->unk1C0[i + 1], &obj->unk1C0[i],
                    sizeof(obj->unk1C0[0]));
        MI_CpuCopy8(&obj->unk040[i + 1], &obj->unk040[i],
                    sizeof(obj->unk040[0]));
    }
    ents = obj->unk1C0;
    friends = obj->unk040;
    MI_CpuFill8(&ents[0x1F], 0, sizeof(ents[0]));
    MI_CpuFill8(&friends[0x1F], 0, sizeof(friends[0]));
}


void sub_02009AE4(struct Sub020097BCObj *obj, u32 dest, u32 src)
{
    MI_CpuCopy8(&obj->unk1C0[src], &obj->unk1C0[dest], sizeof(obj->unk1C0[0]));
    MI_CpuCopy8(&obj->unk040[src], &obj->unk040[dest], sizeof(obj->unk040[0]));
    MI_CpuFill8(&obj->unk1C0[src], 0, sizeof(obj->unk1C0[0]));
    MI_CpuFill8(&obj->unk040[src], 0, sizeof(obj->unk040[0]));
}


void sub_02009B3C(struct Sub020097BCObj *obj)
{
    int i;
    int j = -1;

    for (i = 0; i < 0x20; i++) {
        if (sub_02009A1C(obj, i) != 0) {
            if (j != -1) {
                sub_02009AE4(obj, j, i);
                i = -1;
                j = -1;
            }
        } else {
            if (j == -1) {
                j = i;
            }
        }
    }
}


void sub_02009B80(struct Sub020097BCObj *obj, int i)
{
    struct Sub0203F4E4Date date;

    func_0203F4E4((struct RtcDate *)(&date));
    obj->unk1C0[i].unk2A = date.year + 2000;
    obj->unk1C0[i].unk2C = date.month;
    obj->unk1C0[i].unk2D = date.day;
}


void sub_02009BB8(struct Sub020097BCObj *obj, int i, int a, int b, int c)
{
    if (i < 0 || i >= 0x20) {
        return;
    }
    obj->unk1C0[i].unk24 += (u16)a;
    if (obj->unk1C0[i].unk24 > 9999) {
        obj->unk1C0[i].unk24 = 9999;
    }
    obj->unk1C0[i].unk26 += (u16)b;
    if (obj->unk1C0[i].unk26 > 9999) {
        obj->unk1C0[i].unk26 = 9999;
    }
    obj->unk1C0[i].unk28 += (u16)c;
    if (obj->unk1C0[i].unk28 > 9999) {
        obj->unk1C0[i].unk28 = 9999;
    }
    sub_02009B80(obj, i);
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * alias: wifilist.c.  sub_02009C24 folds one entry's three counters into
 * another's, clamping each at 9999 the way sub_02009BB8 does, and then clears
 * the entry it drained.
 *
 * The cut between this range and src/matched/unit_02009CB0.c is what makes
 * both halves EXACT.  DWC_CreateExchangeToken is reached from exactly two
 * places in the image, the pool word of sub_02009CA8 at 0x02009CAC and the
 * `blx` inside sub_02009CB0 at 0x02009CB8, and a range holding both leaves the
 * address with no witness at all.  Split, the `blx` attests this file's pool
 * word and the pool word attests that file's `blx`.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009C24.c  *       --addr 0x02009C24 --thumb
 */
void sub_02009C24(struct Sub020097BCObj *obj, int src, int dest)
{
    if (dest < 0 || dest >= 0x20) {
        return;
    }
    if (src < 0 || src >= 0x20) {
        return;
    }
    obj->unk1C0[dest].unk24 += obj->unk1C0[src].unk24;
    if (obj->unk1C0[dest].unk24 > 9999) {
        obj->unk1C0[dest].unk24 = 9999;
    }
    obj->unk1C0[dest].unk26 += obj->unk1C0[src].unk26;
    if (obj->unk1C0[dest].unk26 > 9999) {
        obj->unk1C0[dest].unk26 = 9999;
    }
    obj->unk1C0[dest].unk28 += obj->unk1C0[src].unk28;
    if (obj->unk1C0[dest].unk28 > 9999) {
        obj->unk1C0[dest].unk28 = 9999;
    }
    MI_CpuFill8(&obj->unk1C0[src], 0, sizeof(obj->unk1C0[0]));
}


void sub_02009CA8(void *account, void *out)
{
    DWC_CreateExchangeToken(account, out);
}


int func_02009CB0(int a0, int a1){ int t0 = (int)sub_02009860((struct Sub020097BCObj *)a0); int t1 = func_020599BC((int)t0, (int)((a1 + 0) + 0)); return t1; }


/*
 * Compared as a unit rather than as a single function because the packet's
 * range runs two bytes past the last instruction: `match.py one` sees the
 * original as 36 bytes against the compiler's 34 and reports EXACT*, while
 * `tu` lays the section out and reproduces the linker's two-byte filler.
 */
int func_02009CC0(void *a0)
{
    u8 buf[12];
    void *h = sub_02009860(a0);

    func_02009CB0((int)a0, (int)buf);
    return func_020598EC(h, buf);
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * alias: the DWC-facing end of wifilist.c.  sub_02009D08 is the one that names
 * the save block: it fetches block id 0x1E out of sub_020071CC and hands it
 * straight to the entry accessor of src/matched/unit_02009860.c, so the wifi
 * friend list lives in block 0x1E.
 *
 * sub_02009860, the two-byte `bx lr` in src/matched/unit_02009860.c, is used
 * here the way sub_020084F4 is used in src/matched/unit_02008F48.c: its result
 * feeds the next call's first argument with no move in between, so it is an
 * identity accessor and is declared with the type that call needs.
 *
 * NEAR MISS, 0x02009CB0 and 0x02009CC0, 50 bytes, skipped for attestation and
 * not for codegen.  They are
 *
 *   void sub_02009CB0(struct WifiList *obj, void *out)
 *   {
 *       DWC_CreateExchangeToken(sub_02009860(obj), out);
 *   }
 *
 *   void sub_02009CC0(struct WifiList *obj)
 *   {
 *       u8 token[0xC];
 *       void *account = sub_02009860(obj);
 *
 *       sub_02009CB0(obj, token);
 *       DWC_GetGsProfileId(account, token);
 *   }
 *
 * and with sub_02009C24 they reproduce every concrete byte.  The chain that
 * blocks them is two links long.  DWC_CreateExchangeToken is reached from
 * exactly two places in the image: the pool word of sub_02009CA8 at 0x02009CAC
 * and the `blx` in sub_02009CB0 at 0x02009CB8.  Whichever of the two is in the
 * range, the other is its witness, so exactly one of them can be matched, and
 * src/matched/unit_02009C24.c takes sub_02009CA8 because that choice is what
 * lets its own pool word be attested by the `blx`.  sub_02009CB0 is then
 * unmatched, and the only branch to *it* anywhere in the image is the one in
 * sub_02009CC0, so sub_02009CC0 cannot be matched either.  Both close the day
 * anything else in the image calls either address.
 *
 * sub_02009D50 compares two call results against two parameters, and both
 * comparisons only come out `cmp r0, rN` when a named local holds the result:
 * written inline, in either operand order or as one `&&` chain, the compiler
 * normalises to `cmp rN, r0` and the file is two bytes wrong.  See
 * docs/idioms/cmp-operand-order-names-the-temporary.md.
 *
 * sub_02009D50's second parameter is dead: nothing in it reads r1, and
 * sub_02009D1C still computes sub_020084F4(p) to pass there.  Leaving the
 * parameter out moves every argument and the function does not match, so the
 * dead argument is part of the shape.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009C24.c \
 *       --addr 0x02009C24 --thumb
 */
u32 sub_02009CE4(struct Sub020097BCObj *obj)
{
    void *account = sub_02009860(obj);

    if (DWC_CheckHasProfile(account) != 0) {
        if (DWC_CheckValidConsole(account) != 0) {
            return 1;
        }
    }
    return 0;
}


struct Sub020097BCObj *sub_02009D08(void *sys)
{
    struct Sub020097BCObj *obj = sub_020071CC(sys, 0x1E);

    sub_020099D4(obj, 0);
    return obj;
}


int sub_02009D1C(struct Sub020097BCObj *obj, struct Sub0200852CObj *p,
                 u32 *out)
{
    u32 id = sub_02008530(p);
    u8 kind = sub_02008550(p);

    return sub_02009D50(obj, sub_020084F4(p), id, kind, out);
}


int sub_02009D50(struct Sub020097BCObj *obj, const void *unused, u32 id,
                 u32 kind, u32 *out)
{
    u8 i;
    u32 v;

    for (i = 0; i < 0x20; i++) {
        if (sub_02009A1C(obj, i) == 1) {
            v = sub_02009864(obj, i, 0);
            if (v == id) {
                v = sub_02009864(obj, i, 9);
                if (v == kind) {
                    if (out != 0) {
                        *out = i;
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * alias: the head of the next file after wifilist.c, a 0xD54-byte record whose
 * rest is in pkt_02009DB8.  Same opening as every other record here: a four
 * byte function returning the size over its own pool word, then a constructor
 * that clears exactly that many bytes.
 *
 * Unlike the 0x23 block in src/matched/unit_02009448.c, this constructor
 * *calls* the size function instead of spelling the constant a second time, so
 * the two files differ in the source and not only in the bytes.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009D9C.c \
 *       --addr 0x02009D9C --thumb
 */
u32 sub_02009D9C(void)
{
    return sizeof(struct Sub02009D9CObj_0);
}


void sub_02009DA4(struct Sub02009D9CObj_0 *obj)
{
    MI_CpuFill8(obj, 0, sub_02009D9C());
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           sub_02009E74, sub_02009E8C, sub_02009EA8, sub_02009EB0
 *
 * alias: the body of the 0xD54-byte record whose head is
 * src/matched/unit_02009D9C.c.  It is a hundred-slot most-recently-used list
 * of the 0x20-byte object of src/matched/unit_0200852C.c, plus one counter:
 *
 *   +0x000  Sub0200852CObj[100]   0x20 bytes each
 *   +0xD50  u32                   a use count, saturating at 99999
 *
 * sub_02008468, four bytes returning 0x20, is the element size, and
 * sub_02009DE8 uses it for both of its block moves rather than spelling 0x20
 * out.  The insert shifts the whole list up by one slot with MI_CpuMove and
 * copies the new object into slot 0, so slot 0 is the most recent; when the
 * object is already in the list only its +0x1C byte is refreshed.
 *
 * sub_02009DB8 returns -1 for "not found", materialised as `movs r0, #0` and
 * `mvns r0, r0` rather than as a pool word, and every caller compares against
 * that same pair.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009DB8.c \
 *       --addr 0x02009DB8 --thumb
 */
int sub_02009DB8(struct Sub02009D9CObj_1 *obj, u32 id)
{
    int i;

    for (i = 0; i < 100; i++) {
        if (sub_0200855C(&obj->unk000[i]) != 0
            && id == sub_02008530(&obj->unk000[i])) {
            return i;
        }
    }
    return -1;
}


void sub_02009DE8(struct Sub02009D9CObj_1 *obj, struct Sub0200852CObj *p)
{
    u32 id = sub_02008530(p);
    u32 size = sub_02008468();
    int i;

    if (id == 0) {
        return;
    }
    i = sub_02009DB8(obj, id);
    if (i != -1) {
        sub_02008558(&obj->unk000[i], sub_02008554(p));
        return;
    }
    MI_CpuMove(obj->unk000, &obj->unk000[1], size * 99);
    MI_CpuCopy8(p, obj->unk000, size);
}


u32 sub_02009E40(struct Sub02009D9CObj_1 *obj, u32 i)
{
    if (i >= 100) {
        i = 0;
    }
    return sub_02008530(&obj->unk000[i]);
}


struct Sub0200852CObj *sub_02009E54(struct Sub02009D9CObj_1 *obj, u32 i)
{
    if (i >= 100) {
        return 0;
    }
    if (sub_02009E40(obj, i) == 0) {
        return 0;
    }
    return &obj->unk000[i];
}


u32 sub_02009E74(struct Sub02009D9CObj_1 *obj, u32 id)
{
    if (sub_02009DB8(obj, id) != -1) {
        return 1;
    }
    return 0;
}


int sub_02009E8C(struct Sub02009D9CObj_1 *obj)
{
    int i;

    for (i = 0; i < 100; i++) {
        if (sub_0200855C(&obj->unk000[i]) == 0) {
            break;
        }
    }
    return i;
}


u32 sub_02009EA8(const struct Sub02009D9CObj_1 *obj)
{
    return obj->unkD50;
}


void sub_02009EB0(struct Sub02009D9CObj_1 *obj)
{
    obj->unkD50 = obj->unkD50 + 1;
    if (obj->unkD50 > 99999) {
        obj->unkD50 = 99999;
    }
}


/*
 * Save-block getter for block 0x1F, the same one-line shape as
 * func_0200AD6C (block 0x2E): a tail call through the pool with the id in
 * r1. Seeded from ov120 (0x021D4A90, 0x021D4AC8), ov135 (0x02201B78) and
 * the ov175 root func_021D7E18 (0x021D827E).
 */
void *func_02009EC8(void *sys)
{
    return func_020071CC(sys, 0x1f);
}


/*
 * Save-table size callback: returns 0xA94, the size of the block whose
 * init is func_02009EDC.  Pointer word 0x02009ED5 at 0x0209DBC4 (the
 * save table's (size, init, id) row for id 0x22).
 */
u32 func_02009ED4(void)
{
    return 0xA94;
}


void func_02009EDC(void *a0)
{
    u8 buf[12];

    func_02082BCC(buf, 0, 0xc);
    ((struct Obj11227 *)buf)->f0 = a0;
    ((struct Obj11227 *)buf)->f4 = 1;
    func_02082BCC(a0, 0, 0xa94);
    func_0200A480((struct Obj *)buf);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02009F0C.c \\
 *       --func func_02009F0C --addr 0x02009F0C --thumb --cc 1.1p1
 */
u32 func_02009F0C(u32 a)
{
    if (a != 0 && a < 4) {
        return 1;
    }
    return 0;
}


int func_02009F1C(void *a0)
{
    u32 i;
    u32 n = func_0200A400(a0);

    for (i = 0; i < n; i++) {
        if (func_02009F0C(((u8 *)func_0200A43C(a0, i))[0xb3]) == 0)
            return 1;
    }
    return 0;
}


int func_02009F50(char *p, unsigned int idx)
{
    unsigned char *e = (unsigned char *)func_0200A43C((struct Obj *)p, idx);
    func_0200A400((struct Obj *)p);
    if (idx < 0xc && func_02009F0C(((struct Obj15577 *)e)->fB3) != 0)
        return 1;
    return 0;
}


void func_02009F7C(void *p, unsigned int idx)
{
    unsigned int i;
    unsigned int n = (unsigned int)func_0200A400(p);
    if (func_02009F50(p, idx) != 0)
        return;
    for (i = idx; i < n - 1; i++) {
        void *dst = func_0200A43C(p, i);
        void *src = func_0200A43C(p, i + 1);
        *(Slot *)dst = *(Slot *)src;
    }
    func_02082BCC(func_0200A43C(p, i), 0, 0xcc);
}


void *func_02009FD4(char *p, unsigned int idx)
{
    unsigned char *e = (unsigned char *)func_0200A43C((struct Obj *)p, idx);
    unsigned int n = func_0200A400((struct Obj *)p);
    if (idx < n && func_02009F0C(((struct Obj15578 *)e)->fB3) != 0)
        return e;
    return 0;
}


int func_0200A000(char *p, int idx, void *buf)
{
    char *e;
    int r = 0;
    func_0200A400((struct Obj *)p);
    func_0200A49C((struct Obj *)p);
    e = (char *)func_02009FD4(p, idx);
    if (e != 0) {
        func_02082D44(e, buf, 0xcc);
        r = 1;
    }
    func_0200A480((struct Obj *)p);
    return r;
}


int func_0200A034(void *p, void *arg)
{
    unsigned int i;
    int found = 0;
    unsigned int n = (unsigned int)func_0200A400(p);
    func_0200A49C(p);
    if (func_02009F1C(p) == 1) {
        for (i = 0; i < n; i++) {
            void *slot = func_0200A43C(p, i);
            if (func_02009F0C(((struct Obj15579 *)slot)->fB3) == 0) {
                func_02082D44(arg, slot, 0xcc);
                found = 1;
                break;
            }
        }
    }
    func_0200A480(p);
    return found;
}


void func_0200A094(void *p, unsigned int idx)
{
    unsigned int n = (unsigned int)func_0200A400(p);
    func_0200A49C(p);
    if (idx < n) {
        void *slot = func_0200A43C(p, idx);
        ((struct Obj15580 *)slot)->fB3 = 0;
        func_02009F7C(p, idx);
    }
    func_0200A480(p);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200A0C8.c \\
 *       --func func_0200A0C8 --addr 0x0200A0C8 --thumb --cc 1.1p1
 */
u32 func_0200A0C8(u8 *p)
{
    u32 r;

    func_0200A49C((struct Obj *)p);
    r = func_02009F1C(p);
    func_0200A480((struct Obj *)p);
    return r;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200A0E4.c \\
 *       --func func_0200A0E4 --addr 0x0200A0E4 --thumb --cc 1.1p1
 */
u32 func_0200A0E4(u8 *p, u32 a)
{
    u32 r;

    func_0200A49C((struct Obj *)p);
    r = func_02009F50((char *)p, a);
    func_0200A480((struct Obj *)p);
    return r;
}


int func_0200A104(char *p, unsigned int idx)
{
    int r = 0;
    unsigned int n = func_0200A400((struct Obj *)p);
    func_0200A49C((struct Obj *)p);
    if (idx < n) {
        unsigned char *e = (unsigned char *)func_0200A43C((struct Obj *)p, idx);
        if (((unsigned int)(((struct Obj15581 *)e)->fB4) << 0x1e) >> 0x1f)
            r = 1;
    }
    func_0200A480((struct Obj *)p);
    return r;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200A13C.c \\
 *       --func func_0200A13C --addr 0x0200A13C --thumb --cc 1.1p1
 */
void func_0200A13C(u8 *p, u32 i)
{
    u32 n = func_0200A400((struct Obj *)p);
    u8 *q;

    func_0200A49C((struct Obj *)p);
    if (i < n) {
        q = func_0200A43C((struct Obj *)p, i);
        q[0xb4] |= 2;
    }
    func_0200A480((struct Obj *)p);
}


int func_0200A170(char *p)
{
    int found = 0;
    unsigned int i;
    unsigned int n = func_0200A400((struct Obj *)p);
    func_0200A49C((struct Obj *)p);
    for (i = 0; i < n; i++) {
        if (func_02009F50(p, i) == 1)
            found = 1;
    }
    func_0200A480((struct Obj *)p);
    return found;
}


int func_0200A1A8(char *p, unsigned int bit)
{
    int r = 0;
    unsigned char *t = (unsigned char *)func_0200A41C((struct Obj *)p);
    func_0200A49C((struct Obj *)p);
    if (bit < 0x800) {
        if (t[bit >> 3] & (1 << (bit & 7)))
            r = 1;
    }
    func_0200A480((struct Obj *)p);
    return r;
}


void func_0200A1E4(void *p, unsigned int idx)
{
    u8 *b = func_0200A41C(p);
    func_0200A49C(p);
    if (idx < 0x800) {
        b[idx >> 3] |= (u8)(1 << (idx & 7));
    }
    func_0200A480(p);
}


/*
 * note:     closed 2026-09-21 by tools/permuter.py (hill, --types): declaration order i before n,
 *           and the counter n is unsigned (8 bytes)
 */
int func_0200A21C(u8 *obj)
{
    int i;
    u32 limit = 0x2d0;
    u32 n = 0;

    do {
        for (i = 0; i < 16; i++) {
            n++;
        }
    } while (n < (int)limit);
    return ((struct Obj15585 *)obj)->f2CE == func_0203F1FC(obj, 0x2ce);
}


void func_0200A254(void *p, unsigned int a, unsigned int b)
{
    unsigned char tmp[0xcc];
    func_0200A49C(p);
    if (func_02009F50(p, a) && func_02009F50(p, b)) {
        void *x = func_02009FD4(p, a);
        void *y = func_02009FD4(p, b);
        func_02082D44(x, tmp, 0xcc);
        func_02082D44(y, x, 0xcc);
        func_02082D44(tmp, y, 0xcc);
    }
    func_0200A480(p);
}


void func_0200A2B8(void *a0, int a1)
{
    if (func_0200A350(a0) == 0) {
        func_021DFDC0(((struct Obj15586 *)a0)->f8);
    } else {
        func_02012DAC(a1);
    }
}


int func_0200A2D8(void *a0, int a1)
{
    if (func_0200A350(a0) == 0) {
        if (func_021DFE00(((struct Obj15587 *)a0)->f8) != 0)
            return 2;
        return 0;
    }
    return func_02012DD0((u8 *)a1);
}


void *func_0200A300(void *a0, void *a1, void *a2)
{
    void *p = func_02030734((u32)a2, 0xc, 0, g_020A71A4, 0x260);

    func_02082BCC(p, 0, 0xc);
    func_0200A358(p, a0, (int)a1, (int)a2);
    return p;
}


void func_0200A338(void *a0)
{
    func_0200A3D0(a0);
    func_020307B0(a0);
}


/*
 * Four bytes of code and a pool word: the plain Thumb tail call of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.  It carries no label in the
 * generated listing (it saves nothing), so it was read out of the bytes; it
 * sits between func_0200A338 and func_0200A350 at the end of its packet.
 * Its target reads one object pointer in r0 and returns the unsigned count
 * used by the overlay callers.
 */
u32 func_0200A348(struct Obj *obj)
{
    return func_0200A400(obj);
}


int func_0200A350(struct Obj *a0)
{
    return func_0200A3FC(a0);
}


/*
 * note:     wave 16: promoted.  0x021DFE90 and 0x021DFEAC are unlabelled
 *           ov228 leaves (a byte getter at +0x378 and `p + 0xC`), now matched
 *           in src/matched/func_021DFE90.c / func_021DFEAC.c (shard
 *           ov228/pkt_021DFC20); the ov228 hints below make both sites
 *           `matched, overlay`.  func_021DFEAC's body reads r0, so its
 *           prototype now takes the pointer func_021DFC20 returned (the
 *           callee-arity lever; same bytes, it was a live leftover before).
 * WHAT CHANGED THIS WAVE (docs/notes/pkt_0200A358.c.txt had this row at DIFF,
 * 112 bytes against 120, 91 concrete bytes out).  The note's C spelled the
 * dispatch on a2 as `if (a2 == 1) t = sub_020071EC(a1);` with `t` initialised
 * to 1.  The original is a SWITCH with an explicit empty-ish case 0:
 *
 *   0200A36A  cmp r4, #0 / beq  ->  0200A374: b 0200A37E  (t = 1)
 *   0200A36E  cmp r4, #1 / beq  ->  0200A376: bl 20071EC
 *   0200A372  b            ->  0200A37E: movs r0, #1      (default, t = 1)
 *
 * Two separate branch targets that both land on `movs r0, #1` is the tell of
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md read the other way
 * round: case 0 and the default arm are written out separately in the source
 * even though they do the same thing.  Writing the switch with case 0,
 * case 1 and default each assigning `t` recovers the missing 8 bytes AND the
 * register allocation -- the `if` form spilled a3 to `[sp]` where the
 * original keeps it in r7 -- and takes the row from 91 concrete bytes out to
 * zero in one edit.  The 0xE4 pool word is the same absolute linker symbol
 * func_0200A3D0 next door uses
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/func_0200A358.c \
 *       --func sub_0200A358 --addr 0x0200A358 --cc 1.1p1 --thumb
 */
void sub_0200A358(u8 *p, void *ctrl, int a2, int a3)
{
    int t;
    void *w;

    func_02082BCC(p, 0, 0xc);
    switch (a2) {
    case 0:
        t = 1;
        break;
    case 1:
        t = sub_020071EC((const struct Sub020071E4Ctrl *)ctrl);
        break;
    default:
        t = 1;
        break;
    }
    if (t != 0) {
        ((struct Obj04037 *)p)->f0 = (u32)sub_020071CC((struct Sub020071CCCtrl *)ctrl, 0x22);
        ((struct Obj04037 *)p)->f4 = 1;
        return;
    }
    func_02034AC4((int)ov_id_E4);
    w = func_021DFC20(a3);
    ((struct Obj04037 *)p)->f8 = (u32)w;
    ((struct Obj04037 *)p)->f0 = (u32)func_021DFEAC(w);
    ((struct Obj04037 *)p)->f4 = 0;
    if (func_021DFE90((void *)((struct Obj04037 *)p)->f8) == 0) {
        func_02082BCC((void *)((struct Obj04037 *)p)->f0, 0, 0x368);
        sub_0200A480((struct Obj *)p);
    }
}


/*
 * note:     wave 16: promoted.  0x021DFDB8 is an unlabelled ov228 leaf, a
 *           one-argument tail call to the ARM heap free func_020307B0, now
 *           matched in src/matched/func_021DFDB8.c (shard ov228/pkt_021DFC20);
 *           the ov228 hint below makes the site `matched, overlay`.
 * Third pass, lane 1: this row was DIFF for two passes and is now byte-correct.
 * The residue was never a codegen difference.  The original's second call is
 *
 *   0200A3E4  04 48        ldr r0, [pc, #0x10]
 *   0200A3E6  2a f0 3a eb  blx #0x2034a5c
 *   ...
 *   0200A3F8  e4 00 00 00  0x000000E4
 *
 * a small constant loaded from the pool where `func_02034A5C(0xe4)` gives
 * `movs r0, #0xe4`.  That is the reading of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md: a pool
 * word holding a value too small to be an address is an `R_ARM_ABS32` against
 * an absolute symbol, i.e. 0xE4 is a linker-defined id, and declaring it and
 * passing it reproduces the original's pool word and all 44 bytes.  The
 * site resolves as `literal x2` (two other pool words in the image hold
 * 0x000000E4, e.g. 0x02007070), which is what confirms the reading.
 * Five numeric spellings were tried and all five give `movs`:
 * `0xe4`, `(u32)0xe4`, a macro, a `static const u32`, and a file-scope
 * `const u32`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0200A3D0.c \
 *       --func func_0200A3D0 --addr 0x0200A3D0 --cc 1.1p1 --thumb
 */
void func_0200A3D0(void *obj)
{
    switch (((struct Obj11228 *)obj)->f4) {
    case 0:
        func_021DFDB8((void *)((struct Obj11228 *)obj)->f8);
        func_02034A5C((int)ov_abs_e4);
        break;
    case 1:
        break;
    }
    func_02082BCC(obj, 0, 0xc);
}


#define unk_02FFFC3C (*(volatile u32 *)0x02FFFC3C)


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200A43C, func_0200A480, func_0200A49C, func_0200A4B8,
 *           func_0200A50C, func_0200A53C, func_0200A544, func_0200A5F8,
 *           func_0200A604, func_0200A628, func_0200A630, func_0200A640,
 *           func_0200A644, func_0200A680, func_0200A6BC
 *
 * 764 bytes, 0x0200A3FC..0x0200A6F8, 19 functions.  Five of the nineteen
 * carry no label in the generated listing (0x0200A53C, 0x0200A628,
 * 0x0200A630, 0x0200A640 and 0x0200A680): none of them saves lr, so
 * disasm.py's prologue sweep does not fire and the listing prints their
 * bytes as `.word` data in the middle of a literal pool.  They were read out
 * of those words.  0x0200A53C is the giveaway of the three: `movs r0, #0xa9;
 * lsls r0, #2; bx lr` returns 0x2A4, which is exactly the size the
 * constructor at 0x0200A544 clears, the same "a block file opens with a
 * function returning its own size" shape docs/MATCHING.md records for the
 * 0x0200857C run.
 *
 * This unit absorbs the previously matched single function
 * src/matched/sub_0200A6BC.c (0x0200A6BC, 60 bytes), which is its last
 * function.  Its legacy manifest entry is superseded by this unit.
 *
 * What the range is.  Two objects, and two layers.
 *
 * `struct Obj` is a twelve byte handle: a pointer to a block, a kind that is
 * only ever 0 or 1, and a third word.  Every accessor on it is a `switch`
 * over that kind with the default falling through to a zero return, and the
 * two arms are byte for byte identical in three of the four cases, so the
 * distinction is in the source and not in the code.  The 0x0200A4B8 /
 * 0x0200A50C pair stamps and clears a four byte header sitting at the end of
 * the block (offset 0x364 or 0xA90 for the two kinds), holding a 32-bit key
 * built out of a system word and handed to the pair of routines at
 * 0x0203F2FC / 0x0203F328 / 0x0203F37C.
 *
 * `struct Big` is a 0x2A4-byte record with two parallel 0x20-byte bitmaps at
 * 0x258 and 0x278.  0x0200A6BC sets the same bit in both, 0x0200A644 tests
 * the first and 0x0200A680 tests the second; the constructor at 0x0200A544
 * clears the record, seeds two arrays and then sets fifteen of those bits by
 * hand.  100 (0x64) is the bound on every one of the three, so 100 of the
 * 256 bits are in use.
 *
 * Three things in this unit cost time and are recorded under docs/idioms/:
 *
 *  - the assignment that both arms of a switch make is emitted once, at a
 *    merge point the default case jumps over.  Writing it after the switch
 *    instead puts the default's branch on that merge point and changes one
 *    branch target and the whole register allocation of the function.  See
 *    docs/idioms/switch-arms-tail-merge.md.
 *  - a repeated read of a hardware address has to be written as two named
 *    locals.  `(X << 8) | X` on a volatile lvalue interleaves the shift
 *    between the two loads; the original loads both and then shifts.  See
 *    docs/idioms/volatile-reread-needs-two-locals.md.
 *  - 0x02FFFC3C is a cast address constant and not an extern.  An `extern
 *    volatile u32` at that address produces an ABS32 relocation and puts the
 *    address in a different register.  Same idiom file as above.
 *
 * Near miss, left out of this unit deliberately: the function at
 * 0x0200A3D0, which is the one immediately before it and is almost certainly
 * part of the same original file.  Two separate reasons, either of which is
 * enough:
 *
 *  1. it calls 0x021DFDB8, which is an overlay address.  `attest()` now has a
 *     rule for those: a target inside an overlay per layout/layout.json is
 *     attested when that overlay's own listing carries a `func_` label at the
 *     address, the label's ISA is the declared ISA, and some branch outside
 *     the compared range targets it.  The third part holds here (a `bl` from
 *     0x02006F42 inside arm9_main and another from ov088 at 0x021BC378); the
 *     first does not.  0x021DFDB8 is inside seven overlays at once, because
 *     overlays share load windows, and they disagree about what is there:
 *     ov093 has an instruction in the middle of a function, ov119 a `movs`,
 *     ov170 a data word, ov228 an eight byte Thumb thunk.  None of them
 *     labels it, so nothing says which of the seven the call means and the
 *     relocation stays a wildcard.  (The thunk in ov228 is the linker's Thumb
 *     veneer shape, which the `veneer` class deliberately does not recognise:
 *     mwccarm emits those same eight bytes for a Thumb tail call.  See "The
 *     veneer class" in docs/MATCHING.md.)
 *  2. two concrete bytes are wrong regardless.  The original materialises the
 *     constant 0xE4 with `ldr r0, [pc, #0x10]` out of its own literal pool,
 *     where every spelling of the integer 228 tried here (decimal, hex,
 *     suffixed, cast, enumerator, `sizeof`, `offsetof`) compiles to `movs
 *     r0, #0xE4` under all nine front ends at every optimisation level.  The
 *     function immediately before it does the same thing with the same value,
 *     so whatever the construct is, it is used twice in a row and is not an
 *     accident.  The rest of the function is byte for byte right.
 */
u32 func_0200A3FC(struct Obj *obj)
{
    return obj->unk04;
}


u32 func_0200A400(struct Obj *obj)
{
    switch (obj->unk04) {
    case 0:
        return 3;
    case 1:
        return 12;
    }
    return 0;
}


void *func_0200A418(struct Obj *obj)
{
    return obj->unk00;
}


void *func_0200A41C(struct Obj *obj)
{
    switch (obj->unk04) {
    case 0:
        return func_0200A418(obj);
    case 1:
        return func_0200A418(obj);
    }
    return 0;
}


void *func_0200A43C(struct Obj *obj, u32 index)
{
    func_0200A400(obj);
    switch (obj->unk04) {
    case 0:
        return (u8 *)func_0200A418(obj) + 0x100 + index * 0xCC;
    case 1:
        return (u8 *)func_0200A418(obj) + 0x100 + index * 0xCC;
    }
    return 0;
}


void func_0200A480(struct Obj *obj)
{
    func_0200A4B8(func_0200A418(obj), func_0200A3FC(obj));
}


void func_0200A49C(struct Obj *obj)
{
    func_0200A50C(func_0200A418(obj), func_0200A3FC(obj));
}


void func_0200A4B8(void *base, u32 kind)
{
    u32 size;
    struct Hdr *h;
    u32 a, b;

    switch (kind) {
    case 0:
        size = 0x368;
        h = (struct Hdr *)((u8 *)base + (size - 4));
        break;
    case 1:
        size = 0xA94;
        h = (struct Hdr *)((u8 *)base + (size - 4));
        break;
    }
    a = unk_02FFFC3C;
    b = unk_02FFFC3C;
    h->unk02 = (u16)((a << 8) | b);
    if (h->unk02 == 0) {
        h->unk02 = 1;
    }
    h->unk00 = func_0203F2FC(base, size - 4);
    func_0203F328(base, size - 4, h->unk00 + (h->unk02 << 16));
}


void func_0200A50C(void *base, u32 kind)
{
    u32 size;
    struct Hdr *h;

    switch (kind) {
    case 0:
        size = 0x368;
        h = (struct Hdr *)((u8 *)base + (size - 4));
        break;
    case 1:
        size = 0xA94;
        h = (struct Hdr *)((u8 *)base + (size - 4));
        break;
    }
    func_0203F37C(base, size - 4, h->unk00 + (h->unk02 << 16));
    h->unk02 = 0;
}


u32 func_0200A53C(void)
{
    return sizeof(struct Big);
}


void func_0200A544(struct Big *p)
{
    u8 i;

    MI_CpuFill8(p, 0, sizeof(struct Big));
    func_0200A604(p);
    for (i = 0; i < 10; i++) {
        p->unk1E0[i].unk0 = 4;
    }
    p->unk29D = 0;
    p->unk29E = 0;
    func_0200A6BC(p, 0x30);
    func_0200A6BC(p, 0x46);
    func_0200A6BC(p, 0x53);
    func_0200A6BC(p, 0x4B);
    func_0200A6BC(p, 0x00);
    func_0200A6BC(p, 0x01);
    func_0200A6BC(p, 0x0A);
    func_0200A6BC(p, 0x1C);
    func_0200A6BC(p, 0x08);
    func_0200A6BC(p, 0x3B);
    func_0200A6BC(p, 0x3F);
    func_0200A6BC(p, 0x42);
    func_0200A6BC(p, 0x10);
    func_0200A6BC(p, 0x59);
    func_0200A6BC(p, 0x4C);
}


void *func_0200A5F8(void *sys)
{
    return func_020071CC(sys, 0x2A);
}


void func_0200A604(struct Big *p)
{
    u8 i;

    for (i = 0; i < 8; i++) {
        p->unk1B0[i].unk0 = 10;
    }
}


u8 *func_0200A628(struct Big *p)
{
    return (u8 *)p->unk1B0;
}


u32 func_0200A630(struct Bits *p)
{
    return p->unk00_16 != 0;
}


void func_0200A640(void)
{
}


u32 func_0200A644(struct Big *p, u8 index)
{
    if (index < 100) {
        u8 shift = (s32)index % 8;
        u8 byte  = index >> 3;
        if ((p->unk258[byte] & (1 << shift)) > 0) {
            return 1;
        }
    }
    return 0;
}


u32 func_0200A680(struct Big *p, u8 index)
{
    if (index < 100) {
        u8 shift = (s32)index % 8;
        u8 byte  = index >> 3;
        if ((p->unk278[byte] & (1 << shift)) > 0) {
            return 1;
        }
    }
    return 0;
}


void func_0200A6BC(struct Big *p, u32 index)
{
    u8 shift, byte;

    if (index >= 100) {
        return;
    }
    shift = (s32)index % 8;
    byte  = index >> 3;
    p->unk258[byte] |= (u8)(1 << shift);
    p->unk278[byte] |= (u8)(1 << shift);
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200A75C, func_0200A768, func_0200A780, func_0200A788,
 *           func_0200A7A0, func_0200A7AC, func_0200A7B8, func_0200A7C0,
 *           func_0200A7C8, func_0200A7D4, func_0200A7E0, func_0200A7EC,
 *           func_0200A800, func_0200A7F8, func_0200A81C, func_0200A828,
 *           func_0200A834
 *
 * 328 bytes, 0x0200A6F8..0x0200A840, 21 functions, and the direct
 * continuation of src/matched/unit_0200A3FC.c: every one of them reaches the
 * same 0x2A4-byte `struct Big`, and the accessors here are what pin the last
 * quarter of its layout (three counters at 0x252, 0x254 and 0x256, a
 * four-entry byte array at 0x298 and four separate bytes at 0x29C..0x29F).
 *
 * Fourteen of the twenty-one carry no label in the generated listing: none of
 * them saves lr, so disasm.py's prologue sweep does not fire and the listing
 * prints their bytes as `.word` data.  They are the accessor half of the file
 * and were read out of those words, the same way the sixteen accessors of
 * unit_0200852C.c were.
 *
 * 0x0200A6F8 is the one docs/MATCHING.md already named under "The two
 * missing labels": the 28-byte loop that clears the second of the two
 * bitmaps func_0200A6BC sets a bit in.  It is in
 * layout/function_starts.txt, attested by the bl from ov133 at 0x021B62A2,
 * which is why it has a label here and its fourteen neighbours do not.
 *
 * 0x0200A714 counts how many of the 256 bit positions are set in the first
 * bitmap by calling func_0200A644 on every one of them, and 0x0200A73C asks
 * whether that count has reached 100, which is the same bound the three
 * bitmap routines in unit_0200A3FC.c check their index against.  So 100 is
 * the population of whatever the bitmap enumerates and this pair is its
 * "have you seen all of them" test.
 *
 * Two details pin source shapes here, both of them one-line fixes that look
 * like body diffs:
 *
 *  - in 0x0200A714 the accumulator has to be declared before the loop
 *    counter.  Declared the other way round the two locals swap registers,
 *    which is six differing bytes spread over the whole function and nothing
 *    else.  Same finding as docs/idioms/local-declaration-order-is-stack-
 *    order.md, one level up: the rule holds for register-allocated locals and
 *    not only for stack slots.
 *  - 0x0200A800 saturates at 0xFFFF, and the source tests `v < 0xFFFF` with
 *    the saturating store in the `else`.  Written the other way round the
 *    compiler emits `blt` where the original has `bge` and swaps the two
 *    stores, which is four bytes and reads as a different function.
 */
void func_0200A6F8(struct Big *p)
{
    u8 i;

    for (i = 0; i < 0x20; i++) {
        p->unk278[i] = 0;
    }
}


u32 func_0200A714(struct Big *p)
{
    u32 count;
    s32 i;

    count = 0;
    for (i = 0; i < 256; i++) {
        if (func_0200A644(p, (u8)i) == 1) {
            count++;
        }
    }
    return count;
}


u32 func_0200A73C(struct Big *p)
{
    if (func_0200A714(p) == 100) {
        return 1;
    }
    return 0;
}


struct BigSub4 *func_0200A750(struct Big *p, u32 index)
{
    return &p->unk1E0[index];
}


u16 func_0200A75C(struct Big *p)
{
    return p->unk252;
}


void func_0200A768(struct Big *p)
{
    if (p->unk252 < 0xFFFF) {
        p->unk252++;
    }
}


u16 func_0200A780(struct Big *p)
{
    return p->unk254;
}


void func_0200A788(struct Big *p)
{
    if (p->unk254 < 0xFFFF) {
        p->unk254++;
    }
}


u8 func_0200A7A0(struct Big *p, u32 index)
{
    return p->unk298[index];
}


void func_0200A7AC(struct Big *p, u32 index, u8 value)
{
    p->unk298[index] = value;
}


u8 func_0200A7B8(struct Big *p)
{
    return p->unk29C;
}


void func_0200A7C0(struct Big *p, u8 value)
{
    p->unk29C = value;
}


u8 func_0200A7C8(struct Big *p)
{
    return p->unk29D;
}


void func_0200A7D4(struct Big *p, u8 value)
{
    p->unk29D = value;
}


u8 func_0200A7E0(struct Big *p)
{
    return p->unk29E;
}


void func_0200A7EC(struct Big *p, u8 value)
{
    p->unk29E = value;
}


u8 *func_0200A7F8(struct Big *p)
{
    return p->unk208;
}


void func_0200A800(struct Big *p, s32 delta)
{
    s32 v = p->unk256 + delta;

    if (v < 0xFFFF) {
        p->unk256 = v;
    } else {
        p->unk256 = 0xFFFF;
    }
}


u16 func_0200A81C(struct Big *p)
{
    return p->unk256;
}


u32 func_0200A828(struct Big *p)
{
    return p->unk29F;
}


void func_0200A834(struct Big *p, u8 value)
{
    p->unk29F = value;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 8 bytes, 0x0200A840..0x0200A848, one function, which carries no label in
 * the generated listing: it is the three-instruction size getter that opens
 * every save block file in this region, and it has no prologue.
 *
 * The size it returns, 0x2DC, is what fixes the tail of the record.  The
 * constructor in the next function hands out the two sub-objects at +0x1E8
 * and +0x1FC, so the only free choice left is how much follows the second
 * one, and 0xE0 is what makes sizeof agree with the getter.
 *
 * Near miss, and the reason this unit stops at 0x0200A848: func_0200A848, 28
 * bytes, reproduces every concrete byte and caps at MATCH.  It is
 *
 *     void func_0200A848(struct Rec2DC *p)
 *     {
 *         func_02161D98(p);
 *         func_02161EEC(p->unk1E8);
 *         func_02161F00(p->unk1FC);
 *     }
 *
 * and all three callees live in overlay space.  0x02161D98 is attested by the
 * overlay-resident callee class (label x1, witness 0x02012674).  The other
 * two are not: 0x02161EEC has exactly two branch witnesses image wide, one of
 * them this call and the other 0x02186378, and 0x02161F00 has exactly one,
 * this call.  Neither address carries a func_ label in any overlay that
 * contains it, which is part 1 of the overlay rule, so neither can be
 * attested and no cut helps: the only witness is the call that needs it.  It
 * closes the day disasm.py labels either address.
 */
u32 func_0200A840(void)
{
    return sizeof(struct Rec2DC);
}


/*
 * note:     wave 16: promoted.  02161EEC is the unlabelled ov010 leaf now
 *           matched in src/matched/func_02161EEC.c (shard ov010/pkt_02161EEC),
 *           which attests the call as `matched, overlay` under the ov010
 *           hint below; 02161F00 resolves as sole-ref/code (overlay).
 */
void func_0200A848(void **a0)
{
    func_02161D98((char *)a0);
    func_02161EEC((u16 *)&a0[0x7a]);
    func_02161F00(&a0[0x7f]);
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200A898, func_0200A8A0, func_0200A8AC, func_0200A8C8,
 *           func_0200A8D0, func_0200A8E4, func_0200A8F8
 *
 * 162 bytes, 0x0200A864..0x0200A906, 11 functions, six of which carry no
 * label in the generated listing.
 *
 * The object is a 0x34C-byte record holding thirty 0x1C-byte entries
 * followed by one word of flags; 30 * 0x1C is 0x348, which is exactly the
 * offset func_0200A930 reads that word at, so the array length and the
 * record size check against each other.  Each entry carries a packed word at
 * +0x10 whose fields this file reads one at a time: 7 bits at bit 0, 10 bits
 * at bit 7, one bit at bit 17, and one bit at bit 31 that func_0200A8AC
 * scans for to find how many entries are in use.
 *
 * The bit widths are not guesses.  Each getter is a `lsls`/`lsrs` pair whose
 * two shift counts give the field's position and width directly, and where
 * the return type is narrower than the field the compiler adds a second
 * truncating pair: func_0200A8D0's `lsls #25 / lsrs #25` is the 7-bit field
 * and its `lsls #24 / lsrs #24` is the `u8` return, and dropping either
 * changes two instructions.
 *
 * Near miss, and the reason this unit stops where it does: func_0200A908 at
 * 0x0200A908, 40 bytes, which unpacks four fields of one entry through four
 * out-parameters.  Two of the four are bitfields of the same byte at +0x1B,
 * and the original loads that byte exactly once, with `ldrb` into the
 * register that held the entry pointer, and then does each field's shift pair
 * immediately before its own store.  Writing the two reads directly is two
 * `ldrb`s, because the intervening store through a `u8 *` may alias the
 * struct and the compiler reloads; writing them into locals first gets the
 * single load but hoists both shift pairs above both stores.  Sixteen
 * spellings were tried (locals for each subset of the four outputs, a nested
 * one-byte bitfield struct copied to a local, the whole tail as a `u32`
 * bitfield container, and the shifts written out by hand), and the best of
 * them is sixteen bytes wrong in exactly that scheduling.  Every other byte
 * of the function is right.  The next unit therefore resumes at 0x0200A930.
 */
void *func_0200A864(void *sys)
{
    return func_020071CC(sys, 0x2B);
}


void func_0200A870(struct Rec2Head *dest, const struct Rec2Head *src)
{
    MI_CpuCopy8(src, dest, sizeof(struct Rec2Head));
}


void func_0200A884(const struct Rec2Head *src, struct Rec2Head *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Rec2Head));
}


u8 *func_0200A890(struct Rec2 *p)
{
    return p->unk1E8;
}


u8 *func_0200A898(struct Rec2 *p)
{
    return p->unk1FC;
}


void *func_0200A8A0(void *sys)
{
    return func_020071CC(sys, 0x2C);
}


s32 func_0200A8AC(struct Rec *r)
{
    s32 i;

    for (i = 0; i < 30; i++) {
        if (r->entries[i].f10_31 == 0) {
            break;
        }
    }
    return i;
}


struct Entry_0 *func_0200A8C8(struct Rec *r, u32 index)
{
    return &r->entries[index];
}


u8 func_0200A8D0(struct Rec *r, u32 index)
{
    return r->entries[index].f10_0;
}


u16 func_0200A8E4(struct Rec *r, u32 index)
{
    return r->entries[index].f10_7;
}


u32 func_0200A8F8(struct Rec *r, u32 index)
{
    return r->entries[index].f10_17;
}


/*
 * Unlabelled Thumb leaf: reads record i (28 bytes) and writes its u16, u8
 * and two bitfields to four out pointers.
 */
void func_0200A908(const Entry_0 *p, u32 i, u16 *n, u8 *a, u8 *b, u8 *c)
{
    *n = p[i].n;
    *a = p[i].a;
    *b = p[i].b;
    *c = p[i].c;
}


/*
 * Unlabelled Thumb leaf: low byte of the word at +0x348.
 */
u8 func_0200A930(char *p)
{
    return ((B *)(p + 0x348))->v;
}


int sub_0200A940(void *a0, int a1, int a2, void *a3)
{
    u32 n = sub_0200A8AC(a0);
    int target = sub_0200AA00(a1, a2, a3);
    int best = 0;
    u32 bestd = 0xffffffffu;
    u32 i;

    for (i = 0; i < n; i++) {
        int d = sub_0200A8D0(a0, i) - target;
        if (d < 0) {
            d = -d;
        }
        if (bestd == d) {
            u32 tmp[2];
            tmp[0] = (u32)best;
            tmp[1] = (u32)i;
            best = (int)tmp[sub_020056EC(2)];
        } else if (bestd > d) {
            best = i;
            bestd = d;
        }
    }
    return best;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * The two helpers between func_0200A940 and func_0200AA00, both invisible
 * to the worklist: each saves registers but not lr and nothing branches to
 * either from outside, so disasm.py prints the pair as a single run of
 * `.word` (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * The 92 bytes here cover the whole gap.
 *
 * Both walk the same array of 0x1e records of 0x1c bytes that
 * func_0200A940 above them indexes, and both accept a record on the same
 * pair of tests: the u32 at +0x14 equal to the key and bit 31 of the u32
 * at +0x10 set.  The first returns bit 7 of the byte at +0x1b of the
 * matching record, the second returns 1.
 */
int sub_0200A9A4(struct T0200A9A4 *o, u32 v)
{
    int i;

    for (i = 0; i < 0x1e; i++) {
        if (o[i].f14 == v && (o[i].f10 >> 31) == 1)
            return (u32)(o[i].f1b << 24) >> 31;
    }
    return 0;
}


int sub_0200A9D4(struct T0200A9A4 *o, u32 v)
{
    int i;

    for (i = 0; i < 0x1e; i++) {
        if (o[i].f14 == v && (o[i].f10 >> 31) == 1)
            return 1;
    }
    return 0;
}


/*
 * A date interpolation: copy the caller's 16-byte date record onto the
 * stack (the `ldm/stm` pair of docs/idioms/aggregate-assignment-is-ldm-stm.md),
 * take its day number with func_0203F540, overwrite the two fields at +4 and
 * +8 with the two scalar arguments, take the day number again, and wrap the
 * difference into a year.  The tail is the fixed-point sine lookup
 * src/matched/func_0203F684.c already evidences -- the same 4096-entry signed
 * halfword table at 0x020A1B38 indexed at `2 * i`, with 30 in place of 360 --
 * scaled to a percentage: `(sin + 0x1000) * 50 >> 12`, truncated to u8.
 *
 * Two things were load-bearing and cost the run:
 *
 *  - `asrs r0, r0, #4` after the second (UNSIGNED) divide.  The division is
 *    _u32_div_f at both sites, so the expression is unsigned, but the shift
 *    is arithmetic: the quotient has to be bound to an `s32` local first.
 *    Writing the whole chain inline gives `lsrs`; making the division itself
 *    signed swaps the helper to _s32_div_f and loses the call.
 *  - `cmp r4, r0` and not `cmp r0, r4`: the guard is written `if (a >= b)`,
 *    naming the FIRST day number first.  The equivalent `if (b <= a)` is two
 *    bytes wrong (cmp operands swapped and blo becomes bhi).  This is
 *    docs/idioms/cmp-operand-order-names-the-temporary.md, and it is the same
 *    lever src/matched/func_0200ABE0.c in this family already records.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AA00.c \
 *       --func func_0200AA00 --addr 0x0200AA00 --cc 1.1p1 --thumb
 */
u8 func_0200AA00(u32 a0, u32 a1, struct Date *src)
{
    struct Date d = *src;
    u32 a, b;

    a = func_0203F540((struct RtcDate *)&d);
    d.f04 = a0;
    d.f08 = a1;
    b = func_0203F540((struct RtcDate *)&d);
    if (a >= b) {
        b += 365;
    }
    {
        s32 i = (s32)((((b - a) % 30) * 0xFFFF) / 30);
        return (u8)((tbl_020A1B38[2 * (i >> 4)] + 0x1000) * 50 >> 12);
    }
}


/*
 * EXACT*: the listing extent is 196 bytes because the two unlabelled leaves
 * at 0x0200AB04 and 0x0200AB24 follow without a label; they are already
 * matched separately as src/matched/unit_0200AB04.c.  This file reproduces
 * the 154 bytes of sub_0200AA68 itself.
 *
 * The orchestrator of the family (see docs/families/mystery_data.h).  Find an
 * existing Entry with the caller's key (sub_0200ACD0), take its 10-bit
 * counter if there is one, build a fresh Entry on the stack from that counter
 * and the caller's eleven arguments (sub_0200AC14), insert it in key order
 * (sub_0200AB50) recording the slot in the low byte of the record's flag word
 * at +0x348, and if the new entry duplicates one already present
 * (sub_0200ABE0) bump every matching entry's counter (sub_0200AD00).  It
 * returns the slot back out of the flag word.
 *
 * This row was the "unfilable" one of docs/notes/pkt_0200AA00.c.txt (misfiled
 * under that name; it is about 0x0200AA68).  That note's verdict was that
 * every one of the five call sites is unwitnessed outside the compared range
 * and the row therefore caps at MATCH.  THAT IS NO LONGER TRUE, for two
 * independent reasons: all five callees are matched today, and the
 * `sole-ref/code` class introduced 2026-09-21 carries a code target that is
 * exactly a traced function start with no outside-branch requirement, which
 * is precisely the single-caller-callee shape here.  All five sites now
 * resolve as `sole-ref`, and the row is EXACT* rather than MATCH.
 *
 * Three declaration-level levers, none of them a statement shape:
 *
 *  1. sub_0200AC14 takes EIGHT SEPARATE SCALAR PARAMETERS, not one 0x20-byte
 *     struct by value (see the header of src/matched/func_0200AC14.c, which
 *     this wave re-read the same way).  Passing a struct makes this caller
 *     emit an ldm/stm block copy where the original stores each field into
 *     its own outgoing word with `str`; the scalar form is what produces the
 *     `ldrb r1, [r0, #4] / str r1, [sp, #8]` ladder at +0x28..+0x48.
 *  2. `a2` is u16, not u32.  This is the one the permuter found:
 *       --mode hill --budget 800 --types, 189 single mutations tried,
 *       191st compile: type:p(a2:u32->u16), 74 concrete bytes out -> 46,
 *       and it aligned the whole first 0x5C bytes of the function.
 *     Nothing about the disassembly says a2 is narrow directly; it says so
 *     only through the register allocation downstream of it, which is exactly
 *     the residue class permuter.py exists for.
 *  3. The +0x348 flag word is read and written as an 8-bit BITFIELD, not
 *     masked by hand.  `((Flags *)&r->f348)->b0 = sub_0200AB50(...)` gives
 *     the interleaved `lsls r0, #0x18 / ... / lsrs r0, #0x18 / orrs r0, r2`
 *     the original has; the hand-written `r->f348 = (r->f348 & ~0xff) | slot`
 *     hoists the truncation out of the mask work and is 4 bytes short.  The
 *     read at the end needs the same bitfield, which is where the SECOND
 *     `lsls #0x18 / lsrs #0x18` pair at +0x92 comes from -- a plain
 *     `(u8)(r->f348 & 0xff)` folds the two pairs into one.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AA68.c \
 *       --func sub_0200AA68 --addr 0x0200AA68 --cc 1.1p1 --thumb
 */
u8 sub_0200AA68(Rec *r, const void *src, u16 a2, u8 a3,
                u8 s0, u8 s1, u32 s2, u16 s3, u8 s4, u8 s5, u8 s6)
{
    Entry_1 tmp;
    Entry_1 *hit;
    u16 count = 0;

    hit = (Entry_1 *)sub_0200ACD0((char *)r->entries, 30, s2);
    if (hit != 0) {
        count = hit->b1;
    }
    sub_0200AC14(&tmp, src, a2, count, a3, s0, s1, s2, s3, s4, s5, s6);
    {
    ((Flags *)&r->f348)->b0 = sub_0200AB50(r->entries, 30, &tmp);
    }
    if (sub_0200ABE0((u8 *)r->entries, 30, (u8 *)&tmp) != 0) {
        sub_0200AD00(r->entries, 30, &tmp);
    }
    {
        u8 v = ((Flags *)&r->f348)->b0;
        return v;
    }
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Two unlabelled leaves at the end of the packet, after func_0200AA68:
 * `push {r4, r5}` with no lr for the first, nothing at all for the second,
 * so both print as `.word` (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The first clears bit 7 of the byte at +0x1b of each of the same 0x1e
 * records of 0x1c bytes the two helpers at 0x0200A9A4 index (that byte's
 * bit 7 is the flag sub_0200A9A4 returns); the second is a four-byte
 * constant getter for 0x34c, which Thumb spells `movs r0, #0xd3; lsls
 * r0, r0, #2`.
 */
void sub_0200AB04(struct Rec0200AB04 *o)
{
    int i;

    for (i = 0; i < 0x1e; i++)
        o[i].bits.flag = 0;
}


int sub_0200AB24(void)
{
    return 0x34c;
}


void func_0200AB2C(void *a0)
{
    func_02082BCC(a0, 0, 0x34c);
    ((struct Obj11229 *)a0)->f348 = (((struct Obj11229 *)a0)->f348 & ~0xff) | 0x7f;
}


u8 func_0200AB50(Ent *list, s32 n, Ent *dst)
{
    s32 i;
    s32 best = -1;
    s32 k;

    for (i = 0; i < n; i++) {
        if (list[i].flag != 0) {
            if (list[i].key > dst->key) continue;
        }
        best = i;
        break;
    }
    if (best == -1) return 0xff;

    for (k = n - 1; k > best; k--) {
        if (list[k].off != 0 || list[k - 1].off != 0) memcpy(&list[k - 1], &list[k], 0x1c);
    }
    memcpy(dst, &list[best], 0x1c);
    return best;
}


/*
 * The comparison has to be written with the *caller's* object on the left
 * (`*(u32 *)(b + 0x14) == *(u32 *)(p + 0x14)`): both sides are loads, and the
 * one the source names first is the one that lands in `cmp`'s left slot, so
 * swapping them is one byte (`cmp r2, r5` against `cmp r5, r2`).  Leaving the
 * invariant load in the condition rather than hoisting it into a local is
 * also load-bearing: as a local it is materialised before the `n <= 0` guard
 * and the entry test moves.  EXACT*: the 2-byte linker filler at 0x0200AC12
 * is inside the packet but the listing extent runs to the next label.
 */
int func_0200ABE0(u8 *a0, int n, u8 *b)
{
    int i;

    for (i = 0; i < n; i++) {
        u8 *p = a0 + i * 0x1c;

        if (((struct Obj15588 *)b)->f14 == ((struct Obj11230 *)p)->f14 && ((struct Obj11230 *)p)->f10 >> 31 == 1)
            return 1;
    }
    return 0;
}


/*
 * The Entry constructor of the family (see docs/families/mystery_data.h):
 * clear the 0x1C-byte record, copy 8 halfwords from `src` into the first
 * 16 bytes with sub_0201F41C, then fill the packed word at +0x10, the key at
 * +0x14, the halfword at +0x18, the byte at +0x1A and the two bit-packed
 * fields of +0x1B, and finally set the top bit of +0x10 and bit 7 of +0x1B.
 *
 * WHAT CHANGED THIS WAVE (docs/notes/pkt_0200AC14.c.txt had this row at DIFF
 * with three independent residue groups, "no recoverable source in this note"
 * on the 2026-09-21 re-verify).  The note read the eight stack words at
 * sp+0x18..sp+0x34 as ONE 0x20-byte parameter block passed BY VALUE, because
 * the function takes its address once (`add r0, sp, #0x18`) and then reads
 * fields off it with `ldrb r1, [r0, #4]`, `ldrh r1, [r0, #0xc]` and so on.
 * That reading is wrong, and it is what produced all three residues.
 *
 * They are EIGHT SEPARATE SCALAR PARAMETERS of narrow types:
 *
 *     u8 p0, u8 p1, u8 p2, u32 p3, u16 p4, u8 p5, u8 p6, u8 p7
 *
 * Each occupies its own word of the incoming argument area (the ABI passes
 * every stack argument in a word slot regardless of width), so the OFFSETS
 * are identical to the struct reading and the disassembly cannot tell the two
 * apart by offset alone.  What tells them apart is the LOAD WIDTH: a struct
 * member of declared type u8 and a u8 parameter both read `ldrb`, but only
 * the scalar form lets the compiler base every one of them off a single
 * `add r0, sp, #0x18` while keeping p3 as a plain `ldr r0, [sp, #0x24]`
 * scheduled ahead of the +0x10 store -- which is residue 1 of the note,
 * unreachable from the struct form.  Residues 2 and 3 fall out with it: the
 * a3 insert accumulates into the keep register and the bit-6 insert keeps its
 * explicit `& 1` and `(u8)` cast, both of which the struct form folded.
 *
 * The permuter confirms the struct form is a dead end rather than a spelling
 * problem: on the 188-byte, 10-concrete-bytes-out struct version,
 *   --mode hill  --budget 800  --types: 158 single mutations, no improvement
 *   --mode anneal --budget 3000 --types: 3000 compiles in 204s, completely
 *   flat at asm=400 bytes-out=10 the whole way, never once leaving the
 *   plateau.
 * A residue no mutation of the statement shape can reach is a residue in the
 * DECLARATIONS, and re-reading the parameter list was what closed it.
 *
 * The bitfield widths of Self are the ones src/matched/unit_0200A864.c
 * already evidences for this family's Entry record (7 / 10 / 1 at +0x10,
 * 6 / 1 / 1 at +0x1B); the four extra sub-fields between them (4 / 4 / 5)
 * are read off this function's own mask pool words 0xFFFDFFFF, 0xFFC3FFFF
 * and 0xFC3FFFFF at 0x0200ACC0..0x0200ACCC.
 *
 * The top bit at the end must be written `(f10 & 0x7FFFFFFF) | 0x80000000`
 * -- which is what the `b6 : 1` bitfield assignment compiles to -- and not
 * `f10 |= 0x80000000`, which loses the `ldr r0, =0x7FFFFFFF / adds r0, r0, #1`
 * pair at +0x96.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AC14.c \
 *       --func sub_0200AC14 --addr 0x0200AC14 --cc 1.1p1 --thumb
 */
void sub_0200AC14(Entry_1 *self, const void *src, u32 a2, u32 a3,
                  u8 p0, u8 p1, u8 p2, u32 p3, u16 p4, u8 p5, u8 p6, u8 p7)
{
    func_02082BCC(self, 0, 0x1c);
    sub_0201F41C(src, self->w0, 8);
    self->b0 = a2;
    self->f14 = p3;
    self->b2 = p0;
    self->b3 = p1;
    self->b4 = p2;
    self->b1 = a3;
    self->f18 = p4;
    self->f1a = p5;
    self->c0 = p6;
    self->c1 = (u8)(p7 & 1u);
    self->b6 = 1;
    self->c2 = 1;
}


char *func_0200ACD0(char *base, int count, int target)
{
    int i;
    for (i = 0; i < count; i++) {
        char *e = base + i * 0x1c;
        if (target == ((struct Obj11231 *)e)->f14) {
            if ((((struct Obj11231 *)e)->f10 >> 31) == 1)
                return e;
        }
    }
    return 0;
}


/*
 * EXACT*: the listing extent runs to 156 bytes because the function at
 * 0x0200AD6C that follows saves nothing and therefore carries no label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); this file
 * reproduces the 108 bytes of sub_0200AD00 itself, code and both pool words.
 * The unlabelled follower at 0x0200AD6C should be seeded into
 * layout/function_starts.txt by the integrator.
 *
 * Another linear scan over the family's 0x1C-byte Entry records (see
 * docs/families/mystery_data.h): for every entry whose u32 at +0x14 matches
 * the reference's, bump the 10-bit counter at bit 7 of the packed word at
 * +0x10, set bit 7 of the byte at +0x1B, and clamp the counter to 999.
 *
 * WHAT CHANGED THIS WAVE (docs/notes/pkt_0200AD00.c.txt had this row at DIFF,
 * 104 bytes against 156, 94 concrete bytes out -- effectively a whole-function
 * mismatch).  The note's C did the field access by hand:
 *
 *     v = *(u32 *)(e + 0x10);
 *     *(u32 *)(e + 0x10) = (v & 0xfffe007fu) | ((((v >> 7) & 0x3ff) + 1) << 7);
 *
 * which compiles to `lsrs #7; ands <0x3ff>` for the read and a pool word for
 * the 0x3FF, three instructions and a constant the original never
 * materialises.  The original reads the field as `lsls #0xf / lsrs #0x16` and
 * writes it back as `lsls #0x16 / lsrs #0xf`: an EQUAL-width shift pair with
 * no matching type, which is
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md -- a 10-bit
 * unsigned BITFIELD at bit 7, not a hand-rolled mask.  Declaring the whole
 * packed word as the `struct Entry` bitfields the family header already
 * evidences (func_0200A8D0/A8E4/A8F8 in src/matched/unit_0200A864.c prove the
 * 7/10/1 widths) takes the row from 94 concrete bytes out to 2 in one edit,
 * and also drops the lr push: the hand-written version needed a spill the
 * bitfield form does not.
 *
 * The last two bytes were the operand order of the guard.  Both sides are
 * loads, and the side the SOURCE names first lands in the left register:
 * `ref->unk14 != e->unk14` gives `ldr r2, [r6, #0x14]` then `ldr r1, [r5,
 * #0x14]`, and the natural-reading `e->unk14 != ref->unk14` gives them the
 * other way round.  This is docs/idioms/cmp-operand-order-names-the-temporary.md
 * and it is the THIRD function in this family to turn on it
 * (src/matched/func_0200ABE0.c and src/matched/func_0200AA00.c are the others).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AD00.c \
 *       --func sub_0200AD00 --addr 0x0200AD00 --cc 1.1p1 --thumb
 */
void sub_0200AD00(Entry_1 *base, int n, Entry_1 *ref)
{
    int i;

    for (i = 0; i < n; i++) {
        Entry_1 *e = &base[i];
        u32 x;

        if (ref->f14 != e->f14) {
            continue;
        }
        e->b1 = e->b1 + 1;
        e->c2 = 1;
        x = e->b1;
        if (x > 999) {
            x = 999;
        }
        e->b1 = x;
    }
}


/*
 * Save-block getter for block 0x2E, the same one-line shape as
 * func_0200A864 / func_0200A8A0 (blocks 0x2B, 0x2C) in unit_0200A864.c:
 * a tail call through the pool with the id in r1.
 */
void *func_0200AD6C(void *sys)
{
    return func_020071CC(sys, 0x2e);
}


/*
 * note:     wave 17 lane untried_small: return 0xF8 (the size of a 0xF8-byte record); listing extent runs over the unlabelled neighbours 0x0200AD7C, 0x0200AD8C, 0x0200AD94.
 */
int func_0200AD78(void)
{
    return 0xF8;
}


/*
 * note:     wave 18 lane ties_b: unlabelled follower of func_0200AD78; clears a 0xF8-byte record with func_02082AC0 (tail call).
 */
void func_0200AD7C(void *rec)
{
    func_02082AC0(0, rec, 0xF8);
}


/*
 * note:     wave 18 lane ties_b: unlabelled follower; getter of the u16 at +0xEC (extent includes two bytes of padding).
 */
u16 func_0200AD8C(const Rec0200AD8C *p)
{
    return p->fEC;
}


/*
 * note:     wave 18 lane ties_b: unlabelled follower; setter of the u16 at +0xEC (extent includes two bytes of padding).
 */
void func_0200AD94(Rec0200AD94 *p, u16 v)
{
    p->fEC = v;
}


void OS_KillThread(void *thread, void *arg1)
{
    void *res = (void *)func_020173EC();
    func_02082D44(thread, arg1, (int)res);
}


/*
 * Unlabelled Thumb leaf in the ARM9 module: an empty `bx lr` body.
 *
 * Addresses are Black-image addresses.
 */
void func_0200ADB4(void)
{
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200ADE8, func_0200ADF0, func_0200AE08, func_0200AE14,
 *           func_0200AE18, func_0200AE3C, func_0200AE54, func_0200AEE8,
 *           func_0200AFD4, func_0200B040, func_0200B074, func_0200B078,
 *           func_0200B110, func_0200B1A8, func_0200B1C4, func_0200B1D4,
 *           func_0200B1E0, func_0200B1F8, func_0200B204, func_0200B214,
 *           func_0200B254
 *
 * alias: the original source file is named in the image.  The constructor at
 * 0x0200ADF0 passes 0x020A71B4 to the debug allocator at 0x02030734, and the
 * bytes there spell "regulation.c"; the string before it is
 * "mystery_data.c", which is what the `string` attestation class uses to fix
 * the address without reading the pool word under test.  That makes this the
 * second original source file name this project has recovered, after
 * "playtime.c".  The functions keep their func_<address> names, because the
 * file identity is attested and the individual entry points are not.
 *
 * 1260 bytes, 0x0200ADB8..0x0200B2A4, 25 functions, eleven of which carry no
 * label in the generated listing.
 *
 * What a regulation is, read off the accessors: a 0xBC-byte record of
 * battle-rule settings.  The pair at 0x0200AE54 and 0x0200AEE8 is its whole
 * scalar interface, a get and a set indexed by a rule id in 0..22, and the
 * set carries the legal range of every rule: ids 0 to 3 take a value under 7,
 * 6 and 6 and 6; id 4 is capped at 100; id 6 at 600; ids 7, 8, 13, 17 and 19
 * are booleans; id 11 is a u16 under 651; id 20 is capped at 99.  Ids 9, 10
 * and 14 are missing from both tables because they are not scalars: they are
 * the three bitmaps at +0x0A, +0x5C and +0xAC that func_0200AFD4 tests a bit
 * of.  A second pair at 0x0200B078 and 0x0200B110 does the same job for a
 * larger record that contains this one at offset 0, over ids 1..12 and a set
 * of signed fields at 0x152..0x15D.  0x0200B1A8 checks the record against the
 * checksum stored at +0x15E.
 *
 * Four things here are worth naming:
 *
 *  - a dense switch becomes a PC-relative halfword jump table, and the whole
 *    of it, table included, comes out of ordinary C.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.  The table
 *    is what reads the case list back: an entry pointing at the common exit
 *    is a case that is absent from the source, which is how ids 9, 10 and 14
 *    above are known to be missing rather than empty.
 *  - func_0200B078 falls off the end of its switch with no return statement,
 *    and the original's default arm is a bare `bx lr` that returns the
 *    incoming pointer.  Adding a `return 0;` to make the C well-formed adds
 *    an instruction and moves every case body.
 *  - a 0x160-byte struct assignment is an inline eight-byte `ldm`/`stm` loop
 *    rather than a call, but only when the struct is four-aligned; declared
 *    as a `u8` array it is a byte loop instead.  See
 *    docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *  - `p->unk12 >> n` on a `u8` field is an *arithmetic* shift, because the
 *    field promotes to `int` before the shift.  Writing the field as `u32`,
 *    or casting, gives `lsrs` and two bytes wrong in func_0200B214.
 */
void func_0200ADB8(void *dest, const void *src, u32 a2)
{
    MI_CpuCopy8(src, dest, func_020173EC());
}


void func_0200ADD0(struct RegB *p, u32 value)
{
    p->unkF0 = value;
}


void func_0200ADD8(struct RegB *p, u32 value)
{
    p->unkF4 = value;
}


u16 func_0200ADE0(struct RegB *p)
{
    return p->unkEE;
}


u32 func_0200ADE8(void)
{
    return 0x2FC;
}


struct Reg *func_0200ADF0(u32 heap)
{
    return func_02030734(heap, sizeof(struct Reg), 1, func_0200ADF0_File,
                         0x73);
}


void func_0200AE08(const struct Reg *src, struct Reg *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Reg));
}


void func_0200AE14(void)
{
}


void func_0200AE18(struct Reg *p, void *dest)
{
    void *g = func_02045B38(0, 2, 0xA6, 1);

    func_02045CAC(g, ((struct Obj17006 *)p)->f0, dest);
    func_02045C04(g);
}


void *func_0200AE3C(struct Reg *p, u32 heap)
{
    void *dest = func_020457B0(0x1A, heap);

    func_0200AE18(p, dest);
    return dest;
}


u32 func_0200AE54(struct Reg *p, u32 id)
{
    u32 v = 0;

    switch (id) {
    case 0:  v = p->unk00; break;
    case 1:  v = p->unk01; break;
    case 2:  v = p->unk02; break;
    case 3:  v = p->unk03; break;
    case 4:  v = p->unk04; break;
    case 5:  v = p->unk05; break;
    case 6:  v = p->unk06; break;
    case 7:  v = p->unk08; break;
    case 8:  v = p->unk09; break;
    case 11: v = p->unkA8; break;
    case 12: v = p->unkAA; break;
    case 13: v = p->unkAB; break;
    case 15: v = p->unkB3; break;
    case 16: v = p->unkB4; break;
    case 17: v = p->unkB5; break;
    case 18: v = p->unkB6; break;
    case 19: v = p->unkB8; break;
    case 20: v = p->unkB9; break;
    case 21: v = p->unkBA; break;
    case 22: v = p->unkBB; break;
    }
    return v;
}


void func_0200AEE8(struct Reg *p, u32 id, s32 value)
{
    switch (id) {
    case 0:  if (value < 7)     { p->unk00 = value; } break;
    case 1:  if (value < 6)     { p->unk01 = value; } break;
    case 2:  if (value < 6)     { p->unk02 = value; } break;
    case 3:  if (value < 6)     { p->unk03 = value; } break;
    case 4:  if (value <= 100)  { p->unk04 = value; } break;
    case 5:  if (value <= 6)    { p->unk05 = value; } break;
    case 6:  if (value <= 600)  { p->unk06 = value; } break;
    case 7:  if (value < 2)     { p->unk08 = value; } break;
    case 8:  if (value < 2)     { p->unk09 = value; } break;
    case 11: if (value < 0x28B) { p->unkA8 = value; } break;
    case 12: p->unkAA = value; break;
    case 13: if (value < 2)     { p->unkAB = value; } break;
    case 15: p->unkB3 = value; break;
    case 16: p->unkB4 = value; break;
    case 17: if (value < 2)     { p->unkB5 = value; } break;
    case 18: p->unkB6 = value; break;
    case 19: if (value < 2)     { p->unkB8 = value; } break;
    case 20: if (value <= 0x63) { p->unkB9 = value; } break;
    case 21: if (value < 6)     { p->unkBA = value; } break;
    case 22: p->unkBB = value; break;
    }
}


u32 func_0200AFD4(struct Reg *p, u32 id, s32 n)
{
    s32 byte = n / 8;
    s32 bit  = n % 8;

    switch (id) {
    case 9:
        if (p->unk0A[byte] & (1 << bit)) {
            return 1;
        }
        break;
    case 10:
        if (p->unk5C[byte] & (1 << bit)) {
            return 1;
        }
        break;
    case 14:
        if (p->unkAC[byte] & (1 << bit)) {
            return 1;
        }
        break;
    }
    return 0;
}


void func_0200B040(struct Reg *p, struct RegAC *out)
{
    MI_CpuFill8(out, 0, sizeof(struct RegAC));
    out->unk7 = func_0200AE54(p, 13);
    if (out->unk7 >= 2) {
        out->unk7 = 1;
    }
    MI_CpuCopy8(p->unkAC, out, 7);
}


u8 *func_0200B074(struct Reg2 *p)
{
    return p->unkC0;
}


s32 func_0200B078(struct Reg2 *p, u32 id)
{
    switch (id) {
    case 1:  return p->unkBC;
    case 2:  return p->unk152;
    case 3:  return p->unk154;
    case 4:  return p->unk155;
    case 5:  return p->unk156;
    case 6:  return p->unk157;
    case 7:  return p->unk158;
    case 8:  return p->unk159;
    case 9:  return p->unk15A;
    case 10: return p->unk15B;
    case 11: return p->unk15C;
    case 12: return p->unk15D;
    }
}


void func_0200B110(struct Reg2 *p, u32 id, s32 value)
{
    switch (id) {
    case 1:  p->unkBC  = value; break;
    case 2:  p->unk152 = value; break;
    case 3:  p->unk154 = value; break;
    case 4:  p->unk155 = value; break;
    case 5:  p->unk156 = value; break;
    case 6:  p->unk157 = value; break;
    case 7:  p->unk158 = value; break;
    case 8:  p->unk159 = value; break;
    case 9:  p->unk15A = value; break;
    case 10: p->unk15B = value; break;
    case 11: p->unk15C = value; break;
    case 12: p->unk15D = value; break;
    }
}


u32 func_0200B1A8(struct Reg2 *p)
{
    if (p->unk15E == func_0200B1C4(p)) {
        return 1;
    }
    return 0;
}


u16 func_0200B1C4(struct Reg2 *p)
{
    return func_0203F1FC((const u8 *)p, 0x15E);
}


struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index)
{
    return &arr[index];
}


void func_0200B1E0(struct Rec160 *arr, u32 index, const struct Rec160 *src)
{
    arr[index] = *src;
}


void func_0200B1F8(struct Rec1E *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Rec1E));
}


struct Rec1E *func_0200B204(struct RecBig *p, u32 index)
{
    return &p->unk2C0[index];
}


s32 func_0200B214(struct Rec1E *p, u32 id, u8 n)
{
    switch (id) {
    case 0: return p->unk00[n];
    case 1: return p->unk0C[n];
    case 2: return (p->unk12 >> n) & 1;
    case 3: return (p->unk13 >> n) & 1;
    }
    return 0;
}


void func_0200B254(struct Rec1E *p, int id, u8 n, s32 value)
{
    switch (id) {
    case 0: p->unk00[n] = value; break;
    case 1: p->unk0C[n] = value; break;
    case 2: p->unk12 |= (u8)((value == 1) << n); break;
    case 3: p->unk13 |= (u8)((value == 1) << n); break;
    }
}
