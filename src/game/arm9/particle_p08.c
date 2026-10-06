/*
 * file:     particle_p08.c
 * unit:     yes
 * function: func_02050C04, func_02050C30, func_02050DB8, func_02050ED4
 * address:  0x02050C04
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
 *   g_02146A88     0x02146A88  data
 *   g_020A7FC0     0x020A7FC0  data
 *   g_020A1590     0x020A1590  data
 *   g_020A1584     0x020A1584  data
 *   g_020A1578     0x020A1578  data
 *   g_020A15A8     0x020A15A8  data
 *   func_02030734  0x02030734  arm
 *   func_02051648  0x02051648  arm
 *   func_02052DC8  0x02052DC8  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02051620  0x02051620  arm
 *   func_0206168C  0x0206168C  arm
 *   func_020621FC  0x020621FC  arm
 *   func_02061824  0x02061824  arm
 *   func_02062594  0x02062594  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02048AC4  0x02048AC4  arm
 */
#include "../../matched/include/Obj01319.h"

struct Dst648;
struct Src648;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct { u32 x, y, z; } Vec3;

struct Emit {
    u32  f00;
    u8   pad04[0x08];
    u32  f0c;
    u32  f10;
    u32  f14;
    u8   pad18[0x1a];
    u16  f32;
    Vec3 f34;
    Vec3 f40;
    Vec3 f4c;
    u8   pad58[0x202];
    u8   f25a;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02051648(struct Dst648 *this, struct Src648 *src, u16 a2, int *a3, int *a4, int *a5, u32 a6);
extern u32   func_02052DC8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void  MI_CpuFill8(void *dst, u32 v, u32 n);
extern void func_02051620(void);
extern void func_0206168C(u32 *src);
extern u32 func_020621FC(u32 h);
extern void func_02061824(void *p);
extern int func_02062594(u32 id);
extern u32 func_020307B0(void *p);
extern u32 func_02048AC4(void *ptr);
int func_02050C04(int a, int b, int c, int d);
void *func_02050C30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap);
void func_02050DB8(u8 *p);
void func_02050ED4(void);
extern u32 *g_02146A88;
extern const char g_020A7FC0[];
extern Vec3 g_020A1590;
extern Vec3 g_020A1584;
extern Vec3 g_020A1578;
extern const u32 g_020A15A8[];



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050C04.c \
 *       --func func_02050C04 --addr 0x02050C04 --cc 1.1p1 --arm
 */
int func_02050C04(int a, int b, int c, int d)
{
    return (int)func_02050C30(a, b, c, 5, 6, 63, d);
}



/*
 * particle.c, the emitter constructor (wave 13): find a free slot among the
 * sixteen in the 0x02146A88 table, allocate a 0x260-byte emitter (particle.c
 * line 285), clear it, copy the three default vectors in as struct
 * assignments, clear flag bit 0, wire the span fields from (a0, a1), publish
 * the emitter in its slot, optionally build the 3D block (a2 == 1), and store
 * func_02052DC8's handle at +0.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02050C30.c.txt: size-exact at 392 with 37
 * bytes out inside the final argument setup, permuter exhausted): the
 * per-slot table 0x020A15A8 is CONST, `extern const u32 g_020A15A8[];`.
 * Without const the element load may not move above the two argument stores
 * to the outgoing area (they could alias it), so the compiler schedules the
 * truncations and stores first; const lets it issue the table base load
 * first and the element load in the middle, as the image does.  The same
 * mechanism as docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md,
 * applied to a global array.  The note's argument order (a3, a4, a5 each
 * truncated with a (u16) cast at the use) and its three other decisions all
 * stand.
 */
void *func_02050C30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap)
{
    struct Emit *e;
    u32 *tab;
    int i = 0;

    tab = g_02146A88;
    do {
        if (tab[i] == 0)
            break;
        i++;
    } while (i < 16);
    if (i >= 16)
        return 0;

    e = (struct Emit *)func_02030734((u16)heap, 0x260, 0, g_020A7FC0, 285);
    MI_CpuFill8(e, 0, 0x260);
    e->f34 = g_020A1590;
    e->f40 = g_020A1584;
    e->f4c = g_020A1578;
    e->f32 = e->f32 & ~1u;
    MI_CpuFill8((void *)a0, 0, a1);
    e->f0c = a0;
    e->f10 = a0;
    e->f14 = a0 + a1;
    e->f25a = (u8)i;
    g_02146A88[i] = (u32)e;

    if (a2 == 1)
        func_02051648((struct Dst648 *)e, 0, 0x2000, 0, 0, 0, heap);

    e->f00 = func_02052DC8(g_020A15A8[i], 0x18, 0xc8, (u16)a3, (u16)a4, (u16)a5);
    return e;
}



/*
 * Emitter teardown: release the two 0x40-entry resource tables (either as a
 * whole through func_0206168C / func_02061824, or entry by entry through
 * func_020621FC / func_02062594 depending on the flag byte at +0x258), drop
 * the block at +4 unless the +0x32 bit-0 bitfield says otherwise, unpublish
 * the emitter from the singleton's sixteen-slot table, release the 3D block
 * at +0x20 and free the record.
 *
 * CLOSES both residues of docs/notes/func_02050DB8.c.txt.
 *
 * 1. The note's HARD BLOCKER is gone without filing anything: 0x0206168C
 *    (and 0x02061824) had no branch outside this range, but both are traced
 *    `func_` labels, so the sole-ref/code sub-kind added 2026-09-21 attests
 *    them.  All nine sites resolve, none wildcarded.
 *
 * 2. The note's 20-byte register swap in the sixteen-entry search loop is
 *    closed by writing that loop WITHOUT a cursor local: `g_02146A88[j]`
 *    drawn fresh at both the read and the store, not `a = g_02146A88; a[j]`.
 *    Found with tools/permuter.py (hill, budget 500, mutation `expand(a x2)`).
 *    The note ruled out declaration order, a separate index, hoisting the
 *    counter and the pointer-walk form, but never tried expanding the cursor
 *    away; with the cursor gone the array pointer lands in r2 and the index
 *    in r1, which is the image's assignment.  The note's other finding for
 *    this loop still holds and is still needed: the element goes into a named
 *    local `t` before the compare, or the compare comes out `cmp r5, r0`.
 *
 * Two more spelling tells found on the way to size-exact, neither in the note:
 *   * the two 0x40-entry loops read the element as `((u32 *)(p + 0x58))[i]`
 *     but store it as `*(u32 *)(p + i * 4 + 0x58)`.  Spelled the SAME way at
 *     both ends the compiler CSEs the address into a callee-saved register
 *     and holds it across the call, which drops the image's second
 *     `add r0, r5, r6, lsl #2` -- four bytes per loop, eight in total, and a
 *     sixth register in the frame.  Two different spellings of one address
 *     defeat the CSE and give the image's recompute-per-use.
 *   * the +0x32 guard is `((u32)(f << 31) >> 31) == 0`: the cast to u32 is
 *     what makes the second shift `lsrs` rather than `asrs` (the u16 field
 *     promotes to int, and a plain `>> 31` on an int is arithmetic).  A
 *     `& 1` mask folds to a single `tst` and is four bytes short, per the
 *     note.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050DB8.c \
 *       --func func_02050DB8 --addr 0x02050DB8 --cc 1.1p1 --arm
 *   EXACT, 284 bytes, 9 relocation sites, all resolved.
 */
void func_02050DB8(u8 *p)
{
    int i;
    u32 z = 0;

    func_02051620();

    if (p[0x258] & 1) {
        func_0206168C((u32 *)(p + 0x58));
    } else if (p[0x258] & 2) {
        for (i = 0; i < 0x40; i++) {
            if (((u32 *)(p + 0x58))[i] != 0) {
                func_020621FC(((u32 *)(p + 0x58))[i]);
                *(u32 *)(p + i * 4 + 0x58) = z;
            }
        }
    }

    if (p[0x258] & 4) {
        func_02061824(p + 0x158);
    } else if (p[0x258] & 8) {
        for (i = 0; i < 0x40; i++) {
            if (((u32 *)(p + 0x158))[i] != 0) {
                func_02062594(((u32 *)(p + 0x158))[i]);
                *(u32 *)(p + i * 4 + 0x158) = z;
            }
        }
    }

    {
        u32 h = ((struct Obj01319 *)p)->f4;
        p[0x258] = (u8)z;
        ((struct Obj01319 *)p)->f8 = z;
        if (h != 0) {
            if (((u32)((((struct Obj01319 *)p)->f32) << 31) >> 31) == 0) {
                func_020307B0((void *)h);
                ((struct Obj01319 *)p)->f4 = z;
            }
        }
    }

    {
        int j = 0;
        for (;;) {
            u32 t = g_02146A88[j];
            if (t == (u32)p) {
                g_02146A88[j] = z;
                break;
            }
            j++;
            if (j >= 0x10)
                break;
        }
    }

    if (((struct Obj01319 *)p)->f20 != 0)
        func_02048AC4((void *)(((struct Obj01319 *)p)->f20));

    func_020307B0(p);
}



/*
 * Teardown of a sixteen-entry table of pointers: every non-null entry is
 * released through func_02050DB8, then the table pointer itself is handed to
 * func_020307B0 and cleared.  The global is re-read from its own slot before
 * every use, which is what the loop's `ldr r0, [r4]` at the top is; the two
 * pool words are the same address, so both `ldr r4, [pc, ...]` load one word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050ED4.c \
 *       --func func_02050ED4 --addr 0x02050ED4 --cc 1.1p1 --arm
 */
void func_02050ED4(void)
{
    int i;

    for (i = 0; i < 16; i++) {
        u32 v = g_02146A88[i];

        if (v != 0)
            func_02050DB8((u8 *)v);
    }
    func_020307B0((void *)((u32)g_02146A88));
    g_02146A88 = 0;
}
