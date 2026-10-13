/*
 * function: func_02154C20
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
 * ov021 func_021B4C54 passes it as a function pointer together with the block
 * {func_0201210C(..), 0} (wave A1 witness).
 *
 * symbols:
 *   EVENT_WIFICLUB_Create  0x02154BF8  thumb  ov006
 * Addresses are Black-image addresses.
 */

typedef struct Pair {
    int a;
    int b;
} Pair;

extern int EVENT_WIFICLUB_Create(int gameSystem, int b, int c);

/* Overlay entry point: unpacks the request pair and creates the event. */
int func_02154C20(int gameSystem, Pair *request)
{
    return EVENT_WIFICLUB_Create(gameSystem, request->a, request->b);
}
