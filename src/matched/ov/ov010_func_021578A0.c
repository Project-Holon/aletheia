/*
 * function: DELIVERY_BEACON_Start
 * address:  0x021578A0
 * packet:   pkt_ov010_021578A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   DELIVERY_BEACON_CheckDestSize  0x02157700  thumb  ov010
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   DELIVERY_BEACON_SetStepAtLine  0x021576C4  thumb  ov010
 *   DELIVERY_BEACON_OnSessionStarted  0x0215788C  thumb  ov010
 *   DELIVERY_BEACON_StepIdle  0x021576CC  thumb  ov010
 *   d_021727E0  0x021727E0  data  ov010
 *   d_02172780  0x02172780  data  ov010
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int GFL_NET_GetRunState(void);
extern void DELIVERY_BEACON_CheckDestSize(int *p);
struct Req;
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern void DELIVERY_BEACON_SetStepAtLine(char *p, int v, int line);
extern void DELIVERY_BEACON_OnSessionStarted(void *p);
extern void DELIVERY_BEACON_StepIdle(void);
extern u8 d_021727E0[];
extern u8 d_02172780[];

int DELIVERY_BEACON_Start(u32 *p)
{
    if (GFL_NET_GetRunState() != 0)
        return 0;
    d_021727E0[7] = *p;
    *((u8 *)p + 0x31B8) = 0xFF;
    DELIVERY_BEACON_CheckDestSize((int *)p);
    GFL_NET_StartSession((struct Req *)d_02172780, (u32)DELIVERY_BEACON_OnSessionStarted, (u32)p);
    DELIVERY_BEACON_SetStepAtLine((char *)p, (int)DELIVERY_BEACON_StepIdle, 0x1F2);
    return 1;
}
