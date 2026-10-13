/*
 * function: func_021D9404
 * address:  0x021D9404
 * packet:   pkt_ov119_021D9404
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *
 * Byte-identical twin of func_021D93D4 (same 12-byte predicate stub).
 */

typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);

void func_021D9404(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if ((u32)GFL_NET_HANDLE_GetCurrentHandle() == e)
        return;
}
