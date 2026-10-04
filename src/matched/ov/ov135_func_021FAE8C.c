/*
 * function: func_021FAE8C
 * address: 0x021FAE8C
 * packet: pkt_ov135_021FAE8C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9660 0x021F9660 thumb ov135
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   tbl_022033FC 0x022033FC data a4
 */
#include "../include/Obj00098.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021F9660(void *, int);
extern const int tbl_022033FC[][2];
int func_021FAE8C(u8 *p)
{
    if (func_0204B98C(((struct Obj00098 *)p)->f8)) return -1;
    func_021F9660(p, 4);
    func_0204B3DC(((struct Obj00098 *)p)->f8, 0);
    if (((struct Obj00098 *)p)->f38 >= 0) {
        if (tbl_022033FC[((struct Obj00098 *)p)->f38][0] != 1)
            ((struct Obj00098 *)p)->f48 = 10;
        else {
            ((struct Obj00098 *)p)->f3A = 0;
            ((struct Obj00098 *)p)->f48 = 14;
        }
    } else return -2;
    return -1;
}
