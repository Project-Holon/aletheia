/*
 * function: func_021D7D6C
 * address: 0x021D7D6C
 * packet: pkt_ov120_021D7D6C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7C1C 0x021D7C1C thumb ov120
 *   func_021D7C48 0x021D7C48 thumb ov120
 *   func_021D7D30 0x021D7D30 thumb ov120
 *   func_021D7710 0x021D7710 thumb ov120
 *   func_02051B84 0x02051B84 arm
 *   d_021D8AF8 0x021D8AF8 data a4
 */
#include "../include/Obj13937.h"
typedef unsigned short u16;
extern const int d_021D8AF8[];
extern void func_021D7C1C(char *);
extern int func_021D7C48(char *,int,int,int,int,int);
extern void func_021D7D30(char *);
extern void func_021D7710(char *);
typedef unsigned char  u8;
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
void func_021D7D6C(char *p,int a,int b)
{
    func_021D7C1C(p);
    func_021D7C48(p,0,8,7,16,6);
    func_021D7C48(p,1,8,13,16,6);
    func_021D7D30(p);
    func_021D7710(p);
    ((struct Obj13937 *)p)->f8=func_02051B84((u8 *)d_021D8AF8,a,b,((struct Obj13937 *)p)->fC8);
}
