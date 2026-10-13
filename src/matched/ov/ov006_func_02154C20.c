/*
 * function: EVENT_WIFICLUB_Entry
 * address:  0x02154C20
 * packet:   pkt_ov006_02154C20
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callback adapter: unpacks a two-word argument block and tail-calls
 * EVENT_WIFICLUB_Create (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Region
 * ov006: the only overlay mapped at this address; Thumb code directly after
 * the pool word of EVENT_WIFICLUB_Create, which is also its tail-call target.
 * ov021 SCRCMD_PROC_FLD_CallOv006Event passes it as a function pointer together with the block
 * {GAMESYSTEM_GetFieldMap(..), 0} (wave A1 witness).
 *
 * symbols:
 *   EVENT_WIFICLUB_Create  0x02154BF8  thumb  ov006
 * Addresses are Black-image addresses.
 */

typedef struct Pair {
    int a;
    int b;
} Pair;

extern int EVENT_WIFICLUB_Create(int a, int b, int c);

int EVENT_WIFICLUB_Entry(int x, Pair *p)
{
    return EVENT_WIFICLUB_Create(x, p->a, p->b);
}
