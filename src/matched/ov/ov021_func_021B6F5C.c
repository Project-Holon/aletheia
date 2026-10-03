/*
 * function: func_021B6F5C
 * address:  0x021B6F5C
 * packet:   pkt_ov021_021B6F5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B6EE0  0x021B6EE0  thumb ov021
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021B6EE0(void *, void *);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_020307B0(void *);

int func_021B6F5C(void *a, void *b, void *c)
{
    void *t;
    int r;

    t = func_021B6EE0(a, c);
    if (t == 0) {
        return 1;
    }
    r = func_02017E1C(t, 0x4C, 0);
    func_020307B0(t);
    return r == 1 ? 2 : 1;
}
