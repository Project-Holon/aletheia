/*
 * function: func_02158B3C
 * address: 0x02158B3C
 * packet: pkt_ov010_02158B3C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
int func_02158B3C(const u8 *p, int key) {
    for (;;) {
        u16 v = p[0] + (p[1] << 8);
        if (v == 0) return 0xffff;
        if (key == v) return (u16)(p[2] + (p[3] << 8));
        p += 6;
    }
}
