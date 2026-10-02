/*
 * function: func_021C60B8
 * address:  0x021C60B8
 * packet:   pkt_ov021_021C60B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_021C1D68  0x021C1D68  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021C61D4  0x021C61D4  thumb  ov021
 *   func_021C61EC  0x021C61EC  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021A9F40  0x021A9F40  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 f0;
    u8 pad1[3];
    u32 f4;
    u32 f8;
    void *fC;
    void *f10;
} Work;

extern void func_021A2F48(void *a, int b);
extern int func_021A2F54(void *a);
extern void *func_021A3074(void *p);
extern void func_0216D410(void *obj, u32 a);
extern int func_0216D480(void *obj);
extern int func_02189A00(void *a);
extern void *func_021C1D68(u32 a, int b, int c);
extern void func_02012374(void *a, void *t);
extern int func_021C61D4(Work *w);
extern void func_021C61EC(void *a, u32 b, void *c);
extern void *func_02188CE8(void *a);
extern void *func_021A9F40(void *self, u32 v);
extern void func_02158780(void *a, u32 id, u32 b, u32 c, u32 d);
extern void *func_02188C7C(void *p);
extern void func_0216D9E4(void *o);

int func_021C60B8(void *task, int *state, Work *w)
{
    void *t;

    switch (*state) {
    case 0:
        if (w->f0 >= 6) {
            *state = 5;
            break;
        }
        func_021A2F48(w->f10, 0x80);
        (*state)++;
    case 1:
        if (func_021A2F54(w->f10) != 1)
            break;
        func_0216D410(func_021A3074(w->f10), 0xa2);
        (*state)++;
        break;
    case 2:
        if (func_0216D480(func_021A3074(w->f10)) != 1)
            break;
        t = func_021C1D68(w->f4, func_02189A00(w->fC), w->f0);
        if (t != 0)
            func_02012374(task, t);
        (*state)++;
        break;
    case 3:
        func_021A2F48(w->f10, 8);
        (*state)++;
    case 4:
        if (func_021A2F54(w->f10) != 1)
            break;
        *state = 5;
        break;
    case 5:
        if (func_021C61D4(w) == 0) {
            *state = 8;
            break;
        }
        func_021C61EC(task, w->f4, w->fC);
        *state = 6;
        break;
    case 6:
        t = func_021A9F40(func_02188CE8(w->fC), 2);
        if (t == 0) {
            *state = 7;
            break;
        }
        func_02012374(task, t);
        *state = 9;
        break;
    case 7:
        func_02158780(task, 0x2793, 0, 0, 0x15);
        *state = 9;
        break;
    case 8:
        func_02158780(task, 0x2794, 0, 0, 0x15);
        *state = 9;
        break;
    case 9:
        func_0216D9E4(func_02188C7C(w->fC));
        return 1;
    }
    return 0;
}
