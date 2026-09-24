/*
 * function: func_021DF1C8
 * address:  0x021DF1C8
 * packet:   pkt_021DF1C8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   func_021DFAA8   0x021DFAA8  arm  ov175
 *   func_021DF644   0x021DF644  arm  ov175
 *   func_02059F54   0x02059F54  arm
 *   g_021E4D08      0x021E4D08  data
 *
 * Looks the argument up in the ov175 bss slot's +4 field, and on a hit
 * reports code 8 through func_021DF644 into the arm9 error channel.
 */

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
} Slot;

extern u32 func_021DFAA8(u32 a, u32 b);
extern u32 func_021DF644(u32 a, u32 b);
extern void func_02059F54(u32 a, u32 b);
extern u32 g_021E4D08[];

u32 func_021DF1C8(u32 a)
{
    Slot *t = (Slot *)g_021E4D08;
    u32 r5 = func_021DFAA8(t->f4, a);

    if (r5 != 0) {
        u32 r4 = 8;

        func_02059F54(r4, func_021DF644(r4, r5));
    }
    return r5;
}

/*
 * EXACT*: the listing extent runs to 92 bytes because the neighbour
 * func_021DF20C is an untraced 5-word blob; the compiled body's 68 bytes
 * all compare equal and all 4 relocation sites resolve.
 */
