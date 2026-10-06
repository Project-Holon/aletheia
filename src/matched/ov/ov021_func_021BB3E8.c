/*
 * function: func_021BB3E8
 * address:  0x021BB3E8
 * packet:   pkt_ov021_021BB3E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013C9C  0x02013C9C  thumb
 *   func_020490A8  0x020490A8  arm
 *   func_02030734  0x02030734  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_0219EF44  0x0219EF44  thumb  ov021
 *   func_0219EF7C  0x0219EF7C  thumb  ov021
 *   func_0219F018  0x0219F018  thumb  ov021
 *   func_021B7C58  0x021B7C58  thumb  ov021
 *   func_0219EF6C  0x0219EF6C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021DE2D0     0x021DE2D0  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern int func_02013C9C(u16 key);
extern u32 func_020490A8(u32 a, u32 b);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
typedef unsigned char  u8;
struct S;
extern u8 *func_0219EF44(u32 heap);
extern void func_0219EF7C(struct S *p, u32 b, u32 c);
extern u8 *func_0219F018(u8 *p);
extern void func_021B7C58(u32, u32, u32, u32, u32, u32);
extern void func_0219EF6C(u8 *p);
extern void func_020307B0(void *);
extern int d_021DE2D0;

void func_021BB3E8(u32 *a, u32 b, u16 c, u16 d, u16 e, u32 f, u16 g)
{
    u16 id;
    u16 *p;
    u32 h;

    id = (g & 0x7FFF) | 0x8000;
    p = (u16 *)func_02030734(id, func_020490A8(0x6d, func_02013C9C(b)), 1, (const char *)&d_021DE2D0, 0x1c9);
    func_02048F4C(p, 0x6d, func_02013C9C(b));
    h = (u32)func_0219EF44(id);
    func_0219EF7C((struct S *)h, p[0], id);
    func_021B7C58(a[0], (u32)func_0219F018((u8 *)h), c, d, e, f);
    func_0219EF6C((u8 *)h);
    func_020307B0(p);
}
