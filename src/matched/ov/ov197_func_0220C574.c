/*
 * function: func_0220C574
 * address: 0x0220C574
 * packet: pkt_ov197_0220C574
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220BB98 0x0220BB98 thumb ov197
 *   func_0220BBD8 0x0220BBD8 thumb ov197
 *   func_0220C180 0x0220C180 thumb ov197
 *   func_0220C220 0x0220C220 thumb ov197
 *   func_0220C4D4 0x0220C4D4 thumb ov197
 *   func_0220C724 0x0220C724 thumb ov197
 *   func_0220C6F8 0x0220C6F8 thumb ov197
 *   d_0220DB88 0x0220DB88 data a4
 */
#include "../include/Obj01075.h"
#include "../include/Obj25037.h"
#include "../include/Obj25038.h"
#include "../include/Obj25039.h"
#include "../include/Obj25040.h"
#include "../include/Obj25041.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Pair { short x, y; };
extern const struct Pair d_0220DB88[];
extern unsigned func_0220BB98(const char *, unsigned);
typedef unsigned int   u32;
extern int func_0220BBD8(u32 key);
extern void func_0220C180(char *, unsigned, unsigned, unsigned);
extern void func_0220C220(char *, unsigned, unsigned);
extern void func_0220C4D4(int, int);
extern void func_0220C724(char *, u16, u8, u8, const struct Pair *);
extern void func_0220C6F8(u8 *, unsigned, unsigned);
void func_0220C574(char *p)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        unsigned item = func_0220BB98(p, i);
        if (item) {
            func_0220C180(p, item, i, i);
            func_0220C220(p, item, i);
            func_0220C4D4(*(int *)(p + i * 4 + 0x424), (int)&d_0220DB88[i]);
            if (((struct Obj25037 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8 == 1)
                func_0220C724(p, i * 8 + 7, func_0220BBD8(item), 0, &d_0220DB88[i + 6]);
        }
    }
    if (((struct Obj25038 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8 == 1)
        func_0220C724(p, 55, ((struct Obj25039 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f14, ((struct Obj25040 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f15, &d_0220DB88[i + 6]);
    if (((struct Obj25041 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8 == 2) func_0220C6F8((u8 *)p, 64, 16);
}
