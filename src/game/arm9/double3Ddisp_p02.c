/*
 * file:     double3Ddisp_p02.c
 * unit:     yes
 * function: func_0204EA4C, func_0204EA64, func_0204EAD4, func_0204EB68, func_0204EBD4, func_0204ED24, func_0204ED4C, func_0204ED70, func_0204ED80, func_0204ED8C, func_0204ED98, func_0204EDA4, func_0204EDB0, func_0204EDBC, func_0204EDC4
 * address:  0x0204EA4C
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
 *   g_02146A80 0x02146A80 data a4
 *   func_020809B4   0x020809B4  arm
 *   func_020806B0   0x020806B0  arm
 *   func_0208068C   0x0208068C  arm
 *   func_0207D4B0   0x0207D4B0  arm
 *   func_0207D518   0x0207D518  arm
 *   func_020809A0   0x020809A0  arm
 *   func_0208074C   0x0208074C  arm
 *   func_02030734  0x02030734  arm
 *   sBillboard     0x020A7FA4  data
 *   func_0204F27C  0x0204F27C  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj11443.h"
#include "../../matched/include/Obj06987.h"
#include "../../matched/include/Obj16108.h"
#include "../../matched/include/Obj16110.h"
#include "../../matched/include/Obj16112.h"
#include "../../matched/include/Obj16114.h"
#include "../../matched/include/Obj16116.h"
#include "../../matched/include/Obj16118.h"
#include "../../matched/include/Obj11444.h"

struct Actor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Blk3 {
    u32 w[3];
};

extern void func_020809B4(void);
extern void func_020806B0(int sub_bg);
extern void func_0208068C(u32 v);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_0207D518(u32 v);
extern int func_020809A0(void);
extern void func_0208074C(int sub_obj);
extern void func_0204F27C(struct Actor *p);
extern u32 func_020307B0(void *p);
void func_0204ED24(void *p);
void func_0204ED80(u8 *dst, u16 *src);
void func_0204ED8C(u8 *dst, u16 *src);
void func_0204ED98(u8 *dst, u16 *src);
void func_0204EDA4(u8 *dst, u16 *src);
void func_0204EDB0(u8 *dst, u8 *src);
void func_0204EDBC(u8 *dst, u8 val);
void func_0204EDC4(u8 *dst, int a, int b);
void func_0204EA4C(void);
void func_0204EA64(void);
void func_0204EAD4(void);
void func_0204EB68(void);
void func_0204ED4C(u8 *a0, short *a1);
extern char *g_02146A80;



/*
 * Sets the +8 word of the cell-actor singleton to 1.
 * Witness leaf for ov180 func_021B6704.
 */
void func_0204EA4C(void)
{
    *(int *)(g_02146A80 + 8) = 1;
}




/*
 * The cell-actor system's shutdown step: it bails out while the power-control
 * halfword at 0x04000304 is non-zero, then tears the system down one way or
 * the other depending on the +4 word of the singleton, clears +8 and toggles
 * +4 to 1 if it was 0.
 *
 * 0x04000606 is a hardware address cast in the source, not a relocation: it
 * is a pool word with no symbols block entry, and the halfword there is read
 * (which is what a `u16` hardware register at that address looks like).
 *
 * The +4 word is both tested and then re-read, and both re-reads of the
 * singleton (`ldr r0, [pc, #0x24]; ldr r1, [r0]`) are the global's own address
 * being reloaded after the call, so the source spells `g_02146A80` out again
 * instead of holding it in a local.
 *
 * `x = (x == 0) ? 1 : 0` comes out as `mov r2, #0` before the earlier store
 * and a single predicated `moveq r2, #1` here: the zero is materialised once
 * and shared with the store of 0 to +8.
 */
void func_0204EA64(void)
{
    if (*(volatile u16 *)0x04000606 != 0) {
        return;
    }
    if (*(u32 *)(g_02146A80 + 8) == 0) {
        return;
    }
    if (*(u32 *)(g_02146A80 + 4) != 0) {
        func_0204EB68();
    } else {
        func_0204EAD4();
    }
    *(u32 *)(g_02146A80 + 8) = 0;
    *(u32 *)(g_02146A80 + 4) = (*(u32 *)(g_02146A80 + 4) == 0) ? 1 : 0;
}




/*
 * The mirror of func_0204EB68, and func_0204EA64's other shutdown arm: it
 * *sets* bit 15 of the power-control halfword at 0x04000304 instead of
 * clearing it, runs the complementary SDK calls, and leaves 0x04001000 and
 * 0x0400100c in the "on" state.
 *
 * Three things here are spelling rather than codegen.  The u32 clear is
 * `& ~0x1f00`, which is encodable and becomes `bic`; the u16 mask at the very
 * end is written `& 0xffbf` rather than `& ~0x40` because 0xffbf is not an ARM
 * immediate and therefore costs a pool word, which is what the image has -
 * `~0x40` would have been a `bic #0x40` and four bytes shorter.  And the two
 * last statements each read 0x0400100c afresh, because the first one's store
 * makes the second's read a genuinely new volatile load.
 */
void func_0204EAD4(void)
{
    u16 v = *(volatile u16 *)0x04000304;

    *(volatile u16 *)0x04000304 = v | 0x8000;
    func_020809B4();
    func_020806B0(4);
    func_0208068C(8);
    *(volatile u32 *)0x04000064 = 0x80330010;
    func_0207D4B0(1, 0, 1);
    func_0207D518(5);
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0x1f00) | 0x400;
    *(volatile u16 *)0x0400100c = (*(volatile u16 *)0x0400100c & 0x43) | 0x84 | 0x4000;
    *(volatile u16 *)0x0400100c = *(volatile u16 *)0x0400100c & 0xffbf;
}




/*
 * The other arm of func_0204EA64's shutdown: it clears bit 15 of the
 * power-control halfword at 0x04000304, runs three SDK calls, writes
 * 0x80320010 to 0x04000064, runs the two channel teardowns and finally sets
 * bit 12 of 0x04001000 in place.
 *
 * Every one of those addresses is a cast constant, not a symbol: the pool
 * words carry no relocations.  The first and the fifth share a single pool
 * word, because 0x04000064 is 0x2A0 below 0x04000304 and the load's reach
 * covers it - that is the "pool base for a far field" sharing
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md),
 * and writing the second address as its own literal costs an extra pool word
 * and four bytes.
 *
 * Both read-modify-writes are one expression each, which is why there is
 * exactly one load and one store per register despite both being volatile.
 */
void func_0204EB68(void)
{
    u16 v = *(volatile u16 *)0x04000304;

    *(volatile u16 *)0x04000304 = (u16)(v & ~0x8000);
    func_020809A0();
    func_0208074C(8);
    func_0208068C(4);
    *(volatile u32 *)0x04000064 = 0x80320010;
    func_0207D4B0(1, 0, 1);
    func_0207D518(5);
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0x1f00) | 0x1000;
}




struct Blob28 { u32 w[7]; };   /* 28 bytes, align 4 -> ldm/stm 16 + 12 */

struct Board {
    u16 id;             /* 0x00 */
    u16 pad0;
    u32 ptr0;           /* 0x04 */
    u32 ptr1;           /* 0x08 */
    u16 count0;         /* 0x0c */
    u16 count1;         /* 0x0e */
    u8  blob[0x18];     /* 0x10 .. 0x27 */
    u32 a28;            /* 0x28 */
    u32 a2c;            /* 0x2c */
    u16 b30;            /* 0x30 */
    u16 b32;
    u16 b34;
    u16 b36;
    u16 b38;
};

struct BigElem { u32 f00; u32 f04; u32 f08; u32 f0c; u32 f10; u32 f14; u32 f18; u32 f1c; u32 f20; u32 f24; };  /* 0x28 */

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char sBillboard[];

/*
 * billboard.c's board constructor; the only allocation site in the image
 * whose __FILE__ word is 0x020A7FA4 ("billboard.c", the NUL of
 * "battle_disp.c" at 0x020A7FA3 fixes where it starts).  Caller is
 * func_0204FF18.  Three func_02030734 calls at lines 153, 159 and 161: the
 * 0x3c-byte board, its count0 * 0x28 record array and its count1 * 0x1c
 * element array.
 *
 * The whole payload is ONE 28-byte aggregate assignment at +0x0c, which mwcc
 * expands to a 16-byte ldm/stm pair with write-back followed by a 12-byte
 * pair without: the second pair reuses the bases the write-back left in r8
 * (source + 16) and sb (dest + 0x10), so the three bytes of `add` that a
 * spelled-out second copy costs are absent from the original.  The source
 * must be a 4-aligned aggregate; a struct of bytes compiles to a byte-copy
 * loop instead.
 */
void *func_0204EBD4(u8 *src, void *heap)
{
    struct Board *h;
    const char *file;
    int i;

    file = sBillboard;
    h = (struct Board *)func_02030734((int)heap, sizeof(struct Board), 1, file, 153);
    h->id = (u16)(int)heap;
    *(struct Blob28 *)((u8 *)h + 0x0c) = *(struct Blob28 *)src;
    h->ptr0 = (u32)func_02030734((int)heap, h->count0 * 0x28, 1, file, 159);
    h->ptr1 = (u32)func_02030734((int)heap, h->count1 * 0x1c, 1, file, 161);
    for (i = 0; i < h->count0; i++) {
        ((struct BigElem *)h->ptr0)[i].f00 = 0;
        ((struct BigElem *)h->ptr0)[i].f14 = 5;
    }
    for (i = 0; i < h->count1; i++) {
        u16 *q = (u16 *)(h->ptr1 + i * 0x1c);
        *q = (u16)((*q & ~0x3FFFu) | 0x3FFFu);
    }
    h->a2c = 0;
    h->b30 = 0;
    h->b32 = 0;
    h->b34 = 0;
    h->a28 = 0;
    h->b36 = 0;
    h->b38 = 0;
    return h;
}


/*
 * Free an actor and its two sub-objects, in +8, +4, self order.
 */
void func_0204ED24(void *p)
{
    func_0204F27C(p);
    func_020307B0(((struct Obj11443 *)p)->f8);
    func_020307B0(((struct Obj11443 *)p)->f4);
    func_020307B0(p);
}



/*
 * Sets the flag word at +0x2c and copies three signed halfwords out of the
 * caller's array into +0x30, +0x32 and +0x34.
 *
 * Unlabelled in the generated listing, and it is the follower that makes
 * func_0204ED24 EXACT*: the prologue saves nothing, so `disasm.py` never
 * auto-labelled it, and the extent inferred for 0x0204ED24 runs through these
 * 36 bytes to the next label at 0x0204ED70
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Seeding
 * 0x0204ED4C in layout/function_starts.txt turns that EXACT* into EXACT and
 * changes nothing else - it is the integrator's file, not this packet's.
 *
 * The three `ldrsh` leave the array backwards (a1[2] first) and the three
 * `strh` write in order, so the values have to live in three registers at
 * once: the source holds them in locals, and the locals have to be *declared*
 * in reverse order (`v2`, `v1`, `v0`) while being assigned in the same
 * reverse order.  Declared v0, v1, v2 the compiler gives a1[1] the higher of
 * the two scratch registers and a1[2] the lower one, which is four bytes of
 * register field wrong - see
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 * Writing the three stores straight from the array (no locals) interleaves
 * each load with its store and is eight bytes wrong.
 */
void func_0204ED4C(u8 *a0, short *a1)
{
    short v2;
    short v1;
    short v0;

    ((struct Obj06987 *)a0)->f2C = 1;
    v2 = a1[2];
    v1 = a1[1];
    v0 = a1[0];
    ((struct Obj06987 *)a0)->f30 = v0;
    ((struct Obj06987 *)a0)->f32 = v1;
    ((struct Obj06987 *)a0)->f34 = v2;
}



/*
 * Copy the caller's 12-byte record into the actor at +0x10.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204ED70 and its body ends at 0x0204ED80.
 */
void func_0204ED70(u8 *dst, struct Blk3 *src)
{
    *(struct Blk3 *)(dst + 0x10) = *src;
}


/*
 * Halfword field store into the actor at +0x1c from the caller's pointer.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204ED80 and its body ends at 0x0204ED8C.
 */
void func_0204ED80(u8 *dst, u16 *src)
{
    ((struct Obj16108 *)dst)->f1C = *src;
}


/*
 * Halfword field store into the actor at +0x1e from the caller's pointer.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204ED8C and its body ends at 0x0204ED98.
 */
void func_0204ED8C(u8 *dst, u16 *src)
{
    ((struct Obj16110 *)dst)->f1E = *src;
}


/*
 * Halfword field store into the actor at +0x20 from the caller's pointer.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204ED98 and its body ends at 0x0204EDA4.
 */
void func_0204ED98(u8 *dst, u16 *src)
{
    ((struct Obj16112 *)dst)->f20 = *src;
}


/*
 * Halfword field store into the actor at +0x22 from the caller's pointer.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204EDA4 and its body ends at 0x0204EDB0.
 */
void func_0204EDA4(u8 *dst, u16 *src)
{
    ((struct Obj16114 *)dst)->f22 = *src;
}


/*
 * Byte field store into the actor at +0x24 from the caller's pointer.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204EDB0 and its body ends at 0x0204EDBC.
 */
void func_0204EDB0(u8 *dst, u8 *src)
{
    ((struct Obj16116 *)dst)->f24 = *src;
}


/*
 * Byte field store into the actor at +0x25 straight from the value
 * parameter: there is no load in the image at all.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204EDBC and its body ends at 0x0204EDC4.
 */
void func_0204EDBC(u8 *dst, u8 val)
{
    ((struct Obj16118 *)dst)->f25 = val;
}


/*
 * Two halfword field stores, +0x36 and +0x38, from the two value
 * parameters.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204EDC4 and its body ends at 0x0204EDD0.
 */
void func_0204EDC4(u8 *dst, int a, int b)
{
    ((struct Obj11444 *)dst)->f36 = a;
    ((struct Obj11444 *)dst)->f38 = b;
}
