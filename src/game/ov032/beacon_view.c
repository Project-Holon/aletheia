/*
 * file:     beacon_view.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFF7C, func_021F0050, func_021F0078, func_021F00C8, func_021F0114, func_021F0140, func_021F0208, func_021F028C, func_021F029C, func_021F02C4, func_021F03EC, func_021F0438, func_021F055C, func_021F05E8, func_021F0668, func_021F067C, func_021F0684, func_021F06E0, func_021F079C, func_021F07D4, func_021F0820, func_021F086C, func_021F0884, func_021F089C, func_021F08E4, func_021F096C, func_021F0A18, func_021F0A98, func_021F0AC0, func_021F0B10, func_021F0B64, func_021F0B80, func_021F0BA8, func_021F0C04, func_021F0C70, func_021F0CF8, func_021F0D38, func_021F0D5C, func_021F0D9C, func_021F0DC0, func_021F0DD8, func_021F0DE0, func_021F0DF4, func_021F0E04, func_021F0E24, func_021F0E7C, func_021F0EA4, func_021F0ED0, func_021F0EDC, func_021F0F30, func_021F0F44, func_021F0F74, func_021F0FC8, func_021F0FE8, func_021F1004, func_021F1070, func_021F1080, func_021F10D8, func_021F1144, func_021F1218, func_021F1268, func_021F12B8, func_021F1340, func_021F13A0, func_021F1418, func_021F1484, func_021F150C, func_021F155C, func_021F1704, func_021F178C, func_021F17D8, func_021F180C, func_021F1888, func_021F18C4, func_021F18E0, func_021F1930, func_021F199C, func_021F1A08, func_021F1A18, func_021F1A28, func_021F1B94, func_021F1CF0, func_021F1E40, func_021F1EAC, func_021F1F00, func_021F1F34, func_021F1F9C, func_021F201C, func_021F20A8, func_021F20E4, func_021F2144, func_021F21B0, func_021F21F8, func_021F2234, func_021F22FC, func_021F2344, func_021F23F8, func_021F2404, func_021F253C, func_021F2544, func_021F254C, func_021F2588, func_021F25D4, func_021F2608, func_021F2624, func_021F2664, func_021F2674, func_021F26D8, func_021F26F0, func_021F2714, func_021F27B4, func_021F27CC, func_021F27D4, func_021F28DC, func_021F2908, func_021F2A04, func_021F2A8C, func_021F2BD4, func_021F2C1C, func_021F2CC4, func_021F2D20, func_021F2EDC, func_021F2F44, func_021F2FCC, func_021F3010, func_021F3058, func_021F30B4, func_021F30D4, func_021F31A8, func_021F3214, func_021F3264, func_021F32D4, func_021F32F8
 * address:  0x021EFEC0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02021EE4  0x02021EE4  thumb
 *   func_02165AC4  0x02165AC4  thumb  ov010
 *   func_021659F0  0x021659F0  thumb  ov010
 *   func_0203D34C  0x0203D34C  arm
 *   func_02035D20  0x02035D20  arm
 *   func_02165C10  0x02165C10  thumb  ov010
 *   func_02035CB8 0x02035CB8 arm
 *   func_021585E0  0x021585E0  thumb  ov010
 *   func_02012204  0x02012204  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_020275D0  0x020275D0  thumb
 *   func_020275C4  0x020275C4  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   sub_02010EA0 0x02010EA0 thumb
 *   func_021658D4  0x021658D4  thumb  ov010
 *   func_02165B5C  0x02165B5C  thumb  ov010
 *   func_02165A10  0x02165A10  thumb  ov010
 *   func_0200C1E0  0x0200C1E0  thumb
 *   func_02021FD8  0x02021FD8  thumb
 *   func_021D3294  0x021D3294  thumb  ov021
 *   func_0201C4DC 0x0201C4DC thumb
 *   func_021657E8  0x021657E8  thumb  ov010
 *   func_0204B98C 0x0204B98C arm
 *   func_02165D08  0x02165D08  thumb  ov010
 *   func_02165C48  0x02165C48  thumb  ov010
 *   func_02165C50  0x02165C50  thumb  ov010
 *   _u32_div_f     0x0209C2B0  arm
 *   MI_CpuCopy8   0x02082D44  arm
 *   d_021F3554    0x021F3554  data  a4
 *   d_021F356C     0x021F356C  data  a4
 *   d_021F3538     0x021F3538  data  a1
 *   func_0204B898  0x0204B898  arm
 *   func_02035D40  0x02035D40  arm
 *   d_021F3530     0x021F3530  data  a2
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02041FF4  0x02041FF4  arm
 *   func_0202800C  0x0202800C  thumb
 *   func_0202846C  0x0202846C  thumb
 *   func_02028178  0x02028178  thumb
 *   func_0202824C  0x0202824C  thumb
 *   func_0202822C  0x0202822C  thumb
 *   func_02028230  0x02028230  thumb
 *   func_02028148  0x02028148  thumb
 *   func_02165E24 0x02165E24 thumb ov010
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02025774 0x02025774 thumb
 *   func_020257D0  0x020257D0  thumb
 *   func_0204581C  0x0204581C  arm
 *   func_02031194  0x02031194  arm
 *   func_02165CE8  0x02165CE8  thumb  ov010
 *   func_0204A9D0  0x0204A9D0  arm
 *   func_020215BC  0x020215BC  thumb
 *   d_021F3541     0x021F3541  data  ov032  a1
 *   func_02165CC0  0x02165CC0  thumb  ov010
 *   func_02021F64  0x02021F64  thumb
 *   func_02026D48  0x02026D48  thumb
 *   func_02165CB4 0x02165CB4 thumb ov010
 *   func_02165CE4  0x02165CE4  thumb  ov010
 *   func_02165C34  0x02165C34  thumb  ov010
 *   func_02165D50  0x02165D50  thumb  ov010
 *   func_02165D6C  0x02165D6C  thumb  ov010
 *   func_02165D8C  0x02165D8C  thumb  ov010
 *   func_0202590C 0x0202590C thumb
 *   func_020275B8 0x020275B8 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0207C768 0x0207C768 arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_02040618 0x02040618 arm
 *   func_02165FCC 0x02165FCC thumb ov010
 *   func_02165374 0x02165374 thumb ov010
 *   func_0200C1C8 0x0200C1C8 thumb
 *   func_02045838 0x02045838 arm
 *   func_02165EBC 0x02165EBC thumb ov010
 *   func_02165D20 0x02165D20 thumb ov010
 *   func_02031288 0x02031288 arm
 *   func_0201F184 0x0201F184 thumb
 *   func_02010FA0 0x02010FA0 thumb
 *   func_02007FB8 0x02007FB8 thumb
 *   func_02010EEC 0x02010EEC thumb
 *   d_021F352C 0x021F352C data ov032 a1
 *   func_02165FC0 0x02165FC0 thumb ov010
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02045770 0x02045770 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_02030734 0x02030734 arm
 *   d_021F36A0 0x021F36A0 data ov032 a1
 *   func_020120F4 0x020120F4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188E30 0x02188E30 thumb ov021
 *   func_020490F4 0x020490F4 arm
 *   func_0203115C 0x0203115C arm
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020310C4 0x020310C4 arm
 *   func_02165888 0x02165888 thumb ov010
 *   func_02158614 0x02158614 thumb ov010
 *   func_021945A4 0x021945A4 thumb ov021
 *   func_02164B38 0x02164B38 thumb ov010
 *   func_020124AC 0x020124AC thumb
 *   func_021CD2A4 0x021CD2A4 thumb ov021
 *   func_021F5260 0x021F5260 thumb ov083
 *   func_021F5368 0x021F5368 thumb ov083
 *   ov083_id 0x00000053 data
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0201235C 0x0201235C thumb
 *   func_020282A4 0x020282A4 thumb
 *   func_02021D50 0x02021D50 thumb
 *   func_02012A54  0x02012A54  thumb
 *   func_020275A8  0x020275A8  thumb
 *   func_02165B04  0x02165B04  thumb  ov010
 *   func_020275AC  0x020275AC  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF10  0x0200BF10  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   func_02008730  0x02008730  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02165B2C  0x02165B2C  thumb  ov010
 *   func_02165B10  0x02165B10  thumb  ov010
 *   func_02010F7C  0x02010F7C  thumb
 *   func_02165940 0x02165940 thumb ov010
 *   func_02010F8C 0x02010F8C thumb
 *   func_0203101C  0x0203101C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_0201C4C8  0x0201C4C8  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_0201DD68  0x0201DD68  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02031140 0x02031140 arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_020216B4  0x020216B4  thumb
 *   func_02021640  0x02021640  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040588  0x02040588  arm
 *   d_021F3608     0x021F3608  data  ov032  a4
 *   d_021F3628     0x021F3628  data  ov032  a4
 *   d_021F3648     0x021F3648  data  ov032  a4
 *   d_021F3668     0x021F3668  data  ov032  a4
 *   func_020403F4 0x020403F4 arm
 *   func_02028590 0x02028590 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02028604 0x02028604 thumb
 *   func_02049250  0x02049250  arm
 *   func_02062A98  0x02062A98  arm
 *   func_02062A00  0x02062A00  arm
 *   DC_FlushAll    0x02086284  arm
 *   d_021F35BC     0x021F35BC  data  ov032  a2
 *   d_021F35C8     0x021F35C8  data  ov032  a2
 *   d_021F35D4     0x021F35D4  data  ov032  a2
 *   d_021F35E0 0x021F35E0 data ov032 a4
 *   func_0204B100 0x0204B100 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B258 0x0204B258 arm
 *   func_02025538 0x02025538 thumb
 *   func_02043598 0x02043598 arm
 *   func_021F34C8 0x021F34C8 thumb ov032
 *   func_02025588 0x02025588 thumb
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020450F0 0x020450F0 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204BA20 0x0204BA20 arm
 *   d_021F35F0 0x021F35F0 data ov032 a2
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02043678  0x02043678  arm
 *   func_020255A0  0x020255A0  thumb
 */
#include "../../matched/include/Obj00007.h"
#include "../../matched/include/Obj00188.h"
#include "../../matched/include/Obj09794.h"
#include "../../matched/include/Obj05120.h"
#include "../../matched/include/Obj20414.h"
#include "../../matched/include/Obj20415.h"
#include "../../matched/include/Obj20416.h"
#include "../../matched/include/Obj09795.h"
#include "../../matched/include/Obj04310.h"
#include "../../matched/include/Obj07629.h"
#include "../../matched/include/Obj13061.h"
#include "../../matched/include/Obj00225.h"
#include "../../matched/include/Obj20418.h"
#include "../../matched/include/Obj09797.h"
#include "../../matched/include/Obj13063.h"
#include "../../matched/include/Obj06134.h"
#include "../../matched/include/Obj01676.h"
#include "../../matched/include/Obj00710.h"
#include "../../matched/include/Obj04311.h"
#include "../../matched/include/Obj20428.h"
#include "../../matched/include/Obj03636.h"
#include "../../matched/include/Obj00007.h"
#include "../../matched/include/Obj09798.h"
#include "../../matched/include/Obj02751.h"
#include "../../matched/include/Obj20431.h"
#include "../../matched/include/Obj20433.h"
#include "../../matched/include/Obj01037.h"
#include "../../matched/include/Obj00879.h"
#include "../../matched/include/Obj05121.h"
#include "../../matched/include/Obj20436.h"
#include "../../matched/include/Obj02113.h"
#include "../../matched/include/Obj20437.h"
#include "../../matched/include/Obj20438.h"
#include "../../matched/include/Obj13066.h"
#include "../../matched/include/Obj04312.h"
#include "../../matched/include/Obj20439.h"
#include "../../matched/include/Obj20441.h"
#include "../../matched/include/Obj02752.h"
#include "../../matched/include/Obj20443.h"
#include "../../matched/include/Obj20444.h"
#include "../../matched/include/Obj06135.h"
#include "../../matched/include/Obj07634.h"
#include "../../matched/include/Obj09799.h"
#include "../../matched/include/Obj20446.h"
#include "../../matched/include/Obj06136.h"
#include "../../matched/include/Obj06137.h"
#include "../../matched/include/Obj20448.h"
#include "../../matched/include/Obj07635.h"
#include "../../matched/include/Obj07637.h"
#include "../../matched/include/Obj20452.h"
#include "../../matched/include/Obj20453.h"
#include "../../matched/include/Obj07638.h"
#include "../../matched/include/Obj20455.h"
#include "../../matched/include/Obj20458.h"
#include "../../matched/include/Obj00812.h"
#include "../../matched/include/Obj20459.h"
#include "../../matched/include/Obj20460.h"
#include "../../matched/include/Obj07639.h"
#include "../../matched/include/Obj09800.h"
#include "../../matched/include/Obj13067.h"
#include "../../matched/include/Obj05123.h"
#include "../../matched/include/Obj20461.h"
#include "../../matched/include/Obj20462.h"
#include "../../matched/include/Obj07640.h"
#include "../../matched/include/Obj13068.h"
#include "../../matched/include/Obj13069.h"

#define FX32_CONST(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)
struct Obj02021EE4;
struct Queue;
struct Rec_021EFEC0;
struct Ctx;
struct WordSet;
struct Blk34;
struct Chan02021FD8;
struct PrintSys;
struct Actor;
struct Obj;
struct MsgBank;
struct CharBuf;
struct Descriptor;
struct Vec2;
struct TcblNode;
struct U16Vec;
struct PalAnmSlot;
struct S_021EFEC0;
struct Sub0204A9D0;
struct Strbuf;
struct Grid;
struct S02030FB4;
struct Rec02010FA0;
struct Cfg;
struct Tcbl;
struct Desc;
struct S0201235C;
struct S02021D50;
struct Big;
struct BigObj;
struct Rec1B0;
struct Sub0200852CObj;
struct Node;
struct S02031140;
struct BgTemplate;
struct R;
struct TaskMenuState;
struct ArcFile;
struct NitroFileHeader;
struct Bank;
struct Param;
struct Sys;
struct Bmp;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_021EFEC0;

typedef struct { u32 x, y; } Pair_021EFEC0;

typedef struct { int x, y; } Vec2;

typedef struct { short x,y; } Pair_021F0BA8;

typedef struct S_021EFEC0 S_021EFEC0;

typedef signed char s8;

typedef struct Rec_021EFEC0 Rec_021EFEC0;

typedef signed int     s32;

typedef struct {
    u32 a;
    u32 b;
} Args;

typedef struct { void *f00; void *f04; unsigned f08; void *f0c; void *f10; } Desc;

typedef struct { int state; void *f04; unsigned f08; void *owner; unsigned f10; unsigned f14; unsigned f18; } Work_021F254C;

typedef struct {
    u32 count;
    u32 *items;
} ResList;

typedef struct {
    u16 count;
    u16 base;
} ResSpec;

typedef struct {
    ResSpec s[3];
} ResSpec3;

typedef struct {
    void *data;
    void *res;
} Ent;

typedef struct {
    u8 *hdr;
    u32 data;
    void *res;
} Res3;

typedef struct {
    u8 pad0[0x96];
    u16 heap;
    u16 heap2;
    u8 pad9a[0x12];
    u32 fac;
    u8 padb0[0x84];
    ResList l134[3];
    ResList l14c[3];
    ResList l164[3];
    u8 pad17c[0x15c];
    Ent e2[12];
    Ent e1[16];
    Res3 r3b8;
    Res3 r3c4;
} Work_021F2A8C;

typedef struct { int w[4]; } T16;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    unsigned char fc;
} T_021F254C;

typedef struct {
    unsigned n0;
    unsigned *a0;
    unsigned n1;
    unsigned *a1;
    unsigned n2;
    unsigned *a2;
} T_021F31A8;

typedef struct {
    short x;
    short y;
    unsigned short w;
    unsigned char z;
    unsigned char h;
} Rect;

typedef struct {
    short x;
    short y;
} Pt;

typedef struct {
    char pad[0x138];
    unsigned *a;        /* 0x138 */
    int pad2;
    unsigned *b;        /* 0x140 */
    int pad3;
    unsigned *c;        /* 0x148 */
    char pad4[0x2BC - 0x14C];
    void *o[6];         /* 0x2BC */
} S_021F254C;

typedef short          s16_021F254C;

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 pad03[5];
    s16_021F254C x;
    s16_021F254C y;
    void *f0c;
    void *f10;
    void *f14;
    void *f18;
    void *f1c;
    void *f20;
    void *f24;
    u32 f28;
    u8 pad2c[8];
} Rec_021F254C;

typedef struct {
    void *bmp;
    s16_021F254C x;
    s16_021F254C y;
    u32 f08;
    u32 f0c;
    u8 f10;
    u8 f11;
    u16 f12;
    u32 f14;
} Tmpl;

extern void func_02021EE4(struct Obj02021EE4 *o, int v);
extern int func_02165AC4(struct Queue *q, struct Rec_021EFEC0 *out, u16 *tag, int delta);
extern int func_021659F0(u8 *q, int delta);
extern void func_0203D34C(u32 a, u32 b);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_02165C10(u8 *p);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern int func_021585E0(int);
extern u32 func_02012204(const struct Ctx *p);
extern u32 func_0201058C(void *key);
extern void *func_020275D0(char *p);
extern int func_020275C4(void *p);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern u8 sub_02010EA0(int,u8 *);
extern int func_021658D4(struct Queue *q, struct Rec_021EFEC0 *out, u16 *tag);
extern int func_02165B5C(struct Rec_021EFEC0 *r);
extern int func_02165A10(struct Queue *q, struct Rec_021EFEC0 *rec, u16 tag, int *flag);
extern u32 func_0200C1E0(struct Blk34 *p);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void func_021D3294(u32 p, u32 a, u32 b, u32 c, u32 d);
extern void func_0201C4DC(struct PrintSys *p, u32 lo, u32 hi);
extern void func_021657E8(void *a, u16 b);
extern u32 func_0204B98C(struct Actor *);
extern u8 func_02165D08(struct Rec_021EFEC0 *r);
extern u32 func_02165C48(u32 rec);
extern u32 func_02165C50(u32 x);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u16 func_0204B898(struct Obj *p);
extern u32 func_02035D40(struct Ctx *ctx, u32 a, u32 b);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern u32 func_02041FF4(u32 layer, u16 x, u16 y, u16 *flags);
extern u32 *func_0202800C(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7,
                          u16 a8);
extern u32 func_0202846C(u8 *p);
extern void func_02028178(u8 *p);
extern u32 func_0202824C(void **p);
extern void func_0202822C(char *p, int v);
extern u32 func_02028230(u8 *p);
extern void func_02028148(u8 *p);
extern int func_02165E24(int a0);
extern void func_020061E4(unsigned int a);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02025774(unsigned char *,unsigned);
extern void func_020257D0(struct Obj *o);
extern void func_0204581C(struct U16Vec *vec);
extern void func_02031194(struct TcblNode *n);
extern u8 func_02165CE8(struct S_021EFEC0 *p);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern void func_02165CC0(int a0, int a1);
extern void func_02021F64(u16 *, u16 *, int, u8, u16);
extern u16 func_02026D48(u16 v);
extern u8 func_02165CB4(int a);
extern u16 func_02165CE4(u8 *r);
extern void func_02165C34(struct Rec_021EFEC0 *r, void *buf);
extern void func_02165D50(struct Rec_021EFEC0 *r, struct Strbuf *buf);
extern int func_02165D6C(int a0, int a1);
extern int func_02165D8C(int a0, int a1);
extern void func_0202590C(struct Grid *g, s16_021EFEC0 x, s16_021EFEC0 y);
extern void func_020275B8(char *p, int v);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_02082BCC(void *p, int v, int n);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02165FCC(int a, int b, u16 c);
extern void func_02165374(unsigned a0);
extern u32 func_0200C1C8(struct Blk34 *p);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern u16 func_02165EBC(struct Rec_021EFEC0 *r);
extern u8 func_02165D20(struct Rec_021EFEC0 *r);
extern void func_02031288(int *p, int v);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern unsigned int func_02010FA0(struct Rec02010FA0 *p, int idx);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern int func_02010EEC(void);
extern u8 func_02165FC0(u32 type);
extern void func_0201C7D0(u32 bmp, u32 x, u32 y, const void *text, u32 f, u16 color);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02041B6C(u32 bit);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188E30(u8 *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0203115C(struct Tcbl *p);
extern void func_02049238(void *h);
extern u32 func_020307B0(void *p);
extern void func_020310C4(struct Tcbl *p);
extern int func_02165888(int a0);
extern void func_02158614(void *p);
extern void *func_021945A4(void *a, u32 b, u32 c);
extern void *func_02164B38(void *a, void *b, u8 c);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern u32 func_021CD2A4(u32 a, u32 b, u32 x, u32 c, u32 d);
extern void *func_021F5260(void *a0, int *a1);
extern void *func_021F5368(void *p, void *q);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern void func_020282A4(struct Obj *obj);
extern void func_02021D50(struct S02021D50 *);
extern u32 func_02012A54(const struct BigObj *p);
extern u32 func_020275A8(u32 a);
extern u8 func_02165B04(u8 *q);
extern u8 func_020275AC(u8 *p);
extern signed char func_02012FFC(void);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern u8 func_0200BF10(struct Rec1B0 *p);
extern u32 func_02012138(const struct Ctx *p);
extern u32 func_0201283C(const struct BigObj *p);
extern void *func_0201292C(const struct BigObj *p);
extern void *func_0200C0E8(void *sys);
extern u32 func_0200C1DC(struct Blk34 *p);
extern struct Sub0200852CObj *func_02008730(void *sys);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 *func_02165B2C(u32 heap);
extern u8 *func_02165B10(u32 heap);
extern void *func_02010F7C(u32 heap);
extern void func_02165940(unsigned char *p);
extern void func_02010F8C(void *);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_020056A0(void *fn, void *ctx, u32 a);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern u32 func_0201C440(void *p);
extern void func_0201C4C8(struct PrintSys *p, u32 v);
extern u32 func_02188C54(u8 *p);
extern u32 func_021904AC(u8 *p);
extern void func_0201DD68(void);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(Rec_021F254C *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_02030EAC(struct Node *n);
extern void func_02031140(struct S02031140 *p);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_020216B4(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02021640(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(unsigned);
extern unsigned func_02028590(int, int, int, unsigned);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern int func_02028604(int a0);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern s32 func_02062A00(struct NitroFileHeader *file, void **out);
extern void DC_FlushAll(void);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void *func_02025538(unsigned int a0, void *a1);
extern void func_02043598(unsigned, unsigned);
extern void func_021F34C8(char *, int);
extern void func_02025588(void *p);
extern void func_0204B084(int);
extern u32 func_0204B1CC(struct Bank *bank);
extern void *func_020450F0(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern u32 func_020452E8(struct Descriptor *d);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204B3B4(struct Obj *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
void func_021EFEC0(u8 *o);
int func_021EFF7C(u8 *p);
int func_021F0050(unsigned char *p);
int func_021F0078(char *p);
int func_021F00C8(char *p);
int func_021F0114(u8 *p);
int func_021F0140(u8 *p);
void func_021F0208(u8 *p, int flag);
void func_021F028C(unsigned char *p);
void func_021F029C(char *p,int flag);
int func_021F02C4(u8 *p);
int func_021F03EC(u8 *p);
int func_021F0438(u8 *p);
int func_021F055C(u8 *p);
void func_021F05E8(u8 *p, int a, u32 b);
int func_021F0668(char *p, int i);
void func_021F067C(char *p);
void func_021F0684(u8 *p, u8 *a, u8 *b);
void func_021F06E0(u8 *p, u32 x, int y);
void func_021F079C(u8 *p,int v);
u32 func_021F07D4(u8 *p);
int func_021F0820(u32 x);
int func_021F086C(int *a, int *b);
void func_021F0884(int *a, int *b, int *c);
int func_021F089C(Vec2 *pt, Vec2 *tri);
int func_021F08E4(u8 *p, void *pt);
int func_021F096C(u8 *p, void *pt);
int func_021F0A18(u8 *p, u32 *v);
void func_021F0A98(char *p,unsigned a);
void func_021F0AC0(char *p);
void func_021F0B10(char *p, int a, int b);
void func_021F0B64(char *p);
void func_021F0B80(char *p,void *t,unsigned a);
int func_021F0BA8(u8 *p);
void func_021F0C04(char *p, int flag);
int func_021F0C70(char *p, int flag);
int func_021F0CF8(char *p, int i);
void func_021F0D38(char *p);
int func_021F0D5C(char *p, int i);
void func_021F0D9C(char *p);
int func_021F0DC0(void *p);
void func_021F0DD8(unsigned int a);
void func_021F0DE0(void *p, short x, short y);
void func_021F0DF4(void *p, unsigned short v);
void func_021F0E04(char *p, unsigned a);
void func_021F0E24(char *p);
void func_021F0E7C(char *p);
void func_021F0EA4(char *p,unsigned a);
void func_021F0ED0(char *p, int a);
void func_021F0EDC(char *p);
void func_021F0F30(char *p, int a, int b);
u8 *func_021F0F44(u8 *p, int a);
void func_021F0F74(char *p, u8 *q, void *r);
void func_021F0FC8(char *p, u8 *q, int r);
int func_021F0FE8(S_021EFEC0 *p);
void func_021F1004(char *p, u8 *q, int r);
void func_021F1070(char *p, char *q, void *text, int a4);
void func_021F1080(char *p, char *q, int r, int t);
void func_021F10D8(char *this, u8 *p, int a);
void func_021F1144(u8 *p, u8 *q, void *r, int mode, int skip, int t);
void func_021F1218(char *p, short x, short y);
void func_021F1268(char *this);
void func_021F12B8(u8 *this, int dir);
void func_021F1340(char *this, int a, u8 b);
void func_021F13A0(char *this, int a, int b, int c, int s);
void func_021F1418(void *h, u8 *t);
void func_021F1484(char *this, int a, u8 *b, u8 *c, void *s);
void func_021F150C(u8 *this, u8 *p, void *s);
void func_021F155C(char *p, u8 *e, int mode, u8 delay, int *r);
void func_021F1704(void *h, char *t);
void func_021F178C(char *this, u8 a, int *p);
void func_021F17D8(void *task, u8 *q);
int func_021F180C(char *this, int x, int flag);
void func_021F1888(char *p, Rec_021EFEC0 *r);
void func_021F18C4(char *p, int b);
void func_021F18E0(char *p, u32 a, int *c);
void func_021F1930(void *task, u8 *s);
int func_021F199C(char *p, void *x, int flag);
void func_021F1A08(char *p);
void func_021F1A18(char *p, int b);
void func_021F1A28(char *p, int b, u8 c, int *r);
void func_021F1B94(void *h, u8 *t);
void func_021F1CF0(void *h, u8 *t);
void func_021F1E40(char *p, char *q, void *x, int flag);
void func_021F1EAC(void *task, u8 *s);
void func_021F1F00(char *p, int a);
void func_021F1F34(char *p, u8 *q, int *r);
void func_021F1F9C(void *task, u8 *s);
void func_021F201C(char *p, char *q, void *text, u16 x, u8 y, u8 a5, u16 col, u32 a7);
void func_021F20A8(char *p, char *q, int *r);
void func_021F20E4(void *task, char *q);
void func_021F2144(char *p, char *q, void *text, u16 col, u32 a4);
void func_021F21B0(char *p, char *q, int *r);
void func_021F21F8(void *task, char *q);
char *func_021F2234(u32 a0, u32 a1);
void func_021F22FC(char *p);
void func_021F2344(char *p, int a1);
u32 func_021F23F8(char *p);
void *func_021F2404(char *p, int go);
void func_021F253C(char *p, int v);
void func_021F2544(char *p);
Desc *func_021F254C(char *p, unsigned a, unsigned b, unsigned c);
int func_021F2588(int a0, int a1, int *st);
int func_021F25D4(u8 *p, int *st);
int func_021F2608(char *p, int *unused);
int func_021F2624(int a0, int *st);
void func_021F2664(int a, char *p);
int func_021F2674(char *p);
int func_021F26D8(u8 *p);
int func_021F26F0(u8 *p);
int func_021F2714(char *p);
int func_021F27B4(u8 *p);
int func_021F27CC(char *p);
void func_021F27D4(u8 *p);
void func_021F28DC(char *p);
void func_021F2908(char *p);
void func_021F2A04(char *p);
void func_021F2A8C(u8 *p, void *h);
void func_021F2BD4(char *p);
void func_021F2C1C(char *p);
void func_021F2CC4(char *p);
void func_021F2D20(Work_021F2A8C *p, void *h);
void func_021F2EDC(char *p);
void func_021F2F44(char *p, void *a);
void func_021F2FCC(char *p);
void func_021F3010(T_021F254C *p, unsigned a, unsigned b, unsigned c, unsigned char d, unsigned char e, unsigned char f);
void func_021F3058(char *p);
void func_021F30B4(char *p);
void func_021F30D4(char *this, ResList *out, const ResSpec *spec, void *arc);
void func_021F31A8(void *unused, T_021F31A8 *p);
void *func_021F3214(char *p, unsigned a, unsigned b, unsigned c, short x, short y, unsigned char w, unsigned char h, unsigned char z);
void func_021F3264(S_021F254C *p);
void func_021F32D4(char *p);
void func_021F32F8(char *p, u8 idx);
extern u32 d_021F3554[];
extern Vec2 d_021F356C[2][5];
extern u8 d_021F3538[][3];
extern u16 d_021F3530[];
extern u8 d_021F3541[];
extern u8 d_021F352C[];
extern char d_021F36A0[];
extern u8 ov083_id[];
extern const u8 d_021F3608[];
extern const u8 d_021F3628[];
extern const u8 d_021F3648[];
extern const u8 d_021F3668[];
extern const ResSpec3 d_021F35BC;
extern const ResSpec3 d_021F35C8;
extern const ResSpec3 d_021F35D4;
extern T16 d_021F35E0;
extern Pt d_021F35F0[];














void func_021EFEC0(u8 *o)
{
    int i;
    u8 *q;
    u8 *e;
    int s;
    int t;

    func_02021EE4((struct Obj02021EE4 *)(*(int *)&((struct Obj00007 *)o)->fAC), 1);
    func_021F0AC0((char *)o);
    func_021F0B10((char *)o, 1, 0);
    for (i = 0; i < o[0x7D]; i++) {
        q = o + 0x48;
        t = o[0x7C];
        func_02165AC4((struct Queue *)(((struct Obj00007 *)o)->f3C), (struct Rec_021EFEC0 *)(((struct Obj00007 *)o)->f40), (u16 *)q, t + i);
        s = func_021659F0((u8 *)(((struct Obj00007 *)o)->f3C), t + i);
        e = func_021F0F44(o, 0xFF);
        func_021F0F30((char *)e, (u8)s, (u8)(i + 1));
        func_021F1144(o, e, (void *)(((struct Obj00007 *)o)->f40), 2, 0, 0);
        func_021F0EA4((char *)e, (int)1);
    }
    func_021F0E24((char *)o);
    func_021F0E7C((char *)o);
    if (((struct Obj00007 *)o)->f28 == 0x30)
        func_021F0DF4((void *)(*(int *)&((struct Obj00007 *)o)->f2BC), 3);
    func_0203D34C(0, ((struct Obj00007 *)o)->f96);
}














int func_021EFF7C(u8 *p)
{
    Pair_021EFEC0 v;
    int r;
    int s;

    if (func_02035D20(&v.x, &v.y) == 0)
        return 0;
    r = func_021F0A18(p, (u32 *)(&v));
    if (r != -1) {
        switch (r) {
        case 0:
            return 4;
        case 1:
            func_021F253C((char *)p, 8);
            break;
        case 2:
            return 5;
        case 3:
            func_021F253C((char *)p, 1);
            break;
        }
        return 0;
    }
    r = func_021F08E4(p, &v);
    if (r != -1) {
        func_02165AC4((struct Queue *)(((struct Obj00188 *)p)->f3C), (struct Rec_021EFEC0 *)(((struct Obj00188 *)p)->f40), (u16 *)(p + 0x48), p[0x7C] + r);
        if (func_02165C10((u8 *)(((struct Obj00188 *)p)->f40)) != 0)
            return 0;
        p[0x7E] = r;
        func_021F1F00((char *)p, (u8)r);
        func_021F253C((char *)p, 4);
        return 0;
    }
    s = func_021F096C(p, &v);
    if (s != -1) {
        func_021F1340((char *)p, s, (int)0);
        return 3;
    }
    return 0;
}













int func_021F0050(unsigned char *p) { u32 pt[2]; if(func_02035CB8(pt,pt+1)) return func_021F096C(p,pt); return -1; }














int func_021F0078(char *p)
{
    int r;

    r = func_021585E0(((struct Obj09794 *)p)->f1C);
    if (func_02012204((const struct Ctx *)(((struct Obj09794 *)p)->f0)) != 0) {
        func_021F253C(p, 1);
        return 1;
    }
    if (r == 2) {
        func_021F253C(p, 2);
        return 1;
    }
    if (func_0201058C((void *)(((struct Obj09794 *)p)->f20)) & 8) {
        func_021F253C(p, 3);
        return 1;
    }
    return 0;
}














int func_021F00C8(char *p)
{
    u16 *f;

    f = func_020275D0((char *)(*(int *)(p + 0x34)));
    if (*f == 0)
        return 0;
    *f = 0;
    func_0201EE0C(*(void **)(p + 0x110), 0, (void *)func_020275C4((void *)(*(int *)(p + 0x34))),
                  *(u8 *)(p + 0x30), 1, 2);
    func_021F18C4(p, 0xB);
    return 1;
}













int func_021F0114(u8 *p) { unsigned n; n=func_021F07D4(p); if(n==0x30) return 0; if(n==sub_02010EA0(n,*(u8 * *)&((struct Obj05120 *)p)->f24)) return 0; func_021F1A18((char *)p,n); return 1; }














int func_021F0140(u8 *p)
{
    u8 t;

    if (func_021658D4((struct Queue *)(((struct Obj00188 *)p)->f38), (struct Rec_021EFEC0 *)(((struct Obj00188 *)p)->f4C), (u16 *)(p + 0x4A)) == 0) {
        func_021F1268((char *)p);
        return 0;
    }
    if (func_02165B5C((struct Rec_021EFEC0 *)(((struct Obj00188 *)p)->f4C)) != 0)
        return 0;
    p[0x54] = func_02165A10((struct Queue *)(((struct Obj00188 *)p)->f3C), (struct Rec_021EFEC0 *)(((struct Obj00188 *)p)->f4C), ((struct Obj00188 *)p)->f4A, (int *)(p + 0x5C));
    p[0x55] = func_021659F0((u8 *)(((struct Obj00188 *)p)->f3C), p[0x54]);
    if (((struct Obj00188 *)p)->f5C == 0) {
        *(u8 * *)&((struct Obj00188 *)p)->f50 = func_021F0F44(p, p[0x55]);
    } else {
        *(u8 * *)&((struct Obj00188 *)p)->f50 = 0;
        ((struct Obj00188 *)p)->f2D4 = func_0200C1E0((struct Blk34 *)(((struct Obj00188 *)p)->f14));
    }
    if (*(u8 * *)&((struct Obj00188 *)p)->f50 != 0 && ((struct Obj20414 *)(*(u8 * *)&((struct Obj00188 *)p)->f50))->f2C != 0)
        ((struct Obj00188 *)p)->f6C = 0;
    else
        ((struct Obj00188 *)p)->f6C = 1;
    t = p[0x7B];
    p[0x57] = t;
    if (t < 0x1E) {
        p[0x7B] += (u8)((struct Obj00188 *)p)->f5C;
        if (p[0x7B] <= 4)
            p[0x7D] = p[0x7B];
    }
    return 1;
}














void func_021F0208(u8 *p, int flag)
{
    if (flag) {
        func_02021FD8((struct Chan02021FD8 *)(((struct Obj00007 *)p)->fAC), 1, 0, 0xe0, 6, 0);
        func_02021FD8((struct Chan02021FD8 *)(((struct Obj00007 *)p)->fAC), 3, 0, 0xe0, 6, 0);
        func_021D3294(((struct Obj00007 *)p)->f10, 5, 0x1e, 0xa, 6);
    } else {
        func_02021FD8((struct Chan02021FD8 *)(((struct Obj00007 *)p)->fAC), 1, 0, 0xe0, 0, 0);
        func_02021FD8((struct Chan02021FD8 *)(((struct Obj00007 *)p)->fAC), 3, 0, 0xe0, 0, 0);
        func_021D3294(((struct Obj00007 *)p)->f10, 4, 0x1e, 0xd, 3);
    }
}













void func_021F028C(unsigned char *p) { func_021F12B8(p, ((struct Obj20415 *)p)->f84); }













void func_021F029C(char *p,int flag) { if(flag) func_0201C4DC((struct PrintSys *)(((struct Obj00007 *)p)->fB4),2000,0); else func_0201C4DC((struct PrintSys *)(((struct Obj00007 *)p)->fB4),500,0); }














int func_021F02C4(u8 *p)
{
    int r;

    switch (((struct Obj00007 *)p)->f6C) {
    case 0:
        if (((struct Obj20416 *)(*(u8 * *)&((struct Obj00007 *)p)->f50))->f2C != 0)
            break;
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 1:
        r = func_021F180C((char *)p, ((struct Obj00007 *)p)->f4C, ((struct Obj00007 *)p)->f5C);
        if (((struct Obj00007 *)p)->f5C == 0) {
            if (r != 0) {
                func_021F05E8(p, 4, 2);
                func_021F0DD8(0x549);
            }
            if (*(u8 * *)&((struct Obj00007 *)p)->f50 != 0) {
                func_021F1144(p, *(u8 * *)&((struct Obj00007 *)p)->f50, (void *)(((struct Obj00007 *)p)->f4C), 0, r == 0, 0);
                func_021F0EA4((char *)(*(u8 * *)&((struct Obj00007 *)p)->f50), 1);
            }
            return 1;
        }
        func_021F05E8(p, 4, 2);
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 2:
        func_021F0AC0((char *)p);
        func_021F0B10((char *)p, 1, (int)(p + 0xA8));
        func_021F06E0(p, ((struct Obj00007 *)p)->f4C, p[0x57]);
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 3:
        if (p[0x7C] != 0) {
            p[0x54] = p[0x7C];
            func_02165AC4((struct Queue *)(((struct Obj00007 *)p)->f3C), (struct Rec_021EFEC0 *)(((struct Obj00007 *)p)->f4C), (u16 *)(p + 0x4A), p[0x54]);
            p[0x55] = func_021659F0((u8 *)(((struct Obj00007 *)p)->f3C), p[0x54]);
        }
        func_021F13A0((char *)p, ((struct Obj00007 *)p)->f4C, p[0x55], 1, (p[0x7C] != 0 ? 1 : 0) + 1);
        p[0x7C] = p[0x54];
        func_021F0DD8(0x64A);
        return 1;
    }
    return 0;
}














int func_021F03EC(u8 *p)
{
    int s = ((struct Obj00007 *)p)->f6C;

    switch (s) {
    case 0:
        func_021F05E8(p, 0, 1);
        func_021F029C((char *)p, 1);
        func_021F1A08((char *)p);
        ((struct Obj00007 *)p)->f6C = ((struct Obj00007 *)p)->f6C + 1;
        break;
    case 1:
        if (((struct Obj00007 *)p)->fA8 == 0) {
            func_021F029C((char *)p, 0);
            ((struct Obj00007 *)p)->f6C = 0;
            return 1;
        }
        break;
    }
    return 0;
}














int func_021F0438(u8 *p)
{
    u8 *e;
    u8 s;

    if (((struct Obj00007 *)p)->fA8 != 0)
        return 5;
    switch (((struct Obj00007 *)p)->f6C) {
    case 0:
        func_021F05E8(p, 2, 1);
        func_021F0B10((char *)p, 2, (int)(p + 0xA8));
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 1:
        if (func_021F0668((char *)p, 2) != 0)
            break;
        func_021F05E8(p, 0, 2);
        func_021F05E8(p, 1, 2);
        func_021F05E8(p, 3, 2);
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 2:
        ((struct Obj00007 *)p)->f6C = func_021F055C(p);
        if (((struct Obj00007 *)p)->f6C == 3)
            return 3;
        break;
    case 4:
        s = func_021659F0((u8 *)(((struct Obj00007 *)p)->f3C), p[0x7E] + p[0x7C]);
        e = func_021F0F44(p, s);
        func_0201EE0C(((struct Obj00007 *)p)->f110, 0, ((struct Obj09795 *)e)->f24, e[4], 1, 2);
        func_021F029C((char *)p, 1);
        func_021F18C4((char *)p, 3);
        func_021657E8((void *)(*(int *)&((struct Obj00007 *)p)->f4), ((struct Obj09795 *)e)->f6);
        ((struct Obj00007 *)p)->f6C = 5;
        break;
    case 5:
        func_021F029C((char *)p, 0);
        ((struct Obj00007 *)p)->f6C = 6;
        break;
    case 3:
        func_021F05E8(p, 2, 0);
        ((struct Obj00007 *)p)->f6C = 2;
        break;
    case 6:
        func_021F05E8(p, 4, 0);
        func_021F0B10((char *)p, 1, (int)(p + 0xA8));
        ((struct Obj00007 *)p)->f6C = 7;
        break;
    case 7:
        ((struct Obj00007 *)p)->f6C = 0;
        return 0;
    }
    return 5;
}














int func_021F055C(u8 *p)
{
    Pair_021EFEC0 v;
    int r;
    int s;

    if (func_02012204((const struct Ctx *)(((struct Obj00188 *)p)->f0)) != 0) {
        func_021F253C((char *)p, 1);
        return 6;
    }
    if (func_02035D20(&v.x, &v.y) == 0)
        return 2;
    if (func_021F0A18(p, (u32 *)(&v)) == 2)
        return 6;
    r = func_021F08E4(p, &v);
    if (r != -1) {
        p[0x7e] = r;
        func_021F1F00((char *)p, (u8)r);
        return 4;
    }
    s = func_021F096C(p, &v);
    if (s != -1) {
        func_021F1340((char *)p, s, (int)5);
        return 3;
    }
    return 2;
}














void func_021F05E8(u8 *p, int a, u32 b)
{
    u8 m;

    if (a == 4)
        m = 0xf;
    else
        m = 1 << a;
    if ((1 & m) && ((struct Obj00007 *)p)->f28 != 0x30)
        func_021F0DF4((void *)(*(u32 *)&((struct Obj00007 *)p)->f2BC), (u8)(b + 1));
    if (2 & m)
        func_021F0DF4((void *)(((struct Obj00007 *)p)->f2C0), (u8)(b + 4));
    if ((4 & m) && p[0x7b] != 0)
        func_021F0DF4((void *)(*(u32 *)&((struct Obj00007 *)p)->f2C4), (u8)(b + 7));
    if (8 & m)
        func_021F0DF4((void *)(((struct Obj00007 *)p)->f2C8), (u8)(b + 10));
}













int func_021F0668(char *p, int i) { return func_0204B98C(*(struct Actor **)(p + i * 4 + 0x2bc)); }














void func_021F067C(char *p)
{
    func_021F0E24(p);
}














void func_021F0684(u8 *p, u8 *a, u8 *b)
{
    int i = 0;
    u16 tag;

    *a = 0;
    *b = 0;
    for (; i < p[0x7b]; i++) {
        func_02165AC4((struct Queue *)(((struct Obj04310 *)p)->f3C), (struct Rec_021EFEC0 *)(((struct Obj04310 *)p)->f44), &tag, i);
        if (p[0x30] != func_02165D08((struct Rec_021EFEC0 *)(((struct Obj04310 *)p)->f44)))
            (*a)++;
        if (p[0x32] != func_02165C48(((struct Obj04310 *)p)->f44))
            (*b)++;
    }
}














void func_021F06E0(u8 *p, u32 x, int y)
{
    u8 v[2];

    v[1] = 0;
    v[0] = 0;
    func_021F0684(p, &v[0], &v[1]);
    if (func_02165C50(x) != 2)
        func_021F079C(p, 1);
    if (p[0x59] != v[1] && v[1] == 0x14)
        func_021F079C(p, 2);
    if (((struct Obj00007 *)p)->f2D4 % 100 == 0)
        func_021F079C(p, 3);
    if (y == 0x1d && p[0x7b] == 0x1e)
        func_021F079C(p, 4);
    if (p[0x58] != v[0] && v[0] == 0x14)
        func_021F079C(p, 5);
    if (func_021F0820(((struct Obj00007 *)p)->f2D4) != 0)
        func_021F079C(p, 6);
    p[0x58] = v[0];
    p[0x59] = v[1];
}













/*
 * volatile: count byte at +0x8c re-read at 021F07A2 and 021F07BE.
 */
void func_021F079C(u8 *p,int v) { int n,i; n=*(volatile u8 *)&((struct Obj07629 *)p)->f8C; for(i=0;i<n;i++) if(v==p[i+0x8d]) return; *(volatile u8 *)&((struct Obj07629 *)p)->f8C=*(volatile u8 *)&((struct Obj07629 *)p)->f8C+1; (p+n)[0x8d]=v; }














u32 func_021F07D4(u8 *p)
{
    u32 n = p[0x8d];

    if (n == 0)
        return 0x30;
    p[0x8c] = p[0x8c] - 1;
    MI_CpuCopy8(p + 0x8e, p + 0x8d, p[0x8c]);
    (p + p[0x8c])[0x8d] = 0;
    return d_021F3554[n - 1];
}














int func_021F0820(u32 x)
{
    u32 d;

    if (x / 100 == 0)
        return 0;
    d = x % 10;
    x = x / 10;
    do {
        if ((u8)(x % 10) != d)
            return 0;
        x = x / 10;
    } while (x != 0);
    return 1;
}













int func_021F086C(int *a, int *b) { return a[0]*b[1] - a[1]*b[0]; }













void func_021F0884(int *a, int *b, int *c) { c[0]=a[0]-b[0]; c[1]=a[1]-b[1]; }












int func_021F089C(Vec2 *pt, Vec2 *tri)
{
    int i;
    Vec2 a;
    Vec2 b;

    for (i = 0; i < 3; i++) {
        func_021F0884((int *)pt, (int *)(&tri[i]), (int *)(&a));
        func_021F0884((int *)(&tri[(i + 1) % 3]), (int *)(&tri[i]), (int *)(&b));
        if (func_021F086C((int *)(&a), (int *)(&b)) < 0)
            return 0;
    }
    return 1;
}











int func_021F08E4(u8 *p, void *pt)
{
    int i;
    int x;
    int y;
    int t[6];

    for (i = 0; i < p[0x7d]; i++) {
        x = i * 13;
        y = i * 40;
        t[0] = x;
        t[1] = y + 5;
        t[2] = x + 0xc;
        t[3] = y + 0x2b;
        t[4] = x + 0xd2;
        t[5] = y + 0x2b;
        if (func_021F089C((Vec2 *)pt, (Vec2 *)t))
            return i;
        t[0] = x;
        t[1] = y + 5;
        t[2] = x + 0xd2;
        t[3] = y + 0x2b;
        t[4] = x + 0xc6;
        t[5] = y + 5;
        if (func_021F089C((Vec2 *)pt, (Vec2 *)t))
            return i;
    }
    return -1;
}











/*
 * Tries the point against the triangles of two fixed 5-vertex fans (byte
 * index triples in d_021F3538); returns 1 - j for the fan that hits, else -1.
 * Copying the vertices as Vec2 structs gives the x-then-y load order; the
 * `k = 0` ahead of the fan pointer keeps `movs r4, #0` first.
 */
int func_021F096C(u8 *p, void *pt)
{
    int flags;
    int j;
    int k;
    Vec2 t[3];

    flags = 0;
    if (p[0x7c] != 0)
        flags |= 1;
    if (p[0x7c] + p[0x7d] < p[0x7b])
        flags |= 2;
    for (j = 0; j < 2; j++) {
        if (flags & (j + 1)) {
            Vec2 *v;
            k = 0;
            v = d_021F356C[j];
            for (; k < 3; k++) {
                t[0] = v[d_021F3538[k][0]];
                t[1] = v[d_021F3538[k][1]];
                t[2] = v[d_021F3538[k][2]];
                if (func_021F089C((Vec2 *)pt, (Vec2 *)((int *)t)))
                    return 1 - j;
            }
        }
    }
    return -1;
}











int func_021F0A18(u8 *p, u32 *v)
{
    u8 b[5];
    int i;

    b[4] = 0xff;
    for (i = 0; i < 4; i++) {
        u32 a = func_0204B898((struct Obj *)(*(u32 *)(p + 0x2bc + i * 4)));
        if ((u8)(a - (i * 3 + 1)) % 3 < 2) {
            b[0] = 0xac;
            b[1] = b[0] + 0x18;
            b[2] = i * 32 + 0x84;
            b[3] = b[2] + 0x18;
            if (func_02035D40((struct Ctx *)b, v[0], v[1]) != -1) {
                func_021F0DD8(d_021F3530[i]);
                return i;
            }
        }
    }
    return -1;
}









void func_021F0A98(char *p,unsigned a) { func_02045CAC(((struct Obj00007 *)p)->f114,a,((struct Obj00007 *)p)->f118); func_0201F250(((struct Obj00007 *)p)->f110,((struct Obj00007 *)p)->f11C,((struct Obj00007 *)p)->f118); }










void func_021F0AC0(char *p)
{
    func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00007 *)p)->f110), 0, ((struct Obj00007 *)p)->f7B, 2, 1, 1);
    func_021F0A98(p, 0);
    func_021F201C(p, p + 0x110 + 0x94, (void *)(*(int *)&((struct Obj00007 *)p)->f11C), 4, 0, 1, 0x3DC1, 0);
}










void func_021F0B10(char *p, int a, int b)
{
    func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00007 *)p)->f110), 0, *(int *)&((struct Obj00007 *)p)->f2D4, 5, 0, 1);
    func_021F0A98(p, a);
    func_021F201C(p, p + 0x110 + 0x80, (void *)(*(int *)&((struct Obj00007 *)p)->f11C), 0, 4, 0, 0x3C40, b);
}









void func_021F0B64(char *p) { func_02043B5C(((struct Obj00007 *)p)->f194,0x40); func_02045334(((struct Obj00007 *)p)->f190); }









void func_021F0B80(char *p,void *t,unsigned a) { func_021F201C(p,p+0x17c,t,0,0,9,0x449,a); }









int func_021F0BA8(u8 *p)
{
    u32 x;
    u32 y;
    u16 v = 0xFFFE;
    u8 c = p[0];

    p[0] = c - 1;
    if (c == 0) {
        p[0] = 0;
        return 1;
    }
    if (func_02035D20(&x, &y) != 0) {
        if (func_02041FF4(6, x, y + 0x40, &v) != 0) {
            p[0] = 0;
            return 1;
        }
    }
    return 0;
}









void func_021F0C04(char *p, int flag)
{
    int i;
    int n;
    int base;
    char *q;

    if (flag == 0) {
        q = p + 0xc0;
        n = 3;
        base = 8;
    } else {
        q = p + 0xf0;
        n = 2;
        base = 0x10;
    }
    for (i = 0; i < n; i++) {
        *(u32 *)(q + i * 16) = (u32)func_0202800C(((struct Obj13061 *)p)->fB8, (u32)(q + i * 16 + 4),
                                      (u8)(base + i * 8), 0x15, 8, 3, 1, 0,
                                      ((struct Obj13061 *)p)->f98);
    }
}









int func_021F0C70(char *p, int flag)
{
    int s;
    char *q;
    int n;
    int i;

    s = -1;
    if (flag == 0) {
        q = p + 0xc0;
        n = 3;
    } else {
        q = p + 0xf0;
        n = 2;
    }
    for (i = 0; i < n; i++) {
        if (func_0202846C(*(u8 **)(q + i * 16)) == 1) {
            func_02028178((u8 *)(*(u32 *)(q + i * 16)));
            return -1;
        }
    }
    for (i = 0; i < n; i++) {
        if (func_0202824C((void **)(*(u32 **)(q + i * 16))) != 0) {
            if (i < n - 1) {
                func_021F0DD8(0x54c);
                s = i;
            } else {
                func_0202822C(*(char **)(q + i * 16), 1);
                func_021F0DD8(0x54c);
                s = i;
            }
        }
        func_02028178((u8 *)(*(u32 *)(q + i * 16)));
    }
    return s;
}









int func_021F0CF8(char *p, int i)
{
    char *q;
    int j;

    q = p + 0xc0;
    func_02028178((u8 *)(*(u32 *)(q + i * 16)));
    if (func_02028230(*(u8 **)(q + i * 16)) != 0) {
        for (j = 0; j < 3; j++) {
            func_02028148((u8 *)(*(u32 *)(p + j * 16 + 0xc0)));
            *(u32 *)(p + j * 16 + 0xc0) = 0;
        }
        return 1;
    }
    return 0;
}








void func_021F0D38(char *p) { int i; for(i=0;i<3;i++) { func_02028148(*(unsigned char **)(p+i*16+0xc0)); *(unsigned *)(p+i*16+0xc0)=0; } }









int func_021F0D5C(char *p, int i)
{
    char *q;
    int j;

    q = p + 0xf0;
    func_02028178((u8 *)(*(u32 *)(q + i * 16)));
    if (func_02028230(*(u8 **)(q + i * 16)) != 0) {
        for (j = 0; j < 2; j++) {
            func_02028148((u8 *)(*(u32 *)(p + j * 16 + 0xf0)));
            *(u32 *)(p + j * 16 + 0xf0) = 0;
        }
        return 1;
    }
    return 0;
}








void func_021F0D9C(char *p) { int i; for(i=0;i<2;i++) { func_02028148(*(unsigned char **)(p+i*16+0xf0)); *(unsigned *)(p+i*16+0xf0)=0; } }








int func_021F0DC0(void *p) { int a; a=func_02165E24((int)p); if(a==0 || a>=0x33) return 0x12; return a+0x11; }









void func_021F0DD8(unsigned int a)
{
    func_020061E4(a);
}








void func_021F0DE0(void *p, short x, short y) { Pair_021F0BA8 d; d.x=x; d.y=y; func_0204B404(p,(const struct Vec2 *)(&d),0); }








void func_021F0DF4(void *p, unsigned short v) { func_0204B878(p,v); func_0204B9A0(p); }








void func_021F0E04(char *p, unsigned a) { int i; for(i=0;i<=3;i++) func_0204B3DC(*(void **)(p+i*4+0x2bc),a); }









void func_021F0E24(char *p)
{
    if (((struct Obj00007 *)p)->f7C == 0) {
        func_0204B878((struct Obj *)(((struct Obj00007 *)p)->f2CC), 0x10);
    } else {
        func_0204B878((struct Obj *)(((struct Obj00007 *)p)->f2CC), 0xd);
    }
    if (((struct Obj00007 *)p)->f7C + ((struct Obj00007 *)p)->f7D < ((struct Obj00007 *)p)->f7B) {
        func_0204B878((struct Obj *)(((struct Obj00007 *)p)->f2D0), 0x11);
        return;
    }
    func_0204B878((struct Obj *)(((struct Obj00007 *)p)->f2D0), 0x14);
}








void func_021F0E7C(char *p) { if(((struct Obj00007 *)p)->f7B==0) func_0204B878(((struct Obj00007 *)p)->f2C4,9); else func_0204B878(((struct Obj00007 *)p)->f2C4,7); }








void func_021F0EA4(char *p,unsigned a) { func_02025774(*(unsigned char * *)&((struct Obj00225 *)p)->f18,a); func_0204B3DC(((struct Obj00225 *)p)->f10,a); func_0204B3DC(((struct Obj00225 *)p)->fC,a); if(a==0) func_021F0ED0(p,a); }









void func_021F0ED0(char *p, int a)
{
    func_0204B3DC(((struct Obj20418 *)p)->f14, a);
}








void func_021F0EDC(char *p)
{
    int z = 0;

    func_021F0EA4(p, 0);
    func_021F0ED0(p, 0);
    func_02043B5C((struct CharBuf *)(((struct Obj00225 *)p)->f1C), 0);
    func_020257D0((struct Obj *)(*(int *)&((struct Obj00225 *)p)->f18));
    func_0204581C((struct U16Vec *)(*(int *)&((struct Obj00225 *)p)->f24));
    func_0204581C((struct U16Vec *)(*(int *)&((struct Obj00225 *)p)->f20));
    ((struct Obj00225 *)p)->f1 = 0xff;
    ((struct Obj00225 *)p)->f2 = z;
    ((struct Obj00225 *)p)->f3 = z;
    if (((struct Obj00225 *)p)->f2C != 0) {
        func_02031194((struct TcblNode *)(((struct Obj00225 *)p)->f2C));
        ((struct Obj00225 *)p)->f2C = z;
    }
    if (*(int *)&((struct Obj00225 *)p)->f30 != 0) {
        func_02031194((struct TcblNode *)(*(int *)&((struct Obj00225 *)p)->f30));
        *(int *)&((struct Obj00225 *)p)->f30 = 0;
    }
}







void func_021F0F30(char *p, int a, int b) { func_021F0EDC(p); p[1]=a; p[2]=b; }







u8 *func_021F0F44(u8 *p, int a)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (a == p[i * 0x34 + 0x1b9])
            return p + 0x1b8 + i * 0x34;
    }
    return 0;
}








void func_021F0F74(char *p, u8 *q, void *r)
{
    int x;

    x = func_02165CE8((struct S_021EFEC0 *)r);
    func_0204A9D0(*(int *)(((struct Obj00007 *)p)->f158 + q[0] * 4), (struct Sub0204A9D0 *)(*(int *)(p + x * 8 + 0x338)));
    func_020215BC((struct PalAnmSlot *)(*(int *)&((struct Obj00007 *)p)->fAC),
                  (const void *)(*(int *)&((struct Obj00007 *)p)->f3BC + ((d_021F3541[x] & 0xf) << 5)), 3,
                  (u16)((q[0] + 9) << 4), 0x20);
}






void func_021F0FC8(char *p, u8 *q, int r)
{
    func_0204A9D0((*(int **)(p + 0x170))[q[0]], (struct Sub0204A9D0 *)(*(int *)(p + r * 8 + 0x2d8)));
}






int func_021F0FE8(S_021EFEC0 *p)
{
    switch (func_02165C48((u32)p)) {
    case 21: return 0;
    case 20: return 1;
    default: return 2;
    }
}






void func_021F1004(char *p, u8 *q, int r)
{
    u16 a[5];
    int x;
    int b;
    u16 *t;

    x = func_021F0FE8((S_021EFEC0 *)r);
    b = x * 16;
    t = *(u16 * *)&((struct Obj00007 *)p)->f3C8;
    a[0] = t[b];
    a[1] = t[b + 1];
    a[2] = t[b + 2];
    func_02165CC0((int)(&a[3]), r);
    func_02021F64(&a[3], &a[4], 1, 3, 0);
    func_020215BC((struct PalAnmSlot *)(*(int *)&((struct Obj00007 *)p)->fAC), a, 3, (u16)((q[0] + 4) * 16 + 1), 10);
}





void func_021F1070(char *p, char *q, void *text, int a4)
{
    func_021F2144(p, q, text, 0x3c60, a4);
}














void func_021F1080(char *p, char *q, int r, int t)
{
    u8 c;

    c = (func_02026D48(((struct Obj00225 *)q)->f6) >= 0x2a30) ? 1 : 0;
    if (c == ((struct Obj00225 *)q)->f5 && r == 0) {
        return;
    }
    ((struct Obj00225 *)q)->f5 = c;
    if (c != 0) {
        func_021F2144(p, q, (void *)(*(int *)&((struct Obj00225 *)q)->f24), 0xca0, t);
    } else {
        func_021F2144(p, q, (void *)(*(int *)&((struct Obj00225 *)q)->f24), 0x3c60, t);
    }
}














void func_021F10D8(char *this, u8 *p, int a)
{
    u8 v;
    int k;

    p[3] = func_02165CB4(a);
    v = p[3];
    if (v == 0) {
        k = 0x30;
        v = 5;
    } else {
        k = 0x35;
    }
    func_020215BC((struct PalAnmSlot *)(*(int *)&((struct Obj00007 *)this)->fAC), *(u16 * *)&((struct Obj00007 *)this)->f3C8 + 0x30, (int)3, (u16)((p[0] + 4) * 16 + 8), 10);
    func_020215BC((struct PalAnmSlot *)(*(int *)&((struct Obj00007 *)this)->fAC), *(u16 * *)&((struct Obj00007 *)this)->f3C8 + k, (int)3, (u16)((p[0] + 4) * 16 + 8), v * 2);
}














void func_021F1144(u8 *p, u8 *q, void *r, int mode, int skip, int t)
{
    ((struct Obj00225 *)q)->f6 = func_02165CE4(r);
    q[4] = func_02165D08(r);
    func_02165C34(r, ((struct Obj00225 *)q)->f24);
    func_0204581C(((struct Obj00225 *)q)->f20);
    func_02165D50(r, ((struct Obj00225 *)q)->f20);
    func_021F10D8((char *)p, q, (int)r);
    func_021F0F74((char *)p, q, r);
    func_021F1004((char *)p, q, (int)r);
    if (skip != 0)
        return;
    switch (mode) {
    case 0:
        switch (func_02165E24((int)r)) {
        case 0x18:
            func_02165D6C((int)r, (int)(((struct Obj00007 *)p)->f118));
            func_021F1070((char *)p, (char *)q, ((struct Obj00007 *)p)->f118, t);
            break;
        case 0x31:
            func_02165D8C((int)r, (int)(((struct Obj00007 *)p)->f118));
            func_021F1070((char *)p, (char *)q, ((struct Obj00007 *)p)->f118, t);
            break;
        }
        func_021F1E40((char *)p, (char *)q, r, 0);
        break;
    case 1:
        func_021F1070((char *)p, (char *)q, ((struct Obj00225 *)q)->f20, t);
        func_021F1E40((char *)p, (char *)q, r, 1);
        break;
    case 2:
        func_021F1080((char *)p, (char *)q, 1, t);
        break;
    }
}














void func_021F1218(char *p, short x, short y)
{
    ((struct Obj00225 *)p)->f8 = x;
    ((struct Obj00225 *)p)->fA = y;
    func_021F0DE0(((struct Obj00225 *)p)->fC, x, y);
    func_021F0DE0(((struct Obj00225 *)p)->f10, x + 0x20, y + 0x18);
    func_021F0DE0(((struct Obj00225 *)p)->f14, x + 0x3c, y + 0x18);
    func_0202590C(((struct Obj00225 *)p)->f18, x + 0x48, y + 0x10);
}














void func_021F1268(char *this)
{
    int i;
    char *e;

    for (i = 0; i < ((struct Obj09797 *)this)->f7D; i++) {
        e = (char *)func_021F0F44((u8 *)this, (u8)func_021659F0(*(u8 * *)&((struct Obj09797 *)this)->f3C, ((struct Obj09797 *)this)->f7C + i));
        if (((struct Obj13063 *)e)->f30 == 0 || ((struct Obj13063 *)e)->f2C != 0)
            func_021F1080(this, e, 0, 0);
    }
}














/*
 * Byte-correct; the only wildcard is the bl to func_020275B8 (blocker: no
 * witness outside the range for an unlabelled arm9 leaf, Ilias's). Verified
 * leaf C (EXACT, arm9 0x020275B8, thumb, 12 bytes incl. pool word 0x0B0E):
 *   typedef unsigned char u8;
 *   void func_020275B8(char *p, u8 v) { p[0xb0e] = v; }
 * The this+0x7c/0x7d reads are volatile: the original re-reads them.
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/func_020275A8,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 */
void func_021F12B8(u8 *this, int dir)
{
    u8 t;
    int n;
    u8 idx;

    func_021F0DD8(0x54b);
    if (dir == 0) {
        t = *(volatile u8 *)(this + 0x7c) + *(volatile u8 *)(this + 0x7d);
        n = *(volatile u8 *)(this + 0x7c) + 1;
    } else {
        t = *(volatile u8 *)(this + 0x7c) - 1;
        n = *(volatile u8 *)(this + 0x7c) - 1;
    }
    *(volatile u8 *)(this + 0x7c) = n;
    func_020275B8(*(void **)(this + 0x34), *(volatile u8 *)(this + 0x7c));
    func_02165AC4(*(void **)(this + 0x3c), *(void **)(this + 0x40), (u16 *)(this + 0x48), t);
    idx = func_021659F0(*(void **)(this + 0x3c), t);
    func_021F13A0((char *)this, (int)(*(void **)(this + 0x40)), idx, (u8)dir, 2);
}














void func_021F1340(char *this, int a, u8 b)
{
    this[0x81] = 1;
    this[0x82] = 0;
    ((struct Obj00188 *)this)->f84 = a;
    this[0x83] = b;
    ((struct Obj00188 *)this)->f88 = 0;
    func_021F029C(this, 1);
    if (((struct Obj00188 *)this)->f84 == 0)
        func_021F0DF4((void *)(((struct Obj00188 *)this)->f2D0), 0x13);
    else
        func_021F0DF4((void *)(((struct Obj00188 *)this)->f2CC), 0xf);
    func_021F05E8((u8 *)this, 4, 2);
    func_021F12B8((u8 *)this, a);
}














void func_021F13A0(char *this, int a, int b, int c, int s)
{
    char *e;
    u8 *r;

    e = (char *)func_021F0F44((u8 *)this, 0xff);
    if (e != 0) {
        r = func_02031290(func_020311B8(*(u32 *)&((struct Obj00007 *)this)->fA0, (void *)func_021F1418, 0x18, 0));
        func_02082BCC(r, 0, 0x18);
        *(char * *)&((struct Obj06134 *)r)->fC = this;
        r[1] = c;
        *(char * *)&((struct Obj06134 *)r)->f8 = e;
        ((struct Obj06134 *)r)->f4 = s;
        *(int * *)&((struct Obj06134 *)r)->f14 = (int *)(this + 0xa8);
        ((struct Obj00007 *)this)->fA8 = ((struct Obj00007 *)this)->fA8 + 1;
        func_021F0F30(e, b, 0);
        func_021F1144((u8 *)this, (u8 *)e, (void *)a, s, 0, (int)(r + 0x10));
    }
}














void func_021F1418(void *h, u8 *t)
{
    void *this;

    this = ((struct Obj01676 *)t)->fC;
    if (((struct Obj01676 *)t)->f10 > 0)
        return;
    if (t[0] == 0) {
        func_021F0EA4(((struct Obj01676 *)t)->f8, 1);
        if (((struct Obj01676 *)t)->f4 == 1) {
            func_021F150C(this, ((struct Obj01676 *)t)->f8, t + 0x10);
            func_021F0ED0(((struct Obj01676 *)t)->f8, 1);
        } else {
            func_021F1484(this, t[1], ((struct Obj01676 *)t)->f8, 0, t + 0x10);
        }
        t[0] = t[0] + 1;
        return;
    }
    if (*(int * *)&((struct Obj01676 *)t)->f14 != 0)
        *(*(int * *)&((struct Obj01676 *)t)->f14) = *(*(int * *)&((struct Obj01676 *)t)->f14) - 1;
    func_02031194(h);
}














void func_021F1484(char *this, int a, u8 *b, u8 *c, void *s)
{
    int i;
    u8 *e;

    if (b != 0) {
        if (a == 0)
            b[2] = 5;
        else
            b[2] = 0;
        func_021F1218((char *)b, -13 * (1 - b[2]), -40 * (1 - b[2]));
        func_021F0EA4((char *)b, 1);
    }
    for (i = 0; i < 5; i++) {
        e = (u8 *)(this + 0x1b8) + i * 0x34;
        if (e[1] != 0xff) {
            if (c == 0 || e[0] != c[0])
                func_021F155C(this, e, a, 0, s);
        }
    }
}














void func_021F150C(u8 *this, u8 *p, void *s)
{
    int k;

    p[2] = 1;
    func_021F1218((char *)p, -208, 0);
    func_021F0EA4((char *)p, 1);
    k = 0;
    if (this[0x7b] != 0)
        k = 8;
    func_021F155C((char *)this, p, 2, (u8)k, s);
    func_021F1484((char *)this, 1, 0, p, s);
}














void func_021F155C(char *p, u8 *e, int mode, u8 delay, int *r)
{
    u8 *t;

    t = func_02031290(func_020311B8(*(u32 *)(p + 0xa0), (void *)func_021F1704, 0x28, 0));
    func_02082BCC(t, 0, 0x28);
    t[0xc] = mode;
    if (t[0xc] == 0) {
        e[2] = e[2] - 1;
    } else if (t[0xc] == 1) {
        e[2] = e[2] + 1;
    }
    *(char **)(t + 4) = p;
    *(u8 **)(t + 8) = e;
    *(s16_021EFEC0 *)(t + 0x10) = (1 - e[2]) * -13;
    *(s16_021EFEC0 *)(t + 0x12) = (1 - e[2]) * -40;
    *(int *)(t + 0x14) = FX32_CONST(*(s16_021EFEC0 *)(e + 8));
    *(int *)(t + 0x18) = FX32_CONST(*(s16_021EFEC0 *)(e + 0xa));
    t[0xe] = 8;
    t[0xd] = delay;
    *(int *)(t + 0x1c) = func_0207C768(FX32_CONST(*(s16_021EFEC0 *)(t + 0x10) - *(s16_021EFEC0 *)(e + 8)), FX32_CONST(t[0xe]));
    *(int *)(t + 0x20) = func_0207C768(FX32_CONST(*(s16_021EFEC0 *)(t + 0x12) - *(s16_021EFEC0 *)(e + 0xa)), FX32_CONST(t[0xe]));
    *(int **)(t + 0x24) = r;
    (*r)++;
}














void func_021F1704(void *h, char *t)
{
    u8 *e;

    switch (((struct Obj00710 *)t)->f0) {
    case 0:
        if (((struct Obj00710 *)t)->fD != 0) {
            ((struct Obj00710 *)t)->fD = ((struct Obj00710 *)t)->fD - 1;
            return;
        }
        ((struct Obj00710 *)t)->fF = ((struct Obj00710 *)t)->fF + 1;
        if (((struct Obj00710 *)t)->fF < ((struct Obj00710 *)t)->fE) {
            int x = ((struct Obj00710 *)t)->f14 + ((struct Obj00710 *)t)->f1C;
            int y = ((struct Obj00710 *)t)->f18 + ((struct Obj00710 *)t)->f20;
            ((struct Obj00710 *)t)->f14 = x;
            ((struct Obj00710 *)t)->f18 = y;
            func_021F1218((char *)(*(u8 * *)&((struct Obj00710 *)t)->f8), (short)(x >> 12), (short)(y >> 12));
            return;
        }
        func_021F1218((char *)(*(u8 * *)&((struct Obj00710 *)t)->f8), ((struct Obj00710 *)t)->f10, ((struct Obj00710 *)t)->f12);
        e = *(u8 * *)&((struct Obj00710 *)t)->f8;
        if (e[2] == 0 || e[2] == 5) {
            ((struct Obj00710 *)t)->f0 = ((struct Obj00710 *)t)->f0 + 1;
            return;
        }
        break;
    case 1:
    default:
        e = *(u8 * *)&((struct Obj00710 *)t)->f8;
        if (((struct Obj00225 *)e)->f2C != 0)
            return;
        func_021F0EDC((char *)e);
        break;
    }
    **(int * *)&((struct Obj00710 *)t)->f24 = **(int * *)&((struct Obj00710 *)t)->f24 - 1;
    func_02031194(h);
}













void func_021F178C(char *this, u8 a, int *p)
{
    u8 *r;
    int v;

    r = func_02031290(func_020311B8(((struct Obj20428 *)this)->fA0, (void *)func_021F17D8, 0xc, 0));
    func_02082BCC(r, 0, 0xc);
    r[0] = a;
    if (r[0] == 0) {
        r[3] = 0;
        v = 0x10;
    } else {
        v = 0x40;
        r[3] = v;
        v -= 0x50;
    }
    r[4] = v;
    r[1] = 4;
    *(int * *)&((struct Obj04311 *)r)->f8 = p;
    *p = *p + 1;
}












void func_021F17D8(void *task, u8 *q)
{
    u32 old;
    int x;
    old = q[2];
    q[2] = old + 1;
    if (old < q[1]) {
        x = ((struct Obj03636 *)q)->f3;
        q[3] = x + ((struct Obj03636 *)q)->f4;
        func_02040618(6, 3, ((struct Obj03636 *)q)->f3);
        return;
    }
    (**(int * *)&((struct Obj03636 *)q)->f8)--;
    func_02031194(task);
}











int func_021F180C(char *this, int x, int flag)
{
    int k;

    k = func_02165E24(x);
    if (flag != 0) {
        func_02165FCC(x, *(int *)&((struct Obj00007 *)this)->f110, ((struct Obj00007 *)this)->f96);
        func_021F18C4(this, 0x12);
        return 1;
    }
    switch (k) {
    case 1:
        return 0;
    case 0x12:
        return func_021F199C(this, (void *)x, 0);
    case 0x32:
        return func_021F199C(this, (void *)x, 1);
    case 0x18:
        func_02165374(func_0200C1C8((struct Blk34 *)(((struct Obj00007 *)this)->f14)));
        break;
    }
    func_021F1888(this, (Rec_021EFEC0 *)x);
    return 1;
}









void func_021F1888(char *p, Rec_021EFEC0 *r)
{
    func_02165FCC((int)r, (int)(((struct Obj00007 *)p)->f110), ((struct Obj00007 *)p)->f96);
    func_021F0A98(p, (u8)func_021F0DC0(r));
    func_021F18E0(p, *(u32 *)&((struct Obj00007 *)p)->f11C, (int *)(p + 0xa8));
}









void func_021F18C4(char *p, int b)
{
    func_021F0A98(p, b);
    func_021F18E0(p, *(u32 *)&((struct Obj00007 *)p)->f11C, (int *)(p + 0xa8));
}










void func_021F18E0(char *p, u32 a, int *c)
{
    u8 *r;

    r = func_02031290(func_020311B8(*(u32 *)&((struct Obj00007 *)p)->fA0, (void *)func_021F1930, 0x10, 0));
    func_02082BCC(r, 0, 0x10);
    func_02045838((struct U16Vec *)(*(u32 *)&((struct Obj00007 *)p)->f120), (struct U16Vec *)a);
    *(char * *)&((struct Obj09798 *)r)->f8 = p;
    r[1] = 0x5a;
    func_021F05E8((u8 *)p, 4, 2);
    *(int * *)&((struct Obj09798 *)r)->fC = c;
    (*c)++;
}










void func_021F1930(void *task, u8 *s)
{
    if (((struct Obj02751 *)s)->f4 != 0)
        return;
    switch (s[0]) {
    case 0:
        func_021F0B80(*(char * *)&((struct Obj02751 *)s)->f8, (void *)(((struct Obj20431 *)(*(char * *)&((struct Obj02751 *)s)->f8))->f120), (unsigned int)(s + 4));
        s[0]++;
        return;
    case 1:
        func_021F178C(*(char * *)&((struct Obj02751 *)s)->f8, 0, (int *)(s + 4));
        s[0]++;
        return;
    case 2:
        if (func_021F0BA8(s + 1) != 0) {
            func_021F178C(*(char * *)&((struct Obj02751 *)s)->f8, 1, (int *)(s + 4));
            s[0]++;
        }
        return;
    default:
        (**(int * *)&((struct Obj02751 *)s)->fC)--;
        func_02031194(task);
        return;
    }
}










int func_021F199C(char *p, void *x, int flag)
{
    int r;

    if (flag)
        r = func_02165EBC(x);
    else
        r = func_02165D20(x);
    if (r == 0x30 || r > 0x2d)
        return 0;
    if (r == sub_02010EA0(r, *(u8 * *)&((struct Obj00007 *)p)->f24))
        return 0;
    func_02165FCC((int)x, *(u32 *)&((struct Obj00007 *)p)->f110, ((struct Obj00007 *)p)->f96);
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00007 *)p)->f110), (void *)(*(u32 *)&((struct Obj00007 *)p)->f11C), (void *)(*(u32 *)&((struct Obj00007 *)p)->f118));
    func_021F1A28(p, r, 1, (int *)(p + 0xa8));
    return 1;
}









void func_021F1A08(char *p)
{
    func_021F1A28(p, ((struct Obj20433 *)p)->f28, 0, (int *)(p + 0xa8));
}









void func_021F1A18(char *p, int b)
{
    func_021F1A28(p, b, 2, (int *)(p + 0xa8));
}










/*
 * Byte-correct; the only wildcard is the bl to func_02010FA0 (blocker: no
 * witness outside the range for an unlabelled arm9 leaf, Ilias's; it sits
 * in the word run after sub_02010EA0/func_02010EEC). Verified leaf C
 * (EXACT, arm9 0x02010FA0, thumb, `one --thumb` with no --region):
 *   typedef unsigned short u16;
 *   u16 func_02010FA0(unsigned char *rec, int slot)
 *   { return *(u16 *)(rec + slot * 0xc + 2); }
 * `u8 c` and `int flag` with `flag = 0` after the p[0x7f] store are what
 * put the flag's zero store after the argument copies.
 */
void func_021F1A28(char *p, int b, u8 c, int *r)
{
    void *h;
    int flag;
    u8 *t;

    h = func_020311B8(*(u32 *)(p + 0xa0), (void *)func_021F1B94, 0x24, 0);
    t = func_02031290(h);
    func_02082BCC(t, 0, 0x24);
    p[0x7f] = 0x30;
    flag = 0;
    if (c == 0)
        flag = 1;
    p[0x80] = flag;
    *(char **)(t + 0x1c) = p;
    t[2] = 0x5a;
    *(int *)(t + 0xc) = b;
    t[3] = c;
    func_0201F184((struct WordSet *)(*(u32 *)(p + 0x110)), 1, b);
    if (t[3] == 0) {
        *(u16 *)(t + 0x12) = func_02010FA0((struct Rec02010FA0 *)(*(u32 *)(p + 0x24)), b);
        *(u16 *)(t + 0x10) = func_02007FB8((u8 *)(*(u32 *)(p + 0x18)), 0x23f, *(u16 *)(p + 0x96));
        func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x110)), 2, *(u16 *)(t + 0x12), 3, 0, 1);
        func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x110)), 3, *(u16 *)(t + 0x10), 3, 0, 1);
        if (b == sub_02010EA0(b, (u8 *)(*(u32 *)(p + 0x24)))) {
            *(u16 *)(t + 0x14) = func_02010EEC();
            if (*(u16 *)(t + 0x14) != 0) {
                *(u16 *)(t + 0x16) = *(u16 *)(t + 0x14) / 60;
                *(u16 *)(t + 0x18) = *(u16 *)(t + 0x14) % 60;
                func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x110)), 4, *(u16 *)(t + 0x16), 3, 0, 1);
                func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x110)), 5, *(u16 *)(t + 0x18), 2, 0, 1);
            }
        }
    }
    if (t[3] != 0)
        func_021F05E8((u8 *)p, 0, 2);
    func_021F05E8((u8 *)p, 1, 2);
    func_021F05E8((u8 *)p, 2, 2);
    func_021F05E8((u8 *)p, 3, 2);
    if (*(u16 *)(t + 0x14) != 0 || *(u16 *)(t + 0x10) < *(u16 *)(t + 0x12))
        func_02031288(h, (int)((void *)func_021F1CF0));
    *(int **)(t + 0x20) = r;
    (*r)++;
}










void func_021F1B94(void *h, u8 *t)
{
    char *p;
    int r;

    p = *(char * *)&((struct Obj01037 *)t)->f1C;
    if (((struct Obj01037 *)t)->f8 > 0)
        return;
    switch (t[0]) {
    case 0:
        func_021F0A98(p, d_021F352C[t[3]]);
        func_021F0B80(p, (void *)(*(u32 *)&((struct Obj00007 *)p)->f11C), (unsigned int)((int *)(t + 8)));
        t[0]++;
        break;
    case 1:
        func_021F178C(p, 0, (int *)(t + 8));
        t[0]++;
        break;
    case 2:
        func_021F029C(p, 1);
        func_021F0C04(p, 0);
        func_021F0B64(p);
        func_021F0E04(p, 0);
        t[0]++;
        break;
    case 3:
        r = func_021F0C70(p, 0);
        if (r < 0)
            break;
        t[5] = r;
        switch (t[5]) {
        case 0:
            func_021F253C(p, 6);
            t[0] = 3;
            break;
        case 1:
            p[0x7f] = ((struct Obj01037 *)t)->fC;
            func_021F253C(p, 5);
            t[0] = 4;
            break;
        case 2:
            t[0] = 5;
            break;
        }
        break;
    case 4:
        if (*(u8 *)&((struct Obj00007 *)p)->f7F != 0x30) {
            p[0x7f] = 0x30;
            t[0] = 3;
            break;
        }
        func_021F0D38(p);
        t[0] = 6;
        break;
    case 5:
        if (func_021F0CF8(p, t[5]) == 0)
            break;
        t[0]++;
        break;
    case 6:
        func_021F0B10(p, 1, (int)((int *)(t + 8)));
        func_021F0E04(p, 1);
        func_021F178C(p, 1, (int *)(t + 8));
        t[0]++;
        break;
    default:
        func_021F05E8((u8 *)p, 4, 0);
        func_021F029C(p, 0);
        (**(int * *)&((struct Obj01037 *)t)->f20)--;
        func_02031194(h);
        break;
    }
}









void func_021F1CF0(void *h, u8 *t)
{
    char *p;
    int r;

    p = *(char * *)&((struct Obj00879 *)t)->f1C;
    if (((struct Obj00879 *)t)->f8 > 0)
        return;
    switch (t[0]) {
    case 0:
        if (((struct Obj00879 *)t)->f14 != 0)
            func_021F0A98(p, (u8)((((struct Obj00879 *)t)->f16 != 0 ? 1 : 0) + 9));
        else if (((struct Obj00879 *)t)->f10 < ((struct Obj00879 *)t)->f12)
            func_021F0A98(p, (u8)8);
        func_021F0B80(p, (void *)(*(u32 *)&((struct Obj00007 *)p)->f11C), (unsigned int)((int *)(t + 8)));
        t[0]++;
        break;
    case 1:
        func_021F178C(p, 0, (int *)(t + 8));
        t[0]++;
        break;
    case 2:
        func_021F0E04(p, 0);
        t[0]++;
        break;
    case 3:
        func_021F0C04(p, 1);
        func_021F0B64(p);
        t[0]++;
        break;
    case 4:
        r = func_021F0C70(p, 1);
        if (r < 0)
            break;
        t[5] = r;
        if (t[5] == 0) {
            func_021F253C(p, 7);
            p[0x79] = 1;
            t[0] = 5;
        } else {
            t[0] = 6;
        }
        break;
    case 5:
        if (((struct Obj00007 *)p)->f79 != 0) {
            t[0] = 4;
            break;
        }
        func_021F0D9C(p);
        t[0] = 7;
        break;
    case 6:
        if (func_021F0D5C(p, t[5]) == 0)
            break;
        t[0]++;
        break;
    case 7:
        func_021F0B10(p, 1, (int)((int *)(t + 8)));
        func_021F0E04(p, 1);
        func_021F178C(p, 1, (int *)(t + 8));
        t[0]++;
        break;
    default:
        func_021F05E8((u8 *)p, 4, (int)0);
        (**(int * *)&((struct Obj00879 *)t)->f20)--;
        func_02031194(h);
        break;
    }
}









void func_021F1E40(char *p, char *q, void *x, int flag)
{
    void *t;
    u8 *r;

    t = func_020311B8(((struct Obj20436 *)p)->fA0, (void *)func_021F1EAC, 0x18, 0);
    r = func_02031290(t);
    func_02082BCC(r, 0, 0x18);
    *(char * *)&((struct Obj05121 *)r)->f10 = p;
    *(char * *)&((struct Obj05121 *)r)->f8 = q;
    r[1] = 0x5a;
    ((struct Obj00225 *)q)->f30 = t;
    if (flag)
        ((struct Obj05121 *)r)->fC = 1;
    else
        ((struct Obj05121 *)r)->fC = func_02165E24((int)x);
    func_021F0FC8(p, (u8 *)q, func_02165FC0(((struct Obj05121 *)r)->fC));
    func_021F0ED0(q, flag ? 0 : 1);
}









void func_021F1EAC(void *task, u8 *s)
{
    if (s[0] == 0) {
        u8 c = s[1];
        s[1] = c - 1;
        if (c != 0)
            return;
        if (((struct Obj02113 *)s)->fC == 1 || ((struct Obj02113 *)s)->fC == 0x18 || ((struct Obj02113 *)s)->fC == 0x31) {
            func_021F1080((char *)(((struct Obj02113 *)s)->f10), (char *)(*(u32 *)&((struct Obj02113 *)s)->f8), 1, 0);
            s[0]++;
            return;
        }
    } else {
        if (((struct Obj20437 *)(*(char * *)&((struct Obj02113 *)s)->f8))->f2C != 0)
            return;
    }
    ((struct Obj20438 *)(*(char * *)&((struct Obj02113 *)s)->f8))->f30 = 0;
    func_021F0ED0(*(char * *)&((struct Obj02113 *)s)->f8, 0);
    func_02031194(task);
}








void func_021F1F00(char *p, int a)
{
    u8 *q;
    u8 index;
    index = func_021659F0(*(u8 * *)&((struct Obj13066 *)p)->f3C, a + ((struct Obj13066 *)p)->f7C);
    q = func_021F0F44((u8 *)p, index);
    func_021F1F34(p, q, (int *)(p + 0xa8));
    func_021F0DD8(0x54c);
}









void func_021F1F34(char *p, u8 *q, int *r)
{
    u8 *t;

    t = func_02031290(func_020311B8(((struct Obj20439 *)p)->fA0, (void *)func_021F1F9C, 0x14, 0));
    func_02082BCC(t, 0, 0x14);
    *(char * *)&((struct Obj04312 *)t)->fC = p;
    *(u8 * *)&((struct Obj04312 *)t)->f8 = q;
    t[2] = 2;
    t[3] = (q[0] + 4) << 4;
    func_02021FD8((struct Chan02021FD8 *)(((struct Obj20441 *)(*(char * *)&((struct Obj04312 *)t)->fC))->fAC), 3, t[3], 0x10, 4, 0x7fff);
    if (r != 0) {
        *(int * *)&((struct Obj04312 *)t)->f10 = r;
        (*r)++;
    }
}









void func_021F1F9C(void *task, u8 *s)
{
    u8 c = s[0];

    if (c < 2) {
        if (s[1]++ >= s[2]) {
            func_02021FD8((struct Chan02021FD8 *)(((struct Obj20443 *)(*(char * *)&((struct Obj02752 *)s)->fC))->fAC), 3, s[3], 0x10, (c % 2) << 2, 0x7fff);
            s[0]++;
            s[1] = 0;
        }
    } else {
        int *r;

        func_02021FD8((struct Chan02021FD8 *)(((struct Obj20444 *)(*(char * *)&((struct Obj02752 *)s)->fC))->fAC), 3, s[3], 0x10, 0, 0x7fff);
        r = *(int * *)&((struct Obj02752 *)s)->f10;
        if (r != 0)
            (*r)--;
        func_02031194(task);
    }
}









void func_021F201C(char *p, char *q, void *text, u16 x, u8 y, u8 a5, u16 col, u32 a7)
{
    u32 w;
    u32 v;

    func_02043B5C((struct CharBuf *)(((struct Obj06135 *)q)->f4), a5);
    if (((struct Obj07634 *)p)->f7A != 0) {
        func_0201C7D0(((struct Obj06135 *)q)->f4, x, y, text, ((struct Obj07634 *)p)->fB0, col);
        w = ((struct Obj06135 *)q)->f0;
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        return;
    }
    v = ((struct Obj07634 *)p)->fB4;
    func_0201C724((void *)v, (u32)func_02045770((struct Descriptor *)((struct Obj06135 *)q)->f8), x, y, (u32)text,
                  ((struct Obj07634 *)p)->fB0, col);
    ((struct Obj06135 *)q)->fC = 1;
    func_021F20A8(p, q, (int *)a7);
}








void func_021F20A8(char *p, char *q, int *r)
{
    u8 *t;
    t = func_02031290(func_020311B8(((struct Obj20446 *)p)->fA0, (void *)func_021F20E4, 0x10, 0));
    func_02082BCC(t, 0, 0x10);
    *(char * *)&((struct Obj09799 *)t)->f8 = p;
    *(char * *)&((struct Obj09799 *)t)->f4 = q;
    if (r != 0) {
        *(int * *)&((struct Obj09799 *)t)->fC = r;
        (*r)++;
    }
}








void func_021F20E4(void *task, char *q)
{
    u8 *s;
    u32 v;
    int *r;

    v = ((struct Obj20448 *)(*(char * *)&((struct Obj06136 *)q)->f8))->fB4;
    s = *(u8 * *)&((struct Obj06136 *)q)->f4 + 8;
    if (s[4] != 0) {
        if (func_0201C6C4((struct PrintSys *)v, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj06137 *)s)->f0))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj06137 *)s)->f0);
            s[4] = 0;
        }
    }
    if (s[4] == 0) {
        func_02045374((struct Cfg *)(**(u32 * *)&((struct Obj06136 *)q)->f4));
        func_02041B6C(func_02045730((struct Descriptor *)(**(u32 * *)&((struct Obj06136 *)q)->f4)));
        r = *(int * *)&((struct Obj06136 *)q)->fC;
        if (r != 0)
            (*r)--;
        func_02031194(task);
    }
}








void func_021F2144(char *p, char *q, void *text, u16 col, u32 a4)
{
    u32 *t;

    t = (u32 *)(q + 0x18);
    func_02043B5C((struct CharBuf *)t[1], 0);
    if (((struct Obj07635 *)p)->f7A != 0) {
        func_0201C7D0((u32)((void *)t[1]), 0, 0, text, (u32)((void *)(((struct Obj07635 *)p)->fB0)), col);
        func_020257D0((struct Obj *)t[0]);
        return;
    }
    func_0201C724((void *)(((struct Obj07635 *)p)->fB4), t[1], 0, 0, (u32)text, ((struct Obj07635 *)p)->fB0, col);
    func_021F21B0(p, q, (int *)a4);
}








void func_021F21B0(char *p, char *q, int *r)
{
    void *t;
    u8 *s;

    t = func_020311B8(((struct Obj20452 *)p)->fA0, (void *)func_021F21F8, 0x10, 0);
    s = func_02031290(t);
    func_02082BCC(s, 0, 0x10);
    *(char * *)&((struct Obj07637 *)s)->f8 = p;
    *(char * *)&((struct Obj07637 *)s)->f0 = q;
    *(char * *)&((struct Obj07637 *)s)->f4 = q + 0x18;
    ((struct Obj20453 *)q)->f2C = t;
    if (r != 0) {
        *(int * *)&((struct Obj07637 *)s)->fC = r;
        (*r)++;
    }
}







void func_021F21F8(void *task, char *q)
{
    int *r;
    if (func_0201C6C4((struct PrintSys *)(((struct Obj20455 *)(*(char * *)&((struct Obj07638 *)q)->f8))->fB4), (void *)((*(u32 **)(q + 4))[1])) == 0) {
        func_020257D0((struct Obj *)(**(u32 * *)&((struct Obj07638 *)q)->f4));
        r = *(int * *)&((struct Obj07638 *)q)->fC;
        if (r != 0)
            (*r)--;
        ((struct Obj20458 *)(*(char * *)&((struct Obj07638 *)q)->f0))->f2C = 0;
        func_02031194(task);
    }
}







char *func_021F2234(u32 a0, u32 a1)
{
    char *p;
    void *v;

    p = func_02030734(0x70, 0x3d0, 1, d_021F36A0, 0x8d);
    ((struct Obj00007 *)p)->f0 = a0;
    ((struct Obj00007 *)p)->f4 = (u32)func_020120F4((const struct Ctx *)a0);
    ((struct Obj00007 *)p)->f8 = v = func_0201210C((void *)a0);
    ((struct Obj00007 *)p)->f10 = func_02188E30(v);
    ((struct Obj00007 *)p)->fC = a1;
    ((struct Obj00007 *)p)->f98 = 0x70;
    ((struct Obj00007 *)p)->f94 = 0x15;
    ((struct Obj00007 *)p)->f96 = 0x8070;
    ((struct Obj00007 *)p)->f9C = func_020490F4(0xad, ((struct Obj00007 *)p)->f98);
    func_021F27D4((u8 *)p);
    func_021F2908(p);
    func_021F2A8C((u8 *)p, ((struct Obj00007 *)p)->f9C);
    func_021F2C1C(p);
    func_021F2D20((Work_021F2A8C *)p, ((struct Obj00007 *)p)->f9C);
    func_021F2F44(p, ((struct Obj00007 *)p)->f9C);
    func_021F3058(p);
    ((struct Obj00007 *)p)->f7A = 1;
    func_021EFEC0((u8 *)p);
    ((struct Obj00007 *)p)->f7A = 0;
    *(u32 *)&((struct Obj00007 *)p)->f60 = 0;
    func_021F0208((u8 *)p, 1);
    return p;
}







void func_021F22FC(char *p)
{
    func_0203115C((struct Tcbl *)(((struct Obj00812 *)p)->fA0));
    func_021F30B4(p);
    func_021F2FCC(p);
    func_021F2EDC(p);
    func_021F2CC4(p);
    func_021F2BD4(p);
    func_021F2A04(p);
    func_021F28DC(p);
    func_02049238((void *)((struct Obj00812 *)p)->f9C);
    func_020307B0(p);
}





void func_021F2344(char *p, int a1)
{
    int f;

    if (((struct Obj00007 *)p)->f60 != a1) {
        int c;

        if (((struct Obj00007 *)p)->f72 != 0 && a1 == 0) {
            c = 1;
        } else {
            c = 0;
        }
        if (c == 0) {
            f = 1;
            ((struct Obj00007 *)p)->f60 = a1;
            if (a1 != 0) {
                f = 0;
            }
            func_021F0208((u8 *)p, f);
        }
    }
    if (((struct Obj00007 *)p)->f70 != 0) {
        if (a1 == 0) {
            func_021F2544(p);
            return;
        }
        return;
    }
    if (a1 != 0) {
        func_020310C4((struct Tcbl *)(*(int *)&((struct Obj00007 *)p)->fA0));
        switch (((struct Obj00007 *)p)->f68) {
        case 0:
            ((struct Obj00007 *)p)->f68 = func_021F2674(p);
            break;
        case 1:
            ((struct Obj00007 *)p)->f68 = func_021F26D8((u8 *)p);
            break;
        case 2:
            ((struct Obj00007 *)p)->f68 = func_021F26F0((u8 *)p);
            break;
        case 3:
            ((struct Obj00007 *)p)->f68 = func_021F2714(p);
            break;
        case 4:
            ((struct Obj00007 *)p)->f68 = func_021F27B4((u8 *)p);
            break;
        case 5:
            ((struct Obj00007 *)p)->f68 = func_021F27CC(p);
            break;
        case 6:
        case 7:
            break;
        }
        func_02165888(((struct Obj00007 *)p)->f38);
    }
}




/*
 * Byte-correct; the only wildcards are the bls to two unlabelled arm9
 * leaves, Ilias's (blocker: no witness outside the range). Verified leaf C
 * (both EXACT, thumb, `one --thumb` with no --region):
 *   0x020275B8 (12 bytes incl. pool word 0x0B0E):
 *     typedef unsigned char u8;
 *     void func_020275B8(char *p, u8 v) { p[0xb0e] = v; }
 *   0x020275D0 (12 bytes incl. pool word 0x0B0C):
 *     void *func_020275D0(char *p) { return p + 0xb0c; }
 * 0x53 is ov083's id (func_021F5260/func_021F5368 are ov083 children).
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/func_020275A8,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 */
u32 func_021F23F8(char *p)
{
    return func_0201C4E4(*(struct PrintSys **)(p + 0xB4));
}


void *func_021F2404(char *p, int go)
{
    void *r;
    Args args;

    if (go == 0)
        return 0;
    switch (*(u16 *)(p + 0x70)) {
    case 2:
        func_02158614((void *)(*(int *)(p + 0x1c)));
    case 1:
    case 3:
        func_020275B8(*(void **)(p + 0x34), 0);
        r = func_021F254C(p, (unsigned)(func_021945A4(*(void **)p, (u32)(*(void **)(p + 8)), 0)), 0, 3);
        break;
    case 4:
        r = func_021F254C(p, (unsigned)(func_02164B38(*(void **)p, *(void **)(p + 8), *(u8 *)(p + 0x7e) + *(u8 *)(p + 0x7c))), 1, 0);
        break;
    case 5:
        args.a = *(u8 *)(p + 0x7f);
        args.b = *(u8 *)(p + 0x80);
        r = func_021F254C(p, (unsigned)(func_020124AC(*(void **)p, (u32)ov083_id, (void *)func_021F5260, (u32)(&args))), 2, *(u32 *)(p + 0xd0));
        p[0x7f] = 0x30;
        break;
    case 6:
        r = func_021F254C(p, (unsigned)(func_020124AC(*(void **)p, (u32)ov083_id, (void *)func_021F5368, (u32)(*(void **)(p + 8)))), 2, *(u32 *)(p + 0xc0));
        break;
    case 7:
        r = func_021F254C(p, (unsigned)(func_020124AC(*(void **)p, (u32)ov083_id, (void *)func_021F5368, (u32)(*(void **)(p + 8)))), 2, *(u32 *)(p + 0xf0));
        p[0x79] = 0;
        break;
    case 8:
        r = func_021F254C(p, (unsigned)((void *)func_021CD2A4((u32)(*(void **)p), (u32)(*(void **)(p + 8)), 0, 7, (u32)func_020275D0((char *)(*(int *)(p + 0x34))))), 0, 1);
        break;
    default:
        return 0;
    }
    func_021F2544(p);
    return r;
}




void func_021F253C(char *p, int v)
{
    ((struct Obj20459 *)p)->f70 = v;
}




void func_021F2544(char *p)
{
    ((struct Obj20460 *)p)->f70 = 0;
}







Desc *func_021F254C(char *p, unsigned a, unsigned b, unsigned c)
{
    Desc *d;
    Work_021F254C *w;
    d = (Desc *)func_020122C0(((struct Obj07639 *)p)->f0, 0, func_021F2588, 0x1c);
    w = func_020124E8((struct Obj *)d);
    w->owner = p;
    w->f04 = ((struct Obj07639 *)p)->f0;
    w->f08 = ((struct Obj07639 *)p)->f8;
    w->f10 = a;
    w->f14 = b;
    w->f18 = c;
    ((struct Obj07639 *)p)->f72 = 1;
    return d;
}








int func_021F2588(int a0, int a1, int *st)
{
    int r;
    char *o;

    r = 0;
    o = (char *)st[3];
    switch (st[5]) {
    case 0:
        r = func_021F25D4((u8 *)o, st);
        break;
    case 1:
        r = func_021F2608(o, st);
        break;
    case 2:
        r = func_021F2624((int)o, st);
        break;
    }
    if (r) {
        ((struct Obj09800 *)o)->f72 = 0;
        func_0201235C((struct S0201235C *)a0, (u32 *)st[4]);
    }
    return 0;
}







int func_021F25D4(u8 *p, int *st)
{
    switch (st[0]) {
    case 0:
        func_021F05E8(p, st[6], 1);
        st[0]++;
        return 0;
    case 1:
        if (func_021F0668((char *)p, st[6]) != 0)
            return 0;
        break;
    }
    return 1;
}







int func_021F2608(char *p, int *unused)
{
    func_020310C4(*(struct Tcbl * *)&((struct Obj09800 *)p)->fA0);
    if (((struct Obj09800 *)p)->fA8 == 0)
        return 1;
    return 0;
}








int func_021F2624(int a0, int *st)
{
    int h = st[6];

    switch (st[0]) {
    case 0:
        func_0202822C((char *)h, 1);
        st[0]++;
        break;
    case 1:
        func_02028178((u8 *)h);
        if (func_02028230((u8 *)h)) {
            func_020282A4((struct Obj *)h);
            return 1;
        }
        break;
    }
    return 0;
}







void func_021F2664(int a, char *p)
{
    if (*(struct S02021D50 * *)&((struct Obj13067 *)p)->fAC)
        func_02021D50(*(struct S02021D50 * *)&((struct Obj13067 *)p)->fAC);
}








int func_021F2674(char *p)
{
    int r;

    if (func_021F00C8(p)) {
        ((struct Obj00188 *)p)->f74 = 90;
        return 2;
    }
    if (func_021F0078(p)) {
        return 0;
    }
    r = func_021EFF7C((u8 *)p);
    if (r == 0) {
        if (((struct Obj00188 *)p)->f74 != 0) {
            ((struct Obj00188 *)p)->f74 = ((struct Obj00188 *)p)->f74 - 1;
            return 0;
        }
        if (func_021F0114((u8 *)p) == 1) {
            ((struct Obj00188 *)p)->f74 = 90;
            return 2;
        }
        if (func_021F0140((u8 *)p) == 0) {
            return 0;
        }
        ((struct Obj00188 *)p)->f74 = 90;
        return 1;
    }
    return r;
}







int func_021F26D8(u8 *p)
{
    if (func_021F02C4(p) == 0)
        return 1;
    ((struct Obj00007 *)p)->f6C = 0;
    return 2;
}







int func_021F26F0(u8 *p)
{
    if (((struct Obj00007 *)p)->fA8 != 0)
        return 2;
    func_021F05E8(p, 4, 0);
    func_021F067C((char *)p);
    return 0;
}








/*
 * note:     func_021F05E8 takes three arguments (its own matched file); the
 *           cleared zero is shared with its third argument, which is what
 *           puts the zero in r2 for the three stores.
 */
int func_021F2714(char *p)
{
    int r;

    if (((struct Obj00007 *)p)->f82 == 0) {
        r = func_021F0050((unsigned char *)p);
        if (r != ((struct Obj00007 *)p)->f84 || r == -1) {
            ((struct Obj00007 *)p)->f82 = 1;
        }
        ((struct Obj00007 *)p)->f88 = ((struct Obj00007 *)p)->f88 + 1;
    }
    if (((struct Obj00007 *)p)->f82 != 0) {
        if (((struct Obj00007 *)p)->fA8 > 0) {
            return 3;
        }
        ((struct Obj00007 *)p)->f82 = 0;
        ((struct Obj00007 *)p)->f88 = 0;
        ((struct Obj00007 *)p)->f81 = 0;
        if (((struct Obj00007 *)p)->f83 == 0) {
            func_021F05E8((u8 *)p, 4, 0);
        }
        func_021F067C(p);
        func_021F029C(p, 0);
        return ((struct Obj00007 *)p)->f83;
    }
    if (((struct Obj00007 *)p)->fA8 == 0) {
        func_021F028C((unsigned char *)p);
    }
    return 3;
}







/*
 * note: extent follower 0x021F27CC is already filed separately.
 */
int func_021F27B4(u8 *p)
{
    if (func_021F03EC(p) == 0)
        return 4;
    ((struct Obj00007 *)p)->f6C = 0;
    return 0;
}








int func_021F27CC(char *p)
{
    return func_021F0438((u8 *)p);
}








/*
 *           wildcarded because their targets are unlabelled arm9 leaves with no
 *           caller outside this range (Ilias's, inside arm9). Each was verified
 *           EXACT with `one --thumb` and no --region:
 *             0x020275A8  u32 func_020275A8(u32 a) { return a; }
 *             0x020275AC  u8 func_020275AC(u8 *p) { return p[0xb0e]; }
 *             0x02010F7C  u32 func_02010F7C(u32 heap)
 *                         { return func_02048F60(0x26, 0, heap); }
 *                         (func_02048F60 0x02048F60 arm, a tail call)
 *           Once those three are matched in arm9, this file is EXACT as it stands.
 *           The min of p[0x7b] and 4 must be an if/else of two stores: the
 *           ternary inverts the branch (blo for bhs; b).
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/func_020275A8,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 */
void func_021F27D4(u8 *p)
{
    u32 sv;
    u32 s2;

    *(u32 *)(p + 0x34) = func_02012A54((const struct BigObj *)(*(u32 *)(p + 4)));
    *(u32 *)(p + 0x3c) = func_020275A8(*(u32 *)(p + 0x34));
    p[0x7b] = func_02165B04((u8 *)(*(u32 *)(p + 0x3c)));
    p[0x7c] = func_020275AC((u8 *)(*(u32 *)(p + 0x34)));
    if (p[0x7b] < 4)
        p[0x7d] = p[0x7b];
    else
        p[0x7d] = 4;
    p[0x7f] = 0x30;
    p[0x78] = func_02012FFC();
    sv = (u32)func_02012EBC((struct Big *)(*(u32 *)(p + 4)));
    *(u32 *)(p + 0x28) = func_0200BF10((struct Rec1B0 *)func_0200BE48((void *)sv));
    *(u32 *)(p + 0x1c) = func_02012138((const struct Ctx *)(*(u32 *)p));
    *(u32 *)(p + 0x20) = func_0201283C((const struct BigObj *)(*(u32 *)(p + 4)));
    *(u32 *)(p + 0x18) = (u32)func_0201292C((const struct BigObj *)(*(u32 *)(p + 4)));
    *(u32 *)(p + 0x14) = (u32)func_0200C0E8((void *)sv);
    *(u32 *)(p + 0x2d4) = func_0200C1DC((struct Blk34 *)(*(u32 *)(p + 0x14)));
    s2 = (u32)func_02008730((void *)sv);
    *(u32 *)(p + 0x2c) = (u16)func_02008530((const struct Sub0200852CObj *)s2);
    p[0x30] = func_02008550((const struct Sub0200852CObj *)s2);
    p[0x31] = func_02008554((const struct Sub0200852CObj *)s2);
    p[0x32] = 0x15;
    *(u32 *)(p + 0x38) = (u32)func_02165B2C(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x40) = (u32)func_02165B10(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x44) = (u32)func_02165B10(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x4c) = (u32)func_02165B10(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x24) = (u32)func_02010F7C(*(u16 *)(p + 0x98));
    func_021F0684(p, p + 0x58, p + 0x59);
}







/*
 * note: two alignment padding bytes at 0x021F2906 follow the body.
 */
void func_021F28DC(char *p)
{
    func_02165940(((struct Obj05123 *)p)->f38);
    func_02010F8C(((struct Obj05123 *)p)->f24);
    func_020307B0(((struct Obj05123 *)p)->f4C);
    func_020307B0(((struct Obj05123 *)p)->f44);
    func_020307B0(((struct Obj05123 *)p)->f40);
    func_020307B0(((struct Obj05123 *)p)->f38);
}








void func_021F2908(char *p)
{
    ((struct Obj00007 *)p)->fA0 = func_0203101C(((struct Obj00007 *)p)->f98, ((struct Obj00007 *)p)->f98, 0x10, 0x80);
    ((struct Obj00007 *)p)->fA4 = func_020056A0((void *)func_021F2664, p, 0);
    ((struct Obj00007 *)p)->fAC = (u32)func_02021518(((struct Obj00007 *)p)->f98);
    func_0202155C((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), 1, 0x1c0, ((struct Obj00007 *)p)->f98);
    func_0202155C((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), 3, 0x200, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->fB4 = func_0201C440((void *)(((struct Obj00007 *)p)->f98));
    func_0201C4C8((struct PrintSys *)(((struct Obj00007 *)p)->fB4), 1);
    func_0201C4DC((struct PrintSys *)(((struct Obj00007 *)p)->fB4), 0x1f4, 0);
    ((struct Obj00007 *)p)->fB0 = func_021904AC((u8 *)func_02188C54((u8 *)(*(u32 *)&((struct Obj00007 *)p)->f8)));
    func_0201DD68();
    ((struct Obj00007 *)p)->f110 = func_0201EC64(((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f114 = func_02045B38(1, 2, 8, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f118 = func_020457B0(0xd9, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f11C = func_020457B0(0xd9, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f120 = func_020457B0(0xd9, ((struct Obj00007 *)p)->f98);
}








void func_021F2A04(char *p)
{
    func_02045808((struct U16Vec *)(((struct Obj00812 *)p)->f120));
    func_02045808((struct U16Vec *)(((struct Obj00812 *)p)->f11C));
    func_02045808((struct U16Vec *)(((struct Obj00812 *)p)->f118));
    func_02045C04((Rec_021F254C *)(((struct Obj00812 *)p)->f114));
    func_0201ED04((struct WordSet *)(((struct Obj00812 *)p)->f110));
    func_0201C6EC((struct PrintSys *)(((struct Obj00812 *)p)->fB4));
    func_0201C4C0((struct PrintSys *)(((struct Obj00812 *)p)->fB4));
    func_0201DD68();
    func_020215A0((struct PalAnmSlot *)(((struct Obj00812 *)p)->fAC), 3);
    func_020215A0((struct PalAnmSlot *)(((struct Obj00812 *)p)->fAC), 1);
    func_02021540((void *)(((struct Obj00812 *)p)->fAC));
    ((struct Obj00812 *)p)->fAC = 0;
    func_02030EAC((struct Node *)(((struct Obj00812 *)p)->fA4));
    func_02031140((struct S02031140 *)(*(int *)&((struct Obj00812 *)p)->fA0));
}








/*
 * volatile: 0x021F2ACE ldr / 0x021F2AD6 str of 0x04001000 (REG_DB_DISPCNT_SUB read-modify-write); 0x021F2ADC strh to 0x04001050 (hardware registers)
 */
void func_021F2A8C(u8 *p, void *h)
{
    func_0203FCA0(4, (const struct BgTemplate *)d_021F3608, 0);
    func_0203FCA0(5, (const struct BgTemplate *)d_021F3628, 0);
    func_0203FCA0(6, (const struct BgTemplate *)d_021F3648, 0);
    func_0203FCA0(7, (const struct BgTemplate *)d_021F3668, 0);
    func_02082A7C(0, (void *)0x06200000, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    func_020216B4((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), (void *)h, 0x13, ((struct Obj00007 *)p)->f96, 1, 0x1a0, 0);
    func_02021640((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), 0x17, 5, ((struct Obj00007 *)p)->f96, 1, 0x20, 0xd0);
    func_02049658((void *)h, 0x14, 7, 0, 0, 1, ((struct Obj00007 *)p)->f96);
    func_020498F4((void *)h, 0x15, 5, 0, 0x800, 1, ((struct Obj00007 *)p)->f96);
    func_020498F4((void *)h, 0x16, 6, 0, 0x800, 1, ((struct Obj00007 *)p)->f96);
    func_020498F4((void *)h, 0x17, 7, 0, 0x800, 1, ((struct Obj00007 *)p)->f96);
    func_0207D63C(0x04001050, 4, 0x1e, 0xd, 3);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    func_02040588(7, 1);
}








void func_021F2BD4(char *p)
{
    unsigned short z = 0;

    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    *(volatile unsigned short *)0x04001050 = z;
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
}








void func_021F2C1C(char *p)
{
    int i;
    int z;

    z = 0;
    ((struct Obj00007 *)p)->fBC = func_02028590(9, 0, 1, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->fB8 = (unsigned int)func_02027F60(4, 0xe, ((struct Obj00007 *)p)->fB0, ((struct Obj00007 *)p)->fB4, ((struct Obj00007 *)p)->f98);
    i = 0;
    do {
        *(unsigned *)(p + i * 16 + 0xc4) = (unsigned int)func_02045EC0((struct MsgBank *)(*(unsigned *)&((struct Obj00007 *)p)->f114), i + 0xc);
        *(unsigned short *)(p + i * 16 + 0xc8) = 0x39e3;
        *(int *)(p + i * 16 + 0xcc) = z;
        *(int *)(p + i * 16 + 0xc0) = z;
        i++;
    } while (i < 3);
    z = 0;
    i = 0;
    do {
        *(unsigned *)(p + i * 16 + 0xf4) = (unsigned int)func_02045EC0((struct MsgBank *)(*(unsigned *)&((struct Obj00007 *)p)->f114), i + 0xf);
        *(unsigned short *)(p + i * 16 + 0xf8) = 0x39e3;
        *(int *)(p + i * 16 + 0xfc) = z;
        *(int *)(p + i * 16 + 0xf0) = z;
        i++;
    } while (i < 2);
}








void func_021F2CC4(char *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (*(int *)(p + i * 16 + 0xf0) != 0) {
            func_02028148((u8 *)(*(int *)(p + i * 16 + 0xf0)));
        }
        func_02045808((struct U16Vec *)(*(int *)(p + i * 16 + 0xf4)));
    }
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + i * 16 + 0xc0) != 0) {
            func_02028148((u8 *)(*(int *)(p + i * 16 + 0xc0)));
        }
        func_02045808((struct U16Vec *)(*(int *)(p + i * 16 + 0xc4)));
    }
    func_02027FD8((struct TaskMenuState *)(((struct Obj00812 *)p)->fB8));
    func_02028604(((struct Obj00812 *)p)->fBC);
}








/*
 * note:     the work block must be a struct with the two Ent arrays as members:
 *           raw (p + K)[i] offsets fold the base into one register and the
 *           frame comes out 0x10 bytes short.
 */
void func_021F2D20(Work_021F2A8C *p, void *h)
{
    void *h2;
    ResSpec3 a;
    ResSpec3 b;
    ResSpec3 c;
    int i;

    h2 = func_020490F4(0x20, p->heap);
    a = d_021F35BC;
    func_021F30D4((char *)((Work_021F2A8C *)p), p->l134, a.s, h);
    b = d_021F35D4;
    func_021F30D4((char *)((Work_021F2A8C *)p), p->l164, b.s, h);
    c = d_021F35C8;
    func_021F30D4((char *)((Work_021F2A8C *)p), p->l14c, c.s, h2);
    func_020216B4((struct PalAnmSlot *)p->fac, h, 0, p->heap, 3, 0x1c0, 0);
    func_02021640((struct PalAnmSlot *)p->fac, 0, 1, p->heap, 3, 0x20, 0xe0);
    p->r3c4.res = func_02049250(h, 4, p->heap2);
    func_02062A98(p->r3c4.res, (void **)(&p->r3c4.hdr));
    p->r3c4.data = ((struct Obj20461 *)(p->r3c4.hdr))->fC;
    p->r3b8.res = func_02049250(h2, 0, p->heap2);
    func_02062A98(p->r3b8.res, (void **)(&p->r3b8.hdr));
    p->r3b8.data = ((struct Obj20462 *)(p->r3b8.hdr))->fC;
    for (i = 0; i < 16; i++) {
        p->e1[i].res = func_02049250(h2, i + 0x31, p->heap2);
        func_02062A00(p->e1[i].res, &p->e1[i].data);
    }
    for (i = 0; i < 12; i++) {
        p->e2[i].res = func_02049250(h, i + 7, p->heap2);
        func_02062A00(p->e2[i].res, &p->e2[i].data);
    }
    DC_FlushAll();
    func_02049238(h2);
}








void func_021F2EDC(char *p)
{
    int i;

    for (i = 0; i < 12; i++) {
        func_020307B0((void *)(*(int *)(p + 0x2dc + i * 8)));
    }
    for (i = 0; i < 16; i++) {
        func_020307B0((void *)(*(int *)(p + 0x33c + i * 8)));
    }
    func_020307B0((void *)(((struct Obj00812 *)p)->f3CC));
    func_020307B0((void *)(((struct Obj00812 *)p)->f3C0));
    func_021F31A8(p, (T_021F31A8 *)(p + 0x14c));
    func_021F31A8(p, (T_021F31A8 *)(p + 0x164));
    func_021F31A8(p, (T_021F31A8 *)(p + 0x134));
}








/*
 * note:     func_0204B258 takes two arguments (twin ov029_func_021F1DE8): the
 *           0x12C result still in r1 at that call is its second argument.
 */
void func_021F2F44(char *p, void *a)
{
    T16 t;
    int i;

    ((struct Obj00007 *)p)->f128 = func_0204B100(0x40, 0, ((struct Obj00007 *)p)->f94);
    t = d_021F35E0;
    ((struct Obj00007 *)p)->f12C = func_0204B034((u8 *)(&t), 1, ((struct Obj00007 *)p)->f98);
    func_0204B258(((struct Obj00007 *)p)->f128, ((struct Obj00007 *)p)->f12C);
    ((struct Obj00007 *)p)->f124 = func_02025538(((struct Obj00007 *)p)->f98, ((struct Obj00007 *)p)->f128);
    func_021F3264((S_021F254C *)p);
    for (i = 0; i < 5; i++) {
        func_021F32F8(p, i);
    }
    func_02043598(0x10, 1);
}








void func_021F2FCC(char *p)
{
    int i;

    func_02043598(0x10, 0);
    for (i = 0; i < 5; i++) {
        func_021F34C8(p, (unsigned char)i);
    }
    func_021F32D4(p);
    func_02025588((void *)(((struct Obj00812 *)p)->f124));
    func_0204B084(((struct Obj00812 *)p)->f12C);
    func_0204B1CC((struct Bank *)(((struct Obj00812 *)p)->f128));
}






void func_021F3010(T_021F254C *p, unsigned a, unsigned b, unsigned c, unsigned char d, unsigned char e, unsigned char f)
{
    void *w;
    p->f0 = func_020450F0((void *)a, c, d, e, f, b, 1);
    p->f4 = func_02045770(p->f0);
    w = p->f0;
    p->fc = 0;
    p->f8 = w;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));
}





void func_021F3058(char *p)
{
    func_021F3010((T_021F254C *)(p + 0x17C), 6, 1, 2, 0x16, 0x1C, 6);
    func_021F3010((T_021F254C *)(p + 0x190), 4, 0xD, 1, 0x15, 0xF, 3);
    func_021F3010((T_021F254C *)(p + 0x1A4), 7, 4, 0, 0x13, 6, 2);
}




void func_021F30B4(char *p)
{
    int i;
    for (i = 0; i < 3; i++)
        func_020452E8(*(struct Descriptor **)(p + i * 20 + 0x17c));
}





void func_021F30D4(char *this, ResList *out, const ResSpec *spec, void *arc)
{
    int i;

    func_02082BCC(out, 0, 0x18);
    for (i = 0; i < 3; i++) {
        out[i].count = spec[i].count;
        if (out[i].count != 0)
            out[i].items = func_02030734(((struct Obj07640 *)this)->f94, out[i].count << 2, 1, d_021F36A0, 0x4C3);
    }
    for (i = 0; i < out[0].count; i++)
        out[0].items[i] = func_0204ABF0(arc, spec[0].base + i, 1, 0, ((struct Obj07640 *)this)->f94);
    for (i = 0; i < out[1].count; i++)
        out[1].items[i] = func_0204A6C8(arc, spec[1].base + i, 0, 1, ((struct Obj07640 *)this)->f94);
    for (i = 0; i < out[2].count; i++)
        out[2].items[i] = func_0204AF28(arc, spec[2].base + i * 2, spec[2].base + 1 + i * 2, ((struct Obj07640 *)this)->f94);
}




void func_021F31A8(void *unused, T_021F31A8 *p)
{
    unsigned i;
    int j;
    for (i = 0; i < p->n2; i++)
        func_0204AFD8(p->a2[i]);
    for (i = 0; i < p->n1; i++)
        func_0204A8D4(p->a1[i]);
    for (i = 0; i < p->n0; i++)
        func_0204ADA4(p->a0[i]);
    for (j = 0; j < 3; j++) {
        if (((unsigned *)p)[j * 2 + 1] != 0)
            func_020307B0((void *)(((unsigned *)p)[j * 2 + 1]));
    }
}




void *func_021F3214(char *p, unsigned a, unsigned b, unsigned c, short x, short y, unsigned char w, unsigned char h, unsigned char z)
{
    Rect r;
    void *res;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    r.z = z;
    res = func_0204B294((void *)((struct Obj13068 *)p)->f128, a, b, c, &r, 0, ((struct Obj13068 *)p)->f94);
    func_0204B92C(res, 1);
    func_0204BA20(res, 0);
    return res;
}




/*
 * note:     the object array at +0x2BC must be a struct array member: raw
 *           (p + i * 4) arithmetic schedules p+i*4 ahead of &d[i] (2-byte DIFF).
 */
void func_021F3264(S_021F254C *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        p->o[i] = func_021F3214((char *)p, *p->b, *p->a, *p->c, d_021F35F0[i].x, d_021F35F0[i].y, i * 3 + 1, 1, 1);
        func_0204B3DC(p->o[i], 1);
    }
}



void func_021F32D4(char *p)
{
    int i;
    char *q;
    for (i = 0; i < 6; i++) {
        q = p + i * 4;
        func_0204B3DC(*(struct Obj * *)&((struct Obj13069 *)q)->f2BC, 0);
        func_0204B3B4(*(struct Obj * *)&((struct Obj13069 *)q)->f2BC);
    }
}




/*
 * Builds the 0x34-byte record at +0x1B8 that func_021F34C8 tears down.
 */
void func_021F32F8(char *p, u8 idx)
{
    Rec_021F254C *r;
    Tmpl t;

    r = (Rec_021F254C *)(p + 0x1b8 + idx * 0x34);
    func_02082BCC(r, 0, 0x34);
    r->f00 = idx;
    r->f01 = 0xff;
    r->f02 = 0;
    r->f28 = ((struct Obj00007 *)p)->fB4;
    r->x = idx * 13;
    r->y = idx * 0x28;
    r->f0c = func_021F3214(p, **(u32 * *)&((struct Obj00007 *)p)->f140, **(u32 * *)&((struct Obj00007 *)p)->f138, **(u32 * *)&((struct Obj00007 *)p)->f148,
                           r->x, r->y, 0, 3, idx + 0x14);
    func_0204B6F4(r->f0c, (u8)idx, 0);
    r->f10 = func_021F3214(p, (*(u32 **)(p + 0x158))[idx], **(u32 * *)&((struct Obj00007 *)p)->f138, **(u32 * *)&((struct Obj00007 *)p)->f160,
                           r->x + 0x20, r->y + 0x18, 0, 3, idx + 10);
    func_0204B6F4(r->f10, (u8)(idx + 9), 1);
    r->f14 = func_021F3214(p, (*(u32 **)(p + 0x170))[idx], **(u32 * *)&((struct Obj00007 *)p)->f138, **(u32 * *)&((struct Obj00007 *)p)->f178,
                           r->x + 0x3c, r->y + 0x18, 0, 3, idx + 5);
    r->f1c = func_02043678(0xc, 2, 0x20, ((struct Obj00007 *)p)->f98);
    t.bmp = r->f1c;
    t.x = r->x + 0x48;
    t.y = r->y + 0x10;
    t.f08 = **(u32 * *)&((struct Obj00007 *)p)->f138;
    t.f0c = 3;
    t.f10 = 0;
    t.f11 = 3;
    t.f12 = 0;
    t.f14 = 1;
    r->f18 = func_020255A0(((struct Obj00007 *)p)->f124, (const struct Param *)(&t));
    r->f20 = func_020457B0(0xb, ((struct Obj00007 *)p)->f98);
    r->f24 = func_020457B0(8, ((struct Obj00007 *)p)->f98);
    func_02043B5C(r->f1c, 0);
    func_020257D0(r->f18);
    func_02025774(r->f18, 0);
    func_0204B3DC(r->f0c, 0);
    func_0204B3DC(r->f10, 0);
    func_0204B3DC(r->f14, 0);
}
