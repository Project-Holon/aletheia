/*
 * function: func_021F37B8
 * address: 0x021F37B8
 * packet: pkt_ov041_021F37B8
 * region: ov041
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
typedef signed int     s32;
struct Big;
struct Ctx;
struct Rec94;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p);
extern void func_021BE418(u8 *, u16);
extern void func_021BE580(void *);
void func_021F37B8(u8 *p)
{
    int x = func_02188D2C((int *)p);
    func_021897A0(p, 1);
    func_021BE418((u8 *)x, 0);
}
