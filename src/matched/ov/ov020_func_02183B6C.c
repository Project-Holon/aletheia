/*
 * function: EVENT_MAPCHANGE_CreateByMode
 * address: 0x02183B6C
 * packet: pkt_ov020_02183B6C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_MAPCHANGE_CreateFirstStartEvent 0x02183C34 thumb ov020
 *   EVENT_MAPCHANGE_CreateContinueEvent 0x02183F5C thumb ov020
 *   EVENT_MAPCHANGE_CreateNewGameStartEvent 0x02183D68 thumb ov020
 */
extern void *EVENT_MAPCHANGE_CreateFirstStartEvent(void *owner, void *input);
extern int EVENT_MAPCHANGE_CreateContinueEvent(int a, unsigned char *p);
extern int EVENT_MAPCHANGE_CreateNewGameStartEvent(int a);
void EVENT_MAPCHANGE_CreateByMode(int a, int *p)
{
    switch (*p) {
    case 0: EVENT_MAPCHANGE_CreateFirstStartEvent((void *)a, p); break;
    case 1: EVENT_MAPCHANGE_CreateContinueEvent(a, (unsigned char *)p); break;
    case 2: EVENT_MAPCHANGE_CreateNewGameStartEvent(a); break;
    }
}
