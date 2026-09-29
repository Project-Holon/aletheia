/*
 * function: func_021F3C2C
 * address:  0x021F3C2C
 * packet:   pkt_ov055_021F3C2C
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The pool carries 0x021F4620 twice (0x021F3CDC, 0x021F3CE0): the store and
 * the call argument name it through two externs.
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021F4620     0x021F4620  data  ov055  a4
 *   d_021F4620_b   0x021F4620  data  ov055  a4
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_021F40F4  0x021F40F4  thumb  ov055
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216DCCC  0x0216DCCC  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct V {
    u16 h0;
    u16 h2;
    int pad4[2];
    u16 hc;
    u16 he;
    int pad10[5];
} V;

typedef struct O {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 ha;
    int fc;
    void *f10;
    u16 h14;
    u16 h16;
} O;

typedef struct Ent {
    int key;
    u16 h[6];
} Ent;

typedef struct T {
    u8 pad0[0xd];
    u8 n;
    u16 h[21];
    Ent *f38;
    u32 f3c;
} T;

extern V d_021F4620;
extern V d_021F4620_b;

extern u32 func_020056EC(u32);
extern int func_0216CE60(int, void *, int);
extern u32 func_021F40F4(const T *);
extern void func_0216DAC8(int, int);
extern void func_0216DCCC(int, int);
extern void func_0216D8C0(int, int *);

void func_021F3C2C(O *o, int a, int b, const T *s, int i)
{
    u32 k;
    u32 r;
    u16 x;

    k = 0;
    x = s->h[func_020056EC(0) % s->n];
    d_021F4620.h2 = x;
    r = func_020056EC(0);
    o->h8 = i + 0x30;
    for (k = 0; k < s->f3c; k++) {
        if (x == s->f38[k].key) {
            o->h6 = s->f38[k].h[r % 6];
            break;
        }
    }
    o->fc = func_0216CE60(a, &d_021F4620_b, b);
    o->f0 = 0;
    o->f1 = 0;
    o->f2 = 0;
    o->f3 = 0;
    o->ha = func_021F40F4(s);
    func_0216DAC8(o->fc, 1);
    func_0216DCCC(o->fc, 1);
    {
        int v[3] = {0, 0, 0};
        v[0] = func_020056EC(0x8000) - 0x4000;
        func_0216D8C0(o->fc, v);
    }
}
