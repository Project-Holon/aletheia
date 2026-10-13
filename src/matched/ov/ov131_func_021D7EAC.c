/*
 * function: P_STA_INFO_HidePage
 * address: 0x021D7EAC
 * packet: pkt_ov131_021D7EAC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041570 0x02041570 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj10512.h"

extern void func_02041300(unsigned int, int, int, int, unsigned char, unsigned char, unsigned char);
extern void func_02041B6C(unsigned int);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void func_02041570(int channel, u16 val);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
void P_STA_INFO_HidePage(unsigned char *p, void *a1)
{
    func_02041300(1, 0, 0, 0, 19, 21, 16);
    func_02041B6C(1);
    func_02041570(4, 0);
    func_02041B6C(4);
    func_0204B3DC(((struct Obj10512 *)p)->f198, 0);
    func_0204B3DC(((struct Obj10512 *)p)->f19C, 0);
    func_0204B878(((struct Obj10512 *)p)->f178, 0);
}
