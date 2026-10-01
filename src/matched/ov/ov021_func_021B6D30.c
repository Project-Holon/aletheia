/*
 * function: func_021B6D30
 * address:  0x021B6D30
 * packet:   pkt_ov021_021B6D30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb ov010
 *   func_02158F74  0x02158F74  thumb ov010
 *   d_021D9980     0x021D9980  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int (*fn)(void *, void *, void *);
    u8 pad[0x14];
} Entry;

extern void *func_0215A5F4(void *);
extern void *func_02158F74(void *);
extern Entry d_021D9980[];

int func_021B6D30(int idx, void *x, void *c)
{
    void *r;
    int (*fn)(void *, void *, void *);

    r = func_02158F74(func_0215A5F4(c));
    fn = d_021D9980[idx].fn;
    if (x != 0 && fn != 0) {
        return fn(r, x, c);
    }
    return 7;
}
