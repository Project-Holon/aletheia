/*
 * unit:     no
 * function: GFL_NET_HANDLE_RequestNegotiation
 * address:  0x02039A2C
 * packet:   pkt_020399B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 */

typedef signed int     s32;
typedef unsigned short u16;
struct Entry;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
void GFL_NET_HANDLE_RequestNegotiation(int a)
{
    char *q;
    if (GFL_NET_SYSTEM_GetCurrentAid())
        return;
    q = (char *)GFL_NET_HANDLE_GetNetHandle(0xff) + a * 2;
    q[0x2c] = (char)a;
    q[0x2d] = 1;
}
