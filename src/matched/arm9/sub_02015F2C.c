/*
 * function: MCSS_SetAnimCallback
 * address:  0x02015F2C
 * packet:   pkt_02015F2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   NNS_G2dSetCellAnimationParam  0x02063000  arm
 *
 * A pure forwarder: tail-calls NNS_G2dSetCellAnimationParam on a member 0x34 bytes into
 * the object, with a fixed 1 as the second argument.
 *
 * EXACT* because the 18 compiled bytes fall far short of the disasm.py
 * extent (252 bytes): the packet's next several functions carry no
 * register-saving prologue and disasm.py's extent runs to the following
 * labelled function; they are not matched here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_SetAnimCallback.c \
 *       --func MCSS_SetAnimCallback --addr 0x02015F2C --cc 1.1p1
 */

typedef unsigned int u32;

extern void NNS_G2dSetCellAnimationParam(int p0, int p1, int p2, int p3);

void MCSS_SetAnimCallback(void *a, u32 arg1, u32 arg2)
{
    NNS_G2dSetCellAnimationParam((int)((char *)a + 0x34), 1, arg1, arg2);
}
