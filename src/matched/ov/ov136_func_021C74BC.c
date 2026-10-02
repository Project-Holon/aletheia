/*
 * function: func_021C74BC
 * address:  0x021C74BC
 * packet:   pkt_ov136_021C74BC
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0            0x020307B0  arm
 */

typedef unsigned char u8;
extern void func_020307B0(void *);
int func_021C74BC(u8 *p)
{
    func_020307B0(*(void **)(p + 0x10));
    return 8;
}
