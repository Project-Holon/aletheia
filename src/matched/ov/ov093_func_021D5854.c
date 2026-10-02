/*
 * function: func_021D5854
 * address: 0x021D5854
 * packet: pkt_ov093_021D5854
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
struct Work { void *a; void *b; u8 pad[0x13]; u8 low:6; u8 flag:1; u8 high:1; };
void func_021D5854(struct Work *p) { p->b = 0; p->flag = 0; }
