/*
 * function: SCRIPT_WORK_CompareValues
 * address: 0x0215932C
 * packet: pkt_ov010_0215932C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
int SCRIPT_WORK_CompareValues(unsigned int a, unsigned int b)
{
    if (a < b) return 0;
    if (a == b) return 1;
    return 2;
}
