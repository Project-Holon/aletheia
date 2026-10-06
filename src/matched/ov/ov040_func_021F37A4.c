/*
 * function: func_021F37A4
 * address: 0x021F37A4
 * packet: pkt_ov040_021F37A4
 * region: ov040
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02188D2C(int *);
extern int *func_021897BC(char *, int);
extern void func_021897A0(u8 *, int);
struct Big;
struct Ctx;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void func_021BE418(u8 *, u16);
extern void func_021BE580(void *);
void func_021F37A4(u8 *p)
{
    func_021897BC((char *)p, 1);
    *func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(p))), 3) = 1;
}
