/*
 * function: func_021C2CD8
 * address: 0x021C2CD8
 * packet: pkt_ov093_021C2CD8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x021C2D0E.
 * symbols:
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021C2D10 0x021C2D10 thumb ov093
 *   func_021C2E64 0x021C2E64 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021D5B68(void *);
extern int func_021C2D10(u8 *, u16 *, u8 *, u8 *);
extern int func_021C2E64(u8 *, const u16 *, u8 *, u8 *, int);
void func_021C2CD8(u8 *p, u16 *q, u8 *a, u8 *b)
{
    if (func_021D5B68(b) == 0) {
        if (func_021C2D10(p, q, a, b) != 0)
            func_021C2E64(p, q, a, b, 0);
    }
}
