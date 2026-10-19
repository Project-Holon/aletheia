/*
 * function: default_link_is_on
 * address:  0x021573BC
 * packet:   pkt_ov009_021573BC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * network.o static leaf: the default link-state callback CPS_Startup installs,
 *   reporting the link as up. Placed from the vendor symtab; entry seeded in
 *   layout/function_starts.txt (pool word at ov009 0x021575A4 in CPS_Startup).
 *
 * sdk:      default_link_is_on (libcps.TWL.HYB.a network.o, static)
 */

int default_link_is_on(void)
{
    return 1;
}
