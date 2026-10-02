/*
 * function: func_021BFBD0
 * address: 0x021BFBD0
 * packet: pkt_ov093_021BFBD0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two alignment bytes at 0x021BFC06 precede the next labelled function.
 * symbols:
 *   func_021CD568 0x021CD568 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021CD568(void *, u32, u32, ...);
void func_021BFBD0(u8 *p, u32 fallback, u8 *record, u32 pos)
{
    u32 value = *(u16 *)record;
    if (value == 0) value = fallback;
    func_021CD568(*(void **)(p + 12), (u16)pos, 0x30,
                 record[2], record[3], value, record[4]);
    record[4] = 0;
    record[5] |= 2;
}
