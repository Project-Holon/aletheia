/*
 * function: func_021DE144
 * address: 0x021DE144
 * packet: pkt_ov171_021DE144
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020275E4 0x020275E4 thumb
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj01756.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;
extern u32 func_020275E4(void);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern void *func_020490F4(u32 id, u16 heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(u8 *);
void func_021DE144(char *p)
{
    unsigned i;
    u8 *s;
    int a;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xbb4 + i * 4) = -1;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xbe8 + i * 4) = -1;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xc1c + i * 4) = -1;
    s = func_020490F4(func_020275E4(), 0x808c);
    ((struct Obj01756 *)p)->fBE4 = func_0204A6C8(s, func_02027618(), 0, 0, 0x8c);
    *(int *)&((struct Obj01756 *)p)->fC18 = func_0204ABF0(s, func_02027614(), 0, 0x180, 0x8c);
    a = func_0202761C(2);
    ((struct Obj01756 *)p)->fC4C = func_0204AF28(s, a, func_02027620(2), 0x8c);
    func_02049238(s);
}
