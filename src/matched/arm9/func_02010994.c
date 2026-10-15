/*
 * function: GFL_NET_SAVE_StepWaitSync72
 * address:  0x02010994
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepWaitSync72.c \
 *       --func GFL_NET_SAVE_StepWaitSync72 --addr 0x02010994 --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_SAVE_SetStep  0x02010888  thumb
 *   GFL_NET_SAVE_StepDelay  0x020109B8  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
extern void GFL_NET_SAVE_SetStep(u8 *p, u32 v);
extern void GFL_NET_SAVE_StepDelay(u8 *p);

void GFL_NET_SAVE_StepWaitSync72(u8 *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x72, 8) != 0) {
        GFL_NET_SAVE_SetStep(p, (u32)GFL_NET_SAVE_StepDelay);
    }
}
