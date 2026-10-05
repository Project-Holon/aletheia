/*
 * function: func_021DE76C
 * address: 0x021DE76C
 * packet: pkt_ov171_021DE76C
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 (wD7 lane16): EXACT. cur and i are both set before n (`u16 i = 0;` at the
 *   declaration, loop with an empty init), so r0/r1 are live while n is computed; the scheduler then sinks them.
 * symbols:
 *   d_021DEC94 0x021DEC94 data
 */
typedef unsigned char u8; typedef unsigned short u16; typedef signed char s8;
extern u8 d_021DEC94[];

void func_021DE76C(u8 *p, int mode)
{
    u16 cur = *(s8 *)(p + 0xC5C);
    u16 i = 0;
    u16 n = *(u16 *)(p + *(s8 *)(p + 0xC5E) * 0xBC + 0xC4);
    for (; i < n; ) {
        if (mode == 1) {
            u8 *q = p + cur;
            q[0xB34] = *(u16 *)(d_021DEC94 + n * 0x18 + i * 4 - 0x16);
            q[0xB3A] = q[0xB34];
            cur++;
            if (cur >= *(u16 *)(p + *(s8 *)(p + 0xC5E) * 0xBC + 0xC4))
                cur = 0;
        } else {
            u8 *q = p + i;
            q[0xB34] = 0;
            q[0xB3A] = 0;
        }
        i++;
        n = *(u16 *)(p + *(s8 *)(p + 0xC5E) * 0xBC + 0xC4);
    }
}
