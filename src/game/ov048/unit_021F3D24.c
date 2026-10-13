/*
 * file:     unit_021F3D24.c
 * function: FIELD_GIMMICK_GATE_HasNewsEntry
 * address:  0x021F3D24
 * packet:   pkt_ov048_021F3D24
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      FIELD_GIMMICK_GATE_HasNewsEntry (libdwcaccount.TWL.HYB.thumb.a(dwc_account.o))
 *
 * symbols:
 *   FIELD_GIMMICK_GATE_FindNewsEntry  0x021F3C2C  thumb  ov048
 */

extern unsigned long FIELD_GIMMICK_GATE_FindNewsEntry(void *userdata);

int FIELD_GIMMICK_GATE_HasNewsEntry(void *frienddata)
{
    if (FIELD_GIMMICK_GATE_FindNewsEntry(frienddata))
        return 1;
    return 0;
}
