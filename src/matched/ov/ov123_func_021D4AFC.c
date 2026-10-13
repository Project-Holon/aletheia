/*
 * function: func_021D4AFC
 * address: 0x021D4AFC
 * packet: pkt_ov123_021D4AFC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4E7C 0x021D4E7C thumb ov123
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_021D4E64 0x021D4E64 thumb ov123
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021D4D40 0x021D4D40 thumb ov123
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D4A04 0x021D4A04 thumb ov123
 */
#include "../include/Obj00273.h"
typedef unsigned int u32;
extern int func_021D4E7C(char *);
extern int TOUCHPANEL_GetTrg(void);
typedef unsigned char  u8;
extern void func_021D4E64(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021D4D40(char *, int);
extern void func_021D4244(char *, void *, int);
extern void func_021D4A04(char *);
void func_021D4AFC(char *p)
{
    if (func_021D4E7C(p) != 0 && TOUCHPANEL_GetTrg() != 0) {
        func_021D4E64((u8 *)p);
        ((struct Obj00273 *)p)->f27C = 0;
        GFL_USE_PlaySeDefaultVolume(0x73b);
        func_021D4D40(p, 0);
        func_021D4244(p, func_021D4A04, 0x360);
    }
}
