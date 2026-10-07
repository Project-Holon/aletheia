/*
 * file:     iss_3ds_sys_p02.c
 * unit:     yes
 * function: func_0202B7B8, func_0202B7BC, func_0202B7C8, func_0202B7D4, func_0202B7E0, func_0202B7EC, func_0202B7F8, func_0202B804, func_0202B810, func_0202B818, func_0202B834, func_0202B84C, func_0202B894, func_0202B8E4, func_0202B8F4
 * address:  0x0202B7B8
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
 *   func_0202AB5C  0x0202AB5C  thumb
 *   sub_0202B420  0x0202B420  thumb
 *   func_0202BECC  0x0202BECC  thumb
 *   sub_0202C0C8  0x0202C0C8  thumb
 *   sub_0202B90C  0x0202B90C  thumb
 *   Data_0209FF88  0x0209FF88  data
 */
#include "../../matched/include/Obj15841.h"
#include "../../matched/include/Obj08804.h"
#include "../../matched/include/Obj15842.h"
#include "../../matched/include/Obj17267.h"
#include "../../matched/include/Obj15843.h"
#include "../../matched/include/Obj15844.h"
#include "../../matched/include/Obj01019.h"

struct Obj;
struct SaveBlock;
struct Rec44;
struct BigObj;
struct Sub02006E40Obj;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    u8   id;
    u8   pad[3];
    void (*enter)(void *);
    void (*leave)(void *);
} Entry;

extern void func_0202AB5C(u8 *p, u32 a1);
extern void sub_0202B420(u8 *p, u16 v);
extern void func_0202BECC(u8 *p, u32 key);
extern void sub_0202C0C8(void *p);
extern void sub_0202B90C(u8 *a0);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u16 func_02005C44(void);
extern u32 func_0201295C(const struct BigObj *p);
extern u8 func_02006E7C(const struct Sub02006E40Obj *obj, u16 key);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_0202BA24(u8 *p);
extern void func_0202B944(void *obj);
extern void  func_0202B958(u8 *p);
extern void func_0202B9C8(struct Obj *o);
extern u32 func_020307B0(void *p);
extern void func_0202BAF4(u8 *o);
void sub_0202B7B8(void);
void func_0202B7BC(struct Obj *o, u32 a1);
void func_0202B7C8(u8 *p, u16 v);
void func_0202B7D4(u8 *p, u32 key);
void func_0202B7E0(u8 *p, u32 b);
void func_0202B7EC(u8 *p, u32 b);
void *func_0202B7F8(struct Obj *o);
u16 func_0202B804(struct Obj *o);
u32 func_0202B810(void);
u8 func_0202B818(struct Obj *o);
u32 func_0202B834(struct Obj *o);
void func_0202B84C(void *a);
u8 *func_0202B894(u32 id);
void func_0202B8E4(struct Obj *o);
void func_0202B8F4(u8 *a0);
extern const Entry Data_0209FF88[];




/*
 * An empty function: `bx lr` and nothing else. Matched as a one-function
 * unit rather than with `one`, because disasm.py's 4-byte extent for this
 * address includes the linker's inter-section padding after the 2-byte
 * body, and `tu` lays the compiled object out on its own footprint instead
 * of against that extent (see src/matched/sub_0202AB64.c for the same
 * situation with a longer body).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/sub_0202B7B8.c \
 *       --addr 0x0202B7B8 --thumb
 */
void sub_0202B7B8(void)
{
}





/*
 * Parked: the only site, the ABS32 at +0008, names 0x0202AB5C, which is a
 * four-byte Thumb linker veneer (`ldr r3, [pc, #0]; bx r3` followed by the word
 * 0x0202AC61 - measured at 0x0202AB5C..0x0202AB60) sitting in the word run
 * before 0x0202AB64.  veneer_at() admits only the two ARM encodings, so the
 * `veneer` class refuses a Thumb stub; `label` has no label (disasm.py prints
 * it as data), `literal` has no pool word outside this range, and no C spelling
 * produces the stub, so it can never be a manifest entry.  Permanent.
 */
void func_0202B7BC(struct Obj *o, u32 a1)
{
    func_0202AB5C((u8 *)(((struct Obj15841 *)o)->f10), a1);
}





/*
 * Parked: every concrete byte is right; the only unresolved relocation site(s)
 * target 0202B420, which has no witness outside this range (no outside branch names it,
 * not a manifest entry, not in layout/runtime_arm9.txt).
 *
 * The callee is an unlabelled Thumb leaf, so its ISA has to be declared here;
 * without the `symbols:` line the name convention defaults it to ARM and the
 * `matched` class refuses the EXACT entry at 0x0202B420 on the ISA mismatch.
 *
 * Closed by the `matched` class: 0x0202B420 was filed as an EXACT entry this wave (pkt_0202B1F4), and the callee had to be declared thumb here.
 */
void func_0202B7C8(u8 *p, u16 v)
{
    sub_0202B420(((struct Obj08804 *)p)->f18, v);
}





/*
 * Tail-call thunk: the node's 0x1c word goes straight to func_0202BECC.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B7D4.c \
 *       --func func_0202B7D4 --addr 0x0202B7D4 --thumb --cc 1.1p1
 *
 * Closed by the `matched` class: 0x0202BECC -> 0x0202BF90, both filed this wave.
 */
void func_0202B7D4(u8 *p, u32 key)
{
    func_0202BECC((u8 *)(((struct Obj15842 *)p)->f1C), key);
}





/*
 * Parked: every concrete byte is right; the only unresolved relocation site(s)
 * target 0202C0C8, which has no witness outside this range (no outside branch names it,
 * not a manifest entry, not in layout/runtime_arm9.txt).
 *
 * The callee is an unlabelled Thumb thunk, so its ISA has to be declared here;
 * without the `symbols:` line the name convention defaults it to ARM and the
 * `matched` class refuses the EXACT entry at 0x0202C0C8 on the ISA mismatch.
 *
 * Closed by the `matched` class: 0x0202C0C8 was filed as an EXACT entry this wave (pkt_0202C148).
 */
void func_0202B7E0(u8 *p, u32 b)
{
    sub_0202C0C8(((struct Obj08804 *)p)->f20);
}





/*
 * Parked: the only site, the ABS32 at +0008, names 0x0202B90C - the fourth
 * four-byte Thumb linker veneer of the run at 0x0202B8F4/8FC/904/90C
 * (`00 4b 18 47` + word 0x0202BB41).  Artifact class, hence permanent: no C
 * spelling produces it, and with the ARM-only `veneer` class it has no witness
 * of any other class either.  Every concrete byte reproduces.
 */
void func_0202B7EC(u8 *p, u32 b)
{
    sub_0202B90C(((struct Obj08804 *)p)->f24);
}





/*
 * The three iss_3ds_sys.c tail-call units that resolve without any further
 * work: func_0202B7F8 forwards the +4 field to func_020127A4,
 * func_0202B804 chains it into func_02012AC8, and func_0202B810 is a bare
 * thunk to func_02005C44.  All three are named in the `function:` field
 * above so that the `matched` class attests all three addresses: the 32
 * bytes laid out by `tu` cover all three entry points, and
 * src/pending/func_0202B744.c needs 0x0202B804 as a witness.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202B7F8.c \
 *       --addr 0x0202B7F8 --thumb --cc 1.1p1
 */
void *func_0202B7F8(struct Obj *o)
{
    return func_020127A4((struct SaveBlock *)((struct Obj17267 *)o)->f4);
}




u16 func_0202B804(struct Obj *o)
{
    return func_02012AC8(func_0202B7F8(o));
}




u32 func_0202B810(void)
{
    return func_02005C44();
}





/*
 * Reads the +4 field, and passes it and the low half of func_0202B810()'s
 * result to func_02006E7C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B818.c \
 *       --func func_0202B818 --addr 0x0202B818 --thumb --cc 1.1p1
 */
u8 func_0202B818(struct Obj *o)
{
    u32 r = func_0201295C((const struct BigObj *)(((struct Obj15843 *)o)->f4));

    return func_02006E7C((const struct Sub02006E40Obj *)r, (u16)func_0202B810());
}





/*
 * Compares the +8 field against func_0202B810() (the +4 field by way of
 * func_020127A4) and returns 1 when they differ, 0 when they match.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B834.c \
 *       --func func_0202B834 --addr 0x0202B834 --thumb --cc 1.1p1
 */
u32 func_0202B834(struct Obj *o)
{
    if (((struct Obj15844 *)o)->f8 == func_0202B810()) {
        return 0;
    }
    return 1;
}





/*
 * note:     wave 16: promoted.  0x0209FF8C was never a second table: it is
 *           Data_0209FF88 + 4, the `enter` field of entry v, which the
 *           compiler reaches through its own pool word because a register
 *           offset load has no immediate (docs/idioms/
 *           pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 *           One symbol, one struct with both callbacks; the +4 site then
 *           resolves against the attested 0x0209FF88.
 */
void func_0202B84C(void *a)
{
    int v = func_0202B818(a);
    int i;

    for (i = 0; i < 9; i++) {
        if (v != Data_0209FF88[i].id && Data_0209FF88[i].leave != 0) {
            Data_0209FF88[i].leave(a);
        }
    }
    if (Data_0209FF88[v].enter != 0) {
        Data_0209FF88[v].enter(a);
    }
}




/*
 * closed:   blocker  is now a manifest entry (matched class)
 *
 * Allocates and clears a 0x26c-byte node, seeds its three scalar members and
 * runs its three initialisers.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B894.c \
 *       --func func_0202B894 --addr 0x0202B894 --thumb --cc 1.1p1
 */
u8 *func_0202B894(u32 id)
{
    u8 *p = (u8 *)func_02030734(id, 0x26c, 0, (const void *)0x020A7738, 0xa3);

    ((struct Obj01019 *)p)->f0 = (u16)id;
    ((struct Obj01019 *)p)->f4 = 0;
    p[8] = 0x7f;
    p[9] = 0x7f;
    p[0xa] = 4;
    ((struct Obj01019 *)p)->fC = 0;
    ((struct Obj01019 *)p)->f10 = 0;
    ((struct Obj01019 *)p)->f14 = 0;
    ((struct Obj01019 *)p)->f18 = 0;
    ((struct Obj01019 *)p)->f1C = 0;
    ((struct Obj01019 *)p)->f20 = 0;

    func_0202BA24(p);
    func_0202B944(p);
    func_0202B958(p);
    return p;
}




/*
 * Tears the object down: func_0202B9C8 first, then the matched heap release
 * func_020307B0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B8E4.c \
 *       --func func_0202B8E4 --addr 0x0202B8E4 --thumb --cc 1.1p1
 */
void func_0202B8E4(struct Obj *o)
{
    func_0202B9C8(o);
    func_020307B0(o);
}


/*
 * Artifact, not C: 0x0202B8F4 is a four-byte linker veneer
 * (`00 4b 18 47` = ldr r3, [pc, #0]; bx r3; .word 0x0202BAF5) sitting in a
 * run of identical veneers at 0x0202B8F4/0x0202B8FC/0x0202B904/0x0202B90C.
 * No C spelling produces this shape; reported in
 * docs/notes/pkt_0202B7BC.func_0202B8F4.c.txt and left parked.
 *
 * A bare tail-call thunk to func_0202BAF4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B8F4.c \
 *       --func func_0202B8F4 --addr 0x0202B8F4 --thumb --cc 1.1p1
 */
void func_0202B8F4(u8 *a0)
{
    func_0202BAF4(a0);
}
