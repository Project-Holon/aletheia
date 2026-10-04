/*
 * function: func_021916E0
 * address:  0x021916E0
 * packet:   pkt_ov021_021916E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_02190D5C  0x02190D5C  thumb  ov021
 *   func_0201CE30  0x0201CE30  thumb
 *   func_02040618  0x02040618  arm
 *   func_021927F8  0x021927F8  thumb  ov021
 *   func_021927FC  0x021927FC  thumb  ov021
 *   func_021928C0  0x021928C0  thumb  ov021
 *   func_0219320C  0x0219320C  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u32 func_02190D5C(u32);
extern u32 func_0201CE30(u32);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u32 func_021927F8(u32 *);
extern void func_021927FC(u32 *, u32, u32);
extern void func_021928C0(u32 *, u32, u32);
extern u32 func_0219320C(u32);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02045334(u32);

u32 func_021916E0(u32 *a)
{
    u32 r;
    func_020362DC();
    func_0203630C();
    r = func_02190D5C(a[7]);
    a[9] = func_0201CE30(*(u32 *)(a[7] + 4));
    func_02040618(1, 3, *(s16 *)((u8 *)a + 0x28));
    if (*(s16 *)((u8 *)a + 0x28) < 0) {
        *(s16 *)((u8 *)a + 0x28) += 2;
        if (*(s16 *)((u8 *)a + 0x28) > 0) {
            *(s16 *)((u8 *)a + 0x28) = 0;
        }
    }
    *(s16 *)((u8 *)a + 0x28) = -*(s16 *)((u8 *)a + 0x28);
    switch (r) {
    case 0:
        if (func_021927F8(a) == 1) {
            func_021927FC(a, (u32)func_02045770((struct Descriptor *)a[6]), 15);
            func_02045334(a[6]);
        }
        break;
    case 1:
        if (func_0219320C(a[3] + 0x160) == 0) {
            func_021928C0(a, (u32)func_02045770((struct Descriptor *)a[6]), 15);
            func_02045334(a[6]);
        }
        break;
    case 2:
        if (*(s16 *)((u8 *)a + 0x28) != 0) {
            *(s16 *)((u8 *)a + 0x28) = 0;
            func_02040618(1, 3, *(s16 *)((u8 *)a + 0x28));
        }
        return 1;
    }
    return 0;
}
