/*
 * function: func_021ECEB8
 * address:  0x021ECEB8
 * packet:   pkt_ov093_021ECEB8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_021B85DC  0x021B85DC  thumb  ov093
 *   func_0201CD10  0x0201CD10  thumb
 *   func_0201CE0C  0x0201CE0C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;

extern void func_02043B5C(int, int);
struct Rec;
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern int func_021B85DC(int);
extern struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void func_0201CE0C(void *p);

void func_021ECEB8(u8 *a, u32 b, u16 s, u32 c)
{
    void *o;

    func_02043B5C(*(int *)(a + 4), 0xc);
    func_0201DD78(1, 9, 0xc);
    o = func_0201CD10(*(u32 *)a, 0, 0, b, *(u32 *)(a + 0x24),
                      func_021B85DC(*(int *)(a + 0x134)),
                      *(u32 *)(a + 0x2c), 0,
                      *(u16 *)(a + 0x13c), 0xc, c);
    *(void **)(a + 0x30) = o;
    func_0201CE0C(o);
    a[0x13f] = 0;
    a[0x13e] = 0;
    if (s == 0xff) {
        *(u16 *)(a + 0x148) = 0x50;
        *(u16 *)(a + 0x14c) = 0;
    } else {
        *(u16 *)(a + 0x148) = s;
        *(u16 *)(a + 0x14c) = s;
    }
    *(u16 *)(a + 0x14a) = *(u16 *)(a + 0x148);
    a[0x141] = 0;
}
