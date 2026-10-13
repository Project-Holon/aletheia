/*
 * packet: pkt_ov186_021FFB80
 * function: func_021FFB80
 * address: 0x021FFB80
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012E40 0x02012E40 thumb
 *   func_021D7124 0x021D7124 thumb ov125
 *   func_021D6770 0x021D6770 thumb ov125
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 */
#include "../include/Obj10800.h"
typedef unsigned char  u8;
extern u8 func_02012E40(const u8 *o);
extern void func_021D7124(char *, int, int, int);
extern void func_021D6770(char *);
extern void DWC_RAP_SetErrorHookCallback(int, int);
int func_021FFB80(char *p, int b, int kind, int d)
{
    if (func_02012E40(((struct Obj10800 *)p)->f5E0)) return 1;
    func_021D7124(p, b, kind, d);
    if (kind == 3 || kind == 6) {
        if (((struct Obj10800 *)p)->f5A4) {
            func_021D6770(p);
            ((struct Obj10800 *)p)->f5A4 = 0;
        }
        DWC_RAP_SetErrorHookCallback(0, 0);
    }
    return 0;
}
