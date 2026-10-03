/*
 * function: func_021D2D7C
 * address:  0x021D2D7C
 * packet:   pkt_ov021_021D2D7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task step: case 2 swings the object on a sine of tick/steps. The zero
 * vector is a block-scoped `= {0, 0, 0}` (base pointer then three stores);
 * the offset's products are named locals stored after the position copy.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218ED04  0x0218ED04  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   _u32_div_f     0x0209C2B0  arm
 *   d_020A1B38     0x020A1B38  data   a2
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct Vec {
    int x, y, z;
} Vec;

typedef struct Work {
    s16 x;
    s16 y;
    s16 dx;
    s16 dy;
    u16 thresh;
    u16 cnt;
    u16 period;
    u8  total;
    u8  left;
    u32 steps;
    u32 tick;
    Vec *pos;
} Work;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_020124E8(struct Obj *p);
extern void *func_02188C58(void *o);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern Vec *func_0218EC5C(void *h);
extern void func_0218EC54(u8 *p);
extern void func_0218ED04(u8 *p, const struct Vec *v);
extern void func_0218EC30(void *h, Vec *v);
extern void func_0218F05C(unsigned char *a);
extern void func_0218EC90(void *h, Vec *v);
extern const s16 d_020A1B38[];

int func_021D2D7C(void *task, int *state)
{
    Work *w;
    void *o;
    void *h;
    int done;
    u16 ang;
    int s;

    done = 0;
    o = func_0201210C(func_020124E4(task));
    w = func_020124E8(task);
    h = func_02188C58(o);

    switch (*state) {
    case 0:
        func_0218F0A8(h);
        (*state)++;
        break;
    case 1:
        if (func_0218F0E8(h) == 0) {
            w->pos = func_0218EC5C(h);
            func_0218EC54(h);
            (*state)++;
        }
        break;
    case 2:
        w->tick++;
        ang = (w->tick << 16) / w->steps;
        if (w->thresh != 0 && w->total - w->left >= w->thresh) {
            w->cnt++;
            if (w->cnt >= w->period) {
                w->cnt = 0;
                w->y -= w->dy;
                w->x -= w->dx;
                if (w->y <= 0) {
                    w->y = 1;
                }
                if (w->x <= 0) {
                    w->x = 1;
                }
            }
        }
        if (w->tick >= w->steps) {
            w->left--;
            w->tick = 0;
        }
        if (w->left == 0) {
            w->tick = 0;
            done = 1;
        }
        if (done) {
            Vec zero = {0, 0, 0};
            func_0218ED04(h, &zero);
            func_0218EC30(h, w->pos);
            func_0218F05C(h);
            (*state)++;
        } else {
            Vec pos;
            Vec ofs;
            int ox, oy;
            s = d_020A1B38[(ang >> 4) * 2];
            ox = w->x * s;
            oy = w->y * s;
            pos = *w->pos;
            pos.x += ox;
            pos.y += oy;
            ofs.x = ox;
            ofs.y = oy;
            ofs.z = 0;
            func_0218EC90(h, &pos);
            func_0218ED04(h, &ofs);
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}
