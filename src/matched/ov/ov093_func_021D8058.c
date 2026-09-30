/*
 * unit: yes
 * function: func_021D8058,func_021D805C
 * address: 0x021D8058
 * packet: pkt_ov093_021D8058
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02020FE4 0x02020FE4 thumb
 *   data_021F6360 0x021F6360 data ov093 a2
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 data_021F6360;
extern u32 func_02020FE4(void *,u32,u32);
void func_021D8058(void) { }
u32 func_021D805C(void *p,u32 n) { return func_02020FE4(p,n,data_021F6360); }
