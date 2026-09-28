/*
 * function: func_021D97A4
 * address:  0x021D97A4
 * packet:   pkt_021D97A4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E5D40   0x021E5D40  thumb
 *   func_021E89D0   0x021E89D0  thumb
 *   func_021E8A00   0x021E8A00  thumb
 *   func_021E5EF8   0x021E5EF8  thumb  ov119
 *   func_021E5F24   0x021E5F24  thumb
 *
 * Release path for the +0x1c block pointer, freed through 0x021E5EF8
 *     and cleared; a second call is a no-op.  The callee address is shared by
 *     two overlays, so the symbols: line carries the ov177 hint that the
 *     image's call to it there fixes.
 */

typedef unsigned long u32;

extern void func_021E5EF8(u32 p);

void func_021D97A4(char *obj)
{
    u32 p = *(u32 *)(obj + 0x1c);

    if (p != 0) {
        func_021E5EF8(p);
        *(u32 *)(obj + 0x1c) = 0;
    }
}

