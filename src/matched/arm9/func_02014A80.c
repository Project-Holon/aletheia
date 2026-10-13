/*
 * function: func_02014A80
 * address:  0x02014A80
 * packet:   pkt_02014A80
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TIMEZONE_GetZoneLightLevel  0x02011400  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *
 * Scans the 0x34-byte-stride table at a0 for the element whose 3600*hour +
 * 60*minute value first climbs past a2 while the best so far is still at or
 * below it, then returns that element's eight halfword fields through the
 * caller's buffer (the four at +8 and the four at +0x28).
 *
 * Shape notes:
 *  - the index runs from 0 and the loop is entered only when a1 != 0, so the
 *    counter's first comparison sits at the bottom (`cmp r4, a1 / blo`) and
 *    the guard at the top is a bare `adds r0, r1, #0 / beq`);
 *  - the element's +2 field is signed (`ldrsh` with a register offset,
 *    docs/idioms/ldrsh-register-offset-is-signedness.md), which is why both
 *    comparisons on the running value are `bgt`;
 *  - `i % a1` is one call to the unsigned divmod helper with the remainder
 *    read out of r1, so the source must stay a modulo expression and not a
 *    hand-rolled subtraction loop;
 *  - the two products are two statements (`v = 0xE10 * ...; v += ...;`).
 *    Written as one expression mwcc evaluates the s16 arm first and the
 *    15-byte window at +0x2C comes out in the other order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014A80.c \
 *       --func func_02014A80 --addr 0x02014A80 --cc 1.1p1 --thumb
 */
#include "../include/Obj02990.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 TIMEZONE_GetZoneLightLevel(int row, int col);
extern u32 _u32_div_f(u32, u32);

void func_02014A80(u8 *a0, u32 a1, s32 a2, u32 a3, u16 *out)
{
    u32 i;
    s32 best;
    s32 v;
    u32 k;
    u8 *e;

    best = 0;
    i = 0;
    if (a1 != 0) {
        do {
            e = a0 + i * 0x34;
            v = 0xE10 * (s32)TIMEZONE_GetZoneLightLevel(a3, *(u16 *)(a0 + i * 0x34));
            v += ((struct Obj02990 *)e)->f2 * 0x3C;
            if (best <= a2 && v > a2) {
                break;
            }
            best = v;
            i++;
        } while (i < a1);
    }

    k = i % a1;
    e = a0 + k * 0x34;
    out[0] = ((struct Obj02990 *)e)->f8;
    out[1] = ((struct Obj02990 *)e)->fA;
    out[2] = ((struct Obj02990 *)e)->fC;
    out[3] = ((struct Obj02990 *)e)->fE;
    out[4] = ((struct Obj02990 *)e)->f28;
    out[5] = ((struct Obj02990 *)e)->f2A;
    out[6] = ((struct Obj02990 *)e)->f2C;
    out[7] = ((struct Obj02990 *)e)->f2E;
}
