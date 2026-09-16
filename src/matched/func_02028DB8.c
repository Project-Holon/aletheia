/*
 * function: func_02028DB8
 * address:  0x02028DB8
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02028D7C  0x02028D7C  thumb
 */

typedef unsigned int u32;

extern void *func_02028D7C(void *obj);

int func_02028DB8(void *obj)
{
    return *(u32 *)func_02028D7C(obj) != 0;
}
