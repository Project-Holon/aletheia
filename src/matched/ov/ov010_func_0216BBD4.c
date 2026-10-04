/*
 * function: func_0216BBD4
 * address:  0x0216BBD4
 * packet:   pkt_ov010_0216BBD4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F39B8  0x021F39B8  thumb  ov045
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_02188CB4(unsigned char *p);
struct VecFx32;
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern int func_021F39B8();
extern void func_0215897C(void *vm, void *task);

int func_0216BBD4(int c, int vm)
{
    void *ws;
    void *p8;
    void *p10;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int buf[3];
    int vec[3];
    int *x;
    int *y;
    int r;

    ws = func_0215A5F4((void *)vm);
    p8 = func_0215A5DC((void *)vm);
    p10 = func_0201210C((void *)p8);
    a1 = func_02159B10((void *)c, (void *)vm);
    a2 = func_02159B10((void *)c, (void *)vm);
    a3 = func_02159B10((void *)c, (void *)vm);
    a4 = func_02159B10((void *)c, (void *)vm);
    a5 = func_02159B10((void *)c, (void *)vm);
    a6 = func_02159B10((void *)c, (void *)vm);
    func_021A3038(func_02188CB4((void *)p10), (struct VecFx32 *)buf);
    vec[0] = (a2 << 16) + 0x8000;
    vec[1] = a3 << 15;
    vec[2] = (a4 << 16) + 0x8000;
    if (a1 == 0) {
        x = buf;
        y = vec;
    } else {
        x = vec;
        y = buf;
    }
    r = func_021F39B8(p8, a1, x, y, a5 << 15, a6);
    if (r == 0) {
        return 1;
    }
    func_0215897C(ws, (void *)r);
    return 1;
}
