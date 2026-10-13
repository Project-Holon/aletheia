/*
 * function: WIFICLUB_StateCloseMessageOnKey
 * address: 0x021BDC0C
 * packet: pkt_ov099_021BDC0C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 */
#include "../include/Obj13697.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int WIFICLUB_UpdateTalkStream(void *);
extern u32 KEY_GetTrg(void);
extern void WIFICLUB_ClearTalkWindow(char *);
int WIFICLUB_StateCloseMessageOnKey(char *p, int v)
{
    if (WIFICLUB_UpdateTalkStream(p) == 0) return v;
    if (KEY_GetTrg() != 0) {
        WIFICLUB_ClearTalkWindow(p);
        ((struct Obj13697 *)p)->f1353 = 0x4a;
        ((struct Obj13697 *)p)->f1CC = 0x8a;
    }
    return v;
}
