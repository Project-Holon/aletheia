/*
 * function: func_021641C8
 * address: 0x021641C8
 * packet: pkt_ov010_021641C8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: halfword-wrapped +0xFFCD preserves the literal-pool bias;
 * spelling -51 produced a 26-byte DIFF instead of the 32-byte body.
 * symbols:
 *   func_0216D5A0 0x0216D5A0 thumb ov010
 *   func_0216D708 0x0216D708 thumb ov010
 */

typedef unsigned short u16;
extern u16 func_0216D5A0(void *);
extern void func_0216D708(void *);
void func_021641C8(void *a) { if ((u16)(func_0216D5A0(a)+0xFFCD) <= 3) func_0216D708(a); }
