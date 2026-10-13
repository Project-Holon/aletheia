/*
 * unit:     yes
 * function: BTL_TOKUSEI_SleepGuard_CheckAdd, BTL_TOKUSEI_SleepGuard_CureOnEntry, BTL_TOKUSEI_SleepGuard_CureOnPeriodicCheck
 * address:  0x021D9418
 * packet:   pkt_ov093_021D9418
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_TOKUSEI_BlockSickIfTargeted  0x021D9648  thumb  ov093
 *   BTL_TOKUSEI_CureSickIfOwner  0x021D96DC  thumb  ov093
 *   BTL_TOKUSEI_CureSick  0x021D96FC  thumb  ov093
 */

extern int BTL_TOKUSEI_BlockSickIfTargeted(int, int, int);
extern void BTL_TOKUSEI_CureSickIfOwner(int, int, int);
extern void BTL_TOKUSEI_CureSick(void *a, int b, int c);

void BTL_TOKUSEI_SleepGuard_CheckAdd(int a, int b, int c, int *out)
{
    int r;

    r = BTL_TOKUSEI_BlockSickIfTargeted(b, c, 2);
    *out = r;
    if (r == 0)
        *out = BTL_TOKUSEI_BlockSickIfTargeted(b, c, 0xe);
}

void BTL_TOKUSEI_SleepGuard_CureOnEntry(int a, int b, int c)
{
    BTL_TOKUSEI_CureSickIfOwner(b, c, 2);
}

void BTL_TOKUSEI_SleepGuard_CureOnPeriodicCheck(int a, int b, int c)
{
    BTL_TOKUSEI_CureSick((void *)b, c, 2);
}
