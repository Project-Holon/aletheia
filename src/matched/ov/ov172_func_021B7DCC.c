/*
 * function: func_021B7DCC
 * address: 0x021B7DCC
 * packet: pkt_ov172_021B7DCC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_LOWER_DATA_Exit 0x0203E6C0 arm
 *   func_020307B0 0x020307B0 arm
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 *   func_021BE0D8 0x021BE0D8 thumb ov172
 */
#include "../include/Obj06559.h"
typedef unsigned char u8;
extern void GFL_NET_LOWER_DATA_Exit(void);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void GFL_NET_FreeAligned(void *);
extern int func_021BE0D8(void *);
void func_021B7DCC(void *p, char *q)
{
    u8 i;
    GFL_NET_LOWER_DATA_Exit();
    func_020307B0(((struct Obj06559 *)q)->f1A8);
    func_020307B0(((struct Obj06559 *)q)->f1A4);
    GFL_NET_FreeAligned(((struct Obj06559 *)q)->f18C);
    GFL_NET_FreeAligned(((struct Obj06559 *)q)->f190);
    GFL_NET_FreeAligned(((struct Obj06559 *)q)->f188);
    for (i = 0; i < 3; i++) {
        if (func_021BE0D8(p) == 0 || i == 0)
            GFL_NET_FreeAligned(*(void **)(q + i * 4 + 0x164));
    }
    func_020307B0(q);
}
