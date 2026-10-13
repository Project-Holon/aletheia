/*
 * function: COMPATIBLE_IRC_SYS_ProfileSyncSendRequest
 * address: 0x021B678C
 * packet: pkt_ov101_021B678C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   COMPATIBLE_IRC_SYS_SendToHandle 0x021B6494 thumb ov101
 */
typedef unsigned int   u32;
extern int COMPATIBLE_IRC_SYS_SendToHandle(u32 p, u32 a, u32 b, u32 c);
int COMPATIBLE_IRC_SYS_ProfileSyncSendRequest(int *p,int a,int b) { p[5]=a; p[4]=b; return COMPATIBLE_IRC_SYS_SendToHandle((u32)((int *)p[0]),0x1000,8,(u32)(p+4))!=0; }
