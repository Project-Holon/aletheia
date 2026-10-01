/*
 * function: func_021EADD4
 * address: 0x021EADD4
 * packet: pkt_ov093_021EADD4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE318 0x021EE318 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct O;
extern int func_021EE318(struct O *);
int func_021EADD4(u8 *p)
{
    return func_021EE318(*(struct O **)(p + 0x17c));
}
