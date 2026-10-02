/*
 * function: func_021F00C4
 * address: 0x021F00C4
 * packet: pkt_ov030_021F00C4
 * region: ov030
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: empty callback bx lr, two-byte alignment then separate constructor
 * starts 0x021F00C8; callback alone is reproduced.
 * interface: func_021F0058 installs this callback and func_021F00F8 invokes
 * it with its object pointer in r0. Empty body does not read that context.
 */
void func_021F00C4(void *unused)
{
}
