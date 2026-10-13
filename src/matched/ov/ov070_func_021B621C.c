/*
 * function: ITEMMENU_SwapSlots
 * address: 0x021B621C
 * packet: pkt_ov070_021B621C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */
typedef unsigned char u8;
extern void MI_CpuCopy8(const void *, void *, unsigned int);
void ITEMMENU_SwapSlots(u8 *p, int a, int b)
{
    int tmp;
    MI_CpuCopy8(p + 0x20 + (int)((unsigned int)a * 4U), &tmp, 4);
    MI_CpuCopy8(p + 0x20 + (int)((unsigned int)b * 4U), p + 0x20 + (int)((unsigned int)a * 4U), 4);
    MI_CpuCopy8(&tmp, p + 0x20 + (int)((unsigned int)b * 4U), 4);
}
