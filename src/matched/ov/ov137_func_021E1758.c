/*
 * function: GURU2_MAIN_SyncPlayerCount
 * address: 0x021E1758
 * packet: pkt_ov137_021E1758
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_GetUnionApp 0x021DEB10 thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 */
#include "../include/Obj01753.h"
extern void *GURU2_MAIN_GetUnionApp(char *p);
extern int UNION_APP_GetMemberCount(unsigned char *);
void GURU2_MAIN_SyncPlayerCount(char *p, int a1) { ((struct Obj01753 *)p)->f30=UNION_APP_GetMemberCount(GURU2_MAIN_GetUnionApp(p)); }
