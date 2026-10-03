/*
 * function: func_021866F8
 * address:  0x021866F8
 * packet:   pkt_ov020_021866F8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045A98  0x02045A98  arm
 *   func_02161E78  0x02161E78  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct S {
    u8 lo : 4;
    u8 hi : 4;
};

extern u16 func_02045A98(void);
extern void func_02161E78(void *a0);

void func_021866F8(char *p)
{
    int i;
    int found;
    u16 v;

    v = func_02045A98();
    if ((u8)p[1] >= 0x1e)
        func_02161E78(p);
    if ((u8)p[2] > 0x64)
        func_02161E78(p);
    if (((struct S *)p)->hi != 0) {
        found = 0;
        for (i = 0; i < 8; i++) {
            if (v == *(u16 *)(p + 4 + i * 2))
                found = 1;
        }
        if (found == 0)
            func_02161E78(p);
    }
}
