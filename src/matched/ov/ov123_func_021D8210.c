/*
 * function: func_021D8210
 * address: 0x021D8210
 * packet: pkt_ov123_021D8210
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D706C 0x021D706C thumb ov123
 *   func_021D580C 0x021D580C thumb ov123
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 */
#include "../include/Obj22966.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D706C(char *);
extern int func_021D580C(char *);
extern unsigned int KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
void func_021D8210(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22966 *)p)->f18)) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            func_021D6EE0((u8 *)p, (int)func_021D706C, 0x5e9);
        }
    }
}
