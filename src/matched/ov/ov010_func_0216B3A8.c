/*
 * function: func_0216B3A8
 * address:  0x0216B3A8
 * packet:   pkt_ov010_0216B3A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_0216B2E4  0x0216B2E4  thumb  ov010
 *   func_0216B340  0x0216B340  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Desc;

extern void *func_0201210C(void *p);
extern void func_020120F4();
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(u8 *p);
extern void *func_0216D888(void *p);
extern void func_0216B2E4();
extern struct Desc *func_0216B340(int a0, int a1, void *a2, int a3, int a4);

struct Desc *func_0216B3A8(int a0, int a1, int a2)
{
    int buf[3];
    void *t;

    t = func_0201210C((void *)a0);
    func_020120F4(a0);
    func_0216B2E4(func_0216D888(func_021A3074(func_02188CB4(t))), a1, buf);
    return func_0216B340(a0, a1 != 9, buf, a1, a2);
}
