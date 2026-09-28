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

typedef unsigned long u32;

typedef int (*RoundFn)(char *ctx, char *peer, int dir, int flag);

extern int func_021DF23C(int a, int b, int c, void *out);
extern int func_021DF298(u32 h);
extern int func_021DF2C8(u32 h);
extern int func_021DF2F8(u32 h);
extern int func_021DF328(u32 h);
extern int func_021DF358(u32 h, int dir, void *buf, int d, int mode, u32 id, void *aux);
extern int func_021DF3B0(u32 h, u32 a, int flag);
extern void func_02034714(const char *file, int line, const char *msg);
extern const char d_021E2EF8[];

int func_021DAE54(char *ctx, char *other, char *peer, u32 a3, RoundFn cb, int flag, int have, int twoway)
{
    int r;
    int mode;
    int mode2;

    if ((r = func_021DF23C(1, 2, 0, ctx + 4)) != 0)
        return r;
    if ((r = func_021DF298(*(u32 *)(ctx + 4))) != 0)
        return r;
    if ((r = func_021DF2C8(*(u32 *)(ctx + 4))) != 0)
        return r;
    if ((r = func_021DF328(*(u32 *)(ctx + 4))) != 0)
        return r;

    if (flag != 0 || have == 0) {
        mode = 5;
    } else {
        switch (*(u32 *)(peer + 4)) {
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
    if ((r = func_021DF358(*(u32 *)(ctx + 4), 0, ctx + 0x30, 0, mode, *(u32 *)ctx, ctx + 0x58)) != 0)
        return r;
    if ((r = cb(ctx, peer, 1, flag)) != 0)
        return r;
    if ((r = func_021DF328(*(u32 *)(ctx + 4))) != 0)
        return r;

    if (twoway == 1) {
        if (have == 0) {
            mode2 = 5;
        } else if (flag != 0) {
            mode2 = 3;
        } else {
            switch (*(u32 *)(peer + 4)) {
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
        if ((r = func_021DF358(*(u32 *)(ctx + 4), 1, other + 0x30, 0, mode2, *(u32 *)other, other + 0x58)) != 0)
            return r;
        if ((r = cb(ctx, peer, 0, flag)) != 0)
            return r;
    }
    if ((r = func_021DF2F8(*(u32 *)(ctx + 4))) != 0)
        return r;
    if (flag != 0)
        return func_021DF3B0(*(u32 *)(ctx + 4), a3, 1);
    return func_021DF3B0(*(u32 *)(ctx + 4), a3, 0);
}
