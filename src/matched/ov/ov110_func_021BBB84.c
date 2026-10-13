/*
 * function: func_021BBB84
 * address: 0x021BBB84
 * packet: pkt_ov110_021BBB84
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021BB224 0x021BB224 thumb ov110
 *   func_0204B404 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj05290.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { s16 x, y; } Vec2;
typedef unsigned int   u32;
struct Obj;
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u8 func_021BF6DC(u8 *);
extern void func_021BB224(unsigned, int *, int *);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void func_021BBB84(u8 *p, unsigned index)
{
    Vec2 pos;
    int x, y;
    int state;
    ((struct Obj05290 *)p)->f58 = func_0204B3F4(((struct Obj05290 *)p)->f54);
    func_0204B3DC(((struct Obj05290 *)p)->f54, 1);
    if (func_021BF6DC(*(u8 * *)&((struct Obj05290 *)p)->f4) == 0 && index != 254) {
        pos.x = 48 + 80 * (index % 3U);
        pos.y = 64 + 24 * (index / 3U);
        state = 31;
    } else {
        state = 16;
        switch (index) {
        case 252: case 253: case 254: break;
        default:
            func_021BB224(index, &x, &y);
            pos.x = x + 18;
            pos.y = y + 56;
            state = 30;
            break;
        }
    }
    func_0204B404(((struct Obj05290 *)p)->f54, (const struct Vec2 *)(&pos), 0);
    CLACT_SetActorAnimSeq(((struct Obj05290 *)p)->f54, state);
}
