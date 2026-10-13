/*
 * function: func_021DA434
 * address:  0x021DA434
 * packet:   pkt_021DA434
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWC_RAP_IsStateInSession  0x02156CD0  thumb  ov009
 *   g_021E2C8C     0x021E2C8C  data
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm  arm9
 *   GFL_NET_SendToHandle  0x0203D3A8  arm  arm9
 *
 * Unblocked by matching DWC_RAP_IsStateInSession (ov009, EXACT): the +0002 call site now
 * attests as `matched`.  A live module (non-zero from 0x02156CD0) takes the
 * 0x020399A8 handle into 0x0203D3A8 as the 0x2402/4 entry of the 0x021E2C8C
 * block, anything else reports 1.
 */

typedef unsigned short u16;
typedef unsigned long u32;

extern int DWC_RAP_IsStateInSession(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 g_021E2C8C[];

int func_021DA434(void)
{
    if (DWC_RAP_IsStateInSession() != 0)
        return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2402, 4, (u32)g_021E2C8C);
    return 1;
}

