/*
 * function: func_020682F8
 * address:  0x020682F8
 * packet:   pkt_020682F8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MIi_CpuClearFast    0x02082AC0  arm
 *
 * Fill a sub-rectangle of ONE 8x8 tile with a pixel word.  dst is the tile,
 * (x, y) the sub-rectangle's offset inside it, (w, h) its extent, val the
 * expanded pixel word (func_02068A18's expansion) and bpp 4 or 8.  A whole
 * tile goes to MIi_CpuClearFast (MIi_CpuClearFast) in one call; otherwise each
 * of the h rows is masked in place, one word per row at 4bpp and two at
 * 8bpp, where the 64-bit row mask is built longhand from two 32-bit halves
 * with the >= 32 shift cases spelled out.  Called seven-argument from
 * func_02068AE8 and func_02068C84.
 *
 * COMPILER PIN ../2.0/sp2, "kept branches" (docs/FRONTEND-PINS.md): the image
 * keeps `blo` over both four-instruction >= 32 blocks (0x020683A4,
 * 0x020683C8); 1.1p1 predicates them and is 304 bytes against 312.
 *
 * Levers, after the note docs/notes/pkt_020682F8.c.txt had the push one
 * register too wide under the pin (63 bytes out):
 *   - u and the 64 - (u + w*8) remainder are UNSIGNED (`blo`, not `blt`);
 *   - in the 8bpp arm the remainder is NOT held in a local across the arm:
 *     it is named once for the first test (`r`) and written out again at
 *     each later use.  Holding it live is what cost the third callee-saved
 *     register (found by tools/permuter.py, expand(v));
 *   - the 4bpp mask is built in two statements (m = ~0 >> u; m <<= ...);
 *   - declaration order `set` before `end` (4bpp) and `slo, shi, p, end`
 *     (8bpp) picks the image's registers for the fill values and the bound.
 */

typedef unsigned int u32;

extern void MIi_CpuClearFast(u32 data, void *dst, int size);

void func_020682F8(u32 *dst, int x, int y, int w, int h, u32 val, int bpp)
{
    if (w == 8 && h == 8) {
        MIi_CpuClearFast(val, dst, bpp << 3);
        return;
    }
    if (bpp == 4) {
        int u = x << 2;
        int v = 0x20 - (u + (w << 2));
        u32 m = 0xFFFFFFFF >> u;
        u32 *p;
        u32 set;
        u32 *end;

        m = m << (v + (x << 2));
        p = dst + y;
        end = p + h;
        set = val & (m >> v);
        m = ~(m >> v);
        while (p < end) {
            *p = set | (*p & m);
            p++;
        }
    } else {
        u32 u = x << 3;
        u32 lo = 0xFFFFFFFF >> u;
        u32 hi;
        u32 slo;
        u32 shi;
        u32 *p;
        u32 *end;
        u32 e;
        u32 r;

        r = 0x40 - (u + (w << 3));
        if (r < 0x20) {
            lo = lo << u;
        } else {
            e = r - 0x20;
            lo = (lo << (u + e)) >> e;
        }
        hi = 0xFFFFFFFF << (0x40 - (u + (w << 3)));
        if (u < 0x20) {
            hi = hi >> (0x40 - (u + (w << 3)));
        } else {
            e = u - 0x20;
            hi = (hi >> (e + (0x40 - (u + (w << 3))))) << e;
        }
        p = dst + y * 2;
        end = p + h * 2;
        slo = val & lo;
        shi = val & hi;
        lo = ~lo;
        hi = ~hi;
        while (p < end) {
            p[0] = slo | (p[0] & lo);
            p[1] = shi | (p[1] & hi);
            p += 2;
        }
    }
}
