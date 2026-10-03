/*
 * function: func_021FC684
 * address: 0x021FC684
 * packet: pkt_ov132_021FC684
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FCA38 0x021FCA38 thumb ov132
 *   func_02026400 0x02026400 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern void func_021FCA38(char *);
extern void func_02026400(struct Comm *);
void func_021FC684(char *p) { func_021FCA38(p); func_02026400(*(struct Comm **)(p+0x50)); }
