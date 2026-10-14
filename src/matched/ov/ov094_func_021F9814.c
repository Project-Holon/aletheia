/*
 * function: BTLV_EFFVM_ClearBlockedFlag
 * address:  0x021F9814
 * packet:   pkt_ov094_021F9814
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears flag bit 7 of the owner's work.
 *
 * symbols:
 *   VM_GetUserData 0x02011324 thumb
 */
extern unsigned *VM_GetUserData(void *);

void BTLV_EFFVM_ClearBlockedFlag(void *a)
{
    *VM_GetUserData(a) &= ~0x80;
}
