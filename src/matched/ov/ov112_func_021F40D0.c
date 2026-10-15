/*
 * function: MUSICAL_MCSS_SetObjectValue
 * address: 0x021F40D0
 * packet: pkt_ov112_021F40D0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F8264 0x021F8264 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u32 words[4]; } Quad;
extern const Quad d_021F8264;
u32 MUSICAL_MCSS_SetObjectValue(void *p,u32 i,u16 c) { Quad q=d_021F8264; return q.words[i]; }
