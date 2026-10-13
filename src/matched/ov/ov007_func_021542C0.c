/*
 * function: EVENT_BSUBWAY_COMM_Start
 * address:  0x021542C0
 * packet:   pkt_ov007_021542C0
 * region:   ov007
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callback adapter: unpacks a two-word argument block and tail-calls
 * EVENT_BSUBWAY_COMM_CreateEvent (docs/idioms/tail-call-is-a-pool-word-and-bx.md), the twin of
 * ov006 EVENT_WIFICLUB_Entry. Region ov007; Thumb code directly before its pool word.
 * ov021 BSUBWAY_SCR_CmdTool passes it to GAME_EVENT_CreateOverlayEvent with the ov007
 * id (pool word at 0x021CB23C).
 *
 * symbols:
 *   EVENT_BSUBWAY_COMM_CreateEvent  0x021542CC  thumb  ov007
 * Addresses are Black-image addresses.
 */

typedef struct Pair {
    int a;
    int b;
} Pair;

extern void *EVENT_BSUBWAY_COMM_CreateEvent(void *p, int a, int b);

int EVENT_BSUBWAY_COMM_Start(int x, Pair *p)
{
    return (int)EVENT_BSUBWAY_COMM_CreateEvent((void *)x, p->a, p->b);
}
