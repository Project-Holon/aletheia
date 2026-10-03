/*
 * function: func_021A5458
 * address:  0x021A5458
 * packet:   pkt_ov021_021A5458
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021A5318  0x021A5318  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB348  0x021AB348  thumb  ov021
 */

typedef unsigned int u32;

void *func_021A3960(unsigned char *p);
typedef unsigned short u16;
u32 func_0216D7DC(void *p);
int func_021A5318(u32 *p, u32 m);
u16 func_021AB0F0(u32 attr);
int func_021AB348(u16 id);

int func_021A5458(u32 *p)
{
    int x = func_0216D7DC(func_021A3960(*(unsigned char **)(p + 3)));

    if (func_021A5318(p, 2) == 0 && func_021AB348(func_021AB0F0(x)) == 1)
        return 1;
    return 0;
}
