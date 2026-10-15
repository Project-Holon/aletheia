/*
 * function: WIFIBATTLEMATCH_NET_SendRegValue
 * address:  0x021DC2C0
 * packet:   pkt_021DC2C0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *
 * Tagged log/emit: the tick from 0x020399A8, the id 0x2405, a length of
 *     4 and the caller's pointer go to 0x0203D3A8, which is the four-argument
 *     form the listing loads straight into r2/r3.
 */

typedef unsigned short u16;
typedef unsigned long u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);

int WIFIBATTLEMATCH_NET_SendRegValue(u32 ignored, void *p)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2405, 4, (u32)p);
}

