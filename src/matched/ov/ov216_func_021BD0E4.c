/*
 * function: func_021BD0E4
 * address: 0x021BD0E4
 * packet: pkt_ov216_021BD0E4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   sub_0202DCC4 0x0202DCC4 thumb
 *   PMS_DRAW_SetVisible 0x0202DCB0 thumb
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 */
#include "../include/Obj00051.h"
#include "../include/Obj08428.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
struct Obj0202DCC4;
struct Obj0202DC98;
extern void CLACT_SetActorDrawEnable(struct Obj *, u32);
extern u32 sub_0202DCC4(const struct Obj0202DCC4 *, u32);
extern void PMS_DRAW_SetVisible(struct Obj0202DC98 *, int, u32);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
void func_021BD0E4(char *p, u8 index, u32 enable)
{
    char *entry;
    entry = p + 0x15c + index * 128;
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj08428 *)entry)->f78, enable);
    if (((struct Obj08428 *)entry)->f7D != 0)
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj08428 *)entry)->f74, enable);
    if (sub_0202DCC4(*(struct Obj0202DCC4 * *)&((struct Obj00051 *)p)->f158, index) != 0)
        PMS_DRAW_SetVisible(*(struct Obj0202DC98 * *)&((struct Obj00051 *)p)->f158, index, enable);
    BG_SYS_SetPlaneVisible(((struct Obj08428 *)entry)->f7E, (u8)enable);
}
