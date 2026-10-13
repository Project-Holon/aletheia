/*
 * function: func_0217656C
 * address:  0x0217656C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears 0x28 bytes of the argument.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm  arm9

 */

extern void MI_CpuFill8(void *p, int v, int n);

void func_0217656C(void *p)
{
    MI_CpuFill8(p, 0, 0x28);
}

