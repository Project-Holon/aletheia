/*
 * unit: yes
 * function: func_021F3868, func_021F38A0
 * address: 0x021F3868
 * packet: pkt_ov051_021F3868
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: extent follower at 0x021F38A0 is an empty return stub; no existing same-region source or shard was found.
 * symbols:
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_02188CD0 0x02188CD0 thumb ov021
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_021F3D94 0x021F3D94 thumb ov051
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
extern unsigned short func_02188C84(u8 *);
struct Big;
struct Ctx;
extern void *func_02188C80(void *p);
extern unsigned func_02188CD0(u8 *);
extern unsigned short func_02188C9C(u8 *);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern int func_021F3D94(int);
extern char *func_0200B3A4(unsigned,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021F3868(u8 *p)
{
    unsigned h;
    func_02188C84(p);
    h=(unsigned int)func_02012EC4(func_020120F4(func_02188C80(p)));
    func_02188CD0(p);
    func_020307B0(*(void **)(func_0200B3A4(h,func_021F3D94(func_02188C9C(p)))+4));
}

void func_021F38A0(void)
{
}
