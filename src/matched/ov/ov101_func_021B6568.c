/*
 * function: COMPATIBLE_IRC_SYS_StepSendProfile
 * address: 0x021B6568
 * packet: pkt_ov101_021B6568
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMPATIBLE_IRC_SYS_ProfileSyncStepSend 0x021B67F8 thumb ov101
 */
extern int COMPATIBLE_IRC_SYS_ProfileSyncStepSend(int *,int);
int COMPATIBLE_IRC_SYS_StepSendProfile(int *p,int resource) { if(p[30]) return 1; return COMPATIBLE_IRC_SYS_ProfileSyncStepSend(p+1,resource); }
