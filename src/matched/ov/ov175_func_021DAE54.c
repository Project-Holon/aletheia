/*
 * function: func_021DAE54
 * address:  0x021DAE54
 * packet:   pkt_021DAE54
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DF23C  0x021DF23C  arm
 *   func_021DF298  0x021DF298  arm
 *   func_021DF2C8  0x021DF2C8  arm
 *   func_021DF2F8  0x021DF2F8  arm
 *   func_021DF328  0x021DF328  arm
 *   func_021DF358  0x021DF358  arm
 *   func_021DF3B0  0x021DF3B0  arm
 *   func_02034714  0x02034714  arm
 *   d_021E2EF8     0x021E2EF8  data
 *
 * One exchange round: bails with the first nonzero status of the four session checks, sends the local record (mode from the peer kind), runs the callback, optionally sends the peer's record back and runs the callback again, then closes with the flag.
 */
#include "../include/Obj02887.h"
#include "../include/Obj14337.h"
#include "../include/Obj24332.h"

typedef unsigned long u32;

typedef int (*RoundFn)(char *ctx, char *peer, int dir, int flag);

typedef signed int     s32;
extern int func_021DF23C(u32 a0, u32 a1, u32 a2, u32 a3);
extern int func_021DF298(u32 h);
extern int func_021DF2C8(u32 h);
extern int func_021DF2F8(u32 h);
extern int func_021DF328(u32 h);
extern s32 func_021DF358(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, char *a5, s32 a6);
extern int func_021DF3B0(u32 h, u32 a, int flag);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_021E2EF8[];

int func_021DAE54(char *ctx, char *other, char *peer, u32 a3, RoundFn cb, int flag, int have, int twoway)
{
    int r;
    int mode;
    int mode2;

    if ((r = func_021DF23C(1, 2, 0, (u32)(ctx + 4))) != 0)
        return r;
    if ((r = func_021DF298(((struct Obj02887 *)ctx)->f4)) != 0)
        return r;
    if ((r = func_021DF2C8(((struct Obj02887 *)ctx)->f4)) != 0)
        return r;
    if ((r = func_021DF328(((struct Obj02887 *)ctx)->f4)) != 0)
        return r;

    if (flag != 0 || have == 0) {
        mode = 5;
    } else {
        switch (((struct Obj14337 *)peer)->f4) {
        case 1:
        case 4:
            mode = 0;
            break;
        case 0:
        case 3:
            mode = 1;
            break;
        case 2:
            mode = 2;
            break;
        default:
            func_02034714(d_021E2EF8, 0, d_021E2EF8);
            break;
        }
    }
    if ((r = func_021DF358(((struct Obj02887 *)ctx)->f4, 0, (s32)(ctx + 0x30), 0, mode, (char *)(((struct Obj02887 *)ctx)->f0), (s32)(ctx + 0x58))) != 0)
        return r;
    if ((r = cb(ctx, peer, 1, flag)) != 0)
        return r;
    if ((r = func_021DF328(((struct Obj02887 *)ctx)->f4)) != 0)
        return r;

    if (twoway == 1) {
        if (have == 0) {
            mode2 = 5;
        } else if (flag != 0) {
            mode2 = 3;
        } else {
            switch (((struct Obj14337 *)peer)->f4) {
            case 1:
            case 4:
                mode2 = 1;
                break;
            case 0:
            case 3:
                mode2 = 0;
                break;
            case 2:
                mode2 = 2;
                break;
            default:
                func_02034714(d_021E2EF8, 0, d_021E2EF8);
                break;
            }
        }
        if ((r = func_021DF358(((struct Obj02887 *)ctx)->f4, 1, (s32)(other + 0x30), 0, mode2, (char *)(((struct Obj24332 *)other)->f0), (s32)(other + 0x58))) != 0)
            return r;
        if ((r = cb(ctx, peer, 0, flag)) != 0)
            return r;
    }
    if ((r = func_021DF2F8(((struct Obj02887 *)ctx)->f4)) != 0)
        return r;
    if (flag != 0)
        return func_021DF3B0(((struct Obj02887 *)ctx)->f4, a3, 1);
    return func_021DF3B0(((struct Obj02887 *)ctx)->f4, a3, 0);
}
