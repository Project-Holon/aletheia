/*
 * function: func_021BB30C
 * address:  0x021BB30C
 * packet:   pkt_ov091_021BB30C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;

extern u32 func_02017E1C(void *p, u32 id, u32 v);

typedef struct {
    int obj;
    u16 pad4;
    u16 lo;
    u16 hi;
} S;

void func_021BB30C(u8 *a, S *s)
{
    s->hi = func_02017E1C((void *)s->obj, 0xa0, 0);
    ((s8 *)a)[0x11e] = (s->hi - s->lo) / 100;
    if (s->hi > s->lo)
        ((s8 *)a)[0x11e] = ((s8 *)a)[0x11e] + 1;
    else
        ((s8 *)a)[0x11e] = ((s8 *)a)[0x11e] - 1;
}
