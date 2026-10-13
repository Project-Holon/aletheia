/*
 * function: func_021D8A38
 * address: 0x021D8A38
 * packet: pkt_ov123_021D8A38
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D706C 0x021D706C thumb ov123
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj13997.h"

typedef unsigned int u32;
typedef unsigned char  u8;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D706C(char *p);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void func_021D8A38(char *p)
{
    if (((struct Obj13997 *)p)->f64 % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    ++((struct Obj13997 *)p)->f64;
    if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
        func_021D6EE0((u8 *)p, (int)func_021D706C, 0x88e);
}
