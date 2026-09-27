/*
 * function: func_021B854C
 * address:  0x021B854C
 * packet:   pkt_021B854C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * near miss: compiles 264 vs 268.  All 10 relocation sites resolve; the
 * reconstructed control flow (three-way arg4 selection, duplicated 9280
 * tail-merged, abs(arg5) guards, cf client 9500/9500) reproduces the original
 * instruction sequence.  Writing the tail result back into the arg7 parameter
 * (instead of a named u32 local) pins the prologue and frame exactly:
 * push {r4,r5,r6,r7,lr}; sub sp,#0x1c, no extra saved register.  Residual:
 * 1.1p1 assigns the stack-passed arg5 to r6 and arg6 to r7, the original holds
 * the opposite (arg5->r7, arg6->r6), so the abs(arg5) guard and the arg4/arg6
 * compares all read the wrong register and the body diverges past that point.
 * The assignment follows live-range start, so every source spelling tried
 * (separate locals for arg5/arg6, m used in the guard, no m local, both
 * declaration orders) leaves arg5 in r6.
 *
 * symbols:
 *   func_021B95C0  0x021B95C0  thumb
 *   func_021B87D8  0x021B87D8  thumb
 *   func_021B8514  0x021B8514  thumb
 *   func_021B93D4  0x021B93D4  thumb
 *   func_021B9278  0x021B9278  thumb
 *   func_021B9280  0x021B9280  thumb
 *   func_021B8658  0x021B8658  thumb
 *   func_021B963C  0x021B963C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_021B95C0(u8 *p, u8 *q, int a3, int a4, u8 *sr, u32 a6);
u8 *func_021B87D8(u8 *p, u32 idx);
u8 *func_021B8514(u8 *p, u32 v, u8 *q, u16 *r, int flag);
int func_021B93D4(int dir);
int func_021B9278(u32 a, u32 b, u32 c);
int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
void func_021B8658(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
int func_021B963C(u8 *a, u8 *b);

int func_021B854C(u8 *p, u8 *a, u32 arg3, int arg4, int arg5, int arg6, int arg7)
{
    int m = arg6;
    int res;

    if (func_021B95C0(*(u8 **)(p + 0x28), a, arg4, arg5,
                      *(u8 **)(p + 0x24), *(u32 *)(p + 0x1c)) == 0)
        return 0;
    if ((arg5 < 0 ? -arg5 : arg5) > arg7)
        return 0;
    if (arg4 >= arg6) {
        u8 *row = func_021B87D8(*(u8 **)(p + 0x24), *(u32 *)(a + 4));
        res = (int)func_021B8514(row, *(u32 *)(a + 8),
                                  *(u8 **)(p + 0x24), *(u16 **)(p + 0x28), 1);
    } else if (arg4 >= 0) {
        goto tail;
    } else {
        u8 *row = func_021B87D8(*(u8 **)(p + 0x24), *(u32 *)a);
        res = (int)func_021B8514(row, func_021B93D4(*(u32 *)(a + 8)),
                                  *(u8 **)(p + 0x24), *(u16 **)(p + 0x28), 1);
    }
    if (res == 0) {
        if (arg4 > arg6)
            return 0;
        goto tail;
    }
    a = (u8 *)res;
    if (arg4 >= arg6) {
        arg4 -= arg6;
        m = func_021B9278(res, *(u32 *)(p + 0x1c), *(u32 *)(p + 0x24));
        arg7 = (u32)func_021B9280((u8 *)res, arg4, m, *(u8 **)(p + 0x24));
    } else if (arg4 < 0) {
        m = func_021B9278(res, *(u32 *)(p + 0x1c), *(u32 *)(p + 0x24));
        arg4 += m;
        arg7 = (u32)func_021B9280((u8 *)res, arg4, m, *(u8 **)(p + 0x24));
    }
    if (arg4 >= m)
        return 0;
    if ((arg5 < 0 ? -arg5 : arg5) > (int)arg7)
        return 0;
tail:
    func_021B8658(p, (u32)a, arg3, arg4, arg5, m, (int)arg7);
    func_021B963C(a, *(u8 **)(p + 0x24));
    return arg3;
}
