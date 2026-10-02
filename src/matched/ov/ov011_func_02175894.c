/*
 * function: func_02175894
 * address: 0x02175894
 * packet: pkt_ov011_02175894
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F4FC 0x0203F4FC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_0203F4FC(void);
int func_02175894(u8 *p)
{
    u32 now = func_0203F4FC();
    u32 stamp = *(u32 *)(p + 0x190);
    if (now < stamp) now += 86400;
    return now - stamp;
}
