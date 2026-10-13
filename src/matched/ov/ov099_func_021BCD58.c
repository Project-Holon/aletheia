/*
 * function: WIFICLUB_StateRuleViolationKey
 * address:  0x021BCD58
 * packet:   pkt_ov099_021BCD58
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_UpdateTalkStream  0x021BA928  thumb  ov099
 *   KEY_GetTrg  0x020362DC  arm
 *   WIFICLUB_ClearTalkWindow  0x021BA8EC  thumb  ov099
 *   WIFICLUB_CheckPartyAgainstRules  0x021BCB70  thumb  ov099
 *   WIFICLUB_ShowRuleWindow  0x021BBEB4  thumb  ov099
 */
#include "../include/Obj07945.h"
#include "../include/Obj22033.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern int WIFICLUB_UpdateTalkStream(char *p, int v);
extern u32 KEY_GetTrg(void);
extern void WIFICLUB_ClearTalkWindow(char *p);
struct BigObj;
extern int WIFICLUB_CheckPartyAgainstRules(void *rules, const struct BigObj *obj, u32 *mask);
struct O;
extern void WIFICLUB_ShowRuleWindow(struct O *p, int mask, u32 a, int mode);

int WIFICLUB_StateRuleViolationKey(char *p, int v)
{
    int out;

    if (WIFICLUB_UpdateTalkStream(p, v) == 0) {
        return v;
    }
    if (KEY_GetTrg() != 0) {
        WIFICLUB_ClearTalkWindow(p);
        WIFICLUB_CheckPartyAgainstRules((void *)(((struct Obj07945 *)p)->f1348), (const struct BigObj *)(((struct Obj07945 *)p)->fC4), (u32 *)(&out));
        WIFICLUB_ShowRuleWindow((struct O *)p, out, ((struct Obj22033 *)(*(u8 * *)&((struct Obj07945 *)p)->f248))->f48, 2);
        ((struct Obj07945 *)p)->f1CC = 0x77;
    }
    return v;
}
