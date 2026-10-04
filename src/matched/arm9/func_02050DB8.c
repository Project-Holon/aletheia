/*
 * function: func_02050DB8
 * address:  0x02050DB8
 * packet:   pkt_02050C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02051620  0x02051620  arm
 *   func_0206168C  0x0206168C  arm
 *   func_020621FC  0x020621FC  arm
 *   func_02061824  0x02061824  arm
 *   func_02062594  0x02062594  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02048AC4  0x02048AC4  arm
 *   g_02146A88     0x02146A88  data
 *
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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02051620(void);
extern void func_0206168C(void *p);
extern u32 func_020621FC(u32 h);
extern void func_02061824(void *p);
extern int func_02062594(u32 id);
extern void func_020307B0(void *p);
extern void func_02048AC4(void *ptr);
extern u32 *g_02146A88;

void func_02050DB8(u8 *p)
{
    int i;
    u32 z = 0;

    func_02051620();

    if (p[0x258] & 1) {
        func_0206168C(p + 0x58);
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
        u32 h = *(u32 *)(p + 4);
        p[0x258] = (u8)z;
        *(u32 *)(p + 8) = z;
        if (h != 0) {
            if (((u32)((*(u16 *)(p + 0x32)) << 31) >> 31) == 0) {
                func_020307B0((void *)h);
                *(u32 *)(p + 4) = z;
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

    if (*(u32 *)(p + 0x20) != 0)
        func_02048AC4((void *)(*(u32 *)(p + 0x20)));

    func_020307B0(p);
}
