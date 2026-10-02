/*
 * function: func_02177080
 * address: 0x02177080
 * packet: pkt_ov014_02177080
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   func_02177AA8 0x02177AA8 thumb ov014
 */
extern int func_02177AA8(void);
int func_02177080(void (*cb)(void))
{
    if (cb != 0) {
        func_02177AA8();
        cb();
    }
    return func_02177AA8();
}
