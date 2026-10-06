/*
 * file:     particle_p05.c
 * unit:     yes
 * function: func_020506B8, func_02050738, func_02050790, func_020507A0, func_020507D0, func_020507F0, func_02050804, func_0205082C, func_02050848, func_0205085C, func_02050880, func_02050894, func_020508C4, func_020508D8, func_020508EC, func_02050920
 * address:  0x020506B8
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
 *   func_020473D8  0x020473D8  arm
 *   func_0204F2B4  0x0204F2B4  arm
 *   func_0204F344  0x0204F344  arm
 *   func_020473EC   0x020473EC  arm
 *   func_0204F2CC   0x0204F2CC  arm
 *   DWCi_LSTlErase 0x0204F7DC arm
 */
#include "../../matched/include/Obj06992.h"
#include "../../matched/include/Obj11453.h"
#include "../../matched/include/Obj11454.h"
#include "../../matched/include/Obj16154.h"
#include "../../matched/include/Obj16155.h"
#include "../../matched/include/Obj02611.h"
#include "../../matched/include/Obj16156.h"
#include "../../matched/include/Obj16157.h"
#include "../../matched/include/Obj11455.h"
#include "../../matched/include/Obj16158.h"
#include "../../matched/include/Obj11456.h"
#include "../../matched/include/Obj16160.h"
#include "../../matched/include/Obj16161.h"

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct Owner {
    u32 f00;
    u32 f04;
    void (*f08)(u32 a0, u32 a1, u32 a2, u32 a3);
} Owner;

typedef struct Entry {
    u16 f00;
    u16 f02;
    u32 f04;
} Entry;

typedef unsigned char  u8;

typedef struct tagLISTCB {
    void *head;
    void *tail;
} LISTCB;

typedef struct { int f0; char pad[0x24]; } E28_020507D0;

typedef struct { int pad0; int f4; char pad[0x10]; E28_020507D0 *f18; } Mgr_020507D0;

struct S8 {
    u16 h;
    u16 pad;
    u32 w;
};

struct S40 {
    u32 f0;
    u16 f4;
    u16 f6;
    u32 f8;
    u32 f12;
    u32 f16;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f32;
    u32 f36;
};

typedef struct { int f0; char pad[0x24]; } E28_020508C4;

typedef struct { char pad[0x18]; E28_020508C4 *f18; } Mgr_020508C4;

struct S14 {
    u16 f : 14;
};

extern int func_020473D8(int a0);
extern void func_0204F2B4(int p0, int p1, int p2);
extern void func_0204F344(void *a0, u32 a1, int a2, int *out, int *in, u8 flag);
extern int func_020473EC(int a0);
extern u32 func_0204F2CC(u32 a, u16 b, u32 *out);
extern void DWCi_LSTlErase(void *ob);
extern int func_0204F720(u32 a, u32 b, void *buf);
extern u32 func_0204F704(u8 *a0, int i);
extern void func_020500A0(int p0);
extern int func_02050984(int a);
void func_020506B8(Owner *o, Entry *e, u32 a2);
u32 func_02050738(void *p, void *q);
void func_02050790(LISTCB *list, int b, int c);
int func_020507A0(void *p, int idx, u32 x);
int func_020507D0(Mgr_020507D0 *p, int i);
void func_020507F0(void *p, int idx, u32 v);
void func_02050804(void *p, int idx, u32 v, u16 h);
void func_0205082C(void *p, int idx, u32 h);
u16 func_02050848(u8 *p, int i);
void func_0205085C(void *p, int idx, u32 v);
u16 func_02050880(u8 *p, int i);
int func_02050894(void *p, int idx, int j);
int func_020508C4(Mgr_020508C4 *p, int i);
u32 func_020508D8(u8 *o, u32 i);
u32 func_020508EC(u8 *p, int i, u16 *out);


void func_020506B8(Owner *o, Entry *e, u32 a2)
{
    u32 s4;
    u32 s3;
    u32 s2;
    u32 base;
    u32 zero;

    base = func_020473D8(e->f04);
    func_0204F2B4(o->f04, e->f00, (int)(&s4));
    zero = 0;
    func_0204F344((void *)o->f04, e->f00, a2, (int *)(&s3), (int *)(&s2), zero);
    if (o->f08 != 0) {
        o->f08(zero, s4, base + s3, s2);
    }
}


/*
 * An 88-byte ARM function in the 0x02050000 block.  It reads a record index
 * out of the object at +4, resolves it through func_020473EC, then calls
 * func_0204F2CC with the object's word at +4, the halfword at q[0] and a
 * stack scratch slot; when the hook pointer at p+8 is non-null it calls the
 * hook with the scratch value and the resolved record.  The null case returns
 * the func_0204F2CC result, which is why the `cmp ip, #0` sits after the
 * second call with r0 still live.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050738.c \
 *       --func func_02050738 --addr 0x02050738 --cc 1.1p1 --arm
 */
u32 func_02050738(void *p, void *q)
{
    u32 v = func_020473EC(((struct Obj06992 *)q)->f4);
    u32 t;
    u32 r = func_0204F2CC(((struct Obj11453 *)p)->f4, ((struct Obj06992 *)q)->f0, &t);
    u32 (*hook)(u32, u32, u32, u32) = *(u32 (**)(u32, u32, u32, u32))((char *)p + 8);

    if (hook == 0)
        return r;
    return hook(1, t, v, 0x20);
}


/*
 * sdk:      DWCi_LSTlPopFront (libdwcutil.TWL.HYB.a list.o)
 */
void func_02050790(LISTCB *list, int b, int c)
{
    DWCi_LSTlErase(list->tail);
}


/*
 * The listing labels this function at 0x020507A4, not 0x020507A0: disasm.py
 * only auto-labels a prologue that saves lr, so the four bytes at 0x020507A0
 * that home the four argument registers (`push {r0,r1,r2,r3}`, the tell for
 * an address-taken register parameter,
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md) are
 * printed as a stray `.word` and the label lands on the `push {r3, lr}` four
 * bytes later.  The real entry is 0x020507A0 and the function is 48 bytes,
 * not the worklist's 44; verified from 0x020507A0, where the extent runs to
 * the next label at 0x020507D0.
 *
 * The third parameter is not a pointer but a scalar whose address is taken
 * (`&x`, compiled as the home slot).  Written as `u8 *buf` it compiles to 32
 * bytes; as `u8 buf[16]`, 32; only `&x` on a scalar reproduces the home push.
 *
 * Reads element `idx` of a 40-byte record array hanging off p+24 and hands it,
 * together with p's own word at +4 and the caller's buffer address, to
 * func_0204F720.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020507A0.c \
 *       --func func_020507A0 --addr 0x020507A0 --cc 1.1p1 --arm
 */
int func_020507A0(void *p, int idx, u32 x)
{
    return func_0204F720(((struct Obj11454 *)p)->f4,
                         *(u32 *)(((struct Obj11454 *)p)->f18 + idx * 40),
                         &x);
}


/*
 * Leaf witness for ov021 0x021BBF10 / 0x021BC138 (lane wA1-12).
 */
int func_020507D0(Mgr_020507D0 *p, int i)
{
    return func_0204F704((u8 *)p->f4, p->f18[i].f0);
}


void func_020507F0(void *p, int idx, u32 v)
{
    char *e = (char *)(((struct Obj16154 *)p)->f18 + idx * 40);
    ((struct Obj16155 *)e)->f18 = v;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050804.c \
 *       --func func_02050804 --addr 0x02050804 --cc 1.1p1 --arm
 */
void func_02050804(void *p, int idx, u32 v, u16 h)
{
    char *e = (char *)(((struct Obj16156 *)p)->f18 + idx * 40);

    ((struct Obj02611 *)e)->f8 = v;
    ((struct Obj02611 *)e)->fC = h;
    ((struct Obj02611 *)e)->fE = 0;
    func_020500A0((int)e);
}


void func_0205082C(void *p, int idx, u32 h)
{
    char *e = (char *)(((struct Obj16157 *)p)->f18 + idx * 40);
    ((struct Obj02611 *)e)->fE = h;
    func_020500A0((int)e);
}


/*
 * Leaf witness for ov021 0x0219F058 and siblings (lane wA1-06).
 */
u16 func_02050848(u8 *p, int i)
{
    return *(u16 *)(*(u8 * *)&((struct Obj11455 *)p)->f18 + i * 40 + 0xe);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0205085C.c \
 *       --func func_0205085C --addr 0x0205085C --cc 1.1p1 --arm
 */
void func_0205085C(void *p, int idx, u32 v)
{
    char *e = (char *)(((struct Obj16158 *)p)->f18 + idx * 40);

    func_020500A0((int)e);
    ((struct Obj02611 *)e)->f10 = v;
}


/*
 * Leaf witness for ov021 0x0219F058 and siblings (lane wA1-06).
 */
u16 func_02050880(u8 *p, int i)
{
    return *(u16 *)(*(u8 * *)&((struct Obj11455 *)p)->f18 + i * 40 + 0x10);
}


/*
 * PROMOTED from src/pending/func_02050894.c: it was parked at MATCH because
 * the only branch in the image to 0x02050738 is the one inside this function.
 * 0x02050738 (88 bytes, pkt_02050340) is now matched, so the site resolves by
 * the `matched` class with no change to the C.  The file's packet id is
 * corrected from pkt_02050340 to pkt_02050894, which is the packet the
 * worklist gives 0x02050894.
 *
 * Moves one word between two parallel record arrays of the object: the index
 * is read out of the 40-byte record table at p+24, the value out of the
 * 8-byte-pair array at p+12, the value is stored back into the record the
 * index names, and the record is handed to func_02050738.
 *
 * The listing's extent runs 140 bytes because the follower at 0x020508C4 is an
 * unlabelled leaf accessor (no prologue that saves lr).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050894.c \
 *       --func func_02050894 --addr 0x02050894 --cc 1.1p1 --arm
 */
int func_02050894(void *p, int idx, int j)
{
    struct S8  *arr = *(struct S8 * *)&((struct Obj11456 *)p)->fC;
    struct S40 *rec = *(struct S40 * *)&((struct Obj11456 *)p)->f18;
    u16 e = rec[idx].f4;
    u32 v = arr[j].w;

    arr[e].w = v;
    return func_02050738(p, &arr[e]);
}


/*
 * Leaf witness for ov021 0x021BBF10 / 0x021BC138 (lane wA1-12).
 */
int func_020508C4(Mgr_020508C4 *p, int i)
{
    return p->f18[i].f0;
}


u32 func_020508D8(u8 *o, u32 i)
{
    return *(u16 *)(*(u8 * *)&((struct Obj16160 *)o)->f18 + i * 0x28 + 4);
}


u32 func_020508EC(u8 *p, int i, u16 *out)
{
    u16 v = *(u16 *)(*(u8 * *)&((struct Obj16161 *)p)->f18 + i * 40 + 0x1c);
    *out = v;
    return (u16)(v + 4 + 0xC000) <= 3;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050920.c \
 *       --func func_02050920 --addr 0x02050920 --cc 1.1p1 --arm
 */
int func_02050920(struct S14 *p)
{
    return func_02050984(p->f) != 0;
}
