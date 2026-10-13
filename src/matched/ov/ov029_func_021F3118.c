/*
 * function: C_GEAR_StepWaitSlots
 * address: 0x021F3118
 * packet: pkt_ov029_021F3118
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: caller sets r2=0x1514 despite two-input thunk/leaf; retained
 * in the caller extern to reproduce original argument setup.
 * symbols:
 *   C_GEAR_RunFrame 0x021F2130 thumb ov029
 *   C_GEAR_AreActorSlotsIdle 0x021F30EC thumb ov029
 *   C_GEAR_DeleteActorSlots 0x021F30C8 thumb ov029
 *   C_GEAR_ChangeStep 0x021EFEF8 thumb ov029
 *   C_GEAR_StepIdle 0x021F2180 thumb ov029
 */
struct Obj;
extern void C_GEAR_RunFrame(char *p);
extern int C_GEAR_AreActorSlotsIdle(struct Obj *p);
extern void C_GEAR_DeleteActorSlots(struct Obj *p);
extern void C_GEAR_ChangeStep(char *p, void (*f)(void), int line);
extern void C_GEAR_StepIdle(char *p);
void C_GEAR_StepWaitSlots(void *p)
{
    C_GEAR_RunFrame(p);
    if (C_GEAR_AreActorSlotsIdle(p)) {
        C_GEAR_DeleteActorSlots(p);
        C_GEAR_ChangeStep(p, (void (*)(void))C_GEAR_StepIdle, 0x1514);
    }
}
