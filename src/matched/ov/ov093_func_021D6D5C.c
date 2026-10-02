/*
 * function: func_021D6D5C
 * address: 0x021D6D5C
 * packet: pkt_ov093_021D6D5C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6238 0x021D6238 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilSlots;
extern void func_021D6238(struct UtilSlots *,int);
void func_021D6D5C(u8 *p,u16 n) { *(u16 *)(p+0x1f2)=n; func_021D6238((struct UtilSlots *)p,8); }
