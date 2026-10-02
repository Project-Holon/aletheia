/*
 * function: func_021BA624
 * address: 0x021BA624
 * packet: pkt_ov091_021BA624
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_021BA688 0x021BA688 thumb ov091
 *   func_021BA670 0x021BA670 thumb ov091
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02017E40(void *,u32,u32);
extern u32 func_021BA688(u8 *,u16);
extern u32 func_021BA670(u8 *,u16);
void func_021BA624(u8 *p, void *q, u16 id) { u32 old=func_02017E1C(q,6,0); if(old) func_021BA688(p,old); func_02017E40(q,6,id); if(id) func_021BA670(p,id); }
