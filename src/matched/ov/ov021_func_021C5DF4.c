/*
 * function: func_021C5DF4
 * address:  0x021C5DF4
 * packet:   pkt_ov021_021C5DF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_021C5FA8  0x021C5FA8  thumb  ov021
 *   func_021C602C  0x021C602C  thumb  ov021
 *   func_02005728  0x02005728  thumb
 *   func_021C5FC0  0x021C5FC0  thumb  ov021
 *   func_021C5FEC  0x021C5FEC  thumb  ov021
 *   func_021C6018  0x021C6018  thumb  ov021
 *   func_021C6054  0x021C6054  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02008DF0  0x02008DF0  thumb
 *   func_021AA8EC  0x021AA8EC  thumb  ov021
 *   func_020130B4  0x020130B4  thumb
 *   func_0216E7C8  0x0216E7C8  thumb  ov010
 *   func_0201235C  0x0201235C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct {
    void *f0;
    void *f4;
    u8 *f8;
    void *fC;
    u32 f10;
    void *f14;
    u32 f18;
    u32 f1C;
    u8 pad20[0x39];
    u8 f59;
    u16 f5A;
    u32 f5C;
    u32 f60;
    void *f64;
} Work;

extern void func_021A2F48(u32 a, int b);
extern int func_021A2F54(u32 a);
extern void func_0216D674(u32 a, u32 b);
extern void func_020061E4(u32 a);
extern int func_021C5FA8(Work *w, u32 n);
extern void func_021C602C(Work *w);
extern u32 func_02005728(u32 v);
extern int func_021C5FC0(Work *w, u32 n);
extern void func_021C5FEC(Work *w);
extern void func_021C6018(Work *w);
extern void func_021C6054(Work *w);
extern void func_02158780(void *a, u16 id, u32 b, u32 c, u32 d);
extern void func_02008DF0(u32 a, u32 b);
extern void func_021AA8EC(void *p);
extern void func_020130B4(void *p);
extern void *func_0216E7C8(void *a0, u8 *a1, void *a2, int a3, int a4);
extern void func_0201235C(void *task, void *next);

int func_021C5DF4(void *task, int *state, Work *w)
{
    int r;

    switch (*state) {
    case 0:
        if (w->f5A != 0) {
            *state = 8;
            break;
        }
        func_021A2F48(w->f18, 0x200);
        (*state)++;
    case 1:
        if (func_021A2F54(w->f18) != 1)
            break;
        func_0216D674(w->f1C, 0);
        func_020061E4(0x684);
        (*state)++;
        break;
    case 2:
        if (func_021C5FA8(w, 15) == 0)
            break;
        func_021C602C(w);
        if (w->f64 == 0) {
            *state = 5;
            break;
        }
        w->f5C = func_02005728(0x5a) + 0x1e;
        (*state)++;
        break;
    case 3:
        r = func_021C5FC0(w, w->f5C);
        if (r == 1) {
            *state = 6;
            break;
        }
        if (r != 2)
            break;
        func_021C5FEC(w);
        (*state)++;
        break;
    case 4:
        r = func_021C5FC0(w, 0x1e);
        if (r == 0)
            break;
        func_021C6018(w);
        if (r == 1) {
            func_021C6054(w);
            func_0216D674(w->f1C, 3);
            func_02158780(task, 0x2796, 0, 0, 0x15);
            *state = 10;
            break;
        }
        if (r != 2)
            break;
        func_02008DF0(w->f10, 0x50);
        *state = 7;
        break;
    case 5:
        r = func_021C5FC0(w, 0x78);
        if (r != 2) {
            if (r == 1)
                *state = 6;
            break;
        }
    case 6:
    case 7:
        func_021C6054(w);
        if (w->f64 != 0) {
            if (w->f59 == 1)
                func_021AA8EC(w->fC);
            func_020130B4(w->f64);
        }
        func_0216D674(w->f1C, 1);
        func_02158780(task, *state + 0x2792, 0, 0, 0x15);
        *state = 8;
        break;
    case 8:
        func_021A2F48(w->f18, 8);
        *state = 9;
    case 9:
        if (func_021A2F54(w->f18) == 1)
            return 1;
        break;
    case 10:
        func_02008DF0(w->f10, 8);
        func_0201235C(task, func_0216E7C8(w->f0, w->f8, w->f64, 0, (u8)(w->f59 == 1 ? 1 : 4)));
        return 0;
    }
    return 0;
}
