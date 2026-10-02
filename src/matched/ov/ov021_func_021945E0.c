/*
 * function: func_021945E0
 * address:  0x021945E0
 * packet:   pkt_ov021_021945E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_020129D0  0x020129D0  thumb
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_020129B8  0x020129B8  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern u32 func_02188CCC(void *p);
extern int func_021A0ED4(u32 a);
extern void *func_02188C7C(void *p);
extern void func_020124E4(void *a);
extern u32 func_020120F4(void);
extern void func_0216D9A0(void *a);
extern void func_020129D0(u32 a, int b);
extern void func_021A0F30(u32 a, u32 b);
extern void func_020129B8(u32 a, int b);
extern void func_0216D9E4(void *a);

int func_021945E0(void *a, int b, u8 *c)
{
    void *r6;
    u32 r4;

    switch (c[0x10]) {
    case 0:
        if (func_021A0ED4(func_02188CCC(*(void **)(c + 8))) == 1) {
            r6 = func_02188C7C(*(void **)(c + 8));
            func_020124E4(a);
            r4 = func_020120F4();
            func_0216D9A0(r6);
            func_020129D0(r4, 1);
            func_021A0F30(func_02188CCC(*(void **)(c + 8)), *(u32 *)(c + 0xc));
            c[0x10]++;
        }
        break;
    case 1:
        if (func_021A0ED4(func_02188CCC(*(void **)(c + 8))) == 1) {
            func_020124E4(a);
            func_020129B8(func_020120F4(), *(u32 *)(c + 0xc) & 0xff);
            c[0x10]++;
        }
        break;
    case 2:
        func_0216D9E4(func_02188C7C(*(void **)(c + 8)));
        return 1;
    }
    return 0;
}
