/*
 * function: func_0217DFB4
 * address:  0x0217DFB4
 * packet:   pkt_ov019_0217DFB4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0217BB20  0x0217BB20  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_02174CE4  0x02174CE4  thumb  ov012
 *   func_021750D0  0x021750D0  thumb  ov012
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0217F060  0x0217F060  thumb  ov019
 *   func_0217FE44  0x0217FE44  thumb  ov019
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 */
#include "../include/Obj19422.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x2d];
    u8 f2d;
} Obj;

struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
typedef unsigned int   u32;
extern void *func_021A3074(u8 *p);
extern int func_0217BB20(char *p);
extern void func_0217F074(void *ctx);
extern u32 func_0217F1EC(u8 *p);
extern u32 func_02174CE4(char *p);
extern u8 func_021750D0(u8 *p);
extern int func_0216D3CC(int a0);
extern int func_0217F060(int i);
extern int func_0217FE44(int a, int mode, unsigned *out);
extern void func_0216D410(void *h, u16 v);
extern int func_0216D454(void *h);
extern int func_0216D480(char *p);
extern int func_0217B8E4(char *p, int v);

int func_0217DFB4(void *ctx, Obj *obj, int a2, u8 *state)
{
    void *w = ((struct Obj19422 *)ctx)->f355C;
    void *h;
    unsigned out;
    int r;

    if (func_0217BB20(ctx) == 1) {
        func_0217F074(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        (*state)++;
        break;
    case 1:
        if (func_02174CE4(w) == 1)
            (*state)++;
        break;
    case 2:
        if (func_0217F1EC(ctx) != 0) {
            r = func_021750D0(w);
            if (r == 1) {
                (*state)++;
            } else if (r == 0) {
                func_0217B8E4(ctx, 0x2c);
                return 1;
            }
        }
        break;
    case 3:
        h = func_021A3074(func_02188CB4((void *)a2));
        if (func_0216D3CC((int)h) == 1) {
            func_0217FE44(a2, func_0217F060(obj->f2d), &out);
            func_0216D410(h, (out & 1) ? 2 : 3);
            (*state)++;
        }
        break;
    case 4:
        h = func_021A3074(func_02188CB4((void *)a2));
        if (func_0216D454(h) == 1) {
            func_0216D480(h);
            func_0217B8E4(ctx, 0x2d);
            return 1;
        }
        break;
    }
    return 0;
}
