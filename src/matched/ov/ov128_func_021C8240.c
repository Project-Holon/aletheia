/*
 * function: func_021C8240
 * address: 0x021C8240
 * packet: pkt_ov128_021C8240
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Two names reproduce the duplicate 0x021CA7C0 pool words; the
 * mutable config declaration preserves sequential halfword loads/stores.
 * symbols:
 *   func_0204B09C 0x0204B09C arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021C8A50 0x021C8A50 thumb ov128
 *   func_021C860C 0x021C860C thumb ov128
 *   d_021CA7C0 0x021CA7C0 data a4
 *   cb_021CA7C0 0x021CA7C0 data a4
 */
#include "../include/Obj00179.h"
#include "../include/Obj10484.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { s16 x, y; } Pair;
typedef void (*Callback)(u8 *, u8 *, int, int);
typedef struct { Callback cb[4]; Pair pos; } Config;
extern Config d_021CA7C0;
extern Callback cb_021CA7C0[];
typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_0204B09C(void *, int, Pair *);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_021C8A50(char *p, int unused);
extern void func_021C860C(u8 *, u8 *, u8 *, int, int, u16);
int func_021C8240(u8 *p, u8 *a, u8 *b, u16 h)
{
    Pair pos;
    int delta;
    Callback cb;
    int mode;
    if (func_0201C6B4(((struct Obj10484 *)b)->f34) == 0) return 0;
    if (((struct Obj00179 *)p)->f100 > 24) {
        pos.x = d_021CA7C0.pos.x;
        pos.y = d_021CA7C0.pos.y;
        func_0204B09C(((struct Obj10484 *)b)->f140, 0, &pos);
        mode = ((struct Obj00179 *)p)->f102 == 2 ? 2 : 1;
        func_021C8A50((char *)(p + 12 + mode * 76), (int)b);
        func_021C860C(p, a, b, ((struct Obj00179 *)p)->f0, ((struct Obj00179 *)p)->f4, h);
        return 1;
    }
    delta = (((struct Obj00179 *)p)->f100 * 256) / 24;
    if (((struct Obj00179 *)p)->f102 == 2) delta = -delta;
    func_02041EE4(2, 0, delta);
    func_02041EE4(3, 0, delta);
    pos.x = d_021CA7C0.pos.x;
    pos.y = d_021CA7C0.pos.y;
    pos.x += (s16)delta;
    func_0204B09C(((struct Obj10484 *)b)->f140, 0, &pos);
    mode = ((struct Obj00179 *)p)->f100;
    if (mode % 6 != 0) {
        cb = cb_021CA7C0[mode / 6];
        if (cb != 0) cb(p, b, ((struct Obj00179 *)p)->f0, *(s16 *)&((struct Obj00179 *)p)->f2);
    }
    (((struct Obj00179 *)p)->f100)++;
    return 0;
}
