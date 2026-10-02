/*
 * function: func_021BB554
 * address: 0x021BB554
 * packet: pkt_ov091_021BB554
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202D034 0x0202D034 thumb
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_02017E1C(void *,u32,u32);
extern void func_0202D034(u16,u32);
void func_021BB554(u32 p) { func_0202D034(*(u16 *)(p+6),func_02017E1C(*(void **)p,0xa1,0)); }
