/*
 * function: GURU2_MAIN_StateStartWipeOut
 * address: 0x021DF7A4
 * packet: pkt_ov137_021DF7A4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 */
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
int GURU2_MAIN_StateStartWipeOut(int *p){WIPE_SYS_Start((void *)2,0,0,0,8,1,114);*p=51;return 0;}
