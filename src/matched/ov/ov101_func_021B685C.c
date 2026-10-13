/*
 * function: COMPATIBLE_IRC_SYS_ProfileSyncGetPartnerProfile
 * address: 0x021B685C
 * packet: pkt_ov101_021B685C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef struct R { int words[11]; } R;
void COMPATIBLE_IRC_SYS_ProfileSyncGetPartnerProfile(int *p,R *out) { *out=*(R *)p[12]; }
