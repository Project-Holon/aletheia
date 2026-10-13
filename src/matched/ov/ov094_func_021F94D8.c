/*
 * function: func_021F94D8
 * address:  0x021F94D8
 * packet:   pkt_ov094_021F94D8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Tears down the owner's work: func_021F97E4, free, then VM_Delete.
 *
 * symbols:
 *   func_02011324 0x02011324 thumb
 *   func_021F97E4 0x021F97E4 thumb ov094
 *   func_020307B0 0x020307B0 arm
 *   VM_Delete 0x02011264 thumb
 */
struct ScriptVm;
extern void *func_02011324(struct ScriptVm *vm);
extern void func_021F97E4(void *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void VM_Delete(void *);

void func_021F94D8(void *a)
{
    void *s = func_02011324(a);
    func_021F97E4(a);
    func_020307B0(s);
    VM_Delete(a);
}
