/*
 * function: func_021CE3B4
 * address: 0x021CE3B4
 * packet: pkt_ov093_021CE3B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EA614 0x021EA614 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct H;
extern void func_021EA614(char *p, struct H *h);
void func_021CE3B4(u8 *p, void *q) { func_021EA614(*(void **)(p+0x54),q); p[0x120]=1; }
