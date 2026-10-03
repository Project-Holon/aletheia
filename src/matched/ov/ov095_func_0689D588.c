/*
 * function: func_0689D588
 * address: 0x0689D588
 * packet: pkt_ov095_0689D588
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two-byte zero alignment padding follows; contiguous scratch TU is EXACT.
 * symbols:
 *   func_0689D5C8 0x0689D5C8 thumb ov095
 */
typedef unsigned char u8;
extern u8 func_0689D5C8(u8 *, u8);
int func_0689D588(u8 *p, u8 key)
{
    if (func_0689D5C8(p, key) != 6) return 1;
    return 0;
}
