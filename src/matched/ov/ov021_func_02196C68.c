/*
 * function: func_02196C68
 * address:  0x02196C68
 * packet:   pkt_ov021_02196C68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * State setup: like func_02196A60 with a 16-byte record and other handlers.
 *
 * symbols:
 *   func_02196034  0x02196034  thumb  ov021
 *   func_0219630C  0x0219630C  thumb  ov021
 *   func_021966B0  0x021966B0  thumb  ov021
 *   func_0219728C  0x0219728C  thumb  ov021
 *   func_0219649C  0x0219649C  thumb  ov021
 *   func_02196F44  0x02196F44  thumb  ov021
 *   func_02196FF0  0x02196FF0  thumb  ov021
 *   func_02051B84  0x02051B84  arm
 *   d_021D4080     0x021D4080  data  ov021  a4
 *   d_021D4034     0x021D4034  data  ov021  a4
 *   d_021DDB44     0x021DDB44  data  ov021  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Rec16 { u32 a; u32 b; u32 c; u32 d; };

extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_0219630C(u32 a, void *b, u8 *c, void *d, u32 e, u32 f);
extern void func_021966B0(u8 *p, u32 n);
extern void func_0219728C(u8 *p);
struct Cb;
extern void func_0219649C(void *a, int b, struct Cb *c);
extern int func_02196F44(u32 v, u8 *p);
extern void func_02196FF0(u8 *p);
extern void *func_02051B84(void *a, void *b, void *c, u32 d);
extern struct Rec16 d_021D4080;
extern u8 d_021D4034[];
extern u8 d_021DDB44[];

void func_02196C68(u8 *p)
{
    struct Rec16 loc = d_021D4080;

    func_0219728C(p);
    func_021966B0(p, 0xD);
    func_0219630C(4, &loc, p, d_021DDB44, 0, 0);
    *(void **)(p + 0x24) = func_02051B84(d_021D4034, func_0219649C, p, *(u16 *)(p + 0x10));
    *(void **)(p + 4) = func_02196F44;
    func_02196034(p, func_02196FF0, 0x4CC);
}
