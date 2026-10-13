/*
 * function: func_0689D5FC
 * address: 0x0689D5FC
 * packet: pkt_ov095_0689D5FC
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: form the modular base + 3*i first, then read byte at +2; p[3*i+2] differs
 * by four bytes because its +2 is added to the index register.
 * ABI: reads r0 base and r1 index; byte load returned in r0.
 * The index is u8: the ov093 caller at 021C50C4 narrows its loop counter
 * to a byte at the call. The body compiles the same as with int.
 */
typedef unsigned char u8;
typedef unsigned int u32;
int func_0689D5FC(u8 *p, u8 i) { return ((u8 *)((u32)p + (u32)i * 3u))[2]; }
