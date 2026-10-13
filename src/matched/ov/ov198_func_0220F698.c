/*
 * function: func_0220F698
 * address: 0x0220F698
 * packet: pkt_ov198_0220F698
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void);
int func_0220F698(u8 *p) { if(WIPE_SYS_EndCheck()==1) { if((*(u8 **)p)[31]==4)return 25; if((*(u8 **)p)[31]==5)return 30; return 3; } return 2; }
