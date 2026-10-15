/*
 * function: POKETRADE_DEMO_COMMON_StepWaitSync
 * address:  0x021D4520
 * packet:   pkt_ov117_021D4520
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_DEMO_COMMON_StepStartSlides  0x021D4544  thumb  ov117
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *h, u32 a, u32 b);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_DEMO_COMMON_StepStartSlides(u8 *p);

void POKETRADE_DEMO_COMMON_StepWaitSync(u8 *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 8) != 0) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_COMMON_StepStartSlides);
    }
}
