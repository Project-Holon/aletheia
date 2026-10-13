/*
 * function: C_GEAR_AreActorSlotsIdle
 * address: 0x021F30EC
 * packet: pkt_ov029_021F30EC
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 */
typedef unsigned int   u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
struct Slot { void *object; int a; int b; };
struct Obj { char pad[0x3c]; struct Slot slots[20]; };
int C_GEAR_AreActorSlotsIdle(struct Obj *p)
{
    int result = 1;
    int i;
    for (i = 0; i < 20; i++) {
        if (p->slots[i].object) {
            if (CLACT_IsActorAnimActive(p->slots[i].object)) {
                result = 0;
                break;
            }
        }
    }
    return result;
}
