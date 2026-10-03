/*
 * function: func_02210B00
 * address: 0x02210B00
 * packet: pkt_ov198_02210B00
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02210F4C 0x02210F4C thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_022110D4(u8 *,int),func_02210F4C(u8 *,int);
int func_02210B00(u8 *p,int i) { if(!*(u16 *)(p+func_022110D4(p,i)*76+8))return 0;if(func_02210F4C(p,i)==1)return 1;return 2; }
