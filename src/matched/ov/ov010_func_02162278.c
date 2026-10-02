/*
 * function: func_02162278
 * address: 0x02162278
 * packet: pkt_ov010_02162278
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned short u16;
void func_02162278(char *p, int index, u16 a, u16 b)
{
    *(int *)(p + 0x30 + index * 8) = index;
    *(u16 *)(p + 0x34 + index * 8) = a;
    *(u16 *)(p + 0x36 + index * 8) = b;
    *(u16 *)(p + 2) = (u16)(*(u16 *)(p + 2) | (1 << (index + 5)));
}
