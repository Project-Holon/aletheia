/*
 * unit:     yes
 * function: MONOLITH_TOOL_DeleteActorAt, MONOLITH_TOOL_Noop
 * address:  0x021B7168
 * packet:   pkt_ov071_021B7168
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * ARM9 tail call followed by an empty function.
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 */

struct Obj;
void MONOLITH_TOOL_DeleteActorAt(void *p)
{
    void CLACT_DeleteActor(struct Obj *p);
    CLACT_DeleteActor(p);
}

void MONOLITH_TOOL_Noop(void *a)
{
}
