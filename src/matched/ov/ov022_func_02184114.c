/*
 * function: UNION_APP_Close
 * address:  0x02184114
 * packet:   pkt_02184114
 * region:   ov022
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_NotifyUserEvent  0x0203D1E8  arm
 */

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern void GFL_NET_NotifyUserEvent(u32 unused, void *arg);

int UNION_APP_Close(unsigned char *p)
{
    if (p[4] == 0) {
        GFL_NET_NotifyUserEvent((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0);
        p[9] = 1;
        return 1;
    }
    return 0;
}
