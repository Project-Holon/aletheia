/*
 * function: func_021D885C
 * address: 0x021D885C
 * packet: pkt_ov123_021D885C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D580C 0x021D580C thumb ov123
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6F04 0x021D6F04 thumb ov123
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 */
#include "../include/Obj10450.h"
#include "../include/Obj22976.h"

typedef unsigned int u32;
extern int func_021D580C(char *);
extern void func_021D584C(char *);
typedef unsigned char  u8;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D6F04(char *p);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
void func_021D885C(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj10450 *)p)->f18)) {
        if (func_020362DC() || TOUCHPANEL_GetTrg()) {
            ((struct Obj22976 *)(*(char * *)&((struct Obj10450 *)p)->f20))->f1C8 = 1;
            func_021D584C(*(char * *)&((struct Obj10450 *)p)->f18);
            func_021D6EE0((u8 *)p, (int)func_021D6F04, 0x808);
        }
    }
}
