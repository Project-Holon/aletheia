/*
 * function: ISS_SWITCH_SET_Create
 * address:  0x0202C2EC
 * packet:   pkt_0202C2EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Closed: ISS_SWITCH_SET_Alloc became an EXACT manifest entry, so the matched class attests the call at 0x0202C2F0.
 *
 * symbols:
 *   ISS_SWITCH_SET_Init  0x0202C360  thumb
 *   ISS_SWITCH_SET_Alloc  0x0202C384  thumb
 *   ISS_SWITCH_SET_CreateSwitches  0x0202C3A8  thumb
 */

typedef unsigned int u32;

extern void *ISS_SWITCH_SET_Alloc(void *heap);
struct Obj0202C360;
extern void ISS_SWITCH_SET_Init(struct Obj0202C360 *p);
extern void ISS_SWITCH_SET_CreateSwitches(char *p, int a1);

u32 ISS_SWITCH_SET_Create(void *heap)
{
    u32 r = (u32)ISS_SWITCH_SET_Alloc(heap);

    ISS_SWITCH_SET_Init((void *)r);
    ISS_SWITCH_SET_CreateSwitches((char *)r, (int)heap);
    return r;
}
