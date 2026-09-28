/*
 * function: SOC_Recv
 * address:  0x0215f590
 * packet:   pkt_ov009_0215F590
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_Recv (soc.o)
 *
 * note:     object DWARF names this clone SOC_Recv but its sole call site
 *           relocates to SOCL_WriteTo 0x0215e024 (socl_write.o).
 *
 * symbols:
 *   SOCL_WriteTo   0x0215e024 arm
 */

extern int SOCL_WriteTo(int s, void *buffer, int buffer_len,
                        unsigned short remote_port, unsigned long remote_ip,
                        int flags);

int SOC_Recv(int s, void *buf, int len, int flags)
{
    return SOCL_WriteTo(s, buf, len, 0, 0, flags);
}
