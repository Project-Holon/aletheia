/*
 * function: ISS_CITY_SYS_InitUnits
 * address:  0x0202AB7C
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker ISS_CITY_SYS_InitUnits.c is now a manifest entry (matched class)
 *
 * A bare tail-call thunk to ISS_CITY_SYS_LoadUnits.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_SYS_InitUnits.c \
 *       --func ISS_CITY_SYS_InitUnits --addr 0x0202AB7C --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_CITY_SYS_LoadUnits  0x0202AB8C  thumb
 */

struct A;
extern void ISS_CITY_SYS_LoadUnits(struct A *a0, void *a1);

struct Node;

void ISS_CITY_SYS_InitUnits(struct Node *p, void *heapId)
{
    ISS_CITY_SYS_LoadUnits((struct A *)p, heapId);
}
