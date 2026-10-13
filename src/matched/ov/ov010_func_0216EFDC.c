/*
 * function: EVENT_BATTLE_IsTaskResultSilent
 * address:  0x0216EFDC
 * packet:   pkt_ov010_0216EFDC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     2026-10-05 wave P19 lane 6: tiny unlabelled tail-call leaf filed as
 *           the witness for the calls in ov010 EVENT_BATTLE_ProcBattleTask. Reads the info
 *           block at w[2] and tail-calls EVENT_BATTLE_IsResultSilent(info[0x8c / 4], info[0]).
 *
 * symbols:
 *   EVENT_BATTLE_IsResultSilent  0x0216EFA8  thumb  ov010
 */
extern int EVENT_BATTLE_IsResultSilent(int a, int b);

int EVENT_BATTLE_IsTaskResultSilent(int *w)
{
    int *q = (int *)w[2];
    return EVENT_BATTLE_IsResultSilent(q[0x8c / 4], q[0]);
}
