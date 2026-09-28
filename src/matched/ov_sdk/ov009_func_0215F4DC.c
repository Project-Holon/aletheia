/*
 * function: SOC_Recv
 * address:  0x0215f4dc
 * packet:   pkt_ov009_0215F4DC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_Recv (soc.o)
 *
 * symbols:
 *   SOCL_ReadFrom   0x0215d6c8 arm
 */

extern int SOCL_ReadFrom(int s, void *buffer, int buffer_len,
                         unsigned short *remote_port, unsigned long *remote_ip,
                         int flags);

int SOC_Recv(int s, void *buf, int len, int flags)
{
    return SOCL_ReadFrom(s, buf, len, 0, 0, flags);
}
