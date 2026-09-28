/*
 * function: func_021BC33C
 * address:  0x021BC33C
 * packet:   pkt_021BC33C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Unlabelled leaf in ov210 directly after func_021BC318 (which ends at
 * 0x021BC328, pool at 0x021BC32C); it saves nothing, so disasm.py prints it
 * inside a .word run.  It is the function-pointer blocker target of
 * func_021BC318 (pkt_021BC318).  Reads a mode byte from [p+0x2b9] and a
 * halfword from the IO register at 0x04000006, then writes one of six packed
 * halfwords to the register at 0x04001052.
 */

void func_021BC33C(void *ctx, unsigned char *p)
{
    int v = *(volatile unsigned short *)0x04000006;
    int b = p[0x2b9];

    if (b == 4) {
        if (v >= 0x98)
            *(volatile unsigned short *)0x04001052 = 0x050B;
        else if (v >= 0x70)
            *(volatile unsigned short *)0x04001052 = 0x060A;
        else if (v >= 0x48)
            *(volatile unsigned short *)0x04001052 = 0x0709;
        else if (v >= 0x20)
            *(volatile unsigned short *)0x04001052 = 0x0808;
        else
            *(volatile unsigned short *)0x04001052 = 0x0A06;
    } else {
        if (v >= 0xa8)
            *(volatile unsigned short *)0x04001052 = 0x050B;
        else if (v >= 0x90)
            *(volatile unsigned short *)0x04001052 = 0x060A;
        else if (v >= 0x78)
            *(volatile unsigned short *)0x04001052 = 0x0709;
        else if (v >= 0x60)
            *(volatile unsigned short *)0x04001052 = 0x0808;
        else if (v >= 0x48)
            *(volatile unsigned short *)0x04001052 = 0x0A06;
        else
            *(volatile unsigned short *)0x04001052 = 0x0C04;
    }
}
