/*
 * function: func_021DA1EC
 * address: 0x021DA1EC
 * packet: pkt_ov123_021DA1EC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   func_021D9730 0x021D9730 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 *   func_021DA1C8 0x021DA1C8 thumb ov123
 */
#include "../include/Obj03803.h"
typedef unsigned char  u8;
extern void NHTTP_RAP_DeleteConnection(u8 *p);
extern void func_021D9730(char *p, int n);
extern void func_021DA034(char *p, int n, int unused);
extern void func_021DA1C8(char *p);
void func_021DA1EC(char *p)
{
    unsigned n;
    n = ((struct Obj03803 *)p)->f70 + 11;
    if (((struct Obj03803 *)p)->f8) NHTTP_RAP_DeleteConnection(((struct Obj03803 *)p)->f8);
    if (((struct Obj03803 *)p)->f70 == 0xfff1) n = 22;
    else if (((struct Obj03803 *)p)->f70 == 0xfff2) n = 23;
    else if (((struct Obj03803 *)p)->f70 == 0xfff3) n = 20;
    else if (((struct Obj03803 *)p)->f70 >= 10) n = 20;
    func_021D9730(((struct Obj03803 *)p)->f10,n);
    func_021DA034(p,(int)func_021DA1C8,0x167);
}
