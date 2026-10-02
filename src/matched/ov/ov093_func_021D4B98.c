/*
 * function: func_021D4B98
 * address: 0x021D4B98
 * packet: pkt_ov093_021D4B98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_021D4330 0x021D4330 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *d_021F3B88;
extern u8 func_021D4330(int);
int func_021D4B98(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (func_021D4330(i) != 0 && *(u16 *)(d_021F3B88 + i * 0xbbc + 0x17ae) != 0)
            return 0;
    }
    return 1;
}
