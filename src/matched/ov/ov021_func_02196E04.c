/*
 * function: func_02196E04
 * address:  0x02196E04
 * packet:   pkt_ov021_02196E04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * State setup: like func_02196A60 with other handlers.
 *
 * symbols:
 *   func_02196034  0x02196034  thumb  ov021
 *   func_0219630C  0x0219630C  thumb  ov021
 *   func_021966B0  0x021966B0  thumb  ov021
 *   func_021973A0  0x021973A0  thumb  ov021
 *   func_0219649C  0x0219649C  thumb  ov021
 *   func_02196D94  0x02196D94  thumb  ov021
 *   func_02196D88  0x02196D88  thumb  ov021
 *   func_02051B84  0x02051B84  arm
 *   d_021D3FD8     0x021D3FD8  data  ov021  a4
 *   d_021D4004     0x021D4004  data  ov021  a4
 *   d_021DDAF4     0x021DDAF4  data  ov021  a4
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00093.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Rec8 { u32 a; u32 b; };

extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_0219630C(u32 a, void *b, u8 *c, void *d, u32 e, u32 f);
extern void func_021966B0(u8 *p, u32 n);
extern void func_021973A0(u8 *p);
struct Cb;
extern void func_0219649C(void *a, int b, struct Cb *c);
extern int func_02196D94(u32 v, u8 *p);
extern void func_02196D88(u8 *p);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern struct Rec8 d_021D3FD8;
extern u8 d_021D4004[];
extern u8 d_021DDAF4[];

void func_02196E04(u8 *p)
{
    struct Rec8 loc = d_021D3FD8;

    func_021973A0(p);
    func_021966B0(p, 0xD);
    func_0219630C(2, &loc, p, d_021DDAF4, 0, 0);
    ((struct Obj00093 *)p)->f24 = func_02051B84(d_021D4004, (int)func_0219649C, (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = func_02196D94;
    func_02196034(p, func_02196D88, 0x54D);
}
