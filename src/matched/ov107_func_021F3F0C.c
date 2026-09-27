/*
 * function: mystrlen
 * address:  0x021F3F0C
 * packet:   pkt_ov107_021F3F0C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_gameinfo.o).  decl_line 335, local len
 * (int).  Line map 337/338/339/340/341 at +0x4/+0x0/+0x14/+0x20/+0x24.
 */
typedef unsigned short u16;

int mystrlen(const u16 *str)
{
    int len = 0;

    while (*str++)
        len++;

    return len;
}
