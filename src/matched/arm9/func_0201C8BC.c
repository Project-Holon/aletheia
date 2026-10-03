/*
 * function: func_0201C8BC
 * address:  0x0201C8BC
 * packet:   pkt_0201C8BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045A90  0x02045A90  arm
 *   func_0201DE18  0x0201DE18  thumb
 *   func_0201DE00  0x0201DE00  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201C974  0x0201C974  thumb
 *
 * printsys.c: if the 4-bit field at bits 20..23 of PrintCtx+0x04 is 1,
 * split the packed 5/5/5 triple at +0x0E and pass it to func_0201DE18; on a
 * nonzero result fill buf through func_0201DE00, pass the triple to
 * func_0201DD78 and set done; then set the field to 2.  Render glyphs
 * through func_0201C974 until 0xFFFF, and if done, pass buf back to
 * func_0201DD78.
 *
 * Two facts the bytes pin (docs/notes/pkt_0201C8BC.c.txt has the history):
 *
 *  1. `done` is a PLAIN u8, not a volatile int.  The image reloads the
 *     zero from [sp,#4] before each of the three byte stores and forms buf's
 *     address as `add r1, sp, #8`: [sp,#4] is the SPILL slot of a register
 *     candidate, and buf is the first addressable local.  A plain int done
 *     has its zero forwarded into the stores (180 bytes); a volatile done
 *     gets a home next to buf in the local area and the stores go off
 *     `add r0, sp, #4` plus 4/5/6 (17 out).  A u8 (or u16, or signed char)
 *     flag is neither forwarded nor addressable
 *     (docs/idioms/a-narrow-flag-local-is-spilled-not-constant-propagated.md).
 *
 *  2. The rewrite mask is 0xFF0FFFFF (clear bits 20..23, the field the
 *     `<< 8 >> 28` test reads), then or 0x200000 (field = 2).  Earlier
 *     notes and docs/families/printsys.h wrote 0xFFFF0FFF.
 *
 * hi and mid are int (the u8 truncation is in the expression), lo is u8:
 * that is what puts hi in r7, mid in r6 and lo in the [sp] spill slot.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02045A90(int a0);
extern u32 func_0201DE18(u32 r, u32 g, u32 b);
extern void func_0201DE00(u8 *a0, u8 *a1, u8 *a2);
extern void func_0201DD78(int a0, int a1, int a2);
extern void *func_0201C974(void *a0, void *a1, int a2);

void func_0201C8BC(u8 *a0, int a1)
{
    u16 *p = (u16 *)func_02045A90(a1);
    u8 buf[3];
    u8 done = 0;
    int hi;
    int mid;
    u8 lo;

    buf[0] = done;
    buf[1] = done;
    buf[2] = done;
    if (((int)(*(u32 *)(a0 + 4) << 8)) >> 28 == 1) {
        int v = *(u16 *)(a0 + 0xe);

        hi = (u8)((v >> 10) & 0x1F);
        mid = (u8)((v >> 5) & 0x1F);
        lo = (u8)(v & 0x1F);
        if (func_0201DE18(hi, mid, lo) != 0) {
            func_0201DE00(&buf[2], &buf[1], &buf[0]);
            func_0201DD78(hi, mid, lo);
            done = 1;
        }
        *(u32 *)(a0 + 4) = (*(u32 *)(a0 + 4) & 0xFF0FFFFF) | 0x200000;
    }
    while (*p != 0xFFFF) {
        p = (u16 *)func_0201C974(a0, p, 1);
    }
    if (done) {
        func_0201DD78(buf[2], buf[1], buf[0]);
    }
}
