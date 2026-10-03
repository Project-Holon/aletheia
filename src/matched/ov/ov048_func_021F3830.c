/*
 * function: func_021F3830
 * address:  0x021F3830
 * packet:   pkt_ov048_021F3830
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201296C  0x0201296C  thumb
 *   func_02014314  0x02014314  thumb
 *   func_021F37A4  0x021F37A4  thumb  ov048
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_0201296C(int a);
extern void func_02014314(int a, u16 b);
typedef unsigned int   u32;
extern u8 *func_021F37A4(u32 a);

void func_021F3830(int *p)
{
    int r6;
    int i;
    u8 *q;

    r6 = func_0201296C(p[2]);
    q = func_021F37A4(p[1]) + 0xc;
    for (i = 0; i < q[0]; i++) {
        if (*(int *)(q + i * 4 + 4) == 8) {
            func_02014314(r6, *(int *)(q + i * 4 + 0x20));
        }
    }
}
