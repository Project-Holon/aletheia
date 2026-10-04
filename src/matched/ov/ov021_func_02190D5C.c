/*
 * function: func_02190D5C
 * address:  0x02190D5C
 * packet:   pkt_ov021_02190D5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE34  0x0201CE34  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_02193228  0x02193228  thumb  ov021
 *   func_02193260  0x02193260  thumb  ov021
 *   func_0219320C  0x0219320C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021932A0  0x021932A0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32 func_0201CE30(void *p);
extern u32 func_0201CE34(void *p);
extern void func_0201CE38(void *p);
extern int func_02193228(u8 *p);
extern int func_02193260(u32 a, u32 b);
extern u8 func_0219320C(u8 *p);
extern void func_020061E4(u32 a);
extern void func_021932A0(u32 a, int f);

int func_02190D5C(u32 *p)
{
    int r = func_0201CE30((void *)p[1]);

    switch (r) {
    case 0:
        if (func_02193228((u8 *)(p[2] + 0x160)) != 0) {
            func_021932A0(p[1], 1);
        } else {
            func_021932A0(p[1], 0);
        }
        break;
    case 1:
        if (func_02193260(p[2] + 0x160, func_0201CE34((void *)p[1])) != 0) {
            if (func_0219320C((u8 *)(p[2] + 0x160)) == 0) {
                func_020061E4(0x547);
            }
            func_0201CE38((void *)p[1]);
            r = 0;
            func_021932A0(p[1], 0);
        }
        break;
    case 2:
        break;
    }
    return r;
}
