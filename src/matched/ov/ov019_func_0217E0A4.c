/*
 * function: func_0217E0A4
 * address:  0x0217E0A4
 * packet:   pkt_ov019_0217E0A4
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
 *   func_021750B0  0x021750B0  thumb  ov012
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

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x2d];
    u8 f2d;
} Obj;

extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(u8 *p);
extern int func_0217BB20(char *p);
extern void func_0217F074(void *ctx);
extern void func_021750B0(u8 *p, u8 v);
extern int func_02174CE4(void *w);
extern u8 func_021750D0(u8 *p);
extern int func_0216D3CC(void *h);
extern u8 func_0217F060(int i);
extern int func_0217FE44(int a, int mode, unsigned *out);
extern void func_0216D410(void *h, u16 v);
extern int func_0216D454(void *h);
extern int func_0216D480(char *p);
extern int func_0217B8E4(char *p, char v);

int func_0217E0A4(void *ctx, Obj *obj, int a2, u8 *state)
{
    void *w = *(void **)((u8 *)ctx + 0x355c);
    void *h;
    unsigned out;

    h = func_021A3074(func_02188CB4((void *)a2));
    if (func_0217BB20(ctx) == 1) {
        func_0217F074(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        func_021750B0(w, 0xff);
        (*state)++;
        break;
    case 1:
        if (func_02174CE4(w) == 1)
            (*state)++;
        break;
    case 2:
        if (func_021750D0(w) != 0xff)
            (*state)++;
        break;
    case 3:
        func_0217F074(ctx);
        (*state)++;
        break;
    case 4:
        if (func_0216D3CC(h) == 1) {
            func_0217FE44(a2, func_0217F060(obj->f2d), &out);
            func_0216D410(h, (out & 1) ? 0xb : 0xa);
            (*state)++;
        }
        break;
    case 5:
        if (func_0216D454(h) == 1) {
            func_0216D480(h);
            func_0217B8E4(ctx, 0x2a);
            return 1;
        }
        break;
    }
    return 0;
}
