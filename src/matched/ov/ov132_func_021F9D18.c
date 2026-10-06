/*
 * function: func_021F9D18
 * address: 0x021F9D18
 * packet: pkt_ov132_021F9D18
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F9F74 0x021F9F74 thumb ov132
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj14088.h"
typedef unsigned char u8;
typedef struct { int x, y, z; } Vec;
extern void func_021F8044(void *unused, unsigned int *p, unsigned int *q);
extern void func_021F9F74(char *, unsigned, const int *);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
void func_021F9D18(char *p, unsigned i)
{
    Vec v;
    u8 j;
    func_021F8044(((struct Obj14088 *)p)->f40, *(void **)(p + i * 4 + 0x44), (unsigned int *)(&v));
    v.x /= 16;
    v.y = (0xc0000 - (v.y - 0x20000)) / 16;
    v.z = 0xb4000;
    for (j = 0; j < 3; j++) func_021F9F74(*(char * *)&((struct Obj14088 *)p)->fBC, j, &v.x);
    func_020061E4(1961);
}
