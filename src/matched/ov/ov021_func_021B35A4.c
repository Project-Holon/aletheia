/*
 * function: func_021B35A4
 * address:  0x021B35A4
 * packet:   pkt_ov021_021B35A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B3258  0x021B3258  thumb  ov021
 *   func_021B3470  0x021B3470  thumb  ov021
 *   func_021B41AC  0x021B41AC  thumb  ov021
 *   func_021B42D0  0x021B42D0  thumb  ov021
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021B4AA4  0x021B4AA4  thumb  ov021
 *   func_021B4BA4  0x021B4BA4  thumb  ov021
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02020234  0x02020234  thumb
 *   func_0201FDA0  0x0201FDA0  thumb
 *   func_0201FEBC  0x0201FEBC  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021B4714  0x021B4714  thumb  ov021
 *   func_021B3568  0x021B3568  thumb  ov021
 *   func_021B40D4  0x021B40D4  thumb  ov021
 *   func_02007E50  0x02007E50  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_021B34F4  0x021B34F4  thumb  ov021
 *   func_021B46FC  0x021B46FC  thumb  ov021
 *   func_021B3F3C  0x021B3F3C  thumb  ov021
 *   func_021B40A8  0x021B40A8  thumb  ov021
 *   func_021B3C58  0x021B3C58  thumb  ov021
 *   func_021B3B04  0x021B3B04  thumb  ov021
 *   func_021B3B84  0x021B3B84  thumb  ov021
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_020310C4  0x020310C4  arm
 *   d_021D9440     0x021D9440  data   ov021  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00030.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void func_021B3258(u32 unused, char *a, u32 b, u32 c);
extern void func_021B3470(char *p);
extern void func_021B41AC(char *w, u16 b);
extern void func_021B42D0(char *w, u32 a, u32 b);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern int func_021B4AA4(char *w);
extern void func_021B4BA4(int i);
struct Cfg;
struct PrintSys;
struct Sub02008C20Obj;
struct Tcbl;
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 a);
extern void func_02020234(u8 *p);
extern u32 func_0201FDA0(const void *a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_0201FEBC(u8 *p);
extern void func_020061E4(u32 se);
extern void func_021B4714(char *w, u32 a, u32 b, u32 c);
extern void func_021B3568(char *w, u32 a);
extern void func_021B40D4(char *w);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u8 func_021B34F4(char *p);
extern void func_021B46FC(char *p);
extern void func_021B3F3C(char *w);
extern void func_021B40A8(char *w);
extern void func_021B3C58(char *w);
extern void func_021B3B04(char *w);
extern void func_021B3B84(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *a);
extern void func_020310C4(struct Tcbl *p);
extern const u8 d_021D9440[];

int func_021B35A4(u32 a, char *p, u32 c, u32 d)
{
    int r;
    u32 q;

    switch (((struct Obj00030 *)p)->f0) {
    case 0:
        func_021B3258(a, p, c, d);
        (((struct Obj00030 *)p)->f0)++;
        break;
    case 1:
        func_021B3470(p);
        break;
    case 2:
        func_021B41AC(p, ((struct Obj00030 *)p)->f1FC);
        func_021B42D0(p, ((struct Obj00030 *)p)->f208, ((struct Obj00030 *)p)->f200);
        func_0204B3DC((struct Obj *)((struct Obj00030 *)p)->f1CC, 1);
        ((struct Obj00030 *)p)->f0 = 3;
        break;
    case 3:
        ((struct Obj00030 *)p)->f0 = func_021B4AA4(p);
        break;
    case 4:
        func_021B4BA4(0);
        func_02045374((struct Cfg *)(*(u32 *)&((struct Obj00030 *)p)->f16C));
        func_02045374((struct Cfg *)(((struct Obj00030 *)p)->f178));
        func_02041B6C(1);
        func_0204B3DC((struct Obj *)((struct Obj00030 *)p)->f1CC, 0);
        func_02020234((u8 *)(*(u32 *)&((struct Obj00030 *)p)->f1A4));
        ((struct Obj00030 *)p)->f0 = 1;
        break;
    case 5:
        func_021B4BA4(1);
        func_02045374((struct Cfg *)(*(u32 *)&((struct Obj00030 *)p)->f16C));
        func_0204B3DC((struct Obj *)((struct Obj00030 *)p)->f1CC, 0);
        ((struct Obj00030 *)p)->f184 = func_0201FDA0(d_021D9440, 1, 9, 0, ((struct Obj00030 *)p)->f4);
        if (((struct Obj00030 *)p)->f162 != 1) {
            func_021B41AC(p, ((struct Obj00030 *)p)->f1FC);
        }
        ((struct Obj00030 *)p)->f0 = 7;
        break;
    case 6:
        func_021B4BA4(1);
        func_02045374((struct Cfg *)(*(u32 *)&((struct Obj00030 *)p)->f16C));
        func_0204B3DC((struct Obj *)((struct Obj00030 *)p)->f1CC, 0);
        ((struct Obj00030 *)p)->f184 = func_0201FDA0(d_021D9440, 1, 9, 0, ((struct Obj00030 *)p)->f4);
        ((struct Obj00030 *)p)->f0 = 7;
        break;
    case 7:
        r = func_0201FEBC((u8 *)(((struct Obj00030 *)p)->f184));
        if (r == -1) {
        } else if (r == 0) {
            ((struct Obj00030 *)p)->f0 = 8;
            func_021B4BA4(1);
            func_02020234((u8 *)(*(u32 *)&((struct Obj00030 *)p)->f1A4));
            func_02045374((struct Cfg *)(*(u32 *)&((struct Obj00030 *)p)->f16C));
            func_02041B6C(1);
        } else if (r == -2) {
            ((struct Obj00030 *)p)->f0 = 4;
        }
        break;
    case 8:
        func_020061E4(0x655);
        func_021B4714(p, 9, ((struct Obj00030 *)p)->f1FC, *(s16 *)&((struct Obj00030 *)p)->f208 > 1);
        func_021B3568(p, ((struct Obj00030 *)p)->f200 * *(s16 *)&((struct Obj00030 *)p)->f208);
        func_021B40D4(p);
        func_02007E50((u8 *)(((struct Obj00030 *)p)->f10), ((struct Obj00030 *)p)->f1FC, ((struct Obj00030 *)p)->f208, ((struct Obj00030 *)p)->f4);
        ((struct Obj00030 *)p)->f0 = 10;
        *(u8 *)&((struct Obj00030 *)p)->f1 = 9;
        break;
    case 9:
        if (((struct Obj00030 *)p)->f1FC == 4 && *(s16 *)&((struct Obj00030 *)p)->f208 >= 10) {
            func_021B4714(p, 15, ((struct Obj00030 *)p)->f1FC, *(s16 *)&((struct Obj00030 *)p)->f208 > 1);
            func_02007E50((u8 *)(((struct Obj00030 *)p)->f10), 12, 1, ((struct Obj00030 *)p)->f4);
            func_02008DF0((struct Sub02008C20Obj *)(((struct Obj00030 *)p)->f14), 0x1F);
            ((struct Obj00030 *)p)->f0 = 10;
            *(u8 *)&((struct Obj00030 *)p)->f1 = 4;
        } else {
            ((struct Obj00030 *)p)->f0 = 4;
        }
        break;
    case 10:
        ((struct Obj00030 *)p)->f0 = func_021B34F4(p);
        break;
    case 11:
        func_021B46FC(p);
        func_021B3F3C(p);
        func_021B40A8(p);
        func_021B3C58(p);
        func_021B3B04(p);
        func_021B3B84(p);
        return 1;
    }
    func_0201C4E4((struct PrintSys *)(*(u32 *)&((struct Obj00030 *)p)->f1B0));
    q = *(u32 *)&((struct Obj00030 *)p)->f1B0;
    if (((struct Obj00030 *)p)->f1AC != 0 && func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj00030 *)p)->f1A8))) == 0) {
        func_02045334((struct Descriptor *)((struct Obj00030 *)p)->f1A8);
        ((struct Obj00030 *)p)->f1AC = 0;
    }
    func_020310C4((struct Tcbl *)(((struct Obj00030 *)p)->f1B4));
    func_020310C4((struct Tcbl *)(((struct Obj00030 *)p)->f1B4));
    return 0;
}
