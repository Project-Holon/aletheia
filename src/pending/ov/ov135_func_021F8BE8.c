/*
 * function: func_021F8BE8
 * address:  0x021F8BE8
 * packet:   pkt_021F8BE8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker: one hop: the image leaves the inner switch's out-of-range exit as its own 'b' (0x021F8C90 -> 0x021F8CEC) that 1.1p1 threads away here, so this build is 292 bytes against 296. Every other instruction matches. Notes and measurements are in docs/notes/pkt_021F8BE8.c.txt.
 *
  *
  *
  *
  *
  *
 * symbols:
 *   func_021C7C1C  0x021C7C1C  arm  ov114
 *   func_021C866C  0x021C866C  arm  ov114
 *   func_021C86A8  0x021C86A8  arm  ov114
 *   func_021F4FC4  0x021F4FC4  thumb
 *   func_021F513C  0x021F513C  thumb
 *   func_021F4EC0  0x021F4EC0  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0x38];
    int err;
    u8 pad3C[0xF7C - 0x3C];
    int state;
    int sub;
    u8 padF84[0xF8C - 0xF84];
    int wait;
} Work;

extern void func_021C7C1C(void);
extern int func_021C866C(void);
extern int func_021C86A8(void);
extern void func_021F4FC4(Work *p);
extern void func_021F513C(Work *p);
extern void func_021F4EC0(Work *p, u32 a, u32 b);

int func_021F8BE8(Work *p)
{
    int code;

    func_021C7C1C();
    if (func_021C866C() != 0) {
        code = func_021C86A8();
        p->wait = 0;
        switch (code) {
        case 0:
            switch (p->state) {
            case 0:
                switch (p->sub) {
                case 0:
                    func_021F4EC0(p, 1, 0);
                    return 1;
                case 3:
                    p->err = -5003;
                    return 2;
                case 1:
                    p->err = -5000;
                    return 2;
                case 2:
                    p->err = -5001;
                    return 2;
                }
                break;
            case 1:
                p->err = -5004;
                return 2;
            case 2:
                p->err = -5005;
                return 2;
            default:
                func_021F4FC4(p);
                break;
            }
            break;
        case 1:
            func_021F4FC4(p);
            p->err = code;
            return 2;
        case -1:
        case 2:
            func_021F4FC4(p);
            p->err = code;
            return 2;
        case -15:
        case -12:
            func_021F4FC4(p);
            p->err = code;
            return 2;
        case -14:
        case -2:
            func_021F4FC4(p);
            p->err = code;
            return 2;
        default:
            func_021F4FC4(p);
            break;
        }
        func_021F513C(p);
    } else if (++p->wait == 0xE10) {
        func_021F513C(p);
    }
    return 0;
}
