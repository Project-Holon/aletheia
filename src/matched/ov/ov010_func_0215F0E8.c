/*
 * function: func_0215F0E8
 * address: 0x0215F0E8
 * packet: pkt_ov010_0215F0E8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 */

typedef unsigned int u32;
typedef struct Pair { u32 a, b; } Pair;
void func_0215F0E8(u32 *out, const Pair *in, u32 *ctx) { out[0] = 0x19740205; out[1] = ctx[3]; *(Pair *)(out+3) = *in; out[2] = ctx[2]; }
