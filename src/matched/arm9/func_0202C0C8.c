/*
 * function: ISS_SWITCH_SYS_ZoneChange
 * address:  0x0202C0C8
 * packet:   pkt_0202C148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An eight-byte tail-call thunk into ISS_SWITCH_SYS_CheckZoneChange.  Unlabelled in the listing
 * and absent from the worklist; filed from the bytes.  src/pending/
 * ISS_SYS_OnZoneChangeSwitch.c is blocked on this address and now has it as a `matched`
 * witness.
 *
 * symbols:
 *   ISS_SWITCH_SYS_CheckZoneChange  0x0202C218  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_ZoneChange.c \
 *       --func ISS_SWITCH_SYS_ZoneChange --addr 0x0202C0C8 --thumb --cc 1.1p1
 */

extern void ISS_SWITCH_SYS_CheckZoneChange(void);

void ISS_SWITCH_SYS_ZoneChange(void)
{
    ISS_SWITCH_SYS_CheckZoneChange();
}
