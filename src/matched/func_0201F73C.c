/*
 * function: func_0201F73C
 * address:  0x0201F73C
 * packet:   pkt_0201F5DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045730  0x02045730  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_0201F628  0x0201F628  thumb
 *   func_020409B4  0x020409B4  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern void *func_02045730(void *a);
extern u32   func_02045758(void *a);
extern u32   func_02045760(void *a);
extern u32   func_02045748(void *a);
extern u32   func_02045750(void *a);
extern void  func_0201F628(void *x, u32 val1, u32 val2, u32 val3, u32 val4, void *d, s32 c);
extern void  func_020409B4(void *x);
extern void  func_02041B6C(void *x);

void func_0201F73C(void *a, s32 b, s32 c, void *d)
{
    void *x = func_02045730(a);
    u32 val1 = func_02045758(a);
    u32 val2 = func_02045760(a);
    u32 val3 = func_02045748(a);
    u32 val4 = func_02045750(a);

    func_0201F628(x, val1, val2, val3, val4, d, c);
    if (b == 0) {
        func_020409B4(x);
    } else if (b == 1) {
        func_02041B6C(x);
    }
}
