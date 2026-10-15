/*
 * function: HandlePacket
 * address:  0x0217C848
 * packet:   pkt_ov009_0217C848
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      HandlePacket (gsavailable.o)
 *
 * symbols:
 *   func_020923F0                  0x020923F0  arm
 *   gGsAvailableCheck                     0x021ACF7C  data
 *   g_021ACF84                     0x021ACF84  data
 *   gGsAvailableMagic                     0x021A370C  data
 */

struct SOCSockAddrIn { unsigned char len; unsigned char family; unsigned short port; unsigned long addr; };
typedef unsigned char  u8;
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern unsigned short gGsAvailableCheck[];
extern unsigned char g_021ACF84[];
extern char gGsAvailableMagic[];

int HandlePacket(char *packet, int len, struct SOCSockAddrIn *address, int *disabledservices)
{
    int bitfield;
    if (len < 7)
        return 1;
    if (func_020923F0((const u8 *)(&address->addr), g_021ACF84, 4) != 0)
        return 1;
    if (address->port != gGsAvailableCheck[3])
        return 1;
    if (func_020923F0((const u8 *)packet, (const u8 *)gGsAvailableMagic, 3) != 0)
        return 1;
    bitfield = (packet[3] << 24) & 0xff000000;
    bitfield |= (packet[4] << 16) & 0xff0000;
    bitfield |= (packet[5] << 8) & 0xff00;
    bitfield |= (unsigned char)packet[6];
    *disabledservices = bitfield;
    return 0;
}
