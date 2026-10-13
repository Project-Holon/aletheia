/*
 * function: func_0215E334
 * address:  0x0215E334
 * packet:   pkt_0215E334
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Thumb tail call into ENV_SetResourceSet (ARM, 0x020307B0): `ldr r3,
 * [pc, #0]; bx r3` plus the pool word, the shape of the arm9 copy
 * VM_Delete.  Unlabelled in the listing (no prologue, called only from
 * arm9), so it is emitted as data words.
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_0215E334(void *ptr)
{
    func_020307B0(ptr);
}
