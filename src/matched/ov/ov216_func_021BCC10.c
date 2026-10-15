/*
 * function: BEACON_DETAIL_GRA_UpdateInteract
 * address: 0x021BCC10
 * packet: pkt_ov216_021BCC10
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_IsNetOffBySleep 0x02012204 thumb
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   BEACON_DETAIL_GRA_AddSlotSlideTask 0x021BD89C thumb ov216
 *   BEACON_DETAIL_GRA_IsTouchOnActor 0x021BCCC4 thumb ov216
 *   BEACON_DETAIL_GRA_PlaySe 0x021BCD00 thumb ov216
 *   BEACON_DETAIL_GRA_AddTimerTask 0x021BD6F0 thumb ov216
 *   KEY_GetTrg  0x020362DC  arm  arm9
 */
#include "../include/Obj05554.h"

typedef unsigned int u32;
extern int TOUCHBAR_GetPressedButtonIdIfPressing(unsigned char *);
extern u32 KEY_GetTrg(void);
struct Ctx;
extern unsigned GAMESYSTEM_IsNetOffBySleep(const struct Ctx *);
extern void BEACON_DETAIL_GRA_AddSlotSlideTask(char *p, int a);
typedef unsigned char  u8;
extern int BEACON_DETAIL_GRA_IsTouchOnActor(u8 *p);
extern void BEACON_DETAIL_GRA_PlaySe(int);
extern void BEACON_DETAIL_GRA_AddTimerTask(char *p);
int BEACON_DETAIL_GRA_UpdateInteract(unsigned char *p)
{
    int state=TOUCHBAR_GetPressedButtonIdIfPressing(((struct Obj05554 *)p)->f124);
    unsigned keys=KEY_GetTrg();
    if(GAMESYSTEM_IsNetOffBySleep((const struct Ctx *)**(void ** *)&((struct Obj05554 *)p)->f14)) { (*(unsigned char **)(p+0x14))[9]=1; return 4; }
    if(state==1) { (*(unsigned char **)(p+0x14))[9]=0; return 4; }
    if(state==3 && p[0x30]) { BEACON_DETAIL_GRA_AddSlotSlideTask((char *)p,1); return 3; }
    if(state==2 && p[0x30]<p[0x2f]-1) { BEACON_DETAIL_GRA_AddSlotSlideTask((char *)p,0); return 3; }
    if(!p[0x260]) return 2;
    if(BEACON_DETAIL_GRA_IsTouchOnActor(p) || (keys&1)) { BEACON_DETAIL_GRA_PlaySe(1356); BEACON_DETAIL_GRA_AddTimerTask((char *)p); return 3; }
    return 2;
}
