/*
 * function: func_021F626C
 * address: 0x021F626C
 * packet: pkt_ov112_021F626C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 a:1,b:1,c:1,rest:29; } Flags;
void func_021F626C(u8 *p) { ((Flags *)(p+236))->a=1; }
