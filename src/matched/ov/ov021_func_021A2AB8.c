/*
 * function: WEATHER_TASK_TickSpawner
 * address:  0x021A2AB8
 * packet:   pkt_ov021_021A2AB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    u32 f0;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fA;
    s16 fC;
    s16 fE;
    s16 f10;
    s16 f12;
    s32 f14;
    void (*f18)(u32 a, s32 b, u32 c);
} Obj;

s32 WEATHER_TASK_TickSpawner(Obj *o, u32 arg)
{
    u32 flags;
    s32 neg;

    flags = 0;
    if (o->f10 == 0) {
        flags |= 1;
    } else {
        neg = o->f10 > 0 ? 0 : 1;
        if ((o->f8 >= o->fE && neg == 0) || (o->f8 <= o->fE && neg == 1)) {
            flags |= 1;
            o->f8 = o->fE;
        }
    }
    if (o->f14 == 0) {
        flags |= 2;
    } else {
        neg = o->f14 > 0 ? 0 : 1;
        if ((o->f4 >= o->fC && neg == 0) || (o->f4 <= o->fC && neg == 1)) {
            flags |= 2;
            o->f4 = o->fC;
        }
    }
    o->f6--;
    if (o->f6 <= 0) {
        o->f18(o->f0, o->f4, arg);
        o->f6 = o->f8;
        if (!(flags & 1)) {
            o->f8 += o->f10;
        }
        if (!(flags & 2)) {
            o->fA++;
            if (o->fA >= o->f12) {
                o->fA = 0;
                o->f4 += (s16)o->f14;
            }
        }
    }
    return (flags & 1) ? 1 : 0;
}
