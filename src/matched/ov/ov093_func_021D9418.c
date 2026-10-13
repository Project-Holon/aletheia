/*
 * unit:     yes
 * function: HAND_TOKUSEI_SleepGuard_CheckAdd, HAND_TOKUSEI_SleepGuard_CureOnEntry, HAND_TOKUSEI_SleepGuard_CureOnPeriodicCheck
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
 *   HAND_TOKUSEI_BlockSickIfTargeted  0x021D9648  thumb  ov093
 *   HAND_TOKUSEI_CureSickIfOwner  0x021D96DC  thumb  ov093
 *   HAND_TOKUSEI_CureSick  0x021D96FC  thumb  ov093
 */

extern int HAND_TOKUSEI_BlockSickIfTargeted(int, int, int);
extern void HAND_TOKUSEI_CureSickIfOwner(int, int, int);
extern void HAND_TOKUSEI_CureSick(void *a, int b, int c);

void HAND_TOKUSEI_SleepGuard_CheckAdd(int a, int b, int c, int *out)
{
    int r;

    r = HAND_TOKUSEI_BlockSickIfTargeted(b, c, 2);
    *out = r;
    if (r == 0)
        *out = HAND_TOKUSEI_BlockSickIfTargeted(b, c, 0xe);
}

void HAND_TOKUSEI_SleepGuard_CureOnEntry(int a, int b, int c)
{
    HAND_TOKUSEI_CureSickIfOwner(b, c, 2);
}

void HAND_TOKUSEI_SleepGuard_CureOnPeriodicCheck(int a, int b, int c)
{
    HAND_TOKUSEI_CureSick((void *)b, c, 2);
}
