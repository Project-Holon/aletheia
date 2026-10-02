/*
 * function: func_021D8434
 * address: 0x021D8434
 * packet: pkt_ov093_021D8434
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * follower: Two zero alignment bytes.
 * lever: Enum mask preserves the contradictory clear-and-mask operations;
 * placing the mask first in the final AND selects the original register.
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
union B { u32 word; struct { u32 kind:4; u32 rest:28; } bits; };
typedef enum { MASK=15 } Mask;
void func_021D8434(u32 *p) { Mask mask=MASK; *p=mask & (*p & ~15); }
