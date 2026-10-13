/*
 * function: DWCi_ScCreateSessionCallback
 * address:  0x021DF07C
 * packet:   pkt_021DF07C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Dispatches through the function pointer at +8 of the ov175 bss slot
 *  *  0x021E4D08: the first two arguments are dropped, the third and fourth
 *  *  become the callee's arguments.
 */

typedef unsigned long u32;

typedef struct {
    u32 f0;
    u32 f4;
    void (*fn)(u32, u32);
} Disp;

void DWCi_ScCreateSessionCallback(u32 a, u32 b, u32 c, u32 d)
{
    Disp *t = (Disp *)0x021E4D08;
    t->fn(c, d);
}

