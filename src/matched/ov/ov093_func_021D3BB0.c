/*
 * function: func_021D3BB0
 * address: 0x021D3BB0
 * packet: pkt_ov093_021D3BB0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: compiled 14 bytes followed by 2-byte alignment padding.
 * ABI: narrow extern arguments follow explicit caller truncation.
 * symbols:
 *   func_021EFA94 0x021EFA94 thumb ov093
 */
extern int func_021EFA94(void *, int);
int func_021D3BB0(char *p, int unused, unsigned int *a)
{
    func_021EFA94(*(void **)(p + 0x34), a[0]);
    return 1;
}
