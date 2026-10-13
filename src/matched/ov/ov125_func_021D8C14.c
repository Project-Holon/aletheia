/*
 * function: func_021D8C14
 * address: 0x021D8C14
 * packet: pkt_ov125_021D8C14
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_0208CC78 0x0208CC78 arm
 *   func_021D7C7C 0x021D7C7C arm ov125
 *   func_0208CADC 0x0208CADC arm
 *   d_021DAA88 0x021DAA88 data a4
 */
#include "../include/Obj14013.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *d_021DAA88;
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 func_0208CC78(const char *);
extern char *func_021D7C7C(u32);
extern char *func_0208CADC(char *destp, const char *srcp);
void func_021D8C14(const char *s, u8 *p)
{
    MI_CpuCopy8(d_021DAA88, p, 0x830);
    if (s) {
        *(char * *)&((struct Obj14013 *)p)->f800 = func_021D7C7C(func_0208CC78(s) + 1);
        func_0208CADC(*(char * *)&((struct Obj14013 *)p)->f800, s);
    }
}
