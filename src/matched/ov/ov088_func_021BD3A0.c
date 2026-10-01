/*
 * function: func_021BD3A0
 * address: 0x021BD3A0
 * packet: pkt_ov088_021BD3A0
 * region: ov088
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Unlabelled 24-byte predicate. Parent cleared this sole blocker of
 * ov204:021BE708 after SDK/ownership/unit/shard audit. Same object at p+a4
 * is passed by matched ov204:021BE6E8/021BE6F8 to ov088:021BD374/021BD39C;
 * ov204:021BEF20 initializes it from input d+c. Matched ov088:021BD3B8
 * reads the same byte fields (7 and 4), confirming the region inference.
 */
int func_021BD3A0(unsigned char *p)
{
    if (p[7] == 1)
        return 1;
    if (p[4] == 3)
        return 1;
    return 0;
}
