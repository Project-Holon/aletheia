/*
 * function: func_021F3D1C
 * address:  0x021F3D1C
 * packet:   pkt_ov039_021F3D1C
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_021F3DE4 0x021F3DE4 thumb ov039
 */

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern int func_02188D2C(int *p);
extern unsigned char *func_021897BC(int, int);
extern int func_02188C80(int);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern int *func_0200B3A4(int, int);
extern void func_021BE580(int);
typedef unsigned short u16;
extern int func_021F3DE4(void *p, u16 delta, u16 i);

void func_021F3D1C(int a)
{
    int *r7;
    int r6;
    int i;
    unsigned char *r5;

    r6 = func_02188D2C((int *)a);
    r5 = func_021897BC(a, 1);
    r7 = func_0200B3A4((int)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(a))), 2);
    func_021BE580(r6);
    for (i = 0; i < 4; i++)
        r7[i] = func_021F3DE4((void *)r6, (unsigned char)i, (unsigned char)(r5[i + 0x21EC] + 1));
}
