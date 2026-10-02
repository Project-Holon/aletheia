/*
 * function: func_021CE2E8
 * address: 0x021CE2E8
 * packet: pkt_ov093_021CE2E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8434 0x021D8434 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D8434(u8 *);
void func_021CE2E8(u8 *p) { *(u8 **)(p+0xc)=p+0x124; func_021D8434(p+0x124); *(u8 **)(p+0xd8)=*(u8 **)(p+0xc); *(u32 *)(p+0xdc)=4; }
