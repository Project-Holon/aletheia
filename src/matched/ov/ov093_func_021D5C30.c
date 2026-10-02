/*
 * function: func_021D5C30
 * address: 0x021D5C30
 * packet: pkt_ov093_021D5C30
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are zero alignment padding.
 * symbols:
 *   func_021D5C08 0x021D5C08 thumb ov093
 */
struct UtilWork;
extern unsigned int func_021D5C08(struct UtilWork *);
int func_021D5C30(struct UtilWork *p)
{
    if (func_021D5C08(p) != 16) return 1;
    return 0;
}
