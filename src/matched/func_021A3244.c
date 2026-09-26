/*
 * function: func_021A3244
 * address:  0x021A3244
 * packet:   pkt_021A3244
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3A3C  0x021A3A3C  thumb  ov021
 *
 * Tail-call thunk: ldr r0,[r0,#4]; ldr r3,[pc]; bx r3; .word func_021A3A3C.
 * Unlabelled in the ARM9 listings (the .word run at 0x021A3244 in ov021);
 * blocker target of ov010's func_0216A244 (pkt_0216A244).
 */

extern void func_021A3A3C(void *);

void func_021A3244(void *p)
{
    func_021A3A3C(*(void **)((char *)p + 4));
}
