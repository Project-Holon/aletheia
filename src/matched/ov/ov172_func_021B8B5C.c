/*
 * function: func_021B8B5C
 * address:  0x021B8B5C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two arm9 calls in sequence.
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
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
extern u32 func_0203D1A4(struct Link *p);

void func_021B8B5C(void)
{
    func_0203D1A4((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
}
