/*
 * function: func_021BB148
 * address:  0x021BB148
 * packet:   pkt_ov068_021BB148
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_021BB138  0x021BB138  thumb  ov068
 *   func_021BB1C4  0x021BB1C4  thumb  ov068
 */

typedef unsigned int u32;

typedef signed int     s32;
typedef unsigned char  u8;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern u32 func_0204E804();
extern void func_021BB138(void *p, int v);
extern void func_021BB1C4(void *a, u32 *st, u8 *w);

void func_021BB148(void *unused, u32 *p)
{
    switch (*p) {
    case 0:
        func_0204E720(3, 16, 0, 0);
        *p = 1;
        break;
    case 1:
        if (func_0204E804() == 0) {
            *p = 2;
        }
        break;
    case 2:
        func_021BB138(unused, (int)func_021BB1C4);
        break;
    }
}
