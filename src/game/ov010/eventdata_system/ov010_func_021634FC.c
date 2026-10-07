/*
 * function: func_021634FC
 * address: 0x021634FC
 * packet: pkt_ov010_021634FC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment at 0x0216352A before func_0216352C.
 * symbols:
 *   func_0216D608 0x0216D608 thumb ov010
 *   func_02163464 0x02163464 thumb ov010
 *   func_021AC760 0x021AC760 thumb ov021
 */
#include "../../../matched/include/Obj00110.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_0216D608(void *p);
extern int func_02163464(int a0, int a1);
extern void func_021AC760(u32 a, u32 b, u32 c, int d);
void func_021634FC(void *p, u8 *q)
{
    int flag;
    int kind;
    if (((struct Obj00110 *)q)->fE & 0x20) {
        flag = func_0216D608(p);
        kind = func_02163464(((struct Obj00110 *)q)->fA, q[24]);
        if (flag != 0)
            func_021AC760(*(u32 *)&((struct Obj00110 *)q)->f14, (u32)p, 1, kind);
    }
}
