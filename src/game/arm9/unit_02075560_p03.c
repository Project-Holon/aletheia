/*
 * file:     unit_02075560_p03.c
 * unit:     yes
 * function: func_02075994, func_02075A2C, func_02075A94, func_02075AB8, func_02075B28, func_02075B54, func_02075B94
 * address:  0x02075994
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
 *   g_02150178  0x02150178  data
 *   g_0214EA90  0x0214EA90  data
 *   g_02150190  0x02150190  data
 *   func_02073898  0x02073898  arm
 *   func_02087988 0x02087988  arm
 *   func_0208799C 0x0208799C  arm
 *   func_02060614 0x02060614  arm
 *   func_020605B4 0x020605B4  arm
 *   func_020604AC 0x020604AC  arm
 */
#include "../../matched/include/Obj16688.h"

struct Obj;
struct SndObj2;
struct X;
struct DList;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef signed int    s32;

struct Obj75994 {
    u8  pad_00[0x118];
    s32 b0 : 1;
    s32 b1 : 1;
    s32 rest : 30;
    u8  pad_11c[0x5c];
    u32 cb;
};

struct Obj {
    u8 pad000[0x118];
    s32 b0:1;
    s32 rest:31;
    u8 pad11C[0x54];
    void (*f170)(u8 *o);
};

struct SndObj2 {
    char pad[0x128];
    int ref_count;
};

typedef unsigned short u16;

struct LerpObj {
    int start;
    int target;
    int step;
    int duration;
};

struct Entry { u32 f0; u32 f4; u32 f8; };   /* 0xC bytes each */

struct Table { u8 pad00[0x1c]; u32 count; struct Entry arr[]; };

extern void func_02086028(void *p);
extern void func_02086078(void *p);
extern void func_02073AB4(struct Obj75994 *o);
extern void func_02075968(u8 *o);
extern void func_02073898(struct X *x);
extern void func_020604AC(void *list, void *object);
extern u32  func_02087988(void);
extern void func_0208799C(u32);
extern void *func_02060614(struct DList *list, void *elem);
extern void func_020605B4(volatile struct DList *list, void *elem);
void func_02075994(struct Obj75994 *o);
void func_02075A2C(struct Obj *o);
void func_02075A94(struct SndObj2 *obj);
void func_02075AB8(void *a, u32 v);
void func_02075B28(void *p);
struct Entry *func_02075B54(struct Table *t, int idx);
void func_02075B94(struct LerpObj *obj);
extern u8  g_02150178[];
extern u8  g_0214EA90[];
extern u8  g_02150190[];




/*
 * Symbols:
 *   g_02150178  0x02150178  data
 *   g_0214EA90  0x0214EA90  data
 *
 * Two relocation sites stay wildcarded, neither for want of C:
 *   +0064  bl func_02075A2C   `label`: 0x02075A2C's only branch image-wide is
 *                             this function's own call (asm, single caller).
 *                             It is inside THIS packet; the callee is parked
 *                             (byte-correct MATCH, its own `bl 0x02075968`
 *                             site has the same defect), so filing it does not
 *                             attest this site either.
 *   +0090  ABS32 g_02150178   `literal`: the only pool word naming 0x02150178
 *                             anywhere in the image, so own-pool-only.
 * The remaining six sites resolve (`label` x20/x20/x5/x20/x20, `literal` x5).
 * Spelled with the two bitfields at +0x118 as signed 1-bit fields; an
 * unsigned field emits `lsrs r0, r0, #0x1f` where the image has `asrs`, a
 * concrete two-byte diff.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02075994.c \
 *       --func func_02075994 --addr 0x02075994 --arm --cc 1.1p1
 */
void func_02075994(struct Obj75994 *o)
{
    u8 *p;

    func_02086028(g_02150178);
    p = *(u8 **)(g_0214EA90 + 4);
    if (p != 0)
        func_02086028(p + 0x10c8);
    if (o->b1 != 0)
        func_02073AB4(o);
    if (o->b0 != 0)
        ((void (*)(struct Obj75994 *))o->cb)(o);
    func_02075A2C((struct Obj *)o);
    func_02086078(g_02150178);
    p = *(u8 **)(g_0214EA90 + 4);
    if (p == 0)
        return;
    func_02086078(p + 0x10c8);
}



/*
 *           branch anywhere in the image outside 02075A2C..02075A94, so
 *           `label` refuses it - and 0x02075968 is itself only 8 bytes from
 *           EXACT (two BIC destinations), see docs/notes/pkt_02075794.c.txt.
 *           (2) ABS32 g_02150190: the data address is named by exactly one
 *           pool word in the image, this function's own, so `literal` has no
 *           second occurrence either.  The other four sites resolve
 *           (func_02075A94 and func_02075AB8 as `matched`, g_0214EA90 as
 *           `literal x5`).  The body is byte-correct.
 */
void func_02075A2C(struct Obj *o)
{
    u8 *p;

    if (o->b0 == 0) return;
    func_02075A94((struct SndObj2 *)o);
    o->f170((u8 *)o);
    func_02075AB8(g_02150190, (u32)((u8 *)o));
    p = *(u8 **)(g_0214EA90 + 4);
    if (p != 0) func_02075AB8(p + 0x10e0, (u32)((u8 *)o));
    func_02075968((u8 *)o);
}



void func_02075A94(struct SndObj2 *obj)
{
    if (obj->ref_count != 0) {
        if (--obj->ref_count == 0) {
            func_02073898((struct X *)obj);
        }
    }
}



/*
 * The unlink walk holds the interrupt state in the lowest callee-saved
 * register and the next link in r6, so the state survives the two calls in
 * the body; declaring `n` inside the loop (rather than hoisting it) is what
 * keeps r6 out of the prologue's push.
 */
void func_02075AB8(void *a, u32 v)
{
    u32 state = func_02087988();
    void *p = func_02060614(a, 0);

    while (p != 0) {
        void *n = func_02060614(a, p);

        if (((struct Obj16688 *)p)->f8 == v) {
            func_020605B4(a, p);
            func_02075B28(p);
        }
        p = n;
    }
    func_0208799C(state);
}


void func_02075B28(void *p)
{
    u32 state = func_02087988();
    func_020604AC(g_0214EA90 + 0xc, p);
    func_0208799C(state);
}


/*
 * Signed compare against zero for the negative index (`movlt`/`bxlt`) but an
 *  * unsigned `>=` for the bound (`movhs`/`bxhs`), which is what an `int` index
 *  * compared against a `u32` count gives; the -1 element test is the
 *  * R_ARM_ABS32-free third guard the tail ends on. No relocations at all.
 */
struct Entry *func_02075B54(struct Table *t, int idx)
{
    struct Entry *e;

    if (idx < 0) return 0;
    if (idx >= t->count) return 0;
    e = &t->arr[idx];
    if (e->f0 == -1) return 0;
    return e;
}



void func_02075B94(struct LerpObj *obj)
{
    obj->target = 0;
    obj->start = 0;
    obj->duration = 0;
    obj->step = 0;
}
