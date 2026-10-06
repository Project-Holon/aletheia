/*
 * function: func_02184C48
 * address:  0x02184C48
 * packet:   pkt_ov023_02184C48
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020275E4  0x020275E4  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   d_020A1448     0x020A1448  data  a4
 *   d_02186ACC     0x02186ACC  data  ov023  a4
 *   func_0204B100  0x0204B100  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02027618  0x02027618  thumb
 *   func_02027614  0x02027614  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_02049238  0x02049238  arm
 */
#include "../include/Obj00049.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;

extern u8 d_020A1448[];
extern u8 d_02186ACC[];
extern u32 func_020275E4(void);
extern void *func_020490F4(unsigned int id, u16 heap);
struct Bank;
struct Cfg;
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
typedef signed int     s32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void func_02049238(void *h);

void func_02184C48(u8 *p, void *q)
{
    void *h;
    u32 t;

    h = func_020490F4(func_020275E4(), 0x28);
    func_0204A48C((const struct Cfg *)d_020A1448, (u32)d_02186ACC, 0x28);
    ((struct Obj00049 *)p)->f38 = (u32)func_0204B100(0x35, 1, 0x28);
    ((struct Obj00049 *)p)->f40 = func_0204A6C8(q, 3, 0, 0, 0x28);
    ((struct Obj00049 *)p)->f3C = func_0204ABF0(q, 0, 0, 0, 0x28);
    ((struct Obj00049 *)p)->f44 = func_0204AF28(q, 5, 8, 0x28);
    ((struct Obj00049 *)p)->f4C = func_0204A6C8(h, func_02027618(), 0, 0, 0x28);
    ((struct Obj00049 *)p)->f48 = func_0204AC18(h, func_02027614(), 0, 0x160, 0, 3, 0x28);
    t = func_0202761C(0);
    ((struct Obj00049 *)p)->f50 = func_0204AF28(h, t, func_02027620(0), 0x28);
    ((struct Obj00049 *)p)->f58 = func_0204A6C8(q, 3, 0, 1, 0x28);
    ((struct Obj00049 *)p)->f54 = func_0204ABF0(q, 0, 1, 0, 0x28);
    ((struct Obj00049 *)p)->f5C = func_0204AF28(q, 5, 8, 0x28);
    func_02049238(h);
}
