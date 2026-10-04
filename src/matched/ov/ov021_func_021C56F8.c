/*
 * function: func_021C56F8
 * address:  0x021C56F8
 * packet:   pkt_ov021_021C56F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_021C577C  0x021C577C  thumb  ov021
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char u8;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern int func_0201C6C4(int a, int b);
extern void func_02045334(int a);
extern void func_021C577C(int a, int b, int c);
extern void func_0204B3DC(int a, int b);

int func_021C56F8(int *a)
{
    int r4 = a[3];
    int i;
    int r7;

    if (*(u8 *)(a + 5) != 0) {
        if (func_0201C6C4(r4, (int)func_02045770((struct Descriptor *)a[4])) == 0) {
            func_02045334(a[4]);
            *(u8 *)(a + 5) = 0;
        }
    }
    r7 = 1;
    if (*(u8 *)(a + 5) != 0) {
        r7 = 0;
    }
    if (r7 != 0) {
        if (a[0x11] != 0) {
            func_021C577C(a[1], 0, 0);
            a[0x11] = 0;
        }
        if (a[0x12] != 0) {
            for (i = 0; i < 3; i++) {
                func_0204B3DC(a[0xa + i], 1);
            }
            a[0x12] = 0;
        }
    }
    return r7;
}
