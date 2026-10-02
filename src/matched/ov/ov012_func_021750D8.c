/*
 * function: func_021750D8
 * address: 0x021750D8
 * packet: pkt_ov012_021750D8
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Two trailing alignment bytes. Duplicated store arms preserve the branch stub.
 */
typedef unsigned char u8;
int func_021750D8(u8 *p, int slot, int value)
{
    int i;
    int result;
    if (value == 255) {
        (p+slot)[0xcc] = value;
        result = 1;
    } else {
        for (i = 0; i < 4; i++) {
            if ((p+i)[0xcc] == value) { result = 0; break; }
        }
    if (i == 4) {
        (p+slot)[0xcc] = value;
        result = 1;
    }
    }
    (p+slot)[0xd0] = result;
    return result;
}
