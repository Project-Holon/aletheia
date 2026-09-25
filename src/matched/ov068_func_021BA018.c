/*
 * function: func_021BA018
 * address:  0x021BA018
 * packet:   pkt_ov068_021BA018
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (disasm.py traced no prologue); the function that thunk
 * func_021B9944 tail-calls.  lsls r1,#2 / adds r0,r0,r1 / ldr r0,[r0,#0x18]
 * / bx lr.
 */

int func_021BA018(char *p, int i)
{
    return *(int *)(p + (i << 2) + 0x18);
}
