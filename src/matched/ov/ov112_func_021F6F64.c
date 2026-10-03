/*
 * function: func_021F6F64
 * address: 0x021F6F64
 * packet: pkt_ov112_021F6F64
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow code.
 * symbols:
 *   func_02047910 0x02047910 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02047910(void *,int,int);
void func_021F6F64(u8 *p) { u8 i; if(*(u32 *)(p+28)) { for(i=0;i<3;i++) func_02047910(*(void **)(p+60),i,4096); } }
