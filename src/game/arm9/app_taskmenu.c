/*
 * file:     app_taskmenu.c
 * unit:     yes
 * function: func_020263B0, func_020263D8, func_02026400, func_0202640C, func_02026454, func_02026460, func_02026474, func_02026478, func_0202647C, func_02026484, func_0202648C, func_02026490, func_02026498, func_020264AC, func_020264B4, func_020264F4, func_02026504, func_02026608, func_02026680, func_020266AC, func_020266C0, func_020266D4, func_020266E0, func_02026728, func_020267BC, func_020267E4, func_020267FC, func_02026824, func_0202685C, func_02026A60, func_02026BFC, func_02026C1C, func_02026C30, func_02026C78, func_02026C8C, func_02026CA0, func_02026CE0, sub_02026D04, func_02026D48, func_02026D88, func_02026FB8, func_02027060, func_0202708C, func_020270AC, func_020270E0, func_02027100, func_02027120, func_02027138, func_0202715C, func_02027174, func_02027198, func_020271DC, func_020271F8, func_02027220, func_02027230, func_02027258, func_02027268, func_02027290, func_020272A4, func_020272D0, func_020272EC, func_02027314, func_02027324, func_0202734C, func_0202735C, func_0202737C, func_020273C4, func_020273DC, func_020273F8, func_02027414, func_02027430, func_0202744C, func_02027460, func_020274B4, func_020274C8, func_020274F8, func_0202751C, func_02027584, func_020275A8, func_020275AC, func_020275B8, func_020275C4, func_020275D0, func_020275DC, func_020275E0, func_020275E4, func_020275E8, func_020275EC, func_020275F8, func_020275FC, func_02027600, func_02027604, func_02027610, func_02027614, func_02027618, func_0202761C, func_02027620, func_02027624, func_02027628, func_0202762C, func_02027630, func_02027634, func_02027694, func_02027698, func_0202769C, func_020276A0, func_020276A4, func_020276A8, func_020276AC, func_020276B0, func_020276B4, func_020276B8, func_020276BC, func_020276C0, func_020276C4, func_02027710, func_02027714, func_02027718, func_0202771C, func_02027720, func_0202772C, func_02027738, func_02027740, func_02027748, func_0202774C, func_02027750, func_02027754, func_02027758, func_0202775C, func_02027760, func_02027764, func_02027768, func_0202776C, func_02027770, func_02027774, func_02027778, func_0202784C, func_02027858, func_020278F4, func_02027974, func_020279E8, func_02027A04, func_02027A08, func_02027A20, func_02027A24, func_02027B30, func_02027B60, func_02027BF4, func_02027CD8, func_02027CFC, func_02027D44, func_02027E3C, func_02027F60, func_02027FD8, func_02027FEC, func_0202800C, func_0202804C, func_02028084, func_02028148, func_0202815C, func_02028164, func_02028178, func_02028218, func_0202822C, func_02028230, func_0202824C, func_020282A4, func_020282AC, func_020282D8, func_0202843C, func_02028454, func_0202846C, func_02028470, func_02028484, func_020284F4, func_02028528, func_0202855C, func_02028590, func_0202822E
 * address:  0x020263B0
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
 *   g_0209FB74  0x0209FB74  data
 *   func_02082BCC  0x02082BCC  arm
 *   func_02026490  0x02026490  thumb
 *   MI_CpuFill8 0x02082BCC  arm
 *   func_02012B58  0x02012B58  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012950  0x02012950  thumb
 *   func_020084BC  0x020084BC  thumb
 *   func_02008500  0x02008500  thumb
 *   func_02008550  0x02008550  thumb
 *   sub_02026504  0x02026504  thumb
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   g_02146940     0x02146940  data
 *   g_020A74BC     0x020A74BC  data
 *   g_020A74C0     0x020A74C0  data
 *   func_0203CD98  0x0203CD98  arm
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_020272EC  0x020272EC  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   d_02146940     0x02146940  data  a4
 *   func_0217778C  0x0217778C  thumb
 *   data_0209FC20  0x0209FC20  data
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_0200E44C  0x0200E44C  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02167394  0x02167394  thumb
 *   func_0200E3A4  0x0200E3A4  thumb
 *   func_0200E49C  0x0200E49C  thumb
 *   func_0200E460  0x0200E460  thumb
 *   func_0200E4CC  0x0200E4CC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C33C  0x0200C33C  thumb
 *   func_0200C364  0x0200C364  thumb
 *   g_GameBeacon  0x02146940  data
 *   func_0200E6E8    0x0200E6E8  thumb
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   func_020127A4    0x020127A4  thumb
 *   func_02012AC8    0x02012AC8  thumb
 *   func_02013CC8    0x02013CC8  thumb
 *   func_02013CE0    0x02013CE0  thumb
 *   func_02012894    0x02012894  thumb
 *   func_02166C7C    0x02166C7C  thumb
 *   func_02008534    0x02008534  thumb
 *   func_02008554    0x02008554  thumb
 *   func_0200856C    0x0200856C  thumb
 *   func_02008570    0x02008570  thumb
 *   func_0200C224    0x0200C224  thumb
 *   func_0200C1C4    0x0200C1C4  thumb
 *   func_0200C1DC    0x0200C1DC  thumb
 *   func_02008650    0x02008650  thumb
 *   func_0200E3A0    0x0200E3A0  thumb
 *   func_0200E6FC    0x0200E6FC  thumb
 *   func_02045A98    0x02045A98  arm
 *   func_020084F4    0x020084F4  thumb
 *   func_0200C1F4    0x0200C1F4  thumb
 *   g_0209FC20    0x0209FC20  data
 *   g_0209FC04  0x0209FC04  data
 *   GX_GetBankForLCDC  0x02045A98  arm
 *   sub_02045A38       0x02045A38  arm
 *   func_02027230 0x02027230 thumb
 *   func_020271F8 0x020271F8 thumb
 *   g_System        0x02146940  data
 *   sub_02027060    0x02027060  thumb
 *   sub_02026FB8    0x02026FB8  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_021809D8  0x021809D8  thumb ov231
 *   func_02034A5C  0x02034A5C  arm
 *   sub_020274F8   0x020274F8  thumb
 *   func_02005624  0x02005624  thumb
 *   ov231_id       0x000000E7  data
 *   func_020457B0       0x020457B0  arm
 *   func_02045B38       0x02045B38  arm
 *   func_02045EC0       0x02045EC0  arm
 *   func_02045A38       0x02045A38  arm
 *   func_02045924       0x02045924  arm
 *   func_02045808       0x02045808  arm
 *   func_02045C04       0x02045C04  arm
 *   sBeaconStatus42     0x020A74D0  data
 *   d_0209FCF8  0x0209FCF8  data
 *   d_0209FCEC  0x0209FCEC  data
 *   func_0204162C  0x0204162C  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   MIi_CpuCopy16     0x02082A60  arm
 *   func_02027a24     0x02027A24  thumb
 *   func_020355c4     0x020355C4  arm
 *   func_02027b30     0x02027B30  thumb
 *   sFile_020A74E0    0x020A74E0  data
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   sub_020450F0   0x020450F0  arm
 *   sub_0201C724   0x0201C724  thumb
 *   tbl_020A1B38   0x020A1B38  data
 *   sub_02061CA4   0x02061CA4  arm
 *   func_020355C4 0x020355C4  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02035C08  0x02035C08  arm
 *   func_02049DB4   0x02049DB4  arm
 *   func_02049B40   0x02049B40  arm
 *   sub_020307B0  0x020307B0  arm
 *   sub_0201D304   0x0201D304  thumb
 *   g_020A74E0     0x020A74E0  data
 *   _s32_div_f     0x0209C0A4  arm
 *   func_02035D20  0x02035D20  arm
 *   func_02045738  0x02045738  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045798  0x02045798  arm
 *   func_02045740  0x02045740  arm
 *   func_020437D4  0x020437D4  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE5C  0x0201CE5C  thumb
 *   g_0209FD10  0x0209FD10  data
 */
#include "../../matched/include/Obj17245.h"
#include "../../matched/include/Obj17246.h"
#include "../../matched/include/Obj17248.h"
#include "../../matched/include/Obj17249.h"
#include "../../matched/include/Obj17250.h"
#include "../../matched/include/Obj04053.h"
#include "../../matched/include/Obj04054.h"
#include "../../matched/include/Obj06914.h"
#include "../../matched/include/Obj05716.h"
#include "../../matched/include/Obj00747.h"
#include "../../matched/include/Obj11840.h"
#include "../../matched/include/Obj17251.h"
#include "../../matched/include/Obj15760.h"
#include "../../matched/include/Obj00121.h"
#include "../../matched/include/Obj17252.h"
#include "../../matched/include/Obj15763.h"
#include "../../matched/include/Obj05717.h"
#include "../../matched/include/Obj05718.h"
#include "../../matched/include/Obj05719.h"
#include "../../matched/include/Obj05720.h"
#include "../../matched/include/Obj15764.h"
#include "../../matched/include/Obj15765.h"
#include "../../matched/include/Obj00059.h"
#include "../../matched/include/Obj00104.h"
#include "../../matched/include/Obj15770.h"
#include "../../matched/include/Obj11289.h"
#include "../../matched/include/Obj06917.h"
#include "../../matched/include/Obj15778.h"
#include "../../matched/include/Obj15779.h"
#include "../../matched/include/Obj00864.h"
#include "../../matched/include/Obj15780.h"
#include "../../matched/include/Obj11291.h"
#include "../../matched/include/Obj11292.h"
#include "../../matched/include/Obj15793.h"
#include "../../matched/include/Obj15794.h"

struct BigObj;
struct Rec44;
struct Sub24;
struct Sub0200852CObj;
struct Obj_1;
struct PlayTime;
struct Rec;
struct Big;
struct Blk34;
struct Rec_02026D88;
struct Rec1C;
struct SaveBlock;
struct Rec0200E6FC;
struct U16Vec;
struct Src_020263B0;
struct MsgBank;
struct Strbuf;
struct Cfg;
struct Obj_020263B0;
struct S;
struct Descriptor;
struct PrintSys;
struct Menu;
struct CfgObj;
struct Src;
struct StrObj;
struct Bmp;
typedef signed char    s8;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Obj_0 {
    u8  pad0[4];
    u8  f4;
    u8  f5;
    u8  pad6[0xA];
    u8  f10;
    u8  pad11[3];
    u32 f14;
    u32 f18;
};

typedef void (*Fn)(u32 a, u32 b, u32 c);

struct Sub {
    u32 f00;
    u8  b0 : 1;
    u8  b1 : 1;
    u8  b2 : 1;
    u8  b3 : 5;
    u8  f05;      /* +0x05 */
    u8  f06;
    u8  f07;
};

struct Comm {
    u32 f00;
    u8  b0 : 1;   /* +0x04 */
    u8  b1 : 1;
    u8  b2 : 1;
    u8  b3 : 5;
    u8  f05;
    u8  f06;
    u8  f07;
    u32 f08;
    struct Sub sub;       /* +0x0C; its state byte is +0x10 */
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
};

struct Field4 {
    u8 lo : 2;
    u8 bit2 : 1;
    u8 hi : 5;
};

struct Slot {
    u16 f00;
    u8  f02;
    u8  b0 : 1;
    u8  b1 : 1;
    u8  b2 : 1;
    u8  b3 : 5;
    u32 f04;
    u32 f08;
};

struct Ring {
    struct Slot slot[6];
    u8 count;
    u8 cursor;
};

struct Obj_1 {
    u32 owner;
    u8  pad04[0x3c - 4];
    struct Ring ring;
};

typedef struct {
    u16 h0;      /* +0x00 */
    u8  unk2;    /* +0x02 */
    u8  live : 1;   /* +0x03 bit 0 */
    u8  f1 : 1;     /* +0x03 bit 1 */
    u8  f2 : 1;     /* +0x03 bit 2 */
    u32 w4;      /* +0x04 */
    u32 w8;      /* +0x08 */
} Rec;

typedef struct { u8 b0 : 1; u8 rest : 7; u8 pad[0xb]; } E;

typedef signed int     s32;

/* the player's own record, 0x60 bytes at +4 of the beacon block */
struct Inner {
    u8  f00;
    u8  f01;
    u8  f02;
    u8  pad03[9];
    u32 f0c;
    u8  pad10[0x10];
    u16 arr[8];         /* 0x20 */
    u16 f30;
    u8  pad32[0x16];
    u16 lo : 8;         /* 0x48 */
    u16 a  : 3;
    u16 b  : 5;
    u16 f4a;
    u16 f4c;
    u8  pad4e[2];
    u8  field_50[10];
    u8  pad5a[4];
    u8  f5e;            /* 0x5e */
    u8  pad5f;
};

/* one received beacon slot, 0x60 bytes */
struct BeaconSlot {
    u8  b00;
    u8  pad01[0x10 - 1];
    u16 f10;
    u8  pad12[0x5c - 0x12];
    u16 f5c;
    u8  pad5e[2];
};

struct BeaconSys {
    u32 f00;
    struct Inner in;
    struct BeaconSlot slot[30];
    u32 mask;           /* 0xBA4 */
    u32 field_BA8;
    u8  padBAC[3];
    u8  field_BAF;
    u16 field_BB0;
};

typedef short          s16_0;

struct Payload { u32 w[23]; };

struct Rec { struct Payload p; u16 f5c; u8 pad5e[2]; };

struct Req {
    u8   f00;
    u8   pad01[8 - 1];
    u32  f08;
    u32  f0clo : 16;
    u32  trainer : 10;
    u32  f0chi : 6;
    u16  f10;
    u8   pad12[0x30 - 0x12];
    u16  f30;
    u8   pad32[0x3C - 0x32];
    u32  f3C;
    u8   pad40[0x46 - 0x40];
    u16  f46;
    u8   pad48[0x50 - 0x48];
    u8   f50[0x10];
};

typedef signed short   s16_1;

typedef struct {
    u8  language;
    u8  favoriteColor;
    u8  month;
    u8  day;
    u16 nickName[11];
    u16 nickNameLength;
    u16 comment[27];
    u16 commentLength;
} OSOwnerInfo;

struct Src_020263B0 { u16 a; u16 b; u16 c; u16 d; };

struct Rec_02026D88 {
    u8  b00;
    u8  b01;
    u8  b02;
    u8  b03lo : 7;
    u8  b03hi : 1;

    u32 id    : 17;
    u32 mode  : 10;
    u32 f04hi : 5;

    u32 peer  : 17;
    u32 seq   : 5;
    u32 f08hi : 10;

    u32 c0    : 6;
    u32 c6    : 3;
    u32 c9    : 3;
    u32 c12   : 4;
    u32 trainer : 10;
    u32 f0chi : 6;

    u16 f10;
    u16 f12[7];
    u16 vec[8];
    u16 f30;
    u8  pad32[0x50 - 0x32];
    u8  f50[10];
};

typedef struct {
    u32 f00;
    u32 f04 : 17;
    u32 f04hi : 15;
    u32 f08 : 17;
    u32 f08b : 5;
    u32 f08hi : 10;
    u32 f0clo : 16;
    u32 f0c : 10;
    u32 f0chi : 6;
    u8  pad10[0x5c - 0x10];
    u16 f5c;
    u8  f5e;
} Obj_0;

struct Prio { u32 prio : 8; u32 frames : 24; };

typedef struct { unsigned short lo : 8; unsigned short hi : 8; } F;

typedef struct {
    void *f000[0xb08 / 4];
    void *fb08;
} Obj_1;

struct BeaconGfx {
    u8  pad[0x540];
    u16 pal[0x60];
};

struct TaskMenuTmpl
{
  u32 heapId;
  u8 count;
  u8 pad05[3];
  const void *unk08;
  u32 unk0c;
  u8 pad10[2];
  u8 unk12;
  u8 unk13;
};

struct TaskMenuOwner {
  u8 pad_00[0x14];
  void *unk_14;
};

struct TaskMenu
{
  u8 unk00;
  u8 unk01;
  u16 unk02;
  u16 unk04;
  u16 unk06;
  u32 unk08;
  u32 unk0c;
  u32 unk10;
  u32 unk14;
  void **buf1;
  void *buf2;
  struct TaskMenuTmpl tmpl;
  void *arg1;
};

struct CfgTmpl {
    u8  pad00[0x14];
    u32 f14;
};

struct Cfg {
    u16 f00;
    u16 f02;
    struct CfgTmpl *f04;
    u8  pad08[0x10 - 0x08];
    u32 f10;
    u32 f14;
};

struct Src {
    u32 f00;
    u16 f04;
    u8  pad06[8 - 6];
    u32 f08;
};

struct Row_0 {
    u32 f00;
    u16 f04;
    u8  pad06[8 - 6];
    u32 f08;
};

struct Glyph {
    u16 f00;
    u16 f02;
};

struct Obj_020263B0 {
    u8  pad00[0x18];
    u32 *layers;
    struct Row_0 *rows;
    u8  pad20[0x24 - 0x20];
    u8  count;
    u8  pad25[0x2c - 0x25];
    u32 inset;
    u8  x0;
    u8  y0;
    u8  dx;
    u8  dy;
    struct Glyph *glyph;
};

typedef signed short   s16;

struct Row_1 {
    u8  pad00[8];
    u32 f08;
};

struct Menu {
    u8  cursor;     /* +0x00 */
    u8  pad01;      /* +0x01 */
    u16 h2;         /* +0x02 */
    u32 pad04[2];   /* +0x04 */
    u32 f0C;        /* +0x0C */
    u32 f10;        /* +0x10 */
    u32 pad14;      /* +0x14 */
    u32 *f18;       /* +0x18 */
    struct Row_1 *f1C;/* +0x1C */
    u32 pad20;      /* +0x20 */
    u8  count;      /* +0x24 */
    u8  pad25[0x34 - 0x25];
    u32 f34;        /* +0x34 */
};

struct R {
    u16 a;
    u16 b;
    u32 f04;
    u32 obj;
    u32 pad0c;
    u32 c;
    u32 d;
};

struct TaskMenuState {
    u8 pad[8];
    void *child;
};

struct CfgObj {
    u32 f00;
    u8  pad04[0x0c - 0x04];
    u32 f0c;
    u8  pad10[0x12 - 0x10];
    u16 f12;
    u8  pad14[0x18 - 0x14];
    struct Cfg *f18;
    u16 f1c;
    u16 f1e;
};

struct Anim {
    u32 obj;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
    u32 unk10_pos;
    u16 frame;
    u16 div;
    u8  unk14[4];
    u8  unk18_a[2];
    u32 ctx;
    u16 unk1c;
    u16 unk1e;
};

struct Obj_02028084 {
    u32 field_00;
    u32 pad_04[4];
    u16 field_14;
    u16 pad_16;
    u32 field_18;
};

struct Obj {
    u32 pad_00[2];
    u32 field_08;
    u32 pad_0c;
    u16 field_10;
    u16 pad_12;
    u32 flags;
};

struct T {
    u32 f00;
    u8  pad04[0x18];
    u16 f1c;
    u16 f1e;
};

typedef signed int     s32_0202846C;

typedef signed int     s32_02028470;

typedef int s32_02028484;

typedef struct Blk {
    u8  first;
    u8  pad[3];
    u32 flags;
} Blk;

extern void func_02082BCC(void *dst, int val, u32 n);
extern void func_02026490(void *obj, u32 value);
extern void MI_CpuFill8(void *dst, u8 value, u32 size);
extern u8 func_02012B58(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern int func_020084BC(const u16 *values);
extern void func_02008500(void *a, void *b);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void sub_02026504(struct Obj_1 *o, u32 id0, u32 id1, u32 v);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int  func_0203CD98(void);
extern int func_02012FCC(int p0);
extern u16 func_0200864C(const struct PlayTime *p);
extern void func_020272EC(s32 a);
extern void MI_CpuCopy8(const void *, void *, unsigned int);
extern void func_0217778C(void);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E394(void *p);
extern int   func_0200E44C(void *p, int i);
extern u32   func_02167394(u8 id);
extern u32   func_0200E3A4(void *p, u8 id);
extern u32 func_0200E49C(u8 *p, u32 a, u32 count);
extern void func_0200E460(char *p, int idx, int v);
extern void func_0200E4CC(u8 *a0, u32 a1, u32 a2, int a3);
extern void *func_0200C0F0(void *p);
extern int func_0200C33C(struct Blk34 *p, u32 i);
extern void func_0200C364(struct Blk34 *p, u8 i, int v);
extern void *func_0200E6E8(u32 a);
extern void  OS_GetOwnerInfo(OSOwnerInfo *info);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013CC8(u32 id);
extern u32 func_02013CE0(u32 id);
extern struct Rec1C *func_02012894(const struct BigObj *p);
extern u32 func_02166C7C();
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_0200C224(struct Blk34 *p);
extern u32 func_0200C1C4(struct Blk34 *p);
extern u32 func_0200C1DC(struct Blk34 *p);
extern u8 func_02008650(const struct PlayTime *p);
extern void *func_0200E3A0(void *p);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u16   func_02045A98(void);
extern u16  *func_020084F4(void *p);
extern u16 *func_0200C1F4(struct Blk34 *p);
extern u16 GX_GetBankForLCDC(void);
extern void sub_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern void func_02027230(u16 value);
extern void func_020271F8(u16 value);
extern u32 sub_02027060(u32 id);
extern void sub_02026FB8(void *queue);
extern int   func_02034AC4(signed int id);
extern int   func_021809D8(void);
extern void  func_02034A5C(int id);
extern void  sub_020274F8(void);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020307B0(void *p);
extern u32 func_0204162C(int channel);
extern void *func_02049EF4(void *arc, u32 id, u32 comp, void **out, u32 heap);
extern void  func_02082D44(void *dst, const void *src, u32 size);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void func_02027a24(struct Obj_020263B0 *o, struct Cfg *cfg);
extern u8 func_020355c4(void);
extern void func_02027b30(u32 a0, struct S *s, int mode);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02041B6C(u32 bit);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *p);
extern void func_02045374(struct Cfg *cfg);
extern u32  _u32_div_f(u32 a, u32 b);
extern u32   sub_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d,
                          u8 slot);
extern void sub_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045798(struct Descriptor *p, u8 v);
extern s32 sub_02061CA4(void *p, u32 a, u32 b, s32 size);
extern u8 func_020355C4(void);
extern u32  func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 id);
extern int  func_02035C08(const void *key);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void  func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern u32 sub_020307B0(void *p);
extern u32 sub_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_02035D20(u32 *x, u32 *y);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern void *func_020437D4(const struct Bmp *bmp);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 n);
extern u32 func_0201CE30(void *h);
extern void func_0201CE38(void *h);
extern void func_0201CE5C(struct Rec *p, s32_02028484 v);
extern int func_02035C60(void);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
void func_020263B0(struct Obj_0 *p, u32 a);
void func_020263D8(struct Comm *p, u32 a1, u32 a2);
void func_02026400(struct Comm *p);
void func_0202640C(struct Comm *p, u32 a, u32 b);
u32 sub_02026454(void *obj);
u32 sub_02026460(void *obj);
u32 sub_02026474(void *obj);
u32 sub_02026478(void *obj);
u32 sub_0202647C(void *obj);
void sub_02026480(void *obj, u32 value);
void sub_02026484(void *obj);
u32 sub_0202648C(void *obj);
void sub_02026490(void *obj, u32 value);
void sub_02026498(void *obj, u32 flag);
u32 sub_020264AC(void *obj);
void func_020264B4(void *p, int idx, u16 val0, u8 val3, u32 val4, int flag);
void func_020264F4(u8 *p);
void func_02026504(struct Obj_1 *o, u32 id0, u32 id1, u32 v);
int func_02026608(u8 *p, u8 *out);
void func_02026680(u8 *p);
void sub_020266AC(u32 a, u32 b, u32 c);
void sub_020266C0(u32 a, u32 b, u32 c);
void sub_020266D4(u32 a, u32 b);
void func_020266E0(u32 a0);
void func_02026728(void);
void func_020267BC(u32 a0);
void func_020267E4(void *p);
void func_020267FC(void);
void func_02026824(struct Obj_1 *o);
void func_0202685C(u8 *base, struct Req *r);
int func_02026A60(struct Req *r);
void *sub_02026BFC(u8 *base, int n);
void *sub_02026C1C(int n);
void *sub_02026C30(u8 *base, int n);
void *sub_02026C78(int n);
u32 sub_02026C8C(void);
int func_02026CA0(int *p);
void func_02026CE0(u32 n);
int sub_02026D04(const struct BeaconSlot *r);
u16 sub_02026D48(u16 v);
void func_02026D88(struct Rec_02026D88 *o, void *sys);
void func_02026FB8(Obj_0 *o);
u32 func_02027060(u32 a);
int func_0202708C(u16 v);
void func_020270AC(void *vec, u16 *dest);
u8 func_020270E0(void);
void func_02027100(const void *src);
void func_02027120(u8 a, u8 b);
void func_02027138(u32 x);
void func_0202715C(u32 a0);
void func_02027174(u32 x);
void func_02027198(void);
asm void OS_SetPrintBlockingMode(void);
void sub_020271F8(u16 value);
void sub_02027230(u16 value);
void sub_02027268(u16 value);
void sub_020272A4(u16 a, u16 b);
void sub_020272EC(u16 value);
void sub_02027324(u16 value);
void func_0202735C(u32 a0, u32 a1);
void func_0202737C(u32 *p, u32 a1, u32 a2);
void func_020273C4(char *p, unsigned short v);
void func_020273DC(char *p, unsigned short v);
void func_020273F8(char *p, unsigned short v);
void func_02027414(char *p, unsigned short v);
void func_02027430(char *p, unsigned short v);
void func_0202744C(void *dst);
void func_02027460(void *p, const struct Src_020263B0 *s);
void func_020274B4(u32 a0);
void func_020274C8(void);
void func_020274F8(void);
Obj_1 *func_0202751C(u32 heap, u32 a1);
void func_02027584(u8 *p);
u32 func_020275A8(u32 a);
u8 func_020275AC(u8 *p);
void func_020275B8(char *p, int v);
int func_020275C4(void *p);
void *func_020275D0(char *p);
int func_020275DC(void);
void func_020275E0(void);
u32 func_020275E4(void);
u32 func_020275E8(void);
u8 func_020275EC(int i);
u32 func_020275F8(u32 a);
u32 func_020275FC(u32 a);
u32 func_02027600(u32 a);
u8 func_02027604(u8 i);
u32 func_02027610(u32 a);
u32 func_02027614(void);
u32 func_02027618(void);
u32 func_0202761C(u32 a);
u32 func_02027620(u32 a);
u32 func_02027624(void);
u32 func_02027628(void);
u32 func_0202762C(void);
u32 func_02027630(void);
void func_02027634(void *arc, int id, u32 heap, int base, u32 pal);
u32 func_02027694(void);
u32 func_02027698(void);
u32 func_0202769C(u32 i);
u32 func_020276A0(u32 i);
u32 func_020276A4(void);
u32 func_020276A8(void);
u32 func_020276AC(u32 i);
u32 func_020276B0(u32 i);
u32 func_020276B4(void);
u32 func_020276B8(void);
u32 func_020276BC(u32 i);
u32 func_020276C0(u32 i);
int func_020276C4(int a0);
int func_02027710(int a);
int func_02027714(int a);
int func_02027718(int a);
int func_0202771C(int a);
int func_02027720(int a);
int func_0202772C(int a);
int func_02027738(int dummy, int b);
int func_02027740(int dummy, int b);
int func_02027748(void);
int func_0202774C(int a);
int func_02027750(int a);
int func_02027754(int a);
int func_02027758(void);
int func_0202775C(int a);
int func_02027760(int a);
int func_02027764(int a);
int func_02027768(void);
int func_0202776C(int a);
int func_02027770(int a);
int func_02027774(int a);
struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
struct TaskMenu *func_0202784C(struct TaskMenuTmpl *a0, void *a1);
void func_02027858(struct TaskMenu *m);
void func_020278F4(u8 *p);
void func_02027974(struct TaskMenu *p);
u32 func_020279E8(struct TaskMenu *m);
u8 func_02027A04(const u8 *p);
u32 func_02027A08(struct TaskMenu *tm, u32 arg);
unsigned func_02027A20(char *p);
void func_02027A24(struct Obj_020263B0 *o, struct Cfg *cfg);
u32 func_02027B30(u32 a0, struct S *s, int mode);
void func_02027B60(u16 *phase, u16 *out, u32 mode, u32 slot);
void func_02027BF4(u16 *phase, u16 *out, u16 mode, u32 slot, u16 c0, u16 c1);
int func_02027CD8(int a0, int a1);
void func_02027CFC(u8 *p, int sel);
void func_02027D44(struct Menu *m);
void func_02027E3C(u8 *m);
struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
u32 func_02027FD8(struct TaskMenuState *s);
u32 func_02027FEC(struct Cfg *a0, struct Src *a1, u16 a2, u16 a3, u8 a4, u16 a5);
u32 *func_0202800C(struct Cfg *a0, struct Src *a1, u16 a2, u16 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);
u32 *func_0202804C(struct Cfg *a0, struct Src *a1, u16 a2, u16 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);
struct CfgObj *func_02028084(struct Cfg *cfg, struct Src *src, u16 a2, u16 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 heap);
void func_02028148(u8 *p);
void func_0202815C(u8 *a0);
void func_02028164(u8 *p);
void func_02028178(u8 *p);
void func_02028218(struct Obj_02028084 *obj, u32 a);
void func_0202822C(char *p, int v);
u32 func_02028230(u8 *p);
u32 func_0202824C(void **p);
void func_020282A4(struct Obj *obj);
void func_020282AC(struct T *p, u16 *a1, u32 a2, u32 a3, u16 a4);
void func_020282D8(u32 bg, struct Cfg *cfg, u32 style);
void func_0202843C(u8 *p);
void func_02028454(u8 *p);
u32 func_0202846C(u8 *p);
void func_02028470(u8 *p, u32 v);
s32_02028484 func_02028484(Blk *blk, void *h);
u32 func_020284F4(u32 a);
u32 func_02028528(u32 a);
u32 func_0202855C(u32 a);
void func_02028590(u32 a0, u32 a1, u32 a2, u16 a3);
extern u8 g_0209FB74[];
extern struct BeaconSys *g_02146940;
extern char   g_020A74BC[];
extern char   g_020A74C0[];
extern u8 *d_02146940;
extern const u32 data_0209FC20[];
extern struct BeaconSys *g_GameBeacon;
extern const struct Prio g_0209FC20[];
extern u16 g_0209FC04[];
extern void * const volatile g_System;
extern char  ov231_id[];
extern const char sBeaconStatus42[];
extern const u8 d_0209FCF8[];
extern const u8 d_0209FCEC[];
extern char sFile_020A74E0[];
extern s16 tbl_020A1B38[];
extern char  g_020A74E0[];
extern char g_0209FD10[];













/*
 * Parked: every concrete byte is right; the only unresolved site is the
 * data table base 0x0209FB74, whose word has no witness outside this range
 * (`literal` has nothing to stand on, and no branch anywhere names it).
 */
void func_020263B0(struct Obj_0 *p, u32 a)
{
    if (p->f10 != 5) {
        Fn fn = *(Fn *)(g_0209FB74 + p->f5 * 0x1C);

        if (fn != 0) {
            fn(p->f14, p->f18, a);
        }
    }
}













/*
 * A whole translation unit, matched as one byte range.
 *
 * game_comm.c, 0x020263D8..0x02026454: start a request, the unlabelled
 * forwarding leaf func_02026400 (func_0202640C(p, 0, 0) as a pool-word tail
 * call), and the request update.  The byte at +4 of the comm object and of
 * its 8-byte sub-object at +0xC is a set of one-bit flags; every clear is a
 * `bics` and every set an `orrs`, which only bitfield stores give
 * (docs/families/game_comm.h).  func_020263D8 clears bit 1 between its two
 * plain stores: f14, bit, f05 is the one order whose flag load lands after
 * the f14 store (the other two schedule the f05 store first).
 *
 * Integrator: seed 0x02026400 (unlabelled follower, member of this unit).
 */
void func_020263D8(struct Comm *p, u32 a1, u32 a2)
{
    p->f14 = a2;
    p->b1 = 0;
    p->f05 = a1;
    p->f20 = 0;
    p->f1c = 0;
    func_02082BCC(&p->sub, 0, 8);
    func_020264F4((u8 *)p);
}













void func_02026400(struct Comm *p)
{
    func_0202640C(p, 0, 0);
}













void func_0202640C(struct Comm *p, u32 a, u32 b)
{
    if (*((u8 *)&p->sub + 4) == 2) {
        func_02026490(&p->sub, 3);
        p->f20 = a;
        p->f1c = b;
    } else if (*((u8 *)&p->sub + 4) < 2) {
        p->b0 = 1;
        p->f20 = a;
        p->f1c = b;
    } else {
        p->b1 = 1;
        if (p->f20 == 0) {
            p->f20 = a;
            p->f1c = b;
        }
    }
}
















/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0202647C, sub_02026480, sub_02026484, sub_0202648C
 *
 * Eight two-to-five-instruction accessors on one object, none of them
 * pushing a register: only the first is a real label in the generated
 * listing (a `func_starts` seed reached it some other way), and the other
 * seven print as `.word` runs between the two named functions this range
 * sits between, the same gap docs/idioms/unlabelled-leaf-functions-hide-
 * in-word-runs.md describes.
 *
 * sub_02026454 returns byte field +5 unconditionally: the original's
 * `bne`-around-a-redundant-`movs r0,#0` is what a plain `return v;`
 * compiles to when `v` is already known nonzero on one path, not a
 * guard. sub_02026460 is a genuine conjunction, `field5 != 0 &&
 * field0x10 != 2`, and only that phrasing (not two early-return `if`s)
 * produces the shared branch target both comparisons jump to
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 * The rest are plain word/byte getters and setters on fields +0x18, +0,
 * +6 and +8, one of them (sub_02026484) a "clear to zero" specialisation
 * of the setter that immediately follows it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02026454.c \
 *       --addr 0x02026454 --thumb
 */
u32 sub_02026454(void *obj)
{
    u8 v = *((u8 *)obj + 5);
    if (v != 0) {
        return v;
    }
    return 0;
}
















u32 sub_02026460(void *obj)
{
    if (*((u8 *)obj + 5) != 0 && *((u8 *)obj + 0x10) != 2) {
        return 1;
    }
    return 0;
}
















u32 sub_02026474(void *obj)
{
    return ((struct Obj17245 *)obj)->f18;
}
















u32 sub_02026478(void *obj)
{
    return ((struct Obj17246 *)obj)->f0;
}
















u32 sub_0202647C(void *obj)
{
    return *((u8 *)obj + 6);
}
















void sub_02026480(void *obj, u32 value)
{
    ((struct Obj17248 *)obj)->f8 = value;
}
















void sub_02026484(void *obj)
{
    ((struct Obj17249 *)obj)->f8 = 0;
}
















u32 sub_0202648C(void *obj)
{
    return ((struct Obj17250 *)obj)->f8;
}
















/*
 * A whole translation unit, matched as one byte range.
 *
 * The labelled sub_02026490 (8 bytes) is followed immediately by two more
 * unlabelled leaves reaching to the next real label at 0x020264B4, the
 * same shape as src/matched/unit_02026454.c just above it in the image.
 *
 * sub_02026490 sets byte field +4 to its argument and unconditionally
 * sets byte field +5 to 1. sub_02026498 and sub_020264AC are a
 * setter/getter pair on bit 2 of field +4: the setter narrows its 32-bit
 * argument to a byte before taking bit 0 of it
 * (`u8 f = (u8)flag;` is what produces the `lsls #0x18`/`lsrs #0x18`
 * truncation pair, not a mask, per the halfword-narrowing case in
 * docs/MATCHING.md), and the getter's `lsls #0x1d`/`lsrs #0x1f` pair is a
 * bitfield extraction rather than a type conversion (32 - 0x1d is 3, not
 * 8/16/32), which only reproduces from an actual bitfield member
 * declaration: docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02026490.c \
 *       --addr 0x02026490 --thumb
 */
void sub_02026490(void *obj, u32 value)
{
    *((u8 *)obj + 4) = value;
    *((u8 *)obj + 5) = 1;
}
















void sub_02026498(void *obj, u32 flag)
{
    u8 f = (u8)flag;
    u8 v = *((u8 *)obj + 4);

    v = (v & ~4) | ((f & 1) << 2);
    *((u8 *)obj + 4) = v;
}
















u32 sub_020264AC(void *obj)
{
    return ((struct Field4 *)((u8 *)obj + 4))->bit2;
}
















void func_020264B4(void *p, int idx, u16 val0, u8 val3, u32 val4, int flag)
{
    u8 *base = (u8 *)p + 0x24;
    u8 *elem = base + idx * 8;
    u16 old0;
    u8 old5;

    elem[4] = val4;
    old0 = *(u16 *)(base + idx * 8);
    if (old0 == val0 && elem[5] == val3) {
        return;
    }
    if (old0 != val0) {
        ((struct Obj04053 *)elem)->f2 = old0;
        ((struct Obj04053 *)elem)->f0 = val0;
    }
    old5 = elem[5];
    if (old5 == val3) {
        return;
    }
    elem[6] = old5;
    elem[5] = val3;
    if (!flag) {
        sub_020266C0((u32)p, idx, val3);
    }
}
















void func_020264F4(u8 *p)
{
    MI_CpuFill8(p + 0x24, 0, 0x18);
}
















/*
 * Push one entry onto the six-slot ring buffer that func_020261E4 built at
 * +0x3c of the sprite object (0xc bytes per slot, write cursor at +0x85,
 * fill count at +0x84).  Each of the two handle arguments is resolved
 * against the owner's current id: equal to it means the "self" handle
 * (func_02012944), otherwise the by-id lookup (func_02012950).  If either
 * handle is busy (func_020084BC == 1) the whole push is abandoned before
 * anything is written.
 */
void func_02026504(struct Obj_1 *o, u32 id0, u32 id1, u32 v)
{
    struct Ring *r;
    u32 h0;
    u32 h1;
    struct Slot *s;

    r = &o->ring;
    if (id0 == func_02012B58((void *)o->owner)) {
        h0 = (u32)func_02012944((void *)o->owner);
    } else {
        h0 = (u32)func_02012950((void *)o->owner, id0);
    }
    if (id1 == func_02012B58((void *)o->owner)) {
        h1 = (u32)func_02012944((void *)o->owner);
    } else {
        h1 = (u32)func_02012950((void *)o->owner, id1);
    }
    if (func_020084BC((const u16 *)h0) == 1) {
        return;
    }
    if (func_020084BC((const u16 *)h1) == 1) {
        return;
    }
    s = &r->slot[r->cursor];
    if (s->b0 == 1) {
        r->count = (u8)(r->count + 1);
    }
    s->f02 = (u8)id0;
    s->f00 = (u16)v;
    s->b0 = 1;
    func_02008500((void *)h0, (void *)s->f04);
    s->b1 = (u8)(u32)func_02008550((const struct Sub0200852CObj *)h0);
    func_02008500((void *)h1, (void *)s->f08);
    s->b2 = (u8)(u32)func_02008550((const struct Sub0200852CObj *)h1);
    r->cursor = (u8)(r->cursor + 1);
    if (r->cursor >= 6) {
        r->cursor = 0;
    }
    if (r->count >= 6) {
        r->count = 0;
    }
}













/*
 * EXACT*: the listing extent runs 164 bytes because the follower at
 * 0x0202667E is an unlabelled leaf (`movs r0, r0` / `bx lr`) that saves
 * nothing, so `disasm.py` never labels it.  Byte coverage ends at +0x76.
 *
 * Counted eight-entry bank: pop the next live 12-byte record at
 * base + base[0x48] * 12, publish it as the caller's 0x10-byte snapshot,
 * clear its live flag and advance the cursor with a wrap at six.
 *
 * The publish order is not the source order: the whole-word load of +0x04
 * lands before the `out[8] = 0` store, so the C has to store the word first
 * and the byte second to let the scheduler hoist the load into the store's
 * shadow.  Written with `out[8] = 0` first, the compiled order flips and
 * nine bytes differ.
 */
int func_02026608(u8 *p, u8 *out)
{
    u8 *base = p + 0x3c;
    Rec *r = (Rec *)(base + base[0x48] * 12);

    if (r->live == 0) {
        return 0;
    }
    func_02082BCC(out, 0, 0x10);
    ((struct Obj04054 *)out)->f0 = r->w4;
    out[8] = 0;
    out[0xa] = r->f1;
    ((struct Obj04054 *)out)->f4 = r->w8;
    out[9] = 1;
    out[0xb] = r->f2;
    ((struct Obj04054 *)out)->fC = r->h0;
    r->live = 0;
    base[0x48] = base[0x48] + 1;
    if (base[0x48] >= 6) {
        base[0x48] = 0;
    }
    return 1;
}














/*
 * Clears bit 0 of six 12-byte entries at +0x3F and the bytes at +0x85 and +0x84.
 * Caller: ov011 0x021731C8.
 */
void func_02026680(u8 *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        ((E *)(p + 0x3f))[i].b0 = 0;
    }
    p[0x85] = 0;
    p[0x84] = 0;
}














/*
 * A thin wrapper over `sub_02026504` (258 bytes, still open), forwarding
 * its three arguments unchanged and appending a fourth: 0x27 when the
 * second and third arguments are equal, 0x26 otherwise. The `? :` form,
 * not an `if`/`else` writing the call twice, is what reproduces the
 * single shared `lsls`/`lsrs #0x10` that narrows the chosen constant to
 * the callee's 16-bit fourth parameter after the branch instead of in
 * each arm.
 *
 * `sub_02026504`'s only three callers in the whole ARM9 image are this
 * function and its two siblings sub_020266C0 and sub_020266D4
 * (src/matched/sub_020266C0.c, src/matched/sub_020266D4.c). Keeping each
 * in its own translation unit is what gives the other two's calls
 * standing as outside evidence for this one; compiled together as a
 * single unit the three calls would attest only each other and the whole
 * range would cap at MATCH (docs/MATCHING.md, "the pairwise case across
 * two files").
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020266AC.c \
 *       --func sub_020266AC --addr 0x020266AC --cc 1.1p1 --thumb
 */
void sub_020266AC(u32 a, u32 b, u32 c)
{
    sub_02026504((struct Obj_1 *)a, b, c, (u16)((b == c) ? 0x27 : 0x26));
}














/*
 * The same wrapper shape as src/matched/sub_020266AC.c, with the constant
 * pair 0x1e/0x1d in place of 0x27/0x26. See that file's header for why it
 * is kept in its own translation unit rather than merged with its two
 * siblings.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020266C0.c \
 *       --func sub_020266C0 --addr 0x020266C0 --cc 1.1p1 --thumb
 */
void sub_020266C0(u32 a, u32 b, u32 c)
{
    sub_02026504((struct Obj_1 *)a, b, c, (u16)((b == c) ? 0x1e : 0x1d));
}














/*
 * The simplest of the three sub_02026504 wrappers: forwards its first
 * argument, repeats its second as both the second and third callee
 * argument, and appends the literal 0x1f. See
 * src/matched/sub_020266AC.c's header for why the three are kept as
 * separate files rather than one unit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020266D4.c \
 *       --func sub_020266D4 --addr 0x020266D4 --cc 1.1p1 --thumb
 */
void sub_020266D4(u32 a, u32 b)
{
    sub_02026504((struct Obj_1 *)a, b, b, 0x1f);
}














/*
 * Allocates the 0xbb4-byte beacon system block on the caller's heap and
 * publishes it through g_02146940, after releasing any previous one.
 *
 * The two spellings that decided it:
 *   - the third argument (1) is bound to a NAMED local `one`, which keeps
 *     it alive in the callee-saved r4 across the call to func_02030734;
 *     the trailing -1 store is then derived from it as `subs r2, r4, #2`.
 *     Written as a plain -1 / 0xff / (u8)-1, the compiler folds it to
 *     `movs r2, #0xff` before the call and the r4/r5 assignment flips.
 *   - 0xbb4 stays a plain integer literal: the compiler pools it of its
 *     own accord, so no absolute linker symbol is needed (an earlier
 *     attempt that declared it as `extern char sBeaconSize[]` produced
 *     the same 72 bytes but capped at MATCH on that unattestable ABS32).
 *
 * 0x020A74BC resolves through sole-ref; 0x020A74C0 is the __FILE__ string.
 */
void func_020266E0(u32 a0)
{
    u32 one = 1;

    if (g_02146940 != 0) {
        func_02034714(g_020A74BC, 0, g_020A74BC);
    }
    g_02146940 = func_02030734(a0, 0xbb4, one, g_020A74C0, 0x5a);
    ((char *)g_02146940)[0xbb4 - 7] = (u8)(one - 2);
}














void func_02026728(void)
{
    char *p;
    s32 v;
    s32 i;

    p = (char *)g_02146940;
    if (p == 0) {
        return;
    }
    if (func_0203CD98() == 0) {
        return;
    }
    if (((struct Obj06914 *)p)->f0 != 0) {
        v = func_0200864C((const struct PlayTime *)func_02012FCC(((struct Obj06914 *)p)->f0));
        if (((struct Obj06914 *)p)->fBB0 != v) {
            switch (v) {
            case 0xa:
            case 0x1e:
            case 0x32:
            case 0x64:
                func_020272EC(v);
                break;
            }
        }
        ((struct Obj06914 *)p)->fBB0 = (u16)v;
    }
    func_02026824((struct Obj_1 *)(p + 4));
    for (i = 0; i < 0x1e; i++) {
        if (*(u8 *)(p + i * 0x60 + 0x64) != 0) {
            if (*(u16 *)(p + i * 0x60 + 0xc0) < 0xffff) {
                *(u16 *)(p + i * 0x60 + 0xc0) += 1;
            }
        }
    }
}












void func_020267BC(u32 a0)
{
    u32 *p = (u32 *)g_02146940;

    *p++ = a0;
    func_02026D88((struct Rec_02026D88 *)p, (void *)a0);
    *(u16 *)((char *)g_02146940 + 0xbb0) =
        func_0200864C((const struct PlayTime *)func_02012FCC((int)((void *)a0)));
}












void func_020267E4(void *p)
{
    MI_CpuCopy8(d_02146940 + 4, p, 0x5C);
}












void func_020267FC(void)
{
    if (g_02146940->in.f5e == 1) {
        if (func_0203CD98() == 1) {
            func_0217778C();
            g_02146940->in.f5e = 0;
        }
    }
}












void func_02026824(struct Obj_1 *o)
{
    u16 n = ((struct Obj05716 *)o)->f30;

    if (n == 1) {
        return;
    }
    ((struct Obj05716 *)o)->f5C += 1;
    if ((u32)((struct Obj05716 *)o)->f5C > (data_0209FC20[n] >> 8)) {
        *(u16 *)&((struct Obj05716 *)o)->f5C = 0;
        ((struct Obj05716 *)o)->f30 = 1;
    }
}











static inline u32 calc(struct Req *r, int id)
{
    u32 v;
    if (id == 0x1d) {
        v = r->trainer / 10 + 1;
        if (v > func_02167394(id))
            v = func_02167394(id);
    } else {
        v = func_0200E3A4(r->f50, id);
    }
    return v;
}










/*
 * The ring insert: advance hi with a wrap at 30 (pushing lo along when the
 * ring is full), grant the record's items through the bag (0x0200E394
 * family), mark matching entries in the 0x0200C0F0 table, then clear the
 * slot, struct-copy the 92-byte payload in, zero +0x5c, set the live bit
 * and bump the +0xBAE fill count.
 *
 * `bl 0x02167394` sites are the only references to that address in the
 * whole image, all inside this range, and no overlay listing labels a
 * function there (ov009 and ov010 both cover the address, interior to
 * code), so no class attests it and no cut helps (--suggest-split).
 *
 * Two spellings the bytes need: the item-amount helper takes an INT id
 * (the `cmp r,#0x1d` is on the untruncated value; the callees' u8
 * parameters produce the lsls/lsrs at each call), and the slot is one
 * pointer `&slots[hi]` which the compiler keeps as base+0x64 and
 * hi*0x60 in two stack slots.
 */
void func_0202685C(u8 *base, struct Req *r)
{
    void *bag;
    void *sys;
    void *bag2;
    void *tbl;
    int i;
    int j;
    int id;
    u32 v;
    struct Rec *rec;

    (((struct Obj00747 *)base)->fBAD)++;
    if (((struct Obj00747 *)base)->fBAD >= 30)
        ((struct Obj00747 *)base)->fBAD = 0;

    rec = (struct Rec *)(base + 0x64) + ((struct Obj00747 *)base)->fBAD;
    if (((struct Obj00747 *)base)->fBAE > 0 && ((struct Obj00747 *)base)->fBAD == ((struct Obj00747 *)base)->fBAC) {
        (((struct Obj00747 *)base)->fBAC)++;
        if (((struct Obj00747 *)base)->fBAC >= 30)
            ((struct Obj00747 *)base)->fBAC = 0;
    }

    bag = func_0200E394(func_02012EBC(((struct Obj00747 *)base)->f0));
    for (i = 0; i < 3; i++) {
        id = func_0200E44C(bag, i);
        if (id != 0xff) {
            v = calc(r, id);
            if (v != 0 && func_0200E49C(bag, id, v) == 0) {
                func_0200E460(bag, id, 1);
                func_0200E4CC(bag, id, v, 1);
                ((struct Obj00747 *)base)->fBAF = 1;
            }
        }
    }

    sys = func_02012EBC(((struct Obj00747 *)base)->f0);
    bag2 = func_0200E394(sys);
    tbl = func_0200C0F0(sys);
    for (i = 0; i < 3; i++) {
        id = func_0200C33C(tbl, (u8)i);
        if (id != 0xff) {
            for (j = 0; j < 3; j++) {
                if (id == func_0200E44C(bag2, j)) {
                    if (calc(r, id) != 0)
                        func_0200C364(tbl, i, 1);
                }
            }
        }
    }

    MI_CpuFill8(rec, 0, 0x60);
    rec->p = *(struct Payload *)r;
    rec->f5c = 0;
    ((struct Obj00747 *)base)->fBA4 |= 1 << ((struct Obj00747 *)base)->fBAD;
    if (((struct Obj00747 *)base)->fBAE < 30)
        (((struct Obj00747 *)base)->fBAE)++;
}














/*
 * The duplicate/accept scan over the receive ring.  Closed 2026-09-23 by
 * writing the ring walk as the plain two-case shape: `if (lo <= hi)` one
 * loop over lo..hi, `else` a loop over lo..29 THEN a loop over 0..hi, each
 * hit doing `hit = 1; break;`.  The compiler itself cross-jumps loop 3's hit
 * block into loop 1's (both continue at the tail) and keeps loop 2's, whose
 * break lands on loop 3's `i = 0`; the earlier goto/label construction in
 * docs/notes/func_02026A60.c.txt only imitated that and left a duplicated
 * `blt`.  EXACT* because the follower at 0x02026BFC has no label.
 */
int func_02026A60(struct Req *r)
{
    u8 *base = (u8 *)g_GameBeacon;
    int hit = 0;
    int i;
    u16 kind;
    signed char hi;
    signed char lo;

    if ((r->f00 & 2) == 0) {
        return hit;
    }

    kind = r->f30;
    if (kind == 0 || kind >= 0x33) {
        return 0;
    }

    if (kind == 0x18) {
        if (((struct Obj00747 *)base)->f14 != r->f46) {
            return hit;
        }
    }

    hi = ((struct Obj00747 *)base)->fBAD;
    lo = ((struct Obj00747 *)base)->fBAC;

    if (lo <= hi) {
        for (i = lo; i <= hi; i++) {
            if (r->f10 == *(u16 *)(base + i * 0x60 + 0x74)) {
                if (kind == 1 ||
                    ((r->f08 << 10) >> 27) == ((*(u32 *)(base + i * 0x60 + 0x6c) << 10) >> 27)) {
                    return 0;
                }
                hit = 1;
                break;
            }
        }
    } else {
        for (i = lo; i < 0x1e; i++) {
            if (r->f10 == *(u16 *)(base + i * 0x60 + 0x74)) {
                if (kind == 1 ||
                    ((r->f08 << 10) >> 27) == ((*(u32 *)(base + i * 0x60 + 0x6c) << 10) >> 27)) {
                    return 0;
                }
                hit = 1;
                break;
            }
        }
        for (i = 0; i <= hi; i++) {
            if (r->f10 == *(u16 *)(base + i * 0x60 + 0x74)) {
                if (kind == 1 ||
                    ((r->f08 << 10) >> 27) == ((*(u32 *)(base + i * 0x60 + 0x6c) << 10) >> 27)) {
                    return 0;
                }
                hit = 1;
                break;
            }
        }
    }

    if (kind == 0x19) {
        if (r->f3C != 0x2932013A) return 0;
    } else if (kind == 0x1A) {
        if (r->f3C != 0x48841DC1) return 0;
    } else if (kind == 0x1B) {
        if (r->f3C != 0x701DDC92) return 0;
    } else if (kind == 0x32) {
        if (r->f3C != 0xFEE48201) return 0;
    }

    if (hit == 1) {
        u32 off = i * 0x60;
        *(struct Payload *)(base + off + 0x64) = *(struct Payload *)r;
        *(u16 *)(base + off + 0xC0) = 0;
        ((struct Obj00747 *)base)->fBA4 |= (u32)(1 << i);
    } else {
        func_0202685C(base, r);
        ((struct Obj00747 *)base)->fBA8 = ((struct Obj00747 *)base)->fBA8 + 1;
    }
    return 1;
}
















/*
 * Five unlabelled leaves between func_02026A60 and func_02026CA0
 * (0x02026BFC..0x02026CA0), tu-verified: two ring-slot accessors, their
 * g_GameBeacon tail-call wrappers, and the +0xBA8 count getter.
 *   sub_02026BFC  slot n of the ring if n is below the s8 at +0xBAE
 *   sub_02026C1C  sub_02026BFC(g_GameBeacon, n)
 *   sub_02026C30  the slot n records back from the hi cursor, wrapped at 30;
 *                 the zero test on count - n is `c - n == 0` (a `subs`),
 *                 not `c == n` (a `cmp`)
 *   sub_02026C78  sub_02026C30(g_GameBeacon, n)
 *   sub_02026C8C  the +0xBA8 insert count
 * None has an lr save, so the integrator should seed all five starts.
 */
void *sub_02026BFC(u8 *base, int n)
{
    int c = ((struct Obj17251 *)base)->fBAE;
    if (c == 0 || c - n <= 0)
        return 0;
    return base + 0x64 + n * 0x60;
}
















void *sub_02026C1C(int n)
{
    return sub_02026BFC((u8 *)g_GameBeacon, n);
}
















void *sub_02026C30(u8 *base, int n)
{
    u32 c = ((struct Obj11840 *)base)->fBA8;
    int j;
    if (c == 0 || c - n == 0)
        return 0;
    j = ((struct Obj11840 *)base)->fBAD - (int)(c - 1 - n);
    if ((j < 0 ? -j : j) >= 30)
        return 0;
    if (j < 0)
        j += 30;
    return base + 0x64 + j * 0x60;
}
















void *sub_02026C78(int n)
{
    return sub_02026C30((u8 *)g_GameBeacon, n);
}
















u32 sub_02026C8C(void)
{
    return g_GameBeacon->field_BA8;
}
















int func_02026CA0(int *p)
{
    int i = *p;

    while (i < 0x1e) {
        if (g_02146940->mask & (1 << i)) {
            *p = *p + 1;
            return *p - 1;
        }
        i = *p + 1;
        *p = i;
    }
    return 0x1e;
}














/*
 * Clears bit `n` of the ring live mask at +0xba4 of the game beacon block.
 * The earlier MATCH park read the pool word as 0x02021440; the word at
 * 0x02026CFC is 0x02146940, g_GameBeacon, attested by 77 other pools.
 * EXACT* because the follower at 0x02026D04 is an unlabelled leaf.
 */
void func_02026CE0(u32 n)
{
    g_GameBeacon->mask = ((1 << n) ^ 0xffffffff) & g_GameBeacon->mask;
}













/*
 * Finds the ring slot whose +0x10 id equals the record's, sets its live-mask
 * bit and answers 1; 0 when none does.
 * Unlabelled leaf (no lr save): the integrator should seed 0x02026D04 into
 * layout/function_starts.txt.
 */
int sub_02026D04(const struct BeaconSlot *r)
{
    struct BeaconSys *g = g_GameBeacon;
    int i;
    for (i = 0; i < 30; i++) {
        if (r->f10 == g->slot[i].f10) {
            g->mask |= 1 << i;
            return 1;
        }
    }
    return 0;
}













/*
 * Answers the +0x5c halfword of the first live ring slot whose +0x10 id
 * equals v, or 0xffff.
 * Unlabelled leaf (no lr save): the integrator should seed 0x02026D48 into
 * layout/function_starts.txt.
 */
u16 sub_02026D48(u16 v)
{
    struct BeaconSys *g = g_GameBeacon;
    int i;
    for (i = 0; i < 30; i++) {
        if (g->slot[i].b00 != 0 && g->slot[i].f10 == v)
            return g->slot[i].f5c;
    }
    return 0xffff;
}













/*
 * The own-beacon builder: fills a BeaconRec from the player profile, the
 * save blocks and the DS owner info.  Layout it proves beyond the family
 * header: word +0 is four BYTES (+0 = 0xff, +1/+2 from 0x0200856C and
 * 0x02008570, +3 split 7:1 as u8 bitfields -- strb/ldrb, not word RMW);
 * word +0xC is 6:3:3:4:10:6 (bits 0..5 = 0x15, 6..8 from 0x02008554,
 * 9..11 from 0x0200C224, 12..15 the owner's favoriteColor, then the
 * trainer and top fields); +0x12 is seven halfwords filled like +0x20;
 * +0x50 takes ten bytes via MI_CpuCopy8; the scratch at sp+0x14 is the
 * 0x54-byte OSOwnerInfo.  Levers that mattered: stack order (save, tbl,
 * bag declared in that order) and func_02008550 answering a word that is
 * narrowed with an explicit (u8) before the 1-bit store.
 */
void func_02026D88(struct Rec_02026D88 *o, void *sys)
{
    void *save;
    void *tbl;
    void *bag;
    void *prof;
    void *st;
    struct Src_020263B0 src;
    OSOwnerInfo info;
    u16 *q;
    u16 v;
    int i;

    prof = func_02012944(sys);
    save = func_02012EBC(sys);
    tbl = func_0200C0F0(save);
    bag = func_0200E6E8((u32)save);
    OS_GetOwnerInfo(&info);

    o->b00 = 0xff;
    o->mode = func_02012AC8(func_020127A4(sys));
    if ((int)func_02013CC8((u16)o->mode) == 1 || (int)func_02013CE0((u16)o->mode) == 1) {
        o->mode = ((struct Obj15760 *)((u8 *)func_02012894(sys)))->f4;
    }
    o->f08hi = func_02166C7C(sys, (u16)o->mode);
    o->b03lo = 0x30;
    o->f10 = func_02008534(prof);
    o->c12 = info.favoriteColor;
    o->b03hi = (u8)(u32)func_02008550(prof);
    if (o->b03hi == 0) {
        o->c6 = func_02008554(prof);
    } else {
        o->c6 = func_02008554(prof) - 8;
    }
    o->c0 = 0x15;
    o->f04hi = 2;
    o->b01 = func_0200856C(prof);
    o->b02 = func_02008570(prof);
    o->c9 = func_0200C224(tbl);
    o->peer = func_0200C1C4(tbl);
    o->id = func_0200C1DC(tbl);
    st = (void *)func_02012FCC((int)sys);
    o->trainer = func_0200864C(st);
    o->f0chi = func_02008650(st);
    MI_CpuCopy8(func_0200E3A0(func_0200E394(save)), o->f50, 10);
    func_0200E6FC(bag, 0, (struct Rec0200E6FC *)(&src));
    func_020274B4((u32)(&src));
    v = func_02045A98();
    q = func_020084F4(prof);
    for (i = 0; i < 7; i++) {
        o->f12[i] = q[i];
        if (v == q[i])
            break;
    }
    q = func_0200C1F4(tbl);
    for (i = 0; i < 8; i++) {
        o->vec[i] = q[i];
        if (v == q[i])
            break;
    }
    func_0202744C(o);
    o->f30 = 0;
}


















void func_02026FB8(Obj_0 *o)
{
    void *a;
    void *b;

    a = func_02012EBC((void *)g_02146940->f00);
    b = (void *)func_02012FCC((int)((void *)g_02146940->f00));
    a = func_0200C0F0(a);
    o->f0c = func_0200864C(b);
    o->f0chi = func_02008650(b);
    o->f08 = func_0200C1C4(a);
    o->f04 = func_0200C1DC(a);
    o->f08b = o->f08b + 1;
    o->f5c = 0;
    o->f5e = 1;
}


















/*
 * The priority gate: answers 1 when id `a`'s priority is at least that of
 * the current mode at +0x34 of the block.  The table at 0x0209FC20 is a
 * word of BITFIELDS, { prio : 8; frames : 24; } -- func_02026824 reads the
 * same word `>> 8`.  Spelled as `(u8)tbl[i]` on a u32 array the compiler
 * ties the lsrs order to the cmp order and stays 4 bytes out (see
 * docs/notes/pkt_02027060.func_02027060.c.txt); the bitfield read frees
 * the schedule.  Also EXACT under ../2.0/sp2.
 */
u32 func_02027060(u32 a)
{
    if (g_0209FC20[a].prio >= g_0209FC20[g_GameBeacon->in.f30].prio)
        return 1;
    return 0;
}


















int func_0202708C(u16 v)
{
    u32 i = 0;

    while (i < 0xe) {
        if (v == g_0209FC04[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}


















void func_020270AC(void *vec, u16 *dest)
{
    u16 buf[12];
    u16 stamp;
    int i;

    stamp = GX_GetBankForLCDC();
    sub_02045A38(vec, buf, 12);

    for (i = 0; i < 10; i++) {
        dest[i] = buf[i];
        if (stamp == buf[i]) {
            break;
        }
    }
}


















u8 func_020270E0(void)
{
    struct BeaconSys *ptr = g_02146940;
    u8 ret;

    if (ptr == 0) {
        return 0;
    }

    ret = ptr->field_BAF;
    ptr->field_BAF = 0;
    return ret;
}


















void func_02027100(const void *src)
{
    struct Inner *in = &g_02146940->in;

    MI_CpuCopy8(src, in->field_50, 10);
    in->f5e = 1;
}
















/*
 * 20 bytes. Stores two bytes at +5 and +6 of the block that g_02146940 points
 * to and sets the flag byte at +0x62 (reached as +4 then +0x5E: a nested
 * record at +4, written through a pointer local `q = &s->sub`; direct
 * `s->sub.flag` folds to +0x62). Filed in wave D6 as the unlabelled leaf that ov219
 * func_02183D14 calls.
 */
void func_02027120(u8 a, u8 b)
{
    struct Inner *in = &g_02146940->in;

    in->f01 = a;
    in->f02 = b;
    in->f5e = 1;
}















/*
 * Unlabelled Thumb leaf in the ARM9 module: inserts three bits (9..11) into
 * the word at +0x10 of the nested object at +4, then sets the byte at +0x62.
 * The inner-object pointer is what pins the two-step `adds r0, r1, #4` /
 * `adds r0, #0x5e` address form (see func_0202715C).
 *
 * Addresses are Black-image addresses.
 */
void func_02027138(u32 x)
{
    struct Inner *in = &g_02146940->in;

    in->f0c = (in->f0c & 0xFFFFF1FFu) | ((x << 29) >> 20);
    in->f5e = 1;
}














/*
 * EXACT*: the listing extent runs 60 bytes to the next label; only the
 * first 24 bytes belong to this function (the follower at 0x02027174 is
 * an unlabelled leaf).
 *
 * The original splits the address arithmetic into `adds r0, r4, #4` then
 * `adds r0, #0x5e`, which a flat `*(u8 *)(p + 0x62)` folds into one
 * `adds r4, #0x62`.  Taking a pointer to a NESTED struct member (the
 * inner object starts at +4) before the call is what pins the two-step
 * form: `&g->in` is its own value, materialised at +0x0A, and the field
 * offset is added separately at +0x0E.
 */
void func_0202715C(u32 a0)
{
    struct Inner *in = &g_02146940->in;

    func_020274B4(a0);
    in->f5e = 1;
}













/*
 * Unlabelled Thumb leaf in the ARM9 module: inserts three bits (6..8) into the
 * word at +0x10 of the nested object at +4, then sets the byte at +0x62.
 * Pairs with func_02027138; the inner-object pointer pins the two-step
 * address form (see func_0202715C).
 *
 * Addresses are Black-image addresses.
 */
void func_02027174(u32 x)
{
    struct Inner *in = &g_02146940->in;

    in->f0c = (in->f0c & 0xFFFFFE3Fu) | ((x << 29) >> 23);
    in->f5e = 1;
}













void func_02027198(void)
{
    struct BeaconSys *g = g_02146940;
    struct Inner *in;
    u16 *q;
    u32 v;
    u32 t;
    int i;

    in = &g->in;
    t = (u32)func_0200C0F0(func_02012EBC((void *)g->f00));
    v = func_02045A98();
    q = func_0200C1F4((struct Blk34 *)t);
    for (i = 0; i < 8; i++) {
        in->arr[i] = q[i];
        if (q[i] == v) {
            break;
        }
    }
    in->f5e = 1;
}












asm void OS_SetPrintBlockingMode(void)
{
    push {r4, lr}
    add r4, r0, #0
    bl func_0202708C
    cmp r0, #0
    beq loc_020271F0
    add r0, r4, #0
    bl func_02027230
    pop {r4, pc}
loc_020271F0:
    add r0, r4, #0
    bl func_020271F8
    pop {r4, pc}
}














static void sub_02027220(void *dst, u16 value);














/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02027268, sub_02027290, sub_020272A4, sub_020272D0,
 *           sub_020272EC, sub_02027314, sub_02027324, sub_0202734C
 *
 * Six checker/trampoline pairs, one per numeric event id (0xe, 0xf, 0x10,
 * 0x11, 0x14, 0x23), all working the same event-queue object obtained as
 * `g_System + 4`. Every checker has the same shape: ask
 * `sub_02027060(id)` (a priority gate against the object's current mode,
 * not itself in this packet) whether the id is allowed to run right now,
 * and if so, forward the caller's argument(s) into the queue object
 * through the matching trampoline and then hand the queue object to
 * `sub_02026FB8` (the dispatcher, also outside this packet). The queue
 * object is re-read from `g_System` between the trampoline call and the
 * dispatch call rather than kept in a register, because the compiler
 * cannot see across those two calls that the global does not change: this
 * is only reproduced by declaring `g_System` `volatile`, which is exactly
 * the case docs/idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md
 * records.
 *
 * The trampolines write the event id to +0x30 of the queue object and, in
 * four of the six (0xe, 0xf, 0x14, 0x23), a single 16-bit argument to
 * +0x32 or +0x34 before tail-calling the shared `func_0202744C`, which
 * marks the object "pending" independently of which id was just set. The
 * 0x10 trampoline instead tail-calls `func_020270AC(value, dst+0x34)`
 * directly, skipping `func_0202744C`; sub_020272A4/sub_020272D0 (id 0x11)
 * takes two arguments and does both: it stores the first at +0x32,
 * forwards the second to `func_020270AC(b, dst+0x34)`, and then also
 * calls `func_0202744C`. `func_020270AC` and `sub_02026FB8` are themselves
 * open in this packet's neighbour pkt_02026250, so they are left as
 * unresolved externs here and attest through the whole-image `label`
 * class, since both are called from more places than just this unit.
 *
 * All twelve functions, 356 bytes, one contiguous run with no gap: the
 * trampoline of one pair ends exactly where the checker of the next
 * begins. 31 of 31 relocations resolve (`local` for the intra-file calls,
 * `label` for sub_02027060/sub_02026FB8/func_020270AC/func_0202744C, and
 * `literal` for g_System, which is loaded from the pool at least 26 times
 * elsewhere in the ARM9 image).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020271F8.c \
 *       --addr 0x020271F8 --thumb
 */
void sub_020271F8(u16 value)
{
    if (sub_02027060(0xe)) {
        void *queue = (char *)g_System + 4;
        sub_02027220(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}














static void sub_02027220(void *dst, u16 value)
{
    ((struct Obj00121 *)dst)->f30 = 0xe;
    ((struct Obj00121 *)dst)->f32 = value;
    func_0202744C(dst);
}














static void sub_02027258(void *dst, u16 value);














void sub_02027230(u16 value)
{
    if (sub_02027060(0xf)) {
        void *queue = (char *)g_System + 4;
        sub_02027258(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}














static void sub_02027258(void *dst, u16 value)
{
    ((struct Obj00121 *)dst)->f30 = 0xf;
    ((struct Obj00121 *)dst)->f32 = value;
    func_0202744C(dst);
}














static void sub_02027290(void *dst, u16 value);














void sub_02027268(u16 value)
{
    if (sub_02027060(0x10)) {
        void *queue = (char *)g_System + 4;
        sub_02027290(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}














static void sub_02027290(void *dst, u16 value)
{
    ((struct Obj17252 *)dst)->f30 = 0x10;
    func_020270AC((void *)value, (u16 *)((char *)dst + 0x34));
}














static void sub_020272D0(void *dst, u16 a, u16 b);














void sub_020272A4(u16 a, u16 b)
{
    if (sub_02027060(0x11)) {
        void *queue = (char *)g_System + 4;
        sub_020272D0(queue, a, b);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}














static void sub_020272D0(void *dst, u16 a, u16 b)
{
    ((struct Obj00121 *)dst)->f30 = 0x11;
    ((struct Obj00121 *)dst)->f32 = a;
    func_020270AC((void *)b, (u16 *)((char *)dst + 0x34));
    func_0202744C(dst);
}














static void sub_02027314(void *dst, u16 value);














void sub_020272EC(u16 value)
{
    if (sub_02027060(0x14)) {
        void *queue = (char *)g_System + 4;
        sub_02027314(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}














static void sub_02027314(void *dst, u16 value)
{
    ((struct Obj00121 *)dst)->f30 = 0x14;
    ((struct Obj00121 *)dst)->f34 = value;
    func_0202744C(dst);
}














static void sub_0202734C(void *dst, u16 value);














void sub_02027324(u16 value)
{
    if (sub_02027060(0x23)) {
        void *queue = (char *)g_System + 4;
        sub_0202734C(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}














static void sub_0202734C(void *dst, u16 value)
{
    ((struct Obj00121 *)dst)->f30 = 0x23;
    ((struct Obj00121 *)dst)->f34 = value;
    func_0202744C(dst);
}














void func_0202735C(u32 a0, u32 a1)
{
    func_0202737C((u32 *)&g_02146940->in, a0, a1);
    g_02146940->in.f5e = 1;
}














void func_0202737C(u32 *p, u32 a1, u32 a2)
{
    p[1] = (p[1] & 0xf801ffff) | ((a1 & 0x3ff) << 17);
    p[2] = (p[2] & 0x003fffff) | (func_02166C7C(a2) << 22);
    ((struct Obj00121 *)p)->f48 = (((struct Obj00121 *)p)->f48 & ~0xff) | 5;
    func_0202744C(p);
}














/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void func_020273C4(char *p, unsigned short v)
{
    ((F *)(p + 0x48))->lo = 0;
    ((struct Obj15763 *)p)->f4E = v;
}














void func_020273DC(char *p, unsigned short v)
{
    ((struct Obj05717 *)p)->f48 = (((struct Obj05717 *)p)->f48 & ~0xff) | 1;
    ((struct Obj05717 *)p)->f4E = v;
}














void func_020273F8(char *p, unsigned short v)
{
    ((struct Obj05718 *)p)->f48 = (((struct Obj05718 *)p)->f48 & ~0xff) | 2;
    ((struct Obj05718 *)p)->f4E = v;
}














void func_02027414(char *p, unsigned short v)
{
    ((struct Obj05719 *)p)->f48 = (((struct Obj05719 *)p)->f48 & ~0xff) | 3;
    ((struct Obj05719 *)p)->f4E = v;
}














void func_02027430(char *p, unsigned short v)
{
    ((struct Obj05720 *)p)->f48 = (((struct Obj05720 *)p)->f48 & ~0xff) | 4;
    ((struct Obj05720 *)p)->f4E = v;
}














/*
 * Sets the low byte of the halfword at +0x48 of its argument to the
 * constant 5, leaving the high byte untouched. Called from every
 * trampoline of src/matched/unit_020271F8.c as a shared "mark this event
 * object pending" step, independent of which event id was just written.
 *
 * `disasm.py` measures this function's extent to the next label at
 * 0x020274B4, 104 bytes away, but only the first 20 bytes belong to it;
 * what follows is a second, unlabelled function (the same
 * "half the accessors are printed as .word data" gap
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md describes)
 * that packs several bitfields of the same object from a small argument
 * struct. It is out of scope for this file and still open. The mismatched
 * extent is why this entry is EXACT* rather than EXACT.
 *
 * Writing the mask as `~0xffu` rather than building 0xff00 directly is
 * what keeps the mask in the `movs r1, #0xff` / `bics r2, r1` shape the
 * original uses; the equivalent `& 0xff00` immediate has no Thumb
 * encoding and this compiler rematerialises it as `lsls`/`ands` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202744C.c \
 *       --func func_0202744C --addr 0x0202744C --cc 1.1p1 --thumb
 */
void func_0202744C(void *dst)
{
    u16 v = ((struct Obj00121 *)dst)->f48;

    v = (v & ~0xffu) | 5;
    ((struct Obj00121 *)dst)->f48 = v;
}














/*
 * Copies four halfwords into the console's own beacon record (+4 of the
 * block): two BITFIELDS of the u16 at rec+0x48 (bits 8..10 and 11..15,
 * masks 0xF8FF / 0x07FF, the low byte being the one func_0202744C sets),
 * then rec+0x4a and rec+0x4c.  The caller func_020274B4 passes &own in r0
 * but this body ignores it and recomputes; the two-step `adds r,r0,#4;
 * adds r,#0x48` at every access is a pointer local `o = &g->own`, not a
 * held `g` (which folds to one `adds #0x4c`).
 * Unlabelled leaf (no lr save): the integrator should seed 0x02027460.
 */
void func_02027460(void *p, const struct Src_020263B0 *s)
{
    struct Inner *o = &g_GameBeacon->in;

    o->a = s->a;
    o->b = s->b;
    o->f4a = s->c;
    o->f4c = s->d;
}













void func_020274B4(u32 a0)
{
    func_02027460((char *)g_02146940 + 4, (const struct Src_020263B0 *)a0);
}













/*
 * note:     wave 17 (overlay_id class): EXACT*. The pooled overlay-id site
 *           ov231_id (231) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * The ABS32 pool word 0x000000E7 is an absolute overlay-id symbol (ov231,
 * matching the bl into func_021809D8 in asm/overlays/ov231.s), per
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 * EXACT* because the listing extent (84 bytes) runs over the follower
 * sub_020274F8.
 */
void func_020274C8(void)
{
    int r;

    func_02034AC4((int)ov231_id);
    r = func_021809D8();
    func_02034A5C((int)ov231_id);
    if (r == 0) {
        func_02005624((u32)sub_020274F8, 0, 3);
    }
}














void func_020274F8(void)
{
    if (g_02146940 != 0) {
        g_02146940->mask = 0;
        g_02146940->in.f5e = 0;
        g_02146940->mask = 0;
    }
}














Obj_1 *func_0202751C(u32 heap, u32 a1)
{
    Obj_1 *p;
    void *arc;
    void *msg;
    u16 buf[10];

    p = (Obj_1 *)func_02030734(heap, 0xb10, 1, sBeaconStatus42, 42);
    p->fb08 = func_020457B0(9, heap);
    arc = func_02045B38(0, 2, 8, a1);
    msg = func_02045EC0(arc, 0x11);
    func_02045A38(msg, buf, 9);
    func_02045924(p->fb08, buf);
    func_02045808(msg);
    func_02045C04(arc);
    return p;
}














/*
 * Releases the +0xB08 handle, zeroes 0xB10 bytes and frees the object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027584.c \
 *       --func func_02027584 --addr 0x02027584 --thumb --cc 1.1p1
 */
void func_02027584(u8 *p)
{
    func_02045808((struct U16Vec *)(((struct Obj15764 *)p)->fB08));
    func_02082BCC(p, 0, 0xb10);
    func_020307B0(p);
}














/*
 * Unlabelled arm9 leaf. Filed as the relocation witness for ov032 (wave D2).
 */
u32 func_020275A8(u32 a) { return a; }














u8 func_020275AC(u8 *p) { return p[0xb0e]; }














void func_020275B8(char *p, int v) { p[0xb0e] = v; }













/*
 * Unlabelled arm9 leaf reading the word at +0xB08. Filed as the relocation
 * witness for ov021 func_021CD3A4 (wave A1).
 */
int func_020275C4(void *p)
{
    return ((struct Obj15765 *)p)->fB08;
}













void *func_020275D0(char *p) { return p + 0xb0c; }







/*
 * Witness leaf for ov119 callers (func_021DCD38, func_021DCF24).
 */
int func_020275DC(void)
{
    return 0;
}






void func_020275E0(void)
{
}













/*
 * Returns the constant 0x53.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020275E4.c \
 *       --func func_020275E4 --addr 0x020275E4 --thumb --cc 1.1p1
 */
u32 func_020275E4(void)
{
    return 0x53;
}













/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020275E8.c \\
 *       --func func_020275E8 --addr 0x020275E8 --thumb --cc 1.1p1
 */
u32 func_020275E8(void)
{
    return 0x21;
}













/*
 * note: byte lookup in a u8 table; called from ov094 func_02204CC0 (bl at
 *   +0x1EE, 0x02204EAE) with a u8 index.
 */
u8 func_020275EC(int i)
{
    return d_0209FCF8[i];
}













/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020275F8.c \\
 *       --func func_020275F8 --addr 0x020275F8 --thumb --cc 1.1p1
 */
u32 func_020275F8(u32 a)
{
    return a + 0x22;
}













/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020275FC.c \\
 *       --func func_020275FC --addr 0x020275FC --thumb --cc 1.1p1
 */
u32 func_020275FC(u32 a)
{
    return a + 0x3b;
}













/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027600.c \\
 *       --func func_02027600 --addr 0x02027600 --thumb --cc 1.1p1
 */
u32 func_02027600(u32 a)
{
    return a + 0x3e;
}












/*
 * note: byte lookup in a u8 table; called from ov070, ov131 and ov198.
 */
u8 func_02027604(u8 i)
{
    return d_0209FCEC[i];
}












/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027610.c \\
 *       --func func_02027610 --addr 0x02027610 --thumb --cc 1.1p1
 */
u32 func_02027610(u32 a)
{
    return a + 0x38;
}












/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027614.c \\
 *       --func func_02027614 --addr 0x02027614 --thumb --cc 1.1p1
 */
u32 func_02027614(void)
{
    return 0x13;
}












/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027618.c \\
 *       --func func_02027618 --addr 0x02027618 --thumb --cc 1.1p1
 */
u32 func_02027618(void)
{
    return 0x14;
}












/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202761C.c \\
 *       --func func_0202761C --addr 0x0202761C --thumb --cc 1.1p1
 */
u32 func_0202761C(u32 a)
{
    return a + 0x15;
}












/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027620.c \\
 *       --func func_02027620 --addr 0x02027620 --thumb --cc 1.1p1
 */
u32 func_02027620(u32 a)
{
    return a + 0x18;
}












/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027624.c \\
 *       --func func_02027624 --addr 0x02027624 --thumb --cc 1.1p1
 */
u32 func_02027624(void)
{
    return 0x1b;
}












/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027628.c \\
 *       --func func_02027628 --addr 0x02027628 --thumb --cc 1.1p1
 */
u32 func_02027628(void)
{
    return 0x1c;
}











/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202762C.c \\
 *       --func func_0202762C --addr 0x0202762C --thumb --cc 1.1p1
 */
u32 func_0202762C(void)
{
    return 0x1d;
}











/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027630.c \\
 *       --func func_02027630 --addr 0x02027630 --thumb --cc 1.1p1
 */
u32 func_02027630(void)
{
    return 0x1e;
}











/*
 *           func_020276A0, func_020276A4, func_020276A8, func_020276AC,
 *           func_020276B0, func_020276B4, func_020276B8, func_020276BC,
 *           func_020276C0
 * beacon_status.c, 0x02027634..0x020276C4: load the beacon status palette,
 * copy its 0x60 colours into the archive's copy and re-base each entry
 * (colour index + base, palette number in the top nibble), then twelve
 * unlabelled 4-byte resource-id getters in groups of four (two constants,
 * two offsets of their argument).
 *
 * What closed the loader after docs/notes/pkt_02027634.c.txt (100 bytes
 * against 96): the palette is a u16[0x60] FIELD at +0x540 of one struct
 * type, and the archive data is that same struct 0xC bytes into the file;
 * with both written as `->pal` the offset 0x540 is one constant kept in r7
 * and the +0xC is added on its own, which is the image.  The re-base is
 * `(pal << 12) + (base + (c & 0xfff))`.
 *
 * Integrator: seed the twelve leaves 0x02027694..0x020276C0 (members).
 */
void func_02027634(void *arc, int id, u32 heap, int base, u32 pal)
{
    struct BeaconGfx *g;
    void *data;
    void *h;
    int i;

    g = (struct BeaconGfx *)func_0204162C(id);
    h = func_02049EF4(arc, 0x1d, 0, &data, heap);
    func_02082D44(((struct BeaconGfx *)((u8 *)data + 0xc))->pal, g->pal, 0xc0);
    func_020307B0(h);
    for (i = 0; i < 0x60; i++)
        g->pal[i] = (pal << 12) + (base + (g->pal[i] & 0xfff));
}











u32 func_02027694(void)
{
    return 0x42;
}











u32 func_02027698(void)
{
    return 0x41;
}











u32 func_0202769C(u32 i)
{
    return i + 0x43;
}











u32 func_020276A0(u32 i)
{
    return i + 0x46;
}











u32 func_020276A4(void)
{
    return 0x49;
}











u32 func_020276A8(void)
{
    return 0x4a;
}











u32 func_020276AC(u32 i)
{
    return i + 0x4b;
}











u32 func_020276B0(u32 i)
{
    return i + 0x4e;
}











u32 func_020276B4(void)
{
    return 0xb;
}











u32 func_020276B8(void)
{
    return 0xc;
}











u32 func_020276BC(u32 i)
{
    return i + 0xd;
}











u32 func_020276C0(u32 i)
{
    return i + 0x10;
}










int func_020276C4(int a0){ int t0, t1; t0 = func_02017E1C((int)a0, (int)0xa0, (int)0); if ((unsigned int)(t0) == (unsigned int)(0)) { return 6; } else { t1 = func_02017E1C((int)((a0 + 0) + 0), (int)0x9d, (int)(0 + 0)); if ((unsigned int)(t1) == (unsigned int)(1)) { return 1; } else { if ((unsigned int)(t1) == (unsigned int)(2)) { return 3; } else { if ((unsigned int)(t1) == (unsigned int)(3)) { return 2; } else { if ((unsigned int)(t1) == (unsigned int)(4)) { return 5; } else { if ((unsigned int)(t1) == (unsigned int)(5)) { return 4; } else { return 8; } } } } } } }









/*
 *           func_02027720, func_0202772C, func_02027738, func_02027740,
 *           func_02027748, func_0202774C, func_02027750, func_02027754,
 *           func_02027758, func_0202775C, func_02027760, func_02027764,
 *           func_02027768, func_0202776C, func_02027770, func_02027774
 *
 * Offset accessors and constants in beacon_status.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02027710.c \
 *       --addr 0x02027710 --thumb --cc 1.1p1
 */
int func_02027710(int a)
{
    return a + 0x51;
}










int func_02027714(int a)
{
    return a + 0x54;
}










int func_02027718(int a)
{
    return a + 0xa6;
}










int func_0202771C(int a)
{
    return a + 0xa9;
}










int func_02027720(int a)
{
    if (a == 0) {
        a = 4;
    }
    return a + 0x56;
}










int func_0202772C(int a)
{
    if (a == 0) {
        a = 4;
    }
    return a + 0x6f;
}










int func_02027738(int dummy, int b)
{
    return b + 0x89;
}










int func_02027740(int dummy, int b)
{
    return b + 0x8c;
}










int func_02027748(void)
{
    return 0x8f;
}










int func_0202774C(int a)
{
    return a + 0x90;
}










int func_02027750(int a)
{
    return a + 0x93;
}










int func_02027754(int a)
{
    return a + 0x96;
}










int func_02027758(void)
{
    return 0;
}










int func_0202775C(int a)
{
    return a + 2;
}










int func_02027760(int a)
{
    return a + 5;
}










int func_02027764(int a)
{
    return a + 8;
}










int func_02027768(void)
{
    return 0x99;
}










int func_0202776C(int a)
{
    return a + 0x9a;
}










int func_02027770(int a)
{
    return a + 0x9d;
}










int func_02027774(int a)
{
    return a + 0xa0;
}









/*
 * The TaskMenu constructor: allocate the 0x38-byte menu ("app_taskmenu.c",
 * lines 162/168/169), copy the 0x14-byte template in, allocate count*4 and
 * count*12 buffers and copy the template's item table into the second,
 * zero the cursor state, default the two template bytes at +0x12/+0x13 to
 * 13 and 3 when zero, then run func_02027A24 and, unless func_020355C4()
 * says otherwise, func_02027B30 on the current item.
 *
 * Promoted from src/pending (DIFF, 6 bytes out) in wave 12.  The last
 * residue was the scheduling of the +0x12 template load after the three
 * zero stores: the template parameter is NOT const.  With a const pointer
 * mwcc proves the stores into the menu cannot reach the template and
 * hoists the ldrb above them; without it the load stays in source order.
 * The two defaults are unconditional stores of a conditioned value
 * (v = tmpl->unk12; if (v == 0) v = 13; m->tmpl.unk12 = v), not guarded
 * member stores.
 */
struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1)
{
  struct TaskMenu *m;
  m = func_02030734((u16) tmpl->heapId, 0x38, 0, sFile_020A74E0, 162);
  m->tmpl = *tmpl;
  m->arg1 = arg1;
  m->buf1 = func_02030734((u16) m->tmpl.heapId, m->tmpl.count * 4, 0, sFile_020A74E0, 168);
  m->buf2 = func_02030734((u16) m->tmpl.heapId, m->tmpl.count * 12, 0, sFile_020A74E0, 169);
  MIi_CpuCopy16(m->tmpl.unk08, m->buf2, m->tmpl.count * 12);
  m->unk0c = 0;
  m->unk10 = 0;
  m->unk00 = 0;
  m->unk01 = 0;
  m->unk02 = 0;
  m->unk14 = 1U;
  {
    u8 v12 = tmpl->unk12;
    u8 v13;
    if (v12 == 0)
    {
      v12 = 13;
    }
    m->tmpl.unk12 = v12;
    v13 = tmpl->unk13;
    if (v13 == 0)
    {
      v13 = 3;
    }
    m->tmpl.unk13 = v13;
  }
  func_02027a24((struct Obj_020263B0 *)m, arg1);
  if (func_020355c4() == 0)
  {
    func_02027b30((u32)(((void **) m->buf1)[m->unk00]), m->arg1, 1);
  }
  m->unk08 = 1;
  return m;
}










struct TaskMenu *func_0202784C(struct TaskMenuTmpl *a0, void *a1){ struct TaskMenu *t0; t0 = func_02027778(a0, a1); *(int *)&((struct Obj00059 *)((char *)(t0)))->f14 = (int)2; return t0; }










/*
 * Tear down a task menu: drain every queued item of every cell, destroy the
 * cells, drop the shared owner and release the three blocks.
 *
 * The item count at +0x24 is a `u8` and the two loop counters are `u8` too,
 * which is what the `lsls #24 / lsrs #24` pair after each increment says.
 * +0x24 is past the `ldrb` immediate reach of 31, so every read of it costs
 * an `adds r0, #0x24` first
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * The second loop's entry test does not reload the count: it reuses the
 * register the first loop's last bottom-of-loop read left behind, which is
 * why `movs r4, #0 / cmp r0, #0` appears with no load between them.
 *
 * The inner drain is a `while` whose condition is a call, so the condition
 * is emitted twice, once as the entry guard and once as the back edge.
 *
 * EXACT*: the extent runs to 156 bytes because the next function has no
 * label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027858.c \
 *       --func func_02027858 --addr 0x02027858 --cc 1.1p1 --thumb
 */
void func_02027858(struct TaskMenu *m)
{
    void *owner;
    u8 i;
    u8 j;

    owner = (void *)func_02045730(m->buf1[0]);

    for (i = 0; i < m->tmpl.count; i++) {
        while (func_0201C6C4(((struct TaskMenuOwner *)m->arg1)->unk_14,
                             func_02045770(m->buf1[i])) != 0) {
            func_0201C4E4(((struct TaskMenuOwner *)m->arg1)->unk_14);
        }
    }

    for (j = 0; j < m->tmpl.count; j++) {
        func_020456F8(m->buf1[j]);
        func_020452E8(m->buf1[j]);
    }

    func_02041B6C((u32)owner);
    func_020307B0(m->buf1);
    func_020307B0(m->buf2);
    func_020307B0(m);
}










/*
 * app_taskmenu.c: the deselect sweep.  If the menu is in state 1, scan every
 * entry's cell for a hit; a hit clears the sentinel, and only when no hit was
 * found (sentinel still 1) does the second loop tear every cell down and
 * leave state 0.
 *
 * NOTE: the earlier DIFF note read the `adds r7, r4, #0` at +0x18 as a live
 * copy of the loop index, and every spelling chasing that came out 126 bytes.
 * It is not a copy of the index: +0x18 sits BEFORE the loop's back-edge target
 * (0x0202790E), so r7 is set once and never updated.  The assignment in the
 * loop is the constant `sel = 0`, rematerialised off the already-zero r4 per
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md.
 */
void func_020278F4(u8 *p)
{
    u8 i;
    u8 sel;

    if (((struct Obj00104 *)p)->f8 != 1) {
        return;
    }
    sel = 1;
    for (i = 0; i < ((struct Obj00104 *)p)->f24; i++) {
        if (func_0201C6C4((struct PrintSys *)(*(u32 *)(*(u32 *)&((struct Obj00104 *)p)->f34 + 0x14)),
                          (void *)((u32)func_02045770((struct Descriptor *)(*(u32 **)(p + 0x18))[i]))) == 1) {
            sel = 0;
        }
    }
    if (sel != 1) {
        return;
    }
    for (i = 0; i < ((struct Obj00104 *)p)->f24; i++) {
        u32 v = (*(u32 **)(p + 0x18))[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_02041B6C(func_02045730((struct Descriptor *)v));
    }
    ((struct Obj00104 *)p)->f8 = 0;
}










/*
 * field_sound_system.c.  EXACT: all seven relocations resolve.  The calls to
 * func_02027D44 and func_02027E3C carry on class sole-ref/code (each is the
 * only branch anywhere in the image to its target, and each target is exactly
 * a traced Thumb function start); func_02027E3C was additionally filed EXACT
 * in src/matched/ on 2026-09-21, which would carry that site on class matched
 * as well.
 */
void func_02027974(struct TaskMenu *p)
{
    u32 step;
    u16 *q;

    func_020278F4((u8 *)p);
    if (p->unk0c == 0) {
        func_02027D44((struct Menu *)p);
        if (p->unk0c == 0) {
            func_02027E3C((u8 *)p);
        }
    } else {
        step = _u32_div_f(4, p->unk14);
        if ((u8)(_u32_div_f(p->unk01, step) & 1) == 0) {
            func_02027B30((u32)p->buf1[p->unk00], (struct S *)p->arg1, 1);
        } else {
            func_02027B30((u32)p->buf1[p->unk00], (struct S *)p->arg1, 0);
        }
        p->unk01 = (u8)(p->unk01 + 1);
    }
    q = (u16 *)p->arg1;
    func_02027B60(&p->unk02, &p->unk04, (u8)q[0], (u8)q[1]);
}










/*
 * app_taskmenu.c's "does the menu need more than one page" predicate: the
 * per-page capacity is 16 divided by the entry height at +0x14, and the
 * answer is whether the entry count at +1 reaches it.
 *
 * The division is the unsigned runtime helper, so both operands are unsigned
 * and the comparison is `blo`
 * (docs/idioms/runtime-helper-reloc.md).  The 1-returning arm falls through
 * and the 0-returning arm is the branch target, which is the source order
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md): the `if` is
 * written `>=`, not `<`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020279E8.c \
 *       --func func_020279E8 --addr 0x020279E8 --cc 1.1p1 --thumb
 */
u32 func_020279E8(struct TaskMenu *m)
{
    if (m->unk01 >= 16 / m->unk14) {
        return 1;
    }
    return 0;
}









u8 func_02027A04(const u8 *p)
{
    return *p;
}







/*
 * The one relocation site's pool word is 0x02027B31, i.e. 0x02027B30 with the
 * Thumb bit set - the header used to declare 0x02077B30, an ARM address, which
 * was a misreading of the word.  Resolved when 0x02027B30 became EXACT.
 */
u32 func_02027A08(struct TaskMenu *tm, u32 arg)
{
    u32 index = tm->unk00;
    void *fn = tm->buf1[index];
    void *ctx = tm->arg1;
    return func_02027B30((u32)fn, (struct S *)ctx, arg);
}





/*
 * Getter for the word at offset 0xC of a task menu object; witness for
 * the call at +0x16 of ov119 func_021DA318.
 */
unsigned func_02027A20(char *p)
{
    return ((struct Obj15770 *)p)->fC;
}







/*
 * Build the o->count BG layers of a multi-row menu, one per iteration: the
 * layer handle goes into o->layers[i], the per-row descriptor lives in the
 * 0xc-byte array at o->rows[i], and the same four-call teardown quartet that
 * func_0202800C runs once per object runs once per layer here.
 *
 * The flag at +0x2c picks between a plain origin (+0x30, +0x31) and one
 * inset by +0x32 / (+0x33 * +0x24); both arms narrow to u8, which is what
 * keeps the two lsls/lsrs #0x18 pairs alive.
 */
void func_02027A24(struct Obj_020263B0 *o, struct Cfg *cfg)
{
    u32 ox;
    u32 oy;
    u8  i;
    u32 bg;
    struct Row_0 *rows;
    struct Row_0 *row;

    if (o->inset == 0) {
        ox = o->x0;
        oy = o->y0;
    } else {
        ox = (u8)(o->x0 - o->dx);
        oy = (u8)(o->y0 - o->dy * o->count);
    }
    for (i = 0; i < o->count; i++) {
        o->layers[i] = sub_020450F0((u8)o->glyph->f00, ox,
                                    (u8)(oy + i * o->dy), o->dx,
                                    o->dy, (u8)(o->glyph->f02 + 1), 1);
        func_020282D8(o->layers[i], cfg, o->rows[i].f08);
        rows = o->rows;
        row = &rows[i];
        sub_0201C724((void *)cfg->f14, (u32)func_02045770((struct Descriptor *)o->layers[i]), 0xa, 6,
                     rows[i].f00, cfg->f10, row->f04);
        bg = o->layers[i];
        func_02045334((struct Descriptor *)bg);
        func_02045374((struct Cfg *)bg);
        func_02041B6C(func_02045730((struct Descriptor *)bg));
    }
}








u32 func_02027B30(u32 a0, struct S *s, int mode)
{
    if (mode == 1) {
        func_02045798((struct Descriptor *)a0, (u8)((struct Obj11289 *)s)->f2);
    } else if (mode == 0) {
        func_02045798((struct Descriptor *)a0, (u8)(((struct Obj11289 *)s)->f2 + 1));
    }
    func_02045374((struct Cfg *)a0);
    func_02041B6C(func_02045730((struct Descriptor *)a0));
}








void func_02027B60(u16 *phase, u16 *out, u32 mode, u32 slot)
{
    s32 s;
    u8 b, r, g;

    if (*phase + 0x400 >= 0x10000) {
        *phase = (u16)(*phase - 0xfc00);
    } else {
        *phase = (u16)(*phase + 0x400);
    }

    s = (s16)((tbl_020A1B38[2 * (*phase >> 4) + 1] + 0x1000) / 2);

    b = (u8)(((s + s * 16) >> 12) + 0xd);
    r = (u8)(((s * 7) >> 12) + 5);
    g = (u8)(((s * 15) >> 12) + 0xa);

    *out = (u16)(r | (g << 5) | (b << 10));

    if (mode <= 3) {
        sub_02061CA4((void *)0xf, slot * 32 + 0xc, (u32)out, 2);
    } else {
        sub_02061CA4((void *)0x1f, slot * 32 + 0xc, (u32)out, 2);
    }
}







/*
 * Sibling of func_02027B60: advance the u16 phase by 0x400 (wrapping at
 * 0x10000), take the sine-table value tbl_020A1B38[2*(phase>>4)+1], and
 * lerp channel by channel between two BGR555 colours c0 and c1 (the fifth
 * and sixth, stack, arguments); write the packed colour to *out and hand
 * it to sub_02061CA4 with 0xf (mode <= 3) or 0x1f.
 *
 * Closed in wave 12.  The 59-byte residue the earlier note read as
 * scheduling of the six-way colour unpack was the third parameter's type:
 * `mode` is a u16.  Nothing in the instruction stream shows the width
 * (the parameter is homed with a plain str either way), but the narrower
 * type changes the order the scheduler emits the unpack prologue in,
 * which is exactly where all 59 bytes sat.  The
 * permuter found it inside an 11-mutation anneal result; `type:p(mode)` is
 * the only one of the eleven that matters.
 */
void func_02027BF4(u16 *phase, u16 *out, u16 mode, u32 slot,
                   u16 c0, u16 c1)
{
    s32 s;
    u8 r0c, g0c, b0c;
    u8 r1c, g1c, b1c;
    u8 r, g, b;

    r0c = (u8)(c0 & 0x1f);
    g0c = (u8)((c0 & (0x1f << 5)) >> 5);
    b0c = (u8)((c0 & (0x1f << 10)) >> 10);
    r1c = (u8)(c1 & 0x1f);
    g1c = (u8)((c1 & (0x1f << 5)) >> 5);
    b1c = (u8)((c1 & (0x1f << 10)) >> 10);

    if (*phase + 0x400 >= 0x10000) {
        *phase = (u16)(*phase - 0xfc00);
    } else {
        *phase = (u16)(*phase + 0x400);
    }

    s = (s16)((tbl_020A1B38[2 * (*phase >> 4) + 1] + 0x1000) / 2);

    b = (u8)(b0c + ((s * (b1c - b0c)) >> 12));
    r = (u8)(r0c + ((s * (r1c - r0c)) >> 12));
    g = (u8)(g0c + ((s * (g1c - g0c)) >> 12));

    *out = (u16)(r | (g << 5) | (b << 10));

    if (mode <= 3) {
        sub_02061CA4((void *)0xf, slot * 32 + 0xc, (u32)out, 2);
    } else {
        sub_02061CA4((void *)0x1f, slot * 32 + 0xc, (u32)out, 2);
    }
}







int func_02027CD8(int a0, int a1){ int t0, t1; *(int *)&((struct Obj00059 *)((char *)((a0 + 0))))->f10 = (int)a1; if ((unsigned int)(a1) == (unsigned int)(1)) { func_020355D8((int)1); t1 = func_02027B30((int)*(int *)(((char *)(*(int *)&((struct Obj00059 *)((char *)((a0 + 0))))->f18) + ((int)((*(unsigned char *)&((struct Obj00059 *)((char *)((a0 + 0))))->f0 << 2)) << 0))), (struct S *)*(int *)&((struct Obj00059 *)((char *)((a0 + 0))))->f34, (int)0); } else {  return a0; } }








void func_02027CFC(u8 *p, int sel)
{
    int i;

    *p = sel;
    if (func_020355C4() != 0) {
        return;
    }
    i = 0;
    while (i < ((struct Obj06917 *)p)->f24) {
        if (i == sel) {
            func_02027B30((*(u32 **)(p + 0x18))[i], (struct S *)(((struct Obj06917 *)p)->f34), 1);
        } else {
            func_02027B30((*(u32 **)(p + 0x18))[i], (struct S *)(((struct Obj06917 *)p)->f34), 0);
        }
        i++;
    }
}








/*
 * The TaskMenu per-frame input step: up (0x40) / down (0x80) move the
 * cursor with wrap-around and play 0x548; A (held & 1) confirms (m->f0C = 1,
 * sound 0x551 or 0x54c by the row's +8 word); B (held & 2) jumps to the
 * last row, sound 0x551.  In the func_020355C4() == 1 mode a press that is
 * not B only re-highlights the current row.  When the cursor moved, the old
 * row is un-highlighted and the new one highlighted via func_02027B30.
 *
 * Closed in wave 12 from the 84-byte wave-4 source by two facts:
 *  - the up/down arms play 0x548, not 0x54C: the pool is 0x548, 0x551,
 *    0x54C in first-use order and the 0x40 arm's ldr reaches the first
 *    word (68 of the 84 bytes were this constant and the pool order it
 *    forced);
 *  - in the B arm the cursor store is written BEFORE the m->f0C = 1 store.
 *    The scheduler emits them the other way round, but the source order
 *    decides which of the constant 1 and the count temporary gets r0; the
 *    permuter never moves one store past another, so it could not find it.
 * No `one` local is needed; the constant is CSE'd by the compiler.
 */
void func_02027D44(struct Menu *m)
{
    u32 held;
    u32 hit;
    int prev;

    held = func_020362DC();
    hit  = func_0203633C();
    if (m->f10 == 1) {
        return;
    }
    if (func_020355C4() == 1) {
        if ((held & 2) == 0) {
            if ((held & 0xC3) == 0) {
                return;
            }
            func_02027B30(m->f18[m->cursor], (struct S *)m->f34, 1);
            func_020355D8(0);
            func_020061E4(0x548);
            return;
        }
    }
    prev = m->cursor;
    if (hit & 0x40) {
        if (prev == 0) {
            m->cursor = (u8)(m->count - 1);
        } else {
            m->cursor = (u8)(prev - 1);
        }
        m->h2 = 0;
        func_020061E4(0x548);
    } else if (hit & 0x80) {
        if (prev >= m->count - 1) {
            m->cursor = 0;
        } else {
            m->cursor = (u8)(prev + 1);
        }
        m->h2 = 0;
        func_020061E4(0x548);
    } else {
        if (held & 1) {
            m->f0C = 1;
            if (m->f1C[prev].f08 == 1) {
                func_020061E4(0x551);
            } else {
                func_020061E4(0x54C);
            }
        } else if (held & 2) {
            m->cursor = (u8)(m->count - 1);
            m->f0C = 1;
            func_020061E4(0x551);
            func_020355D8(0);
        }
    }
    if (prev == m->cursor) {
        return;
    }
    func_02027B30(m->f18[prev], (struct S *)m->f34, 0);
    func_02027B30(m->f18[m->cursor], (struct S *)m->f34, 1);
}







/*
 * app_taskmenu.c: the touch handler.  Builds a stack table of one
 * eight-pixel-tall hit rectangle per menu entry (0xff-terminated), hands it
 * to func_02035C08, and on a hit moves the cursor, repaints the old and the
 * new entry, and raises the confirm notification.
 */
void func_02027E3C(u8 *m)
{
    u8  rect[0x24];
    u32 top;
    u8  left;
    u8  i;
    int hit;
    int one;

    if (((struct Obj00104 *)m)->f2C == 0) {
        top  = m[0x30];
        left = m[0x31];
    } else {
        top = (u8)(m[0x30] - m[0x32]);
        left = (u8)(m[0x31] - m[0x33] * m[0x24]);
    }

    for (i = 0; i < m[0x24]; i++) {
        rect[i * 4 + 0] = (u8)((left << 3) + m[0x33] * 8 * i);
        rect[i * 4 + 1] = (u8)((left << 3) + m[0x33] * 8 * (i + 1));
        rect[i * 4 + 2] = (u8)(top << 3);
        rect[i * 4 + 3] = (u8)(((top + m[0x32]) << 3) - 1);
    }
    rect[i * 4] = 0xff;

    hit = func_02035C08(rect);
    if (hit == ~0) {
        return;
    }
    one = 1;
    func_020355D8(one);
    func_02027B30(((u32 *)*(u32 * *)&((struct Obj00104 *)m)->f18)[m[0]], (struct S *)(*(u32 *)&((struct Obj00104 *)m)->f34), 0);
    m[0] = (u8)hit;
    *(int *)&((struct Obj00104 *)m)->fC = one;
    func_02027B30(((u32 *)*(u32 * *)&((struct Obj00104 *)m)->f18)[m[0]], (struct S *)(*(u32 *)&((struct Obj00104 *)m)->f34), one);
    if (m[0] == 0) {
        func_020061E4(0x54C);
        return;
    }
    if (*(int *)(*(u8 * *)&((struct Obj00104 *)m)->f1C + m[0] * 0xC + 8) == 1) {
        func_020061E4(0x551);
        return;
    }
    func_020061E4(0x54C);
}







/*
 * Allocate and zero a 0x18-byte record ("app_taskmenu.c", line 0x2c6) and
 * fill it: two u16 ids at +0/+2, two words at +0x10/+0x14, then two
 * resources from the 0x02049xxx loader keyed by func_020275E4()'s handle.
 *
 * The 30-byte residue the earlier notes read as an allocation tie was the
 * callees' argument lists: func_020275E4()'s result is the FIRST argument
 * of func_02049DB4 and func_02049B40 (r0 is never reloaded between the bl
 * and the blx), so the constants 0x20 / 0x1f are the second argument, and
 * func_02049B40 takes (h, 0x1f, sel, a1 << 5, 0x40, heap) -- six arguments
 * with the heap id last.  Written that way the heap parameter needs no
 * address-taken pointer; it is an ordinary fifth (stack) parameter.
 */
struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap)
{
    struct R *r;
    u32 sel;

    sel = 0;
    r = (struct R *)func_02030734(heap, 0x18, 0, sFile_020A74E0, 0x2c6);
    MI_CpuFill8(r, 0, 0x18);
    r->a = a0;
    r->b = a1;
    r->c = a2;
    r->d = a3;
    if (a0 > 3) {
        sel = 4;
    }
    r->obj = (u32)func_02049DB4(func_020275E4(), 0x20, 0, (u32)(&r->f04), heap);
    func_02049B40(func_020275E4(), 0x1f, sel, a1 << 5, 0x40, heap);
    return r;
}







u32 func_02027FD8(struct TaskMenuState *s)
{
    sub_020307B0(s->child);
    return sub_020307B0(s);
}






u32 func_02027FEC(struct Cfg *a0, struct Src *a1, u16 a2, u16 a3, u8 a4, u16 a5)
{
    return (u32)func_0202800C(a0, a1, a2, a3, a4, 3, 0, 0, a5);
}







u32 *func_0202800C(struct Cfg *a0, struct Src *a1, u16 a2, u16 a3, u8 a4, u8 a5,
                   u32 a6, u32 a7, u16 a8)
{
    u32 *p = (u32 *)func_02028084(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    void *q = (void *)p[0];

    func_02045334(q);
    func_02045374(q);
    func_02041B6C(func_02045730(q));
    return p;
}







u32 *func_0202804C(struct Cfg *a0, struct Src *a1, u16 a2, u16 a3, u8 a4, u8 a5,
                   u32 a6, u32 a7, u16 a8)
{
    u32 *p = (u32 *)func_02028084(a0, a1, a2, a3, a4, a5, a6, a7, a8);

    func_02045374((void *)p[0]);
    func_02041B6C(func_02045730((void *)p[0]));
    return p;
}






/*
 * Nine-argument constructor: allocate a 0x20-byte menu object on heap a8
 * (the __FILE__ pool word 0x020A74E0 is app_taskmenu.c, line 0x337), zero
 * it, then build the BG layer and the text window.  func_0202800C, the only
 * in-image caller, forwards all nine arguments unchanged, which is where the
 * u8/u8/u32/u32/u16 spelling of the five stack arguments comes from.
 *
 * a2 and a3 are u16, not u32.  The earlier DIFF note (45 bytes out, all
 * spill-ordering) held them u32; the permuter's type mutation found that
 * narrowing BOTH closes the residue, and the reading is sound rather than
 * lucky: the original spills them with a full-word `str` and reloads with a
 * full-word `ldr` and never truncates, so writing the narrowing explicitly
 * (`(u16)a2` at the use site, or a u16 local assigned from a u32 parameter)
 * inserts an lsls/lsrs pair the original does not have and takes the diff
 * from 45 bytes to 171.  The only spelling with no truncation anywhere is a
 * parameter that is already 16 bits at entry.  No in-image caller passes a
 * value wider than 16 bits: the single caller func_0202800C forwards its own
 * arguments unchanged, and its caller func_02027FEC does the same; both are
 * BG coordinate arguments handed straight to sub_020450F0.
 *
 * `cellSrc` (src->f08 lifted into a local before the func_020282D8 call) is
 * the last 6 bytes: it pins the load ahead of the argument setup.
 */
struct CfgObj *func_02028084(struct Cfg *cfg, struct Src *src, u16 a2, u16 a3,
                          u8 a4, u8 a5, u32 a6, u32 a7, u16 heap)
{
    struct CfgObj *o;
    u32 bg;
    s16 w;
    u32 cellSrc;

    w = 2;
    o = (struct CfgObj *)func_02030734(heap, 0x20, 0, g_020A74E0, 0x337);
    MI_CpuFill8(o, 0, 0x20);
    o->f18 = cfg;
    o->f0c = 1;
    o->f12 = (u16)(a6 + 1);
    bg = sub_020450F0((u8)cfg->f00, a2, a3, a4, a5, (u8)(cfg->f02 + 1), 1);
    cellSrc = src->f08;
    o->f00 = bg;
    func_020282D8(bg, cfg, cellSrc);
    if (a7 == 1) {
        w = (u8)(((a4 << 3) - sub_0201D304((void *)src->f00, cfg->f10, 0)
                  - 0x10) >> 1);
    }
    sub_0201C724((void *)cfg->f14, (u32)func_02045770((void *)o->f00),
                 (s16)(w + 8), 6, src->f00, cfg->f10, src->f04);
    o->f1c = 0x3545;
    o->f1e = 0x7B2C;
    return o;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028148.c \\
 *       --func func_02028148 --addr 0x02028148 --thumb --cc 1.1p1
 */
void func_02028148(u8 *p)
{
    func_020456F8((struct Descriptor *)(((struct Obj15778 *)p)->f0));
    func_02028164(p);
}





/*
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x02028164, the callee's
 * address with its Thumb bit set (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202815C.c \
 *       --func func_0202815C --addr 0x0202815C --thumb --cc 1.1p1
 */
void func_0202815C(u8 *a0)
{
    func_02028164(a0);
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028164.c \\
 *       --func func_02028164 --addr 0x02028164 --thumb --cc 1.1p1
 */
void func_02028164(u8 *p)
{
    func_020452E8((struct Descriptor *)(((struct Obj15779 *)p)->f0));
    func_020307B0(p);
}





/*
 * bytes match.
 *   +0098 func_02027BF4: the `bl` at 0x02028210 inside this function is the
 *     only branch to 0x02027BF4 anywhere in the image (grep over
 *     asm/arm9/main.s and asm/overlays/ finds the definition plus this one
 *     call site), so the `label` class has no witness outside the compared
 *     range and no manifest entry reproduces 0x02027BF4 yet. A second
 *     caller, or an EXACT entry covering func_02027BF4, unsticks it.
 *
 * The trailing `*`: the inferred extent runs to 0x02028230 because the next
 * function, at 0x02028218, saves no lr and so carries no label. It is a
 * six-instruction leaf that zeroes the halfword at +0x14 and tail-calls
 * through a pool word (`ldr r3, [pc, #0]; bx r3`); a second unlabelled leaf
 * (`bx lr`) follows it at 0x0202822E. Both are seeds for
 * layout/function_starts.txt.
 *
 * The per-frame step of an animation object.  Two independent phases: tear
 * down the finished sub-object at +0xc once its sequence has run out, then
 * advance the frame counter at +0x10 and re-post every other frame.  The
 * `(4 / h)` divisor is the same `_s32_div_f` helper func_02028230 uses on
 * the same two halfwords.
 *
 * The parity test on the frame index is the signed `% 2` sequence
 * (lsrs #31 / lsls #31 / subs / rors #31 / adds), not a mask: the counter
 * is read as a signed value, so a plain `& 1` would be four bytes shorter
 * and wrong.
 */
void func_02028178(u8 *p)
{
    u32 obj;
    u16 *ctx;

    if (((struct Obj00864 *)p)->fC != 0) {
        if (func_0201C6C4((struct PrintSys *)(*(u32 *)(*(u32 *)&((struct Obj00864 *)p)->f18 + 0x14)),
                          (void *)((u32)func_02045770((struct Descriptor *)((struct Obj00864 *)p)->f0))) == 0) {
            obj = ((struct Obj00864 *)p)->f0;
            func_02045334((struct Descriptor *)obj);
            func_02045374((struct Cfg *)obj);
            func_02041B6C(func_02045730((struct Descriptor *)obj));
            ((struct Obj00864 *)p)->fC = 0;
        }
    }

    if (((struct Obj00864 *)p)->f8 != 0) {
        s32 d = 4 / (s32)((struct Obj00864 *)p)->f12;

        if ((u8)((s32)((struct Obj00864 *)p)->f10 / d % 2) == 0) {
            func_02027B30(((struct Obj00864 *)p)->f0, (struct S *)(*(u32 *)&((struct Obj00864 *)p)->f18), 1);
        } else {
            func_02027B30(((struct Obj00864 *)p)->f0, (struct S *)(*(u32 *)&((struct Obj00864 *)p)->f18), 0);
        }
        ((struct Obj00864 *)p)->f10 = ((struct Obj00864 *)p)->f10 + 1;
    }

    ctx = *(u16 * *)&((struct Obj00864 *)p)->f18;
    func_02027BF4((u16 *)(p + 0x14), (u16 *)(p + 0x16), (u8)ctx[0], (u8)ctx[1],
                  ((struct Obj00864 *)p)->f1C, ((struct Obj00864 *)p)->f1E);
}





/*
 * A tail call that clears the u16 at offset 0x14 and forwards two of the
 * object's own fields plus the caller's argument.
 */
void func_02028218(struct Obj_02028084 *obj, u32 a)
{
    obj->field_14 = 0;
    func_02027B30(obj->field_00, (struct S *)obj->field_18, a);
}





/*
 * Unlabelled leaf setter: stores v at p + 8.
 */
void func_0202822C(char *p, int v)
{
    ((struct Obj15780 *)p)->f8 = v;
}

/*
 * Alternate entry: func_0202822E() is the `bx lr` at func_0202822C + 2 (the
 * function map lists it as its own symbol); it has no code of its own.
 */







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028230.c \
 *       --func func_02028230 --addr 0x02028230 --thumb --cc 1.1p1
 */
u32 func_02028230(u8 *p)
{
    s32 r = 0x10 / (s32)((struct Obj00864 *)p)->f12;

    if ((s32)((struct Obj00864 *)p)->f10 < r) {
        return 0;
    }
    return 1;
}








/*
 * Touch hit test against a window.  func_02035D20 reports whether the
 * screen is being touched and where; if so the window's origin and
 * extent are read off its descriptor in tile units and scaled to
 * pixels by 8, and the touch point must fall inside that rectangle.
 *
 * The extent accessor func_02045738 is called twice rather than once
 * with its result reused: it is an external ARM call, so the compiler
 * cannot prove it pure, and both calls survive.
 */
u32 func_0202824C(void **p)
{
    u32 x;
    u32 y;
    u32 left;
    u32 top;
    u32 right;
    u32 bottom;

    if (func_02035D20(&x, &y) == 0) {
        goto fail;
    }

    left = func_02045758(p[0]) * 8;
    top = func_02045760(p[0]) * 8;
    right = left + func_02045738(p[0]) * 8;
    bottom = top + func_02045738(p[0]) * 8;

    if (x - left > right - left) {
        goto fail;
    }
    if (y - top > bottom - top) {
        goto fail;
    }
    return 1;
fail:
    return 0;
}








/*
 * A leaf that clears the word at offset 8 and the halfword at offset 0x10.
 */
void func_020282A4(struct Obj *obj)
{
    obj->field_08 = 0;
    obj->field_10 = 0;
}




void func_020282AC(struct T *p, u16 *a1, u32 a2, u32 a3, u16 a4)
{
    a1[1] = a2;
    p->f1c = a3;
    p->f1e = a4;
    func_02045798((void *)p->f00, (u8)(a2 + 1));
    func_02045374((void *)p->f00);
    func_02041B6C(func_02045730((void *)p->f00));
}



/*
 * app_taskmenu.c: paints a window frame into the BG's tilemap.  Walks the
 * layer's rows (func_02045740) and columns (func_02045738) and, per 0x20-byte
 * tile, classifies the cell as one of eleven kinds -- four corners, three
 * edges, two style-dependent inner columns, the plain interior -- and copies
 * the matching tile out of the template's tile bank (cfg->f04->f14) into the
 * layer's tile memory.
 *
 * Two shape notes, both worth a byte each:
 *  - Both loops are a top guard plus a bottom back-edge (`for (;;)` with the
 *    `x >= n` / `y >= n` test written out at both ends), not a plain `for`:
 *    the original's guards are `bhi`/`bhs` on the freshly-called bound and
 *    the two back-edges land on 0x02028312 and 0x02028304, which a `for` does
 *    not reproduce (366 bytes, 291 wrong).  The row loop's `x = 0` sits after
 *    the row guard, which is what the `goto nextrow` preserves.
 *  - `rowbase` must be DECLARED BEFORE `dst`: the two are the only spilled
 *    locals and they take sp+0xc and sp+0x10 in declaration order, the later
 *    declaration at the lower address (docs/idioms/local-declaration-order-is-stack-order.md).
 *    The wrong order is otherwise byte-perfect and reads as exactly 4 bytes
 *    out, two stores and two loads with the slots swapped.
 *
 * EXACT*: the compiled body is 354 bytes and the listing's inferred extent is
 * 356 -- the follower at 0x0202843C has no label, so the extent ran two bytes
 * long over the alignment padding.  Not a byte difference.
 */
void func_020282D8(u32 bg, struct Cfg *cfg, u32 style)
{
    u8  y;
    u8  x;
    u32 rowbase;
    u32 dst;
    u32 tEdgeB;
    u32 tEdgeA;
    u32 src;
    u32 t;

    y = 0;
    if (y >= func_02045740((struct Descriptor *)bg)) {
        return;
    }
    t = style - 1;
    tEdgeB = (t + t * 2 + 9) << 5;
    tEdgeA = (t + t * 2 + 10) << 5;
    for (;;) {
        x = 0;
        if (x >= func_02045738((struct Descriptor *)bg)) {
            goto nextrow;
        }
        for (;;) {
        dst = (u32)func_020437D4((const struct Bmp *)((u32)func_02045770((struct Descriptor *)bg)));
        rowbase = (x + y * func_02045738((struct Descriptor *)bg)) << 5;
        if (y == 0 && x == 0) {
            src = cfg->f04->f14;
        } else if (y == 0 && x == func_02045738((struct Descriptor *)bg) - 1) {
            src = cfg->f04->f14 + 0x40;
        } else if (y == 0) {
            src = cfg->f04->f14 + 0x20;
        } else if (y == func_02045740((struct Descriptor *)bg) - 1 && x == 0) {
            src = cfg->f04->f14 + 0xc0;
        } else if (y == func_02045740((struct Descriptor *)bg) - 1 && x == func_02045738((struct Descriptor *)bg) - 1) {
            src = cfg->f04->f14 + (1 << 8);
        } else if (y == func_02045740((struct Descriptor *)bg) - 1) {
            src = cfg->f04->f14 + 0xe0;
        } else if (style != 0 && x == func_02045738((struct Descriptor *)bg) - 3) {
            src = cfg->f04->f14 + tEdgeB;
        } else if (style != 0 && x == func_02045738((struct Descriptor *)bg) - 2) {
            src = cfg->f04->f14 + tEdgeA;
        } else if (x == 0) {
            src = cfg->f04->f14 + 0x60;
        } else if (x == func_02045738((struct Descriptor *)bg) - 1) {
            src = cfg->f04->f14 + 0xa0;
        } else {
            src = cfg->f04->f14 + 0x80;
        }
        MIi_CpuCopy32((const void *)src, (void *)(dst + rowbase), 0x20);
            x++;
            if (x >= func_02045738((struct Descriptor *)bg)) {
                break;
            }
        }
nextrow:
        y++;
        if (y >= func_02045740((struct Descriptor *)bg)) {
            return;
        }
    }
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202843C.c \\
 *       --func func_0202843C --addr 0x0202843C --thumb --cc 1.1p1
 */
void func_0202843C(u8 *p)
{
    func_020456F8((struct Descriptor *)(((struct Obj11291 *)p)->f0));
    func_02041B6C((u8)*(u16 *)(((struct Obj11291 *)p)->f18));
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028454.c \\
 *       --func func_02028454 --addr 0x02028454 --thumb --cc 1.1p1
 */
void func_02028454(u8 *p)
{
    func_02045374((struct Cfg *)(((struct Obj11292 *)p)->f0));
    func_02041B6C((u8)*(u16 *)(((struct Obj11292 *)p)->f18));
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202846C.c \\
 *       --func func_0202846C --addr 0x0202846C --thumb --cc 1.1p1
 */
u32 func_0202846C(u8 *p)
{
    return ((struct Obj15793 *)p)->fC;
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028470.c \\
 *       --func func_02028470 --addr 0x02028470 --thumb --cc 1.1p1
 */
void func_02028470(u8 *p, u32 v)
{
    func_02082BCC(p, 0, 8);
    ((struct Obj15794 *)p)->f4 = v;
}




/*
 * Per-frame service step for one handle attached to a state block: reads
 * the handle's state word with func_0201CE30 and dispatches on it as a
 * switch. State 1 finishes the handle (func_020284F4 on the block's flags
 * word, then a fixed-id notify through func_020061E4 and a teardown call);
 * state 0 runs a two-phase step, gated on bit 10 of the same flags word,
 * where func_0202855C latches the block's first byte and func_02028528
 * later releases the handle. Both state-0 callees take the flags word in
 * r0, which is what pins it there across the whole arm and pushes the mask
 * and the byte test into r1. State 2, and a null handle, return 1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028484.c \
 *       --func func_02028484 --addr 0x02028484 --cc 1.1p1 --thumb
 */
s32_02028484 func_02028484(Blk *blk, void *h)
{
    u32 mask;

    if (h != 0) {
        switch (func_0201CE30(h)) {
        case 2:
            return 1;
        case 1:
            if (func_020284F4(blk->flags) != 0) {
                func_020061E4(0x547);
                func_0201CE38(h);
            }
            break;
        case 0:
            mask = 1 << 10;
            if ((mask & blk->flags) == 0) {
                if (blk->first == 0) {
                    if (func_0202855C(blk->flags) != 0) {
                        blk->first = 1;
                    }
                } else {
                    if (func_02028528(blk->flags) != 0) {
                        func_0201CE5C(h, 0);
                    }
                }
            }
            break;
        }
        return 0;
    }
    return 1;
}




u32 func_020284F4(u32 a)
{
    u32 r = 0;

    if (a == 0) {
        r = 1;
    }

    if (a & 2) {
        if (func_020362DC() & 3) {
            r = 1;
        }
    }

    if (a & 4) {
        if (func_02035C60() != 0) {
            r = 1;
        }
    }

    return r;
}




u32 func_02028528(u32 a)
{
    u32 r = 0;

    if (a == 0) {
        r = 1;
    }

    if (a & 2) {
        if (func_0203630C() & 3) {
            r = 1;
        }
    }

    if (a & 4) {
        if (func_02035C38() != 0) {
            r = 1;
        }
    }

    return r;
}




u32 func_0202855C(u32 a)
{
    u32 r = 0;

    if (a == 0) {
        r = 1;
    }

    if (a & 2) {
        if (func_0203630C() == 0) {
            r = 1;
        }
    }

    if (a & 4) {
        if (func_02035C38() == 0) {
            r = 1;
        }
    }

    return r;
}



void func_02028590(u32 a0, u32 a1, u32 a2, u16 a3)
{
    func_020285A4(a0, a1, a2, a3, g_0209FD10);
}
