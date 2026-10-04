/*
 * function: func_021B9BDC
 * address:  0x021B9BDC
 * packet:   pkt_ov070_021B9BDC
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_021B9BA0  0x021B9BA0  thumb  ov070
 *   func_020456F8  0x020456F8  arm
 *   func_02045374  0x02045374  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_021BB6E0  0x021BB6E0  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   func_021B9850  0x021B9850  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;

typedef signed int     s32;
typedef unsigned char  u8;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_021B9BA0(char *);
struct Cfg;
struct Descriptor;
struct MsgBank;
extern void func_020456F8(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void *func_020490F4(unsigned int id, u16 heap);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021BB6E0(int p, u32 *obj, u32 str, u16 x, s16 y, u16 color);
extern u8 func_020355C4(void);
extern void func_021B9850(char *);

void func_021B9BDC(char *p)
{
    void *bg;

    ((struct Obj00002 *)p)->f774 = func_020450F0(3, 0x12, 9, 0xc, 3, 3, 1);
    func_021B9BA0(p);
    func_020456F8((struct Descriptor *)(((struct Obj00002 *)p)->f774));
    ((struct Obj00002 *)p)->f754 = func_020450F0(3, 0x11, 0xd, 0xb, 2, 3, 1);
    ((struct Obj00002 *)p)->f76C = func_020450F0(3, 0x11, 0xf, 0xb, 2, 3, 1);
    ((struct Obj00002 *)p)->f734 = func_020450F0(6, 0, 0x13, 0x20, 5, 0, 1);
    ((struct Obj00002 *)p)->f73C = func_020450F0(6, 7, 5, 0x12, 3, 0, 1);
    *(int *)&((struct Obj00002 *)p)->f744 = func_020450F0(6, 0x14, 8, 6, 3, 0, 1);
    ((struct Obj00002 *)p)->f74C = func_020450F0(6, 2, 0xc, 0x1d, 7, 0, 1);
    func_02045374((struct Cfg *)(((struct Obj00002 *)p)->f73C));
    func_02045374((struct Cfg *)(*(int *)&((struct Obj00002 *)p)->f744));
    func_02045374((struct Cfg *)(((struct Obj00002 *)p)->f74C));
    func_02045374((struct Cfg *)(((struct Obj00002 *)p)->f734));
    bg = func_020490F4(0x19, ((struct Obj00002 *)p)->f544);
    ((struct Obj00002 *)p)->f550 = func_0204AF28(bg, 1, 0, ((struct Obj00002 *)p)->f544);
    func_02049238(bg);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x66, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 8, 4, 0x3DC0);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5d, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 8, 0x18, 0x3DC0);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5b, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 0x70, 4, 0x3DC0);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5c, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 0x70, 0x18, 0x3DC0);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5a, (void *)(((struct Obj00002 *)p)->f524));
    func_021BB6E0((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 0xd0, 4, 0x3DC0);
    if (func_020355C4() == 0) {
        func_021B9850(p);
    }
}
