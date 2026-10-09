/*
 * file:     iss_dungeon_sys.c
 * unit:     yes
 * function: func_0202B230, func_0202B254, func_0202B28C, func_0202B2A4, func_0202B2BC, func_0202B2CC, func_0202B2FC, func_0202B360, func_0202B374, func_0202B3A0, func_0202B3EC, func_0202B404, func_0202B420, func_0202B424, func_0202B42C, func_0202B434, func_0202B438, func_0202B454, func_0202B47C, func_0202B490, func_0202B49C
 * address:  0x0202B230
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
 *   func_02012984  0x02012984  thumb
 */
#include "../../matched/include/Obj03001.h"
#include "../../matched/include/Obj15831.h"
#include "../../matched/include/Obj05726.h"
#include "../../matched/include/Obj15832.h"
#include "../../matched/include/Obj03438.h"
#include "../../matched/include/Obj15834.h"
#include "../../matched/include/Obj02009.h"
#include "../../matched/include/Obj15835.h"
#include "../../matched/include/Obj15836.h"
#include "../../matched/include/Obj15837.h"
#include "../../matched/include/Obj15838.h"
#include "../../matched/include/Obj11315.h"

struct Rec44;
struct Vec12;
struct Obj;
struct Node;
struct BigObj;
typedef unsigned char u8;

typedef unsigned int  u32;

struct S {
    u32 a;
    u32 b;
    u32 c;
};

typedef signed int    s32;

typedef unsigned short u16;

typedef struct Item {
    u16 id;
    u8 pad[0x1a];
} Item;

typedef struct Container {
    u8 count;
    u8 pad[3];
    Item * volatile items;
} Container;

extern struct Vec12 *func_02012AA0(struct Rec44 *p);
extern void func_02005F24(u32 a, u32 b);
extern void func_02005EE0(u32 a, u32 b, u32 c, u32 d);
extern u32 *func_02005C3C(void);
extern void func_02073018(struct Obj *o, u32 v, u32 w);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02049030(u32 a);
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
extern u32 func_020307B0(void *p);
extern u8 func_02012984(const struct BigObj *p);
void func_0202B230(u8 *p);
u32 func_0202B254(u8 *p);
void func_0202B28C(u8 *p);
void func_0202B2A4(u8 *p);
void func_0202B2BC(u8 *p);
void func_0202B2CC(u8 *p, u32 idx);
u8 *func_0202B2FC(u32 heapId);
void func_0202B360(u8 *p);
Item *func_0202B374(Container *c, u16 id);
struct Node *func_0202B3A0(u32 a, u32 b, u32 heapId);
void func_0202B3EC(u8 *p);
void func_0202B404(u8 *p);
void func_0202B420(u8 *p, u16 v);
void func_0202B424(u8 *a0);
void func_0202B42C(u8 *a0);
u32 func_0202B434(u8 *p);
u32 func_0202B438(u8 *p, u16 id);
void func_0202B454(char *p);
void func_0202B47C(u8 *p);
void func_0202B490(u8 *p);
void func_0202B49C(u8 *p, u16 id);









/*
 * When the object is active, polls it and either advances or retreats.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B230.c \
 *       --func func_0202B230 --addr 0x0202B230 --thumb --cc 1.1p1
 *
 * Closed by the `matched` class: 0x0202B254 was filed as an EXACT entry this wave (pkt_0202B230).
 */
void func_0202B230(u8 *p)
{
    if (((struct Obj03001 *)p)->f0 == 0) {
        return;
    }
    if (func_0202B254(p) != 0) {
        func_0202B28C(p);
    } else {
        func_0202B2A4(p);
    }
}









/*
 * Compares the 12 bytes at +0xc against the record func_02012AA0 returns from
 * the pointer at +8, then copies the record over them either way, and reports
 * whether they differed.
 *
 * The guard has to be written as a conjunction of equalities over subscripts:
 * `if (s[0] == d[0] && s[1] == d[1] && s[2] == d[2]) differ = 0; else differ = 1;`
 * Each test then branches *away* to the shared "1" block and the "0" block falls
 * through, which is the original's shape (movs r3,#0; b over; movs r3,#1).  The
 * disjunction of inequalities - `differ = (s[0] != d[0]) || ...` - is the same
 * value but emits the last test with the opposite polarity and an inline
 * `movs r3,#1`, five bytes away; the ternary spelling of the same conjunction
 * keeps the polarity but moves the copy, and loses the match.
 *
 * Closes the blocker of src/pending/func_0202B230.c, and through it
 * src/pending/func_0202B1F4.c and src/pending/func_0202B6CC.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B254.c \
 *       --func func_0202B254 --addr 0x0202B254 --thumb --cc 1.1p1
 */
u32 func_0202B254(u8 *p)
{
    u32 *s = (u32 *)func_02012AA0((struct Rec44 *)(((struct Obj03001 *)p)->f8));
    int differ;

    if (s[0] == ((struct Obj03001 *)p)->fC && s[1] == ((struct Obj03001 *)p)->f10 &&
        s[2] == ((struct Obj03001 *)p)->f14) {
        differ = 0;
    } else {
        differ = 1;
    }
    *(struct S *)(p + 0xc) = *(struct S *)s;
    return (u32)differ;
}









/*
 * Raises the object's signed +4 value by 8, saturating at 0x7f, and
 * refreshes it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B28C.c \
 *       --func func_0202B28C --addr 0x0202B28C --thumb --cc 1.1p1
 */
void func_0202B28C(u8 *p)
{
    s32 v = (s32)((struct Obj03001 *)p)->f4;

    if (v < 0x7f) {
        v += 8;
        if (v > 0x7f) {
            v = 0x7f;
        }
        ((struct Obj03001 *)p)->f4 = (u32)v;
        func_0202B2BC(p);
    }
}









/*
 * Lowers the object's +4 value by 8, saturating at 0, and refreshes it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B2A4.c \
 *       --func func_0202B2A4 --addr 0x0202B2A4 --thumb --cc 1.1p1
 */
void func_0202B2A4(u8 *p)
{
    s32 v = (s32)((struct Obj03001 *)p)->f4;

    if (v > 0) {
        v -= 8;
        if (v < 0) {
            v = 0;
        }
        ((struct Obj03001 *)p)->f4 = (u32)v;
        func_0202B2BC(p);
    }
}









/*
 * Tail-calls func_02005F24(0x300, value).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B2BC.c \
 *       --func func_0202B2BC --addr 0x0202B2BC --thumb --cc 1.1p1
 */
void func_0202B2BC(u8 *p)
{
    func_02005F24(0x300, ((struct Obj15831 *)p)->f4);
}









/*
 * closed:   blocker func_0202B2CC.c is now a manifest entry (matched class)
 *
 * Indexed-eighth-of-a-word helper: a u16 lane at 0xc+2i and a signed u16 lane
 * at 4+2i of the same record, fed to the tile/VRAM helpers.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B2CC.c \
 *       --func func_0202B2CC --addr 0x0202B2CC --thumb --cc 1.1p1
 */
void func_0202B2CC(u8 *p, u32 idx)
{
    u32 off = idx << 1;

    func_02005EE0(0xffff, *(u16 *)(p + 0xc + off), 0xffffffff, 0);
    func_02073018((struct Obj *)func_02005C3C(), 0xfcff, (u32)*(short *)(p + 4 + off));
}









/*
 * closed:   blocker func_0202B3A0.c is now a manifest entry (matched class)
 *
 * Builds a table node: a count byte is fetched from func_02049030, then that
 * many 0x1c-byte records are allocated and each one formatted in place.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B2FC.c \
 *       --func func_0202B2FC --addr 0x0202B2FC --thumb --cc 1.1p1
 */
u8 *func_0202B2FC(u32 heapId)
{
    u32 i;
    u8 *p = (u8 *)func_02030734(heapId, 8, 0, (const void *)0x020A7718, 0x77);

    p[0] = (u8)func_02049030(0x92);
    ((struct Obj05726 *)p)->f4 = (u32)func_02030734(heapId, 0x1c * p[0], 0,
                                         (const void *)0x020A7718, 0x79);

    for (i = 0; (int)i < (int)p[0]; i++) {
        func_02048F74((u8 *)(((struct Obj05726 *)p)->f4 + i * 0x1c), 0x92, i, 0, (u32 *)0x1c);
    }
    return p;
}









/*
 * Releases the +4 pointer and then the object itself through the heap
 * release.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B360.c \
 *       --func func_0202B360 --addr 0x0202B360 --thumb --cc 1.1p1
 */
void func_0202B360(u8 *p)
{
    func_020307B0(((struct Obj15832 *)p)->f4);
    func_020307B0(p);
}









/*
 * iss_dungeon_sys.c: find the 0x1C-byte item whose id matches, or NULL.
 * Three shape facts close it (docs/notes/pkt_0202B374.c.txt had 6, later
 * 31, bytes out):
 *   - the loop is written as its own guard plus do/while, with the items
 *     base loaded inside the guard (the image loads it after `cmp; ble`);
 *   - the items pointer member is volatile, so the hit path re-reads it
 *     (`ldr r0, [r0, #4]`) instead of reusing the loop's base;
 *   - the count goes through a copy local before the bound (found by
 *     tools/permuter.py, temp(tmp=c->count)): it swaps the bound and the
 *     base between r7 and r6 to the image's choice.
 */
Item *func_0202B374(Container *c, u16 id)
{
    int i;
    int n;
    Item *it;
    int count = c->count;

    n = count;
    i = 0;
    if (i < n) {
        it = c->items;
        do {
            if (id == it[i].id)
                return &c->items[i];
            i++;
        } while (i < n);
    }
    return 0;
}









/*
 * closed:   blocker func_0202B3A0.c is now a manifest entry (matched class)
 *
 * Allocates a 0x38-byte node, fills its header fields, resolves the +0x14
 * sub-object through func_0202B2FC and runs func_0202B454 over it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B3A0.c \
 *       --func func_0202B3A0 --addr 0x0202B3A0 --thumb --cc 1.1p1
 */
struct Node *func_0202B3A0(u32 a, u32 b, u32 heapId)
{
    struct Node *p = (struct Node *)func_02030734(heapId, 0x38, 0,
                                                  (const void *)0x020A7718, 0x109);

    ((struct Obj03438 *)((u8 *)p))->f0 = (u16)heapId;
    ((struct Obj03438 *)p)->f8 = a;
    ((struct Obj03438 *)p)->f4 = b;
    ((struct Obj03438 *)p)->fC = 0;
    ((struct Obj03438 *)p)->f10 = 0xffff;
    ((struct Obj03438 *)p)->f12 = 0xffff;
    ((struct Obj03438 *)p)->f14 = (u32)func_0202B2FC(heapId);
    ((struct Obj03438 *)p)->f18 = 0;
    func_0202B454((char *)p);
    return p;
}









/*
 * Runs the destructor chain: func_0202B42C, then releases the +0x14
 * sub-object and the object itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B3EC.c \
 *       --func func_0202B3EC --addr 0x0202B3EC --thumb --cc 1.1p1
 */
void func_0202B3EC(u8 *p)
{
    func_0202B42C(p);
    func_0202B360(*(u8 * *)&((struct Obj15834 *)p)->f14);
    func_020307B0(p);
}







/*
 * When the object is active and its +0x10 and +0x12 halfwords differ,
 * latches the new value and re-resolves the current record.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B404.c \
 *       --func func_0202B404 --addr 0x0202B404 --thumb --cc 1.1p1
 */
void func_0202B404(u8 *p)
{
    u16 a;
    u16 b;

    if (((struct Obj02009 *)p)->fC == 0) {
        return;
    }
    a = ((struct Obj02009 *)p)->f10;
    b = ((struct Obj02009 *)p)->f12;
    if (a == b) {
        return;
    }
    ((struct Obj02009 *)p)->f10 = b;
    func_0202B49C(p, ((struct Obj02009 *)p)->f10);
}






/*
 * A four-byte setter for the halfword at +0x12.  Unlabelled in the listing
 * (it saves nothing and is chased by a linker thunk at 0x0202B424), absent
 * from the worklist, and filed straight from the bytes.  It is the blocker of
 * src/pending/func_0202B7C8.c, which reaches it through a pool word and so
 * has no other witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B420.c \
 *       --func func_0202B420 --addr 0x0202B420 --thumb --cc 1.1p1
 */
void func_0202B420(u8 *p, u16 v)
{
    ((struct Obj15835 *)p)->f12 = v;
}





/*
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x0202B47C, the callee's
 * address with its Thumb bit set (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B424.c \
 *       --func func_0202B424 --addr 0x0202B424 --thumb --cc 1.1p1
 */
void func_0202B424(u8 *a0)
{
    func_0202B47C(a0);
}




/*
 * A bare tail-call thunk to func_0202B490.  The callee is an unlabelled leaf,
 * so its ISA has to be declared here; with `symbols:` absent the name
 * convention defaults it to ARM and the `matched` class refuses the EXACT
 * entry at 0x0202B490 on the ISA mismatch.
 */
void func_0202B42C(u8 *a0)
{
    func_0202B490(a0);
}



/*
 * Returns the object's +0xc word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B434.c \
 *       --func func_0202B434 --addr 0x0202B434 --thumb --cc 1.1p1
 */
u32 func_0202B434(u8 *p)
{
    return ((struct Obj15836 *)p)->fC;
}




/*
 * Returns 1 when the object's +0x14 sub-object holds a record with the
 * given id, else 0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B438.c \
 *       --func func_0202B438 --addr 0x0202B438 --thumb --cc 1.1p1
 */
u32 func_0202B438(u8 *p, u16 id)
{
    u8 *q = *(u8 * *)&((struct Obj15837 *)p)->f14;

    if (q == 0) {
        return 0;
    }
    return (u8 *)func_0202B374((Container *)q, id) != 0 ? 1 : 0;
}




void func_0202B454(char *p)
{
    int i;
    ((struct Obj15838 *)p)->f1C = 0xffff;
    for (i = 0; i < 4; i++) {
        *(unsigned short *)(p + i * 2 + 0x20) = 0;
        *(unsigned short *)(p + i * 2 + 0x28) = 0x100;
        *(unsigned short *)(p + i * 2 + 0x30) = 0;
    }
}




/*
 * When the object is idle, marks it active and resolves its current
 * record.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B47C.c \
 *       --func func_0202B47C --addr 0x0202B47C --thumb --cc 1.1p1
 */
void func_0202B47C(u8 *p)
{
    if (((struct Obj02009 *)p)->fC == 0) {
        ((struct Obj02009 *)p)->fC = 1;
        func_0202B49C(p, ((struct Obj02009 *)p)->f10);
    }
}




/*
 * Clears the object's active word when it is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B490.c \
 *       --func func_0202B490 --addr 0x0202B490 --thumb --cc 1.1p1
 */
void func_0202B490(u8 *p)
{
    if (((struct Obj11315 *)p)->fC != 0) {
        ((struct Obj11315 *)p)->fC = 0;
    }
}




/*
 * closed:   blocker func_0202B2CC.c is now a manifest entry (matched class)
 *
 * Resolves the node's 0x14 descriptor into the 0x18 slot and, when that
 * succeeds, feeds the resolved handle and the key derived from the node's
 * second word to func_0202B2CC.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B49C.c \
 *       --func func_0202B49C --addr 0x0202B49C --thumb --cc 1.1p1
 */
void func_0202B49C(u8 *p, u16 id)
{
    u32 r = (u32)(u8 *)func_0202B374((Container *)((u8 *)(((struct Obj02009 *)p)->f14)), id);

    ((struct Obj02009 *)p)->f18 = r;
    if (r != 0) {
        func_0202B2CC((u8 *)(((struct Obj02009 *)p)->f18), func_02012984((const struct BigObj *)(((struct Obj02009 *)p)->f8)));
    }
}
