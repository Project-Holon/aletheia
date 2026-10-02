/*
 * function: func_02024450
 * address: 0x02024450
 * packet: pkt_02024450
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned short u16;

int func_02024450(const u16 *p)
{
    if (*p != 0xFFFF) {
        return 1;
    }
    return 0;
}
