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
 *   sub_0204B3DC 0x0204B3DC arm
 *   sub_0202DCC4 0x0202DCC4 thumb
 *   func_0202DCB0 0x0202DCB0 thumb
 *   sub_02040588 0x02040588 arm
 */
#include "../include/Obj00051.h"
#include "../include/Obj08428.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
struct Obj0202DCC4;
struct Obj0202DC98;
extern void sub_0204B3DC(struct Obj *, u32);
extern u32 sub_0202DCC4(const struct Obj0202DCC4 *, u32);
extern void func_0202DCB0(struct Obj0202DC98 *, int, u32);
extern void sub_02040588(unsigned char which, unsigned char enable);
void func_021BD0E4(char *p, u8 index, u32 enable)
{
    char *entry;
    entry = p + 0x15c + index * 128;
    sub_0204B3DC(*(struct Obj * *)&((struct Obj08428 *)entry)->f78, enable);
    if (((struct Obj08428 *)entry)->f7D != 0)
        sub_0204B3DC(*(struct Obj * *)&((struct Obj08428 *)entry)->f74, enable);
    if (sub_0202DCC4(*(struct Obj0202DCC4 * *)&((struct Obj00051 *)p)->f158, index) != 0)
        func_0202DCB0(*(struct Obj0202DC98 * *)&((struct Obj00051 *)p)->f158, index, enable);
    sub_02040588(((struct Obj08428 *)entry)->f7E, (u8)enable);
}
