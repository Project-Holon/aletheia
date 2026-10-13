/*
 * function: WIFICLUB_StateCancelOnKeyAfterMessage
 * address: 0x021BD0BC
 * packet: pkt_ov099_021BD0BC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 */
#include "../include/Obj13689.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int WIFICLUB_UpdateTalkStream(void *);
extern u32 KEY_GetTrg(void);
int WIFICLUB_StateCancelOnKeyAfterMessage(char *p, int v)
{
    if (WIFICLUB_UpdateTalkStream(p) == 0) return v;
    if (KEY_GetTrg() == 0) return v;
    ((struct Obj13689 *)p)->f1353 = 0x6e;
    ((struct Obj13689 *)p)->f1CC = 0x8a;
    return v;
}
