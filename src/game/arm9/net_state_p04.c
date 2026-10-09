/*
 * file:     net_state_p04.c
 * unit:     yes
 * function: func_020377B8, func_0203781C, func_02037858, func_02037894, func_02037928, func_020379C8, func_02037A44, func_02037A6C, func_02037B08, func_02037BA4, func_02037BE8, func_02037C10, func_02037D78, func_02037D98, func_02037E60, func_02037F48, func_0203802C, func_020380E4, func_020381D8, func_02038298, func_02038340, func_02038380, func_02038524, func_02038570, func_020385C4, func_020387A0, func_02038924, func_02038A48, func_02038A90, func_02038AE0, func_02038C18, func_02038D30, func_02038D4C, func_02038D68, func_02038DF0, func_02039050, func_020390BC, func_02039160, func_020392B8, func_020392EC, sub_02039338, sub_020393A8, sub_020393D0, func_02039414, func_02039468, func_020394C0, func_020394DC, func_020394F0, func_02039548, sub_02039560, sub_02039578, sub_02039594, func_020395E0, func_020395EC, func_02039658, func_0203971C, func_02039764, func_02039834, func_020398B4
 * address:  0x020377B8
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
 *   func_0203D798   0x0203D798  arm
 *   func_0203D788   0x0203D788  arm
 *   func_02037288   0x02037288  arm
 *   func_02037680   0x02037680  arm
 *   func_020377AC   0x020377AC  arm
 *   g_020A7A20      0x020A7A20  data
 *   func_020307B0   0x020307B0  arm
 *   func_02036B88   0x02036B88  arm
 *   g_021469D0      0x021469D0  data
 *   func_02039338   0x02039338  arm
 *   func_020393A8   0x020393A8  arm
 *   func_020370F4  0x020370F4  arm
 *   func_020393D0  0x020393D0  arm
 *   func_0203ACAC  0x0203ACAC  arm
 *   func_02037478  0x02037478  arm
 *   lbl_020A7A20    0x020A7A20  data
 *   func_0203D6BC   0x0203D6BC  arm
 *   d_020A7A20     0x020A7A20  data
 *   func_0203D680  0x0203D680  arm
 *   func_020366A8  0x020366A8  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02036428  0x02036428  arm
 *   func_02034714  0x02034714  arm
 *   func_02037224  0x02037224  arm
 *   d_020A7A24     0x020A7A24  data
 *   d_020A7A50     0x020A7A50  data
 *   func_02037258  0x02037258  arm
 *   str_020A7A24   0x020A7A24  data
 *   str_020A7A54   0x020A7A54  data
 *   func_02039548  0x02039548  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   g_020A7A24     0x020A7A24  data
 *   g_020A7A50     0x020A7A50  data
 *   str_020A7A50   0x020A7A50  data
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02036A50  0x02036A50  arm
 *   func_0203C990  0x0203C990  arm
 *   func_02039594  0x02039594  arm
 *   func_020368C0  0x020368C0  arm
 *   func_0203996C   0x0203996C  arm
 *   func_0203A770   0x0203A770  arm
 *   func_02037234   0x02037234  arm
 *   func_020365E8  0x020365E8  arm
 *   func_02036540  0x02036540  arm
 *   func_02036500  0x02036500  arm
 *   func_020364D4  0x020364D4  arm
 *   func_0203A804  0x0203A804  arm
 *   func_0203A7EC  0x0203A7EC  arm
 *   func_0203A634  0x0203A634  arm
 *   func_0203A81C  0x0203A81C  arm
 *   func_02082D44  0x02082D44  arm
 *   g_021469DC     0x021469DC  data
 *   func_0203666C   0x0203666C  arm
 *   func_02036B98 0x02036B98 arm
 *   str_020A7A68   0x020A7A68  data
 *   str_020A7A78   0x020A7A78  data
 *   func_0203A28C  0x0203A28C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   file_020A7A68  0x020A7A68  data
 *   g_021469D4     0x021469D4  data
 *   msg_020A7A7C   0x020A7A7C  data
 *   msg_020A7A88   0x020A7A88  data
 *   sub_0203996C   0x0203996C  arm
 */
#include "../../matched/include/Obj11351.h"
#include "../../matched/include/Obj15917.h"
#include "../../matched/include/Obj15920.h"
#include "../../matched/include/Obj15922.h"
#include "../../matched/include/Obj05734.h"
#include "../../matched/include/Obj11352.h"
#include "../../matched/include/Obj05735.h"
#include "../../matched/include/Obj15929.h"
#include "../../matched/include/Obj15930.h"
#include "../../matched/include/Obj06938.h"
#include "../../matched/include/Obj15931.h"
#include "../../matched/include/Obj15934.h"
#include "../../matched/include/Obj03449.h"
#include "../../matched/include/Obj06939.h"
#include "../../matched/include/Obj15941.h"
#include "../../matched/include/Obj08833.h"
#include "../../matched/include/Obj15944.h"
#include "../../matched/include/Obj15945.h"

struct Conn;
struct Hdr;
struct Entry;
struct Src;
struct St;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct NetRing {
    u8  pad00[8];
    u32 state;          /* 0x08 */
    u8  pad0C[4];
};

/* The object g_021469D0 points at (0x1f0 bytes, allocated by func_02037288). */
struct Net {
    u8  *f00;           /* 0x00 */
    u8  *f04;
    u8  *f08;
    u8  *f0C;
    u8  *f10;
    u8  *f14;
    u8  *f18;
    struct NetRing f1C;
    struct NetRing f2C;
    struct NetRing f3C;
    struct NetRing f4C[8];
    u8  fCC[0x28];
    u8  fF4[0x28];
    u8  f11C[8][16];
    u8  f19C[16];
    u32 f1AC;
    int f1B0;
    int f1B4[8];
    u8  f1D4;
    u8  f1D5;
    u8  f1D6;
    u8  f1D7[8];
    u8  pad1DF;
    u32 f1E0;
    u16 f1E4;
    u8  pad1E6;
    u8  f1E7;
    u8  f1E8;
    u8  f1E9;
    u8  f1EA;
    u8  f1EB;
    u8  f1EC;
    u8  f1ED;
    u8  pad1EE[2];
};

struct Ctx_020377B8 {
    u8   pad00[0x340];
    u32 *f340;
};

struct Oth_020377B8 {
    u8 pad00[0x64];
    u8 f64;
    u8 f65;
};

struct Vtbl {
    u8   pad00[0x64];
    u32 (*f64)(u32, u32, u32, void *);   /* 0x64 */
    u8   pad68[0x70 - 0x68];
    u32 (*f70)(void);                    /* 0x70 */
};

struct Ctx_02037E60 {
    u8           pad00[0x340];
    struct Vtbl *f340;                   /* 0x340 */
};

struct Ctx {
    u8   pad00[0x340];
    u32 *f340;
};

struct Oth_02038380 {
    u8 pad00[0x65];
    u8 f65;
};

struct Oth {
    u8 pad00[0x64];
    u8 f64;
    u8 f65;
};

struct Hdr
{
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 body[1];
};

struct Glob
{
    u8 pad_00[0x65];
    u8 f65;
};

struct Conn
{
    u8 pad_00[0x24];
    u32 f24;
};

struct Vt
{
    u8 pad_00[0x7c];
    u8 (*f7c)(void);
    u8 pad_80[0x30];
    s32 (*fb0)(void);
};

struct Sys
{
    u8 pad_00[0x340];
    struct Vt *f340;
};

struct Buf
{
    void *ptr;
    u16 len;
};

struct Rec {
    u8  pad_00[0x64];
    u8  f64;
};

struct Err {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
};

typedef signed short   s16;

struct Src {
    u8  pad00[0x0c];
    s16 pos;
};

struct St {
    s32 done;
    u8 *dst;
    u16 left;
    u16 total;
    u16 h;
    u8  f0E;
    u8  f0F;
};

typedef signed char   s8;

typedef int           s32_020390BC;

typedef signed int     s32_020392B8;

struct Slots {
    u8 pad_00[0x80];
    s32 (*unk80)(void);
};

struct Owner {
    u8 pad_00[0x340];
    struct Slots *unk340;
};

struct Mode {
    u8 pad_00[0x65];
    u8 unk65;
};

struct LinkDriver_020377B8 {
    unsigned char pad00[0x7c];
    u32 (*get_mask)(void);
};

struct LinkRoot_020377B8 {
    unsigned char pad000[0x340];
    struct LinkDriver_020377B8 *driver;
};

struct LinkDriver_020393D0 {
    u8 pad00[0x88];
    int (*busy)(void);
};

struct LinkRoot_020393D0 {
    u8 pad000[0x340];
    struct LinkDriver_020393D0 *driver;
};

typedef struct {
    u8 pad_000[0x65];
    u8 f065;
} T_0203D798;

struct Session {
    u8 pad00[0x64];
    u8 unk_64;
    u8 state;
};

struct Entry_02039658 {
    void *obj;
    u8    pad_04[4];
    void *slot[8];
    u8    pad_28[0x16];
    u16   key3e;
    u16   key40;
};

struct Entry_02039764 {
    u8    pad_00[8];
    void *slot[8];
    u8    pad_28[0x1c];
    u16   key44;
    u16   key46;
    u8    pad_48;
    u8    f49;
    u8    f4a;
};

struct Entry {
    u8   pad_00[8];
    void *handle[8];
};

extern void *func_0203D798(void);
extern void *func_0203D788(void);
extern int func_02037288(u32 a0, u32 heap, u32 c);
extern void func_02037680(int i);
extern void  func_020377AC(void);
extern u32 func_020307B0(void *p);
extern void  func_02036B88(void *p);
extern u16 func_02039338(void);
extern int   func_020393A8(void);
extern u32  func_020370F4(u32 a);
extern int  func_020393D0(void);
extern void func_0203ACAC(void);
extern void func_02037478(void);
extern u32 func_0203D6BC(void);
extern u32 func_0203D680(void);
extern int func_020366A8(struct Conn *p);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern struct Entry *func_020399A8(void);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_02036428(u8 *dst, u8 *src, s32 len);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02037224(u8 v, int b);
extern u32  func_02037258(void);
extern void func_02039548(void);
extern u32 func_0203CA98(void);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern void MI_CpuFill8(void *, u8, u32);
extern int func_02036A50(u32 list, u16 *info);
extern u32 func_0203C990(void);
extern int    func_02039594(void);
extern int    func_020368C0(void *tbl, u32 a, u32 b, u32 c, u32 d, u32 e,
                            u32 f);
extern int func_020365E8(char *p);
extern struct Entry *func_0203996C(s32 idx);
extern void func_0203A770(u32 a, u32 b, int c, u32 d, u32 e, u32 f);
extern void func_02037234(u8 *p);
extern u32 func_02036540(u32 a);
extern u32 func_02036500(u32 a);
extern int  func_020364D4(struct Src *s, u8 *buf, u32 n, u32 max);
extern int  func_0203A804(u32 h);
extern int  func_0203A7EC(u32 h);
extern u32 func_0203A634(u32 a0);
extern u32 func_0203A81C(u32 a0, u32 a1, u32 a2);
extern void func_02082D44(void *dst, const void *src, int n);
extern void func_0203666C(u32 h);
extern int func_02036B98(char *p, int v);
extern u16 func_0203A28C(u16 mask, u32 idx, u32 set);
extern void *func_02082BCC(void *dst, int val, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Entry *sub_0203996C(s32 idx);
u32 func_020377B8(u8 arg0);
void func_0203781C(u32 arg);
void func_02037858(u32 arg);
void func_02037894(u8 a0, u16 a1, u32 a2, u32 a3);
u32 func_02037928(u32 a0, u16 a1);
int func_020379C8(u32 p);
void func_02037A44(int a);
void func_02037A6C(u32 a0, u32 a1, u16 a2, u32 a3);
void func_02037B08(void);
void func_02037BA4(void);
void func_02037BE8(u32 a);
int func_02037C10(void);
void func_02037D78(void);
int func_02037D98(int a);
void func_02037E60(void);
void func_02037F48(void);
void func_0203802C(void);
u32 func_020380E4(u32 a0, u8 *rec, u32 len);
void func_020381D8(u32 a0, u32 a1);
void func_02038298(void);
void func_02038340(void);
void func_02038380(void);
int func_02038524(void);
void func_02038570(void);
void func_020385C4(void);
int func_020387A0(u32 i, u8 *p, s32 n);
int func_02038924(u32 a0, u8 *p, s32 n);
int func_02038A48(int a);
int func_02038A90(u32 a);
s32 func_02038AE0(struct Hdr *h, struct Conn *c, s32 len, u8 a3);
int func_02038C18(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
void func_02038D30(int a0, int a1, int a2, int a3);
void func_02038D4C(int a0, int a1, int a2, int a3);
void func_02038D68(int a0, u32 a1, u32 a2, u8 *a3);
void func_02038DF0(struct Src *src, s32 a1, u8 *buf, struct St *st, u32 n);
void func_02039050(void);
void func_020390BC(void);
int func_02039160(u32 mode);
u32 func_020392B8(void);
int func_020392EC(void);
u16 sub_02039338(void);
int sub_020393A8(void);
int sub_020393D0(void);
u32 func_02039414(void);
void func_02039468(u32 a, u32 b);
int func_020394C0(void);
void sub_020394DC(u8 v);
void func_020394F0(u32 a);
void sub_02039548(void);
void sub_02039560(void);
void sub_02039578(void);
int sub_02039594(void);
int sub_020395E0(int slot);
int func_020395EC(struct Entry *a);
void func_02039658(struct Entry_02039658 *e, u32 idx);
void func_0203971C(unsigned char *a, u32 b);
struct Entry_02039764 *func_02039764(u32 idx);
void func_02039834(void);
void func_020398B4(void);
extern u8 g_020A7A20[];
extern struct Net *g_021469D0;
extern u8 lbl_020A7A20[];
extern u8 d_020A7A20[];
extern u8 d_020A7A24[];
extern u8 d_020A7A50[];
extern const u8 str_020A7A24[];
extern const u8 str_020A7A54[];
extern u8   g_020A7A24[];
extern u8   g_020A7A50[];
extern const u8 str_020A7A50[];
extern const u8 str_020A7A68[];
extern const u8 str_020A7A78[];
extern const char file_020A7A68[];
extern void *g_021469D4;
extern const char msg_020A7A7C[];
extern const char msg_020A7A88[];



















/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020377B8.c \
 *       --func func_020377B8 --addr 0x020377B8 --cc 1.1p1 --arm
 */
u32 func_020377B8(u8 arg0)
{
    u32 zero;
    char *a = func_0203D798();
    char *b = func_0203D788();
    u16 val;
    void (*f)(void *);

    ((struct Obj11351 *)a)->f66 = arg0;
    f = *(void (**)(void *))(*(char * *)&((struct Obj15917 *)b)->f340 + 0x68);
    f(func_020377AC);

    zero = 0;
    val = ((struct Obj11351 *)a)->f56;
    func_02037288(0x80, val, zero);

    func_02037680(zero);
    func_02037680(1);
    func_02037680(2);

    return 1;
}



















/*
 * Reset-and-notify hook: two context getters, the per-slot reset for `arg`,
 * and then the hook at +8 of the first context if it is installed, called with
 * the first context's word at +0x34C and the incoming argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203781C.c \
 *       --func func_0203781C --addr 0x0203781C --cc 1.1p1 --arm
 */
void func_0203781C(u32 arg)
{
    char *a = func_0203D798();
    char *b = func_0203D788();
    void (*hook)(u32, u32);

    func_02037680(arg);

    hook = *(void (**)(u32, u32))(a + 8);
    if (hook == 0)
        return;
    hook(((struct Obj15920 *)b)->f34C, arg);
}



















/*
 * Byte-for-byte twin of func_0203781C (same 60 bytes, same call order): two
 * context getters, the per-slot reset for `arg`, then the hook at +8 of the
 * first context when it is installed, called with the first context's word at
 * +0x34C and the argument.  Two copies of the same 60 bytes exist in the image
 * and this is the second, so the pair also demonstrates that the listing's
 * duplicate-glue pattern is real code and not one function reached twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037858.c \
 *       --func func_02037858 --addr 0x02037858 --cc 1.1p1 --arm
 */
void func_02037858(u32 arg)
{
    char *a = func_0203D798();
    char *b = func_0203D788();
    void (*hook)(u32, u32);

    func_02037680(arg);

    hook = *(void (**)(u32, u32))(a + 8);
    if (hook == 0)
        return;
    hook(((struct Obj15922 *)b)->f34C, arg);
}


















/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037894.c \
 *       --func func_02037894 --addr 0x02037894 --cc 1.1p1 --arm
 */
void func_02037894(u8 a0, u16 a1, u32 a2, u32 a3)
{
    char *a = func_0203D798();
    char *b = func_0203D788();
    u32 flag;
    u16 val;
    void (*f1)(void *);
    void (*f2)(void *);
    void (*f3)(u32, u32);

    ((struct Obj11352 *)a)->f66 = a0;

    f1 = *(void (**)(void *))(*(char * *)&((struct Obj05734 *)b)->f340 + 0x3C);
    f1(func_0203781C);

    f2 = *(void (**)(void *))(*(char * *)&((struct Obj05734 *)b)->f340 + 0x68);
    f2(func_020387A0);

    if (((struct Obj05734 *)b)->f64 != 0 && ((struct Obj05734 *)b)->f6C != 0) {
        flag = 1;
    } else {
        flag = 0;
    }

    a = func_0203D798();
    val = ((struct Obj11352 *)a)->f56;
    func_02037288(a1, val, flag);

    f3 = *(void (**)(u32, u32))(*(char * *)&((struct Obj05734 *)b)->f340 + 0x40);
    f3(a2, a3);
}


















/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037928.c \
 *       --func func_02037928 --addr 0x02037928 --cc 1.1p1 --arm
 */
u32 func_02037928(u32 a0, u16 a1)
{
    char *b = func_0203D788();
    void (*f1)(void *);
    u32 (*f2)(u32, u32);
    void (*f3)(void *);
    u32 res;
    u32 flag;
    char *a;
    u16 val;

    f1 = *(void (**)(void *))(*(char * *)&((struct Obj05735 *)b)->f340 + 0x3C);
    f1(func_02037858);

    f2 = *(u32 (**)(u32, u32))(*(char * *)&((struct Obj05735 *)b)->f340 + 0x44);
    res = f2(a0, 0);

    if (res == 1) {
        f3 = *(void (**)(void *))(*(char * *)&((struct Obj05735 *)b)->f340 + 0x68);
        f3(func_02038924);

        if (((struct Obj05735 *)b)->f64 != 0 && ((struct Obj05735 *)b)->f6C != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        a = func_0203D798();
        val = ((struct Obj15929 *)a)->f56;
        func_02037288(a1, val, flag);

        g_020A7A20[1] = 4;
    }

    return res;
}


















/*
 * Context teardown through three vtable slots at +0x3c, +0xbc and +0x68 of the
 * object the context's word at +0x340 names.  The first and third are handed a
 * function address as their argument (0x02037858 and 0x02038924), which is why
 * the pool holds two code pointers; the +0xbc slot's answer decides whether the
 * rest runs, and the byte at +1 of the object at 0x020A7A20 is set to 4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020379C8.c \
 *       --func func_020379C8 --addr 0x020379C8 --cc 1.1p1 --arm
 */
int func_020379C8(u32 p)
{
    int   r;
    char *c = func_0203D788();

    (*(void (**)(u32))(*(char **)(c + 0x340) + 0x3C))((u32)func_02037858);
    r = (*(int (**)(void))(*(char **)(c + 0x340) + 0xBC))();
    if (r == 1) {
        (*(void (**)(u32))(*(char **)(c + 0x340) + 0x68))((u32)func_02038924);
        func_02037288(p, *(u16 *)((char *)func_0203D798() + 0x56), 0);
        g_020A7A20[1] = 4;
    }
    return r;
}


















void func_02037A44(int a)
{
    int *r = func_0203D788();
    int *t = *(int * *)&((struct Obj15930 *)r)->f340;
    if (t == 0)
        return;
    ((void (*)(int))t[0x30])(a);
}



















/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037A6C.c \
 *       --func func_02037A6C --addr 0x02037A6C --cc 1.1p1 --arm
 */
void func_02037A6C(u32 a0, u32 a1, u16 a2, u32 a3)
{
    char *b = func_0203D788();
    char *a = func_0203D798();
    void (*f1)(void *);
    u32 flag;
    u16 val;
    void (*f2)(u32, u32, u32, u32, u32);

    f1 = *(void (**)(void *))(*(char * *)&((struct Obj06938 *)b)->f340 + 0x68);
    f1(func_02038924);

    if (a0 != 0) {
        if (((struct Obj06938 *)b)->f64 != 0 && ((struct Obj06938 *)b)->f6C != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        a = func_0203D798();
        val = ((struct Obj15931 *)a)->f56;
        func_02037288(a2, val, flag);

        g_020A7A20[1] = 4;
    }

    f2 = *(void (**)(u32, u32, u32, u32, u32))(*(char * *)&((struct Obj06938 *)b)->f340 + 0x48);
    f2(a0, a1, 0, 0, a3);
}



















/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037B08.c \
 *       --func func_02037B08 --addr 0x02037B08 --cc 1.1p1 --arm
 */
void func_02037B08(void)
{
    func_0203D788();
    func_0203D798();

    if (g_021469D0 == 0) {
        return;
    }

    func_020307B0(g_021469D0->f14);
    func_020307B0(g_021469D0->f18);
    func_020307B0(g_021469D0->f10);

    func_02036B88(g_021469D0->fF4);
    func_02036B88(g_021469D0->fCC);

    func_020307B0(g_021469D0->f00);
    func_020307B0(g_021469D0->f04);
    func_020307B0(g_021469D0->f08);
    func_020307B0(g_021469D0->f0C);

    func_020307B0(g_021469D0);

    g_021469D0 = 0;
}

















/*
 * 64 bytes gated on the byte at +0x1EC of the object the global pointer names:
 * when it is set, the first getter's non-zero answer runs func_02037B08 and
 * returns, the second getter's non-zero answer returns without it, and
 * everything else runs func_02037B08.  The two `bl func_02037B08` are separate
 * copies in the original, which is what the two arms give.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037BA4.c \
 *       --func func_02037BA4 --addr 0x02037BA4 --cc 1.1p1 --arm
 */
void func_02037BA4(void)
{
    if (g_021469D0->f1EC == 0)
        return;
    if (func_02039338() == 0) {
        if (func_020393A8() == 0)
            func_02037B08();
        return;
    }
    func_02037B08();
}

















/*
 * Guards the eight-slot table behind the global at 0x021469D0: an unarmed
 * global returns through `popeq`, an index past 7 through `popcs` (the compare
 * is unsigned, so a negative index is rejected as well), and only a live slot
 * reaches func_02037680.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037BE8.c \
 *       --func func_02037BE8 --addr 0x02037BE8 --cc 1.1p1 --arm
 */
void func_02037BE8(u32 a)
{
    if (g_021469D0 == 0)
        return;
    if (a >= 8)
        return;
    func_02037680(a);
}

















/*
 * The net tick dispatcher.  Two shapes are load-bearing: the f1EA/0x393D0
 * early exit is an out-of-line `goto bail` block placed AFTER the main body,
 * and the main path's `return 1` is reached by a `goto done` that lands on
 * the SAME `mov r0,#1; pop` the bail block falls into.  Writing either as a
 * plain `return 1` duplicates the epilogue and loses the `b #0x2037d6c`.
 */
int func_02037C10(void)
{
    struct Ctx_020377B8 *c = func_0203D788();
    struct Oth_020377B8 *o = func_0203D798();

    if (g_021469D0 == 0) {
        if (c != 0)
            ((void (*)(u32))c->f340[0xc / 4])(0);
        return 1;
    }

    {
        u32 (*h)(void) = (u32 (*)(void))c->f340[0x84 / 4];
        if (h != 0) {
            func_020370F4(h());
        }
    }

    if (g_021469D0->f1EA != 0)
        goto bail;
    if (func_020393D0() != 0)
        goto bail;

    if (o->f64 == 0 && (o->f65 == 0 || o->f65 == 5)) {
        func_02037F48();
    } else if ((u8)(o->f65 + 0xfd) <= 1) {
        func_0203802C();
    } else if ((u8)(o->f65 + 0xff) <= 1) {
        func_02038298();
    } else {
        func_02038340();
        func_02039050();
        if (func_02039338() == 0) {
            if (func_02039160(0) != 0 && o->f64 != 0)
                func_020385C4();
        }
        if (func_02039338() != 0)
            goto skip;
    }
    func_020390BC();
skip:
    if (o->f65 != 1 && o->f65 != 2) {
        ((void (*)(u16))c->f340[0xc / 4])(
            g_021469D0->f1E4);
    }
    func_0203ACAC();
    func_02037BA4();
    goto done;

bail:
    ((void (*)(u32))c->f340[0xc / 4])(0);
done:
    return 1;
}
















/*
 * Teardown hook for the same global src/matched/func_02037BE8.c guards: the
 * armed pointer goes to func_02037478, an unarmed one is a `popeq`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037D78.c \
 *       --func func_02037D78 --addr 0x02037D78 --cc 1.1p1 --arm
 */
void func_02037D78(void)
{
    struct Net *v;

    v = g_021469D0;
    if (v == 0)
        return;
    func_02037478();
}
















int func_02037D98(int a)
{
    int r = 0;
    if (lbl_020A7A20[1] != 4)
        return r;
    if (a != 0) {
        struct Net *p = g_021469D0;
        if (p->f1B0 > 0)
            return r;
        if (func_02038AE0((struct Hdr *)p->f00, (struct Conn *)p->fCC, func_0203D6BC(), p->f1D5) != 0) {
            struct Net *q = g_021469D0;
            q->f1D5++;
        }
        lbl_020A7A20[1] = 0;
        r = 1;
    } else {
        struct Net *p = g_021469D0;
        if (func_02038AE0((struct Hdr *)p->f00, (struct Conn *)p->fCC, func_0203D6BC(), p->f1D5) != 0) {
            struct Net *q = g_021469D0;
            q->f1D5++;
            lbl_020A7A20[1] = 0;
            r = 1;
        }
    }
    return r;
}














void func_02037E60(void)
{
    struct Ctx_02037E60 *c = func_0203D788();
    u32 v = func_0203D6BC();
    u32 r;

    r = c->f340->f70();
    if (r == 0)
        return;
    r = func_02039338();
    r = func_02039160(r);
    if (r == 0)
        return;
    if (g_020A7A20[1] != 0)
        return;
    if (func_02039338() != 0) {
        r = c->f340->f64((u32)g_021469D0->f00, v, 0, func_02038A48);
        if (r == 0)
            return;
        g_020A7A20[1] = 2;
        g_021469D0->f1B0 = g_021469D0->f1B0 + 1;
    } else {
        g_020A7A20[1] = 2;
        func_02038A48(1);
        func_020387A0(0, (u8 *)g_021469D0->f00, (u16)v);
        g_021469D0->f1B0 = g_021469D0->f1B0 + 1;
    }
}















/*
 * Declaration order is what closes this one: p must be declared LAST of the
 * four locals so it takes r6 and the loop index takes r4 (see
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * The failure arm of the +0x5C poll is an out-of-line `goto`, not an
 * if-converted tail; the (u16) truncation of v happens after the n>0 test
 * and the index is zeroed before it.
 */
void func_02037F48(void)
{
    s32 i;
    s32 n;
    u32 v;
    u8 *p;

    p = func_0203D788();

    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0x58))() == 0)
        return;

    if (g_021469D0->f1EB != 0)
        func_02037D98(1);

    if (((u32 (*)(u32)) * (u32 *)(*(u32 *)(p + 0x340) + 0x5C))((u32)g_021469D0->f00) != 1)
        goto fail;

    *(u8 *)(d_020A7A20 + 1) = 4;
    g_021469D0->f1EB = 1;

    v = func_0203D6BC();
    n = func_0203D680();
    i = 0;
    if (n > 0) {
        v = (unsigned short)v;
        do {
        func_020387A0((unsigned short)i,
                      (u8 *)(((u32 (*)(u32))
                           * (u32 *)(*(u32 *)(p + 0x340) + 0x60))(i)), v);
            i++;
        } while (i < n);
    }
    return;

fail:
    g_021469D0->f1EB = 0;
}















/*
 * Fourth entry of this packet's chain, and the one the lane table expected to
 * need two callees filed: it calls func_020381D8, whose own entry is in this
 * shard, so that site resolves through `matched`; 0x020366A8 and 0x0203D3A8,
 * the other two the table named, turn out to have outside witnesses
 * (0x02038B48 and 0x02039AAC) once the compared range is this one function
 * rather than the whole packet.
 *
 * The two literals in the tail are different objects: the first argument to
 * func_020381D8 is one dereference of the 0x021469D0 pointer word, and the
 * final store is into the byte at 0x020A7A20 + 1.  Reading them as the same
 * symbol makes the compiler pool the address once and spend a second
 * callee-saved register on the transfer value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203802C.c \
 *       --func func_0203802C --addr 0x0203802C --cc 1.1p1 --arm
 */
void func_0203802C(void)
{
    u8 *p;
    u32 v;

    p = func_0203D788();

    if (func_020366A8((struct Conn *)g_021469D0->fCC) != 0)
        func_0203D3A8(func_020399A8(), 0x10, 0, 0);

    v = *(u32 *)(((struct Obj15934 *)p)->f340 + 0x9C);
    if (v != 0)
        ((void (*)(void))v)();
    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0x6C))() != 1)
        return;

    v = func_0203D6BC();
    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0xA0))() != 1)
        return;
    if (func_02037D98(0) == 0)
        return;

    func_020381D8((u32)g_021469D0->f00, v);
    *(u8 *)(d_020A7A20 + 1) = 4;
}















/*
 * Validates one incoming record against the per-slot table reached through
 * 0x021469D0: the byte at +4 of the record is a presence/state tag (0xFF is
 * "locked out", bit 1 is the "no free slot" rejection), then the two-byte
 * header of the body is checked against the result of 0x0203F1FC, then the
 * slot's own counter byte at 0x1D7+slot is compared with rec[5]-1 before
 * being overwritten with rec[5].  Slot `a0` lives at 0x54 + (a0 << 4), so the
 * per-slot block is 16 bytes and the counter table is a byte array.
 *
 * The +8 bit of rec[4] biases the third argument by 0xFF; both the globals are
 * re-read from the pointer word after every call, which is why the C indexes
 * g_021469D0 directly instead of caching it in a local.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020380E4.c \
 *       --func func_020380E4 --addr 0x020380E4 --cc 1.1p1 --arm
 */
u32 func_020380E4(u32 a0, u8 *rec, u32 len)
{
    int v;
    u32 n;

    func_0203D798();
    func_0203D6BC();

    if (rec[4] == 0xFF)
        return 0;
    if (g_021469D0->f4C[a0].state == 0 && (rec[4] & 2))
        return 0;

    v = func_0203F1FC(rec + 2, len - 2);
    if (rec[0] != (u8)v || ((v & 0xFF00) >> 8) != rec[1])
        return 0;
    if (g_021469D0->f1D7[a0] != 0 &&
        (u8)(rec[5] - 1) != g_021469D0->f1D7[a0])
        return 0;

    g_021469D0->f1D7[a0] = rec[5];
    n = rec[2];
    if (rec[4] & 8)
        n += 0xFF;
    func_02036428((u8 *)&g_021469D0->f4C[a0], rec + 7, n);
    g_021469D0->f4C[a0].state = 1;
    return 1;
}















/*
 * Second half of this packet's chain: it calls func_020380E4, whose own entry
 * is in this shard, so the call site is attested by `matched` rather than by
 * the single in-range witness the lane table saw.
 *
 * The flow: two global locks are set up, then the interface object reached
 * through *(p + 0x340) is asked twice (its +0xA4 and +0xAC entries); only if
 * both answer non-zero does the transfer run - otherwise the two literals at
 * 0x020A7A24/0x020A7A50 go to 0x02034714 with 0x400.  The transfer calls the
 * object's +0x64 entry with the two arguments and zeroed r2/r3, reads the
 * +0x80 entry for the record number, and hands (u16)record-number, first
 * argument and (u16)second argument to func_020380E4 before the fixed 4 /
 * 0x40C delay through 0x02037224.
 *
 * The guards' polarity is the `bne` / `beq` pair at +0x2C and +0x38: the two
 * object calls are one conjunction whose false arm is the failure block
 * written first, which is the if/else spelling and not a guard chain.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020381D8.c \
 *       --func func_020381D8 --addr 0x020381D8 --cc 1.1p1 --arm
 */
void func_020381D8(u32 a0, u32 a1)
{
    u8 *p;
    u32 v;

    func_0203D798();
    p = func_0203D788();

    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0xA4))() == 0 ||
        ((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0xAC))() == 0) {
        func_02034714((const char *)d_020A7A24, 0x400, (const char *)d_020A7A50);
        return;
    }

    if (*(u8 *)(d_020A7A20 + 1) != 0)
        return;
    ((void (*)(u32, u32, u32, u32))
         * (u32 *)(*(u32 *)(p + 0x340) + 0x64))(a0, a1, 0, 0);
    v = ((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0x80))();
    func_020380E4((u16)v, (u8 *)a0, (u16)a1);
    func_02037224(4, 0x40C);
}















/*
 * Third entry of this packet's chain, and the one that shows why the object
 * word has to be re-read rather than cached: 0x021469D0 is a pointer word and
 * every use of the object it points at goes back through the pool address, so
 * the C indexes g_021469D0 directly each time.
 *
 * The state machine is three bytes of the object (0x1E7 = "armed", 0x1ED =
 * "in flight", 0x1D5 = a mode byte feeding 0x02038AE0): returning early
 * unless armed, arming the in-flight flag once 0x02038AE0 agrees, and only
 * then running the object's +0x64 entry, which clears the flag when it
 * returns non-zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02038298.c \
 *       --func func_02038298 --addr 0x02038298 --cc 1.1p1 --arm
 */
void func_02038298(void)
{
    u8 *p;
    u32 v;

    func_0203D798();
    p = func_0203D788();
    v = func_0203D6BC();

    if (g_021469D0->f1E7 == 0)
        return;
    if (g_021469D0->f1ED == 0) {
        if (func_02038AE0((struct Hdr *)g_021469D0->f00, (struct Conn *)g_021469D0->fCC,
                          func_0203D6BC(),
                          g_021469D0->f1D5) != 0)
            g_021469D0->f1ED = 1;
    }

    if (g_021469D0->f1ED != 1)
        return;
    if (((u32 (*)(u32, u32, u32, u32))
             * (u32 *)(*(u32 *)(p + 0x340) + 0x64))((u32)g_021469D0->f00, v,
                                                    0, 0) == 0)
        return;
    g_021469D0->f1ED = 0;
}














/*
 * Promoted from src/pending/ on lane 1.  All 64 concrete bytes are right; the
 * one open site was the PC24 at +0x0038, the `bl` to func_02037E60, which had
 * exactly one branch reference in the whole image (this one) and so no
 * `label` witness.  With src/matched/func_02037E60.c filed EXACT the site
 * resolves through the `matched` class and the file prints EXACT with no
 * change to its C.
 *
 * The reading: refresh the UI object, ask its +0x340 owner's +0x70 virtual
 * whether the session is still up, then let the two teardown probes decide
 * whether func_02037D98(1) and func_02037E60 are reached.  The first
 * func_0203D798() result is discarded - the image overwrites r0 with
 * func_0203D788()'s answer immediately - which is why the call stands on its
 * own statement rather than as an initialiser.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02038340.c \
 *       --func func_02038340 --addr 0x02038340 --cc 1.1p1 --arm
 */
void func_02038340(void)
{
    void *p;

    func_0203D798();
    p = func_0203D788();
    if (((int (*)(void))*(unsigned int *)(*(unsigned int *)((char *)p + 0x340) + 0x70))() == 0)
        return;
    if (func_02039160(func_02039338()) == 0)
        return;
    func_02037D98(1);
    func_02037E60();
}












void func_02038380(void)
{
    struct Ctx *c = func_0203D788();

    func_0203D680();
    if (g_020A7A20[0] == 1) {
        if ((int)func_020392B8() > 1) {
            func_02037224(2, 0x46a);
            if (((int (*)(void))c->f340[0x70 / 4])() != 0) {
                u32 t = func_02037258();
                if (((int (*)(u32, u32, u32, u32))c->f340[0x64 / 4])(
                        (u32)g_021469D0->f08, t, 0, (u32)func_02038A90) != 0)
                    goto tail;
                func_02037224(1, 0x46a + 4);
                goto tail;
            }
            if (((struct Oth_02038380 *)func_0203D798())->f65 != 3 && ((struct Oth_02038380 *)func_0203D798())->f65 != 4)
                goto tail;
            if (((int (*)(void))c->f340[0xa0 / 4])() == 0) {
                func_02037224(1, 0x475);
                goto tail;
            }
            if (g_021469D0->f08[2] == 0)
                return;
            {
                u32 t = func_0203D6BC();
                ((void (*)(u32, u32, u32, u32))c->f340[0x64 / 4])(
                    (u32)g_021469D0->f08, t, 0x64, 0);
            }
        }
    }
tail:
    if (g_020A7A20[0] == 2) {
        func_02038570();
        func_02038924(0, g_021469D0->f08, (u16)func_02037258());
        func_02037224(3, 0x490 - 3);
    }
    if (((int (*)(void))c->f340[0x70 / 4])() == 0)
        goto last;
    if (((struct Oth_02038380 *)func_0203D798())->f65 == 3)
        goto last;
    if (((struct Oth_02038380 *)func_0203D798())->f65 != 4)
        return;
last:
    func_02037224(4, 0x492);
}











int func_02038524(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (func_02039160((u16)i) != 0 && g_021469D0->f1B4[i] > 0) {
            return 0;
        }
    }
    return 1;
}












void func_02038570(void)
{
    int i;
    int n = func_0203D680();

    for (i = 0; i < n; i++) {
        if (func_02039160((u16)i) != 0) {
            g_021469D0->f1B4[i] += 1;
        }
    }
}












/*
 * net_system.c.  The outer per-frame entry: it dispatches on the link-state
 * byte at +0x65 of the 0x0203D798 object, in two two-wide bands written as
 * unsigned-wrapped range tests ((u8)(s - 1) <= 1 and (u8)(s - 3) <= 1), and
 * falls through to func_02038380 in both of the middle bands.
 * func_02037224 takes the caller's __LINE__ as its second argument; the four
 * line numbers are 0x4d5, 0x4da, 0x4e1 and 0x4f4.  The assert at +0x50 is
 * the usual func_02034714(file, line, expr) triple.
 */
void func_020385C4(void)
{
    struct Ctx *c = func_0203D788();
    struct Oth *o = func_0203D798();
    u8 s = o->f65;

    if ((u8)(s + 0xff) <= 1) {
        if (func_02039160(0) == 0)
            return;
        if (o->f64 != 0)
            func_02034714((const char *)str_020A7A24, 0x4d5, (const char *)str_020A7A54);
        if (g_020A7A20[0] == 4 && g_021469D0->f1AC != 0
            && func_02038524() != 0)
            func_02037224(1, 0x4da);
        if (g_020A7A20[0] != 1)
            return;
        {
            u32 t = func_02037258();
            if (((int (*)(u32, u32, u32, u32))c->f340[0x64 / 4])(
                    (u32)g_021469D0->f08, t, 0, 0) == 0)
                return;
        }
        func_02037224(4, 0x4e1);
        func_02038570();
        return;
    }
    if ((u8)(s + 0xfd) <= 1) {
        if (g_020A7A20[0] == 4) {
            struct Net *g = g_021469D0;
            u32 t = func_02037258();

            func_02038AE0((struct Hdr *)g->f08, (struct Conn *)g->fF4, t, g->f1D4);
            g = g_021469D0;
            g->f1D4 = (u8)(g->f1D4 + 1);
            func_02037224(1, 0x4f4);
        }
        func_02038380();
        return;
    }
    if (((int (*)(void))c->f340[0x70 / 4])() == 0)
        return;
    if (func_02038524() == 0)
        return;
    if (g_020A7A20[0] == 4) {
        struct Net *g = g_021469D0;
        u32 t = func_02037258();

        func_02038AE0((struct Hdr *)g->f08, (struct Conn *)g->fF4, t, g->f1D4);
        g = g_021469D0;
        g->f1D4 = (u8)(g->f1D4 + 1);
        func_02037224(1, 0x501);
    }
    func_02038380();
}












/*
 * The indexed twin of src/matched/func_02038924.c (the own-slot variant):
 * same receive/validate/copy shape, but every global offset is scaled by
 * the slot index -- the 0x1B4 credit counter by i*4, the 0x54 accepted
 * flag and the 0x4C payload by i*16, the 0x1D7 sequence byte by i.  The
 * extra middle block this one has and 0x02038924 does not is the sequence
 * check at 0x1D7+i with its own 0x3F3 error line.
 */
int func_020387A0(u32 i, u8 *p, s32 n)
{
    struct Net *g;
    u8 *q;
    u32 v;
    s32 len;
    int r;

    func_0203D6BC();
    if (p == 0)
        return 0;
    g = g_021469D0;
    g->f1B4[i] = g->f1B4[i] - 1;
    if (i == 0)
        g_021469D0->f1E4 = p[3];
    v = p[4];
    if (v == 0xff)
        return 0;
    if (g_021469D0->f4C[i].state == 0) {
        if (v & 2)
            return 0;
    }
    r = func_0203F1FC(p + 2, n - 2);
    if (p[0] != (u8)r || ((r & 0xff00) >> 8) != p[1]) {
        func_02039548();
        q = (u8 *)func_0203CA98();
        if (((struct Obj03449 *)q)->fC == 0)
            func_0203C9AC(((struct Obj03449 *)q)->f0, ((struct Obj03449 *)q)->f4, ((struct Obj03449 *)q)->f8, 0x3f2);
        return 0;
    }
    {
        u8 *s = g_021469D0->f1D7;
        if (s[i] != 0 && (u8)(p[5] - 1) != s[i]) {
            func_02039548();
            q = (u8 *)func_0203CA98();
            if (((struct Obj03449 *)q)->fC == 0)
                func_0203C9AC(((struct Obj03449 *)q)->f0, ((struct Obj03449 *)q)->f4, ((struct Obj03449 *)q)->f8, 0x3f3);
            return 0;
        }
        s[i] = p[5];
    }
    len = p[2];
    if (p[4] & 8)
        len += 0xff;
    func_02036428((u8 *)&g_021469D0->f4C[i], p + 7, len);
    g_021469D0->f4C[i].state = 1;
    return 1;
}











int func_02038924(u32 a0, u8 *p, s32 n)
{
    struct Net *g;
    u8 *q;
    u32 v;
    s32 len;
    int r;

    (int)func_0203D798();
    func_0203D6BC();
    g = g_021469D0;
    g->f1B0 = g->f1B0 - 1;
    if (p == 0)
        return 0;
    if (a0 == 0)
        g_021469D0->f1E4 = p[3];
    v = p[4];
    if (v == 0xff)
        return 0;
    if (g_021469D0->f2C.state == 0) {
        if (v & 2)
            return 0;
    }
    r = func_0203F1FC((const u8 *)(p + 2), n - 2);
    if (p[0] != (u8)r || ((r & 0xff00) >> 8) != p[1]) {
        func_02039548();
        q = (u8 *)func_0203CA98();
        if (((struct Obj06939 *)q)->fC == 0)
            func_0203C9AC(((struct Obj06939 *)q)->f0, ((struct Obj06939 *)q)->f4, ((struct Obj06939 *)q)->f8, 0x3f2);
        return 0;
    }
    g_021469D0->f1D6 = p[5];
    len = p[2];
    if (p[4] & 8)
        len += 0xff;
    func_02036428((u8 *)&g_021469D0->f2C, p + 7, len);
    g_021469D0->f2C.state = 1;
    return 1;
}











/*
 * Idempotent bring-up: when the argument is non-zero and the mode byte at
 * 0x020A7A21 still reads 2, it is flipped to 4 and the call is skipped; in
 * every other case the 0x5C0-byte block at 0x020A7A24 is handed to
 * func_02034714 with 0x020A7A50 as the third argument.  Either way the
 * function answers 1 through the single shared epilogue (`mov r0, #1;
 * pop {r3, pc}`), which is why the taken arm ends in `beq` to that epilogue
 * and not in a predicated return.
 *
 * The three globals are *arrays*, not pointers: the image loads the pool word
 * straight into r0 and then does `ldrb r1, [r0, #1]`, so `extern u8
 * g_020A7A20[]` with a `[1]` subscript is the spelling that reproduces it - as
 * `extern u8 *g_020A7A20` the compiler adds a second load and the file grows
 * to 88 bytes.  The arm's two instructions are predicated (`moveq`/`strbeq`)
 * rather than branched.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02038A48.c \
 *       --func func_02038A48 --addr 0x02038A48 --cc 1.1p1 --arm
 */
int func_02038A48(int a)
{
    if (a != 0 && g_020A7A20[1] == 2) {
        g_020A7A20[1] = 4;
    } else {
        func_02034714((const char *)g_020A7A24, 0x5C0, (const char *)g_020A7A50);
    }
    return 1;
}











int func_02038A90(u32 a)
{
    func_0203D6BC();
    func_0203D680();
    func_0203D798();
    if (a != 0) {
        func_02037224(4, 0x5d4);
    } else {
        func_02034714((const char *)str_020A7A24, 0x5d8, (const char *)str_020A7A50);
    }
    return 1;
}











s32 func_02038AE0(struct Hdr *h, struct Conn *c, s32 len, u8 a3)
{
    struct Glob *g;
    struct Sys *sys;
    struct Buf buf;
    s32 n;
    u16 v;

    g = func_0203D798();
    sys = func_0203D788();

    MI_CpuFill8(h, 0, (u32)len);

    if (c->f24 == 0)
        h->f04 = 1;
    else
        h->f04 = 2;
    c->f24 = 0;

    h->f03 = sys->f340->f7c();

    if (func_020366A8(c) == 0)
    {
        if ((u8)(g->f65 + 0xfd) > 1)
            goto body;
        if (sys->f340->fb0() != 1)
            goto body;
    }
    h->f04 = 0xff;
    return 0;

body:
    ;

    buf.len = (u16)(len - 7);
    buf.ptr = &h->body[0];
    if (func_02036A50((u32)c, (u16 *)(&buf)) == 0)
        c->f24 = 1;

    if (buf.len != 0xffff)
        n = (len - buf.len) - 7;
    else
        n = len - 7;

    if (n > 0xff)
    {
        n = n + 1;
        h->f04 = h->f04 | 8;
    }

    h->f02 = (u8)n;
    h->f05 = a3;

    v = func_0203F1FC(&h->f02, len - 2);
    h->f00 = (u8)v;
    h->f01 = (u8)((v & 0xff00) >> 8);

    return 1;
}










/*
 * Seven-argument entry to the comms send path.  The seventh argument is a
 * flag whose INVERSE becomes the `broadcast` byte handed to func_020368C0:
 * `flag == 0` gives 1, anything else gives 0, materialised as
 * `mov r5,#1` / `cmp r4,#0` / `movne r5,#0` before the first call.
 *
 * The module handle behind the global at 0x021469D0 is fetched once and every
 * later read comes off the same pooled base; a null handle, a busy queue
 * (func_02039414 non-zero or func_0203C990 zero) and a failed func_02039594
 * all return 0 early.  func_0203D798's result is only used for its +0x64
 * byte, which selects the +0xf4 table over the +0xcc one when the fifth
 * argument is the 0xff wildcard.
 *
 * The broadcast flag is additionally cleared when the third argument is not
 * less than the handle's +0x1e0 word: `cmp r7,r0` / `cmpge r5,#1` /
 * `moveq r5,#0` is the conjunction `if (a3 >= lim && flag != 0) flag = 0;`
 * written as one expression
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * On a failed send the error path reports through func_0203CA98's three-word
 * record with line 0x3f4 and returns 0; a successful send returns 1.
 *
 * Addresses are Black-image addresses.
 *
 * BYTE-CORRECT, PARKED: 280 bytes, 0 concrete mismatches.  Capped at MATCH by
 * the sole unresolved site, the PC24 at +0x00D0 naming func_020368C0
 * (0x020368C0).  That address has no branch anywhere in the image outside this
 * function's own `bl` and no manifest entry, so neither `label` nor `matched`
 * can attest it; the call is the last thing before the function's two tail
 * exits, so no cut frees it either.  Filing 0x020368C0 promotes this file
 * unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02038C18.c \
 *       --func func_02038C18 --addr 0x02038C18 --cc 1.1p1 --arm
 */
int func_02038C18(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7)
{
    struct Rec *rec;
    struct Net *h;
    struct Err *err;
    void *tbl;
    u32 flag;

    flag = 1;
    if (a7 != 0)
        flag = 0;

    rec = func_0203D798();
    if (g_021469D0 == 0)
        return 0;
    if (func_02039414() != 0 || func_0203C990() != 0)
        return 0;
    if (func_02039594() == 0)
        return 0;

    h = g_021469D0;
    if ((int)a3 >= (int)h->f1E0 && flag == 1)
        flag = 0;

    if (rec->f64 != 0 && a5 == 0xff)
        tbl = h->fF4;
    else
        tbl = h->fCC;

    if (func_020368C0(tbl, a1, a2, a3, a4, flag, a6) != 0)
        return 1;

    func_02039548();
    err = (struct Err *)func_0203CA98();
    if (err->f0c == 0)
        func_0203C9AC(err->f00, err->f04, err->f08, 0x3f4);
    return 0;
}









void func_02038D30(int a0, int a1, int a2, int a3)
{
    func_020365E8((char *)&g_021469D0->f1C);
}









void func_02038D4C(int a0, int a1, int a2, int a3)
{
    func_020365E8((char *)&g_021469D0->f3C);
}










/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02038D68.c \
 *       --func func_02038D68 --addr 0x02038D68 --cc 1.1p1 --arm
 */
void func_02038D68(int a0, u32 a1, u32 a2, u8 *a3)
{
    u32 v;

    func_0203D798();
    v = (u32)func_0203996C(func_02039338());
    func_0203A770(a3[0x0E], a3[0x0F], a0, a1, a2, v);

    if (func_02039338() == 0) {
        v = (u32)func_0203996C(0xFF);
        if (a0 < 0x11)
            func_0203A770(a3[0x0E], a3[0x0F], a0, a1, a2, v);
    }

    func_02037234(a3);
}










/*
 * net_system.c packet reassembly: drain a slot's receive ring (src, the
 * 0x10-byte slot header func_0203640C builds; +0x0C is its read cursor)
 * into the reassembly record st, one chunk per turn, asserting at line
 * 0x6E3 on a zero header.  Written fresh from the image: the old note
 * (docs/notes/pkt_02038DF0.c.txt) kept no recoverable source.
 *
 * What closed it:
 *   - func_020364D4 is written in BOTH arms of the func_0203A804 test,
 *       if (!func_0203A804(h)) len = f(src, buf, left, left);
 *       else                   len = f(src, buf, left, n - 7);
 *     The compiler hoists the shared argument setup above the branch and
 *     sinks the call below it, which is the image's `mov r3, r2 / b /
 *     ldr r3, [sp, #4]` diamond.  A ternary argument (any spelling) is
 *     if-converted to moveq/ldrne and is 8 bytes short.
 *   - n is u32 (with it s32 the stack parameter is loaded after the guard
 *     instead of in the prologue); `int lim = n - 7` assigned inside the
 *     loop is an equivalent EXACT spelling.
 *   - h is u32 and declared after len/sv/p (permuter decl-order);
 *     func_02036540's result is narrowed through a u16 local at the 0xFFFF
 *     re-seed (the lsl/lsr pair), so it is declared returning u32 here.
 */
void func_02038DF0(struct Src *src, s32 a1, u8 *buf, struct St *st, u32 n)
{
    int len;
    s16 sv;
    u8 *p;
    u32 h;
    int cnt;

    func_0203D798();
    while (func_020365E8((char *)src) != 0) {
        h = st->h;
        if (h == 0) {
            h = func_02036540((u32)src);
            if (h == 0) {
                func_02034714((const char *)str_020A7A24, 0x6E3, (const char *)str_020A7A50);
                continue;
            }
        }
        sv = src->pos;
        st->h = h;
        if (st->total == 0xFFFF) {
            if (func_020365E8((char *)src) < 3) {
                src->pos = sv;
                return;
            }
            {
                u16 v = func_02036540((u32)src);
                st->left = v;
                st->total = v;
            }
            st->f0E = a1;
            st->f0F = func_02036500((u32)src);
        }
        sv = src->pos;
        if (func_0203A804(h) && func_0203A634(st->f0F)) {
            if (st->dst == 0)
                st->dst = (u8 *)func_0203A81C(h, st->f0E, st->total);
            p = st->dst + st->done;
        } else {
            p = buf;
            st->dst = buf;
        }
        if (!func_0203A634(st->f0F))
            p = 0;
        if (!func_0203A804(h))
            len = func_020364D4(src, buf, st->left, st->left);
        else
            len = func_020364D4(src, buf, st->left, n - 7);
        st->left = st->left - (u16)len;
        cnt = len;
        if (st->total > st->done) {
            cnt = st->total - st->done;
            if (cnt > len)
                cnt = len;
            if (p != 0)
                func_02082D44(buf, p, cnt);
        }
        st->done += cnt;
        if (st->left == 0) {
            func_02038D68(h, st->total, (u32)st->dst, (u8 *)st);
            continue;
        }
        if (!func_0203A7EC(h))
            return;
        if (func_0203A804(h))
            return;
        if (!func_0203A634(st->f0F))
            return;
        st->left += (u16)len;
        src->pos = sv;
        return;
    }
}








void func_02039050(void)
{
    int i;
    struct Net *p;

    if (g_021469D0 == 0)
        return;

    func_0203666C((u32)&g_021469D0->f2C);

    for (i = 0; i < 4; i++) {
        if ((int)func_020365E8((char *)&g_021469D0->f2C) <= 0)
            return;

        p = g_021469D0;
        func_02038DF0((struct Src *)&p->f2C, 0xFF, p->f18,
                      (struct St *)p->f19C, func_02037258());
    }
}









/*
 * n slots of 0x10 bytes at g+0x4c, each prepared by func_0203666C and then
 * offered to func_02038DF0 up to four times, with the record at g+0x11c and
 * the frame returned by func_0203D6BC handed to each call.
 *
 * Three spellings are load-bearing.  The global is re-read through
 * g_021469D0 itself in every statement (mwcc keeps its address in `sb` and
 * reloads the value, because the calls may store through it).  There is no
 * explicit `if (n <= 0) return;`: with `n = func_0203D680();` followed
 * straight by `for (i = 0; i < n; i++)` the loop's pre-test folds to
 * `cmp r7, #0` / `pople` because i is known zero, and the loop-exit
 * epilogue tail-merges with the function's own.  And the inner body is
 * `if (test > 0) call(...)` rather than `if (test <= 0) break;`, because
 * the original's branch lands on the inner increment (the continue path).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020390BC.c \
 *       --func func_020390BC --addr 0x020390BC --cc 1.1p1 --arm
 */
void func_020390BC(void)
{
    s32_020390BC i, j, n;
    u8 *s;

    s = (u8 *)func_0203D6BC();
    if (g_021469D0 == 0)
        return;

    n = func_0203D680();

    for (i = 0; i < n; i++) {
        func_0203666C((u32)&g_021469D0->f4C[i]);
        for (j = 0; j < 4; j++) {
            if (func_020365E8((char *)&g_021469D0->f4C[i]) > 0)
                func_02038DF0((struct Src *)&g_021469D0->f4C[i], i,
                              g_021469D0->f18,
                              (struct St *)g_021469D0->f11C[i], (u32)s);
        }
    }
}









int func_02039160(u32 mode)
{
    u8 *p5;
    u8 *p4;
    struct Net *g;
    u32 v;
    u16 m;

    p5 = (u8 *)func_0203D788();
    p4 = (u8 *)func_0203D798();
    g = g_021469D0;
    if (g == 0)
        return 0;
    v = (u8)(p4[0x65] + 0xff);
    if (v <= 1) {
        if (g->f1E7 != 0) {
            if (((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x80)))() != -1) {
                if (mode == 0)
                    return 1;
                if (mode == 1)
                    return 1;
            }
        }
        return 0;
    }
    v = (u8)(p4[0x65] + 0xfd);
    if (v <= 1) {
        if (mode < 2 || mode == 0xff) {
            if (((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x70)))() != 0)
                return 1;
        }
        return 0;
    }
    if (func_020392EC() == 0)
        return 0;
    if (((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x70)))() == 0)
        return 0;
    if (mode == (u32)func_02039338())
        return 1;
    if (func_02039338() == 0 || p4[0x64] == 0) {
        m = (u16)((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x7c)))();
        if (((1 << mode) & m) != 0)
            return 1;
    } else {
        if (((1 << mode) & g_021469D0->f1E4) != 0)
            return 1;
    }
    return 0;
}









/*
 * Counts the eight slots whose test function answers non-zero.  The slot
 * number goes in as a `u16` - the `lsl #16` / `lsr #16` pair in the loop is
 * that narrowing - so the callee is declared with a `u16` parameter and the
 * cast costs nothing at the call site.  The counter is in r4 and the index in
 * r5, which is the declaration order below.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020392B8.c \
 *       --func func_020392B8 --addr 0x020392B8 --cc 1.1p1 --arm
 */
u32 func_020392B8(void)
{
    u32 count;
    s32_020392B8 i;

    count = 0;
    for (i = 0; i < 8; i++) {
        if (func_02039160((u16)i) != 0)
            count++;
    }
    return count;
}









/*
 * Returns 1 while the state byte at +0x65 is one to four, but only while the
 * global at 0x021469D0 is live; otherwise it dispatches through the vtable at
 * +0x340 of the net state and returns that hook's value (+0x6C slot).
 *
 * The `add r0, r0, #0xff` / `and r0, r0, #0xff` pair is `(u8)(v - 1)`: mwcc
 * writes the -1 as +0xFF because the truncation to u8 makes the two
 * equivalent and 0xFF keeps the `and` mask a plain immediate.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020392EC.c \
 *       --func func_020392EC --addr 0x020392EC --cc 1.1p1 --arm
 */
int func_020392EC(void)
{
    u8 *s = (void *)func_0203D788();
    u8 *p = (void *)func_0203D798();

    if (g_021469D0 != 0 && (u8)(p[0x65] + 0xFF) <= 3)
        return 1;

    return (*(int (**)(void))(*(u32 *)(s + 0x340) + 0x6C))();
}






u16 sub_02039338(void)
{
    struct Owner *owner;
    u8 sel;
    s32 v;

    if (g_021469D0 == 0) {
        goto none;
    }

    owner = func_0203D788();
    sel = ((struct Mode *)func_0203D798())->unk65 + 0xff;

    if (sel <= 1) {
        v = owner->unk340->unk80();
        if (v == -1) {
            goto none;
        }
        return (u16)v;
    }

    return (u16)owner->unk340->unk80();

none:
    return 0;
}





int sub_020393A8(void)
{
    u16 mask;

    mask = ((struct LinkRoot_020377B8 *)func_0203D788())->driver->get_mask();
    return mask & 0xFFFE;
}





/*
 * Is the link busy?  The +0x1e9 flag on the link state forces a yes, and
 * otherwise the driver's own predicate at +0x88 decides.
 *
 * The two halves of the flag test share one `ne` chain and a single `popne`,
 * so they are one `&&` rather than nested `if`s.  func_0203D788 is called
 * before the flag is even read because its result is needed on the fall
 * through path, and the compiler will not sink a call past a branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020393D0.c \n *       --func sub_020393D0 --addr 0x020393D0 --cc 1.1p1 --arm
 */
int sub_020393D0(void)
{
    struct LinkRoot_020393D0 *root;

    root = func_0203D788();

    if (g_021469D0 != 0 && g_021469D0->f1E9 != 0) {
        return 1;
    }
    return root->driver->busy() != 0;
}






/*
 * Asks the transport's +0x88 virtual whether the link is up, falling back to
 * the +0x1E9 flag of the object at 0x021469D0 when the virtual is missing or
 * answers zero.  Both re-tests are conditional-execution chains (`cmpne`), so
 * the source is the `!= 0 && ...` spelling in each place.  The result local
 * is declared after the context refresh and assigned at its first use: with
 * `u32 r = 0;` ahead of the refresh the value is live across func_0203D788
 * and the allocator spends a callee-saved register on it (`push {r4, lr}`
 * instead of the original's `push {r3, lr}`).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039414.c  *       --func func_02039414 --addr 0x02039414 --cc 1.1p1 --arm
 */
u32 func_02039414(void)
{
    u8 *p = func_0203D788();
    u32 r = 0;

    if (p != 0 && ((struct Obj15941 *)p)->f340 != 0)
        r = ((u32 (*)(void))*(u32 *)(*(u32 *)(p + 0x340) + 0x88))();
    if (r == 0) {
        struct Net *q = g_021469D0;

        if (q != 0 && q->f1E9 != 0)
            r = 1;
    }
    return r;
}






void func_02039468(u32 a, u32 b)
{
    u8 *s = (u8 *)func_0203D798();

    if (s[0x64] != 0 && b == 0xff) {
        func_02036B98((char *)g_021469D0->fF4, a);
    } else {
        func_02036B98((char *)g_021469D0->fCC, a);
    }
}






/*
 * Leaf that saves no lr: tail-calls func_020366A8 on the 0xCC queue of the
 * net_system record (docs/families/net_system.h, fCC).  Reached only through
 * the long-branch veneer at 0x0203D56C.
 */
int func_020394C0(void)
{
    return func_020366A8((struct Conn *)g_021469D0->fCC);
}





/*
 * A leaf setter on the link state: store the argument byte at +0x1e7.  It
 * saves no registers, so disasm.py gives it no label and it prints as a run
 * of `.word`s between two pools
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020394DC.c \n *       --func sub_020394DC --addr 0x020394DC --cc 1.1p1 --arm
 */
void sub_020394DC(u8 v)
{
    g_021469D0->f1E7 = v;
}





void func_020394F0(u32 a)
{
    u8 v = ((T_0203D798 *)func_0203D798())->f065;

    if ((u8)(v + 0xff) > 1) {
        return;
    }
    g_021469D0->f1AC = a;
    if (a == 0) {
        return;
    }
    g_021469D0->f1B0 = 0;
    g_021469D0->f1B4[0] = 0;
    g_021469D0->f1B4[1] = 0;
}





/*
 * Set the +0x1e9 flag on the link state.  sub_02039560 is the clearing half;
 * the two are byte-for-byte the same but for the stored constant.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039548.c \n *       --func sub_02039548 --addr 0x02039548 --cc 1.1p1 --arm
 */
void sub_02039548(void)
{
    g_021469D0->f1E9 = 1;
}




/*
 * Clear the +0x1e9 flag sub_02039548 sets.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039560.c \n *       --func sub_02039560 --addr 0x02039560 --cc 1.1p1 --arm
 */
void sub_02039560(void)
{
    g_021469D0->f1E9 = 0;
}




/*
 * Set the +0x1ea flag, but only when the link state has been constructed.
 * The guard and the store share one `ne` predication rather than a branch,
 * and the stored 1 is materialised into r0, the register the pool address
 * was loaded into, because that register is dead by then.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039578.c \n *       --func sub_02039578 --addr 0x02039578 --cc 1.1p1 --arm
 */
void sub_02039578(void)
{
    if (g_021469D0 != 0) {
        g_021469D0->f1EA = 1;
    }
}




/*
 * May the caller proceed?  With no link state, or with the +0x64 byte of the
 * session record set, the answer is an unconditional yes; in the two session
 * states 0 and 5 it is whatever the +0x1eb byte of the link state says; any
 * other state is a yes.
 *
 * The `state == 0 || state == 5` pair is one `cmp` / `cmpne` chain feeding a
 * single `eq` block, so it has to be written as one disjunction: as two
 * `if`s the shared block is duplicated.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039594.c \n *       --func sub_02039594 --addr 0x02039594 --cc 1.1p1 --arm
 */
int sub_02039594(void)
{
    struct Session *s;

    if (g_021469D0 == 0) {
        goto yes;
    }

    s = func_0203D798();
    if (s->unk_64 != 0) {
        goto yes;
    }
    if (s->state == 0 || s->state == 5) {
        return g_021469D0->f1EB;
    }
yes:
    return 1;
}




/*
 * Clamp a slot index to the sentinel: anything from 8 up becomes 0xff, and
 * everything below passes through untouched.  Twelve bytes, no prologue.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020395E0.c \n *       --func sub_020395E0 --addr 0x020395E0 --cc 1.1p1 --arm
 */
int sub_020395E0(int slot)
{
    if (slot >= 8) {
        slot = 0xFF;
    }
    return slot;
}





/*
 *           0x020A7A68 ends at 0x020A7A75; the 3-byte gap kills the `string`
 *           class, so 0x020A7A78 has no witness outside 020395EC..02039658.
 *           Every concrete byte of the body reproduces.
 */
int func_020395EC(struct Entry *a)
{
    struct Entry *v;
    int i;

    func_0203D788();
    v = func_0203996C(0xff);
    if (v == a) {
        return 0xff;
    }
    for (i = 0; i < 9; i++) {
        v = func_0203996C(i);
        if (v == a) {
            return i;
        }
    }
    func_02034714((const char *)str_020A7A68, 0x6e, (const char *)str_020A7A78);
    return -1;
}




/*
 * Reset one slot entry while KEEPING its eight resource pointers.  The eight
 * pointers at +8 are stashed on the stack, each live one's 0x10-byte record
 * is zeroed in place, the entry's own object at +0 is released, the whole
 * 0x50-byte entry is wiped, and the eight pointers are written straight back
 * -- so the resource objects survive the reset and only the entry's state
 * does not.  A real slot index (anything but the 0xFF own-slot spelling)
 * first has its bit cleared out of the +0x40 mask through func_0203A28C and
 * its +0x3E companion zeroed.  func_02039834 and func_020398B4 both drive
 * this in a loop over the nine slots.
 *
 * THE STACK BUFFER HOLDS NINE POINTERS, NOT EIGHT, AND ONLY EIGHT ARE USED.
 * Declared `void *saved[8]` the function is byte-identical but for its frame:
 * `sub sp, sp, #0x20` with r3 in the push, against the image's
 * `sub sp, sp, #0x24` with a seven-register push.  The ninth word is what
 * takes the frame to 0x24 and lets the prologue drop the r3 home slot; the
 * unused slot is not padding the compiler inserted but a declared one.  Nine
 * is also the family's own table size (sub_0203996C resolves nine 0x50-byte
 * entries, eight peers plus the own slot), so the buffer was almost
 * certainly spelled with the same manifest constant as the table and the
 * loop simply stops at the eight peers.  tools/permuter.py exhausted hill
 * mode (206 single mutations, none better) on the eight-element version:
 * the array's own size is outside its mutation set.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039658.c \
 *       --func func_02039658 --addr 0x02039658 --cc 1.1p1 --arm
 */
void func_02039658(struct Entry_02039658 *e, u32 idx)
{
    void *saved[9];
    int i;

    if (idx != 0xff) {
        u16 h = e->key40;
        e->key3e = 0;
        e->key40 = func_0203A28C(h, idx, 0);
    }

    for (i = 0; i < 8; i++) {
        if (e->slot[i] != 0)
            func_02082BCC(e->slot[i], 0, 0x10);
        saved[i] = e->slot[i];
    }

    if (e->obj != 0) {
        func_020307B0(e->obj);
        e->obj = 0;
    }

    func_02082BCC(e, 0, 0x50);

    for (i = 0; i < 8; i++)
        e->slot[i] = saved[i];

    func_02037BE8(idx);
}




/*
 * Clears the slot's `0x3e` field, refreshes its `0x40` field from the
 * selector, then clears the 0x10-byte record its indexed pointer names.
 * The early `popeq` is the null test written as an early return.
 */
void func_0203971C(unsigned char *a, u32 b)
{
    if (b != 0xFF) {
        u16 h = ((struct Obj08833 *)a)->f40;
        ((struct Obj08833 *)a)->f3E = 0;
        ((struct Obj08833 *)a)->f40 = (u16)func_0203A28C(h, b, 0);
    }
    {
        void *p = *(void **)(a + b * 4 + 8);
        if (p == 0)
            return;
        func_02082BCC(p, 0, 0x10);
    }
}




/*
 * (Re)initialise one slot entry and hand it back.  The entry is wiped to
 * 0x50 zero bytes, its packed key at +0x44/+0x46 is set to the 0xFF
 * sentinel and its +0x49/+0x4A state bytes cleared.  Only the OWN slot
 * (index 0xFF) owns the eight 0x10-byte resource records at +8: for it the
 * old eight are released before the wipe and eight fresh ones allocated
 * after it out of the heap named by the record's +0x56 halfword (line 0xC7);
 * a peer slot keeps a null array on both sides of the wipe.
 *
 * This is func_02039834's per-slot worker and the constructive twin of
 * func_02039658 (which keeps the resource pointers rather than
 * reallocating them).
 *
 * TWO LEVERS, and only one of them is an allocation tie.
 *
 * IT RETURNS THE ENTRY.  The image's `mov r0, r8` at +0xBC, between the
 * +0x46 store and the +0x49 store, is the return value: both callers
 * (func_02039834, func_020398B4) discard it, so nothing downstream forces
 * it, but written `void` the function is four bytes short and that `mov` is
 * simply missing.  A dead-looking `mov r0, <callee-saved>` just before the
 * epilogue of a function whose callers ignore the result is the tell.
 *
 * DECLARATION ORDER: `struct Entry *e;` before `u8 *g;`.  The other way
 * round the two swap colours -- the record goes to r8 and the entry to sb,
 * against the image's sb and r8 -- for ten `mov`/`ldr` operands and no size
 * change (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * tools/permuter.py --explain reports this residue as exactly one swapped
 * pair (r8 <-> sb), which is what says to reach for declaration order rather
 * than for the body.
 *
 * The allocation loop's counter is a SECOND variable from the release
 * loop's, zeroed before the wipe call rather than at the loop head: that is
 * the `mov sl, #0` at +0x50 sitting above `bl func_02082BCC`, where reusing
 * `i` would re-zero it after the call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039764.c \
 *       --func func_02039764 --addr 0x02039764 --cc 1.1p1 --arm
 */
struct Entry_02039764 *func_02039764(u32 idx)
{
    struct Entry_02039764 *e;
    u8 *g;
    int i;

    g = func_0203D798();
    func_0203D788();
    e = (struct Entry_02039764 *)func_0203996C(idx);

    if (idx == 0xff) {
        for (i = 0; i < 8; i++) {
            if (e->slot[i] != 0)
                func_020307B0(e->slot[i]);
        }
    }

    i = 0;
    func_02082BCC(e, 0, 0x50);

    if (idx == 0xff) {
        for (; i < 8; i++)
            e->slot[i] = func_02030734(((struct Obj15944 *)g)->f56, 0x10, 1, file_020A7A68, 0xc7);
    }

    e->f4a = 0;
    e->key44 = 0xff;
    e->key46 = 0xff;
    e->f49 = 0;
    return e;
}




/*
 * Module bring-up, the twin of func_020398B4's teardown: reset all eight
 * peer slots through func_02039764, reset the own slot (0xFF) too, assert
 * that the module handle g_021469D4 is NOT already live, then allocate the
 * 0x20-byte handle for it out of the heap named by the record's +0x56
 * halfword (line 0xE5; the assert is line 0xE3).
 *
 * TWO LEVERS, both of which the note in docs/notes/pkt_02039764.c.txt was
 * one step short of.
 *
 * DECLARATION ORDER: `int i;` before `u8 *p;`.  With `p` declared first the
 * allocator colours the object pointer r4 and the reset index r5, which is
 * the swap of the image's r5/r4 the note recorded; swapping the two
 * declarations swaps the colours back
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * The note tried this "and it does not move it" only because the remaining
 * residue below masked the result.
 *
 * ASSERT POLARITY: the guard is `g_021469D4 != 0`, not `== 0`.  The image
 * skips the report with `beq`, so the report runs on the NON-null handle:
 * bringing a module up twice is the error, where func_020398B4's matching
 * assert at line 0x100 fires on the null handle because tearing down a dead
 * module is the error there.  Getting it backwards is a one-byte diff
 * (the condition field of a single branch) and nothing else.
 *
 * The note's second finding is now stale: func_02039764's only branch sites
 * image-wide are this function's own two calls, so `label` still refuses it,
 * but `sole-ref/code` carries it (0x02039764 is a traced function start), and
 * msg_020A7A7C resolves through `sole-ref` the same way.  This file is EXACT,
 * not the MATCH the note predicted.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039834.c \
 *       --func func_02039834 --addr 0x02039834 --cc 1.1p1 --arm
 */
void func_02039834(void)
{
    int i;
    u8 *p;

    p = func_0203D798();
    for (i = 0; i < 8; i++) {
        func_02039764(i);
    }
    func_02039764(0xff);

    if (g_021469D4 != 0) {
        func_02034714(file_020A7A68, 0xe3, msg_020A7A7C);
    }
    g_021469D4 = func_02030734(((struct Obj15945 *)p)->f56, 0x20, 1, file_020A7A68, 0xe5);
}



/*
 * The teardown twin of func_02039834: clear every one of the eight peer slots
 * (func_02039658 on each slot's entry), release the eight resource handles the
 * own-slot entry parks at +8..+0x24, clear the own slot too, then assert the
 * module handle g_021469D4 is live and free it.
 *
 * The own-slot entry is taken once, before the release loop, and the address
 * of each handle word is recomputed per iteration rather than kept in a
 * cursor: func_020307B0 is an ordinary extern, so the store after it needs a
 * fresh `add r0, r5, r6, lsl #2`
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 * The two `mov` of the slot key 0xff share one register with the clear loop's
 * counter, which is why the tail spells the key as `mov r4, #0xff`.
 *
 * The __FILE__ argument is "net_handle.c" at 0x020A7A68, line 0x100.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020398B4.c \
 *       --func func_020398B4 --addr 0x020398B4 --cc 1.1p1 --arm
 */
void func_020398B4(void)
{
    struct Entry *own;
    int i;
    u32 key;

    for (i = 0; i < 8; i++) {
        func_02039658((struct Entry_02039658 *)(sub_0203996C(i)), i);
    }

    own = sub_0203996C(0xff);

    for (i = 0; i < 8; i++) {
        if (own->handle[i] != 0) {
            func_020307B0(own->handle[i]);
            own->handle[i] = 0;
        }
    }

    key = 0xff;
    func_02039658((struct Entry_02039658 *)(sub_0203996C(key)), key);

    if (g_021469D4 == 0) {
        func_02034714(file_020A7A68, 0x100, msg_020A7A88);
    }
    func_020307B0(g_021469D4);
    g_021469D4 = 0;
}
