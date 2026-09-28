/*
 * function: func_02156F50
 * address:  0x02156F50
 * packet:   pkt_02156F50
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021A8268  0x021A8268  data  ov009
 *
 * Setter after the function ending at pool 0x02156F4C, which stores to the
 * same halfword: writes its argument to +0x20 of the object d_021A8268
 * points to. Called from the ov175 root func_021D7E18 (0x021D85E0).
 */

typedef unsigned short u16;

extern char *d_021A8268;

void func_02156F50(int a)
{
    *(u16 *)(d_021A8268 + 0x20) = a;
}
