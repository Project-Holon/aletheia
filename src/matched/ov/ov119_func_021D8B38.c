/*
 * function: func_021D8B38
 * address: 0x021D8B38
 * packet: pkt_ov119_021D8B38
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DB7AC 0x021DB7AC thumb ov119
 */
#include "../include/Obj00001.h"
extern void func_021DB7AC(char *,int,int);
void func_021D8B38(char *p)
{
    ((struct Obj00001 *)p)->f1080 += 1;
    ((struct Obj00001 *)p)->f1084 = 1;
    func_021DB7AC(p, 0, 0);
}
