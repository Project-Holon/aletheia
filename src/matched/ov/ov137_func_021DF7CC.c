/*
 * function: GURU2_MAIN_StateWaitWipeOut, GURU2_MAIN_StateFinished
 * unit: yes
 * address: 0x021DF7CC
 * packet: pkt_ov137_021DF7CC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 */
typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
int GURU2_MAIN_StateWaitWipeOut(int *p){if(WIPE_SYS_EndCheck()){*p=52;return 1;}return 0;}
int GURU2_MAIN_StateFinished(void){return 2;}
