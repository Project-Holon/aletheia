/*
 * function: WIFICLUB_StateApplyRuleSelection
 * address: 0x021BDC44
 * packet: pkt_ov099_021BDC44
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_LoadPickedRegulation 0x021BCBD8 thumb ov099
 *   WIFICLUB_HasRuleViolation 0x021BDDF4 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   d_021C390C 0x021C390C data ov099 a4
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_AddNetCommandsAndCheckFriend 0x021C23C8 thumb ov099
 *   WIFICLUB_EnableTouchBar 0x021C23D8 thumb ov099
 */
#include "../include/Obj07953.h"
typedef unsigned short u16;
typedef struct { int v[8]; } Table;
extern const Table d_021C390C;
typedef unsigned int   u32;
extern u32 WIFICLUB_LoadPickedRegulation(char *p, int m);
extern int WIFICLUB_HasRuleViolation(char *);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
extern int WIFICLUB_AddNetCommandsAndCheckFriend(void *a, void *b);
extern void WIFICLUB_EnableTouchBar(char *, int);
int WIFICLUB_StateApplyRuleSelection(char *p, int v)
{
    Table t;
    WIFICLUB_LoadPickedRegulation(p, 1);
    if (WIFICLUB_HasRuleViolation(p) == 0) {
        WIFICLUB_ShowStreamedMessage(p, 0x68, 0);
        ((struct Obj07953 *)p)->f1CC = 0x63;
        return v;
    }
    t = d_021C390C;
    WIFICLUB_SetOwnStatusAndPublish(p, 2, (u16)t.v[((struct Obj07953 *)p)->f134E + ((struct Obj07953 *)p)->f134C * 2]);
    WIFICLUB_AddNetCommandsAndCheckFriend(p, (void *)(-1));
    ((struct Obj07953 *)p)->f1CC = 0x9e;
    WIFICLUB_EnableTouchBar(p, 1);
    return v;
}
