/*
 * function: C_GEAR_DeleteActorSlots
 * address: 0x021F30C8
 * packet: pkt_ov029_021F30C8
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
struct Slot { void *object; int a; int b; };
struct Obj { char pad[0x3c]; struct Slot slots[20]; };
void C_GEAR_DeleteActorSlots(struct Obj *p)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (p->slots[i].object) {
            CLACT_DeleteActor(p->slots[i].object);
            p->slots[i].object = 0;
        }
    }
}
