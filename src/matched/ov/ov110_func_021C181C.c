/*
 * function: func_021C181C
 * address: 0x021C181C
 * packet: pkt_ov110_021C181C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank;
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *,int,u32);
void func_021C181C(void **p) { func_0204B1CC(*p); func_0204A5AC(); func_02082BCC(p,0,4); }
