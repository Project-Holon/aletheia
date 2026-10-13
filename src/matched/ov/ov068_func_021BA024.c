/*
 * unit:     yes
 * function: OPTION_MENU_InitInput, OPTION_MENU_ExitInput
 * address:  0x021BA024
 * packet:   pkt_ov068_021BA024
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two identical wrappers around MI_CpuFill8(p, 0, 0x20).
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

void OPTION_MENU_InitInput(void *p, int heap)
{
    void MI_CpuFill8(void *, int, int);
    MI_CpuFill8(p, 0, 0x20);
}

void OPTION_MENU_ExitInput(void *p)
{
    void MI_CpuFill8(void *, int, int);
    MI_CpuFill8(p, 0, 0x20);
}
