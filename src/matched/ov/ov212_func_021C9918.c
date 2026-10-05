/*
 * function: func_021C9918
 * address: 0x021C9918
 * packet: pkt_ov212_021C9918
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u8 func_021C9918(const u8 *t, const u16 *u, u32 s, u32 f)
{
    u16 n;
    n = 0;
    if (f != 0) {
        do {
            s = u[s];
            if (s == 0) break;
            n++;
        } while (n != f);
    }
    return t[s];
}
