/*
 * function: BR_CODEIN_RecordStepDeleteProfile
 * address: 0x021DBD40
 * packet: pkt_ov183_021DBD40
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_CODEIN_RecordDeleteProfileScreen 0x021DCE28 thumb ov183
 *   BR_CODEIN_RecordDeleteActors 0x021DCE48 thumb ov183
 *   BR_CODEIN_RecordDeleteButtons 0x021DD054 thumb ov183
 *   BR_UTIL_ClearTaskStep 0x021FD744 thumb ov186
 */
#include "../include/Obj00050.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern void BR_CODEIN_RecordDeleteProfileScreen(char *,char *),BR_CODEIN_RecordDeleteActors(char *,char *),BR_CODEIN_RecordDeleteButtons(char *,char *);
extern int BR_UTIL_ClearTaskStep(int *a);
void BR_CODEIN_RecordStepDeleteProfile(int *task,int b,char *p) { if(((struct Obj00050 *)p)->fB0) BR_CODEIN_RecordDeleteProfileScreen(p,*(char * *)&((struct Obj00050 *)p)->fD0); else BR_CODEIN_RecordDeleteActors(p,*(char * *)&((struct Obj00050 *)p)->fD0); BR_CODEIN_RecordDeleteButtons(p,*(char * *)&((struct Obj00050 *)p)->fD0); BR_UTIL_ClearTaskStep(task); }
