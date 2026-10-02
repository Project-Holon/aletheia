/*
 * function: func_021F0354
 * address: 0x021F0354
 * packet: pkt_ov035_021F0354
 * region: ov035
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: followers 021F0364 and 021F0370 already filed separately.
 * symbols:
 *   func_02027974 0x02027974 thumb
 */
extern void func_02027974(void *p);
void func_021F0354(char *p)
{
    if (*(void **)(p + 0x44) != 0)
        func_02027974(*(void **)(p + 0x44));
}
