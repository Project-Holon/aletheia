/*
 * file:     unit_02183B60.c
 * unit:     yes
 * function: func_02183B60, func_02183B6C, func_02183B90, func_02183C34, func_02183C58, func_02183C9C, func_02183D68, func_02183DD4, func_02183DE4, func_02183F5C, func_0218403C, func_0218409C, func_02184120, func_021841C0, func_02184360, func_02184388, func_02184410, func_02184504, func_02184584, func_0218466C, func_02184730, func_021847CC, func_02184894, func_0218495C, func_02184A14, func_02184AB4, func_02184B54, func_02184BF8
 * address:  0x02183B60
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0208068C  0x0208068C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   func_0202E888  0x0202E888  thumb
 *   sub_0202E8CC   0x0202E8CC  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02187808  0x02187808  thumb  ov020
 *   func_02012374  0x02012374  thumb
 *   func_02161B90  0x02161B90  thumb  ov010
 *   func_0201235C  0x0201235C  thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_021860D4  0x021860D4  thumb  ov020
 *   func_02161D64  0x02161D64  thumb  ov010
 *   func_020127F0  0x020127F0  thumb
 *   func_02161F14  0x02161F14  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02158A10  0x02158A10  thumb  ov010
 *   func_02185A68  0x02185A68  thumb  ov020
 *   func_021857C0  0x021857C0  thumb  ov020
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_020145FC  0x020145FC  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC578  0x021BC578  thumb  ov021
 *   func_02014264  0x02014264  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B08  0x02008B08  thumb
 *   func_02008B20  0x02008B20  thumb
 *   func_02021444  0x02021444  thumb
 *   func_02185F6C  0x02185F6C  thumb  ov020
 *   func_02012B38  0x02012B38  thumb
 *   func_0201445C  0x0201445C  thumb
 *   func_02012894  0x02012894  thumb
 *   func_02185B70  0x02185B70  thumb  ov020
 *   func_0218601C  0x0218601C  thumb  ov020
 *   func_0202735C  0x0202735C  thumb
 *   func_02168EEC  0x02168EEC  thumb  ov010
 *   func_02164474  0x02164474  thumb  ov010
 *   func_0202C860  0x0202C860  thumb
 *   func_0201405C  0x0201405C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216E29C  0x0216E29C  thumb  ov010
 *   func_0216CCCC  0x0216CCCC  thumb  ov010
 *   func_020143CC  0x020143CC  thumb
 *   func_02158780  0x02158780  thumb  ov010
 *   func_020142E8  0x020142E8  thumb
 *   func_0201433C  0x0201433C  thumb
 *   func_0201AD0C  0x0201AD0C  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_02008B4C  0x02008B4C  thumb
 *   func_02008B78  0x02008B78  thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_02008C00  0x02008C00  thumb
 *   func_0216A390  0x0216A390  thumb  ov010
 *   func_0203F524  0x0203F524  arm
 *   func_0200C384  0x0200C384  thumb
 *   func_0216AAE4  0x0216AAE4  thumb  ov010
 *   func_0202E848  0x0202E848  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02013B38  0x02013B38  thumb
 *   func_0201407C  0x0201407C  thumb
 *   func_020140D8  0x020140D8  thumb
 *   func_020140B4  0x020140B4  thumb
 *   func_021BE89C  0x021BE89C  thumb  ov021
 *   func_021BE8B8  0x021BE8B8  thumb  ov021
 *   sub_0202E8A4   0x0202E8A4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   ov230_id       0x000000E6  data
 *   func_02012138  0x02012138  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_02014554  0x02014554  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02013D34  0x02013D34  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_0218604C  0x0218604C  thumb  ov020
 *   func_0218606C  0x0218606C  thumb  ov020
 *   func_0218608C  0x0218608C  thumb  ov020
 *   func_021882A0  0x021882A0  arm  ov230d
 *   func_02188318  0x02188318  arm  ov230d
 *   func_021883CC  0x021883CC  arm  ov230d
 *   func_0202E8CC  0x0202E8CC  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0216A358  0x0216A358  thumb  ov010
 *   func_02164454  0x02164454  thumb  ov010
 *   func_0216445C  0x0216445C  thumb  ov010
 *   func_02164464  0x02164464  thumb  ov010
 *   func_0215874C  0x0215874C  thumb  ov010
 *   func_02029C64  0x02029C64  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_021BD648  0x021BD648  thumb  ov021
 *   func_021BD9BC  0x021BD9BC  thumb  ov021
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02013DD0  0x02013DD0  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_021746AC  0x021746AC  thumb  ov011
 *   func_02158428  0x02158428  thumb  ov010
 *   func_02012A30  0x02012A30  thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02029D44  0x02029D44  thumb
 *   func_02029D7C  0x02029D7C  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_021BF58C  0x021BF58C  thumb  ov021
 *   func_021BFD34  0x021BFD34  thumb  ov021
 *   func_02185F48  0x02185F48  thumb  ov020
 *   func_021BF5B4  0x021BF5B4  thumb  ov021
 *   func_021BFD70  0x021BFD70  thumb  ov021
 *   func_021BF5E8  0x021BF5E8  thumb  ov021
 *   func_021BFDA0  0x021BFDA0  thumb  ov021
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B2C  0x02012B2C  thumb
 *   func_021BF61C  0x021BF61C  thumb  ov021
 *   func_021BFDD0  0x021BFDD0  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_021BFE00  0x021BFE00  thumb  ov021
 *   func_021BF644  0x021BF644  thumb  ov021
 *   ov011_id       0x0000000B  data  a1
 *   ov012_id       0x0000000C  data  a1
 */
#include "../../matched/include/Obj02684.h"
#include "../../matched/include/Obj19450.h"
#include "../../matched/include/Obj00082.h"
#include "../../matched/include/Obj02068.h"
#include "../../matched/include/Obj02069.h"
#include "../../matched/include/Obj01649.h"
#include "../../matched/include/Obj04972.h"
#include "../../matched/include/Obj04190.h"
#include "../../matched/include/Obj05964.h"
#include "../../matched/include/Obj04977.h"
#include "../../matched/include/Obj09424.h"
#include "../../matched/include/Obj04978.h"

struct BigObj;
struct Ctx;
struct Evt;
struct S0201235C;
struct Desc;
struct Obj;
struct Big;
struct Sub02008AECObj;
struct Arg;
struct Rec1C;
struct Sub02014444Obj;
struct Blk34;
struct Sub02008AECSession;
struct Sub020140BCObj;
struct Comm;
struct SaveBlock;
struct Rec44;
typedef int (*fp)(void);

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

typedef struct { void *owner; void *input; } Work;

typedef short          s16;

typedef struct Arg {
    u32 f0;
    u8  pad4[4];
    u8  f8[4];
    s16 fC;
} Arg;

typedef unsigned long long u64;

typedef struct { int w[7]; } Blk28;

typedef struct Obj {
    int f00;
    int f04;
    int f08;
    char pad0c[0x14 - 0x0c];
    s16 f14;
    char pad16[0x44 - 0x16];
    int f44;
    u16 f48;
    u16 f4a;
} Obj;

typedef struct { int f[39]; } S9C;

extern void *func_020120F4(const struct Ctx *p);
extern void func_0208068C(int a);
extern void func_02082AC0(int v, u32 a, u32 b);
extern void func_02080B98(void);
extern int func_0202E888(void);
extern u8 sub_0202E8CC(s32 a, s32 b);
extern u8 func_02012984(const struct BigObj *p);
extern int func_02187808(int a, int b, int c);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02161B90(void *p, void *a1, int kind, int sub, int flag);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u8 *func_020127C4(void *p);
extern u8 *func_02012944(void *p);
extern void func_021860D4(u16 *p, int a1, int id);
extern int func_02161D64(int a0);
extern int func_020127F0(int a);
extern void func_02161F14(u16 *out, u8 *in, int c);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_02158A10(int a, int b);
extern void func_02185A68(void *a, int b);
extern void func_021857C0(void *a, int b);
extern unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which);
extern void *func_020298A0(void *a, u32 b, u32 c, u32 d);
extern int func_020145FC(int a0);
extern void *func_0201210C(const struct Ctx *p);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u32 func_02188D20(u8 *p);
extern void func_021BC578(void *p, int v);
extern void func_02014264(void *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008AECObj *func_02008B08(void *sys);
extern void func_02008B20(struct Sub02008AECObj *obj);
extern void func_02021444(void);
extern void func_02185F6C(int a);
extern void *func_02012B38(const struct BigObj *p);
extern void func_0201445C(struct Sub02014444Obj *o, u8 v);
extern struct Rec1C *func_02012894(const struct BigObj *p);
extern void func_02185B70(void *p);
extern void func_0218601C(int a);
extern void func_0202735C(u32 a0, u32 a1);
extern void func_02168EEC(int a);
extern void func_02164474(int a, int b);
extern void func_0202C860(u8 *a0, int a1);
extern u8 func_0201405C(u32 id);
extern u32 func_02012964(const struct BigObj *p);
extern void func_0216E29C(struct Obj *o, int v);
extern void func_0216CCCC(struct Obj *o);
extern u32 func_020143CC(u32 a, u32 b);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void func_0201433C(char *a0, int a1);
extern void *func_0201AD0C(void *sys);
extern void *func_02012F08(int *p);
extern int func_02008B4C(const struct Sub02008AECObj *obj);
extern int func_02008B78(const struct Sub02008AECObj *obj);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern void func_02008C00(struct Sub02008AECSession *s);
extern void func_0216A390(int a, int b);
extern u64 func_0203F524();
extern void func_0200C384(struct Blk34 *p, u32 lo, u32 hi);
extern void func_0216AAE4(void *sys, void *party, int season);
extern int func_0202E848(int a0, int a1, int a2);
extern u16 func_02188C84(u8 *p);
extern u32 func_02013B38(u32 id);
extern int func_0201407C(int a, int b, int c);
extern u8 func_020140D8(struct Sub020140BCObj *p);
extern u32 func_020140B4(void *a);
extern int func_021BE89C(int a, u32 b);
extern int func_021BE8B8(int a, int b);
extern u8 sub_0202E8A4(u8 a);
extern u32 func_02012844(const struct BigObj *p);
extern void *func_021625CC(char *p, unsigned i);
extern u8 func_021626E8(u8 *p);
extern u32 func_02012138(const struct Ctx *p);
extern u8 func_0201447C(struct Sub02014444Obj *o, u8 v);
extern int func_02014554(int a, int b);
extern int func_02034AC4(int id);
extern void func_02034A5C(int handle);
extern u32 func_02013D34(u32 id);
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
extern void *func_0218604C(void);
extern void *func_0218606C(void);
extern void func_0218608C(void);
extern u32 func_021882A0(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188318(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_021883CC(void (*a)(void), void (*b)(void), u32 c);
extern u8 func_0202E8CC(s32 a, s32 b);
extern void *func_02012934(const struct BigObj *p);
extern int func_0216A358(int a, int b, u32 *p, int c);
extern int func_02164454(int a, int b);
extern int func_0216445C(int a, int b);
extern int func_02164464(int a, int b);
extern void func_0215874C(void *p);
extern void *func_02029C64(void *a);
extern void *func_02188C7C(u8 *p);
extern void func_0216D9A0(void *map);
extern int func_021BD648(u8 *p);
extern int func_021BD9BC(u32 *p);
extern int func_02158344(int a0);
extern unsigned int *func_0216D9E4(void *c);
extern int func_02013DD0(int a);
extern u8 func_0215841C(void *p);
extern int func_021746AC(char *a, int b);
extern u8 func_02158428(u8 *p);
extern unsigned int func_02012A30(const struct BigObj *p);
extern void *func_02161824(void *a, void *b);
extern void func_02029D44(u32 a, u32 b, u16 c, u8 d);
extern void func_02029D7C(int a, int b);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern void func_021BC550(void *p, int v);
extern void *func_021BF58C(int a, void *p, int c);
extern int func_021BFD34(int ctx, int a, int b, u8 *p);
extern void func_02185F48(void *p);
extern void *func_021BF5B4(int a, int b, int c, int d, int e, int f);
extern void *func_021BFD70(int a0, void *p, int a2, int a3);
u32 func_021BF5E8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void *func_021BFDA0(int a0, void *p, int a2, int a3);
extern void *func_020127A4(struct SaveBlock *p);
extern void func_02012B2C(struct Rec44 *p, u32 v);
extern void *func_021BF61C(int a, int b, int c);
extern void *func_021BFDD0(int a0, void *p, int a2, int a3);
extern u32 func_02188D38(u8 *p);
extern int func_021C6E48(int a);
extern void *func_021BFE00(int a0, void *p, int a2);
extern int func_021BF644(int a, int b, int c);
int func_02183B60(int f);
void func_02183B6C(int a, int *p);
int func_02183B90(int a, int *state, int *p);
void *func_02183C34(void *owner, void *input);
void func_02183C58(int a);
int func_02183C9C(void *obj, int *state, Arg *arg);
extern int func_02183D68();
void func_02183DD4(void *p);
int func_02183DE4(int ctx, int *state, u8 *p);
int func_02183F5C(int a0, u8 *a1);
void func_0218403C(u8 *p);
void func_0218409C(u8 *p, int arg);
void func_02184120(u8 *p, int arg);
int func_021841C0(int ctx, int *state, u8 **pp);
void *func_02184360(u8 *p, int value);
int func_02184388(int a, int *state, u8 *p);
int func_02184410(int a, int *state, u8 *p);
int func_02184504(int a, int *state, u8 *p);
int func_02184584(int ctx, int *state, u8 *p);
int func_0218466C(int ctx, int *state, u8 *p);
int func_02184730(int ctx, int *state, u8 *p);
int func_021847CC(int ctx, int *state, u8 *p);
int func_02184894(void *a, int *state, Obj *o);
int func_0218495C(int ctx, int *state, u8 *p);
int func_02184A14(int ctx, int *state, u8 *p);
int func_02184AB4(int ctx, int *state, u8 *p);
int func_02184B54(int ctx, int *state, u8 *p);
int func_02184BF8(void *ctx, int *st, int *p);
extern u8 ov230_id[];
extern char ov011_id[];
extern char ov012_id[];






int func_02183B60(int f)
{
    if (f)
        ((fp)f)();
    return ~f;
}





void func_02183B6C(int a, int *p)
{
    switch (*p) {
    case 0: func_02183C34((void *)a, p); break;
    case 1: func_02183F5C(a, (unsigned char *)p); break;
    case 2: func_02183D68(a); break;
    }
}





int func_02183B90(int a, int *state, int *p)
{
    int w = p[0];
    int s = (int)func_020120F4((const struct Ctx *)w);
    int r;
    int t;

    switch (*state) {
    case 0:
        func_0208068C(0x1ff);
        func_02082AC0(0, 0x1a << 22, 0x29 << 14);
        func_02080B98();
        (*state)++;
        break;
    case 1:
        sub_0202E8CC(s, (u16)func_0202E888());
        t = func_02012984((const struct BigObj *)s);
        r = func_02187808(w, t, t);
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*state)++;
        break;
    case 2:
        r = (int)func_02161B90((void *)w, (void *)a, 5, 0, 1);
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*state)++;
        break;
    case 3:
        func_0201235C((struct S0201235C *)a, (u32 *)func_02183D68(w, p[1]));
        break;
    }
    return 0;
}




void *func_02183C34(void *owner, void *input)
{
    void *task;
    Work *w;
    task = func_020122C0(owner, 0, (void *)func_02183B90, sizeof(Work));
    w = func_020124E8(task);
    w->owner = owner;
    w->input = input;
    return task;
}





void func_02183C58(int a)
{
    int w = (int)func_020120F4((const struct Ctx *)a);
    int r5 = (int)func_020127C4((void *)w);

    func_021860D4((u16 *)r5, (int)func_02012944((void *)w), 1);
    func_02161D64((int)func_020127C4((void *)w));
    r5 = func_020127F0(w);
    func_02161F14((u16 *)r5, (u8 *)func_020127C4((void *)w), 1);
}





/*
 * Byte-correct (202 bytes + 2 padding). The one unresolved site is
 * +005E THM_CALL func_02029DF4: an unlabelled arm9 Thumb thunk
 * (ldr r3,[pc,#0]; bx r3; .word 0x02029EB5), so no label and no
 * outside witness. It is Ilias's arm9 leaf, verified EXACT at
 * 0x02029DF4 (region arm9, thumb, dsi/1.1p1 -O4,p) as:
 *     extern int func_02029EB4(u32 a, int b, u32 c);   (0x02029EB4 thumb)
 *     int func_02029DF4(u32 a, int b, u32 c)
 *     { return func_02029EB4(a, b, c); }
 * Once that leaf is filed in an arm9 shard this caller resolves as
 * `matched` and goes EXACT. The same call caps the twin
 * src/matched/ov/ov012_func_021743A4.c, which `one` now reports MATCH.
 */
int func_02183C9C(void *obj, int *state, Arg *arg)
{
    u32 x = arg->f0;
    u32 t = (u32)func_020120F4((const struct Ctx *)x);
    void *w;

    func_0201296C((const struct BigObj *)t);
    switch (*state) {
    case 0:
        func_02158A10(x, 1);
        func_02185A68((void *)x, (u16)arg->fC);
        func_021857C0((void *)x, (int)arg->f8);
        (*state)++;
        break;
    case 1:
        func_02012374(obj, func_020298A0((void *)x, func_02029DF4((void *)t, arg->fC, func_02012984((const struct BigObj *)t)), 0, 0x3c));
        (*state)++;
        break;
    case 2:
        func_02012374(obj, (struct Evt **)func_020145FC(x));
        (*state)++;
        break;
    case 3:
        func_02012374(obj, (struct Evt **)func_021BE92C((void *)x, (int)func_0201210C((void *)x), 1, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        w = func_0201210C((void *)x);
        if (func_02188D20(w) != 0)
            func_021BC578((void *)func_02188D20(w), arg->fC);
        return 1;
    }
    return 0;
}





int func_02183D68(int a)
{
    int r6 = (int)func_020122C0((void *)a, 0, func_02183C9C, 0x24);
    int *r4 = func_020124E8((struct Obj *)r6);

    r4[0] = a;
    r4[1] = (int)func_020120F4((const struct Ctx *)a);
    func_02014264(r4 + 2);
    func_02183C58(a);
    func_02008B20(func_02008B08(func_02012EBC((struct Big *)r4[1])));
    func_02021444();
    func_02185F6C(r4[1]);
    func_0208068C(0x1ff);
    func_02082AC0(0, 0x1a << 22, 0x29 << 14);
    func_02080B98();
    return r6;
}



/*
 * interface: 020127C4 forwards 020127D0's returned pointer in r0.
 */
void func_02183DD4(void *p)
{
    func_02161D64((int)func_020127C4(func_020120F4(p)));
}




/*
 * Byte-correct at 376 of 376 bytes.  Four wildcarded call sites, all of
 * them unlabelled tail-call leaves with no witness outside this range.
 * Each leaf's C below was verified EXACT with `match.py one` in a scratch
 * file; none is filed, because the arm9 one belongs to Ilias:
 *   +0xD4  func_02029DF4 (arm9, Ilias's): ldr r3,=func_02029EB4+1; bx r3
 *          int func_02029DF4(int a, int b, int c)
 *          { return func_02029EB4(a, b, c); }
 *   +0x96  func_02164474 (ov010): void f(int a, int b) { func_0215E364(a, b); }
 *   +0xB6  func_0216E29C (ov010): void f(u8 *p, int n)
 *          { func_02048F4C(*(int *)(p + 0x44), 0x3a, n); }   (02048F4C arm)
 *   +0xBC  func_0216CCCC (ov010): void f(u8 *p)
 *          { func_02082BCC(*(int *)(p + 0x44), 0, 0x310); }  (02082BCC arm)
 * Filing the three ov010 leaves (region hint ov010: ov009 overlaps them)
 * and the arm9 leaf makes this file EXACT unchanged.  This is the callback
 * func_02183F5C registers through func_020122C0.
 *
 * 2026-10-04 (wD2 lane 02): the last blocker, the ov010 leaf func_02164474, is now filed as
 * src/matched/ov/ov010_func_02164474.c (EXACT); the other three leaves were already filed. The tool still reports
 * it unresolved because the manifest is stale. Expected EXACT after the integrator's manifest refresh.
 */
int func_02183DE4(int ctx, int *state, u8 *p)
{
    int a;
    int s;
    int m;
    u8 *q;
    int n;
    int t;

    a = *(int *)(p + 0);
    s = (int)func_020120F4((const struct Ctx *)a);
    m = func_0201296C((const struct BigObj *)s);

    switch (*state) {
    case 0:
        func_0201445C(func_02012B38((const struct BigObj *)s), 1);
        if (*(int *)(p + 0xc) != 0) {
            q = (u8 *)func_02012894((const struct BigObj *)s);
            *(s16 *)(p + 8) = *(s16 *)(q + 4);
            func_02185B70((void *)a);
            func_02185A68((void *)a, *(u16 *)(p + 8));
            func_0218601C(s);
            func_021857C0((void *)a, (int)q);
            func_0202735C(*(u16 *)(q + 4), s);
        } else {
            func_02185A68((void *)a, *(u16 *)(p + 8));
            func_0218601C(s);
            func_02168EEC(s);
            func_02164474(s, *(u16 *)(p + 8));
            func_0202C860((u8 *)s, *(u16 *)(p + 8));
            n = func_0201405C(*(u16 *)(p + 8));
            t = func_02012964((const struct BigObj *)s);
            if (n < 16) {
                func_0216E29C((struct Obj *)t, n);
            } else {
                func_0216CCCC((struct Obj *)t);
            }
        }
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, func_020298A0((void *)a, func_02029DF4((void *)s, *(u16 *)(p + 8), func_02012984((const struct BigObj *)s)), 0, 0x3c));
        (*state)++;
        break;
    case 2:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_020145FC(a));
        (*state)++;
        break;
    case 3:
        if (*(int *)(p + 0xc) != 0 && *((u16 *)func_020143CC(m, 0x4041)) != 0) {
            func_02158780((void *)ctx, 0x83b, 0, 0, 0x15);
        } else {
            u8 k = func_02012984((const struct BigObj *)s);
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)a, (int)func_0201210C((const struct Ctx *)a), 3, 0, 0, k, k));
        }
        (*state)++;
        break;
    case 4:
        t = (int)func_0201210C((const struct Ctx *)a);
        if (func_02188D20((u8 *)t) != 0) {
            func_021BC578((void *)func_02188D20((u8 *)t), *(u16 *)(p + 8));
        }
        return 1;
    }
    return 0;
}




int func_02183F5C(int a0, u8 *a1)
{
    int t0;
    int *s;
    int r5;
    int r7;
    int r6;
    int h;
    u64 t;

    t0 = (int)func_020122C0((void *)a0, 0, (void *)((int)func_02183DE4), 0x10);
    s = func_020124E8((struct Obj *)t0);
    s[0] = a0;
    s[1] = (int)func_020120F4((const struct Ctx *)a0);
    ((struct Obj02684 *)s)->f8 = ((struct Obj19450 *)a1)->f10;
    r5 = func_0201296C((const struct BigObj *)s[1]);
    s[3] = func_020142E8((void *)r5, 0x966);
    func_0201433C((char *)r5, 0x966);
    r7 = (int)func_02012EBC((struct Big *)s[1]);
    r5 = (int)func_02008B08((void *)r7);
    r6 = (int)func_0201AD0C((void *)r7);
    h = (int)func_02012F08((int *)s[1]);
    if (!func_02008B4C((const struct Sub02008AECObj *)r5) || !func_02008B78((const struct Sub02008AECObj *)r5)) {
        func_02008C00(func_02008B14((void *)r7));
        func_0216A390(s[1], r6);
        t = func_0203F524();
        func_0200C384((struct Blk34 *)h, (u32)t, (u32)(t >> 32));
    }
    func_02008B20((struct Sub02008AECObj *)r5);
    func_0216AAE4((void *)s[1], (void *)r6, func_02012984((const struct BigObj *)s[1]));
    func_02183DD4((void *)a0);
    func_02021444();
    func_0208068C(0x1FF);
    func_02082AC0(0, 0x06800000, 0xA4000);
    func_02080B98();
    return t0;
}




void func_0218403C(u8 *p)
{
    u16 s[2];
    int r4;
    int r6;
    int flag;
    u16 hi;

    func_0202E848(((struct Obj00082 *)p)->f4, (int)(&s[1]), (int)(&s[0]));
    r4 = func_02188C84((u8 *)(*(int *)&((struct Obj00082 *)p)->f8));
    r6 = func_0201407C(r4, func_02013B38(((struct Obj00082 *)p)->f14), 0);
    flag = 0;
    if (func_020140D8((struct Sub020140BCObj *)r6) != 0)
        flag = 1;
    func_020140B4((void *)r6);
    hi = s[1];
    if (s[0] != hi && flag) {
        ((struct Obj00082 *)p)->f44 = 1;
        ((struct Obj00082 *)p)->f48 = hi;
        ((struct Obj00082 *)p)->f4A = s[0];
    }
}




void func_0218409C(u8 *p, int arg)
{
    u8 *q = p + 0x4c;

    ((struct Obj02068 *)q)->f4 = *(int *)&((struct Obj00082 *)p)->f0;
    ((struct Obj02068 *)q)->f8 = ((struct Obj00082 *)p)->f4;
    ((struct Obj02068 *)q)->fC = *(int *)&((struct Obj00082 *)p)->f8;
    ((struct Obj02068 *)q)->f10 = ((struct Obj00082 *)p)->f2C;
    ((struct Obj00082 *)p)->f4C = arg;
    ((struct Obj02068 *)q)->f18 = ((struct Obj00082 *)p)->fC;
    *(Blk28 *)(q + 0x1c) = *(Blk28 *)(p + 0x10);
    ((struct Obj02068 *)q)->f38 = func_021BE89C(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02068 *)q)->f3C = func_021BE8B8(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02068 *)q)->f40 = (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) ? 1 : 0;
    ((struct Obj02068 *)q)->f44 = sub_0202E8A4(((struct Obj00082 *)p)->f48);
    ((struct Obj02068 *)q)->f45 = ((struct Obj00082 *)p)->f4A;
    ((struct Obj02068 *)q)->f48 = 0;
    ((struct Obj02068 *)q)->f4C = 0;
}




void func_02184120(u8 *p, int arg)
{
    u8 *q = p + 0x4c;

    ((struct Obj02069 *)q)->f4 = *(int *)&((struct Obj00082 *)p)->f0;
    ((struct Obj02069 *)q)->f8 = ((struct Obj00082 *)p)->f4;
    ((struct Obj02069 *)q)->fC = *(int *)&((struct Obj00082 *)p)->f8;
    ((struct Obj02069 *)q)->f10 = ((struct Obj00082 *)p)->f2C;
    ((struct Obj00082 *)p)->f4C = arg;
    ((struct Obj02069 *)q)->f18 = ((struct Obj00082 *)p)->fC;
    *(Blk28 *)(q + 0x1c) = *(Blk28 *)(p + 0x10);
    ((struct Obj02069 *)q)->f38 = func_021BE89C(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02069 *)q)->f3C = func_021BE8B8(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02069 *)q)->f40 = (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) ? 1 : 0;
    ((struct Obj02069 *)q)->f44 = sub_0202E8A4(((struct Obj00082 *)p)->f48);
    ((struct Obj02069 *)q)->f45 = ((struct Obj00082 *)p)->f4A;
    if (((struct Obj00082 *)p)->f10 == 1) {
        ((struct Obj02069 *)q)->f14 = 0;
        return;
    }
    ((struct Obj02069 *)q)->f14 = func_021626E8(func_021625CC((char *)func_02012844((const struct BigObj *)(((struct Obj00082 *)p)->f4)), ((struct Obj00082 *)p)->f16));
}




/*
 * Two spellings are load-bearing.  The u8 range check on func_02026454's
 * result is `adds r0, #0xff; lsls/lsrs #0x18; cmp #1; bhi`: written
 * `(u8)(v - 1) <= 1` it compiles to `subs r0, r0, #1` (one byte out), and as
 * `switch (v) { case 1: case 2: }` it grows by 4 bytes with two compares;
 * only `(u8)(v + 0xff) <= 1` gives the add.  The dead `str r2, [sp, #0xc]`
 * after `adds r2, #0x14` is `a += 0x14;` on the spilled local before the
 * func_0216A358 call.  func_021882A0/02188318/021883CC are ov230's decrypted
 * code (ov230d token); each gets the range func_02183B60 to one of this
 * overlay's end markers.  Leaves filed for this function: ov010 0x02164454,
 * 0x0216445C, 0x02164464 and ov020 0x0218608C.
 */
int func_021841C0(int ctx, int *state, u8 **pp)
{
    u8 *p;
    int x;
    int y;
    int z;
    int w;
    void *c;
    int b;
    int a;

    p = *pp;
    z = ((struct Obj01649 *)p)->f8;
    x = ((struct Obj01649 *)p)->f0;
    y = ((struct Obj01649 *)p)->f4;
    w = func_02012138((const struct Ctx *)x);

    switch (*state) {
    case 0:
        func_0201447C(func_02012B38((const struct BigObj *)y), 2);
        func_02012374((struct Evt *)ctx, (struct Evt **)func_02014554(x, z));
        (*state)++;
        break;
    case 1:
        func_02034AC4((int)ov230_id);
        if (func_02013D34(((struct Obj01649 *)p)->f14) == 1 && (u8)(func_02026454((void *)w) + 0xff) <= 1) {
            func_02026400((struct Comm *)w);
            *state = 2;
        } else {
            *state = 3;
        }
        break;
    case 2:
        if (func_02026454((void *)w) == 0) {
            *state = 3;
        }
        break;
    case 3:
        func_021882A0((void (*)(void))func_02183B60, (void (*)(void))func_0218604C, 0);
        func_02185B70((void *)x);
        if (((struct Obj01649 *)p)->f40 != 0 && ((struct Obj01649 *)p)->f44 != 0) {
            func_0202E8CC(y, ((struct Obj01649 *)p)->f4A);
            a = (int)func_02008B14(func_02012EBC((struct Big *)y));
            b = func_02012984((const struct BigObj *)y);
            c = func_02012934((void *)y);
            func_0216AAE4((void *)y, c, b);
            a += 0x14;
            func_0216A358(y, (int)c, (u32 *)a, b);
        }
        func_02188318((void (*)(void))func_02183B60, (void (*)(void))func_0218606C, 0);
        func_02185A68((void *)x, ((struct Obj01649 *)p)->f14);
        func_021857C0((void *)x, (int)(p + 0x10));
        if (((struct Obj01649 *)p)->f30 != 4) {
            func_0202735C(((struct Obj01649 *)p)->f14, y);
        }
        func_021883CC((void (*)(void))func_02183B60, func_0218608C, 0);
        switch (((struct Obj01649 *)p)->f30) {
        case 1:
            func_02164454(y, ((struct Obj01649 *)p)->f14);
            break;
        case 2:
            func_02164464(y, ((struct Obj01649 *)p)->f14);
            break;
        case 3:
            func_0216445C(y, ((struct Obj01649 *)p)->f14);
            break;
        }
        func_02034A5C((int)ov230_id);
        func_0215874C((void *)w);
        (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_020145FC(x));
        (*state)++;
        break;
    case 5:
        func_02012374((struct Evt *)ctx, func_02029C64((void *)x));
        (*state)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}


void *func_02184360(u8 *p, int value)
{
    void *task;
    void **w;
    task = func_020122C0(((struct Obj00082 *)p)->f0, 0, (void *)func_021841C0, 4);
    w = func_020124E8(task);
    *w = p;
    p[0x30] = value;
    return task;
}



int func_02184388(int a, int *state, u8 *p)
{
    void *w = ((struct Obj00082 *)p)->f8;

    switch (*state) {
    case 0:
        func_0218403C(p);
        func_0216D9A0(func_02188C7C((u8 *)w));
        func_0218409C(p, a);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BD648(p + 0x4c));
        (*state)++;
        return 0x21;
    case 1:
        func_02012374((struct Evt *)a, func_02184360(p, 0));
        (*state)++;
        break;
    case 2:
        func_02184120(p, a);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BD9BC((u32 *)(p + 0x4c)));
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}



/*
 * Byte-correct (MATCH*: 242 compiled against a 244-byte listing extent, the
 * two bytes are alignment padding).  The one wildcarded site is +0x4C,
 * `bl func_02013DD0`: an unlabelled arm9 leaf (Ilias's) with no witness
 * outside this range, the documented near miss after unit_02013D9C.c.  Its
 * bytes (ldr r1,=0x0209DFC0; ldr r3,=sub_02013B10+1; movs r2,#4; bx r3) are
 *     extern const unsigned short tbl_0209DFC0[];      (data)
 *     extern int sub_02013B10(int v, const unsigned short *t, int n);
 *     int func_02013DD0(int v) { return sub_02013B10(v, tbl_0209DFC0, 4); }
 * which now verifies EXACT on its own (2026-09-29, `match.py one --region
 * arm9 --thumb`: the table by sole-ref/data, sub_02013B10 by literal), so
 * the unit_02013D9C.c note that it has no witness is out of date.  Once
 * that leaf is filed in an arm9 shard, this file goes EXACT unchanged.
 */
int func_02184410(int a, int *state, u8 *p)
{
    int z;
    int y;
    u8 *w;

    z = *(int *)(p + 8);
    y = *(int *)(p + 4);
    w = (u8 *)func_02158344(func_02012138((const struct Ctx *)(*(int *)(p + 0))));

    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C((u8 *)z));
        if (func_02013DD0(*(u16 *)(p + 0x14)) == 1) {
            *state = 5;
        } else {
            *state = 1;
        }
        break;
    case 1:
        func_0218409C(p, a);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BD648(p + 0x4c));
        (*state)++;
        return 0x21;
    case 2:
        func_02012374((struct Evt *)a, func_02184360(p, 0));
        (*state)++;
        break;
    case 3:
        func_02184120(p, a);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BD9BC((u32 *)(p + 0x4c)));
        (*state)++;
        break;
    case 4:
        return 1;
    case 5:
        if (w == 0) {
            *state = 7;
            break;
        }
        if (func_021746AC((char *)w, func_0215841C((void *)y)) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (w == 0) {
            *state = 7;
            break;
        }
        if (func_02158428(w) == 1) {
            *state = 1;
        }
        break;
    case 7:
        func_0216D9E4(func_02188C7C((u8 *)z));
        return 1;
    }
    return 0;
}



int func_02184504(int a, int *state, u8 *p)
{
    int r;
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj04972 *)p)->f0;
    z = ((struct Obj04972 *)p)->f8;
    y = ((struct Obj04972 *)p)->f4;
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        r = (int)func_02161824((void *)x, (void *)z);
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*state)++;
        break;
    case 1:
        func_02029D44(v, y, ((struct Obj04972 *)p)->f14, (u8)((struct Obj04972 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 2:
        r = (int)func_02184360(p, ((struct Obj04972 *)p)->f30);
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}



int func_02184584(int ctx, int *state, u8 *p)
{
    int x;
    int z;

    x = *(int *)&((struct Obj00082 *)p)->f0;
    z = *(int *)&((struct Obj00082 *)p)->f8;

    switch (*state) {
    case 0:
        func_0218403C(p);
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        if (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) {
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, 0, 0));
        } else {
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, func_021BE89C(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14), 0));
        }
        (*state)++;
        break;
    case 2:
        func_02012374((struct Evt *)ctx, func_02184360(p, ((struct Obj00082 *)p)->f30));
        (*state)++;
        break;
    case 3:
        if (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) {
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, 3, 0, 0, (u8)((struct Obj00082 *)p)->f48, (u8)((struct Obj00082 *)p)->f4A));
        } else {
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, func_021BE8B8(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14), 0, 1, 0, 0));
        }
        (*state)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}



int func_0218466C(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj04190 *)p)->f0;
    y = ((struct Obj04190 *)p)->f4;
    z = ((struct Obj04190 *)p)->f8;
    v = (int)func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 8:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, 2, 0));
        (*state)++;
        break;
    case 9:
        func_02029D44(v, y, ((struct Obj04190 *)p)->f14, (u8)((struct Obj04190 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 10:
        func_02012374((struct Evt *)ctx, func_02184360(p, ((struct Obj04190 *)p)->f30));
        (*state)++;
        break;
    case 11:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, 2, 0, 0, 0, 0));
        (*state)++;
        break;
    case 12:
        func_021BC550((void *)func_02188D20((u8 *)z), *(s16 *)&((struct Obj04190 *)p)->f14);
        return 1;
    default:
        (*state)++;
        break;
    }
    return 0;
}



int func_02184730(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj05964 *)p)->f0;
    y = ((struct Obj05964 *)p)->f4;
    z = ((struct Obj05964 *)p)->f8;
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BFD34(ctx, x, z, p + 0x34));
        (*state)++;
        break;
    case 2:
        func_02029D44(v, y, ((struct Obj05964 *)p)->f14, (u8)((struct Obj05964 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, func_02184360(p, 0));
        (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BF58C(ctx, (void *)x, z));
        (*state)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}



int func_021847CC(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = *(int *)&((struct Obj00082 *)p)->f0;
    y = ((struct Obj00082 *)p)->f4;
    z = *(int *)&((struct Obj00082 *)p)->f8;
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_0218403C(p);
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, func_021BFD70(ctx, (void *)x, z, ((struct Obj00082 *)p)->f44));
        (*state)++;
        break;
    case 2:
        func_02185F48((void *)y);
        func_02029D44(v, y, ((struct Obj00082 *)p)->f14, (u8)((struct Obj00082 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, func_02184360(p, 2));
        (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)ctx, func_021BF5B4(ctx, x, z, ((struct Obj00082 *)p)->f44,
                                         ((struct Obj00082 *)p)->f48, ((struct Obj00082 *)p)->f4A));
        (*state)++;
        break;
    case 5:
        func_021BC550((void *)func_02188D20((u8 *)z), *(s16 *)&((struct Obj00082 *)p)->f14);
        return 1;
    }
    return 0;
}



int func_02184894(void *a, int *state, Obj *o)
{
    int f0 = o->f00;
    int f4 = o->f04;
    int f8 = o->f08;
    int h = func_02012A30((const void *)f4);

    switch (*state) {
    case 0:
        func_0218403C((u8 *)o);
        func_02012374(a, func_02161824((void *)f0, (void *)f8));
        (*state)++;
        break;
    case 1:
        func_02012374(a, func_021BFDA0((int)a, (void *)f0, f8, o->f44));
        (*state)++;
        break;
    case 2:
        func_02185F48((void *)f4);
        func_02029D44((int)h, (int)f4, (u16)o->f14, (u8)o->f4a);
        func_02029D7C(h, f4);
        (*state)++;
        break;
    case 3:
        func_02012374(a, func_02184360((u8 *)o, 2));
        (*state)++;
        break;
    case 4:
        func_02012374(a, (struct Evt **)func_021BF5E8((u32)a, f0, f8, o->f44, o->f48, o->f4a));
        (*state)++;
        break;
    case 5:
        func_021BC550((void *)func_02188D20((u8 *)f8), o->f14);
        return 1;
    }
    return 0;
}



int func_0218495C(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj04977 *)p)->f0;
    y = ((struct Obj04977 *)p)->f4;
    z = ((struct Obj04977 *)p)->f8;
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, func_021BFDD0(ctx, (void *)x, z, 1));
        (*state)++;
        break;
    case 2:
        func_02012B2C((struct Rec44 *)((int)func_020127A4((struct SaveBlock *)y)), 0);
        func_02029D44(v, y, ((struct Obj04977 *)p)->f14, (u8)((struct Obj04977 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, func_02184360(p, 3));
        (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)ctx, func_021BF61C(ctx, x, z));
        (*state)++;
        break;
    case 5:
        func_021BC550((void *)func_02188D20((u8 *)z), *(s16 *)&((struct Obj04977 *)p)->f14);
        return 1;
    }
    return 0;
}



int func_02184A14(int ctx, int *state, u8 *p)
{
    int x = *(int *)&((struct Obj00082 *)p)->f0;
    int z = *(int *)&((struct Obj00082 *)p)->f8;
    int t = func_02188D38((u8 *)z);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, 1, 0));
        (*state)++;
        break;
    case 1:
        if (func_021C6E48(t)) {
            func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
            (*state)++;
        }
        break;
    case 2:
        func_02012374((struct Evt *)ctx, func_02184360(p, 0));
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, 1, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        func_021BC550((void *)func_02188D20((u8 *)z), *(s16 *)&((struct Obj00082 *)p)->f14);
        return 1;
    }
    return 0;
}



int func_02184AB4(int ctx, int *state, u8 *p)
{
    int x = ((struct Obj09424 *)p)->f0;
    int z = ((struct Obj09424 *)p)->f8;
    int r;
    S9C *o;

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, 0, 0));
        (*state)++;
        break;
    case 2:
        r = (int)func_020122C0((void *)x, 0, func_02184504, 0x9c);
        o = func_020124E8((struct Obj *)r);
        *o = *(S9C *)p;
        func_02012374((struct Evt *)ctx, (struct Evt **)r);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        func_021BC550((void *)func_02188D20((u8 *)z), ((struct Obj09424 *)p)->f14);
        return 1;
    }
    return 0;
}



int func_02184B54(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj04978 *)p)->f0;
    y = ((struct Obj04978 *)p)->f4;
    z = ((struct Obj04978 *)p)->f8;
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, func_021BFE00(ctx, (void *)x, z));
        (*state)++;
        break;
    case 2:
        func_02029D44(v, y, ((struct Obj04978 *)p)->f14, (u8)((struct Obj04978 *)p)->f4A);
        func_02029D7C(v, y);
        func_02012374((struct Evt *)ctx, func_02184360(p, 0));
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BF644(ctx, x, z));
        (*state)++;
        break;
    case 4:
        func_021BC550((void *)func_02188D20((u8 *)z), *(s16 *)&((struct Obj04978 *)p)->f14);
        return 1;
    }
    return 0;
}



int func_02184BF8(void *ctx, int *st, int *p)
{
    int a = p[0];
    int b = p[2];
    int r;

    switch (*st) {
    case 0:
        r = (int)func_021BFDD0((int)ctx, (void *)a, b, 0);
    join:
        func_02012374(ctx, (struct Evt **)r);
        (*st)++;
        break;
    case 1:
        r = (int)func_02184360((u8 *)p, 0);
        goto join;
    case 2:
        func_02034A5C((int)ov012_id);
        func_02034AC4((int)ov011_id);
        func_02158780(ctx, 0x83A, 0, 0, 0x15);
        (*st)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
