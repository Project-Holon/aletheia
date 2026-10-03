/*
 * function: func_021FD8D4
 * address: 0x021FD8D4
 * packet: pkt_ov132_021FD8D4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;struct Link;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *);
u32 func_021FD8D4(char *p) {return *(u8 *)((u32)p+func_0203D1A4((struct Link *)func_020399A8())*0x30+0x72);}
