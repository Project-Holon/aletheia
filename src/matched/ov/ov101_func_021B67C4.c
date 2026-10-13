/*
 * function: COMPATIBLE_IRC_SYS_ProfileSyncSendAck
 * address: 0x021B67C4
 * packet: pkt_ov101_021B67C4
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMPATIBLE_IRC_SYS_SendToHandle 0x021B6494 thumb ov101
 */
typedef unsigned int   u32;
extern int COMPATIBLE_IRC_SYS_SendToHandle(u32 p, u32 a, u32 b, u32 c);
int COMPATIBLE_IRC_SYS_ProfileSyncSendAck(int *p) { int value; return COMPATIBLE_IRC_SYS_SendToHandle((u32)((int *)p[0]),0x1001,4,(u32)(&value))!=0; }
