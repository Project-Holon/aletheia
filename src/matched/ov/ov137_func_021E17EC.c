/*
 * function: func_021E17EC
 * address: 0x021E17EC
 * packet: pkt_ov137_021E17EC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef signed short s16;
int func_021E17EC(char *p)
{
    int count = 0;
    unsigned bits = *(s16 *)(*(char **)(p + 0xdc) + 0x46);
    while (bits) {
        count += bits & 1;
        bits >>= 1;
    }
    return count;
}
