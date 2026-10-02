/*
 * function: func_02157E78
 * address: 0x02157E78
 * packet: pkt_ov010_02157E78
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
void func_02157E78(u8 *p)
{
    void (*callback)(u8 *) = *(void (**)(u8 *))(p + 0x678);
    if (callback != 0)
        callback(p);
}
