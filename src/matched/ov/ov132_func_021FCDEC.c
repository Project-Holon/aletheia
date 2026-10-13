/*
 * function: func_021FCDEC
 * address:  0x021FCDEC
 * packet:   pkt_021FCDEC
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *
 * Addresses are Black-image addresses.
 */

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *, unsigned int, unsigned int);

void func_021FCDEC(int a, int b)
{
    func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), b, 0x11);
}
