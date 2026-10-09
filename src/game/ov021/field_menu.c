/*
 * file:     field_menu.c
 * unit:     yes
 * function: func_021A7CE8, func_021A7E3C, func_021A7EB4, func_021A7F38, func_021A80FC, func_021A810C, func_021A811C, func_021A8140, func_021A8198, func_021A81DC, func_021A81EC, func_021A8200, func_021A8214, func_021A8234, func_021A8244, func_021A8268, func_021A8278, func_021A82A8, func_021A82D8, func_021A8324, func_021A834C, func_021A836C, func_021A84A8, func_021A84BC, func_021A8588, func_021A85B4
 * address:  0x021A7CE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02185B88  0x02185B88  thumb  ov020
 *   func_0218F0F8  0x0218F0F8  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021BDCC8  0x021BDCC8  thumb  ov021
 *   func_02029D7C  0x02029D7C  thumb
 *   func_021618E0  0x021618E0  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_021BDD40  0x021BDD40  thumb  ov021
 *   func_021BDD48  0x021BDD48  thumb  ov021
 *   func_021BDD20  0x021BDD20  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_021BDD34  0x021BDD34  thumb  ov021
 *   func_0218E160  0x0218E160  thumb  ov021
 *   func_021BDCB8  0x021BDCB8  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_021BDC94  0x021BDC94  thumb  ov021
 *   func_02162370  0x02162370  thumb  ov010
 *   func_021A7B10  0x021A7B10  thumb  ov021
 *   func_02029D44  0x02029D44  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A3484  0x021A3484  thumb  ov021
 *   func_0207CEE4  0x0207CEE4  arm
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_021A36C8  0x021A36C8  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_02188C98  0x02188C98  thumb
 *   func_0218DC6C  0x0218DC6C  thumb
 *   func_0218C7D8  0x0218C7D8  thumb
 *   func_0218C860  0x0218C860  thumb
 *   func_0218C8D8  0x0218C8D8  thumb  ov021
 *   func_0218C88C  0x0218C88C  thumb
 *   func_0218C990  0x0218C990  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DDF94     0x021DDF94  data  ov021  a1
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_020355C4  0x020355C4  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_021A8D40  0x021A8D40  thumb  ov021
 *   func_0201C440  0x0201C440  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_021A8B18  0x021A8B18  thumb  ov021
 *   func_021A8874  0x021A8874  thumb  ov021
 *   func_021A8BB8  0x021A8BB8  thumb  ov021
 *   func_02049238  0x02049238  arm
 *   func_02040588  0x02040588  arm
 *   func_021A90E0  0x021A90E0  thumb  ov021
 *   func_021A8DD8  0x021A8DD8  thumb  ov021
 *   func_020129C4  0x020129C4  thumb
 *   func_021A8E20  0x021A8E20  thumb  ov021
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_021A0FB4  0x021A0FB4  thumb
 *   func_021A926C  0x021A926C  thumb  ov021
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_02040618  0x02040618  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021A12D4  0x021A12D4  thumb  ov021
 *   func_021A9294  0x021A9294  thumb  ov021
 *   func_021A87A8  0x021A87A8  thumb  ov021
 *   func_020221A4  0x020221A4  thumb
 *   func_021A8EEC  0x021A8EEC  thumb  ov021
 *   func_021A8FFC  0x021A8FFC  thumb  ov021
 *   func_0204B98C  0x0204B98C  arm
 *   func_021A9080  0x021A9080  thumb  ov021
 *   func_0204B878  0x0204B878  arm
 *   func_021A0FA0  0x021A0FA0  thumb  ov021
 *   func_0201C4E4  0x0201C4E4  thumb
 */
#include "../../matched/include/Obj18069.h"
#include "../../matched/include/Obj18070.h"

struct Evt;
struct Obj;
struct Src;
struct Desc;
struct BigObj;
struct Obj00020;
struct VecFx32;
struct W;
struct Ctx;
struct Rec44;
struct Bank;
struct Node;
struct PrintSys;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Args_021A7CE8 {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
} Args_021A7CE8;

typedef struct Work_021A7CE8 {
    Args_021A7CE8 *f00;
    void *f04;
    void *f08;
    u8 f0C[0x18 - 0x0C];
    u16 f18;
} Work_021A7CE8;

typedef unsigned int   u32;

typedef struct Work_021A7E3C {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    int f10;
    int f14;
    u16 f18;
    u8 f1A;
    u8 pad1B[0x28 - 0x1B];
    int f28;
    u8 pad2C[0x36 - 0x2C];
    u8 f36;
    u8 pad37;
    int f38;
} Work_021A7E3C;

typedef struct Args_021A7E3C {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
} Args_021A7E3C;

typedef struct Args {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    u8 pad18[0x20 - 0x18];
    u16 f20;
    u8 pad22[0x45 - 0x22];
    u8 f45;
    u8 pad46[0x48 - 0x46];
    int f48;
} Args;

typedef struct Work {
    Args *f00;
    void *f04;
    void *f08;
    u8 f0C[0x18 - 0x0C];
    u16 f18;
    u8 pad1A[0x38 - 0x1A];
    int f38;
} Work;

typedef signed short   s16;

typedef signed char    s8;

typedef struct V {
    int x;
    int y;
    int z;
} V;

typedef signed int     s32;

typedef struct Work_021A81EC {
    u8 pad00[0x2C];
    u8 step[10];
    u8 f36;
} Work_021A81EC;

typedef struct Work_021A8200 {
    u8 pad00[0x18];
    u16 f18;
    u8 pad1A[0x36 - 0x1A];
    u8 f36;
} Work_021A8200;

typedef struct {
    int pad[3];
    int fc;
} R;

typedef struct {
    R *f0;
    int pad[6];
    int f1c[3];
    int f28;
} S_021A8140;

typedef struct {
    int pad[10];
    int f28;
} S_021A8234;

typedef struct Src {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    u8 pad10[0x3C - 0x10];
    int f3C;
    int f40;
    u8 f44;
    u8 f45;
} Src;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int pad10[10];
    int f38;
    int f3c;
    int f40;
} R_021A8324;

typedef struct {
    int pad[14];
    int f38;
} R_021A834C;

typedef struct {
    R_021A834C *f0;
} S_021A7CE8;

typedef struct Item {
    int f00;
    void *f04;
    int f08;
    void *f0C;
    void *f10;
    int f14;
    void *f18;
} Item;

typedef struct Obj {
    u16 f00;
    u16 f02;
    void *f04;
    int f08;
    int f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u16 f1C;
    u8 f1E;
    u8 f1F;
    u8 f20;
    u8 f21;
    u8 pad22[2];
    int f24;
    int f28;
    int f2C;
    int f30;
    Item items[7];
    int fF8;
    u16 fFC;
    u8 padFE[2];
    int f100;
    u8 pad104[0x124 - 0x104];
    u32 f124;
    u32 f128;
    void *f12C;
    void *f130;
    u32 f134;
} Obj;

typedef struct {
    u16 h0;
    u16 pad2;
    int f4;
    int f8;
    int pad[7];
    int f28;
} S_021A84A8;

typedef struct Obj_021A84A8 {
    u8 pad00[0x34];
    Item items[7];
    u8 padF8[0x104 - 0xF8];
    void *f104;
    void *f108;
    void *f10C;
    void *f110;
    void *f114;
    void *f118;
    void *f11C;
    void *f120;
    void *f124;
    void *f128;
    void *f12C;
    void *f130;
} Obj_021A84A8;

typedef struct Sel {
    u8 pad00[0x14];
    u8 f14;
    u8 f15;
    u8 pad16[2];
    int f18;
} Sel;

typedef struct Obj_021A8588 {
    u16 f00;
    u16 f02;
    void *f04;
    void *f08;
    int f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u16 f1C;
    u8 f1E;
    u8 f1F;
    u8 f20;
    u8 f21;
    u8 pad22[2];
    int f24;
    int f28;
    int f2C;
    int f30;
    Item items[7];
    Sel *fF8;
    s16 fFC;
    u8 padFE[2];
    int f100;
    u8 pad104[0x124 - 0x104];
    u32 f124;
    u32 f128;
    void *f12C;
    void *f130;
} Obj_021A8588;

extern void *func_02188C58(void *o);
extern unsigned int func_02188D38(u8 *p);
extern u16 func_02188C9C(u8 *p);
extern void func_02185B88(void *p, unsigned int v);
extern int func_0218F0F8(u8 *a);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_021BDCC8(char *a, int *b);
extern void func_02029D7C(void *a, void *b);
extern void *func_021618E0(void *a, void *o);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021BDD40(void *p);
extern int func_021BDD48(struct Obj *o);
extern void func_021BDD20(void *p);
extern int func_021C6E48(void *p);
extern void func_021BDD34(u8 *p);
extern int func_0218E160(u32 a);
extern void func_021BDCB8(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void *func_021BDC94(void *p);
extern int func_02162370(int a);
extern int func_021A7B10(void *a);
extern void func_02029D44(u32 a, u32 b, u16 c, u8 d);
extern void func_020061E4(u32 a);
extern void *func_02188CB4(struct Obj00020 *p);
extern u16 func_021A3050(u8 *p);
extern void func_021A3038(u8 *, struct VecFx32 *);
extern u32 func_02188CFC(u8 *p);
extern void func_021A3484(unsigned char **a, int b, s32 *c);
extern void func_0207CEE4(int a, V *b, V *c, V *d);
extern void *func_021A3074(u8 *p);
extern void func_02163E58(void *p, V *in, int *out);
extern u32 func_02188C5C(u8 *p);
extern void *func_021BB480(void *p);
extern int func_021A36C8(u8 *p, u32 k, void *buf);
extern void func_021B7D38(void *p, int *in, V *out);
extern u32 func_02188C98(u8 *p);
extern u32 func_0218DC6C(u8 *p);
extern int func_0218C7D8(void *p, int b, int c);
extern void func_0218C860(int a);
extern int func_0218C8D8(void *p);
extern void func_0218C88C(unsigned char *p, int v, int c);
extern int func_0218C990(unsigned char *p, int v);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern unsigned char *func_020120F8(const struct Ctx *p);
extern unsigned short func_02012AC8(const struct Rec44 *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern u32 func_02188C54(u8 *p);
extern u8 func_020355C4(void);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_021A8D40(void *unused, struct W *w);
extern u32 func_0201C440(void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_021A8B18(void *a, void *b, u32 c);
extern void func_021A8874(struct Obj *p, void *q, int r, u32 unused);
extern void func_021A8BB8(struct Obj *p, void *q, int r);
extern void func_02049238(void *q);
extern u32 func_02040588(unsigned char, unsigned char);
extern void func_021A90E0(struct W *w);
extern void func_021A8DD8(Obj *p);
extern u8 func_020129C4(const struct BigObj *p);
extern void func_021A8E20(struct W *w, u32 v);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021A0FB4(u32 *p, u32 a);
extern void func_021A926C(Obj_021A84A8 *p, Item *it);
extern void func_02030EAC(struct Node *n);
extern void func_0204B3B4(struct Obj_021A84A8 *p);
extern void func_0204B084(void *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_020403F4(u32 i);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020307B0(void *p);
extern void func_020409B4(u32 index);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_021A12D4(u32 *p, u32 x);
extern void func_021A9294(Obj_021A8588 *p, Item *it);
extern void func_021A87A8(Obj_021A8588 *p);
extern u32 func_020221A4(void);
extern void func_021A8EEC(Obj_021A8588 *p);
extern void func_021A8FFC(struct W *w);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021A9080(Obj_021A8588 *p, u8 a, u8 b);
extern void func_0204B878(struct Obj_021A8588 *p, u16 value);
extern void func_021A0FA0(int *p, int v);
extern u32 func_0201C4E4(struct PrintSys *ps);
int func_021A7CE8(void *task, int *state, Work_021A7CE8 *w);
void *func_021A7E3C(Args_021A7E3C *a);
void func_021A7EB4(u8 *p);
int func_021A7F38(void *task, int *state, Work *w);
int func_021A80FC(u32 a);
void func_021A810C(struct Obj00020 *p, struct VecFx32 *out);
void func_021A811C(u32 a, u32 b);
void func_021A8140(void *a, V *out);
void func_021A8198(void *a, V *out);
u8 func_021A81DC(u32 a);
u8 func_021A81EC(Work_021A81EC *w);
void func_021A8200(Work_021A8200 *w);
void func_021A8214(S_021A8140 *s);
void func_021A8234(S_021A8234 *s);
int func_021A8244(u32 a);
int func_021A8268(u32 a);
void func_021A8278(S_021A8234 *s);
void func_021A82A8(S_021A8234 *s);
void func_021A82D8(void *a, struct Src **pp);
void func_021A8324(int a, R_021A8324 **r);
int func_021A834C(S_021A7CE8 *s);
Obj *func_021A836C(u16 heap, u16 a1, int a2, void *a3, int a4);
void func_021A84A8(S_021A84A8 *s);
void func_021A84BC(Obj_021A84A8 *p);
int func_021A8588(void);
u32 func_021A85B4(Obj_021A8588 *p);
extern char d_021DDF94[];






/*
 * Step machine over the Work step table: each state either stays or loads
 * the next step (func_021A81EC) and advances the index (func_021A8200).
 * Returns 1 once the current step is 8 and the handle reports done.
 */
int func_021A7CE8(void *task, int *state, Work_021A7CE8 *w)
{
    Args_021A7CE8 *a;
    void *a04;
    void *obj;
    void *a08;
    void *w04;
    void *h;
    void *d;

    a = w->f00;
    a04 = a->f04;
    obj = a->f0C;
    a08 = a->f08;
    w04 = w->f04;
    h = func_02188C58(obj);
    d = (void *)func_02188D38(obj);
    func_02188C9C(obj);

    switch (*state) {
    case 0:
        func_02185B88(obj, 1);
        if (func_0218F0F8(h) == 0) {
            *state = func_021A81EC((Work_021A81EC *)w);
            func_021A8200((Work_021A8200 *)w);
        } else {
            func_0218F0A8(h);
            *state = 9;
        }
        break;
    case 9:
        if (func_0218F0E8(h) == 0) {
            *state = func_021A81EC((Work_021A81EC *)w);
            func_021A8200((Work_021A8200 *)w);
        }
        break;
    case 1:
        func_021BDCC8(w->f08, (int *)w->f0C);
        func_02029D7C(w04, a08);
        func_021A82D8(task, (struct Src **)w);
        *state = func_021A81EC((Work_021A81EC *)w);
        func_021A8200((Work_021A8200 *)w);
        break;
    case 2:
        func_021A8278((S_021A8234 *)w);
        *state = func_021A81EC((Work_021A81EC *)w);
        func_021A8200((Work_021A8200 *)w);
        break;
    case 3:
        if (func_021A8244((u32)w) == 1) {
            *state = func_021A81EC((Work_021A81EC *)w);
            func_021A8200((Work_021A8200 *)w);
        }
        break;
    case 4:
        func_02185B88(obj, 0);
        func_02012374(task, func_021618E0(a04, obj));
        if (func_021BDD40(w->f08) != 0 && func_021BDD48(w->f08) != 0) {
            *state = 10;
        } else {
            *state = func_021A81EC((Work_021A81EC *)w);
            func_021A8200((Work_021A8200 *)w);
        }
        break;
    case 6:
        func_021A82A8((S_021A8234 *)w);
        *state = func_021A81EC((Work_021A81EC *)w);
        func_021A8200((Work_021A8200 *)w);
        break;
    case 10:
        if (w->f18++ > 15) {
            *state = func_021A81EC((Work_021A81EC *)w);
            func_021A8200((Work_021A8200 *)w);
        }
        break;
    case 5:
        func_021BDD20(w->f08);
        *state = func_021A81EC((Work_021A81EC *)w);
        func_021A8200((Work_021A8200 *)w);
        break;
    case 7:
        if (func_021A8244((u32)w) == 1) {
            *state = func_021A81EC((Work_021A81EC *)w);
            func_021A8200((Work_021A8200 *)w);
        }
        break;
    case 8:
        break;
    }

    if (func_021A81DC((u32)w) == 8 && func_021C6E48(d) != 0) {
        func_021BDD34(w->f08);
        func_0218E160((u32)h);
        func_021BDCB8(w->f08);
        func_021A8234((S_021A8234 *)w);
        return 1;
    }
    return 0;
}






void *func_021A7E3C(Args_021A7E3C *a)
{
    void *task;
    Work_021A7E3C *w;

    task = func_020122C0(a->f04, 0, func_021A7F38, 0x3C);
    w = func_020124E8(task);
    w->f00 = a;
    w->f04 = (void *)func_02012A30(a->f08);
    w->f28 = 0;
    w->f18 = 0;
    w->f1A = func_021A80FC((u32)a->f0C);
    w->f36 = 0;
    w->f08 = func_021BDC94(a->f0C);
    w->f0C = a->f10;
    w->f10 = 0;
    w->f14 = 1;
    func_021A811C((u32)a->f0C, (u32)((u8 *)w + 0x1C));
    func_021A8214((S_021A8140 *)w);
    func_021A7EB4((u8 *)w);
    if (func_02162370((int)a->f10) != 0) {
        w->f38 = 1;
    } else {
        w->f38 = 0;
    }
    return task;
}






void func_021A7EB4(u8 *p)
{
    if (func_021A8268((u32)p) != 0) {
        p[0x2C] = 0;
        p[0x2D] = 3;
        p[0x2E] = 1;
        p[0x2F] = 2;
        p[0x30] = 5;
        p[0x31] = 6;
        p[0x32] = 7;
        p[0x33] = 8;
    } else {
        p[0x2C] = 0;
        p[0x2D] = 1;
        p[0x2E] = 2;
        p[0x2F] = 5;
        p[0x30] = 6;
        p[0x31] = 7;
        p[0x32] = 8;
    }
}






/*
 * Task callback installed by func_021A7E3C: steps through the Work step
 * table like func_021A7CE8, returning 0x21 to run again in the same frame
 * when w->f38 is set, 1 when the last step finishes, 0 otherwise.
 */
int func_021A7F38(void *task, int *state, Work *w)
{
    Args *a;
    void *a04;
    void *a08;
    void *obj;
    void *w04;
    void *d;

    a = w->f00;
    a04 = a->f04;
    a08 = a->f08;
    obj = a->f0C;
    w04 = w->f04;
    d = (void *)func_02188D38(obj);

    switch (*state) {
    case 0:
        func_021BDCC8(w->f08, (int *)w->f0C);
        *state = func_021A81EC((Work_021A81EC *)((Work_021A7CE8 *)w));
        func_021A8200((Work_021A8200 *)((Work_021A7CE8 *)w));
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 1:
        func_021BDD20(w->f08);
        *state = func_021A81EC((Work_021A81EC *)((Work_021A7CE8 *)w));
        func_021A8200((Work_021A8200 *)((Work_021A7CE8 *)w));
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 3:
        func_021A8278((S_021A8234 *)((Work_021A7CE8 *)w));
        *state = func_021A81EC((Work_021A81EC *)((Work_021A7CE8 *)w));
        func_021A8200((Work_021A8200 *)((Work_021A7CE8 *)w));
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 2:
        if (func_021C6E48(d) == 0) {
            break;
        }
        if (func_021BDD40(w->f08) != 0 && func_021BDD48(w->f08) != 0) {
            *state = 9;
        } else {
            *state = func_021A81EC((Work_021A81EC *)((Work_021A7CE8 *)w));
            func_021A8200((Work_021A8200 *)((Work_021A7CE8 *)w));
        }
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 4:
        if (func_021A8244((u32)w) == 1) {
            *state = func_021A81EC((Work_021A81EC *)((Work_021A7CE8 *)w));
            func_021A8200((Work_021A8200 *)((Work_021A7CE8 *)w));
            if (w->f38 != 0) {
                return 0x21;
            }
        }
        break;
    case 9:
        if (w->f18++ > 15) {
            *state = func_021A81EC((Work_021A81EC *)((Work_021A7CE8 *)w));
            func_021A8200((Work_021A8200 *)((Work_021A7CE8 *)w));
            if (w->f38 != 0) {
                return 0x21;
            }
        }
        break;
    case 5:
        func_021A7B10(obj);
        func_02012374(task, func_021618E0(a04, obj));
        *state = func_021A81EC((Work_021A81EC *)((Work_021A7CE8 *)w));
        func_021A8200((Work_021A8200 *)((Work_021A7CE8 *)w));
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 6:
        func_02029D44((u32)w04, (u32)a08, a->f20, a->f45);
        a->f48 = 1;
        *state = func_021A81EC((Work_021A81EC *)((Work_021A7CE8 *)w));
        func_021A8200((Work_021A8200 *)((Work_021A7CE8 *)w));
        break;
    case 7:
        if (func_021A834C((S_021A7CE8 *)w) != 0) {
            func_020061E4(0x559);
        }
        func_021A8324((int)task, (R_021A8324 * *)w);
        *state = func_021A81EC((Work_021A81EC *)((Work_021A7CE8 *)w));
        func_021A8200((Work_021A8200 *)((Work_021A7CE8 *)w));
        break;
    case 8:
        func_021BDD34(w->f08);
        func_021BDCB8(w->f08);
        func_021A8234((S_021A8234 *)((Work_021A7CE8 *)w));
        return 1;
    }
    return 0;
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A80FC(u32 a)
{
return (((u32)func_021A3050(func_02188CB4((struct Obj00020 *)a)) << 24) >> 24);
}






void func_021A810C(struct Obj00020 *p, struct VecFx32 *out)
{
    func_021A3038((u8 *)func_02188CB4(p), out);
}




void func_021A811C(u32 a, u32 b)
{
if (func_02188CFC((u8 *)a) == 1) {
    func_021A8198((void *)a, (V *)b);
    return;
}
func_021A8140((void *)a, (V *)b);
}







void func_021A8140(void *a, V *out)
{
    void *ctx;
    int k;
    V v0;
    V v1;
    V v2;
    int t;

    ctx = func_02188CB4(a);
    k = func_021A3050(ctx);
    func_021A3038(ctx, (struct VecFx32 *)&v0);
    func_021A3484(ctx, k, (s32 *)(&v1));
    func_0207CEE4(0x10000, &v1, &v0, &v2);
    func_02163E58(func_021A3074(ctx), &v2, &t);
    v2.y = t;
    *out = v2;
}







void func_021A8198(void *a, V *out)
{
    void *ctx;
    int k;
    void *h;
    V res;
    int in[2];

    ctx = func_02188CB4(a);
    k = func_021A3050(ctx);
    h = func_021BB480((void *)func_02188C5C(a));
    func_021A36C8(ctx, k, in);
    func_021B7D38(h, in, &res);
    *out = res;
}







u8 func_021A81DC(u32 a)
{
return *(u8 *)((u8 *)(((a + *(u8 *)((u8 *)((a + 54)))) + 44)));
}







/*
 * Unlabelled leaf: the Work step table entry after the current one
 * (step[f36 + 1]); func_021A81DC reads step[f36].
 */
u8 func_021A81EC(Work_021A81EC *w)
{
    return w->step[(u8)(w->f36 + 1)];
}







/*
 * Unlabelled leaf: advance the Work step index and clear its frame counter.
 */
void func_021A8200(Work_021A8200 *w)
{
    w->f36++;
    w->f18 = 0;
}







void func_021A8214(S_021A8140 *s)
{
    s->f28 = func_0218C7D8((void *)func_0218DC6C((u8 *)func_02188C98((u8 *)s->f0->fc)), 1, (int)s->f1c);
}






void func_021A8234(S_021A8234 *s)
{
    if (s->f28 != 0) {
        func_0218C860(s->f28);
    }
}






int func_021A8244(u32 a)
{
if (func_021A8268(a) == 0) {
    return 1;
}
if (func_0218C8D8((void *)(((struct Obj18069 *)((u8 *)(a)))->f28)) != 0) {
    return 1;
}
return 0;
}






int func_021A8268(u32 a)
{
if (((struct Obj18070 *)((u8 *)(a)))->f28 != 0) {
    return 1;
}
return 0;
}






void func_021A8278(S_021A8234 *s)
{
    u16 v;
    if (func_021A8268((unsigned int)s)) {
        func_0218C88C((unsigned char *)s->f28, 0, 0);
        if (func_0218C990((unsigned char *)s->f28, (int)(&v))) {
            func_020061E4(v);
        }
    }
}






void func_021A82A8(S_021A8234 *s)
{
    u16 v;
    if (func_021A8268((unsigned int)s)) {
        func_0218C88C((unsigned char *)s->f28, 1, 0);
        if (func_0218C990((unsigned char *)s->f28, (int)(&v))) {
            func_020061E4(v);
        }
    }
}






void func_021A82D8(void *a, struct Src **pp){
    Src *s;
    void *r;

    s = *pp;
    if (s->f40 != 0) {
        r = (void *)func_021BE92C(s->f04, (int)s->f0C, 3, 0, 0, s->f44, s->f45);
    } else {
        r = (void *)func_021BE92C(s->f04, (int)s->f0C, s->f3C, 0, 1, 0, 0);
    }
    func_02012374(a, r);
}





void func_021A8324(int a, R_021A8324 **r)
{
    R_021A8324 *p = *r;
    int t;
    if (p->f40 != 0) {
        t = func_021BE8D4((void *)p->f4, p->fc, 0, 0);
    } else {
        t = func_021BE8D4((void *)p->f4, p->fc, p->f38, 0);
    }
    func_02012374((struct Evt *)a, (struct Evt **)t);
}





int func_021A834C(S_021A7CE8 *s)
{
    R_021A834C *p = s->f0;
    if (func_021A8268((u32)s)) {
        return 0;
    }
    if (p->f38 != 2) {
        return 1;
    }
    return 0;
}





/*
 * 0x021DDF94 is the "field_menu.c" file-name string; 0x134 is its line.
 */
Obj *func_021A836C(u16 heap, u16 a1, int a2, void *a3, int a4)
{
    Obj *p;
    u32 x;
    u32 y;
    void *q;
    u32 r;

    p = func_02030734(heap, 0x138, 0, d_021DDF94, 0x134);
    x = (u32)func_02188C80(a3);
    y = (u32)func_020120F4((const struct Ctx *)x);
    p->f00 = heap;
    p->f02 = a1;
    p->f04 = a3;
    p->f08 = a2;
    p->f0C = 1;
    p->f1C = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)x));
    p->f14 = func_0201296C((const struct BigObj *)y);
    p->f18 = (u32)func_02012944((void *)y);
    p->f10 = func_02188C54(a3);
    p->f1E = 0;
    p->f1F = 0;
    p->f24 = p->f2C = func_020355C4() ^ 1;
    p->fF8 = 0;
    p->f130 = func_020056A0(func_021A8D40, p, 0);
    p->f12C = (void *)func_0201C440((void *)p->f00);
    p->f100 = 0;
    p->fFC = 0;
    q = func_020490F4(0x47, p->f02);
    r = func_021A8B18((void *)y, (void *)p->f14, p->f1C);
    p->f21 = r;
    func_021A8874(p, q, r, p->f10);
    func_021A8BB8(p, q, r);
    func_02049238(q);
    func_02040588(1, 1);
    if (a4 == 1) {
        p->f1E = 0;
        p->f1F = 0;
        p->f24 = 1;
        func_021A90E0((struct W *)p);
        func_021A8DD8(p);
    } else {
        func_021A8E20((struct W *)p, func_020129C4((const struct BigObj *)y));
        p->f24 = 1;
        if (p->f2C != 0) {
            func_0204B3DC((struct Obj *)p->f124, 1);
        } else {
            func_0204B3DC((struct Obj *)p->f124, 0);
        }
    }
    func_0203D34C(0, p->f02);
    return p;
}




void func_021A84A8(S_021A84A8 *s)
{
    if (s->f28 == 1) {
        func_021A0FB4((u32 *)s->f8, s->h0);
    }
}




void func_021A84BC(Obj_021A84A8 *p)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        func_021A926C(p, &p->items[i]);
    }
    func_021A84A8((S_021A84A8 *)p);
    func_02030EAC(p->f130);
    func_0204B3B4(p->f128);
    func_0204B3B4(p->f124);
    func_0204B084(p->f120);
    func_0204B1CC(p->f11C);
    func_0204AFD8((u32)p->f10C);
    func_0204A8D4((u32)p->f108);
    func_0204ADA4((u32)p->f104);
    func_0204AFD8((u32)p->f118);
    func_0204A8D4((u32)p->f114);
    func_0204ADA4((u32)p->f110);
    func_02040618(6, 3, 0);
    func_020403F4(7);
    func_020403F4(5);
    func_020403F4(6);
    func_0201C6EC(p->f12C);
    func_0201C4C0(p->f12C);
    func_020307B0(p);
}




int func_021A8588(void)
{
func_020409B4(6);
func_02040588(4, 1);
func_02040588(5, 1);
func_02040588(6, 1);
return func_02040588(7, 1);
}




u32 func_021A85B4(Obj_021A8588 *p)
{
    u8 i;
    s16 v;
    Sel *s;

    switch (p->f0C) {
    case 1:
        if (func_0201C6B4(p->f12C) == 1) {
            func_021A12D4(p->f08, p->f02);
            for (i = 0; i < 7; i++) {
                func_021A9294(p, &p->items[i]);
            }
            if (p->fFC != 0) {
                func_020061E4(0x554);
                p->f0C = 0;
            } else {
                p->f0C = 2;
                func_021A8588();
            }
        }
        break;
    case 0:
        v = p->fFC;
        if (v < 0x40) {
            p->fFC = 0;
            p->f0C = 3;
            func_021A8588();
        } else {
            p->fFC = v - 0x40;
            func_021A87A8(p);
        }
        p->f100 = 1;
        break;
    case 2:
        if (func_020221A4() == 1) {
            func_021A12D4(p->f08, p->f02);
            p->f0C = 3;
        }
        break;
    case 3:
        func_021A8EEC(p);
        func_021A8FFC((struct W *)p);
        func_021A90E0((struct W *)p);
        break;
    case 4:
        if (func_0204B98C((struct Actor *)p->f128) != 0) {
            break;
        }
        p->f0C = 5;
        func_02040588(5, 1);
        func_02040588(6, 1);
        func_02040588(7, 1);
        func_02040588(4, 1);
        break;
    case 5:
        if (p->f28 == 1 || p->f1F == 3) {
            p->f0C = 9;
            func_020061E4(0x556);
            func_02040588(4, 0);
            func_02040588(5, 1);
            func_02040588(6, 1);
            func_02040588(7, 1);
            func_0204B3DC((struct Obj *)((struct Obj_021A8588 *)p->f128), 0);
        } else {
            s = p->fF8;
            if (s->f18 != 0) {
                p->f20 = 0;
                func_021A9080(p, s->f14, s->f15);
                func_0204B878((struct Obj_021A8588 *)p->f124, 1);
                func_0204B3DC((struct Obj *)((struct Obj_021A8588 *)p->f124), 1);
                p->f0C = 6;
                func_020061E4(0x54C);
            } else {
                p->f0C = 8;
            }
        }
        break;
    case 6:
        p->f20++;
        if (func_0204B98C((struct Actor *)p->f124) == 0) {
            p->f0C = 8;
        }
        break;
    case 7:
        func_021A0FA0(p->f08, 4);
        p->f0C = 10;
        break;
    case 8:
        func_021A0FA0(p->f08, 3);
        p->f0C = 10;
        break;
    case 9:
        if (p->fFC + 0x40 > 0xC0) {
            p->fFC = 0xC0;
            p->f0C = 7;
        } else {
            p->fFC += 0x40;
            func_021A87A8(p);
        }
        p->f100 = 1;
        break;
    }
    return func_0201C4E4(p->f12C);
}
