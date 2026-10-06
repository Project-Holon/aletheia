/*
 * function: func_0219AEC8
 * address:  0x0219AEC8
 * packet:   pkt_ov021_0219AEC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Twin of func_0219AB8C (same shape; the step field is signed and advanced
 * through func_0219ADEC).
 *
 * symbols:
 *   func_0219B2E8  0x0219B2E8  thumb  ov021
 *   func_0216D7E8  0x0216D7E8  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D7F8  0x0216D7F8  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0219ADEC  0x0219ADEC  thumb  ov021
 *   func_0219B120  0x0219B120  thumb  ov021
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_0219B358  0x0219B358  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021639C0  0x021639C0  thumb  ov010
 *   func_0219B334  0x0219B334  thumb  ov021
 *   func_0219B060  0x0219B060  thumb  ov021
 *   func_02164168  0x02164168  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_0219B390  0x0219B390  thumb  ov021
 *   func_0216DA44  0x0216DA44  thumb
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct St {
    u8 f0;
    s8 step;
    u8 last;
    u8 axis;
    u8 id;
    u8 f5;
    u8 f6;
    u8 f7;
    s8 f8;
} St;

extern int func_0219B2E8(int a, u8 *b);
extern int func_0216D7E8(void *p);
extern int func_0216D83C(void *p);
extern int func_0216D7F8(void *p);
extern int func_0216D86C(void *p);
extern void func_0219ADEC(St *b);
extern u32 *func_0219B120(u32 id);
extern int func_0216D600(int a0, u16 a1);
extern int func_0219B358(u32 a);
extern void func_0216D5E0(int a0, int a1);
extern int func_021639C0(int a, u16 b);
extern int func_0219B334(u32 a);
extern int func_0219B060(void);
extern int func_02164168(int a);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(char *a0, int a1);
extern void func_0219B390(int a, s8 *b);
extern void func_0216DA44(int a);

int func_0219AEC8(char *a, St *b)
{
    u32 *tbl;
    u32 v;
    int x0;
    int y0;
    int x1;
    int y1;
    int f;
    int m;

    if (func_0219B2E8((int)a, &b->f6) == 0) {
        return 0;
    }
    if (b->step == b->last) {
        if (b->axis == 0) {
            x0 = func_0216D7E8((void *)a);
            if (x0 == func_0216D83C((void *)a)) {
                func_0219ADEC(b);
            }
        } else {
            x0 = func_0216D7F8((void *)a);
            if (x0 == func_0216D86C((void *)a)) {
                func_0219ADEC(b);
            }
        }
    }
    if (b->step == 3) {
        x0 = func_0216D7E8((void *)a);
        y0 = func_0216D7F8((void *)a);
        x1 = func_0216D83C((void *)a);
        y1 = func_0216D86C((void *)a);
        if (x0 == x1 && y0 == y1) {
            b->step = 0;
        }
    }
    tbl = func_0219B120(b->id);
    v = tbl[b->step];
    func_0216D600((int)a, (u16)v);
    if (func_0219B358((u32)a) == 0) {
        func_0216D5E0((int)a, (u16)v);
    }
    f = func_021639C0((int)a, (u16)v);
    if (1 & f) {
        func_0219ADEC(b);
        v = tbl[b->step];
        func_0216D600((int)a, (u16)v);
        if (func_0219B358((u32)a) == 0) {
            func_0216D5E0((int)a, (u16)v);
        }
        f = func_021639C0((int)a, (u16)v);
    }
    m = 12;
    if (func_0219B334((u32)a) != 0 && func_0219B060() == 1 && func_02164168((int)a) == 1) {
        m = 16;
    }
    if (f != 0) {
        m = 32;
    }
    func_0216D438(a, (u16)func_02197E7C((u16)v, (u16)m));
    if (func_0219B358((u32)a) == 1) {
        func_0219B390((int)a, &b->f8);
    }
    func_0216DA44((int)a);
    b->f0 = 3;
    return 1;
}
