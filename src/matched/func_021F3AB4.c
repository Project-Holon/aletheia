/*
 * function: func_021F3AB4
 * address:  0x021F3AB4
 * packet:   pkt_021F3AB4
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 */

typedef unsigned int u32;

extern u32 func_0201296C(u32 a);
extern int func_020142E8(u32 a, u32 b);

int func_021F3AB4(void *p)
{
    return func_020142E8(func_0201296C(*(u32 *)((char *)p + 8)), 0x97b) == 1;
}
