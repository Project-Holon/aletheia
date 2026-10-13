/*
 * function: WIFICLUB_StateCheckRules
 * address:  0x021BCCB8
 * packet:   pkt_ov099_021BCCB8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_LoadPickedRegulation  0x021BCBD8  thumb  ov099
 *   WIFICLUB_HasRuleViolation  0x021BDDF4  thumb  ov099
 *   WIFICLUB_ShowStreamedMessage  0x021BAAB8  thumb  ov099
 *   WIFICLUB_SetPartnerNameWord  0x021BA874  thumb  ov099
 *   WIFICLUB_ResetTimeIcon  0x021BC090  thumb  ov099
 */
#include "../include/Obj03732.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern u32 WIFICLUB_LoadPickedRegulation(char *p, int m);
extern int WIFICLUB_HasRuleViolation(char *p);
extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);
extern void WIFICLUB_SetPartnerNameWord(char *p, int id);
extern void WIFICLUB_ResetTimeIcon(char *p);

int WIFICLUB_StateCheckRules(char *p, int v)
{
    int m;
    u8 *q;

    m = ((struct Obj03732 *)p)->f135C;
    if (m == 3 || m == 1) {
        WIFICLUB_LoadPickedRegulation(p, 1);
    } else {
        WIFICLUB_LoadPickedRegulation(p, 0);
    }
    if (WIFICLUB_HasRuleViolation(p) == 0) {
        WIFICLUB_ShowStreamedMessage(p, 0x68, 0);
        ((struct Obj03732 *)p)->f1CC = 0x63;
        return v;
    }
    ((struct Obj03732 *)p)->f1352 = 7;
    q = *(u8 * *)&((struct Obj03732 *)p)->f248;
    if (q[0x44] != q[0x45]) {
        ((struct Obj03732 *)p)->f1CC = 0x7D;
    } else {
        ((struct Obj03732 *)p)->f1CC = 0x81;
    }
    WIFICLUB_SetPartnerNameWord(p, ((struct Obj03732 *)p)->f242 - 1);
    if (((struct Obj03732 *)p)->f135C - 3 <= 1u) {
        WIFICLUB_ShowStreamedMessage(p, 0xE, 0);
    } else {
        WIFICLUB_ShowStreamedMessage(p, 0x4C, 0);
    }
    WIFICLUB_ResetTimeIcon(p);
    return v;
}
