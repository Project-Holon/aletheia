/*
 * function: func_021F37EC
 * address: 0x021F37EC
 * packet: pkt_ov040_021F37EC
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
 *   func_0201210C 0x0201210C thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_021F381C 0x021F381C thumb ov040
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
struct Desc;
struct Rec94;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void func_021BE418(u8 *, u16);
extern void func_021BE580(void *);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F381C(void *, int *);
void *func_021F37EC(void *p, u32 i)
{
    u16 *q = (u16 *)func_021897BC((char *)func_0201210C(p), 1);
    void *r;
    if (i >= 1) return 0;
    r = func_020122C0(p, 0, func_021F381C, 0);
    *q = i;
    return r;
}
