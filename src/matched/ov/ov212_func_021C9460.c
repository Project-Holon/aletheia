/*
 * function: func_021C9460
 * address:  0x021C9460
 * packet:   pkt_ov212_021C9460
 * region:   ov212
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Bottom-up unblocker for the last unresolved site of
 * src/pending/func_021BD3AC.c.  Thumb tail-call veneer into the ARM9
 * func_020307B0 (the image is `ldr r3,[pc,#0]; bx r3; .word 0x020307B0`);
 * disasm emits it as an unlabelled `.word` run, so no listing class attests
 * it.  Addresses are Black-image addresses.
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021C9460(int a0)
{
    func_020307B0((void *)a0);
}
