/*
 * function: func_021CA3AC
 * address: 0x021CA3AC
 * packet: pkt_ov093_021CA3AC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero bytes at 021CA3CE are alignment padding.
 * symbols:
 *   func_021BD1B0 0x021BD1B0 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BD1B0(void *, u8);
struct Msg;
extern int func_021C99A0(void *, const struct Msg *);
int func_021CA3AC(u8 *p, const u8 *q)
{
    if (func_021BD1B0(p, q[4])) {
        func_021C99A0(p, (const struct Msg *)(q + 8));
        return 1;
    }
    return 0;
}
