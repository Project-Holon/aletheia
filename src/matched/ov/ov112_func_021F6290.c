/*
 * function: MUSICAL_MCSS_PauseMCAnim
 * address: 0x021F6290
 * packet: pkt_ov112_021F6290
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 a:1,b:1,c:1,rest:29; } Flags;
void MUSICAL_MCSS_PauseMCAnim(u8 *p) { ((Flags *)(p+236))->b=1; }
