/*
 * function: POKETRADE_PROC_RecvIgnoredA
 * address:  0x021D93D4
 * packet:   pkt_ov119_021D93D4
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 */

typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);

void POKETRADE_PROC_RecvIgnoredA(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if ((u32)GFL_NET_HANDLE_GetCurrentHandle() == e)
        return;
}
