/*
 * function: func_02177104
 * address: 0x02177104
 * packet: pkt_ov014_02177104
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02177B2C 0x02177B2C thumb ov014
 */
extern void *func_02177B2C(int index);
void *func_02177104(int index)
{
    if (index >= 16) return 0;
    return func_02177B2C(index);
}
