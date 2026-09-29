/*
 * function: func_021F0C70
 * address:  0x021F0C70
 * packet:   pkt_ov032_021F0C70
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0C70  0x021F0C70  thumb
 *   func_0202846C  0x0202846C  thumb
 *   func_02028178  0x02028178  thumb
 *   func_0202824C  0x0202824C  thumb
 *   func_0202822C  0x0202822C  thumb
 *   func_021F0DD8  0x021F0DD8  thumb  ov032
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_0202846C(u8 *p);
extern void func_02028178(u32 w);
extern u32 func_0202824C(u32 *w);
extern void func_0202822C(char *p, int v);
extern void func_021F0DD8(int a);

int func_021F0C70(char *p, int flag)
{
    int s;
    char *q;
    int n;
    int i;

    s = -1;
    if (flag == 0) {
        q = p + 0xc0;
        n = 3;
    } else {
        q = p + 0xf0;
        n = 2;
    }
    for (i = 0; i < n; i++) {
        if (func_0202846C(*(u8 **)(q + i * 16)) == 1) {
            func_02028178(*(u32 *)(q + i * 16));
            return -1;
        }
    }
    for (i = 0; i < n; i++) {
        if (func_0202824C(*(u32 **)(q + i * 16)) != 0) {
            if (i < n - 1) {
                func_021F0DD8(0x54c);
                s = i;
            } else {
                func_0202822C(*(char **)(q + i * 16), 1);
                func_021F0DD8(0x54c);
                s = i;
            }
        }
        func_02028178(*(u32 *)(q + i * 16));
    }
    return s;
}
