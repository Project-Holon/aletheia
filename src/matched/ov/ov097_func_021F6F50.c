/*
 * function: VS_MULTI_LIST_InitClact
 * address: 0x021F6F50
 * packet: pkt_ov097_021F6F50
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_InitSystem 0x0204A48C arm
 *   gVsMultiListClactInit 0x021F764C data a4
 *   gVsMultiListDispVram 0x021F761C data a4
 */
struct Cfg { unsigned w[7]; };
extern const struct Cfg gVsMultiListClactInit;
extern const unsigned gVsMultiListDispVram[];
extern void CLACT_InitSystem(const struct Cfg *, unsigned, unsigned);
void VS_MULTI_LIST_InitClact(void)
{
    struct Cfg c = gVsMultiListClactInit;
    CLACT_InitSystem(&c, (unsigned)gVsMultiListDispVram, 0x71);
}
