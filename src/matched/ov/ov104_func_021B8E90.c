/*
 * function: func_021B8E90
 * address: 0x021B8E90
 * packet: pkt_ov104_021B8E90
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Clears 16 bytes at p, then sets the word at +4 to 1. EXACT* ends at
 * 021B8EA2, followed solely by two zero alignment bytes. The caller
 * ov104 021B7560 passes a second argument that this function ignores.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
extern void MI_CpuFill8(void *, int, int);

void func_021B8E90(int *p, int a1)
{
    MI_CpuFill8(p, 0, 16);
    p[1] = 1;
}
