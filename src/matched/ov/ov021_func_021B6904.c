/*
 * function: func_021B6904
 * address:  0x021B6904
 * packet:   pkt_ov021_021B6904
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb ov010
 *   func_02012934  0x02012934  thumb
 *   func_021B6934  0x021B6934  thumb ov021
 *   func_0215A5CC  0x0215A5CC  thumb ov010
 *   func_0201AB8C  0x0201AB8C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5E4(void *a0);
extern void *func_02012934(void *p);
extern int func_021B6934(void *);
extern u32 func_0215A5CC(void *);
extern void func_0201AB8C(void *, int, int, u32);

void func_021B6904(void *a)
{
    void *t;
    void *u;
    int r;

    t = func_0215A5E4(a);
    u = func_02012934(t);
    r = func_021B6934(t);
    if (r >= 0) {
        func_0201AB8C(u, r, 0, func_0215A5CC(a));
    }
}
