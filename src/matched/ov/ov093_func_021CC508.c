/*
 * function: func_021CC508
 * address:  0x021CC508
 * packet:   pkt_ov093_021CC508
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C84D0  0x021C84D0  thumb  ov093
 *   func_021C8910  0x021C8910  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D59B4(u8 *p, int k);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021C84D0(void *a, void *m);
extern int func_021C8910(void *a);
extern void func_021CC95C(void *lock, u32 v, int line);

int func_021CC508(char *p, void *m)
{
    u32 s;
    int r;

    if (func_021D59B4(m, 16) != 150) {
        s = func_021CC8D8(p + 0x1d74, 1921);
        func_021C84D0(p, m);
        r = func_021C8910(p);
        func_021CC95C(p + 0x1d74, s, 1926);
        if (r == 2)
            return 1;
    }
    return 0;
}
