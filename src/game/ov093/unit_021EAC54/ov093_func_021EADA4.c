/*
 * function: func_021EADA4
 * address: 0x021EADA4
 * packet: pkt_ov093_021EADA4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE264 0x021EE264 thumb ov093
 */
#include "../../../matched/include/Obj21571.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct T;
extern void func_021EE264(char *, int, struct T *);
void func_021EADA4(u8 *p, int a, struct T *b)
{
    func_021EE264(*(char * *)&((struct Obj21571 *)p)->f17C, a, b);
}
