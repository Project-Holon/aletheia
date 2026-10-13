/*
 * function: GFL_NET_DEVWIFI_PollDisconnect
 * address:  0x02155244
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Feeds the inverted argument to DWC_RAP_ProgressDisconnect and reports 1 when it accepts.
 *
 * symbols:
 *   DWC_RAP_ProgressDisconnect  0x02156690  thumb  ov009
 *   DWC_RAP_ResetToIdle  0x02156730  thumb  ov009

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int GFL_NET_DEVWIFI_PollDisconnect(int x)
{
    int DWC_RAP_ProgressDisconnect(int);
    int DWC_RAP_ResetToIdle(void);
    int t;
    if (x == 0) t = 1;
    else t = 0;
    if (DWC_RAP_ProgressDisconnect(t)) {
        DWC_RAP_ResetToIdle();
        return 1;
    }
    return 0;
}
