/*
 * function: func_02184114
 * address:  0x02184114
 * packet:   pkt_02184114
 * region:   ov022
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1E8  0x0203D1E8  arm
 */

extern int  func_020399A8(void);
typedef unsigned int   u32;
extern void func_0203D1E8(u32 unused, void *arg);

int func_02184114(unsigned char *p)
{
    if (p[4] == 0) {
        func_0203D1E8(func_020399A8(), 0);
        p[9] = 1;
        return 1;
    }
    return 0;
}
