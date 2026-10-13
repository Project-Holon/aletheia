/*
 * function: OPTION_MENU_ExitList
 * address:  0x021BA7B4
 * packet:   pkt_ov068_021BA7B4
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to MI_CpuFill8(p, 0, 0x58).  Address also resident in ov217;
 * region-qualified packet id.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

void OPTION_MENU_ExitList(void *p)
{
    void MI_CpuFill8(void *, int, int);
    MI_CpuFill8(p, 0, 0x58);
}
