/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov047_021F36C0
 * region:   ov047
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 */

typedef unsigned short u16;
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *func_02188C80(void *p);
extern u16 func_02188C84(u8 *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern int *func_021897BC(char *p, int idx);
extern void *func_021A3074(unsigned char *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);

void func_021F36C0(int a)
{
    void **p;

    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))), 0x1f);
    func_02189764((unsigned char *)a, 1, func_02188C84((u8 *)a), 0x14);
    p = (void **)func_021897BC((char *)a, 1);
    p[0] = func_02188CB4((void *)a);
    p[1] = func_021A3074(p[0]);
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
}
