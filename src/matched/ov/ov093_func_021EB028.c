/*
 * function: func_021EB028
 * address: 0x021EB028
 * packet: pkt_ov093_021EB028
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_020215EC 0x020215EC thumb
 *   func_020215BC 0x020215BC thumb
 *   func_02041300 0x02041300 arm
 *   func_02040C14 0x02040C14 arm
 *   func_021EB1D8 0x021EB1D8 thumb ov093
 *   func_0204989C 0x0204989C arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045374 0x02045374 arm
 *   func_020454E0 0x020454E0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_021ED76C 0x021ED76C thumb ov093
 *   func_021ED930 0x021ED930 thumb ov093
 *   func_021EDB3C 0x021EDB3C thumb ov093
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_020434DC 0x020434DC arm
 *   d_021F3930 0x021F3930 data a4
 *   d_021F3950 0x021F3950 data a4
 *   d_021F3970 0x021F3970 data a4
 */
#include "../include/Obj00970.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct BgTemplate;
extern const struct BgTemplate d_021F3930, d_021F3950, d_021F3970;
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
struct S;
extern int func_021F86E0(void);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct PalAnmSlot;
extern void func_020215EC(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02040C14(u32, u32, u32, u32);
extern u16 func_021EB1D8(u8 *, u32, u32, u32);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045374(struct Cfg *cfg);
extern void func_020454E0(struct Cfg *cfg, u16 base, u32 pal);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_021ED76C(struct S *s, int a);
extern void func_021ED930(char *s);
extern void func_021EDB3C(struct S *s, char *a1);
extern void func_020409B4(u32 index);
extern void func_02040588(u32 which, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);

void func_021EB028(u8 *p)
{
    u16 zero;
    u32 tile;
    func_0203FCA0(1, &d_021F3930, 0);
    func_0203FCA0(2, &d_021F3950, 0);
    func_0203FCA0(3, &d_021F3970, 0);
    func_020215EC((struct PalAnmSlot *)func_021F86E0(), 0xb, 0x5a, ((struct Obj00970 *)p)->f13C, 0, 0x20, 0, 0);
    func_020215EC((struct PalAnmSlot *)func_021F86E0(), 0xb, 0xd6, ((struct Obj00970 *)p)->f13C, 0, 0x60, 0x10, 0x10);
    zero = 0;
    func_020215BC((struct PalAnmSlot *)func_021F86E0(), &zero, 0, 0, 2);
    func_02041300(1, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02040C14(1, 0, 1, 0);
    tile = func_021EB1D8(p, 0xb, 0x59, 1);
    *(u32 *)&((struct Obj00970 *)p)->f14 = func_021EB1D8(p, 0xb, 0xd5, 3);
    func_0204989C(0xb, 0xd7, 2, 0, 0, 0, ((struct Obj00970 *)p)->f13C);
    func_0204989C(0xb, 0xd8, 3, 0, 0, 0, ((struct Obj00970 *)p)->f13C);
    ((struct Obj00970 *)p)->f0 = (void *)func_020450F0(1, 1, 0x13, 0x1e, 4, 0, 0);
    ((struct Obj00970 *)p)->f4 = func_02045770(((struct Obj00970 *)p)->f0);
    func_02045374(((struct Obj00970 *)p)->f0);
    func_020454E0(((struct Obj00970 *)p)->f0, tile, 0);
    func_02043B5C(((struct Obj00970 *)p)->f4, 0xc);
    func_02045334(((struct Obj00970 *)p)->f0);
    ((struct Obj00970 *)p)->f10 = func_021EB1D8(p, 0xb, 0xdd, 3);
    ((struct Obj00970 *)p)->f8 = (void *)func_020450F0(3, 0x15, 0x25, 0xa, 0xc, 3, 0);
    ((struct Obj00970 *)p)->fC = func_02045770(((struct Obj00970 *)p)->f8);
    func_021ED76C((struct S *)(p + 0x154), (int)(((struct Obj00970 *)p)->f0));
    func_021ED930((char *)p);
    func_021EDB3C((struct S *)p, ((struct Obj00970 *)p)->f14);
    func_020409B4(1);
    func_020409B4(2);
    func_020409B4(3);
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_020434DC(0x10, 1);
}
