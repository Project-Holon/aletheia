/*
 * function: func_021BCC10
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
 *   func_021BD89C 0x021BD89C thumb ov216
 *   func_021BCCC4 0x021BCCC4 thumb ov216
 *   func_021BCD00 0x021BCD00 thumb ov216
 *   func_021BD6F0 0x021BD6F0 thumb ov216
 */
#include "../include/Obj05554.h"

typedef unsigned int u32;
extern int TOUCHBAR_GetPressedButtonIdIfPressing(unsigned char *);
extern u32 func_020362DC(void);
struct Ctx;
extern unsigned GAMESYSTEM_IsNetOffBySleep(const struct Ctx *);
extern void func_021BD89C(char *p, int a);
typedef unsigned char  u8;
extern int func_021BCCC4(u8 *p);
extern void func_021BCD00(int);
extern void func_021BD6F0(char *p);
int func_021BCC10(unsigned char *p)
{
    int state=TOUCHBAR_GetPressedButtonIdIfPressing(((struct Obj05554 *)p)->f124);
    unsigned keys=func_020362DC();
    if(GAMESYSTEM_IsNetOffBySleep((const struct Ctx *)**(void ** *)&((struct Obj05554 *)p)->f14)) { (*(unsigned char **)(p+0x14))[9]=1; return 4; }
    if(state==1) { (*(unsigned char **)(p+0x14))[9]=0; return 4; }
    if(state==3 && p[0x30]) { func_021BD89C((char *)p,1); return 3; }
    if(state==2 && p[0x30]<p[0x2f]-1) { func_021BD89C((char *)p,0); return 3; }
    if(!p[0x260]) return 2;
    if(func_021BCCC4(p) || (keys&1)) { func_021BCD00(1356); func_021BD6F0((char *)p); return 3; }
    return 2;
}
