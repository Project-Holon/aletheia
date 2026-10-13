/*
 * function: func_02154438
 * address:  0x02154438
 * packet:   pkt_ov002_02154438
 * region:   ov002
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021543E8  0x021543E8  thumb  ov002
 */

typedef int s32;

extern void *func_021543E8(void *gameSystem, int fieldMap, int entryMode, int ratedFlag, int matchKind);

/* Overlay entry point: unpacks the four-word request and creates the event. */
void func_02154438(s32 gameSystem, s32 *request)
{
    func_021543E8((void *)gameSystem, request[0], request[1], request[2], request[3]);
}
