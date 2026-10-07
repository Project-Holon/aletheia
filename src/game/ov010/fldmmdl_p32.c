/*
 * file:     fldmmdl_p32.c
 * unit:     yes
 * function: func_0216DEE0, func_0216DEEC, func_0216DF1C, func_0216DF64, func_0216DFAC, func_0216DFC4, func_0216E014, func_0216E084
 * address:  0x0216DEE0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_02030DA8  0x02030DA8  arm
 *   func_0216D4F4  0x0216D4F4  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D514  0x0216D514  thumb  ov010
 *   func_0216D3A8  0x0216D3A8  thumb  ov010
 *   func_02030EAC  0x02030EAC  arm
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D5D8  0x0216D5D8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 */
#include "../../matched/include/Obj17852.h"
#include "../../matched/include/Obj19133.h"
#include "../../matched/include/Obj00113.h"

struct Ctx;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

extern void *func_0216DE94(void *, unsigned);
extern u16 func_0216D4F0(void *p);
extern int func_0216D55C(int a0, int a1);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern u16 func_0216D588(void *p);
extern void func_0216CF2C(u8 *o);
extern u16 func_0216D4F4(void *p);
extern u16 func_0216D5A0(void *p);
extern u32 func_0216D514(void *p);
extern void func_0216D3A8(u32 a, u32 b);
extern int func_02030DA8(int owner, int fn, int arg, int n);
extern int func_02030EAC();
extern void *func_0216D67C(void *a);
extern u16 func_0216D598(void *p);
extern void func_0216D844(void *p, s16 v);
extern void func_0216D85C(void *p, int v);
extern void func_0216D874(int a0, int a1);
extern void func_0216D89C(void *p, const void *q);
extern int func_02163F10(int a0);
extern int func_0216D5D8(int a0, int a1);
extern void *func_0216D4B4(char *p);
extern void *func_0216D568(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
void *func_0216DEE0(void *a0);
int func_0216DEEC(int a0);
void func_0216DF1C(u32 x);
void func_0216DF64(u8 *o, u32 b);
int func_0216DFAC(int a0);
int func_0216DFC4(void *a, u32 id);
void func_0216E014(void *a, int *p, int b);
void func_0216E084(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k);


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216DE94, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DEE0.c \
 *       --func func_0216DEE0 --addr 0x0216DEE0 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216DEE0(void *a0)
{
    return func_0216DE94(a0, 255);
}


int func_0216DEEC(int a0)
{
    int a1;
    int t4;
    int t5;
    int t6;
    int t7;

t5 = a0 + 0;
t4 = 0;
    a0 = func_0216D4F0((void *)a0);
loc_0216DEF6:
t7 = 1;
t5 = ((struct Obj17852 *)t5)->f18;
t6 = a0 + 0;
t7 = t7 << 8;
loc_0216DEFE:
a0 = t5 + 0;
a1 = 1;
    a0 = func_0216D55C(a0, a1);
loc_0216DF06:
    if (a0 != 0) goto loc_0216DF0E;
loc_0216DF0A:
a0 = t5 + 0;
    return a0;
loc_0216DF0E:
t4 = t4 + 1;
t5 = t5 + t7;
    if (t4 < t6) goto loc_0216DEFE;
loc_0216DF16:
a0 = 0;
    return a0;}


void func_0216DF1C(u32 x)
{
    int n;
    u8 *o;
    u32 k = 0x20;

    n = 0;
    while (func_0216DD1C((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n))) {
        if (func_0216D55C((int)o, k) == 0) {
            func_0216D588(o);
            func_0216CF2C(o);
        }
    }
}


void func_0216DF64(u8 *o, u32 b)
{
    int d = 0;
    int base = func_0216D4F4((void *)b);
    int t = func_0216D5A0(o);

    if (t == 0x30 || t == 0x32)
        d = 1;
    else if (func_0216D588(o) == 0xff)
        d--;
    ((struct Obj19133 *)o)->f84 = func_02030DA8(func_0216D514((void *)b), (int)func_0216D3A8, (int)o, base + d);
}


int func_0216DFAC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = a0 + 0x84;
a0 = *(int *)&((struct Obj00113 *)((char *)a0))->f0;
    if (a0 == 0) goto loc_0216DFC2;
loc_0216DFB8:
    a0 = func_02030EAC(a0);
loc_0216DFBC:
a0 = 0;
t4 = t4 + 0x84;
*(int *)&((struct Obj00113 *)((char *)t4))->f0 = a0;
loc_0216DFC2:
    return a0;}


int func_0216DFC4(void *a, u32 id)
{
    u32 iter = 0;
    void *out;
    void *ctx;

    ctx = func_0216D67C(a);
    while (func_0216DD1C(ctx, (struct Rec **)(&out), &iter) == 1) {
        if (out != a) {
            u32 v = func_0216D598(out);
            if (v != 0xFFFF && v == id)
                return 1;
        }
    }
    return 0;
}


void func_0216E014(void *a, int *p, int b)
{
    func_0216D844(a, (s16)((p[0] >> 4) / 4096));
    func_0216D85C(a, (s16)((p[1] >> 4) / 4096));
    func_0216D874((int)a, (s16)((p[2] >> 4) / 4096));
    func_0216D89C(a, p);
    func_02163F10((int)a);
    func_0216D5D8((int)a, b);
    func_0216D4B4(a);
    func_0216D568(a, 0x20);
    func_0216D570(a, 0x50);
}

void func_0216E084(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k) { int p[3]; p[0]=(x<<16)+0x8000; p[1]=y<<16; p[2]=(z<<16)+0x8000; func_0216E014(a,p,k); }
