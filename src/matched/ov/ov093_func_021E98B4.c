/*
 * function: func_021E98B4
 * address: 0x021E98B4
 * packet: pkt_ov093_021E98B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * interface: eight-byte ldr-r3/bx-r3 stub forwards only live r0;
 * target body reads only r0. Original caller compares returned r0 with zero.
 * symbols:
 *   func_021E9738 0x021E9738 thumb ov093
 */
typedef unsigned int u32;
extern u32 func_021E9738(void *);
u32 func_021E98B4(void *p)
{
    return func_021E9738(p);
}
