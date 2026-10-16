/*
 * function: PMS_INPUT_DATA_FilterInitialWords
 * address: 0x021B98F8
 * packet: pkt_ov110_021B98F8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 PMS_INPUT_DATA_FilterInitialWords(u8 *p, u16 *src, u16 *out, u32 n)
{
    u32 count = 0;
    u32 c = *src;
    while (c != 0xFFFF) {
        if (c == 0xFFFE) {
            u32 len;
            u32 i;
            src++;
            len = *src++;
            for (i = 0; i < len; i++) {
                u32 v = src[i];
                if (p[0x1D6E + (v >> 3)] & (1 << (v & 7))) {
                    out[n++] = v;
                    count++;
                    break;
                }
            }
            src += len;
        } else {
            if (p[0x1D6E + (c >> 3)] & (1 << (c & 7))) {
                out[n++] = c;
                count++;
            }
            src++;
        }
        c = *src;
    }
    return count;
}
