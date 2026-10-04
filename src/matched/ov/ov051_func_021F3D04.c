/*
 * function: func_021F3D04
 * address: 0x021F3D04
 * packet: pkt_ov051_021F3D04
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021F3D94 0x021F3D94 thumb ov051
 *   func_021C928C 0x021C928C thumb ov021
 */

typedef unsigned short u16;
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern u16 func_02188C9C(u8 *p);
extern char *func_0200B3A4(unsigned, int);
extern int func_021F3D94(int);
extern void func_021C928C(unsigned);

void func_021F3D04(int a, int b)
{
    unsigned h = (unsigned int)func_02012EC4(func_020120F4(func_02188C80((void *)a)));
    char *p = *(char **)(func_0200B3A4(h, func_021F3D94(func_02188C9C((u8 *)a))) + 4);
    func_021C928C(((unsigned *)(p + 0x6c))[b]);
}
