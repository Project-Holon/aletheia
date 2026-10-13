/*
 * unit:     yes
 * function: BTL_TOKUSEI_ConfusionGuard_ShowBlockedMessage, BTL_TOKUSEI_ConfusionGuard_CureOnEntry, BTL_TOKUSEI_ConfusionGuard_CureOnPeriodicCheck, BTL_TOKUSEI_GetConfusionGuardHandlers
 * address:  0x021D9558
 * packet:   pkt_ov093_021D9558
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_TOKUSEI_ShowSickGuardMessage  0x021D9670  thumb
 *   BTL_TOKUSEI_CureSickIfOwner  0x021D96DC  thumb  ov093
 *   BTL_TOKUSEI_CureSick  0x021D96FC  thumb  ov093
 *   gConfusionGuardHandlers     0x021F0BB4  data   ov093  a4
 */

typedef unsigned short u16;
extern void BTL_TOKUSEI_ShowSickGuardMessage(void *a, void *b, int c, int *d, u16 e);
extern void BTL_TOKUSEI_CureSickIfOwner(int, int, int);
extern void BTL_TOKUSEI_CureSick(void *a, int b, int c);
extern int gConfusionGuardHandlers[];

void BTL_TOKUSEI_ConfusionGuard_ShowBlockedMessage(int a, int b, int c, int d)
{
    BTL_TOKUSEI_ShowSickGuardMessage((void *)a, (void *)b, c, (int *)d, 0x165);
}

void BTL_TOKUSEI_ConfusionGuard_CureOnEntry(int a, int b, int c)
{
    BTL_TOKUSEI_CureSickIfOwner(b, c, 6);
}

void BTL_TOKUSEI_ConfusionGuard_CureOnPeriodicCheck(int a, int b, int c)
{
    BTL_TOKUSEI_CureSick((void *)b, c, 6);
}

int *BTL_TOKUSEI_GetConfusionGuardHandlers(int *p)
{
    *p = 4;
    return gConfusionGuardHandlers;
}
