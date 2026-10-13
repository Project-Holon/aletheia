/*
 * function: COLOSSEUM_ResetParties
 * address:  0x02175240
 * packet:   pkt_ov012_02175240
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   POKEPARTY_Init  0x0201A948  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
struct Party;
extern void POKEPARTY_Init(struct Party *p);

void COLOSSEUM_ResetParties(u8 *a, int b)
{
    int self;
    int i;

    self = GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    for (i = 0; i < 4; i++) {
        if (b == 0 || self != i) {
            POKEPARTY_Init(*(void **)(a + i * 4 + 0x148));
        }
        a[i + 0x158] = 0;
    }
}
