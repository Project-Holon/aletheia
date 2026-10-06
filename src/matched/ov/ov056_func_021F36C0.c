/*
 * function: func_021F36C0
 * address: 0x021F36C0
 * packet: pkt_ov056_021F36C0
 * region: ov056
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Unlabelled tail-call stub at the start of ov056 (the listing prints it as
 * .word data): ldr r3,[pc]; bx r3 to func_021F36F0.  Referenced as
 * 0x021F36C1 from the ov021 table at 021D9CC0: ov036..ov065 all load at
 * 0x021F36C0, so that word names the head of whichever of them is loaded.
 *
 * symbols:
 *   func_021F36F0  0x021F36F0  thumb  ov056
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void *func_021F36F0(void *a, u8 *b, u32 c);

void *func_021F36C0(void *a, u8 *b, u32 c)
{
    return func_021F36F0(a, b, c);
}
