/*
 * file:     iss_city_sys_p02.c
 * unit:     yes
 * function: func_0202AB5C, func_0202AB64, func_0202AB7C, func_0202AB84, func_0202AB8C, func_0202ABD0, func_0202ABF8, func_0202ABFC, func_0202AC00
 * address:  0x0202AB5C
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
 *   func_0202AC60  0x0202AC60  thumb
 *   func_0202ABD0  0x0202ABD0  thumb
 *   func_02049030  0x02049030  arm
 *   func_02030734  0x02030734  arm
 *   func_0202AEEC  0x0202AEEC  thumb
 *   g_020A76E8     0x020A76E8  data
 *   func_0202AF28  0x0202AF28  thumb
 *   sub_020307B0   0x020307B0  arm
 */
#include "../../matched/include/Obj03492.h"
#include "../../matched/include/Obj17262.h"
#include "../../matched/include/Obj17263.h"
#include "../../matched/include/Obj15813.h"

struct A;
struct Node;
struct Obj;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef int s32;

struct A {
    u8  pad0[0x14];
    u32 *unk14;
    u8  unk18;
};

typedef unsigned short u16;

struct Obj {
    u8 pad[0x14];
    void **arr;
    u8 count;
};

extern void func_0202AC60(u8 *p, u32 a1);
extern void func_0202AB8C(struct A *a0, void *a1);
extern void func_0202ABD0(struct Obj *obj);
extern u32 func_02049030(u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *func_0202AEEC(u32 a, u32 b);
extern void func_0202AF28(void *item);
extern u32 sub_020307B0(void *p);
extern u32 func_0202ACC8(void *obj);
extern void func_0202AEB8(void *obj, u32 value);
extern int func_0202AEBC(int a0);
extern u32 func_0202ACBC(u32 *p);
extern int func_0202ADB4(int a0, int a1);
extern int func_0202AD8C(int a0);
extern void func_0202ABFC(void *obj, u32 value);
u32 sub_0202ABF8(void *obj);
void sub_0202ABFC(void *obj, u32 value);
void func_0202AC00(u8 *p);
void func_0202AB5C(u8 *p, u32 a1);
void sub_0202AB64(void *obj, u32 unused, u32 value);
void func_0202AB7C(struct Node *p, void *heapId);
extern const char g_020A76E8[];


/*
 * iss_city_sys.c: an unlabelled forwarding leaf, a pool-word tail call to
 * func_0202AC60 with the caller's arguments passed through untouched.
 */
void func_0202AB5C(u8 *p, u32 a1)
{
    func_0202AC60(p, a1);
}



/*
 * A constructor-shaped clear on a small object: five words and a byte
 * zeroed, the third argument stored at offset 0, and a byte at +0x19 set to
 * 0xff. The second argument is never read; the compiler is free to reuse its
 * register (r1) as the zero source for every clearing store, which is why
 * the parameter has to stay declared even though nothing in the body names
 * it. No relocation of any kind. Matched as a one-function unit rather than
 * with `one`: disasm.py's extent for this address runs two bytes long
 * because it counts the linker's inter-section padding before the next
 * label (0x0202AB7C, a labelled veneer), and `tu` lays the compiled object
 * out on its own footprint instead of against that extent.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/sub_0202AB64.c \
 *       --addr 0x0202AB64 --thumb
 */
void sub_0202AB64(void *obj, u32 unused, u32 value)
{
    ((struct Obj03492 *)obj)->f4 = 0;
    ((struct Obj03492 *)obj)->f8 = 0;
    ((struct Obj03492 *)obj)->fC = 0;
    ((struct Obj03492 *)obj)->f10 = 0;
    ((struct Obj03492 *)obj)->f14 = 0;
    ((struct Obj03492 *)obj)->f18 = 0;
    ((struct Obj03492 *)obj)->f0 = value;
    ((struct Obj03492 *)obj)->f19 = 0xff;
}



/*
 * closed:   blocker func_0202AB7C.c is now a manifest entry (matched class)
 *
 * A bare tail-call thunk to func_0202AB8C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AB7C.c \
 *       --func func_0202AB7C --addr 0x0202AB7C --thumb --cc 1.1p1
 */
void func_0202AB7C(struct Node *p, void *heapId)
{
    func_0202AB8C((struct A *)p, heapId);
}


void func_0202AB84(void *obj)
{
    func_0202ABD0(obj);
}



/*
 * Graduated from src/pending/; promoted once its blocker became a manifest entry.
 *
 * Previously blocked at MATCH on `label`: func_0202AEEC has exactly one branch reference
 * image-wide, this function's own call, so no witness exists outside the
 * compared range and no cut helps.  It closes when func_0202AEEC (pkt_0202AEEC)
 * acquires a manifest entry or a second caller appears.
 *
 * closed:   blocker 0202AEEC is now a manifest entry (matched class)
 */
void func_0202AB8C(struct A *a0, void *a1)
{
    s32 n = func_02049030(0x84);
    s32 i;

    a0->unk18 = n;
    a0->unk14 = func_02030734((u32)a1, n << 2, 0, g_020A76E8, 0x14d);
    for (i = 0; i < n; i++) {
        a0->unk14[i] = (u32)func_0202AEEC((u32)a1, i);
    }
}


void func_0202ABD0(struct Obj *obj)
{
    int i;
    int count = obj->count;

    for (i = 0; i < count; i++) {
        func_0202AF28(obj->arr[i]);
    }
    sub_020307B0(obj->arr);
    obj->arr = 0;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * A getter/setter pair on a word field at offset 8 of the same object, back
 * to back with no gap. Neither function has a relocation.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202ABF8.c \
 *       --addr 0x0202ABF8 --thumb
 */
u32 sub_0202ABF8(void *obj)
{
    return ((struct Obj17262 *)obj)->f8;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * A getter/setter pair on a word field at offset 8 of the same object, back
 * to back with no gap. Neither function has a relocation.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202ABF8.c \
 *       --addr 0x0202ABF8 --thumb
 */
void sub_0202ABFC(void *obj, u32 value)
{
    ((struct Obj17263 *)obj)->f8 = value;
}


void func_0202AC00(u8 *p)
{
    if (func_0202ACC8(p) != 0)
        return;

    ((struct Obj15813 *)p)->f4 = 1;
    func_0202AEB8(p, 0);
    func_0202AEBC((int)p);
    func_0202ADB4((int)p, func_0202ACBC((u32 *)p));

    if (func_0202AD8C((int)p) == 1)
        func_0202ABFC(p, 1);
    else
        func_0202ABFC(p, 0);
}
