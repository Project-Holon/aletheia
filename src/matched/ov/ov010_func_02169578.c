/*
 * function: func_02169578
 * address:  0x02169578
 * packet:   pkt_ov010_02169578
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: forwarding tail call to func_02169A68.
 *
 * symbols:
 *   func_02169A68  0x02169A68  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern int func_02169A68(unsigned char *a);

int func_02169578(unsigned char *a)
{
    return func_02169A68(a);
}
