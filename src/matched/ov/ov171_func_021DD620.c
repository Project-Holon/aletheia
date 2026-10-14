/*
 * function: DENDOU_VIEW_StartRotation
 * address: 0x021DD620
 * packet: pkt_ov171_021DD620
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: A u16 count preserves the word spill at sp+0; bind the final quotient
 *   before multiplying. Explicit runtime calls preserve the zero divisor path.
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 *   sAngleSpacingByCount 0x021DEB56 data
 */
#include "../include/Obj00347.h"
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
extern int _s32_div_f(int, int);
extern const u8 sAngleSpacingByCount[];

void DENDOU_VIEW_StartRotation(char *p, int step) {
    s16 dst = ((struct Obj00347 *)p)->fC5C;
    s16 src = dst + step;
    unsigned i;
    int angle;
    u16 count;
    if (src < 0) {
        count = *(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4);
        src += (s16)count;
    } else {
        count = *(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4);
        if (src >= count) src -= (s16)count;
    }
    for (i = 0; i < (unsigned)count; i++) {
        *(s16 *)(p + dst * 2 + 0xb1c) = *(s16 *)(p + src * 2 + 0xb10);
        *(u8 *)(p + dst + 0xb40) = *(u8 *)(p + src + 0xb34);
        dst += (s16)_s32_div_f(step, step < 0 ? -step : step);
        if (dst < 0) {
            count = *(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4);
            dst = count - 1;
        } else {
            count = *(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4);
            if (dst >= count) dst = 0;
        }
        src += (s16)_s32_div_f(step, step < 0 ? -step : step);
        if (src < 0) src = count - 1;
        else if (src >= count) src = 0;
    }
    angle = ((struct Obj00347 *)p)->fC61;
    if (angle < 0) angle = -angle;
    if (step < 0) step = -step;
    angle = _s32_div_f(sAngleSpacingByCount[count - 1], angle);
    ((struct Obj00347 *)p)->fC62 = angle * step;
}
