/*
 * function: GFL_NET_DEVWIFI_UpdateDisconnect
 * address:  0x021551DC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Null-pointer guard through DWC_RAP_ProgressDisconnect, then either DWC_RAP_ResetToIdle or DWC_RAP_RunStateMachine.
 *
 * symbols:
 *   DWC_RAP_ProgressDisconnect  0x02156690  thumb  ov009
 *   DWC_RAP_ResetToIdle  0x02156730  thumb  ov009
 *   DWC_RAP_RunStateMachine  0x0215592C  thumb  ov009

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int GFL_NET_DEVWIFI_UpdateDisconnect(void *p)
{
    int DWC_RAP_ProgressDisconnect(int);
    int DWC_RAP_ResetToIdle(void);
    int DWC_RAP_RunStateMachine(int a);
    int t;
    if (p == 0) t = 1;
    else t = 0;
    if (DWC_RAP_ProgressDisconnect(t)) {
        DWC_RAP_ResetToIdle();
        return 1;
    }
    DWC_RAP_RunStateMachine((int)p);
    return 1;
}
