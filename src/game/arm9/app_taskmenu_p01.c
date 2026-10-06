/*
 * file:     app_taskmenu_p01.c
 * unit:     yes
 * function: func_020263B0, func_020263D8, func_02026400, func_0202640C, func_02026454, func_02026460, func_02026474, func_02026478, func_0202647C, func_02026484, func_0202648C, func_02026490, func_02026498, func_020264AC, func_020264B4, func_020264F4, func_02026504, func_02026608, func_02026680, func_020266AC, func_020266C0, func_020266D4, func_020266E0, func_02026728, func_020267BC, func_020267E4, func_020267FC, func_02026824, func_0202685C, func_02026A60, func_02026BFC, func_02026C1C, func_02026C30, func_02026C78, func_02026C8C, func_02026CA0, func_02026CE0, sub_02026D04, func_02026D48, func_02026D88, func_02026FB8, func_02027060, func_0202708C, func_020270AC, func_020270E0, func_02027100, func_02027120, func_02027138, func_0202715C, func_02027174, func_02027198, func_020271DC, func_020271F8, func_02027220, func_02027230, func_02027258, func_02027268, func_02027290, func_020272A4, func_020272D0, func_020272EC, func_02027314, func_02027324, func_0202734C, func_0202735C, func_0202737C, func_020273C4, func_020273DC, func_020273F8, func_02027414, func_02027430, func_0202744C, func_02027460, func_020274B4, func_020274C8, func_020274F8, func_0202751C, func_02027584, func_020275A8, func_020275AC, func_020275B8, func_020275C4, func_020275D0
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
struct Src;
struct MsgBank;
struct Strbuf;
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

struct Src { u16 a; u16 b; u16 c; u16 d; };

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

extern void func_02082BCC(void *dst, int val, u32 n);
extern void func_02026490(void *obj, u32 value);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
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
void func_02027460(void *p, const struct Src *s);
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
void func_02026400(struct Comm *p)
{
    func_0202640C(p, 0, 0);
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
u32 sub_02026460(void *obj)
{
    if (*((u8 *)obj + 5) != 0 && *((u8 *)obj + 0x10) != 2) {
        return 1;
    }
    return 0;
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
u32 sub_02026474(void *obj)
{
    return ((struct Obj17245 *)obj)->f18;
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
u32 sub_02026478(void *obj)
{
    return ((struct Obj17246 *)obj)->f0;
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
u32 sub_0202647C(void *obj)
{
    return *((u8 *)obj + 6);
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
void sub_02026480(void *obj, u32 value)
{
    ((struct Obj17248 *)obj)->f8 = value;
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
void sub_02026484(void *obj)
{
    ((struct Obj17249 *)obj)->f8 = 0;
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
void sub_02026498(void *obj, u32 flag)
{
    u8 f = (u8)flag;
    u8 v = *((u8 *)obj + 4);

    v = (v & ~4) | ((f & 1) << 2);
    *((u8 *)obj + 4) = v;
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
void *sub_02026C1C(int n)
{
    return sub_02026BFC((u8 *)g_GameBeacon, n);
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
void *sub_02026C78(int n)
{
    return sub_02026C30((u8 *)g_GameBeacon, n);
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
    struct Src src;
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
static void sub_02027220(void *dst, u16 value)
{
    ((struct Obj00121 *)dst)->f30 = 0xe;
    ((struct Obj00121 *)dst)->f32 = value;
    func_0202744C(dst);
}







static void sub_02027258(void *dst, u16 value);







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
void sub_02027230(u16 value)
{
    if (sub_02027060(0xf)) {
        void *queue = (char *)g_System + 4;
        sub_02027258(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}







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
static void sub_02027258(void *dst, u16 value)
{
    ((struct Obj00121 *)dst)->f30 = 0xf;
    ((struct Obj00121 *)dst)->f32 = value;
    func_0202744C(dst);
}







static void sub_02027290(void *dst, u16 value);







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
void sub_02027268(u16 value)
{
    if (sub_02027060(0x10)) {
        void *queue = (char *)g_System + 4;
        sub_02027290(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}







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
static void sub_02027290(void *dst, u16 value)
{
    ((struct Obj17252 *)dst)->f30 = 0x10;
    func_020270AC((void *)value, (u16 *)((char *)dst + 0x34));
}







static void sub_020272D0(void *dst, u16 a, u16 b);







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
void sub_020272A4(u16 a, u16 b)
{
    if (sub_02027060(0x11)) {
        void *queue = (char *)g_System + 4;
        sub_020272D0(queue, a, b);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}







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
static void sub_020272D0(void *dst, u16 a, u16 b)
{
    ((struct Obj00121 *)dst)->f30 = 0x11;
    ((struct Obj00121 *)dst)->f32 = a;
    func_020270AC((void *)b, (u16 *)((char *)dst + 0x34));
    func_0202744C(dst);
}







static void sub_02027314(void *dst, u16 value);







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
void sub_020272EC(u16 value)
{
    if (sub_02027060(0x14)) {
        void *queue = (char *)g_System + 4;
        sub_02027314(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}







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
static void sub_02027314(void *dst, u16 value)
{
    ((struct Obj00121 *)dst)->f30 = 0x14;
    ((struct Obj00121 *)dst)->f34 = value;
    func_0202744C(dst);
}







static void sub_0202734C(void *dst, u16 value);







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
void sub_02027324(u16 value)
{
    if (sub_02027060(0x23)) {
        void *queue = (char *)g_System + 4;
        sub_0202734C(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}







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







/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void func_020273DC(char *p, unsigned short v)
{
    ((struct Obj05717 *)p)->f48 = (((struct Obj05717 *)p)->f48 & ~0xff) | 1;
    ((struct Obj05717 *)p)->f4E = v;
}







/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void func_020273F8(char *p, unsigned short v)
{
    ((struct Obj05718 *)p)->f48 = (((struct Obj05718 *)p)->f48 & ~0xff) | 2;
    ((struct Obj05718 *)p)->f4E = v;
}







/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void func_02027414(char *p, unsigned short v)
{
    ((struct Obj05719 *)p)->f48 = (((struct Obj05719 *)p)->f48 & ~0xff) | 3;
    ((struct Obj05719 *)p)->f4E = v;
}







/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
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
void func_02027460(void *p, const struct Src *s)
{
    struct Inner *o = &g_GameBeacon->in;

    o->a = s->a;
    o->b = s->b;
    o->f4a = s->c;
    o->f4c = s->d;
}






void func_020274B4(u32 a0)
{
    func_02027460((char *)g_02146940 + 4, (const struct Src *)a0);
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







/*
 * Unlabelled arm9 leaf. Filed as the relocation witness for ov032 (wave D2).
 */
u8 func_020275AC(u8 *p) { return p[0xb0e]; }







/*
 * Unlabelled arm9 leaf. Filed as the relocation witness for ov032 (wave D2).
 */
void func_020275B8(char *p, int v) { p[0xb0e] = v; }






/*
 * Unlabelled arm9 leaf reading the word at +0xB08. Filed as the relocation
 * witness for ov021 func_021CD3A4 (wave A1).
 */
int func_020275C4(void *p)
{
    return ((struct Obj15765 *)p)->fB08;
}






/*
 * Unlabelled arm9 leaf. Filed as the relocation witness for ov032 (wave D2).
 */
void *func_020275D0(char *p) { return p + 0xb0c; }
