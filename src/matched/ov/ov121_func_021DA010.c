/*
 * function: func_021DA010
 * address: 0x021DA010
 * packet: pkt_ov121_021DA010
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202F038(u8 *);
extern void func_02045374(void *);
extern u32 func_02045730(void *);
extern void func_020409B4(u32);
void func_021DA010(u8 *p) { *(u32 *)(p+0x2c)=1; if(*(u8 **)(p+0x3c)) { func_0202F038(*(u8 **)(p+0x3c)); *(u32 *)(p+0x3c)=0; func_02045374(*(void **)(p+0x10)); func_020409B4(func_02045730(*(void **)(p+0x10))); } }
