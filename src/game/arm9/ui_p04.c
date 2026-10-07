/*
 * file:     ui_p04.c
 * unit:     yes
 * function: func_02035080, func_0203508C, func_02035100, func_02035108, func_02035120
 * address:  0x02035080
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
 *   g_021469BC    0x021469BC  data
 *   func_02035080 0x02035080  arm
 *   func_02035120 0x02035120  arm
 *   func_02035100  0x02035100  arm
 */
#include "../../matched/include/Obj08822.h"
#include "../../matched/include/Obj15886.h"

struct Obj02035080;
struct Obj02035120;
typedef unsigned int u32;

struct Obj02035080 {
    unsigned char pad[0x1c];
    u32 unk1C;
    unsigned char pad2[0x0C];
    u32 unk2C;
};

typedef unsigned char u8;

struct Obj02035120 {
    unsigned char pad[0x18];
    u32 unk18;
    unsigned char pad2[0x04];
    u32 unk20;
    unsigned char pad3[0x08];
    u32 unk2C;
    u32 unk30;
};

extern void func_02035080(struct Obj02035080 *p, u32 a, u32 b);
extern void func_02035120(struct Obj02035120 *p, u32 a, u32 b);
void func_0203508C(u32 a, u32 b, u32 c);
u32 func_02035100(u32 *p);
u32 func_02035108(void);
extern u8 *g_021469BC;



/*
 * A plain two-field setter in the ARM SDK-style block at
 * 0x02035000..0x02038000: "str r1,[r0,#0x1c]; str r2,[r0,#0x2c]; bx lr",
 * twelve bytes, no relocations at all.  The struct here only pins the two
 * offsets this function touches, not the real layout.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035080.c \
 *       --func sub_02035080 --addr 0x02035080 --cc 1.1p1 --arm
 */
void sub_02035080(struct Obj02035080 *p, u32 a, u32 b)
{
    p->unk1C = a;
    p->unk2C = b;
}


void func_0203508C(u32 a, u32 b, u32 c)
{
    u8 *g = g_021469BC;

    if (g[0x41] != 0) {
        if (((struct Obj08822 *)g)->f18 != 0) {
            ((void (*)(u32)) * (u32 *)(g + 0x18))(((struct Obj08822 *)g)->f2C);
        }
        if (a != 0) {
            ((void (*)(u32))a)(c);
        }
    }
    func_02035080((struct Obj02035080 *)g_021469BC, a, c);
    func_02035120((struct Obj02035120 *)g_021469BC, b, c);
}


/*
 * An unlabelled leaf.  disasm.py only traces a prologue that saves lr, so this
 * eight-byte getter was printed as `.word 0xE590001C / .word 0xE12FFF1E` in
 * the word run that follows func_0203508C's literal pool
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  It is the
 * only callee func_02035108 has, and that neighbour stays capped at MATCH for
 * as long as this address has no manifest entry
 * (docs/idioms/a-veneer-attests-nothing-while-its-target-is-an-unlabelled-leaf.md
 * is the same shape, where the stub in between makes a `matched` entry useless
 * - here the pool word names the leaf directly, so the entry is the unblock).
 */
u32 func_02035100(u32 *p)
{
    return ((struct Obj15886 *)p)->f1C;
}



/*
 * closed:   the tail call's target 0x02035100 is now a manifest entry
 *           (matched class); the global resolves on `literal x100`.
 *
 * Promoted out of src/pending: it was parked at MATCH on 0x02035100, an
 * unlabelled eight-byte leaf that had no witness of any class - its only
 * naming pool word is this function's own.  Filing the leaf (see
 * src/matched/func_02035100.c) closes the site with no change here.
 */
u32 func_02035108(void)
{
    return func_02035100((u32 *)g_021469BC);
}



/*
 * Two more plain field setters right after sub_02035080's pair, same shape:
 * "str r1,[r0,#0x18]; str r2,[r0,#0x2c]; bx lr" then
 * "str r1,[r0,#0x20]; str r2,[r0,#0x30]; bx lr", twelve bytes each, no
 * relocations.  A third function follows in the same block at 0x02035138
 * (not attempted here: it loads through two pool words and is not a plain
 * accessor).
 *
 * The struct here only pins the four offsets these two functions touch, not
 * the real layout.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02035120.c \
 *       --addr 0x02035120 --arm
 */
void sub_02035120(struct Obj02035120 *p, u32 a, u32 b)
{
    p->unk18 = a;
    p->unk2C = b;
}

void sub_0203512C(struct Obj02035120 *p, u32 a, u32 b)
{
    p->unk20 = a;
    p->unk30 = b;
}
