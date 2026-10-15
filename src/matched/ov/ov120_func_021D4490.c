/*
 * function: GTSNEGO_DISP_WaitWipeDone
 * address: 0x021D4490
 * packet: pkt_ov120_021D4490
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void); extern void GTSNEGO_DISP_SetStateCallback(int,void (*)(int),int);
void GTSNEGO_DISP_WaitWipeDone(int p) { if (WIPE_SYS_EndCheck()) GTSNEGO_DISP_SetStateCallback(p,0,0x213); }
