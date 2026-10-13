/*
 * function: ISS_SWITCH_SYS_CheckZoneChange
 * address:  0x0202C218
 * packet:   pkt_0202C218
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the record through ISS_SWITCH_SYS_TurnOff when the object is live and the
 * lookup fails.  Unlabelled in the listing (no lr save of its own beyond the
 * callee-saved set) and absent from the worklist; filed from the bytes.  It is
 * the tail-call target of the thunk at 0x0202C0C8, which is what
 * src/pending/ISS_SYS_OnZoneChangeSwitch.c is blocked on.
 *
 * symbols:
 *   sub_0202C2D8  0x0202C2D8  thumb
 *   ISS_SWITCH_SYS_IsActiveSetZone  0x0202C250  thumb
 *   ISS_SWITCH_SYS_ResetActiveSet  0x0202C2DC  thumb
 *   ISS_SWITCH_SYS_TurnOff  0x0202C204  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_CheckZoneChange.c \
 *       --func ISS_SWITCH_SYS_CheckZoneChange --addr 0x0202C218 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

extern u32  sub_0202C2D8(u32 *p);
extern u32  ISS_SWITCH_SYS_IsActiveSetZone(u32 *p, u32 v);
extern void ISS_SWITCH_SYS_ResetActiveSet(void *p);
extern void ISS_SWITCH_SYS_TurnOff(u32 *p);

void ISS_SWITCH_SYS_CheckZoneChange(u32 *p, u32 v)
{
    if (sub_0202C2D8(p) == 0) {
        return;
    }
    if (ISS_SWITCH_SYS_IsActiveSetZone(p, v) != 0) {
        return;
    }
    ISS_SWITCH_SYS_ResetActiveSet(p);
    ISS_SWITCH_SYS_TurnOff(p);
}
