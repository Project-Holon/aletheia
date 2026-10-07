/*
 * file:     unit_021766A8.c
 * unit:     yes
 * function: func_021766A8, func_021766CC, func_021766F0, func_021767A0, func_021767F0, func_02176850, func_02176870, func_02176880, func_0217688C
 * address:  0x021766A8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203133C 0x0203133C arm
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02029BCC  0x02029BCC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_020144DC  0x020144DC  thumb
 *   func_02012444  0x02012444  thumb
 *   func_02029C00  0x02029C00  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   d_02176FCC     0x02176FCC  data  ov011  a4
 *   func_02012B58  0x02012B58  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012B80  0x02012B80  thumb
 *   d_02176FD8     0x02176FD8  data  ov011  a4
 *   func_02174854 0x02174854 thumb ov011
 */
#include "../../matched/include/Obj12441.h"

struct S020314B8;
struct S020315D4;
struct Desc;
struct Obj;
struct Ctx;
struct Evt;
struct BigObj;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct {
    u8  pad[0x86];
    u16 v : 3;
} Rec_021767A0;

typedef struct {
    u8  pad[0x86];
    u16 v : 3;
    u8  pad2[0x902 - 0x88];
    u8  f902;
} Rec_021767F0;

typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
} Cs;

typedef struct { u16 value : 3; } Flag;

typedef struct { u8 value; u8 enabled; } Pair;

extern void func_0203133C(struct S020314B8 *p);
extern u32 func_020307B0(void *p);
extern void func_020315D4(struct S020315D4 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02029BCC(void *a, u32 b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int  func_02189A08(unsigned char *p);
extern void func_021CF498(struct Ctx *c, u32 x, int idx);
extern int  func_020144DC(int a, int b);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern void *func_02029C00(void *a);
extern void *func_020145CC(void *a0);
extern void *func_02029CC0(void *a);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u8 func_02012B58(const struct BigObj *p);
extern int func_02158344(int a0);
extern u32 func_0200FB24(void);
extern u8 func_02012B80(const struct BigObj *p);
extern int func_02174854(u8 *p, int key, int data);
int func_021766A8(void *p, int b, int c, u8 *q);
void *func_021766CC(void *p, void *q);
int func_021766F0(void *a, u32 *p, int *q);
u8 func_021767A0(void *a, void *b);
void func_021767F0(void *a, void *b, Cs *c);
int func_02176850(u8 *p, u8 value);
u32 func_02176870(u8 *p);
u8 *func_02176880(u8 *p);
void func_0217688C(u8 *a0, u8 a1);
extern char d_02176FCC[];
extern Cs   d_02176FD8;

/*
 * extent: two alignment bytes at 021766CA.
 */
int func_021766A8(void *p, int b, int c, u8 *q)
{
    func_0203133C(((struct Obj12441 *)q)->fF4);
    func_020307B0(((struct Obj12441 *)q)->fF8);
    func_020315D4(p);
    return 1;
}

void *func_021766CC(void *p, void *q)
{
    void *desc;
    void **buf;
    desc = func_020122C0(p, 0, func_021766F0, 8);
    buf = func_020124E8(desc);
    buf[1] = q;
    buf[0] = p;
    return desc;
}


/*
 * Lever: case 1 forwards func_0201210C's live r0 result into
 * func_02189A08(unsigned char *); the matched body reads p + 0x13C.
 */
int func_021766F0(void *a, u32 *p, int *q)
{
    int sv;

    sv = (int)func_0201210C((const struct Ctx *)q[0]);
    switch (*p) {
    case 0:
        func_02012374(a, func_02029BCC((void *)q[0], 0x490));
        (*p)++;
        break;
    case 1:
        func_021CF498((struct Ctx *)func_02189A08((unsigned char *)sv), (u32)a, 5);
        (*p)++;
        break;
    case 2:
        func_02012374(a, (struct Evt **)func_020144DC(q[0], sv));
        (*p)++;
        break;
    case 3:
        func_02012444(a, -1, (u32)d_02176FCC, q[1]);
        (*p)++;
        break;
    case 4:
        func_02012374(a, func_02029C00((void *)q[0]));
        (*p)++;
        break;
    case 5:
        func_02012374(a, func_020145CC((void *)q[0]));
        (*p)++;
        break;
    case 6:
        func_02012374(a, func_02029CC0((void *)q[0]));
        (*p)++;
        break;
    case 7:
        func_02012374(a, (struct Evt **)func_021BE92C((void *)q[0], sv, 0, 0, 1, 0, 0));
        (*p)++;
        break;
    default:
        return 1;
    }
    return 0;
}


u8 func_021767A0(void *a, void *b)
{
    u8 x;
    u8 y;
    Rec_021767A0 *r;

    x = (int)func_02012B58(b);
    r = (Rec_021767A0 *)func_02158344((int)a);
    if (func_0200FB24()) {
        y = (int)func_02012B80(b);
        if (y == x) {
            return 4;
        }
        return y;
    }
    if (r != 0) {
        if (r->v == x) {
            return 4;
        }
        return r->v;
    }
    return 4;
}


void func_021767F0(void *a, void *b, Cs *c)
{
    Rec_021767F0 *r;
    int d;

    r = (Rec_021767F0 *)func_02158344((int)a);
    if (r == 0 || r->v == func_02012B58(b)) {
        d = 0;
    } else {
        d = r->v - func_02012B58(b);
        if (d < 0) {
            d += r->f902;
        }
    }
    *c = d_02176FD8;
    c->w0 += d << 22;
}

/*
 * extent: followers 02176870 and 02176880 already filed separately.
 */
int func_02176850(u8 *p, u8 value)
{
    Pair pair;
    pair.value = value;
    pair.enabled = 1;
    return func_02174854(p, (u8)((Flag *)(p + 0x86))->value, (int)&pair);
}


/*
 * Unlabelled leaf: bit 1 of the byte at +0x8F8 of the argument.
 */
u32 func_02176870(u8 *p)
{
    return (u32)(p[0x8F8] << 30) >> 31;
}


/*
 * Unlabelled leaf: returns the address 0x82C bytes into the object.
 * Filed as the sole blocker of func_02166434 (ov010).
 */
u8 *func_02176880(u8 *p)
{
    return p + 0x82C;
}


/*
 * Recursive MATCH unblocker: callee of func_0216AF3C (ov010) at +0032. The
 * address is Thumb code in ov011 (ARM/data in the overlapping ov009), so the
 * matched shard makes that site attest as `matched`.
 */
void func_0217688C(u8 *a0, u8 a1)
{
    a0[0x8E0] = a1;
    a0[0x8E1] = 1;
}
