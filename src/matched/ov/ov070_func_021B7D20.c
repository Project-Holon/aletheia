/*
 * function: func_021B7D20
 * address:  0x021B7D20
 * packet:   pkt_ov070_021B7D20
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Refresh the current slot, redraw the cell, and when it is idle count down
 * one of the two timers (clamped at 0 and at -1).
 *
 * symbols:
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_02007F1C  0x02007F1C  thumb
 *   func_02007FB8  0x02007FB8  thumb
 */

typedef unsigned short u16;

typedef struct Obj {
    unsigned char pad000[0x18];
    void *gfx;
    unsigned char pad01C[0x544 - 0x1C];
    u16 f544;
    unsigned char pad546[0x810 - 0x546];
    int timerA;
    int timerB;
    unsigned char pad818[0x84C - 0x818];
    int cell;
} Obj;

extern int func_021B61B8(Obj *o);
extern void func_021B616C(Obj *o, int v);
extern int func_021B61C8(Obj *o);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);

void func_021B7D20(Obj *o, int x)
{
    int v;

    func_021B616C(o, func_021B61B8(o));
    func_02007F1C(o->gfx, o->cell, x, o->f544);
    if (func_02007FB8(o->gfx, o->cell, o->f544) != 0)
        return;
    if (func_021B61C8(o) + 1 < 7) {
        v = o->timerA - 1;
        if (v <= 0)
            v = 0;
        o->timerA = v;
    } else {
        v = o->timerB - 1;
        if (v < -1)
            v = -1;
        o->timerB = v;
    }
}
