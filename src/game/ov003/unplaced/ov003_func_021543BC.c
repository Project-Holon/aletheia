/*
 * function: func_021543BC
 * address:  0x021543BC
 * packet:   pkt_ov003_021543BC
 * region:   ov003
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf callback (tail call through a pool word), sole blocker of
 * ov010 func_0215CCE8's MATCH.
 *
 * symbols:
 *   func_0215437C  0x0215437C  thumb  ov003
 */

typedef struct { unsigned fieldMap; unsigned procKind; } LaunchRequest;

extern void *func_0215437C(void *gameSystem, int fieldMap, int procKind);

/* Overlay entry point: unpacks the request and creates the event. */
void *func_021543BC(void *gameSystem, LaunchRequest *request)
{
    return func_0215437C(gameSystem, request->fieldMap, request->procKind);
}
