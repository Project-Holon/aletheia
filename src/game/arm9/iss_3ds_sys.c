/*
 * file:     iss_3ds_sys.c
 * unit:     yes
 * function: func_0202B4BC, func_0202B4F0, func_0202B500, func_0202B544, func_0202B578, func_0202B57C, func_0202B584, func_0202B59C, func_0202B5D4, func_0202B5FC, func_0202B610, func_0202B624, func_0202B63C, func_0202B64C, func_0202B65C, func_0202B66C, func_0202B67C, func_0202B68C, func_0202B69C, func_0202B6AC, func_0202B6BC, func_0202B6CC, func_0202B6DC, func_0202B6EC, func_0202B6F8, func_0202B704, func_0202B710, func_0202B720, func_0202B72C, func_0202B738, func_0202B744, func_0202B758, func_0202B764, func_0202B770, func_0202B77C, func_0202B788, func_0202B794, func_0202B7A0, func_0202B7AC, func_0202B7B8, func_0202B7BC, func_0202B7C8, func_0202B7D4, func_0202B7E0, func_0202B7EC, func_0202B7F8, func_0202B804, func_0202B810, func_0202B818, func_0202B834, func_0202B84C, func_0202B894, func_0202B8E4, func_0202B8F4, func_0202B8FC, func_0202B904, func_0202B90C, func_0202B914, func_0202B920, func_0202B928, func_0202B934, func_0202B93C, func_0202B944, func_0202B958, func_0202B9C8, func_0202B9E0, func_0202B9F0, func_0202BA24, func_0202BA60, func_0202BA7C, func_0202BA9C, func_0202BABC, func_0202BAE8
 * address:  0x0202B4BC
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
 *   str_020A772C  0x020A772C  data
 *   func_0202C070  0x0202C070  thumb
 *   func_0202B1F4  0x0202B1F4  thumb
 *   func_0202AB38  0x0202AB38  thumb
 *   func_0202C09C  0x0202C09C  thumb
 *   func_0202AB5C  0x0202AB5C  thumb
 *   func_0202AB4C  0x0202AB4C  thumb
 *   func_0202AB54  0x0202AB54  thumb
 *   func_0202B1FC  0x0202B1FC  thumb
 *   func_0202B204  0x0202B204  thumb
 *   sub_0202B420  0x0202B420  thumb
 *   func_0202BECC  0x0202BECC  thumb
 *   sub_0202C0C8  0x0202C0C8  thumb
 *   sub_0202B90C  0x0202B90C  thumb
 *   Data_0209FF88  0x0209FF88  data
 *   func_0202BB40  0x0202BB40  thumb
 *   func_0202BB48  0x0202BB48  thumb
 */
#include "../../matched/include/Obj02010.h"
#include "../../matched/include/Obj17265.h"
#include "../../matched/include/Obj17266.h"
#include "../../matched/include/Obj00563.h"
#include "../../matched/include/Obj02011.h"
#include "../../matched/include/Obj15840.h"
#include "../../matched/include/Obj15841.h"
#include "../../matched/include/Obj08804.h"
#include "../../matched/include/Obj15842.h"
#include "../../matched/include/Obj17267.h"
#include "../../matched/include/Obj15843.h"
#include "../../matched/include/Obj15844.h"
#include "../../matched/include/Obj01019.h"
#include "../../matched/include/Obj15845.h"
#include "../../matched/include/Obj02601.h"

struct SaveBlock;
struct Obj;
struct Node;
struct Rec44;
struct BigObj;
struct Sub02006E40Obj;
struct ArcFile;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

typedef signed char    s8;

typedef struct {
    u8   id;
    u8   pad[3];
    void (*enter)(void *);
    void (*leave)(void *);
} Entry;

typedef struct { int x, y, z; } V3;

struct Item {
    u32 id;
    u32 unk;
};

struct Obj {
    u8 pad[0x264];
    const struct Item *items;
    u8 count;
};

typedef enum { SLOT_0, SLOT_MAX = 16 } Slot;

typedef struct { int f0; V3 pos; int f10; int f14; int f18; } E;

typedef struct { char pad[0x24]; E e[1]; } M;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void   func_0202B584(void *p);
extern u32 func_020307B0(void *p);
extern void func_0202B7B8(void);
extern struct Node *func_0202B1AC(u32 a, u32 heapId);
extern struct Node *func_0202AAF4(u32 a, void *heapId);
extern struct Node *func_0202B3A0(u32 a, u32 b, u32 heapId);
extern u8 *func_0202BE68(u32 heapId);
extern u8 *func_0202C070(u32 heap);
extern void func_0202B1EC(void *ptr);
extern void func_0202AB28(void *p);
extern void func_0202C08C(u8 *p);
extern void func_0202B404(u8 *p);
extern void func_0202BEBC(u8 *p);
extern void func_0202C0C0(u32 *a0);
extern void func_0202B3EC(u8 *p);
extern void func_0202BEA4(u8 *p);
extern void func_0202B1F4(u8 *a0);
extern void func_0202AB38(u8 *p);
extern void func_0202C09C(u8 *p);
extern void func_0202B1FC(u8 *p);
extern void func_0202AB4C(u8 *p);
extern void func_0202B424(u8 *p);
extern void func_0202C0B8(u8 *p);
extern void func_0202B204(u8 *p);
extern void func_0202AB54(u8 *p);
extern void func_0202B42C(u8 *p);
extern void func_0202BEE4(u8 *p);
extern void func_0202BEDC(int a, int b);
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
extern void func_0202B944(void *obj);
extern void func_0202BAF4(u8 *o);
extern void func_0202BB40(u8 *p);
extern void *func_020490F4(u32 id, u32 heap);
extern u16    func_0204961C(void *obj);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void   func_02049238(void *h);
extern int func_0202BB48(int a0);
void *func_0202B4BC(struct SaveBlock *a, u32 b);
void func_0202B4F0(u8 *p);
void func_0202B500(u8 *p);
void func_0202B544(u32 a, u16 b);
u32 func_0202B578(u32 *p);
u32 sub_0202B57C(void *obj);
u32 sub_0202B580(void *obj);
void sub_0202B584(void *obj);
void func_0202B59C(u8 *p, struct SaveBlock *a, u32 b);
void func_0202B5D4(u32 a);
void func_0202B5FC(struct Obj *o);
void func_0202B610(struct Obj *o);
void func_0202B624(struct Obj *o);
void func_0202B63C(struct Obj *o);
void func_0202B64C(struct Obj *o);
void func_0202B65C(struct Obj *o);
void func_0202B66C(struct Obj *o);
void func_0202B67C(u8 *p);
void func_0202B68C(int a0);
void func_0202B69C(int a0);
void func_0202B6AC(u8 *p);
void func_0202B6BC(int a0);
void func_0202B6CC(u8 *o);
void func_0202B6DC(u8 *o);
void func_0202B6EC(u8 *p);
void func_0202B6F8(u8 *p);
void func_0202B704(u8 *p);
void func_0202B710(u8 *o);
void func_0202B720(u8 *p);
void func_0202B72C(u8 *p);
void func_0202B738(u8 *p);
void func_0202B744(u8 *o);
void func_0202B758(u8 *p);
void func_0202B764(u8 *p);
void func_0202B770(u8 *p);
void func_0202B77C(u8 *p);
void func_0202B788(u8 *p);
void func_0202B794(u8 *p);
void func_0202B7A0(u8 *p);
void func_0202B7AC(u8 *p);
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
void func_0202B8FC(u8 *p);
void func_0202B904(u8 *p);
void func_0202B90C(u8 *a0);
void func_0202B914(struct Obj *o, u32 v);
void func_0202B920(void *m, int i, int a, int b);
int func_0202B928(int a, int b);
void func_0202B934(void *m, int i, const V3 *v);
void func_0202B93C(int a, void *b, void *c);
void sub_0202B944(void *obj);
void func_0202B958(u8 *p);
void func_0202B9C8(struct Obj *o);
int func_0202B9E0(int a0, int a1);
u8 func_0202B9F0(const struct Obj *p, u32 key);
void func_0202BA24(u8 *p);
void func_0202BA60(M *m, int i, int a, int b);
void func_0202BA7C(M *m, int i, const V3 *v);
void func_0202BA9C(char *p, const int *a, const int *b);
void func_0202BABC(u8 *o);
void func_0202BAE8(u32 *p);
extern const u8 str_020A772C[];
extern const Entry Data_0209FF88[];









/*
 * Blocked: the THM_CALL at +0024 to func_0202B59C has no manifest entry yet;
 * it is the last of four sites (str_020A772C resolves on `string`).  Chain:
 * 0x0202B59C needs 0x0202B64C, which needs 0x0202C070, which needs 0x0202C148 -
 * and 0x0202C148 is a DIFF (see docs/notes/pkt_0202C148.c.txt), so this row is
 * capped for this pass.  Every concrete byte reproduces.
 */
void *func_0202B4BC(struct SaveBlock *a, u32 b)
{
    void *p = func_02030734(b, 0x28, 0, (void *)str_020A772C, 0xa3);

    func_0202B584(p);
    func_0202B59C(p, a, b);
    return p;
}









/*
 * closed:   blocker func_0202B2CC.c is now a manifest entry (matched class)
 *
 * Release pair: tear the node down with func_0202B5D4, then free it.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B4F0.c \
 *       --func func_0202B4F0 --addr 0x0202B4F0 --thumb --cc 1.1p1
 */
void func_0202B4F0(u8 *p)
{
    func_0202B5D4((u32)p);
    func_020307B0(p);
}









/*
 * cap: label -- two call targets have no witness outside this range:
 *   0x0202B84C (func_0202B84C) and 0x0202B710 (func_0202B710).
 *   Both are still-open band_0_64 addresses; each is called exactly once
 *   image-wide and that call site is inside this function, so the `label`
 *   class refuses (every witness is in-range). No C change can fix this:
 *   the moment either callee has its own manifest entry the site attests
 *   and this file turns EXACT untouched.
 *   All 68 bytes concrete-identical; 7 of 9 relocation sites resolved.
 */
void func_0202B500(u8 *p)
{
    if (func_0202B834((struct Obj *)p) == 1) {
        func_0202B84C(p);
        ((struct Obj02010 *)p)->f8 = func_0202B810();
    }
    func_0202B6CC(p);
    func_0202B6DC(p);
    func_0202B6EC(p);
    func_0202B6F8(p);
    func_0202B704(p);
    func_0202B710(p);
    ((struct Obj02010 *)p)->fC = ((struct Obj02010 *)p)->fC + 1;
}









/*
 *           --suggest-split offers nothing (single function, both
 *           unresolved sites' only witness is inside this range).
 *
 * Parked: four of the six call sites resolve (0x0202B7B8, 0x0202B7C8,
 * 0x0202B7D4, 0x0202B7E0 are manifest entries).  The two that stay unresolved
 * are 0x0202B7BC and 0x0202B7EC, whose own single callees are the four-byte
 * Thumb linker veneers at 0x0202AB5C and 0x0202B90C - artifact class, no C
 * spelling produces them, so neither thunk can ever earn a manifest entry and
 * no cut of this file frees the site.  Every concrete byte reproduces.
 */
void func_0202B544(u32 a, u16 b)
{
    func_0202B7B8();
    func_0202B7BC((struct Obj *)a, b);
    func_0202B7C8((u8 *)a, b);
    func_0202B7D4((u8 *)a, b);
    func_0202B7E0((u8 *)a, b);
    func_0202B7EC((u8 *)a, b);
}









u32 func_0202B578(u32 *p)
{
    return p[8];
}









/*
 * A whole translation unit, matched as one byte range.
 *
 * Two word getters, at offsets 0x24 and 0x18, packed into a single 8-byte
 * pair with no gap. Neither has a relocation.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202B57C.c \
 *       --addr 0x0202B57C --thumb
 */
u32 sub_0202B57C(void *obj)
{
    return ((struct Obj17265 *)obj)->f24;
}









u32 sub_0202B580(void *obj)
{
    return ((struct Obj17266 *)obj)->f18;
}









/*
 * A constructor-shaped clear on a small object: a leading halfword and ten
 * words, all zeroed in address order. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202B584.c \
 *       --func sub_0202B584 --addr 0x0202B584 --cc 1.1p1 --thumb
 */
void sub_0202B584(void *obj)
{
    ((struct Obj00563 *)obj)->f0 = 0;
    ((struct Obj00563 *)obj)->f4 = 0;
    ((struct Obj00563 *)obj)->f8 = 0;
    ((struct Obj00563 *)obj)->fC = 0;
    ((struct Obj00563 *)obj)->f10 = 0;
    ((struct Obj00563 *)obj)->f14 = 0;
    ((struct Obj00563 *)obj)->f18 = 0;
    ((struct Obj00563 *)obj)->f1C = 0;
    ((struct Obj00563 *)obj)->f20 = 0;
    ((struct Obj00563 *)obj)->f24 = 0;
}









/*
 * Parked: five of the six initialisers resolve as `matched` (0x0202B5FC,
 * 0x0202B610, 0x0202B624, 0x0202B63C, 0x0202B65C).  The one that does not is
 * 0x0202B64C at +002A, which is itself capped on 0x0202C070, which is capped
 * on 0x0202C148 (DIFF).  Every concrete byte reproduces; the C is final.
 *
 * Constructor hub: fills the four word/halfword members of a node and runs
 * its six initialisers in order.
 */
void func_0202B59C(u8 *p, struct SaveBlock *a, u32 b)
{
    ((struct Obj00563 *)p)->f4  = (u32)a;
    ((struct Obj00563 *)p)->f8  = 0xffffffff;
    ((struct Obj00563 *)p)->f0  = (u16)b;
    ((struct Obj00563 *)p)->fC = 0;

    func_0202B5FC((struct Obj *)p);
    func_0202B610((struct Obj *)p);
    func_0202B624((struct Obj *)p);
    func_0202B63C((struct Obj *)p);
    func_0202B64C((struct Obj *)p);
    func_0202B65C((struct Obj *)p);
}









/*
 * Parked: every concrete byte is right; the only unresolved relocation site(s)
 * target 0202B6AC, which has no witness outside this range (no outside branch names it,
 * not a manifest entry, not in layout/runtime_arm9.txt).
 * closed:   blocker func_0202B6AC.c is now a manifest entry (matched class)
 */
void func_0202B5D4(u32 a)
{
    func_0202B66C((struct Obj *)a);
    func_0202B67C((u8 *)a);
    func_0202B68C(a);
    func_0202B69C(a);
    func_0202B6AC((u8 *)a);
    func_0202B6BC(a);
}









/*
 * Builds the +0x14 sub-object from the +4 field and the object's u16 id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B5FC.c \
 *       --func func_0202B5FC --addr 0x0202B5FC --thumb --cc 1.1p1
 */
void func_0202B5FC(struct Obj *o)
{
    ((struct Obj00563 *)o)->f14 = (u32)func_0202B1AC((u32)func_0202B7F8(o), ((struct Obj00563 *)o)->f0);
}









/*
 * closed:   blocker func_0202B6DC.c is now a manifest entry (matched class)
 *
 * Builds the +0x10 sub-object from the +4 field and the object's u16 id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B610.c \
 *       --func func_0202B610 --addr 0x0202B610 --thumb --cc 1.1p1
 */
void func_0202B610(struct Obj *o)
{
    ((struct Obj00563 *)o)->f10 = (u32)func_0202AAF4((u32)func_0202B7F8(o), (void *)(((struct Obj00563 *)o)->f0));
}









/*
 * closed:   blocker func_0202B3A0.c is now a manifest entry (matched class)
 *
 * Builds the +0x18 sub-object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B624.c \
 *       --func func_0202B624 --addr 0x0202B624 --thumb --cc 1.1p1
 */
void func_0202B624(struct Obj *o)
{
    ((struct Obj00563 *)o)->f18 = (u32)func_0202B3A0(((struct Obj00563 *)o)->f4,
                                             (u32)func_0202B7F8(o), ((struct Obj00563 *)o)->f0);
}









/*
 * Builds the +0x1c sub-object from the object's u16 id.
 *
 * Promoted out of src/pending: the callee func_0202BE68 acquired an EXACT
 * manifest entry, so the THM_CALL field now resolves through the `matched`
 * class.  Every byte is hard; the listing extent is two bytes longer than the
 * code because of the Thumb alignment pad the front end emits after `pop`.
 */
void func_0202B63C(struct Obj *o)
{
    ((struct Obj00563 *)o)->f1C = (u32)func_0202BE68(((struct Obj00563 *)o)->f0);
}









/*
 * Blocked: the only site, the THM_CALL at +0006 to func_0202C070, has no
 * manifest entry.  0x0202C070 is byte-correct but capped in turn on 0x0202C148,
 * which is a DIFF (docs/notes/pkt_0202C148.c.txt), so this row cannot close
 * this pass.  Every concrete byte reproduces.
 *
 * Builds the +0x20 sub-object from the object's u16 id.
 */
void func_0202B64C(struct Obj *o)
{
    ((struct Obj00563 *)o)->f20 = (u32)func_0202C070(((struct Obj00563 *)o)->f0);
}









/*
 * closed:   blocker func_0202B59C.c is now a manifest entry (matched class)
 *
 * Builds the +0x24 sub-object from the object's u16 id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B65C.c \
 *       --func func_0202B65C --addr 0x0202B65C --thumb --cc 1.1p1
 */
void func_0202B65C(struct Obj *o)
{
    ((struct Obj00563 *)o)->f24 = (u32)func_0202B894(((struct Obj00563 *)o)->f0);
}









/*
 * Releases the +0x14 field through func_0202B1EC (the OS_FreeToHeap thunk)
 * and clears it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B66C.c \
 *       --func func_0202B66C --addr 0x0202B66C --thumb --cc 1.1p1
 */
void func_0202B66C(struct Obj *o)
{
    func_0202B1EC((void *)(((struct Obj02011 *)o)->f14));
    ((struct Obj02011 *)o)->f14 = 0;
}









/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B67C.c \\
 *       --func func_0202B67C --addr 0x0202B67C --thumb --cc 1.1p1
 *
 * Closed: every byte reproduces and the site that held it open is now attested.
 */
void func_0202B67C(u8 *p)
{
    func_0202AB28(*(u8 * *)&((struct Obj02011 *)p)->f10);
    *(u32 *)&((struct Obj02011 *)p)->f10 = 0;
}








void func_0202B68C(int a0)
{
    func_0202B3EC((u8 *)(((struct Obj02011 *)a0)->f18));
    ((struct Obj02011 *)a0)->f18 = 0;
}








void func_0202B69C(int a0)
{
    func_0202BEA4((u8 *)(((struct Obj02011 *)a0)->f1C));
    ((struct Obj02011 *)a0)->f1C = 0;
}









/*
 * closed:   blocker func_0202B6AC.c is now a manifest entry (matched class)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B6AC.c \\
 *       --func func_0202B6AC --addr 0x0202B6AC --thumb --cc 1.1p1
 */
void func_0202B6AC(u8 *p)
{
    func_0202C08C(*(u8 * *)&((struct Obj02011 *)p)->f20);
    *(u32 *)&((struct Obj02011 *)p)->f20 = 0;
}








void func_0202B6BC(int a0)
{
    func_0202B8E4((struct Obj *)(((struct Obj02011 *)a0)->f24));
    ((struct Obj02011 *)a0)->f24 = 0;
}








/*
 * Blocked: 0202B1F4 (thumb, from header) has no witness outside 0202B6CC..0202B6DC. Every concrete byte reproduces.
 *
 * Closed by the `matched` class: 0x0202B1F4 -> 0x0202B230 -> 0x0202B254, all filed this wave.
 */
void func_0202B6CC(u8 *o)
{
    if ((((struct Obj02010 *)o)->fC & 1) == 0) {
        func_0202B1F4((u8 *)(((struct Obj02010 *)o)->f14));
    }
}








/*
 * Blocked: 0202AB38 (thumb, from header) has no witness outside 0202B6DC..0202B6EC. Every concrete byte reproduces.
 * closed:   blocker func_0202B6DC.c is now a manifest entry (matched class)
 */
void func_0202B6DC(u8 *o)
{
    if ((((struct Obj02010 *)o)->fC & 1) == 0) {
        func_0202AB38((u8 *)(((struct Obj02010 *)o)->f10));
    }
}








/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B6EC.c \\
 *       --func func_0202B6EC --addr 0x0202B6EC --thumb --cc 1.1p1
 */
void func_0202B6EC(u8 *p)
{
    func_0202B404(*(u8 * *)&((struct Obj02010 *)p)->f18);
}







/*
 * Promoted out of src/pending: the tail call's pool word holds the Thumb entry
 * of func_0202BEBC, which acquired an EXACT manifest entry, so the `matched`
 * class now witnesses the ABS32 site.  Every byte is hard, including the
 * two-byte alignment pad the front end emits between the code and the pool.
 */
void func_0202B6F8(u8 *p)
{
    func_0202BEBC(*(u8 * *)&((struct Obj02010 *)p)->f1C);
}







/*
 * The callee is an unlabelled Thumb thunk, so its ISA has to be declared here;
 * without the `symbols:` line the name convention defaults it to ARM and the
 * `matched` class refuses the EXACT entry at 0x0202C0C0 on the ISA mismatch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B704.c \\
 *       --func func_0202B704 --addr 0x0202B704 --thumb --cc 1.1p1
 *
 * Closed by the `matched` class: the pool word names 0x0202C09C, an existing EXACT entry (pkt_0202BE00).
 */
void func_0202B704(u8 *p)
{
    func_0202C09C(*(u8 * *)&((struct Obj02010 *)p)->f20);
}





/*
 * Blocked: the THM_CALL at +000A targets 0x0202B8F4, a four-byte Thumb linker
 * veneer (`00 4b 18 47` + its target word, the head of the identical run
 * 0x0202B8F4/8FC/904/90C).  It is artifact class: no C spelling produces it,
 * so it can never be a manifest entry and `literal` has no outside pool word
 * either (permanent).  Every concrete byte reproduces.
 */
void func_0202B710(u8 *o)
{
    if ((((struct Obj02010 *)o)->fC & 1) == 0) {
        func_0202B8F4((u8 *)(((struct Obj02010 *)o)->f24));
    }
}




void func_0202B720(u8 *p)
{
    func_0202B1FC((u8 *)((struct Obj02010 *)p)->f14);
}




void func_0202B72C(u8 *p)
{
    func_0202AB4C((u8 *)((struct Obj02010 *)p)->f10);
}




void func_0202B738(u8 *p)
{
    func_0202B424((u8 *)((struct Obj02010 *)p)->f18);
}




/*
 * Promoted out of src/pending: both callees, func_0202B804 and func_0202BEDC,
 * now have EXACT manifest entries, so the two THM_CALL fields resolve through
 * the `matched` class and every byte is hard.
 */
void func_0202B744(u8 *o)
{
    func_0202BEDC(((struct Obj15840 *)o)->f1C, func_0202B804((struct Obj *)o));
}




void func_0202B758(u8 *p)
{
    func_0202C0B8((u8 *)((struct Obj02010 *)p)->f20);
}




void func_0202B764(u8 *p)
{
    func_0202B8FC((u8 *)((struct Obj02010 *)p)->f24);
}




void func_0202B770(u8 *p)
{
    func_0202B204((u8 *)((struct Obj02010 *)p)->f14);
}




void func_0202B77C(u8 *p)
{
    func_0202AB54((u8 *)((struct Obj02010 *)p)->f10);
}




void func_0202B788(u8 *p)
{
    func_0202B42C((u8 *)((struct Obj02010 *)p)->f18);
}




void func_0202B794(u8 *p)
{
    func_0202BEE4((u8 *)((struct Obj02010 *)p)->f1C);
}




void func_0202B7A0(u8 *p)
{
    func_0202C0C0((u32 *)((u8 *)((struct Obj02010 *)p)->f20));
}




void func_0202B7AC(u8 *p)
{
    func_0202B904((u8 *)((struct Obj02010 *)p)->f24);
}






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



void func_0202B8FC(u8 *p)
{
    func_0202BABC(p);
}



void func_0202B904(u8 *p)
{
    func_0202BAE8((u32 *)p);
}






/*
 * A bare tail-call thunk, same shape as func_0202B8F4 (ldr r3, [pc, #0];
 * bx r3; .word 0x0202BB41).  0x0202BB40 is itself another thunk (to
 * func_0202BA24), filed as src/matched/func_0202BB40.c in the same shard;
 * that entry is the matched witness for this pool word.
 */
void func_0202B90C(u8 *a0)
{
    func_0202BB40(a0);
}







/*
 * Clamps the second argument to 0x7f and stores it in the +8 byte.  No
 * relocations; pure.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B914.c \
 *       --func func_0202B914 --addr 0x0202B914 --thumb --cc 1.1p1
 */
void func_0202B914(struct Obj *o, u32 v)
{
    if (v > 0x7f) {
        v = 0x7f;
    }
    ((struct Obj15845 *)o)->f8 = (u8)v;
}







/*
 * Unlabelled arm9 leaf, filed as a relocation witness for ov021
 * func_021C4D14 (wave A1, lane 13).
 */
void func_0202B920(void *m, int i, int a, int b)
{
    func_0202BA60(m, i, a, b);
}






int func_0202B928(int a, int b)
{
    return *(int *)(a + b * 0x1c + 0x24);
}







/*
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 func_021C4E34
 * (wave A1, lane 13).
 */
void func_0202B934(void *m, int i, const V3 *v)
{
    func_0202BA7C(m, i, v);
}







void func_0202B93C(int a, void *b, void *c)
{
    func_0202BA9C((char *)a, b, c);
}







/*
 * A three-field initialiser on a far offset (0x264): a word cleared, a byte
 * cleared right after it, and a byte set to 0xff two past that. The offset
 * is past the Thumb ldr/str immediate reach, so the compiler computes the
 * base with a shift instead of an immediate, which is ordinary codegen for
 * a field this far out rather than anything hand written. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202B944.c \
 *       --func sub_0202B944 --addr 0x0202B944 --cc 1.1p1 --thumb
 */
void sub_0202B944(void *obj)
{
    ((struct Obj01019 *)obj)->f264 = 0;
    ((struct Obj01019 *)obj)->f268 = 0;
    ((struct Obj01019 *)obj)->f269 = 0xff;
}







/*
 * closed:   blocker  is now a manifest entry (matched class)
 *
 * Same list dance as func_0202BEEC, on a node whose record table sits at
 * 0x264 and whose record count at 0x268; the node's own u16 id supplies the
 * selector.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B958.c \
 *       --func func_0202B958 --addr 0x0202B958 --thumb --cc 1.1p1
 */
void func_0202B958(u8 *p)
{
    u32  id = ((struct Obj01019 *)p)->f0;
    void *h = func_020490F4(0xb9, (u16)((id & 0x7fff) | 0x8000));
    u8   n = (u8)func_0204961C(h);
    u32  i;

    p[0x268] = n;
    ((struct Obj01019 *)p)->f264 = (u32)func_02030734(id, (u32)(n << 3), 0,
                                             (const void *)0x020A7738, 0x178);

    for (i = 0; i < (u32)n; i++) {
        func_0204932C(h, i, (void *)(((struct Obj01019 *)p)->f264 + (i << 3)));
    }
    func_02049238(h);
}






/*
 * Releases the +0x264 field through the matched heap release func_020307B0,
 * then tears the object down through func_0202B944.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B9C8.c \
 *       --func func_0202B9C8 --addr 0x0202B9C8 --thumb --cc 1.1p1
 */
void func_0202B9C8(struct Obj *o)
{
    func_020307B0((void *)(((struct Obj01019 *)o)->f264));
    func_0202B944(o);
}





int func_0202B9E0(int a0, int a1){ if ((unsigned int)(*(unsigned char *)(((char *)(a0) + ((int)(0x269) << 0)))) != (unsigned int)(a1)) { *(unsigned char *)(((char *)(a0) + ((int)(0x269) << 0))) = (unsigned char)a1; } else {  return a0; } }






u8 func_0202B9F0(const struct Obj *p, u32 key)
{
    const struct Item *items = p->items;
    u8 count;
    u8 i;

    if (items == 0) {
        return 0xff;
    }

    count = p->count;
    for (i = 0; i < count; i++) {
        if (items[i].id == key) {
            return i;
        }
    }

    return 0xff;
}






/*
 * iss_3ds_sys.c: resets the 0x10 entries (record +0x24 stride 0x1c) and the
 * two parallel word arrays at +0x1e4 and +0x224.  EXACT* (the listing extent
 * runs on into the unlabelled 28-byte follower at 0x0202BA60).
 *
 * Two facts closed it after thirteen loop spellings had failed
 * (docs/notes/pkt_0202B9F0.c.txt): the counter is an enum, which keeps the
 * unfolded `cmp r4, #0x10; bge` entry guard with a plain increment
 * (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md), and the
 * three word stores write 0, not i: r3 is a copy of the counter taken once in
 * the preheader, when both are zero, and never incremented.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BA24.c \
 *       --func func_0202BA24 --addr 0x0202BA24 --thumb --cc 1.1p1
 */
void func_0202BA24(u8 *p)
{
    Slot i;
    for (i = 0; i < 0x10; i++) {
        *(u32 *)(p + i * 0x1c + 0x24) = 0;
        *(u32 *)(p + i * 0x1c + 0x38) = 0x7f;
        *(u16 *)(p + i * 0x1c + 0x3c) = 1 << i;
        *(u32 *)(p + i * 4 + 0x1e4) = 0;
        *(u32 *)(p + i * 4 + 0x224) = 0;
    }
}




void func_0202BA60(M *m, int i, int a, int b)
{
    E *e = &m->e[i];
    if (e->f0 != 1) {
        e->f0 = 1;
        e->f10 = a;
        e->f14 = b;
    }
}




static inline void V3_Set(V3 *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}




/*
 * Unlabelled arm9 leaf, filed as the relocation witness for arm9 func_0202B934 (ov021 func_021C4E34)
 * (wave A1, lane 13).
 */
void func_0202BA7C(M *m, int i, const V3 *v)
{
    E *e = &m->e[i];

    if (e->f0 != 0)
        V3_Set(&e->pos, v->x, v->y, v->z);
}




static inline void set3(int *d, int x, int y, int z)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
}





void func_0202BA9C(char *p, const int *a, const int *b)
{
    set3((int *)(p + 0xC), a[0], a[1], a[2]);
    set3((int *)(p + 0x18), b[0], b[1], b[2]);
}





/*
 * Closed by the `matched` class: 0x0202B9F0 became an EXACT shard entry
 * (pkt_0202B9F0) in this wave.  The listing extent runs to 0x0202BAF4
 * because the follower at 0x0202BAE6 is unlabelled, so the verdict is EXACT*.
 */
void func_0202BABC(u8 *o)
{
    if (((struct Obj02601 *)o)->f4 != 0) {
        return;
    }
    ((struct Obj02601 *)o)->f4 = 1;
    func_0202B9E0((int)o, func_0202B9F0((const struct Obj *)o, func_02005C44()));
    func_0202BB48((int)o);
}


void func_0202BAE8(u32 *p)
{
    if (p[1] != 0) {
        p[1] = 0;
    }
}
