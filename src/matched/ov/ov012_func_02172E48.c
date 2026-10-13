/*
 * function: UNION_COMM_Update
 * address:  0x02172E48
 * packet:   pkt_ov012_02172E48
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   UNION_COMM_UpdateReset  0x02172D7C  thumb  ov012
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   func_0217778C  0x0217778C  thumb  ov014
 *   UNION_COMM_UpdateBeaconScan  0x021730C8  thumb  ov012
 *   UNION_COMM_UpdateColosseum  0x0217303C  thumb  ov012
 *   UNION_COMM_SendEntryReplies  0x02172FF0  thumb  ov012
 *   UNION_COMM_UpdateConnectSync  0x02172EEC  thumb  ov012
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   UNION_COMM_RequestShutdown  0x02172D38  thumb  ov012
 */

typedef unsigned char u8;

typedef struct {
    u8 pad[0xC8];
    u8 f0 : 1;
    u8 f1 : 1;
} Obj;

typedef struct {
    u8 pad[0x2829];
    u8 f2829;
    u8 pad2[0x2831 - 0x282A];
    u8 f2831;
    u8 pad3[0x355C - 0x2832];
    Obj *obj;
} Work;

extern int UNION_COMM_UpdateReset(u8 *p);
extern int GFL_NET_GetRunState(void);
extern void func_0217778C(void);
extern void UNION_COMM_UpdateBeaconScan(u8 *self);
extern void UNION_COMM_UpdateColosseum(Work *w);
extern void UNION_COMM_SendEntryReplies(u8 *w);
extern void UNION_COMM_UpdateConnectSync(Work *w);
typedef unsigned int   u32;
extern u32 func_0200FB24(void);
extern u32 GFL_NET_IsParentAid(void);
extern void UNION_COMM_RequestShutdown(u8 *p);

void UNION_COMM_Update(int a, int b, Work *w)
{
    if (UNION_COMM_UpdateReset((u8 *)w) == 1) {
        return;
    }
    if (GFL_NET_GetRunState() == 0) {
        return;
    }
    if (w->f2829 == 1) {
        func_0217778C();
        w->f2829 = 0;
    }
    UNION_COMM_UpdateBeaconScan((u8 *)w);
    UNION_COMM_UpdateColosseum(w);
    UNION_COMM_SendEntryReplies((u8 *)w);
    UNION_COMM_UpdateConnectSync(w);
    if (func_0200FB24() != 0 && GFL_NET_IsParentAid() == 1 && w->obj != 0
        && w->obj->f0 == 1 && w->f2831 == 0x2a && w->obj->f1 == 0) {
        UNION_COMM_RequestShutdown((u8 *)w);
        w->obj->f1 = 1;
    }
}
