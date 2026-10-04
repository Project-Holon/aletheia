/*
 * function: func_021FC360
 * address: 0x021FC360
 * packet: pkt_ov135_021FC360
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0203D34C 0x0203D34C arm
 */
#include "../include/Obj03298.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x, y, z; u8 pri, f7; } ObjPos;
extern void func_02082BCC(void *, int, int);
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B84C(void *, int);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0203D34C(u32 a, u32 b);
void func_021FC360(char *p)
{
    ObjPos pos;
    func_02082BCC(&pos, 0, sizeof(pos));
    pos.x = 0xd0;
    pos.y = 0x3a;
    ((struct Obj03298 *)p)->fD08 = func_0204B294(((struct Obj03298 *)p)->fBC0, (unsigned int)((struct Obj03298 *)p)->fBC4, (unsigned int)((struct Obj03298 *)p)->fBC8, (unsigned int)((struct Obj03298 *)p)->fBCC, &pos, 0, 0x48);
    func_0204B92C(((struct Obj03298 *)p)->fD08, 1);
    func_0204B878(((struct Obj03298 *)p)->fD08, 0x24);
    func_0204B84C(((struct Obj03298 *)p)->fD08, 1);
    func_0204B3DC(((struct Obj03298 *)p)->fD08, 1);
    func_0203D34C(0, 0x48);
}
