/*
 * function: func_021F8D18
 * address:  0x021F8D18
 * packet:   pkt_021F8D18
 * region:   ov185
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021FEEC0   0x021FEEC0  thumb
 *   func_021FBDA4   0x021FBDA4  thumb
 *   func_021FC1F8   0x021FC1F8  thumb
 *   func_021FC610   0x021FC610  thumb  ov135
 *   func_021F3AF0   0x021F3AF0  thumb
 *
 * Build the p+0x14 handle once: flush the three sub-resources and start
 *   0x21F3AF0 on the indexed table entry.
 */


extern void func_021FEEC0(int, int, int);
extern void func_021FBDA4(int, int);
extern void func_021FC1F8(int, int);
extern void func_021FC610(int, int);
extern int func_021F3AF0(int, int);

void func_021F8D18(char *a, int *r4)
{
    if (*(int *)(a + 0x14) == 0) {
        func_021FEEC0(r4[1], 0, 0);
        func_021FBDA4(r4[3], 0);
        func_021FC1F8(r4[3], 0);
        func_021FC610(r4[2], *(unsigned short *)(a + 0x30));
        *(int *)(a + 0x14) = func_021F3AF0(
            *(int *)(a + 0x40 + *(unsigned short *)(a + 0xC) * 4) + 0x80,
            *(unsigned short *)(a + 0x30));
    }
}
