/*
 * function: func_021FAAB8
 * address: 0x021FAAB8
 * packet: pkt_ov132_021FAAB8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj04515.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void func_021FAAB8(char *p, unsigned flag)
{
    if (((struct Obj04515 *)p)->f48 != 255) {
        CLACT_SetActorDrawEnable(((struct Obj04515 *)p)->f4C, flag);
        CLACT_SetActorDrawEnable(((struct Obj04515 *)p)->f54, flag);
    }
    if (((struct Obj04515 *)p)->f4A != 255) {
        CLACT_SetActorDrawEnable(((struct Obj04515 *)p)->f50, flag);
        CLACT_SetActorDrawEnable(((struct Obj04515 *)p)->f58, flag);
    }
    ((struct Obj04515 *)p)->fC = flag;
}
