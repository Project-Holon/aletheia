/*
 * function: func_021B6DE4
 * address:  0x021B6DE4
 * packet:   pkt_ov021_021B6DE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B6E24  0x021B6E24  thumb ov021
 *   func_0216D588  0x0216D588  thumb ov010
 *   func_021B6E68  0x021B6E68  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021B6E24(void *);
extern u16 func_0216D588(void *);
extern int func_021B6E68(void *);

u16 func_021B6DE4(void *a, void *b)
{
    void *t;
    int r;

    t = func_021B6E24(a);
    if (t != 0) {
        return func_0216D588(t);
    }
    r = func_021B6E68(b);
    if (r >= 0) {
        return r;
    }
    return 0;
}
