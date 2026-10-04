/*
 * function: func_02196538
 * address:  0x02196538
 * packet:   pkt_ov021_02196538
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 *   func_02049F78  0x02049F78  arm
 *   func_02082D44  0x02082D44  arm
 *   func_021964B0  0x021964B0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_0201F5DC  0x0201F5DC  thumb
 *   func_02049B40  0x02049B40  arm
 *   d_021DDAD4     0x021DDAD4  data  ov021  a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct GfFont;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *h);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(void *src, void *dst, u32 n);
extern void func_021964B0(void *pal, const u16 *add, u32 n);
extern void func_020307B0(void *p);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern const u16 d_021DDAD4[];

void func_02196538(u8 *p)
{
    void *h;
    void *res;
    u8 *pal;

    *(u32 *)(p + 0x2F8) = 0;
    *(void **)(p + 0x38) = func_020457B0(0x12C, *(u16 *)(p + 0x10));
    *(void **)(p + 0x2C) = func_0201D7EC(0x17, 0, 0, 0, *(u16 *)(p + 0x10));
    *(void **)(p + 0x28) = func_02045B38(0, 2, 0x2E, *(u16 *)(p + 0x10));

    h = func_020490F4(0x1C, *(u16 *)(p + 0x10));
    func_02049B68(h, 1, 0, 0, 0, *(u16 *)(p + 0x10));
    *(u32 *)(p + 0x44) = func_02049740(h, 6, 0, 0, 0, *(u16 *)(p + 0x10));
    func_02049990(h, 0xD, 0, 0, (u16)*(u32 *)(p + 0x44), 0, 0, *(u16 *)(p + 0x10));
    func_02049238(h);

    h = func_020490F4(0x1D, *(u16 *)(p + 0x10));
    func_02049B68(h, 2, 4, 0, 0, *(u16 *)(p + 0x10));
    res = func_02049F78(h, 2, (u32)(&pal), *(u16 *)(p + 0x10));
    func_02082D44(*(void **)(pal + 0xC), p + 0x48, 0x100);
    func_02082D44(*(void **)(pal + 0xC), p + 0x148, 0x100);
    func_021964B0(p + 0x148, d_021DDAD4, 8);
    func_020307B0(res);
    func_02049B68(h, 0, 0, 0, 0, *(u16 *)(p + 0x10));
    *(u32 *)(p + 0x40) = func_02049740(h, 4, 4, 0, 0, *(u16 *)(p + 0x10));
    func_02049990(h, 9, 4, 0, (u16)*(u32 *)(p + 0x40), 0, 0, *(u16 *)(p + 0x10));
    func_02049990(h, 0xB, 6, 0, (u16)*(u32 *)(p + 0x40), 0, 0, *(u16 *)(p + 0x10));
    func_02049238(h);

    *(void **)(p + 0x3C) = func_0201F5DC((void *)5, 0xC, 0, *(u16 *)(p + 0x10));
    func_02049B40(0x17, 5, 4, 0x160, 0x20, *(u16 *)(p + 0x10));
}
