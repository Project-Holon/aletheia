/*
 * function: func_021EADB4
 * address: 0x021EADB4
 * packet: pkt_ov093_021EADB4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE2A0 0x021EE2A0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct O;
extern int func_021EE2A0(struct O *);
int func_021EADB4(u8 *p)
{
    return func_021EE2A0(*(struct O **)(p + 0x17c));
}
