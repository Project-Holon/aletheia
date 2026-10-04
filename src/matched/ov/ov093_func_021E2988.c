/*
 * unit:     yes
 * function: func_021E2988, func_021E29DC
 * address:  0x021E2988
 * packet:   pkt_ov093_021E2988
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_0201C1D8  0x0201C1D8  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F2564     0x021F2564  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
struct QQ;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern u16 func_021D70A8(struct QQ *p);
extern u16 func_0201C1D8(void *p);
extern int func_021D76BC(int key, u32 v);
extern int d_021F2564[];

void func_021E2988(void *a, void *b, int c)
{
    void *m;
    u32 x;
    u32 y;
    u32 r;
    u32 t;

    if (c == func_021D775C(3)) {
        m = func_021C7CF4(b, c);
        x = func_021D59B4(m, 0xD);
        y = func_021D59B4(m, 0xE);
        t = func_0201C1D8((void *)func_021D70A8(a));
        r = t * x / y;
        if (r == 0)
            r = 1;
        func_021D76BC(0x30, r);
    }
}

int *func_021E29DC(int *p)
{
    *p = 1;
    return d_021F2564;
}
