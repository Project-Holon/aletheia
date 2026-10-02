/*
 * function: func_021D587C
 * address: 0x021D587C
 * packet: pkt_ov093_021D587C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EF948 0x021EF948 thumb ov093
 */
extern int func_021EF948(int);
int func_021D587C(void *p, int k)
{
    switch(k) {
    case 9: if (func_021EF948(6)) k = 11; break;
    case 11: if (func_021EF948(6)) k = 9; break;
    }
    return k;
}
