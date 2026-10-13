/*
 * function: ISS_CITY_SYS_Create
 * address:  0x0202AAF4
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker ISS_CITY_SYS_InitUnits.c is now a manifest entry (matched class)
 *
 * Allocates a 0x1c-byte node with the allocator entry point and runs the
 * two initialisers ISS_CITY_SYS_InitState and ISS_CITY_SYS_InitUnits over it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_SYS_Create.c \
 *       --func ISS_CITY_SYS_Create --addr 0x0202AAF4 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_CITY_SYS_InitState  0x0202AB64  thumb
 *   ISS_CITY_SYS_InitUnits  0x0202AB7C  thumb
 */

typedef unsigned int u32;

struct Node;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void ISS_CITY_SYS_InitState(void *obj, u32 unused, u32 value);
extern void ISS_CITY_SYS_InitUnits(struct Node *p, void *heapId);

struct Node *ISS_CITY_SYS_Create(u32 a, void *heapId)
{
    struct Node *p = (struct Node *)func_02030734((u32)heapId, 0x1c, 0,
                                                  (const void *)0x020A76E8, 0x92);

    ISS_CITY_SYS_InitState(p, (u32)heapId, a);
    ISS_CITY_SYS_InitUnits(p, heapId);
    return p;
}
