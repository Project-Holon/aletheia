/*
 * function: func_021F39C0
 * address:  0x021F39C0
 * packet:   pkt_ov055_021F39C0
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021690B4  0x021690B4  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021F3E84  0x021F3E84  thumb  ov055
 *   func_021F3C2C  0x021F3C2C  thumb  ov055
 *   func_021F405C  0x021F405C  thumb  ov055
 *   func_021F43D8  0x021F43D8  thumb  ov055
 *   func_02189A68  0x02189A68  thumb  ov021
 */

extern int func_02188C54(int);
extern int func_02188C80(int);
extern int func_020120F4(int);
extern void *func_02188CB4(unsigned char *p);
extern void *func_02188C7C(unsigned char *p);
extern int func_02188C9C(int);
extern int func_021690B4(int);
extern int func_02188C84(int);
extern void func_021F3E84(char *, int, int, int);
extern void func_021F3C2C(char *, int, int, char *, int);
extern void func_021F405C(char *, char *, int);
extern void func_021F43D8(char *, int, char *, int, int);
extern void func_02189A68(int, char *);

void func_021F39C0(int a, int b, char *c)
{
    int i;
    int t4, t0, t1, t2, t3;

    t0 = func_02188C54(b);
    t1 = func_020120F4(func_02188C80(b));
    *(int *)c = func_02188CB4((void *)b);
    *(int *)(c + 4) = func_02188C7C((void *)b);
    t2 = func_02188C9C(b);
    t3 = func_021690B4(t1);
    t4 = func_02188C84(b);
    func_021F3E84(c + 0x308, t3, t2, t4);
    for (i = 0; i < 0x20; i++)
        func_021F3C2C(c + 8 + i * 0x18, *(int *)(c + 4), t2, c + 0x308, i);
    func_021F405C(c + 0x308, c, t3);
    func_021F43D8(c + 0x348, t0, c + 0x308, t3, t4);
    func_02189A68(b, c);
}
