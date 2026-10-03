/*
 * function: func_021D9320
 * address: 0x021D9320
 * packet: pkt_ov129_021D9320
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: Two zero alignment bytes.
 * symbols:
 *   func_021D92E4 0x021D92E4 thumb ov129
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021D92E4(u8 *);
int func_021D9320(u8 *p) { if(!*(int *)(p+0x328)) return 1; if(func_021D92E4(p)<=*(int *)(p+0x344)) return 1; return 0; }
