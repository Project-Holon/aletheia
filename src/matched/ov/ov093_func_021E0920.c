/*
 * function: HAND_WAZA_JumpKickCrashOnFail
 * address:  0x021E0920
 * packet:   pkt_ov093_021E0920
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The call passes r3 (d) through to HAND_WAZA_JumpKickDealCrashDamage, whose own C takes three
 * parameters; the prototype here carries the fourth.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   HAND_WAZA_JumpKickDealCrashDamage  0x021E0944  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
extern void HAND_WAZA_JumpKickDealCrashDamage(int a, void *q, int id, int d);

void HAND_WAZA_JumpKickCrashOnFail(int a, void *b, int c, int d)
{
    if (c == BTL_EVENT_GetVar(2))
        HAND_WAZA_JumpKickDealCrashDamage(a, b, c, d);
}
