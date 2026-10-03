/*
 * function: func_021BB990
 * address:  0x021BB990
 * packet:   pkt_ov021_021BB990
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02030734  0x02030734  arm
 *   func_021BB960  0x021BB960  thumb  ov021
 *   func_021BB978  0x021BB978  thumb  ov021
 *   d_021DE2F8     0x021DE2F8  data  a4
 */

typedef unsigned short u16;

extern int d_021DE2F8;

typedef signed int     s32;
typedef unsigned int   u32;
int func_02034AC4(s32 handle);
int func_02030DA8(int a, void *fn, int *b, int c);
int func_02030734(int a, int b, int c, void *d, int e);
void func_021BB960(u32 a, u32 b, u32 c, u32 d);
void func_021BB978(u32 a, u32 b, u32 c, u32 d);

int *func_021BB990(int a, int *d, const int *c)
{
    int *p = (int *)d[3];
    int i;

    for (i = 0; i < d[2]; i++, p += 6) {
        if (p[1] != 0) {
            continue;
        }
        if (a != -1) {
            func_02034AC4(a);
        }
        p[5] = a;
        p[1] = func_02030DA8(d[4], func_021BB960, p, c[0]);
        p[2] = func_02030DA8(d[5], func_021BB978, p, c[0]);
        p[0] = (int)d;
        p[3] = (int)c;
        if (*(u16 *)(c + 1) != 0) {
            p[4] = func_02030734((u16)d[1], *(u16 *)(c + 1), 1, &d_021DE2F8, 0xc3);
        }
        if (c[2] != 0) {
            ((void (*)(int *, int, int))c[2])(p, d[0], p[4]);
        }
        return p;
    }
    return 0;
}
