/*
 * function: WIFICLUB_StateCheckEntryRules
 * address:  0x021BD038
 * packet:   pkt_ov099_021BD038
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_LoadOwnRegulation  0x021BCC4C  thumb  ov099
 *   WIFICLUB_HasRuleViolation  0x021BDDF4  thumb  ov099
 *   WIFICLUB_ShowStreamedMessage  0x021BAAB8  thumb  ov099
 */
#include "../include/Obj05263.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern void WIFICLUB_LoadOwnRegulation(void *a);
extern int WIFICLUB_HasRuleViolation(char *p);
extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);

int WIFICLUB_StateCheckEntryRules(char *p, int v)
{
    WIFICLUB_LoadOwnRegulation(p);
    if (WIFICLUB_HasRuleViolation(p) == 0) {
        switch (((struct Obj05263 *)p)->f135C) {
        case 3:
            ((struct Obj05263 *)p)->f1CC = 0x9D;
            WIFICLUB_ShowStreamedMessage(p, 0x68, 0);
            return v;
        case 2:
        case 4:
            ((struct Obj05263 *)p)->f1CC = 0x63;
            WIFICLUB_ShowStreamedMessage(p, 0x68, 0);
            return v;
        default:
            ((struct Obj05263 *)p)->f1CC = 0x96;
            WIFICLUB_ShowStreamedMessage(p, 0x68, 0);
            return v;
        }
    }
    ((struct Obj05263 *)p)->f1353 = 0x64;
    ((struct Obj05263 *)p)->f1CC = 0x8A;
    return v;
}
