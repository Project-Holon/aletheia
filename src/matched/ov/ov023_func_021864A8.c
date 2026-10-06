/*
 * function: func_021864A8
 * address: 0x021864A8
 * packet: pkt_ov023_021864A8
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C08 0x02035C08 arm
 *   d_02186AAC 0x02186AAC data a4
 */
extern int func_02035C08(const void *p);
extern char d_02186AAC[];
int func_021864A8(char *p)
{
    if (func_02035C08(d_02186AAC) != -1)
        return 1;
    return 0;
}
