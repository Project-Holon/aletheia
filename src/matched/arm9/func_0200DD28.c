/*
 * function: func_0200DD28
 * address:  0x0200DD28
 * packet:   pkt_0200DD28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 100 bytes (0x0200DD28..0x0200DD8C). Sets one bit of the 2000-bit bitmap of
 * the 0xB90 save block (unit_0200DD10.c) and packs four bytes into its stamp.
 * The u8 mask initialised to 1 at the top gives the early `movs r3,#1`.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_0200DD28(u8 *p, u32 a, u32 b, u32 *q) {
    u8 mask = 1;
    u16 idx;
    if (b == 0 || b > 200 || a == 0 || a > 10) {
        return;
    }
    idx = (b - 1) + (a - 1) * 200;
    mask <<= (u8)(idx % 8);
    (p + 4)[(u8)(idx / 8)] |= mask;
    *(u32 *)p = (q[0] << 24) | ((q[1] << 24) >> 8) | ((q[2] << 24) >> 16) | q[3];
}
