/*
 * function: func_021C93A8
 * address: 0x021C93A8
 * packet: pkt_ov212_021C93A8
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
void func_021C93A8(u32 heap) { WIPE_SYS_Start(0,1,1,0,6,1,heap); }
