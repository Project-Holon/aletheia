/*
 * function: func_02191BE8
 * address:  0x02191BE8
 * packet:   pkt_ov021_02191BE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020458F8  0x020458F8  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045770  0x02045770  arm
 *   func_0219214C  0x0219214C  thumb  ov021
 *   func_02045334  0x02045334  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040618  0x02040618  arm
 *   func_02192138  0x02192138  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_021928C0  0x021928C0  thumb  ov021
 *   func_021927FC  0x021927FC  thumb  ov021
 *   func_02043814  0x02043814  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021921C8  0x021921C8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020458F8(u32 a);
extern u32 func_020457B0(u32 a, u32 heap);
struct Descriptor;
extern void *func_02045770(struct Descriptor *w);
extern int func_0219214C(u32 a, u32 b, u32 c, u32 d, u32 *cnt, u8 col);
extern void func_02045334(u32 w);
extern void func_020409B4(u32 layer);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern int func_02192138(u32 a, u32 b, u32 c);
extern u32 func_020362DC(void);
extern void func_021928C0(u32 *p, u32 a, u32 b);
extern void func_021927FC(u32 *p, u32 a, u32 b);
extern void func_02043814(u32 a, u32 b);
extern void func_020061E4(u32 a);
extern int func_021921C8(u32 a, u32 b, u32 c, int n, u16 col);

u32 func_02191BE8(u32 *p, u32 b)
{
    switch (p[6]) {
    case 0:
        p[4] = b;
        p[5] = func_020457B0(func_020458F8(b) + 2, *(u16 *)p[0]);
        func_0219214C((u32)func_02045770((struct Descriptor *)p[1]), p[12], p[4], p[5], p + 9, 15);
        func_02045334(p[1]);
        func_020409B4((u8)((u16 *)p[0])[1]);
        p[6]++;
        break;
    case 1:
        *(int *)&p[7] += 12;
        if (*(int *)&p[7] >= 0) {
            p[7] = 0;
            p[6]++;
        }
        func_02040618((u8)((u16 *)p[0])[1], 3, p[7]);
        break;
    case 2:
        if (func_02192138(p[4], p[5], p[9]) == 1) {
            p[6] = 5;
            break;
        }
        p[6]++;
    case 3:
        if ((func_020362DC() & 3) == 0) {
            func_021928C0(p + 10, (u32)func_02045770((struct Descriptor *)p[1]), 15);
            func_02045334(p[1]);
            break;
        }
        func_021927FC(p + 10, (u32)func_02045770((struct Descriptor *)p[1]), 15);
        func_02043814((u32)func_02045770((struct Descriptor *)p[1]), p[3]);
        func_0219214C(p[2], p[12], p[4], p[5], p + 9, 15);
        p[8] = 0;
        func_020061E4(0x547);
        p[6]++;
    case 4:
        if (func_021921C8((u32)func_02045770((struct Descriptor *)p[1]), p[3], p[2], p[8], 15) == 1) {
            p[6] = 2;
        } else {
            p[8] += 4;
        }
        func_02045334(p[1]);
        func_020409B4((u8)((u16 *)p[0])[1]);
        break;
    case 5:
        if ((func_020362DC() & 0xf3) == 0) {
            break;
        }
        p[6]++;
    case 6:
        *(int *)&p[7] -= 12;
        if (*(int *)&p[7] <= -48) {
            p[7] = -48;
        }
        func_02040618((u8)((u16 *)p[0])[1], 3, p[7]);
        if (*(int *)&p[7] == -48) {
            p[6]++;
            return 1;
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}
