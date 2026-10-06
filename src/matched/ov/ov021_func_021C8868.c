/*
 * function: func_021C8868
 * address:  0x021C8868
 * packet:   pkt_ov021_021C8868
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_02011330  0x02011330  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021C8738  0x021C8738  thumb  ov021
 */

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
typedef unsigned char  u8;
struct Big;
extern u8 *func_02012ED0(struct Big *p);
typedef unsigned short u16;
struct Stream;
extern u16 func_02011330(struct Stream *s);
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern int func_021C8738(char *p, int k);

int func_021C8868(int a, int b)
{
    int *r4;
    int r7;
    unsigned short *r5;

    func_0215A5F4((void *)b);
    r4 = (int *)func_02012ED0(func_020120F4((void *)func_02188C80(func_0201210C(func_0215A5DC((void *)b)))));
    r7 = func_02011330((struct Stream *)a);
    r5 = func_02159AE8((void *)a, (void *)b);
    *r5 = func_021C8738((char *)(*r4), r7);
    return 0;
}
