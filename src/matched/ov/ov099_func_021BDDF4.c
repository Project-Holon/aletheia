/*
 * function: WIFICLUB_HasRuleViolation
 * address: 0x021BDDF4
 * packet: pkt_ov099_021BDDF4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_CheckPartyAgainstRules 0x021BCB70 thumb ov099
 *   WIFICLUB_CheckSavedRegulation 0x021BCBBC thumb ov099
 */
#include "../include/Obj07954.h"
typedef unsigned int   u32;
struct BigObj;
extern int WIFICLUB_CheckPartyAgainstRules(void *rules, const struct BigObj *obj, u32 *mask);
extern int WIFICLUB_CheckSavedRegulation(int,int,int *);
int WIFICLUB_HasRuleViolation(char *p) {
 int out;
 if (WIFICLUB_CheckPartyAgainstRules((void *)(((struct Obj07954 *)p)->f1348),(const struct BigObj *)(((struct Obj07954 *)p)->fC4),(u32 *)(&out)) && WIFICLUB_CheckSavedRegulation(((struct Obj07954 *)p)->f1348,((struct Obj07954 *)p)->fCC,&out)) return 0;
 return 1;
}
