/*
 * function: func_021AF7E4
 * address:  0x021AF7E4
 * packet:   pkt_ov021_021AF7E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201EF5C  0x0201EF5C  thumb
 *   func_0201EF4C  0x0201EF4C  thumb
 *   func_0201EF40  0x0201EF40  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *cur;
} Script;

extern void *func_0215A5F4(void *p);
extern u32 func_02158F74(void *);
extern u32 func_02159B10(Script *, u32);
extern void func_0201EF5C(u32, u32, u32);
extern void func_0201EF4C(u32, u32, u32);
extern void func_0201EF40(u32, u32, u32);

void func_021AF7E4(Script *a, u32 b)
{
    u32 x = func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    u32 y, n, flag;
    u8 *q;
    a->cur = p + 1;
    y = func_02159B10(a, b);
    n = func_02159B10(a, b);
    q = a->cur;
    flag = *q;
    a->cur = q + 1;
    if (n > 1) {
        func_0201EF5C(x, v, y);
    } else if (flag != 0) {
        func_0201EF4C(x, v, y);
    } else {
        func_0201EF40(x, v, y);
    }
}
