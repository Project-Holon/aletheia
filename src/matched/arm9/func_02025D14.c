/*
 * function: func_02025D14
 * address:  0x02025D14
 * packet:   pkt_02025D14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf: a bare tail call to func_02030164 with no arguments.
 * `ldr r3,[pc,#0]; bx r3` (the pool word names 0x02030164).  Disasm.py did
 * not label it because it has no prologue; the live bytes decode as Thumb.
 *
 * symbols:
 *   func_02025D14  0x02025D14  thumb
 *   func_02030164  0x02030164  arm
 */

typedef unsigned int   u32;
extern u32 func_02030164(void *p);

void func_02025D14(void *a0)
{
    func_02030164(a0);
}
