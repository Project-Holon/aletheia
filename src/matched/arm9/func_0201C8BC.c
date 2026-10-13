/*
 * function: PRINTSYS_RunJob
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
 *   STRBUF_GetChars  0x02045A90  arm
 *   GF_FONT_IsTextColorDifferent  0x0201DE18  thumb
 *   GF_FONT_GetTextColor  0x0201DE00  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   PRINTSYS_PrintStep  0x0201C974  thumb
 *
 * printsys.c: if the 4-bit field at bits 20..23 of PrintCtx+0x04 is 1,
 * split the packed 5/5/5 triple at +0x0E and pass it to GF_FONT_IsTextColorDifferent; on a
 * nonzero result fill buf through GF_FONT_GetTextColor, pass the triple to
 * func_0201DD78 and set done; then set the field to 2.  Render glyphs
 * through PRINTSYS_PrintStep until 0xFFFF, and if done, pass buf back to
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
#include "../include/Obj00698.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct U16Vec;
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u32 GF_FONT_IsTextColorDifferent(u32 r, u32 g, u32 b);
extern void GF_FONT_GetTextColor(u8 *a0, u8 *a1, u8 *a2);
struct PrintCtx;
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern u16 *PRINTSYS_PrintStep(struct PrintCtx *c, u16 *p, u32 f);

void PRINTSYS_RunJob(u8 *a0, int a1)
{
    u16 *p = (u16 *)STRBUF_GetChars((struct U16Vec *)a1);
    u8 buf[3];
    u8 done = 0;
    int hi;
    int mid;
    u8 lo;

    buf[0] = done;
    buf[1] = done;
    buf[2] = done;
    if (((int)(((struct Obj00698 *)a0)->f4 << 8)) >> 28 == 1) {
        int v = ((struct Obj00698 *)a0)->fE;

        hi = (u8)((v >> 10) & 0x1F);
        mid = (u8)((v >> 5) & 0x1F);
        lo = (u8)(v & 0x1F);
        if (GF_FONT_IsTextColorDifferent(hi, mid, lo) != 0) {
            GF_FONT_GetTextColor(&buf[2], &buf[1], &buf[0]);
            func_0201DD78((int)hi, (int)mid, (int)lo);
            done = 1;
        }
        ((struct Obj00698 *)a0)->f4 = (((struct Obj00698 *)a0)->f4 & 0xFF0FFFFF) | 0x200000;
    }
    while (*p != 0xFFFF) {
        p = (u16 *)PRINTSYS_PrintStep((struct PrintCtx *)a0, p, (int)1);
    }
    if (done) {
        func_0201DD78((int)buf[2], (int)buf[1], (int)buf[0]);
    }
}
