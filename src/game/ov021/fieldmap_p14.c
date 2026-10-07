/*
 * file:     fieldmap_p14.c
 * unit:     yes
 * function: func_02189A38, func_02189A48, func_02189A50, func_02189A58, func_02189A60, func_02189A68, func_02189A70, func_02189A78, func_02189A80, func_02189ACC, func_02189AE8, func_02189B04, func_02189B28, func_02189B30, func_02189BA8
 * address:  0x02189A38
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
 *   func_02012984  0x02012984  thumb
 *   func_020113D8  0x020113D8  thumb
 *   func_0218ED3C  0x0218ED3C  thumb  ov021
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_02013BA8  0x02013BA8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02013B50  0x02013B50  thumb
 *   func_02159BF4  0x02159BF4  thumb  ov010
 *   func_02159BF8  0x02159BF8  thumb  ov010
 *   func_02159BFC  0x02159BFC  thumb  ov010
 *   func_02159C20  0x02159C20  thumb  ov010
 *   func_020140BC  0x020140BC  thumb
 *   func_020140C0  0x020140C0  thumb
 *   func_020140CC  0x020140CC  thumb
 *   d_021D3700     0x021D3700  data  a4
 *   d_021D373C     0x021D373C  data  a4
 */
#include "../../matched/include/Obj17890.h"
#include "../../matched/include/Obj19506.h"
#include "../../matched/include/Obj19507.h"
#include "../../matched/include/Obj17891.h"
#include "../../matched/include/Obj17892.h"
#include "../../matched/include/Obj19508.h"
#include "../../matched/include/Obj03106.h"
#include "../../matched/include/G__anon_Ent.h"

struct BigObj;
struct Obj;
struct Sub020140BCObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Rec { int w[15]; } Rec;

typedef struct Ent { Rec r; int f3c; int f40; int f44; } Ent;

extern u32 func_020113D8(u32);
extern u8 func_02012984(const struct BigObj *p);
extern u8 *func_0218ED3C(u8 *p);
extern u8 func_02013BA8(u32 id);
extern u32 func_02013CE0(u32 id);
extern u32 func_02013B50(u32 id);
extern unsigned short func_02159BF4(struct Obj *p);
extern unsigned short func_02159BF8(struct Obj *p);
extern int func_02159BFC(struct Obj *p);
extern char *func_02159C20(char *p);
extern u16 func_020140BC(struct Sub020140BCObj *p);
extern u32 func_020140C0(struct Sub020140BCObj *p);
extern u32 func_020140CC(struct Sub020140BCObj *p);
int func_02189A38(int a);
int func_02189A48(char *p);
void func_02189A50(char *p, int v);
void func_02189A58(u8 *p, u32 v);
u8 *func_02189A60(u8 *p);
void func_02189A68(char *a, int b);
u32 func_02189A70(u8 *p);
u32 func_02189A78(u8 *p);
int func_02189A80(char *p);
int func_02189ACC(u32 a0);
int func_02189AE8(int a);
int func_02189B04(int x);
u32 func_02189B28(u32 id);
void func_02189B30(int a, int x, char *out, void *obj);
int func_02189BA8(int x);
extern short d_020A1B38[];
extern Ent d_021D3700[];
extern struct _anon_Ent d_021D373C[];


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02189A38(int a)
{
return func_020113D8(func_02012984((const struct BigObj *)(((struct Obj17890 *)((u8 *)(a)))->f8)));
}

int func_02189A48(char *p)
{
    return *(unsigned int *)(p + 0x144);
}

/*
 * Unlabelled leaf (saves no lr): stores r1 at +0x144.  Callee of ov020
 * func_02187CEC and func_02187CFC.
 */
void func_02189A50(char *p, int v)
{
    *(int *)(p + 0x144) = v;
}


/*
 * Unlabelled leaf setter, called from func_021BEF8C.
 */
void func_02189A58(u8 *p, u32 v)
{
    ((struct Obj19506 *)p)->f140 = v;
}


/*
 * Addresses are Black-image addresses.
 */
u8 *func_02189A60(u8 *p)
{
    return p + 0x148;
}


void func_02189A68(char *a, int b)
{
    ((struct Obj19507 *)a)->f150 = b;
}


/*
 * Loads the 32-bit word at byte +0x150 of the object.
 */
u32 func_02189A70(u8 *p)
{
    return ((struct Obj17891 *)p)->f150;
}


/*
 * Loads the 32-bit word at byte +0x100 of the object.
 */
u32 func_02189A78(u8 *p)
{
    return ((struct Obj17892 *)p)->f100;
}


int func_02189A80(char *p)
{
    unsigned short *q = (short unsigned int *)func_0218ED3C(((struct Obj19508 *)p)->f10);
    int i = (*q >> 4) * 2 + 1;
    int s = d_020A1B38[i];
    long long v;
    int r;

    if (s < 0)
        s = -s;
    v = ((long long)s << 14) + 0x800;
    r = (int)(v >> 12) - 0x4000;
    if (r < -0x2000)
        r = -0x2000;
    return r;
}


/*
 * Leaf: returns one of two pooled constants (0x1EE / 0x136) depending on
 * func_02013BA8() == 1.  Callee of func_021881D8 (assigns p->x104).
 */
int func_02189ACC(u32 a0)
{
    if (func_02013BA8(a0) == 1)
        return 0x1EE;
    return 0x136;
}


/*
 * Leaf: 0 for id 0x3f, else 0 when func_02013CE0() reports 1, else 1.
 * Callee of func_02189204.  EXACT* because the unlabelled follower
 * (0x02189B04) has no seed; no byte differs.
 */
int func_02189AE8(int a)
{
    if (a == 0x3f)
        return 0;
    if (func_02013CE0(a) == 1)
        return 0;
    return 1;
}

int func_02189B04(int x)
{
    if (x == 0x3F)
        return 1;
    if (x == 0x8C)
        return 1;
    if (x == 0x8D)
        return 1;
    if (x == 0x8E)
        return 1;
    return 0;
}


/*
 * Tail-call thunk: forwards to func_02013B50 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02189B28(u32 id)
{
    return func_02013B50(id);
}


void func_02189B30(int a, int x, char *out, void *obj)
{
    int i = (int)func_02189B28((unsigned int)a);

    *(Rec *)out = d_021D3700[i].r;
    if (d_021D3700[i].f40 != 0) {
        ((struct Obj03106 *)out)->f14 = func_02159BF4(obj);
        ((struct Obj03106 *)out)->f16 = func_02159BF8(obj);
        ((struct Obj03106 *)out)->f18 = func_02159BFC(obj);
        ((struct Obj03106 *)out)->f1C = (int)func_02159C20(obj);
    }
    ((struct Obj03106 *)out)->f20 = 1;
    ((struct Obj03106 *)out)->f24 = 0xe;
    ((struct Obj03106 *)out)->f28 = func_020140BC((struct Sub020140BCObj *)x);
    ((struct Obj03106 *)out)->f2C = func_020140C0((struct Sub020140BCObj *)x);
    ((struct Obj03106 *)out)->f30 = func_020140CC((struct Sub020140BCObj *)x);
}


int func_02189BA8(int x)
{
    return d_021D373C[(int)func_02189B28((unsigned int)x)].f0;
}
