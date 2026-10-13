/*
 * function: OPTION_MENU_ExitRunner
 * address:  0x021BB114
 * packet:   pkt_ov068_021BB114
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to MI_CpuFill8(p, 0, 0x10).
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

void OPTION_MENU_ExitRunner(void *p)
{
    void MI_CpuFill8(void *, int, int);
    MI_CpuFill8(p, 0, 0x10);
}
