/*
 * function: GFL_NET_DEVWIRELESS_Begin
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
 *   NET_WHPIPE_IsIdle 0x02177AA8 thumb ov014
 */
extern int NET_WHPIPE_IsIdle(void);
int GFL_NET_DEVWIRELESS_Begin(void (*cb)(void))
{
    if (cb != 0) {
        NET_WHPIPE_IsIdle();
        cb();
    }
    return NET_WHPIPE_IsIdle();
}
