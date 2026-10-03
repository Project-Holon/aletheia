/*
 * function: func_021FAE1C
 * address: 0x021FAE1C
 * packet: pkt_ov132_021FAE1C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;

int func_021FAE1C(char *p, int *out)
{
    int start;
    int delta;
    *(u16 *)(p + 0xe) += 1;
    if (*(u16 *)(p + 0xe) >= *(u16 *)(p + 0xc)) {
        *out = *(int *)(p + 8);
        return 1;
    }
    start = *(int *)(p + 4);
    delta = *(int *)(p + 8) - start;
    *out = start + (delta * *(u16 *)(p + 0xe)) / *(u16 *)(p + 0xc);
    return 0;
}
