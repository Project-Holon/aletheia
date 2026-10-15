/*
 * function: WIFILOGIN_MSG_StepWaitWipe
 * address: 0x021D6198
 * packet: pkt_ov115_021D6198
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIFILOGIN_MSG_RunStep 0x021D6134 thumb ov115
 *   WIFILOGIN_MSG_StepMessage 0x021D61B8 thumb ov115
 */
typedef unsigned char u8;typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void);extern void WIFILOGIN_MSG_RunStep(void *,void (*)(u8 *),int);extern void WIFILOGIN_MSG_StepMessage(u8 *);
void WIFILOGIN_MSG_StepWaitWipe(u8 *p) { if(WIPE_SYS_EndCheck())WIFILOGIN_MSG_RunStep(p,WIFILOGIN_MSG_StepMessage,0x169); }
