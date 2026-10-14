/*
 * function: GURU2_MAIN_StepAngle
 * address: 0x021DF22C
 * packet: pkt_ov137_021DF22C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gGuru2PointerAngleTable 0x021E1FDC data a2
 *   GURU2_MAIN_BroadcastResult 0x021E19C0 thumb ov137
 *   GURU2_MAIN_AddAngleWrapped 0x021E15DC thumb ov137
 *
 * note 2026-10-05 (wave P17 L7, final push G6L7): DIFF 26/116, obj/step/target colour
 * rotation and index load order; about 60 forms tried (see git history of the pending copy).
 *
 * pass 2 2026-10-06 P2L39: EXACT in --lang c99 and --lang c. Under #pragma opt_propagation
 * off, all locals declared at the top (target before step), with step assigned before
 * target: this gives obj r6, step r5, target r4. A named table pointer local assigned first
 * keeps the table load live across the multiply (table r4), which lets count be a named
 * local without a copy before muls. The reads in the order index, selected, count, angle
 * give the low colours (angle r1, count r2, index r3).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u8 pad[28]; int angle;} Selected;
typedef struct { int state; u8 pad[36]; Selected *selected; int index, count; } Obj;
extern u16 gGuru2PointerAngleTable[][5];
extern void GURU2_MAIN_BroadcastResult(char *r4, int r5);
extern void GURU2_MAIN_AddAngleWrapped(int *, int);
#pragma opt_propagation off
int GURU2_MAIN_StepAngle(Obj *obj)
{
    Selected *sel;
    int current, index, count;
    int target, step;
    int angle, delta;
    u16 (*table)[5];
    table = gGuru2PointerAngleTable;
    index = obj->index;
    sel = obj->selected;
    count = obj->count;
    current = sel->angle;
    step = 0x4000;
    target = table[count][index] << 12;
    angle = current;
    delta = target - current;
    if (delta < 0) delta = target + 0x168000 - current;
    if (delta <= 0x10000) step >>= 1;
    if (delta < step) step = delta;
    GURU2_MAIN_BroadcastResult((char *)obj, step);
    GURU2_MAIN_AddAngleWrapped(&angle, step);
    if (angle / 4096 == target / 4096) obj->state = 31;
    return 0;
}
#pragma opt_propagation reset
