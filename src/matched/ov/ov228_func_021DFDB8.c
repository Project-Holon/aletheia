/*
 * function: SAVE_OUTSIDE_Free
 * address:  0x021DFDB8
 * packet:   pkt_021DFC20
 * region:   ov228
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Unlabelled leaf in ov228 (it saves nothing; the listing prints it as
 * .word data after pool_021DFDB4): a one-argument forwarding tail call to
 * the heap free func_020307B0, `ldr r3, [pc]; bx r3` plus the pool word.
 * Its caller is arm9 MYSTERY_DATA_Unload (mystery_data.c), whose MATCH park names
 * this address as its only unwitnessed call.  Integrator: seed ov228
 * 0x021DFDB8.
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void SAVE_OUTSIDE_Free(void *p)
{
    func_020307B0(p);
}
