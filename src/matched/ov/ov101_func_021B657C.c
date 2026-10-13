/*
 * function: COMPATIBLE_IRC_SYS_GetPartnerProfile
 * address: 0x021B657C
 * packet: pkt_ov101_021B657C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMPATIBLE_IRC_SYS_ProfileSyncGetPartnerProfile 0x021B685C thumb ov101
 */
typedef struct R { int words[11]; } R;
extern void COMPATIBLE_IRC_SYS_ProfileSyncGetPartnerProfile(int *,R *);
void COMPATIBLE_IRC_SYS_GetPartnerProfile(int *p,R *out) { if(!p[30]) COMPATIBLE_IRC_SYS_ProfileSyncGetPartnerProfile(p+1,out); }
