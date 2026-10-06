/*
 * function: func_02021540
 * address:  0x02021540
 * packet:   pkt_02021540
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf: a bare tail call to func_020307B0 with no arguments
 * (`ldr r3,[pc,#0]; bx r3`; the pool word names 0x020307B0).  Disasm.py gave
 * it no func_ label because it has no prologue.
 *
 * symbols:
 *   func_02021540  0x02021540  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_02021540(void *a0)
{
    func_020307B0(a0);
}
