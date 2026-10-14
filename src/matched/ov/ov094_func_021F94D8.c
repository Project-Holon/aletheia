/*
 * function: BTLV_EFFVM_Destroy
 * address:  0x021F94D8
 * packet:   pkt_ov094_021F94D8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Tears down the owner's work: BTLV_EFFVM_StopScript, free, then VM_Delete.
 *
 * symbols:
 *   VM_GetUserData 0x02011324 thumb
 *   BTLV_EFFVM_StopScript 0x021F97E4 thumb ov094
 *   func_020307B0 0x020307B0 arm
 *   VM_Delete 0x02011264 thumb
 */
struct ScriptVm;
extern void *VM_GetUserData(struct ScriptVm *vm);
extern void BTLV_EFFVM_StopScript(void *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void VM_Delete(void *);

void BTLV_EFFVM_Destroy(void *a)
{
    void *s = VM_GetUserData(a);
    BTLV_EFFVM_StopScript(a);
    func_020307B0(s);
    VM_Delete(a);
}
