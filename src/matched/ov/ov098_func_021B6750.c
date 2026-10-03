/*
 * function: func_021B6750
 * address:  0x021B6750
 * packet:   pkt_ov098_021B6750
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B6A00  0x021B6A00  thumb  ov098
 *   func_021B6A3C  0x021B6A3C  thumb  ov098
 *   func_0204E720  0x0204E720  arm
 *   func_02005E30  0x02005E30  thumb
 *   func_0204E804  0x0204E804  arm
 */

extern void func_021B6A00(int a, int b);
extern int func_021B6A3C(int a);
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_02005E30(u32 a);
extern int func_0204E804(void);

int func_021B6750(char *p)
{
    switch (*(int *)(p + 0x60)) {
    case 0:
        func_021B6A00(*(int *)(p + 0x14), *(int *)p);
        *(int *)(p + 0x60) = *(int *)(p + 0x60) + 1;
        break;
    case 1:
        if (func_021B6A3C(*(int *)(p + 0x14)) != 0) {
            func_0204E720(3, 0, 0x10, 2);
            func_02005E30(8);
            *(int *)(p + 0x60) = *(int *)(p + 0x60) + 1;
        }
        break;
    case 2:
        if (func_0204E804() == 0)
            return 2;
        break;
    }
    return 0;
}
