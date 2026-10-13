/*
 * function: func_021B8B48
 * address:  0x021B8B48
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * arm9 call whose result is the first argument of the second call.
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *a, u32 b, u32 c);

int func_021B8B48(void *p, u32 a, u32 b)
{
    return GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), b, 0x20);
}
