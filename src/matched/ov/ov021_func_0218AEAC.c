/*
 * function: FIELD_EVENT_CHECK_IsConnectOnFootType
 * address:  0x0218AEAC
 * packet:   pkt_ov021_0218AEAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * True when EVENTDATA_SYSTEM_GetConnectExitType reports kind 0, 5 or 6.
 *
 * symbols:
 *   EVENTDATA_SYSTEM_GetConnectExitType  0x021626E8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u8 EVENTDATA_SYSTEM_GetConnectExitType(u8 *p);

int FIELD_EVENT_CHECK_IsConnectOnFootType(u8 *p)
{
    u8 v = EVENTDATA_SYSTEM_GetConnectExitType(p);
    return v == 0 || v == 5 || v == 6;
}
