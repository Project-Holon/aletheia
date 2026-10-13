/*
 * function: func_021DA36C
 * address:  0x021DA36C
 * packet:   pkt_021DA36C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_STATE_WifiDisconnect  0x0203C554  arm
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *
 * Three-call init/reset sequence: 0x0203D7B0(0), 0x0203D7BC(0) and
 *     0x0203C554(1).
 */

typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void func_0203D7BC(u8 a0);
typedef unsigned int   u32;
extern void GFL_NET_STATE_WifiDisconnect(u32 a);

void func_021DA36C(void)
{
    GFL_NET_SetAutoExit(0);
    func_0203D7BC(0);
    GFL_NET_STATE_WifiDisconnect(1);
}

