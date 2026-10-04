/*
 * function: func_021D478C
 * address: 0x021D478C
 * packet: pkt_ov123_021D478C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: seven independent offset locals each receive 0x2ac then their final literal; both spill stores survive.
 * symbols:
 *   d_021DA638 0x021DA638 data a1
 *   d_021DA634 0x021DA634 data a1
 *   d_021DA63C 0x021DA63C data a1
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 */
#include "../include/Obj00471.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Point { u16 x, y, z; u8 a, b; };
struct Triple { u8 v[3]; };
extern const struct Triple d_021DA638, d_021DA634, d_021DA63C;
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Actor;
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
void func_021D478C(char *p)
{
    struct Triple x, y, z;
    struct Point pt;
    int i;
    int o1, o2, o3, o4, o5, o6, o7;
    x = d_021DA638;
    y = d_021DA634;
    z = d_021DA63C;
    i = 0;
    o1 = 0x2ac; o1 = 0x294;
    o2 = 0x2ac; o2 = 0x290;
    o3 = 0x2ac; o3 = 0x298;
    o4 = 0x2ac; o4 = 0x2a0;
    o5 = 0x2ac; o5 = 0x2a0;
    o6 = 0x2ac; o6 = 0x2a0;
    o7 = 0x2ac; o7 = 0x2a0;
    for (; i < 3; i++) {
        pt.x = x.v[i]; pt.y = y.v[i]; pt.z = z.v[i];
        pt.a = 0; pt.b = 2;
        *(void **)(p + i * 4 + o4) = func_0204B294((void *)((struct Obj00471 *)p)->f2AC, (unsigned int)*(void **)(p + o1), *(u32 *)(p + o2), *(u32 *)(p + o3), &pt, 1, ((struct Obj00471 *)p)->fC);
        func_0204B92C(*(void **)(p + i * 4 + o5), 0);
        func_0204B3DC(*(void **)(p + i * 4 + o6), 1);
        func_0204B688(*(void **)(p + i * 4 + o7), 1);
    }
}
