/*
 * function: BSUBWAY_COMM_CheckTimingSync
 * address:  0x02167B34
 * packet:   pkt_02167B34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_CheckTimingSync  0x0203D5A0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Entry;

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_CheckTimingSync();

int BSUBWAY_COMM_CheckTimingSync(int a0)
{
    int a1;
    int t4;
    struct Entry *e;

t4 = a0 + 0;
    e = GFL_NET_HANDLE_GetCurrentHandle();
loc_02167B3C:
a1 = t4 + 0;
    a0 = GFL_NET_CheckTimingSync(e, a1);
loc_02167B42:
    return a0;}
