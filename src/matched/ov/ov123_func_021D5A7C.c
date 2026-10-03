/*
 * function: func_021D5A7C
 * address: 0x021D5A7C
 * packet: pkt_ov123_021D5A7C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0202F038(void *);
extern u8 *func_0202EE8C(u32,void *,u8,u8,u16);
void func_021D5A7C(char *p){if(*(void **)(p+0x7c)){func_0202F038(*(void **)(p+0x7c));*(void **)(p+0x7c)=0;}*(void **)(p+0x7c)=func_0202EE8C(*(u32 *)(p+0x84),*(void **)(p+0x44),15,16,*(u16 *)(p+0xb0));}
