/*
 * function: func_021B8F08
 * address: 0x021B8F08
 * packet: pkt_ov104_021B8F08
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: BLDCNT at 04000050, the hardware halfword store at 021B8F16.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021B8F08(void *task,u8 *p) {
 if(*(u32 *)(p+0x8a8)) {
  *(u32 *)(p+0x8a8)=0;
  *(volatile u16 *)0x04000050=0;
 }
}
