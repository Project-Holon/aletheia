/*
 * function: BTLV_EFFVM_StopLiveSounds
 * address:  0x021F9A7C
 * packet:   pkt_ov094_021F9A7C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Stops every live sound slot of the owner's work (six words at 0x26c, -1 = free).
 *
 * symbols:
 *   VM_GetUserData 0x02011324 thumb
 *   PM_VOICE_StopSlot 0x02006BB4 thumb
 */
typedef unsigned int   u32;
struct ScriptVm;
extern void *VM_GetUserData(struct ScriptVm *vm);
extern void PM_VOICE_StopSlot(u32 i);

void BTLV_EFFVM_StopLiveSounds(void *a)
{
    char *s = VM_GetUserData(a);
    int i;

    for (i = 0; i < 6; i++) {
        if (((int *)(s + 0x26c))[i] != -1)
            PM_VOICE_StopSlot(((int *)(s + 0x26c))[i]);
    }
}
