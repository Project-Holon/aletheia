/*
 * file:     net_state_p01.c
 * unit:     yes
 * function: sub_020353B0, sub_020353C8, sub_020353F8, sub_02035428, sub_0203545C, func_02035544, sub_020355C4, sub_020355D8, sub_020355EC, sub_020355F8,, sub_02035660, func_0203568C, func_020356A0, func_02035750, func_02035760, func_02035780, func_020357A0, func_020357C0, func_020357E0, func_020358A0, func_02035A60, func_02035A70, func_02035AA4, func_02035ADC, func_02035B58, func_02035BA4, func_02035BBC, func_02035C08, func_02035C20, func_02035C38, func_02035C48, func_02035C60, func_02035C70, func_02035CB8, func_02035CD8, func_02035D20, func_02035D40, func_02035D5C, func_02035D98, func_02035DC8, func_02035DD8, func_02035E08, func_02035E18, func_02035E54, func_02035E84, func_02035EB0, func_02035ECC, func_02035EE8, func_02035F38, func_020360A8, func_020360B8, func_02036254, func_02036270, func_02036290, func_020362A4, func_020362BC, func_020362DC, func_020362EC, func_0203630C, func_0203631C, func_0203633C, func_0203634C, func_02036370, func_02036390, func_020363B8, func_020363D4, func_020363F0, func_0203640C, func_02036428, func_020364D4, func_02036500, func_02036540, func_02036568, func_020365E8, func_0203660C, func_02036624, func_02036640, func_0203666C, func_02036670, func_020366A8, func_020366C0, func_020366FC, func_02036738
 * address:  0x020353B0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020353B0  0x020353B0  arm
 *   PM_SetBackLight 0x0208BDD8  arm
 *   func_02035224   0x02035224  arm
 *   func_020353F8   0x020353F8  arm
 *   func_02035E08   0x02035E08  arm
 *   func_0203524C   0x0203524C  arm
 *   PM_GoSleepMode  0x0208C154  arm
 *   func_020353C8   0x020353C8  arm
 *   func_020352AC   0x020352AC  arm
 *   func_02035268   0x02035268  arm
 *   func_02035DC8   0x02035DC8  arm
 *   func_02035428   0x02035428  arm
 *   func_02035284   0x02035284  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   OS_ResetSystem            0x02087BCC  arm
 *   OS_WaitIrq                0x0208459C  arm
 *   g_021469BC     0x021469BC  data
 *   str_020A798C   0x020A798C  data
 *   g_021469C4     0x021469C4  data
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   TP_Init              0x0208A924  arm
 *   TP_GetUserInfo       0x0208A998  arm
 *   TP_SetCalibrateParam 0x0208AA2C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0208AB1C  0x0208AB1C  arm
 *   func_0208ABB8  0x0208ABB8  arm
 *   func_0208ADB4  0x0208ADB4  arm
 *   func_0208B104  0x0208B104  arm
 *   func_0208AC0C  0x0208AC0C  arm
 *   func_0208AD14  0x0208AD14  arm
 *   func_0208B220  0x0208B220  arm
 *   func_0208B238  0x0208B238  arm
 *   g_020A799C    0x020A799C  data
 *   func_0203521C  0x0203521C  arm
 *   func_02039548  0x02039548  arm
 *   func_02034714  0x02034714  arm
 *   file_020A79A4  0x020A79A4  data
 *   str_020A79B4   0x020A79B4  data
 *   file_020A79C0    0x020A79C0  data
 *   _s32_div_f  0x0209C0A4  arm
 */
#include "../../matched/include/Obj11334.h"
#include "../../matched/include/Obj11335.h"
#include "../../matched/include/Obj11336.h"
#include "../../matched/include/Obj11337.h"
#include "../../matched/include/Obj07103.h"
#include "../../matched/include/Obj06933.h"
#include "../../matched/include/Obj11338.h"
#include "../../matched/include/Obj11339.h"
#include "../../matched/include/Obj11343.h"
#include "../../matched/include/Obj15897.h"
#include "../../matched/include/Obj11344.h"
#include "../../matched/include/Obj11345.h"
#include "../../matched/include/Obj11346.h"
#include "../../matched/include/Obj01465.h"
#include "../../matched/include/Obj15900.h"
#include "../../matched/include/Obj05731.h"
#include "../../matched/include/Obj15901.h"
#include "../../matched/include/Obj15902.h"
#include "../../matched/include/Obj11347.h"
#include "../../matched/include/Obj15903.h"
#include "../../matched/include/Obj11348.h"
#include "../../matched/include/Obj05732.h"

#define HW_BUTTON_XY_BUF    0x02FFFFA8
#define REG_KEYINPUT        0x04000130
#define PAD_ALL_MASK        0x2FFF
struct TPData;
struct Kind;
struct R;
struct Ctx02035C48;
struct Obj;
struct Sys;
struct Conn;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef void (*UiCb)(void *);

typedef int  (*UiPred)(void *);

struct Sys {
    u8      pad00[0x10];
    UiCb    on_10;
    UiCb    on_14;
    UiCb    on_18;
    UiCb    on_1c;
    UiCb    on_20;
    UiPred  on_24;
    void   *arg_28;
    void   *arg_2c;
    void   *arg_30;
    void   *arg_34;
    u8      always;
    u8      pad39[2];
    u8      backlight;
    u8      unk_3c;
    u8      unk_3d;
    u8      unk_3e;
    u8      unk_3f;
    u8      pad40[3];
    u8      suspended;
};

typedef unsigned short u16;

typedef struct {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
    u16 f08;
    u8  f0A;
    u8  f0B;
} S12;

typedef struct {
    struct Sys *sys;
    int (*f04)(S12 *dst, S12 *src);
} Desc;

struct Kind {
    u8 pad00[0x3D];
    u8 unk3D;
};

typedef signed int     s32;

struct Work {
    u8  pad00[0x5c];
    u16 f5c;
    u16 f5e;
    u16 f60;
    u16 f62;
    u16 f64;
    u16 f66;
    u16 f68;
    u16 f6a;
    u16 f6c;
    u16 f6e;
    u16 f70;
    u16 f72;
    u8  f74;
};

struct Samp {
    u16 x;
    u16 y;
    u16 v;
    u16 t;
};

struct R {
    u8 t;
    u8 a;
    u8 b;
    u8 c;
};

struct Sio_02035D5C {
    u8 pad_00[0x0c];
    u8 buf[0x4c];
    u16 unk58;
    u16 unk5a;
    u8 pad_5c[0x19];
    u8 unk75;
};

struct Sio_02035E54 {
    u8 pad_00[0x64];
    u16 unk64;
    u16 unk66;
    u16 unk68;
    u16 unk6a;
    u16 unk6c;
    u16 unk6e;
    u16 unk70;
    u16 unk72;
};

typedef struct {
    u8  pad[0x40];
    u32 f40;
    u32 f44;
} T;

typedef volatile u16   vu16;

struct Key {
    u8  pad00[0x0c];
    u32 cont;           /* 0x0c */
    u32 trg;            /* 0x10 */
    u32 rpt;            /* 0x14 */
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    s32 wait;           /* 0x3c */
    s32 speed;          /* 0x40 */
    s32 delay;          /* 0x44 */
};

struct Ent {
    u32 f00;
    u32 f04;
    u8  f08;
    u8  pad09[3];
};

struct Obj {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad0c[0xc];
    u32 f18;
    u32 f1c;
    u32 f20;
};

struct Rec_02036254 {
    u8 pad00[0x40];
    int f40;
    int f44;
};

struct Rec_020362BC {
    u8 pad_00[0x1c];
    u32 unk_1c;
    u8 pad_20[0x08];
    u32 unk_28;
};

struct Rec_020362EC {
    u8 pad_00[0x18];
    u32 unk_18;
    void *unk_1c;
    u32 unk_20;
    u32 unk_24;
    void *unk_28;
    u32 unk_2c;
    u8 pad_30[0x10];
    u32 unk_40;
    u32 unk_44;
};

struct Rec_02036390 {
    u8 pad_00[0x24];
    u32 unk24;
    u32 unk28;
    u32 unk2c;
    u32 unk30;
    u32 unk34;
    u32 unk38;
};

struct Rec_02036290 {
    const void *f0;
};

struct Rec {
    u32 unk0;
    u32 unk4;
    u8  pad8[4];
    u16 unkC;
    u16 unkE;
};

typedef struct {
    u8   *buf;
    int   size;
    u32   pad8;
    short head;
    volatile short tail;
} NetRingBuff;

struct Rec_020363B8 {
    u8 pad00[0x1c];
    int f1C;
    u8 pad_20[0x8];
    int f28;
};

struct Rec_020363D4 {
    u8 pad00[0x18];
    int f18;
    u8 pad_1c[0x8];
    int f24;
};

struct Rec_020363F0 {
    u8 pad00[0x20];
    int f20;
    u8 pad_24[0x8];
    int f2C;
};

struct Seq_0203660C {
    int f0;
    int f4;
};

extern int func_020353B0(void);
extern int PM_SetBackLight(u32 which, u32 status);
extern struct Sys *func_02035224(void);
extern int  func_020353F8(struct Sys *p);
extern void func_02035E08(void);
extern void func_0203524C(struct Sys *p);
extern void PM_GoSleepMode(u32 trigger, u32 a, u32 b);
extern void func_020353C8(struct Sys *p);
extern void func_020352AC(struct Sys *p);
extern void func_02035268(struct Sys *p);
extern void func_02035DC8(void);
extern void func_02035428(u32 status);
extern void func_02035284(struct Sys *p);
extern struct Sys *sub_02035224(void);
extern void GXx_SetMasterBrightness_(u32 reg, int brightness);
int func_0203CEAC(void (*a0)(u32));
extern u32 func_0203D210(void);
extern u32 func_02076B8C(void);
extern void OS_ResetSystem(u32 param);
extern void OS_WaitIrq(u32 clear, u32 irqFlags);
extern u32 func_0203CF5C(void);
extern void func_0204E638(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dst, u8 val, u32 size);
extern void  TP_Init(void);
extern int   TP_GetUserInfo(u16 *info);
extern void  TP_SetCalibrateParam(u16 *info);
extern void *func_02082BCC(void *dst, int val, u32 size);
extern void func_0208AB1C(void);
extern u32 func_0208ABB8(struct TPData *result);
extern void func_0208ADB4(struct TPData *result);
extern void func_0208B104(struct TPData *disp, const struct TPData *raw);
extern int sub_02035C20(const void *p);
extern void func_0208AC0C(u32 a, u32 b, void *c, u32 d);
extern void func_0208AD14(void);
extern void func_0208B220(u32 slot);
extern u32 func_0208B238(u32 slot);
extern u32 func_0203521C(u32 *p);
extern void func_02039548(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
int sub_020353B0(void);
void sub_020353C8(struct Sys *p);
int sub_020353F8(struct Sys *p);
void sub_02035428(u32 status);
void sub_0203545C(void);
void func_02035544(u32 param);
u8 sub_020355C4(void);
void sub_020355D8(u8 v);
void sub_020355EC(struct Sys *p);
void sub_020355F8(struct Sys *unused, u8 v);
u8 sub_0203560C(struct Sys *p);
void sub_02035614(u8 v);
u8 sub_02035630(void);
void sub_02035648(void);
void sub_02035660(u8 v);
int func_0203568C(void);
void func_020356A0(int a0);
int func_02035750(void);
u16 func_02035760(struct Kind *p);
u16 func_02035780(struct Kind *p);
int func_020357A0(struct Kind *p);
u16 func_020357C0(struct Kind *p);
void *sub_020357E0(u32 id);
void func_020358A0(struct Sys *ctx);
void func_02035A60(void);
u32 func_02035A70(u8 *p, s32 x, s32 y);
u32 func_02035AA4(u8 *p, u32 a, u32 b);
int func_02035ADC(struct R *p, u32 x, u32 y);
int func_02035B58(u32 a, u32 b);
int func_02035BA4(const void *p);
int func_02035BBC(void *ctx, void *param);
int func_02035C08(const void *p);
int func_02035C20(const void *p);
int sub_02035C38(void);
u16 func_02035C48(struct Ctx02035C48 *ctx);
int sub_02035C60(void);
u32 sub_02035C70(struct Sys *ctx, u32 *outA, u32 *outB);
u32 sub_02035CB8(u32 *outA, u32 *outB);
u32 sub_02035CD8(struct Sys *ctx, u32 *outA, u32 *outB);
u32 sub_02035D20(u32 *outA, u32 *outB);
u32 sub_02035D40(struct Sys *ctx, u32 a, u32 b);
u32 sub_02035D5C(struct Sio_02035D5C *p);
void sub_02035D98(struct Sio_02035D5C *p);
void sub_02035DC8(void);
void sub_02035DD8(struct Sio_02035D5C *p);
void sub_02035E08(void);
u32 sub_02035E18(struct Sio_02035D5C *p);
void sub_02035E54(struct Sys *p);
void func_02035E84(void *p, u16 a, u16 b, u16 c, u16 d);
int func_02035EB0(int a0, int a1, int a2);
int func_02035ECC(int a0, int a1, int a2);
T *func_02035EE8(u32 a);
void func_02035F38(struct Sys *ctx);
void sub_020360A8(void);
void func_020360B8(struct Obj *o);
int func_02036254(int a0, int a1, int a2);
int func_02036270(int a0, int a1);
int func_02036290(int a0, const void *a1);
void func_020362A4(const void *p);
u32 sub_020362BC(struct Sys *ctx);
u32 sub_020362DC(void);
u32 sub_020362EC(struct Sys *ctx);
u32 sub_0203630C(void);
u32 sub_0203631C(struct Sys *ctx);
u32 sub_0203633C(void);
void sub_0203634C(struct Sys *ctx, u32 *outA, u32 *outB);
void sub_02036370(u32 *outA, u32 *outB);
void sub_02036390(struct Sys *p);
int func_020363B8(int a0, int a1, int a2);
int func_020363D4(int a0, int a1, int a2);
int func_020363F0(int a0, int a1, int a2);
void func_0203640C(struct Rec *p, u32 a, int b);
void func_02036428(NetRingBuff *r, const u8 *src, int len);
int func_020364D4(char *p, unsigned char *dst, int len, int max);
u32 func_02036500(u32 a);
u32 func_02036540(u32 a);
int func_02036568(const NetRingBuff *r, u8 *dst, int len, int max);
int func_020365E8(char *p);
int func_0203660C(int a0, int a1, int a2, int a3);
int func_02036624(void *p, int v);
int func_02036640(char *p);
void func_0203666C(void);
u8 *func_02036670(u32 *p);
int func_020366A8(struct Conn *p);
int func_020366C0(char *p);
u32 func_020366FC(u32 *p);
void func_02036738(char *q, int v);
extern Desc g_021469BC;
extern const char str_020A798C[];
extern void *g_021469C4;
extern u8 g_020A799C[];
extern const char file_020A79A4[];
extern const char str_020A79B4[];
extern const char file_020A79C0[];









/*
 * The "is the lid state low enough to keep running" predicate: normalise
 * func_0203568C's level to a boolean at the threshold 2.  Written as a
 * signed compare, so the two constant arms come out as movle/movgt off one
 * `cmp r0, #2` instead of a branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020353B0.c \n *       --func sub_020353B0 --addr 0x020353B0 --cc 1.1p1 --arm
 */
int sub_020353B0(void)
{
    return func_0203568C() <= 2;
}









/*
 * Run the +0x20 hook, but only when one is installed and sub_020353B0 says
 * the state allows it.  The two guards each carry their own `popeq`: a call
 * sits between them, so they cannot share an exit block and are two `if`s
 * rather than one `&&`.
 *
 * The hook pointer is re-read after the sub_020353B0 call, and the argument
 * at +0x30 is loaded before it, because nothing proves the call left the
 * context alone.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020353C8.c \n *       --func sub_020353C8 --addr 0x020353C8 --cc 1.1p1 --arm
 */
void sub_020353C8(struct Sys *p)
{
    if (p->on_20 == 0) {
        return;
    }
    if (func_020353B0() == 0) {
        return;
    }
    p->on_20(p->arg_30);
}








/*
 * The context's veto predicate: the byte at +0x38 forces a yes, otherwise a
 * hook at +0x24 decides, and with no hook the answer is no.  The hook
 * pointer stays in r1 from its own null test through the `blx`, which is why
 * the argument at +0x34 is fetched into r0 second.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020353F8.c \n *       --func sub_020353F8 --addr 0x020353F8 --cc 1.1p1 --arm
 */
int sub_020353F8(struct Sys *p)
{
    if (p->always != 0) {
        return 1;
    }
    if (p->on_24 == 0) {
        return 0;
    }
    return p->on_24(p->arg_34);
}







/*
 * Retry PM_SetBackLight on the bottom screen until it reports success or a
 * thousand attempts have gone by.  The loop counter is assigned before the
 * hoisted screen selector, which is what puts `mov r5, #0` ahead of
 * `mov r4, #2`
 * (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035428.c \n *       --func sub_02035428 --addr 0x02035428 --cc 1.1p1 --arm
 */
void sub_02035428(u32 status)
{
    int i;

    for (i = 0; i < 1000; i++) {
        if (PM_SetBackLight(2, status) == 0) {
            return;
        }
    }
}






/*
 * The lid/sleep service, one of the five sub_02034EF8 runs per frame.  Bit
 * 15 of the halfword at 0x02FFFFA8 is the lid-closed flag; when it is set
 * and the veto predicate sub_020353F8 says no, the machine goes to sleep
 * with the whole shutdown/wake sequence around it, and when the predicate
 * says yes the context is instead marked as suspended (+0x43) with the
 * backlight forced off.  An open lid undoes the suspension.
 *
 * The flag is read as a signed `int`, hence `asrs r1, r1, #0xf` rather than
 * a logical shift: the halfword zero-extends into an `int`, the mask keeps
 * it positive, and the shift inherits the signed type.
 *
 * The literal 0 sits in r5 for the whole function because PM_GoSleepMode's
 * second and third arguments and the +0x43 store all want it.
 *
 * PARKED AT MATCH.  Every concrete byte is right, and fifteen of the sixteen
 * relocation sites resolve.  The sixteenth, PM_GoSleepMode at 0x0208C154, is
 * reached from exactly one place in the whole image: the `bl` at 0x020354A4
 * inside this function.  `label` therefore has no outside branch, and
 * `matched` would need an EXACT manifest entry for TwlSDK libspi code.  No
 * split can help, because the site is inside the only function that needs
 * it.
 *
 * This is what caps src/pending/sub_02034EF8.c as well.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0203545C.c \
 *       --func sub_0203545C --addr 0x0203545C --cc 1.1p1 --arm
 */
void sub_0203545C(void)
{
    struct Sys *p;

    p = func_02035224();

    if ((*(u16 *)0x02FFFFA8 & 0x8000) >> 15) {
        if (func_020353F8(p) == 0) {
            func_02035E08();
            func_0203524C(p);
            PM_GoSleepMode(0xC, 0, 0);
            func_020353C8(p);
            func_020352AC(p);
            func_02035268(p);
            func_02035DC8();
            if (p->suspended != 0) {
                p->suspended = 0;
                func_02035428(p->backlight);
            }
        } else {
            if (p->suspended == 0) {
                p->suspended = 1;
                func_02035428(0);
                func_02035284(p);
                func_0203524C(p);
            }
        }
    } else {
        if (p->suspended != 0) {
            p->suspended = 0;
            func_02035428(p->backlight);
            func_02035268(p);
            func_020352AC(p);
        }
    }
}





/*
 * The soft-reset trap: fade both screens to white, tear the UI down, then spin
 * forever pumping the main loop's per-frame work.  The loop never exits (the
 * image's tail is an unconditional `b` back to the func_0203D210 test), and
 * the reset path inside it returns through OS_ResetSystem.
 *
 * Both master-brightness registers come off one pool word: 0x0400006C is the
 * main engine's MASTER_BRIGHT and the sub engine's sits +0x1000 away, which is
 * why the image loads the base once into r5 and spells the second as
 * `add r0, r5, #0x1000`.  The brightness value 0x10 and the OS_WaitIrq mask
 * are both kept in r4 across the calls, and the `mov r4, #1` that retargets it
 * sits before the loop head.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035544.c \
 *       --func func_02035544 --addr 0x02035544 --cc 1.1p1 --arm
 */
void func_02035544(u32 param)
{
    struct Sys *ctx;

    ctx = sub_02035224();
    GXx_SetMasterBrightness_(0x0400006C, 0x10);
    GXx_SetMasterBrightness_(0x0400006C + 0x1000, 0x10);
    func_0203CEAC(0);

    while (1) {
        if (func_0203D210() != 0 && func_02076B8C() != 0) {
            sub_02035428(((u8 *)ctx)[0x3b]);
            OS_ResetSystem(param);
        }
        OS_WaitIrq(1, 1);
        func_0203CF5C();
        func_0204E638();
    }
}




/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0203560C, sub_02035614, sub_02035630, sub_02035648
 *
 * The accessor block of the singleton reached through the pointer at
 * 0x021469BC.  None of these eight functions saves lr, so disasm.py
 * labels none of them; they are visible only by sweeping addresses
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The block is written as instance accessors plus global wrappers that
 * fetch the singleton and forward:
 *
 *   sub_020355C4  read the u8 at +0x3c of the singleton.
 *   sub_020355D8  write it.
 *   sub_020355EC  clear the u8 at +0x3e of a caller-supplied instance.
 *   sub_020355F8  write the u8 at +0x3d.  Takes an instance pointer for
 *                 symmetry with sub_0203560C but ignores it and goes
 *                 through the singleton anyway; the reload of the global
 *                 over r0 is the whole tell.
 *   sub_0203560C  read the u8 at +0x3d of a caller-supplied instance.
 *   sub_02035614  global wrapper over sub_020355F8.
 *   sub_02035630  global wrapper over sub_0203560C.
 *   sub_02035648  global wrapper over sub_020355EC.
 *
 * The range deliberately stops before sub_02035660, the one labelled
 * function of this file: its calls to 0x02036390 and 0x02035E54 have no
 * witness outside the file, so including it caps the whole unit at MATCH.
 * It is parked in src/pending/sub_02035660.c.
 *
 * Every wrapper is a pool word and a `bx ip`, never a displacement
 * branch, because each function is its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020355C4.c \
 *       --addr 0x020355C4 --arm
 */
u8 sub_020355C4(void)
{
    return g_021469BC.sys->unk_3c;
}




void sub_020355D8(u8 v)
{
    g_021469BC.sys->unk_3c = v;
}




void sub_020355EC(struct Sys *p)
{
    p->unk_3e = 0;
}




void sub_020355F8(struct Sys *unused, u8 v)
{
    g_021469BC.sys->unk_3d = v;
}




u8 sub_0203560C(struct Sys *p)
{
    return p->unk_3d;
}




void sub_02035614(u8 v)
{
    sub_020355F8(g_021469BC.sys, v);
}




u8 sub_02035630(void)
{
    return sub_0203560C(g_021469BC.sys);
}




void sub_02035648(void)
{
    sub_020355EC(g_021469BC.sys);
}



void sub_02035660(u8 v)
{
    sub_020355F8(g_021469BC.sys, v);
    sub_02036390(g_021469BC.sys);
    sub_02035E54(g_021469BC.sys);
}



int func_0203568C(void)
{
    return g_021469BC.sys->unk_3f;
}




/*
 * A descriptor fan-out: the global at 0x021469BC carries a callback at +4
 * which fills two twelve-byte records on the stack, and the seven
 * accessors below push each pair into the object in a0.
 */
void func_020356A0(int a0)
{
    S12 b;
    S12 a;

    if (g_021469BC.f04 == 0) {
        return;
    }
    if (g_021469BC.f04(&b, &a) == 0) {
        return;
    }
    func_020363B8(a0, b.f00, a.f00);
    func_020363D4(a0, b.f02, a.f02);
    func_020363F0(a0, b.f04, a.f04);
    func_02035E84((void *)a0, b.f06, b.f08, a.f06, a.f08);
    func_02035EB0(a0, b.f0A, a.f0A);
    func_02035ECC(a0, b.f0B, a.f0B);
}



int func_02035750(void){ return *(int *)(0x21469C4); }




/*
 * A one-liner over the object at 0x021469C4: when the kind byte at +0x3D is
 * 0x1E (30) the halfword at +0x64 is reported, otherwise the one at +0x5C.
 * The kind test is on the *argument*, the two halfwords on the object the
 * accessor func_02035750 returns, which is why the argument is kept in r4
 * across the call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035760.c \
 *       --func func_02035760 --addr 0x02035760 --cc 1.1p1 --arm
 */
u16 func_02035760(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11334 *)q)->f64;
    return ((struct Obj11334 *)q)->f5C;
}



/*
 * The second halfword pair of the same accessor family as
 * src/matched/func_02035760.c: kind byte +0x3D == 0x1E selects +0x66, else
 * +0x5E.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035780.c \
 *       --func func_02035780 --addr 0x02035780 --cc 1.1p1 --arm
 */
u16 func_02035780(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11335 *)q)->f66;
    return ((struct Obj11335 *)q)->f5E;
}



/*
 * Third of the family in src/matched/func_02035760.c: kind byte +0x3D == 0x1E
 * selects +0x6A, else +0x62.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020357A0.c \
 *       --func func_020357A0 --addr 0x020357A0 --cc 1.1p1 --arm
 */
int func_020357A0(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11336 *)q)->f6A;
    return ((struct Obj11336 *)q)->f62;
}



/*
 * Fourth of the family in src/matched/func_02035760.c: kind byte +0x3D ==
 * 0x1E selects +0x68, else +0x60.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020357C0.c \
 *       --func func_020357C0 --addr 0x020357C0 --cc 1.1p1 --arm
 */
u16 func_020357C0(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11337 *)q)->f68;
    return ((struct Obj11337 *)q)->f60;
}



/*
 * Allocates the touched-icon work object (0x7c bytes), clears it, brings
 * the touch panel up and stores the calibration handed back by
 * TP_GetUserInfo.  When the user has no stored calibration (the call does
 * not answer 1) the four halfwords are filled with the firmware defaults
 * 0x2ae / 0x58c / 0xe25 / 0x1208; 0x58c is materialised as
 * `0x510 + 0x7c` because the size constant is still live in r6.  The
 * object pointer is published at 0x021469C4 and returned.
 *
 * The two bytes at +0x75/+0x76 are the state and the blinking flag of the
 * icon driver; the u16 pair at +0x58 is cleared before the panel is up.
 */
void *sub_020357E0(u32 id)
{
    u16 info[4];
    void *p = func_02030734(id, 0x7c, 0, str_020A798C, 0x83);

    MI_CpuFill8(p, 0, 0x7c);
    ((struct Obj07103 *)p)->f58 = 0;
    ((struct Obj07103 *)p)->f5A = 0;
    TP_Init();
    if (TP_GetUserInfo(info) == 1) {
        TP_SetCalibrateParam(info);
    } else {
        info[0] = 0x2ae;
        info[1] = 0x58c;
        info[2] = 0xe25;
        info[3] = 0x1208;
        TP_SetCalibrateParam(info);
    }
    ((struct Obj07103 *)p)->f75 = 4;
    ((struct Obj07103 *)p)->f76 = 0;
    g_021469C4 = p;
    return p;
}



/*
 * The touch-panel sampling pass of the touchpanel.c family: it resolves the
 * work object, refuses to run with the lid closed, samples the panel (with a
 * bounded debounce retry), converts the raw sample, and then does the edge /
 * latch bookkeeping over the halfword block at +0x5c..+0x72.
 *
 * Bit 15 of the halfword at 0x02FFFFA8 is the lid-closed flag, the same
 * hardware address src/matched/sub_0203545C.c reads; it is a cast constant,
 * not a relocation (docs/idioms/volatile-reread-needs-two-locals.md).  When
 * it is set the whole 0x7c-byte object is cleared and the pass returns.
 *
 * Three declaration facts carry the register allocation, and none of them is
 * visible in the control flow:
 *
 *   - The two sample buffers are laid out `raw` first and `cal` second, but
 *     the ORIGINAL passes sp+8 to the sampler and sp+0 to the converter, so
 *     `cal` is the sp+0 object: the dispatch code the function tests is
 *     `cal.t` at [sp,#6] and the state word it latches is `cal.v` at [sp,#4].
 *     Getting those two fields the wrong way round moves every stack offset
 *     in the tail.
 *   - `struct Samp` is x, y, v, t: the `v`/`t` order is what puts the tested
 *     halfword at +6 rather than +4.
 *   - The resolver's result is bound to its own local `sio` DECLARED LAST and
 *     copied into `w`.  Initialising `w` from the call directly, or declaring
 *     `sio` before `w`, swaps r4 and r5 through the whole body; the extra
 *     copy is what splits the live range so that the loop counter keeps r4.
 *     The permuter found this as `temp(tmp=func_02035750(ctx))`.
 *
 * The `% 2 == 0` tail test compiles to the lsr/rsb/adds triple at +0x168,
 * the signed-remainder-by-two idiom on a signed char field.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020358A0.c \
 *       --func func_020358A0 --addr 0x020358A0 --cc 1.1p1 --arm
 */
void func_020358A0(struct Sys *ctx)
{
    struct Samp raw;
    struct Samp cal;
    struct Work *w;
    u32 done = 0;
    u32 n;
    struct Work *sio = (struct Work *)func_02035750();

    w = sio;
    if (w == 0) {
        return;
    }
    if ((s32)(*(u16 *)0x02FFFFA8 & 0x8000) >> 15 != 0) {
        func_02082BCC(w, 0, 0x7c);
        return;
    }
    if (w->f74 == 0) {
        n = 0;
        func_0208AB1C();
        if (func_0208ABB8((struct TPData *)(&raw)) != 0) {
            do {
                n = (n + 1) & 0xff;
                if (n >= 0x20) {
                    cal.t = 3;
                    done = 1;
                    break;
                }
                func_0208AB1C();
            } while (func_0208ABB8((struct TPData *)(&raw)) != 0);
        }
    } else {
        func_0208ADB4((struct TPData *)(&raw));
    }
    if (done == 0) {
        func_0208B104((struct TPData *)(&cal), (const struct TPData *)(&raw));
    }
    if (cal.t == 0) {
        w->f5c = cal.x;
        w->f5e = cal.y;
    } else if (w->f62 != 0) {
        if (cal.t != 1) {
            if (cal.t == 2) {
                w->f5c = cal.x;
            }
        } else {
            w->f5e = cal.y;
        }
    } else {
        cal.v = 0;
    }
    w->f60 = cal.v & (cal.v ^ w->f62);
    w->f62 = cal.v;
    w->f70 = w->f70 | w->f60;
    w->f72 = w->f72 | w->f62;
    if (w->f5e != 0) {
        w->f6e = w->f5e;
    }
    if (w->f5c != 0) {
        w->f6c = w->f5c;
    }
    if (ctx->unk_3e % 2 == 0) {
        w->f64 = w->f6c;
        w->f66 = w->f6e;
        w->f68 = w->f70;
        w->f6a = w->f72;
        w->f6c = 0;
        w->f6e = 0;
        w->f70 = 0;
        w->f72 = 0;
    }
}



/*
 * Previously parked at MATCH: the `bl` to 0x020358A0 had no outside witness.
 * Closed 2026-09-22 (family wave 5) when 0x020358A0 was itself decompiled to
 * EXACT in src/matched/func_020358A0.c; that manifest entry is now the
 * witness and the site resolves on class `matched`.
 *
 * Two calls in a row: the first one's result is the second one's argument,
 * handed over in r0 with nothing in between.  Nothing else: no stack frame,
 * no locals.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035A60.c \
 *       --func func_02035A60 --addr 0x02035A60 --cc 1.1p1 --arm
 */
void func_02035A60(void)
{
    func_020358A0((struct Sys *)func_02035224());
}



/*
 * The radius test of a packed four-byte record: (x - p[1])^2 + (y - p[2])^2 is
 * compared against p[3]^2, and the answer is 1 when it is strictly smaller.
 * The two differences are the second and third arguments, which is why the
 * argument registers r1 and r2 are subtracted from p[1] and p[2] rather than
 * the other way round.
 *
 * Two tells worth keeping.  The squared radius is computed with `smulbb`,
 * a 16x16 multiply, because p[3] is a `u8` and mwcc knows both factors fit in
 * sixteen bits; the two distance squares need the full 32-bit `mul`/`mla`
 * because their operands are `int` differences.  And the comparison is
 * unsigned (`movcc`/`movcs`), which is free here: both sides are sums of
 * squares and therefore non-negative, so mwcc may pick either.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035A70.c \
 *       --func func_02035A70 --addr 0x02035A70 --cc 1.1p1 --arm
 */
u32 func_02035A70(u8 *p, s32 x, s32 y)
{
    s32 dx = p[1] - x;
    s32 dy = p[2] - y;
    u32 r = p[3];

    return (u32)(dx * dx + dy * dy) < r * r;
}



/*
 * The rectangular counterpart of src/matched/func_02035A70.c, on the same
 * packed four-byte record: a point (a, b) is inside when both distances from
 * the low corner fit in the record's width and height, each spelled as the
 * one-sided range test `v - lo <= hi - lo`.
 *
 * Written as `if (c1 && c2) return 1; return 0;`, the whole body compiles to
 * a single chain of conditionally executed instructions - the second pair of
 * loads, the two subtractions and the comparison all carry the LS condition
 * of the first comparison, and the two `movls`/`movhi` are the boolean - and
 * that chain is exactly the original.  A bare `return c1 && c2;` instead
 * presets a zero register and branches, which is 4 bytes longer and does not
 * match; the `return`-in-`if` spelling is what this source needs, the same
 * shape docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md
 * describes for the disjunction.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035AA4.c \
 *       --func func_02035AA4 --addr 0x02035AA4 --cc 1.1p1 --arm
 */
u32 func_02035AA4(u8 *p, u32 a, u32 b)
{
    if (a - p[2] <= (u32)(p[3] - p[2]) && b - p[0] <= (u32)(p[1] - p[0]))
        return 1;
    return 0;
}



/*
 * The hit-test table walk of the touchpanel.c family.  It scans an array of
 * four-byte records for the first one the point (x, y) falls inside, and
 * returns that record's index, or -1 when the table runs out.  Byte 0 of a
 * record is the shape tag: 0xFF ends the table, 0xFD skips the entry, 0xFE
 * selects the circle test at func_02035A70 and anything else the rectangle
 * test at func_02035AA4.
 *
 * THE DECLARATION IS THE WHOLE FUNCTION.  Written with a `u8 *` parameter
 * and the record address spelled `p + i * 4` (any of: a `rec` local at any
 * scope, `&p[i*4]`, a `u32 *` base with a cast, or the expression written
 * out at each call site), the body compiles to a 21-byte residue in the head
 * that no amount of statement shuffling moves.  The original computes the
 * record address with `add r0, r7, r4, lsl #2` AFTER both argument moves,
 * keeping the tag byte in r0 across the two compares; every pointer-arithmetic
 * spelling hoists the address above the compares instead, which pushes the
 * tag into r1 and rotates the rest.
 *
 * Declaring the record as a struct and indexing the array (`p[i].t`, with
 * `&p[i]` cast for the calls) is what reproduces it: the address becomes an
 * addressing-mode computation the scheduler is free to sink below the
 * compares rather than a value that has to be live across them.  This is the
 * "residue the permuter cannot move at all is usually in the declarations"
 * case: tools/permuter.py plateaus at 8 bytes out from every pointer-spelled
 * start (its best single mutation, `temp(tmp=p + (i * 4))`, is a loop-invariant
 * hoist that is not value-preserving here), and the struct declaration is
 * EXACT with no mutation at all.
 *
 * Supersedes the near miss recorded in docs/notes/pkt_02035ADC.c.txt, which
 * tried four pointer spellings and reached the same 21-byte head.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035ADC.c \
 *       --func func_02035ADC --addr 0x02035ADC --cc 1.1p1 --arm
 */
int func_02035ADC(struct R *p, u32 x, u32 y)
{
    int i = 0;

    while (p[i].t != 0xff) {
        if (p[i].t != 0xfd) {
            if (p[i].t == 0xfe) {
                if (func_02035A70((u8 *)&p[i], x, y) != 0) {
                    return i;
                }
            } else {
                if (func_02035AA4((u8 *)&p[i], x, y) != 0) {
                    return i;
                }
            }
        }
        i++;
    }
    return -1;
}



int func_02035B58(u32 a, u32 b)
{
    u32 x;
    u32 y;

    func_02035750();
    if (func_020357A0((struct Kind *)a) == 0) {
        return -1;
    }
    x = func_02035760((struct Kind *)a);
    y = func_02035780((struct Kind *)a);
    return func_02035ADC((struct R *)b, x, y);
}



int func_02035BA4(const void *p)
{
    return func_02035B58((u32)func_02035224(), (u32)p);
}




int func_02035BBC(void *ctx, void *param)
{
    void *a;
    void *b;

    func_02035750();
    if (func_020357C0(ctx) == 0) {
        return -1;
    }

    a = (void *)func_02035760(ctx);
    b = (void *)func_02035780(ctx);

    return func_02035ADC(param, (u32)a, (u32)b);
}




int func_02035C08(const void *p)
{
    return func_02035BBC((void *)((int)func_02035224()), (void *)p);
}




int func_02035C20(const void *p)
{
    func_02035750();
    return func_020357A0((struct Kind *)p);
}




/*
 * A two-call forwarder in the ARM SDK-style block at 0x02035000..0x02038000:
 * "push {r3, lr}; bl sub_02035224; bl sub_02035C20; pop {r3, pc}", sixteen
 * bytes, no register setup between the calls: the first call's result is
 * still in r0 as the second call's argument, and the second call's result
 * is returned.
 *
 * Byte-correct.  sub_02035224 resolves on the `label` class (58 branches to
 * it image-wide, e.g. 0x02035460).  sub_02035C20 does not: this call is its
 * only reference anywhere in the image, so that site stays wildcarded and
 * caps the file at MATCH.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02035C38.c \
 *       --func sub_02035C38 --addr 0x02035C38 --cc 1.1p1 --arm
 */
int sub_02035C38(void)
{
    return sub_02035C20(sub_02035224());
}




/*
 * Hands the same context to both halves of the teardown pair.  The
 * argument is kept in a callee-saved register across the first call
 * rather than reloaded, which is what says it is one parameter passed
 * twice and not two different values.
 *
 * Decompiled to unstick src/pending/sub_02035C60.c, whose only blocking
 * relocation was this address: 0x02035C48 is reached by exactly one
 * branch image-wide (the `bl` at 0x02035C68 inside that caller), so class
 * `label` was unavailable and only an EXACT entry here could attest it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035C48.c \
 *       --func func_02035C48 --addr 0x02035C48 --cc 1.1p1 --arm
 */
u16 func_02035C48(struct Ctx02035C48 *ctx)
{
    func_02035750();
    return func_020357C0((struct Kind *)ctx);
}



/*
 * Forward to func_02035C48 with the context func_02035224 supplies, same
 * "no context argument" shape as the block in unit_02035C70.c.
 *
 * func_02035C48's only call site anywhere in the image is the one right
 * here, inside this 16-byte function, so the `label` class has no witness
 * outside the range under test and --suggest-split cannot help (the
 * function is atomic; there is nothing to cut).  The site resolves on
 * class `matched` against src/matched/func_02035C48.c, decompiled for
 * exactly this purpose.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035C60.c \
 *       --func sub_02035C60 --addr 0x02035C60 --cc 1.1p1 --arm
 */
int sub_02035C60(void)
{
    return func_02035C48((struct Ctx02035C48 *)func_02035224());
}




/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02035D40
 *
 * The singleton-facing half of the 0x02035000 block: every entry point here
 * is the "no context argument" spelling of a worker that lives a little
 * earlier in the file, with func_02035224() supplying the context.
 *
 * sub_02035C70 and sub_02035CD8 are the two two-output readers; they differ
 * only in which predicate gates them (0x020357A0 versus 0x020357C0).  Each
 * is called from exactly one place, its own wrapper in this same file, so
 * the two pairs have to live in one unit for those sites to close as
 * `local` (same shape as src/matched/unit_020362BC.c).
 *
 * sub_02035D40 has no label of its own in the listing: it is an unlabelled
 * follower of sub_02035D20 (its prologue saves nothing).  It is the u16
 * narrowing shim in front of func_02035ADC, and it is the pool-word-and-bx
 * tail call idiom, one section per function.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02035C70.c \
 *       --addr 0x02035C70 --arm
 */
u32 sub_02035C70(struct Sys *ctx, u32 *outA, u32 *outB)
{
    func_02035750();
    if (func_020357A0((struct Kind *)ctx) == 0) {
        return 0;
    }
    *outA = func_02035760((struct Kind *)ctx);
    *outB = func_02035780((struct Kind *)ctx);
    return 1;
}


u32 sub_02035CB8(u32 *outA, u32 *outB)
{
    return sub_02035C70((struct Sys *)func_02035224(), outA, outB);
}


u32 sub_02035CD8(struct Sys *ctx, u32 *outA, u32 *outB)
{
    func_02035750();
    if (func_020357C0((struct Kind *)ctx) == 0) {
        return 0;
    }
    *outA = func_02035760((struct Kind *)ctx);
    *outB = func_02035780((struct Kind *)ctx);
    return 1;
}


u32 sub_02035D20(u32 *outA, u32 *outB)
{
    return sub_02035CD8((struct Sys *)func_02035224(), outA, outB);
}


u32 sub_02035D40(struct Sys *ctx, u32 a, u32 b)
{
    return (u32)func_02035ADC((struct R *)ctx, (u16)a, (u16)b);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02035E08, sub_02035E18
 *
 * The open/close pair of the 0x02035000 block's link layer, plus their
 * no-context wrappers.  sub_02035DD8 brings the link up (state word at +0x5a
 * goes to 1) and sub_02035D98 takes it down (state word goes back to 0);
 * both refuse to act unless the handle at +0x58 is live and the state is not
 * already where they would leave it.
 *
 * The four workers are kept in one unit deliberately: sub_02035D5C,
 * sub_02035D98, sub_02035DD8 and sub_02035E18 are each reached by exactly
 * one branch in the image, the one in this same file, so as separate files
 * every wrapper would cap at MATCH.  Inside one range each site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02035D5C.c \
 *       --addr 0x02035D5C --arm
 */
u32 sub_02035D5C(struct Sio_02035D5C *p)
{
    if (p->unk58 == 0) {
        return 1;
    }
    func_0208AD14();
    func_0208B220(4);
    if (func_0208B238(4) != 0) {
        return 2;
    }
    return 1;
}


void sub_02035D98(struct Sio_02035D5C *p)
{
    struct Sio_02035D5C *sio = (struct Sio_02035D5C *)func_02035750();

    if (sio != 0 && sio->unk5a != 0 && sio->unk58 != 0) {
        sub_02035E18(sio);
        sio->unk5a = 0;
    }
}


void sub_02035DC8(void)
{
    sub_02035D98((struct Sio_02035D5C *)func_02035224());
}


void sub_02035DD8(struct Sio_02035D5C *p)
{
    struct Sio_02035D5C *sio = (struct Sio_02035D5C *)func_02035750();

    if (sio != 0 && sio->unk5a != 1 && sio->unk58 != 0) {
        sub_02035D5C(sio);
        sio->unk5a = 1;
    }
}


void sub_02035E08(void)
{
    sub_02035DD8((struct Sio_02035D5C *)func_02035224());
}


u32 sub_02035E18(struct Sio_02035D5C *p)
{
    u32 ret;

    func_0208AC0C(0, p->unk75, p->buf, 9);
    ret = 2;
    func_0208B220(2);
    if (func_0208B238(2) == 0) {
        ret = 1;
    }
    return ret;
}



/*
 * Zeroes the eight-halfword counter block at +0x64 of the record
 * func_02035750 resolves its argument to.  One of the two follow-up passes
 * that src/pending/sub_02035660.c runs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035E54.c \
 *       --func sub_02035E54 --addr 0x02035E54 --cc 1.1p1 --arm
 */
void sub_02035E54(struct Sys *p)
{
    struct Sio_02035E54 *sio = (struct Sio_02035E54 *)func_02035750();

    sio->unk64 = 0;
    sio->unk66 = 0;
    sio->unk68 = 0;
    sio->unk6a = 0;
    sio->unk6c = 0;
    sio->unk6e = 0;
    sio->unk70 = 0;
    sio->unk72 = 0;
}



/*
 * The setter that mirrors the four accessors of src/matched/func_02035760.c:
 * four halfword stores into the object func_02035750 returns, at +0x64 and
 * +0x66 from the third and fifth arguments and at +0x6C and +0x6E from the
 * second and fourth.  The fifth argument is a stack argument, which is why
 * `ldrh r1, [sp, #0x10]` sits second - the argument area is above the pushed
 * {r4,r5,r6,lr}.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035E84.c \
 *       --func func_02035E84 --addr 0x02035E84 --cc 1.1p1 --arm
 */
void func_02035E84(void *p, u16 a, u16 b, u16 c, u16 d)
{
    u8 *q;

    q = (u8 *)func_02035750();
    ((struct Obj06933 *)q)->f64 = c;
    ((struct Obj06933 *)q)->f66 = d;
    ((struct Obj06933 *)q)->f5C = a;
    ((struct Obj06933 *)q)->f5E = b;
}



int func_02035EB0(int a0, int a1, int a2){ int t0; t0 = func_02035750(); ((struct Obj11338 *)((char *)(t0)))->f68 = (unsigned short)a2; ((struct Obj11338 *)((char *)(t0)))->f60 = (unsigned short)a1; return t0; }




int func_02035ECC(int a0, int a1, int a2){ int t0; t0 = func_02035750(); ((struct Obj11339 *)((char *)(t0)))->f6A = (unsigned short)a2; ((struct Obj11339 *)((char *)(t0)))->f62 = (unsigned short)a1; return t0; }




T *func_02035EE8(u32 a)
{
    T *p = (T *)func_02030734(a, 0x4c, 0, (const char *)g_020A799C, 0x44);

    func_02082BCC(p, 0, 0x4c);
    p->f40 = 8;
    p->f44 = 0xf;
    return p;
}




static inline s32 PAD_DetectFold(void)
{
    return (s32)((*(vu16 *)HW_BUTTON_XY_BUF & 0x8000) >> 15);
}




static inline u16 PAD_Read(void)
{
    return (u16)(((*(vu16 *)REG_KEYINPUT | *(vu16 *)HW_BUTTON_XY_BUF) ^ PAD_ALL_MASK) & PAD_ALL_MASK);
}




/*
 * key.c.  The per-frame pad update: with the lid closed (PAD_DetectFold) the
 * six edge words are cleared; otherwise the pad is read (PAD_Read, the SDK
 * inline: KEYINPUT | the ARM7 XY buffer, ^ and & 0x2FFF, so the 0x2FFF mask
 * is the 0x02FFFFA8 pool word shifted right by 12, not a pool word of its
 * own), UP cancels DOWN and LEFT cancels RIGHT, trigger and repeat are
 * derived from the previous hold word at +0x0C, the repeat counter at +0x3C
 * reloads from +0x40 (speed) or +0x44 (delay), and func_020360B8 then remaps
 * the three published words before they are accumulated into +0x30..+0x38
 * and latched into +0x24..+0x2C on every other frame (ctx->unk_3e, a SIGNED
 * modulo-2 test on a u8 byte).  Both hardware addresses are cast constants, not
 * relocations.  Written from the SDK inline shapes (NitroSDK pad.h, library
 * function shapes only); EXACT on the first transcription.
 */
void func_02035F38(struct Sys *ctx)
{
    struct Key *k = (struct Key *)func_0203521C((u32 *)ctx);
    u16 key;

    if (PAD_DetectFold()) {
        k->f1c = 0;
        k->f18 = 0;
        k->f20 = 0;
        k->f28 = 0;
        k->f24 = 0;
        k->f2c = 0;
        return;
    }

    key = PAD_Read();
    key = key & ~((key & 0x40) << 1) & ~((key & 0x20) >> 1);

    k->trg = key & (key ^ k->cont);
    k->rpt = key & (key ^ k->cont);
    if (key != 0 && k->cont == key) {
        if (--k->wait == 0) {
            k->rpt = key;
            k->wait = k->speed;
        }
    } else {
        k->wait = k->delay;
    }
    k->cont = key;
    k->f1c = k->trg;
    k->f18 = key;
    k->f20 = k->rpt;
    func_020360B8((struct Obj *)k);
    k->f34 |= k->f1c;
    k->f30 |= k->f18;
    k->f38 |= k->f20;
    if (ctx->unk_3e % 2 != 0) {
        return;
    }
    k->f28 = k->f34;
    k->f24 = k->f30;
    k->f2c = k->f38;
    k->f34 = 0;
    k->f30 = 0;
    k->f38 = 0;
}



/*
 * The no-context spelling of func_02035F38: fetch the singleton with
 * func_02035224 and hand it over.  Sixteen bytes, no register setup between
 * the two calls, so the argument count is not visible from the code; the
 * one-argument reading is the one the rest of this file's wrappers take
 * (compare src/matched/unit_020362BC.c).
 *
 * PARKED AT MATCH.  Every concrete byte is right.  func_02035224 resolves on
 * `label`; func_02035F38 does not, because the `bl` at 0x020360B0 inside this
 * function is its only reference anywhere in the image.
 *
 * Identical situation to src/pending/sub_02035A60.c: a tu over
 * 0x02035F38..0x020360B8 would make the site `local`, and 0x02035F38 is 360
 * bytes, left for whoever takes pkt_02035E84.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020360A8.c \
 *       --func sub_020360A8 --addr 0x020360A8 --cc 1.1p1 --arm
 */
void sub_020360A8(void)
{
    func_02035F38((struct Sys *)func_02035224());
}



static inline void m2(u32 *f, struct Ent *p)
{
    u32 v = 0;
    if (*f & p->f00)
        v |= p->f04;
    if (*f & p->f04)
        v |= p->f00;
    *f &= (p->f00 | p->f04) ^ 0xffff;
    *f |= v;
}

static inline void m1(u32 *f, struct Ent *p)
{
    if (*f & p->f00)
        *f |= p->f04;
}

static inline void m3(u32 *f, struct Ent *p)
{
    *f &= p->f00 ^ 0xffff;
}

/*
 * key.c.  Walks a run of 12-byte entries from o->f00 + o->f08 * 12 and
 * applies each entry's mask/value pair to the three state words at
 * +0x1c/+0x18/+0x20: case 1 ORs the value in where the mask matches, case 2
 * swaps the two bit groups (m2), case 3 clears the mask's bits, and case 0
 * ends the walk.  The function has no relocations; its one pooled word is the
 * constant 0x0000FFFF.
 *
 * What closed it (wave 13): the case-2 accumulator is a FRESH zero per field
 * (`u32 v = 0;` inside a per-field helper, or equally a block-scoped local).
 * The three zeros are three distinct values that the optimiser hoists as
 * r3/r2/r1 ahead of the loop, and that is what leaves lr, the highest
 * callee-saved register, for 0xFFFF.  The earlier source kept three
 * function-scope accumulators a, b, c = 0 and copied them into one v per arm;
 * every instruction was right but 0xFFFF and the arm temporaries rotated
 * through r4/r5/r6/lr (127 bytes).  The two compound statements
 * `*f &= mask; *f |= v;` (not one merged assignment) are still what
 * re-reads the field before the AND.
 */
void func_020360B8(struct Obj *o)
{
    struct Ent *p;

    if (o->f00 == 0)
        return;

    p = (struct Ent *)(o->f00 + o->f08 * 12);

    for (;;) {
        switch (p->f08) {
        case 0:
            return;
        case 1:
            m1(&o->f1c, p);
            m1(&o->f18, p);
            m1(&o->f20, p);
            break;
        case 2:
            m2(&o->f1c, p);
            m2(&o->f18, p);
            m2(&o->f20, p);
            break;
        case 3:
            m3(&o->f1c, p);
            m3(&o->f18, p);
            m3(&o->f20, p);
            break;
        }
        p++;
    }
}


int func_02036254(int a0, int a1, int a2)
{
    struct Rec_02036254 *r = (struct Rec_02036254 *)func_0203521C((u32 *)a0);

    r->f40 = a1;
    r->f44 = a2;
    return (int)r;
}

int func_02036270(int a0, int a1)
{
    return func_02036254((int)func_02035224(), a0, a1);
}


int func_02036290(int a0, const void *a1)
{
    struct Rec_02036290 *r = (struct Rec_02036290 *)func_0203521C((u32 *)a0);

    r->f0 = a1;
    return (int)r;
}




void func_020362A4(const void *p)
{
    func_02036290((int)func_02035224(), p);
}




/*
 * A whole translation unit, matched as one byte range.
 *
 * sub_020362BC picks one of two key masks out of the record returned by
 * func_0203521C, keyed on a one-byte mode tag at +0x3d of its own argument;
 * sub_020362DC is the two-call wrapper that runs func_02035224 first.
 *
 * The two are kept in one unit deliberately: sub_020362DC's only call to
 * sub_020362BC has no witness anywhere else in the image, so as separate
 * files sub_020362DC caps at MATCH.  Inside one range the site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020362BC.c \
 *       --addr 0x020362BC --arm
 */
u32 sub_020362BC(struct Sys *ctx)
{
    struct Rec_020362BC *rec = (struct Rec_020362BC *)func_0203521C((u32 *)ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_28;
    }
    return rec->unk_1c;
}


u32 sub_020362DC(void)
{
    return sub_020362BC((struct Sys *)func_02035224());
}



/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0203634C, sub_02036370
 *
 * Three more of the mode-keyed record accessors that src/matched/
 * unit_020362BC.c opens: each picks one of two key masks out of the record
 * func_0203521C returns, keyed on the one-byte mode tag at +0x3d of the
 * context, and each is paired with a no-context wrapper that supplies the
 * context from func_02035224().  sub_0203634C is the two-output form and
 * reads the same field pair for either mode.
 *
 * The three workers have no caller but their own wrapper in this file, so
 * as separate files every wrapper would cap at MATCH; inside one range each
 * site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020362EC.c \
 *       --addr 0x020362EC --arm
 */
u32 sub_020362EC(struct Sys *ctx)
{
    struct Rec_020362EC *rec = (struct Rec_020362EC *)func_0203521C((u32 *)ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_24;
    }
    return rec->unk_18;
}


u32 sub_0203630C(void)
{
    return sub_020362EC((struct Sys *)func_02035224());
}


u32 sub_0203631C(struct Sys *ctx)
{
    struct Rec_020362EC *rec = (struct Rec_020362EC *)func_0203521C((u32 *)ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_2c;
    }
    return rec->unk_20;
}


u32 sub_0203633C(void)
{
    return sub_0203631C((struct Sys *)func_02035224());
}


void sub_0203634C(struct Sys *ctx, u32 *outA, u32 *outB)
{
    struct Rec_020362EC *rec = (struct Rec_020362EC *)func_0203521C((u32 *)ctx);

    *outA = rec->unk_40;
    *outB = rec->unk_44;
}


void sub_02036370(u32 *outA, u32 *outB)
{
    sub_0203634C((struct Sys *)func_02035224(), outA, outB);
}



/*
 * Zeroes the six-word block at +0x24 of the record func_0203521C resolves
 * its argument to.  The other follow-up pass that src/pending/sub_02035660.c
 * runs (see src/matched/sub_02035E54.c for the first).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02036390.c \
 *       --func sub_02036390 --addr 0x02036390 --cc 1.1p1 --arm
 */
void sub_02036390(struct Sys *p)
{
    struct Rec_02036390 *rec = (struct Rec_02036390 *)func_0203521C((u32 *)p);

    rec->unk24 = 0;
    rec->unk28 = 0;
    rec->unk2c = 0;
    rec->unk30 = 0;
    rec->unk34 = 0;
    rec->unk38 = 0;
}


int func_020363B8(int a0, int a1, int a2)
{
    struct Rec_020363B8 *r = (struct Rec_020363B8 *)func_0203521C((u32 *)a0);

    r->f28 = a2;
    r->f1C = a1;
    return (int)r;
}


int func_020363D4(int a0, int a1, int a2)
{
    struct Rec_020363D4 *r = (struct Rec_020363D4 *)func_0203521C((u32 *)a0);

    r->f24 = a2;
    r->f18 = a1;
    return (int)r;
}


int func_020363F0(int a0, int a1, int a2)
{
    struct Rec_020363F0 *r = (struct Rec_020363F0 *)func_0203521C((u32 *)a0);

    r->f2C = a2;
    r->f20 = a1;
    return (int)r;
}





/*
 * Initialises a small record: the two leading words get the first two
 * arguments, and the two halfwords at +0x0C and +0x0E are cleared.  The
 * second argument is declared `s16` and that is visible in the code: the
 * compiler sign-extends it with an `lsl #16` / `asr #16` pair before the
 * two-word `stmia`, which is the only way a narrowed parameter reaches a
 * 32-bit store.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203640C.c \
 *       --func func_0203640C --addr 0x0203640C --cc 1.1p1 --arm
 */
void func_0203640C(struct Rec *p, u32 a, int b)
{
    p->unk0 = a;
    p->unk4 = (short)b;
    p->unkC = 0;
    p->unkE = 0;
}




/*
 * net_ring_buff.c's write: refuse (func_02039548) unless the free space
 * (func_02036640) exceeds len, then copy len bytes in at the +0xE write
 * cursor modulo the capacity (func_02036624), asserting src != NULL at line
 * 0x44 each byte, and store the wrapped cursor back.  The write cursor is
 * declared volatile: the loop bound re-reads it every pass and the first
 * read happens twice, exactly as the image does (the same re-read shape the
 * matched func_020365E8 spells with volatile casts).
 */
void func_02036428(NetRingBuff *r, const u8 *src, int len)
{
    int i;
    int k;

    if (func_02036640((char *)r) <= len) {
        func_02039548();
        return;
    }
    k = 0;
    for (i = r->tail; i < r->tail + len; i++) {
        if (src == 0) {
            func_02034714(file_020A79A4, 0x44, str_020A79B4);
        }
        r->buf[func_02036624(r, i)] = src[k];
        k++;
    }
    r->tail = (short)func_02036624(r, i);
}




/*
 * Blocked: the PC24 at +0008 to 0x02036568 has no witness of any class and no
 * manifest entry is possible this pass: 0x02036568 is a 128-byte ARM function
 * whose C is byte-correct except an eight-instruction schedule permutation of
 * its loop tail (seven spellings measured, all identical) - a DIFF, see
 * docs/notes/pkt_02036568.c.txt.  The second site (func_02036624) resolves as
 * `matched`.  Every concrete byte here reproduces.
 */
int func_020364D4(char *p, unsigned char *dst, int len, int max)
{
    int d = func_02036568((const NetRingBuff *)p, dst, len, max);
    ((struct Obj01465 *)p)->fC = (short)func_02036624(p, ((struct Obj01465 *)p)->fC + d);
    return d;
}





/*
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * second pool word, file_020A79C0, whose only literal pool in the whole image
 * is this function's own, at 0x0203653C and therefore inside the compared
 * range.  The `string` class cannot stand in for it either: 0x020A79C0 holds
 * the one-character string "0" (the listing shows `.word 0x00000030` there,
 * preceded by the terminator of "pDataArea"), and attest_string() requires at
 * least four printable characters before the NUL, so the address is refused by
 * rule 2.  It closes the day the same string address is referenced from a pool
 * outside this range, or the rule's four-character floor is revisited for
 * one-character strings.  The three other sites resolve: func_020364D4 and
 * func_02034714 as `label`, file_020A79A4 as `literal`.
 */
u32 func_02036500(u32 a)
{
    u8 b;

    if (func_020364D4((char *)a, &b, 1, 1) == 1)
        return b;
    func_02034714(file_020A79A4, 0x6C, file_020A79C0);
    return 0;
}





/*
 * Packs two bytes read through src/matched/func_02036500.c into one halfword,
 * high byte first.  The same call is made twice with the same argument.
 *
 * The shape that reproduces the original is `hi = (u16)(call << 8);` - the
 * `u16` narrowing folded into the shift, which mwcc encodes as `lsl r4, r0,
 * #24` (`(x << 8) mod 2^16` starts its life as `x << 24`) with the companion
 * half of the pair spent as the *shift operand* of the `orr`, `orr r0, r0, r4,
 * lsr #16`.  Spelling the mask as a value first - `hi = (u8)call;` or
 * `(u8)hi << 8` - makes mwcc emit `and r4, r0, #0xFF` followed by
 * `orr r0, r0, r4, lsl #8` instead: the same two instructions, the same
 * result, different bytes.  This is the unequal-shift-pair tell of
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 * one level up: with the mask inline mwcc picks the AND form, so the mask has
 * to be on the narrowed *variable*, not on the shifted expression.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036540.c \
 *       --func func_02036540 --addr 0x02036540 --cc 1.1p1 --arm
 */
u32 func_02036540(u32 a)
{
    u16 hi;
    u32 lo;

    hi = (u16)(func_02036500(a) << 8);
    lo = func_02036500(a);
    return (u16)(hi | lo);
}




/*
 * wm_icon.c ring reader. Wave 17 lane untried_small, from 25 out: the ring
 * is a const pointer, in this function and in func_02036624's prototype (both
 * only read it). With the read-only qualifier the compiler hoists the
 * loop-bottom bound load above the byte store through dst, as the image does.
 * The write cursor +0x0E stays volatile (the func_02036428 lever).
 */
int func_02036568(const NetRingBuff *r, u8 *dst, int len, int max)
{
    int i;
    int n;

    n = 0;
    for (i = r->head; i < r->head + len; i++) {
        if (r->tail == func_02036624((void *)r, i) || n == max) {
            return n;
        }
        dst[n] = r->buf[func_02036624((void *)r, i)];
        n++;
    }
    return n;
}




/*
 * 36 bytes with no call: the distance from the cursor at p+0x0C to the end of
 * the buffer at p+0x0E, answered from the buffer base at p+4 when the cursor is
 * past the end.
 *
 * The halfword at p+0x0E is read three times in the original (condition, both
 * arms), which is why it is spelled as a field read in each place rather than
 * bound to a local. Spelling all three as plain field reads is not enough on
 * this front end: it CSEs the two arm reads into the condition's register and
 * the function comes out one instruction (4 bytes) short at 32. Declaring the
 * two arm reads `volatile` keeps all three loads, which is the original's shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020365E8.c \
 *       --func func_020365E8 --addr 0x020365E8 --cc 1.1p1 --arm
 */
int func_020365E8(char *p)
{
    int a = ((struct Obj01465 *)p)->fC;

    if (a > ((struct Obj01465 *)p)->fE)
        return ((struct Obj01465 *)p)->f4 + *(volatile short *)&((struct Obj01465 *)p)->fE - a;
    return *(volatile short *)&((struct Obj01465 *)p)->fE - a;
}


int func_0203660C(int a0, int a1, int a2, int a3)
{
    int t0 = func_020365E8((char *)a0);

    return ((struct Seq_0203660C *)a0)->f4 - t0;
}




int func_02036624(void *p, int v)
{
    return v % ((struct Obj15900 *)p)->f4;
}




static inline int RingUsed(char *p)
{
    int a = ((struct Obj05731 *)p)->fC;
    if (a > ((struct Obj05731 *)p)->fE)
        return ((struct Obj05731 *)p)->f4 + *(volatile short *)&((struct Obj05731 *)p)->fE - a;
    return *(volatile short *)&((struct Obj05731 *)p)->fE - a;
}




/*
 * Free space of a net_ring_buff.c ring: capacity (+4) minus the used count.
 * The used count is the body of the matched sibling func_020365E8 inlined
 * verbatim (its two volatile re-reads of the +0xE cursor are what keep the
 * per-arm reloads the earlier DIFF note could not reproduce).
 */
int func_02036640(char *p)
{
    return ((struct Obj15901 *)p)->f4 - RingUsed(p);
}



void func_0203666C(void){ }




/*
 * Finds the first of `p->unk1C` records (stride 0x14) whose halfword at +0x0E
 * is zero and returns a pointer to it, or NULL when the count is not positive
 * or no record matches.  The found case is a bare `bxeq lr` with the moving
 * pointer still in r0, which is what makes the return type a pointer rather
 * than a boolean: the function returns the record it found, not 1.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036670.c \
 *       --func func_02036670 --addr 0x02036670 --cc 1.1p1 --arm
 */
u8 *func_02036670(u32 *p)
{
    u8  *q;
    s32  i;
    s32  n;

    q = (u8 *)p[6];
    n = (s32)p[7];
    for (i = 0; i < n; i++) {
        if (((struct Obj15902 *)q)->fE == 0)
            return q;
        q += 0x14;
    }
    return 0;
}




int func_020366A8(struct Conn *p)
{
    return func_020366C0((char *)p) == 0;
}



/*
 * Counts the 20-byte records of the array at p+0x18 whose halfword at +0x0E is
 * non-zero, up to the count in p+0x1C.  60 bytes, no calls, no pool: the loop
 * is rotated and the test is a predicated `addne`.
 *
 * The declaration order is the whole lever.  Declared `e, i, c, n` the four
 * locals land in r1, r2, r3 and ip exactly as the image has them: the cursor
 * first, then the index, then the counter (whose `mov r3, #0` then feeds
 * `mov r2, r3` for the index), and the bound last in ip, so the bound's load
 * is the one that survives to just before the `ble`.  With the bound declared
 * first - how this file previously stood - the bound takes r2, the cursor r3
 * and the counter ends up in r0, which frees the `mov r0, r3` before the
 * return and shortens the body to 56 bytes (DIFF).  A param pointer (`u32 *p`
 * plus `q = (u8 *)p[6]`) does not reach it either: the four locals colour the
 * same way whatever the order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020366C0.c \
 *       --func func_020366C0 --addr 0x020366C0 --cc 1.1p1 --arm
 */
int func_020366C0(char *p)
{
    const char *e = *(char * *)&((struct Obj11347 *)p)->f18;
    int         i;
    int         c = 0;
    int         n = ((struct Obj11347 *)p)->f1C;

    for (i = 0; i < n; i++, e += 0x14) {
        if (((struct Obj15903 *)e)->fE != 0)
            c++;
    }
    return c;
}



/*
 * Pops one entry off a singly linked list held at p[0], one link at a time:
 * the successor is p[0]->unk8; when it exists it becomes the new head and its
 * own back pointer at +4 is cleared, otherwise the head and the word after it
 * are both zeroed.  Returns 0 only when the list was already empty.
 *
 * Every arm is conditional-executed, so the function has exactly one `bx lr`
 * per exit and both `strne`/`streq` groups sit on the same `cmp`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020366FC.c \
 *       --func func_020366FC --addr 0x020366FC --cc 1.1p1 --arm
 */
u32 func_020366FC(u32 *p)
{
    u32 v;

    v = p[0];
    if (v != 0) {
        v = ((struct Obj11348 *)v)->f8;
        if (v != 0) {
            p[0] = v;
            ((struct Obj11348 *)v)->f4 = 0;
        } else {
            p[0] = 0;
            p[1] = 0;
        }
        return 1;
    }
    return 0;
}



void func_02036738(char *q, int v)
{
    *(char *)*(char * *)&((struct Obj05732 *)q)->f0 = (char)v;
    *(char * *)&((struct Obj05732 *)q)->f0 = *(char * *)&((struct Obj05732 *)q)->f0 + 1;
    ((struct Obj05732 *)q)->f4 = ((struct Obj05732 *)q)->f4 - 1;
}
