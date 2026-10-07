/*
 * function: func_02185794
 * address: 0x02185794
 * packet: pkt_ov219_02185794
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wD6 lane16): EXACT. The flag block is an if/else-if chain with h == 0 first; tail merging of the duplicate stores gives the bne/b pairs.
 * symbols:
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048B80 0x02048B80 arm
 *   func_02048B94 0x02048B94 arm
 *   func_02048B60 0x02048B60 arm
 *   func_02048B6C 0x02048B6C arm
 *   func_02185AC8 0x02185AC8 thumb ov219
 *   d_02185E0C 0x02185E0C data a4
 *   d_02185DF4 0x02185DF4 data a4
 *   d_020A1C78 0x020A1C78 data
 */

#include "../include/G_02185E0C.h"
#include "../include/G_Vec3.h"

typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 x,y,z;} Vec3;
typedef struct {char pad[0x30]; short a, b;} Cfg;
extern struct G_02185E0C d_02185E0C;
extern struct Vec3 d_02185DF4;
extern Cfg d_020A1C78;
extern void func_02048AFC(void *, Vec3 *);
extern void func_02048B44(void *, Vec3 *);
struct Light;
extern void func_02048B80(struct Light *l, u32 v);
extern void func_02048B94(struct Light *l, u32 v);
extern void func_02048B60(struct Light *l, const u32 *in);
extern void func_02048B6C(struct Light *l, const u32 *in);
extern int func_02185AC8(char *);

void func_02185794(char *p)
{
    u32 a = 0;
    u32 b = 0x19 << 14;
    func_02048AFC(*(void **)(p + 0xC36C), ((Vec3 *)&d_02185E0C));
    func_02048B44(*(void **)(p + 0xC36C), ((Vec3 *)&d_02185DF4));
    func_02048B80(*(void **)(p + 0xC36C), d_020A1C78.a);
    func_02048B94(*(void **)(p + 0xC36C), d_020A1C78.b);
    func_02048B60(*(void **)(p + 0xC36C), &a);
    func_02048B6C(*(void **)(p + 0xC36C), &b);
    if (*(u16 *)(p + 0xC31C) == 0)
        *(u16 *)(p + 0xC30C) = 1;
    else if (*(u32 *)(p + 0xC33C) == 0)
        *(u16 *)(p + 0xC30C) = 0;
    else if (*(u32 *)(p + 0xC33C) == 0xdc)
        *(u16 *)(p + 0xC30C) = 0;
    else
        *(u16 *)(p + 0xC30C) = 1;
    while (func_02185AC8(p) != 1)
        ;
}
