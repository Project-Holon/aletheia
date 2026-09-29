/*
 * function: func_021777FC
 * address:  0x021777FC
 * packet:   pkt_ov014_021777FC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A4     0x021797A4  data   a4
 *   d_02179790     0x02179790  data   a4
 *   func_0203D798  0x0203D798  arm
 *   func_02034714  0x02034714  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02177A74  0x02177A74  thumb  ov014
 *   func_02177D58  0x02177D58  thumb  ov014
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_021797A4;
extern u8 d_02179790[];
extern u8 *func_0203D798(void);
extern void func_02034714(u8 *a, int b, u8 *c);
extern void func_02082D44(void *src, void *dst, int n);
extern int func_02177A74(void);
extern void func_02177D58(u8 *p, int n);

typedef int (*SizeFn)(u32 a);
typedef u32 (*DataFn)(u32 a);

void func_021777FC(void)
{
    u8 *w = g_021797A4;
    u8 *e = w + 0xC6E;
    u8 *st = func_0203D798();
    SizeFn sfn = *(SizeFn *)(st + 0x1C);
    int n;

    if (sfn != 0) {
        n = sfn(*(u32 *)(w + 0xC64));
        if (n > 0x68)
            func_02034714(d_02179790, 0, d_02179790);
        func_02082D44((void *)(*(DataFn *)(st + 0x18))(*(u32 *)(w + 0xC64)), e + 8, n);
    }
    if (e[6] != func_02177A74()) {
        w[0xCF0] = 0;
        e[6] = func_02177A74();
    }
    if (w[0xCF0] == 0) {
        func_02177D58(w + 0xC6E, 0x70);
        w[0xCF0] = 2;
    }
    w[0xCF0]--;
}
