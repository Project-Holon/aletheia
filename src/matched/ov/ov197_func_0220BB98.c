/*
 * function: B_BAG_MAIN_GetSlotItem
 * address: 0x0220BB98
 * packet: pkt_ov197_0220BB98
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: one statement n = (n + k * 6) << 2, then p += index * 0x90 and a
 *   const u16 pointer s = p + n read as s[0xa8] / s[0xa9]; the byte-offset
 *   spelling (n += ..; n *= 4; slot + 0x150) sank the shift after the
 *   0x90 multiply (13 bytes), and a typed row struct folded 0x150 (60 bytes).
 */
typedef unsigned short u16;
typedef unsigned char u8;
unsigned B_BAG_MAIN_GetSlotItem(const char *p, unsigned n)
{
    unsigned index = *(u8 *)(p + 0x533);
    const u16 *s;
    n = (n + *(short *)(*(char **)p + 0x38 + index * 2) * 6) << 2;
    p += index * 0x90;
    s = (const u16 *)(p + n);
    if (s[0xa8] != 0 && s[0xa9] != 0) return s[0xa8];
    return 0;
}
