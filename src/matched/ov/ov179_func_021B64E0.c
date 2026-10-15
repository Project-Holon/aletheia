/*
 * function: CDEMO_SCENE_Step
 * address:  0x021B64E0
 * packet:   pkt_021B64E0
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frame-paced step: accumulates OS_GetTick deltas in microseconds and
 * advances one 66,667 us (15 Hz) step at a time. The entry table must be
 * const: that is what lets the e->b load schedule ahead of the count store.
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   func_0204047C  0x0204047C  arm
 *   CDEMO_SCENE_LoadScreenBlock  0x021B669C  thumb  ov179
 *   data_021B6A1C  0x021B6A1C  data  ov179
 *   _ull_mul       0x0209C054  arm
 *   _ll_udiv       0x0209C00C  arm
 */
#include "../include/Obj00546.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

typedef struct {
    u16 unk0;
    u16 count;
    int a;
    int b;
} Entry;

extern const Entry data_021B6A1C[];
extern u64 func_020870D0(void);
extern void func_0204047C(int idx, unsigned short val);
extern void CDEMO_SCENE_LoadScreenBlock(int, int, int, int, int);

int CDEMO_SCENE_Step(char *p)
{
    const Entry *e = &data_021B6A1C[**(u16 * *)&((struct Obj00546 *)p)->f0];

    if (((struct Obj00546 *)p)->f6040 == 0) {
        ((struct Obj00546 *)p)->f6040 = func_020870D0();
    } else {
        u64 now = func_020870D0();
        ((struct Obj00546 *)p)->f6048 += (now - ((struct Obj00546 *)p)->f6040) * 64000 / 33514;
        ((struct Obj00546 *)p)->f6040 = now;
        if (((struct Obj00546 *)p)->f6048 < 66667)
            return 4;
        ((struct Obj00546 *)p)->f6048 -= 66667;
    }

    switch (((struct Obj00546 *)p)->f603F) {
    case 0:
        CDEMO_SCENE_LoadScreenBlock(((struct Obj00546 *)p)->f4, ((struct Obj00546 *)p)->f603C, e->b, e->a, 0);
        (((struct Obj00546 *)p)->f603C)++;
        CDEMO_SCENE_LoadScreenBlock(((struct Obj00546 *)p)->f4, ((struct Obj00546 *)p)->f603C, e->b, e->a, 1);
        (((struct Obj00546 *)p)->f603C)++;
        func_0204047C((u8)2, (u8)0);
        func_0204047C((u8)3, (u8)1);
        ((struct Obj00546 *)p)->f603F = 1;
        break;
    case 1:
        func_0204047C((u8)((((struct Obj00546 *)p)->f603E ^ 1) + 2), (u8)0);
        func_0204047C((u8)(((struct Obj00546 *)p)->f603E + 2), (u8)1);
        CDEMO_SCENE_LoadScreenBlock(((struct Obj00546 *)p)->f4, ((struct Obj00546 *)p)->f603C, e->b, e->a, ((struct Obj00546 *)p)->f603E);
        (((struct Obj00546 *)p)->f603C)++;
        if (((struct Obj00546 *)p)->f603C >= e->count) {
            ((struct Obj00546 *)p)->f603F = 2;
        } else {
            ((struct Obj00546 *)p)->f603E ^= 1;
        }
        break;
    case 2:
        func_0204047C((u8)(((struct Obj00546 *)p)->f603E + 2), (u8)0);
        func_0204047C((u8)((((struct Obj00546 *)p)->f603E ^ 1) + 2), (u8)1);
        ((struct Obj00546 *)p)->f603F = 3;
        break;
    case 3:
        return 5;
    }
    return 4;
}
