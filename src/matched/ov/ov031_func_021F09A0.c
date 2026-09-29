/*
 * function: func_021F09A0
 * address:  0x021F09A0
 * packet:   pkt_ov031_021F09A0
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BBC2C  0x021BBC2C  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_021F07AC  0x021F07AC  thumb  ov031
 *   d_021F10D0     0x021F10D0  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021BBC2C(void *r, int i);
extern void func_02034714(const char *file, int line, const char *msg);
extern void func_021F07AC(void *a, void *b, u32 c);
extern const char d_021F10D0[];

void func_021F09A0(void *a, char *b)
{
    int k;
    int i = *(int *)(b + 0x440);
    int lo = i - 3;
    void *e;

    if (lo < 0)
        lo = -1;
    k = i - lo - 1;
    for (; i > lo; i--, k--) {
        e = func_021BBC2C(b, i);
        if (e == 0)
            func_02034714(d_021F10D0, 0, d_021F10D0);
        if (k <= -1)
            func_02034714(d_021F10D0, 0, d_021F10D0);
        func_021F07AC(a, e, (u8)k);
    }
}
