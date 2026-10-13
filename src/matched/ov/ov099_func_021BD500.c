/*
 * function: WIFICLUB_StateShowBoxPartyViolations
 * address: 0x021BD500
 * packet: pkt_ov099_021BD500
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUB_CheckSavedRegulation 0x021BCBBC thumb ov099
 *   WIFICLUB_ShowRuleWindow 0x021BBEB4 thumb ov099
 */
#include "../include/Obj07949.h"
#include "../include/Obj22037.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int WIFICLUB_UpdateTalkStream(char *p, int result);
extern u32 KEY_GetTrg(void);
extern void WIFICLUB_ClearTalkWindow(char *p);
extern int WIFICLUB_CheckSavedRegulation(int a, int b, int *out);
struct O;
extern void WIFICLUB_ShowRuleWindow(struct O *p, int mask, u32 a, int mode);
int WIFICLUB_StateShowBoxPartyViolations(char *p, int result)
{
    int out;
    if (WIFICLUB_UpdateTalkStream(p, result) == 0) return result;
    if (KEY_GetTrg() != 0) {
        WIFICLUB_ClearTalkWindow(p);
        WIFICLUB_CheckSavedRegulation(((struct Obj07949 *)p)->f1348, ((struct Obj07949 *)p)->fCC, &out);
        WIFICLUB_ShowRuleWindow((struct O *)p, out, ((struct Obj22037 *)(*(u8 * *)&((struct Obj07949 *)p)->f248))->f48, 3);
        ((struct Obj07949 *)p)->f1CC = 0x6d;
    }
    return result;
}
