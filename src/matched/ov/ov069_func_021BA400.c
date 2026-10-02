/*
 * function: func_021BA400
 * address: 0x021BA400
 * packet: pkt_ov069_021BA400
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow.
 */
int func_021BA400(char *p, int k)
{
    int result = 0;
    if (k == 0) {
        if (*(unsigned short *)(p + 0x160) != 0) {
            *(unsigned short *)(p + 0x160) = *(unsigned short *)(p + 0x160) - 1;
            result = 1;
        }
    } else if (k == 1) {
        if (*(unsigned short *)(p + 0x160) < *(unsigned short *)(p + 0x162) - 1) {
            *(unsigned short *)(p + 0x160) = *(unsigned short *)(p + 0x160) + 1;
            result = 1;
        }
    }
    return result;
}
