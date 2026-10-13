/*
 * function: EVENT_BATTLE_REC_SAVE_Start
 * address: 0x021550A0
 * packet: pkt_ov008_021550A0
 * region: ov008
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_BATTLE_REC_SAVE_CreateEvent 0x021550B0 thumb ov008
 */
extern void *EVENT_BATTLE_REC_SAVE_CreateEvent(void *, int, int, int);
void *EVENT_BATTLE_REC_SAVE_Start(void *a, const int *p)
{
    return EVENT_BATTLE_REC_SAVE_CreateEvent(a, p[0], p[1], p[2]);
}
