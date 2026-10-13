/*
 * function: SOC_Send
 * address:  0x0215f590
 * packet:   pkt_ov009_0215F590
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_Send (soc.o)
 *
 * note:     soc.o order: SOC_RecvFrom (0x0215F500, 144 bytes) ends here and
 *           SOC_SendTo follows at +36; the call goes to SOCL_WriteTo, as
 *           SOC_Send does (SOC_Recv calls SOCL_ReadFrom).
 *
 * symbols:
 *   SOCL_WriteTo   0x0215e024 arm
 */

extern int SOCL_WriteTo(int s, void *buffer, int buffer_len,
                        unsigned short remote_port, unsigned long remote_ip,
                        int flags);

int SOC_Send(int s, void *buf, int len, int flags)
{
    return SOCL_WriteTo(s, buf, len, 0, 0, flags);
}
