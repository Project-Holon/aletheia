/*
 * function: func_02190EF0
 * address:  0x02190EF0
 * packet:   pkt_ov021_02190EF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02190D5C  0x02190D5C  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
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

extern int func_02190D5C(u32 *p);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u8 func_021927F8(u8 *p);
struct Cur;
extern void func_021927FC(struct Cur *c, u32 win, u32 col);
extern void func_021928C0(struct Cur *c, u32 win, u32 col);
extern u8 func_0219320C(u8 *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02045334(struct Descriptor *);

u32 func_02190EF0(u32 *p)
{
    u32 r = func_02190D5C((u32 *)p[1]);
    func_020362DC();
    func_0203630C();
    switch (r) {
    case 0:
        if (func_021927F8((u8 *)(p + 6)) == 1) {
            func_021927FC((struct Cur *)(p + 6), (u32)func_02045770((struct Descriptor *)p[0]), 15);
            func_02045334((struct Descriptor *)p[0]);
        }
        break;
    case 1:
        if (func_0219320C((u8 *)(p[5] + 0x160)) == 0) {
            func_021928C0((struct Cur *)(p + 6), (u32)func_02045770((struct Descriptor *)p[0]), 15);
            func_02045334((struct Descriptor *)p[0]);
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}
